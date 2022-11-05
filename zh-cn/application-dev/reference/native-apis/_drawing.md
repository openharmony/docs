# Drawing


## **Overview**

**Description:**

Drawing模块提供包括2D图形渲染、文字绘制和图片显示等功能函数

Drawing模块提供包括2D图形渲染、文字绘制和图片显示等功能函数.

提供2D绘制功能

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since:**

8

**Version:**

1.0


## **Summary**


### Files

  | File&nbsp;Name | Description | 
| -------- | -------- |
| [drawing_bitmap.h](drawing__bitmap_8h.md) | 文件中定义了与位图相关的功能函数 | 
| [drawing_brush.h](drawing__brush_8h.md) | 文件中定义了与画刷相关的功能函数 | 
| [drawing_canvas.h](drawing__canvas_8h.md) | 文件中定义了与画布相关的功能函数 | 
| [drawing_color.h](drawing__color_8h.md) | 文件中定义了与颜色相关的功能函数 | 
| [drawing_font_collection.h](drawing__font__collection_8h.md) | 定义绘制模块中与fontCollection相关的函数 | 
| [drawing_path.h](drawing__path_8h.md) | 文件中定义了与自定义路径相关的功能函数 | 
| [drawing_pen.h](drawing__pen_8h.md) | 文件中定义了与画笔相关的功能函数 | 
| [drawing_text_declaration.h](drawing__text__declaration_8h.md) | 提供2d&nbsp;drawing文本相关的数据结构声明 | 
| [drawing_text_typography.h](drawing__text__typography_8h.md) | 定义绘制模块中排版相关的函数 | 
| [drawing_types.h](drawing__types_8h.md) | 文件中定义了用于绘制2d图形的数据类型，包括画布、画笔、画刷、位图和路径 | 


### Classes

  | Classes&nbsp;Name | Description | 
| -------- | -------- |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型 | 


### Typedefs

  | Typedef&nbsp;Name | Description | 
| -------- | -------- |
| OH_Drawing_FontCollection | typedef&nbsp;struct&nbsp;OH_Drawing_FontCollection<br/>OH_Drawing_FontCollection用于加载字体 | 
| OH_Drawing_Typography | typedef&nbsp;struct&nbsp;OH_Drawing_Typography<br/>OH_Drawing_Typography用于管理排版的布局和显示等 | 
| OH_Drawing_TextStyle | typedef&nbsp;struct&nbsp;OH_Drawing_TextStyle<br/>OH_Drawing_TextStyle用于管理字体颜色、装饰等 | 
| OH_Drawing_TypographyStyle | typedef&nbsp;struct&nbsp;OH_Drawing_TypographyStyle<br/>OH_Drawing_TypographyStyle用于管理排版风格，如文字方向等 | 
| OH_Drawing_TypographyCreate | typedef&nbsp;struct&nbsp;OH_Drawing_TypographyCreate<br/>OH_Drawing_TypographyCreate用于创建OH_Drawing_Typography. | 
| OH_Drawing_Canvas | typedef&nbsp;struct&nbsp;OH_Drawing_Canvas<br/>OH_Drawing_Canvas定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字 | 
| OH_Drawing_Pen | typedef&nbsp;struct&nbsp;OH_Drawing_Pen<br/>OH_Drawing_Pen定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色 | 
| OH_Drawing_Brush | typedef&nbsp;struct&nbsp;OH_Drawing_Brush<br/>OH_Drawing_Brush定义为画刷，画刷用于描述填充图形的样式和颜色 | 
| OH_Drawing_Path | typedef&nbsp;struct&nbsp;OH_Drawing_Path<br/>OH_Drawing_Path定义为路径，路径用于自定义各种形状 | 
| OH_Drawing_Bitmap | typedef&nbsp;struct&nbsp;OH_Drawing_Bitmap<br/>OH_Drawing_Bitmap定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据 | 


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| OH_Drawing_PenLineCapStyle&nbsp;{&nbsp;LINE_FLAT_CAP,&nbsp;LINE_SQUARE_CAP,&nbsp;LINE_ROUND_CAP&nbsp;} | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式 | 
| OH_Drawing_PenLineJoinStyle&nbsp;{&nbsp;LINE_MITER_JOIN,&nbsp;LINE_ROUND_JOIN,&nbsp;LINE_BEVEL_JOIN&nbsp;} | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式 | 
| OH_Drawing_TextDirection&nbsp;{&nbsp;TEXT_DIRECTION_RTL,&nbsp;TEXT_DIRECTION_LTR&nbsp;} | 文字方向 | 
| OH_Drawing_TextAlign&nbsp;{&nbsp;&nbsp;&nbsp;TEXT_ALIGN_LEFT,&nbsp;TEXT_ALIGN_RIGHT,&nbsp;TEXT_ALIGN_CENTER,&nbsp;TEXT_ALIGN_JUSTIFY,&nbsp;&nbsp;&nbsp;TEXT_ALIGN_START,&nbsp;TEXT_ALIGN_END&nbsp;} | 文字对齐方式 | 
| OH_Drawing_FontWeight&nbsp;{&nbsp;&nbsp;&nbsp;FONT_WEIGHT_100,&nbsp;FONT_WEIGHT_200,&nbsp;FONT_WEIGHT_300,&nbsp;FONT_WEIGHT_400,&nbsp;&nbsp;&nbsp;FONT_WEIGHT_500,&nbsp;FONT_WEIGHT_600,&nbsp;FONT_WEIGHT_700,&nbsp;FONT_WEIGHT_800,&nbsp;&nbsp;&nbsp;FONT_WEIGHT_900&nbsp;} | 字重 | 
| OH_Drawing_TextBaseline&nbsp;{&nbsp;TEXT_BASELINE_ALPHABETIC,&nbsp;TEXT_BASELINE_IDEOGRAPHIC&nbsp;} | 基线位置 | 
| OH_Drawing_TextDecoration&nbsp;{&nbsp;TEXT_DECORATION_NONE&nbsp;=&nbsp;0x0,&nbsp;TEXT_DECORATION_UNDERLINE&nbsp;=&nbsp;0x1,&nbsp;TEXT_DECORATION_OVERLINE&nbsp;=&nbsp;0x2,&nbsp;TEXT_DECORATION_LINE_THROUGH&nbsp;=&nbsp;0x4&nbsp;} | 文本装饰 | 
| OH_Drawing_FontStyle&nbsp;{&nbsp;FONT_STYLE_NORMAL,&nbsp;FONT_STYLE_ITALIC&nbsp;} | 区分字体是否为斜体 | 
| OH_Drawing_ColorFormat&nbsp;{&nbsp;&nbsp;&nbsp;COLOR_FORMAT_UNKNOWN,&nbsp;COLOR_FORMAT_ALPHA_8,&nbsp;COLOR_FORMAT_RGB_565,&nbsp;COLOR_FORMAT_ARGB_4444,&nbsp;&nbsp;&nbsp;COLOR_FORMAT_RGBA_8888,&nbsp;COLOR_FORMAT_BGRA_8888&nbsp;} | OH_Drawing_ColorFormat用于描述位图像素的存储格式 | 
| OH_Drawing_AlphaFormat&nbsp;{&nbsp;ALPHA_FORMAT_UNKNOWN,&nbsp;ALPHA_FORMAT_OPAQUE,&nbsp;ALPHA_FORMAT_PREMUL,&nbsp;ALPHA_FORMAT_UNPREMUL&nbsp;} | OH_Drawing_AlphaFormat用于描述位图像素的透明度分量 | 


