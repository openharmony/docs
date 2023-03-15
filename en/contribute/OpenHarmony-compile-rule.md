
# OpenHarmony Compilation Specifications

## Overview

**Introduction**

This topic covers C, C++, and Java compiler options or system configurations, including language options, warning options, security options, general options, code generation options, architecture options, optimization options, and compiler macros.

**Scope**

This topic specifies the C, C++, and Java compiler options or system configurations to be added during the compilation and build, and briefly describes the functionalities of these options. It also explains the involved exceptions.

This topic does not cover security options in non-OS cases (such as bare core, BIOS, Bootloader, and BSBC). It is recommended that stack protection be implemented before related specifications are released.

You can apply for arbitration for any dispute over exceptions that are not described in this document.

**Clause Composition**

Each clause generally includes the title, level, and description. In the description part, "Positive Example" provides an example that meets the clause, and "Negative Example" provides an example that does not meet the clause.

**Title**

Brief description of the clause.

Clauses are classified into principles and guidelines. Principles can be used to evaluate the quality of guidelines and serve as a guide for their adjustment. Guidelines are practices that need to be followed or referenced. The identifier preceding a title tells whether the clause is a principle (P) or guideline (G).

As stipulated in *Security Engineering Guidelines*, a principle identifier takes the format of P.Number, and a guideline identifier takes the format of G.Language.Element.Number, where **Language** indicates the programming language in use, **Element** is an abbreviation of the key element (corresponding to the level-1 title in this topic) in the domain, and **Number** is a 2-bit number incremented from 01. 

| Language | Element | Catalog    | Language | Element | Catalog        |
|----------|---------|----------|----------|---------|--------------|
| C&C++    | LANG    | Language options| C&C++    | WARN    | Warning options    |
| C&C++    | SEC     | Security options| C&C++    | CDG     | Code generation options|
| C&C++    | OPT     | Optimization options| C&C++    | MD      | Architecture options    |
| C&C++    | OVA     | General options| C&C++    | LNK     | Link options    |
| C&C++    | DBG     | Debugging options| C&C++    | PRE     | Compiler macros      |
| C&C++    | OTH     | Other    | Java      | JAVAC     | Javac   |
| Java    | MAVEN   | Maven   |   |    |        |

**Level**

Guidelines are classified into requirements and recommendations by level.

-   Requirement: a guideline that must be followed in principle, but can be implemented phase by phase based on the specific product version plan.

-   Recommendation: a best practice that helps mitigate risks. Your team can determine whether to follow the recommendation based on actual business conditions.

**Description**

This part describes the clause, its working principle, and positive and negative examples. For some clauses, exceptions are provided.

##  C/C++ Compiler Options

### Language Options

##### G.C&C++.LANG.01 Explicitly set the compiler language standards.

**[Type]** Requirement

**[Description]** According to the time sequence, common ISO C standards include **-std=c90**, **-std=c99**, and **-std=c11**, and the corresponding GNU extension standards are **-std=gnu90**, **-std=gnu99**, and **-std=gnu11**.

According to the time sequence, common ISO C++ standards include **-std=c++98**, **-std=c++11**, **-std=c++14**, and **-std=c++1z**, and the corresponding GNU extension standards are **-std=gnu++98**, **-std=gnu++11**, **-std=gnu++14**, and **-std=gnu++1z**.

**-ansi** corresponds to **-std=c90** in the ISO C standard and **-std=c++98** in the ISO C++ standard.

The GNU extensions fully support the corresponding ISO standards.

Options such as **-Wpedantic**, **-pedantic**, and **-pedantic-errors** are used to check whether the ISO standards are strictly complied with. If the syntax does not comply with the ISO standards, a warning is generated. The GNU extension syntax may also trigger warnings.

##### G.C&C++.LANG.02 Use the new language standards.

**[Type]** Recommendation

##### G.C&C++.LANG.03 Explicitly set the char type, either **-fsigned-char** or **-funsigned-char**.

**[Type]** Recommendation

**[Description]** In the x86 environment, char is of the signed type by default. In the ARM64 environment, char is of the unsigned type by default. Generally, use the **-fsigned-char** option to ensure that the compiler can adapt to instruction sets of different platforms.

If char is equivalent to unsigned char (this is the case for some products), you are advised to use the **-funsigned-char** option.

##### G.C&C++.LANG.04 DO NOT enable -fpermissive for C++.

**[Type]** Requirement

**[Description]** The **-fpermissive** option downgrades syntax errors in the C++ code to warnings. Therefore, do not enable this option.

### Warning Options

#### Options

##### G.C&C++.WARN.01 Enable -Wall to check for useful warnings.

**[Type]** Requirement

**[Description]** **-Wall** is a set of useful warning options recognized by the GNU Compiler Collection (GCC), including **-Wpointer-sign**, **-Wframe-address**, **-Wmaybe-uninitialized**, and **-Wint-in-bool-context**. Learn the meanings of these warnings and modify code to clear them. 

##### G.C&C++.WARN.02 Enable -Wextra to check for additional warnings except -Wall. Use -Wno-XXXX to suppress huge numbers of false positives.

**[Type]** Requirement

**[Description]** **-Wextra** is a set of useful warning options except **-Wall**, including **-Wempty-body**, **Wmissing-field-initializers**, and **-Wunused-parameter**.

Enabling **-Wextra** may cause many false positives. Based on the actual test, you can use **-Wno-XXXX** to suppress false positives. For example, if your product has a huge number of false positives for **-Wunused-parameter\-Wmissing-field-initializers**, you can set **-Wextra -Wno-unused-parameter\-Wno-missing-field-initializers**, after being approved by the chief software engineer of the product line.

##### G.C&C++.WARN.03 Enable -Weffc++ to check for Scott Meyers' Effective C++ options.

**[Type]** Recommendation

**[Description]** **-Weffc++** is a set of warning options corresponding to Scott Meyers' Effective C++ options.

#### Warning Suppression

##### G.C&C++.WARN.04 DO NOT enable -w to suppress all warnings.

**[Type]** Requirement

**[Description]** The warnings displayed by the compiler are useful for identifying poor code and obscure bugs. Enabling the **-w** option will suppress all warnings.

##### G.C&C++.WARN.05 DO NOT enable -Wno-XXXX to suppress all warning options contained in -Wall.

**[Type]** Requirement

