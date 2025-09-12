# ArkTS语言介绍

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @LeechyLiang-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @zhang_yixin13-->

ArkTS是一种设计用于构建高性能应用的编程语言。它在继承TypeScript语法的基础上进行了优化，以提供更高的性能和开发效率。

许多编程语言在设计之初未考虑移动设备，导致应用运行缓慢、低效且功耗大。随着移动设备在日常生活中越来越普遍，针对移动环境的编程语言优化需求日益增加。ArkTS专为解决这些问题而设计，聚焦提高运行效率。

TypeScript是在JavaScript基础上通过添加类型定义扩展而来的，ArkTS则是TypeScript的进一步扩展。TypeScript提供了一种更结构化的JavaScript编码方法，深受开发者喜爱。ArkTS保持了TypeScript的大部分语法，旨在为现有的TypeScript开发者提供高度兼容的体验，帮助移动开发者快速上手。

ArkTS的一大特性是它专注于低运行时开销。ArkTS对TypeScript的动态类型特性施加了更严格的限制，以减少运行时开销，提高执行效率。通过取消动态类型特性，ArkTS代码能更有效地被运行前编译和优化，从而实现更快的应用启动和更低的功耗。

ArkTS语言设计中考虑了与TypeScript和JavaScript的互通性。许多移动应用开发者希望重用TypeScript和JavaScript代码及库，因此ArkTS提供与TypeScript和JavaScript的无缝互通，使开发者可以轻松集成TypeScript和JavaScript代码到应用中，充分利用现有代码和库进行ArkTS开发。

本教程将指导开发者了解ArkTS的核心功能、语法和最佳实践，助力开发者使用ArkTS高效构建高性能的移动应用。

如需详细了解ArkTS语言，请参阅[ArkTS具体指南](../arkts-utils/arkts-overview.md)<!--RP1--><!--RP1End-->。

## 基本知识

### 声明

ArkTS通过声明引入变量、常量、类型和函数。

**变量声明**

使用关键字`let`声明的变量可以在程序执行期间具有不同的值。

```typescript
let hi: string = 'hello';
hi = 'hello, world';
```

**常量声明**

使用关键字`const`声明的常量为只读类型，只能被赋值一次。

```typescript
const hello: string = 'hello';
```

对常量重新赋值会造成编译时错误。

**自动类型推断**

如果变量或常量的声明包含初始值，开发者无需显式指定类型，因为ArkTS规范已列举了所有允许自动推断类型的场景。

以下示例中，两条声明语句都是有效的，两个变量都是`string`类型：

```typescript
let hi1: string = 'hello';
let hi2 = 'hello, world';
```

### 类型

**基本类型和引用类型**

基本数据类型包括`number`、`string`等简单类型，它们可以准确地表示单一的数据类型。对基本类型的存储和访问都是直接的，比较时直接比较其值。

引用类型包括对象、数组和函数等复杂数据结构。这些类型通过引用访问数据，对象和数组可以包含多个值或键值对，函数则可以封装可执行的代码逻辑。引用类型在内存中通过指针访问数据，修改引用会影响原始数据。

**`number`类型**

ArkTS提供`number`类型，任何整数和浮点数都可以被赋给此类型的变量。

数字字面量包括整数字面量和十进制浮点数字面量。

整数字面量包括以下类别：

* 十进制整数，由数字序列组成。例如：`0`、`117`、`-345`。
* 十六进制整数，以0x（或0X）开头，包含数字（0-9）和字母a-f或A-F。例如：`0x1123`、`0x00111`、`-0xF1A7`。
* 八进制整数，以0o（或0O）开头，只能包含数字（0-7）。例如：`0o777`。
* 二进制整数，以0b（或0B）开头，只能包含数字0和1。例如：`0b11`、`0b0011`、`-0b11`。

浮点数字面量包括以下部分：

* 十进制整数，可为有符号数（前缀为“+”或“-”）。
* 小数点（“.”）。
* 小数部分（由十进制数字字符串表示）。
* 指数部分，以“e”或“E”开头，后跟有符号（前缀为“+”或“-”）或无符号整数。

示例：

```typescript
let n1 = 3.14;
let n2 = 3.141592;
let n3 = .5;
let n4 = 1e2;

function factorial(n: number): number {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

factorial(n1)  //  7.660344000000002 
factorial(n2)  //  7.680640444893748 
factorial(n3)  //  1 
factorial(n4)  //  9.33262154439441e+157 
```

`number`类型在表示大整数（即超过-9007199254740991~9007199254740991）时会造成精度丢失。在开发时可以按需使用`bigint`类型来确保精度：

```typescript

let bigInt: BigInt = BigInt('999999999999999999999999999999999999999999999999999999999999');
console.info('bigInt:' + bigInt.toString());

```

**`boolean`类型**

`boolean`类型由`true`和`false`两个逻辑值组成。

通常在条件语句中使用`boolean`类型的变量：

```typescript
let isDone: boolean = false;

// ...

if (isDone) {
  console.info('Done!');
}
```

**`string`类型**

`string`类型代表字符序列，可以使用转义字符来表示字符。

字符串字面量由单引号（'）或双引号（"）之间括起来的零个或多个字符组成。字符串字面量还有一特殊形式，是用反向单引号（\`）括起来的模板字面量。

```typescript
let s1 = 'Hello, world!\n';
let s2 = "this is a string";
let a = 'Success';
let s3 = `The result is ${a}`;
```

**`void`类型**

`void`类型用于指定函数没有返回值。
此类型只有一个值，同样是`void`。由于`void`是引用类型，因此它可以用于泛型类型参数。

```typescript
class Class<T> {
  //...
}
let instance: Class <void>
```

**`Object`类型**

`Object`类型是所有引用类型的基类型。任何值，包括基本类型的值，都可以直接被赋给`Object`类型的变量（基本类型值会被自动装箱）。`Object`类型用于表示除基本类型外的类型。
```typescript
let o1: Object = 'Alice';
let o2: Object = ['a','b'];
let o3: Object = 1;
```

**`array`类型**

`array`类型，即数组，是由可赋值给数组声明中指定的元素类型的数据组成的对象。
数组可由数组复合字面量赋值。数组复合字面量是用方括号括起来的零个或多个表达式列表，每个表达式为数组中的一个元素。数组的长度由数组中元素的个数确定。数组中第一个元素的索引为0。

以下示例将创建包含三个元素的数组：

```typescript
let names: string[] = ['Alice', 'Bob', 'Carol'];
```

**`enum`类型**

`enum`类型，即枚举类型，是预先定义的一组命名值的值类型，其中命名值又称为枚举常量。
使用枚举常量时必须以枚举类型名称为前缀。

```typescript
enum ColorSet { Red, Green, Blue }
let c: ColorSet = ColorSet.Red;
```

常量表达式用于显式设置枚举常量的值。

```typescript
enum ColorSet { White = 0xFF, Grey = 0x7F, Black = 0x00 }
let c: ColorSet = ColorSet.Black;
```

**`Union`类型**

`Union`类型，即联合类型，是由多个类型组合成的引用类型。联合类型包含了变量可能的所有类型。

```typescript
class Cat {
  name: string = 'cat';
  // ...
}
class Dog {
  name: string = 'dog';
  // ...
}
class Frog {
  name: string = 'frog';
  // ...
}
type Animal = Cat | Dog | Frog | number | string | null | undefined;
// Cat、Dog、Frog是一些类型（类或接口）

let animal: Animal = new Cat();
animal = new Frog();
animal = 42;
animal = 'dog';
animal = undefined;
// 可以将类型为联合类型的变量赋值为任何组成类型的有效值
```

