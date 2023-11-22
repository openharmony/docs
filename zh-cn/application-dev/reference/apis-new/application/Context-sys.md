# Context    
Context模块提供了ability或application的上下文的能力，包括访问特定应用程序的资源等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import common from '@ohos.app.ability.common';  
    
```  
    
## Context    
Context模块提供了ability或application的上下文的能力，包括访问特定应用程序的资源等。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### createBundleContext    
根据Bundle名称创建安装包的上下文。  
 **调用形式：**     
- createBundleContext(bundleName: string): Context  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Context | 安装包的上下文。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import common from '@ohos.app.ability.common';  
  
export default class EntryAbility extends UIAbility {  
  onCreate() {  
    console.log('MyAbility onCreate');  
    let bundleContext: common.Context;  
    try {  
      bundleContext = this.context.createBundleContext('com.example.test');  
    } catch (error) {  
      console.error(`createBundleContext failed, error.code: ${error.code}, error.message: ${error.message}`);  
    }  
  }  
}  
    
```    
  
    
### createModuleContext    
根据Bundle名称和模块名称创建上下文。  
 **调用形式：**     
- createModuleContext(bundleName: string, moduleName: string): Context  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | Bundle名称。 |  
| moduleName | string | true | 模块名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Context | 模块的上下文。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import common from '@ohos.app.ability.common';  
  
export default class EntryAbility extends UIAbility {  
  onCreate() {  
    console.log('MyAbility onCreate');  
    let moduleContext: common.Context;  
    try {  
      moduleContext = this.context.createModuleContext('com.example.test', 'entry');  
    } catch (error) {  
      console.error('createModuleContext failed, error.code: ${error.code}, error.message: ${error.message}');  
    }  
  }  
}  
    
```    
  
