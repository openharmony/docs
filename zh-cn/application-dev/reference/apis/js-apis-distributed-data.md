# 分布式数据管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import distributedData from '@ohos.data.distributedData';
```


## 权限

无


## distributedData.createKVManager

createKVManager(config: KVManagerConfig, callback: AsyncCallback&lt;KVManager&gt;): void

创建一个KVManager对象实例，用于管理数据库对象，并通过callback方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [KVManagerConfig](#kvmanagerconfig) | 是 | 提供KVManager实例的配置信息，包括调用方的包名和用户信息。 |
  | callback | AsyncCallback&lt;[KVManager](#kvmanager)&gt; | 是 | KVManager实例创建时调用的回调，返回KVManager对象实例。 |

- 示例：
  ```
  let kvManager;
  try {
      const kvManagerConfig = {
          bundleName : 'com.example.datamanagertest',
          userInfo : {
              userId : '0',
              userType : 0
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


## distributedData.createKVManager

createKVManager(config: KVManagerConfig): Promise&lt;KVManager&gt;

创建一个KVManager对象实例，用于管理数据库对象，并通过Promise方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [KVManagerConfig](#kvmanagerconfig) | 是 | 提供KVManager实例的配置信息，包括调用方的包名和用户信息。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[KVManager](#kvmanager)&gt; | 指定的Promise回调方法，返回创建的KVManager对象实例。 |

- 示例：
  ```
  let kvManager;
  try {
      const kvManagerConfig = {
          bundleName : 'com.example.datamanagertest',
          userInfo : {
              userId : '0',
              userType : 0
          }
      }
      distributedData.createKVManager(kvManagerConfig).then((manager) => {
          console.log("createKVManager success");
          kvManager = manager;
      }).catch((err) => {
          console.log("createKVManager err: "  + JSON.stringify(err));
      });
  } catch (e) {
      console.log("An unexpected error occurred. Error:" + e);
  }
  ```


## KVManagerConfig

提供KVManager实例的配置信息，包括调用方的包名和用户信息。

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| userInfo | [UserInfo](#userinfo) | 是 | 调用方的用户信息。 |
| bundleName | string | 是 | 调用方的包名。 |


## UserInfo

用户信息。

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| userId | string | 是 | 指示要设置的用户ID。 |
| userType | [UserType](#usertype) | 是 | 指示要设置的用户类型。 |


## UserType

用户类型。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SAME_USER_ID | 0 | 使用同一帐户登录不同设备的用户。 |


## KVManager

数据管理实例，用于获取KVStore的相关信息。在调用KVManager的方法前，需要先通过createKVManager构建一个KVManager实例。


### getKVStore

getKVStore&lt;T extends KVStore&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void

通过指定Options和storeId，创建并获取KVStore数据库，并通过callback方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | storeId | string | 是 | 数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#Constants)。 |
  | options | [Options](#options) | 是 | 创建KVStore实例的配置信息。 |
  | callback | AsyncCallback&lt;T&gt;，<br/>&lt;T&nbsp;extends&nbsp;KVStore&gt; | 是 | 创建KVStore实例的回调，返回KVStore对象实例。 |

- 示例：
  ```
  let kvStore;
  try {
      const options = {
          createIfMissing : true,
          encrypt : false,
          backup : false,
          autoSync : true,
          kvStoreType : 1,
          securityLevel : 3,
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


### getKVStore

getKVStore&lt;T extends KVStore&gt;(storeId: string, options: Options): Promise&lt;T&gt;

通过指定Options和storeId，创建并获取KVStore数据库，并通过Promise方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | storeId | string | 是 | 数据库唯一标识符，长度不大于[MAX_STORE_ID_LENGTH](#Constants)。 |
  | options | [Options](#options) | 是 | 创建KVStore实例的配置信息。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;T&gt;<br/>&lt;T&nbsp;extends&nbsp;KVStore&gt; | 指定的Promise回调方法，返回创建的KVStore数据库实例。 |

- 示例：
  ```
  let kvStore;
  try {
      const options = {
          createIfMissing : true,
          encrypt : false,
          backup : false,
          autoSync : true,
          kvStoreType : 1,
          securityLevel : 3,
      };
      kvManager.getKVStore('storeId', options).then((store) => {
          console.log("getKVStore success");
          kvStore = store;
      }).catch((err) => {
          console.log("getKVStore err: "  + JSON.stringify(err));
      });
  } catch (e) {
      console.log("An unexpected error occurred. Error:" + e);
  }
  ```


## Options

用于提供创建数据库的配置信息。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| createIfMissing | boolean | 否 | 当数据库文件不存在时是否创建数据库，默认创建。 |
| encrypt | boolean | 否 | 设置数据库文件是否加密，默认不加密。 |
| backup | boolean | 否 | 设置数据库文件是否备份，默认备份。 |
| autoSync | boolean | 否 | 设置数据库文件是否自动同步，默认不自动同步。 |
| kvStoreType | [KVStoreType](#kvstoretype) | 否 | 设置要创建的数据库类型，默认为多设备协同数据库。 |
| securityLevel | [SecurityLevel](#securitylevel) | 否 | 设置数据库安全级别，默认不设置安全级别。 |


## KVStoreType

用于指定创建的数据库的类型。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| DEVICE_COLLABORATION | 0 | 表示多设备协同数据库。 |
| SINGLE_VERSION | 1 | 表示单版本数据库。 |
| MULTI_VERSION | 2 | 表示多版本数据库。此类型当前不允许使用。 |


## SecurityLevel

用于指定创建的数据库的安全级别。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| NO_LEVEL | 0 | 表示数据库不设置安全级别。 |
| S0 | 1 | 表示数据库的安全级别为公共级别安全。 |
| S1 | 2 | 表示数据库的安全级别为低级别安全，当数据泄露时会产生较低影响。 |
| S2 | 3 | 表示数据库的安全级别为中级别安全，当数据泄露时会产生较大影响。 |
| S3 | 5 | 表示数据库的安全级别为高级别安全，当数据泄露时会产生重大影响。 |
| S4 | 6 | 表示数据库的安全级别为关键级别安全，当数据泄露时会产生严重影响。 |


## Constants

KVStore常量。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| MAX_KEY_LENGTH | 1024 | 数据库中Key允许最大长度，单位字节。 |
| MAX_VALUE_LENGTH | 4194303 | 数据库中Value允许的最大长度，单位字节。 |
| MAX_KEY_LENGTH_DEVICE | 896 | 最大设备坐标密钥长度。 |
| MAX_STORE_ID_LENGTH | 128 | 数据库标识符允许的最大长度，单位字节。 |
| MAX_QUERY_LENGTH | 512000 | 最大查询长度。 |
| MAX_BATCH_SIZE | 128 | 最大批处理操作大小。 |


## KVStore

KVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅同步完成的方法。在调用KVStore的方法前，需要先通过getKVStore构建一个KVStore实例。


### put

put(key: string, value: Uint8Array | string | number | boolean, callback: AsyncCallback&lt;void&gt;): void

添加指定类型键值对到数据库，并通过callback方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要添加数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#Constants)。 |
  | value | Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;boolean | 是 | 要添加数据的value，支持Uint8Array、number&nbsp;、&nbsp;string&nbsp;、boolean，<br/>Uint8Array、string&nbsp;的长度不大于[MAX_VALUE_LENGTH](#Constants)。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
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


### put

put(key: string, value: Uint8Array | string | number | boolean): Promise&lt;void&gt;

添加指定类型键值对到数据库，并通过Promise方式返回，此方法为异步方法。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要添加数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#Constants)。 |
  | value | Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;boolean | 是 | 要添加数据的value，支持Uint8Array、number&nbsp;、&nbsp;string&nbsp;、boolean，<br/>Uint8Array、string&nbsp;的长度不大于[MAX_VALUE_LENGTH](#Constants)。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步处理。 |


- 示例
  ```
  const KEY_TEST_STRING_ELEMENT = 'key_test_string';
  const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
  try {
      kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
          console.log("put success: " + JSON.stringify(data));
      }).catch((err) => {
          console.log("put err: " + JSON.stringify(err));
      });
  }catch (e) {
      console.log("An unexpected error occurred. Error:" + e);
  }
  ```


### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

从数据库中删除指定键值的数据，并通过callback方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要删除数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#Constants)。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  const KEY_TEST_STRING_ELEMENT = 'key_test_string';
  const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
  try {
      kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, function (err,data) {
          if (err != undefined) {
              console.log("put err: " + JSON.stringify(err));
              return;
          }
          console.log("put success");
          kvStore.delete(KEY_TEST_STRING_ELEMENT, function (err,data) {
              if (err != undefined) {
                  console.log("delete err: " + JSON.stringify(err));
                  return;
              }
              console.log("delete success");
          });
      });
  }catch (e) {
      console.log("An unexpected error occurred. Error:" + e);
  }
  ```


### delete

delete(key: string): Promise&lt;void&gt;

从数据库中删除指定键值的数据，并通过Promise方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要删除数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#Constants)。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise实例，用于异步处理。 |

- 示例
  ```
  const KEY_TEST_STRING_ELEMENT = 'key_test_string';
  const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
  try {
      kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
          console.log("put success: " + JSON.stringify(data));
          kvStore.delete(KEY_TEST_STRING_ELEMENT).then((data) => {
              console.log("delete success");
          }).catch((err) => {
              console.log("delete err: " + JSON.stringify(err));
          });
      }).catch((err) => {
          console.log("put err: " + JSON.stringify(err));
      });
  }catch (e) {
      console.log("An unexpected error occurred. Error:" + e);
  }
  ```


### on

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;ChangeNotification&gt;): void

订阅指定类型的数据变更通知，此方法为同步方法。

- 参数：
  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | event | 'dataChange' | 回调函数名称。 |
  | type | [SubscribeType](#subscribetype) | 表示订阅的类型。 |
  | observer | Callback&lt;[ChangeNotification](#changenotification)&gt; | 回调函数。 |

- 示例
  ```
  kvStore.on('dataChange', 2, function (data) {
      console.log("dataChange callback call data: " + JSON.stringify(data));
  });
  ```


### on

on(event: 'syncComplete', syncCallback: Callback&lt;Array&lt;[string, number]&gt;&gt;): void

订阅数据同步完成通知，此方法为同步方法。

- 参数：
  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | event | 'syncComplete' | 回调函数名称。 |
  | syncCallback | Callback&lt;Array&lt;[string,&nbsp;number]&gt;&gt; | 回调函数。 |

- 示例
  ```
  kvStore.on('syncComplete', function (data) {
      console.log("syncComplete callback call data: " + data);
  });
  ```


## SubscribeType

描述订阅类型。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SUBSCRIBE_TYPE_LOCAL | 0 | 表示订阅本地数据变更。 |
| SUBSCRIBE_TYPE_REMOTE | 1 | 表示订阅远端数据变更。 |
| SUBSCRIBE_TYPE_ALL | 2 | 表示订阅远端和本地数据变更。 |


## ChangeNotification

数据变更时通知的对象，包括数据插入的数据、更新的数据、删除的数据和设备ID。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| insertEntries | [Entry](#entry)[] | 是 | 是 | 数据添加记录。 |
| updateEntries | [Entry](#entry)[] | 是 | 是 | 数据更新记录。 |
| deleteEntries | [Entry](#entry)[] | 是 | 是 | 数据删除记录。 |
| deviceId | string | 是 | 是 | 设备ID，此处为设备UUID。 |


## Entry

存储在数据库中的键值对。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| key | string | 是 | 是 | 键值。 |
| value | [Value](#value) | 是 | 是 | 值对象。 |


## Value

存储在数据库中的对象。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| type | [ValueType](#valuetype) | 是 | 是 | 值类型。 |
| value | Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;boolean | 是 | 是 | 值，Uint8Array、string&nbsp;的长度不大于[MAX_VALUE_LENGTH](#Constants)。 |


## ValueType

用于表示数据类型。

只能被内部应用使用。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| STRING | 0 | 表示值类型为字符串。 |
| INTEGER | 1 | 表示值类型为整数。 |
| FLOAT | 2 | 表示值类型为浮点数。 |
| BYTE_ARRAY | 3 | 表示值类型为字节数组。 |
| BOOLEAN | 4 | 表示值类型为布尔值。 |
| DOUBLE | 5 | 表示值类型为双浮点数。 |


## SingleKVStore

单版本分布式数据库，继承自KVStore，提供查询数据和同步数据的方法。在调用SingleKVStore的方法前，需要先通过getKVStore构建一个KVStore实例。


### get

get(key: string, callback: AsyncCallback&lt;Uint8Array | string | boolean | number&gt;): void

获取指定键的值，并通过callback方式返回，此方法为异步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要查询数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#Constants)。 |
  | callback | AsyncCallback&lt;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;number&gt; | 是 | 回调函数，获取查询的值。 |

- 示例
  ```
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


### get

get(key: string): Promise&lt;Uint8Array | string | boolean | number&gt;

获取指定键的值，并通过Promise方式返回，此方法为异步方法。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 要查询数据的key，不能为空且长度不大于[MAX_KEY_LENGTH](#Constants)。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Uint8Array&nbsp;\|&nbsp;string&nbsp;\|&nbsp;boolean&nbsp;\|&nbsp;number&gt; | Promise实例，用于获取异步返回结果。 |


- 示例
  ```
  const KEY_TEST_STRING_ELEMENT = 'key_test_string';
  const VALUE_TEST_STRING_ELEMENT = 'value-test-string';
  try {
      kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT).then((data) => {
          console.log("put success: " + JSON.stringify(data));
          kvStore.get(KEY_TEST_STRING_ELEMENT).then((data) => {
              console.log("get success data: " + data);
          }).catch((err) => {
              console.log("get err: " + JSON.stringify(err));
          });
      }).catch((err) => {
          console.log("put err: " + JSON.stringify(err));
      });
  }catch (e) {
      console.log("An unexpected error occurred. Error:" + e);
  }
  ```


### sync

sync(deviceIdList: string[], mode: SyncMode, allowedDelayMs?: number): void

在手动同步模式下，触发数据库同步，此方法为同步方法。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceIdList | string[] | 是 | 同一组网环境下，需要同步的设备的deviceId列表。 |
  | mode | [SyncMode](#syncmode) | 是 | 同步类型。 |
  | allowedDelayMs | number | 否 | 可选参数，允许延时时间，单位：ms（毫秒）。 |

- 示例：
  ```
  kvStore.sync(deviceIds, 1, 1000);
  ```


## SyncMode

用于指定同步模式。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| PULL_ONLY | 0 | 表示只能从远端拉取数据到本端。 |
| PUSH_ONLY | 1 | 表示只能从本端推送数据到对端。 |
| PUSH_PULL | 2 | 表示从本端推送数据到远端，然后从远端拉取数据到本端。 |
