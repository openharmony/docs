# DataShare Development
The **DataShare** module allows an application to manage its own data and share data with other applications. Currently, data can be shared only between applications on the same device.

## Available APIs

**Table 1** APIs of the data provider

|API|Description|
|:------|:------|
|onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void|Called to initialize service logic when the data provider application is created, for example, when a database is created.|
|insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void|Inserts data into the database.|
|update?(uri: string, predicates: DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void|Updates data in the database.|
|query?(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void|Queries data from the database.|
|delete?(uri: string, predicates: DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void|Deletes data from the database.|

For more information, see [DataShareExtensionAbility](../reference/apis/js-apis-application-DataShareExtensionAbility.md).

**Table 2** APIs of the data consumer

| API                                                      | Description                              |
| :----------------------------------------------------------- | :--------------------------------- |
| createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void | Creates a **DataShareHelper** instance.             |
| insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | Inserts a single data record into the database.        |
| update(uri: string, predicates: DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | Updates data in the database.          |
| query(uri: string, predicates: DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void | Queries data from the database.              |
| delete(uri: string, predicates: DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void | Deletes one or more data records from the database.|

For more information, see [DataShareHelper](../reference/apis/js-apis-data-dataShare.md).

## When to Use

There are two roles in **DataShare**:

- Data provider: adds, deletes, modifies, and queries data, opens files, and shares data.
- Data consumer: accesses the data provided by the provider using **DataShareHelper**.

Examples are given below.

### Data Provider Application Development (Only for System Applications)

1. Import the dependencies.

   ```ts
   import Extension from '@ohos.application.DataShareExtensionAbility';
   import rdb from '@ohos.data.rdb';
   import fileIo from '@ohos.fileio';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```

2. Override **DataShareExtensionAbility** APIs based on actual requirements. For example, if the data provider provides only data query, override only the **query()** API.

3. Implement the data provider services. For example, implement data storage of the data provider by using a database, reading and writing files, or accessing the network.

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
       
   	// Override the onCreate() API.
       onCreate(want, callback) {
           result = this.context.cacheDir + '/datashare.txt'
           // Create an RDB.
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
   
   	// Override the query() API.
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
       // Override other APIs as required.
       // ...
   };
   ```

4. Define **DataShareExtensionAbility** in **module.json5**.

   | Field| Description                                                    |
   | ------------ | ------------------------------------------------------------ |
   | "name"       | Ability name, corresponding to the **ExtensionAbility** class name derived from **Ability**.        |
   | "type"       | Ability type. The value is **dataShare**, indicating the development is based on the **datashare** template.|
   | "uri"        | URI used for communication. It is the unique identifier for the data consumer to connect to the provider.               |
   | "visible"    | Whether it is visible to other applications. Data sharing is allowed only when the value is **true**.|

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
       "visible": true
     }
   ]
   ```

### Data Consumer Application Development

1. Import the dependencies.

   ```ts
   import Ability from '@ohos.application.Ability';
   import dataShare from '@ohos.data.dataShare';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   ```
   
2. Define the URI string for communicating with the data provider.

   ```ts
   // Different from the URI defined in the module.json5 file, the URI passed in the parameter has an extra slash (/), because there is a DeviceID parameter between the second and the third slash (/).
   let dseUri = ("datashare:///com.samples.datasharetest.DataShare");
   ```
   
3. Create a **DataShareHelper** instance.

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
   
4. Use the APIs provided by **DataShareHelper** to access the services provided by the provider, for example, adding, deleting, modifying, and querying data.

   ```ts
   // Construct a piece of data.
   let valuesBucket = { "name": "ZhangSan", "age": 21, "isStudent": false, "Binary": new Uint8Array([1, 2, 3]) };
   let updateBucket = { "name": "LiSi", "age": 18, "isStudent": true, "Binary": new Uint8Array([1, 2, 3]) };
   let predicates = new dataSharePredicates.DataSharePredicates();
   let valArray = new Array("*");
   // Insert a piece of data.
   dsHelper.insert(dseUri, valuesBucket, (err, data) => {
     console.log("dsHelper insert result: " + data);
   });
   // Update data.
   dsHelper.update(dseUri, predicates, updateBucket, (err, data) => {
     console.log("dsHelper update result: " + data);
   });
   // Query data.
   dsHelper.query(dseUri, predicates, valArray, (err, data) => {
     console.log("dsHelper query result: " + data);
   });
   // Delete data.
   dsHelper.delete(dseUri, predicates, (err, data) => {
     console.log("dsHelper delete result: " + data);   
   });
   ```
   
