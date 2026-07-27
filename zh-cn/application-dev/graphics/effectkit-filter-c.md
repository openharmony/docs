# 添加图像效果 (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Multimedia-->
<!--Owner: @hanamaru-->
<!--Designer: @chensiyi_CE-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->

## 场景介绍

在离线处理图像时，可以进行一些图像效果的设置以获取视觉上的不同呈现，比如设置图像模糊程度、调节图像亮度和灰度、设置图像反色等。

主要基于滤镜（Filter）设置不同的图像效果。

## 接口说明

使用滤镜（Filter）设置图像效果的常用接口如下表所示，详细使用和参数请见[effect_filter](../reference/apis-arkgraphics2d/capi-effect-filter-h.md)。

| 接口 | 描述 |
| -------- | -------- |
| EffectErrorCode OH_Filter_CreateEffect(OH_PixelmapNative\* pixelmap, OH_Filter\*\* filter)| 用于创建一个基于像素图对象的滤镜对象。 |
| EffectErrorCode OH_Filter_Blur(OH_Filter\* filter, float radius)| 创建一个模糊效果并且添加到滤镜中。 |
| EffectErrorCode OH_Filter_Brighten(OH_Filter\* filter, float brightness) | 创建一个提亮效果并且添加到滤镜中。 |
| EffectErrorCode OH_Filter_GrayScale(OH_Filter\* filter) | 创建一个灰度效果并且添加到滤镜中。 |
| EffectErrorCode OH_Filter_Invert(OH_Filter\* filter) | 创建一个反色效果并且添加到滤镜中。 |
| EffectErrorCode OH_Filter_GetEffectPixelMap(OH_Filter\* filter, OH_PixelmapNative\*\* pixelmap) | 获取滤镜处理后生成的像素图对象。 |
| EffectErrorCode OH_Filter_Release(OH_Filter\* filter) | 释放滤镜对象。|

## 开发步骤
1. 在Native工程的src/main/cpp/CMakeLists.txt中添加如下链接库：

   ``` C++
   target_link_libraries(entry PUBLIC libnative_drawing.so)
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
   target_link_libraries(entry PUBLIC libnative_effect.so)
   target_link_libraries(entry PUBLIC libpixelmap.so)
   ```

2. 导入依赖的相关头文件。

   ``` C++
   #include "multimedia/image_framework/image/pixelmap_native.h"
   #include "native_effect/effect_filter.h"
   ```

