# Persisting KV Store Data


## When to Use

The key-value (KV) database stores data in the form of KV pairs. You can use KV stores to store data organized in a simple model, for example, product names and prices or employee IDs and daily attendance. The simple data structure allows higher compatibility with different database versions and device types.


## Constraints

- For each record in a device KV store, the key cannot exceed 896 bytes and the value cannot exceed 4 MB.

- For each record in a single KV store, the key cannot exceed 1 KB and the value cannot exceed 4 MB.

- A maximum of 16 distributed KV stores can be opened simultaneously for an application.

- Blocking operations, for example, modifying UI components, are not allowed in the KV store event callbacks.


## Available APIs

The following table lists the APIs used for KV data persistence. Most of the APIs are executed asynchronously, using a callback or promise to return the result. The following table uses the callback-based APIs as an example. For more information about the APIs, see [Distributed KV Store](../reference/apis/js-apis-distributedKVStore.md).

| API| Description| 
| -------- | -------- |
| createKVManager(config: KVManagerConfig): KVManager | Creates a **KvManager** instance to manage database objects.| 
| getKVStore&lt;T&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void | Creates and obtains a KV store of the specified type.| 
| put(key: string, value: Uint8Array\|string\|number\|boolean, callback: AsyncCallback&lt;void&gt;): void | Adds a KV pair of the specified type to this KV store.| 
| get(key: string, callback: AsyncCallback&lt;Uint8Array\|string\|boolean\|number&gt;): void | Obtains the value of the specified key.| 
| delete(key: string, callback: AsyncCallback&lt;void&gt;): void | Deletes a KV pair based on the specified key.| 


## How to Develop

1. Create a **KvManager** instance to manage database objects. 

   Example:
   Stage model:

     
   ```js
   // Import the module.
   import distributedKVStore from '@ohos.data.distributedKVStore';
   
   // Stage model
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   let kvManager;
   
   export default class EntryAbility extends UIAbility {
     onCreate() {
       let context = this.context;
       const kvManagerConfig = {
         context: context,
         bundleName: 'com.example.datamanagertest'
       };
       try {
         // Create a KVManager instance.
         kvManager = distributedKVStore.createKVManager(kvManagerConfig);
         console.info('Succeeded in creating KVManager.');
         // Create and obtain the database.
       } catch (e) {
         console.error(`Failed to create KVManager. Code:${e.code},message:${e.message}`);
       }
     }
   }
   ```

   FA model:

     
   ```js
   // Import the module.
   import distributedKVStore from '@ohos.data.distributedKVStore';
   
   // FA model
   import featureAbility from '@ohos.ability.featureAbility';
   
   let kvManager;
   let context = featureAbility.getContext(); // Obtain the context.
   const kvManagerConfig = {
     context: context,
     bundleName: 'com.example.datamanagertest'
   };
   try {
     kvManager = distributedKVStore.createKVManager(kvManagerConfig);
     console.info('Succeeded in creating KVManager.');
     // Create and obtain the database.
   } catch (e) {
     console.error(`Failed to create KVManager. Code:${e.code},message:${e.message}`);
   }
   ```

2. Create and obtain a KV store. 
     
   Example:
   ```js
   try {
     const options = {
       createIfMissing: true, // Whether to create a KV store when the database file does not exist. By default, a KV store is created.
       encrypt: false, // Whether to encrypt the KV store. By default, KV stores are not encrypted.
       backup: false, // Whether to back up database files. By default, the database files are backed up.
       autoSync: true, // Whether to automatically synchronize database files. The value **true** means to automatically synchronize database files; the value **false** (default) means the opposite.
       kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION, // Type of the KV store to create. By default, a device KV store is created.
       securityLevel: distributedKVStore.SecurityLevel.S2 // Security level of the KV store.
     };
     // storeId uniquely identifies a KV store.
     kvManager.getKVStore('storeId', options, (err, kvStore) => {
       if (err) {
         console.error(`Failed to get KVStore. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in getting KVStore.');
       // Perform related data operations.
     });
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```

3. Use **put()** to add data to the KV store. 
     
   Example:
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
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```

   > **NOTE**
   >
   > The **put()** method adds a KV pair if the specified key does not exists and changes the value if the the specified key already exists.

4. Use **get()** to obtain the value of a key. 
     
   Example:
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
       kvStore.get(KEY_TEST_STRING_ELEMENT, (err, data) => {
         if (err !== undefined) {
           console.error(`Failed to get data. Code:${err.code},message:${err.message}`);
           return;
         }
         console.info(`Succeeded in getting data. data:${data}`);
       });
     });
   } catch (e) {
     console.error(`Failed to get data. Code:${e.code},message:${e.message}`);
   }
   ```

5. Use **delete()** to delete the data of the specified key. 
     
   Example:
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
       kvStore.delete(KEY_TEST_STRING_ELEMENT, (err) => {
         if (err !== undefined) {
           console.error(`Failed to delete data. Code:${err.code},message:${err.message}`);
           return;
         }
         console.info('Succeeded in deleting data.');
       });
     });
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```
