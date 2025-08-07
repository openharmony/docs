# ffrt_queue_attr_t

## 概述

串行队列属性结构。

**起始版本：** 10

**相关模块：** [FFRT](capi-ffrt.md)

**所在头文件：** [type_def.h](capi-type-def-h.md)

## 汇总

### 成员函数

| 名称 | 描述 |
| -- | -- |
| [uint32_t storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)]](#sizeof) | 串行队列属性所占空间 |

## 成员函数说明

### sizeof()

```
uint32_t storage[(ffrt_queue_attr_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)]
```

**描述**

串行队列属性所占空间


