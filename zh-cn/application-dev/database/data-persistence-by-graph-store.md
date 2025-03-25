# 通过图数据库实现数据持久化（仅对系统应用开放）


## 场景介绍

图数据库是一种专门用于处理复杂关系数据的数据库管理系统。它通过节点（顶点）和关系（边）的结构来存储和查询数据，能够高效地处理大量复杂的关系运算。图数据库的核心优势在于直接通过存储的边来遍历关系，相较于关系型数据库的多表JOIN遍历关系更为高效。常见使用场景有社交网络与关系分析、知识图谱、实时推荐系统等。当前接口均为系统能力，仅对系统应用开放。


## 基本概念

- **图**：由**节点**和**关系**组成的数据结构，用于表示实体及其关联。

- **Schema**：定义了数据的结构化规则，类似于关系型数据库中的表结构设计。它明确了图中节点、关系、属性以及约束的组织方式，确保数据的一致性和查询效率。

- **节点（顶点）**：图中的基本实体单元。

- **关系（边）**：连接两个节点的有向边，表示实体间的关联。

- **路径**：由顶点和边按照从起点到终点的顺序组成的序列。

- **标签**：用于对节点或关系进行分类或分组的标记。例如下文建图语句中的“Person”、“Friend”。

- **属性**：附加在节点或关系上的键值对，存储具体数据。例如下文插入顶点语句中的“name: 'name_1'”、“age: 11”。

- **点表**：用于存储顶点信息的表。表名为点的标签（下文建图语句中的“Person”），表中内容包括点的id、属性等。

- **边表**：用于存储边信息的表。表名为边的标签（下文建图语句中的“Friend”），表中内容包括边的id、起终点的id、属性等。

- **变量**：GQL语句中用于在查询中临时存储和引用图数据（节点、边、路径等）的标识符，主要有以下三种：
  - 点变量：用于表示图中的一个顶点，通过变量名引用节点的属性、标签等（例如下文查询顶点的GQL语句中的“person”）。
  - 边变量：用于表示图中的边，通过变量名引用边的属性、标签等（例如下文查询边的GQL语句中的“relation”）。
  - 路径变量：用于表示图中的路径，即一系列顶点和边的有序集合，通常由路径遍历操作生成（例如下文查询路径的GQL语句中的“path”）。
```ts
const CREATE_GRAPH = "CREATE GRAPH test { (person:Person {name STRING, age INT}),(person)-[:Friend {year INT}]->(person) };"

const INSERT_VERTEX = "INSERT (:Person {name: 'name_1', age: 11});"

const QUERY_VERTEX = "MATCH (person:Person) RETURN person;"

const QUERY_EDGE = "MATCH ()-[relation:Friend]->() RETURN relation;"

const QUERY_PATH = "MATCH path=(a:Person {name: 'name_1'})-[]->{2, 2}(b:Person {name: 'name_3'}) RETURN path;"
```


## 运作机制

图数据库对应用提供通用的操作接口，底层使用自研组件作为持久化存储引擎，支持事务、索引、加密等特性。


## 约束限制

### 支持的数据类型及规格

ArkTS侧支持的基本数据类型：number、string、boolean。各数据类型的具体规格及约束见下表：

| 数据类型 | 规格说明 |
| - | - |
| NULL | 即nullptr，用来表示一个缺失值的项，建图时不允许设置数据类型为NULL。 |
| number | 1. INTEGER，取值范围与int64_t一致，NUMERIC、DATE、DATETIME、INT都映射成int64_t。<br/>2. DOUBLE，取值范围与double一致，REAL、FLOAT都映射成double。 |
| string | 1. 最大64 * 1024字节，包含结束符'\0'。<br/>2. CHARACTER(20)、VARXHAR(255)、VARYING CHARACTER(255)、NCHAR(55)、NATIVE CHARACTER(70)、NVARCHAR(100)都映射成STRING，其中数字没有实际意义。<br/>3.字符串字面量必须用成对的单引号，不可以用双引号，字符串内部不可以有单引号。 |
| boolean | 取值为true或false，BOOL、BOOLEAN都映射成int64_t。 |

### 属性图DDL规格及约束

DDL（Data Definition Language）语句： 数据定义语言，主要用于定义图的Schema。常用的DDL语句关键字为CREATE。DDL具体规格及约束见下表：

> **说明：**
>
> 当前实现是GQL标准语法的子集，下列约束中除**列约束**与GQL标准无差异外，其余约束在GQL标准中均未指定。

