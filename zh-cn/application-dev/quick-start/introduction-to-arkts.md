# ArkTS语言介绍

ArkTS是一种为构建高性能应用而设计的编程语言。ArkTS在继承TypeScript语法的基础上进行了优化，以提供更高的性能和开发效率。

随着移动设备在人们的日常生活中变得越来越普遍，许多编程语言在设计之初没有考虑到移动设备，导致应用的运行缓慢、低效、功耗大，针对移动环境的编程语言优化需求也越来越大。ArkTS是专为解决这些问题而设计的，聚焦于提高运行效率。

目前流行的编程语言TypeScript是在JavaScript基础上通过添加类型定义扩展而来的，而ArkTS则是TypeScript的进一步扩展。TypeScript深受开发者的喜爱，因为它提供了一种更结构化的JavaScript编码方法。ArkTS旨在保持TypeScript的大部分语法，为现有的TypeScript开发者实现无缝过渡，让移动开发者快速上手ArkTS。

ArkTS的一大特性是它专注于低运行时开销。ArkTS对TypeScript的动态类型特性施加了更严格的限制，以减少运行时开销，提高执行效率。通过取消动态类型特性，ArkTS代码能更有效地被运行前编译和优化，从而实现更快的应用启动和更低的功耗。

与JavaScript的互通性是ArkTS语言设计中的关键考虑因素。鉴于许多移动应用开发者希望重用其TypeScript和JavaScript代码和库，ArkTS提供了与JavaScript的无缝互通，使开发者可以很容易地将JavaScript代码集成到他们的应用中。这意味着开发者可以利用现有的代码和库进行ArkTS开发。

为了确保应用开发的最佳体验，ArkTS提供对方舟开发框架ArkUI的声明式语法和其他特性的支持。由于此部分特性不在既有TypeScript的范围内，因此我们在《ArkUI支持》一章中提供了详细的ArkUI示例。

本教程将指导开发者了解ArkTS的核心功能、语法和最佳实践，使开发者能够使用ArkTS高效构建高性能的移动应用。<!--Del-->编程规范请参考[ArkTS语言规范](../../contribute/OpenHarmony-ArkTS-coding-style-guide.md)。<!--DelEnd-->

## 基本知识

### 声明

ArkTS通过声明引入变量、常量、函数和类型。

#### 变量声明

以关键字`let`开头的声明引入变量，该变量在程序执行期间可以具有不同的值。

```typescript
let hi: string = 'hello';
hi = 'hello, world';
```

#### 常量声明

以关键字`const`开头的声明引入只读常量，该常量只能被赋值一次。

```typescript
const hello: string = 'hello';
```

对常量重新赋值会造成编译时错误。

#### 自动类型推断

由于ArkTS是一种静态类型语言，所有数据的类型都必须在编译时确定。

但是，如果一个变量或常量的声明包含了初始值，那么开发者就不需要显式指定其类型。ArkTS规范中列举了所有允许自动推断类型的场景。

以下示例中，两条声明语句都是有效的，两个变量都是`string`类型：

```typescript
let hi1: string = 'hello';
let hi2 = 'hello, world';
```

### 类型

#### `Number`类型

ArkTS提供`number`和`Number`类型，任何整数和浮点数都可以被赋给此类型的变量。

数字字面量包括整数字面量和十进制浮点数字面量。

整数字面量包括以下类别：

* 由数字序列组成的十进制整数。例如：`0`、`117`、`-345`
* 以0x（或0X）开头的十六进制整数，可以包含数字（0-9）和字母a-f或A-F。例如：`0x1123`、`0x00111`、`-0xF1A7`
* 以0o（或0O）开头的八进制整数，只能包含数字（0-7）。例如：`0o777`
* 以0b（或0B）开头的二进制整数，只能包含数字0和1。例如：`0b11`、`0b0011`、`-0b11`

浮点字面量包括以下：

* 十进制整数，可为有符号数（即，前缀为“+”或“-”）；
* 小数点（“.”）
* 小数部分（由十进制数字字符串表示）
* 以“e”或“E”开头的指数部分，后跟有符号（即，前缀为“+”或“-”）或无符号整数。

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

#### `Boolean`类型

`boolean`类型由`true`和`false`两个逻辑值组成。

通常在条件语句中使用`boolean`类型的变量：

