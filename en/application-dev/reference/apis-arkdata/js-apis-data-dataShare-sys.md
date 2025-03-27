# @ohos.data.dataShare (DataShare) (System API)

The **DataShare** module allows an application to manage its own data and share data with other applications on the same device.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.
>
> - The APIs of this module can be used only in the stage model.
>
> - The callback in **on('rdbDataChange')** cannot transfer data larger than 200 KB in size.


## Modules to Import

```ts
import { dataShare } from '@kit.ArkData';
```

## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void

Creates a **DataShareHelper** instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context)        | Yes  | Context of the application.                                          |
| uri      | string                                                   | Yes  | Uniform Resource Identifier (URI) of the server application to connect.                              |
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the **DataShareHelper** instance created. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700010 | The DataShareHelper is not initialized successfully. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { UIAbility } from '@kit.AbilityKit';

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper: dataShare.DataShareHelper | undefined = undefined;
let context = getContext(UIAbility);
try {
  dataShare.createDataShareHelper(context, uri, (err:BusinessError, data:dataShare.DataShareHelper) => {
    if (err !== undefined) {
      console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
      return;
    }
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`createDataShareHelper error: code: ${code}, message: ${message} `);
};
```

## dataShare.createDataShareHelper<sup>10+</sup>
createDataShareHelper(context: Context, uri: string, options: DataShareHelperOptions, callback: AsyncCallback&lt;DataShareHelper&gt;): void 

Creates a **DataShareHelper** instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer


| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context)        | Yes  | Context of the application.                                          |
| uri      | string                                                   | Yes  | URI of the server application to connect.                              |
| options | [DataShareHelperOptions](#datasharehelperoptions10)| Yes  | Whether [DataShareHelper](#datasharehelper) is in proxy mode and the waiting time for starting the data provider process in non-silent access mode.<br>If this parameter is not set, [DataShareHelper](#datasharehelper) is not in proxy mode and the waiting time for starting the data provider process in non-silent access mode is 2 seconds.<br>If the URI starts with **datashareproxy**, the **isProxy** parameter in **options** must be set. Otherwise, **DataShareHelper** will fail to be created and an error will be returned.|
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the **DataShareHelper** instance created. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700010 | The DataShareHelper is not initialized successfully. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { UIAbility } from '@kit.AbilityKit';

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let dataShareHelper: dataShare.DataShareHelper | undefined = undefined;
let context = getContext(UIAbility);
try {
  dataShare.createDataShareHelper(context, uri, {isProxy : true}, (err:BusinessError, data:dataShare.DataShareHelper) => {
    if (err !== undefined) {
      console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
      return;
    }
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`createDataShareHelper error: code: ${code}, message: ${message} `);
};
```
## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, options?: DataShareHelperOptions): Promise&lt;DataShareHelper&gt;

Creates a **DataShareHelper** instance. This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name | Type                                         | Mandatory| Description                          |
| ------- | ------------------------------------------------- | ---- | ------------------------------ |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context) | Yes  | Context of the application.            |
| uri     | string                                            | Yes  | URI of the server application to connect.|
| options<sup>10+</sup> | [DataShareHelperOptions](#datasharehelperoptions10) | No| Optional configuration of the **DataShareHelper** instance. It specifies whether [DataShareHelper](#datasharehelper) is in proxy mode and the waiting time for starting the data provider process in non-silent access mode.<br>If this parameter is not set, [DataShareHelper](#datasharehelper) is not in proxy mode and the waiting time for starting the data provider process in non-silent access mode is 2 seconds.<br>If the URI starts with **datashareproxy**, the **isProxy** parameter in **options** must be set. Otherwise, **DataShareHelper** will fail to be created and an error will be returned. |

**Return value**

| Type                                              | Description                                  |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;[DataShareHelper](#datasharehelper)&gt; | Promise used to return the **DataShareHelper** instance created.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700010 | The DataShareHelper is not initialized successfully. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { UIAbility } from '@kit.AbilityKit';

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let dataShareHelper: dataShare.DataShareHelper | undefined = undefined;
let context = getContext(UIAbility);
try {
  dataShare.createDataShareHelper(context, uri, {isProxy : true}).then((data: dataShare.DataShareHelper) => {
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
  }). catch((err: BusinessError) => {
    console.error(`createDataShareHelper error: code: ${err.code}, message: ${err.message} `);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`createDataShareHelper error: code: ${code}, message: ${message} `);
};
```

## dataShare.enableSilentProxy<sup>11+</sup>

enableSilentProxy(context: Context, uri?: string): Promise&lt;void&gt;

Enables silent access. This API uses a promise to return the result.

Observe the following when using this API:
 - The data provider calls this API to enable silent access.
 - Whether silent access is enabled is determined based on the return value of this API and the [isSilentProxyEnable](../../database/share-data-by-datashareextensionability.md) field in the **data_share_config.json** file together.
 - If silent access is enabled for a URI using this API, silent access takes effect when the related **datashareHelper** API is called. Otherwise, the setting of **isSilentProxyEnable** in the **data_share_config.json** file is used to determine whether to enable silent access.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                                                                                                                                                                                                                                              |
| ------- | ------------------------------------------------------- | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context) | Yes  | Context of the application.                                                                                                                                                                                                                                                                       |
| uri     | string                                                  | No  | URI of the data, for which silent access is to be enabled.<br>Global setting: If **uri** is **undefined** or **null** or is not specified, all the previous settings will be cleared and silent access will be enabled globally for the data provider.<br>URI-specific setting: If a URI is specified, silent access to the specified URI will be enabled.<br>When datashareHelper APIs are called, the URI-specific setting is preferentially applied. If no match is found, the global setting is applied.<br>URI format: **datashare:///{bundleName}/{moduleName}/{storeName}/{tableName}**|

**Return value**

| Type                                              | Description                                  |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;void&gt; | returns no value.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700011 | The URI is not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { UIAbility } from '@kit.AbilityKit';

let uri = ("datashare:///com.acts.datasharetest/entry/DB00/TBL00?Proxy=true");
let context = getContext(UIAbility);
dataShare.enableSilentProxy(context, uri).then(() => {
  console.info("enableSilentProxy succeed");
}). catch((err: BusinessError) => {
  console.error(`enableSilentProxy error: code: ${err.code}, message: ${err.message} `);
});
```

## dataShare.disableSilentProxy<sup>11+</sup>

disableSilentProxy(context: Context, uri?: string): Promise&lt;void&gt;

Disables silent access. This API uses a promise to return the result.

Observe the following when using this API:
 - The data provider calls this API to disable silent access.
 - Whether silent access is disabled is determined based on the return value of this API and the [isSilentProxyEnable](../../database/share-data-by-datashareextensionability.md) field in the **data_share_config.json** file together.
 - If silent access is disabled for a URI using this API, the setting takes effect when the related **datashareHelper** API is called. Otherwise, the setting of **isSilentProxyEnable** in the **data_share_config.json** file is used to determine whether to disable silent access.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                                                                                                                                                                                                                                            |
| ------- | ------------------------------------------------------- | ---- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context) | Yes  | Context of the application.                                                                                                                                                                                                                                                                     |
| uri     | string                                                  | No  | URI of the data, for which silent access is to be disabled.<br>Global setting: If **uri** is **undefined** or **null** or is not specified, all the previous settings will be cleared and silent access will be disabled globally for the data provider.<br>URI-specific setting: If a URI is specified, silent access to the specified URI will be disabled.<br>When datashareHelper APIs are called, the URI-specific setting is preferentially applied. If no match is found, the global setting is applied.<br>URI format: **datashare:///{bundleName}/{moduleName}/{storeName}/{tableName}**|

**Return value**

| Type                                              | Description                                  |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;void&gt; | returns no value.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700011 | The URI does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { UIAbility } from '@kit.AbilityKit';

let uri = ("datashare:///com.acts.datasharetest/entry/DB00/TBL00?Proxy=true");
let context = getContext(UIAbility);
dataShare.disableSilentProxy(context, uri).then(() => {
  console.info("disableSilentProxy succeed");
}). catch((err: BusinessError) => {
  console.error(`disableSilentProxy error: code: ${err.code}, message: ${err.message} `);
});
```

## DataShareHelperOptions<sup>10+</sup>

Represents the optional parameters of [DataShareHelper](#datasharehelper).

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| isProxy | boolean | No| Whether the [DataShareHelper](#datasharehelper) is in proxy mode.<br>The default value is **false**.<br>If the value is **true**, the [DataShareHelper](#datasharehelper) to be created is in proxy mode, and all operations will not open the data provider application unless the database does not exist. If the database does not exist, [createDataShareHelper](#datasharecreatedatasharehelper10) will start the data provider to create a database.|
| waitTime<sup>16+</sup> | number | No| Waiting time for starting the data provider process, in seconds.<br>The default value is **2**.|

## TemplateId<sup>10+</sup>

Defines the **TemplateId** struct. **TemplateId** is generated by [**addTemplate**](#addtemplate10) to identify a template.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| subscriberId | string | Yes| ID of the subscriber who handles the callback. The value must the same as the **subscriberId** in [**addTemplate**](#addtemplate10). The ID of each subscriber must be unique.|
| bundleNameOfOwner | string | Yes| Bundle name of the template owner. The value must be the same as the **bundleName** in [**addTemplate**](#addtemplate10).|

## PublishedItem<sup>10+</sup>

Defines the data to publish.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the data to publish.|
| data | string \| ArrayBuffer | Yes| Data to publish. If the data to publish exceeds 20 KB, you are advised to use the data in ArrayBuffer format.|
| subscriberId | string | Yes| Subscriber ID.|

## RdbDataChangeNode<sup>10+</sup>

Represents the RDB data change result. The data returned by the callback is not larger than 200 KB in size.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the callback.|
| templateId | [TemplateId](#templateid10) | Yes| ID of the template that triggers the callback.|
| data | Array&lt;string&gt; | Yes| Data of the callback. If an error occurs during callback data processing, the callback will not be triggered.|

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
| predicates | Record<string, string> | Yes| Predicates to use. When [**on**](#onrdbdatachange10) is called, the predicates are used to generate data. This parameter applies only to RDB data storage. |
| scheduler | string | Yes| Template scheduler SQL, which is embedded with a custom function. Currently, the **remindTimer** function is embedded. The **remindTimer** triggers a subscription-based update in specified scenarios.<br>The scheduler SQL statement is triggered when:<br>1. The subscribed data is modified.<br>2. The first subscription is added to the corresponding database.|
| update<sup>14+<sup> | string | No| Update SQL statement of a specified template. The default value is an empty string. When [on](#onrdbdatachange10) is called, the **update** parameter is used to update data. This parameter applies only to RDB data storage. |

## OperationResult<sup>10+</sup>

Defines the result of the operation for subscribing to or unsubscribing from the data changes or published data.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name| Type| Mandatory| Description|
| -------- | -------- | ----- | -------- |
| key | string | Yes| Key of the operation result.|
| result | number | Yes| Operation result. If the operation is successful, **0** is returned; otherwise, an error code is returned. |
## UpdateOperation<sup>12+</sup>

Represents the batch update operation information.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                        | Mandatory| Description          |
| ---------- | ------------------------------------------------------------ | ---- | -------------- |
| values     | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | Yes  | Data to be updated, which|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions for deleting the data.    |

## ChangeType<sup>12+</sup>

Enumerates the data change types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name    | Value         | Description         |
| ---------| ------------| --------------|
| INSERT   | 0           | Data is added.|
| DELETE   | 1           | Data is deleted.|
| UPDATE   | 2           | Data is updated.|

## SubscriptionType<sup>12+</sup>

Enumerates the data subscription types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name                       | Value  | Description                        |
| ----------------------------|------| ---------------------------- |
| SUBSCRIPTION_TYPE_EXACT_URI | 0    | Data change of the specified URI.|

## ChangeInfo<sup>12+</sup>

Represents the data change information, including the data change type, URI of the data changed, and changed data content.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                        | Mandatory| Description          |
| ---------- | ------------------------------------------------------------ | ---- | -------------- |
| type       | [ChangeType](#changetype12)      | Yes  | Data change type.|
| uri        | string                                                       | Yes  | URI of the data changed.     |
| values     | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt;| Yes  | Changed data.  |

## DataShareHelper

Provides a **DataShareHelper** instance to access or manage data on the server. Before calling an API provided by **DataShareHelper**, you must create a **DataShareHelper** instance using [createDataShareHelper](#datasharecreatedatasharehelper).

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback&lt;void&gt;): void

Subscribes to the data change of the specified URI. After an observer is registered, the subscriber will receive a notification when the **notifyChange()** API is called. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                   |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event/callback type. The value is **dataChange**, which indicates the data change.|
| uri      | string               | Yes  | URI of the data to be observed.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the data change. If the data is changed, **err** is **undefined**. Otherwise, this callback is not invoked or **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let onCallback: () => void = (): void => {
  console.info("**** Observer on callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper !== undefined) {
  (dataShareHelper as dataShare.DataShareHelper).on("dataChange", uri, onCallback);
}
```

### on('dataChange')<sup>12+</sup>

on(event: 'dataChange', type:SubscriptionType, uri: string, callback: AsyncCallback&lt;ChangeInfo&gt;): void

Subscribes to the data change of the specified URI. This API uses an asynchronous callback to return the result. After a change notification is registered, the subscriber will receive a notification when the **notifyChange()** API is called. The change notification contains the data change type, URI of the data changed, and the changed data.  Silent access is not supported.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                   |
| -------- | -------------------- | ---- | ------------------------ |
| event     | string               | Yes  | Event/callback type. The value is **dataChange**, which indicates the data change.|
| type     | [SubscriptionType](#subscriptiontype12)| Yes  | Subscription type.|
| uri      | string               | Yes  | URI of the data to be observed.|
| callback | AsyncCallback&lt;[ChangeInfo](#changeinfo12)&gt; | Yes  | Callback used to return the data change when the change notification is triggered.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.acts.datasharetest");
export function callback(error:BusinessError, ChangeInfo:dataShare.ChangeInfo) {
    console.info(' **** Observer callback **** ChangeInfo:' + JSON.stringify(ChangeInfo));
}
if (dataShareHelper !== undefined) {
  (dataShareHelper as dataShare.DataShareHelper).on('dataChange', dataShare.SubscriptionType.SUBSCRIPTION_TYPE_EXACT_URI, uri, callback);
}
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback&lt;void&gt;): void

Unsubscribes from the data change of the specified URI.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                   |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event/callback type. The value is **dataChange**, which indicates the data change.|
| uri      | string               | Yes  | URI of the data to be observed.|
| callback | AsyncCallback&lt;void&gt; | No  | Callback to unregister. If this parameter is **undefined**, **null**, or left empty, this API unregisters all callbacks for the specified URI.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let callback: () => void = (): void => {
  console.info("**** Observer on callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).on("dataChange", uri, callback);
  (dataShareHelper as dataShare.DataShareHelper).off("dataChange", uri, callback);
}
```


### off('dataChange')<sup>12+</sup>

off(event: 'dataChange', type:SubscriptionType, uri: string, callback?: AsyncCallback&lt;ChangeInfo&gt;): void

Unsubscribes from the data change of the specified URI. Silent access is not supported.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                   |
| -------- | -------------------- | ---- | ------------------------ |
| event     | string               | Yes  | Event or callback type. The value is **dataChange**, which indicates the data change.|
| type     | [SubscriptionType](#subscriptiontype12)| Yes  | Subscription type.|
| uri      | string               | Yes  | URI of the data to be observed.|
| callback | AsyncCallback&lt;[ChangeInfo](#changeinfo12)&gt;| No  | Callback to unregister. If this parameter is **undefined**, **null**, or left empty, this API unregisters all callbacks for the specified URI. If this parameter is specified, the callback must be the one registered in [on('datachange')](#ondatachange12).|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.acts.datasharetest");
export function callback(error:BusinessError, ChangeInfo:dataShare.ChangeInfo) {
    console.info(' **** Observer callback **** ChangeInfo:' + JSON.stringify(ChangeInfo));
}
if (dataShareHelper !== undefined) {
  (dataShareHelper as dataShare.DataShareHelper).on("dataChange", dataShare.SubscriptionType.SUBSCRIPTION_TYPE_EXACT_URI, uri, callback);
  (dataShareHelper as dataShare.DataShareHelper).off("dataChange", dataShare.SubscriptionType.SUBSCRIPTION_TYPE_EXACT_URI, uri, callback);
}
```

### addTemplate<sup>10+</sup>

addTemplate(uri: string, subscriberId: string, template: Template): void

Adds a data template with the specified subscriber.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                   | Mandatory| Description                    |
| -------- | ------------------------ | ---- | -------------------------|
| uri      | string                   | Yes  | URI of the data to add. |
| subscriberId | string               | Yes  | Unique ID of the template subscriber.|
| template    | [Template](#template10) | Yes  | Data template to add.       |

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700011 | The URI is not exist.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let subscriberId = '11';
let key1: string = "p1";
let value1: string = "select cityColumn as city_1, visitedCilumn as visited_1 from citys where like = true";
let key2: string = "p2";
let value2: string = "select cityColumn as city_2, visitedCilumn as visited_2 from citys where like = false";
let template: dataShare.Template = {
  predicates : {
    key1 : value1,
    key2 : value2,
  },
  scheduler : "select remindTimer(time) from TBL00",
  update : "update TBL00 set cityColumn = 'visited' where cityColumn = 'someCity'"
}
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).addTemplate(uri, subscriberId, template);
}
```

### delTemplate<sup>10+</sup>

delTemplate(uri: string, subscriberId: string): void

Deletes a data template based on the specified subscriber.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type       | Mandatory| Description                      |
| -------- | -------------| ---- | ------------------------- |
| uri      | string       | Yes  | URI of the data to delete.    |
| subscriberId | string   | Yes  | Unique ID of the subscriber.         |

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700011 | The URI is not exist.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let subscriberId = '11';
let key1: string = "p1";
let value1: string = "select cityColumn as city_1, visitedCilumn as visited_1 from citys where like = true";
let key2: string = "p2";
let value2: string = "select cityColumn as city_2, visitedCilumn as visited_2 from citys where like = false";
let template: dataShare.Template = {
  predicates : {
    key1 : value1,
    key2 : value2,
  },
  scheduler : "select remindTimer(time) from TBL00"
}
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).addTemplate(uri, subscriberId, template);
  (dataShareHelper as dataShare.DataShareHelper).delTemplate(uri, subscriberId);
}
```

### on('rdbDataChange')<sup>10+</sup>

on(type: 'rdbDataChange', uris: Array&lt;string&gt;, templateId: TemplateId, callback: AsyncCallback&lt;RdbDataChangeNode&gt;): Array&lt;OperationResult&gt;

Subscribes to the changes of the data corresponding to the specified URI and template.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                           | Mandatory| Description                                                        |
| -------- | ----------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                           | Yes  | Event type. The value is **rdbDataChange**, which indicates the change of the RDB data. If **type** is any other value, there is no response to this API. |
| uris    | Array&lt;string&gt;                | Yes  | URIs of the target data.          |
| templateId | [TemplateId](#templateid10)       | Yes  | ID of the template that triggers the callback.          |
| callback | AsyncCallback&lt;[RdbDataChangeNode](#rdbdatachangenode10)&gt;   | Yes  | Callback used to return the data change. If the operation is successful, **err** is **undefined** and **node** is the data changed. Otherwise, this callback is not invoked or **err** is an error object. |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let onCallback: (err: BusinessError, node: dataShare.RdbDataChangeNode) => void = (err: BusinessError, node:dataShare.RdbDataChangeNode): void => {
  console.info("onCallback " + JSON.stringify(node.uri));
  console.info("onCallback " + JSON.stringify(node.templateId));
  console.info("onCallback " + node.data.length);
  for (let i = 0; i < node.data.length; i++) {
    console.info("onCallback " + typeof node.data[i] + " " + node.data[i]);
  }
}

let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let templateId:dataShare.TemplateId = {subscriberId:"11", bundleNameOfOwner:"com.acts.ohos.data.datasharetest"};
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).on("rdbDataChange", [uri], templateId, onCallback);
}
```

### off('rdbDataChange')<sup>10+</sup>

off(type: 'rdbDataChange', uris: Array&lt;string&gt;, templateId: TemplateId, callback?: AsyncCallback&lt;RdbDataChangeNode&gt;): Array&lt;OperationResult&gt;

Unsubscribes from the changes of the data corresponding to the specified URI and template.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                       |
| -------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| type      | string                                      | Yes  | Event type. The value is **rdbDataChange**, which indicates the change of the RDB data.  |
| uris    | Array&lt;string&gt;                           | Yes  | URIs of the target data.          |
| templateId | [TemplateId](#templateid10)                | Yes  | ID of the template that triggers the callback.       |
| callback | AsyncCallback&lt;[RdbDataChangeNode](#rdbdatachangenode10)&gt; | No  | Callback to unregister. If this parameter is **undefined**, **null**, or left empty, this API unregisters all callbacks for the specified URI.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let uri = ("datashareproxy://com.samples.datasharetest.DataShare");
let templateId:dataShare.TemplateId = {subscriberId:"11", bundleNameOfOwner:"com.acts.ohos.data.datasharetest"};
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).off("rdbDataChange", [uri], templateId);
}
```

### on('publishedDataChange')<sup>10+</sup>

on(type: 'publishedDataChange', uris: Array&lt;string&gt;, subscriberId: string, callback: AsyncCallback&lt;PublishedDataChangeNode&gt;): Array&lt;OperationResult&gt;

Subscribes to the change of the published data.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                           | Mandatory| Description                                                        |
| -------- | ----------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                           | Yes  | Event type. The value is **publishedDataChange**, which indicates the change of the published data.|
| uris    | Array&lt;string&gt;                | Yes  | URIs of the target data.          |
| subscriberId | string                        | Yes  | Subscriber ID of the callback.          |
| callback | AsyncCallback&lt;[PublishedDataChangeNode](#publisheddatachangenode10)&gt;   | Yes  | Callback used to return the data change. If the operation is successful, **err** is **undefined** and **node** is the data changed. Otherwise, this callback is not invoked or **err** is an error object. |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let onPublishCallback: (err: BusinessError, node: dataShare.PublishedDataChangeNode) => void = (err: BusinessError, node:dataShare.PublishedDataChangeNode): void => {
  console.info("onPublishCallback node bundleName " + JSON.stringify(node.bundleName));
  console.info("onPublishCallback node data size" + node.data.length);
  for (let i = 0; i < node.data.length; i++) {
    console.info("onPublishCallback node " + typeof node.data[i].data);
    if (typeof node.data[i].data != 'string') {
      let array: ArrayBuffer = node.data[i].data as ArrayBuffer;
      let data: Uint8Array = new Uint8Array(array);
      console.info("onPublishCallback " + i + " " + JSON.stringify(data));
    }
    console.info("onPublishCallback data " + i + " " + JSON.stringify(node.data[i]));
  }
}
let uris:Array<string> = ['city', 'datashareproxy://com.acts.ohos.data.datasharetest/appInfo', 'key2'];
let subscriberId = '11';
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).on('publishedDataChange', uris, subscriberId, onPublishCallback);
}
```

### off('publishedDataChange')<sup>10+</sup>

off(type: 'publishedDataChange', uris: Array&lt;string&gt;, subscriberId: string, callback?: AsyncCallback&lt;PublishedDataChangeNode&gt;): Array&lt;OperationResult&gt;

Unsubscribes from the change of the published data.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                      |
| -------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| type      | string                                      | Yes  | Event type. The value is **publishedDataChange**, which indicates the change of the published data.|
| uris    | Array&lt;string&gt;                           | Yes  | URIs of the target data.          |
| subscriberId | string                                   | Yes  | Subscriber ID of the callback.          |
| callback | AsyncCallback&lt;[PublishedDataChangeNode](#publisheddatachangenode10)&gt; | No  | Callback to unregister. If this parameter is **undefined**, **null**, or left empty, this API unregisters all callbacks for the specified URI.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Array&lt;[OperationResult](#operationresult10)&gt; | Returns the operation result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let offCallback: (err: BusinessError, node: dataShare.PublishedDataChangeNode) => void = (err: BusinessError, node:dataShare.PublishedDataChangeNode): void => {
  console.info("**** Observer off callback ****");
}
let uris:Array<string> = ["city", "datashareproxy://com.acts.ohos.data.datasharetest/appInfo", "key2"];
let subscriberId = '11';
if (dataShareHelper != undefined) {
  let result: Array<dataShare.OperationResult> = (dataShareHelper as dataShare.DataShareHelper).off("publishedDataChange", uris, subscriberId, offCallback);
}
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
| version | number                                             | Yes  | Version of the data to publish. A larger value indicates a later version. If the version of the data published is earlier than that of the data in the database, the data in the database will not be updated.|
| callback | AsyncCallback&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | Yes  | Callback used to return the result. If data is published, **err** is **undefined**, and **result** is the data publish result. Otherwise, this callback is not triggered or **err** is an error object.   |

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700012 | The data area is not exist.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let arrayBuffer = new ArrayBuffer(1);
let version = 1;
let dataArray : Array<dataShare.PublishedItem> = [{key:"key2", subscriberId:"11", data:arrayBuffer}];
let publishCallback: (err: BusinessError, result: Array<dataShare.OperationResult>) => void = (err: BusinessError, result: Array<dataShare.OperationResult>): void => {
  console.info("publishCallback " + JSON.stringify(result));
}
try {
  console.info("dataArray length is:", dataArray.length);
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).publish(dataArray, "com.acts.ohos.data.datasharetest", version, publishCallback);
  }
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
| callback | AsyncCallback&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | Yes  | Callback used to return the result. If data is published, **err** is **undefined**, and **result** is the data publish result. Otherwise, this callback is not triggered or **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700012 | The data area is not exist.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let publishCallback: (err: BusinessError, result: Array<dataShare.OperationResult>) => void = (err: BusinessError, result: Array<dataShare.OperationResult>): void => {
  console.info("publishCallback " + JSON.stringify(result));
}
let dataArray : Array<dataShare.PublishedItem> = [
  {key:"city", subscriberId:"11", data:"xian"},
  {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
  {key:"empty", subscriberId:"11", data:"nobody sub"}];
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).publish(dataArray, "com.acts.ohos.data.datasharetest", publishCallback);
}
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
| version | number                         | No  | Version of the data to publish. A larger value indicates a later version. If the version of the data published is earlier than that of the data in the database, the data in the database will not be updated.<br> If the data version is not checked, leave this parameter unspecified.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[OperationResult](#operationresult10)&gt;&gt; | Returns the operation result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700012 | The data area is not exist.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let dataArray: Array<dataShare.PublishedItem> = [
  {key:"city", subscriberId:"11", data:"xian"},
  {key:"datashareproxy://com.acts.ohos.data.datasharetest/appInfo", subscriberId:"11", data:"appinfo is just a test app"},
  {key:"empty", subscriberId:"11", data:"nobody sub"}];
if (dataShareHelper != undefined) {
  let result: Promise<Array<dataShare.OperationResult>> = (dataShareHelper as dataShare.DataShareHelper).publish(dataArray, "com.acts.ohos.data.datasharetest");
}
```

