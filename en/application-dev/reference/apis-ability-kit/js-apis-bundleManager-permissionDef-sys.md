# PermissionDef (System API)

The **PermissionDef** module provides permission details defined in the configuration file. The information can be obtained using [bundleManager.getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## **PermissionDef**

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | Yes  | No  | Name of the permission.  |
| grantMode      | number | Yes  | No  | Grant mode of the permission.|
| labelId        | number | Yes  | No  | ID of the permission label.  |
| descriptionId  | number | Yes  | No  | ID of the permission description.  |
