# 方舟字节码文件格式

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @ctw-ian; @huyunhui1; @oh-rgx1; @zmw1-->
<!--SE: @ctw-ian; @hufeng20-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

本文详细介绍了方舟字节码文件的格式，旨在帮助开发者深入理解字节码的组成结构，以指导字节码的分析和修改。

## 约束
本文内容基于方舟字节码版本号12.0.6.0（版本号为方舟编译器内部保留字段，开发者无需关注，仅供准确对照之用）。


## 字节码文件数据类型
方舟字节码使用了多种基础和复合数据类型，以下为常见类型的定义和说明。

### 整型

| **名称**        | **说明**                           |
| -------------- | ---------------------------------- |
| `uint8_t`      | 8-bit无符号整数。                  |
| `uint16_t`     | 16-bit无符号整数，采用小端字节序。   |
| `uint32_t`     | 32-bit无符号整数，采用小端字节序。   |
| `uleb128`      | leb128编码的无符号整数。             |
| `sleb128`      | leb128编码的有符号整数。             |


### 字符串

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `utf16_length`   | `uleb128`  | 值为`len << 1 \| is_ascii`，其中`len`是字符串在UTF-16编码中的大小，`is_ascii`标记该字符串是否仅包含ASCII字符。 |
| `data`           | `uint8_t[]` | 以'\0'结尾的MUTF-8编码字符序列。  |


### TaggedValue

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                |
| -------------- | -------------- | -------------------------------------------- |
| `tag`          | `uint8_t`      | 表示数据种类的标记。                           |
| `data`         | `uint8_t[]`    | 根据不同的标记，`data`是不同类型的数据或者为空。 |


