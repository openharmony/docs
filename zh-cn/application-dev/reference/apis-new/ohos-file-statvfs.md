# @ohos.file.statvfs    
该模块提供文件系统相关存储信息的功能，向应用程序提供获取文件系统总字节数、空闲字节数的JS接口。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import statfs from '@ohos.file.statvfs'    
```  
    
## getFreeSize    
异步方法获取指定文件系统空闲字节。  
 **调用形式：**     
    
- getFreeSize(path: string): Promise\<number>    
起始版本： 9    
- getFreeSize(path: string, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 需要查询的文件系统的文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取空闲字节数之后的回调 |  
| Promise<number> | 返回空闲字节数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900005 | I/O error |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900018 | Not a directory |  
| 13900030 | Filename too Long |  
| 13900031 | Function not implemented |  
| 13900033 | Too many symbolic links encountered |  
| 13900038 | Value too large for defined data type |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let path: string = "/dev";  
  statvfs.getFreeSize(path, (err: BusinessError, number: number) => {  
    if (err) {  
      console.info("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);  
    } else {  
      console.info("getFreeSize succeed, Size: " + number);  
    }  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let path: string = "/dev";  
  statvfs.getFreeSize(path).then((number: number) => {  
    console.info("getFreeSize succeed, Size: " + number);  
  }).catch((err: BusinessError) => {  
    console.info("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);  
  });  
    
```    
  
    
## getFreeSizeSync<sup>(10+)</sup>    
以同步方法获取指定文件系统空闲字节数。  
 **调用形式：**     
- getFreeSizeSync(path: string): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 需要查询的文件系统的文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回空闲字节数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900005 | I/O error |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 |  |  
| 13900018 | Not a directory |  
| 13900030 | Filename too Long |  
| 13900031 | Function not implemented |  
| 13900033 | Too many symbolic links encountered |  
| 13900038 | Value too large for defined data type |  
| 13900042 | Unknown error |  
    
 **示例代码：**   
```ts    
let path = "/dev";  let number = statvfs.getFreeSizeSync(path);  console.info("getFreeSizeSync succeed, Size: " + number);    
```    
  
    
## getTotalSize    
异步方法获取指定文件系统总字节数。  
 **调用形式：**     
    
- getTotalSize(path: string): Promise\<number>    
起始版本： 9    
- getTotalSize(path: string, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 需要查询的文件系统的文件路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取总字节数之后的回调 |  
| Promise<number> | 返回总字节数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900005 | I/O error |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900018 | Not a directory |  
| 13900030 | Filename too Long |  
| 13900031 | Function not implemented |  
| 13900033 | Too many symbolic links encountered |  
| 13900038 | Value too large for defined data type |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let path: string = "/dev";  
  statvfs.getTotalSize(path, (err: BusinessError, number: number) => {  
    if (err) {  
      console.info("getTotalSize with error message: " + err.message + ", error code: " + err.code);  
    } else {  
      console.info("getTotalSize succeed, Size: " + number);  
    }  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let path: string = "/dev";  
  statvfs.getTotalSize(path).then((number: number) => {  
    console.info("getTotalSize succeed, Size: " + number);  
  }).catch((err: BusinessError) => {  
    console.info("getTotalSize with error message: " + err.message + ", error code: " + err.code);  
  });  
    
```    
  
    
## getTotalSizeSync<sup>(10+)</sup>    
以同步方法获取指定文件系统总字节数。  
 **调用形式：**     
- getTotalSizeSync(path: string): number  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 需要查询的文件系统的文件路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回总字节数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | No such file or directory |  
| 13900004 | Interrupted system call |  
| 13900005 | I/O error |  
| 13900008 | Bad file descriptor |  
| 13900011 | Out of memory |  
| 13900012 | Permission denied |  
| 13900013 | Bad address |  
| 13900018 | Not a directory |  
| 13900030 | Filename too Long |  
| 13900031 | Function not implemented |  
| 13900033 | Too many symbolic links encountered |  
| 13900038 | Value too large for defined data type |  
| 13900042 | Unknown error |  
    
 **示例代码：**   
```ts    
let path = "/dev";  let number = statvfs.getTotalSizeSync(path);  console.info("getTotalSizeSync succeed, Size: " + number);    
```    
  
