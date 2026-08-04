# Native DisplaySoloist Development (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @wh_qwe-->
<!--Designer: @wh_qwe-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=1eef0e1140c123e13d7d8e64b360a32b63fc454f translatedAt=2026-08-03T11:18:19.103Z pushedAt=2026-08-04T03:49:42.728Z -->

To develop a native service that controls the frame rate in an independent thread, you use **DisplaySoloist** to implement the services, such as gaming and self-drawing UI framework interconnection.

A **DisplaySoloist** instance can exclusively occupy a thread or share a thread with others.

## Available APIs

| Name                                                    | Description                                                 |
| ------------------------------------------------------------ | ----------------------------------------------------- |
| OH_DisplaySoloist* OH_DisplaySoloist_Create (bool useExclusiveThread) | Creates an **OH_DisplaySoloist** instance.                      |
| OH_DisplaySoloist_Destroy (OH_DisplaySoloist * displaySoloist) | Destroys an **OH_DisplaySoloist** instance.                      |
| OH_DisplaySoloist_Start (OH_DisplaySoloist * displaySoloist, OH_DisplaySoloist_FrameCallback callback, void * data) | Starts per-frame callback, sets the callback function, and invokes it on each VSync signal. |
| OH_DisplaySoloist_Stop (OH_DisplaySoloist * displaySoloist)  | Stops requesting the next VSync signal and triggering the callback function.|
| OH_DisplaySoloist_SetExpectedFrameRateRange (OH_DisplaySoloist* displaySoloist, DisplaySoloist_ExpectedRateRange* range) | Sets the expected frame rate range.                                   |

For details, see [NativeDisplaySoloist](../reference/apis-arkgraphics2d/capi-nativedisplaysoloist.md).

## How to Develop

   In this example, a graphic is drawn using the native Drawing module. Specifically, an expected frame rate is set through the asynchronous thread, and the graphic is drawn based on the frame rate and displayed on the native window. For details about graphics drawing, see [Using Drawing to Draw and Display Graphics (C/C++)](graphic-drawing-overview.md).

### Adding Dependencies

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.

<!-- @[display_soloist_add_lib](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/cpp/CMakeLists.txt) -->

``` Text
target_link_libraries(entry PUBLIC libace_napi.z.so libnative_drawing.so libnative_window.so libace_ndk.z.so libnative_display_soloist.so)
```

**Including Header Files**

<!-- @[display_soloist_import_module_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/cpp/samples/sample_xcomponent.h) -->

``` C
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <arpa/nameser.h>
#include <bits/alltypes.h>
#include <native_window/external_window.h>
#include <native_drawing/drawing_bitmap.h>
#include <native_drawing/drawing_color.h>
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_pen.h>
#include <native_drawing/drawing_brush.h>
#include <native_drawing/drawing_path.h>
#include <cstdint>
#include <map>
#include <sys/mman.h>
#include <string>
#include "napi/native_api.h"
```

