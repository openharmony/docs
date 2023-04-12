# C++ Coding Style Guide

## Purpose
Rules are not perfect. They might disable useful features in specific situations and therefore affect code implementation. However, the purpose of developing rules is to get more benefits for most programmers. If a rule cannot be followed in your team operation, we can improve the rule together.

Before referring to this coding style guide, you are expected to have the following basic capabilities of the C++programming language: 

1. Have a general knowledge of ISO standards for C++.
2. Be familiar with the basic features of C++, including those of C++ 03/11/14/17.
3. Have a general knowledge of the C++ standard library.

## General Principles
Code must meet the requirements for readability, maintainability, security, reliability, testability, efficiency, and portability while ensuring functionality correctness.  

## Key Points
1. C++ programming style, such as naming and typesetting.
2. C++ modular design, including how to design header files, classes, interfaces, and functions.
3. Best practices of C++ features, including constants, type casting, resource management, and templates.
4. Best practices of modern C++, including conventions that can improve code maintainability and reliability in C++ 11/14/17.
5. This coding style guide is preferentially applicable to C++17.

## Conventions
**Rule**: Conventions that must be followed during programming.

**Rec**: Conventions that must be considered during programming.

This document is applicable to standard C++ versions (C++ 03/11/14/17) unless otherwise specified.

## Exceptions
It is necessary to understand the reason for these conventions and try to comply with them, no matter if they are rules or recommendations.

However, some rules and recommendations have exceptions.

The only acceptable exceptions are those that do not violate the general principles and provide appropriate reasons for the exception.

Try to avoid exceptions because they affect the code consistency. Exceptions to 'Rules' should be very rare.

The style consistency principle is preferred in the following case: 

When you modify open-source or third-party code, comply with their respective code specifications.

# 2 Naming
## General Naming Rules
__CamelCase__
CamelCase is the practice of writing compound words or phrases so that each word or abbreviation in the phrase begins with a capital letter, and with no intervening spaces or punctuation.

There are two conventions: UpperCamelCase and lowerCamelCase.


| Type                                     | Naming Style                             |
| ---------------------------------------- | ---------------------------------------- |
| Class, struct, enumeration, union, scope name| UpperCamelCase                           |
| Functions (including global functions, scope functions, and member functions) | UpperCamelCase                           |
| Global variables (including variables of the global and namespace scopes, and class static variables), local variables, function parameters, and class, struct, and union member variables | lowerCamelCase                           |
| Macro, constant, enumerated value, goto tag| All capitalized, separated by underscores (\_)|

Note:

**Constant** in the above table refers to the variable that is of the basic data type, enumeration type, and string type and modified by **const** or **constexpr** under the global scope, the namespace scope, and the scope of a static member of a class, excluding arrays and other variables.

**Variable** indicates the variables excluding those defined in **Constant**. These variables use the lowerCamelCase style.

## File Naming
### Rule 2.2.1 Use .cpp as the C++ file name extension and .h as the header file name extension.
It is recommended that you use .h as the file name extension of a header file so that the header file is compatible with C and C++.

It is recommended that you use .cpp as the file name extension of an implementation file. In this way, you can easily distinguish C++ code from C code.

At present, there are some other file name extensions used by programmers:

- Header files:  .hh, .hpp, .hxx
- Implementation files: .cc, .cxx, .C

If your project team uses a specific file name extension, you can continue to use it and keep the style consistent.

This document uses .h and .cpp extensions.


### Rule 2.2.2 Keep C++ file names the same as the class name.
The names of the C++ header file and the C++ implementation file must be the same as the class name. Use the unix\_like style and keep the style consistent.

For example, if there is a class named DatabaseConnection, the corresponding file names are as follows:
- database_connection.h
- database_connection.cpp

The naming rules of struct, namespace, and enumeration definition files are similar to the rules above.

## Function Naming
Functions are named in the UpperCamelCase style. Generally, the verb or verb-object structure is used.
```cpp
class List {
public:
	void AddElement(const Element& element);
	Element GetElement(const unsigned int index) const;
	bool IsEmpty() const;
};

namespace Utils {
    void DeleteUser();
}
```

## Type Naming

Types are named in the UpperCamelCase style.

All types, such as classes, structs, unions, typedefs, and enumerations, use the same conventions. Example:

```cpp
// Classes, structs, and unions
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...
union Packet { ...

// typedefs
typedef std::map<std::string, UrlTableProperties*> PropertiesMap;

// Enums
enum UrlTableErrors { ...
```

For namespace naming, UpperCamelCase is recommended.
```cpp
// Namespaces
namespace OsUtils {
  
namespace FileUtils {
      
}
  
}
```


### Rec 2.4.1 Do not abuse typedef or #define to set alias for the basic data types.
Unless otherwise specified, do not use typedef or #define to redefine basic data types.

The basic data types found in the `<cstdint>` header file are preferable.

| Signed Type | Unsigned Type | Description                              |
| ----------- | ------------- | ---------------------------------------- |
| int8_t      | uint8_t       | The signed or unsigned 8-bit integer type. |
| int16_t     | uint16_t      | The signed or unsigned 16-bit integer type. |
| int32_t     | uint32_t      | The signed or unsigned 32-bit integer type. |
| int64_t     | uint64_t      | The signed or unsigned 64-bit integer type. |
| intptr_t    | uintptr_t     | The signed or unsigned integer type large enough to hold a pointer. |


## Variable Naming
General variables, including global variables, function parameters, local variables, and member variables, are named in the lowerCamelCase style.
```cpp
std::string tableName;  // Good: Recommended style.
std::string tablename;  // Bad: Forbidden style.
std::string path;       // Good: When there is only one word, lowerCamelCase (all lowercase) is used.
```

### Rule 2.5.1 Add the prefix 'g_' to global variables. Do not add a prefix to a static variable.
Global variables should be used as little as possible, and special attention should be paid to their use. This prefix highlights global variables so that developers can be more careful when handling them.
- Global static variables and global variables are named in the same way.
- Static variables in functions and common local variables are named in the same way.
- Static member variables in classes and common member variables are named in the same way.

```cpp
int g_activeConnectCount;

void Func()
{
    static int packetCount = 0;  
    ...
}
```

### Rule 2.5.2 Name member variables in classes in the unix\_like style.

```cpp
class Foo {
private:
    std::string fileName_;   // Add the underscore (\_) as the suffix, similar to the K&R naming style.
};
```
Use the lowerCamelCase style and do not add prefixes or suffixes to name a member variable of the struct or union type. Keep the naming style consistent with that for a local variable.

## Macro, Constant, and Enum Naming
Use uppercase letters separated by underscores (\_) for macro names and enumerated values.
In the global scope, constants of named and unnamed namespaces and static member constants should be capitalized and separated with underscores (\_).Local constants and ordinary const member variables use the lowerCamelCase naming style.

```cpp
#define MAX(a, b) (((a) < (b))? (b): (a)) // Example of naming a macro only.

enum BaseColor {    // Note: The enum type name is in the UpperCamelCase style, whereas the enumerated value is in uppercase letters separated by underscores (\_).
    RED,
    DARK_RED,
    GREEN,
    LIGHT_GREEN
};

int Func(...)
{
    const unsigned int bufferSize = 100;    // Local variable
    char *p = new char[bufferSize];
    ...
}

namespace Utils {
	const unsigned int DEFAULT_FILE_SIZE_KB = 200;        // Global variable
}

```

# 3 Formatting

## Line Length

### Rule 3.1.1 Include 120 characters or less in each line.
If the line of code exceeds the permitted length, wrap the line appropriately.

Exceptions:
- If a line of comment contains a command or URL of more than 120 characters, you can keep the line for easy copy, paste, and search using the grep command.
- The #include and #error statements are allowed to exceed the line length requirement. However, you should try to avoid this.
- The error information in preprocessor directives can exceed the permitted length.
  Put the error information of preprocessor directives in one line to facilitate reading and understanding even if the line contains more than 120 characters.
```cpp
#ifndef XXX_YYY_ZZZ
#error Header aaaa/bbbb/cccc/abc.h must only be included after xxxx/yyyy/zzzz/xyz.h, because xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#endif
```

## Indentation

### Rule 3.2.1 Use spaces to indent and indent 4 spaces at a time.
Only spaces can be used for indentation. Four spaces are indented each time. Do not use the Tab character to indent.

Currently, almost all integrated development environments (IDEs) support automatic conversion of a Tab input to four spaces. Configure your IDE to support indentation with spaces.

## Braces
### Rule 3.3.1 Use the K&R indentation style.
__K&R style__

While wrapping a line, the left brace of the function (excluding the lambda statement) starts a new line and takes a single line. Other left braces are placed at the end of the line along with the statement.

The right brace takes a single line, unless it is followed by the rest of the same statement, such as `while` in the `do` statement, `else` or `else if` in the `if` statement, a comma, or a semicolon.

Example:
```cpp
struct MyType {     // The left brace is placed at the end of the line along with the statement, and one space is used for indentation.
    ...
};

int Foo(int a)
{                   // The left brace of the function starts a new line, and nothing else is placed on the line.
    if (...) {
        ...
    } else {
        ...
    }
}
```
The reasons for recommending this style are as follows:

- Code is more compact.
- Placing the brace at the end of the statement makes the code more continuous in reading rhythm than starting a new line.
- This style complies with mainstream norms and habits of programming languages.
- Most modern IDEs have an automatic code indentation, alignment and display. Placing the brace at the end of a line does not impact understanding.


If no function body is inside the braces, the braces can be put on the same line.
```cpp
class MyClass {
public:
    MyClass() : value_(0) {}
    
private:
    int value_;
};
```

## Function Declarations and Definitions

### Rule 3.4.1 Keep the return type and function name of the function declaration or definition in the same line, and align the function parameter list appropriately if it needs to be wrapped.
When a function is declared and defined, the return value type of the function should be in the same line as the function name. When the function parameter list is wrapped, it should be aligned appropriately.
The left parenthesis of a parameter list is always in the same line as the function name. The right parenthesis always follows the last parameter.

Example:
```cpp
ReturnType FunctionName(ArgType paramName1, ArgType paramName2)   // Good: All are in the same line.
{
    ...
}

ReturnType VeryVeryVeryLongFunctionName(ArgType paramName1,     // Each added parameter starts on a new line because the line length limit is exceeded.
                                        ArgType paramName2,     // Good: aligned with the previous parameter.
                                        ArgType paramName3)
{
    ...
}

ReturnType LongFunctionName(ArgType paramName1, ArgType paramName2, // Parameters are wrapped because the line length limit is exceeded.
    ArgType paramName3, ArgType paramName4, ArgType paramName5)     // Good: After the line break, 4 spaces are used for indentation.
{
    ...
}

ReturnType ReallyReallyReallyReallyLongFunctionName(            // The line length cannot accommodate even the first parameter, and a line break is required.
    ArgType paramName1, ArgType paramName2, ArgType paramName3) // Good: After the line break, 4 spaces are used for indentation.
{
    ...
}
```

## Function Calls
### Rule 3.5.1 A function call parameter list should be placed on one line. When the parameter list exceeds the line length and requires a line break, the parameters should be properly aligned.
A function call parameter list should be placed on one line. When the parameter list exceeds the line length and requires a line break, the parameters should be properly aligned.

The left parenthesis always follows the function name, and the right parenthesis always follows the last parameter.

The following are examples of proper line breaks:
```cpp
ReturnType result = FunctionName(paramName1, paramName2);   // Good: All function parameters are on one line.

ReturnType result = FunctionName(paramName1,
                                 paramName2,                // Good: aligned with the previous parameter
                                 paramName3);

ReturnType result = FunctionName(paramName1, paramName2, 
    paramName3, paramName4, paramName5);                    // Good: Parameters are wrapped. After the line break, 4 spaces are used for indentation.

ReturnType result = VeryVeryVeryLongFunctionName(           // The line length cannot accommodate even the first parameter, and a line break is required.
    paramName1, paramName2, paramName3);                    // After the line break, 4 spaces are used for indentation.
```

If some of the parameters called by a function are associated with each other, you can group them for better understanding.
```cpp
// Good: The parameters in each line represent a group of data structures with strong correlation. They are placed on a line for ease of understanding.
int result = DealWithStructureLikeParams(left.x, left.y,     // A group of related parameters.
                                         right.x, right.y);  // Another group of related parameters.
```

## if Statements

### Rule 3.6.1 Use braces to include an if statement.
We require that all if statements use braces, even if there is only one statement.

Reasons:
- The logic is intuitive and easy to read.
- It is less prone to mistakes when new code is added to the existing if statement.
- If function-like macros are used in a conditional statement, it is less prone to mistakes (in case the braces are missing when macros are defined).

