# 首选项开发指导

## 场景介绍

首选项功能通常用于保存应用的一些常用配置信息，并不适合需要存储大量数据和频繁改变数据的场景。应用的数据保存在文件中，这些文件可以持久化地存储在设备上。需要注意的是，应用访问的实例包含文件所有数据，这些数据会一直加载在设备的内存中，直到应用主动从内存中将其移除前，应用都可以通过Preferences API进行相关数据操作。

## 接口说明

首选项为应用提供key-value键值型的文件数据处理能力，支持应用持久化轻量级数据，并对其修改和查询。数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括数字型、字符型、布尔型。

### 创建存储实例

读取指定文件，将数据加载到Preferences实例，即可创建一个存储实例，用于数据操作。

**表1** 首选项实例创建接口

| 包名              | 接口名                                      | 描述                                        |
| ----------------- | ------------------------------------------- | ------------------------------------------- |
| ohos.data.preferences | getPreferences(context: Context, name: string): Promise\<Preferences> | 读取指定首选项持久化文件，将数据加载到Preferences实例，用于数据操作。 |

### 存入数据

通过put系列方法，可以增加或修改Preferences实例中的数据。

**表2** 首选项存入接口

| 类名    | 接口名                                             | 描述                                            |
| ------- | -------------------------------------------------- | ----------------------------------------------- |
| Preferences | put(key: string, value: ValueType): Promise\<void> | 支持值为number、string、boolean类型的数据存入，同时也支持Array<number>、Array<string>、Array<boolean>三种类型的数组的存入。 |

### 读取数据

通过调用get系列方法，可以读取Preferences中的数据。

**表3** 首选项读取接口

| 类名    | 接口名                                                     | 描述                                            |
| ------- | ---------------------------------------------------------- | ----------------------------------------------- |
| Preferences | get(key: string, defValue: ValueType): Promise\<ValueType> | 支持获取值为number、string、boolean类型的数据，同时也支持获取值为Array<number>、Array<string>、Array<boolean>三种数组类型的数据。 |

### 数据持久化

通过执行flush方法，应用可以将缓存的数据再次写回文本文件中进行持久化存储。

**表4** 首选项持久化接口

| 类名    | 接口名                  | 描述                                    |
| ------- | ----------------------- | --------------------------------------- |
| Preferences | flush(): Promise\<void> | 将Preferences实例通过异步线程回写入文件中。 |

### 订阅数据变化

订阅数据变更者类，订阅的key的值发生变更后，在执行flush方法后，会执行callback回调。

**表5** 首选项变化订阅接口

| 类名    | 接口名                                                       | 描述           |
| ------- | ------------------------------------------------------------ | -------------- |
| Preferences | on(type: 'change', callback: Callback<{ key : string }>): void | 订阅数据变化。 |
| Preferences | off(type: 'change', callback: Callback<{ key : string }>): void | 注销订阅。     |

### 删除数据文件

通过调用以下两种接口，可以删除数据实例或对应的文件。

**表6** 首选项删除接口

| 包名              | 接口名                                               | 描述                                                         |
| ----------------- | ---------------------------------------------------- | ------------------------------------------------------------ |
| ohos.data.preferences | deletePreferences(context: Context, name: string): Promise<void>;     | 从缓存中移除已加载的Preferences对象，同时从设备上删除对应的文件。 |
| ohos.data.preferences | removePreferencesFromCache(context: Context, name: string): Promise\<void>; | 仅从缓存中移除已加载的Preferences对象，主要用于释放内存。

## 开发步骤

1. 准备工作，导入@ohos.data.preferences以及相关的模块到开发环境。

   ```js
   import preferences from '@ohos.data.preferences'
   ```

2. 获取Preferences实例。

   读取指定文件，将数据加载到Preferences实例，用于数据操作。
   ```js
   let promise = preferences.getPreferences(this.context, 'mystore')
   ```

3. 存入数据。

   使用Preferences put方法保存数据到缓存的实例中。

   ```js
   promise.then((pref) => {
       let putPromise = pref.put('startup', 'auto')
       putPromise.then(() => {
           console.info("Put the value of startup successfully.")
       }).catch((err) => {
           console.info("Put the value of startup failed with err: " + err)
       })
   }).catch((err) => {
       console.info("Get the storage failed")
   })
   ```

4. 读取数据。

   使用Preferences get方法读取数据。

   ```js
   promise.then((pref) => {
       let getPromise = pref.get('startup', 'default')
       getPromise.then((value) => {
           console.info("The value of startup is " + value)
       }).catch((err) => {
           console.info("Get the value of startup failed with err: " + err)
       })
   }).catch((err) => {
       console.info("Get the storage failed")})
   ```

5. 数据持久化。

   应用存入数据到Preferences实例后，可以通过flush方法将Preferences实例回写到文件中。

   ```js
   pref.flush();
   ```

6. 订阅数据变化。

   应用订阅数据变化需要指定observer作为回调方法。订阅的key的值发生变更后，当执行flush方法时，observer被触发回调。

   ```js
    var observer = function (key) {
        console.info("The key of " + key + " changed.")
    }
    pref.on('change', observer)
    pref.put('startup', 'auto', function (err) {
        if (err) {
            console.info("Put the value of startup failed with err: " + err)
            return
        }
        console.info("Put the value of startup successfully.")
        pref.flush(function (err) {
            if (err) {
                console.info("Flush to file failed with err: " + err)
                return
            }
            console.info("Flushed to file successfully.")    // observer will be called.
        })
    })
   ```

7. 删除指定文件。

   使用deletePreferences方法从内存中移除指定文件对应的Preferences单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。删除后，数据及文件将不可恢复。

   ```js
    let deletePromise = preferences.deletePreferences(context, 'mystore')
    deletePromise.then(() => {
        console.info("Deleted successfully.")
    }).catch((err) => {
        console.info("Deleted failed with err: " + err)
    })
   ```
