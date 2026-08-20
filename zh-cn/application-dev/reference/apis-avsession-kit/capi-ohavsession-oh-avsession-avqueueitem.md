# OH_AVSession_AVQueueItem
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVSession_AVQueueItem {...} OH_AVSession_AVQueueItem
```

## 概述

音视频队列元素的定义。

**起始版本：** 23

**相关模块：** [OHAVSession](capi-ohavsession.md)

**所在头文件：** [native_avqueueitem.h](capi-native-avqueueitem-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t itemId | 资源ID。 |
| [OH_AVSession_AVMediaDescription](capi-ohavsession-oh-avsession-avmediadescription.md) *description | 媒体项信息。 |