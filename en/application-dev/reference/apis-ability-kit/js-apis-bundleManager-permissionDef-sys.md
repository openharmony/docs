# PermissionDef (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides permission details defined in the [module.json5](../../quick-start/module-configuration-file.md) file. The information can be obtained using [bundleManager.getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## PermissionDef

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
 
**System API**: This is a system API.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | Yes  | No  | Name of the permission.  |
| grantMode      | number | Yes  | No  | [Grant mode of the permission](../../security/AccessToken/app-permission-mgmt-overview.md#authorization-mode). The value **0** means user authorization, and **1** means system authorization.|
| labelId        | number | Yes  | No  | ID of the permission label.  |
| descriptionId  | number | Yes  | No  | ID of the permission description.  |