### Functions

  | Function | Description | 
| -------- | -------- |
| OH_Drawing_BitmapCreate&nbsp;(void) | OH_Drawing_Bitmap&nbsp;\*<br/>函数用于创建一个位图对象。 | 
| OH_Drawing_BitmapDestroy&nbsp;(OH_Drawing_Bitmap&nbsp;\*) | void<br/>函数用于销毁位图对象并回收该对象占有内存。 | 
| OH_Drawing_BitmapBuild&nbsp;(OH_Drawing_Bitmap&nbsp;\*,&nbsp;const&nbsp;uint32_t&nbsp;width,&nbsp;const&nbsp;uint32_t&nbsp;height,&nbsp;const&nbsp;OH_Drawing_BitmapFormat&nbsp;\*) | void<br/>函数用于初始化位图对象的宽度和高度，并且为该位图设置像素格式 | 
| OH_Drawing_BitmapGetWidth&nbsp;(OH_Drawing_Bitmap&nbsp;\*) | uint32_t<br/>该函数用于获取指定位图的宽度 | 
| OH_Drawing_BitmapGetHeight&nbsp;(OH_Drawing_Bitmap&nbsp;\*) | uint32_t<br/>函数用于获取指定位图的高度 | 
| OH_Drawing_BitmapGetPixels&nbsp;(OH_Drawing_Bitmap&nbsp;\*) | void&nbsp;\*<br/>函数用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据 | 
| OH_Drawing_BrushCreate&nbsp;(void) | OH_Drawing_Brush&nbsp;\*<br/>函数用于创建一个画刷对象 | 
| OH_Drawing_BrushDestroy&nbsp;(OH_Drawing_Brush&nbsp;\*) | void<br/>函数用于销毁画刷对象并回收该对象占有的内存。 | 
| OH_Drawing_BrushIsAntiAlias&nbsp;(const&nbsp;OH_Drawing_Brush&nbsp;\*) | bool<br/>函数用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| OH_Drawing_BrushSetAntiAlias&nbsp;(OH_Drawing_Brush&nbsp;\*,&nbsp;bool) | void<br/>函数用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| OH_Drawing_BrushGetColor&nbsp;(const&nbsp;OH_Drawing_Brush&nbsp;\*) | uint32_t<br/>函数用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示 | 
| OH_Drawing_BrushSetColor&nbsp;(OH_Drawing_Brush&nbsp;\*,&nbsp;uint32_t&nbsp;color) | void<br/>函数用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示 | 
| OH_Drawing_CanvasCreate&nbsp;(void) | OH_Drawing_Canvas&nbsp;\*<br/>函数用于创建一个画布对象 | 
| OH_Drawing_CanvasDestroy&nbsp;(OH_Drawing_Canvas&nbsp;\*) | void<br/>函数用于销毁画布对象并回收该对象占有的内存 | 
| OH_Drawing_CanvasBind&nbsp;(OH_Drawing_Canvas&nbsp;\*,&nbsp;OH_Drawing_Bitmap&nbsp;\*) | void<br/>函数用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染） | 
| OH_Drawing_CanvasAttachPen&nbsp;(OH_Drawing_Canvas&nbsp;\*,&nbsp;const&nbsp;OH_Drawing_Pen&nbsp;\*) | void<br/>函数用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓 | 
| OH_Drawing_CanvasDetachPen&nbsp;(OH_Drawing_Canvas&nbsp;\*) | void<br/>函数用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓 | 
| OH_Drawing_CanvasAttachBrush&nbsp;(OH_Drawing_Canvas&nbsp;\*,&nbsp;const&nbsp;OH_Drawing_Brush&nbsp;\*) | void<br/>函数用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状 | 
| OH_Drawing_CanvasDetachBrush&nbsp;(OH_Drawing_Canvas&nbsp;\*) | void<br/>函数用于去除掉画布中的画刷，使用后画布将不去填充图形形状 | 
| OH_Drawing_CanvasSave&nbsp;(OH_Drawing_Canvas&nbsp;\*) | void<br/>函数用于保存当前画布的状态（画布矩阵）到一个栈顶 | 
| OH_Drawing_CanvasRestore&nbsp;(OH_Drawing_Canvas&nbsp;\*) | void<br/>函数用于恢复保存在栈顶的画布状态（画布矩阵） | 
| OH_Drawing_CanvasDrawLine&nbsp;(OH_Drawing_Canvas&nbsp;\*,&nbsp;float&nbsp;x1,&nbsp;float&nbsp;y1,&nbsp;float&nbsp;x2,&nbsp;float&nbsp;y2) | void<br/>函数用于画一条直线段 | 
| OH_Drawing_CanvasDrawPath&nbsp;(OH_Drawing_Canvas&nbsp;\*,&nbsp;const&nbsp;OH_Drawing_Path&nbsp;\*) | void<br/>函数用于画一个自定义路径 | 
| OH_Drawing_CanvasClear&nbsp;(OH_Drawing_Canvas&nbsp;\*,&nbsp;uint32_t&nbsp;color) | void<br/>函数用于使用指定颜色去清空画布 | 
| OH_Drawing_ColorSetArgb&nbsp;(uint32_t&nbsp;alpha,&nbsp;uint32_t&nbsp;red,&nbsp;uint32_t&nbsp;green,&nbsp;uint32_t&nbsp;blue) | uint32_t<br/>函数用于将4个变量（分别描述透明度、红色、绿色和蓝色）转化为一个描述颜色的32位（ARGB）变量 | 
| OH_Drawing_CreateFontCollection&nbsp;(void) | OH_Drawing_FontCollection&nbsp;\*<br/>创建OH_Drawing_FontCollection | 
| OH_Drawing_DestroyFontCollection&nbsp;(OH_Drawing_FontCollection&nbsp;\*) | void<br/>释放被OH_Drawing_FontCollection对象占据的内存 | 
| OH_Drawing_PathCreate&nbsp;(void) | OH_Drawing_Path&nbsp;\*<br/>函数用于创建一个路径对象 | 
| OH_Drawing_PathDestroy&nbsp;(OH_Drawing_Path&nbsp;\*) | void<br/>函数用于销毁路径对象并回收该对象占有的内存 | 
| OH_Drawing_PathMoveTo&nbsp;(OH_Drawing_Path&nbsp;\*,&nbsp;float&nbsp;x,&nbsp;float&nbsp;y) | void<br/>函数用于设置自定义路径的起始点位置 | 
| OH_Drawing_PathLineTo&nbsp;(OH_Drawing_Path&nbsp;\*,&nbsp;float&nbsp;x,&nbsp;float&nbsp;y) | void<br/>函数用于添加一条从路径的最后点位置到目标点位置的线段 | 
| OH_Drawing_PathArcTo&nbsp;(OH_Drawing_Path&nbsp;\*,&nbsp;float&nbsp;x1,&nbsp;float&nbsp;y1,&nbsp;float&nbsp;x2,&nbsp;float&nbsp;y2,&nbsp;float&nbsp;startDeg,&nbsp;float&nbsp;sweepDeg) | void<br/>函数用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆，&nbsp;然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段 | 
| OH_Drawing_PathQuadTo&nbsp;(OH_Drawing_Path&nbsp;\*,&nbsp;float&nbsp;ctrlX,&nbsp;float&nbsp;ctrlY,&nbsp;float&nbsp;endX,&nbsp;float&nbsp;endY) | void<br/>函数用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线 | 
| OH_Drawing_PathCubicTo&nbsp;(OH_Drawing_Path&nbsp;\*,&nbsp;float&nbsp;ctrlX1,&nbsp;float&nbsp;ctrlY1,&nbsp;float&nbsp;ctrlX2,&nbsp;float&nbsp;ctrlY2,&nbsp;float&nbsp;endX,&nbsp;float&nbsp;endY) | void<br/>函数用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线 | 
| OH_Drawing_PathClose&nbsp;(OH_Drawing_Path&nbsp;\*) | void<br/>函数用于闭合路径，会添加一条从路径起点位置到最后点位置的线段 | 
| OH_Drawing_PathReset&nbsp;(OH_Drawing_Path&nbsp;\*) | void<br/>函数用于重置自定义路径数据 | 
| OH_Drawing_PenCreate&nbsp;(void) | OH_Drawing_Pen&nbsp;\*<br/>函数用于创建一个画笔对象 | 
| OH_Drawing_PenDestroy&nbsp;(OH_Drawing_Pen&nbsp;\*) | void<br/>函数用于销毁画笔对象并回收该对象占有的内存 | 
| OH_Drawing_PenIsAntiAlias&nbsp;(const&nbsp;OH_Drawing_Pen&nbsp;\*) | bool<br/>函数用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| OH_Drawing_PenSetAntiAlias&nbsp;(OH_Drawing_Pen&nbsp;\*,&nbsp;bool) | void<br/>函数用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理 | 
| OH_Drawing_PenGetColor&nbsp;(const&nbsp;OH_Drawing_Pen&nbsp;\*) | uint32_t<br/>函数用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示 | 
| OH_Drawing_PenSetColor&nbsp;(OH_Drawing_Pen&nbsp;\*,&nbsp;uint32_t&nbsp;color) | void<br/>函数用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示 | 
| OH_Drawing_PenGetWidth&nbsp;(const&nbsp;OH_Drawing_Pen&nbsp;\*) | float<br/>函数用于获取画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度 | 
| OH_Drawing_PenSetWidth&nbsp;(OH_Drawing_Pen&nbsp;\*,&nbsp;float&nbsp;width) | void<br/>函数用于设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度 | 
| OH_Drawing_PenGetMiterLimit&nbsp;(const&nbsp;OH_Drawing_Pen&nbsp;\*) | float<br/>函数用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角 | 
| OH_Drawing_PenSetMiterLimit&nbsp;(OH_Drawing_Pen&nbsp;\*,&nbsp;float&nbsp;miter) | void<br/>函数用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角 | 
| OH_Drawing_PenGetCap&nbsp;(const&nbsp;OH_Drawing_Pen&nbsp;\*) | OH_Drawing_PenLineCapStyle<br/>函数用于获取画笔笔帽的样式 | 
| OH_Drawing_PenSetCap&nbsp;(OH_Drawing_Pen&nbsp;\*,&nbsp;OH_Drawing_PenLineCapStyle) | void<br/>函数用于设置画笔笔帽样式 | 
| OH_Drawing_PenGetJoin&nbsp;(const&nbsp;OH_Drawing_Pen&nbsp;\*) | OH_Drawing_PenLineJoinStyle<br/>函数用于获取画笔绘制折线转角的样式 | 
| OH_Drawing_PenSetJoin&nbsp;(OH_Drawing_Pen&nbsp;\*,&nbsp;OH_Drawing_PenLineJoinStyle) | void<br/>函数用于设置画笔绘制转角的样式 | 
| OH_Drawing_CreateTypographyStyle&nbsp;(void) | OH_Drawing_TypographyStyle&nbsp;\*<br/>创建OH_Drawing_TypographyStyle | 
| OH_Drawing_DestroyTypographyStyle&nbsp;(OH_Drawing_TypographyStyle&nbsp;\*) | void<br/>释放被OH_Drawing_TypographyStyle对象占据的内存 | 
| OH_Drawing_SetTypographyTextDirection&nbsp;(OH_Drawing_TypographyStyle&nbsp;\*,&nbsp;int) | void<br/>设置文本方向 | 
| OH_Drawing_SetTypographyTextAlign&nbsp;(OH_Drawing_TypographyStyle&nbsp;\*,&nbsp;int) | void<br/>设置文本对齐方式 | 
| OH_Drawing_SetTypographyTextMaxLines&nbsp;(OH_Drawing_TypographyStyle&nbsp;\*,&nbsp;int) | void<br/>设置文本最大行数 | 
| OH_Drawing_CreateTextStyle&nbsp;(void) | OH_Drawing_TextStyle&nbsp;\*<br/>创建OH_Drawing_TextStyle | 
| OH_Drawing_DestroyTextStyle&nbsp;(OH_Drawing_TextStyle&nbsp;\*) | void<br/>释放被OH_Drawing_TextStyle对象占据的内存 | 
| OH_Drawing_SetTextStyleColor&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;uint32_t) | void<br/>设置文本颜色 | 
| OH_Drawing_SetTextStyleFontSize&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;double) | void<br/>设置字号 | 
| OH_Drawing_SetTextStyleFontWeight&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;int) | void<br/>设置字重 | 
| OH_Drawing_SetTextStyleBaseLine&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;int) | void<br/>设置字体基线位置 | 
| OH_Drawing_SetTextStyleDecoration&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;int) | void<br/>设置装饰 | 
| OH_Drawing_SetTextStyleDecorationColor&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;uint32_t) | void<br/>设置装饰颜色 | 
| OH_Drawing_SetTextStyleFontHeight&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;double) | void<br/>设置字体高度 | 
| OH_Drawing_SetTextStyleFontFamilies&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;int,&nbsp;const&nbsp;char&nbsp;\*fontFamilies[]) | void<br/>设置字体类型 | 
| OH_Drawing_SetTextStyleFontStyle&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;int) | void<br/>设置字体风格 | 
| OH_Drawing_SetTextStyleLocale&nbsp;(OH_Drawing_TextStyle&nbsp;\*,&nbsp;const&nbsp;char&nbsp;\*) | void<br/>设置语言区域 | 
| OH_Drawing_CreateTypographyHandler&nbsp;(OH_Drawing_TypographyStyle&nbsp;\*,&nbsp;OH_Drawing_FontCollection&nbsp;\*) | OH_Drawing_TypographyCreate&nbsp;\*<br/>创建指向OH_Drawing_TypographyCreate对象的指针 | 
| OH_Drawing_DestroyTypographyHandler&nbsp;(OH_Drawing_TypographyCreate&nbsp;\*) | void<br/>释放被OH_Drawing_TypographyCreate对象占据的内存 | 
| OH_Drawing_TypographyHandlerPushStyle&nbsp;(OH_Drawing_TypographyCreate&nbsp;\*,&nbsp;OH_Drawing_TextStyle&nbsp;\*) | void<br/>设置排版风格 | 
| OH_Drawing_TypographyHandlerAddText&nbsp;(OH_Drawing_TypographyCreate&nbsp;\*,&nbsp;const&nbsp;char&nbsp;\*) | void<br/>设置文本内容 | 
| OH_Drawing_TypographyHandlerPop&nbsp;(OH_Drawing_TypographyCreate&nbsp;\*) | void<br/>排版弹出 | 
| OH_Drawing_CreateTypography&nbsp;(OH_Drawing_TypographyCreate&nbsp;\*) | OH_Drawing_Typography&nbsp;\*<br/>创建OH_Drawing_Typography | 
| OH_Drawing_DestroyTypography&nbsp;(OH_Drawing_Typography&nbsp;\*) | void<br/>释放OH_Drawing_Typography对象占据的内存 | 
| OH_Drawing_TypographyLayout&nbsp;(OH_Drawing_Typography&nbsp;\*,&nbsp;double) | void<br/>排版布局 | 
| OH_Drawing_TypographyPaint&nbsp;(OH_Drawing_Typography&nbsp;\*,&nbsp;OH_Drawing_Canvas&nbsp;\*,&nbsp;double,&nbsp;double) | void<br/>显示文本 | 


