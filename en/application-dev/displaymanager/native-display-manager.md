# Using OH_DisplayManager to Obtain Basic Display Information and Listen for Status Changes (C/C++)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk; @logn-->
<!--Designer: @hejunfei1991-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## When to Use

The [OH_DisplayManager](../reference/apis-arkui/capi-oh-displaymanager.md) module provides functions for you to obtain the display information and listen for display status changes and folded/unfolded state changes. Applications can adapt to different UIs based on the information and changes.

- The display information that can be obtained includes the resolution, physical pixel density, logical pixel density, refresh rate, size, orientation, and rotation angle of the display.

- The display status changes include changes of the rotation, resolution, and refresh rate of the display.

- The folded/unfolded state changes indicate whether the device is in the folded or unfolded state. A function is also provided for you to check whether a device is foldable.

## Basic Concepts

- Density DPI: physical pixel density, that is, the number of physical pixels per inch of the display.

- Density pixels: logical pixel density, which indicates the scaling coefficient of the physical pixels and logical pixels. It is calculated by dividing the physical pixel density by 160.

## Available APIs

The following table lists the common APIs. For more API description, see [OH_DisplayManager](../reference/apis-arkui/capi-oh-displaymanager.md).

| Name| Description|
| -------- | -------- |
| OH_NativeDisplayManager_GetDefaultDisplayRotation(NativeDisplayManager_Rotation *displayRotation) | Obtains the rotation angle of the default display.|
| OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo **cutoutInfo) | Obtains the cutout information of the default display.|
| OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo *cutoutInfo) |  Destroys the cutout information of the default display.|
| OH_NativeDisplayManager_IsFoldable()|Checks whether the device is foldable.|
| OH_NativeDisplayManager_RegisterDisplayChangeListener( OH_NativeDisplayManager_DisplayChangeCallback displayChangeCallback, uint32_t *listenerIndex)|Registers a listener for status changes (such as rotation, refresh rate, DPI, and resolution changes) of the display.|
|OH_NativeDisplayManager_UnregisterDisplayChangeListener(uint32_t listenerIndex)|Cancels the listening for status changes of the display.|
|OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener( OH_NativeDisplayManager_FoldDisplayModeChangeCallback displayModeChangeCallback, uint32_t *listenerIndex)|Registers a listener for folded/unfolded state changes of the display.|
|OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener(uint32_t listenerIndex)|Cancels the listening for folded/unfolded state changes of the display.|

## Linking the Dynamic Library in the CMake Script

```
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
target_link_libraries(entry PUBLIC libnative_display_manager.so )
```

## Including Header Files

```c++
#include <window_manager/oh_display_info.h>
#include <window_manager/oh_display_manager.h>
#include <hilog/log.h>
```

## Obtaining Display Information

1. Call **OH_NativeDisplayManager_GetDefaultDisplayRotation** to obtain the rotation angle of the default display.

   ```c++
   #include "napi/native_api.h"
   #include <window_manager/oh_display_info.h>
   #include <window_manager/oh_display_manager.h>
   #include <hilog/log.h>
   
   static napi_value GetDefaultDisplayRotation(napi_env env, napi_callback_info info)
   {
       NativeDisplayManager_Rotation displayRotation;
       NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_GetDefaultDisplayRotation(&displayRotation);
       if (errCode == NativeDisplayManager_ErrorCode::DISPLAY_MANAGER_OK) {
           napi_value rotation;
           napi_create_int32(env, displayRotation, &rotation);
           return rotation;
       } else {
           napi_value errorCode;
           napi_create_int32(env, errCode, &errorCode);
           return errorCode;  
       }
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
          {"getDisplayRotation", nullptr, GetDefaultDisplayRotation, nullptr, nullptr, nullptr, napi_default, nullptr},
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   ```

2. Call **OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo** to obtain the cutout information of the default display. Call **OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo** to destroy the cutout information.

   ```c++
   #include "napi/native_api.h"
   #include <window_manager/oh_display_info.h>
   #include <window_manager/oh_display_manager.h>
   #include <hilog/log.h>
   
   static napi_value CreateDefaultDisplayCutoutInfo(napi_env env, napi_callback_info info)
   {
       NativeDisplayManager_CutoutInfo *cutOutInfo = NULL;
       NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo(&cutOutInfo);
       OH_LOG_INFO(LOG_APP, "GetDefaultCutoutInfo errCode=%{public}d", errCode);
       if (errCode == NativeDisplayManager_ErrorCode::DISPLAY_MANAGER_OK) {
           if (cutOutInfo != NULL && cutOutInfo->boundingRectsLength != 0) {
               OH_LOG_INFO(LOG_APP, "GetDefaultCutoutInfo cutOutInfo length=%{public}d", cutOutInfo->boundingRectsLength);
               for (int i = 0; i < cutOutInfo->boundingRectsLength; i++) {
                   OH_LOG_INFO(LOG_APP, "cutOutInfo[%{public}d]=[%{public}d %{public}d %{public}d %{public}d]",
                       i, cutOutInfo->boundingRects[i].left, cutOutInfo->boundingRects[i].top,
                       cutOutInfo->boundingRects[i].width, cutOutInfo->boundingRects[i].height);
               }
               OH_LOG_INFO(LOG_APP, "cutOutInfo waterfall left rect=[%{public}d %{public}d %{public}d %{public}d]",
               cutOutInfo->waterfallDisplayAreaRects.left.left, cutOutInfo->waterfallDisplayAreaRects.left.top,
               cutOutInfo->waterfallDisplayAreaRects.left.width, cutOutInfo->waterfallDisplayAreaRects.left.height);
               OH_LOG_INFO(LOG_APP, "cutOutInfo waterfall top rect=[%{public}d %{public}d %{public}d %{public}d]",
               cutOutInfo->waterfallDisplayAreaRects.top.left, cutOutInfo->waterfallDisplayAreaRects.top.top,
               cutOutInfo->waterfallDisplayAreaRects.top.width, cutOutInfo->waterfallDisplayAreaRects.top.height);
               OH_LOG_INFO(LOG_APP, "cutOutInfo waterfall right rect=[%{public}d %{public}d %{public}d %{public}d]",
               cutOutInfo->waterfallDisplayAreaRects.right.left, cutOutInfo->waterfallDisplayAreaRects.right.top,
               cutOutInfo->waterfallDisplayAreaRects.right.width, cutOutInfo->waterfallDisplayAreaRects.right.height);
               OH_LOG_INFO(LOG_APP, "cutOutInfo waterfall bottom rect=[%{public}d %{public}d %{public}d %{public}d]",
               cutOutInfo->waterfallDisplayAreaRects.bottom.left, cutOutInfo->waterfallDisplayAreaRects.bottom.top,
               cutOutInfo->waterfallDisplayAreaRects.bottom.width, cutOutInfo->waterfallDisplayAreaRects.bottom.height);            
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
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
           {"getCutoutInfo", nullptr, CreateDefaultDisplayCutoutInfo, nullptr, nullptr, nullptr, napi_default, nullptr},
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   ```



