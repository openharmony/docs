# @ohos.file.cloudSyncManager (端云同步管理能力)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @zsyztt; @Hermits; @reminder2352-->
<!--Designer: @yunlanying-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @foryourself-->

该模块向云空间应用提供端云同步管理能力：包括使能/去使能端云协同能力、修改应用同步开关，云端数据变化通知以及账号退出清理/保留云相关文件等。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.cloudSyncManager (端云同步管理能力)](js-apis-file-cloudsyncmanager.md)。

## 导入模块

```ts
import { cloudSyncManager } from '@kit.CoreFileKit';
```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise&lt;void&gt;

异步方法修改应用的端云文件同步开关，以Promise形式返回结果。

**系统接口**：该接口为系统接口。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。 |
| bundleName | string | 是   | 应用包名。|
| status | boolean | 是   | 修改的应用云同步开关状态。true为打开；false为关闭。|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回修改应用的端云文件同步开关的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true).then(() => {
    console.info("changeAppCloudSwitch successfully");
  }).catch((err: BusinessError) => {
    console.error("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.changeAppCloudSwitch

changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean, callback: AsyncCallback&lt;void&gt;): void

异步方法修改应用的端云文件同步开关，以callback形式返回结果。

**系统接口**：该接口为系统接口。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| bundleName | string | 是   | 应用包名|
| status | boolean | 是   | 修改的应用云同步开关状态。true为打开；false为关闭。|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步修改应用的端云文件同步开关之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true, (err: BusinessError) => {
    if (err) {
      console.error("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("changeAppCloudSwitch successfully");
    }
  });
  ```

## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string): Promise&lt;void&gt;

异步方法通知端云服务应用的云数据变更，以Promise形式返回结果。

**系统接口**：该接口为系统接口。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| bundleName | string | 是   | 应用包名。|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回通知端云服务应用的云数据变更的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName).then(() => {
    console.info("notifyDataChange successfully");
  }).catch((err: BusinessError) => {
    console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.notifyDataChange

notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

异步方法通知端云服务应用的云数据变更，以callback形式返回结果。

**系统接口**：该接口为系统接口。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| bundleName | string | 是   | 应用包名。|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步通知端云服务应用的云数据变更之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let bundleName: string = "com.example.bundle";
  cloudSyncManager.notifyDataChange(accountId, bundleName, (err: BusinessError) => {
    if (err) {
      console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("notifyDataChange successfully");
    }
  });
  ```

## ExtraData<sup>11+</sup>

云端数据变更信息。

**系统接口**：该接口为系统接口。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| eventId | string | 是   | 变更事件id。|
| extraData | ExtraData | 是   | 云端数据变更信息。|

## cloudSyncManager.notifyDataChange<sup>11+</sup>

notifyDataChange(userId: number, extraData: ExtraData): Promise&lt;void&gt;

异步方法通知端云服务应用的云数据变更，以Promise形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| userId | number | 是   | 用户Id。|
| extraData | ExtraData | 是   | 云端数据变更信息。|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回通知端云服务应用的云数据变更的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userId: number = 100;
  let extraData: cloudSyncManager.ExtraData = {eventId: "eventId", extraData: "data"};
  cloudSyncManager.notifyDataChange(userId, extraData).then(() => {
    console.info("notifyDataChange successfully");
  }).catch((err: BusinessError) => {
    console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.notifyDataChange<sup>11+</sup>

notifyDataChange(userId: number, extraData: ExtraData, callback: AsyncCallback&lt;void&gt;): void

异步方法通知端云服务应用的云数据变更，以callback形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| userId | number | 是   | 用户Id。|
| extraData | ExtraData | 是   | 云端数据变更信息。|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步通知端云服务应用的云数据变更之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001  | IPC error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userId: number = 100;
  let extraData: cloudSyncManager.ExtraData = {eventId: "eventId", extraData: "data"};
  cloudSyncManager.notifyDataChange(userId, extraData, (err: BusinessError) => {
    if (err) {
      console.error("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("notifyDataChange successfully");
    }
  });
  ```

## cloudSyncManager.enableCloud

enableCloud(accountId: string, switches: Record<string, boolean>): Promise&lt;void&gt;

异步方法使能端云协同能力，以Promise形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| switches | Record<string, boolean> | 是   | 应用的端云协同特性使能开关，string类型为应用包名，boolean类型为开关状态。true为打开；false为关闭。|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回使能端云协同能力的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let switches: Record<string, boolean> = {
    'com.example.bundleName1': true,
    'com.example.bundleName2': false
  }
  cloudSyncManager.enableCloud(accountId, switches).then(() => {
    console.error("enableCloud successfully");
  }).catch((err: BusinessError) => {
    console.info("enableCloud failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.enableCloud

enableCloud(accountId: string, switches: Record<string, boolean>, callback: AsyncCallback&lt;void&gt;): void

异步方法使能端云协同能力，以callback形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| switches | Record<string, boolean> | 是   | 应用的端云协同特性使能开关，string类型为应用包名，boolean类型为开关状态。true为打开；false为关闭。|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步使能端云协同能力之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let switches: Record<string, boolean> = {
    'com.example.bundleName1': true,
    'com.example.bundleName2': false
  }
  cloudSyncManager.enableCloud(accountId, switches, (err: BusinessError) => {
    if (err) {
      console.error("enableCloud failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("enableCloud successfully");
    }
  });
  ```

## cloudSyncManager.disableCloud

disableCloud(accountId: string): Promise&lt;void&gt;

异步方法去使能端云协同能力，以Promise形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回去使能端云协同能力的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  cloudSyncManager.disableCloud(accountId).then(() => {
    console.info("disableCloud successfully");
  }).catch((err: BusinessError) => {
    console.error("disableCloud failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.disableCloud

disableCloud(accountId: string, callback: AsyncCallback&lt;void&gt;): void

异步方法去使能端云协同能力，以callback形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步去使能端云协同能力之后的回调。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  cloudSyncManager.disableCloud(accountId, (err: BusinessError) => {
    if (err) {
      console.error("disableCloud failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("disableCloud successfully");
    }
  });
  ```

## Action

清理本地云相关数据时的Action，为枚举类型。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| RETAIN_DATA |  0 |  仅清除云端标识，保留本地缓存文件。|
| CLEAR_DATA |  1 |  清除云端标识信息，若存在本地缓存文件，一并删除。|

## cloudSyncManager.clean

clean(accountId: string, appActions: Record<string, Action>): Promise&lt;void&gt;

异步方法清理本地云相关数据，以Promise形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| appActions | Record<string, Action> | 是   | 清理动作类型，string类型为待清理应用包名， [Action](#action)为清理动作类型。|

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回清理本地云相关数据的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
  let appActions: Record<string, cloudSyncManager.Action> = {
    'com.example.bundleName1': cloudSyncManager.Action.RETAIN_DATA,
    'com.example.bundleName2': cloudSyncManager.Action.CLEAR_DATA
  };
  cloudSyncManager.clean(accountId, appActions).then(() => {
    console.info("clean successfully");
  }).catch((err: BusinessError) => {
    console.error("clean failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## cloudSyncManager.clean

clean(accountId: string, appActions: Record<string, Action>, callback: AsyncCallback&lt;void&gt;): void

异步方法清理本地云相关数据，以callback形式返回结果。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| accountId | string | 是   | 账号Id。|
| appActions | Record<string, Action> | 是   | 清理动作类型，string类型为待清理应用包名， [Action](#action)为清理动作类型。|
| callback | AsyncCallback&lt;void&gt; | 是   | 异步方法清理本地云相关数据。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountId: string = "testAccount";
    let appActions: Record<string, cloudSyncManager.Action> = {
    'com.example.bundleName1': cloudSyncManager.Action.RETAIN_DATA,
    'com.example.bundleName2': cloudSyncManager.Action.CLEAR_DATA
  };
  cloudSyncManager.clean(accountId, appActions, (err: BusinessError) => {
    if (err) {
      console.error("clean failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("clean successfully");
    }
  });
  ```

## DowngradeDownload<sup>20+</sup>

降级下载：云空间会员服务到期，为避免用户云上数据丢失，提供的集中下载云端数据的能力。

云盘降级下载对象，用于支撑云空间应用完成云盘文件的降级下载流程。

**系统接口**：该接口为系统接口。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

### constructor<sup>20+</sup>

constructor(bundleName: string)

降级下载对象的构造函数，用于获取指定包名的DowngradeDownload类的实例。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名     | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------- |
| bundleName | string | 是   | 应用包名。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)以及[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                                                          |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13900020 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  let bundleName = 'com.demo.a';
  try {
    let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  } catch (e) {
    let error = e as BusinessError;
    console.error(`Failed to create downgrade manager object, error code: ${error.code}, message: ${error.message}`);
  }
  ```

### getCloudFileInfo<sup>20+</sup>

getCloudFileInfo(): Promise&lt;CloudFileInfo&gt;

获取需要降级下载的应用仅位于本地、仅位于云端或者本地和云端均有的文件大小和个数信息。使用Promise异步回调。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**返回值：**

  | 类型                              | 说明                     |
  | --------------------------------- | ------------------------ |
  | Promise&lt;[CloudFileInfo](js-apis-file-cloudsyncmanager.md#cloudfileinfo20)&gt; | Promise对象，返回携带本地与云端文件信息的对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)以及[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                                                          |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 13900010 | Try again.                                                                                                                                                                        |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let bundleName: string = "com.demo.a";
  let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  downgradeMgr.getCloudFileInfo().then((fileInfo: cloudSyncManager.CloudFileInfo) => {
    console.info("cloud file info: " + JSON.stringify(fileInfo));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get downgrade info, error message: ${err.message}, error code: ${err.code}`);
  });
  ```

### startDownload<sup>20+</sup>

startDownload(callback: Callback&lt;DownloadProgress&gt;): Promise&lt;void&gt;

异步方法启动指定应用的云文件的降级下载，使用Promise异步回调。

同一应用存在正在执行的降级下载任务的情况下，重复触发会返回错误信息（22400006）。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                                                                |
| -------- | -------------------------------- | ---- | ----------------------------------------------------------------------------------- |
| callback | Callback&lt;[DownloadProgress](js-apis-file-cloudsyncmanager.md#downloadprogress20)&gt; | 是   | 降级下载进度回调，回调参数为DownloadProgress，返回值为void。 |

**返回值：**

  | 类型                | 说明                      |
  | ------------------- | ------------------------- |
  | Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)以及[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                                                          |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 13900010 | Try again.                                                                                                                                                                        |
| 13900020 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |
| 22400006 | The same task is already in progress.                                                                                                                                             |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let bundleName: string = "com.demo.a";
  let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  let callback = (data: cloudSyncManager.DownloadProgress) => {
    console.info(`Dwongrade progress: downloadedSize: ${data.downloadedSize}, totalSize: ${data.totalSize}`);
    if (data.state == cloudSyncManager.DownloadState.COMPLETED) {
      console.info('Dwongrade finished.');
    } else if (data.state == cloudSyncManager.DownloadState.STOPPED) {
      console.info(`Dwongrade stopped, reason: ${data.stopReason}.`);
    }
  };
  downgradeMgr.startDownload(callback).then(() => {
    console.info("Downgrade started successfully.");
  }).catch((err: BusinessError) => {
    console.error(`Failed to start downgrade, error message: ${err.message}, error code: ${err.code}`);
  });
  ```

### stopDownload<sup>20+</sup>

stopDownload(): Promise&lt;void&gt;

停止由[startDownload](#startdownload20)触发的降级下载任务，使用Promise异步回调。

**系统接口**：该接口为系统接口。

**需要权限**：ohos.permission.CLOUDFILE_SYNC_MANAGER

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

**返回值：**

  | 类型                | 说明                      |
  | ------------------- | ------------------------- |
  | Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)以及[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                                                                                          |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.                                                                                                 |
| 202      | Permission verification failed, application which is not a system application uses system API.                                                                                    |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let bundleName: string = "com.demo.a";
  let downgradeMgr = new cloudSyncManager.DowngradeDownload(bundleName);
  downgradeMgr.startDownload((data: cloudSyncManager.DownloadProgress) => {
    console.info(`Dwongrade progress: downloadedSize: ${data.downloadedSize}, totalSize: ${data.totalSize}`);
  }).then(() => {
    console.info("Downgrade started successfully.");
  }).catch((err: BusinessError) => {
    console.error(`Failed to start downgrade, error message: ${err.message}, error code: ${err.code}`);
  });

  let needStop = true;
  if (needStop) {
    downgradeMgr.stopDownload().then(() => {
      console.info("Downgrade stopped successfully.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to stop downgrade, error message: ${err.message}, error code: ${err.code}`);
    });
  }
  ```
