# DDK_Ashmem
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## 概述

定义通过接口<b>OH_DDK_CreateAshmem</b>创建的共享内存，共享内存的缓冲区提供更好的性能。

**起始版本：** 12

**相关模块：** [BaseDdk](capi-baseddk.md)

**所在头文件：** [ddk_types.h](capi-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t ashmemFd | 共享内存的文件描述符。 |
| const uint8_t* address | 缓存区地址。 |
| const uint32_t size | 缓存区大小。 |
| uint32_t offset | 已使用缓冲区的偏移量。默认值为0，表示没有偏移，缓冲区从指定地址开始。 |
| uint32_t bufferLength | 使用的缓冲区长度。默认情况下，该值等于size，表示使用整个缓冲区。 |
| uint32_t transferredLength | 传输数据的长度。 |


