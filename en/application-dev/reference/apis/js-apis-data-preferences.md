# Preferences

The **Preferences** module provides APIs for processing data in the form of key-value (KV) pairs and supports persistence of the KV pairs when required.

The key is of the string type, and the value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.


> **NOTE**<br/>
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import data_preferences from '@ohos.data.preferences';
```

## Constants

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name            | Type| Readable| Writable| Description                                   |
| ---------------- | -------- | ---- | ---- | --------------------------------------- |
| MAX_KEY_LENGTH   | string   | Yes  | No  | Maximum length of a key. The key must be less than 80 bytes.    |
| MAX_VALUE_LENGTH | string   | Yes  | No  | Maximum length of a value. The value must be less than 8192 bytes.|


## data_preferences.getPreferences

getPreferences(context: Context, name: string, callback: AsyncCallback&lt;Preferences&gt;): void

Obtains a **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                                                        |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| context  | Context            | Yes  | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).                                                |
| name     | string                                           | Yes  | Name of the **Preferences** instance.|
| callback | AsyncCallback&lt;[Preferences](#preferences)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **object** is the **Preferences** instance obtained. Otherwise, **err** is an error code.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

let preferences = null;
data_preferences.getPreferences(context, 'mystore', function (err, object) {
    if (err) {
        console.info("Failed to get the preferences. Cause: " + err);
        return;
    }
    preferences = object;
    console.info("Got the preferences successfully.");
})
```

Stage model:

```ts
// Obtain the context.
import Ability from '@ohos.application.Ability';
let context = null;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context;
    }
}

let preferences = null;
data_preferences.getPreferences(context, 'mystore', function (err, object) {
    if (err) {
        console.info("Failed to get the preferences. Cause: " + err);
        return;
    }
    preferences = object;
    console.info("Got the preferences successfully.");
})
```

## data_preferences.getPreferences

getPreferences(context: Context, name: string): Promise&lt;Preferences&gt;

Obtains a **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                                 | Mandatory| Description                   |
| ------- | ------------------------------------- | ---- | ----------------------- |
| context | Context | Yes  | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).           |
| name    | string                                | Yes  | Name of the **Preferences** instance.|

**Return value**

| Type                                      | Description                              |
| ------------------------------------------ | ---------------------------------- |
| Promise&lt;[Preferences](#preferences)&gt; | Promise used to return the **Preferences** instance obtained.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

let preferences = null;
let promise = data_preferences.getPreferences(context, 'mystore');
promise.then((object) => {
    preferences = object;
    console.info("Got the preferences successfully.");
}).catch((err) => {
    console.info("Failed to get the preferences. Cause: " + err);
})
```

Stage model:

```ts
// Obtain the context.
import Ability from '@ohos.application.Ability';
let context = null;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context;
    }
}

let preferences = null;
let promise = data_preferences.getPreferences(context, 'mystore');
promise.then((object) => {
    preferences = object;
    console.info("Got the preferences successfully.");
}).catch((err) => {
    console.info("Failed to get the preferences. Cause: " + err);
})
```

## data_preferences.deletePreferences

deletePreferences(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a **Preferences** instance from the memory. This API uses an asynchronous callback to return the result.

If the **Preferences** instance has a persistent file, this API also deletes the persistent file.

The deleted **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will be caused.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                |
| -------- | ------------------------------------- | ---- | ---------------------------------------------------- |
| context  | Context | Yes  | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).                                        |
| name     | string                                | Yes  | Name of the **Preferences** instance to delete.                          |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error code.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

data_preferences.deletePreferences(context, 'mystore', function (err) {
    if (err) {
        console.info("Failed to delete the preferences. Cause: " + err);
        return;
    }
    console.info("Deleted the preferences successfully." );
})
```

Stage model:

```ts
// Obtain the context.
import Ability from '@ohos.application.Ability';
let context = null;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context;
    }
}

data_preferences.deletePreferences(context, 'mystore', function (err) {
    if (err) {
        console.info("Failed to delete the preferences. Cause: " + err);
        return;
    }
    console.info("Deleted the preferences successfully." );
})
```

## data_preferences.deletePreferences

deletePreferences(context: Context, name: string): Promise&lt;void&gt;

Deletes a **Preferences** instance from the memory. This API uses a promise to return the result.

