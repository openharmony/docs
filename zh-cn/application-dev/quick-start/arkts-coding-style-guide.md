# ArkTS编程规范

## 目标和适用范围

本文参考业界标准及实践，结合ArkTS语言特点，为提高代码的规范、安全、性能提供编码指南。

本文适用于使用ArkTS编写代码的开发场景。

## 规则来源

ArkTS在保持TypeScript基本语法风格的基础上，进一步强化静态检查和分析。本文部分规则筛选自《[OpenHarmony应用TS&JS编程指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-Application-Typescript-JavaScript-coding-guide.md)》，为ArkTS语言新增的语法添加了规则，旨在提高代码可读性、执行性能。

## 章节概览

### 代码风格

包含命名和格式。

### 编程实践

包含声明与初始化、数据类型、运算与表达式、异常等。

参考了《OpenHarmony应用TS&JS编程指南》中的规则，对其中ArkTS语言不涉及的部分作了去除，为ArkTS语言新增的语法添加了规则。

## 术语和定义

|  术语   | 缩略语  | 中文解释 |
|  ----  | ----  |  ----|
| ArkTS  | 无 | ArkTS编程语言 |
| TypeScript  | TS | TypeScript编程语言 |
| JavaScript  | JS | JavaScript编程语言 |
| ESObject  | 无 | 在ArkTS跨语言调用的场景中，用以标注JS/TS对象的类型 |

## 总体原则

规则分为两个级别：要求和建议。

**要求**：表示原则上应该遵从。本文所有内容目前均为针对ArkTS的要求。

**建议**：表示该条款属于最佳实践，可结合实际情况考虑是否纳入。

## 命名

### 为标识符取一个好名字，提高代码可读性

**【描述】**

好的标识符命名应遵循以下原则：
 - 能清晰的表达意图，避免使用单个字母、未成惯例的缩写来命名
 - 使用正确的英文单词并符合英文语法，不要使用中文拼音
 - 能区分出意思，避免造成误导

### 类名、枚举名、命名空间名采用UpperCamelCase风格

**【级别】建议**

**【描述】**

类采用首字母大写的驼峰命名法。
类名通常是名词或名词短语，例如Person、Student、Worker。不应使用动词，也应该避免类似Data、Info这样的模糊词。

**【正例】**
```
// 类名
class User {
  username: string

  constructor(username: string) {
    this.username = username;
  }

  sayHi() {
    console.log('hi' + this.username);
  }
}

// 枚举名
enum UserType {
  TEACHER = 0,
  STUDENT = 1
};

// 命名空间
namespace Base64Utils {
  function encrypt() {
    // todo encrypt
  }

  function decrypt() {
    // todo decrypt
  }
};
```

### 变量名、方法名、参数名采用lowerCamelCase风格

**【级别】建议**

**【描述】**

函数的命名通常是动词或动词短语，采用小驼峰命名，示例如下：
1.   load + 属性名()
2.   put + 属性名()
3.   is + 布尔属性名()
4.   has + 名词/形容词()
5.   动词()
6.   动词 + 宾语()
变量名通常是名词或名词短语，采用小驼峰命名，便于理解。

**【正例】**
```
let msg = 'Hello world';

function sendMsg(msg: string) {
  // todo send message
}

let userName = 'Zhangsan';

function findUser(userName: string) {
  // todo find user by user name
}
```

### 常量名、枚举值名采用全部大写，单词间使用下划线隔开

**【级别】建议**

**【描述】**

常量命名，应该由全大写单词与下划线组成，单词间用下划线分割。常量命名要尽量表达完整的语义。

**【正例】**

```
const MAX_USER_SIZE = 10000;

enum UserType {
  TEACHER = 0,
  STUDENT = 1
};
```

### 避免使用否定的布尔变量名，布尔型的局部变量或方法需加上表达是非意义的前缀

**【级别】建议**

**【描述】**

布尔型的局部变量建议加上表达是非意义的前缀，比如is，也可以是has、can、should等。但是，当使用逻辑非运算符，并出现双重否定时，会出现理解问题，比如!isNotError，意味着什么，不是很好理解。因此，应避免定义否定的布尔变量名。

**【反例】**

```
let isNoError = true;
let isNotFound = false;

function empty() {}
function next() {}
```

**【正例】**

```
let isError = false;
let isFound = true;

function isEmpty() {}
function hasNext() {}
```

## 格式

### 使用空格缩进，禁止使用tab字符

**【级别】建议**

**【描述】**

