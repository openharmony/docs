# Distributed Data Management

Distributed data management provides collaboration between databases of different devices for applications. The APIs provided by distributed data management can be used to save data to the distributed database and perform operations such as adding, deleting, modifying, and querying data in the distributed database.

>**NOTE**<br/>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import distributedData from '@ohos.data.distributedData';
```


## distributedData.createKVManager

createKVManager(config: KVManagerConfig, callback: AsyncCallback&lt;KVManager&gt;): void

Creates a **KVManager** object to manage key-value (KV) stores. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| config | [KVManagerConfig](#kvmanagerconfig) | Yes | Configuration of the **KVManager** object, including the bundle name and user information of the caller.|
| callback | AsyncCallback&lt;[KVManager](#kvmanager)&gt; | Yes | Callback invoked to return the **KVManager** object created.|

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
            console.log("createKVManager err: "  + JSON.stringify(err));
            return;
        }
        console.log("createKVManager success");
        kvManager = manager;
    });
} catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

## distributedData.createKVManager

createKVManager(config: KVManagerConfig): Promise&lt;KVManager&gt;

Creates a **KVManager** object to manage KV stores. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| config |[KVManagerConfig](#kvmanager) | Yes | Configuration of the **KVManager** object, including the bundle name and user information of the caller.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[KVManager](#kvmanager)&gt; | Promise used to return the **KVManager** object created.|

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
    distributedData.createKVManager(kvManagerConfig).then((manager) => {
        console.log("createKVManager success");
        kvManager = manager;
    }).catch((err) => {
        console.log("createKVManager err: "  + JSON.stringify(err));
    });
} catch (e) {
    console.log("An unexpected error occurred. Error:" + e);
}
```

## KVManagerConfig

