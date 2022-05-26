# AbilityDelegatorArgs

> **说明**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```



## AbilityDelegatorArgs

测试参数信息

| 名称                | 类型                   | 可读 | 可写 | 说明                                                         |
| ------------------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName          | string                 | 是   | 是   | 当前被测试应用的包名<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| parameters          | {[key:string]: string} | 是   | 是   | 当前启动单元测试的参数<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| testCaseNames       | string                 | 是   | 是   | 测试用例名称<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |
| testRunnerClassName | string                 | 是   | 是   | 执行测试用例的测试执行器的名称<br/>**系统能力：** SystemCapability.Ability.AbilityRuntime.Core |