## **Details**


## **Typedef**


### OH_Drawing_Bitmap

  
```
typedef struct OH_Drawing_Bitmap OH_Drawing_Bitmap
```

**Description:**

OH_Drawing_Bitmap定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据


### OH_Drawing_Brush

  
```
typedef struct OH_Drawing_Brush OH_Drawing_Brush
```

**Description:**

OH_Drawing_Brush定义为画刷，画刷用于描述填充图形的样式和颜色


### OH_Drawing_Canvas

  
```
typedef struct OH_Drawing_Canvas OH_Drawing_Canvas
```

**Description:**

OH_Drawing_Canvas定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字


### OH_Drawing_FontCollection

  
```
typedef struct OH_Drawing_FontCollection OH_Drawing_FontCollection
```

**Description:**

OH_Drawing_FontCollection用于加载字体


### OH_Drawing_Path

  
```
typedef struct OH_Drawing_Path OH_Drawing_Path
```

**Description:**

OH_Drawing_Path定义为路径，路径用于自定义各种形状


### OH_Drawing_Pen

  
```
typedef struct OH_Drawing_Pen OH_Drawing_Pen
```

**Description:**

OH_Drawing_Pen定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色


### OH_Drawing_TextStyle

  
```
typedef struct OH_Drawing_TextStyle OH_Drawing_TextStyle
```

**Description:**

OH_Drawing_TextStyle用于管理字体颜色、装饰等


### OH_Drawing_Typography

  
```
typedef struct OH_Drawing_Typography OH_Drawing_Typography
```

**Description:**

OH_Drawing_Typography用于管理排版的布局和显示等


### OH_Drawing_TypographyCreate

  
```
typedef struct OH_Drawing_TypographyCreate OH_Drawing_TypographyCreate
```

**Description:**

OH_Drawing_TypographyCreate用于创建OH_Drawing_Typography.


### OH_Drawing_TypographyStyle

  
```
typedef struct OH_Drawing_TypographyStyle OH_Drawing_TypographyStyle
```

**Description:**

OH_Drawing_TypographyStyle用于管理排版风格，如文字方向等


## **Enumeration Type**


### OH_Drawing_AlphaFormat

  
```
enum OH_Drawing_AlphaFormat
```

**Description:**

OH_Drawing_AlphaFormat用于描述位图像素的透明度分量

  | Enumerator | Description | 
| -------- | -------- |
| ALPHA_FORMAT_UNKNOWN | 未知格式 | 
| ALPHA_FORMAT_OPAQUE | 位图无透明度 | 
| ALPHA_FORMAT_PREMUL | 每个像素的颜色组件由透明度分量预先乘以 | 
| ALPHA_FORMAT_UNPREMUL | 每个像素的颜色组件未由透明度分量预先乘以 | 


### OH_Drawing_ColorFormat

  
```
enum OH_Drawing_ColorFormat
```

**Description:**

OH_Drawing_ColorFormat用于描述位图像素的存储格式

  | Enumerator | Description | 
| -------- | -------- |
| COLOR_FORMAT_UNKNOWN | 未知格式. | 
| COLOR_FORMAT_ALPHA_8 | 每个像素用一个8位的量表示，8个位比特位表示透明度 | 
| COLOR_FORMAT_RGB_565 | 每个像素用一个16位的量表示，高位到低位依次是5个比特位表示红，6个比特位表示绿，5个比特位表示蓝 | 
| COLOR_FORMAT_ARGB_4444 | 每个像素用一个16位的量表示，高位到低位依次是4个比特位表示透明度，4个比特位表示红，4个比特位表示绿，4个比特位表示蓝 | 
| COLOR_FORMAT_RGBA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示透明度，8个比特位表示红，8个比特位表示绿，8个比特位表示蓝 | 
| COLOR_FORMAT_BGRA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示蓝，8个比特位表示绿，8个比特位表示红，8个比特位表示透明度 | 


### OH_Drawing_FontStyle

  
```
enum OH_Drawing_FontStyle
```

**Description:**

区分字体是否为斜体

  | Enumerator | Description | 
| -------- | -------- |
| FONT_STYLE_NORMAL | 非斜体 | 
| FONT_STYLE_ITALIC | 斜体 | 


### OH_Drawing_FontWeight

  
```
enum OH_Drawing_FontWeight
```

**Description:**

字重

  | Enumerator | Description | 
| -------- | -------- |
| FONT_WEIGHT_100 | 字重为thin | 
| FONT_WEIGHT_200 | 字重为extra-light | 
| FONT_WEIGHT_300 | 字重为light | 
| FONT_WEIGHT_400 | 字重为normal/regular | 
| FONT_WEIGHT_500 | 字重为medium | 
| FONT_WEIGHT_600 | 字重为semi-bold | 
| FONT_WEIGHT_700 | 字重为bold | 
| FONT_WEIGHT_800 | 字重为extra-bold | 
| FONT_WEIGHT_900 | 字重为black | 


### OH_Drawing_PenLineCapStyle

  
```
enum OH_Drawing_PenLineCapStyle
```

**Description:**

枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式

  | Enumerator | Description | 
| -------- | -------- |
| LINE_FLAT_CAP | 没有笔帽样式，线条头尾端点处横切 | 
| LINE_SQUARE_CAP | 笔帽的样式为方框，线条的头尾端点处多出一个方框，方框宽度和线段一样宽，高度时线段厚度的一半 | 
| LINE_ROUND_CAP | 笔帽的样式为圆弧，线条的头尾端点处多出一个半圆弧，半圆的直径与线段厚度一致 | 


### OH_Drawing_PenLineJoinStyle

  
```
enum OH_Drawing_PenLineJoinStyle
```

**Description:**

枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式

  | Enumerator | Description | 
| -------- | -------- |
| LINE_MITER_JOIN | 转角类型为尖角，如果折线角度比较小，则尖角会很长，需要使用限制值（miter&nbsp;limit）进行限制 | 
| LINE_ROUND_JOIN | 转角类型为圆头 | 
| LINE_BEVEL_JOIN | 转角类型为平头 | 


### OH_Drawing_TextAlign

  
```
enum OH_Drawing_TextAlign
```

**Description:**

文字对齐方式

  | Enumerator | Description | 
| -------- | -------- |
| TEXT_ALIGN_LEFT | 左对齐 | 
| TEXT_ALIGN_RIGHT | 右对齐 | 
| TEXT_ALIGN_CENTER | 居中对齐 | 
| TEXT_ALIGN_JUSTIFY | 两端对齐，即紧靠左和右边缘，中间单词空隙由空格填充&nbsp;最后一行除外 | 
| TEXT_ALIGN_START | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时，&nbsp;TEXT_ALIGN_START和TEXT_ALIGN_LEFT相同；&nbsp;类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时，&nbsp;TEXT_ALIGN_START和TEXT_ALIGN_RIGHT相同。 | 
| TEXT_ALIGN_END | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时，&nbsp;TEXT_ALIGN_END和TEXT_ALIGN_RIGHT相同；&nbsp;类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时，&nbsp;TEXT_ALIGN_END和TEXT_ALIGN_LEFT相同。 | 


### OH_Drawing_TextBaseline

  
```
enum OH_Drawing_TextBaseline
```

**Description:**

基线位置

  | Enumerator | Description | 
| -------- | -------- |
| TEXT_BASELINE_ALPHABETIC | 用于表音文字，基线在中间偏下的位置 | 
| TEXT_BASELINE_IDEOGRAPHIC | 用于表意文字，基线位于底部 | 


### OH_Drawing_TextDecoration

  
```
enum OH_Drawing_TextDecoration
```

**Description:**

文本装饰

  | Enumerator | Description | 
| -------- | -------- |
| TEXT_DECORATION_NONE | 无装饰 | 
| TEXT_DECORATION_UNDERLINE | 下划线 | 
| TEXT_DECORATION_OVERLINE | 上划线 | 
| TEXT_DECORATION_LINE_THROUGH | 删除线 | 


### OH_Drawing_TextDirection

  
```
enum OH_Drawing_TextDirection
```

**Description:**

文字方向

  | Enumerator | Description | 
| -------- | -------- |
| TEXT_DIRECTION_RTL | 方向：从右到左 | 
| TEXT_DIRECTION_LTR | 方向：从左到右 | 


## **Function**


### OH_Drawing_BitmapBuild()

  
```
void OH_Drawing_BitmapBuild (OH_Drawing_Bitmap * , const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat *  )
```

**Description:**

函数用于初始化位图对象的宽度和高度，并且为该位图设置像素格式

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Bitmap | 参数是一个指向位图对象的指针 | 
| width | 参数是位图要初始化设置的宽度 | 
| height | 参数是位图要初始化设置的高度 | 
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 参数是位图要初始化设置的像素格式，包括像素的颜色类型和透明度类型 | 


### OH_Drawing_BitmapCreate()

  
```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreate (void )
```

**Description:**

函数用于创建一个位图对象。

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

函数会返回一个指针，指针指向创建的位图对象


### OH_Drawing_BitmapDestroy()

  
```
void OH_Drawing_BitmapDestroy (OH_Drawing_Bitmap * )
```

**Description:**

函数用于销毁位图对象并回收该对象占有内存。

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Bitmap | 参数是一个指向位图对象的指针 | 


### OH_Drawing_BitmapGetHeight()

  
```
uint32_t OH_Drawing_BitmapGetHeight (OH_Drawing_Bitmap * )
```

**Description:**

函数用于获取指定位图的高度

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Bitmap | 参数是一个指向位图对象的指针 | 

**Returns:**

函数返回位图的高度


### OH_Drawing_BitmapGetPixels()

  
```
void* OH_Drawing_BitmapGetPixels (OH_Drawing_Bitmap * )
```

**Description:**

函数用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Bitmap | 参数是一个指向位图对象的指针 | 

**Returns:**

函数返回位图的像素地址


### OH_Drawing_BitmapGetWidth()

  
```
uint32_t OH_Drawing_BitmapGetWidth (OH_Drawing_Bitmap * )
```

**Description:**

该函数用于获取指定位图的宽度

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Bitmap | 参数是一个指向位图对象的指针 | 

**Returns:**

函数返回位图的宽度


### OH_Drawing_BrushCreate()

  
```
OH_Drawing_Brush* OH_Drawing_BrushCreate (void )
```

**Description:**

函数用于创建一个画刷对象

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

函数会返回一个指针，指针指向创建的画刷对象


### OH_Drawing_BrushDestroy()

  
```
void OH_Drawing_BrushDestroy (OH_Drawing_Brush * )
```

**Description:**

函数用于销毁画刷对象并回收该对象占有的内存。

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Brush | 参数是一个指向画刷对象的指针 | 


### OH_Drawing_BrushGetColor()

  
```
uint32_t OH_Drawing_BrushGetColor (const OH_Drawing_Brush * )
```

**Description:**

函数用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Brush | 参数是一个指向画刷对象的指针 | 

**Returns:**

函数返回一个描述颜色的32位（ARGB）变量


### OH_Drawing_BrushIsAntiAlias()

  
```
bool OH_Drawing_BrushIsAntiAlias (const OH_Drawing_Brush * )
```

**Description:**

函数用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Brush | 参数是一个指向画刷对象的指针 | 

**Returns:**

函数返回画刷对象是否设置抗锯齿属性，返回真则设置了抗锯齿，返回假则没有设置抗锯齿


### OH_Drawing_BrushSetAntiAlias()

  
```
void OH_Drawing_BrushSetAntiAlias (OH_Drawing_Brush * , bool  )
```

**Description:**

函数用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Brush | 参数是一个指向画刷对象的指针 | 
| bool | 参数真为抗锯齿，参数假则不做抗锯齿处理 | 


### OH_Drawing_BrushSetColor()

  
```
void OH_Drawing_BrushSetColor (OH_Drawing_Brush * , uint32_t color )
```

**Description:**

函数用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Brush | 参数是一个指向画刷对象的指针 | 
| color | 参数是一个描述颜色的32位（ARGB）变量 | 


### OH_Drawing_CanvasAttachBrush()

  
```
void OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas * , const OH_Drawing_Brush *  )
```

**Description:**

函数用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 
| OH_Drawing_Brush | 参数为一个指向画刷对象的指针 | 


### OH_Drawing_CanvasAttachPen()

  
```
void OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas * , const OH_Drawing_Pen *  )
```

**Description:**

函数用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 
| OH_Drawing_Pen | 参数为一个指向画笔对象的指针 | 


### OH_Drawing_CanvasBind()

  
```
void OH_Drawing_CanvasBind (OH_Drawing_Canvas * , OH_Drawing_Bitmap *  )
```

**Description:**

函数用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 
| OH_Drawing_Bitmap | 参数为一个指向位图对象的指针 | 


### OH_Drawing_CanvasClear()

  
```
void OH_Drawing_CanvasClear (OH_Drawing_Canvas * , uint32_t color )
```

**Description:**

函数用于使用指定颜色去清空画布

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 
| color | 参数为一个描述颜色的32位（ARGB）变量 | 


### OH_Drawing_CanvasCreate()

  
```
OH_Drawing_Canvas* OH_Drawing_CanvasCreate (void )
```

**Description:**

函数用于创建一个画布对象

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

函数会返回一个指针，指针指向创建的画布对象


### OH_Drawing_CanvasDestroy()

  
```
void OH_Drawing_CanvasDestroy (OH_Drawing_Canvas * )
```

**Description:**

函数用于销毁画布对象并回收该对象占有的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数是一个指向画布对象的指针 | 


### OH_Drawing_CanvasDetachBrush()

  
```
void OH_Drawing_CanvasDetachBrush (OH_Drawing_Canvas * )
```

**Description:**

函数用于去除掉画布中的画刷，使用后画布将不去填充图形形状

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 


### OH_Drawing_CanvasDetachPen()

  
```
void OH_Drawing_CanvasDetachPen (OH_Drawing_Canvas * )
```

**Description:**

函数用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 


### OH_Drawing_CanvasDrawLine()

  
```
void OH_Drawing_CanvasDrawLine (OH_Drawing_Canvas * , float x1, float y1, float x2, float y2 )
```

**Description:**

函数用于画一条直线段

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 
| x1 | 参数为线段起始点的横坐标 | 
| y1 | 参数为线段起始点的纵坐标 | 
| x2 | 参数为线段结束点的横坐标 | 
| y2 | 参数为线段结束点的纵坐标 | 


### OH_Drawing_CanvasDrawPath()

  
```
void OH_Drawing_CanvasDrawPath (OH_Drawing_Canvas * , const OH_Drawing_Path *  )
```

**Description:**

函数用于画一个自定义路径

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 


### OH_Drawing_CanvasRestore()

  
```
void OH_Drawing_CanvasRestore (OH_Drawing_Canvas * )
```

**Description:**

函数用于恢复保存在栈顶的画布状态（画布矩阵）

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 


### OH_Drawing_CanvasSave()

  
```
void OH_Drawing_CanvasSave (OH_Drawing_Canvas * )
```

**Description:**

函数用于保存当前画布的状态（画布矩阵）到一个栈顶

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Canvas | 参数为一个指向画布对象的指针 | 


### OH_Drawing_ColorSetArgb()

  
```
uint32_t OH_Drawing_ColorSetArgb (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue )
```

**Description:**

函数用于将4个变量（分别描述透明度、红色、绿色和蓝色）转化为一个描述颜色的32位（ARGB）变量

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| alpha | 参数为一个描述透明度的变量,&nbsp;变量范围是0x00~0xFF | 
| red | 参数为一个描述红色的变量,&nbsp;变量范围是0x00~0xFF | 
| green | 参数为一个描述绿色的变量,&nbsp;变量范围是0x00~0xFF | 
| blue | 参数为一个描述蓝色的变量,&nbsp;变量范围是0x00~0xFF | 

**Returns:**

函数返回一个描述颜色的32位（ARGB）变量


### OH_Drawing_CreateFontCollection()

  
```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection (void )
```

**Description:**

创建OH_Drawing_FontCollection

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

指向创建的OH_Drawing_FontCollection对象的指针


### OH_Drawing_CreateTextStyle()

  
```
OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle (void )
```

**Description:**

创建OH_Drawing_TextStyle

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

指向创建的OH_Drawing_TextStyle对象的指针


### OH_Drawing_CreateTypography()

  
```
OH_Drawing_Typography* OH_Drawing_CreateTypography (OH_Drawing_TypographyCreate * )
```

**Description:**

创建OH_Drawing_Typography

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针 | 

**Returns:**

指向OH_Drawing_Typography对象的指针


### OH_Drawing_CreateTypographyHandler()

  
```
OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler (OH_Drawing_TypographyStyle * , OH_Drawing_FontCollection *  )
```

**Description:**

