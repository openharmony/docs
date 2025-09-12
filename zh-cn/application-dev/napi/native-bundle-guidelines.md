# NativeBundle开发指导
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## 场景介绍

开发者可以通过本指导了解在OpenHarmony应用中，如何使用Native Bundle接口获取应用自身相关信息。

## 接口说明

| 接口名                                                       | 描述                                     |
| :----------------------------------------------------------- | :--------------------------------------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getcurrentapplicationinfo) | 获取应用自身相关信息。          |
| [OH_NativeBundle_GetAppId](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getappid) | 获取自身应用的appId信息。 |
| [OH_NativeBundle_GetAppIdentifier](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getappidentifier) | 获取自身应用的appIdentifier信息。 |
| [OH_NativeBundle_GetMainElementName](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getmainelementname) | 获取自身应用入口的信息。 |
| [OH_NativeBundle_GetCompatibleDeviceType](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getcompatibledevicetype) | 获取自身应用适用的设备类型。 |
| [OH_NativeBundle_IsDebugMode](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_isdebugmode) | 查询当前应用的调试模式。|
| [OH_NativeBundle_GetModuleMetadata](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getmodulemetadata) | 获取当前应用的元数据信息。 |
| [OH_NativeBundle_GetAbilityResourceInfo](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getabilityresourceinfo) | 获取支持打开特定文件类型的组件资源信息列表。从API version 21开始支持。 |


## 开发步骤

**1. 创建工程**

![native](figures/rawfile1.png)


**2. 添加依赖**

创建完成后，DevEco Studio会在工程生成cpp目录，目录有types/libentry/index.d.ts、napi_init.cpp、CMakeLists.txt等文件。

1. 打开src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加包管理的libbundle_ndk.z.so。

    ```c++
    target_link_libraries(entry PUBLIC libace_napi.z.so libbundle_ndk.z.so)
    ```

2. 打开src/main/cpp/napi_init.cpp文件，添加头文件。

    ```c++
    //napi依赖头文件
    #include "napi/native_api.h"
    //NDK接口依赖头文件
    #include "bundle/ability_resource_info.h"
    #include "bundle/native_interface_bundle.h"
    //free()函数依赖的基础库
    #include <cstdlib>
    ```

**3. 修改源文件**

1. 打开src/main/cpp/napi_init.cpp文件，文件Init会对当前方法进行初始化映射，这里定义对外的接口。

    ```c++
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "getCurrentApplicationInfo", nullptr, GetCurrentApplicationInfo, nullptr, nullptr, nullptr, napi_default, nullptr},   // 新增方法 getCurrentApplicationInfo
            { "getAppId", nullptr, GetAppId, nullptr, nullptr, nullptr, napi_default, nullptr},                                     // 新增方法 getAppId
            { "getAppIdentifier", nullptr, GetAppIdentifier, nullptr, nullptr, nullptr, napi_default, nullptr},                     // 新增方法 getAppIdentifier
            { "getMainElementName", nullptr, GetMainElementName, nullptr, nullptr, nullptr, napi_default, nullptr},                 // 新增方法 getMainElementName
            { "getCompatibleDeviceType", nullptr, GetCompatibleDeviceType, nullptr, nullptr, nullptr, napi_default, nullptr},       // 新增方法 getCompatibleDeviceType
            { "isDebugMode", nullptr, IsDebugMode, nullptr, nullptr, nullptr, napi_default, nullptr},                               // 新增方法 isDebugMode
            { "getModuleMetadata", nullptr, GetModuleMetadata, nullptr, nullptr, nullptr, napi_default, nullptr},                   // 新增方法 getModuleMetadata
            { "getAbilityResourceInfo", nullptr, GetAbilityResourceInfo, nullptr, nullptr, nullptr, napi_default, nullptr}          // 新增方法 getAbilityResourceInfo
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    ```

