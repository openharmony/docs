# @ohos.dlpPermission    
数据防泄漏（DLP）是OpenHarmony提供的系统级的数据防泄漏解决方案，提供跨设备的文件的权限管理、加密存储、授权访问等能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import dlpPermission from '@ohos.dlpPermission'    
```  
    
## GatheringPolicyType    
DLP沙箱聚合策略类型的枚举。沙箱聚合表示同一权限类型的DLP文件，在同一个沙箱内打开，例如在同一个沙箱内使用不同tab页打开；沙箱非聚合表示不同DLP文件在不同沙箱打开。    
    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GATHERING | 1 | 表示沙箱聚合。 |  
| NON_GATHERING | 2 | 表示沙箱非聚合。 |  
    
## getDLPGatheringPolicy    
查询DLP沙箱聚合策略。  
 **调用形式：**     
    
- getDLPGatheringPolicy(): Promise\<GatheringPolicyType>    
起始版本： 10    
- getDLPGatheringPolicy(callback: AsyncCallback\<GatheringPolicyType>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | | callback | AsyncCallback<[GatheringPolicyType](#gatheringpolicytype)> | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 | |  
| Promise<GatheringPolicyType> | Promise对象。返回当前DLP沙箱聚合策略。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
| 401 | Parameter error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.getDLPGatheringPolicy((err, res) => {  
    if (err != undefined) {  
      console.error('getDLPGatheringPolicy error,', err.code, err.message);  
    } else {  
      console.info('res', JSON.stringify(res));  
    }  
  }); // 获取沙箱聚合策略  
} catch (err) {  
  console.error('getDLPGatheringPolicy error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let res: Promise<dlpPermission.GatheringPolicyType> = dlpPermission.getDLPGatheringPolicy(); // 获取沙箱聚合策略  
  console.info('res', JSON.stringify(res));  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## DLPSandboxInfo    
表示DLP沙箱的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| appIndex | number | false | true | 表示DLP沙箱应用索引。 |  
| tokenID | number | false | true | 表示DLP沙箱应用的tokenID。 |  
    
## installDLPSandbox    
安装一个应用的DLP沙箱。  
 **调用形式：**     
    
- installDLPSandbox(     bundleName: string,     access: DLPFileAccess,     userId: number,     uri: string   ): Promise\<DLPSandboxInfo>    
起始版本： 10    
- installDLPSandbox(     bundleName: string,     access: DLPFileAccess,     userId: number,     uri: string,     callback: AsyncCallback\<DLPSandboxInfo>   ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用包名。 |  
| access | DLPFileAccess | true | DLP文件授权类型。 |  
| userId | number | true | 当前的用户ID，通过帐号子系统获取的OS帐号ID，默认主用户ID：100。 |  
| uri | string | true | DLP文件的URI。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取应用沙箱信息的回调。 |  
| Promise<DLPSandboxInfo> | Promise对象。安装沙箱应用，返回应用沙箱信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
try {  
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri, (err, res) => {  
    if (err != undefined) {  
      console.error('installDLPSandbox error,', err.code, err.message);  
    } else {  
      console.info('res', JSON.stringify(res));  
    }  
  }); // 安装DLP沙箱  
} catch (err) {  
  console.error('installDLPSandbox error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
try {  
  let res: Promise<dlpPermission.DLPSandboxInfo> = dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri); // 安装DLP沙箱  
  console.info('res', JSON.stringify(res));  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## uninstallDLPSandbox    
卸载一个应用的DLP沙箱。  
 **调用形式：**     
    
- uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number): Promise\<void>    
起始版本： 10    
- uninstallDLPSandbox(     bundleName: string,     userId: number,     appIndex: number,     callback: AsyncCallback\<void>   ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用包名。 |  
| userId | number | true | 当前的用户ID，通过帐号子系统获取的系统帐号ID，默认主用户ID：100 |  
| appIndex | number | true | DLP沙箱号。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取卸载结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
try {  
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri).then((res)=>{  
    console.info('res', JSON.stringify(res));  
    dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, res.appIndex, (err, res) => {  
      if (err != undefined) {  
        console.error('uninstallDLPSandbox error,', err.code, err.message);  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
    });  
  }); // 安装DLP沙箱  
} catch (err) {  
  console.error('uninstallDLPSandbox error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
try {  
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri).then((res)=>{  
    console.info('res', JSON.stringify(res));  
    dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, res.appIndex); // 卸载DLP沙箱  
  }); // 安装DLP沙箱  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## DLPSandboxState    
DLP沙箱身份。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | 表示应用包名。 |  
| appIndex | number | false | true | 表示DLP沙箱应用索引。 |  
    
## on('uninstallDLPSandbox')    
注册监听DLP沙箱卸载事件。  
 **调用形式：**     
- on(type: 'uninstallDLPSandbox', listener: Callback\<DLPSandboxState>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件类型。 |  
| listener | Callback<DLPSandboxState> | true | 沙箱应用卸载事件的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.on('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {  
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)  
  }); // 订阅  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## off('uninstallDLPSandbox')    
取消监听DLP沙箱卸载事件。  
 **调用形式：**     
- off(type: 'uninstallDLPSandbox', listener?: Callback\<DLPSandboxState>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件类型。 |  
| listener | Callback<DLPSandboxState> | false | 沙箱应用卸载事件的回调。默认为空，表示取消该类型事件的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.off('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {  
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)  
  }); // 取消订阅  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## AccountType    
授权帐号类型的枚举。    
    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CLOUD_ACCOUNT | 1 | 表示云帐号。 |  
| DOMAIN_ACCOUNT | 2 | 表示域帐号。 |  
    
## AuthUser    
表示授权用户数据。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| authAccount | string | false | true | 表示被授权用户帐号。 |  
| authAccountType | AccountType | false | true | 表示被授权用户帐号类型。 |  
| dlpFileAccess | DLPFileAccess | false | true | 表示被授予的权限。 |  
| permExpiryTime | number | false | true | 表示授权到期时间。 |  
    
## DLPProperty    
表示授权相关信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ownerAccount | string | false | true | 表示权限设置者帐号。 |  
| ownerAccountID | string | false | true | 表示权限设置者帐号的ID。 |  
| ownerAccountType | AccountType | false | true | 表示权限设置者帐号类型。 |  
| authUserList | Array<AuthUser> | false | false | 表示授权用户列表，默认为空。 |  
| contactAccount | string | false | true | 表示联系人帐号。 |  
| offlineAccess | boolean | false | true | 表示是否是离线打开。 |  
| everyoneAccessList | Array<DLPFileAccess> | false | false | 表示授予所有人的权限，默认为空。 |  
    
## DLPFile    
管理DLPFile的实例，表示一个DLP文件对象，需要通过[generateDLPFile](#dlppermissiongeneratedlpfile)/[openDLPFile](#dlppermissionopendlpfile)获取DLPFile的示例。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| dlpProperty | DLPProperty | false | true | 表示DLP文件授权相关信息。 |  
    
### addDLPLinkFile    
在FUSE文件系统(Filesystem in Userspace)添加link文件(FUSE文件系统中映射到密文的虚拟文件，对该文件的读写操作会同步到DLP文件)。  
 **调用形式：**     
    
- addDLPLinkFile(linkFileName: string): Promise\<void>    
起始版本： 10    
- addDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| linkFileName | string | true | 用于fuse文件系统的link文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取添加结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link', async (err, res) => {  
      if (err != undefined) {  
        console.error('addDLPLinkFile error,', err.code, err.message);  
        await dlpFile.closeDLPFile(); //关闭DLP对象  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
    });  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('addDLPLinkFile error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
### stopFuseLink    
停止FUSE关联读写。  
 **调用形式：**     
    
- stopFuseLink(): Promise\<void>    
起始版本： 10    
- stopFuseLink(callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取停止结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 19100001 | Invalid parameter value. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
| 401 | Parameter error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.stopFuseLink(async (err, res) => {  
      if (err != undefined) {  
        console.error('stopFuseLink error,', err.code, err.message);  
        await dlpFile.closeDLPFile(); //关闭DLP对象  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
    });  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('stopFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.stopFuseLink(); // 暂停link读写  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
    
```    
  
    
### resumeFuseLink    
恢复FUSE关联读写。  
 **调用形式：**     
    
