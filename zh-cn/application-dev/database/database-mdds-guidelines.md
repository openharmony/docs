# 分布式数据服务开发指导

## 场景介绍

分布式数据服务主要实现用户设备中应用程序数据内容的分布式同步。当设备1上的应用A在分布式数据库中增、删、改数据后，设备2上的应用A也可以获取到该数据库变化。可在分布式图库、信息、通讯录、文件管理器等场景中使用。


## 接口说明
具体分布式数据相关功能接口请见[分布式数据管理](../reference/apis/js-apis-distributed-data.md)。

OpenHarmony系统中的分布式数据服务模块为开发者提供下面几种功能：

**表1** 分布式数据服务关键API功能介绍

| 功能分类                   | 接口名称                                                     | 描述                                            |
| -------------------------- | ------------------------------------------------------------ | ----------------------------------------------- |
| 分布式数据库创建。         | createKVManager(config:&nbsp;KVManagerConfig,&nbsp;callback:&nbsp;AsyncCallback&lt;KVManager&gt;):&nbsp;void<br/>createKVManager(config:&nbsp;KVManagerConfig):&nbsp;Promise&lt;KVManager> | 创建一个KVManager对象实例，用于管理数据库对象。 |
| 分布式数据库创建。         | getKVStore&lt;T&nbsp;extends&nbsp;KVStore&gt;(storeId:&nbsp;string,&nbsp;options:&nbsp;Options,&nbsp;callback:&nbsp;AsyncCallback&lt;T&gt;):&nbsp;void<br/>getKVStore&lt;T&nbsp;extends&nbsp;KVStore&gt;(storeId:&nbsp;string,&nbsp;options:&nbsp;Options):&nbsp;Promise&lt;T&gt; | 指定Options和storeId，创建并获取KVStore数据库。 |
| 分布式数据增、删、改、查。 | put(key:&nbsp;string,&nbsp;value:&nbsp;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;boolean,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br/>put(key:&nbsp;string,&nbsp;value:&nbsp;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;boolean):&nbsp;Promise&lt;void> | 插入和更新数据。                                |
| 分布式数据增、删、改、查。 | delete(key:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br/>delete(key:&nbsp;string):&nbsp;Promise&lt;void> | 删除数据。                                      |
| 分布式数据增、删、改、查。 | get(key:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;number&gt;):&nbsp;void<br/>get(key:&nbsp;string):&nbsp;Promise&lt;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;number> | 查询数据。                                      |
| 订阅分布式数据变化。       | on(event:&nbsp;'dataChange',&nbsp;type:&nbsp;SubscribeType,&nbsp;observer:&nbsp;Callback&lt;ChangeNotification&gt;):&nbsp;void<br/>on(event:&nbsp;'syncComplete',&nbsp;syncCallback:&nbsp;Callback&lt;Array&lt;[string,&nbsp;number]&gt;&gt;):&nbsp;void | 订阅数据库中数据的变化。                        |
| 分布式数据同步。           | sync(deviceIdList:&nbsp;string[],&nbsp;mode:&nbsp;SyncMode,&nbsp;allowedDelayMs?:&nbsp;number):&nbsp;void | 在手动模式下，触发数据库同步。                  |




## 开发步骤

以单版本分布式数据库为例，说明开发步骤。

1. 导入模块。
   ```js
   import distributedData from '@ohos.data.distributedData';
   ```

2. 根据配置构造分布式数据库管理类实例。
   1. 根据应用上下文创建KvManagerConfig对象。
   2. 创建分布式数据库管理器实例。

   以下为创建分布式数据库管理器的代码示例：
   ```js
   let kvManager;
   try {
       const kvManagerConfig = {
           bundleName : 'com.example.datamanagertest',
           userInfo : {
               userId : '0',
               userType : distributedData.UserType.SAME_USER_ID
           }
       }
       distributedData.createKVManager(kvManagerConfig, function (err, manager) {
           if (err) {
               console.log("createKVManager err: "  + JSON.stringify(err));
               return;
           }
           console.log("createKVManager success");
           kvManager = manager;
       });
   } catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

3. 获取/创建分布式数据库。
   1. 声明需要创建的分布式数据库ID描述。
   2. 创建分布式数据库，建议关闭自动同步功能(autoSync:false)，需要同步时主动调用sync接口。

   以下为创建分布式数据库的代码示例：
   ```js
   let kvStore;
   try {
       const options = {
           createIfMissing : true,
           encrypt : false,
           backup : false,
           autoSync : false,
           kvStoreType : distributedData.KVStoreType.SINGLE_VERSION,
           securityLevel : distributedData.SecurityLevel.S0,
       };
       kvManager.getKVStore('storeId', options, function (err, store) {
           if (err) {
               console.log("getKVStore err: "  + JSON.stringify(err));
               return;
           }
           console.log("getKVStore success");
           kvStore = store;
       });
   } catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 组网设备间同步数据的场景，建议在应用启动时打开分布式数据库，获取数据库的句柄。在该句柄（如上例中的kvStore）的生命周期内无需重复创建数据库，可直接使用句柄对数据库进行数据的插入等操作。

4. 订阅分布式数据变化。
   以下为订阅单版本分布式数据库数据变化通知的代码示例:
   ```js
   kvStore.on('dataChange', distributedData.SubscribeType.SUBSCRIBE_TYPE_ALL, function (data) {
       console.log("dataChange callback call data: " + JSON.stringify(data));
   });
   ```

5. 将数据写入分布式数据库。
   1. 构造需要写入分布式数据库的Key(键)和Value(值)。
   2. 将键值数据写入分布式数据库。

   以下为将字符串类型键值数据写入分布式数据库的代码示例：

   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
   try {
       kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
           if (err != undefined) {
               console.log("put err: " + JSON.stringify(err));
               return;
           }
           console.log("put success");
       });
   }catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

