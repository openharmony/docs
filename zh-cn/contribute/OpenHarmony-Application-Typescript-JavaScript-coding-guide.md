# OpenHarmony应用TS&JS编程指南

# 概述

## 目标和适用范围

本指南适用于在OpenHarmony上使用TypeScript和JavaScript进行系统开发或应用开发编写代码的场景。

本文参考业界标准及实践，结合语言引擎技术特点以及OpenHarmony技术特点，为提高代码的规范、安全、性能提供编码建议。

## 规则来源

本指南筛选自OpenHarmony JS通用编程规范[1]，结合可发挥OpenHarmony技术特点并且不违反业界认知的规则，包括ESLint、TSC配置等。

ESLint相关规则中的正例反例代码来源于ESLint Rules[2]，标注“参见 @typescript-eslint”。

## 章节概览

### [OpenHarmony应用环境限制](#openharmony应用环境限制)

OpenHarmony应用因安全因素的使用限制，均为强制要求。

### 语言特性：[声明与初始化](#声明与初始化)、[数据类型](#数据类型)、[运算与表达式](#运算与表达式)、[函数](#函数)、[类与对象](#类与对象)、[异常](#异常)、[异步](#异步)、[类型](#类型)

## 约定

**规则** ：编程时必须遵守的约定

**建议** ：编程时必须加以考虑的约定

无论是“规则”还是“建议”，都必须理解该条目这么规定的原因，并努力遵守。

# OpenHarmony应用环境限制

## 使用严格模式

**【级别】规则**

**【描述】**

严格模式（ECMAScript 5开始引入ECMAScript标准中，通过'use strict'语法开启）是采用具有限制性JavaScript变体的一种方式，从而使代码隐式地脱离“马虎模式/稀松模式/懒散模式”（sloppy）。

1. 严格模式通过**抛出错误**来消除了一些原有**静默错误** ；
1. 严格模式修复了一些导致JavaScript引擎难以执行优化的缺陷——有时候，相同的代码，严格模式可以比非严格模式下**运行得更快** ；
1. 严格模式**禁用了**在ECMAScript的未来版本中可能会定义的一些语法。

**注：OpenHarmony上方舟编译运行时目前只支持严格模式的TS/JS代码**

## 禁止使用eval()

**【级别】规则**

**【描述】**

使用eval()会让程序比较混乱，导致可读性较差。

**【反例】**

```javascript
console.log(eval({ a:2 })); // 输出[object Object] 
console.log(eval('"a" + 2')); // 输出'a2' 
console.log(eval('{ a: 2 }')); // 输出2 
console.log(eval('let value = 1 + 1;')); // 输出undefined
```

## 禁止使用with() {}

**【级别】规则**

**【描述】**

使用with让代码在语义上变得不清晰，因为with的对象，可能会与局部变量产生冲突，从而改变程序原本的用义。

**【反例】**

```javascript
const foo = { x: 5 };
with (foo) {
  let x = 3;
  console.log(x);  // x = 3
}
console.log(foo.x);  // x = 3
```

## 不要动态创建函数

**【级别】规则**

**【描述】**

定义函数的方法包括3种：函数声明、Function构造函数和函数表达式。不管用哪种方法定义函数，它们都是Function对象的实例，并将继承Function对象所有默认或自定义的方法和属性。以函数构造器创建函数的方式类似于函数eval()，可以接受任何字符串形式作为它的函数体，这就会有安全漏洞的风险。

**【反例】**

```javascript
let add = new Function('a','b','return a + b');
// Function构造函数也可以只有一个参数，该参数可以为任意的字符串:
let dd = new Function('alert("hello")');
```

**【正例】**

```javascript
// 函数声明
function add(a,b){
  return a+b;
}
// 函数表达式
let add = function(a,b){
  return a+b;
}
```

# 声明与初始化

## 声明变量时要求使用const或let而不是var

**【级别】规则**

**【描述】**

在ECMAScript 6允许开发者使用let和const关键字在块级作用域而非函数作用域下声明变量。块级作用域在很多其他编程语言中很普遍，能帮助开发者避免错误。只读变量用const定义，其它变量用let定义。

**【反例】**

```javascript
var number = 1;
var count = 1;
if (isOK) {
  count += 1;
}
```

**【正例】**

```javascript
const number = 1;
let count = 1;
if (isOK) {
  count += 1;
}
```

# 数据类型

## 不要省略浮点数小数点前后的0

**【级别】规则**

**【描述】**

