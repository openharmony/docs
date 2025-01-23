# 获取设备的位置信息开发指导(C/C++)


## 场景介绍

开发者可以调用OpenHarmony位置相关接口，监听设备的位置变化。

## 函数说明

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Location_IsLocatingEnabled(bool* enabled)     | 查询位置开关是否开启。                                 |
| OH_Location_StartLocating(const Location_RequestConfig* requestConfig) | 启动定位并订阅位置变化。 |
| Location_ResultCode OH_Location_StopLocating(const Location_RequestConfig* requestConfig) | 停止定位并取消订阅位置变化。 |
| OH_LocationInfo_GetBasicInfo(Location_Info* location)   | 获取位置基本信息。 |
| OH_LocationInfo_GetAdditionalInfo(Location_Info* location, char* additionalInfo, uint32_t length) | 获取位置信息中的附加信息。 |
| OH_Location_CreateRequestConfig(void) | 创建一个位置请求参数结构体实例。    |
| OH_Location_DestroyRequestConfig(Location_RequestConfig* requestConfig) | 销毁位置请求参数实例并回收内存。  |
| OH_LocationRequestConfig_SetUseScene(Location_RequestConfig* requestConfig, Location_UseScene useScene) | 设置位置请求参数中的用户活动场景。     |
| OH_LocationRequestConfig_SetPowerConsumptionScene(Location_RequestConfig* requestConfig, Location_PowerConsumptionScene powerConsumptionScene) | 设置位置请求参数中的功耗场景。      |
| OH_LocationRequestConfig_SetInterval(Location_RequestConfig* requestConfig, int interval) | 设置位置请求参数中的位置上报间隔。                               |
| OH_LocationRequestConfig_SetCallback(Location_RequestConfig* requestConfig, Location_InfoCallback callback, void* userData) | 设置回调函数。     |


## 开发步骤

1. 获取设备的位置信息，需要有位置权限，位置权限申请的方法和步骤见[申请位置权限开发指导](location-permission-guidelines.md)。


2. CMakeLists.txt文件中引入动态依赖库。

   ```c
   target_link_libraries(entry PUBLIC libace_napi.z.so)
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
   target_link_libraries(entry PUBLIC liblocation_ndk.so)
   ```

3. 在napi_init.cpp文件中编码，首先导入模块。

   ```c
   #include "sensors/oh_location.h"
   #include "sensors/oh_location_type.h"
   #include "napi/native_api.h"
   #include "hilog/log.h"
   ```

4. 调用获取位置接口之前需要先判断位置开关是否打开。
   查询当前位置开关状态，返回结果为布尔值，true代表位置开关开启，false代表位置开关关闭，示例代码如下：

   ```c
    static napi_value OhLocationIsEnabled(napi_env env, napi_callback_info info)
    {
        bool isEnabled = false;
        auto resultCode = OH_Location_IsLocatingEnabled(&isEnabled);
        napi_value result = nullptr;
        napi_get_boolean(env, isEnabled, &result);
        return result;
    }
    // 在Init函数中补充接口。
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            {"ohLocationIsEnabled", nullptr, OhLocationIsEnabled, nullptr, nullptr, nullptr, napi_default, nullptr},
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
   ```
   如果位置开关未开启，可以拉起全局开关设置弹框，引导用户打开位置开关，具体可参考[拉起全局开关设置弹框](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestglobalswitch12)

5. 定位位置变化。

    ```c
    // 定义一个请求参数
    struct Location_RequestConfig *requestConfig = NULL;

    // 定义一个回调函数用来接收位置信息
    void reportLocation(Location_Info* location, void* userData)
    {
        auto baseInfo = OH_LocationInfo_GetBasicInfo(location);
        char additionalInfo[] = "";
        auto addition = OH_LocationInfo_GetAdditionalInfo(location, additionalInfo, 0);
        return;
    }

    // 订阅位置信息
    static napi_value OhLocationStartLocating(napi_env env, napi_callback_info info)
    {
        if (g_requestConfig == nullptr) {
            g_requestConfig = OH_Location_CreateRequestConfig();
        }
        OH_LocationRequestConfig_SetUseScene(g_requestConfig, LOCATION_USE_SCENE_NAVIGATION);
        OH_LocationRequestConfig_SetPowerConsumptionScene(g_requestConfig, LOCATION_HIGH_POWER_CONSUMPTION);
        OH_LocationRequestConfig_SetInterval(g_requestConfig, 1);
        OH_LocationRequestConfig_SetCallback(g_requestConfig, reportLocation, (void *)(1));
        OH_Location_StartLocating(g_requestConfig);
        int32_t ret = 0;
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        return result;
    }

    //取消订阅位置信息， g_requestConfig要和订阅时传入的对象保持一致
    static napi_value OhLocationStopLocating(napi_env env, napi_callback_info info)
    {
        OH_Location_StopLocating(g_requestConfig);
        if (g_requestConfig != nullptr) {
            OH_Location_DestroyRequestConfig(g_requestConfig);
            g_requestConfig = nullptr;
        }
        int32_t ret = 0;
        napi_value result = nullptr;
        napi_create_int32(env, ret, &result);
        return result;
    }

    // 在Init函数中补充接口。
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            {"ohLocationStartLocating", nullptr, OhLocationStartLocating, nullptr, nullptr, nullptr, napi_default, nullptr},
            {"ohLocationStopLocating", nullptr, OhLocationStopLocating, nullptr, nullptr, nullptr, napi_default, nullptr},
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    ```