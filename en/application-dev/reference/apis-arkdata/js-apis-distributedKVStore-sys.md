# @ohos.data.distributedKVStore (Distributed KV Store) (System API)

The **distributedKVStore** module implements collaboration between databases for different devices that forms a Super Device. You can use the APIs provided by this module to save application data to a distributed key-value (KV) store and perform operations, such as adding, deleting, modifying, querying, and synchronizing data in distributed KV stores.

The **distributedKVStore** module provides the following functionalities:

- [KVManager](js-apis-distributedKVStore.md#kvmanager): provides a **KVManager** instance to obtain KV store information.
- [KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset): provides APIs for accessing the results obtained from a KV store.
- [Query](js-apis-distributedKVStore.md#query): provides APIs for setting predicates for data query.
- [SingleKVStore](#singlekvstore): provides APIs for querying and synchronizing data in single KV stores. The single KV stores manage data without distinguishing devices.
- [DeviceKVStore](#devicekvstore): provides APIs for querying and synchronizing data in device KV stores. This class inherits from [SingleKVStore](#singlekvstore). The device KV stores manage data by device.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.data.distributedKVStore](js-apis-distributedKVStore.md).

## Modules to Import

```ts
import { distributedKVStore } from '@kit.ArkData';
```

## SingleKVStore

Implements data management in a single KV store, such as adding data, deleting data, and subscribing to data changes or data sync completion.

Before calling **SingleKVStore** APIs, you need to use [getKVStore](js-apis-distributedKVStore.md#getkvstore) to create a **SingleKVStore** instance.

### putBatch

putBatch(value: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;void&gt;): void

Writes batch data to this single KV store. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                    | Mandatory| Description              |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| value    | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | Yes  | Data to write.|
| callback | AsyncCallback&lt;void&gt;                                     | Yes  | Callback used to return the result.        |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                            |
| ------------ | ---------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| ID| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ValuesBucket } from '@kit.ArkData';

try {
  let bucket1: ValuesBucket = {key:"name", value: "LiSi"};
  let bucket2: ValuesBucket = {key:"age", value: 20};
  let bucket3: ValuesBucket = {key:"deposits", value: 12.34};
  let people: Array<ValuesBucket> = new Array(bucket1, bucket2, bucket3)
  kvStore.putBatch(people, (err: BusinessError) => {
    if (err != undefined) {
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in putting batch');
  })
} catch (e) {
  let error = e as BusinessError;
  console.error(`Failed to do putBatch error.code is ${error.code},message is ${error.message}`);
}
```

### putBatch

putBatch(value: Array&lt;ValuesBucket&gt;): Promise&lt;void&gt;

Writes batch data to this single KV store. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type                                                    | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | Yes  | Data to write.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                            |
| ------------ | ---------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| ID| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ValuesBucket } from '@kit.ArkData';

try {
  let bucket1: ValuesBucket = {key:"name", value: "LiSi"};
  let bucket2: ValuesBucket = {key:"age", value: 20};
  let bucket3: ValuesBucket = {key:"deposits", value: 12.34};
  let people: Array<ValuesBucket> = new Array(bucket1, bucket2, bucket3)
  kvStore.putBatch(people).then(() => {
    console.info(`Succeeded in putting patch`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to do putBatch error.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`Failed to do putBatch error.code is ${error.code},message is ${error.message}`);
}
```

### delete

delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;void&gt;)

Deletes KV pairs from this KV store. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the KV pairs to delete. If this parameter is **null**, define the processing logic.|
| callback   | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result.                                     |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                    |
| 15100005    | Database or result set already closed. |

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| ID| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let predicates = new dataSharePredicates.DataSharePredicates();
  let arr = ["name"];
  predicates.inKeys(arr);
  kvStore.put("name", "bob", (err:BusinessError) => {
    if (err != undefined) {
      console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info("Succeeded in putting");
    if (kvStore != null) {
      kvStore.delete(predicates, (err:BusinessError) => {
        if (err == undefined) {
          console.info('Succeeded in deleting');
        } else {
          console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);
        }
      });
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);
}
```

### delete

delete(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;void&gt;

Deletes KV pairs from this KV store. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the KV pairs to delete. If this parameter is **null**, define the processing logic.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                            |
| ------------ | ---------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100003     | Database corrupted.                      |
| 15100005     | Database or result set already closed.   |

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| ID| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let predicates = new dataSharePredicates.DataSharePredicates();
  let arr = ["name"];
  predicates.inKeys(arr);
  kvStore.put("name", "bob").then(() => {
    console.info(`Succeeded in putting data`);
    if (kvStore != null) {
      kvStore.delete(predicates).then(() => {
        console.info('Succeeded in deleting');
      }).catch((err: BusinessError) => {
        console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified conditions. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.             |
| callback   | AsyncCallback&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt;   | Yes  | Callback used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err != undefined) {
      console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err != undefined) {
          console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('Succeeded in closing result set');
      });
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified conditions. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the KV pairs to delete. If this parameter is **null**, define the processing logic.|

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt; | Promise used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates).then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing result set');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
  });

} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

## DeviceKVStore

Provides APIs for querying and synchronizing data in a device KV store. This class inherits from **SingleKVStore**.

Data is distinguished by device in a device KV store. Each device can only write and modify its own data. Data of other devices is read-only and cannot be modified.

For example, a device KV store can be used to implement image sharing between devices. The images of other devices can be viewed, but not be modified or deleted.

Before calling **DeviceKVStore** APIs, you need to use [getKVStore](js-apis-distributedKVStore.md#getkvstore) to create a **DeviceKVStore** instance.

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified conditions for this device. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.             |
| callback   | AsyncCallback&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt;   | Yes  | Callback used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err != undefined) {
      console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err != undefined) {
          console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('Succeeded in closing result set');
      })
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified conditions for this device. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the KV pairs to delete. If this parameter is **null**, define the processing logic.|

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt; | Promise used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet(predicates).then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing result set');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified conditions for a device. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> **deviceId** can be obtained by [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).
> For details about how to obtain **deviceId**, see the example of [sync](js-apis-distributedKVStore.md#sync).

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId  | string                                                       | Yes  | ID of the target device.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.             |
| callback   | AsyncCallback&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt;   | Yes  | Callback used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet('localDeviceId', predicates, async (err: BusinessError, result: distributedKVStore.KVStoreResultSet) => {
    if (err != undefined) {
      console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet, (err: BusinessError) => {
        if (err != undefined) {
          console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('Succeeded in closing result set');
      })
    }
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```

### getResultSet

getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified conditions for a device. This API uses a promise to return the result.
> **NOTE**
>
> **deviceId** can be obtained by [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).
> For details about how to obtain **deviceId**, see the example of [sync](js-apis-distributedKVStore.md#sync).

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| deviceId  | string                                                       | Yes  | ID of the target device.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the KV pairs to delete. If this parameter is **null**, define the processing logic.|

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](js-apis-distributedKVStore.md#kvstoreresultset)&gt; | Promise used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](errorcode-distributedKVStore.md).

| ID| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401          | Parameter error.Possible causes:1.Mandatory parameters are left unspecified; 2.Incorrect parameters types.|
| 202          | Permission verification failed, application which is not a system application uses system API.|
| 15100001     | Upper limit exceeded.                  |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let resultSet: distributedKVStore.KVStoreResultSet;
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.prefixKey("batch_test_string_key");
  kvStore.getResultSet('localDeviceId', predicates).then((result: distributedKVStore.KVStoreResultSet) => {
    console.info('Succeeded in getting result set');
    resultSet = result;
    if (kvStore != null) {
      kvStore.closeResultSet(resultSet).then(() => {
        console.info('Succeeded in closing result set');
      }).catch((err: BusinessError) => {
        console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
      });
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
  });
} catch (e) {
  let error = e as BusinessError;
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);
}
```
