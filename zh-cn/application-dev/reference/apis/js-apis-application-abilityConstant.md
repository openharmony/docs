# AbilityConstant

- [导入模块](#导入模块)
- [属性](#属性)

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

启动参数的接口.

## 导入模块

```js
import AbilityConstant from '@ohos.application.AbilityConstant';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| launchReason | LaunchReason| 是 | 是 | 指示启动原因。 | 
| lastExitReason | LastExitReason | 是 | 是 | 表示最后退出原因。 | 

## AbilityConstant.LaunchReason

初次开始原因的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知的状态。 |
| START_ABILITY          | 1    | 启动能力。 |
| CALL | 2    | 呼叫。 |
| CONTINUATION           | 3    | 继续。 |


## AbilityConstant.LastExitReason

上次退出原因的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知的状态。 |
| ABILITY_NOT_RESPONDING          | 1    | 能力没有反应 |
| NORMAL | 2    | 正常的状态。 |


## AbilityConstant.OnContinueResult 

继续结果的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | 同意。 |
| REJECT           | 1    | 拒绝。 |
| MISMATCH  | 2    | 不匹配。|
