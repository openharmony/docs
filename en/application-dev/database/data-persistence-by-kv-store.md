# Persisting KV Store Data


## When to Use

The key-value (KV) database stores data in the form of KV pairs. You can use KV stores to store data organized in a simple model, for example, product names and prices or employee IDs and daily attendance. The simple data structure allows higher compatibility with different database versions and device types.


## Constraints

- For each record in a device KV store, the key cannot exceed 896 bytes and the value cannot exceed 4 MB.

- For each record in a single KV store, the key cannot exceed 1 KB and the value cannot exceed 4 MB.

- A maximum of 16 distributed KV stores can be opened simultaneously for an application.

- Blocking operations, for example, modifying UI components, are not allowed in the KV store event callbacks.


## Available APIs

The following table lists the APIs used for KV data persistence. Most of the APIs are executed asynchronously, using a callback or promise to return the result. The following table uses the callback-based APIs as an example. For more information about the APIs, see [Distributed KV Store](../reference/apis-arkdata/js-apis-distributedKVStore.md).

| API| Description| 
| -------- | -------- |
| createKVManager(config: KVManagerConfig): KVManager | Creates a **KvManager** instance to manage database objects.| 
| getKVStore&lt;T&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void | Obtains a KV store of the specified type.| 
| put(key: string, value: Uint8Array \| string \| number \| boolean, callback: AsyncCallback&lt;void&gt;): void | Adds a KV pair of the specified type to this KV store.| 
| get(key: string, callback: AsyncCallback\<boolean \| string \| number \| Uint8Array>): void | Obtains the value of the specified key.| 
| delete(key: string, callback: AsyncCallback&lt;void&gt;): void | Deletes a KV pair based on the specified key.| 


## How to Develop

1. Create a **KvManager** instance to manage database objects. <br>Example:

   Stage model:

     
   ```js
   // Import the module.
   import { distributedKVStore } from '@kit.ArkData';
   
   // Stage model
   import { window } from '@kit.ArkUI';
   import { UIAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let kvManager: distributedKVStore.KVManager | undefined = undefined;
   
   export default class EntryAbility extends UIAbility {
     onCreate() {
       let context = this.context;
       const kvManagerConfig: distributedKVStore.KVManagerConfig = {
         context: context,
         bundleName: 'com.example.datamanagertest'
       };
       try {
         // Create a KVManager instance.
         kvManager = distributedKVStore.createKVManager(kvManagerConfig);
         console.info('Succeeded in creating KVManager.');
         // Create and obtain the database.
       } catch (e) {
         let error = e as BusinessError;
         console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
       }
     }
   }
   if (kvManager !== undefined) {
      kvManager = kvManager as distributedKVStore.KVManager;
     // Perform subsequent operations.
     //...
   }
   ```

   FA model:

     
   ```js
   // Import the module.
   import { distributedKVStore } from '@kit.ArkData';
   
   // FA model
   import { featureAbility } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let kvManager: distributedKVStore.KVManager | undefined = undefined;
   let context = featureAbility.getContext(); // Obtain the context.
   const kvManagerConfig: distributedKVStore.KVManagerConfig = {
     context: context,
     bundleName: 'com.example.datamanagertest'
   };
   try {
     kvManager = distributedKVStore.createKVManager(kvManagerConfig);
     console.info('Succeeded in creating KVManager.');
     // Create and obtain the database.
   } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
   }
   if (kvManager !== undefined) {
     kvManager = kvManager as distributedKVStore.KVManager;
     // Perform subsequent operations.
     //...
   }

   ```

2. Create and obtain a KV store. <br>Example:
     
   ```js
   let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
   try {
     const options: distributedKVStore.Options = {
       createIfMissing: true,
       encrypt: false,
       backup: false,
       autoSync: false,
       // If kvStoreType is left empty, a device KV store is created by default.
       kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
       // Device KV store: kvStoreType: distributedKVStore.KVStoreType.DEVICE_COLLABORATION,
       securityLevel: distributedKVStore.SecurityLevel.S3
     };
     kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options, (err, store: distributedKVStore.SingleKVStore) => {
       if (err) {
         console.error(`Failed to get KVStore: Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in getting KVStore.');
       kvStore = store;
       // Before performing related data operations, obtain a KV store instance.
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   if (kvStore !== undefined) {
     kvStore = kvStore as distributedKVStore.SingleKVStore;
       // Perform subsequent operations.
       //...
   }
   ```

3. Use **put()** to add data to the KV store. <br>Example:
     
   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value_test_string';
   try {
     kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in putting data.');
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```

   > **NOTE**
   >
   > The **put()** method adds a KV pair if the specified key does not exists and changes the value if the the specified key already exists.

4. Use **get()** to obtain the value of a key. <br>Example:
     
   ```js
   try {
     kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in putting data.');
       kvStore = kvStore as distributedKVStore.SingleKVStore;
       kvStore.get(KEY_TEST_STRING_ELEMENT, (err, data) => {
         if (err != undefined) {
           console.error(`Failed to get data. Code:${err.code},message:${err.message}`);
           return;
         }
         console.info(`Succeeded in getting data. Data:${data}`);
       });
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`Failed to get data. Code:${error.code},message:${error.message}`);
   }
   ```

5. Use **delete()** to delete the data of the specified key. <br>Example:
     
   ```js
   try {
     kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in putting data.');
       kvStore = kvStore as distributedKVStore.SingleKVStore;
       kvStore.delete(KEY_TEST_STRING_ELEMENT, (err) => {
         if (err !== undefined) {
           console.error(`Failed to delete data. Code:${err.code},message:${err.message}`);
           return;
         }
         console.info('Succeeded in deleting data.');
       });
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```
