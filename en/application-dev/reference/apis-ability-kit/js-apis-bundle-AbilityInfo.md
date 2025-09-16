# AbilityInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides information about an ability. Unless otherwise specified, the information is obtained through [bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are deprecated since API version 9. You are advised to use [bundleManager-AbilityInfo](js-apis-bundleManager-abilityInfo.md) instead.

## AbilityInfo<sup>(deprecated)<sup>

This API is deprecated since API version 9. You are advised to use [bundleManager-AbilityInfo](js-apis-bundleManager-abilityInfo.md#abilityinfo-1) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                 | Type                                                        | Read-Only| Optional| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| bundleName            | string                                                       | Yes  | No  | Bundle name.                                            |
| name                  | string                                                       | Yes  | No  | Ability name.                                               |
| label                 | string                                                       | Yes  | No  | Ability name visible to users.                                   |
| description           | string                                                       | Yes  | No  | Ability description.                                             |
| icon                  | string                                                       | Yes  | No  | Index of the ability icon resource file.                                 |
| descriptionId         | number                                                       | Yes  | No  | ID of the ability description.                                           |
| iconId                | number                                                       | Yes  | No  | ID of the ability icon.                                           |
| moduleName            | string                                                       | Yes  | No  | Name of the HAP file to which the ability belongs.                                    |
| process               | string                                                       | Yes  | No  | Process name of the ability.                 |
| targetAbility         | string                                                       | Yes  | No  | Target ability that the ability alias points to.<br>**Model restriction**: This API can be used only in the FA model.|
| backgroundModes       | number                                                       | Yes  | No  | Background service mode of the ability.<br>**Model restriction**: This API can be used only in the FA model.        |
| isVisible             | boolean                                                      | Yes  | No  | Whether the ability can be called by other applications. **true** if the ability can be called by other applications, **false** otherwise.                         |
| formEnabled           | boolean                                                      | Yes  | No  | Whether the ability provides the service widget capability. **true** if the ability provides the service widget capability, **false** otherwise.<br>**Model restriction**: This API can be used only in the FA model.|
| type                  | bundle.AbilityType                                                  | Yes  | No  | Ability type.<br>**Model restriction**: This API can be used only in the FA model.               |
| orientation           | [bundle.DisplayOrientation](js-apis-Bundle.md#displayorientationdeprecated) | Yes  | No  | Ability display orientation.                                         |
| launchMode            | [bundle.LaunchMode](js-apis-Bundle.md#launchmodedeprecated)         | Yes  | No  | Ability launch mode.                                         |
| permissions           | Array\<string>                                               | Yes  | No  | Permissions required for other applications to call the ability.<br>The value is obtained by passing in GET_ABILITY_INFO_WITH_PERMISSION to [bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated).|
| deviceTypes           | Array\<string>                                               | Yes  | No  | Device types supported by the ability.                                     |
| deviceCapabilities    | Array\<string>                                               | Yes  | No  | Device capabilities required for the ability.                                     |
| readPermission        | string                                                       | Yes  | No  | Permission required for reading the ability data.<br>**Model restriction**: This API can be used only in the FA model. |
| writePermission       | string                                                       | Yes  | No  | Permission required for writing data to the ability.<br>**Model restriction**: This API can be used only in the FA model. |
| applicationInfo       | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md)         | Yes  | No  | Application configuration information.<br>The value is obtained by passing in GET_ABILITY_INFO_WITH_APPLICATION to [bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated).|
| uri                   | string                                                       | Yes  | No  | URI of the ability.<br>**Model restriction**: This API can be used only in the FA model.|
| labelId               | number                                                       | Yes  | No  | ID of the ability label.                                           |
| subType               | bundle.AbilitySubType                                               | Yes  | No  | Subtype of the template that can be used by the ability.<br>**Model restriction**: This API can be used only in the FA model.|
| metaData<sup>8+</sup> | Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)>     | Yes  | No  | Metadata of the ability.<br>The value is obtained by passing in GET_ABILITY_INFO_WITH_METADATA to [bundle.getAbilityInfo](js-apis-Bundle.md#bundlegetabilityinfodeprecated).|
| enabled<sup>8+</sup>  | boolean                                                      | Yes  | No  | Whether the ability is enabled. **true** if enabled, **false** otherwise.                                           |
