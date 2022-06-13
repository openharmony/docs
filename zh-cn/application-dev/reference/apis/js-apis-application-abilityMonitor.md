# AbilityMonitor

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```

## AbilityMonitor

Ability监听器

| 名称                                                         | 类型     | 可读 | 可写 | 说明                                                         |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | 是   | 是   | 当前AbilityMonitor绑定的ability名称<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability被启动初始化时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityForeground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability状态变成前台时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityBackground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability状态变成后台时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被创建时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageRestore?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被重载时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |


