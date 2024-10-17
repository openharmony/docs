# 窗口子系统变更说明

## cl.window.1 优化getWindowProperties，增加返回值中drawableRect的实时性，调用行为变更

**访问级别**

公开接口

**变更原因**

应用调用getWindowProperties可以获取窗口属性，返回的结构体中表示可绘制区域的字段为drawableRect，如果在on('windowSizeChange')回调中调用getWindowproperties，可能获得未更新的drawableRect。
通过本次变更，在on('windowSizeChange')回调中同步更新windowRect和drawableRect，应用可基于此进行更加灵活的自绘制布局。

**变更影响**

该变更为不兼容变更。

变更前：on('windowSizeChange')回调中调用getWindowProperties获取drawableRect，可能获得未更新的drawableRect。

变更后：on('windowSizeChange')回调中调用getWindowProperties获取drawableRect，可以获得正确的drawableRect。

**起始 API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.45开始。

**变更的接口/组件**

@ohos.window.d.ts

系统能力：SystemCapability.WindowManager.WindowManager.Core

接口：getWindowProperties

**适配指导**

drawableRect字段从API 11开始提供

本次变更在API 13开始生效，应用如果依赖drawableRect，可以通过api版本信息来保持兼容，实例如下：
```ts
try {
  let properties = windowClass.getWindowProperties();
  if (deviceInfo.sdkApiVersion >= 13) {
    console.info(`use drawableRect here. ${properties.drawableRect}`);
  }
} catch (exception) {
  console.error(`Failed to obtain the window properties. Cause code: ${exception.code}, message: ${exception.message}`);
}
```