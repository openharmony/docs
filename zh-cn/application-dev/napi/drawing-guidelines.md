# Drawing开发指导

## 场景介绍

Native Drawing模块提供了一系列的接口用于基本图形和字体的绘制。常见的应用场景举例：
* 2D图形绘制。
* 文本绘制。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_Drawing_BitmapCreate (void) | 创建一个位图对象。 |
| OH_Drawing_BitmapBuild (OH_Drawing_Bitmap *, const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat *) | 初始化位图对象的宽度和高度，并且为该位图设置像素格式。 |
| OH_Drawing_CanvasCreate (void) | 创建一个画布对象。 |
| OH_Drawing_CanvasBind (OH_Drawing_Canvas *, OH_Drawing_Bitmap *) | 将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。 |
| OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas *, const OH_Drawing_Brush *) | 设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。 |
| OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas *, const OH_Drawing_Pen *) | 设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。 |
| OH_Drawing_CanvasDrawPath (OH_Drawing_Canvas *, const OH_Drawing_Path *) | 画一个自定义路径。 |
| OH_Drawing_PathCreate (void) | 创建一个路径对象。 |
| OH_Drawing_PathMoveTo (OH_Drawing_Path *, float x, float y) | 设置自定义路径的起始点位置。 |
| OH_Drawing_PathLineTo (OH_Drawing_Path *, float x, float y) | 添加一条到目标点的线段。 |
| OH_Drawing_PathClose (OH_Drawing_Path *) | 闭合路径，会添加一条到路径起点位置的线段。 |
| OH_Drawing_PenCreate (void) | 创建一个画笔对象。 |
| OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen *, bool) | 设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| OH_Drawing_PenSetWidth (OH_Drawing_Pen *, float width) | 设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度。 |
| OH_Drawing_BrushCreate (void) | 创建一个画刷对象。 |
| OH_Drawing_BrushSetColor (OH_Drawing_Brush *, uint32_t color) | 设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。 |
| OH_Drawing_CreateTypographyStyle (void) | 创建一个排版对象，用于定义排版样式。 |
| OH_Drawing_CreateTextStyle (void) | 创建一个文本对象，用于定义文本样式。 |
| OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate *, const char *) | 设置文本内容。 |
| OH_Drawing_TypographyPaint (OH_Drawing_Typography *, OH_Drawing_Canvas *, double, double) | 显示文本。 |

详细的接口说明请参考[Drawing](../reference/native-apis/_drawing.md)。

## 2D图形绘制开发步骤

以下步骤描述了在**OpenHarmony**如何使用 **Native Drawing** 模块的画布画笔绘制一个基本的2D图形：

1. **创建Bitmap实例**。使用 **drawing_bitmap.h** 的 **OH_Drawing_BitmapCreate** 接口创建一个Bitmap实例 **cBitmap**，并使用 **OH_Drawing_BitmapBuild** 指定其长宽大小和像素格式。

    ```c++
    // 创建一个bitmap对象
    OH_Drawing_Bitmap* cBitmap = OH_Drawing_BitmapCreate();
    // 定义bitmap的像素格式
    OH_Drawing_BitmapFormat cFormat {COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUYE};
    // 构造对应格式的bitmap
    OH_Drawing_BitmapBuild(cBitmap, width, height, &cFormat);
    ```

2. **创建画布实例**。使用 **drawing_canvas.h** 的 **OH_Drawing_CanvasCreate** 接口创建一个画布实例 **cCanvas**，并使用 **OH_Drawing_CanvasBind** 接口将 **cBitmap** 实例绑定到 **cCanvas** 上，后续在画布上绘制的内容会输出到绑定的 **cBitmap** 实例中。

    ```c++
    // 创建一个canvas对象
    OH_Drawing_Canvas* cCanvas = OH_Drawing_CanvasCreate();
    // 将画布与bitmap绑定，画布画的内容会输出到绑定的bitmap内存中
    OH_Drawing_CanvasBind(cCanvas, cBitmap);
    // 使用白色清除画布内容
    OH_Drawing_CanvasClear(cCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
    ```

