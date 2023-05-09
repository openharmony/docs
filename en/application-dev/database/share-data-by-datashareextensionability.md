# Sharing Data Using DataShareExtensionAbility


## When to Use

If complex services are involved in cross-application data access, you can use **DataShareExtensionAbility** to start the application of the data provider to implement data access.

You need to implement flexible service logics via callbacks of the service provider.


## Working Principles

There are two roles in **DataShare**:

- Data provider: implements operations, such as adding, deleting, modifying, and querying data, and opening a file, using [DataShareExtensionAbility](../reference/apis/js-apis-application-dataShareExtensionAbility.md).

- Data consumer: accesses the data provided by the provider using [createDataShareHelper()](../reference/apis/js-apis-data-dataShare.md#datasharecreatedatasharehelper).

**Figure 1** Data sharing mechanism
 
![dataShare](figures/dataShare.jpg)

- The **DataShareExtensionAbility** module, as the data provider, implements services related to data sharing between applications.

- The **DataShareHelper** module, as the data consumer, provides APIs for accessing data, including adding, deleting, modifying, and querying data.

- The data consumer communicates with the data provider via inter-process communication (IPC). The data provider can be implemented through a database or other data storage.

- The **ResultSet** module is implemented through shared memory. Shared memory stores the result sets, and interfaces are provided to traverse result sets.


## How to Develop


### Data Provider Application Development (Only for System Applications)

[DataShareExtensionAbility](../reference/apis/js-apis-application-dataShareExtensionAbility.md) provides the following APIs. You can override these APIs as required.

- **onCreate**: called by the server to initialize service logic when the DataShare client connects to the DataShareExtensionAbility server.

- **insert**: called to insert data upon the request of the client. Data insertion must be implemented in this callback on the server.

- **update**: called to update data upon the request of the client. Data update must be implemented in this callback on the server.

- **delete**: called to delete data upon the request of the client. Data deletion must be implemented in this callback on the server.

- **query**: called to query data upon the request of the client. Data query must be implemented in this callback on the server.

- **batchInsert**: called to batch insert data upon the request of the client. Batch data insertion must be implemented in this callback on the server.

- **normalizeUri**: converts the URI provided by the client to the URI used by the server.

- **denormalizeUri**: converts the URI used by the server to the initial URI passed by the client.

Before implementing a **DataShare** service, you need to create a **DataShareExtensionAbility** object in the DevEco Studio project as follows:

1. In the **ets** directory of the **Module** project, right-click and choose **New > Directory** to create a directory named **DataShareExtAbility**.

2. Right-click the **DataShareAbility** directory, and choose **New > TypeScript File** to create a file named **DataShareExtAbility.ts**.

3. Import **@ohos.application.DataShareExtensionAbility** and other dependencies to the **DataShareExtAbility.ts** file, and 
override the service implementation as required. For example, if the data provider provides only the data insertion, deletion, and query services, you can override only these APIs.
   
   ```js
   import Extension from '@ohos.application.DataShareExtensionAbility';
   import rdb from '@ohos.data.relationalStore';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```

4. Implement the data provider services. For example, implement data storage of the data provider by using a database, reading and writing files, or accessing the network.
   
   ```js
   const DB_NAME = 'DB00.db';
   const TBL_NAME = 'TBL00';
   const DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
   + TBL_NAME
   + ' (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, isStudent BOOLEAN, Binary BINARY)';
   
   let rdbStore;
   let result;
   
   export default class DataShareExtAbility extends Extension {
     private rdbStore_;
   
     // Override onCreate().
     onCreate(want, callback) {
       result = this.context.cacheDir + '/datashare.txt';
       // Create an RDB store.
       rdb.getRdbStore(this.context, {
         name: DB_NAME,
         securityLevel: rdb.SecurityLevel.S1
       }, function (err, data) {
         rdbStore = data;
         rdbStore.executeSql(DDL_TBL_CREATE, [], (err) => {
           console.info(`DataShareExtAbility onCreate, executeSql done err:${err}`);
         });
         if (callback) {
           callback();
         }
       });
     }
   
     // Override query().
     query(uri, predicates, columns, callback) {
       if (predicates === null || predicates === undefined) {
         console.info('invalid predicates');
       }
       try {
         rdbStore.query(TBL_NAME, predicates, columns, (err, resultSet) => {
           if (resultSet !== undefined) {
             console.info(`resultSet.rowCount:${resultSet.rowCount}`);
           }
           if (callback !== undefined) {
             callback(err, resultSet);
           }
         });
       } catch (err) {
         console.error(`Failed to query. Code:${err.code},message:${err.message}`);
       }
     }
     // Override other APIs as required.
   };
   ```

5. Define **DataShareExtensionAbility** in **module.json5**.

     **Table 1** Fields in module.json5
   
   | Field| Description| Mandatory|
   | -------- | -------- | -------- |
   | name | Ability name, corresponding to the **ExtensionAbility** class name derived from **Ability**.| Yes|
   | type | Ability type. The value is **dataShare**, indicating the development is based on the **datashare** template.| Yes|
   | uri | URI used for communication. It is the unique identifier for the data consumer to connect to the provider.| Yes|
   | exported | Whether it is visible to other applications. Data sharing is allowed only when the value is **true**.| Yes|
   | readPermission | Permission required for accessing data. If this parameter is not set, the read permission is not verified by default.| No|
   | writePermission | Permission required for modifying data. If this parameter is not set, write permission verification is not performed by default.| No|

   **module.json5 example**

   
   ```json
   "extensionAbilities": [
     {
       "srcEntrance": "./ets/DataShareExtAbility/DataShareExtAbility.ts",
       "name": "DataShareExtAbility",
       "icon": "$media:icon",
       "description": "$string:description_datashareextability",
       "type": "dataShare",
       "uri": "datashare://com.samples.datasharetest.DataShare",
       "exported": true
     }
   ]
   ```


### Data Consumer Application Development

1. Import the dependencies.
   
   ```js
   import UIAbility from '@ohos.app.ability.UIAbility';
   import dataShare from '@ohos.data.dataShare';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```

2. Define the URI string for communicating with the data provider.
   
   ```js
   // Different from the URI defined in the module.json5 file, the URI passed in the parameter has an extra slash (/), because there is a DeviceID parameter between the second and the third slash (/).
   let dseUri = ('datashare:///com.samples.datasharetest.DataShare');
   ```

3. Create a **DataShareHelper** instance.
   
   ```js
   let dsHelper;
   let abilityContext;
   
   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage) {
       abilityContext = this.context;
       dataShare.createDataShareHelper(abilityContext, dseUri, (err, data) => {
         dsHelper = data;
       });
     }
   }
   ```

4. Use the APIs provided by **DataShareHelper** to access the services provided by the provider, for example, adding, deleting, modifying, and querying data.
   
   ```js
   // Construct a piece of data.
   let valuesBucket = { 'name': 'ZhangSan', 'age': 21, 'isStudent': false, 'Binary': new Uint8Array([1, 2, 3]) };
   let updateBucket = { 'name': 'LiSi', 'age': 18, 'isStudent': true, 'Binary': new Uint8Array([1, 2, 3]) };
   let predicates = new dataSharePredicates.DataSharePredicates();
   let valArray = ['*'];
   // Insert a piece of data.
   dsHelper.insert(dseUri, valuesBucket, (err, data) => {
     console.info(`dsHelper insert result:${data}`);
   });
   // Update data.
   dsHelper.update(dseUri, predicates, updateBucket, (err, data) => {
     console.info(`dsHelper update result:${data}`);
   });
   // Query data.
   dsHelper.query(dseUri, predicates, valArray, (err, data) => {
     console.info(`dsHelper query result:${data}`);
   });
   // Delete data.
   dsHelper.delete(dseUri, predicates, (err, data) => {
     console.info(`dsHelper delete result:${data}`);
   });
   ```
