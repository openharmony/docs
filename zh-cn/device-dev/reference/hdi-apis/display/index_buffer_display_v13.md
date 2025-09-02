# Display (V1_2)


## 概述

显示模块驱动接口定义。

提供给上层图形服务使用的驱动接口，包括图层管理、设备控制、显示内存管理等相关接口。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [DisplayBufferType.idl](files_buffer_display_v12_display_buffer_type_8idl.md) | 显示内存类型定义，定义显示内存操作相关接口所使用的数据类型。 | 
| [IMapper.idl](files_buffer_display_v12_i_mapper_8idl.md) | 显示内存映射接口声明。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ImagePlane](annotated_buffer_display_v12_image_plane.md) | 定义UV偏移信息。 | 
| struct&nbsp;&nbsp;[ImageLayout](annotated_buffer_display_v12_image_layout.md) | 定义格式和位置相关信息。 | 
| interface&nbsp;&nbsp;[IMapper](annotated_buffer_display_v12_interface_i_mapper.md) | 定义释放显示内存接口，基于v1_0.IMapper增加获取图像位置接口GetImageLayout。 | 
