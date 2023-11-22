# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Non-MDM Applications Granted with the MDM Permission Cannot Be Installed

The **app-distribution-type** field in the [signing certificate](../../../application-dev/security/app-provision-structure.md) is used to determine whether an application is an MDM application.
* If **app-distribution-type** is **enterprise_mdm**, the application is an MDM application.
* If **app-distribution-type** is not **enterprise_mdm**, the application is a non-MDM application.
  

The **availableType** attribute in the **definePermissions** field in the [config.jso file](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json) is used to determine whether the MDM permission is granted.
* If **availableType** is **MDM**, the MDM permission is granted.
* If **availableType** is not **MDM**, the MDM permission is not granted.

**Change Impact**

If a non-MDM application is granted with the MDM permission, the application cannot be installed.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Check whether your application is an MDM application. If not, do not request the MDM permission.