在JavaScript中，浮点值会包含一个小数点，没有要求小数点之前或之后必须有一个数字。虽然不是一个语法错误，但这种格式的数字使真正的小数和点操作符变的难以区分。由于这个原因，必须在小数点前面和后面有一个数字，以明确表明是要创建一个小数。

**【反例】**

```javascript
const num = .5;
const num = 2.;
const num = -.7;
```

**【正例】**

```javascript
const num = 0.5;
const num = 2.0;
const num = -0.7;
```

## 判断变量是否为NaN时必须使用isNaN()方法

**【级别】规则**

**【描述】**

在JavaScript中，NaN是Number类型的一个特殊值。它被用来表示非数值，这里的数值是指在IEEE浮点数算术标准中定义的双精度64位格式的值。
因为在JavaScript中NaN独特之处在于它不等于任何值，包括它本身，与NaN进行比较的结果是令人困惑：NaN !== NaN or NaN != NaN的值都是true。
因此，必须使用Number.isNaN()或全局的isNaN()函数来测试一个值是否是NaN。

**【反例】**

```javascript
if (foo == NaN) {
  // ...
}
if (foo != NaN) {
  // ...
}
```

**【正例】**

```javascript
if (isNaN(foo)) {
  // ...
}
if (!isNaN(foo)) {
  // ...
}
```

## 浮点型数据判断相等不要直接使用==或===

**【级别】规则**

**【描述】**

由于浮点数在计算机表示中存在精度的问题，数学上相等的数字，经过运算后，其浮点数表示可能不再相等，因而不能使用相等运算符==或===判断浮点数是否相等。

**【反例】**

```javascript
0.1 + 0.2 == 0.3; // false
0.1 + 0.2 === 0.3; // false
```

**【正例】**

```javascript
const EPSILON = 1e-6;
const num1 = 0.1;
const num2 = 0.2;
const sum = 0.3;
if(Math.abs(num1 + num2 - sum) < EPSILON) {
  ...
}
```

## 不要在数组上定义或使用非数字属性（length除外）

**【级别】规则**

**【描述】**

在JavaScript中，数组也是对象，可以往数组上添加属性，但为了处理方便和避免出错，数组只应该用来存储有序（即索引连续）的一组数据。必须要添加属性时，考虑用Map或者Object替代。

**【反例】**

```javascript
const myHash = [];
myHash['key1'] = 'val1';
myHash['key2'] = 'val2';
myHash[0] = '222';
for (const key in myHash) {
  // key的值为 0 key1 key2
  console.log(key);
}
console.log(myHash.length); // 数组长度为1
```

**【正例】**

非数字属性时使用Map、Object

```javascript
const map = new Map();
map.set('key1', 'val1');
map.set('key2', 'val2');
for(const [key, value] of map) {
  console.log('属性：' + key + ', 值：' + value);
}
```

## 数组遍历优先使用Array对象方法

**【级别】规则**

**【描述】**

对于数组的遍历处理，应该优先使用Array对象方法，如：forEach()、map()、every()、filter()、find()、findIndex()、reduce()、some()。
注意：不能使用for-in遍历数组。

**【反例】**

```javascript
const numbers = [1, 2, 3, 4, 5];
let sum = 0;
// 使用for in遍历数组
for (const num in numbers) {
  console.log(num);
  sum += num;
}
// 依赖已有数组来创建新的数组时，通过for遍历，生成一个新数组
const increasedByOne = [];
for (let i = 0; i < numbers.length; i++) {
  increasedByOne.push(numbers[i] + 1);
}
```

**【正例】**

```javascript
const numbers = [1, 2, 3, 4, 5];
// 使用for of遍历求和
let sum = 0;
for (const num of numbers) {
  sum += num;
}
// 使用forEach遍历求和
let sum = 0;
numbers.forEach(num => sum += num);
// better: 使用reduce方法实现求和，是更好的方式
const sum = numbers.reduce((total, num) => total + num, 0);
// 依赖已有数组来创建新的数组，可使用forEach遍历，生成一个新数组
const increasedByOne = [];
numbers.forEach(num => increasedByOne.push(num + 1));
// better: 使用map方法是更好的方式
const increasedByOne = numbers.map(num => num + 1);
```

# 运算与表达式

## 判断相等时应使用===和!== ，而不是==和!=

**【级别】规则**

**【描述】**

JavaScript中使用双等==做相等判断时会自动做类型转换，如：[] == false、[] == ![]、3 == '03'都是true，当类型确定时使用全等===做比较可以提高效率。

**【反例】**

```javascript
age == bee
foo == true
bananas != 1
value == undefined
typeof foo == 'undefined'
'hello' != 'world'
0 == 0
true == true
```

