# Skill

skill标签对象，可以通过[bundleManager.queryAbilityInfo](js-apis-bundleManager-sys.md#queryAbilityInfo)获取，其中入参abilityFlags至少包含GET_ABILITY_INFO_WITH_SKILL。此对象在[AbilityInfo](js-apis-bundleManager-abilityInfo.md)、[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)中均包含。

> **说明：**
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## Skill

**系统能力**: SystemCapability.BundleManager.BundleFramework.Core
| 名称     | 类型   | 可读 | 可写 | 说明       |
| -------- | ------ | ---- | ---- | ---------- |
| actions     | Array\<String> | 是   | 否   | Skill接收的Action集合。 |
| entities    | Array\<String> | 是   | 否   | Skill接收的Entity集合。   |
| uris | Array<\<[uri](js-apis-bundleManager-uri.md)>> | 是   | 否   | Want匹配的Uri集合。 |
| domainVerify     | String | 是   | 否   | Skill接收的DomainVerify值, 仅在AbilityInfo中存在。 |
| permissions     | Array\<String> | 是   | 否   | Skill接收的Permission集合。 |