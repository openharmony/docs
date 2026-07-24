# 使用OH_DisplayManager实现屏幕基础信息查询和状态监听 (C/C++)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk-->
<!--Designer: @logn; @wulong158-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## 场景介绍

[OH_DisplayManager](../reference/apis-arkui/capi-oh-displaymanager.md)屏幕管理模块用于提供屏幕的信息查询、屏幕状态变化监听、折叠设备的折叠状态变化监听等能力，应用可根据对应的屏幕信息、屏幕状态变化、屏幕折叠状态适配不同的UI界面显示。

- 支持查询的屏幕信息，包括屏幕的分辨率、物理像素密度、逻辑像素密度、刷新率、屏幕尺寸、屏幕旋转方向、屏幕旋转角度等。

- 支持屏幕状态变化的监听，包括屏幕旋转变化，屏幕分辨率变化、屏幕刷新率变化等。

- 支持查询当前设备是否为可折叠设备，同时支持折叠状态（展开/折叠）变化的监听。

## 基本概念

- 屏幕的物理像素密度(densityDPI)：代表每英寸屏幕所拥有的物理像素点数。

- 屏幕的逻辑像素的密度(densityPixels)：代表物理像素与逻辑像素的缩放系数比，计算方法为物理像素密度除以160。

## 接口说明

常用接口如下表所示。更多API说明请参考[OH_DisplayManager](../reference/apis-arkui/capi-oh-displaymanager.md)。

| 接口名 | 描述 |
| -------- | -------- |
| OH_NativeDisplayManager_GetDefaultDisplayRotation(NativeDisplayManager_Rotation *displayRotation) | 获取默认屏幕的旋转角度。 |
| OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo **cutoutInfo) | 获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 |
| OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo *cutoutInfo) |  销毁挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。|
| OH_NativeDisplayManager_IsFoldable()|查询设备是否可折叠。|
| OH_NativeDisplayManager_RegisterDisplayChangeListener( OH_NativeDisplayManager_DisplayChangeCallback displayChangeCallback, uint32_t *listenerIndex)|注册屏幕状态变化监听（如旋转变化、刷新率、DPI、分辨率等）。|
|OH_NativeDisplayManager_UnregisterDisplayChangeListener(uint32_t listenerIndex)|取消屏幕状态变化监听。|
|OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener( OH_NativeDisplayManager_FoldDisplayModeChangeCallback displayModeChangeCallback, uint32_t *listenerIndex)|注册屏幕展开、折叠状态变化监听。|
|OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener(uint32_t listenerIndex)|取消屏幕展开、折叠状态变化监听。|

## 在CMake脚本中链接动态库
<!-- @[add_display_target_link](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/CMakeLists.txt) -->

``` Text
target_link_libraries(nativedisplay PUBLIC libhilog_ndk.z.so)
target_link_libraries(nativedisplay PUBLIC libnative_display_manager.so)
```

## 添加头文件

