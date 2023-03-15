# display_gralloc.h


## **概述**

显示内存驱动接口声明。

**Since:**

1.0

**Version:**

2.0

**相关模块:**

[Display](_display.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [GrallocFuncs](_gralloc_funcs.md) | 显示内存驱动接口结构体，定义显示内存驱动接口函数指针。 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GrallocInitialize](_display.md#grallocinitialize)(GrallocFuncs&nbsp;\*\*funcs) | 初始化内存模块，并获取内存提供的操作接口。 | 
| [GrallocUninitialize](_display.md#grallocuninitialize)(GrallocFuncs&nbsp;\*funcs) | 取消初始化内存模块，并释放内存操作接口指针。 | 