3. **构造Path形状**。使用 **drawing_path.h** 提供的接口完成一个五角星形状的构造 **cPath**。

    ```c++
    int len = 300;

    float aX = 500;
    float aY = 500;

    float dX = aX - len * std::sin(18.0f);
    float dY = aY + len * std::cos(18.0f);

    float cX = aX + len * std::sin(18.0f);
    float cY = dY;

    float bX = aX + (len / 2.0);
    float bY = aY + std::sqrt((cX - dX) * (cX - dX) + (len / 2.0) * (len / 2.0));

    float eX = aX - (len / 2.0);
    float eY = bY;

    // 创建一个path对象，然后使用接口连接成一个五角星形状
    OH_Drawing_Path* cPath = OH_Drawing_PathCreate();
    // 指定path的起始位置
    OH_Drawing_PathMoveTo(cPath, aX, aY);
    // 用直线连接到目标点
    OH_Drawing_PathLineTo(cPath, bX, bY);
    OH_Drawing_PathLineTo(cPath, cX, cY);
    OH_Drawing_PathLineTo(cPath, dX, dY);
    OH_Drawing_PathLineTo(cPath, eX, eY);
    // 闭合形状，path绘制完毕
    OH_Drawing_PathClose(cPath);
    ```

4. **设置画笔和画刷样式**。使用 **drawing_pen.h** 的 **OH_Drawing_PenCreate** 接口创建一个画笔实例 **cPen**, 并设置抗锯齿、颜色、线宽等属性，画笔用于形状边框线的绘制。使用**drawing_brush.h** 的 **OH_Drawing_BrushCreate** 接口创建一个画刷实例 **cBrush**, 并设置填充颜色， 画刷用于形状内部的填充。使用 **drawing_canvas.h** 的 **OH_Drawing_CanvasAttachPen** 和 **OH_Drawing_CanvasAttachBrush** 接口将画笔画刷的实例设置到画布实例中。

    ```c++
    // 创建一个画笔Pen对象，Pen对象用于形状的边框线绘制
    OH_Drawing_Pen* cPen = OH_Drawing_PenCreate();
    OH_Drawing_PenSetAntiAlias(cPen, true);
    OH_Drawing_PenSetColor(cPen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
    OH_Drawing_PenSetWidth(cPen, 10.0);
    OH_Drawing_PenSetJoin(cPen, LINE_ROUND_JOIN);
    // 将Pen画笔设置到canvas中
    OH_Drawing_CanvasAttachPen(cCanvas, cPen);

    // 创建一个画刷Brush对象，Brush对象用于形状的填充
    OH_Drawing_Brush* cBrush = OH_Drawing_BrushCreate();
    OH_Drawing_BrushSetColor(cBrush, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0xFF, 0x00));

    // 将Brush画刷设置到canvas中
    OH_Drawing_CanvasAttachBrush(cCanvas, cBrush);
    ```

5. **绘制Path形状**。使用 **drawing_canvas.h** 的 **OH_Drawing_CanvasDrawPath** 接口将五角星绘制到画布上，绘制完毕后不再使用的实例需要调用对应的接口进行销毁。

    ```c++
    // 在画布上画path的形状，五角星的边框样式为pen设置，颜色填充为Brush设置
    OH_Drawing_CanvasDrawPath(cCanvas, cPath);
    // 销毁创建的对象
    OH_Drawing_BrushDestory(cBrush);
    OH_Drawing_PenDestory(cPen);
    OH_Drawing_PathDestory(cPath);
    ```

6. **获取像素数据**。使用 **drawing_bitmap.h** 的 **OH_Drawing_BitmapGetPixels** 接口获取到画布绑定bitmap实例的像素地址，该地址指向的内存包含画布刚刚绘制的像素数据。

    ```c++
    // 画完后获取像素地址，地址指向的内存包含画布画的像素数据
    void* bitmapAddr = OH_Drawing_BitmapGetPixels(cBitmap);
    auto ret = memcpy_s(addr, addrSize, bitmapAddr, addrSize);
    if (ret != EOK) {
        LOGI("memcpy_s failed");
    }
    // 销毁canvas对象
    OH_Drawing_CanvasDestory(cCanvas);
    // 销毁bitmap对象
    OH_Drawing_BitmapDestory(cBitmap);
    ```

