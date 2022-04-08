# Lightweight Storage

Lightweight storage provides applications with data processing capability and allows applications to perform lightweight data storage and query. Data is stored in key-value (KV) pairs. Keys are of the string type, and values can be of the number, string, or Boolean type.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import data_preferences from '@ohos.data.preferences'
```

## Attributes

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| MAX_KEY_LENGTH | string | Yes| No| Maximum length of a key. It is 80 bytes.|
| MAX_VALUE_LENGTH | string | Yes| No| Maximum length of a value of the string type. It is 8192 bytes.|


## data_preferences.getPreferences

getPreferences(context: Context, name: string, callback: AsyncCallback&lt;Preferences&gt;): void

Reads a file and loads the data to the **Preferences** instance. This method uses an asynchronous callback to return the execution result.


**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the app's internal data storage.|
  | callback | AsyncCallback&lt;[Preferences](#preferences)&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_preferences from '@ohos.data.preferences'
  var path = this.context.getDataBaseDir()
  data_preferences.getPreferences(this.context, 'mystore', function (err, preferences) {
      if (err) {
          console.info("Get the preferences failed, path: " + path + '/mystore')
          return;
      }
      preferences.put('startup', 'auto', function (err) {
          if (err) {
              console.info("Put the value of startup failed with err: " + err)
              return
          }
          console.info("Put the value of startup successfully.")
          preferences.flush(function (err) {
              if (err) {
                  console.info("Flush to file failed with err: " + err)
                  return
              }
              console.info("Flushed to file successfully.")
          })
      })
  })
  ```


## data_preferences.getPreferences

getPreferences(context: Context, name: string): Promise&lt;Preferences&gt;

Reads a file and loads the data to the **Preferences** instance. This method uses a promise to return the execution result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the app's internal data storage.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[Preferences](#preferences)&gt; | Promise used to return the result.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_preferences from '@ohos.data.preferences'
  var path = this.context.getDataBaseDir()
  let promisePre = data_preferences.getPreferences(this.context, 'mystore')
  promisePre.then((preferences) => {
      preferences.put('startup', 'auto', function (err) {
          if (err) {
              console.info("Put the value of startup failed with err: " + err)
              return
          }
          console.info("Put the value of startup successfully.")
          preferences.flush(function (err) {
              if (err) {
                  console.info("Flush to file failed with err: " + err)
                  return
              }
              console.info("Flushed to file successfully.")
          })
      })
  }).catch((err) => {
      console.info("Get the preferences failed, path: " + path + '/mystore')
  })
  ```


## data_preferences.deletePreferences

deletePreferences(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Removes the singleton **Preferences** instance of the specified file from the memory, and deletes the specified file, its backup file, and corrupted files. After the specified files are deleted, the **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will occur. This method uses an asynchronous callback to return the execution result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the app's internal data storage.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_preferences from '@ohos.data.preferences'
  data_preferences.deletePreferences(this.context, 'mystore', function (err) {
      if (err) {
          console.info("Deleted failed with err: " + err)
          return
      }
      console.info("Deleted successfully.")
  })
  ```


## data_preferences.deletePreferences

deletePreferences(context: Context, name: string): Promise&lt;void&gt;

Removes the singleton **Preferences** instance of the specified file from the memory, and deletes the specified file, its backup file, and corrupted files. After the specified files are deleted, the **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will occur. This method uses a promise to return the execution result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the app's internal data storage.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_preferences from '@ohos.data.preferences'
  let promisedelPre = data_preferences.deletePreferences(this.context, 'mystore')
  promisedelPre.then(() => {
      console.info("Deleted successfully.")
  }).catch((err) => {
      console.info("Deleted failed with err: " + err)
  })
  ```


## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Removes the singleton **Preferences** instance of a file from the cache. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur.

This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the app's internal data storage.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_preferences from '@ohos.data.preferences'
  data_preferences.removePreferencesFromCache(this.context, 'mystore', function (err) {
      if (err) {
          console.info("Removed preferences from cache failed with err: " + err)
          return
      }
      console.info("Removed preferences from cache successfully.")
  })
  ```


## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string): Promise&lt;void&gt;

Removes the singleton **Preferences** instance of a file from the cache. The removed instance cannot be used for data operations. Otherwise, data inconsistency will occur.

This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | context | Context | Yes| Context of the app or functionality.|
  | name | string | Yes| Name of the app's internal data storage.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  import Ability from '@ohos.application.Ability'
  import data_preferences from '@ohos.data.preferences'
  let promiserevPre = data_preferences.removePreferencesFromCache(this.context, 'mystore')
  promiserevPre.then(() => {
      console.info("Removed preferences from cache successfully.")
  }).catch((err) => {
      console.info("Removed preferences from cache failed with err: " + err)
  })
  ```


## Preferences

Provides APIs for obtaining and modifying storage data.


### get

get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void

Obtains the value corresponding to a key. If the value is null or not in the default value format, the default value is returned.

This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data. It cannot be empty.|
  | defValue | ValueType | Yes| Default value to be returned. It can be a number, string, or Boolean value.|
  | callback | AsyncCallback&lt;ValueType&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  preferences.get('startup', 'default', function(err, value) {
      if (err) {
          console.info("Get the value of startup failed with err: " + err)
          return
      }
      console.info("The value of startup is " + value)
  })
  ```


### get

get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;

Obtains the value corresponding to a key. If the value is null or not in the default value format, the default value is returned.

This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data. It cannot be empty.|
  | defValue | ValueType | Yes| Default value to be returned. It can be a number, string, or Boolean value.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;ValueType&gt; | Promise used to return the result.|