**【正例】**

```javascript
age === bee
foo === true
bananas !== 1
value === undefined
typeof foo === 'undefined'
'hello' !== 'world'
0 === 0
true === true
```

**【例外】**

```javascript
//当判断对象是否是null的时候，可直接使用如下形式：
obj == null
obj != null
```

## 不要在控制性条件表达式中执行赋值操作

**【级别】规则**

**【描述】**

控制性条件表达式常用于if、while、for、?:等条件判断中。
在控制性条件表达式中执行赋值，常常导致意料之外的行为，且代码的可读性非常差。

**【反例】**

```javascript
// 在控制性判断中赋值不易理解  
if (isFoo = false) {
  ...
}
```

**【正例】**

```javascript
const isFoo = someBoolean; // 在上面赋值，if条件判断中直接使用
if (isFoo) {
  ...
}
```

# 函数

## 必须使用一致的return语句

**【级别】规则**

**【描述】**

不像静态类型语言强制要求函数返回一个指定类型的值，JavaScript允许在一个函数中不同的代码路径返回不同类型的值。

而JavaScript在以下情况下函数会返回undefined：

1. 在退出之前没有执行return语句
1. 执行return语句，但没有显式地指定一个值
1. 执行return undefined
1. 执行return void，其后跟着一个表达式 (例如，一个函数调用)
1. 执行return，其后跟着其它等于undefined的表达式

在一个函数中，如果任何代码路径显式的返回一个值，但一些代码路径不显式返回一个值，那么这种情况可能是个书写错误，尤其是在一个较大的函数里。因此，函数内，应使用一致的return语句。

**【反例】**

```javascript
function doSomething(condition) {
  if (condition) {
    ...
    return true;
  } else {
    ...
    return;
  }
}
function doSomething(condition) {
  if (condition) {
    ...
    return true;
  }
}
```

**【正例】**

```javascript
// 保证所有路径都以相同的方式返回值
function doSomething(condition) {
  if (condition) {
    ...
    return true;
  } else {
    ...
    return false;
  }
}

function doSomething(condition) {
  if (condition) {
    ...
    return true;
  }
  ...
  return false;
}
```

## 不要使用arguments，可以选择rest语法替代

**【级别】规则**

**【描述】**

rest参数是一个真正的数组，也就是说能够在它上面直接使用所有的数组方法，比如sort，map，forEach或pop，而arguments是一个类数组。因此，应选择使用rest语法替代arguments。另外，rest参数必须是列表中的最后一个参数。

**【反例】**

```javascript
function concatenateAll() {
  // 因为arguments是类数组，不能直接使用join方法，需要先转换为真正的数组
  const args = Array.prototype.slice.call(arguments);   
  return args.join('');
}
```

**【正例】**

```javascript
function concatenateAll(...args) {
  return args.join('');
}
```

## 不要将This赋值给一个变量，约束This在一个Scope内使用

**【级别】规则**

**【描述】**

箭头函数提供了更简洁的语法，并且箭头函数中的this对象指向是不变的，this绑定到定义时所在的对象，有更好的代码可读性。而保存this引用的方式，容易让开发人员搞混。

**【反例】**

```javascript
function foo() {
  const self = this;
  return function() {
    console.log(self);
  };
}
```

**【正例】**

```javascript
function foo() {
  return () => {
    console.log(this);
  };
}
```

参见：[@typescript-eslint/no-this-alias](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-this-alias.md)

ESLint的描述更加严苛，我们认为this不应该在任何情况下赋值给一个变量。

# 类与对象

## 使用点号来访问对象的属性，只有计算属性使用[]

**【级别】规则**

**【描述】**

在JavaScript中，可以使用点号 (foo.bar) 或者方括号 (foo['bar'])来访问属性。然而，点号通常是首选，因为它更加易读，简洁，也更适于JavaScript压缩。

**【正例】**

```javascript
const name = obj.name;
const key = getKeyFromDB();
const prop = obj[key]; // 属性名是变量时才使用[]
```

## 不要修改内置对象的原型，或向原型添加方法

**【级别】规则**

**【描述】**

内置对象作为一套公共接口，具有约定俗成的行为方式，若修改其原型，可能破坏接口语义。因此，永远不要修改内置对象的原型，或向原型添加方法。

**【反例】**

```javascript
Array.prototype.indexOf = function () {
  return -1;
}
// 其它地方使用的时候
const arr = [1, 1, 1, 1, 1, 2, 1, 1, 1];
console.log(arr.indexOf(2)); // 输出-1
```

## 不要删除对象的可计算属性