## Listening for Display Status Changes

Call **OH_NativeDisplayManager_RegisterDisplayChangeListener** to register a listener for display status changes, including the rotation, resolution, refresh rate, and DPI changes. Call **OH_NativeDisplayManager_UnregisterDisplayChangeListener** to cancel the listening for the display status changes.

```c++
#include "napi/native_api.h"
#include <window_manager/oh_display_info.h>
#include <window_manager/oh_display_manager.h>
#include <hilog/log.h>

void DisplayChangeCallback(uint64_t displayId)
{
    OH_LOG_INFO(LOG_APP, "DisplayChangeCallback displayId=%{public}lu.", displayId);
}

static napi_value RegisterDisplayChangeListener(napi_env env, napi_callback_info info)
{
    uint32_t listenerIndex;
    NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_RegisterDisplayChangeListener(
        DisplayChangeCallback, &listenerIndex);
    OH_LOG_INFO(LOG_APP, "RegisterDisplayChangeListener listenerIndex =%{public}d errCode=%{public}d.",
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

static napi_value UnregisterDisplayChangeListener(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = { nullptr };

    uint32_t listenerIndex;
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    napi_get_value_uint32(env, args[0], &listenerIndex);
    OH_LOG_INFO(LOG_APP, "UnregisterDisplayChangeListener listenerIndex =%{public}d.", listenerIndex);
    NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_UnregisterDisplayChangeListener(listenerIndex);
    OH_LOG_INFO(LOG_APP, "UnregisterDisplayChangeListener errCode=%{public}d.", errCode);
    napi_value errorCode;
    napi_create_int32(env, errCode, &errorCode);
    return errorCode;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"registerDisplayChange", nullptr, RegisterDisplayChangeListener, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"unregisterDisplayChange", nullptr, UnregisterDisplayChangeListener, nullptr, nullptr, nullptr,
            napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

```

## Listening for Folded/Unfolded State Changes

1. Call **OH_NativeDisplayManager_IsFoldable** to check whether a device is foldable.

   ```c++
   #include "napi/native_api.h"
   #include <window_manager/oh_display_manager.h>
   #include <hilog/log.h>
   
   static napi_value IsFoldable(napi_env env, napi_callback_info info)
   {
       bool isFoldDevice = OH_NativeDisplayManager_IsFoldable();
       OH_LOG_INFO(LOG_APP, "IsFoldable isFoldDevice =%{public}d.", isFoldDevice);
       napi_value isFold;
       napi_get_boolean(env, isFoldDevice, &isFold);
       return isFold;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
           {"checkIsFoldDevice", nullptr, IsFoldable, nullptr, nullptr, nullptr, napi_default, nullptr},
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   ```
2. Call **OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener** to register a listener for folded/unfolded state changes of the display. Call **OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener** to cancel the listening for the folded/unfolded state changes.

   ```c++
   #include "napi/native_api.h"
   #include <window_manager/oh_display_info.h>
   #include <window_manager/oh_display_manager.h>
   #include <hilog/log.h>
   
   void FoldDisplayModeChangeCallback(NativeDisplayManager_FoldDisplayMode displayMode)
   {
       OH_LOG_INFO(LOG_APP, "displayMode=%{public}d.", displayMode);
   }
   
   static napi_value RegisterFoldDisplayModeChangeListener(napi_env env, napi_callback_info info)
   {
       uint32_t listenerIndex = 0;
       NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener(
           FoldDisplayModeChangeCallback, &listenerIndex);
       OH_LOG_INFO(LOG_APP, "listenerIndex =%{public}d errCode=%{public}d.",
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
       napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
       napi_get_value_uint32(env, args[0], &listenerIndex);
       OH_LOG_INFO(LOG_APP, "listenerIndex =%{public}d.", listenerIndex);
       NativeDisplayManager_ErrorCode errCode = OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener(listenerIndex);
       OH_LOG_INFO(LOG_APP, "errorCode=%{public}d", errCode);
       napi_value errorCode;
       napi_create_int32(env, errCode, &errorCode);
       return errorCode;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
       { "registerFoldDisplayModeChange", nullptr, RegisterFoldDisplayModeChangeListener, nullptr, nullptr, nullptr,
           napi_default, nullptr },
       { "unregisterFoldDisplayModeChange", nullptr, UnregisterFoldDisplayModeChangeListener, nullptr, nullptr,
           nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   ```
