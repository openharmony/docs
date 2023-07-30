# OHOS::Media::OhosImageComponent


## 概述

定义图像组成信息。

**起始版本：**

10

**相关模块：**

[Image](image.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [byteBuffer](#bytebuffer) | 像素数据地址 | 
| [size](#size) | 内存中的像素数据大小 | 
| [componentType](#componenttype) | 像素数据类型 | 
| [rowStride](#rowstride) | 像素数据行宽 | 
| [pixelStride](#pixelstride) | 像素数据的像素大小 | 


## 结构体成员变量说明


### byteBuffer

```
uint8_t* OHOS::Media::OhosImageComponent::byteBuffer
```

**描述：**

像素数据地址


### componentType

```
int32_t OHOS::Media::OhosImageComponent::componentType
```

**描述：**

像素数据类型


### pixelStride

```
int32_t OHOS::Media::OhosImageComponent::pixelStride
```

**描述：**

像素数据的像素大小


### rowStride

```
int32_t OHOS::Media::OhosImageComponent::rowStride
```

**描述：**

像素数据行宽


### size

```
size_t OHOS::Media::OhosImageComponent::size
```

**描述：**

内存中的像素数据大小
