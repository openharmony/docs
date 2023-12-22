# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Logic Used for Judging System Applications Changed

The **app-feature** field in the [signing certificate](../../../application-dev/security/app-provision-structure.md) is used to determine whether an application is a system application.
* If **app-feature** is **hos_system_app**, the application is a system application.
* If **app-feature** is not **hos_normal_app**, the application is a third-party application.

**Change Impact**

If an application is located in **/system/app**, the path is configured in the **/****/etc/app/install_list.json** file, but **app-feature** is **hos_normal_app**, then the application cannot use system APIs.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Check whether your application is a system application. If yes, change **app-feature** to **hos_system_app** and re-sign the HAP file.


## c2.bundlemanager.2 Added the dataUnclearable Field to the ApplicationInfo Struct

The **dataUnclearable** field is added to the [ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) struct. For details, see [API reference](../../../application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md).

**Change Impact**

N/A

**Key API/Component Changes**

The **dataUnclearable** field is added to the [ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) struct. For details, see [API reference](../../../application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md).

**Adaptation Guide**

N/A

## c3.bundlemanager.3 Restricted the Installation of Debugging Applications

**Access Level**

Others

**Reason for Change**

Debugging applications can be installed on a device in debugging mode. You can determine whether an application is a debugging one based on the **type** field in the [signing certificate](../../../application-dev/security/app-provision-structure.md).

**Change Impact**

If the signing certificate type of an application is **debug** and the device is in non-debug mode, the application cannot be installed on the device.

**Change Since**

OpenHarmony SDK 4.1.2.5

**Key API/Component Changes**

N/A

**Adaptation Guide**

To install an application on a device in non-debugging mode, use a certificate of the **release** type to sign the application during build.
