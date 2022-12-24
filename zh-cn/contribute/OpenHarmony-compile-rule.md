
# 开源编译规范

## 概述

**简介：**

本规范包括C/C++/Java语言编译选项或系统配置，包括语言选项、警告选项、安全选项、总体选项、代码生成选项、架构选项、优化选项、编译宏等。

**范围：**

本规范规定了C/C++/Java语言在编译构建过程中需要添加的编译选项或系统配置，并对这些选项的作用进行了简单说明。此外，规范中对涉及到的例外场景也进行了阐释说明。

无OS（如裸核、BIOS、Bootloader、BSBC等）需遵循的安全编译选项还未制定，本规范暂不做要求，在相关规范发布之前，建议实施栈保护。

对于本规范未描述的例外情况，如果存在争议，可申请仲裁。

**条款组织方式：**

每个条款一般包含标题、级别、描述等组成部分。条款内容中的“正确示例”表示符合该条款要求的例子，“错误示例”表示不符合该条款要求的例子。

**标题：**

描述本条款的内容。

规范条款分为原则和规则两个类别，原则可以评价规则内容制定的好坏并引导规则进行相应的调整；规则是需要遵从或参考的实践。通过标题前的编号标识出条款的类别为原则或者规则。

标题前的编号规则参见《安全工程规范内容总纲》，其中'P'为单词Principle首字母，'G'为单词Guideline的首字母。原则条款的编号规则为P.Number。规则的编号方式为G.Language.Element. Number，其中Language是语言分类，Element为领域知识中关键元素（本规范中对应的一级目录）的英文字母缩略语。Number是从1开始递增的两位阿拉伯数字，不足两位时高位补0。

| Language | Element | 目录     | Language | Element | 目录         |
|----------|---------|----------|----------|---------|--------------|
| C&C++    | LANG    | 语言选项 | C&C++    | WARN    | 警告选项     |
| C&C++    | SEC     | 安全选项 | C&C++    | CDG     | 代码生成选项 |
| C&C++    | OPT     | 优化选项 | C&C++    | MD      | 架构选项     |
| C&C++    | OVA     | 总体选项 | C&C++    | LNK     | 链接选项     |
| C&C++    | DBG     | 调试选项 | C&C++    | PRE     | 编译宏       |
| C&C++    | OTH     | 其他     | JAVA       | JAVAC     | JAVAC    |
| JAVA     | MAVEN   | MAVEN    |   |    |        |

**级别：**

规则类条款分为两个级别：要求、建议。

-   要求：表示产品原则上应该遵从，但可以按照具体产品版本计划和节奏分期实现。

-   建议：表示该条款属于最佳实践，有助于进一步消解风险，产品可结合业务情况考虑是否纳入。

**描述：**

对条款的进一步描述，描述条款的原理，配合正确和错误的代码例子作为示范。有的条款还包含一些规则不适用的例外场景。

##  C/C++语言编译选项

### 语言选项

##### G.C&C++.LANG.01 显式设置编译的语言标准

**【级别】** 要求

**【描述】** 按时间先后顺序，常用的ISO C标准包括："-std=c90","-std=c99","-std=c11"，对应的GNU扩展标准为"-std=gnu90","-std=gnu99","-std=gnu11"。

按时间先后顺序，常用的ISO C++标准包括："-std=c++98","-std=c++11","-std=c++14","-std=c++1z"，对应的GNU扩展标准为"-std=gnu++98","-std=gnu++11","-std=gnu++14","-std=gnu++1z"。

"-ansi"对应ISO C标准"-std=c90"和ISO C++标准"-std=c++98"。

GNU扩展标准完全支持对应的ISO标准，并在对应的ISO标准上做了扩展。

"-Wpedantic","-pedantic","-pedantic-errors"等选项用于检查是否严格符合对应的ISO标准，对不符合标准的语法进行警告，GNU扩展语法也可能产生警告。

##### G.C&C++.LANG.02 采用较新的语言标准

**【级别】** 建议

##### G.C&C++.LANG.03 显式设置char的类型："-fsigned-char"或"-funsigned-char"

**【级别】** 建议

**【描述】**"-fsigned-char"：x86环境默认char是signed类型，但是ARM64下，默认char是unsigned类型；编译器适配不同平台后端的指令集，故为了考虑平台兼容性，使用该选项。

部分产品可能默认char等效于unsignd char，这种情况下建议使用选项"-funsigned-char"显式设置。

##### G.C&C++.LANG.04 对C++语言，禁止使用"-fpermissive"选项

**【级别】** 要求

**【描述】** 使用"-fpermissive"选项将C++代码中不符合标准的语法error降级成warning。不允许使用该选项，应采用符合标准的C++语法。

### 警告选项

#### 选项集

##### G.C&C++.WARN.01 打开"-Wall"选项，检查有用的警告选项集

**【级别】** 要求

**【描述】** "-Wall"是gcc编译器认可的、很有用的警告选项集合，包括"-Wpointer-sign"、"-Wframe-address"、"-Wmaybe-uninitialized"、"-Wint-in-bool-context"等警告。对于这些警告，应该理解其含义，通过修改代码来消除警告。

##### G.C&C++.WARN.02 打开"-Wextra"选项，检查除"-Wall"外附加的选项集；"-Wextra"中误报较多的选项，可以使用"-Wno-XXXX"屏蔽

**【级别】** 要求

**【描述】** "-Wextra"是除"-Wall"外的一些有用的警告选项集合，包括“-Wempty-body”、"Wmissing-field-initializers"、"-Wunused-parameter"等警告。

"-Wextra"中某些警告可能存在较多误报，产品在实测的基础上，可以使用“-Wno-XXXX”屏蔽其中误报较多的警告，如某产品实测“-Wunused-parameter
\-Wmissing-field-initializers”误报较多，可以设置“-Wextra -Wno-unused-parameter
\-Wno-missing-field-initializers”，由产品线软件总工批准。

##### G.C&C++.WARN.03 打开"-Weffc++"选项，检查Scott Meyers’ Effective C++选项

**【级别】** 建议

**【描述】** "-Weffc++"：Scott Meyers’ Effective C++对应的警告选项集。