- resumeFuseLink(): Promise\<void>    
起始版本： 10    
- resumeFuseLink(callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取恢复结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 19100001 | Invalid parameter value. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
| 401 | Parameter error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.stopFuseLink(); // 暂停link读写  
    dlpFile.resumeFuseLink(async (err, res) => {  
      if (err != undefined) {  
        console.error('resumeFuseLink error,', err.code, err.message);  
        await dlpFile.closeDLPFile(); //关闭DLP对象  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
    });  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('resumeFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.stopFuseLink(); // 暂停link读写  
    dlpFile.resumeFuseLink(); // 恢复link读写  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
    
```    
  
    
### replaceDLPLinkFile    
替换link文件。  
 **调用形式：**     
    
- replaceDLPLinkFile(linkFileName: string): Promise\<void>    
起始版本： 10    
- replaceDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| linkFileName | string | true | 用于fuse文件系统的link文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取替换结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback<span style="letter-spacing: 0px;">）:</span>  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.stopFuseLink(); // 暂停link读写  
    dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link', async (err, res) => { // 替换link文件  
      if (err != undefined) {  
        console.error('replaceDLPLinkFile error,', err.code, err.message);  
        await dlpFile.closeDLPFile(); //关闭DLP对象  
      } else {  
        console.info('res', JSON.stringify(res));  
        await dlpFile.resumeFuseLink(); // 恢复link读写  
      }  
    });  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.stopFuseLink(); // 暂停link读写  
    dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link'); // 替换link文件  
    dlpFile.resumeFuseLink(); // 恢复link读写  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
    
```    
  
    
### deleteDLPLinkFile    
删除fuse文件系统中创建的link文件。  
 **调用形式：**     
    
- deleteDLPLinkFile(linkFileName: string): Promise\<void>    
起始版本： 10    
- deleteDLPLinkFile(linkFileName: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| linkFileName | string | true | 用于fuse文件系统的link文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取删除结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.deleteDLPLinkFile('test.txt.dlp.link', async (err, res) => { // 删除link文件  
      if (err != undefined) {  
        console.error('deleteDLPLinkFile error,', err.code, err.message);  
        await dlpFile.closeDLPFile(); //关闭DLP对象  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
    });  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件  
    dlpFile.deleteDLPLinkFile('test.txt.dlp.link'); // 删除link文件  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
    
```    
  
    
### recoverDLPFile    
移除DLP文件的权限控制，恢复成明文文件。  
 **调用形式：**     
    
- recoverDLPFile(plaintextFd: number): Promise\<void>    
起始版本： 10    
- recoverDLPFile(plaintextFd: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| plaintextFd | number | true | 目标明文文件的fd。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取恢复结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100002 | Credential task error. |  
| 19100003 | Credential task time out. |  
| 19100004 | Credential service error. |  
| 19100005 | Remote credential server error. |  
| 19100008 | Not DLP file. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100010 | DLP file is read-only. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
let destFile = fs.openSync("destUri");  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.recoverDLPFile(destFile.fd, async (err, res) => { // 还原DLP文件  
      if (err != undefined) {  
        console.error('recoverDLPFile error,', err.code, err.message);  
        await dlpFile.closeDLPFile(); //关闭DLP对象  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
    });  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
let destFile = fs.openSync("destUri");  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.recoverDLPFile(destFile.fd); // 还原DLP文件  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
fs.closeSync(destFile);  
    
```    
  
    
### closeDLPFile    
关闭DLPFile，释放对象。  
 **调用形式：**     
    
- closeDLPFile(): Promise\<void>    
起始版本： 10    
- closeDLPFile(callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取关闭结果的回调。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 19100001 | Invalid parameter value. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.closeDLPFile((err, res) => { // 关闭DLP文件  
      if (err != undefined) {  
        console.error('closeDLPFile error,', err.code, err.message);  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
      fs.closeSync(file);  
    });  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);  
  fs.closeSync(file);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
    
```    
  
    
## generateDLPFile    
将明文文件加密生成权限受控文件，仅在授权列表内的用户可以打开，授权又分为完全控制权限和只读权限。获取DLPFile管理对象  
 **调用形式：**     
    
- generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty): Promise\<DLPFile>    
起始版本： 10    
- generateDLPFile(     plaintextFd: number,     ciphertextFd: number,     property: DLPProperty,     callback: AsyncCallback\<DLPFile>   ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| plaintextFd | number | true | 待加密明文文件的fd。 |  
| ciphertextFd | number | true | 目标加密文件的fd。 |  
| property | DLPProperty | true | 授权用户信息：授权用户列表、owner帐号、联系人帐号。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回DLPFile对象。 |  
| Promise<DLPFile> | Promise对象。返回对象表示成功生成DLP文件，返回null表示失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100002 | Credential task error. |  
| 19100003 | Credential task time out. |  
| 19100004 | Credential service error. |  
| 19100005 | Remote credential server error. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let dlpUri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt";  
let file = fs.openSync(uri);  
let dlp = fs.openSync(dlpUri);  
try {  
  let dlpProperty: dlpPermission.DLPProperty = {  
    ownerAccount: 'zhangsan',  
    ownerAccountType: dlpPermission.AccountType.DOMAIN_ACCOUNT,  
    authUserList: [],  
    contactAccount: 'zhangsan',  
    offlineAccess: true,  
    ownerAccountID: 'xxxxxxx',  
    everyoneAccessList: []  
  };  
  dlpPermission.generateDLPFile(file.fd, dlp.fd, dlpProperty, (err, res) => { // 生成DLP文件  
    if (err != undefined) {  
      console.error('generateDLPFile error,', err.code, err.message);  
    } else {  
      console.info('res', JSON.stringify(res));  
    }  
  });  
} catch (err) {  
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);  
  fs.closeSync(file);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
let dlpUri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt";  
let file = fs.openSync(uri);  
let dlp = fs.openSync(dlpUri);  
try {  
  let dlpProperty: dlpPermission.DLPProperty = {  
    ownerAccount: 'zhangsan',  
    ownerAccountType: dlpPermission.AccountType.DOMAIN_ACCOUNT,  
    authUserList: [],  
    contactAccount: 'zhangsan',  
    offlineAccess: true,  
    ownerAccountID: 'xxxxxxx',  
    everyoneAccessList: []  
  };  
  dlpPermission.generateDLPFile(file.fd, dlp.fd, dlpProperty).then((dlpFile)=>{  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 生成DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
fs.closeSync(dlp);  
    
```    
  
    
## openDLPFile    
打开DLP文件。获取DLPFile管理对象  
 **调用形式：**     
    
- openDLPFile(ciphertextFd: number): Promise\<DLPFile>    
起始版本： 10    
- openDLPFile(ciphertextFd: number, callback: AsyncCallback\<DLPFile>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention  
 **需要权限：** ohos.permission.ACCESS_DLP_FILE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ciphertextFd | number | true | 加密文件的fd。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回DLPFile对象。 |  
| Promise<DLPFile> | Promise对象。返回对象表示打开生成DLP文件，返回null表示失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100002 | Credential task error. |  
| 19100003 | Credential task time out. |  
| 19100004 | Credential service error. |  
| 19100005 | Remote credential server error. |  
| 19100008 | Not DLP file. |  
| 19100009 | Failed to operate the DLP file. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;  
let appId = "";  
  
try{  
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {  
    if (err) {  
      console.error('error', err.code, err.message);  
    } else {  
      appId = data.sinagtureInfo.appId;  
    }  
  })  
} catch (err) {  
  console.error('error', err.code, err.message);  
}  
  
try {  
  dlpPermission.openDLPFile(file.fd, appId, (err, res) => { // 打开DLP文件  
    if (err != undefined) {  
      console.error('openDLPFile error,', err.code, err.message);  
    } else {  
      console.info('res', JSON.stringify(res));  
    }  
  });  
} catch (err) {  
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);  
  fs.closeSync(file);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import bundleManager from '@ohos.bundle.bundleManager';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
let file = fs.openSync(uri);  
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;  
let appId = "";  
  
try{  
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {  
    if (err) {  
      console.error('error', err.code, err.message);  
    } else {  
      appId = data.sinagtureInfo.appId;  
    }  
  })  
} catch (err) {  
  console.error('error', err.code, err.message);  
}  
  
try {  
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{  
    dlpFile.closeDLPFile(); //关闭DLP对象  
  }); // 打开DLP文件  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
    
```    
  
