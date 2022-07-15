# Preferences Development

> **NOTE**
>
> This feature is supported since API Version 9. For the versions earlier than API Version 9, use [Lightweight Storage](../reference/apis/js-apis-data-storage.md) APIs.

## When to Use

Preferences are ideal for storing data frequently used by applications, but not for storing a large amount of data or data with frequent changes. The application data is persistently stored on a device in the form of files. Note that the instance accessed by an application contains all data of the file. The data is always loaded to the memory of the device until the application removes it from the memory. The application can perform data operations using the **Preferences** APIs.

## Available APIs

Preferences provide capabilities for processing data in the form of key-value (KV) pairs and support data persistence, modification, and query. In KV pairs, keys are of the string type, and values can be of the number, string, or Boolean type. For more APIs related to preferences, see [Preferences](../reference/apis/js-apis-data-preferences.md).

### Creating a Preferences Instance

Create a **Preferences** instance for data operations. A **Preferences** instance is created after data is read from a specified file and loaded to the instance.

**Table 1** API for creating a **Preferences** instance

| Package             | API                                     | Description                                       |
| ----------------- | ------------------------------------------- | ------------------------------------------- |
| ohos.data.preferences | getPreferences(context: Context, name: string): Promise\<Preferences> | Obtains a **Preferences** instance for data operations.|

### Writing Data

Call the **put()** method to add or modify data in a **Preferences** instance.

**Table 2** API for writing data

| Class   | API                                            | Description                                           |
| ------- | -------------------------------------------------- | ----------------------------------------------- |
| Preferences | put(key: string, value: ValueType): Promise\<void> | Writes data with the value type of number, string, boolean, Array\<number>, Array\<string>, or Array\<boolean>.|

### Reading Data

Call the **get()** method to read data from a **Preferences** instance.

**Table 3** API for reading data

| Class   | API                                                    | Description                                           |
| ------- | ---------------------------------------------------------- | ----------------------------------------------- |
| Preferences | get(key: string, defValue: ValueType): Promise\<ValueType> | Obtains data with the value type of number, string, boolean, Array\<number>, Array\<string>, or Array\<boolean>.|

### Storing Data Persistently

Call the **flush()** method to write the cached data back to its text file for persistent storage.

**Table 4** API for data persistence

| Class   | API                 | Description                                   |
| ------- | ----------------------- | --------------------------------------- |
| Preferences | flush(): Promise\<void> | Writes data from the **Preferences** instance back to its file through an asynchronous thread.|

### Observing Data Changes

You can subscribe to data changes. When the value of the subscribed key is changed by **flush()**, a callback will be invoked to return the new data.

**Table 5** APIs for observing **Preferences** changes

| Class   | API                                                      | Description          |
| ------- | ------------------------------------------------------------ | -------------- |
| Preferences | on(type: 'change', callback: Callback<{ key : string }>): void | Subscribes to data changes.|
| Preferences | off(type: 'change', callback: Callback<{ key : string }>): void | Unsubscribes from data changes.    |

### Deleting Data

Use the following APIs to delete a **Preferences** instance or data file.

**Table 6** APIs for deleting **Preferences**

| Package             | API                                              | Description                                                        |
| ----------------- | ---------------------------------------------------- | ------------------------------------------------------------ |
| ohos.data.preferences | deletePreferences(context: Context, name: string): Promise\<void>;     | Deletes a **Preferences** instance from the cache and deletes its file from the device.|
| ohos.data.preferences | removePreferencesFromCache(context: Context, name: string): Promise\<void>; | Removes a **Preferences** instance from the memory to release memory.

## How to Develop

1. Import @ohos.data.preferences and related modules to the development environment.

   ```js
   import data_preferences from '@ohos.data.preferences'
   ```

2. Create a **Preferences** instance.

   Read the specified file and load its data to the **Preferences** instance for data operations.
   ```js
   let promise = data_preferences.getPreferences(this.context, 'mystore')
   ```

3. Write data.

   Use the **put()** method of the **Preferences** class to write data to the cached **Preferences** instance.

   ```js
   promise.then((preferences) => {
       let putPromise = preferences.put('startup', 'auto')
       putPromise.then(() => {
           console.info("Put the value of startup successfully.")
       }).catch((err) => {
           console.info("Failed to put the value of startup with err: " + err)
       })
   }).catch((err) => {
       console.info("Failed to get the preferences")
   })
   ```

4. Read data.

   Use the **get()** method of the **Preferences** class to read data.

   ```js
   promise.then((preferences) => {
       let getPromise = preferences.get('startup', 'default')
       getPromise.then((value) => {
           console.info("The value of startup is " + value)
       }).catch((err) => {
           console.info("Failed to get the value of startup with err: " + err)
       })
   }).catch((err) => {
       console.info("Failed to get the preferences")})
   ```

5. Store data persistently.

   Use the **flush()** method to flush data from the **Preferences** instance to its file.

   ```js
   preferences.flush();
   ```

6. Observe data changes.

   Specify an observer as the callback to subscribe to data changes for an application. When the value of the subscribed key is changed and the **flush()** method is executed, the observe callback will be invoked to return the change.

   ```js
    var observer = function (key) {
        console.info("The key of " + key + " changed.")
    }
    preferences.on('change', observer)
    preferences.put('startup', 'auto', function (err) {
        if (err) {
            console.info("Failed to put the value of startup with err: " + err)
            return
        }
        console.info("Put the value of startup successfully.")
        preferences.flush(function (err) {
            if (err) {
                console.info("Failed to flush data to file with err: " + err)
                return
            }
            console.info("Flushed to file successfully.")    // Observer will be called.
        })
    })
   ```

7. Delete the specified file.

   Use the **deletePreferences** method to delete the **Preferences** singleton of the specified file from the memory, and delete the specified file, its backup file, and corrupted files. After the specified files are deleted, the application cannot use that instance to perform any data operation. Otherwise, data inconsistency will occur. The deleted data and files cannot be restored.

   ```js
    let proDelete = data_preferences.deletePreferences(context, 'mystore')
    proDelete.then(() => {
        console.info("Data deleted successfully.")
    }).catch((err) => {
        console.info("Failed to delete data with err: " + err)
    })
   ```
