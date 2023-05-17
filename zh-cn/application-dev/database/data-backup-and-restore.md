# 数据库备份与恢复


## 场景介绍

当应用在处理一项重要的操作，显然是不能被打断的。例如：写入多个表关联的事务。此时，每个表的写入都是单独的，但是表与表之间的事务关联性不能被分割。

如果操作的过程中出现问题，开发者可以使用恢复功能，将数据库恢复到之前的状态，重新对数据库进行操作。

在数据库被篡改、删除、或者设备断电场景下，数据库可能会因为数据丢失、数据损坏、脏数据等而不可用，可以通过数据库的备份恢复能力将数据库恢复至可用状态。


键值型数据库和关系型数据库均支持对数据库的备份和恢复。另外，键值型数据库还支持删除数据库备份，以释放本地存储空间。


## 键值型数据库备份、恢复与删除

键值型数据库，通过backup接口实现数据库备份，通过restore接口实现数据库恢复，通过deletebackup接口删除数据库备份。具体接口及功能，可见[分布式键值数据库](../reference/apis/js-apis-distributedKVStore.md)。

1. 创建数据库。

   (1) 创建kvManager。

   (2) 配置数据库参数。

   (3) 创建kvStore。

     
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

2. 使用put()方法插入数据。
     
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

3. 使用backup()方法备份数据。
     
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

4. 使用delete()方法删除数据（模拟意外删除、篡改场景）。
     
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

5. 使用restore()方法恢复数据。
     
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

6. 当本地设备存储空间有限或需要重新备份时，还可使用deleteBackup()方法删除备份，释放存储空间。
     
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


## 关系型数据库备份与恢复

关系型数据库，通过backup接口实现数据库备份，通过restore接口实现数据库恢复。具体接口及功能，可见[关系型数据库](../reference/apis/js-apis-data-relationalStore.md)。

1. 使用getRdbStore()方法创建关系型数据库。
     
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

2. 使用insert()方法插入数据。
     
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

3. 使用backup()方法备份数据。
     
   ```js
   store.backup('dbBackup.db', (err) => {
     if (err) {
       console.error(`Failed to backup data. Code:${err.code},message:${err.message}`);
       return;
     }
     console.info(`Succeeded in backuping data.`);
   })
   ```

4. 使用delete()方法删除数据（模拟意外删除、篡改场景）。
     
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

5. 使用restore()方法恢复数据。
     
   ```js
   store.restore('dbBackup.db', (err) => {
     if (err) {
       console.error(`Failed to restore data. Code:${err.code},message:${err.message}`);
       return;
     }
     console.info(`Succeeded in restoring data.`);
   })
   ```
