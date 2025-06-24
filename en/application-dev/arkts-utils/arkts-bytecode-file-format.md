# Ark Bytecode File Format
This topic describes the Ark bytecode file format in detail, aiming to help you understand its structure and facilitate the analysis and modification of bytecode files.


## Constraints
This topic is based on Ark bytecode of version 12.0.6.0. The version number is an internal field of the ArkCompiler and does not require your attention.


## Bytecode File Data Types
The Ark bytecode uses a variety of basic and composite data types. Below are the definitions and explanations for common types.

### Integer

| **Name**       | **Description**                          |
| -------------- | ---------------------------------- |
| `uint8_t`      | 8-bit unsigned integer.                 |
| `uint16_t`     | 16-bit unsigned integer in little-endian mode.  |
| `uint32_t`     | 32-bit unsigned integer in little-endian mode.  |
| `uleb128`      | Unsigned integer encoded in LEB128 format.            |
| `sleb128`      | Signed integer encoded in LEB128 format.            |


### String

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `utf16_length`   | `uleb128`  | The value is **len << 1 \**| **is_ascii**, where **len** is the length of a string encoded by UTF-16, and **is_ascii** specifies whether the string contains only ASCII characters.|
| `data`           | `uint8_t[]` | Null-terminated sequence of characters encoded in MUTF-8 format. |


### TaggedValue

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                               |
| -------------- | -------------- | -------------------------------------------- |
| `tag`          | `uint8_t`      | Marker indicating the type of data.                          |
| `data`         | `uint8_t[]`    | Data content. Its type is determined by the tag, and it may be empty.|


