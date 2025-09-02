# @ohos.data.storage (Lightweight Data Storage)

Lightweight storage provides applications with data processing capability and allows applications to perform lightweight data storage and query. Data is stored in key-value (KV) pairs. Keys are of the string type, and values can be of the number, string, or Boolean type.

> **NOTE**<br/>
>
> -  The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> -  The APIs of this module are no longer maintained since API version 9. You are advised to use [@ohos.data.preferences](js-apis-data-preferences.md).


## Modules to Import

```js
import data_storage from '@ohos.data.storage';
```

## Constants

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name            | Type | Readable | Writable | Description                                 |
| ---------------- | -------- | ---- | ---- | ------------------------------------- |
| MAX_KEY_LENGTH   | number   | Yes  | No  | Maximum length of a key, which is 80 bytes.    |
| MAX_VALUE_LENGTH | number   | Yes  | No  | Maximum length of a value, which is 8192 bytes. |


## data_storage.getStorageSync

getStorageSync(path: string): Storage

Reads the specified file and loads its data to the **Storage** instance for data operations.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Path of the target file. |

**Return value**

| Type               | Description                                             |
| ------------------- | ------------------------------------------------- |
| [Storage](#storage) | **Storage** instance used for data storage operations. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
  path = filePath;
  console.info("======================>getFilesDirPromise====================>");

  let storage = data_storage.getStorageSync(path + '/mystore');
  storage.putSync('startup', 'auto');
  storage.flushSync();
});
```


## data_storage.getStorage

getStorage(path: string, callback: AsyncCallback&lt;Storage&gt;): void

Reads the specified file and loads its data to the **Storage** instance for data operations. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                    | Mandatory | Description                      |
| -------- | ---------------------------------------- | ---- | -------------------------- |
| path     | string                                   | Yes  | Path of the target file. |
| callback | AsyncCallback&lt;[Storage](#storage)&gt; | Yes  | Callback used to return the result.                |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
  path = filePath;
  console.info("======================>getFilesDirPromise====================>");

  data_storage.getStorage(path + '/mystore', function (err, storage) {
    if (err) {
      console.info("Failed to get the storage. path: " + path + '/mystore');
      return;
    }
    storage.putSync('startup', 'auto');
    storage.flushSync();
  })
});
```


## data_storage.getStorage

getStorage(path: string): Promise&lt;Storage&gt;

Reads the specified file and loads its data to the **Storage** instance for data operations. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Path of the target file. |

**Return value**

| Type                              | Description                           |
| ---------------------------------- | ------------------------------- |
| Promise&lt;[Storage](#storage)&gt; | Promise used to return the result. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
  path = filePath;
  console.info("======================>getFilesDirPromise====================>");

  let getPromise = data_storage.getStorage(path + '/mystore');
  getPromise.then((storage) => {
    storage.putSync('startup', 'auto');
    storage.flushSync();
  }).catch((err) => {
    console.info("Failed to get the storage. path: " + path + '/mystore');
  })
});
```


## data_storage.deleteStorageSync

deleteStorageSync(path: string): void

Deletes the singleton **Storage** instance of a file from the memory, and deletes the specified file, its backup file, and damaged files. After the specified files are deleted, the **Storage** instance cannot be used for data operations. Otherwise, data inconsistency will occur.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Path of the target file. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
    path = filePath;
    console.info("======================>getFilesDirPromise====================>");

    data_storage.deleteStorageSync(path + '/mystore');
});
```

## data_storage.deleteStorage

deleteStorage(path: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the singleton **Storage** instance of a file from the memory, and deletes the specified file, its backup file, and damaged files. After the specified files are deleted, the **Storage** instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory | Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Path of the target file. |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
  path = filePath;
  console.info("======================>getFilesDirPromise====================>");

  data_storage.deleteStorage(path + '/mystore', function (err) {
    if (err) {
      console.info("Failed to delete the storage with err: " + err);
      return;
    }
    console.info("Succeeded in deleting the storage.");
  })
});
```


## data_storage.deleteStorage

deleteStorage(path: string): Promise&lt;void&gt;

Deletes the singleton **Storage** instance of a file from the memory, and deletes the specified file, its backup file, and damaged files. After the specified files are deleted, the **Storage** instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Path of the target file. |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
  path = filePath;
  console.info("======================>getFilesDirPromise====================>");

  let promisedelSt = data_storage.deleteStorage(path + '/mystore');
  promisedelSt.then(() => {
    console.info("Succeeded in deleting the storage.");
  }).catch((err) => {
    console.info("Failed to delete the storage with err: " + err);
  })
});
```


