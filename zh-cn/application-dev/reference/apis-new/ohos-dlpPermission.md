# @ohos.dlpPermission    
数据防泄漏（DLP）是OpenHarmony提供的系统级的数据防泄漏解决方案，提供跨设备的文件的权限管理、加密存储、授权访问等能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import dlpPermission from '@ohos.dlpPermission'    
```  
    
## ActionFlagType    
可以对DLP文件进行的操作类型枚举。例如：DLP沙箱应用可以根据是否具有操作权限，对其按钮进行置灰。    
    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTION_VIEW | 0x00000001 | 表示文件的查看权限。 |  
| ACTION_SAVE | 0x00000002 | 表示文件的保存权限。 |  
| ACTION_SAVE_AS | 0x00000004 | 表示文件的另存为权限。 |  
| ACTION_EDIT | 0x00000008 | 表示文件的编辑权限。 |  
| ACTION_SCREEN_CAPTURE | 0x00000010 | 表示文件的截屏权限。 |  
| ACTION_SCREEN_SHARE | 0x00000020 | 表示文件的共享屏幕权限。 |  
| ACTION_SCREEN_RECORD | 0x00000040 | 表示文件的录屏权限。 |  
| ACTION_COPY | 0x00000080 | 表示文件的复制权限。 |  
| ACTION_PRINT | 0x00000100 | 表示文件的打印权限。 |  
| ACTION_EXPORT | 0x00000200 | 表示文件的导出权限。 |  
| ACTION_PERMISSION_CHANGE | 0x00000400 | 表示文件的修改文件权限。 |  
    
## DLPFileAccess    
DLP文件授权类型的枚举。    
    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NO_PERMISSION | 0 | 表示无文件权限。 |  
| READ_ONLY | 1 | 表示文件的只读权限。 |  
| CONTENT_EDIT | 2 | 表示文件的编辑权限。 |  
| FULL_CONTROL | 3 | 表示文件的完全控制权限。 |  
    
## DLPPermissionInfo    
表示DLP文件的权限信息。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| dlpFileAccess | DLPFileAccess | false | true | 表示DLP文件针对用户的授权类型，例如：只读 |  
| flags | number | false | true | 表示DLP文件的详细操作权限，是不同[ActionFlagType](#actionflagtype)的组合。 |  
    
## AccessedDLPFileInfo    
表示被打开的DLP文件的信息。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | false | true | 表示DLP文件的uri。 |  
| lastOpenTime | number | false | true | 表示DLP文件最近打开时间。 |  
    
## RetentionSandboxInfo    
保留沙箱的沙箱信息。  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
### 属性    
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| appIndex | number | false | true | 表示DLP沙箱应用索引。 |  
| bundleName | string | false | true | 表示应用包名。 |  
| docUris | Array<string> | false | true | 表示DLP文件的URI列表。 |  
    
## isDLPFile    
根据文件的fd，查询该文件是否是DLP文件  
 **调用形式：**     
    
- isDLPFile(fd: number): Promise\<boolean>    
起始版本： 10    
- isDLPFile(fd: number, callback: AsyncCallback\<boolean>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 文件的fd(file descriptor, 文件描述符)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示是DLP文件，返回false表示非DLP文件。 |  
| Promise<boolean> | Promise对象。返回true表示是DLP文件，返回false表示非DLP文件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
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
  dlpPermission.isDLPFile(file.fd, (err, res) => {  
    if (err != undefined) {  
      console.error('isDLPFile error,', err.code, err.message);  
    } else {  
      console.info('res', res);  
    }  
    fs.closeSync(file);  
  });  
} catch (err) {  
  console.error('isDLPFile error,', (err as BusinessError).code, (err as BusinessError).message);  
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
  let res = dlpPermission.isDLPFile(file.fd); // 是否加密DLP文件  
  console.info('res', res);  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
fs.closeSync(file);  
    
```    
  
    
## getDLPPermissionInfo    
查询当前DLP沙箱的权限信息。  
 **调用形式：**     
    
