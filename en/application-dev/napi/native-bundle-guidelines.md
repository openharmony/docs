# Native Bundle Development
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## When to Use

Use the native bundle APIs to obtain application information.

## Available APIs

| API                                                      | Description                                    |
| :----------------------------------------------------------- | :--------------------------------------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getcurrentapplicationinfo) | Obtains the information about the current application.         |
| [OH_NativeBundle_GetAppId](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getappid) | Obtains the appId information about the application.|
| [OH_NativeBundle_GetAppIdentifier](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getappidentifier) | Obtains the appIdentifier information about the application.|
| [OH_NativeBundle_GetMainElementName](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getmainelementname) | Obtains the entry information of the application.|
| [OH_NativeBundle_GetCompatibleDeviceType](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getcompatibledevicetype) | Obtains the compatible device type of the application.|
| [OH_NativeBundle_IsDebugMode](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_isdebugmode) | Queries the debug mode of the application.|
| [OH_NativeBundle_GetModuleMetadata](../reference/apis-ability-kit/capi-native-interface-bundle-h.md#oh_nativebundle_getmodulemetadata) | Obtains the metadata information of the application.|


## How to Develop

1. Create a project.

![native](figures/rawfile1.png)


2. Add dependencies.

After the project is created, the **cpp** directory is created in the project directory. In the **cpp** directory, there are files such as **types/libentry/index.d.ts**, **napi_init.cpp**, and **CMakeLists.txt**.

1. Open the **src/main/cpp/CMakeLists.txt** file, and add **libbundle_ndk.z.so** to **target_link_libraries**.

    ```c++
    target_link_libraries(entry PUBLIC libace_napi.z.so libbundle_ndk.z.so)
    ```

2. Open the **src/main/cpp/napi_init.cpp** file, and add the header file.

    ```c++
    // Include the header file required for napi.
    #include "napi/native_api.h"
    // Include the header file required for NDK interfaces.
    #include "bundle/native_interface_bundle.h"
    // Include the standard library for the free() function.
    #include <cstdlib>
    ```

3. Modify the source file.

1. When the **src/main/cpp/napi_init.cpp** file is opened, **Init** is called to initialize the API.

    ```c++
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "getCurrentApplicationInfo", nullptr, GetCurrentApplicationInfo, nullptr, nullptr, nullptr, napi_default, nullptr},   // Add the getCurrentApplicationInfo API.
            { "getAppId", nullptr, GetAppId, nullptr, nullptr, nullptr, napi_default, nullptr},                                     // Add the getAppId API.
            { "getAppIdentifier", nullptr, GetAppIdentifier, nullptr, nullptr, nullptr, napi_default, nullptr},                     // Add the getAppIdentifier API.
            { "getMainElementName", nullptr, GetMainElementName, nullptr, nullptr, nullptr, napi_default, nullptr},                 // Add the getMainElementName method.
            { "getCompatibleDeviceType", nullptr, GetCompatibleDeviceType, nullptr, nullptr, nullptr, napi_default, nullptr},       // Add the getCompatibleDeviceType method.
            { "isDebugMode", nullptr, IsDebugMode, nullptr, nullptr, nullptr, napi_default, nullptr},                               // Add the isDebugMode method.
            { "getModuleMetadata", nullptr, GetModuleMetadata, nullptr, nullptr, nullptr, napi_default, nullptr},                    // Add the getModuleMetadata method.
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    ```

2. Add the API to the **src/main/cpp/napi_init.cpp** file.

    ```c++
    static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info);
    static napi_value GetAppId(napi_env env, napi_callback_info info);
    static napi_value GetAppIdentifier(napi_env env, napi_callback_info info);
    static napi_value GetMainElementName(napi_env env, napi_callback_info info);
    static napi_value GetCompatibleDeviceType(napi_env env, napi_callback_info info);
    static napi_value IsDebugMode(napi_env env, napi_callback_info info);
    static napi_value GetModuleMetadata(napi_env env, napi_callback_info info);
3. Obtain the native bundle information object from the **src/main/cpp/napi_init.cpp** file and convert it to a JavaScript bundle information object. In this way, you can obtain the application information on the JavaScript side.

    ```c++
    static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info)
    {
        // Call the native API to obtain the application information.
        OH_NativeBundle_ApplicationInfo nativeApplicationInfo = OH_NativeBundle_GetCurrentApplicationInfo();
        napi_value result = nullptr;
        napi_create_object(env, &result);
        // Convert the bundle name obtained by calling the native API to the bundleName property in the JavaScript object.
        napi_value bundleName;
        napi_create_string_utf8(env, nativeApplicationInfo.bundleName, NAPI_AUTO_LENGTH, &bundleName);
        napi_set_named_property(env, result, "bundleName", bundleName);
        // Convert the fingerprint information obtained by calling the native API to the fingerprint property in the JavaScript object.
        napi_value fingerprint;
        napi_create_string_utf8(env, nativeApplicationInfo.fingerprint, NAPI_AUTO_LENGTH, &fingerprint);
        napi_set_named_property(env, result, "fingerprint", fingerprint);
    
        // To prevent memory leak, manually release the memory.
        free(nativeApplicationInfo.bundleName);
        free(nativeApplicationInfo.fingerprint);
        return result;
    }
    
    static napi_value GetAppId(napi_env env, napi_callback_info info)
    {
        // Call the native API to obtain the appId.
        char* appId = OH_NativeBundle_GetAppId();
        // Convert the appId obtained by calling the native API to nAppId and return it.
        napi_value nAppId;
        napi_create_string_utf8(env, appId, NAPI_AUTO_LENGTH, &nAppId);
        // To prevent memory leak, manually release the memory.
        free(appId);
        return nAppId;
    }
    
    static napi_value GetAppIdentifier(napi_env env, napi_callback_info info)
    {
        // Call the native API to obtain the appIdentifier.
        char* appIdentifier = OH_NativeBundle_GetAppIdentifier();
        // Convert the appIdentifier obtained by calling the native API to nAppIdentifier and return it.
        napi_value nAppIdentifier;
        napi_create_string_utf8(env, appIdentifier, NAPI_AUTO_LENGTH, &nAppIdentifier);
        // To prevent memory leak, manually release the memory.
        free(appIdentifier);
        return nAppIdentifier;
    }
    
    static napi_value GetMainElementName(napi_env env, napi_callback_info info)
    {
        // Call the native API to obtain the application entry information.
        OH_NativeBundle_ElementName elementName = OH_NativeBundle_GetMainElementName();
        napi_value result = nullptr;
        napi_create_object(env, &result);
        // Convert the bundle name obtained by calling the native API to the bundleName property in the JavaScript object.
        napi_value bundleName;
        napi_create_string_utf8(env, elementName.bundleName, NAPI_AUTO_LENGTH, &bundleName);
        napi_set_named_property(env, result, "bundleName", bundleName);
        // Convert the module name obtained by calling the native API to the moduleName property in the JavaScript object.
        napi_value moduleName;
        napi_create_string_utf8(env, elementName.moduleName, NAPI_AUTO_LENGTH, &moduleName);
        napi_set_named_property(env, result, "moduleName", moduleName);
        // Convert the ability name obtained by calling the native API to the abilityName property in the JavaScript object.
        napi_value abilityName;
        napi_create_string_utf8(env, elementName.abilityName, NAPI_AUTO_LENGTH, &abilityName);
        napi_set_named_property(env, result, "abilityName", abilityName);
        // To prevent memory leak, manually release the memory.
        free(elementName.bundleName);
        free(elementName.moduleName);
        free(elementName.abilityName);
        return result;
    }
    
    static napi_value GetCompatibleDeviceType(napi_env env, napi_callback_info info)
    {
        // Call the native API to obtain the device type.
        char* deviceType = OH_NativeBundle_GetCompatibleDeviceType();
        // Convert the device type obtained by calling the native API to nDeviceType and return it.
        napi_value nDeviceType;
        napi_create_string_utf8(env, deviceType, NAPI_AUTO_LENGTH, &nDeviceType);
        // To prevent memory leak, manually release the memory.
        free(deviceType);
        return nDeviceType;
    }
    
    static napi_value IsDebugMode(napi_env env, napi_callback_info info)
    {
        bool isDebug = false;
        // Call the native API to obtain the application debug mode.
        bool isSuccess = OH_NativeBundle_IsDebugMode(&isDebug);
        // Throw an exception if the native API call fails
        if (isSuccess == false) {
            napi_throw_error(env, nullptr, "call failed");
            return nullptr;
        }
        // Convert the debug information obtained by calling the native API to debug and return it.
        napi_value debug;
        napi_get_boolean(env, isDebug, &debug);
        return debug;
    }
    
    static napi_value GetModuleMetadata(napi_env env, napi_callback_info info)
    {
        size_t moduleCount = 0;
        // Call the native API to obtain the application metadata information.
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
    
            // Convert the module name obtained by calling the native API to the moduleName property in the JavaScript object.
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
    
                // Convert the metadata name obtained by calling the native API to the name property in the JavaScript object.
                napi_set_named_property(env, metadataObj, "name", name);
                // Convert the metadata value obtained by calling the native API to the value property in the JavaScript object.
                napi_set_named_property(env, metadataObj, "value", value);
                // Convert the metadata resource obtained by calling the native API to the resource property in the JavaScript object.
                napi_set_named_property(env, metadataObj, "resource", resource);
    
                napi_set_element(env, metadataArray, j, metadataObj);
            }
    
            napi_set_named_property(env, moduleObj, "metadata", metadataArray);
            napi_set_element(env, result, i, moduleObj);
        }
    
        // To prevent memory leak, manually release the memory.
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
    ```

4. Expose APIs.

Declare the exposed APIs in the **src/main/cpp/types/libentry/Index.d.ts** file.

```js
export const add: (a: number, b: number) => number;
export const getCurrentApplicationInfo: () => object;   // Add the exposed API getCurrentApplicationInfo.
export const getAppId: () => string;                    // Add the exposed API getAppId.
export const getAppIdentifier: () => string;            // Add the exposed API getAppIdentifier.
export const getMainElementName: () => object;          // Add the exposed API getMainElementName.
export const getCompatibleDeviceType: () => string;     // Add the exposed API getCompatibleDeviceType.
export const isDebugMode: () => string;                 // Add the exposed API isDebugMode.
export const getModuleMetadata: () => object;           // Add the exposed API getModuleMetadata.
```

5. Call APIs on the JavaScript side.

1. Open the **src\main\ets\pages\index.ets** file, and import **libentry.so**.


2. Call the native APIs to print the obtained information. An example is as follows:

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
            })
        }
        .width('100%')
        }
        .height('100%')
    }
    }
    ```

For details about the APIs, see [Native_Bundle](../reference/apis-ability-kit/capi-native-bundle.md).
