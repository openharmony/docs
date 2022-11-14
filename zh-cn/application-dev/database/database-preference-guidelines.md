# 首选项开发指导

> **说明：**
>
> 该功能特性从API Version 9开始支持。API Version 9之前可使用[轻量级存储](../reference/apis/js-apis-data-storage.md)的相关功能接口。

## 场景介绍

首选项功能通常用于保存应用的一些常用配置信息，并不适合需要存储大量数据和频繁改变数据的场景。应用的数据保存在文件中，这些文件可以持久化地存储在设备上。

需要注意的是，应用访问的实例包含文件所有数据，这些数据会一直加载在设备的内存中，直到应用主动从内存中将其移除前，应用都可以通过Preferences API进行相关数据操作。

## 接口说明

首选项为应用提供Key-Value键值型的文件数据处理能力，支持应用持久化轻量级数据，并对其修改和查询。

数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括数字型、字符型、布尔型以及这3种类型的数组类型。

更多首选项相关接口，请见[首选项API](../reference/apis/js-apis-data-preferences.md)。

### 创建存储实例

读取指定文件，将数据加载到Preferences实例，即可创建一个存储实例，用于数据操作。

**表1** 首选项实例创建接口

| 包名                  | 接口名                                                       | 描述                                                         |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.data.preferences | getPreferences(context: Context, name: string): Promise\<Preferences> | 读取指定首选项持久化文件，将数据加载到Preferences实例，用于数据操作。 |

### 数据处理

通过put系列方法，可以增加或修改Preferences实例中的数据。

通过调用get系列方法，可以读取Preferences中的数据。

通过调用getAll系列方法，可以获取Preferences中包含所有键值的Object对象。

通过调用delete系列方法，可以删除Preferences中名为给定Key的存储键值对。

**表2** 首选项数据处理接口

| 类名        | 接口名                                                     | 描述                                                         |
| ----------- | ---------------------------------------------------------- | ------------------------------------------------------------ |
| Preferences | put(key: string, value: ValueType): Promise\<void>         | 支持存入值为number、string、boolean、Array\<number>、Array\<string>、Array\<boolean>类型的数据。 |
| Preferences | get(key: string, defValue: ValueType): Promise\<ValueType> | 支持获取值为number、string、boolean、Array\<number>、Array\<string>、Array\<boolean>类型的数据。 |
| Preferences | getAll(): Promise\<Object>                                  | 支持获取含有所有键值的Object对象。                           |
| Preferences | delete(key: string): Promise\<void>                         | 支持从Preferences实例中删除名为给定Key的存储键值对。         |


### 数据持久化

通过执行flush方法，应用可以将缓存的数据再次写回文本文件中进行持久化存储。

**表4** 首选项持久化接口

| 类名        | 接口名                  | 描述                                        |
| ----------- | ----------------------- | ------------------------------------------- |
| Preferences | flush(): Promise\<void> | 将Preferences实例通过异步线程回写入文件中。 |

### 订阅数据变更

订阅数据变更，订阅的Key的值发生变更后，在执行flush方法后，会触发callback回调。

**表5** 首选项变化订阅接口

| 类名        | 接口名                                                       | 描述           |
| ----------- | ------------------------------------------------------------ | -------------- |
| Preferences | on(type: 'change', callback: Callback<{ key : string }>): void | 订阅数据变更。 |
| Preferences | off(type: 'change', callback: Callback<{ key : string }>): void | 注销订阅。     |

### 删除数据文件

通过调用以下两种接口，可以删除数据实例或对应的文件。

**表6** 首选项删除接口

| 包名                  | 接口名                                                       | 描述                                                         |
| --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.data.preferences | deletePreferences(context: Context, name: string): Promise\<void> | 从缓存中移除已加载的Preferences对象，同时从设备上删除对应的文件。 |
| ohos.data.preferences | removePreferencesFromCache(context: Context, name: string): Promise\<void> | 仅从缓存中移除已加载的Preferences对象，主要用于释放内存。    |

## 开发步骤

1. 准备工作，导入@ohos.data.preferences以及相关的模块到开发环境。

   ```js
   import data_preferences from '@ohos.data.preferences';
   ```

2. 获取Preferences实例。

   读取指定文件，将数据加载到Preferences实例，用于数据操作。

   FA模型示例：

   ```js
   // 获取context
   import featureAbility from '@ohos.ability.featureAbility'
   let context = featureAbility.getContext();
   
   let preferences = null;
   let promise = data_preferences.getPreferences(context, 'mystore');
   
   promise.then((pref) => {
       preferences = pref;
   }).catch((err) => {
       console.info("Failed to get preferences.");
   })
   ```

   Stage模型示例：

   ```ts
   // 获取context
   import Ability from '@ohos.application.Ability'
   let context = null;
   let preferences = null;
   export default class MainAbility extends Ability {
       onWindowStageCreate(windowStage){
           context = this.context;
       }
   }
   
   let promise = data_preferences.getPreferences(context, 'mystore');
   
   promise.then((pref) => {
       preferences = pref;
   }).catch((err) => {
       console.info("Failed to get preferences.");
   })
   ```

3. 存入数据。

   使用put方法保存数据到缓存的实例中。

   ```js
   let putPromise = preferences.put('startup', 'auto');
   putPromise.then(() => {
       console.info("Succeeded in putting the value of 'startup'.");
   }).catch((err) => {
       console.info("Failed to put the value of 'startup'. Cause: " + err);
   })
   ```
   
4. 读取数据。

   使用get方法读取数据。

   ```js
   let getPromise = preferences.get('startup', 'default');
   getPromise.then((value) => {
       console.info("The value of 'startup' is " + value);
   }).catch((err) => {
       console.info("Failed to get the value of 'startup'. Cause: " + err);
   })
   ```
   
5. 数据持久化。

   应用存入数据到Preferences实例后，可以通过flush方法将Preferences实例回写到文件中。

   ```js
   preferences.flush();
   ```

6. 订阅数据变更。

   应用订阅数据变更需要指定observer作为回调方法。订阅的Key的值发生变更后，当执行flush方法时，observer被触发回调。

   ```js
   let observer = function (key) {
       console.info("The key" + key + " changed.");
   }
   preferences.on('change', observer);
   // 数据产生变更，由'auto'变为'manual'
   preferences.put('startup', 'manual', function (err) {
       if (err) {
           console.info("Failed to put the value of 'startup'. Cause: " + err);
           return;
       }
       console.info("Succeeded in putting the value of 'startup'.");
       preferences.flush(function (err) {
           if (err) {
               console.info("Failed to flush. Cause: " + err);
               return;
           }
           console.info("Succeeded in flushing."); // observer will be called.
       })
   })
   ```

7. 删除指定文件。

   使用deletePreferences方法从内存中移除指定文件对应的Preferences单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。删除后，数据及文件将不可恢复。

   ```js
   let proDelete = data_preferences.deletePreferences(context, 'mystore');
   proDelete.then(() => {
       console.info("Succeeded in deleting.");
   }).catch((err) => {
       console.info("Failed to delete. Cause: " + err);
   })
   ```

## 相关实例

针对首选项开发，有以下相关实例可供参考：

- [`Preferences`：首选项（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/data/Preferences)