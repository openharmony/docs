# OhosImageComponent


## 概述

定义图像组成信息。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t \* [byteBuffer](#bytebuffer) | 像素数据地址  | 
| size_t [size](#size) | 内存中的像素数据大小  | 
| int32_t [componentType](#componenttype) | 像素数据类型  | 
| int32_t [rowStride](#rowstride) | 像素数据行宽  | 
| int32_t [pixelStride](#pixelstride) | 像素数据的像素大小  | 


## 结构体成员变量说明


### byteBuffer

```
uint8_t* OhosImageComponent::byteBuffer
```
**描述**
像素数据地址


### componentType

```
int32_t OhosImageComponent::componentType
```
**描述**
像素数据类型

| 值 | 说明 |
| ------ | ----------------------- |
| 1 | OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y 亮度信息 |
| 2 | OHOS_IMAGE_COMPONENT_FORMAT_YUV_U 色度信息 |
| 3 | OHOS_IMAGE_COMPONENT_FORMAT_YUV_V 色差值信息 |
| 4 | OHOS_IMAGE_COMPONENT_FORMAT_JPEG Jpeg 格式 |

### pixelStride

```
int32_t OhosImageComponent::pixelStride
```
**描述**
像素数据的像素大小


### rowStride

```
int32_t OhosImageComponent::rowStride
```
**描述**
像素数据行宽，读取相机预览流数据时，需要考虑按stride进行读取，具体用法见[C/C++预览流二次处理示例](../../media/camera/native-camera-preview-imageReceiver.md)。


### size

```
size_t OhosImageComponent::size
```
**描述**
内存中的像素数据大小
