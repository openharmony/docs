# drawing_path.h


## **Overview**

**Related Modules:**

[Drawing](_drawing.md)

**Description:**

文件中定义了与自定义路径相关的功能函数

**Since:**
8
**Version:**
1.0

## **Summary**


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_Drawing_PathCreate](_drawing.md#ga379fcebc6b43c3b90e0933d928d7c890)&nbsp;(void) | [OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*<br/>函数用于创建一个路径对象 | 
| [OH_Drawing_PathDestroy](_drawing.md#gaa5961e76fd8d2aacdd1fe94ad354ba51)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*) | void<br/>函数用于销毁路径对象并回收该对象占有的内存 | 
| [OH_Drawing_PathMoveTo](_drawing.md#ga3934f53ce94644feaa79fb96bc7fbcc9)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*,&nbsp;float&nbsp;x,&nbsp;float&nbsp;y) | void<br/>函数用于设置自定义路径的起始点位置 | 
| [OH_Drawing_PathLineTo](_drawing.md#ga4da6ed28d5db091be54af8efe661eb18)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*,&nbsp;float&nbsp;x,&nbsp;float&nbsp;y) | void<br/>函数用于添加一条从路径的最后点位置到目标点位置的线段 | 
| [OH_Drawing_PathArcTo](_drawing.md#ga33c44796dfe8050dad3e6306f66ba0d3)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*,&nbsp;float&nbsp;x1,&nbsp;float&nbsp;y1,&nbsp;float&nbsp;x2,&nbsp;float&nbsp;y2,&nbsp;float&nbsp;startDeg,&nbsp;float&nbsp;sweepDeg) | void<br/>函数用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆，&nbsp;然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段 | 
| [OH_Drawing_PathQuadTo](_drawing.md#ga5f69a50c045822c5d5d4896bc120318b)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*,&nbsp;float&nbsp;ctrlX,&nbsp;float&nbsp;ctrlY,&nbsp;float&nbsp;endX,&nbsp;float&nbsp;endY) | void<br/>函数用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线 | 
| [OH_Drawing_PathCubicTo](_drawing.md#ga6a84a20af7911dc504696402c357f1be)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*,&nbsp;float&nbsp;ctrlX1,&nbsp;float&nbsp;ctrlY1,&nbsp;float&nbsp;ctrlX2,&nbsp;float&nbsp;ctrlY2,&nbsp;float&nbsp;endX,&nbsp;float&nbsp;endY) | void<br/>函数用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线 | 
| [OH_Drawing_PathClose](_drawing.md#ga7a3be11857364cdf2e6ca1af70917816)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*) | void<br/>函数用于闭合路径，会添加一条从路径起点位置到最后点位置的线段 | 
| [OH_Drawing_PathReset](_drawing.md#gaf907c525b05dbd1355d16dc13b4ccda9)&nbsp;([OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*) | void<br/>函数用于重置自定义路径数据 | 
