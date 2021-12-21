# C Coding Style Guide

## <a name="c0-1"></a>Purpose

Rules are not perfect. Disabling useful features in specific situations may affect code implementation. However, the rules are formulated "to help most programmers to get more benefits". If a rule is found unhelpful or difficult to follow in team coding, please send your feedback to us so we can improve the rule accordingly. Before referring to this guide, you are expected to have the following basic capabilities for C rather than being a beginner who wants to learn about C.

1. Understand the ISO standard of C.
2. Be familiar with the basic features of C.
3. Understand the standard library of C.

## <a name="c0-2"></a>General Principles

Code must meet the requirements for **readability**, **maintainability**, **security**, **reliability**, **testability**, **efficiency**, and **portability** while ensuring functionality correctness.

## <a name="c0-3"></a>Conventions

**Rule**: Conventions that must be followed during programming.  
**Suggestion**: Conventions that must be considered during programming.

It is necessary to understand the reason for these conventions and to try and comply with them, no matter if they are rules or recommendations.

## <a name="c0-4"></a>Exceptions

The only acceptable exceptions are those that do not violate the general principles and provide appropriate reasons for their existence.   
Exceptions destroy code consistency. Try to avoid them. Exceptions to 'Rules' should be very rare.

The style consistency principle is preferred in the following case:   
**When you modify open source or third-party code. The existing code specifications prevail.**

# <a name="c1"></a>1 Naming

Names include file, function, variable, type, and macro names.

Naming is considered the most difficult and important thing in software development.   
The name of an identifier must be clear, well defined, and easy to understand, adapting to reading habit.

The unified naming style is the most direct expression of the consistency principle.

## <a name="c1-1"></a>General Conventions

**CamelCase**  
Camel case is the practice of writing compound words or phrases so that each word or abbreviation in the phrase begins with a capital letter, and with no intervening spaces or punctuation.   
This style has two alternatives depending on the case of the first letter: **UpperCamelCase and lowerCamelCase**

### <a name="r1-1"></a>Rule 1.1 Name identifiers in camel case style.

| Type| Naming Style
|----------|----------
| Function, struct, enumeration, union| UpperCamelCase
| Variable, function parameter, macro parameter, struct body, union member| lowerCamelCase
| Macro, constant, enumerated value, goto tag| All capitalized, separated with underscores (\_)

Note:   
The `constant` in the above table refers to the variable of the basic data type, enumeration, and string type of the const modifier under the global scope, excluding array, struct and union.   
The `variable` in the above table refers to variables other than the constant definition, all using lowercase.

### <a name="a1-1"></a>Rec 1.1 The larger the scope, the more accurate the name should be.

C is different from C++. There is no namespace or class. Therefore, the names of identifiers in the global scope must not conflict with each other.   
Names of global functions, global variables, macros, types, and enumerations must be accurately described and unique in the global scope.

Example:

```c
int GetCount(void);                 // Bad: inaccurate description.
int GetActiveConnectCount(void);    // Good
```

For accurate naming, a module prefix can be added if necessary.   
The module prefix and the naming body can be connected by following the CamelCase style.   
Example:

```c
int PrefixFuncName(void);   // OK: CamelCase, with no prefix in the format, but prefix in the content.

enum XxxMyEnum {            // OK.
    ...
};
```

## <a name="c1-2"></a>File Naming

### <a name="a1-2"></a>Rec 1.2 Use lowercase file names.

File names naming are allowed only with lowercase letters, numbers, and underscores (\_).   
File names should be as short, accurate, and unambiguous as possible.   
The reason for using lowercase file names is that different systems process file names in different ways (for example, Microsoft DOS and Windows OS are not case sensitive, but Unix/Linux and Mac systems are by default).

Good example:  
`dhcp_user_log.c`

Bad examples:   
`dhcp_user-log.c`: It is not recommended you separate names with '-'.  
`dhcpuserlog.c`: The words are not separated, causing poor readability.

## <a name="c1-3"></a>Function Naming

Functions are named in UpperCamelCase style.

### <a name="a1-3"></a>Rec 1.3 Name functions that comply with reading habits.

The "verb + object" structure can be used for action related function names. For example:

```c
AddTableEntry() // OK 
DeleteUser()    // OK
GetUserInfo()   // OK
```

An adjective or a prefix "is" can be used in a function returning a Boolean value. For example:

```c
DataReady()     // OK
IsRunning()     // OK
JobDone()       // OK
```

Data or Getter function:

```c
TotalCount()    // OK
GetTotalCount() // OK
```

## <a name="c1-4"></a>Variable Naming

Variables are named in the lowerCamelCase style. This includes global variables, local variables, parameters in the function declaration or definition as well as parameters in function-like macro.

### <a name="r1-2"></a> Rule 1.2 Add the 'g\_' prefix to global variables. Do not add this prefix to static variables in a function.

Global variables should be used as little as possible, and special attention should be paid to their use. Prefixes are used for visual prominence, prompting developers to be more careful about using global variables.   
The naming rule of global static variables is the same as that of global variables. The name of a static variable in a function is the same as that of a common local variable.

```c
int g_activeConnectCount;

void Func(void)
{
    static int pktCount = 0;  
    ...
}
```

Notes: The nature of a constant is also a global variable, but it does not apply to current rule if the naming style is all uppercase and connected by underline.

### <a name="a1-4"></a>Rec 1.4 Keep local variables short and to the point.

The name of a local variable should be short on the premise that meanings can be expressed through context.

The following is an example:

```c
int Func(...)
{
    enum PowerBoardStatus powerBoardStatusOfSlot; // Not good: Long redundant local variable.
    powerBoardStatusOfSlot = GetPowerBoardStatus(slot);
    if (powerBoardStatusOfSlot == POWER_OFF) {
        ...
    }    
    ...
}
```

Better writing style:

```c
int Func(...)
{ 
    enum PowerBoardStatus status;   // Good: The status can be clearly expressed in context.
    status = GetPowerBoardStatus(slot);
    if (status == POWER_OFF) {
        ...
    }
    ...
}
```

Similarly, "tmp" can be used to address any type of temporary variable.   
A short variable name should be used with caution, but sometimes a single character variable is allowed, for example, a counter variable in a loop statement.

```c
int i; 
...
for (i = 0; i < COUNTER_RANGE; i++) {
    ...
}
```

Or, variables in simple math functions:

```c
int Mul(int a, int b)
{
	return a * b;
}
```

## <a name="c1-5"></a>Type Naming

Types are named in the UpperCamelCase style.   
The type can be a structure, a union, or an enumeration.

Example:

```c
struct MsgHead {
    enum MsgType type;
    int msgLen;
    char *msgBuf;
};

union Packet {
    struct SendPacket send;
    struct RecvPacket recv;
};

enum BaseColor {
    RED,    // Note: The enumeration is in UpperCamelCase style while the enumerated values adopt the macro naming style.
    GREEN,
    BLUE
};

typedef int (*NodeCmpFunc)(struct Node *a, struct Node *b);
```

When you use typedef to set an alias for a struct, a union or an enum type, try to use anonymous type.   
If you need self-nesting pointers, you can add a 'tag' prefix or an underscore suffix.

```c
typedef struct {    // Good: The anonymous struct is used because self-nesting is not required.
    int a;
    int b;
} MyType;           // Struct alias with UpperCamelCase.

​```c
typedef struct tagNode {    // Good: Add the 'tag' prefix or use 'Node_'.
    struct tagNode *prev;
    struct tagNode *next;
} Node;             // UpperCamelCase.
```

## <a name="c1-6"></a>Macros, Constants, and Enumeration Naming

Macros and enumerated values are capitalized and are separated with underscores (\_).   
Constants are recommended to be capitalized and be separated with underscores (\_). Also, as global const variables, they can be named with global variable style.   
The constants here are defined as global const variables of basic data type, enumeration, and string type.

Function-like macros, can be named the same way as functions, using the UpperCamelCase naming style.   
However, this approach makes the macros look the same as functions. It is confusing and needs special attention.

Macro example:

```c
#define PI 3.14
#define MAX(a, b)   (((a) < (b)) ? (b) : (a))
```

```c
#ifdef SOME_DEFINE
void Bar(int);
#define Foo(a) Bar(a)   // The function-like macro is named as a function style.
#else
void Foo(int);
#endif
```

Constant example:

```c
const int VERSION = 200;    // OK.

const enum Color DEFAULT_COLOR = BLUE; // OK.

const char PATH_SEP = '/';  // OK.

const char * const GREETINGS = "Hello, World!"; // OK.
```

Non-constant example:

```c
// Structure type does not meet the definition of constant.
const struct MyType g_myData = { ... };     // OK: Name it in lowerCamelCase style.

// Array type does not meet the definition of constant.
const int g_xxxBaseValue[4] = { 1, 2, 4, 8 };   // OK: Name it in lowerCamelCase style.

