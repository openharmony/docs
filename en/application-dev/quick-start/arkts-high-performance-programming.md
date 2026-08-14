# ArkTS Performant Programming Practices

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao; @cy917474985-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e25164b4c5d2db315865d228475dc21473dba5fb translatedAt=2026-08-13T08:50:44.903Z pushedAt=2026-08-13T11:51:52.249Z -->

## Overview

This topic provides a set of performant programming practices that you can apply in performance-critical scenarios. They are techniques and recommendations drawn from real-world development. Following these practices in your service implementation can help develop performant applications. For details about ArkTS programming specifications, see [ArkTS Coding Style Guide](./arkts-coding-style-guide.md).

## Declarations and Expressions

### Using const to Declare Unchanged Variables

You are advised to use **const** to declare variables that remain unchanged.

<!-- @[const_variable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
const index = 10000; // This variable does not change later, so declare it as a constant.
```

### Avoiding Mixed Use of Integers and Floating-Point Numbers in Variables of the number Type

For variables of the **number** type, integer data and floating-point data are distinguished during optimization at runtime. As such, avoid changing the data type of the variables after they have been initialized.

<!-- @[number_int_float](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let intNum = 1;
intNum = 1.1;  // This variable is declared as integer data. Do not assign floating-point data to it later.

let doubleNum = 1.1;
doubleNum = 1;  // This variable is declared as floating-point data. Do not assign integer data to it later.
```

### Avoiding Overflow in Arithmetic Operations

When arithmetic operations run into overflow, the engine enters a slower logic branch for processing overflow, affecting subsequent performance. Below are some suggestions to mitigate the overflow risk.

- For operations such as addition, subtraction, multiplication, and exponentiation, the value should not be greater than **INT32_MAX** (2147483647) or less than **INT32_MIN** (-2147483648).

- For operations such as & (and) and >>> (unsigned right shift), the value should not be greater than **INT32_MAX**.

### Extracting Constants in Loops to Reduce Attribute Access Times

If the constants do not change in the loop, they can be extracted outside the loop to reduce the number of access times.

<!-- @[constant_in_loop_poor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
class Time {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNum(num: number): number {
  let total: number = 348;
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    // Here, `info` and `start` of `Time` are looked up multiple times, and each lookup returns the same value.
    total += ((Time.info[num - Time.start] & index) !== 0) ? 1 : 0;
  }
  return total;
}
```

You can extract **Time.info[num - Time.start]** as a constant to reduce the number of attribute access times and improve performance. The optimized code is as follows.

<!-- @[constant_in_loop_better](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
class TimeBetter {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNumBetter(num: number): number {
  let total: number = 348;
  const info = TimeBetter.info[num - TimeBetter.start];  // Extract the invariant from the loop.
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

<!-- @[outside_variable_poor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let arr = [0, 1, 2];

function fooWithout(): number {
  return arr[0] + arr[1];
}

fooWithout();
```

In performance-sensitive scenarios, you are advised to pass external variables using parameters.

<!-- @[outside_variable_better](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let arr_ = [0, 1, 2];

function fooWithArray(array: number[]): number {
  return array[0] + array[1];
}

fooWithArray(arr_);
```

### Avoiding Optional Parameters

An optional function parameter may be **undefined**. When such a parameter is used in the function, the system needs to check whether the parameter is null, which will cause extra overhead.

<!-- @[avoid_optional_parameters_poor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
function add(left?: number, right?: number): number | undefined {
  if (left != undefined && right != undefined) {
    return left + right;
  }
  return undefined;
}
```

Declare function parameters as mandatory parameters based on service requirements. You can use the default parameters.

<!-- @[avoid_optional_parameters_better](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
function addWithParams(left: number = 0, right: number = 0): number {
  return left + right;
}
```

## Arrays

### Prioritizing TypedArray for Value Arrays

Where only arithmetic operations are involved, use **TypedArray**.

Sample code before optimization:

<!-- @[use_typearray_poor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
const arr1 = new Array<number>(1, 2, 3);
const arr2 = new Array<number>(4, 5, 6);
let res = new Array<number>(3);
for (let i = 0; i < 3; i++) {
  res[i] = arr1[i] + arr2[i];
}
```

Sample code after optimization:

<!-- @[use_typearray_better](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
const typedArray1 = Int8Array.from([1, 2, 3]);
const typedArray2 = Int8Array.from([4, 5, 6]);
let res1 = new Array<number>(3);
for (let i = 0; i < 3; i++) {
  res1[i] = typedArray1[i] + typedArray2[i];
}
```

### Avoiding Sparse Arrays

When allocating an array whose size exceeds 1024 bytes or a sparse array during runtime, a hash table is used to store elements. This mode results in slower access speeds. Therefore, you should avoid converting arrays to sparse arrays during code development.

<!-- @[avoid_sparse_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Directly allocating an array of size 100000 is handled at runtime by using a hash table to store elements.
let count = 100000;
let res: number[] = new Array(count).fill(0);

// After creating an array, assigning a value directly at index 9999 makes it a sparse array.
let result: number[] = [];
result[9999] = 0;
```

### Avoiding Arrays of Union Types

When appropriate, use arrays that contain elements of the same type. That is, avoid using arrays of union types. Avoid mixed use of integer data and floating-point data in number arrays.

<!-- @[avoid_joint_type_poor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let arrNum: number[] = [1, 1.1, 2]; // Mix integer and floating-point type data in a numeric array.
let arrUnion: (number | string)[] = [1, 'hello']; // Union type array
```

Place the data of the same type in the same array based on service requirements. 

<!-- @[avoid_joint_type_better](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let arrInt: number[] = [1, 2, 3];
let arrDouble: number[] = [0.1, 0.2, 0.3];
let arrString: string[] = ['hello', 'world'];
```

## Exceptions

### Avoiding Frequent Exceptions

Creating exceptions involves constructing the stack frame for the exception, which may incur performance overhead. In light of this, avoid frequently throwing exceptions in performance-sensitive scenarios, for example, in **for** loop statements.

Sample code before optimization:

<!-- @[exception_handling_poor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->

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

<!-- @[exception_handling_better](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/PerformantPractices/entry/src/main/ets/pages/Index.ets) -->     

``` TypeScript
function divBetter(a: number, b: number): number {
  if (a <= 0 || b <= 0) {
    return NaN;
  }
  return a / b;
}

function sumBetter(num: number): number {
  let sum = 0;
  for (let t = 1; t < 100; t++) {
    // Intercept exceptions directly to avoid frequent exceptions.
    if (num <= 0) {
      console.info('Invalid numbers.');
    }
    sum += divBetter(t, num);
  }
  return sum;
}
```