- getDLPPermissionInfo(): Promise\<DLPPermissionInfo>    
起始版本： 10    
- getDLPPermissionInfo(callback: AsyncCallback\<DLPPermissionInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |  
| Promise<DLPPermissionInfo> | Promise对象。返回查询的DLP文件的权限信息，无异常则表明查询成功。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 19100001 | Invalid parameter value. |  
| 19100006 | No permission to invoke this API, which is for DLP sandbox application. |  
| 19100011 | System service exception. |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内  
  if (inSandbox) {  
    dlpPermission.getDLPPermissionInfo((err, res) => {  
      if (err != undefined) {  
        console.error('getDLPPermissionInfo error,', err.code, err.message);  
      } else {  
        console.info('res', JSON.stringify(res));  
      }  
    }); // 获取当前权限信息  
  }  
} catch (err) {  
  console.error('getDLPPermissionInfo error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内  
  if (inSandbox) {  
    let res: Promise<dlpPermission.DLPPermissionInfo> = dlpPermission.getDLPPermissionInfo(); // 获取当前权限信息  
    console.info('res', JSON.stringify(res));  
  }  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## getOriginalFileName    
获取指定DLP文件名的原始文件名。接口为同步接口。  
 **调用形式：**     
- getOriginalFileName(fileName: string): string  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fileName | string | true | 指定要查询的文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回DLP文件的原始文件名。例如：DLP文件名为test.txt.dlp，则返回的原始文件名为test.txt。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let res = dlpPermission.getOriginalFileName('test.txt.dlp'); // 获取原始文件名  
  console.info('res', res);  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## getDLPSuffix    
获取DLP文件扩展名。接口为同步接口。  
 **调用形式：**     
- getDLPSuffix(): string  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | System service exception. |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 19100011 | 返回DLP文件扩展名。例如：原文件"text.txt"，返回拓展名为".dlp"，加密后的DLP文件名为"test.txt.dlp"。 |  
    
 **示例代码：**   
示例：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let res = dlpPermission.getDLPSuffix(); // 获取DLP拓展名  
  console.info('res', res);  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## on('openDLPFile')    
监听打开DLP文件。在当前应用的沙箱应用打开DLP文件时，通知当前应用。  
 **调用形式：**     
- on(type: 'openDLPFile', listener: Callback\<AccessedDLPFileInfo>): void  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件类型。'openDLPFile'：打开DLP文件。 |  
| listener | Callback<AccessedDLPFileInfo> | true | DLP文件打开事件的回调。在当前应用的沙箱应用打开DLP文件时，通知当前应用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100007 | No permission to invoke this API, which is not for DLP sandbox application. |  
| 19100011 | System service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.on('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {  
    console.info('openDlpFile event', info.uri, info.lastOpenTime)  
  }); // 订阅  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## off('openDLPFile')    
取消监听打开DLP文件。在当前应用的沙箱应用打开DLP文件时，取消通知当前应用。  
 **调用形式：**     
- off(type: 'openDLPFile', listener?: Callback\<AccessedDLPFileInfo>): void  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件类型。'openDLPFile'：打开DLP文件。 |  
| listener | Callback<AccessedDLPFileInfo> | false | DLP文件被打开的事件的回调。在当前应用的沙箱应用打开DLP文件时，取消通知当前应用。默认为空，表示取消该类型事件的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100007 | No permission to invoke this API, which is not for DLP sandbox application. |  
| 19100011 | System service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.off('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {  
    console.info('openDlpFile event', info.uri, info.lastOpenTime)  
  }); // 取消订阅  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## isInSandbox    
查询当前应用是否运行在DLP沙箱环境。  
 **调用形式：**     
    
