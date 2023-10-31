# OhosPixelMapCreateOps


## 概述

用于定义创建 pixel map 设置选项的相关信息。

**起始版本：**

10

**相关模块：**

[Image](image.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [width](#width) | 图片的宽, 用pixels表示 | 
| [height](#height) | 图片的高, 用pixels表示 | 
| [pixelFormat](#pixelformat) | 图片的格式 | 
| [editable](#editable) | 图片的编辑类型 | 
| [alphaType](#alphatype) | 图片的alpha类型 | 
| [scaleMode](#scalemode) | 图片的缩放类型 | 


## 结构体成员变量说明


### alphaType

```
uint32_t OhosPixelMapCreateOps::alphaType
```

**描述：**

图片的alpha类型，取值范围如下表所示：

| 值 | 说明 |
| ------ | ----------------------- |
| 0 | 未知透明度。 |
| 1 | 没有alpha或图片全透明。 |
| 2 | RGB前乘alpha。 |
| 3 | RGB不前乘alpha。 |


### editable

```
uint32_t OhosPixelMapCreateOps::editable
```

**描述：**

图片的编辑类型，true为图像像素可编辑，false为不可编辑。


### height

```
uint32_t OhosPixelMapCreateOps::height
```

**描述：**

图片的高, 用pixels表示


### pixelFormat

```
int32_t OhosPixelMapCreateOps::pixelFormat
```

**描述：**

图片的格式，取值范围如下表所示：

| 值 | 说明 |
| ------ | ----------------- |
| 0 | 未知格式。 |
| 2 | 格式为RGB_565 |
| 3 | 格式为RGBA_8888 |
| 4 | 格式为BGRA_8888 |
| 5 | 格式为RGB_888 |
| 6 | 格式为ALPHA_8 |
| 7 | 格式为RGBA_F16 |
| 8 | 格式为NV21 |
| 9 | 格式为NV12 |

### scaleMode

```
uint32_t OhosPixelMapCreateOps::scaleMode
```

**描述：**

图片的缩放类型，取值范围如下表所示：

| 值 | 说明 |
| ------ | -------------------------------------------------- |
| 1 | 缩放图像以填充目标图像区域并居中裁剪区域外的效果。 |
| 0 | 图像适合目标尺寸的效果。 |

### width

```
uint32_t OhosPixelMapCreateOps::width
```

**描述：**

图片的宽, 用pixels表示