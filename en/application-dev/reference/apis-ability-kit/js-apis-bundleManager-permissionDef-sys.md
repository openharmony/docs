# PermissionDef (System API)

The PermissionDef module provides permission details defined in the configuration file. The information can be obtained using [bundleManager.getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## **PermissionDef**

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
 
**System API**: This is a system API.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | Yes  | No  | Name of the permission.  |
| grantMode      | number | Yes  | No  | [Grant mode of the permission](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-permission-mgmt-overview#authorization-mode). The value **0** means user authorization, and **1** means system authorization.|
| labelId        | number | Yes  | No  | ID of the permission label.  |
| descriptionId  | number | Yes  | No  | ID of the permission description.  |
