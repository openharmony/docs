# PermissionDef

The **PermissionDef** module provides permission details defined in the configuration file. The information can be obtained using [bundleManager.getPermissionDef](js-apis-bundleManager.md).  

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **PermissionDef**

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Type  | Readable| Writable| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | Yes  | No  | Name of the permission.  |
| grantMode      | number | Yes  | No  | Grant mode of the permission.|
| labelId        | number | Yes  | No  | Label ID of the permission.  |
| descriptionId  | number | Yes  | No  | Description ID of the permission.  |
