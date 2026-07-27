# DRM_Statistics
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_Statistics {...} DRM_Statistics
```

## 概述

MediaKeySystem（媒体密钥系统）的度量信息。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t statisticsCount | 度量信息的数量，表示statisticsName和statisticsDescription数组中有效元素的个数。取值范围为[0, MAX_STATISTICS_COUNT]。 |
| char statisticsName[MAX_STATISTICS_COUNT][MAX_STATISTICS_NAME_LEN] | 度量信息名称数组，每行存储一个度量项的名称。常见度量名称由DRM解决方案定义，如"DecryptionOperations"（解密操作次数）、"KeySessions"（密钥会话数）等。数组维度由MAX_STATISTICS_COUNT和MAX_STATISTICS_NAME_LEN宏定义。 |
| char statisticsDescription[MAX_STATISTICS_COUNT][MAX_STATISTICS_BUFFER_LEN] | 度量信息描述数组，每行存储对应statisticsName的度量值。描述内容由DRM解决方案定义，可能包含数值、百分比或其他格式的统计数据。数组维度由MAX_STATISTICS_COUNT和MAX_STATISTICS_BUFFER_LEN宏定义。 |


