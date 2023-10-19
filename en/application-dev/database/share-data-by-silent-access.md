# Silent Access via the DatamgrService


## When to Use

In a typical cross-application data access scenario, the data provider may be started multiple times.

To reduce the number of startup times of the data provider and improve the access speed, OpenHarmony provides the silent access feature, which allows access to the database without starting the data provider.

In silent data access, the DatamgrService accesses and modifies data without starting the data provider.

The DatamgrService supports basic database access or data hosting only. If service processing is required, the service processing needs to be encapsulated into APIs for the data consumer to call.

If the service processing is too complex to be processed by the data consumer, use [DataShareExtensionAbility](../reference/apis/js-apis-application-dataShareExtensionAbility.md) to start the data provider.


## Working Principles

The DatamgrService can serve as a proxy to access the following types of data:

- Persistent data

  Persistent data belongs to the database of the data provider. It is stored in the sandbox of the data provider and can be shared in declaration mode by the data provider. Persistent data is configured as data tables for access.


- Process data 

  The process data managed by the **DatamgrService** is stored in the DatamgrService sandbox in JSON or byte format. This type of data is automatically deleted 10 days after no subscription.


| Type | Storage Location     | Data Format       | Validity Period         | Application Scenario                             |
| ----- | --------- | ----------- | ------------ | --------------------------------- |
| Persistent data| Sandbox of the data provider | Tables in the database   | Permanent storage        | RDB data applications, such as schedules and conferences.     |
| Process data | DatamgrService sandbox| JSON or byte| Automatically deleted 10 days after no subscription| Applications featuring simple and time-sensitive data, such as step count, weather, and heart rate.|



**Figure 1** Silent access

![silent_dataShare](figures/silent_dataShare.jpg)

- In silent access, **DatamgrService** obtains the access rules configured by the data provider through directory mapping, performs preprocessing based on rules, and accesses the database.

- To use silent access, the URIs must be in the following format:
  datashareproxy://{bundleName}/{dataPath}

  The **DatamgrService** obtains the data provider application based on **bundleName**, reads the configuration, verifies the permission, and accesses data.

  **dataPath** identifies the data. It can be customized and must be unique in the same data provider application.


## Constraints

- Currently, only the RDB stores support silent data access.
- The system supports a maximum of 16 concurrent query operations. Excess query requests need to be queued for processing.
- The proxy is not allowed to create a database for persistent data. To create a database, you must start the data provider.
- If the data provider is an application with a normal signature, the data read/write permission must be system_basic or higher.


## Available APIs

The following table lists the APIs for silent data access. Most of the APIs are executed asynchronously in callback or promise mode. In the following table, callback-based APIs are used as an example. For more information about the APIs, see [Data Sharing](../reference/apis/js-apis-data-dataShare.md).

### Common API

| API                                    | Description                  |
| ---------------------------------------- | -------------------- |
| createDataShareHelper(context: Context, uri: string, options: DataShareHelperOptions, callback: AsyncCallback&lt;DataShareHelper&gt;): void | Creates a **DataShareHelper** instance.|

### APIs for Persistent Data

| API                                    | Description                  |
| ---------------------------------------- | -------------------- |
| insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | Inserts a row of data into a table.        |
| delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void | Deletes one or more data records from the database.   |
| query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void | Queries data in the database.          |
| update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void | Updates data in the database.        |
| addTemplate(uri: string, subscriberId: string, template: Template): void | Adds a data template with the specified subscriber.     |
| on(type: 'rdbDataChange', uris: Array&lt;string&gt;, templateId: TemplateId, callback: AsyncCallback&lt;RdbDataChangeNode&gt;): Array&lt;OperationResult | Subscribes to the changes of the data corresponding to the specified URI and template.|

### APIs for Process Data

| API                                    | Description                |
| ---------------------------------------- | ------------------ |
| publish(data: Array&lt;PublishedItem&gt;, bundleName: string, version: number, callback: AsyncCallback&lt;Array&lt;OperationResult&gt;&gt;): void | Publishes data to the **DatamgrService**.|
| on(type: 'publishedDataChange', uris: Array&lt;string&gt;, subscriberId: string, callback: AsyncCallback&lt;PublishedDataChangeNode&gt;): Array&lt;OperationResult&gt; | Subscribes to changes of the published data.   |