<!-- @[import_display_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
#include <window_manager/oh_display_info.h>
#include <window_manager/oh_display_manager.h>
#include <hilog/log.h>
```

## 获取屏幕状态

1. 可以通过OH_NativeDisplayManager_GetDefaultDisplayRotation获取默认屏幕的旋转角度。

    <!-- @[get_rotation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value GetDefaultDisplayRotation(napi_env env, napi_callback_info info)
    {
        NativeDisplayManager_Rotation displayRotation;
        NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_GetDefaultDisplayRotation(&displayRotation);
        if (errCode == NativeDisplayManager_ErrorCode::DISPLAY_MANAGER_OK) {
            napi_value rotation;
            napi_create_int32(env, displayRotation, &rotation);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest", "rotation=%{public}d", displayRotation);
            return rotation;
        } else {
            napi_value errorCode;
            napi_create_int32(env, errCode, &errorCode);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
                "GetDefaultDisplayRotation errCode=%{public}d", errCode);
            return errorCode;
        }
    }
    ```

2. 可以通过OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。 可通过OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo销毁挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。

    <!-- @[get_cutout_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value CreateDefaultDisplayCutoutInfo(napi_env env, napi_callback_info info)
    {
        NativeDisplayManager_CutoutInfo *cutOutInfo = NULL;
        NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo(&cutOutInfo);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest", "GetDefaultCutoutInfo errCode=%{public}d", errCode);
        if (errCode == NativeDisplayManager_ErrorCode::DISPLAY_MANAGER_OK) {
            if (cutOutInfo != NULL && cutOutInfo->boundingRectsLength != 0) {
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
                    "GetDefaultCutoutInfo cutOutInfo length=%{public}d", cutOutInfo->boundingRectsLength);
                for (int i = 0; i < cutOutInfo->boundingRectsLength; i++) {
                    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
                        "cutOutInfo[%{public}d]=[%{public}d %{public}d %{public}d %{public}d]",
                        i, cutOutInfo->boundingRects[i].left, cutOutInfo->boundingRects[i].top,
                        cutOutInfo->boundingRects[i].width, cutOutInfo->boundingRects[i].height);
                }
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
                    "cutOutInfo waterfall left rect=[%{public}d %{public}d %{public}d %{public}d]",
                    cutOutInfo->waterfallDisplayAreaRects.left.left, cutOutInfo->waterfallDisplayAreaRects.left.top,
                    cutOutInfo->waterfallDisplayAreaRects.left.width, cutOutInfo->waterfallDisplayAreaRects.left.height);
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
                    "cutOutInfo waterfall top rect=[%{public}d %{public}d %{public}d %{public}d]",
                    cutOutInfo->waterfallDisplayAreaRects.top.left, cutOutInfo->waterfallDisplayAreaRects.top.top,
                    cutOutInfo->waterfallDisplayAreaRects.top.width, cutOutInfo->waterfallDisplayAreaRects.top.height);
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
                    "cutOutInfo waterfall right rect=[%{public}d %{public}d %{public}d %{public}d]",
                    cutOutInfo->waterfallDisplayAreaRects.right.left, cutOutInfo->waterfallDisplayAreaRects.right.top,
                    cutOutInfo->waterfallDisplayAreaRects.right.width, cutOutInfo->waterfallDisplayAreaRects.right.height);
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
                    "cutOutInfo waterfall bottom rect=[%{public}d %{public}d %{public}d %{public}d]",
                    cutOutInfo->waterfallDisplayAreaRects.bottom.left,
                    cutOutInfo->waterfallDisplayAreaRects.bottom.top,
                    cutOutInfo->waterfallDisplayAreaRects.bottom.width,
                    cutOutInfo->waterfallDisplayAreaRects.bottom.height);
            }
            napi_value boundingRectsLength;
            napi_create_int32(env, cutOutInfo->boundingRectsLength, &boundingRectsLength);
            OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo(cutOutInfo);
            return boundingRectsLength;
        } else {
            napi_value errorCode;
            napi_create_int32(env, errCode, &errorCode);
            return errorCode;
        }
    }
    ```

## 监听屏幕状态变化

可以通过OH_NativeDisplayManager_RegisterDisplayChangeListener接口注册屏幕变化的监听，包括屏幕旋转、分辨率变化、刷新率变化、DPI变化等。 通过OH_NativeDisplayManager_UnregisterDisplayChangeListener接口取消屏幕状态变化的监听。

<!-- @[register_display_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
void DisplayChangeCallback(uint64_t displayId)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
        "DisplayChangeCallback displayId=%{public}lu.", displayId);
}

static napi_value RegisterDisplayChangeListener(napi_env env, napi_callback_info info)
{
    uint32_t listenerIndex;
    NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_RegisterDisplayChangeListener(
        DisplayChangeCallback, &listenerIndex);
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
        "RegisterDisplayChangeListener listenerIndex =%{public}d errCode=%{public}d.", listenerIndex, errCode);
    if (errCode == NativeDisplayManager_ErrorCode::DISPLAY_MANAGER_OK) {
        napi_value registerIndex;
        napi_create_int32(env, listenerIndex, &registerIndex);
        return registerIndex;
    } else {
        napi_value errorCode;
        napi_create_int32(env, errCode, &errorCode);
        return errorCode;
    }
}

static napi_value UnregisterDisplayChangeListener(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = { nullptr };

    uint32_t listenerIndex;
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_get_value_uint32(env, args[0], &listenerIndex);
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
        "UnregisterDisplayChangeListener listenerIndex =%{public}d.", listenerIndex);
    NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_UnregisterDisplayChangeListener(listenerIndex);
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest",
        "UnregisterDisplayChangeListener errCode=%{public}d.", errCode);
    napi_value errorCode;
    napi_create_int32(env, errCode, &errorCode);
    return errorCode;
}
```

## 监听折叠设备状态变化

