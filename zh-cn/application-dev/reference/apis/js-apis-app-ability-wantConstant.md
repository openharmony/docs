# @ohos.app.ability.wantConstant (wantConstant)

wantConstant模块提供want中操作want常数和解释Flags说明的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import wantConstant from '@ohos.app.ability.wantConstant';
```

## wantConstant.Params

want操作的常数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称                    | 值                                 | 说明                                                                           |
| ----------------------- | ---------------------------------- | ------------------------------------------------------------------------------ |
| DLP_PARAMS_SANDBOX      | ohos.dlp.params.sandbox            | 指示沙盒标志的参数的操作。<br>**系统API**：该接口为系统接口，三方应用不支持调用。 |
| DLP_PARAMS_BUNDLE_NAME  | ohos.dlp.params.bundleName         | 指示DLP Bundle名称的参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |
| DLP_PARAMS_MODULE_NAME  | ohos.dlp.params.moduleName         | 指示DLP模块名称的参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |
| DLP_PARAMS_ABILITY_NAME | ohos.dlp.params.abilityName        | 指示DLP能力名称的参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |
| DLP_PARAMS_INDEX        | ohos.dlp.params.index              | 指示DLP索引参数的操作。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |
| ABILITY_BACK_TO_OTHER_MISSION_STACK   | ability.params.backToOtherMissionStack     | 表示是否支持跨任务链返回。 <br>**系统API**：该接口为系统接口，三方应用不支持调用。 |

## wantConstant.Flags

Flags说明。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称                                 | 值       | 说明                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权。                                  |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权。                                  |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能。                              |