# media_types.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 概述

声明了常见媒体类型的定义。

**引用文件：** <multimedia/player_framework/media_types.h>

**库：** libnative_media_core.so

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 18

**相关模块：** [Core](capi-core.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Core_HdrType](#oh_core_hdrtype) | OH_Core_HdrType | HDR类型枚举。 |

## 枚举类型说明

### OH_Core_HdrType

```
enum OH_Core_HdrType
```

**描述**

HDR类型枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| OH_CORE_HDR_TYPE_NONE = 0 | 此选项用于标记非HDR类型。 |
| OH_CORE_HDR_TYPE_VIVID = 1 | 此选项用于标记HDR Vivid类型。 |