#### 警告屏蔽

##### G.C&C++.WARN.04 禁止使用"-w"选项屏蔽所有警告

**【级别】** 要求

**【描述】** 编译器提示的警告通常对于鉴别低劣的代码和隐晦的bug非常有用，使用-w选项会屏蔽了所有的警告。

##### G.C&C++.WARN.05 禁止使用"-Wno-XXXX"抑制"-Wall"包含的所有警告选项

**【级别】** 要求

**【描述】** "-Wall"是gcc编译器认可的、很有用的警告选项集合，禁止使用比如"-Wno-pointer-sign"、"-Wno-frame-address"、"-Wno-maybe-uninitialized"、"-Wno-int-in-bool-context"抑制"-Wall"包含的"-Wpointer-sign"、"-Wframe-address"、"-Wmaybe-uninitialized"、"-Wint-in-bool-context"选项。

##### G.C&C++.WARN.06 禁止使用"-Wno-error= XXXX"选项将已指定的升级错误的警告再次降级成警告

**【级别】** 要求

**【描述】** "-Werror=XXXX"把指定警告升级错误，"-Wno-error=XXXX"：将指定升级成错误的警告再次降级成警告，令人困惑。

##### G.C&C++.WARN.07 避免使用"-Wno-XXXX"抑制编译器缺省打开的编译警告选项

**【级别】** 建议

**【描述】** 编译器缺省打开的编译警告选项，是gcc编译器认可的、很有用的警告选项，如"-Wwrite-strings"、"-Wdelete-incomplete"、"-Wsizeof-array-argument"等。对于这些警告，应该理解其含义，通过修改代码来消除警告。

**【错误示例】** 某组件的构建工程中使用"-Wno-write-strings"抑制"-Wwrite-strings"编译警告7749次。

**例外：** 为了确保构建一致性，可以重定义 \__FILE_\_ 宏，消除绝对路径，可以使用"-Wno-builtin-macro-redefined"抑制"-Wbuiltin-macro-redefined"警告。

#### 警告升级

##### G.C&C++.WARN.08 使用"-Werror"、"-Werror=XXXX"选项把警告当错误处理

**【级别】** 建议

**【描述】** 建议打开"-Werror"、"-Werror=XXXX"选项：把警告当错误处理

"-Werror"：把警告当错误处理，一旦出现警告，编译就会失败，有利于在开发过程中清除所有的警告。

"-Werror=XXXX"：把指定警告当错误处理。使用"-Werror=XXXX"指定某些警告当错误处理，有利于在开发过程中清除所指定的警告。，如"-Werror=implicit-function-declaration"、"-Werror=format-SEC"。

#### 警告管理

##### G.C&C++.WARN.09 同一构建工程中，统一编译警告选项。

**【级别】** 要求

**【描述】** 统一的编译警告选项，确保各部分代码质量统一。

#### 函数

##### G.C&C++.WARN.10 打开"-Wtrampolines"选项，避免内嵌函数生成trampoline

**【级别】** 建议

**【描述】** 内嵌函数是定义于函数中的函数。当内嵌函数指针生成trampoline时，会触发警告。Trampoline是在运行时创建于栈区的一小段数据或代码，它包含了内嵌函数的地址信息，它被用于内嵌函数的间接调用。某些平台上，Trampoline仅仅由一些特殊处理的数据构成。但是，大多数平台上，它是由代码构成的，因此它需要栈可执行来支持。栈变成可执行栈，CPU读取栈上指令执行，攻击者可能通过缓冲区溢出攻击等手段运行栈内存上自己得代码。

**【错误示例】** 在函数main内部定义并通过函数指针调用内嵌函数fun，在”-Wtrampolines”选项下编译警告。

-  源程序：
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

-  编译选项： 
```
gcc -Wtrampolines trampolines.c -o out  
```

-  编译结果：
```
warning:trampoline generated for nested function ‘fun’ [-Wtrampolines]  
```                                                                                                                                     
**例外**："-Wtrampolines" xt-xcc和clang编译器不支持。

##### G.C&C++.WARN.11 打开"-Wformat=2"选项，检查格式化输入/输出函数的安全

**【级别】** 建议

**【描述】** "-Wformat=2"是“-Wformat”、“-Wformat-nonliteral”、“-Wformat-SEC“、”\-Wformat-y2k“的集合。

1. “-Wformat”：格式化函数的参数类型、格式错误时，警告

2. “-Wformat-nonliteral”：当格式化字符串为非字符串常量时，警告

3. “-Wformat-SEC“、” -Wformat-y2k“

