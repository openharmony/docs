# 数据防泄漏服务开发指导(C/C++)
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--Designer: @QRF-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

数据防泄漏（Data Loss Prevention，DLP）是系统提供的系统级的数据防泄漏解决方案，提供跨设备的文件的权限管理、加密存储、授权访问等能力。

- 权限管理：查询当前DLP沙箱的权限信息。
- 文件信息获取：获取DLP文件的基本信息，如原始文件名。
- 沙箱环境检测：查询当前应用是否运行在DLP沙箱环境。
- 配置管理：设置、获取和清理沙箱应用配置信息。
      
## 接口说明
数据防泄漏服务关键接口如下表所示。具体API说明详见[dlp_permission_api.h](../../reference/apis-data-protection-kit/capi-dlp-permission-api-h.md)
| 名称 | 描述 |
| -------- | -------- |
| DLP_ErrCode OH_DLP_GetDlpPermissionInfo(DLP_FileAccess \*dlpFileAccess, uint32_t \*flags)| 查询当前DLP沙箱的权限信息。 |
|DLP_ErrCode OH_DLP_GetOriginalFileName(const char \*fileName, char \*\*originalFileName)  | 获取指定DLP文件名的原始文件名。 |
|DLP_ErrCode OH_DLP_IsInSandbox(bool \*isInSandbox)  |查询当前应用是否运行在DLP沙箱环境。  |
| DLP_ErrCode OH_DLP_SetSandboxAppConfig(const char \*configInfo) | 设置沙箱应用配置信息。 |
| DLP_ErrCode OH_DLP_GetSandboxAppConfig(char \*\*configInfo) |获取沙箱应用配置信息。  |
|DLP_ErrCode OH_DLP_CleanSandboxAppConfig()  |清理沙箱应用配置信息。  |


## 开发步骤

1. 在CMakeLists.txt中导入数据防泄漏的共享库，并链接该库。
    <!-- @[dlp_C_makeLists](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/CMakeLists.txt) -->
    
    ``` Text
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.5.0)
    project(DlpApiTest)
    
    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    
    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()
    
    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)
    
    add_library(entry SHARED napi_init.cpp)
    target_link_libraries(entry PUBLIC libace_napi.z.so libohdlp_permission.so)
    ```
    

2. 导入数据防泄漏服务的头文件和NAPI相关头文件。
    <!-- @[dlp_C_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    #include "napi/native_api.h"
    #include <cstdint>
    #include <cstdlib>
    #include "DataProtectionKit/dlp_permission_api.h"
    ```
    

3. 查询当前DLP沙箱的权限信息。
    <!-- @[dlp_C_GetDlpPermissionInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value GetDlpPermissionInfo(napi_env env, napi_callback_info info)
    {
        DLP_FileAccess dlpFileAccess = NO_PERMISSION; // 表示DLP文件授权类型
        uint32_t flags = 0; // 表示DLP文件的详细操作权限
        DLP_ErrCode ret = OH_DLP_GetDlpPermissionInfo(&dlpFileAccess, &flags);
        if (ret == DLP_ErrCode::ERR_OH_SUCCESS) {
            napi_value result[2] = {nullptr};
            napi_create_int32(env, dlpFileAccess, &result[0]);
            napi_create_int32(env, flags, &result[1]);
            return result[1];
        }
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        return result;
    }
    ```
    

4. 获取指定DLP文件名的原始文件名。
    <!-- @[dlp_C_GetOriginalFileName](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value GetOriginalFileName(napi_env env, napi_callback_info info)
    {
        const char *fileName = "test.txt.dlp"; // 表示DLP文件名，用以获取原始文件名
        char *originalFileName = nullptr; // 表示原始文件名
        DLP_ErrCode ret = OH_DLP_GetOriginalFileName(fileName, &originalFileName);
        if (ret == DLP_ErrCode::ERR_OH_SUCCESS) {
            napi_value result = nullptr;
            napi_create_string_utf8(env, originalFileName, NAPI_AUTO_LENGTH, &result);
            return result;
        }
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        free(originalFileName); // 处理完后手动释放originalFileName
        return result;
    }
    ```
    

5. 查询当前应用是否运行在DLP沙箱环境。
    <!-- @[dlp_C_IsInSandbox](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value IsInSandbox(napi_env env, napi_callback_info info)
    {
        bool isInSandbox = false; // true表示当前应用在沙箱中，false表示应用不在沙箱
        DLP_ErrCode ret = OH_DLP_IsInSandbox(&isInSandbox);
        if (ret == DLP_ErrCode::ERR_OH_SUCCESS) {
            napi_value result = nullptr;
            napi_get_boolean(env, isInSandbox, &result);
            return result;
        }
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        return result;
    }
    ```
    

6. 设置沙箱应用配置信息。
    <!-- @[dlp_C_SetSandboxAppConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value SetSandboxAppConfig(napi_env env, napi_callback_info info)
    {
        const char *configInfo = "configInfo"; // 沙箱应用配置信息，用户可将配置信息json化后传入
        DLP_ErrCode ret = OH_DLP_SetSandboxAppConfig(configInfo);
        
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        return result;
    }
    ```
    

7. 获取沙箱应用配置信息。
    <!-- @[dlp_C_GetSandboxAppConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/napi_init.cpp) --> 
    
    ``` C++
    static napi_value GetSandboxAppConfig(napi_env env, napi_callback_info info)
    {
        char *configInfo = nullptr; // 输出json化后的沙箱应用配置信息
        DLP_ErrCode ret = OH_DLP_GetSandboxAppConfig(&configInfo);
        if (ret == DLP_ErrCode::ERR_OH_SUCCESS) {
            napi_value result = nullptr;
            napi_create_string_utf8(env, configInfo, NAPI_AUTO_LENGTH, &result);
            return result;
        }
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        free(configInfo); // 处理完后手动释放configInfo
        return result;
    }
    ```
    

8. 清理沙箱应用配置信息。
    <!-- @[dlp_C_CleanSandboxAppConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DlpCApiTest/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value CleanSandboxAppConfig(napi_env env, napi_callback_info info)
    {
        DLP_ErrCode ret = OH_DLP_CleanSandboxAppConfig();
        
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        return result;
    }
    ```
    