<!-- @[display_soloist_import_module_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

``` C++
#include <native_display_soloist/native_display_soloist.h>
```

### How to Develop

1. Define an ArkTS API file and name it **XComponentContext.ts**, which is used to connect to the native layer.

   <!-- @[display_soloist_export_interface_xcomponent_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/ets/interface/XComponentContext.ts) -->

   ``` TypeScript
   export default interface XComponentContext {
     register(): void;
   
     unregister(): void;
   
     destroy(): void;
   };
   ```

2. Define a demo page, which contains two **XComponents**.

   <!-- @[display_soloist_create_xcomponent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import XComponentContext from '../interface/XComponentContext';
   // ...
   
   @Entry
   @Component
   struct Index {
     private xComponentContext1: XComponentContext | undefined = undefined;
     private xComponentContext2: XComponentContext | undefined = undefined;
   
     // ...
   
     build() {
       Column() {
         Row() {
           // ...
   
           XComponent({
             id: 'xcomponentId_30',
             type: XComponentType.SURFACE,
             libraryname: 'entry'
           })
             .onLoad((xComponentContext) => {
               this.xComponentContext1 = xComponentContext as XComponentContext;
             }).width('640px')
             // ...
         }.height('40%')
   
         Row() {
           // ...
   
           XComponent({
             id: 'xcomponentId_120',
             type: XComponentType.SURFACE,
             libraryname: 'entry'
           })
             .onLoad((xComponentContext) => {
               this.xComponentContext2 = xComponentContext as XComponentContext;
             }).width('640px')
             // ...
         }.height('40%')
   
         // ...
       }
     }
   }
   ```

3. Obtain the native **XComponent** at the C++ layer. You are advised to save the **XComponent** in a singleton. This step must be performed during napi_init.

    Create a PluginManager singleton class to manage the NativeXComponent.

   <!-- @[display_soloist_create_plugin_manager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/cpp/plugin/plugin_manager.h) -->

   ``` C
   class PluginManager {
   public:
       ~PluginManager();
   
       static PluginManager *GetInstance();
   
       void SetNativeXComponent(std::string &id, OH_NativeXComponent *nativeXComponent);
       SampleXComponent *GetRender(std::string &id);
       void Export(napi_env env, napi_value exports);
   
   private:
       std::unordered_map<std::string, OH_NativeXComponent *> nativeXComponentMap_;
       std::unordered_map<std::string, SampleXComponent *> pluginRenderMap_;
   };
   ```

   The **SampleXComponent** class will be created in the step of drawing the graphic.

   <!-- @[display_soloist_export_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/cpp/plugin/plugin_manager.cpp) -->

   ``` C++
   void PluginManager::Export(napi_env env, napi_value exports)
   {
       nativeXComponentMap_.clear();
       pluginRenderMap_.clear();
       if ((env == nullptr) || (exports == nullptr)) {
           SAMPLE_LOGE("Export: env or exports is null");
           return;
       }
   
       napi_value exportInstance = nullptr;
       if (napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance) != napi_ok) {
           SAMPLE_LOGE("Export: napi_get_named_property fail");
           return;
       }
   
       OH_NativeXComponent *nativeXComponent = nullptr;
       if (napi_unwrap(env, exportInstance, reinterpret_cast<void **>(&nativeXComponent)) != napi_ok) {
           SAMPLE_LOGE("Export: napi_unwrap fail");
           return;
       }
   
       char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {'\0'};
       uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
       if (OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
           SAMPLE_LOGE("Export: OH_NativeXComponent_GetXComponentId fail");
           return;
       }
   
       std::string id(idStr);
       auto context = PluginManager::GetInstance();
       if ((context != nullptr) && (nativeXComponent != nullptr)) {
           context->SetNativeXComponent(id, nativeXComponent);
           auto render = context->GetRender(id);
           if (render != nullptr) {
               render->RegisterCallback(nativeXComponent);
               render->Export(env, exports);
           } else {
               SAMPLE_LOGE("render is nullptr");
           }
       }
   }
   ```

4. Configure the frame rate and register the callback function at the native layer.

   Define the callback function for each frame.

   <!-- @[display_soloist_frame_rate_setting_and_subscription_function_registration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

   ``` C++
   static void TestCallback(long long timestamp, long long targetTimestamp, void *data)
   {
       // ...
       OH_NativeXComponent *component = nullptr;
       component = static_cast<OH_NativeXComponent *>(data);
       if (component == nullptr) {
           SAMPLE_LOGE("TestCallback: component is null");
           return;
       }
   
       char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {'\0'};
       uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
       if (OH_NativeXComponent_GetXComponentId(component, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
           SAMPLE_LOGE("TestCallback: Unable to get XComponent id");
           return;
       }
   
       std::string id(idStr);
       auto render = SampleXComponent::GetInstance(id);
       if (render != nullptr) {
           OHNativeWindow *nativeWindow = render->GetNativeWindow();
           uint64_t width;
           uint64_t height;
   
           int32_t xSize = OH_NativeXComponent_GetXComponentSize(component, nativeWindow, &width, &height);
           if (xSize == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
               render->Prepare();
               render->Create();
               if (id == "xcomponentId_30") {
                   int offset = 16;
                   render->ConstructPath(offset, offset, render->defaultOffsetY);
               }
               if (id == "xcomponentId_120") {
                   int offset = 4;
                   render->ConstructPath(offset, offset, render->defaultOffsetY);
               }
               // ...
           }
       }
   }
   ```

   Call the **DisplaySoloist** APIs to configure the frame rate and register the callback function for each frame. If the input parameter **useExclusiveThread** is set to **true** when **OH_DisplaySoloist_Create** is called to create a **DisplaySoloist** instance, **OH_DisplaySoloist_FrameCallback** is executed in exclusive thread mode. Otherwise, **OH_DisplaySoloist_FrameCallback** is executed in shared thread mode.

   > **NOTE**
   >
   > - After the instance calls **NapiRegister**, it must call **NapiUnregister** when it no longer needs to control the frame rate, so as to avoid memory leakage.
   > - During page redirection, both **NapiUnregister** and **NapiDestroy** must be called to avoid memory leakage.

   <!-- @[display_soloist_napi_register_and_unregister](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

   ``` C++
   static std::unordered_map<std::string, OH_DisplaySoloist *> g_displaySync;
   
   // ...
   
   void ExecuteDisplaySoloist(std::string id, DisplaySoloist_ExpectedRateRange range, bool useExclusiveThread,
                              OH_NativeXComponent *nativeXComponent)
   {
       OH_DisplaySoloist *nativeDisplaySoloist = nullptr;
       if (g_displaySync.find(id) == g_displaySync.end()) {
           g_displaySync[id] = OH_DisplaySoloist_Create(useExclusiveThread);
       }
       nativeDisplaySoloist = g_displaySync[id];
       OH_DisplaySoloist_SetExpectedFrameRateRange(nativeDisplaySoloist, &range);
       OH_DisplaySoloist_Start(nativeDisplaySoloist, TestCallback, nativeXComponent);
   }
   
   napi_value SampleXComponent::NapiRegister(napi_env env, napi_callback_info info)
   {
       // ...
   
       napi_value thisArg;
       if (napi_get_cb_info(env, info, nullptr, nullptr, &thisArg, nullptr) != napi_ok) {
           SAMPLE_LOGE("NapiRegister: napi_get_cb_info fail");
           return nullptr;
       }
   
       napi_value exportInstance;
       if (napi_get_named_property(env, thisArg, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance) != napi_ok) {
           SAMPLE_LOGE("NapiRegister: napi_get_named_property fail");
           return nullptr;
       }
   
       OH_NativeXComponent *nativeXComponent = nullptr;
       if (napi_unwrap(env, exportInstance, reinterpret_cast<void **>(&nativeXComponent)) != napi_ok) {
           SAMPLE_LOGE("NapiRegister: napi_unwrap fail");
           return nullptr;
       }
   
       char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {'\0'};
       uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
       if (OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
           SAMPLE_LOGE("NapiRegister: Unable to get XComponent id");
           return nullptr;
       }
       SAMPLE_LOGI("RegisterID = %{public}s", idStr);
       std::string id(idStr);
       SampleXComponent *render = SampleXComponent::GetInstance(id);
       if (render != nullptr) {
           DisplaySoloist_ExpectedRateRange range;
           bool useExclusiveThread = false;
           if (id == "xcomponentId_30") {
               range = {30, 120, 30};
           }
   
           if (id == "xcomponentId_120") {
               range = {30, 120, 120};
           }
           ExecuteDisplaySoloist(id, range, useExclusiveThread, nativeXComponent);
       }
       return nullptr;
   }
   
   napi_value SampleXComponent::NapiUnregister(napi_env env, napi_callback_info info)
   {
       // ...
           OH_DisplaySoloist_Stop(g_displaySync[id]);
           // ...
   }
   
   napi_value SampleXComponent::NapiDestroy(napi_env env, napi_callback_info info)
   {
       // ...
           OH_DisplaySoloist_Destroy(g_displaySync[id]);
           g_displaySync.erase(id);
           // ...
   }
   
   // ...
   
   void SampleXComponent::Export(napi_env env, napi_value exports)
   {
       if ((env == nullptr) || (exports == nullptr)) {
           SAMPLE_LOGE("Export: env or exports is null");
           return;
       }
       napi_property_descriptor desc[] = {
           {"register", nullptr, SampleXComponent::NapiRegister, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"unregister", nullptr, SampleXComponent::NapiUnregister, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"destroy", nullptr, SampleXComponent::NapiDestroy, nullptr, nullptr, nullptr, napi_default, nullptr}};
   
       if (napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc) != napi_ok) {
           SAMPLE_LOGE("Export: napi_define_properties failed");
       }
   }
   ```

5. Register and deregister the callback function for each frame at the TS layer, and destroy the OH_DisplaySoloist instance.

   <!-- @[display_soloist_disappear](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySoloist/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   aboutToDisappear(): void {
     // ...
     if (this.xComponentContext1) {
       this.xComponentContext1.unregister();
       this.xComponentContext1.destroy();
     }
     if (this.xComponentContext2) {
       this.xComponentContext2.unregister();
       this.xComponentContext2.destroy();
     }
   }
   
   // ...
   
       Row() {
         Button('Start')
           .id('Start')
           .fontSize(14)
           .fontWeight(500)
           .margin({ bottom: 20, right: 6, left: 6 })
           .onClick(() => {
             if (this.xComponentContext1) {
               this.xComponentContext1.register();
             }
             if (this.xComponentContext2) {
               this.xComponentContext2.register();
             }
           })
           .width('30%')
           .height(40)
           .shadow(ShadowStyle.OUTER_DEFAULT_LG)
   
         Button('Stop')
           .id('Stop')
           .fontSize(14)
           .fontWeight(500)
           .margin({ bottom: 20, left: 6 })
           .onClick(() => {
             if (this.xComponentContext1) {
               this.xComponentContext1.unregister();
             }
             if (this.xComponentContext2) {
               this.xComponentContext2.unregister();
             }
           })
           .width('30%')
           .height(40)
           .shadow(ShadowStyle.OUTER_DEFAULT_LG)
       }
   ```

<!--RP1-->

## Samples

The following sample is provided to help you better understand how to develop the frame rate feature:

- [DisplaySoloist Hierarchical Control (API Version 14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/DisplaySoloist)

<!--RP1End-->