# 模块描述(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

在Stage模型中，WindowStage/Window可以通过[loadContent](arkts-apis-window-Window.md#loadcontent9)接口加载页面并创建UI的实例，并将页面内容渲染到关联的窗口中，所以UI实例和窗口是一一关联的。一些全局的UI接口是和具体UI实例的执行上下文相关的，在当前接口调用时，通过追溯调用链跟踪到UI的上下文，来确定具体的UI实例。若在非UI页面中或者一些异步回调中调用这类接口，可能无法跟踪到当前UI的上下文，导致接口执行失败。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.arkui.UIContext (UIContext)](arkts-apis-uicontext.md)。

## 导入模块

```ts
import {
  BackgroundLuminanceSamplingConfigs, LuminanceSampler
} from '@kit.ArkUI';
```

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**系统接口**：此接口为系统接口。