## Implementation of the Persistence Data

The following describes how to share an RDB store.

### Data Provider Application

1. In the **module.json5** file, set the ID, read/write permissions, and basic information of the table to be shared under **proxyDatas**.

   **Table 1** Fields of proxyDatas in module.json5

   | Field                   | Description                                    | Mandatory  |
   | ----------------------- | ---------------------------------------- | ---- |
   | uri                     | URI of the data, which is the unique identifier for cross-application data access.                 | Yes   |
   | requiredReadPermission  | Permission required for reading data from the data proxy. If this parameter is not set, other applications are not allowed to access data. For details about the supported permissions, see [Application Permission List](../security/permission-list.md).           | No   |
   | requiredWritePermission | Permission required for modifying data from the data proxy. If this parameter is not set, other applications are not allowed to modify the data. For details about the supported permissions, see [Application Permission List](../security/permission-list.md).         | No   |
   | metadata                | Data source information, including the **name** and **resource** fields.<br> The **name** field identifies the configuration, which has a fixed value of **dataProperties**.<br> The value of **resource** is **$profile:{fileName}**, indicating that the name of the configuration file is **{fileName}.json**.| Yes   |

   **module.json5 example**

   ```json
   "proxyDatas":[
     {
       "uri": "datashareproxy://com.acts.ohos.data.datasharetest/test",
       "requiredReadPermission": "ohos.permission.GET_BUNDLE_INFO",
       "requiredWritePermission": "ohos.permission.KEEP_BACKGROUND_RUNNING",
       "metadata": {
         "name": "dataProperties",
         "resource": "$profile:my_config"
       }
     }
   ]
   ```
   **Table 2** Fields in my_config.json

   | Field | Description                                    | Mandatory  |
   | ----- | ---------------------------------------- | ---- |
   | path  | Data source path, in the **Database_name/Table_name** format. Currently, only RDB stores are supported.             | Yes   |
   | type  | Database type. Currently, only **rdb** is supported.            | Yes   |
   | scope | Scope of the database.<br>- **module** indicates that the database is located in this module.<br>- **application** indicates that the database is located in this application.| No   |

   **my_config.json example**

   ```json
   {
     "path": "DB00/TBL00",
     "type": "rdb",
     "scope": "application"
   }
   ```

### Data Consumer Application


1. Import dependencies.

   ```ts
   import dataShare from '@ohos.data.dataShare';
   import dataSharePredicates from '@ohos.data.dataSharePredicates';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import { ValuesBucket } from '@ohos.data.ValuesBucket';
   import window from '@ohos.window';
   import { BusinessError } from '@ohos.base';
   ```

2. Define the URI string for communicating with the data provider.

   ```ts
   let dseUri = ('datashareproxy://com.acts.ohos.data.datasharetest/test');
   ```