可以使用不同机制获取联合类型中的特定类型值。

示例：

```typescript
class Cat { sleep () {}; meow () {} }
class Dog { sleep () {}; bark () {} }
class Frog { sleep () {}; leap () {} }

type Animal = Cat | Dog | Frog;

function foo(animal: Animal) {
  if (animal instanceof Frog) {
    animal.leap();  // animal在这里是Frog类型
  }
  animal.sleep(); // Animal具有sleep方法
}
```

**`Aliases`类型**

`Aliases`类型为匿名类型（如数组、函数、对象字面量或联合类型）提供名称，或为已定义的类型提供替代名称。

```typescript
type Matrix = number[][];
type Handler = (s: string, no: number) => string;
type Predicate <T> = (x: T) => boolean;
type NullableObject = Object | null;
```

### 运算符

**赋值运算符**

赋值运算符`=`，使用方式如`x=y`。

复合赋值运算符将赋值与运算符组合在一起，例如：`a += b` 等价于 `a = a + b`，

其中的 `+=` 即为复合赋值运算符

复合赋值运算符包括：`+=`、`-=`、`*=`、`/=`、`%=`、`<<=`、`>>=`、`>>>=`、`&=`、`|=`、`^=`。

**比较运算符**

| 运算符| 说明                                                 |
| -------- | ------------------------------------------------------------ |
| `===`    | 如果两个操作数严格相等（对于不同类型的操作数认为是不相等的），则返回true。 |
| `!==`    | 如果两个操作数严格不相等（对于不同类型的操作数认为是不相等的），则返回true。 |
| `==`     | 如果两个操作数相等，则返回true。 |
| `!=`     | 如果两个操作数不相等，则返回true。    |
| `>`      | 如果左操作数大于右操作数，则返回true。 |
| `>=`     | 如果左操作数大于或等于右操作数，则返回true。 |
| `<`      | 如果左操作数小于右操作数，则返回true。    |
| `<=`     | 如果左操作数小于或等于右操作数，则返回true。 |

`===`与`==`的区别：
```typescript
// ==只比较目标的值相等
console.info(String(null == undefined)); // true
// ===比较目标的值和类型都相等
console.info(String(null === undefined)); // false
```


**算术运算符**

一元运算符包括：`-`、`+`、`--`、`++`。

二元运算符列举如下：

| 运算符| 说明             |
| -------- | ------------------------ |
| `+`      | 加法                |
| `-`      | 减法             |
| `*`      | 乘法          |
| `/`      | 除法                |
| `%`      | 除法后余数|

**位运算符**

| 运算符 | 说明                                                 |
| --------- | ------------------------------------------------------------ |
| `a & b`   | 按位与：如果两个操作数的对应位都为1，则将这个位设置为1，否则设置为0。|
| `a \| b`  | 按位或：如果两个操作数的相应位中至少有一个为1，则将这个位设置为1，否则设置为0。|
| `a ^ b`   | 按位异或：如果两个操作数的对应位不同，则将这个位设置为1，否则设置为0。|
| `~ a`     | 按位非：反转操作数的位。               |
| `a << b`  | 左移：将a的二进制表示向左移b位。|
| `a >> b`  | 算术右移：将a的二进制表示向右移b位，带符号扩展。|
| `a >>> b` | 逻辑右移：将a的二进制表示向右移b位，左边补0。|

**逻辑运算符**

| 运算符  | 说明|
| ---------- | ----------- |
| `a && b`   | 逻辑与 |
| `a \|\| b` | 逻辑或 |
| `! a`      | 逻辑非 |

### 语句

**`If`语句**

`if`语句用于需要根据逻辑条件执行不同语句的场景。当逻辑条件为真时，执行对应的一组语句，否则执行另一组语句（如果有的话）。
`else`部分也可以包含`if`语句。

`if`语句如下所示：

```typescript
if (condition1) {
  // 语句1
} else if (condition2) {
  // 语句2
} else {
  // else语句
}
```

条件表达式可以是任何类型，非`boolean`类型会进行隐式类型转换：

```typescript
let s1 = 'Hello';
if (s1) {
  console.info(s1); // 打印“Hello”
}

let s2 = 'World';
if (s2.length != 0) {
  console.info(s2); // 打印“World”
}
```

**`Switch`语句**

使用`switch`语句执行与`switch`表达式值匹配的代码块。

`switch`语句如下所示：

```typescript
switch (expression) {
  case label1: // 如果label1匹配，则执行
    // ...
    // 语句1
    // ...
    break; // 可省略
  case label2:
  case label3: // 如果label2或label3匹配，则执行
    // ...
    // 语句23
    // ...
    break; // 可省略
  default:
    // 默认语句
}
```

如果`switch`表达式的值等于某个label的值，则执行相应的语句。

如果没有任何一个label值与表达式值相匹配，并且`switch`具有`default`子句，那么程序会执行`default`子句对应的代码块。

`break`语句（可选的）允许跳出`switch`语句并继续执行`switch`语句之后的语句。

如果没有`break`语句，则执行`switch`中的下一个label对应的代码块。

**条件表达式**

条件表达式根据第一个表达式的布尔值来返回其他两个表达式之一的结果。

示例如下：

```typescript
condition ? expression1 : expression2
```

如果`condition`的值为真值（转换后为`true`的值），则使用`expression1`作为该表达式的结果；否则，使用`expression2`作为该表达式的结果。

示例：

```typescript
let message = Math.random() > 0.5 ? 'Valid' : 'Failed';
```

`condition`如果是非bool值则会进行隐式转换。

示例：

```typescript
    console.info('a' ? 'true' : 'false'); // true
    console.info('' ? 'true' : 'false'); // false
    console.info(1 ? 'true' : 'false'); // true
    console.info(0 ? 'true' : 'false'); // false
    console.info(null ? 'true' : 'false'); // false
    console.info(undefined ? 'true' : 'false'); // false
```

**`For`语句**

`for`语句会被重复执行，直到循环退出语句值为`false`。

`for`语句如下所示：

```typescript
for ([init]; [condition]; [update]) {
  statements
}
```

`for`语句的执行流程如下：

1、 执行`init`表达式（如有）。此表达式通常初始化一个或多个循环计数器。  
2、 计算`condition`。如果它为真值（转换后为`true`的值），则执行循环主体的语句。如果它为假值（转换后为`false`的值），则`for`循环终止。  
3、 执行循环主体的语句。
4、 如果有`update`表达式，则执行该表达式。  
5、 返回步骤2。

示例：

```typescript
let sum = 0;
for (let i = 0; i < 10; i += 2) {
  sum += i;
}
```

**`For-of`语句**

使用`for-of`语句可遍历数组、Set、Map、字符串等可迭代的类型。示例如下：

```typescript
for (forVar of IterableExpression) {
  // process forVar
}
```

示例：

```typescript
for (let ch of 'a string object') {
  console.info(ch);
}
```

**`While`语句**

只要`condition`为真值（转换后为`true`的值），`while`语句就会执行`statements`语句。示例如下：

```typescript
while (condition) {
  statements
}
```

示例：

