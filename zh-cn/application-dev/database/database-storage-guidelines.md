# 轻量级数据存储开发指导

## 场景介绍

轻量级数据存储功能通常用于保存应用的一些常用配置信息，并不适合需要存储大量数据和频繁改变数据的场景。应用的数据保存在文件中，这些文件可以持久化地存储在设备上。需要注意的是，应用访问的实例包含文件所有数据，这些数据会一直加载在设备的内存中，直到应用主动从内存中将其移除前，应用可以通过Storage的API进行数据操作。

## 接口说明

轻量级存储为应用提供key-value键值型的文件数据处理能力，支持应用对数据进行轻量级存储及查询。数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括数字型、字符型、布尔型。

**创建存储实例**

读取指定文件，将数据加载到Storage实例，即可创建一个存储实例，用于数据操作。

**表1** 轻量级数据存储实例创建接口

| 包名              | 接口名                                      | 描述                                        |
| ----------------- | ------------------------------------------- | ------------------------------------------- |
| ohos.data.storage | getStorage(path: string): Promise\<Storage> | 获取文件对应的Storage单实例，用于数据操作。 |

**存入数据**

通过put系列方法，可以增加或修改Storage实例中的数据。

**表2** 轻量级数据存入接口

| 类名    | 接口名                                             | 描述                                            |
| ------- | -------------------------------------------------- | ----------------------------------------------- |
| Storage | put(key: string, value: ValueType): Promise\<void> | 支持值为number、string、boolean类型的数据存入。 |

**读取数据**

通过调用get系列方法，可以读取Storage中的数据。

**表3** 轻量级数据读取接口

| 类名    | 接口名                                                     | 描述                                            |
| ------- | ---------------------------------------------------------- | ----------------------------------------------- |
| Storage | get(key: string, defValue: ValueType): Promise\<ValueType> | 支持获取值为number、string、boolean类型的数据。 |

**数据持久化**

通过执行flush方法，应用可以将缓存的数据再次写回文本文件中进行持久化存储。

**表4** 轻量级数据持久化接口

| 类名    | 接口名                  | 描述                                    |
| ------- | ----------------------- | --------------------------------------- |
| Storage | flush(): Promise\<void> | 将Storage实例通过异步线程回写入文件中。 |

**订阅数据变化**

订阅数据变化需要指定StorageObserver作为回调方法。订阅的key的值发生变更后，当执行flush方法时，StorageObserver被回调。

**表5** 轻量级数据变化订阅接口

| 类名    | 接口名                                                       | 描述           |
| ------- | ------------------------------------------------------------ | -------------- |
| Storage | on(type: 'change', callback: Callback\<StorageObserver>): void | 订阅数据变化。 |
| Storage | off(type: 'change', callback: Callback\<StorageObserver>): void | 注销订阅。     |

**删除数据文件**

通过调用以下两种接口，可以删除数据实例或对应的文件。

**表6** 轻量级数据存储删除接口

| 包名              | 接口名                                               | 描述                                                         |
| ----------------- | ---------------------------------------------------- | ------------------------------------------------------------ |
| ohos.data.storage | deleteStorage(path: string): Promise\<void>          | 从缓存中移除已加载的Storage对象，同时从设备上删除对应的文件。 |
| ohos.data.storage | removeStorageFromCache(path: string): Promise\<void> | 仅从缓存中移除已加载的Storage对象，主要用于释放内存。        |

## 开发步骤

1. 准备工作，导入@ohos.data.storage以及相关的模块到开发环境。

   ```js
   import dataStorage from '@ohos.data.storage'
   import featureAbility from '@ohos.ability.featureAbility'  // 用于获取文件存储路径
   ```

2. 获取Storage实例。

   读取指定文件，将数据加载到Storage实例，用于数据操作。
   ```js
   var context = featureAbility.getContext()
   context.getFilesDir().then(() => {
    console.info("======================>getFilesDirPromsie====================>");
   });

   let promise = dataStorage.getStorage(path + '/mystore')
   ```

3. 存入数据。

   使用Storage put方法保存数据到缓存的实例中。

   ```js
   promise.then((storage) => {
       let getPromise = storage.put('startup', 'auto') // 保存数据到缓存的storage示例中。
       getPromise.then(() => {
           console.info("Put the value of startup successfully.")
       }).catch((err) => {
           console.info("Put the value of startup failed with err: " + err)
       })
   }).catch((err) => {
       console.info("Get the storage failed")
   })
   ```

4. 读取数据。

   使用Storage get方法读取数据。

   ```js
   promise.then((storage) => {
       let getPromise = storage.get('startup', 'default')
       getPromise.then((value) => {
           console.info("The value of startup is " + value)
       }).catch((err) => {
           console.info("Get the value of startup failed with err: " + err)
       })
   }).catch((err) => {
       console.info("Get the storage failed")})
   ```

5. 数据持久化。

   应用存入数据到Storage实例后，可以通过flush或者flushSync方法将Storage实例回写到文件中。

   ```js
   storage.flush();
   ```

6. 订阅数据变化。

   应用订阅数据变化需要指定StorageObserver作为回调方法。订阅的key的值发生变更后，当执行flush方法时，StorageObserver被触发回调。不再需要StorageObserver时请注销。

   ```js
   promise.then((storage) => {
       var observer = function (key) {
           console.info("The key of " + key + " changed.")
       }
       storage.on('change', observer)
       storage.putSync('startup', 'auto')  // 修改storage存储数据
       storage.flushSync()  // 触发订阅者回调方法
   
       storage.off('change', observer) // 注销数据变化订阅
   }).catch((err) => {
       console.info("Get the storage failed")
   })
   ```

7. 删除指定文件。

   使用deleteStorage方法从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。删除后，数据及文件将不可恢复。

   ```js
   let promise = dataStorage.deleteStorage(path + '/mystore')
   promise.then(() => {
       console.info("Deleted successfully.")
   }).catch((err) => {
       console.info("Deleted failed with err: " + err)})
   ```
## 相关实例
针对轻量级数据存储开发，有以下相关实例可供参考：
- [`LiteStorage`：轻量级存储（eTS）（API7）](https://gitee.com/openharmony/app_samples/tree/master/data/LiteStorage)
- [轻量级偏好数据库](https://gitee.com/openharmony/codelabs/tree/master/Data/Database)
- [备忘录（eTS）](https://gitee.com/openharmony/codelabs/tree/master/Data/NotePad_OH_ETS)