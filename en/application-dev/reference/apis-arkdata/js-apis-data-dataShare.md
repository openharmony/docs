# @ohos.data.dataShare (DataShare)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @woodenarow-->
<!--Designer: @woodenarow; @xuelei3-->
<!--Tester: @chenwan188; @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=e4f6de7bd3d29f75145b4739bb4953e93b1f39e5 translatedAt=2026-08-17T10:26:20.313Z pushedAt=2026-08-17T10:54:27.459Z -->

The **DataShare** module allows an app to manage its own data and share data with other apps on the same device.

> **NOTE**
>
> - The initial APIs of this module are supported since <!--RP1-->API version 9<!--RP1End-->. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { dataShare } from '@kit.ArkData';
```

## dataShare.createDataProxyHandle<sup>20+</sup>

createDataProxyHandle(): Promise&lt;DataProxyHandle&gt;

Creates a **DataProxyHandle** instance. This API uses a promise to return the result.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

**Return value**

| Type                                              | Description                                  |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;[DataProxyHandle](#dataproxyhandle20)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally. |

**Example:**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    dataShare.createDataProxyHandle().then((dataProxyHandle) => {
      console.info("createDataProxyHandle succeed");
    }).catch((err: BusinessError) => {
      console.error(`Failed to create DataProxyHandle. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## ChangeType<sup>20+</sup>

Enumerates the data change types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name    | Value         | Description         |
| ---------| ------------| --------------|
| INSERT   | 0           | Data is inserted.|
| DELETE   | 1           | Data is deleted.|
| UPDATE   | 2           | Data is updated.|

## ProxyData<sup>20+</sup>