```typescript
let n = 0;
let x = 0;
while (n < 3) {
  n++;
  x += n;
}
```

**`Do-while`语句**

如果`condition`的值为真值（转换后为`true`的值），那么`statements`语句会重复执行。示例如下：

```typescript
do {
  statements
} while (condition)
```

示例：

```typescript
let i = 0;
do {
  i += 1;
} while (i < 10)
```

**`Break`语句**

使用`break`语句可以终止循环语句或`switch`。

示例：

```typescript
let x = 0;
while (true) {
  x++;
  if (x > 5) {
    break;
  }
}
```

如果`break`语句后带有标识符，则将控制流转移到该标识符所包含的语句块之外。

示例：

```typescript
let x = 1;
label: while (true) {
  switch (x) {
    case 1:
      // statements
      break label; // 中断while语句
  }
}
```

**`Continue`语句**

`continue`语句会停止当前循环迭代的执行，并将控制传递给下一次迭代。

示例：

```typescript
let sum = 0;
for (let x = 0; x < 100; x++) {
  if (x % 2 == 0) {
    continue;
  }
  sum += x;
}
```

**`Throw`和`Try`语句**

`throw`语句用于抛出异常或错误：

```typescript
throw new Error('this error')
```

`try`语句用于捕获和处理异常或错误：

```typescript
try {
  // 可能发生异常的语句块
} catch (e) {
  // 异常处理
}
```

下面的示例中`throw`和`try`语句用于处理除数为0的错误：

```typescript
class ZeroDivisor extends Error {}

function divide (a: number, b: number): number{
  if (b == 0) throw new ZeroDivisor();
  return a / b;
}

function process (a: number, b: number) {
  try {
    let res = divide(a, b);
    console.info('result: ' + res);
  } catch (x) {
    console.error('some error');
  }
}
```

支持`finally`语句：

```typescript
function processData(s: string) {
  let error: Error | null = null;

  try {
    console.info('Data processed: ' + s);
    // ...
    // 可能发生异常的语句
    // ...
  } catch (e) {
    error = e as Error;
    // ...
    // 异常处理
    // ...
  } finally {
    // 无论是否发生异常都会执行的代码
    if (error != null) {
      console.error(`Error caught: input='${s}', message='${error.message}'`);
    }
  }
}
```

## 函数

### 函数声明

函数声明引入一个函数，包含其名称、参数列表、返回类型和函数体。

以下示例是一个简单的函数和它的语法语义说明：

1.参数类型标注：x: string, y: string 显式声明参数类型为字符串类型。

2.返回值类型：: string 指定函数返回值为字符串类型。

```typescript
function add(x: string, y: string): string {
  let z: string = `${x} ${y}`;
  return z;
}
```

在函数声明中，必须为每个参数标记类型。如果参数为可选参数，那么允许在调用函数时省略该参数。函数的最后一个参数可以是rest参数。

### 可选参数

可选参数的格式可为`name?: Type`。

```typescript
function hello(name?: string) {
  if (name == undefined) {
    console.info('Hello!');
  } else {
    console.info(`Hello, ${name}!`);
  }
}
```

可选参数的另一种形式为设置的参数默认值。如果在函数调用中这个参数被省略了，则会使用此参数的默认值作为实参。

```typescript
function multiply(n: number, coeff: number = 2): number {
  return n * coeff;
}
multiply(2);  // 返回2*2
multiply(2, 3); // 返回2*3
```

### Rest参数

函数的最后一个参数可以是rest参数，格式为`...restArgs`。rest参数允许函数接收一个由剩余实参组成的数组，类型为任意指定类型，用于处理不定数量的参数输入。

```typescript
function sum(...numbers: number[]): number {
  let res = 0;
  for (let n of numbers)
    res += n;
  return res;
}

sum(); // 返回0
sum(1, 2, 3); // 返回6
```

### 返回类型

如果可以从函数体内推断出函数返回类型，则可在函数声明中省略标注返回类型。

```typescript
// 显式指定返回类型
function foo(): string { return 'foo'; }

// 推断返回类型为string
function goo() { return 'goo'; }
```

不需要返回值的函数的返回类型可以显式指定为`void`或省略标注。这类函数不需要返回语句。

以下示例中两种函数声明方式都是有效的：

```typescript
function hi1() { console.info('hi'); }
function hi2(): void { console.info('hi'); }
```

### 函数的作用域

函数中定义的变量和其他实例仅可以在函数内部访问，不能从外部访问。

如果函数中定义的变量与外部作用域中已有实例同名，则函数内的局部变量定义将覆盖外部定义。

```typescript
let outerVar = 'I am outer ';

function func() {
    let outerVar = 'I am inside';
    console.info(outerVar); // 输出: I am inside
}

func();
```

### 函数调用

调用函数以执行其函数体，实参值会赋值给函数的形参。

如果函数定义如下：

```typescript
function join(x: string, y: string): string {
  let z: string = `${x} ${y}`;
  return z;
}
```

则此函数的调用需要包含两个`string`类型的参数：

```typescript
let x = join('hello', 'world');
console.info(x); // 输出: hello world
```

### 函数类型

函数类型通常用于定义回调函数：

```typescript
type trigFunc = (x: number) => number // 这是一个函数类型

function do_action(f: trigFunc) {
  f(3.141592653589); // 调用函数
}

do_action(Math.sin); // 将函数作为参数传入
```

### 箭头函数（又名Lambda函数）

函数可以定义为箭头函数，例如：

```typescript
let sum = (x: number, y: number): number => {
  return x + y;
}
```

箭头函数的返回类型可以省略，此时返回类型从函数体推断。

表达式可以指定为箭头函数，使表达更简短，因此以下两种表达方式是等价的：

```typescript
let sum1 = (x: number, y: number) => { return x + y; }
let sum2 = (x: number, y: number) => x + y
```

### 闭包

闭包是由函数及声明该函数的环境组合而成的。该环境包含了这个闭包创建时作用域内的任何局部变量。

在下例中，`f`函数返回了一个闭包，它捕获了`count`变量，每次调用`z`，`count`的值会被保留并递增。

```typescript
function f(): () => number {
  let count = 0;
  let g = (): number => { count++; return count; };
  return g;
}

let z = f();
z(); // 返回：1
z(); // 返回：2
```

### 函数重载

可以通过编写重载，指定函数的不同调用方式。具体方法是，为同一个函数写入多个同名但签名不同的函数头，函数实现紧随其后。

```typescript
function foo(x: number): void;            /* 第一个函数定义 */
function foo(x: string): void;            /* 第二个函数定义 */
function foo(x: number | string): void {  /* 函数实现 */
}

foo(123);     //  OK，使用第一个定义
foo('aa'); // OK，使用第二个定义
```

不允许重载函数有相同的名字和参数列表，否则将导致编译错误。

## 类

类声明引入一个新类型，并定义其字段、方法和构造函数。

在以下示例中，定义了`Person`类，该类具有字段`name`和`surname`、构造函数和方法`fullName`：

```typescript
class Person {
  name: string = '';
  surname: string = '';
  constructor (n: string, sn: string) {
    this.name = n;
    this.surname = sn;
  }
  fullName(): string {
    return this.name + ' ' + this.surname;
  }
}
```

定义类后，可以使用关键字`new`创建实例：

```typescript
let p = new Person('John', 'Smith');
console.info(p.fullName());
```

或者，可以使用对象字面量创建实例：

