# Kernel Coding Specification


This kernel coding specification is developed based on the general programming specifications in the industry. It defines the programming styles for kernel developers to follow.

## Principle

Overall principle:

-   Clear: The code should be easy to understand, maintain, and rebuilt. Avoid obscure syntax.
-   Simple: Use short names and compact functions.
-   Efficient: Improve program efficiency by using algorithms, compiler optimization options, or hardware resources.
-   Concise: The code is reasonable and consistent.

Comply with this specification in most cases. When third-party open-source code needs to modified or a large number of open-source code APIs are used, follow the specifications applied to the third-party open-source code. Flexibly use this specification based on general principles.

## Directory Structure

You are advised to divide directories by function module and then define the header file directory and source file directory for each module.

Unless otherwise specified, use lowercase letters separated by underscores \(\_\) for directory names and file names.

## **Naming**

The CamelCase style is recommended. The rules are as follows:

<a name="table881274918408"></a>
<table><thead align="left"><tr id="row1886484994019"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p6864184954016"><a name="p6864184954016"></a><a name="p6864184954016"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p486416495404"><a name="p486416495404"></a><a name="p486416495404"></a>Naming Style</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p18864549124011"><a name="p18864549124011"></a><a name="p18864549124011"></a>Format</p>
</th>
</tr>
</thead>
<tbody><tr id="row486494913409"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p2864184916403"><a name="p2864184916403"></a><a name="p2864184916403"></a>Function, struct, enumeration, union, and typedef</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p18864154944015"><a name="p18864154944015"></a><a name="p18864154944015"></a>Upper camel case, or upper camel case prefixed with the module name</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p10864249124015"><a name="p10864249124015"></a><a name="p10864249124015"></a>AaaBbb</p>
<p id="p1886444919403"><a name="p1886444919403"></a><a name="p1886444919403"></a>XXX_AaaBbb</p>
</td>
</tr>
<tr id="row198643495409"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p18864174964013"><a name="p18864174964013"></a><a name="p18864174964013"></a>Local variables, function parameters, macro parameters, structure fields, and union members</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p12864204924018"><a name="p12864204924018"></a><a name="p12864204924018"></a>Lower camel case</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p8864549124012"><a name="p8864549124012"></a><a name="p8864549124012"></a>aaaBBB</p>
</td>
</tr>
<tr id="row15864184913405"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p786484914014"><a name="p786484914014"></a><a name="p786484914014"></a>Global variables</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1786544914400"><a name="p1786544914400"></a><a name="p1786544914400"></a>Lower camel case prefixed with g_</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1986594994013"><a name="p1986594994013"></a><a name="p1986594994013"></a>g_aaaBBB</p>
</td>
</tr>
<tr id="row48651849104017"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p8865104914407"><a name="p8865104914407"></a><a name="p8865104914407"></a>Macros (excluding function-like macros), enumerated values, goto tags</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p186574954011"><a name="p186574954011"></a><a name="p186574954011"></a>All uppercase letters separated with underscores (_)</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p188653494401"><a name="p188653494401"></a><a name="p188653494401"></a>AAA_BBB</p>
</td>
</tr>
<tr id="row1286516495402"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p108651749114012"><a name="p108651749114012"></a><a name="p108651749114012"></a>Function-like macros</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1586534910405"><a name="p1586534910405"></a><a name="p1586534910405"></a>Uppercase letters separated with underscores (_), upper camel case, or upper camel case prefixed with the module name</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1186544904010"><a name="p1186544904010"></a><a name="p1186544904010"></a>AAA_BBB</p>
<p id="p18865174918402"><a name="p18865174918402"></a><a name="p18865174918402"></a>AaaBbb</p>
<p id="p13865174910407"><a name="p13865174910407"></a><a name="p13865174910407"></a>XXX_AaaBbb</p>
</td>
</tr>
<tr id="row6865154974017"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p6865114944011"><a name="p6865114944011"></a><a name="p6865114944011"></a>Header file names</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p16865134944010"><a name="p16865134944010"></a><a name="p16865134944010"></a>Starts with an underscore (_) and ends with H. The middle part is the file name in all caps and is separated by underscores (_).</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1986520493408"><a name="p1986520493408"></a><a name="p1986520493408"></a>_AAA_H</p>
</td>
</tr>
</tbody>
</table>

The  **LOS\_**_ModuleFunc_  format is recommended for external APIs of the kernel. Preposition the object if there is any. Example:

```
LOS_TaskCreate
LOS_MuxLock
```

The APIs between internal modules in the kernel directory are in the  **Os**_ModuleFunc_  format. For example:

```
OsTaskScan
OsMuxInit
```

## Comments

Generally, clear software architecture and appropriate symbol naming improve code readability.

Comments are added to make the source code easier for humans to understand. Therefore, add comments only when necessary, from the perspective of the readers.

Comments must be concise, clear, and unambiguous. The information must be complete and not redundant.

Comments must be added to the file header. It is recommended that the comments include the copyright description, file function description, author, creation date, and precautions.

Use a consistent style for comments. The use of /\* and \*/ as block comment delimiters is recommended. There must be a space between the comment characters and the comment. Comment single-line and multi-line comments are as follows:

```
/* Single-line comment */
// Single-line comment
/*
 * Multi-line comment
 * Second line
 */
// Multi-line comment
// Another line
```

Place the code comment above or to the right of the code.

Leave no blank line between the code and the comment, and indent the comment the same way as the code.

Leave at least one space between the code and the comment on the right.

You are advised to align multiple consecutive comments on the right. For example:

```
#define CONST_A 100    /* Const A */
#define CONST_B 2000   /* Const B */
```

## **Format**

Indent code of each level with four spaces rather than tabs \('\\t'\) for a better readability.

While wrapping a line, the left brace of the function starts a new line and takes a single line. Other left braces are placed at the end of the line along with the statement. The right brace occupies one line unless followed by the remaining part of the same statement, for example, while in the do statement, else/else if in the if statement, or a comma or semicolon.

Write only one statement in one line.

Example:

```
struct MyType {  // Add a comment here, and leave a space between the comment sign (//) and the comment.
    ...
};               // The right brace is followed by a semicolon (;).
int Foo(int a) {// The left brace of the function is placed at the beginning of a line and occupies one line.
    if (a > 0) {
        Foo();   // There is only one statement in a line.
        Bar();         
     } else {    // The right brace, else, and the subsequent left brace are in the same line.
        ...         
     } // The right brace occupies one line exclusively.
     ... 
}
```

Avoid lines longer than 120 characters. When starting a new line, place the operator at the end of the line, indent the new line or align the lines of the same type, and place the operator indicating not end or connection sign at the end of the line.

```
// Assume that the first line below does not fit on a single line.
if (currentValue > MIN && // Good: Place the Boolean operator at the end of the new line.
    currentValue < MAX) { // Good: Align with the two operands of the (&&) operator.
       DoSomething();
       ... 
}
flashPara.flashEndAddr = flashPara.flashBaseAddr + // Good: Place the plus sign at the end of the line.
                         flashPara.flashSize; // Good: Align the two operands.

// Good: Place function parameters in one line.
ReturnType result = FunctionName(paramName1, paramName2); 
ReturnType result = FunctionName(paramName1,
                                 paramName2,
                                 paramName3); // Good: Align with the preceding parameters.
ReturnType result = FunctionName(paramName1, paramName2,
      paramName3, paramName4, paramName5); // Good: Place the parameters in a new line, with an indentation of 4 spaces.
ReturnType result = VeryVeryVeryLongFunctionName( // Start a new line because the first parameter does not fit on a single line.
      paramName1, paramName2, paramName3); // Indent the new line 4 spaces.

// Good: Place a group of data structures with strong correlation in a line for easy understanding.
int result = DealWithStructLikeParams(left.x, left.y, // Indicates a group of related parameters.
                                      right.x, right.y); // Indicates another group of related parameters.
```

Use braces, that is, compound statements for  **if**,  **for**,  **while**, and  **do-while**  statements.

```
while (condition) {} // Good: Use braces even if the loop body is empty.
while (condition) {
     continue;       // Good: continue indicates empty logic. Use braces.
}
```

Indent the  **case**  or  **default**  statement as follows compared with the  **switch**  statement:

```
switch (var) {
    case 0:             // Good: Indent
        DoSomething1(); // Good: indent
        break;
    case 1: {           // Good: with braces
        DoSomething2();
        break;
    }
    default:
        break;
}
```

The pointer "\*" follows a variable or function name, for example:

```
int *p1;   // OK
int* p2; // Bad: The pointer * follows a data type.
int*p3; // Bad: There is no space on both sides of *.
int * p4; // Bad: There is a space on both sides of *.
struct Foo *CreateFoo(void); // OK: The pointer * follows a function name.
Exception:
char * const VERSION = "V100";    // OK: When there is the const modifier, a space is required on both sides of *.
int Foo(const char * restrict p); // OK: When there is the restrict modifier, a space is required on both sides of *.
sz = sizeof(int*); // OK: There is no variable on the right, and * follows the data type.
```

## Macros

If a function-like macro can be replaced by a function, use a function instead. Use inline functions for performance-critical scenarios.

When defining a macro, use complete parentheses \(round brackets\). For example:

```
#define SUM(a, b) ((a) + (b)) // Complies with this specification.
#define SOME_CONST  100         // Good:  No parentheses are required for a single number.
#define ANOTHER_CONST   (-1)    // Good: Parentheses are required for a negative number.
#define THE_CONST   SOME_CONST  // Good: No parentheses are required for a single identifier.
```

Pay attention to the following:

-   Do not add parentheses for macro parameters used in \# or \#\# operations.
-   Do not add parentheses for macro parameters used in string concatenation.
-   If a macro parameter is used as a separate part in one side of an assignment operation\(including += and -=\), parentheses can be omitted.
-   If a macro parameter is used as a separate part in a comma expression, function, or macro call list, parentheses can be omitted.

```
// Do not enclose x in parentheses.
#define MAKE_STR(x) #x

// Do not enclose obj in parentheses.
#define HELLO_STR(obj) "Hello, " obj

// Parentheses are required for a and b, but not for value.
#define UPDATE_VALUE(value, a, b) (value = (a) + (b))

// Parentheses are required for a, but not for b.
#define FOO(a, b) Bar((a) + 1, b)
```

The statement used to implement the function-like macros that contain multiple statements must be placed in  **do-while\(0\)**.

Do not pass expressions with side effects, such as  **a++**, to function-like macros as parameters.

Exercise caution when using the statements such as  **return**,  **goto**,  **continue**, and  **break**  in the function-like macro definition.

Do not use preprocessor directives, such as  **\#include**,  **\#deﬁne**, and  **\#ifdef**, in arguments for macro calling. Otherwise, undefined behavior may occur.

Do not end macro definitions with a semicolon \(;\).

## Header Files<a name="section158507231319"></a>

A header file should have a single responsibility.

Generally, each .c file should have a .h file \(the file name may not be the same\) to store the function declaration, macro definition, and type definition provided externally. If no external API is provided, the .h file can be skipped.

Avoid circular dependency between header files. For example,  **a.h**  contains  **b.h**,  **b.h**  contains  **c.h**, and  **c.h**  contains  **a.h**.

Header files should be self-contained \(compile on their own\).

Protect header files by  **\#deﬁne**,  **\#ifndef**, and  **\#endif**  to prevent repeated inclusion. Do not use  **\#pragma once**.

Do not reference external function APIs or variables in declaration mode. Use the APIs provided by other modules or files only by including header files.

It is recommended that header files be included by stability in the following sequence: header file corresponding to the source code, C standard library, operating system library, platform library, project public library, and other dependencies.

## Data Types

You are advised to use the basic data types defined in  **los\_compiler.h**. For example, define the 32-bit unsigned integer as  **UINT32**.

## Variables

Avoid large stack allocations, such as large local arrays.

Use global variables with caution. Do not use or reduce global variables if possible.

Variables must be initialized before being used.

Do not return the address of a local variable outside its scope.

A variable that points to a resource handle or descriptor is assigned a new value immediately after the resource is released. If the scope of the variable ends immediately, no new value needs to be assigned. Variables that point to resource handles or descriptors include pointers, file descriptors, socket descriptors, and other variables that point to resources.

## Assertions

Assertions must be defined using macros and take effect only in the debugging version.

Assertions should be considered as design constraints. Do not use assertions to detect errors that may occur during program running. Use error processing code to handle possible errors.

Do not change the running environment in an assertion.

An assertion is used to check only one error.

## Functions

The validity of data sent from a process to another process and data sent from an application to the kernel must be verified. The verification includes but is not limited to the following:

-   Data length
-   Data range
-   Data type and format
-   Input that contains only acceptable characters \(in a trustlist\)

Do not use global variables, static local variables, or direct I/O operations in functions. If such operations are inevitable, encapsulate read and write operations.

