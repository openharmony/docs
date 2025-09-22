# Database Backup and Restore (ArkTS)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997; @dboy190-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## When to Use

You may need to restore a database in any of the following cases:

An important operation being performed by an application is interrupted.

The database is unavailable due to data loss or corruption, or dirty data.


Both KV stores and RDB stores support database backup and restore. You can also delete KV store backups to release local storage space.


## Backing Up, Restoring, and Deleting a KV Store

You can use **backup()** to back up a KV store, use **restore()** to restore a KV store, and use **deletebackup()** to delete a KV store backup file. For details about the APIs, see [Distributed KV Store](../reference/apis-arkdata/js-apis-distributedKVStore.md).

1. Create a KV store.

   (1) Create a **kvManager** instance.

   (2) Set database parameters.

   (3) Create a **kvStore** instance.


   ```ts
   import { AbilityConstant, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { distributedKVStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';

   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
       let kvManager: distributedKVStore.KVManager;
       let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
       let context = this.context;
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
             if (kvStore !== undefined) {
               // Perform subsequent operations.
               // ...
             }
           });
         } catch (e) {
           let error = e as BusinessError;
           console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
         }
       } catch (e) {
         let error = e as BusinessError;
         console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
       }
     }
   }
   ```

2. Call **put()** to insert data to the KV store.
     
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

3. Call **backup()** to back up the KV store.
     
   ```ts
   let backupFile = 'BK001';
   try {
     kvStore.backup(backupFile, (err) => {
       if (err) {
         console.error(`Fail to backup data.code:${err.code},message:${err.message}`);
       } else {
         console.info('Succeeded in backuping data.');
       }
     });
   } catch (e) {
     let error = e as BusinessError;
     console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
   }
   ```

4. Call **delete()** to delete data to simulate unexpected deletion or data tampering.
     
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

5. Call **restore()** to restore the KV store.
     
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

6. Call **deleteBackup()** to delete the backup file to release storage space.
     
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

A database backup can be used to quickly restore an RDB store in abnormal state.

Two backup modes are available: manual backup and automatic backup. Automatic backup is available only for system applications.

### Manual Backup

Call the [backup](../reference/apis-arkdata/arkts-apis-data-relationalStore-RdbStore.md#backup) API to manually back up an RDB store. <br>Example:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  async onCreate(): Promise<void> {
    let store: relationalStore.RdbStore | undefined = undefined;
    let context = this.context;

    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: 'RdbTest.db',
      securityLevel: relationalStore.SecurityLevel.S3,
      allowRebuild: true
    };
    try {
      store = await relationalStore.getRdbStore(context, STORE_CONFIG);
      await store.executeSql('CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)');
      console.info('Succeeded in getting RdbStore.');
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to get RdbStore. Code:${err.code},message:${err.message}`);
    }

    if (!store) {
      return;
    }

    try {
      /**
       * Backup.db specifies the database backup file. By default, it is in the same directory as the RDB store.
       * You can also specify an absolute path, for example, /data/storage/el2/database/Backup.db. The file path must exist and will not be automatically created.
       */
      await store.backup("Backup.db");
      console.info(`Succeeded in backing up RdbStore.`);
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to backup RdbStore. Code:${err.code}, message:${err.message}`);
    }
  }
}
```

<!--Del-->

### Automatic Backup (for System Applications Only)

To implement hot backup of an RDB store, set **haMode** in [StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#storeconfig) to **MAIN_REPLICA**. This parameter is available only for system applications. <br>Example:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  async onCreate(): Promise<void> {
    let store: relationalStore.RdbStore | undefined = undefined;
    let context = this.context;
    try {
      // Set haMode of StoreConfig to MAIN_REPLICA.
      const AUTO_BACKUP_CONFIG: relationalStore.StoreConfig = {
        name: "BackupRestoreTest.db",
        securityLevel: relationalStore.SecurityLevel.S3,
        haMode: relationalStore.HAMode.MAIN_REPLICA, // Data is written to the main and replica stores on a real-time basis.
        allowRebuild: true
      }

      // Call getRdbStore() to create an RDB store instance.
      store = await relationalStore.getRdbStore(context, AUTO_BACKUP_CONFIG);
      console.info('Succeeded in getting RdbStore.');
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
    }
  }
}
```

