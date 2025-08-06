# @ohos.data.distributedData (Distributed Data Management)

The distributed data management module implements collaboration between databases of different devices for applications. The APIs provided by distributed data management can be used to save data to distributed databases and perform operations such as adding, deleting, modifying, querying, and synchronizing data in distributed databases.

This module provides the following functions:

- [KVManager](#kvmanager): provides a **KVManager** instance to manage key-value (KV) stores.
- [KvStoreResultSet<sup>8+</sup>](#kvstoreresultset8): provides APIs to obtain the KV store result set and query or move the data read position.
- [Query<sup>8+</sup>](#query8): provides APIs to query data from the database through a **Query** instance by using predicates.
- [KVStore](#kvstore): provides APIs to add data, delete data, and observe data changes and data sync through a **KVStore** instance.
- [SingleKVStore](#singlekvstore): provides APIs to query and synchronize data in a single KV store. This class inherits from [KVStore](#kvstore), and data is not distinguished by device.
- [DeviceKVStore<sup>8+</sup>](#devicekvstore8): provides APIs to query and synchronize data in a device KV store. This class inherits from [KVStore](#kvstore), and data is distinguished by device.

>**NOTE**
>
>- The APIs provided by this module are no longer maintained since API version 9. You are advised to use [@ohos.data.distributedKVStore](js-apis-distributedKVStore.md).
>
>- The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>- All the APIs that need to obtain **deviceId** in this module are available only to system applications.


## Modules to Import

```js
import distributedData from '@ohos.data.distributedData';
```


## distributedData.createKVManager

createKVManager(config: KVManagerConfig, callback: AsyncCallback&lt;KVManager&gt;): void

Creates a **KVManager** instance to manage KV stores. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| config | [KVManagerConfig](#kvmanagerconfig) | Yes | Configuration of the **KVManager** instance, including the bundle name and user information of the caller.|
| callback | AsyncCallback&lt;[KVManager](#kvmanager)&gt; | Yes | Callback used to return the **KVManager** instance created.|

**Example**
```js

let kvManager;
try {
    const kvManagerConfig = {
        bundleName : 'com.example.datamanagertest',
        userInfo : {
            userId : '0',
            userType : distributedData.UserType.SAME_USER_ID
        }
    }
    distributedData.createKVManager(kvManagerConfig, function (err, manager) {
        if (err) {
            console.log("Failed to create KVManager: "  + JSON.stringify(err));
            return;
        }
        console.log("Created KVManager successfully");
        kvManager = manager;
    });
} catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

## distributedData.createKVManager

createKVManager(config: KVManagerConfig): Promise&lt;KVManager&gt;

Creates a **KVManager** instance to manage KV stores. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| config |[KVManagerConfig](#kvmanager) | Yes | Configuration of the **KVManager** instance, including the bundle name and user information of the caller.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[KVManager](#kvmanager)&gt; | Promise used to return the **KVManager** instance created.|

**Example**
```js

try {
  const kvManagerConfig = {
    bundleName: 'com.example.datamanagertest',
    userInfo: {
      userId: '0',
      userType: distributedData.UserType.SAME_USER_ID
    }
  }
  distributedData.createKVManager(kvManagerConfig).then((manager) => {
    console.log("Created KVManager successfully");
    kvManager = manager;
  }).catch((err) => {
    console.error("Failed to create KVManager: " + JSON.stringify(err));
  });
} catch (e) {
  console.log("An unexpected error occurred. Error:" + e);
}
```

## KVManagerConfig

Represents the configuration of a **KVManager** instance, including the bundle name and user information of the caller.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| userInfo | [UserInfo](#userinfo) | Yes | User information.|
| bundleName | string | Yes | Bundle name of the caller.|

## UserInfo

Defines user information.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name| Type| Mandatory| Description|
| ----- | ------ |------ | ------ |
| userId | string | No | User ID. The default value is **0**.|
| userType | [UserType](#usertype) | No | User type. The default value is **0**.|


## UserType

Enumerates the user types.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name| Value| Description|
| ----- | ------ | ------ |
| SAME_USER_ID | 0 | User who logs in to different devices using the same account.|


## KVManager

Creates a **KVManager** object to obtain KV store information. Before calling any method in **KVManager**, you must use [createKVManager](#distributeddatacreatekvmanager) to create a **KVManager** object.

### getKVStore

getKVStore&lt;T extends KVStore&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void

Creates and obtains a KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| storeId | string | Yes | Unique identifier of the KV store. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| options | [Options](#options) | Yes | Configuration of the KV store.|
| callback | AsyncCallback&lt;T&gt; | Yes | Callback used to return the KV store instance created.|

**Example**

```js
let kvStore;
let kvManager;
try {
    const options = {
        createIfMissing : true,
        encrypt : false,
        backup : false,
        autoSync : true,
        kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,
        securityLevel : distributedData.SecurityLevel.S3,
    };
    kvManager.getKVStore('storeId', options, function (err, store) {
        if (err) {
            console.log("getKVStore err: "  + JSON.stringify(err));
            return;
        }
        console.log("getKVStore success");
        kvStore = store;
    });
} catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```


### getKVStore

getKVStore&lt;T extends KVStore&gt;(storeId: string, options: Options): Promise&lt;T&gt;

Creates and obtains a KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type               | Mandatory | Description   |
| ------- | ---------------------- | ---- | -------------------- |
| storeId  | string      | Yes  | Unique identifier of the KV store. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| options  | [Options](#options)   | Yes  | Configuration of the KV store.|


**Return value**

| Type                                   | Description       |
| -------------------------------------- | ------------------------ |
| Promise&lt;T&gt;, &lt;T extends [KVStore](#kvstore)&gt; | Promise used to return the KV store instance created.|

**Example**

```js
let kvStore;
let kvManager;
try {
    const options = {
        createIfMissing : true,
        encrypt : false,
        backup : false,
        autoSync : true,
        kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,
        securityLevel : distributedData.SecurityLevel.S3,
    };
    kvManager.getKVStore('storeId', options).then((store) => {
        console.log("getKVStore success");
        kvStore = store;
    }).catch((err) => {
        console.log("getKVStore err: "  + JSON.stringify(err));
    });
} catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

### closeKVStore<sup>8+</sup>

closeKVStore(appId: string, storeId: string, kvStore: KVStore, callback: AsyncCallback&lt;void&gt;): void

Closes a KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**


| Name  | Type             | Mandatory| Description        |
| ------- | -----------------   | ---- | --------------------------- |
| appId    | string              | Yes  | Bundle name of the app that invokes the KV store.        |
| storeId  | string  | Yes  | Unique identifier of the KV store to close. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| kvStore  | [KVStore](#kvstore) | Yes  | KV store to close.    |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
let kvStore;
let kvManager;
const options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: false,
    kvStoreType: distributedData.KVStoreType.SINGLE_VERSION,
    schema: undefined,
    securityLevel: distributedData.SecurityLevel.S3,
}
try {
    kvManager.getKVStore('storeId', options, async function (err, store) {
        console.log('getKVStore success');
        kvStore = store;
        kvManager.closeKVStore('appId', 'storeId', kvStore, function (err, data) {
            console.log('closeKVStore success');
        });
    });
} catch (e) {
    console.log('closeKVStore e ' + e);
}
```


### closeKVStore<sup>8+</sup>

closeKVStore(appId: string, storeId: string, kvStore: KVStore): Promise&lt;void&gt;

Closes a KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description       |
| -----  | ------  | ---- | ----------------------------- |
| appId  | string  | Yes  | Bundle name of the app that invokes the KV store.           |
| storeId | string | Yes  | Unique identifier of the KV store to close. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| kvStore | [KVStore](#kvstore)  | Yes  | KV store to close.       |

**Return value**

| Type         | Description           |
| ------------- | -------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
let kvManager;
let kvStore;
const options = {
    createIfMissing: true,
    encrypt: false,
    backup: false,
    autoSync: false,
    kvStoreType: distributedData.KVStoreType.SINGLE_VERSION,
    schema: undefined,
    securityLevel: distributedData.SecurityLevel.S3,
}
try {
    kvManager.getKVStore('storeId', options).then(async (store) => {
        console.log('getKVStore success');
        kvStore = store;
        kvManager.closeKVStore('appId', 'storeId', kvStore).then(() => {
            console.log('closeKVStore success');
        }).catch((err) => {
            console.log('closeKVStore err ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('CloseKVStore getKVStore err ' + JSON.stringify(err));
    });
} catch (e) {
    console.log('closeKVStore e ' + e);
}
```


### deleteKVStore<sup>8+</sup>

deleteKVStore(appId: string, storeId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| appId  | string  | Yes  | Bundle name of the app that invokes the KV store.    |
| storeId | string | Yes  | Unique identifier of the KV store to delete. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| callback | AsyncCallback&lt;void&gt;  | Yes  | Callback used to return the result.|

**Example**

```js
let kvManager;
let kvStore;
const options = {
    createIfMissing : true,
    encrypt : false,
    backup : false,
    autoSync : true,
    kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,
    schema : undefined,
    securityLevel : distributedData.SecurityLevel.S3,
}
try {
    kvManager.getKVStore('store', options, async function (err, store) {
        console.log('getKVStore success');
        kvStore = store;
        kvManager.deleteKVStore('appId', 'storeId', function (err, data) {
            console.log('deleteKVStore success');
        });
    });
} catch (e) {
    console.log('DeleteKVStore e ' + e);
}
```

### deleteKVStore<sup>8+</sup>

deleteKVStore(appId: string, storeId: string): Promise&lt;void&gt;

Deletes a KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| appId  | string  | Yes  | Bundle name of the app that invokes the KV store.    |
| storeId | string | Yes  | Unique identifier of the KV store to delete. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|


**Return value**

| Type         | Description           |
| ------------- | -------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let kvManager;
let kvStore;
const options = {
    createIfMissing : true,
    encrypt : false,
    backup : false,
    autoSync : true,
    kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,
    schema : undefined,
    securityLevel : distributedData.SecurityLevel.S3,
}
try {
    kvManager.getKVStore('storeId', options).then(async (store) => {
        console.log('getKVStore success');
        kvStore = store;
        kvManager.deleteKVStore('appId', 'storeId').then(() => {
            console.log('deleteKVStore success');
        }).catch((err) => {
            console.log('deleteKVStore err ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('getKVStore err ' + JSON.stringify(err));
    });
} catch (e) {
    console.log('deleteKVStore e ' + e);
}
```


### getAllKVStoreId<sup>8+</sup>

getAllKVStoreId(appId: string, callback: AsyncCallback&lt;string[]&gt;): void

Obtains the IDs of all KV stores that are created by [getKVStore()](#getkvstore) and have not been deleted by [deleteKVStore()](#deletekvstore8). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| appId  | string  | Yes   | Bundle name of the app that invokes the KV store.    |
| callback | AsyncCallback&lt;string[]&gt; | Yes  |Callback used to return the IDs of all created KV stores.|

**Example**

```js
let kvManager;
try {
    kvManager.getAllKVStoreId('appId', function (err, data) {
        console.log('GetAllKVStoreId success');
        console.log('GetAllKVStoreId size = ' + data.length);
    });
} catch (e) {
    console.log('GetAllKVStoreId e ' + e);
}
```


### getAllKVStoreId<sup>8+</sup>

getAllKVStoreId(appId: string): Promise&lt;string[]&gt;

Obtains the IDs of all KV stores that are created by [getKVStore()](#getkvstore) and have not been deleted by [deleteKVStore()](#deletekvstore8). This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| appId  | string  | Yes   | Bundle name of the app that invokes the KV store.    |


**Return value**

| Type         | Description           |
| ------------- | -------------- |
| Promise&lt;string[]&gt;| Promise used to return the IDs of all created KV stores.|

**Example**

```js
let kvManager;
try {
    console.log('GetAllKVStoreId');
    kvManager.getAllKVStoreId('appId').then((data) => {
        console.log('getAllKVStoreId success');
        console.log('size = ' + data.length);
    }).catch((err) => {
        console.log('getAllKVStoreId err ' + JSON.stringify(err));
    });
} catch(e) {
    console.log('getAllKVStoreId e ' + e);
}
```


### on('distributedDataServiceDie')<sup>8+</sup>

on(event: 'distributedDataServiceDie', deathCallback: Callback&lt;void&gt;): void

Subscribes to service status changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| event  | string | Yes   | Event type. The value is **distributedDataServiceDie**, which indicates service status changes.|
| deathCallback  | Callback&lt;void&gt;  | Yes   | Callback used to return the result.|

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
    console.log("An unexpected error occurred. Error:" + e);
}
```


### off('distributedDataServiceDie')<sup>8+</sup>

off(event: 'distributedDataServiceDie', deathCallback?: Callback&lt;void&gt;): void

Unsubscribes from service status changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| event  | string | Yes   | Event type. The value is **distributedDataServiceDie**, which indicates service status changes.|
| deathCallback  | Callback&lt;void&gt;  | No   | Callback to unregister. If this parameter is not specified, all callbacks for service status changes will be unregistered.|


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
    console.log("An unexpected error occurred. Error:" + e);
}
    
```

## Options

Provides KV store configuration.


| Name | Type| Mandatory  | Description                   |
| -----  | ------  | ------  | -------------------|
| createIfMissing  | boolean | No| Whether to create a KV store if the database file does not exist. The default value is **true**, which means to create a KV store.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |
| encrypt  | boolean | No|Whether to encrypt the KV store. The default value is **false**, which means the KV store is not encrypted.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core    |
| backup  | boolean | No|Whether to back up the KV store. The default value is **true**, which means to back up the KV store.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |
| autoSync  | boolean | No|Whether to automatically synchronize database files. The default value is **false**, which means the database files are manually synchronized.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core<br>**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC    |
| kvStoreType | [KVStoreType](#kvstoretype) | No|Type of the KV store to create. The default value is **DEVICE_COLLABORATION**, which indicates a device KV store.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| securityLevel | [SecurityLevel](#securitylevel) | No|Security level (S1 to S4) of the KV store.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core |
| schema<sup>8+</sup> | [Schema](#schema8) | No| Schema that defines the values stored in the KV store. The default value is **undefined**, which means no schema is used.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore|


## KVStoreType

Enumerates the KV store types.


| Name | Value| Description                   |
| ---   | ----  | ----------------------- |
| DEVICE_COLLABORATION  | 0 | Device KV store.<br>The device KV store manages data by device, which eliminates conflicts. Data can be queried by device.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore  |
| SINGLE_VERSION  | 1 | Single KV store.<br>The single KV store does not differentiate data by device. If the same key is modified by different devices, the data will be overwritten.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| MULTI_VERSION   | 2 | Multi-version KV store. This type is not supported currently.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore|


## SecurityLevel

Enumerates the KV store security levels.

| Name | Value| Description                   |
| ---   | ----  | ----------------------- |
| NO_LEVEL  | 0 | No security level is set for the KV store (deprecated).<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore  |
| S0  | 1 | The KV store security level is public (deprecated).<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |
| S1  | 2 | Low security level. If data leakage occurs, minor impact will be caused. For example, a KV store that contains system data such as wallpapers.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |
| S2  | 3 | Medium security level. If data leakage occurs, moderate impact will be caused. For example, a KV store that contains information created by users or call records, such as audio or video clips.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |
| S3  | 5 | High security level. If data leakage occurs, major impact will be caused. For example, a KV store that contains information such as user fitness, health, and location data.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |
| S4  | 6 | Critical security level. If data leakage occurs, severe impact will be caused. For example, a KV store that contains information such as authentication credentials and financial data.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |


## Constants

Defines the KV store constants.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Value| Description                   |
| ---   | ----  | ----------------------- |
| MAX_KEY_LENGTH  | 1024 | Maximum length of a key in the KV store, in bytes. |
| MAX_VALUE_LENGTH  | 4194303 | Maximum length of a value in the KV store, in bytes. |
| MAX_KEY_LENGTH_DEVICE  | 896 | Maximum length of a device key, in bytes.|
| MAX_STORE_ID_LENGTH  | 128 | Maximum length of a KV store ID, in bytes. |
| MAX_QUERY_LENGTH  | 512000 | Maximum query length, in bytes.|
| MAX_BATCH_SIZE  | 128 | Maximum number of batch operations.|

## Schema<sup>8+</sup>

Defines the schema of a KV store. You can create a **Schema** object and place it in [Options](#options) when creating or opening a KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| Name | Type| Readable| Writable| Description                   |
| ---   | ----  | ----  | ----  | ----------------------- |
| root<sup>8+</sup>  | [FieldNode](#fieldnode8) | Yes| Yes| JSON root object.|
| indexes<sup>8+</sup>  | Array\<string> | Yes| Yes| String array in JSON format. |
| mode<sup>8+</sup>  | number | Yes| Yes| Schema mode. |
| skip<sup>8+</sup>  | number | Yes| Yes|  Size of a skip of the schema. |

### constructor<sup>8+</sup> 

constructor()

A constructor used to create a **Schema** instance.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

## FieldNode<sup>8+</sup>

Represents a **Schema** instance, which provides the APIs for defining the values stored in a KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| Name | Type| Readable| Writable| Description                   |
| ---   | ----  | ----  | ----  | ----------------------- |
| nullable<sup>8+</sup>  | boolean | Yes| Yes| Whether the database field can be null.  |
| default<sup>8+</sup>  | string | Yes| Yes| Default value of a **FieldNode**.|
| type<sup>8+</sup>  | number | Yes| Yes| Value of the data type corresponding to the specified node.|

### constructor<sup>8+</sup>

constructor(name: string)

A constructor used to create a **FieldNode** instance with a string field.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name| Type| Mandatory| Description           |
| ------ | -------- | ---- | --------------- |
| name   | string   | Yes  | Value of **FieldNode**.|

### appendChild<sup>8+</sup>

appendChild(child: FieldNode): boolean

Appends a child node to this **FieldNode**.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| child  | [FieldNode](#fieldnode8) | Yes   | Child node to append.  |

**Return value**

| Type         | Description           |
| ------------- | -------------- |
| boolean |Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
import ddm from '@ohos.data.distributedData';
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


## KvStoreResultSet<sup>8+</sup>

Provides APIs to obtain the KV store result sets, and query and move the data read position.

Before calling any method in **KvStoreResultSet**, you must use [getKVStore](#getkvstore) to obtain a **KVStore** object.


### getCount<sup>8+</sup>

getCount(): number

Obtains the total number of rows in the result set.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type  | Description              |
| ------ | --------------    |
| number |Total number of rows obtained.         |

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

### getPosition<sup>8+</sup>

getPosition(): number

Obtains the current data read position (position from which data is read) in the result set.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type  | Description              |
| ------ | --------------    |
| number |Current data read position obtained.  |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet succeeded.');
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


### moveToFirst<sup>8+</sup>

moveToFirst(): boolean

Moves the data read position to the first row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the operation is successful; returns **false** otherwise.  |

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


### moveToLast<sup>8+</sup>

moveToLast(): boolean

Moves the data read position to the last row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the operation is successful; returns **false** otherwise.  |

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


### moveToNext<sup>8+</sup>

moveToNext(): boolean

Moves the data read position to the next row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the operation is successful; returns **false** otherwise.  |

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


### moveToPrevious<sup>8+</sup>

moveToPrevious(): boolean

Moves the data read position to the previous row. If the result set is empty, **false** will be returned.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the operation is successful; returns **false** otherwise.  |

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


### move<sup>8+</sup>

move(offset: number): boolean

Moves the data read position with the specified offset from the current position.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| offset  | number  | Yes   | Offset to move the data read position. A negative value means to move backward, and a positive value means to move forward.  |

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the operation is successful; returns **false** otherwise.  |

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
    const moved5 = resultSet.move(1);
    console.log("move succeed:" + moved5);
} catch (e) {
    console.log("move failed: " + e);
}
```


### moveToPosition<sup>8+</sup>

moveToPosition(position: number): boolean

Moves the data read position from 0 to an absolute position.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| position  | number  | Yes   |Absolute position to move to.         |

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the operation is successful; returns **false** otherwise.  |

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
    const moved6 = resultSet.moveToPosition(1);
    console.log("moveToPosition succeed: " + moved6);
} catch (e) {
    console.log("moveToPosition failed: " + e);
}
```


### isFirst<sup>8+</sup>

isFirst(): boolean

Checks whether the data read position is the first row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the first row is being read; returns **false** otherwise.  |

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


### isLast<sup>8+</sup>

isLast(): boolean

Checks whether the data read position is the last row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the last row is being read; returns **false** otherwise.  |

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

### isBeforeFirst<sup>8+</sup>

isBeforeFirst(): boolean

Checks whether the data read position is before the first row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the data read position is before the first row; returns **false** otherwise. |

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


### isAfterLast<sup>8+</sup>

isAfterLast(): boolean

Checks whether the data read position is after the last row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the data read position is after the last row; returns **false** otherwise. |

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


### getEntry<sup>8+</sup>

getEntry(): Entry

Obtains the KV pair from the current position.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Entry](#entry) |KV pair obtained.|

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


## Query<sup>8+</sup>

Provides APIs to create a **Query** object, which defines different data query criteria.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

### constructor<sup>8+</sup>

constructor() 

A constructor used to create a **Schema** instance.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core


### reset<sup>8+</sup>

reset(): Query

Resets the **Query** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core


**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object reset.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.equalTo("key", "value");
    console.log("query is " + query.getSqlLike());
    query.reset();
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("simply calls should be ok :" + e);
}
```


### equalTo<sup>8+</sup>

equalTo(field: string, value: number|string|boolean): Query

Creates a **Query** object to search for the records with the specified field that are equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | number\|string\|boolean  | Yes   | Value to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.equalTo("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### notEqualTo<sup>8+</sup>

notEqualTo(field: string, value: number|string|boolean): Query

Creates a **Query** object to search for the records with the specified field that are not equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | number\|string\|boolean  | Yes   | Value to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### greaterThan<sup>8+</sup>

greaterThan(field: string, value: number|string|boolean): Query

Creates a **Query** object to search for the records with the specified field that are greater than the given value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | number\|string\|boolean  | Yes   | Value to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.greaterThan("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### lessThan<sup>8+</sup>

lessThan(field: string, value: number|string): Query

Creates a **Query** object to search for the records with the specified field that are less than the given value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | number\|string  | Yes   | Value to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.lessThan("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### greaterThanOrEqualTo<sup>8+</sup>

greaterThanOrEqualTo(field: string, value: number|string): Query

Creates a **Query** object to search for the records with the specified field that are greater than or equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | number\|string  | Yes   | Value to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.greaterThanOrEqualTo("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### lessThanOrEqualTo<sup>8+</sup>

lessThanOrEqualTo(field: string, value: number|string): Query

Creates a **Query** object to search for the records with the specified field that are less than or equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | number\|string  | Yes   | Value to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.lessThanOrEqualTo("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### isNull<sup>8+</sup>

isNull(field: string): Query

Creates a **Query** object to search for the records with the specified field that are **null**.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.isNull("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### inNumber<sup>8+</sup>

inNumber(field: string, valueList: number[]): Query

Creates a **Query** object to search for the records with the specified field that are within the given number list.


**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| valueList  | number[]  | Yes   | List of numbers to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.inNumber("field", [0, 1]);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### inString<sup>8+</sup>

inString(field: string, valueList: string[]): Query

Creates a **Query** object to search for the records with the specified field that are within the given string list.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| valueList  | string[]  | Yes   | List of strings to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.inString("field", ['test1', 'test2']);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### notInNumber<sup>8+</sup>

notInNumber(field: string, valueList: number[]): Query

Creates a **Query** object to search for the records with the specified field that are not within the given number list.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| valueList  | number[]  | Yes   | List of numbers to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notInNumber("field", [0, 1]);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### notInString<sup>8+</sup>

notInString(field: string, valueList: string[]): Query

Creates a **Query** object to search for the records with the specified field that are not within the given string list.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| valueList  | string[]  | Yes   | List of strings to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notInString("field", ['test1', 'test2']);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### like<sup>8+</sup>

like(field: string, value: string): Query

Creates a **Query** object to search for the records with the specified field that are similar to the given string.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | string  | Yes   | String to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.like("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### unlike<sup>8+</sup>

unlike(field: string, value: string): Query

Creates a **Query** object to search for the records with the specified field that are not similar to the given string.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |
| value  | string  | Yes   | String to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.unlike("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### and<sup>8+</sup>

and(): Query

Creates a **Query** object with the AND condition.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value1");
    query.and();
    query.notEqualTo("field", "value2");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### or<sup>8+</sup>

or(): Query

Creates a **Query** object with the OR condition.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value1");
    query.or();
    query.notEqualTo("field", "value2");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### orderByAsc<sup>8+</sup>

orderByAsc(field: string): Query

Creates a **Query** object to sort the query results in ascending order.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value");
    query.orderByAsc("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### orderByDesc<sup>8+</sup>

orderByDesc(field: string): Query

Creates a **Query** object to sort the query results in descending order.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value");
    query.orderByDesc("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### limit<sup>8+</sup>

limit(total: number, offset: number): Query

Creates a **Query** object to specify the number of records in the query result and the start position.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| total  | number  | Yes   |Number of records in the query result. |
| offset | number  | Yes   |Start position. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
let total = 10;
let offset = 1;
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value");
    query.limit(total, offset);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### isNotNull<sup>8+</sup>

isNotNull(field: string): Query

Creates a **Query** object to search for the records whose value is not **null**.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| field  | string  | Yes   |Field to query. It cannot contain '^'.     |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.isNotNull("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### beginGroup<sup>8+</sup>

beginGroup(): Query

Creates a **Query** object for a query condition group with a left parenthesis.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.beginGroup();
    query.isNotNull("field");
    query.endGroup();
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### endGroup<sup>8+</sup>

endGroup(): Query

Creates a **Query** object for a query condition group with a right parenthesis.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.beginGroup();
    query.isNotNull("field");
    query.endGroup();
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### prefixKey<sup>8+</sup>

prefixKey(prefix: string): Query

Creates a **Query** object with a specified key prefix.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| prefix | string  | Yes   |Key prefix.    |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.prefixKey("$.name");
    query.prefixKey("0");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("duplicated calls should be ok :" + e);
}
```


### setSuggestIndex<sup>8+</sup>

setSuggestIndex(index: string): Query

Creates a **Query** object with an index preferentially used for query.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| index  | string  | Yes   |Index preferentially used for query.  |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.setSuggestIndex("$.name");
    query.setSuggestIndex("0");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
   console.log("duplicated calls should be ok :" + e);
}
```


### deviceId<sup>8+</sup>

deviceId(deviceId:string):Query

Creates a **Query** object with the device ID as the key prefix.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| deviceId | string  | Yes   |Device ID.  |


**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.deviceId("deviceId");
    console.log("query is " + query.getSqlLike());
} catch (e) {
    console.log("should be ok on Method Chaining : " + e);
}
```


### getSqlLike<sup>8+</sup>

getSqlLike():string

Obtains the query statement of the **Query** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| string |Query statement obtained.|

**Example**

```js
try {
    let query = new distributedData.Query();
    let sql1 = query.getSqlLike();
    console.log("GetSqlLike sql=" + sql1);
} catch (e) {
    console.log("duplicated calls should be ok : " + e);
}
```


## KVStore

Provides APIs to manage data in a KV store, for example, adding or deleting data and subscribing to data changes or completion of data sync.

Before calling any method in **KVStore**, you must use [getKVStore](#getkvstore) to obtain a **KVStore** object.

### put

put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback&lt;void&gt;): void

Adds a KV pair of the specified type to this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    | string  | Yes   |Key of the KV pair to add. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).  |
| value  | Uint8Array \| string \| number \| boolean | Yes   |Value of the KV pair to add. The value type can be Uint8Array, number, string, or boolean. A value of the Uint8Array or string type cannot exceed [MAX_VALUE_LENGTH](#constants).  |
| callback | AsyncCallback&lt;void&gt; | Yes   |Callback used to return the result.  |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
        if (err != undefined) {
            console.log("put err: " + JSON.stringify(err));
            return;
        }
        console.log("put success");
    });
}catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
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

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
        console.log("put success: " + JSON.stringify(data));
    }).catch((err) => {
        console.log("put err: " + JSON.stringify(err));
    });
}catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a KV pair from this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    | string  | Yes   |Key of the KV pair to delete. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).  |
| callback  | AsyncCallback&lt;void&gt;  | Yes   |Callback used to return the result.  |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
        if (err != undefined) {
            console.log("put err: " + JSON.stringify(err));
            return;
        }
        console.log("put success");
        kvStore.delete(KEY_TEST_STRING_ELEMENT, function (err,data) {
            if (err != undefined) {
                console.log("delete err: " + JSON.stringify(err));
                return;
            }
            console.log("delete success");
        });
    });
}catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

### delete

delete(key: string): Promise&lt;void&gt;

Deletes a KV pair from this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    | string  | Yes   |Key of the KV pair to delete. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants).  |

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
        console.log("put success: " + JSON.stringify(data));
        kvStore.delete(KEY_TEST_STRING_ELEMENT).then((data) => {
            console.log("delete success");
        }).catch((err) => {
            console.log("delete err: " + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log("put err: " + JSON.stringify(err));
    });
}catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

### on('dataChange')

on(event: 'dataChange', type: SubscribeType, listener: Callback&lt;ChangeNotification&gt;): void

Subscribes to data changes of the specified type.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------- |
| event    | string                                                    | Yes  | Event type. The value is **dataChange**, which indicates data changes.|
| type     | [SubscribeType](#subscribetype)                           | Yes  | Type of data change.                                    |
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | Yes  | Callback used to return the result.                                          |

**Example**

```js
let kvStore;
kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {
    console.log("dataChange callback call data: " + JSON.stringify(data));
});
```

### on('syncComplete')

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Subscribes to sync completion events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                  |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------ |
| event        | string                                        | Yes  | Event type. The value is **syncComplete**, which indicates a sync completion event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback used to return a sync completion event.            |

**Example**

```js
let kvStore;
kvStore.on('syncComplete', function (data) {
    console.log("callback call data: " + data);
});
```

### off('dataChange')<sup>8+</sup>

off(event:'dataChange', listener?: Callback&lt;ChangeNotification&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                    |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------------------------- |
| event    | string                                                    | Yes  | Event type. The value is **dataChange**, which indicates data changes.|
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | No  | Callback to unregister. If this parameter is not specified, all callbacks for data changes will be unregistered.|



**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log("dataChange: " + data);
    }
    subscribeDataChange() {
        if (kvStore != null) {
            kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);
        }
    }
    unsubscribeDataChange() {
        if (kvStore != null) {
            kvStore.off('dataChange', this.call);
        }
    }
}
```

### off('syncComplete')<sup>8+</sup>

off(event: 'syncComplete', syncCallback?: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Unsubscribes from sync completion events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                      |
| ------------ | --------------------------------------------- | ---- | ---------------------------------------------------------- |
| event        | string                                        | Yes  | Event type. The value is **syncComplete**, which indicates a sync completion event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | No  | Callback to unregister. If this parameter is not specified, all callbacks for data changes will be unregistered.|

**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log("syncComplete: " + data);
    }
    subscribeSyncComplete() {
        if (kvStore != null) {
            kvStore.on('syncComplete', this.call);
        }
    }
    unsubscribeSyncComplete() {
        if (kvStore != null) {
            kvStore.off('syncComplete', this.call);
        }
    }
}
```

### putBatch<sup>8+</sup>

putBatch(entries: Entry[], callback: AsyncCallback&lt;void&gt;): void

Inserts KV pairs in batches to this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| entries  |[Entry](#entry)[] | Yes   |KV pairs to insert in batches. |
| callback |AsyncCallback&lt;void&gt; |Yes    |Callback used to return the result.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries, async function (err,data) {
        console.log('putBatch success');
        kvStore.getEntries('batch_test_string_key', function (err,entries) {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
        });
    });
}catch(e) {
    console.log('PutBatch e ' + JSON.stringify(e));
}
```


### putBatch<sup>8+</sup>

putBatch(entries: Entry[]): Promise&lt;void&gt;

Inserts KV pairs in batches to this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| entries  |[Entry](#entry)[] | Yes   |KV pairs to insert in batches. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
        kvStore.getEntries('batch_test_string_key').then((entries) => {
            console.log('getEntries success');
            console.log('PutBatch ' + JSON.stringify(entries));
        }).catch((err) => {
            console.log('getEntries fail ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('PutBatch e ' + JSON.stringify(e));
}
```

### deleteBatch<sup>8+</sup>

deleteBatch(keys: string[], callback: AsyncCallback&lt;void&gt;): void

Deletes KV pairs in batches from this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keys  |string[] | Yes   |KV pairs to delete in batches. |
| callback  |AsyncCallback&lt;void&gt; | Yes   |Callback used to return the result. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    let keys = [];
    for (var i = 0; i < 5; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
        keys.push(key + i);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries, async function (err,data) {
        console.log('putBatch success');
        kvStore.deleteBatch(keys, async function (err,data) {
            console.log('deleteBatch success');
        });
    });
}catch(e) {
    console.log('DeleteBatch e ' + e);
}
```


### deleteBatch<sup>8+</sup>

deleteBatch(keys: string[]): Promise&lt;void&gt;

Deletes KV pairs in batches from this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keys   |string[] | Yes   |KV pairs to delete in batches. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    let keys = [];
    for (var i = 0; i < 5; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
        keys.push(key + i);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
        kvStore.deleteBatch(keys).then((err) => {
            console.log('deleteBatch success');
        }).catch((err) => {
            console.log('deleteBatch fail ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('DeleteBatch e ' + e);
}
```


### startTransaction<sup>8+</sup>

startTransaction(callback: AsyncCallback&lt;void&gt;): void

Starts the transaction in this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| callback  |AsyncCallback&lt;void&gt; | Yes   |Callback used to return the result. |

**Example**

```js
let kvStore;
function putBatchString(len, prefix) {
    let entries = [];
    for (var i = 0; i < len; i++) {
        var entry = {
            key : prefix + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    return entries;
}
try {
    var count = 0;
    kvStore.on('dataChange', 0, function (data) {
        console.log('startTransaction 0' + data)
        count++;
    });
    kvStore.startTransaction(async function (err,data) {
        console.log('startTransaction success');
        let entries = putBatchString(10, 'batch_test_string_key');
        console.log('entries: ' + JSON.stringify(entries));
        kvStore.putBatch(entries, async function (err,data) {
            console.log('putBatch success');
        });
    });
}catch(e) {
    console.log('startTransaction e ' + e);
}
```


### startTransaction<sup>8+</sup>

startTransaction(): Promise&lt;void&gt;

Starts the transaction in this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    var count = 0;
    kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_ALL, function (data) {
        console.log('startTransaction ' + JSON.stringify(data));
        count++;
    });
    kvStore.startTransaction().then(async (err) => {
        console.log('startTransaction success');
    }).catch((err) => {
        console.log('startTransaction fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('startTransaction e ' + e);
}
```


### commit<sup>8+</sup>

commit(callback: AsyncCallback&lt;void&gt;): void

Commits the transaction in this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| callback  |AsyncCallback&lt;void&gt; | Yes   |Callback used to return the result. |

**Example**

```js
let kvStore;
try {
    kvStore.commit(function (err,data) {
        if (err == undefined) {
            console.log('commit success');
        } else {
            console.log('commit fail');
        }
    });
}catch(e) {
    console.log('Commit e ' + e);
}
```


### commit<sup>8+</sup>

commit(): Promise&lt;void&gt;

Commits the transaction in this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    kvStore.commit().then(async (err) => {
        console.log('commit success');
    }).catch((err) => {
        console.log('commit fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('Commit e ' + e);
}
```


### rollback<sup>8+</sup>

rollback(callback: AsyncCallback&lt;void&gt;): void

Rolls back the transaction in this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| callback  |AsyncCallback&lt;void&gt; | Yes   |Callback used to return the result. |

**Example**

```js
let kvStore;
try {
    kvStore.rollback(function (err,data) {
        if (err == undefined) {
            console.log('commit success');
        } else {
            console.log('commit fail');
        }
    });
}catch(e) {
    console.log('Rollback e ' + e);
}
```


### rollback<sup>8+</sup>

rollback(): Promise&lt;void&gt;

Rolls back the transaction in this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    kvStore.rollback().then(async (err) => {
        console.log('rollback success');
    }).catch((err) => {
        console.log('rollback fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('Rollback e ' + e);
}
```


### enableSync<sup>8+</sup>

enableSync(enabled: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets data sync, which can be enabled or disabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| enabled  |boolean | Yes   |Whether to enable data sync. The value **true** means to enable data sync, and **false** means the opposite. |
| callback  |AsyncCallback&lt;void&gt; | Yes   |Callback used to return the result. |

**Example**

```js
let kvStore;
try {
    kvStore.enableSync(true, function (err,data) {
        if (err == undefined) {
            console.log('enableSync success');
        } else {
            console.log('enableSync fail');
        }
    });
}catch(e) {
    console.log('EnableSync e ' + e);
}
```


### enableSync<sup>8+</sup>

enableSync(enabled: boolean): Promise&lt;void&gt;

Sets data sync, which can be enabled or disabled. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| enabled  |boolean | Yes   |Whether to enable data sync. The value **true** means to enable data sync, and **false** means the opposite. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    kvStore.enableSync(true).then((err) => {
        console.log('enableSync success');
    }).catch((err) => {
        console.log('enableSync fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('EnableSync e ' + e);
}
```


### setSyncRange<sup>8+</sup>

setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback&lt;void&gt;): void

Sets the data sync range. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| localLabels  |string[] | Yes   |Sync labels set for the local device. |
| remoteSupportLabels  |string[] | Yes   |Sync labels set for remote devices. |
| callback  |AsyncCallback&lt;void&gt; | Yes   |Callback used to return the result. |

**Example**

```js
let kvStore;
try {
    const localLabels = ['A', 'B'];
    const remoteSupportLabels = ['C', 'D'];
    kvStore.setSyncRange(localLabels, remoteSupportLabels, function (err,data) {
        console.log('SetSyncRange put success');
    });
}catch(e) {
    console.log('SetSyncRange e ' + e);
}
```


### setSyncRange<sup>8+</sup>

setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise&lt;void&gt;

Sets the data sync range. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| localLabels  |string[] | Yes   |Sync labels set for the local device. |
| remoteSupportLabels  |string[] | Yes   |Sync labels set for remote devices. |


**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    const localLabels = ['A', 'B'];
    const remoteSupportLabels = ['C', 'D'];
    kvStore.setSyncRange(localLabels, remoteSupportLabels).then((err) => {
        console.log('setSyncRange success');
    }).catch((err) => {
        console.log('delete fail ' + err);
    });
}catch(e) {
    console.log('SetSyncRange e ' + e);
}
```


## SubscribeType

Enumerates the subscription types.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Value  | Description                   |
| -----  | ------   | ----------------------- |
| SUBSCRIBE_TYPE_LOCAL  |0 |Local data changes. |
| SUBSCRIBE_TYPE_REMOTE |1 |Remote data changes. |
| SUBSCRIBE_TYPE_ALL  |2 |Local and remote data changes. |

## ChangeNotification

Defines the content of data change notifications, including inserted data, updated data, deleted data, and device ID.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type  |Mandatory  | Description                   |
| ----- | -------   | ------|------------------------ |
| insertEntries | [Entry](#entry)[]   | Yes|Data inserted.  |
| updateEntries | [Entry](#entry)[]   | Yes|Data updated.  |
| deleteEntries | [Entry](#entry)[]   | Yes|Data deleted.  |
| deviceId | string   | Yes|UUID of the device. |

## Entry

Defines the KV pairs stored in the KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type  |Mandatory  | Description                   |
| ----- | -------   | ------|------------------------ |
| key | string   | Yes|Key of the KV pair stored in the KV store.  |
| value | [Value](#value) | Yes|Value of the KV pair stored in the KV store.  |


## Value

Defines the **value** object in a KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type  |Mandatory  | Description                   |
| ----- | -------   | ------|------------------------ |
| type | [ValueType](#value)   | Yes|Type of the value.  |
| value | Uint8Array \| string \| number \| boolean| Yes|Value of the KV pair stored in the KV store.  |

## ValueType

Enumerates the data types.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Value  | Description                   |
| -----  | ------   | ----------------------- |
| STRING  |0 |String. |
| INTEGER |1 |Integer. |
| FLOAT   |2 |Float (single-precision floating point). |
| BYTE_ARRAY   |3 |Byte array. |
| BOOLEAN   |4 |Boolean. |
| DOUBLE   |5 |Double (double-precision floating point). |

## SingleKVStore

Provides APIs to query and synchronize data in a single KV store. This class inherits from [KVStore](#kvstore).

Data is not distinguished by device in a single KV store. The data written to different devices using the same key will be overwritten. For example, a single KV store can be used to synchronize a user's calendar and contact data between different devices.

Before calling any method in **SingleKVStore**, you must use [getKVStore](#getkvstore) to obtain a **SingleKVStore** instance.

### get

get(key: string, callback: AsyncCallback&lt;Uint8Array | string | boolean | number&gt;): void

Obtains the value of the specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    |string   | Yes   |Key of the value to obtain. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants). |
| callback  |AsyncCallback&lt;Uint8Array \| string \| boolean \| number&gt; | Yes   |Callback used to return the value obtained. |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
        if (err != undefined) {
            console.log("put err: " + JSON.stringify(err));
            return;
        }
        console.log("put success");
        kvStore.get(KEY_TEST_STRING_ELEMENT, function (err,data) {
            console.log("get success data: " + data);
        });
    });
}catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```


### get

get(key: string): Promise&lt;Uint8Array | string | boolean | number&gt;

Obtains the value of the specified key. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    |string   | Yes   |Key of the value to obtain. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants). |


**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;Uint8Array \| string \| boolean \| number&gt; |Promise used to return the value obtained.|

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
        console.log("put success: " + JSON.stringify(data));
        kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {
            console.log("get success data: " + data);
        }).catch((err) => {
            console.log("get err: " + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log("put err: " + JSON.stringify(err));
    });
}catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

### getEntries<sup>8+</sup>

getEntries(keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains all KV pairs that match the specified key prefix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix    |string   | Yes   |Key prefix to match. |
| callback    |AsyncCallback&lt;[Entry](#entry)[]&gt;   | Yes   |Callback used to return the KV pairs that match the specified prefix. |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_number_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.INTEGER,
                value : 222
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err,data) {
        console.log('putBatch success');
        kvStore.getEntries('batch_test_number_key', function (err,entries) {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
        });
    });
}catch(e) {
    console.log('PutBatch e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(keyPrefix: string): Promise&lt;Entry[]&gt;

Obtains all KV pairs that match the specified key prefix. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix    |string   | Yes   |Key prefix to match. |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs that match the specified prefix.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + entries);
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
        kvStore.getEntries('batch_test_string_key').then((entries) => {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
            console.log('entries[0].value: ' + JSON.stringify(entries[0].value));
            console.log('entries[0].value.value: ' + entries[0].value.value);
        }).catch((err) => {
            console.log('getEntries fail ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('PutBatch e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| query  |[Query](#query8)   | Yes   |Key prefix to match. |
| callback  |AsyncCallback&lt;[Entry](#entry)[]&gt;   | Yes   |Callback used to return the KV pairs that match the specified **Query** object. |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21,31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.BYTE_ARRAY,
                value : arr
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries, async function (err,data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        kvStore.getEntries(query, function (err,entries) {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
        });
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(query: Query): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| query  |[Query](#query8)   | Yes   |**Query** object to match. |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs that match the specified **Query** object.|

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21,31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.BYTE_ARRAY,
                value : arr
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        kvStore.getEntries(query).then((entries) => {
            console.log('getEntries success');
        }).catch((err) => {
            console.log('getEntries fail ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('GetEntries putBatch fail ' + JSON.stringify(err))
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(keyPrefix: string, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains the result set with the specified prefix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix  |string   | Yes   |Key prefix to match.|
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)&gt;   | Yes   |Callback used to return the result set with the specified prefix.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('GetResultSet putBatch success');
        kvStore.getResultSet('batch_test_string_key', async function (err, result) {
            console.log('GetResultSet getResultSet succeed.');
            resultSet = result;
            kvStore.closeResultSet(resultSet, function (err, data) {
                console.log('GetResultSet closeResultSet success');
            })
        });
    });
}catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(keyPrefix: string): Promise&lt;KvStoreResultSet&gt;

Obtains the result set with the specified prefix. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix  |string   | Yes   |Key prefix to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)&gt; |Promise used to return the result set with the specified prefix.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
    }).catch((err) => {
        console.log('PutBatch putBatch fail ' + JSON.stringify(err));
    });
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('GetResult getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + JSON.stringify(err));
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('GetResult closeResultSet success');
    }).catch((err) => {
        console.log('closeResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResult e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(query: Query, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains a **KvStoreResultSet** object that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |Query    | Yes   |**Query** object to match.            |
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)&gt;   | Yes   |Callback used to return the **KvStoreResultSet** object obtained.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSet(query, async function (err, result) {
            console.log('getResultSet succeed.');
            resultSet = result;
        });
    });
} catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(query: Query): Promise&lt;KvStoreResultSet&gt;

Obtains a **KvStoreResultSet** object that matches the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)    | Yes   |**Query** object to match.            |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)&gt; |Promise used to return the **KvStoreResultSet** object obtained.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
    const query = new distributedData.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSet(query).then((result) => {
        console.log(' getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSet e ' + e);
}
```

### closeResultSet<sup>8+</sup>

closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback&lt;void&gt;): void

Closes the **KvStoreResultSet** object obtained by [SingleKVStore.getResultSet](#getresultset8). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| resultSet  |[KvStoreResultSet](#kvstoreresultset8)   | Yes   |**KvStoreResultSet** object to close.            |
| callback  |AsyncCallback&lt;void&gt;   | Yes   |Callback used to return the result.            |

**Example**

```js
let kvStore;
try {
    let resultSet = null;
    kvStore.closeResultSet(resultSet, function (err, data) {
        if (err == undefined) {
            console.log('closeResultSet success');
        } else {
            console.log('closeResultSet fail');
        }
    });
}catch(e) {
    console.log('CloseResultSet e ' + e);
}
```


### closeResultSet<sup>8+</sup>

closeResultSet(resultSet: KvStoreResultSet): Promise&lt;void&gt;

Closes the **KvStoreResultSet** object obtained by [SingleKVStore.getResultSet](#getresultset8). This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| resultSet  |[KvStoreResultSet](#kvstoreresultset8)   | Yes   |**KvStoreResultSet** object to close.            |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    let resultSet = null;
    kvStore.closeResultSet(resultSet).then(() => {
        console.log('closeResultSet success');
    }).catch((err) => {
        console.log('closeResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('CloseResultSet e ' + e);
}
```


### getResultSize<sup>8+</sup>

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

Obtains the number of results that match the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)   | Yes   |**Query** object to match.        |
| callback  |AsyncCallback&lt;number&gt;   | Yes   |Callback used to return the number of results that match the specified **Query** object.        |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSize(query, async function (err, resultSize) {
            console.log('getResultSet succeed.');
        });
    });
} catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup>

getResultSize(query: Query): Promise&lt;number&gt;

Obtains the number of results that match the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)   | Yes   |**Query** object to match.        |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;number&gt; |Promise used to return the number of results obtained.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
    const query = new distributedData.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSize(query).then((resultSize) => {
        console.log('getResultSet succeed.');
    }).catch((err) => {
        console.log('getResultSet failed: ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### removeDeviceData<sup>8+</sup>

removeDeviceData(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes data of a device. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string   | Yes   |ID of the target device.      |
| callback  |AsyncCallback&lt;void&gt;   | Yes   |Callback used to return the result.     |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {
        console.log('put success');
        const deviceid = 'no_exist_device_id';
        kvStore.removeDeviceData(deviceid, async function (err,data) {
            if (err == undefined) {
                console.log('removeDeviceData success');
            } else {
                console.log('removeDeviceData fail');
                kvStore.get(KEY_TEST_STRING_ELEMENT, async function (err,data) {
                    console.log('RemoveDeviceData get success');
                });
            }
        });
    });
}catch(e) {
    console.log('RemoveDeviceData e ' + e);
}
```


### removeDeviceData<sup>8+</sup>

removeDeviceData(deviceId: string): Promise&lt;void&gt;

Deletes data of a device. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string   | Yes   |ID of the target device.      |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((err) => {
        console.log('removeDeviceData put success');
    }).catch((err) => {
        console.log('put fail ' + JSON.stringify(err));
    });
    const deviceid = 'no_exist_device_id';
    kvStore.removeDeviceData(deviceid).then((err) => {
        console.log('removeDeviceData success');
    }).catch((err) => {
        console.log('removeDeviceData fail ' + JSON.stringify(err));
    });
    kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {
        console.log('get success data:' + data);
    }).catch((err) => {
        console.log('RemoveDeviceData get fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('RemoveDeviceData e ' + e);
}
```

### sync


sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void

Synchronizes the KV store manually.
> **NOTE**
>
> **deviceIds** is **networkId** in <!--RP2-->[DeviceInfo](../apis-distributedservice-kit/js-apis-device-manager-sys.md#deviceinfo), which can be obtained by [deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP2End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                          |
| --------- | --------------------- | ---- | ---------------------------------------------- |
| deviceIds | string[]              | Yes  | List of **networkId**s of the devices in the same networking environment to be synchronized.|
| mode      | [SyncMode](#syncmode) | Yes  | Sync mode.                                    |
| delayMs   | number                | No  | Delay time allowed, in milliseconds. The default value is **0**.    |

**Example**

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';

let devManager;
let kvStore;
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';
// create deviceManager
deviceManager.createDeviceManager('bundleName', (err, value) => {
  if (!err) {
    devManager = value;
    let deviceIds = [];
    if (devManager != null) {
      var devices = devManager.getTrustedDeviceListSync();
      for (var i = 0; i < devices.length; i++) {
        deviceIds[i] = devices[i].networkId;
      }
    }
    try {
      kvStore.on('syncComplete', function (data) {
        console.log('Sync dataChange');
      });
      kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, function (err, data) {
        if (err != undefined) {
          console.log("put err: " + JSON.stringify(err));
          return;
        }
        console.log('Succeeded in putting data');
        const mode = distributedData.SyncMode.PULL_ONLY;
        kvStore.sync(deviceIds, mode, 1000);
      });
    } catch (e) {
      console.log('Sync e' + e);
    }
  }
});
```

### on('dataChange')<sup>8+</sup>

on(event: 'dataChange', type: SubscribeType, listener: Callback&lt;ChangeNotification&gt;): void

Subscribes to data changes of the specified type.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------- |
| event    | string                                                    | Yes  | Event type. The value is **dataChange**, which indicates data changes.|
| type     | [SubscribeType](#subscribetype)                           | Yes  | Type of data change.                                    |
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | Yes  | Callback used to return the result.                                          |

**Example**

```js
let kvStore;
kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {
    console.log("dataChange callback call data: " + JSON.stringify(data));
});
```

### on('syncComplete')<sup>8+</sup>

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Subscribes to sync completion events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                  |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------ |
| event        | string                                        | Yes  | Event type. The value is **syncComplete**, which indicates a sync completion event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback used to return a sync completion event.            |

**Example**

```js
let kvStore;
const KEY_TEST_FLOAT_ELEMENT = 'key_test_float';
const VALUE_TEST_FLOAT_ELEMENT = 321.12;
try {
    kvStore.on('syncComplete', function (data) {
        console.log('syncComplete ' + data)
    });
    kvStore.put(KEY_TEST_FLOAT_ELEMENT, VALUE_TEST_FLOAT_ELEMENT).then((data) => {
        console.log('syncComplete put success');
    }).catch((error) => {
        console.log('syncComplete put fail ' + error);
    });
}catch(e) {
    console.log('syncComplete put e ' + e);
}
```

### off('dataChange')<sup>8+</sup>

off(event:'dataChange', listener?: Callback&lt;ChangeNotification&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                    |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------------------------- |
| event    | string                                                    | Yes  | Event type. The value is **dataChange**, which indicates data changes.|
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | No  | Callback to unregister. If this parameter is not specified, all callbacks for data changes will be unregistered.|

**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log("dataChange: " + data);
    }
    subscribeDataChange() {
        if (kvStore != null) {
            kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);
        }
    }
    unsubscribeDataChange() {
        if (kvStore != null) {
            kvStore.off('dataChange', this.call);
        }
    }
}
```

### off('syncComplete')<sup>8+</sup>

off(event: 'syncComplete', syncCallback?: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Unsubscribes from sync completion events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                      |
| ------------ | --------------------------------------------- | ---- | ---------------------------------------------------------- |
| event        | string                                        | Yes  | Event type. The value is **syncComplete**, which indicates a sync completion event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | No  | Callback to unregister. If this parameter is not specified, all callbacks for data changes will be unregistered. |

**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log("syncComplete: " + data);
    }
    subscribeSyncComplete() {
        if (kvStore != null) {
            kvStore.on('syncComplete', this.call);
        }
    }
    unsubscribeSyncComplete() {
        if (kvStore != null) {
            kvStore.off('syncComplete', this.call);
        }
    }
}
```

### setSyncParam<sup>8+</sup>

setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback&lt;void&gt;): void

Sets the default delay allowed for KV store sync. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| defaultAllowedDelayMs  |number  | Yes   |Default delay allowed for database sync, in ms.   |
| callback  |AsyncCallback&lt;void&gt;  | Yes  |Callback used to return the result.  |

**Example**

```js
let kvStore;
try {
    const defaultAllowedDelayMs = 500;
    kvStore.setSyncParam(defaultAllowedDelayMs, function (err,data) {
        console.log('SetSyncParam put success');
    });
}catch(e) {
    console.log('testSingleKvStoreSetSyncParam e ' + e);
}
```


### setSyncParam<sup>8+</sup>

setSyncParam(defaultAllowedDelayMs: number): Promise&lt;void&gt;

Sets the default delay allowed for KV store sync. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| defaultAllowedDelayMs  |number  | Yes   |Default delay allowed for database sync, in ms.   |


**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    const defaultAllowedDelayMs = 500;
    kvStore.setSyncParam(defaultAllowedDelayMs).then((err) => {
        console.log('SetSyncParam put success');
    }).catch((err) => {
        console.log('SetSyncParam put fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('SetSyncParam e ' + e);
}
```


### getSecurityLevel<sup>8+</sup>

getSecurityLevel(callback: AsyncCallback&lt;SecurityLevel&gt;): void

Obtains the security level of this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| callback  |AsyncCallback&lt;[SecurityLevel](#securitylevel)&gt;  | Yes   |Callback used to return the security level of the KV store.   |

**Example**

```js
let kvStore;
try {
    kvStore.getSecurityLevel(function (err,data) {
        console.log('getSecurityLevel success');
    });
}catch(e) {
    console.log('GetSecurityLevel e ' + e);
}
```


### getSecurityLevel<sup>8+</sup>

getSecurityLevel(): Promise&lt;SecurityLevel&gt;

Obtains the security level of this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[SecurityLevel](#securitylevel)&gt; |Promise used to return the security level of the KV store.|

**Example**

```js
let kvStore;
try {
    kvStore.getSecurityLevel().then((data) => {
        console.log(' getSecurityLevel success');
    }).catch((err) => {
        console.log('getSecurityLevel fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetSecurityLevel e ' + e);
}
```


## DeviceKVStore<sup>8+</sup> 

Provides APIs to query and synchronize data in a device KV store. This class inherits from [KVStore](#kvstore).

Data is distinguished by device in a device KV store. Each device can only write and modify its own data. Data of other devices is read-only and cannot be modified.

For example, a device KV store can be used to implement image sharing between devices. The images of other devices can be viewed, but not be modified or deleted.

Before calling any method in **DeviceKVStore**, you must use [getKVStore](#getkvstore) to obtain a **DeviceKVStore** object.

### get<sup>8+</sup>

get(deviceId: string, key: string, callback: AsyncCallback&lt;boolean|string|number|Uint8Array&gt;): void

Obtains a string value that matches the specified device ID and key. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| key       |string  | Yes   |Key to match.   |
| callback  |AsyncCallback&lt;boolean\|string\|number\|Uint8Array&gt;  | Yes   |Callback used to return the value obtained.   |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try{
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {
        console.log('put success');
        kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, function (err,data) {
            console.log('get success');
        });
    })
}catch(e) {
    console.log('get e' + e);
}
```


### get<sup>8+</sup>

get(deviceId: string, key: string): Promise&lt;boolean|string|number|Uint8Array&gt;

Obtains a string value that matches the specified device ID and key. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| key       |string  | Yes   |Key to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;boolean\|string\|number\|Uint8Array&gt; |Promise used to return the string value that matches the given condition.|

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string_2';
const VALUE_TEST_STRING_ELEMENT = 'value-string-002';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then(async (data) => {
        console.log(' put success');
        kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT).then((data) => {
            console.log('get success');
        }).catch((err) => {
            console.log('get fail ' + JSON.stringify(err));
        });
    }).catch((error) => {
        console.log('put error' + error);
    });
} catch (e) {
    console.log('Get e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains all KV pairs that match the specified device ID and key prefix. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| keyPrefix |string  | Yes   |Key prefix to match.   |
| callback  |AsyncCallback&lt;[Entry](#entry)[]&gt;  | Yes |Callback used to return the KV pairs obtained.   |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + entries);
    kvStore.putBatch(entries, async function (err,data) {
        console.log('putBatch success');
        kvStore.getEntries('localDeviceId', 'batch_test_string_key', function (err,entries) {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
        });
    });
}catch(e) {
    console.log('PutBatch e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(deviceId: string, keyPrefix: string): Promise&lt;Entry[]&gt;

Obtains all KV pairs that match the specified device ID and key prefix. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| keyPrefix |string  | Yes   |Key prefix to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return all the KV pairs that match the given condition.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + entries);
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
        kvStore.getEntries('localDeviceId', 'batch_test_string_key').then((entries) => {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
            console.log('entries[0].value: ' + JSON.stringify(entries[0].value));
            console.log('entries[0].value.value: ' + entries[0].value.value);
        }).catch((err) => {
            console.log('getEntries fail ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('PutBatch e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |
| callback |AsyncCallback&lt;[Entry](#entry)[]&gt;  | Yes   |Callback used to return the KV pairs obtained.   |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21,31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.BYTE_ARRAY,
                value : arr
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries, async function (err,data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        query.deviceId('localDeviceId');
        kvStore.getEntries(query, function (err,entries) {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
        });
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(query: Query): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs that match the specified **Query** object.|

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21,31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.BYTE_ARRAY,
                value : arr
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        kvStore.getEntries(query).then((entries) => {
            console.log('getEntries success');
        }).catch((err) => {
            console.log('getEntries fail ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('GetEntries putBatch fail ' + JSON.stringify(err))
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(deviceId: string, query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified device ID and **Query** object. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |
| callback |AsyncCallback&lt;[Entry](#entry)[]&gt;  | Yes   |Callback used to return the KV pairs that match the specified device ID and **Query** object.   |

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21,31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.BYTE_ARRAY,
                value : arr
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries, async function (err,data) {
        console.log('putBatch success');
        var query = new distributedData.Query();
        query.deviceId('localDeviceId');
        query.prefixKey("batch_test");
        kvStore.getEntries('localDeviceId', query, function (err,entries) {
            console.log('getEntries success');
            console.log('entries.length: ' + entries.length);
            console.log('entries[0]: ' + JSON.stringify(entries[0]));
        })
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getEntries<sup>8+</sup>

getEntries(deviceId: string, query: Query): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified device ID and **Query** object. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs that match the specified device ID and **Query** object.|

**Example**

```js
let kvStore;
try {
    var arr = new Uint8Array([21,31]);
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_bool_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.BYTE_ARRAY,
                value : arr
            }
        }
        entries.push(entry);
    }
    console.log('entries: ' + JSON.stringify(entries));
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
        var query = new distributedData.Query();
        query.deviceId('localDeviceId');
        query.prefixKey("batch_test");
        kvStore.getEntries('localDeviceId', query).then((entries) => {
            console.log('getEntries success');
        }).catch((err) => {
            console.log('getEntries fail ' + JSON.stringify(err));
        });
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains a **KvStoreResultSet** object that matches the specified device ID and key prefix. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| keyPrefix |string  | Yes   |Key prefix to match.   |
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)&gt;  | Yes |Callback used to return the **KvStoreResultSet** object that matches the specified device ID and key prefix.   |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key', async function (err, result) {
        console.log('getResultSet succeed.');
        resultSet = result;
        kvStore.closeResultSet(resultSet, function (err, data) {
            console.log('closeResultSet success');
        })
    });
}catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(deviceId: string, keyPrefix: string): Promise&lt;KvStoreResultSet&gt;

Obtains a **KvStoreResultSet** object that matches the specified device ID and key prefix. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| keyPrefix |string  | Yes   |Key prefix to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)&gt; |Promise used to return the **KvStoreResultSet** object that matches the specified device ID and key prefix.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key').then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + JSON.stringify(err));
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('closeResultSet success');
    }).catch((err) => {
        console.log('closeResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(query: Query, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains a **KvStoreResultSet** object that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)&gt;  | Yes |Callback used to return the **KvStoreResultSet** object obtained.   |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        query.deviceId('localDeviceId');
        kvStore.getResultSet(query, async function (err, result) {
            console.log('getResultSet succeed.');
            resultSet = result;
            kvStore.closeResultSet(resultSet, function (err, data) {
                console.log('closeResultSet success');
            })
        });
    });
} catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(query: Query): Promise&lt;KvStoreResultSet&gt;

Obtains a **KvStoreResultSet** object that matches the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)&gt; |Promise used to return the **KvStoreResultSet** object that matches the specified **Query** object.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
    }).catch((err) => {
        console.log('putBatch fail ' + err);
    });
    const query = new distributedData.Query();
    query.deviceId('localDeviceId');
    query.prefixKey("batch_test");
    console.log("GetResultSet " + query.getSqlLike());
    kvStore.getResultSet(query).then((result) => {
        console.log('getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet failed: ' + JSON.stringify(err));
    });
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('closeResultSet success');
    }).catch((err) => {
        console.log('closeResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(deviceId: string, query: Query, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains a **KvStoreResultSet** object that matches the specified device ID and **Query** object. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)&gt;  | Yes |Callback used to return the **KvStoreResultSet** object that matches the specified device ID and **Query** object.   |

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSet('localDeviceId', query, async function (err, result) {
            console.log('getResultSet succeed.');
            resultSet = result;
            kvStore.closeResultSet(resultSet, function (err, data) {
                console.log('closeResultSet success');
            })
        });
    });
} catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup>

getResultSet(deviceId: string, query: Query): Promise&lt;KvStoreResultSet&gt;

Obtains a **KvStoreResultSet** object that matches the specified device ID and **Query** object. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)&gt; |Promise used to return the **KvStoreResultSet** object that matches the specified device ID and **Query** object.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('GetResultSet putBatch success');
    }).catch((err) => {
        console.log('PutBatch putBatch fail ' + JSON.stringify(err));
    });
    const query = new distributedData.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSet('localDeviceId', query).then((result) => {
        console.log('GetResultSet getResultSet succeed.');
        resultSet = result;
    }).catch((err) => {
        console.log('GetResultSet getResultSet failed: ' + JSON.stringify(err));
    });
    query.deviceId('localDeviceId');
    console.log("GetResultSet " + query.getSqlLike());
    kvStore.closeResultSet(resultSet).then((err) => {
        console.log('GetResultSet closeResultSet success');
    }).catch((err) => {
        console.log('GetResultSet closeResultSet fail ' + JSON.stringify(err));
    });

}catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### closeResultSet<sup>8+</sup>

closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback&lt;void&gt;): void

Closes the **KvStoreResultSet** object obtained by [DeviceKVStore.getResultSet](#getresultset8-4). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| resultSet  |[KvStoreResultSet](#kvstoreresultset8)  | Yes   |**KvStoreResultSet** object to close.  |
| callback   |AsyncCallback&lt;void&gt;                 | Yes   |Callback used to return the result.   |

**Example**

```js
let kvStore;
try {
    console.log('CloseResultSet success');
    let resultSet = null;
    kvStore.closeResultSet(resultSet, function (err, data) {
        if (err == undefined) {
            console.log('closeResultSet success');
        } else {
            console.log('closeResultSet fail');
        }
    });
}catch(e) {
    console.log('CloseResultSet e ' + e);
}
```


### closeResultSet<sup>8+</sup>

closeResultSet(resultSet: KvStoreResultSet): Promise&lt;void&gt;

Closes the **KvStoreResultSet** object obtained by [DeviceKVStore.getResultSet](#getresultset8-4). This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| resultSet  |[KvStoreResultSet](#kvstoreresultset8)  | Yes   |**KvStoreResultSet** object to close.  |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
try {
    console.log('CloseResultSet success');
    let resultSet = null;
    kvStore.closeResultSet(resultSet).then(() => {
        console.log('closeResultSet success');
    }).catch((err) => {
        console.log('closeResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('CloseResultSet e ' + e);
}
```


### getResultSize<sup>8+</sup>

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

Obtains the number of results that match the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query     |[Query](#query8)       | Yes   |**Query** object to match.   |
| callback  |AsyncCallback&lt;number&gt;  | Yes   |Callback used to return the number of results obtained.   |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        query.deviceId('localDeviceId');
        kvStore.getResultSize(query, async function (err, resultSize) {
            console.log('getResultSet succeed.');
        });
    });
} catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup>

getResultSize(query: Query): Promise&lt;number&gt;

Obtains the number of results that match the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query     |[Query](#query8)       | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;number&gt; |Promise used to return the number of results obtained.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
    const query = new distributedData.Query();
    query.prefixKey("batch_test");
    query.deviceId('localDeviceId');
    kvStore.getResultSize(query).then((resultSize) => {
        console.log('getResultSet succeed.');
    }).catch((err) => {
        console.log('getResultSet failed: ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup>

getResultSize(deviceId: string, query: Query, callback: AsyncCallback&lt;number&gt;): void;

Obtains the number of results that match the specified device ID and **Query** object. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string                       | Yes   |ID of the target device.   |
| query     |[Query](#query8)       | Yes   |**Query** object to match.   |
| callback  |AsyncCallback&lt;number&gt;  | Yes   |Callback used to return the number of results obtained.   |

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries, async function (err, data) {
        console.log('putBatch success');
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        kvStore.getResultSize('localDeviceId', query, async function (err, resultSize) {
            console.log('getResultSet succeed.');
        });
    });
} catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup>

getResultSize(deviceId: string, query: Query): Promise&lt;number&gt;

Obtains the number of results that match the specified device ID and **Query** object. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string                       | Yes   |ID of the target device.   |
| query     |[Query](#query8)       | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;number&gt; |Promise used to return the number of results obtained.|

**Example**

```js
let kvStore;
try {
    let entries = [];
    for (var i = 0; i < 10; i++) {
        var key = 'batch_test_string_key';
        var entry = {
            key : key + i,
            value : {
                type : distributedData.ValueType.STRING,
                value : 'batch_test_string_value'
            }
        }
        entries.push(entry);
    }
    kvStore.putBatch(entries).then(async (err) => {
        console.log('putBatch success');
    }).catch((err) => {
        console.log('putBatch fail ' + JSON.stringify(err));
    });
    var query = new distributedData.Query();
    query.prefixKey("batch_test");
    kvStore.getResultSize('localDeviceId', query).then((resultSize) => {
        console.log('getResultSet succeed.');
    }).catch((err) => {
        console.log('getResultSet failed: ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### removeDeviceData<sup>8+</sup>

removeDeviceData(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes data of the specified device from this KV store. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string                       | Yes   |ID of the target device. |
| callback  |AsyncCallback&lt;void&gt;    | Yes   |Callback used to return the result.   |

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, async function (err,data) {
        console.log('RemoveDeviceData  put success');
        const deviceid = 'no_exist_device_id';
        kvStore.removeDeviceData(deviceid, async function (err,data) {
            if (err == undefined) {
                console.log('removeDeviceData success');
            } else {
                console.log('removeDeviceData fail');
                kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, async function (err,data) {
                    console.log('RemoveDeviceData get success');
                });
            }
        });
    });
}catch(e) {
    console.log('RemoveDeviceData e ' + e);
}
```


### removeDeviceData<sup>8+</sup>

removeDeviceData(deviceId: string): Promise&lt;void&gt;

Deletes data of the specified device from this KV store. This API uses a promise to return the result.
> **NOTE**
>
> The value of **deviceId** can be obtained by <!--RP1-->[deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP1End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.
> For details about how to obtain **deviceId**, see [sync()](#sync).

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device. |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise that returns no value.|

**Example**

```js
let kvStore;
const KEY_TEST_STRING_ELEMENT = 'key_test_string';
const VALUE_TEST_STRING_ELEMENT = 'value-string-001';
try {
    kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((err) => {
        console.log('RemoveDeviceData put success');
    }).catch((err) => {
        console.log('RemoveDeviceData put fail ' + JSON.stringify(err));
    });
    const deviceid = 'no_exist_device_id';
    kvStore.removeDeviceData(deviceid).then((err) => {
        console.log('removeDeviceData success');
    }).catch((err) => {
        console.log('removeDeviceData fail ' + JSON.stringify(err));
    });
    kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT).then((data) => {
        console.log('RemoveDeviceData get success data:' + data);
    }).catch((err) => {
        console.log('RemoveDeviceData get fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('RemoveDeviceData e ' + e);
}
```


### sync<sup>8+</sup>

sync(deviceIds: string[], mode: SyncMode, delayMs?: number): void

Synchronizes the KV store manually.

> **NOTE**
>
> **deviceIds** is **networkId** in <!--RP2-->[DeviceInfo](../apis-distributedservice-kit/js-apis-device-manager-sys.md#deviceinfo), which can be obtained by [deviceManager.getTrustedDeviceListSync](../apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync). <!--RP2End-->The APIs of the **deviceManager** module are system interfaces and available only to system applications.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceIds    |string[]               | Yes   |**networkId**s of the devices to be synchronized.|
| mode            |[SyncMode](#syncmode)  | Yes   |Sync mode. |
| delayMs  |number                 | No   |Delay time allowed, in milliseconds. The default value is **0**. |

**Example**

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';

let devManager;
let kvStore;
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';
// create deviceManager
deviceManager.createDeviceManager('bundleName', (err, value) => {
  if (!err) {
    devManager = value;
    let deviceIds = [];
    if (devManager != null) {
      var devices = devManager.getTrustedDeviceListSync();
      for (var i = 0; i < devices.length; i++) {
        deviceIds[i] = devices[i].networkId;
      }
    }
    try {
      kvStore.on('syncComplete', function (data) {
        console.log('Sync dataChange');
      });
      kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, function (err, data) {
        if (err != undefined) {
          console.log("put err: " + JSON.stringify(err));
          return;
        }
        console.log('Succeeded in putting data');
        const mode = distributedData.SyncMode.PULL_ONLY;
        kvStore.sync(deviceIds, mode, 1000);
      });
    } catch (e) {
      console.log('Sync e' + e);
    }
  }
});
```

### on('dataChange')<sup>8+</sup>

on(event: 'dataChange', type: SubscribeType, listener: Callback&lt;ChangeNotification&gt;): void

Subscribes to data changes of the specified type.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                |
| -------- | --------------------------------------------------------- | ---- | ---------------------------------------------------- |
| event    | string                                                    | Yes  | Event type. The value is **dataChange**, which indicates data changes.|
| type     | [SubscribeType](#subscribetype)                           | Yes  | Type of data change.                                    |
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | Yes  | Callback used to return the result.                                          |

**Example**

```js
let kvStore;
kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {
    console.log("dataChange callback call data: " + JSON.stringify(data));
});
```

### on('syncComplete')<sup>8+</sup>

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Subscribes to sync completion events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                  |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------ |
| event        | string                                        | Yes  | Event type. The value is **syncComplete**, which indicates a sync completion event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback used to return a sync completion event.            |

**Example**

```js
let kvStore;
const KEY_TEST_FLOAT_ELEMENT = 'key_test_float';
const VALUE_TEST_FLOAT_ELEMENT = 321.12;
try {
    kvStore.on('syncComplete', function (data) {
        console.log('syncComplete ' + data)
    });
    kvStore.put(KEY_TEST_FLOAT_ELEMENT, VALUE_TEST_FLOAT_ELEMENT).then((data) => {
        console.log('syncComplete put success');
    }).catch((error) => {
        console.log('syncComplete put fail ' + error);
    });
}catch(e) {
    console.log('syncComplete put e ' + e);
}
```

### off('dataChange')<sup>8+</sup>

off(event:'dataChange', listener?: Callback&lt;ChangeNotification&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                    |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------------------------- |
| event    | string                                                    | Yes  | Event type. The value is **dataChange**, which indicates data changes.|
| listener | Callback&lt;[ChangeNotification](#changenotification)&gt; | No  | Callback to unregister. If this parameter is not specified, all callbacks for data changes will be unregistered.|

**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log("dataChange: " + data);
    }
    subscribeDataChange() {
        if (kvStore != null) {
            kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_REMOTE, this.call);
        }
    }
    unsubscribeDataChange() {
        if (kvStore != null) {
            kvStore.off('dataChange', this.call);
        }
    }
}
```

### off('syncComplete')<sup>8+</sup>

off(event: 'syncComplete', syncCallback?: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Unsubscribes from sync completion events.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                      |
| ------------ | --------------------------------------------- | ---- | ---------------------------------------------------------- |
| event        | string                                        | Yes  | Event type. The value is **syncComplete**, which indicates a sync completion event.|
| syncCallback | Callback&lt;Array&lt;[string, number]&gt;&gt; | No  | Callback to unregister. If this parameter is not specified, all callbacks for data changes will be unregistered. |

**Example**

```js
let kvStore;
class KvstoreModel {
    call(data) {
        console.log("syncComplete: " + data);
    }
    subscribeSyncComplete() {
        if (kvStore != null) {
            kvStore.on('syncComplete', this.call);
        }
    }
    unsubscribeSyncComplete() {
        if (kvStore != null) {
            kvStore.off('syncComplete', this.call);
        }
    }
}
```

## SyncMode

Enumerates the sync modes.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name      | Value    | Description                   |
| -----      | ------    | ----------------------- |
| PULL_ONLY  |0          |Pull data from the peer end to the local end only.|
| PUSH_ONLY  |1          |Push data from the local end to the peer end only.|
| PUSH_PULL  |2          |Push data from the local end to the peer end and then pull data from the peer end to the local end.|
