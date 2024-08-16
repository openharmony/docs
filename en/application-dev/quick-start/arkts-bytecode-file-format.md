# Ark Bytecode File Format
The Ark bytecode file is a binary product compiled by ArkTS/TS/JS. This topic describes the Ark bytecode file format in detail, aiming to introduce each part of the bytecode and guide you to analyze and modify it.


## Constraints
This topic applies only to Ark bytecode whose version number is 11.0.2.0. (The version number is an internal reserved field of the Ark compiler.)


## Data Types of Bytecode File

### Integer

| **Name**       | **Description**                          |
| -------------- | ---------------------------------- |
| `uint8_t`      | 8-bit unsigned integer.                 |
| `uint16_t`     | 16-bit unsigned integer in little-endian mode.  |
| `uint32_t`     | 32-bit unsigned integer in little-endian mode.  |
| `uleb128`      | Leb128-encoded unsigned integer.            |
| `sleb128`      | Leb128-encoded signed integer.            |


### String
- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `utf16_length`   | `uleb128`  | The value is **`len << 1 \**| **is_ascii**, where **len** indicates the size of a string encoded by UTF-16, and **is_ascii`** indicates whether the string contains only ASCII characters. The value can be 0 or 1.|
| `data`           | `uint8_t[]` | MUTF-8 encoded character sequence ending with **\0**. |


### TaggedValue
- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                               |
| -------------- | -------------- | -------------------------------------------- |
| `tag`          | `uint8_t`      | Indicates the tag of a data type.                          |
| `data`         | `uint8_t[]`    | According to different tags, **data** is of different types or is empty.|


