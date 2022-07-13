# Preferences

Preferences provide capabilities for processing data in the form of key-value (KV) pairs and support lightweight data persistence, modification, and query. In KV pairs, the keys are of the string type, and the values can be of the number, string, or Boolean type.


> **NOTE**<br/>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import data_preferences from '@ohos.data.preferences';
```

## Constants

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| MAX_KEY_LENGTH | string | Yes| No| Maximum length of a key. It must be less than 80 bytes.|
| MAX_VALUE_LENGTH | string | Yes| No| Maximum length of a value. It must be less than 8192 bytes.|


## data_preferences.getPreferences

getPreferences(context: Context, name: string, callback: AsyncCallback&lt;Preferences&gt;): void

Reads a **Preferences** persistence file and loads data to the **Preferences** instance for data operations. This API uses an asynchronous callback to return the result.


**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | Yes| Context of the application or function.|
  | name | string | Yes| Name of the **Preferences** instance persistence file.|
  | callback | AsyncCallback&lt;[Preferences](#preferences)&gt; | Yes| Callback used to return the result.|

**Example**
```ts
data_preferences.getPreferences(this.context, 'mystore', function (err, preferences) {
    if (err) {
              console.info("Failed to get the preferences")
        return;
    }
    console.info("Got preferences successfully.")
})
```


## data_preferences.getPreferences

getPreferences(context: Context, name: string): Promise&lt;Preferences&gt;

Reads a **Preferences** persistence file and loads data to the **Preferences** instance for data operations. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | Yes| Context of the application or function.|
  | name | string | Yes| Name of the **Preferences** instance persistence file.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[Preferences](#preferences)&gt; | Promise used to return the result.|

**Example**
```ts
let promise = data_preferences.getPreferences(this.context, 'mystore')
promise.then((preferences) => {
    console.info("Got preferences successfully.")
}).catch((err) => {
    console.info("Failed to get the preferences")
})
```


## data_preferences.deletePreferences

deletePreferences(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a **Preferences** singleton instance, the persistence file and backup file, and corrupted files from the memory.
Once a **Preferences** persistence file is deleted, the **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | Yes| Context of the application or function.|
  | name | string | Yes| Name of the **Preferences** instance persistence file.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**
```ts
data_preferences.deletePreferences(this.context, 'mystore', function (err) {
    if (err) {
              console.info("Failed to delete data, err: " + err)
        return
    }
    console.info("Deleted preferences successfully.")
})
```


## data_preferences.deletePreferences

deletePreferences(context: Context, name: string): Promise&lt;void&gt;

Deletes a **Preferences** singleton instance, the persistence file and backup file, and corrupted files from the memory.
Once a **Preferences** persistence file is deleted, the **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | Yes| Context of the application or function.|
  | name | string | Yes| Name of the **Preferences** instance persistence file.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```ts
let promise = data_preferences.deletePreferences(this.context, 'mystore')
promise.then(() => {
    console.info("Deleted preferences successfully.")
}).catch((err) => {
          console.info("Failed to delete preferences, err: " + err)
})
```


## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Removes a **Preferences** singleton instance from the memory.

When a **Preferences** singleton instance is removed, this instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | Yes| Context of the application or function.|
  | name | string | Yes| Name of the **Preferences** instance persistence file.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**
```ts
data_preferences.removePreferencesFromCache(this.context, 'mystore', function (err) {
    if (err) {
        console.info("Failed to remove preferences from cache, err: " + err)
        return
    }
    console.info("Removed preferences from cache successfully.")
})
```


## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string): Promise&lt;void&gt;

Removes a **Preferences** singleton instance from the memory.

When a **Preferences** singleton instance is removed, this instance cannot be used for data operations. Otherwise, data inconsistency will occur. This API uses a promise to return the execution result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | [Context](js-apis-ability-context.md) | Yes| Context of the application or function.|
  | name | string | Yes| Name of the **Preferences** instance persistence file.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```ts
