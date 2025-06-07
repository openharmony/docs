# AbilityDelegatorArgs

AbilityDelegatorArgs模块提供在应用程序执行测试用例期间，获取测试用例参数AbilityDelegatorArgs对象的能力。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> 
> 本模块接口仅可在<!--RP1-->[自动化测试框架arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->中使用。

## 导入模块

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## 使用说明

通过AbilityDelegatorRegistry中[getArguments](js-apis-app-ability-abilityDelegatorRegistry.md#abilitydelegatorregistrygetarguments)方法获取。

## AbilityDelegatorArgs

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                | 类型                   | 只读 | 可选 | 说明                                                         |
| ------------------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName          | string                 | 否   | 否   | 当前被测试应用的包名。 |
| parameters          | Record\<string, string> | 否   | 否   | 当前启动单元测试的参数。 |
| testCaseNames       | string                 | 否   | 否   | 测试用例名称。 |
| testRunnerClassName | string                 | 否   | 否   | 执行测试用例的测试执行器名称。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let args: abilityDelegatorRegistry.AbilityDelegatorArgs = abilityDelegatorRegistry.getArguments();
```
