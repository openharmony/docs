# ArkTS Performant Programming Practices

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @zhanyi819-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @zhang_yixin13-->

## Overview

This topic provides a set of performant programming practices that you can apply in performance-critical scenarios. They are techniques and recommendations drawn from real-world development. Following these practices in your service implementation can help develop performant applications. For details about ArkTS programming specifications, see [ArkTS Coding Style Guide](./arkts-coding-style-guide.md).

## Declarations and Expressions

### Using const to Declare Unchanged Variables

You are advised to use **const** to declare variables that remain unchanged.

``` TypeScript
const index = 10000; // This variable does not change in the subsequent process. You are advised to declare it as a constant.
```


### Avoiding Mixed Use of Integers and Floating-Point Numbers in Variables of the number Type

For variables of the **number** type, integer data and floating-point data are distinguished during optimization at runtime. As such, avoid changing the data type of the variables after they have been initialized.

``` TypeScript
let intNum = 1;
intNum = 1.1; // This variable is declared as an integer data type. Avoid assigning a floating-point number to it.

let doubleNum = 1.1;
doubleNum = 1; // This variable is declared as a floating-point data type. Avoid assigning an integer to it.
```


### Avoiding Overflow in Arithmetic Operations

When arithmetic operations run into overflow, the engine enters a slower logic branch for processing overflow, affecting subsequent performance. Below are some suggestions to mitigate the overflow risk.

- For operations such as addition, subtraction, multiplication, and exponentiation, the value should not be greater than **INT32_MAX** (2147483647) or less than **INT32_MIN** (-2147483648).

- For operations such as & (and) and >>> (unsigned right shift), the value should not be greater than **INT32_MAX**.


### Extracting Constants in Loops to Reduce Attribute Access Times

If the constants do not change in the loop, they can be extracted outside the loop to reduce the number of access times.

``` TypeScript
class Time {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNum(num: number): number {
  let total: number = 348;
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    // The system searches for info and start of Time multiple times, and the values found each time are the same.
    total += ((Time.info[num - Time.start] & index) !== 0) ? 1 : 0;
  }
  return total;
}
```

You can extract **Time.info[num - Time.start]** as a constant to reduce the number of attribute access times and improves performance. The optimized code is as follows.

``` TypeScript
class Time {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNum(num: number): number {
  let total: number = 348;
  const info = Time.info[num - Time.start];  // Extract constants from the loop.
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    if ((info & index) != 0) {
      total++;
    }
  }
  return total;
}
```


## Functions

### Using Parameters to Pass External Variables

Using closures may cause extra overhead.  

``` TypeScript
let arr = [0, 1, 2];

function foo(): number {
  return arr[0] + arr[1];
}

foo();
```

In performance-sensitive scenarios, you are advised to pass external variables using parameters.
``` TypeScript
let arr = [0, 1, 2];

function foo(array: number[]): number {
  return array[0] + array[1];
}

foo(arr);
```


### Avoiding Optional Parameters

An optional function parameter may be **undefined**. When such a parameter is used in the function, the system needs to check whether the parameter is null, which will cause extra overhead.

``` TypeScript
function add(left?: number, right?: number): number | undefined {
  if (left != undefined && right != undefined) {
    return left + right;
  }
  return undefined;
}
```

Declare function parameters as mandatory parameters based on service requirements. You can use the default parameters.
``` TypeScript
function add(left: number = 0, right: number = 0): number {
  return left + right;
}
```


## Arrays

### Prioritizing TypedArray for Value Arrays

Where only arithmetic operations are involved, use **TypedArray**.

Sample code before optimization:
``` TypeScript
const arr1 = new Array<number>(1, 2, 3);
const arr2 = new Array<number>(4, 5, 6);
let res = new Array<number>(3);
for (let i = 0; i < 3; i++) {
  res[i] = arr1[i] + arr2[i];
}
```

Sample code after optimization:
``` TypeScript
const typedArray1 = Int8Array.from([1, 2, 3]);
const typedArray2 = Int8Array.from([4, 5, 6]);
let res = new Int8Array(3);
for (let i = 0; i < 3; i++) {
  res[i] = typedArray1[i] + typedArray2[i];
}
```


### Avoiding Sparse Arrays

When allocating an array whose size exceeds 1024 bytes or a sparse array during runtime, a hash table is used to store elements. This mode results in slower access speeds. Therefore, you should avoid converting arrays to sparse arrays during code development.

``` TypeScript
// Allocate an array of 100,000 bytes, for which a hash table is used to store elements.
let count = 100000;
let result: number[] = new Array(count);

// The array will become a sparse array when the value is changed to 9999 after the array is created.
let result: number[] = new Array();
result[9999] = 0;
```


### Avoiding Arrays of Union Types

When appropriate, use arrays that contain elements of the same type. That is, avoid using arrays of union types. Avoid mixed use of integer data and floating-point data in number arrays.

``` TypeScript
let arrNum: number[] = [1, 1.1, 2];  // Both integer data and floating-point data are used in a value array.

let arrUnion: (number | string)[] = [1, 'hello'];  // Union array.
```

Place the data of the same type in the same array based on service requirements. 
``` TypeScript
let arrInt: number[] = [1, 2, 3];
let arrDouble: number[] = [0.1, 0.2, 0.3];
let arrString: string[] = ['hello', 'world'];
```


## Exceptions

### Avoiding Frequent Exceptions

Creating exceptions involves constructing the stack frame for the exception, which may performance overhead. In light of this, avoid frequently throwing exceptions in performance-sensitive scenarios, for example, in **for** loop statements.

Sample code before optimization:

``` TypeScript
function div(a: number, b: number): number {
  if (a <= 0 || b <= 0) {
    throw new Error('Invalid numbers.');
  }
  return a / b;
}

function sum(num: number): number {
  let sum = 0;
  try {
    for (let t = 1; t < 100; t++) {
      sum += div(t, num);
    }
  } catch (e) {
    console.info(e.message);
  }
  return sum;
}
```

Sample code after optimization:

``` TypeScript
function div(a: number, b: number): number {
  if (a <= 0 || b <= 0) {
    return NaN;
  }
  return a / b;
}

function sum(num: number): number {
  let sum = 0;
  for (let t = 1; t < 100; t++) {
    if (num <= 0) {
      console.info('Invalid numbers.');
    }
    sum += div(t, num);
  }
  return sum;
}
```
