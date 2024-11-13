# 请求自绘制内容绘制帧率

对于基于[XComponent](../ui/napi-xcomponent-guidelines.md)进行Native开发的业务，可以请求独立的绘制帧率进行内容开发，如游戏、自绘制UI框架对接等场景。

## 接口说明

| 函数名称  | 说明     |
|-----|--------|
| OH_NativeXComponent_SetExpectedFrameRateRange (OH_NativeXComponent *component, OH_NativeXComponent_ExpectedRateRange *range) |设置帧期望的帧率范围。 
| OH_NativeXComponent_RegisterOnFrameCallback (OH_NativeXComponent *component, OH_NativeXComponent_OnFrameCallback *callback) | 设置每帧回调函数，同时启动每帧回调。 |
| OH_NativeXComponent_UnRegisterOnFrameCallback (OH_NativeXComponent *component) | 取消注册的每帧回调函数，同时停止调用回调函数。 |

## 开发步骤

   > **说明：**
   >
   > 本范例是通过Drawing在Native侧实现图形的绘制，并将其呈现在NativeWindow上，具体可参考[使用Drawing实现图形绘制与显示](drawing-guidelines.md)。

1. 定义ArkTS接口文件XComponentContext.ts，用来对接Native层。
   ```ts
   export default interface XComponentContext {
   register(): void;
   unregister(): void;
   };
   ```

2. 定义演示页面，包含两个XComponent组件。

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

3. Native层配置帧率和注册回调函数。

   ```ts
   static void TestCallback(OH_NativeXComponent *component, uint64_t timestamp, uint64_t targetTimestamp) // 定义每帧的回调函数
   {
       // ...
       // 获取XComponent的surface大小
       int32_t xSize = OH_NativeXComponent_GetXComponentSize(component, nativeWindow, &width, &height);
       if ((xSize == OH_NATIVEXCOMPONENT_RESULT_SUCCESS) && (render != nullptr)) {
           render->Prepare();
           render->Create();
           if (id == "xcomponentId_30") {
               // 30Hz绘制时,每帧移动的距离为16像素
               render->ConstructPath(16, 16, render->defaultOffsetY);
           }
           if (id == "xcomponentId_120") {
               // 120Hz绘制时，每帧移动的距离为4像素
               render->ConstructPath(4, 4, render->defaultOffsetY);
           }
     	 // ...
       }
   }
   ```

   > **说明：**
   >
   > - Callback回调函数运行于UI主线程，故涉及UI线程的耗时操作不应运行于回调函数中，以免影响性能。
   > - 实例在调用NapiRegister后，在不需要进行帧率控制时，应进行NapiUnregister操作，避免内存泄漏问题。

   ```ts
   void SampleXComponent::RegisterOnFrameCallback(OH_NativeXComponent *nativeXComponent) 
   {
       OH_NativeXComponent_RegisterOnFrameCallback(nativeXComponent, TestCallback); // 注册回调函数，并使能每帧回调
   }
   
   napi_value SampleXComponent::NapiRegister(napi_env env, napi_callback_info info)
   {
       // ...
       render->RegisterOnFrameCallback(nativeXComponent); // 在TS层使能注册与使能每帧回调
       // ...
   }
   
   napi_value SampleXComponent::NapiUnregister(napi_env env, napi_callback_info info)
   {
       // ...
       OH_NativeXComponent_UnregisterOnFrameCallback(nativeXComponent); // 在TS层取消注册每帧回调
       // ...
   }
   ```

4. TS层注册和取消注册每帧回调。

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

## 相关实例

针对可变帧率的开发，有以下相关实例可供参考：

- [DisplaySync分级管控(ArkTS)(API11)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/DisplaySync)