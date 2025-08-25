# drawing_register_font.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## 概述

定义绘制模块中字体管理器相关的函数。

**引用文件：** <native_drawing/drawing_register_font.h>

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [uint32_t OH_Drawing_RegisterFont(OH_Drawing_FontCollection*, const char* fontFamily, const char* familySrc)](#oh_drawing_registerfont) | 用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。 |
| [uint32_t OH_Drawing_RegisterFontBuffer(OH_Drawing_FontCollection*, const char* fontFamily, uint8_t* fontBuffer,size_t length)](#oh_drawing_registerfontbuffer) | 用于在字体管理器中注册字体缓冲区。 |
| [uint32_t OH_Drawing_UnregisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily)](#oh_drawing_unregisterfont) | 通过字体家族名称取消注册自定义字体。<br> 取消注册当前正在使用的字体可能导致文本渲染异常，包括乱码或字形缺失。<br> 所有使用被取消注册的字体家族名称的排版对象都应该被销毁重建。 |

## 函数说明

### OH_Drawing_RegisterFont()

```
uint32_t OH_Drawing_RegisterFont(OH_Drawing_FontCollection*, const char* fontFamily, const char* familySrc)
```

**描述**

用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | 指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 指需要注册的字体的字体名称。 |
| const char* familySrc | 指需要注册的字体文件的路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回错误代码，0为成功，1为文件不存在，2为打开文件失败，3为读取文件失败，4为寻找文件失败，5为获取大小失败，9文件损坏。 |

### OH_Drawing_RegisterFontBuffer()

```
uint32_t OH_Drawing_RegisterFontBuffer(OH_Drawing_FontCollection*, const char* fontFamily, uint8_t* fontBuffer,size_t length)
```

**描述**

用于在字体管理器中注册字体缓冲区。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* |  指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 指需要注册的字体的字体名称。 |
| uint8_t* fontBuffer | 指需要注册的字体文件的缓冲区。 |
| size_t length | 指需要注册的字体文件的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回错误代码，0为成功，6为缓冲区大小为零，7为字体集合为空，9文件损坏。 |

### OH_Drawing_UnregisterFont()

```
uint32_t OH_Drawing_UnregisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily)
```

**描述**

通过字体家族名称取消注册自定义字体。

取消注册当前正在使用的字体可能导致文本渲染异常，包括乱码或字形缺失。

所有使用被取消注册的字体家族名称的排版对象都应该被销毁重建。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 需要取消注册的字体家族名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回执行结果状态码，0为成功，8为入参不合法，1为取消注册失败。 |