<!--DelEnd-->

## Rebuilding an RDB Store

If error 14800011 is displayed when an RDB store is created or used, an exception occurs in the database. You can delete the database and restore data.

You can set **allowRebuild** in [StoreConfig](../reference/apis-arkdata/arkts-apis-data-relationalStore-i.md#storeconfig) to **true**, which allows the database to be automatically deleted when an exception occurs. The newly rebuilt RDB store is empty. You need to create tables and restore data from the database backup. For details about how to back up RDB store data, see [Backing Up an RDB Store](#backing-up-an-rdb-store). For details about how to restore RDB store data, see [Restoring RDB Store Data](#restoring-rdb-store-data).

If **allowRebuild** in **StoreConfig** is set to **true** before the database is abnormal, the database will be automatically deleted when an exception occurs.

If **allowRebuild** in **StoreConfig** is not set or is set to **false**, set **allowRebuild** to **true** and open the rebuilt RDB store. <br>Example:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  async onCreate(): Promise<void> {
    let store: relationalStore.RdbStore | undefined = undefined;
    let context = this.context;
    try {
      const STORE_CONFIG: relationalStore.StoreConfig = {
        name: 'RdbTest.db',
        securityLevel: relationalStore.SecurityLevel.S3,
        allowRebuild: true
      };
      store = await relationalStore.getRdbStore(context, STORE_CONFIG);
      await store.executeSql('CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)');
      console.info('Succeeded in getting RdbStore.');
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
    }
  }
}
```

## Restoring RDB Store Data

If an RDB store is abnormal, you can restore it by using the database backup.

You can restore data from either the manual backup data or automatic backup data. The latter is available only for system applications.

### Restoring from Manual Backup Data

You can use **backup()** to [perform manual backup](#manual-backup) and use **restore()** to restore data from the manual backup data.

The following example contains only the code snippet for the restore process. The complete code must also contain the code for backing up data and rebuilding an RDB store.

1. Throws an error code to indicate a database exception.

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
   import { UIAbility } from '@kit.AbilityKit';
   import { relationalStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo } from '@kit.CoreFileKit';

   export default class EntryAbility extends UIAbility {
     async onCreate(): Promise<void> {
       let store: relationalStore.RdbStore | undefined = undefined;
       let context = this.context;
       let STORE_CONFIG: relationalStore.StoreConfig = {
         name: "RdbTest.db",
         securityLevel: relationalStore.SecurityLevel.S3,
         allowRebuild: true
       }
       try {
         /**
          * Backup.db specifies the database backup file. By default, it is in the same directory as the current database.
          * If an absolute path is specified for the database backup file, for example, /data/storage/el2/database/Backup.db, pass in the absolute path.
          */
         let backupFilePath = context.databaseDir + '/rdb/Backup.db';
         const backupExist = await fileIo.access(backupFilePath);
         if (!backupExist) {
           console.info("Backup is not exist.");
           // Open the rebuilt RDB store and create tables.
           // Generate data.
           return;
         }
       } catch (e) {
         console.error(`Code:${e.code}, message:${e.message}`);
       }

       try {
         store = await relationalStore.getRdbStore(context, STORE_CONFIG);
         // Call restore() to restore data.
         await store.restore("Backup.db");
         console.log("Restore from back success.")
       } catch (e) {
         const err = e as BusinessError;
         console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
       }
     }
   }
   ```

<!--Del-->

### Restoring from Automatic Backup Data (for System Applications Only)

Call [restore()](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#restore12) to restore data from the [automatic backup data](#automatic-backup-for-system-applications-only). Only system applications support this operation.

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
                   console.error(`Code:${e.code}, message:${e.message}`);
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
         console.error(`Code:${err.code}, message:${err.message}`);
     }
   }
   ```

<!--DelEnd-->

<!--RP1--><!--RP1End-->
