# @ohos.update    
升级范围：升级整个系统，包括内置资源和预置应用，不包括三方应用。  
升级类型：SD卡升级、在线升级。  
- SD卡升级依赖升级包和SD卡安装。- 在线升级依赖设备厂商部署的用于管理升级包的服务器。服务器由设备厂商部署，IP由调用者传入，请求的request接口是固定的，由设备厂商开发。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import update from '@ohos.update'    
```  
    
## getOnlineUpdater    
获取在线升级对象。  
 **调用形式：**     
- getOnlineUpdater(upgradeInfo: UpgradeInfo): Updater  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| upgradeInfo | UpgradeInfo | true | 升级对象信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Updater | 升级对象。 |  
    
 **示例代码：**   
```ts    
try {  
      const upgradeInfo: update.UpgradeInfo = {  
        upgradeApp: "com.ohos.ota.updateclient",  
        businessType: {  
          vendor: update.BusinessVendor.PUBLIC,  
          subType: update.BusinessSubType.FIRMWARE  
        }  
      };  
      let updater = update.getOnlineUpdater(upgradeInfo);  
    } catch(error) {  
      console.error(`Fail to get updater error: ${error}`);  
    }  
    
```    
  
    
## getRestorer    
获取恢复出厂设置对象。  
 **调用形式：**     
- getRestorer(): Restorer  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Restorer | 恢复出厂对象。 |  
    
 **示例代码：**   
```ts    
try {  
  let restorer = update.getRestorer();  
} catch(error) {  
  console.error(`Fail to get restorer: ${error}`);  
}  
    
```    
  
    
## getLocalUpdater    
获取本地升级对象。  
 **调用形式：**     
- getLocalUpdater(): LocalUpdater  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| LocalUpdater | 本地升级对象。 |  
    
 **示例代码：**   
```null    
try {  
  let localUpdater = update.getLocalUpdater();  
} catch(error) {  
  console.error(`Fail to get localUpdater error: ${error}`);  
};  
    
```    
  
    
## Updater  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### checkNewVersion    
检查新版本信息。  
 **调用形式：**     
    
- checkNewVersion(callback: AsyncCallback\<CheckResult>): void    
起始版本： 9    
- checkNewVersion(): Promise\<CheckResult>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回搜包结果对象。 |  
| Promise<CheckResult> | Promise对象，返回搜包结果对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.checkNewVersion((err: BusinessError, result: update.CheckResult) => {  
      console.log(`checkNewVersion isExistNewVersion  ${result?.isExistNewVersion}`);  
    });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.checkNewVersion()  
      .then((result: update.CheckResult) => {  
        console.log(`checkNewVersion isExistNewVersion: ${result.isExistNewVersion}`);  
        // 版本摘要信息  
        console.log(`checkNewVersion versionDigestInfo: ${result.newVersionInfo.versionDigestInfo.versionDigest}`);  
      })  
      .catch((err: BusinessError)=>{  
        console.log(`checkNewVersion promise error ${JSON.stringify(err)}`);  
      })  
    
```    
  
    
### getNewVersionInfo    
获取新版本信息。  
 **调用形式：**     
    
