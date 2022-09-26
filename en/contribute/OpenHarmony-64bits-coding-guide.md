# 32- and 64-Bit Portability Coding Guide

## About This Document

### Purpose

OpenHarmony aims to build an open, distributed OS framework for smart IoT devices in the full-scenario, full-connectivity, and full-intelligence era. It has the following technical features: hardware collaboration for resource sharing, one-time development for multi-device deployment, and a unified OS for flexible deployment.
OpenHarmony supports the following system types:

1. Mini system: a device oriented to devices that have MCU processors such as ARM Cortex-M and 32-bit RISC-V. These devices have limited hardware resources. The minimum device memory is 128 KiB.
2. Small system: a device oriented to devices that have application processors such as 64-bit ARM Cortex-A. The minimum device memory is 1 MiB.
3. Standard system: a device oriented to devices that have application processors such as 64-bit ARM Cortex-A. The minimum device memory is 128 MiB.

OpenHarmony code can run on 32- and 64-bit devices. For easier code portability, clear coding specifications are necessary. This document stipulates the specifications on code porting and 64-bit coding, helping you improve code standardization and portability.

### Application Scope

C and C++ code for the user space and kernel space, without distinguishing the programming language standards.

### Differences Between 32-Bit OS and 64-Bit OS

#### Data Type Differences

Most 32-bit OSs use ILP32, which defines int, long, and pointer as 32 bits. Most 64-bit OSs use LP64, which defines long, long long, and pointer as 64 bits. The Windows OS uses LLP64, which defines long long and pointer as 64 bits. The table below lists the length of each primitive data type.

| **Type**| **ILP32** | **LP64** | **LLP64** | **LP32** | **ILP64** |
| --------- | --------- | -------- | --------- | -------- | --------- |
| char      | 1         | 1        | 1         | 1        | 1         |
| short     | 2         | 2        | 2         | 2        | 2         |
| int       | 4         | 4        | 4         | 2        | 8         |
| long      | **4**     | **8**    | **4**     | 4        | 8         |
| long long | 8         | 8        | 8         | 8        | 8         |
| float     | 4         | 4        | 4         | 4        | 4         |
| double    | 8         | 8        | 8         | 8        | 8         |
| size_t    | **4**     | **8**    | **8**     | 4        | 8         |
| pointer   | **4**     | **8**    | **8**     | 4        | 8         |

The table below lists the length of `sizeof` and `print` in ILP32 and LP64 to show the differences between constants and types.

| Type               | ILP32 sizeof | ILP32 print | LP64 sizeof | LP64 print | Remarks|
| ------------------ | ------------ | ----------- | ----------- | ---------- | ------ |
| bool               | 1            | %u          | 1           | %u         | C++    |
| char               | 1            | %d or %c| 1           | %d or %c|        |
| unsigned char      | 1            | %u          | 1           | %u         |        |
| short              | 2            | %d          | 2           | %d         |        |
| unsigned short     | 2            | %u          | 2           | %u         |        |
| int                | 4            | %d          | 4           | %d         |        |
| unsigned int       | 4            | %u          | 4           | %u         |        |
| long               | 4            | %ld         | **8**       | %ld        | Differences exist.|
| unsigned long      | 4            | %lu         | **8**       | %lu        | Differences exist.|
| long int           | 4            | %ld         | **8**       | %ld        | Differences exist.|
| unsigned long int  | 4            | %lu         | **8**       | %lu        | Differences exist.|
| long long          | 8            | %lld        | 8           | %lld       |        |
| unsigned long long | 8            | %llu        | 8           | %llu       |        |
| type \*             | 4            | %p          | **8**       | %p         | Differences exist.|
| pid_t              | 4            | %d          | 4           | %d         |        |
| socklen_t          | 4            | %u          | 4           | %u         |        |
| off_t              | 4            | %zd         | **8**       | %zd        | Differences exist.|
| time_t             | 4            | %zd         | 8           | %zd        | Differences exist.|
| pthread_t          | 4            | %zu         | **8**       | %zu        | Differences exist.|
| size_t             | 4            | %zu         | 8           | %zu        | Differences exist.|
| ssize_t            | 4            | %zd         | **8**       | %zd        | Differences exist.|

#### Differences in Data Structure Alignment

##### Alignment of the data structure that contains a pointer

```c
typedef struct tagFoo {
    void *p;
    uint32_t i;
} Foo;
```

