# Skill
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module defines a skill object. Such an object can be obtained through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with at least **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_SKILL** passed in to **bundleFlags**. (The skill information is contained in [BundleInfo](./js-apis-bundleManager-bundleInfo.md) -> [HapModuleInfo](./js-apis-bundleManager-hapModuleInfo.md) -> [AbilityInfo](./js-apis-bundleManager-abilityInfo.md) or [ExtensionAbilityInfo](./js-apis-bundleManager-extensionAbilityInfo.md).)

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
| Name    | Type  | Read-Only| Optional| Description      |
| -------- | ------ | ---- | ---- | ---------- |
| actions     | Array\<string> | Yes  | No  | [Actions](js-apis-ability-wantConstant.md#action) received by the skill.|
| entities    | Array\<string> | Yes  | No  | [Entities](js-apis-ability-wantConstant.md#entity) received by the skill.  |
| uris | Array\<SkillUri> | Yes  | No  | URIs that match Want.|
| domainVerify     | boolean | Yes  | No  | DomainVerify value received by the skill. This parameter exists only in **AbilityInfo** and specifies whether domain name verification is enabled. **true** if enabled, **false** otherwise.|

## SkillUri

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
| Name           | Type  | Read-Only| Optional| Description                                                       |
| --------------- | ------ | ---- | ---- | ----------------------------------------------------------- |
| scheme          | string | Yes  | No  | Scheme of the URI, such as HTTP, HTTPS, file, and FTP.         |
| host            | string | Yes  | No  | Host address of the URI. This parameter takes effect only when **scheme** is specified.           |
| port            | number | Yes  | No  | Port number of the URI. This parameter takes effect only when both **scheme** and **host** are specified.  |
| path            | string | Yes  | No  | Path of the URI. This parameter takes effect only when both **scheme** and **host** are specified.  |
| pathStartWith   | string | Yes  | No  | Prefix of the path of the URI. This parameter takes effect only when both **scheme** and **host** are specified.|
| pathRegex       | string | Yes  | No  | Regular expression of the path of the URI. This parameter takes effect only when both **scheme** and **host** are specified.|
| type            | string | Yes  | No  | Data type that matches Want. The value complies with the [Multipurpose Internet Mail Extensions (MIME) type](../../database/uniform-data-type-descriptors.md#utd-definition) specification.|
| utd             | string | Yes  | No  | Standard data type of the URI that matches Want. This parameter applies to sharing scenarios.|
| maxFileSupported | number   | Yes  | No  | Maximum number of files of a specified type that can be received or opened at a time. The value must be an integer greater than or equal to 0.|
| linkFeature     | string | Yes  | No  | [Feature type](../../application-models/app-uri-config.md#description-of-linkfeature) provided by the URI. It is used to implement redirection between applications and exists only in **AbilityInfo**.|