```typescript
class Point {
  x: number = 0;
  y: number = 0;
}
let p: Point = {x: 42, y: 42};
```

### 字段

字段是直接在类中声明的某种类型的变量。

类可以具有实例字段或者静态字段。

**实例字段**

实例字段存在于类的每个实例上。每个实例都有自己的实例字段集合。

要访问实例字段，需要使用类的实例。

```typescript
class Person {
  name: string = '';
  age: number = 0;
  constructor(n: string, a: number) {
    this.name = n;
    this.age = a;
  }

  getName(): string {
    return this.name;
  }
}

let p1 = new Person('Alice', 25);
p1.name; // Alice
let p2 = new Person('Bob', 28);
p2.getName(); // Bob
```

**静态字段**

使用关键字`static`将字段声明为静态。静态字段属于类本身，类的所有实例共享一个静态字段。

要访问静态字段，需要使用类名：

```typescript
class Person {
  static numberOfPersons = 0;
  constructor() {
     // ...
     Person.numberOfPersons++;
     // ...
  }
}

Person.numberOfPersons;
```

**字段初始化**

为了减少运行时错误并提升执行性能，
ArkTS要求所有字段在声明时或构造函数中显式初始化，与标准TS的`strictPropertyInitialization`模式相同。

以下代码在ArkTS中不合法。

```typescript
class Person {
  name: string; // undefined
  
  setName(n:string): void {
    this.name = n;
  }
  
  getName(): string {
    // 开发者使用"string"作为返回类型，这隐藏了name可能为"undefined"的事实。
    // 更合适的做法是将返回类型标注为"string | undefined"，以告诉开发者这个API所有可能的返回值。
    return this.name;
  }
}

let jack = new Person();
// 假设代码中没有对name赋值，即没有调用"jack.setName('Jack')"
jack.getName().length; // 运行时异常：name is undefined
```

在ArkTS中，开发者应该这样写代码。

```typescript
class Person {
  name: string = '';
  
  setName(n:string): void {
    this.name = n;
  }
  
  // 类型为'string'，不可能为"null"或者"undefined"
  getName(): string {
    return this.name;
  }
}
  

let jack = new Person();
// 假设代码中没有对name赋值，即没有调用"jack.setName('Jack')"
jack.getName().length; // 0, 没有运行时异常
```

接下来的代码示例展示了当`name`的值可能为`undefined`时，如何正确编写代码。

```typescript
class Person {
  name?: string; // 可能为`undefined`

  setName(n:string): void {
    this.name = n;
  }

  // 编译时错误：name可以是"undefined"，所以这个API的返回值类型不能仅定义为string类型
  getNameWrong(): string {
    return this.name;
  }

  getName(): string | undefined { // 返回类型匹配name的类型
    return this.name;
  }
}

let jack = new Person();
// 假设代码中没有对name赋值，即没有调用"jack.setName('Jack')"

// 编译时错误：编译器认为下一行代码有可能会访问undefined的属性，报错
jack.getName().length;  // 编译失败

jack.getName()?.length; // 编译成功，没有运行时错误
```

**getter和setter**

setter和getter可用于提供对对象属性的受控访问。

在以下示例中，setter用于禁止将`_age`属性设置为无效值：

```typescript
class Person {
  name: string = '';
  private _age: number = 0;
  get age(): number { return this._age; }
  set age(x: number) {
    if (x < 0) {
      throw Error('Invalid age argument');
    }
    this._age = x;
  }
}

let p = new Person();
p.age; // 输出0
p.age = -42; // 设置无效age值会抛出错误
```

在类中可以定义getter或者setter。

### 方法

方法属于类。类可以定义实例方法或者静态方法。静态方法属于类本身，只能访问静态字段。而实例方法既可以访问静态字段，也可以访问实例字段，包括类的私有字段。

**实例方法**

以下示例说明了实例方法的工作原理。

`calculateArea`方法计算矩形面积：

```typescript
class RectangleSize {
  private height: number = 0;
  private width: number = 0;
  constructor(height: number, width: number) {
    this.height = height;
    this.width = width;
  }
  calculateArea(): number {
    return this.height * this.width;
  }
}
```

必须通过类的实例调用实例方法：

```typescript
let square = new RectangleSize(10, 10);
square.calculateArea(); // 输出：100
```

**静态方法**

使用关键字 `static` 声明静态方法。静态方法属于类，只能访问静态字段。

静态方法定义了类作为一个整体的公共行为。

必须通过类名调用静态方法：

```typescript
class Cl {
  static staticMethod(): string {
    return 'this is a static method.';
  }
}
console.info(Cl.staticMethod());
```

**继承**

一个类可以继承另一个类（称为基类），并使用以下语法实现多个接口：

```typescript
class [extends BaseClassName] [implements listOfInterfaces] {
  // ...
}
```

继承类继承基类的字段和方法，但不继承构造函数。继承类可以新增定义字段和方法，也可以覆盖其基类定义的方法。

基类也称为“父类”或“超类”。继承类也称为“派生类”或“子类”。

示例：

```typescript
class Person {
  name: string = '';
  private _age = 0;
  get age(): number {
    return this._age;
  }
}
class Employee extends Person {
  salary: number = 0;
  calculateTaxes(): number {
    return this.salary * 0.42;
  }
}
```

包含`implements`子句的类必须实现列出的接口中定义的所有方法，但使用默认实现定义的方法除外。

```typescript
interface DateInterface {
  now(): string;
}
class MyDate implements DateInterface {
  now(): string {
    // 在此实现
    return 'now';
  }
}
```

**父类访问**

关键字`super`可用于访问父类的实例字段、实例方法和构造函数。在实现子类功能时，可以通过该关键字从父类中获取所需接口：

```typescript
class RectangleSize {
  protected height: number = 0;
  protected width: number = 0;

  constructor (h: number, w: number) {
    this.height = h;
    this.width = w;
  }

  draw() {
    /* 绘制边界 */
  }
}
class FilledRectangle extends RectangleSize {
  color = ''
  constructor (h: number, w: number, c: string) {
    super(h, w); // 父类构造函数的调用
    this.color = c;
  }

  draw() {
    super.draw(); // 父类方法的调用
    // super.height -可在此处使用
    /* 填充矩形 */
  }
}
```

**方法重写**

子类可以重写其父类中定义的方法的实现。重写的方法必须具有与原始方法相同的参数类型和相同或派生的返回类型。

```typescript
class RectangleSize {
  // ...
  area(): number {
    // 实现
    return 0;
  }
}
class Square extends RectangleSize {
  private side: number = 0;
  area(): number {
    return this.side * this.side;
  }
}
```

**方法重载签名**

通过重载签名，指定方法的不同调用。具体方法为，为同一个方法写入多个同名但签名不同的方法头，方法实现紧随其后。

```typescript
class C {
  foo(x: number): void;            /* 第一个签名 */
  foo(x: string): void;            /* 第二个签名 */
  foo(x: number | string): void {  /* 实现签名 */
  }
}
let c = new C();
c.foo(123);     // OK，使用第一个签名
c.foo('aa'); // OK，使用第二个签名
```

如果两个重载签名的名称和参数列表均相同，则为错误。

### 构造函数

类声明可以包含用于初始化对象状态的构造函数。

构造函数定义如下：

```typescript
constructor ([parameters]) {
  // ...
}
```

如果未定义构造函数，则会自动创建具有空参数列表的默认构造函数，例如：

