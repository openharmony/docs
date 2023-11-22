# @ohos.document    
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import document from '@ohos.document'    
```  
    
## choose<sup>(deprecated)</sup>    
通过文件管理器选择文件，异步返回文件URI，使用promise形式返回结果。  
 **调用形式：**     
- choose(types?: string[]): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| types<sup>(deprecated)</sup> | string[] | false | 限定文件选择的类型  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 异步返回文件URI（注：当前返回错误码） |  
    
 **示例代码：**   
示例：  
```ts    
let types: Array<string> = [];  
document.choose(types);    
```    
  
    
## choose<sup>(deprecated)</sup>    
通过文件管理器选择文件，异步返回文件URI，使用callback形式返回结果。  
 **调用形式：**     
- choose(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 异步获取对应文件URI（注：当前返回错误码）  |  
    
 **示例代码：**   
示例：  
```ts    
let uri: string = "";  
document.choose((err: TypeError, uri: string) => {  
  //do something with uri  
});    
```    
  
    
## choose<sup>(deprecated)</sup>    
通过文件管理器选择文件，异步返回文件URI，使用callback形式返回结果。  
 **调用形式：**     
- choose(types: string[], callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| types<sup>(deprecated)</sup> | string[] | true | 限定选择文件的类型  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 异步获取对应文件URI（注：当前返回错误码）  |  
    
 **示例代码：**   
示例：  
```ts    
let types: Array<string> = [];  
let uri: string = "";  
document.choose(types, (err: TypeError, uri: string) => {  
  //do something with uri  
});    
```    
  
    
## show<sup>(deprecated)</sup>    
异步打开URI对应的文件，使用promise形式返回结果。  
 **调用形式：**     
- show(uri: string, type: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 待打开的文件URI  |  
| type<sup>(deprecated)</sup> | string | true | 待打开文件的类型  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise回调返回void表示成功打开文件（注：当前返回错误码） |  
    
 **示例代码：**   
示例：  
```ts    
let type: string = "";  
let uri: string = "";  
document.show(uri, type);    
```    
  
    
## show<sup>(deprecated)</sup>    
异步打开URI对应的文件，使用callback形式返回结果。  
 **调用形式：**     
- show(uri: string, type: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 待打开的文件URI  |  
| type<sup>(deprecated)</sup> | string | true | 待打开文件的类型  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 异步打开uri对应文件（注：当前返回错误码）   。 |  
    
 **示例代码：**   
示例：  
```ts    
let type: string = "";  
let uri: string = "";  
document.show(uri, type, (err: TypeError) => {  
  //do something  
});    
```    
  
