# drawing_sampling_options.h


## 概述

文件中定义了与采样相关的功能函数。用于图片或者纹理等图像的采样。

**引用文件：**&lt;native_drawing/drawing_sampling_options.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode)  [OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode) | 过滤模式枚举。 |
| typedef enum [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode)  [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode) | 多级渐远纹理模式枚举。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode) { FILTER_MODE_NEAREST, FILTER_MODE_LINEAR } | 过滤模式枚举。 |
| [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode) { MIPMAP_MODE_NONE, MIPMAP_MODE_NEAREST, MIPMAP_MODE_LINEAR } | 多级渐远纹理模式枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \* [OH_Drawing_SamplingOptionsCreate](_drawing.md#oh_drawing_samplingoptionscreate) ([OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode), [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode)) | 创建一个采样选项对象。 |
| void [OH_Drawing_SamplingOptionsDestroy](_drawing.md#oh_drawing_samplingoptionsdestroy) ([OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | 销毁采样选项对象并回收该对象占有内存。 |
