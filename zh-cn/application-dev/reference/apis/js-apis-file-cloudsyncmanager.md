# @ohos.file.cloudSyncManager (端云同步管理能力)

该模块向云空间提供通知或更改端云服务状态的能力。

> **说明：**
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用。

## 导入模块

```js
import cloudSyncManager from '@ohos.file.cloudSyncManager';
```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise&lt;void&gt;;

异步方法修改应用的端云文件同步开关，以Promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 帐号|
| bundleName | string | 是   | 应用包名|
| status | boolean | 是   | 修改的应用云同步开关状态，true为打开，false为关闭|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回修改应用的端云文件同步开关的结果 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true).then(function() {
      console.info("changeAppCloudSwitch successfully");
  }).catch(function(err) {
      console.info("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean, callback: AsyncCallback&lt;void&gt;): void;

异步方法修改应用的端云文件同步开关，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 帐号|
| bundleName | string | 是   | 应用包名|
| status | boolean | 是   | 修改的应用云同步开关状态，true为打开，false为关闭|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步修改应用的端云文件同步开关之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true, (err) => {
    if (err) {
      console.info("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("changeAppCloudSwitch successfully");
    }
  });
  ```

## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string): Promise&lt;void&gt;;

异步方法通知端云服务应用的云数据变更，以Promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 帐号|
| bundleName | string | 是   | 应用包名|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回通知端云服务应用的云数据变更的结果 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName).then(function() {
      console.info("notifyDataChange successfully");
  }).catch(function(err) {
      console.info("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

异步方法通知端云服务应用的云数据变更，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 帐号|
| bundleName | string | 是   | 应用包名|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步通知端云服务应用的云数据变更之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**示例：**

  ```js
  let accountId = "testAccount";
  let bundleName = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName, (err) => {
    if (err) {
      console.info("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("notifyDataChange successfully");
    }
  });
  ```