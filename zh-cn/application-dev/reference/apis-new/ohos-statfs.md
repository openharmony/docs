# @ohos.statfs    
该模块提供文件系统相关存储信息的功能，向应用程序提供获取文件系统总字节数、空闲字节数的JS接口。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Statfs from '@ohos.statfs'    
```  
    
## getFreeBytes<sup>(deprecated)</sup>    
异步方法获取指定文件系统空闲字节数，使用callback形式返回结果。  
 **调用形式：**     
- getFreeBytes(path: string, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.statvfs.getFreeSize。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 需要查询的文件系统的文件路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步获取空闲字节数之后的回调 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  let path = "/dev";  
  statfs.getFreeBytes(path).then((number: number) => {  
    console.info("getFreeBytes promise successfully:" + number);  
  }).catch((err: BusinessError) => {  
    console.info("getFreeBytes failed with error:" + JSON.stringify(err));  
  });  
    
```    
  
    
## getFreeBytes<sup>(deprecated)</sup>    
异步方法获取指定文件系统空闲字节数，以Promise形式返回结果。  
 **调用形式：**     
- getFreeBytes(path: string): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.statvfs.getFreeSize。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 需要查询的文件系统的文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回空闲字节数 |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  let context = featureAbility.getContext();  context.getFilesDir().then(function (path) {      statfs.getFreeBytes(path, function (err, number) {          console.info("getFreeBytes callback successfully:" + number);      });  });    
```    
  
    
## getTotalBytes<sup>(deprecated)</sup>    
异步方法获取指定文件系统总字节数，使用callback形式返回结果。  
 **调用形式：**     
- getTotalBytes(path: string, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.statvfs.getTotalSize。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 需要查询的文件系统的文件路径 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步获取总字节数之后的回调。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  let path = "/dev";  
  statfs.getTotalBytes(path).then((number: number) => {  
    console.info("getTotalBytes promise successfully:" + number);  
  }).catch((err: BusinessError) => {  
    console.info("getTotalBytes failed with error:" + JSON.stringify(err));  
  });  
    
```    
  
    
## getTotalBytes<sup>(deprecated)</sup>    
异步方法获取指定文件系统总字节数，以Promise形式返回结果。  
 **调用形式：**     
- getTotalBytes(path: string): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.statvfs.getTotalSize。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 需要查询的文件系统的文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回总字节数 |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  let context = featureAbility.getContext();  context.getFilesDir().then(function (path) {      statfs.getTotalBytes(path, function(err, number) {          console.info("getTotalBytes callback successfully:" + number);      });  });    
```    
  