**[Description]** **-Wall** is a set of useful alarm options recognized by the GCC compiler. Do not use **-Wno-pointer-sign**, **-Wno-frame-address**, **-Wno-maybe-uninitialized**, or **-Wno-int-in-bool-context** to suppress the **-Wpointer-sign**, **-Wframe-address**, **-Wmaybe-uninitialized**, and **-Wint-in-bool-context** options contained in **-Wall**.

##### G.C&C++.WARN.06 DO NOT enable -Wno-error= XXXX to degrade a specific warning that has been upgraded to an error to a warning again.

**[Type]** Requirement

**[Description]** **-Werror=XXXX** escalates a warning to an error. **-Wno-error= XXXX** downgrades a warning that has been escalated to an error to a warning again.

##### G.C&C++.WARN.07 DO NOT enable -Wno-XXXX to suppress the warning options enabled by the compiler by default.

**[Type]** Recommendation

**[Description]** The warning options enabled by the compiler by default are useful options recognized by the GCC, such as **-Wwrite-strings**, **-Wdelete-incomplete**, and **-Wsizeof-array-argument**. Learn the meanings of these warnings and modify code to clear them. 

**[Negative Example]** In the build project of a component, **-Wno-write-strings** is used to suppress the **-Wwrite-strings** warning for 7749 times.

**[Exception]** To ensure build consistency, you can redefine the **\_*****FILE*****\_** macro to eliminate absolute paths. In this case, you can use **-Wno-builtin-macro-redefined** to suppress the **-Wbuiltin-macro-redefined** warning.

#### Warning Escalation

##### G.C&C++.WARN.08 Enable -Werror or -Werror=XXXX to escalate warnings to errors. 

**[Type]** Recommendation

**[Description]** Enable the **-Werror** or **-Werror=XXXX** option to escalate warnings to errors.

If **-Werror** is enabled, all warnings are escalated as errors. Once a warning is generated, the compilation will fail. This helps clear all warnings during development.

If **-Werror=XXXX** is enabled, a specific type of warning is escalated as errors. This helps clear the specified warnings during development. Example: **-Werror=implicit-function-declaration** and **-Werror=format-SEC**.

#### Warning Management

##### G.C&C++.WARN.09 Use unified warning options in a build project.

**[Type]** Requirement

**[Description]** Use unified compilation warning options to ensure the same code quality of each part.

#### Functions

##### G.C&C++.WARN.10 Enable -Wtrampolines to check for trampolines pointed to by nested functions.

**[Type]** Recommendation

**[Description]** With the **-Wtrampolines** option enabled, a warning is generated when a nested function points to a trampoline. A trampoline is a small piece of data or code that is created at runtime and resides on the stack. It contains the address of a nested function and is used to indirectly call the nested function. On some platforms, a trampoline consists of only specially processed data. However, on most platforms, it is made up of code and requires an executable stack. For an executable stack, the CPU reads instructions from the stack and executes the instructions. This makes it possible for attackers to run their code in the stack memory by means of buffer overflow attacks.

**[Negative Example]** Define a nested function **fun** in the **main** function, and use the function pointer to call **fun**.

-  Source program
```
\#include \<stdio.h\> 
int main(){  
    int ret;
    int (\*pfunc)(int a, int b);
    int fun(int a, int b){
      return a + b;
    }
    pfunc = fun;
    ret = pfunc(10, 20);
    printf("test gcc option -Wtrampolines! ret = %d\\n", ret);
    return 0;
} 
```

-  Compiler options
```
gcc -Wtrampolines trampolines.c -o out  
```

-  Compilation result
```
warning: trampoline generated for nested function 'fun' [-Wtrampolines] 
```
**[Exception]** The **-Wtrampolines** option is not supported by xt-xcc and Clang compilers.

##### G.C&C++.WARN.11 Enable -Wformat=2 to check input/output format functions.

**[Type]** Recommendation

**[Description]** **-Wformat=2** is a collection of **-Wformat**, **-Wformat-nonliteral**, **-Wformat-SEC**, and **\-Wformat-y2k**.

1. With the **-Wformat** option enabled, a warning is generated when the parameter type or format of a format function is incorrect.

2. With the **-Wformat-nonliteral** option enabled, a warning is generated when the format string is a non-string constant.

