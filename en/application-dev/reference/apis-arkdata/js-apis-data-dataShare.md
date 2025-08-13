# @ohos.data.dataShare (DataShare)

The **DataShare** module allows an application to manage its own data and share data with other applications on the same device.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import { dataShare } from '@kit.ArkData';
```


## dataShare.createDataProxyHandle<sup>20+</sup>

createDataProxyHandle(): Promise&lt;DataProxyHandle&gt;

Creates a **DataProxyHandle** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

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
      console.error(`createDataProxyHandle error: code: ${err.code}, message: ${err.message}`);
    });
  };
};
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
| uri        | string                                                      | No| No | Unique ID of a shared configuration, fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application. The value is a string with a maximum of 255 bytes.|
| value      | [ValueType](js-apis-data-valuesBucket.md#valuetype)         | No| Yes  | Value of a shared configuration. If not specified, the value is an empty string. The value is a string with a maximum of 4096 bytes. If this parameter is not set when the shared configuration is published for the first time, the value will be an empty string by default. If this parameter is not set when a shared configuration is updated, the value of the shared configuration will not be updated.    |
| allowList  | string\[]                                         | No| Yes  | List of applications that can subscribe to and read shared configurations. If this parameter is left empty, the value is an empty string array. The array can contain a maximum of 256 elements. Excess elements are invalid. Each element in the array is the **appIdentifier** of an application. The maximum length of a single **appIdentifier** is 128 bytes and the excess value is invalid. If this parameter is not set when the shared configuration is published for the first time, the allowlist is empty by default. If this parameter is not set when the shared configuration is updated, the allowlist will not be updated. An empty allowlist indicates that only the publisher can access the shared configuration. |

## DataProxyChangeInfo<sup>20+</sup>

Defines a struct for notifying subscribers of the shared configuration changes, including data change type, URI, and content.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Type                                                        | Read-Only| Optional| Description          |
| ---------- | ----------------------------------------------------------- | ----| ---- | -------------- |
| type       | [ChangeType](#changetype20)                                | No| No   | Data change type.|
| uri       | string                                                        | No| No   | URI to change.|
| value     | [ValueType](js-apis-data-valuesBucket.md#valuetype)             | No| No    | Changed data.    |

## DataProxyErrorCode<sup>20+</sup>

Enumerates the status code returned by the batch operations of shared configuration.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

| Name      | Value                                                         | Description          |
| ---------- | ----------------------------------------------------------| -------------- |
| SUCCESS        | 0                                                       | The operation is successful.|
| URI_NOT_EXIST  | 1                                                       | The URI does not exist or the URI is not subscribed to.|
| NO_PERMISSION  | 2                                                       | No permission to perform this operation on the URI.|
| OVER_LIMIT     | 3                                                       | The number of configurations published by the current application exceeds the upper limit of 32. |

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


## DataProxyHandle<sup>20+</sup>

Defines the data proxy handle, which can be used to access or manage shared configuration information. Before calling an API provided by **DataProxyHandle**, you must create a **DataProxyHandle** instance using [createDataProxyHandle](#datasharecreatedataproxyhandle20).

### on('dataChange')<sup>20+</sup>

on(event: 'dataChange', uris: string[], config: DataProxyConfig, callback: AsyncCallback&lt;DataProxyChangeInfo[]&gt;): DataProxyResult[]

Subscribes to the change event of the shared configuration corresponding to a specified URI. If the change event is subscribed, the subscriber will receive a callback notification that carries the data change type, changed URI, and changed content when the publisher modifies the configuration. This API uses an asynchronous callback to return the result. This function does not support cross-user notification subscription or subscription to unpublished configurations. If the permission is revoked after the subscription is successful, the subscriber will not be notified consequently.

When the configuration publisher calls the [publish](#publish20) or [delete](#delete20) API to publish or delete a configuration, a notification is automatically triggered.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| event     | string                        | Yes  | Event or callback type. The value is **dataChange**, which indicates the data change. This event is triggered when the configuration publisher modifies the configuration.|
| uris     | string\[]             | Yes  | Array of URIs to be subscribed, with a maximum of 32 URIs. The value is fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application.|
| config      | [DataProxyConfig](#dataproxyconfig20)               | Yes  | Data proxy configuration.|
| callback | AsyncCallback&lt;[DataProxyChangeInfo](#dataproxychangeinfo20)\[]&gt; | Yes  | Callback triggered when the publisher modifies the configuration.|

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
    console.error('err:', err);
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

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| event     | string                        | Yes  | Event or callback type. The value is **dataChange**, which indicates the data change.|
| uris     | string\[]             | Yes  | Array of URIs to be unsubscribed, with a maximum of 32 URIs. The value is fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application.|
| config      | [DataProxyConfig](#dataproxyconfig20)               | Yes  | Data proxy configuration.|
| callback | AsyncCallback&lt;[DataProxyChangeInfo](#dataproxychangeinfo20)\[]&gt; | No  | Callback to unregister. If the value is empty, undefined, or null, all notifications of the URIs are unsubscribed.|

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
    console.error('err:', err);
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

Publishes shared configuration items. After the publish, the publisher and the applications in the allowlist can access these items. If the URI to be published already exists, the corresponding shared configuration item is updated. If any URI in the configuration item to be published exceeds the maximum length or fails the format verification, the current publish operation fails. Only the publisher can update shared configuration items. Each application supports a maximum of 32 shared configurations.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| data     | [ProxyData](#proxydata20)\[]       | Yes  | Array of shared configuration items to be created or updated, with a maximum of 32 items.|
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
const newConfigData: dataShare.ProxyData[] = [{
  uri: 'datashareproxy://com.example.app1/config1',
  value: 'Value1',
  allowList: ['com.example.app2', 'com.example.app3'],
}, {
  uri: 'datashareproxy://com.example.app1/config2',
  value: 'Value2',
  allowList: ['com.example.app3', 'com.example.app4'],
},];
const config: dataShare.DataProxyConfig = {
  type: dataShare.DataProxyType.SHARED_CONFIG,
};
dataProxyHandle.publish(newConfigData, config).then((results: dataShare.DataProxyResult[]) => {
  results.forEach((result) => {
    console.info(`URI: ${result.uri}, Result: ${result.result}`);
  });
}).catch((error: BusinessError) => {
  console.error('Error publishing config:', error);
});
```

### delete<sup>20+</sup>

delete(uris: string[], config: DataProxyConfig): Promise&lt;DataProxyResult[]&gt;

Deletes the specified shared configuration items based on the URI. Only the publisher can delete the shared configuration items.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| uris     | string\[]          | Yes  | URI array of the shared configuration items to be deleted, with a maximum of 32 URIs. The value is fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application.|
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes  | Shared configuration type.|

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
  console.error('Error deleting config:', error);
});
```

### get<sup>20+</sup>

get(uris: string[], config: DataProxyConfig): Promise&lt;DataProxyGetResult[]&gt;

Obtains a specified shared configuration item based on the URI. Only the publisher and applications in the allowed list can access the shared configuration item.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                       | Mandatory| Description                   |
| -------- | ----------------------------- | ---- | ------------------------ |
| uris     | string\[]         | Yes  | URI array of the shared configuration items to be obtained, with a maximum of 32 URIs. The value is fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application.|
| config   | [DataProxyConfig](#dataproxyconfig20)   | Yes  | Shared configuration type.|

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
  console.error('Error getting config:', error);
});
```
