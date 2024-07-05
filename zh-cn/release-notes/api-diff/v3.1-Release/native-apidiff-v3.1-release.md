# Native API 差异报告

OpenHarmony 3.1 Release相较于OpenHarmony 3.0 LTS版本的API变更如下:

## 标准系统接口变更

  | 模块名称 | 接口名称                                                     | 变更类型 | 变更说明                                        |
  | -------- | ------------------------------------------------------------ | -------- | ----------------------------------------------- |
  | 图形-drawing | OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection(void) | 新增     | 创建OH_Drawing_FontCollection                   |
  | 图形-drawing | void OH_Drawing_DestroyFontCollection(OH_Drawing_FontCollection*) | 新增     | 释放被OH_Drawing_FontCollection对象占据的内存   |
  | 图形-drawing  | OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle(void) | 新增     | 创建OH_Drawing_TypographyStyle                  |
  | 图形-drawing  | void OH_Drawing_DestroyTypographyStyle(OH_Drawing_TypographyStyle*) | 新增     | 释放被OH_Drawing_TypographyStyle对象占据的内存  |
  | 图形-drawing  | void OH_Drawing_SetTypographyTextDirection(OH_Drawing_TypographyStyle*, int /* OH_Drawing_TextDirection */) | 新增     | 设置文本方向                                    |
  | 图形-drawing  | void OH_Drawing_SetTypographyTextAlign(OH_Drawing_TypographyStyle*, int /* OH_Drawing_TextAlign */) | 新增     | 设置文本对齐方式                                |
  | 图形-drawing  | void OH_Drawing_SetTypographyTextMaxLines(OH_Drawing_TypographyStyle*, int /* maxLines */) | 新增     | 设置文本最大行数                                |
  | 图形-drawing  | OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle(void)       | 新增     | 创建OH_Drawing_TextStyle                        |
  | 图形-drawing  | void OH_Drawing_DestroyTextStyle(OH_Drawing_TextStyle*)      | 新增     | 释放被OH_Drawing_TextStyle对象占据的内存        |
  | 图形-drawing  | void OH_Drawing_SetTextStyleColor(OH_Drawing_TextStyle*, uint32_t /* color */) | 新增     | 设置文本颜色                                    |
  | 图形-drawing  | void OH_Drawing_SetTextStyleFontSize(OH_Drawing_TextStyle*, double /* fontSize */); | 新增     | 设置字号                                        |
  | 图形-drawing  | void OH_Drawing_SetTextStyleFontWeight(OH_Drawing_TextStyle*, int /* OH_Drawing_FontWeight */) | 新增     | 设置字重                                        |
  | 图形-drawing  | void OH_Drawing_SetTextStyleBaseLine(OH_Drawing_TextStyle*, int /* OH_Drawing_TextBaseline */) | 新增     | 设置字体基线位置                                |
  | 图形-drawing  | void OH_Drawing_SetTextStyleDecoration(OH_Drawing_TextStyle*, int /* OH_Drawing_TextDecoration */) | 新增     | 设置装饰                                        |
  | 图形-drawing  | void OH_Drawing_SetTextStyleDecorationColor(OH_Drawing_TextStyle*, uint32_t /* color */) | 新增     | 设置装饰颜色                                    |
  | 图形-drawing  | void OH_Drawing_SetTextStyleFontHeight(OH_Drawing_TextStyle*, double /* fontHeight */) | 新增     | 设置行高，按当前字体大小的倍数进行设置                                    |
  | 图形-drawing  | void OH_Drawing_SetTextStyleFontFamilies(OH_Drawing_TextStyle*,int /* fontFamiliesNumber \*/, const char* fontFamilies[]); | 新增     | 设置字体类型                                    |
  | 图形-drawing  | void OH_Drawing_SetTextStyleFontStyle(OH_Drawing_TextStyle*, int /* OH_Drawing_FontStyle */) | 新增     | 设置字体风格                                    |
  | 图形-drawing  | void OH_Drawing_SetTextStyleLocale(OH_Drawing_TextStyle*, const char*) | 新增     | 设置语言区域                                    |
  | 图形-drawing  | OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler(OH_Drawing_TypographyStyle*, OH_Drawing_FontCollection*) | 新增     | 创建指向OH_Drawing_TypographyCreate对象的指针   |
  | 图形-drawing  | void OH_Drawing_DestroyTypographyHandler(OH_Drawing_TypographyCreate*) | 新增     | 释放被OH_Drawing_TypographyCreate对象占据的内存 |
  | 图形-drawing  | void OH_Drawing_TypographyHandlerPushTextStyle(OH_Drawing_TypographyCreate*, OH_Drawing_TextStyle*) | 新增     | 排版风格入栈                                    |
  | 图形-drawing  | void OH_Drawing_TypographyHandlerAddText(OH_Drawing_TypographyCreate*, const char*) | 新增     | 设置文本内容                                    |
  | 图形-drawing  | void OH_Drawing_TypographyHandlerPopTextStyle(OH_Drawing_TypographyCreate*) | 新增     | 排版风格出栈                                    |
  | 图形-drawing  | OH_Drawing_Typography* OH_Drawing_CreateTypography(OH_Drawing_TypographyCreate*) | 新增     | 创建OH_Drawing_Typography                       |
  | 图形-drawing  | void OH_Drawing_DestroyTypography(OH_Drawing_Typography*)    | 新增     | 释放OH_Drawing_Typography对象占据的内存         |
  | 图形-drawing  | void OH_Drawing_TypographyLayout(OH_Drawing_Typography*, double /* maxWidth */) | 新增     | 排版布局                                        |
  | 图形-drawing  | void OH_Drawing_TypographyPaint(OH_Drawing_Typography*, OH_Drawing_Canvas*, double /* potisionX */, double /\* potisionY */) | 新增     | 显示文本                                        |
