# @ohos.fileshare    
该模块提供文件分享能力，提供系统应用将公共目录文件统一资源标志符（Uniform Resource Identifier，URI）以读写权限授权给其他应用的接口，授权后应用可通过[is-file-fs.md)的相关接口进行相关open、read、write等操作，实现文件分享。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import fileShare from '@ohos.fileshare'    
```  
    
## grantUriPermission    
将公共目录文件URI进行授权操作。  
 **调用形式：**     
    
- grantUriPermission(     uri: string,     bundleName: string,     flag: wantConstant.Flags,     callback: AsyncCallback\<void>   ): void    
起始版本： 9    
- grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.AppFileService  
 **需要权限：** ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 公共目录文件URI |  
| bundleName | string | true | 分享目标的包名 |  
| flag | wantConstant.Flags | true | 授权的权限，参考[wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags)<br/>wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION：读授权<br/>wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION：写授权 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步授权之后的回调 |  
| Promise<void> | Promise对象，无返回值 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed |  
| 202 | The caller is not a system application |  
| 401 | The input parameter is invalid |  
| 143000001 | IPC error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import wantConstant from '@ohos.app.ability.wantConstant';  
  import { BusinessError } from '@ohos.base';  
  let uri: string = 'file://media/image/8';  
  let bundleName: string = 'com.demo.test';  
  try {  
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |  
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION, (err: BusinessError) => {  
      if (err) {  
        console.error("grantUriPermission failed with error: " + JSON.stringify(err));  
        return;  
      }  
      console.info("grantUriPermission success!");  
    });  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("grantUriPermission failed with error:" + JSON.stringify(error));  
  }  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import wantConstant from '@ohos.app.ability.wantConstant';  
  import { BusinessError } from '@ohos.base';  
  let uri: string = 'file://media/image/8';  
  let bundleName: string = 'com.demo.test';  
  try {  
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |  
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION).then(() => {  
      console.info("grantUriPermission success!");  
    }).catch((error: BusinessError) => {  
      console.error("grantUriPermission failed with error:" + JSON.stringify(error));  
    });  
  } catch (err) {  
    let error: BusinessError = err as BusinessError;  
    console.error("grantUriPermission failed with error:" + JSON.stringify(error));  
  }  
    
```    
  
