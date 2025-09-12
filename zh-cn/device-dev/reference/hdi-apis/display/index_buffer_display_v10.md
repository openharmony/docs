# Display (V1_0)


## 概述

显示模块驱动接口定义。

提供给上层图形服务使用的驱动接口，包括图层管理、设备控制、显示内存管理等相关接口。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [DisplayBufferType.idl](files_buffer_display_v10_display_buffer_type_8idl.md) | 显示内存类型定义，定义显示内存操作相关接口所使用的数据类型。 | 
| [IAllocator.idl](files_buffer_display_v10_i_allocator_8idl.md) | 显示内存分配接口声明。 | 
| [IMapper.idl](files_buffer_display_v10_i_mapper_8idl.md) | 显示内存映射接口声明。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[AllocInfo](annotated_buffer_display_v10_alloc_info.md) | 定义待分配内存的信息。 | 
| struct&nbsp;&nbsp;[VerifyAllocInfo](annotated_buffer_display_v10_verify_alloc_info.md) | 用于验证内存分配信息的结构体定义。 | 
| interface&nbsp;&nbsp;[IAllocator](annotated_buffer_display_v10_interface_i_allocator.md) | 定义显示内存分配接口。 | 
| interface&nbsp;&nbsp;[IMapper](annotated_buffer_display_v10_interface_i_mapper.md) | 定义释放显示内存接口。 | 
