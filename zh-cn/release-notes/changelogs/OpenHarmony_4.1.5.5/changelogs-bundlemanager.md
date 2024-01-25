# 包管理子系统变更说明

## cl.bundlemanager.1 ApplicationReservedFlag枚举和ApplicationInfo中的applicationReservedFlag字段删除

**访问级别**

公开接口

**删除原因**

applicationReservedFlag命名过于复杂，不易理解，且当前存储信息没有使用方，可以删除。

**删除影响**

该变更为非兼容性变更。ApplicationInfo中的applicationReservedFlag原本用于存储应用的保留字段，当前仅存储应用是否加密的信息。废弃后，无法再通过applicationReservedFlag获取应用的保留信息。

**API Level**

11

**删除发生版本**

从OpenHarmony SDK 4.1.5.5开始

**删除的接口/组件**

| 接口声明 | 删除说明 |
| --------------- | ------- |
| enum ApplicationReservedFlag | 不再需要该枚举来获取相应信息。 |
| readonly applicationReservedFlag: number; | 命名过于复杂，不易理解，当前存储信息没有使用方。 |

**适配指导**

当前该接口没有使用方，applicationReservedFlag中存储的应用加密信息，应用无需感知。


## cl.bundlemanager.2 包管理NDK结构体OH_NativeBundle_ApplicationInfo删除appId和appIdentifier字段。

**访问级别**

公开接口

**删除原因**

结构体[OH_NativeBundle_ApplicationInfo](../../../application-dev/reference/native-apis/_o_h___native_bundle_application_info.md)删除appId和appIdentifier字段。

**删除影响**

如果使用API 11及以上的开发的Native应用，使用包管理查询接口[OH_NativeBundle_GetCurrentApplicationInfo](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getcurrentapplicationinfo)不再能查询appId和appIdentifier信息。

**API Level**

11

**删除发生版本**

从OpenHarmony SDK 4.1.5.5开始

**删除的接口/组件**

应用调用包管理NDK接口[OH_NativeBundle_GetCurrentApplicationInfo](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getcurrentapplicationinfo)查询应用自身信息。

**适配指导**

调用包管理接口[OH_NativeBundle_GetAppId](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getappid)查询appId信息。
调用包管理接口[OH_NativeBundle_GetAppIdentifier](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getappidentifier)查询appIdentifier信息。

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

        char* appId = OH_NativeBundle_GetAppId();  // new
        // Native接口获取的appId转为js对象里的appId属性
        napi_value napi_appId;
        napi_create_string_utf8(env, appId, NAPI_AUTO_LENGTH, &napi_appId);
        napi_set_named_property(env, result, "appId", napi_appId);

        char* appIdentifier = OH_NativeBundle_GetAppIdentifier();  // new
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

## c3.bundlemanager.3 调试应用安装管控变更

**访问级别**

其他

**变更原因**

当前对调试应用安装做了管控，无法在非开发者模式下安装调试应用，可以由[签名证书](../../../application-dev/security/app-provision-structure.md)中的type字段来判断是否为调试应用。

**变更影响**

该变更为非兼容性变更。如果应用的签名证书类型为debug，且设备处于非开发者模式，会导致无法安装。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始

**变更的接口/组件**

不涉及接口及组件变更。

**适配指导**

可通过设置中的“通用-开发者模式”来打开或者关闭开发者模式。
