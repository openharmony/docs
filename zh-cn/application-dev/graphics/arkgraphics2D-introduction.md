# ArkGraphics 2D简介

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @goumiao; @hangmengxin-->
<!--Designer: @liumingxiang; @wangyanglan-->
<!--Tester: @yhl0101; @nobuggers-->
<!--Adviser: @ge-yafang-->

ArkGraphics 2D（方舟2D图形服务 ）主要提供图形绘制与显示相关的能力。开发者可以基于一套统一的图形接口进行应用开发，使应用开发更简单、高效。

## 能力范围

- 提供图像处理的一些基本能力，包括对当前图像的亮度调节、模糊化、灰度调节、智能取色等。具体可见[@ohos.effectKit (图像效果)](../reference/apis-arkgraphics2d/js-apis-effectKit.md)。

- 提供管理抽象化色域对象的基础能力，包括色域的创建、色域基础属性的获取等。具体可见[@ohos.graphics.colorSpaceManager (色彩管理)](../reference/apis-arkgraphics2d/js-apis-colorSpaceManager.md)与[@ohos.graphics.sendableColorSpaceManager (可共享的色彩管理)](../reference/apis-arkgraphics2d/js-apis-sendableColorSpaceManager.md)。

- 提供可针对不同形式的内容指定帧率的能力，可用于开发者自绘制内容。具体可见[可变帧率简介](displaysync-overview.md)。

- 提供高动态显示的相关能力，具体可见[@ohos.graphics.hdrCapability (HDR能力)](../reference/apis-arkgraphics2d/js-apis-hdrCapability.md)。

- 提供自绘制的相关能力，开发者可根据需要，自定义绘制实现UI效果，可自定义绘制基础形状、文本、图片等。具体可见[@ohos.graphics.drawing (绘制模块)](../reference/apis-arkgraphics2d/arkts-apis-graphics-drawing.md)。

- 提供图形绘制与显示相关的Native能力，包括[NativeWindow](../reference/apis-arkgraphics2d/capi-nativewindow.md)、[NativeBuffer](../reference/apis-arkgraphics2d/capi-oh-nativebuffer.md)、[NativeImage](../reference/apis-arkgraphics2d/capi-oh-nativeimage.md)、[NativeVsync](../reference/apis-arkgraphics2d/capi-nativevsync.md)、[Drawing](../reference/apis-arkgraphics2d/capi-drawing.md)等模块。

## 使用场景

- 图像效果处理：开发者可根据不同的UI效果需要，使用[effectKit模块](../reference/apis-arkgraphics2d/js-apis-effectKit.md)实现图像的效果处理，以提升用户浏览体验。

- 设置图像色域：开发者可根据设计需求使用图像文件并设置色域信息，实现图像广色域效果的绘制和显示。

- 定制帧率场景：支持开发者根据不同内容和需要，定制帧率进行绘制。比如不同游戏场景和界面时，设置不同的帧率，以提升用户体验流畅性并达到平衡功耗的效果。

- 自绘制场景：开发者可根据不同的UI效果和场景需要，使用Drawing等模块实现除ArkUI组件外的自定义组件或者自定义UI效果的绘制和显示。

## 亮点特征

- 同个窗口支持多个帧率：支持为同个窗口的不同内容，比如动画或自绘制UI，定制不同的绘制帧率，不同内容之间独立运行。

- 支持帧率动态配置，兼顾体验与功耗：支持三方框架根据UI场景，动态请求绘制帧率，比如游戏、视频等业务，兼顾流畅体验与功耗体验。
  
- 支持录制回放机制，提升交互体验：支持录制命令的缓存，可对绘制指令进行回放，以提升UI绘制的跟手性。
  
- 支持多种渲染后端：一次开发，支持多种渲染绘制后端，以降低多端适配成本，并满足应用的差异化需求。
  