```typescript
let isDone: boolean = false;

// ...

if (isDone) {
  console.log ('Done!');
}
```

#### `String`类型

`string`代表字符序列；可以使用转义字符来表示字符。

字符串字面量由单引号（'）或双引号（"）之间括起来的零个或多个字符组成。字符串字面量还有一特殊形式，是用反向单引号（\`）括起来的模板字面量。

```typescript
let s1 = 'Hello, world!\n';
let s2 = 'this is a string';
let a = 'Success';
let s3 = `The result is ${a}`;
```

#### `Void`类型

`void`类型用于指定函数没有返回值。
此类型只有一个值，同样是`void`。由于`void`是引用类型，因此它可以用于泛型类型参数。

```typescript
class Class<T> {
  //...
}
let instance: Class <void>
```

#### `Object`类型

`Object`类型是所有引用类型的基类型。任何值，包括基本类型的值（它们会被自动装箱），都可以直接被赋给`Object`类型的变量。

#### `Array`类型

`array`，即数组，是由可赋值给数组声明中指定的元素类型的数据组成的对象。
数组可由数组复合字面量（即用方括号括起来的零个或多个表达式的列表，其中每个表达式为数组中的一个元素）来赋值。数组的长度由数组中元素的个数来确定。数组中第一个元素的索引为0。

以下示例将创建包含三个元素的数组：

```typescript
let names: string[] = ['Alice', 'Bob', 'Carol'];
```

#### `Enum`类型

`enum`类型，又称枚举类型，是预先定义的一组命名值的值类型，其中命名值又称为枚举常量。
使用枚举常量时必须以枚举类型名称为前缀。

```typescript
enum ColorSet { Red, Green, Blue }
let c: ColorSet = ColorSet.Red;
```

常量表达式可以用于显式设置枚举常量的值。

```typescript
enum ColorSet { White = 0xFF, Grey = 0x7F, Black = 0x00 }
let c: ColorSet = ColorSet.Black;
```

#### `Union`类型

`union`类型，即联合类型，是由多个类型组合成的引用类型。联合类型包含了变量可能的所有类型。

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
type Animal = Cat | Dog | Frog | number;
// Cat、Dog、Frog是一些类型（类或接口）

let animal: Animal = new Cat();
animal = new Frog();
animal = 42;
// 可以将类型为联合类型的变量赋值为任何组成类型的有效值
```

可以用不同的机制获取联合类型中特定类型的值。
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

#### `Aliases`类型

`Aliases`类型为匿名类型（数组、函数、对象字面量或联合类型）提供名称，或为已有类型提供替代名称。

```typescript
type Matrix = number[][];
type Handler = (s: string, no: number) => string;
type Predicate <T> = (x: T) => boolean;
type NullableObject = Object | null;
```

### 运算符

#### 赋值运算符

赋值运算符`=`，使用方式如`x=y`。

复合赋值运算符将赋值与运算符组合在一起，其中`x op = y`等于`x = x op y`。

复合赋值运算符列举如下：`+=`、`-=`、`*=`、`/=`、`%=`、`<<=`、`>>=`、`>>>=`、`&=`、`|=`、`^=`。

#### 比较运算符

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

#### 算术运算符

一元运算符为`-`、`+`、`--`、`++`。

二元运算符列举如下：

| 运算符| 说明             |
| -------- | ------------------------ |
| `+`      | 加法                |
| `-`      | 减法             |
| `*`      | 乘法          |
| `/`      | 除法                |
| `%`      | 除法后余数|

#### 位运算符

| 运算符 | 说明                                                 |
| --------- | ------------------------------------------------------------ |
| `a & b`   | 按位与：如果两个操作数的对应位都为1，则将这个位设置为1，否则设置为0。|
| `a \| b`  | 按位或：如果两个操作数的相应位中至少有一个为1，则将这个位设置为1，否则设置为0。|
| `a ^ b`   | 按位异或：如果两个操作数的对应位不同，则将这个位设置为1，否则设置为0。|
| `~ a`     | 按位非：反转操作数的位。               |
| `a << b`  | 左移：将a的二进制表示向左移b位。|
| `a >> b`  | 算术右移：将a的二进制表示向右移b位，带符号扩展。|
| `a >>> b` | 逻辑右移：将a的二进制表示向右移b位，左边补0。|

#### 逻辑运算符

| 运算符  | 说明|
| ---------- | ----------- |
| `a && b`   | 逻辑与 |
| `a \|\| b` | 逻辑或 |
| `! a`      | 逻辑非 |

### 语句

#### `If`语句

`if`语句用于需要根据逻辑条件执行不同语句的场景。当逻辑条件为真时，执行对应的一组语句，否则执行另一组语句（如果有的话）。
`else`部分也可能包含`if`语句。

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

条件表达式可以是任何类型。但是对于`boolean`以外的类型，会进行隐式类型转换：

```typescript
let s1 = 'Hello';
if (s1) {
  console.log(s1); // 打印“Hello”
}

