# Database Backup and Restore


## When to Use

You may need to restore a database in any of the following cases:

- An important operation being performed by an application is interrupted.

- The database is unavailable due to data loss or corruption, or dirty data.


Both KV stores and RDB stores support database backup and restore. In addition, KV stores allow you to delete database backups to release local storage space.


## Backing Up, Restoring, and Deleting a KV Store

You can use **backup()** to back up a KV store, use **restore()** to restore a KV store, and use **deletebackup()** to delete a KV store backup file. For details about the APIs, see [Distributed KV Store](../reference/apis-arkdata/js-apis-distributedKVStore.md).

1. Create a KV store.

   (1) Create a **kvManager** instance.

   (2) Set database parameters.

   (3) Create a **kvStore** instance.

     
   ```ts
   import { distributedKVStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let kvManager: distributedKVStore.KVManager;
   let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
   let context = getContext(this);
   const kvManagerConfig: distributedKVStore.KVManagerConfig = {
     context: context,
     bundleName: 'com.example.datamanagertest'
   }
   try {
     kvManager = distributedKVStore.createKVManager(kvManagerConfig);
     console.info('Succeeded in creating KVManager.');
     try {
       const options: distributedKVStore.Options = {
         createIfMissing: true,
         encrypt: true,
         backup: false,
         autoSync: false,
         kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
         securityLevel: distributedKVStore.SecurityLevel.S3
       };
       kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options, (err, store: distributedKVStore.SingleKVStore) => {
         if (err) {
           console.error(`Failed to get KVStore. Code:${err.code},message:${err.message}`);
           return;
         }
         console.info('Succeeded in getting KVStore.');
         kvStore = store;
       });
     } catch (e) {
       let error = e as BusinessError;
       console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
     }
   } catch (e) {
     let error = e as BusinessError;
     console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
   }
   
   if (kvStore !== undefined) {
     kvStore = kvStore as distributedKVStore.SingleKVStore;
     // Perform subsequent operations.
     //...
   }
   ```

2. Use **put()** to insert data to the KV store.
     
   ```ts
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
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```

3. Use **backup()** to back up the KV store.
     
   ```ts
   let backupFile = 'BK001';
   try {
     kvStore.backup(backupFile, (err) => {
       if (err) {
         console.error(`Fail to backup data.code:${err.code},message:${err.message}`);
       } else {
         console.info('Succeeded in backupping data.');
       }
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```

4. Use **delete()** to delete data to simulate unexpected deletion or data tampering.
     
   ```ts
   try {
     kvStore.delete(KEY_TEST_STRING_ELEMENT, (err) => {
       if (err !== undefined) {
         console.error(`Fail to delete data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in deleting data.');
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```

5. Use **restore()** to restore the KV store.
     
   ```ts
   let backupFile = 'BK001';
   try {
     kvStore.restore(backupFile, (err) => {
       if (err) {
         console.error(`Fail to restore data. Code:${err.code},message:${err.message}`);
       } else {
         console.info('Succeeded in restoring data.');
       }
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```

6. Use **deleteBackup()** to delete the backup file to release storage space.
     
   ```ts
   let files = ['BK001'];
   try {
     kvStore.deleteBackup(files).then((data) => {
       console.info(`Succeed in deleting Backup. Data:filename is ${data[0]},result is ${data[1]}.`);
     }).catch((err: BusinessError) => {
       console.error(`Fail to delete Backup. Code:${err.code},message:${err.message}`);
     })
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```


## Backing Up and Restoring an RDB Store

You can use **backup()** to back up an RDB store, and use **restore()** to restore an RDB store. For details about the APIs, see [RDB Store](../reference/apis-arkdata/js-apis-data-relationalStore.md).

1. Use **getRdbStore()** to create an RDB store.
     
   ```ts
   import { relationalStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let store: relationalStore.RdbStore | undefined = undefined;

   let context = getContext(this);

   const STORE_CONFIG: relationalStore.StoreConfig = {
     name: 'RdbTest.db',
     securityLevel: relationalStore.SecurityLevel.S3
   };
   relationalStore.getRdbStore(context, STORE_CONFIG, (err, rdbStore) => {
     store = rdbStore;
     if (err) {
       console.error(`Failed to get RdbStore. Code:${err.code},message:${err.message}`);
       return;
     }
     store.executeSql('CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)', (err) => {
     })
     console.info('Succeeded in getting RdbStore.');
   })
   ```

2. Use **insert()** to insert data to the RDB store.
     
   ```ts
   import { ValuesBucket } from '@kit.ArkData';

   let value1 = 'Rose';
   let value2 = 18;
   let value3 = 100.5;
   let value4 = new Uint8Array([1, 2, 3, 4, 5]);

   // You can use either of the following:
   const valueBucket1: ValuesBucket = {
     'NAME': value1,
     'AGE': value2,
     'SALARY': value3,
     'CODES': value4,
   };
   const valueBucket2: ValuesBucket = {
     NAME: value1,
     AGE: value2,
     SALARY: value3,
     CODES: value4,
   };
   const valueBucket3: ValuesBucket = {
     "NAME": value1,
     "AGE": value2,
     "SALARY": value3,
     "CODES": value4,
   };

   if(store != undefined) {
     (store as relationalStore.RdbStore).insert('EMPLOYEE', valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE, (err, rowId) => {
       if (err) {
         console.error(`Failed to insert data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info(`Succeeded in inserting data. rowId:${rowId}`);
     })
   }
   ```

3. Use **backup()** to back up the RDB store.
     
   ```ts
   if(store != undefined) {
     (store as relationalStore.RdbStore).backup('dbBackup.db', (err) => {
       if (err) {
         console.error(`Failed to back up data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in backing up data.');
     })
   }
   ```

4. Use **delete()** to delete data to simulate unexpected deletion or data tampering.
     
   ```ts
   let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
   predicates.equalTo('NAME', 'Lisa');
   if(store != undefined) {
     (store as relationalStore.RdbStore).delete(predicates).then((rows: number) => {
       console.info(`Delete rows: ${rows}`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to delete data. Code:${err.code},message:${err.message}`);
     })
   }
   ```

5. Use **restore()** to restore the RDB store.
     
   ```ts
   if(store != undefined) {
     (store as relationalStore.RdbStore).restore('dbBackup.db', (err) => {
       if (err) {
         console.error(`Failed to restore data. Code:${err.code},message:${err.message}`);
         return;
       }
       console.info('Succeeded in restoring data.');
     })
   }
   ```