**【级别】规则**

**【描述】**

delete会改变对象的布局，而delete对象的可计算属性会非常危险，而且会大幅约束语言运行时的优化从而影响执行性能。

注意：建议不删除对象的任何属性，如果有需要，建议用map和set。

**【反例】**

```javascript
// Can be replaced with the constant equivalents, such as container.aaa
delete container['aaa'];

// Dynamic, difficult-to-reason-about lookups
const name = 'name';
delete container[name];
delete container[name.toUpperCase()];
```

**【正例】**

```javascript
// 一定程度也会影响优化性能，但比删除可计算属性好一些。
delete container.aaa;

delete container[7];
```

参见：[@typescript-eslint/no-dynamic-delete](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-dynamic-delete.md)

# 异常

## 不要使用return、break、continue或抛出异常使finally块非正常结束

**【级别】规则**

**【描述】**

在finally代码块中，直接使用return、break、continue、throw语句，或由于调用方法的异常未处理，会导致finally代码块无法正常结束。非正常结束的finally代码块会影响try或catch代码块中异常的抛出，也可能会影响方法的返回值。所以要保证finally代码块正常结束。

**【反例】**

```javascript
function foo() {
  try {
    ...
    return 1;
  } catch(err) {
    ...
    return 2;
  } finally {
    return 3;
 }
}
```

**【正例】**

```javascript
function foo() {
  try {
    ...
    return 1;
  } catch(err) {
    ...
    return 2;
  } finally {
    console.log('XXX!');
  }
}
```

# 异步

## 禁用不必要的return await

**【级别】规则**

**【描述】**

因为async function的返回值总是封装在Promise.resolve，return await实际上并没有做任何事情，只是在Promise resolve或reject之前增加了额外的时间。唯一有效的情况是，在try/catch语句中使用return await来捕获另一个基于Promise的函数的错误。

**【反例】**

```javascript
async function foo() {
  return await bar();
}
```

**【正例】**

```javascript
async function foo() {
  return bar();
}
async function foo() {
  await bar();
  return;
}
async function foo() {
  const baz = await bar();
  return baz;
}
async function foo() {
  try {
    return await bar();
  } catch (error) {
    // here can be executed, go on
  }
}
```

## 不允许等待非Thenable的值

**【级别】规则**

**【描述】**

如果await一个非Thenable的值，await会把该值转换为已正常处理的Promise，然后等待其处理结果。此时await反而会影响代码性能。

**【反例】**

```javascript
async function f3() {
  const y = await 20;
  console.log(y); // 20
}

f3();
console.log(30);

// output
// 30
// 20
```

**【正例】**

```javascript
async function f3() {
  const y = 20;
  console.log(y); // 20
}

f3();
console.log(30);

// output
// 20
// 30
```

参见：[@typescript-eslint/await-thenable](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/await-thenable.md)

# 类型

## 强制将Null和Undefined作为独立类型标注

**【级别】规则**

**【描述】**

Null和Undefined作为独立类型标注，可以提高代码的安全性，避免空指针异常。

**【反例】**

```javascript
let userName: string;
userName = 'hello';
userName = undefined;
```

**【正例】**

```javascript
let userName: string | undefined;
userName = 'hello';
userName = undefined;
```

## 必须显式声明函数及类方法的返回值类型

**【级别】规则**

**【描述】**

显式声明返回类型，这可确保返回值被分配给正确类型的变量；或者在没有返回值的情况下，调用代码不会尝试把undefined分配给变量。

**【反例】**

```javascript
// 没有返回值时，没有声明返回值类型为void
function test() {
  return;
}
// 没有声明返回值类型为number
function fn() {
  return 1;
};
// 没有声明返回值类型为string
let arrowFn = () => 'test';
class Test {
  // 没有返回值时，没有声明返回值类型为void
  method() {
    return;
  }
}
```

**【正例】**

```javascript
// 函数没有返回值时，显式声明返回值类型为void
function test(): void {
  return;
}
// 显式声明返回值类型为number
function fn(): number {
  return 1;
};
// 显式声明返回值类型为 string
let arrowFn = (): string => 'test';
class Test {
  // 没有返回值时，显式声明返回值类型为void
  method(): void {
    return;
  }
}
```

参见：[@typescript-eslint/explicit-function-return-type](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/explicit-function-return-type.md)

## 强制使用类型导出的一致性

**【级别】规则**

**【描述】**

如果导出类型（type），将导出类型和导出其他对象分开写。

**【反例】**

