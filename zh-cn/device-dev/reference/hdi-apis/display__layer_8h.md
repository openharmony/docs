# display_layer.h


## **概述**

显示图层驱动接口声明。

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
| [LayerFuncs](_layer_funcs.md) | 显示图层驱动接口结构体，定义显示图层驱动接口函数指针。 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [LayerInitialize](_display.md#layerinitialize)(LayerFuncs&nbsp;\*\*funcs) | 实现图层初始化功能，申请图层使用的资源，并获取图层提供的操作接口。 | 
| [LayerUninitialize](_display.md#layeruninitialize)(LayerFuncs&nbsp;\*funcs) | 取消图层初始化功能，释放图层使用到的资源，并释放图层操作接口指针。 | 
