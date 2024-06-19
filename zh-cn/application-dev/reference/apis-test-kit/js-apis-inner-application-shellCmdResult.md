# ShellCmdResult

本模块提供Shell命令执行结果的能力。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在<!--RP1-->[自动化测试框架arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->中使用。

## 导入模块

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称      | 类型   | 可读 | 可写 | 说明                                                         |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| stdResult | string | 是   | 是   | 标准输出内容。 |
| exitCode  | number | 是   | 是   | 结果码。 |

## 使用说明

通过abilityDelegator中的[executeShellCommand](js-apis-inner-application-abilityDelegator.md#executeshellcommand)方法来获取。

**示例：**
```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let cmd = 'cmd';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (error: BusinessError, data) => {
  if (error) {
    console.error(`executeShellCommand fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`executeShellCommand success, data: ${JSON.stringify(data)}`);
  }
});
```