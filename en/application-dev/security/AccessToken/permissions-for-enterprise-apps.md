# Permissions for Enterprise Applications

The following permissions are available to <!--Del-->system applications and <!--DelEnd-->enterprise applications. Enterprise applications include normal enterprise apps and Mobile Device Management (MDM) applications.

The distribution type of enterprise applications can be **enterprise_normal** (normal enterprise application) or **enterprise_mdm** (MDM application). You can <!--RP1-->obtain the distribution type from the **app-distribution-type** field in the [HarmonyAppProvision configuration file](../app-provision-structure.md).<!--RP1End-->

For details about how to request the permissions for enterprise applications, see [declaring permissions](declare-permissions.md).

## ohos.permission.SET_FILE_GUARD_POLICY

Allows an application to update the file guard policy.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 10

**Changelog**: For API versions 10 to 14, this permission is of the system_core level and available only to MDM applications. Starting from API version 14, the permission level is changed to system_basic and this permission is accessible to normal enterprise applications.

## ohos.permission.FILE_GUARD_MANAGER

Allows an application to scan media and sandbox and set file extended properties.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 10

**Changelog**: For API versions 10 to 14, this permission is of the system_core level and available only to MDM applications. Starting from API version 14, the permission level is changed to system_basic and this permission is accessible to normal enterprise applications.