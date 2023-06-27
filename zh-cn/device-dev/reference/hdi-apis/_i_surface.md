# ISurface


## 概述

用于存放窗口相关信息的结构体定义，提供给硬件加速使用，例如图像合成，位图搬移等操作。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [phyAddr](_display.md#phyaddr-23) | uint64_t<br/>图像首地址 | 
| [height](_display.md#height-48) | int32_t<br/>图像高度 | 
| [width](_display.md#width-49) | int32_t<br/>图像宽度 | 
| [stride](_display.md#stride-12) | int32_t<br/>图像跨度 | 
| [enColorFmt](_display.md#encolorfmt) | [PixelFormat](_display.md#pixelformat)<br/>图像格式 | 
| [bYCbCrClut](_display.md#bycbcrclut) | bool<br/>CLUT表是否位于&nbsp;YCbCr&nbsp;空间 | 
| [bAlphaMax255](_display.md#balphamax255) | bool<br/>图像alpha最大值为255还是128 | 
| [bAlphaExt1555](_display.md#balphaext1555) | bool<br/>是否使能1555的Alpha扩展 | 
| [alpha0](_display.md#alpha0-22) | uint8_t<br/>Alpha0值，取值范围：[0,255] | 
| [alpha1](_display.md#alpha1-22) | uint8_t<br/>Alpha1值，取值范围：[0,255] | 
| [cbcrPhyAddr](_display.md#cbcrphyaddr) | uint64_t<br/>CbCr分量地址 | 
| [cbcrStride](_display.md#cbcrstride) | int32_t<br/>CbCr分量跨度 | 
| [clutPhyAddr](_display.md#clutphyaddr) | uint64_t<br/>Clut表首地址，用作颜色扩展或颜色校正 | 