3. Create a **DataShareHelper** instance.

   ```ts
   let dsHelper: dataShare.DataShareHelper | undefined = undefined;
   let abilityContext: Context;

   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       abilityContext = this.context;
       dataShare.createDataShareHelper(abilityContext, "", {
         isProxy: true
       }, (err, data) => {
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

5. Subscribe to the specified data.

   ```ts
   function onCallback(err: BusinessError, node: dataShare.RdbDataChangeNode) {
     console.info("uri " + JSON.stringify(node.uri));
     console.info("templateId " + JSON.stringify(node.templateId));
     console.info("data length " + node.data.length);
     for (let i = 0; i < node.data.length; i++) {
       console.info("data " + node.data[i]);
     }
   }

   let key21: string = "p1";
   let value21: string = "select * from TBL00";
   let key22: string = "p2";
   let value22: string = "select name from TBL00";
   let template: dataShare.Template = {
     predicates: {
       key21: value21,
       key22: value22,
     },
     scheduler: ""
   }
   if(dsHelper != undefined)
   {
     (dsHelper as dataShare.DataShareHelper).addTemplate(dseUri, "111", template);
   }
   let templateId: dataShare.TemplateId = {
     subscriberId: "111",
     bundleNameOfOwner: "com.acts.ohos.data.datasharetestclient"
   }
   if(dsHelper != undefined) {
     // When the DatamgrService modifies data, onCallback is invoked to return the data queried based on the rules in the template.
     let result: Array<dataShare.OperationResult> = (dsHelper as dataShare.DataShareHelper).on("rdbDataChange", [dseUri], templateId, onCallback);
   }
   ```

## Implementation of the Process Data

The following describes how to host process data.

### (Optional) Data Provider Application

In the **module.json5** file of the data provider, set the process data ID, read/write permissions, and basic information under **proxyDatas**.

> **NOTE**
>
> - This step is optional.
> - If **proxyDatas** is not configured, the hosted data cannot be accessed by other applications.
> - If **proxyDatas** is not configured, you do not need to use the full data path. For example, you can use **weather** instead of **datashareproxy://com.acts.ohos.data.datasharetest/weather** when publishing, subscribing to, and querying data.

**Table 3** Fields of proxyDatas in module.json5

| Field                   | Description                         | Mandatory  |
| ----------------------- | ----------------------------- | ---- |
| uri                     | URI of the data, which is the unique identifier for cross-application data access.      | Yes   |
| requiredReadPermission  | Permission required for reading data from the data proxy. If this parameter is not set, other applications are not allowed to access data. For details about the supported permissions, see [Application Permission List](../security/permission-list.md).| No   |
| requiredWritePermission | Permission required for modifying data from the data proxy. If this parameter is not set, other applications are not allowed to access data. For details about the supported permissions, see [Application Permission List](../security/permission-list.md).| No   |

**module.json5 example**

```json
"proxyDatas": [
  {
    "uri": "datashareproxy://com.acts.ohos.data.datasharetest/weather",
    "requiredReadPermission": "ohos.permission.GET_BUNDLE_INFO",
    "requiredWritePermission": "ohos.permission.KEEP_BACKGROUND_RUNNING"
  }
]
```

### Data Consumer Application

1. Import dependencies.

   ```ts
   import dataShare from '@ohos.data.dataShare';
   import UIAbility from '@ohos.app.ability.UIAbility';
   import window from '@ohos.window';
   import { BusinessError } from '@ohos.base';
   ```

2. Create a **DataShareHelper** instance.

   ```ts
   let dsHelper: dataShare.DataShareHelper | undefined = undefined;
   let abilityContext: Context;

   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       abilityContext = this.context;
       dataShare.createDataShareHelper(abilityContext, "", {isProxy : true}, (err, data) => {
         dsHelper = data;
       });
     }
   }
   ```

3. Use the APIs provided by **DataShareHelper** to access the services provided by the provider, for example, adding, deleting, modifying, and querying data.

   ```ts
   // Construct two pieces of data. The first data is not configured with proxyDatas and cannot be accessed by other applications.
   let data : Array<dataShare.PublishedItem> = [
     {key:"city", subscriberId:"11", data:"xian"},
     {key:"datashareproxy://com.acts.ohos.data.datasharetest/weather", subscriberId:"11", data:JSON.stringify("Qing")}];
   // Publish data.
   if (dsHelper != undefined) {
     let result: Array<dataShare.OperationResult> = await (dsHelper as dataShare.DataShareHelper).publish(data, "com.acts.ohos.data.datasharetestclient");
   }
   ```

4. Subscribe to the specified data.

   ```ts
   function onPublishCallback(err: BusinessError, node:dataShare.PublishedDataChangeNode) {
     console.info("onPublishCallback");
   }
   let uris:Array<string> = ["city", "datashareproxy://com.acts.ohos.data.datasharetest/weather"];
   if (dsHelper != undefined) {
     let result: Array<dataShare.OperationResult> = (dsHelper as dataShare.DataShareHelper).on("publishedDataChange", uris, "11", onPublishCallback);
   }
   ```

   
