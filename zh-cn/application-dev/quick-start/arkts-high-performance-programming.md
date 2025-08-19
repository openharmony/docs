# ArkTS高性能编程实践

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @zhanyi819-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @zhang_yixin13-->

## 概述

本文提供应用性能敏感场景下的高性能编程建议，帮助开发者编写高性能应用。高性能编程实践是在开发过程中总结的一些高性能写法和建议。在实现业务功能时，应同步思考并理解高性能写法的原理，并将其应用于代码逻辑中。关于ArkTS编程规范，请参考[ArkTS编程规范](./arkts-coding-style-guide.md)。

## 声明与表达式

### 使用`const`声明不变的变量

不变的变量推荐使用`const`声明。

``` TypeScript
const index = 10000; // 该变量在后续过程中未发生改变，建议声明成常量
```


### `number`类型变量避免整型和浮点型混用

针对`number`类型，运行时在优化时会区分整型和浮点型数据。建议避免在初始化后改变数据类型。

``` TypeScript
let intNum = 1;
intNum = 1.1;  // 该变量在声明时为整型数据，建议后续不要赋值浮点型数据

let doubleNum = 1.1;
doubleNum = 1;  // 该变量在声明时为浮点型数据，建议后续不要赋值整型数据
```


### 数值计算避免溢出

常见的可能导致溢出的数值计算包括如下场景，溢出之后，会导致引擎走入慢速的溢出逻辑分支处理，影响后续的性能。

- 针对加法、减法、乘法、指数运算等运算操作，应避免数值大于INT32_MAX（2147483647）或小于INT32_MIN（-2147483648）。

- 针对&（and）、>>>（无符号右移）等运算操作，应避免数值大于INT32_MAX。


### 循环中常量提取，减少属性访问次数

如果常量在循环中不会改变，可以将其提取到循环外部，减少访问次数。

``` TypeScript
class Time {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNum(num: number): number {
  let total: number = 348;
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    // 此处会多次对Time的info及start进行查找，并且每次查找出来的值是相同的
    total += ((Time.info[num - Time.start] & index) !== 0) ? 1 : 0;
  }
  return total;
}
```

优化后的代码如下，可以将`Time.info[num - Time.start]`提取为常量，这样可以显著减少属性访问次数，提升性能。

``` TypeScript
class Time {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNum(num: number): number {
  let total: number = 348;
  const info = Time.info[num - Time.start];  // 从循环中提取不变量
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    if ((info & index) != 0) {
      total++;
    }
  }
  return total;
}
```


## 函数

### 建议使用参数传递函数外的变量

使用闭包会造成额外的开销。在性能敏感场景中，建议使用参数传递函数外的变量替代。

``` TypeScript
let arr = [0, 1, 2];

function foo(): number {
  return arr[0] + arr[1];
}

foo();
```

建议使用参数传递函数外部的变量，以替代使用闭包。
``` TypeScript
let arr = [0, 1, 2];

function foo(array: number[]): number {
  return array[0] + array[1];
}

foo(arr);
```


### 避免使用可选参数

函数的可选参数表示参数可能为`undefined`，在函数内部使用该参数时，需要进行非空值的判断，造成额外的开销。

``` TypeScript
function add(left?: number, right?: number): number | undefined {
  if (left != undefined && right != undefined) {
    return left + right;
  }
  return undefined;
}
```

根据业务需求，将函数参数声明为必选参数。考虑使用默认参数。
``` TypeScript
function add(left: number = 0, right: number = 0): number {
  return left + right;
}
```


## 数组

### 数值数组推荐使用TypedArray

涉及纯数值计算时，推荐使用TypedArray数据结构。

优化前的代码示例：
``` TypeScript
const arr1 = new Array<number>(1, 2, 3);
const arr2 = new Array<number>(4, 5, 6);
let res = new Array<number>(3);
for (let i = 0; i < 3; i++) {
  res[i] = arr1[i] + arr2[i];
}
```

优化后的代码示例：
``` TypeScript
const typedArray1 = Int8Array.from([1, 2, 3]);
const typedArray2 = Int8Array.from([4, 5, 6]);
let res = new Int8Array(3);
for (let i = 0; i < 3; i++) {
  res[i] = typedArray1[i] + typedArray2[i];
}
```


### 避免使用稀疏数组

运行时在分配超过1024大小的数组或稀疏数组时，会采用hash表来存储元素。在该模式下，访问数组元素速度较慢。代码开发时应避免数组变成稀疏数组。

``` TypeScript
// 直接分配100000大小的数组，运行时会处理成用hash表来存储元素
let count = 100000;
let result: number[] = new Array(count);

// 创建数组后，直接在9999处赋值，会变成稀疏数组
let result: number[] = new Array();
result[9999] = 0;
```


### 避免使用联合类型数组

避免使用联合类型数组。避免在数值数组中混合使用整型数据和浮点型数据。

``` TypeScript
let arrNum: number[] = [1, 1.1, 2];  // 数值数组中混合使用整型数据和浮点型数据

let arrUnion: (number | string)[] = [1, 'hello'];  // 联合类型数组
```

根据业务需求，将相同类型的数据放在同一数组中。  
``` TypeScript
let arrInt: number[] = [1, 2, 3];
let arrDouble: number[] = [0.1, 0.2, 0.3];
let arrString: string[] = ['hello', 'world'];
```


## 异常

### 避免频繁抛出异常

创建异常时会构造异常的栈帧，造成性能损耗。在性能敏感场景下，如`for`循环语句中，应避免频繁抛出异常。

优化前的代码示例：

``` TypeScript
function div(a: number, b: number): number {
  if (a <= 0 || b <= 0) {
    throw new Error('Invalid numbers.')
  }
  return a / b
}

function sum(num: number): number {
  let sum = 0
  try {
    for (let t = 1; t < 100; t++) {
      sum += div(t, num)
    }
  } catch (e) {
    console.log(e.message)
  }
  return sum
}
```

优化后的代码示例：

``` TypeScript
function div(a: number, b: number): number {
  if (a <= 0 || b <= 0) {
    return NaN
  }
  return a / b
}

function sum(num: number): number {
  let sum = 0
  for (let t = 1; t < 100; t++) {
    if (t <= 0 || num <= 0) {
      console.log('Invalid numbers.')
    }
    sum += div(t, num)
  }
  return sum
}
```