If the **Preferences** instance has a persistent file, this API also deletes the persistent file.

The deleted **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will be caused.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                                 | Mandatory| Description                   |
| ------- | ------------------------------------- | ---- | ----------------------- |
| context | Context | Yes  | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).           |
| name    | string                                | Yes  | Name of the **Preferences** instance to delete.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

let promise = data_preferences.deletePreferences(context, 'mystore');
promise.then(() => {
    console.info("Deleted the preferences successfully.");
}).catch((err) => {
    console.info("Failed to delete the preferences. Cause: " + err);
})
```

Stage model:

```ts
// Obtain the context.
import Ability from '@ohos.application.Ability';
let context = null;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context;
    }
}

let promise = data_preferences.deletePreferences(context, 'mystore');
promise.then(() => {
    console.info("Deleted the preferences successfully.");
}).catch((err) => {
    console.info("Failed to delete the preferences. Cause: " + err);
})
```

## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Removes a **Preferences** instance from the memory. This API uses an asynchronous callback to return the result.

The removed **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will be caused.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                |
| -------- | ------------------------------------- | ---- | ---------------------------------------------------- |
| context  | Context | Yes  | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).                                        |
| name     | string                                | Yes  | Name of the **Preferences** instance to remove.                          |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error code.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

data_preferences.removePreferencesFromCache(context, 'mystore', function (err) {
    if (err) {
        console.info("Failed to remove the preferences. Cause: " + err);
        return;
    }
    console.info("Removed the preferences successfully.");
})
```

Stage model:

```ts
// Obtain the context.
import Ability from '@ohos.application.Ability';
let context = null;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context;
    }
}

data_preferences.removePreferencesFromCache(context, 'mystore', function (err) {
    if (err) {
        console.info("Failed to remove the preferences. Cause: " + err);
        return;
    }
    console.info("Removed the preferences successfully.");
})
```

## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string): Promise&lt;void&gt;

Removes a **Preferences** instance from the memory. This API uses a promise to return the result.

The removed **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will be caused.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                                 | Mandatory| Description                   |
| ------- | ------------------------------------- | ---- | ----------------------- |
| context | Context | Yes  | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).           |
| name    | string                                | Yes  | Name of the **Preferences** instance to remove.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

let promise = data_preferences.removePreferencesFromCache(context, 'mystore');
promise.then(() => {
    console.info("Removed the preferences successfully.");
}).catch((err) => {
    console.info("Failed to remove the preferences. Cause: " + err);
})
```

Stage model:

```ts
// Obtain the context.
import Ability from '@ohos.application.Ability';
let context = null;
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context;
    }
}