创建指向OH_Drawing_TypographyCreate对象的指针

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle的指针 | 
| OH_Drawing_FontCollection | 指向OH_Drawing_FontCollection的指针 | 

**Returns:**

指向新创建的OH_Drawing_TypographyCreate对象的指针


### OH_Drawing_CreateTypographyStyle()

  
```
OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle (void )
```

**Description:**

创建OH_Drawing_TypographyStyle

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

指向创建的OH_Drawing_TypographyStyle对象的指针


### OH_Drawing_DestroyFontCollection()

  
```
void OH_Drawing_DestroyFontCollection (OH_Drawing_FontCollection * )
```

**Description:**

释放被OH_Drawing_FontCollection对象占据的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_FontCollection | 指向OH_Drawing_FontCollection对象的指针 | 


### OH_Drawing_DestroyTextStyle()

  
```
void OH_Drawing_DestroyTextStyle (OH_Drawing_TextStyle * )
```

**Description:**

释放被OH_Drawing_TextStyle对象占据的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 


### OH_Drawing_DestroyTypography()

  
```
void OH_Drawing_DestroyTypography (OH_Drawing_Typography * )
```

**Description:**

释放OH_Drawing_Typography对象占据的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 | 


### OH_Drawing_DestroyTypographyHandler()

  
```
void OH_Drawing_DestroyTypographyHandler (OH_Drawing_TypographyCreate * )
```

**Description:**

释放被OH_Drawing_TypographyCreate对象占据的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针 | 


### OH_Drawing_DestroyTypographyStyle()

  
```
void OH_Drawing_DestroyTypographyStyle (OH_Drawing_TypographyStyle * )
```

**Description:**

释放被OH_Drawing_TypographyStyle对象占据的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针 | 


### OH_Drawing_PathArcTo()

  
```
void OH_Drawing_PathArcTo (OH_Drawing_Path * , float x1, float y1, float x2, float y2, float startDeg, float sweepDeg )
```

**Description:**

函数用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆， 然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 
| x1 | 参数为包围椭圆的矩形左上角点位置的横坐标 | 
| y1 | 参数为包围椭圆的矩形左上角点位置的纵坐标 | 
| x2 | 参数为包围椭圆的矩形右下角点位置的横坐标 | 
| y3 | 参数为包围椭圆的矩形右下角点位置的纵坐标 | 


### OH_Drawing_PathClose()

  
```
void OH_Drawing_PathClose (OH_Drawing_Path * )
```

**Description:**

函数用于闭合路径，会添加一条从路径起点位置到最后点位置的线段

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 


### OH_Drawing_PathCreate()

  
```
OH_Drawing_Path* OH_Drawing_PathCreate (void )
```

**Description:**

函数用于创建一个路径对象

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

函数会返回一个指针，指针指向创建的路径对象


### OH_Drawing_PathCubicTo()

  
```
void OH_Drawing_PathCubicTo (OH_Drawing_Path * , float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY )
```

**Description:**

函数用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 
| ctrlX1 | 参数为第一个控制点位置的横坐标 | 
| ctrlY1 | 参数为第一个控制点位置的纵坐标 | 
| ctrlX2 | 参数为第二个控制点位置的横坐标 | 
| ctrlY2 | 参数为第二个控制点位置的纵坐标 | 
| endX | 参数为目标点位置的横坐标 | 
| endY | 参数为目标点位置的纵坐标 | 


### OH_Drawing_PathDestroy()

  
```
void OH_Drawing_PathDestroy (OH_Drawing_Path * )
```

**Description:**

函数用于销毁路径对象并回收该对象占有的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 


### OH_Drawing_PathLineTo()

  
```
void OH_Drawing_PathLineTo (OH_Drawing_Path * , float x, float y )
```

**Description:**

函数用于添加一条从路径的最后点位置到目标点位置的线段

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 
| x | 参数为目标点的横坐标 | 
| y | 参数为目标点的纵坐标 | 


### OH_Drawing_PathMoveTo()

  
```
void OH_Drawing_PathMoveTo (OH_Drawing_Path * , float x, float y )
```

**Description:**

函数用于设置自定义路径的起始点位置

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 
| x | 参数为起始点的横坐标 | 
| y | 参数为起始点的纵坐标 | 


### OH_Drawing_PathQuadTo()

  
```
void OH_Drawing_PathQuadTo (OH_Drawing_Path * , float ctrlX, float ctrlY, float endX, float endY )
```

**Description:**

函数用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 
| ctrlX | 参数为控制点位置的横坐标 | 
| ctrlY | 参数为控制点位置的纵坐标 | 
| endX | 参数为目标点位置的横坐标 | 
| endY | 参数为目标点位置的纵坐标 | 


### OH_Drawing_PathReset()

  
```
void OH_Drawing_PathReset (OH_Drawing_Path * )
```

**Description:**

函数用于重置自定义路径数据

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Path | 参数为一个指向路径对象的指针 | 


### OH_Drawing_PenCreate()

  
```
OH_Drawing_Pen* OH_Drawing_PenCreate (void )
```

**Description:**

函数用于创建一个画笔对象

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns:**

函数会返回一个指针，指针指向创建的画笔对象


### OH_Drawing_PenDestroy()

  
```
void OH_Drawing_PenDestroy (OH_Drawing_Pen * )
```

**Description:**

函数用于销毁画笔对象并回收该对象占有的内存

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 


### OH_Drawing_PenGetCap()

  
```
OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap (const OH_Drawing_Pen * )
```

**Description:**

函数用于获取画笔笔帽的样式

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 

**Returns:**

函数返回画笔笔帽样式


### OH_Drawing_PenGetColor()

  
```
uint32_t OH_Drawing_PenGetColor (const OH_Drawing_Pen * )
```

**Description:**

函数用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 

**Returns:**

函数返回一个描述颜色的32位（ARGB）变量


### OH_Drawing_PenGetJoin()

  
```
OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin (const OH_Drawing_Pen * )
```

**Description:**

函数用于获取画笔绘制折线转角的样式

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 

**Returns:**

函数返回折线转角的样式


### OH_Drawing_PenGetMiterLimit()

  
```
float OH_Drawing_PenGetMiterLimit (const OH_Drawing_Pen * )
```

**Description:**

函数用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 

**Returns:**

函数返回尖角的限制值


### OH_Drawing_PenGetWidth()

  
```
float OH_Drawing_PenGetWidth (const OH_Drawing_Pen * )
```

**Description:**

函数用于获取画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 

**Returns:**

函数返回画笔的厚度


### OH_Drawing_PenIsAntiAlias()

  
```
bool OH_Drawing_PenIsAntiAlias (const OH_Drawing_Pen * )
```

**Description:**

