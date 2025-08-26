# BundleResourceInfo (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides resource information of an application, such as the icon and label. The information can be obtained by calling [getBundleResourceInfo](js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
```

## BundleResourceInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**System API**: This is a system API.

| Name                     | Type  | Read-Only| Optional| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| bundleName              | string | Yes  | No  | Bundle name of the application.|
| icon              | string | Yes  | No  | Application icon, which is encoded using Base64. |
| label                     | string | Yes  | No  | Application label.|
| drawableDescriptor<sup>12+</sup>                     | [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor-sys.md) | Yes  | No  | drawableDescriptor object of the application icon.|
| appIndex<sup>12+</sup>           | number | Yes  | No  | Index of an application clone.|
