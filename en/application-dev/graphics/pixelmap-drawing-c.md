# Drawing Images (C/C++)


A PixelMap is a data structure used to store and represent images in the memory. It is a set of uncompressed pixels. However, images in formats such as JPEG and PNG are compressed. To draw a JPEG or PNG image on the screen, decode the image into a PixelMap. For details, see [Introduction to Image Kit](../media/image/image-overview.md).


Currently, drawing (C/C++) depends on PixelMap, which can be used to read or write image data and obtain image information. For details about the APIs, see [drawing_pixel_map.h](../reference/apis-arkgraphics2d/drawing__pixel__map_8h.md).


There are multiple APIs for creating a PixelMap. The following uses OH_Drawing_PixelMapGetFromOhPixelMapNative() as an example.


1. Adding a Link Library

   Add the following link libraries to the src/main/cpp/CMakeLists.txt file of the Native project:

   ```c++
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)
   ```

2. Creates an OH_PixelmapNative object.

   The PixelMap needs to be obtained from the OH_PixelmapNative object defined by the image framework. Therefore, you need to create OH_PixelmapNative by calling OH_PixelmapNative_CreatePixelmap(). This function takes four parameters. The first parameter is the buffer of the image pixel data, which is used to initialize the pixels of the PixelMap. The second parameter is the buffer length. The third parameter is the PixelMap format (including the length, width, color type, and transparency type). The fourth parameter is the OH_PixelmapNative object, which is used as an output parameter.
   
   ```c++
   // Image width and height
   uint32_t width = 600;
   uint32_t height = 400;
   // Byte length. Each RGBA_8888 pixel occupies 4 bytes.
   size_t bufferSize = width * height * 4;
   uint8_t *pixels = new uint8_t[bufferSize];
   for (uint32_t i = 0; i < width*height; ++i) {
       // Traverse and edit each pixel to form a stripe between red, green, and blue.
       uint32_t n = i / 20 % 3;
       pixels[i*4] = 0x00;
       pixels[i*4+1] = 0x00;
       pixels[i*4+2] = 0x00;
       pixels[i*4+3] = 0xFF;
       if (n == 0) { 
           pixels[i*4] = 0xFF;
       } else if (n == 1) {
           pixels[i*4+1] = 0xFF;
       } else {
           pixels[i*4+2] = 0xFF;
       }
   }
   // Set the PixelMap format (length, width, color type, and transparency type).
   OH_Pixelmap_InitializationOptions *createOps = nullptr;
   OH_PixelmapInitializationOptions_Create(&createOps);
   OH_PixelmapInitializationOptions_SetWidth(createOps, width);
   OH_PixelmapInitializationOptions_SetHeight(createOps, height);
   OH_PixelmapInitializationOptions_SetPixelFormat(createOps, PIXEL_FORMAT_RGBA_8888);
   OH_PixelmapInitializationOptions_SetAlphaType(createOps, PIXELMAP_ALPHA_TYPE_UNKNOWN);
   // Create an OH_PixelmapNative object.
   OH_PixelmapNative *pixelMapNative = nullptr;
   OH_PixelmapNative_CreatePixelmap(pixels, bufferSize, createOps, &pixelMapNative);
   ```

3. Create a **PixelMap** instance.

   Obtain the PixelMap from OH_PixelmapNative by calling OH_Drawing_PixelMapGetFromOhPixelMapNative().

   ```c++
   OH_Drawing_PixelMap *pixelMap = OH_Drawing_PixelMapGetFromOhPixelMapNative(pixelMapNative);
   ```

4. Draw a PixelMap.

   The PixelMap needs to be drawn by calling OH_Drawing_CanvasDrawPixelMapRect(). The function accepts five parameters: canvas, PixelMap object, pixel capture area in PixelMap, area displayed in the canvas, and sampling option object.

   The sampling option object (OH_Drawing_SamplingOptions) represents a specific manner of sampling from original pixel data (that is, a bitmap) to generate a new pixel value. For details, refer to [drawing_sampling_options.h](../reference/apis-arkgraphics2d/drawing__sampling__options_8h.md).

   ```c++
   // Pixel capture area in the PixelMap.
   OH_Drawing_Rect *src = OH_Drawing_RectCreate(0, 0, 600, 400);
   // Area displayed on the canvas.
   OH_Drawing_Rect *dst = OH_Drawing_RectCreate(200, 200, 800, 600);
   Implements sampling options.
   OH_Drawing_SamplingOptions* samplingOptions = OH_Drawing_SamplingOptionsCreate(
       OH_Drawing_FilterMode::FILTER_MODE_LINEAR, OH_Drawing_MipmapMode::MIPMAP_MODE_LINEAR);
   // Draw a PixelMap.
   OH_Drawing_CanvasDrawPixelMapRect(canvas, pixelMap, src, dst, samplingOptions);
   ```

5. Release related objects after the drawing is complete.

   ```c++
   OH_PixelmapNative_Release(pixelMapNative);
   delete[] pixels;
   ```

   The drawing effect is as follows:

   ![Screenshot_20241225200426678](figures/Screenshot_20241225200426678.jpg)
