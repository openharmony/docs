# Ark Bytecode File Format
The Ark Bytecode file is a binary product compiled in ArkTS/TS/JS. This topic describes the Ark Bytecode file format in detail, aiming to introduce each part of the bytecode and guide you to analyze and modify the bytecode.


## Constraints
This topic only applies to Ark Bytecode in 11.0.2.0 version. (The version number is an internal reserved field of the Ark compiler.)


## Data Types of Bytecode File

### Integer

| **Name**       | **NOTE**                          |
| -------------- | ---------------------------------- |
| `uint8_t`      | 8-bit unsigned integer.                 |
| `uint16_t`     | 16-bit unsigned integer in little-endian mode.  |
| `uint32_t`     | 32-bit unsigned integer in little-endian mode.  |
| `uleb128`      | Leb128-encoded unsigned integer.            |
| `sleb128`      | Leb128-encoded signed integer.            |


### String
- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `utf16_length`   | `uleb128`  | The value is **`len << 1 \**| **is_ascii**, where **len** indicates the size of a string encoded by UTF-16, and **is_ascii`** indicates whether the string contains only ASCII characters. The value can be **0** or **1**.|
| `data`           | `uint8_t[]` | MUTF-8 encoded character sequence ending with **\0**. |


### TaggedValue
- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                               |
| -------------- | -------------- | -------------------------------------------- |
| `tag`          | `uint8_t`      | Indicates the tag of a data type.                          |
| `data`         | `uint8_t[]`    | According to different tags, **data** is of different types or is empty.|


