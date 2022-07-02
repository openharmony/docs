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

ohos.permission.UPDATE_SYSTEM
ohos.permission.FACTORY_RESET

## update.getOnlineUpdater

getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater

获取在线升级Updater。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名         | 类型                          | 必填   | 说明   |
| ----------- | --------------------------- | ---- | ---- |
| upgradeInfo | [UpgradeInfo](#upgradeinfo)                 | 是    | 升级信息 |

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| [Updater](#updater) | 升级对象 |

**示例：**

```
try {
  var upgradeInfo = {
    upgradeApp: "com.ohos.ota.updateclient",
    businessType: {
      vendor: BusinessVendor.PUBLIC
      subType: BusinessSubType.FIRMWARE;
    }
  }
  let updater = update.getOnlineUpdater(upgradeInfo);
} catch(error) {
  console.error(" Fail to get updater error: " + error);
}
```

## update.getRestorer

getRestorer(): Restorer

获取恢复出厂对象Restorer。

**系统能力**：SystemCapability.Update.UpdateService


**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| [Restorer](#restorer) | 恢复出厂对象 |

**示例：**

```
try {
  let restorer = update.getRestorer();
} catch(error) {
  console.error(" Fail to get restorer: " + error);
}
```

## update.getLocalUpdater

getLocalUpdater(): LocalUpdater

获取本地升级的LocalUpdater。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型                  | 说明   |
| ------------------- | ---- |
| [LocalUpdater](#localupdater) | 本地升级对象 |

**示例：**

```
try {
  let localUpdater = update.getLocalUpdater();
} catch(error) {
  console.error(" Fail to get localUpdater error: " + error);
}
```

## Updater

### checkNewVersion

checkNewVersion(callback: AsyncCallback\<CheckResult>): void

检查新版本，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback\<[CheckResult](#checkresult)> | 是    | 回调返回检测结果 |

**示例：**

```
updater.checkNewVersion((err, result) => {
  console.log("checkNewVersion isExsitNewVersion  " + result?.isExsitNewVersion);
});
```

### checkNewVersion

checkNewVersion(): Promise\<CheckResult>

检查新版本，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值:**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<[CheckResult](#checkresult)> | Promise函数返回检测结果 |

**示例:**

```
updater.checkNewVersion().then(result => {
  console.log("checkNewVersion isExsitNewVersion  " + result.isExsitNewVersion);
  // 版本摘要信息
  console.log("checkNewVersion versionDigestInfo  " + result.newVersionInfo.versionDigestInfo);
}).catch(err => {
  console.log("checkNewVersion promise error $JSON.stringify(err)");
});
```

###  getNewVersionInfo

getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void

获取新版本信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback<[NewVersionInfo](#newversioninfo)> | 是    | 回调返回新版本信息 |

**示例：**

```
updater.getNewVersionInfo((err, info) => {
  console.log(`info versionName = ` + info?.versionComponents[0].displayVersion);
  console.log(`info versionCode = ` + info?.versionComponents[0].innerVersion);
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
updater.getNewVersionInfo().then(info => {
  console.log(`info versionName = ` + info.versionComponents[0].displayVersion);
  console.log(`info versionCode = ` + info.versionComponents[0].innerVersion);
}).catch(err => {
  console.log("getNewVersionInfo promise error $JSON.stringify(err)");
});
```

###  getCurrentVersionInfo

getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void

获取当前版本信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback<[CurrentVersionInfo](#currentversioninfo)> | 是    | 回调返回当前版本信息 |

**示例：**

```
updater.getCurrentVersionInfo((err, info) => {
  console.log(`info osVersion = ` + info?.osVersion);
  console.log(`info deviceName = ` + info?.deviceName);
  console.log(`info displayVersion = ` + info?.versionComponents[0].displayVersion);
});
```

### getCurrentVersionInfo

getCurrentVersionInfo(): Promise\<CurrentVersionInfo>

获取当前版本信息，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<[CurrentVersionInfo](#currentversioninfo)> | Promise，用于异步获取结果 |

**示例：**

```
updater.getCurrentVersionInfo().then(info => {
  console.log(`info osVersion = ` + info.osVersion);
  console.log(`info deviceName = ` + info.deviceName);
  console.log(`info displayVersion = ` + info.versionComponents[0].displayVersion);
}).catch(err => {
  console.log("getCurrentVersionInfo promise error $JSON.stringify(err)");
});
```

###  getTaskInfo

getTaskInfo(callback: AsyncCallback\<TaskInfo>): void

获取升级任务信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback<[TaskInfo](#taskinfo)> | 是    | 回调返回升级任务信息 |

**示例：**

```
updater.getTaskInfo((err, info) => {
  console.log(`getTaskInfo isexistTask= ` + info?.existTask);
});
```

### getTaskInfo

getTaskInfo(): Promise\<TaskInfo>

获取升级任务信息，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<[TaskInfo](#taskinfo)> | Promise，用于异步获取结果 |

**示例：**

```
updater.getTaskInfo().then(info => {
  console.log(`getTaskInfo existTask= ` + info.existTask);
}).catch(err => {
  console.log("getTaskInfo promise error $JSON.stringify(err)");
});
```

###  download

download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions, callback: AsyncCallback\<void>): void

下载新版本，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| downloadOptions | [DownloadOptions](#downloadoptions) | 是    | 下载选项 |
| callback | AsyncCallback<void> | 是    | 执行回调 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 下载选项
var downloadOptions = {
  allowNetwork: NetType.CELLULAR_AND_WIFI, // 允许所有网络下载
  order: Order.DOWNLOAD // 下载
}
updater.download(versionDigestInfo, downloadOptions, (err) => {
  console.log(`download error $JSON.stringify(err)`);
});
```

### download

download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>

下载新版本，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| downloadOptions | [DownloadOptions](#downloadoptions) | 是    | 下载选项 |

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise，用于异步获取结果 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 下载选项
var downloadOptions = {
  allowNetwork: NetType.CELLULAR_AND_WIFI, // 允许所有网络下载
  order: Order.DOWNLOAD // 下载
}
updater.download(versionDigestInfo, downloadOptions).then(() => {
  console.log(`download start`);
}).catch(err => {
  console.log(`download error $JSON.stringify(err)`);
});
```

###  resumeDownload

resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions, callback: AsyncCallback\<void>): void

恢复下载新版本，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| resumeDownloadOptions | [ResumeDownloadOptions](#resumedownloadoptions) | 是    | 恢复下载选项 |
| callback | AsyncCallback<void> | 是    | 执行回调 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 恢复下载选项
var resumeDownloadOptions = {
  allowNetwork: NetType.CELLULAR_AND_WIFI, // 允许所有网络下载
}
updater.resumeDownload(versionDigestInfo, resumeDownloadOptions, (err) => {
  console.log(`resumeDownload error $JSON.stringify(err)`);
});
```

### resumeDownload

resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>

恢复下载新版本，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| resumeDownloadOptions | [ResumeDownloadOptions](#resumedownloadoptions) | 是    | 恢复下载选项 |

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise，用于异步获取结果 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 恢复下载选项
var resumeDownloadOptions = {
  allowNetwork: NetType.CELLULAR_AND_WIFI, // 允许所有网络下载
}
updater.resumeDownload(versionDigestInfo, resumeDownloadOptions).then(value => {
  console.log(`resumeDownload start`);
}).catch(err => {
  console.log(`resumeDownload error $JSON.stringify(err)`);
});
```

###  pauseDownload

pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions, callback: AsyncCallback\<void>): void

暂停下载新版本，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| pauseDownloadOptions | [PauseDownloadOptions](#pausedownloadoptions) | 是    | 暂停下载选项 |
| callback | AsyncCallback<void> | 是    | 执行回调 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 暂停下载选项
var pauseDownloadOptions = {
  isAllowAutoResume: true, // 允许自动恢复下载
}
updater.pauseDownload(versionDigestInfo, pauseDownloadOptions, (err) => {
  console.log(`pauseDownload error $JSON.stringify(err)`);
});
```

### pauseDownload

pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>

恢复下载新版本，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| pauseDownloadOptions | [PauseDownloadOptions](#pausedownloadoptions) | 是    | 暂停下载选项 |

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise，用于异步获取结果 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 暂停下载选项
var pauseDownloadOptions = {
  isAllowAutoResume: true, // 允许自动恢复下载
}
updater.pauseDownload(versionDigestInfo, pauseDownloadOptions).then(value => {
  console.log(`pauseDownload`);
}).catch(err => {
  console.log(`pauseDownload error $JSON.stringify(err)`);
});
```

###  upgrade

upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void

升级新版本，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| upgradeOptions | [UpgradeOptions](#upgradeoptions) | 是    | 更新选项 |
| callback | AsyncCallback<void> | 是    | 执行回调 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 安装选项
var upgradeOptions = {
  order: Order.INSTALL, // 安装指令
}
updater.upgrade(versionDigestInfo, upgradeOptions, (err) => {
  console.log(`upgrade error $JSON.stringify(err)`);
});
```

### upgrade

upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>

升级新版本，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| upgradeOptions | [UpgradeOptions](#upgradeoptions) | 是    | 更新选项 |

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise，用于异步获取结果 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 安装选项
var upgradeOptions = {
  order: Order.INSTALL, // 安装指令
}
updater.upgrade(versionDigestInfo, upgradeOptions).then(() => {
  console.log(`upgrade start`);
}).catch(err => {
  console.log(`upgrade error $JSON.stringify(err)`);
});
```

###  clearError

clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void

清除异常状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| clearOptions | [ClearOptions](#clearoptions) | 是    | 清除选项 |
| callback | AsyncCallback<void> | 是    | 执行回调 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 清除选项
var clearOptions = {
  status: UpgradeStatus.UPGRADE_FAIL,
}
updater.clearError(versionDigestInfo, clearOptions, (err) => {
  console.log(`clearError error $JSON.stringify(err)`);
});
```

### clearError

clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>

清除异常状态，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| versionDigestInfo | [VersionDigestInfo](#versiondigestinfo) | 是    | 版本摘要信息 |
| clearOptions | [ClearOptions](#clearoptions) | 是    | 更新选项 |

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise，用于异步获取结果 |

**示例：**

```
// 版本摘要信息
var versionDigestInfo = {
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息
}

// 清除选项
var clearOptions = {
  status: UpgradeStatus.UPGRADE_FAIL,
}
updater.clearError(versionDigestInfo, clearOptions).then(() => {
  console.log(`clearError success`);
}).catch(err => {
  console.log(`clearError error $JSON.stringify(err)`);
});
```

### getUpgradePolicy

getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void

获取升级策略信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[UpgradePolicy](#upgradepolicy)> | 是    | 回调返回升级策略信息 |

**示例：**

```
updater.getUpgradePolicy((err, policy) => {
  console.log(`policy downloadStrategy = ` + policy?.downloadStrategy);
  console.log(`policy autoUpgradeStrategy = ` + policy?.autoUpgradeStrategy);
});
```

### getUpgradePolicy

getUpgradePolicy(): Promise\<UpgradePolicy>

获取升级策略，通过promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型                                      | 说明                |
| --------------------------------------- | ----------------- |
| Promise\<[UpgradePolicy](#upgradepolicy)> | Promise函数返回升级策略信息 |

**示例：**

```
updater.getUpgradePolicy().then(policy => {
  console.log(`policy downloadStrategy = ` + policy.downloadStrategy);
  console.log(`policy autoUpgradeStrategy = ` + policy.autoUpgradeStrategy);
}).catch(err => {
  console.log(`getUpgradePolicy promise error $JSON.stringify(err)`);
});
```

### setUpgradePolicy

setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<number>): void

设置升级策略，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明         |
| -------- | ---------------------------------------- | ---- | ---------- |
| policy | [UpgradePolicy](#upgradepolicy) | 是    | 升级策略 |
| callback | AsyncCallback\<number> | 是    | 回调设置结果 |

**示例：**

```
let policy = {
  downloadStrategy: false,
  autoUpgradeStrategy: false,
  autoUpgradeInterval: [ 120, 240 ], // 自动升级时间段，用分钟表示
}
updater.setUpgradePolicy(policy, (err, value) => {
  console.log(`setUpgradePolicy result: ` + value?);
});
```

### setUpgradePolicy

setUpgradePolicy(policy: UpgradePolicy): Promise\<number>

设置升级策略，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名    | 类型                            | 必填   | 说明     |
| ------ | ----------------------------- | ---- | ------ |
| policy | [UpgradePolicy](#upgradepolicy) | 是    | 升级策略 |

**返回值：**

| 类型               | 说明              |
| ---------------- | --------------- |
| Promise\<number> | Promise函数返回设置结果 |

**示例：**

```
let policy = {
  downloadStrategy: false,
  autoUpgradeStrategy: false,
  autoUpgradeInterval: [ 120, 240 ], // 自动升级时间段，用分钟表示
}
updater.setUpdatePolicy(policy).then(result => 
  console.log("setUpdatePolicy ", result)
).catch(err => {
  console.log(`setUpdatePolicy promise error $JSON.stringify(err)`);
});
```

###  terminateUpgrade

terminateUpgrade(callback: AsyncCallback\<void>): void

终止升级，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback<void> | 是    | 结果回调 |

**示例：**

```
updater.terminateUpgrade((err) => {
  console.log(`terminateUpgrade error $JSON.stringify(err)`);
});
```

### terminateUpgrade

terminateUpgrade(): Promise\<void>

终止升级，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值：**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise，用于异步获取结果 |

**示例：**

```
updater.terminateUpgrade().then(() => {
  console.log(`terminateUpgrade success`);
}).catch(err => {
  console.log(`terminateUpgrade error $JSON.stringify(err)`);
});
```


### on
on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void

注册事件监听，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo) | 是    | 事件信息 |
| taskCallback |  [UpgradeTaskCallback](#upgradetaskcallback) | 是    | 事件回调 |

**示例：**

```
var eventClassifyInfo = {
  eventClassify: EventClassify.TASK // 订阅升级更新事件
  extraInfo: ""
}

function onTaskUpdate(eventInfo): void {
  console.log("on eventInfo id ", eventInfo.eventId);
}

updater.on(eventClassifyInfo, onTaskUpdate);
```

### off
off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void

取消注册事件监听，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo) | 是    | 事件信息 |
| taskCallback |  [UpgradeTaskCallback](#upgradetaskcallback) | 否    | 事件回调 |

**示例：**

```
var eventClassifyInfo = {
  eventClassify: EventClassify.TASK // 订阅升级更新事件
  extraInfo: ""
}

function onTaskUpdate(eventInfo): void {
  console.log("on eventInfo id ", eventInfo.eventId);
}

updater.off(eventClassifyInfo, onTaskUpdate);
```

## Restorer

### factoryReset

factoryReset(callback: AsyncCallback\<void>): void

恢复出厂设置，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback\<void> | 是    | 回调结果 |

**示例：**

```
restorer.factoryReset((err) => {
  console.log("factoryReset error $JSON.stringify(err)");
});
```

### factoryReset

factoryReset(): Promise\<void>

恢复出厂设置，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值:**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise函数返回调用结果 |

**示例:**

```
restorer.factoryReset().then(() => {
  console.log("factoryReset success ");
}).catch(err => {
  console.log("factoryReset error $JSON.stringify(err)");
});
```

## LocalUpdater

### verifyUpgradePackage

verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<number>): void

校验升级包，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| upgradeFile | [UpgradeFile](#upgradefile) | 是    | 升级文件 |
| certsFile | string | 是    | 证书文件路径 |
| callback | AsyncCallback\<number> | 是    | 回调校验结果 |

**示例：**

```
var upgradeFile = {
  fileType: ComponentType.OTA // OTA包
  filePath: "path" // 本地升级包路径
}

localUpdater.verifyUpgradePackage(upgradeFile, "cerstFilePath", (err, value) => {
  console.log("factoryReset error $JSON.stringify(err)");
});
```

### verifyUpgradePackage

verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<void>

校验升级包，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| upgradeFile | [UpgradeFile](#upgradefile) | 是    | 升级文件 |
| certsFile | string | 是    | 证书文件路径 |

**返回值:**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise函数返回调用结果 |

**示例:**

```
var upgradeFile = {
  fileType: ComponentType.OTA // OTA包
  filePath: "path" // 本地升级包路径
}
localUpdater.verifyUpgradePackage(upgradeFile, "cerstFilePath").then(number => {
  console.log("verifyUpgradePackage result: " + number);
}).catch(err => {
  console.log("verifyUpgradePackage error $JSON.stringify(err)");
});
```

### applyNewVersion
applyNewVersion(upgradeFiles: Array<[UpgradeFile](#upgradefile)>, callback: AsyncCallback\<void>): void

安装升级包，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| upgradeFile | Array<[UpgradeFile](#upgradefile)> | 是    | 升级文件 |
| callback | AsyncCallback\<void> | 是    | 回调安装结果 |

**示例：**

```
var upgradeFiles = [{
  fileType: ComponentType.OTA // OTA包
  filePath: "path" // 本地升级包路径
}]

localUpdater.applyNewVersion(upgradeFiles, (err) => {
  console.log("applyNewVersion error $JSON.stringify(err)");
});
```

### applyNewVersion

applyNewVersion(upgradeFiles: Array<[UpgradeFile](#upgradefile)>): Promise\<void>

安装升级包，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**返回值:**

| 类型                                       | 说明               |
| ---------------------------------------- | ---------------- |
| Promise\<void> | Promise函数返回调用结果 |

**示例:**

```
var upgradeFile = [{
  fileType: ComponentType.OTA // OTA包
  filePath: "path" // 本地升级包路径
}]
localUpdater.applyNewVersion(upgradeFiles).then(() => {
  console.log("applyNewVersion success");
}).catch(err => {
  console.log("applyNewVersion error $JSON.stringify(err)");
});
```

### on
on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void

注册事件监听，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo) | 是    | 事件信息 |
| taskCallback |  [UpgradeTaskCallback](#upgradetaskcallback) | 是    | 事件回调 |

**示例：**

```
var eventClassifyInfo = {
  eventClassify: EventClassify.TASK // 订阅升级更新事件
  extraInfo: ""
}

function onTaskUpdate(eventInfo) {
  console.log("on eventInfo id ", eventInfo.eventId);
}

localUpdater.on(eventClassifyInfo, onTaskUpdate);
```

### off
off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void

取消注册事件监听，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Update.UpdateService

**参数：**

| 参数名      | 类型                                       | 必填   | 说明        |
| -------- | ---------------------------------------- | ---- | --------- |
| eventClassifyInfo | [EventClassifyInfo](#eventclassifyinfo) | 是    | 事件信息 |
| taskCallback |  [UpgradeTaskCallback](#upgradetaskcallback) | 是    | 事件回调 |

**示例：**

```
var eventClassifyInfo = {
  eventClassify: EventClassify.TASK // 订阅升级更新事件
  extraInfo: ""
}

function onTaskUpdate(eventInfo) {
  console.log("on eventInfo id ", eventInfo.eventId);
}

localUpdater.off(eventClassifyInfo, onTaskUpdate);
```

## UpgradeInfo

升级信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| upgradeApp          | string                      | 是    | 调用方包名  |
| businessType        | [BusinessType](#businesstype) | 是    | 升级业务类型    |

## BusinessType

升级业务类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| vendor              | [BusinessVendor](#businessvendor)   | 是    | 供应商  |
| subType             | [BusinessSubType](#businesssubtype) | 是    | 类型    |

## CheckResult

搜包结果。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| isExistNewVersion              | bool   | 是    | 是否有新版本  |
| newVersionInfo             | [NewVersionInfo](#newversioninfo) | 否    | 新版本数据    |

## NewVersionInfo

新版本数据。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| versionDigestInfo              | [VersionDigestInfo](#versiondigestinfo)   | 是    | 版本摘要  |
| versionComponents             | Array\<[VersionComponent](#vesioncomponent)>  | 是    | 版本组件    |

## VersionDigestInfo

版本摘要。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| versionDigest              | string   | 是    | 版本摘要  |

## VersionComponent

版本组件。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| componentType              | [ComponentType](#componentyype)   | 是    | 组件类型  |
| upgradeAction              | [UpgradeAction](#upgradeaction)   | 是    | 升级方式  |
| displayVersion              | string   | 是    | 显示版本号  |
| innerVersion              | string   | 是    | 版本号  |
| size              | number   | 是    | 升级包大小  |
| effectiveMode              | [EffectiveMode](#effectivemode)   | 是    | 生效模式  |
| descriptionInfo              | [DescriptionInfo](#descriptioninfo)   | 是    | 版本描述文件信息  |

## DescriptionInfo

版本描述文件信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| descriptionType              | [DescriptionType](#descriptiontype)   | 是    | 描述文件类型  |
| content              |  string  | 是    | 描述文件内容  |

## CurrentVersionInfo

当前版本信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| osVersion              | string   | 是    | 系统版本号  |
| deviceName              | string   | 是    | 设备名  |
| versionComponents              | Array\<[VersionComponent](#vesioncomponent)>   | 否    | 版本组件  |

## DownloadOptions

下载选项。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| allowNetwork              | [NetType](#nettype)   | 是    | 网络类型  |
| order              | [Order](#order)   | 是    | 升级指令  |

## ResumeDownloadOptions

恢复下载选项。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| allowNetwork              | [NetType](#nettype)   | 是    | 网络类型  |

## PauseDownloadOptions

暂停下载选项。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| isAllowAutoResume              | bool   | 是    | 是否允许自动恢复  |

## UpgradeOptions

升级选项。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| order              | [Order](#order)   | 是    | 升级指令  |

## ClearOptions

清除异常选项。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| status              | [UpgradeStatus](#upgradestatus)   | 是    | 异常状态  |

## UpgradePolicy

升级策略。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| downloadStrategy        | bool                        | 是    | 自动下载策略  |
| autoUpgradeStrategy         | bool | 是    | 自动升级策略    |
| autoUpgradePeriods | Array\<[UpgradePeriod](#upgradeperiod)>              | 是    | 自动升级时间段 |

## UpgradePeriod

升级时间段。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| start        | number                        | 是    | 开始时间  |
| end         | number | 是    | 结束时间    |

## TaskInfo

任务信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| existTask        | bool                        | 是    | 是否存在任务  |
| taskBody         | [TaskBody](#taskinfo) | 是    | 任务数据    |

## EventInfo

事件信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| eventId        |   [EventId](#eventid)    | 是    | 事件ID  |
| taskBody         | [TaskBody](#taskinfo) | 是    | 任务数据    |

## TaskBody

任务数据。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| versionDigestInfo        |   [VersionDigestInfo](#versiondigestinfo)    | 是    | 版本摘要  |
| status         | [UpgradeStatus](#upgradestatus) | 是    | 升级状态    |
| subStatus         | number | 否    | 子状态    |
| progress         | number | 是    | 进度    |
| installMode         | number | 是    | 安装模式    |
| errorMessages         |  Array\<[ErrorMessage](#errormessage)>  | 否    | 错误信息    |
| versionComponets         | Array\<[VersionComponet](#versioncomponet)> | 是    | 版本组件    |

## ErrorMessage

错误信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| errorCode        |   number   | 是    | 错误码  |
| errorMessage         | string | 是    | 错误描述    |

## EventClassifyInfo

事件信息。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| eventClassify        |   EventClassify   | 是    | 事件类型  |
| extraInfo         | string | 是    | 额外信息    |

## UpgradeFile

升级文件。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称                  | 参数类型                        | 必填   | 说明      |
| ------------------- | --------------------------- | ---- | ------- |
| fileType        |   ComponentType   | 是    | 文件类型  |
| filePath         | string | 是    | 文件路径    |

## UpgradeTaskCallback

### onTaskUpdate
onTaskUpdate(eventInfo: [EventInfo](#eventinfo)): void

事件回调。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 名称              | 参数类型                                     | 必填   | 说明   |
| --------------- | ---------------------------------------- | ---- | ---- |
| eventInfo          | [EventInfo](#eventinfo)     | 是    | 事件信息 |

## BusinessVendor

设备厂家。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| PUBLIC   | "public" | 开源  |

## BusinessSubType

升级类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| FIRWARE   | 1 | 固件  |

## ComponentType

升级包类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| OTA   | 1 | 固件  |

## UpgradeAction

升级方式。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| UPGRADE   | "upgrade" | 差分包  |
| RECOVERY   | "recovery" | 修复包  |

## EffectiveMode

生效模式。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| COLD   | 1 | 冷升级  |
| LIVE   | 2 | 热升级  |
| LIVE_AND_COLD   | 3 | 融合升级  |

## DescriptionType

描述文件类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| CONTENT   | 0 | 内容  |
| URI   | 1 | 链接  |

## NetType

网络类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| CELLULAR   | 1 | 数据网络  |
| METERED_WIFI   | 2 | 热点WIFI  |
| NOT_METERED_WIFI   | 4 | 非热点WIFI  |
| WIFI   | 6 | WIFI  |
| CELLULAR_AND_WIFI   | 7 | 数据网络和WIFI  |

## Order

升级指令。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| DOWNLOAD   | 1 | 下载  |
| INSTALL   | 2 | 安装  |
| APPLY   | 4 | 生效  |
| DOWNLOAD_AND_INSTALL   | 3 | 下载并安装  |
| INSTALL_AND_APPLY   | 6 | 安装并生效  |

## UpgradeStatus

升级状态。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| WAITING_DOWNLOAD   | 20 | 待下载  |
| DOWNLOADING   | 21 | 下载中  |
| DOWNLOAD_PAUSE   | 22 | 下载暂停  |
| DOWNLOAD_FAIL   | 23 | 下载失败  |
| WAITING_INSTALL   | 30 | 待安装  |
| UPDATING   | 31 | 更新中  |
| WATING_APPLY   | 40 | 待生效  |
| APPLYING   | 21 | 生效中  |
| UPGRADE_SUCCESS   | 50 | 升级成功  |
| UPGRADE_FAIL   | 51 | 升级失败  |

## EventClassify

事件类型。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| TASK   | 0x01000000 | 任务事件  |

## EventId

事件ID。

**系统能力**：以下各项对应的系统能力均为:SystemCapability.Update.UpdateService

| 参数名                 | 默认值  | 说明       |
| ------------------- | ---- | -------- |
| EVENT_TASK_BASE   | 0x01000000 | 任务事件  |
| EVENT_TASK_RECEIVE   | 0x01000001 | 收到任务  |
| EVENT_TASK_CANCEL   | 0x01000010 | 取消任务  |
| EVENT_DOWNLOAD_WAIT   | 0x01000011 | 待下载  |
| EVENT_DOWNLOAD_START   | 0x01000100 | 开始下载  |
| EVENT_DOWNLOAD_UPDATE   | 0x01000101 | 下载进度更新  |
| EVENT_DOWNLOAD_PAUSE   | 0x01000110 | 下载暂停  |
| EVENT_DOWNLOAD_RESUME   | 0x01000111 | 恢复下载  |
| EVENT_DOWNLOAD_SUCCESS   | 0x01001000 | 下载成功  |
| EVENT_DOWNLOAD_FAIL   | 0x01001001 | 下载失败  |
| EVENT_UPGRADE_WAIT   | 0x01001010 | 待升级  |
| EVENT_UPGRADE_START   | 0x01001100 | 开始升级  |
| EVENT_UPGRADE_UPDATE   | 0x01001101 | 升级中  |
| EVENT_APPLY_WAIT   | 0x01001110 | 待生效  |
| EVENT_APPLY_START   | 0x01001111 | 开始生效  |
| EVENT_UPGRADE_SUCCESS   | 0x01010000 | 更新成功  |
| EVENT_UPGRADE_FAIL   | 0x01010001 | 更新失败  |
