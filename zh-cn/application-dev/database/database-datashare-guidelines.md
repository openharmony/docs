# 数据共享开发指导
DataShare即数据共享模块，提供了向其他应用共享以及管理其数据的方法。目前仅支持同个设备上应用之间的数据共享。

## 接口说明

**表1** 数据提供方API说明

|接口名|描述|
|:------|:------|
|onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void|DataShareExtensionAbility生命周期回调，在数据提供方应用创建时回调，执行初始化业务逻辑操作，如创建数据库。|
|insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方向数据库中插入数据时回调。|
|update?(uri: string, predicates: DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方更新数据时回调。|
|query?(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void|业务函数，在访问方查询数据时回调。|
|delete?(uri: string, predicates: DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void|业务函数，在访问方删除数据时回调。|

完整的数据提供方接口请见[DataShareExtensionAbility](../reference/apis/js-apis-application-dataShareExtensionAbility.md)。

**表2** 数据访问方API说明

| 接口名                                                       | 描述                               |
| :----------------------------------------------------------- | :--------------------------------- |
| createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void | 创建DataShare工具类。              |
| insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | 将单条数据记录插入数据库。         |
| update(uri: string, predicates: DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | 更新数据库中的数据记录。           |
| query(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void | 查询数据库中的数据。               |
| delete(uri: string, predicates: DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void | 从数据库中删除一条或多条数据记录。 |

完整的数据访问方接口请见[DataShareHelper](../reference/apis/js-apis-data-dataShare.md)。

## 开发场景

数据共享可分为数据的提供方和访问方两部分。

- 提供方可以选择性实现数据的增、删、改、查，以及文件打开等功能，并对外共享这些数据。
- 访问方利用工具类，便可以访问提供方提供的这些数据。

以下是数据提供方和数据访问方应用的各自开发示例。

### 数据提供方应用的开发（仅限系统应用）

1. 导入基础依赖包。

   ```ts
   import Extension from '@ohos.application.DataShareExtensionAbility';
   import rdb from '@ohos.data.rdb';
   import fileIo from '@ohos.fileio';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```

2. 数据提供方（也称服务端）继承于DataShareExtensionAbility，开发者可根据应用需求选择性重写其业务实现。例如数据提供方只提供查询服务，则可只重写查询接口。

3. 数据提供方的业务实现由开发者自定义。例如可以通过数据库、读写文件或访问网络等各方式实现数据提供方的数据存储。

   ```ts
   const DB_NAME = "DB00.db";
   const TBL_NAME = "TBL00";
   const DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
   + TBL_NAME
   + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, isStudent BOOLEAN, Binary BINARY)";
   
   let rdbStore;
   let result;
   
   export default class DataShareExtAbility extends Extension {
       private rdbStore_;
       
   	// 重写onCreate接口
       onCreate(want, callback) {
           result = this.context.cacheDir + '/datashare.txt'
           // 业务实现使用RDB
           rdb.getRdbStore(this.context, {
               name: DB_NAME
           }, 1, function (err, data) {
               rdbStore = data;
               rdbStore.executeSql(DDL_TBL_CREATE, [], function (err) {
                   console.log('DataShareExtAbility onCreate, executeSql done err:' + JSON.stringify(err));
               });
               callback();
           });
       }
   
   	// 重写query接口
       query(uri, predicates, columns, callback) {
           if (predicates == null || predicates == undefined) {
               console.info('invalid predicates');
           }
           try {
               rdbStore.query(TBL_NAME, predicates, columns, function (err, resultSet) {
                   if (resultSet != undefined) {
                       console.info('resultSet.rowCount: ' + resultSet.rowCount);
                   }
                   if (callback != undefined) {
                       callback(err, resultSet);
                   }
               });
           } catch (err) {
               console.error('error' + err);
           }
       }
       // 可根据应用需求，选择性重写各个接口
       // ...
   };
   ```

4. 在module.json5中定义DataShareExtensionAbility。

   | Json重要字段 | 备注说明                                                     |
   | ------------ | ------------------------------------------------------------ |
   | "name"       | Ability名称，对应Ability派生的ExtensionAbility类名。         |
   | "type"       | Ability类型，DataShare对应的Ability类型为”dataShare“，表示基于datashare模板开发的。 |
   | "uri"        | 通信使用的URI，是客户端链接服务端的唯一标识。                |
   | "visible"    | 对其他应用是否可见，设置为true时，才能与其他应用进行通信传输数据。 |

   **module.json5配置样例**

   ```json
   "extensionAbilities": [
     {
       "srcEntrance": "./ets/DataShareExtAbility/DataShareExtAbility.ts",
       "name": "DataShareExtAbility",
       "icon": "$media:icon",
       "description": "$string:description_datashareextability",
       "type": "dataShare",
       "uri": "datashare://com.samples.datasharetest.DataShare",
       "visible": true
     }
   ]
   ```

### 数据访问方应用的开发

1. 导入基础依赖包。

   ```ts
   import Ability from '@ohos.application.Ability';
   import dataShare from '@ohos.data.dataShare';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```
   
2. 定义与数据提供方通信的URI字符串。

   ```ts
   // 作为参数传递的URI，与module.json5中定义的URI的区别是多了一个"/"，是因为作为参数传递的URI中，在第二个与第三个"/"中间，存在一个DeviceID的参数
   let dseUri = ("datashare:///com.samples.datasharetest.DataShare");
   ```
   
3. 创建工具接口类对象。

   ```ts
   let dsHelper;
   let abilityContext;
   
   export default class MainAbility extends Ability {
   	onWindowStageCreate(windowStage) {
   		abilityContext = this.context;
   		dataShare.createDataShareHelper(abilityContext, dseUri, (err, data)=>{
   			dsHelper = data;
   		});
   	}
   }
   ```
   
4. 获取到接口类对象后，便可利用其提供的接口访问提供方提供的服务，如进行数据的增删改查等。

   ```ts
   // 构建一条数据
   let valuesBucket = { "name": "ZhangSan", "age": 21, "isStudent": false, "Binary": new Uint8Array([1, 2, 3]) };
   let updateBucket = { "name": "LiSi", "age": 18, "isStudent": true, "Binary": new Uint8Array([1, 2, 3]) };
   let predicates = new dataSharePredicates.DataSharePredicates();
   let valArray = new Array("*");
   // 插入一条数据
   dsHelper.insert(dseUri, valuesBucket, (err, data) => {
     console.log("dsHelper insert result: " + data);
   });
   // 更新数据
   dsHelper.update(dseUri, predicates, updateBucket, (err, data) => {
     console.log("dsHelper update result: " + data);
   });
   // 查询数据
   dsHelper.query(dseUri, predicates, valArray, (err, data) => {
     console.log("dsHelper query result: " + data);
   });
   // 删除指定的数据
   dsHelper.delete(dseUri, predicates, (err, data) => {
     console.log("dsHelper delete result: " + data);   
   });
   ```
   
