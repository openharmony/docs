# Skill

The **Skill** module defines a skill object. Such an object can be obtained through [bundleManager.queryAbilityInfo](js-apis-bundleManager-sys.md#queryAbilityInfo), with at least **GET_ABILITY_INFO_WITH_SKILL** passed in to **abilityFlags**. This object is contained in both [AbilityInfo](js-apis-bundleManager-abilityInfo.md) and [ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Skill

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
| Name    | Type  | Readable| Writable| Description      |
| -------- | ------ | ---- | ---- | ---------- |
| actions     | Array\<String> | Yes  | No  | Actions received by the skill.|
| entities    | Array\<String> | Yes  | No  | Entities received by the skill.  |
| uris | Array<\<[uri](js-apis-bundleManager-uri.md)>> | Yes  | No  | URIs that match Want.|
| domainVerify     | String | Yes  | No  | DomainVerify value received by the skill. This parameter exists only in **AbilityInfo**.|
| permissions     | Array\<String> | Yes  | No  | Permissions received by the skill.|