- isInSandbox(): Promise\<boolean>    
起始版本： 10    
- isInSandbox(callback: AsyncCallback\<boolean>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回当前应用是否运行在沙箱中。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
| 401 | Parameter error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.isInSandbox((err, data) => {  
    if (err) {  
      console.error('isInSandbox error,', err.code, err.message);  
    } else {  
      console.info('isInSandbox, data');  
    }  
  }); // 是否在沙箱内  
} catch (err) {  
  console.error('isInSandbox error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内  
  console.info('res', inSandbox);  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## getDLPSupportedFileTypes    
查询当前可支持权限设置和校验的文件扩展名类型列表。  
 **调用形式：**     
    
- getDLPSupportedFileTypes(): Promise\<Array\<string>>    
起始版本： 10    
- getDLPSupportedFileTypes(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |  
| Promise<Array<string>> | Promise对象。返回当前可支持权限设置和校验的文件扩展名类型列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 19100001 | Invalid parameter value. |  
| 19100011 | System service exception. |  
| 401 | Parameter error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.getDLPSupportedFileTypes((err, res) => {  
    if (err != undefined) {  
      console.error('getDLPSupportedFileTypes error,', err.code, err.message);  
    } else {  
      console.info('res', JSON.stringify(res));  
    }  
  }); // 获取支持DLP的文件类型  
} catch (err) {  
  console.error('getDLPSupportedFileTypes error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let res = dlpPermission.getDLPSupportedFileTypes(); // 获取支持DLP的文件类型  
  console.info('res', JSON.stringify(res));  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## setRetentionState    
打开DLP文件时自动安装沙箱，关闭DLP文件时自动卸载沙箱。设置沙箱保留状态时DLP文件关闭时自动卸载暂时失效。  
 **调用形式：**     
    
- setRetentionState(docUris: Array\<string>): Promise\<void>    
起始版本： 10    
- setRetentionState(docUris: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| docUris | Array<string> | true | 表示需要设置保留状态的文件uri列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。err为undefine时表示设置成功；否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100006 | No permission to invoke this API, which is for DLP sandbox application. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
try {  
  dlpPermission.setRetentionState([uri], (err, res) => {  
    if (err != undefined) {  
      console.error('setRetentionState error,', err.code, err.message);  
    } else {  
      console.info('setRetentionState success');  
    }  
  }); // 设置沙箱保留  
} catch (err) {  
  console.error('setRetentionState error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
try {  
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内  
  if (inSandbox) {  
    dlpPermission.setRetentionState([uri]); // 设置沙箱保留  
  }  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## cancelRetentionState    
取消沙箱保留状态即恢复DLP文件关闭时自动卸载沙箱策略。  
 **调用形式：**     
    
- cancelRetentionState(docUris: Array\<string>): Promise\<void>    
起始版本： 10    
- cancelRetentionState(docUris: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| docUris | Array<string> | true | 表示需要设置保留状态的文件uri列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。err为undefine时表示设置成功；否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
  dlpPermission.cancelRetentionState([uri], (err, res) => {  
    if (err != undefined) {  
      console.error('cancelRetentionState error,', err.code, err.message);  
    } else {  
      console.info('cancelRetentionState success');  
    }  
  }); // 取消沙箱保留  
} catch (err) {  
  console.error('cancelRetentionState error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";  
try {  
  dlpPermission.cancelRetentionState([uri]); // 取消沙箱保留  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## getRetentionSandboxList    
查询指定应用的保留沙箱信息列表。使用Promise方式异步返回结果。  
 **调用形式：**     
    
- getRetentionSandboxList(bundleName?: string): Promise\<Array\<RetentionSandboxInfo>>    
起始版本： 10    
- getRetentionSandboxList(bundleName: string, callback: AsyncCallback\<Array\<RetentionSandboxInfo>>): void    
起始版本： 10    
- getRetentionSandboxList(callback: AsyncCallback\<Array\<RetentionSandboxInfo>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | false | 指定应用包名。默认为空，查询当前应用的保留沙箱信息列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |  
| Promise<Array<RetentionSandboxInfo>> | Promise对象。返回查询的沙箱信息列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 19100001 | Invalid parameter value. |  
| 19100007 | No permission to invoke this API, which is not for DLP sandbox application. |  
| 19100011 | System service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.getRetentionSandboxList("bundleName", (err, res) => {  
    if (err != undefined) {  
      console.error('getRetentionSandboxList error,', err.code, err.message);  
    } else {  
      console.info('res', JSON.stringify(res));  
    }  
  }); // 获取沙箱保留列表  
} catch (err) {  
  console.error('getRetentionSandboxList error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let res: Promise<Array<dlpPermission.RetentionSandboxInfo>> = dlpPermission.getRetentionSandboxList(); // 获取沙箱保留列表  
  console.info('res', JSON.stringify(res))  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
    
## getDLPFileAccessRecords    
查询最近访问的DLP文件列表。  
 **调用形式：**     
    
- getDLPFileAccessRecords(): Promise\<Array\<AccessedDLPFileInfo>>    
起始版本： 10    
- getDLPFileAccessRecords(callback: AsyncCallback\<Array\<AccessedDLPFileInfo>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Security.DataLossPrevention    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |  
| Promise<Array<AccessedDLPFileInfo>> | Promise对象。返回最近访问的DLP文件列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 19100001 | Invalid parameter value. |  
| 19100007 | No permission to invoke this API, which is not for DLP sandbox application. |  
| 19100011 | System service exception. |  
| 401 | Parameter error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  dlpPermission.getDLPFileAccessRecords((err, res) => {  
    if (err != undefined) {  
      console.error('getDLPFileAccessRecords error,', err.code, err.message);  
    } else {  
      console.info('res', JSON.stringify(res));  
    }  
  }); // 获取DLP访问列表  
} catch (err) {  
  console.error('getDLPFileAccessRecords error,', (err as BusinessError).code, (err as BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import dlpPermission from '@ohos.dlpPermission';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let res: Promise<Array<dlpPermission.AccessedDLPFileInfo>> = dlpPermission.getDLPFileAccessRecords(); // 获取DLP访问列表  
  console.info('res', JSON.stringify(res))  
} catch (err) {  
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错  
}  
    
```    
  
