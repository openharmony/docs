# 方舟字节码基本原理

## 总体设计
### 概述
方舟字节码（Ark Bytecode），是由方舟编译器编译ArkTS/TS/JS生成的，提供给方舟运行时解释执行的二进制文件，字节码中的主要内容是方舟字节码指令。<br>
本文旨在介绍方舟字节码指令相关的设计，将在后续章节中对构成指令的重要概念和具体的指令格式及含义进行说明，帮助开发者了解方舟字节码指令，指导开发者进行指令相关的特性开发工作。<br>
一条方舟字节码指令，由操作码（指令的名称）和指令入参列表组成。操作码包含无前缀的操作码和有前缀的操作码两种情况。寄存器、立即数以及string id/method id/literal id，均可以作为指令的入参，除此之外，部分指令中使用累加器作为默认参数。<br>
方舟字节码中，除寄存器和累加器之外，还存在**全局变量**、**模块（[module](https://262.ecma-international.org/12.0/#sec-ecmascript-language-scripts-and-modules)）命名空间和模块变量**、**词法环境和词法变量**、**补丁变量**4种值存储方式。指令可以使用这4种储值位置中的值作为入参。

### 术语和约束
#### 术语
本文涉及的术语清单：

|     术语      |      说明        |
|   ----------  |    ----------   |
|  acc         |	accumulator，累加器，方舟字节码中一个特殊的寄存器   |
|  bit	|  一个比特，本文中用位表示   |
|  hole	|  还未进行初始化的对象或变量   |
|  id	|  index，索引，是string id/method id/literal id的总称   |
|  string id	|  string index，16位的数字，用于索引到对应的字符串   |
|  method id	|  method index，16位的数字，用于索引到对应的方法   |
|  literal id  |     literal index，16位的数字，用于索引到对应的字面量数组   |
|  lexical environment	|  词法环境，用来存放闭包变量的语义环境   |
|  lexical variable	|  词法变量，词法环境中所存的闭包变量   |

#### 约束
* 本文中所有采用代码形式描述的内容均遵循[ArkTS语言规范](../quick-start/introduction-to-arkts.md)
* 本文仅适用于版本号为12.0.6.0的方舟字节码（版本号为方舟编译器内部保留字段，开发者无需关注）

### 字节码构成
#### 操作码与前缀
方舟字节码中的操作码通常被编码为一个8位的值，因此至多只能有256个操作码。随着方舟编译器运行时功能的演进，字节码的数量也在逐步增加，已经超过了256个。因此，方舟字节码引入了前缀（prefix），将操作码最大宽度从8位扩展到16位。8位操作码（无前缀的）用于表示频繁出现的指令，16位操作码（有前缀的）用于表示出现频率不高的指令。<br>
带前缀的操作码为小端法存储的16位值，由8位操作码和8位前缀组成，编码规则为：操作码左移8位，再与前缀相或。
|     前缀操作码      |      助记符        |      描述        |
|     ----------  |    ----------   |    ----------   |
|  0xfe	  |  throw	|  有条件/无条件的throw指令 |
|  0xfd	  |  wide	|  含有更宽编码宽度的立即数、id或寄存器索引的指令  |
|  0xfc	  |  deprecated	 |  方舟编译器不再会产生的指令，仅用于维护运行时兼容性；<br>本文后续章节中将省略对这些指令的说明 |
|  0xfb	  |  callruntime | 	调用运行时方法的指令  |

前缀操作码的助记符的形式为**前缀助记符.操作码助记符**, 例如，wide.stlexvar。stlexvar指令的操作码是0x0d，前缀wide是0xfd，则此带前缀的指令（wide.stlexvar）的操作码是0x0dfd。

#### 寄存器与累加器
方舟虚拟机模型基于寄存器，所有的寄存器均是虚拟寄存器。当寄存器中存放原始类型的值时，寄存器的宽度是64位；当寄存器中存放对象类型的值时，寄存器的宽度适应为足够宽，以存放对该对象的引用。<br>
方舟字节码中，存在一个名为累加器（accumulator，也简称作acc）的不可见寄存器。acc是许多指令的默认目标寄存器，也是许多指令的默认参数。acc不占用编码宽度，有助于产生更为紧凑的字节码。<br>

示例代码：
```ts
function foo(): number {
    return 1;
}
```
字节码中的相关指令：
```assembly
.function any .foo(any a0, any a1, any a2) {
    ldai 0x1
    return
}
```
指令*ldai 0x1*：将整型字面量1加载到acc中；<br>
指令*return*：将acc中的值返回。

#### 立即数
方舟字节码中部分指令采用常数形式来表示整型数值、双精度浮点型数值、跳转偏移量等数据。这类常数被称为立即数，可以是8位、16位、32位或64位。

#### 方法索引、字符串索引、字面量索引
方舟字节码中存放着源文件中使用到的所有方法、字符串和字面量数组的偏移量。其中，字面量数组中存放着各种字面量数据，例如整型数字、字符串偏移量和方法偏移量。在方舟字节码指令中，这些方法、字符串以及字面量数组的索引都是16位的，分别被称作方法索引（method id）、字符串索引（string id）以及字面量索引（literal id）。这些索引被编码在指令中，以引用方法、字符串和字面量数组。

### 值存储方式
#### 全局变量
在[Script](https://262.ecma-international.org/12.0/#sec-ecmascript-language-scripts-and-modules)编译模式下，全局变量是一个存储在全局唯一的映射中的变量，其键值为全局变量的名称，值为全局变量的值。全局变量可通过全局（global）相关的指令进行访问。<br>

示例代码：
```ts
function foo(): void {
    a += 2;
    b = 5;
}
```
字节码中的相关指令：
```assembly
.function any .foo(any a0, any a1, any a2) {
    tryldglobalbyname 0x0, a
    sta v4
    ldai 0x2
    add2 0x1, v4
    trystglobalbyname 0x2, a
    ldai 0x5
    trystglobalbyname 0x3, b
    ...
}
```
指令*tryldglobalbyname 0x0, a*：将名称为a的全局变量加载进acc，不存在名称为a的全局变量时，抛出异常；<br>
指令*trystglobalbyname 0x2, a*：将acc中的值存放到名称为a的全局变量上，不存在名称为a的全局变量时，抛出异常；<br>
指令*trystglobalbyname 0x3, b*：将acc中的值存放到名称为b的全局变量上，不存在名称为b的全局变量时，抛出异常。<br>
**注意：**<br>
上述指令中出现的0x0，0x2，0x3是方舟运行时内部使用的保留数字，开发者无需关注。

#### 模块命名空间和模块变量
源文件中所有使用到的[模块命名空间](https://262.ecma-international.org/12.0/#module-namespace-exotic-object)（module namespace）都会被编译进一个数组中，指令中使用索引来引用一个模块命名空间。例如，指令*getmodulenamespace 0x1*引用了索引*0x1*处的模块命名空间。<br>
源文件中所有使用到的模块变量（module variable）都会被编译进一个数组中，指令中使用索引来引用一个模块变量。例如，指令*stmodulevar 0x1*引用了索引*0x1*处的模块变量。<br>
在函数中，如果一个模块变量的声明和这个函数在同一个源文件中，则将这个变量称为局部模块变量；否则称为外部模块变量。例如，指令*ldlocalmodulevar*和*ldexternalmodulevar*分别用于加载局部模块变量和外部模块变量。<br>
产生模块指令的相关场景，包括[import](https://262.ecma-international.org/12.0/#sec-imports)和[export](https://262.ecma-international.org/12.0/#sec-exports)，主要场景列举如下：
* ```import * as```：module namespace
* ```import { }```：module variable
* ```export```：local export

**注意：**<br>
模块相关的逻辑是编译器的内部实现，随着方舟编译器的后续演进，可能会出现新的涉及模块指令的场景；另一方面，现有的模块命名空间和模块变量指令的相关场景，也可能会随着需求演进和代码重构，不再涉及产生模块相关指令。<br>

示例代码：
```ts
import { a, b } from "./module_foo"
import * as c from "./module_bar"

export let d: number = 3;

a + b + d;
```
字节码中的相关指令：
```assembly
.function any .func_main_0(any a0, any a1, any a2) {
    getmodulenamespace 0x1
    ldai 0x3
    stmodulevar 0x0
    ldexternalmodulevar 0x0
    sta v0
    throw.undefinedifholewithname a
    ldexternalmodulevar 0x1
    sta v1
    throw.undefinedifholewithname b
    lda v1
    add2 0x0, v0
    sta v0
    ldlocalmodulevar 0x0
    sta v1
    throw.undefinedifholewithname d
    lda v1
    add2 0x1, v0
    ...
}
```
指令*getmodulenamespace 0x1*：获取1号槽位上的模块命名空间（c），存放到acc中；<br>
指令*stmodulevar 0x0*：将acc中的值存放到当前模块的0号槽位上；<br>
指令*ldexternalmodulevar 0x0*：加载外部模块的0号槽位上的值（a），存放到acc中；<br>
指令*ldlocalmodulevar 0x0*：加载当前局部模块的0号槽位上的值（d），存放到acc中。

#### 词法环境和词法变量
方舟字节码中，词法环境（lexical environment）可以看作是一个具有多个槽位的数组，每个槽位对应一个词法变量（lexical variable），一个方法中可能会存在多个词法环境。指令中使用词法环境的相对层级编号和槽位索引，来表示一个词法变量。例如，指令*ldlexvar 0x1, 0x2*的含义是：将1个层次外的词法环境的2号槽位上的值存放到acc中。
```
|xxx|xxx|xxx|xxx|   <-- 当前词法环境外的第1个词法环境
         ^
         |------------ ldlexvar 0x1, 0x2

|xxx|xxx|xxx|xxx|   <-- 当前词法环境
```
**注意：**<br>
lexical相关的逻辑是编译器的内部实现。随着方舟编译器的后续演进，可能会出现新的涉及lexical指令的场景；另一方面，现有的lexical指令的相关场景，也可能会随着需求演进和代码重构，不再涉及产生lexical相关指令。
示例代码：
```ts
function foo(): void {
    let a: number = 1;
    function bar(): number {
        return a;
    }
}
```
字节码中的相关指令：
```assembly
.function any .foo(any a0, any a1, any a2) {
    newlexenv 0x1
    ...
    definefunc 0x0, .bar, 0x0
    sta v3
    ldai 0x1 
    ...
    stlexvar 0x0, 0x0
    ...
}    

.function any .bar(any a0, any a1, any a2) {
    ...
    ldlexvar 0x0, 0x0
    ...
}
```
指令*newlexenv 0x1*：创建一个槽位数为1的词法环境，将其存放到acc中，并进入该词法环境；<br>
指令*stlexvar 0x0, 0x0*：将acc中的值存放到0个层次外的词法环境的0号槽位上；<br>
指令*ldlexvar 0x0, 0x0*：将0个层次外的词法环境的0号槽位上的值存放到acc中。

#### 共享词法环境
共享词法环境是一类特殊的词法环境。与一般词法环境的区别在于，共享词法环境中的每个词法变量都是[sendable对象](arkts-sendable.md)。方舟编译器通过共享词法环境实现词法变量在多线程的共享。

示例代码：
```ets
@Sendable
class A { }

@Sendable
class B {
    u: A = new A()
}
```
字节码中的相关指令：
```assembly
.function any .#~B=#B(any a0, any a1, any a2) {
label_1: 
label_0: 
	callruntime.ldsendablevar 0x0, 0x0
	sta v0
	throw.undefinedifholewithname A
	...
label_2: 
}

.function any .func_main_0(any a0, any a1, any a2) {
label_1: 
label_0: 
	callruntime.newsendableenv 0x1
	...
	callruntime.definesendableclass 0x0, .#~A=#A, _3, 0x0, v0
	callruntime.stsendablevar 0x0, 0x0
	...
label_2: 
}
```
指令*callruntime.newsendableenv 0x1*：创建一个槽位数为1的共享词法环境，并进入该词法环境；<br>
指令*callruntime.stsendablevar 0x0, 0x0*：将acc中的值存放到0个层次外的共享词法环境的0号槽位上；<br>
指令*callruntime.ldsendablevar 0x0, 0x0*：将0个层次外的共享词法环境的0号槽位上的值存放到acc中。

#### 补丁变量
方舟编译器支持补丁模式的编译，当源文件发生修改时，经过补丁模式编译，生成一个补丁字节码，配合原字节码，完成功能的更新。方舟编译器在补丁模式下编译时，产生的补丁变量会被存放在一个特殊的补丁词法环境中。方舟字节码中使用补丁词法环境上的槽位编号来引用补丁变量。例如，指令*ldpatchvar 0x1*加载的是槽位号为1的补丁变量。<br>

示例代码：
```ts
function bar(): void {} // 新增语句，编译补丁

function foo(): void {
    bar(); // 新增语句，编译补丁
}
```
字节码中的相关指令：
```assembly
.function any foo(...) {
    ...
    wide.ldpatchvar 0x0
    sta v4
    lda v4
    callarg0 0x0
    ...
}

.function any patch_main_0(...) {
    newlexenv 0x1
    definefunc 0x1, bar:(any,any,any), 0x0
    wide.stpatchvar 0x0
    ...
}
```
指令*wide.stpatchvar 0x0*：将函数bar存放到补丁词法环境的0号槽位；<br>
指令*wide.ldpatchvar 0x0*：将补丁词法环境上0号槽位的值存放到acc中。

### 函数调用规范
对于一个包含了N个形参的方法，该方法所使用的寄存器中的最后N+3个会被用于传递参数。其中，前三个寄存器固定表示函数本身（FunctionObject）、[new.target](https://262.ecma-international.org/12.0/#sec-function-environment-records)（NewTarget）和函数所在的词法环境中的```this```（this），后续的N个寄存器依次对应这N个形参。<br>

示例代码：
```ts
function foo(a: number, b: number): void {}
```
字节码中的相关指令：
```assembly
.function any .foo(any a0, any a1, any a2, any a3, any a4) {
    // a0: FunctionObject
    // a1: NewTarget
    // a2: this 
    // a3: a
    // a4: b
}
```

## 字节码格式说明
|     助记符      |      语义说明       |
|   ----------   |    ----------   |
|  ID16	 |  8位操作码，16位id   |
|  IMM16	 |  8位操作码，16位立即数   |
|  IMM16_ID16	 |  8位操作码，16位立即数，16位id   |
|  IMM16_ID16_ID16_IMM16_V8	 |  8位操作码，16位立即数，2个16位id，16位立即数，8位寄存器   |
|  IMM16_ID16_IMM8	 |  8位操作码，16位立即数，16位id，8位立即数   |
|  IMM16_ID16_V8	 |  8位操作码，16位立即数，16位id，8位寄存器   |
|  IMM16_IMM16	 |  8位操作码，2个16位立即数   |
|  IMM16_IMM8_V8	 |  8位操作码，16位立即数，8位立即数，8位寄存器   |
|  IMM16_V8	 |  8位操作码，16位立即数，8位寄存器   |
|  IMM16_V8_IMM16	 |  8位操作码，16位立即数，8位寄存器，16位立即数   |
|  IMM16_V8_V8	 |  8位操作码，16位立即数，2个8位寄存器   |
|  IMM32	 |  8位操作码，32位立即数   |
|  IMM4_IMM4	 |  8位操作码，2个4位立即数   |
|  IMM64	 |  8位操作码，64位立即数   |
|  IMM8	 |  8位操作码，8位立即数   |
|  IMM8_ID16	 |  8位操作码，8位立即数，16位id   |
|  IMM8_ID16_ID16_IMM16_V8	 |  8位操作码，8位立即数，2个16位id，16位立即数，8位寄存器   |
|  IMM8_ID16_IMM8	 |  8位操作码，8位立即数，16位id，8位立即数   |
|  IMM8_ID16_V8	 |  8位操作码，8位立即数，16位id，8位寄存器   |
|  IMM8_IMM16	 |  8位操作码，8位立即数，16位立即数   |
|  IMM8_IMM8	 |  8位操作码，2个8位立即数   |
|  IMM8_IMM8_V8	 |  8位操作码，2个8位立即数，8位寄存器   |
|  IMM8_V8	 |  8位操作码，8位立即数，8位寄存器   |
|  IMM8_V8_IMM16	 |  8位操作码，8位立即数，8位寄存器，16位立即数   |
|  IMM8_V8_V8	 |  8位操作码，8位立即数，2个8位寄存器   |
|  IMM8_V8_V8_V8	 |  8位操作码，8位立即数，3个8位寄存器   |
|  IMM8_V8_V8_V8_V8	 |  8位操作码，8位立即数，4个8位寄存器   |
|  NONE	 |  8位操作码   |
|  PREF_IMM16	 |  16位前缀操作码，16位立即数   |
|  PREF_IMM16_ID16	 |  16位前缀操作码，16位立即数，16位id   |
|  PREF_IMM16_V8	 |  16位前缀操作码，16位立即数，8位寄存器   |
|  PREF_IMM16_V8_V8	 |  16位前缀操作码，16位立即数，2个8位寄存器   |
|  PREF_IMM8	 |  16位前缀操作码，8位立即数   |
|  PREF_NONE	 |  16位前缀操作码   |
|  PREF_V8	 |  16位前缀操作码，8位寄存器   |
|  PREF_V8_ID16	 |  16位前缀操作码，8位寄存器，16位id   |
|  PREF_V8_IMM32	 |  16位前缀操作码，8位寄存器，32位立即数   |
|  V16_V16	 |  8位操作码，2个16位寄存器   |
|  V4_V4	 |  8位操作码，2个4位寄存器   |
|  V8	 |  8位操作码，8位寄存器   |
|  V8_IMM16	 |  8位操作码，8位寄存器，16位立即数   |
|  V8_IMM8	 |  8位操作码，8位寄存器，8位立即数   |
|  V8_V8	 |  8位操作码，2个8位寄存器   |
|  V8_V8_V8	 |  8位操作码，3个8位寄存器   |
|  V8_V8_V8_V8	 |  8位操作码，4个8位寄存器   |

## 字节码汇总集合
下表中汇总了当前版本的所有方舟字节码，寄存器索引、立即数和id通过每四位宽度使用一个字符替代的形式来描述。<br>
以指令*defineclasswithbuffer RR, @AAAA, @BBBB, +CCCC, vDD*为例：<br>
* *defineclasswithbuffer*：指示操作的操作码助记符
* *RR*：方舟运行时内部使用的8位保留数字，此处提及仅为完整展示指令格式，开发者无需关注
* *@AAAA，@BBBB*：16位id
* *+CCCC*：16位立即数
* *vDD*：8位寄存器索引

|    操作码   |   格式    |  助记符/语法   |     参数       |      说明     |
|   -------   |  -------  |  ----------  |   ----------   |   --------   |
|  0x00	|  NONE	|  ldundefined	|   |  	将**undefined**加载进acc。   |
|  0x01	|  NONE	|  ldnull	|   |  	将**null**加载进acc。   |
|  0x02	|  NONE	|  ldtrue	|   |  	将**true**加载进acc。   |
|  0x03	|  NONE	|  ldfalse	|   |  	将**false**加载进acc。   |
|  0x04	|  NONE	|  createemptyobject	|   |  	创建一个空对象，并将其存放到acc中。   |
|  0x05	|  IMM8|  	createemptyarray RR	|  R：方舟运行时内部使用的8位保留数字	|  创建一个空数组，并将其存放到acc中。   |
|  0x06	|  IMM8_ID16	|  createarraywithbuffer RR, @AAAA	|  R：方舟运行时内部使用的8位保留数字<br>A：16位的literal id	|  使用索引A对应的字面量数组，创建一个数组对象，并将其存放到acc中。   |
|  0x07	|  IMM8_ID16	|  createobjectwithbuffer RR, @AAAA	|  R：方舟运行时内部使用的8位保留数字<br>A：16位的literal id	|  使用索引A对应的字面量数组，创建一个对象，并将其存放到acc中。   |
|  0x08	|  IMM8_IMM8_V8	|  newobjrange RR, +AA, vBB	|  R：方舟运行时内部使用的8位保留数字<br>A：参数数量<br>B：类对象<br>B + 1, ..., B + A - 1：传递给构造函数的参数 |  	以B + 1, ..., B + A - 1作为参数，创建一个B类的实例，并将其存放到acc中。   |
|  0x09	|  IMM8	|  newlexenv +AA	|  A：词法环境中的槽位数目	|  创建一个槽位数为A的词法环境，将其存放到acc中，并进入该词法环境。   |
|  0x0a	|  IMM8_V8	|  add2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A + acc`，并将计算结果存放到acc中。   |
|  0x0b	|  IMM8_V8	|  sub2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A - acc`，并将计算结果存放到acc中。   |
|  0x0c	|  IMM8_V8	|  mul2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A * acc`，并将计算结果存放到acc中。   |
|  0x0d	|  IMM8_V8	|  div2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A / acc`，并将计算结果存放到acc中。   |
|  0x0e	|  IMM8_V8	|  mod2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A % acc`，并将计算结果存放到acc中。   |
|  0x0f	|  IMM8_V8	|  eq RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A == acc`，并将计算结果存放到acc中。   |
|  0x10	|  IMM8_V8	|  noteq RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A != acc`，并将计算结果存放到acc中。   |
|  0x11	|  IMM8_V8	|  less RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A < acc`，并将计算结果存放到acc中。   |
|  0x12	|  IMM8_V8	|  lesseq RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A <= acc`，并将计算结果存放到acc中。   |
|  0x13	|  IMM8_V8	|  greater RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A > acc`，并将计算结果存放到acc中。   |
|  0x14	|  IMM8_V8	|  greatereq RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A >= acc`，并将计算结果存放到acc中。   |
|  0x15	|  IMM8_V8	|  shl2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A << acc`，并将计算结果存放到acc中。   |
|  0x16	|  IMM8_V8	|  shr2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A >>> acc`，并将计算结果存放到acc中。   |
|  0x17	|  IMM8_V8	|  ashr2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A >> acc`，并将计算结果存放到acc中。   |
|  0x18	|  IMM8_V8	|  and2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A & acc`，并将计算结果存放到acc中。   |
|  0x19	|  IMM8_V8	|  or2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A \| acc`，并将计算结果存放到acc中。   |
|  0x1a	|  IMM8_V8	|  xor2 RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A ^ acc`，并将计算结果存放到acc中。
|  0x1b	|  IMM8_V8	|  exp RR, vAA	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字<br>A：操作数	|  计算`A ** acc`，并将计算结果存放到acc中。   |
|  0x1c	|  IMM8	|  typeof RR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字	|  计算`typeof acc`，并将计算结果存放到acc中。   |
|  0x1d	|  IMM8	|  tonumber RR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字	|  以acc作为参数，执行[ToNumber](https://262.ecma-international.org/12.0/#sec-tonumber)，将结果存放到acc中。   |
|  0x1e	|  IMM8	|  tonumeric RR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字	|  以acc作为参数，执行[ToNumeric](https://262.ecma-international.org/12.0/#sec-tonumeric)，将结果存放到acc中。   |
|  0x1f	|  IMM8	|  neg RR	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字	|  计算`-acc`，并将计算结果存放到acc中。   |
|  0x20	|  IMM8	|  not RR	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字	|  计算`~acc`，并将计算结果存放到acc中。   |
|  0x21	|  IMM8	|  inc RR	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字	|  计算`acc + 1`，并将计算结果存放到acc中。   |
|  0x22	|  IMM8	|  dec RR	|  默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字	|  计算`acc - 1`，并将计算结果存放到acc中。   |
|  0x23	|  NONE	|  istrue	|  默认入参：acc：对象	|  计算`acc == true`，并将计算结果存放到acc中。   |
|  0x24	|  NONE	|  isfalse	|  默认入参：acc：对象	|  计算`acc == false`，并将计算结果存放到acc中。   |
|  0x25	|  IMM8_V8	|  isin RR, vAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  计算`A in acc`，并将计算结果存放到acc中。   |
|  0x26	|  IMM8_V8	|  instanceof RR, vAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  计算`A instanceof acc`，并将计算结果存放到acc中。   |
|  0x27	|  IMM8_V8	|  strictnoteq RR, vAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  计算`acc !== A`，并将计算结果存放到acc中。   |
|  0x28	|  IMM8_V8	|  stricteq RR, vAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  计算`acc === A`，并将计算结果存放到acc中。   |
|  0x29	|  IMM8	|  callarg0 RR	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字	|  不传递参数，直接调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x2a	|  IMM8_V8	|  callarg1 RR, vAA	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：参数	|  以A作为参数，调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x2b	|  IMM8_V8_V8	|  callargs2 RR, vAA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A, B：参数	|  以A，B作为参数，调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x2c	|  IMM8_V8_V8_V8	|  callargs3 RR, vAA, vBB, vCC	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A, B, C：参数	|  以A, B, C作为参数，调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x2d	|  IMM8_V8	|  callthis0 RR, vAA	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  将`this`的值设置为A，不传递参数，调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x2e	|  IMM8_V8_V8	|  callthis1 RR, vAA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：参数	|  将`this`的值设置为A，以B作为参数，调用acc中存放的函数对象，并将计算结果存放到acc中。   |
|  0x2f	|  IMM8_V8_V8_V8	|  callthis2 RR, vAA, vBB, vCC	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B, C：参数  |  将`this`的值设置为A，以B，C作为参数，调用acc中存放的函数对象，并将计算结果存放到acc中。   |
|  0x30	|  IMM8_V8_V8_V8_V8	|  callthis3 RR, vAA, vBB, vCC, vDD	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B, C, D：参数  |  将`this`的值设置为A，以B, C, D作为参数，调用acc中存放的函数对象，并将计算结果存放到acc中。   |
|  0x31	|  IMM8_IMM8_V8	|  callthisrange RR, +AA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：参数数量<br>B：对象<br>B + 1, ..., B + A：参数	|  将`this`的值设置为B，以B + 1，...，B + A作为参数，调用acc中存放的函数对象，并将计算结果存放到acc中。   |
|  0x32	|  IMM8_IMM8_V8	|  supercallthisrange RR, +AA, vBB	|  R：方舟运行时内部使用的8位保留数字<br>A：参数数量<br>B, ..., B + A - 1：参数	|  以B, ..., B + A - 1作为参数, 调用`super`函数，并将结果存放到acc中。<br>当A的值是0时，B是**undefined**。<br>此指令仅出现在非箭头函数中。   |
|  0x33	|  IMM8_ID16_IMM8	|  definefunc RR, @AAAA, +BB	|  R：方舟运行时内部使用的8位保留数字<br>A：method id<br>B：方法A的形参数量 | 创建方法A的函数对象，并将其存放到acc中。   |
|  0x34	|  IMM8_ID16_IMM8	|  definemethod RR, @AAAA, +BB	|  默认入参：acc：类对象或类对象的对象原型，方法为静态方法时，acc中是类对象<br>R：方舟运行时内部使用的8位保留数字<br>A：method id<br>B：方法A的形参数量 	|  创建方法A的函数对象，将acc中的对象设置为该函数对象的[HomeObject](https://262.ecma-international.org/12.0/#sec-ecmascript-function-objects)属性，并将该函数对象存放到acc中。   |
|  0x35	|  IMM8_ID16_ID16_IMM16_V8	|  defineclasswithbuffer RR, @AAAA, @BBBB, +CCCC, vDD	|  R：方舟运行时内部使用的8位保留数字<br>A：类的构造函数的method id<br>B：literal id<br>C：方法A的形参数量<br>D：父类	|  使用索引B对应的字面量数组和父类D，创建A的类对象，并将其存放到acc中。   |
|  0x36	|  V8	|  getnextpropname vAA	| A：迭代器	|  执行[for-in迭代器](https://262.ecma-international.org/12.0/#sec-createiterresultobject)A的[next](https://262.ecma-international.org/12.0/#sec-%25foriniteratorprototype%25.next)方法，并将结果存放到acc中。   |
|  0x37	|  IMM8_V8	|  ldobjbyvalue RR, vAA	|  默认入参：acc：属性键值<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  加载A对象的键值为acc的属性，并将结果存放到acc中。
|  0x38	|  IMM8_V8_V8	|  stobjbyvalue RR, vAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x39	|  IMM8_V8	|  ldsuperbyvalue RR, vAA	|  默认入参：acc：属性键值<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  在当前函数中，获取`super`的键值为acc的属性，并将其存放到acc中。若该属性为访问器属性，则将A中的对象作为调用该属性getter函数时的`this`参数。   |
|  0x3a	|  IMM8_IMM16	|  ldobjbyindex RR, +AAAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：属性键值	|  加载acc中所存对象的键值为A的属性，并将其存放到acc中。   |
|  0x3b	|  IMM8_V8_IMM16	|  stobjbyindex RR, vAA, +BBBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x3c	|  IMM4_IMM4	|  ldlexvar +A, +B	|  A：词法环境层级<br>B：槽位号	|  将A个层次外的词法环境的B号槽位上的值存放到acc中。   |
|  0x3d	|  IMM4_IMM4	|  stlexvar +A, +B	|  默认入参：acc：值<br>A：词法环境层级<br>B：槽位号	|  将acc中的值存放到A个层次外的词法环境的B号槽位上。   |
|  0x3e	|  ID16	|  lda.str @AAAA	|  A：string id	|  将索引A对应的字符串存放到acc中。   |
|  0x3f	|  IMM8_ID16	|  tryldglobalbyname RR, @AAAA	|  R：方舟运行时内部使用的8位保留数字<br>A：string id	|  将名称为索引A对应的字符串的全局变量存放进acc中，不存在名称为A的全局变量时，抛出异常。   |
|  0x40	|  IMM8_ID16	|  trystglobalbyname RR, @AAAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：string id	|  将acc中的值存放到名称为索引A对应的字符串的全局变量上，不存在名称为A的全局变量时，抛出异常。   |
|  0x41	|  IMM16_ID16	|  ldglobalvar RRRR, @AAAA	|  R：方舟运行时内部使用的16位保留数字<br>A：string id	|  将名称为索引A对应的字符串的全局变量的值存放到acc中，该变量一定存在。   |
|  0x42	|  IMM8_ID16	|  ldobjbyname RR, @AAAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：string id	|  加载acc中所存对象的键值为索引A对应的字符串的属性，并将其存放到acc中。   |
|  0x43	|  IMM8_ID16_V8	|  stobjbyname RR, @AAAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：string id<br>B：对象	|  将acc中的值存放到对象B的键值为索引A对应的字符串的属性上。   |
|  0x44	|  V4_V4	|  mov vA, vB	|  A, B：寄存器索引	|  将寄存器B中的内容复制到寄存器A中。   |
|  0x45	|  V8_V8	|  mov vAA, vBB	|  A, B：寄存器索引	|  将寄存器B中的内容复制到寄存器A中。   |
|  0x46	|  IMM8_ID16	|  ldsuperbyname RR, @AAAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：string id	|  在当前函数中，获取`super`的键值为索引A对应的字符串的属性，并将其存放到acc中。若该属性为访问器属性，则将acc中的对象作为调用该属性getter函数时的`this`参数。   |
|  0x47	|  IMM16_ID16	|  stconsttoglobalrecord RRRR, @AAAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id	|  将acc的值存放到全局变量中以`const`定义的名字为索引A对应的字符串的常量。   |
|  0x48	|  IMM16_ID16	|  sttoglobalrecord RRRR, @AAAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id	|  将acc的值存放到全局变量中以`let`定义的名字为索引A对应的字符串的变量。   |
|  0x49	|  IMM8_ID16	|  ldthisbyname RR, @AAAA	|  R：方舟运行时内部使用的8位保留数字<br>A：string id	|  加载`this`的键值为索引A对应的字符串的属性，并把结果存放到acc中。   |
|  0x4a	|  IMM8_ID16	|  stthisbyname RR, @AAAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：string id	|  将acc中的值存放到`this`的键值为索引A对应的字符串的属性上。   |
|  0x4b	|  IMM8	|  ldthisbyvalue RR	|  默认入参：acc：属性键值<br>R：方舟运行时内部使用的8位保留数字	|  加载`this`的键值为acc的属性，并将结果存放到acc中。   |
|  0x4c	|  IMM8_V8	|  stthisbyvalue RR, vAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：属性键值	|  将acc中的值存放到`this`的键值为A的属性上。   |
|  0x4d	|  IMM8	|  jmp +AA	|  A：有符号的分支偏移量	|  无条件跳转到分支A。   |
|  0x4e	|  IMM16	|  jmp +AAAA	|  A：有符号的分支偏移量	|  无条件跳转到分支A。   |
|  0x4f	|  IMM8	|  jeqz +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc == 0`，如果为真，则跳转到分支A。   |
|  0x50	|  IMM16	|  jeqz +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc == 0`，如果为真，则跳转到分支A。   |
|  0x51	|  IMM8	|  jnez +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc != 0`，如果为真，则跳转到分支A。   |
|  0x52	|  IMM8	|  jstricteqz +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc === 0`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x53	|  IMM8	|  jnstricteqz +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc !== 0`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x54	|  IMM8	|  jeqnull +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc == null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x55	|  IMM8	|  jnenull +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc != null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x56	|  IMM8	|  jstricteqnull +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc === null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x57	|  IMM8	|  jnstricteqnull +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc !== null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x58	|  IMM8	|  jequndefined +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc == undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x59	|  IMM8	|  jneundefined +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc != undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x5a	|  IMM8	|  jstrictequndefined +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc === undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x5b	|  IMM8	|  jnstrictequndefined +AA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc !== undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x5c	|  V8_IMM8	|  jeq vAA, +BB	|  默认入参：acc：值<br>A：值<br>B：有符号的分支偏移量	|  计算`acc == A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0x5d	|  V8_IMM8	|  jne vAA, +BB	|  默认入参：acc：值<br>A：值<br>B：有符号的分支偏移量	|  计算`acc != A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0x5e	|  V8_IMM8	|  jstricteq vAA, +BB	|  默认入参：acc：对象<br>A：对象<br>B：有符号的分支偏移量	|  计算`acc === A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0x5f	|  V8_IMM8	|  jnstricteq vAA, +BB	|  默认入参：acc：对象<br>A：对象<br>B：有符号的分支偏移量	|  计算`acc !== A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0x60	|  V8	|  lda vAA	|  A：寄存器索引	|  将寄存器A中的内容存放到acc中。   |
|  0x61	|  V8	|  sta vAA	|  默认入参：acc<br>A：寄存器索引	|  将acc中的内容存放到寄存器A中。   |
|  0x62	|  IMM32	|  ldai +AAAAAAAA	|  A：常量字面量	|  将整型字面量A存放到acc中。   |
|  0x63	|  IMM64	|  fldai +AAAAAAAAAAAAAAAA	|  A：常量字面量	|  将双精度浮点型字面量A存放到acc中。   |
|  0x64	|  NONE	|  return	|  默认入参：acc：值	|  返回acc中的值。   |
|  0x65	|  NONE	|  returnundefined	 | 	|  返回**undefined**。   |
|  0x66	|  NONE	|  getpropiterator	|  默认入参：acc：对象	|  将acc中所存的对象的[for-in迭代器](https://262.ecma-international.org/12.0/#sec-createiterresultobject)存放到acc中。   |
|  0x67	|  IMM8	|  getiterator RR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字	|  执行[GetIterator](https://262.ecma-international.org/12.0/#sec-getiterator)(acc, sync)方法，并将结果存放到acc中。   |
|  0x68	|  IMM8_V8	|  closeiterator RR, vAA	|  R：方舟运行时内部使用的8位保留数字<br>A：对象	|  以类型为 *[iteratorRecord](https://262.ecma-international.org/12.0/#sec-iterator-records)* 的A作为参数，执行[IteratorClose](https://262.ecma-international.org/12.0/#sec-iteratorclose)，并将结果存放到acc中。   |
|  0x69	|  NONE	|  poplexenv	|   	|  跳出当前的词法环境，进入外面一层词法环境。   |
|  0x6a	|  NONE	|  ldnan	|   	|  将**nan**存放到acc中。   |
|  0x6b	|  NONE	|  ldinfinity	|   	|  将**infinity**存放到acc中。   |
|  0x6c	|  NONE	|  getunmappedargs	 |  	|  将当前函数的**arguments**存放到acc中。   |
|  0x6d	|  NONE	|  ldglobal	 |  	|  将**global**对象存放到acc中。 |
|  0x6e	|  NONE	|  ldnewtarget	 |  	|  将当前函数的隐式参数NewTarget存放到acc中。<br>指令功能未使能，暂不可用。   |
|  0x6f	|  NONE	|  ldthis	|   	|  将`this`存放到acc中。   |
|  0x70	|  NONE	|  ldhole	 |  	|  将**hole**存放到acc中。   |
|  0x71	|  IMM8_ID16_IMM8	|  createregexpwithliteral RR, @AAAA, +BB	|  R：方舟运行时内部使用的8位保留数字<br>A：string id<br>B：指代正则表达式修饰符	|  使用索引A对应的字符串和B指代的修饰符，创建一个正则表达式，并存放到acc中。<br>B和所指代的修饰符的对应关系为：0（默认值，无修饰符），1（g），2（i），4（m），8（s），16（u），32（y）；B也可以指代符合语法规范的修饰符的组合，例如3，指代的修饰符是gi。  |
|  0x72	|  IMM16_ID16_IMM8	|  createregexpwithliteral RRRR, @AAAA, +BB	|  R：方舟运行时内部使用的16位保留数字<br>A：string id<br>B：指代正则表达式修饰符	|  使用索引A对应的字符串和B指代的修饰符，创建一个正则表达式，并存放到acc中。<br>B和所指代的修饰符的对应关系为：0（默认值，无修饰符），1（g），2（i），4（m），8（s），16（u），32（y）；B也可以指代符合语法规范的修饰符的组合，例如3，指代的修饰符是gi。  |
|  0x73	|  IMM8_IMM8_V8	|  callrange RR, +AA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：参数数量<br>B,..., B + A - 1：参数	|  以B, ..., B + A - 1作为参数，调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x74	|  IMM16_ID16_IMM8	|  definefunc RRRR, @AAAA, +BB	|  R：方舟运行时内部使用的16位保留数字<br>A：method id<br>B：方法A的形参数量	|  创建方法A的函数对象，并将其存放到acc中。   |
|  0x75	|  IMM16_ID16_ID16_IMM16_V8	|  defineclasswithbuffer RRRR, @AAAA, @BBBB, +CCCC, vDD	|  R：方舟运行时内部使用的16位保留数字<br>A：类的构造函数的method id<br>B：literal id<br>C：方法A的形参数量<br>D：父类	|  使用索引B对应的字面量数组和父类D，创建A的类对象，并将其存放到acc中。   |
|  0x76	|  IMM8	|  gettemplateobject RR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字	|  执行[GetTemplateObject](https://262.ecma-international.org/12.0/#sec-gettemplateobject)(acc)，并将结果存放到acc中。   |
|  0x77	| IMM8_V8	| setobjectwithproto RR, vAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字<br>A：值	|  将acc中存放对象的 **\_\_proto\_\_** 属性设置为A。   |
|  0x78	|  IMM8_V8_V8	|  stownbyvalue RR, vAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x79	|  IMM8_V8_IMM16	|  stownbyindex RR, vAA, +BBBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x7a	|  IMM8_ID16_V8	|  stownbyname RR, @AAAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：string id<br>B：对象	|  将acc中的值存放到对象B的键值为索引A对应的字符串的属性上。   |
|  0x7b	|  IMM8	|  getmodulenamespace +AA	|  A：模块索引	|  对第A个模块，执行[GetModuleNamespace](https://262.ecma-international.org/12.0/#sec-getmodulenamespace)，并将结果存放到acc中。   |
|  0x7c	|  IMM8	|  stmodulevar +AA	|  默认入参：acc：值<br>A：槽位号	|  将acc中的值存放到槽位号为A的模块变量中。   |
|  0x7d	|  IMM8	|  ldlocalmodulevar +AA	|  A：槽位号	|  将槽位号为A的局部模块变量存放到acc中。   |
|  0x7e	|  IMM8	|  ldexternalmodulevar +AA	|  A：槽位号	|  将槽位号为A的外部模块变量存放到acc中。   |
|  0x7f	|  IMM16_ID16	|  stglobalvar RRRR, @AAAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id	|  将acc中的值存放到名字为索引A对应的字符串的全局变量上，这个变量一定存在。   |
|  0x80	|  IMM16	|  createemptyarray RRRR	|  R：方舟运行时内部使用的16位保留数字	|  创建一个空数组，并将其存放到acc中。   |
|  0x81	|  IMM16_ID16	|  createarraywithbuffer RRRR, @AAAA	|  R：方舟运行时内部使用的16位保留数字<br>A：literal id	|  使用索引A对应的字面量数组，创建一个数组对象, 并将其存放到acc中。   |
|  0x82	|  IMM16_ID16	|  createobjectwithbuffer RRRR, @AAAA	|  R：方舟运行时内部使用的16位保留数字<br>A：literal id	|  使用索引A对应的字面量数组，创建一个对象, 并将其存放到acc中。   |
|  0x83	|  IMM16_IMM8_V8	|  newobjrange RRRR, +AA, vBB	|  R：方舟运行时内部使用的16位保留数字<br>A：参数数量<br>B：类对象<br>B + 1, ..., B + A - 1：传递给构造函数的参数	|  以B + 1, ..., B + A - 1作为参数，创建一个B类的实例，并将其存放到acc中。   |
|  0x84	|  IMM16	|  typeof RRRR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的16位保留数字	|  计算`typeof acc`，并将计算结果存放到acc中。   |
|  0x85	|  IMM16_V8	|  ldobjbyvalue RRRR, vAA	|  默认入参：acc：属性键值<br>R：方舟运行时内部使用的16位保留数字<br>A：对象	|  加载A对象的键值为acc的属性，并将结果存放到acc中。   |
|  0x86	|  IMM16_V8_V8	|  stobjbyvalue RRRR, vAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x87	|  IMM16_V8	|  ldsuperbyvalue RRRR, vAA	|  默认入参：acc：属性键值<br>R：方舟运行时内部使用的16位保留数字<br>A：对象	|  在当前函数中，获取`super`的键值为acc的属性，并将其存放到acc中。若该属性为访问器属性，则将A中的对象作为调用该属性getter函数时的`this`参数。   |
|  0x88	|  IMM16_IMM16	|  ldobjbyindex RRRR, +AAAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的16位保留数字<br>A：属性键值	|  加载acc中所存对象的键值为A的属性，并将其存放到acc中。   |
|  0x89	|  IMM16_V8_IMM16	|  stobjbyindex RRRR, vAA, +BBBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x8a	|  IMM8_IMM8	|  ldlexvar +AA, +BB	|  A：词法环境层级<br>B：槽位号	|  将A个层次外的词法环境的B号槽位上的值存放到acc中。   |
|  0x8b	|  IMM8_IMM8	|  stlexvar +AA, +BB	|  默认入参：acc：值<br>A：词法环境层级<br>B：槽位号	|  将acc中的值存放到A个层次外的词法环境的B号槽位上。   |
|  0x8c	|  IMM16_ID16	|  tryldglobalbyname RRRR, @AAAA	|  R：方舟运行时内部使用的16位保留数字<br>A：string id	|  将名称为索引A对应的字符串的全局变量存放进acc中，不存在名称为A的全局变量时，抛出异常。   |
|  0x8d	|  IMM16_ID16	|  trystglobalbyname RRRR, @AAAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id	|  将acc中的值存放到名称为索引A对应的字符串的全局变量上，不存在名称为A的全局变量时，抛出异常。   |
|  0x8e	|  IMM8_ID16_V8	|  stownbynamewithnameset RR, @AAAA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：string id<br>B：对象	|  将acc中的函数对象存放到对象B的键值为索引A对应的字符串的属性上，并将函数的名称设置为索引A对应的字符串。   |
|  0x8f	|  V16_V16	|  mov vAAAA, vBBBB	|  A, B：寄存器索引	|  将寄存器B中的内容复制到寄存器A中。   |
|  0x90	|  IMM16_ID16	|  ldobjbyname RRRR, @AAAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的16位保留数字<br>A：string id	|  加载acc中所存对象的键值为索引A对应的字符串的属性，并将其存放到acc中。   |
|  0x91	|  IMM16_ID16_V8	|  stobjbyname RRRR, @AAAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id<br>B：对象	|  将acc中的值存放到对象B的键值为索引A对应的字符串的属性上。   |
|  0x92	|  IMM16_ID16	|  ldsuperbyname RRRR, @AAAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的16位保留数字<br>A：string id	|  在当前函数中，获取`super`的键值为索引A对应的字符串的属性，并将其存放到acc中。若该属性为访问器属性，则将acc中的对象作为调用该属性getter函数时的`this`参数。   |
|  0x93	|  IMM16_ID16	|  ldthisbyname RRRR, @AAAA	|  R：方舟运行时内部使用的16位保留数字<br>A：string id	|  加载`this`的键值为索引A对应的字符串的属性，并把结果存放到acc中。   |
|  0x94	|  IMM16_ID16	|  stthisbyname RRRR, @AAAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id	|  将acc中的值存放到`this`的键值为索引A对应的字符串的属性上。   |
|  0x95	|  IMM16	|  ldthisbyvalue RRRR	|  默认入参：acc：属性键值<br>R：方舟运行时内部使用的16位保留数字	|  加载`this`的键值为acc的属性，并将结果存放到acc中。   |
|  0x96	|  IMM16_V8	|  stthisbyvalue RRRR, vAA	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：属性键值	|  将acc中的值存放到`this`的键值为A的属性上。   |
|  0x97	|  V8	|  asyncgeneratorreject vAA	 |  默认入参：acc：异常<br>A：生成器	|  使用 *[generator](https://262.ecma-international.org/12.0/#sec-generator-objects)* A和acc中存放的异常，执行[AsyncGeneratorReject](https://262.ecma-international.org/12.0/#sec-asyncgeneratorreject)，并将结果存放到acc中。   |
|  0x98	|  IMM32	|  jmp +AAAAAAAA	|  A：有符号的分支偏移量	|  无条件跳转到分支A。   |
|  0x99	|  IMM8_V8_V8	|  stownbyvaluewithnameset RR, vAA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上，并将函数的名称设置为B。   |
|  0x9a	|  IMM32	|  jeqz +AAAAAAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc == 0`，如果为真，则跳转到分支A。   |
|  0x9b	|  IMM16	|  jnez +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc != 0`，如果为真，则跳转到分支A。   |
|  0x9c	|  IMM32	|  jnez +AAAAAAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc != 0`，如果为真，则跳转到分支A。   |
|  0x9d	|  IMM16	|  jstricteqz +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc === 0`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x9e	|  IMM16	|  jnstricteqz +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc !== 0`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0x9f	|  IMM16	|  jeqnull +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc == null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa0	|  IMM16	|  jnenull +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc != null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa1	|  IMM16	|  jstricteqnull +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc === null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa2	|  IMM16	|  jnstricteqnull +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc !== null`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa3	|  IMM16	|  jequndefined +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc == undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa4	|  IMM16	|  jneundefined +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc != undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa5	|  IMM16	|  jstrictequndefined +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算a`cc === undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa6	|  IMM16	|  jnstrictequndefined +AAAA	|  默认入参：acc：值<br>A：有符号的分支偏移量	|  计算`acc !== undefined`，如果为真，则跳转到分支A。<br>指令功能未使能，暂不可用。   |
|  0xa7	|  V8_IMM16	|  jeq vAA, +BBBB	|  默认入参：acc：值<br>A：值<br>B：有符号的分支偏移量	|  计算`acc == A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0xa8	|  V8_IMM16	|  jne vAA, +BBBB	|  默认入参：acc：值<br>A：值<br>B：有符号的分支偏移量	|  计算`acc != A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0xa9	|  V8_IMM16	|  jstricteq vAA, +BBBB	|  默认入参：acc：值<br>A：值<br>B：有符号的分支偏移量	|  计算`acc === A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0xaa	|  V8_IMM16	|  jnstricteq vAA, +BBBB	|  默认入参：acc：值<br>A：值<br>B：有符号的分支偏移量	|  计算`acc !== A`，如果为真，则跳转到分支B。<br>指令功能未使能，暂不可用。   |
|  0xab	|  IMM16	|  getiterator RRRR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的16位保留数字	|  执行[GetIterator](https://262.ecma-international.org/12.0/#sec-getiterator)(acc, sync)方法，并将结果存放到acc中。   |
|  0xac	|  IMM16_V8	|  closeiterator RRRR, vAA	|  R：方舟运行时内部使用的16位保留数字<br>A：对象	|  以类型为 *[iteratorRecord](https://262.ecma-international.org/12.0/#sec-iterator-records)* 的A作为参数，执行[IteratorClose](https://262.ecma-international.org/12.0/#sec-iteratorclose)，并将结果存放到acc中。   |
|  0xad	|  NONE	|  ldsymbol	 |  	|  加载**Symbol**对象到acc中。   |
|  0xae	|  NONE	|  asyncfunctionenter	|   	|  创建一个异步函数对象，并将这个对象存放到acc中。   |
|  0xaf	|  NONE	|  ldfunction	|   	|  将当前的函数对象加载到acc中。   |
|  0xb0	|  NONE	|  debugger	|   	|  调试时用于暂停执行。   |
|  0xb1	|  V8	|  creategeneratorobj vAA	|  A：函数对象	|  使用函数对象A，创建一个*generator*，并将其存放到acc中。   |
|  0xb2	|  V8_V8	|  createiterresultobj vAA, vBB	|  A：对象<br>B：布尔值	|  以 *value* A和 *done* B作为参数，执行[CreateIterResultObject](https://262.ecma-international.org/12.0/#sec-createiterresultobject)，并将结果存放到acc中。   |
|  0xb3	|  IMM8_V8_V8	|  createobjectwithexcludedkeys +AA, vBB, vCC	|  A：范围寄存器数量<br>B：对象<br>C, ..., C + A：属性键值	|  基于对象B，创建一个排除了键值C, ..., C + A的对象，并将其存放到acc中。<br>这个指令用于支持使用析构和扩展语法创建对象。   |
|  0xb4	|  IMM8_V8	|  newobjapply RR, vAA	|  默认入参：acc：参数列表<br>R：方舟运行时内部使用的8位保留数字<br>A：类对象	|  使用acc中存放的参数列表，创建一个A类的实例，并将其存放到acc中。   |
|  0xb5	|  IMM16_V8	|  newobjapply RRRR, vAA	|  默认入参：acc：参数列表<br>R：方舟运行时内部使用的16位保留数字<br>A：类对象	|  使用acc中存放的参数列表，创建一个A类的实例，并将其存放到acc中。   |
|  0xb6	|  IMM8_ID16	|  newlexenvwithname +AA, @BBBB	|  A：词法环境中的槽位数量<br>B：literal id	|  使用索引B对应的字面量数组中所存放的词法变量名称，创建一个具有A个槽位的词法环境，将这个词法环境存放到acc中，并进入该词法环境。   |
|  0xb7	|  V8	|  createasyncgeneratorobj vAA	|  A：函数对象	|  基于函数对象A，创建一个异步的*generator*，并将其存放到acc中。   |
|  0xb8	|  V8_V8_V8	|  asyncgeneratorresolve vAA, vBB, vCC	|  A：生成器<br>B：对象<br>C：布尔值	|  以 *generator* A, *value* B和 *done* C作为参数，执行[AsyncGeneratorResolve](https://262.ecma-international.org/12.0/#sec-asyncgeneratorresolve)，并将结果存放到acc中。   |
|  0xb9	|  IMM8_V8	|  supercallspread RR, vAA	|  默认入参：acc：类对象<br>R：方舟运行时内部使用的8位保留数字<br>A：参数列表	|  以参数列表A作为参数，调用acc中所存类的父类构造函数，并将结果存放到acc中。   |
|  0xba	|  IMM8_V8_V8	|  apply RR, vAA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：参数列表	|  将`this`设置为A，以参数列表B作为参数，调用acc中存放的函数对象，并将返回值存放到acc中。   |
|  0xbb	|  IMM8_IMM8_V8	|  supercallarrowrange RR, +AA, vBB	|  默认入参：acc：类对象<br>R：方舟运行时内部使用的8位保留数字<br>A：参数数量<br>B, ..., B + A - 1：参数	|  以B, ..., B + A - 1作为参数，调用acc中所存类的父类的构造函数，并将结果存放到acc中。<br>如果A的值为0，则B为**undefined**。<br>此指令仅出现在箭头函数中。   |
|  0xbc	|  V8_V8_V8_V8	|  definegettersetterbyvalue vAA, vBB, vCC, vDD	|  默认入参：acc：是否需要为访问器设置名称，是一个布尔值<br>A：对象<br>B：属性键值<br>C：getter函数对象<br>D：setter函数对象	|  以getter方法 C和setter方法 D作为参数，定义对象A的键值为B的属性的访问器，并将结果对象存放到acc中。<br>如果C是**undefined**，则不会设置getter，如果D是**undefined**，则不会设置setter。   |
|  0xbd	|  NONE	|  dynamicimport	|  默认入参：acc：值	|  使用acc中的值作为参数，执行[ImportCalls](https://262.ecma-international.org/12.0/#sec-import-calls)，并把结果存放到acc中。   |
|  0xbe	|  IMM16_ID16_IMM8	|  definemethod RRRR, @AAAA, +BB	|  默认入参：acc：类对象或类对象的对象原型，方法为静态方法时，acc中是类对象<br>R：方舟运行时内部使用的16位保留数字<br>A：method id<br>B：方法A的形参数量	|  创建方法A的函数对象，将acc中的对象设置为该函数对象的[[[HomeObject]]](https://262.ecma-international.org/12.0/#sec-ecmascript-function-objects)属性，并将该函数对象存放到acc中。   |
|  0xbf	|  NONE	|  resumegenerator	|  默认入参：acc：生成器	|  基于acc中存放的generator，执行[GeneratorResume](https://262.ecma-international.org/12.0/#sec-generatorresume)，并将结果存放到acc中。   |
|  0xc0	|  NONE	|  getresumemode	|  默认入参：acc：生成器	|  获取acc中所存放的generator的执行完成后恢复值的类型，并将其存放到acc中。   |
|  0xc1	|  IMM16	|  gettemplateobject RRRR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的16位保留数字	|  执行[GetTemplateObject](https://262.ecma-international.org/12.0/#sec-gettemplateobject)(acc)，并将结果存放到acc中。   |
|  0xc2	|  V8	|  delobjprop vAA	|  默认入参：acc：属性键值<br>A：对象	|  删除对象A的键值为acc的属性。   |
|  0xc3	|  V8	|  suspendgenerator vAA	|  默认入参：acc：值<br>A：生成器	|  使用acc中所存放的值，挂起*generator* A，并将结果存放到acc中。   |
|  0xc4	|  V8	|  asyncfunctionawaituncaught vAA	|  默认入参：acc：值<br>A：函数对象	|  使用函数对象A和acc的值，执行[AwaitExpression](https://262.ecma-international.org/12.0/#prod-AwaitExpression)，并将结果存放到acc中。   |
|  0xc5	|  V8	|  copydataproperties vAA	|  默认入参：acc：对象<br>A：目标对象	|  将acc中所存放的对象的所有属性拷贝到A中，并将A存放到acc中。   |
|  0xc6	|  V8_V8	|  starrayspread vAA, vBB	|  默认入参：acc：值<br>A：数组<br>B：数组索引	|  将acc中的值按照[SpreadElement](https://262.ecma-international.org/12.0/#prod-SpreadElement)的形式存放到数组A的以索引B起始的位置上，并将结果数组的长度存放到acc中。   |
|  0xc7	|  IMM16_V8	|  setobjectwithproto RRRR, vAA	|  默认入参：acc：对象<br>R：方舟运行时内部使用的16位保留数字<br>A：值	|  将acc中存放对象的 **\_\_proto\_\_** 属性设置为A。   |
|  0xc8	|  IMM16_V8_V8	|  stownbyvalue RRRR, vAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0xc9	|  IMM8_V8_V8	|  stsuperbyvalue RR, vAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：属性键值	|  在当前函数中，将acc中的值存放到`super`的键值为B的属性上。若该属性为访问器属性，则将A中的对象作为调用该属性setter函数时的`this`参数。   |
|  0xca	|  IMM16_V8_V8	|  stsuperbyvalue RRRR, vAA, vBB | 默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：对象<br>B：属性键值	|  在当前函数中，将acc中的值存放到`super`的键值为B的属性上。若该属性为访问器属性，则将A中的对象作为调用该属性setter函数时的`this`参数。   |
|  0xcb	|  IMM16_V8_IMM16	|  stownbyindex RRRR, vAA, +BBBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0xcc	|  IMM16_ID16_V8	|  stownbyname RRRR, @AAAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id<br>B：对象	|  将acc中的值存放到对象B的键值为索引A对应的字符串的属性上。   |
|  0xcd	|  V8	|  asyncfunctionresolve vAA	|  默认入参：acc：值<br>A：异步的函数对象	|  使用acc中的值，解析对象A的Promise对象，并将结果存放到acc中。   |
|  0xce	|  V8	|  asyncfunctionreject vAA	|  默认入参：acc：值<br>A：异步的函数对象	|  使用acc中的值，驳回对象A的Promise对象，并将结果存放到acc中。   |
|  0xcf	|  IMM8	|  copyrestargs +AA	|  A：形参列表中[剩余参数](https://262.ecma-international.org/12.0/#prod-FunctionRestParameter)所在的位次	|  复制剩余参数，并将复制出的参数数组副本存放到acc中。   |
|  0xd0	|  IMM8_ID16_V8	|  stsuperbyname RR, @AAAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的8位保留数字<br>A：string id<br>B：对象	|  在当前函数中，将acc中的值存放到`super`的键值为索引A对应的字符串的属性上。<br>若该属性为访问器属性，则将B中的对象作为调用该属性setter函数时的`this`参数。   |
|  0xd1	|  IMM16_ID16_V8	|  stsuperbyname RRRR, @AAAA, vBB	|  默认入参：acc：值<br>R：方舟运行时内部使用的16位保留数字<br>A：string id<br>B：对象	|  在当前函数中，将acc中的值存放到`super`的键值为索引A对应的字符串的属性上。<br>若该属性为访问器属性，则将B中的对象作为调用该属性setter函数时的`this`参数。   |
|  0xd2	|  IMM16_V8_V8	|  stownbyvaluewithnameset RRRR, vAA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上，并将函数的名称设置为B。   |
|  0xd3	|  ID16	|  ldbigint @AAAA	|  A：string id	|  基于索引A对应的字符串，创建**BigInt**类型的值，并将其存放到acc中。   |
|  0xd4	|  IMM16_ID16_V8	|  stownbynamewithnameset RRRR, @AAAA, vBB	|  默认入参：acc：函数对象<br>R：方舟运行时内部使用的16位保留数字<br>A：string id<br>B：对象	|  将acc中的函数对象存放到对象B的键值为索引A对应的字符串的属性上，并将函数的名称设置为索引A对应的字符串。   |
|  0xd5	|  NONE	|  nop	 |  	|  无操作。   |
|  0xd6	|  IMM8	|  setgeneratorstate +AA	|  默认入参：acc：生成器对象<br>A：生成器状态	|  将acc中存放的generator的状态设置为A (参考：[GeneratorState](https://262.ecma-international.org/12.0/#sec-properties-of-generator-instances)和[AsyncGeneratorState](https://262.ecma-international.org/12.0/#sec-properties-of-asyncgenerator-intances))<br>A可能的值有以下几项：undefined(0x0)、suspendedStart(0x1)、suspendedYield(0x2)、executing(0x3)、completed(0x4)和awaitingReturn(0x5)。   |
|  0xd7	|  IMM8	|  getasynciterator RR	|  默认入参：acc：对象<br>R：方舟运行时内部使用的8位保留数字	|  执行[GetIterator](https://262.ecma-international.org/12.0/#sec-getiterator)(acc, async)，并将结果存放到acc上。   |
|  0xd8	|  IMM8_IMM16_IMM16	|  ldprivateproperty RR, +AAAA, +BBBB	|  默认入参：acc：对象<br>A：词法环境层级<br>B：槽位号	|  加载A个层次外的词法环境的B号槽位上的值，作为属性键值，将acc中所存放对象的该键值对应的值存放到acc中。   |
|  0xd9	|  IMM8_IMM16_IMM16_V8	|  stprivateproperty RR, +AAAA, +BBBB, vCC	|  A：词法环境层级<br>B：槽位号<br>C：对象	|  加载A个层次外的词法环境的B号槽位上的值，作为属性键值，将acc中的值存放到C中所存放对象的该键值上。   |
|  0xda	|  IMM8_IMM16_IMM16	|  testin RR, +AAAA, +BBBB	|  默认入参：acc：对象<br>A：词法环境层级<br>B：槽位号	|  加载A个层次外的词法环境的B号槽位上的值，计算是否`in acc`，将结果存放到acc中。   |
|  0xdb	|  IMM8_ID16_V8	|  definefieldbyname RR, @AAAA, vBB	|  默认入参：acc：值<br>A：string id<br>B：对象	|  为对象B定义一个键值为A的属性，并将acc中的值存放到其中。   |
|  0xdc	|  IMM8_ID16_V8	|  definepropertybyname RR, @AAAA, vBB	|  默认入参：acc：值<br>A：string id<br>B：对象	|  为对象B定义一个键值为A的属性，并将acc中的值存放到其中。   |
|  0xfb	|  PREF_NONE	|  callruntime.notifyconcurrentresult	|  默认入参：acc：并发函数的返回值	|  将并发函数的返回值通知运行时。<br>此指令仅出现在并发函数中。   |
|  0xfc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0xfd	|  PREF_IMM16_V8_V8	|  wide.createobjectwithexcludedkeys +AAAA, vBB, vCC	|  A：范围寄存器数量<br>B：对象<br>C, ..., C + A：属性键值	|  基于对象B，创建一个排除了键值C, ..., C + A的对象，并将其存放到acc中。<br>这个指令用例支持使用析构和扩展语法创建对象。   |
|  0xfe	|  PREF_NONE	|  throw	|  默认入参：acc：异常	|  抛出acc中存放的异常。   |
|  0x01fb	|  PREF_IMM8_V8_V8	|  callruntime.definefieldbyvalue RR, vAA, vBB	|  默认入参：acc：值<br>A：属性键值<br>B：对象	|  为对象B定义一个键值为A的属性，并将acc中的值存放到其中。   |
|  0x01fc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x01fd	|  PREF_IMM16_V8	|  wide.newobjrange +AAAA, vBB	|  A：参数数量<br>B：类对象<br>B + 1, ..., B + A - 1：传递给构造函数的参数	|  以B + 1, ..., B + A - 1作为参数，创建一个B类的实例，并将其存放到acc中。   |
|  0x01fe	|  PREF_NONE	|  throw.notexists	|   	|  抛出异常：未定义的方法。   |
|  0x02fb	|  PREF_IMM8_IMM32_V8	|  callruntime.definefieldbyindex RR, +AAAAAAAA, vBB	|  默认入参：acc：值<br>A：属性键值<br>B：对象	|  为对象B定义一个键值为A的属性，并将acc中的值存放到其中。   |
|  0x02fc	|  (deprecated)	 |  |  | （弃用的操作码） |   
|  0x02fd	|  PREF_IMM16	|  wide.newlexenv +AAAA	|  A：词法环境中的槽位数目	|  创建一个槽位数为A的词法环境，将其存放到acc中，并进入该词法环境。   |
|  0x02fe	|  PREF_NONE	|  throw.patternnoncoercible |   	|  抛出异常：此对象不可以强制执行。   |
|  0x03fb	|  PREF_NONE	|  callruntime.topropertykey 	|  默认入参：acc：值	|  将acc中的值转换为属性值，如果转换失败，则抛出错误。   |
|  0x03fc	|  (deprecated)	 |  |  | （弃用的操作码） |  	 
|  0x03fd	|  PREF_IMM16_ID16	|  wide.newlexenvwithname +AAAA, @BBBB	|  A：词法环境中的槽位数量<br>B：literal id	|  使用索引B对应的字面量数组中所存放的词法变量名称，创建一个具有A个槽位的词法环境，将这个词法环境存放到acc中，并进入该词法环境。   |
|  0x03fe	|  PREF_NONE	|  throw.deletesuperproperty	|   |  	抛出异常：删除父类的属性。   |
|  0x04fb	|  PREF_IMM_16_ID16	|  callruntime.createprivateproperty +AAAA, @BBBB	|  A：要创建的符号数量<br>B：literal id	|  创建A个符号；从索引B对应的字面量数组中获取存放的私有方法，如果其中存在私有实例方法，则额外创建一个符号（"method"），将所有创建出的符号按照创建顺序，依次放到当前类所在的词法环境的末尾。<br>此指令仅出现在定义类的时候。   |
|  0x04fc	|  (deprecated)	 |  |  | （弃用的操作码） |  	 
|  0x04fd	|  PREF_IMM16_V8	|  wide.callrange +AAAA, vBB	|  默认入参：acc：函数对象<br>A：参数数量<br>B, ..., B + A - 1：参数	|  以B, ..., B + A - 1作为参数，调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x04fe	|  PREF_V8	|  throw.constassignment vAA	|  A：常量变量的名称	|  抛出异常：对常量变量进行赋值。   |
|  0x05fb	|  PREF_IMM8_IMM_16_IMM_16_V8	|  callruntime.defineprivateproperty RR, +AAAA, +BBBB, vCC	|  默认入参：acc：值<br>A：词法环境层数<br>B：槽位号<br>C：对象	|  加载A个层次外的词法环境的B号槽位上的符号，赋值为acc，将其作为私有属性添加到对象C上。   |
|  0x05fc	|  (deprecated)	 |  |  | （弃用的操作码） |  	 
|  0x05fd	|  PREF_IMM16_V8	|  wide.callthisrange +AAAA, vBB	|  默认入参：acc：函数对象<br>A：参数数量<br>B：对象<br>B + 1, ..., B + A：参数	|  将`this`的值设置为B，以B + 1，...，B + A作为参数，调用acc中存放的函数对象，并将计算结果存放到acc中。   |
|  0x05fe	|  PREF_V8	|  throw.ifnotobject vAA	|  A：对象	|  如果A不是一个对象，抛出异常。   |
|  0x06fb	|  PREF_IMM8_V8	|  callruntime.callinit +RR, vAA	|  acc：函数对象<br>R：方舟运行时内部使用的8位保留数字<br>A：对象	|  将`this`的值设置为A，不传递参数，调用acc中存放的函数对象，并将结果存放到acc中。   |
|  0x06fc	|  (deprecated)	 |  |  | （弃用的操作码） |  	 
|  0x06fd	|  PREF_IMM16_V8	|  wide.supercallthisrange +AAAA, vBB	|  A：参数数量<br>B, ..., B + A - 1：参数	|  以B, ..., B + A - 1作为参数, 调用`super`函数，并将结果存放到acc中。<br>当A的值是0时，B是**undefined**。<br>此指令仅出现在非箭头函数中。   |
|  0x06fe	|  PREF_V8_V8	|  throw.undefinedifhole vAA, vBB	|  A：对象<br>B：对象名称	|  如果A的值是**hole**，则抛出异常：B的值是**undefined**。   |
|  0x07fb	|  PREF_IMM16_ID16_ID16_IMM16_V8	|  callruntime.definesendableclass RRRR, @AAAA, @BBBB, +CCCC, vDD	|  R：方舟运行时内部使用的16位保留数字<br>A：[sendable class](arkts-sendable.md#sendable-class)的构造函数的method id<br>B：literal id<br>C：方法A的形参数量<br>D：父类	|  使用索引B对应的字面量数组和父类D，创建一个A类的对象，并将其存放到acc中。   |
|  0x07fc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x07fd	|  PREF_IMM16_V8	|  wide.supercallarrowrange +AAAA, vBB	|  默认入参：acc：类对象<br>A：参数数量<br>B, ..., B + A - 1:参数	|  以B, ..., B + A - 1作为参数，调用acc中所存类的父类的构造函数，并将结果存放到acc中。<br>如果A的值为0，则B为**undefined**。<br>此指令仅出现在箭头函数中。   |
|  0x07fe	|  PREF_IMM8	|  throw.ifsupernotcorrectcall +AA	|  默认入参：acc：对象<br>A：错误种类	|  如果`super`没有被正确调用，抛出错误。   |
|  0x08fb	|  PREF_IMM16	|  callruntime.ldsendableclass +AAAA	|  A：词法环境层级	|  将A个层次外的词法环境的[sendable class](arkts-sendable.md#sendable-class)存放到acc中。   |
|  0x08fc	|  (deprecated)	 |  |  | （弃用的操作码） | 
|  0x08fd	|  PREF_IMM32	|  wide.ldobjbyindex +AAAAAAAA	|  默认入参：acc：对象<br>A：属性键值	|  加载acc中所存对象的键值为A的属性，并将其存放到acc中。   |
|  0x08fe	|  PREF_IMM16	|  throw.ifsupernotcorrectcall +AAAA	|  默认入参：acc：对象<br>A：错误种类	|  如果`super`没有被正确调用，抛出错误。   |
|  0x09fb	|  PREF_IMM8	|  callruntime.ldsendableexternalmodulevar +AA	|  A：槽位号	|  将槽位号为A的外部模块变量存放到acc中。此指令仅出现在sendable class和[sendable function](arkts-sendable.md#sendable-function)中。   |
|  0x09fc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x09fd	|  PREF_V8_IMM32	|  wide.stobjbyindex vAA, +BBBBBBBB	|  默认入参：acc：值<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x09fe	|  PREF_ID16	|  throw.undefinedifholewithname @AAAA	|  默认入参：acc：对象<br>A：string id	|  如果acc中的值是**hole**，则抛出异常：A的值是**undefined**。   |
|  0x0afb	|  PREF_IMM16	|  callruntime.wideldsendableexternalmodulevar +AAAA	|  A：槽位号	|  将槽位号为A的外部模块变量存放到acc中。此指令仅出现在sendable class和sendable function中。   |
|  0x0afc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x0afd	|  PREF_V8_IMM32	|  wide.stownbyindex vAA, +BBBBBBBB	|  默认入参：acc：值<br>A：对象<br>B：属性键值	|  将acc中的值存放到对象A的键值为B的属性上。   |
|  0x0bfb	|  PREF_IMM8	|  callruntime.newsendableenv +AA	|  A：共享词法环境中的槽位数目	|  创建一个槽位数为A的共享词法环境，并进入该词法环境。   |
|  0x0bfc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x0bfd	|  PREF_IMM16	|  wide.copyrestargs +AAAA	|  A：形参列表中剩余参数起始的位次	|  复制剩余参数，并将复制出的参数数组副本存放到acc中。   |
|  0x0cfb	|  PREF_IMM16	|  callruntime.widenewsendableenv +AAAA	|  A：共享词法环境中的槽位数目	| 创建一个槽位数为A的共享词法环境，并进入该词法环境 。   |
|  0x0cfc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x0cfd	|  PREF_IMM16_IMM16	|  wide.ldlexvar +AAAA, +BBBB	|  A：词法环境层级<br>B：槽位号	|  将A个层次外的词法环境的B号槽位上的值存放到acc中。   |
|  0x0dfb	|  PREF_IMM4_IMM4	|  callruntime.stsendablevar +A +B	| 	默认入参：acc：值<br>A：共享词法环境层级<br>B：槽位号 |  将acc中的值存放到A个层次外的共享词法环境的B号槽位上。   |
|  0x0dfc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x0dfd	|  PREF_IMM16_IMM16	|  wide.stlexvar +AAAA, +BBBB	|  默认入参：acc：值<br>A：词法环境层级<br>B：槽位号	|  将acc中的值存放到A个层次外的词法环境的B号槽位上。   |
|  0x0efb	|  PREF_IMM8_IMM8	|  callruntime.stsendablevar +AA +BB	| 默认入参：acc：值<br>A：共享词法环境层级<br>B：槽位号   | 将acc中的值存放到A个层次外的共享词法环境的B号槽位上 。   |
|  0x0efc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x0efd	|  PREF_IMM16	|  wide.getmodulenamespace +AAAA	|  A：模块索引	|  对第A个模块，执行[GetModuleNamespace](https://262.ecma-international.org/12.0/#sec-getmodulenamespace)，并将结果存放到acc中。   |
|  0x0ffb	|  PREF_IMM16_IMM16	|  callruntime.widestsendablevar +AAAA +BBBB	|  默认入参：acc：值<br>A：共享词法环境层级<br>B：槽位号 |  将acc中的值存放到A个层次外的共享词法环境的B号槽位上。   |
|  0x0ffc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x0ffd	|  PREF_IMM16	|  wide.stmodulevar +AAAA	|  默认入参：acc：值<br>A：槽位号	|  将acc中的值存放到槽位号为A的模块变量中。   |
|  0x10fb	|  PREF_IMM4_IMM4	|  callruntime.ldsendablevar +A +B	|  A：共享词法环境层级<br>B：槽位号  | 将A个层次外的共享词法环境的B号槽位上的值存放到acc中。   |
|  0x10fc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x10fd	|  PREF_IMM16	|  wide.ldlocalmodulevar +AAAA	|  A：槽位号	|  将槽位号为A的局部模块变量存放到acc中。 |
|  0x11fb	|  PREF_IMM8_IMM8	|  callruntime.ldsendablevar +AA + BB	|  A：共享词法环境层级<br>B：槽位号  | 将A个层次外的共享词法环境的B号槽位上的值存放到acc中。   |
|  0x11fc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x11fd	|  PREF_IMM16	|  wide.ldexternalmodulevar +AAAA	|  A：槽位号	|  将槽位号为A的外部模块变量存放到acc中。|
|  0x12fb	|  PREF_IMM16_IMM16	|  callruntime.wideldsendablevar +AAAA +BBBB	|  A：共享词法环境层级<br>B：槽位号	|  将A个层次外的共享词法环境的B号槽位上的值存放到acc中。   |
|  0x12fc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x12fd	|  PREF_IMM16	|  wide.ldpatchvar +AAAA	|  A：补丁变量槽位号	|  将槽位号为A的补丁变量加载到acc中。<br>此指令仅出现在补丁模式编译场景下。|
|  0x13fb	|  PREF_IMM8	|  callruntime.istrue +RR	|  	默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字	|  计算acc == true，并将计算结果存放到acc中。   |
|  0x13fc	|  (deprecated)	 |  |  | （弃用的操作码） |
|  0x13fd	|  PREF_IMM16	|  wide.stpatchvar +AAAA	|  默认入参：acc：值<br>A：补丁变量槽位号	|  将acc中的值存放进槽位号为A的补丁变量中。<br>此指令仅出现在补丁模式编译场景下。 |
|  0x14fb	|  PREF_IMM8	|  callruntime.isfalse +RR	|  	默认入参：acc：操作数<br>R：方舟运行时内部使用的8位保留数字	|  计算acc == false，并将计算结果存放到acc中。   |
|  0x15fb	|  PREF_IMM8	|  callruntime.ldlazymodulevar +AA	|  A：槽位号	|   将槽位号为A的外部模块变量存放到acc中。此指令仅适用于通过[lazy import](arkts-lazy-import.md)导入的模块变量。   |
|  0x16fb	|  PREF_IMM16	|  callruntime.wideldlazymodulevar +AAAA	|  A：槽位号	|   将槽位号为A的外部模块变量存放到acc中。此指令仅适用于通过lazy import导入的模块变量。   |
|  0x17fb	|  PREF_IMM8	|  callruntime.ldlazysendablemodulevar +AA	|  A：槽位号	|   将槽位号为A的外部模块变量存放到acc中。此指令仅适用于通过lazy import导入的模块变量且仅出现在sendable class和sendable function中。   |
|  0x18fb	|  PREF_IMM16	|  callruntime.wideldlazysendablemodulevar +AAAA	|  A：槽位号	|  将槽位号为A的外部模块变量存放到acc中。此指令仅适用于通过lazy import导入的模块变量且仅出现在sendable class和sendable function中。   |
|  0x14fc<br>0x15fc<br>...<br>0x2efc | (deprecated)	 |  |  | （弃用的操作码） |