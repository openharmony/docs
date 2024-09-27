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

6. 当本地设备存储空间有限或需要重新备份时，还可使用deleteBackup()方法删除备份，释放存储空间。
     
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

## 关系型数据库损坏重建

关系型数据库，可以通过在[StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig)中配置allowRebuild参数以设置数据库在损坏时是否自动重建，默认不重建。

开库时在StoreConfig中配置allowRebuild参数为true，则数据库损坏时将自动重建。

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

<!--Del-->
## 关系型数据库双写备份与恢复（仅系统应用可用）

关系型数据库，可以通过在[StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#storeconfig)中配置haMode参数实现数据库双写备份，通过[restore](../reference/apis-arkdata/js-apis-data-relationalStore-sys.md#restore12)接口实现数据库恢复。

1. 使用getRdbStore()方法创建关系型数据库，配置haMode参数为MAIN_REPLICA。
     
   ```ts
   import { relationalStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let store: relationalStore.RdbStore | undefined = undefined;

   let context = getContext(this);

   const STORE_CONFIG: relationalStore.StoreConfig = {
     name: 'RdbTest.db',
     securityLevel: relationalStore.SecurityLevel.S3,
     haMode: relationalStore.HAMode.MAIN_REPLICA
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

2. 使用insert()方法插入数据。
     
   ```ts
   import { ValuesBucket } from '@kit.ArkData';

   let value1 = 'Rose';
   let value2 = 18;
   let value3 = 100.5;
   let value4 = new Uint8Array([1, 2, 3, 4, 5]);

   // 以下三种方式可用
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

3. 使用delete()方法删除数据（模拟意外删除、篡改场景）。
     
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

4. 使用restore()方法恢复数据。
     
   ```ts
   if(store != undefined) {
     let promiseRestore = (store as relationalStore.RdbStore).restore();
     promiseRestore.then(() => {
       console.info('Succeeded in restoring.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to restore, code is ${err.code},message is ${err.message}`);
     })
    }
   ```
<!--DelEnd-->

## 关系型数据库备份与恢复

关系型数据库，通过backup接口实现数据库备份，通过restore接口实现数据库恢复。具体接口及功能，可见[关系型数据库](../reference/apis-arkdata/js-apis-data-relationalStore.md)。

1. 使用getRdbStore()方法创建关系型数据库。
     
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

2. 使用insert()方法插入数据。
     
   ```ts
   import { ValuesBucket } from '@kit.ArkData';

   let value1 = 'Rose';
   let value2 = 18;
   let value3 = 100.5;
   let value4 = new Uint8Array([1, 2, 3, 4, 5]);

   // 以下三种方式可用
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

3. 使用backup()方法备份数据。
     
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

4. 使用delete()方法删除数据（模拟意外删除、篡改场景）。
     
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

5. 使用restore()方法恢复数据。
     
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
