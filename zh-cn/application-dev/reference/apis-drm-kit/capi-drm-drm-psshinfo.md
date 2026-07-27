# DRM_PsshInfo
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_PsshInfo {...} DRM_PsshInfo
```

## 概述

 DRM内容保护系统专用头（Protection System Specific Header）信息。
 
**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t uuid[DRM_UUID_LEN] | DRM系统的UUID（通用唯一标识符），用于唯一标识一个DRM内容保护系统。UUID长度为16字节，由DRM解决方案提供商分配。常见DRM系统的UUID可参考相关DRM规范。 |
| int32_t dataLen | PSSH数据的长度，表示data数组中有效数据的字节数。单位为字节（Byte），取值范围为[0, MAX_PSSH_DATA_LEN]。 |
| uint8_t data[MAX_PSSH_DATA_LEN] | PSSH数据，包含DRM系统特定的初始化数据。数据格式由DRM解决方案定义，通常包含密钥ID、内容ID等信息。数组长度由MAX_PSSH_DATA_LEN宏定义。 |