let promise = data_preferences.removePreferencesFromCache(this.context, 'mystore')
promise.then(() => {
    console.info("Removed preferences from cache successfully.")
}).catch((err) => {
    console.info("Failed to remove preferences from cache, err: " + err)
})
```


## Preferences

Provides APIs for obtaining and modifying storage data.


### get

get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void

Obtains the value of a key. If the value is null or a non-default value, the default data is returned. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the data to obtain. It cannot be empty.|
| defValue | [ValueType](#valuetype) | Yes| Default value to be returned. It can be a number, string, or Boolean value.
| callback | AsyncCallback&lt;ValueType&gt; | Yes| Callback used to return the result.|

**Example**
```ts
preferences.get('startup', 'default', function(err, value) {
    if (err) {
                  console.info("Failed to get the value of startup, err: " + err)
        return
    }
              console.info("The value of startup is " + value)
})
```


### get

get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;

Obtains the value of a key. If the value is null or a non-default value, the default data is returned. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data to obtain. It cannot be empty.|
  | defValue | [ValueType](#valuetype) | Yes| Default value to be returned. It can be a number, string, or Boolean value.

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;ValueType&gt; | Promise used to return the result.|

**Example**
```ts
let promise = preferences.get('startup', 'default')
promise.then((value) => {
    console.info("The value of startup is " + value)
}).catch((err) => {
              console.info("Failed to get the value of startup, err: " + err)
})
```

### getAll

getAll(callback: AsyncCallback&lt;Object&gt;): void;

Obtains the **Object** instance that contains all KV pairs.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Object&gt; | Yes| Callback used to return the **Object** instance obtained.|

**Example**
```ts
preferences.getAll(function (err, value) {
    if (err) {
        console.info("getAll failed, err: " + err)
        return
    }
    let keys = Object.keys(value)
    console.info('getAll keys = ' + keys)
    console.info("getAll object = " + JSON.stringify(value))
});
```


### getAll

getAll(): Promise&lt;Object&gt;

Obtains the **Object** instance that contains all KV pairs.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Object&gt; | Promise used to return the **Object** instance obtained.|

**Example**
```ts
let promise = preferences.getAll()
promise.then((value) => {
    let keys = Object.keys(value)
    console.info('getAll keys = ' + keys)
    console.info("getAll object = " + JSON.stringify(value))
}).catch((err) => {
    console.info("getAll failed, err: " + err)
})
```

### put

put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void

Puts a new value to this **Preferences** instance and its persistence file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data. It cannot be empty.|
  | value | [ValueType](#valuetype) | Yes| New value to store. It can be a number, string, or Boolean value.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**
```ts
preferences.put('startup', 'auto', function (err) {
    if (err) {
                  console.info("Failed to put the value of startup, err: " + err)
        return
    }
    console.info("Put the value of startup successfully.")
})
```


### put

put(key: string, value: ValueType): Promise&lt;void&gt;

Puts a new value to this **Preferences** instance and its persistence file. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data. It cannot be empty.|
  | value | [ValueType](#valuetype) | Yes| New value to store. It can be a number, string, or Boolean value.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```ts