对于产品自行封装的格式化输入输出框架函数， 应于 API 声明 format attribute
以利用编译器检查能力， 详细参考
[https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html\#Common-Function-Attributes](https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes)

##### G.C&C++.WARN.12 打开"-Wstrict-prototypes "选项，避免函数在声明或定义中没有指定参数类型

**【级别】** 建议

**【描述】** 在函数的声明或定义时，显式指明函数参数类型，编译器检查函数调用和定义之间参数类型的不匹配情况。

**【错误示例】**

-  源程序：
```
\#include \<stdio.h\>
int func(param){  
    return param; 
} 

``` 
-  编译选项： 
```
gcc -Wstrict-prototypes strict_prototypes.c -o out
``` 
-  编译结果:
```
 warning: function declaration isn't a prototype [-Wstrict-prototypes]  int func(param){ 
```

相关文档：《SEI CERT C Coding Standard》DCL07-C. Include the appropriate type
information in function declarators

#### 二进制一致性

##### G.C&C++.WARN.13 打开"-Wdate-time"选项，避免使用时间宏，确保二进制一致性

**【级别】** 建议

**【描述】** "-Wdate-time"：避免代码使用__DATE__、__TIME__、__TIMESTAMP__，以确保二进制一致性。

**【错误示例】**

-  源程序:
```
\#include \<stdio.h\> 
int main() {
    printf ("%s %s %s\\n",_DATE_,_TIME_,_TIMESTAMP_);
    return 0;
}  
```
-  编译选项:
```
gcc -Wdate-time datetime.c -o out 
```
-  编译结果:
```
warning:macro "_DATE_" might prevent reproducible builds [-Wdate-time] warning:macro "_TIME_" might prevent reproducible builds [-Wdate-time] warning:macro "_TIMESTAMP_" might prevent reproducible builds [-Wdate-time]
```

#### 语句

##### G.C&C++.WARN.14 打开"-Wfloat-equal"选项，避免浮点数相等比较运算

**【级别】** 要求

**【描述】** 由于浮点数存在精度问题，大多数情况下是近似值，不能精确判断是否相等。浮点数相等或不相等比较是不安全的行为，建议通过判断两数之差的绝对值是否小于可接受误差来判断浮点数是否相等，可以使用C语言标准库函数fabs()求两浮点数之差的绝对值，然后与可接受误差比较，如果在可接受误差范围内，则相等，否则不相等。需要特别注意的是：\>、\<、\>=、\<=这四种比较运算符用于浮点数比较不会警告。

**【错误示例】**

-  源程序 ：
```
\#include \<stdio.h\> 
int main() {
    double a = 0.3;
    double b = 0.6;
    ouble c = 0.9; 
    if ((a+b) == c) {
        /\* 看似相等，实际运行时，a+b与c不相等\*/  
        printf("double equal\\n");
    }    
    return 0;
} 
```

-  编译选项： 
```
gcc -Wfloat-equal float_equal.c -o out 
```

上述示例中，进行双精度浮点数相等比较，编译器警告"warning:comparing floating
point with == or != is unsafe[-Wfloat-equal]"，a+b和c看似应该相等，但是程序运行时并不相等，这是因为浮点数是近似表达，a+b和c均为近似值，浮点数的相等性比较不可信，是一种不安全的行为。浮点数正确的比较方式是设定一个可接受的误差精度，如果两个浮点数差值的绝对值在这个误差范围内，就表示相等，正确方式如下：

**【正确示例】** 浮点数相等比较

-  源程序 ：
```
\#include \<stdio.h\> \#include \<math.h\> \#define EPSILON 1e-6 /
\* 双精度比较可接受的误差 \*/ 
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

-  编译选项：

```
gcc -Wfloat-equal float_equal.c -o out
```

##### G.C&C++.WARN.15 打开"-Wswitch-default"选项，确保switch语句有default分支

**【级别】** 建议

**【描述】** 如果switch语句没有default分支，在-Wswitch-default选项下编译警告。

**【错误示例】**

-  源程序：
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
-  编译选项： 
```
gcc -Wswitch-default switch_default.c -o out
```
-  编译结果：
```
warning: switch missing default case [-Wswitch-default] switch (Color) 
```                                                                                               

#### 变量

##### G.C&C++.WARN.16 打开"-Wshadow"选项，检查变量覆盖

**【级别】** 建议

**【描述】** "-Wshadow"：局部变量覆盖全局变量、函数参数等产生的警告。C++语言打开该选项警告较多，团队可以根据实际情况评估是否打开该选项。

**【错误示例】**

-  源程序：
```
int num = 0;  
int foo(int a, int b){  
     int num = a + b;
    return num;  
} 

```
-  编译选项：
```
gcc -Wshadow shadow.c -o out 
```
-  编译结果： 
```
warning: declaration of 'num' shadows a global declaration [-Wshadow] int num = a + b; 
```

##### G.C&C++.WARN.17 打开"-Wstack-usage=len"选项，设置栈大小，避免栈溢出

**【级别】** 建议

**【描述】** 如果函数使用的栈内存可能超过len个字节，编译警告。len的值，团队根据实际情况设置。

**【错误示例】**

-  源程序：
``` 
void foo(void) { 
      int arr[1000] = {0};
      return;  
}  
```
-  编译选项： 
```
gcc -Wstack-usage=1000 stack_usage.c -o out 
```
-  编译结果： 
```
warning: stack usage is 4012 bytes [-Wstack-usage=] void foo(void) { 
```

##### G.C&C++.WARN.18 打开"-Wframe-larger-than=len" 选项，设置栈框架大小，避免栈溢出

**【级别】** 建议

**【描述】** 如果一个函数的栈框架超过len字节，编译警告。len的值，团队根据实际情况设置。

**【错误示例】**

-  源程序： 
```
void foo(void) {   
    int arr[1000] = {0};   
    return;
} 
```
-  编译选项： 
```
gcc -Wframe-larger-than=1000 stack_usage.c -o out 
```
-  编译结果： 
```
warning: the frame size of 4000 bytes is larger than 1000 bytes [-Wframe-larger-than=] 
```

##### G.C&C++.WARN.19 不建议打开“-Wno-return-local-addr“选项，检查返回局部变量地址

**【级别】** 建议

**【描述】** 如果函数返回局部变量的地址，编译时默认产生“-Wreturn-local-addr”警告。禁止开启“-Wno-return-local-addr”选项屏蔽这些警告。

**【错误示例】**

-  源程序：
```
int\* foo() {
    int a=0;
    return \&a; 
} 
```
-  编译选项：
```
gcc -Wreturn-local-addr return_local_addr.c -o out 
```
-  编译结果：
```
warning: function returns address of local variable [-Wreturn-local-addr] return \&a;
```

#### 类型转换

##### G.C&C++.WARN.20 打开"-Wconversion"选项，避免隐式转换改变数值

**【级别】** 建议

**【描述】** 如果代码中的隐式转换会改变数值，在-Wconversion下编译警告。
可能造成数值改变的隐式转换包括：带小数的实数转换成整数，无符号数和有符号数之间的转换，较大类型的数转换成较小类型。需要注意的是，如果代码进行显式强转，在-Wconversion下编译不会警告。

**【错误示例】**

-  源程序：
```
int foo(void) { 
    double num = 1.2;
    return num;  
}  
``` 
-  编译选项：
```
gcc-Wconversion conversion.c -o out   
```
-  编译结果： 
```
warning: conversion from 'double' to 'int' may change value [-Wfloat-conversion] return num; 
```

不同类型的对象指针之间不应进行强制转换。

##### G.C&C++.WARN.21 打开"-Wcast-qual"选项，指针类型强制转换时，避免目标类型丢失类型限定词

**【级别】** 建议

对指针类型强制转化，导致目标类型丢失类型限定词

**【描述】** 如将const char\*指针类型强制转换为普通的char\*时会丢失const类型限定词，const修饰指针是期望该指针指向的内存不可修改，如果强制转化丢失了const类型限定词，就可以通过转换后的结果指针修改原本不期望被修改的内存，失去了对对象const约束的意义。

**【错误示例】**

-  源程序：
```
static char buf[8]; 
void foo(){
    const char\* ptr = buf;
    char\* q = (char\*)ptr; 
} 
```
-  编译选项： 
```
gcc -Wcast-qual cast_qual.c -o out
```
-  编译结果： 
```
warning: cast discards 'const' qualifier from pointer target type [-Wcast-qual] char\* q = (char\*)ptr; 
```

##### G.C&C++.WARN.22 打开“-Wcast-align”选项，检查指针类型强制转换，避免目标所需的地址对齐字节数增加

**【级别】** 建议

**【描述】** 当源程序中某个指针类型强制转换导致目标所需的地址对齐字节数增加时，则产生警告。比如在整型只能以两字节或四字节边界进行访问的机器上，将 char \* 转换为 int \* 则给出警告。

#### 数组

##### G.C&C++.WARN.23 打开“-Wvla”选项，避免变长数组

**【级别】** 建议

**【描述】** 定义数组时，如果数据长度是变量而非固定值，在-Wvla选项下编译警告。

**【错误示例】**

-  源程序：
```
void foo(int len) {
    int arr[len];
}
```  
-  编译选项：
```
gcc -Wvla val.c -o out
```
-  编译结果： 
```
warning: ISO C90 forbids variable length array 'arr' [-Wvla] int arr[len];
``` 

#### 无效代码

##### G.C&C++.WARN.24 打开“-Wunused”选项，避免无效代码

**【级别】** 建议

**【描述】** -Wunused选项检查代码中未使用的变量、函数、参数、别名等问题。-Wunused选项包含了多个针对某种类型对象未使用的子选项：

\-Wunused-but-set-variable

\-Wunused-function

\-Wunused-label

\-Wunused-local-typedefs

\-Wunused-variable

\-Wunused-value

需要注意的是，需要使用-Wextra \-Wunused或者-Wunused-parameter，才能对函数中未使用的形参警告。

**【错误示例】**

-  源程序：
```
void foo(void) {
    int a;
}
``` 
-  编译选项： 
```
gcc -Wunused unused.c -o out
``` 
-  编译结果： 
```
warning: unused variable 'a' [-Wunused-variable] int a; 
```

#### 预处理

##### G.C&C++.WARN.25 打开“-Wundef ”选项，避免预编译指令\#if语句中出现未定义的标识符

**【级别】** 建议

**【描述】** 当一个没有定义的标识符出现在 \#if 中时，给出警告。

**【错误示例】**

-  源程序：
```
\#if DEFINE_A_VALUE
\#endif
``` 
-  编译选项：
```
gcc -Wunused unused.c -o out
```

-  编译结果：
```
warning: "DEFINE_A_VALUE" is not defined, evaluates to 0 [-Wundef] \#if DEFINE_A_VALUE
```

#### 类

##### G.C&C++.WARN.26 打开“-Wnon-virtual-dtor”选项，避免基类析构函数没有定义虚函数

**【级别】** 建议

**【描述】** 只有基类析构函数是virtual，通过多态调用的时候才能保证派生类的析构函数被调用。

**【错误示例】**

-  源程序 ：
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
-  编译选项：
```
gcc-Wnon-virtual-dtor non_virtual_destructors.cpp -o out 
```

-  编译结果： 
```
warning: 'class Base' has virtual functions and accessible non-virtual destructor [-Wnon-virtual-dtor]
```

##### G.C&C++.WARN.27 打开“-Wdelete-non-virtual-dtor”选项，当基类析构函数没有定义虚函数时，避免通过指向基类的指针来执行删除操作

**【级别】 建议**

**【描述】** 当基类没有定义虚析构函数，指向基类的指针来执行删除操作，可导致未定义的行为。禁止开启“-Wno-delete-non-virtual-dtor”选项屏蔽这些警告。

**【错误示例】**

-  源程序：
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
-  编译选项： 
```
gcc--Woverloaded-virtual overloaded_virtual.cpp -o out 
```
-  编译结果： 
```
warning: deleting object of polymorphic class type 'Base' which has non-virtual destructor might cause undefined behavior [-Wdelete-non-virtual-dtor] delete base;
```

##### G.C&C++.WARN.28 打开"-Woverloaded-virtual"选项，避免隐藏基类虚函数

**【级别】** 建议

**【描述】** 派生类重新定义基类的虚函数，导致基类的虚函数被隐藏。

**【错误示例】**

-  源程序：
```
class Base {
    public: virtual void f();
};
class Sub: public Base {
    public: void f(int);
};
``` 
-  编译选项： 
```
gcc--Woverloaded-virtual overloaded_virtual.cpp -o out 
```
-  编译结果：
```
warning: by 'void Sub::f(int)' [-Woverloaded-virtual] void f(int); 
```
### 安全选项

#### 选项集

##### G.C&C++.SEC.01 打开栈保护选项

**【级别】** 要求

**【描述】**

**Linux平台用户态**

作用阶段：编译选项

作用范围：可重定位文件（.o）、动态库、可执行程序

用法：-fstack-protector-all/-fstack-protector-strong

**说明：** 当存在缓冲区溢出攻击漏洞时，攻击者可以覆盖栈上的返回地址来劫持程序控制流。启用栈保护后，在缓冲区和控制信息间插入一个canary word。攻击者在覆盖返回地址的时候，往往也会覆盖canary word。通过检查canary word的值是否被修改，就可以判断是否发生了溢出攻击。

1\. GCC4.9版本及以上落地-fstack-protector-strong；

2\. GCC4.9版本以下落地-fstack-protector-all。

3\. windriver linux 4.3 + MIPS的环境不支持该特性。

**Linux平台内核**

作用阶段：编译选项

作用范围：Linux平台内核态

用法：内核编译前打开配置CONFIG_CC_STACKPROTECTOR/CONFIG_CC_STACKPROTECTOR_STRONG

**说明:**

内核3.14及以上版本可支持CONFIG_CC_STACKPROTECTOR_STRONG，原有CONFIG_CC_STACKPROTECTOR(对应-fstack-protector)修改为CONFIG_CC_STACKPROTECTOR_REGULAR，内核4.18及以上版本CONFIG_CC_STACKPROTECTOR_REGULAR(对应-fstack-protector)修改为CONFIG_STACKPROTECTOR，CONFIG_CC_STACKPROTECTOR_STRONG（对应-fstack-protector-strong）修改为CONFIG_STACKPROTECTOR_STRONG

受限于OS内核不支持本选项，导致驱动程序也无法使能本选项的情况可例外。其中，所使用的OS内核必须是下列情况中的一种或多种：

1.官方发布的最新版本或者公司推荐的OS版本；

2.由于产品配套（如，兼容客户OS）或兼容现网存量产品，而必须选择的OS版本；

3.由于商务原因（如，实体名单）无法与OS厂商联系并获取新版本，只能使用老版本的场景；

**LiteOS平台**

作用阶段：编译选项

作用范围：LiteOS V200R003C00及之后的版本

用法：-fstack-protector-all/-fstack-protector-strong

**说明：** 1.GCC4.9版本及以上落地-fstack-protector-strong；

2.GCC4.9版本以下落地-fstack-protector-all。

受限于编译器版本不支持本选项或硬件提供类似栈保护的情况可例外。如以下两种情况：

1.由于IAR 8.20版本以下版本不支持任务栈保护，不作要求。

2.使用硬件栈保护的不作要求（如ARC架构下部分产品能够提供硬件栈保护机制，栈溢出时能够触发硬件异常）。

##### G.C&C++.SEC.02 打开地址随机化选项

**【级别】** 要求

windows平台HighASLR & ForceASLR选项实施级别为建议

**【描述】**

**Linux（用户态）**

**a. 使用命令 echo 2 \>/proc/sys/kernel/randomize_va_space 打开系统随机化配置**

**作用阶段：** 运行系统配置

**作用范围：** 堆、栈、内存映射区（mmap基址、shared libraries、vdso页）

**用法：** echo 2 \>/proc/sys/kernel/randomize_va_space

**说明**：

ASLR是一种针对缓冲区溢出的安全保护技术，通过对堆、栈、共享库映射等线性区布局的随机化，增加攻击者预测目的地址的难度，防止攻击者直接定位攻击代码位置，达到阻止溢出攻击的目的。randomize_va_space等于1时，栈、数据段、VDSO会随机化，randomize_va_space等于2时堆地址也会随机化。

需要ASLR开启的级别为最高级别，即randomize_va_space等于2

**b. 打开PIC选项实现动态库随加载**

**作用阶段**：编译选项

**作用范围**：动态库

**用法：** –fPIC(-fpic)

**说明：**

地址无关选项将发生在代码段的重定位移到数据段实现，so文件加载时代码段不会发生任何变化，做到所有进程共用一个代码段副本。

\-fPIC和-fpic均指示GCC产生地址无关代码，唯一的区别是-fPIC产生代码稍大，-fpic产生代码相对较小。

**c. 打开PIE选项实现可执行文件随机加载**

**作用阶段：** 编译链接选项

**作用范围：** 可执行程序

**用法：** –fPIE（-fpie）-pie

**说明：**

具备PIE的可执行文件，在加载执行时可像共享库一样随机加载。有研究表明：PIE可有效降低固定地址类攻击、缓冲溢出类攻击的成功概率。

（1）关注对应的热补丁版本是否支持PIE选项，不支持的场景下不建议使用该选项

（2）-fPIE编译选项，-pie链接选项。

（3）-fPIE产生代码稍大，-fpie产生代码相对较小。

**LiteOS平台**

**a. 配置代码段、数据段随机加载**

**作用阶段：** 编译、链接选项以及运行系统配置

**作用范围：** LiteOS V200R003C00及之后的版本

**用法：** 先编译成可随机的镜像；然后镜像加载时，对地址进行随机修正

**说明：** 1.依赖支持随机地址加载的bootloader，依赖MMU、DDR空间。

2.开启后性能下降10%左右。

3.方案：-fPIE -pie借助GOT表实现地址随机，gcc和自研HCC编译器均可提供支持；

4.开销较大无法落地时，需要业务提供具体的数据到TMG审核。

受限于产品硬件设计或启动流程不支持的情况可例外。如以下三种情况：

1.XIP场景，即系统直接运行于Flash。

2.rom化场景，即全部或部分代码rom化，无法重新加载的场景。

3.bootloader不支持随机地址加载。

**b.配置动态库随机加载**

**作用阶段：** 编译选项

**作用范围：** LiteOS V200R003C00及之后的版本

**用法：** -fPIC

**说明：** 1.动态库编译阶段采用-fPIC。

##### G.C&C++.SEC.03 打开GOT表重定位只读选项

**【级别】** 要求

**【描述】**

**Linux平台-用户态**

**a.部分重定向只读选项：**
 
**作用阶段：** 链接选项

**作用范围：** 动态库、可执行程序

**用法：** -Wl,-z,relro

**说明**：

动态链接的ELF二进制程序使用称为全局偏移表（GOT）的查找表去动态解析位于共享库中的函数。攻击者通过缓冲区溢出修改GOT表项的函数地址值来达到攻击的目的。通过增加RELRO选项，可以防止GOT表被恶意重写。

**b.全部重定向只读选项：**

**作用阶段：** 链接选项

**作用范围：** 动态库、可执行程序

**用法：** -Wl,-z,now

**说明**：

开启部分重定项只读保护后，再开启立即绑定可实现全部重定向只读保护，即：全部重定向只读(GOT表全保护)：-Wl,-z,relro,-z,now 可较好对ret2plt的攻击进行防护，而对诸如缓冲区溢出等攻击无法防范。

对于大量使用共享库中的函数代码产品，在一定程会导致程序装载（启动）阶段缓慢，而运行时性能不会有影响。

##### G.C&C++.SEC.04 打开堆栈不可执行/数据执行保护选项实现堆栈不可执行保护

**【级别】** 要求

**【描述】**

**Linux平台-用户态**

**作用阶段：** 链接选项

**作用范围：** 动态库、可执行程序

**用法：** -Wl,-z,noexecstack

**说明**：

1.如果有内嵌函数，会导致功能错误，需要先用-Wtrampolines进行检测，GCC4.6.4版本及以上。
2.windriver linux 4.3普通版本不支持该特性。  
3.windriver linux 6 + MIPS不支持该特性。

**LiteOS平台**

**作用阶段：** 运行系统配置

**作用范围：** LiteOS V200R003C00及之后的版本

**用法：** 运行时配置堆栈不可执行、数据段(BSS,DATA)不可执行

**说明：** 1.依赖硬件支持MMU/MPU/PMP等内存保护单元。

##### G.C&C++.SEC.05 使用-s选项或者strip工具去除符号表

**【级别】** linux平台-用户态：要求，其它平台：建议。

**【描述】**

**Linux平台-用户态**

**作用阶段：** 链接选项

**作用范围：** 动态库、可执行程序

**用法：** -s(strip工具)

**说明：**

符号在链接过程中，发挥着至关重要的作用，链接过程的本质就是把多个不同的目标文件“粘”到一起，符号可看作链接的粘合剂，整个链接过程正是基于符号才正确完成的。链接完成后，符号表对可执行文件运行已经无任何作用，反而会成为攻击者构造攻击的工具，因此删除符号表可防御黑客攻击。事实上删除符号表除防攻击外，还可对文件减肥，降低文件大小。

1.对于静态库，可重定位文件（.o）不能strip，否则出现编译错误，只涉及ELF可执行文件和动态库交付的产品才可以去除符号表

2.仅交付给产品，并不直接参与公司外部发布的组件和平台，需提供正式机制通知下游产品在发布阶段统一执行删除符号表操作

3.因为strip会影响产品定位网上问题和热补丁，构建流程上需要保证strip前后的版本同步，即需要产品本地保留未strip符号表的版本供补丁制作和网上调测使用。如可采用以下方案：

3.1 执行机在编译的时候，生成未剥离符号表的可执行文件和动态库的版本,版本归档到VMP上(CMC)供产品做热补丁

3.2 使用strip工具对动态库和可执行文件删除符号表

3.3 剥离符号的可执行文件和动态库压缩到启动大包

4.strip工具和-s选项可达到一样的去除符号表的效果，基于-s选项会造成版本两次编译构建，建议发布前直接使用strip工具,strip级别为默认，如stripbin.out。

**LiteOS平台**

**作用阶段：** 链接选项

**作用范围：** LiteOS V200R003C00及之后的版本

**用法：** -s(strip)

**说明：** 1.LiteOS产品最终用于烧录的编译结果为bin文件，本身不存在符号表信息，建议不开启。

##### G.C&C++.SEC.06 禁止使用Run-time Search Path选项

**【级别】** 要求

**【描述】**

**Linux平台-用户态**

**作用阶段：** 链接选项

**作用范围：** 动态库、可执行程序

**用法：** -Wl,--disable-new-dtags,--rpath,/libpath1:/libpath2;-Wl,--enable-new-dtags,--rpath,/libpath1:/libpath2

**说明**：

主要用于防护LD_LIBRARY_PATH替换同名动态库的攻击。通过加入此选项可以指定一个运行时动态库搜索的路径，该路径的搜索优先级高于LD_LIBRARY_PATH指定的路径。可执行文件在运行阶段进行动态库搜索时会首先在--rpath指定的路径查找动态库，然后才会到LD_LIBRARY_PATH指定的路径搜索。因此可以有效防御LD_LIBRARY_PATH=[attackpath]来替换同名动态库的攻击。但是该选项有也很多局限性，如指向的路径不安全，若普通用户可以在这些目录中使用恶意程序替换正常程序，造成权限提升，引发不安全路径漏洞。

##### G.C&C++.SEC.07 打开代码段/数据段写保护选项

**【级别】** 建议

**【描述】**

**LiteOS平台**

**a. 配置代码段、只读数据段写保护**

**作用阶段：** 运行系统配置

**作用范围：** LiteOS V200R003C00及之后的版本

**用法：** 运行时配置代码段、ReadOnly Data段不可修改

**说明：** 1.依赖硬件支持MMU/MPU/PMP等内存保护单元。

##### G.C&C++.SEC.10 启用FORTIFY_SOURCE编译宏来打开FS选项

**【级别】** 建议

**【描述】**

**Linux平台-用户态**

**作用阶段：** 编译选项

**用法：** -D_FORTIFY_SOURCE=2 -O2

**说明**：

程序中使用到静态的固定大小的缓冲区，增加了该选项之后，编译器或运行时库会对相关函数的调用在编译时或运行时进行检查。

原则上推荐级别为-O2（基于性能优化效果优于O1）,若产品基于O2的风险性允许使用-O1。

先在分支版本添加，重点做性能测试，根据测试结果取舍。

**LiteOS平台**

**作用阶段：** 编译选项

**作用范围：** LiteOS V200R003C00及之后的版本

**用法：** -D_FORTIFY_SOURCE=2 -O2

**说明：** 1. 选项收益和lib库实现有关。

2.当前LiteOS使用musl库，如果产品替换支持相关功能的lib库，需按需开启。

受限于lib库不支持情况可例外。如以下情况：

1.musl库配置D_FORTIFY_SOURCE=2没有作用，容易对用户造成误导，可不开启。

##### G.C&C++.SEC.11 打开ftrapv选项来检测整数溢出

**【级别】** 建议

**【描述】**

**Linux平台-用户态、LiteOS平台**

**作用阶段：** 编译选项

**用法**：-ftrapv

使用了-ftrapv选项后，执行带符号的整数间的加、减、乘运算时，不是通过CPU的指令，而是用包含在GCC附属库libgcc.c里的函数来实现。

性能影响较大，建议在Release版本不实施。

##### G.C&C++.SEC.13 打开栈检查选项

**【级别】**

Linux平台-用户态：建议

LiteOS平台：要求（禁用）

**【描述】**

**Linux平台-用户态**

**作用阶段：** 编译选项

**作用范围：** 可重定位文件、动态库、可执行程序

**用法：** -fstack-check

**说明：**

stack-check在编译时检查程序中栈空间，如果超过编译告警阀值则产生告警；然后在程序中生成额外的指令来检查运行时栈不会被溢出，stack-check选项会在每个栈空间最低底部设置一个安全的缓冲区，如果函数中申请的栈空间进入安全缓冲区，则触发一个Storage_Error异常。但它所生成的代码实际上并不处理异常，如果检测到异常则会发出一个消息，通知操作系统处理。它只保证操作系统可以检测到栈扩展。

性能影响较大，建立在Debug版本中实施，Release版本不实施

**实施建议：** 可选

**LiteOS平台**

**作用阶段：** 编译选项

**作用范围：** LiteOS V100R003C00及之后的版本

**用法：** -fstack-check

**说明：** 1.开启后程序会访问非法地址，导致执行异常，因此LiteOS平台下禁止打开栈检查选项。

### 优化选项

#### 选项集

##### P.C&C++.01 在实测的基础上，选择合适优化等级和各种优化选项

**【描述】** 在实测的基础上，尝试各种代码优化选项，以查看它们是否确实为生成程序更快。

##### G.C&C++.OPT.01 优化等级建议选"-O2"、"-Os"、"-O3"

**【级别】** 建议

##### G.C&C++.OPT.02 当代码中存在较多的不同类型指针互转时，使用"-fno-strict-aliasing"选项关闭严格别名优化

**【级别】** 建议

**【描述】** GCC的"-O2"打开"-fstrict-aliasing"严格别名规则优化：编译器假定相同的内存地址绝不会存放不同类型的数据，该优化选项相对激进。为了避免代码中不同类型指针互转导致优化问题，可以使用"-fno-strict-aliasing"关闭优化；最好的方式是修改代码，遵守严格别名规则。

注意使用"-fno-strict-aliasing"选项可能会影响产品性能，如某产品一个性能敏感组件实测，"-O2
\-fno-strict-aliasing"相比"-O2"会有性能下降，测的数据最多下降有9%。

##### G.C&C++.OPT.03 X86/ARM架构下，基于DOPRA平台的产品建议使用"-fno-omit-frame-pointer"选项关闭去SFP（Stack Frame Pointer）优化

**【级别】** 建议

**【描述】** "-fno-omit-frame-pointer"：GCC的“-O”
("-O1")会打开"-fomit-frame-pointer"优化选项，也就是去掉函数调用时的frame
pointer，优化会导致代码难以调试，建议通过选项"-fno-omit-frame-pointer"禁止该项优化。

产品需要在性能优化和保留调试信息进行权衡。

### 代码生成选项

#### 选项集

##### G.C&C++.CDG.01 未初始化的全局变量放置在目标文件的数据段："-fno-common"

**【级别】** 要求

**【描述】** "-fno-common"：未初始化的全局变量放置在目标文件的数据段，两个不同的编译单元中声明了同一个全局变量导致警告。多个临时的全局变量定义会增加代码维护难度，降低链接速度和增加空间消耗。

##### G.C&C++.CDG.02 将结构体放在寄存器中直接返回："-freg-struct-return"

**【级别】** 建议

**【描述】** "-freg-struct-return"：采用寄存器返回结构与联合值。

“-fpcc-struct-return”：在返回短的结构和联合值时，与较长的值一样，使用内存而非寄存器。

尽可能在寄存器中返回结构和联合值。对小结构而言，这比“-fpcc-struct-return”效率更高。
如果既未使用“-fpcc-struct-return”， 又未使用相反的“-freg-struct-return ”， GNU
CC缺省使用目标机器指定的标准规则。如果没有标准规则， 除了在GNUCC为主要编译器的机器上，GNU CC缺省采用“-fpcc-struct-return”，在可以选择标准的情况下， 我们选择了更高效的寄存器返 回方式。

注意，此选项影响二进制兼容性，应整个产品统一。

##### G.C&C++.CDG.03 设置默认的ELF镜像中符号的可见性为隐藏："-fvisibility=hidden"

**【级别】** 建议

**【描述】** "-fvisibility=hidden"：可以让动态库中仅API外部可见，有效实现二进制的模块化。使用该选项可以提高动态库链接和加载的速度，防止符号冲突。但该选项加上后,需要考虑对该模块函数打补丁的成本，因为原来的全局符号变成LOCAL属性，对其打补丁时需要重新组名（DOPRA补丁规范有详细的组名规则），构建补丁的成本会增加。是否打开该选项，需要权衡。

##### G.C&C++.CDG.04 启用表达式计算顺序强化规则： “-fstrong-eval-order”

**【级别】** 建议

**【描述】** "-fstrong-eval-order"：按C++17的规格确定子表达式之间的计算顺序，比如表达式
T().m_i = A().B() 在未开启时可能生成指令的求值顺序时 A() T() B() ，不符合常规预期；该选项当启用 "-std=c++17" 时自动开启， 但当前 gcc7.3默认"-std=c++14"，建议显式开启以降低不可预期行为。

### 总体选项

#### 选项集

##### G.C&C++.OVA.01 打开总体选项："-pipe"

**【级别】** 建议

**【描述】** "-pipe" ：编译过程中多管道并发，节省编译时间

### 架构选项

#### 选项集

##### G.C&C++.MD.01 对于嵌入式软件，显式指明如下架构选项

1.  软硬浮点(按照CPU支持类型进行添加或者不添加）

2.  指令集 (如：march=armv7-a/ march=armv8-a)

**【级别】** 要求

### 链接选项

#### 选项集

##### G.C&C++.LNK.01 打开如下链接选项："-Wl,-Bsymbolic"、"-rdynamic"、" -Wl,--no-undefined"

**【级别】** 建议

**【描述】** -Wl,-Bsymbolic：同名符号优先使用本so,减少got表调转  
"-rdynamic"：解决dlopen反向依赖的问题；BIN文件通过地址返回符号名称，需要加，否则backtrace_symbol返回的是地址，不能定位；影响：产品BIN文件增大。

"-Wl,--no-undefined"：可以将运行时加载错误，在链接期提前识别出来。打开该选项，导致链接时间会变长，因为链接期要进行依赖关系校验。如果-l指定依赖库不全，会有功能问题，需要产品权衡。


### 调试选项
#### 选项集

##### G.C&C++.DBG.01 对于版本发布构建，禁止携带调试信息

**【级别】** 要求

**【描述】** 调试信息指 符号表 和
详细调试信息表，根据当前安全规定，调试信息，不是运行所必须，要求发布件删除这些信息，包括符号表，以提升攻击难度；热补丁、perf分析、抓堆栈等维测场景受影响。

使用 "-s" 链接选项可完全不生成调试信息，需注意此方法生成的组件与不加 "-s"
后重新构建生成的组件 build-id 是不一致的，不能直接用来 gdb定位问题；也可以链接后使用 objcopy --only-keep-debug \<target\> \<xxx.dbg\> 加上objcopy objcopy --strip-unneeded \<target\> 方式分离调试符号，同样可达成交付件不含有符号表等调试信息。

如果编译阶段启用了 -g 生成详细调试信息表， 会因含有源代码绝对路径信息造成不同目录下构建的二进制差异， 此时可使用 -fdebug-prefix-map=old=new来将绝对路径映射成相对路径，达成 BEP 要求。

### 编译宏
#### 选项集

##### G.C&C++.PRE.01 明确-D编译宏的具体用途，建立-D编译宏的清单

**【级别】** 要求

**【描述】** 每增加一个-D编译宏，就需要对它进行额外的测试。为每一种软件-D编译宏所作的代码修改，必须验证能否适用于其他-D编译宏。首先必须针对所有的-D编译宏，对软件进行构建，以确保没有编译错误；其次必须针对所有的-D编译宏进行完整的测试。

对于未使用的-D编译宏，应该直接删除。

### 其他
#### 选项集

##### G.C&C++.OTH.01 同一构建工程中，避免使用重复的或包含关系的编译选项

**【级别】** 建议

**【描述】** 重复的编译选项是冗余信息，不利于维护。如果编译选项具有不同的参数，可能导致与初始预期不同的方式编译源文件。

编译选项之间存在包含关系时，同时使用会导致冗余。譬如"-Wall"包含40多个子警告选项，"-O"包含40多个子优化选项，当它们与子选项同时使用时就会导致冗余。

**【错误示例】** 某组件对编译优化选项"-O"取值达到7055次，其中同一构建工程中出现多个"-O"，如"-O2...-O6"、"-O2...-O3"。

\# "-Wall"包含"-Waddress"，同时使用产生冗余

gcc -Wall -Waddress -c test.c -o test.o

\# "-O"包含"-fauto-inc-dec"，同时使用产生冗余

gcc -O -fauto-inc-dec -c test.c -o test.o

##### G.C&C++.OTH.02 避免使用相反冲突的选项

**【级别】** 建议

**【描述】** 大多数'-f'和'-W'有两个相反的互相否定的选项:
\-fname/-fno-name和-Wname/-Wno-name，同时引用导致冲突，令人疑惑，不利于维护。

**【错误示例】**

\#同时引用-fomit-frame-pointer和-fno-omit-frame-pointer

```
set(CMAKE_C_FLAGS "-MD -MF -Wall -save-temps -fverbose-asm -fsigned-char
\-fomit-frame-pointer -fno-stack-protector \\

\-fno-delete-null-pointer-checks -fno-common -freg-struct-return -O2
\-fno-omit-frame-pointer -fno-strength-reduce" )
```

##### G.C&C++.OTH.03 编译选项的编写顺序：优化等级（如-O2）+总体选项+警告选项+语言选项+代码生成选项+架构选项（MD-Dependent Options）+优化选项+安全编译选项+自定义宏

**【级别】** 建议

**【描述】** 有选项集的，先写选项集，例如"-Wall"应该写到"-Wformat=2"前。

**【正确示例】**

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

## Java语言编译选项 

### 语言级别
#### 选项集

##### G.JAVA.LANG.01 每个交付单元使用的Java编译语言级别必须一致，且必须与使用的Java版本对应的编译语言级别一致。

**【级别】** 要求

**【描述】** 不同模块的编译语言级别不一致，这些模块需要配置不同的编译选项，导致构建脚本不一致。

使用与Java版本对应的编译语言级别，可以在编译阶段提示对应Java版本不推荐的编码实践，如Java 8版本将Java 7版本部分可用的API标记为 @Deprecated，推荐用更好的API来替换。当使用编译语言级别8时就会在编译阶段发出警告，代码中使用了将被弃用的API。

### MAVEN
#### 选项集

##### G.JAVA.MAVEN.01 版本发布构建时禁止使用maven 编译选项-X，避免输出大量的debug日志。

**【级别】** 要求

**【描述】** -X是debug选项，会输出大量的debug日志。

### JAVAC
#### 选项集

##### G.JAVA.JAVAC.01 禁止使用的javac编译选项：-nowarn/-Xlint:none/-Xlint:name 选项关闭所有或部分javac编译告警;-g:none/-g:[keyword list]选项关闭全部或指定生成部分调试信息

**【级别】** 要求

**【描述】** 编译告警能够帮助提前发现代码存在的缺陷和风险，关闭编译告警会给代码质量带来隐患;使用-g:none或-g:[keywordlist]会导致生成过少或过多的调试信息，影响可维护性或降低运行效率。

**例外**：-Xlint:all,-processing  
运行时处理的注解不需要注解处理器,产生编译告警可以通过-Xlint的参数-processing进行抑制。

##### G.JAVA.JAVAC.02 必须使用的javac编译选项：-source，-target，-Xlint:all。 同时maven-compiler-plugin的showWarnings属性必须设置为true。

**【级别】** 求

**【描述】**

\-source 指定编译器接受的java源文件版本

\-target 指定编译器生成的class文件版本

\-Xlint:all 使能所有推荐编译告警

showWarnings 属性必须设置为true，不设置或者设置为false时部分编译告警无法检查出来

**【正确示例】**

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

