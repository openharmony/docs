# Metadata

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
描述的module、ability、extensionAbility配置信息，标签值为数组类型，该标签下的配置只对当前module、或者ability、或者extensionAbility生效。
可以通过[getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)获取，此对象在[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)、[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)、[AbilityInfo](js-apis-bundleManager-abilityInfo.md)、[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)中均包含。

## Metadata

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core
| 名称     | 类型   | 可读 | 可写 | 说明       |
| -------- | ------ | ---- | ---- | ---------- |
| name     | string | 是   | 是   | 元数据名称 |
| value    | string | 是   | 是   | 元数据值   |
| resource | string | 是   | 是   | 元数据资源 |