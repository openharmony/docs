# drawing_bitmap.h


## **Overview**

**Related Modules:**

[Drawing](_drawing.md)

**Description:**

文件中定义了与位图相关的功能函数

**Since:**
8
**Version:**
1.0

## **Summary**


### Classes

  | Classe&nbsp;Name | Description | 
| -------- | -------- |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_Drawing_BitmapCreate](_drawing.md#gac2d33ba4b18e71eca8c41c136004ba48)&nbsp;(void) | [OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)&nbsp;\*<br/>函数用于创建一个位图对象。 | 
| [OH_Drawing_BitmapDestroy](_drawing.md#ga5c31becccf1d3ad5df5f6bc7d9007b8f)&nbsp;([OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)&nbsp;\*) | void<br/>函数用于销毁位图对象并回收该对象占有内存。 | 
| [OH_Drawing_BitmapBuild](_drawing.md#ga699afe9c4d2665cdd21b5d9b6dfed2ec)&nbsp;([OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)&nbsp;\*,&nbsp;const&nbsp;uint32_t&nbsp;width,&nbsp;const&nbsp;uint32_t&nbsp;height,&nbsp;const&nbsp;[OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md)&nbsp;\*) | void<br/>函数用于初始化位图对象的宽度和高度，并且为该位图设置像素格式 | 
| [OH_Drawing_BitmapGetWidth](_drawing.md#ga67b83650847ab1f6e79ca122905d55a3)&nbsp;([OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)&nbsp;\*) | uint32_t<br/>该函数用于获取指定位图的宽度 | 
| [OH_Drawing_BitmapGetHeight](_drawing.md#gace471d69bec5b152bd4de5fa8504f7fd)&nbsp;([OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)&nbsp;\*) | uint32_t<br/>函数用于获取指定位图的高度 | 
| [OH_Drawing_BitmapGetPixels](_drawing.md#gaf007f52cfbcbc63cd02971c6480c55fb)&nbsp;([OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)&nbsp;\*) | void&nbsp;\*<br/>函数用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据 | 
