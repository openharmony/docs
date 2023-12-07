#  图形图像子系统ChangeLog

## cl.图形图像.1 Image NDK接口OH_GetImageInfo()、OH_PixelMap_GetImageInfo()变更

**访问级别**

公开接口

**变更原因**

Jpeg图片支持硬解码，申请的内存为DMA内存，是一块对齐的内存。因此更改了OH_GetImageInfo()、OH_PixelMap_GetImageInfo()的rowSize计算方式。

**变更影响**

该变更为非兼容变更，NDK接口OhosPixelMapInfos和OhosPixelMapInfo的rowSize计算方式变化。

**变更发生版本**

从OpenHarmony SDK 4.1.3.1开始。

**rowSize组件**

变更前：

rowSize，每行的byte数，计算方式：图片的宽 * 每个像素字节数。

变更后：

rowSize，每行的byte数，计算方式：DMA内存为图片的宽 * 每个像素字节数 + padding；其他内存为图片的宽 * 每个像素字节数。

**适配指导**

开发者需要根据新的rowSize计算值，进行相应适配。
