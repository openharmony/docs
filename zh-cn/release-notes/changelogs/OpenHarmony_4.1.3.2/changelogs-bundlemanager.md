# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理NDK结构体OH_NativeBundle_ApplicationInfo新增appId和appIdentifier字段，需手动释放。

**访问级别**

公开接口

**变更原因**

结构体[OH_NativeBundle_ApplicationInfo](../../../application-dev/reference/native-apis/_o_h___native_bundle_application_info.md)新增appId和appIdentifier字段。

**变更影响**

如果使用API 11及以上的开发的Native应用，如果不手动释放结构体OH_NativeBundle_ApplicationInfo中的appId和appIdentifier字段，会造成内存泄漏。如果使用API 11之前的开发的native应用，则无需适配。

**变更发生版本**

从OpenHarmony SDK 4.1.3.2开始

**变更的接口/组件**

应用调用包管理NDK接口[OH_NativeBundle_GetCurrentApplicationInfo](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getcurrentapplicationinfo)查询应用自身信息。

**适配指导**

应用若是使用API 11及以上的版本开发的Native应用，则需要在代码里手动释放appId和appIdentifier申请的内存。

示例代码

 ```c++
    static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info)
    {
        // 调用Native接口获取应用信息
        OH_NativeBundle_ApplicationInfo nativeApplicationInfo = OH_NativeBundle_GetCurrentApplicationInfo();
        napi_value result = nullptr;
        napi_create_object(env, &result);
        // Native接口获取的应用包名转为js对象里的bundleName属性
        napi_value bundleName;
        napi_create_string_utf8(env, nativeApplicationInfo.bundleName, NAPI_AUTO_LENGTH, &bundleName);
        napi_set_named_property(env, result, "bundleName", bundleName);
        // Native接口获取的指纹信息转为js对象里的fingerprint属性
        napi_value fingerprint;
        napi_create_string_utf8(env, nativeApplicationInfo.fingerprint, NAPI_AUTO_LENGTH, &fingerprint);
        napi_set_named_property(env, result, "fingerprint", fingerprint);

        char* appId = OH_NativeBundle_GetAppId();
        // Native接口获取的appId转为js对象里的appId属性
        napi_value napi_appId;
        napi_create_string_utf8(env, appId, NAPI_AUTO_LENGTH, &napi_appId);
        napi_set_named_property(env, result, "appId", napi_appId);

        char* appIdentifier = OH_NativeBundle_GetAppIdentifier();
        // Native接口获取的appIdentifier转为js对象里的appIdentifier属性
        napi_value napi_appIdentifier;
        napi_create_string_utf8(env, appIdentifier, NAPI_AUTO_LENGTH, &napi_appIdentifier);
        napi_set_named_property(env, result, "appIdentifier", napi_appIdentifier);
        // 最后为了防止内存泄漏，手动释放
        free(nativeApplicationInfo.bundleName);
        free(nativeApplicationInfo.fingerprint);
        free(appId);
        free(appIdentifier);
        return result;
    }
```

详细开发指导可参考包[管理NDK开发指导](../../../application-dev/napi/native-bundle-guidelines.md)。