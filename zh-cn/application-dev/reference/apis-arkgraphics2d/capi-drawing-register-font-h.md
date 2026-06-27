# drawing_register_font.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## 概述

定义绘制模块中字体管理器相关的函数，提供自定义字体的注册、注销以及字体格式检测能力，支持ttf、otf、ttc和otc等多种字体文件格式。

**引用文件：** <native_drawing/drawing_register_font.h>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [uint32_t OH_Drawing_RegisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, const char* familySrc)](#oh_drawing_registerfont) | 用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。 |
| [uint32_t OH_Drawing_RegisterFontBuffer(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, uint8_t* fontBuffer,size_t length)](#oh_drawing_registerfontbuffer) | 用于在字体管理器中注册字体缓冲区，支持从ttf、otf文件读取的数据。 |
| [uint32_t OH_Drawing_UnregisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily)](#oh_drawing_unregisterfont) | 通过字体名称取消注册自定义字体。<br> 取消注册当前正在使用的字体可能导致文本渲染异常，包括乱码或字形缺失。<br> 所有使用被取消注册的字体名称的排版对象都应该被销毁重建。 |
| [uint32_t OH_Drawing_RegisterFontByIndex(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, const char* familySrc, uint32_t index)](#oh_drawing_registerfontbyindex) | 使用ttc/otc文件注册自定义字体，通过index参数指定需要注册的字体索引。 |
| [uint32_t OH_Drawing_RegisterFontBufferByIndex(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, uint8_t* fontBuffer, size_t length, uint32_t index)](#oh_drawing_registerfontbufferbyindex) | 使用ttc/otc文件字节流注册字体。 |
| [bool OH_Drawing_IsFontSupportedFromPath(const char* path)](#oh_drawing_isfontsupportedfrompath) | 检查系统是否支持指定路径的字体格式。 |
| [bool OH_Drawing_IsFontSupportedFromBuffer(uint8_t* data, size_t dataLength)](#oh_drawing_isfontsupportedfrombuffer) | 检查系统是否支持缓冲区中指定的字体格式。 |

## 函数说明

### OH_Drawing_RegisterFont()

```c
uint32_t OH_Drawing_RegisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, const char* familySrc)
```

**描述**

用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 需要注册的字体的字体名称。 |
| const char* familySrc | 需要注册的字体文件的路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数执行结果。0表示接口执行成功，1表示文件不存在，2表示打开文件失败，3表示读取文件失败，4表示寻找文件失败，5表示获取大小失败，8表示fontCollection为NULL，9表示文件损坏。 |

### OH_Drawing_RegisterFontBuffer()

```c
uint32_t OH_Drawing_RegisterFontBuffer(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, uint8_t* fontBuffer,size_t length)
```

**描述**

用于在字体管理器中注册字体缓冲区，支持从ttf、otf文件读取的数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection |  指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 需要注册的字体的字体名称。 |
| uint8_t* fontBuffer | 需要注册的字体文件的缓冲区。 |
| size_t length | 需要注册的字体文件的长度，需与fontBuffer实际长度保持一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数执行结果。0表示接口执行成功，6表示fontBuffer为NULL，7表示缓冲区大小为零，8表示fontCollection为NULL。 |

### OH_Drawing_UnregisterFont()

```c
uint32_t OH_Drawing_UnregisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily)
```

**描述**

通过字体名称取消注册自定义字体。

取消注册当前正在使用的字体可能导致文本渲染异常，包括乱码或字形缺失。

所有使用被取消注册的字体名称的排版对象都应该被销毁重建。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 需要取消注册的字体名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数执行结果。0表示函数执行成功，8表示入参不合法，1表示取消注册失败。 |

### OH_Drawing_RegisterFontByIndex()

```c
uint32_t OH_Drawing_RegisterFontByIndex(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, const char* familySrc, uint32_t index)
```

**描述**

使用ttc/otc文件注册自定义字体，通过index参数指定需要注册的字体索引。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 需要注册的字体的字体名称。 |
| const char* familySrc | 需要注册的字体文件的路径。 |
| uint32_t index | 字体在ttc/otc文件中的索引，取值范围为[0, 字体数量-1]，非ttc/otc格式文件需设置为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数执行结果。0表示函数执行成功，1表示文件不存在，2表示打开文件失败，3表示读取文件失败，4表示寻找文件失败，5表示获取大小失败，8表示fontCollection为NULL，9表示文件损坏。 |

### OH_Drawing_RegisterFontBufferByIndex()

```c
uint32_t OH_Drawing_RegisterFontBufferByIndex(OH_Drawing_FontCollection* fontCollection, const char* fontFamily, uint8_t* fontBuffer, size_t length, uint32_t index)
```

**描述**

使用ttc/otc文件字节流注册字体。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象的指针。 |
| const char* fontFamily | 需要注册的字体的字体名称。 |
| uint8_t* fontBuffer | 需要注册的字体文件的字节流数据。 |
| size_t length | 字节流数据长度，需与fontBuffer实际长度保持一致。 |
| uint32_t index | 字体在ttc/otc文件中的索引，取值范围为[0, 字体数量-1]，非ttc/otc格式文件需设置为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数执行结果。0表示函数执行成功，6表示fontBuffer为NULL，7表示缓冲区大小为0，8表示fontCollection为空，9表示文件损坏。 |

### OH_Drawing_IsFontSupportedFromPath()

```c
bool OH_Drawing_IsFontSupportedFromPath(const char* path)
```

**描述**

检查系统是否支持指定路径的字体格式。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* path | 字体文件的绝对路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持该字体则返回true；否则返回false。 |

### OH_Drawing_IsFontSupportedFromBuffer()

```c
bool OH_Drawing_IsFontSupportedFromBuffer(uint8_t* data, size_t dataLength)
```

**描述**

检查系统是否支持缓冲区中指定的字体格式。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t* data | 包含字体数据的内存缓冲区的指针。 |
| size_t dataLength | 字体数据的大小（以字节为单位），需与data实际长度保持一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持该字体则返回true；否则返回false。 |