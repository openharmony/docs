# AbilityConstant

- [导入模块](#导入模块)
- [属性](#属性)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。


启动参数的接口.


## 导入模块

  
```js
import AbilityConstant from '@ohos.application.AbilityConstant';
```


## 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| launchReason | LaunchReason| 是 | 是 | 指示启动原因。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| lastExitReason | LastExitReason | 是 | 是 | 表示最后退出原因。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 

## AbilityConstant.LaunchReason

初次开始原因的类型。

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知的状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| START_ABILITY          | 1    | 启动能力。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| CALL | 2    | 呼叫。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| CONTINUATION           | 3    | 继续。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |


## AbilityConstant.LaunchReason

上次退出原因的类型。

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知的状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| ABILITY_NOT_RESPONDING          | 1    | 能力没有反应<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| NORMAL | 2    | 正常的状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |


## AbilityConstant.OnContinueResult 

继续结果的类型。

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | 同意。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| REJECT           | 1    | 拒绝。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| MISMATCH  | 2    | 不匹配。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
