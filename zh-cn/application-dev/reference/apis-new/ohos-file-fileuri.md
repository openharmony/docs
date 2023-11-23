# @ohos.file.fileuri    
该模块提供通过PATH获取文件统一资源标志符（Uniform Resource Identifier，URI），后续可通过使用[is-file-fs.md)进行相关open、read、write等操作，实现文件分享。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import fileUri from '@ohos.file.fileuri'    
```  
    
## FileUri<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.FileManagement.AppFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.AppFileService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(10+)</sup> | string | true | true | 获取FileUri对应文件名。 |  
    
## getUriFromPath    
以同步方法获取文件URI。  
 **调用形式：**     
- getUriFromPath(path: string): string  
  
 **系统能力:**  SystemCapability.FileManagement.AppFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 文件的沙箱路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回文件URI |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | The input parameter is invalid |  
    
 **示例代码：**   
```ts    
let filePath = pathDir + "/test";  
let uri = fileuri.getUriFromPath(filePath);    
```    
  