let promise = data_preferences.removePreferencesFromCache(context, 'mystore');
promise.then(() => {
    console.info("Removed the preferences successfully.");
}).catch((err) => {
    console.info("Failed to remove the preferences. Cause: " + err);
})
```

## Preferences

Provides methods for obtaining and modifying data.

Before calling any method of **Preferences**, you must obtain a **Preferences** instance by using [data_preferences.getPreferences](#data_preferencesgetpreferences).


### get

get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void

Obtains the value of a key. This API uses an asynchronous callback to return the result. If the value is **null** or is not the type of the default value, the default value is returned.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                                       | Yes  | Key of the data to obtain. It cannot be empty.                             |
| defValue | [ValueType](#valuetype)                      | Yes  | Default value to be returned. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|
| callback | AsyncCallback&lt;[ValueType](#valuetype)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is** undefined** and **data** is the value obtained. Otherwise, **err** is an error code.|

**Example**

```js
preferences.get('startup', 'default', function(err, data) {
    if (err) {
        console.info("Failed to get the value of 'startup'. Cause: " + err);
        return;
    }
    console.info("Got the value of 'startup'. Data: " + data);
})
```


### get

get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;

Obtains the value of a key. This API uses a promise to return the result. If the value is **null** or is not the type of the default value, the default value is returned.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

 **Parameters**
 
| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| key      | string                  | Yes  | Key of the data to obtain. It cannot be empty.                             |
| defValue | [ValueType](#valuetype) | Yes  | Default value to be returned. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[ValueType](#valuetype)&gt; | Promise used to return the value obtained.|

**Example**

```js
let promise = preferences.get('startup', 'default');
promise.then((data) => {
    console.info("Got the value of 'startup'. Data: " + data);
}).catch((err) => {
    console.info("Failed to get the value of 'startup'. Cause: " + err);
})
```

### getAll

getAll(callback: AsyncCallback&lt;Object&gt;): void;

Obtains an **Object** instance that contains all KV pairs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;Object&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **value** is the **Object** instance obtained. Otherwise, **err** is an error code.|

**Example**

```js
preferences.getAll(function (err, value) {
    if (err) {
        console.info("Failed to get all KV pairs. Cause: " + err);
        return;
    }
    let allKeys = Object.keys(value);
    console.info("getAll keys = " + allKeys);
    console.info("getAll object = " + JSON.stringify(value));
});
```


### getAll

getAll(): Promise&lt;Object&gt;

Obtains an **Object** instance that contains all KV pairs. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Promise&lt;Object&gt; | Promise used to return the **Object** instance obtained.|

**Example**

```js
let promise = preferences.getAll();
promise.then((value) => {
    let allKeys = Object.keys(value);
    console.info('getAll keys = ' + allKeys);
    console.info("getAll object = " + JSON.stringify(value));
}).catch((err) => {
    console.info("Failed to get all KV pairs. Cause: " + err);
})
```

### put

put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void

Writes data to this **Preferences** instance. This API uses an asynchronous callback to return the result. You can use [flush](#flush) to make the **Preferences** instance persistent.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                    | Yes  | Key of the data. It cannot be empty.                               |
| value    | [ValueType](#valuetype)   | Yes  | Value to write. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is undefined. Otherwise, **err** is an error code.    |

**Example**

```js
preferences.put('startup', 'auto', function (err) {
    if (err) {
        console.info("Failed to put the value of 'startup'. Cause: " + err);
        return;
    }
    console.info("Put the value of 'startup' successfully.");
})
```


### put

put(key: string, value: ValueType): Promise&lt;void&gt;

Writes data to this **Preferences** instance. This API uses a promise to return the result. You can use [flush](#flush) to make the **Preferences** instance persistent.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type                   | Mandatory| Description                                                        |
| ------ | ----------------------- | ---- | ------------------------------------------------------------ |
| key    | string                  | Yes  | Key of the data. It cannot be empty.                               |
| value  | [ValueType](#valuetype) | Yes  | Value to write. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = preferences.put('startup', 'auto');
promise.then(() => {
    console.info("Put the value of 'startup' successfully.");
}).catch((err) => {
    console.info("Failed to put the value of 'startup'. Cause: " + err);
})
```


### has

