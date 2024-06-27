# NativeDisplaySoloist开发指导 (C/C++)

如果开发者想在独立线程中进行帧率控制的Native侧业务，可以通过DisplaySoloist来实现，如游戏、自绘制UI框架对接等场景。
开发者可以选择多个DisplaySoloist实例共享一个线程，也可以选择每个DisplaySoloist实例独占一个线程。

## 接口说明

| 函数名称  | 说明     |
|-----|--------|
| OH_DisplaySoloist* OH_DisplaySoloist_Create (bool useExclusiveThread) |创建一个OH_DisplaySoloist实例。 |
| OH_DisplaySoloist_Destroy (OH_DisplaySoloist * displaySoloist) | 销毁一个OH_DisplaySoloist实例。 |
| OH_DisplaySoloist_Start (OH_DisplaySoloist * displaySoloist, OH_DisplaySoloist_FrameCallback callback, void * data ) | 设置每帧回调函数，每次VSync信号到来时启动每帧回调。 |
| OH_DisplaySoloist_Stop (OH_DisplaySoloist * displaySoloist) | 停止请求下一次VSync信号，并停止调用回调函数callback。 |
| OH_DisplaySoloist_SetExpectedFrameRateRange (OH_DisplaySoloist* displaySoloist, DisplaySoloist_ExpectedRateRange* range) | 设置期望帧率范围。 |

## 开发步骤

   本范例是通过Drawing在Native侧实现图形的绘制，通过异步线程设置期望的帧率，再根据帧率进行图形的绘制并将其呈现在NativeWindow上，图形绘制部分可参考[使用Drawing实现图形绘制与显示](drawing-guidelines.md)。

1. 定义ArkTS接口文件XComponentContext.ts，用来对接Native层。
   ```ts
   export default interface XComponentContext {
   register(): void;
   unregister(): void;
   destroy(): void;
   };
   ```

2. 定义演示页面，包含两个XComponent组件。

   ```ts
   @Entry
   @Component
   struct Index {
     private xComponentContext1: XComponentContext | undefined = undefined;
     private xComponentContext2: XComponentContext | undefined = undefined;
      Row() {
        XComponent({ id: 'xcomponentId_30', type: 'surface', libraryname: 'entry' })
          .onLoad((xComponentContext) => {
            this.xComponentContext1 = xComponentContext as XComponentContext;
          }).width('640px')
      }.height('40%')

      Row() {
        XComponent({ id: 'xcomponentId_120', type: 'surface', libraryname: 'entry' })
          .onLoad((xComponentContext) => {
            this.xComponentContext2 = xComponentContext as XComponentContext;
          }).width('640px')// Multiples of 64
      }.height('40%')
   }
   ```

3. Native层配置帧率和注册回调函数。

   ```c++
   static void TestCallback(long long timestamp, long long targetTimestamp, void *data) // 定义每帧的回调函数
   {
       // ...
       // 获取XComponent的surface大小
       int32_t xSize = OH_NativeXComponent_GetXComponentSize(component, nativeWindow, &width, &height);
       if ((xSize == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) && (render != nullptr)) {
           render->Prepare();
           render->Create();
           if (id == "xcomponentId30") {
               // 30Hz绘制时,每帧移动的距离为16像素
               render->ConstructPath(16, 16, render->defaultOffsetY);
           }
           if (id == "xcomponentId120") {
               // 120Hz绘制时，每帧移动的距离为4像素
               render->ConstructPath(4, 4, render->defaultOffsetY);
           }
     	 // ...
       }
   }
   ```

   > **说明：**
   >
   > - 实例在调用NapiRegister后，在不需要进行帧率控制时，应进行NapiUnregister操作，避免内存泄漏问题。
   > - 在页面跳转时，应进行NapiUnregister和NapiDestroy操作，避免内存泄漏问题。

   ```c++
   static std::unordered_map<std::string, OH_DisplaySoloist *> g_displaySync;

   napi_value SampleXComponent::NapiRegister(napi_env env, napi_callback_info info)
   {
       // ...
       OH_DisplaySoloist *nativeDisplaySoloist = nullptr;
       if (g_displaySync.find(id) == g_displaySync.end()) {
           // 创建OH_DisplaySoloist实例
           g_displaySync[id] = OH_DisplaySoloist_Create(true);
       }
       nativeDisplaySoloist = g_displaySync[id];
       // 设置期望帧率范围
       OH_DisplaySoloist_SetExpectedFrameRateRange(nativeDisplaySoloist, &range);
       // 注册回调与使能每帧回调
       OH_DisplaySoloist_Start(nativeDisplaySoloist, TestCallback, nativeXComponent);
       // ...
   }
   
   napi_value SampleXComponent::NapiUnregister(napi_env env, napi_callback_info info)
   {
       // ...
       // 取消注册每帧回调
       OH_DisplaySoloist_Stop(g_displaySync[id]);; 
       // ...
   }

   napi_value SampleXComponent::NapiDestroy(napi_env env, napi_callback_info info)
   {
       // ...
       // 销毁OH_DisplaySoloist实例
       OH_DisplaySoloist_Destroy(g_displaySync[id]);
       g_displaySync.erase(id);       
       // ...
   }
   ```

4. TS层注册和取消注册每帧回调，销毁OH_DisplaySoloist实例。

   ```ts

   // 离开页面时，取消回调注册与销毁OH_DisplaySoloist实例
   aboutToDisappear(): void {
     Logger.info(TAG, "aboutToDisappear");
     if (this.xComponentContext1) {
       Logger.info(TAG, "Unregister1");
       this.xComponentContext1.unregister();
       this.xComponentContext1.destroy();
     }
     if (this.xComponentContext2) {
       Logger.info(TAG, "Unregister2");
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