```cpp
if (objectIsNotExist) {         // Good: Braces are added to a single-line conditional statement.
    return CreateNewObject();
}
```
### Rule 3.6.2 Place if, else, and else if keywords on separate lines.
If there are multiple branches in a conditional statement, they should be placed on separate lines.

Good example:

```cpp
if (someConditions) { 
    DoSomething();
    ...
} else {  // Good: Put the if and else keywords on separate lines.
    ...
}
```

Bad example:

```cpp
if (someConditions) { ... } else { ... } // Bad: The if and else keywords are put on the same line.
```

## Loop Statements
### Rule 3.7.1 Use braces after loop statements.
Similar to if statements, we require that the for and while loop statements contain braces, even if the loop body is empty or there is only one loop statement.
```cpp
for (int i = 0; i < someRange; i++) {   // Good: Braces are used.
    DoSomething();
}
```
```cpp
while (condition) {} // Good: The while loop body is empty. Braces should be used.
```
```cpp
while (condition) {
    continue; // Good: The continue keyword highlights the end of the empty loop. Braces should be used.
}
```

Bad example:
```cpp
for (int i = 0; i < someRange; i++)
    DoSomething();      // Bad: Braces are mandatory.
```
```cpp
while (someCondition) ; // Bad: Using a semicolon here will make people misunderstand that it is a part of the while statement and not the end to it.
```

## Switch Statements
### Rule 3.8.1 Indent case and default in a switch statement with four spaces.
The indentation style of the switch statement is as follows:
```cpp
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

```cpp
switch (var) {
case 0:                 // Bad: case is not indented.
    DoSomething();
    break;
default:                // Bad: default is not indented.
    break;
}
```

## Expressions

### Rec 3.9.1 Keep a consistent line break style for expressions and ensure that operators are placed at the end of a line.
A long expression that does not meet the line length requirement must be wrapped appropriately. 

Generally, the expression is wrapped at an operator of a lower priority or a connector, and the operator or connector is placed at the end of the line.

Placing these at the end of a line indicates that the operation is to be continued on the next line.
Example:

// Assume that the first line exceeds the length limit.
```cpp
if (currentValue > threshold &&  // Good: After the line break, the logical-AND operators are placed at the end of the line.
    someCondition) {
    DoSomething();
    ...
}

int result = reallyReallyLongVariableName1 +    // Good
             reallyReallyLongVariableName2;
```
After an expression is wrapped, ensure that the lines are aligned appropriately or indented with 4 spaces. See the following example.

```cpp
int sum = longVariableName1 + longVariableName2 + longVariableName3 +
    longVariableName4 + longVariableName5 + longVariableName6;         // Good: indented with 4 spaces

int sum = longVariableName1 + longVariableName2 + longVariableName3 +
          longVariableName4 + longVariableName5 + longVariableName6;   // Good: The lines are aligned.
```
## Variable Assignment

### Rule 3.10.1 Multiple variable definitions and assignment statements cannot be written on one line.
Each line should have only one variable initialization statement. It is easier to read and understand.

```cpp
int maxCount = 10;
bool isCompleted = false;
```

Bad example:

```cpp
int maxCount = 10; bool isCompleted = false; // Bad: Multiple variable initialization statements must be separated on different lines. Each variable initialization statement occupies one line.
int x, y = 0;  // Bad: Multiple variable definitions must be separated on different lines. Each definition occupies one line.

int pointX;
int pointY;
...
pointX = 1; pointY = 2;  // Bad: Multiple variable assignment statements must be separated on different lines.
```
Exception: Multiple variables can be declared and initialized in the for loop header, if initialization statement (C++17), and structured binding statement (C++17). Multiple variable declarations in these statements have strong associations. Forcible division into multiple lines may cause problems such as scope inconsistency and separation of declaration from initialization.

## Initialization
Initialization is applicable to structs, unions, and arrays.

### Rule 3.11.1 When an initialization list is wrapped, ensure that the line after the break is indented and aligned properly.
If a structure or array initialization list is wrapped, the line after the break is indented with four spaces.
Choose the wrap location and alignment style for best comprehension.

```cpp
const int rank[] = {
    16, 16, 16, 16, 32, 32, 32, 32,
    64, 64, 64, 64, 32, 32, 32, 32
};
```

## Pointers and References
### Rec 3.12.1 The pointer type `*` follows a variable name or type. There can be only one space to the side of it.
Pointer naming: There can be only one space next to `*`.
```cpp
int* p = NULL;  // Good
int *p = NULL;  // Good

int*p = NULL;   // Bad
int * p = NULL; // Bad
```

Exception: When a variable is modified by const or restrict, `*` cannot follow the variable or type.
```cpp
const char * const VERSION = "V100";
```

### Rec 3.12.2 The reference type `&` follows a variable name or type. There can be only one space to the side of it.
Reference naming: There can be only one space around `&`.
```cpp
int i = 8;

int& p = i;     // Good
int &p = i;     // Good
int*& rp = pi; // Good: The reference type `*&` follows the type.
int *&rp = pi; // Good: The reference type `*&` follows the variable name.
int* &rp = pi; // Good: The pointer type `*` follows the type and the reference type `&` follows the variable name.

int & p = i;    // Bad
int&p = i;      // Bad
```

## Compilation Preprocessing
### Rule 3.13.1 Place a number sign (#) at the beginning of a line for compilation preprocessing. In nested compilation preprocessing, the number sign (#) can be indented.
The number sign (#) must be placed at the beginning of a line for compilation preprocessing, even if the code is embedded in the function body.

### Rule 3.13.2 Do not use macros.
Macros do not obey scope, type system, and other rules, and may easily lead to issues. Avoid macro definitions wherever possible. If you must use macros, give them unique names.
In C++, there are many ways to avoid using macros:
- Use `const` or `enum` to define constants that are easy to understand.
- Use namespaces to avoid name conflicts.
- Use the `inline` function to avoid function call overhead.
- Use the `template` function to handle multiple types.
Macros can be used in scenarios such as header guards, conditional compilation, and logging.

### Rule 3.13.3 Do not use macros to represent constants.
Macros involve simple text replacement, which is completed during preprocessing. When an error occurs, the macro value is reported without the macro name. During tracing and debugging, the macro name is not displayed either. Besides, macros do not have type checking or scopes.

### Rule 3.13.4 Do not use function-like macros.
Before defining a function-like macro, consider whether it can be replaced with a function. If yes, you are advised to use a function for replacement.

The disadvantages of the function-like macro are as follows:

- Function-like macros have no type check, which is not as strict as the function call check.
- If macro parameters are not evaluated during macro expansion, unexpected results may occur.
- A macro has no independent scope.
- There are high skill requirements on the proper use of macros (for example, the usage of `#` and wide use of parentheses), which reduces readability.
- Extensions of some macros can only be implemented by specific compilers in specific scenarios, such as `statement expression` of `gcc`, reducing the portability.
- After the macro is expanded during precompilation, it is invisible during subsequent compilation, linking, and debugging. Besides, macros that contain multiple lines are expanded into a line. Function-like macros are difficult to debug, set breakpoints, and locate in case of bugs.
- Macros containing a large number of statements must be expanded at each call point. If there are many call points, the code will be expanded.

Unlike macros, functions do not have these disadvantages. However, the biggest disadvantage of functions is low execution efficiency (increasing the overhead of function calls and the difficulty of compiler optimization).

In light of this, you can use inline functions when necessary. Similar to macros, inline functions are expanded at the call point. The difference is that inline functions are expanded during compilation.

Inline functions have the advantages of both functions and macros:
- Strict type checking is performed for inline functions.
- Parameters are evaluated only once for inline functions.
- Inline functions are expanded in place and there is no overhead for function calls.
- Inline functions are better optimized than standard functions.
For performance-sensitive code, consider using inline functions instead of standard functions.

Exceptions:

In logging scenarios, only function-like macros can be used to keep information such as the file name (__FILE__) and line number (__LINE__) of the call point.

## Whitespace
### Rule 3.14.1 Ensure that horizontal spaces are used to highlight keywords and important information, and avoid unnecessary whitespace.
Horizontal spaces are used to highlight keywords and important information. Spaces are not allowed at the end of each code line. The general rules are as follows:

- Add spaces after keywords such as if, switch, case, do, while, and for.
- Do not add spaces after the left parenthesis or before the right parenthesis.
- For expressions enclosed by braces, either add a space on either side or avoid a space on either side.
- Do not add spaces after any unary operator (& * + - ~ !).
- Add a space to the left and right sides of each binary operator (= + -< > * /% | & ^ <= >= == !=).
- Add spaces to the left and right sides of a ternary operator (? :).
- Do not add spaces between a prefix or suffix increment (++) or decrement (--) operator and a variable.
- Do not add spaces before or after a struct member operator (. ->).
- Do not add spaces before commas. Add spaces after commas.
- Do not add spaces between a template or type conversion operator (<>) and a type.
- Do not add spaces before or after a domain operator (::).
- Determine whether to add spaces before and after a colon (:) based on the actual situation.

In normal cases:
```cpp
void Foo(int b) {  // Good: A space is added before the left brace.

int i = 0;  // Good: During variable initialization, there should be spaces before and after =. Do not leave a space before the semicolon.

int buf[BUF_SIZE] = {0}; // Good: Spaces are not added in braces.
```

Function definition and call:
```cpp
int result = Foo(arg1,arg2);
                    ^    // Bad: A space should be added after the comma.

int result = Foo( arg1, arg2 );
                 ^          ^  // Bad: Spaces should not be added after the left parenthesis or before the right parenthesis.
```

Pointer and Address Operator
```cpp
x = *p;     // Good: There is no space between the operator * and the pointer p.
p = &x;     // Good: There is no space between the operator & and the variable x.
x = r.y;    // Good: When a member variable is accessed through the operator (.), no space is added.
x = r->y;   // Good: When a member variable is accessed through the operator (->), no space is added.
```

Other Operators:
```cpp
x = 0;   // Good: There is a space before and after the assignment operator (=).
x = -5;  // Good: There is no space between the minus sign (–) and the number.
++x;     //Good: Do not add spaces between a prefix or suffix increment (++) or decrement (--) operator and a variable..
x--;

if (x && !y) // Good: There is a space before and after the Boolean operator. There is no space between the ! operator and the variable.
v = w * x + y / z;  // Good: There is a space before and after the binary operator.
v = w * (x + z);    // Good: There is no space before or after the expression in the parentheses.

int a = (x < y) ? x : y;  // Good: Ternary operator. There is a space before and after ? and :
```

Loops and Conditional Statements:
```cpp
if (condition) {  // Good: There is a space between the if keyword and the left parenthesis, and no space before or after the conditional statement in the parentheses.
    ...
} else {           // Good: There is a space between the else keyword and the left brace.
    ...
}

while (conditions) {}   // Good: There is a space between the while keyword and the left parenthesis. There is no space before or after the conditional statement in the parentheses.

for (int i = 0; i < someRange; ++i) {  // Good: There is a space between the for keyword and the left parenthesis, and after the semicolon.
    ...
}

switch (condition) {  // Good: There is a space after the switch keyword.
    case 0:     // Good: There is no space between the case condition and the colon.
        ...
        break;
    ...
    default:
        ...
        break;
}
```

Templates and Conversions
```cpp
// Angle brackets (< and >) are not adjacent to space. There is no space before < or between > and (.
vector<string> x;
y = static_cast<char*>(x);

// There can be a space between the type and the pointer operator. Keep the spacing style consistent.
vector<char *> x;
```

Scope Operators
```cpp
std::cout;    // Good: Namespace access. Do not leave spaces.

int MyClass::GetValue() const {}  // Good: Do not leave spaces in the definition of member functions.
```

Colons
```cpp
// Scenarios when space is required

// Good: // Add a space before or after the colon in a derived class definition.
class Sub : public Base {
    
};

// Add a space before or after the colon in the initialization list of a constructor function.
MyClass::MyClass(int var) : someVar_(var) 
{
    DoSomething();
}

// Add a space before or after the colon in a bit-field.
struct XX {
    char a : 4;     
    char b : 5;     
    char c : 4;
};
```

```cpp
// Scenarios when space is not required

// Good: // No space is added before or after the colon next to a class access permission (public or private).
class MyClass {
public:
    MyClass(int var);
private:
    int someVar_;
};

// No space is added before or after the colon in a switch statement.
switch (value)
{
    case 1:
        DoSomething();
        break;
    default:
        break;
}
```

Note: Currently, all IDEs support automatic deletion of spaces at the end of a line. Please configure your IDE correctly.

### Rec 3.14.1 Use blank lines only when necessary to keep code compact.