```typescript
class Point {
  x: number = 0;
  y: number = 0;
}
let p = new Point();
```

在这种情况下，默认构造函数使用字段类型的默认值初始化实例中的字段。

**派生类的构造函数**

构造函数函数体的第一条语句可以使用关键字`super`来显式调用直接父类的构造函数。

```typescript
class RectangleSize {
  constructor(width: number, height: number) {
    // ...
  }
}
class Square extends RectangleSize {
  constructor(side: number) {
    super(side, side);
  }
}
```

**构造函数重载签名**

可以通过编写重载签名，指定构造函数的不同调用方式。具体方法是，为同一个构造函数写入多个同名但签名不同的构造函数头，构造函数实现紧随其后。

```typescript
class C {
  constructor(x: number)             /* 第一个签名 */
  constructor(x: string)             /* 第二个签名 */
  constructor(x: number | string) {  /* 实现签名 */
  }
}
let c1 = new C(123);      // OK，使用第一个签名
let c2 = new C('abc');    // OK，使用第二个签名
```

如果两个重载签名的名称和参数列表均相同，则为错误。

### 可见性修饰符

类的方法和属性都可以使用可见性修饰符。

可见性修饰符包括：`private`、`protected`和`public`。默认可见性为`public`。

**Public（公有）**

`public`修饰的类成员（字段、方法、构造函数）在程序的任何可访问该类的地方都是可见的。

**Private（私有）**

`private`修饰的成员不能在声明该成员的类之外访问，例如：

```typescript
class C {
  public x: string = '';
  private y: string = '';
  set_y (new_y: string) {
    this.y = new_y; // OK，因为y在类本身中可以访问
  }
}
let c = new C();
c.x = 'a'; // OK，该字段是公有的
c.y = 'b'; // 编译时错误：'y'不可见
```

**Protected（受保护）**

`protected`修饰符的作用与`private`修饰符非常相似，不同点是`protected`修饰的成员允许在派生类中访问，例如：

```typescript
class Base {
  protected x: string = '';
  private y: string = '';
}
class Derived extends Base {
  foo() {
    this.x = 'a'; // OK，访问受保护成员
    this.y = 'b'; // 编译时错误，'y'不可见，因为它是私有的
  }
}
```

### 对象字面量

对象字面量是一个表达式，可用于创建类实例并提供一些初始值。它在某些情况下更方便，可以用来代替`new`表达式。

对象字面量的表示方式是：封闭在花括号对({})中的'属性名：值'的列表。

```typescript
class C {
  n: number = 0;
  s: string = '';
}

let c: C = {n: 42, s: 'foo'};
```

ArkTS是静态类型语言，如上述示例所示，对象字面量只能在可以推导出该字面量类型的上下文中使用。其他正确的例子如下所示：

```typescript
class C {
  n: number = 0;
  s: string = '';
}

function foo(c: C) {}

let c: C

c = {n: 42, s: 'foo'};  // 使用变量的类型
foo({n: 42, s: 'foo'}); // 使用参数的类型

function bar(): C {
  return {n: 42, s: 'foo'}; // 使用返回类型
}
```

也可以在数组元素类型或类字段类型中使用：

```typescript
class C {
  n: number = 0;
  s: string = '';
}
let cc: C[] = [{n: 1, s: 'a'}, {n: 2, s: 'b'}];
```

**`Record`类型的对象字面量**

泛型`Record<K, V>`用于将类型（键类型）的属性映射到另一个类型（值类型）。常用对象字面量来初始化该类型的值：

```typescript
let map: Record<string, number> = {
  'John': 25,
  'Mary': 21,
}

map['John']; // 25
```

类型`K`可以是字符串类型或数值类型(不包括bigint)，而`V`可以是任何类型。

```typescript
interface PersonInfo {
  age: number;
  salary: number;
}
let map: Record<string, PersonInfo> = {
  'John': { age: 25, salary: 10},
  'Mary': { age: 21, salary: 20}
}
```

### 抽象类 

带有`abstract`修饰符的类称为抽象类。抽象类可用于表示一组更具体的概念所共有的概念。

尝试创建抽象类的实例会导致编译错误：

```typescript
abstract class X {
  field: number;
  constructor(p: number) {
    this.field = p; 
  }
}

let x = new X(666)  //编译时错误：不能创建抽象类的具体实例
```

抽象类的子类可以是抽象类也可以是非抽象类。抽象父类的非抽象子类可以实例化。因此，执行抽象类的构造函数和该类非静态字段的字段初始化器：

```typescript
abstract class Base {
  field: number;
  constructor(p: number) { 
    this.field = p; 
  }
}

class Derived extends Base {
  constructor(p: number) {
    super(p); 
  }
}

let x = new Derived(666);
```

**抽象方法**

带有`abstract`修饰符的方法称为抽象方法，抽象方法可以被声明但不能被实现。

只有抽象类内才能有抽象方法，如果非抽象类具有抽象方法，则会发生编译时错误：

```typescript
class Y {
  abstract method(p: string)  //编译时错误：抽象方法只能在抽象类内。
}
```

## 接口

接口声明引入新类型。接口是定义代码协定的常见方式。

任何类的实例，只要实现了特定接口，即可通过该接口实现多态。

接口通常包含属性和方法的声明。

示例：

```typescript
interface Style {
  color: string; // 属性
}
interface AreaSize {
  calculateAreaSize(): number; // 方法的声明
  someMethod(): void;     // 方法的声明
}
```

实现接口的类示例：

```typescript
// 接口：
interface AreaSize {
  calculateAreaSize(): number; // 方法的声明
  someMethod(): void;     // 方法的声明
}

// 实现：
class RectangleSize implements AreaSize {
  private width: number = 0;
  private height: number = 0;
  someMethod(): void {
    console.info('someMethod called');
  }
  calculateAreaSize(): number {
    this.someMethod(); // 调用另一个方法并返回结果
    return this.width * this.height;
  }
}
```

### 接口属性

接口属性可以是字段、getter、setter或getter和setter组合的形式。

属性字段只是getter/setter对的便捷写法。以下表达方式是等价的：

```typescript
interface Style {
  color: string;
}
```

```typescript
interface Style {
  get color(): string;
  set color(x: string);
}
```

实现接口的类也可以使用以下两种方式：

```typescript
interface Style {
  color: string;
}

class StyledRectangle implements Style {
  color: string = '';
}
```

```typescript
interface Style {
  color: string;
}

class StyledRectangle implements Style {
  private _color: string = '';
  get color(): string { return this._color; }
  set color(x: string) { this._color = x; }
}
```

### 接口继承

接口可以继承其他接口，示例如下：

```typescript
interface Style {
  color: string;
}

interface ExtendedStyle extends Style {
  width: number;
}
```

继承接口包含被继承接口的所有属性和方法，还可以添加自己的属性和方法。


### 抽象类和接口

抽象类与接口都无法实例化。抽象类是类的抽象，抽象类用来捕捉子类的通用特性，接口是行为的抽象。在ArkTS语法中抽象类与接口的区别如下：

