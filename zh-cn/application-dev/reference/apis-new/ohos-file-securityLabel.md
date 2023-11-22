# @ohos.file.securityLabel    
该模块提供文件数据安全等级的相关功能：向应用程序提供查询、设置文件数据安全等级的JS接口。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import securityLabel from '@ohos.file.securityLabel'    
```  
    
## DataLevel    
    
| 取值范围 | 说明 |  
| --------| --------|  
| s0 |  |  
| s1 |  |  
| s2 |  |  
| s3 |  |  
| s4 |  |  
    
## setSecurityLabel    
以异步方法设置数据标签，以promise形式返回结果。  
 **调用形式：**     
    
- setSecurityLabel(path: string, type: DataLevel): Promise\<void>    
起始版本： 9    
- setSecurityLabel(path: string, type: DataLevel, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件路径 |  
| type | DataLevel | true | 文件等级属性，只支持"s0","s1","s2","s3","s4" |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 是否设置数据标签之后的回调 |  
| Promise<void> | Promise实例，用于异步获取结果。本调用将返回空值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900007 | Arg list too long |  
| 13900015 | File exists |  
| 13900020 | Invalid argument |  
| 13900025 | No space left on device |  
| 13900037 | No data available |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + '/test.txt';  
  securityLabel.setSecurityLabel(filePath, "s0", (err: BusinessError) => {  
    if (err) {  
      console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);  
    } else {  
      console.info("setSecurityLabel successfully.");  
    }  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + '/test.txt';  
  securityLabel.setSecurityLabel(filePath, "s0").then(() => {  
    console.info("setSecurityLabel successfully");  
  }).catch((err: BusinessError) => {  
    console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);  
  });  
    
```    
  
    
## setSecurityLabelSync    
以同步方法设置数据标签。  
 **调用形式：**     
- setSecurityLabelSync(path: string, type: DataLevel): void  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件路径 |  
| type | DataLevel | true | 文件等级属性，只支持"s0","s1","s2","s3","s4" |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900007 | Arg list too long |  
| 13900015 | File exists |  
| 13900020 | Invalid argument |  
| 13900025 | No space left on device |  
| 13900037 | No data available |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + '/test.txt';securityLabel.setSecurityLabelSync(filePath, "s0");    
```    
  
    
## getSecurityLabel    
异步方法获取数据标签，以promise形式返回结果。  
 **调用形式：**     
    
- getSecurityLabel(path: string): Promise\<string>    
起始版本： 9    
- getSecurityLabel(path: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取数据标签之后的回调 |  
| Promise<string> | 返回数据标签 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900007 | Arg list too long |  
| 13900015 | File exists |  
| 13900020 | Invalid argument |  
| 13900025 | No space left on device |  
| 13900037 | No data available |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + '/test.txt';  
  securityLabel.getSecurityLabel(filePath, (err: BusinessError, type: string) => {  
    if (err) {  
      console.log("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);  
    } else {  
      console.log("getSecurityLabel successfully, Label: " + type);  
    }  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + '/test.txt';  
  securityLabel.getSecurityLabel(filePath).then((type: string) => {  
    console.log("getSecurityLabel successfully, Label: " + type);  
  }).catch((err: BusinessError) => {  
    console.log("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);  
  });  
    
```    
  
    
## getSecurityLabelSync    
以同步方法获取数据标签。  
 **调用形式：**     
- getSecurityLabelSync(path: string): string  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回数据标签 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900001 | Operation not permitted |  
| 13900007 | Arg list too long |  
| 13900015 | File exists |  
| 13900020 | Invalid argument |  
| 13900025 | No space left on device |  
| 13900037 | No data available |  
| 13900041 | Quota exceeded |  
| 13900042 | Unknown error |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + '/test.txt';let type = securityLabel.getSecurityLabelSync(filePath);console.log("getSecurityLabel successfully, Label: " + type);    
```    
  