let s2 = 'World';
if (s2.length != 0) {
  console.log(s2); // 打印“World”
}
```

#### `Switch`语句

使用`switch`语句来执行与`switch`表达式值匹配的代码块。

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

#### 条件表达式

条件表达式由第一个表达式的布尔值来决定返回其它两个表达式中的哪一个。

示例如下：

```typescript
condition ? expression1 : expression2
```

如果`condition`的为真值（转换后为`true`的值），则使用`expression1`作为该表达式的结果；否则，使用`expression2`。

示例：

```typescript
let isValid = Math.random() > 0.5 ? true : false;
let message = isValid ? 'Valid' : 'Failed';
```

#### `For`语句

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
5、 回到步骤2。  

示例：

```typescript
let sum = 0;
for (let i = 0; i < 10; i += 2) {
  sum += i;
}
```

#### `For-of`语句

使用`for-of`语句可遍历数组或字符串。示例如下：

```typescript
for (forVar of expression) {
  statements
}
```

示例：

```typescript
for (let ch of 'a string object') {
  /* process ch */
}
```

#### `While`语句

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

#### `Do-while`语句

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

#### `Break`语句

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

#### `Continue`语句

`continue`语句会停止当前循环迭代的执行，并将控制传递给下一个迭代。

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

#### `Throw`和`Try`语句

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
    console.log('result: ' + res);
  } catch (x) {
    console.log('some error');
  }
}
```

支持`finally`语句：

```typescript
function processData(s: string) {
  let error: Error | null = null;

  try {
    console.log('Data processed: ' + s);
    // ...
    // 可能发生异常的语句
    // ...
  } catch (e) {
    error = e as Error;
    // ...
    // 异常处理
    // ...
  } finally {
    if (error != null) {
      console.log(`Error caught: input='${s}', message='${error.message}'`);
    }
  }
}
```

## 函数

### 函数声明

函数声明引入一个函数，包含其名称、参数列表、返回类型和函数体。