* 一个类只能继承一个抽象类，而一个类可以实现一个或多个接口；
```typescript
// Bird类继承Animal抽象类并实现多个接口CanFly、CanSwim
class Bird extends Animal implements CanFly, CanSwim {
  // ...  
}
```
* 接口中不能含有静态代码块以及静态方法，而抽象类可以有静态代码块和静态方法；
```typescript
interface MyInterface {
    // 错误：接口中不能包含静态成员
    static staticMethod(): void; 

    // 错误：接口中不能包含静态代码块
    static { console.info("static") }; 
} 

abstract class MyAbstractClass {
    // 正确：抽象类可以有静态方法
    static staticMethod(): void { console.info("static");}

    // 正确：抽象类可以有静态代码块
    static { console.info("static initialization block");}
}
```
* 抽象类里面可以有方法的实现，但是接口没有方法的实现，是完全抽象的；
```typescript
abstract class MyAbstractClass {
   // 正确：抽象类里面可以有方法的实现
   func(): void { console.info("func");}
}
interface MyInterface {
   // 错误：接口没有方法的实现，是完全抽象的
   func(): void { console.info("func");}
}
```
* 抽象类可以有构造函数，而接口不能有构造函数。
```typescript
abstract class MyAbstractClass {
  constructor(){}  // 正确：抽象类可以有构造函数
}
interface MyInterface {
  constructor(); // 错误：接口中不能有构造函数
}
```

## 泛型类型和函数

泛型类型和函数使代码能够以类型安全的方式操作多种数据类型，而无需为每种类型编写重复的逻辑。

### 泛型类和接口

类和接口可以定义为泛型，将参数添加到类型定义中。如以下示例中的类型参数`Element`：

```typescript
class CustomStack<Element> {
  public push(e: Element):void {
    // ...
  }
}
```

要使用类型CustomStack，必须为每个类型参数指定类型实参：

```typescript
let s = new CustomStack<string>();
s.push('hello');
```

编译器在使用泛型类型和函数时会确保类型安全。参见以下示例：

```typescript
let s = new CustomStack<string>();
s.push(55); // 将会产生编译时错误
```

### 泛型约束

泛型类型的类型参数可以被限制只能取某些特定的值。例如，`MyHashMap<Key, Value>`这个类中的`Key`类型参数必须具有`hash`方法。

```typescript
interface Hashable {
  hash(): number;
}
class MyHashMap<Key extends Hashable, Value> {
  public set(k: Key, v: Value) {
    let h = k.hash();
    // ...其他代码...
  }
}
```

在上面的例子中，`Key`类型扩展了`Hashable`，`Hashable`接口的所有方法都可以为key调用。

### 泛型函数

使用泛型函数可编写更通用的代码。比如返回数组最后一个元素的函数：

```typescript
function last(x: number[]): number {
  return x[x.length - 1];
}
last([1, 2, 3]); // 3
```

如果需要为任何数组定义相同的函数，使用类型参数将该函数定义为泛型：

```typescript
function last<T>(x: T[]): T {
  return x[x.length - 1];
}
```

现在，该函数可以与任何数组一起使用。

在函数调用中，类型实参可以显式或隐式设置：

```typescript
// 显式设置的类型实参
let res: string = last<string>(['aa', 'bb']);
let res: number = last<number>([1, 2, 3]);

// 隐式设置的类型实参
// 编译器根据调用参数的类型来确定类型实参
let res: number = last([1, 2, 3]);
```

### 泛型默认值

泛型类型的类型参数可以设置默认值，这样无需指定实际类型实参，直接使用泛型类型名称即可。以下示例展示了类和函数的这一特性。

```typescript
class SomeType {}
interface Interface <T1 = SomeType> { }
class Base <T2 = SomeType> { }
class Derived1 extends Base implements Interface { }
// Derived1在语义上等价于Derived2
class Derived2 extends Base<SomeType> implements Interface<SomeType> { }

function foo<T = number>(): void {
  // ...
}
foo();
// 此函数在语义上等价于下面的调用
foo<number>();
```

## 空安全

默认情况下，ArkTS中的所有类型都不允许为空，这类似于TypeScript的(`strictNullChecks`)模式，但规则更严格。

在下面的示例中，所有行都会导致编译时错误：

```typescript
let x: number = null;    // 编译时错误
let y: string = null;    // 编译时错误
let z: number[] = null;  // 编译时错误
```

可以为空值的变量定义为联合类型`T | null`。

```typescript
let x: number | null = null;
x = 1;    // ok
x = null; // ok
if (x != null) { /* do something */ }
```

### 非空断言运算符

后缀运算符`!`可用于断言其操作数为非空。

当应用于可空类型的值时，编译时类型会变为非空类型。例如，类型从`T | null`变为`T`：

```typescript
class A {
  value: number = 0;
}

function foo(a: A | null) {
  a.value;   // 编译时错误：无法访问可空值的属性
  a!.value;  // 编译通过，如果运行时a的值非空，可以访问到a的属性；如果运行时a的值为空，则发生运行时异常
}
```

### 空值合并运算符

空值合并二元运算符`??`用于检查左侧表达式的求值是否等于`null`或者`undefined`。如果是，则表达式的结果为右侧表达式；否则，结果为左侧表达式。

换句话说，`a ?? b`等价于三元运算符`(a != null && a != undefined) ? a : b`。

在以下示例中，`getNick`方法返回已设置的昵称。如果未设置，则返回空字符串。

```typescript
class Person {
  // ...
  nick: string | null = null;
  getNick(): string {
    return this.nick ?? '';
  }
}
```

### 可选链

访问对象属性时，如果属性是`undefined`或`null`，可选链运算符返回`undefined`。

```typescript
class Person {
  nick: string | null = null;
  spouse?: Person

  setSpouse(spouse: Person): void {
    this.spouse = spouse;
  }

  getSpouseNick(): string | null | undefined {
    return this.spouse?.nick;
  }

  constructor(nick: string) {
    this.nick = nick;
    this.spouse = undefined;
  }
}
```

**说明**：`getSpouseNick`的返回类型必须为`string | null | undefined`，因为该方法在某些情况下会返回`null`或`undefined`。

可选链可以任意长，可以包含任意数量的`?.`运算符。

在以下示例中，如果`Person`实例的`spouse`属性不为空，并且`spouse`的`nick`属性也不为空时，输出`spouse.nick`。否则，输出`undefined`。

```typescript
class Person {
  nick: string | null = null;
  spouse?: Person;

  constructor(nick: string) {
    this.nick = nick;
    this.spouse = undefined;
  }
}

let p: Person = new Person('Alice');
p.spouse?.nick; // undefined
```

## 模块

程序可划分为多组编译单元或模块。

每个模块都有其自己的作用域，即在模块中创建的任何声明（变量、函数、类等）在该模块之外都不可见，除非它们被显式导出。

与此相对，必须首先将另一个模块导出的变量、函数、类、接口等导入到当前模块中。

### 导出

可以使用关键字`export`导出顶层的声明。

未导出的声明名称被视为私有名称，只能在声明该名称的模块中使用。

```typescript
export class Point {
  x: number = 0;
  y: number = 0;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}
export let Origin = new Point(0, 0);
export function Distance(p1: Point, p2: Point): number {
  return Math.sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
```
**导出默认导出的对象**
```typescript
class Demo{
  constructor(){
  }
}
export default new Demo();

```

### 导入

**静态导入**

导入声明用于导入从其他模块导出的实体，并在当前模块中提供其绑定。导入声明由两部分组成：

* 导入路径，用于指定导入的模块；
* 导入绑定，用于定义导入的模块中的可用实体集和使用形式（限定或不限定使用）。

