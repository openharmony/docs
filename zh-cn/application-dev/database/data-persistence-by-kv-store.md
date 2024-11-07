# 通过键值型数据库实现数据持久化


## 场景介绍

键值型数据库存储键值对形式的数据，当需要存储的数据没有复杂的关系模型，比如存储商品名称及对应价格、员工工号及今日是否已出勤等，由于数据复杂度低，更容易兼容不同数据库版本和设备类型，因此推荐使用键值型数据库持久化此类数据。


## 约束限制

- 设备协同数据库，针对每条记录，Key的长度≤896 Byte，Value的长度&lt;4 MB。

- 单版本数据库，针对每条记录，Key的长度≤1 KB，Value的长度&lt;4 MB。

- 每个应用程序最多支持同时打开16个键值型分布式数据库。

- 键值型数据库事件回调方法中不允许进行阻塞操作，例如修改UI组件。


## 接口说明

以下是键值型数据库持久化功能的相关接口，大部分为异步接口。异步接口均有callback和Promise两种返回形式，下表均以callback形式为例，更多接口及使用方式请见[分布式键值数据库](../reference/apis-arkdata/js-apis-distributedKVStore.md)。

| 接口名称 | 描述 | 
| -------- | -------- |
| createKVManager(config: KVManagerConfig): KVManager | 创建一个KVManager对象实例，用于管理数据库对象。 | 
| getKVStore&lt;T&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void | 指定options和storeId，创建并得到指定类型的KVStore数据库。 | 
| put(key: string, value: Uint8Array \| string \| number \| boolean, callback: AsyncCallback&lt;void&gt;): void | 添加指定类型的键值对到数据库。 | 
| get(key: string, callback: AsyncCallback\<boolean \| string \| number \| Uint8Array>): void | 获取指定键的值。 | 
| delete(key: string, callback: AsyncCallback&lt;void&gt;): void | 从数据库中删除指定键值的数据。 | 


## 开发步骤

1. 若要使用键值型数据库，首先要获取一个KVManager实例，用于管理数据库对象。示例代码如下所示：

   Stage模型示例：

      
    ```js
    // 导入模块
    import { distributedKVStore } from '@kit.ArkData';
    
    // Stage模型
    import { window } from '@kit.ArkUI';
    import { UIAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    let kvManager: distributedKVStore.KVManager | undefined = undefined;
    
    export default class EntryAbility extends UIAbility {
      onCreate() {
        let context = this.context;
        const kvManagerConfig: distributedKVStore.KVManagerConfig = {
          context: context,
          bundleName: 'com.example.datamanagertest'
        };
        try {
          // 创建KVManager实例
          kvManager = distributedKVStore.createKVManager(kvManagerConfig);
          console.info('Succeeded in creating KVManager.');
          // 继续创建获取数据库
        } catch (e) {
          let error = e as BusinessError;
          console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
        }
      }
    }
    if (kvManager !== undefined) {
      kvManager = kvManager as distributedKVStore.KVManager;
      //进行后续操作
      //...
    }
    ```

   FA模型示例：

      
    ```js
    // 导入模块
    import { distributedKVStore } from '@kit.ArkData';
    
    // FA模型
    import { featureAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    let kvManager: distributedKVStore.KVManager | undefined = undefined;
    let context = featureAbility.getContext(); // 获取context
    const kvManagerConfig: distributedKVStore.KVManagerConfig = {
      context: context,
      bundleName: 'com.example.datamanagertest'
    };
    try {
      kvManager = distributedKVStore.createKVManager(kvManagerConfig);
      console.info('Succeeded in creating KVManager.');
      // 继续创建获取数据库
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
    }
    if (kvManager !== undefined) {
      kvManager = kvManager as distributedKVStore.KVManager;
      //进行后续操作
      //...
    }

    ```

2. 创建并获取键值数据库。示例代码如下所示：
     
    ```js
    let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
    try {
      const options: distributedKVStore.Options = {
        createIfMissing: true,
        encrypt: false,
        backup: false,
        autoSync: false,
        // kvStoreType不填时，默认创建多设备协同数据库
        kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
        // 多设备协同数据库：kvStoreType: distributedKVStore.KVStoreType.DEVICE_COLLABORATION,
        securityLevel: distributedKVStore.SecurityLevel.S3
      };
      kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options, (err, store: distributedKVStore.SingleKVStore) => {
        if (err) {
          console.error(`Failed to get KVStore: Code:${err.code},message:${err.message}`);
          return;
        }
        console.info('Succeeded in getting KVStore.');
        kvStore = store;
        // 请确保获取到键值数据库实例后，再进行相关数据操作
      });
    } catch (e) {
      let error = e as BusinessError;
      console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
    }
    if (kvStore !== undefined) {
      kvStore = kvStore as distributedKVStore.SingleKVStore;
      //进行后续操作
      //...
    }
    ```