int Foo(...)
{
    // The scope does not meet the definition of constant.
    const int bufSize = 100;    // OK: Name it in lowerCamelCase style.
    ...
}
```

Enumeration example:

```c
// Note: The enumeration type name is in the UpperCamelCase style, while enumerated values are all capitalized and separated with underscores (_).
enum BaseColor {
    RED,
    GREEN,
    BLUE
};
```

### <a name="a1-5"></a>Rec 1.5 Do not name temporary variables in function-like macros and pollute the external scope.

First, **use function-like macros as little as possible.**

When a function-like macro needs to define local variables, to avoid naming conflicts with local variables in external functions,

an underline is a good solution. Example:

```c
#define SWAP_INT(a, b) do { \
    int tmp_ = a; \
    a = b; \
    b = tmp_; \
} while (0)
```

# <a name="c2"></a>2 Formatting

## <a name="c2-1"></a>Line Length

### <a name="a2-1"></a>Rec 2.1 Ensure that each line is no more than 120 characters in length.

The line width of the code should not be too long, otherwise it is not conducive to reading.   
The line length requirement indirectly guides developers in shortening function and variable names, reducing nesting, and improving readability.   
It is strongly recommended that the number of characters per line do not exceed **120** unless readability is significantly improved as a result and no information is hidden.   
While the resolution of modern monitors is very high, long lines will increase the difficulty of reading comprehension, which is against the principles of "clear" and "concise" defined in this document.

The following scenarios should not be wrapped, and can be treated as exceptions:

- Line breaks can cause strings truncated and hard to retrieved (grep), such as command lines or URLs. Codes or comments that contain these can be treated as exceptions appropriately.
- '#include', '#error' statements are allowed to exceed the line width requirement, but you should try to avoid this.

Example:

```c
#ifndef XXX_YYY_ZZZ
#error Header aaaa/bbbb/cccc/abc.h must only be included after xxxx/yyyy/zzzz/xyz.h
#endif
```

## <a name="c2-2"></a>Indentation

### <a name="r2-1"></a>Rule 2.1 Use spaces to indent and indent four spaces at a time.

Only spaces can be used for indentation. **4** spaces are indented each time. Do not use the Tab character to indent.   
Currently, almost all integrated development environments (IDEs) and code editors support automatically converting a Tab input to **4** spaces. Please set your code editor to support indentation with spaces, if it is not the default.

## <a name="c2-3"></a>Braces

### <a name="r2-2"></a>Rule 2.2 Use the K\&R indentation style.

**K\&R style**  
While wrapping a line, the left brace of the function starts a new line and takes a single line. Other left braces are placed at the end of the line along with the statement.   
The right brace takes a single line, unless it is followed by the rest of the same statement, such as 'while' in the 'do' statement, or 'else'/'else if' of the 'if' statement, or a comma or semicolon.

For example:

```c
struct MyType {     // Good: Follow the statement to the end, and indent one space.
    ...
};                  // Good: The right brace is followed by the semicolon.

int Foo(int a)
{                   // Good: The left brace of the function starts a new line, and nothing else is placed on the line.
    if (...) {
        ...
    } else {        // Good: The 'else' statement follows the right brace.
        ...
    }               // Good: The right brace takes a single line.
}
```

## <a name="c2-4"></a>Function Declaration and Definition

### <a name="r2-3"></a>Rule 2.3 The return type and function name of the function declaration and definition must be on the same line. The function parameter list must be aligned appropriately if it needs to be wrapped.

When a function is declared and defined, the return value type of the function should be in the same line as the function name.

When the function parameter list is wrapped, it should be aligned appropriately.   
The left parenthesis of a parameter list is always in the same line as the function name. The right parenthesis always follows the last parameter.

The following is an example of line breaks:

```c
ReturnType FunctionName(ArgType paramName1, ArgType paramName2)   // Good：All in one line
{
    ...
}

ReturnType VeryVeryVeryLongFunctionName(ArgType paramName1,     // The line length cannot accommodate all parameters and thus a line break is required.
                                        ArgType paramName2,     // Good：Aligned with the previous line.
                                        ArgType paramName3)
{
    ...
}

ReturnType LongFunctionName(ArgType paramName1, ArgType paramName2, // Subject to line length, a line break is required.
    ArgType paramName3, ArgType paramName4, ArgType paramName5)     // Good: After the line break, 4 spaces are used for indentation.
{
    ...
}

ReturnType ReallyReallyReallyReallyLongFunctionName(            // The line length cannot accommodate the first parameter, and thus a line break is required.
    ArgType paramName1, ArgType paramName2, ArgType paramName3) // Good: After the line break, 4 spaces are used for indentation.
{
    ...
}
```

## <a name="c2-5"></a>Function Calls

### <a name="r2-4"></a>Rule 2.4 The parameter list should be aligned appropriately when the parameter list requires a line break.

When the function is called, if the function parameter list is wrapped, it should be aligned appropriately.   
The left parenthesis is always followed by a function name, and the right parenthesis always follows the last parameter.

The following is an example of line breaks:

```c
ReturnType result = FunctionName(paramName1, paramName2);   // Good：Function parameters are placed in one line.

ReturnType result = FunctionName(paramName1,
                                 paramName2,                // Good：Aligned with the above parameters.
                                 paramName3);

ReturnType result = FunctionName(paramName1, paramName2, 
    paramName3, paramName4, paramName5);                    // Good：After the line break, 4 spaces are used for indentation.

ReturnType result = VeryVeryVeryLongFunctionName(           // The line length cannot accommodate the first parameter, and thus a line break is required.
    paramName1, paramName2, paramName3);                    // After the line break, 4 spaces are used for indentation.
```

If the parameters in a function call are associated with each other, the parameters are grouped for better understanding, rather than strictly adhering to formatting requirements.

```c
// Good：The parameters in each line represent a group of data structures with a strong correlation. They are placed on one line for ease of understanding.
int result = DealWithStructureLikeParams(left.x, left.y,     // Indicates a group of parameters.
                                         right.x, right.y);  // Indicates another group of related parameters.
```

## <a name="c2-6"></a>Conditional Statements

### <a name="r2-5"></a>Rule 2.5 Conditional statements must use braces.

We require that all conditional statements use braces, even if there is only one statement.   
Reason:

- Logic is intuitive and easy to read.
- It is not easy to make mistakes when adding new code to the existing conditional statement.
- Function-like macros without braces are used in conditional statements, can be error prone if braces do not surround the conditional statement.

```c
if (objectIsNotExist) {         // Good: Braces are added to a single-line conditional statement.
    return CreateNewObject();
}
```

### <a name="r2-6"></a>Rule 2.6 Do not place 'if', 'else' and 'else if' in the same line.

In a conditional statement, if there are multiple branches, they should be written in different lines.

The correct format:

```c
if (someConditions) {
    ...
} else {    // Good: The 'else' is in a different line of 'if'.
    ...
}
```

The following is a case that does not comply with the specifications:

```c
if (someConditions) { ... } else { ... } // Bad: They are in the same line.
```

## <a name="c2-7"></a>Loops

### <a name="r2-7"></a>Rule 2.7 Use braces in loop statements.

Similar to the condition expression, we require that the for and while loop conditional statements contain braces, even if there is only one loop.

```c
for (int i = 0; i < someRange; i++) {   // Good: Braces are used.
    DoSomething();
}
```

```c
while (condition) { }   // Good: The while loop body is empty. And braces are used.
```

```c
while (condition) { 
    continue;           // Good: The continue keyword highlights the end of the empty loop. And braces are used.
}
```

Bad example:

```c
for (int i = 0; i < someRange; i++)
    DoSomething();      // Bad: Braces should be added.
```

```c
while (condition);      // Bad: Using semicolons will make people misunderstand which code is a part of the while statement.
```

## <a name="c2-8"></a>Switch Statements

### <a name="r2-8"></a>Rule 2.8 Indent the case or default statement in a switch statement block.

The indentation style of the switch statement is as follows:

```c
switch (var) {
    case 0:             // Good: Indented
        DoSomething1(); // Good: Indented
        break;
    case 1: {           // Good: Braces are added.
        DoSomething2();
        break;
    }
    default:
        break;
}
```

```c
switch (var) {
case 0:                 // Bad: 'case' not indented
    DoSomething();
    break;
default:                // Bad: 'default' not indented
    break;
}
```

## <a name="c2-9"></a>Expressions

### <a name="a2-2"></a>Rec 2.2 Keep a consistent expression line break style and ensure that operators are placed at the end of the line.

A long expression that does not meet the line length requirement must be wrapped appropriately. Generally, the expression is wrapped at an operator of a lower priority or a hyphen, and the operator or hyphen is placed at the end of the line.   
The operator and hyphen are placed at the end of the line, indicating that the operation is to be continued.

Example:

```c
// Pretend that the following first line does not meet the line length requirement.
if ((currentValue > MIN) &&  // Good: After the line break, the Boolean operator is placed at the end of the line.
    (currentValue < MAX)) {    
    DoSomething();
    ...
}