- getNewVersionInfo(callback: AsyncCallback\<NewVersionInfo>): void    
起始版本： 9    
- getNewVersionInfo(): Promise\<NewVersionInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回新版本信息对象。 |  
| Promise<NewVersionInfo> | Promise对象，返回新版本信息对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getNewVersionInfo((err: BusinessError, info: update.NewVersionInfo) => {  
      console.log(`info displayVersion = ${info?.versionComponents[0].displayVersion}`);  
      console.log(`info innerVersion = ${info?.versionComponents[0].innerVersion}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getNewVersionInfo().then((info: update.NewVersionInfo) => {  
    console.log(`info displayVersion = ${info.versionComponents[0].displayVersion}`);  
    console.log(`info innerVersion = ${info.versionComponents[0].innerVersion}`);  
}).catch((err: BusinessError) => {  
    console.log(`getNewVersionInfo promise error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### getNewVersionDescription    
获取新版本描述文件。  
 **调用形式：**     
    
- getNewVersionDescription(       versionDigestInfo: VersionDigestInfo,       descriptionOptions: DescriptionOptions,       callback: AsyncCallback\<Array\<ComponentDescription>>     ): void    
起始版本： 9    
- getNewVersionDescription(       versionDigestInfo: VersionDigestInfo,       descriptionOptions: DescriptionOptions     ): Promise\<Array\<ComponentDescription>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | true | 版本摘要信息。 |  
| descriptionOptions | DescriptionOptions | true | 描述文件选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回新版本描述文件。 |  
| Promise<Array<ComponentDescription>> | Promise对象，返回新版本描述文件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 描述文件选项  
const descriptionOptions: update.DescriptionOptions = {  
  format: update.DescriptionFormat.STANDARD, // 标准格式  
  language: "zh-cn" // 中文  
};  
  
updater.getNewVersionDescription(versionDigestInfo, descriptionOptions).then((info: Array<update.ComponentDescription>)=> {  
  console.log(`getNewVersionDescription promise info ${JSON.stringify(info)}`);  
}).catch((err: BusinessError) => {  
  console.log(`getNewVersionDescription promise error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 描述文件选项  
const descriptionOptions: update.DescriptionOptions = {  
  format: update.DescriptionFormat.STANDARD, // 标准格式  
  language: "zh-cn" // 中文  
};  
  
updater.getNewVersionDescription(versionDigestInfo, descriptionOptions).then((info: Array<update.ComponentDescription>)=> {  
  console.log(`getNewVersionDescription promise info ${JSON.stringify(info)}`);  
}).catch((err: BusinessError) => {  
  console.log(`getNewVersionDescription promise error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### getCurrentVersionInfo    
获取当前版本信息。  
 **调用形式：**     
    
- getCurrentVersionInfo(callback: AsyncCallback\<CurrentVersionInfo>): void    
起始版本： 9    
- getCurrentVersionInfo(): Promise\<CurrentVersionInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前版本信息对象。 |  
| Promise<CurrentVersionInfo> | Promise对象，返回当前版本信息对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getCurrentVersionInfo((err: BusinessError, info: update.CurrentVersionInfo) => {  
  console.log(`info osVersion = ${info?.osVersion}`);  
  console.log(`info deviceName = ${info?.deviceName}`);  
  console.log(`info displayVersion = ${info?.versionComponents[0].displayVersion}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getCurrentVersionInfo().then((info: update.CurrentVersionInfo) => {  
  console.log(`info osVersion = ${info.osVersion}`);  
  console.log(`info deviceName = ${info.deviceName}`);  
  console.log(`info displayVersion = ${info.versionComponents[0].displayVersion}`);  
}).catch((err: BusinessError) => {  
  console.log(`getCurrentVersionInfo promise error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### getCurrentVersionDescription    
获取当前版本描述文件。  
 **调用形式：**     
    
- getCurrentVersionDescription(       descriptionOptions: DescriptionOptions,       callback: AsyncCallback\<Array\<ComponentDescription>>     ): void    
起始版本： 9    
- getCurrentVersionDescription(descriptionOptions: DescriptionOptions): Promise\<Array\<ComponentDescription>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptionOptions | DescriptionOptions | true | 描述文件选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前版本描述文件。 |  
| Promise<Array<ComponentDescription>> | Promise对象，返回当前版本描述文件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
// 描述文件选项const descriptionOptions: update.DescriptionOptions = {  format: update.DescriptionFormat.STANDARD, // 标准格式  language: "zh-cn" // 中文};  
updater.getCurrentVersionDescription(descriptionOptions, (err, info) => {  console.log(`getCurrentVersionDescription info ${JSON.stringify(info)}`);  console.log(`getCurrentVersionDescription err ${JSON.stringify(err)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
const descriptionOptions: update.DescriptionOptions = {  format: update.DescriptionFormat.STANDARD, // 标准格式  language: "zh-cn" // 中文};updater.getCurrentVersionDescription(descriptionOptions).then((info: Array<update.ComponentDescription>) => {  console.log(`getCurrentVersionDescription promise info ${JSON.stringify(info)}`);}).catch((err: BusinessError) => {  console.log(`getCurrentVersionDescription promise error ${JSON.stringify(err)}`);});    
```    
  
    
### getTaskInfo    
获取升级任务信息。  
 **调用形式：**     
    
- getTaskInfo(callback: AsyncCallback\<TaskInfo>): void    
起始版本： 9    
- getTaskInfo(): Promise\<TaskInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回升级任务信息对象。 |  
| Promise<TaskInfo> | Promise对象，返回任务信息对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getTaskInfo((err: BusinessError, info: update.TaskInfo) => {  
  console.log(`getTaskInfo isexistTask= ${info?.existTask}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getTaskInfo().then((info: update.TaskInfo) => {  
  console.log(`getTaskInfo isexistTask= ${info.existTask}`);  
}).catch((err: BusinessError) => {  
  console.log(`getTaskInfo promise error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### download    
下载新版本。  
 **调用形式：**     
    
- download(       versionDigestInfo: VersionDigestInfo,       downloadOptions: DownloadOptions,       callback: AsyncCallback\<void>     ): void    
起始版本： 9    
- download(versionDigestInfo: VersionDigestInfo, downloadOptions: DownloadOptions): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | true | 版本摘要信息。 |  
| downloadOptions | DownloadOptions | true | 下载选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当下载成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 下载选项  
const downloadOptions: update.DownloadOptions = {  
  allowNetwork: update.NetType.CELLULAR, // 允许数据网络下载  
  order: update.Order.DOWNLOAD // 下载  
};  
updater.download(versionDigestInfo, downloadOptions, (err: BusinessError) => {  
  console.log(`download error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 下载选项  
const downloadOptions: update.DownloadOptions = {  
  allowNetwork: update.NetType.CELLULAR, // 允许数据网络下载  
   order: update.Order.DOWNLOAD // 下载  
};  
updater.download(versionDigestInfo, downloadOptions).then(() => {  
  console.log(`download start`);  
}).catch((err: BusinessError) => {  
  console.log(`download error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### resumeDownload    
恢复下载新版本。  
 **调用形式：**     
    
- resumeDownload(       versionDigestInfo: VersionDigestInfo,       resumeDownloadOptions: ResumeDownloadOptions,       callback: AsyncCallback\<void>     ): void    
起始版本： 9    
- resumeDownload(versionDigestInfo: VersionDigestInfo, resumeDownloadOptions: ResumeDownloadOptions): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | true | 版本摘要信息。 |  
| resumeDownloadOptions | ResumeDownloadOptions | true | 恢复下载选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | | callback              | AsyncCallback\<void>                     | 是    | 回调函数。当恢复下载成功时，err为undefined，否则为错误对象。 | |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo : update.VersionDigestInfo= {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 恢复下载选项  
const resumeDownloadOptions : update.ResumeDownloadOptions= {  
  allowNetwork: update.NetType.CELLULAR, // 允许数据网络下载  
};  
updater.resumeDownload(versionDigestInfo, resumeDownloadOptions, (err: BusinessError) => {  
  console.log(`resumeDownload error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 恢复下载选项  
const resumeDownloadOptions: update.ResumeDownloadOptions = {  
  allowNetwork: update.NetType.CELLULAR, // 允许数据网络下载  
};  
updater.resumeDownload(versionDigestInfo, resumeDownloadOptions).then(() => {  
  console.log(`resumeDownload start`);  
}).catch((err: BusinessError) => {  
  console.log(`resumeDownload error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### pauseDownload    
暂停下载新版本。  
 **调用形式：**     
    
- pauseDownload(       versionDigestInfo: VersionDigestInfo,       pauseDownloadOptions: PauseDownloadOptions,       callback: AsyncCallback\<void>     ): void    
起始版本： 9    
- pauseDownload(versionDigestInfo: VersionDigestInfo, pauseDownloadOptions: PauseDownloadOptions): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | true | 版本摘要信息。 |  
| pauseDownloadOptions | PauseDownloadOptions | true | 暂停下载选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当暂停下载成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 暂停下载选项  
const pauseDownloadOptions: update.PauseDownloadOptions = {  
  isAllowAutoResume: true // 允许自动恢复下载  
};  
updater.pauseDownload(versionDigestInfo, pauseDownloadOptions, (err: BusinessError) => {  
  console.log(`pauseDownload error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 暂停下载选项  
const pauseDownloadOptions: update.PauseDownloadOptions = {  
  isAllowAutoResume: true // 允许自动恢复下载  
};  
updater.pauseDownload(versionDigestInfo, pauseDownloadOptions).then(() => {  
  console.log(`pauseDownload`);  
}).catch((err: BusinessError)  => {  
  console.log(`pauseDownload error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### upgrade    
升级新版本。  
 **调用形式：**     
    
- upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- upgrade(versionDigestInfo: VersionDigestInfo, upgradeOptions: UpgradeOptions): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | true | 版本摘要信息。 |  
| upgradeOptions | UpgradeOptions | true | 更新选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当升级执行成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 安装选项  
const upgradeOptions: update.UpgradeOptions = {  
  order: update.Order.INSTALL // 安装指令  
};  
updater.upgrade(versionDigestInfo, upgradeOptions, (err: BusinessError) => {  
  console.log(`upgrade error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 安装选项  
const upgradeOptions: update.UpgradeOptions = {  
  order: update.Order.INSTALL // 安装指令  
};  
updater.upgrade(versionDigestInfo, upgradeOptions).then(() => {  
  console.log(`upgrade start`);  
}).catch((err: BusinessError) => {  
  console.log(`upgrade error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### clearError    
清除异常状态。  
 **调用形式：**     
    
- clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- clearError(versionDigestInfo: VersionDigestInfo, clearOptions: ClearOptions): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | true | 版本摘要信息。 |  
| clearOptions | ClearOptions | true | 清除选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当清除异常成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 清除选项  
const clearOptions: update.ClearOptions = {  
  status: update.UpgradeStatus.UPGRADE_FAIL,  
};  
updater.clearError(versionDigestInfo, clearOptions, (err: BusinessError) => {  
  console.log(`clearError error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// 版本摘要信息  
const versionDigestInfo: update.VersionDigestInfo = {  
  versionDigest: "versionDigest" // 检测结果中的版本摘要信息  
};  
  
// 清除选项  
const clearOptions: update.ClearOptions = {  
  status: update.UpgradeStatus.UPGRADE_FAIL,  
};  
updater.clearError(versionDigestInfo, clearOptions).then(() => {  
  console.log(`clearError success`);  
}).catch((err: BusinessError) => {  
  console.log(`clearError error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### getUpgradePolicy    
获取升级策略信息。  
 **调用形式：**     
    
- getUpgradePolicy(callback: AsyncCallback\<UpgradePolicy>): void    
起始版本： 9    
- getUpgradePolicy(): Promise\<UpgradePolicy>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回升级策略信息对象。 |  
| Promise<UpgradePolicy> | Promise对象，返回升级策略信息对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getUpgradePolicy(err: BusinessError, policy: update.UpgradePolicy) => {  
  console.log(`policy downloadStrategy = ${policy?.downloadStrategy}`);  
  console.log(`policy autoUpgradeStrategy = ${policy?.autoUpgradeStrategy}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.getUpgradePolicy().then((policy: update.UpgradePolicy) => {  
  console.log(`policy downloadStrategy = ${policy.downloadStrategy}`);  
  console.log(`policy autoUpgradeStrategy = ${policy.autoUpgradeStrategy}`);  
}).catch((err: BusinessError)  => {  
  console.log(`getUpgradePolicy promise error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### setUpgradePolicy    
设置升级策略。  
 **调用形式：**     
    
- setUpgradePolicy(policy: UpgradePolicy, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setUpgradePolicy(policy: UpgradePolicy): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| policy | UpgradePolicy | true | 升级策略。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回设置结果对象。 |  
| Promise<void> | Promise对象。 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
const policy: update.UpgradePolicy = {  
  downloadStrategy: false,  
  autoUpgradeStrategy: false,  
  autoUpgradePeriods: [{ start: 120, end: 240 }] // 自动升级时间段，用分钟表示  
};  
updater.setUpgradePolicy(policy, (err: BusinessError) => {  
  console.log(`setUpgradePolicy result: ${err}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
const policy: update.UpgradePolicy = {  
  downloadStrategy: false,  
  autoUpgradeStrategy: false,  
  autoUpgradePeriods: [ { start: 120, end: 240 } ] // 自动升级时间段，用分钟表示  
};  
updater.setUpgradePolicy(policy).then(() => {  
  console.log(`setUpgradePolicy success`);  
}).catch((err: BusinessError) => {  
  console.log(`setUpgradePolicy promise error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### terminateUpgrade    
终止升级。  
 **调用形式：**     
    
- terminateUpgrade(callback: AsyncCallback\<void>): void    
起始版本： 9    
- terminateUpgrade(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当清除升级缓存成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.terminateUpgrade((err: BusinessError) => {  
  console.log(`terminateUpgrade error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
updater.terminateUpgrade().then(() => {  
  console.log(`terminateUpgrade success`);  
}).catch((err: BusinessError) => {  
  console.log(`terminateUpgrade error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### on    
注册事件监听。使用callback异步回调。  
 **调用形式：**     
- on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventClassifyInfo | EventClassifyInfo | true | 事件信息。 |  
| taskCallback | UpgradeTaskCallback | true | 事件回调。 |  
    
 **示例代码：**   
```ts    
const eventClassifyInfo: update.EventClassifyInfo = {  eventClassify: update.EventClassify.TASK, // 订阅升级更新事件  extraInfo: ""};  
updater.on(eventClassifyInfo, (eventInfo: update.EventInfo) => {  console.log("updater on " + JSON.stringify(eventInfo));});    
```    
  
    
### off    
取消注册事件监听。使用callback异步回调。  
 **调用形式：**     
- off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventClassifyInfo | EventClassifyInfo | true | 事件信息。 |  
| taskCallback | UpgradeTaskCallback | false | 事件回调。 |  
    
 **示例代码：**   
```ts    
const eventClassifyInfo: update.EventClassifyInfo = {  eventClassify: update.EventClassify.TASK, // 订阅升级更新事件  extraInfo: ""};  
updater.off(eventClassifyInfo, (eventInfo: update.EventInfo) => {  console.log("updater off " + JSON.stringify(eventInfo));});    
```    
  
    
## Restorer  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### factoryReset    
恢复出厂设置。  
 **调用形式：**     
    
- factoryReset(callback: AsyncCallback\<void>): void    
起始版本： 9    
- factoryReset(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.FACTORY_RESET    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当恢复出厂执行成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
restorer.factoryReset((err) => {  console.log(`factoryReset error ${JSON.stringify(err)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
restorer.factoryReset().then(() => {  
  console.log(`factoryReset success`);  
}).catch((err: BusinessError) => {  
  console.log(`factoryReset error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
## LocalUpdater    
。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### verifyUpgradePackage    
校验升级包。  
 **调用形式：**     
    
- verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- verifyUpgradePackage(upgradeFile: UpgradeFile, certsFile: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| upgradeFile | UpgradeFile | true | 升级文件。 |  
| certsFile | string | true | 证书文件路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回升级包校验结果对象。 |  
| Promise<void> | Promise对象，返回升级包校验结果对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
const upgradeFile: update.UpgradeFile = {  fileType: update.ComponentType.OTA, // OTA包  filePath: "path" // 本地升级包路径};  
localUpdater.verifyUpgradePackage(upgradeFile, "cerstFilePath", (err) => {  console.log(`factoryReset error ${JSON.stringify(err)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
const upgradeFile: update.UpgradeFile = {  
  fileType: update.ComponentType.OTA, // OTA包  
  filePath: "path" // 本地升级包路径  
};  
localUpdater.verifyUpgradePackage(upgradeFile, "cerstFilePath").then(() => {  
  console.log(`verifyUpgradePackage success`);  
}).catch((err: BusinessError) => {  
  console.log(`verifyUpgradePackage error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### applyNewVersion    
安装升级包。  
 **调用形式：**     
    
- applyNewVersion(upgradeFiles: Array\<UpgradeFile>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- applyNewVersion(upgradeFiles: Array\<UpgradeFile>): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService  
 **需要权限：** ohos.permission.UPDATE_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| upgradeFiles | Array<UpgradeFile> | true | 升级文件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当安装升级包执行成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11500104 | IPC error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
const upgradeFiles: Array<update.UpgradeFile> = [{  fileType: update.ComponentType.OTA, // OTA包  filePath: "path" // 本地升级包路径}];  
localUpdater.applyNewVersion(upgradeFiles, (err) => {  console.log(`applyNewVersion error ${JSON.stringify(err)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
const upgradeFiles: Array<update.UpgradeFile> = [{  
  fileType: update.ComponentType.OTA, // OTA包  
  filePath: "path" // 本地升级包路径  
}];  
localUpdater.applyNewVersion(upgradeFiles).then(() => {  
  console.log(`applyNewVersion success`);  
}).catch((err: BusinessError) => {  
  console.log(`applyNewVersion error ${JSON.stringify(err)}`);  
});  
    
```    
  
    
### on    
注册事件监听。使用callback异步回调。  
 **调用形式：**     
- on(eventClassifyInfo: EventClassifyInfo, taskCallback: UpgradeTaskCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventClassifyInfo | EventClassifyInfo | true | 事件信息。 |  
| taskCallback | UpgradeTaskCallback | true | 事件回调。 |  
    
 **示例代码：**   
```ts    
const eventClassifyInfo: update.EventClassifyInfo = {  eventClassify: update.EventClassify.TASK, // 订阅升级更新事件  extraInfo: ""};  
let onTaskUpdate: update.UpgradeTaskCallback = (eventInfo: update.EventInfo) => {  console.log(`on eventInfo id `, eventInfo.eventId);};localUpdater.on(eventClassifyInfo, onTaskUpdate);    
```    
  
    
### off    
取消注册事件监听。使用callback异步回调。  
 **调用形式：**     
- off(eventClassifyInfo: EventClassifyInfo, taskCallback?: UpgradeTaskCallback): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventClassifyInfo | EventClassifyInfo | true | 事件信息。 |  
| taskCallback | UpgradeTaskCallback | false | 事件回调。 |  
    
 **示例代码：**   
```ts    
const eventClassifyInfo: update.EventClassifyInfo = {  eventClassify: update.EventClassify.TASK, // 订阅升级更新事件  extraInfo: ""};  
let onTaskUpdate: update.UpgradeTaskCallback = (eventInfo: update.EventInfo) => {  console.log(`on eventInfo id `, eventInfo.eventId);};localUpdater.off(eventClassifyInfo, onTaskUpdate);    
```    
  
    
## UpgradeInfo    
升级信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| upgradeApp | string | false | true | 调用方包名。 |  
| businessType | BusinessType | false | true | 升级业务类型。 |  
    
## BusinessType    
升级业务类型。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| vendor | BusinessVendor | false | true | 供应商/厂家。 |  
| subType | BusinessSubType | false | true | 升级类型。 |  
    
## CheckResult    
搜包结果。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isExistNewVersion | boolean | false | true | 是否有新版本。<br>ture表示有新版本，false表示没有新版本。 |  
| newVersionInfo | NewVersionInfo | false | true | 新版本数据。 |  
    
## NewVersionInfo    
新版本数据。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | false | true | 版本摘要。 |  
| versionComponents | Array<VersionComponent> | false | true | 版本组件。 |  
    
## VersionDigestInfo    
版本摘要。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| versionDigest | string | false | true | 版本摘要。 |  
    
## VersionComponent    
版本组件。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| componentId | string | false | true | 组件标识。 |  
| componentType | ComponentType | false | true | 组件类型。 |  
| upgradeAction | UpgradeAction | false | true | 升级方式。 |  
| displayVersion | string | false | true | 显示版本号。 |  
| innerVersion | string | false | true | 版本号。 |  
| size | number | false | true | 升级包大小，单位为B。 |  
| effectiveMode | EffectiveMode | false | true | 生效模式。 |  
| descriptionInfo | DescriptionInfo | false | true | 版本描述文件信息。 |  
    
## DescriptionOptions    
描述文件选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| format | DescriptionFormat | false | true | 描述文件格式。 |  
| language | string | false | true | 描述文件语言。 |  
    
## ComponentDescription    
组件描述文件。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| componentId | string | false | true | 组件标识。 |  
| descriptionInfo | DescriptionInfo | false | true | 描述文件信息。 |  
    
## DescriptionInfo    
版本描述文件信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| descriptionType | DescriptionType | false | true | 描述文件类型。 |  
| content | string | false | true | 描述文件内容。 |  
    
## CurrentVersionInfo    
当前版本信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| osVersion | string | false | true | 系统版本号。 |  
| deviceName | string | false | true | 设备名。 |  
| versionComponents | Array<VersionComponent> | false | true | 版本组件。 |  
    
## DownloadOptions    
下载选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| allowNetwork | NetType | false | true | 网络类型。 |  
| order | Order | false | true | 升级指令。 |  
    
## ResumeDownloadOptions    
恢复下载选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| allowNetwork | NetType | false | true | 网络类型。 |  
    
## PauseDownloadOptions    
暂停下载选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isAllowAutoResume | boolean | false | true | 是否允许自动恢复。<br>ture表示允许自动恢复，false表示不允许。 |  
    
## UpgradeOptions    
升级选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| order | Order | false | true | 升级指令。 |  
    
## ClearOptions    
清除异常选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| status | UpgradeStatus | false | true | 异常状态。 |  
    
## UpgradePolicy    
升级策略。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| downloadStrategy | boolean | false | true | 自动下载策略。 <br>ture表示可自动下载，false表示不可自动下载。 |  
| autoUpgradeStrategy | boolean | false | true | 自动升级策略。 <br>ture表示可自动升级，false表示不可自动升级。 |  
| autoUpgradePeriods | Array<UpgradePeriod> | false | true | 自动升级时间段。 |  
    
## UpgradePeriod    
升级时间段。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| start | number | false | true | 开始时间。 |  
| end | number | false | true | 结束时间。 |  
    
## TaskInfo    
任务信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| existTask | boolean | false | true | 是否存在任务。<br>ture表示存在，false表示不存在。 |  
| taskBody | TaskBody | false | true | 任务数据。 |  
    
## EventInfo    
事件信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eventId | EventId | false | true | 事件ID。 |  
| taskBody | TaskBody | false | true | 任务数据。 |  
    
## TaskBody    
任务数据。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| versionDigestInfo | VersionDigestInfo | false | true | 版本摘要。 |  
| status | UpgradeStatus | false | true | 升级状态。 |  
| subStatus | number | false | true | 子状态。 |  
| progress | number | false | true | 进度。 |  
| installMode | number | false | true | 安装模式。 |  
| errorMessages | Array<ErrorMessage> | false | true | 错误信息。 |  
| versionComponents | Array<VersionComponent> | false | true | 版本组件。 |  
    
## ErrorMessage    
错误信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| errorCode | number | false | true | 错误码。 |  
| errorMessage | string | false | true | 错误描述。 |  
    
## EventClassifyInfo    
事件信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eventClassify | EventClassify | false | true | 事件类型。 |  
| extraInfo | string | false | true | 额外信息。 |  
    
## UpgradeFile    
升级文件。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### 属性    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fileType | ComponentType | false | true | 文件类型。 |  
| filePath | string | false | true | 文件路径。 |  
    
## UpgradeTaskCallback    
  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
### null    
事件回调。  
  
 **调用形式：**     
- (eventInfo: EventInfo): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Update.UpdateService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventInfo | EventInfo | true | 事件信息。 |  
    
## BusinessVendor    
设备厂家。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PUBLIC | public | 开源。 |  
    
## BusinessSubType    
升级类型。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FIRMWARE | 1 | 固件。 |  
    
## ComponentType    
组件类型。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OTA | 1 | 固件。 |  
    
## UpgradeAction    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UPGRADE | upgrade | 差分包。 |  
| RECOVERY | recovery | 修复包。 |  
    
## EffectiveMode    
生效模式。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COLD | 1 | 冷升级。 |  
| LIVE | 2 | 热升级。 |  
| LIVE_AND_COLD | 3 | 融合升级。 |  
    
## DescriptionType    
描述文件类型。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONTENT | 0 | 内容。 |  
| URI | 1 | 链接。 |  
    
## DescriptionFormat    
描述文件格式。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STANDARD | 0 | 标准格式。 |  
| SIMPLIFIED | 1 | 简易格式。 |  
    
## NetType    
网络类型。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CELLULAR | 1 | 数据网络。 |  
| METERED_WIFI | 2 | 热点WIFI。 |  
| NOT_METERED_WIFI | 4 | 非热点WIFI。 |  
| WIFI | 6 | WIFI。 |  
| CELLULAR_AND_WIFI | 7 | 数据网络和WIFI。 |  
    
## Order    
升级指令。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DOWNLOAD | 1 | 下载。 |  
| INSTALL | 2 | 安装。 |  
| DOWNLOAD_AND_INSTALL | 3 | 下载并安装。 |  
| APPLY | 4 | 生效。 |  
| INSTALL_AND_APPLY | 6 | 安装并生效。 |  
    
## UpgradeStatus    
升级状态。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WAITING_DOWNLOAD | 20 | 待下载。 |  
| DOWNLOADING | 21 | 下载中。 |  
| DOWNLOAD_PAUSED | 22 | 下载暂停。 |  
| DOWNLOAD_FAIL | 23 | 下载失败。 |  
| WAITING_INSTALL | 30 | 待安装。 |  
| UPDATING | 31 | 更新中。 |  
| WAITING_APPLY | 40 | 待生效。 |  
| APPLYING | 41 | 生效中。 |  
| UPGRADE_SUCCESS | 50 | 升级成功。 |  
| UPGRADE_FAIL | 51 | 升级失败。 |  
    
## EventClassify    
事件类型。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TASK | 0x01000000 | 任务事件。 |  
    
## EventId    
事件ID。    
    
 **系统能力:**  SystemCapability.Update.UpdateService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EVENT_TASK_BASE | EventClassify.TASK | 任务事件。 |  
| EVENT_TASK_RECEIVE |  | 收到任务。 |  
| EVENT_TASK_CANCEL |  | 取消任务。 |  
| EVENT_DOWNLOAD_WAIT |  | 待下载。 |  
| EVENT_DOWNLOAD_START |  | 开始下载。 |  
| EVENT_DOWNLOAD_UPDATE |  | 下载进度更新。 |  
| EVENT_DOWNLOAD_PAUSE |  | 下载暂停。 |  
| EVENT_DOWNLOAD_RESUME |  | 恢复下载。 |  
| EVENT_DOWNLOAD_SUCCESS |  | 下载成功。 |  
| EVENT_DOWNLOAD_FAIL |  | 下载失败。 |  
| EVENT_UPGRADE_WAIT |  | 待升级。 |  
| EVENT_UPGRADE_START |  | 开始升级。 |  
| EVENT_UPGRADE_UPDATE |  | 升级中。 |  
| EVENT_APPLY_WAIT |  | 待生效。 |  
| EVENT_APPLY_START |  | 开始生效。 |  
| EVENT_UPGRADE_SUCCESS |  | 更新成功。 |  
| EVENT_UPGRADE_FAIL |  | 更新失败。 |  
