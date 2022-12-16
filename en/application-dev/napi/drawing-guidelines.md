# Drawing Development

## When to Use

The Native Drawing module provides APIs for drawing 2D graphics and text. The following scenarios are common for drawing development:
* Drawing 2D graphics
* Drawing text drawing

## Available APIs

| API| Description| 
| -------- | -------- |
| OH_Drawing_BitmapCreate (void) | Creates a bitmap object.|
| OH_Drawing_BitmapBuild (OH_Drawing_Bitmap *, const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat *) | Initializes the width and height of a bitmap object and sets the pixel format for the bitmap.|
| OH_Drawing_CanvasCreate (void) | Creates a canvas object.|
| OH_Drawing_CanvasBind (OH_Drawing_Canvas *, OH_Drawing_Bitmap *) | Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap (this process is called CPU rendering).|
| OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas *, const OH_Drawing_Brush *) | Attaches a brush to a canvas so that the canvas will use the style and color of the brush to fill in a shape.|
| OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas *, const OH_Drawing_Pen *) | Attaches a pen to a canvas so that the canvas will use the style and color of the pen to outline a shape.|
| OH_Drawing_CanvasDrawPath (OH_Drawing_Canvas *, const OH_Drawing_Path *) | Draws a path.|
| OH_Drawing_PathCreate (void) | Creates a path object.|
| OH_Drawing_PathMoveTo (OH_Drawing_Path *, float x, float y) | Sets the start point of a path.|
| OH_Drawing_PathLineTo (OH_Drawing_Path *, float x, float y) | Draws a line segment from the last point of a path to the target point.|
| OH_Drawing_PathClose (OH_Drawing_Path *) | Closes a path. A line segment from the start point to the last point of the path is added.|
| OH_Drawing_PenCreate (void) | Creates a pen object.|
| OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen *, bool) | Checks whether anti-aliasing is enabled for a pen. If anti-aliasing is enabled, edges will be drawn with partial transparency.|
| OH_Drawing_PenSetWidth (OH_Drawing_Pen *, float width) | Sets the thickness for a pen. This thickness determines the width of the outline of a shape.|
| OH_Drawing_BrushCreate (void) | Creates a brush object.|
| OH_Drawing_BrushSetColor (OH_Drawing_Brush *, uint32_t color) | Sets the color for a brush. The color will be used by the brush to fill in a shape.|
| OH_Drawing_CreateTypographyStyle (void) | Creates a `TypographyStyle` object.|
| OH_Drawing_CreateTextStyle (void) | Creates a `TextStyle` object.|
| OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate *, const char *) | Sets the text content.|
| OH_Drawing_TypographyPaint (OH_Drawing_Typography *, OH_Drawing_Canvas *, double, double) | Paints text on the canvas.|



## Development Procedure for 2D Graphics Drawing

The following steps describe how to use the canvas and brush of the Native Drawing module to draw a 2D graphics.

1. **Create a bitmap object.** Use `OH_Drawing_BitmapCreate` in `drawing_bitmap.h` to create a bitmap object (named `cBitmap` in this example), and use `OH_Drawing_BitmapBuild` to specify its length, width, and pixel format.

    ```c++
    // Create a bitmap object.
    OH_Drawing_Bitmap* cBitmap = OH_Drawing_BitmapCreate();
    // Define the pixel format of the bitmap.
    OH_Drawing_BitmapFormat cFormat {COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUYE};
    // Set the pixel format for the bitmap.
    OH_Drawing_BitmapBuild(cBitmap, width, height, &cFormat);
    ```

2. **Create a canvas object.** Use `OH_Drawing_CanvasCreate` in `drawing_canvas.h` to create a canvas object (named `cCanvas` in this example), and use `OH_Drawing_CanvasBind` to bind `cBitmap` to this canvas. The content drawn on the canvas will be output to the bound `cBitmap` object.

    ```c++
    // Create a canvas object.
    OH_Drawing_Canvas* cCanvas = OH_Drawing_CanvasCreate();
    // Bind the bitmap to the canvas. The content drawn on the canvas will be output to the bound bitmap memory.
    OH_Drawing_CanvasBind(cCanvas, cBitmap);
    // Use white to clear the canvas.
    OH_Drawing_CanvasClear(cCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
    ```

