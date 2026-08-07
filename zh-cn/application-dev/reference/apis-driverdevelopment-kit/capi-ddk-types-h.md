# ddk_types.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供基础DDK接口所使用的Base DDK类型、枚举值和数据结构。

**引用文件：** <ddk/ddk_types.h>

**库：** libddk_base.z.so

**系统能力：** SystemCapability.Driver.DDK.Extension

**起始版本：** 12

**相关模块：** [Ddk](capi-baseddk.md)

## 汇总

### 结构体

| 名称                                       | typedef关键字 | 描述 |
|------------------------------------------| -- | -- |
| [DDK_Ashmem](capi-baseddk-ddk-ashmem.md) | DDK_Ashmem | 定义通过接口[OH_DDK_CreateAshmem](capi-ddk-api-h.md#oh_ddk_createashmem)创建的共享内存。共享内存的缓冲区提供更好的性能，适用于多个模块之间高效共享大数据量、驱动程序与应用程序之间快速数据交换等需要高性能数据共享的场景。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [DDK_RetCode](#ddk_retcode) | DDK_RetCode | 枚举基本DDK中使用的错误代码。开发者调用DDK接口后，通过检查这些错误码来判断操作是否成功，并根据具体错误码（如参数无效、空指针异常等）进行相应的错误处理。 |

## 枚举类型说明

### DDK_RetCode

```c
enum DDK_RetCode
```

**描述**

枚举基本DDK中使用的错误代码。开发者调用DDK接口后，通过检查这些错误码来判断操作是否成功，并根据具体错误码（如参数无效、空指针异常等）进行相应的错误处理。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| DDK_SUCCESS = 0 | 接口调用成功完成，操作按预期执行。 |
| DDK_FAILURE = 28600001 | 接口调用过程中发生通用错误，操作无法完成。表示操作因非特定原因失败（如资源不足、内部错误等通用错误场景）。 |
| DDK_INVALID_PARAMETER = 28600002 | 传入的参数不符合接口要求，如参数值为空、超出范围或类型不匹配。 |
| DDK_INVALID_OPERATION = 28600003 | 执行了不支持或禁止的操作，如在错误的设备状态下执行操作。 |
| DDK_NULL_PTR = 28600004 | 检测到必要的指针参数为NULL，导致无法继续执行操作。 |