int result = reallyReallyLongVariableName1 +    // Good: The plus sign is placed at the end of the line.
             reallyReallyLongVariableName2;
```

After an expression is wrapped, ensure that the lines are properly aligned or indented by 4 spaces. See the following example.

```c
int sum = longVaribleName1 + longVaribleName2 + longVaribleName3 +
    longVaribleName4 + longVaribleName5 + longVaribleName6;         // OK: indented with 4 spaces

int sum = longVaribleName1 + longVaribleName2 + longVaribleName3 +
          longVaribleName4 + longVaribleName5 + longVaribleName6;   // OK: aligned
```

## <a name="c2-10"></a>Variable Assignment

### <a name="r2-9"></a> Rule 2.9 Multiple variable definitions and assignment statements cannot be written on one line.

It is best to have only one variable initialization statement on each line. It is easier to read and understand.

```c
int maxCount = 10;
bool isCompleted = false;
```

The following is an example that does not comply with the specifications:

```c
int maxCount = 10; bool isCompleted = false; // Bad: Multiple initialization statements are placed on the same line.
int x, y = 0;  // Bad: Variable definitions need to be placed on different lines. Each definition occupies one line.

int pointX;
int pointY;
...
pointX = 1; pointY = 2;  // Bad: Multiple variable assignment statements are placed on the same line.
```

Exception:   
If multiple variables with strong correlation are defined and do not need to be initialized, you can define the variables in a line to reduce repeated information so that the code is more compact.

```c
int i, j;  // Good: Multiple variables that are defined and do not need to be initialized immediately can be written in one line.
for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
        ...
    }
}
```

## <a name="c2-11"></a>Initialization

Initialization is applicable to structs, unions, and arrays.

### <a name="r2-10"></a>Rule 2.10 Indent when initiating a new line, or make a reasonable alignment.

When a structure or array is initialized, if a line break is made, ensure that the line is indented with 4 spaces.   
From the readability point of view, make a reasonable alignment.

```c
// Good: No line break for a short line.
int arr[4] = { 1, 2, 3, 4 };

// Good: A line break here makes the readability better.
const int rank[] = { 
    16, 16, 16, 16, 32, 32, 32, 32,
    64, 64, 64, 64, 32, 32, 32, 32
};
```

For complex data, the initialization should be clear and compact.   
Refer to the following format:

```c
int a[][4] = {
    { 1, 2, 3, 4 }, { 2, 2, 3, 4 }, // OK.
    { 3, 2, 3, 4 }, { 4, 2, 3, 4 }
};

int b[][8] = {
    { 1, 2, 3, 4, 5, 6, 7, 8 },     // OK.
    { 2, 2, 3, 4, 5, 6, 7, 8 }
};
```

```c
int c[][8] = {
    {
        1, 2, 3, 4, 5, 6, 7, 8      // OK.
    }, {
        2, 2, 3, 4, 5, 6, 7, 8
    }
};
```

Note:

- If the left brace is placed at the end of the line, the corresponding right brace should be placed into a new line.
- If the left brace is followed by the content, the corresponding right brace should also follow the content.

### <a name="r2-11"></a>Rule 2.11 When struct and union members are initialized, each member is initialized on a separate line.

The C99 standard supports the initialization of the struct and union members in their definition. This is called the designated initializer. If initialization is performed in this way, each member is initialized in a separate line.

```c
struct Date {
    int year;
    int month;
    int day;
};

struct Date date = {    // Good: When the designated initializer is used, each member is initialized on a separate line.
    .year   = 2000,
    .month  = 1,
    .day    = 1 
};
```

## <a name="c2-12"></a>Pointers

### <a name="a2-3"></a>Rec 2.3 The pointer type asterisk "\*" follows the variable name or the type. Do not leave spaces on both sides and always use at least one space.

When you declare or define a pointer variable or return a pointer type function, "\*" can be placed on the left or right, adhering to the type or name. Do not leave spaces on both sides. And do not leave out spaces altogether.

```c
int *p1;    // OK.
int* p2;    // OK.

int*p3;     // Bad: No spaces.
int * p4;   // Bad: Spaces on both sides.
```

Choose a style and stay consistent.

When using style that "\*" follows type, avoid declaring multiple variables with pointer in a line.

```c
int* a, b;  // Bad: It is easy to misinterpret b as a pointer.
```

When using style that "\*" follows variable, there may be situations that cannot be followed.   
Do not follow when it cannot. Style consistency first.

```c
char * const VERSION = "V100";      // OK.
int Foo(const char * restrict p);   // OK.
```

"\*" never follows 'const' or 'restrict' keywords anytime.

## <a name="c2-13"></a>Compilation Preprocessing

### <a name="r2-12"></a>Rule 2.12 The number sign (#) must be placed at the beginning of a line for compilation preprocessing and can be indented in nested compilation preprocessing.

The number sign (#) must be placed at the beginning of a line for compilation preprocessing, even if the code is embedded in the function body.

```c
#if defined(__x86_64__) && defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_16) // Good: "#" is at the beginning of the line.
#define ATOMIC_X86_HAS_CMPXCHG16B 1  // Good: "#" is at the beginning of the line.
#else
#define ATOMIC_X86_HAS_CMPXCHG16B 0
#endif

int FunctionName(void)
{
    if (someThingError) {
        ...
#ifdef HAS_SYSLOG        // Good: "#" is at the beginning of the line even though it's in a function body.
        WriteToSysLog();
#else
        WriteToFileLog();
#endif
    }
}
```

Nested preprocessing statements starting with "#" can be indented and aligned based on indentation requirements to different layers.

```c
#if defined(__x86_64__) && defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_16)
    #define ATOMIC_X86_HAS_CMPXCHG16B 1  // Good: Statements are layered, facilitating reading.
#else
    #define ATOMIC_X86_HAS_CMPXCHG16B 0
#endif
```

## <a name="c2-14"></a>Whitespace

### <a name="r2-13"></a>Rule 2.13 Ensure that horizontal whitespace is used to highlight keywords, important information and avoid unnecessary whitespace.

Horizontal spaces should be used to highlight keywords and important information. Do not add spaces at the end of each line of code. The general rules are as follows:

- Add spaces after keywords such as if, switch, case, do, while, and for.
- Do not add spaces after the left parenthesis or before the right parenthesis.
- Add a space before and after each binary operator (= + - \< > \* / % \| \& \^ \<= >= == !=).
- Do not add a space after any unary operator (\& \* + - ~!).
- A space is required before and after each ternary operator (? :).
- Add spaces before and after the colon of bit field description.
- There is no space between ++/-- and variables.
- There is no space before and after the struct member operator (. ->).
- Adding or not adding spaces inside the brace must be consistent.
- Do not add spaces before commas, semicolons, colons (without the colon in the ternary operator or the bit field description); Add spaces after them.
- There is no space between the parentheses of the function parameter list and the function name.
- There is no space between the parenthesis of the type cast and the object being converted.
- There is no space between the square bracket of the array and the array name.
- Spaces at the end of the line can be omitted.

For spaces inside the braces, the following are **recommended**:

- In general, spaces should be added after the left brace or before the right brace.
- For empty, or a single identifier, or a single literal constant, spaces are not required. Such as: '{}', '{0}', '{NULL}', '{"hi"}'.
- Spaces between consecutively nested multiple parentheses, spaces are not required. Such as: '{{0}}', '{{ 1, 2 }}'. Bad example: '{ 0, {1}}'. It is not a continuous nested scene, and the spaces inside the outermost braces are inconsistent.

In normal cases:

```c
int i = 0;                  // Good: When the variable is initialized, there should be spaces before and after the =. Do not leave a space before the semicolon.
int buf[BUF_SIZE] = {0};    // Good: During array initialization, spaces in curly braces are optional.
int arr[] = { 10, 20 };     // Good: A space is added before and after the brace.
```

Function definition and call:

```c
int result = Foo(arg1,arg2); 
                      ^         // Bad: There should be a space after the comma.

int result = Foo( arg1, arg2 );
                 ^          ^   // Bad: No space should be added to either side in the parentheses.
```

Pointer and address-of operator:

```c
x = *p;     // Good: There is no space between the operator * and the pointer p.
p = &x;     // Good: There is no space between the operator & and the variable x.
x = r.y;    // Good: When a member variable is accessed through the operator (.), no space is added.
x = r->y;   // Good: When a member variable is accessed through the operator (.), no space is added.
```

Operator:

```c
x = 0;    // Good: A space must be added before and after the assignment operator (=).
x = -5;   // Good: Do not add spaces before the minus sign (-) and the number.
++x;      // Good: Do not add spaces before the minus sign (-) and the number.
x--;
    
if (x && !y)        // Good: A space must be added before and after the Boolean operator. Do not leave spaces between the ! operator and variables.
v = w * x + y / z;  // Good: A space must be added before and after binary operators.
v = w * (x + z);    // Good: No space is required before and after the expression in the parentheses.
```

Loops and conditional statements:

```c
if (condition) {    // Good: A space is added between the if keyword and the parenthesis and no space is added before or after the conditional statement inside the parentheses.
    ...
} else {            // Good: A space is added between the else keyword and the curly brace.
    ...
}

