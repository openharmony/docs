# 数据库加密


## 场景介绍

为了增强数据库的安全性，数据库提供了一个安全适用的数据库加密能力，从而对数据库存储的内容实施有效保护。通过数据库加密等安全方法实现了数据库数据存储的保密性和完整性要求，使得数据库以密文方式存储并在密态方式下工作，确保了数据安全。

加密后的数据库只能通过接口进行访问，无法通过其它方式打开数据库文件。数据库的加密属性在创建数据库时确认，无法变更。

键值型数据库和关系型数据库均支持数据库加密操作。


## 键值型数据库加密

键值型数据库，通过options中encrypt参数来设置是否加密，默认为false，表示不加密。encrypt参数为true时表示加密。

具体接口及功能，可见[分布式键值数据库](../reference/apis/js-apis-distributedKVStore.md)。

  
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
    // 设置数据库加密
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


## 关系型数据库加密

关系型数据库，通过StoreConfig中encrypt属性来设置是否加密，默认为false，表示不加密。encrypt参数为true时表示加密。

具体接口及功能，可见[关系型数据库](../reference/apis/js-apis-data-relationalStore.md)。

  
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
