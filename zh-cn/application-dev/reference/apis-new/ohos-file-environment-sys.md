# @ohos.file.environment    
该模块提供环境目录能力，获取内存存储根目录、公共文件根目录的JS接口。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Environment from '@ohos.file.environment'    
```  
    
## getStorageDataDir    
异步方法获取内存存储根目录。  
 **调用形式：**     
    
- getStorageDataDir(): Promise\<string>    
起始版本： 8    
- getStorageDataDir(callback: AsyncCallback\<string>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.File.Environment    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取内存存储根目录之后的回调 |  
| Promise<string> | 返回存储根目录 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | The caller is not a system application |  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
environment.getStorageDataDir((err: BusinessError, path: string) => {  
  if (err) {  
    console.info("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("getStorageDataDir successfully, Path: " + path);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
environment.getStorageDataDir().then((path: string) => {  
    console.info("getStorageDataDir successfully, Path: " + path);  
}).catch((err: BusinessError) => {  
    console.info("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
    
## getUserDataDir    
异步方法获取公共文件根目录。  
 **调用形式：**     
    
- getUserDataDir(): Promise\<string>    
起始版本： 8    
- getUserDataDir(callback: AsyncCallback\<string>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.File.Environment    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取公共文件根目录之后的回调 |  
| Promise<string> | 返回公共文件根目录 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | The caller is not a system application |  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
environment.getUserDataDir((err: BusinessError, path: string) => {  
  if (err) {  
    console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);  
  } else {  
    console.info("getUserDataDir successfully, Path: " + path);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
environment.getUserDataDir().then((path: string) => {  
  console.info("getUserDataDir successfully, Path: " + path);  
}).catch((err: BusinessError) => {  
  console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);  
});  
    
```    
  
