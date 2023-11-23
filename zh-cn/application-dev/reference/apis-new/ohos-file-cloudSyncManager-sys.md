# @ohos.file.cloudSyncManager    
该模块向云空间应用提供端云同步管理能力，包括使能/去使能端云协同能力、修改应用同步开关，云端数据变化通知以及帐号退出清理/保留云相关文件等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import cloudSyncManager from '@ohos.file.cloudSyncManager'    
```  
    
## changeAppCloudSwitch    
异步方法修改应用的端云文件同步开关。  
 **调用形式：**     
    
- changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise\<void>    
起始版本： 10    
- changeAppCloudSwitch(     accountId: string,     bundleName: string,     status: boolean,     callback: AsyncCallback\<void>   ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.DistributedFileService.CloudSyncManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 帐号Id |  
| bundleName | string | true | 应用包名 |  
| status | boolean | true | 修改的应用云同步开关状态，true为打开，false为关闭 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步修改应用的端云文件同步开关之后的回调 |  
| Promise<void> | 使用Promise形式返回修改应用的端云文件同步开关的结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
let bundleName: string = "com.example.bundle";  
cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true, (err: BusinessError) => {  
  if (err) {  
    console.info("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("changeAppCloudSwitch successfully");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
let bundleName: string = "com.example.bundle";  
cloudSyncManager.changeAppCloudSwitch(accountId, bundleName, true).then(() => {  
  console.info("changeAppCloudSwitch successfully");  
}).catch((err: BusinessError) => {  
  console.info("changeAppCloudSwitch failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## notifyDataChange    
异步方法通知端云服务应用的云数据变更。  
 **调用形式：**     
    
- notifyDataChange(accountId: string, bundleName: string): Promise\<void>    
起始版本： 10    
- notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.DistributedFileService.CloudSyncManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 帐号Id |  
| bundleName | string | true | 应用包名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步通知端云服务应用的云数据变更之后的回调 |  
| Promise<void> | 使用Promise形式返回通知端云服务应用的云数据变更的结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
let bundleName: string = "com.example.bundle";  
cloudSyncManager.notifyDataChange(accountId, bundleName, (err: BusinessError) => {  
  if (err) {  
    console.info("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("notifyDataChange successfully");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
let bundleName: string = "com.example.bundle";  
cloudSyncManager.notifyDataChange(accountId, bundleName).then(() => {  
  console.info("notifyDataChange successfully");  
}).catch((err: BusinessError) => {  
  console.info("notifyDataChange failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## enableCloud    
异步方法使能端云协同能力。  
 **调用形式：**     
    
- enableCloud(accountId: string, switches: { [bundleName: string]: boolean }): Promise\<void>    
起始版本： 10    
- enableCloud(     accountId: string,     switches: { [bundleName: string]: boolean },     callback: AsyncCallback\<void>   ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.DistributedFileService.CloudSyncManager  
 **需要权限：** ohos.permission.CLOUDFILE_SYNC_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 帐号Id |  
| switches | { [bundleName: string]: boolean } | true | 应用的端云协同特性使能开关，bundleName为应用包名，开关状态是个boolean类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步使能端云协同能力之后的回调 |  
| Promise<void> | 使用Promise形式返回使能端云协同能力的结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
let switches: Record<string, boolean> = {  
  'com.example.bundleName1': true,  
  'com.example.bundleName2': false  
}  
cloudSyncManager.enableCloud(accountId, switches, (err: BusinessError) => {  
  if (err) {  
    console.info("enableCloud failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("enableCloud successfully");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
let switches: Record<string, boolean> = {  
  'com.example.bundleName1': true,  
  'com.example.bundleName2': false  
}  
cloudSyncManager.enableCloud(accountId, switches).then(() => {  
  console.info("enableCloud successfully");  
}).catch((err: BusinessError) => {  
  console.info("enableCloud failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## disableCloud    
异步方法去使能端云协同能力。  
 **调用形式：**     
    
- disableCloud(accountId: string): Promise\<void>    
起始版本： 10    
- disableCloud(accountId: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.DistributedFileService.CloudSyncManager  
 **需要权限：** ohos.permission.CLOUDFILE_SYNC_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 帐号Id |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步去使能端云协同能力之后的回调 |  
| Promise<void> | 使用Promise形式返回去使能端云协同能力的结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
cloudSyncManager.disableCloud(accountId, (err: BusinessError) => {  
  if (err) {  
    console.info("disableCloud failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("disableCloud successfully");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
cloudSyncManager.disableCloud(accountId).then(() => {  
  console.info("disableCloud successfully");  
}).catch((err: BusinessError) => {  
  console.info("disableCloud failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## Action    
清理本地云相关数据时的Action，为枚举类型。    
    
 **系统能力:**  SystemCapability.FileManagement.DistributedFileService.CloudSyncManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RETAIN_DATA | 0 | 仅清除云端标识，保留本地缓存文件 |  
| CLEAR_DATA | 1 | 清除云端标识信息，若存在本地缓存文件，一并删除 |  
    
## clean    
异步方法清理本地云相关数据。  
 **调用形式：**     
    
- clean(accountId: string, appActions: { [bundleName: string]: Action }): Promise\<void>    
起始版本： 10    
- clean(accountId: string, appActions: { [bundleName: string]: Action }, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.DistributedFileService.CloudSyncManager  
 **需要权限：** ohos.permission.CLOUDFILE_SYNC_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 帐号Id |  
| appActions | { [bundleName: string]: Action } | true | 清理动作类型，bundleName为待清理应用包名, [Action](#action)为清理动作类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步方法清理本地云相关数据 |  
| Promise<void> | 使用Promise形式返回清理本地云相关数据的结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
  let appActions: Record<string, cloudSyncManager.Action> = {  
  'com.example.bundleName1': cloudSyncManager.Action.RETAIN_DATA,  
  'com.example.bundleName2': cloudSyncManager.Action.CLEAR_DATA  
};  
cloudSyncManager.clean(accountId, appActions, (err: BusinessError) => {  
  if (err) {  
    console.info("clean failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("clean successfully");  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let accountId: string = "testAccount";  
let appActions: Record<string, cloudSyncManager.Action> = {  
  'com.example.bundleName1': cloudSyncManager.Action.RETAIN_DATA,  
  'com.example.bundleName2': cloudSyncManager.Action.CLEAR_DATA  
};  
cloudSyncManager.clean(accountId, appActions).then(() => {  
  console.info("clean successfully");  
}).catch((err: BusinessError) => {  
  console.info("clean failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