```javascript
interface ButtonProps {
  onClick: () => void;
}
class Button implements ButtonProps {
  onClick() {
    console.log('button!');
  }
}
export { Button, ButtonProps };
```

**【正例】**

```javascript
interface ButtonProps {
  onClick: () => void;
}
class Button implements ButtonProps {
  onClick() {
    console.log('button!');
  }
}
export { Button };
export type { ButtonProps };
```

参见：[@typescript-eslint/consistent-type-exports](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/consistent-type-exports.md)

## 强制使用类型导入的一致性

**【级别】规则**

**【描述】**

如果导入类型（type），将导入类型和导入其他对象分开写。

**【反例】**

```javascript
import { Foo } from 'Foo';
import Bar from 'Bar';
type T = Foo;
const x: Bar = 1;
```

**【正例】**

```javascript
import type { Foo } from 'Foo';
import type Bar from 'Bar';
type T = Foo;
const x: Bar = 1;
```

参见：[@typescript-eslint/consistent-type-imports](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/consistent-type-imports.md)

## 避免使用any

**【级别】规则**

**【描述】**

使用了`any`类型会使所有编译时的类型检查被忽略。一般来说，这个行为不是必需的，也不符合期望。如果类型未知，要求使用`unknown` 。
当引入的三方件不是使用TS语言或者没有提供TS类型声明时，可以使用`any`来声明相关的三方件对象。

## 不允许定义any类型

**【级别】规则**

**【描述】**

不允许定义any类型。它的目的是为了让类型在TS中尽量明确，帮助语言运行时优化。

**【反例】**

```javascript
const age: any = 'seventeen';
function greet(): any {}
function greet(param: Array<any>): string {}
```

**【正例】**

```javascript
const age: number = 17;
function greet(): string {}
function greet(param: Array<string>): string {}
```

参见：[@typescript-eslint/no-explicit-any](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-explicit-any.md)

## 不允许使用any作为参数传递

**【级别】规则**

**【反例】**

```javascript
declare function foo(arg1: string, arg2: number, arg3: string): void;

const anyTyped = 1 as any;

foo(...anyTyped);
foo(anyTyped, 1, 'a');

const tuple1 = ['a', anyTyped, 'b'] as const;
foo(...tuple1);
```

**【正例】**

```javascript
declare function foo(arg1: string, arg2: number, arg3: string): void;

foo('a', 1, 'b');

const tuple1 = ['a', 1, 'b'] as const;
foo(...tuple1);
```

参见：[@typescript-eslint/no-unsafe-argument](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-argument.md)

## 不允许在赋值中使用any

**【级别】规则**

**【反例】**

```javascript
const x = 1 as any,

const x: Set<string> = new Set<any>();
```

**【正例】**

```javascript
const x = 1;

const x: Set<string> = new Set<string>();
```

参见：[@typescript-eslint/no-unsafe-assignment](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-assignment.md)

## 不允许call类型为any的变量

**【级别】规则**

**【反例】**

```javascript
declare const anyVar: any;
declare const nestedAny: { prop: any };

anyVar();
anyVar.a.b();

nestedAny.prop();
nestedAny.prop['a']();
```

**【正例】**

```javascript
declare const typedVar: () => void;
declare const typedNested: { prop: { a: () => void } };

typedVar();
typedNested.prop.a();
```

参见：[@typescript-eslint/no-unsafe-call](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-call.md)

## 不允许访问类型为any的对象的成员

**【级别】规则**

**【反例】**

```markup
declare const anyVar: any;
declare const nestedAny: { prop: any };

anyVar.a;
anyVar.a.b;

nestedAny.prop.a;
nestedAny.prop['a'];
```

**【正例】**

```javascript
declare const properlyTyped: { prop: { a: string } };

properlyTyped.prop.a;
properlyTyped.prop['a'];
```

参见：[@typescript-eslint/no-unsafe-member-access](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-member-access.md)

## 不允许声明函数返回值类型为any或者any[]

**【级别】规则**

**【反例】**

```javascript
function foo1() {
  return 1 as any;
}
```

**【正例】**

```javascript
function foo1() : number {
  return 1;
}
```

参见：[@typescript-eslint/no-unsafe-return](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-return.md)

# 参考

1. 《OpenHarmony JS通用编程规范》：[https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-JavaScript-coding-style-guide.md](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-JavaScript-coding-style-guide.md)
1. ESLint Rules：[https://github.com/typescript-eslint/typescript-eslint/tree/main/packages/eslint-plugin/docs/rules](https://github.com/typescript-eslint/typescript-eslint/tree/main/packages/eslint-plugin/docs/rules)
1. 《高性能JavaScript》
