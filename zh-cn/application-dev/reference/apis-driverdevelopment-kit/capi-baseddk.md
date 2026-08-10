# Ddk
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供Base DDK接口，包括创建、映射、取消映射以及销毁共享内存。

**起始版本：** 12

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [ddk_api.h](capi-ddk-api-h.md) | 声明主机侧访问的Base DDK接口。提供共享内存的创建、映射、销毁等功能，支持开发者在驱动程序中高效管理共享内存资源，适用于需要与驱动侧共享数据的场景，有助于简化内存管理、提升数据传输效率。 |
| [ddk_types.h](capi-ddk-types-h.md) | 提供基础DDK接口所使用的Base DDK类型、枚举值和数据结构。 |