6. 查询分布式数据库数据。
   1. 构造需要从单版本分布式数据库中查询的Key(键)。
   2. 从单版本分布式数据库中获取数据。

   以下为从分布式数据库中查询字符串类型数据的代码示例：
   ```js
   const KEY_TEST_STRING_ELEMENT = 'key_test_string';
   const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
   try {
       kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
           if (err != undefined) {
               console.log("put err: " + JSON.stringify(err));
               return;
           }
           console.log("put success");
           kvStore.get(KEY_TEST_STRING_ELEMENT, function (err,data) {
               console.log("get success data: " + data);
           });
       });
   }catch (e) {
       console.log("An unexpected error occurred. Error:" + e);
   }
   ```

7. 同步数据到其他设备。
   1.选择同一组网环境下的设备以及同步模式，进行数据同步。

   以下为单版本分布式数据库进行数据同步的代码示例，其中deviceIds可由deviceManager调用getTrustedDeviceListSync()方法得到，1000表示最大延迟时间为1000ms：
   ```js
   import deviceManager from '@ohos.distributedHardware.deviceManager';
   
   let devManager;
   // create deviceManager
   deviceManager.createDeviceManager("bundleName", (err, value) => {
       if (!err) {
           devManager = value;
           // get deviceIds
           let deviceIds = [];
           if (devManager != null) {
               var devices = devManager.getTrustedDeviceListSync();
               for (var i = 0; i < devices.length; i++) {
                   deviceIds[i] = devices[i].deviceId;
               }
           }
           try{
               kvStore.sync(deviceIds, distributedData.SyncMode.PUSH_ONLY, 1000);
           }catch (e) {
                console.log("An unexpected error occurred. Error:" + e);
           }
       }
   });
   ```
## 相关实例
针对分布式数据开发，有以下相关实例可供参考：
- [`KvStore`：分布式数据库（eTS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/data/Kvstore)
- [分布式数据库](https://gitee.com/openharmony/codelabs/tree/master/Data/JsDistributedData)
