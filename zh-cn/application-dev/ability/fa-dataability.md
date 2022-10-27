# DataAbility开发指导

## 场景介绍

基于Data模板的Ability（以下简称“Data”），有助于应用管理其自身和其他应用存储数据的访问，并提供与其他应用共享数据的方法。Data既可用于同设备不同应用的数据共享，也支持跨设备不同应用的数据共享。

Data提供方可以自定义数据的增、删、改、查，以及文件打开等功能，并对外提供这些接口。

## URI介绍

Data的提供方和使用方都通过URI（Uniform Resource Identifier）来标识一个具体的数据，例如数据库中的某个表或磁盘上的某个文件。OpenHarmony的URI仍基于URI通用标准，格式如下：

![fa-dataability-uri](figures/fa-dataability-uri.png)

- scheme：协议方案名，固定为“dataability”，代表Data Ability所使用的协议类型。
- authority：设备ID。如果为跨设备场景，则为目标设备的ID；如果为本地设备场景，则不需要填写。
- path：资源的路径信息，代表特定资源的位置信息。
- query：查询参数。
- fragment：可以用于指示要访问的子资源。

URI示例：

- 跨设备场景：dataability://*device_id*/*com.domainname.dataability.persondata*/*person*/*10*
- 本地设备：dataability:///*com.domainname.dataability.persondata*/*person*/*10*

> 说明
> 
> 本地设备的“device_id”字段为空，因此在“dataability:”后面有三个“/”。

## 接口说明

