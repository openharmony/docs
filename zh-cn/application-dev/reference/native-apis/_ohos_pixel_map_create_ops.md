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

图片的alpha类型


### editable

```
uint32_t OhosPixelMapCreateOps::editable
```

**描述：**

图片的编辑类型


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

图片的格式

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | 未知格式。        |
| RGB_565                | 2      | 格式为RGB_565     |
| RGBA_8888              | 3      | 格式为RGBA_8888 |
| BGRA_8888<sup>9+</sup> | 4      | 格式为BGRA_8888 |
| RGB_888<sup>9+</sup>   | 5      | 格式为RGB_888   |
| ALPHA_8<sup>9+</sup>   | 6      | 格式为ALPHA_8   |
| RGBA_F16<sup>9+</sup>  | 7      | 格式为RGBA_F16  |
| NV21<sup>9+</sup>      | 8      | 格式为NV21      |
| NV12<sup>9+</sup>      | 9      | 格式为NV12      |

### editable

```
boolean OhosPixelMapCreateOps::editable
```

**描述：**

图片的编辑类型

| 名称       | 类型    | 可读 | 可写 | 说明                       |
| ---------- | ------- | ---- | ---- | -------------------------- |
| editable | boolean | 是   | 否   | 设定是否图像像素可被编辑。 |

### alphaType

```
uint32_t OhosPixelMapCreateOps::alphaType
```

**描述：**

图片的alpha类型

| 名称     |   值   | 说明                    |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | 未知透明度。            |
| OPAQUE   | 1      | 没有alpha或图片全透明。 |
| PREMUL   | 2      | RGB前乘alpha。         |
| UNPREMUL | 3      | RGB不前乘alpha。       |

### scaleMode

```
uint32_t OhosPixelMapCreateOps::scaleMode
```

**描述：**

图片的缩放类型

| 名称            |   值   | 说明                                               |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | 缩放图像以填充目标图像区域并居中裁剪区域外的效果。 |
| FIT_TARGET_SIZE | 0      | 图像适合目标尺寸的效果。                           |

### width

```
uint32_t OhosPixelMapCreateOps::width
```

**描述：**

图片的宽, 用pixels表示