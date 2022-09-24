# ISurface


## **概述**

**所属模块:**

[Display](_display.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [phyAddr](_display.md#phyaddr-22) | 图像首地址 | 
| [height](_display.md#height-47) | 图像高度 | 
| [width](_display.md#width-47) | 图像宽度 | 
| [stride](_display.md#stride) | 图像跨度 | 
| [enColorFmt](_display.md#encolorfmt) | 图像格式 | 
| [bYCbCrClut](_display.md#bycbcrclut) | CLUT表是否位于YCbCr空间 | 
| [bAlphaMax255](_display.md#balphamax255) | 图像Alpha最大值为255还是128 | 
| [bAlphaExt1555](_display.md#balphaext1555) | 是否使能1555的Alpha扩展 | 
| [alpha0](_display.md#alpha0-22) | Alpha0值，取值范围：[0,255] | 
| [alpha1](_display.md#alpha1-22) | Alpha1值，取值范围：[0,255] | 
| [cbcrPhyAddr](_display.md#cbcrphyaddr) | CbCr分量地址 | 
| [cbcrStride](_display.md#cbcrstride) | CbCr分量跨度 | 
| [clutPhyAddr](_display.md#clutphyaddr) | CLUT表首地址，用作颜色扩展或颜色校正。| 


## **详细描述**

用于存放窗口相关信息的结构体定义，提供给硬件加速使用，例如图像合成，位图搬移等操作。
