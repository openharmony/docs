# Creating a DataAbility
<!--deprecated_code_no_check-->

To meet the basic requirements of the database storage service, implement the **Insert**, **Query**, **Update**, and **Delete** methods for a DataAbility. The **BatchInsert** and **ExecuteBatch** methods have already implemented the traversal logic, but not batch data processing.


The following sample code shows how to create a DataAbility:

```ts
import featureAbility from '@ohos.ability.featureAbility';
import type common from '@ohos.app.ability.common';
import type Want from '@ohos.app.ability.Want';
import type { AsyncCallback, BusinessError } from '@ohos.base';
import dataAbility from '@ohos.data.dataAbility';
import rdb from '@ohos.data.rdb';
import hilog from '@ohos.hilog';

let TABLE_NAME = 'book';
let STORE_CONFIG: rdb.StoreConfig = { name: 'book.db' };
let SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS book(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, introduction TEXT NOT NULL)';
let rdbStore: rdb.RdbStore | undefined = undefined;
const TAG: string = '[Sample_FAModelAbilityDevelop]';
const domain: number = 0xFF00;

class DataAbility {
  onInitialized(want: Want): void {
    hilog.info(domain, TAG, 'DataAbility onInitialized, abilityInfo:' + want.bundleName);
    let context: common.BaseContext = { stageMode: featureAbility.getContext().stageMode };
    rdb.getRdbStore(context, STORE_CONFIG, 1, (err, store) => {
      hilog.info(domain, TAG, 'DataAbility getRdbStore callback');
      store.executeSql(SQL_CREATE_TABLE, []);
      rdbStore = store;
    });
  }

  insert(uri: string, valueBucket: rdb.ValuesBucket, callback: AsyncCallback<number>): void {
    hilog.info(domain, TAG, 'DataAbility insert start');
    if (rdbStore) {
      rdbStore.insert(TABLE_NAME, valueBucket, callback);
    }
  }

  batchInsert(uri: string, valueBuckets: Array<rdb.ValuesBucket>, callback: AsyncCallback<number>): void {
    hilog.info(domain, TAG, 'DataAbility batch insert start');
    if (rdbStore) {
      for (let i = 0; i < valueBuckets.length; i++) {
        hilog.info(domain, TAG, 'DataAbility batch insert i=' + i);
        if (i < valueBuckets.length - 1) {
          rdbStore.insert(TABLE_NAME, valueBuckets[i], (err: BusinessError, num: number) => {
            hilog.info(domain, TAG, 'DataAbility batch insert ret=' + num);
          });
        } else {
          rdbStore.insert(TABLE_NAME, valueBuckets[i], callback);
        }
      }
    }
  }

  query(uri: string, columns: Array<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback<rdb.ResultSet>): void {
    hilog.info(domain, TAG, 'DataAbility query start');
    let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates);
    if (rdbStore) {
      rdbStore.query(rdbPredicates, columns, callback);
    }
  }

  update(uri: string, valueBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback<number>): void {
    hilog.info(domain, TAG, 'DataAbility update start');
    let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates);
    if (rdbStore) {
      rdbStore.update(valueBucket, rdbPredicates, callback);
    }
  }

  delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback<number>): void {
    hilog.info(domain, TAG, 'DataAbility delete start');
    let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates);
    if (rdbStore) {
      rdbStore.delete(rdbPredicates, callback);
    }
  }
}

export default new DataAbility();
```