- Example
  ```
  let promiseget = preferences.get('startup', 'default')
  promiseget.then((value) => {
      console.info("The value of startup is " + value)
  }).catch((err) => {
      console.info("Get the value of startup failed with err: " + err)
  })
  ```


### put

put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void

Obtains the **Preferences** instance corresponding to the specified file, writes data to the **Preferences** instance using a **Preferences** API, and saves data to the file using **flush()** or **flushSync()**.

This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data to modify. It cannot be empty.|
  | value | ValueType | Yes| New value to store. It can be a number, string, or Boolean value.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  preferences.put('startup', 'auto', function (err) {
      if (err) {
          console.info("Put the value of startup failed with err: " + err)
          return
      }
      console.info("Put the value of startup successfully.")
  })
  ```


### put

put(key: string, value: ValueType): Promise&lt;void&gt;

Obtains the **Preferences** instance corresponding to the specified file, writes data to the **Preferences** instance using a **Preferences** API, and saves data to the file using **flush()** or **flushSync()**.

This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data to modify. It cannot be empty.|
  | value | ValueType | Yes| New value to store. It can be a number, string, or Boolean value.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  let promiseput = preferences.put('startup', 'auto')
  promiseput.then(() => {
      console.info("Put the value of startup successfully.")
  }).catch((err) => {
      console.info("Put the value of startup failed with err: " + err)
  })
  ```


### has

has(key: string, callback: AsyncCallback&lt;boolean&gt;): boolean

Checks whether the **Preference** object contains data with a given key.

This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data. It cannot be empty.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the execution result.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the **Preference** object contains data with the specified key; returns **false** otherwise.|

- Example
  ```
  preferences.has('startup', function (err, isExist) {
      if (err) {
          console.info("Check the key of startup failed with err: " + err)
          return
      }
      if (isExist) {
          console.info("The key of startup is contained.")
      }
  })
  ```


### has

has(key: string): Promise&lt;boolean&gt;

Checks whether the **Preference** object contains data with a given key.

This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data. It cannot be empty.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the result.|

- Example
  ```
  let promisehas = preferences.has('startup')
  promisehas.then((isExist) => {
      if (isExist) {
          console.info("The key of startup is contained.")
      }
  }).catch((err) => {
      console.info("Check the key of startup failed with err: " + err)
  })
  ```


### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

Deletes data with the specified key from this **Preference** object.

This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data. It cannot be empty.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  preferences.delete('startup', function (err) {
      if (err) {
          console.info("Delete startup key failed with err: " + err)
          return
      }
      console.info("Deleted startup key successfully.")
  })
  ```


### delete

delete(key: string): Promise&lt;void&gt;

Deletes data with the specified key from this **Preference** object.

This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | key | string | Yes| Key of the data.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  let promisedel = preferences.delete('startup')
  promisedel.then(() => {
      console.info("Deleted startup key successfully.")
  }).catch((err) => {
      console.info("Delete startup key failed with err: " + err)
  })
  ```


### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Saves the modification of this object to the **Preferences** instance and synchronizes the modification to the file.

This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  preferences.flush(function (err) {
      if (err) {
          console.info("Flush to file failed with err: " + err)
          return
      }
      console.info("Flushed to file successfully.")
  })
  ```


### flush

flush(): Promise&lt;void&gt;

Saves the modification of this object to the **Preferences** instance and synchronizes the modification to the file.

This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  let promiseflush = preferences.flush()
  promiseflush.then(() => {
      console.info("Flushed to file successfully.")
  }).catch((err) => {
      console.info("Flush to file failed with err: " + err)
  })
  ```


### clear

clear(callback: AsyncCallback&lt;void&gt;): void

Clears this **Preferences** object.

This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  preferences.clear(function (err) {
      if (err) {
          console.info("Clear to file failed with err: " + err)
          return
      }
      console.info("Cleared to file successfully.")
  })
  ```


### clear

clear(): Promise&lt;void&gt;

Clears this **Preferences** object.

This method uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example
  ```
  let promiseclear = preferences.clear()
  promiseclear.then(() => {
      console.info("Cleared to file successfully.")
  }).catch((err) => {
      console.info("Clear to file failed with err: " + err)
  })
  ```


### on('change')

on(type: 'change', callback: Callback&lt;{ key : string }&gt;): void

Subscribes to data changes. When the value of the subscribed key changes, a callback will be invoked after the **flush()** method is executed.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Description|
  | -------- | -------- | -------- |
  | type | string | Event type. The value **change** indicates data change events.|
  | callback | Callback&lt;{ key : string }&gt; | Callback used to return data changes.|

- Example
  ```
  var observer = function (key) {
      console.info("The key of " + key + " changed.")
  }
  preferences.on('change', observer)
  preferences.put('startup', 'auto', function (err) {
      if (err) {
          console.info("Put the value of startup failed with err: " + err)
          return
      }
      console.info("Put the value of startup successfully.")
      preferences.flush(function (err) {
          if (err) {
              console.info("Flush to file failed with err: " + err)
              return
          }
          console.info("Flushed to file successfully.")    // observer will be called.
      })
  })  
  ```


### off('change')

off(type: 'change', callback: Callback&lt;{ key : string }&gt;): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

- Parameters
  | Name| Type| Description|
  | -------- | -------- | -------- |
  | type | string | Event type. The value **change** indicates data change events.|
  | callback | Callback&lt;{ key : string }&gt; | Callback used to return data changes.|

- Example
  ```
  var observer = function (key) {
      console.info("The key of " + key + " changed.")
  }
  preferences.off('change', observer)
  ```