| 规格项 | 规格说明 |
| - | - |
| 创建属性图 | 1. 一个数据库实例至多只能创建一个属性图。<br/>2. 不支持在一个子句上同时定义点表和边表，即：(person:Person {name STRING, age INT})-[:Friend {year INT}]->(person)。<br/>3. 创建属性图时的边表必须指定方向，当前只允许从左到右的方向，即‘-[’、‘]->’。<br/>4. 属性图名称长度上限128字节，不区分大小写。<br/>5. 变量名区分大小写，点表必须指定变量名，变量名长度上限128字节，且变量名不可以anon_开头，边表不可以指定变量名，不同点表对应的变量名不可重复。<br/>6. ‘-[’、‘]->’、‘]-’、‘<-[’中间不能出现空格，如‘- [’<br/>7. 创建属性图时，必须先定义点表，再定义边表，必须至少定义一个点表，边表可以不定义。<br/>8. 不允许点标签和边标签同名。<br/>9. GQL系统表中使用变长字段类型保存建图语句，因此建图语句长度需要小于64 * 1024字节。 |
| 点表/边表总个数 | 1. 用户创建的点边表名称不能与系统表名（以预留表前缀‘GM_’开头）重复。<br/>2. 不允许用户修改系统表。<br/>3. 暂不允许用户查询系统表。<br/>4. 单进程非共享模式，一个数据库实例点表数量上限为2000，边表数量上限为10000。<br/>5. 由于变长字段类型长度上限为64 * 1024字节，点边表实际能够创建的最大个数会出现小于上限值的情况，例如10000个边表的建图语句超过了64 * 1024字节会导致属性图创建失败。 |
| 点表/边表属性数量 | 1. 一个点表/边表里最多允许1023个属性（不包含DB内部默认添加的identity属性）。<br/>2. 不允许指定属性名为rowid或identity，DB内部会默认给每个点、边标签都加上identity属性。<br/>3. 属性名称长度上限128字节，不区分大小写。<br/>4. identity属性不允许插入时指定值，不允许更新，不允许通过属性名identity查询，只能通过element_id(v)获取变量v的identity。 |
| 表名长度 | 表名长度上限128字节，不区分大小写，如table和TABLE是相同的表。 |
| 属性名长度 | 属性名长度上限128字节，不区分大小写。 |
| 变长字段类型长度 | string类型的属性值的长度应不超过64 * 1024字节。 |
| 默认值 | 1. 仅支持常量表达式作为默认值，如100，‘China’等。<br/>2. 当默认值为时间关键字时（CURRENT_DATE、CURRENT_TIMESTAMP、CURRENT_TIME），对应的类型应为string而不是int64_t。 |
| 列约束 | 当属性设置NOT NULL时，该属性值不允许为NULL。 |

### 属性图DML/DQL规格及约束

DML（Data Manipulation Language）语句: 数据操纵语言，主要是对数据进行增加、删除、修改操作。常用的DML语句关键字有：INSERT、SET、DETACH DELETE等。</br>DQL（Data Query Language）语句：数据查询语言，主要是对数据进行查询操作。常用的DQL语句关键字有MATCH、WHERE等。

#### 关键字规格及约束

| 关键字 | 规格说明 | 与GQL标准差异 |
| - | - | - |
| MATCH | 1. 不支持无上限的变长跳数（下N跳：0<=N<=3）。<br/>2. 变量名区分大小写，且变量名不可以‘anon_’开头。<br/>3. 不允许变长边和定长边同时出现，例如“MATCH p = (a: A)-[e1]->(b)-[e2]->{1, 2}(c)”，e1是定长边，e2是变长边。<br/>4. 插入语句的MATCH子句中，path的数量不可以超过2，其他语句不可以超过1。<br/>5. 变长下N跳只能出现一次，变长下N跳的边上不能再指定表名、属性过滤列表（如{id: 1}）、WHERE子句。<br/>6. 同一个variableName不可以对应多个路径或多个边，同一个variableName可以对应多个点表，但如果指定点表必须指定相同的lableName。<br/>7. ‘-[’、‘]->’、‘]-’、‘<-[’中间不能出现空格，如‘- [’。<br/>8. 不支持一个GQL语句中使用两个及以上的MATCH。<br/>9. 匹配模式中出现{}时，必须带有属性名和属性值，不允许出现空的{}，例如“MATCH (n: Person {}) RETURN n”会出现语法错误。 | 除9外，GQL标准未明确定义左侧约束。 |
| WHERE | 1. WHERE后面不支持使用变长边变量和路径变量，点变量和边变量必须指定属性名称。<br/>2. 如果WHERE后面直接是属性列（例如“WHERE id”，则转换成bool的值，然后进行判断（id=0时转换后为false，否则为true）。<br/>3. WHERE子句后不能出现“()-[]->()”等图匹配形式。 | 除3外，GQL标准不存在左侧约束。 |
| INSERT | 1. 插入语句必须指定待插入的点和边所在的标签（表）名。<br/>2. 不支持INSERT后跟RETURN一起使用。<br/>3. 不支持同时插入点和边。<br/>4. 不支持MATCH+WHERE+INSERT组合。<br/>5. 匹配模式中出现{}时，必须带有属性名和属性值，不允许出现空的{}，例如：INSERT (: Person {})”会出现语法错误。 | 除5外，GQL标准不存在左侧约束。 |
| SET | 1. 不支持更新点边所属的标签名（表名），不支持一个点多标签。<br/>2. 不支持SET后跟RETURN一起使用。<br/>3. 不支持更新不设置任何属性值（例如“SET p = {}”），至少要有一个属性被设置。<br/>4. SET子句后不能出现“()-[]->()”等图匹配形式。 | 除4外，GQL标准不存在左侧约束。 |
| DETACH DELETE | 1. 匹配点如果存在边（关系）会一并删除，匹配边则只删除边。<br/>2.不支持DETACH DELETE后跟RETURN一起使用。<br/>3. 不支持删除变长边变量和路径变量，DELETE子句后不能出现“()-[]->()”等图匹配形式。<br/>4. 不支持未加关键字的DELETE（同义词：NODETACH DELETE）。 | 除1、3外，GQL标准不存在左侧约束。 |
| RETURN | 1. 不支持返回变长的边变量，例如“MATCH p=(a: Person)-[e]->{0, 2}(d) RETURN e;”，只能返回变量p，a，b，不能返回变长边变量e。<br/>2. 不支持RETURN \*。<br/>3. RETURN子句后不能出现“()-[]->()”等图匹配形式。<br/>4. 返回结果中（变量、属性、表达式）每一列的字节长度限制为64 * 1024字节，包含结尾符‘\0’在内。<br/>5. RETURN返回点、边、路径变量时，返回结果（json字符串）不包含内容为null的属性列。<br/>6. 未显示指定GROUP KEY的聚集查询，不允许返回“变量.属性”字段，允许返回重复列（包括重复字段列、聚集函数拓展列、COUNT(\*)）。<br/>7. 显式指定GROUP KEY的聚集查询，RETURN中的“变量.属性”字段必须和GROUP KEY相同，不允许返回部分GROUP KEY字段、不存在的“变量.属性”字段以及重复列（包括重复字段列、聚集函数拓展列、COUNT(\*)）。<br/>8. 显示指定GROUP KEY的聚集查询，聚集查询返回的列的排列方式为：GROUP KEY字段+聚集函数拓展列。<br/>9.存在聚集查询时，不允许在RETURN中返回表达式和基础函数。<br/>10. GQL语句中有聚集函数时，只支持返回属性列或者聚集函数列，不支持RETURN点边变量或者路径变量。<br/>11. 列别名可在ORDER BY中使用，但不能在GROUP BY中使用。<br/>12. 不允许存在重复的列别名。<br/>13. 列别名不区分大小写。 | 除3外，GQL标准不存在左侧约束。 |
| LIMIT | 不支持LIMIT后使用负数。 | 无差异。 |
| OFFSET | 不支持OFFSET后使用负数。 | 不支持SKIP作为OFFSET的同义词。 |
| ORDER BY | 1. 不支持用数字指代RETURN子句中的投影列进行排序。<br/>2. 不支持对整个变量进行排序。<br/>3. 不支持ORDER BY后使用聚集函数。<br/>4. 新增如下关键字：<br/>保留关键字ORDER、BY、ASC、ASCENDING、DESC、DESCENDING、NULLS。非保留关键字：FIRST、LAST。<br/>5. 当存在聚合查询时，ORDER BY必须与GROUP BY配合使用。<br/>6. 当将ORDER BY与GROUP BY配合使用时，排序KEY中所使用的属性列必须在投影结果中存在。<br/>7. 未指定排序顺序时，默认升序排列。<br/>8. 未指定NULL值优先级时，默认NULL值优先级最低。 | GQL标准中未明确指定约束1，不存在约束2、3。 |
| GROUP BY | 1. GROUP KEY数量上限为32个。<br/>2. GROUP KEY不支持对无标签变量的字段进行分组。即作为GROUP BY后接的KEY在MATCH子句中的变量必须带标签。<br/>3. GROUP KEY只能为变量.属性，如a.prop，不支持对点边标签、点边变量、路径、变长边及其上的字段进行分组。<br/>4. GROUP KEY不能重复，包括重复的字段列，重复的拓展聚焦列。 | 左侧约束为GQL标准的子集。 |

#### 运算、函数规格及约束

| 运算/函数 | 规格说明 | 与GQL标准差异 |
| - | - | - |
| 算数运算 | 1. 支持+、-、*、/、%。<br/>2. 支持定长与定长类型的运算，不支持变长类型的算数运算，不支持定长与变长类型的算数运算。<br/>3. 当将高精度类型的数据，设置给低精度类型字段时，会丢失精度。 | GQL标准中不存在约束2。 |
| 比较运算 | 1. 支持=、!=、>、>=、<、<=、<>。<br/>2. 不支持连续的操作运算，比如0<=F1<=10，需要改写为0<=F1 AND F1<=10，直接写0<=F1<=10相当于(0<=F1)<=10。<br/>3. 支持定长与定长类型的运算，支持变长与变长类型的运算，不支持定长与变长类型的比较运算。<br/>4. 浮点数的精度定位误差为+/-0.000000000000001。<br/>5. 不支持(a, b) < (1, 2)的比较。 | 除1外，GQL标准不存在左侧约束。 |
| 逻辑运算 | 1. 支持AND、OR、NOT、IS NULL、IS NOT NULL、IN、NOT IN、LIKE、NOT LIKE、\|\|（字符串拼接）。<br/>2. 对于AND、OR、NOT运算符，其操作数会被强制转为bool类型，例如：WHERE 0.00001 AND '0.1'，0.00001是浮点数，与0比较精度定义误差为+/-0.000000000000001，因此0.00001不等于0，转换为bool后为true，'0.1'为字符串类型，首先从字符串转换为double类型的0.1，然后与0比较时不等于0，转换为bool后为true。<br/>3. 对于LIKE、NOT LIKE运算符，其操作数会被强转为字符串类型，例如：WHERE 0.5 LIKE 0.5，0.5会被强转为字符串'0.5'，相当于WHERE '0.5' LIKE '0.5'，结果为true。<br/>4. IN、NOT IN目前不支持右边为子查询，会报31300009错误码。 | 除1外，GQL标准不存在左侧约束。 |
| 时间函数 | 1. 仅支持DATE()、LOCAL_TIME()、LOCAL_DATETIME()。<br/>2. 入参支持的time-value格式：<br/>YYYY-MM-DD<br/>YYYY-MM-DD HH:MM<br/>YYYY-MM-DD HH:MM:SS<br/>YYYY-MM-DDTHH:MM<br/>YYYY-MM-DDTHH:MM:SS<br/>HH:MM<br/>HH:MM:SS<br/>3. 不支持函数嵌套。<br/>4. 入参只支持字符串字面量。 | 不支持从记录中解析日期，例如：date({year: 1984, month: 11, day: 27})。 |
| 取整函数 | 1. 支持FLOOR()、CEIL()/CEILING()。<br/>2. 入参必须为数字型。<br/>3. 不支持函数嵌套。<br/>4. 不支持科学计数法作为函数入参。 | GQL标准中不存在约束4。 |
| 字符串函数 | 1. 支持CHAR_LENGTH()/CHARACTER_LENGTH()、LOWER()、UPPER()、SUBSTR()/SUBSTRING()、SUBSET_OF()。<br/>2. 除SUBSTR()/SUBSTRING()外，其他函数入参必须为字符串。SUBSTR()/SUBSTRING()的第一个参数为字符串类型，第二个参数和第三个参数为数值类型。<br/>3. 入参使用字符串拼接运算符‘\|\|’时允许拼接数字类型。<br/>4. SUBSTR()/SUBSTRING()、SUBSET_OF()的参数可以互相嵌套，此外其他函数不支持函数嵌套。<br/>5. 不支持科学计数法作为函数入参。<br/>6. SUBSTR()/SUBSTRING()参数的个数必须是3，第一个入参是原始字符串，第二个入参是从第几个（左起第一个字符填1，右起第一个字符填-1）字符开始切分子串，第三个入参表示子串的长度。第二个入参和第三个入参如果是浮点型，会向下取整。<br/>7. SUBSET_OF()第一个参数是原始字符串，第二个参数是查询字符串，第三个参数是分词符，返回结果为bool类型（即返回1或0），分词符字符串长度必须是1，前两个参数的开头和结尾不能有多余的分词符，分词符不可以连续。 | GQL标准中不存在约束4。 |
| 聚集函数 | 1. 聚集函数只支持SUM、MAX、MIN、AVG以及COUNT，不支持FIRST和LAST。<br/>2. 聚集函数内只允许存在单列有效的“变量.属性”字段，不允许使用空值、多个字段、不存在字段、表达式、变量等，不支持使用无标签变量的属性字段。<br/>3. 不支持聚合函数（内/间）的表达式运算、聚集函数嵌套。<br/>4. 聚集函数内计算的字段类型仅支持：INTEGER/BOOLEAN/DOUBLE/STRING类型，与GQL支持的数据类型一致。<br/>5. GQL场景在单条查询超过100MB时，不会使用临时文件，会报31300004错误码。 | 左侧约束为GQL标准的子集。 |
| 类型转换函数 | 1. 不支持函数嵌套。<br/>2. 不支持科学计数法作为函数入参。<br/>3. CAST AS INT<br/>&nbsp;&nbsp;i. 入参支持STRING、INTERGER、BOOLEAN、DOUBLE。<br/>&nbsp;&nbsp;ii. 入参为true返回1，false返回0。<br/>&nbsp;&nbsp;iii. 入参不能被转换为INT的字符串将会报错。<br/>&nbsp;&nbsp;iv. 入参为浮点数截断返回整数。<br/>4. CAST AS BOOL<br/>&nbsp;&nbsp;i. 入参支持INTERGER、BOOLEAN、DOUBLE。<br/>&nbsp;&nbsp;ii. 不支持CAST('true' AS BOOL)。<br/>&nbsp;&nbsp;ii. 输入为BOOLEAN内部实际使用INT类型，0代表false，1代表true，转其他任何INTEGER为BOOLEAN返回其本身。<br/>5. CAST AS DOUBLE<br/>&nbsp;&nbsp;i. 入参支持STRING、INTERGER、BOOLEAN、DOUBLE。<br/>&nbsp;&nbsp;ii. 入参不能被转换为DOUBLE的字符串将会报错。<br/>6. CAST AS STRING<br/>&nbsp;&nbsp;i. 入参支持STRING、INTERGER、BOOLEAN、DOUBLE。<br/>&nbsp;&nbsp;ii. CAST(true AS STRING)返回值为'1'。 | GQL标准中不支持BOOL与INT以及DOUBLE之间的转换。 |

### 索引规格及约束

索引是优化查询性能的关键工具，其核心在于加速节点和边的属性查找。具体规格及约束见下表：

> **说明：**
>
> GQL标准不存在索引相关语法。

| 规格项 | 规格说明 |
| - | - |
| 索引名长度 | 索引名长度上限为128字节，不区分大小写，且不能与标签名相同（不区分大小写）。 |
| 索引的大小 | 单条索引中，所有索引列的总大小不能超过1024字节。 |
| 变长字段索引长度 | 如果将变长字段设置为Key，则该变长字段的大小应小于1024字节。 |
| 索引使用约束 | 需满足连续最左匹配原则，否则索引功能不生效，会走全表扫描流程。<br/>1. BTree不支持联合索引同时指定多个字段的范围查询，如{0<F1<10, 0<F2<10}。<br/>2. BTree不支持联合索引非连续字段查询，如在F1，F2，F3，F4建索引，指定{F1, F3}这样的非连续前缀字段的条件。 |
| 复合索引 | 单个索引包含的列数上限是32。 |
| 索引名唯一性 | 允许不同标签中存在相同名称的索引，例如，t1.id和t2.id，id是索引名。 |
| 创建索引 | 1. 唯一索引中，重复的NULL值不会报索引冲突。<br/>2. 单个标签上最多可以创建10个索引。<br/>3. 创建属性图时不支持使用Primary Key和Unique关键字来创建索引，仅支持通过创建索引语句建立索引。<br/>4. 创建索引时可通过指定Unique关键字来创建唯一索引。 |
| 删除索引 | 删除索引的时候需指定索引所属标签名，例如，Drop Index lable.index。 |
| 索引升降序 | ASC：升序，DESC：降序，默认升序ASC，目前暂不支持设置升降序。 |
| 表达式索引 | 暂不支持。 |

### 事务规格及约束

| 规格项 | 规格说明 | 与GQL标准差异 |
| - | - | - |
| 显式事务 | 1. 默认可串行化隔离级别。<br/>2. 暂不支持SAVEPOINT（数据库中用于事务管理的重要机制，具体表现为在事务内部创建标记点，以便进行部分回滚。）。<br/>3. 不支持DDL与DML混合事务，不支持DDL事务，不支持DDL事务回滚。<br/>4. 当前事务中的单条语句执行失败，回滚单条语句。<br/>5. 事务必须显示地提交或者回滚，否则事务都将回滚。<br/>6. 不能在无事务状态下提交或回滚事务。<br/>7. 同时创建两个事务，写写互斥，读写/写读互斥，读读并发。<br/>8. 长事务资源：事务中操作上限和缓存大小undo日志相关，受文件系统空间限制，同时存在的锁等待线程数同开库连接上限相关。 | GQL标准支持基本的事务语法，不支持SAVEPOINT，支持开启只读事务和读写事务。 |
| 并发操作 | 支持多并发，仅支持可串行化隔离级别，多线程涉及写操作的并发会有一定程度的阻塞。 | GQL标准支持SQL使用的所有隔离级别。 |

### 其他规格及约束

- 系统默认日志方式是WAL（Write Ahead Log）模式，系统默认落盘方式是FULL模式。

- 为保证数据的准确性，数据库同一时间只能支持一个写操作。

- 当应用被卸载完成后，设备上的相关数据库文件及临时文件会被自动清除。

- 不支持多进程模式。

- 暂不支持图数据库的备份、恢复。


## 接口说明

以下是图数据库持久化功能的相关接口，更多接口及使用方式请见[图数据库（系统接口）](../reference/apis-arkdata/js-apis-data-graphStore-sys.md)。

| 接口名称 | 描述 | 
| -------- | -------- |
| getStore(context: Context, config: StoreConfig): Promise&lt;GraphStore&gt; | 获得一个GraphStore，操作图数据库，用户可以根据自己的需求配置GraphStore的参数，然后通过GraphStore调用相关接口可以执行相关的数据操作。 |
| read(gql: string): Promise&lt;Result&gt; | 执行数据查询语句，返回查询结果。 |
| write(gql: string): Promise&lt;Result&gt; | 执行数据写入语句（增、删、改）。 |
| close(): Promise&lt;void&gt; | 关闭数据库，回滚所有未提交的事务。 |
| createTransaction(): Promise&lt;Transaction&gt; | 创建事务实例。 |
| Transaction.read(gql: string): Promise&lt;Result&gt; | 使用事务实例执行数据查询语句，返回查询结果。 |
| Transaction.write(gql: string): Promise&lt;Result&gt; | 使用事务实例执行数据写入语句（增、删、改）。 |
| Transaction.commit(): Promise&lt;void&gt; | 提交当前事务中已经执行的GQL语句。 |
| Transaction.rollback(): Promise&lt;void&gt; | 回滚当前事务中已经执行的GQL语句。 |
| deleteStore(context: Context, config: StoreConfig): Promise&lt;void&gt; | 使用指定的数据库文件配置删除数据库。 |


## 开发步骤

下文仅提供Stage模型下的示例代码。

1. 使用图数据库实现数据持久化，需要调用getStore()接口获取一个GraphStore，其中包括建库、变更安全等级、变更为加密数据库等操作。示例代码如下所示：

   ```ts
   import { graphStore } from '@kit.ArkData'; // 导入模块
   import { UIAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { window } from '@kit.ArkUI';

   let store: graphStore.GraphStore | null = null;

   const STORE_CONFIG: graphStore.StoreConfig = {
     name: "testGraphDb", // 数据库文件名，不需要加.db后缀
     securityLevel: graphStore.SecurityLevel.S2, // 数据库安全级别
     encrypt: false, // 可选参数，指定数据库是否加密，默认不加密
   };

   const STORE_CONFIG_NEW: graphStore.StoreConfig = {
     name: "testGraphDb", // 数据库文件名需要与之前开库使用的文件名保持一致
     securityLevel: graphStore.SecurityLevel.S3,
     encrypt: true,
   };

   // 此处示例在EntryAbility中实现，使用者也可以在其他合理场景中使用
   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       graphStore.getStore(this.context, STORE_CONFIG).then(async (gdb: graphStore.GraphStore) => {
         store = gdb;
         console.info('Get GraphStore successfully.')
       }).catch((err: BusinessError) => {
         console.error(`Get GraphStore failed, code is ${err.code}, message is ${err.message}`);
       })

       // 变更安全等级、变更为加密数据库前需要先调用close()接口关闭数据库
       if(store != null) {
         (store as graphStore.GraphStore).close().then(() => {
           console.info(`Close successfully`);

           graphStore.getStore(this.context, STORE_CONFIG_NEW).then(async (gdb: graphStore.GraphStore) => {
             store = gdb;
             console.info('Update StoreConfig successfully.')
           }).catch((err: BusinessError) => {
             console.error(`Update StoreConfig failed, code is ${err.code}, message is ${err.message}`);
           })
         }).catch ((err: BusinessError) => {
           console.error(`Close failed, code is ${err.code}, message is ${err.message}`);
         })
       }
     }
   }
   ```

2. 获取到GraphStore后，调用write()接口创建图。示例代码如下所示：

   ```ts
   const CREATE_GRAPH = "CREATE GRAPH test " +
     "{ (person:Person {name STRING, age INT}),(person)-[:Friend {year INT}]->(person) };"

   if(store != null) {
     (store as graphStore.GraphStore).write(CREATE_GRAPH).then(() => {
       console.info('Create graph successfully');
     }).catch((err: BusinessError) => {
       console.error(`Create graph failed, code is ${err.code}, message is ${err.message}`);
     })
   }
   ```

3. 成功创建图后，调用write()接口插入、更新顶点及边。示例代码如下所示：

   > **说明：**
   >
   > 图数据库没有显式的flush操作实现持久化，数据插入即保存在持久化文件。

   ```ts
   const INSERT_VERTEX_1 = "INSERT (:Person {name: 'name_1', age: 11});";
   const INSERT_VERTEX_2 = "INSERT (:Person {name: 'name_2', age: 22});";
   const INSERT_VERTEX_3 = "INSERT (:Person {name: 'name_3', age: 0});";

   const UPDATE_VERTEX_3 = "MATCH (p:Person) WHERE p.name='name_3' SET p.age=33;"

   const INSERT_EDGE_12 = "MATCH (p1:Person {name: 'name_1'}), (p2:Person {name: 'name_2'}) " +
     "INSERT (p1)-[:Friend {year: 12}]->(p2);";
   const INSERT_EDGE_23 = "MATCH (p2:Person {name: 'name_2'}), (p3:Person {name: 'name_3'}) " +
     "INSERT (p2)-[:Friend {year: 0}]->(p3);";

   const UPDATE_EDGE_23 = "MATCH (p2:Person {name: 'name_2'})-[relation:Friend]->(p3:Person {name: 'name_3'})" +
     " SET relation.year=23;";
    
   let writeList = [
    INSERT_VERTEX_1,
    INSERT_VERTEX_2,
    INSERT_VERTEX_3,
    UPDATE_VERTEX_3,
    INSERT_EDGE_12,
    INSERT_EDGE_23,
    UPDATE_EDGE_23,
   ]

   if(store != null) {
     writeList.forEach((gql) => {
       (store as graphStore.GraphStore).write(gql).then(() => {
         console.info('Write successfully');
       }).catch((err: BusinessError) => {
         console.error(`Write failed, code is ${err.code}, message is ${err.message}`);
       });
     });
   }
   ```

4. 调用read()接口查询顶点、边、路径。示例代码如下所示：

   ```ts
   const QUERY_VERTEX = "MATCH (person:Person) RETURN person;"

   const QUERY_EDGE = "MATCH ()-[relation:Friend]->() RETURN relation;"

   const QUERY_PATH = "MATCH path=(a:Person {name: 'name_1'})-[]->{2, 2}(b:Person {name: 'name_3'}) RETURN path;"

   if(store != null) {
     (store as graphStore.GraphStore).read(QUERY_VERTEX).then((result: graphStore.Result) => {
       console.info('Query vertex successfully');
       result.records?.forEach((data) => {
         for (let item of Object.entries(data)) {
           const key = item[0];
           const value = item[1];
           const vertex = value as graphStore.Vertex;
           console.info(`key : ${key}, vertex.properties : ${JSON.stringify(vertex.properties)}`);
         }
       });
     }).catch((err: BusinessError) => {
       console.error(`Query vertex failed, code is ${err.code}, message is ${err.message}`);
     });

     (store as graphStore.GraphStore).read(QUERY_EDGE).then((result: graphStore.Result) => {
       console.info('Query edge successfully');
       result.records?.forEach((data) => {
         for (let item of Object.entries(data)) {
           const key = item[0];
           const value = item[1];
           const edge = value as graphStore.Edge;
           console.info(`key : ${key}, edge.properties : ${JSON.stringify(edge.properties)}`);
         }
       });
     }).catch((err: BusinessError) => {
       console.error(`Query edge failed, code is ${err.code}, message is ${err.message}`);
     });

     (store as graphStore.GraphStore).read(QUERY_PATH).then((result: graphStore.Result) => {
       console.info('Query path successfully');
       result.records?.forEach((data) => {
         for (let item of Object.entries(data)) {
           const key = item[0];
           const value = item[1];
           const path = value as graphStore.Path;
           console.info(`key : ${key}, path.length : ${path.length}`);
         }
       });
     }).catch((err: BusinessError) => {
       console.error(`Query path failed, code is ${err.code}, message is ${err.message}`);
     })
   }
   ```

5. 调用write()接口删除顶点、边。示例代码如下所示：

   ```ts
   const DELETE_VERTEX_AND_RELATED_EDGE = "MATCH (p:Person {name: 'name_1'}) DETACH DELETE p;"

   const DELETE_EDGE_ONLY = "MATCH (p2:Person {name: 'name_2'})-[relation: Friend]->(p3:Person {name: 'name_3'})" +
     " DETACH DELETE relation;"

   if(store != null) {
     (store as graphStore.GraphStore).write(DELETE_VERTEX_AND_RELATED_EDGE).then(() => {
       console.info('Delete vertex and related edge successfully');
     }).catch((err: BusinessError) => {
       console.error(`Delete vertex and related edge failed, code is ${err.code}, message is ${err.message}`);
     });

     (store as graphStore.GraphStore).write(DELETE_EDGE_ONLY).then(() => {
       console.info('Delete edge only successfully');
     }).catch((err: BusinessError) => {
       console.error(`Delete edge only failed, code is ${err.code}, message is ${err.message}`);
     })
   }
   ```

6. 创建事务并使用事务进行写入、查询、提交、回滚。示例代码如下所示：

   ```ts
   let transactionRead: graphStore.Transaction | null = null;
   let transactionWrite: graphStore.Transaction | null = null;

   const INSERT = "INSERT (:Person {name: 'name_5', age: 55});";
   
   const QUERY = "MATCH (person:Person) RETURN person;";

   if(store != null) {
     (store as graphStore.GraphStore).createTransaction().then((trans: graphStore.Transaction) => {
       transactionRead = trans;
       console.info('Create transactionRead successfully');
     }).catch((err: BusinessError) => {
       console.error(`Create transactionRead failed, code is ${err.code}, message is ${err.message}`);
     });

     (store as graphStore.GraphStore).createTransaction().then((trans: graphStore.Transaction) => {
       transactionWrite = trans;
       console.info('Create transactionWrite successfully');
     }).catch((err: BusinessError) => {
       console.error(`Create transactionWrite failed, code is ${err.code}, message is ${err.message}`);
     });

     if(transactionRead != null) {
       (transactionRead as graphStore.Transaction).read(QUERY).then((result: graphStore.Result) => {
         console.info('Transaction read successfully');
         result.records?.forEach((data) => {
           for (let item of Object.entries(data)) {
             const key = item[0];
             const value = item[1];
             const vertex = value as graphStore.Vertex;
             console.info(`key : ${key}, vertex.properties : ${JSON.stringify(vertex.properties)}`);
           }
         });
       }).catch((err: BusinessError) => {
         console.error(`Transaction read failed, code is ${err.code}, message is ${err.message}`);
       });

       (transactionRead as graphStore.Transaction).rollback().then(() => {
         console.info(`Rollback successfully`);
         transactionRead = null;
       }).catch ((err: BusinessError) => {
         console.error(`Rollback failed, code is ${err.code}, message is ${err.message}`);
       })
     }

     if(transactionWrite != null) {
       (transactionWrite as graphStore.Transaction).write(INSERT).then(() => {
         console.info('Transaction write successfully');
       }).catch((err: BusinessError) => {
         console.error(`Transaction write failed, code is ${err.code}, message is ${err.message}`);
       });

       (transactionWrite as graphStore.Transaction).commit().then(() => {
         console.info(`Commit successfully`);
         transactionWrite = null;
       }).catch ((err: BusinessError) => {
         console.error(`Commit failed, code is ${err.code}, message is ${err.message}`);
       })
     }
   }
   ```

7. 删除数据库。调用deleteStore()方法，删除数据库及数据库相关文件。示例代码如下所示：

   ```ts
   const DROP_GRAPH_GQL = "DROP GRAPH test;"

   class EntryAbility extends UIAbility {
     onWindowStageDestroy() {
       if(store != null) {
         // 删除图，可忽略此步
         (store as graphStore.GraphStore).write(DROP_GRAPH_GQL).then(() => {
           console.info('Drop graph successfully');
         }).catch((err: BusinessError) => {
           console.error(`Drop graph failed, code is ${err.code}, message is ${err.message}`);
         });

         // 关闭数据库，示例在EntryAbility中实现，使用者也可以在其他合理场景中使用
         (store as graphStore.GraphStore).close().then(() => {
           console.info(`Close successfully`);
         }).catch ((err: BusinessError) => {
           console.error(`Close failed, code is ${err.code}, message is ${err.message}`);
         })
       }

       // 删库时使用的StoreConfig应与最后一次开库时使用的StoreConfig保持一致
       graphStore.deleteStore(this.context, STORE_CONFIG_NEW).then(() => {
         store = null;
         console.info('Delete GraphStore successfully.');
       }).catch((err: BusinessError) => {
         console.error(`Delete GraphStore failed, code is ${err.code},message is ${err.message}`);
       })
     }
   }
   ```