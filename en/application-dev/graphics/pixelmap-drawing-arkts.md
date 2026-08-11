# Drawing Images (ArkTS)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=3c9498a5af1cedc12000d743f1689bf266862723 translatedAt=2026-08-03T11:21:32.384Z pushedAt=2026-08-04T07:16:19.685Z -->

A pixel map is a data structure used to store and represent images in memory. It is an uncompressed collection of pixels. Images in formats such as JPEG or PNG are compressed, which are different from pixel maps. If you need to draw JPEG or PNG images on the screen, decode them into the pixel map format first. For details about image decoding, see [Introduction to Image Kit](../media/image/image-overview.md).

Drawing pixel maps using the **Drawing** APIs (ArkTS) depends on the **PixelMap** module, which can read or write image data and obtain image information. For details about **PixelMap** APIs, see [PixelMap](../reference/apis-image-kit/arkts-apis-image-PixelMap.md).

1. Create a **PixelMap** instance.

   You can create a **PixelMap** instance using multiple APIs. The following uses **createPixelMapSync()** as an example. For details about other ways and APIs, see the [@ohos.multimedia.image](../reference/apis-image-kit/arkts-apis-image.md) module.

   <!-- @[arkts_graphics_draw_image](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/PixelMapDrawing.ets) -->

   ``` TypeScript
   // Image width and height.
   let width = 600;
   let height = 400;
   // Byte length. Each RGBA_8888 pixel occupies 4 bytes.
   let byteLength = width * height * 4;
   const color: ArrayBuffer = new ArrayBuffer(byteLength);
   let bufferArr = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i += 4) {
     // Traverse and edit each pixel to form red, green, and blue stripes.
     bufferArr[i] = 0x00;
     bufferArr[i+1] = 0x00;
     bufferArr[i+2] = 0x00;
     bufferArr[i+3] = 0xFF;
     let n = Math.floor(i / 80) % 3;
     if (n == 0) {
       bufferArr[i] = 0xFF;
     } else if (n == 1) {
       bufferArr[i+1] = 0xFF;
     } else {
       bufferArr[i+2] = 0xFF;
     }
   }
   // Set pixel attributes.
   let opts: image.InitializationOptions =
     { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: height, width: width } };
   // Create a PixelMap instance.
   pixelMap = image.createPixelMapSync(color, opts);
   ```

2. (Optional) Edit the pixels in the **PixelMap** instance. If no pixel needs to be edited, skip this step.

   You can edit the pixels in the **PixelMap** instance using multiple APIs. The following uses **writePixelsSync()** as an example. For details about other ways and APIs, see [PixelMap](../reference/apis-image-kit/arkts-apis-image-PixelMap.md).

   <!-- @[arkts_graphics_draw_edit_pixel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/PixelMapDrawing.ets) -->

   ``` TypeScript
   // Set the width and height of the editing area.
   let innerWidth = 400;
   let innerHeight = 200;
   // Byte length of the editing area. Each RGBA_8888 pixel occupies 4 bytes.
   let innerByteLength = innerWidth * innerHeight * 4;
   const innerColor: ArrayBuffer = new ArrayBuffer(innerByteLength);
   let innerBufferArr = new Uint8Array(innerColor);
   for (let i = 0; i < innerBufferArr.length; i += 4) {
     // Set the pixels in the editing area to black and white stripes.
     let n = Math.floor(i / 80) % 2;
     if (n == 0) {
       innerBufferArr[i] = 0x00;
       innerBufferArr[i+1] = 0x00;
       innerBufferArr[i+2] = 0x00;
     } else {
       innerBufferArr[i] = 0xFF;
       innerBufferArr[i+1] = 0xFF;
       innerBufferArr[i+2] = 0xFF;
     }
     innerBufferArr[i+3] = 0xFF;
   }
   // Set the pixels, width, height, and offset of the editing area.
   const area: image.PositionArea = {
     pixels: innerColor,
     offset: 0,
     stride: innerWidth * 4,
     region: { size: { height: innerHeight, width: innerWidth }, x: 100, y: 100 }
   };
   // Edit the pixel map to form the middle black and white stripes.
   pixelMap.writePixelsSync(area);
   // To display the image completely, change the start point to (0, 0).
   canvas.drawImage(pixelMap, 0, 0);
   ```

3. Draw the pixel map.

   Use the **Canvas** APIs to draw the pixel map. The following uses **drawImage()** as an example. For details about other ways and APIs, see [drawing.Canvas](../reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Canvas.md).

   The **drawImage()** function takes four parameters: (1) **PixelMap** created; (2) X coordinate of the upper left corner of the drawn image; (3) Y coordinate of the upper left corner; (4) sampling option object. By default, the original sampling option object is constructed without any parameter.

   <!-- @[arkts_graphics_draw_image_pixel_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/PixelMapDrawing.ets) -->

   ``` TypeScript
   // To display the image completely, change the start point to (0, 0).
   canvas.drawImage(pixelMap, 0, 0);
   ```

   The drawing effect is as follows:

   ![Drawing the pixel map](figures/Draw-the-pixel-map.png)

<!--RP1-->

## Samples

The following samples are provided to help you better understand how to use the **Drawing** APIs (ArkTS) for development:

- [ArkTSGraphicsDraw (API20)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw)

<!--RP1End-->