# Metadata
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module defines a metadata object. An application can obtain the metadata through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with **GET_BUNDLE_INFO_WITH_METADATA** passed in for [bundleFlags](js-apis-bundleManager.md#bundleflag). This object is contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md), [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md), [AbilityInfo](js-apis-bundleManager-abilityInfo.md), and [ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md).

The module provides the configuration about the module, UIAbility, and ExtensionAbility. The value is of the array type. The configuration is valid only for the current module, UIAbility, or ExtensionAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## Metadata

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
| Name    | Type  | Read-Only| Optional| Description      |
| -------- | ------ | ---- | ---- | ---------- |
| name     | string | No  | No  | Metadata name.|
| value    | string | No  | No  | Metadata value.  |
| resource | string | No  | No  | Metadata resource descriptor. For details, see **$profile:config_file**, which indicates the **config_file.json** file configured in the **profile** directory.|
| valueId<sup>18+</sup>  | number | Yes  | Yes  | ID of the metadata value. If **valueId** is not set to **0**, the current metadata value is customized, and **valueId** must be used to obtain the corresponding value from the resource manager module. If **valueId** is set to **0**, the current metadata value is a fixed string.|
