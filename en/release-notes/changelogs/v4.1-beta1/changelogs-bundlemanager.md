# Bundle Manager Subsystem Changelog
## cl.bundlemanager.1 Field metadata in the ApplicationInfo struct Deprecated

The **metadata** field is deprecated since API version 10. You are advised to use **metadataArray** instead.

**Change Impact**<br>
The **metadata** field in the **ApplicationInfo** struct is no longer maintained since API version 10.

**Key API/Component Changes**<br>
The **metadata** field in the **ApplicationInfo** struct is deprecated since API version 10.

**Adaptation Guide**<br>
Use the **metadataArray** field to replace the **metadata** field.

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));
            hilog.info(0x0000, 'testTag', 'metadataArray is: %{public}s', JSON.stringify(data.metadataArray));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);
}
```
## cl.bundlemanager.1 Schema Validation in modulecheck and configcheck Changed

In the schema validation files **app.json**, **module.json**, **configSchema_lite.json**, and **configSchema_rich.json**, the maximum number of characters allowed for **bundleName** is changed from 127 to 128.

**Change Impact**<br>
Before the change, the maximum length allowed for **bundleName** is 127 characters. When the length of **bundleName** is greater than or equal to 128 characters, DevEco Studio cannot build or pack the project, and reports the error message "Schema validate failed."

After the change, the maximum length allowed for **bundleName** is 128 characters. When **bundleName** is set to 128 characters, DevEco Studio can build and pack the project. When the length of **bundleName** is greater than 128 characters, DevEco Studio cannot build or pack the project, and reports the error message "Schema validate failed."

**Key API/Component Changes**<br>
No API or component change is involved.

**Adaptation Guide**<br>
No adaptation is required. You only need to upgrade the SDK in use.

## cl.bundlemanager.1 Maximum Length Allowed for bundleName in the Application Installation Package Changed to 128 Characters

During application installation, the bundle manager subsystem verifies the length of **bundleName** in the installation package. The maximum length allowed is changed from 127 characters to 128 characters.

**Change Impact**<br>
Before the change, the maximum length allowed for **bundleName** in the installation package is 127 characters. If the length of **bundleName** is greater than or equal to 128 characters, the system reports an error and the application cannot be installed.

After the change, the maximum length allowed for **bundleName** in the installation package is 128 characters. If the length of **bundleName** is 128 characters, the application can be installed. If the length is greater than 128 characters, the system reports an error and the application cannot be installed.

**Key API/Component Changes**<br>
No API or component change is involved.

**Adaptation Guide**<br>
No adaptation is required.

## cl.bundlemanager.1 Logic Used for Judging System Applications Changed

The **app-feature** field in the [signing certificate](../../../application-dev/security/app-provision-structure.md) is used to determine whether an application is a system application.
* If **app-feature** is **hos_system_app**, the application is a system application.
* If **app-feature** is not **hos_normal_app**, the application is a third-party application.

**Change Impact**<br>
If an application is located in **/system/app**, the path is configured in the **/****/etc/app/install_list.json** file, but **app-feature** is **hos_normal_app**, then the application cannot use system APIs.

**Key API/Component Changes**<br>
No API or component change is involved.

**Adaptation Guide**<br>
Check whether your application is a system application. If yes, change **app-feature** to **hos_system_app** and re-sign the HAP file.


## c2.bundlemanager.2 Added the dataUnclearable Field to the ApplicationInfo Struct

The **dataUnclearable** field is added to the [ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) struct. For details, see [API reference](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md).

**Change Impact**<br>
There is no impact.

**Key API/Component Changes**<br>
The **dataUnclearable** field is added to the [ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts) struct. For details, see [API reference](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md).

**Adaptation Guide**<br>
No adaptation is required.

## c3.bundlemanager.3 Restricted the Installation of Debugging Applications

**Access Level**

Others

**Reason for Change**

Debugging applications can be installed on a device in debugging mode. You can determine whether an application is a debugging one based on the **type** field in the [signing certificate](../../../application-dev/security/app-provision-structure.md).

**Change Impact**

If the signing certificate type of an application is **debug** and the device is in non-debug mode, the application cannot be installed on the device.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.2.5

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

To install an application on a device in non-debugging mode, use a certificate of the **release** type to sign the application during build.

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

## cl.bundlemanager.1 Fields appId and appIdentifier Are Added to OH_NativeBundle_ApplicationInfo and Memory Must Be Manually Released

**Access Level**

Public APIs

**Reason for Change**

The **appId** and **appIdentifier** fields are added to the [OH_NativeBundle_ApplicationInfo](../../../application-dev/reference/native-apis/_o_h___native_bundle_application_info.md) struct.

**Change Impact**

For a native application developed using API version 11 or later, you must manually release the memory allocated for the **appId** and **appIdentifier** fields in the **OH_NativeBundle_ApplicationInfo** struct; otherwise, memory leak occurs. If the native application is developed using APIs earlier than API version 11, no adaptation is required.

**Change Since**

OpenHarmony SDK 4.1.3.2

**Key API/Component Changes**

An application calls [OH_NativeBundle_GetCurrentApplicationInfo](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getcurrentapplicationinfo) to query its own information.

**Adaptation Guide**

If your application is a native application developed using API version 11 or later, manually release the memory allocated for **appId** and **appIdentifier**.

Sample Code

 ```c++
    static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info)
    {
        // Call the native API to obtain the application information.
        OH_NativeBundle_ApplicationInfo nativeApplicationInfo = OH_NativeBundle_GetCurrentApplicationInfo();
        napi_value result = nullptr;
        napi_create_object(env, &result);
        // Convert the bundle name obtained by calling the native API to the bundleName attribute in the JavaScript object.
        napi_value bundleName;
        napi_create_string_utf8(env, nativeApplicationInfo.bundleName, NAPI_AUTO_LENGTH, &bundleName);
        napi_set_named_property(env, result, "bundleName", bundleName);
        // Convert the fingerprint information obtained by calling the native API to the fingerprint attribute in the JavaScript object.
        napi_value fingerprint;
        napi_create_string_utf8(env, nativeApplicationInfo.fingerprint, NAPI_AUTO_LENGTH, &fingerprint);
        napi_set_named_property(env, result, "fingerprint", fingerprint);
        // Convert the application ID obtained by calling the native API to the appId attribute in the JavaScript object.
        napi_value appId;
        napi_create_string_utf8(env, nativeApplicationInfo.appId, NAPI_AUTO_LENGTH, &appId);
        napi_set_named_property(env, result, "appId", appId);
        // Convert the application identifier obtained by calling the native API to the appIdentifier attribute in the JavaScript object.
        napi_value appIdentifier;
        napi_create_string_utf8(env, nativeApplicationInfo.appIdentifier, NAPI_AUTO_LENGTH, &appIdentifier);
        napi_set_named_property(env, result, "appIdentifier", appIdentifier);
        // To prevent memory leak, manually release the memory.
        free(nativeApplicationInfo.bundleName);
        free(nativeApplicationInfo.fingerprint);
        free(nativeApplicationInfo.appId);  // new
        free(nativeApplicationInfo.appIdentifier);  // new
        return result;
    }
