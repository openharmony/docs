# ShellCmdResult

ShellCmdResult模块提供Shell命令执行结果的能力。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 使用说明

通过abilityDelegator中的executeShellCommand方法来获取。

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout).then((data : any) => {
    console.info("executeShellCommand promise");
});
```

## ShellCmdResult

Shell命令执行结果

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称      | 类型   | 可读 | 可写 | 说明                                                         |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| stdResult | string | 是   | 是   | 标准输出内容<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| exitCode  | number | 是   | 是   | 结果码<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