3. **Construct a shape.** Use the APIs provided in `drawing_path.h` to draw a pentagram `cPath`.

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

    // Create a path object and use the APIs to draw a pentagram.
    OH_Drawing_Path* cPath = OH_Drawing_PathCreate();
    // Specify the start point of the path.
    OH_Drawing_PathMoveTo(cPath, aX, aY);
    // Draw a line segment from the last point of a path to the target point.
    OH_Drawing_PathLineTo(cPath, bX, bY);
    OH_Drawing_PathLineTo(cPath, cX, cY);
    OH_Drawing_PathLineTo(cPath, dX, dY);
    OH_Drawing_PathLineTo(cPath, eX, eY);
    // Close the path. Now the path is drawn.
    OH_Drawing_PathClose(cPath);
    ```

4. **Set the brush and pen styles.** Use `OH_Drawing_PenCreate` in `drawing_pen.h` to create a pen (named `cPen` in this example), and set the attributes such as the anti-aliasing, color, and thickness. The pen is used to outline a shape. Use `OH_Drawing_BrushCreate` in `drawing_brush.h` to create a brush (named `cBrush` in this example), and set the brush color. The brush is used to fill in a shape. Use `OH_Drawing_CanvasAttachPen` and `OH_Drawing_CanvasAttachBrush` in `drawing_canvas.h` to attach the pen and brush to the canvas.

    ```c++
    // Create a pen object and set the anti-aliasing, color, and thickness.
    OH_Drawing_Pen* cPen = OH_Drawing_PenCreate();
    OH_Drawing_PenSetAntiAlias(cPen, true);
    OH_Drawing_PenSetColor(cPen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
    OH_Drawing_PenSetWidth(cPen, 10.0);
    OH_Drawing_PenSetJoin(cPen, LINE_ROUND_JOIN);
    // Attach the pen to the canvas.
    OH_Drawing_CanvasAttachPen(cCanvas, cPen);

    // Create a brush object and set the color.
    OH_Drawing_Brush* cBrush = OH_Drawing_BrushCreate();
    OH_Drawing_BrushSetColor(cBrush, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0xFF, 0x00));

    // Attach the brush to the canvas.
    OH_Drawing_CanvasAttachBrush(cCanvas, cBrush);
    ```

5. **Draw a shape.** Use `OH_Drawing_CanvasDrawPath` in `drawing_canvas.h` to draw a pentagram on the canvas. Call the corresponding APIs to destroy the objects when they are no longer needed.

    ```c++
    // Draw a pentagram on the canvas. The outline of the pentagram is drawn by the pen, and the color is filled in by the brush.
    OH_Drawing_CanvasDrawPath(cCanvas, cPath);
    // Destroy the created objects when they are no longer needed.
    OH_Drawing_BrushDestory(cBrush);
    OH_Drawing_PenDestory(cPen);
    OH_Drawing_PathDestory(cPath);
    ```

6. **Obtain pixel data.** Use `OH_Drawing_BitmapGetPixels` in `drawing_bitmap.h` to obtain the pixel address of the bitmap bound to the canvas. The memory to which the address points contains the pixel data of the drawing on the canvas.

    ```c++
    // Obtain the pixel address after drawing. The memory to which the address points contains the pixel data of the drawing on the canvas.
    void* bitmapAddr = OH_Drawing_BitmapGetPixels(cBitmap);
    auto ret = memcpy_s(addr, addrSize, bitmapAddr, addrSize);
    if (ret != EOK) {
        LOGI("memcpy_s failed");
    }
    // Destroy the canvas object.
    OH_Drawing_CanvasDestory(cCanvas);
    // Destroy the bitmap object.
    OH_Drawing_BitmapDestory(cBitmap);
    ```

## Development Procedure for Text Drawing

The following steps describe how to use the text drawing and display feature of the Native Drawing module.
1. **Create a canvas and a bitmap.**

    ```c++
    // Create a bitmap.
    OH_Drawing_Bitmap* cBitmap = OH_Drawing_BitmapCreate();
    OH_Drawing_BitmapFormat cFormat {COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUE};
    OH_Drawing_BitmapBuild(cBitmap, width, height, &cFormat);
    // Create a canvas.
    OH_Drawing_Canvas* cCanvas = OH_Drawing_CanvasCreate();
    OH_Drawing_CanvasBind(cCanvas, cBitmap);
    OH_Drawing_CanvasClear(cCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
    ```
  
2. **Set the typography style.**

    ```c++
    // Set the typography attributes such as left to right (LTR) for the text direction and left-aligned for the text alignment mode.
    OH_Drawing_TypographyStyle* typoStyle = OH_Drawing_CreateTypographyStyle();
    OH_Drawing_SetTypographyTextDirection(typoStyle, TEXT_DIRECTION_LTR);
    OH_Drawing_SetTypographyTextAlign(typoStyle, TEXT_ALIGN_LEFT);
    ```

3. **Set the text style.**

    ```c++
    // Set the text color, for example, black.
    OH_Drawing_TextStyle* txtStyle = OH_Drawing_CreateTextStyle();
    OH_Drawing_SetTextStyleColor(txtStyle, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
    // Set text attributes such as the font size and weight.
    double fontSize = 30;
    OH_Drawing_SetTextStyleFontSize(txtStyle, fontSize);
    OH_Drawing_SetTextStyleFontWeight(txtStyle, FONT_WEIGHT_400);
    OH_Drawing_SetTextStyleBaseLine(txtStyle, TEXT_BASELINE_ALPHABETIC);
    OH_Drawing_SetTextStyleFontHeight(txtStyle, 1);
    // Set the font families.
    const char* fontFamilies[] = {"Roboto"};
    OH_Drawing_SetTextStyleFontFamilies(txtStyle, 1, fontFamilies);
    OH_Drawing_SetTextStyleFontStyle(txtStyle, FONT_STYLE_NORMAL);
    OH_Drawing_SetTextStyleLocale(txtStyle, "en");
    ```

4. **Generate the final text display effect.**

    ```c++
    OH_Drawing_TypographyCreate* handler = OH_Drawing_CreateTypographyHandler(typoStyle,
        OH_Drawing_CreateFontCollection());
    OH_Drawing_TypographyHandlerPushTextStyle(handler, txtStyle);
    // Set the text content.
    const char* text = "OpenHarmony\n";
    OH_Drawing_TypographyHandlerAddText(handler, text);
    OH_Drawing_TypographyHandlerPopTextStyle(handler);
    OH_Drawing_Typography* typography = OH_Drawing_CreateTypography(handler);
    // Set the maximum width.
    double maxWidth = 800.0;
    OH_Drawing_TypographyLayout(typography, maxWidth);
    // Set the start position for drawing the text on the canvas.
    double position[2] = {10.0, 15.0};
    // Draw the text on the canvas.
    OH_Drawing_TypographyPaint(typography, cCanvas, position[0], position[1]);
    ```
