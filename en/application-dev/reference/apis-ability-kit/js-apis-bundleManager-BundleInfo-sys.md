# BundleInfo (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module defines the bundle information. Applications can obtain bundle information of a specific application through [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo14), with [bundleFlags](js-apis-bundleManager.md#bundleflag) set to the information to be contained in the returned [BundleInfo](js-apis-bundleManager-bundleInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [BundleInfo](js-apis-bundleManager-bundleInfo.md).

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## DynamicIconInfo

Describes the information about the dynamic icon of an application.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName    | string    | Yes  | No  | Bundle name of the application associated with the dynamic icon.|
| moduleName    | string    | Yes  | No  | Module name of the application associated with the dynamic icon.|
| userId    | number    | Yes  | No  | User ID of the application associated with the dynamic icon.|
| appIndex    | number    | Yes  | No  | Index of the application clone associated with the dynamic icon.|


## BundleOptions

Describes the bundle options used to set or query application information.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name     | Type          | Read-Only| Optional| Description               |
| --------- | -------------- | ---- | ---- | ------------------- |
| userId | number         | No  | Yes  | User ID. By default, the user is the current caller.            |
| appIndex | number         | No  | Yes  | Index of an application clone. The default value is **0**, indicating the main application.   |
