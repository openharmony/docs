#  Graphics Subsystem Changelog

## cl.graphics.1 Image APIs OH_GetImageInfo() and OH_PixelMap_GetImageInfo() Changed

**Access Level**

Public

**Reason for Change**

During hardware decoding for JPEG images, Direct Memory Access (DMA) is used, which is an aligned memory. Therefore, the method for calculating **rowSize** in **OH_GetImageInfo()** and **OH_PixelMap_GetImageInfo()** is changed.

**Change Impact**

This change is incompatible with earlier versions. The method for calculating **rowSize** is changed.

**API Level**

<11>

**Change Since**

OpenHarmony SDK 4.1.3.1

**rowSize Component**

Before change:

**rowSize**: number of bytes per row. Calculation formula: Image width x Number of bytes in each pixel.

After change:

**rowSize**: number of bytes per row. In the case of DMA, the formula is as follows: Image width x Roundup(64 x Number of bytes per pixel). (The roundup means that each row is automatically padded.) In the case of other types of memory, the formula is as follows: Image width x Number of bytes per pixel.

**Adaptation Guide**

Scenario: The memory address of the pixel map is obtained by calling **OH_PixelMap_AccessPixels()**. When you directly operate the memory, adjust **rowSize**.

Case 1: When OpenCV uses the pixel map data to construct **cv::Mat**, it must include the input parameter **step**.

Before change:

```c++
cv::Mat srv(rows: bitmap.height, cols: bitmap.width, type: CV_8UC4, data: imagePixels);
```

After change:

```c++
cv::Mat srv(rows: bitmap.height, cols: bitmap.width, type: CV_8UC4, data: imagePixels, step: rowSize);
```

Case 2: When you copy the pixel map data, do not include the padding.

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
