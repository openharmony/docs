# Database Encryption


## When to Use

OpenHarmony provides the database encryption capability to effectively protect the data stored in a database. Database encryption allows data to be stored and used in ciphertext, ensuring data confidentiality and integrity.

The encrypted database can be accessed only using an API, and the database file cannot be opened in other ways. Whether a database is encrypted is set when the database is created, and the setting cannot be changed.

Both KV stores and RDB stores support database encryption. For RDB stores, you can custom the encryption/decryption keys and other parameters.


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

The **encrypt** property in [StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig) specifies whether to encrypt the RDB store. The value **true** means to encrypt the RDB store, and **false** means the opposite.

If **encrypt** is **true**, you can set parameters such as the key and algorithm used for encryption/decryption in **cryptoParam**.

The **cryptoParam** parameter is optional.

If **cryptoParam** is not set, the default configuration is used for database encryption and decryption.


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

If **cryptoParam** is set, the specified key and algorithm are used for database encryption and decryption.

```ts
import { relationalStore } from '@kit.ArkData';

let context = getContext(this);

// Initialize the key to be used.
let key = new Uint8Array(32);
for (let i = 0; i < 32; i++) {
    key[i] = i;
}

// Initialize the encryption algorithm.
const CRYPTO_PARAM : relationalStore.CryptoParam = {
    encryptionKey: key,     // (Mandatory) Key used to open the encrypted database. If this parameter is not specified, the database generates and saves the key and uses the generated key to open the database file.
    iterationCount: 25000,  // (Optional) Number of iterations. The value must be greater than or equal to 0. If this parameter is not specified or is set to 0, the default value 10000 and the default encryption algorithm are used.
    encryptionAlgo: relationalStore.EncryptionAlgo.AES_256_CBC, // (Optional) Encryption/Decryption algorithm. If this parameter is not specified, the default algorithm AES_256_GCM is used.
    hmacAlgo: relationalStore.HmacAlgo.SHA256,   // (Optional) HMAC algorithm. If this parameter is not specified, the default value SHA256 is used.
    kdfAlgo: relationalStore.KdfAlgo.KDF_SHA512, // (Optional) KDF algorithm. If this parameter is not specified, the default value (same as the HMAC algorithm) is used.
    cryptoPageSize: 2048                         // (Optional) Page size used for encryption/decryption. The value must be an integer within the range of 1024 to 65536 and a power of 2. The default value is 1024.
}

const STORE_CONFIG : relationalStore.StoreConfig = {
    name: "encrypted.db",
    securityLevel: relationalStore.SecurityLevel.S3,
    encrypt: true,
    cryptoParam: CRYPTO_PARAM
}

async function run() {
    let store = await relationalStore.getRdbStore(context, STORE_CONFIG);
    if (store == null) {
      console.error('Failed to get RdbStore.');
    } else {
      console.info('Succeeded in getting RdbStore.');
    }
    // Clear the key.
    CRYPTO_PARAM.encryptionKey.fill(0);
}

run();
```

If you do not care about the algorithm and other parameters used for encryption, leave **cryptoParam** unspecified. In this case, the default encryption configuration is used. If you want to customize the encryption configuration or open an encrypted database that is not configured by default, set **cryptoParam**.

