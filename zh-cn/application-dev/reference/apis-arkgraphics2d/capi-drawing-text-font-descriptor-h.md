# drawing_text_font_descriptor.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## 概述

定义了字体信息的相关接口，比如获取字体信息、查找和匹配指定字体、读取字体描述符属性以及获取字体的Unicode码和字体数量等。

**引用文件：** <native_drawing/drawing_text_font_descriptor.h>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| --- | --- | --- |
| [OH_Drawing_FontVariationInstanceCoordinate](capi-drawing-oh-drawing-fontvariationinstancecoordinate.md) | OH_Drawing_FontVariationInstanceCoordinate | 可变字体属性键值对。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) | OH_Drawing_SystemFontType | 字体类型的枚举。 |
| [OH_Drawing_FontFullDescriptorAttributeId](#oh_drawing_fontfulldescriptorattributeid) | OH_Drawing_FontFullDescriptorAttributeId | 字体描述符属性的枚举。不同类型的字体描述符属性，请使用对应类型的接口获取属性。如字体描述符属性FULL_DESCRIPTOR_ATTR_I_WEIGHT为int类型，需使用[OH_Drawing_GetFontFullDescriptorAttributeInt](capi-drawing-text-font-descriptor-h.md#oh_drawing_getfontfulldescriptorattributeint)接口获取其属性值。 |
| [OH_Drawing_FontVariationAxisAttributeId](#oh_drawing_fontvariationaxisattributeid) | OH_Drawing_FontVariationAxisAttributeId | 字体可变轴属性的枚举。 |
| [OH_Drawing_FontVariationInstanceAttributeId](#oh_drawing_fontvariationinstanceattributeid) | OH_Drawing_FontVariationInstanceAttributeId | 字体可变实例属性的枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_FontDescriptor* OH_Drawing_MatchFontDescriptors(OH_Drawing_FontDescriptor* desc, size_t* num)](#oh_drawing_matchfontdescriptors) | 获取与指定字体描述符匹配的所有系统字体描述符，其中[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)的path字段不作为有效的匹配字段，其余字段不是默认值时生效。<br>如果参数desc的所有字段都是默认值，则获取所有系统字体描述符。<br>如果匹配失败，返回NULL。不再需要[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontdescriptors)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyFontDescriptors(OH_Drawing_FontDescriptor* descriptors, size_t num)](#oh_drawing_destroyfontdescriptors) | 释放字体描述符[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)数组。 |
| [OH_Drawing_FontDescriptor* OH_Drawing_GetFontDescriptorByFullName(const OH_Drawing_String* fullName,OH_Drawing_SystemFontType fontType)](#oh_drawing_getfontdescriptorbyfullname) | 根据字体名称和字体类型获取指定的字体描述符，支持系统字体、风格字体和用户已安装字体，如果获取失败则返回NULL。<br>字体描述符是描述字体特征的一种数据结构，它包含了定义字体外观和属性的详细信息。 |
| [OH_Drawing_Array* OH_Drawing_GetSystemFontFullNamesByType(OH_Drawing_SystemFontType fontType)](#oh_drawing_getsystemfontfullnamesbytype) | 根据字体类型获取对应字体的字体名称数组。 |
| [const OH_Drawing_String* OH_Drawing_GetSystemFontFullNameByIndex(OH_Drawing_Array* fullNameArray, size_t index)](#oh_drawing_getsystemfontfullnamebyindex) | 在字体名称数组中通过索引获取对应位置的字体名称，如果索引超出范围或数组无效，则返回NULL。 |
| [void OH_Drawing_DestroySystemFontFullNames(OH_Drawing_Array* fullNameArray)](#oh_drawing_destroysystemfontfullnames) | 释放通过字体类型获取的对应字体的字体名称数组占用的内存。 |
| [OH_Drawing_Array* OH_Drawing_GetFontFullDescriptorsFromStream(const void* data, size_t size)](#oh_drawing_getfontfulldescriptorsfromstream) | 根据原始二进制数据获取字体描述符数组。 |
| [OH_Drawing_Array* OH_Drawing_GetFontFullDescriptorsFromPath(const char* path)](#oh_drawing_getfontfulldescriptorsfrompath) | 根据字体文件路径获取字体描述符数组。 |
| [const OH_Drawing_FontFullDescriptor* OH_Drawing_GetFontFullDescriptorByIndex(OH_Drawing_Array* descriptorArray, size_t index)](#oh_drawing_getfontfulldescriptorbyindex) | 在字体描述符数组中通过索引获取对应的字体描述符。 |
| [void OH_Drawing_DestroyFontFullDescriptors(OH_Drawing_Array* descriptorArray)](#oh_drawing_destroyfontfulldescriptors) | 释放字体描述符数组占用的内存。 |
| [void OH_Drawing_DestroyFontFullDescriptor(const OH_Drawing_FontFullDescriptor* descriptor)](#oh_drawing_destroyfontfulldescriptor) | 释放字体描述符指针占用的内存。本函数可用于释放由[OH_Drawing_GetFontFullDescriptorByFullName](capi-drawing-text-font-descriptor-h.md#oh_drawing_getfontfulldescriptorbyfullname)接口获取的字体描述符指针。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontFullDescriptorAttributeInt(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id, int* value)](#oh_drawing_getfontfulldescriptorattributeint) | 获取int类型字体描述符的属性。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontFullDescriptorAttributeBool(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id, bool* value)](#oh_drawing_getfontfulldescriptorattributebool) | 获取bool类型字体描述符的属性。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontFullDescriptorAttributeString(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id, OH_Drawing_String* str)](#oh_drawing_getfontfulldescriptorattributestring) | 获取[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型字体描述符的属性。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontUnicodeArrayFromFile(const char* fontSrc, uint32_t index, int32_t** unicodeArray, int32_t* arrayLength)](#oh_drawing_getfontunicodearrayfromfile) | 从字体文件中获取unicode码。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontUnicodeArrayFromBuffer(uint8_t* fontBuffer, size_t length, uint32_t index, int32_t** unicodeArray, int32_t* arrayLength)](#oh_drawing_getfontunicodearrayfrombuffer) | 从字体字节流缓存中获取unicode码。 |
| [uint32_t OH_Drawing_GetFontCountFromFile(const char* fontSrc)](#oh_drawing_getfontcountfromfile) | 获取字体文件中包含的字体数量。 |
| [uint32_t OH_Drawing_GetFontCountFromBuffer(uint8_t* fontBuffer, size_t length)](#oh_drawing_getfontcountfrombuffer) | 获取字体缓存数据中包含的字体数量。 |
| [OH_Drawing_String* OH_Drawing_GetFontPathsByType(OH_Drawing_SystemFontType fontType, size_t* pathCount)](#oh_drawing_getfontpathsbytype) | 获取指定字体类型的所有字体文件路径。 |
| [OH_Drawing_Array* OH_Drawing_GetFontFullDescriptorAttributeArray(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id)](#oh_drawing_getfontfulldescriptorattributearray) | 获取字体描述符的对象数组属性。 |
| [OH_Drawing_FontVariationAxis* OH_Drawing_GetFontVariationAxisByIndex(OH_Drawing_Array* array, size_t index)](#oh_drawing_getfontvariationaxisbyindex) | 在字体可变轴数组中通过索引获取对应的字体可变轴。 |
| [void OH_Drawing_DestroyFontVariationAxis(OH_Drawing_Array* fontVariaAxisArray)](#oh_drawing_destroyfontvariationaxis) | 释放字体可变轴数组占用的内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontVariationAxisAttributeDouble(OH_Drawing_FontVariationAxis* variationAxis, OH_Drawing_FontVariationAxisAttributeId id, double *value)](#oh_drawing_getfontvariationaxisattributedouble) | 获取double类型字体可变轴的属性。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontVariationAxisAttributeInt(OH_Drawing_FontVariationAxis* variationAxis, OH_Drawing_FontVariationAxisAttributeId id, int *value)](#oh_drawing_getfontvariationaxisattributeint) | 获取int类型字体可变轴的属性。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontVariationAxisAttributeStr(OH_Drawing_FontVariationAxis* variationAxis, OH_Drawing_FontVariationAxisAttributeId id, OH_Drawing_String *str)](#oh_drawing_getfontvariationaxisattributestr) | 获取[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型字体可变轴的属性。 |
| [OH_Drawing_FontVariationInstance* OH_Drawing_GetFontVariationInstanceByIndex(OH_Drawing_Array* array, size_t index)](#oh_drawing_getfontvariationinstancebyindex) | 在字体可变实例数组中通过索引获取对应的字体可变实例。 |
| [void OH_Drawing_DestroyFontVariationInstance(OH_Drawing_Array* fontVariaAxisInstance)](#oh_drawing_destroyfontvariationinstance) | 释放字体可变实例数组占用的内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_GetFontVariationInstanceAttributeStr(OH_Drawing_FontVariationInstance* variationInstance, OH_Drawing_FontVariationInstanceAttributeId id, OH_Drawing_String* str)](#oh_drawing_getfontvariationinstanceattributestr) | 获取[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型字体可变实例的属性。 |
| [OH_Drawing_FontVariationInstanceCoordinate* OH_Drawing_GetFontVariationInstanceCoordinate(OH_Drawing_FontVariationInstance* variationInstance, size_t* arrayLength)](#oh_drawing_getfontvariationinstancecoordinate) | 获取字体可变实例的可变字体属性对象。 |
| [const OH_Drawing_FontFullDescriptor* OH_Drawing_GetFontFullDescriptorByFullName(const OH_Drawing_String* fullName, OH_Drawing_SystemFontType fontType)](#oh_drawing_getfontfulldescriptorbyfullname) | 根据字体名称和字体类型获取字体完整描述符对象。 |

## 枚举类型说明

### OH_Drawing_SystemFontType

```c
enum OH_Drawing_SystemFontType
```

**描述**

字体类型的枚举。

**起始版本：** 14

| 枚举项 | 描述 |
| -- | -- |
| ALL = 1 << 0 | 所有字体类型。 |
| GENERIC = 1 << 1 | 系统字体类型。 |
| STYLISH = 1 << 2 | 风格字体类型。 |
| INSTALLED = 1 << 3 | 用户已安装字体类型。 |
| CUSTOMIZED = 1 << 4 | 自定义字体类型。<br/> **起始版本：** 18|

### OH_Drawing_FontFullDescriptorAttributeId

```c
enum OH_Drawing_FontFullDescriptorAttributeId
```

**描述**

字体描述符属性的枚举。不同类型的字体描述符属性，请使用对应类型的接口获取属性。如字体描述符属性FULL_DESCRIPTOR_ATTR_I_WEIGHT为int类型，需使用[OH_Drawing_GetFontFullDescriptorAttributeInt](capi-drawing-text-font-descriptor-h.md#oh_drawing_getfontfulldescriptorattributeint)接口获取其属性值。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| FULL_DESCRIPTOR_ATTR_S_PATH = 0 | 字体文件的路径，[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型。 |
| FULL_DESCRIPTOR_ATTR_S_POSTSCRIPT_NAME = 1 | 唯一标识字体的名称，[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型。 |
| FULL_DESCRIPTOR_ATTR_S_FULL_NAME = 2 | 字体的名称，[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型。 |
| FULL_DESCRIPTOR_ATTR_S_FAMILY_NAME = 3 | 字体家族的名称，[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型。 |
| FULL_DESCRIPTOR_ATTR_S_SUB_FAMILY_NAME = 4 | 子字体家族的名称，[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型。 |
| FULL_DESCRIPTOR_ATTR_I_WEIGHT = 5 | 字体的字重，int类型。 |
| FULL_DESCRIPTOR_ATTR_I_WIDTH = 6 | 字体的宽窄风格属性，int类型。 |
| FULL_DESCRIPTOR_ATTR_I_ITALIC = 7 | 字体是否倾斜，int类型。1表示字体倾斜，0表示字体非倾斜。 |
| FULL_DESCRIPTOR_ATTR_B_MONO = 8 | 字体是否等宽，bool类型。true表示字体等宽，false表示字体非等宽。 |
| FULL_DESCRIPTOR_ATTR_B_SYMBOLIC = 9 | 字体是否支持符号字体，bool类型。true表示支持符号字体，false表示不支持符号字体。 |
| FULL_DESCRIPTOR_ATTR_S_LOCAL_POSTSCRIPT_NAME = 10 | 根据系统语言配置提取字体唯一标识的名称。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_LOCAL_FULL_NAME = 11 | 根据系统语言配置提取字体全名。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_LOCAL_FAMILY_NAME = 12 | 根据系统语言配置提取字体家族名称。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_LOCAL_SUB_FAMILY_NAME = 13 | 根据系统语言配置提取子字体家族名称。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_VERSION = 14 | 字体版本。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_MANUFACTURE = 15 | 字体制造商信息。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_COPYRIGHT = 16 | 字体版权信息。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_TRADEMARK = 17 | 字体商标信息。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_S_LICENSE = 18 | 字体许可证信息。<br>**起始版本：** 23 |
| FULL_DESCRIPTOR_ATTR_O_VARIATION_AXIS = 19 | 字体可变轴数组。<br>**起始版本：** 24 |
| FULL_DESCRIPTOR_ATTR_O_VARIATION_INSTANCE = 20 | 字体可变实例数组。<br>**起始版本：** 24 |
| FULL_DESCRIPTOR_ATTR_I_INDEX = 21 | 字体索引。<br>**起始版本：** 23 |

### OH_Drawing_FontVariationAxisAttributeId

```c
enum OH_Drawing_FontVariationAxisAttributeId
```

**描述**

字体可变轴属性的枚举。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| FONT_VARIATION_AXIS_ATTR_S_KEY = 0 | 字体可变轴的关键字标识。 |
| FONT_VARIATION_AXIS_ATTR_D_MIN_VALUE = 1 | 字体可变轴的最小值。 |
| FONT_VARIATION_AXIS_ATTR_D_MAX_VALUE = 2 | 字体可变轴的最大值。 |
| FONT_VARIATION_AXIS_ATTR_D_DEFAULT_VALUE = 3 | 字体可变轴的默认值。 |
| FONT_VARIATION_AXIS_ATTR_I_FLAGS = 4 | 字体可变轴的标志位。值为0时表示该轴对用户可见，值为1时表示该轴应隐藏。 |
| FONT_VARIATION_AXIS_ATTR_S_NAME = 5 | 字体可变轴的英文名称。 |
| FONT_VARIATION_AXIS_ATTR_S_LOCAL_NAME = 6 | 字体可变轴的本地化名称。 |

### OH_Drawing_FontVariationInstanceAttributeId

```c
enum OH_Drawing_FontVariationInstanceAttributeId
```

**描述**

字体可变实例属性的枚举。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| FONT_VARIATION_INSTANCE_ATTR_S_NAME = 0 | 字体可变实例的英文名称。 |
| FONT_VARIATION_INSTANCE_ATTR_S_LOCAL_NAME = 1 | 字体可变实例的本地化名称。 |

## 函数说明

### OH_Drawing_MatchFontDescriptors()

```c
OH_Drawing_FontDescriptor* OH_Drawing_MatchFontDescriptors(OH_Drawing_FontDescriptor* desc, size_t* num)
```

**描述**

获取与指定字体描述符匹配的所有系统字体描述符，其中[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)的path字段不作为有效的匹配字段，其余字段不是默认值时生效。<br>如果参数desc的所有字段都是默认值，则获取所有系统字体描述符。<br>如果匹配失败，返回NULL。不再需要[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontdescriptors)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* desc | 指向字体描述符[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)对象的指针。<br>建议使用[OH_Drawing_CreateFontDescriptor](capi-drawing-text-typography-h.md#oh_drawing_createfontdescriptor)获得有效的[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)实例。<br>如果自己创建[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)实例，请确保不用于匹配的字段是默认值。 |
| size_t* num | 出参，用于接收返回值数组的成员个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* | [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)数组，释放时请使用[OH_Drawing_DestroyFontDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontdescriptors)。 |

### OH_Drawing_DestroyFontDescriptors()

```c
void OH_Drawing_DestroyFontDescriptors(OH_Drawing_FontDescriptor* descriptors, size_t num)
```

**描述**

释放字体描述符[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* descriptors | 需要释放的字体描述符[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)数组指针。 |
| size_t num | [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)数组的成员个数。 |

### OH_Drawing_GetFontDescriptorByFullName()

```c
OH_Drawing_FontDescriptor* OH_Drawing_GetFontDescriptorByFullName(const OH_Drawing_String* fullName,OH_Drawing_SystemFontType fontType)
```

**描述**

根据字体名称和字体类型获取指定的字体描述符，支持系统字体、风格字体和用户已安装字体，如果获取失败则返回NULL。<br>字体描述符是描述字体特征的一种数据结构，它包含了定义字体外观和属性的详细信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_String](capi-drawing-oh-drawing-string.md)* fullName | 表示指向字体名称字符串[OH_Drawing_String](capi-drawing-oh-drawing-string.md)的指针。 |
| [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) fontType | 表示字体类型的枚举值[OH_Drawing_SystemFontType](capi-drawing-text-font-descriptor-h.md#oh_drawing_systemfonttype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* | 指向字体描述符对象[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)的指针，不再需要[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptor](capi-drawing-text-typography-h.md#oh_drawing_destroyfontdescriptor)接口释放该对象的指针。 |

### OH_Drawing_GetSystemFontFullNamesByType()

```c
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
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* | 返回对应字体类型的字体名称数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针，不再需要[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)时，请使用[OH_Drawing_DestroySystemFontFullNames](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroysystemfontfullnames)接口释放该对象的指针。 |

### OH_Drawing_GetSystemFontFullNameByIndex()

```c
const OH_Drawing_String* OH_Drawing_GetSystemFontFullNameByIndex(OH_Drawing_Array* fullNameArray, size_t index)
```

**描述**

在字体名称数组中通过索引获取对应位置的字体名称，如果索引超出范围或数组无效，则返回NULL。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* fullNameArray | 表示字体名称数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。 |
| size_t index | 数组的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const [OH_Drawing_String](capi-drawing-oh-drawing-string.md)* | 返回对应索引的字体名称[OH_Drawing_String](capi-drawing-oh-drawing-string.md)的指针。 |

### OH_Drawing_DestroySystemFontFullNames()

```c
void OH_Drawing_DestroySystemFontFullNames(OH_Drawing_Array* fullNameArray)
```

**描述**

释放通过字体类型获取的对应字体的字体名称数组占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* fullNameArray | 表示字体名称数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。 |


### OH_Drawing_GetFontFullDescriptorsFromStream()

```c
OH_Drawing_Array* OH_Drawing_GetFontFullDescriptorsFromStream(const void* data, size_t size)
```

**描述**

根据原始二进制数据获取字体描述符数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const void* data | 指向原始二进制字体数据缓冲区的指针。 |
| size_t size | 以字节为单位的字体数据缓冲区的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Array*](capi-drawing-oh-drawing-array.md) | 返回指向对应字体文件的字体描述符数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针，不再需要OH_Drawing_Array时，请使用[OH_Drawing_DestroyFontFullDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontfulldescriptors)接口释放该对象的指针。<br>如果因数据格式无效或解析错误导致操作失败，返回NULL。 |

### OH_Drawing_GetFontFullDescriptorsFromPath()

```c
OH_Drawing_Array* OH_Drawing_GetFontFullDescriptorsFromPath(const char* path)
```

**描述**

根据字体文件路径获取字体描述符数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* path | 需要查询的字体文件的路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Array*](capi-drawing-oh-drawing-array.md) | 返回指向对应字体文件的字体描述符数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针，不再需要OH_Drawing_Array时，请使用[OH_Drawing_DestroyFontFullDescriptors](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontfulldescriptors)接口释放该对象的指针。<br>如果字体文件未找到、字体文件路径无效、字体文件无权限或者文件非字体格式，返回NULL。 |

### OH_Drawing_GetFontFullDescriptorByIndex()

```c
const OH_Drawing_FontFullDescriptor* OH_Drawing_GetFontFullDescriptorByIndex(OH_Drawing_Array* descriptorArray, size_t index)
```

**描述**

在字体描述符数组中通过索引获取对应的字体描述符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* descriptorArray | 表示指向字体描述符数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。 |
| size_t index | 数组的索引，索引值从0开始。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const [OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)* | 返回指向指定索引处字体描述符对象[OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)的指针。<br>如果索引超出范围或数组无效，则返回NULL。 |

### OH_Drawing_DestroyFontFullDescriptors()

```c
void OH_Drawing_DestroyFontFullDescriptors(OH_Drawing_Array* descriptorArray)
```

**描述**

释放字体描述符数组占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* descriptorArray | 表示指向字体描述符数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。 |

### OH_Drawing_DestroyFontFullDescriptor()

```c
void OH_Drawing_DestroyFontFullDescriptor(const OH_Drawing_FontFullDescriptor* descriptor)
```

**描述**

释放字体描述符指针占用的内存。本函数可用于释放由[OH_Drawing_GetFontFullDescriptorByFullName](capi-drawing-text-font-descriptor-h.md#oh_drawing_getfontfulldescriptorbyfullname)接口获取的字体描述符指针。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)* descriptor | 表示指向字体描述符对象[OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)的指针。 |

### OH_Drawing_GetFontFullDescriptorAttributeInt()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontFullDescriptorAttributeInt(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id, int* value)
```

**描述**

获取int类型字体描述符的属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)* descriptor | 指向字体描述符对象[OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)的指针。 |
| [OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid) id | 字体描述符属性id。从[OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid)中可获取字体描述符属性。 |
| int* value | 指向int类型属性的指针。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数descriptor或者value为空指针。<br>返回OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH，表示传入属性id与调用函数不匹配。 |

### OH_Drawing_GetFontFullDescriptorAttributeBool()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontFullDescriptorAttributeBool(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id, bool* value)
```

**描述**

获取bool类型字体描述符的属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)* descriptor | 指向字体描述符对象[OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)的指针。 |
| [OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid) id | 字体描述符属性id。从[OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid)中可获取字体描述符属性。 |
| bool* value | 指向bool类型属性的指针。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数descriptor或者value为空指针。<br>返回OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH，表示传入属性id与调用函数不匹配。 |

### OH_Drawing_GetFontFullDescriptorAttributeString()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontFullDescriptorAttributeString(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id, OH_Drawing_String* str)
```

**描述**

获取[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型字体描述符的属性。

> **说明：** 
> 如果不再需要OH_Drawing_String，调用方需要手动释放OH_Drawing_String结构体内部的strData成员。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)* descriptor | 指向字体描述符对象[OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)的指针。 |
| [OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid) id | 字体描述符属性id。从[OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid)中可获取字体描述符属性。 |
| [OH_Drawing_String](capi-drawing-oh-drawing-string.md)* str | 指向OH_Drawing_String类型属性的指针。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数descriptor或者str为空指针。<br>返回OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH，表示传入属性id与调用函数不匹配。 |

### OH_Drawing_GetFontUnicodeArrayFromFile()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontUnicodeArrayFromFile(const char* fontSrc, uint32_t index, int32_t** unicodeArray, int32_t* arrayLength)
```

**描述**

从字体文件中获取unicode码。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* fontSrc | 字体文件路径。 |
| uint32_t index | ttc/otc文件中字体的索引，取值范围为[0, 字体数量-1]，非ttc/otc文件需设置为0。 |
| int32_t** unicodeArray | 出参，用于接收unicode码数组，当不需要时，使用free()释放。 |
| int32_t* arrayLength | 出参，用于接收unicode码数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示传入字体路径非法、传入非字体文件或参数unicodeArray、arrayLength为NULL。 |

### OH_Drawing_GetFontUnicodeArrayFromBuffer()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontUnicodeArrayFromBuffer(uint8_t* fontBuffer, size_t length, uint32_t index, int32_t** unicodeArray, int32_t* arrayLength)
```

**描述**

从字体字节流缓存中获取unicode码。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t* fontBuffer | 字体文件数据。 |
| size_t length | 字体文件数据长度。 |
| uint32_t index | ttc/otc文件中字体的索引，取值范围为[0, 字体数量-1]，非ttc/otc文件需设置为0。 |
| int32_t** unicodeArray | 出参，用于接收unicode码数组，当不需要时，使用free()释放。 |
| int32_t* arrayLength | 出参，用于接收unicode码数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示缓存数据非法或缓存数据不是字体文件数据或参数unicodeArray、arrayLength为NULL。 |

### OH_Drawing_GetFontCountFromFile()

```c
uint32_t OH_Drawing_GetFontCountFromFile(const char* fontSrc)
```

**描述**

获取字体文件中包含的字体数量。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* fontSrc | 字体文件路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 字体数量。 |

### OH_Drawing_GetFontCountFromBuffer()

```c
uint32_t OH_Drawing_GetFontCountFromBuffer(uint8_t* fontBuffer, size_t length)
```

**描述**

获取字体缓存数据中包含的字体数量。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t* fontBuffer | 字体缓存数据。 |
| size_t length | 字体数据长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 字体数量。 |

### OH_Drawing_GetFontPathsByType()

```c
OH_Drawing_String* OH_Drawing_GetFontPathsByType(OH_Drawing_SystemFontType fontType, size_t* pathCount)
```

**描述**

获取指定字体类型的所有字体文件路径。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_SystemFontType](capi-drawing-text-font-descriptor-h.md#oh_drawing_systemfonttype) fontType | 系统字体类型对象 [OH_Drawing_SystemFontType](capi-drawing-text-font-descriptor-h.md#oh_drawing_systemfonttype) 的枚举。 |
| size_t* pathCount | 出参，用于接收返回的字体路径列表的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_String*](capi-drawing-oh-drawing-string.md) | 返回字体路径列表。不再需要时，请使用free释放该对象指针以及每个OH_Drawing_String对象内部持有的指针。 |

### OH_Drawing_GetFontFullDescriptorAttributeArray()

```c
OH_Drawing_Array* OH_Drawing_GetFontFullDescriptorAttributeArray(const OH_Drawing_FontFullDescriptor* descriptor, OH_Drawing_FontFullDescriptorAttributeId id)
```

**描述**

获取字体描述符的对象数组属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)* descriptor | 指向字体描述符对象[OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)的指针。 |
| [OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid) id | 字体描述符属性id。从[OH_Drawing_FontFullDescriptorAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontfulldescriptorattributeid)中可获取字体描述符属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Array*](capi-drawing-oh-drawing-array.md) | 返回对象数组，获取失败时返回NULL。当id为FULL_DESCRIPTOR_ATTR_O_VARIATION_AXIS时，不再需要时请使用[OH_Drawing_DestroyFontVariationAxis](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontvariationaxis)接口释放；当id为FULL_DESCRIPTOR_ATTR_O_VARIATION_INSTANCE时，不再需要时请使用[OH_Drawing_DestroyFontVariationInstance](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontvariationinstance)接口释放。 |

### OH_Drawing_GetFontVariationAxisByIndex()

```c
OH_Drawing_FontVariationAxis* OH_Drawing_GetFontVariationAxisByIndex(OH_Drawing_Array* array, size_t index)
```

**描述**

在字体可变轴数组中通过索引获取对应的字体可变轴。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* array | 指向字体可变轴数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针，通过[OH_Drawing_GetFontFullDescriptorAttributeArray](capi-drawing-text-font-descriptor-h.md#oh_drawing_getfontfulldescriptorattributearray)获取。 |
| size_t index | 数组的索引，索引值从0开始。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontVariationAxis*](capi-drawing-oh-drawing-fontvariationaxis.md) | 返回指向指定索引处字体可变轴对象[OH_Drawing_FontVariationAxis](capi-drawing-oh-drawing-fontvariationaxis.md)的指针。<br>如果索引超出范围或数组无效，则返回NULL。 |

### OH_Drawing_DestroyFontVariationAxis()

```c
void OH_Drawing_DestroyFontVariationAxis(OH_Drawing_Array* fontVariaAxisArray)
```

**描述**

释放字体可变轴数组占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* fontVariaAxisArray | 指向字体可变轴数组对象[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。 |

### OH_Drawing_GetFontVariationAxisAttributeDouble()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontVariationAxisAttributeDouble(OH_Drawing_FontVariationAxis* variationAxis, OH_Drawing_FontVariationAxisAttributeId id, double *value)
```

**描述**

获取double类型字体可变轴的属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontVariationAxis](capi-drawing-oh-drawing-fontvariationaxis.md)* variationAxis | 指向字体可变轴对象[OH_Drawing_FontVariationAxis](capi-drawing-oh-drawing-fontvariationaxis.md)的指针。 |
| [OH_Drawing_FontVariationAxisAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationaxisattributeid) id | 字体可变轴属性id。从[OH_Drawing_FontVariationAxisAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationaxisattributeid)中可获取字体可变轴的属性。 |
| double *value | 指向double类型属性的指针。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数variationAxis或者value为空指针。<br>返回OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH，表示传入属性id与调用函数不匹配。 |

### OH_Drawing_GetFontVariationAxisAttributeInt()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontVariationAxisAttributeInt(OH_Drawing_FontVariationAxis* variationAxis, OH_Drawing_FontVariationAxisAttributeId id, int *value)
```

**描述**

获取int类型字体可变轴的属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontVariationAxis](capi-drawing-oh-drawing-fontvariationaxis.md)* variationAxis | 指向字体可变轴对象[OH_Drawing_FontVariationAxis](capi-drawing-oh-drawing-fontvariationaxis.md)的指针。 |
| [OH_Drawing_FontVariationAxisAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationaxisattributeid) id | 字体可变轴属性id。从[OH_Drawing_FontVariationAxisAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationaxisattributeid)中可获取字体可变轴的属性。 |
| int *value | 指向int类型属性的指针。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数variationAxis或者value为空指针。<br>返回OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH，表示传入属性id与调用函数不匹配。 |

### OH_Drawing_GetFontVariationAxisAttributeStr()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontVariationAxisAttributeStr(OH_Drawing_FontVariationAxis* variationAxis, OH_Drawing_FontVariationAxisAttributeId id, OH_Drawing_String *str)
```

**描述**

获取[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型字体可变轴的属性。

> **说明：** 
>
> 如果不再需要OH_Drawing_String，调用方需要手动释放OH_Drawing_String结构体内部的strData成员。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontVariationAxis](capi-drawing-oh-drawing-fontvariationaxis.md)* variationAxis | 指向字体可变轴对象[OH_Drawing_FontVariationAxis](capi-drawing-oh-drawing-fontvariationaxis.md)的指针。 |
| [OH_Drawing_FontVariationAxisAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationaxisattributeid) id | 字体可变轴属性id。从[OH_Drawing_FontVariationAxisAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationaxisattributeid)中可获取字体可变轴的属性。 |
| [OH_Drawing_String](capi-drawing-oh-drawing-string.md) *str | 指向OH_Drawing_String类型属性的指针。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数variationAxis或者str为空指针。<br>返回OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH，表示传入属性id与调用函数不匹配。 |

### OH_Drawing_GetFontVariationInstanceByIndex()

```c
OH_Drawing_FontVariationInstance* OH_Drawing_GetFontVariationInstanceByIndex(OH_Drawing_Array* array, size_t index)
```

**描述**

在字体可变实例数组中通过索引获取对应的字体可变实例。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* array | 指向字体可变实例数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。通过[OH_Drawing_GetFontFullDescriptorAttributeArray](capi-drawing-text-font-descriptor-h.md#oh_drawing_getfontfulldescriptorattributearray)获取。 |
| size_t index | 数组的索引，索引值从0开始。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontVariationInstance*](capi-drawing-oh-drawing-fontvariationinstance.md) | 返回指向指定索引处字体可变实例对象[OH_Drawing_FontVariationInstance](capi-drawing-oh-drawing-fontvariationinstance.md)的指针。<br>如果索引超出范围或数组无效，则返回NULL。 |

### OH_Drawing_DestroyFontVariationInstance()

```c
void OH_Drawing_DestroyFontVariationInstance(OH_Drawing_Array* fontVariaAxisInstance)
```

**描述**

释放字体可变实例数组占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* fontVariaAxisInstance | 指向字体可变实例数组对象[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。 |

### OH_Drawing_GetFontVariationInstanceAttributeStr()

```c
OH_Drawing_ErrorCode OH_Drawing_GetFontVariationInstanceAttributeStr(OH_Drawing_FontVariationInstance* variationInstance, OH_Drawing_FontVariationInstanceAttributeId id, OH_Drawing_String* str)
```

**描述**

获取[OH_Drawing_String](capi-drawing-oh-drawing-string.md)类型字体可变实例的属性。

> **说明：** 
>
> 如果不再需要OH_Drawing_String，调用方需要手动释放OH_Drawing_String结构体内部的strData成员。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontVariationInstance](capi-drawing-oh-drawing-fontvariationinstance.md)* variationInstance | 指向字体可变实例对象[OH_Drawing_FontVariationInstance](capi-drawing-oh-drawing-fontvariationinstance.md)的指针。 |
| [OH_Drawing_FontVariationInstanceAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationinstanceattributeid) id | 字体可变实例属性id。从[OH_Drawing_FontVariationInstanceAttributeId](capi-drawing-text-font-descriptor-h.md#oh_drawing_fontvariationinstanceattributeid)中可获取字体可变实例属性。 |
| [OH_Drawing_String](capi-drawing-oh-drawing-string.md)* str | 指向OH_Drawing_String类型属性的指针。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数variationInstance或者str为空指针。<br>返回OH_DRAWING_ERROR_ATTRIBUTE_ID_MISMATCH，表示传入属性id与调用函数不匹配。 |

### OH_Drawing_GetFontVariationInstanceCoordinate()

```c
OH_Drawing_FontVariationInstanceCoordinate* OH_Drawing_GetFontVariationInstanceCoordinate(OH_Drawing_FontVariationInstance* variationInstance, size_t* arrayLength)
```

**描述**

获取字体可变实例的可变字体属性对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontVariationInstance](capi-drawing-oh-drawing-fontvariationinstance.md)* variationInstance | 指向字体可变实例的指针。 |
| size_t* arrayLength | 指向OH_Drawing_FontVariationInstanceCoordinate列表长度的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontVariationInstanceCoordinate*](capi-drawing-oh-drawing-fontvariationinstancecoordinate.md) | 返回指向可变字体属性列表的指针，若variationInstance无效则返回NULL。 |

### OH_Drawing_GetFontFullDescriptorByFullName()

```c
const OH_Drawing_FontFullDescriptor* OH_Drawing_GetFontFullDescriptorByFullName(const OH_Drawing_String* fullName, OH_Drawing_SystemFontType fontType)
```

**描述**

根据字体名称和字体类型获取字体完整描述符对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_String](capi-drawing-oh-drawing-string.md)* fullName | 指向字体名称对象[OH_Drawing_String](capi-drawing-oh-drawing-string.md)的指针。 |
| [OH_Drawing_SystemFontType](capi-drawing-text-font-descriptor-h.md#oh_drawing_systemfonttype) fontType | 系统字体类型对象[OH_Drawing_SystemFontType](capi-drawing-text-font-descriptor-h.md#oh_drawing_systemfonttype)的枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [const OH_Drawing_FontFullDescriptor*](capi-drawing-oh-drawing-fontfulldescriptor.md) | 返回指向字体完整描述符对象[OH_Drawing_FontFullDescriptor](capi-drawing-oh-drawing-fontfulldescriptor.md)的指针。不再需要OH_Drawing_FontFullDescriptor时，请使用[OH_Drawing_DestroyFontFullDescriptor](capi-drawing-text-font-descriptor-h.md#oh_drawing_destroyfontfulldescriptor)接口释放该对象的指针。 |