# @ohos.app.ability.wantConstant (wantConstant)(系统接口)

wantConstant模块提供want中操作want常数和解释Flags说明的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.wantConstant (wantConstant)](js-apis-app-ability-wantConstant.md)。

## 导入模块

```ts
import { wantConstant } from '@kit.AbilityKit';
```

## Params

want的Params操作的常量。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称                    | 值                                 | 说明                                                                           |
| ----------------------- | ---------------------------------- | ------------------------------------------------------------------------------ |
| DLP_PARAMS_SANDBOX      | ohos.dlp.params.sandbox            | 指示沙盒标志的参数的操作。<br>**系统接口**：此接口为系统接口。 |
| DLP_PARAMS_BUNDLE_NAME  | ohos.dlp.params.bundleName         | 指示DLP Bundle名称的参数的操作。 <br>**系统接口**：此接口为系统接口。 |
| DLP_PARAMS_MODULE_NAME  | ohos.dlp.params.moduleName         | 指示DLP模块名称的参数的操作。 <br>**系统接口**：此接口为系统接口。 |
| DLP_PARAMS_ABILITY_NAME | ohos.dlp.params.abilityName        | 指示DLP能力名称的参数的操作。 <br>**系统接口**：此接口为系统接口。 |
| DLP_PARAMS_INDEX        | ohos.dlp.params.index              | 指示DLP索引参数的操作。 <br>**系统接口**：此接口为系统接口。 |
| ASSERT_FAULT_SESSION_ID<sup>12+</sup>  | ohos.ability.params.asssertFaultSessionId      | 指示AssertFault的会话ID。 <br>**系统接口**：此接口为系统接口。 |