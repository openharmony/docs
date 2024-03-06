# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Fields appId and appIdentifier Are Added to OH_NativeBundle_ApplicationInfo and Memory Must Be Manually Released

**Access Level**

Public

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

        char* appId = OH_NativeBundle_GetAppId();
        // Convert the application ID obtained by calling the native API to the appId attribute in the JavaScript object.
        napi_value napi_appId;
        napi_create_string_utf8(env, appId, NAPI_AUTO_LENGTH, &napi_appId);
        napi_set_named_property(env, result, "appId", napi_appId);

        char* appIdentifier = OH_NativeBundle_GetAppIdentifier();
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

For details, see [Native Bundle Development](../../../application-dev/napi/native-bundle-guidelines.md).
