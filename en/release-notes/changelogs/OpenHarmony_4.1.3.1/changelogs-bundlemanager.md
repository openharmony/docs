# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Non-MDM Applications Granted with the MDM Permission Cannot Be Installed

**Access Level**

System APIs

**Reason for Change**

The MDM permission can be granted only to MDM applications.

**Change Impact**

Non-MDM applications granted with the MDM permission cannot be installed.

The **app-distribution-type** field in the [signing certificate](../../../application-dev/security/app-provision-structure.md) is used to determine whether an application is an MDM application.
* If **app-distribution-type** is **enterprise_mdm**, the application is an MDM application.
* If **app-distribution-type** is not **enterprise_mdm**, the application is a non-MDM application.

The **availableType** attribute in the **definePermissions** field in the [config.jso file](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json) is used to determine whether the MDM permission is granted.
* If **availableType** is **MDM**, the MDM permission is granted.
* If **availableType** is not **MDM**, the MDM permission is not granted.

**Change Since**

OpenHarmony SDK 4.1.3.1

**Key API/Component Changes**

To grant the permission to an application, declare the permission in the [module.json5 file](../../../application-dev/quick-start/module-structure.md#internal-structure-of-the-reqpermissions-attribute) if the application is developed based on the stage model or in the [config.json file](../../../application-dev/quick-start/module-configuration-file.md#requestpermissions) if the application is developed based on the FA model. Non-MDM applications cannot apply for the MDM permission.

**Adaptation Guide**

Check whether your application is an MDM application. If not, do not request the MDM permission.
