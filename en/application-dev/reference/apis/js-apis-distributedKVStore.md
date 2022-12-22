# # @ohos.data.distributedKVStore 

The **distributedKVStore** module implements collaboration between databases for different devices that forms a Super Device. The APIs provided by this module can be used to save data to a distributed key-value (KV) store and perform operations, such as adding, deleting, modifying, querying, and synchronizing data in distributed KV stores.

The **distributedKVStore** module provides the following functions:

- [KVManager](#kvmanager): provides a **KVManager** instance to obtain KV store information.
- [KVStoreResultSet](#kvstoreresultset): provides APIs for obtaining KV store result sets.
- [Query](#query): provides APIs for setting predicates and querying data using predicates.
- [SingleKVStore](#singlekvstore): provides APIs for querying data in single KV stores and synchronizing data. The single KV stores manage data without distinguishing devices.
- [DeviceKVStore](#devicekvstore): provides APIs for querying in device KV stores and synchronizing data. This class inherits from [SingleKVStore](#singlekvstore). The device KV stores manage data by device.

> **NOTE**<br/>
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import distributedKVStore from '@ohos.data.distributedKVStore';
```

## KVManagerConfig

Provides the **KVManager** instance configuration, including the bundle name of the invoker and the application context.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name    | Type             | Mandatory| Description                                                        |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| context    | Context               | Yes  |Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).|
| bundleName | string                | Yes  | Bundle name.                                              |

## Constants

Provides constants of the distributed KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name                 | Value     | Description                                   |
| --------------------- | ------- | --------------------------------------- |
| MAX_KEY_LENGTH        | 1024    | Maximum length of a key in the distributed KV store, in bytes.  |
| MAX_VALUE_LENGTH      | 4194303 | Maximum length of a value in the distributed KV store, in bytes.|
| MAX_KEY_LENGTH_DEVICE | 896     | Maximum length of a device key, in bytes.           |
| MAX_STORE_ID_LENGTH   | 128     | Maximum length of a KV store ID, in bytes. |
| MAX_QUERY_LENGTH      | 512000  | Maximum query length, in bytes.               |
| MAX_BATCH_SIZE        | 128     | Maximum number of batch operations.                   |

## ValueType

Enumerates the data types.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name      | Description                  |
| ---------- | ---------------------- |
| STRING     | String.  |
| INTEGER    | Integer.    |
| FLOAT      | Float (single-precision floating point).  |
| BYTE_ARRAY | Byte array.|
| BOOLEAN    | Boolean.  |
| DOUBLE     | Double (double-precision floating point).|

## Value

Defines the **value** object in a KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type  |Mandatory | Description                   |
| ----- | -------   |-----|------------------------ |
| type | [ValueType](#valuetype) | Yes|Type of the value.  |
| value | Uint8Array \| string \| number \| boolean| Yes|Value of the KV pair stored in the KV store.  |

## Entry

Defines the KV pairs stored in the KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type       | Mandatory| Description    |
| ----- | --------------- | ---- | -------- |
| key   | string          | Yes  | Key of the KV pair stored in the KV store.  |
| value | [Value](#value) | Yes  | Value of the KV pair stored in the KV store.|

## ChangeNotification

Defines the content of a data change notification, including inserted data, updated data, deleted data, and device ID.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name         | Type         | Mandatory      | Description                    |
| ------------- | ----------------- | ---- | ------------------------ |
| insertEntries | [Entry](#entry)[] | Yes  | Data inserted.          |
| updateEntries | [Entry](#entry)[] | Yes  | Data updated.          |
| deleteEntries | [Entry](#entry)[] | Yes   | Data deleted.          |
| deviceId      | string            | Yes   | UUID of the device.|

## SyncMode

Enumerates the synchronization modes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name     | Description                                                |
| --------- | ---------------------------------------------------- |
| PULL_ONLY | Pull data from the peer end to the local end only.                      |
| PUSH_ONLY | Push data from the local end to the peer end only.                      |
| PUSH_PULL | Push data from the local end to the peer end and then pull data from the peer end to the local end.|

## SubscribeType

Enumerates the subscription types.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name                 | Description                        |
| --------------------- | ---------------------------- |
| SUBSCRIBE_TYPE_LOCAL  | Local data changes.      |
| SUBSCRIBE_TYPE_REMOTE | Remote data changes.      |
| SUBSCRIBE_TYPE_ALL    | Local and remote data changes.|

## KVStoreType

Enumerates the distributed KV store types.

| Name                | Description                                                        |
| -------------------- | ------------------------------------------------------------ |
| DEVICE_COLLABORATION | Device KV store.<br> The device KV store manages data by device, which eliminates conflicts. Data can be queried by device.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore|
| SINGLE_VERSION       | Single KV store.<br> The single KV store does not differentiate data by device. If the same key is modified by different devices, the data will be overwritten.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|

## SecurityLevel

Enumerates the KV store security levels.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name       | Description                                                        |
| -------:   | ------------------------------------------------------------ |
| S1         | The KV store security level is low. If data leakage occurs, minor impact will be caused on the database. For example, a KV store that contains system data such as wallpapers.|
| S2         | The KV store security level is medium. If data leakage occurs, moderate impact will be caused on the database. For example, a KV store that contains information created by users or call records, such as audio or video clips.|
| S3         |  The KV store security level is high. If data leakage occurs, major impact will be caused on the database. For example, a KV store that contains information such as user fitness, health, and location data.|
| S4         |  The KV store security level is critical. If data leakage occurs, severe impact will be caused on the database. For example, a KV store that contains information such as authentication credentials and financial data.|

## Options

Provides KV store configuration.

| Name         | Type                       | Mandatory| Description                                                        |
| --------------- | -------------- | ---- | -------------------------|
| createIfMissing | boolean                         | No | Whether to create a KV store if no database file exists. By default, a KV store is created.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| encrypt         | boolean                         | No  | Whether to encrypt database files. By default, database files are not encrypted.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| backup          | boolean                         | No  | Whether to back up database files. By default, database files are backed up. <br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| autoSync        | boolean                         | No  | Whether database files are automatically synchronized. By default, database files are not automatically synchronized.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core<br>**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC|
| kvStoreType     | [KVStoreType](#kvstoretype)     | No  | Type of the KV store to create. By default, a device KV store is created. The device KV store stores data for multiple devices that collaborate with each other.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| securityLevel   | [SecurityLevel](#securitylevel) | Yes  |Security level of the KV store.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| schema          | [Schema](#schema)               | No  | Schema used to define the values stored in the KV store. By default, **schema** is not used.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore|

## Schema

Defines the schema of a KV store. You can create a **Schema** object and place it in [Options](#options) when creating or opening a KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| Name   | Type                   | Readable| Writable| Description                      |
| ------- | ----------------------- | ---- | ---- | -------------------------- |
| root    | [FieldNode](#fieldnode) | Yes  | Yes  | JSON root object.          |
| indexes | Array\<string>          | Yes  | Yes  | String array in JSON format.|
| mode    | number                  | Yes  | Yes  | Schema mode.        |
| skip    | number                  | Yes  | Yes  | Size of a skip of the schema.        |

### constructor

constructor()

A constructor used to create a **Schema** instance.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

## FieldNode

Represents a **Schema** instance, which provides the methods for defining the values stored in a KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| Name    | Type   | Readable| Writable| Description                          |
| -------- | ------- | ---- | ---- | ------------------------------ |
| nullable | boolean | Yes  | Yes  | Whether the database field can be null.  |
| default  | string  | Yes  | Yes  | Default value of a **FieldNode**.       |
| type     | number  | Yes  | Yes  | Value of the data type corresponding to the specified node.|

### constructor

constructor(name: string)

A constructor used to create a **FieldNode** instance with a string field.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name| Type| Mandatory| Description           |
| ------ | -------- | ---- | --------------- |
| name   | string   | Yes  | Value of **FieldNode**.|

### appendChild

appendChild(child: FieldNode): boolean

Appends a child node to this **FieldNode**.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name| Type               | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| child  | [FieldNode](#fieldnode) | Yes  | Child node to append.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
import ddm from '@ohos.data.distributedKVStore';

try {
    let node = new ddm.FieldNode("root");
    let child1 = new ddm.FieldNode("child1");
    let child2 = new ddm.FieldNode("child2");
    let child3 = new ddm.FieldNode("child3");
    node.appendChild(child1);
    node.appendChild(child2);
    node.appendChild(child3);
    console.log("appendNode " + JSON.stringify(node));
    child1 = null;
    child2 = null;
    child3 = null;
    node = null;
} catch (e) {
    console.log("AppendChild " + e);
}
```

## distributedKVStore.createKVManager

createKVManager(config: KVManagerConfig, callback: AsyncCallback&lt;KVManager&gt;): void

Creates a **KVManager** instance to manage KV stores. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                       |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------------------- |
| config   | [KVManagerConfig](#kvmanagerconfig)          | Yes  | **KVManager** instance configuration, including the bundle name of the invoker and the context of the application.|
| callback | AsyncCallback&lt;[KVManager](#kvmanager)&gt; | Yes  | Callback invoked to return the **KVManager** instance created.                    |

**Example**

Stage model:

```js
import AbilityStage from '@ohos.application.Ability'
let kvManager;
export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
        let context = this.context
        const kvManagerConfig = {
            context: context,
            bundleName: 'com.example.datamanagertest',
        }
        try {
            distributedKVStore.createKVManager(kvManagerConfig, function (err, manager) {
                if (err) {
                    console.error(`Failed to create KVManager.code is ${err.code},message is ${err.message}`);
                    return;
                }
                console.log("Created KVManager successfully");
                kvManager = manager;
            });
        } catch (e) {
            console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
        }
    }
}
```

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility'
let kvManager;
let context = featureAbility.getContext()
const kvManagerConfig = {
    context: context,
    bundleName: 'com.example.datamanagertest',
}
try {
    distributedKVStore.createKVManager(kvManagerConfig, function (err, manager) {
        if (err) {
            console.error(`Failed to create KVManager.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log("Created KVManager successfully");
        kvManager = manager;
    });
} catch (e) {
    console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
}
```

## distributedKVStore.createKVManager

createKVManager(config: KVManagerConfig): Promise&lt;KVManager&gt;

Creates a **KVManager** instance to manage KV stores. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type                     | Mandatory| Description                                                     |
| ------ | ----------------------------- | ---- | --------------------------------------------------------- |
| config | [KVManagerConfig](#kvmanager) | Yes  | Configuration of the **KVManager** instance, including the bundle name and user information of the caller.|

**Return value**

| Type                                  | Description                                      |
| -------------------------------------- | ------------------------------------------ |
| Promise&lt;[KVManager](#kvmanager)&gt; | Promise used to return the **KVManager** instance created.|

**Example**

Stage model:

```js
import AbilityStage from '@ohos.application.Ability'
let kvManager;
export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
        let context = this.context
        const kvManagerConfig = {
            context: context,
            bundleName: 'com.example.datamanagertest',
        }
        try {
            distributedKVStore.createKVManager(kvManagerConfig).then((manager) => {
                console.log("Created KVManager successfully");
                kvManager = manager;
            }).catch((err) => {
                console.error(`Failed to create KVManager.code is ${err.code},message is ${err.message}`);
            });
        } catch (e) {
            console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
        }
    }
}
```

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility'
let kvManager;
let context = featureAbility.getContext()
const kvManagerConfig = {
    context: context,
    bundleName: 'com.example.datamanagertest',
}
try {
    distributedKVStore.createKVManager(kvManagerConfig).then((manager) => {
        console.log("Created KVManager successfully");
        kvManager = manager;
    }).catch((err) => {
        console.error(`Failed to create KVManager.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
}
```

## KVManager

Provides an instance to obtain information about a distributed KV store. Before calling any API in **KVManager**, you must use [createKVManager](#distributedkvstorecreatekvmanager) to create a **KVManager** instance.

### getKVStore

getKVStore&lt;T &gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void

Creates and obtains a distributed KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type              | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| storeId  | string                 | Yes  | Unique identifier of the KV store. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| options  | [Options](#options)    | Yes  | Configuration of the KV store to create.                              |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback invoked to return the distributed single or device KV store created. |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| ID| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 15100002     | Open existed database with changed options. |
| 15100003     | Database corrupted.                         |

**Example**

```js
let kvStore;
let kvManager;
try {
    const options = {
        createIfMissing: true,
        encrypt: false,
        backup: false,
        autoSync: true,
        kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
        securityLevel: distributedKVStore.SecurityLevel.S2,
    };
    kvManager.getKVStore('storeId', options, function (err, store) {
        if (err) {
            console.error(`Fail to get KVStore.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log("Obtained the KVStore successfully.");
        kvStore = store;
    });
} catch (e) {
    console.log(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### getKVStore

getKVStore&lt;T &gt;(storeId: string, options: Options): Promise&lt;T&gt;

Creates and obtains a distributed KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type           | Mandatory| Description                                                        |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| storeId | string              | Yes  | Unique identifier of the KV store. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| options | [Options](#options) | Yes  | Configuration of the distributed KV store to create.                              |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;T&gt; | Promise used to return the distributed single or device KV store created.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| ID| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 15100002     | Open existed database with changed options. |
| 15100003     | Database corrupted.                         |

**Example**

```js
let kvStore;
let kvManager;
try {
    const options = {
        createIfMissing: true,
        encrypt: false,
        backup: false,
        autoSync: true,
        kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
        securityLevel: distributedKVStore.SecurityLevel.S2,
    };
    kvManager.getKVStore('storeId', options).then((store) => {
        console.log("Obtained the KVStore successfully.");
        kvStore = store;
    }).catch((err) => {
        console.error(`Fail to get KVStore.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.log(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### closeKVStore

closeKVStore(appId: string, storeId: string, callback: AsyncCallback&lt;void&gt;): void

Closes a distributed KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| appId    | string                    | Yes  | Bundle name of the app that invokes the KV store.                                      |
| storeId  | string                    | Yes  | Unique identifier of the KV store to close. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                                  |

**Example**

```js
let kvStore;
let kvManager;
const options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: true,
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
    schema: '',
    securityLevel: distributedKVStore.SecurityLevel.S2,
}
try {
    kvManager.getKVStore('storeId', options, async function (err, store) {
        console.log('Obtained the KVStore successfully.');
        kvStore = store;
        kvManager.closeKVStore('appId', 'storeId', function (err, data) {
            if (err != undefined) {
                console.error(`Fail to close KVStore.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Closed the KVStore successfully.');
        });
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### closeKVStore

closeKVStore(appId: string, storeId: string): Promise&lt;void&gt;

Closes a distributed KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory| Description                                                        |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| appId   | string   | Yes  | Bundle name of the app that invokes the KV store.                                      |
| storeId | string   | Yes  | Unique identifier of the KV store to close. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
let kvManager;
let kvStore;
const options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: true,
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
    schema: '',
    securityLevel: distributedKVStore.SecurityLevel.S2,
}
try {
    kvManager.getKVStore('storeId', options).then(async (store) => {
        console.log('Obtained the KVStore successfully.');
        kvStore = store;
        kvManager.closeKVStore('appId', 'storeId').then(() => {
            console.log('Closed the KVStore successfully.');
        }).catch((err) => {
            console.error(`Fail to close KVStore.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to get KVStore.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to close KVStore.code is ${e.code},message is ${e.message}`);
}
```

### deleteKVStore

deleteKVStore(appId: string, storeId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a distributed KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| appId    | string                    | Yes  | Bundle name of the app that invokes the KV store.                                      |
| storeId  | string                    | Yes  | Unique identifier of the KV store to delete. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                                  |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**|
| ------------ | ------------ |
| 15100004     | Not found.   |

**Example**

```js
let kvManager;
let kvStore;
const options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: true,
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
    schema: '',
    securityLevel: distributedKVStore.SecurityLevel.S2,
}
try {
    kvManager.getKVStore('store', options, async function (err, store) {
        if (err != undefined) {
            console.error(`Fail to get KVStore.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Obtained the KVStore successfully.');
        kvStore = store;
        kvManager.deleteKVStore('appId', 'storeId', function (err, data) {
            if (err != undefined) {
                console.error(`Fail to delete KVStore.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log(`Deleted the KVStore successfully.`);
        });
    });
} catch (e) {
    console.error(`Fail to delete KVStore.code is ${e.code},message is ${e.message}`);
}
```

### deleteKVStore

deleteKVStore(appId: string, storeId: string): Promise&lt;void&gt;

Deletes a distributed KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory| Description                                                        |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| appId   | string   | Yes  | Bundle name of the app that invokes the KV store.                                      |
| storeId | string   | Yes  | Unique identifier of the KV store to delete. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**|
| ------------ | ------------ |
| 15100004     | Not found.   |

**Example**

```js
let kvManager;
let kvStore;
const options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: true,
    kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
    schema: '',
    securityLevel: distributedKVStore.SecurityLevel.S2,
}
try {
    kvManager.getKVStore('storeId', options).then(async (store) => {
        console.log('Obtained the KVStore successfully.');
        kvStore = store;
        kvManager.deleteKVStore('appId', 'storeId').then(() => {
            console.log('Deleted the KVStore successfully.');
        }).catch((err) => {
            console.error(`Fail to delete KVStore.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to get KVStore.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to delete KVStore.code is ${e.code},message is ${e.message}`);
}
```

### getAllKVStoreId

getAllKVStoreId(appId: string, callback: AsyncCallback&lt;string[]&gt;): void

Obtains the IDs of all distributed KV stores that are created by [getKVStore](#getkvstore) and have not been deleted by [deleteKVStore](#deletekvstore). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                               |
| -------- | ----------------------------- | ---- | --------------------------------------------------- |
| appId    | string                        | Yes  | Bundle name of the app that invokes the KV store.                             |
| callback | AsyncCallback&lt;string[]&gt; | Yes  | Callback invoked to return the IDs of the distributed KV stores obtained.|

**Example**

```js
let kvManager;
try {
    kvManager.getAllKVStoreId('appId', function (err, data) {
        if (err != undefined) {
            console.error(`Fail to get AllKVStoreId.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Obtained all KV store IDs successfully.');
        console.log(`GetAllKVStoreId size = ${data.length}`);
    });
} catch (e) {
    console.error(`Fail to get AllKVStoreId.code is ${e.code},message is ${e.message}`);
}
```

### getAllKVStoreId

getAllKVStoreId(appId: string): Promise&lt;string[]&gt;

Obtains the IDs of all distributed KV stores that are created by [getKVStore](#getkvstore) and have not been deleted by [deleteKVStore](#deletekvstore). This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                  |
| ------ | -------- | ---- | ---------------------- |
| appId  | string   | Yes  | Bundle name of the app that invokes the KV store.|

**Return value**

| Type                   | Description                                                  |
| ----------------------- | ------------------------------------------------------ |
| Promise&lt;string[]&gt; | Promise used to return the IDs of the distributed KV stores obtained.|

**Example**

```js
let kvManager;
try {
    console.log('GetAllKVStoreId');
    kvManager.getAllKVStoreId('appId').then((data) => {
        console.log('Obtained all KV store IDs successfully.');
        console.log(`GetAllKVStoreId size = ${data.length}`);
    }).catch((err) => {
        console.error(`Fail to get AllKVStoreId.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to get AllKVStoreId.code is ${e.code},message is ${e.message}`);
}
```

### on('distributedDataServiceDie')

on(event: 'distributedDataServiceDie', deathCallback: Callback&lt;void&gt;): void

Subscribes to service status changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name       | Type            | Mandatory| Description                                                        |
| ------------- | -------------------- | ---- | ------------------------------------------------------------ |
| event         | string               | Yes  | Event to subscribe to. The value is **distributedDataServiceDie**, which indicates a service status change event.|
| deathCallback | Callback&lt;void&gt; | Yes  | Callback invoked to return the result.                                                  |

**Example**

```js
let kvManager;
try {
    console.log('KVManagerOn');
    const deathCallback = function () {
        console.log('death callback call');
    }
    kvManager.on('distributedDataServiceDie', deathCallback);
} catch (e) {
    console.log(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### off('distributedDataServiceDie')

off(event: 'distributedDataServiceDie', deathCallback?: Callback&lt;void&gt;): void

Unsubscribes from service status changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name       | Type            | Mandatory| Description                                                        |
| ------------- | -------------------- | ---- | ------------------------------------------------------------ |
| event         | string               | Yes  | Event to unsubscribe from. The value is **distributedDataServiceDie**, which indicates a service status change event.|
| deathCallback | Callback&lt;void&gt; | No  | Callback for the service status change event.                                                  |

**Example**

```js
let kvManager;
try {
    console.log('KVManagerOff');
    const deathCallback = function () {
        console.log('death callback call');
    }
    kvManager.off('distributedDataServiceDie', deathCallback);
} catch (e) {
    console.log(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

## KVStoreResultSet

Provides APIs for obtaining the distributed KV store result sets.

Before calling any API in **KVStoreResultSet**, you must use **[getKVStore](#getkvstore)** to construct a **SingleKVStore** or **DeviceKVStore** instance.

### getCount

getCount(): number

Obtains the total number of rows in the result set.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Total number of rows obtained.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const count = resultSet.getCount();
    console.log("getCount succeed:" + count);
} catch (e) {
    console.log("getCount failed: " + e);
}
```

### getPosition

getPosition(): number

Obtains the current data read position (position from which data is read) in the result set.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Current data read position obtained.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('Obtained the result set successfully.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const position = resultSet.getPosition();
    console.log("getPosition succeed:" + position);
} catch (e) {
    console.log("getPosition failed: " + e);
}
```

### moveToFirst

moveToFirst(): boolean

Moves the data read position to the first row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                           |
| ------- | ----------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const moved1 = resultSet.moveToFirst();
    console.log("moveToFirst succeed: " + moved1);
} catch (e) {
    console.log("moveToFirst failed " + e);
}
```

### moveToLast

moveToLast(): boolean

Moves the data read position to the last row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                           |
| ------- | ----------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const moved2 = resultSet.moveToLast();
    console.log("moveToLast succeed:" + moved2);
} catch (e) {
    console.log("moveToLast failed: " + e);
}
```

### moveToNext

moveToNext(): boolean

Moves the data read position to the next row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                           |
| ------- | ----------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const moved3 = resultSet.moveToNext();
    console.log("moveToNext succeed: " + moved3);
} catch (e) {
    console.log("moveToNext failed: " + e);
}
```

### moveToPrevious

moveToPrevious(): boolean

Moves the data read position to the previous row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                           |
| ------- | ----------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const moved4 = resultSet.moveToPrevious();
    console.log("moveToPrevious succeed:" + moved4);
} catch (e) {
    console.log("moveToPrevious failed: " + e);
}
```

### move

move(offset: number): boolean

Moves the data read position with the specified offset from the current position.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| offset | number   | Yes  | Offset to move the data read position. A negative value means to move backward, and a positive value means to move forward.|

**Return value**

| Type   | Description                                           |
| ------- | ----------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('Obtained the result set successfully.');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultSet.code is ${err.code},message is ${err.message}`);
    });
    const moved5 = resultSet.move(1);
    console.log(`Succeeded in moving.moved5 = ${moved5}`);
} catch (e) {
    console.log(`Fail to move.code is ${e.code},message is ${e.message}`);
}
```

### moveToPosition

moveToPosition(position: number): boolean

Moves the data read position from 0 to an absolute position.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type| Mandatory| Description          |
| -------- | -------- | ---- | -------------- |
| position | number   | Yes  | Absolute position to move to.|

**Return value**

| Type   | Description                                           |
| ------- | ----------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('Obtained the result set successfully.');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultSet.code is ${err.code},message is ${err.message}`);
    });
    const moved6 = resultSet.moveToPosition(1);
    console.log(`Succeeded in moving to position.moved6=${moved6}`);
} catch (e) {
    console.error(`Fail to move to position.code is ${e.code},message is ${e.message}`);
}
```

### isFirst

isFirst(): boolean

Checks whether the data read position is the first row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the first row is being read; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const isfirst = resultSet.isFirst();
    console.log("Check isFirst succeed:" + isfirst);
} catch (e) {
    console.log("Check isFirst failed: " + e);
}
```

### isLast

isLast(): boolean

Checks whether the data read position is the last row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the last row is being read; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const islast = resultSet.isLast();
    console.log("Check isLast succeed: " + islast);
} catch (e) {
    console.log("Check isLast failed: " + e);
}
```

### isBeforeFirst

isBeforeFirst(): boolean

Checks whether the data read position is before the first row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the data read position is before the first row; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const isbeforefirst = resultSet.isBeforeFirst();
    console.log("Check isBeforeFirst succeed: " + isbeforefirst);
} catch (e) {
    console.log("Check isBeforeFirst failed: " + e);
}
```

### isAfterLast

isAfterLast(): boolean

Checks whether the data read position is after the last row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the data read position is after the last row; returns **false** otherwise.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const isafterlast = resultSet.isAfterLast();
    console.log("Check isAfterLast succeed:" + isafterlast);
} catch (e) {
    console.log("Check isAfterLast failed: " + e);
}
```

### getEntry

getEntry(): Entry

Obtains the KV pair from the current position.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type           | Description        |
| --------------- | ------------ |
| [Entry](#entry) | KV pair obtained.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + err);
    });
    const entry  = resultSet.getEntry();
    console.log("getEntry succeed:" + JSON.stringify(entry));
} catch (e) {
    console.log("getEntry failed: " + e);
}
```

## Query

Provides methods to create a **Query** object, which defines different data query criteria.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

### constructor

constructor()

A constructor used to create a **Schema** instance.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

### reset

reset(): Query

Resets the **Query** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| [Query](query) | **Query** object reset.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.equalTo("key", "value");
    console.log("query is " + query.getSqlLike());
    query.reset();
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("simply calls should be ok :" + e);
}
```

### equalTo

equalTo(field: string, value: number|string|boolean): Query

Creates a **Query** object to match the specified field whose value is equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It cannot contain '^'. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.equalTo("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.ode is ${e.code},message is ${e.message}`);
}
```

### notEqualTo

notEqualTo(field: string, value: number|string|boolean): Query

Creates a **Query** object to match the specified field whose value is not equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It cannot contain '^'. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.notEqualTo("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### greaterThan

greaterThan(field: string, value: number|string|boolean): Query

Creates a **Query** object to match the specified field whose value is greater than the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**
| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It cannot contain '^'. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.greaterThan("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### lessThan

lessThan(field: string, value: number|string): Query

Creates a **Query** object to match the specified field whose value is less than the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**


| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It cannot contain '^'. |
| value  | number\|string  | Yes   | Value specified.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.lessThan("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: number|string): Query

Creates a **Query** object to match the specified field whose value is greater than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**


| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It cannot contain '^'. |
| value  | number\|string  | Yes   | Value specified.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.greaterThanOrEqualTo("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: number|string): Query

Creates a **Query** object to match the specified field whose value is less than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**


| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It cannot contain '^'. |
| value  | number\|string  | Yes   | Value specified.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.lessThanOrEqualTo("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### isNull

isNull(field: string): Query

Creates a **Query** object to match the specified field whose value is **null**.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                         |
| ------ | -------- | ---- | ----------------------------- |
| fieId  | string   | Yes  | Field to match. It cannot contain '^'.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.isNull("field");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### inNumber

inNumber(field: string, valueList: number[]): Query

Creates a **Query** object to match the specified field whose value is within the specified list of numbers.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type| Mandatory| Description                         |
| --------- | -------- | ---- | ----------------------------- |
| fieId     | string   | Yes  | Field to match. It cannot contain '^'.|
| valueList | number[] | Yes  | List of numbers.           |

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.inNumber("field", [0, 1]);
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### inString

inString(field: string, valueList: string[]): Query

Creates a **Query** object to match the specified field whose value is within the specified list of strings.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type| Mandatory| Description                         |
| --------- | -------- | ---- | ----------------------------- |
| fieId     | string   | Yes  | Field to match. It cannot contain '^'.|
| valueList | string[] | Yes  | List of strings.     |

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.inString("field", ['test1', 'test2']);
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### notInNumber

notInNumber(field: string, valueList: number[]): Query

Creates a **Query** object to match the specified field whose value is not within the specified list of numbers.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type| Mandatory| Description                         |
| --------- | -------- | ---- | ----------------------------- |
| fieId     | string   | Yes  | Field to match. It cannot contain '^'.|
| valueList | number[] | Yes  | List of numbers.           |

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.notInNumber("field", [0, 1]);
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### notInString

notInString(field: string, valueList: string[]): Query

Creates a **Query** object to match the specified field whose value is not within the specified list of strings.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type| Mandatory| Description                         |
| --------- | -------- | ---- | ----------------------------- |
| fieId     | string   | Yes  | Field to match. It cannot contain '^'.|
| valueList | string[] | Yes  | List of strings.     |

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.notInString("field", ['test1', 'test2']);
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### like

like(field: string, value: string): Query

Creates a **Query** object to match the specified field whose value is similar to the specified string.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                         |
| ------ | -------- | ---- | ----------------------------- |
| fieId  | string   | Yes  | Field to match. It cannot contain '^'.|
| value  | string   | Yes  | String specified.         |

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.like("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### unlike

unlike(field: string, value: string): Query

Creates a **Query** object to match the specified field whose value is not similar to the specified string.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                         |
| ------ | -------- | ---- | ----------------------------- |
| fieId  | string   | Yes  | Field to match. It cannot contain '^'.|
| value  | string   | Yes  | String specified.         |

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.unlike("field", "value");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### and

and(): Query

Creates a **Query** object with the AND condition.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type          | Description          |
| -------------- | -------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.notEqualTo("field", "value1");
    query.and();
    query.notEqualTo("field", "value2");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```

### or

or(): Query

Creates a **Query** object with the OR condition.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type          | Description          |
| -------------- | -------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.notEqualTo("field", "value1");
    query.or();
    query.notEqualTo("field", "value2");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```

### orderByAsc

orderByAsc(field: string): Query

Creates a **Query** object to sort the query results in ascending order.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                         |
| ------ | -------- | ---- | ----------------------------- |
| fieId  | string   | Yes  | Field to match. It cannot contain '^'.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.notEqualTo("field", "value");
    query.orderByAsc("field");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### orderByDesc

orderByDesc(field: string): Query

Creates a **Query** object to sort the query results in descending order.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                         |
| ------ | -------- | ---- | ----------------------------- |
| fieId  | string   | Yes  | Field to match. It cannot contain '^'.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.notEqualTo("field", "value");
    query.orderByDesc("field");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### limit

limit(total: number, offset: number): Query

Creates a **Query** object to specify the number of results and where to start.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ------------------ |
| total  | number   | Yes  | Number of results to query.|
| offset | number   | Yes  | Start position for query.    |

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
let total = 10;
let offset = 1;
try {
    let query = new distributedKVStore.Query();
    query.notEqualTo("field", "value");
    query.limit(total, offset);
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
     console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### isNotNull

isNotNull(field: string): Query

Creates a **Query** object to match the specified field whose value is not **null**.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                         |
| ------ | -------- | ---- | ----------------------------- |
| fieId  | string   | Yes  | Field to match. It cannot contain '^'.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.isNotNull("field");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### beginGroup

beginGroup(): Query

Creates a **Query** object for a query condition group with a left parenthesis.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.beginGroup();
    query.isNotNull("field");
    query.endGroup();
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```

### endGroup

endGroup(): Query

Creates a **Query** object for a query condition group with a right parenthesis.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.beginGroup();
    query.isNotNull("field");
    query.endGroup();
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```

### prefixKey

prefixKey(prefix: string): Query

Creates a **Query** object with a specified key prefix.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ------------------ |
| prefix | string   | Yes  | Key prefix.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.prefixKey("$.name");
    query.prefixKey("0");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### setSuggestIndex

setSuggestIndex(index: string): Query

Creates a **Query** object with an index preferentially used for query.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description              |
| ------ | -------- | ---- | ------------------ |
| index  | string   | Yes  | Index preferentially used for query.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.setSuggestIndex("$.name");
    query.setSuggestIndex("0");
    console.log(`query is ${query.getSqlLike()}`);
    query = null;
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### deviceId

deviceId(deviceId:string):Query

Creates a **Query** object with the device ID as the key prefix.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type| Mandatory| Description              |
| -------- | -------- | ---- | ------------------ |
| deviceId | string   | Yes  | Device ID.|

**Return value**

| Type          | Description           |
| -------------- | --------------- |
| [Query](query) | **Query** object created.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    query.deviceId("deviceId");
    console.log(`query is ${query.getSqlLike()}`);
} catch (e) {
    console.error(`duplicated calls should be ok.code is ${e.code},message is ${e.message}`);
}
```

### getSqlLike

getSqlLike():string

Obtains the query statement of the **Query** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | Returns the query statement obtained.|

**Example**

```js
try {
    let query = new distributedKVStore.Query();
    let sql1 = query.getSqlLike();
    console.log(`GetSqlLike sql= ${sql1}`);
} catch (e) {
    console.log("duplicated calls should be ok : " + e);
}
```

## SingleKVStore

Implements data management in a single KV store, such as adding data, deleting data, and subscribing to data changes or data synchronization completion.

Before calling any method in **SingleKVStore**, you must use [getKVStore](#getkvstore) to obtain a **SingleKVStore** instance.

### put

put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback&lt;void&gt;): void

Adds a KV pair of the specified type to this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    | string  | Yes   |Key of the KV pair to add. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).  |
| value  | Uint8Array \| string \| number \| boolean | Yes   |Value of the KV pair to add. The value type can be Uint8Array, number, string, or boolean. A value of the Uint8Array or string type cannot exceed [MAX_VALUE_LENGTH](#constants).  |
| callback | AsyncCallback&lt;void&gt; | Yes   |Callback invoked to return the result.  |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log("Put data successfully.");
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### put

put(key: string, value: Uint8Array | string | number | boolean): Promise&lt;void&gt;

Adds a KV pair of the specified type to this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    | string  | Yes   |Key of the KV pair to add. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).  |
| value  | Uint8Array \| string \| number \| boolean | Yes   |Value of the KV pair to add. The value type can be Uint8Array, number, string, or boolean. A value of the Uint8Array or string type cannot exceed [MAX_VALUE_LENGTH](#constants).  |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
        console.log(`Put data successfully. data=${data}`);
    }).catch((err) => {
        console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### putBatch

putBatch(entries: Entry[], callback: AsyncCallback&lt;void&gt;): void

Batch inserts KV pairs to this single KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | ------------------------ | ---- | ------------------------ |
| entries  | [Entry](#entry)[]        | Yes  | KV pairs to insert in batches.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.              |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        kvStore.getEntries('batch_test_string_key', function (err, entries) {
            if (err != undefined) {
                console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
            }
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
        });
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message} `);
}
```

### putBatch

putBatch(entries: Entry[]): Promise&lt;void&gt;

Batch inserts KV pairs to this single KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type         | Mandatory| Description                    |
| ------- | ----------------- | ---- | ------------------------ |
| entries | [Entry](#entry)[] | Yes  | KV pairs to insert in batches.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries).then(async (entries) => {
        console.log('Batch put data successfully.');
        kvStore.getEntries('batch_test_string_key').then((entries) => {
            console.log('Obtained the entries successfully.');
            console.log(`PutBatch ${entries}`);
        }).catch((err) => {
            console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message} `);
}
```

### putBatch

putBatch(value: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;void&gt;): void

Writes data to this single KV store. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                    | Mandatory| Description              |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| value    | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | Yes  | Data to write.|
| callback | AsyncCallback&lt;void&gt;                                     | Yes  | Callback invoked to return the result.        |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let v8Arr = [];
    let arr = new Uint8Array([4, 5, 6, 7]);
    let vb1 = { key: "name_1", value: 32 }
    let vb2 = { key: "name_2", value: arr };
    let vb3 = { key: "name_3", value: "lisi" };

    v8Arr.push(vb1);
    v8Arr.push(vb2);
    v8Arr.push(vb3);
    kvStore.putBatch(v8Arr, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
    })
} catch (e) {
    console.error(`Fail to put batch.code is ${e.code},message is ${e.message}`);
}
```

### putBatch

putBatch(value: Array&lt;ValuesBucket&gt;): Promise&lt;void&gt;

Write data to this KV store. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type                                                    | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | Yes  | Data to write. |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let v8Arr = [];
    let arr = new Uint8Array([4, 5, 6, 7]);
    let vb1 = { key: "name_1", value: 32 }
    let vb2 = { key: "name_2", value: arr };
    let vb3 = { key: "name_3", value: "lisi" };

    v8Arr.push(vb1);
    v8Arr.push(vb2);
    v8Arr.push(vb3);
    kvStore.putBatch(v8Arr).then(async (data) => {
        console.log(`Batch put data successfully.`);
    }).catch((err) => {
        console.error(`putBatch fail.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`putBatch fail.code is ${e.code},message is ${e.message}`);
}
```

### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a KV pair from this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                    | Yes  | Key of the KV pair to delete. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                                  |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005    | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Put data successfully.');
        kvStore.delete(KEY_TEST_STRING_ELEMENT, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to delete.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Deleted data successfully.');
        });
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### delete

delete(key: string): Promise&lt;void&gt;

Deletes a KV pair from this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| key    | string   | Yes  | Key of the KV pair to delete. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
        console.log(`Put data successfully: ${data}`);
        kvStore.delete(KEY_TEST_STRING_ELEMENT).then((data) => {
            console.log('Deleted data successfully.');
        }).catch((err) => {
            console.error(`Fail to delete.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### delete

delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;void&gt;)

Deletes KV pairs from this KV store. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the KV pairs to delete. If this parameter is **null**, define the processing logic.|
| callback   | AsyncCallback&lt;void&gt;                                    | Yes  | Callback invoked to return the result.                                     |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005    | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';
let kvStore;
try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    kvStore.delete(predicates, function (err, data) {
        if (err == undefined) {
            console.log('Deleted data successfully.');
        } else {
            console.error(`Fail to delete.code is ${err.code},message is ${err.message}`);
        }
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### delete

delete(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;void&gt;

Deletes KV pairs from this KV store. This API uses a promise to return the result.

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

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let kvStore;
try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let arr = ["name"];
    predicates.inKeys(arr);
    kvStore.put("name", "bob").then((data) => {
        console.log(`Put data successfully: ${data}`);
        kvStore.delete(predicates).then((data) => {
            console.log('Deleted data successfully.');
        }).catch((err) => {
            console.error(`Fail to delete.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### deleteBatch

deleteBatch(keys: string[], callback: AsyncCallback&lt;void&gt;): void

Batch deletes KV pairs from this single KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| keys     | string[]                  | Yes  | KV pairs to delete in batches.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.              |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    let keys = [];
    for (var i = 0; i < 5; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
        keys.push(key + i);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        kvStore.deleteBatch(keys, async function (err, data) {
            if (err != undefined) {
                console.error(`Fail to delete Batch.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Batch deleted data successfully.');
        });
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### deleteBatch

deleteBatch(keys: string[]): Promise&lt;void&gt;

Batch deletes KV pairs from this single KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                    |
| ------ | -------- | ---- | ------------------------ |
| keys   | string[] | Yes  | KV pairs to delete in batches.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    let keys = [];
    for (var i = 0; i < 5; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
        keys.push(key + i);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries).then(async (data) => {
        console.log('Batch put data successfully.');
        kvStore.deleteBatch(keys).then((err) => {
            console.log('Batch deleted data successfully.');
        }).catch((err) => {
            console.error(`Fail to delete Batch.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### removeDeviceData

removeDeviceData(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes data of a device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type                 | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| deviceId | string                    | Yes  | ID of the target device.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.            |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err, data) {
        console.log('Put data successfully.');
        const deviceid = 'no_exist_device_id';
        kvStore.removeDeviceData(deviceid, async function (err, data) {
            if (err == undefined) {
                console.log('Removed device data successfully.');
            } else {
                console.error(`Fail to remove device data.code is ${err.code},message is ${err.message} `);
                kvStore.get(KEY_TEST_STRING_ELEMENT, async function (err, data) {
                    console.log('Obtained data successfully.');
                });
            }
        });
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`)
}
```

### removeDeviceData

removeDeviceData(deviceId: string): Promise&lt;void&gt;

Deletes data of a device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type| Mandatory| Description                  |
| -------- | -------- | ---- | ---------------------- |
| deviceId | string   | Yes  | ID of the target device.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((err) => {
        console.log('Put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put data.code is ${err.code},message is ${err.message} `);
    });
    const deviceid = 'no_exist_device_id';
    kvStore.removeDeviceData(deviceid).then((err) => {
        console.log('Removed device data successfully.');
    }).catch((err) => {
        console.error(`Fail to remove device data.code is ${err.code},message is ${err.message} `);
    });
    kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {
        console.log('Obtained data successfully.');
    }).catch((err) => {
        console.error(`Fail to get data.code is ${err.code},message is ${err.message} `);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`)
}
```

### get

get(key: string, callback: AsyncCallback<boolean | string| number | Uint8Array>): void

Obtains the value of the specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    |string   | Yes   |Key of the value to obtain. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants). |
| callback  |AsyncCallback&lt;boolean \| string \| number \| Uint8Array&gt; | Yes   |Callback invoked to return the value obtained. |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log("Put data successfully.");
        kvStore.get(KEY_TEST_STRING_ELEMENT, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to get.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log(`Obtained data successfully. data=${data}`);
        });
    });
} catch (e) {
    console.error(`Fail to get.code is ${e.code},message is ${e.message}`);
}
```

### get

get(key: string): Promise&lt;boolean | string| number | Uint8Array&gt;

Obtains the value of the specified key. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| key    | string   | Yes  | Key of the value to obtain. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).|

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;Uint8Array \| string \| boolean \| number&gt; |Promise used to return the value obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
        console.log(`Put data successfully. data=${data}`);
        kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {
            console.log(`Obtained data successfully. data=${data}`);
        }).catch((err) => {
            console.error(`Fail to get.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to get.code is ${e.code},message is ${e.message}`);
}
```

### getEntries

getEntries(keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains all KV pairs that match the specified key prefix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type                              | Mandatory| Description                                    |
| --------- | -------------------------------------- | ---- | ---------------------------------------- |
| keyPrefix | string                                 | Yes  | Key prefix to match.                    |
| callback  | AsyncCallback&lt;[Entry](#entry)[]&gt; | Yes  | Callback invoked to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        kvStore.getEntries('batch_test_string_key', function (err, entries) {
            if (err != undefined) {
                console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
        });
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message} `);
}
```

### getEntries

getEntries(keyPrefix: string): Promise&lt;Entry[]&gt;

Obtains all KV pairs that match the specified key prefix. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type| Mandatory| Description                |
| --------- | -------- | ---- | -------------------- |
| keyPrefix | string   | Yes  | Key prefix to match.|

**Return value**

| Type                            | Description                                       |
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise used to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries).then(async (entries) => {
        console.log('Batch put data successfully.');
        kvStore.getEntries('batch_test_string_key').then((entries) => {
            console.log('Obtained the entries successfully.');
            console.log(`PutBatch ${entries}`);
        }).catch((err) => {
            console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message} `);
}
```

### getEntries

getEntries(query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                           |
| -------- | -------------------------------------- | ---- | ----------------------------------------------- |
| query    | [Query](query)                         | Yes  | Key prefix to match.                           |
| callback | AsyncCallback&lt;[Entry](#entry)[]&gt; | Yes  | Callback invoked to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21, 31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.BYTE_ARRAY,
                value: arr
            }
        }
        entries.push(entry);
    }
    console.log(`entries: {entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getEntries(query, function (err, entries) {
            if (err != undefined) {
                console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
        });
    });
} catch (e) {
    console.error(`Fail to get Entries.code is ${e.code},message is ${e.message}`);
}
```

### getEntries

getEntries(query: Query): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type      | Mandatory| Description          |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](query) | Yes  | **Query** object to match.|

**Return value**

| Type                            | Description                                              |
| -------------------------------- | -------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise used to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21, 31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.BYTE_ARRAY,
                value: arr
            }
        }
        entries.push(entry);
    }
    console.log(`entries: {entries}`);
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getEntries(query).then((entries) => {
            console.log('Obtained the entries successfully.');
        }).catch((err) => {
            console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`)
    });
    console.log('Obtained the entries successfully.');
} catch (e) {
    console.error(`Fail to get Entries.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a result set with the specified prefix from this single KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type                                                  | Mandatory| Description                                |
| --------- | ---------------------------------------------------------- | ---- | ------------------------------------ |
| keyPrefix | string                                                     | Yes  | Key prefix to match.                |
| callback  | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Yes  | Callback invoked to return the result set obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        kvStore.getResultSet('batch_test_string_key', async function (err, result) {
            if (err != undefined) {
                console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the result set successfully');
            resultSet = result;
            kvStore.closeResultSet(resultSet, function (err, data) {
                if (err != undefined) {
                    console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
                    return;
                }
                console.log('Closed the result set successfully');
            })
        });
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string): Promise&lt;KVStoreResultSet&gt;

Obtains a result set with the specified prefix from this single KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type| Mandatory| Description                |
| --------- | -------- | ---- | -------------------- |
| keyPrefix | string   | Yes  | Key prefix to match.|

**Return value**

| Type                                                | Description                                   |
| ---------------------------------------------------- | --------------------------------------- |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise used to return the result set obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('Obtained the result set successfully');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully');
    }).catch((err) => {
        console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSet

getResultSet(query: Query, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                  | Mandatory| Description                                                     |
| -------- | ---------------------------------------------------------- | ---- | --------------------------------------------------------- |
| query    | Query                                                      | Yes  | **Query** object to match.                                           |
| callback | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Yes  | Callback invoked to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSet(query, async function (err, result) {
            if (err != undefined) {
                console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the result set successfully');
        });
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(query: Query): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type      | Mandatory| Description          |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](query) | Yes  | **Query** object to match.|

**Return value**

| Type                                                | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    const query = new distributedKVStore.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSet(query).then((result) => {
        console.log('Obtained the result set successfully');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}    
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified predicate object. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.             |
| callback   | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt;   | Yes  | Callback invoked to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let kvStore;
try {
    let resultSet;
    let predicates = new dataSharePredicates.DataSharePredicates();
    predicates.prefixKey("batch_test_string_key");
    kvStore.getResultSet(predicates, async function (err, result) {
        if (err != undefined) {
            console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Obtained the result set successfully');
        resultSet = result;
        kvStore.closeResultSet(resultSet, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Closed the result set successfully');
        })
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified predicate object. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.|

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let kvStore;
try {
    let resultSet;
    let predicates = new dataSharePredicates.DataSharePredicates();
    predicates.prefixKey("batch_test_string_key");
    kvStore.getResultSet(predicates).then((result) => {
        console.log('Obtained the result set successfully');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully');
    }).catch((err) => {
        console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### closeResultSet

closeResultSet(resultSet: KVStoreResultSet, callback: AsyncCallback&lt;void&gt;): void

Closes the **KVStoreResultSet** object returned by [SingleKvStore.getResultSet](#getresultset-1). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type                             | Mandatory| Description                              |
| --------- | ------------------------------------- | ---- | ---------------------------------- |
| resultSet | [KVStoreResultSet](#kvstoreresultset) | Yes  | **KVStoreResultSet** object to close.|
| callback  | AsyncCallback&lt;void&gt;             | Yes  | Callback invoked to return the result.                        |

**Example**

```js
let kvStore;
try {
    let resultSet = null;
    kvStore.closeResultSet(resultSet, function (err, data) {
        if (err == undefined) {
            console.log('Closed the result set successfully');
        } else {
            console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
        }
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### closeResultSet

closeResultSet(resultSet: KVStoreResultSet): Promise&lt;void&gt;

Closes the **KVStoreResultSet** object returned by [SingleKvStore.getResultSet](#getresultset-1). This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type                             | Mandatory| Description                              |
| --------- | ------------------------------------- | ---- | ---------------------------------- |
| resultSet | [KVStoreResultSet](#kvstoreresultset) | Yes  | **KVStoreResultSet** object to close.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    let resultSet = null;
    kvStore.closeResultSet(resultSet).then(() => {
        console.log('Closed the result set successfully');
    }).catch((err) => {
        console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSize

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

Obtains the number of results that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                       |
| -------- | --------------------------- | ---- | ------------------------------------------- |
| query    | [Query](query)              | Yes  | **Query** object to match.                             |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the number of results obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSize(query, async function (err, resultSize) {
            if (err != undefined) {
                console.error(`Fail to get result size.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the result set size successfully');
        });
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSize

getResultSize(query: Query): Promise&lt;number&gt;

Obtains the number of results that matches the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type      | Mandatory| Description          |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](query) | Yes  | **Query** object to match.|

**Return value**

| Type                 | Description                                           |
| --------------------- | ----------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of results obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    const query = new distributedKVStore.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSize(query).then((resultSize) => {
        console.log('Obtained the result set size successfully');
    }).catch((err) => {
        console.error(`Fail to get result size.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### backup

backup(file:string, callback: AsyncCallback&lt;void&gt;):void

Backs up a distributed KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| file     | string                    | Yes  | Name of the KV store. The value cannot be empty or exceed [MAX_KEY_LENGTH](#constants).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
let file = "BK001";
try {
    kvStore.backup(file, (err, data) => {
        if (err) {
            console.error(`Fail to backup.code is ${err.code},message is ${err.message} `);
        } else {
            console.info(`Backed up data successfully. data=${data}`);
        }
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### backup

backup(file:string): Promise&lt;void&gt;

Backs up an RDB store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| file   | string   | Yes  | Name of the KV store. The value cannot be empty or exceed [MAX_KEY_LENGTH](#constants).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
let file = "BK001";
try {
    kvStore.backup(file).then((data) => {
        console.info(`Backed up data successfully. data=${data}`);
    }).catch((err) => {
        console.error(`Fail to backup.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### restore

restore(file:string, callback: AsyncCallback&lt;void&gt;):void

Restores a distributed KV store from a database file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| file     | string                    | Yes  | Name of the database file. The value cannot be empty or exceed [MAX_KEY_LENGTH](#constants).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
let file = "BK001";
try {
    kvStore.restore(file, (err, data) => {
        if (err) {
            console.error(`Fail to restore.code is ${err.code},message is ${err.message}`);
        } else {
            console.info(`Restored data successfully. data=${data}`);
        }
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### restore

restore(file:string): Promise&lt;void&gt;

Restores a distributed KV store from a database file. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| file   | string   | Yes  | Name of the database file. The value cannot be empty or exceed [MAX_KEY_LENGTH](#constants).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
let file = "BK001";
try {
    kvStore.restore(file).then((data) => {
        console.info(`Restored data successfully. data=${data}`);
    }).catch((err) => {
        console.error(`Fail to restore.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### deleteBackup

deleteBackup(files:Array&lt;string&gt;, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;):void

Deletes a backup file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                          | Mandatory| Description                                                        |
| -------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| files    | Array&lt;string&gt;                                | Yes  | Name of the backup file to delete. The value cannot be empty or exceed [MAX_KEY_LENGTH](#constants).|
| callback | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback invoked to return the name of the backup file deleted and the operation result.                |

**Example**

```js
let kvStore;
let files = ["BK001", "BK002"];
try {
    kvStore.deleteBackup(files, (err, data) => {
        if (err) {
            console.error(`Fail to delete Backup.code is ${err.code},message is ${err.message}`);
        } else {
            console.info(`Deleted the backup file successfully. data=${data}`);
        }
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### deleteBackup

deleteBackup(files:Array&lt;string&gt;): Promise&lt;Array&lt;[string, number]&gt;&gt;

Deletes a backup file. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type           | Mandatory| Description                                                        |
| ------ | ------------------- | ---- | ------------------------------------------------------------ |
| files  | Array&lt;string&gt; | Yes  | Name of the backup file to delete. The value cannot be empty or exceed [MAX_KEY_LENGTH](#constants).|

**Return value**

| Type                                        | Description                                           |
| -------------------------------------------- | ----------------------------------------------- |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise used to return the name of the backup file deleted and the operation result.|

**Example**

```js
let kvStore;
let files = ["BK001", "BK002"];
try {
    kvStore.deleteBackup(files).then((data) => {
        console.info(`Deleted the backup file successfully. data=${data}`);
    }).catch((err) => {
        console.error(`Fail to delete Backup.code is ${err.code},message is ${err.message}`);
    })
} catch (e) {
    console.log(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
}
```

### startTransaction

startTransaction(callback: AsyncCallback&lt;void&gt;): void

Starts the transaction in this single KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
function putBatchString(len, prefix) {
    let entries = [];
    for (var i = 0; i < len; i++) {
        var entry = {
            key: prefix + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    return entries;
}

try {
    var count = 0;
    kvStore.on('dataChange', 0, function (data) {
        console.log(`startTransaction 0 ${data}`);
        count++;
    });
    kvStore.startTransaction(async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to start Transaction.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Started the transaction successfully.');
        let entries = putBatchString(10, 'batch_test_string_key');
        console.log(`entries: ${entries}`);
        kvStore.putBatch(entries, async function (err, data) {
            if (err != undefined) {
                console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Batch put data successfully.');
        });
    });
} catch (e) {
    console.error(`Fail to start Transaction.code is ${e.code},message is ${e.message}`);
}
```

### startTransaction

startTransaction(): Promise&lt;void&gt;

Starts the transaction in this single KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    var count = 0;
    kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_ALL, function (data) {
        console.log(`startTransaction 0 ${data}`);
        count++;
    });
    kvStore.startTransaction().then(async (err) => {
        console.log('Started the transaction successfully.');
    }).catch((err) => {
        console.error(`Fail to start Transaction.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to start Transaction.code is ${e.code},message is ${e.message}`);
}
```

### commit

commit(callback: AsyncCallback&lt;void&gt;): void

Commits the transaction in this single KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    kvStore.commit(function (err, data) {
        if (err == undefined) {
            console.log('Committed the transaction successfully.');
        } else {
            console.error(`Fail to commit.code is ${err.code},message is ${err.message}`);
        }
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### commit

commit(): Promise&lt;void&gt;

Commits the transaction in this single KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    kvStore.commit().then(async (err) => {
        console.log('Committed the transaction successfully.');
    }).catch((err) => {
        console.error(`Fail to commit.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.ode is ${e.code},message is ${e.message}`);
}
```

### rollback

rollback(callback: AsyncCallback&lt;void&gt;): void

Rolls back the transaction in this single KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    kvStore.rollback(function (err,data) {
        if (err == undefined) {
            console.log('Rolled back the transaction successfully');
        } else {
            console.error(`Fail to rollback.code is ${err.code},message is ${err.message}`);
        }
    });
}catch(e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### rollback

rollback(): Promise&lt;void&gt;

Rolls back the transaction in this single KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    kvStore.rollback().then(async (err) => {
        console.log('Rolled back the transaction successfully');
    }).catch((err) => {
        console.error(`Fail to rollback.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### enableSync

enableSync(enabled: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets data synchronization, which can be enabled or disabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                     |
| -------- | ------------------------- | ---- | --------------------------------------------------------- |
| enabled  | boolean                   | Yes  | Whether to enable data synchronization. The value **true** means to enable data synchronization, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                               |

**Example**

```js
let kvStore;
try {
    kvStore.enableSync(true, function (err, data) {
        if (err == undefined) {
            console.log('Enabled sync successfully.');
        } else {
            console.error(`Fail to enable sync.code is ${err.code},message is ${err.message}`);
        }
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### enableSync

enableSync(enabled: boolean): Promise&lt;void&gt;

Sets data synchronization, which can be enabled or disabled. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory| Description                                                     |
| ------- | -------- | ---- | --------------------------------------------------------- |
| enabled | boolean  | Yes  | Whether to enable data synchronization. The value **true** means to enable data synchronization, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    kvStore.enableSync(true).then((err) => {
        console.log('Enabled sync successfully.');
    }).catch((err) => {
        console.error(`Fail to enable sync.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### setSyncRange

setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback&lt;void&gt;): void

Sets the data synchronization range. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name             | Type                 | Mandatory| Description                            |
| ------------------- | ------------------------- | ---- | -------------------------------- |
| localLabels         | string[]                  | Yes  | Synchronization labels set for the local device.        |
| remoteSupportLabels | string[]                  | Yes  | Synchronization labels set for remote devices.|
| callback            | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                      |

**Example**

```js
let kvStore;
try {
    const localLabels = ['A', 'B'];
    const remoteSupportLabels = ['C', 'D'];
    kvStore.setSyncRange(localLabels, remoteSupportLabels, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to set syncRange.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Set syncRange successfully.');
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### setSyncRange

setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise&lt;void&gt;

Sets the data synchronization range. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name             | Type| Mandatory| Description                            |
| ------------------- | -------- | ---- | -------------------------------- |
| localLabels         | string[] | Yes  | Synchronization labels set for the local device.        |
| remoteSupportLabels | string[] | Yes  | Synchronization labels set for remote devices.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    const localLabels = ['A', 'B'];
    const remoteSupportLabels = ['C', 'D'];
    kvStore.setSyncRange(localLabels, remoteSupportLabels).then((err) => {
        console.log('Set syncRange successfully.');
    }).catch((err) => {
        console.error(`Fail to set syncRange.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### setSyncParam

setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback&lt;void&gt;): void

Sets the default delay allowed for KV store synchronization. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name               | Type                 | Mandatory| Description                                        |
| --------------------- | ------------------------- | ---- | -------------------------------------------- |
| defaultAllowedDelayMs | number                    | Yes  | Default delay allowed for database synchronization, in ms.|
| callback              | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                  |

**Example**

```js
let kvStore;
try {
    const defaultAllowedDelayMs = 500;
    kvStore.setSyncParam(defaultAllowedDelayMs, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to set syncParam.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Set syncParam successfully');
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### setSyncParam

setSyncParam(defaultAllowedDelayMs: number): Promise&lt;void&gt;

Sets the default delay allowed for KV store synchronization. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name               | Type| Mandatory| Description                                        |
| --------------------- | -------- | ---- | -------------------------------------------- |
| defaultAllowedDelayMs | number   | Yes  | Default delay allowed for database synchronization, in ms.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    const defaultAllowedDelayMs = 500;
    kvStore.setSyncParam(defaultAllowedDelayMs).then((err) => {
        console.log('Set syncParam successfully');
    }).catch((err) => {
        console.error(`Fail to set syncParam.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### sync

sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void

Synchronizes the KV store manually. For details about the synchronization modes of the distributed data service, see [Distributed Data Service Overview](../../database/database-mdds-overview.md).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type             | Mandatory| Description                                          |
| --------- | --------------------- | ---- | ---------------------------------------------- |
| deviceIds | string[]              | Yes  | List of IDs of the devices in the same networking environment to be synchronized.|
| mode      | [SyncMode](#syncmode) | Yes  | Synchronization mode.                                    |
| delayMs   | number                | No  | Allowed synchronization delay time, in ms.    |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**       |
| ------------ | ------------------- |
| 15100003     | Database corrupted. |
| 15100004     | Not found.          |

**Example**

```js
let kvStore;
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';
try {
    kvStore.on('syncComplete', function (data) {
        console.log('Sync dataChange');
    });
    kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to sync.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Put data successfully.');
        const devices = ['deviceList'];
        const mode = distributedKVStore.SyncMode.PULL_ONLY;
        kvStore.sync(devices, mode, 1000);
    });
} catch (e) {
    console.error(`Fail to sync.code is ${e.code},message is ${e.message}`);
}
```

### sync

sync(deviceIds: string[], query: Query, mode: SyncMode, delayMs?: number): void

Synchronizes the KV store manually. This API returns the result synchronously. For details about the synchronization modes of the distributed data service, see [Distributed Data Service Overview](../../database/database-mdds-overview.md).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type             | Mandatory| Description                                          |
| --------- | --------------------- | ---- | ---------------------------------------------- |
| deviceIds | string[]              | Yes  | List of IDs of the devices in the same networking environment to be synchronized.|
| mode      | [SyncMode](#syncmode) | Yes  | Synchronization mode.                                    |
| query     | [Query](query)        | Yes  | **Query** object to match.                      |
| delayMs   | number                | No  | Allowed synchronization delay time, in ms.    |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**       |
| ------------ | ------------------- |
| 15100003     | Database corrupted. |
| 15100004     | Not found.          |

**Example**

```js
let kvStore;
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';
try {
    kvStore.on('syncComplete', function (data) {
        console.log('Sync dataChange');
    });
    kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to sync.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Put data successfully.');
        const devices = ['deviceList'];
        const mode = distributedKVStore.SyncMode.PULL_ONLY;
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        query.deviceId('localDeviceId');
        kvStore.sync(devices, query, mode, 1000);
    });
} catch (e) {
    console.error(`Fail to sync.code is ${e.code},message is ${e.message}`);
}
```

### on('dataChange')

on(event: 'dataChange', type: SubscribeType, listener: Callback&lt;ChangeNotification&gt;): void

Subscribes to data changes of the specified type.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------- |
| event    | string                                                    | Yes  | Event to subscribe to. The value is **dataChange**, which indicates a data change event.|
| type     | [SubscribeType](#subscribetype)                           | Yes  | Type of data change.                                    |
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | Yes  | Callback invoked to return the result.                                          |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100001     | Over max subscribe limits.             |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {
        console.log(`dataChange callback call data: ${data}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### on('syncComplete')

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Subscribes to synchronization complete events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                     | Mandatory| Description                                                  |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------ |
| event        | string                                        | Yes  | Event to subscribe to. The value is **syncComplete**, which indicates a synchronization complete event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback used to return the synchronization result.            |

**Example**

```js
let kvStore;
const KEY_TEST_FLOAT_ELEMENT = 'key_test_float';
const VALUE_TEST_FLOAT_ELEMENT = 321.12;
try {
    kvStore.on('syncComplete', function (data) {
        console.log(`syncComplete ${data}`);
    });
    kvStore.put(KEY_TEST_FLOAT_ELEMENT, VALUE_TEST_FLOAT_ELEMENT).then((data) => {
        console.log('Put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to subscribe syncComplete.code is ${e.code},message is ${e.message}`);
}
```

### off('dataChange')

off(event:'dataChange', listener?: Callback&lt;ChangeNotification&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                    |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------------------------- |
| event    | string                                                    | Yes  | Event to unsubscribe from. The value is **dataChange**, which indicates a data change event.|
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | No  | Callback invoked to return the result.                                              |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log(`dataChange : ${data}`);
    }

    subscribeDataChange() {
        try {
            if (kvStore != null) {
                kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);
            }
        } catch (err) {
            console.error(`Fail to subscribeDataChange.code is ${err.code},message is ${err.message}`);
        }
    }

    unsubscribeDataChange() {
        try {
            if (kvStore != null) {
                kvStore.off('dataChange', this.call);
            }
        } catch (err) {
            console.error(`Fail to unsubscribeDataChange.code is ${err.code},message is ${err.message}`);
        }
    }
}
```

### off('syncComplete')

off(event: 'syncComplete', syncCallback?: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Unsubscribes from synchronization complete events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                     | Mandatory| Description                                                      |
| ------------ | --------------------------------------------- | ---- | ---------------------------------------------------------- |
| event        | string                                        | Yes  | Event to unsubscribe from. The value is **syncComplete**, which indicates a synchronization complete event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | No  | Callback used to return the synchronization result.                |

**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log(`syncComplete : ${data}`);
    }

    subscribeDataChange() {
        try {
            if (kvStore != null) {
                kvStore.on('syncComplete', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);
            }
        } catch (err) {
            console.error(`Fail to subscribeDataChange.code is ${err.code},message is ${err.message}`);
        }
    }

    unsubscribeDataChange() {
        try {
            if (kvStore != null) {
                kvStore.off('dsyncComplete', this.call);
            }
        } catch (err) {
            console.error(`Fail to unsubscribeDataChange.code is ${err.code},message is ${err.message}`);
        }
    }
}
```

### getSecurityLevel

getSecurityLevel(callback: AsyncCallback&lt;SecurityLevel&gt;): void

Obtains the security level of this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                            |
| -------- | ---------------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;[SecurityLevel](#securitylevel)&gt; | Yes  | Callback invoked to return the security level obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID** | **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    kvStore.getSecurityLevel(function (err, data) {
        if (err != undefined) {
            console.error(`Fail to get SecurityLevel.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Obtained securityLevel successfully');
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### getSecurityLevel

getSecurityLevel(): Promise&lt;SecurityLevel&gt;

Obtains the security level of this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type                                          | Description                               |
| ---------------------------------------------- | ----------------------------------- |
| Promise&lt;[SecurityLevel](#securitylevel)&gt; | Promise used to return the security level obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    kvStore.getSecurityLevel().then((data) => {
        console.log('Obtained securityLevel successfully');
    }).catch((err) => {
        console.error(`Fail to get SecurityLevel.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

## DeviceKVStore

Provides APIs for querying and synchronizing data in a device KV store. This class inherits from **SingleKVStore**.

Data is distinguished by device in a device KV store. Each device can only write and modify its own data. Data of other devices is read-only and cannot be modified.

For example, a device KV store can be used to implement image sharing between devices. The images of other devices can be viewed, but not be modified or deleted.

Before calling any method in **DeviceKVStore**, you must use [getKVStore](#getkvstore) to obtain a **DeviceKVStore** object.

### get

get(key: string, callback: AsyncCallback<boolean | string| number | Uint8Array>): void

Obtains the value of the specified key for this device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| key      | string                                                       | Yes  | Key of the value to obtain. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).|
| callback | AsyncCallback&lt;boolean \| string \| number \| Uint8Array&gt; | Yes  | Callback invoked to return the value obtained.                                |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log("Put data successfully.");
        kvStore.get(KEY_TEST_STRING_ELEMENT, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to get.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log(`Obtained data successfully. data=${data}`);
        });
    });
} catch (e) {
    console.error(`Fail to get.code is ${e.code},message is ${e.message}`);
}
```

### get

get(key: string): Promise&lt;boolean | string| number | Uint8Array&gt;

Obtains the value of the specified key for this device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| key    | string | Yes  | Key of the value to obtain. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).|

**Return value**

| Type                                                    | Description                           |
| -------------------------------------------------------- | ------------------------------- |
| Promise&lt;Uint8Array \| string \| boolean \| number&gt; | Promise used to return the value obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
        console.log(`Put data successfully. data=${data}`);
        kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {
            console.log(`Obtained data successfully. data=${data}`);
        }).catch((err) => {
            console.error(`Fail to get.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to get.code is ${e.code},message is ${e.message}`);
}
```

### get

get(deviceId: string, key: string, callback: AsyncCallback&lt;boolean|string|number|Uint8Array&gt;): void

Obtains a string value that matches the specified device ID and key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| key       |string  | Yes   |Key to match.   |
| callback  |AsyncCallback&lt;boolean\|string\|number\|Uint8Array&gt;  | Yes   |Callback invoked to return the value obtained.   |

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Put data successfully.');
        kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to get.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained data successfully');
        });
    })
} catch (e) {
    console.error(`Fail to get.code is ${e.code},message is ${e.message}`);
}
```

### get

get(deviceId: string, key: string): Promise&lt;boolean|string|number|Uint8Array&gt;

Obtains a string value that matches the specified device ID and key. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type| Mandatory| Description                    |
| -------- | -------- | ---- | ------------------------ |
| deviceId | string   | Yes  | ID of the target device.|
| key      | string   | Yes  | Key to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;boolean\|string\|number\|Uint8Array&gt; |Promise used to return the string value obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100004     | Not found.                             |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(async (data) => {
        console.log('Put data successfully.');
        kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT).then((data) => {
            console.log('Obtained data successfully');
        }).catch((err) => {
            console.error(`Fail to get.code is ${err.code},message is ${err.message}`);
        });
    }).catch((error) => {
        console.error(`Fail to put.code is ${error.code},message is ${error.message}`);
    });
} catch (e) {
    console.error(`Fail to get.code is ${e.code},message is ${e.message}`);
}
```

### getEntries

getEntries(keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains all KV pairs that match the specified key prefix for this device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type                                  | Mandatory| Description                                    |
| --------- | -------------------------------------- | ---- | ---------------------------------------- |
| keyPrefix | string                                 | Yes  | Key prefix to match.                    |
| callback  | AsyncCallback&lt;[Entry](#entry)[]&gt; | Yes  | Callback invoked to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        kvStore.getEntries('batch_test_string_key', function (err, entries) {
            if (err != undefined) {
                console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
        });
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message} `);
}
```

### getEntries

getEntries(keyPrefix: string): Promise&lt;Entry[]&gt;

Obtains all KV pairs that match the specified key prefix for this device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type  | Mandatory| Description                |
| --------- | ------ | ---- | -------------------- |
| keyPrefix | string | Yes  | Key prefix to match.|

**Return value**

| Type                            | Description                                       |
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise used to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries).then(async (entries) => {
        console.log('Batch put data successfully.');
        kvStore.getEntries('batch_test_string_key').then((entries) => {
            console.log('Obtained the entries successfully.');
            console.log(`PutBatch ${entries}`);
        }).catch((err) => {
            console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put Batch.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message} `);
}
```

### getEntries

getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains all KV pairs that match the specified device ID and key prefix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name   | Type                              | Mandatory| Description                                          |
| --------- | -------------------------------------- | ---- | ---------------------------------------------- |
| deviceId  | string                                 | Yes  | ID of the target device.                      |
| keyPrefix | string                                 | Yes  | Key prefix to match.                          |
| callback  | AsyncCallback&lt;[Entry](#entry)[]&gt; | Yes  | Callback invoked to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries : ${entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        kvStore.getEntries('localDeviceId', 'batch_test_string_key', function (err, entries) {
            if (err != undefined) {
                console.error(`Fail to get entries.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
        });
    });
} catch (e) {
    console.error(`Fail to put batch.code is ${e.code},message is ${e.message}`);
}
```

### getEntries

getEntries(deviceId: string, keyPrefix: string): Promise&lt;Entry[]&gt;

Obtains all KV pairs that match the specified device ID and key prefix. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name   | Type| Mandatory| Description                    |
| --------- | -------- | ---- | ------------------------ |
| deviceId  | string   | Yes  | ID of the target device.|
| keyPrefix | string   | Yes  | Key prefix to match.    |

**Return value**

| Type                            | Description                                             |
| -------------------------------- | ------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise used to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
        kvStore.getEntries('localDeviceId', 'batch_test_string_key').then((entries) => {
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
            console.log(`entries[0].value: ${entries[0].value}`);
            console.log(`entries[0].value.value: ${entries[0].value.value}`);
        }).catch((err) => {
            console.error(`Fail to get entries.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to put batch.code is ${e.code},message is ${e.message}`);
}    
```

### getEntries

getEntries(query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains all KV pairs that match the specified **Query** object for this device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                 |
| -------- | -------------------------------------- | ---- | ----------------------------------------------------- |
| query    | [Query](query)                         | Yes  | Key prefix to match.                                 |
| callback | AsyncCallback&lt;[Entry](#entry)[]&gt; | Yes  | Callback used to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21, 31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.BYTE_ARRAY,
                value: arr
            }
        }
        entries.push(entry);
    }
    console.log(`entries: {entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getEntries(query, function (err, entries) {
            if (err != undefined) {
                console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
        });
    });
} catch (e) {
    console.error(`Fail to get Entries.code is ${e.code},message is ${e.message}`);
}
```

### getEntries

getEntries(query: Query): Promise&lt;Entry[]&gt;

Obtains all KV pairs that match the specified **Query** object for this device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type          | Mandatory| Description          |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](query) | Yes  | **Query** object to match.|

**Return value**

| Type                            | Description                                                    |
| -------------------------------- | -------------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise used to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21, 31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.BYTE_ARRAY,
                value: arr
            }
        }
        entries.push(entry);
    }
    console.log(`entries: {entries}`);
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getEntries(query).then((entries) => {
            console.log('Obtained the entries successfully.');
        }).catch((err) => {
            console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to get Entries.code is ${err.code},message is ${err.message}`)
    });
    console.log('Obtained the entries successfully.');
} catch (e) {
    console.error(`Fail to get Entries.code is ${e.code},message is ${e.message}`);
}
```

### getEntries

getEntries(deviceId: string, query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified device ID and **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type                              | Mandatory| Description                                                   |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------- |
| deviceId | string                                 | Yes  | ID of the target device.                                   |
| query    | [Query](query)                         | Yes  | **Query** object to match.                                         |
| callback | AsyncCallback&lt;[Entry](#entry)[]&gt; | Yes  | Callback invoked to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21, 31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.BYTE_ARRAY,
                value: arr
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        var query = new distributedKVStore.Query();
        query.deviceId('localDeviceId');
        query.prefixKey("batch_test");
        kvStore.getEntries('localDeviceId', query, function (err, entries) {
            if (err != undefined) {
                console.error(`Fail to get entries.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the entries successfully.');
            console.log(`entries.length: ${entries.length}`);
            console.log(`entries[0]: ${entries[0]}`);
        })
    });
    console.log('Obtained the entries successfully.');
} catch (e) {
    console.error(`Fail to get entries.code is ${e.code},message is ${e.message}`);
}
```

### getEntries

getEntries(deviceId: string, query: Query): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified device ID and **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type      | Mandatory| Description                |
| -------- | -------------- | ---- | -------------------- |
| deviceId | string         | Yes  | ID of the target device.|
| query    | [Query](query) | Yes  | **Query** object to match.      |

**Return value**

| Type                            | Description                                                      |
| -------------------------------- | ---------------------------------------------------------- |
| Promise&lt;[Entry](#entry)[]&gt; | Promise used to return the KV pairs obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21, 31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.BYTE_ARRAY,
                value: arr
            }
        }
        entries.push(entry);
    }
    console.log(`entries: ${entries}`);
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
        var query = new distributedKVStore.Query();
        query.deviceId('localDeviceId');
        query.prefixKey("batch_test");
        kvStore.getEntries('localDeviceId', query).then((entries) => {
            console.log('Obtained the entries successfully.');
        }).catch((err) => {
            console.error(`Fail to get entries.code is ${err.code},message is ${err.message}`);
        });
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    console.log('Obtained the entries successfully.');
} catch (e) {
    console.error(`Fail to get entries.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a result set with the specified prefix for this device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type                                                      | Mandatory| Description                                |
| --------- | ---------------------------------------------------------- | ---- | ------------------------------------ |
| keyPrefix | string                                                     | Yes  | Key prefix to match.                |
| callback  | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Yes  | Callback invoked to return the result set obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        kvStore.getResultSet('batch_test_string_key', async function (err, result) {
            if (err != undefined) {
                console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the result set successfully');
            resultSet = result;
            kvStore.closeResultSet(resultSet, function (err, data) {
                if (err != undefined) {
                    console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
                    return;
                }
                console.log('Closed the result set successfully');
            })
        });
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(keyPrefix: string): Promise&lt;KVStoreResultSet&gt;

Obtains a result set with the specified prefix for this device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type  | Mandatory| Description                |
| --------- | ------ | ---- | -------------------- |
| keyPrefix | string | Yes  | Key prefix to match.|

**Return value**

| Type                                                | Description                                   |
| ---------------------------------------------------- | --------------------------------------- |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise used to return the result set obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('Obtained the result set successfully');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully');
    }).catch((err) => {
        console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSet

getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified device ID and key prefix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name   | Type                                                    | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId  | string                                                       | Yes  | ID of the target device.                                    |
| keyPrefix | string                                                       | Yes  | Key prefix to match.                                        |
| callback  | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Yes  | Callback invoked to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key', async function (err, result) {
        if (err != undefined) {
            console.error(`Fail to get resultSet.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Obtained the result set successfully.');
        resultSet = result;
        kvStore.closeResultSet(resultSet, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to close resultSet.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Closed the result set successfully.');
        })
    });
} catch (e) {
    console.error(`Fail to get resultSet.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(deviceId: string, keyPrefix: string): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified device ID and key prefix. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name   | Type| Mandatory| Description                    |
| --------- | -------- | ---- | ------------------------ |
| deviceId  | string   | Yes  | ID of the target device.|
| keyPrefix | string   | Yes  | Key prefix to match.    |

**Return value**

| Type                                                  | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key').then((result) => {
        console.log('Obtained the result set successfully.');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultSet.code is ${err.code},message is ${err.message}`);
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully.');
    }).catch((err) => {
        console.error(`Fail to close resultSet.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to get resultSet.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(deviceId: string, query: Query, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified device ID and **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type                                                    | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId | string                                                       | Yes  | ID of the device to which the **KVStoreResultSet** object belongs.                          |
| query    | [Query](query)                                               | Yes  | **Query** object to match.                                              |
| callback | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Yes  | Callback invoked to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSet('localDeviceId', query, async function (err, result) {
            if (err != undefined) {
                console.error(`Fail to get resultSet.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the result set successfully.');
            resultSet = result;
            kvStore.closeResultSet(resultSet, function (err, data) {
                if (err != undefined) {
                    console.error(`Fail to close resultSet.code is ${err.code},message is ${err.message}`);
                    return;
                }
                console.log('Closed the result set successfully.');
            })
        });
    });
} catch (e) {
    console.error(`Fail to get resultSet.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(deviceId: string, query: Query): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified device ID and **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type      | Mandatory| Description                              |
| -------- | -------------- | ---- | ---------------------------------- |
| deviceId | string         | Yes  | ID of the device to which the **KVStoreResultSet** object belongs.|
| query    | [Query](query) | Yes  | **Query** object to match.                    |

**Return value**

| Type                                                  | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    const query = new distributedKVStore.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSet('localDeviceId', query).then((result) => {
        console.log('Obtained the result set successfully.');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultSet.code is ${err.code},message is ${err.message}`);
    });
    query.deviceId('localDeviceId');
    console.log("GetResultSet " + query.getSqlLike());
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully.');
    }).catch((err) => {
        console.error(`Fail to close resultSet.code is ${err.code},message is ${err.message}`);
    });

} catch (e) {
    console.error(`Fail to get resultSet.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(query: Query): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified **Query** object for this device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type          | Mandatory| Description          |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](query) | Yes  | **Query** object to match.|

**Return value**

| Type                                                | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise used to return Obtains a **KVStoreResultSet** object that matches the specified **Query** object for this device.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    const query = new distributedKVStore.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSet(query).then((result) => {
        console.log('Obtained the result set successfully');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}    
```

### getResultSet

getResultSet(deviceId: string, query: Query): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified device ID and **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type          | Mandatory| Description                              |
| -------- | -------------- | ---- | ---------------------------------- |
| deviceId | string         | Yes  | ID of the device to which the **KVStoreResultSet** object belongs.|
| query    | [Query](query) | Yes  | **Query** object to match.                    |

**Return value**

| Type                                                | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise used to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    const query = new distributedKVStore.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSet('localDeviceId', query).then((result) => {
        console.log('Obtained the result set successfully.');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultSet.code is ${err.code},message is ${err.message}`);
    });
    query.deviceId('localDeviceId');
    console.log("GetResultSet " + query.getSqlLike());
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully.');
    }).catch((err) => {
        console.error(`Fail to close resultSet.code is ${err.code},message is ${err.message}`);
    });

} catch (e) {
    console.error(`Fail to get resultSet.code is ${e.code},message is ${e.message}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified predicate object for this device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.             |
| callback   | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt;   | Yes  | Callback invoked to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let kvStore;
try {
    let resultSet;
    let predicates = new dataSharePredicates.DataSharePredicates();
    predicates.prefixKey("batch_test_string_key");
    kvStore.getResultSet(predicates, async function (err, result) {
        if (err != undefined) {
            console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Obtained the result set successfully');
        resultSet = result;
        kvStore.closeResultSet(resultSet, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Closed the result set successfully');
        })
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSet

getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified predicate object for this device. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.|

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let kvStore;
try {
    let resultSet;
    let predicates = new dataSharePredicates.DataSharePredicates();
    predicates.prefixKey("batch_test_string_key");
    kvStore.getResultSet(predicates).then((result) => {
        console.log('Obtained the result set successfully');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully');
    }).catch((err) => {
        console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSet

getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;KVStoreResultSet&gt;): void

Obtains a **KVStoreResultSet** object that matches the specified predicate object and device ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId  | string                                                       | Yes  | ID of the target device.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.             |
| callback   | AsyncCallback&lt;[KVStoreResultSet](#kvstoreresultset)&gt;   | Yes  | Callback invoked to return the **KVStoreResultSet** object obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let kvStore;
try {
    let resultSet;
    let predicates = new dataSharePredicates.DataSharePredicates();
    predicates.prefixKey("batch_test_string_key");
    kvStore.getResultSet('localDeviceId', predicates, async function (err, result) {
        if (err != undefined) {
            console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Obtained the result set successfully');
        resultSet = result;
        kvStore.closeResultSet(resultSet, function (err, data) {
            if (err != undefined) {
                console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Closed the result set successfully');
        })
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSet

getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise&lt;KVStoreResultSet&gt;

Obtains a **KVStoreResultSet** object that matches the specified predicate object and device ID. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                           |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| deviceId  | string                                                       | Yes  | ID of the target device.                                    |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | **DataSharePredicates** object that specifies the **KVStoreResultSet** object to obtain. If this parameter is **null**, define the processing logic.|

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise&lt;[KVStoreResultSet](#kvstoreresultset)&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates';
let kvStore;
try {
    let resultSet;
    let predicates = new dataSharePredicates.DataSharePredicates();
    predicates.prefixKey("batch_test_string_key");
    kvStore.getResultSet('localDeviceId', predicates).then((result) => {
        console.log('Obtained the result set successfully');
        resultSet = result;
    }).catch((err) => {
        console.error(`Fail to get resultset.code is ${err.code},message is ${err.message}`);
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('Closed the result set successfully');
    }).catch((err) => {
        console.error(`Fail to close resultset.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSize

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

Obtains the number of results that match the specified **Query** object for this device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                             |
| -------- | --------------------------- | ---- | ------------------------------------------------- |
| query    | [Query](query)              | Yes  | **Query** object to match.                                   |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the number of results that match the specified **Query** object.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSize(query, async function (err, resultSize) {
            if (err != undefined) {
                console.error(`Fail to get result size.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained the result set size successfully');
        });
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSize

getResultSize(query: Query): Promise&lt;number&gt;

Obtains the number of results that match the specified **Query** object for this device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type          | Mandatory| Description          |
| ------ | -------------- | ---- | -------------- |
| query  | [Query](query) | Yes  | **Query** object to match.|

**Return value**

| Type                 | Description                                                |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of results that match the specified **Query** object.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    const query = new distributedKVStore.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSize(query).then((resultSize) => {
        console.log('Obtained the result set size successfully');
    }).catch((err) => {
        console.error(`Fail to get result size.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`An unexpected error occured.code is ${e.code},message is ${e.code}`);
}
```

### getResultSize

getResultSize(deviceId: string, query: Query, callback: AsyncCallback&lt;number&gt;): void;

Obtains the number of results that matches the specified device ID and **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type                   | Mandatory| Description                                               |
| -------- | --------------------------- | ---- | --------------------------------------------------- |
| deviceId | string                      | Yes  | ID of the device to which the **KVStoreResultSet** object belongs.                 |
| query    | [Query](query)              | Yes  | **Query** object to match.                                     |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the number of results obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        if (err != undefined) {
            console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
            return;
        }
        console.log('Batch put data successfully.');
        const query = new distributedKVStore.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSize('localDeviceId', query, async function (err, resultSize) {
            if (err != undefined) {
                console.error(`Fail to get resultSize.code is ${err.code},message is ${err.message}`);
                return;
            }
            console.log('Obtained resultSize successfully');
            ;
        });
    });
} catch (e) {
    console.error(`Fail to get resultSize.code is ${e.code},message is ${e.message}`);
}
```

### getResultSize

getResultSize(deviceId: string, query: Query): Promise&lt;number&gt;

Obtains the number of results that matches the specified device ID and **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name  | Type      | Mandatory| Description                              |
| -------- | -------------- | ---- | ---------------------------------- |
| deviceId | string         | Yes  | ID of the device to which the **KVStoreResultSet** object belongs.|
| query    | [Query](query) | Yes  | **Query** object to match.                    |

**Return value**

| Type                 | Description                                                  |
| --------------------- | ------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of results obtained.|

**Error codes**

For details about the error codes, see [Distributed KV Store Error Codes](../errorcodes/errorcode-distributedKVStore.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 15100003     | Database corrupted.                    |
| 15100005     | Database or result set already closed. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key: key + i,
            value: {
                type: distributedKVStore.ValueType.STRING,
                value: 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('Batch put data successfully.');
    }).catch((err) => {
        console.error(`Fail to put batch.code is ${err.code},message is ${err.message}`);
    });
    var query = new distributedKVStore.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSize('localDeviceId', query).then((resultSize) => {
        console.log('Obtained resultSize successfully');
        ;
    }).catch((err) => {
        console.error(`Fail to get resultSize.code is ${err.code},message is ${err.message}`);
    });
} catch (e) {
    console.error(`Fail to get resultSize.code is ${e.code},message is ${e.message}`);
}
```