函数用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 

**Returns:**

函数返回画笔对象是否设置抗锯齿属性，返回真则设置了抗锯齿，返回假则没有设置抗锯齿


### OH_Drawing_PenSetAntiAlias()

  
```
void OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen * , bool  )
```

**Description:**

函数用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 
| bool | 参数真为抗锯齿，参数假则不做抗锯齿处理 | 


### OH_Drawing_PenSetCap()

  
```
void OH_Drawing_PenSetCap (OH_Drawing_Pen * , OH_Drawing_PenLineCapStyle  )
```

**Description:**

函数用于设置画笔笔帽样式

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 
| OH_Drawing_PenLineCapStyle | 参数是一个描述画笔笔帽样式的变量 | 


### OH_Drawing_PenSetColor()

  
```
void OH_Drawing_PenSetColor (OH_Drawing_Pen * , uint32_t color )
```

**Description:**

函数用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 
| color | 参数是一个描述颜色的32位（ARGB）变量 | 


### OH_Drawing_PenSetJoin()

  
```
void OH_Drawing_PenSetJoin (OH_Drawing_Pen * , OH_Drawing_PenLineJoinStyle  )
```

**Description:**

函数用于设置画笔绘制转角的样式

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 
| OH_Drawing_PenLineJoinStyle | 参数值一个描述折线转角样式的变量 | 


### OH_Drawing_PenSetMiterLimit()

  
```
void OH_Drawing_PenSetMiterLimit (OH_Drawing_Pen * , float miter )
```

**Description:**

函数用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 
| miter | 参数是一个描述尖角限制值的变量 | 


### OH_Drawing_PenSetWidth()

  
```
void OH_Drawing_PenSetWidth (OH_Drawing_Pen * , float width )
```

**Description:**

函数用于设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Pen | 参数是一个指向画笔对象的指针 | 
| width | 参数是一个描述画笔厚度的变量 | 


### OH_Drawing_SetTextStyleBaseLine()

  
```
void OH_Drawing_SetTextStyleBaseLine (OH_Drawing_TextStyle * , int  )
```

**Description:**

设置字体基线位置

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| int | OH_Drawing_TextBaseline枚举类型 | 


### OH_Drawing_SetTextStyleColor()

  
```
void OH_Drawing_SetTextStyleColor (OH_Drawing_TextStyle * , uint32_t  )
```

**Description:**

设置文本颜色

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| uint32_t | 颜色 | 


### OH_Drawing_SetTextStyleDecoration()

  
```
void OH_Drawing_SetTextStyleDecoration (OH_Drawing_TextStyle * , int  )
```

**Description:**

设置装饰

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| int | OH_Drawing_TextDecoration枚举类型 | 


### OH_Drawing_SetTextStyleDecorationColor()

  
```
void OH_Drawing_SetTextStyleDecorationColor (OH_Drawing_TextStyle * , uint32_t  )
```

**Description:**

设置装饰颜色

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| uint32_t | 颜色 | 


### OH_Drawing_SetTextStyleFontFamilies()

  
```
void OH_Drawing_SetTextStyleFontFamilies (OH_Drawing_TextStyle * , int , const char * fontFamilies[] )
```

**Description:**

设置字体类型

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| int | 字体名称数量 | 
| fontFamilies | 指向字体类型的指针数组 | 


### OH_Drawing_SetTextStyleFontHeight()

  
```
void OH_Drawing_SetTextStyleFontHeight (OH_Drawing_TextStyle * , double  )
```

**Description:**

设置字体高度

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| double | 字体高度 | 


### OH_Drawing_SetTextStyleFontSize()

  
```
void OH_Drawing_SetTextStyleFontSize (OH_Drawing_TextStyle * , double  )
```

**Description:**

设置字号

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| double | 字号 | 


### OH_Drawing_SetTextStyleFontStyle()

  
```
void OH_Drawing_SetTextStyleFontStyle (OH_Drawing_TextStyle * , int  )
```

**Description:**

设置字体风格

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| int | OH_Drawing_FontStyle枚举类型 | 


### OH_Drawing_SetTextStyleFontWeight()

  
```
void OH_Drawing_SetTextStyleFontWeight (OH_Drawing_TextStyle * , int  )
```

**Description:**

设置字重

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| int | OH_Drawing_FontWeight枚举类型 | 


### OH_Drawing_SetTextStyleLocale()

  
```
void OH_Drawing_SetTextStyleLocale (OH_Drawing_TextStyle * , const char *  )
```

**Description:**

设置语言区域

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 
| char | 语言区域，数据类型为指向char的指针 | 


### OH_Drawing_SetTypographyTextAlign()

  
```
void OH_Drawing_SetTypographyTextAlign (OH_Drawing_TypographyStyle * , int  )
```

**Description:**

设置文本对齐方式

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针 | 
| int | OH_Drawing_TextAlign枚举类型 | 


### OH_Drawing_SetTypographyTextDirection()

  
```
void OH_Drawing_SetTypographyTextDirection (OH_Drawing_TypographyStyle * , int  )
```

**Description:**

设置文本方向

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针 | 
| int | OH_Drawing_TextDirection枚举类型 | 


### OH_Drawing_SetTypographyTextMaxLines()

  
```
void OH_Drawing_SetTypographyTextMaxLines (OH_Drawing_TypographyStyle * , int  )
```

**Description:**

设置文本最大行数

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针 | 
| int | 最大行数 | 


### OH_Drawing_TypographyHandlerAddText()

  
```
void OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate * , const char *  )
```

**Description:**

设置文本内容

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针 | 
| char | 指向文本内容的指针 | 


### OH_Drawing_TypographyHandlerPop()

  
```
void OH_Drawing_TypographyHandlerPop (OH_Drawing_TypographyCreate * )
```

**Description:**

排版弹出

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针 | 


### OH_Drawing_TypographyHandlerPushStyle()

  
```
void OH_Drawing_TypographyHandlerPushStyle (OH_Drawing_TypographyCreate * , OH_Drawing_TextStyle *  )
```

**Description:**

设置排版风格

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针 | 
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 | 


### OH_Drawing_TypographyLayout()

  
```
void OH_Drawing_TypographyLayout (OH_Drawing_Typography * , double  )
```

**Description:**

排版布局

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 | 
| double | 文本最大宽度 | 


### OH_Drawing_TypographyPaint()

  
```
void OH_Drawing_TypographyPaint (OH_Drawing_Typography * , OH_Drawing_Canvas * , double , double  )
```

**Description:**

显示文本

\@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 | 
| OH_Drawing_Canvas | 指向OH_Drawing_Canvas对象的指针 | 
| double | x坐标 | 
| double | y坐标 | 
