# Database Backup and Restoration


## When to Use

You may need to restore a database in any of the following cases:

An important operation being performed by an application is interrupted.

The database is unavailable due to data loss or corruption, or dirty data.


Both KV stores and RDB stores support database backup and restoration. In addition, KV stores allow you to delete database backups to release local storage space.


## Backing Up, Restoring, and Deleting a KV Store

You can use **backup()** to back up a KV store, use **restore()** to restore a KV store, and use **deletebackup()** to delete a KV store backup file. For details about the APIs, see [Distributed KV Store](../reference/apis/js-apis-distributedKVStore.md).

1. Create a KV store.

   (1) Create a **kvManager** instance.

   (2) Set database parameters.

   (3) Create a **kvStore** instance.

     
   ```js
   import distributedKVStore from '@ohos.data.distributedKVStore';
   
   let kvManager;
   let context = getContext(this);
   const kvManagerConfig = {
     context: context,
     bundleName: 'com.example.datamanagertest'
   }
   try {
     kvManager = distributedKVStore.createKVManager(kvManagerConfig);
     console.info('Succeeded in creating KVManager.');
   } catch (e) {
     console.error(`Failed to create KVManager. Code:${e.code},message:${e.message}`);
   }
   let kvStore;
   try {
     const options = {
       createIfMissing: true,
       encrypt: false,
       backup: false,
       autoSync: true,
       kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
       securityLevel: distributedKVStore.SecurityLevel.S2
     };
     kvManager.getKVStore('storeId', options, (err, store) => {
       if (err) {
         console.error(`Fail to get KVStore. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in getting KVStore.');
       kvStore = store;
     });
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```

2. Use **put()** to insert data to the KV store.
     
   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value_test_string';
   try {
     kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Fail to put data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in putting data.');
     });
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```

3. Use **backup()** to back up the KV store.
     
   ```js
   let file = 'BK001';
   try {
     kvStore.backup(file, (err) => {
       if (err) {
         console.error(`Fail to backup data.code:${err.code},message:${err.message}`);
       } else {
         console.info('Succeeded in backupping data.');
       }
     });
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```

4. Use **delete()** to delete data to simulate unexpected deletion or data tampering.
     
   ```js
   try {
     kvStore.delete(KEY_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Fail to delete data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in deleting data.');
     });
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```

5. Use **restore()** to restore the KV store.
     
   ```js
   let file = 'BK001';
   try {
     kvStore.restore(file, (err) => {
       if (err) {
         console.error(`Fail to restore data. Code:${err.code},message:${err.message}`);
       } else {
         console.info('Succeeded in restoring data.');
       }
     });
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```

6. Use **deleteBackup()** to delete the backup file to release storage space.
     
   ```js
   let kvStore;
   let files = ['BK001'];
   try {
     kvStore.deleteBackup(files).then((data) => {
       console.info(`Succeed in deleting Backup. Data:filename is ${data[0]},result is ${data[1]}.`);
     }).catch((err) => {
       console.error(`Fail to delete Backup. Code:${err.code},message:${err.message}`);
     })
   } catch (e) {
     console.error(`An unexpected error occurred. Code:${e.code},message:${e.message}`);
   }
   ```


## Backing Up and Restoring an RDB Store

You can use **backup()** to back up an RDB store, and use **restore()** to restore an RDB store. For details about the APIs, see [RDB Store](../reference/apis/js-apis-data-relationalStore.md).

1. Use **getRdbStore()** to create an RDB store.
     
   ```js
   import relationalStore from '@ohos.data.relationalStore';
   
   let store;
   let context = getContext(this);
   const STORE_CONFIG = {
     name: 'RdbTest.db',
     securityLevel: relationalStore.SecurityLevel.S1
   };
   relationalStore.getRdbStore(context, STORE_CONFIG, (err, rdbStore) => {
     store = rdbStore;
     if (err) {
       console.error(`Failed to get RdbStore. Code:${err.code},message:${err.message}`);
       return;
     }
     store.executeSql("CREATE TABLE IF NOT EXISTS EMPLOYEE (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, age INTEGER, salary INTEGER, codes Uint8Array);", null);
     console.info('Succeeded in getting RdbStore.');
   })
   ```

2. Use **insert()** to insert data to the RDB store.
     
   ```js
   const valueBucket = {
     'NAME': 'Lisa',
     'AGE': 18,
     'SALARY': 100.5,
     'CODES': new Uint8Array([1, 2, 3, 4, 5])
   };
   store.insert('EMPLOYEE', valueBucket, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE, (err, rowId) => {
     if (err) {
       console.error(`Failed to insert data. Code:${err.code},message:${err.message}`);
       return;
     }
     console.info(`Succeeded in inserting data. rowId:${rowId}`);
   })
   ```

3. Use **backup()** to back up the RDB store.
     
   ```js
   store.backup('dbBackup.db', (err) => {
     if (err) {
       console.error(`Failed to backup data. Code:${err.code},message:${err.message}`);
       return;
     }
     console.info(`Succeeded in backuping data.`);
   })
   ```

4. Use **delete()** to delete data to simulate unexpected deletion or data tampering.
     
   ```js
   let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
   predicates.equalTo('NAME', 'Lisa');
   let promise = store.delete(predicates);
   promise.then((rows) => {
     console.info(`Delete rows: ${rows}`);
   }).catch((err) => {
     console.error(`Failed to delete data. Code:${err.code},message:${err.message}`);
   })
   ```

5. Use **restore()** to restore the RDB store.
     
   ```js
   store.restore('dbBackup.db', (err) => {
     if (err) {
       console.error(`Failed to restore data. Code:${err.code},message:${err.message}`);
       return;
     }
     console.info(`Succeeded in restoring data.`);
   })
   ```
