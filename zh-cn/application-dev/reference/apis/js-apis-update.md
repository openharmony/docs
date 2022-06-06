# 升级

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

升级范围：升级整个系统，包括内置的资源、预置应用；第三方的应用不在升级的范围。

升级依赖：升级分为SD卡升级和在线升级两种。

- SD卡升级依赖升级包和SD卡安装。
- 在线升级依赖设备厂商部署的用于管理升级包的服务器。服务器由设备厂商部署，IP由调用者传入，请求的request接口是固定的，由设备厂商开发。

## 导入模块

```js
import update from '@ohos.update'
```

## 权限列表

无

## update.getUpdater

getUpdater(upgradeFile: string, updateType?: UpdateTypes): Updater

获取本地升级Updater。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名         | 类型                          | 必填   | 说明   |
| ----------- | --------------------------- | ---- | ---- |
| upgradeFile | string                      | 是    | 升级文件 |
| updateType  | [UpdateTypes](#updatetypes) | 是    | 升级类型 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| [Updater](#updater) | 升级对象 |

**示例：**

```
try {
  let updater = update.getUpdater('/data/updater/updater.zip', 'OTA');
} catch(error) {
  console.error(" Fail to get updater error: " + error);
}
```

## update.getUpdaterForOther

getUpdaterForOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater

获取升级对象给待升级设备。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名         | 类型                          | 必填   | 说明    |
| ----------- | --------------------------- | ---- | ----- |
| upgradeFile | string                      | 是    | 升级文件  |
| device      | string                      | 是    | 待升级设备 |
| updateType  | [UpdateTypes](#updatetypes) | 是    | 升级类型  |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| [Updater](#updater) | 升级对象 |

**示例：**

```
try {
  let updater = update.getUpdaterForOther('/data/updater/updater.zip', '1234567890', 'OTA');
} catch(error) {
  console.error(" Fail to get updater error: " + error);
}
```

## update.getUpdaterFromOther

getUpdaterFromOther(upgradeFile: string, device: string, updateType?: UpdateTypes): Updater

获取其它设备为本设备升级的Updater。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名         | 类型                          | 必填   | 说明    |
| ----------- | --------------------------- | ---- | ----- |
| upgradeFile | string                      | 是    | 升级文件  |
| device      | string                      | 是    | 待升级设备 |
| updateType  | [UpdateTypes](#updatetypes) | 是    | 升级类型  |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| [Updater](#updater) | 升级对象 |

**示例：**

```
try {
  let updater = update.getUpdaterFromOther('/data/updater/updater.zip', '1234567890', 'OTA');
} catch(error) {
  console.error(" Fail to get updater error: " + error);
}
```

## Updater

###  getNewVersionInfo

getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void

获取新版本信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback<[NewVersionInfo](#newversioninfo)> | 否    | 回调返回新版本信息 |

**示例：**

```
updater.getNewVersionInfo(info => {
  console.log("getNewVersionInfo success  " + info.status);
  console.log(`info versionName = ` + info.checkResult[0].versionName);
  console.log(`info versionCode = ` + info.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + info.checkResult[0].verifyInfo);
});
```

### getNewVersionInfo

getNewVersionInfo(): Promise\<NewVersionInfo>

获取新版本信息，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<[NewVersionInfo](#newversioninfo)> | Promise，用于异步获取结果 |

**示例：**

```
updater.getNewVersionInfo().then(value => {
  console.log(`info versionName = ` + value.checkResult[0].versionName);
  console.log(`info versionCode = ` + value.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + value.checkResult[0].verifyInfo);
}).catch(err => {
  console.log("getNewVersionInfo promise error: " + err.code);
});
```

### checkNewVersion

checkNewVersion(callback: AsyncCallback\<NewVersionInfo>): void

检查新版本，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback\<[NewVersionInfo](#newversioninfo)> | 否    | 回调返回新版本信息 |

**示例：**

```
updater.checkNewVersion(info => {
  console.log("checkNewVersion success  " + info.status);
  console.log(`info versionName = ` + info.checkResult[0].versionName);
  console.log(`info versionCode = ` + info.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + info.checkResult[0].verifyInfo);
});
```

### checkNewVersion

checkNewVersion(): Promise\<NewVersionInfo>

检查新版本，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值:**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<[NewVersionInfo](#newversioninfo)> | Promise函数返回新版本信息 |

**示例:**

```
updater.checkNewVersion().then(value => {
  console.log(`info versionName = ` + value.checkResult[0].versionName);
  console.log(`info versionCode = ` + value.checkResult[0].versionCode);
  console.log(`info verifyInfo = ` + value.checkResult[0].verifyInfo);
}).catch(err => {
  console.log("checkNewVersion promise error: " + err.code);
});
```

### verifyUpdatePackage

verifyUpdatePackage(upgradeFile: string, certsFile: string): void

升级前检查升级包是否有效。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名         | 类型     | 必填   | 说明        |
| ----------- | ------ | ---- | --------- |
| upgradeFile | string | 是    | 待校验的升级包路径 |
| certsFile   | string | 是    | 证书路径      |

**示例：**

```
updater.on("verifyProgress", callback => {
  console.info('on verifyProgress ' + callback.percent);
});
update.verifyUpdatePackage("XXX", "XXX");
```

### rebootAndCleanUserData<sup>7+</sup>

rebootAndCleanUserData(): Promise\<number>

重启设备并清除用户分区数据。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型               | 说明                  |
| ---------------- | ------------------- |
| Promise\<number> | Promise示例，用于异步获取结果。 |

**示例：**

```
updater.rebootAndCleanUserData().then(result => {
  console.log("rebootAndCleanUserData " + result);
}).catch(err => {
  console.info("rebootAndCleanUserData promise error: " + err.code);
});
```

### rebootAndCleanUserData<sup>7+</sup>

rebootAndCleanUserData(callback: AsyncCallback\<number>): void

重启设备并清除用户分区数据。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型       | 必填   | 说明                     |
| -------- | -------- | ---- | ---------------------- |
| callback | Function | 是    | AsyncCallback\<number> |

**示例：**

```
updater.rebootAndCleanUserData(result => {
  console.log("rebootAndCleanUserData ", result)
});
```

### applyNewVersion

applyNewVersion(): Promise\<number>

重启设备后安装升级包。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型               | 说明                  |
| ---------------- | ------------------- |
| Promise\<number> | Promise示例，用于异步获取结果。 |

**示例：**

```
updater.applyNewVersion().then(result => {
    console.log("appVewVersion ", result)
}).catch(err => {
    console.info("applyNewVersion promise error: " + err.code);
});
```

### applyNewVersion

applyNewVersion(callback: AsyncCallback\<number>): void

重启设备后安装升级包。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型       | 必填   | 说明                     |
| -------- | -------- | ---- | ---------------------- |
| callback | Function | 是    | AsyncCallback\<number> |

**示例：**

```
updater.applyNewVersion(result => {
  console.log("applyNewVersion ", result)
});
```

### download

download(): void

下载新版本，并监听下载进程。

**系统能力**：SystemCapability.Update.UpdateService

**示例：**

```
updater.on("downloadProgress", progress => {
  console.log("downloadProgress on" + progress);
  console.log(`downloadProgress status: ` + progress.status);
  console.log(`downloadProgress percent: ` + progress.percent);
});
updater.download();
```

### upgrade

upgrade():void

启动升级。

**系统能力**：SystemCapability.Update.UpdateService

**示例：**

```
updater.on("upgradeProgress", progress => {
  console.log("upgradeProgress on" + progress);
  console.log(`upgradeProgress status: ` + progress.status);
  console.log(`upgradeProgress percent: ` + progress.percent);
});
updater.upgrade();
```

### setUpdatePolicy

setUpdatePolicy(policy: UpdatePolicy, callback: AsyncCallback\<number>): void

设置升级策略，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                            | 必填   | 说明     |
| -------- | ----------------------------- | ---- | ------ |
| policy   | [UpdatePolicy](#updatepolicy) | 是    | 设置升级策略 |
| callback | AsyncCallback\<number>        | 是    | 回调返回结果 |

**示例：**

```
// 设置策略
let policy = {
  autoDownload: false,
  autoDownloadNet: true,
  mode: 2,
  autoUpgradeInterval: [ 2, 3 ],
  autoUpgradeCondition: 2
}
updater.setUpdatePolicy(policy, result => {
  console.log("setUpdatePolicy ", result)
});
```

### setUpdatePolicy

setUpdatePolicy(policy: UpdatePolicy): Promise\<number>

设置升级策略，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名    | 类型                            | 必填   | 说明     |
| ------ | ----------------------------- | ---- | ------ |
| policy | [UpdatePolicy](#updatepolicy) | 是    | 设置升级策略 |

**返回值：**

| 类型               | 说明              |
| ---------------- | --------------- |
| Promise\<number> | Promise函数返回设置结果 |

**示例：**

```
let policy = {
  autoDownload: false,
  autoDownloadNet: true,
  mode: 2,
  autoUpgradeInterval: [ 2, 3 ],
  autoUpgradeCondition: 2
}
updater.setUpdatePolicy(policy).then(result => 
  console.log("setUpdatePolicy ", result)
).catch(err => {
  console.log("setUpdatePolicy promise error: " + err.code);
});
```

### getUpdatePolicy

getUpdatePolicy(callback: AsyncCallback\<UpdatePolicy>): void

获取升级策略信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[UpdatePolicy](#updatepolicy)> | 否    | 回调返回升级策略信息 |

**示例：**

```
updater.getUpdatePolicy(policy => {
  console.log("getUpdatePolicy success");
  console.log(`policy autoDownload = ` + policy.autoDownload);
  console.log(`policy autoDownloadNet = ` + policy.autoDownloadNet);
  console.log(`policy mode = ` + policy.mode);
});
```

### getUpdatePolicy

getUpdatePolicy(): Promise\<UpdatePolicy>

获取升级策略，通过promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型                                      | 说明                |
| --------------------------------------- | ----------------- |
| Promise\<[UpdatePolicy](#updatepolicy)> | Promise函数返回升级策略信息 |

**示例：**

```
updater.getUpdatePolicy().then(value => {
  console.log(`info autoDownload = ` + value.autoDownload);
  console.log(`info autoDownloadNet = ` + value.autoDownloadNet);
  console.log(`info mode = ` + value.mode);
}).catch(err => {
  console.log("getUpdatePolicy promise error: " + err.code);
});
```

## UpdateTypes

升级类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名   | 说明    |
| ----- | ----- |
| OTA   | OTA升级 |
| patch | 补丁升级  |

## PackageTypes

升级包类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                  | 默认值  | 说明      |
| -------------------- | ---- | ------- |
| PACKAGE_TYPE_NORMAL  | 1    | 通用升级包   |
| PACKAGE_TYPE_BASE    | 2    | 基础升级包   |
| PACKAGE_TYPE_CUST    | 3    | 定制升级包   |
| PACKAGE_TYPE_PRELOAD | 4    | 预装升级包   |
| PACKAGE_TYPE_COTA    | 5    | 参数配置升级包 |
| PACKAGE_TYPE_VERSION | 6    | 版本升级包   |
| PACKAGE_TYPE_PATCH   | 7    | 补丁包     |

## InstallMode

安装模式。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明   |
| ------------------- | ---- | ---- |
| INSTALL_MODE_NORMAL | 0    | 正常升级 |
| INSTALL_MODE_NIGHT  | 1    | 夜间升级 |
| INSTALL_MODE_AUTO   | 2    | 自动升级 |

## NewVersionStatus

新版本检测状态。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| VERSION_STATUS_ERR  | -1   | 检测版本时出错  |
| VERSION_STATUS_NEW  | 0    | 检测到新版本   |
| VERSION_STATUS_NONE | 1    | 没有检测到新版本 |
| VERSION_STATUS_BUSY | 2    | 检测版本时忙   |

## UpdatePolicy

升级策略。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| autoDownload        | bool                        | 是    | 自动升级开关  |
| installMode         | [InstallMode](#installmode) | 是    | 安装模式    |
| autoUpgradeInterval | Array\<number>              | 是    | 自动升级时间段 |

## NewVersionInfo

新版本信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称              | 参数类型                                     | 必填   | 说明   |
| --------------- | ---------------------------------------- | ---- | ---- |
| status          | [NewVersionStatus](#newversionstatus)    | 是    | 升级状态 |
| errMsg          | string                                   | 是    | 错误信息 |
| checkResults    | Array<[CheckResult](#checkresult)>       | 是    | 检测结果 |
| descriptionInfo | Array\<[DescriptionInfo](#descriptioninfo)> | 是    | 描述信息 |

## CheckResult

检测结果。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称            | 参数类型                          | 必填   | 说明     |
| ------------- | ----------------------------- | ---- | ------ |
| versionName   | string                        | 是    | 版本名称   |
| versionCode   | number                        | 是    | 版本编码   |
| size          | number                        | 是    | 版本大小   |
| verifyInfo    | string                        | 是    | 版本校验信息 |
| packageType   | [PackageTypes](#packagetypes) | 是    | 版本类型   |
| descriptionId | string                        | 是    | 版本描述信息 |

## DescriptionInfo

版本描述信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称            | 参数类型   | 必填   | 说明            |
| ------------- | ------ | ---- | ------------- |
| descriptionId | string | 是    | 版本versionId信息 |
| content       | string | 是    | 版本changelog信息 |