## TypeDescriptor
TypeDescriptor是类（[Class](#class)）名称的格式，由`'L'`、`'_'`、`ClassName`和`';'`组成：`L_ClassName;`。其中，`ClassName`是类的全名，名字中的`'.'`会被替换为`'/'`。


## 字节码文件布局
字节码文件起始于[Header](#header)结构。文件中的所有结构均可以从`Header`出发，直接或间接地访问到。字节码文件中结构的引用方式包括偏移量和索引。偏移量是一个32位长度的值，表示当前结构的起始位置在字节码文件中相对于文件头的字节偏移量，从0开始计算。索引是一个16位长度的值，表示当前结构在索引区域中的位置，此机制将在[IndexSection](#indexsection)章节描述。

字节码文件中所有多字节数值类型（如u16、u32和i32等）均采用小端字节序（Little-endian）存储。


### Header

- 对齐方式：单字节对齐。
- 格式：

| **名称**    | **格式** | **说明**                                               |
| ----------------- | -------------- | ------------------------------------------------------------ |
| `magic`             | `uint8_t[8]`     | 文件头魔数，值必须是`'P' 'A' 'N' 'D' 'A' '\0' '\0' '\0'`。    |
| `checksum`          | `uint32_t`       | 字节码文件除文件头魔数和本校验字段之外的内容的adler32校验和。 |
| `version`           | `uint8_t[4]`     | 字节码文件的版本号（[Version](#version)）。 |
| `file_size`         | `uint32_t`       | 字节码文件的大小，以字节为单位。                             |
| `foreign_off`       | `uint32_t`       | 偏移量，指向外部区域。外部区域中仅包含类型为[ForeignClass](#foreignclass)或[ForeignMethod](#foreignmethod)的元素。`foreign_off`指向该区域的第一个元素。 |
| `foreign_size`      | `uint32_t`       | 外部区域的大小，以字节为单位。                               |
| `num_classes`       | `uint32_t`       | [ClassIndex](#classindex)结构中元素的数量，即文件中定义的[Class](#class)的数量。 |
| `class_idx_off`     | `uint32_t`       | 偏移量，指向[ClassIndex](#classindex)。 |
| `num_lnps`          | `uint32_t`       | [LineNumberProgramIndex](#linenumberprogramindex)结构中元素的数量，即文件中定义的Line number program的数量。 |
| `lnp_idx_off`       | `uint32_t`       | 偏移量，指向[LineNumberProgramIndex](#linenumberprogramindex)。 |
| `reserved`          | `uint32_t`       | 方舟字节码文件内部使用的保留字段。                           |
| `num_index_regions` | `uint32_t`       | [IndexSection](#indexsection)结构中元素的数量，即文件中[IndexHeader](#indexheader)的数量。 |
| `index_section_off` | `uint32_t`       | 偏移量，指向[IndexSection](#indexsection)。 |


### Version
字节码版本号由4个部分组成，格式为：`主版本号.次版本号.特性版本号.编译版本号`。

| **名称** | **格式** | **说明**                                             |
| -------------- | -------------- | ---------------------------------------------------------- |
| 主版本号       | `uint8_t`        | 标识整体架构调整引入的字节码文件格式变更。                 |
| 次版本号       | `uint8_t`        | 标识局部架构调整或者重大特性调整引入的字节码文件格式变更。 |
| 特性版本号     | `uint8_t`        | 标识中小特性引入的字节码文件格式变更。                     |
| 编译版本号     | `uint8_t`        | 标识缺陷修复引入的字节码文件格式变更。                     |


### ForeignClass
描述字节码文件中的外部类。外部类在其他文件中声明，并在当前字节码文件中被引用。

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | 外部类的名称，命名遵循[TypeDescriptor](#typedescriptor)语法。 |


### ForeignMethod
描述字节码文件中的外部方法。外部方法在其他文件中声明，并在当前字节码文件中被引用。

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | 一个指向该方法所从属的类的索引，指向一个在[ClassRegionIndex](#classregionindex)中的位置，该位置的值是一个指向[Class](#class)或[ForeignClass](#foreignclass)的偏移量。 |
| `reserved`       | `uint16_t`       | 方舟字节码文件内部使用的保留字段。               |
| `name_off`       | `uint32_t`       | 一个偏移量，指向[字符串](#字符串)，表示方法名称。 |
| `index_data`     | `uleb128`        | 方法的[MethodIndexData](#methodindexdata)数据。 |

> **注意：**
> 
> 通过ForeignMethod的偏移量，可以找到偏移量所在的IndexHeader以解析`class_idx`。


### ClassIndex
ClassIndex结构能通过名称快速定位到Class的定义。

- 对齐方式：4个字节。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | 一个数组，数组中每个元素的值是一个指向[Class](#class)的偏移量。数组中的元素根据类的名称进行排序，名称遵循[TypeDescriptor](#typedescriptor)语法。数组长度由[Header](#header)中的`num_classes`指定。 |


### Class
在字节码文件中，一个类可以表示方舟字节码的一个源代码文件或者一种内置的[Annotation](#annotation)。当表示源代码文件时，类的方法对应源代码文件中的函数，类的字段对应源文件中的内部信息；当表示内置的Annotation时，类中不包含字段与方法。源代码文件中的一个类在字节码文件中表示为一个对应其构造函数的方法。

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | Class的名称，命名遵循[TypeDescriptor](#typedescriptor)语法。 |
| `reserved`       | `uint32_t`       | 方舟字节码文件内部使用的保留字段。                           |
| `access_flags`   | `uleb128`        | Class的访问标志，是[ClassAccessFlag](#classaccessflag)的组合。 |
| `num_fields`     | `uleb128`        | Class的字段的数量。                                          |
| `num_methods`    | `uleb128`        | Class的方法的数量。                                          |
| `class_data`     | `TaggedValue[]`  | 不定长度的数组，数组中每个元素都是[TaggedValue](#taggedvalue)类型，元素的标记是[ClassTag](#classtag)类型，数组中的元素按照标记递增排序（`0x00`标记除外）。 |
| `fields`         | `Field[]`        | Class的字段的数组，数组中每一个元素都是[Field](#field)类型。数组长度由`num_fields`指定。 |
| `methods`        | `Method[]`       | Class的方法的数组，数组中每一个元素都是[Method](#method)类型。数组长度由`num_methods`指定。 |


### ClassAccessFlag

| **名称** | **值** | **说明**                                               |
| -------------- | ------------ | ------------------------------------------------------------ |
| `ACC_PUBLIC`     | `0x0001`       | 默认属性，方舟字节码中的[Class](#class)均具备此标志。 |
| `ACC_ANNOTATION` | `0x2000`       | 声明该类为[Annotation](#annotation)类型。 |


### ClassTag

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **值** | **数量** | **格式** | **说明**                                               |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`  | `1`  | `none`    | 拥有此标记的[TaggedValue](#taggedvalue)，是其所在`class_data`的最后一项。 |
| `SOURCE_LANG`    | `0x02`  | `0-1` | `uint8_t` | 拥有此标记的[TaggedValue](#taggedvalue)的`data`的值为0时，表示源码语言是ArkTS/TS/JS。 |
| `SOURCE_FILE`    | `0x07`  | `0-1`  | `uint32_t`| 拥有此标记的[TaggedValue](#taggedvalue)的`data`是一个偏移量，指向[字符串](#字符串)，表示源文件的名称。 |

> **注意：**
> 
> ClassTag是`class_data`中元素（[TaggedValue](#taggedvalue)）所具备的标记，表头中的“数量”指的是在某一个[Class](#class)的`class_data`中拥有此标记的元素出现的次数。


### Field
描述字节码文件中的字段。

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | 一个指向该字段从属的类的索引，指向一个在[ClassRegionIndex](#classregionindex)中的位置，该位置的值是[Type](#type)类型，是一个指向[Class](#class)的偏移量。 |
| `type_idx`       | `uint16_t`       | 一个指向定义该字段的类型的索引，指向一个在[ClassRegionIndex](#classregionindex)中的位置，该位置的值是[Type](#type)类型。 |
| `name_off`       | `uint32_t`       | 一个偏移量，指向[字符串](#字符串)，表示字段的名称。 |
| `reserved`       | `uleb128`        | 方舟字节码文件内部使用的保留字段。                           |
| `field_data`     | `TaggedValue[]`  | 不定长度的数组，数组中每个元素都是[TaggedValue](#taggedvalue)类型，元素的标记是[FieldTag](#fieldtag)类型，数组中的元素按照标记递增排序（`0x00`标记除外）。 |

> **注意：**
> 
> 通过Field的偏移量，可以找到偏移量所在的IndexHeader以解析`class_idx`和`type_idx`。


### FieldTag

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **值** | **数量** | **格式** | **说明**  |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`   | `1`   | `none`     | 拥有此标记的[TaggedValue](#taggedvalue)，是其所在`field_data`的最后一项。 |
| `INT_VALUE`      | `0x01`   | `0-1` | `sleb128`  | 拥有此标记的[TaggedValue](#taggedvalue)的`data`的类型为`boolean`、`byte`、`char`、`short` 或 `int`。 |
| `VALUE`          | `0x02`   | `0-1` | `uint32_t` | 拥有此标记的[TaggedValue](#taggedvalue)的`data`的类型为[Value formats](#value-formats)中的`FLOAT`或`ID`。 |

> **注意：**
> 
> FieldTag是`field_data`中元素（[TaggedValue](#taggedvalue)）的标记。表头中的“数量”表示在某个[Field](#field)的`field_data`中拥有此标记的元素出现的次数。


### Method
描述字节码文件中的方法。

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | 一个指向该方法所从属的类的索引，指向一个在[ClassRegionIndex](#classregionindex)中的位置，该位置的值是[Type](#type)类型，是一个指向[Class](#class)的偏移量。 |
| `reserved`       | `uint16_t`       | 方舟字节码文件内部使用的保留字段。                           |
| `name_off`       | `uint32_t`       | 一个偏移量，指向[字符串](#字符串)，表示方法名称。 |
| `index_data`     | `uleb128`        | 方法的[MethodIndexData](#methodindexdata)数据。 |
| `method_data`    | `TaggedValue[]`  | 不定长度的数组，数组中每个元素都是[TaggedValue](#taggedvalue)类型，元素的标记是[MethodTag](#methodtag)类型，数组中的元素按照标记递增排序（`0x00`标记除外）。 |

> **注意：**
> 
> 通过Method的偏移量，可以找到偏移量所在的IndexHeader以解析`class_idx`。


### MethodIndexData
MethodIndexData是一个无符号32位整数，划分为3个部分。

| **位** | **名称** | **格式** | **说明**                                               |
| ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| 0 - 15       | `header_index`   | `uint16_t`       | 指向一个在[IndexSection](#indexsection)中的位置，该位置的值是[IndexHeader](#indexheader)。通过IndexHeader可以找到该方法引用的所有方法（[Method](#method)）、[字符串](#字符串)或字面量数组（[LiteralArray](#literalarray)）的偏移量。 |
| 16 - 23      | `function_kind`  | `uint8_t`        | 表示方法的函数类型（FunctionKind）。 |
| 24 - 31      | `reserved`       | `uint8_t`        | 方舟字节码文件内部使用的保留字段。                           |


#### FunctionKind

| **名称**           | **值** | **说明**   |
| ------------------------ | ------------ | ---------------- |
| `FUNCTION`                 | `0x1`          | 普通函数。       |
| `NC_FUNCTION`              | `0x2`          | 普通箭头函数。   |
| `GENERATOR_FUNCTION`       | `0x3`          | 生成器函数。     |
| `ASYNC_FUNCTION`           | `0x4`          | 异步函数。       |
| `ASYNC_GENERATOR_FUNCTION` | `0x5`          | 异步生成器函数。 |
| `ASYNC_NC_FUNCTION`        | `0x6`          | 异步箭头函数。   |
| `CONCURRENT_FUNCTION`      | `0x7`          | 并发函数。       |


### MethodTag

| **名称** | **值** | **数量** | **格式** | **说明**                                               |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`         | `1`             | `none`           | 拥有此标记的[TaggedValue](#taggedvalue)，是其所在`method_data`的最后一项。 |
| `CODE`           | `0x01`         | `0-1`           | `uint32_t`       | 拥有此标记的[TaggedValue](#taggedvalue)的`data`是一个偏移量，指向[Code](#code)，表示方法的代码段。 |
| `SOURCE_LANG`    | `0x02`         | `0-1`            | `uint8_t`        | 拥有此标记的[TaggedValue](#taggedvalue)的`data`为0时，表示源码语言是ArkTS/TS/JS。 |
| `DEBUG_INFO`     | `0x05`         | `0-1`            | `uint32_t`       | 拥有此标记的[TaggedValue](#taggedvalue)的`data`是一个偏移量，指向[DebugInfo](#debuginfo)，表示方法的调试信息。 |
| `ANNOTATION`     | `0x06`         | `>=0`            | `uint32_t`       | 拥有此标记的[TaggedValue](#taggedvalue)的`data`是一个偏移量，指向[Annotation](#annotation)， 表示方法的注解。 |

> **注意：**
> 
> MethodTag是`method_data`中元素（[TaggedValue](#taggedvalue)）的标记。表头中的“数量”表示在某个[Method](#method)的`method_data`中，具有此标记的元素出现的次数。


### Code

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_vregs`      | `uleb128`        | 表示寄存器的数量，不包括存放入参和默认参数的寄存器。         |
| `num_args`       | `uleb128`        | 表示入参和默认参数的总数。                                     |
| `code_size`      | `uleb128`        | 表示所有指令的总大小，以字节为单位。                             |
| `tries_size`     | `uleb128`        | `try_blocks`数组的长度，表示[TryBlock](#tryblock)的数量。 |
| `instructions`   | `uint8_t[]`      | 所有指令的数组。                                           |
| `try_blocks`     | `TryBlock[]`     | 一个数组，数组中每个元素均为TryBlock类型。|


### TryBlock

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `start_pc`       | `uleb128`        | TryBlock的第一条指令距离其所在[Code](#code)的`instructions`的起始位置的偏移量。 |
| `length`         | `uleb128`        | TryBlock的大小，以字节为单位。                               |
| `num_catches`    | `uleb128`        | 与TryBlock关联的[CatchBlock](#catchblock)的数量，值为1。 |
| `catch_blocks`   | `CatchBlock[]`   | 与TryBlock关联的CatchBlock的数组，数组中有且仅有一个可以捕获所有类型的异常的CatchBlock。 |


### CatchBlock

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                  |
| -------------- | -------------- | ----------------------------------------------- |
| `type_idx`       | `uleb128`        | 值为0，表示此CatchBlock块捕获所有类型的异常。 |
| `handler_pc`     | `uleb128`        | 异常处理逻辑的第一条指令的程序计数器。          |
| `code_size`      | `uleb128`        | 此CatchBlock的大小，以字节为单位。              |


### Annotation
描述一个注解结构。

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式**      | **说明**                                               |
| -------------- | ------------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`   | 一个指向当前Annotation所从属的类的索引，指向一个在[ClassRegionIndex](#classregionindex)中的位置，该位置的值是[Type](#type)类型，是一个指向[Class](#class)的偏移量。 |
| `count`          | `uint16_t`   | `elements`数组的长度。                                         |
| `elements`       | AnnotationElement[] | 一个数组，数组的每个元素都是[AnnotationElement](#annotationelement)类型。 |
| `element_types`  | `uint8_t[]`  | 一个数组，数组的每个元素都是[AnnotationElementTag](#annotationelementtag)类型，用于描述一个AnnotationElement。每个元素在`element_types`数组中的位置和其对应的AnnotationElement在`elements`数组中的位置一致。 |

> **注意：**
> 
> 通过Annotation的偏移量，可以找到偏移量所在的IndexHeader以解析`class_idx`。


### AnnotationElementTag

| **名称** | **标记** |
| -------------- | --------- |
| `u1`             | `'1'`   |
| `i8`             | `'2'`   |
| `u8`             | `'3'`   |
| `i16`            | `'4'`   |
| `u16`            | `'5'`   |
| `i32`            | `'6'`   |
| `u32`            | `'7'`   |
| `i64`            | `'8'`   |
| `u64`            | `'9'`   |
| `f32`            | `'A'`   |
| `f64`            | `'B'`   |
| `string`         | `'C'`   |
| `method`         | `'E'`   |
| `annotation`     | `'G'`   |
| `literalarray`   | `'#'`   |
| `unknown`        | `'0'`   |


### AnnotationElement

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name_off`       | `uint32_t`       | 一个偏移量，指向[字符串](#字符串)，表示注解元素的名称。 |
| `value`          | `uint32_t`       | 注解元素的值，若该值的宽度不超过32位，则此处存储值本身。否则，此处存储的值为指向[Value formats](#value-formats)格式的偏移量。 |


### Value formats
不同的值类型，有不同的值编码格式，包括INTEGER, LONG, FLOAT, DOUBLE, ID。

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `INTEGER`        | `uint32_t`       | 有符号的四字节整数值。                                       |
| `LONG`           | `uint64_t`       | 有符号的八字节整数值。                                       |
| `FLOAT`          | `uint32_t`       | 四字节位模式，向右零扩展，系统会将其解译为 IEEE754 32 位浮点值。 |
| `DOUBLE`         | `uint64_t`       | 八字节位模式，向右零扩展，系统会将其解译为 IEEE754 64 位浮点值。 |
| `ID`             | `uint32_t`       | 四字节位模式，表示文件中某个结构的偏移量。                   |


### LineNumberProgramIndex
行号程序索引（LineNumberProgramIndex）的结构是一个数组，便于使用更紧凑的索引访问行号程序（Line number program）。

- 对齐方式：4个字节。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | 一个数组，数组中每个元素的值是一个偏移量，指向一个行号程序。数组长度由[Header](#header)中的`num_lnps`指定。 |


### DebugInfo
调试信息（DebugInfo）包含方法的程序计数器与源代码中的行列号之间的映射以及有关局部变量的信息。调试信息的格式由[DWARF调试信息格式第3版](https://dwarfstd.org/dwarf3std.html)（见第6.2项）的内容演变形成。基于状态机（State machine）的执行模型对行号程序（Line number program）进行解释，可得到映射和局部变量信息编码。为对不同方法的相同行号程序进行去重，程序中引用的所有常量都被移动到了常量池（Constant pool）中。

- 对齐方式：单字节对齐。
- 格式：

| **名称**          | **格式** | **说明**                                               |
| ----------------------- | -------------- | ------------------------------------------------------------ |
| `line_start`              | `uleb128`        | 状态机的行号寄存器的初始值。                                 |
| `num_parameters`          | `uleb128`        | 入参和默认参数的总数量。                                     |
| `parameters`              | `uleb128[]`      | 存储方法入参名称的数组，长度为`num_parameters`。每个元素表示字符串的偏移量或0，0表示对应参数无名称。 |
| `constant_pool_size`      | `uleb128`        | 常量池的大小，以字节为单位。                                 |
| `constant_pool`           | `uleb128[]`      | 存放常量池数据的数组，数组长度是`constant_pool_size`。         |
| `line_number_program_idx` | `uleb128`        | 一个索引，指向一个在[LineNumberProgramIndex](#linenumberprogramindex)中的位置，该位置的值是一个指向Line number program的偏移量。Line number program的长度可变，以`END_SEQUENCE`操作码结束。 |


#### Constant pool
常量池（Constant pool）是DebugInfo中存放常量的结构。很多方法都具有相似的行号程序，其区别仅在于变量名、变量类型和文件名。为了对这类行号程序进行去重，程序中引用的所有常量都存储在常量池。在解释程序时，状态机维护一个指向常量池的指针。当状态机解释一条需要常量参数的指令时，会从内存常量池指针指向的位置读取值，然后递增指针。


#### State machine
状态机（State machine）的作用是产生[DebugInfo](#debuginfo)信息。状态机中有以下的寄存器：

| **名称**    | **初始值**                                             | **说明**                                               |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `address`           | 0                                                            | 程序计数器（指向方法的某个指令），只能单调递增。             |
| `line`              | [DebugInfo](#debuginfo)的属性`line_start`的值 | 无符号整数，对应源码中的行号。所有的行都是从1开始编号，因此寄存器的值不能小于1。 |
| `column`            | 0                                                            | 无符号整数，对应源码中的列号。                               |
| `file`              | `class_data`（参见[Class](#class)）中`SOURCE_FILE`标记的值，或者0 | 一个偏移量，指向[字符串](#字符串)，表示源文件的名称。如果没有文件名信息（[Class](#class)中没有`SOURCE_FILE`标记），那么寄存器的值是0。 |
| `source_code`       | 0                                                            | 一个偏移量，指向[字符串](#字符串)，表示源文件的源码。如果没有源码信息，那么寄存器的值是0。 |
| `constant_pool_ptr` | [DebugInfo](#debuginfo)中常量池的起始地址 | 指向当前常量值的指针。                                       |


#### Line number program
一个行号程序（Line number program）由指令组成。每条指令都包含一个字节的操作码以及可选参数。根据操作码的不同，参数的值可能被编码在指令中（称为指令参数），或者需要从常量池中获取（称为常量池参数）。

| **操作码**  | **值** | **指令参数**   | **常量池参数**    | **参数说明** | **说明**  |
| ----- | ----- | ------- | ---- | ------- | ------ |
| `END_SEQUENCE`         | `0x00`  |       |          |        | 标记行号程序的结束。    |
| `ADVANCE_PC`           | `0x01`  |    | `uleb128 addr_diff`   | `addr_diff`：`address`寄存器的值待增加的数值。    | `address`寄存器中的值加上`addr_diff`，指向下一个地址，而不生成位置条目。 |
| `ADVANCE_LINE`         | `0x02` |     | `sleb128 line_diff`  | `line_diff`：`line`寄存器的值待增加的数值。    | `line`寄存器中的值加上`line_diff`，指向下一个行位置，而不生成位置条目。 |
| `START_LOCAL`          | `0x03` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`   | `register_num`：将包含局部变量的寄存器。<br>`name_idx`：一个偏移量，指向[字符串](#字符串)，表示变量的名称。<br>`type_idx`：一个偏移量，指向[字符串](#字符串)，表示变量的类型。 | 在当前地址中引入一个带有名称和类型的局部变量。将要包含这个变量的寄存器的编号被编码在指令中。如果寄存器的编号是-1，则表示这个寄存器是累加器寄存器。`name_idx`和`type_idx`的值可能为0，如果为0，则代表对应的信息不存在。 |
| `START_LOCAL_EXTENDED` | `0x04` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`<br>`uleb128 sig_idx` | `register_num`：将包含局部变量的寄存器。<br>`name_idx`：一个偏移量，指向[字符串](#字符串)，表示变量的名称。<br>`type_idx`：一个偏移量，指向[字符串](#字符串)，表示变量的类型。<br>`sig_idx`：一个偏移量，指向[字符串](#字符串)，表示变量的签名。 | 在当前地址中引入一个带有名称、类型和签名的局部变量。将要包含这个变量的寄存器的编号被编码在指令中。如果寄存器的编号是-1，则表示这个寄存器是累加器寄存器。`name_idx`、`type_idx`和`sig_idx`的值可能为0，如果为0，则代表对应的信息不存在。 |
| `END_LOCAL`            | `0x05` | `sleb128 register_num` |    | `register_num`：包含局部变量的寄存器。  | 在当前地址将指定寄存器中的局部变量标记为超出范围。寄存器的编号为-1，则表示这个寄存器是累加器寄存器。 |
| `SET_FILE`             | `0x09`  |    | `uleb128 name_idx`  | `name_idx`：一个偏移量，指向[字符串](#字符串)，表示文件的名称。 | 设置`file`寄存器的值。`name_idx`的值可能为0，如果为0，则代表对应的信息不存在。 |
| `SET_SOURCE_CODE`      | `0x0a`  |    | `uleb128 source_idx` | `source_idx`：一个偏移量，指向[字符串](#字符串)，表示文件的源码。 | 设置`source_code`寄存器的值。`source_idx`的值可能为0，如果为0，则代表对应的信息不存在。 |
| `SET_COLUMN`           | `0x0b` |    | `uleb128 column_num`   | `column_num`：待设置的列号。   | 设置`column`寄存器的值，并生成一个位置条目。  |
| 特殊操作码           | `0x0c..0xff`   |   |  |   | 使 `line` 和 `address` 寄存器指向下一个地址，并生成一个位置条目。详情参阅下文中的说明。 |


对于值在`0x0c`和`0xff`（含）之间的特殊操作码，状态机按照以下步骤将`line`和`address`寄存器移动一小部分，然后生成一个新的位置条目（参见[DWARF调试信息格式第3版](https://dwarfstd.org/dwarf3std.html)第6.2.5.1项 Special Opcodes）：

| **步骤序号** | **操作**                                     | **说明**                                               |
| ----- | -------------------------------------------------- | ------------------------------------------------------------ |
| 1     | `adjusted_opcode = opcode - OPCODE_BASE`            | 计算调整后的操作码。`OPCODE_BASE`的值是`0x0c`，是第一个特殊操作码。 |
| 2     | `address += adjusted_opcode / LINE_RANGE`            | 增加`address`寄存器中的值。`LINE_RANGE`的值是15，用来计算行号信息的变化。 |
| 3     | `line += LINE_BASE + (adjusted_opcode % LINE_RANGE)` | 增加`line`寄存器中的值。`LINE_BASE`的值是-4，是最小的行号增量值；最大的行号增量值是`LINE_BASE + LINE_RANGE - 1`。 |
| 4     |                                                    | 生成一个新的位置条目。                                       |

> **注意：**
> 
> 特殊操作码计算方式：`(line_increment - LINE_BASE) + (address_increment * LINE_RANGE) + OPCODE_BASE`。


### IndexSection
通常情况下，字节码文件的各个结构使用32位偏移量来引用，当一个结构引用另一个结构时，需要在当前结构中记录被引用结构的32位偏移量。为了减小文件体积，字节码文件被分割成多个索引区域（Index region），每个索引区域内的结构使用16位索引。IndexSection结构描述了索引区域的集合。

- 对齐方式：4个字节。
- 格式：

| **名称** | **格式** | **说明**       |
| -------------- | -------------- | --------- |
| `headers`        | `IndexHeader[]`  | 一个数组，数组中每个元素是[IndexHeader](#indexheader)类型。数组中的元素根据区域的起始偏移量进行排序。数组长度由[Header](#header)中的`num_index_regions`指定。 |


### IndexHeader
每个IndexHeader结构描述一个索引区域。每个索引区域都有两类索引：指向[Type](#type)的索引和指向方法、字符串或者字面量数组的索引。

- 对齐方式：4个字节。
- 格式：

| **名称**        | **格式** | **说明**    |
| -------------- | -------------- | ---------- |
| `start_off`                             | `uint32_t`       | 该区域的起始偏移量。                                         |
| `end_off`                               | `uint32_t`       | 该区域的结束偏移量。                                         |
| `class_region_idx_size`                 | `uint32_t`       | 该区域的[ClassRegionIndex](#classregionindex)中元素的数量，最大值为65536。 |
| `class_region_idx_off`                  | `uint32_t`       | 一个偏移量，指向[ClassRegionIndex](#classregionindex)。 |
| `method_string_literal_region_idx_size` | `uint32_t`       | 该区域的[MethodStringLiteralRegionIndex](#methodstringliteralregionindex)中元素的数量，最大值为65536。 |
| `method_string_literal_region_idx_off`  | `uint32_t`       | 一个偏移量，指向[MethodStringLiteralRegionIndex](#methodstringliteralregionindex)。 |
| `reserved`                              | `uint32_t`       | 方舟字节码文件内部使用的保留字段。                           |

### ClassRegionIndex
ClassRegionIndex结构的作用是允许通过更紧凑的索引，找到对应的[Type](#type)。

- 对齐方式：4个字节。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `types`          | `Type[]`         | 一个数组，数组中每个元素都是[Type](#type)类型。数组长度由[IndexHeader](#indexheader)中的`class_region_idx_size`指定。 |


### Type
表示一个基本类型编码或一个指向[Class](#class)的偏移量，是一个32位的值。

基本类型采用以下方式编码：

| **类型**       | **编码**        |
| -------------- | -------------- |
| `u1`           | `0x00`         |
| `i8`           | `0x01`         |
| `u8`           | `0x02`         |
| `i16`          | `0x03`         |
| `u16`          | `0x04`         |
| `i32`          | `0x05`         |
| `u32`          | `0x06`         |
| `f32`          | `0x07`         |
| `f64`          | `0x08`         |
| `i64`          | `0x09`         |
| `u64`          | `0x0a`         |
| `any`          | `0x0c`         |


### MethodStringLiteralRegionIndex
MethodStringLiteralRegionIndex结构的作用是允许通过更紧凑的索引，找到对应的方法、字符串或者字面量数组。

- 对齐方式：4个字节。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`      | `uint32_t[]`   | 一个数组，数组中每个元素的值都是一个偏移量，指向方法、字符串或者字面量数组。数组长度由[IndexHeader](#indexheader)中的`method_string_literal_region_idx_size`指定。 |


### LiteralArray
描述字节码文件中的字面量数组。

- 对齐方式：单字节对齐。
- 格式：

| **名称** | **格式** | **说明**                                               |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_literals`   | `uint32_t`       | `literals`数组的长度。                                         |
| `literals`       | `Literal[]`      | 一个数组，数组的每个元素都是[Literal](#literal)类型。 |


### Literal
描述字节码文件中的字面量，根据字面量值的字节数的不同，有四种编码格式。分别是单字节编码、双字节编码、四字节编码和八字节编码。根据不同数值长度对应相应的编译格式，优化字节码文件大小。

- 对齐方式：每种格式都有对应的对齐规则。
- 格式：

| **名称** | **格式** | **说明** |
| -------------- | ------------ | -------------- |
| 单字节编码      | `uint8_t`    | 单字节的值，单字节对齐，存储用于简单类型的字面量，例如`BOOL`字面量。   |
| 双字节编码      | `uint16_t`   | 双字节的值，2个字节对齐，存储16位整型字面量。   |
| 四字节编码      | `uint32_t`   | 四字节的值，4个字节对齐，存储32位数值字面量，例如`INTEGER`整数型字面量，或`FLOAT`浮点型字面量。   |
| 八字节编码      | `uint64_t`   | 八字节的值，8个字节对齐，存储64位数值字面量，例如`DOUBLE`双精度浮点型字面量。   |
