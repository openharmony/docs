# AVSession_OutputDeviceInfo
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct AVSession_OutputDeviceInfo {...} AVSession_OutputDeviceInfo
```

## 概述

输出设备信息的定义。

**起始版本：** 23

**相关模块：** [OHAVSession](capi-ohavsession.md)

**所在头文件：** [native_deviceinfo.h](capi-native-deviceinfo-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t size | 设备信息数组的大小，表示deviceInfos数组的元素数量。 |
| [AVSession_DeviceInfo](capi-ohavsession-avsession-deviceinfo.md) **deviceInfos | 指向设备信息数组的指针，数组长度由size字段指定。 |