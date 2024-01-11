#  图形图像子系统ChangeLog

## cl.图形图像.1 Image NDK接口OH_GetImageInfo()、OH_PixelMap_GetImageInfo()变更

**访问级别**

公开接口

**变更原因**

Jpeg图片支持硬解码，申请的内存为DMA内存，是一块对齐的内存。因此更改了OH_GetImageInfo()、OH_PixelMap_GetImageInfo()的rowSize计算方式。

**变更影响**

该变更为非兼容变更，NDK接口OhosPixelMapInfos和OhosPixelMapInfo的rowSize计算方式变化。

**API Level**

<11>

**变更发生版本**

从OpenHarmony SDK 4.1.3.1开始。

**rowSize组件**

变更前：

rowSize，每行的byte数，计算方式：图片的宽 * 每个像素字节数。

变更后：

rowSize，每行的byte数，计算方式：DMA内存为图片的宽 * 每个像素字节数的64倍向上取整（每行末尾会自动补齐）；其他内存为图片的宽 * 每个像素字节数。

**适配指导**

场景：通过NDK接口如OH_PixelMap_AccessPixels()，获取到pixelmap的内存地址，直接操作内存时，需要对rowSize进行适配。

案例1：openCV在处理pixelmap的位图数据时需要通过pixelmap的位图数据构建openCV中的cv::Mat, 需要增加step入参，

变更前：

```c++
cv::Mat srv(rows: bitmap.height, cols: bitmap.width, type: CV_8UC4, data: imagePixels);
```

变更后：

```c++
cv::Mat srv(rows: bitmap.height, cols: bitmap.width, type: CV_8UC4, data: imagePixels, step: rowSize);
```

案例2:拷贝pixelmap的位图数据，需要跳过padding区域。

```c++
for (int i = 0; i < imageInfo_.size.height; ++i) {
    errno_t ret = memcpy_s(dst, rowDataSize_, src_ + i * rowStride_, rowDataSize_);
    if (ret != 0) {
        Hilog::Error(LABLE, "read pixels by buffer memcpy the pixelmap data to dst fail, error:%{public}d", ret);
        return ERROR_IMAGE_READ_PIXECLMAP_FAILED;
    }
    dst += rowDataSize_;
}
```
