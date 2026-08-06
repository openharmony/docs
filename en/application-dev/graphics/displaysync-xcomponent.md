# Requesting Frame Rates for Custom Content

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @wh_qwe-->
<!--Designer: @wh_qwe-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=740dcdea7b2e0f63c4b99baa0eb4f2e92e763430 translatedAt=2026-08-03T11:19:07.746Z pushedAt=2026-08-04T06:15:33.677Z -->

When you use native APIs to develop an application based on the [XComponent](../ui/napi-xcomponent-guidelines.md), you can request an independent frame rate for custom content in scenarios such as gaming and custom UI framework interconnection.

## Available APIs

| Name | Description    |
|-----|--------|
| OH_NativeXComponent_SetExpectedFrameRateRange (OH_NativeXComponent *component, OH_NativeXComponent_ExpectedRateRange *range) | Sets the expected frame rate range. |
| OH_NativeXComponent_RegisterOnFrameCallback (OH_NativeXComponent *component, OH_NativeXComponent_OnFrameCallback *callback) | Registers the display update callback and enables the callback for each frame.|
| OH_NativeXComponent_UnregisterOnFrameCallback (OH_NativeXComponent *component) | Unregisters the per-frame callback function and stops invoking the callback. |

For details about the APIs, see [OH_NativeXComponent Native XComponent](../reference/apis-arkui/capi-oh-nativexcomponent-native-xcomponent.md).

## How to Develop

   > **NOTE**
   >
   > This section draws a graphic through the native Drawing module and presents it using the native Window module. For details, see [Using Drawing to Draw and Display Graphics](graphic-drawing-overview.md).

1. Add dependencies.

   Add the following library to **CMakeLists.txt**.

   <!-- @[display_sync_add_lib](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/cpp/CMakeLists.txt) -->

   ``` Text
   target_link_libraries(entry PUBLIC libace_napi.z.so libnative_drawing.so libnative_window.so libace_ndk.z.so)
   ```

   Import the required header files.

   <!-- @[display_sync_import_module_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/cpp/samples/sample_xcomponent.h) -->

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

   <!-- @[display_sync_import_module_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

   ``` C++
   #include <native_drawing/drawing_text_typography.h>
   ```

2. Define an ArkTS API file and name it **XComponentContext.ts**, which is used to connect to the native layer.

   <!-- @[display_sync_export_interface_xcomponent_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/interface/XComponentContext.ts) -->

   ``` TypeScript
   export default interface XComponentContext {
     register(): void;
   
     unregister(): void;
   };
   ```

3. Define a demo page, which contains two **XComponents**.

   <!-- @[display_sync_create_xcomponent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/XComponentDisplaySync.ets) -->

   ``` TypeScript
   import XComponentContext from '../interface/XComponentContext';
   // ...
   
   @Entry
   @Component
   struct Index {
     private xComponentContext1: XComponentContext | undefined = undefined;
     private xComponentContext2: XComponentContext | undefined = undefined;
   
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

4. Configure the frame rate and register the callback function at the native layer.

   <!-- @[display_sync_napi_frame_rate_setting_and_subscription_function_registration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

   ``` C++
   static void TestCallback(OH_NativeXComponent *component, uint64_t timestamp, uint64_t targetTimestamp)
   {
       // ...
       
       int32_t xSize = OH_NativeXComponent_GetXComponentSize(component, nativeWindow, &width, &height);
       if ((xSize == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) && (render != nullptr)) {
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
   ```

   > **NOTE**
   >
   > - The callback function runs in the UI main thread. To avoid adverse impact on the performance, time-consuming operations related to the UI thread should not run in the callback function.
   > - After the instance calls **OH_NativeXComponent_RegisterOnFrameCallback**, it must call **OH_NativeXComponent_UnregisterOnFrameCallback** when it no longer needs to control the frame rate, so as to avoid memory leakage and impact on performance and power consumption.
   > - Before API version 18, if the application calls **OH_NativeXComponent_RegisterOnFrameCallback** to set the callback function and does not unregister the callback function, the application can receive the expected callback when the XComponent instance exists.
   > - From API version 18 onwards, if the application calls **OH_NativeXComponent_RegisterOnFrameCallback** to set the callback function and does not unregister the callback function, the application can receive the expected callback only when the XComponent is on the tree.

   <!-- @[display_sync_register_on_frame_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

   ``` C++
   void SampleXComponent::RegisterOnFrameCallback(OH_NativeXComponent *nativeXComponent)
   {
       // ...
       OH_NativeXComponent_RegisterOnFrameCallback(nativeXComponent, TestCallback);
   }
   ```

   <!-- @[display_sync_napi_register](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

   ``` C++
   napi_value SampleXComponent::NapiRegister(napi_env env, napi_callback_info info)
   {
       // ...
           render->RegisterOnFrameCallback(nativeXComponent);
           // ...
   }
   ```

   <!-- @[display_sync_napi_unregister](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/cpp/samples/sample_xcomponent.cpp) -->

   ``` C++
   napi_value SampleXComponent::NapiUnregister(napi_env env, napi_callback_info info)
   {
       // ...
           OH_NativeXComponent_UnregisterOnFrameCallback(nativeXComponent);
           // ...
   }
   ```

5. Register and deregister the callback function for each frame at the TS layer.

   <!-- @[display_sync_start_and_stop_per_frame_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/XComponentDisplaySync.ets) -->

   ``` TypeScript
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
   
     // ...
   }
   ```

<!--RP1-->

## Samples

- [DisplaySync (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/DisplaySync)

<!--RP1End-->