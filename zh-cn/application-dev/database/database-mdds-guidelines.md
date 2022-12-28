# 分布式数据服务开发指导

## 场景介绍

分布式数据服务主要实现用户设备中应用程序数据内容的分布式同步。当设备1上的应用A在分布式数据库中增、删、改数据后，设备2上的应用A也可以获取到该数据库变化。可在分布式图库、信息、通讯录、文件管理器等场景中使用。


## 接口说明

分布式数据相关功能接口请见[分布式键值数据库](../reference/apis/js-apis-distributedKVStore.md)。

**表1** 分布式数据服务关键API功能介绍

| 接口名称                                                     | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| createKVManager(config: KVManagerConfig, callback: AsyncCallback&lt;KVManager&gt;): void<br/>createKVManager(config: KVManagerConfig): Promise&lt;KVManager> | 创建一个`KVManager`对象实例，用于管理数据库对象。            |
| getKVStore&lt;TextendsKVStore&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void<br/>getKVStore&lt;TextendsKVStore&gt;(storeId: string, options: Options): Promise&lt;T&gt; | 指定`Options`和`storeId`，创建并获取指定类型`KVStore`数据库。 |
| put(key: string, value: Uint8Array\|string\|number\|boolean, callback: AsyncCallback&lt;void&gt;): void<br/>put(key: string, value: Uint8Array\|string\|number\|boolean): Promise&lt;void> | 插入和更新数据。                                             |
| delete(key: string, callback: AsyncCallback&lt;void&gt;): void<br/>delete(key: string): Promise&lt;void> | 删除数据。                                                   |
| get(key: string, callback: AsyncCallback&lt;Uint8Array\|string\|boolean\|number&gt;): void<br/>get(key: string): Promise&lt;Uint8Array\|string\|boolean\|number> | 查询数据。                                                   |
| on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;ChangeNotification&gt;): void<br/>on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string,number]&gt;&gt;): void | 订阅数据库中数据的变化。                                     |
| sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void | 在手动模式下，触发数据库同步。                               |

## 开发步骤

以单版本分布式数据库为例，说明开发步骤。

1. 导入模块。

   ```js
   import distributedKVStore from '@ohos.data.distributedKVStore';
   ```

