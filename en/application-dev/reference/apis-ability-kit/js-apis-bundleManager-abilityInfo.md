# AbilityInfo

The module defines the ability information. An application can obtain its own ability information through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_ABILITY** passed in to [bundleFlags](js-apis-bundleManager.md#bundleflag).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## AbilityInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                 | Type                                                    | Read-Only| Optional| Description                                     |
| --------------------- | -------------------------------------------------------- | ---- | ---- | ------------------------------------------ |
| bundleName            | string                                                   | Yes  | No  | Bundle name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| moduleName            | string                                                   | Yes  | No  | Module name to which the ability belongs.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| name                  | string                                                   | Yes  | No  | Ability name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| label                 | string                                                   | Yes  | No  | Resource descriptor of the ability name visible to users. Example: **"label": "$string: mainability_description"**. Since API version 20, if [bundleManager.getAbilityInfo](js-apis-bundleManager.md#bundlemanagergetabilityinfo20) is used to obtain ability information, this field is the ability name visible to users.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| labelId               | number                                                   | Yes  | No  | ID of the ability label.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| description           | string                                                   | Yes  | No  | Ability description.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| descriptionId         | number                                                   | Yes  | No  | ID of the ability description.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| icon                  | string                                                   | Yes  | No  | Resource descriptor of the ability icon. Example: **"icon": "$media:icon"**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| iconId                | number                                                   | Yes  | No  | ID of the ability icon.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| process               | string                                                   | Yes  | No  | Process name of the ability.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| exported             | boolean                                                  | Yes  | No  | Whether the ability can be called by other applications. The value **true** means that the ability can be called by other applications, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| type                  | [bundleManager.AbilityType](js-apis-bundleManager.md#abilitytype)      | Yes  | No  | Ability type.<br>**Model restriction**: This API can be used only in the FA model.|
| orientation           | [bundleManager.DisplayOrientation](js-apis-bundleManager.md#displayorientation)  | Yes  | No  | Ability display orientation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| launchType            | [bundleManager.LaunchType](js-apis-bundleManager.md#launchtype)        | Yes  | No  | Ability launch mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| permissions           | Array\<string>                                           | Yes  | No  | Permissions required for other applications to call the ability.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| readPermission        | string                                                   | Yes  | No  | Permission required for reading the ability data.<br>**Model restriction**: This API can be used only in the FA model.|
| writePermission       | string                                                   | Yes  | No  | Permission required for writing data to the ability.<br>**Model restriction**: This API can be used only in the FA model.|
| uri                   | string                                                   | Yes  | No  | URI of the ability.<br>**Model restriction**: This API can be used only in the FA model.|
| deviceTypes           | Array\<string>                                           | Yes  | No  | Device types supported by the ability.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| applicationInfo       | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)     | Yes  | No  | Application information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_APPLICATION** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| metadata              | Array\<[Metadata](js-apis-bundleManager-metadata.md)>           | Yes  | No  | Metadata of the ability. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_METADATA** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| enabled               | boolean                                                  | Yes  | No  | Whether the ability is enabled. The value **true** means that the ability is enabled, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| supportWindowModes    | Array\<[bundleManager.SupportWindowMode](js-apis-bundleManager.md#supportwindowmode)> | Yes  | No  | Window modes supported by the ability.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| windowSize|[WindowSize](#windowsize)                                            |    Yes  | No  | Window size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| excludeFromDock<sup>12+</sup>             | boolean                                                  | Yes  | No  | Whether the ability icon can be hidden in the dock area. The value **true** means that the ability icon can be hidden in the dock area, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| skills<sup>12+</sup>             | Array\<[Skill](js-apis-bundleManager-skill.md)>                                                 | Yes  | No  | Skills of the ability.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  |
| appIndex<sup>12+</sup>    | number    | Yes  | No  | Index of an application clone. It takes effect only for [application clones](../../quick-start/app-clone.md).|
| orientationId<sup>14+</sup>    | number      | Yes  | No  | Resource ID of the ability display mode. If **orientationId** is set to a value other than **0**, the current display mode is customized, and this ID must be used to obtain the corresponding resource from the resource manager module. If **orientationId** is set to **0**, no resource is configured.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## WindowSize

Describes the window size.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name              | Type   | Read-Only| Optional| Description                              |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| maxWindowRatio     | number  | Yes  | No  | Maximum aspect ratio of the window in free window mode. The value ranges from 0 to 1. An example value is 0.12.|
| minWindowRatio     | number  | Yes  | No  | Minimum aspect ratio of the window in free window mode. The value ranges from 0 to 1. An example value is 0.5.|
| maxWindowWidth     | number  | Yes  | No  | Maximum width of the window in free window mode. The unit is vp.|
| minWindowWidth     | number  | Yes  | No  | Minimum width of the window in free window mode. The unit is vp.|
| maxWindowHeight    | number  | Yes  | No  | Maximum height of the window in free window mode. The unit is vp.|
| minWindowHeight    | number  | Yes  | No  | Minimum height of the window in free window mode. The unit is vp.|
