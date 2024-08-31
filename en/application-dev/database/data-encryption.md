# Database Encryption


## When to Use

OpenHarmony provides the database encryption capability to effectively protect the data stored in a database. Database encryption allows data to be stored and used in ciphertext, ensuring data confidentiality and integrity.

The encrypted database can be accessed only using an API, and the database file cannot be opened in other ways. Whether a database is encrypted is set when the database is created, and the setting cannot be changed.

Both KV stores and RDB stores support database encryption.


## Encrypting a KV Store

When a KV store is created, the **encrypt** parameter in **options** specifies whether to encrypt it. The value **true** means to encrypt the KV store, and the value **false** (default) means the opposite.

For details about the APIs, see [Distributed KV Store](../reference/apis-arkdata/js-apis-distributedKVStore.md).

  
```ts
import { distributedKVStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let kvManager: distributedKVStore.KVManager | undefined = undefined;
let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
let context = getContext(this);
const kvManagerConfig: distributedKVStore.KVManagerConfig = {
  context: context,
  bundleName: 'com.example.datamanagertest',
}
try {
  kvManager = distributedKVStore.createKVManager(kvManagerConfig);
  console.info('Succeeded in creating KVManager.');
} catch (e) {
  let error = e as BusinessError;
  console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
}
if (kvManager !== undefined) {
  kvManager = kvManager as distributedKVStore.KVManager;
  try {
    const options: distributedKVStore.Options = {
      createIfMissing: true,
      // Whether to encrypt the KV store.
      encrypt: true,
      backup: false,
      autoSync: false,
      kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
      securityLevel: distributedKVStore.SecurityLevel.S3
    };
    kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options, (err, store: distributedKVStore.SingleKVStore) => {
      if (err) {
        console.error(`Fail to get KVStore. Code:${err.code},message:${err.message}`);
        return;
      }
      console.info('Succeeded in getting KVStore.');
      kvStore = store;
    });
  } catch (e) {
    let error = e as BusinessError;
    console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
  }
}
if (kvStore !== undefined) {
  kvStore = kvStore as distributedKVStore.SingleKVStore;
    // Perform subsequent operations.
    //...
}
```


## Encrypting an RDB Store 

When an RDB store is created, the **encrypt** parameter in **StoreConfig** specifies whether to encrypt it. The value **true** means to encrypt the RDB store, and the value **false** (default) means the opposite.

For details about the APIs, see [RDB Store](../reference/apis-arkdata/js-apis-data-relationalStore.md).

  
```ts
import { relationalStore } from '@kit.ArkData';

let store: relationalStore.RdbStore;
let context = getContext(this);
const STORE_CONFIG: relationalStore.StoreConfig = {
  name: 'RdbTest.db',
  securityLevel: relationalStore.SecurityLevel.S3,
  encrypt: true
};
relationalStore.getRdbStore(context, STORE_CONFIG, (err, rdbStore) => {
  store = rdbStore;
  if (err) {
    console.error(`Failed to get RdbStore. Code:${err.code},message:${err.message}`);
    return;
  }
  console.info('Succeeded in getting RdbStore.');
})
```
