# @ohos.app.ability.quickFixManager    
quickFixManager模块提供快速修复的能力，快速修复是系统提供给开发者的一种技术手段，支持开发者以远快于（小时级、分钟级）应用升级的方式进行缺陷修复。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import quickFixManager from '@ohos.app.ability.quickFixManager'    
```  
    
## HapModuleQuickFixInfo    
hap级别的快速修复信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.QuickFix    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.QuickFix    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| moduleName | string | true | true | HAP的名称。 |  
| originHapHash | string | true | true | 指示hap的哈希值。 |  
| quickFixFilePath | string | true | true | 指示快速修复文件的安装路径。 |  
    
## ApplicationQuickFixInfo    
应用级别的快速修复信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.QuickFix    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.QuickFix    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | 应用Bundle名称。 |  
| bundleVersionCode | number | true | true | 应用的版本号。 |  
| bundleVersionName | string | true | true | 应用版本号的文字描述。 |  
| quickFixVersionCode | number | true | true | 快速修复补丁包的版本号。 |  
| quickFixVersionName | string | true | true | 快速修复补丁包版本号的文字描述。 |  
| hapModuleQuickFixInfo | Array<HapModuleQuickFixInfo> | true | true | hap级别的快速修复信息。 |  
    
## applyQuickFix    
快速修复的补丁安装接口。  
 **调用形式：**     
    
- applyQuickFix(hapModuleQuickFixFiles: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- applyQuickFix(hapModuleQuickFixFiles: Array\<string>): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.QuickFix  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hapModuleQuickFixFiles | Array<string> | true | 快速修复补丁文件（补丁文件需包含有效的文件路径）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法。 |  
| Promise<void> | 返回相应结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 18500002 | The specified quick fix is invalid. It may not exist or inaccessible. |  
| 18500008 | Internal error. |  
    
 **示例代码1：**   
  
示例(callback):  
```ts    
import quickFixManager from '@ohos.app.ability.quickFixManager';  
  
  try {  
    let hapModuleQuickFixFiles = ['/data/storage/el2/base/entry.hqf'];  
    quickFixManager.applyQuickFix(hapModuleQuickFixFiles, (error) => {  
      if (error) {  
          console.error( `applyQuickFix failed with error: ${error}`);  
      } else {  
          console.info( 'applyQuickFix success');  
      }  
    });  
  } catch (paramError) {  
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
  }  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import quickFixManager from '@ohos.app.ability.quickFixManager';  
import { BusinessError } from '@ohos.base';  
  
  try {  
    let bundleName = 'bundleName';  
    quickFixManager.getApplicationQuickFixInfo(bundleName).then((data) => {  
      console.info(`getApplicationQuickFixInfo success: ${data}`);  
    }).catch((error: BusinessError) => {  
      console.error(`getApplicationQuickFixInfo err: ${error}`);  
    });  
  } catch (paramError) {  
    console.error(`error: ${paramError.code}, ${paramError.message}`);  
  }  
    
```    
  
    
## revokeQuickFix<sup>(10+)</sup>    
撤销快速修复的接口，使用callback方式返回结果。  
 **调用形式：**     
    
- revokeQuickFix(bundleName: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- revokeQuickFix(bundleName: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.QuickFix  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 需要撤销补丁的应用Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法。 |  
| Promise<void> | 返回相应结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 18500001 | The bundle is not exist or no patch has applied. |  
| 18500009 | The application has a apply quick fix task that is being processed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import quickFixManager from '@ohos.app.ability.quickFixManager';  
  let bundleName = "com.example.myapplication";  quickFixManager.revokeQuickFix(bundleName, (err) => {    console.info("revokeQuickFix " + bundleName + " " + JSON.stringify(err));  });    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import quickFixManager from '@ohos.app.ability.quickFixManager';  
import { BusinessError } from '@ohos.base';  
  
  let bundleName = "com.example.myapplication";  
  quickFixManager.revokeQuickFix(bundleName).then(() => {  
    console.info("revokeQuickFix " + bundleName +" ok");  
  }).catch((err: BusinessError) => {  
    console.info("revokeQuickFix " + bundleName +" failed, error code is ", JSON.stringify((err)));  
  });  
    
```    
  
    
## getApplicationQuickFixInfo    
获取应用的快速修复信息。  
 **调用形式：**     
    
- getApplicationQuickFixInfo(bundleName: string, callback: AsyncCallback\<ApplicationQuickFixInfo>): void    
起始版本： 9    
- getApplicationQuickFixInfo(bundleName: string): Promise\<ApplicationQuickFixInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.QuickFix  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 应用的快速修复信息。 |  
| Promise<ApplicationQuickFixInfo> | 返回应用的快速修复信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 18500001 | The specified bundleName is invalid. |  
| 18500008 | Internal error. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import quickFixManager from '@ohos.app.ability.quickFixManager';  
  
  try {  
    let bundleName = 'bundleName';  
    quickFixManager.getApplicationQuickFixInfo(bundleName, (error, data) => {  
      if (error) {  
        console.error(`getApplicationQuickFixInfo error: ${error}`);  
      } else {  
        console.info(`getApplicationQuickFixInfo success: ${data}`);  
      }  
    });  
  } catch (paramError) {  
    console.error(`error: ${paramError.code}, ${paramError.message}`);  
  }  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import quickFixManager from '@ohos.app.ability.quickFixManager';  
import { BusinessError } from '@ohos.base';  
  
  try {  
    let bundleName = 'bundleName';  
    quickFixManager.getApplicationQuickFixInfo(bundleName).then((data) => {  
      console.info(`getApplicationQuickFixInfo success: ${data}`);  
    }).catch((error: BusinessError) => {  
      console.error(`getApplicationQuickFixInfo err: ${error}`);  
    });  
  } catch (paramError) {  
    console.error(`error: ${paramError.code}, ${paramError.message}`);  
  }  
    
```    
  
