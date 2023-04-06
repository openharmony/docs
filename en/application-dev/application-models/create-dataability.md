# Creating a DataAbility


To meet the basic requirements of the database storage service, implement the **Insert**, **Query**, **Update**, and **Delete** methods for a DataAbility. The **BatchInsert** and **ExecuteBatch** methods have already implemented the traversal logic, but not batch data processing.


The following sample code shows how to create a DataAbility:

```ts
import featureAbility from '@ohos.ability.featureAbility'
import dataAbility from '@ohos.data.dataAbility'
import dataRdb from '@ohos.data.rdb'

const TABLE_NAME = 'book'
const STORE_CONFIG = { name: 'book.db' }
const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS book(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, introduction TEXT NOT NULL)'
let rdbStore: dataRdb.RdbStore = undefined

export default {
  onInitialized(abilityInfo) {
    console.info('DataAbility onInitialized, abilityInfo:' + abilityInfo.bundleName)
    let context = featureAbility.getContext()
    dataRdb.getRdbStore(context, STORE_CONFIG, 1, (err, store) => {
      console.info('DataAbility getRdbStore callback')
      store.executeSql(SQL_CREATE_TABLE, [])
      rdbStore = store
    });
  },
  insert(uri, valueBucket, callback) {
    console.info('DataAbility insert start')
    rdbStore.insert(TABLE_NAME, valueBucket, callback)
  },
  batchInsert(uri, valueBuckets, callback) {
    console.info('DataAbility batch insert start')
    for (let i = 0;i < valueBuckets.length; i++) {
      console.info('DataAbility batch insert i=' + i)
      if (i < valueBuckets.length - 1) {
        rdbStore.insert(TABLE_NAME, valueBuckets[i], (err: any, num: number) => {
          console.info('DataAbility batch insert ret=' + num)
        })
      } else {
        rdbStore.insert(TABLE_NAME, valueBuckets[i], callback)
      }
    }
  },
  query(uri, columns, predicates, callback) {
    console.info('DataAbility query start')
    let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates)
    rdbStore.query(rdbPredicates, columns, callback)
  },
  update(uri, valueBucket, predicates, callback) {
    console.info('DataAbilityupdate start')
    let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates)
    rdbStore.update(valueBucket, rdbPredicates, callback)
  },
  delete(uri, predicates, callback) {
    console.info('DataAbilitydelete start')
    let rdbPredicates = dataAbility.createRdbPredicates(TABLE_NAME, predicates)
    rdbStore.delete(rdbPredicates, callback)
  }
};
```