只允许使用空格(space)进行缩进。

建议大部分场景优先使用2个空格，换行导致的缩进优先使用4个空格。
不允许插入制表符Tab。当前几乎所有的集成开发环境（IDE）和代码编辑器都支持配置将Tab键自动扩展为2个空格输入，应在代码编辑器中配置使用空格进行缩进。

**【正例】**

```
class DataSource {
  id: number = 0
  title: string = ''
  content: string = ''
}

const dataSource: DataSource[] = [
  {
    id: 1,
    title: 'Title 1',
    content: 'Content 1'
  },
  {
    id: 2,
    title: 'Title 2',
    content: 'Content 2'
  }

];

function test(dataSource: DataSource[]) {
  if (!dataSource.length) {
    return;
  }

  for (let data of dataSource) {
    if (!data || !data.id || !data.title || !data.content) {
      continue;
    }
    // some code
  }

  // some code
}
```

### 行宽不超过120个字符

**【级别】建议**

**【描述】**

代码行宽不宜过长，否则不利于阅读。

控制行宽可以间接的引导程序员去缩短函数、变量的命名，减少嵌套的层数，精炼注释，提升代码可读性。
建议每行字符数不超过120个，除非需要显著增加可读性（超过120个），且不会隐藏信息。
例外：如果一行注释包含了超过120个字符的命令或URL，则可以保持一行，以方便复制、粘贴和通过grep查找；预处理的error信息在一行便于阅读和理解，即使超过120个字符。

### 条件语句和循环语句的实现必须使用大括号

**【级别】建议**

**【描述】**

在`if`、`for`、`do`、`while`等语句的执行体加大括号`{}`是一种最佳实践，因为省略大括号容易导致错误，并且降低代码的清晰度。

**【反例】**

```
if (condition)
  console.log('success');

for (let idx = 0; idx < 5; ++idx)
  console.log(idx);
```

**【正例】**

```
if (condition) {
  console.log('success');
}

for (let idx = 0; idx < 5; ++idx) {
  console.log(idx);
}
```

### `switch`语句的`case`和`default`需缩进一层

**【级别】建议**

**【描述】**

`switch`的`case`和`default`要缩进一层（2个空格）。开关标签之后换行的语句，需再缩进一层（2个空格）。

**【正例】**

```
switch (condition) {
  case 0: {
    doSomething();
    break;
  }
  case 1: {
    doOtherthing();
    break;
  }
  default:
    break;
}
```

### 表达式换行需保持一致性，运算符放行末

**【级别】建议**

**【描述】**

当语句过长或可读性不佳时，需要在合适的地方进行换行。
换行时将操作符放在行末，表示“未结束，后续还有”，保持与常用的格式化工具的默认配置一致。

**【正例】**

```
// 假设条件语句超出行宽
if (userCount > MAX_USER_COUNT ||
  userCount < MIN_USER_COUNT) {
  doSomething();
}
```

### 多个变量定义和赋值语句不允许写在一行

**【级别】要求**

**【描述】**

每个语句的变量声明都应只声明一个变量。
这种方式更便于添加变量声明，无需考虑将分号改为逗号，以免引入错误。此外，每个语句只声明一个变量，使用调试器逐个调试也很方便，而不是一次跳过所有变量。

**【反例】**

```
let maxCount = 10, isCompleted = false;
let pointX, pointY;
pointX = 10; pointY = 0;
```

**【正例】**

```
let maxCount = 10;
let isCompleted = false;
let pointX = 0;
let pointY = 0;
```

### 空格应该突出关键字和重要信息，避免不必要的空格

**【级别】建议**

**【描述】**

空格应该突出关键字和重要信息。总体建议如下：
1.   `if`, `for`, `while`, `switch`等关键字与左括号`(`之间加空格。
2.   在函数定义和调用时，函数名称与参数列表的左括号`(`之间不加空格。
3.   关键字`else`或`catch`与其之前的大括号`}`之间加空格。
4.   任何打开大括号(`{`)之前加空格，有两个例外：
a)   在作为函数的第一个参数或数组中的第一个元素时，对象之前不用加空格，例如：`foo({ name: 'abc' })`。
b)   在模板中，不用加空格，例如：`abc${name}`。
5.   二元操作符(`+` `-` `*` `=` `<` `>` `<=` `>=` `===` `!==` `&&` `||`)前后加空格；三元操作符(`? :`)符号两侧均加空格。
6.   数组初始化中的逗号和函数中多个参数之间的逗号后加空格。
7.   在逗号(`,`)或分号(`;`)之前不加空格。
8.   数组的中括号(`[]`)内侧不要加空格。
9.   不要出现多个连续空格。在某行中，多个空格若不是用来作缩进的，通常是个错误。