There must be as few blank lines as possible so that more code can be displayed for easy reading. Recommendations:
- Add blank lines according to the correlation between lines.
- Consecutive blank lines are not allowed inside functions, type definitions, macros, and initialization expressions.
- A maximum of **two** consecutive blank lines can be used. 
- Do not add blank lines on the first and last lines of a code block in braces. This recommendation is not applicable to code block in braces of a namespace.

```cpp
int Foo()
{
    ...
}



int bar() {// Bad: More than one blank lines are used between two function definitions.
{
    ...
}


if (...) {
        // Bad: Do not add blank lines on the first and last lines of a code block.
    ...
        // Bad: Do not add blank lines on the first and last lines of a code block. 
}

int Foo(...)
{
        // Bad: Do not add blank lines before the first statement in a function body.
    ...
}
```

## Classes
### Rule 3.15.1 Class access specifier declarations are in the sequence: public, protected, private. Indent these specifiers to the same level as the class keyword.
```cpp
class MyClass : public BaseClass {
public:      // Not indented.
    MyClass();  // Indented with 4 spaces.
    explicit MyClass(int var);
    ~MyClass() {}

    void SomeFunction();
    void SomeFunctionThatDoesNothing() 
    {
    }

    void SetVar(int var) { someVar_ = var; }
    int GetVar() const { return someVar_; }

private:
    bool SomeInternalFunction();

    int someVar_;
    int someOtherVar_;
};
```

In each part, it is recommended that similar statements be put together and in the following order: Type (including typedef, using, nested structs and classes), Constant, Factory Function, Constructor, Assignment Operator, Destructor, Other Member Function, and Data Member


### Rule 3.15.2 The constructor initialization list must be on the same line or wrapped and aligned with four spaces of indentation.
```cpp
// If all variables can be placed on the same line
MyClass::MyClass(int var) : someVar_(var) 
{
    DoSomething();
}

// If the variables cannot be placed on the same line
// Wrapped at the colon and indented with four spaces
MyClass::MyClass(int var)
    : someVar_(var), someOtherVar_(var + 1)  // Good: Add a space after the comma.
{
    DoSomething();
}

//  If an initialization list needs to be placed in multiple lines, put each member on a separate line and align between lines.
MyClass::MyClass(int var)
    someVar(var),             // Four spaces of indentation.
      someOtherVar_(var + 1) 
{  
    DoSomething();
}
```

# 4 Comments
Generally, clear architecture and good naming are recommended to improve code readability, and comments are provided only when necessary. 

Comments are used to help readers quickly understand code. Therefore, **comments should be provided for the sake of readers**.

Comments must be concise, clear, and unambiguous, ensuring that information is complete and not redundant.

**Comments are as important as code**. 

When writing a comment, you need to step into the reader's shoes and use comments to express what the reader really needs. Comments are used to express the function and intention of code, rather than repeating code.

When modifying the code, ensure that the comments are consistent with the modified code. It is not polite to modify only code and keep the old comments, which will undermine the consistency between code and comments, and may confuse or even mislead readers.

Comments should be made in English.  

## Comment Style

In C++ code, both ` /* */` and ` // ` can be used for commenting. 

Comments can be classified into different types, such as file header comments, function header comments, and code comments. This is based on their purposes and positions. 

Comments of the same type must keep a consistent style.

Note: Example code in this document uses comments in the `//` format only to better describe the rules and recommendations. This does not mean this comment format is better.

## File Header Comments
### Rule 4.2.1 File header comments must contain the copyright notice.

/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
    *
 * http://www.apache.org/licenses/LICENSE-2.0
    *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
    */

## Function Header Comments
### Rule 4.3.1 Write function header comments for public functions.
Public functions are interfaces provided by classes for external systems. To use public functions, the caller must understand the functionalities, parameter value ranges, return values, and precautions of the functions.
Write function header comments for the function value range, return value, and precautions, since they cannot be self-explained.

### Rule 4.3.2 Function header comments with no content are forbidden.
Not all functions need function header comments.

For information that cannot be described by function signatures, add function header comments.

Function header comments are placed above the function declaration or definition. Use one of the following styles:

Use '//' to start the function header.

```cpp
// Single-line function header
int Func1(void);

// Multi-line function header
// Second line
int Func2(void);
```

Use `/*   */` to start the function header.
```cpp
/* Single-line function header */
int Func1(void);

/*
 * Another single-line function header
 */
int Func2(void);

/*
 * Multi-line function header
 * Second line
 */
int Func3(void);
```
Use function names to describe functions, and add function header comments if necessary.

Do not write useless or redundant function headers. Do not write empty function headers with no content.

The function header comment content will depend on the function and includes but is not limited to: a function description, return value, performance constraints, usage comments, memory conventions, algorithm implementation, reentering requirements.

In the function interface declaration in the external header file, the function header comment should clearly describe important and useful information.

Good example:

```cpp
/*
 * The number of written bytes is returned. If -1 is returned, the write operation failed.
 * Note that the memory buffer should be released by the caller.
 */
int WriteString(const char *buf, int len);
```

Bad example:
```cpp
/*
 * Function name: WriteString
 * Function: Write a character string.
 * Parameters:
 * Return value:
 */
int WriteString(const char *buf, int len);
```
Problems:

- The 'Parameters' and 'Return value' have no content. 
- The function name is redundant.
- The most import thing, that is, who needs to release the buffer, is not clearly stated.

## Code Comments
### Rule 4.4.1 Code comments are placed above or on the right of the corresponding code.
### Rule 4.4.2 There must be a space between the comment character and the comment content. At least one space is required between the comment and code if the comment is placed to the right of code.
Comments placed above code should be indented the same as that of the code.
Use one of the following styles:
Use "//".
```cpp

// Single-line comment
DoSomething();

// Multi-line comment
// Second line
DoSomething();
```

Use `/* */`.
```cpp
/* Single-line comment */
DoSomething();

/*
 * Multi-line comment in another mode
 * Second line
 */
DoSomething();
```
Leave at least one space between the code and the comment on the right. It is recommended that no more than four spaces be left.

You can use the Tab key to indent 1–4 spaces.

Select and use one of the following styles:

```cpp
int foo = 100;  // Comment on the right
int bar = 200;  /* Comment on the right */
```
It is more appealing sometimes when the comment is placed on the right of code and the comments and code are aligned vertically.

After the alignment, ensure that the comment is 1–4 spaces away from the widest line of code.
Example:

```cpp
const int A_CONST = 100;         /* Related comments of the same type can be aligned vertically. */
const int ANOTHER_CONST = 200;   /* Leave spaces after code to align comments vertically. */
```
When the comment on the right exceeds the line width, consider placing the comment above the code.

### Rule 4.4.3 Delete unused code segments. Do not comment them out.
Code that is commented out cannot be maintained. If you attempt to restore the code, it is very likely to introduce ignorable defects.

The correct method is to delete unnecessary code directly. If necessary, consider porting or rewriting the code.

Here, commenting out refers to the removal of code from compilation without actually deleting it. This is done by using /* */, //, #if 0, #ifdef NEVER_DEFINED, and so on.

# 5 Header Files
## Header File Responsibility
A header file is an external interface of a module or file. The design of a header file shows most of the system design.

The interface declaration for most functions is more suitable placed in the header file, but implementation (except inline functions) cannot be placed in the header file. Functions, macros, enumerations, and structure definitions that need to be used in .cpp files cannot be placed in the header file.

The header responsibility should be simple. An overly complex header file will make dependencies complex and cause long compilation times.

### Rec 5.1.1 Each .cpp file should have a .h file with the same name. It should be used to declare the classes and interfaces that need to be exposed externally.
Generally, each .cpp file has a corresponding .h file. This .cpp file is used to store the function declarations, macro definitions, and class definitions that are to be exposed.

If a .cpp file does not need to open any interface externally, it should not exist.

Exception: __An entry point (for example, the file where the main function is located), unit tests, and dynamic libraries __

Example:
```cpp
// Foo.h 

#ifndef FOO_H
#define FOO_H

class Foo {
public:
    Foo();
    void Fun();
    
private:
    int value_;
};

#endif
```

```cpp
// Foo.cpp
#include "Foo.h"

namespace { // Good: The declaration of the internal function is placed in the header of the .cpp file, and has been limited to the unnamed namespace or static scope.
    void Bar()
    {
    }
}

...

void Foo::Fun()
{
    Bar();
}
```

## Header File Dependency
### Rule 5.2.1 Header file cyclic dependency is forbidden.
An example of cyclic dependency (also known as circular dependency) is: a.h contains b.h, b.h contains c.h, and c.h contains a.h. If any of these header files is modified, all code containing a.h, b.h, and c.h needs to be recompiled.  

For a unidirectional dependency, for example if: a.h contains b.h, b.h contains c.h, and c.h does not contain any header file, modifying a.h does not mean that we need to recompile the source code for b.h or c.h.

The cyclic dependency of header files reflects an obviously unreasonable architecture design, which can be avoided through optimization.


### Rule 5.2.2 Header files should have #define guards to prevent multiple inclusion.
To prevent header files from being included multiple times, all header files should be protected by #define. Do not use #pragma once.

When defining a protection character, comply with the following rules:

1) The protection character uses a unique name.

2) Do not place code or comments (except for file header comments) before or after the protected part.

Example: Assume that the timer.h file of the timer module is in the timer/include/timer.h directory. Perform the following operations to safeguard the timer.h file:

```cpp
#ifndef TIMER_INCLUDE_TIMER_H
#define TIMER_INCLUDE_TIMER_H
...
#endif
```

### Rule 5.2.3 It is prohibited to reference external function interfaces and variables in extern declaration mode.
Interfaces provided by other modules or files can be used only by including header files.

Using external function interfaces and variables in extern declaration mode may cause inconsistency between declarations and definitions when external interfaces are changed.

In addition, this kind of implicit dependency may cause architecture corruption.

Cases that do not comply with specifications:

// a.cpp content
```cpp
extern int Fun();   // Bad: Use external functions in extern mode.

void Bar() 
{
    int i = Fun();
    ...
}
```

// b.cpp content
```cpp
int Fun() 
{
    // Do something
}
```
Should be changed to:

// a.cpp content
```cpp
#include "b.h"   // Good: Use the interface provided by other .cpp by including its corresponding header file.

void Bar() 
{
    int i = Fun();
    ...
}
```

// b.h content
```cpp
int Fun();
```

// b.cpp content
```cpp
int Fun() 
{
    // Do something
}
```
In some scenarios, if internal functions need to be referenced with no intrusion to the code, the extern declaration mode can be used.

Example:

When performing unit testing on an internal function, you can use the extern declaration to reference the tested function.

When a function needs to be stubbed or patched, the function can be declared using extern.

### Rule 5.2.4 Do not include header files in extern "C".
If a header file is included in extern "C", extern "C" may be nested. Some compilers restrict the nesting of extern "C". If there are too many nested layers, compilation errors may occur.

When C and C++ programmings are used together and if extern "C" includes a header file, the original intent behind the header file may be hindered. For example, when the link specifications are modified incorrectly.

For example, assume that there are two header files a.h and b.h.

// a.h content
```cpp
...
#ifdef __cplusplus
void Foo(int);
#define A(value) Foo(value)
#else
void A(int)
#endif
```
// b.h content
```cpp
...
#ifdef __cplusplus
extern "C" {
#endif

#include "a.h"
void B();

#ifdef __cplusplus
}
#endif
```

Using the C++ preprocessor to expand b.h, the following information is displayed:
```cpp
extern "C" {
    void Foo(int);
    void B();
}
```

According to the author of a.h, the function Foo is a C++ free function following the "C++" link specification.
However, because `#include "a.h"` is placed inside `extern "C"` in b.h, the link specification of function Foo is changed incorrectly.

Exceptions:
In the C++ compilation environment, if you want to reference the header file of pure C, the C header files should not contain `extern "C"`. The non-intrusive approach is to include the C header file in `extern "C"`.

### Rec 5.2.1 Use `#include` instead of a forward declaration to include header files.
A forward declaration is for the declaration of classes, functions, and templates and is not meant for its definition.

- Advantages:
  1. Forward declarations can save compilation time. Redundant `#include `statements force the compiler to expand more files and process more input.
  2. Forward declarations can save unnecessary recompilation time. The use of #include will force your code to be recompiled multiple times due to unrelated changes in header files.
