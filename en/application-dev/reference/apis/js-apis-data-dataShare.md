# @ohos.data.dataShare (Data Sharing)

The **DataShare** module allows an application to manage its own data and share data with other applications on the same device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.
>
> The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import dataShare from '@ohos.data.dataShare'
```

## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void

Creates a **DataShareHelper** instance. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to access **DataShareExtension**, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target **DataShareExtension** is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](js-apis-inner-application-context.md#context)        | Yes  | Context of an application.                                          |
| uri      | string                                                   | Yes  | Uniform Resource Identifier (URI) of the server application to connect.                              |
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the **DataShareHelper** instance created. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 15700010 | The DataShareHelper is not initialized successfully. |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper;
try {
    dataShare.createDataShareHelper(this.context, uri, (err, data) => {
        if (err !== undefined) {
            console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("createDataShareHelper succeed, data : " + data);
        dataShareHelper = data;
    });
} catch (err) {
    console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
};
```

## dataShare.createDataShareHelper<sup>10+</sup>
createDataShareHelper(context: Context, uri: string, options: DataShareHelperOptions, callback: AsyncCallback&lt;DataShareHelper&gt;): void

Creates a **DataShareHelper** instance. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to access **DataShareExtension**, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target **DataShareExtension** is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer


| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](js-apis-inner-application-context.md#context)        | Yes  | Context of an application.                                          |
| uri      | string                                                   | Yes  | Uniform Resource Identifier (URI) of the server application to connect.                              |
| options | [DataShareHelperOptions](#datasharehelperoptions10)| Yes  | Configuration specifying whether [DataShareHelper](#datasharehelper) is in proxy mode.|
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the **DataShareHelper** instance created. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 15700010 | The DataShareHelper is not initialized successfully. |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let dataShareHelper;
try {
    dataShare.createDataShareHelper(this.context, uri, {isProxy : true}, (err, data) => {
        if (err !== undefined) {
            console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("createDataShareHelper succeed, data : " + data);
        dataShareHelper = data;
    });
} catch (err) {
    console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
};
```
## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, options?: DataShareHelperOptions): Promise&lt;DataShareHelper&gt;

Creates a **DataShareHelper** instance. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to access **DataShareExtension**, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target **DataShareExtension** is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name | Type                                         | Mandatory| Description                          |
| ------- | ------------------------------------------------- | ---- | ------------------------------ |
| context | [Context](js-apis-inner-application-context.md#context) | Yes  | Context of an application.            |
| uri     | string                                            | Yes  | Uniform Resource Identifier (URI) of the server application to connect.|
| options | [DataShareHelperOptions](#datasharehelperoptions10) | No| Optional configuration of the **DataShareHelper** instance. This parameter is supported from API version 10. If it is not set, [DataShareHelper](#datasharehelper) is not in proxy mode.|

**Return value**

| Type                                              | Description                                  |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;[DataShareHelper](#datasharehelper)&gt; | Promise used to return the **DataShareHelper** instance created.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 15700010 | The DataShareHelper is not initialized successfully. |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let dataShareHelper;
try {
    dataShare.createDataShareHelper(this.context, uri, {isProxy : true}).then((data) => {
        console.info("createDataShareHelper succeed, data : " + data);
        dataShareHelper = data;
    }). catch((err) => {
        console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
};
```

## DataShareHelperOptions<sup>10+</sup>

Defines whether [DataShareHelper](#datasharehelper) is in proxy mode.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| isProxy | boolean | No| Whether the [DataShareHelper](#datasharehelper) is in proxy mode. The default value is **false**.<br>If the value is **true**, the [DataShareHelper](#datasharehelper) to be created is in proxy mode, and all operations will not open the data provider application unless the database does not exist. If the database does not exist, [createDataShareHelper] (#datasharecreatedatasharehelper10) will start the data provider to create a database.|

## TemplateId<sup>10+</sup>

Defines the **TemplateId** struct. **TemplateId** is generated by [**addTemplate**](#addtemplate10) to identify a template.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| subscriberId | string | Yes| ID of the subscriber who handles the callback. The value must the same as the **subscriberId** in [**addTemplate**](#addtemplate10). The ID of each subscriber must be unique.|
| bundleNameOfOwner | string | Yes| Bundle name of the template owner. The value must be the same as the **bundleName** in [**addTemplate**](#addtemplate10).|

## PublishedItem<sup>10+</sup>

Defines the type of the data to publish.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the data to publish.|
| data | string \| [Ashmem](js-apis-rpc.md#ashmem8) | Yes| Data to publish. If the data volume is large, use **Ashmem**.|
| subscriberId | string | Yes| Subscriber ID.|

## RdbDataChangeNode<sup>10+</sup>

Defines the subscription/unsubscription result of the RDB data changes.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the callback.|
| templateId | [TemplateId](#templateid10) | Yes| ID of the template that triggers the callback.|
| data | Array&lt;string&gt; | Yes| Data of the callback.|

## PublishedDataChangeNode<sup>10+</sup>

Defines the subscription/unsubscription result of the changes in the published data.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the callback.|
| data | Array&lt;[PublishedItem](#publisheditem10)&gt; | Yes| Data of the callback.|

## Template<sup>10+</sup>

Defines the struct of the template used in a subscription.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| predicates | { [key: string]: string } | Yes| Predicates to use. When [**on**](#onrdbdatachange10) is called, the predicates are used to generate data. This parameter applies only to RDB data storage. |
| scheduler | string | Yes| Template scheduler SQL, which is embedded with a custom function. Currently, the **remindTimer** function is embedded. The **remindTimer** triggers a subscription-based update in specified scenarios.<br>The scheduler SQL statement is triggered when:<br>1. The subscribed data is modified.<br>2. The first subscription is added to the corresponding database.|

## OperationResult<sup>10+</sup>

Defines the result of the operation for subscribing to or unsubscribing from the data changes or published data.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | ----- | -------- |
| key | string | Yes| Key of the operation result.|
| result | number | Yes| Operation result. |
## DataShareHelper

Provides a **DataShareHelper** instance to access or manage data on the server. Before calling an API provided by **DataShareHelper**, you must create a **DataShareHelper** instance using [createDataShareHelper](#datasharecreatedatasharehelper).

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback&lt;void&gt;): void

Subscribes to changes of the specified data. After an observer is registered, the subscriber will receive a notification when the change notification is triggered (the **notifyChange()** method is called). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                   |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event type to subscribe to. The value is **dataChange**, which indicates data change events.|
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If data is changed, the value of **err** is undefined. Otherwise, this callback is not invoked or the value of **err** is an error object.|

**Example**

```ts
function onCallback() {
    console.info("**** Observer on callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.on("dataChange", uri, onCallback);
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback&lt;void&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                   |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event or callback type to unsubscribe from. The value is **dataChange**, which indicates data change events.|
| uri      | string               | Yes  | URI of the target data.|
| callback | AsyncCallback&lt;void&gt; | No  | Callback for the data change event. If this parameter is left empty, all notification events of the URI will be unsubscribed from.|

**Example**

```ts
function callback() {
    console.info("**** Observer callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.on("dataChange", uri, callback);
dataShareHelper.off("dataChange", uri, callback);
```

### addTemplate<sup>10+</sup>

addTemplate(uri: string, subscriberId: string, template: Template): void

Adds a data template with the specified subscriber.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                   | Mandatory| Description                    |
| -------- | ------------------------ | ---- | -------------------------|
| uri      | string                   | Yes  | URI of the data template to add. |
| subscriberId | string               | Yes  | Unique ID of the template subscriber.|
| template    | [Template](#template10) | Yes  | Data template to add.       |

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message             |
| -------- | -------------------- |
| 15700011 | The uri is not exist.|

**Example**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let subscriberId = '11';
let template = {
    predicates : {
        "p1" : "select cityColumn as city_1, visitedCilumn as visited_1 from citys where like = true",
        "p2" : "select cityColumn as city_2, visitedCilumn as visited_2 from citys where like = false",
    },
    scheduler : "select remindTimer(time) from TBL00"
}
dataShareHelper.addTemplate(uri, subscriberId, template);
```

### delTemplate<sup>10+</sup>

delTemplate(uri: string, subscriberId: string): void

Deletes a data template based on the specified subscriber.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type       | Mandatory| Description                      |
| -------- | -------------| ---- | ------------------------- |
| uri      | string       | Yes  | URI of the data template to delete.    |
| subscriberId | string   | Yes  | Unique ID of the subscriber.         |

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message             |
| -------- | -------------------- |
| 15700011 | The uri is not exist.|

**Example**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let subscriberId = '11';
let template = {
    predicates : {
        "p1" : "select cityColumn as city_1, visitedCilumn as visited_1 from citys where like = true",
        "p2" : "select cityColumn as city_2, visitedCilumn as visited_2 from citys where like = false",
    },
    scheduler : "select remindTimer(time) from TBL00"
}
dataShareHelper.addTemplate(uri, subscriberId, template);
dataShareHelper.delTemplate(uri, subscriberId);
```

### on('rdbDataChange')<sup>10+</sup>

on(type: 'rdbDataChange', uris: Array&lt;string&gt;, templateId: TemplateId, callback: AsyncCallback&lt;RdbDataChangeNode&gt;): Array&lt;OperationResult&gt;

Subscribes to the changes of the data corresponding to the specified URI and template.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                           | Mandatory| Description                                                        |
| -------- | ----------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                           | Yes  | Type of the event to subscribe to. The value is **rdbDataChange**, which indicates the RDB data change event. |
| uris    | Array&lt;string&gt;                | Yes  | URIs of the data to operate.          |
| templateId | [TemplateId](#templateid10)       | Yes  | ID of the template that triggers the callback.          |
| callback | AsyncCallback&lt;[RdbDataChangeNode](#rdbdatachangenode10)&gt;   | Yes  | Callback invoked to return the result when the specified data changes. The **err** is **undefined**, and **node** is the new data. Otherwise, this callback is not triggered or **err** is an error object. |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Example**

```ts
function onCallback(err, node:dataShare.RdbDataChangeNode) {
    console.info("onCallback " + JSON.stringify(node.uri));
    console.info("onCallback " + JSON.stringify(node.templateId));
    console.info("onCallback " + node.data.length);
    for (let i = 0; i < node.data.length; i++) {
        console.info("onCallback " + typeof node.data[i] + " " + node.data[i]);
    }
}

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let templateId:dataShare.TemplateId = {subscriberId:"11", bundleNameOfOwner:"com.acts.ohos.data.datasharetest"};
let result:Array<dataShare.OperationResult> = dataShareHelper.on("rdbDataChange", [uri], templateId, onCallback);
```

### off('rdbDataChange')<sup>10+</sup>

off(type: 'rdbDataChange', uris: Array&lt;string&gt;, templateId: TemplateId, callback?: AsyncCallback&lt;RdbDataChangeNode&gt;): Array&lt;OperationResult&gt;

Unsubscribes from the changes of the data corresponding to the specified URI and template.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                       |
| -------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| type      | string                                      | Yes  | Type of the event to unsubscribe from. The value is **rdbDataChange**, which indicates the RDB data change event.  |
| uris    | Array&lt;string&gt;                           | Yes  | URIs of the data to operate.          |
| templateId | [TemplateId](#templateid10)                | Yes  | ID of the template that triggers the callback.       |
| callback | AsyncCallback&lt;[RdbDataChangeNode](#rdbdatachangenode10)&gt; | No  | Callback invoked to return the result. Callback for the data change event. If this parameter is left empty, all notification events of the URI will be unsubscribed from.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Example**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let templateId:dataShare.TemplateId = {subscriberId:"11", bundleNameOfOwner:"com.acts.ohos.data.datasharetest"};
let result:Array<dataShare.OperationResult> = dataShareHelper.off("rdbDataChange", [uri], templateId);
```

### on('publishedDataChange')<sup>10+</sup>

on(type: 'publishedDataChange', uris: Array&lt;string&gt;, subscriberId: string, callback: AsyncCallback&lt;PublishedDataChangeNode&gt;): Array&lt;OperationResult&gt;

Subscribes to the changes of the published data.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                           | Mandatory| Description                                                        |
| -------- | ----------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                           | Yes  | Type of the event to subscribe to. The value is **publishedDataChange**, which indicates the event of published data changes.|
| uris    | Array&lt;string&gt;                | Yes  | URIs of the data to operate.          |
| subscriberId | string                        | Yes  | Subscriber ID of the callback.          |
| callback | AsyncCallback&lt;[PublishedDataChangeNode](#publisheddatachangenode10)&gt;   | Yes  | Callback invoked to return the result when the published data changes. The **err** is **undefined**, and **node** is the new data. Otherwise, this callback is not triggered or **err** is an error object. |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Example**

```ts
import rpc from '@ohos.rpc';

function onPublishCallback(err, node:dataShare.PublishedDataChangeNode) {
    console.info("onPublishCallback node bundleName " + JSON.stringify(node.bundleName));
    console.info("onPublishCallback node data size" + node.data.length);
    for (let i = 0; i < node.data.length; i++) {
        console.info("onPublishCallback node " + typeof node.data[i].data);
        if (typeof node.data[i].data != 'string') {
            let ash:rpc.Ashmem = node.data[i].data;
            ash.mapReadonlyAshmem();
            console.info("onPublishCallback " + JSON.stringify(ash.readAshmem(ash.getAshmemSize()/4, 0)));
            ash.closeAshmem();
        }
        console.info("onPublishCallback data " + i + " " + JSON.stringify(node.data[i]));
    }
}
let uris:Array<string> = ['city', 'datashareproxy://com.acts.ohos.data.datasharetest/appInfo', 'key2'];
let subscriberId = '11';
let result: Array<dataShare.OperationResult> = dataShareHelper.on('publishedDataChange', uris, subscriberId, onPublishCallback);
```

### off('publishedDataChange')<sup>10+</sup>

off(type: 'publishedDataChange', uris: Array&lt;string&gt;, subscriberId: string, callback?: AsyncCallback&lt;PublishedDataChangeNode&gt;): Array&lt;OperationResult&gt;

Unsubscribes from the changes of the published data.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                      |
| -------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| type      | string                                      | Yes  | Type of the event to unsubscribe from. The value is **publishedDataChange**, which indicates the event of published data changes.|
| uris    | Array&lt;string&gt;                           | Yes  | URIs of the data to operate.          |
| subscriberId | string                                   | Yes  | Subscriber ID of the callback.          |
| callback | AsyncCallback&lt;[PublishedDataChangeNode](#publisheddatachangenode10)&gt; | No  | Callback invoked to return the result. Callback for the published data change event. If this parameter is left empty, all notification events of the URI will be unsubscribed from.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Example**

```ts
function offCallback(err, node:dataShare.PublishedDataChangeNode) {
    console.info("**** Observer off callback ****");
}
let uris:Array<string> = ["city", "datashareproxy://com.acts.ohos.data.datasharetest/appInfo", "key2"];
let subscriberId = '11';
let result: Array<dataShare.OperationResult> = dataShareHelper.off("publishedDataChange", uris, subscriberId, offCallback);
```

### publish<sup>10+</sup>

publish(data: Array&lt;PublishedItem&gt;, bundleName: string, version: number, callback: AsyncCallback&lt;Array&lt;OperationResult&gt;&gt;): void

Publishes data to the database.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                     | Mandatory| Description     |
| --------- | -------------------------------------------------| ---- | ------------------- |
| data      | Array&lt;[PublishedItem](#publisheditem10)&gt;     | Yes  | Data to publish.  |
| bundleName | string                                          | Yes  | Application of the data to publish. This parameter is valid only for the private data published. Only the application can read the data.          |
| version | number                                             | Yes  | Version of the data to publish. A larger value indicates a later data version. If the version of the data published is earlier than that of the data in the database, the data in the database will not be updated.|
| callback | AsyncCallback&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | Yes  | Callback invoked to return the result. If data is published, **err** is **undefined**, and **result** is the data publish result. Otherwise, this callback will not be triggered or **err** is an error object.   |

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**Example**

```ts
import rpc from '@ohos.rpc';

let ashmem = null;
let subscriberId = '11';
let version = 1;
let data : Array<dataShare.PublishedItem> = [
    {key:"city", subscriberId:"11", data:"xian"},
    {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
    {key:"empty", subscriberId:"11", data:"nobody sub"}];
let nums:number[] = [1,2,3];
function publishCallback(err, result: Array<dataShare.OperationResult>) {
    console.info("publishCallback " + JSON.stringify(result));
    ashmem.closeAshmem();
}
try {
    ashmem = rpc.Ashmem.create("ashmem", (nums.length) * 4);
    ashmem.mapReadWriteAshmem();
    ashmem.writeAshmem(nums, nums.length, 0);
    data.push({
        "key" : "key2",
        "data" : ashmem,
        "subscriberId" : "11",
    });
    console.info("data length is:", data.length);
    dataShareHelper.publish(data, "com.acts.ohos.data.datasharetest", version, publishCallback);
} catch (e) {
    console.error("publish error " + JSON.stringify(e));
}
```

### publish<sup>10+</sup>

publish(data: Array&lt;PublishedItem&gt;, bundleName: string, callback: AsyncCallback&lt;Array&lt;OperationResult&gt;&gt;): void

Publishes data to the database.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                           | Mandatory| Description                                |
| -------- | ------------------------------------------------- | ---- | ---------------------------------- |
| data      | Array&lt;[PublishedItem](#publisheditem10)&gt;                        | Yes  | Data to publish.  |
| bundleName | string                                          | Yes  | Application of the data to publish. This parameter is valid only for the private data published. Only the application can read the data.      |
| callback | AsyncCallback&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | Yes  | Callback invoked to return the result. If data is published, **err** is **undefined**, and **result** is the data publish result. Otherwise, this callback will not be triggered or **err** is an error object.|

**Example**

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

```ts
function publishCallback(err, result: Array<dataShare.OperationResult>) {
    console.info("publishCallback " + JSON.stringify(result));
}
let data : Array<dataShare.PublishedItem> = [
    {key:"city", subscriberId:"11", data:"xian"},
    {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
    {key:"empty", subscriberId:"11", data:"nobody sub"}];
dataShareHelper.publish(data, "com.acts.ohos.data.datasharetest", publishCallback);
```

### publish<sup>10+</sup>

publish(data: Array&lt;PublishedItem&gt;, bundleName: string, version?: number): Promise&lt;Array&lt;OperationResult&gt;&gt;

Publishes data to the database.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                           |
| -------- | ----------------------------- | ---- | ------------------------------ |
| data      | Array&lt;[PublishedItem](#publisheditem10)&gt;    | Yes  | Data to publish.|
| bundleName | string                      | Yes  | Application of the data to publish. This parameter is valid only for the private data published. Only the application can read the data. |
| version | number                         | No  | Version of the data to publish. A larger value indicates a later data version. If the version of the data published is earlier than that of the data in the database, the data in the database will not be updated.<br> If the data version is not checked, leave this parameter unspecified.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | Returns the operation result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**Example**

```ts
let data : Array<dataShare.PublishedItem> = [
    {key:"city", subscriberId:"11", data:"xian"},
    {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
    {key:"empty", subscriberId:"11", data:"nobody sub"}];
let result: Array<dataShare.OperationResult> = dataShareHelper.publish(data, "com.acts.ohos.data.datasharetest");
```

### getPublishedData<sup>10+</sup>

getPublishedData(bundleName: string, callback: AsyncCallback&lt;Array&lt;PublishedItem&gt;&gt;): void

Obtains the published data of an application.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name   | Type            | Mandatory| Description                          |
| -------- | -----------------| ---- | ----------------------------- |
| bundleName | string         | Yes  | Application to which the data belongs. |
| callback | AsyncCallback&lt;Array&lt;[PublishedItem](#publisheditem10)&gt;&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**Example**

```ts
function publishCallback(err, data: Array<dataShare.PublishedItem>) {
    console.info("**** Observer publish callback ****");
}
dataShareHelper.getPublishedData("com.acts.ohos.data.datasharetest", publishCallback);
```

### getPublishedData<sup>10+</sup>

getPublishedData(bundleName: string): Promise&lt;Array&lt;PublishedItem&gt;&gt;

Obtains the published data of an application.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type        | Mandatory| Description                                   |
| -------- | --------------| ---- | -------------------------------------- |
| bundleName | string      | Yes  | Application to which the data belongs.          |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[PublishedItem](#publisheditem10)&gt;&gt; | Promise used to return the data obtained.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](../errorcodes/errorcode-datashare.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 15700012 | The data area is not exist.|

**Example**

```ts 
let publishedData:Array<dataShare.PublishedItem> = dataShareHelper.getPublishedData("com.acts.ohos.data.datasharetest");
```

### insert

insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Inserts a single data record into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                     | Mandatory| Description                                                       |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                                    | Yes  | URI of the data to insert.                                    |
| value    | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | Yes  | Data to insert. If this parameter is empty, a blank row will be inserted.          |
| callback | AsyncCallback&lt;number&gt;                               | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the index of the inserted data record. Otherwise, **err** is an error object.<br>The data index is not returned if the APIs of the database in use, for example, the key-value database (KVDB), do not support the return of indexes.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
}
try {
    dataShareHelper.insert(uri, valueBucket, (err, data) => {
        if (err !== undefined) {
            console.error(`insert error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("insert succeed, data : " + data);
    });
} catch (err) {
    console.error(`insert error: code: ${err.code}, message: ${err.message} `);
};
```

### insert

insert(uri: string, value: ValuesBucket): Promise&lt;number&gt;

Inserts a single data record into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name | Type                                                     | Mandatory| Description                                              |
| ----- | --------------------------------------------------------- | ---- | -------------------------------------------------- |
| uri   | string                                                    | Yes  | URI of the data to insert.                          |
| value | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | Yes  | Data to insert. If this parameter is empty, a blank row will be inserted.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the index of the inserted data record.<br>The data index is not returned if the APIs of the database in use (for example, KVDB) do not support the return of indexes.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
}
try {
    dataShareHelper.insert(uri, valueBucket).then((data) => {
        console.info("insert succeed, data : " + data);
    }). catch((err) => {
        console.error(`insert error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`insert error: code: ${err.code}, message: ${err.message} `);
};
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

Deletes one or more data records from the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to delete.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **delete()** vary depending on the database in use. For example, the KVDB supports only **inKeys**.|
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of deleted data records. Otherwise, **err** is an error object.<br>The number of deleted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.delete(uri, da, (err, data) => {
        if (err !== undefined) {
            console.error(`delete error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("delete succeed, data : " + data);
    });
} catch (err) {
    console.error(`delete error: code: ${err.code}, message: ${err.message} `);
};
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates): Promise&lt;number&gt;

Deletes one or more data records from the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to delete.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **delete()** vary depending on the database in use. For example, the KVDB supports only **inKeys**.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of deleted data records.<br>The number of deleted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.delete(uri, da).then((data) =>  {
        console.info("delete succeed, data : " + data);
    }). catch((err) => {
        console.error(`delete error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`delete error: code: ${err.code}, message: ${err.message} `);
};
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to query.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **query()** vary depending on the database used. For example, the KVDB supports only **inKeys** and **prefixKey**.|
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is empty, all columns will be queried.              |
| callback   | AsyncCallback&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the result set obtained. Otherwise, **err** is an error object.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.query(uri, da, columns, (err, data) => {
        if (err !== undefined) {
            console.error(`query error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("query succeed, rowCount : " + data.rowCount);
    });
} catch (err) {
    console.error(`query error: code: ${err.code}, message: ${err.message} `);
};
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;): Promise&lt;DataShareResultSet&gt;

Queries data in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to query.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **query()** vary depending on the database used. For example, the KVDB supports only **inKeys** and **prefixKey**.|
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is empty, all columns will be queried.              |

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | Promise used to return the result set obtained.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
    dataShareHelper.query(uri, da, columns).then((data) =>  {
        console.info("query succeed, rowCount : " + data.rowCount);
    }). catch((err) => {
        console.error(`query error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`query error: code: ${err.code}, message: ${err.message} `);
};
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Updates data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to update.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **update()** vary depending on the database in use. For example, only the relational database (RDB) supports predicates.|
| value      | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | Yes  | New data.                                          |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of updated data records. Otherwise, **err** is an error object.<br>The number of updated data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
try {
    dataShareHelper.update(uri, da, va, (err, data) => {
        if (err !== undefined) {
            console.error(`update error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("update succeed, data : " + data);
    });
} catch (err) {
    console.error(`update error: code: ${err.code}, message: ${err.message} `);
};
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket): Promise&lt;number&gt;

Updates data in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to update.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **update()** vary depending on the database in use. For example, only the relational database (RDB) supports predicates.|
| value      | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | Yes  | New data.                                          |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of data records updated.<br>The number of updated data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
try {
    dataShareHelper.update(uri, da, va).then((data) =>  {
        console.info("update succeed, data : " + data);
    }). catch((err) => {
        console.error(`update error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`update error: code: ${err.code}, message: ${err.message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

Batch inserts data into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri      | string                                                       | Yes  | URI of the data to insert.                                    |
| values   | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | Yes  | Data to insert.                                          |
| callback | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of data records inserted. Otherwise, **err** is an error object.<br>The number of inserted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
try {
    dataShareHelper.batchInsert(uri, vbs, (err, data) => {
        if (err !== undefined) {
            console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
            return;
        }
        console.info("batchInsert succeed, data : " + data);
    });
} catch (err) {
    console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

Batch inserts data into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                    |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| uri    | string                                                       | Yes  | URI of the data to insert.|
| values | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | Yes  | Data to insert.      |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of data records inserted.<br>The number of inserted data records is not returned if the APIs of the database (for example, KVDB) in use do not the return of the number of data records.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
try {
    dataShareHelper.batchInsert(uri, vbs).then((data) =>  {
        console.info("batchInsert succeed, data : " + data);
    }). catch((err) => {
        console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
    });
} catch (err) {
    console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
};
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

Normalizes a **DataShare** URI. The **DataShare** URI can be used only by the local device, but the normalized URI can be used across devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                  | Mandatory| Description                                                    |
| -------- | ---------------------- | ---- | -------------------------------------------------------- |
| uri      | string                 | Yes  | [URI](js-apis-uri.md#uri) to normalize.     |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the normalized URI (if **null** is returned, URI normalization is not supported). Otherwise, **err** is an error object.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri, (err, data) => {
    if (err !== undefined) {
        console.info("normalizeUri failed, error message : " + err);
    }else{
        console.info("normalizeUri = " + data);
    }
});
```

### normalizeUri

normalizeUri(uri: string): Promise&lt;string&gt;

Normalizes a **DataShare** URI. The **DataShare** URI can be used only by the local device, but the normalized URI can be used across devices. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ---- | ------ | ---- | ----------------------------------------- |
| uri  | string | Yes  | [URI](js-apis-uri.md#uri) to normalize.|

**Return value**

| Type            | Description                                          |
| ---------------- | ---------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. If URI normalization is supported, the normalized URI is returned. Otherwise, **null** is returned.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri).then((data) => {
    console.info("normalizeUri = " + data);
}).catch((err) => {
    console.info("normalizeUri failed, error message : " + err);
});
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

Denormalizes a URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | Yes  | [URI](js-apis-uri.md#uri) to denormalize.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the URI obtained. If the original URI is returned, denormalization is not required. If **null** is returned, denormalization is not supported. If the operation fails, **err** is an error object.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri, (err, data) => {
    if (err !== undefined) {
        console.error("denormalizeUri failed, error message : " + err);
    }else{
        console.info("denormalizeUri = " + data);
    }
});
```

### denormalizeUri

denormalizeUri(uri: string): Promise&lt;string&gt;

Denormalizes a URI. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                                       |
| ---- | ------ | ---- | ------------------------------------------- |
| uri  | string | Yes  | [URI](js-apis-uri.md#uri) to denormalize.|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. If the denormalization is successful, the URI obtained is returned. If no operation is required, the original URI is returned. If denormalization is not supported, **null** is returned.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri).then((data) => {
    console.info("denormalizeUri = " + data);
}).catch((err) => {
    console.error("denormalizeUri failed, error message : " + err);
});
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback&lt;void&gt;): void

Notifies the registered observer of data changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name   | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the observer is notified of the data changes, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri, () => {
    console.info("***** notifyChange *****");
});
```

### notifyChange

notifyChange(uri: string): Promise&lt;void&gt;

Notifies the registered observer of data changes. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                |
| ---- | ------ | ---- | -------------------- |
| uri  | string | Yes  | URI of the data.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri);
```
