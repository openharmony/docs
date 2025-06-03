# 通过向量数据库实现数据持久化 (ArkTS)


## 场景介绍

向量数据库是一种支持存储、管理和检索向量数据的数据库，也支持标量的关系型数据处理。数据类型"floatvector"用来存储数据向量化的结果，从而实现对这些数据的快速检索和相似性搜索‌。</br>
从API version 18开始，支持通过向量数据库实现数据持久化。

## 基本概念

- **结果集**：指用户查询之后的结果集合，可以对数据进行访问。结果集提供了灵活的数据访问方式，可以更方便地拿到用户想要的数据。
- **floatvector**：该数据类型表示向量数据，例如[1.0, 3.0, 2.4, 5.1, 6.2, 11.7]。

## 约束限制

- 系统默认日志方式是[WAL](data-terminology.md#wal模式)（Write Ahead Log）模式，系统默认落盘方式是[FULL模式](data-terminology.md#full模式)。

- 数据库中默认有4个读连接和1个写连接，线程获取到空闲读连接时，即可进行读取操作。当没有空闲读连接时，会创建新的读连接。

- 为保证数据的准确性，数据库同一时间只能支持一个写操作，并发的写操作会串行执行。

- 当应用被卸载完成后，设备上的相关数据库文件及临时文件会被自动清除。

- ArkTS侧支持的基本数据类型：number、string、二进制类型数据、boolean；特殊数据类型：ValueType。

- 为保证插入并读取数据成功，建议一条数据不要超过2M。超出该大小，插入成功，读取失败。

## 规格限制

### 数据类型

数据库表字段的类型，如下所示：

| 类型 | 描述 | 是否支持 |
| -------- | -------- | -------- |
| NULL | 空值 | 是 |
| INTEGER | 整形 | 是 |
| DOUBLE | 浮点类型 | 是 |
| TEXT | 字符串类型 | 是 |
| BLOB | 二进制类型 | 是 |
| FLOATVECTOR | 向量数据类型 | 是 |

### 字段约束

数据库表字段的约束，如下所示：

| 功能 | SQL语法 | 是否支持 |
| -------- | -------- | -------- |
| 不可为NULL | NOT NULL | 是 |
| 默认值 | DEFAULT  | 是 |
| 唯一索引 | UNIQUE | 是 |
| 主键索引 | PRIMARY KEY | 是 |
| 外键索引 | FOREIGN | 否 |
| CHECK约束 | CHECK | 否 |

### 子句

查询语句中的子句，如下所示：

| 关键字 | 描述 | 是否支持 |
| -------- | -------- | -------- |
| WHERE | 从一个或多个表中获取数据的条件。 | 是 |
| LIMIT | 返回数据的限制。  | 是 |
| ORDER BY | 基于一列或多列排序。 | 是 |
| ORDER BY 向量距离 | <->是L2距离，<=>是余弦距离。 | 是 |
| GROUP BY | 对相同的数据进行分组。 | 是 |
| HAVING | 过滤聚合函数的结果。 | 是 |
| INDEXED BY | 查询时必须使用特定索引。 | 是 |
| DISTINCT | 消除重复记录。 | 否 |

### 集合

查询语句中的集合语句，如下所示：

| 关键字 | 描述 | 是否支持 |
| -------- | -------- | -------- |
| UNION | 合并两个或多个查询语句的结果并去重。 | 是 |
| UNION ALL | 合并两个或多个查询语句的结果。 | 是 |

### 运算符

针对某个条件做筛选时，可以使用运算符，一般在查询语句中使用。运算符如下所示：

| 运算类型 | 符号 | 是否支持 |
| -------- | -------- | -------- |
| 算术运算 | +、-、*、/、% | 是 |
| 比较运算 | ==、=、!=、>、>=、<、<= | 是 |
| 逻辑运算 | AND、BETWEEN、EXISTS、IN、NOT IN、NOT、OR、IS NULL、IS、IS NOT、LIKE、GLOB | 是 |
| 字符串拼接运算 | \|\| | 是 |
| 位运算 | &、\|、~、<<、>> | 是 |
| 向量距离运算 | <->、<=> | 是，支持在聚合函数max和min中使用 |

### 时间&日期

根据不同的时间函数返回不同格式的日期，一般在查询语句中使用。时间&日期函数如下所示：

| 关键字 | 描述 | 是否支持 |
| -------- | -------- | -------- |
| DATE | 以"YYYY-MM-DD"格式返回日期。 | 是 |
| TIME | 以"HH:MM:SS"格式返回时间。 | 是 |
| DATETIME | 以"YYYY-MM-DD HH:MM:SS"格式返回。 | 是 |
| JULIANDAY | 返回从格林尼治时间的公元前4714年11月24日正午算起的天数。 | 是 |
| STRFTIME | 根据第一个参数指定的格式字符串返回格式化的日期。 | 是 |

### 函数

SQL语句中的函数，如下所示：

| 关键字 | 描述 | 是否支持 |
| -------- | -------- | -------- |
| COUNT | 计算查询返回的行数。 | 是 |
| MAX/MIN | 选择某列的最大值/最小值。 | 是 |
| AVG | 计算某列的平均值。 | 是 |
| SUM | 计算某列的总和。 | 是 |
| RANDOM | 返回一个'-9223372036854775808'到'9223372036854775807'之间的伪随机整数。 | 是 |
| ABS | 计算绝对值。 | 是 |
| UPPER/LOWER | 将字符串转换为大/小写字母。 | 是 |
| LENGTH | 返回字符串的长度。 | 是 |

## 接口说明

以下是向量数据库持久化功能的相关接口，更多接口及使用方式请见[关系型数据库](../reference/apis-arkdata/js-apis-data-relationalStore.md)。

| 接口名称 | 描述 |
| -------- | -------- |
| getRdbStore(context: Context, config: StoreConfig): Promise&lt;RdbStore&gt; | 用户可以根据自己的需求配置StoreConfig参数获得RdbStore对象，通过调用RdbStore接口执行数据操作。|
| execute(sql: string, txId: number, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt; | 执行包含指定参数的SQL语句，语句中的各种表达式和操作符之间的关系操作符号(例如=、>、<)不超过1000个。 |
| querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt; | 根据指定SQL语句查询数据库中的数据，语句中的各种表达式和操作符之间的关系操作符号(例如=、>、<)不超过1000个。 |
| beginTrans(): Promise&lt;number&gt; | 在开始执行SQL语句之前，开始事务。 |
| commit(txId : number):Promise&lt;void&gt; | 提交已经执行的SQL语句，跟beginTrans配合使用。 |
| rollback(txId : number):Promise&lt;void&gt; | 回滚已经执行的SQL语句，跟beginTrans配合使用。 |
| deleteRdbStore(context: Context, config: StoreConfig): Promise&lt;void&gt; | 删除数据库。 |
| isVectorSupported(): boolean | 判断系统是否提供向量数据库能力。 |

## 开发步骤

1. 判断当前系统是否支持向量数据库，若不支持，则表示当前系统不具备向量数据库能力。示例代码如下：

   ```ts
   import { relationalStore } from '@kit.ArkData'; // 导入模块
   import { UIAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { window } from '@kit.ArkUI';     
   // 此处示例在Ability中实现，使用者也可以在其他合理场景中使用
   class EntryAbility extends UIAbility {
     async onWindowStageCreate(windowStage: window.WindowStage) {
        // 判断当前系统是否支持向量数据库
       let ret = relationalStore.isVectorSupported();
       if (!ret) {
         console.error(`vectorDB is not supported .`);
         return;
       }
       // 开库、增删改查等
     }
   }
   ```

2. 若支持向量数据库则需要获取一个RdbStore。通过getRdbStore接口创建数据库，并执行建表操作。

   > **说明：**
   >
   > - 应用创建的数据库与其上下文（Context）有关，即使使用同样的数据库名称，不同的应用上下文也会产生多个数据库，例如每个UIAbility都有各自的上下文。
   > 
   > - 当应用首次获取数据库（调用getRdbStore）后，在应用沙箱内会产生对应的数据库文件。使用数据库的过程中，在与数据库文件相同的目录下可能会产生以-wal和-shm结尾的临时文件。此时若开发者希望移动数据库文件到其它地方使用查看，则需要同时移动这些临时文件，当应用被卸载完成后，其在设备上产生的数据库文件及临时文件也会被移除。
   > 
   > - 错误码的详细介绍请参见[通用错误码](../reference/errorcode-universal.md)和[关系型数据库错误码](../reference/apis-arkdata/errorcode-data-rdb.md)。

   示例代码如下：

   ```ts
   let store: relationalStore.RdbStore | undefined = undefined;
   const STORE_CONFIG :relationalStore.StoreConfig= {
     name: 'VectorTest.db', // 数据库文件名
     securityLevel: relationalStore.SecurityLevel.S1, // 数据库安全级别
     vector: true // 可选参数，该参数为true时才可以使用向量数据库。
   };   
   
   relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
     store = rdbStore;
     // 建表语句，floatvector(2)代表repr的维度是2
     const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, repr floatvector(2));';
     // 第二个入参表示不开启显示事务，第三个参数undefined表示未使用参数绑定
     await store!.execute(SQL_CREATE_TABLE, 0, undefined); 
   }).catch((err: BusinessError) => {
     console.error(`Get RdbStore failed, code is ${err.code}, message is ${err.message}`);
   });  
   ```

3. 获取到RdbStore后，调用execute接口插入数据。

   > **说明：**
   >
   > 向量数据库没有显式的flush操作实现持久化，数据插入即保存在持久化文件。
   
   示例代码如下：

   ```ts
   try {
     // 使用参数绑定
     const vectorValue: Float32Array = Float32Array.from([1.2, 2.3]);
     await store!.execute("insert into test VALUES(?, ?);", 0, [0, vectorValue]);
     // 不使用参数绑定
     await store!.execute("insert into test VALUES(1, '[1.3, 2.4]');", 0, undefined);
   } catch (err) {
     console.error(`execute insert failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

4. 获取到RdbStore后，调用execute接口修改或删除数据。示例代码如下：

   ```ts
   // 修改数据
   try {
     // 使用参数绑定
     const vectorValue1: Float32Array = Float32Array.from([2.1, 3.2]);
     await store!.execute("update test set repr = ? where id = ?", 0, [vectorValue1, 0]);
     // 不使用参数绑定
     await store!.execute("update test set repr = '[5.1, 6.1]' where id = 0", 0, undefined);
   } catch (err) {
     console.error(`execute update failed, code is ${err.code}, message is ${err.message}`);
   }

   // 删除数据
   try {
     // 使用参数绑定
     await store!.execute("delete from test where id = ?", 0, [0]);
     // 不使用参数绑定
     await store!.execute("delete from test where id = 0", 0, undefined);
   } catch (err) {
     console.error(`execute delete failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

5. 获取到RdbStore后，调用querySql方法查找数据，返回一个ResultSet结果集。

   > **说明：**
   >
   > 当应用完成查询数据操作，不再使用结果集（ResultSet）时，请及时调用close方法关闭结果集，释放系统为其分配的内存。

   示例代码如下：

   ```ts
   // 单表查询
   try {
     // 使用参数绑定
     const QUERY_SQL = "select id, repr <-> ? as distance from test where id > ? order by repr <-> ? limit 5;";
     const vectorValue2: Float32Array = Float32Array.from([6.2, 7.3]);
     let resultSet = await store!.querySql(QUERY_SQL, [vectorValue2, 0, vectorValue2]);
     while (resultSet!.goToNextRow()) {
        let id = resultSet.getValue(0);
        let dis = resultSet.getValue(1);
     }
     resultSet!.close();

     // 不使用参数绑定
     const QUERY_SQL1 = "select id, repr <-> '[6.2, 7.3]' as distance from test where id > 0 order by repr <-> '[6.2, 7.3]' limit 5;";
     resultSet = await store!.querySql(QUERY_SQL1);
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }

   // 子查询
   try {
     // 创建第二张表
     let CREATE_SQL = "CREATE TABLE IF NOT EXISTS test1(id text PRIMARY KEY);";
     await store!.execute(CREATE_SQL);
     let resultSet = await store!.querySql("select * from test where id in (select id from test1);");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }

   // 聚合查询
   try {
     let resultSet = await store!.querySql("select * from test where repr <-> '[1.0, 1.0]' > 0 group by id having max(repr <=> '[1.0, 1.0]');");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }

   // 多表查询
   try {
     // union all与union的区别在于union会将数据去重
     let resultSet = await store!.querySql("select id, repr <-> '[1.5, 5.6]' as distance from test union select id, repr <-> '[1.5, 5.6]' as distance from test order by distance limit 5;");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

6. 创建视图并执行查询。示例代码如下：

   ```ts
   // 视图查询
   try {
     // 创建视图
     await store!.execute("CREATE VIEW v1 as select * from test where id > 0;");
     let resultSet = await store!.querySql("select * from v1;");
     resultSet!.close();
   } catch (err) {
     console.error(`query failed, code is ${err.code}, message is ${err.message}`);
   }
   ```
   
7. ‌使用向量索引进行查询，提升查询效率。

   向量数据库索引‌是一种以向量作为键的索引机制，旨在提供高效且快速的搜索能力。
   
   当前支持的向量索引基础语法和扩展语法如下：

   - 基础语法如下：

     ```sql
     // index_name为索引名称，index_type是索引类型，dist_function是索引距离度量类型
     CREATE INDEX [IF NOT EXISTS] index_name ON table_name USING index_type (column_name dist_function);

     DROP INDEX table_name.index_name;
     ```
   - 扩展语法如下：

     ```sql
     CREATE INDEX [基础语法] [WITH(parameter = value [, ...])];
     ```

   **表1** 索引类型(index_type)

   | 类型      | 备注说明                                                     |
   | --------- | ------------------------------------------------------------ |
   | gsdiskann | 适用于处理高维稠密向量数据，如文本嵌入、图像特征等。         |

   **表2** 索引距离度量类型(dist_function)

   | 类型   | 计算符号 | 备注说明   |
   | ------ | -------- | ---------- |
   | L2     | <->      | 欧式距离。|
   | COSINE | <=>      | 余弦距离。|

   **表3** 扩展语法参数(parameter)

   | 参数名称   | 取值范围和约束 | 备注说明   |
   | ------ | -------- | ---------- |
   | QUEUE_SIZE | 设置范围是[10, 1000]，默认值 20。     | 代表创建索引搜索近邻的时候候选队列的长度，queue_size越大，构建速度降低，召回率有略微提升。 |
   | OUT_DEGREE | 设置范围是[1, 1200] ，默认值 60。      | 邻居节点出度数量。out_degree与pageSize也有关系，out_degree的数量超过pageSize的存储范围将报错GRD_INVALID_ARGS。|

   > **说明：**
   >
   > - 删除索引的时候需要指定表名称，即Drop Index table.index_name。
   > 
   > - 随表一起创建的索引不能删除，如建表时创建的主键。
   > 
   > - 向量索引的命中条件。必须是ORDER BY + LIMIT类型的查询，ORDER BY只有一个排序条件，这个条件是向量距离条件；ORDER BY与DESC连用，不会使用向量索引；查询距离度量与创建索引时的度量需要保持一致，例如创建向量索引时使用L2，在查询时使用<->进行度量才可以命中索引。

   示例代码如下：

   ```ts
   // 基础用法
   try {
     // 创建的索引名称为diskann_l2_idx，索引列为repr，类型为gsdiskann，距离度量类型为L2
     await store!.execute("CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(repr L2);");
     // 删除表test中的diskann_l2_idx索引
     await store!.execute("DROP INDEX test.diskann_l2_idx;");
   } catch (err) {
     console.error(`create index failed, code is ${err.code}, message is ${err.message}`);
   }

   // 扩展语法
   try {
     // 设置QUEUE_SIZE为20，OUT_DEGREE为50
     await store!.execute("CREATE INDEX diskann_l2_idx ON test USING GSDISKANN(repr L2) WITH (queue_size=20, out_degree=50);");
   } catch (err) {
     console.error(`create ext index failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

8. 配置数据老化功能。当应用的数据需要定期清理时，可以按时间或空间配置数据老化策略，从而实现数据的自动化清理。
   
   语法如下所示：

   ```sql
   CREATE TABLE table_name(column_name type [, ...]) [WITH(parameter = value [, ...])];
   ```

   其中，parameter为可配置的参数，value为对应取值，具体情况见下表。

   **表4** 数据老化策略参数(parameter)

   | 参数名称 | 必填 | 取值范围和使用说明 |
   | ------ | -------- | ---------- |
   | time_col | 是 | 列名。类型必须为整数且不为空。 |
   | interval | 否 | 老化任务线程的执行间隔时间，超过该时间后执行写操作，触发老化任务，删除符合老化条件的数据；若在间隔时间内执行写操作，不会触发老化任务。取值范围是[5 second, 1 year]，时间单位支持second、minute、hour、day、month、year，不区分大小写或复数形式(1 hour和1 hours均可)，默认是1 day。 |
   | ttl | 否 | 数据保留时间。取值范围是[1 hour, 1 year]，时间单位支持second、minute、hour、day、month、year，不区分大小写或复数形式(1 hour和1 hours均可)，默认是3 month。 |
   | max_num | 否 | 数据量限制。取值范围是[100, 1024]，默认是1024。老化任务在执行完过期数据删除后，如剩余表内数据超过max_num行，则会找到距离过期时间最近的时间点，删除该时间点对应的所有数据，直到数据量少于max_num。 |

   时间相关参数会按数值换算为秒作为原子单位，取值规则如下所示：

   | 单位 | 向下换算成秒取值 |
   | ------ | -------- |
   | year | 365 * 24 * 60 * 60 |
   | month | 30 * 24 * 60 * 60 |
   | day | 24 * 60 * 60 |
   | hour | 60 * 60 |
   | minute | 60 |

   例如配置`ttl = '3 months'`，实际ttl会被换算为`3 * (30 * 24 * 60 * 60) = 7776000 seconds`。

   示例代码如下：

   ```ts
   try {
     // 每隔五分钟执行写操作后，会触发数据老化任务
     await store!.execute("CREATE TABLE test2(rec_time integer not null) WITH (time_col = 'rec_time', interval = '5 minute');");
   } catch (err) {
     console.error(`configure data aging failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

9. 配置数据压缩功能。该功能在建表时配置，可以压缩数据类型为text的列数据。

   从API version 20开始，支持数据压缩功能。

   语法如下所示：

   ```sql
   CREATE TABLE table_name(content text [, ...]) [WITH(compress_col = 'content')];
   ```

   其中，compress_col为必填参数，value是类型为text的数据列名，可以与数据老化功能同时配置。

   示例代码如下：

   ```ts
   try {
     // content列配置了数据压缩，并且配置了数据老化。
     await store!.execute("CREATE TABLE IF NOT EXISTS test3 (time integer not null, content text) with (time_col = 'time', interval = '5 minute', compress_col = 'content');");
   } catch (err) {
     console.error(`configure data compress failed, code is ${err.code}, message is ${err.message}`);
   }
   ```

10. 删除数据库。

    调用deleteRdbStore方法，删除数据库及数据库相关文件。示例代码如下：

    ```ts
    try {
      await relationalStore.deleteRdbStore(this.context, STORE_CONFIG);
    } catch (err) {
      console.error(`delete rdbStore failed, code is ${err.code},message is ${err.message}`);
    }
    ```

   