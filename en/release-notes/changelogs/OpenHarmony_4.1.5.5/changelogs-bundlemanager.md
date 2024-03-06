# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Deleted the ApplicationReservedFlag Enum and the applicationReservedFlag field in ApplicationInfo

**Access Level**

Public APIs

**Reason for Change**

The name of **applicationReservedFlag** is too difficult to understand. In addition, the information obtained by this field is never used.

**Change Impact**

This change is a non-compatible change. The **applicationReservedFlag** field in **ApplicationInfo** is designed to store the reserved fields of an application. Currently, it is used to store only the information indicating whether the application is encrypted. After the field is deleted, you cannot obtain the reserved fields of an application through **applicationReservedFlag**.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

| API| Description|
| --------------- | ------- |
| enum ApplicationReservedFlag | This enum is no longer used.|
| readonly applicationReservedFlag: number; | This field is no longer used.|

**Adaptation Guide**

No adaptation is required.


## cl.bundlemanager.2 Deleted the appId and appIdentifier Fields from OH_NativeBundle_ApplicationInfo

**Access Level**

Public APIs

**Reason for Change**

The **appId** and **appIdentifier** fields is deleted from the [OH_NativeBundle_ApplicationInfo](../../../application-dev/reference/native-apis/_o_h___native_bundle_application_info.md) struct.

**Change Impact**

For a native application developed using API version 11 or later, you cannot use [OH_NativeBundle_GetCurrentApplicationInfo](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getcurrentapplicationinfo) to obtain its appId and appIdentifier information.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

An application calls [OH_NativeBundle_GetCurrentApplicationInfo](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getcurrentapplicationinfo) to query its own information.

**Adaptation Guide**

Call [OH_NativeBundle_GetAppId](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getappid) to query the appId information.
Call [OH_NativeBundle_GetAppIdentifier](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getappidentifier) to query the appIdentifier information.

Sample code:

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

        char* appId = OH_NativeBundle_GetAppId();  // new
        // Convert the application ID obtained by calling the native API to the appId attribute in the JavaScript object.
        napi_value napi_appId;
        napi_create_string_utf8(env, appId, NAPI_AUTO_LENGTH, &napi_appId);
        napi_set_named_property(env, result, "appId", napi_appId);

        char* appIdentifier = OH_NativeBundle_GetAppIdentifier();  // new
        // Convert the application identifier obtained by calling the native API to the appIdentifier attribute in the JavaScript object.
        napi_value napi_appIdentifier;
        napi_create_string_utf8(env, appIdentifier, NAPI_AUTO_LENGTH, &napi_appIdentifier);
        napi_set_named_property(env, result, "appIdentifier", napi_appIdentifier);
        // To prevent memory leak, manually release the memory.
        free(nativeApplicationInfo.bundleName);
        free(nativeApplicationInfo.fingerprint);
        free(appId);
        free(appIdentifier);
        return result;
    }
```

## c3.bundlemanager.3 Control Changed for the Installation of Debugging Applications

**Access Level**

Other

**Reason for Change**

Debugging applications can be installed only on a device in developer mode. You can determine whether an application is a debugging one based on the **type** field in the [signing certificate](../../../application-dev/security/app-provision-structure.md).

**Change Impact**

This change is a non-compatible change. If the signing certificate type of an application is **debug** and the device is not in developer mode, the application cannot be installed on the device.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.5.5

**Key API/Component Changes**

N/A

**Adaptation Guide**

You can choose **Settings > General > Developer Mode** to enable or disable the developer mode.
