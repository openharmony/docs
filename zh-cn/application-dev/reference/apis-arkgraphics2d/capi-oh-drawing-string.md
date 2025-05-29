# OH_Drawing_String

## 概述

采用UTF-16编码的字符串信息结构体。

**起始版本：** 14

**相关模块：** [Drawing](capi-drawing.md)

**所在头文件：** [drawing_types.h](capi-drawing-types-h.md)

## 汇总

### 成员变量

| 名称             | 描述                                          |
| ---------------- | --------------------------------------------- |
| uint8_t* strData | 指向包含UTF-16编码的字节数组的指针。          |
| uint32_t strLen  | `strData`指向的字符串的实际长度，单位为字节。 |

