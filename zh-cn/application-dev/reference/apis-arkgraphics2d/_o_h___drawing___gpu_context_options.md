# OH_Drawing_GpuContextOptions


## 概述

定义有关图形处理器上下文的选项。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)

**所在头文件：**[drawing_gpu_context.h](drawing__gpu__context_8h.md)

**废弃：** 从API version 18开始废弃。

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| bool [allowPathMaskCaching](#allowpathmaskcaching) | 用于控制是否启用路径蒙版缓存，如果为true，则允许缓存路径蒙版纹理，如果为false，则不允许。 | 


## 结构体成员变量说明


### allowPathMaskCaching

```
bool OH_Drawing_GpuContextOptions::allowPathMaskCaching
```

**描述**

用于控制是否启用路径蒙版缓存，如果为true，则允许缓存路径蒙版纹理，如果为false，则不允许。