2. 在src/main/cpp/napi_init.cpp文件中，增加对应的方法，如下所示：

    ```c++
    static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info);
    static napi_value GetAppId(napi_env env, napi_callback_info info);
    static napi_value GetAppIdentifier(napi_env env, napi_callback_info info);
    static napi_value GetMainElementName(napi_env env, napi_callback_info info);
    static napi_value GetCompatibleDeviceType(napi_env env, napi_callback_info info);
    static napi_value IsDebugMode(napi_env env, napi_callback_info info);
    static napi_value GetModuleMetadata(napi_env env, napi_callback_info info);
    static napi_value GetAbilityResourceInfo(napi_env env, napi_callback_info info);
3. 在src/main/cpp/napi_init.cpp文件中获取Native的包信息对象，并转为js的包信息对象，即可在js侧获取应用的信息：

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
    
        // 最后为了防止内存泄漏，手动释放
        free(nativeApplicationInfo.bundleName);
        free(nativeApplicationInfo.fingerprint);
        return result;
    }
    
    static napi_value GetAppId(napi_env env, napi_callback_info info)
    {
        // 调用Native接口获取应用appId
        char* appId = OH_NativeBundle_GetAppId();
        // Native接口转成nAppId返回
        napi_value nAppId;
        napi_create_string_utf8(env, appId, NAPI_AUTO_LENGTH, &nAppId);
        // 最后为了防止内存泄漏，手动释放
        free(appId);
        return nAppId;
    }
    
    static napi_value GetAppIdentifier(napi_env env, napi_callback_info info)
    {
        // 调用Native接口获取应用appIdentifier
        char* appIdentifier = OH_NativeBundle_GetAppIdentifier();
        // Native接口转成nAppIdentifier返回
        napi_value nAppIdentifier;
        napi_create_string_utf8(env, appIdentifier, NAPI_AUTO_LENGTH, &nAppIdentifier);
        // 最后为了防止内存泄漏，手动释放
        free(appIdentifier);
        return nAppIdentifier;
    }
    
    static napi_value GetMainElementName(napi_env env, napi_callback_info info)
    {
        // 调用Native接口获取应用入口的信息
        OH_NativeBundle_ElementName elementName = OH_NativeBundle_GetMainElementName();
        napi_value result = nullptr;
        napi_create_object(env, &result);
        // Native接口获取的应用包名转为js对象里的bundleName属性
        napi_value bundleName;
        napi_create_string_utf8(env, elementName.bundleName, NAPI_AUTO_LENGTH, &bundleName);
        napi_set_named_property(env, result, "bundleName", bundleName);
        // Native接口获取的模块名称转为js对象里的moduleName属性
        napi_value moduleName;
        napi_create_string_utf8(env, elementName.moduleName, NAPI_AUTO_LENGTH, &moduleName);
        napi_set_named_property(env, result, "moduleName", moduleName);
        // Native接口获取的ability名称转为js对象里的abilityName属性
        napi_value abilityName;
        napi_create_string_utf8(env, elementName.abilityName, NAPI_AUTO_LENGTH, &abilityName);
        napi_set_named_property(env, result, "abilityName", abilityName);
        // 最后为了防止内存泄漏，手动释放
        free(elementName.bundleName);
        free(elementName.moduleName);
        free(elementName.abilityName);
        return result;
    }
    
    static napi_value GetCompatibleDeviceType(napi_env env, napi_callback_info info)
    {
        // 调用Native接口获取应用deviceType
        char* deviceType = OH_NativeBundle_GetCompatibleDeviceType();
        // Native接口转成nDeviceType返回
        napi_value nDeviceType;
        napi_create_string_utf8(env, deviceType, NAPI_AUTO_LENGTH, &nDeviceType);
        // 最后为了防止内存泄漏，手动释放
        free(deviceType);
        return nDeviceType;
    }
    
    static napi_value IsDebugMode(napi_env env, napi_callback_info info)
    {
        bool isDebug = false;
        // 调用Native接口获取应用DebugMode的信息
        bool isSuccess = OH_NativeBundle_IsDebugMode(&isDebug);
        // 调用Native接口失败抛出异常
        if (isSuccess == false) {
            napi_throw_error(env, nullptr, "call failed");
            return nullptr;
        }
        // Native接口转成debug返回
        napi_value debug;
        napi_get_boolean(env, isDebug, &debug);
        return debug;
    }
    
    static napi_value GetModuleMetadata(napi_env env, napi_callback_info info)
    {
        size_t moduleCount = 0;
        // 调用Native接口获取应用元数据的信息
        OH_NativeBundle_ModuleMetadata* modules = OH_NativeBundle_GetModuleMetadata(&moduleCount);
        if (modules == nullptr || moduleCount == 0) {
            napi_throw_error(env, nullptr, "no metadata found");
            return nullptr;
        }
    
        napi_value result;
        napi_create_array(env, &result);
    
        for (size_t i = 0; i < moduleCount; i++) {
            napi_value moduleObj;
            napi_create_object(env, &moduleObj);
    
            // Native接口获取的模块名转为js对象里的moduleName属性
            napi_value moduleName;
            napi_create_string_utf8(env, modules[i].moduleName, NAPI_AUTO_LENGTH, &moduleName);
            napi_set_named_property(env, moduleObj, "moduleName", moduleName);
    
            napi_value metadataArray;
            napi_create_array(env, &metadataArray);
    
            for (size_t j = 0; j < modules[i].metadataArraySize; j++) {
                napi_value metadataObj;
                napi_create_object(env, &metadataObj);
    
                napi_value name;
                napi_value value;
                napi_value resource;
    
                napi_create_string_utf8(env, modules[i].metadataArray[j].name, NAPI_AUTO_LENGTH, &name);
                napi_create_string_utf8(env, modules[i].metadataArray[j].value, NAPI_AUTO_LENGTH, &value);
                napi_create_string_utf8(env, modules[i].metadataArray[j].resource, NAPI_AUTO_LENGTH, &resource);
    
                // Native接口获取的元数据名称转为js对象里的name属性
                napi_set_named_property(env, metadataObj, "name", name);
                // Native接口获取的元数据值名称转为js对象里的value属性
                napi_set_named_property(env, metadataObj, "value", value);
                // Native接口获取的元数据资源转为js对象里的resource属性
                napi_set_named_property(env, metadataObj, "resource", resource);
    
                napi_set_element(env, metadataArray, j, metadataObj);
            }
    
            napi_set_named_property(env, moduleObj, "metadata", metadataArray);
            napi_set_element(env, result, i, moduleObj);
        }
    
        // 最后为了防止内存泄漏，手动释放
        for (size_t i = 0; i < moduleCount; i++) {
            free(modules[i].moduleName);
            for (size_t j = 0; j < modules[i].metadataArraySize; j++) {
                free(modules[i].metadataArray[j].name);
                free(modules[i].metadataArray[j].value);
                free(modules[i].metadataArray[j].resource);
            }
            free(modules[i].metadataArray);
        }
        free(modules);
        return result;
    }

    static napi_value GetAbilityResourceInfo(napi_env env, napi_callback_info info) {
        size_t argc = 1;
        napi_value args[1];
        napi_status status;

        // 获取传入的参数
        status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
        if (status != napi_ok || argc < 1) {
            napi_throw_error(env, nullptr, "Invalid arguments. Expected fileType string.");
            return nullptr;
        }

        // 检查参数类型是否为字符串
        napi_valuetype valuetype;
        status = napi_typeof(env, args[0], &valuetype);
        if (status != napi_ok || valuetype != napi_string) {
            napi_throw_error(env, nullptr, "Argument must be a string");
            return nullptr;
        }

        // 获取字符串参数
        char fileType[256] = {0}; // 假设文件类型不会超过255个字符
        size_t str_len;
        status = napi_get_value_string_utf8(env, args[0], fileType, sizeof(fileType) - 1, &str_len);
        if (status != napi_ok) {
            napi_throw_error(env, nullptr, "Failed to get fileType string");
            return nullptr;
        }

        size_t infosCount = 0;
        OH_NativeBundle_AbilityResourceInfo *infos = nullptr;

        // 调用Native接口获取组件资源信息，使用传入的fileType
        BundleManager_ErrorCode ret = OH_NativeBundle_GetAbilityResourceInfo(fileType, &infos, &infosCount);

        if (ret == BUNDLE_MANAGER_ERROR_CODE_PERMISSION_DENIED) {
            napi_throw_error(env, nullptr, "BUNDLE_MANAGER_ERROR_CODE_PERMISSION_DENIED");
            return nullptr;
        }

        if (infos == nullptr || infosCount == 0) {
            napi_throw_error(env, nullptr, "no metadata found");
            return nullptr;
        }

        napi_value result;
        napi_create_array(env, &result);

        for (size_t i = 0; i < infosCount; i++) {

            auto temp = (OH_NativeBundle_AbilityResourceInfo *)((char *)infos + OH_NativeBundle_GetSize() * i);

            napi_value infoObj;
            napi_create_object(env, &infoObj);

            // 1. 添加Default App
            bool IsDefaultApp = true;
            OH_NativeBundle_CheckDefaultApp(temp, &IsDefaultApp);
            napi_value defaultAppValue;
            napi_get_boolean(env, IsDefaultApp, &defaultAppValue);
            napi_set_named_property(env, infoObj, "IsDefaultApp", defaultAppValue);

            // 2. 添加App Index
            int appIndex = -1;
            OH_NativeBundle_GetAppIndex(temp, &appIndex);
            napi_value appIndexValue;
            napi_create_int32(env, appIndex, &appIndexValue);
            napi_set_named_property(env, infoObj, "appIndex", appIndexValue);

            // 3. 添加Label
            char *label = nullptr;
            OH_NativeBundle_GetLabel(temp, &label);
            napi_value labelValue;
            if (label) {
                napi_create_string_utf8(env, label, NAPI_AUTO_LENGTH, &labelValue);
                free(label);
            } else {
                napi_get_null(env, &labelValue);
            }
            napi_set_named_property(env, infoObj, "label", labelValue);

            // 4. 添加Bundle Name
            char *bundleName = nullptr;
            OH_NativeBundle_GetBundleName(temp, &bundleName);
            napi_value bundleNameValue;
            if (bundleName) {
                napi_create_string_utf8(env, bundleName, NAPI_AUTO_LENGTH, &bundleNameValue);
                free(bundleName);
            } else {
                napi_get_null(env, &bundleNameValue);
            }
            napi_set_named_property(env, infoObj, "bundleName", bundleNameValue);

            // 5. 添加Module Name
            char *moduleName = nullptr;
            OH_NativeBundle_GetModuleName(temp, &moduleName);
            napi_value moduleNameValue;
            if (moduleName) {
                napi_create_string_utf8(env, moduleName, NAPI_AUTO_LENGTH, &moduleNameValue);
                free(moduleName);
            } else {
                napi_get_null(env, &moduleNameValue);
            }
            napi_set_named_property(env, infoObj, "moduleName", moduleNameValue);

            // 6. 添加Ability Name
            char *abilityName = nullptr;
            OH_NativeBundle_GetAbilityName(temp, &abilityName);
            napi_value abilityNameValue;
            if (abilityName) {
                napi_create_string_utf8(env, abilityName, NAPI_AUTO_LENGTH, &abilityNameValue);
                free(abilityName);
            } else {
                napi_get_null(env, &abilityNameValue);
            }
            napi_set_named_property(env, infoObj, "abilityName", abilityNameValue);

            // 7. 添加Icon
            char *icon = nullptr;
            OH_NativeBundle_GetIcon(temp, &icon);
            napi_value iconValue;
            if (icon) {
                napi_create_string_utf8(env, icon, NAPI_AUTO_LENGTH, &iconValue);
                free(icon);
            } else {
                napi_get_null(env, &iconValue);
            }
            napi_set_named_property(env, infoObj, "icon", iconValue);

            napi_set_element(env, result, i, infoObj);
        }

        // 释放内存
        OH_AbilityResourceInfo_Destroy(infos, infosCount);

        return result;
    }
    ```