**【反例】**

```
// if 和左括号 ( 之间没有加空格
if(isJedi) {
  fight();
}

// 函数名fight和左括号 ( 之间加了空格
function fight (): void {
  console.log('Swooosh!');
}
```

**【正例】**

```
// if 和左括号之间加一个空格
if (isJedi) {
  fight();
}

// 函数名fight和左括号 ( 之间不加空格
function fight(): void {
  console.log('Swooosh!');
}
```

**【反例】**

```
if (flag) {
  // ...
}else {  // else 与其前面的大括号 } 之间没有加空格
  // ...
}
```

**【正例】**

```
if (flag) {
  // ...
} else {  // else 与其前面的大括号 } 之间增加空格
  // ...
}
```

**【正例】**

```
function foo() {  // 函数声明时，左大括号 { 之前加个空格
  // ...
}

bar('attr', {  // 左大括号前加个空格
  age: '1 year',
  sbreed: 'Bernese Mountain Dog',
});
```

**【正例】**

```
const arr = [1, 2, 3];  // 数组初始化中的逗号后面加个空格，逗号前面不加空格
myFunc(bar, foo, baz);  // 函数的多个参数之间的逗号后加个空格，逗号前面不加空格
```

### 建议字符串使用单引号

**【级别】建议**

**【描述】**

通常情况下，建议使用单引号。

**【反例】**

```
let message = "world";
console.log(message);
```

**【正例】**

```
let message = 'world';
console.log(message);
```

### 对象字面量属性超过4个，需要都换行

**【级别】建议**

**【描述】**

对象字面量的属性应保持一致的格式：要么每个属性都换行，要么所有属性都在同一行。当对象字面量的属性超过4个时，建议统一换行。

**【反例】**

```
interface I {
  name: string
  age: number
  value: number
  sum: number
  foo: boolean
  bar: boolean
}

let obj: I = { name: 'tom', age: 16, value: 1, sum: 2, foo: true, bar: false }
```

**【正例】**

```
interface I {
  name: string
  age: number
  value: number
  sum: number
  foo: boolean
  bar: boolean
}

let obj: I = {
  name: 'tom',
  age: 16,
  value: 1,
  sum: 2,
  foo: true,
  bar: false
}
```

### 把`else`/`catch`放在`if`/`try`代码块关闭括号的同一行

**【级别】建议**

**【描述】**

编写条件语句时，建议将`else`放在`if`代码块关闭括号的同一行。同样，编写异常处理语句时，建议将`catch`放在`try`代码块关闭括号的同一行。

**【反例】**

```
if (isOk) {
  doThing1();
  doThing2();
}
else {
  doThing3();
}
```

**【正例】**

```
if (isOk) {
  doThing1();
  doThing2();
} else {
  doThing3();
}
```

**【反例】**

```
try {
  doSomething();
}
catch (err) {
  // 处理错误
}
```

**【正例】**

```
try {
  doSomething();
} catch (err) {
  // 处理错误
}
```

### 大括号`{`和语句在同一行

**【级别】建议**

**【描述】**

应保持一致的大括号风格。建议将大括号置于控制语句或声明语句的同一行。

**【反例】**

```
function foo()
{
  // ...
}
```

**【正例】**

```
function foo() {
  // ...
}
```
 
## 编程实践

### 建议添加类属性的可访问修饰符

**【级别】建议**

**【描述】**

ArkTS提供了`private`, `protected`和`public`可访问修饰符。默认情况下，属性的可访问修饰符为`public`。选取适当的可访问修饰符可以提升代码的安全性和可读性。注意：如果类中包含`private`属性，无法通过对象字面量初始化该类。

**【反例】**

```
class C {
  count: number = 0

  getCount(): number {
    return this.count
  }
}
```

**【正例】**

```
class C {
  private count: number = 0

  public getCount(): number {
    return this.count
  }
}
```

### 不建议省略浮点数小数点前后的0

**【级别】建议**

**【描述】**

ArkTS中，浮点值包含一个小数点，不要求小数点之前或之后必须有一个数字。在小数点前面和后面都添加数字可以提高代码的可读性。

**【反例】**

```
const num = .5;
const num = 2.;
const num = -.7;
```

**【正例】**

```
const num = 0.5;
const num = 2.0;
const num = -0.7;
```

### 判断变量是否为`Number.NaN`时必须使用`Number.isNaN()`方法

**【级别】要求**

**【描述】**

在ArkTS中，`Number.NaN`是`Number`类型的一个特殊值。它被用来表示非数值，这里的数值是指在IEEE浮点数算术标准中定义的双精度64位格式的值。
在ArkTS中，`Number.NaN`的独特之处在于它不等于任何值，包括其本身。与`Number.NaN`进行比较时，结果是令人困惑的：`Number.NaN !== Number.NaN` 和 `Number.NaN != Number.NaN` 的值都是 `true`。
因此，必须使用`Number.isNaN()`函数来测试一个值是否是`Number.NaN`。

**【反例】**

```
if (foo == Number.NaN) {
  // ...
}

if (foo != Number.NaN) {
  // ...
}
```

**【正例】**

```
if (Number.isNaN(foo)) {
  // ...
}

if (!Number.isNaN(foo)) {
  // ...
}
```

### 数组遍历优先使用`Array`对象方法

**【级别】要求**

**【描述】**

对于数组的遍历处理，应该优先使用Array对象方法，如：`forEach(), map(), every(), filter(), find(), findIndex(), reduce(), some()`。

**【反例】**

```
const numbers = [1, 2, 3, 4, 5];
// 依赖已有数组来创建新的数组时，通过for遍历，生成一个新数组
const increasedByOne: number[] = [];
for (let i = 0; i < numbers.length; i++) {
  increasedByOne.push(numbers[i] + 1);
}
```

**【正例】**

```
const numbers = [1, 2, 3, 4, 5];
// better: 使用map方法是更好的方式
const increasedByOne: number[] = numbers.map(num => num + 1);
```

### 不要在控制性条件表达式中执行赋值操作

**【级别】要求**

**【描述】**

控制性条件表达式用于`if`、`while`、`for`和`?:`等条件判断中。
在控制性条件表达式中执行赋值容易导致意外行为，且降低代码的可读性。

**【反例】**

```
// 在控制性判断中赋值不易理解
if (isFoo = false) {
  // ...
}
```

**【正例】**

```
const isFoo = someBoolean; // 在上面赋值，if条件判断中直接使用
if (isFoo) {
  // ...
}
```

### 在`finally`代码块中，不要使用`return`、`break`、`continue`或抛出异常，避免`finally`块非正常结束

**【级别】要求**

**【描述】**

在`finally`代码块中，直接使用`return`、`break`、`continue`、`throw`语句或调用方法时未处理异常，会导致`finally`代码块无法正常结束。`finally`代码块非正常结束会影响`try`或`catch`代码块中异常的抛出，也可能影响方法的返回值。因此，必须确保`finally`代码块正常结束。

**【反例】**

```
function foo() {
  try {
    // ...
    return 1;
  } catch (err) {
    // ...
    return 2;
  } finally {
    return 3;
 }
}
```

**【正例】**

```
function foo() {
  try {
    // ...
    return 1;
  } catch (err) {
    // ...
    return 2;
  } finally {
    console.log('XXX!');
  }
}
```

### 避免使用`ESObject`

**【级别】建议**

**【描述】**

`ESObject`主要用于ArkTS和TS/JS的跨语言调用场景中的类型标注。在非跨语言调用场景中使用`ESObject`标注类型，会引入不必要的跨语言调用，导致额外的性能开销。

**【反例】**

```
// lib.ets
export interface I {
  sum: number
}

export function getObject(value: number): I {
  let obj: I = { sum: value };
  return obj
}

// app.ets
import { getObject } from 'lib'
let obj: ESObject = getObject(123);
```

**【正例】**

```
// lib.ets
export interface I {
  sum: number
}

export function getObject(value: number): I {
  let obj: I = { sum: value };
  return obj
}

// app.ets
import { getObject, I } from 'lib'
let obj: I = getObject(123);
```

### 使用`T[]`表示数组类型

**【级别】建议**

**【描述】**

ArkTS提供了两种数组类型的表示方式：`T[]`和`Array<T>`。建议所有数组类型均使用`T[]`表示，以提高代码可读性。

**【反例】**

```
let x: Array<number> = [1, 2, 3];
let y: Array<string> = ['a', 'b', 'c'];
```

**【正例】**

```
// 统一使用T[]语法
let x: number[] = [1, 2, 3];
let y: string[] = ['a', 'b', 'c'];
```