| 图形-drawing    |OH_Drawing_Bitmap* OH_Drawing_BitmapCreate(void)|新增|函数用于创建一个位图对象|
| 图形-drawing    |void OH_Drawing_BitmapDestroy(OH_Drawing_Bitmap*)|新增|函数用于销毁位图对象并回收该对象占有内存|
| 图形-drawing    |void OH_Drawing_BitmapBuild(OH_Drawing_Bitmap*, const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat*)|新增|函数用于初始化位图对象的宽度和高度，并且为该位图设置像素格式|
| 图形-drawing    |uint32_t OH_Drawing_BitmapGetWidth(OH_Drawing_Bitmap*)|新增|该函数用于获取指定位图的宽度|
| 图形-drawing    |uint32_t OH_Drawing_BitmapGetHeight(OH_Drawing_Bitmap*)|新增|函数用于获取指定位图的高度|
| 图形-drawing    |void* OH_Drawing_BitmapGetPixels(OH_Drawing_Bitmap*)|新增|函数用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据|
| 图形-drawing    |OH_Drawing_Brush* OH_Drawing_BrushCreate(void)|新增|函数用于创建一个画刷对象|
| 图形-drawing    |void OH_Drawing_BrushDestroy(OH_Drawing_Brush*)|新增|函数用于销毁画刷对象并回收该对象占有的内存|
| 图形-drawing    |bool OH_Drawing_BrushIsAntiAlias(const OH_Drawing_Brush*)|新增|函数用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理|
| 图形-drawing    |void OH_Drawing_BrushSetAntiAlias(OH_Drawing_Brush*, bool)|新增|函数用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理|
| 图形-drawing    |uint32_t OH_Drawing_BrushGetColor(const OH_Drawing_Brush*)|新增|函数用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示|
| 图形-drawing    |void OH_Drawing_BrushSetColor(OH_Drawing_Brush*, uint32_t color)|新增|函数用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示|
| 图形-drawing    |OH_Drawing_Canvas* OH_Drawing_CanvasCreate(void)|新增|函数用于创建一个画布对象|
| 图形-drawing    |void OH_Drawing_CanvasDestroy(OH_Drawing_Canvas*)|新增|函数用于销毁画布对象并回收该对象占有的内存|
| 图形-drawing    |void OH_Drawing_CanvasBind(OH_Drawing_Canvas*, OH_Drawing_Bitmap*)|新增|函数用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）|
| 图形-drawing    |void OH_Drawing_CanvasAttachPen(OH_Drawing_Canvas*, const OH_Drawing_Pen*)|新增|函数用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓|
| 图形-drawing    |void OH_Drawing_CanvasDetachPen(OH_Drawing_Canvas*)|新增|函数用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓|
| 图形-drawing    |void OH_Drawing_CanvasAttachBrush(OH_Drawing_Canvas*, const OH_Drawing_Brush*)|新增|函数用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状|
| 图形-drawing    |void OH_Drawing_CanvasDetachBrush(OH_Drawing_Canvas*)|新增|函数用于去除掉画布中的画刷，使用后画布将不去填充图形形状|
| 图形-drawing    |void OH_Drawing_CanvasSave(OH_Drawing_Canvas*)|新增|函数用于保存当前画布的状态（画布矩阵）到一个栈顶|
| 图形-drawing    |void OH_Drawing_CanvasRestore(OH_Drawing_Canvas*)|新增|函数用于恢复保存在栈顶的画布状态（画布矩阵）|
| 图形-drawing    |void OH_Drawing_CanvasDrawLine(OH_Drawing_Canvas*, float x1, float y1, float x2, float y2)|新增|函数用于画一条直线段|
| 图形-drawing    |void OH_Drawing_CanvasDrawPath(OH_Drawing_Canvas*, const OH_Drawing_Path*)|新增|函数用于画一个自定义路径|
| 图形-drawing    |void OH_Drawing_CanvasClear(OH_Drawing_Canvas*, uint32_t color)|新增|函数用于使用指定颜色去清空画布|
| 图形-drawing    |uint32_t OH_Drawing_ColorSetArgb(uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue)|新增|函数用于将4个变量（分别描述透明度、红色、绿色和蓝色）转化为一个描述颜色的32位（ARGB）变量|
| 图形-drawing    |OH_Drawing_Path* OH_Drawing_PathCreate(void)|新增|函数用于创建一个路径对象|
| 图形-drawing    |void OH_Drawing_PathDestroy(OH_Drawing_Path*)|新增|函数用于销毁路径对象并回收该对象占有的内存|
| 图形-drawing    |void OH_Drawing_PathMoveTo(OH_Drawing_Path*, float x, float y)|新增|函数用于设置自定义路径的起始点位置|
| 图形-drawing    |void OH_Drawing_PathLineTo(OH_Drawing_Path*, float x, float y)|新增|函数用于添加一条从路径的最后点位置到目标点位置的线段|
| 图形-drawing    |void OH_Drawing_PathArcTo(OH_Drawing_Path*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg)|新增|函数用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆，然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段|
| 图形-drawing    |void OH_Drawing_PathQuadTo(OH_Drawing_Path*, float ctrlX, float ctrlY, float endX, float endY)|新增|函数用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线|
| 图形-drawing    |void OH_Drawing_PathCubicTo(OH_Drawing_Path*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY)|新增|函数用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线|
| 图形-drawing    |void OH_Drawing_PathClose(OH_Drawing_Path*)|新增|函数用于闭合路径，会添加一条从路径起点位置到最后点位置的线段|
| 图形-drawing    |void OH_Drawing_PathReset(OH_Drawing_Path*)|新增|函数用于重置自定义路径数据|
| 图形-drawing    |OH_Drawing_Pen* OH_Drawing_PenCreate(void)|新增|函数用于创建一个画笔对象|
| 图形-drawing    |void OH_Drawing_PenDestroy(OH_Drawing_Pen*)|新增|函数用于销毁画笔对象并回收该对象占有的内存|
| 图形-drawing    |bool OH_Drawing_PenIsAntiAlias(const OH_Drawing_Pen*)|新增|函数用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理|
| 图形-drawing    |void OH_Drawing_PenSetAntiAlias(OH_Drawing_Pen*, bool)|新增|函数用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理|
| 图形-drawing    |uint32_t OH_Drawing_PenGetColor(const OH_Drawing_Pen*)|新增|函数用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示|
| 图形-drawing    |void OH_Drawing_PenSetColor(OH_Drawing_Pen*, uint32_t color)|新增|函数用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示|
| 图形-drawing    |float OH_Drawing_PenGetWidth(const OH_Drawing_Pen*)|新增|函数用于获取画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度|
| 图形-drawing    |void OH_Drawing_PenSetWidth(OH_Drawing_Pen*, float width)|新增|函数用于设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度|
| 图形-drawing    |float OH_Drawing_PenGetMiterLimit(const OH_Drawing_Pen*)|新增|函数用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角|
| 图形-drawing    |void OH_Drawing_PenSetMiterLimit(OH_Drawing_Pen*, float miter)|新增|函数用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角|
| 图形-drawing    |OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap(const OH_Drawing_Pen*)|新增|函数用于获取画笔笔帽的样式|
| 图形-drawing    |void OH_Drawing_PenSetCap(OH_Drawing_Pen*, OH_Drawing_PenLineCapStyle)|新增|函数用于设置画笔笔帽样式|
| 图形-drawing    |OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin(const OH_Drawing_Pen*)|新增|函数用于获取画笔绘制折线转角的样式|
| 图形-drawing    |void OH_Drawing_PenSetJoin(OH_Drawing_Pen*, OH_Drawing_PenLineJoinStyle)|新增|函数用于设置画笔绘制转角的样式|
| 图形-NativeWindow    | struct NativeWindow* OH_NativeWindow_CreateNativeWindow(void* pSurface) | 新增 | 新增创建NativeWindow实例接口 |
| 图形-NativeWindow    | void OH_NativeWindow_DestroyNativeWindow(struct NativeWindow* window) | 新增 | 新增NativeWindow对象的引用计数减1接口 |
| 图形-NativeWindow    | struct NativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer(void* pSurfaceBuffer) | 新增 | 新增创建NativeWindowBuffer实例接口 |
| 图形-NativeWindow    | void OH_NativeWindow_DestroyNativeWindowBuffer(struct NativeWindowBuffer* buffer) | 新增 | 新增NativeWindowBuffer对象的引用计数减1接口 |
| 图形-NativeWindow    | int32_t OH_NativeWindow_NativeWindowRequestBuffer(struct NativeWindow *window, struct NativeWindowBuffer **buffer, int *fenceFd) | 新增 | 新增通过NativeWindow对象申请一块NativeWindowBuffer接口 |
| 图形-NativeWindow    | int32_t OH_NativeWindow_NativeWindowFlushBuffer(struct NativeWindow *window, struct NativeWindowBuffer *buffer, int fenceFd, Region region) | 新增 | 新增通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中接口 |
| 图形-NativeWindow    | int32_t OH_NativeWindow_NativeWindowAbortBuffer(struct NativeWindow *window, struct NativeWindowBuffer *buffer) | 新增 | 新增通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中接口 |
| 图形-NativeWindow    | int32_t OH_NativeWindow_NativeWindowHandleOpt(struct NativeWindow *window, int code, ...) | 新增 | 新增设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等接口 |
| 图形-NativeWindow    | BufferHandle *OH_NativeWindow_GetBufferHandleFromNative(struct NativeWindowBuffer *buffer) | 新增 | 新增通过NativeWindowBuffer获取该buffer的BufferHandle指针接口 |
| 图形-NativeWindow    | int32_t OH_NativeWindow_NativeObjectReference(void *obj) | 新增 | 新增增加一个NativeObject的引用计数接口 |
| 图形-NativeWindow    | int32_t OH_NativeWindow_NativeObjectUnreference(void *obj) | 新增 | 新增减少一个NativeObject的引用计数接口 |
| 图形-NativeWindow    | int32_t OH_NativeWindow_GetNativeObjectMagic(void *obj) | 新增 | 新增获取NativeObject的MagicId接口 |
| DFX-hilog    | LOG_DOMAIN                                                   | 新增     | 十六进制整数宏，标识日志所对应的业务领域。                   |
| DFX-hilog    | LOG_TAG                                                      | 新增     | 字符串宏，标识调用所在的类或者业务。                         |
| DFX-hilog    | LOG_APP                                                      | 新增     | 日志类型枚举，标识应用日志类型。                             |
| DFX-hilog    | LOG_DEBUG                                                    | 新增     | 日志级别枚举，标识DEBUG日志级别。                            |
| DFX-hilog    | LOG_INFO                                                     | 新增     | 日志级别枚举，标识INFO日志级别。                             |
| DFX-hilog    | LOG_WARN                                                     | 新增     | 日志级别枚举，标识WARN日志级别。                             |
| DFX-hilog    | LOG_ERROR                                                    | 新增     | 日志级别枚举，标识ERROR日志级别。                            |
| DFX-hilog    | LOG_FATAL                                                    | 新增     | 日志级别枚举，标识FATAL日志级别。                            |
| DFX-hilog    | bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level) | 新增     | 普通接口，用于检查指定业务领域、TAG、级别的日志是否可以打印。 |
| DFX-hilog    | int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...) | 新增     | 普通接口，用于写日志。                                       |
| DFX-hilog    | OH_LOG_DEBUG(type, ...)                                      | 新增     | 宏封装接口，用于写DEBUG级别日志。                            |
| DFX-hilog    | OH_LOG_INFO(type, ...)                                       | 新增     | 宏封装接口，用于写INFO级别日志。                             |
| DFX-hilog    | OH_LOG_WARN(type, ...)                                       | 新增     | 宏封装接口，用于写WARN级别日志。                             |
| DFX-hilog    | OH_LOG_ERROR(type, ...)                                      | 新增     | 宏封装接口，用于写ERROR级别日志。                            |
| DFX-hilog    | OH_LOG_FATAL(type, ...)                                      | 新增     | 宏封装接口，用于写FATAL级别日志。                            |
| zlib     | ZEXTERN uLong ZEXPORT adler32 OF((uLong adler, const Bytef *buf, uInt len));<br />ZEXTERN uLong ZEXPORT adler32_z OF((uLong adler, const Bytef *buf, z_size_t len)); | 新增     | 使用buf更新adler32                                           |
| zlib     | ZEXTERN uLong ZEXPORT adler32_combine OF((uLong, uLong, z_off_t)); <br />ZEXTERN uLong ZEXPORT adler32_combine64 OF((uLong, uLong, z_off_t)); | 新增     | 合并两个adler32                                              |
| zlib     | ZEXTERN int ZEXPORT compress2 OF((Bytef *dest,   uLongf *destLen,  const Bytef *source, uLong sourceLen,  int level));<br />ZEXTERN int ZEXPORT compress OF((Bytef *dest,   uLongf *destLen, const Bytef *source, uLong sourceLen)); | 新增     | 将源缓冲区压缩到目标缓冲区                                   |
| zlib     | ZEXTERN uLong ZEXPORT compressBound OF((uLong sourceLen));   | 新增     | 返回压缩大小的上限。在compress2/compress调用之前使用，以分配目标缓冲区 |
| zlib     | ZEXTERN uLong ZEXPORT crc32   OF((uLong crc, const Bytef *buf, uInt len));<br />ZEXTERN uLong ZEXPORT crc32_z OF((uLong adler, const Bytef *buf, z_size_t len)); | 新增     | 使用buf更新crc32                                             |
| zlib     | ZEXTERN uLong ZEXPORT crc32_combine OF((uLong, uLong, z_off_t));<br />ZEXTERN uLong ZEXPORT crc32_combine64 OF((uLong, uLong, z_off64_t)); | 新增     | 合并两个crc32                                                |
| zlib     | ZEXTERN int ZEXPORT deflate OF((z_streamp strm, int flush)); | 新增     | 压缩函数                                                     |
| zlib     | ZEXTERN uLong ZEXPORT deflateBound OF((z_streamp strm, uLong sourceLen)); | 新增     | 返回压缩大小的上限。在deflateInit/deflateInit2调用之后使用，以分配目标缓冲区 |
| zlib     | ZEXTERN int ZEXPORT deflateCopy OF((z_streamp dest, z_streamp source)); | 新增     | 将目标流设置为源流的完整副本                                 |
| zlib     | ZEXTERN int ZEXPORT deflateEnd OF((z_streamp strm));         | 新增     | 压缩完成以后,释放空间                                        |
| zlib     | ZEXTERN int ZEXPORT deflateGetDictionary OF((z_streamp strm, Bytef *dictionary, uInt  *dictLength)); | 新增     | 返回由deflate维护的滑动字典                                  |
| zlib     | ZEXTERN int ZEXPORT deflateInit_ OF((z_streamp strm, int level, const char *version, int stream_size));<br />ZEXTERN int ZEXPORT deflateInit2_ OF((z_streamp strm, int  level, int  method, int windowBits, int memLevel, int strategy, const char *version, int stream_size)); | 新增     | 压缩初始化的基础函数                                         |
| zlib     | ZEXTERN int ZEXPORT deflateParams OF((z_streamp strm, int level, int strategy)); | 新增     | 动态更新压缩级别和压缩策略                                   |
| zlib     | ZEXTERN int ZEXPORT deflatePending OF((z_streamp strm,  unsigned *pending, int *bits)); | 新增     | 返回已生成但尚未在可用输出中提供的输出的字节数和位数         |
| zlib     | ZEXTERN int ZEXPORT deflatePrime OF((z_streamp strm, int bits, int value)); | 新增     | 在压缩输出流中插入bit                                        |
| zlib     | ZEXTERN int ZEXPORT deflateReset OF((z_streamp strm));       | 新增     | 等价于 deflateEnd 后跟 deflateInit，但是不释放和重新分配内部压缩状态 |
| zlib     | ZEXTERN int ZEXPORT deflateSetDictionary OF((z_streamp strm, const Bytef *dictionary, uInt  dictLength)); | 新增     | 从给定的字节序列初始化压缩字典，而不产生任何压缩输出         |
| zlib     | ZEXTERN int ZEXPORT deflateSetHeader OF((z_streamp strm, gz_headerp head)); | 新增     | 当delateInit2()请求gzip流时，delateSetHeader()提供gzip头信息 |
| zlib     | ZEXTERN int ZEXPORT deflateTune OF((z_streamp strm, int good_length, int max_lazy, int nice_length, int max_chain)); | 新增     | 微调压缩的内部压缩参数                                       |
| zlib     | ZEXTERN int ZEXPORT gzbuffer OF((gzFile file, unsigned size)); | 新增     | 设置此库函数使用的内部缓冲区大小。默认缓冲区大小为8192字节   |
| zlib     | ZEXTERN void ZEXPORT gzclearerr OF((gzFile file));           | 新增     | 清除文件的错误和文件结束标志                                 |
| zlib     | ZEXTERN int ZEXPORT    gzclose OF((gzFile file));<br />ZEXTERN int ZEXPORT gzclose_r OF((gzFile file));<br />ZEXTERN int ZEXPORT gzclose_w OF((gzFile file)); | 新增     | 刷新所有挂起的输出，关闭压缩文件并解除压缩状态               |
| zlib     | ZEXTERN int ZEXPORT gzdirect OF((gzFile file));              | 新增     | 如果在读取时直接复制文件，则返回true (1)；如果文件是正在解压缩的gzip流，则返回false (0)。 |
| zlib     | ZEXTERN gzFile ZEXPORT gzdopen OF((int fd, const char *mode)); | 新增     | 将gzFile与文件描述符fd关联。文件描述符从open、dup、create、管道或fileno等调用中获得（如果文件以前已使用fopen打开）。mode参数与gzopen中的一样 |
| zlib     | ZEXTERN int ZEXPORT gzeof OF((gzFile file));                 | 新增     | 如果在读取时设置了文件结束指示器，则返回true (1)，否则返回false (0) |
| zlib     | ZEXTERN const char * ZEXPORT gzerror OF((gzFile file, int *errnum)); | 新增     | 返回给定压缩文件上发生的最后一个错误的错误消息               |
| zlib     | ZEXTERN int ZEXPORT gzflush OF((gzFile file, int flush));    | 新增     | 将所有挂起的输出刷新到压缩文件中                             |
| zlib     | ZEXTERN z_size_t ZEXPORT gzfread OF((voidp buf, z_size_t size, z_size_t nitems, gzFile file)); | 新增     | 从文件读取最多n个大小的item到Buf                             |
| zlib     | ZEXTERN z_size_t ZEXPORT gzfwrite OF((voidpc buf, z_size_t size, z_size_t nitems, gzFile file)); | 新增     | 将n个大小为Buf的item写入文件，复制stdio的fwrite()的接口，使用size_t请求和返回类型 |
| zlib     | ZEXTERN int ZEXPORT gzgetc OF((gzFile file));<br />ZEXTERN int ZEXPORT gzgetc_ OF((gzFile file)); | 新增     | 从压缩文件中读取一个字节                                     |
| zlib     | ZEXTERN char * ZEXPORT gzgets OF((gzFile file, char *buf, int len)); | 新增     | 从压缩文件中读取字节，直到读取len-1字符，或读取换行符并将其传输到Buf，或遇到文件结束条件 |
| zlib     | ZEXTERN z_off_t ZEXPORT gzoffset OF((gzFile));<br />ZEXTERN z_off64_t ZEXPORT gzoffset64 OF((gzFile)); | 新增     | 返回正在读取或写入的文件中的当前偏移量                       |
| zlib     | ZEXTERN gzFile ZEXPORT gzopen OF((const char *, const char *));<br />ZEXTERN gzFile ZEXPORT gzopen64 OF((const char *, const char *)); | 新增     | 打开gzip (.gz)文件以进行读取或写入                           |
| zlib     | ZEXTERN int ZEXPORTVA gzprintf Z_ARG((gzFile file, const char *format, ...)); | 新增     | 在格式字符串的控制下转换、格式化和写入参数到压缩文件中       |
| zlib     | ZEXTERN int ZEXPORT gzputc OF((gzFile file, int c));<br />ZEXTERN int ZEXPORT gzputs OF((gzFile file, const char *s)); | 新增     | 将转换为无符号字符的c写入压缩文件。gzputc返回写入的值，如果出现错误，则返回-1。 |
| zlib     | ZEXTERN int ZEXPORT gzread OF((gzFile file, voidp buf, unsigned len)); | 新增     | 从压缩文件中读取给定数量的未压缩字节                         |
| zlib     | ZEXTERN int ZEXPORT    gzrewind OF((gzFile file));           | 新增     | 重定向给定的文件                                             |
| zlib     | ZEXTERN z_off_t ZEXPORT gzseek OF((gzFile, z_off_t, int));<br />ZEXTERN z_off_t ZEXPORT gzseek64 OF((gzFile, z_off_t, int)); | 新增     | 设置给定压缩文件上下一个gzread或gzwrite的起始位置            |
| zlib     | ZEXTERN int ZEXPORT gzsetparams OF((gzFile file, int level, int strategy)); | 新增     | 动态更新压缩级别或策略                                       |
| zlib     | ZEXTERN z_off_t ZEXPORT gztell OF((gzFile));<br />ZEXTERN z_off64_t ZEXPORT gztell64 OF((gzFile)); | 新增     | 返回给定压缩文件上下一个gzread或gzwrite的起始位置            |
| zlib     | ZEXTERN int ZEXPORT gzungetc OF((int c, gzFile file));       | 新增     | 将一个字符写入流，作为下一次读取时的第一个字符读取           |
| zlib     | ZEXTERN int ZEXPORT gzwrite OF((gzFile file, voidpc buf, unsigned len)); | 新增     | 将给定数量的未压缩字节写入压缩文件                           |
| zlib     | ZEXTERN int ZEXPORT inflate OF((z_streamp strm, int flush)); | 新增     | 解压缩尽可能多的数据，并在输入缓冲区变空或输出缓冲区变满时停止 |
| zlib     | ZEXTERN int ZEXPORT inflateBack OF((z_streamp strm, in_func in, void FAR *in_desc, out_func out, void FAR *out_desc));<br />ZEXTERN int ZEXPORT inflateBackEnd OF((z_streamp strm));<br />ZEXTERN int ZEXPORT inflateBackInit_ OF((z_streamp strm, int windowBits, unsigned char FAR *window, const char *version, int stream_size)); | 新增     | 使用回调接口实现解压                                         |
| zlib     | ZEXTERN int ZEXPORT inflateCopy OF((z_streamp dest, z_streamp source)); | 新增     | 将目标流设置为源流的完整副本                                 |
| zlib     | ZEXTERN int ZEXPORT inflateEnd OF((z_streamp strm));         | 新增     | 此流的所有动态分配的数据结构都将被释放                       |
| zlib     | ZEXTERN int ZEXPORT inflateGetDictionary OF((z_streamp strm, Bytef *dictionary, uInt  *dictLength)); | 新增     | 返回由inflate维护的滑动字典                                  |
| zlib     | ZEXTERN int ZEXPORT inflateGetHeader OF((z_streamp strm, gz_headerp head)); | 新增     | 将gzip头信息存储在提供的gz_header结构中。                    |
| zlib     | ZEXTERN int ZEXPORT inflateInit_ OF((z_streamp strm, const char *version, int stream_size));<br _>/ZEXTERN int ZEXPORT inflateInit2_ OF((z_streamp strm, int  windowBits, const char *version, int stream_size)); | 新增     | 解压初始化函数                                               |
| zlib     | ZEXTERN long ZEXPORT inflateMark OF((z_streamp strm));       | 新增     | 返回两个值，一个在返回值的低16位，另一个在剩余的高位，通过将返回值向下移动16位获得。 |
| zlib     | ZEXTERN int ZEXPORT inflatePrime OF((z_streamp strm, int bits, int value)); | 新增     | 在inflate输入流中插入位                                      |
| zlib     | ZEXTERN int ZEXPORT inflateReset OF((z_streamp strm));<br />ZEXTERN int ZEXPORT inflateReset2 OF((z_streamp strm, int windowBits)); | 新增     | 此函数等效于inflateEnd后跟inflateInit，但不会释放和重新分配内部解压缩状态。流将保留可能已由inflateInit2设置的属性。 |
| zlib     | ZEXTERN int ZEXPORT inflateSetDictionary OF((z_streamp strm, const Bytef *dictionary, uInt  dictLength)); | 新增     | 从给定的未压缩字节序列初始化解压缩字典                       |
| zlib     | ZEXTERN int ZEXPORT inflateSync OF((z_streamp strm));        | 新增     | 跳过无效的压缩数据，直到找到可能的完全刷新点，或直到跳过所有可用输入。没有输出。 |
| zlib     | ZEXTERN int ZEXPORT uncompress OF((Bytef *dest,   uLongf *destLen, const Bytef *source, uLong sourceLen));<br />ZEXTERN int ZEXPORT uncompress2 OF((Bytef *dest,   uLongf *destLen, const Bytef *source, uLong *sourceLen)); | 新增     | 将源缓冲区解压到目标缓冲区，sourceLen是源缓冲区的字节长度。  |
| zlib     | ZEXTERN uLong ZEXPORT zlibCompileFlags OF((void));           | 新增     | 返回指示编译时选项的标志。                                   |
| zlib     | ZEXTERN const char * ZEXPORT zlibVersion OF((void));         | 新增     | 返回zlib版本                                                 |
| 全球化-resmgr   | NativeResourceManager *OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr) | 新增     | 新增初始化native资源管理接口                   |
| 全球化-resmgr   | void OH_ResourceManager_ReleaseNativeResourceManager(NativeResourceManager *resMgr) | 新增     | 新增释放native资源管理接口                     |
| 全球化-resmgr   | RawDir *OH_ResourceManager_OpenRawDir(const NativeResourceManager *mgr, const char *dirName) | 新增     | 新增打开指定rawfile目录接口                    |
| 全球化-resmgr   | RawFile *OH_ResourceManager_OpenRawFile(const NativeResourceManager *mgr, const char *fileName) | 新增     | 新增打开指定rawfile文件接口                    |
| 全球化-resmgr   | const char *OH_ResourceManager_GetRawFileName(RawDir *rawDir, int index) | 新增     | 新增获取rawfile名字接口                        |
| 全球化-resmgr   | int OH_ResourceManager_GetRawFileCount(RawDir *rawDir)       | 新增     | 新增获取指定rawfile目录下的rawfile文件数量接口 |
| 全球化-resmgr   | void OH_ResourceManager_CloseRawDir(RawDir *rawDir)          | 新增     | 新增释放rawfile目录相关资源接口                |
| 全球化-resmgr   | int OH_ResourceManager_ReadRawFile(const RawFile *rawFile, void *buf, size_t length) | 新增     | 新增读取指定rawfile文件接口                    |
| 全球化-resmgr   | int OH_ResourceManager_SeekRawFile(const RawFile *rawFile, long offset, int whence) | 新增     | 新增根据指定偏移量查询rawfile中的数据接口      |
| 全球化-resmgr   | long OH_ResourceManager_GetRawFileSize(RawFile *rawFile)     | 新增     | 新增获取rawfile文件size大小接口                |
| 全球化-resmgr   | void OH_ResourceManager_CloseRawFile(RawFile *rawFile)       | 新增     | 新增释放rawfile文件相关资源接口                |
| 全球化-resmgr   | long OH_ResourceManager_GetRawFileOffset(const RawFile *rawFile) | 新增     | 新增获取当前rawfile的偏移量接口                |
| 全球化-resmgr   | bool OH_ResourceManager_GetRawFileDescriptor(const RawFile *rawFile, RawFileDescriptor &descriptor) | 新增     | 新增获取rawfile的fd接口                        |
| 全球化-resmgr   | bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor) | 新增     | 新增释放rawfile的fd接口                        |
|    媒体-multimedia      |   OH_GetImageInfo       |     新增     |    通过pixel的数据地址来获取信息      |
|    媒体-multimedia      |   OH_AccessPixels       |     新增     |    锁定给定的pixel的数据地址      |
|    媒体-multimedia      |   OH_UnAccessPixels     |     新增     |    解锁给定的pixel的数据地址      |
| 媒体-audio_standard | SL_API SLresult SLAPIENTRY slCreateEngine(<br/>    SLObjectItf             *pEngine,<br/>    SLuint32                numOptions,<br/>    const SLEngineOption    *pEngineOptions,<br/>    SLuint32                numInterfaces,<br/>    const SLInterfaceID     *pInterfaceIds,<br/>    const SLboolean         * pInterfaceRequired<br/>); | 新增     | 创建并返回Engine对象      |
| 媒体-audio_standard | SLObjectItf_<br/>SLresult (*Realize) (<br/>        SLObjectItf self,<br/>        SLboolean async<br/>    ); | 新增     | 初始化Object对象          |
| 媒体-audio_standard | SLObjectItf_<br/>SLresult (*Resume) (<br/>        SLObjectItf self,<br/>        SLboolean async<br/>    ); | 新增     | 恢复Object对象            |
| 媒体-audio_standard | SLObjectItf_<br/>SLresult (*GetState) (<br/>        SLObjectItf self,<br/>        SLuint32 * pState<br/>    ); | 新增     | 获取对象的状态            |
| 媒体-audio_standard | SLObjectItf_<br/>SLresult (*GetInterface) (<br/>        SLObjectItf self,<br/>        const SLInterfaceID iid,<br/>        void * pInterface<br/>    ); | 新增     | 根据接口iid获取对象的接口 |
| 媒体-audio_standard | SLObjectItf_<br/>SLresult (*RegisterCallback) (<br/>        SLObjectItf self,<br/>        slObjectCallback callback,<br/>        void * pContext<br/>    ); | 新增     | 注册callback              |
| 媒体-audio_standard | SLObjectItf_<br/>void (*Destroy) (<br/>        SLObjectItf self<br/>    ); | 新增     | 销毁对象                  |
| 媒体-audio_standard | SLresult (*CreateAudioPlayer) (<br/>        SLEngineItf self,<br/>        SLObjectItf * pPlayer,<br/>        SLDataSource *pAudioSrc,<br/>        SLDataSink *pAudioSnk,<br/>        SLuint32 numInterfaces,<br/>        const SLInterfaceID * pInterfaceIds,<br/>        const SLboolean * pInterfaceRequired<br/>    ); | 新增     | 创建AudioPlayer对象       |
| 媒体-audio_standard | SLresult (*CreateOutputMix) (<br/>        SLEngineItf self,<br/>        SLObjectItf * pMix,<br/>        SLuint32 numInterfaces,<br/>        const SLInterfaceID * pInterfaceIds,<br/>        const SLboolean * pInterfaceRequired<br/>    ); | 新增     | 创建OutputMix对象         |
| 媒体-audio_standard | SLPlayItf_<br/>SLresult (*SetPlayState) (<br/>        SLPlayItf self,<br/>        SLuint32 state<br/>    ); | 新增     | 设置Player的状态          |
| 媒体-audio_standard | SLPlayItf_<br/>SLresult (*GetPlayState) (<br/>        SLPlayItf self,<br/>        SLuint32 *pState<br/>    ); | 新增     | 获取Player的状态          |
| 媒体-audio_standard | SLBufferQueueItf_<br/>SLresult (*Enqueue) (<br/>        SLBufferQueueItf self,<br/>        const void *pBuffer,<br/>        SLuint32 size<br/>    ); | 新增     | 向BufferQueue中填入数据   |
| 媒体-audio_standard | SLBufferQueueItf_<br/>SLresult (*Clear) (<br/>        SLBufferQueueItf self<br/>    ); | 新增     | 清除BufferQueue的数据     |
| 媒体-audio_standard | SLBufferQueueItf_<br/>SLresult (*GetState) (<br/>        SLBufferQueueItf self,<br/>        SLBufferQueueState *pState<br/>    ); | 新增     | 获取BufferQueue的状态     |
| 媒体-audio_standard | SLVolumeItf_<br/>SLresult (*SetVolumeLevel) (<br/>        SLVolumeItf self,<br/>        SLmillibel level<br/>    ); | 新增     | 设置音量分贝值            |
| 媒体-audio_standard | SLVolumeItf_<br/>SLresult (*GetVolumeLevel) (<br/>        SLVolumeItf self,<br/>        SLmillibel *pLevel<br/>    ); | 新增     | 获取音量分贝值            |
| 媒体-audio_standard | SLVolumeItf_<br/>SLresult (*GetMaxVolumeLevel) (<br/>        SLVolumeItf  self,<br/>        SLmillibel *pMaxLevel<br/>    ); | 新增     | 设置支持的最大分贝值      |
  | LIBUV | [LIBUV标准](https://gitee.com/openharmony/docs/tree/2844f08105b08115f6f5694e9f7552e2f1fe3c12/zh-cn/application-dev/reference/native-lib/third_party_libuv) | 新增 | 新增LIBUV接口 |
  | Node-API | [Node-API](https://gitee.com/openharmony/docs/blob/2844f08105b08115f6f5694e9f7552e2f1fe3c12/zh-cn/application-dev/reference/native-lib/third_party_napi/napi.md) | 新增 | NAPI组件对Node-API的接口进行了重新实现，新增支持Node-API标准库中的部分接口 |
| EGL | [EGL标准](https://github.com/KhronosGroup/EGL-Registry/tree/main/api/EGL/) | 新增 | 新增EGL接口 |
| GLES3 | [GLES3标准](https://github.com/KhronosGroup/OpenGL-Registry/tree/main/api/GLES3/) | 新增 | 新增OpenGLES3.0接口 |
| 标准C++库 | [libc++标准](https://libcxx.llvm.org/) | 新增 | 新增标准C++库接口 |
| 标准C库 | [libc、libm、libdl](https://zh.cppreference.com/w/c/header)组合实现C11标准C库 | 新增 | 新增标准C库接口 |