while (condition) {}    // Good: A space is added between the while keyword and the parenthesis. No space is added before or after the conditional statement inside the parentheses.

for (int i = 0; i < someRange; ++i) {  // Good: A space is added between the for keyword and the parenthesis, and after the semicolons (;).
    ...
}

switch (var) {  // Good: A space is added after the switch keyword.
    case 0:     // Good: No space is added between the case conditional statement and the colon.
        ...
        break;
    ...
    default:
        ...
        break;
}
```

Note: Current integrated development environments (IDEs) and code editors can be set to automatically delete spaces at the end of a line. Please configure your editor as such.

### <a name="a2-4"></a>Rec 2.4 Arrange blank lines reasonably keep the code compact.

Reduce unnecessary blank lines so that more code can be displayed for easy reading. The following rules are recommended:

- Make a reasonable arrangement of blank lines according to the degree of relevance of neighboring content.
- Do not put two or more consecutive blank lines inside a function, a type definition, a macro, or an initialization expression.
- Do not use **three** or more consecutive blank lines.
- Do not add blank lines at the start and end of a code block defined by braces.

```c
ret = DoSomething();

if (ret != OK) {    // Bad: Return value judgment should follow the function call.
    return -1;
}
```

```c
int Foo(void)
{
    ...
}



int Bar(void)       // Bad: Use no more than two continuous blank lines.
{
    ...
}
```

```c
int Foo(void)
{
        
    DoSomething();  // Bad: The blank lines above and below are unnecessary.
    ...

}
```

# <a name="c3"></a>3 Comments

Generally, clear architecture and good symbol naming are recommended to improve code readability, and comments are provided only when necessary.   
Comments help readers quickly understand code. Therefore, **comments should be provided when necessary** for the sake of readers.

The comments must be concise, clear, and unambiguous, ensuring that the information is complete and not redundant.

**Comments are as important as code.**   
When writing a comment, you need to step into the reader's shoes and use comments to express what the reader really needs. Comments are used to express the function and intention of code, rather than repeating code.   
When modifying the code, ensure that the comments are consistent. It is impolite to only modify code and not update the comments. It destroys the consistency between code and comments, and may confuse or even mislead readers.

Comment code in fluent English.

## <a name="c3-1"></a>Comment Style

In C code, both `/*` `*/` and `//` can be used.   
Comments can be classified into different types depending on purpose and position, such as file header comments, function header comments, and general comments.  
Comments of the same type must keep a consistent style.

Note: The sample code used in this article sees extensive use of the '//' post-comment. This is only to aid understanding, and does not mean that this comment style is better.

## <a name="c3-2"></a>File Header Comments

### <a name="r3-1"></a>Rule 3.1 File header comments must contain the copyright license.

/\*

* Copyright (c) 2020 Huawei Device Co., Ltd.
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* ​
* http://www.apache.org/licenses/LICENSE-2.0
* ​
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License. \*/

## <a name="c3-3"></a>Function Header Comments

### <a name="r3-2"></a>Rule 3.2 Empty function header comments with no content are forbidden.

Not all functions need function header comments.  
Function header comments must be added for any information that cannot be expressed just with function prototype.

Function header comments are placed above the function declaration or definition.   
Select and use one of the following styles:   
**Use '//' to start the function header.**

```c
// Single-line function header
int Func1(void);

// Multi-line function header
// Second line
int Func2(void);
```

**Use '/\*' '\*/' to start the function header.**

```c
/* Single-line function header */
int Func1(void);

/*
 * Single-line or multi-line function header
 * Second line
 */
int Func2(void);
```

Use function names to describe functions, and only add function header comments if necessary.   
Do not write useless or redundant function headers. Do not write empty function headers with no content.

The function header comment content is **optional** any may include the following: function description, return value, performance constraint, usage, memory convention, algorithm implementation, and reentering requirements.   
In the function interface declaration in the external header file of the module, the function header comment should clearly describe important and useful information.

Example:

```c
/*
 * The number of written bytes is returned. If -1 is returned, the write operation fails.
 * Note that, the memory buffer is released by the caller.
 */
int WriteString(char *buf, int len);
```

Bad example:

```c
/*
 * Function name: WriteString
 * Function: Write a character string.
 * Parameter:
 * Return value:
 */
int WriteString(char *buf, int len);
```

Problems in the preceding example are as follows:

- The 'Parameter' and 'Return value' headings have no content.
- The function name has redundant information.
- The most important thing, the notice to release the buffer, is not clearly stated.

## <a name="c3-4"></a>Code Comments

### <a name="r3-3"></a>Rule 3.3 Code comments are placed above or to the right of the corresponding code.

### <a name="r3-4"></a>Rule 3.4 There must be a space between the comment character and the comment content. At least one space is required between the comment and code if the comment is placed to the right of code.

Comments placed above code should be indented to the same level as the code.   
Select and use one of the following styles:   
**Use '//' to start the comment.**

```c
// Single-line comment
DoSomething();

// Multi-line comment
// Second line
DoSomething();
```

**Use '/\*' '\*/' to start the comment.**

```c
/*Single-line comment */
DoSomething();

/*
 * Single-/Multi-line comment
 * Second line
 */
DoSomething();
```

Leave at least one space between the code and the comment on the right. No more than four spaces is recommended.   
You can use the extended Tab key to indent 1-4 spaces.

Select and use one of the following styles:

```c
int foo = 100;  // Comment on the right
int bar = 200;  /* Comment on the right */
```

It is more appealing sometimes when the comment is placed to the right of code and the comments and code are aligned vertically.   
After the alignment, ensure that the comment is 1–4 spaces separated from the closest code line on the left.   
Example:

```c
#define A_CONST 100         /* Related comments of the same type can be aligned vertically. */
#define ANOTHER_CONST 200   /* Leave spaces after code to align comments vertically. */
```

If the comment on the right exceeds the permitted line length, the comment can be placed above the code.

### <a name="r3-5"></a>Rule 3.5 Delete unused code segments. Do not comment them out.

Code that is commented out cannot be maintained. If you attempt to restore the code, it is very likely to introduce ignorable defects.   
The correct method is to delete unnecessary code. If necessary, consider porting or rewriting the code.

Here, commenting out refers to the removal of code from compilation without actually deleting it. This is done by using /\* \*/, //, #if 0, #ifdef NEVER\_DEFINED, and so on.

### <a name="a3-1"></a>Rec 3.1 No TODO, TBD, or FIXME comment is allowed in code delivered to a customer.

TODO and TBD comments are used to describe required improvements and supplements.  
FIXME comments are used to describe defects that need fixing.  
They should have a standardized style, which facilitates text search. For example:

```c
// TODO(<author-name>): Supplement to XX 
// FIXME: XX defect
```

During version development, this type of comments can be used for highlighting, and must be processed and deleted before delivery.

### <a name="a3-2"></a>Rec 3.2 If 'break' or 'return' is not added to the end of the case statement block (fall-through), comments must be provided.

Sometimes, the same thing is needed for multiple case tags. When a case statement ends without 'break' or 'return', the statement in the next case tag will be executed. This is called "fall-through".   
In this case, you need to add comments for the "fall-through" to clearly describe your intention.

For example, explicitly specify the "fall-through”:

```c
switch (var) {
    case 0:
        DoSomething();
        /* fall-through */
    case 1:
        DoSomeOtherThing();
        ...
        break;
    default: 
        DoNothing();
        break;
}
```

If the case statement is empty, the comment explaining the "fall-through" can be omitted.

```c
switch (var) {
    case 0:
    case 1:
        DoSomething();
        break;
    default:
        DoNothing();
        break;
}
```

# <a name="c4"></a>4 Header Files

**For the C language, the design of the header file reflects most of the system design.**   
The correct use of the header file makes code more readable, reduces file size, and speeds up compilation and build performance.

This chapter summarizes some methods from the perspective of programming specifications to help you properly plan header files.

## <a name="c4-1"></a>Header File Responsibility

A header file is an external interface of a module or file.   
The interface declaration for most functions (except inline functions), is more suitable in the header file, than as interface implementations.   
Header responsibility should be simple. A complex header file will make dependencies complex and cause long compilation times.

### <a name="a4-1"></a>Rec 4.1 Each .c file must have a corresponding .h file, which is used to declare the interfaces that need to be disclosed externally.

Generally, each .c file has a corresponding .h file (Not necessarily the same name.), which is used to store the function declarations, macro definitions, and type definitions that are to be exposed externally.   
If a .c file does not need to open any interface externally, it should not exist.

Exception: the entry point of the program (for example, the file where the main function is located), unit test code, and dynamic library code.

Example:   
foo.h content

```c
#ifndef FOO_H
#define FOO_H

int Foo(void);  // Good: Declare an external interface in the header file.

#endif
```

foo.c content