导入绑定可以有几种形式。

假设模块的路径为“./utils”，并且导出了实体“X”和“Y”。

导入绑定`* as A`表示绑定名称“A”，通过`A.name`可访问从导入路径指定的模块导出的所有实体：

```typescript
import * as Utils from './utils';
Utils.X // 表示来自Utils的X
Utils.Y // 表示来自Utils的Y
```

导入绑定`{ ident1, ..., identN }`表示将导出的实体与指定名称绑定，该名称可以用作简单名称：

```typescript
import { X, Y } from './utils';
X // 表示来自utils的X
Y // 表示来自utils的Y
```

如果标识符列表定义了`ident as alias`，则实体`ident`将绑定在名称`alias`下：

```typescript
import { X as Z, Y } from './utils';
Z // 表示来自Utils的X
Y // 表示来自Utils的Y
X // 编译时错误：'X'不可见
```

**动态导入**
在应用开发的有些场景中，如果希望根据条件导入模块或者按需导入模块，可以使用动态导入代替静态导入。
import()语法被称为动态导入（dynamic import），是一种类似函数的表达式，用于动态导入模块。调用这种方式，会返回一个promise。
如下例所示，import(modulePath)可以加载模块并返回一个promise，该promise resolve为一个包含其所有导出的模块对象。该表达式可以在代码中的任意位置调用。

```typescript
// Calc.ts
export function add(a:number, b:number):number {
  let c = a + b;
  console.info('Dynamic import, %d + %d = %d', a, b, c);
  return c;
}

// Index.ts
import("./Calc").then((obj: ESObject) => {
  console.info(obj.add(3, 5));  
}).catch((err: Error) => {
  console.error("Module dynamic import error: ", err);
});
```

如果在异步函数中，可以使用let module = await import(modulePath)。

```typescript
// say.ts
export function hi() {
  console.info('Hello');
}
export function bye() {
  console.info('Bye');
}
```

那么，可以像下面这样进行动态导入：

```typescript
async function test() {
  let ns = await import('./say');
  let hi = ns.hi;
  let bye = ns.bye;
  hi();
  bye();
}
```

更多的使用动态import的业务场景和使用实例见[动态import](../arkts-utils/arkts-dynamic-import.md)。

<!--RP2--><!--RP2End-->

### 顶层语句

顶层语句是指在模块最外层编写的语句，不被任何函数、类或块级作用域包裹。这些语句包括变量声明、函数声明和表达式。

## 关键字

### this

关键字`this`只能在类的实例方法中使用。

**示例**

```typescript
class A {
  count: string = 'a';
  m(i: string): void {
    this.count = i;
  }
}
```

使用限制：

* 不支持`this`类型
* 不支持在函数和类的静态方法中使用`this`

**示例**

```typescript
class A {
  n: number = 0;
  f1(arg1: this) {} // 编译时错误，不支持this类型
  static f2(arg1: number) {
    this.n = arg1;  // 编译时错误，不支持在类的静态方法中使用this
  }
}

function foo(arg1: number) {
  this.n = i;       // 编译时错误，不支持在函数中使用this
}
```

关键字`this`的指向:

* 调用实例方法的对象
* 正在构造的对象

## 注解

注解（Annotation）是一种语言特性，它通过添加元数据来改变应用声明的语义。
注解的声明和使用如下所示：

**示例：**

```typescript
// 注解的声明：
@interface ClassAuthor {
  authorName: string
}

// 注解的使用：
@ClassAuthor({authorName: "Bob"})
class MyClass {
  // ...
}
```

- 使用@interface声明注解。
- 注解`ClassAuthor`需要将元信息添加到类声明中。
- 注解必须放置在声明之前。
- 注解可以包含上述示例中所示的参数。

对于要使用的注解，其名称必须以符号`@`（例如：@MyAnno）为前缀。符号`@`和名称之间不允许有空格和行分隔符。
```typescript
ClassAuthor({authorName: "Bob"}) // 编译错误：注解需要'@'为前缀
@ ClassAuthor({authorName: "Bob"}) // 编译错误：符号`@`和名称之间不允许有空格和行分隔符
```
如果在使用位置无法访问注解名称，则会发生编译错误。
注解声明可以导出并在其他文件中使用。

多个注解可以应用于同一个声明（注解间的先后顺序不影响使用）。
```typescript
@MyAnno()
@ClassAuthor({authorName: "John Smith"})
class MyClass {
  // ...
}
```
注解不是Typescript中的特性，只能在`.ets/.d.ets`文件中使用。

