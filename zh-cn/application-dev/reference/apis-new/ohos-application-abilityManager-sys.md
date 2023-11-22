# @ohos.application.abilityManager    
AbilityManager模块提供对Ability相关信息和状态信息进行获取、新增、修改等能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import abilityManager from '@ohos.application.abilityManager'    
```  
    
## AbilityState<sup>(deprecated)</sup>    
Ability的状态信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityManager/abilityManager#AbilityState替代。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INITIAL<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityManager/abilityManager.AbilityState#INITIAL替代。<br>表示ability为initial状态。 |  
| FOREGROUND<sup>(deprecated)</sup> | 9 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityManager/abilityManager.AbilityState#FOREGROUND替代。<br>表示ability为foreground状态。 |  
| BACKGROUND<sup>(deprecated)</sup> | 10 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityManager/abilityManager.AbilityState#BACKGROUND替代。<br>表示ability为background状态。 |  
| FOREGROUNDING<sup>(deprecated)</sup> | 11 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityManager/abilityManager.AbilityState#FOREGROUNDING替代。<br>表示ability为foregrounding状态。 |  
| BACKGROUNDING<sup>(deprecated)</sup> | 12 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.abilityManager/abilityManager.AbilityState#BACKGROUNDING替代。<br>表示ability为backgrounding状态。 |  
    
## updateConfiguration<sup>(deprecated)</sup>    
通过修改配置来更新配置（callback形式）。  
 **调用形式：**     
- updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.abilityManager/abilityManager#updateConfiguration。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | Configuration | true | 新的配置项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 被指定的回调方法。   |  
    
 **示例代码：**   
示例 （callback）：  
```ts    
import abilityManager from '@ohos.application.abilityManager';  
import { Configuration } from '@ohos.application.Configuration';  
  
let config: Configuration = {  
  language: 'chinese'   
};  
  
abilityManager.updateConfiguration(config, () => {  
    console.log('------------ updateConfiguration -----------');  
});  
    
```    
  
    
## updateConfiguration<sup>(deprecated)</sup>    
  
  
通过修改配置来更新配置（Promise形式）。  
 **调用形式：**     
- updateConfiguration(config: Configuration): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.abilityManager/abilityManager#updateConfiguration。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | Configuration | true | 新的配置项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 返回执行结果。 |  
    
 **示例代码：**   
示例 （promise）：  
```ts    
import abilityManager from '@ohos.application.abilityManager';  
import { Configuration } from '@ohos.application.Configuration';  
import { BusinessError } from '@ohos.base';  
  
let config: Configuration = {  
  language: 'chinese'   
};  
  
abilityManager.updateConfiguration(config).then(() => {  
  console.log('updateConfiguration success');  
}).catch((err: BusinessError) => {  
  console.error('updateConfiguration fail');  
});  
    
```    
  
    
## getAbilityRunningInfos<sup>(deprecated)</sup>    
获取Ability运行相关信息（callback形式）。  
 **调用形式：**     
- getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.abilityManager/abilityManager#getAbilityRunningInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<AbilityRunningInfo>> | 返回执行结果。 |  
    
 **示例代码：**   
示例 （promise）：  
```ts    
import abilityManager from '@ohos.application.abilityManager';  
import { BusinessError } from '@ohos.base';  
  
abilityManager.getAbilityRunningInfos().then((data) => {  
    console.log(`getAbilityRunningInfos  data: ${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
  console.error(`getAbilityRunningInfos err: ${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getAbilityRunningInfos<sup>(deprecated)</sup>    
获取Ability运行相关信息（Promise形式）。  
 **调用形式：**     
- getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.abilityManager/abilityManager#getAbilityRunningInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<AbilityRunningInfo>> | true | 被指定的回调方法。  |  
    
 **示例代码：**   
示例 （callback）：  
```ts    
import abilityManager from '@ohos.application.abilityManager';  
abilityManager.getAbilityRunningInfos((err,data) => {   console.log(`getAbilityRunningInfos err: ${err}, data: ${JSON.stringify(data)}`);});    
```    
  
