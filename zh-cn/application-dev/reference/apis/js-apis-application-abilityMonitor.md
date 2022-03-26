# AbilityMonitor

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```



## AbilityMonitor

Ability监听器

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                 | 类型     | 可读 | 可写 | 说明                                                         |
| -------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName          | string   | 是   | 是   | 当前AbilityMonitor绑定的ability名称。                        |
| onAbilityCreate      | function | 是   | 是   | ability被启动初始化时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onAbilityForeground  | function | 是   | 是   | ability状态变成前台时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onAbilityBackground  | function | 是   | 是   | ability状态变成后台时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onAbilityDestroy     | function | 是   | 是   | ability被销毁前的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onWindowStageCreate  | function | 是   | 是   | window stage被创建时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onWindowStageRestore | function | 是   | 是   | window stage被重载时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onWindowStageDestroy | function | 是   | 是   | window stage被销毁前的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |

