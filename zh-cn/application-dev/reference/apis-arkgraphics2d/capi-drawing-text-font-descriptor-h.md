# drawing_text_font_descriptor.h

## 概述

定义了字体信息的相关接口，比如获取字体信息，查找指定字体等。

**引用文件：** <native_drawing/drawing_text_font_descriptor.h>

**库：** libnative_drawing.so

**起始版本：** 14

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) | OH_Drawing_SystemFontType | 字体类型的枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_FontDescriptor* OH_Drawing_MatchFontDescriptors(OH_Drawing_FontDescriptor* desc, size_t* num)](#oh_drawing_matchfontdescriptors) | 获取与指定字体描述符匹配的所有系统字体描述符，其中[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)的path字段不作为有效的匹配字段，其余字段不是默认值时生效。<br>如果参数desc的所有字段都是默认值，则获取所有系统字体描述符。<br>如果匹配失败，返回NULL。不再需要[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontdescriptors)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyFontDescriptors(OH_Drawing_FontDescriptor* descriptors, size_t num)](#oh_drawing_destroyfontdescriptors) | 释放字体描述符[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)数组。 |
| [OH_Drawing_FontDescriptor* OH_Drawing_GetFontDescriptorByFullName(const OH_Drawing_String* fullName,OH_Drawing_SystemFontType fontType)](#oh_drawing_getfontdescriptorbyfullname) | 根据字体名称和字体类型获取指定的字体描述符，支持系统字体、风格字体和用户已安装字体。<br>字体描述符是描述字体特征的一种数据结构，它包含了定义字体外观和属性的详细信息。 |
| [OH_Drawing_Array* OH_Drawing_GetSystemFontFullNamesByType(OH_Drawing_SystemFontType fontType)](#oh_drawing_getsystemfontfullnamesbytype) | 根据字体类型获取对应字体的字体名称数组。 |
| [const OH_Drawing_String* OH_Drawing_GetSystemFontFullNameByIndex(OH_Drawing_Array* fullNameArray, size_t index)](#oh_drawing_getsystemfontfullnamebyindex) | 在字体名称数组中通过索引获取对应位置的字体名称。 |
| [void OH_Drawing_DestroySystemFontFullNames(OH_Drawing_Array* fullNameArray)](#oh_drawing_destroysystemfontfullnames) | 释放通过字体类型获取的对应字体的字体名称数组占用的内存。 |

## 枚举类型说明

### OH_Drawing_SystemFontType

```
enum OH_Drawing_SystemFontType
```

**描述**

字体类型的枚举。

**起始版本：** 14

| 枚举项 | 描述 |
| -- | -- |
| ALL = 1 << 0 | 所有字体类型。 |
| GENERIC = 1 << 1 | 系统字体类型。 |
| STYLISH = 1 << 2 | 风格字体类型 |
| INSTALLED = 1 << 3 | 用户已安装字体类型。 |
| CUSTOMIZED = 1 << 4 | 自定义字体类型。<br/> **起始版本：** 18|


## 函数说明

### OH_Drawing_MatchFontDescriptors()

```
OH_Drawing_FontDescriptor* OH_Drawing_MatchFontDescriptors(OH_Drawing_FontDescriptor* desc, size_t* num)
```

**描述**

获取与指定字体描述符匹配的所有系统字体描述符，其中[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)的path字段不作为有效的匹配字段，其余字段不是默认值时生效。<br>如果参数desc的所有字段都是默认值，则获取所有系统字体描述符。<br>如果匹配失败，返回NULL。不再需要[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontdescriptors)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)* desc | 指针。<br>建议使用[OH_Drawing_CreateFontDescriptor](capi-drawing-text-typography-h.md#oh_drawing_createfontdescriptor)获得有效的[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)实例。<br>如果自己创建[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)实例，请确保不用于匹配的字段是默认值。 |
| size_t* num | 表示返回值数组的成员个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)* | [OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)数组，释放时请使用[OH_Drawing_DestroyFontDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontdescriptors)。 |

### OH_Drawing_DestroyFontDescriptors()

```
void OH_Drawing_DestroyFontDescriptors(OH_Drawing_FontDescriptor* descriptors, size_t num)
```

**描述**

释放字体描述符[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)* descriptors | 数组。 |
| size_t num | [OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)数组的成员个数。 |

### OH_Drawing_GetFontDescriptorByFullName()

```
OH_Drawing_FontDescriptor* OH_Drawing_GetFontDescriptorByFullName(const OH_Drawing_String* fullName,OH_Drawing_SystemFontType fontType)
```

**描述**

根据字体名称和字体类型获取指定的字体描述符，支持系统字体、风格字体和用户已安装字体。<br>字体描述符是描述字体特征的一种数据结构，它包含了定义字体外观和属性的详细信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_String](capi-oh-drawing-string.md)* fullName | 表示指向字体名称字符串[OH_Drawing_String](capi-oh-drawing-string.md)的指针。 |
| [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) fontType | 表示字体类型的枚举值[OH_Drawing_SystemFontType](capi-drawing-text-font-descriptor-h.md#oh_drawing_systemfonttype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)* | 指向字体描述符对象[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)的指针，不再需要[OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptor](capi-drawing-text-typography-h.md#oh_drawing_destroyfontdescriptor)接口释放该对象的指针。 |

### OH_Drawing_GetSystemFontFullNamesByType()

```
OH_Drawing_Array* OH_Drawing_GetSystemFontFullNamesByType(OH_Drawing_SystemFontType fontType)
```

**描述**

根据字体类型获取对应字体的字体名称数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) fontType | 表示字体类型的枚举值[OH_Drawing_SystemFontType](capi-drawing-text-font-descriptor-h.md#oh_drawing_systemfonttype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Array](capi-oh-drawing-array.md)* | 返回对应字体类型的字体名称数组[OH_Drawing_Array](capi-oh-drawing-array.md)的指针，不再需要[OH_Drawing_Array](capi-oh-drawing-array.md)时，请使用[OH_Drawing_DestroySystemFontFullNames](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroysystemfontfullnames)接口释放该对象的指针。 |

### OH_Drawing_GetSystemFontFullNameByIndex()

```
const OH_Drawing_String* OH_Drawing_GetSystemFontFullNameByIndex(OH_Drawing_Array* fullNameArray, size_t index)
```

**描述**

在字体名称数组中通过索引获取对应位置的字体名称。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-oh-drawing-array.md)* fullNameArray | 表示字体名称数组[OH_Drawing_Array](capi-oh-drawing-array.md)的指针。 |
| size_t index | 数组的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const [OH_Drawing_String](capi-oh-drawing-string.md)* | 返回对应索引的字体名称[OH_Drawing_String](capi-oh-drawing-string.md)的指针。 |

### OH_Drawing_DestroySystemFontFullNames()

```
void OH_Drawing_DestroySystemFontFullNames(OH_Drawing_Array* fullNameArray)
```

**描述**

释放通过字体类型获取的对应字体的字体名称数组占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-oh-drawing-array.md)* fullNameArray | 表示字体名称数组[OH_Drawing_Array](capi-oh-drawing-array.md)的指针。 |