1. 可以通过OH_NativeDisplayManager_IsFoldable接口查询设备是不是折叠设备。

    <!-- @[get_foldable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    static napi_value IsFoldable(napi_env env, napi_callback_info info)
    {
        bool isFoldDevice = OH_NativeDisplayManager_IsFoldable();
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest", "IsFoldable isFoldDevice =%{public}d.", isFoldDevice);
        napi_value isFold;
        napi_get_boolean(env, isFoldDevice, &isFold);
        return isFold;
    }
    ```
 

2. 可以通过OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener注册屏幕展开/折叠状态变化的监听。 通过OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener接口取消屏幕展开/折叠状态变化的监听。

    <!-- @[register_displayMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->
    
    ``` C++
    void FoldDisplayModeChangeCallback(NativeDisplayManager_FoldDisplayMode displayMode)
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest", "displayMode=%{public}d.", displayMode);
    }
    
    static napi_value RegisterFoldDisplayModeChangeListener(napi_env env, napi_callback_info info)
    {
        uint32_t listenerIndex = 0;
        NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener(
            FoldDisplayModeChangeCallback, &listenerIndex);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest", "listenerIndex =%{public}d errCode=%{public}d.",
            listenerIndex, errCode);
        if (errCode == NativeDisplayManager_ErrorCode::DISPLAY_MANAGER_OK) {
            napi_value registerIndex;
            napi_create_int32(env, listenerIndex, &registerIndex);
            return registerIndex;
        } else {
            napi_value errorCode;
            napi_create_int32(env, errCode, &errorCode);
            return errorCode;
        }
    }
    
    static napi_value UnregisterFoldDisplayModeChangeListener(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value args[1] = { nullptr };
        uint32_t listenerIndex;
        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
        napi_get_value_uint32(env, args[0], &listenerIndex);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest", "listenerIndex =%{public}d.", listenerIndex);
        NativeDisplayManager_ErrorCode errCode =
            OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener(listenerIndex);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "DMSTest", "errorCode=%{public}d", errCode);
        napi_value errorCode;
        napi_create_int32(env, errCode, &errorCode);
        return errorCode;
    }
    ```

## 注册函数

<!-- @[register_napi_display_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"getDisplayRotation", nullptr, GetDefaultDisplayRotation, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getCutoutInfo", nullptr, CreateDefaultDisplayCutoutInfo, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"registerDisplayChange", nullptr, RegisterDisplayChangeListener,
            nullptr, nullptr, nullptr, napi_default, nullptr},
        {"unregisterDisplayChange", nullptr, UnregisterDisplayChangeListener,
            nullptr, nullptr, nullptr, napi_default, nullptr},
        {"checkIsFoldDevice", nullptr, IsFoldable, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"registerFoldDisplayModeChange", nullptr, RegisterFoldDisplayModeChangeListener,
            nullptr, nullptr, nullptr, napi_default, nullptr},
        {"unregisterFoldDisplayModeChange", nullptr, UnregisterFoldDisplayModeChangeListener,
            nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

## 注册模块

<!-- @[register_display_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_module displayModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "nativedisplay",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&displayModule);
}
```

## 在Index.ets文件中调用函数

<!-- @[call_display_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
private callGetDisplayRotation(): void {
  this.promptAction.openToast({ message: '调用getDisplayRotation方法' }).catch((error: Error) => {
    console.error(`callGetDisplayRotation error ${JSON.stringify(error)}`);
  }).then(() => {
    console.info(`get rotation value is: ${displayNapi.getDisplayRotation()}`);
  });
}

private callFoldableCallback(): void {
  this.promptAction.openToast({ message: '调用register displayMode方法' }).catch((error: Error) => {
    console.error(`callFoldableCallback error ${JSON.stringify(error)}`);
  }).then(() => {
    let registerIndex = displayNapi.registerFoldDisplayModeChange();
    console.info(`register foldable value is: ${registerIndex}`);
    console.info(`unregister foldable value is: ${displayNapi.unregisterFoldDisplayModeChange(registerIndex)}`);
  });
}

private callGetCutoutInfo(): void {
  this.promptAction.openToast({ message: '调用getCutoutInfo方法' }).catch((error: Error) => {
    console.error(`callGetCutoutInfo error ${JSON.stringify(error)}`);
  }).then(() => {
    console.info(`cutoutInfo length is: ${displayNapi.getCutoutInfo()}`);
  });
}

private callDealListenCallback(): void {
  this.promptAction.openToast({ message: '调用register change方法' }).catch((error: Error) => {
    console.error(`callDealListenCallback error ${JSON.stringify(error)}`);
  }).then(() => {
    let registerIndex = displayNapi.registerDisplayChange();
    console.info(`register display change value is: ${registerIndex}`);
    console.info(`unregister display change value is: ${displayNapi.unregisterDisplayChange(registerIndex)}`);
  });
}

private callDealFoldableDevice(): void {
  this.promptAction.openToast({ message: '调用dealFoldableDevice方法' }).catch((error: Error) => {
    console.error(`callDealFoldableDevice error ${JSON.stringify(error)}`);
  }).then(() => {
    console.info(`fold device is: ${displayNapi.checkIsFoldDevice()}`);
  });
}
```
