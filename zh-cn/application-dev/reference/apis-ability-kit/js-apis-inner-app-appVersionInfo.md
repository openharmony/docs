# AppVersionInfo

应用版本信息，可以通过[getAppVersionInfo](js-apis-inner-app-context.md#contextgetappversioninfo7)获取当前应用的版本信息。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在FA模型下使用。

## 导入模块

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 类型   | 只读 | 可选 | 说明           |
| ----------- | ------ | ---- | ---- | -------------- |
| appName     | string | 是   | 否   | 应用名称。     |
| versionCode | number | 是   | 否   | 应用版本编码。 |
| versionName | string | 是   | 否   | 应用版本名称。   |

