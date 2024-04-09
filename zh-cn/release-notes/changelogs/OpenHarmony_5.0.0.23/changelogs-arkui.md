# ArkUI子系统Changelog

## cl.arkui.1  Image组件按照syncLoad来同步/异步加载PixelMap格式图片

**访问级别**

公开接口

**变更原因**

应用侧的某些实现场景需要Image组件支持异步加载pixelMap。

**变更影响**

该变更为非兼容性变更。

API version 11及以前，Image组件加载PixelMap始终为同步加载。

API version 12及以后，Image组件按照syncLoad来同步/异步加载PixelMap格式图片，若没有设置则按照syncLoad为false进行异步加载。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**示例：**

无

**变更的接口/组件**

Image组件

**适配指导**

若应用侧需要Image组件同步加载pixelmap，则需要设置syncLoad为true。