> **注意**
> 
> 应用开发中，在[release模式下构建](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har#section19788284410)源码HAR，并同时[开启混淆](../../application-dev/arkts-utils/source-obfuscation.md)时，由于编译产物为JS文件，而在JS中没有注解的实现机制，因此会在编译过程中被移除，导致无法通过注解实现AOP插桩。
>
> 为避免因此引起的功能异常，禁止在JS HAR(编译产物中存在JS的HAR包)中使用注解。
>
> 如果需要在release模式并且开启混淆的情况下构建含有注解的HAR包，可以构建[字节码HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har#section16598338112415)。

### 用户自定义注解

**从API version 20及之后版本，支持用户自定义注解。**

**用户自定义注解的声明**
`用户自定义注解`的定义与`interface`的定义类似，其中的`interface`关键字以符号`@`为前缀。<br>
注解字段仅限于下面列举的类型：
* number
* boolean
* string
* 枚举
* 以上类型的数组
>**说明：**
>
> - 如果使用其他类型用作注解字段的类型，则会发生编译错误。
> - 注解字段类型不支持bigint。

注解字段的默认值必须使用常量表达式来指定。<br>常量表达式的场景如下所示：
* 数字字面量
* 布尔字面量
* 字符串字面量
* 枚举值（需要在编译时确定值）
* 以上常量组成的数组
>**说明：**
>
> 如果枚举值不能在编译时确定，会编译报错。
```typescript
// a.ts
export enum X {
  x = foo(); // x不是编译时能确定的常量
}

// b.ets
import {X} from './a';

@interface Position {
  data: number = X.x; // 编译错误：注解字段的默认值必须使用常量表达式
}
```
注解必须定义在顶层作用域（top-level），否则会出现编译报错。<br>
注解的名称不能与注解定义所在作用域内可见的其他实体名称相同，否则会出现编译报错。<br>
注解不支持类型Typescript中的合并，否则会出现编译报错。
```typescript
namespace ns {
  @interface MataInfo { // 编译错误：注解必须定义在顶层作用域
    // ...
  }
}

@interface Position {
  // ...
}

class Position { // 编译错误：注解的名称不能与注解定义所在作用域内可见的其他实体名称相同
  // ...
}

@interface ClassAuthor {
  name: string;
}

@interface ClassAuthor { // 编译错误：注解的名称不能与注解定义所在作用域内可见的其他实体名称相同
  data: sting;
}
```
注解不是类型，把注解当类型使用时会出现编译报错（例如：对注解使用类型别名）。
```typescript
@interface Position {}
type Pos = Position; // 编译错误：注解不是类型
```
注解不支持在类的getter和setter方法中添加，若添加注解会编译报错。
```typescript
@interface ClassAuthor {
  authorName: string;
}

@ClassAuthor({authorName: "John Smith"})
class MyClass {
  private _name: string = "Bob";

  @ClassAuthor({authorName: "John Smith"}) // 编译错误：注解不支持在类的getter和setter方法添加
  get name() {
    return this._name;
  }

  @ClassAuthor({authorName: "John Smith"}) // 编译错误：注解不支持在类的getter和setter方法添加
  set name(authorName: string) {
    this._name = authorName;
  }
}
```

**用户自定义注解的使用**
注解声明示例如下：
```typescript
@interface ClassPreamble {
  authorName: string;
  revision: number = 1;
}
@interface MyAnno {}
```
当前仅允许对`class declarations`和`method declarations`使用注解，对类和方法可以同时使用同一个注解。<br>注解用法示例如下：
```typescript
@ClassPreamble({authorName: "John", revision: 2})
class C1 {
  // ...
}

@ClassPreamble({authorName: "Bob"}) // revision的默认值为1
class C2 {
  // ...
}

@MyAnno() // 对类和方法可以同时使用同一个注解
class C3 {
  @MyAnno()
  foo() {}
  @MyAnno()
  static bar() {}
}
```
注解中的字段顺序不影响使用。
```typescript
@ClassPreamble({authorName: "John", revision: 2})
// the same as:
@ClassPreamble({revision: 2, authorName: "John"})
```
使用注解时，必须给所有没有默认值的字段赋值，否则会发生编译错误。
>**说明：**
>
> 赋值应当与注解声明的类型一致，所赋的值与注解字段默认值的要求一样，只能使用常量表达式。
```typescript
@ClassPreamble() // 编译错误：authorName字段未定义
class C1 {
  // ...
}
```
如果注解中定义了数组类型的字段，则使用数组字面量来设置该字段的值。
```typescript
@interface ClassPreamble {
  authorName: string;
  revision: number = 1;
  reviewers: string[];
}

@ClassPreamble(
  {
    authorName: "Alice",
    reviewers: ["Bob", "Clara"]
  }
)
class C3 {
  // ...
}
```
如果不需要定义注解字段，可以省略注解名称后的括号。
```typescript
@MyAnno
class C4 {
  // ...
}
```

**导入和导出注解**
注解也可以被导入导出。针对导出，当前仅支持在定义时的导出，即`export @interface`的形式。<br>
**示例：**
```typescript
export @interface MyAnno {}
```
针对导入，当前仅支持`import {}`和`import * as`两种方式。<br>
**示例：**
```typescript
// a.ets
export @interface MyAnno {}
export @interface ClassAuthor {}

// b.ets
import { MyAnno } from './a';
import * as ns from './a';

@MyAnno
@ns.ClassAuthor
class C {
  // ...
}
```
- 不允许在import中对注解进行重命名。
```typescript
import { MyAnno as Anno } from './a'; // 编译错误：不允许在import中对注解进行重命名
```
不允许对注解使用任何其他形式的 import/export，这会导致编译报错。
- 由于注解不是类型，因此禁止使用`type`符号进行导入和导出。
```typescript
import type { MyAnno } from './a'; // 编译错误：注解不允许使用'type'符号进行导入和导出
```

- 如果仅从模块导入注解，则不会触发模块的副作用。
```typescript
// a.ets
export @interface Anno {}

export @interface ClassAuthor {}

console.info("hello");

// b.ets
import { Anno } from './a';
import * as ns from './a';

@MyAnno
@ns.ClassAuthor // 仅引用了ns的注解，不会导致a.ets的console.info执行
class X {
  // ...
}
```

**.d.ets文件中的注解**
注解可以出现在.d.ets文件中。
可以在.d.ets文件中用环境声明（ambient declaration）来声明注解。
```typescript
ambientAnnotationDeclaration:
  'declare' userDefinedAnnotationDeclaration
  ;
```

**示例：**
```typescript
// a.d.ets
export declare @interface ClassAuthor {}
```
上述声明中：
- 不会引入新的注解定义，而是提供注解的类型信息。
- 注解需定义在其他源代码文件中。
- 注解的环境声明和实现需要完全一致，包括字段的类型和默认值。
```typescript
// a.d.ets
export declare @interface NameAnno{name: string = ""}

// a.ets
export @interface NameAnno{name: string = ""} // ok
```
环境声明的注解和class类似，也可以被import使用。
```typescript
// a.d.ets
export declare @interface MyAnno {}

// b.ets
import { MyAnno } from './a';

@MyAnno
class C {
  // ...
}
```

**编译器自动生成的.d.ets文件**<br>
当编译器根据ets代码自动生成.d.ets文件时，存在以下2种情况。
1. 当注解定义被导出时，源代码中的注解定义会在.d.ets文件中保留。
```typescript
// a.ets
export @interface ClassAuthor {}

@interface MethodAnno { // 没导出
  data: number;
}

// a.d.ets 编译器生成的声明文件
export declare @interface ClassAuthor {}
```
2. 当下面所有条件成立时，源代码中实体的注解实例会在.d.ets文件中保留。<br>
    2.1 注解的定义被导出（import的注解也算作被导出）。<br>
    2.2 如果实体是类，则类被导出。<br>
    2.3 如果实体是方法，则类被导出，并且方法不是私有方法。
```typescript
// a.ets
import { ClassAuthor } from './author';

export @interface MethodAnno {
  data: number = 0;
}

@ClassAuthor
class MyClass {
  @MethodAnno({data: 123})
  foo() {}

  @MethodAnno({data: 456})
  private bar() {}
}

// a.d.ets 编译器生成的声明文件
import {ClassAuthor} from "./author";

export declare @interface MethodAnno {
  data: number = 0;
}

@ClassAuthor
export declare class MyClass {
  @MethodAnno({data: 123})
  foo(): void;

  bar; // 私有方法不保留注解
}
```

**开发者生成的.d.ets文件**<br>
开发者生成的.d.ets文件中的注解信息不会自动应用到实现的源代码中。<br>
**示例：**
```typescript
// b.d.ets 开发者生成的声明文件
@interface ClassAuthor {}

@ClassAuthor // 声明文件中有注解
class C {
  // ...
}

// b.ets 开发者对声明文件实现的源代码
@interface ClassAuthor {}

// 实现文件中没有注解
class C {
  // ...
}
```
在最终编译产物中，class C没有注解。

**重复注解和继承**
同一个实体不能重复使用同一注解，否则会导致编译错误。
```typescript
@MyAnno({name: "123", value: 456})
@MyAnno({name: "321", value: 654}) // 编译错误：不允许重复注释
class C {
  // ...
}
```
子类不会继承基类的注解，也不会继承基类方法的注解。

**注解和抽象类、抽象方法**
不支持对抽象类或抽象方法使用注解，否则将导致编译错误。
```typescript
@MyAnno // 编译错误：不允许在抽象类和抽象方法上使用注解
abstract class C {
  @MyAnno
  abstract foo(): void; // 编译错误：不允许在抽象类和抽象方法上使用注解
}
```

## ArkUI支持

本节演示ArkTS为创建图形用户界面（GUI）程序提供的机制。ArkUI基于TypeScript提供了一系列扩展能力，以声明式地描述应用程序的GUI以及GUI组件间的交互。


### ArkUI示例

[MVVM代码示例](../ui/state-management/arkts-mvvm.md#代码示例)提供了一个完整的基于ArkUI的应用程序，以展示其GUI编程功能。

有关ArkUI功能的更多详细信息，请参见ArkUI[基本语法概述](../ui/state-management/arkts-basic-syntax-overview.md)。