## data_storage.removeStorageFromCacheSync

removeStorageFromCacheSync(path: string): void

Removes the singleton **Storage** instance of a file from the cache. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Path of the target file. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
    path = filePath;
    console.info("======================>getFilesDirPromise====================>");

    data_storage.removeStorageFromCacheSync(path + '/mystore');
});
```


## data_storage.removeStorageFromCache

removeStorageFromCache(path: string, callback: AsyncCallback&lt;void&gt;): void

Removes the singleton **Storage** instance of a file from the cache. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory | Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | Yes  | Path of the target file. |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
  path = filePath;
  console.info("======================>getFilesDirPromise====================>");

  data_storage.removeStorageFromCache(path + '/mystore', function (err) {
    if (err) {
      console.info("Failed to remove storage from cache with err: " + err);
      return;
    }
    console.info("Succeeded in removing storage from cache.");
  })
});
```


## data_storage.removeStorageFromCache

removeStorageFromCache(path: string): Promise&lt;void&gt;

Removes the singleton **Storage** instance of a file from the cache. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Path of the target file. |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let path;
let context = featureAbility.getContext();
context.getFilesDir().then((filePath) => {
  path = filePath;
  console.info("======================>getFilesDirPromise====================>");

  let promiserevSt = data_storage.removeStorageFromCache(path + '/mystore')
  promiserevSt.then(() => {
    console.info("Succeeded in removing storage from cache.");
  }).catch((err) => {
    console.info("Failed to remove storage from cache with err: " + err);
  })
});
```

## Storage

Provides APIs for obtaining and modifying storage data.

Before calling the following APIs, use [data_storage.getStorage](#data_storagegetstorage) or [data_storage.getStorageSync](#data_storagegetstoragesync) to obtain the **Storage** instance.

### getSync

getSync(key: string, defValue: ValueType): ValueType

Obtains the value corresponding to a key. If the value is null or not of the default value type, **defValue** is returned.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                   | Mandatory | Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| key      | string                  | Yes  | Key of the data. It cannot be empty.                             |
| defValue | [ValueType](#valuetype) | Yes  | Default value to be returned if the value of the specified key does not exist. It can be a number, string, or Boolean value. |

**Return value**

| Type     | Description                                                    |
| --------- | -------------------------------------------------------- |
| ValueType | Value corresponding to the specified key. If the value is null or not in the default value format, the default value is returned. |

**Example**

```js
let value = storage.getSync('startup', 'default');
console.info("The value of startup is " + value);
```


### get

get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void

Obtains the value corresponding to a key. If the value is null or not of the default value type, **defValue** is returned. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                          | Mandatory | Description                                     |
| -------- | ------------------------------ | ---- | ----------------------------------------- |
| key      | string                         | Yes  | Key of the data. It cannot be empty.          |
| defValue | [ValueType](#valuetype)        | Yes  | Default value to be returned. It can be a number, string, or Boolean value. |
| callback | AsyncCallback&lt;ValueType&gt; | Yes  | Callback used to return the result.                               |

**Example**

```js
storage.get('startup', 'default', function(err, value) {
    if (err) {
        console.info("Failed to get the value of startup with err: " + err);
        return;
      }
    console.info("The value of startup is " + value);
})
```


### get

get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;

Obtains the value corresponding to a key. If the value is null or not of the default value type, **defValue** is returned. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                   | Mandatory | Description                                     |
| -------- | ----------------------- | ---- | ----------------------------------------- |
| key      | string                  | Yes  | Key of the data. It cannot be empty.          |
| defValue | [ValueType](#valuetype) | Yes  | Default value to be returned. It can be a number, string, or Boolean value. |

**Return value**

| Type                    | Description                           |
| ------------------------ | ------------------------------- |
| Promise&lt;ValueType&gt; | Promise used to return the result. |

**Example**

```js
let promiseget = storage.get('startup', 'default');
promiseget.then((value) => {
    console.info("The value of startup is " + value)
}).catch((err) => {
    console.info("Failed to get the value of startup with err: " + err);
})
```


### putSync

putSync(key: string, value: ValueType): void

Obtains the **Storage** instance corresponding to the specified file, writes data to the **Storage** instance using a **Storage** API, and saves the modification using **flush()** or **flushSync()**.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                   | Mandatory | Description                                     |
| ------ | ----------------------- | ---- | ----------------------------------------- |
| key    | string                  | Yes  | Key of the data. It cannot be empty.            |
| value  | [ValueType](#valuetype) | Yes  | New value to store. It can be a number, string, or Boolean value. |

**Example**

```js
storage.putSync('startup', 'auto');
```


### put

put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void

Obtains the **Storage** instance corresponding to the specified file, writes data to the **Storage** instance using a **Storage** API, and saves the modification using **flush()** or **flushSync()**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory | Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| key      | string                    | Yes  | Key of the data. It cannot be empty.            |
| value    | [ValueType](#valuetype)   | Yes  | New value to store. It can be a number, string, or Boolean value. |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                               |

**Example**

```js
storage.put('startup', 'auto', function (err) {
    if (err) {
        console.info("Failed to put the value of startup with err: " + err);
        return;
    }
    console.info("Succeeded in putting the value of startup.");
})
```


### put

put(key: string, value: ValueType): Promise&lt;void&gt;

Obtains the **Storage** instance corresponding to the specified file, writes data to the **Storage** instance using a **Storage** API, and saves the modification using **flush()** or **flushSync()**. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                   | Mandatory | Description                                     |
| ------ | ----------------------- | ---- | ----------------------------------------- |
| key    | string                  | Yes  | Key of the data. It cannot be empty.            |
| value  | [ValueType](#valuetype) | Yes  | New value to store. It can be a number, string, or Boolean value. |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```js
let promiseput = storage.put('startup', 'auto');
promiseput.then(() => {
    console.info("Succeeded in putting the value of startup.");
}).catch((err) => {
    console.info("Failed to put the value of startup with err: " + err);
})
```


### hasSync

hasSync(key: string): boolean

Checks whether the storage object contains data with a given key.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the data. It cannot be empty. |

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| boolean | Returns **true** if the storage object contains data with the specified key; returns **false** otherwise. |

**Example**

```js
let isExist = storage.hasSync('startup');
if (isExist) {
    console.info("The key of startup is contained.");
}
```


### has

has(key: string, callback: AsyncCallback&lt;boolean&gt;): boolean

Checks whether the storage object contains data with a given key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                        | Mandatory | Description                           |
| -------- | ---------------------------- | ---- | ------------------------------- |
| key      | string                       | Yes  | Key of the data. It cannot be empty. |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.                     |

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| boolean | Returns **true** if the storage object contains data with the specified key; returns **false** otherwise. |

**Example**

```js
storage.has('startup', function (err, isExist) {
    if (err) {
        console.info("Failed to check the key of startup with err: " + err);
        return;
    }
    if (isExist) {
        console.info("The key of startup is contained.");
    }
})
```


### has

has(key: string): Promise&lt;boolean&gt;

Checks whether the storage object contains data with a given key. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the data. It cannot be empty. |

**Return value**

| Type                  | Description                       |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. |

**Example**

```js
let promisehas = storage.has('startup')
promisehas.then((isExist) => {
    if (isExist) {
        console.info("The key of startup is contained.");
    }
}).catch((err) => {
    console.info("Failed to check the key of startup with err: " + err);
})
```


### deleteSync

deleteSync(key: string): void

Deletes data with the specified key from this storage object.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                             |
| ------ | ------ | ---- | --------------------------------- |
| key    | string | Yes  | Key of the data. It cannot be empty. |

**Example**

```js
 storage.deleteSync('startup');
