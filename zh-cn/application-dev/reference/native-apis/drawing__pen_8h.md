# drawing_pen.h


## **Overview**

**Related Modules:**

[Drawing](_drawing.md)

**Description:**

文件中定义了与画笔相关的功能函数

**Since:**
8
**Version:**
1.0

## **Summary**


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| [OH_Drawing_PenLineCapStyle](_drawing.md#gafa9d815d933e0fd6aa7549d12080fa8f)&nbsp;{&nbsp;[LINE_FLAT_CAP](_drawing.md#ggafa9d815d933e0fd6aa7549d12080fa8fa99c48cc6172088f1a86e8688e347933a),&nbsp;[LINE_SQUARE_CAP](_drawing.md#ggafa9d815d933e0fd6aa7549d12080fa8fac9929c30114c046b75b844e459f1e69f),&nbsp;[LINE_ROUND_CAP](_drawing.md#ggafa9d815d933e0fd6aa7549d12080fa8fa0efe3fb7b56d7407737c42aebe5b91e5)&nbsp;} | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式 | 
| [OH_Drawing_PenLineJoinStyle](_drawing.md#gad10001f23f6c42f97a392cba30011460)&nbsp;{&nbsp;[LINE_MITER_JOIN](_drawing.md#ggad10001f23f6c42f97a392cba30011460a126e5fbae0f63b8431d3a6763035d488),&nbsp;[LINE_ROUND_JOIN](_drawing.md#ggad10001f23f6c42f97a392cba30011460aa2bfcc7c744ab7a56c047942060ad3ba),&nbsp;[LINE_BEVEL_JOIN](_drawing.md#ggad10001f23f6c42f97a392cba30011460a8ad7df33f8ff73c5c080fcf159631fde)&nbsp;} | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_Drawing_PenCreate](_drawing.md#gae52fe4132b90726d813661750948e2dd)&nbsp;(void) | [OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*<br/>函数用于创建一个画笔对象 | 
| [OH_Drawing_PenDestroy](_drawing.md#ga907538d02a50836e8033a3f7bf12c80e)&nbsp;([OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | void<br/>函数用于销毁画笔对象并回收该对象占有的内存 | 
| [OH_Drawing_PenIsAntiAlias](_drawing.md#ga31dee499a3d1dd81e526bcc1dd620961)&nbsp;(const&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | bool<br/>函数用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| [OH_Drawing_PenSetAntiAlias](_drawing.md#ga93dbc44cf424038a17ae311920550283)&nbsp;([OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*,&nbsp;bool) | void<br/>函数用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| [OH_Drawing_PenGetColor](_drawing.md#ga8a8db886ecf41a729e40a1f760338220)&nbsp;(const&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | uint32_t<br/>函数用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示 | 
| [OH_Drawing_PenSetColor](_drawing.md#ga6e5b065f521dd9c41d5e7f2af5c379cb)&nbsp;([OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*,&nbsp;uint32_t&nbsp;color) | void<br/>函数用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示 | 
| [OH_Drawing_PenGetWidth](_drawing.md#ga3d898184f61b685d724e6d272fb12168)&nbsp;(const&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | float<br/>函数用于获取画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度 | 
| [OH_Drawing_PenSetWidth](_drawing.md#ga562b5102bf599e640a94e104480df0f4)&nbsp;([OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*,&nbsp;float&nbsp;width) | void<br/>函数用于设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度 | 
| [OH_Drawing_PenGetMiterLimit](_drawing.md#ga8f8a512b3930d8883dff59916eaaa72a)&nbsp;(const&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | float<br/>函数用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角 | 
| [OH_Drawing_PenSetMiterLimit](_drawing.md#ga73a96e3e9ca95a82f0de2076cb03ffba)&nbsp;([OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*,&nbsp;float&nbsp;miter) | void<br/>函数用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角 | 
| [OH_Drawing_PenGetCap](_drawing.md#ga7db0d5ac28ac24db29fc49c113affc32)&nbsp;(const&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | [OH_Drawing_PenLineCapStyle](_drawing.md#gafa9d815d933e0fd6aa7549d12080fa8f)<br/>函数用于获取画笔笔帽的样式 | 
| [OH_Drawing_PenSetCap](_drawing.md#gaa0d8f5e75ec5fbc776c4e5e780e29af3)&nbsp;([OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*,&nbsp;[OH_Drawing_PenLineCapStyle](_drawing.md#gafa9d815d933e0fd6aa7549d12080fa8f)) | void<br/>函数用于设置画笔笔帽样式 | 
| [OH_Drawing_PenGetJoin](_drawing.md#ga35b26a60ebf70c207f1e8fb8659a9103)&nbsp;(const&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | [OH_Drawing_PenLineJoinStyle](_drawing.md#gad10001f23f6c42f97a392cba30011460)<br/>函数用于获取画笔绘制折线转角的样式 | 
| [OH_Drawing_PenSetJoin](_drawing.md#ga65e9826c39a847b22825e99af65afbb7)&nbsp;([OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*,&nbsp;[OH_Drawing_PenLineJoinStyle](_drawing.md#gad10001f23f6c42f97a392cba30011460)) | void<br/>函数用于设置画笔绘制转角的样式 | 