3. **-Wformat-SEC** and **-Wformat-y2k**: If your product has encapsulated input and output framework format functions, declare the format attribute in the API to use the compiler check capabilities. For details, see the following:
[https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html\#Common-Function-Attributes](https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes)

##### G.C&C++.WARN.12 Enable -Wstrict-prototypes to check for unspecified parameter types in the function declaration or definition.

**[Type]** Recommendation

**[Description]** When a function is declared or defined, explicitly specify its parameter type. The compiler checks whether the parameter type in the call matches that in the definition.

**[Negative Example]**

-  Source program
```
\#include \<stdio.h\>
int func(param){  
    return param; 
} 

```
-  Compiler options
```
gcc -Wstrict-prototypes strict_prototypes.c -o out
```
-  Compilation result
```
 warning: function declaration isn't a prototype [-Wstrict-prototypes]  int func(param){ 
```

Related document: SEI CERT C Coding Standard DCL07-C.Include the appropriate type
information in function declarators

#### Binary Consistency

##### G.C&C++.WARN.13 Enable -Wdate-time to check for time macros.

**[Type]** Recommendation

**[Description]** Enable the **-Wdate-time** option to check for **__DATE__**, **TIME**, or **TIMESTAMP** in the code. This ensures binary consistency.

**[Negative Example]**

-  Source program
```
\#include \<stdio.h\> 
int main() {
    printf ("%s %s %s\\n",_DATE_,_TIME_,_TIMESTAMP_);
    return 0;
}  
```
-  Compiler options
```
gcc -Wdate-time datetime.c -o out 
```
-  Compilation result
```
warning:macro "_DATE_" might prevent reproducible builds [-Wdate-time] warning:macro "_TIME_" might prevent reproducible builds [-Wdate-time] warning:macro "_TIMESTAMP_" might prevent reproducible builds [-Wdate-time]
```

#### Statements

##### G.C&C++.WARN.14 Enable -Wfloat-equal to check for equality comparison of floating point numbers.

**[Type]** Requirement

**[Description]** Floating point numbers have precision problems and cannot be accurately determined whether they are equal or not. You are advised to check whether the absolute value of the difference between two numbers is less than the acceptable error. You can use the C function **fabs()** to obtain the absolute value of the difference, and then compare the absolute value with the acceptable error. If the absolute value is less than the acceptable error, the two numbers are equal. Otherwise, they are not equal. Note that no warning is generated when the following comparison operators are used to compare floating point numbers: \>, \<, \>=, and \<=. 

**[Negative Example]**

-  Source program
```
\#include \<stdio.h\> 
int main() {
    double a = 0.3;
    double b = 0.6;
    ouble c = 0.9; 
    if ((a+b) == c) {
        /\* It seems that a+b is equal to c, but actually not. \*/ 
        printf("double equal\\n");
    }    
    return 0;
} 
```

-  Compiler options
```
gcc -Wfloat-equal float_equal.c -o out 
```

In the preceding example, when double-precision floating point numbers are compared, the compiler generates "warning:comparing floating point with == or != is unsafe[-Wfloat-equal]". The correct method is to set an acceptable error range. If the absolute value of the difference between two floating point numbers is within the range, they are determined to be equal.

**[Positive Example]**

-  Source program
```
\#include \<stdio.h\> \#include \<math.h\> \#define EPSILON 1e-6 /
\* Acceptable error range for the comparison of double-precision floating point numbers \*/
int main() {
    double a = 0.3;
    double b = 0.6;
    double c = 0.9;
    if (fabs((a+b)-c) \< EPSILON) {
        printf("double equal\\n");
    }   
    return 0;
} 
```

-  Compiler options

```
gcc -Wfloat-equal float_equal.c -o out
```

##### G.C&C++.WARN.15 Enable -Wswitch-default to check whether the **switch** statement has the default branch.

**[Type]** Recommendation

**[Description]** If the **switch** statement does not have the default branch, a compilation warning is generated under the **-Wswitch-default** option.

**[Negative Example]**

-  Source program
```
enum TintColor{
    RED,  DARK_RED,  GREEN,  LIGHT_GREEN 
};    
void Colorize(enum TintColor Color)  {
    switch (Color)  {
        case RED:  
            /\* code \*/
            break;
        case DARK_RED:
            break;
    }
} 
```
-  Compiler options
```
gcc -Wswitch-default switch_default.c -o out
```
-  Compilation result
```
warning: switch missing default case [-Wswitch-default] switch (Color) 
```

#### Variables

##### G.C&C++.WARN.16 Enable -Wshadow to check variable coverage.

**[Type]** Recommendation

**[Description]** With the **-Wshadow** option enabled, a warning is generated when local variables overwrite global variables and function parameters. A large number of warnings will be generated when this option is enabled in C++. You can determine whether to enable it based on the actual situation.

**[Negative Example]**

-  Source program
```
int num = 0;  
int foo(int a, int b){  
     int num = a + b;
    return num;  
} 

```
-  Compiler options
```
gcc -Wshadow shadow.c -o out 
```
-  Compilation result
```
warning: declaration of 'num' shadows a global declaration [-Wshadow] int num = a + b; 
```

##### G.C&C++.WARN.17 Enable -Wstack-usage=len to set the stack size.

**[Type]** Recommendation

**[Description]** If the stack memory used by a function may exceed the number of bytes specified by **len**, a compilation warning is generated. You can set **len** based on the project requirements.

**[Negative Example]**

-  Source program
``` 
void foo(void) { 
      int arr[1000] = {0};
      return;  
}  
```
-  Compiler options
```
gcc -Wstack-usage=1000 stack_usage.c -o out 
```
-  Compilation result
```
warning: stack usage is 4012 bytes [-Wstack-usage=] void foo(void) { 
```

##### G.C&C++.WARN.18 Enable -Wframe-larger-than=len to set the stack framework size.

**[Type]** Recommendation

**[Description]** If the stack framework of a function exceeds the number of bytes specified by **len**, a compilation warning is generated. You can set **len** based on the project requirements.

**[Negative Example]**

-  Source program
```
void foo(void) {   
    int arr[1000] = {0};   
    return;
} 
```
-  Compiler options
```
gcc -Wframe-larger-than=1000 stack_usage.c -o out 
```
-  Compilation result
```
warning: the frame size of 4000 bytes is larger than 1000 bytes [-Wframe-larger-than=] 
```

##### G.C&C++.WARN.19 DO NOT enable -Wno-return-local-addr and check the returned local variable address.

**[Type]** Recommendation

**[Description]** If a function returns the address of a local variable, the **-Wreturn-local-addr** warning is generated by default during compilation. Do not enable the **-Wno-return-local-addr** option to suppress this warning.

**[Negative Example]**

-  Source program
```
int\* foo() {
    int a=0;
    return \&a; 
} 
```
-  Compiler options
```
gcc -Wreturn-local-addr return_local_addr.c -o out 
```
-  Compilation result
```
warning: function returns address of local variable [-Wreturn-local-addr] return \&a;
```

#### Type Conversion

##### G.C&C++.WARN.20 Enable -Wconversion to check for implicit conversion that results in value changes.

**[Type]** Recommendation

**[Description]** If implicit conversion in the code causes value changes, a compilation warning is generated under the **-Wconversion** option.

Implicit conversions that may cause value changes include: converting a real number with a decimal to an integer, converting an unsigned number to a signed number (or vice versa), and converting a number of a larger type to a smaller type. If explicit conversion is used in the code, no warning is generated under **-Wconversion** during the compilation.

**[Negative Example]**

-  Source program
```
int foo(void) { 
    double num = 1.2;
    return num;  
}  
```
-  Compiler options
```
gcc-Wconversion conversion.c -o out   
```
-  Compilation result
```
warning: conversion from 'double' to 'int' may change value [-Wfloat-conversion] return num; 
```

Do not forcibly convert object pointers from one type to another.

##### G.C&C++.WARN.21 Enable -Wcast-qual to check for missing type qualifier of the target type when the pointer type is forcibly converted.

**[Type]** Recommendation

**[Description]** When the pointer type is forcibly converted, the target type may not contain the type qualifier.

For example, if the const char\* pointer type is forcibly converted to a common char\* pointer type, the type qualifier **const** is not contained. Missing this qualifier may cause modifications to the memory that is not expected to be modified.

**[Negative Example]**

-  Source program
```
static char buf[8]; 
void foo(){
    const char\* ptr = buf;
    char\* q = (char\*)ptr; 
} 
```
-  Compiler options
```
gcc -Wcast-qual cast_qual.c -o out
```
-  Compilation result
```
warning: cast discards 'const' qualifier from pointer target type [-Wcast-qual] char\* q = (char\*)ptr; 
```

##### G.C&C++.WARN.22 Enable -Wcast-align to check for explicit pointer type conversion to prevent the number of bytes used by the target type for address alignment from increasing.

**[Type]** Recommendation

**[Description]** A warning is generated when the number of bytes used by the target type for address alignment increases due to explicit conversion of a pointer type in the source program. For example, on a machine where an integer is aligned to a two- or four-byte boundary, a warning is generated when char \* is converted to int \*.

#### Arrays

##### G.C&C++.WARN.23 Enable -Wvla to check for variable-length arrays.

**[Type]** Recommendation

**[Description]** If the length of an array is a variable, a compilation warning is generated under the **-Wvla** option.

**[Negative Example]**

-  Source program
```
void foo(int len) {
    int arr[len];
}
```
-  Compiler options
```
gcc -Wvla val.c -o out
```
-  Compilation result
```
warning: ISO C90 forbids variable length array 'arr' [-Wvla] int arr[len];
```

#### Invalid Code

##### G.C&C++.WARN.24 Enable -Wunused to check for invalid code.

**[Type]** Recommendation

**[Description]** The **-Wunused** option checks for unused variables, functions, parameters, and aliases in the code. This option contains multiple suboptions, as listed below:

- \-Wunused-but-set-variable

- \-Wunused-function

- \-Wunused-label

- \-Wunused-local-typedefs

- \-Wunused-variable

- \-Wunused-value


Warnings about formal parameters that are not used in the function are generated only when **-Wextra \-Wunused** or **-Wunused-parameter** is enabled.

**[Negative Example]**

-  Source program
```
void foo(void) {
    int a;
}
```
-  Compiler options
```
gcc -Wunused unused.c -o out
```
-  Compilation result
```
warning: unused variable 'a' [-Wunused-variable] int a; 
```

#### Preprocessing

##### G.C&C++.WARN.25 Enable -Wundef to check for undefined identifiers in the \#if statement of preprocessing directives.

**[Type]** Recommendation

**[Description]** When an undefined identifier appears in the \#if statement, a warning is generated.

**[Negative Example]**

-  Source program
```
\#if DEFINE_A_VALUE
\#endif
```
-  Compiler options
```
gcc -Wunused unused.c -o out
```

-  Compilation result
```
warning: "DEFINE_A_VALUE" is not defined, evaluates to 0 [-Wundef] \#if DEFINE_A_VALUE
```

#### Classes

##### G.C&C++.WARN.26 Enable -Wnon-virtual-dtor to check for undefined virtual destructors for the base class.

**[Type]** Recommendation

**[Description]** Destructors of the derived class can be called during polymorphism invocation only when destructors of the base class are virtual.

**[Negative Example]**

-  Source program
```
class Base {
    public: virtual void foo() const = 0;\
    ~Base() {}
};
class Derived: public Base {
    public: virtual void foo() const {}
    Derived() {}
};
```
-  Compiler options
```
gcc-Wnon-virtual-dtor non_virtual_destructors.cpp -o out 
```

-  Compilation result
```
warning: 'class Base' has virtual functions and accessible non-virtual destructor [-Wnon-virtual-dtor]
```

##### G.C&C++.WARN.27 Enable -Wdelete-non-virtual-dtor to check whether the pointer of the base class is used for deletion when no virtual destructor is defined for the base class.

**[Type]** Recommendation

**[Description]** If the pointer of the base class is used for deletion when no virtual destructor is defined for a base class, undefined behavior may occur. Do not enable the **-Wno-delete-non-virtual-dtor** option to suppress this type of warning.

**[Negative Example]**

-  Source program
```
class Base {
    public: virtual void f();
};
class Sub: public Base {
    public: void f(int);
};
int main() {
    Sub\ * sub = new Sub();
    Base\ * base = sub;
    delete base;
}
```
-  Compiler options
```
gcc--Woverloaded-virtual overloaded_virtual.cpp -o out 
```
-  Compilation result
```
warning: deleting object of polymorphic class type 'Base' which has non-virtual destructor might cause undefined behavior [-Wdelete-non-virtual-dtor] delete base;
```

##### G.C&C++.WARN.28 Enable -Woverloaded-virtual to check for hiding virtual functions of the base class.

**[Type]** Recommendation

**[Description]** A derived class redefines the virtual function of the base class, causing that function to be hidden. If this is the case, a warning is generated when **-Woverloaded-virtual** is enabled.

**[Negative Example]**

-  Source program
```
class Base {
    public: virtual void f();
};
class Sub: public Base {
    public: void f(int);
};
```
-  Compiler options
```
gcc--Woverloaded-virtual overloaded_virtual.cpp -o out 
```
-  Compilation result
```
warning: by 'void Sub::f(int)' [-Woverloaded-virtual] void f(int); 
```
### Security Options

#### Options

##### G.C&C++.SEC.01 Enable the stack protection options.

**[Type]** Requirement

**[Description]**

**User-mode Linux**

Application phase: compiler options

Application scope: relocatable files (.o), dynamic libraries, and executable programs.

Syntax: -fstack-protector-all/-fstack-protector-strong

Description: 

In the case of a buffer overflow vulnerability, an attacker can overwrite the return address on the stack to hijack the control flow. When stack protection is enabled, a canary word is inserted between the buffer and the control flow. Generally, this canary word is overwritten when the attacker overwrites the return address. By checking the canary word, you can determine whether an overflow attack occurs.

1\. Enable **-fstack-protector-strong** in GCC 4.9 and later versions.

2\. Enable **-fstack-protector-all** in versions earlier than GCC 4.9.

3\. This feature is not supported in the Wind River Linux 4.3 + MIPS environment.

**Kernel-mode Linux**

Application phase: compiler options

Application scope: kernel mode of the Linux platform

Usage: Enable **CONFIG_CC_STACKPROTECTOR** or **CONFIG_CC_STACKPROTECTOR_STRONG** before kernel compilation.

Description:

In kernel 3.14 and later versions, **CONFIG_CC_STACKPROTECTOR_STRONG** is supported, and **CONFIG_CC_STACKPROTECTOR** (corresponding to **-fstack-protector**) is changed to **CONFIG_CC_STACKPROTECTOR_REGULAR**. In kernel 4.18 and later versions, **CONFIG_CC_STACKPROTECTOR_REGULAR** (corresponding to **-fstack-protector**) is changed to **CONFIG_STACKPROTECTOR**, and **CONFIG_CC_STACKPROTECTOR_STRONG** (corresponding to **-fstack-protector-strong**) is changed to **CONFIG_STACKPROTECTOR_STRONG**.

Exception: You do not need to enable this feature if the OS kernel in use, which must fall into one of the following scenarios, does not support it.

1. The OS version is the latest official version or recommended version.

2. The OS version in a mandatory selection for purposes of product compatibility.

3. The OS version cannot be upgraded due to commercial reasons.

**LiteOS**

Application phase: compiler options

Application scope: LiteOS V200R003C00 and later versions

Syntax: -fstack-protector-all/-fstack-protector-strong

Description: 

1. Enable **-fstack-protector-strong** in GCC 4.9 and later versions.

2. Enable **-fstack-protector-all** in versions earlier than GCC 4.9.

Exception: You do not need to enable this feature if the compiler does not provide this option or hardware stack protection is supported, as described below:

1. Versions earlier than IAR 8.20 do not support stack protection.

2. Hardware stack protection is provided. For example, some products in the ARC architecture can provide hardware stack protection, and hardware exceptions are triggered in the case of stack overflow.

##### G.C&C++.SEC.02 Enable the ASLR option.

**[Type]** Requirement

Type for the high address space layout randomization (ASLR) and force ASLR option on the Windows platform: Recommendation

**[Description]**

**User-mode Linux**

a. Run the **echo 2 \>/proc/sys/kernel/randomize_va_space** command to enable the system randomization configuration.

Application phase: runtime system configuration

Application scope: heap, stack, and memory mapping segment (mmap base address, shared libraries, and vDSO page)

Syntax: echo 2 \>/proc/sys/kernel/randomize_va_space

Description:

ASLR is a security technique used to prevent the exploit of buffer overflow vulnerabilities. It randomizes the layout of linear regions such as heaps, stacks, and shared libraries, making it harder for attackers to predict target addresses and preventing them from locating attack code, which leads to reduced overflow attacks. When **randomize_va_space** is set to **1**, the stack, data segment, and vDSO are randomized. When **randomize_va_space** is set to **2**, the heap address is also randomized.

To use the highest level ASLR, set **randomize_va_space** to **2**.

b. Enable the PIC option to randomly load dynamic libraries.

Application phase: compiler options

Application scope: dynamic libraries

Syntax: –fPIC(-fpic)

Description:

The position-independent code (PIC) option implements code segment relocation on a data segment, so the code segment does not change when .so files are being loaded. In this case, all processes share a code segment copy.

Both the **\-fPIC** and **-fpic** options ensure that GCC produces PIC. The only difference is that **-fPIC** produces larger code whereas **-fpic** produces smaller code.

c. Enable the PIE option to randomly load executable files.

Application phase: compile options and link options

Application scope: executable programs

Syntax: –fPIE (-fpie) -pie

Description:

Position-independent executable (PIE) files can be loaded randomly in the same manner as shared libraries during loading and execution. The PIE can effectively reduce the success rate of fixed address attacks and buffer overflow attacks.

(1) Check whether hot patch versions support the PIE options. If not, do not use any PIE option.

(2) **-fPIE** is a compiler option, and **-pie** is a link option.

(3) **-fPIE** produces larger code, whereas **-fpic** produces smaller code.

**LiteOS**

a. Enable random loading of code segments and data segments.

Application phase: compiler options, link options, and runtime system configuration

Application scope: LiteOS V200R003C00 and later versions

Usage: Compile the image into a random image, and then randomly correct the address during image loading.

Description: 

1. This feature depends on the bootloader that supports random address loading and depends on the MMU and DDR space.

2. When this feature is enabled, the performance decreases by about 10%.

3. The **-fPIE** and **-pie** options use the Global Offset Table (GOT) to implement address randomization. Both GCC and in-house HCC compilers support this feature.

4. If the cost is high and cannot be implemented, provide specific data to the TMG for review.

Exception: You do not need to enable this feature in the case of product hardware design or startup process restrictions, as described below:

1. XIP scenario, where the system directly runs on the flash memory.

2. ROM-based scenario, that is, all or part of the code is ROM-based and cannot be reloaded.

3. The bootloader does not support random address loading.

b. Enable random loading of dynamic libraries.

Application phase: compiler options

Application scope: LiteOS V200R003C00 and later versions

Syntax: -fPIC

Description: **-fPIC** is used in the dynamic library compilation phase.

##### G.C&C++.SEC.03 Enable GOT RELRO.

**[Type]** Requirement

**[Description]**

**User-mode Linux**

a. Partial RELRO

Application phase: link options

Application scope: dynamic libraries and executable programs

Syntax: -Wl,-z,relro

Description:

A dynamically linked executable and linkable format (ELF) binary uses the GOT to dynamically resolve functions in shared libraries. Attackers can leverage the buffer overflow to modify the function addresses of GOT entries in an attempt to attack the system. By adding the Relocation Read-Only (RELRO) option, you can prevent the GOT from being maliciously overwritten.

b. Full RELRO

Application phase: link options

Application scope: dynamic libraries and executable programs

Syntax: -Wl,-z,now

Description:

After partial RELRO is enabled and then the now option is enabled, full RELRO can be implemented. In other words, **-Wl,-z,relro,-z,now** is used to implement full RELRO. It can defend against Return to Procedural Linkage Table (Ret2PLT) attacks, but not buffer overflow attacks.

If your product uses a large number of functions in shared libraries, applying RELRO will slow down program loading (startup), but it does not affect the runtime performance.

##### G.C&C++.SEC.04 Enable the non-executable stack option/data execution protection option to implement non-executable stack protection.

**[Type]** Requirement

**[Description]**

**User-mode Linux**

Application phase: link options

Application scope: dynamic libraries and executable programs

Syntax: -Wl,-z,noexecstack

Description:

1. If there are nested functions, functional errors may occur. In this case, use **-Wtrampolines** to check the code. The version must be GCC 4.6.4 or later.
2. Wind River Linux 4.3 does not support this feature. 
3. Wind River Linux 6 + MIPS does not support this feature.

**LiteOS**

Application phase: runtime system configuration

Application scope: LiteOS V200R003C00 and later versions

Usage: The runtime configuration stack cannot be executed, and the data segment (BSS and DATA) cannot be executed.

Description: This feature requires the hardware to support memory protection units such as MMU, MPU, and PMP.

##### G.C&C++.SEC.05 Use the -s option or the strip tool to remove the symbol tables.

**[Type]** Requirement for user-mode Linux and recommendation for other platforms

**[Description]**

**User-mode Linux**

Application phase: link options

Application scope: dynamic libraries and executable programs

Usage: -s (strip tool)

Description:

Symbols play a vital role in the linking process. The essence of a linking process is to link multiple target files together. A symbol can be regarded as the adhesive for linking. The entire linking process is completed based on symbols. After linking is complete, the symbol table will no longer affect the running of executable files. Instead, it can be exploited by attackers. Therefore, deleting the symbol table can help defend against hacker attacks. In addition, it can help reduce the file size.

1. For static libraries, relocatable files (.o) cannot be stripped. Otherwise, compilation errors occur. The symbol table can be removed only for products involving ELF executable files and dynamic libraries.

2. For components and platforms that are delivered only to internal products, a formal mechanism must be provided to instruct downstream products to delete the symbol table in the release phase.

3. Stripping affects the locating of network problems and hot patches. Therefore, the versions before and after stripping must be synchronized in the build process. That is, the versions that are not stripped must be reserved locally for patch making and online commissioning. The following solutions can be used:

    3.1 During compilation, the executor generates executable files and dynamic library versions whose symbol tables are not stripped. The versions are archived to the VMP (CMC) for hot patches.

    3.2 Use the strip tool to delete symbol tables from dynamic libraries and executable files.

    3.3 The executable files and dynamic libraries with symbol tables removed can be compressed to the startup software package.

4. The strip tool and the **-s** option can achieve the same effect of removing the symbol table. If the **-s** option is used, the version will be compiled and built twice. You are advised to use the strip tool before release. The strip level is the default value, for example, stripbin.out.

**LiteOS**

Application phase: link options

Application scope: LiteOS V200R003C00 and later versions

Syntax: -s(strip)

Description: The compilation result of LiteOS products for burning is a .bin file, which does not contain symbol table. Therefore, you are advised not to enable this feature.

##### G.C&C++.SEC.06 Do not use the Run-time Search Path option.

**[Type]** Requirement

**[Description]**

**User-mode Linux**

Application phase: link options

Application scope: dynamic libraries and executable programs

Syntax: -Wl,--disable-new-dtags,--rpath,/libpath1:/libpath2;-Wl,--enable-new-dtags,--rpath,/libpath1:/libpath2

Description:

This option is used to protect against the substitute of the **LD_LIBRARY_PATH** for a dynamic library with the same name. This option specifies a path for the runtime dynamic library search, which has a higher search priority than the path specified by **LD_LIBRARY_PATH**. When an executable file searches for a dynamic library at run time, it first searches the path specified by **--rpath** and then searches the path specified by **LD_LIBRARY_PATH**. In the case **LD_LIBRARY_PATH =[attackpath]**, using this option can effectively prevent against the substitute of the **LD_LIBRARY_PATH** for a dynamic library with the same name. However, this option has limitations. For example, if the specified path is not secure, common users can use malicious programs to replace normal programs in these directories, causing privilege escalation and subsequently resulting in insecure path vulnerabilities.

##### G.C&C++.SEC.07 Enable write protection for code segments and data segments.

**[Type]** Recommendation

**[Description]**

**LiteOS**

a. Configure write protection for code segments and read-only data segments.

Application phase: runtime system configuration

Application scope: LiteOS V200R003C00 and later versions

Usage: The runtime configuration code segment and read-only data segment cannot be modified.

Description: This feature requires the hardware to support memory protection units such as MMU, MPU, and PMP.

##### G.C&C++.SEC.10 Enable the compiler macro FORTIFY_SOURCE to enable the FS option.

**[Type]** Recommendation

**[Description]**

**User-mode Linux**

Application phase: compiler options

Syntax: -D_FORTIFY_SOURCE=2 -O2

Description:

When a program uses a static buffer with a fixed size, adding this option will allow the compiler or runtime library to check the call of related functions at compile time or run time.

In principle, the recommended level is -O2, which delivers a better performance optimization effect than O1. If the product is based on O2, -O1 can be used.

Add the option to a branch version first and conduct performance testing. Then determine whether to add the option to the mainline version based on the test result.

**LiteOS**

Application phase: compiler options

Application scope: LiteOS V200R003C00 and later versions

Syntax: -D_FORTIFY_SOURCE=2 -O2

Description: 

1. The benefits of the option are related to the implementation of the library.

2. Currently, LiteOS uses the musl library. If the product uses another library that supports related functionalities, enable the option as required.

Exception: You do not need to enable this option if the library does not support this feature, as described below:

1. Setting D_FORTIFY_SOURCE=2 for the musl library does not take effect, which may cause misleading. Therefore, you do not need to enable D_FORTIFY_SOURCE.

##### G.C&C++.SEC.11 Enable the ftrapv option to detect integer overflow.

**[Type]** Recommendation

**[Description]**

User-mode Linux and LiteOS

Application phase: compiler options

Syntax: -ftrapv

After the **-ftrapv** option is used, the addition, subtraction, and multiplication operations on signed integers are performed by using functions contained in a GCC library libgcc.c instead of CPU instructions.

Using this option greatly affects the performance. You are not advised enabling the option in the release version.

##### G.C&C++.SEC.13 Enable the stack check option.

**[Level]**

Recommendation for user-mode Linux

Requirement (disabled) for LiteOS

**[Description]**

**User-mode Linux**

Application phase: compiler options

Application scope: relocatable files, dynamic libraries, and executable programs.

Syntax: -fstack-check

Description:

The **stack-check** option checks the stack space in a program at compile time. If the stack space exceeds the alarm threshold, an alarm is generated. Then, an extra instruction is generated in the program to check whether the stack overflows at run time. The **stack-check** option sets a secure buffer at the lowest bottom of each stack. If the stack space applied in the function enters the security buffer, a Storage_Error exception is triggered. However, the generated code does not process exceptions. If an exception is detected, a message is sent to notify the OS. It ensures that the OS can detect stack extension.

Using this option greatly affects the performance. You are advised to enable the option in the debug version, but not the release version.

Implementation suggestion: optional

**LiteOS**

Application phase: compiler options

Application scope: LiteOS V100R003C00 and later versions

Syntax: -fstack-check

Description: After the stack check option is enabled, the program may access an invalid address, causing execution exceptions. Therefore, do not enable it on the LiteOS platform.

### Optimization Options

#### Options

##### P.C&C++.01 Select an appropriate optimization level based on the actual test result.

**[Description]** Based on the actual test result, try different code optimization options to see if they are really faster for the program.

##### G.C&C++.OPT.01 Preferentially select -O2, -Os, and -O3.

**[Type]** Recommendation

##### G.C&C++.OPT.02 Use -fno-strict-aliasing to disable strict alias optimization when many pointers of different types need to be converted.

**[Type]** Recommendation

**[Description]** **-O2** of GCC enables **-fstrict-aliasing** for strict alias rule optimization. The compiler assumes that the same memory address will never store different types of data. This optimization option is relatively radical. To avoid optimization issues caused by the conversion between pointers of different types in the code, you can use **-fno-strict-aliasing** to disable the optimization. A good practice is to modify the code to follow strict alias rules.

Using the **-fno-strict-aliasing** option may affect product performance. For example, in the test of a performance-sensitive component of a product, the performance of **-O2 \-fno-strict-aliasing** decreases by 9% compared with **-O2**.

##### G.C&C++.OPT.03 In the x86/ARM architecture, use -fno-omit-frame-pointer to disable stack frame pointer (SFP) optimization for DOPRA-based products.

**[Type]** Recommendation

**[Description]** **-fno-omit-frame-pointer**: The -O (-O1) option of GCC
enables the **-fomit-frame-pointer** optimization option, that is, removing the frame pointer used during function invoking. This optimization makes the code difficult to debug. You are advised to disable the optimization by using the **-fno-omit-frame-pointer** option.

You need to balance performance optimization and debugging information retention.

### Code Generation Options

#### Options

##### G.C&C++.CDG.01 Use -fno-common to check for uninitialized global variables in the data segment of the target file.

**[Type]** Requirement

**[Description]** With the **-fno-common** option enabled, a warning is generated when an uninitialized global variable placed in the data segment of the target file is declared in two compilation units. Defining multiple temporary global variables increases the difficulty in code maintenance, reduce the linking speed, and consume more space.

##### G.C&C++.CDG.02: Use -freg-struct-return to return a struct in the register.

**[Type]** Recommendation

**[Description]** With the **-freg-struct-return** option, the register returns the struct and union.

With the **-fpcc-struct-return** option, the memory instead of the register is used to return a struct and union (either short or long).

You are advised to use the register to return the struct and union. For a small struct, this is more efficient than **-fpcc-struct-return**.

If neither **-fpcc-struct-return** nor **-freg-struct-return** is used, GNU CC uses the standard rules specified by the target machine. If there is no standard rule, GNU CC uses **-fpcc-struct-return** by default except on the machine where GNU CC is the main compiler. If a standard can be selected, the register return mode is selected.

Note that this option affects binary compatibility and should be unified for the entire product.

##### G.C&C++.CDG.03 Use -fvisibility=hidden to set the visibility of symbols in the default ELF image to hidden.

**[Type]** Recommendation

**[Description]** The **-fvisibility=hidden** option makes only APIs in the dynamic library externally visible, effectively implementing binary modularization. This option helps increase the speed of dynamic library linking and loading and prevent symbol conflicts. However, after this option is enabled, the cost of patching the module function needs to be considered because the original global symbol now has the LOCAL attribute, the name needs to be changed when the patch is installed (the DOPRA patch specification has detailed naming rules), and the patch building cost will increase. Balance the benefits against the costs before enabling this option.

##### G.C&C++.CDG.04 Use -fstrong-eval-order to enable the expression calculation sequence rule.

**[Type]** Recommendation

**[Description]** The **-fstrong-eval-order** option determines the calculation sequence of subexpressions based on C++17 specifications. For example, when the option is not enabled,
the expression T().m_i = A().B() may generate the evaluation sequence A() T() B(), which is different from that expected. This option is automatically enabled when **-std=c++17** is enabled. However, **-std=c++14** is used in GCC 7.3 by default. You are advised to enable this option explicitly to reduce unexpected behavior.

### General Options

#### Options

##### G.C&C++.OVA.01 Enable the general option -pipe.

**[Type]** Recommendation

**[Description]** With the **-pipe** option enabled, multiple pipes are concurrently used during compilation to shorten compilation time.

### Architecture Options

#### Options

##### G.C&C++.MD.01 Explicitly specify the following architecture options for embedded software.

1.  Soft and hard floating points (added or not added based on CPU-supported types)

2.  Instruction set (such as march=armv7-a and march=armv8-a)

**[Type]** Requirement

### Link Options

#### Options

##### G.C&C++.LNK.01 Enable the link options -Wl,-Bsymbolic, -rdynamic, and -Wl,--no-undefined.

**[Type]** Recommendation

**[Description]** With the **-Wl,-Bsymbolic** option enabled, the symbol with the same name preferentially uses the local .so file to reduce GOT redirections. 
The **-rdynamic** option resolves the reverse dependency problem of dlopen. The .bin file returns symbol names through addresses. If this option is disabled, backtrace_symbol returns an address that cannot be used for locating. This option increases the size of the .bin file.

The **-Wl,--no-undefined** option identifies runtime loading errors in the linking period. If this option is enabled, the linking time is prolonged due to dependency verification in the linking period. If dependency libraries specified by **-l** are incomplete, functional errors may occur. You need to balance between performance and functions.


### Debugging Options
#### Options

##### G.C&C++.DBG.01 DO NOT carry debugging information during version release build.

**[Type]** Requirement

**[Description]** The debugging information refers to the symbol table and the detailed debugging information table. According to the security regulations, the debugging information is not mandatory for running and should be deleted from the release package. However, the information loss adversely affects maintenance and debugging, such as hot patches, perf analysis, and stack capture.

If the **-s** link option is used, no debugging information is generated. Note that the build-id of the component generated by this method is different from that of the rebuilt components without the **-s** option, and therefore it cannot be directly used to locate faults in the GDB. You can also use **objcopy --only-keep-debug \<target\> \<xxx.dbg\>** and **objcopy objcopy --strip-unneeded \<target\>** to separate debugging symbols after linking. In this way, the deliverables do not contain debugging information.

If **-g** is enabled in the compilation phase to generate a detailed debugging information table, binary differences may occur in different directories due to the absolute path information of the source code. In this case, you can use **-fdebug-prefix-map=old=new** to map the absolute path to a relative path.

### Compiler Macros
#### Options

##### G.C&C++.PRE.01 Specify a specific purpose of each -D compiler macro and create a list of -D compiler macros. 

**[Type]** Requirement

**[Description]** Each time a -D compiler macro is added, additional testing is required. Verify that the code modifications made on each software -D compiler macro are applicable to other -D compiler macros. First, for all -D compiler macros, software build is required to eliminate compilation errors. Second, complete testing is mandatory for all -D compiler macros.

Delete all unused -D compiler macros.

### Other
#### Options

##### G.C&C++.OTH.01 DO NOT use duplicate or inclusion compiler options in a build project.

**[Type]** Recommendation

**[Description]** Duplicate compiler options cause redundant information and hinder maintenance. If the compiler options have different parameters, the source file may be compiled in a way different than initially expected.

Using compiler options with inclusion relationships also causes redundancy. For example, **-Wall** contains more than 40 sub-warning options, and **-O** contains more than 40 sub-optimization options. When they are used together with sub-options, redundancy occurs.

**[Negative Example]** A component takes the value of the compiler optimization option **-O** for 7055 times, and multiple **-O** options, for example, **-O2...-O6** and **-O2...-O3**, exist in a build project.

\# The use of **-Wall** and **-Waddress** at the same time causes redundancy.

gcc -Wall -Waddress -c test.c -o test.o

\# The use of **-O** and **-fauto-inc-dec** at the same time causes redundancy.

gcc -O -fauto-inc-dec -c test.c -o test.o

##### G.C&C++.OTH.02 DO NOT use conflicting options.

**[Type]** Recommendation

**[Description]** Most **-f** and **-W** have two opposite options,
such as **-fname** and **-fno-name**, as well as **-Wname** and **-Wno-name**. If they are referenced at the same time, conflicts occur, which is confusing and inconvenient for maintenance.

**[Negative Example]**

\# Reference both **-fomit-frame-pointer** and **-fno-omit-frame-pointer**.

```
set(CMAKE_C_FLAGS "-MD -MF -Wall -save-temps -fverbose-asm -fsigned-char
\-fomit-frame-pointer -fno-stack-protector \\

\-fno-delete-null-pointer-checks -fno-common -freg-struct-return -O2
\-fno-omit-frame-pointer -fno-strength-reduce" )
```

##### G.C&C++.OTH.03 Compiler options are compiled in the following sequence: optimization levels (such as -O2) + general options + warning options + language options + code generation options + architecture options (MD-dependent options) + optimization options + security options + custom macros.

**[Type]** Recommendation

**[Description]** Place compiler option sets prior to specific options. For example, write **-Wall** before **-Wformat=2**.

**[Positive Example]**

```
\# Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.  
\# toolchain for ARMA15(without FPU)HI1381/HI1215  
\# cpu_family = arm  
\# bit_width_in_run = 32  
\# cpu_core = a15  
\# compile flags  
set(CC_OPT_LEVEL "-O2")  
set(CC_OVERALL_FLAGS "-pipe")  
set(CC_WARN_FLAGS "-Wall -Wextra -Wdate-time -Wtrampolines -Wfloat-equal
\-Wshadow -Wformat=2")  
set(CC_LANGUAGE_FLAGS "-fsigned-char")  
set(CC_CDG_FLAGS "-fno-common -freg-struct-return")  
set(CC_MD_DEPENDENT_FLAGS "-mfloat-abi=soft -march=armv7-a -mtune=cortex-a15")  
set(CC_OPT_FLAGS "-fno-strict-aliasing -fno-omit-frame-pointer")  
set(CC_SEC_FLAGS "-fPIC -fstack-protector-strong --param=ssp-buffer-size=4")  
set(CC_DEFINE_FLAGS "-DXXXXX")  
set(CC_ALL_OPTIONS "\${CC_OPT_LEVEL} \${CC_OVERALL_FLAGS} \${CC_WARN_FLAGS}
\${CC_LANNGUAGE_FLAGS} \\  
\${CC_CDG_FLAGS} \${CC_MD_DEPENDENT_FLAGS} \${CC_OPT_FLAGS} \${CC_SEC_FLAGS}
\${CC_DEFINE_FLAGS}")

\# public link flags  
set(PUBLIC_LNK_FLAGS "-rdynamic -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now")

\# link flag for module  
set(SHARED_LNK_FLAGS "-shared \${PUBLIC_LNK_FLAGS}")  
set(PIE_EXE_LNK_FLAGS "-pie \${PUBLIC_LNK_FLAGS}")

```

## Java Compiler Options

### Language Level
#### Options

##### G.JAVA.LANG.01 Use the same Java compiler language level for each delivery unit, and use the same language level as that of the Java version in use.

**[Type]** Requirement

**[Description]** If the compiler language levels of multiple modules are different, different compiler options need to be configured for these modules. Consequently, the compilation scripts are inconsistent.

If the compiler language level corresponding to the Java version is used, a warning is displayed during compilation when the code is not recommended by the Java version. For example, when you use a Java 7 API, which is annotated as @Deprecated and replaced with a new API in Java 8, a warning is display during compilation if the compiler language level 8 is used.

### Maven
#### Options

##### G.JAVA.MAVEN.01 DO NOT use **-X** during version release to avoid generating a large number of debug logs.

**[Type]** Requirement

**[Description]** **-X** is a debug option. If **-X** is enabled, a large number of debug logs will be generated.

### Javac
#### Options

##### G.JAVA.JAVAC.01 DO NOT use -nowarn, -Xlint:none, or -Xlint:name to suppress all or some javac compilation warnings, and DO NOT use -g:none or -g:[keyword list] to suppress all or some debugging information.

**[Type]** Requirement

**[Description]** Compilation warnings help detect code defects and risks in advance. Suppressing compilation warnings brings potential risks to code quality. If the **-g:none** or **-g:[keywordlist]** option is used, too little or too much debugging information is generated, which adversely affects code maintainability or reduces operating efficiency.

**[Exception]** -Xlint:all,-processing 

Annotations processed at run time do not require an annotation processor. Such compilation warnings can be suppressed by using the **-processing** parameter of **-Xlint**.

##### G.JAVA.JAVAC.02 Use -source, -target, and -Xlint:all, and set showWarnings in maven-compiler-plugin to true.

**[Type]** Requirement

**[Description]**

**\-source** specifies the Java source file version accepted by the compiler.

**\-target** specifies the version of the class file generated by the compiler.

**\-Xlint:all** enables all recommended compilation warnings.

If **showWarnings** is left blank or set to **false**, some compilation warnings cannot be detected.

**[Positive Example]**

```
\<plugin\>

\<groupId\>org.apache.maven.plugins\</groupId\>

\<artifactId\>maven-compiler-plugin\</artifactId\>

\<configuration\>

\<source\>1.8\</source\>

\<target\>1.8\</target\>

\<showWarnings\>true\</showWarnings\>

\<compilerArgs\>

\<arg\>-Xlint:all\</arg\>

\</compilerArgs\>

\</configuration\>

\</plugin\>

```
