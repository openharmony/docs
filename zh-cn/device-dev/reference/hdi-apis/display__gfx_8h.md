# display_gfx.h


## 概述

显示硬件加速驱动接口声明。

**Since:**
1.0
**Version:**
1.0
**相关模块:**

[Display](_display.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [GfxFuncs](_gfx_funcs.md) | struct<br/>显示硬件加速驱动接口结构体，定义硬件加速驱动接口函数指针。&nbsp; | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GfxInitialize](_display.md#gfxinitialize)&nbsp;([GfxFuncs](_gfx_funcs.md)&nbsp;\*\*funcs) | int32_t<br/>获取硬件加速相关的操作接口指针。&nbsp; | 
| [GfxUninitialize](_display.md#gfxuninitialize)&nbsp;([GfxFuncs](_gfx_funcs.md)&nbsp;\*funcs) | int32_t<br/>释放硬件加速相关的操作接口指针。&nbsp; | 
