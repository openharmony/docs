# @ohos.file.fileAccess    
fileAccess模块是基于extension机制实现的一个对公共文件访问和操作的框架。该模块一方面对接各类文件管理服务，如存储管理服务等，另一方面为系统应用提供一套统一的文件访问管理接口。存储管理服务可以管理内置存储部分目录，以及共享盘、U盘、SD卡等设备上的资源。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import fileAccess from '@ohos.file.fileAccess'    
```  
    
## getFileAccessAbilityInfo    
以异步方法获取系统内extension配置为fileAccess类型的所有Want信息。  
 **调用形式：**     
    
- getFileAccessAbilityInfo(callback: AsyncCallback\<Array\<Want>>): void    
起始版本： 9    
- getFileAccessAbilityInfo(): Promise\<Array\<Want>>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示当前系统配置fileAccess的所有文件管理类服务 |  
| Promise<Array<Want>> | 表示当前系统配置fileAccess的所有文件管理类服务 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
async function getFileAccessAbilityInfo() {  
  try {  
    fileAccess.getFileAccessAbilityInfo((err: BusinessError, wantInfos: Array<Want>) => {  
      if (err) {  
        console.error("Failed to getFileAccessAbilityInfo in async, errCode:" + err.code + ", errMessage:" + err.message);  
        return;  
      }  
      console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));  
    });  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("getFileAccessAbilityInfo failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
async function getFileAccessAbilityInfo() {  
  let wantInfos: Array<Want> = [];  
  try {  
    wantInfos = await fileAccess.getFileAccessAbilityInfo();  
    console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("getFileAccessAbilityInfo failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
## createFileAccessHelper    
以同步方法创建连接当前系统内所有文件管理服务的helper对象。  
 **调用形式：**     
- createFileAccessHelper(context: Context): FileAccessHelper  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 代表ability的上下文的能力。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FileAccessHelper | 提供文件访问和操作能力的helper对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import common from '@ohos.app.ability.common';  
let context = getContext(this) as common.UIAbilityContext;  
function createFileAccessHelper02() {  
  let fileAccessHelperAllServer: fileAccess.FileAccessHelper;  
  // 创建连接系统内所有配置fileAccess的文件管理类服务的helper对象  
  try {  
    // context 是EntryAbility 传过来的context  
    fileAccessHelperAllServer = fileAccess.createFileAccessHelper(context);  
    if (!fileAccessHelperAllServer) {  
      console.error("createFileAccessHelper interface returns an undefined object");  
    }  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
## createFileAccessHelper    
以同步方法创建连接指定wants的helper对象。  
 **调用形式：**     
- createFileAccessHelper(context: Context, wants: Array\<Want>): FileAccessHelper  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | ability的上下文的能力 |  
| wants | Array<Want> | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FileAccessHelper | 提供文件访问和操作的能力的helper对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
import common from '@ohos.app.ability.common';  
let context = getContext(this) as common.UIAbilityContext;  
function createFileAccessHelper01() {  
  let fileAccessHelper: fileAccess.FileAccessHelper;  
  // wantInfos 从getFileAccessAbilityInfo()获取  
  let wantInfos: Array<Want> = [  
    {  
      bundleName: "com.ohos.UserFile.ExternalFileManager",  
      abilityName: "FileExtensionAbility",  
    },  
  ]  
  try {  
    // context 是EntryAbility 传过来的context  
    fileAccessHelper = fileAccess.createFileAccessHelper(context, wantInfos);  
    if (!fileAccessHelper) {  
      console.error("createFileAccessHelper interface returns an undefined object");  
    }  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
## FileInfo    
表示文件(夹)属性信息和接口能力。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | false | true | 文件(夹)的uri。 |  
| relativePath<sup>(10+)</sup> | string | false | true | 文件(夹)的相对路径 |  
| fileName | string | false | true | 文件(夹)的名称 |  
| mode | number | false | true | 文件(夹)的权限信息。 |  
| size | number | false | true | 文件(夹)的大小 |  
| mtime | number | false | true | 文件(夹)的修改时间 |  
| mimeType | string | false | true | 文件(夹)的媒体资源类型 |  
    
### listFile    
以同步方法从某个目录，基于过滤器，获取下一级符合条件的文件(夹)信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备过滤，外置存储设备不支持过滤。  
 **调用形式：**     
- listFile(filter?: Filter): FileIterator  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | Filter | false | 过滤器对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FileIterator | 文件(夹)信息的迭代器对象FileIterator |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
// fileInfoDir 表示某个目录信息  
// let filter = { suffix : [".txt", ".jpg", ".xlsx"] };  
let fileInfoDir: fileAccess.FileInfo; // = fileInfos[0];  
let subfileInfos: Array<fileAccess.FileInfo> = [];  
let isDone: boolean = false;  
try {  
  let fileIterator = fileInfoDir.listFile();  
  // 含过滤器实现的listFile  
  // let fileIterator = fileInfoDir.listFile(filter);  
  if (!fileIterator) {  
    console.error("listFile interface returns an undefined object");  
  }  
  while (!isDone) {  
    let result = fileIterator.next();  
    console.log("next result = " + JSON.stringify(result));  
    isDone = result.done;  
    if (!isDone) {  
      subfileInfos.push(result.value);  
    }  
  }  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
### scanFile    
以同步方法从某个目录，基于过滤器，递归获取符合条件的文件信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备。  
 **调用形式：**     
- scanFile(filter?: Filter): FileIterator  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | Filter | false | 过滤器对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FileIterator | 文件信息的迭代器对象FileIterator |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
// fileInfoDir 表示某个目录信息  
// let filter = {suffix : [".txt", ".jpg", ".xlsx"]};  
let fileInfoDir: fileAccess.FileInfo; // = fileInfos[0];  
let subfileInfos: Array<fileAccess.FileInfo> = [];  
let isDone: boolean = false;  
try {  
  let fileIterator = fileInfoDir.scanFile();  
  // 含过滤器实现的scanFile  
  // let fileIterator = fileInfoDir.scanFile(filter);  
  if (!fileIterator) {  
    console.error("scanFile interface returns an undefined object");  
  }  
  while (!isDone) {  
    let result = fileIterator.next();  
    console.log("next result = " + JSON.stringify(result));  
    isDone = result.done;  
    if (!isDone) {  
      subfileInfos.push(result.value);  
    }  
  }  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("scanFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
## FileIterator    
表示文件夹的迭代器对象。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### next    
可以通过next同步方法获取下一级文件(夹)信息。  
 **调用形式：**     
- next(): { value: FileInfo, done: boolean }  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| { value: FileInfo, done: boolean } | 通过next遍历文件夹，直到done返回true结束；value字段返回fileInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
## RootInfo    
表示设备的根属性信息和接口能力。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceType | number | false | true | 设备类型 |  
| uri | string | false | true | 设备根目录Uri |  
| relativePath<sup>(10+)</sup> | string | false | true | 根目录的相对路径 |  
| displayName | string | false | true | 设备名称 |  
| deviceFlags | number | false | true | 设备支持的能力 |  
    
### listFile    
以同步方法从某设备根节点开始，基于过滤器，获取第一级符合条件的文件(夹)信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备过滤，外置存储设备不支持过滤。  
 **调用形式：**     
- listFile(filter?: Filter): FileIterator  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | Filter | false | 过滤器对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FileIterator |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
// rootinfos 从getRoots()获取  
// let filter = {suffix : [".txt", ".jpg", ".xlsx"]};  
let rootInfo: fileAccess.RootInfo; // = rootinfos[0];  
let fileInfos: Array<fileAccess.FileInfo> = [];  
let isDone: boolean = false;  
try {  
  let fileIterator = rootInfo.listFile();  
  // 含过滤器实现的listFile  
  // let fileIterator = rootInfo.listFile(filter);  
  if (!fileIterator) {  
    console.error("listFile interface returns an undefined object");  
  }  
  while (!isDone) {  
    let result = fileIterator.next();  
    console.log("next result = " + JSON.stringify(result));  
    isDone = result.done;  
    if (!isDone) {  
      fileInfos.push(result.value);  
    }  
  }  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
### scanFile    
以同步方法从某设备根节点开始，基于过滤器，递归获取符合条件的文件信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备。  
 **调用形式：**     
- scanFile(filter?: Filter): FileIterator  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | Filter | false | 过滤器对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FileIterator | 文件信息的迭代器对象FileIterator |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
// rootInfos 从 getRoots()获取  
// let filter = {suffix : [".txt", ".jpg", ".xlsx"]};  
let rootInfo: fileAccess.RootInfo; // = rootinfos[0];  
let fileInfos: Array<fileAccess.FileInfo> = [];  
let isDone: boolean = false;  
try {  
  let fileIterator = rootInfo.scanFile();  
  // 含过滤器实现的scanFile  
  // let fileIterator = rootInfo.scanFile(filter);  
  if (!fileIterator) {  
    console.error("scanFile interface returns undefined object");  
  }  
  while (!isDone) {  
    let result = fileIterator.next();  
    console.log("next result = " + JSON.stringify(result));  
    isDone = result.done;  
    if (!isDone) {  
      fileInfos.push(result.value);  
    }  
  }  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("scanFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
## RootIterator    
表示设备根目录的迭代器对象。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### next    
通过next同步方法获取下一级设备根目录。  
 **调用形式：**     
- next(): { value: RootInfo, done: boolean }  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| { value: RootInfo, done: boolean } | 通过next遍历文件夹，直到done返回true结束；value字段返回rootInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
## CopyResult<sup>(10+)</sup>    
表示复制操作失败时的返回信息，复制成功时则没有返回信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
## OPENFLAGS    
枚举，目前支持的文件打开的标志位。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| READ | 0o0 | 读模式。 |  
| WRITE | 0o1 | 写模式。 |  
| WRITE_READ | 0o2 | 读写模式。 |  
    
## FileKey<sup>(10+)</sup>    
枚举，支持查询的键。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISPLAY_NAME | display_name | 文件名 |  
| DATE_ADDED | date_added | 文件创建的日期，例如1501925454。 |  
| DATE_MODIFIED | date_modified | 文件的修改日期，例如1665310670 |  
| RELATIVE_PATH | relative_path | 相对路径，例如Pictures/Screenshots/ |  
| FILE_SIZE | size | 文件（夹）大小（单位：字节） |  
    
## NotifyType<sup>(10+)</sup>    
枚举，通知类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOTIFY_ADD | 0 | 表示新增文件（详见registerObserver接口的示例2、示例3） |  
| NOTIFY_DELETE | 1 | 表示删除文件（详见unregisterObserver(uri: string, callback: Callbacklt;NotifyMessagegt;)接口的示例1、示例2） |  
| NOTIFY_MOVED_TO | 2 | 表示移动至该文件（对目录下子文件或目录执行rename操作，或外部文件或目录执行move操作到本文件，详见registerObserver接口的示例1，及unregisterObserver(uri: string)接口的示例1） |  
| NOTIFY_MOVED_FROM | 3 | 表示自该文件移出（对目录下子文件或目录执行rename操作，或子文件（夹）执行move操作从该文件夹内移出，详见registerObserver接口的示例1，及unregisterObserver(uri: string)接口的示例1）。 |  
| NOTIFY_MOVE_SELF | 4 | 表示本文件被移动（如对文件或文件夹执行rename或move操作时，监听该文件（夹）的callback收到该事件，详见registerObserver接口的示例1） |  
    
## NotifyMessage<sup>(10+)</sup>    
通知回调函数的值。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(10+)</sup> | NotifyType | false | true | 变更的通知类型 |  
| uris<sup>(10+)</sup> | Array<string> | false | true | 所变更文件的uri集合，目前仅支持单条通知，后序支持多条通知 |  
    
## FileAccessHelper    
FileAccessHelper对象。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### openFile    
以异步方法打开文件，返回文件描述符。  
 **调用形式：**     
    
- openFile(uri: string, flags: OPENFLAGS): Promise\<number>    
起始版本： 9    
- openFile(uri: string, flags: OPENFLAGS, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 待打开文件的uri |  
| flags | OPENFLAGS | true | 文件打开的标志 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 文件描述符 |  
| Promise<number> | 文件描述符 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ, (err: BusinessError, fd: number) => {  
    if (err) {  
      console.error("Failed to openFile in async, errCode:" + err.code + ", errMessage:" + err.message);  
    }  
    console.log("openFile sucess, fd: " + fd);  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function openFile01() {  
  // 以内置存储目录为例  
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri  
  // 开发者应根据自己实际获取的uri进行开发  
  let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let fd = await fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ);  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### createFile    
以异步方法创建文件到指定目录，返回新文件uri。  
 **调用形式：**     
    
- createFile(uri: string, displayName: string): Promise\<string>    
起始版本： 9    
- createFile(uri: string, displayName: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示需要创建文件的父目录的Uri |  
| displayName | string | true | 待创建文件的名称，默认本地文件需要添加后缀 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 新创建的文件的uri |  
| Promise<string> | 新创建的文件的uri |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceUri: string = "file://docs/storage/Users/currentUser/Download";  
let displayName: string = "file1";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.createFile(sourceUri, displayName, (err: BusinessError, fileUri: string) => {  
    if (err) {  
      console.error("Failed to createFile in async, errCode:" + err.code + ", errMessage:" + err.message);  
    }  
    console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceUri: string = "file://docs/storage/Users/currentUser/Download";  
let displayName: string = "file1";  
let fileUri: string;  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileUri = await fileAccessHelper.createFile(sourceUri, displayName);  
  if (!fileUri) {  
    console.error("createFile return undefined object");  
  }  
  console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
### mkDir    
以异步方法创建文件夹到指定目录，返回文件夹uri。  
 **调用形式：**     
    
- mkDir(parentUri: string, displayName: string): Promise\<string>    
起始版本： 9    
- mkDir(parentUri: string, displayName: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parentUri | string | true | 表示需要创建文件夹的父目录的Uri |  
| displayName | string | true | 待创建文件夹的名称 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 新创建的文件夹的uri |  
| Promise<string> | 新创建的文件夹的uri |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceUri: string = "file://docs/storage/Users/currentUser/Download";  
let dirName: string = "dirTest";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.mkDir(sourceUri, dirName, (err: BusinessError, dirUri: string) => {  
    if (err) {  
      console.error("Failed to mkDir in async, errCode:" + err.code + ", errMessage:" + err.message);  
    }  
    console.log("mkDir sucess, dirUri: " + JSON.stringify(dirUri));  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceUri: string = "file://docs/storage/Users/currentUser/Download";  
let dirName: string = "dirTest";  
let dirUri: string;  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  dirUri = await fileAccessHelper.mkDir(sourceUri, dirName);  
  if (!dirUri) {  
    console.error("mkDir return undefined object");  
  }  
  console.log("mkDir sucess, dirUri: " + JSON.stringify(dirUri));  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
### delete    
以异步方法删除文件(夹)，返回错误码。  
 **调用形式：**     
    
- delete(uri: string): Promise\<number>    
起始版本： 9    
- delete(uri: string, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 待删除文件(夹)的uri |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 删除操作的错误码 |  
| Promise<number> | 删除操作的错误码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.delete(targetUri, (err: BusinessError, code: number) => {  
    if (err) {  
      console.error("Failed to delete in async, errCode:" + err.code + ", errMessage:" + err.message);  
    }  
    console.log("delete sucess, code: " + code);  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function deleteFile01() {  
  // 以内置存储目录为例  
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri  
  // 开发者应根据自己实际获取的uri进行开发  
  let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let code = await fileAccessHelper.delete(targetUri);  
    if (code != 0)  
      console.error("delete failed, code " + code);  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### move    
以异步方法移动文件(夹)，返回移动后文件(夹)的uri。使用Promise异步回调。目前仅支持设备内移动，跨设备不支持移动。  
 **调用形式：**     
    
- move(sourceFile: string, destFile: string): Promise\<string>    
起始版本： 9    
- move(sourceFile: string, destFile: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sourceFile | string | true | 待移动的源文件(夹)的uri |  
| destFile | string | true | 目标文件夹的uri |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 新路径下的文件(夹)的uri |  
| Promise<string> | 新路径下的文件(夹)的uri |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceFile destFile表示Download目录下文件和文件夹，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.move(sourceFile, destFile, (err: BusinessError, fileUri: string) => {  
    if (err) {  
      console.error("Failed to move in async, errCode:" + err.code + ", errMessage:" + err.message);  
    }  
    console.log("move sucess, fileUri: " + JSON.stringify(fileUri));  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function moveFile01() {  
  // 以内置存储目录为例  
  // 示例代码sourceFile destFile表示Download目录下文件和文件夹，该uri是对应的fileInfo中uri  
  // 开发者应根据自己实际获取的uri进行开发  
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let fileUri = await fileAccessHelper.move(sourceFile, destFile);  
    console.log("move sucess, fileUri: " + JSON.stringify(fileUri));  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### copy<sup>(10+)</sup>    
复制文件或目录。  
 **调用形式：**     
    
- copy(sourceUri: string, destUri: string, force?: boolean): Promise\<Array\<CopyResult>>    
起始版本： 10    
- copy(sourceUri: string, destUri: string, callback: AsyncCallback\<Array\<CopyResult>>): void    
起始版本： 10    
- copy(sourceUri: string, destUri: string, force: boolean, callback: AsyncCallback\<Array\<CopyResult>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sourceUri | string | true | 待拷贝的源文件(夹)的 uri，例如：file://docs/storage/Users/currentUser/Download/1.txt |  
| destUri | string | true | 目标文件夹的 uri，例如：file://docs/storage/Users/currentUser/Download/test。 |  
| force | boolean | false | 含有同名文件时是否强制覆盖文件，force 为 true 时强制覆盖文件，force 为空或 false 时不强制覆盖文件 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |  
| Promise<Array<CopyResult>> | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.copy(sourceFile, destFile, true, async (err: BusinessError, copyResult: Array<fileAccess.CopyResult>) => {  
    if (err) {  
      console.error("copy failed, errCode:" + err.code + ", errMessage:" + err.message);  
    }  
    if (copyResult.length === 0) {  
      console.log("copy success");  
    } else {  
      for (let i = 0; i < copyResult.length; i++) {  
        console.error("errCode" + copyResult[i].errCode);  
        console.error("errMsg" + copyResult[i].errMsg);  
        console.error("sourceUri" + copyResult[i].sourceUri);  
        console.error("destUri" + copyResult[i].destUri);  
      }  
    }  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri  
// 开发者应根据自己实际获取的uri进行开发  
async function copyFunc01() {  
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let copyResult = await fileAccessHelper.copy(sourceFile, destFile);  
    if (copyResult.length === 0) {  
      console.log("copy success");  
    } else {  
      for (let i = 0; i < copyResult.length; i++) {  
        console.error("errCode" + copyResult[i].errCode);  
        console.error("errMsg" + copyResult[i].errMsg);  
        console.error("sourceUri" + copyResult[i].sourceUri);  
        console.error("destUri" + copyResult[i].destUri);  
      }  
    }  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### rename    
以异步方法重命名文件(夹)，返回重命名后的文件(夹)的Uri。  
 **调用形式：**     
    
- rename(uri: string, displayName: string): Promise\<string>    
起始版本： 9    
- rename(uri: string, displayName: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 源文件(夹)的uri |  
| displayName | string | true | 文件(夹)名，支持带后缀 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 重命名后的文件(夹)的uri |  
| Promise<string> | 重命名后的文件(夹)的uri |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.rename(sourceDir, "testDir", (err: BusinessError, DestDir: string) => {  
    if (err) {  
      console.error("Failed to rename in async, errCode:" + err.code + ", errMessage:" + err.message);  
    }  
    console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function renameFile01() {  
  // 以内置存储目录为例  
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri  
  // 开发者应根据自己实际获取的uri进行开发  
  let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let DestDir = await fileAccessHelper.rename(sourceDir, "testDir");  
    console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### access    
以异步方法判断文件(夹)是否存在。  
 **调用形式：**     
    
- access(sourceFileUri: string): Promise\<boolean>    
起始版本： 9    
- access(sourceFileUri: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sourceFileUri | string | true | 文件(夹)的uri |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 文件(夹)是否存在 |  
| Promise<boolean> | 文件(夹)是否存在 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceDir表示Download目录下文件夹，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceDir: string = "file://docs/storage/Users/currentUser/Download/test";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.access(sourceDir, (err: BusinessError, existJudgment: boolean) => {  
    if (err) {  
      console.error("Failed to access in async, errCode:" + err.code + ", errMessage:" + err.message);  
      return;  
    }  
    if (existJudgment)  
      console.log("sourceDir exists");  
    else  
      console.log("sourceDir does not exist");  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
async function accessFunc() {  
  let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let existJudgment = await fileAccessHelper.access(sourceDir);  
    if (existJudgment) {  
      console.log("sourceDir exists");  
    } else {  
      console.log("sourceDir does not exist");  
    }  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### query<sup>(10+)</sup>    
通过uri查询文件或目录的相关信息。  
 **调用形式：**     
    
- query(uri: string, metaJson: string): Promise\<string>    
起始版本： 10    
- query(uri: string, metaJson: string, callback: AsyncCallback\<string>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 所选文件或目录的uri（从[FileInfo](#fileinfo)中获取） |  
| metaJson | string | true | json字符串，包含查询属性[FILEKEY](#filekey10) |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回json字符串，包括查询属性和值 |  
| Promise<string> | 返回json字符串，包括查询属性和值 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function getQuery02() {  
  let imageFileRelativePath: string = "/storage/Users/currentUser/Download/queryTest/image/01.jpg";  
  let jsonStrSingleRelativepath: string = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);  
    fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath, (err: BusinessError, queryResult: string) => {  
      if (err) {  
        console.log("query_file_single faf query Failed, errCode:" + err.code + ", errMessage:" + err.message);  
        return;  
      }  
      console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);  
    })  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function getQuery01() {  
  let imageFileRelativePath: string = "/storage/Users/currentUser/Download/queryTest/image/01.jpg";  
  let jsonStrSingleRelativepath: string = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);  
    let queryResult = await fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath);  
    console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);  
  }  
}  
    
```    
  
    
### getFileInfoFromUri<sup>(10+)</sup>    
以异步方法获取uri对应的FileInfo对象。  
 **调用形式：**     
    
