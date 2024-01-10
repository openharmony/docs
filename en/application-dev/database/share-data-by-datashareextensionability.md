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


### Data Provider Application (Only for System Applications)

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

3. Import **@ohos.application.DataShareExtensionAbility** and other dependencies to the **DataShareExtAbility.ts** file, and override the service implementation as required. For example, if the data provider provides only the data insertion, deletion, and query services, you can override only these APIs.

   ```ts
   import Extension from '@ohos.application.DataShareExtensionAbility';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   import relationalStore from '@ohos.data.relationalStore';
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base'
   ```

4. Implement the data provider services. For example, implement data storage of the data provider by using a database, reading and writing files, or accessing the network.

   ```ts
   const DB_NAME = 'DB00.db';
   const TBL_NAME = 'TBL00';
   const DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
     + TBL_NAME
     + ' (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, isStudent BOOLEAN, Binary BINARY)';

   let rdbStore: relationalStore.RdbStore;
   let result: string;

   export default class DataShareExtAbility extends Extension {
     // Override onCreate().
     onCreate(want: Want, callback: Function) {
       result = this.context.cacheDir + '/datashare.txt';
       // Create an RDB store.
       relationalStore.getRdbStore(this.context, {
         name: DB_NAME,
         securityLevel: relationalStore.SecurityLevel.S1
       }, (err, data) => {
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
     query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array<string>, callback: Function) {
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
         let code = (err as BusinessError).code;
         let message = (err as BusinessError).message
         console.error(`Failed to query. Code:${code},message:${message}`);
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
   | metadata   | Configuration for silent access, including the **name** and **resource** fields.<br>The **name** field identifies the configuration, which has a fixed value of **ohos.extension.dataShare**.<br>The **resource** field has a fixed value of **$profile:data_share_config**, which indicates that the profile name is **data_share_config.json**. | **metadata** is mandatory when the ability launch type is **singleton**. For details about the ability launch type, see **launchType** in the [Internal Structure of the abilities Attribute](../quick-start/module-structure.md#internal-structure-of-the-abilities-attribute).|

   **module.json5 example**

   ```json
   "extensionAbilities": [
     {
       "srcEntry": "./ets/DataShareExtAbility/DataShareExtAbility.ts",
       "name": "DataShareExtAbility",
       "icon": "$media:icon",
       "description": "$string:description_datashareextability",
       "type": "dataShare",
       "uri": "datashare://com.samples.datasharetest.DataShare",
       "exported": true,
       "metadata": [{"name": "ohos.extension.dataShare", "resource": "$profile:data_share_config"}]
     }
   ]
   ```

   **Table 2** Fields in the data_share_config.json file

   | Field         | Description                                    | Mandatory  |
   | ------------- | ---------------------------------------- | ---- |
   | tableConfig   | Label configuration.                                   | Yes   |
   | uri           | Range for which the configuration takes effect. The URI supports the following formats in descending order by priority:<br>- *****: indicates all databases and tables.<br>- **datashare:///{bundleName}/{moduleName}/{storeName}**: specifies a database.<br>- **datashare:///{bundleName}/{moduleName}/{storeName}/{tableName}**: specifies a table.<br>If URIs of different formats are configured, only the URI with higher priority takes effect. | Yes   |
   | crossUserMode | Whether data is shared by multiple users.<br>The value **1** means to share data between multiple users, and the value **2** means the opposite. | Yes   |

   **data_share_config.json Example**

   ```json
   "tableConfig": [
    {
      "uri": "*",
      "crossUserMode": 1
    },
    {
      "uri": "datashare:///com.acts.datasharetest/entry/DB00",
      "crossUserMode": 1
    },
    {
      "uri": "datashare:///com.acts.datasharetest/entry/DB00/TBL00",
      "crossUserMode": 2
    }
   ]
   ```


### Data Consumer Application

1. Import the dependencies.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import dataShare from '@ohos.data.dataShare';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   import { ValuesBucket } from '@ohos.data.ValuesBucket'
   import window from '@ohos.window';
   ```

2. Define the URI string for communicating with the data provider.

   ```ts
   // Different from the URI defined in the module.json5 file, the URI passed in the parameter has an extra slash (/), because there is a DeviceID parameter between the second and the third slash (/).
   let dseUri = ('datashare:///com.samples.datasharetest.DataShare');
   ```

3. Create a **DataShareHelper** instance.

   ```ts
   let dsHelper: dataShare.DataShareHelper | undefined = undefined;
   let abilityContext: Context;

   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       abilityContext = this.context;
       dataShare.createDataShareHelper(abilityContext, dseUri, (err, data) => {
         dsHelper = data;
       });
     }
   }
   ```

4. Use the APIs provided by **DataShareHelper** to access the services provided by the provider, for example, adding, deleting, modifying, and querying data.

   ```ts
   // Construct a piece of data.
   let key1 = 'name';
   let key2 = 'age';
   let key3 = 'isStudent';
   let key4 = 'Binary';
   let valueName1 = 'ZhangSan';
   let valueName2 = 'LiSi';
   let valueAge1 = 21;
   let valueAge2 = 18;
   let valueIsStudent1 = false;
   let valueIsStudent2 = true;
   let valueBinary = new Uint8Array([1, 2, 3]);
   let valuesBucket: ValuesBucket = { key1: valueName1, key2: valueAge1, key3: valueIsStudent1, key4: valueBinary };
   let updateBucket: ValuesBucket = { key1: valueName2, key2: valueAge2, key3: valueIsStudent2, key4: valueBinary };
   let predicates = new dataSharePredicates.DataSharePredicates();
   let valArray = ['*'];
   if (dsHelper != undefined) {
     // Insert a piece of data.
     (dsHelper as dataShare.DataShareHelper).insert(dseUri, valuesBucket, (err, data) => {
       console.info(`dsHelper insert result:${data}`);
     });
     // Update data.
     (dsHelper as dataShare.DataShareHelper).update(dseUri, predicates, updateBucket, (err, data) => {
       console.info(`dsHelper update result:${data}`);
     });
     // Query data.
     (dsHelper as dataShare.DataShareHelper).query(dseUri, predicates, valArray, (err, data) => {
       console.info(`dsHelper query result:${data}`);
     });
     // Delete data.
     (dsHelper as dataShare.DataShareHelper).delete(dseUri, predicates, (err, data) => {
       console.info(`dsHelper delete result:${data}`);
     });
   }
   ```
