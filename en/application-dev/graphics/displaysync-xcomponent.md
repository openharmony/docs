# Requesting Frame Rates for Custom Content

When you use native APIs to develop an application based on the [XComponent](../ui/napi-xcomponent-guidelines.md), you can request an independent frame rate for custom content in scenarios such as gaming and custom UI framework interconnection.

## Available APIs

| Name | Description    |
|-----|--------|
| OH_NativeXComponent_SetExpectedFrameRateRange (OH_NativeXComponent *component, OH_NativeXComponent_ExpectedRateRange *range) |Sets the expected frame rate range.
| OH_NativeXComponent_RegisterOnFrameCallback (OH_NativeXComponent *component, OH_NativeXComponent_OnFrameCallback *callback) | Registers the display update callback and enables the callback for each frame.|
| OH_NativeXComponent_UnRegisterOnFrameCallback (OH_NativeXComponent *component) | Deregisters the display update callback and disables the callback for each frame.|

## How to Develop

   > **NOTE**
   >
   > This section draws a graphic through the native Drawing module and presents it using the native Window module. For details, see [Using Drawing to Draw and Display Graphics](drawing-guidelines.md).

1. Define an ArkTS API file and name it **XComponentContext.ts**, which is used to connect to the native layer.
   ```ts
   export default interface XComponentContext {
   register(): void;
   unregister(): void;
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
          XComponent({ id: 'xcomponentId_30', type: 'surface', libraryname: 'entry' })
            .onLoad((xComponentContext) => {
              this.xComponentContext1 = xComponentContext as XComponentContext;
            }).width('832px')
        }.height('40%')

        Row() {
          XComponent({ id: 'xcomponentId_120', type: 'surface', libraryname: 'entry' })
            .onLoad((xComponentContext) => {
              this.xComponentContext2 = xComponentContext as XComponentContext;
            }).width('832px') // Multiples of 64
        }.height('40%')
      }
    }
   }
   ```

3. Configure the frame rate and register the callback function at the native layer.

   ```ts
   static void TestCallback(OH_NativeXComponent *component, uint64_t timestamp, uint64_t targetTimestamp) // Define the callback function for each frame.
   {
       // ...
       // Obtain the surface size of the XComponent.
       int32_t xSize = OH_NativeXComponent_GetXComponentSize(component, nativeWindow, &width, &height);
       if ((xSize == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) && (render != nullptr)) {
           render->Prepare();
           render->Create();
           if (id == "xcomponentId_30") {
               // When the frame rate is 30 Hz, the frame moves by 16 pixels at a time.
               render->ConstructPath(16, 16, render->defaultOffsetY);
           }
           if (id == "xcomponentId_120") {
               // When the frame rate is 120 Hz, the frame moves by 4 pixels at a time.
               render->ConstructPath(4, 4, render->defaultOffsetY);
           }
     	 // ...
       }
   }
   ```

   > **NOTE**
   >
   > - The callback function runs in the UI main thread. To avoid adverse impact on the performance, time-consuming operations related to the UI thread should not run in the callback function.
   > - After the instance calls **NapiRegister**, it must call **NapiUnregister** when it no longer needs to control the frame rate, so as to avoid memory leakage.

   ```ts
   void SampleXComponent::RegisterOnFrameCallback(OH_NativeXComponent *nativeXComponent) 
   {
       OH_NativeXComponent_RegisterOnFrameCallback(nativeXComponent, TestCallback); // Register the callback function and enable callback for each frame.
   }
   
   napi_value SampleXComponent::NapiRegister(napi_env env, napi_callback_info info)
   {
       // ...
       render->RegisterOnFrameCallback(nativeXComponent); // Register the callback function and enable callback for each frame at the TS layer.
       // ...
   }
   
   napi_value SampleXComponent::NapiUnregister(napi_env env, napi_callback_info info)
   {
       // ...
       The OH_NativeXComponent_UnregisterOnFrameCallback(nativeXComponent); // Deregister the callback function for each frame at the TS layer.
       // ...
   }
   ```

4. Register and deregister the callback function for each frame at the TS layer.

   ```ts
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

