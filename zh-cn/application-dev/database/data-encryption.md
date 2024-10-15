# 数据库加密


## 场景介绍

为了增强数据库的安全性，数据库提供了一个安全适用的数据库加密能力，从而对数据库存储的内容实施有效保护。通过数据库加密等安全方法实现了数据库数据存储的保密性和完整性要求，使得数据库以密文方式存储并在密态方式下工作，确保了数据安全。

加密后的数据库只能通过接口进行访问，无法通过其它方式打开数据库文件。数据库的加密属性在创建数据库时确认，无法变更。

键值型数据库和关系型数据库均支持数据库加密操作，其中关系型数据库支持自定义加密/解密的密钥和其他参数。


## 键值型数据库加密

键值型数据库，通过options中encrypt参数来设置是否加密，默认为false，表示不加密。encrypt参数为true时表示加密。

具体接口及功能，可见[分布式键值数据库](../reference/apis-arkdata/js-apis-distributedKVStore.md)。

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
      // 设置数据库加密
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
    //进行后续操作
    //...
}
```


## 关系型数据库加密

关系型数据库，通过[StoreConfig](../reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig)中encrypt属性来设置是否加密。encrypt参数为true时表示加密；为false时表示不加密；默认值为false。

当encrypt为true时，支持开发者通过可选属性cryptoParam设置自定义的加密/解密密钥和算法等参数。

针对cryptoParam的配置与否，有如下两种场景：

场景1：不配置cryptoParam属性，此时会使用默认的加密配置进行数据库的加密/解密。


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

场景2：配置cryptoParam属性，此时会使用开发者自定义的密钥和算法参数进行数据库的加密/解密。

```ts
import { relationalStore } from '@kit.ArkData';

let context = getContext(this);

// 初始化需要使用的密钥
let key = new Uint8Array(32);
for (let i = 0; i < 32; i++) {
    key[i] = i;
}

// 初始化加密算法
const CRYPTO_PARAM : relationalStore.CryptoParam = {
    encryptionKey: key, // 必选参数，使用指定的密钥打开加密数据库。
    iterationCount: 25000, // 可选参数，迭代次数。迭代次数必须大于零。不指定或等于零则使用默认值10000和默认加密算法。
    encryptionAlgo: relationalStore.EncryptionAlgo.AES_256_CBC, // 可选参数，加密/解密算法。如不指定，默认算法为AES_256_GCM。
    hmacAlgo: relationalStore.HmacAlgo.SHA256, // 可选参数，HMAC算法。如不指定，默认值为SHA256。
    kdfAlgo: relationalStore.KdfAlgo.KDF_SHA512, // 可选参数，KDF算法。如不指定，默认值和HMAC算法相等。
    cryptoPageSize: 2048 // 可选参数，加密/解密时使用的页大小。必须为512到65536范围内的整数并且为2的幂。如不指定，默认值为1024。
}

const STORE_CONFIG : relationalStore.StoreConfig = {
    name: "encrypted.db",
    securityLevel: relationalStore.SecurityLevel.S3,
    encrypt: true,
    cryptoParam: CRYPTO_PARAM
}

let store = await relationalStore.getRdbStore(context, STORE_CONFIG);
if (store == null) {
  console.error('Failed to get RdbStore.');
} else {
  console.info('Succeeded in getting RdbStore.');
}

// 调用完后需要将密钥清零
CRYPTO_PARAM.encryptionKey.fill(0);
```

如果开发者不关心加密使用的算法及参数，则无需配置cryptoParam属性，使用默认加密配置即可。当开发者需要自定义加密配置，或需要打开非默认配置的加密数据库时，则需要配置cryptoParam属性。
