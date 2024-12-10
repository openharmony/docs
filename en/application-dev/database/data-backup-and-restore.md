# Database Backup and Restore


## When to Use

You may need to restore a database in any of the following cases:

- An important operation being performed by an application is interrupted.

- The database is unavailable due to data loss or corruption, or dirty data.


Both KV stores and RDB stores support database backup and restore. You can also delete KV store backups to release local storage space.


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
   let files = [backupFile];
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

## Backing Up an RDB Store

A database backup can be used to quickly restore a corrupted RDB store.

Two backup modes are available: manual backup and automatic backup. Automatic backup is available only for system applications.

### Manual Backup

Use [backup()](../reference/apis-arkdata/js-apis-data-relationalStore.md#backup) to manually back up an RDB store. <br>Example:

   ```ts
   import { relationalStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo } from '@kit.CoreFileKit';
   
   let store: relationalStore.RdbStore | undefined = undefined;

   let context = getContext(this);

   const STORE_CONFIG: relationalStore.StoreConfig = {
     name: 'RdbTest.db',
     securityLevel: relationalStore.SecurityLevel.S3,
     allowRebuild: true
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

     // Backup.db indicates the name of the database backup file. By default, it is in the same directory as the RdbStore file. You can also specify the directory in the customDir + backup.db format.
     (store as relationalStore.RdbStore).backup("Backup.db", (err: BusinessError) => {
       if (err) {
         console.error(`Failed to backup RdbStore. Code:${err.code}, message:${err.message}`);
           return;
        }
        console.info(`Succeeded in backing up RdbStore.`);
     })
   })
   ```

<!--Del-->

### Automatic Backup (for System Applications Only)

To implement hot backup of an RDB store, set **haMode** in [StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#storeconfig) to **MAIN_REPLICA**. This parameter is available only for system applications. <br>Example:

   ```ts
   // Set haMode to MAIN_REPLICA.
   const AUTO_BACKUP_CONFIG :relationalStore.StoreConfig = {
     name: "BackupResotreTest.db",
     securityLevel: relationalStore.SecurityLevel.S3,
     haMode: relationalStore.HAMode.MAIN_REPLICA, // Data is written to the main and replica stores on a real-time basis.
     allowRebuild: true
   }

   // Use getRdbStore() to create an RDB store instance.
   relationalStore.getRdbStore(context, AUTO_BACKUP_CONFIG, (err, store) => {
     if (err) {
       console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in getting RdbStore.');
   })
   ```

<!--DelEnd-->

## Rebuilding an RDB Store

If error code 14800011 is reported during the creation or use of an RDB store, the database is corrupted. If this occurs, you can rebuild the RDB store and restore data from a backup.

To enable automatic rebuild of an RDB store, set **allowRebuild** in [StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig) to **true**. The newly rebuilt RDB store is empty. You need to create tables and restore data from the database backup. For details about how to back up RDB store data, see [Backing Up an RDB Store](#backing-up-an-rdb-store). For details about how to restore RDB store data, see [Restoring RDB Store Data](#restoring-rdb-store-data).

If **allowRebuild** in **StoreConfig** is set to **true** before the database is corrupted, the database will be automatically rebuilt when corrupted.

If **allowRebuild** in **StoreConfig** is not set or is set to **false**, set **allowRebuild** to **true** and open the rebuilt RDB store. <br>Example:

   ```ts
   import { relationalStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let store: relationalStore.RdbStore | undefined = undefined;

   let context = getContext(this);

   const STORE_CONFIG: relationalStore.StoreConfig = {
     name: 'RdbTest.db',
     securityLevel: relationalStore.SecurityLevel.S3,
     allowRebuild: true
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

## Restoring RDB Store Data

If an RDB store is corrupted, you can restore it by using the database backup.

You can restore data from either the manual backup data or automatic backup data. The latter is available only for system applications.

### Restoring from Manual Backup Data

You can use **backup()** to [perform manual backup](#manual-backup) and use **restore()** to restore data from the manual backup data.

The following example contains only the code snippet for the restore process. The complete code must also contain the code for backing up data and rebuilding an RDB store.

1. Throw an exception that indicates database corruption.

   ```ts
   let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
   if (store != undefined) {
     (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((result: relationalStore.ResultSet) => {
       let resultSet = result;
       try {
         /* ...
            Logic for adding, deleting, and modifying data.
            ...
         */
         // Throw an exception.
         if (resultSet?.rowCount == -1) {
           resultSet ?.isColumnNull(0);
         }
         // Call other APIs such as resultSet.goToFirstRow() and resultSet.count(), which also throw exceptions.
         while (resultSet.goToNextRow()) {
           console.info(JSON.stringify(resultSet.getRow()))
         }
         resultSet.close();
       } catch (err) {
           if (err.code === 14800011) {
              // Perform step 2 (close result sets and then restore data).
           }
           console.error(JSON.stringify(err));
       }
     })
   }
   ```

2. Close all opened result sets.

   ```ts
   // Obtain all opened result sets.
   let resultSets: Array<relationalStore.ResultSet> = [];
   // Call resultSet.close() to close all opened result sets.
   for (let resultSet of resultSets) {
     try {
       resultSet.close();
     } catch (e) {
         if (e.code !== 14800014) {
           console.error(`Code:${e.code}, message:${e.message}`);
         }
     }
   }
   ```

3. Call **restore()** to restore data.

   ```ts
   try {
     let context = getContext();
     // Backup.db indicates the name of the database backup file. By default, it is in the same directory as the RdbStore file. You can also specify the directory in the customDir + backup.db format.
     let backup = context.databaseDir + '/backup/test_backup.db';
     if(!fileIo.access(backup)) {
       console.info("no backup file");
       try {
         (store as relationalStore.RdbStore).close;
         store = undefined;
       } catch (e) {
           if (e.code != 14800014) {
             console.info(JSON.stringify(e));
           }
       }
       let storeConfig: relationalStore.StoreConfig = {
         name: "BackupResotreTest.db",
         securityLevel: relationalStore.SecurityLevel.S3,
         allowRebuild: true
       }
       // Open the rebuilt RDB store and create tables.
       // Generate data.
       return
     }
     // Call restore() to restore data.
     (store as relationalStore.RdbStore).restore(backup);
   } catch (e) {
       console.error(`Code:${e.code}, message:${e.message}`);
   }
   ```

<!--Del-->

### Restoring from Automatic Backup Data (for System Applications Only)

Use [restore()](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#restore12) to restore data from the [automatic backup data](#automatic-backup-for-system-applications-only). Only system applications support this operation.

The following example contains only the code snippet for the restore process. The complete code must also contain the code for backing up data and rebuilding an RDB store.

   ```ts
   if (store !== undefined) {
     try {
       // Add, delete, modify, and query data.
     } catch (err) {
         if (err.code == 14800011) {
           // Obtain all opened result sets.
           let resultSets: Array<relationalStore.ResultSet> = [];
           // Call resultSet.close() to close all opened result sets.
           for (let resultSet of resultSets) {
             try {
               resultSet.close();
             } catch (e) {
                 if (e.code !== 14800014) {
                   console.info(`Code:${err.code}, message:${err.message}`);
                 }
             }
           }
   
           (store as relationalStore.RdbStore).restore("Backup.db", (err: BusinessError) => {
             if (err) {
               console.error(`Failed to restore RdbStore. Code:${err.code}, message:${err.message}`);
               return;
             }
             console.info(`Succeeded in restoring RdbStore.`);
           })
         }
         console.info(`Code:${err.code}, message:${err.message}`);
     }
   }
   ```

<!--DelEnd-->
