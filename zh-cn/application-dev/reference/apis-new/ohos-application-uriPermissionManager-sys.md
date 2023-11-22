# @ohos.application.uriPermissionManager    
URI权限管理模块。用于应用A授权/撤销授权URI给应用B。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import uriPermissionManager from '@ohos.application.uriPermissionManager'    
```  
    
## grantUriPermission    
授权URI给指定应用，通过callback返回结果。  
 **调用形式：**     
    
- grantUriPermission(    uri: string,    flag: wantConstant.Flags,    targetBundleName: string,    callback: AsyncCallback\<number>  ): void    
起始版本： 10    
- grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.PROXY_AUTHORIZATION_URI    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 |  
| flag | wantConstant.Flags | true | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags) | 是 | URI的读权限或写权限。 |  
| targetBundleName | string | true | 被授权URI的应用包名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回检验结果，返回0表示有权限，返回-1表示无权限。 |  
| Promise<number> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
| 16000058 | Invalid URI flag. |  
| 16000059 | Invalid URI type. |  
| 16000060 | Sandbox application can not grant URI permission. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import uriPermissionManager from '@ohos.application.uriPermissionManager';  
  import WantConstant from '@ohos.app.ability.wantConstant';  
  import fs from '@ohos.file.fs';  
  import fileUri from '@ohos.file.fileuri';  
  
  let targetBundleName = 'com.example.test_case1'  
  let path = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";  
  fs.mkdir(path, (err) => {  
    if (err) {  
      console.log("mkdir error"+err.message)  
    } else {  
      console.log("mkdir succeed")  
    }  
  });  
  let uri = fileUri.getUriFromPath(path);  
  uriPermissionManager.grantUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName, (result) => {  
    console.log("result.code = " + result.code)  
  })  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import uriPermissionManager from '@ohos.application.uriPermissionManager';  
  import WantConstant from '@ohos.app.ability.wantConstant';  
  import fs from '@ohos.file.fs';  
  import fileUri from '@ohos.file.fileuri';  
  import { BusinessError } from '@ohos.base';  
  
  let targetBundleName = 'com.example.test_case1'  
  let path = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";  
  
  fs.mkdir(path, (err) => {  
    if (err) {  
      console.log("mkdir error"+err.message)  
    } else {  
      console.log("mkdir succeed")  
    }  
  });  
  let uri = fileUri.getUriFromPath(path);  
  uriPermissionManager.grantUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName)  
    .then((data) => {  
      console.log('Verification succeeded.' + data)  
    }).catch((error: BusinessError) => {  
    console.log('Verification failed.');  
  })  
    
```    
  
    
## revokeUriPermission    
撤销授权指定应用的URI，通过callback返回结果。  
 **调用形式：**     
    
- revokeUriPermission(uri: string, targetBundleName: string, callback: AsyncCallback\<number>): void    
起始版本： 10    
- revokeUriPermission(uri: string, targetBundleName: string): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.PROXY_AUTHORIZATION_URI    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 |  
| targetBundleName | string | true | 被撤销授权uri的应用包名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回检验结果，返回0表示有权限，返回-1表示无权限。 |  
| Promise<number> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
| 16000059 | Invalid URI type. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
 import uriPermissionManager from '@ohos.application.uriPermissionManager';  
 let targetBundleName = 'com.example.test_case2' let uri = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir" uriPermissionManager.revokeUriPermission(uri, targetBundleName, (result) => {   console.log("result.code = " + result.code) })    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import uriPermissionManager from '@ohos.application.uriPermissionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let targetBundleName = 'com.example.test_case2'  
  let uri = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir"  
  uriPermissionManager.revokeUriPermission(uri, targetBundleName)  
  .then((data) => {  
      console.log('Verification succeeded.' + data)  
  }).catch((error: BusinessError) => {  
      console.log('Verification failed.');  
  })  
    
```    
  