2. 请求权限（同步操作时进行该步骤）。

   需要在`config.json`文件里进行配置请求权限（FA模型），示例代码如下：

    ```json
    {
      "module": {
          "reqPermissions": [
              {
                 "name": "ohos.permission.DISTRIBUTED_DATASYNC"
              }
          ]
      }
    }
    ```

   Stage模型下的权限请求请参见[权限声明-Stage模型](../security/accesstoken-guidelines.md#stage模型)。

   这个权限还需要在应用首次启动的时候弹窗获取用户授权，可以通过如下代码实现：

    ```js
    // FA模型
    import featureAbility from '@ohos.ability.featureAbility';
   
    function grantPermission() {
    console.info('grantPermission');
    let context = featureAbility.getContext();
    context.requestPermissionsFromUser(['ohos.permission.DISTRIBUTED_DATASYNC'], 666).then((data) => {
        console.info('success: ${data}');
    }).catch((error) => {
        console.info('failed: ${error}');
    })
    }
   
    grantPermission();
   
    // Stage模型
    import Ability from '@ohos.application.Ability';
   
    let context = null;
   
    function grantPermission() {
    class MainAbility extends Ability {
        onWindowStageCreate(windowStage) {
        let context = this.context;
        }
    }
   
    let permissions = ['ohos.permission.DISTRIBUTED_DATASYNC'];
    context.requestPermissionsFromUser(permissions).then((data) => {
        console.log('success: ${data}');
    }).catch((error) => {
        console.log('failed: ${error}');
    });
    }
   
    grantPermission();
    ```

3. 根据配置构造分布式数据库管理类实例。

   1. 根据应用上下文创建`kvManagerConfig`对象。
   2. 创建分布式数据库管理器实例。

   以下为创建分布式数据库管理器的代码示例：

   ```js
   // FA模型获取context
   import featureAbility from '@ohos.ability.featureAbility';
   let context = featureAbility.getContext();
   
   // Stage模型获取context
   import AbilityStage from '@ohos.application.Ability';
   let context = null;
   class MainAbility extends AbilityStage{
      onWindowStageCreate(windowStage){
        context = this.context;
      }
   }
   
   let kvManager;
   try {
     const kvManagerConfig = {
       bundleName: 'com.example.datamanagertest',
       context:context,
     }
     distributedKVStore.createKVManager(kvManagerConfig, function (err, manager) {
       if (err) {
         console.error(`Failed to createKVManager.code is ${err.code},message is ${err.message}`);
         return;
       }
       console.log('Succeeded in creating KVManager');
       kvManager = manager;
     });
   } catch (e) {
     console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
   }
   ```

4. 获取/创建分布式数据库。

   1. 声明需要创建的分布式数据库ID描述。
   2. 创建分布式数据库，建议关闭自动同步功能（`autoSync:false`），需要同步时主动调用`sync`接口。

   以下为创建分布式数据库的代码示例：

   ```js
   let kvStore;
   try {
     const options = {
       createIfMissing: true,
       encrypt: false,
       backup: false,
       autoSync: false,
       kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
       securityLevel: distributedKVStore.SecurityLevel.S1
     };
     kvManager.getKVStore('storeId', options, function (err, store) {
       if (err) {
         console.error(`Failed to get KVStore: code is ${err.code},message is ${err.message}`);
         return;
       }
       console.log('Succeeded in getting KVStore');
       kvStore = store;
     });
   } catch (e) {
     console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
   }
   ```

   > **说明：**
   >
   > 组网设备间同步数据的场景，建议在应用启动时打开分布式数据库，获取数据库的句柄。在该句柄（如示例中的`kvStore`）的生命周期内无需重复创建数据库，可直接使用句柄对数据库进行数据的插入等操作。

5. 订阅分布式数据变化。

   以下为订阅单版本分布式数据库数据变化通知的代码示例:

   ```js
   try{
       kvStore.on('dataChange', distributedKVStore.SubscribeType.SUBSCRIBE_TYPE_ALL, function (data) {
           console.log(`dataChange callback call data: ${data}`);
       });
   }catch(e){
       console.error(`An unexpected error occured.code is ${e.code},message is ${e.message}`);
   }
   ```

6. 将数据写入分布式数据库。

   1. 构造需要写入分布式数据库的`Key`（键）和`Value`（值）。
   2. 将键值数据写入分布式数据库。

   以下为将字符串类型键值数据写入分布式数据库的代码示例：

   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
   try {
       kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
           if (err != undefined) {
               console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
               return;
           }
           console.log("Succeeded in putting");
       });
   }catch (e) {
       console.error(`An unexpected error occurred.code is ${e.code},message is ${e.message}`);
   }
   ```

7. 查询分布式数据库数据。

   1. 构造需要从单版本分布式数据库中查询的`Key`（键）。
   2. 从单版本分布式数据库中获取数据。

   以下为从分布式数据库中查询字符串类型数据的代码示例：

   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
   try {
       kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
           if (err != undefined) {
               console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
               return;
           }
           console.log("Succeeded in putting");
           kvStore.get(KEY_TEST_STRING_ELEMENT, function (err,data) {
           if (err != undefined) {
               console.error(`Failed to get.code is ${err.code},message is ${err.message}`);
               return;
           }
               console.log(`Succeeded in getting data:${data}`);
           });
       });
   }catch (e) {
       console.error(`Failed to get.code is ${e.code},message is ${e.message}`);
   }
   ```

8. 同步数据到其他设备。

   选择同一组网环境下的设备以及同步模式，进行数据同步。

   > **说明**：
   >
   > 其中`deviceManager`模块的接口均为系统接口。

   以下为单版本分布式数据库进行数据同步的代码示例：

   ```js
   import deviceManager from '@ohos.distributedHardware.deviceManager';
   
   let devManager;
   // create deviceManager
   deviceManager.createDeviceManager('bundleName', (err, value) => {
       if (!err) {
           devManager = value;
           // deviceIds由deviceManager调用getTrustedDeviceListSync方法得到
           let deviceIds = [];
           if (devManager != null) {
               var devices = devManager.getTrustedDeviceListSync();
               for (var i = 0; i < devices.length; i++) {
                   deviceIds[i] = devices[i].deviceId;
               }
           }
           try{
               // 1000表示最大延迟时间为1000ms
               kvStore.sync(deviceIds, distributedKVStore.SyncMode.PUSH_ONLY, 1000);
           } catch (e) {
                console.error(`An unexpected error occurred. code is ${e.code},message is ${e.message}`);
           }
       }
   });
   ```

## 相关实例

针对分布式数据开发，有以下相关实例可供参考：

- [`DistributedCalc`：分布式计算器（JS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/common/DistributeCalc)
- [`DistributedCalc`：分布式计算器（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/Preset/DistributeCalc)
- [`DistributedDataGobang`：分布式五子棋（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/data/DistributedDataGobang)
- [`DDMQuery`：结果集与谓词（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/data/DDMQuery)
- [`KvStore`：分布式数据库（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/data/Kvstore)
- [分布式数据库（JS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Data/JsDistributedData)