- getFileInfoFromUri(uri: string): Promise\<FileInfo>    
起始版本： 10    
- getFileInfoFromUri(uri: string, callback: AsyncCallback\<FileInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 文件(夹)的Uri |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | uri对应的FileInfo对象 |  
| Promise<FileInfo> | FileInfo对象 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
let sourceUri: string = "file://docs/storage/Users/currentUser/Download";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.getFileInfoFromUri(sourceUri, (err: BusinessError, fileInfo: fileAccess.FileInfo) => {  
    if (err) {  
      console.error("Failed to getFileInfoFromUri in async, errCode:" + err.code + ", errMessage:" + err.message);  
      return;  
    }  
    console.log("getFileInfoFromUri success, fileInfo: " + JSON.stringify(fileInfo));  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 以内置存储目录为例  
// 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri  
// 开发者应根据自己实际获取的uri进行开发  
async function getUri() {  
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let fileInfo = await fileAccessHelper.getFileInfoFromUri(sourceUri);  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### getFileInfoFromRelativePath<sup>(10+)</sup>    
以异步方法获取relativePath对应的FileInfo对象。  
 **调用形式：**     
    
- getFileInfoFromRelativePath(relativePath: string): Promise\<FileInfo>    
起始版本： 10    
- getFileInfoFromRelativePath(relativePath: string, callback: AsyncCallback\<FileInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| relativePath | string | true | 文件(夹)的相对路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | relativePath对应的FileInfo对象 |  
| Promise<FileInfo> | FileInfo对象 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 示例代码relativePath表示Download目录，该relativePath是对应的fileInfo中relativePath  
// 开发者应根据自己实际获取的relativePath进行开发  
let relativePath: string = "Download/";  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  fileAccessHelper.getFileInfoFromRelativePath(relativePath, (err: BusinessError, fileInfo: fileAccess.FileInfo) => {  
    if (err) {  
      console.error("Failed to getFileInfoFromRelativePath in async, errCode:" + err.code + ", errMessage:" + err.message);  
      return;  
    }  
    console.log("getFileInfoFromRelativePath success, fileInfo: " + JSON.stringify(fileInfo));  
  });  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
// 示例代码relativePath表示Download目录，该relativePath是对应的fileInfo中relativePath  
// 开发者应根据自己实际获取的relativePath进行开发  
async function getRelativePath() {  
  let relativePath: string = "Download/";  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(relativePath);  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### getRoots    
以异步方法获取helper对象连接的文件管理服务类的设备根节点信息。 该方法返回迭代器对象RootIterator，然后通过[next](#next-1)方法返回[RootInfo](#rootinfo)。  
 **调用形式：**     
    
- getRoots(): Promise\<RootIterator>    
起始版本： 9    
- getRoots(callback: AsyncCallback\<RootIterator>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 根设备目录信息组成迭代器对象 |  
| Promise<RootIterator> | 根设备目录信息组成迭代器对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900006 | No such device or address |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900014 | Device or resource busy |  
| 13900015 | File exists |  
| 13900017 | No such device |  
| 13900018 | Not a directory |  
| 13900019 | Is a directory |  
| 13900020 | Invalid argument |  
| 13900022 | Too many open files |  
| 13900023 | Text file busy |  
| 13900024 | File too large |  
| 13900025 | No space left on device |  
| 13900027 | Read-only file system |  
| 13900029 | Resource deadlock would occur |  
| 13900030 | Filename too Long |  
| 13900033 | Too many symbolic links encountered |  
| 13900034 | Operation would block |  
| 13900038 | Value too large for defined data type |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
| 14000001 |  |  
| 14000002 |  |  
| 14000003 |  |  
| 14000004 |  |  
| 14300001 | Invalid display name |  
| 14300002 | Invalid uri |  
| 14300003 | Invalid file name extension |  
| 14300004 | File has been put into trash bin |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function getRoots() {  
  let rootinfos: Array<fileAccess.RootInfo> = [];  
  let isDone: boolean = false;  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    fileAccessHelper.getRoots((err: BusinessError, rootIterator: fileAccess.RootIterator) => {  
      if (err) {  
        console.error("Failed to getRoots in async, errCode:" + err.code + ", errMessage:" + err.message);  
      }  
      while (!isDone) {  
        let result = rootIterator.next();  
        console.log("next result = " + JSON.stringify(result));  
        isDone = result.done;  
        if (!isDone) {  
          rootinfos.push(result.value);  
        }  
      }  
    });  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function getRoots() {  
let rootIterator: fileAccess.RootIterator;  
let rootinfos: Array<fileAccess.RootInfo> = [];  
let isDone: boolean = false;  
try {  
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
  rootIterator = await fileAccessHelper.getRoots();  
  if (!rootIterator) {  
    console.error("getRoots interface returns an undefined object");  
  }  
  while (!isDone) {  
    let result = rootIterator.next();  
    console.log("next result = " + JSON.stringify(result));  
    isDone = result.done;  
    if (!isDone) {  
      rootinfos.push(result.value);  
    }  
  }  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);  
}  
}  
    
```    
  
    
### registerObserver<sup>(10+)</sup>    
注册指定uri的callback。uri与callback可以为多对多的关系，推荐使用一个callback监听一个uri。  
 **调用形式：**     
    
- registerObserver(uri: string, notifyForDescendants: boolean, callback: Callback\<NotifyMessage>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 文件或目录的uri |  
| notifyForDescendants | boolean | true | 监听目录时，是否监听子文件变化 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回通知信息 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14300002 | Invalid uri |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function registerObserver01() {  
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let dirUri1 = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR1');  
    let dirUri2 = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR2');  
    // 因注册时notifyForDescendants参数为true所以期待收到两次通知  
    // uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVED_FROM  
    // uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVE_SELF  
    const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {  
      if (NotifyMessageDir != undefined) {  
        console.log('NotifyType: ' + NotifyMessageDir.NotifyType + 'NotifyUri:' + NotifyMessageDir.uri[0]);  
      } else {  
        console.error("NotifyMessageDir is undefined");  
      }  
    }  
    // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR2/SUB_FILE'，事件类型为NOTIFY_MOVED_TO  
    const callbackDir2 = (NotifyMessageDir: fileAccess.NotifyMessage) => {  
      if (NotifyMessageDir != undefined) {  
        console.log('NotifyType: ' + NotifyMessageDir.NotifyType + 'NotifyUri:' + NotifyMessageDir.uri[0]);  
      } else {  
        console.error("NotifyMessageDir is undefined");  
      }  
    }  
    // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVE_SELF  
    // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVED_FROM  
    const callbackFile = (NotifyMessageDir: fileAccess.NotifyMessage) => {  
      if (NotifyMessageDir != undefined) {  
        console.log('NotifyType: ' + NotifyMessageDir.NotifyType + 'NotifyUri:' + NotifyMessageDir.uri[0]);  
      } else {  
        console.error("NotifyMessageDir is undefined");  
      }  
    }  
    let fileUri = await fileAccessHelper.createFile(dirUri1, 'SUB_FILE');  
    fileAccessHelper.registerObserver(dirUri1, true, callbackDir1);  
    fileAccessHelper.registerObserver(dirUri2, true, callbackDir2);  
    // 如果不监听被移动文件本身，将不会触发NOTIFY_MOVE_SELF事件  
    fileAccessHelper.registerObserver(fileUri, true, callbackFile);  
    let moveFileUri = await fileAccessHelper.move(fileUri, dirUri2);  
    // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件  
    fileAccessHelper.unregisterObserver(dirUri1, callbackDir1);  
    fileAccessHelper.unregisterObserver(dirUri2, callbackDir2);  
    fileAccessHelper.unregisterObserver(fileUri, callbackFile);  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("registerObserver failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
    
### unregisterObserver<sup>(10+)</sup>    
取消注册指定的uri和callback。  
 **调用形式：**     
    
- unregisterObserver(uri: string, callback?: Callback\<NotifyMessage>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 文件或目录的uri |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 解注册uri下对应的callback。如果该参数不填，则解注册对应的所有callbackback |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 14300002 | Invalid uri |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function UnregisterObserver01() {  
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';  
  try {  
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取  
    let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');  
    // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR'，事件类型为NOTIFY_DELETE  
    const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {  
      if (NotifyMessageDir != undefined) {  
        console.log('NotifyType: ' + NotifyMessageDir.NotifyType + 'NotifyUri:' + NotifyMessageDir.uri[0]);  
      } else {  
        console.error("NotifyMessageDir is undefined");  
      }  
    }  
    fileAccessHelper.registerObserver(dirUri, true, callbackDir);  
    await fileAccessHelper.delete(dirUri);  
    // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件  
    fileAccessHelper.unregisterObserver(dirUri, callbackDir);  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);  
  }  
}  
    
```    
  
