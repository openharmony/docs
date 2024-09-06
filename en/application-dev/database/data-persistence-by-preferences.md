# Persisting Preferences Data


## When to Use

The **Preferences** module provides APIs for processing data in the form of key-value (KV) pairs, including querying, modifying, and persisting KV pairs. You can use **Preferences** when you want a unique storage for global data. 

The **Preferences** data is cached in the memory, which allows fast access when the data is required. If you want to persist data, you can use **flush()** to save the data to a file. The **Preferences** data occupies the application's memory space and cannot be encrypted through configuration. Therefore, it is recommended for storing personalized settings (font size and whether to enable the night mode) of applications. 


## Working Principles

User applications call **Preference** through the ArkTS interface to read and write data files. You can load the data of a **Preferences** persistence file to a **Preferences** instance. Each file uniquely corresponds to an instance. The system stores the instance in memory through a static container until the instance is removed from the memory or the file is deleted. The following figure illustrates how **Preference** works.

The preference persistent file of an application is stored in the application sandbox. You can use **context** to obtain the file path. For details, see [Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths).

**Figure 1** Preferences working mechanism 

![preferences](figures/preferences.jpg)


## Constraints

- Preferences are not thread-safe and may cause file damage and data loss when used in multi-process scenarios. Do not use preferences in multi-process scenarios.

- The key in a KV pair must be a string and cannot be empty or exceed 1024 bytes.

- If the value is of the string type, use the UTF-8 encoding format. It can be empty or a string not longer than 16 x 1024 x 1024 bytes.

- The memory usage increases with the amount of **Preferences** data. The maximum number of data records recommended is 10,000. Otherwise, high memory overheads will be caused.


## Available APIs

The following table lists the APIs used for persisting user preference data. For more information about the APIs, see [User Preferences](../reference/apis-arkdata/js-apis-data-preferences.md).

| API                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getPreferencesSync(context: Context, options: Options): Preferences | Obtains a **Preferences** instance. This API returns the result synchronously.<br/> An asynchronous API is also provided.                   |
| putSync(key: string, value: ValueType): void                 | Writes data to the **Preferences** instance. This API returns the result synchronously. An asynchronous API is also provided.<br/>You can use **flush()** to persist the **Preferences** instance data.|
| hasSync(key: string): boolean                                   | Checks whether the **Preferences** instance contains a KV pair with the given key. The key cannot be empty. This API returns the result synchronously.<br/> An asynchronous API is also provided.|
| getSync(key: string, defValue: ValueType): ValueType              | Obtains the value of the specified key. If the value is null or not of the default value type, **defValue** is returned. This API returns the result synchronously.<br/> An asynchronous API is also provided.|
| deleteSync(key: string): void                                | Deletes a KV pair from the **Preferences** instance. This API returns the result synchronously.<br/> An asynchronous API is also provided.|
| flush(callback: AsyncCallback&lt;void&gt;): void             | Flushes the data of this **Preferences** instance to a file for data persistence.|
| on(type: 'change', callback: Callback&lt;string&gt;): void | Subscribes to data changes. A callback will be invoked after **flush()** is executed for the data changed.|
| off(type: 'change', callback?: Callback&lt;string&gt;): void | Unsubscribes from data changes.                                          |
| deletePreferences(context: Context, options: Options, callback: AsyncCallback&lt;void&gt;): void | Deletes a **Preferences** instance from memory. If the **Preferences** instance has a persistent file, this API also deletes the persistent file.|


## How to Develop

1. Import the **@kit.ArkData** module.
   
   ```ts
   import { preferences } from '@kit.ArkData';
   ```

2. Obtain a **Preferences** instance.

   Stage model:


   ```ts
   import { UIAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { window } from '@kit.ArkUI';

   let dataPreferences: preferences.Preferences | null = null;

   class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       let options: preferences.Options = { name: 'myStore' };
       dataPreferences = preferences.getPreferencesSync(this.context, options);
     }
   }
   ```

   FA model:


   ```ts
   // Obtain the context.
   import { featureAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let context = featureAbility.getContext();
   let options: preferences.Options =  { name: 'myStore' };
   let dataPreferences: preferences.Preferences = preferences.getPreferencesSync(context, options);
   ```

3. Write data.

   Use **putSync()** to save data to the cached **Preferences** instance. After data is written, you can use **flush()** to persist the **Preferences** instance data to a file if necessary.

   > **NOTE**
   >
   > If the key already exists, **putSync()** overwrites the value. You can use **hasSync()** to check whether the KV pair exists.

   Example:

   ```ts
   import { util } from '@kit.ArkTS';
   if (dataPreferences.hasSync('startup')) {
     console.info("The key 'startup' is contained.");
   } else {
     console.info("The key 'startup' does not contain.");
     // Add a KV pair.
     dataPreferences.putSync('startup', 'auto');
     // If the string contains special characters, convert the string into a Uint8Array before storing it.
     let uInt8Array1 = new util.TextEncoder().encodeInto("~! @#￥%......&* () --+? ");
     dataPreferences.putSync('uInt8', uInt8Array1);
   }
   ```

4. Read data.

   Use **getSync()** to obtain the value of the specified key. If the value is null or is not of the default value type, the default data is returned.

   Example:

   ```ts
   let val = dataPreferences.getSync('startup', 'default');
   console.info("The 'startup' value is " + val);
   // If the value is a string containing special characters, it is stored in the Uint8Array format. Convert the obtained Uint8Array into a string.
   let uInt8Array2 : preferences.ValueType = dataPreferences.getSync('uInt8', new Uint8Array(0));
   let textDecoder = util.TextDecoder.create('utf-8');
   val = textDecoder.decodeWithStream(uInt8Array2 as Uint8Array);
   console.info("The 'uInt8' value is " + val);
   ```

5. Delete data.

   Use **deleteSync()** to delete a KV pair.<br>Example:


   ```ts
   dataPreferences.deleteSync('startup');
   ```

6. Persist data.

   You can use **flush()** to persist the data held in a **Preferences** instance to a file.<br>Example:

   ```ts
   dataPreferences.flush((err: BusinessError) => {
     if (err) {
       console.error(`Failed to flush. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in flushing.');
   })
   ```

7. Subscribe to data changes.

   Specify an observer as the callback to return the data changes for an application. When the value of the subscribed key is changed and saved by **flush()**, the observer callback will be invoked to return the new data.<br>Example:

   ```ts
   let observer = (key: string) => {
     console.info('The key' + key + 'changed.');
   }
   dataPreferences.on('change', observer);
   // The data is changed from 'auto' to 'manual'.
   dataPreferences.put('startup', 'manual', (err: BusinessError) => {
     if (err) {
       console.error(`Failed to put the value of 'startup'. Code:${err.code},message:${err.message}`);
       return;
     }
     console.info("Succeeded in putting the value of 'startup'.");
     if (dataPreferences !== null) {
       dataPreferences.flush((err: BusinessError) => {
         if (err) {
           console.error(`Failed to flush. Code:${err.code}, message:${err.message}`);
           return;
         }
         console.info('Succeeded in flushing.');
       })
     }
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


   ```ts
   preferences.deletePreferences(this.context, options, (err: BusinessError) => {
     if (err) {
       console.error(`Failed to delete preferences. Code:${err.code}, message:${err.message}`);
         return;
     }
     console.info('Succeeded in deleting preferences.');
   })
   ```