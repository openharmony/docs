# Native DisplaySoloist Development (C/C++)

To develop a native service that controls the frame rate in an independent thread, you use **DisplaySoloist** to implement the services, such as gaming and self-drawing UI framework interconnection.

A **DisplaySoloist** instance can exclusively occupy a thread or share a thread with others.

## Available APIs

| Name                                                    | Description                                                 |
| ------------------------------------------------------------ | ----------------------------------------------------- |
| OH_DisplaySoloist* OH_DisplaySoloist_Create (bool useExclusiveThread) | Creates an **OH_DisplaySoloist** instance.                      |
| OH_DisplaySoloist_Destroy (OH_DisplaySoloist * displaySoloist) | Destroys an **OH_DisplaySoloist** instance.                      |
| OH_DisplaySoloist_Start (OH_DisplaySoloist * displaySoloist, OH_DisplaySoloist_FrameCallback callback, void * data ) | Sets a callback function for each frame. The callback function is triggered each time a VSync signal arrives.  |
| OH_DisplaySoloist_Stop (OH_DisplaySoloist * displaySoloist)  | Stops requesting the next VSync signal and triggering the callback function. |
| OH_DisplaySoloist_SetExpectedFrameRateRange (OH_DisplaySoloist* displaySoloist, DisplaySoloist_ExpectedRateRange* range) | Sets the expected frame rate range.                                   |

## How to Develop

In this example, a graphic is drawn using the native Drawing module. Specifically, an expected frame rate is set through the asynchronous thread, and the graphic is drawn based on the frame rate and displayed on the native window. For details about graphics drawing, see [Using Drawing to Draw and Display Graphics (C/C++)](drawing-guidelines.md).

### Adding Dependencies

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.

```txt
libace_napi.z.so
libace_ndk.z.so
libnative_window.so
libnative_drawing.so
libnative_display_soloist.so
```

**Including Header Files**
```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include "napi/native_api.h"
#include <native_display_soloist/native_display_soloist.h>
#include <native_drawing/drawing_bitmap.h>
#include <native_drawing/drawing_color.h>
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_pen.h>
#include <native_drawing/drawing_brush.h>
#include <native_drawing/drawing_path.h>
#include <native_window/external_window.h>
#include <cmath>
#include <algorithm>
#include <stdint.h>
#include <sys/mman.h>
```

1. Define an ArkTS API file and name it **XComponentContext.ts**, which is used to connect to the native layer.
   ```ts
   export default interface XComponentContext {
     register(): void;
     unregister(): void;
     destroy(): void;
   };
   ```

2. Define a demo page, which contains two **XComponents**.

   ```ts
   import XComponentContext from "../interface/XComponentContext";
   
   @Entry
   @Component
   struct Index {
     private xComponentContext1: XComponentContext | undefined = undefined;
     private xComponentContext2: XComponentContext | undefined = undefined;
   
     build() {
       Column() {
         Row() {
           XComponent({ id: 'xcomponentId30', type: 'surface', libraryname: 'entry' })
             .onLoad((xComponentContext) => {
               this.xComponentContext1 = xComponentContext as XComponentContext;
             }).width('640px')
         }.height('40%')
   
         Row() {
           XComponent({ id: 'xcomponentId120', type: 'surface', libraryname: 'entry' })
             .onLoad((xComponentContext) => {
               this.xComponentContext2 = xComponentContext as XComponentContext;
             }).width('640px') // Multiple of 64
         }.height('40%')
       }
     }
   }
   ```
   
3. Obtain the native **XComponent** at the C++ layer. You are advised to save the **XComponent** in a singleton. This step must be performed during napi_init.

    Create a **PluginManger** singleton to manage the native **XComponent**.
    ```c++
    class PluginManager {
    public:
        ~PluginManager();

        static PluginManager *GetInstance();

        void SetNativeXComponent(std::string &id, OH_NativeXComponent *nativeXComponent);
        SampleBitMap *GetRender(std::string &id);
        void Export(napi_env env, napi_value exports);
    private:

        std::unordered_map<std::string, OH_NativeXComponent *> nativeXComponentMap_;
        std::unordered_map<std::string, SampleXComponent *> pluginRenderMap_;
    };
    ```
    The **SampleXComponent** class will be created in the step of drawing the graphic.
    ```c++
    void PluginManager::Export(napi_env env, napi_value exports) {
        nativeXComponentMap_.clear();
        pluginRenderMap_.clear();
        if ((env == nullptr) || (exports == nullptr)) {
            DRAWING_LOGE("Export: env or exports is null");
            return;
        }

        napi_value exportInstance = nullptr;
        if (napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance) != napi_ok) {
            DRAWING_LOGE("Export: napi_get_named_property fail");
            return;
        }

        OH_NativeXComponent *nativeXComponent = nullptr;
        if (napi_unwrap(env, exportInstance, reinterpret_cast<void **>(&nativeXComponent)) != napi_ok) {
            DRAWING_LOGE("Export: napi_unwrap fail");
            return;
        }

        char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {'\0'};
        uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
        if (OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
            DRAWING_LOGE("Export: OH_NativeXComponent_GetXComponentId fail");
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
                DRAWING_LOGE("render is nullptr");
            }
        }
    }
    ```