On a 32-bit OS, the pointer length is 4, **Foo** is 4-byte aligned, and **sizeof(Foo)** is 8. On a 64-bit OS, the pointer length is 8, **Foo** is 8-byte aligned, and **sizeof(Foo)** is 16.

##### Alignment of the data structure that contains a 64-bit integer

```c
typedef struct tagFoo {
    uint64_t p;
    uint32_t i;
} Foo;
```

Although uint64\_t has a fixed length, **sizeof(Foo)** is different due to alignment. On a 32-bit OS, **Foo** is 4-byte aligned, and **sizeof(Foo)** is 12. On a 64-bit OS, **Foo** is 8-byte aligned, and **sizeof(Foo)** is 16. The preceding statement is also true when uint64\_t is replaced by double.	

### Conventions

**Rule**: Conventions that must be complied with during programming.

**Rec**: Conventions that should be complied with during programming.

## Coding Guide

### General Principles

#### [Rule] Follow this coding guide to write code that is applicable to both 32- and 64-bit OSs.

[Description] OpenHarmony will run in both 32- and 64-bit environments for a long time. To ensure code consistency, you must consider code portability during coding.

### Data Type Definition and Formatting

#### [Rule] Use the defined data types to define variables, and avoid custom basic data types without special meanings or requirements.

[Description] Data types with variable lengths may cause incompatibility issues on 32- and 64-bit OSs. Unified and clear data types are required. OpenHarmony defines the following primitive data types:

| Type| ILP32 | LP64  | Print| Use Case|
| ---------------- | ----- | ----- | ------- | ------------------------------------------------------------ |
| void             | -     | -     | -       | Used only for placeholder and general pointer definition.|
| char             | 1     | 1     | %c      | Used for strings and arrays.|
| int8_t           | 1     | 1     | %d      | Used for 1-byte integers.|
| uint8_t          | 1     | 1     | %u      | Used for 1-byte integers.|
| int16_t          | 2     | 2     | %d      | Used to replace short.|
| uint16_t         | 2     | 2     | %u      | Used to replace unsigned short.|
| int32_t          | 4     | 4     | %d      | Used to replace int.|
| uint32_t         | 4     | 4     | %u      | Used to replace unsigned int.|
| int64_t          | 8     | 8     | %PRId64 | Used to replace long long and macros.|
| uint64_t         | 8     | 8     | %PRIu64 | Used to replace unsigned long long and macros.|
| float            | 4     | 4     | %f      | Used for single-precision floating point numbers.|
| double           | 8     | 8     | %lf     | Used for double-precision floating point numbers.|
| bool             | 1     | 1     | %d      | Used for Boolean.|
| uintptr_t        | **4** | **8** | %zu     | Used for pointer storage. Different lengths are defined for 32- and 64-bit OSs.|
| type \*           | **4** | **8** | %p      | Variable-length type. It is equivalent to uintptr_t, which is recommended for type conversion.|
| nullptr_t        | **4** | **8** | %p      | Used for pointer initialization.|
| pid_t            | 4     | 4     | %d      | Built-in for the Linux kernel. It has a fixed length.|
| socklen_t        | 4     | 4     | %u      | Built-in for the Linux kernel. It has a fixed length.|
| off_t/time_t     | **4** | **8** | %zd     | Signed, variable-length type.|
| size_t/pthread_t | **4** | **8** | %zu     | Unsigned, variable-length type. It is used only for compatibility of calling library functions (for example, size_t is used in an underlying API).|

The preceding types are defined in the **stddef.h** (C) and **cstdint** (C++) standard libraries. When `#define` is used to redefine related types, the source must be one of these types.

Do not use non-standard types unless otherwise specified. Do not define common basic types unless they have special meanings. For primitive data types used in third-party interfaces and API calling, refer to their respective rules.

[Example] Do not customize primitive data types unless necessary.

```c
// Do not use the following code to redefine a data type.
typedef unsigned int UINT32;// This definition is forbidden.

// The preceding definition can be replaced by uint32_t. However, you can define a type that has a specific meaning.
typedef uint32_t DB_TABLE_ID; // This definition can be retained.
```

[Example] Do not use the following two types, because their lengths are different from the common sense.

| Type| ILP32  | LP64  | PRINT | Use Case|
| -------- | ------ | ----- | ----- | ---------------------- |
| float_t  | **12** | **4** | -     | Improper length. Do not use it.|
| double_t | **12** | **8** | -     | Improper length. Do not use it.|

#### [Rec] Do not use custom variable-length variables. A clear description is required if they are used to adapt to platforms or third-party interfaces.

[Description] The native types such as long, int, short, and size_t have different lengths in the 32- and 64-bit environments. This may cause code risks. If these types are used for external storage or communication, system incompatibility may occur. Therefore, do not use them unless otherwise specified.

[Exception] Due to platform, third-party interface, or library function reasons, they can be used with a clear description.

[Example]

```c
long var;
// This data type is 4-byte long on a 32-bit OS and 8-byte long on a 64-bit OS. You are advised to use uint32_t or uint64_t instead.
```

#### [Rule] Do not use uchar to define variables.

[Description] It is not standard to use uchar or unsigned char to define strings. Instead, use char for strings or uint8_t for unsigned integers.

For non-ANSI character sequences involving 8-bit encoding, char is recommended. In C++, wchar can be used.

#### [Rule] Define an integer variable that is used to store a pointer as uintptr_t.

[Description] The uintptr_t type is used to store data of the pointer length. The length can be automatically adjusted in the 32- and 64-bits environments.

[Example]

```c
uintptr_t sessionPtr;

// When the pointer is stored as a variable, both the forced type conversion and left value should be defined as uintptr_t to adapt to the length changes in different scenarios.
sessionPtr = (uintptr_t) GetMemAddress();
```

#### [Rec] When the type defined by the input parameter or return value of a function does not match the variable type, exercise caution to ensure that the result is correct after conversion following the value assignment and type conversion rules.

[Description] If type inconsistency is inevitable, convert the type with caution to ensure that the final result meets the application requirements.

[Example]

```c
long function (long l);
int main () {
    int i = -2;
    unsigned int k = 1U;
    long n = function(i + k);
}
```

Note: The preceding code will fail to be executed on a 64-bit OS because the expression (i + k) is an unsigned 32-bit expression. When it is converted to the long type, the symbols are not extended. The result of the input parameter is incorrect. The solution is to forcibly convert one of the operands to a 64-bit type.

#### [Rule] Use 64-bit compatible macros, such as %PRId64, %PRIu64, and %PRIx64, to print 64-bit integers. Incompatible macros, such as %d, %ld, %zd, %x, and %lx, are not allowed.

[Description] If the data to be formatted is of the 64-bit type (defined as uint64_t), format the output as follows:

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint64_t a = 0x1234567fffffff;
    printf("a = %"PRIx64"\n", a);
    return 0;
}
```

The preceding code can output 64-bit numbers in both 32- and 64-bit environments. If other formatting methods are used, compatibility issues may occur, as listed in the following table.

| Formatting Method| ILP32 Build| ILP32 Result| LP64 Build| LP64 Result| Conclusion|
| ---------- | -------------- | --------- | -------------- | -------- | ---------- |
| %lx        | Type mismatch alarm| Incorrect| No alarm| Correct| Incompatible|
| %zx        | Type mismatch alarm| Incorrect| No alarm| Correct| Incompatible|
| %llx       | No alarm| Correct| Type mismatch alarm| Correct| Incompatible|
| %p         | Type mismatch alarm| Incorrect| Type mismatch alarm| Correct| Incompatible|
| %PRIx64    | No alarm| Correct| No alarm| Correct| Compatible|

[Example]The following is an example of the type mismatch alarm information:

```bash
# Build on a 32-bit OS
format '%lx' expects argument of type 'long unsigned int', but argument 2 has type 'uint64_t {aka long long unsigned int}'
format '%zx' expects argument of type 'size_t', but argument 2 has type 'uint64_t {aka long long unsigned int}'
format '%p' expects argument of type 'void *', but argument 2 has type 'uint64_t {aka long long unsigned int}'

# Build on a 64-bit OS
format '%llx' expects argument of type 'long long unsigned int', but argument 2 has type 'uint64_t {aka long unsigned int}'
format '%p' expects argument of type 'void *', but argument 2 has type 'uint64_t {aka long unsigned int}'
```

#### [Rule] When printing type-variable data, consider the data length and reserve sufficient space during alignment.

[Description] On a 32-bit OS, the maximum length of the pointer and size_t is 8 bits (hexadecimal) or 10 bits (decimal). On a 64-bit OS, their maximum length is 20 bits. Therefore, you need to consider the length range when printing the data.

#### [Rule] Do not use L/UL as the suffix of constants. You can add the suffix U to indicate the unsigned int type and the suffix LL/ULL to indicate the 64-bit length.

[Description] By default, constants without suffixes are of the int type. When L/UL is used as the suffix, the length may change on 32- and 64-bit OSs. Therefore, use LL/ULL as the suffix to ensure that the length is fixed at 64 bits in both the 32- and 64-bit environments.

| Constant| ILP32     | LP64  | Scenario|
| -------------- | --------- | ----- | ------------------------------------------------------------ |
| 1              | 4         | 4     | The default type is int32_t, and the length is fixed.|
| 1U             | 4         | 4     | The default type is uint32_t, and the length is fixed.|
| 1L             | **4**     | **8** | The suffix is L. The length is not fixed. Do not use this constant.|
| 1UL            | **4**     | **8** | The suffix is UL. The length is not fixed. Do not use this constant.|
| 1LL            | 8         | 8     | The default type is int64_t. The value is a long integer, and the length is fixed at 64 bits.|
| 1ULL           | 8         | 8     | The type is uint64_t, and the value is an unsigned long integer.|
| 0x7FFFFFFF     | 4         | 4     | The value is an unsigned number. It can be used within the value range of int32\_t. The default type is int32\_t. |
| 0x7FFFFFFFL    | **4**     | **8** | The length is not fixed. Do not use this constant.|
| 0x7FFFFFFFLL   | 8         | 8     | The length is fixed.|
| 0x80000000     | 4         | 4     | It can be used within the value range of uint32\_t. The type is uint32\_t.|
| 0x80000000L    | **4**     | **8** | The suffix is L. It can be used within the value range of uint32\_t. This constant is meaningless. Do not use it.|
| 0x80000000LL   | 8         | 8     | The suffix is LL. It can be used within the value range of uint32\_t. The length is fixed.|
| 0x8000000000   | **NA or 8**| **8** | No prefix. It can be used when the value range of uint32\_t is exceeded. The compiler uses LL by default or considers the value invalid. On a 64-bit OS, the type is fixed at uint64\_t.|
| 0x8000000000L  | **NA or 8**| **8** | The suffix is L. It can be used when the value range of uint32_t is exceeded. This constant is meaningless. Do not use it.|
| 0x8000000000LL | 8         | 8     | The suffix is LL. The type is uint64_t.|

As shown in the preceding table, a constant with the L or UL suffix has different lengths in the 32- and 64-bit environments. This hinders code portability. Therefore, do not use the L or UL suffix.

[Example]

```c
// UL in the following definition is meaningless. It causes an error on a 32-bit OS and is unnecessary on a 64-bit OS.
#define YYY_START_ADDRESS(XXX_START_ADDR + 0x80000000UL)
```

#### [Rule] Use macro constants defined in the standard header file.

[Description] The standard header files **stdint.h** (C) and **cstdint.h** (C++) contain macro constants with the maximum and minimum values. Reference these macro constants, rather than customizing new ones.

[Example]

```c
#include <cstdio>
#include <cinttypes>
 
int main()
{
    std::printf("%zu\n", sizeof(std::int64_t));
    std::printf("%s\n", PRId64);
    std::printf("%+" PRId64 "\n", INT64_MIN);
    std::printf("%+" PRId64 "\n", INT64_MAX);

    std::int64_t n = 7;
    std::printf("%+" PRId64 "\n", n);
}
```

#### [Rule] Use unified definitions instead of all Fs to indicate invalid values of constants.

[Description] The same numeric constant value may be understood differently on 32- and 64-bit OSs, since the 32-bit OS has the signed and unsigned types. Especially, if the most significant bit is 1, this bit is considered as a negative number on a 32-bit OS based on the signed type and a positive number on a 64-bit OS. Use the definitions in **typedef.h** to indicate invalid values.

```c
// Use the definitions in typedef.h.
#define INVALID_INT8((int8_t)(-1))
#define INVALID_UINT8((uint8_t)(-1))
#define INVALID_INT16((int16_t)(-1))
#define INVALID_UINT16((uint16_t)(-1))
#define INVALID_INT32((int32_t)(-1))
#define INVALID_UINT32((uint32_t)(-1))
#define INVALID_INT64((int64_t)(-1))
#define INVALID_UINT64((uint64_t)(-1))
```

[Example]

```c
// On a 32-bit OS, n is a negative number.
long n = 0xFFFFFFFF;
// On a 64-bit OS, n is a positive number. The actual value is 0x00000000FFFFFFFF.
long n = 0xFFFFFFFF;
```

#### [Rec] Use uint32_t to define temporary variables whose size does not exceed 32 bits.

[Description] You do not need to pay special attention to the type of a variable. Use the default uint32_t type to minimize forced type conversions caused by type inconsistency.

### Structure Alignment and Padding

#### [Rule] Do not hardcode a constant to specify the variable length and structure length. Use built-in types such as **sizeof** to obtain the variable length and structure length.

[Description] **sizeof** automatically calculates the variable length and structure length, which might be incorrect if hardcoded. In addition, the running performance will not be adversely affected since the variable length is calculated during build.

On a 64-bit OS, 8-byte alignment is used by default. Using **sizeof()** to obtain the structure length can avoid length calculation errors caused by structure alignment.

Pay attention to the length differences on 32- and 64-bit OSs to avoid length calculation errors. Calculate and apply for space based on the maximum length.

[Example] **sizeof** is not used to calculate the structure length, causing insufficient memory space.

```c
int32_t *p;
p = (int32_t *)malloc(4 * ELEMENTS_NUMBER);
// This code assumes that the pointer length is 4 bytes. However, in LP64, the pointer length is 8 bytes.

// The correct method is to use sizeof().
int32_t *p;
p = (int32_t *)malloc(sizeof(p) * ELEMENTS_NUMBER);
```

#### [Rec] In special cases, force the compiler to use a specific alignment mode on the 64-bit OS.

[Description] If necessary, you can use the specified alignment mode to ensure code compatibility. If the pseudo-instruction **#pragma pack (n)** is used, the compiler aligns data by n bytes. If the pseudo-instruction **#pragma pack ()** is used, the compiler cancels the custom byte alignment mode.

[Example]

```c
#pragma pack(push) // Save the current alignment mode.
#pragma pack(1) // Set the alignment mode to 1-byte alignment.
struct test
{
    ......
};
#pragma pack(pop) // Restore the previous alignment mode.
```

#### [Rule] Uniform the message structures related to multi-device communication. For compatibility purposes, 1-byte alignment is preferred. Do not use 8-byte alignment or 64-bit data types to avoid errors during communication with a 32-bit OS.

Note: Inter-board communication messages involve inter-board operations. The communication fails unless all software is upgraded synchronously. For the sake of compatibility, use 1-byte alignment for the existing protocols and structures and convert them into the network byte order. For new communication protocols, use 4-byte alignment for higher communication efficiency and processing performance.

#### [Rule] Avoid structure padding for external APIs and use at least 4-byte alignment.

[Description] If structure definitions are included in an API header file provided externally, do not pad the structures. It is recommended that natural alignment be used to avoid data holes. Use at least 4-byte alignment.

#### [Rec] Use member names to access structure members. Do not use the offset mode.

[Description] The offsets of data structure members are different in the 32- and 64-bit environments. Therefore, the size of each member cannot be used as the offset. A 32-bit OS does not have structures automatically padded. However, on a 64-bit OS, automatic padding may occur.

[Example]

```c
Struct A
{
    uint32_t a;
    uint32_t *p;
    uint32_t b;
};
```

The offset of member b is equal to sizeof(a) + sizeof(p) on a 32-bit OS. This is not true on a 64-bit OS. The correct method is to locate the index based on the variable name.

```c
xxx.b = 123;
```

If the structure definition is special, for example, if the structure is only the message header and there are other fields, then you can redefine the structure so that it does not include padding fields.

[Example]

```c
typedef struct {
    uint32_t self;           /* Structure used for alignment. */
    uint32_t brother;        /* Structure used for alignment. */
    uint8_t processedFlag;   /* Flag indicating whether the current node has been processed. */
    uint8_t reserve[3];      /* Reserved for 4-byte alignment. */
} TreeNodeInfo;

typedef struct {
    TreeNodeInfo nodeInfo;   /* Data structure of each node's tree information. */
    void *userInfo;          /* Data structure of each node's user information. */
} TreeNode;
```

The **TreeNode** structure has two member structures. In the following code, the address of the first member is the initial address of the second member minus the value of sizeof (the first member). (**inUserInfo** points to the **userInfo** field in the structure.)

```c
inTreeNodeInfo = (TreeNodeInfo *)((void *)(((char *)inUserInfo) - sizeof(TreeNodeInfo)));
```

The structure adopts natural alignment. Note that the length of the substructure **TreeNodeInfo** is 12 bytes on both 32- and 64-bit OSs. On a 32-bit OS, there is no padding between member structures of the **TreeNode** structure, and the structure length is 16 bytes. On a 64-bit OS, **sizeof(TreeNodeInfo)** is 12 and **sizeof(TreeNode)** is 24, which means that there is a 4-byte padding field after the substructure **TreeNodeInfo**. Therefore, when the preceding method is used to obtain the address of the previous field on a 64-bit OS, the 4-byte padding field is not calculated, causing a member access error.

#### [Rec] When defining a structure, implement 8-byte natural alignment to save storage space and avoid padding on the premise that readability is ensured.

[Description] If a structure can be naturally aligned, no padding is required, which effectively reduces the invalid space of the structure. You are advised to define 64-bit data types such as size_t and pointer at both ends of the structure without affecting readability.

[Example]

```c
// The length of the following structure is 24 bytes in natural alignment mode.
struct Foo
{
    int32_t a;
    uint64_t l;
    int32_t x;
}

// After proper adjustment, the size can be reduced to 16 bytes.
struct Foo
{
    uint64_t l;
    int32_t a;
    int32_t x;
}
```

### Data Type Conversion and Calculation

#### [Rule] Avoid implicit type conversion between different data types. If necessary, use explicit type conversion to avoid result inconsistency between the 32- and 64-bit environments.

[Description] Exercise caution when performing operations between operands with different lengths and precisions. Pay attention to the following about implicit type conversion:

1. When the value of a 64-bit variable is assigned to a 32-bit variable, the values of the least significant 32 bits are directly assigned, and the values of the most significant 32 bits are ignored. Then the least significant 32 bits are treated as signed or unsigned based on the left value variable type.

2. When the value of a 32-bit variable is assigned to a 64-bit variable, sign extension is performed based on whether the 32-bit variable is signed or unsigned, and then the 64-bit variable is treated as signed or unsigned based on the variable type.

3. For operations of signed and unsigned numbers, if the result type is not specified, the result is treated as unsigned by default.

The preceding conversion process may cause unexpected results. Therefore, exercise caution to avoid implicit type conversion as much as possible.

[Example] Example of the correct conversion result

```c
int32_t t1 = -2;
int64_t t2 = 1;
int32_t t3 = t1 + t2;
printf("t3 = %d\n", t3);

// Printed: t3 = -1
```

t1 is a 32-bit number, and t2 is a 64-bit number. Before the calculation, t1 is extended to 64 bits. After the calculation, the result is a 64-bit int64_t type. The hexadecimal value stored in the memory is 0xffffffffffffffff. During the value assignment, the value is truncated into 0xffffffff. Then, the value is treated as signed, which is -1. Although the result is correct, data truncation occurs. This may not be the author's intention.

[Example] Conversion from signed to unsigned

```c
int64_t t1 = -1;
uint32_t t2 = t1;
printf("t2=%u", t2);

// Printed: t2=4294967295
```

t1 is a 64-bit int64_t type, which is 0xffffffffffffffff in binary mode. When this value is assigned to a 32-bit int type, the most significant 32 bits are ignored and the least significant 32 bits are displayed. The binary value is 0xffffffff, which is 4294967295 in unsigned mode.

[Example] Conversion from 32-bit to unsigned 64-bit

```c
int32_t t1 = -1;
uint64_t t2 = t1;
printf("t2 = %lu\n", t2);

// Printed: t2 = 18446744073709551615
```

t1 is a signed negative 32-bit number, which must be extended with signs. The most significant bits of the negative number are all fs, and the value after extension is 0xffffffffffffffff. t2 is an unsigned 64-bit number, the value of which is a large positive number.

#### [Rule] When a pointer is used as the base address and the offset is calculated by byte, the pointer must be forcibly converted to a single-byte pointer such as uintptr_t or uint8_t \*.

[Description] If the pointer is converted to an integer of the uint32_t type, the pointer may be truncated. This will not occur if the pointer is converted to uintptr_t. The pointer can also be converted to a single-byte pointer such as uint8_t \* and char \*. In this case, the offset is considered as bytes. A one-byte offset will be carried out for the void \* type. To clarify the type, you are advised to use the type that is more specific.

[Example]

```c
// Incorrect
void *pPkt = (void *)((uint32_t)MSG_GET_DATA_ADDR(msgAddr) + OFFSET);

// Correct
void *pPkt = (void *)((uintptr_t)MSG_GET_DATA_ADDR(msgAddr) + OFFSET); // C
void *pPkt = reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(MSG_GET_DATA_ADDR(msgAddr)) + OFFSET); // C++
```

#### [Rule] Mutual assignment is forbidden between pointers and uint32_t, including function parameter passing.

[Description] If the variable to be defined is a length-variable pointer, use void \*. If the variable to be defined is a pointer or an integer, use uintptr_t.

[Example] Conversion between pointers and integers

```c
int32_t i, *p, *q;
p = &i;
q = (int32_t *) (int32_t)&i;

// In ARM Cortex-A32, p = q; in A64-LP64, p != q
```

To avoid this type conflict, use uintptr_t to indicate the pointer type.

#### [Rule] Mutual assignment is forbidden between size_t and int32_t/uint32_t, including function parameter passing.

[Description] The variable-length type cannot be forcibly converted to the 32-bit type.

[Example]

```c
int32_t length = (int32_t)strlen(str); // Incorrect
```

strlen returns size_t (unsigned long in LP64). When the value is assigned to int32_t, truncation is inevitable. Generally, truncation occurs only when the length of **str** is greater than 2 GB. This is rare in programs.

#### [Rule] When a large array or large `for` loop index is used on a 64-bit OS, the index type must be consistent with the subscript boundary.

[Description] If a large array or large loop is used on a 64-bit OS, the index range may exceed 32 bits. In this case, the variable-length type or 64-bit type must be used to define the array subscript or loop variable to prevent full traversal failures caused by an incorrect variable range.

[Example]

```c
int64_t count = BIG_NUMBER; 
for (unsigned int index = 0; index != count; index++)
    ... 
```

On a 64-bit OS, int64_t is a 64-bit type, and count is a large number. unsigned int is a 32-bit type. As a result, the loop never ends. Therefore, the index type should be changed to int64_t.

### Bit Field and Byte Order

#### [Rule] When defining variables based on bit fields, fully consider the basic types and alignment of bit fields to avoid calculation errors in different bit widths.

[Description] Consider both the width of a bit field and alignment. The structure length is different in different environments. Use the name rather than direct calculation result for the value of a bit field.

#### [Rule] On a 64-bit OS, consider the length difference caused by the shift operation and the problem that the value generated after shift is implicitly extended to 64 bits.

[Description] During the shift operation, check whether overflow and rewind occur. Change the data type to 32-bit to avoid result inconsistency.

[Example]

```c
int64_t t = 1 << a; // Consider the size of a.
```

The maximum value of a is 32 on a 32-bit OS and 64 on a 64-bit OS. If a is a 32-bit variable, the extension to 64 bits must also be considered.

### Third-Party Libraries and Differentiated Features

#### [Rule] The third-party class libraries used by a 64-bit OS must support 64-bit.

[Description] Some library functions and third-party open-source code may not fully support 64-bit. You must evaluate all involved code to ensure that it can run in the 64-bit environment. Some library functions are implemented using different APIs in the 32- and 64-bit environments. Ensure that correct APIs are used.

[Example] In the 32-bit environment, **mmap** can be used. If the size of the memory to map exceeds 2 GB, **mmap64** is required. In the 64-bit environment, **mmap** is used.

#### [Rule] Functionalities involving bottom-layer assembly must be debugged separately on the 32- and 64-bit OSs.

[Description] The number and bit width of registers are different in the 32- and 64-bit environments. The debugging functionalities related to assembly must be adjusted. You must also pay attention to the code validity in the 32-bit and 64-bit environments.

[Example] For the push-to-stack functionality of the call stack, you must write and debug the assembly code in the 32- and 64-bit environment separately.

#### [Rule] The patch functionality must support both 32- and 64-bit instructions.

[Description] The patch mechanism and functionalities must be adopted to the command length changes.

#### [Rule] All tools used on a 64-bit OS must support 64-bit.

[Description] If type inconsistency is inevitable, convert the type with caution to ensure that the final result meets the application requirements.