## TypeDescriptor
**TypeDescriptor** is the format of the [Class](#class) name. Its name **L_ClassName;** is consisted by **'L'**, **'_'**, **ClassName**, and **';'**. In this case, **ClassName** indicates the full name of the class. **'.'** in the name is replaced with **'/'**.


## Bytecode File Layout
The bytecode file is compiled based on the [Header](#header) structure. All structures in the file can be accessed directly or indirectly from the **Header**. The reference modes of the structure in the bytecode file include offset and index. The offset calculated from 0 is a 32-bit value, indicating the distance between the start position of the current structure and the file header in the bytecode file. An index is a 16-bit value that indicates the position of the current structure in the index region. This mechanism is described in [IndexSection](#indexsection).

All multi-byte values in the bytecode file are in little-endian.


### Header
- Align in single byte.
- Format

| **Name**   | **Format**| **NOTE**                                              |
| ----------------- | -------------- | ------------------------------------------------------------ |
| `magic`             | `uint8_t[8]`     | Value of the magic number must be **'P' 'A' 'N' 'D' 'A' '\0' '\0' '\0'**.   |
| `checksum`          | `uint32_t`       | **Adler32** checksum of the content in the bytecode file except the magic number and this check field.|
| `version`           | `uint8_t[4]`     | [Version](#version) number of the bytecode file.|
| `file_size`         | `uint32_t`       | Size of a bytecode file, in bytes.                            |
| `foreign_off`       | `uint32_t`       | An offset that points to an external region. The external region contains two types of elements: [ForeignClass](#foreignclass) or [ForeignMethod](#foreignmethod). **foreign_off** points to the first element in the region.|
| `foreign_size`      | `uint32_t`       | Size of the external region, in bytes.                              |
| `num_classes`       | `uint32_t`       | Number of elements in the [ClassIndex](#classindex) structure, that is, the number of [Class](#class) defined in the file.|
| `class_idx_off`     | `uint32_t`       | An offset that points to [ClassIndex](#classindex).|
| `num_lnps`          | `uint32_t`       | Number of elements in the [LineNumberProgramIndex](#linenumberprogramindex) structure, that is, the number of [Line number program](#line-number-program) defined in the file.|
| `lnp_idx_off`       | `uint32_t`       | An offset that points to [LineNumberProgramIndex](#linenumberprogramindex).|
| `reserved`          | `uint32_t`       | Reserved field used internally in the Ark Bytecode file.                          |
| `reserved`          | `uint32_t`       | Reserved field used internally in the Ark Bytecode file.                          |
| `num_index_regions` | `uint32_t`       | Number of elements in the [IndexSection](#indexsection) structure, that is, the number of [IndexHeader](#indexheader) in the file.|
| `index_section_off` | `uint32_t`       | An offset that points to [IndexSection](#indexsection).|


### Version
The bytecode version number consists of four parts in the format of **major version number.minor version number.feature version number.Build version number**.

| **Name**| **Format**| **NOTE**                                            |
| -------------- | -------------- | ---------------------------------------------------------- |
| Major version number      | `uint8_t`        | Indicates the changes to the bytecode file format caused by the overall structure adjustment.                |
| Minor version number      | `uint8_t`        | Indicates the changes to the bytecode file format caused by partial structure adjustment or major feature adjustment.|
| Feature version number    | `uint8_t`        | Indicates the changes to the bytecode file format caused by small- and medium-sized features.                    |
| Build version number    | `uint8_t`        | Indicates the changes to the bytecode file format caused by defect rectification.                    |


### ForeignClass
Describes the enclosing classes in the bytecode file. They are declared in other files and referenced in the current bytecode file.
- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | Enclosing class name, which follows the [TypeDescriptor](#typedescriptor) syntax.|


### ForeignMethod
Describes external methods in bytecode file. They are declared in other files and referenced in the current bytecode file.
- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index pointing to the class to which the method belongs. It points to a position in [ClassRegionIndex](#classregionindex), whose value is an offset pointing to [Class](#class) or [ForeignClass](#foreignclass).|
| `reserved`       | `uint16_t`       | Reserved field used internally in the Ark Bytecode file.              |
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the method name.|
| `index_data`     | `uleb128`        | [MethodIndexData](#methodindexdata) data of the method.|

**Note:**<br>
With the offset of **ForeignMethod**, an appropriate **IndexHeader** can be found to parse the **class_idx**.


### ClassIndex
The **ClassIndex** structure is used to quickly locate the definition of the **Class** by name.
- Align in four bytes.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | An array. The value of each element in this array is an offset pointing to [Class](#class). Elements in an array are sorted by the class name which follows the [TypeDescriptor](#typedescriptor) syntax. The array length is specified by **num_classes** in [Header](#header).|


### Class
In a bytecode file, a class can represent a source code file of Ark Bytecode or a built-in [Annotation](#annotation). When it indicates a source code file, the method of the class corresponds to the function in the source code file, and class field corresponds to the internal information in the source file. When it indicates a built-in **Annotation**, the class does not contain the field or method. A class in the source code file is represented in the bytecode file as a method corresponding to its constructor.

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name`           | `String`         | Class name, which follows the [TypeDescriptor](#typedescriptor) syntax.|
| `reserved`       | `uint32_t`       | Reserved field used internally in the Ark Bytecode file.                          |
| `access_flags`   | `uleb128`        | Accessing tag of **Class**, which is a combination of [ClassAccessFlag](#classaccessflag).|
| `num_fields`     | `uleb128`        | Number of fields of **Class**.                                         |
| `num_methods`    | `uleb128`        | Number of methods of **Class**.                                         |
| `class_data`     | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [ClassTag](#classtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|
| `fields`         | `Field[]`        | Array of **Class** fields. Each element in this array is of the [Field](#field) type. The array length is specified by **num_fields**.|
| `methods`        | `Method[]`       | Array of **Class** methods. Each element in this array is of the [Method](#method) type. The array length is specified by **num_methods**.|


### ClassAccessFlag

| **Name**| **Value**| **NOTE**                                              |
| -------------- | ------------ | ------------------------------------------------------------ |
| `ACC_PUBLIC`     | `0x0001`       | Default attribute. [Class](#class) in the Ark Bytecode has this tag.|
| `ACC_ANNOTATION` | `0x2000`       | Declares this class as the [Annotation](#annotation) type.|


### ClassTag
- Align in single byte.
- Format

| **Name**| **Value**| **Quantity**| **Format**| **NOTE**                                              |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`  | `1`  | `none`    | The [TaggedValue](#taggedvalue) with this tag is the final item of the **class_data**.|
| `SOURCE_LANG`    | `0x02`  | `0-1 ` | `uint8_t` | The **data** of [TaggedValue](#taggedvalue) with this tag is **0**, indicating that the source code language is in ArkTS, TS, or JS.|
| `SOURCE_FILE`    | `0x07`  | `0-1`  | `uint32_t`| The **data** of [TaggedValue](#taggedvalue) with this tag is an offset that points to [string](#string), indicating the name of the source file.|

**Note:**<br>
**ClassTag** is the tag of the element ([TaggedValue](#taggedvalue)) in the **class_data**. The number in the table header refers to the number of occurrences of the element with this tag in the **class_data** of a [Class](#class).


### Field
Describes the fields in the bytecode file.

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index pointing to the class to which the field belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `type_idx`       | `uint16_t`       | An index that points to the type of the field and points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type.|
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the name of the field.|
| `reserved`       | `uleb128`        | Reserved field used internally in the Ark Bytecode file.                          |
| `field_data`     | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [FieldTag](#fieldtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|

**Note:**<br>
Based on the offset of the **Field**, the appropriate **IndexHeader** can be found to parse the **class_idx** and **type_idx**.


### FieldTag

- Align in single byte.
- Format

| **Name**| **Value**| **Quantity**| **Format**| **NOTE** |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`   | `1`   | `none`     | The [TaggedValue](#taggedvalue) with this tag is the final item of the **field_data**.|
| `INT_VALUE`      | `0x01`   | `0-1` | `sleb128`  | The **data** type of the [TaggedValue](#taggedvalue) with this tag is of **boolean**, **byte**, **char**, **short**, or **int**.|
| `VALUE`          | `0x02`   | `0-1` | `uint32_t` | The **data** type of the [TaggedValue](#taggedvalue) with this tag is of **FLOAT** or **ID** in [Value formats](#value-formats).|

**Note:**<br>
**FieldTag** is the tag of the element ([TaggedValue](#taggedvalue)) in the **field_data**. The number in the table header refers to the number of occurrences of the element with this tag in the **field_data** of a [Field](#field).


### Method
Describes methods in bytecode files.

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`       | An index pointing to the class to which the method belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `reserved`       | `uint16_t`       | Reserved field used internally in the Ark Bytecode file.                          |
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the method name.|
| `index_data`     | `uleb128`        | [MethodIndexData](#methodindexdata) data of the method.|
| `method_data`    | `TaggedValue[]`  | Array with variable length. Each element in the array is of the [TaggedValue](#taggedvalue) type, and the element tag is of the [MethodTag](#methodtag) type. Elements in the array are sorted in ascending order based on the tag (except the **0x00** tag).|

**Note:**<br>
With the offset of **Method**, an appropriate **IndexHeader** can be found to parse the **class_idx**.


### MethodIndexData
**MethodIndexData** is an unsigned 32-bit integer divided into three parts.

| **Bit**| **Name**| **Format**| **NOTE**                                              |
| ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| 0 - 15       | `header_index`   | `uint16_t`       | Points to a position in [IndexSection](#indexsection). The value of this position is [IndexHeader](#indexheader). You can use **IndexHeader** to find the offsets of the method ([Method](#method)), [string](#string), or literal array ([LiteralArray](#literalarray)) referenced by this method.|
| 16 - 23      | `function_kind`  | `uint8_t`        | Indicates the function type ([FunctionKind](#functionkind)) of a method |
| 24 - 31      | `reserved`       | `uint8_t`        | Reserved field used internally in the Ark Bytecode file.                          |


#### FunctionKind

| **Name**          | **Value**| **NOTE**  |
| ------------------------ | ------------ | ---------------- |
| `FUNCTION`                 | `0x1`          | Common function.      |
| `NC_FUNCTION`              | `0x2`          | Common arrow function.  |
| `GENERATOR_FUNCTION`       | `0x3`          | Generator function.    |
| `ASYNC_FUNCTION`           | `0x4`          | Asynchronous function.      |
| `ASYNC_GENERATOR_FUNCTION` | `0x5`          | Asynchronous generator function.|
| `ASYNC_NC_FUNCTION`        | `0x6`          | Asynchronous arrow function.  |
| `CONCURRENT_FUNCTION`      | `0x7`          | Concurrent function.      |


### MethodTag

| **Name**| **Value**| **Quantity**| **Format**| **NOTE**                                              |
| -------------- | ------------ | -------------- | -------------- | ------------------------------------------------------------ |
| `NOTHING`        | `0x00`         | `1`             | `none`           | The [TaggedValue](#taggedvalue) with this tag is the final item of the **method_data**.|
| `CODE`           | `0x01`         | `0-1 `           | `uint32_t`       | The **data** of [TaggedValue](#taggedvalue) with this tag is an offset pointing to [Code](#code), indicating the code segment of the method.|
| `SOURCE_LANG`    | `0x02`         | `0-1`            | `uint8_t`        | The **data** of [TaggedValue](#taggedvalue) with this tag is **0**, indicating that the source code language is in ArkTS, TS, or JS.|
| `DEBUG_INFO`     | `0x05`         | `0-1`            | `uint32_t`       | The **data** of [TaggedValue](#taggedvalue) with this tag is an offset pointing to [DebugInfo](#debuginfo), indicating the debugging information of the method.|
| `ANNOTATION`     | `0x06`         | `>=0`            | `uint32_t`       | The **data** of [TaggedValue](#taggedvalue) with this tag is an offset pointing to [Annotation](#annotation), indicating the annotation of the method.|

**Note:**<br>
**MethodTag** is the tag of the element ([TaggedValue](#taggedvalue)) in the **method_data**. The number in the table header refers to the number of occurrences of the element with this tag in the **method_data** of a [Method](#method).


### Code

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_vregs`      | `uleb128`        | Number of registers. Registers that store input and default parameters are not counted.        |
| `num_args`       | `uleb128`        | Total number of input and default parameters.                                    |
| `code_size`      | `uleb128`        | Total size of all instructions, in bytes.                            |
| `tries_size`     | `uleb128`        | Length of the **try_blocks** array, that is, the number of [TryBlock](#tryblock).   |
| `instructions`   | `uint8_t[]`      | Array of all instructions.                                          |
| `try_blocks`     | `TryBlock[]`     | An array. Each element in the array is of the **TryBlock** type.|


### TryBlock

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `start_pc`       | `uleb128`        | Offset between the first instruction of the **TryBlock** and the start position of the **instructions** in [Code](#code).|
| `length`         | `uleb128`        | Size of the **TryBlock** object to create, in bytes.                              |
| `num_catches`    | `uleb128`        | Number of [CatchBlock](#catchblock) associated with **TryBlock**. The value is 1.|
| `catch_blocks`   | `CatchBlock[]`   | Array of **CatchBlocks** associated with **TryBlock**. The array contains one **CatchBlock** that can capture all types of exceptions.|


### CatchBlock

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                 |
| -------------- | -------------- | ----------------------------------------------- |
| `type_idx`       | `uleb128`        | If the value is **0**, the **CatchBlock** captures all types of exceptions.|
| `handler_pc`     | `uleb128`        | Program counter of the first instruction for handling the exception.         |
| `code_size`      | `uleb128`        | Size of the **CatchBlock**, in bytes.             |


### Annotation
Describes an annotation structure.

- Align in single byte.
- Format

| **Name**| **Format**     | **NOTE**                                              |
| -------------- | ------------------- | ------------------------------------------------------------ |
| `class_idx`      | `uint16_t`   | An index pointing to the class to which the **Annotation** belongs. It points to a position in [ClassRegionIndex](#classregionindex). The value of the position is of the [Type](#type) type and is an offset pointing to [Class](#class).|
| `count`          | `uint16_t`   | Length of the **elements** array.                                        |
| `elements`       | AnnotationElement[] | An array. Each element of the array is of the [AnnotationElement](#annotationelement) type.|
| `element_types`  | `uint8_t[]`  | An array. Each element in the array is of the [AnnotationElementTag](#annotationelementtag) type and is used to describe an **AnnotationElement.** The position of each element in the **element_types** array is the same as that of the corresponding **AnnotationElement** in the **elements** array.|

**Note:**<br>
With the offset of **Annotation**, an appropriate **IndexHeader** can be found to parse the **class_idx**.


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

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `name_off`       | `uint32_t`       | An offset that points to [string](#string), indicating the name of the annotation element.|
| `value`          | `uint32_t`       | Value of the annotation element. If the width of the value is less than 32 bits, the value itself is stored here. Otherwise, the value stored here is an offset pointing to the [Value formats](#value-formats).|


### Value formats
Different value types have different value encoding formats, including INTEGER, LONG, FLOAT, DOUBLE, and ID.

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `INTEGER`        | `uint32_t`       | Signed 4-byte integer value.                                      |
| `LONG`           | `uint64_t`       | Signed 8-byte integer value.                                      |
| `FLOAT`          | `uint32_t`       | 4-byte mode, which is extended to the right zero. The system interprets it as an IEEE754 32-bit floating-point value.|
| `DOUBLE`         | `uint64_t`       | 8-byte mode, which is extended to the right zero. The system interprets it as an IEEE754 64-bit floating-point value.|
| `ID`             | `uint32_t`       | 4-byte mode, indicating the offset of a structure in a file.                  |


### LineNumberProgramIndex
The **LineNumberProgramIndex** structure is an array that facilitates the use of a more compact index to access the [Line number program](#line-number-program).

- Align in four bytes.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`        | `uint32_t[]`     | An array in which the value of each element is an offset pointing to a line number program. The array length is specified by **num_lnps** in [Header](#header).|


### DebugInfo
The **DebugInfo** contains the mapping between the program counter of the method and the line and column numbers in the source code, as well as information about local variables. The format of the debugging information evolves from the contents of [DWARF 3.0 Standard](https://dwarfstd.org/dwarf3std.html) (see section 6.2). The execution model of the [State machine](#state-machine) interprets the [Line number program](#line-number-program) to obtain the mapping and local variable information code. To deduplicate programs with the same line number in different methods, all constants referenced in the programs are moved to the [Constant pool](#constant-pool).

- Align in single byte.
- Format

| **Name**         | **Format**| **NOTE**                                              |
| ----------------------- | -------------- | ------------------------------------------------------------ |
| `line_start`              | `uleb128`        | Initial value of the line number register of the state machine.                                |
| `num_parameters`          | `uleb128`        | Total number of input and default parameters.                                    |
| `parameters`              | `uleb128[]`      | Array that stores the names of input parameters. The array length is **num_parameters**. The value of each element is the offset of the string or **0**. If the value is **0**, the corresponding parameter does not have a name.|
| `constant_pool_size`      | `uleb128`        | Size of the constant pool, in bytes.                                |
| `constant_pool`           | `uleb128[]`      | Array for storing constant pool data. The array length is **constant_pool_size**.        |
| `line_number_program_idx` | `uleb128`        | An index that points to a position in [LineNumberProgramIndex](#linenumberprogramindex). The value of this position is an offset pointing to [Line number program](#line-number-program). The length of **Line number program** is variable and ends with the **END_SEQUENCE** operation code.|


#### Constant pool
A constant pool is a structure for storing constants in **DebugInfo**. Many methods have similar line number programs, which differ only in variable names, variable types, and file names. To deduplicate such line number programs, all constants referenced in the programs are stored in the constant pool. When interpreting the program, the state machine maintains a pointer to the constant pool. When interpreting an instruction that requires constant parameters, the state machine reads the value from the position pointed by the memory constant pool pointer and then increments the pointer.


#### State machine
The state machine is used to generate [DebugInfo](#debuginfo) information. It contains the following registers.

| **Name**   | **Initial Value**                                            | **NOTE**                                              |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `address`           | 0                                                            | Program counter, an instruction that points to a method, can only monotonically increase.            |
| `line`              | Value of the **line_start** attribute of [DebugInfo](#debuginfo)| Unsigned integer, corresponding to the line number in the source code. All lines are numbered from 1. Therefore, the register value cannot be less than **1**.|
| `column`            | 0                                                            | Unsigned integer, corresponding to the column number in the source code.                              |
| `file`              | Value of **SOURCE_FILE** in **class_data** (see [Class](#class)), or 0.| An offset that points to [string](#string), indicating the name of the source file. If there is no file name, that is, there is no **SOURCE_FILE** tag in [Class](#class), the register value is **0**.|
| `source_code`       | 0                                                            | An offset that points to [string](#string), indicating the source code of the source file. If there is no source code information, the register value is **0**.|
| `constant_pool_ptr` | Address of the first byte from the constant pool in [DebugInfo](#debuginfo).| Pointer that points to the current constant value.                                      |


#### Line number program
A line number program consists of instructions. Each instruction contains a single-byte operation code and optional parameters. Because of different operation codes, a parameter value may be encoded in an instruction (called an instruction parameter) or needs to be obtained from a constant pool (called a constant pool parameter).

| **Operation Code** | **Value**| **Command Parameters**  | **Constant Pool Parameters**    | **Parameters**| **NOTE** |
| ----- | ----- | ------- | ---- | ------- | ------ |
| `END_SEQUENCE`         | `0x00`  |       |          |        | Marks the end of the line number program.   |
| `ADVANCE_PC`           | `0x01`  |    | `uleb128 addr_diff`   | **addr_diff**: value to be added to the **address** register value.   | The value in the **address** register plus **addr_diff** points to the next address without generating a location entry.|
| `ADVANCE_LINE`         | `0x02` |     | `sleb128 line_diff`  | **line_diff**: value to be added to the **line** register value.   | The value in the **line** register plus **line_diff** points to the next line position without generating a position entry.|
| `START_LOCAL`          | `0x03` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`   | **register_num**: register containing local variables.<br>**name_idx**: an offset pointing to [string](#string), indicating the variable name.<br>**type_idx**: an offset pointing to [string](#string), indicating the variable type.| Introduces a local variable with a name and a type in the current address. The number of the register that will contain this variable is encoded in the instruction. If the register number is -1, it indicates that the register is an accumulator. The values of **name_idx** and **type_idx** may be **0**. If so, the corresponding information does not exist.|
| `START_LOCAL_EXTENDED` | `0x04` | `sleb128 register_num` | `uleb128 name_idx`<br>`uleb128 type_idx`<br>`uleb128 sig_idx` | **register_num**: register containing local variables.<br>**name_idx**: an offset pointing to [string](#string), indicating the variable name.<br>**type_idx**: an offset pointing to [string](#string), indicating the variable type.<br>**sig_idx**: an offset pointing to [string](#string), indicating the variable signature.| Introduces a local variable with a name, a type, and a signature in the current address. The number of the register that will contain this variable is encoded in the instruction. If the register number is -1, it indicates that the register is an accumulator. The values of **name_idx**, **type_idx**, and **sig_idx** may be **0**. If so, the corresponding information does not exist.|
| `END_LOCAL`            | `0x05` | `sleb128 register_num` |    | **register_num**: register containing local variables. | Marks a local variable in the specified register as out of range at the current address. If the register number is -1, it indicates that the register is an accumulator.|
| `SET_FILE`             | `0x09`  |    | `uleb128 name_idx`  | **name_idx**: an offset pointing to [string](#string), indicating the file name.| Sets the value of the file register. The value of **name_idx** may be **0**. If so, it indicates that the corresponding information does not exist.|
| `SET_SOURCE_CODE`      | `0x0a`  |    | `uleb128 source_idx` | **source_idx**: an offset pointing to [string](#string), indicating the source code of the file.| Sets the value of the **source_code** register. The value of **source_idx** may be **0**. If so, it indicates that the corresponding information does not exist.|
| `SET_COLUMN`           | `0x0b` |    | `uleb128 column_num`   | **column_num**: column number to be set.  | Sets the value of the **column** register and generates a location entry. |
| Special operation code          | `0x0c..0xff`   |   |  |   | Makes the **line** and **address** registers point to the next address and generate a location entry. For details, see the following description.|


For special operation codes whose values are between **0x0c** and **0xff** (included), the state machine moves the **line** and **address** registers by a small part and then generates a new location entry. For details, see section 6.2.5.1 "Special Opcodes" in [DWARF 3.0 Standard](https://dwarfstd.org/dwarf3std.html).

| **No.**| **Operation**                                    | **NOTE**                                              |
| ----- | -------------------------------------------------- | ------------------------------------------------------------ |
| 1     | `adjusted_opcode = opcode - OPCODE_BASE`            | Calculates the adjusted operation code. The value of **OPCODE_BASE** is **0x0c**, which is the first special operation code.|
| 2     | `address += adjusted_opcode / LINE_RANGE`            | Increases the value of the **address** register. The value of LINE_RANGE is 15, which is used to calculate the change of the line number information.|
| 3     | `line += LINE_BASE + (adjusted_opcode % LINE_RANGE)` | Increase the value of the **line** register. The value of **LINE_BASE** is **-4**, which is the minimum line number increment. The maximum row number increment is **LINE_BASE + LINE_RANGE - 1**.|
| 4     |                                                    | Generates a new location entry.                                      |

**Note:**<br>
The special operation code is calculated by using the following formula: **(line_increment - LINE_BASE) + (address_increment * LINE_RANGE) + OPCODE_BASE**.


### IndexSection
Generally, each structure of a bytecode file is referenced by using a 32-bit offset. When a structure references another structure, the 32-bit offset of the referenced structure needs to be recorded in the current structure. To reduce a file size, a bytecode file is divided into multiple index regions, and a structure in each index region uses a 16-bit index. The **IndexSection** structure describes a collection of index areas.

- Align in four bytes.
- Format

| **Name**| **Format**| **NOTE**      |
| -------------- | -------------- | --------- |
| `headers`        | `IndexHeader[]`  | An array. Each element in the array is of the [IndexHeader](#indexheader) type. Elements in the array are sorted based on the start offset of the region. The array length is specified by **num_index_regions** in [Header](#header).|


### IndexHeader
Each **IndexHeader** structure describes an index region. Each index region has two types of indexes: indexes pointing to [Type](#type) and indexes pointing to methods, strings, or literal arrays.

- Align in four bytes.
- Format

| **Name**       | **Format**| **NOTE**   |
| -------------- | -------------- | ---------- |
| `start_off`                             | `uint32_t`       | Start offset of the region.                                        |
| `end_off`                               | `uint32_t`       | End offset of the region.                                        |
| `class_region_idx_size`                 | `uint32_t`       | Number of elements in [ClassRegionIndex](#classregionindex) of the region. The maximum value is **65536**.|
| `class_region_idx_off`                  | `uint32_t`       | An offset that points to [ClassRegionIndex](#classregionindex).|
| `method_string_literal_region_idx_size` | `uint32_t`       | Number of elements in the [MethodStringLiteralRegionIndex](#methodstringliteralregionindex) of the region. The maximum value is **65536**.|
| `method_string_literal_region_idx_off`  | `uint32_t`       | An offset that points to [MethodStringLiteralRegionIndex](#methodstringliteralregionindex).|
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark Bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark Bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark Bytecode file.                          |
| `reserved`                              | `uint32_t`       | Reserved field used internally in the Ark Bytecode file.                          |


### ClassRegionIndex
The **ClassRegionIndex** structure is used to find the corresponding [Type](#type) through a more compact index.

- Align in four bytes.
- Format

| **Name**| **Format**| **NOTE**                                              |
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
The **MethodStringLiteralRegionIndex** structure is used to find the corresponding methods, strings, or literal arrays through a more compact index.

- Align in four bytes.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `offsets`      | `uint32_t[]`   | An array. The value of each element is an offset pointing to a method, a string, or a literal array. The array length is specified by **method_string_literal_region_idx_size** in [IndexHeader](#indexheader).|


### LiteralArray
Describes the literal array in the bytecode file.

- Align in single byte.
- Format

| **Name**| **Format**| **NOTE**                                              |
| -------------- | -------------- | ------------------------------------------------------------ |
| `num_literals`   | `uint32_t`       | Length of the **literals** array.                                        |
| `literals`       | `Literal[]`      | An array. Each element of the array is of the [Literal](#literal) type.|


### Literal
Describes the literals in a bytecode file. There are four encoding formats based on the number of bytes of the literals.

| **Name**| **Format**| **Alignment Type**| **NOTE**|
| -------------- | -------------- | ------------------ | -------------- |
| ByteOne        | `uint8_t`        | 1 byte           | Single-byte value.  |
| ByteTwo        | `uint16_t`       | 2 bytes           | Double-byte value.  |
| ByteFour       | `uint32_t`       | 4 bytes           | Four-byte value.  |
| ByteEight      | `uint64_t`       | 8 bytes           | Eight-byte value.  |
