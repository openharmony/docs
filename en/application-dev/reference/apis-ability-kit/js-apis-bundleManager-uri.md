# uri

The **uri** module defines a URI object. Such an object can be obtained through [bundleManager.queryAbilityInfo](js-apis-bundleManager-sys.md#queryAbilityInfo), with at least **GET_ABILITY_INFO_WITH_SKILL** passed in to **abilityFlags**. This object is contained in [Skill](js-apis-bundleManager-skill.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## uri

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name           | Type  | Readable| Writable| Description                                                       |
| --------------- | ------ | ---- | ---- | ----------------------------------------------------------- |
| scheme          | String | Yes  | No  | Scheme of the URI, such as HTTP, HTTPS, file, and FTP.                                          |
| host            | String | Yes  | No  | Host address of the URI. This parameter is valid only when **scheme** is specified.           |
| port            | String | Yes  | No  | Port number of the URI. This parameter is valid only when both **scheme** and **host** are specified.  |
| path            | String | Yes  | No  | Path of the URI. This parameter is valid only when both **scheme** and **host** are specified.  |
| pathStartWith   | String | Yes  | No  | Prefix of the path of the URI. This parameter is valid only when both **scheme** and **host** are specified.|
| pathRegex       | String | Yes  | No  | Regular expression of the path of the URI. This parameter is valid only when both **scheme** and **host** are specified.|
| utd             | String | Yes  | No  | Standard data type of the URI that matches Want. This parameter applies to sharing scenarios.|
| maxFileSupported | Number   | Yes  | No  | Maximum number of files of a specified type that can be received or opened at a time.|
| linkFeature     | String | Yes  | No  | Feature type provided by the URI. It is used to implement redirection between applications and exists only in **AbilityInfo**.|