3. 调用put()方法向键值数据库中插入数据。示例代码如下所示：
     
    ```js
    const KEY_TEST_STRING_ELEMENT = 'key_test_string';
    const VALUE_TEST_STRING_ELEMENT = 'value_test_string';
    try {
      kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
        if (err !== undefined) {
          console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
          return;
        }
        console.info('Succeeded in putting data.');
      });
    } catch (e) {
      let error = e as BusinessError;
      console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
    }
    ```

   > **说明：**
   >
   > 当Key值存在时，put()方法会修改其值，否则新增一条数据。

4. 调用get()方法获取指定键的值。示例代码如下所示：
     
    ```js
    try {
      kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
        if (err !== undefined) {
          console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
          return;
        }
        console.info('Succeeded in putting data.');
        kvStore = kvStore as distributedKVStore.SingleKVStore;
        kvStore.get(KEY_TEST_STRING_ELEMENT, (err, data) => {
          if (err != undefined) {
            console.error(`Failed to get data. Code:${err.code},message:${err.message}`);
            return;
          }
          console.info(`Succeeded in getting data. Data:${data}`);
        });
      });
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to get data. Code:${error.code},message:${error.message}`);
    }
    ```

5. 调用delete()方法删除指定键值的数据。示例代码如下所示：
     
    ```js
    try {
      kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
        if (err !== undefined) {
          console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
          return;
        }
        console.info('Succeeded in putting data.');
        kvStore = kvStore as distributedKVStore.SingleKVStore;
        kvStore.delete(KEY_TEST_STRING_ELEMENT, (err) => {
          if (err !== undefined) {
            console.error(`Failed to delete data. Code:${err.code},message:${err.message}`);
            return;
          }
          console.info('Succeeded in deleting data.');
        });
      });
    } catch (e) {
      let error = e as BusinessError;
      console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
    }
    ```

6. 通过storeId的值关闭指定的分布式键值数据库。示例代码如下所示：
     
    ```js
    let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
    const options: distributedKVStore.Options = {
      createIfMissing: true,
      encrypt: false,
      backup: false,
      autoSync: false,
      // kvStoreType不填时，默认创建多设备协同数据库
      kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
      // 多设备协同数据库：kvStoreType: distributedKVStore.KVStoreType.DEVICE_COLLABORATION,
      schema: undefined,
      securityLevel: distributedKVStore.SecurityLevel.S3
    };
    try {
      kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options, (err, store: distributedKVStore.SingleKVStore | undefined) => {
        if (err) {
          console.error(`Failed to get KVStore: Code:${err.code},message:${err.message}`);
          return;
        }
        console.info('Succeeded in getting KVStore.');
        kvStore = store;
        // 请确保获取到键值数据库实例后，再进行相关数据操作
        kvStore = undefined;
        store = undefined;
        kvManager = kvManager as distributedKVStore.KVManager;
        kvManager.closeKVStore('appId', 'storeId', (err: BusinessError)=> {
          if (err) {
            console.error(`Failed to close KVStore.code is ${err.code},message is ${err.message}`);
            return;
          }
          console.info('Succeeded in closing KVStore');
        });
      });
    } catch (e) {
      let error = e as BusinessError;
      console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
    }
    if (kvStore !== undefined) {
      kvStore = kvStore as distributedKVStore.SingleKVStore;
      //进行后续操作
      //...
    }
    ```

7. 通过storeId的值删除指定的分布式键值数据库。示例代码如下所示：
     
    ```js
    let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
    const options: distributedKVStore.Options = {
      createIfMissing: true,
      encrypt: false,
      backup: false,
      autoSync: false,
      // kvStoreType不填时，默认创建多设备协同数据库
      kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
      // 多设备协同数据库：kvStoreType: distributedKVStore.KVStoreType.DEVICE_COLLABORATION,
      schema: undefined,
      securityLevel: distributedKVStore.SecurityLevel.S3
    };
    try {
      kvManager.getKVStore<distributedKVStore.SingleKVStore>('storeId', options, (err, store: distributedKVStore.SingleKVStore | undefined) => {
        if (err) {
          console.error(`Failed to get KVStore: Code:${err.code},message:${err.message}`);
          return;
        }
        console.info('Succeeded in getting KVStore.');
        kvStore = store;
        // 请确保获取到键值数据库实例后，再进行相关数据操作
        kvStore = undefined;
        store = undefined;
        kvManager = kvManager as distributedKVStore.KVManager;
        kvManager.deleteKVStore('appId', 'storeId', (err: BusinessError) => {
          if (err != undefined) {
            console.error(`Failed to delete KVStore.code is ${err.code},message is ${err.message}`);
            return;
          }
          console.info(`Succeeded in deleting KVStore`);
        });
      });
    } catch (e) {
      let error = e as BusinessError;
      console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
    }
    if (kvStore !== undefined) {
      kvStore = kvStore as distributedKVStore.SingleKVStore;
      //进行后续操作
      //...
    }
    ```