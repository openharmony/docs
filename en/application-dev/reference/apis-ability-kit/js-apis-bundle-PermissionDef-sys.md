# PermissionDef (System API)

The module provides permission details defined in the configuration file.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module are deprecated since API version 9. You are advised to use [bundleManager-PermissionDef](js-apis-bundleManager-permissionDef-sys.md) instead.
>
> The APIs provided by this module are system APIs.

## **PermissionDef**<sup>(deprecated)<sup>

This API is deprecated since API version 9. You are advised to use [bundleManager-PermissionDef](js-apis-bundleManager-permissionDef-sys.md#permissiondef) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | No  | No  | Name of the permission.  |
| grantMode      | number | No  | No  | Grant mode of the permission. The value **0** means that the system automatically grants the permission after the application installation, and **1** means that the application needs to dynamically request the permission from the user.|
| labelId        | number | No  | No  | ID of the permission label.  |
| descriptionId  | number | No  | No  | ID of the permission description.  |
