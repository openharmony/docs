# 关系型数据库开发指导

## 场景介绍

关系型数据库是在SQLite基础上实现的本地数据操作机制，提供给用户无需编写原生SQL语句就能进行数据增删改查的方法，同时也支持原生SQL语句操作。


## 接口说明

以下是关系型数据库的常用接口说明，大部分为异步接口。异步接口均有callback和Promise两种返回形式，下表均以Promise形式为例，更多接口及使用方式请见[关系型数据库](../reference/apis/js-apis-data-rdb.md)。

### 数据库的创建和删除

关系型数据库提供了数据库创建方式，以及对应的删除接口，涉及的API如下所示。

**表1** 数据库创建和删除API

| 接口名                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getRdbStoreV9(context: Context, config: StoreConfigV9, version: number): Promise&lt;RdbStoreV9&gt; | 获得一个相关的RdbStoreV9，操作关系型数据库，用户可以根据自己的需求配置RdbStoreV9的参数，然后通过RdbStoreV9调用相关接口可以执行相关的数据操作，使用Promise异步回调。<br/>-context：应用程序或功能的上下文。<br/>-config：与此RDB存储相关的数据库配置。<br/>-version：数据库版本。目前暂不支持通过version自动识别数据库升级降级操作，只能由开发者自行维护。 |
| deleteRdbStoreV9(context: Context, name: string): Promise&lt;void&gt; | 使用指定的数据库文件配置删除数据库，使用Promise异步回调。<br/>-context：应用程序或功能的上下文。<br/>-name：数据库名称。 |

### 数据库的增删改查

关系型数据库提供对本地数据增删改查操作的能力，相关API如下所示。

- **新增**
  
  关系型数据库提供了插入数据的接口，通过ValuesBucket输入要存储的数据，通过返回值判断是否插入成功，插入成功时返回最新插入数据所在的行号，失败时则返回-1。
  
  **表2** 数据库插入API
  

  | 类名       | 接口名                                                       | 描述                                                         |
  | ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStoreV9 | insert(table: string, values: ValuesBucket): Promise&lt;number&gt; | 向目标表中插入一行数据，使用Promise异步回调。<br>如果操作成功，返回行ID；否则返回-1。<br/>-table：指定的目标表名。<br/>-values：表示要插入到表中的数据行。 |
  
- **更新**
  
  调用更新接口，传入要更新的数据，并通过RdbPredicatesV9指定更新条件。该接口的返回值表示更新操作影响的行数。如果更新失败，则返回0。
  
  **表3** 数据库更新API
  

  | 类名       | 接口名                                                       | 描述                                                         |
  | ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | RdbStoreV9 | update(values: ValuesBucket, predicates: RdbPredicatesV9): Promise&lt;number&gt; | 根据RdbPredicatesV9的指定实例对象更新数据库中的数据，使用Promise异步回调。<br>返回受影响的行数。<br/>-values：以ValuesBucket存储的要更新的数据。<br/>-predicates：表示RdbPredicatesV9的实例对象指定的更新条件。 |
  
- **删除** 
  
  调用删除接口，通过RdbPredicatesV9指定删除条件。该接口的返回值表示删除的数据行数，可根据此值判断是否删除成功。如果删除失败，则返回0。
  
  **表4** 数据库删除API
  

  | 类名       | 接口名                                                     | 描述                                                         |
  | ---------- | ---------------------------------------------------------- | ------------------------------------------------------------ |
  | RdbStoreV9 | delete(predicates: RdbPredicatesV9): Promise&lt;number&gt; | 根据RdbPredicatesV9的指定实例对象从数据库中删除数据，使用Promise异步回调。<br>返回受影响的行数。 <br/>-predicates：RdbPredicatesV9的实例对象指定的删除条件。 |
  
- **查询** 

  关系型数据库提供了两种查询数据的方式：

  - 直接调用查询接口。使用该接口，会将包含查询条件的谓词自动拼接成完整的SQL语句进行查询操作，无需用户传入原生的SQL语句。
  - 执行原生的SQL语句进行查询操作。

  **表5** 数据库查询API


| 类名       | 接口名                                                       | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | query(predicates: RdbPredicatesV9, columns?: Array&lt;string&gt;): Promise&lt;ResultSetV9&gt; | 根据指定条件查询数据库中的数据，使用Promise异步回调。<br/>-predicates：表示RdbPredicatesV9的实例对象指定的查询条件。<br/>-columns：表示要查询的列。如果值为空，则查询应用于所有列。 |
| RdbStoreV9 | querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;): Promise&lt;ResultSetV9&gt; | 根据指定SQL语句查询数据库中的数据，使用Promise异步回调。<br/>-sql：指定要查询的SQL语句。<br/>-bindArgs：SQL语句中参数的值。 |
| RdbStoreV9 | remoteQuery(device: string, table: string, predicates: RdbPredicatesV9, columns: Array&lt;string&gt;): Promise&lt;ResultSetV9&gt; | 根据指定条件查询指定远程设备数据库中的数据。使用Promise异步回调。<br/>-device：指定远程查询的设备networkId。<br/>-table：指定远程查询的表名。<br/>-predicates：表示RdbPredicatesV9的实例对象，指定查询的条件。<br/>-columns：表示要查询的列。如果值为空，则查询应用于所有列。 |

