# 数据库加密


## 场景介绍

为了增强数据库的安全性，数据库提供了一个安全适用的数据库加密能力，从而对数据库存储的内容实施有效保护。通过数据库加密等安全方法实现了数据库数据存储的保密性和完整性要求，使得数据库以密文方式存储并在密态方式下工作，确保了数据安全。

加密后的数据库只能通过接口进行访问，无法通过其它方式打开数据库文件。数据库的加密属性在创建数据库时确认，无法变更。

键值型数据库和关系型数据库均支持数据库加密操作。


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

关系型数据库，通过StoreConfig中encrypt属性来设置是否加密，默认为false，表示不加密。encrypt参数为true时表示加密。

具体接口及功能，可见[关系型数据库](../reference/apis-arkdata/js-apis-data-relationalStore.md)。

  
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