3. 创建OH_PixelmapNative像素图对象。

   创建滤镜需要一个图像框架定义的像素图对象（OH_PixelmapNative）。可以通过OH_PixelmapNative_CreatePixelmap()创建一个自定义的像素图，也可以通过OH_PixelmapNative_ConvertPixelmapNativeFromNapi()从外部引入像素图。
   
   本文以OH_PixelmapNative_CreatePixelmap()为例创建OH_PixelmapNative。该函数接受4个参数，第一个参数为图像像素数据的缓冲区，用于初始化Pixelmap的像素。第二个参数是缓冲区长度。第三个参数是位图格式（包括长、宽、颜色类型、透明度类型等）。第四个参数即OH_PixelmapNative对象，作为出参使用。

   ``` C++
   // 图片宽高分别为 600 * 400
   uint32_t width = 600;
   uint32_t height = 400;
   const uint16_t RGBA_MIN = 0x00;
   const uint16_t RGBA_MAX = 0xFF;
   const uint16_t RGBA_SIZE = 4;
   // 字节长度，RGBA_8888每个像素占4字节
   size_t bufferSize = width * height * RGBA_SIZE;
   uint8_t *pixels = new uint8_t[bufferSize];
   for (uint32_t i = 0; i < width * height; ++i) {
        // 遍历并编辑每个像素，从而形成红绿蓝相间的条纹
        uint32_t n = i / 20 % 3;
        pixels[i * RGBA_SIZE] = RGBA_MIN; // 红色通道
        pixels[i * RGBA_SIZE + 1] = RGBA_MIN; // +1表示绿色通道
        pixels[i * RGBA_SIZE + 2] = RGBA_MIN; // +2表示蓝色通道
        pixels[i * RGBA_SIZE + 3] = RGBA_MAX; // +3表示不透明度通道
        if (n == 0) {
            pixels[i * RGBA_SIZE] = RGBA_MAX; // 红色通道赋值，颜色显红色
        } else if (n == 1) {
            pixels[i * RGBA_SIZE + 1] = RGBA_MAX; // +1表示绿色通道赋值，其余通道为0，颜色显绿色
        } else {
            pixels[i * RGBA_SIZE + 2] = RGBA_MAX; // +2表示蓝色通道赋值，其余通道为0，颜色显蓝色
        }
   }
   // 设置位图格式（长、宽、颜色类型、透明度类型）
   OH_Pixelmap_InitializationOptions *createOps = nullptr;
   OH_PixelmapInitializationOptions_Create(&createOps);
   OH_PixelmapInitializationOptions_SetWidth(createOps, width);
   OH_PixelmapInitializationOptions_SetHeight(createOps, height);
   OH_PixelmapInitializationOptions_SetPixelFormat(createOps, PIXEL_FORMAT_RGBA_8888);
   OH_PixelmapInitializationOptions_SetAlphaType(createOps, PIXELMAP_ALPHA_TYPE_UNKNOWN);
   // 创建OH_PixelmapNative对象
   OH_PixelmapNative *pixelMapNative = nullptr;
   OH_PixelmapNative_CreatePixelmap(pixels, bufferSize, createOps, &pixelMapNative);
   ```

4. 基于上文生成的OH_PixelmapNative像素图对象，使用OH_Filter_CreateEffect()接口初始化OH_Filter对象。

   ``` C++
   OH_Filter *filter = nullptr;
   EffectErrorCode errCodeCreate = OH_Filter_CreateEffect(pixelMapNative, &filter);
   ```

5. 按需给滤镜添加不同的图像效果。
    - 可使用OH_Filter_Blur()接口在滤镜中添加模糊效果。
        
      ``` C++
      float radius = 20.0; // 模糊半径
      EffectErrorCode errCodeEffect = OH_Filter_Blur(filter, radius);
      ```

    - 可使用OH_Filter_Brighten()接口在滤镜中添加提亮效果。
    
      ``` C++
      float brightness = 0.5; // 提亮程度(0~1)
      EffectErrorCode errCodeEffect = OH_Filter_Brighten(filter, brightness);
      ```

    - 可使用OH_Filter_GrayScale()接口在滤镜中添加灰度效果。
    
      ``` C++
      EffectErrorCode errCodeEffect = OH_Filter_GrayScale(filter);
      ```

    - 可使用OH_Filter_Invert()接口在滤镜中添加反色效果。

      ``` C++
      EffectErrorCode errCodeEffect = OH_Filter_Invert(filter);
      ```

6. 获取经过滤镜处理后的OH_PixelmapNative像素图对象。

   ``` C++
   OH_PixelmapNative* filterResult = nullptr;
   EffectErrorCode errCodeResult = OH_Filter_GetEffectPixelMap(filter, &filterResult);
   ```

7. 当不再需要滤镜生成图像效果后，请及时使用OH_Filter_Release()销毁OH_Filter对象。

   ``` C++
   EffectErrorCode errCodeRelease = OH_Filter_Release(filter);
   ```

   绘制效果如下：
   | 图像处理 | 绘制效果 |
   | -------- | -------- |
   | 原始图像 | ![effectfilter_origin](figures/effectfilter_origin.png) |
   | 添加模糊效果 |![effectfilter_blur](figures/effectfilter_blur.png) |
   | 添加提亮效果 |![effectfilter_brighten](figures/effectfilter_brighten.png) |
   | 添加灰度效果 |![effectfilter_grayscale](figures/effectfilter_grayscale.png)  |
   | 添加反色效果 |![effectfilter_invert](figures/effectfilter_invert.png)  |