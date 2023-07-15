# Database Encryption


## When to Use

OpenHarmony provides the database encryption capability to effectively protect the data stored in a database. Database encryption allows data to be stored and used in ciphertext, ensuring data confidentiality and integrity.

The encrypted database can be accessed only using an API, and the database file cannot be opened in other ways. Whether a database is encrypted is set when the database is created, and the setting cannot be changed.

Both KV stores and RDB stores support database encryption.


## Encrypting a KV Store

When a KV store is created, the **encrypt** parameter in **options** specifies whether to encrypt the KV store. The value **true** means to encrypt the KV store, and the value **false** (default) means the opposite.

For details about the APIs, see [Distributed KV Store](../reference/apis/js-apis-distributedKVStore.md).

  
```js
import distributedKVStore from '@ohos.data.distributedKVStore';

let kvManager;
let context = getContext(this);
const kvManagerConfig = {
  context: context,
  bundleName: 'com.example.datamanagertest',
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
    // Whether to encrypt the KV store.
    encrypt: true,
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


## Encrypting an RDB Store 

When an RDB store is created, the **encrypt** parameter in **options** specifies whether to encrypt the RDB store. The value **true** means to encrypt the RDB store, and the value **false** (default) means the opposite.

For details about the APIs, see [RDB Store](../reference/apis/js-apis-data-relationalStore.md).

  
```js
import relationalStore from '@ohos.data.relationalStore';

let store;
let context = getContext(this);
const STORE_CONFIG = {
  name: 'RdbTest.db',
  securityLevel: relationalStore.SecurityLevel.S1,
  encrypt: true
};
relationalStore.getRdbStore(context, STORE_CONFIG, (err, rdbStore) => {
  store = rdbStore;
  if (err) {
    console.error(`Failed to get RdbStore. Code:${err.code},message:${err.message}`);
    return;
  }
  console.info(`Succeeded in getting RdbStore.`);
})
```