```c
static void Bar(void);  // Good: The declaration of the internal function is placed in the header of the .c file, declaring its static scope.

void Foo(void)
{
    Bar();
}

static void Bar(void)
{
    // Do something;
}
```

Internally used functions declarations, macros, enumerations, structures, and others should not be placed in header ﬁles.

In some products, one .c file corresponds to two .h files. One is used to store external public interfaces, and the other is used to store definitions and declarations among others for internal use to limit the number of code lines in the .c file.   
This style is not recommended. It is used only because the .c file is too large. It should be split into another file instead.   
In addition, if private definitions and declarations are placed in independent header files, they technically cannot avoid inclusion.

This rule, in turn, is not necessarily correct. For example:   
Some simple header files, such as the command ID definition header file, do not need to have the corresponding .c file.   
If a set of interface protocols has multiple instances and the interface is fixed, one .h file can have multiple .c files.

### <a name="a4-2"></a>Rec 4.2 Use .h as the extension of the header file, rather than other unconventional extensions, for example, .inc.

Some products use .inc as the header file name extension, which does not comply with the C language. A header ﬁle using .inc as the ﬁle name extension usually indicates a private header ﬁle. However, in practice, this recommendation is not followed properly. An .inc ﬁle is generally contained in multiple .c ﬁles. This document does not recommend that private definitions be stored in header files. For details, see [Rec 4.1](#a4-1).

## <a name="c4-2"></a>Header File Dependency

The header file contains a dependency, and the dependency should be stable.   
Generally, an unstable module depends on a stable module. When the unstable module changes, the build of the stable module is not affected.

Dependency direction is as follows: Products depend on the platform, and the platform depends on the standard library.

In addition to unstable modules depending on stable modules, each module depends on the interface. In this way, in case of any internal implementation changes to one module, users do not need to recompile another module.   
This assumes that the interface itself is the most stable.

### <a name="r4-1"></a>Rule 4.1 Forbid cyclic dependency of header files.

Cyclic dependency (also known as a circular dependency) of header files means that a.h contains b.h, b.h contains c.h, and c.h contains a.h. If any header file is modified, all code containing a.h, b.h, and c.h needs to be recompiled.   
For a unidirectional dependency: a.h contains b.h, b.h contains c.h, and c.h does not contain any header file, modifying a.h does not mean a need to recompile the source code for b.h or c.h.

The cyclic dependency of header files reflects an obviously unreasonable architecture design, which can be avoided through optimization.

### <a name="r4-2"></a>Rule 4.2 The header file must have the internal #include protection character (#define protection).

To prevent header files from being included multiple times, all header files should be protected by #define. Do not use #pragma once.

When defining a protection character, comply with the following rules:

- The protection character uses a unique name. It is recommended to consider the file path and name below the top layer of the project code tree.
- Do not place code or comments before or after the protected part, except for file header comments.

Assume that the path to timer.h of the timer module is `timer/include/timer.h`. If the protection character resembles 'TIME\_H', it is not unique. Add a path, for example:

```c
#ifndef TIMER_INCLUDE_TIMER_H
#define TIMER_INCLUDE_TIMER_H

...

#endif
```

### <a name="r4-3"></a>Rule 4.3 Do not reference external function interfaces and variables by using declaration.

You can use the interfaces provided by other modules or files only by using header files.   
Using external function interfaces and variables with an extern declaration may cause inconsistency between declarations and definitions when external interfaces are changed.   
In addition, this kind of implicit dependency may cause architecture corruption.

Cases that do not comply with specifications:   
a.c content

```c
extern int Foo(void);   // Bad: Reference external functions by using the extern declaration.
void Bar(void)
{
    int i = Foo();  // Here, the external interface Foo is used.
    ...
}
```

It should be changed to:   
a.c content

```c
#include "b.h"      // Good: Use the interface providing the interface.
void Bar(void)
{
    int i = Foo();
    ...
}
```

b.h content

```c
int Foo(void);
```

b.c content

```c
int Foo(void)
{
    // Do something
}
```

In some scenarios, if internal functions need to be referenced with no intrusion to the code, the extern declaration mode can be used.   
For example:   
When performing unit testing on an internal function, you can use the extern declaration to reference the tested function.  
When a function needs to be stubbed or patched, the function can be declared using extern.

### <a name="r4-4"></a>Rule 4.4 Do not include header files in extern "C".

If a header file is included in extern "C", extern "C" may be nested. Some compilers restrict the nesting of extern "C". If there are too many nested layers, compilation errors may occur.

extern "C" usually occurs in mixed programming using both C and C++. If the extern "C" includes a header file, the original intent behind the header file may be hindered. For example, when the linkage specifications are modified incorrectly.

For example, assume that there are two header files a.h and b.h.   
a.h content

```c
...
#ifdef __cplusplus
void Foo(int);
#define A(value) Foo(value)
#else
void A(int)
#endif
```

b.h content

```c
...
#ifdef __cplusplus
extern "C" {
#endif

#include "a.h"
void B(void);

#ifdef __cplusplus
}
#endif
```

Using the C++ preprocessor to expand b.h, the following information is displayed:

```c
extern "C" {
    void Foo(int);
    void B(void);
}
```

In the a.h file, the function Foo is intended to be a C++ free function following the C++ specifications. However, in the b.h file, because `#include "a.h"` is placed inside `extern "C"`, the linking specification of function Foo is changed incorrectly.

Exception: In the C++ compilation environment, if you want to reference a header file written in pure C, a non-intrusive approach is to exclude the C header file from `extern "C"`.

# <a name="c5"></a>5 Functions

Functions help avoid repeated code and increase reusability. In addition, functions act to layer code and reduce code complexity, hiding implementation details, making programs more modular, and facilitating reading and maintenance.

The function should be concise and short.   
One function completes only one thing.

## <a name="c5-1"></a>Function Design

Writing clean functions and organizing code effectively is the essence of good function design. The code should be simple and not conceal the designer's intention, using clean abstractions and straightforward control statements to organize the function naturally.

### <a name="r5-1"></a>Rule 5.1 Avoid long functions and ensure that functions contain no more than 50 lines (not including blank lines and comments).

A function should fit on one screen, (be no longer than 50 lines), do only one thing, and do it well.

Large functions are often caused by the fulfillment of more than one purpose by the function, or over complication when parts could be abstracted.

Exception:   
Considering the code's aggregation and functionality, some functions may exceed 50 lines, but only if the code is readable and concise.   
These exceptions should be minimal, such as specific algorithm processing.

Even if a large function works well in the moment, once someone modifies it, new problems may occur. It may even cause bugs that are difficult to discover.   
It is recommended that you split it into several simpler and easier to manage functions, facilitating reading and modification of code.

### <a name="r5-2"></a>Rule 5.2 Avoid nesting a code block more than four times within a function.

The nested code block depth of a function refers to the layered depth of a code control block (created by statements such as: if, for, while, and switch).   
Each layer of nesting increases the brain power required to read the code, because you need to maintain a "stack" in your mind comprised of each conditional statement, loop, and so on.   
Code should be broken down functionally to prevent the reader from remembering too much context at a time.

Using `guardian statements`, (a short conditional return), can effectively reduce the nesting layers of if statements. For example:   
The original code nesting level is 3:

```c
int Foo(...)
{
    if (received) {
        type = GetMsgType(msg);
        if (type != UNKNOWN) {
            return DealMsg(...);
        }
    }
    return -1;
}
```

Refactored code using the `guardian statement`, the nesting level is 2:

```c
int Foo(...)
{
    if (!received) {    // Good: Use the 'guardian statement'.
        return -1;
    }
    
    type = GetMsgType(msg);
    if (type == UNKNOWN) {
        return -1;
    }
    
    return DealMsg(..);
}
```

Exception:   
Considering the code's aggregation and functionality, some functions may exceed 4 times nested, but only if the code is readable and concise.   
These exceptions should be rare.

### <a name="a5-1"></a>Rec 5.1 Process all returned error codes.

A function (in a standard library, a third-party library, or a user-defined function) must be able to indicate errors. This can be done by using error tags, special return data, or other means. No matter when a function provides such a mechanism, the caller should immediately check the error indication after the function returns.

Example:

```c
char fileHead[128];
ReadFileHead(fileName, fileHead, sizeof(fileHead)); // Bad: The returned value is not checked.

DealWithFileHead(fileHead, sizeof(fileHead));       // The 'fileHead' is possibly invalid.
```

The correct format is as follows:

```c
char fileHead[128];
ret = ReadFileHead(fileName, fileHead, sizeof(fileHead));
if (ret != OK) {                // Good: Ensure that the 'fileHead' is written.
    return ERROR;
}

DealWithFileHead(fileHead, sizeof(fileHead));       // Process the file header.
```

Note that when the return value of a function is ignored and instead void is returned frequently, consider whether the return value of the function is designed reasonably.   
Only if the caller of a function really doesn't need a return value, should you design the function to return `void`.

## <a name="c5-2"></a>Function Parameters

### <a name="a5-2"></a>Rec 5.2 Use the return value instead of the output parameter when designing a function.

Using return values rather than output parameters improves readability and usually provides the same or better performance.

Readability can be improved by naming functions such as GetXxx, FindXxx, or directly using a single noun, to directly return the corresponding object.

### <a name="a5-3"></a>Rec 5.3 Use strongly typed parameters and avoid using void\*

While different languages have their own views on strong typing and weak typing, it is generally believed that C/C++ is a strongly typed language. Since we use such a strongly typed language, we should keep this style.   
The advantage of this strongly typed style is to prevent evasive errors by catching errors at the compilation stage.

Strong types help the compiler find more errors for us. Pay attention to the usage of the `FooListAddNode` function in the following code:

```c
struct FooNode {
    struct List link;
    int foo;
};

struct BarNode {
    struct List link;
    int bar;
}

void FooListAddNode(void *node) // Bad: Here, the void * type is used to pass parameters.
{
    FooNode *foo = (FooNode *)node;
    ListAppend(&g_fooList, &foo->link);
}

void MakeTheList(...)
{
    FooNode *foo;
    BarNode *bar;
    ...

    FooListAddNode(bar);        // Wrong: In this example, the foo parameter was supposed to be passed, but the bar parameter is incorrectly passed instead. No error is reported immediately and issues may occur as a result.
}

```

The preceding problems may be difficult to expose and are more destructive than compiler errors.   
If the parameter type of `FooListAddNode` is specified clearly, instead of with the `void *` type, the preceding problem can be detected during compilation.

```c
void FooListAddNode(FooNode *foo)
{
    ListAppend(&g_fooList, &foo->link);
}
```

Exception: For some generic interfaces, you can use the input parameter `void *` to pass different types of pointers.

### <a name="a5-4"></a>It is the caller's responsibility to check the validity of internal function parameters of a module.

Validity checks must be performed on data received from external modules to protect programs against illegal input.   
When calling internal functions, by default, the caller is responsible for ensuring the validity of any returned data. If the callee takes responsibility for checking data validity, checks may be performed multiple times and redundant code is generated. This is not concise.

The caller ensures the validity of any received data. This type of contractual programming can make logic simpler and code more readable.   
Example:

```c
int SomeProc(...)
{
    int data;
    
    bool dataOK = GetData(&data);       // Get data.
    if (!dataOK) {                      // Check the result of the previous step ensuring data validity.
        return -1;
    }

    DealWithData(data);                 // Call the data processing function.
    ...
}

void DealWithData(int data)
{
    if (data < MIN || data > MAX) {     // Bad: The caller has already ensured the validity of the data.
        return;
    }

    ...
}
```

### <a name="a5-5"></a>Rec 5.5 The pointer argument of a function should be declared as 'const' if it is not used to modify the pointed object.

The const pointer argument, which restricts the function from modifying the object through the pointer, makes code stronger and safer.

Example: In the example of the strncmp in the 7.21.4.4 of the C99 standard, the invariant parameter is declared as const.

```c
int strncmp(const char *s1, const char *s2, size_t n); // Good: The invariant parameter is declared as const.
```

Note: Whether or not the pointer parameter is to be declared as 'const' depends on the function design, not on whether there is a "modify object" action in the function entity.

### <a name="a5-6"></a>Rec 5.6 Ensure that the number of parameters in a function is less than or equal to 5.

If a function has too many parameters, the function is easy to be affected by changes in external code, hindering maintenance. Too many function parameters will also increases the workload for testing.

The number of parameters in a function must not exceed 5. If the number of parameters exceeds 5, consider the following:

- Check whether the function can be split.
- Check whether any related parameters can be combined and defined as a struct.

## <a name="c5-3"></a>Inline Functions

An inline function is a function optimization method introduced by C99. Function inlining can eliminate the overhead of function calls; thanks to inlining, combination with the called code is implemented, so that the compiler can achieve further code optimization from a larger perspective. The inline function is similar to a function-like macro. For details, see [Rec 6.1](#a6-1).

### <a name="a5-7"></a>Rec 5.7 Ensure that the inline function contains no more than 10 lines (non-blank and non-comment).

Defining a function as an inline function generally aims to improve performance, but it does not always improve performance. If the function body is short, function inlining can effectively reduce the size of the target code and improve the function execution efficiency.   
Vice versa, if the function body is large, inlining will cause expansion of the target code, especially when there are many call points.   
It is recommended that inline functions be controlled to within **10** lines.

Do not abuse inline functions to improve performance. Avoid premature optimization. In general, a function can be defined as an inline function only when actual test data proves that the inlining achieves higher performance. Functions such as setter and getter functions, that are short and called frequently can be defined as inline functions.

### <a name="r5-3"></a>Rule 5.3 Define inline functions that will be called by multiple source files in the header file.

Inline functions are unfolded in compilation. Therefore, the inline function definition must be visible in each source file that calls this function.   
As shown in the following code, inline.h has only the declaration of the `SomeInlineFunc` function but no definition. The other.c file includes inline.h. As a result, inlining fails when `SomeInlineFunc` is called.

inline.h

```c
inline int SomeInlineFunc(void);
```

inline.c

```c
inline int SomeInlineFunc(void)
{
    // Implementation code
}
```

other.c

```c
#include "inline.h"
int OtherFunc(void)
{
    int ret = SomeInlineFunc();
}
```

Due to this restriction, if multiple source files need to call the same inline function, the definition of the inline function needs to be placed in the header file.   
The inline function implementation in **gnu89** differs from that in the **C99** standard. For compatibility, you can declare the function as **static inline**.

# <a name="c6"></a>6 Macros

## <a name="c6-1"></a>Function-like Macros

A function-like macro is a macro (as shown in the following example) similar to a function. It contains several statements to implement a specific function.

```c
#define ASSERT(x) do { \
    if (!(x)) { \
        printk(KERN_EMERG "assertion failed %s: %d: %s\n", \
              __FILE__, __LINE__, #x); \
        BUG(); \
    } \
} while (0)
```

### <a name="a6-1"></a>Use functions instead of function-like macros.

Before defining a function-like macro, consider whether it can be replaced with a function. If so, you are advised to replace macros with functions.   
The disadvantages of the function-like macro are as follows:

- Function-like macros haves no type check, which is not as strict as the function call check. For the example code, see [Below](#macro_lack_of_type_check__example).
- If macro parameters are not calculated during macro expansion, unexpected results may be generated. For details, see [Rule 6.1](#r6-1) and [Rule 6.3](#r6-3).
- The macro has no independent scope. When it is used together with control flow statements, unexpected results described in [Rule 6.2](#r6-2) may be generated.
- There are high skill requirements on the proper use of macros (see the following rules), for example, the usage of `#` and parentheses affects readability.
- Extensions of some macros can only be implemented by specific compilers in specific scenarios, such as `statement expression` of `gcc`, reducing the portability.
- After the macro is expanded at the pre-compilation stage, it is invisible during subsequent compilation, linking, and debugging. Macros that contain multiple lines are expanded into a line. Function-like macros are difficult to debug, interrupt, and locate in the case of bugs.
- Macros containing a large number of statements must be expanded at each call point. If there are many call points, the code will be expanded.

<a name="macro_lack_of_type_check__example"></a>Example code of a function-like macro lacking type check:

```c
#define MAX(a, b)   (((a) < (b)) ? (b) : (a))

int Max(int a, int b)
{
    return (a < b) ? b : a;
}

int TestMacro(void)
{
    unsigned int a = 1;
    int b = -1;

    (void)printf("MACRO: max of a(%u) and b(%d) is %d\n", a, b, MAX(a, b));
    (void)printf("FUNC : max of a(%u) and b(%d) is %d\n", a, b, Max(a, b));
    return 0;
}
```

Due to the lack of type check, the comparison between `a` and `b` in `MAX` is changed to a comparison ignoring the sign status. The result is **a \< b**. The output is as follows:

```
MACRO: max of a(1) and b(-1) is -1
FUNC : max of a(1) and b(-1) is 1
```

The function does not have the preceding macro disadvantages. However, compared with macros, the biggest disadvantage is that the execution efficiency is not as high (increasing the overhead of function calls and the difficulty of compiler optimization).   
Therefore, the C99 standard introduces inline functions (gcc introduces inline functions ahead of this standard).

The inline function is similar to the macro, as it is also expanded at the call point. The difference is that inline functions are expanded during compilation.   
Inline functions have the advantages of both functions and macros:

- Strict type checking is performed for inline functions and functions.
- The parameter of an inline function/function is calculated only once.
- Inline functions are unfolded in place and there is no overhead for function calls.
- Inline functions are better optimized than standard functions.

For performance-sensitive code, consider using inline functions instead of function-like macros.   
Functions and inline functions cannot completely replace function-like macros, because function-like macros are more suitable for certain scenarios.   
For example, in a log scenario, using a function-like macro with variable parameters and default parameters is more convenient.

```c
int ErrLog(const char *file, unsigned long line, const char *fmt, ...);
#define ERR_LOG(fmt, ...) ErrLog(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
```

### <a name="r6-1"></a>Rule 6.1 When a macro is defined, macro parameters must use complete parentheses.

The macro parameter is replaced by text only when the macro is expanded. The value is calculated when the macro is compiled. After the text replacement, the statements contained in the macro are combined with called code.   
The expression after combination may result in a different result than expected, especially when the macro parameter is in an expression.

The following is an incorrect format:

```c
#define SUM(a, b) a + b         // Bad.
```

When the macro is used, the execution result is inconsistent with the expected result.   
`100 / SUM(2, 8)` is expanded to `(100 / 2) + 8`. The expected result is `100 / (2 + 8)`.   
This problem can be solved by adding parentheses to the entire expression, as shown in the following:

```c
#define SUM(a, b) (a + b)       // Bad.
```

However, this method has the following problems:   
`SUM(1 << 2, 8)` is extended to `1 << (2 + 8)` (because the priority of `<<` is lower than that of `+`), which is inconsistent with the expected result `(1 << 2) + 8`.

To solve this problem, add parentheses to each macro parameter, as shown in the following:

```c
#define SUM(a, b) (a) + (b)     // Bad.
```

The third scenario is as follows: `SUM(2, 8) * 10` . The result after the extension is `(2) + ((8) * 10)`, which is inconsistent with the expected result `(2 + 8) * 10`.

In conclusion, the correct format is as follows:

```c
#define SUM(a, b) ((a) + (b))   // Good.
```

But avoid abusing parentheses. As shown in the following, adding parentheses to a single identifier or a positive number is meaningless.

```c
#define SOME_CONST      100     // Good: No parentheses needed for a single positive number.
#define ANOTHER_CONST   (-1)    // Good: Parentheses needed for a negative number.

#define THE_CONST SOME_CONST    // Good: No parentheses needed for a single identifier.
```

Notes:

- Macro parameters in '#', '##' operation do not need parentheses.
- Macro parameters which participating in string splicing do not need parentheses.
- If a macro parameter is used as a separate part in one side of an assignment expression (including +=, -=, etc.), parentheses are not required.
- If a macro parameter is used as a separate part in comma expressions, functions or macro call lists, parentheses are not required.

Example:

```c
#define MAKE_STR(x) #x                  // No parentheses for 'x'

#define HELLO_STR(obj) "Hello, " obj    // No parentheses for 'obj'

#define ADD_3(sum, a, b, c) (sum = (a) + (b) + (c)) // 'a', 'b', and 'c' need parentheses, while 'sum' does not.

#define FOO(a, b) Bar((a) + 1, b)       // 'a' needs parentheses, while 'b' does not.
```

### <a name="r6-2"></a>Rule 6.2 Implementation statements of function-like macros that contain multiple statements must be placed in a do-while(0).

Macros do not have code blocks. Macros do not have code blocks. When a macro is expanded at the call point, the expressions and variables defined in the macro are integrated into the calling code. As a result, variable name conflict and segmentation of macro statements may occur. Use do-while(0) to add a boundary to the macro so that the macro has an independent scope. In addition, a single statement can be formed by combining the macro with a semicolon (;) to avoid this problem.

The following macro is incorrect:

```c
// Not Good.
#define FOO(x) \
    (void)printf("arg is %d\n", (x)); \
    DoSomething((x));
```

When the macro is called as shown in the following example code, the for loop only executes the first statement of the macro, and the next statement of the macro is executed only after the loop ends.

```c
for (i = 1; i < 10; i++)
    FOO(i);
```

To solve the preceding problem, use braces to enclose the statements defined by `FOO`.

```c
#define FOO(x) { \
    (void)printf("arg is %d\n", (x)); \
    DoSomething((x)); \
}
```

The brackets are not associated with semicolons (;). The semicolon following the braces is another statement.   
In the following code example, the "suspended else' compilation error message is displayed.

```c
if (condition)
    FOO(10);
else
    FOO(20);
```

The correct format is to wrap the executed body using a do-while(0), as shown in the following:

```c
// Good.
#define FOO(x) do { \
    (void)printf("arg is %d\n", (x)); \
    DoSomething((x)); \
} while (0)
```

Exception:

- Macros that contain 'break' or 'continue' statements can be treated as exceptions. Do use these macros carefully.
- An exception can be made when the macro contains an incomplete statement. For example, use a macro to encapsulate the conditional part of the for loop.
- An exception can be a non-multiple statement, or a single if/for/while/switch statement.

### <a name="r6-3"></a>Rule 6.3 Do not pass expressions with side effects to a function-like macro.

Since macros are replaced by text, if a function-like macro uses the same macro parameter multiple times and transfers expressions with side effects as macro parameters, unexpected results may occur.   
As shown in the following example, the macro `SQUARE` is normal, but the `a++` expression with side effects is passed to the macro. As a result, the value of `a` is different from the expected value after the `SQUARE` macro is executed.

```c
#define SQUARE(a) ((a) * (a))

int a = 5;
int b;
b = SQUARE(a++);    // Bad: 'a' is added twice.
```

`SQUARE(a++)` is expanded to `((a++) * (a++))` the variable `a` is added twice, and its value is `7` instead of the expected `6`.

The correct format is as follows:

```c
b = SQUARE(a);
a++; // Result: a = 6, which is added only once.
```

In addition, if the macro parameter contains a function call, the function may be called repeatedly after the macro is expanded.   
If the function execution results are the same, it is a waste; if the results are different, the execution result may not meet the expected value.

### <a name="a6-2"></a>Rec 6.2 Exercise caution when you use the statements such as return, goto, continue, and break in a function-like macro definition.

In a macro, the process changing statements, such as return, goto, continue, and break. While they can simplify the code, they hide the real process, which hinders understanding and causes resource leakage.

First, the macro encapsulation of the statement 'return' can easily lead to excessive encapsulation and use.   
As shown in the following code, the judgment of `status` is a part of the main process. After being encapsulated in macros, the purpose is not intuitive. The `RETURN_IF` macro is ignored, causing a confused understanding.

```c
#define LOG_AND_RETURN_IF_FAIL(ret, fmt, ...) do { \
    if ((ret) != OK) {                             \
        (void)ErrLog(fmt, ##__VA_ARGS__);          \
        return (ret);                              \
    }                                              \
} while (0)

#define RETURN_IF(cond, ret) do {                  \
    if (cond) {                                    \
        return (ret);                              \
    }                                              \
} while (0)

ret = InitModuleA(a, b, &status);
LOG_AND_RETURN_IF_FAIL(ret, "Init module A failed!"); // OK.

RETURN_IF(status != READY, ERR_NOT_READY);  // Bad: The most important logic is not obvious.

ret = InitModuleB(c);
LOG_AND_RETURN_IF_FAIL(ret, "Init module B failed!"); // OK.
```

Second, if return is encapsulated in a macro, it may also cause a memory leak. Example is as follows:

```c
#define CHECK_PTR(ptr, ret) do { \
    if ((ptr) == NULL) { \
        return (ret); \
    } \
} while (0)

...

mem1 = MemAlloc(...);
CHECK_PTR(mem1, ERR_CODE_XXX);

mem2 = MemAlloc(...);
CHECK_PTR(mem2, ERR_CODE_XXX);  // Wrong: Memory leak.
```

If `mem2` fails to apply for memory, the `CHECK_PTR` will return a message instead of releasing `mem1`.   
Besides, the name of the `CHECK_PTR` macro is not good. The macro name only reflects the check action and does not specify the result. Readers can see that a failure is returned when the pointer is null only after viewing the macro implementation. It's not inherently obvious.

In summary: It is not recommended to encapsulate statements that change control flow, such as return, goto, continue, and break in macro definitions.  
However, these macros can be used such as return value judgment as an exception.

Note: **Macro names must contain descriptive keywords if statements that will change control flow such as return, goto, continue, and break are used.**

### <a name="a6-3"></a>Rec 6.3 Ensure that function-like macros contain no more than 10 lines (not including blank lines and comments).

A big problem of the function-like macro is that it is more difficult to debug and locate than the function, especially when the macro is too long.   
Macro expansion will also lead to more compiled code. It is recommended that function-like macros contain no more than 10 lines.

# <a name="c7"></a>7 Variables

In C language coding, variables are the most important except for functions.   
When using a variable, you should always follow the principle of "single responsibility".   
By scope, variables can be classified into global variables and local variables.

## <a name="c7-1"></a>Global Variables

Do not use or avoid using global variables.   
In program design, global variables are variables that are accessible to all scopes. Using unnecessary global variables is generally considered a bad habit.

Disadvantages of global variables:

- Destroys the independence and portability of a function. Functions can be dependent on global variables and increased coupling results.
- Reduces readability and maintainability. When multiple functions read and write to global variables, their values may not be determinate, which is unfavorable for comprehension and maintenance.
- In a concurrent programming environment, global variables will hinder reentry of functions. Additional synchronization protection must be added to ensure data security.

If unavoidable, the read and write of global variables should be encapsulated in a centralized manner.

### <a name="r7-1"></a>Rule 7.1 Do not use global variables as interfaces between modules.

Global variables are for the internal implementation of modules and should not be exposed as interfaces.   
Global variables should be as centralized as possible. If the data of this module needs to be disclosed to external modules, a function as an interface to this data should be provided.

## <a name="c7-2"></a>Local Variables

### <a name="r7-2"></a>Rule 7.2 Do not use uninitialized variables as rvalues.

The variable here refers to a local dynamic variable, and also includes a memory block obtained on a memory heap.   
Because their initial values are unpredictable, it is prohibited to use them directly as rvalues without effective initialization.

```c
void Foo(...)
{
    int data;
    Bar(data);  // Bad: Uninitialized variables are used as rvalues.
    ...
}
```

If there are different branches, ensure that all branches are initialized before being used as rvalues.

```c
void Foo(...)
{
    int data;
    if (...) {
        data = 100;
    }
    Bar(data);  // Bad: This value is not initialized in some branches.
    ...
}
```

Uninitialized rvalues can be found by generic static check tools.   
For example, the PCLint tool reports a warning for the following two examples.

> Warning 530: Symbol 'data' (line ...) not initialized Warning 644: Variable 'data' (line ...) may not have been initialized

### <a name="r7-3"></a>Rule 7.3 Forbid invalid and redundant variable initialization.

If the initial value is not determined before initialization is performed, it is not concise but not secure, which may introduce problems that are more difficult to discover.

Common redundant initialization:

```c
int cnt = 0;    // Bad: Redundant initialization. It will be overwritten by later initialization.
...
cnt = GetXxxCnt();
...
```

Variables with conditional values can be initialized to default values during definition.

```c
char *buf = NULL;   // Good: NULL as the default value
if (condition) {
    buf = malloc(MEM_SIZE);
}
...
if (buf != NULL) {  // Check whether memory has been allocated.
    free(buf);
}
```

Even worse, redundant clearing for arrays may affect the performance.

```c
char buf[VERY_BIG_SIZE] = {0};  
memset(buf, 0, sizeof(buf));    // Bad: Redundant clearing
```

Invalid initialization, which hides a more severe problem:

```c
void Foo(...)
{
    int data = 0;   // Bad: regular initialization

    UseData(data);          // UseData should be placed after GetData.
    data = GetData(...);    // Get data.
    ...
}
```

In the preceding code, if 0 is not assigned before initialization, the static check tool can help find the problem of "direct use without being initialized".   
However, due to invalid initialization, the defect of placing "UseData" before "GetData" cannot be easily found.

Therefore, simple code should be written to initialize variables or memory blocks as required.

The C99 does not limit the definition position of local variables to before the first statement in a function. That is, a variable can now be defined close to a variable.   
This concise approach not only limits the scope of the variable scope, but also solves the problem of how to initialize the variable when it is defined.   
If this compilation environment is supported, you are advised to define local variables in this way.

**Exception:**   
**As 'Secure Coding Standard' required, pointers, resource variables, and boolean variables can be treated as exceptions of this rule.**

### <a name="r7-4"></a>Rule 7.4 Do not use magic numbers.

The so-called magic numbers are the numbers that are unintelligible and difficult to understand.   
The magic number is not a concept that can be defined literally. It varies depending on context and service knowledge.

For example, the number 12 varies in different contexts.   
`type = 12;` is not intelligible, but `month = year * 12;` can be understood.   
The number 0 is sometimes seen as a magic number. For example, the `status = 0;` cannot truly express any status information.

Solution:   
Comments can be added for numbers that are used only once.  
For numbers that are used multiple times, macro or const variables must be defined and self-commented with symbolic naming.

The following cases are forbidden:   
The name is not used to explain the meaning of a number, for example, `#define ZERO 0`.  
The value is limited by the name, for example, `#define XX_TIMER_INTERVAL_300MS 300`.

# <a name="c8"></a>8 Programming Practice

## <a name="c8-1"></a>Expressions

### <a name="a8-1"></a>Rec 8.1 When comparing expressions, follow the principle that the left side tends to change and the right side tends to remain unchanged.

When a variable is compared with a constant, placing the constant on the left, for example, `if (MAX == v)` does not read naturally, and `if (MAX > v)` is more diﬃcult to understand.   
The constant should be placed on the right according to the normal reading order and habit. The expression is written as follows:

```c
if (v == MAX) ...
if (v < MAX) ...
```

There are special cases: for example, the expression `if (MIN < v && v < MAX)` is used to check for a range. This first constant should be placed on the left.

You do not need to worry about accidentally writing '==' as '=' because a compilation alarm will be generated for `if (v = MAX)` and an error will be reported by other static check tools. Use these tools to solve such writing errors and ensure that that code is readable.

### <a name="r8-1"></a>A full expression containing an increment (++) or decrement (--) operator should have no other using of the variable.

In an expression containing a variable increment or decrement operation, if the variable is referenced again, the result is not explicitly defined in the C standard, which may vary between compilers or different versions of the same compiler.   
For better portability, you should not make any assumptions about the operation sequence not defined in any standards.

Note that this problem cannot be solved by using parentheses because it is not a problem of priority.

Example:

```c
x = b[i] + i++; // Bad: b[i] operation and i++, the order is not clear.
```

The correct way is to add a separate line of increment or decrement:

```c
x = b[i] + i;
i++;            // Good: Single line.
```

Function parameter:

```c
Func(i++, i);   // Bad: When passing the second parameter, it is not sure whether the increment operation has occurred.
```

The correct way:

```c
i++;            // Good: Single line.
x = Func(i, i);
```

### <a name="a8-2"></a>Rec 8.2 Use parentheses to specify the sequence of expressions, instead of using the default priority.

Parentheses can be used to better emphasize the purpose of used operators. This will prevent program errors due to the inconsistency between default priority and the intended design.   
However, too many parentheses muddy the code, reducing readability. Use them moderately.

Parentheses are recommended when expressions contain operators that are not commonly used and are confusing, such as bitwise operators.

```c
c = (a & 0xFF) + b;     /* Parentheses are required while using bit operators. */
```

## <a name="c8-2"></a>Statements

### <a name="r8-2"></a>Rule 8.2 The switch statement must have a 'default' branch.

In most cases, the 'default' branch exists in the switch statement to ensure that there is a default processing action when the case tag is missing.

Exception:   
If the switch condition variable is of the enumeration type and the case branches cover all values, then the default branch is redundant.   
A modern compiler can check whether the case branch of some enumerated values is missing in the switch statement. A warning will be displayed.

```c
enum Color {
    RED,
    BLUE
};

// The switch condition variable is an enumerated value. Therefore, you do not need to add the 'default' processing branch.
switch (color) {
    case RED:
        DoRedThing();
        break;
    case BLUE:
        DoBlueThing();
        ... 
        break;
}
```

### <a name="a8-3"></a>Rec 8.3 Exercise caution when using the goto statement.

The goto statement destroys the structure of the program, so you'd better not use the goto statement unless you really need it. You can only jump to statements following the goto statement, and only within the one function.

The goto statement is used to implement function return to a single point within a function.   
If a function has a large number of identical logics that cannot be encapsulated, for example, repeated file execution, the processed part of code after the file operation failure (for example, closing the file handle and releasing memory that is dynamically applied for) is usually placed in the last part of the function body. And the goto statement is placed right before these. In this way, the code becomes clear and concise. It can also be encapsulated in functions or macros, but doing so makes code less straightforward.

Example:

```c
// Good: Use a goto statement to implement function return at a single point.
int SomeInitFunc(void)
{
    void *p1;
    void *p2 = NULL;
    void *p3 = NULL;

    p1 = malloc(MEM_LEN);
    if (p1 == NULL) {
        goto EXIT;
    }

    p2 = malloc(MEM_LEN);
    if (p2 == NULL) {
        goto EXIT;
    }

    p3 = malloc(MEM_LEN);
    if (p3 == NULL) {
        goto EXIT;
    }

    DoSomething(p1, p2, p3);
    return 0;   // OK.

EXIT:
    if (p3 != NULL) {
        free(p3);
    }
    if (p2 != NULL) {
        free(p2);
    }
    if (p1 != NULL) {
        free(p1);
    }
    return -1;  // Failed!
}
```

## <a name="c8-3"></a>Type Conversion

### <a name="a8-4"></a>Rec 8.4 Minimize unnecessary type conversion and forced conversion.

When the data type is forcibly changed, the meaning of the data and the value after conversion may change. If details are not considered, potential risks may be generated.

In the following assignment, most compilers do not generate warnings, but the values are slightly changed.

```c
char ch;
unsigned short int exam;

ch = -1;
exam = ch; // Bad: Compilers does not generate any warnings. In this case, the value of exam is 0xFFFF.
```