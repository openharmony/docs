# AbilityMonitor

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明**
>
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。

## 导入模块

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```



## AbilityMonitor

Ability监听器

**系统能力**：以下属性的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                                                         | 类型     | 可读 | 可写 | 说明                                                         |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | 是   | 是   | 当前AbilityMonitor绑定的ability名称 |
| onAbilityCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability被启动初始化时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onAbilityForeground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability状态变成前台时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onAbilityBackground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability状态变成后台时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onAbilityDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | ability被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onWindowStageCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被创建时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onWindowStageRestore?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被重载时的回调函数<br/>不设置该属性则不能收到该生命周期回调 |
| onWindowStageDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | 是   | 是   | window stage被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调 |