- Disadvantages:
  1. Forward declarations hide dependency relationship. When a header file is modified, user code will skip the necessary recompilation process.
  2. A forward declaration may be broken by subsequent changes to the library. Forward declarations of functions and templates sometimes prevent header file developers from changing APIs. For example, widening a formal parameter type, adding a template parameter with a default value, and so on.
  3. Forward declaration of symbols from the namespace `std::` is seen as undefined behavior (as specified in the C++ 11 standard specification).
  4. Forward declaration of multiple symbols from a header file can be more verbose than simply including (#include) the header.
  5. Structuring code only for forward declaration (for example, using pointer members instead of object members) can make the code more complex and slower.
  6. It is difficult to determine whether a forward declaration or `#include` is needed. In some scenarios, replacing `#include` with a forward declaration may cause unexpected results.

Therefore, we should avoid using forward declarations as much as possible. Instead, we use the #include statement to include a header file and ensure dependency.

# 6 Scopes

## Namespaces

### Rec 6.1.1 For code that does not need to be exported from the .cpp file, you are advised to use an unnamed namespace for encapsulation or use static to modify the variables, constants, or functions that need hiding.
In the C++ 2003 standard, using static to modify the external availability of functions and variables was marked as deprecated. Therefore, unnamed namespaces are the recommended method.

Main Reasons:
1. There are too many meanings for static in C++: static function member variable, static member function, static global variable, and static function local variable. Each of them has special processing.
2. Static can only be used to define variables, constants, and functions that are not referenced outside the current .cpp file, while namespaces can also be used to encapsulate types.
3. Use a namespace to control the scope instead of using both static and namespaces.
4. Unnamed namespaces can be used to instantiate templates rather than functions modified by the static keyword.

Do not use unnamed namespaces or static in header files.

```cpp
// Foo.cpp

namespace {
    const int MAX_COUNT = 20;
    void InternalFun(){};
}

void Foo::Fun()
{
    int i = MAX_COUNT;
    
    InternalFun();
}

```

### Rule 6.1.1 Do not use "using" to import namespace in a header file or before #include statements.
Note: Using "using" to import namespace will affect any subsequent code and may cause symbol conflicts. 
Example:

```cpp
// Header file a.h
namespace NamespaceA {
    int Fun(int);
}
```

```cpp
// Header file b.h
namespace NamespaceB {
    int Fun(int);
}

using namespace NamespaceB;

void G()
{
    Fun(1); 
}
```

```cpp
// Source code a.cpp
#include "a.h"
using namespace NamespaceA; 
#include "b.h"

void main()
{
    G(); // "using namespace NamespaceA" before #include "b.h", will cause conflicts when calling NamespaceA::Fun and NamespaceB::Fun.
}
```

Using "using" to import a symbol or define an alias in a header file is allowed in customized namespaces of modules, but is prohibited in the global namespace.
```cpp
// foo.h

#include <fancy/string>
using fancy::string;  // Bad: It is prohibited to import symbols to the global namespace.

namespace Foo {
    using fancy::string;  // Good: Symbols can be imported in customized namespaces of modules.
    using MyVector = fancy::vector;  // Good: In C++11, aliases can be defined in customized namespaces.
}
```


## Global Functions and Static Member Functions

### Rec 6.2.1 Use namespaces to manage global functions. If global functions are closely tied to a class, you can use static member functions.
Note: Placing non-member functions in a namespace avoids polluting the global scope. Do not use "class + static member function" to simply manage global functions. If a global function is closely tied to a class, it can be used as a static member function of the class.

If you need to define some global functions for a .cpp file, use unnamed namespaces for management.
```cpp
namespace MyNamespace {
    int Add(int a, int b);
}

class File {
public:
    static File CreateTempFile(const std::string& fileName);
};
```

## Global Constants and Static Member Constants

### Rec 6.3.1 Use namespaces to manage global constants. If global constants are closely tied to a class, you can use static member constants.
Note: Placing global constants in a namespace avoids polluting the global scope. Do not use "class + static member constant" to simply manage global constants. If a global constant is closely tied to a class, it can be used as a static member constant of the class.

If you need to define some global constants only for a .cpp file, use unnamed namespaces for management.
```cpp
namespace MyNamespace {
    const int MAX_SIZE = 100;
}

class File {
public:
    static const std::string SEPARATOR;
};
```

## Global Variables

### Rec 6.4.1 Do not use global variables. Use the singleton pattern instead.
Note: Global variables can be modified and read, which results in data coupling between production code and the global variables.
```cpp
int g_counter = 0;

// a.cpp
g_counter++;

// b.cpp
g_counter++;

// c.cpp
cout << g_counter << endl;
```

Singleton
```cpp
class Counter {
public:
    static Counter& GetInstance()
    {
        static Counter counter;
        return counter;
    }  // Simple example of a singleton implementation
    
    void Increase() 
    {
        value_++;
    }
    
    void Print() const
    {
        std::cout << value_ << std::endl;
    }

private:
    Counter() : value_(0) {}

private:
    int value_;
};

// a.cpp
Counter::GetInstance().Increase();

// b.cpp
Counter::GetInstance().Increase();

// c.cpp
Counter::GetInstance().Print();
```

After the singleton is implemented, there is a unique global instance, which can functions as a global variable. However, the singleton provides better encapsulation.

Exception: In some cases, the scope of a global variable is contained inside a module. Multiple instances of the same global variable may exist, and each module holds one copy. In this case, a singleton cannot be used as it is limited to one instance.

# 7 Classes

## Constructors, Copy/Move Constructors, Copy/Move Assignment Operators, and Destructors
Constructors, copy/move constructors, copy/move assignment operators, and destructors provide lifetime management methods for objects.
- Constructor: `X()`
- Copy constructor: `X(const X&)`
- Copy assignment operator: `operator=(const X&)`   
- Move constructor: `X (X&&)`         *Provided in versions later than C++ 11*.
- Move assignment operator: `operator=(X&&)`       *Provided in versions later than C++ 11*.
- Destructor: `~X()`

### Rule 7.1.1 The member variables of a class must be initialized explicitly.
Note: If a class has members but no constructor and a default constructor is defined, the compiler will automatically generate a constructor, but it will not initialize member variables. The content of each object is uncertain.

Exceptions:
- If the member variables in a class have a default constructor, explicit initialization is not required.

Example: The following code has no constructor, and private data members cannot be initialized:
```cpp
class Message {
public:
    void ProcessOutMsg()
    {
        //...
    }

private:
    unsigned int msgID_;
    unsigned int msgLength_;
    unsigned char* msgBuffer_;
    std::string someIdentifier_;
};

Message message;   // The message member is not initialized.
message.ProcessOutMsg();   // Potential risks exist in subsequent use.

// Therefore, it is necessary to define a default constructor as follows:
class Message {
public:
    Message() : msgID_(0), msgLength_(0), msgBuffer_(NULL)
    {
    }

    void ProcessOutMsg()
    {
        // ...
    }

private:
    unsigned int msgID_;
    unsigned int msgLength_;
    unsigned char* msgBuffer_;
    std::string someIdentifier; // The member variable has a default constructor. Therefore, explicit initialization is not required.
};
```

### Rec 7.1.1 Initialization during declaration (C++ 11) and initialization using the constructor initialization list are preferred for member variables.
Note: Initialization during declaration (C++11) is preferred because initialized values of member variables can be easily understood. If initialized values of certain member variables are relevant to constructors, or C++ 11 is not supported, the constructor initialization list is used preferentially to initialize these member variables. Compared with the assignment statements in constructors, code of the constructor initialization list is simpler and has higher performance, and can be used to initialize constant and reference members.

```cpp
class Message {
public:
    Message() : msgLength(0) {  // Good: The constructor initialization list is preferred.
    {
        msgBuffer = NULL;     // Bad: Values cannot be assigned in constructors.
    }
    
private:
    unsigned int msgID{0};  // Good: Used in C++11.
    unsigned int msgLength_;
    unsigned char* msgBuffer_;
};
```

### Rule 7.1.2 Declare single-parameter constructors as explicit to prevent implicit conversion.
Note: If a single-parameter constructor is not declared as explicit, it will become an implicit conversion function.
Example:

```cpp
class Foo {
public:
    explicit Foo(const string& name): name_(name)
    {
    }
private:
    string name_;
};


void ProcessFoo(const Foo& foo){}

int main(void)
{
    std::string test = "test";
    ProcessFoo(test);  // Compiling failed.
    return 0;
}
```

The preceding code fails to be compiled because the parameter required by `ProcessFoo` is of the Foo type, which mismatch with the input string type.

If the explicit keyword of the Foo constructor is removed, implicit conversion is triggered and a temporary Foo object is generated when `ProcessFoo` is called with the string parameter. Usually, this implicit conversion is confusing and bugs are apt to be hidden, due to unexpected type conversion. Therefore, single-parameter constructors require explicit declaration.

### Rule 7.1.3 If copy/move constructors and copy/move assignment operators are not needed, clearly prohibit them.
Note: If users do not define it, the compiler will generate copy constructors and copy assignment operators, move constructors and move assignment operators (move semantic functions will be available in versions later than C++ 11).
If we do not use copy constructors or copy assignment operators, explicitly delete them.

1. Set copy constructors or copy assignment operators to private and do not implement them.
```cpp
class Foo {
private:
    Foo(const Foo&);
    Foo& operator=(const Foo&);
};
```
2. Use delete provided by C++ 11. For details, see Rule 10.1.3 in chapter 10 Modern C++ Features.


3. You are advised to inherit **NoCopyable** and **NoMovable**. Do not use macros such as **DISALLOW_COPY_AND_MOVE**, **DISALLOW_COPY**, and **DISALLOW_MOVE**.
```cpp
class Foo : public NoCopyable, public NoMovable {
};
```
Implementation of NoCopyable and NoMovable:
```cpp
class NoCopyable {
public:
    NoCopyable() = default;
    NoCopyable(const NoCopyable&) = delete;
    NoCopyable& operator = (NoCopyable&) = delete;
};

class NoMovable {
public:
    NoMovable() = default;
    NoMovable(NoMovable&&) noexcept = delete;
    NoMovable& operator = (NoMovable&&) noexcept = delete;
};
```

### Rule 7.1.4 Copy constructors and copy assignment operators should be implemented or forbidden together.
Both copy constructors and copy assignment operators provide copy semantics. They should be implemented or hidden together.

```cpp
// The copy constructor and the copy assignment operator are implemented together.
class Foo {
public:
    ...
    Foo(const Foo&);
    Foo& operator=(const Foo&);
    ...
};

// The copy constructor and the copy assignment operator are both set to default, as supported by C++ 11.
class Foo {
public:
    Foo(const Foo&) = default;
    Foo& operator=(const Foo&) = default;
};

// The copy constructor and the copy assignment operator are hidden together. You should use the delete keyword if C++11 features are available.
class Foo {
private:
    Foo(const Foo&);
    Foo& operator=(const Foo&);
};
```

### Rule 7.1.5 Move constructors and move assignment operators should be implemented or hidden together.
The move operation is added in C++ 11. If a class is required to support the move operation, move constructors and move assignment operators need to be implemented.

Both move constructors and move assignment operators provide move semantics. They should be implemented or hidden together.
```cpp
// The copy constructor and the copy assignment operator are implemented together.
class Foo {
public:
    ...
    Foo(Foo&&);
    Foo& operator=(Foo&&);
    ...
};

// The copy constructor and the copy assignment operator are both set to default, as supported by C++ 11.
class Foo {
public:
    Foo(Foo&&) = default;
    Foo& operator=(Foo&&) = default;
};

// The copy constructor and the copy assignment operator are hidden together. You should use the delete keyword if C++11 features are available.
class Foo {
public:
    Foo(Foo&&) = delete;
    Foo& operator=(Foo&&) = delete;
};
```

### Rule 7.1.6 It is prohibited to call virtual functions in constructors and destructors.
Note: Calling a virtual function of the current object in a constructor or destructor will cause behaviors of non-polymorphism.

In C++, a base class constructs only one complete object at a time.

Example: Base indicates the base class, and Sub indicates the derived class.
```cpp
class Base {                       
public:                
    Base();
    virtual void Log() = 0;    // Different derived classes call different log files.
};

Base::Base()         // Base class constructor
{
    Log();           // Call the virtual function log.
}                                                  

class Sub : public Base {       
public:
    virtual void Log();          
};
```

When running the following statement:

`Sub sub;`

The constructor of the derived class is executed first. However, the constructor of the base class is called first. Because the constructor of the base class calls the virtual function log, the log is in the base class version. The derived class is constructed only after the base class is constructed. As a result, behaviors of non-polymorphism are caused.

This also applies to destructors.

### Rule 7.1.7 The copy constructors, copy assignment operators, move constructors, and move assignment operators in polymorphic base classes must be non-public or delete functions.
Slicing occurs if the value of a derived class object is directly assigned to a base class object. In this case, only the base class part is copied or moved, which undermines polymorphism.

[Counterexample]

In the following code example, the copy constructor and copy assignment operator are not defined in the base class. The compiler automatically generates two special member functions.

If the value of a derived class object is assigned to the base class object, slicing occurs. The copy constructor and copy assignment operator can be declared as **deleted** so that the compiler can check such assignment behavior.

```cpp
class Base {                       
public:                
    Base() = default;
    virtual ~Base() = default;
    ...
    virtual void Fun() { std::cout << "Base" << std::endl;}
};

class Derived : public Base {
    ...
    void Fun() override { std::cout << "Derived" << std::endl; }
};

void Foo(const Base &base)
{
    Base other = base; // Bad: Slicing occurs
    other.Fun(); // The Fun() function of the base class is called.
}
```
```cpp
Derived d;
Foo(d); // A derived class object is passed.
```
Set copy constructors or copy assignment operators to **private** and do not implement them.

## Inheritance

### Rule 7.2.1 Declare destructors of a base class as virtual, and declare the class that is not to be inherited as final.
Note: Destructors of the derived class can be called during polymorphism invocation only when destructors of the base class are virtual.

Example: There will be memory leak if destructors of the base class are not declared as virtual.
```cpp
class Base {
public:
    virtual std::string getVersion() = 0;
    
    ~Base() 
    {
        std::cout << "~Base" << std::endl;
    }
};
```

```cpp
class Sub : public Base {
public:
    Sub() : numbers_(NULL)
    {  
    }
    
    ~Sub()
    {
        delete[] numbers_;
        std::cout << "~Sub" << std::endl;
    }
    
    int Init()
    {
        const size_t numberCount = 100;
        numbers_ = new (std::nothrow) int[numberCount];
        if (numbers_ == NULL) {
            return -1;
        }
        
        ...
    }

    std::string getVersion() 
    { 
        return std::string("hello!");
    }
private:
    int* numbers_;
};
```

```cpp
int main(int argc, char* args[])
{
    Base* b = new Sub();

    delete b;
    return 0;
}
```
Because destructors of the base class are not declared as virtual, only destructors of the base class are called when an object is destroyed. Destructors of the derived class Sub are not called. As a result, a memory leak occurs.

Exceptions:

For classes such as **NoCopyable** and **NoMovable** that have no behavior and are used only as identifiers, you do not need to define them as final.

### Rule 7.2.2 Do not use default parameter values for virtual functions.
Note: In C++, virtual functions are dynamically bound, but the default parameters of functions are statically bound during compilation. This means that the function you finally execute is a virtual function that is defined in the derived class but uses the default parameter value in the base class. To avoid confusion and other problems caused by inconsistent default parameter declarations during overriding of virtual functions, it is prohibited to declare default parameter values for all virtual functions.

Example: The default value of parameter "text" of the virtual function "Display" is determined at compilation time instead of runtime, which does not fit with polymorphism.

```cpp
class Base {
public:
    virtual void Display(const std::string& text = "Base!")
    {
        std::cout << text << std::endl;
    }
    
    virtual ~Base(){}
};

class Sub : public Base {
public:
    virtual void Display(const std::string& text  = "Sub!")
    {
        std::cout << text << std::endl; 
    }
    
    virtual ~Sub(){}
};

int main()
{
    Base* base = new Sub();
    Sub* sub = new Sub();
   
    ...
    
    base->Display();  // The program output is as follows: Base! The expected output is as follows: Sub!
    sub->Display();   // The program output is as follows: Sub!
    
    delete base;
    delete sub;
    return 0;
};
```

### Rule 7.2.3 Do not redefine inherited non-virtual functions.
Note: Non-virtual functions cannot be dynamically bound (only virtual functions can be dynamically bound). You can obtain the correct result by operating on the pointer of the base class.

Example:
```cpp
class Base {
public:
    void Fun();
};

class Sub : public Base { 
public:
    void Fun();
};

Sub* sub = new Sub();                     
Base* base = sub;

sub->Fun();    // Call Fun of the derived class.                  
base->Fun();   // Call Fun of the base class.
//...

```

## Multiple Inheritance
In the actual development process, multiple inheritance is seldom used because the following typical problems may occur:
1. Data duplication and name ambiguity caused by "diamond" inheritance. C++ introduces virtual inheritance to solve these problems.
2. In addition to "diamond" inheritance, names of multiple base classes may also conflict with each other, resulting in name ambiguity.
3. If a derived class needs to be extended or needs to override methods of multiple base classes, the responsibilities of the derived classes are unclear and semantics are muddled.
4. Compared with delegation, inheritance is seen as white box reuse, that is, a derived class can access the protected members of the base class, which leads to more coupling. Multiple inheritance, due to the coupling of multiple base classes, leads to even more coupling.

Multiple inheritance has the following advantages:
Multiple inheritance provides a simpler method for assembling and reusing multiple interfaces or classes.

Therefore, multiple inheritance can be used only in the following cases:

### Rec 7.3.1 Use multi-inheritance to implement interface separation and multi-role combination.
If a class requires multiple interfaces, combine multiple separated interfaces by using multiple inheritance. This is similar to the Traits mixin of the Scala language.

```cpp
class Role1 {};
class Role2 {};
class Role3 {};

class Object1 : public Role1, public Role2 {
    // ...
};

class Object2 : public Role2, public Role3 {
    // ...
};

```

The C++ standard library has a similar implementation example:
```cpp
class basic_istream {};
class basic_ostream {};

class basic_iostream : public basic_istream, public basic_ostream {
  
};
```

## Overloading

Overload operators should be used when there are sufficient reasons, and they do not change the original perception of the operators. For example, do not use the plus sign (+) to perform subtraction.
Operator overloading can make code more intuitive but has some disadvantages:
- It is often mistaken that the operation is as fast as a built-in operator, which has no performance degradation.
- There is no naming to aid debugging. It is more convenient to search by function name than by operator.
- Overloading operators can cause confusion if behavior definitions are not intuitive (for example, if the "+" operator is used for subtraction).
- The implicit conversion caused by the overloading of assignment operators may lead to entrenched bugs. Functions such as Equals () and CopyFrom () can be defined to replace the = and == operators.

# 8 Functions
## Function Design
### Rule 8.1.1 Avoid long functions and ensure that each function contains no more than 50 lines (non-null and non-comment).
A function should be displayed on one screen (no longer than 50 lines). It should do only one thing, and do it well.

Long functions often mean that the functions are too complex to implement in more than one function, or overly detailed but not further abstracted.

Exception: Some algorithms may be longer than 50 lines due to algorithm convergence and functional comprehensiveness.

Even if a long function works very well now, once someone modifies it, new problems may occur. It might even cause bugs that are difficult to find.

It is recommended that you split a long function into several functions that are simpler and easier to manage, facilitating comprehension and modification.

## Inline Functions

###  Rec 8.2.1 An inline function cannot exceed 10 lines.
**Note**: An inline function has the same characteristics of a normal function. The difference between an inline function and a normal function lies in the processing of function calls. When a general function is called, the program execution right is transferred to the called function, and then returned to the function that calls it. When an inline function is called, the invocation expression is replaced with an inline function body.

Inline functions are only suitable for small functions with only 1-10 lines. For a large function that contains many statements, the function call and return overheads are relatively trivial and do not need the help of an inline function. Most compilers may abandon the inline mode and use the common method to call the function.

If an inline function contains complex control structures, such as loop, branch (switch), and try-catch statements, the compiler may regard the function as a common function.
**Virtual functions and recursive functions cannot be used as inline functions**.

## Function Parameters

### Rec 8.3.1 Use a reference instead of a pointer for function parameters.

**Note**: A reference is more secure than a pointer because it is not empty and does not point to other targets. Using a reference stops the need to check for illegal null pointers.

If a product is being developed for an older platform, the processing used by the old platform is preferred.
Use const to avoid parameter modification, so that readers can clearly know that a parameter is not going to be modified. This greatly enhances code readability.

Exception: When the input parameter is an array with an unknown compile-time length, you can use a pointer instead of a reference.

### Rec 8.3.2 Use strongly typed parameters. Do not use void*.
While different languages have their own views on strong typing and weak typing, it is generally believed that C and C++ are strongly typed languages. Since we use such a strongly typed language, we should keep to this style.

An advantage of this is the compiler can find type mismatch problems at the compilation stage.

Using strong typing helps the compiler find more errors for us. Pay attention to the usage of the FooListAddNode function in the following code:
```cpp
struct FooNode {
    struct List link;
    int foo;
};

struct BarNode {
    struct List link;
    int bar;
}

void FooListAddNode(void *node) // Bad: Here, the void * type is used to transfer parameters.
{
    FooNode *foo = (FooNode *)node;
    ListAppend(&g_FooList, &foo->link);
}

void MakeTheList()
{
    FooNode *foo = NULL;
    BarNode *bar = NULL;
    ...

    FooListAddNode(bar);        // Wrong: In this example, the foo parameter was supposed to be transferred, but the bar parameter is accidentally transferred instead. However, no error is reported.
}
```

1. You can use a template function to change the parameter type.
2. A base class pointer can be used to implement this according to polymorphism.

### Rec 8.3.3 A function can have a maximum of five parameters.
If a function has too many parameters, it is apt to be affected by external changes, and therefore maintenance is affected. Too many function parameters will also increase the testing workload.

If a function has more than five parameters, you can:
- Split the function.
- Combine related parameters into a struct.

# 9 Other C++ Features

## Constants and Initialization

Unchanged values are easier to understand, trace, and analyze. Therefore, use constants instead of variables as much as possible. When defining values, use const as a default.

### Rule 9.1.1 Do not use macros to replace constants.

**Note**: Macros are a simple text replacement that is completed in the preprocessing phase. When an error is reported, the corresponding value is reported. During tracing and debugging, the value is also displayed instead of the macro name. A macro does not support type checking and is insecure. A macro has no scope.

```cpp
#define MAX_MSISDN_LEN 20    // Bad

// Use const in C++.
const int MAX_MSISDN_LEN = 20; // Good

// In versions later than C++ 11, constexpr can be used.
constexpr int MAX_MSISDN_LEN = 20;
```

###  Rec 9.1.1 A group of related integer constants must be defined as an enumeration.

**Note**: Enumerations are more secure than `#define` or `const int`. The compiler checks whether a parameter value is within the enumerated value range to avoid errors.

```cpp
// Good example:
enum Week {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum Color {
    RED,
    BLACK,
    BLUE
};

void ColorizeCalendar(Week today, Color color);

ColorizeCalendar(BLUE, SUNDAY); // Compilation error. The parameter type is incorrect.

// Bad example:
const int SUNDAY = 0;
const int MONDAY = 1;

const int BLACK  = 0;
const int BLUE   = 1;

bool ColorizeCalendar(int today, int color);
ColorizeCalendar(BLUE, SUNDAY); // No error is reported.
```

When an enumeration value needs to correspond to a specific value, explicit value assignment is required during declaration. Otherwise, do not assign explicit values. This will prevent repeated assignment and reduce the maintenance workload (when adding and deleting members).

```cpp
// Good example: Device ID defined in the S protocol. It is used to identify a device type.
enum DeviceType {
    DEV_UNKNOWN = -1,
    DEV_DSMP = 0,
    DEV_ISMG = 1,
    DEV_WAPPORTAL = 2
};
```

Do not assign explicit values when enumeration is used internally, and only for classification.

```cpp
// Good example: Enumeration definition is used to identify session status in a program.
enum SessionState {
    INIT,
    CLOSED,
    WAITING_FOR_RESPONSE
};
```

Try to avoid repeating enumeration values. If it is required, use the already defined enumeration values instead.

```cpp
enum RTCPType {
    RTCP_SR = 200,
    RTCP_MIN_TYPE = RTCP_SR,        
    RTCP_RR    = 201,
    RTCP_SDES  = 202,
    RTCP_BYE   = 203,
    RTCP_APP   = 204,
    RTCP_RTPFB = 205,
    RTCP_PSFB  = 206,
    RTCP_XR  = 207,
    RTCP_RSI = 208,
    RTCP_PUBPORTS = 209,
    RTCP_MAX_TYPE = RTCP_PUBPORTS  
};
```

### Rule 9.1.2 Magic numbers cannot be used.
So-called magic numbers are numbers that are unintelligible and difficult to understand.

Some numbers can be understood based on context.

For example, the number 12 varies in different contexts.

type = 12; is not intelligible (and a magic number), but `month = year * 12`; can be understood, so we wouldn't really class this as a magic number.

The number 0 is often seen as a magic number. For example, `status = 0`; cannot truly express any status information.

Solution:

Comments can be added for numbers that are used locally.

For the numbers that are used multiple times, you must define them as constants and give them descriptive names.

The following cases are forbidden:

No symbol is used to explain the meaning of a number, for example, ` const int ZERO = 0`.
The symbol name limits the value. For example, for example, `const int XX_TIMER_INTERVAL_300MS = 300`. Use `XX_TIMER_INTERVAL_MS` instead.

### Rule 9.1.3 Ensure that a constant has only one responsibility.

**Note**: A constant is used for only one specific function, that is, a constant cannot be used for multiple purposes.

```cpp
// Good example: For protocol A and protocol B, the length of the MSISDN is 20.
const unsigned int A_MAX_MSISDN_LEN = 20;
const unsigned int B_MAX_MSISDN_LEN = 20;

// Using different namespaces:
namespace Namespace1 {
    const unsigned int MAX_MSISDN_LEN = 20;
}

namespace Namespace2 {
    const unsigned int MAX_MSISDN_LEN = 20;
}
```

### Rule 9.1.4 Do not use memcpy_s or memset_s to initialize non-POD objects.

**Note**: `POD` is short for `Plain Old Data`, which is a concept introduced in the C++ 98 standard (ISO/IEC 14882, first edition, 1998-09-01). The `POD` types include the original types and aggregate types such as `int`, `char`, `float`, `double`, `enumeration`, `void`, and pointer. Encapsulation and object-oriented features cannot be used (for example, user-defined constructors, assignment operators, destructors, base classes, and virtual functions).

For non-POD classes, such as class objects of non-aggregate types, virtual functions may exist. Memory layout is uncertain, and is related to the compiler. Misuse of memory copies may cause serious problems.

Even if a class of the aggregate type is directly copied and compared, and any functions hiding information or protecting data are destroyed, the `memcpy_s` and `memset_s` operations are not recommended.

For details about the POD type, see the appendix.

### Rec 9.1.2 Declare and initialize variables only when they are used.

**Note**: It is a common low-level programming error that a variable is not assigned an initial value before being used. Declaring and initializing a variable just before using it will prevent this.

If all variables are declared at the beginning of a function before they are used, their scope covers the entire function, which may lead to the following problems:
* The program may become difficult to understand and maintain. The definition and use of variables are separated.
* These variables are difficult to initialize properly. At the beginning of a function, there is often insufficient information for variable initialization, and a default null value (such as 0) is often assigned as the initial value. If a variable is used before it is assigned a valid value, it will also cause errors.

Following the minimization principle of variable scopes and the principle of proximity declaration will make it easier to read code and understand variable types and initial values. In particular, use initialization to replace declaration and then assign values.

```cpp
// Bad example: Declaration is separated from initialization.
string name;        // The variable is not initialized in the declaration, and a default constructor is called.
name = "zhangsan";  // An assignment operator is called again. Declaration is separate from definition, which is difficult to understand.

// Good example: Declaration and initialization are together, and easy to understand.
string name("zhangsan");  // Invoke a constructor.
```


## Expressions
### Rule 9.2.1 A variable cannot be referenced again if it is contained in an increment or decrement operation in an expression. 
In an expression where the increment or decrement operations are performed on a variable, the variable cannot be referenced again. The result of a second referencing is not explicitly defined in C++ standards. The results in different compilers or different versions of a compiler may be different.
Therefore, it is recommended that an undefined operation sequence not be assumed.

Note that the problem of operation sequence cannot be solved by using parentheses because this is not a priority problem.

Example:
```cpp
x = b[i] + i++; // Bad: Whether the position of b[i] is before or after the i++ is unclear.
```
The increment or decrement operation should be placed in a single line:
```cpp
x = b[i] + i;
i++;            // Good: i++ is placed in a single line.
```

Function parameter
```cpp
Func(i++, i);   // Bad: Whether the increment operation happens for the second parameter is unclear
```

Good example:
```cpp
i++;            // Good: i++ is placed in a single line.
x = Func(i, i);
```

### Rule 9.2.2 A switch statement must have a default branch.
In most cases, a switch statement requires a default branch to ensure that there is a default action when the case tag is missing for a processed value.

Exceptions:

If the switch condition variables are enumerated and the case branch covers all values, the default branch is redundant.

Because modern compilers can check which case branches are missing in the switch statement and provide an advanced warning. 

```cpp
enum Color {
    RED = 0,
    BLUE
};

// The switch condition variables are enumerated. Therefore, you do not need to add a default branch.
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

### Rec 9.2.1 When comparing expressions, follow the principle that the left side tends to change and the right side tends to remain unchanged.
When a variable is compared with a constant, placing the constant on the left, for example, if (MAX == v), does not comply with standard reading habits  and is more difficult to understand.
The constant should be placed on the right. The expression is written as follows:
```cpp
if (value == MAX) {
  
}

if (value < MAX) {
  
}
```
There are special cases: for example, if the expression `if (MIN < value && value < MAX)` is used to describe a range, the first half, as a constant, should be placed on the left.

You do not need to worry about writing '==' as '=' because a compilation alarm will be generated for `if (value = MAX)` and an error will be reported by other static check tools. Use these tools to solve such writing errors and ensure that that code is readable.

### Rec 9.2.2 Use parentheses to specify the operator precedence.
Use parentheses to specify the operator precedence. This will prevent program errors due to the inconsistency between default priority and the intended design. At the same time, it makes the code clearer and more readable. However, too many parentheses muddy the code, reducing readability. The following is a recommendation on their correct usage.

- For binary and ternary operators, if multiple operators are involved, parentheses should be used.
```cpp
x = a + b + c;        /* The operator does not change, and thus parentheses are not required. */
x = Foo(a + b, c);     /* The operator does not change, and thus parentheses are not required. */
x = 1 << (2 + 3);      /* More than one operator is used and thus parentheses are required. */
x = a + (b / 5);       /* More than one operator is used and thus parentheses are required. */
x = (a == b) ? a : (a – b);    /* More than one operator is used and thus parentheses are required. */
```


## Type Casting

Do not use type branches to customize behaviors. Type branch customization behavior is prone to errors and is an obvious sign of attempting to compile C code using C++. This is very inflexible technology. If you forget to modify all branches when adding a new type to a compiler, you will not be notified. Use templates and virtual functions to let the type define itself rather than letting the calling side determine behavior.

It is recommended that type casting be avoided. We should consider the data type in the code design instead of overusing type casting to solve type conflicts. When designing a basic type, consider the following:
- Whether it is unsigned or signed.
- Is it suitable for float or double?
- Should you use int8, int16, int32, or int64 bit lengths?

However, we cannot prohibit the use of type casting because the C++ language is a machine-oriented programming language, involving pointer addresses, and we interact with various third-party or underlying APIs. Their type design may not be reasonable and type casting tends to occur in the adaptation process.

Exception: When calling a function, if we do not want to process the result of the function, first consider whether this is your best choice. If you do not want to process the return value of the function, cast it to void.

### Rule 9.3.1 If type casting is required, use the type casting provided by the C++ instead of the C style.

**Note**:

The type casting provided by C++ is more targeted, easy to read, and more secure than the C style. C++ provides the following types of casting:
- Type casting:
1. `dynamic_cast`: Used to inherit the downstream transformation of the system. `dynamic_cast` has the type check function. Design the base class and derived class to avoid using dynamic_cast for casting.
2. `static_cast`: Similar to the C style casting, which can be used to convert a value, or to convert the pointer or reference of a derived class into a base class pointer or reference. This casting is often used to eliminate type ambiguity brought on by multiple inheritance, which is relatively safe. If it is a pure arithmetic conversion, use the braces as stated in the following text.
3. `reinterpret_cast`: Used to convert irrelevant types. `reinterpret_cast` forces the compiler to reinterpret the memory of a certain type of objects into another type, which is an unsafe conversion. It is recommended that `reinterpret_cast` be used as little as possible.
4. `const_cast`: Used to remove the `const` attribute of an object so that the object can be modified. You are advised to use `const_cast` as little as possible.

- Arithmetic conversion: (Supported by C++ 11 and later versions)
  If the type information is not lost, for example, the casting from float to double, or from int32 to int64, the braces syntax is recommended.
```cpp
  double d{ someFloat };
  int64_t i{ someInt32 };
```

### Rec 9.3.1 Avoid using `dynamic_cast`.
1. `dynamic_cast` depends on the RTTI of C++ so that the programmer can identify the type of the object in C++ at run time.
2. `dynamic_cast` indicates that a problem has occurred in the design of the base class and derived class.The derived class destroys the contract of the base class and it is necessary to use `dynamic_cast` to convert the class to a subclass for special processing. In this case, it is more desirable to improve the design of the class, instead of using `dynamic_cast` to solve the problem.

### Rec 9.3.2 Avoid using `reinterpret_cast`.

**Note**: `reinterpret_cast` is used to convert irrelevant types. Trying to use `reinterpret_cast` to force a type to another type destroys the security and reliability of the type and is an insecure casting method. Avoid casting between completely different types.

### Rec 9.3.3 Avoid using `const_cast`.

**Note**: The `const_cast` command is used to remove the `const`  and `volatile` properties of an object.

The action of using a pointer or reference after the const_cast conversion to modify the const property of an object is undefined.

```cpp
// Bad example:
const int i = 1024; 
int* p = const_cast<int*>(&i);
*p = 2048;      // The action is undefined.
```

```cpp
// Bad example:
class Foo {
public:
    Foo() : i(3) {}

    void Fun(int v) 
    {
        i = v;
    }

private:
    int i;
};

int main(void)
{
    const Foo f;
    Foo* p = const_cast<Foo*>(&f);
    p->Fun(8);  // The action is undefined.
}

```


## Resource Allocation and Release

### Rule 9.4.1 When a single object is released, delete is used. When an array object is released, delete [] is used.
Note: To delete a single object, use delete; to delete an array object, use delete []. The reasons are as follows:

- new: Apply for memory from the system and call the corresponding constructor to initialize an object.
- new[n]: Apply for memory for n objects and call the constructor n times for each object to initialize them.
- delete: Call the corresponding destructor first and release the memory of an object.
- delete[]: Call the corresponding destructor for each object and release their memory.

If the usage of new and delete does not match this format, the results are unknown. For a non-class type, new and delete will not call the constructor or destructor.

Bad example:
```cpp
const int MAX_ARRAY_SIZE = 100;
int* numberArray = new int[MAX_ARRAY_SIZE];
...
delete numberArray;
numberArray = NULL;
```

Good example:
```cpp
const int MAX_ARRAY_SIZE = 100;
int* numberArray = new int[MAX_ARRAY_SIZE];
...
delete[] numberArray;
numberArray = NULL;
```

### Rec 9.4.1 Use the RAII feature to trace dynamic allocation.

Note: RAII is an acronym for Resource Acquisition Is Initialization. It is a simple technology that controls program resources (such as memory, file handle, network connections, and mutexes) by using the object lifecycle.

The common practice is as follows: When the object is constructed, the resource is obtained, and the access to the resource is controlled so that the resource is always valid in the life cycle of the object. Finally, the resource is released when the object is destructed. This approach has two advantages:
- We do not need to explicitly release resources.
- The resources required by the object are always valid throughout the lifecycle of the object. This way, you do not need to check the validity of the resources, which simplifies logic and improves efficiency.


In the following example, RAII removes the need for explicit release of mutex resources.

```cpp
class LockGuard {
public:
    LockGuard(const LockType& lockType): lock_(lockType)
    {
        lock_.Acquire();
    }
    
    ~LockGuard()
    {
        lock_.Release();
    }
    
private:
    LockType lock_;
};


bool Update()
{
    LockGuard lockGuard(mutex);
    if (...) {
        return false;
    } else {
        // Data operations
    }
    
    return true;
}
```

## Standard Template Library

The standard template library (STL) varies between products. The following table lists some basic rules and suggestions for each team.

### Rule 9.5.1 Do not save the pointer returned by c_str () of std::string.

Note: The C++ standard does not specify that the string::c_str () pointer is permanently valid. Therefore, the STL implementation used can return a temporary storage area and release it quickly when calling string::c_str (). Therefore, to ensure the portability of the program, do not save the result of string::c_str (). Instead, call it directly.

Example:

```cpp
void Fun1()
{
    std::string name = "demo";
    const char* text = name.c_str(); // After the expression ends, the life cycle of name is still in use and the pointer is valid.

    // If a non-const member function (such as operator[] and begin()) of the string type is invoked and the string is modified,
    // The text may become unavailable or may not be the original string.
    name = "test";
    name[1] = '2';

    // When the text pointer is used next time, the string is no longer "demo".
}

void Fun2()
{
    std::string name = "demo";
    std::string test = "test";
    const char* text = (name + test).c_str(); // After the expression ends, the temporary object generated by the + operator may be destroyed, and the pointer may be invalid.

    // When the text pointer is used next time, it no longer points to the valid memory space.
}
```
Exception: In rare cases where high performance coding is required , you can temporarily save the pointer returned by string::c_str() to match the existing functions which support only the input parameters of the const char* type. However, you should ensure that the lifecycle of the string object is longer than that of the saved pointer, and that the string object is not modified within the lifecycle of the saved pointer.


### Rec 9.5.1 Use std::string instead of char*.

Note: Using string instead of `char*` has the following advantages:
1. There is no need to consider the null character '\0' at the end.
2. You can directly use operators such as `+`,  `=`, and `==`, and other character and string operation functions.
3. There is no need to consider memory allocation operations. This helps avoid explicit usage of `new` and `delete` and the resulting errors.

Note that in some STL implementations, string is based on the copy-on-write policy, which causes two problems. One is that the copy-on-write policy of some versions does not implement thread security, and the program breaks down in multi-threaded environments. Second, dangling pointers may be caused when a dynamic link library transfers the string based on the copy-on-write policy, due to the fact that reference count cannot be reduced when the library is unloaded. Therefore, it is important to select a reliable STL implementation to ensure the stability of the program.

Exception:

When an API of a system or other third-party library is called, only `char*` can be used for defined interfaces. However, before calling the interfaces, you can use string. When calling the interfaces, you can use `string::c_str()` to obtain the character pointer.

When a character array is allocated as a buffer on the stack, you can directly define the character array without using string or containers such as `vector<char>`.

### Rule 9.5.2 Do not use auto_ptr.
Note: The `std::auto_ptr` in the STL library has an implicit ownership transfer behavior. The code is as follows:
```cpp
auto_ptr<T> p1(new T);
auto_ptr<T> p2 = p1;
```
After the second line of statements is executed, p1 does not point to the object allocated in line 1 and becomes `NULL`. Therefore, `auto_ptr` cannot be placed in any standard containers.

This ownership transfer behavior is not expected. In scenarios where ownership must be transferred, implicit transfer should not be used. This often requires the programmer to keep extra attention on code that uses `auto_ptr`, otherwise access to a null pointer will occur.

There are two common scenarios for using auto_ptr . One is to transfer it as a smart pointer to outside the function that generates the auto_ptr , and the other is to use auto_ptr as the RAII management class. Resources are automatically released when the lifecycle of auto_ptr expires.

In the first scenario, you can use std::shared_ptr instead.

In the second scenario, you can use std::unique_ptr in the C++ 11 standard. std::unique_ptr is a substitute for std::auto_ptr and supports explicit ownership transfer.

Exception:

Before the C++ 11 standard is widely used, std::auto_ptr can be used in scenarios where ownership needs to be transferred. However, it is recommended that std::auto_ptr be encapsulated. The copy constructor and assignment operator of the encapsulation class should not be used in a standard container.


### Rec 9.5.2 Use the new standard header files.

Note:
When using the standard header file of C++, use `<cstdlib>` instead of `<stdlib.h>`.

## Usage of const
Add the keyword const before the declared variable or parameter (example: `const int foo`) to prevent the variable from being tampered with. Add the const qualifier to the function in the class (example: `class Foo {int Bar (char c) const;} ;`) to make sure the function does not modify the status of the class member variable. const variables, data members, functions, and parameters ensure that the type detection during compilation is accurate and errors are found as soon as possible. Therefore, we strongly recommend that const be used in any possible case.

Sometimes it is better to use constexpr from C++ 11 to define real constants.

### Rule 9.6.1 For formal parameters of pointer and reference types, if the parameters do not need to be modified, use const.
Unchanging values are easier to understand, trace, and analyze. `const` is used as the default option and is checked during compilation to make the code more secure and reliable.
```cpp
class Foo;

void PrintFoo(const Foo& foo);
```

### Rule 9.6.2 For member functions that do not modify member variables, use const.
Declare the member function as `const` whenever possible. The access function should always be const. So long as the function of a member is not modified, the function is declared with const.

When you need to modify data members in a virtual function, take all classes in the inheritance chain into account instead of only focusing on the implementation of a single class.

```cpp
class Foo {
public:

    // ...

    int PrintValue() const // const modifies member functions and does not modify member variables.
    {
        std::cout << value_ << std::endl;
    }

    int GetValue() const  // const modifies member functions and does not modify member variables.
    {
        return value_;
    }

private:
    int value_;
};
```

### Rec 9.6.1 Member variables that will not be modified after initialization should be defined as constants.

```cpp
class Foo {
public:
    Foo(int length) : dataLength_(length) {}
private:
    const int dataLength_;  
};
```

## Exceptions

### Rec 9.7.1 If the function does not throw an exception, the declaration is `noexcept`.
**Reasons:**
1. If the function does not throw an exception, the declaration is `noexcept`, which enables the compiler to optimize the function to the maximum extent, for example, reducing the execution paths and improving the efficiency of exiting when an error occurs.
2. For STL containers such as  `vector`, to ensure the interface robustness, if the `move `  constructor of saved items is not declared as `noexcept`,  the `copy machanism` instead of the  `move machanism`  is used when the items are removed from the container. This would cause performance loss risks. If the function does not throw an exception, or a program does not intercept and process an exception thrown by the function, new `noexcept` keywords can be used to modify the function, indicating that the function does not throw an exception or the thrown exception is not intercepted or processed. For example:

```cpp
extern "C" double sqrt(double) noexcept;  // No exceptions are thrown.

// noexcept can still be used when exceptions may be thrown.
// The exception of memory exhaustion is not processed. The function is simply declared as noexcept.
std::vector<int> MyComputation(const std::vector<int>& v) noexcept
{
    std::vector res = v;    // Exceptions may be thrown.
    // do something
    return res;
}
```

**Example**

```cpp
RetType Function(Type params) noexcept;   // Maximized optimization
RetType Function(Type params) noexcept;   // No optimization

// Declaration as noexcept for the move operation of std::vector is needed.
class Foo1 {
public:
    Foo1(Foo1&& other);  // no noexcept
};

std::vector<Foo1> a1;
a1.push_back(Foo1());
a1.push_back(Foo1()); // The copy constructor is called to enable the container expansion and removal of existing items.

class Foo2 {
public:
    Foo2(Foo2&& other) noexcept;
};

std::vector<Foo2> a2;
a2.push_back(Foo2());
a2.push_back(Foo2()); //Triggers container expansion and invokes the move constructor to move existing elements.
```

**Note**

The default constructor, destructor, `swap` function, and `move` operator should not throw an exception.

## Templates and Generic Programming

### Rule 9.8.1 Do not use generic programming.
OpenHarmony adopts object-oriented programming, which has ideas, concepts, and techniques totally different from those of generic programming.

Generic programming in C++ allows for extremely flexible interfaces that are type safe and high performance, enabling reuse of code of different types but with the same behavior.

However, generic programming has the following disadvantages:

1. People who are not familiar with generic programming often write into templates object-oriented logic or members that do not depend on template parameters, making the code unreadable or bloated.
2. The techniques used in generic programming are often obscure to anyone but language experts. Template code can be unreadable in certain cases.
3. Generic programming often leads to extremely poor compile time error messages. The uncalled-for implementation details of APIs are displayed to users in the error messages, making even a simple API difficult to debug.
4. Inappropriate use of templates cause code bloat during runtime.
5. It is difficult to modify or refactor the template code. The template code is expanded in multiple contexts, and it is hard to verify that the code refactoring makes sense in all of them.

Only __a few components of OpenHarmony__ support generic programming, and the templates developed using generic programming must have detailed comments.

Exceptions:

The STL adaptation layer can use generic programming.

## Macros
In the C++ language, it is strongly recommended that complex macros be used as little as possible.
- For constant definitions, use `const` or `enum` as stated in the preceding sections. 
- For macro functions, try to be as simple as possible, comply with the following principles, and use inline functions and template functions for replacement.

```cpp
// The macro function is not recommended.
#define SQUARE(a, b) ((a) * (b)) 

// Use the template function and inline function as a replacement.
template<typename T> T Square(T a, T b) { return a * b; }
```

For details about how to use macros, see the related chapters about the C language specifications.
**Exception**: For some common and mature applications, for example, encapsulation for new and delete, the use of macros can be retained.

# 10 Modern C++ Features

As the ISO released the C++ 11 language standard in 2011 and released the C++ 17 in March 2017, the modern C++ (C++ 11/14/17) adds a large number of new language features and standard libraries that improve programming efficiency and code quality.
This chapter describes some guidelines for modern C++ use, to avoid language pitfalls.

## Code Simplicity and Security Improvement
### Rec 10.1.1 Use `auto` properly.
**Reasons**

* `auto` can help you avoid writing verbose, repeated type names, and can also ensure initialization when variables are defined.
* The `auto` type deduction rules are complex and need to be read carefully.
* If using `auto` makes the code clearer, use a specific type of it and use it only for local variables.

**Example**

```cpp
// Avoid verbose type names.
std::map<string, int>::iterator iter = m.find(val);
auto iter = m.find(val);

// Avoid duplicate type names.
class Foo {...};
Foo* p = new Foo;
auto p = new Foo;

// Ensure that the initialization is successful.
int x;    // The compilation is correct but the variable is not initialized.
auto x;   // The compilation failed. Initialization is needed.
```

`auto` type deduction may cause the following problems:

```cpp
auto a = 3;           // int
const auto ca = a;    // const int
const auto& ra = a;   // const int&
auto aa = ca;         // int, const and reference are neglected.
auto ila1 = { 10 };   // std::initializer_list<int>
auto ila2{ 10 };      // std::initializer_list<int>

auto&& ura1 = x;      // int&
auto&& ura2 = ca;     // const int&
auto&& ura3 = 10;     // int&&

const int b[10];
auto arr1 = b;        // const int*
auto& arr2 = b;       // const int(&)[10]
```

If you do not pay attention to `auto` type deduction and ignore the reference, hard-to-find performance problems may be created.

```cpp
std::vector<std::string> v;
auto s1 = v[0]; // auto deduction changes s1 to std::string in order to copy v[0].
```

If `auto` is used to define an interface, such as a constant in a header file, the type may be changed if the developer has modified the value.

### Rule 10.1.1 Use the keyword `override` when rewriting virtual functions.
**Reason**

The keyword `override` ensures that the function is a virtual function and an overridden virtual function of the base class. If the subclass function is different from the base class function prototype, a compilation alarm is generated. `final` also ensures that virtual functions are not overridden by subclasses.

If you modify the prototype of a base class virtual function but forget to modify the virtual function overridden by the subclass, you can find inconsistency during compilation. You can also avoid forgetting to modify the overridden function when there are multiple subclasses.

**Example**

```cpp
class Base {
public:
    virtual void Foo();
    virtual void Foo(int var);
    void Bar();
};

class Derived : public Base {
public:
    void Foo() const override; // Compilation failed: derived::Foo is different from that of the prototype of base::Foo and is not overridden.
    void Foo() override;       // Compilation successful: derived::Foo overrode base::Foo.
    void Foo(int var) final;   // Compilation successful: Derived::Foo(int) rewrites Base::Foo(int), and the derived class of Derived cannot override this function.
    void Bar() override;       // Compilation failed: base::Bar is not a virtual function.
};
```

**Summary**
1. When defining the virtual function for the first time based on the base class, use the keyword `virtual`.
2. When overriding the virtual function by a subclass in a base class, including destructors, use the keyword `override` or  `final` instead of `virtual`.
3. For the non-virtual function, do not use `virtual` or `override`.

### Rule: 10.1.2 Use the keyword `delete` to delete functions.
**Reason**

The `delete` keyword is clearer and the application scope is wider than a class member function that is declared as private and not implemented.

**Example**

```cpp
class Foo {
private:
    // Whether the copy structure is deleted or not is unknown because usually only the header file is checked.
    Foo(const Foo&);
};

class Foo {
public:
    // Explicitly delete the copy assignment operator.
    Foo& operator=(const Foo&) = delete;
};
```

The `delete` keyword can also be used to delete non-member functions.

```cpp
template<typename T>
void Process(T value);

template<>
void Process<void>(void) = delete;
```

### Rule 10.1.3 Use `nullptr` instead of `NULL` or `0`.
**Reason**

For a long time, C++ has not had a keyword that represents a null pointer, which is embarrassing:

```cpp
#define NULL ((void *)0)

char* str = NULL;   // Error: void* cannot be automatically converted to char*.

void(C::*pmf)() = &C::Func;
if (pmf == NULL) {} // Error: void* cannot be automatically converted to the pointer that points to the member function.
```

If `NULL` is defined as `0` or `0L`, the above problems can be solved.

Alternatively, use `0` directly in places where null pointers are required. However, another problem occurs. The code is not clear, especially when `auto` is used for automatic deduction.

```cpp
auto result = Find(id);
if (result == 0) {  // Does Find() return a pointer or an integer?
    // do something
}
```

Literally `0` is of the `int` type (`0L` is the `long` type). Therefore, neither `NULL` nor `0` is a pointer type.
When a function of the pointer or integer type is overloaded, `NULL` or `0` calls only the overloaded pointer function.

```cpp
void F(int);
void F(int*);

F(0);      // Call F(int) instead of F(int*).
F(NULL);   // Call F(int) instead of F(int*).
```

In addition, `sizeof(NULL) == sizeof(void*)` does not always make sense, which is a potential risk.

Summary: If `0` or `0L` is directly used, the code is not clear and type security cannot be ensured. If `NULL` is used, the type security cannot be ensured. These are all potential risks.

`nullptr` has many advantages. It literally represents the null pointer and makes the code clearer. More to the point, it is no longer an integer type.

`nullptr` is of the `std::nullptr_t` type. `std::nullptr_t` can be implicitly converted into all original pointer types, so that `nullptr` can represent a null pointer that points to any type.

```cpp
void F(int);
void F(int*);
F(nullptr);   // Call F(int*).

auto result = Find(id);
if (result == nullptr) {  // Find() returns a pointer.
    // do something
}
```

### Rule 10.1.4 Use `using` instead of `typedef`.
For versions earlier than `C++11`, you can define the alias of the type by using `typedef`. No one wants to repeat code like `std::map<uint32_t, std::vector<int>>`.

```cpp
typedef std::map<uint32_t, std::vector<int>> SomeType;
```

Using alias for the type is actually encapsulating the type. This encapsulation makes the code clearer, and to a large extent avoids the bulk modification caused by the type change.
For versions supporting C++ 11 features, `using` is provided to implement `alias declarations`:

```cpp
using SomeType = std::map<uint32_t, std::vector<int>>;
```

Compare the two formats:

```cpp
typedef Type Alias;   // It cannot be told whether the original Type or Alias is at the front.
using Alias = Type;   // The format confirms to the assignment rule. It is easy to understand and helps reduce errors.
```

If this is not enough to prove the advantages of `using`, the alias template may be a better example:

```cpp
//: Only one line of code is need to define an alias for a template.
template<class T>
using MyAllocatorVector = std::vector<T, MyAllocator<T>>;

MyAllocatorVector data;       // An alias for a template defined with "using".

template<class T>
class MyClass {
private:
    MyAllocatorVector data_;   // Another.
};
```

`typedef` does not support alias templates and they have to be hacked in.

```cpp
// A template is used for packaging typedef. Therefore, a template class is needed.
template<class T>
struct MyAllocatorVector {
    typedef std::vector<T, MyAllocator<T>> type;
};

MyAllocatorVector::type data;  // ::type needs to be added when using typedef to define an alias.

template<class T>
class MyClass {
private:
    typename MyAllocatorVector::type data_;  // For a template class, typename is also needed in addition to ::type.
};
```

### Rule 10.1.5 Do not use std::move to operate the const object.
Literally, `std::move` means moving an object. The const object cannot be modified and cannot be moved. Therefore, using `std::move` to operate the const object may confuse code readers.

Regarding actual functions, `std::move` converts an object to the rvalue reference type. It can convert the const object to the rvalue reference of const. Because few types define the move constructor and the move assignment operator that use the const rvalue reference as the parameter, the actual function of code is often degraded to object copy instead of object movement, which brings performance loss.

**Bad example**

```cpp
std::string g_string;
std::vector<std::string> g_stringList;

void func()
{
    const std::string myString = "String content";
    g_string = std::move(myString); // Bad: myString is not moved. Instead, it is copied.
    const std::string anotherString = "Another string content";
    g_stringList.push_back(std::move(anotherString));    // Bad: anotherString is not moved. Instead, it is copied.
}
```

## Smart Pointers
### Rule 10.2.1 Preferentially use the original pointer instead of the smart pointer for singletons and class members that are not held by multiple parties.
**Reason**
Smart pointers automatically release object resources to prevent resource leakage, but they require extra resource overheads. For example, the classes, constructors, and destructors automatically generated by smart pointers consume more resources such as memory.

When singletons, class members, and the like are not held by multiple parties, resources can be released only in class destructors. In this case, smart pointers should not be used.

**Example**

```cpp
class Foo;
class Base {
public:
    Base() {}
    virtual ~Base() 
    {
        delete foo_;
    }
private:
    Foo* foo_ = nullptr;
};
```

**Exceptions**
1. When a created object is returned, a smart pointer can be used if the pointer destructor is required.
```cpp
class User;
class Foo {
public:
    std::unique_ptr<User, void(User *)> CreateUniqueUser() // Use unique_ptr to ensure that the object is created and released in the same runtime.
    {
        sptr<User> ipcUser = iface_cast<User>(remoter);
        return std::unique_ptr<User, void(User *)>(::new User(ipcUser), [](User *user) {
            user->Close();
            ::delete user;
        });
    }

    std::shared_ptr<User> CreateSharedUser() // Use shared_ptr to ensure that the object is created and released in the same runtime.
    {
        sptr<User> ipcUser = iface_cast<User>(remoter);
        return std::shared_ptr<User>(ipcUser.GetRefPtr(), [ipcUser](User *user) mutable {
            ipcUser = nullptr;
        });
    }
};
```
2. When the created object is returned and needs to be referenced by multiple parties, `shared_ptr` can be used.

### Rule 10.2.2 Use `unique_ptr` instead of `shared_ptr`.
**Reasons**

1. Using `shared_ptr` a lot has an overhead (atomic operations on the `shared_ptr`s reference count have a measurable cost).
2. Shared ownership in some cases (such as circular dependency) may create objects that can never be released.
3. Shared ownership can be an attractive alternative to careful ownership design but it may obfuscate the design of a system.

### Rule 10.2.2 Use `std::make_unique` instead of `new` to create a `unique_ptr`.
**Reasons**

1. `make_unique` provides a simpler creation method.
2. `make_unique` ensures the exception safety of complex expressions.

**Example**

```cpp
// Bad: MyClass appears twice, which carries a risk of inconsistency.
std::unique_ptr<MyClass> ptr(new MyClass(0, 1));
// Good: MyClass appears once and there is no possibility of inconsistency.
auto ptr = std::make_unique<MyClass>(0, 1);
```

Recurrence of types may cause serious problems, and it is difficult to find them:

```cpp
// The code compiles fine, but new and delete usage does not match.
std::unique_ptr<uint8_t> ptr(new uint8_t[10]);
std::unique_ptr<uint8_t[]> ptr(new uint8_t);
// No exception safety: The compiler may calculate parameters in the following order:
// 1. Allocate the memory of Foo.
// 2. Construct Foo.
// 3. Call Bar.
// 4. Construct unique_ptr<Foo>.
// If Bar throws an exception, Foo is not destroyed and a memory leak occurs.
F(unique_ptr<Foo>(new Foo()), Bar());

// Exception safety: Calling of function is not interrupted.
F(make_unique<Foo>(), Bar());
```

**Exception**

`std::make_unique` does not support user-defined `deleter`.

In the scenario where the `deleter` needs to be customized, it is recommended that `make_unique` be implemented in the customized version's own namespace.

Using `new` to create `unique_ptr` with the user-defined `deleter` is the last choice.

### Rule 10.2.4 Create `shared_ptr` by using `std::make_shared` instead of `new`.
**Reason**

In addition to the consistency factor similar to that in `std::make_unique` when using `std::make_shared`, performance is also a factor to consider.
`std::shared_ptr` manages two entities:

* Control block (storing reference count, `deleter`, etc.)
* Managed objects

When `std::make_shared` creates `std::shared_ptr`, it allocates sufficient memory for storing control blocks and managed objects on the heap at a time. When `std::shared_ptr<MyClass>(new MyClass)`is used to create a `std::shared_ptr`, not only does `new MyClass` trigger heap allocation, but the constructor function of `std::shard_ptr` triggers a second heap allocation, resulting in extra overhead.

**Exception**

Similar to `std::make_unique`, `std::make_shared` does not support `deleter` customization.

## Lambda
### Rec 10.3.1 Use `lambda` to capture local variables or write local functions when normal functions do not work.
**Reason**

Functions cannot capture local variables or be declared at local scope. If you need those things, choose `lambda` instead of handwritten `functor`.

On the other hand, `lambda` and `functor` objects do not support overloading. If overloading is required, use a function.

If both `lambda` and functions work, a function is preferred. Use the simplest tool.

**Example**

```cpp
// Write a function that accepts only an int or string.
// -- Overloading is more natural.
void F(int);
void F(const string&);

// The local state needs to be captured or appear in the statement or expression range.
// -- A lambda is more natural.
vector<Work> v = LotsOfWork();
for (int taskNum = 0; taskNum < max; ++taskNum) {
    pool.Run([=, &v] {...});
}
pool.Join();
```

### Rule 10.3.1 Avoid capturing by reference in lambdas that will not be used locally.
**Reason**

Using `lambdas` at a "nonlocal" scope includes returning, storing on the heap, and passing to another thread. Local pointers and references should not outlive their scope. Capturing by reference in `lambdas` indicates storing a reference to a local object. If this leads to a reference that exceeds the lifecycle of a local variable, capturing by reference should not be used.

**Example**

```cpp
// Bad
void Foo()
{
    int local = 42;
    // Capture a reference to a local variable.
    // After the function returns results, local no longer exists,
    // Process() call will have undefined behavior.
    threadPool.QueueWork([&]{ Process(local); });
}

// Good
void Foo()
{
    int local = 42;
    // Capture a copy of local.
    // Since a copy of local is made, it will be always available for the call.
    threadPool.QueueWork([=]{ Process(local); });
}
```

### Rec 10.3.2 All variables are explicitly captured if `this` is captured.
**Reason**

The `[=]` in the member function seems to indicate capturing by value but actually it is capturing data members by reference because it captures the invisible `this` pointer by value. Generally, it is recommended that capturing by reference be avoided. If it is necessary to do so, write `this` explicitly.

**Example**

```cpp
class MyClass {
public:
    void Foo()
    {
        int i = 0;

        auto Lambda = [=]() { Use(i, data_); };   // Bad: It looks like we are copying or capturing by value but member variables are actually captured by reference.

        data_ = 42;
        Lambda(); // Call use(42);
        data_ = 43;
        Lambda(); // Call use(43);

        auto Lambda2 = [i, this]() { Use(i, data_); }; // Good: the most explicit and least confusing method.
    }

private:
    int data_ = 0;
};
```

### Rec 10.3.3 Avoid default capture modes.
**Reason**

The lambda expression provides two default capture modes: by-reference (&) and by-value (=).

By default, the "by-reference" capture mode will implicitly capture the reference of all local variables, which will easily lead to dangling references. By contrast, explicitly writing variables that need to be captured can make it easier to check the lifecycle of an object and reduce the possibility of making a mistake.

By default, the "by-value" capture mode will implicitly capture this pointer, and it is difficult to find out which variables the lambda function depends on. If a static variable exists, the reader mistakenly considers that the lambda has copied a static variable.

Therefore, it is required to clearly state the variables that lambda needs to capture, instead of using the default capture mode.

**Bad example**

```cpp
auto func()
{
    int addend = 5;
    static int baseValue = 3;

    return [=]() {  // Only addend is actually copied.
        ++baseValue;    // The modification will affect the value of the static variable.
        return baseValue + addend;
    };
}
```

**Good example**

```cpp
auto func()
{
    int addend = 5;
    static int baseValue = 3;

    return [addend, baseValue = baseValue]() mutable {  // Uses the C++14 capture initialization to copy a variable.
        ++baseValue;    // Modifying the copy of a static variable does not affect the value of the static variable.
        return baseValue + addend;
    };
}
```

Reference: Effective Modern C++: Item 31: Avoid default capture modes.

## Interfaces
### Rec 10.4.1 Use `T*` or `T&` arguments instead of a smart pointer in scenarios where ownership is not involved.
**Reasons**

1. Passing a smart pointer to transfer or share ownership should only be used when the ownership mechanism is explicitly required.
2. Passing a smart pointer (for example, passing `this` ) restricts the use of a function to callers using smart pointers.
3. Passing a shared smart pointer adds a runtime performance cost.

**Example**

```cpp
// Accept any int*.
void F(int*);

// Accept only integers for which you want to transfer ownership.
void G(unique_ptr<int>);

// Accept only integers for which you want to share ownership.
void G(shared_ptr<int>);

// Does not need to change the ownership but requires ownership of the caller.
void H(const unique_ptr<int>&);

// Accept any int.
void H(int&);

// Bad
void F(shared_ptr<Widget>& w)
{
    // ...
    Use(*w); // When only w is used, lifecycle management is not required.
    // ...
};
```
