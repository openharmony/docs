# @ohos.uri    
本模块提供URI字符串解析的相关功能。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import uri from '@ohos.uri'    
```  
    
## URI  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scheme | string | false | true | 获取URI的协议部分。 |  
| userInfo | string | false | true | 获取URI的用户信息部分。 |  
| host | string | false | true | 获取URI的主机名部分（不带端口）。 |  
| port | string | false | true | 获取URI的端口部分。 |  
| path | string | false | true | 获取URI的路径部分。 |  
| query | string | false | true |  获取URI的查询部分。 |  
| fragment | string | false | true | 获取URI的片段部分 |  
| authority | string | false | true | 获取此URI的解码权限组件部分。 |  
| ssp | string | false | true | 获取URI的解码方案特定部分。 |  
    
### toString    
返回适用于URI中的查询字符串。  
 **调用形式：**     
- toString(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回网址的字符串序列化。 |  
    
 **示例代码：**   
```ts    
const result = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');let result1 = result.toString();    
```    
  
    
### equals<sup>(deprecated)</sup>    
判断此URI是否与其他URI对象相等。  
 **调用形式：**     
- equals(other: URI): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.uri.URI.equalsTo。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| other<sup>(deprecated)</sup> | URI | true | 需要比较的URI对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示相等，否则返回false。 |  
    
 **示例代码：**   
```ts    
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');uriInstance.equals(uriInstance1);    
```    
  
    
### equalsTo<sup>(9+)</sup>    
判断此URI是否与其他URI对象相等。  
 **调用形式：**     
- equalsTo(other: URI): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| other | URI | true | 需要比较的URI对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示相等，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');let result = uriInstance.equalsTo(uriInstance1);    
```    
  
    
### checkIsAbsolute    
判断此URI是否为绝对URI（是否定义了scheme组件）。  
 **调用形式：**     
- checkIsAbsolute(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果是绝对URI返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080?query=pppppp');console.log(`${uriInstance.checkIsAbsolute()}`); // trueconst uriInstance1 = new uri.URI('xxx.com/suppliers.htm');console.log(`${uriInstance1.checkIsAbsolute()}`); // false    
```    
  
    
### normalize    
规范化此URI的路径。  
 **调用形式：**     
- normalize(): URI  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| URI | 返回一个path被规范化后的URI对象。 |  
    
 **示例代码：**   
```ts    
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080/path/path1/../path2/./path3?query=pppppp');console.log(uriInstance.path); // /path/path1/../path2/./path3let uriInstance1 = uriInstance.normalize();console.log(uriInstance1.path); // /path/path2/path    
```    
  
