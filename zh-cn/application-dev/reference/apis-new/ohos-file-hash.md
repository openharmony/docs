# @ohos.file.hash    
该模块提供文件哈希处理能力，对文件内容进行哈希处理。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import hash from '@ohos.file.hash'    
```  
    
## hash    
计算文件的哈希值，使用Promise异步回调。  
 **调用形式：**     
    
- hash(path: string, algorithm: string): Promise\<string>    
起始版本： 9    
- hash(path: string, algorithm: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 待计算哈希值文件的应用沙箱路径。 |  
| algorithm | string | true | 哈希计算采用的算法。可选"md5"、"sha1"或"sha256"。建议采用安全强度更高的"sha256"。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步计算文件哈希操作之后的回调函数（其中给定文件哈希值表示为十六进制数字串，所有字母均大写）。 |  
| Promise<string> | Promise对象。返回文件的哈希值。表示为十六进制数字串，所有字母均大写。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  let filePath = pathDir + "/test.txt";  
  Hash.hash(filePath, "sha256", (err: BusinessError, str: string) => {  
    if (err) {  
      console.info("calculate file hash failed with error message: " + err.message + ", error code: " + err.code);  
    } else {  
      console.info("calculate file hash succeed:" + str);  
    }  
  });  
    
```    
  
