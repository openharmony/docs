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
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| resourceManager | resmgr.ResourceManager | false | true | 资源管理对象。 |  
| applicationInfo | ApplicationInfo | false | true | 当前应用程序的信息。 |  
| cacheDir | string | false | true | 缓存目录。 |  
| tempDir | string | false | true | 临时目录。 |  
| filesDir | string | false | true | 文件目录。 |  
| databaseDir | string | false | true | 数据库目录。 |  
| preferencesDir | string | false | true | preferences目录。 |  
| bundleCodeDir | string | false | true | 安装包目录。不能拼接路径访问资源文件，请使用[资源管理接口](js-apis-resource-manager.md)访问资源。 |  
| distributedFilesDir | string | false | true | 分布式文件目录。 |  
| eventHub | EventHub | false | true | 事件中心，提供订阅、取消订阅、触发事件对象。 |  
| area | contextConstant.AreaMode | false | true | 文件分区信息。 |  
    
### createModuleContext    
根据模块名创建上下文。  
 **调用形式：**     
- createModuleContext(moduleName: string): Context  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
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
      moduleContext = this.context.createModuleContext('entry');  
    } catch (error) {  
      console.error('createModuleContext failed, error.code: ${error.code}, error.message: ${error.message}');  
    }  
  }  
}  
    
```    
  
    
### getApplicationContext    
获取本应用的应用上下文。  
 **调用形式：**     
- getApplicationContext(): ApplicationContext  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ApplicationContext | 应用上下文Context。 |  
    
    
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
    let applicationContext: common.Context;  
    try {  
      applicationContext = this.context.getApplicationContext();  
    } catch (error) {  
      console.error('getApplicationContext failed, error.code: ${error.code}, error.message: ${error.message}');  
    }  
  }  
}  
    
```    
  
    
### getGroupDir<sup>(10+)</sup>    
通过使用元服务应用中的Group ID获取对应的共享目录，使用Promise异步回调。  
 **调用形式：**     
    
- getGroupDir(dataGroupID: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getGroupDir(dataGroupID: string): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataGroupID | string | true | 元服务应用项目创建时，系统会指定分配唯一Group ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback方式返回对应的共享目录。如果不存在则返回为空，仅支持应用el2加密级别。 |  
| Promise<string> | 以Promise方式返回对应的共享目录。如果不存在则返回为空，仅支持应用el2加密级别。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000011 | The context does not exist. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import common from '@ohos.app.ability.common';  
  
export default class EntryAbility extends UIAbility {  
  onCreate() {  
    console.log('MyAbility onCreate');  
    let getGroupDirContext: common.Context = this.context;  
  
    getGroupDirContext.getGroupDir("1", (err, data) => {  
      if (err) {  
        console.error(`getGroupDir faile, err: ${JSON.stringify(err)}`);  
      } else {  
        console.log(`getGroupDir result is: ${JSON.stringify(data)}`);  
      }  
    });  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import common from '@ohos.app.ability.common';  
  
export default class EntryAbility extends UIAbility {  
  onCreate() {  
    console.log('MyAbility onCreate');  
    let groupId = "1";  
    let getGroupDirContext: common.Context = this.context;  
    try {  
      getGroupDirContext.getGroupDir(groupId).then(data => {  
        console.log("getGroupDir result:" + data);  
      })  
    } catch (error) {  
      console.error('getGroupDirContext failed, error.code: ${error.code}, error.message: ${error.message}');  
    }  
  }  
}  
    
```    
  