let promise = preferences.put('startup', 'auto')
promise.then(() => {
    console.info("Put the value of startup successfully.")
}).catch((err) => {
              console.info("Failed to put the value of startup, err: " + err)
})
```


### has

has(key: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this **Preferences** instance contains data with a given key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data to check. It cannot be empty.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. It returns **true** if the **Preferences** instance contains data with the given key and returns **false** otherwise.|

**Example**
```ts
preferences.has('startup', function (err, isExist) {
    if (err) {
        console.info("Failed to check the key of startup, err: " + err)
        return
    }
    if (isExist) {
        console.info("The key of startup is contained.")
    } else {
        console.info("The key of startup is not contained.")
    }
})
```


### has

has(key: string): Promise&lt;boolean&gt;

Checks whether this **Preferences** instance contains data with a given key. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data to check. It cannot be empty.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the result. It returns **true** if the **Preferences** instance contains data with the given key and returns **false** otherwise.|

**Example**
```ts
let promise = preferences.has('startup')
promise.then((isExist) => {
    if (isExist) {
        console.info("The key of startup is contained.")
    } else {
        console.info("The key of startup is not contained.")
    }
}).catch((err) => {
    console.info("Failed to check the key of startup, err: " + err)
})
```


### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a KV pair of the specified key from this **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the KV pair to delete. It cannot be empty.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**
```ts
preferences.delete('startup', function (err) {
    if (err) {
        console.info("Failed to delete startup key, err: " + err)
        return
    }
    console.info("Deleted startup key successfully.")
})
```


### delete

delete(key: string): Promise&lt;void&gt;

Deletes a KV pair of the specified key from this **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the KV pair to delete. It cannot be empty.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```ts
let promise = preferences.delete('startup')
promise.then(() => {
    console.info("Deleted startup key successfully.")
}).catch((err) => {
    console.info("Failed to delete startup key, err: " + err)
})
```


### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Saves the modification to this **Preferences** instance and synchronizes the modification to the **Preferences** persistence file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**
```ts
preferences.flush(function (err) {
    if (err) {
        console.info("Failed to flush data to file, err: " + err)
        return
    }
    console.info("Flushed data to file successfully.")
})
```


### flush

flush(): Promise&lt;void&gt;

Saves the modification to this **Preferences** instance and synchronizes the modification to the **Preferences** persistence file. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```ts
let promise = preferences.flush()
promise.then(() => {
    console.info("Flushed data to file successfully.")
}).catch((err) => {
    console.info("Failed to flush data to file, err: " + err)
})
```


### clear

clear(callback: AsyncCallback&lt;void&gt;): void

Clears data of this **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**
```ts
preferences.clear(function (err) {
    if (err) {
        console.info("Failed to clear data, err: " + err)
        return
    }
    console.info("Cleared to file successfully.")
})
```


### clear

clear(): Promise&lt;void&gt;

Clears data of this **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```ts
let promise = preferences.clear()
promise.then(() => {
    console.info("Cleared to file successfully.")
}).catch((err) => {
    console.info("Failed to clear data, err: " + err)
})
```


### on('change')

on(type: 'change', callback: Callback&lt;{ key : string }&gt;): void

Subscribes to data changes. When the value of the subscribed key changes, a callback will be invoked after **flush()** is executed.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes|  Event type. The value **change** indicates data change events.|
  | callback | Callback&lt;{ key : string }&gt;  | Yes| Callback used to return data changes.|

**Example**
```ts
data_preferences.getPreferences(this.context, 'mystore', function (err, preferences) {
    if (err) {
        console.info("Failed to get preferences.")
        return;
    }
    var observer = function (key) {
        console.info("The key of " + key + " changed.")
    }
    preferences.on('change', observer)
    preferences.put('startup', 'auto', function (err) {
        if (err) {
            console.info("Failed to put the value of startup, err: " + err)
            return
        }
        console.info("Put the value of startup successfully.")

        preferences.flush(function (err) {
            if (err) {
                console.info("Failed to flush data to file, err: " + err)
                return
            }
            console.info("Flushed data to file successfully.") // The observer will be called.
        })
    })
})
```


### off('change')

off(type: 'change', callback?: Callback&lt;{ key : string }&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **change** indicates data change events.|
  | callback | Callback&lt;{ key : string }&gt;  | No| Callback used to return data changes. If this parameter is left empty, all callbacks for data changes will be canceled.|

**Example**
```ts
data_preferences.getPreferences(this.context, 'mystore', function (err, preferences) {
    if (err) {
        console.info("Failed to get preferences.")
        return;
    }
    var observer = function (key) {
        console.info("The key of " + key + " changed.")
    }
    preferences.on('change', observer)
    preferences.put('startup', 'auto', function (err) {
        if (err) {
            console.info("Failed to put the value of startup, err: " + err)
            return
        }
        console.info("Put the value of startup successfully.")

        preferences.flush(function (err) {
            if (err) {
                console.info("Failed to flush data to file, err: " + err)
                return
            }
            console.info("Flushed data to file successfully.") // The observer will be called.
        })
        preferences.off('change', observer)
    })
})
```

## ValueType

Enumerates the value types.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name          | Description                          |
| -------------- | ------------------------------ |
| number         | The value is a number.            |
| string         | The value is a string.          |
| boolean        | The value is of Boolean type.          |