## TypeDescriptor
Represents [class](#class) names in the format of **L_ClassName;**, where **ClassName** is the fully qualified name, in which **'.'** is replaced with **'/'**.


## Bytecode File Layout
The bytecode file begins with the [Header](#header) structure, from which all other structures can be accessed directly or indirectly. References within the file use offsets (32-bit) and indexes (16-bit). Offsets indicate the position relative to the file header, starting from 0. Indexes point to specific entries within index regions. More details are provided in [IndexSection](#indexsection).

All multi-byte values in bytecode files are stored in little-endian format.


### Header

- Alignment: single-byte aligned
- Format

| **Name**   | **Format**| **Description**                                              |
| ----------------- | -------------- | ------------------------------------------------------------ |
| `magic`             | `uint8_t[8]`     | Magic number of the file header. Its value must be **'P' 'A' 'N' 'D' 'A' '\0' '\0' '\0'**.   |
| `checksum`          | `uint32_t`       | **Adler32** checksum of the content in the bytecode file, excluding the magic number and this checksum field.|
| `version`           | `uint8_t[4]`     | [Version](#version) of the bytecode file.|
| `file_size`         | `uint32_t`       | Size of the bytecode file, in bytes.                            |
| `foreign_off`       | `uint32_t`       | An offset that points to a foreign region, which contains only elements of the type [ForeignClass](#foreignclass) or [ForeignMethod](#foreignmethod). **foreign_off** points to the first element in the region.|
| `foreign_size`      | `uint32_t`       | Size of the foreign region, in bytes.                              |
| `num_classes`       | `uint32_t`       | Number of elements in the [ClassIndex](#classindex) structure, that is, the number of [classes](#class) defined in the file.|
| `class_idx_off`     | `uint32_t`       | An offset that points to [ClassIndex](#classindex).|
| `num_lnps`          | `uint32_t`       | Number of elements in the [LineNumberProgramIndex](#linenumberprogramindex) structure, that is, the number of [line number programs](#line-number-program) defined in the file.|
| `lnp_idx_off`       | `uint32_t`       | An offset that points to [LineNumberProgramIndex](#linenumberprogramindex).|
| `reserved`          | `uint32_t`       | Reserved field for internal use by the Ark bytecode file.                          |
| `reserved`          | `uint32_t`       | Reserved field for internal use by the Ark bytecode file.                          |
| `num_index_regions` | `uint32_t`       | Number of elements in the [IndexSection](#indexsection) structure, that is, the number of [IndexHeaders](#indexheader) in the file.|
| `index_section_off` | `uint32_t`       | An offset that points to [IndexSection](#indexsection).|


### Version
The bytecode version number consists of four parts in the format of major.minor.feature.build.

| **Name**| **Format**| **Description**                                            |
| -------------- | -------------- | ---------------------------------------------------------- |
| Major      | `uint8_t`        | Indicates significant architectural changes.                |
| Minor      | `uint8_t`        | Indicates changes in local architecture or major features.|
| Feature    | `uint8_t`        | Indicates changes due to minor features.                    |
| Build    | `uint8_t`        | Indicates changes due to bug fixes.                    |


### ForeignClass
Represents foreign classes referenced in the bytecode file but declared in other files.

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | Foreign class name, which follows the [TypeDescriptor](#typedescriptor) syntax.|


### ForeignMethod
Represents foreign methods referenced in the bytecode file but declared in other files.

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index of the class to which the method belongs. It points to a position in [ClassRegionIndex](#classregionindex), and the position value is an offset pointing to [Class](#class) or [ForeignClass](#foreignclass).|
| `reserved`       | `uint16_t`       | Reserved field for internal use by the Ark bytecode file.              |
| `name_off`       | `uint32_t`       | An offset to a [string](#string) representing the method name.|
| `index_data`     | `uleb128`        | [MethodIndexData](#methodindexdata) data of the method.|

> **NOTE**
> 
> The offset of **ForeignMethod** can be used to locate **IndexHeader** at that offset to parse **class_idx**.


### ClassIndex
Facilitates quick lookup of class definitions by name.

- Alignment: 4-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | An array of offsets pointing to [classes](#class). Elements in the array are sorted by the class name, which follows the [TypeDescriptor](#typedescriptor) syntax. The array length is specified by **num_classes** in [Header](#header).|


### Class
Represents either a source code file or an internal [Annotation](#annotation). For a source code file, **methods** correspond to functions in the source code file, and **fields** correspond to internal information in the source file. For **Annotation**, **fields** or **methods** are not contained. A class in the source code file is represented as a constructor in the bytecode file.

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | Class name, which follows the [TypeDescriptor](#typedescriptor) syntax.|
| `reserved`       | `uint32_t`       | Reserved field for internal use by the Ark bytecode file.                          |
| `access_flags`   | `uleb128`        | Tags to access the class, which is a combination of [ClassAccessFlags](#classaccessflag).|
| `num_fields`     | `uleb128`        | Number of fields in the class.                                         |
| `num_methods`    | `uleb128`        | Number of methods in the class.                                         |
| `class_data`     | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [ClassTag](#classtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|
| `fields`         | `Field[]`        | Array of fields in the class. Each element in this array is of the [Field](#field) type. The array length is specified by **num_fields**.|
| `methods`        | `Method[]`       | Array of methods in the class. Each element in this array is of the [Method](#method) type. The array length is specified by **num_methods**.|


### ClassAccessFlag

| **Name**| **Value**| **Description**                                              |
| -------------- | ------------ | ------------------------------------------------------------ |
| `ACC_PUBLIC`     | `0x0001`       | Default attribute. All [classes](#class) in the Ark bytecode file have this tag.|
| `ACC_ANNOTATION` | `0x2000`       | Declares this class as the [Annotation](#annotation) type.|


### ClassTag

- Alignment: single-byte aligned
- Format

| **Name**| **Value**| **Quantity**| **Format**| **Description**                                              |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`  | `1`  | `none`    | Marks a [TaggedValue](#taggedvalue) as the final item in **class_data**.|
| `SOURCE_LANG`    | `0x02`  | `0-1 ` | `uint8_t` | **data** of a [TaggedValue](#taggedvalue) with this tag is **0**, indicating that the source code language is in ArkTS, TS, or JS.|
| `SOURCE_FILE`    | `0x07`  | `0-1`  | `uint32_t`| **data** of a [TaggedValue](#taggedvalue) with this tag is an offset that points to a [string](#string) representing the source file name.|

> **NOTE**
> 
> **ClassTag** is a marker of the element ([TaggedValue](#taggedvalue)) in **class_data**. **Quantity** in the table header refers to the number of occurrences of the element with this tag in **class_data** of a [class](#class).


### Field
Represents fields within the bytecode file.

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index of the class to which the field belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `type_idx`       | `uint16_t`       | An index of the type of the field. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type.|
| `name_off`       | `uint32_t`       | An offset to a [string](#string) representing the field name.|
| `reserved`       | `uleb128`        | Reserved field for internal use by the Ark bytecode file.                          |
| `field_data`     | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [FieldTag](#fieldtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|

> **NOTE**
> 
> The offset of **Field** can be used to locate **IndexHeader** at that offset to parse **class_idx** and **type_idx**.


### FieldTag

- Alignment: single-byte aligned
- Format

| **Name**| **Value**| **Quantity**| **Format**| **Description** |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`   | `1`   | `none`     | Marks a [TaggedValue](#taggedvalue) as the final item in **field_data**.|
| `INT_VALUE`      | `0x01`   | `0-1` | `sleb128`  | The **data** type of a [TaggedValue](#taggedvalue) with this tag is of **boolean**, **byte**, **char**, **short**, or **int**.|
| `VALUE`          | `0x02`   | `0-1` | `uint32_t` | The **data** type of a [TaggedValue](#taggedvalue) with this tag is of **FLOAT** or **ID** in [Value formats](#value-formats).|

> **NOTE**
> 
> **FieldTag** is a marker of the element ([TaggedValue](#taggedvalue)) in **field_data**. **Quantity** in the table header refers to the number of occurrences of the element with this tag in **field_data** of a [field](#field).


### Method
Represents methods within the bytecode file.

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index of the class to which the method belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `reserved`       | `uint16_t`       | Reserved field for internal use by the Ark bytecode file.                          |
| `name_off`       | `uint32_t`       | An offset to a [string](#string) representing the method name.|
| `index_data`     | `uleb128`        | [MethodIndexData](#methodindexdata) data of the method.|
| `method_data`    | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [MethodTag](#methodtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|

> **NOTE**
> 
> The offset of **Method** can be used to locate **IndexHeader** at that offset to parse **class_idx**.


### MethodIndexData
A 32-bit unsigned integer, divided into three parts.

| **Bit**| **Name**| **Format**| **Description**                                              |
| ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| 0 - 15       | `header_index`   | `uint16_t`       | Points to a position in [IndexSection](#indexsection). The value of this position is [IndexHeader](#indexheader). You can use **IndexHeader** to find the offsets of all methods ([Method](#method)), [string](#string), or literal array ([LiteralArray](#literalarray)) referenced by this method.|
| 16 - 23      | `function_kind`  | `uint8_t`        | Function type ([FunctionKind](#functionkind)) of a method.|
| 24 - 31      | `reserved`       | `uint8_t`        | Reserved field for internal use by the Ark bytecode file.                          |


#### FunctionKind

| **Name**          | **Value**| **Description**  |
| ------------------------ | ------------ | ---------------- |
| `FUNCTION`                 | `0x1`          | Common function.      |
| `NC_FUNCTION`              | `0x2`          | Common arrow function.  |
| `GENERATOR_FUNCTION`       | `0x3`          | Generator function.    |
| `ASYNC_FUNCTION`           | `0x4`          | Asynchronous function.      |
| `ASYNC_GENERATOR_FUNCTION` | `0x5`          | Asynchronous generator function.|
| `ASYNC_NC_FUNCTION`        | `0x6`          | Asynchronous arrow function.  |
| `CONCURRENT_FUNCTION`      | `0x7`          | Concurrent function.      |


### MethodTag

| **Name**| **Value**| **Quantity**| **Format**| **Description**                                              |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`         | `1`             | `none`           | Marks a [TaggedValue](#taggedvalue) as the final item in **method_data**.|
| `CODE`           | `0x01`         | `0-1 `           | `uint32_t`       | **data** of a [TaggedValue](#taggedvalue) with this tag is an offset pointing to [Code](#code), indicating the code segment of the method.|
| `SOURCE_LANG`    | `0x02`         | `0-1`            | `uint8_t`        | **data** of a [TaggedValue](#taggedvalue) with this tag is **0**, indicating that the source code language is in ArkTS, TS, or JS.|
| `DEBUG_INFO`     | `0x05`         | `0-1`            | `uint32_t`       | **data** of a [TaggedValue](#taggedvalue) with this tag is an offset pointing to [DebugInfo](#debuginfo), indicating the debugging information of the method.|
| `ANNOTATION`     | `0x06`         | `>=0`            | `uint32_t`       | **data** of a [TaggedValue](#taggedvalue) with this tag is an offset pointing to [Annotation](#annotation), indicating the annotation of the method.|

> **NOTE**
> 
> **MethodTag** is a marker of the element ([TaggedValue](#taggedvalue)) in **method_data**. **Quantity** in the table header refers to the number of occurrences of the element with this tag in **method_data** of a [method](#method).


### Code

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_vregs`      | `uleb128`        | Number of registers. Registers that store input and default parameters are not counted.        |
| `num_args`       | `uleb128`        | Total number of input and default parameters.                                    |
| `code_size`      | `uleb128`        | Total size of all instructions, in bytes.                            |
| `tries_size`     | `uleb128`        | Length of the **try_blocks** array, that is, the number of [TryBlocks](#tryblock).   |
| `instructions`   | `uint8_t[]`      | Array of all instructions.                                          |
| `try_blocks`     | `TryBlock[]`     | An array of **TryBlock** elements.|


### TryBlock

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `start_pc`       | `uleb128`        | Offset between the first instruction of the **TryBlock** and the start position of the **instructions** in [Code](#code).|
| `length`         | `uleb128`        | Size of the **TryBlock** object to create, in bytes.                              |
| `num_catches`    | `uleb128`        | Number of [CatchBlocks](#catchblock) associated with **TryBlock**. The value is 1.|
| `catch_blocks`   | `CatchBlock[]`   | Array of **CatchBlocks** associated with **TryBlock**. The array contains one **CatchBlock** that can capture all types of exceptions.|


### CatchBlock

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                 |
| -------------- | -------------- | ----------------------------------------------- |
| `type_idx`       | `uleb128`        | If the value is **0**, the **CatchBlock** captures all types of exceptions.|
| `handler_pc`     | `uleb128`        | Program counter of the first instruction for handling the exception.         |
| `code_size`      | `uleb128`        | Size of the **CatchBlock**, in bytes.             |


### Annotation
Represents annotations in the bytecode file.

- Alignment: single-byte aligned
- Format

| **Name**| **Format**     | **Description**                                              |
| -------------- | ------------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`   | An index of the class to which the **Annotation** belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `count`          | `uint16_t`   | Length of the **elements** array.                                        |
| `elements`       | AnnotationElement[] | An array of [AnnotationElement](#annotationelement) elements.|
| `element_types`  | `uint8_t[]`  | An array, in which each element is of the [AnnotationElementTag](#annotationelementtag) type and is used to describe an **AnnotationElement.** The position of each element in the **element_types** array is the same as that of the corresponding **AnnotationElement** in the **elements** array.|

> **NOTE**
> 
> The offset of **Annotation** can be used to locate **IndexHeader** at that offset to parse **class_idx**.


### AnnotationElementTag

| **Name**| **Tag**|
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

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name_off`       | `uint32_t`       | An offset to a [string](#string) representing the annotation element name.|
| `value`          | `uint32_t`       | Value of the annotation element. If the width of the value is less than 32 bits, the value itself is stored here. Otherwise, the value stored here is an offset pointing to the [value formats](#value-formats).|


### Value formats
Different value types have different value encoding formats, including **INTEGER**, **LONG**, **FLOAT**, **DOUBLE**, and **ID**.

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `INTEGER`        | `uint32_t`       | 4-byte signed integer.                                      |
| `LONG`           | `uint64_t`       | 8-byte signed integer.                                      |
| `FLOAT`          | `uint32_t`       | 4-byte pattern that is zero-extended to the right. The system interprets this pattern as a 32-bit floating-point value in IEEE754 format.|
| `DOUBLE`         | `uint64_t`       | 8-byte pattern that is zero-extended to the right. The system interprets this pattern as a 64-bit floating-point value in IEEE754 format.|
| `ID`             | `uint32_t`       | 4-byte pattern that indicates the offset to another structure in the file.                  |


### LineNumberProgramIndex
An array that facilitates the use of a more compact index to access the [line number program](#line-number-program).

- Alignment: 4-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | An array of offsets pointing to line number programs. The array length is specified by **num_lnps** in [Header](#header).|


### DebugInfo
Contains mappings between program counters of the method and the line/column numbers in the source code, as well as information about local variables. The format of the debugging information is derived from the contents in section 6.2 of [DWARF 3.0 Standard](https://dwarfstd.org/dwarf3std.html). The execution model of the [state machine](#state-machine) interprets the [line number program](#line-number-program) to obtain the mappings and local variable information code. To deduplicate programs with the same line number in different methods, all constants referenced in the programs are moved to the [constant pool](#constant-pool).

- Alignment: single-byte aligned
- Format

| **Name**         | **Format**| **Description**                                              |
| ----------------------- | -------------- | ------------------------------------------------------------ |
| `line_start`              | `uleb128`        | Initial value of the line number register of the state machine.                                |
| `num_parameters`          | `uleb128`        | Total number of input and default parameters.                                    |
| `parameters`              | `uleb128[]`      | Array that stores the names of input parameters. The array length is specified by **num_parameters**. The value of each element is the offset to the string or **0**. If the value is **0**, the corresponding parameter does not have a name.|
| `constant_pool_size`      | `uleb128`        | Size of the constant pool, in bytes.                                |
| `constant_pool`           | `uleb128[]`      | Array for storing constant pool data. The array length is **constant_pool_size**.        |
| `line_number_program_idx` | `uleb128`        | An index that points to a position in [LineNumberProgramIndex](#linenumberprogramindex). The value of this position is an offset pointing to [Line number program](#line-number-program). The length of **Line number program** is variable and ends with the **END_SEQUENCE** operation code.|


#### Constant Pool
A structure within **DebugInfo** for storing constants. Many methods have similar line number programs, differing only in variable names, variable types, and file names. To eliminate redundancy in these programs, all referenced constants are stored in the constant pool. During program interpretation, the state machine maintains a pointer to the constant pool. When interpreting an instruction that requires a constant parameter, the state machine reads the value from the position pointed to by the constant pool pointer and then increments the pointer.


#### State Machine
Generates [DebugInfo](#debuginfo) information. It contains the following registers.

| **Name**   | **Initial Value**                                            | **Description**                                              |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `address`           | 0                                                            | Program counter (points to an instruction in the method), which can only increase monotonically.            |
| `line`              | Value of **line_start** in [DebugInfo](#debuginfo)| Unsigned integer, corresponding to the line number in the source code. All lines are numbered from 1. Therefore, the register value cannot be less than **1**.|
| `column`            | 0                                                            | Unsigned integer, corresponding to the column number in the source code.                              |
| `file`              | Value of **SOURCE_FILE** in **class_data** (see [Class](#class)), or 0.| An offset to a [string](#string) representing the source file name. If there is no file name (no **SOURCE_FILE** tag in [Class](#class)), the register value is **0**.|
| `source_code`       | 0                                                            | An offset to a [string](#string) representing the source code of the source file. If there is no source code information, the register value is **0**.|
| `constant_pool_ptr` | Address of the first byte of the constant pool in [DebugInfo](#debuginfo).| Pointer to the current constant value.                                      |


#### Line Number Program
Consists of instructions, each containing a single-byte operation code and optional parameters. Depending on the operation code, the parameter values may be encoded within the instruction (called instruction parameters) or retrieved from the constant pool (called constant pool parameters).

| **Operation Code** | **Value**| **Instruction Parameter**  | **Constant Pool Parameters**   | **Parameter Description**| **Description** |
| ----- | ----- | ------- | ---- | ------- | ------ |
| `END_SEQUENCE`         | `0x00`  |       |          |        | Marks the end of the line number program.   |
| `ADVANCE_PC`           | `0x01`  |    | `uleb128 addr_diff`   | **addr_diff**: value to increment the **address** register.   | Increments the **address** register by **addr_diff** to point to the next address, without generating a location entry.|
| `ADVANCE_LINE`         | `0x02` |     | `sleb128 line_diff`  | **line_diff**: value to increment the **line** register.   | Increments the **line** register by **line_diff** to point to the next line position, without generating a location entry.|
| `START_LOCAL`          | `0x03` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`   | **register_num**: register containing the local variable.<br>**name_idx**: an offset to a [string](#string) representing the variable name.<br>**type_idx**: an offset to a [string](#string) representing the variable type.| Introduces a local variable with a name and type at the current address. The number of the register that will contain this variable is encoded in the instruction. If **register_num** is **-1**, it indicates an accumulator register. The values of **name_idx** and **type_idx** may be **0**, indicating no such information.|
| `START_LOCAL_EXTENDED` | `0x04` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`<br>`uleb128 sig_idx` | **register_num**: register containing the local variable.<br>**name_idx**: an offset to a [string](#string) representing the variable name.<br>**type_idx**: an offset to a [string](#string) representing the variable type.<br>**sig_idx**: an offset to a [string](#string) representing the variable signature.| Introduces a local variable with a name, type, and signature at the current address. The number of the register that will contain this variable is encoded in the instruction. If **register_num** is **-1**, it indicates an accumulator register. The values of **name_idx**, **type_idx**, and **sig_idx** may be **0**, indicating no such information.|
| `END_LOCAL`            | `0x05` | `sleb128 register_num` |    | **register_num**: register containing the local variable. | Marks the local variable in the specified register as out of scope at the current address. If **register_num** is **-1**, it indicates an accumulator register.|
| `SET_FILE`             | `0x09`  |    | `uleb128 name_idx`  | **name_idx**: an offset to a [string](#string) representing the file name.| Sets the value of the file register. The value of **name_idx** may be **0**, indicating no such information.|
| `SET_SOURCE_CODE`      | `0x0a`  |    | `uleb128 source_idx` | **source_idx**: an offset to a [string](#string) representing the source code of the file.| Sets the value of the **source_code** register. The value of **source_idx** may be **0**, indicating no such information.|
| `SET_COLUMN`           | `0x0b` |    | `uleb128 column_num`   | **column_num**: column number to be set.  | Sets the value of the **column** register and generates a location entry. |
| Special operation code          | `0x0c..0xff`   |   |  |   | Adjusts the **line** and **address** registers to the next address and generate a location entry. Details are described below.|


For special operation codes in the range **0x0c** to **0xff** (included), the state machine performs the following steps to adjust the **line** and **address** registers and then generates a new location entry. For details, see section 6.2.5.1 "Special Opcodes" in [DWARF 3.0 Standard](https://dwarfstd.org/dwarf3std.html).

| **Step**| **Operation**                                    | **Description**                                              |
| ----- | -------------------------------------------------- | ------------------------------------------------------------ |
| 1     | `adjusted_opcode = opcode - OPCODE_BASE`            | Calculates the adjusted operation code. The value of **OPCODE_BASE** is **0x0c**, which is the first special operation code.|
| 2     | `address += adjusted_opcode / LINE_RANGE`            | Increments the **address** register. The value of **LINE_RANGE** is 15, which is used to calculate changes in the line number information.|
| 3     | `line += LINE_BASE + (adjusted_opcode % LINE_RANGE)` | Increments the **line** register. The value of **LINE_BASE** is **-4**, which is the minimum line number increment. The maximum increment is **LINE_BASE + LINE_RANGE - 1**.|
| 4     |                                                    | Generates a new location entry.                                      |

> **NOTE**
> 
> Special operation codes are calculated by using the following formula: (line_increment - LINE_BASE) + (address_increment * LINE_RANGE) + OPCODE_BASE.


### IndexSection
Generally, bytecode files use 32-bit offsets for referencing structures. When a structure references another structure, the current structure records a 32-bit offset of the referenced structure. To optimize file size, the bytecode file is segmented into index regions that use 16-bit indices instead of 32-bit offsets. The **IndexSection** structure provides an overview of these regions.

- Alignment: 4-byte aligned
- Format

| **Name**| **Format**| **Description**      |
| -------------- | -------------- | --------- |
| `headers`        | `IndexHeader[]`  | An array of [IndexHeader](#indexheader) elements. Elements in the array are sorted based on the start offset of the region. The array length is specified by **num_index_regions** in [Header](#header).|


### IndexHeader
Represents an index region. Each index region has two types of indexes: indexes pointing to [Type](#type) and indexes pointing to methods, strings, or literal arrays.

- Alignment: 4-byte aligned
- Format

| **Name**       | **Format**| **Description**   |
| -------------- | -------------- | ---------- |
| `start_off`                             | `uint32_t`       | Start offset of the region.                                        |
| `end_off`                               | `uint32_t`       | End offset of the region.                                        |
| `class_region_idx_size`                 | `uint32_t`       | Number of elements in [ClassRegionIndex](#classregionindex) of the region. The maximum value is **65536**.|
| `class_region_idx_off`                  | `uint32_t`       | An offset to [ClassRegionIndex](#classregionindex).|
| `method_string_literal_region_idx_size` | `uint32_t`       | Number of elements in [MethodStringLiteralRegionIndex](#methodstringliteralregionindex) of the region. The maximum value is **65536**.|
| `method_string_literal_region_idx_off`  | `uint32_t`       | An offset to [MethodStringLiteralRegionIndex](#methodstringliteralregionindex).|
| `reserved`                              | `uint32_t`       | Reserved field for internal use by the Ark bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field for internal use by the Ark bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field for internal use by the Ark bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field for internal use by the Ark bytecode file.                          |


### ClassRegionIndex
Provides compact indexing for locating [Type](#type) entries.

- Alignment: 4-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `types`          | `Type[]`         | An array of [Type](#type) elements. The array length is specified by **class_region_idx_size** in [IndexHeader](#indexheader).|


### Type
A 32-bit value representing either a basic type encoding or an offset to a [class](#class).

Basic type encodings are listed below.

| **Type**      | **Encoding**       |
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
Provides compact indexing for methods, strings, or literal arrays.

- Alignment: 4-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`      | `uint32_t[]`   | An array of offsets to methods, strings, or literal arrays. The array length is specified by **method_string_literal_region_idx_size** in [IndexHeader](#indexheader).|


### LiteralArray
Describes a literal array in the bytecode file.

- Alignment: single-byte aligned
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_literals`   | `uint32_t`       | Length of the **literals** array.                                        |
| `literals`       | `Literal[]`      | An array of [Literal](#literal) elements.|


### Literal
Describes literals in the bytecode file. Depending on the number of bytes in the literal value, there are four encoding formats: single-byte encoding, double-byte encoding, four-byte encoding, and eight-byte encoding. These formats optimize the size of the bytecode file by matching the encoding to the length of the value.

- Alignment: Each format has its corresponding alignment rules.
- Format

| **Name**| **Format**| **Description**|
| -------------- | ------------ | -------------- |
| Single-byte encoding     | `uint8_t`    | A single-byte value, aligned to one byte, used for simple type literals, such as **BOOL** literals.  |
| Double-byte encoding     | `uint16_t`   | A two-byte value, aligned to two bytes, used for 16-bit integer literals.  |
| Four-byte code     | `uint32_t`   | A four-byte value, aligned to four bytes, used for 32-bit numeric literals, such as **INTEGER** integer literals or **FLOAT** floating-point literals.  |
| Eight-byte encoding     | `uint64_t`   | An eight-byte value, aligned to eight bytes, used for 64-bit numeric literals, such as **DOUBLE** double-precision floating-point literals.  |
