# Introduction to ArkGraphics 2D

ArkGraphics 2D provides APIs for drawing and displaying graphics. With this set of APIs, you'll find your application development easier and more efficient.

## Available Capabilities

- Basic image processing capabilities, including brightness adjustment, blurring, grayscale adjustment, and color picker. For details, see [@ohos.effectKit (Image Effects)](../reference/apis-arkgraphics2d/js-apis-effectKit.md).

- Basic capabilities for creating and managing color space objects and obtaining basic color space attributes. For details, see [@ohos.graphics.colorSpaceManager (Color Space Management)](../reference/apis-arkgraphics2d/js-apis-colorSpaceManager.md) and [@ohos.graphics.sendableColorSpaceManager (Sendable Color Space Management)](../reference/apis-arkgraphics2d/js-apis-sendableColorSpaceManager.md).

- Capabilities for specifying the frame rate based on the type of content. For details, see [Introduction to Variable Frame Rate](displaysync-overview.md).

- High Dynamic Range (HDR) capability. For details, see [@ohos.graphics.hdrCapability (HDR Capability)](../reference/apis-arkgraphics2d/js-apis-hdrCapability.md).

- Self-drawing capabilities, which you can use to customize and draw UI effects, basic shapes, texts, and images. For details, see [@ohos.graphics.drawing](../reference/apis-arkgraphics2d/js-apis-graphics-drawing.md).

- Native capabilities related to graphics drawing and display. For details, see [NativeWindow](../reference/apis-arkgraphics2d/_native_window.md), [NativeBuffer](../reference/apis-arkgraphics2d/_o_h___native_buffer.md), [NativeImage](../reference/apis-arkgraphics2d/_o_h___native_image.md), [NativeVsync](../reference/apis-arkgraphics2d/_native_vsync.md), and [Drawing](../reference/apis-arkgraphics2d/_drawing.md).

## Use Scenarios

- Image effect processing: You can use the [effectKit module](../reference/apis-arkgraphics2d/js-apis-effectKit.md) to process image effects based on UI effect requirements.

- Setting color spaces: You can use image files and set color space information based on design requirements to draw and display images with a wide color space effect.

- Frame rate customization: You can customize the frame rate for drawing based on different content and requirements. For example, you can set different frame rates for different gaming scenarios and screens to smoothen user experience and balance power consumption.

- Self-drawing scenario: You can use Drawing and other modules to draw and display custom components (except the ArkUI components) or custom UI effects based on different UI effects and scenario requirements.

## Features

- Multiple frame rates in the same window: Different frame rates can be customized for different content in the same window, such as animations or self-drawing UIs. Different content runs independently.

- Dynamic frame rate configuration: A third-party framework can dynamically request the frame rate for drawing based on UI scenarios, such as gaming and videos.
  
- Recording playback: Recording commands can be cached and drawing commands can be played back to improve UI drawing efficiency.
  
- Multiple rendering backends: A set of code can be used for multiple rendering backends. This reduces multi-device adaptation costs and meets differentiated application requirements.
  
