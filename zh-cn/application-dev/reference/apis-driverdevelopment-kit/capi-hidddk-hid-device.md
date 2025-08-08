# Hid_Device
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--SE: @w00373942-->
<!--TSE: @dong-dongzhen-->

## 概述

设备基本信息。

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

**所在头文件：** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const char* deviceName | 设备名称 |
| uint16_t vendorId | 厂商ID |
| uint16_t productId | 产品ID |
| uint16_t version | 版本号 |
| uint16_t bustype | 总线类型 |
| Hid_DeviceProp* properties | 设备特性 |
| uint16_t propLength | 设备特性数量 |


