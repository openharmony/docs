# Skill

The Skill module defines a skill object. Such an object can be obtained through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with at least **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_SKILL** passed in to **bundleFlags**. (The skill information is contained in [BundleInfo](./js-apis-bundleManager-bundleInfo.md) -> [HapModuleInfo](./js-apis-bundleManager-hapModuleInfo.md) -> [AbilityInfo](./js-apis-bundleManager-abilityInfo.md) or [ExtensionAbilityInfo](./js-apis-bundleManager-extensionAbilityInfo.md).)

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## Skill

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
| Name    | Type  | Readable| Writable| Description      |
| -------- | ------ | ---- | ---- | ---------- |
| actions     | Array\<string> | Yes  | No  | Actions received by the skill.|
| entities    | Array\<string> | Yes  | No  | Entities received by the skill.  |
| uris | Array\<SkillUri> | Yes  | No  | URIs that match Want.|
| domainVerify     | boolean | Yes  | No  | DomainVerify value received by the skill. This parameter exists only in **AbilityInfo** and specifies whether domain name verification is enabled. The value **true** means that domain name verification is enabled, and **false** means the opposite.|

## SkillUri

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
| Name           | Type  | Readable| Writable| Description                                                       |
| --------------- | ------ | ---- | ---- | ----------------------------------------------------------- |
| scheme          | string | Yes  | No  | Scheme of the URI, such as HTTP, HTTPS, file, and FTP.         |
| host            | string | Yes  | No  | Host address of the URI. This parameter is valid only when **scheme** is specified.           |
| port            | number | Yes  | No  | Port number of the URI. This parameter is valid only when both **scheme** and **host** are specified.  |
| path            | string | Yes  | No  | Path of the URI. This parameter is valid only when both **scheme** and **host** are specified.  |
| pathStartWith   | string | Yes  | No  | Prefix of the path of the URI. This parameter is valid only when both **scheme** and **host** are specified.|
| pathRegex       | string | Yes  | No  | Regular expression of the path of the URI. This parameter is valid only when both **scheme** and **host** are specified.|
| type            | string | Yes  | No  | Data type that matches the want. The value complies with the Multipurpose Internet Mail Extensions (MIME) type specification.|
| utd             | string | Yes  | No  | Standard data type of the URI that matches Want. This parameter applies to sharing scenarios.|
| maxFileSupported | number   | Yes  | No  | Maximum number of files of a specified type that can be received or opened at a time.|
| linkFeature     | string | Yes  | No  | Feature type provided by the URI. It is used to implement redirection between applications and exists only in **AbilityInfo**.|
