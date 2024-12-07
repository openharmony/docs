# input_manager.h


## 概述

描述Input设备管理相关的接口声明。

引用：

- [input_controller.h](input__controller_8h.md)

- [input_reporter.h](input__reporter_8h.md)

- [input_type.h](input__type_8h.md)

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[InputManager](_input_manager.md) | 提供Input设备管理相关的接口。  | 
| struct&nbsp;&nbsp;[IInputInterface](_i_input_interface.md) | 定义用于提供Input设备驱动程序功能的接口。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [GetInputInterface](_input.md#getinputinterface) ([IInputInterface](_i_input_interface.md) \*\*interface) | Input服务通过调用此接口获取操作Input设备的所有接口。  | 