## 文本绘制开发步骤

以下步骤描述了在OpenHarmony中，如何使用**Native Drawing**模块的文字显示功能：
1. **创建画布和bitmap实例**。

    ```c++
    // 创建bitmap
    OH_Drawing_Bitmap* cBitmap = OH_Drawing_BitmapCreate();
    OH_Drawing_BitmapFormat cFormat {COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUE};
    OH_Drawing_BitmapBuild(cBitmap, width, height, &cFormat);
    // 创建canvas
    OH_Drawing_Canvas* cCanvas = OH_Drawing_CanvasCreate();
    OH_Drawing_CanvasBind(cCanvas, cBitmap);
    OH_Drawing_CanvasClear(cCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
    ```
  
2. **设置排版风格**。

    ```c++
    // 选择从左到右/左对齐等排版属性
    OH_Drawing_TypographyStyle* typoStyle = OH_Drawing_CreateTypographyStyle();
    OH_Drawing_SetTypographyTextDirection(typoStyle, TEXT_DIRECTION_LTR);
    OH_Drawing_SetTypographyTextAlign(typoStyle, TEXT_ALIGN_LEFT);
    ```

3. **设置文本风格**。

    ```c++
    // 设置文字颜色，例如黑色
    OH_Drawing_TextStyle* txtStyle = OH_Drawing_CreateTextStyle();
    OH_Drawing_SetTextStyleColor(txtStyle, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
    // 设置文字大小、字重等属性
    double fontSize = 30;
    OH_Drawing_SetTextStyleFontSize(txtStyle, fontSize);
    OH_Drawing_SetTextStyleFontWeight(txtStyle, FONT_WEIGHT_400);
    OH_Drawing_SetTextStyleBaseLine(txtStyle, TEXT_BASELINE_ALPHABETIC);
    OH_Drawing_SetTextStyleFontHeight(txtStyle, 1);
    // 设置字体类型等
    const char* fontFamilies[] = {"Roboto"};
    OH_Drawing_SetTextStyleFontFamilies(txtStyle, 1, fontFamilies);
    OH_Drawing_SetTextStyleFontStyle(txtStyle, FONT_STYLE_NORMAL);
    OH_Drawing_SetTextStyleLocale(txtStyle, "en");
    ```

4. **生成最终文本显示效果**。

    ```c++
    OH_Drawing_TypographyCreate* handler = OH_Drawing_CreateTypographyHandler(typoStyle,
        OH_Drawing_CreateFontCollection());
    OH_Drawing_TypographyHandlerPushTextStyle(handler, txtStyle);
    // 设置文字内容
    const char* text = "OpenHarmony\n";
    OH_Drawing_TypographyHandlerAddText(handler, text);
    OH_Drawing_TypographyHandlerPopTextStyle(handler);
    OH_Drawing_Typography* typography = OH_Drawing_CreateTypography(handler);
    // 设置页面最大宽度
    double maxWidth = 800.0;
    OH_Drawing_TypographyLayout(typography, maxWidth);
    // 设置文本在画布上绘制的起始位置
    double position[2] = {10.0, 15.0};
    // 将文本绘制到画布上
    OH_Drawing_TypographyPaint(typography, cCanvas, position[0], position[1]);
    ```

## 相关实例

针对Drawing模块的使用，有以下相关实例可供参考：
* [Drawing模块2D图形绘制](https://gitee.com/openharmony/graphic_graphic_2d/blob/master/rosen/samples/2d_graphics/drawing_c_sample.cpp)。
* [Drawing模块文本绘制](https://gitee.com/openharmony/graphic_graphic_2d/blob/master/rosen/samples/text/renderservice/drawing_text_c_sample.cpp)。