Defines a struct for shared configurations.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                        | Read-Only| Optional| Description          |
| ---------- | ----------------------------------------------------------- | ----| ---- | -------------- |
| uri        | string                                                      | No| No | Unique ID of a shared configuration, fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application. The value is a string with a maximum of 256 bytes.|
| value      | [ValueType](js-apis-data-valuesBucket.md#valuetype)         | No  | Yes   | Value of the share configuration. If not specified, an empty string is used.<br/>**NOTE**<br/>1. Before API version 26.0.0, the string length cannot exceed 4096 bytes. Since API version 26.0.0, the default maximum string length allowed is 4096 bytes. You can configure maxValueLength in [DataProxyConfig](#dataproxyconfig20) to extend the maximum length to 102400 bytes.<br/>2. When the share configuration is published for the first time, if this parameter is not specified, it is set to an empty string by default. When the share configuration is updated, if this parameter is not specified, the value of the share configuration will not be updated.     |
| allowList  | string\[]                                         | No  | Yes   | List of apps that are allowed to subscribe to and read the share configuration. If not specified, an empty string array is used. The maximum length of the array is 256, and elements beyond 256 do not take effect. When the share configuration is published for the first time, if this parameter is not specified, an empty allowlist is used by default. When the share configuration is updated, if this parameter is not specified, the allowlist of the share configuration will not be updated. An empty allowlist indicates that only the publisher can access the share configuration. <br/>Before API version 26.0.0, each element in the array is the [appIdentifier](../../quick-start/common-problem-of-application.md#what-is-appidentifier) of an app. The maximum length of a single appIdentifier is 128 bytes, and an appIdentifier longer than 128 bytes does not take effect.<br/>Since API version 26.0.0, the array supports the special string "all" (case-sensitive), which indicates that all apps are allowed to access.|
| isMultiValues      | boolean         | No  | Yes   | Whether the share configuration is a multi-value type that uses values. The value **true** indicates that the data published this time is of the multi-value type, in which case the value parameter is ignored. The value **false** indicates a non-multi-value type. The default value is **false**. <br/>**Since:** 26.0.0 |
| values      | Record&lt;number, [ValueType](js-apis-data-valuesBucket.md#valuetype)&gt;         | No  | Yes   | Value of the multi-value type. The first parameter in Record is the key, which is specified by the user and must be unique. The second parameter is the value corresponding to the key. A single app can add up to 10 values under a single URI, and the maximum length of each value is 4096 bytes. In addition, the total length of all values is limited by the maxValueLength field in [DataProxyConfig](#dataproxyconfig20). This parameter takes effect only when isMultiValues is set to **true**, and it cannot be empty. When isMultiValues is **false**, the default value is undefined. <br/>**Since:** 26.0.0 |
| trustProviders      | string[]         | No  | Yes   | List of apps that can assign values to the multi-value share configuration. The array can contain up to 256 elements, and elements beyond 256 do not take effect. Each element in the array is the [appIdentifier](../../quick-start/common-problem-of-application.md#what-is-appidentifier) of an app. The maximum length of an appIdentifier is 128 bytes, and the part longer than 128 bytes does not take effect.<br/>If this parameter is not set when the share configuration is published for the first time, the assignment list is empty by default. An empty assignment list indicates that only the publisher can assign values to the multi-value share configuration. The array supports the special string "all" (case-sensitive), which indicates that all apps are allowed to assign values to the multi-value share configuration. This parameter takes effect only when isMultiValues is set to **true**.<br/>**Since:** 26.0.0 |

## DataProxyChangeInfo<sup>20+</sup>

Defines a struct for notifying subscribers of the shared configuration changes, including data change type, URI, and content.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                        | Read-Only| Optional| Description          |
| ---------- | ----------------------------------------------------------- | ----| ---- | -------------- |
| type       | [ChangeType](#changetype20)                                | No| No   | Data change type.|
| uri       | string                                                        | No | No    | URI for notifying the change. The fixed format is `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundle name of the publisher application of the configuration, and path can be any value but must not be duplicated within the same app. The string length cannot exceed 256 bytes.|
| value     | [ValueType](js-apis-data-valuesBucket.md#valuetype)             | No| No    | Changed data.    |
| values     | [ValueType](js-apis-data-valuesBucket.md#valuetype)[]          | No | Yes     | Change data of the multi-value type. If the changed data type is not a multi-value type, the value of **values** is undefined.<br/>**Since:** 26.0.0     |

## DataProxyErrorCode<sup>20+</sup>

Enumerates the status code returned by the batch operations of shared configuration.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Value                                                         | Description          |
| ---------- | ----------------------------------------------------------| -------------- |
| SUCCESS        | 0                                                       | The operation is successful.|
| URI_NOT_EXIST  | 1                                                       | The URI does not exist or the URI is not subscribed to.|
| NO_PERMISSION  | 2                                                       | No permission to perform this operation on the URI.|
| OVER_LIMIT     | 3                                                       | Before API version 26.0.0, indicates that the configurations published by the current app exceed the upper limit of 32 configurations; from API version 26.0.0, indicates that the configurations published by the current app exceed the upper limit of 64 configurations, or the value of the obtained share configuration item exceeds the maximum length limit configured by the maxValueLength field in [DataProxyConfig](#dataproxyconfig20).  |

## DataProxyResult<sup>20+</sup>

Defines a struct for the batch operation result of shared configuration.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                        | Read-Only| Optional| Description          |
| ---------- | ----------------------------------------------------------- | ---- | ---- | -------------- |
| uri        | string                                                      | No| No  | URI to be operated, with a maximum of 256 bytes. The value is fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application.|
| result  |  [DataProxyErrorCode](#dataproxyerrorcode20)                   | No| No  | Operation result code.|

## DataProxyGetResult<sup>20+</sup>

Defines a struct for obtaining the batch operation result of shared configuration.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                        | Read-Only| Optional| Description          |
| ---------- | ----------------------------------------------------------- | ---- | ---- | -------------- |
| uri        | string                                                      | No| No| URI to be operated, with a maximum of 256 bytes. The value is fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application.|
| result  |  [DataProxyErrorCode](#dataproxyerrorcode20)                   | No| No| Operation result code.|
| value  |  [ValueType](js-apis-data-valuesBucket.md#valuetype) \| undefined  | No| No| If the operation is successful, the value is the one set in shared configuration; otherwise, the value is undefined.|
| allowList  |  string\[] \| undefined                             | No| No  | If the operation is successful, the allowlist is the one set in shared configuration; otherwise, the allowlist is undefined. Only the publisher can obtain the allowlist. Other applications can obtain only the value.|

## DataProxyType<sup>20+</sup>

Enumerates the data proxy types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Value                                                        | Description          |
| ---------- | ---------------------------------------------------------| -------------- |
| SHARED_CONFIG  | 0                                                   | Inter-application shared configuration.|

## DataProxyConfig<sup>20+</sup>

Defines a struct for the data proxy configuration.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                         | Read-Only| Optional| Description          |
| ---------- | ----------------------------------------------------------- | ---- | ---- | -------------- |
| type      | [DataProxyType](#dataproxytype20)                            | No| No  | Type of the data proxy.|
| maxValueLength  | [DataProxyMaxValueLength](#dataproxymaxvaluelength)  | No | Yes   | Maximum length allowed for the value of the share configuration. If not specified, the default value is MAX_LENGTH_4K, that is, the maximum length allowed for the value of the share configuration is 4096 bytes.<br/>**Since:** 26.0.0 |

## DataProxyMaxValueLength

Enumerates the maximum length allowed for the value of a [share configuration](#proxydata20).

**Since:** 26.0.0

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

| Name       | Value                                                         | Description           |
| ---------- | ---------------------------------------------------------| -------------- |
| MAX_LENGTH_4K  | 4096                                                 | Indicates that the maximum length allowed for the value of a share configuration is 4096 bytes. |
| MAX_LENGTH_100K  | 102400                                             | Indicates that the maximum length allowed for the value of a share configuration is 102400 bytes. |

## DataProxyHandle<sup>20+</sup>

Defines the data proxy handle, which can be used to access or manage shared configuration information. Before calling an API provided by **DataProxyHandle**, you must create a **DataProxyHandle** instance using [createDataProxyHandle](#datasharecreatedataproxyhandle20).

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

### on('dataChange')<sup>20+</sup>

on(event: 'dataChange', uris: string[], config: DataProxyConfig, callback: AsyncCallback&lt;DataProxyChangeInfo[]&gt;): DataProxyResult[]

Subscribes to the change event of the shared configuration corresponding to a specified URI. If the change event is subscribed, the subscriber will receive a callback notification that carries the data change type, changed URI, and changed content when the publisher modifies the configuration. This API uses an asynchronous callback to return the result. This function does not support cross-user notification subscription or subscription to unpublished configurations. If the permission is revoked after the subscription is successful, the subscriber will not be notified consequently.

**Paired call**

- After subscribing, you must call [off('dataChange')](#offdatachange20) to unsubscribe when it is no longer needed.

- When unsubscribing, ensure that the event, uris, config, and callback parameters are the same as those used for subscription.

- Failure to unsubscribe may cause memory leaks and resource occupation.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| event     | string                        | Yes  | Event or callback type. The value is **dataChange**, which indicates the data change. This event is triggered when the publisher modifies the configuration.|
| uris     | string\[]             | Yes   | URI array of the share configurations to subscribe to.<br/>**NOTE**<br/>1. Before API version 26.0.0, the maximum length of the array is 32. Since API version 26.0.0, the maximum length of the array is 64.<br/>2. The URI is in the fixed format `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundle name of the publisher application of the configuration, and path can be any value but must be unique within the same app. The string length cannot exceed 256 bytes. |
| config      | [DataProxyConfig](#dataproxyconfig20)               | Yes   | Configuration of the data proxy operation. Since API version 26.0.0, when the length of the changed share configuration content exceeds the maximum length limit configured by the maxValueLength field in [DataProxyConfig](#dataproxyconfig20), the share configuration content is truncated. |
| callback | AsyncCallback&lt;[DataProxyChangeInfo](#dataproxychangeinfo20)\[]&gt; | Yes   | Callback invoked to return the result. If the subscription is successful, err is undefined and data is the obtained array of DataProxyChangeInfo objects, which contains the change type, URI, and changed share configuration content. Otherwise, err is an error object. |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| [DataProxyResult](#dataproxyresult20)\[] | Batch operation result array.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID| Error Message             |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally.|
| 15700014 | The parameter format is incorrect or the value range is invalid.|

**Example:**

```ts
const urisToWatch: string[] =
  ['datashareproxy://com.example.app1/config1', 'datashareproxy://com.example.app1/config2',];
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
const callback = (err: BusinessError<void>, changes: dataShare.DataProxyChangeInfo[]): void => {
  if (err) {
    console.error(`Failed to receive data change notification. Code: ${err.code}, message: ${err.message}`);
  } else {
    changes.forEach((change) => {
      console.info(`Change Type: ${change.type}, URI: ${change.uri}, Value: ${change.value}`);
    });
  }
};
const results: dataShare.DataProxyResult[] = dataProxyHandle.on('dataChange', urisToWatch, config, callback);
results.forEach((result) => {
  console.info(`URI: ${result.uri}, Result: ${result.result}`);
});
```

### off('dataChange')<sup>20+</sup>

off(event: 'dataChange', uris: string[], config: DataProxyConfig, callback?: AsyncCallback&lt;DataProxyChangeInfo[]&gt;): DataProxyResult[]

Unsubscribes from the change event of the proxy data corresponding to a specified URI.

**Paired call**

- This API must be used after [on('dataChange')](#ondatachange20) is called to subscribe.

- When unsubscribing, ensure that the event, uris, and config parameters are the same as those used for subscription.

- If the callback parameter is not specified, all registered callbacks of the URI are unsubscribed.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| event     | string                        | Yes  | Event or callback type. The value is **dataChange**, which indicates the data change.|
| uris     | string\[]             | Yes   | Array of URIs corresponding to the share configurations to unsubscribe from.<br/>**NOTE**<br/>1. Before API version 26.0.0, the maximum length of the array is 32; from API version 26.0.0, the maximum length of the array is 64.<br/>2. The URI is in the fixed format of `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundleName of the publisher app of the configuration, path can be any value but must be unique within the same app, and the string length cannot exceed 256 bytes. |
| config      | [DataProxyConfig](#dataproxyconfig20)               | Yes  | Data proxy configuration.|
| callback | AsyncCallback&lt;[DataProxyChangeInfo](#dataproxychangeinfo20)\[]&gt; | No   | Callback to unsubscribe. If this parameter is not specified, all registered callbacks are unsubscribed.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| [DataProxyResult](#dataproxyresult20)\[] | Batch operation result array.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID| Error Message             |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally.|
| 15700014 | The parameter format is incorrect or the value range is invalid.|

**Example:**

```ts
const urisToUnWatch: string[] =
  ['datashareproxy://com.example.app1/config1', 'datashareproxy://com.example.app1/config2',];
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
const callback = (err: BusinessError<void>, changes: dataShare.DataProxyChangeInfo[]): void => {
  if (err) {
    console.error(`Failed to receive data change notification. Code: ${err.code}, message: ${err.message}`);
  } else {
    changes.forEach((change) => {
      console.info(`Change Type: ${change.type}, URI: ${change.uri}, Value: ${change.value}`);
    });
  }
};
const results: dataShare.DataProxyResult[] = dataProxyHandle.off('dataChange', urisToUnWatch, config, callback);
results.forEach((result) => {
  console.info(`URI: ${result.uri}, Result: ${result.result}`);
});
```

### publish<sup>20+</sup>

publish(data: ProxyData[], config: DataProxyConfig): Promise&lt;DataProxyResult[]&gt;

Publishes share configuration items. This API uses a promise to return the result.

After publication, the publisher and the apps specified in the allowlist can access the share configuration items.

If the URI to be published already exists, the corresponding share configuration item is updated. If the length of any URI in the configuration items to be published exceeds the upper limit or the format verification fails, the current publish operation fails.

Only the publisher is allowed to update share configuration items.

Before API version 26.0.0, each app supports a maximum of 32 share configurations. Since API version 26.0.0, each app supports a maximum of 64 share configurations.

Since API version 26.0.0, publishing multi-value type configurations is supported, and a URI can correspond to only one value type. After a configuration is published, the publish API cannot be used to update a published multi-value type URI. For the APIs for operating multi-value types, see [putValue](#putvalue), [removeValue](#removevalue), and [getValues](#getvalues).

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| data     | [ProxyData](#proxydata20)\[]       | Yes   | Array of share configuration items to be created or updated. Before API version 26.0.0, the maximum length of the array is 32; since API version 26.0.0, the maximum length of the array is 64. |
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes   | Configuration of the data proxy operation. Since API version 26.0.0, if the length of any value in the published configuration items exceeds the maximum length limit configured by the maxValueLength field in [DataProxyConfig](#dataproxyconfig20), the current publish operation fails. |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;[DataProxyResult](#dataproxyresult20)\[]&gt; | Promise used to return the result array of the batch operations.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID| Error Message             |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally.|
| 15700014 | The parameter format is incorrect or the value range is invalid.|

**Example:**

```ts
const newConfigData: dataShare.ProxyData[] = [{
  uri: 'datashareproxy://com.example.app1/config1',
  value: 'Value1',
  allowList: ['appIdentifier2', 'appIdentifier3'], // The string here is only an example. Replace it with the actual appIdentifier of the app when using it.
}, {
  uri: 'datashareproxy://com.example.app1/config2',
  value: 'Value2',
  allowList: ['appIdentifier3', 'appIdentifier4'], // The string here is only an example. Replace it with the actual appIdentifier of the app when using it.
}];
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
dataProxyHandle.publish(newConfigData, config).then((results: dataShare.DataProxyResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to publish config. code: ${error.code}, message: ${error.message}`);
});
```

### delete<sup>20+</sup>

delete(uris: string[], config: DataProxyConfig): Promise&lt;DataProxyResult[]&gt;

Deletes the specified shared configuration items based on URIs. This API uses a promise to return the result. Only the publisher is allowed to delete shared configuration items.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| uris     | string\[]          | Yes   | Array of URIs corresponding to the share configurations to be deleted.<br/>**NOTE**<br/>1. Before API version 26.0.0, the maximum length of the array is 32; starting from API version 26.0.0, the maximum length of the array is 64.<br/>2. The URI is in the fixed format of `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundle name of the publisher app of the configuration, and path can be set to any value but must be unique within the same app. The string length cannot exceed 256 bytes. |
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes  | Data proxy configuration.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;[DataProxyResult](#dataproxyresult20)\[]&gt; | Promise used to return the result array of the batch operations.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID| Error Message             |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally.|
| 15700014 | The parameter format is incorrect or the value range is invalid.|

**Example:**

```ts
const urisToDelete: string[] =
  ['datashareproxy://com.example.app1/config1', 'datashareproxy://com.example.app1/config2',];
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
dataProxyHandle.delete(urisToDelete, config).then((results: dataShare.DataProxyResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to delete config. code: ${error.code}, message: ${error.message}`);
});
```

### deleteMyPublishedData

deleteMyPublishedData(config: DataProxyConfig): Promise&lt;DataProxyResult[]&gt;

Deletes all share configuration items published by the current publisher. This API uses a promise to return the result. Only the configuration publisher can delete share configuration items.

**Since:** 26.0.0

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name     | Type                        | Mandatory | Description                    |
| -------- | ----------------------------- | ---- | ------------------------ |
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes   | Configuration of the data proxy operation. |

**Return value**

| Type             | Description                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;[DataProxyResult](#dataproxyresult20)\[]&gt; | Promise used to return the result. Returns an array of batch operation results.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID | Error Message              |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally. |
| 15700014 | The parameter format is incorrect or the value range is invalid. |

**Example**

```ts
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
dataProxyHandle.deleteMyPublishedData(config).then((results: dataShare.DataProxyResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to delete all configs. Code: ${error.code}, message: ${error.message}`);
});
```

### get<sup>20+</sup>

get(uris: string[], config: DataProxyConfig): Promise&lt;DataProxyGetResult[]&gt;

Obtains a specified shared configuration item based on the URI. This API uses a promise to return the result. Only the publisher and applications in the allowed list can access the shared configuration item.

**System capability:** SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| uris     | string\[]         | Yes   | Array of URIs of the share configurations to obtain.<br/>**NOTE**<br/>1. Before API version 26.0.0, the maximum length of the array is 32; since API version 26.0.0, the maximum length of the array is 64.<br/>2. The URI is in the fixed format `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundle name of the publisher app of the configuration, and path can be any value but must be unique within the same app. The string length cannot exceed 256 bytes. |
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes   | Configuration of the data proxy operation. Since API version 26.0.0, the length of the value of the obtained share configuration item cannot exceed the maximum length limit configured by the maxValueLength field in [DataProxyConfig](#dataproxyconfig20). If the limit is exceeded, the status code of the return value of the corresponding operation result [DataProxyErrorCode](#dataproxyerrorcode20) is OVER_LIMIT. |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;[DataProxyGetResult](#dataproxygetresult20)\[]&gt; | Promise used to return the result array of the batch operations.|

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID| Error Message             |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally.|
| 15700014 | The parameter format is incorrect or the value range is invalid.|

**Example:**

```ts
const urisToGet: string[] =
  ['datashareproxy://com.example.app1/config1', 'datashareproxy://com.example.app1/config2',];
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
dataProxyHandle.get(urisToGet, config).then((results: dataShare.DataProxyGetResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}, AllowList: ${result.allowList}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to get config. code: ${error.code}, message: ${error.message}`);
});
```

### putValue

putValue(uri: string, key: number, value: ValueType, config: DataProxyConfig): Promise&lt;void&gt;

Writes a value to the published data. This operation can be performed only on multi-value type data. This API uses a promise to return the result.

If the key passed in does not exist, a new value is added. If the key already exists, the value corresponding to the key is updated.

By default, a single data item (that is, a URI) can have a maximum of 10 values added in a single app, and the maximum length of each value is 4096 bytes. In addition, the total length of all values of a single data item (that is, a URI) in a single app is limited by the maxValueLength parameter value specified when the data is published using [publish](#publish20).

**Since:** 26.0.0

**System capability:**  SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name     | Type                        | Mandatory | Description                    |
| -------- | ----------------------------- | ---- | ------------------------ |
| uri      | string   | Yes   | URI corresponding to the data to be operated. The fixed format is `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundle name of the publisher application, and path can be set arbitrarily but must not be duplicated within the same app. The string length cannot exceed 256 bytes. |
| key      | number   | Yes   | Key corresponding to the value to be added, which is unique for the same app.<br>The value range is all integers. |
| value    | [ValueType](js-apis-data-valuesBucket.md#valuetype)  | Yes | Value to be added.|
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes   | Configuration of the data proxy operation. The maxValueLength parameter in the configuration does not take effect. |

**Return value**

| Type             | Description                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID | Error Message              |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally. |
| 15700011 | The URI does not exist. |
| 15700014 | The parameter format is incorrect or the value range is invalid. |
| 15700015 | No permission to access the data specified by the URI. |

**Example**

```ts
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
let testUri: string = 'datashareproxy://com.test.dataproxyhandle/test/pv/001';
let newConfigData: dataShare.ProxyData[] = [{
  uri: testUri,
  values: { 0: 'init' },
  isMultiValues: true,
  allowList: [],
  trustProviders: []
}];

await dataProxyHandle?.publish(newConfigData, config).then((results: dataShare.DataProxyResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to publish config. code: ${error.code}, message: ${error.message}`);
});

try {
  await dataProxyHandle?.putValue(testUri, 1, 'hello', config);
  console.info(`putValue success`);
} catch (error) {
  console.error(`putValue failed: code: ${error.code}, message: ${error.message}`);
}
```

### removeValue

removeValue(uri: string, key: number, config: DataProxyConfig): Promise&lt;void&gt;

Removes the value corresponding to the key. This operation can be performed only on multi-value type data. Only values added by the current app can be removed. This API uses a promise to return the result.

**Since:** 26.0.0

**System capability:**  SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name     | Type                        | Mandatory | Description                    |
| -------- | ----------------------------- | ---- | ------------------------ |
| uri      | string   | Yes   | URI corresponding to the data to be operated. The fixed format is `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundle name of the publisher application, and path can be set arbitrarily but must not be duplicated within the same app. The string length cannot exceed 256 bytes. |
| key      | number   | Yes   | Key corresponding to the value to be added. <br>The value range is all integers. |
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes   | Configuration of the data proxy operation. |

**Return value**

| Type             | Description                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID | Error Message              |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally. |
| 15700011 | The URI does not exist. |
| 15700014 | The parameter format is incorrect or the value range is invalid. |
| 15700015 | No permission to access the data specified by the URI. |

**Example**

```ts
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
let testUri: string = 'datashareproxy://com.test.dataproxyhandle/test/pv/001';
let newConfigData: dataShare.ProxyData[] = [{
  uri: testUri,
  values: { 0: 'init' },
  isMultiValues: true,
  allowList: [],
  trustProviders: []
}];

await dataProxyHandle?.publish(newConfigData, config).then((results: dataShare.DataProxyResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to publish config. code: ${error.code}, message: ${error.message}`);
});

try {
  await dataProxyHandle?.removeValue(testUri, 0, config);
  console.info(`removeValue success`);
} catch (error) {
  console.error(`removeValue failed: code: ${error.code}, message: ${error.message}`);
}
```

### getValues

getValues(uri: string, config: DataProxyConfig): Promise&lt;ValueType[]&gt;

Obtains all multi-value type data under the specified URI. Only the publisher and the apps in the [allowList](#proxydata20) can obtain this data. This API uses a promise to return the result.

**Since:** 26.0.0

**System capability:**  SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name     | Type                        | Mandatory | Description                    |
| -------- | ----------------------------- | ---- | ------------------------ |
| uri      | string   | Yes   | URI corresponding to the data to be operated. The fixed format is `"datashareproxy://{bundleName}/{path}"`, where bundleName is the bundle name of the publisher application, and path can be set arbitrarily but must not be duplicated within the same app. The string length cannot exceed 256 bytes. |
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes   | Configuration of the data proxy operation. |

**Return value**

| Type             | Description                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;[ValueType](js-apis-data-valuesBucket.md#valuetype)[]&gt; | Promise used to return the result. Returns an array of all values under the URI. |

**Error codes**

For details about the error codes, see [DataShare Error Codes](errorcode-datashare.md).

| ID | Error Message              |
| -------- | -------------------- |
| 15700000 | Inner error. Possible causes: The service is not ready or is being restarted abnormally. |
| 15700011 | The URI does not exist. |
| 15700014 | The parameter format is incorrect or the value range is invalid. |
| 15700015 | No permission to access the data specified by the URI. |

**Example**

```ts
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
let testUri: string = 'datashareproxy://com.test.dataproxyhandle/test/pv/001';
let newConfigData: dataShare.ProxyData[] = [{
  uri: testUri,
  values: { 0: 'init' },
  isMultiValues: true,
  allowList: [],
  trustProviders: []
}];

await dataProxyHandle!.publish(newConfigData, config).then((results: dataShare.DataProxyResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to publish config. code: ${error.code}, message: ${error.message}`);
});

try {
  let result: ValueType[] = await dataProxyHandle?.getValues(testUri, config);
  console.info(`getValues success. Values: ` + JSON.stringify(result));
} catch (error) {
  console.error(`getValues failed: code: ${error.code}, message: ${error.message}`);
}
```