has(key: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this **Preferences** instance contains a KV pair with the given key. This API uses an asynchronous callback to return the result..

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                       | Yes  | Key of the data to check. It cannot be empty.                             |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. If the **Preferences** instance contains the KV pair, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

```js
preferences.has('startup', function (err, isExist) {
    if (err) {
        console.info("Failed to check the key 'startup'. Cause: " + err);
        return;
    }
    if (isExist) {
        console.info("The key 'startup' is contained.");
    } else {
        console.info("The key 'startup' is not contained.");
    }
})
```


### has

has(key: string): Promise&lt;boolean&gt;

Checks whether this **Preferences** instance contains a KV pair with the given key. This API uses a promise to return the result..

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the data to check. It cannot be empty.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. If the **Preferences** instance contains the KV pair, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

```js
let promise = preferences.has('startup');
promise.then((isExist) => {
    if (isExist) {
        console.info("The key 'startup' is contained.");
    } else {
        console.info("The key 'startup' is not contained.");
    }
}).catch((err) => {
    console.info("Failed to check the key 'startup'. Cause: " + err);
})
```


### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a KV pair from this **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                |
| -------- | ------------------------- | ---- | ---------------------------------------------------- |
| key      | string                    | Yes  | Key of the KV pair to delete. It cannot be empty.                     |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error code.|

**Example**

```js
preferences.delete('startup', function (err) {
    if (err) {
        console.info("Failed to delete the key 'startup'. Cause: " + err);
        return;
    }
    console.info("Deleted the key 'startup'.");
})
```


### delete

delete(key: string): Promise&lt;void&gt;

Deletes a KV pair from this **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the KV pair to delete. It cannot be empty.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = preferences.delete('startup');
promise.then(() => {
    console.info("Deleted the key 'startup'.");
}).catch((err) => {
    console.info("Failed to delete the key 'startup'. Cause: " + err);
})
```


### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Saves the data of this **Preferences** instance to a file asynchronously. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                |
| -------- | ------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error code.|

**Example**

```js
preferences.flush(function (err) {
    if (err) {
        console.info("Failed to flush data. Cause: " + err);
        return;
    }
    console.info("Flushed data successfully.");
})
```


### flush

flush(): Promise&lt;void&gt;

Saves the data of this **Preferences** instance to a file asynchronously. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = preferences.flush();
promise.then(() => {
    console.info("Flushed data to file successfully.")
}).catch((err) => {
    console.info("Failed to flush data. Cause: " + err);
})
```


### clear

clear(callback: AsyncCallback&lt;void&gt;): void

Clears this **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                |
| -------- | ------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error code.|

**Example**

```js
preferences.clear(function (err) {
    if (err) {
        console.info("Failed to clear data. Cause: " + err);
        return;
    }
    console.info("Cleared data successfully.");
})
```


### clear

clear(): Promise&lt;void&gt;

Clears this **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = preferences.clear()
promise.then(() => {
    console.info("Cleared data successfully.");
}).catch((err) => {
    console.info("Failed to clear data. Cause: " + err);
})
```


### on('change')

on(type: 'change', callback: Callback&lt;{ key : string }&gt;): void

Subscribes to data changes. A callback will be triggered to return the new value if the value of the subscribed key is changed and [flushed](#flush).

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                            | Mandatory| Description                                    |
| -------- | -------------------------------- | ---- | ---------------------------------------- |
| type     | string                           | Yes  | Event type to subscribe to. The value **change** indicates data change events.|
| callback | Callback&lt;{ key : string }&gt; | Yes  | Callback invoked to return data changes.                          |

**Example**

```js
data_preferences.getPreferences(this.context, 'mystore', function (err, preferences) {
    if (err) {
        console.info("Failed to get the preferences.");
        return;
    }
    let observer = function (key) {
        console.info("The key " + key + " changed.");
    }
    preferences.on('change', observer);
    preferences.put('startup', 'manual', function (err) {
        if (err) {
            console.info("Failed to put the value of 'startup'. Cause: " + err);
            return;
        }
        console.info("Put the value of 'startup' successfully.");

        preferences.flush(function (err) {
            if (err) {
                console.info("Failed to flush data. Cause: " + err);
                return;
            }
            console.info("Flushed data successfully."); // The observer will be called.
        })
    })
})
```


### off('change')

off(type: 'change', callback?: Callback&lt;{ key : string }&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                            | Mandatory| Description                                      |
| -------- | -------------------------------- | ---- | ------------------------------------------ |
| type     | string                           | Yes  | Event type to unsubscribe from. The value **change** indicates data change events.  |
| callback | Callback&lt;{ key : string }&gt; | No  | Callback to unregister. If this parameter is left blank, the callbacks used to subscribing to all data changes will be unregistered.|

**Example**

```js
data_preferences.getPreferences(this.context, 'mystore', function (err, preferences) {
    if (err) {
        console.info("Failed to get the preferences.");
        return;
    }
    let observer = function (key) {
        console.info("The key " + key + " changed.");
    }
    preferences.on('change', observer);
    preferences.put('startup', 'auto', function (err) {
        if (err) {
            console.info("Failed to put the value of 'startup'. Cause: " + err);
            return;
        }
        console.info("Put the value of 'startup' successfully.");

        preferences.flush(function (err) {
            if (err) {
                console.info("Failed to flush data. Cause: " + err);
                return;
            }
            console.info("Flushed data successfully."); // The observer will be called.
        })
        preferences.off('change', observer);
    })
})
```

## ValueType

Enumerates the value types.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Type           | Description                          |
| --------------- | ------------------------------ |
| number          | The value is a number.            |
| string          | The value is a string.          |
| boolean         | The value is of Boolean type.          |
| Array\<number>  | The value is an array of numbers.  |
| Array\<boolean> | The value is a Boolean array.  |
| Array\<string>  | The value is an array of the strings.|