### getPublishedData<sup>10+</sup>

getPublishedData(bundleName: string, callback: AsyncCallback&lt;Array&lt;PublishedItem&gt;&gt;): void

Obtains the published data of an application.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name   | Type            | Mandatory| Description                          |
| -------- | -----------------| ---- | ----------------------------- |
| bundleName | string         | Yes  | Application to which the data belongs. |
| callback | AsyncCallback&lt;Array&lt;[PublishedItem](#publisheditem10)&gt;&gt; | Yes  | Callback used to return the published data obtained.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700012 | The data area is not exist.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let publishCallback: (err: BusinessError, data: Array<dataShare.PublishedItem>) => void = (err: BusinessError, result: Array<dataShare.PublishedItem>): void => {
  console.info("**** Observer publish callback ****");
}
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).getPublishedData("com.acts.ohos.data.datasharetest", publishCallback);
}
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

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise&lt;Array&lt;[PublishedItem](#publisheditem10)&gt;&gt; | Promise used to return the published data obtained.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                   |
| -------- | -------------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700012 | The data area is not exist.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts 
if (dataShareHelper != undefined) {
  let publishedData: Promise<Array<dataShare.PublishedItem>> = (dataShareHelper as dataShare.DataShareHelper).getPublishedData("com.acts.ohos.data.datasharetest");
}
```

### insert

insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Inserts a single data record into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                     | Mandatory| Description                                                       |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                                    | Yes  | URI of the data to insert.                                    |
| value    | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | Yes  | Data to insert. If this parameter is left empty, a blank row will be inserted.          |
| callback | AsyncCallback&lt;number&gt;                               | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the index of the inserted data record. Otherwise, **err** is an error object.<br>The data index is not returned if the APIs of the database in use, for example, the key-value database (KVDB), do not support the return of indexes.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { ValuesBucket } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value1: string = "rose";
let key2: string = "age";
let value2: number = 22;
let key3: string = "salary";
let value3: number = 200.5;
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).insert(uri, valueBucket, (err: BusinessError, data: number) => {
      if (err !== undefined) {
        console.error(`insert error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("insert succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`insert error: code: ${code}, message: ${message} `);
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
| value | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | Yes  | Data to insert. If this parameter is left empty, a blank row will be inserted.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the index of the inserted data record.<br>The data index is not returned if the APIs of the database in use (for example, KVDB) do not support the return of indexes.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { ValuesBucket } from '@kit.ArkData'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value1: string = "rose1";
let key2: string = "age";
let value2: number = 21;
let key3: string = "salary";
let value3: number = 20.5;
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).insert(uri, valueBucket).then((data: number) => {
      console.info("insert succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`insert error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`insert error: code: ${code}, message: ${message} `);
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
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions for deleting the data.<br>The predicate methods supported by **delete()** vary depending on the database in use. For example, the KVDB supports only **inKeys**. If this parameter is left empty, the entire table will be deleted by default.|
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of deleted data records. Otherwise, **err** is an error object.<br>The number of deleted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).delete(uri, da, (err: BusinessError, data: number) => {
      if (err !== undefined) {
        console.error(`delete error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("delete succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`delete error: code: ${code}, message: ${message} `);
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
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions for deleting the data.<br>The predicate methods supported by **delete()** vary depending on the database in use. For example, the KVDB supports only **inKeys**. If this parameter is left empty, the entire table will be deleted by default.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of deleted data records.<br>The number of deleted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).delete(uri, da).then((data: number) => {
      console.info("delete succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`delete error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`delete error: code: ${code}, message: ${message} `);
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
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions for querying the data.<br>The predicate methods supported by **query()** vary depending on the database used. For example, the KVDB supports only **inKeys** and **prefixKey**. If this parameter is left empty, the entire table will be queried by default.|
| columns    | Array&lt;string&gt;                                          | Yes  | Column to query. If this parameter is left empty, all columns will be queried.              |
| callback   | AsyncCallback&lt;[DataShareResultSet](js-apis-data-DataShareResultSet-sys.md#datashareresultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the result set obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { dataSharePredicates, DataShareResultSet } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).query(uri, da, columns, (err: BusinessError, data: DataShareResultSet) => {
      if (err !== undefined) {
        console.error(`query error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("query succeed, rowCount : " + data.rowCount);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`query error: code: ${code}, message: ${message} `);
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
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions for querying the data.<br>The predicate methods supported by **query()** vary depending on the database used. For example, the KVDB supports only **inKeys** and **prefixKey**. If this parameter is left empty, the entire table will be queried by default.|
| columns    | Array&lt;string&gt;                                          | Yes  | Column to query. If this parameter is left empty, all columns will be queried.              |

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise&lt;[DataShareResultSet](js-apis-data-DataShareResultSet-sys.md#datashareresultset)&gt; | Promise used to return the result set obtained.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { dataSharePredicates, DataShareResultSet } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).query(uri, da, columns).then((data: DataShareResultSet) => {
      console.info("query succeed, rowCount : " + data.rowCount);
    }).catch((err: BusinessError) => {
      console.error(`query error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`query error: code: ${code}, message: ${message} `);
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
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions for updating the data.<br>The predicate methods supported by **update()** vary depending on the database in use. For example, only the relational database (RDB) supports predicates. If this parameter is left empty, the entire table will be updated by default.|
| value      | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | Yes  | New data, which can be null.                                 |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of updated data records. Otherwise, **err** is an error object.<br>The number of updated data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { dataSharePredicates, ValuesBucket } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
let key1: string = "name";
let value1: string = "roe1"
let key2: string = "age";
let value2: number = 21
let key3: string = "salary";
let value3: number = 20.5;
const va: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).update(uri, da, va, (err: BusinessError, data: number) => {
      if (err !== undefined) {
        console.error(`update error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("update succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`update error: code: ${code}, message: ${message} `);
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
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions for updating the data.<br>The predicate methods supported by **update()** vary depending on the database in use. For example, only the relational database (RDB) supports predicates. If this parameter is left empty, the entire table will be updated by default.|
| value      | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)    | Yes  | New data, which can be null.                                  |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of data records updated.<br>The number of updated data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { dataSharePredicates, ValuesBucket } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
let key1: string = "name";
let value1: string = "roe1"
let key2: string = "age";
let value2: number = 21
let key3: string = "salary";
let value3: number = 20.5;
const va: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
}
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).update(uri, da, va).then((data: number) => {
      console.info("update succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`update error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`update error: code: ${code}, message: ${message} `);
};
```

### batchUpdate<sup>12+</sup>

batchUpdate(operations: Record&lt;string, Array&lt;UpdateOperation&gt;&gt;): Promise&lt;Record&lt;string, Array&lt;number&gt;&gt;&gt;

Updates data in batches. A maximum of 900 KB data can be updated at a time. If the data volume exceeds 900 KB, the update will fail. The transaction of this API depends on the data provider. This API uses a promise to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                  |
| ---------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| operations | Record&lt;string, Array&lt;[UpdateOperation](#updateoperation12)&gt;&gt; | Yes  | Collection of the path of the data to update, update conditions, and new data.|

**Return value**

| Type                                                 | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Record&lt;string, Array&lt;number&gt;&gt;&gt; | Promise used to return an array of updated data records. The value **-1** means the update operation fails.<br>The number of updated data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | ------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700000 | Inner error.                         |
| 15700013 | The DataShareHelper instance is already closed. |

**Example**

```ts
import { dataSharePredicates, ValuesBucket } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let record: Record<string, Array<dataShare.UpdateOperation>> = {};
let operations1: Array<dataShare.UpdateOperation> = [];
let operations2: Array<dataShare.UpdateOperation> = [];

let pre1: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
pre1.equalTo("name", "ZhangSan");
let vb1: ValuesBucket = {
  "name": "ZhangSan1",
}
let operation1: dataShare.UpdateOperation = {
  values: vb1,
  predicates: pre1
}
operations1.push(operation1);

let pre2: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
pre2.equalTo("name", "ZhangSan2");
let vb2: ValuesBucket = {
  "name": "ZhangSan3",
}
let operation2: dataShare.UpdateOperation = {
  values: vb2,
  predicates: pre2
}
operations2.push(operation2);
record["uri1"] = operations1;
record["uri2"] = operations2;

try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).batchUpdate(record).then((data: Record<string, Array<number>>) => {
      // Traverse data to obtain the update result of each data record. value indicates the number of data records that are successfully updated. If value is less than 0, the update fails.
      let a = Object.entries(data);
      for (let i = 0; i < a.length; i++) {
        let key = a[i][0];
        let values = a[i][1]
        console.info(`Update uri:${key}`);
        for (const value of values) {
          console.info(`Update result:${value}`);
        }
      }
    }).catch((err: BusinessError) => {
      console.error(`Batch update error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Batch update error: code: ${code}, message: ${message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

Batch inserts data into the database. This API uses an asynchronous callback to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri      | string                                                       | Yes  | URI of the data to insert.                                    |
| values   | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | Yes  | Data to insert.                                          |
| callback | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of data records inserted. Otherwise, **err** is an error object.<br>The number of inserted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { ValuesBucket } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value11: string = "roe11"
let key2: string = "age";
let value21: number = 21;
let key3: string = "salary";
let value31: number = 20.5;
let valuesBucket1: ValuesBucket = {
  key1: value11,
  key2: value21,
  key3: value31,
}
let vbs = new Array(valuesBucket1);
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).batchInsert(uri, vbs, (err, data) => {
      if (err !== undefined) {
        console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
        return;
      }
      console.info("batchInsert succeed, data : " + data);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`batchInsert error: code: ${code}, message: ${message} `);
};
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

Batch inserts data into the database. This API uses a promise to return the result. Silent access is not supported currently.

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

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { ValuesBucket } from '@kit.ArkData'
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let key1: string = "name";
let value11: string = "roe11"
let key2: string = "age";
let value21: number = 21;
let key3: string = "salary";
let value31: number = 20.5;
let valuesBucket1: ValuesBucket = {
  key1: value11,
  key2: value21,
  key3: value31,
}
let vbs = new Array(valuesBucket1);
try {
  if (dataShareHelper != undefined) {
    (dataShareHelper as dataShare.DataShareHelper).batchInsert(uri, vbs).then((data: number) => {
      console.info("batchInsert succeed, data : " + data);
    }).catch((err: BusinessError) => {
      console.error(`batchInsert error: code: ${err.code}, message: ${err.message} `);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`batchInsert error: code: ${code}, message: ${message} `);
};
```

### close<sup>12+</sup>

close(): Promise &lt;void&gt;

Closes the **DataShareHelper** instance. After this API is called, the instance becomes invalid. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | returns no value.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID| Error Message    |
| -------- | ------------ |
| 15700000 | Inner error. |

**Example**

```ts
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).close();
}
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

Normalizes a **DataShare** URI. The **DataShare** URI can be used only by the local device, but the normalized URI can be used across devices. This API uses an asynchronous callback to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                  | Mandatory| Description                                                    |
| -------- | ---------------------- | ---- | -------------------------------------------------------- |
| uri      | string                 | Yes  | [URI](../apis-arkts/js-apis-uri.md#uri) to normalize.     |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the normalized URI (if **null** is returned, URI normalization is not supported). Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).normalizeUri(uri, (err: BusinessError, data: string) => {
    if (err !== undefined) {
      console.info("normalizeUri failed, error message : " + err);
    } else {
      console.info("normalizeUri = " + data);
    }
  });
}
```

### normalizeUri

normalizeUri(uri: string): Promise&lt;string&gt;

Normalizes a **DataShare** URI. The **DataShare** URI can be used only by the local device, but the normalized URI can be used across devices. This API uses a promise to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ---- | ------ | ---- | ----------------------------------------- |
| uri  | string | Yes  | [URI](../apis-arkts/js-apis-uri.md#uri) to normalize.|

**Return value**

| Type            | Description                                          |
| ---------------- | ---------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. If URI normalization is supported, the normalized URI is returned. Otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).normalizeUri(uri).then((data: string) => {
    console.info("normalizeUri = " + data);
  }).catch((err: BusinessError) => {
    console.info("normalizeUri failed, error message : " + err);
  });
}
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

Denormalizes a URI. This API uses an asynchronous callback to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | Yes  | [URI](../apis-arkts/js-apis-uri.md#uri) to denormalize.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the URI obtained. If the original URI is returned, denormalization is not required. If **null** is returned, denormalization is not supported. If the operation fails, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).denormalizeUri(uri, (err: BusinessError, data: string) => {
    if (err !== undefined) {
      console.error("denormalizeUri failed, error message : " + err);
    } else {
      console.info("denormalizeUri = " + data);
    }
  });
}
```

### denormalizeUri

denormalizeUri(uri: string): Promise&lt;string&gt;

Denormalizes a URI. This API uses a promise to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                                       |
| ---- | ------ | ---- | ------------------------------------------- |
| uri  | string | Yes  | [URI](../apis-arkts/js-apis-uri.md#uri) to denormalize.|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. If the denormalization is successful, the URI obtained is returned. If no operation is required, the original URI is returned. If denormalization is not supported, **null** is returned.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).denormalizeUri(uri).then((data: string) => {
    console.info("denormalizeUri = " + data);
  }).catch((err: BusinessError) => {
    console.error("denormalizeUri failed, error message : " + err);
  });
}
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback&lt;void&gt;): void

Notifies the registered observer of data changes. This API uses an asynchronous callback to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name   | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the observer is notified of the data changes, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Mandatory parameters are left unspecified.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).notifyChange(uri, () => {
    console.info("***** notifyChange *****");
  });
}
```

### notifyChange

notifyChange(uri: string): Promise&lt;void&gt;

Notifies the registered observer of data changes. This API uses a promise to return the result. Silent access is not supported currently.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                |
| ---- | ------ | ---- | -------------------- |
| uri  | string | Yes  | URI of the data.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Mandatory parameters are left unspecified.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
let uri = ("datashare:///com.samples.datasharetest.DataShare");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).notifyChange(uri);
}
```

### notifyChange<sup>12+</sup>

notifyChange(data: ChangeInfo): Promise&lt;void&gt;

Notifies the observer of the data change of the specified URI. This API uses a promise to return the result. Silent access is not supported.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                |
| ---- | ------ | ---- | -------------------- |
| data  | [ChangeInfo](#changeinfo12) | Yes  | Information about the data change type, URI of the data changed, and changed data.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise&lt;void&gt; |  returns no value.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message             |
| -------- | -------------------- |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 15700013 | The DataShareHelper instance is already closed.|

**Example**

```ts
import { ValuesBucket } from '@kit.ArkData'

let dsUri = ("datashare:///com.acts.datasharetest");
let bucket1: ValuesBucket = {"name": "LiSi"};
let bucket2: ValuesBucket = {"name": "WangWu"};
let bucket3: ValuesBucket = {"name": "ZhaoLiu"};
let people: Array<ValuesBucket> = new Array(bucket1, bucket2, bucket3);
let changeData:dataShare.ChangeInfo= { type:dataShare.ChangeType.INSERT, uri:dsUri, values:people};
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).notifyChange(changeData);
}
```
