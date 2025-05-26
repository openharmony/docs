# drawing_register_font.h

## 概述

定义绘制模块中字体管理器相关的函数。

**引用文件：** drawing_register_font.h

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [uint32_t OH_Drawing_RegisterFont(OH_Drawing_FontCollection*, const char* fontFamily, const char* familySrc)](#oh_drawing_registerfont) | 用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。 |
| [uint32_t OH_Drawing_RegisterFontBuffer(OH_Drawing_FontCollection*, const char* fontFamily, uint8_t* fontBuffer,size_t length)](#oh_drawing_registerfontbuffer) | 用于在字体管理器中注册字体缓冲区。 |

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
| [OH_Drawing_FontCollection](capi-oh-drawing-fontcollection.md)* | 指向[OH_Drawing_FontCollection](capi-oh-drawing-fontcollection.md)对象的指针。 |
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
| [OH_Drawing_FontCollection](capi-oh-drawing-fontcollection.md)* |  指向OH_Drawing_FontCollection对象的指针。 |
| const char* fontFamily | 指需要注册的字体的字体名称。 |
| uint8_t* fontBuffer | 指需要注册的字体文件的缓冲区。 |
| size_t length | 指需要注册的字体文件的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回错误代码，0为成功，6为缓冲区大小为零，7为字体集合为空，9文件损坏。 |


