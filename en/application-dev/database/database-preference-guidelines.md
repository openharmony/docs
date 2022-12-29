# Preferences Development

> **NOTE**
>
> This feature is supported since API version 9. For the versions earlier than API version 9, use [Lightweight Storage](../reference/apis/js-apis-data-storage.md) APIs.

## When to Use

Preferences are used for storing the data that is frequently used by applications, but not for storing a large amount of data or data frequently changed. The application data is persistently stored on a device in the form of files.

Note that the instance accessed by an application contains all data of the file. The data is always loaded to the memory of the device until the application removes it from the memory. The application can call the **Preferences** APIs to manage data.

## Available APIs

The **Preferences** module provides APIs for processing data in the form of key-value (KV) pairs and supports persistence of the KV pairs when required.

The key is of the string type, and the value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.

For details about **Preferences** APIs, see [Preferences](../reference/apis/js-apis-data-preferences.md).

### Obtaining a **Preferences** Instance

Obtain a **Preferences** instance for data operations. A **Preferences** instance is obtained after data is read from a specified file and loaded to the instance.

**Table 1** API for obtaining a **Preferences** instance

| Package                 | API                                                      | Description                                                        |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.data.preferences | getPreferences(context: Context, name: string): Promise\<Preferences> | Obtains a **Preferences** instance.|

### Processing Data

Call **put()** to add or modify data in a **Preferences** instance.

Call **get()** to read data from a **Preferences** instance.

Call **getAll()** to obtain an **Object** instance that contains all KV pairs in a **Preferences** instance.

Call **delete()** to delete the KV pair of the specified key from the **Preferences** instance.

**Table 2** APIs for processing **Preferences** data

| Class       | API                                                    | Description                                                        |
| ----------- | ---------------------------------------------------------- | ------------------------------------------------------------ |
| Preferences | put(key: string, value: ValueType): Promise\<void>         | Writes data to the **Preferences** instance. The value to write can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|
| Preferences | get(key: string, defValue: ValueType): Promise\<ValueType> | Obtains data from the **Preferences** instance. The value to read can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|
| Preferences | getAll(): Promise\<Object>                                  | Obtains an **Object** instance that contains all KV pairs in the **Preferences** instance.                          |
| Preferences | delete(key: string): Promise\<void>                         | Deletes the KV pair of the specified key from the **Preferences** instance.        |


### Storing Data Persistently

Call **flush()** to write the cached data back to its text file for persistent storage.

**Table 4** API for data persistence

| Class       | API                 | Description                                       |
| ----------- | ----------------------- | ------------------------------------------- |
| Preferences | flush(): Promise\<void> | Flushes data from the **Preferences** instance to its file through an asynchronous thread.|

### Observing Data Changes

You can subscribe to data changes. When the value of the subscribed key is changed and saved by **flush()**, a callback will be invoked to return the new data.

**Table 5** APIs for observing **Preferences** changes

| Class       | API                                                      | Description          |
| ----------- | ------------------------------------------------------------ | -------------- |
| Preferences | on(type: 'change', callback: Callback<{ key : string }>): void | Subscribes to data changes.|
| Preferences | off(type: 'change', callback: Callback<{ key : string }>): void | Unsubscribes from data changes.    |

### Deleting Data

You can use the following APIs to delete a **Preferences** instance or data file.

**Table 6** APIs for deleting **Preferences**

| Package                 | API                                                      | Description                                                        |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.data.preferences | deletePreferences(context: Context, name: string): Promise\<void> | Deletes a **Preferences** instance from the memory and its files from the device.|
| ohos.data.preferences | removePreferencesFromCache(context: Context, name: string): Promise\<void> | Removes a **Preferences** instance from the memory to release memory.   |

## How to Develop

1. Import @ohos.data.preferences and related modules to the development environment.

   ```js
   import data_preferences from '@ohos.data.preferences';
   ```

2. Obtain a **Preferences** instance.

   Read the specified file and load its data to the **Preferences** instance for data operations.

   FA model:

   ```js
   // Obtain the context.
   import featureAbility from '@ohos.ability.featureAbility'
   let context = featureAbility.getContext();
   
   let preferences = null;
   let promise = data_preferences.getPreferences(context, 'mystore');
   
   promise.then((pref) => {
       preferences = pref;
   }).catch((err) => {
       console.info("Failed to get the preferences.");
   })
   ```

   Stage model:

   ```ts
   // Obtain the context.
   import Ability from '@ohos.application.Ability'
   let context = null;
   let preferences = null;
   export default class MainAbility extends Ability {
       onWindowStageCreate(windowStage){
           context = this.context;
       }
   }
   
   let promise = data_preferences.getPreferences(context, 'mystore');
   
   promise.then((pref) => {
       preferences = pref;
   }).catch((err) => {
       console.info("Failed to get the preferences.");
   })
   ```

3. Write data.

   Use **preferences.put()** to write data to the **Preferences** instance.

   ```js
   let putPromise = preferences.put('startup', 'auto');
   putPromise.then(() => {
       console.info("Put the value of 'startup' successfully.");
   }).catch((err) => {
       console.info("Failed to put the value of 'startup'. Cause: " + err);
   })
   ```
   
4. Read data.

   Use **preferences.get()** to read data.

   ```js
   let getPromise = preferences.get('startup', 'default');
   getPromise.then((value) => {
       console.info("The value of 'startup' is " + value);
   }).catch((err) => {
       console.info("Failed to get the value of 'startup'. Cause: " + err);
   })
   ```
   
5. Store data persistently.

   Use **flush()** to flush data from the **Preferences** instance to its file.

   ```js
   preferences.flush();
   ```

6. Observe data changes.

   Specify an observer as the callback to subscribe to data changes for an application. When the value of the subscribed key is changed and saved by **flush()**, the observer callback will be invoked to return the new data.

   ```js
   let observer = function (key) {
       console.info("The key" + key + " changed.");
   }
   preferences.on('change', observer);
   // The data is changed from 'auto' to 'manual'.
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
   ```

7. Delete the specified file.

   Use **deletePreferences()** to delete the **Preferences** instance and its persistent file and backup and corrupted files. After the specified files are deleted, the application cannot use that instance to perform any data operation. Otherwise, data inconsistency will be caused. The deleted data and files cannot be restored.

   ```js
   let proDelete = data_preferences.deletePreferences(context, 'mystore');
   proDelete.then(() => {
        console.info("Deleted data successfully.");
   }).catch((err) => {
        console.info("Failed to delete data. Cause: " + err);
   })
   ```