```

For details, see [Native Bundle Development](../../../application-dev/napi/native-bundle-guidelines.md).

## cl.bundlemanager.1 Deprecated the verifyCodeParams Field in VerifyCodeParam and InstallParam

**Access Level**

System APIs

**Reason for Change**

The code signature file of an application is integrated into the installation package, rather than being specified by using the **verifyCodeParams** Field.

**Change Impact**

The **verifyCodeParams** field in **VerifyCodeParam** and **InstallParam** of the [installer](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-installer.md) module is deprecated. This field is no longer required.

**Deprecated Since**

OpenHarmony SDK 4.1.3.3

**Deprecated APIs/Components**

| API| Description|
| --------------- | ------- |
| interface VerifyCodeParam | No longer required to specify the code signature file of the installation package.|
| verifyCodeParams?: Array<VerifyCodeParam>; | No longer required to specify the code signature file of the installation package.|

**Adaptation Guide**

When calling the APIs provided by the **installer** module, you do not need to specify the code signature file of the installation package, because it is integrated into the installation package.

## cl.bundlemanager.1 Uncompressed Mode Adopted for libs During Packing

**Access Level**

Others

**Reason for Change**

By default, the packing tool packs **libs** in compressed mode. This operation decreases the size of the installation package while increasing the packing time. However, developers are more sensitive to the packing time in the development and debugging phase. As such, the packing tool is changed to pack **libs** in uncompressed mode by default.

**Change Impact**

This change is a compatible change. It affects the compressed mode of **libs** during packing.

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

Before the change, the packing tool packs **libs** in compressed mode by default.

After the change, the packing tool packs **libs** in uncompressed mode by default.

**Adaptation Guide**

By default, the packing tool packs **libs** in uncompressed mode. To pack **libs** in compressed mode, set **compressNativeLibs** in the [module.json5 file](../../../application-dev/quick-start/module-configuration-file.md) to **true**.

<!--no_check-->