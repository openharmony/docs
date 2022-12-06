# AbilityDelegatorArgs

AbilityDelegatorArgs模块提供在应用程序启动期间，用于存储已注册的AbilityDelegator和AbilityDelegatorArgs对象的全局寄存器的能力。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 使用说明

通过AbilityDelegatorRegistry中getArguments方法获取。

## AbilityDelegatorArgs

测试参数信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                | 类型                   | 可读 | 可写 | 说明                                                         |
| ------------------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName          | string                 | 是   | 是   | 当前被测试应用的包名 |
| parameters          | {[key:string]: string} | 是   | 是   | 当前启动单元测试的参数 |
| testCaseNames       | string                 | 是   | 是   | 测试用例名称 |
| testRunnerClassName | string                 | 是   | 是   | 执行测试用例的测试执行器的名称 |

**示例：**

```ts
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry';

var args = AbilityDelegatorRegistry.getArguments();
```


