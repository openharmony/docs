# ddk_api.h


## 概述

声明主机侧访问设备的BASE DDK接口。

**起始版本：** 

12

**相关模块：**

[BASE DDK](_base_ddk.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_DDK_CreateAshmem](_base_ddk.md#oh_ddk_createashmem) (const uint8_t *name, [DDK_Ashmem](_ddk_ashmem.md) \*\*ashmem) | 创建共享内存。  | 
| [OH_DDK_MapAshmem](_base_ddk.md#oh_ddk_mapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem), const uint8_t ashmemMapType) | 共享内存映射。  | 
| [OH_DDK_UnmapAshmem](_base_ddk.md#oh_ddk_unmapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | 取消共享内存映射。  | 
| [OH_DDK_DestoryAshmem](_base_ddk.md#oh_ddk_destoryashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | 销毁共享内存。  | 