```


### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

Deletes data with the specified key from this storage object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory | Description                           |
| -------- | ------------------------- | ---- | ------------------------------- |
| key      | string                    | Yes  | Key of the data. It cannot be empty. |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                     |

**Example**

```js
storage.delete('startup', function (err) {
    if (err) {
        console.info("Failed to delete startup key failed err: " + err);
        return;
    }
    console.info("Succeeded in deleting startup key.");
})
```


### delete

delete(key: string): Promise&lt;void&gt;

Deletes data with the specified key from this storage object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type  | Mandatory | Description                 |
| ------ | ------ | ---- | --------------------- |
| key    | string | Yes  | Key of the data. |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```js
let promisedel = storage.delete('startup')
promisedel.then(() => {
    console.info("Succeeded in deleting startup key.");
}).catch((err) => {
    console.info("Failed to delete startup key failed err: " + err);
})
```


### flushSync

flushSync(): void

Saves the modification of this object to the **Storage** instance and synchronizes the modification to the file.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Example**

```js
storage.flushSync();
```


### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Saves the modification of this object to the **Storage** instance and synchronizes the modification to the file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory | Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. |

**Example**

```js
storage.flush(function (err) {
    if (err) {
        console.info("Failed to flush to file with err: " + err);
        return;
    }
    console.info("Succeeded in flushing to file.");
})
```


### flush

flush(): Promise&lt;void&gt;

Saves the modification of this object to the **Storage** instance and synchronizes the modification to the file. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```js
let promiseflush = storage.flush();
promiseflush.then(() => {
    console.info("Succeeded in flushing to file.");
}).catch((err) => {
    console.info("Failed to flush to file with err: " + err);
})
```


### clearSync

clearSync(): void

Clears this **Storage** object.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Example**

```js
storage.clearSync();
```


### clear

clear(callback: AsyncCallback&lt;void&gt;): void

Clears this **Storage** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory | Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. |

**Example**

```js
storage.clear(function (err) {
    if (err) {
        console.info("Failed to clear the storage with err: " + err);
        return;
    }
    console.info("Succeeded in clearing the storage.");
})
```


### clear

clear(): Promise&lt;void&gt;

Clears this **Storage** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**
| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```js
let promiseclear = storage.clear();
promiseclear.then(() => {
    console.info("Succeeded in clearing the storage.");
}).catch((err) => {
    console.info("Failed to clear the storage with err: " + err);
})
```


### on('change')

on(type: 'change', callback: Callback&lt;StorageObserver&gt;): void

Subscribes to data changes. The **StorageObserver** needs to be implemented. When the value of the key subscribed to is changed, a callback will be invoked after **flush()** or **flushSync()** is executed.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                               |  Mandatory| Description                                    |
| -------- | --------------------------------------------------- | ------ |---------------------------------------- |
| type     | string                                              |Yes| Event type. The value **change** indicates data change events. |
| callback | Callback&lt;[StorageObserver](#storageobserver)&gt; | Yes|Callback used to return the result.                          |

**Example**

```js
let observer = function (key) {
    console.info("The key of " + key + " changed.");
}
storage.on('change', observer);
storage.putSync('startup', 'auto');
storage.flushSync();  // observer will be called.
```


### off('change')

off(type: 'change', callback: Callback&lt;StorageObserver&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                               | Mandatory |  Description                                |
| -------- | --------------------------------------------------- | ------ |---------------------------------------- |
| type     | string                                              |Yes| Event type. The value **change** indicates data change events. |
| callback | Callback&lt;[StorageObserver](#storageobserver)&gt; | Yes|Callback for the data change.                |

**Example**

```js
let observer = function (key) {
    console.info("The key of " + key + " changed.");
}
storage.off('change', observer);
```


## StorageObserver

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name | Type | Mandatory | Description            |
| ---- | -------- | ---- | ---------------- |
| key  | string   | Yes  | Data changed. |

## ValueType

type ValueType = number | string | boolean

Enumerates the value types.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.  |
| boolean | The value is of Boolean type. |
