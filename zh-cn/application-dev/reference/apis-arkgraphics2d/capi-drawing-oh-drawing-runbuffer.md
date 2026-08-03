# OH_Drawing_RunBuffer
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

```c
typedef struct {...} OH_Drawing_RunBuffer
```

## 概述

结构体用于描述一块内存，描述文字和位置信息。

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

**所在头文件：** [drawing_text_blob.h](capi-drawing-text-blob-h.md)

## 汇总

### 成员变量

| 名称               | 描述                                  |
| ------------------ | ------------------------------------- |
| uint16_t* glyphs   | 存储字形索引。                        |
| float* pos         | 存储文字的位置。单位为物理像素px。                      |
| char* utf8text     | 存储文字UTF-8编码。                   |
| uint32_t* clusters | 存储文字簇UTF-8编码（簇指的是集合）。 |

