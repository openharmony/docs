# Persisting Preferences Data


## When to Use

The **Preferences** module provides APIs for processing data in the form of key-value (KV) pairs, and supports persistence of the KV pairs when required, as well as modification and query of the data. You can use **Preferences** when you want a unique storage for global data. **Preferences** caches data in the memory, which allows fast access when the data is required. **Preferences** is recommended for storing small amount of data, such as personalized settings (font size and whether to enable the night mode) of applications.


## Working Principles

User applications call **Preference** through the JS interface to read and write data files. You can load the data of a **Preferences** persistence file to a **Preferences** instance. Each file uniquely corresponds to an instance. The system stores the instance in memory through a static container until the instance is removed from the memory or the file is deleted. The following figure illustrates how **Preference** works.

The preference persistent file of an application is stored in the application sandbox. You can use **context** to obtain the file path. For details, see [Obtaining Application File Paths](../application-models/application-context-stage.md# obtaining-application-file-paths).

**Figure 1** Preferences working mechanism 

![preferences](figures/preferences.jpg)


## Constraints

- The key in a KV pair must be a string and cannot be empty or exceed 80 bytes.

- If the value is of the string type, it can be empty or a string not longer than 8192 bytes.

- The memory usage increases with the amount of **Preferences** data. The maximum number of data records recommended is 10,000. Otherwise, high memory overheads will be caused.


## Available APIs

The following table lists the APIs used for preferences data persistence. Most of the APIs are executed asynchronously in callback or promise mode. The following table uses the callback-based APIs as an example. For more information about the APIs, see [User Preferences](../reference/apis/js-apis-data-preferences.md).

| API| Description|
| -------- | -------- |
| getPreferences(context: Context, name: string, callback: AsyncCallback&lt;Preferences&gt;): void | Obtain a **Preferences** instance.|
| put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void | Writes data to the Preferences instance. You can use **flush()** to persist the **Preferences** instance data.|
| has(key: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether the **Preferences** instance contains a KV pair with the given key. The key cannot be empty.|
| get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void | Obtains the value of the specified key. If the value is null or not of the default value type, **defValue** is returned.|
| delete(key: string, callback: AsyncCallback&lt;void&gt;): void | Deletes the KV pair with the given key from the **Preferences** instance.|
| flush(callback: AsyncCallback&lt;void&gt;): void | Flushes the data of this **Preferences** instance to a file for data persistence.|
| on(type: 'change', callback: Callback&lt;{ key : string }&gt;): void | Subscribes to data changes of the specified key. When the value of the specified key is changed and saved by **flush()**, a callback will be invoked to return the new data.|
| off(type: 'change', callback?: Callback&lt;{ key : string }&gt;): void | Unsubscribes from data changes.|
| deletePreferences(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void | Deletes a **Preferences** instance from memory. If the **Preferences** instance has a persistent file, this API also deletes the persistent file.|


## How to Develop

1. Import the **@ohos.data.preferences** module.
   
   ```js
   import dataPreferences from '@ohos.data.preferences';
   ```

2. Obtain a **Preferences** instance. Read data from a file and load the data to a **Preferences** instance for data operations.

   Stage model:

   
   ```js
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage) {
       try {
         dataPreferences.getPreferences(this.context, 'mystore', (err, preferences) => {
           if (err) {
             console.error(`Failed to get preferences. Code:${err.code},message:${err.message}`);
             return;
           }
           console.info('Succeeded in getting preferences.');
           // Before performing related data operations, obtain a Preferences instance.
         })
       } catch (err) {
         console.error(`Failed to get preferences. Code:${err.code},message:${err.message}`);
       }
     }
   }
   ```

   FA model:

   
   ```js
   import featureAbility from '@ohos.ability.featureAbility';
   
   // Obtain the context.
   let context = featureAbility.getContext();
   
   try {
     dataPreferences.getPreferences(context, 'mystore', (err, preferences) => {
       if (err) {
         console.error(`Failed to get preferences. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in getting preferences.');
       // Before performing related data operations, obtain a Preferences instance.
     })
   } catch (err) {
     console.error(`Failed to get preferences. Code is ${err.code},message:${err.message}`);
   }
   ```

3. Write data.

   Use **put()** to write data to the **Preferences** instance. After data is written, you can use **flush()** to persist the **Preferences** instance data to a file if necessary.

   > **NOTE**
   >
   > If the specified key already exists, the **put()** method changes the value. To prevent a value from being changed by mistake, you can use **has()** to check whether the KV pair exists.

   Example:

   
   ```js
   try {
     preferences.has('startup', function (err, val) {
       if (err) {
         console.error(`Failed to check the key 'startup'. Code:${err.code}, message:${err.message}`);
         return;
       }
       if (val) {
         console.info("The key 'startup' is contained.");
       } else {
         console.info("The key 'startup' does not contain.");
         // Add a KV pair.
         try {
           preferences.put('startup', 'auto', (err) => {
             if (err) {
               console.error(`Failed to put data. Code:${err.code}, message:${err.message}`);
               return;
             }
             console.info('Succeeded in putting data.');
           })
         } catch (err) {
           console.error(`Failed to put data. Code: ${err.code},message:${err.message}`);
         }
       }
     })
   } catch (err) {
     console.error(`Failed to check the key 'startup'. Code:${err.code}, message:${err.message}`);
   }
   ```

4. Read data.

   Use **get()** to obtain the value of the specified key. If the value is null or is not of the default value type, the default data is returned.

   Example:

   ```js
   try {
     preferences.get('startup', 'default', (err, val) => {
       if (err) {
         console.error(`Failed to get value of 'startup'. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info(`Succeeded in getting value of 'startup'. val: ${val}.`);
     })
   } catch (err) {
     console.error(`Failed to get value of 'startup'. Code:${err.code}, message:${err.message}`);
   }
   ```

5. Delete data.

   Use delete() to delete a KV pair.<br>Example:

   
   ```js
   try {
     preferences.delete('startup', (err) => {
       if (err) {
         console.error(`Failed to delete the key 'startup'. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info("Succeeded in deleting the key 'startup'.");
     })
   } catch (err) {
     console.error(`Failed to delete the key 'startup'. Code:${err.code}, message:${err.message}`);
   }
   ```

6. Persist data.

   You can use **flush()** to persist the data held in a **Preferences** instance to a file.

   Example:

   ```js
   try {
     preferences.flush((err) => {
       if (err) {
         console.error(`Failed to flush. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info('Succeeded in flushing.');
     })
   } catch (err) {
     console.error(`Failed to flush. Code:${err.code}, message:${err.message}`);
   }
   ```

7. Subscribe to data changes.

   Specify an observer as the callback to return the data changes for an application. When the value of the subscribed key is changed and saved by **flush()**, the observer callback will be invoked to return the new data.

   Example:

   ```js
   let observer = function (key) {
     console.info('The key' + key + 'changed.');
   }
   preferences.on('change', observer);
   // The data is changed from 'auto' to 'manual'.
   preferences.put('startup', 'manual', (err) => {
     if (err) {
       console.error(`Failed to put the value of 'startup'. Code:${err.code},message:${err.message}`);
       return;
     }
     console.info("Succeeded in putting the value of 'startup'.");
     preferences.flush((err) => {
       if (err) {
         console.error(`Failed to flush. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info('Succeeded in flushing.');
     })
   })
   ```

8. Delete a **Preferences** instance from the memory.

   Use **deletePreferences()** to delete a **Preferences** instance from the memory. If the **Preferences** instance has a persistent file, the persistent file and its backup and corrupted files will also be deleted.

   > **NOTE**
   >
   > - The deleted **Preferences** instance cannot be used for data operations. Otherwise, data inconsistency will be caused.
   > 
   > - The deleted data and files cannot be restored.

   Example:

   
   ```js
   try {
     dataPreferences.deletePreferences(this.context, 'mystore', (err, val) => {
       if (err) {
         console.error(`Failed to delete preferences. Code:${err.code}, message:${err.message}`);
         return;
       }
       console.info('Succeeded in deleting preferences.');
     })
   } catch (err) {
     console.error(`Failed to delete preferences. Code:${err.code}, message:${err.message}`);
   }
   ```