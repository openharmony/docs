# AppVersionInfo

应用版本信息，可以通过[getAppVersionInfo](js-apis-inner-app-context.md#contextgetappversioninfo7)获取当前应用的版本信息。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 类型   | 可读 | 可写 | 说明           |
| ----------- | ------ | ---- | ---- | -------------- |
| appName     | string | 是   | 否   | 应用名称。     |
| versionCode | number | 是   | 否   | 应用版本编码。 |
| versionName | string | 是   | 否   | 应用版本号。   |

