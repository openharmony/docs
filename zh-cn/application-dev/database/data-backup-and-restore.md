# 数据库备份与恢复


## 场景介绍

当应用在处理一项重要的操作，显然是不能被打断的。例如：写入多个表关联的事务。此时，每个表的写入都是单独的，但是表与表之间的事务关联性不能被分割。

如果操作的过程中出现问题，开发者可以使用恢复功能，将数据库恢复到之前的状态，重新对数据库进行操作。

在数据库被篡改、删除、或者设备断电场景下，数据库可能会因为数据丢失、数据损坏、脏数据等而不可用，可以通过数据库的备份恢复能力将数据库恢复至可用状态。


键值型数据库和关系型数据库均支持对数据库的备份和恢复。另外，键值型数据库还支持删除数据库备份，以释放本地存储空间。


## 键值型数据库备份、恢复与删除

键值型数据库，通过backup接口实现数据库备份，通过restore接口实现数据库恢复，通过deletebackup接口删除数据库备份。具体接口及功能，可见[分布式键值数据库](../reference/apis-arkdata/js-apis-distributedKVStore.md)。

1. 创建数据库。

   (1) 创建kvManager。

   (2) 配置数据库参数。

   (3) 创建kvStore。

     
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
     //进行后续操作
     //...
   }
   ```

2. 使用put()方法插入数据。
     
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

3. 使用backup()方法备份数据。
     
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

4. 使用delete()方法删除数据（模拟意外删除、篡改场景）。
     
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

5. 使用restore()方法恢复数据。
     
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

6. 当本地设备存储空间有限或需要重新备份时，还可使用deleteBackup()方法删除备份，释放存储空间。
     
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

## 关系型数据库备份

数据库操作或者存储过程中，有可能会因为各种原因发生非预期的数据库异常的情况，可以根据需要使用关系型数据库的备份能力，以便在数据库异常时，可靠高效地恢复数据保证业务数据正常使用。

关系型数据库支持两种手动备份和自动备份（仅系统应用可用）两种方式。

### 手动备份

手动备份：通过调用[backup](../reference/apis-arkdata/js-apis-data-relationalStore.md#backup)接口实现数据库手动备份。示例如下：

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
     console.info('Succeeded in getting RdbStore.');
     store.executeSql('CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)', (err) => {
     /**
      * "Backup.db"为备份数据库文件名，默认在RdbStore同路径下备份。
      * 也可指定绝对路径："/data/storage/el2/database/Backup.db"，文件路径需要存在，不会自动创建目录。
      */
     (store as relationalStore.RdbStore).backup("Backup.db", (err: BusinessError) => {
       if (err) {
         console.error(`Failed to backup RdbStore. Code:${err.code}, message:${err.message}`);
           return;
        }
        console.info(`Succeeded in backing up RdbStore.`);
      })
     })
   })
   ```

<!--Del-->

### 自动备份（仅系统应用可用）

自动备份：可以通过在[StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#storeconfig)中配置haMode参数为MAIN_REPLICA实现数据库双写备份，仅支持系统应用。示例如下：

   ```ts
   // 新增StoreConfig配置，配置haMode参数为MAIN_REPLICA。
   const AUTO_BACKUP_CONFIG :relationalStore.StoreConfig = {
     name: "BackupResotreTest.db",
     securityLevel: relationalStore.SecurityLevel.S3,
     haMode: relationalStore.HAMode.MAIN_REPLICA, // 配置为双写备份
     allowRebuild: true
   }

   // 使用getRdbStore()方法创建关系型数据库。
   relationalStore.getRdbStore(context, AUTO_BACKUP_CONFIG, (err, store) => {
     if (err) {
       console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in getting RdbStore.');
   })
   ```

<!--DelEnd-->

## 关系型数据库异常重建

在创建或使用关系型数据库的过程中，抛出14800011异常错误码说明数据库出现异常，可以删除数据库后恢复数据。

需要通过在[StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig)中配置allowRebuild参数为true以设置数据库在出现异常时自动删库。数据库重建成功后为空库，需要开发者重新建表并且使用提前备份好的数据进行数据恢复，备份操作可见[关系型数据库备份](#关系型数据库备份)，数据恢复可见[关系型数据库恢复](#关系型数据库数据恢复)。

若数据库异常前已配置StoreConfig中的allowRebuild为true，则数据库出现异常时将自动删库。

若数据库异常前未配置StoreConfig中的allowRebuild或allowRebuild配置为false，则需将其配置为true再次进行开库。具体示例如下：

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

## 关系型数据库数据恢复

针对数据库出现异常的情况，在数据库重建成功后，需要用提前备份好的数据进行数据恢复。

恢复方式分以下两种，手动备份恢复和自动备份恢复（仅系统应用可用）。

### 恢复手动备份数据

关系型数据库通过调用backup接口可以实现[手动备份数据库](#手动备份)，通过restore接口可以实现手动恢复数据库。

具体恢复过程和关键示例代码片段如下，完整示例代码请结合关系型数据库的备份、重建等上下文进行实现。

1. 抛出数据库异常错误码。

   ```ts
   let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
   if (store != undefined) {
     (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((result: relationalStore.ResultSet) => {
       let resultSet = result;
       try {
         /* ...
            业务的增删改逻辑
            ...
         */
         // 抛出异常
         if (resultSet?.rowCount == -1) {
           resultSet ?.isColumnNull(0);
         }
         // todo resultSet.goToFirstRow(), resultSet.count等其它接口也会抛异常
         while (resultSet.goToNextRow()) {
           console.info(JSON.stringify(resultSet.getRow()))
         }
         resultSet.close();
       } catch (err) {
           if (err.code === 14800011) {
              // 执行下文的步骤，即关闭结果集之后进行数据的恢复
           }
           console.error(JSON.stringify(err));
       }
     })
   }
   ```

2. 关闭所有打开着的结果集。

   ```ts
   // 获取所有打开着的结果集
   let resultSets: Array<relationalStore.ResultSet> = [];
   // 使用resultSet.close()方法关闭所有打开着的结果集
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

3. 调用restore接口恢复数据。

   ```ts
   try {
     let context = getContext();
     /**
      * "Backup.db"为备份数据库文件名，默认在当前 store 所在路径下查找备份文件 Backup.db。
      * 如在备份时指定了绝对路径："/data/storage/el2/database/Backup.db", 需要传入绝对路径。
      */
     let backup = context.databaseDir + '/entry/rdb/Backup.db';
     if (!fileIo.access(backup)) {
       console.info("no backup file");
       try {
         (store as relationalStore.RdbStore).close();
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
       // todo 开库建表
       // todo 自行生成数据
       return
     }
     // 调用restore接口恢复数据
     (store as relationalStore.RdbStore).restore("Backup.db");
   } catch (e) {
       console.error(`Code:${e.code}, message:${e.message}`);
   }
   ```

<!--Del-->

### 恢复自动备份数据（仅系统应用可用）

关系型数据库，可以通过[restore](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#restore12)接口恢复[自动备份的数据](#自动备份仅系统应用可用)，仅支持系统应用。

关键示例代码片段如下，完整示例代码请结合关系型数据库的备份、重建等上下文进行实现。

   ```ts
   if (store !== undefined) {
     try {
       // 增删改查
     } catch (err) {
         if (err.code == 14800011) {
           // 获取所有打开着的结果集
           let resultSets: Array<relationalStore.ResultSet> = [];
           // 使用resultSet.close()方法关闭所有打开着的结果集
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