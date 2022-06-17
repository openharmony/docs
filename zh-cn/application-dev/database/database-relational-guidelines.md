# 关系型数据库开发指导

## 场景介绍

关系型数据库是在SQLite基础上实现的本地数据操作机制，提供给用户无需编写原生SQL语句就能进行数据增删改查的方法，同时也支持原生SQL语句操作。


## 接口说明

### 数据库的创建和删除

关系型数据库提供了数据库创建方式，以及对应的删除接口，涉及的API如下所示。

**表1** 数据库创建和删除API

| 接口名 | 描述 |
| -------- | -------- |
|getRdbStore(config:&nbsp;StoreConfig,&nbsp;version:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;RdbStore&gt;):&nbsp;void | 获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，结果以callback形式返回。<br/>-&nbsp;config：与此RDB存储相关的数据库配置。<br/>-&nbsp;version：数据库版本。<br/>-&nbsp;callback：指定callback回调函数。返回一个RdbStore。 |
|getRdbStore(config:&nbsp;StoreConfig,&nbsp;version:&nbsp;number):&nbsp;Promise&lt;RdbStore&gt; | 获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，结果以Promise形式返回。<br/>-&nbsp;config：与此RDB存储相关的数据库配置。<br/>-&nbsp;version：数据库版本。 |
|deleteRdbStore(name:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 删除数据库，结果以callback形式返回。<br/>-&nbsp;name：数据库名称。<br/>-&nbsp;callback：指定callback回调函数。 |
| deleteRdbStore(name:&nbsp;string):&nbsp;Promise&lt;void&gt; | 使用指定的数据库文件配置删除数据库，结果以Promise形式返回。<br/>-&nbsp;name：数据库名称。 |

### 数据库的增删改查

关系型数据库提供对本地数据增删改查操作的能力，相关API如下所示。

- **新增**
  
  关系型数据库提供了插入数据的接口，通过ValuesBucket输入要存储的数据，通过返回值判断是否插入成功，插入成功时返回最新插入数据所在的行号，失败时则返回-1。
  
  **表2** 数据库插入API
  
  | 类名 | 接口名 | 描述 |
  | -------- | -------- | -------- |
  | RdbStore | insert(name:&nbsp;string,&nbsp;values:&nbsp;ValuesBucket,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):void | 向目标表中插入一行数据，结果以callback形式返回。<br/>-&nbsp;name：指定的目标表名。<br/>-&nbsp;values：表示要插入到表中的数据行。<br/>-&nbsp;callback：指定callback回调函数。如果操作成功，返回行ID；否则返回-1。 |
  | RdbStore | insert(name:&nbsp;string,&nbsp;values:&nbsp;ValuesBucket):&nbsp;Promise&lt;number&gt; | 向目标表中插入一行数据，结果以Promise形式返回。<br/>-&nbsp;name：指定的目标表名。<br/>-&nbsp;values：表示要插入到表中的数据行。 |
  
- **更新**
  
  调用更新接口，传入要更新的数据，并通过RdbPredicates指定更新条件。该接口的返回值表示更新操作影响的行数。如果更新失败，则返回0。
  
  **表3** 数据库更新API
  
  | 类名 | 接口名 | 描述 |
  | -------- | -------- | -------- |
  | RdbStore | update(values:&nbsp;ValuesBucket,&nbsp;rdbPredicates:&nbsp;RdbPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):void | 根据RdbPredicates的指定实例对象更新数据库中的数据，结果以callback形式返回。<br/>-&nbsp;values：以ValuesBucket存储的要更新的数据。<br/>-&nbsp;rdbPredicates：表示RdbPredicates的实例对象指定的更新条件。<br/>-&nbsp;callback：指定的callback回调方法。返回受影响的行数。 |
  | RdbStore | update(values:&nbsp;ValuesBucket,&nbsp;rdbPredicates:&nbsp;RdbPredicates):&nbsp;Promise\<number> | 根据RdbPredicates的指定实例对象更新数据库中的数据，结果以Promise形式返回。<br/>-&nbsp;values：以ValuesBucket存储的要更新的数据。<br/>-&nbsp;rdbPredicates：表示RdbPredicates的实例对象指定的更新条件。 |
  
- **删除** 
  
  调用删除接口，通过RdbPredicates指定删除条件。该接口的返回值表示删除的数据行数，可根据此值判断是否删除成功。如果删除失败，则返回0。
  
  **表4** 数据库删除API
  
  | 类名 | 接口名 | 描述 |
  | -------- | -------- | -------- |
  | RdbStore | delete(rdbPredicates:&nbsp;RdbPredicates,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):void | 根据rdbPredicates的指定实例对象从数据库中删除数据，结果以callback形式返回。<br/>-&nbsp;rdbPredicates：RdbPredicates的实例对象指定的删除条件。<br/>-&nbsp;callback：指定callback回调函数。返回受影响的行数。 |
  | RdbStore | delete(rdbPredicates:&nbsp;RdbPredicates):&nbsp;Promise\<number> | 根据rdbPredicates的指定实例对象从数据库中删除数据，结果以Promise形式返回。<br/>-&nbsp;rdbPredicates：RdbPredicates的实例对象指定的删除条件。 |
  
- **查询** 

  关系型数据库提供了两种查询数据的方式：

  - 直接调用查询接口。使用该接口，会将包含查询条件的谓词自动拼接成完整的SQL语句进行查询操作，无需用户传入原生的SQL语句。
  - 执行原生的SQL语句进行查询操作。

  **表5** 数据库查询API

  | 类名 | 接口名 | 描述 |
  | -------- | -------- | -------- |
  | RdbStore | query(rdbPredicates:&nbsp;RdbPredicates,&nbsp;columns:&nbsp;Array,&nbsp;callback:&nbsp;AsyncCallback&lt;ResultSet&gt;):&nbsp;void | 根据指定条件查询数据库中的数据，结果以callback形式返回。<br/>-&nbsp;rdbPredicates：表示RdbPredicates的实例对象指定的查询条件。<br/>-&nbsp;columns：表示要查询的列。如果值为空，则查询应用于所有列。<br/>-&nbsp;callback：指定callback回调函数。如果操作成功，则返回ResultSet对象。 |
  | RdbStore | query(rdbPredicates:&nbsp;RdbPredicates,&nbsp;columns:&nbsp;Array):&nbsp;Promise&lt;ResultSet&gt; | 根据指定条件查询数据库中的数据，结果以Promise形式返回。<br/>-&nbsp;rdbPredicates：表示RdbPredicates的实例对象指定的查询条件。<br/>-&nbsp;columns：表示要查询的列。如果值为空，则查询应用于所有列。 |
  | RdbStore | querySql(sql:&nbsp;string,&nbsp;bindArgs:&nbsp;Array&lt;ValueType&gt;,&nbsp;callback:&nbsp;AsyncCallback&lt;ResultSet&gt;):void | 根据指定SQL语句查询数据库中的数据，结果以callback形式返回。<br/>-&nbsp;sql：指定要查询的SQL语句。<br/>-&nbsp;bindArgs：SQL语句中参数的值。<br/>-&nbsp;callback：指定callback回调函数。如果操作成功，则返回ResultSet对象。 |
  | RdbStore | querySql(sql:&nbsp;string,&nbsp;bindArgs?:&nbsp;Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt; | 根据指定SQL语句查询数据库中的数据，结果以Promise形式返回。<br/>-&nbsp;sql：指定要查询的SQL语句。<br/>-&nbsp;bindArgs：SQL语句中参数的值。 |

### 数据库谓词的使用

关系型数据库提供了用于设置数据库操作条件的谓词RdbPredicates，该类确定RDB中条件表达式的值是true还是false。

**表6** 数据库谓词API

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbPredicates |inDevices(devices: Array\<string>): RdbPredicates | 同步分布式数据库时指定组网内的远程设备。<br/>-&nbsp;devices：组网内指定的远程设备ID。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates |inAllDevices(): RdbPredicates | 同步分布式数据库时连接到组网内的所有远程设备。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | equalTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为ValueType且值等于指定值的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | notEqualTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为ValueType且值不等于指定值的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | beginWrap():&nbsp;RdbPredicates | 向谓词添加左括号。<br/>-&nbsp;RdbPredicates：返回带有左括号的谓词。 |
| RdbPredicates | endWrap():&nbsp;RdbPredicates | 向谓词添加右括号。<br/>-&nbsp;RdbPredicates：返回带有右括号的谓词。 |
| RdbPredicates | or():&nbsp;RdbPredicates | 将或条件添加到谓词中。<br/>-&nbsp;RdbPredicates：返回带有或条件的谓词。 |
| RdbPredicates | and():&nbsp;RdbPredicates | 向谓词添加和条件。<br/>-&nbsp;RdbPredicates：返回带有和条件的谓词。 |
| RdbPredicates | contains(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicats | 配置谓词以匹配数据字段为String且value包含指定值的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回带有包含条件的谓词。 |
| RdbPredicates | beginsWith(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为String且值以指定字符串开头的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | endsWith(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为String且值以指定字符串结尾的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | isNull(field:&nbsp;string):&nbsp;RdbPredicates | 配置谓词以匹配值为null的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | isNotNull(field:&nbsp;string):&nbsp;RdbPredicates | 配置谓词以匹配值不为null的指定字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | like(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为String且值类似于指定字符串的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | glob(field:&nbsp;string,&nbsp;value:&nbsp;string):&nbsp;RdbPredicates | 配置RdbPredicates匹配数据字段为String的指定字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | between(field:&nbsp;string,&nbsp;low:&nbsp;ValueType,&nbsp;high:&nbsp;ValueType):&nbsp;RdbPredicates | 将谓词配置为匹配数据字段为ValueType且value在给定范围内的指定字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;low：指示与谓词匹配的最小值。<br/>-&nbsp;high：指示与谓词匹配的最大值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | notBetween(field:&nbsp;string,&nbsp;low:&nbsp;ValueType,&nbsp;high:&nbsp;ValueType):&nbsp;RdbPredicates | 配置RdbPredicates以匹配数据字段为ValueType且value超出给定范围的指定字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;low：指示与谓词匹配的最小值。<br/>-&nbsp;high：指示与谓词匹配的最大值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | greaterThan(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicatesgr | 配置谓词以匹配数据字段为ValueType且值大于指定值的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | lessThan(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为valueType且value小于指定值的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | greaterThanOrEqualTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为ValueType且value大于或等于指定值的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | lessThanOrEqualTo(field:&nbsp;string,&nbsp;value:&nbsp;ValueType):&nbsp;RdbPredicates | 配置谓词以匹配数据字段为ValueType且value小于或等于指定值的字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：指示要与谓词匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | orderByAsc(field:&nbsp;string):&nbsp;RdbPredicates | 配置谓词以匹配其值按升序排序的列。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | orderByDesc(field:&nbsp;string):&nbsp;RdbPredicates | 配置谓词以匹配其值按降序排序的列。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | distinct():&nbsp;RdbPredicates | 配置谓词以过滤重复记录并仅保留其中一个。<br/>-&nbsp;RdbPredicates：返回可用于过滤重复记录的谓词。 |
| RdbPredicates | limitAs(value:&nbsp;number):&nbsp;RdbPredicates | 设置最大数据记录数的谓词。<br/>-&nbsp;value：最大数据记录数。<br/>-&nbsp;RdbPredicates：返回可用于设置最大数据记录数的谓词。 |
| RdbPredicates | offsetAs(rowOffset:&nbsp;number):&nbsp;RdbPredicates | 配置RdbPredicates以指定返回结果的起始位置。<br/>-&nbsp;rowOffset：返回结果的起始位置，取值为正整数。<br/>-&nbsp;RdbPredicates：返回具有指定返回结果起始位置的谓词。 |
| RdbPredicates | groupBy(fields:&nbsp;Array&lt;string&gt;):&nbsp;RdbPredicates | 配置RdbPredicates按指定列分组查询结果。<br/>-&nbsp;fields：指定分组依赖的列名。<br/>-&nbsp;RdbPredicates：返回分组查询列的谓词。 |
| RdbPredicates | indexedBy(indexName:&nbsp;string):&nbsp;RdbPredicates | 配置RdbPredicates以指定索引列。<br/>-&nbsp;indexName：索引列的名称。<br/>-&nbsp;RdbPredicates：返回具有指定索引列的RdbPredicates。 |
| RdbPredicates | in(field:&nbsp;string,&nbsp;value:&nbsp;Array&lt;ValueType&gt;):&nbsp;RdbPredicates | 配置RdbPredicates以匹配数据字段为ValueType数组且值在给定范围内的指定字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：以ValueType型数组形式指定的要匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |
| RdbPredicates | notIn(field:&nbsp;string,&nbsp;value:&nbsp;Array&lt;ValueType&gt;):&nbsp;RdbPredicates | 将RdbPredicates配置为匹配数据字段为ValueType且值超出给定范围的指定字段。<br/>-&nbsp;field：数据库表中的列名。<br/>-&nbsp;value：以ValueType型数组形式指定的要匹配的值。<br/>-&nbsp;RdbPredicates：返回与指定字段匹配的谓词。 |

### 查询结果集的使用

关系型数据库提供了查询返回的结果集ResultSet，其指向查询结果中的一行数据，供用户对查询结果进行遍历和访问。ResultSet对外API如下所示。

> **须知：**
> **结果集使用完后，请一定要调用close方法显式关闭。**

**表7** 结果集API

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| ResultSet | goTo(offset:number):&nbsp;boolean | 从结果集当前位置移动指定偏移量。 |
| ResultSet | goToRow(position:&nbsp;number):&nbsp;boolean | 将结果集移动到指定位置。 |
| ResultSet | goToNextRow():&nbsp;boolean | 将结果集向后移动一行。 |
| ResultSet | goToPreviousRow():&nbsp;boolean | 将结果集向前移动一行。 |
| ResultSet | getColumnIndex(columnName:&nbsp;string):&nbsp;number | 根据指定的列名获取列索引。 |
| ResultSet | getColumnName(columnIndex:&nbsp;number):&nbsp;string | 根据指定的列索引获取列名。 |
| ResultSet | goToFirstRow():&nbsp;boolean | 判断结果集当前位置是否在第一行。 |
| ResultSet | goToLastRow():&nbsp;boolean | 判断结果集当前位置是否在最后一行。 |
| ResultSet | getString(columnIndex:&nbsp;number):&nbsp;string | 获取当前行指定列的值，以String类型返回。 |
| ResultSet | getBlob(columnIndex:&nbsp;number):&nbsp;Uint8Array | 获取当前行指定列的值，以字节数组形式返回。 |
| ResultSet | getDouble(columnIndex:&nbsp;number):&nbsp;number | 获取当前行指定列的值，以double型返回。 |
| ResultSet | isColumnNull(columnIndex:&nbsp;number):&nbsp;boolean | 检查当前行中指定列的值是否为null。 |
| ResultSet | close():&nbsp;void | 关闭结果集。 |



### 设置分布式列表

>**注意：**  在使用RdbStore的setDistributedTables、obtainDistributedTableName、sync、on、off接口时，需要请求相应的权限：ohos.permission.DISTRIBUTED_DATASYNC。

**设置分布式列表**

**表8** 设置分布式列表

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbStore | setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void | 设置分布式列表，结果以callback形式返回。<br/>-&nbsp;tables：要设置的分布式列表表名。<br/>-&nbsp;callback：指定callback回调函数。 |
| RdbStore | setDistributedTables(tables: Array\<string>): Promise\<void> | 设置分布式列表，结果以Promise形式返回。<br/>-&nbsp;tables：要设置的分布式列表表名。 |

**根据本地表名获取指定远程设备的分布式表名**

用户根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名。

**表9** 根据本地表名获取指定远程设备的分布式表名

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbStore | obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void | 根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名, 结果以callback形式返回。<br/>-&nbsp;device：远程设备。<br/>-&nbsp;table：本地表名。<br/>-&nbsp;callback：指定的callback回调函数，如果操作成功，返回远程设备的分布式表名。  |
| RdbStore | obtainDistributedTableName(device: string, table: string): Promise\<string> | 根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名，结果以Promise形式返回。<br/>-&nbsp;device：远程设备。<br/>-&nbsp;table：本地表名。 |

**在设备之间同步数据**

**表10** 在设备之间同步数据

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbStore | sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[string, number]>>): void | 在设备之间同步数据，结果以callback形式返回。<br/>-&nbsp;mode：指同步模式。SYNC_MODE_PUSH 表示数据从本地设备推送到远程设备；SYNC_MODE_PULL 表示数据从远程设备拉至本地设备。<br/>-&nbsp;predicates：约束同步数据和设备。<br/>-&nbsp;callback：指定的callback回调函数，string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |
| RdbStore | sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[string, number]>> | 在设备之间同步数据，结果以Promise形式返回。<br/>-&nbsp;mode：指同步模式。SYNC_MODE_PUSH 表示数据从本地设备推送到远程设备；SYNC_MODE_PULL 表示数据从远程设备拉至本地设备。<br/>-&nbsp;predicates：约束同步数据和设备。  |

**注册数据库的观察者**

**表11** 注册数据库的观察者

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbStore |on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void| 注册数据库的观察者。当分布式数据库中的数据发生更改时，将调用回调。<br/>-&nbsp;type：指在{@code SubscribeType}中定义的订阅类型；SUBSCRIBE_TYPE_REMOTE 订阅远程数据更改。<br/>-&nbsp;observer：指分布式数据库中数据更改事件的观察者。 |

**从数据库中删除指定类型的指定观察者**

**表12** 从数据库中删除指定类型的指定观察者

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbStore |off(event:'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void;| 从数据库中删除指定类型的指定观察者，结果以callback形式返回。<br/>-&nbsp;type：指在{@code SubscribeType}中定义的订阅类型；SUBSCRIBE_TYPE_REMOTE 订阅远程数据更改。<br/>-&nbsp;observer：指已注册的数据更改观察者。 |

### 数据库的备份和恢复

**备份**

**表13** 备份数据库

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbStore |backup(destName:string, callback: AsyncCallback&lt;void&gt;):void| 以指定名称备份数据库，结果以callback形式返回。<br/>-&nbsp;destName：指定数据库的备份文件名。<br/>-&nbsp;callback：指定callback回调函数。 |
| RdbStore |backup(destName:string): Promise&lt;void&gt;| 以指定名称备份数据库，结果以promise形式返回。<br/>-&nbsp;destName：指定数据库的备份文件名。 |

**恢复**

**表13** 恢复数据库

| 类名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| RdbStore |restore(srcName:string, callback: AsyncCallback&lt;void&gt;):void| 从指定的数据库备份文件恢复数据库，结果以callback形式返回。<br/>-&nbsp;srcName：指定数据库的备份文件名。<br/>-&nbsp;callback：指定callback回调函数。 |
| RdbStore |restore(srcName:string): Promise&lt;void&gt;| 从指定的数据库备份文件恢复数据库，结果以promise形式返回。<br/>-&nbsp;srcName：指定数据库的备份文件名。 |

## 开发步骤

1. 创建数据库。
   1. 配置数据库相关信息，包括数据库的名称、存储模式、是否为只读模式等。
   2. 初始化数据库表结构和相关数据。
   3. 创建数据库。

   示例代码如下：

   ```js
   import data_rdb from '@ohos.data.rdb'
   
   const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
   const STORE_CONFIG = {name: "rdbstore.db",}
   data_rdb.getRdbStore(STORE_CONFIG, 1, function (err, rdbStore) {
       rdbStore.executeSql(SQL_CREATE_TABLE)
       console.info('create table done.')
   })
   ```

2. 插入数据。
   1. 构造要插入的数据，以ValuesBucket形式存储。
   2. 调用关系型数据库提供的插入接口。

   示例代码如下：

   ```js
   var u8 = new Uint8Array([1, 2, 3])
   const valueBucket = {"name": "Tom", "age": 18, "salary": 100.5, "blobType": u8,}
   let insertPromise = rdbStore.insert("test", valueBucket)
   ```

3. 查询数据。
   1. 构造用于查询的谓词对象，设置查询条件。
   2. 调用查询接口查询数据。
   3. 调用结果集接口，返回查询结果。

   示例代码如下：

   ```js
   let predicates = new data_rdb.RdbPredicates("test");
   predicates.equalTo("name", "Tom")
   let promisequery = rdbStore.query(predicates)
       promisequery.then((resultSet) => {
       resultSet.goToFirstRow()
       const id = resultSet.getLong(resultSet.getColumnIndex("id"))
       const name = resultSet.getString(resultSet.getColumnIndex("name"))
       const age = resultSet.getLong(resultSet.getColumnIndex("age"))
       const salary = resultSet.getDouble(resultSet.getColumnIndex("salary"))
       const blobType = resultSet.getBlob(resultSet.getColumnIndex("blobType"))
       resultSet.close()
   })
   ```

4. 设置分布式同步表。
   
    1.权限配置文件中增加以下配置：
    ```js
    "requestPermissions": 
        {
            "name": "ohos.permission.DISTRIBUTED_DATASYNC"
        }
    ```
    2. 获取应用权限。
    3. 数据库调用接口设置分布式同步列表。
    4. 判断是否设置成功。

   示例代码如下：

    ```js
    let context = featureAbility.getContext();
    context.requestPermissionsFromUser(['ohos.permission.DISTRIBUTED_DATASYNC'], 666, function (result) {
        console.info(`result.requestCode=${result.requestCode}`)
    })
    let promise = rdbStore.setDistributedTables(["test"])
    promise.then(() => {
        console.info("setDistributedTables success.")
    }).catch((err) => {
        console.info("setDistributedTables failed.")
    })
    ```

5. 分布式数据同步。
    1. 构造用于同步分布式表的谓词对象，指定组网内的远程设备。
    2. 调用同步数据的接口 。
    3. 判断数据同步是否成功。

    示例代码如下：

    ```js
    let predicate = new data_rdb.RdbPredicates('test')
    predicate.inDevices(['12345678abcde'])
    let promise = rdbStore.sync(rdb.SyncMode.SYNC_MODE_PUSH, predicate)
    promise.then((result) => {
        console.log('sync done.')
        for (let i = 0; i < result.length; i++) {
            console.log('device=' + result[i][0] + ' status=' + result[i][1])
        }
    }).catch((err) => {
        console.log('sync failed')
    })
    ```

6. 分布式数据订阅。
    1. 调用分布式数据订阅接口，注册数据库的观察者。
    2. 当分布式数据库中的数据发生更改时，将调用回调。

    示例代码如下：

    ```js
    function storeObserver(devices) {
        for (let i = 0; i < devices.length; i++) {
            console.log('device=' + device[i] + ' data changed')
        }
    }
    try {
        rdbStore.on('dataChange', rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
    } catch (err) {
        console.log('register observer failed')
    }
    ```

7. 跨设备查询。
    1. 根据本地表名获取指定远程设备的分布式表名。
    2. 调用结果集接口，返回查询结果。

    示例代码如下：

    ```js
    let tableName = rdbStore.obtainDistributedTableName(deviceId, "test");
    let resultSet = rdbStore.querySql("SELECT * FROM " + tableName)
    ```
## 相关实例
针对关系型数据库开发，有以下相关实例可供参考：
- [`Rdb`：关系型数据库（eTS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/data/Rdb)
- [`DistributedRdb`：分布式关系型数据库（eTS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/data/DistributedRdb)
- [关系型数据库](https://gitee.com/openharmony/codelabs/tree/master/Data/JSRelationshipData)
