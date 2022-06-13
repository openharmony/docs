# Lightweight Data Store Development

## When to Use

The lightweight data store is ideal for storing lightweight and frequently used data, but not for storing a large amount of data or data with frequent changes. The application data is persistently stored on a device in the form of files. Note that the instance accessed by an application contains all data of the file. The data is always loaded to the memory of the device until the application removes it from the memory. The application can perform data operations using the  **Storage**  APIs.

## Available APIs

The lightweight data store provides applications with data processing capability and allows applications to perform lightweight data storage and query. Data is stored in key-value pairs. Keys are of the string type, and values can be of the number, string, or Boolean type.

**Creating a Storage Instance**

Create a  **Storage**  instance for data operations. A  **Storage**  instance is created after data is read from a specified file and loaded to the instance.

**Table  1**  API for creating a  **Storage**  instance

| Package Name      | Method                                      | Description                                                  |
| ----------------- | ------------------------------------------- | ------------------------------------------------------------ |
| ohos.data.storage | getStorage(path: string): Promise\<Storage> | Obtains the **Storage** singleton corresponding to a file for data operations. |

**Writing Data**

Call the  **put\(\)**  method to add or modify data in a  **Storage**  instance.

**Table  2**  API for writing data

| Class   | Method                                             | Description                                           |
| ------- | -------------------------------------------------- | ----------------------------------------------------- |
| Storage | put(key: string, value: ValueType): Promise\<void> | Writes data of the number, string, and Boolean types. |

**Reading Data**

Call the  **get\(\)**  method to read data from a  **Storage**  instance.

**Table  3**  API for reading data

| Class   | Method                                                     | Description                                          |
| ------- | ---------------------------------------------------------- | ---------------------------------------------------- |
| Storage | get(key: string, defValue: ValueType): Promise\<ValueType> | Reads data of the number, string, and Boolean types. |

**Storing Data Persistently**

Call the  **flush\(\)**  method to write the cached data back to its text file for persistent storage.

**Table  4**  API for data persistence

| Class   | Method                  | Description                                                  |
| ------- | ----------------------- | ------------------------------------------------------------ |
| Storage | flush(): Promise\<void> | Writes data in the **Storage** instance back to its file through an asynchronous thread. |

**Observing Data Changes**

Specify  **StorageObserver**  as the callback to subscribe to data changes. When the value of the subscribed key is changed and the  **flush\(\)**  method is executed,  **StorageObserver**  will be invoked.

**Table  5**  APIs for subscribing to data changes

| Class   | Method                                                       | Description                     |
| ------- | ------------------------------------------------------------ | ------------------------------- |
| Storage | on(type: 'change', callback: Callback\<StorageObserver>): void | Subscribes to data changes.     |
| Storage | off(type: 'change', callback: Callback\<StorageObserver>): void | Unsubscribes from data changes. |

**Deleting Data**

Use the following APIs to delete a  **Storage**  instance or data file.

**Table  6**  APIs for deleting data

| Package Name      | Method                                               | Description                                                  |
| ----------------- | ---------------------------------------------------- | ------------------------------------------------------------ |
| ohos.data.storage | deleteStorage(path: string): Promise\<void>          | Deletes a **Storage** instance from the cache and deletes its file from the device. |
| ohos.data.storage | removeStorageFromCache(path: string): Promise\<void> | Deletes a **Storage** instance from the cache to release memory. |


## How to Develop

1.  Import  **@ohos.data.storage**  and related modules to the development environment.

    ```js
    import dataStorage from '@ohos.data.storage'
    import featureAbility from '@ohos.ability.featureAbility'  // Used to obtain the file storage path.
    ```

2.  Create a  **Storage**  instance.

    Read the specified file and load its data to the  **Storage**  instance for data operations.

    ```js
    var context = featureAbility.getContext()
    var path = await context.getFilesDir()
    let promise = dataStorage.getStorage(path + '/mystore')
    ```


3.  Write data.

    Use the  **put\(\)**  method of the  **Storage**  class to write data to the cached  **Storage**  instance.

    ```js
    promise.then((storage) => {
        let getPromise = storage.put('startup', 'auto') // Save data to the Storage instance.
        getPromise.then(() => {
            console.info("Put the value of startup successfully.")
        }).catch((err) => {
            console.info("Put the value of startup failed with err: " + err)
        })
    }).catch((err) => {
        console.info("Get the storage failed")
    })
    ```


4.  Read data.

    Use the  **get\(\)**  method of the  **Storage**  class to read data.

    ```js
    promise.then((storage) => {
        let getPromise = storage.get('startup', 'default')
        getPromise.then((value) => {
            console.info("The value of startup is " + value)
        }).catch((err) => {
            console.info("Get the value of startup failed with err: " + err)
        })
    }).catch((err) => {
        console.info("Get the storage failed")
    })
    ```


5.  Store data persistently.

    Use the  **flush**  or  **flushSync**  method to flush data in the  **Storage**  instance to its file.

    ```js
    storage.flush();
    ```

6.  Observe data changes.

    Specify  **StorageObserver**  as the callback to subscribe to data changes for an application. When the value of the subscribed key is changed and the  **flush\(\)**  method is executed,  **StorageObserver**  will be invoked. Unregister the  **StorageObserver**  when it is no longer required.

    ```js
    promise.then((storage) => {
        var observer = function (key) {
            console.info("The key of " + key + " changed.")
        }
        storage.on('change', observer)
        storage.putSync('startup', 'auto') // Modify data in the Storage instance.
        storage.flushSync() // Trigger the StorageObserver callback.
    
        storage.off(...change..., observer) // Unsubscribe from the data changes.
    }).catch((err) => {
        console.info("Get the storage failed")
    })
    ```


7.  Delete the specified file.

    Use the  **deleteStorage**  method to delete the  **Storage**  singleton of the specified file from the memory, and delete the specified file, its backup file, and damaged files. After the specified files are deleted, the application cannot use that instance to perform any data operation. Otherwise, data inconsistency will occur. The deleted data and files cannot be restored.

    ```js
    let promise = dataStorage.deleteStorage(path + '/mystore')
    promise.then(() => {
        console.info("Deleted successfully.")
    }).catch((err) => {
        console.info("Deleted failed with err: " + err)
    })
    ```