**表1** Data中相关生命周期API功能介绍
|接口名|描述|
|:------|:------|
|onInitialized(info: AbilityInfo): void|在Ability初始化调用，通过此回调方法执行RDB等初始化操作。|
|update(uri: string, valueBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void|更新数据库中的数据。|
|query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void|查询数据库中的数据。|
|delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void|删除一条或多条数据。|
|normalizeUri(uri: string, callback: AsyncCallback\<string>): void|对URI进行规范化。一个规范化的URI可以支持跨设备使用、持久化、备份和还原等，当上下文改变时仍然可以引用到相同的数据项。|
|batchInsert(uri: string, valueBuckets: Array\<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void|向数据库中插入多条数据。|
|denormalizeUri(uri: string, callback: AsyncCallback\<string>): void|将一个由normalizeUri生产的规范化URI转换成非规范化的URI。|
|insert(uri: string, valueBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void|向数据中插入一条数据。|
|openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void|打开一个文件。|
|getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback\<Array\<string>>): void|获取文件的MIME类型。|
|getType(uri: string, callback: AsyncCallback\<string>): void|获取URI指定数据相匹配的MIME类型。|
|executeBatch(ops: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void|批量操作数据库中的数据。|
|call(method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void|自定义方法。|


## 开发步骤
### 创建Data

1. 实现Data中Insert、Query、Update、Delete接口的业务内容。保证能够满足数据库存储业务的基本需求。BatchInsert与ExecuteBatch接口已经在系统中实现遍历逻辑，依赖Insert、Query、Update、Delete接口逻辑，来实现数据的批量处理。

    创建Data的代码示例如下：

   ```javascript
    import featureAbility from '@ohos.ability.featureAbility'
    import dataAbility from '@ohos.data.dataAbility'
    import dataRdb from '@ohos.data.rdb'

    const TABLE_NAME = 'book'
    const STORE_CONFIG = { name: 'book.db' }
    const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS book(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, introduction TEXT NOT NULL)'
    let rdbStore: dataRdb.RdbStore = undefined

    export default {
    onInitialized(abilityInfo) {
        console.info('DataAbility onInitialized, abilityInfo:' + abilityInfo.bundleName)
        let context = featureAbility.getContext()
        dataRdb.getRdbStore(context, STORE_CONFIG, 1, (err, store) => {
            console.info('DataAbility getRdbStore callback')
            store.executeSql(SQL_CREATE_TABLE, [])
            rdbStore = store
        });
    },
    insert(uri, valueBucket, callback) {
        console.info('DataAbility insert start')
        rdbStore.insert(TABLE_NAME, valueBucket, callback)
    },
    batchInsert(uri, valueBuckets, callback) {
        console.info('DataAbility batch insert start')
        for (let i = 0;i < valueBuckets.length; i++) {
            console.info('DataAbility batch insert i=' + i)
            if (i < valueBuckets.length - 1) {
                rdbStore.insert(TABLE_NAME, valueBuckets[i], (err: any, num: number) => {
                    console.info('DataAbility batch insert ret=' + num)
                })
            } else {
                rdbStore.insert(TABLE_NAME, valueBuckets[i], callback)
            }
        }
    },
    query(uri, columns, predicates, callback) {
        console.info('DataAbility query start')
        let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates)
        rdbStore.query(rdbPredicates, columns, callback)
    },
    update(uri, valueBucket, predicates, callback) {
        console.info('DataAbilityupdate start')
        let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates)
        rdbStore.update(valueBucket, rdbPredicates, callback)
    },
    delete(uri, predicates, callback) {
        console.info('DataAbilitydelete start')
        let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates)
        rdbStore.delete(rdbPredicates, callback)
    }
    };
   ```

2. 子模块配置

   | Json重要字段 | 备注说明                                                     |
   | ------------ | ------------------------------------------------------------ |
   | "name"       | Ability名称，对应Ability派生的Data类名。                     |
   | "type"       | Ability类型，Data对应的Ability类型为”data“。                 |
   | "uri"        | 通信使用的URI。                                              |
   | "visible"    | 对其他应用是否可见，设置为true时，Data才能与其他应用进行通信传输数据。 |

   **config.json配置样例**

   ```json
   "abilities":[{
       "srcPath": "DataAbility",
       "name": ".DataAbility",
       "icon": "$media:icon",
       "srcLanguage": "ets",
       "description": "$string:description_dataability",
       "type": "data",
       "visible": true,
       "uri": "dataability://ohos.samples.etsdataability.DataAbility"
    }]
   ```

### 访问Data
#### 开发前准备

需导入基础依赖包，以及获取与Data子模块通信的URI字符串。

其中，基础依赖包包括：
- @ohos.ability.featureAbility
- @ohos.data.dataAbility
- @ohos.data.rdb

#### DataAbility接口开发指导


1. 创建工具接口类对象。

   工具接口类对象DataAbilityHelper相关接口可参考[DataAbilityHelper模块](../reference/apis/js-apis-dataAbilityHelper.md)。
   ```js
   // 作为参数传递的URI,与config中定义的URI的区别是多了一个"/",是因为作为参数传递的URI中,在第二个与第三个"/"中间,存在一个DeviceID的参数
   import featureAbility from '@ohos.ability.featureAbility'
   import ohos_data_ability from '@ohos.data.dataAbility'
   import ohos_data_rdb from '@ohos.data.rdb'

   var urivar = "dataability:///com.ix.DataAbility"
   var DAHelper = featureAbility.acquireDataAbilityHelper(
    urivar
   );
   ```
2. 构建数据库相关的RDB数据。
   ```js
   var valuesBucket = {"name": "gaolu"}
   var da = new ohos_data_ability.DataAbilityPredicates()
   var valArray =new Array("value1");
   var cars = new Array({"batchInsert1" : "value1",});
   ```
3. 调用insert方法向指定的Data子模块插入数据。
   ```js
   // callback方式调用:
   DAHelper.insert(
    urivar,
    valuesBucket,
    (error, data) => {
        console.log("DAHelper insert result: " + data)
    }
   );
   ```
   
   ```js
   // promise方式调用:
   var datainsert = await DAHelper.insert(
    urivar,
    valuesBucket
   );
   ```
4. 调用delete方法删除Data子模块中指定的数据。
   ```js
   // callback方式调用:
   DAHelper.delete(
    urivar,
    da,
    (error, data) => {
        console.log("DAHelper delete result: " + data)
    }
   );
   ```
   
   ```js
   // promise方式调用:
   var datadelete = await DAHelper.delete(
    urivar,
    da,
   );
   ```
5. 调用update方法更新指定Data子模块中的数据。
   ```js
   // callback方式调用:
   DAHelper.update(
    urivar
    valuesBucket,
    da,
    (error, data) => {
        console.log("DAHelper update result: " + data)
    }
   );
   ```
   
   ```js
   // promise方式调用:
   var dataupdate = await DAHelper.update(
    urivar,
    valuesBucket,
    da,
   );
   ```
6. 调用query方法在指定的Data子模块中查找数据。
   ```js
   // callback方式调用:
   DAHelper.query(
    urivar,
    valArray,
    da,
    (error, data) => {
        console.log("DAHelper query result: " + data)
    }
   );
   ```
   
   ```js
   // promise方式调用:
   var dataquery = await DAHelper.query(
    urivar,
    valArray,
    da
   );
   ```
7. 调用batchInsert方法向指定的数据子模块批量插入数据。
   ```js
   // callback方式调用:
   DAHelper.batchInsert(
    urivar,
    cars,
    (error, data) => {
        console.log("DAHelper batchInsert result: " + data)
    }
   );
   ```
   
   ```js
   // promise方式调用:
   var databatchInsert = await DAHelper.batchInsert(
    urivar,
    cars
   );
   ```
8. 调用executeBatch方法向指定的Data子模块进行数据的批量处理。
   ```js
   // callback方式调用:
   DAHelper.executeBatch(
    urivar,
    [
        {
            uri: urivar,
            type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
            valuesBucket: {"executeBatch" : "value1",},
            predicates: da,
            expectedCount:0,
            predicatesBackReferences: null,
            interrupted:true,
        }
    ],
    (error, data) => {
        console.log("DAHelper executeBatch result: " + data)
    }
   );
   ```
   
   ```js
   // promise方式调用:
   var dataexecuteBatch = await DAHelper.executeBatch(
    urivar,
    [
        {
            uri: urivar,
            type: featureAbility.DataAbilityOperationType.TYPE_INSERT,
            valuesBucket:
            {
                "executeBatch" : "value1",
            },
            predicates: da,
            expectedCount:0,
            predicatesBackReferences: null,
            interrupted:true,
        }
    ]
   );
   ```

## 相关实例

针对DataAbility开发，有以下相关实例可供参考：

- [`DataAbility`：DataAbility的创建与访问（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/DataAbility)
