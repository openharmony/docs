# drawing_brush.h


## **Overview**

**Related Modules:**

[Drawing](_drawing.md)

**Description:**

文件中定义了与画刷相关的功能函数

**Since:**
8
**Version:**
1.0

## **Summary**


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_Drawing_BrushCreate](_drawing.md#ga75e2193d23cf75878c7b2c78d6b23b35)&nbsp;(void) | [OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)&nbsp;\*<br/>函数用于创建一个画刷对象 | 
| [OH_Drawing_BrushDestroy](_drawing.md#ga9dc1d4aa465d06f2d847feddae1558b5)&nbsp;([OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)&nbsp;\*) | void<br/>函数用于销毁画刷对象并回收该对象占有的内存。 | 
| [OH_Drawing_BrushIsAntiAlias](_drawing.md#ga4c861e23b8c0a3fb84d906d81bea5335)&nbsp;(const&nbsp;[OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)&nbsp;\*) | bool<br/>函数用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| [OH_Drawing_BrushSetAntiAlias](_drawing.md#ga41735fc7a2776fbe41c77b3f4637e1c5)&nbsp;([OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)&nbsp;\*,&nbsp;bool) | void<br/>函数用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| [OH_Drawing_BrushGetColor](_drawing.md#ga29dc1e2442cea7e958a5e037c4cc9f59)&nbsp;(const&nbsp;[OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)&nbsp;\*) | uint32_t<br/>函数用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示 | 
| [OH_Drawing_BrushSetColor](_drawing.md#ga4b62aa574623c1a75e14f612a831531b)&nbsp;([OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)&nbsp;\*,&nbsp;uint32_t&nbsp;color) | void<br/>函数用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示 | 
