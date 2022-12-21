# PermissionDef

The **PermissionDef** module provides permission details defined in the configuration file.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **PermissionDef**<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-PermissionDef](js-apis-bundleManager-permissionDef.md) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Type  | Readable| Writable| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | Yes  | No  | Name of the permission.  |
| grantMode      | number | Yes  | No  | Grant mode of the permission. The value **0** means that the system automatically grants the permission after the application installation, and **1** means that the application needs to dynamically request the permission from the user.|
| labelId        | number | Yes  | No  | Label ID of the permission.  |
| descriptionId  | number | Yes  | No  | Description ID of the permission.  |