4. Configure the frame rate and register the callback function at the native layer.

   Define the callback function for each frame.

   ```c++
   static void TestCallback(long long timestamp, long long targetTimestamp, void *data) 
   {
      // ...
      // Obtain the corresponding XComponent.
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
       OHNativeWindow *nativeWindow = render->GetNativeWindow();
       uint64_t width;
       uint64_t height;
       // Obtain the surface size of the XComponent.
       int32_t xSize = OH_NativeXComponent_GetXComponentSize(component, nativeWindow, &width, &height);
       if ((xSize == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) && (render != nullptr)) {
           render->Prepare();
           render->Create();
           if (id == "xcomponentId30") {
               // When the frame rate is 30 Hz, the frame moves by 16 pixels at a time.
               render->ConstructPath(16, 16, render->defaultOffsetY);
           }
           if (id == "xcomponentId120") {
               // When the frame rate is 120 Hz, the frame moves by 4 pixels at a time.
               render->ConstructPath(4, 4, render->defaultOffsetY);
           }
     	 // ...
       }
   }
   ```

5. Call the **DisplaySoloist** APIs to configure the frame rate and register the callback function for each frame.

   > **NOTE**
   >
   > - After the instance calls **NapiRegister**, it must call **NapiUnregister** when it no longer needs to control the frame rate, so as to avoid memory leakage.
   > - During page redirection, both **NapiUnregister** and **NapiDestroy** must be called to avoid memory leakage.

   ```c++
   static std::unordered_map<std::string, OH_DisplaySoloist *> g_displaySync;
   
   napi_value SampleXComponent::NapiRegister(napi_env env, napi_callback_info info)
   {
       // ...
       // Obtain the corresponding XComponent.
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
       SampleXComponent *render = SampleXComponent().GetInstance(id);
       if (render != nullptr) {
          OH_DisplaySoloist *nativeDisplaySoloist = nullptr;
          if (g_displaySync.find(id) == g_displaySync.end()) {
             // Create an OH_DisplaySoloist instance.
             // The value true means that the OH_DisplaySoloist instance exclusively occupies a thread, and false means that the instance shares a thread with others.
             g_displaySync[id] = OH_DisplaySoloist_Create(true);
          }
          nativeDisplaySoloist = g_displaySync[id];
          // Set the expected frame rate range.
          // The member variables of this struct are the minimum frame rate, maximum frame rate, and expected frame rate.
          DisplaySoloist_ExpectedRateRange range;
          if (id == "xcomponentId30") {
             // The expected frame rate of the first XComponent is 30 Hz.
             range = {30, 120, 30};
          }
          if (id == "xcomponentId120") {
             // The expected frame rate of the second XComponent is 120 Hz.
             range = {30, 120, 120};
          }
          OH_DisplaySoloist_SetExpectedFrameRateRange(nativeDisplaySoloist, &range);
          // Register the callback function for each frame and enable it.
          OH_DisplaySoloist_Start(nativeDisplaySoloist, TestCallback, nativeXComponent);
       }
       // ...
   }
   
   napi_value SampleXComponent::NapiUnregister(napi_env env, napi_callback_info info)
   {
       // ...
       // Unregister the callback function for each frame.
       OH_DisplaySoloist_Stop(g_displaySync[id]);; 
       // ...
   }
   
   napi_value SampleXComponent::NapiDestroy(napi_env env, napi_callback_info info)
   {
       // ...
       // Destroy the OH_DisplaySoloist instance.
       OH_DisplaySoloist_Destroy(g_displaySync[id]);
       g_displaySync.erase(id);       
       // ...
   }
   
   // Implement the mappings between the ArkTS APIs in XComponentContext.ts and C++ APIs.
   void SampleXComponent::Export(napi_env env, napi_value exports) {
    if ((env == nullptr) || (exports == nullptr)) {
        SAMPLE_LOGE("Export: env or exports is null");
        return;
    }
    napi_property_descriptor desc[] = {
        {"register", nullptr, SampleXComponent::NapiRegister, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"unregister", nullptr, SampleXComponent::NapiUnregister, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"destroy", nullptr, SampleXComponent::NapiDestroy, nullptr, nullptr, nullptr, napi_default, nullptr}};
   
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    if (napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc) != napi_ok) {
        SAMPLE_LOGE("Export: napi_define_properties failed");
    }
   }
   ```

6. Register and deregister the callback function for each frame at the TS layer, and destroy the OH_DisplaySoloist instance.

   ```c++
   // When you leave the page, unregister the callback function and destroy the OH_DisplaySoloist instance.
   aboutToDisappear(): void {
     if (this.xComponentContext1) {
       this.xComponentContext1.unregister();
       this.xComponentContext1.destroy();
     }
     if (this.xComponentContext2) {
       this.xComponentContext2.unregister();
       this.xComponentContext2.destroy();
     }
   }
   
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

