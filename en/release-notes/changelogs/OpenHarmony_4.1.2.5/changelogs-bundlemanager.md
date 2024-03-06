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