## TypeDescriptor
**TypeDescriptor** is the format of the class ([Class](#class)) name. Its name **L_ClassName;** is consisted by **'L'**, **'_'**, **ClassName**, and **';'**. In the preceding information, **ClassName** indicates the full name of the class. **'.'** in the name is replaced with **'/'**.


## Bytecode File Layout
The bytecode file is compiled based on the [Header](#header) structure. All structures in the file can be accessed directly or indirectly from the **Header**. The reference modes of the structure in the bytecode file include offset and index. The offset is a 32-bit value, indicating the distance, which is calculated from scratch, between the start position of the current structure and the file header in the bytecode file. An index is a 16-bit value that indicates the position of the current structure in the index area. This mechanism is described in [IndexSection](#indexsection).

All multi-byte values in the bytecode file are in little-endian.


### Header
- Alignment mode: single-byte alignment.
- Format

| **Name**   | **Format**| **Description**                                              |
| ----------------- | -------------- | ------------------------------------------------------------ |
| `magic`             | `uint8_t[8]`     | Value of the magic number must be **'P' 'A' 'N' 'D' 'A' '\0' '\0' '\0'**.   |
| `checksum`          | `uint32_t`       | **Adler32** checksum of the content in the bytecode file except the magic number and this check field.|
| `version`           | `uint8_t[4]`     | Version number of the bytecode file ([Version](#version)).|
| `file_size`         | `uint32_t`       | Size of a bytecode file, in bytes.                            |
| `foreign_off`       | `uint32_t`       | An offset that points to an external area. The external area contains two types of elements: [ForeignClass](#foreignclass) or [ForeignMethod](#foreignmethod). **foreign_off** points to the first element in the area.|
| `foreign_size`      | `uint32_t`       | Size of the external area, in bytes.                              |
| `num_classes`       | `uint32_t`       | Number of elements in the [ClassIndex](#classindex) structure, that is, the number of [Class](#class) defined in the file.|
| `class_idx_off`     | `uint32_t`       | An offset that points to [ClassIndex](#classindex).|
| `num_lnps`          | `uint32_t`       | Number of elements in the [LineNumberProgramIndex](#linenumberprogramindex) structure, that is, the number of [Line number program](#line-number-program) defined in the file.|
| `lnp_idx_off`       | `uint32_t`       | An offset that points to [LineNumberProgramIndex](#linenumberprogramindex).|
| `reserved`          | `uint32_t`       | Reserved field used internally in the Ark bytecode file.                          |
| `reserved`          | `uint32_t`       | Reserved field used internally in the Ark bytecode file.                          |
| `num_index_regions` | `uint32_t`       | Number of elements in the [IndexSection](#indexsection) structure, that is, the number of [IndexHeader](#indexheader) in the file.|
| `index_section_off` | `uint32_t`       | An offset that points to [IndexSection](#indexsection).|


### Version
The bytecode version number consists of four parts in the format of **major version number.minor version number.feature version number.Build version number**.

| **Name**| **Format**| **Description**                                            |
| -------------- | -------------- | ---------------------------------------------------------- |
| Major version number      | `uint8_t`        | Indicates the bytecode file format change caused by the overall structure adjustment.                |
| Minor version number      | `uint8_t`        | Indicates the bytecode file format change caused by partial structure adjustment or major feature adjustment.|
| Feature version number    | `uint8_t`        | Indicates the bytecode file format change caused by small- and medium-sized features.                    |
| Build version number    | `uint8_t`        | Indicates the bytecode file format change caused by defect rectification.                    |


### ForeignClass
Describes the enclosing classes in the bytecode file. They are declared in other files and referenced in the current bytecode file.
- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | Name of the enclosing class, which follows the [TypeDescriptor](#typedescriptor) syntax.|


### ForeignMethod
Describes external methods in bytecode files. They are declared in other files and referenced in the current bytecode file.
- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index pointing to the class to which the method belongs. It points to a position in [ClassRegionIndex](#classregionindex), whose value is an offset pointing to [Class](#class) or [ForeignClass](#foreignclass).|
| `reserved`       | `uint16_t`       | Reserved field used internally in the Ark bytecode file.              |
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the method name.|
| `index_data`     | `uleb128`        | [MethodIndexData](#methodindexdata) data of the method.|

**Note:**<br>
With the offset of **ForeignMethod**, the appropriate **IndexHeader** can be found to parse the **class_idx**.


### ClassIndex
The **ClassIndex** structure is used to quickly locate the definition of the **Class** by name.
- Alignment mode: 4-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | An array. The value of each element in this array is an offset pointing to [Class](#class). Elements in an array are sorted by class name. This name follows the [TypeDescriptor](#typedescriptor) syntax. The array length is specified by **num_classes** in [Header](#header).|


### Class
In a bytecode file, a class can represent a source code file of Ark bytecode or a built-in [Annotation](#annotation). When it indicates a source code file, the method of the class corresponds to the function in the source code file, and class field corresponds to the internal information in the source file. When it indicates a built-in **Annotation**, the class does not contain the field or method. A class in the source code file is represented in the bytecode file as a method corresponding to its constructor.

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | Class name, which follows the [TypeDescriptor](#typedescriptor) syntax.|
| `reserved`       | `uint32_t`       | Reserved field used internally in the Ark bytecode file.                          |
| `access_flags`   | `uleb128`        | Accessing tag of **Class**, which is a combination of [ClassAccessFlag](#classaccessflag).|
| `num_fields`     | `uleb128`        | Number of fields of **Class**.                                         |
| `num_methods`    | `uleb128`        | Number of methods of **Class**.                                         |
| `class_data`     | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [ClassTag](#classtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|
| `fields`         | `Field[]`        | Array of Class fields. Each element in the array is of the [Field](#field) type. The array length is specified by **num_fields**.|
| `methods`        | `Method[]`       | Array of Class methods. Each element in the array is of the [Method](#method) type. The array length is specified by `num_methods`.|


### ClassAccessFlag

| **Name**| **Value**| **Description**                                              |
| -------------- | ------------ | ------------------------------------------------------------ |
| `ACC_PUBLIC`     | `0x0001`       | Default attribute. [Class](#class) in the Ark bytecode has this tag.|
| `ACC_ANNOTATION` | `0x2000`       | Declares the class as the [Annotation](#annotation) type.|


### ClassTag
- Alignment mode: single-byte alignment.
- Format

| **Name**| **Value**| **Quantity**| **Format**| **Description**                                              |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`  | `1`  | `none`    | The [TaggedValue](#taggedvalue) with this tag is the last item of the **class_data**.|
| `SOURCE_LANG`    | `0x02`  | `0-1 ` | `uint8_t` | The **data** of [TaggedValue](#taggedvalue) with this tag is 0, indicating that the source code language is ArkTS, TS, or JS.|
| `SOURCE_FILE`    | `0x07`  | `0-1`  | `uint32_t`| The **data** of [TaggedValue](#taggedvalue) with this tag is an offset that points to [string](#string), indicating the name of the source file.|

**Note:**<br>
**ClassTag** is the tag of the element ([TaggedValue](#taggedvalue)) in the **class_data**. The number in the table header refers to the number of occurrences of the element with this tag in the **class_data** of a [Class](#class).


### Field
Describes the fields in the bytecode file.

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index pointing to the class to which the field belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `type_idx`       | `uint16_t`       | An index that points to the type of the field and points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type.|
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the name of the field.|
| `reserved`       | `uleb128`        | Reserved field used internally in the Ark bytecode file.                          |
| `field_data`     | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [FieldTag](#fieldtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|

**Note:**<br>
Based on the offset of the **Field**, the appropriate **IndexHeader** can be found to parse the **class_idx** and **type_idx**.


### FieldTag

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Value**| **Quantity**| **Format**| **Description** |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`   | `1`   | `none`     | The [TaggedValue](#taggedvalue) with this tag is the last item of the **field_data**.|
| `INT_VALUE`      | `0x01`   | `0-1` | `sleb128`  | The **data** type of the [TaggedValue](#taggedvalue) with this tag is of **boolean**, **byte**, **char**, **short**, or **int**.|
| `VALUE`          | `0x02`   | `0-1` | `uint32_t` | The **data** type of the [TaggedValue](#taggedvalue) with this tag is of **FLOAT** or **ID** in [Value formats](#value-formats).|

**Note:**<br>
**FieldTag** is the tag of the element ([TaggedValue](#taggedvalue)) in the **field_data**. The number in the table header refers to the number of occurrences of the element with this tag in the **field_data** of a [Field](#field).


### Method
Describes methods in bytecode files.

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index pointing to the class to which the method belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `reserved`       | `uint16_t`       | Reserved field used internally in the Ark bytecode file.                          |
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the method name.|
| `index_data`     | `uleb128`        | [MethodIndexData](#methodindexdata) data of the method.|
| `method_data`    | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [MethodTag](#methodtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|

**Note:**<br>
With the offset of **Method**, the appropriate **IndexHeader** can be found to parse the **class_idx**.


### MethodIndexData
**MethodIndexData** is an unsigned 32-bit integer divided into three parts.

| **Bit**| **Name**| **Format**| **Description**                                              |
| ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| 0 - 15       | `header_index`   | `uint16_t`       | Point to a position in [IndexSection](#indexsection). The value of this position is [IndexHeader](#indexheader). You can use **IndexHeader** to find the offsets of all methods ([Method](#method)), [string](#string), or literal arrays ([LiteralArray](#literalarray)) referenced by the method.|
| 16 - 23      | `function_kind`  | `uint8_t`        | Function type of a method ([FunctionKind](#functionkind)).|
| 24 - 31      | `reserved`       | `uint8_t`        | Reserved field used internally in the Ark bytecode file.                          |


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
| `NOTHING`        | `0x00`         | `1`             | `none`           | The [TaggedValue](#taggedvalue) with this tag is the last item of the **method_data**.|
| `CODE`           | `0x01`         | `0-1 `           | `uint32_t`       | The **data** of [TaggedValue](#taggedvalue) that has this tag is an offset pointing to [Code](#code), indicating the code segment of the method.|
| `SOURCE_LANG`    | `0x02`         | `0-1`            | `uint8_t`        | The **data** of [TaggedValue](#taggedvalue) with this tag is 0, indicating that the source code language is ArkTS, TS, or JS.|
| `DEBUG_INFO`     | `0x05`         | `0-1`            | `uint32_t`       | The **data** of [TaggedValue](#taggedvalue) with this tag is an offset that points to [DebugInfo](#debuginfo) and indicates the debugging information of the method.|
| `ANNOTATION`     | `0x06`         | `>=0`            | `uint32_t`       | The **data** of [TaggedValue](#taggedvalue) that has this tag is an offset that points to [Annotation](#annotation) and indicates the annotation of the method.|

**Note:**<br>
**MethodTag** is the tag of the element ([TaggedValue](#taggedvalue)) in the **method_data**. The number in the table header refers to the number of occurrences of the element with this tag in the **method_data** of a [Method](#method).


### Code

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_vregs`      | `uleb128`        | Number of registers. Registers that store input parameters and default parameters are not counted.        |
| `num_args`       | `uleb128`        | Total number of input parameters and default parameters.                                    |
| `code_size`      | `uleb128`        | Total size of all instructions, in bytes.                            |
| `tries_size`     | `uleb128`        | Length of the **try_blocks** array, that is, the number of [TryBlock](#tryblock).   |
| `instructions`   | `uint8_t[]`      | Array of all instructions.                                          |
| `try_blocks`     | `TryBlock[]`     | An array. Each element in the array is of the **TryBlock** type.|


### TryBlock

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `start_pc`       | `uleb128`        | Offset between the first instruction of the **TryBlock** and the start position of the **instructions** of [Code](#code).|
| `length`         | `uleb128`        | Size (in bytes) of the **TryBlock** object to create.                              |
| `num_catches`    | `uleb128`        | Number of [CatchBlock](#catchblock) associated with **TryBlock**. The value is 1.|
| `catch_blocks`   | `CatchBlock[]`   | Array of **CatchBlocks** associated with **TryBlock**. The array contains only one **CatchBlock** that can capture all types of exceptions.|


### CatchBlock

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                 |
| -------------- | -------------- | ----------------------------------------------- |
| `type_idx`       | `uleb128`        | If the value is 0, the **CatchBlock** captures all types of exceptions.|
| `handler_pc`     | `uleb128`        | Program counter of the first instruction of the exception handling logic.         |
| `code_size`      | `uleb128`        | Size of the **CatchBlock**, in bytes.             |


### Annotation
Describes an annotation structure.

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**     | **Description**                                              |
| -------------- | ------------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`   | An index pointing to the class to which the **Annotation** belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `count`          | `uint16_t`   | Length of the **elements** array.                                        |
| `elements`       | AnnotationElement[] | An array. Each element of the array is of the [AnnotationElement](#annotationelement) type.|
| `element_types`  | `uint8_t[]`  | An array. Each element in the array is of the [AnnotationElementTag](#annotationelementtag) type and is used to describe an **AnnotationElement.** The position of each element in the **element_types** array is the same as that of the corresponding **AnnotationElement** in the **elements** array.|

**Note:**<br>
Based on the **Annotation** offset, an appropriate **IndexHeader** can be found to parse the **class_idx**.


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

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the name of the annotation element.|
| `value`          | `uint32_t`       | Value of the annotation element. If the width of the value does not exceed 32 bits, the value itself is stored here. Otherwise, the value stored here is an offset pointing to the [Value formats](#value-formats) format.|


### Value formats
Different value types have different value encoding formats, including INTEGER, LONG, FLOAT, DOUBLE, and ID.

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `INTEGER`        | `uint32_t`       | Signed 4-byte integer value.                                      |
| `LONG`           | `uint64_t`       | Signed 8-byte integer value.                                      |
| `FLOAT`          | `uint32_t`       | 4-byte mode, which is extended to the right zero. The system interprets it as an IEEE754 32-bit floating-point value.|
| `DOUBLE`         | `uint64_t`       | 8-byte mode, which is extended to the right zero. The system interprets it as an IEEE754 64-bit floating-point value.|
| `ID`             | `uint32_t`       | 4-byte mode, indicating the offset of a structure in a file.                  |


### LineNumberProgramIndex
The **LineNumberProgramIndex** structure is an array that facilitates the use of a more compact index to access the [Line number program](#line-number-program).

- Alignment mode: 4-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | An array in which the value of each element is an offset pointing to a line number program. The array length is specified by **num_lnps** in [Header](#header).|


### DebugInfo
The **DebugInfo** contains the mapping between the program counter of the method and the row and column numbers in the source code, as well as information about local variables. The format of the debugging information evolves from the contents of [DWARF 3.0 Standard](https://dwarfstd.org/dwarf3std.html) (see section 6.2). Based on the execution model of the ([State machine](#state-machine)), the ([Line number program](#line-number-program)) is interpreted to obtain the mapping and local variable information code. To deduplicate programs with the same line number in different methods, all constants referenced in the programs are moved to the constant pool ([Constant pool](#constant-pool)).

- Alignment mode: single-byte alignment.
- Format

| **Name**         | **Format**| **Description**                                              |
| ----------------------- | -------------- | ------------------------------------------------------------ |
| `line_start`              | `uleb128`        | Initial value of the line number register of the state machine.                                |
| `num_parameters`          | `uleb128`        | Total number of input parameters and default parameters.                                    |
| `parameters`              | `uleb128[]`      | Array that stores the names of method input parameters. The array length is **num_parameters**. The value of each element is the offset of the string or 0. If the value is 0, the corresponding parameter does not have a name.|
| `constant_pool_size`      | `uleb128`        | Size of the constant pool, in bytes.                                |
| `constant_pool`           | `uleb128[]`      | Array for storing constant pool data. The array length is **constant_pool_size**.        |
| `line_number_program_idx` | `uleb128`        | An index that points to a position in [LineNumberProgramIndex](#linenumberprogramindex). The value of this position is an offset pointing to [Line number program](#line-number-program). The length of Line number program is variable and ends with the **END_SEQUENCE** operation code.|


#### Constant pool
A constant pool is a structure for storing constants in **DebugInfo**. Many methods have similar line-number programs, which differ only in variable names, variable types, and file names. To deduplicate such line number programs, all constants referenced in the programs are stored in the constant pool. When interpreting the program, the state machine maintains a pointer to the constant pool. When interpreting an instruction that requires constant parameters, the state machine reads the value from the position pointed to by the memory constant pool pointer and then increments the pointer.


#### State machine
The state machine is used to generate [DebugInfo](#debuginfo) information. It contains the following registers.

| **Name**   | **Initial Value**                                            | **Description**                                              |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `address`           | 0                                                            | Program counter (pointing to an instruction of a method), which can only monotonically increase.            |
| `line`              | Value of the **line_start** attribute of [DebugInfo](#debuginfo)| Unsigned integer, corresponding to the line number in the source code. All rows are numbered from 1. Therefore, the register value cannot be less than 1.|
| `column`            | 0                                                            | Unsigned integer, corresponding to the column number in the source code.                              |
| `file`              | Value of **SOURCE_FILE** in **class_data** (see [Class](#class)), or 0.| An offset that points to [string](#string), indicating the name of the source file. If there is no file name information, that is, there is no **SOURCE_FILE** tag in [Class](#class), the register value is 0.|
| `source_code`       | 0                                                            | An offset that points to [string](#string), indicating the source code of the source file. If there is no source code information, the register value is 0.|
| `constant_pool_ptr` | Address of the first byte in the constant pool in [DebugInfo](#debuginfo)| Pointer to the current constant value.                                      |


#### Line number program
A line number program consists of instructions. Each instruction contains a single-byte operation code and optional parameters. Depending on the operation code, the value of a parameter may be encoded in an instruction (called an instruction parameter) or needs to be obtained from a constant pool (called a constant pool parameter).

| **Operation Code** | **Value**| **Command Parameters**  | **Constant Pool Parameters**    | **Parameters**| **Description** |
| ----- | ----- | ------- | ---- | ------- | ------ |
| `END_SEQUENCE`         | `0x00`  |       |          |        | Marks the end of the line number program.   |
| `ADVANCE_PC`           | `0x01`  |    | `uleb128 addr_diff`   | **addr_diff**: value to be added to the **address** register value.   | The value in the **address** register plus **addr_diff** points to the next address without generating a location entry.|
| `ADVANCE_LINE`         | `0x02` |     | `sleb128 line_diff`  | **line_diff**: value to be added to the **line** register value   | The value in the **line** register plus **line_diff** points to the next row position without generating a position entry.|
| `START_LOCAL`          | `0x03` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`   | **register_num**: register that will contain local variables<br>**name_idx**: an offset pointing to [string](#string), indicating the name of a variable<br>**type_idx**: an offset pointing to [string](#string), indicating the variable type.| Introduces a local variable with a name and type in the current address. The number of the register that will contain this variable is encoded in the instruction. If the register number is -1, it indicates that the register is an accumulator register. The values of **name_idx** and **type_idx** may be 0. If the values are 0, the corresponding information does not exist.|
| `START_LOCAL_EXTENDED` | `0x04` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`<br>`uleb128 sig_idx` | **register_num**: register that will contain local variables.<br>**name_idx**: an offset pointing to [string](#string), indicating the name of a variable.<br>**type_idx**: an offset pointing to [string](#string), indicating the variable type.<br>**sig_idx**: an offset pointing to [string](#string), indicating the signature of the variable.| Introduces a local variable with a name, type, and signature in the current address. The number of the register that will contain this variable is encoded in the instruction. If the register number is -1, it indicates that the register is an accumulator register. The values of **name_idx**, **type_idx**, and **sig_idx** may be 0. If the values are 0, the corresponding information does not exist.|
| `END_LOCAL`            | `0x05` | `sleb128 register_num` |    | **register_num**: register containing local variables | Marks a local variable in the specified register as out of range at the current address. If the register number is -1, it indicates that the register is an accumulator register.|
| `SET_FILE`             | `0x09`  |    | `uleb128 name_idx`  | **name_idx**: an offset pointing to [string](#string), indicating the file name| Sets the value of the file register. The value of **name_idx** may be 0. If the value is 0, it indicates that the corresponding information does not exist.|
| `SET_SOURCE_CODE`      | `0x0a`  |    | `uleb128 source_idx` | **source_idx**: an offset pointing to [string](#string), indicating the source code of the file.| Sets the value of the **source_code** register. The value of **source_idx** may be 0. If the value is 0, it indicates that the corresponding information does not exist.|
| `SET_COLUMN`           | `0x0b` |    | `uleb128 column_num`   | **column_num**: column number to be set.  | Sets the value of the **column** register and generates a location entry. |
| Special operation code          | `0x0c..0xff`   |   |  |   | Make the **line** and **address** registers point to the next address and generate a location entry. For details, see the following description.|


For special operation codes whose values are between **0x0c** and **0xff** (included), the state machine moves the **line** and **address** registers by a small part and then generates a new location entry. For details, see section 6.2.5.1 "Special Opcodes" in [DWARF 3.0 Standard](https://dwarfstd.org/dwarf3std.html).

| **No.**| **Operation**                                    | **Description**                                              |
| ----- | -------------------------------------------------- | ------------------------------------------------------------ |
| 1     | `adjusted_opcode = opcode - OPCODE_BASE`            | Calculates the adjusted operation code. The value of **OPCODE_BASE** is **0x0c**, which is the first special operation code.|
| 2     | `address += adjusted_opcode / LINE_RANGE`            | Increase the value of the **address** register. The value of **LINE_RANGE** is 15, which is used to calculate the change of line number information.|
| 3     | `line += LINE_BASE + (adjusted_opcode % LINE_RANGE)` | Increase the value of the **line** register. The value of **LINE_BASE** is -4, which is the minimum row number increment. The maximum row number increment is **LINE_BASE + LINE_RANGE - 1**.|
| 4     |                                                    | Generates a new location entry.                                      |

**Note:**<br>
The special operation code is calculated using the following formula: **(line_increment - LINE_BASE) + (address_increment * LINE_RANGE) + OPCODE_BASE**.


### IndexSection
Generally, each structure of a bytecode file is referenced by using a 32-bit offset. When a structure references another structure, the 32-bit offset of the referenced structure needs to be recorded in the current structure. To reduce a file size, a bytecode file is divided into multiple index regions (Index region), and a structure in each index region uses a 16-bit index. The **IndexSection** structure describes a collection of index areas.

- Alignment mode: 4-byte alignment.
- Format

| **Name**| **Format**| **Description**      |
| -------------- | -------------- | --------- |
| `headers`        | `IndexHeader[]`  | An array. Each element in the array is of the [IndexHeader](#indexheader) type. Elements in the array are sorted based on the start offset of the area. The array length is specified by **num_index_regions** in [Header](#header).|


### IndexHeader
Each **IndexHeader** structure describes an index area. Each index area has two types of indexes: indexes pointing to [Type](#type) and indexes pointing to methods, strings, or literal arrays.

- Alignment mode: 4-byte alignment.
- Format

| **Name**       | **Format**| **Description**   |
| -------------- | -------------- | ---------- |
| `start_off`                             | `uint32_t`       | Offset to the start position in this area.                                        |
| `end_off`                               | `uint32_t`       | Offset to the end position in this area.                                        |
| `class_region_idx_size`                 | `uint32_t`       | Number of elements in [ClassRegionIndex](#classregionindex) of the region. The maximum value is 65536.|
| `class_region_idx_off`                  | `uint32_t`       | An offset that points to [ClassRegionIndex](#classregionindex).|
| `method_string_literal_region_idx_size` | `uint32_t`       | Number of elements in the [MethodStringLiteralRegionIndex](#methodstringliteralregionindex) of the region. The maximum value is 65536.|
| `method_string_literal_region_idx_off`  | `uint32_t`       | An offset that points to [MethodStringLiteralRegionIndex](#methodstringliteralregionindex).|
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark bytecode file.                          |


### ClassRegionIndex
The **ClassRegionIndex** structure is used to find the corresponding [Type](#type) through a more compact index.

- Alignment mode: 4-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `types`          | `Type[]`         | An array. Each element in the array is of the [Type](#type) type. The array length is specified by **class_region_idx_size** in [IndexHeader](#indexheader).|


### Type
Indicates a basic type code or an offset pointing to [Class](#class). It is a 32-bit value.

Basic types are encoded in the following ways.

| **Type**      | **Code**       |
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
The **MethodStringLiteralRegionIndex** structure allows you to find the corresponding method, string, or literal array through a more compact index.

- Alignment mode: 4-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`      | `uint32_t[]`   | An array in which the value of each element is an offset pointing to a method, string, or literal array. The array length is specified by **method_string_literal_region_idx_size** in [IndexHeader](#indexheader).|


### LiteralArray
Describes the literal array in the bytecode file.

- Alignment mode: single-byte alignment.
- Format

| **Name**| **Format**| **Description**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_literals`   | `uint32_t`       | Length of the **literals** array.                                        |
| `literals`       | `Literal[]`      | An array. Each element of the array is of the [Literal](#literal) type.|


### Literal
Describes the literals in a bytecode file. There are four encoding formats based on the number of bytes of the literals.

| **Name**| **Format**| **Alignment Type**| **Description**|
| -------------- | -------------- | ------------------ | -------------- |
| ByteOne        | `uint8_t`        | 1 byte           | Single-byte value.  |
| ByteTwo        | `uint16_t`       | 2 bytes           | Double-byte value.  |
| ByteFour       | `uint32_t`       | 4 bytes           | Four-byte value.  |
| ByteEight      | `uint64_t`       | 8 bytes           | Eight-byte value.  |
