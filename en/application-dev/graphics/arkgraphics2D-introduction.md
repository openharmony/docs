# About This Kit

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @goumiao; @hangmengxin-->
<!--Designer: @liumingxiang; @wanyanglan-->
<!--Tester: @yhl0101; @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=4e8c8649f5f2efb4d6a6d42fbee5df7e42731663 translatedAt=2026-08-03T11:15:22.838Z pushedAt=2026-08-04T01:41:11.694Z -->

ArkGraphics 2D provides APIs for drawing and displaying graphics. With this set of APIs, you'll find your application development easier and more efficient.

## Available Capabilities

- Basic image processing capabilities, including brightness adjustment, blurring, grayscale adjustment, and color picker. For details, see [@ohos.effectKit (Image Effects)](../reference/apis-arkgraphics2d/js-apis-effectKit.md).

- Basic capabilities for creating and managing color space objects and obtaining basic color space attributes. For details, see [@ohos.graphics.colorSpaceManager (Color Space Management)](../reference/apis-arkgraphics2d/js-apis-colorSpaceManager.md) and [@ohos.graphics.sendableColorSpaceManager (Sendable Color Space Management)](../reference/apis-arkgraphics2d/js-apis-sendableColorSpaceManager.md).

- Capabilities for specifying the frame rate based on the type of content. For details, see [Introduction to Variable Frame Rate](displaysync-overview.md).

- High Dynamic Range (HDR) capability. For details, see [@ohos.graphics.hdrCapability (HDR Capability)](../reference/apis-arkgraphics2d/js-apis-hdrCapability.md).

- Self-drawing capabilities, which you can use to customize and draw UI effects, basic shapes, texts, and images. For details, see [@ohos.graphics.drawing](../reference/apis-arkgraphics2d/arkts-apis-graphics-drawing.md).

- Native capabilities related to graphics drawing and display. For details, see [NativeWindow](../reference/apis-arkgraphics2d/capi-nativewindow.md), [NativeBuffer](../reference/apis-arkgraphics2d/capi-oh-nativebuffer.md), [NativeImage](../reference/apis-arkgraphics2d/capi-oh-nativeimage.md), [NativeVsync](../reference/apis-arkgraphics2d/capi-nativevsync.md), and [Drawing](../reference/apis-arkgraphics2d/capi-drawing.md).

## Use Scenarios

- Applying image effects: You can use [@ohos.effectKit (image effect)](../reference/apis-arkgraphics2d/js-apis-effectKit.md) to apply image effects based on different UI effect requirements, thereby improving the browsing experience.

- Setting color spaces: You can use image files and set color space information based on design requirements to draw and display images with a wide color space effect.

- Frame rate customization: You can customize the frame rate for drawing based on different content and requirements. For example, you can set different frame rates for different gaming scenarios and screens to smoothen user experience and balance power consumption.

- Self-drawing scenario: You can use Drawing and other modules to draw and display custom components (except the ArkUI components) or custom UI effects based on different UI effects and scenario requirements.

## Features

- Multiple frame rates in the same window: Different frame rates can be customized for different content in the same window, such as animations or self-drawing UIs. Different content runs independently.

- Dynamic frame rate configuration: A third-party framework can dynamically request the frame rate for drawing based on UI scenarios, such as gaming and videos.

- Recording playback: Recording commands can be cached and drawing commands can be played back to improve UI drawing efficiency.

- Multiple rendering backends: A set of code can be used for multiple rendering backends. This reduces multi-device adaptation costs and meets differentiated application requirements.

<!--RP1-->
<!--RP1End-->