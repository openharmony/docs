# Metadata

元数据对象，可以通过[bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取，其中入参bundleFlags至少包含GET_BUNDLE_INFO_WITH_METADATA。此对象在[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)、[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)、[AbilityInfo](js-apis-bundleManager-abilityInfo.md)、[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)中均包含。

> **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
描述的module、uiAbility、extensionAbility配置信息，标签值为数组类型，该标签下的配置只对当前module、uiAbility或者extensionAbility生效。

## Metadata

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core
| 名称     | 类型   | 只读 | 可选 | 说明       |
| -------- | ------ | ---- | ---- | ---------- |
| name     | string | 否   | 否   | 元数据名称。 |
| value    | string | 否   | 否   | 元数据值。   |
| resource | string | 否   | 否   | 元数据资源。 |
| valueId<sup>18+</sup>  | number | 是   | 是   | 元数据值id。当valueId不为0时，表示当前元数据值为自定义配置，需要使用valueId去资源管理获取对应的值。 当valueId为0时，表示当前元数据值为固定字符串。 |