**4. 接口暴露**

在src/main/cpp/types/libentry/Index.d.ts文件中，声明暴露接口。

```js
export const add: (a: number, b: number) => number;
export const getCurrentApplicationInfo: () => object;   // 新增暴露方法 getCurrentApplicationInfo
export const getAppId: () => string;                    // 新增暴露方法 getAppId
export const getAppIdentifier: () => string;            // 新增暴露方法 getAppIdentifier
export const getMainElementName: () => object;          // 新增暴露方法 getMainElementName
export const getCompatibleDeviceType: () => string;     // 新增暴露方法 getCompatibleDeviceType
export const isDebugMode: () => string;                 // 新增暴露方法 isDebugMode
export const getModuleMetadata: () => object;           // 新增暴露方法 getModuleMetadata
export const getAbilityResourceInfo: (fileType: string) => object;      // 新增暴露方法 getAbilityResourceInfo
```

**5. js侧调用**

1. 打开src\main\ets\pages\index.ets, 导入"libentry.so"。


2. 调用Native接口打印出获取的信息内容。示例如下：

    ```js
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import testNapi from 'libentry.so';
    
    const DOMAIN = 0x0000;
    
    @Entry
    @Component
    struct Index {
    @State message: string = 'Hello World';
    
    build() {
        Row() {
        Column() {
            Text(this.message)
            .fontSize($r('app.float.page_text_font_size'))
            .fontWeight(FontWeight.Bold)
            .onClick(() => {
                this.message = 'Welcome';
                hilog.info(DOMAIN, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));
                let appInfo = testNapi.getCurrentApplicationInfo();
                console.info("bundleNDK getCurrentApplicationInfo success, data is " + JSON.stringify(appInfo));
                let appId = testNapi.getAppId();
                console.info("bundleNDK getAppId success, appId is " + appId);
                let appIdentifier = testNapi.getAppIdentifier();
                console.info("bundleNDK getAppIdentifier success, appIdentifier is " + appIdentifier);
                let mainElement = testNapi.getMainElementName();
                console.info("bundleNDK getMainElementName success, data is " + JSON.stringify(mainElement));
                let deviceType = testNapi.getCompatibleDeviceType();
                console.info("bundleNDK getCompatibleDeviceType success, deviceType is " + deviceType);
                let isDebugMode = testNapi.isDebugMode();
                console.info("bundleNDK isDebugMode success, isDebugMode is " + isDebugMode);
                let moduleMetadata = testNapi.getModuleMetadata();
                console.info("bundleNDK getModuleMetadata success, data is " + JSON.stringify(moduleMetadata));
                let fileType: string = '.png';
                let abilityResourceInfo = testNapi.getAbilityResourceInfo(fileType);
                console.info("bundleNDK getAbilityResourceInfo success, data is " + JSON.stringify(abilityResourceInfo));
            })
        }
        .width('100%')
        }
        .height('100%')
    }
    }
    ```

关于包管理NDK接口说明，可参考[Native_Bundle模块介绍](../reference/apis-ability-kit/capi-native-bundle.md)。