以下示例是一个简单的函数，包含两个`string`类型的参数，返回类型为`string`：

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
    console.log('Hello!');
  } else {
    console.log(`Hello, ${name}!`);
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

函数的最后一个参数可以是rest参数。使用rest参数时，允许函数或方法接受任意数量的实参。

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
function hi1() { console.log('hi'); }
function hi2(): void { console.log('hi'); }
```

### 函数的作用域

函数中定义的变量和其他实例仅可以在函数内部访问，不能从外部访问。

如果函数中定义的变量与外部作用域中已有实例同名，则函数内的局部变量定义将覆盖外部定义。

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
console.log(x);
```

### 函数类型

函数类型通常用于定义回调：

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

箭头函数的返回类型可以省略；省略时，返回类型通过函数体推断。

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

我们可以通过编写重载，指定函数的不同调用方式。具体方法为，为同一个函数写入多个同名但签名不同的函数头，函数实现紧随其后。

```typescript
function foo(x: number): void;            /* 第一个函数定义 */
function foo(x: string): void;            /* 第二个函数定义 */
function foo(x: number | string): void {  /* 函数实现 */
}

foo(123);     //  OK，使用第一个定义
foo('aa'); // OK，使用第二个定义
```

不允许重载函数有相同的名字以及参数列表，否则将会编译报错。

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
console.log(p.fullName());
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

#### 实例字段

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
p1.name;
let p2 = new Person('Bob', 28);
p2.getName();
```

#### 静态字段

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

#### 字段初始化

为了减少运行时的错误和获得更好的执行性能，
ArkTS要求所有字段在声明时或者构造函数中显式初始化。这和标准TS中的`strictPropertyInitialization`模式一样。

以下代码是在ArkTS中不合法的代码。

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
// 假设代码中没有对name赋值，例如调用"jack.setName('Jack')"
jack.getName().length; // 运行时异常：name is undefined
```

在ArkTS中，应该这样写代码。

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
// 假设代码中没有对name赋值，例如调用"jack.setName('Jack')"
jack.getName().length; // 0, 没有运行时异常
```

接下来的代码展示了如果`name`的值可以是`undefined`，那么应该如何写代码。

```typescript
class Person {
  name?: string; // 可能为`undefined`

  setName(n:string): void {
    this.name = n;
  }

  // 编译时错误：name可以是"undefined"，所以将这个API的返回值类型标记为string
  getNameWrong(): string {
    return this.name;
  }

  getName(): string | undefined { // 返回类型匹配name的类型
    return this.name;
  }
}

let jack = new Person();
// 假设代码中没有对name赋值，例如调用"jack.setName('Jack')"

// 编译时错误：编译器认为下一行代码有可能会访问undefined的属性，报错
jack.getName().length;  // 编译失败

jack.getName()?.length; // 编译成功，没有运行时错误
```

#### getter和setter

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

#### 实例方法

以下示例说明了实例方法的工作原理。

`calculateArea`方法通过将高度乘以宽度来计算矩形的面积：

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

#### 静态方法

使用关键字`static`将方法声明为静态。静态方法属于类本身，只能访问静态字段。

静态方法定义了类作为一个整体的公共行为。

必须通过类名调用静态方法：

```typescript
class Cl {
  static staticMethod(): string {
    return 'this is a static method.';
  }
}
console.log(Cl.staticMethod());
```

#### 继承

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

#### 父类访问

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

#### 方法重写

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

#### 方法重载签名

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

在这种情况下，默认构造函数使用字段类型的默认值来初始化实例中的字段。

#### 派生类的构造函数

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

#### 构造函数重载签名

我们可以通过编写重载签名，指定构造函数的不同调用方式。具体方法为，为同一个构造函数写入多个同名但签名不同的构造函数头，构造函数实现紧随其后。

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

#### Public（公有）

`public`修饰的类成员（字段、方法、构造函数）在程序的任何可访问该类的地方都是可见的。

#### Private（私有）

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

#### Protected（受保护）

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

ArkTS是静态类型语言，如上述示例所示，对象字面量只能在可以推导出该字面量类型的上下文中使用。其他正确的例子：

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

#### `Record`类型的对象字面量

泛型`Record<K, V>`用于将类型（键类型）的属性映射到另一个类型（值类型）。常用对象字面量来初始化该类型的值：

```typescript
let map: Record<string, number> = {
  'John': 25,
  'Mary': 21,
}

map['John']; // 25
```

类型`K`可以是字符串类型或数值类型，而`V`可以是任何类型。

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

## 接口

接口声明引入新类型。接口是定义代码协定的常见方式。

任何一个类的实例只要实现了特定接口，就可以通过该接口实现多态。

接口通常包含属性和方法的声明

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
    console.log('someMethod called');
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

接口可以继承其他接口，如下面的示例所示：

```typescript
interface Style {
  color: string;
}

interface ExtendedStyle extends Style {
  width: number;
}
```

继承接口包含被继承接口的所有属性和方法，还可以添加自己的属性和方法。

## 泛型类型和函数

泛型类型和函数允许创建的代码在各种类型上运行，而不仅支持单一类型。

### 泛型类和接口

类和接口可以定义为泛型，将参数添加到类型定义中，如以下示例中的类型参数`Element`：

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
last<string>(['aa', 'bb']);
last<number>([1, 2, 3]);

// 隐式设置的类型实参
// 编译器根据调用参数的类型来确定类型实参
last([1, 2, 3]);
```

### 泛型默认值

泛型类型的类型参数可以设置默认值。这样可以不指定实际的类型实参，而只使用泛型类型名称。下面的示例展示了类和函数的这一点。

```typescript
class SomeType {}
interface Interface <T1 = SomeType> { }
class Base <T2 = SomeType> { }
class Derived1 extends Base implements Interface { }
// Derived1在语义上等价于Derived2
class Derived2 extends Base<SomeType> implements Interface<SomeType> { }

function foo<T = number>(): T {
  // ...
}
foo();
// 此函数在语义上等价于下面的调用
foo<number>();
```

## 空安全

默认情况下，ArkTS中的所有类型都是不可为空的，因此类型的值不能为空。这类似于TypeScript的严格空值检查模式（`strictNullChecks`），但规则更严格。

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

应用于可空类型的值时，它的编译时类型变为非空类型。例如，类型将从`T | null`更改为`T`：

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

在以下示例中，`getNick`方法如果设置了昵称，则返回昵称；否则，返回空字符串：

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

在访问对象属性时，如果该属性是`undefined`或者`null`，可选链运算符会返回`undefined`。

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

**说明**：`getSpouseNick`的返回类型必须为`string | null | undefined`，因为该方法可能返回`null`或者`undefined`。

可选链可以任意长，可以包含任意数量的`?.`运算符。

在以下示例中，如果一个`Person`的实例有不为空的`spouse`属性，且`spouse`有不为空的`nick`属性，则输出`spouse.nick`。否则，输出`undefined`：

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

每个模块都有其自己的作用域，即，在模块中创建的任何声明（变量、函数、类等）在该模块之外都不可见，除非它们被显式导出。

与此相对，从另一个模块导出的变量、函数、类、接口等必须首先导入到模块中。

### 导出

可以使用关键字`export`导出顶层的声明。

未导出的声明名称被视为私有名称，只能在声明该名称的模块中使用。

**注意**：通过export方式导出，在导入时要加{}。

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

### 导入

#### 静态导入

导入声明用于导入从其他模块导出的实体，并在当前模块中提供其绑定。导入声明由两部分组成：

* 导入路径，用于指定导入的模块；
* 导入绑定，用于定义导入的模块中的可用实体集和使用形式（限定或不限定使用）。

导入绑定可以有几种形式。

假设模块具有路径“./utils”和导出实体“X”和“Y”。

导入绑定`* as A`表示绑定名称“A”，通过`A.name`可访问从导入路径指定的模块导出的所有实体：

```typescript
import * as Utils from './utils'
Utils.X // 表示来自Utils的X
Utils.Y // 表示来自Utils的Y
```

导入绑定`{ ident1, ..., identN }`表示将导出的实体与指定名称绑定，该名称可以用作简单名称：

```typescript
import { X, Y } from './utils'
X // 表示来自utils的X
Y // 表示来自utils的Y
```

如果标识符列表定义了`ident as alias`，则实体`ident`将绑定在名称`alias`下：

```typescript
import { X as Z, Y } from './utils'
Z // 表示来自Utils的X
Y // 表示来自Utils的Y
X // 编译时错误：'X'不可见
```

#### 动态导入
应用开发的有些场景中，如果希望根据条件导入模块或者按需导入模块，可以使用动态导入代替静态导入。
import()语法通常称为动态导入dynamic import，是一种类似函数的表达式，用来动态导入模块。以这种方式调用，将返回一个promise。
如下例所示，import(modulePath)可以加载模块并返回一个promise，该promise resolve为一个包含其所有导出的模块对象。该表达式可以在代码中的任意位置调用。

```typescript
let modulePath = prompt("Which module to load?");
import(modulePath)
.then(obj => <module object>)
.catch(err => <loading error, e.g. if no such module>)
```

如果在异步函数中，可以使用let module = await import(modulePath)。

```typescript
// say.ts
export function hi() {
  console.log('Hello');
}
export function bye() {
  console.log('Bye');
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

更多的使用动态import的业务场景和使用实例见[动态import](arkts-dynamic-import.md)。

<!--RP1--><!--RP1End-->

### 顶层语句

顶层语句是指在模块的最外层直接编写的语句，这些语句不被包裹在任何函数、类、块级作用域中。顶层语句包括变量声明、函数声明、表达式等。

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

## ArkUI支持

本节演示ArkTS为创建图形用户界面（GUI）程序提供的机制。ArkUI基于TypeScript提供了一系列扩展能力，以声明式地描述应用程序的GUI以及GUI组件间的交互。


### ArkUI示例

[MVVM应用示例](arkts-mvvm.md#mvvm应用示例)提供了一个完整的基于ArkUI的应用程序，以展示其GUI编程功能。

有关ArkUI功能的更多详细信息，请参见ArkUI[基本语法概述](arkts-basic-syntax-overview.md)。