### 数据库谓词的使用

关系型数据库提供了用于设置数据库操作条件的谓词RdbPredicatesV9，该类确定RDB中条件表达式的值是true还是false。

以下列举几个常用谓词，更多谓词的使用请见[关系型数据库谓词](../reference/apis/js-apis-data-rdb.md#rdbpredicates)。

**表6** 数据库谓词API

| 类名            | 接口名                                                       | 描述                                                         |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbPredicatesV9 | equalTo(field: string, value: ValueType): RdbPredicatesV9    | 配置谓词以匹配数据字段为ValueType且值等于指定值的字段。<br/>-field：数据库表中的列名。<br/>-value：指示要与谓词匹配的值。<br/>-RdbPredicatesV9：返回与指定字段匹配的谓词。 |
| RdbPredicatesV9 | notEqualTo(field: string, value: ValueType): RdbPredicatesV9 | 配置谓词以匹配数据字段为ValueType且值不等于指定值的字段。<br/>-field：数据库表中的列名。<br/>-value：指示要与谓词匹配的值。<br/>-RdbPredicatesV9：返回与指定字段匹配的谓词。 |
| RdbPredicatesV9 | or(): RdbPredicatesV9                                        | 将或条件添加到谓词中。<br/>-RdbPredicatesV9：返回带有或条件的谓词。 |
| RdbPredicatesV9 | and(): RdbPredicatesV9                                       | 向谓词添加和条件。<br/>-RdbPredicatesV9：返回带有和条件的谓词。 |
| RdbPredicatesV9 | contains(field: string, value: string): RdbPredicatesV9      | 配置谓词以匹配数据字段为String且value包含指定值的字段。<br/>-field：数据库表中的列名。<br/>-value：指示要与谓词匹配的值。<br/>-RdbPredicatesV9：返回带有包含条件的谓词。 |


### 查询结果集的使用

关系型数据库提供了查询返回的结果集ResultSetV9，其指向查询结果中的一行数据，供用户对查询结果进行遍历和访问。

更多结果集的接口使用，请见[结果集](../reference/apis/js-apis-data-resultset.md)。

> **须知：**
> **结果集使用完后，请一定要调用close方法显式关闭。**

**表7** 结果集API

| 类名        | 接口名                                   | 描述                                       |
| ----------- | ---------------------------------------- | ------------------------------------------ |
| ResultSetV9 | goToFirstRow(): boolean                  | 将结果集移动到第一行。                     |
| ResultSetV9 | getString(columnIndex: number): string   | 获取当前行指定列的值，以String类型返回。   |
| ResultSetV9 | getBlob(columnIndex: number): Uint8Array | 获取当前行指定列的值，以字节数组形式返回。 |
| ResultSetV9 | getDouble(columnIndex: number): number   | 获取当前行指定列的值，以double型返回。     |
| ResultSetV9 | getLong(columnIndex: number): number     | 获取当前行指定列的值，以Long形式返回。     |
| ResultSetV9 | close(): void                            | 关闭结果集。                               |



### 设置分布式列表

> **说明：**  
>
> - 在使用RdbStoreV9的setDistributedTables、obtainDistributedTableName、sync、on、off接口时，需要请求相应的权限：ohos.permission.DISTRIBUTED_DATASYNC。
> - 使用分布式列表前，需要先建立设备间组网，具体接口及使用可见[设备管理](../reference/apis/js-apis-device-manager.md)。

**设置分布式列表**

**表8** 设置分布式列表

| 类名       | 接口名                                                       | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | setDistributedTables(tables: Array\<string>): Promise\<void> | 设置分布式列表，使用Promise异步回调。<br/>-tables：要设置的分布式列表表名。 |

**根据本地表名获取指定远程设备的分布式表名**

用户根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名。

**表9** 根据本地表名获取指定远程设备的分布式表名

| 类名       | 接口名                                                       | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | obtainDistributedTableName(device: string, table: string): Promise\<string> | 根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名，使用Promise异步回调。<br/>-device：远程设备。<br/>-table：本地表名。 |

**在设备之间同步数据**

**表10** 在设备之间同步数据

| 类名       | 接口名                                                       | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | sync(mode: SyncMode, predicates: RdbPredicatesV9): Promise\<Array\<[string, number]>> | 在设备之间同步数据，使用Promise异步回调。<br/>-mode：指同步模式。SYNC_MODE_PUSH 表示数据从本地设备推送到远程设备；SYNC_MODE_PULL 表示数据从远程设备拉至本地设备。<br/>-predicates：约束同步数据和设备。<br>-string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |

**注册数据库的观察者**

**表11** 注册数据库的观察者

| 类名       | 接口名                                                       | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void | 注册数据库的观察者。当分布式数据库中的数据发生更改时，将调用回调。<br/>-type：订阅类型；SUBSCRIBE_TYPE_REMOTE 订阅远程数据更改。<br/>-observer：指分布式数据库中数据更改事件的观察者。 |

**从数据库中删除指定类型的指定观察者**

**表12** 从数据库中删除指定类型的指定观察者

| 类名       | 接口名                                                       | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| RdbStoreV9 | off(event:'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void; | 从数据库中删除指定类型的指定观察者，使用callback异步回调。<br/>-type：订阅类型；SUBSCRIBE_TYPE_REMOTE 订阅远程数据更改。<br/>-observer：指已注册的数据更改观察者。 |

### 数据库的备份和恢复

**备份**

**表13** 备份数据库

| 类名       | 接口名                                        | 描述                                                         |
| ---------- | --------------------------------------------- | ------------------------------------------------------------ |
| RdbStoreV9 | backup(destName: string): Promise&lt;void&gt; | 以指定名称备份数据库，使用Promise异步回调。<br/>-destName：指定数据库的备份文件名。 |

**恢复**

**表14** 恢复数据库

| 类名       | 接口名                                        | 描述                                                         |
| ---------- | --------------------------------------------- | ------------------------------------------------------------ |
| RdbStoreV9 | restore(srcName: string): Promise&lt;void&gt; | 从指定的数据库备份文件恢复数据库，使用Promise异步回调。<br/>-srcName：指定数据库的备份文件名。 |

**事务**

**表15** 事务

| 类名     | 接口名                  | 描述                              |
| -------- | ----------------------- | --------------------------------- |
| RdbStoreV9 | beginTransaction(): void | 在开始执行SQL语句之前，开始事务。 |
| RdbStoreV9 | commit(): void           | 提交已执行的SQL语句。             |
| RdbStoreV9 | rollBack(): void         | 回滚已经执行的SQL语句。           |

## 开发步骤

1. 创建数据库。

   (1) 配置数据库相关信息，包括数据库的名称、存储模式、是否为只读模式等。

   (2) 初始化数据库表结构和相关数据。

   (3) 创建数据库。

   FA模型示例：

    ```js
   import data_rdb from '@ohos.data.rdb'
    // 获取context
   import featureAbility from '@ohos.ability.featureAbility'
   let context = featureAbility.getContext()
   
   const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
   
   const STORE_CONFIGV9 = { name: "RdbTest.db",
                         securityLevel: data_rdb.SecurityLevel.S1}
   data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1, function (err, rdbStoreV9) {
      rdbStoreV9.executeSql(CREATE_TABLE_TEST)
      console.info('create table done.')
   })
    ```
    Stage模型示例：
     ```ts
   import data_rdb from '@ohos.data.rdb'
    // 获取context
   import Ability from '@ohos.application.Ability'
   let context = null
   class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
         context = this.context
       }
   }
   
   const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " + "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
   
   const STORE_CONFIGV9 = { name: "rdbstore.db",
                          securityLevel: data_rdb.SecurityLevel.S1}
   data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1, function (err, rdbStoreV9) {
       rdbStoreV9.executeSql(CREATE_TABLE_TEST)
       console.info('create table done.')
   })
     ```

2. 插入数据。

   (1) 构造要插入的数据，以ValuesBucket形式存储。

   (2) 调用关系型数据库提供的插入接口。

   示例代码如下：

    ```js
    var u8 = new Uint8Array([1, 2, 3])
    const valueBucket = { "name": "Tom", "age": 18, "salary": 100.5, "blobType": u8 }
    let insertPromise = rdbStoreV9.insert("test", valueBucket)
    ```

3. 查询数据。

   (1) 构造用于查询的谓词对象，设置查询条件。

   (2) 调用查询接口查询数据。

   (3) 调用结果集接口，返回查询结果。

   示例代码如下：

    ```js
    let predicatesV9 = new data_rdb.RdbPredicatesV9("test");
    predicatesV9.equalTo("name", "Tom")
    let promisequery = rdbStoreV9.query(predicatesV9)
    promisequery.then((resultSetV9) => {
        resultSetV9.goToFirstRow()
        const id = resultSetV9.getLong(resultSetV9.getColumnIndex("id"))
        const name = resultSetV9.getString(resultSetV9.getColumnIndex("name"))
        const age = resultSetV9.getLong(resultSetV9.getColumnIndex("age"))
        const salary = resultSetV9.getDouble(resultSetV9.getColumnIndex("salary"))
        const blobType = resultSetV9.getBlob(resultSetV9.getColumnIndex("blobType"))
        resultSetV9.close()
    })
    ```

4. 设置分布式同步表。

    (1) 权限配置文件中增加以下配置。    

    ```json
    "requestPermissions": 
      {
        "name": "ohos.permission.DISTRIBUTED_DATASYNC"
      }
    ```

    (2) 获取应用权限。

    (3) 数据库调用接口设置分布式同步列表。

    (4) 判断是否设置成功。

   示例代码如下：

    ```js
    let context = featureAbility.getContext();
    context.requestPermissionsFromUser(['ohos.permission.DISTRIBUTED_DATASYNC'], 666, function (result) {
        console.info(`result.requestCode=${result.requestCode}`)
    })
    let promise = rdbStoreV9.setDistributedTables(["test"])
    promise.then(() => {
        console.info("setDistributedTables success.")
    }).catch((err) => {
        console.info("setDistributedTables failed.")
    })
    ```

5. 分布式数据同步。

    (1) 构造用于同步分布式表的谓词对象，指定组网内的远程设备。

    (2) 调用同步数据的接口。

    (3) 判断数据同步是否成功。

    示例代码如下：

    ```js
    let predicateV9 = new data_rdb.RdbPredicatesV9('test')
    predicateV9.inDevices(['12345678abcde'])
    let promise = rdbStoreV9.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicateV9)
    promise.then((result) => {
        console.log('sync done.')
        for (let i = 0; i < result.length; i++) {
            console.log('device=' + result[i][0] + 'status=' + result[i][1])
        }
    }).catch((err) => {
        console.log('sync failed')
    })
    ```

6. 分布式数据订阅。
  
    (1) 调用分布式数据订阅接口，注册数据库的观察者。

    (2) 当分布式数据库中的数据发生更改时，将调用回调。

    示例代码如下：

    ```js
    function storeObserver(devices) {
        for (let i = 0; i < devices.length; i++) {
            console.log('device=' + device[i] + 'data changed')
        }
    }
  
    try {
        rdbStoreV9.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
    } catch (err) {
        console.log('register observer failed')
    }
    ```

7. 跨设备查询。
   
    (1) 根据本地表名获取指定远程设备的分布式表名。

    (2) 调用结果集接口，返回查询结果。

    示例代码如下：

    ```js
    let tableName = rdbStoreV9.obtainDistributedTableName(deviceId, "test");
    let resultSetV9 = rdbStoreV9.querySql("SELECT * FROM " + tableName)
    ```
    
8. 远程查询。
   
   
   (1) 构造用于查询分布式表的谓词对象，指定组网内的远程分布式表名和设备。
   
   (2) 调用结果集接口，返回查询结果。
   
   示例代码如下：
   
    ```js
    let rdbPredicateV9 = new data_rdb.RdbPredicatesV9('employee')
    predicatesV9.greaterThan("id", 0) 
    let promiseQuery = rdbStoreV9.remoteQuery('12345678abcde', 'employee', rdbPredicateV9)
    promiseQuery.then((resultSetV9) => {
        while (resultSetV9.goToNextRow()) {
            let idx = resultSetV9.getLong(0);
            let name = resultSetV9.getString(1);
            let age = resultSetV9.getLong(2);
            console.info(idx + " " + name + " " + age);
        }
        resultSetV9.close();
    }).catch((err) => {
        console.info("failed to remoteQuery, err: " + err)
    })
    ```
   
9. 数据库的备份和恢复。

   (1) 调用数据库的备份接口，备份当前数据库文件。

    示例代码如下：

    ```js
    let promiseBackup = rdbStoreV9.backup("dbBackup.db")
    promiseBackup.then(() => {
        console.info('Backup success.')
    }).catch((err) => {
        console.info('Backup failed, err: ' + err)
    })
    ```
   (2) 调用数据库的恢复接口，从数据库的备份文件恢复数据库文件。
   
    示例代码如下：

    ```js
    let promiseRestore = rdbStoreV9.restore("dbBackup.db")
    promiseRestore.then(() => {
        console.info('Restore success.')
    }).catch((err) => {
        console.info('Restore failed, err: ' + err)
    })
    ```

## 相关实例
针对关系型数据库开发，有以下相关实例可供参考：
- [`DistributedRdb`：分布式关系型数据库（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/data/DistributedRdb)
- [关系型数据库（JS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Data/JSRelationshipData)