Provides configuration of the **KVManager** object, including the bundle name and user information of the caller.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| userInfo | [UserInfo](#userinfo) | Yes | User information.|
| bundleName | string | Yes | Bundle name.|

## UserInfo

Defines user information.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| userId | string | Yes | User ID.|
| userType | [UserType](#usertype) | Yes | User type.|


## UserType

Defines the user type.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name| Default Value| Description|
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
| callback | AsyncCallback&lt;T&gt; , &lt;T extends [KVStore](#kvstore)&gt;| Yes | Callback invoked to return the KV store created.|

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
        securityLevel : distributedData.SecurityLevel.S2,
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
| Promise&lt;T&gt; &lt;T extends [KVStore](#kvstore)&gt; | Promise used to return the KV store created.|

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
        securityLevel : distributedData.SecurityLevel.S2,
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

### closeKVStore<sup>8+</sup> ###

closeKVStore(appId: string, storeId: string, kvStore: KVStore, callback: AsyncCallback&lt;void&gt;): void

Closes a KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**


| Name  | Type             | Mandatory| Description        |
| ------- | -----------------   | ---- | --------------------------- |
| appId    | string              | Yes  | Bundle name of the app that invokes the KV store.        |
| storeId  | string  | Yes  | Unique identifier of the KV store to close. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| kvStore  | [KVStore](#kvstore) | Yes  | KV store to close.    |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the KV store is closed, **true** will be returned. Otherwise, **false** will be returned.  |

**Example**

```js
let kvStore;
let kvManager;
const options = {
    createIfMissing : true,
    encrypt : false,
    backup : false,
    autoSync : true,
    kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,
    schema : '',
    securityLevel : distributedData.SecurityLevel.S2,
 }
 try {
    kvManager.getKVStore('storeId', options, async function (err, store) {
    console.log('getKVStore success');
    kvStore = store;
    await kvManager.closeKVStore('appId', 'storeId', kvStore, function (err, data) {
        console.log('closeKVStore success');
    });
    });
} catch (e) {
    console.log('closeKVStore e ' + e);
}
```


### closeKVStore<sup>8+</sup> ###

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
| Promise\<void> | Promise used to return the result. If the KV store is closed, **true** will be returned. Otherwise, **false** will be returned.|

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
    schema : '',
    securityLevel : distributedData.SecurityLevel.S2,
}
 try {
    kvManager.getKVStore('storeId', options).then(async (store) => {
    console.log('getKVStore success');
    kvStore = store;
    await kvManager.closeKVStore('appId', 'storeId', kvStore).then(() => {
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


### deleteKVStore<sup>8+</sup> ###

deleteKVStore(appId: string, storeId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| appId  | string  | Yes  | Bundle name of the app that invokes the KV store.    |
| storeId | string | Yes  | Unique identifier of the KV store to delete. The length cannot exceed [MAX_STORE_ID_LENGTH](#constants).|
| callback | AsyncCallback&lt;void&gt;  | Yes  | Callback used to return the result. If the KV store is deleted, **true** will be returned. Otherwise, **false** will be returned.  |

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
    schema : '',
    securityLevel : distributedData.SecurityLevel.S2,
}
try {
    kvManager.getKVStore('store', options, async function (err, store) {
        console.log('getKVStore success');
        kvStore = store;
        await kvManager.deleteKVStore('appId', 'storeId', function (err, data) {
            console.log('deleteKVStore success');
        });
    });
} catch (e) {
    console.log('DeleteKVStore e ' + e);
}
```

### deleteKVStore<sup>8+</sup> ###

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
| Promise&lt;void&gt; | Promise used to return the result. If the KV store is deleted, **true** will be returned. Otherwise, **false** will be returned.|

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
    schema : '',
    securityLevel : distributedData.SecurityLevel.S2,
}
try {
    kvManager.getKVStore('storeId', options).then(async (store) => {
        console.log('getKVStore success');
        kvStore = store;
        await kvManager.deleteKVStore('appId', 'storeId').then(() => {
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


### getAllKVStoreId<sup>8+</sup> ###

getAllKVStoreId(appId: string, callback: AsyncCallback&lt;string[]&gt;): void

Obtains the IDs of all the KV stores that are created using [getKVStore](#getkvstore) and have not been deleted using [deleteKVStore](#deletekvstore8). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| appId  | string  | Yes   | Bundle name of the app that invokes the KV store.    |
| callback | AsyncCallback&lt;void&gt; | Yes  |Callback used to return the KV store IDs obtained. |

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


### getAllKVStoreId<sup>8+</sup> ###

getAllKVStoreId(appId: string): Promise&lt;string[]&gt;

Obtains the IDs of all the KV stores that are created using [getKVStore](#getkvstore) and have not been deleted using [deleteKVStore](#deletekvstore8). This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| appId  | string  | Yes   | Bundle name of the app that invokes the KV store.    |


**Return value**

| Type         | Description           |
| ------------- | -------------- |
| Promise&lt;string[]&gt;| Promise used to return the KV store IDs obtained.|

**Example**

```js
let kvManager;
try {
    console.log('GetAllKVStoreId');
    kvManager.getAllKVStoreId('apppId').then((data) => {
        console.log('getAllKVStoreId success');
        console.log('size = ' + data.length);
    }).catch((err) => {
        console.log('getAllKVStoreId err ' + JSON.stringify(err));
    });
} catch(e) {
    console.log('getAllKVStoreId e ' + e);
}
```


### on('distributedDataServiceDie')<sup>8+</sup> ###

on(event: 'distributedDataServiceDie', deathCallback: Callback&lt;void&gt;): void

Subscribes to the **distributedDataServiceDie** events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| event  | string | Yes   | Name of the event to subscribe to. The value is **distributedDataServiceDie**, which indicates the service status change event.|
| deathCallback  | Callback&lt;void&gt;  | Yes   | Callback invoked when the distributed data service is dead.   |

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


### off('distributedDataServiceDie')<sup>8+</sup> ###

off(event: 'distributedDataServiceDie', deathCallback?: Callback&lt;void&gt;): void

Unsubscribes from the **distributedDataServiceDie** events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| event  | string | Yes   | Name of the event to unsubscribe from. The value is **distributedDataServiceDie**, which indicates the service status change event.|
| deathCallback  | Callback&lt;void&gt;  | No   | Callback used to return the **distributedDataServiceDie** events.   |


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


| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| createIfMissing  | boolean | No| Whether to create a KV store if no database file exists. By default, a KV store is created. <br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core   |
| encrypt  | boolean | No|Whether to encrypt database files. By default, database files are not encrypted.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core    |
| backup  | boolean | No|Whether to back up database files. By default, database files are backed up. <br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core    |
| autoSync  | boolean | No|Whether to automatically synchronize database files. By default, database files are not automatically synchronized.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core<br>**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC    |
| kvStoreType | [KVStoreType](#kvstoretype) | No|Type of the KV store to create. By default, a device KV store is created. The device KV store stores data for multiple devices that collaborate with each other.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| securityLevel | [SecurityLevel](#securitylevel) | No|Security level of the KV store. By default, the security level is not set. <br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core|
| schema<sup>8+</sup> | [Schema](#schema8) | No| Schema used to define the values stored in a KV store.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore|


## KVStoreType

Defines the KV store types.


| Name | Default Value| Description                   |
| ---   | ----  | ----------------------- |
| DEVICE_COLLABORATION  | 0 | Device KV store. <br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore |
| SINGLE_VERSION  | 1 | Single KV store.<br>**System capability**: SystemCapability.DistributedDataManager.KVStore.Core |
| MULTI_VERSION   | 2 | Multi-version KV store. This type is not supported currently. <br>**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore|


## SecurityLevel

Defines the KV store security levels.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Default Value| Description                   |
| ---   | ----  | ----------------------- |
| NO_LEVEL  | 0 | No security level is set for the KV store.  |
| S0  | 1 | The KV store security level is public. |
| S1  | 2 | The KV store security level is low. If data leakage occurs, minor impact will be caused on the database. |
| S2  | 3 | The KV store security level is medium. If data leakage occurs, moderate impact will be caused on the database. |
| S3  | 5 | The KV store security level is high. If data leakage occurs, major impact will be caused on the database. |
| S4  | 6 | The KV store security level is critical. If data leakage occurs, severe impact will be caused on the database. |


## Constants

Defines the KV store constants.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Default Value| Description                   |
| ---   | ----  | ----------------------- |
| MAX_KEY_LENGTH  | 1024 | Maximum length (in bytes) of a key in the KV store.  |
| MAX_VALUE_LENGTH  | 4194303 | Maximum length (in bytes) of a value in the KV store. |
| MAX_KEY_LENGTH_DEVICE  | 896 | Maximum length of the device coordinate key. |
| MAX_STORE_ID_LENGTH  | 128 | Maximum length (in bytes) of a KV store ID. |
| MAX_QUERY_LENGTH  | 512000 | Maximum query length. |
| MAX_BATCH_SIZE  | 128 | Maximum size of a batch operation. |

## Schema<sup>8+</sup> ##

Defines a database schema. When creating or opening a KV store, you can create a **Schema** object and put it into **Options**.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| Name | Type| Description                   |
| ---   | ----  | ----------------------- |
| root<sup>8+</sup>  | [FieldNode](#fieldnode8) | JSON root object.|
| indexes<sup>8+</sup>  | Array\<string> | String array in JSON format. |
| mode<sup>8+</sup>  | number | Schema mode. |
| skip<sup>8+</sup>  | number |  Size of a skip of the schema. |

### constructor<sup>8+</sup> ###

constructor()

A constructor used to create a **Schema** instance.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

## FieldNode<sup>8+</sup> ##

Represents a **Schema** instance, which provides the methods for defining the values stored in a KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

| Name | Type| Description                   |
| ---   | ----  | ----------------------- |
| nullable<sup>8+</sup>  | boolean | Whether the database field can be null.  |
| default<sup>8+</sup>  | string | Default value of a **FieldNode**.|
| type<sup>8+</sup>  | number | Value to store.|

### constructor<sup>8+</sup> ###

constructor(name: string)

A constructor used to create a **FieldNode** instance with a string field.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name| Type| Mandatory| Description           |
| ------ | -------- | ---- | --------------- |
| name   | string   | Yes  | Value of **FieldNode**.|

### appendChild<sup>8+</sup> ###

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
    console.log("appendNode " + node.toJson());
    child1 = null;
    child2 = null;
    child3 = null;
    node = null;
} catch (e) {
    console.log("AppendChild " + e);
}
```


## KvStoreResultSet<sup>8+</sup> ##

Provides methods to obtain the KV store result set and query or move the data read position. Before calling any method in **KvStoreResultSet**, you must use **KvStore** to create a **KvStore** instance.


### getCount<sup>8+</sup> ###

getCount(): number

Obtains the number of rows in the result set.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type  | Description              |
| ------ | --------------    |
| number |Number of rows obtained.         |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const count = resultSet.getCount();
    console.log("GetCount " + count);
} catch (e) {
    console.log("GetCount fail " + e);
}
```

### getPosition<sup>8+</sup> ###

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const position = resultSet.getPosition();
    console.log("getPosition " + position);
} catch (e) {
    console.log("GetPosition fail " + e);
}
```


### moveToFirst<sup>8+</sup> ###

moveToFirst(): boolean

Moves the data read position to the first row.

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.moveToFirst();
    console.log("moveToFirst " + moved);
} catch (e) {
    console.log("MoveToFirst fail " + e);
}
```


### moveToLast<sup>8+</sup> ###

moveToLast(): boolean

Moves the data read position to the last row.

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.moveToLast();
    console.log("moveToLast " + moved);
} catch (e) {
    console.log("moveToLast fail " + e);
}
```


### moveToNext<sup>8+</sup> ###

moveToNext(): boolean

Moves the data read position to the next row.

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.moveToNext();
    console.log("moveToNext " + moved);
} catch (e) {
    console.log("moveToNext fail " + e);
}
```


### moveToPrevious<sup>8+</sup> ###

moveToPrevious(): boolean

Moves the data read position to the previous row.

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.moveToPrevious();
    console.log("moveToPrevious " + moved);
} catch (e) {
    console.log("moveToPrevious fail " + e);
}
```


### move<sup>8+</sup> ###

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.move();
    console.log("move " + moved);
} catch (e) {
    console.log("move fail " + e);
}
```


### moveToPosition<sup>8+</sup> ###

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.moveToPosition();
    console.log("moveToPosition " + moved);
} catch (e) {
    console.log("moveToPosition fail " + e);
}
```


### isFirst<sup>8+</sup> ###

isFirst(): boolean

Checks whether the data read position is the first row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the data read position is the first row; returns **false** otherwise.  |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.isFirst();
    console.log("isFirst " + moved);
} catch (e) {
    console.log("isFirst fail " + e);
}
```


### isLast<sup>8+</sup> ###

isLast(): boolean

Checks whether the data read position is the last row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the data read position is the last row; returns **false** otherwise.  |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.isLast();
    console.log("isLast " + moved);
} catch (e) {
    console.log("isLast fail " + e);
}
```

### isBeforeFirst<sup>8+</sup> ###

isBeforeFirst(): boolean

Checks whether the data read position is before the first row.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description              |
| ------  | --------------    |
| boolean |Returns **true** if the read position is before the first row; returns **false** otherwise. |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('batch_test_string_key').then((result) => {
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.isBeforeFirst();
    console.log("isBeforeFirst " + moved);
} catch (e) {
    console.log("isBeforeFirst fail " + e);
}
```


### isAfterLast<sup>8+</sup> ###

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.isAfterLast();
    console.log("isAfterLast " + moved);
} catch (e) {
    console.log("isAfterLast fail " + e);
}
```


### getEntry<sup>8+</sup> ###

getEntry(): Entry

Obtains a KV pair.

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + err);
    });
    const moved = resultSet.moveToNext();
    const entry  = resultSet.getEntry();
    console.log("getEntry " + JSON.stringify(entry));
} catch (e) {
    console.log("getEntry fail " + e);
}
```


## Query<sup>8+</sup> ##

Provides methods to create a **Query** object, which defines different data query criteria.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

### constructor<sup>8+</sup> ###

constructor() 

A constructor used to create a **Schema** instance.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core


### reset<sup>8+</sup> ###

reset(): Query

Resets the **Query** object that contains common query options.

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


### equalTo<sup>8+</sup> ###

equalTo(field: string, value: number|string|boolean): Query

Creates a **Query** object to match the specified field whose value is equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object reset.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.equalTo("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### notEqualTo<sup>8+</sup> ###

notEqualTo(field: string, value: number|string|boolean): Query

Creates a **Query** object to match the specified field whose value is not equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

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
    console.log("dumplicated calls should be ok :" + e);
}
```


### greaterThan<sup>8+</sup> ###

greaterThan(field: string, value: number|string|boolean): Query

Creates a **Query** object to match the specified field whose value is greater than the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.greaterThan("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### lessThan<sup>8+</sup> ###

lessThan(field: string, value: number|string): Query

Creates a **Query** object to match the specified field whose value is less than the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.lessThan("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### greaterThanOrEqualTo<sup>8+</sup> ###

greaterThanOrEqualTo(field: string, value: number|string): Query

Creates a **Query** object to match the specified field whose value is greater than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.greaterThanOrEqualTo("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### lessThanOrEqualTo<sup>8+</sup> ###

lessThanOrEqualTo(field: string, value: number|string): Query

Creates a **Query** object to match the specified field whose value is less than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| value  | number\|string\|boolean  | Yes   | Value specified.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.lessThanOrEqualTo("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### isNull<sup>8+</sup> ###

isNull(field: string): Query

Creates a **Query** object to match the specified field whose value is **null**.


**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.isNull("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### inNumber<sup>8+</sup> ###

inNumber(field: string, valueList: number[]): Query

Creates a **Query** object to match the specified field whose value is within the specified list of numbers.


**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| valueList  | number[]  | Yes   | List of numbers.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.inNumber("field", [0, 1]);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### inString<sup>8+</sup> ###

inString(field: string, valueList: string[]): Query

Creates a **Query** object to match the specified field whose value is within the specified list of strings.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| valueList  | string[]  | Yes   | List of strings.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.inString("field", ['test1', 'test2']);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### notInNumber<sup>8+</sup> ###

notInNumber(field: string, valueList: number[]): Query

Creates a **Query** object to match the specified field whose value is not within the specified list of numbers.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| valueList  | number[]  | Yes   | List of numbers.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notInNumber("field", [0, 1]);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### notInString<sup>8+</sup> ###

notInString(field: string, valueList: string[]): Query

Creates a **Query** object to match the specified field whose value is not within the specified list of strings.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| valueList  | string[]  | Yes   | List of strings.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notInString("field", ['test1', 'test2']);
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### like<sup>8+</sup> ###

like(field: string, value: string): Query

Creates a **Query** object to match the specified field whose value is similar to the specified string.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| valueList  | string  | Yes   | String specified.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.like("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### unlike<sup>8+</sup> ###

unlike(field: string, value: string): Query

Creates a **Query** object to match the specified field whose value is not similar to the specified string.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |
| valueList  | string  | Yes   | String specified.|

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.unlike("field", "value");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### and<sup>8+</sup> ###

and(): Query

Creates a **Query** object with the AND condition.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

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
    console.log("dumplicated calls should be ok :" + e);
}
```


### or<sup>8+</sup> ###

or(): Query

Creates a **Query** object with the OR condition.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

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
    console.log("dumplicated calls should be ok :" + e);
}
```


### orderByAsc<sup>8+</sup> ###

orderByAsc(field: string): Query

Creates a **Query** object to sort the query results in ascending order.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value");
    query.orderByAsc("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### orderByDesc<sup>8+</sup> ###

orderByDesc(field: string): Query

Creates a **Query** object to sort the query results in descending order.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field to match. It must start with $ and cannot contain ^. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value");
    query.orderByDesc("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### limit<sup>8+</sup> ###

limit(total: number, offset: number): Query

Creates a **Query** object to specify the number of results and where to start.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| total  | number  | Yes   |Number of results to query. |
| offset | number  | Yes   |Start position for query. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.notEqualTo("field", "value");
    query.limit("total", "offset");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### isNotNull<sup>8+</sup> ###

isNotNull(field: string): Query

Creates a **Query** object with a specified field that is not null.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| fieId  | string  | Yes   |Field specified.     |

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.isNotNull("field");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### beginGroup<sup>8+</sup> ###

beginGroup(): Query

Creates a **Query** object for a query condition group with a left parenthesis.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

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
    console.log("dumplicated calls should be ok :" + e);
}
```


### endGroup<sup>8+</sup> ###

endGroup(): Query

Creates a **Query** object for a query condition group with a right parenthesis.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

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
    console.log("dumplicated calls should be ok :" + e);
}
```


### prefixKey<sup>8+</sup> ###

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
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.prefixKey("$.name");
    query.prefixKey("0");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
    console.log("dumplicated calls should be ok :" + e);
}
```


### setSuggestIndex<sup>8+</sup> ###

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
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    query.setSuggestIndex("$.name");
    query.setSuggestIndex("0");
    console.log("query is " + query.getSqlLike());
    query = null;
} catch (e) {
   console.log("dumplicated calls should be ok :" + e);
}
```


### deviceId<sup>8+</sup> ###

deviceId(deviceId:string):Query

Creates a **Query** object with the device ID as the key prefix.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| deviceId | string  | Yes   |Device ID.  |


**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

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


### getSqlLike<sup>8+</sup> ###

getSqlLike():string

Obtains the query statement of this **Query** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| [Query](#query8) |**Query** object Created.|

**Example**

```js
try {
    let query = new distributedData.Query();
    let sql1 = query.getSqlLike();
    console.log("GetSqlLike sql=" + sql1);
} catch (e) {
    console.log("dumplicated calls should be ok : " + e);
}
```


## KVStore

Provides methods to manage data in a KV store, for example, adding or deleting data and subscribing to data changes or completion of data synchronization. Before calling any method in **KVStore**, you must use **getKVStore** to obtain a **KVStore** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

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
| Promise&lt;void&gt; |Promise used to return the result.|

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
| Promise&lt;void&gt; |Promise used to return the result.|

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

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;ChangeNotification&gt;): void

Subscribes to data changes of the specified type. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| event  |string  | Yes   |Name of the event to subscribe to. The value is **dataChange**, which indicates the data change event.      |
| type  |[SubscribeType](#subscribetype) | Yes   |Type of data changes.    |
| observer |Callback&lt;[ChangeNotification](#changenotification)&gt; | Yes   |Callback used to return the result.|

**Example**

```js
let kvStore;
kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_LOCAL, function (data) {
    console.log("dataChange callback call data: " + JSON.stringify(data));
});
```


### on('syncComplete')

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Subscribes to data synchronization completion events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| event  |string | Yes   |Name of the event to subscribe to. The value is **syncComplete**, which indicates the synchronization complete event.      |
| syncCallback  |Callback&lt;Array&lt;[string, number]&gt;&gt; | Yes   |Callback used to return the result.    |

**Example**

```js
let kvStore;
kvStore.on('syncComplete', function (data) {
    console.log("callback call data: " + data);
});
```

### off('dataChange')<sup>8+</sup>

off(event:'dataChange', observer?: Callback&lt;ChangeNotification&gt;): void

Unsubscribes from data change events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| event  |string  | Yes   |Name of the event to unsubscribe from. The value is **dataChange**, which indicates the data change event.      |
| observer |Callback&lt;[ChangeNotification](#changenotification)&gt; |No   |Callback used to return the result.|

**Example**

```js
let kvStore;
kvStore.on('dataChange', function (data) {
    console.log("callback call data: " + data);
});
kvStore.off('dataChange', function (data) {
    console.log("callback call data: " + data);
});
```


### putBatch<sup>8+</sup>

putBatch(entries: Entry[], callback: AsyncCallback&lt;void&gt;): void

Inserts KV pairs in batches to this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| entries  |[Entry](#entry)[] | Yes   |KV pairs to insert in batches. |
| callback |Asyncallback&lt;void&gt; |Yes    |Callback used to return the result.|

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
        await kvStore.getEntries('batch_test_string_key', function (err,entrys) {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
        });
    });
}catch(e) {
    console.log('PutBatch e ' + e);
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
| Promise&lt;void&gt; |Promise used to return the result.|

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
        await kvStore.getEntries('batch_test_string_key').then((entrys) => {
            console.log('getEntries success');
            console.log('PutBatch ' + JSON.stringify(entries));
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
        await kvStore.deleteBatch(keys, async function (err,data) {
            console.log('deleteBatch success');
        });
    });
}catch(e) {
    console.log('DeleteBatch e ' + e);
}
```


### deleteBatch<sup>8+</sup> ###

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
| Promise&lt;void&gt; |Promise used to return the result.|

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
        await kvStore.deleteBatch(keys).then((err) => {
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


### startTransaction<sup>8+</sup> ###

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
        await kvStore.putBatch(entries, async function (err,data) {
            console.log('putBatch success');
        });
    });
}catch(e) {
    console.log('startTransaction e ' + e);
}
```


### startTransaction<sup>8+</sup> ###

startTransaction(): Promise&lt;void&gt;

Starts the transaction in this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise used to return the result.|

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


### commit<sup>8+</sup> ###

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


### commit<sup>8+</sup> ###

commit(): Promise&lt;void&gt;

Commits the transaction in this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise used to return the result.|

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


### rollback<sup>8+</sup> ###

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


### rollback<sup>8+</sup> ###

rollback(): Promise&lt;void&gt;

Rolls back the transaction in this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise used to return the result.|

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


### enableSync<sup>8+</sup> ###

enableSync(enabled: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets data synchronization, which can be enabled or disable. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| enabled  |boolean | Yes   |Whether to enable data synchronization. The value **true** means to enable data synchronization, and **false** means the opposite. |
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


### enableSync<sup>8+</sup> ###

enableSync(enabled: boolean): Promise&lt;void&gt;

Enables or disables data synchronization. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| enabled  |boolean | Yes   |Whether to enable data synchronization. The value **true** means to enable data synchronization, and **false** means the opposite. |

**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise used to return the result.|

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


### setSyncRange<sup>8+</sup> ###

setSyncRange(localLabels: string[], remoteSupportLabels: string[], callback: AsyncCallback&lt;void&gt;): void

Sets the data synchronization range. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| localLabels  |string[] | Yes   |Synchronization labels set for the local device. |
| remoteSupportLabels  |string[] | Yes   |Synchronization labels set for remote devices. |
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


### setSyncRange<sup>8+</sup> ###

setSyncRange(localLabels: string[], remoteSupportLabels: string[]): Promise&lt;void&gt;

Sets the data synchronization range. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| localLabels  |string[] | Yes   |Synchronization labels set for the local device. |
| remoteSupportLabels  |string[] | Yes   |Synchronization labels set for remote devices. |


**Return value**

| Type   | Description      |
| ------  | -------   |
| Promise&lt;void&gt; |Promise used to return the result.|

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

Defines the subscription type.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Default Value  | Description                   |
| -----  | ------   | ----------------------- |
| SUBSCRIBE_TYPE_LOCAL  |0 |Local data changes. |
| SUBSCRIBE_TYPE_REMOTE |1 |Remote data changes. |
| SUBSCRIBE_TYPE_ALL  |2 |Local and remote data changes. |

## ChangeNotification

Defines the content of data change notifications, including inserted data, updated data, deleted data, and device ID.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type  |Readable  |Writable  | Description                   |
| ----- | -------   | -----| ------|------------------------ |
| insertEntries | [Entry](#entry)[]   | Yes |  Yes|Data inserted.  |
| updateEntries | [Entry](#entry)[]   | Yes |  Yes|Data updated.  |
| deleteEntries | [Entry](#entry)[]   | Yes |  Yes|Data deleted.  |
| deviceId | string   | Yes |  Yes|UUID of the device. |

## Entry

Defines the KV pairs stored in the KV store.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type  |Readable  |Writable  | Description                   |
| ----- | -------   | -----| ------|------------------------ |
| key | string   | Yes |  Yes|Key of the KV pair stored in the KV store.  |
| value | [Value](#value) | Yes |  Yes|Value of the KV pair stored in the KV store.  |


## Value

Defines the value in a KV pair.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Type  |Readable  |Writable  | Description                   |
| ----- | -------   | -----| ------|------------------------ |
| type | [ValueType](#value)   | Yes |  Yes|Type of the value.  |
| value | Uint8Array \| string \| number \| boolean| Yes |  Yes|Value of the KV pair stored in the KV store.  |

## ValueType

Enumerates the types of values in KV pairs.

These value types can be used only by internal applications.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name | Default Value  | Description                   |
| -----  | ------   | ----------------------- |
| STRING  |0 |String. |
| INTEGER |1 |Integer. |
| FLOAT   |2 |Float (single-precision floating point). |
| BYTE_ARRAY   |3 |Byte array. |
| BOOLEAN   |4 |Boolean. |
| DOUBLE   |5 |Double (double-precision floating point). |


## SingleKVStore

Provides methods to query and synchronize data in a single KV store. This class inherits from **KVStore**. Before calling any method in **SingleKVStore**, you must use [getKVStore](#getkvstore) to obtain a **SingleKVStore** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

### get

get(key: string, callback: AsyncCallback&lt;Uint8Array | string | boolean | number&gt;): void

Obtains the value of a specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| key    |string   | Yes   |Key of the value to obtain. It cannot be empty, and the length cannot exceed [MAX_KEY_LENGTH](#constants). |
| callback  |AsyncCallback&lt;Uint8Array \| string \| boolean \| number&gt;) | Yes   |Callback used to return the value obtained. |

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

Obtains the value of a specified key. This API uses a promise to return the result.

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

### getEntries<sup>8+</sup> ###

getEntries(keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified key prefix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix    |string   | Yes   |Key prefix to match. |
| callback    |AsyncCallback&lt;[Entry](#entry)[]&gt;   | Yes   |Callback used to return the KV pairs obtained. |

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
        await kvStore.getEntries('batch_test_number_key', function (err,entrys) {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
        });
    });
}catch(e) {
    console.log('PutBatch e ' + e);
}
```


### getEntries<sup>8+</sup> ###

getEntries(keyPrefix: string): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified key prefix. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix    |string   | Yes   |Key prefix to match. |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs obtained.|

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
        await kvStore.getEntries('batch_test_string_key').then((entrys) => {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
            console.log('entrys[0].value: ' + JSON.stringify(entrys[0].value));
            console.log('entrys[0].value.value: ' + entrys[0].value.value);
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


### getEntries<sup>8+</sup> ###

getEntries(query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| query  |[Query](#query8)   | Yes   |**Query** object to match. |
| callback  |AsyncCallback&lt;[Entry](#entry)[]&gt;   | Yes   |Callback used to return the KV pairs obtained. |

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
        await kvStore.getEntries(query, function (err,entrys) {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
        });
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getEntries<sup>8+</sup> ###

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
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs obtained.|

**Example**

```js
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
        await kvStore.getEntries(query).then((entrys) => {
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


### getResultSet<sup>8+</sup> ###

getResultSet(keyPrefix: string, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains the result set with the specified key prefix from this single KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix  |string   | Yes   |Key prefix to match.|
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)&gt;   | Yes   |Callback used to return the result set obtained.|

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
        await kvStore.getResultSet('batch_test_string_key', async function (err, result) {
            console.log('GetResultSet getResultSet success');
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


### getResultSet<sup>8+</sup> ###

getResultSet(keyPrefix: string): Promise&lt;KvStoreResultSet&gt;

Obtains the result set with the specified key prefix from this single KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------  | ----  | ----------------------- |
| keyPrefix  |string   | Yes   |Key prefix to match.|

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)&gt; |Promise used to return the result set obtained.|

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
        console.log('GetResult getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + JSON.stringify(err));
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


### getResultSet<sup>8+</sup> ###

getResultSet(query: Query, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains the **KvStoreResultSet** object that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

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
        await kvStore.getResultSet(query, async function (err, result) {
            console.log('getResultSet success');
            resultSet = result;
        });
    });
} catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup> ###

getResultSet(query: Query): Promise&lt;KvStoreResultSet&gt;

Obtains the **KvStoreResultSet** object that matches the specified **Query** object. This API uses a promise to return the result.

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
        console.log(' getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSet e ' + e);
}
```

### closeResultSet<sup>8+</sup> ###

closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback&lt;void&gt;): void

Closes the **KvStoreResultSet** object obtained by **getResultSet**. This API uses an asynchronous callback to return the result.

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


### closeResultSet<sup>8+</sup> ###

closeResultSet(resultSet: KvStoreResultSet): Promise&lt;void&gt;

Closes the **KvStoreResultSet** object obtained by **getResultSet**. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| resultSet  |[KvStoreResultSet](#kvstoreresultset8)   | Yes   |**KvStoreResultSet** object to close.            |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise used to return the result.|

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


### getResultSize<sup>8+</sup> ###

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

Obtains the number of results that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)   | Yes   |**Query** object to match.        |
| callback  |AsyncCallback&lt;number&gt;   | Yes   |Callback used to return the number of results obtained.        |

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
        await kvStore.getResultSize(query, async function (err, resultSize) {
            console.log('getResultSet success');
        });
    });
} catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup> ###

getResultSize(query: Query): Promise&lt;number&gt;

Obtains the number of results that matches the specified **Query** object. This API uses a promise to return the result.

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
        console.log('getResultSet success');
    }).catch((err) => {
        console.log('getResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### removeDeviceData<sup>8+</sup> ###

removeDeviceData(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes data of a device. This API uses an asynchronous callback to return the result.

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
        await kvStore.removeDeviceData(deviceid, async function (err,data) {
            if (err == undefined) {
                console.log('removeDeviceData success');
            } else {
                console.log('removeDeviceData fail');
                await kvStore.get(KEY_TEST_STRING_ELEMENT, async function (err,data) {
                    console.log('RemoveDeviceData get success');
                });
            }
        });
    });
}catch(e) {
    console.log('RemoveDeviceData e ' + e);
}
```


### removeDeviceData<sup>8+</sup> ###

removeDeviceData(deviceId: string): Promise&lt;void&gt;

Deletes data of a device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string   | Yes   |ID of the target device.      |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise used to return the result.|

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


### on('syncComplete')<sup>8+</sup> ###

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Subscribes to the synchronization completion events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| event  |string   | Yes   |Name of the event to subscribe to. The value is **syncComplete**, which indicates the synchronization complete event.   |
| syncCallback  |Callback&lt;Array&lt;[string, number]&gt;&gt;   | Yes   |Callback used to return the synchronization result.   |

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


### off('syncComplete')<sup>8+</sup> ###

off(event: 'syncComplete', syncCallback?: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Unsubscribes from the synchronization completion events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| event  |string   | Yes   |Name of the event to unsubscribe from. The value is **syncComplete**, which indicates the synchronization complete event.   |
| syncCallback  |Callback&lt;Array&lt;[string, number]&gt;&gt;   | No   |Callback used to return the synchronization result.   |

**Example**

```js
let kvStore;
try {
    const func = function (data) {
        console.log('syncComplete ' + data)
    };
    kvStore.on('syncComplete', func);
    kvStore.off('syncComplete', func);
}catch(e) {
    console.log('syncComplete e ' + e);
}
```


### sync

sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void

Manually triggers KV store synchronization synchronously.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceIdList  |string[]  | Yes   |IDs of the devices to be synchronized. These devices must be in the same networking environment.   |
| mode  |[SyncMode](#syncmode)   | Yes  |Data synchronization mode.   |
| allowedDelayMs  |number   | No  |Allowed synchronization delay time, in ms.  |

**Example**

```js
let kvStore;
kvStore.sync('deviceIds', distributedData.SyncMode.PULL_ONLY, 1000);
```

### setSyncParam<sup>8+</sup> ###

setSyncParam(defaultAllowedDelayMs: number, callback: AsyncCallback&lt;void&gt;): void

Sets the default delay of database synchronization. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| defaultAllowedDelayMs  |number  | Yes   |Default delay allowed for database synchronization, in ms.   |
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


### setSyncParam<sup>8+</sup> ###

setSyncParam(defaultAllowedDelayMs: number): Promise&lt;void&gt;

Sets the default delay of database synchronization. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| defaultAllowedDelayMs  |number  | Yes   |Default delay allowed for database synchronization, in ms.   |


**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise used to return the result.|

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


### getSecurityLevel<sup>8+</sup> ###

getSecurityLevel(callback: AsyncCallback&lt;SecurityLevel&gt;): void

Obtains the security level of this KV store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| callback  |AsyncCallback&lt;[SecurityLevel](#securitylevel)&gt;  | Yes   |Callback used to return the security level obtained.   |

**Example**

```js
let kvStore;
try {
    kvStore.getSecurityLevel(function (err,data) {
        console.log('getSecurityLevel success');
    });
}catch(e) {
    console.log('GetSecurityLeve e ' + e);
}
```


### getSecurityLevel<sup>8+</sup> ###

getSecurityLevel(): Promise&lt;SecurityLevel&gt;

Obtains the security level of this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[SecurityLevel](#securitylevel)&gt; |Promise used to return the security level obtained.|

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
    console.log('GetSecurityLeve e ' + e);
}
```


## DeviceKVStore<sup>8+</sup> ##

Provides methods to manage distributed data by device in the distributed system. This class inherits from **KVStore** and provides data query and synchronization methods. Before calling any method in **DeviceKVStore**, you must use [getKVStore](#getkvstore) to obtain a **DeviceKVStore** object.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

### get<sup>8+</sup> ###

get(deviceId: string, key: string, callback: AsyncCallback&lt;boolean|string|number|Uint8Array&gt;): void

Obtains the string value that matches the specified key for a device. This API uses an asynchronous callback to return the result.

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


### get<sup>8+</sup> ###

get(deviceId: string, key: string): Promise&lt;boolean|string|number|Uint8Array&gt;

Obtains the string value that matches the specified key for a device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| key       |string  | Yes   |Key to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;boolean\|string\|number\|Uint8Array&gt; |Promise used to return the value obtained.|

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


### getEntries<sup>8+</sup> ###

getEntries(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified key prefix for a device. This API uses an asynchronous callback to return the result.

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
        await kvStore.getEntries('localDeviceId', 'batch_test_string_key', function (err,entrys) {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
        });
    });
}catch(e) {
    console.log('PutBatch e ' + e);
}
```


### getEntries<sup>8+</sup> ###

getEntries(deviceId: string, keyPrefix: string): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified key prefix for a device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| keyPrefix |string  | Yes   |Key prefix to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs obtained.|

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
        await kvStore.getEntries('localDeviceId', 'batch_test_string_key').then((entrys) => {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
            console.log('entrys[0].value: ' + JSON.stringify(entrys[0].value));
            console.log('entrys[0].value.value: ' + entrys[0].value.value);
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


### getEntries<sup>8+</sup> ###

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
        expect(err == undefined).assertTrue();
        const query = new distributedData.Query();
        query.prefixKey("batch_test");
        query.deviceId('localDeviceId');
        await kvStore.getEntries(query, function (err,entrys) {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
        });
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getEntries<sup>8+</sup> ###

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
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs obtained.|

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
        await kvStore.getEntries(query).then((entrys) => {
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


### getEntries<sup>8+</sup> ###

getEntries(deviceId: string, query: Query, callback: AsyncCallback&lt;Entry[]&gt;): void

Obtains the KV pairs that match the specified **Query** object for a device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
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
        expect(err == undefined).assertTrue();
        var query = new distributedData.Query();
        query.deviceId('localDeviceId');
        query.prefixKey("batch_test");
        await kvStore.getEntries('localDeviceId', query, function (err,entrys) {
            console.log('getEntries success');
            console.log('entrys.length: ' + entrys.length);
            console.log('entrys[0]: ' + JSON.stringify(entrys[0]));
        })
    });
    console.log('GetEntries success');
}catch(e) {
    console.log('GetEntries e ' + e);
}
```


### getEntries<sup>8+</sup> ###

getEntries(deviceId: string, query: Query): Promise&lt;Entry[]&gt;

Obtains the KV pairs that match the specified **Query** object for a device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[Entry](#entry)[]&gt; |Promise used to return the KV pairs obtained.|

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
        await kvStore.getEntries('localDeviceId', query).then((entrys) => {
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


### getResultSet<sup>8+</sup> ###

getResultSet(deviceId: string, keyPrefix: string, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains the **KvStoreResultSet** object that matches the specified key prefix for a device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| keyPrefix |string  | Yes   |Key prefix to match.   |
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)[]&gt;  | Yes |Callback used to return the **KvStoreResultSet** object obtained.   |

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key', async function (err, result) {
        console.log('getResultSet success');
        resultSet = result;
        await kvStore.closeResultSet(resultSet, function (err, data) {
            console.log('closeResultSet success');
        })
    });
}catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup> ###

getResultSet(deviceId: string, keyPrefix: string): Promise&lt;KvStoreResultSet&gt;

Obtains the **KvStoreResultSet** object that matches the specified key prefix for a device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| keyPrefix |string  | Yes   |Key prefix to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)[]&gt; |Promise used to return the **KvStoreResultSet** object obtained.|

**Example**

```js
let kvStore;
try {
    let resultSet;
    kvStore.getResultSet('localDeviceId', 'batch_test_string_key').then((result) => {
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + JSON.stringify(err));
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


### getResultSet<sup>8+</sup> ###

getResultSet(query: Query, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains the **KvStoreResultSet** object that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)[]&gt;  | Yes |Callback used to return the **KvStoreResultSet** object obtained.   |

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
        await kvStore.getResultSet(query, async function (err, result) {
            console.log('getResultSet success');
            resultSet = result;
            await kvStore.closeResultSet(resultSet, function (err, data) {
                console.log('closeResultSet success');
            })
        });
    });
} catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup> ###

getResultSet(query: Query): Promise&lt;KvStoreResultSet&gt;

Obtains the **KvStoreResultSet** object that matches the specified **Query** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)[]&gt; |Promise used to return the **KvStoreResultSet** object obtained.|

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
        console.log('getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('getResultSet fail ' + JSON.stringify(err));
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


### getResultSet<sup>8+</sup> ###

getResultSet(deviceId: string, query: Query, callback: AsyncCallback&lt;KvStoreResultSet&gt;): void

Obtains the **KvStoreResultSet** object that matches the specified **Query** object for a device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |
| callback  |AsyncCallback&lt;[KvStoreResultSet](#kvstoreresultset8)[]&gt;  | Yes |Callback used to return the **KvStoreResultSet** object obtained.   |

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
        await kvStore.getResultSet('localDeviceId', query, async function (err, result) {
            console.log('getResultSet success');
            resultSet = result;
            await kvStore.closeResultSet(resultSet, function (err, data) {
                console.log('closeResultSet success');
            })
        });
    });
} catch(e) {
    console.log('GetResultSet e ' + e);
}
```


### getResultSet<sup>8+</sup> ###

getResultSet(deviceId: string, query: Query): Promise&lt;KvStoreResultSet&gt;

Obtains the **KvStoreResultSet** object that matches the specified **Query** object for a device. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device.   |
| query  |[Query](#query8)  | Yes   |**Query** object to match.   |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;[KvStoreResultSet](#kvstoreresultset8)[]&gt; |Promise used to return the **KvStoreResultSet** object obtained.|

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
        console.log('GetResultSet getResultSet success');
        resultSet = result;
    }).catch((err) => {
        console.log('GetResultSet getResultSet fail ' + JSON.stringify(err));
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


### closeResultSet<sup>8+</sup> ###

closeResultSet(resultSet: KvStoreResultSet, callback: AsyncCallback&lt;void&gt;): void

Closes the **KvStoreResultSet** object obtained by **getResultSet**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| resultSet  |[KvStoreResultSet](#getresultset8)  | Yes   |**KvStoreResultSet** object to close.  |
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


### closeResultSet<sup>8+</sup> ###

closeResultSet(resultSet: KvStoreResultSet): Promise&lt;void&gt;

Closes the **KvStoreResultSet** object obtained by **getResultSet**. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| resultSet  |[KvStoreResultSet](#getresultset8)  | Yes   |**KvStoreResultSet** object to close.  |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise used to return the result.|

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


### getResultSize<sup>8+</sup> ###

getResultSize(query: Query, callback: AsyncCallback&lt;number&gt;): void

Obtains the number of results that matches the specified **Query** object. This API uses an asynchronous callback to return the result.

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
        await kvStore.getResultSize(query, async function (err, resultSize) {
            console.log('getResultSet success');
        });
    });
} catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup> ###

getResultSize(query: Query): Promise&lt;number&gt;

Obtains the number of results that matches the specified **Query** object. This API uses a promise to return the result.

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
        console.log('getResultSet success');
    }).catch((err) => {
        console.log('getResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup> ###

getResultSize(deviceId: string, query: Query, callback: AsyncCallback&lt;number&gt;): void;

Obtains the number of results that matches the specified **Query** object for a device. This API uses an asynchronous callback to return the result.

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
        await kvStore.getResultSize('localDeviceId', query, async function (err, resultSize) {
            console.log('getResultSet success');
        });
    });
} catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### getResultSize<sup>8+</sup> ###

getResultSize(deviceId: string, query: Query): Promise&lt;number&gt;

Obtains the number of results that matches the specified **Query** object for a device. This API uses a promise to return the result.

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
        console.log('getResultSet success');
    }).catch((err) => {
        console.log('getResultSet fail ' + JSON.stringify(err));
    });
}catch(e) {
    console.log('GetResultSize e ' + e);
}
```


### removeDeviceData<sup>8+</sup> ###

removeDeviceData(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Removes data of a device from this KV store. This API uses an asynchronous callback to return the result.

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
        await kvStore.removeDeviceData(deviceid, async function (err,data) {
            if (err == undefined) {
                console.log('removeDeviceData success');
            } else {
                console.log('removeDeviceData fail');
                await kvStore.get('localDeviceId', KEY_TEST_STRING_ELEMENT, async function (err,data) {
                    console.log('RemoveDeviceData get success');
                });
            }
        });
    });
}catch(e) {
    console.log('RemoveDeviceData e ' + e);
}
```


### removeDeviceData<sup>8+</sup> ###

removeDeviceData(deviceId: string): Promise&lt;void&gt;

Removes data of a device from this KV store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceId  |string  | Yes   |ID of the target device. |

**Return value**

| Type   | Description      |
| ------  | -------   |
|Promise&lt;void&gt; |Promise used to return the result.|

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


### sync<sup>8+</sup> ###

sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void

Manually triggers KV store synchronization synchronously.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| deviceIdList    |string[]               | Yes   |IDs of the devices to be synchronized.|
| mode            |[SyncMode](#syncmode)  | Yes   |Data synchronization mode, which can be **PUSH**, **PULL**, or **PUSH_PULL**. |
| allowedDelayMs  |number                 | No   |Allowed synchronization delay time, in ms. |

**Example**

```js
let kvStore;
const KEY_TEST_SYNC_ELEMENT = 'key_test_sync';
const VALUE_TEST_SYNC_ELEMENT = 'value-string-001';
try {
    kvStore.on('syncComplete', function (data) {
        console.log('Sync dataChange');
    });
    kvStore.put(KEY_TEST_SYNC_ELEMENT + 'testSync101', VALUE_TEST_SYNC_ELEMENT, function (err,data) {
        console.log('Sync put success');
        const devices = ['deviceList'];
        const mode = distributedData.SyncMode.PULL_ONLY;
        kvStore.sync(devices, mode);
    });
}catch(e) {
    console.log('Sync e' + e);
}
```

### on('syncComplete')<sup>8+</sup> ###

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Subscribes to the synchronization completion events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| event    |string      | Yes   |Name of the event to subscribe to. The value is **syncComplete**, which indicates the synchronization complete event.|
| syncCallback            |Callback<Array&lt;[string, number]&gt;> | Yes   |Callback used to return the synchronization result. |

**Example**

```js
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


### off('syncComplete')<sup>8+</sup> ###

off(event: 'syncComplete', syncCallback?: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

Unsubscribes from the synchronization completion events. This API uses a synchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

**Parameters**

| Name | Type| Mandatory | Description                   |
| -----  | ------   | ----  | ----------------------- |
| event         |string                           | Yes   |Name of the event to unsubscribe from. The value is **syncComplete**, which indicates the synchronization complete event.|
| syncCallback  |Callback<Array&lt;[string, number]&gt;&gt; | No   |Callback used to return the synchronization result. |

**Example**

```js
let kvStore;
try {
    const func = function (data) {
        console.log('syncComplete ' + data)
    };
    kvStore.on('syncComplete', func);
    kvStore.off('syncComplete', func);
}catch(e) {
    console.log('syncComplete e ' + e);
}
```


## SyncMode

Defines the synchronization mode.

**System capability**: SystemCapability.DistributedDataManager.KVStore.Core

| Name      | Default Value    | Description                   |
| -----      | ------    | ----------------------- |
| PULL_ONLY  |0          |Pull data from the peer end to the local end only.|
| PUSH_ONLY  |1          |Push data from the local end to the peer end only.|
| PUSH_PULL  |2          |Push data from the local end to the peer end and then pull data from the peer end to the local end.|
