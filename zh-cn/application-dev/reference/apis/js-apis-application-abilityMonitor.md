# AbilityMonitor

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { AbilityMonitor } from './abilityMonitor';
```



## AbilityMonitor

Ability监听器

| 名称                 | 类型     | 可读 | 可写 | 说明                                                         |
| -------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName          | string   | 是   | 是   | 当前AbilityMonitor绑定的ability名称<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityCreate      | function | 是   | 是   | ability被启动初始化时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityForeground  | function | 是   | 是   | ability状态变成前台时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityBackground  | function | 是   | 是   | ability状态变成后台时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityDestroy     | function | 是   | 是   | ability被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageCreate  | function | 是   | 是   | window stage被创建时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageRestore | function | 是   | 是   | window stage被重载时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageDestroy | function | 是   | 是   | window stage被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |


