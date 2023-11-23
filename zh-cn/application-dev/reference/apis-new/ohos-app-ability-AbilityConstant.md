# @ohos.app.ability.AbilityConstant    
AbilityConstant提供Ability相关的枚举，包括设置初次启动原因、上次退出原因、迁移结果、窗口类型等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import AbilityConstant from '@ohos.app.ability.AbilityConstant'    
```  
    
## LaunchParam    
启动参数。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| launchReason | LaunchReason | false | true | 枚举类型，表示启动原因。 |  
| lastExitReason | LastExitReason | false | true | 枚举类型，表示最后退出原因。 |  
    
## LaunchReason    
Ability初次启动原因，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate)方法根据launchParam.launchReason的不同类型执行相应操作。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN | 0 | 未知原因。 |  
| START_ABILITY | 1 | 通过[startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口启动ability。 |  
| CALL | 2 | 通过[startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall)接口启动ability。 |  
| CONTINUATION | 3 | 跨端设备迁移启动ability。 |  
| APP_RECOVERY | 4 | 设置应用恢复后，应用故障时自动恢复启动ability。 |  
| SHARE<sup>(10+)</sup> | 5 | 通过原子化服务分享启动ability。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
  
class MyAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        if (launchParam.launchReason === AbilityConstant.LaunchReason.START_ABILITY) {  
            console.log('The ability has been started by the way of startAbility.');  
        }  
    }  
}  
    
```    
  
    
## LastExitReason    
Ability上次退出原因，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate)方法根据launchParam.lastExitReason的不同类型执行相应操作。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN | 0 | 未知原因。 |  
| ABILITY_NOT_RESPONDING<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用AbilityConstant.LastExitReason#APP_FREEZE替代。<br>ability未响应。从API version 9 开始支持，从API version 10 开始废弃，建议使用APP_FREEZE替代。  |  
| NORMAL | 2 | 用户主动关闭，应用程序正常退出。 |  
| CPP_CRASH<sup>(10+)</sup> | 3 | 本机异常信号，导致应用程序退出。 |  
| JS_ERROR<sup>(10+)</sup> | 4 | 当应用存在JS语法错误并未被开发者捕获时，触发JS_ERROR故障，导致应用程序退出。 |  
| APP_FREEZE<sup>(10+)</sup> | 5 | 由于watchdog检测出应用Freeze故障，导致应用程序退出。 |  
| PERFORMANCE_CONTROL<sup>(10+)</sup> | 6 | 由于系统性能问题（如设备内存不足），导致应用程序退出。 |  
| RESOURCE_CONTROL<sup>(10+)</sup> | 7 | 由于系统资源违规使用（超过CPU、I/O、内存的使用量），导致应用程序退出。 |  
| UPGRADE<sup>(10+)</sup> | 8 | 应用程序因升级而退出。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
  
class MyAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        if (launchParam.lastExitReason === AbilityConstant.LastExitReason.APP_FREEZE) {  
            console.log('The ability has exit last because the ability was not responding.');  
        }  
    }  
}  
    
```    
  
    
## OnContinueResult    
Ability迁移结果，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onContinue(wantParam)](js-apis-app-ability-uiAbility.md#uiabilityoncontinue)方法进完成相应的返回。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AGREE | 0 | <span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">表示同意。</span> |  
| REJECT | 1 | 表示拒绝：如应用在[onContinue](js-apis-app-ability-uiAbility.md#uiabilityoncontinue)中异常会导致迁移以后数据恢复时显示异常，则可以建议REJECT。 |  
| MISMATCH | 2 | 表示版本不匹配：迁移发起端应用可以在[onContinue](js-apis-app-ability-uiAbility.md#uiabilityoncontinue)中获取到迁移目标端应用的版本号，进行协商后，如果版本不匹配导致无法迁移，可以返回该错误。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
class MyAbility extends UIAbility {  
    onContinue(wantParam: Record<string, Object>) {  
        return AbilityConstant.OnContinueResult.AGREE;  
    }  
}  
    
```    
  
    
## MemoryLevel    
内存级别，该类型为枚举，可配合[Ability](js-apis-app-ability-ability.md)的[onMemoryLevel(level)](js-apis-app-ability-ability.md#abilityonmemorylevel)方法根据level执行不同内存级别的相应操作。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MEMORY_LEVEL_MODERATE | 0 |  内存占用适中。  |  
| MEMORY_LEVEL_LOW | 1 | 内存占用低。  |  
| MEMORY_LEVEL_CRITICAL | 2 | 内存占用高。   |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
class MyAbility extends UIAbility {  
    onMemoryLevel(level: AbilityConstant.MemoryLevel) {  
        if (level === AbilityConstant.MemoryLevel.MEMORY_LEVEL_CRITICAL) {  
            console.log('The memory of device is critical, please release some memory.');  
        }  
    }  
}  
    
```    
  
    
## OnSaveResult    
保存应用数据的结果，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate)方法完成相应的返回。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ALL_AGREE | 0 | 总是同意保存状态。 |  
| CONTINUATION_REJECT | 1 | 拒绝迁移保存状态。 |  
| CONTINUATION_MISMATCH | 2 | 迁移不匹配。 |  
| RECOVERY_AGREE | 3 | 同意恢复保存状态。 |  
| RECOVERY_REJECT | 4 | 拒绝恢复保存状态。 |  
| ALL_REJECT | 5 | 总是拒绝保存状态。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
class MyAbility extends UIAbility {  
    onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {  
        return AbilityConstant.OnSaveResult.ALL_AGREE;  
    }  
}  
    
```    
  
    
## StateType    
保存应用数据场景原因，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate)方法根据reason的不同类型执行相应操作。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONTINUATION | 0 | 迁移保存状态。 |  
| APP_RECOVERY | 1 | 应用恢复保存状态。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
class MyAbility extends UIAbility {  
    onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {  
        if (reason === AbilityConstant.StateType.CONTINUATION) {  
            console.log('Save the ability data when the ability continuation.');  
        }   
        return AbilityConstant.OnSaveResult.ALL_AGREE;  
    }  
}  
    
```    
  
    
## ContinueState<sup>(10+)</sup>    
流转状态枚举值。用于表示当前应用任务流转的状态。可配合[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)的[setMissionContinueState](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissioncontinuestate10)方法进行设置。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTIVE | 0 | 指示当前应用任务流转处于激活状态。  |  
| INACTIVE | 1 | 指示当前应用任务流转处于未激活状态。    |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class MyAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE, (result: BusinessError) => {  
        console.info(`setMissionContinueState: ${JSON.stringify(result)}`);  
        });  
    }  
}  
    
```    
  
