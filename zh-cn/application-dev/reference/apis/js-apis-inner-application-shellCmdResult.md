# ShellCmdResult

本模块提供Shell命令执行结果的能力。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称      | 类型   | 可读 | 可写 | 说明                                                         |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| stdResult | string | 是   | 是   | 标准输出内容。 |
| exitCode  | number | 是   | 是   | 结果码。 |

## 使用说明

通过abilityDelegator中的[executeShellCommand](js-apis-inner-application-abilityDelegator.md#executeshellcommand)方法来获取。

**示例：**
```ts
import AbilityDelegatorRegistry from "@ohos.application.abilityDelegatorRegistry";
let abilityDelegator;
let cmd = "cmd";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err: any, data: any) => {
    console.info("executeShellCommand callback, result: ", err);
    console.info("executeShellCommand callback, data: ", data);
});
```