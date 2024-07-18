# ArkTS Performant Programming Practices

## Overview


This topic provides suggestions on performant programming applied in performance-sensitive scenarios, helping you develop performant applications. Performant programming practices stand for some methods and suggestions for writing performant code, which are drawn from real-world development. During service implementation, follow these methods and suggestions as appropriate. For details, see [ArkTS Coding Style Guide](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-ArkTS-coding-style-guide.md).

## Declaration and Expression

### Using const to Declare Unchanged Variables

You are advised to use **const** to declare variables that remain unchanged.

``` TypeScript
const index = 10000; // This variable does not change in the subsequent process. You are advised to declare it as a constant.
```


### Avoiding Mixed Use of Integer Variables and Floating-point Variables of the number Type

For the **number** type, integer data and floating-point data are distinguished during optimization. Avoiding change of the data type after initialization is recommended.

``` TypeScript
let intNum = 1;
intNum = 1.1; // This variable is declared as the integer data. You are advised not to change it to the floating-point data.

let doubleNum = 1.1;
doubleNum = 1; // This variable is declared as the floating-point data. You are advised not to change it to the integer data.
```


### Avoiding Overflow in Arithmetic Operations

When arithmetic operations run into overflow, the engine enters the slow logic branch for processing overflow, affecting subsequent performance. Below are arithmetic operations that are prone to overflow:

- For operations such as addition, subtraction, multiplication, and exponentiation, the value should not be greater than **INT32_MAX** or less than **INT32_MIN**.

- For operations such as & (and) and >>> (unsigned right shift), the value should not be greater than **INT32_MAX**.


### Extracting Constants in Loops to Reduce Attribute Access Times

Constants frequently access the attributes in a loop. If the constant remains unchanged in the loop, it can be extracted outside the loop to reduce the number of attribute access times.

``` TypeScript
class Time {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNum(num: number): number {
  let total: number = 348;
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    // The system searches for info and start of Time for multiple times, and the values found each time are the same.
    total += ((Time.info[num - Time.start] & index) !== 0) ? 1 : 0;
  }
  return total;
}
```

This optimization can extract constants in **Time.info[num - Time.start]**, which greatly reduces the number of attribute access times and brings better performance. The optimized code is as follows:

``` TypeScript
class Time {
  static start: number = 0;
  static info: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
}

function getNum(num: number): number {
  let total: number = 348;
  const info = Time.info[num - Time.start];  // Extract invariants from the loop.
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    if ((info & index) != 0) {
      total++;
    }
  }
  return total;
}
```


## Function

### Using Parameter to Pass External Variables

Closures will cause additional creations and access overhead. In performance-sensitive scenarios, you are advised to use parameter to pass external variables instead of using closures.

``` TypeScript
let arr = [0, 1, 2];

function foo(): number {
  return arr[0] + arr[1];
}

foo();
```

You are advised to use parameter to pass external variables instead of using closures.
``` TypeScript
let arr = [0, 1, 2];

function foo(array: number[]): number {
  return array[0] + array[1];
}

foo(arr);
```


### Avoiding Optional Parameters

The optional parameter of the function may be **undefined**. When this parameter is used in the function, the system needs to check whether the parameter is null, which will cause extra overhead.

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


## Array

### Prioritizing TypedArray for Value Arrays

Where only arithmetic operations are involved, prefer **TypedArrays** over Arrays.

Before optimization
``` TypeScript
const arr1 = new Array<number>([1, 2, 3]);
const arr2 = new Array<number>([4, 5, 6]);
let res = new Array<number>(3);
for (let i = 0; i < 3; i++) {
  res[i] = arr1[i] + arr2[i];
}
```

After optimization
``` TypeScript
const typedArray1 = new Int8Array([1, 2, 3]);
const typedArray2 = new Int8Array([4, 5, 6]);
let res = new Int8Array(3);
for (let i = 0; i < 3; i++) {
  res[i] = typedArray1[i] + typedArray2[i];
}
```


### Avoiding Sparse Arrays

When allocating an array whose size exceeds 1024 or forms a sparse array, a **hash** table is used to store elements. This mode, compared with using an offset to access array elements, results in slower access speeds. Therefore, during development, avoid changing arrays into sparse arrays.

``` TypeScript
// Allocate an array of 100000 bytes and use a hash table to store elements when running.
let count = 100000;
let result: number[] = new Array(count);

// The array will become a sparse array when the value is changed to 9999 after the array is created.
let result: number[] = new Array();
result[9999] = 0;
```


### Avoiding Union Arrays

Avoid using union arrays. Avoid mixed use of integer data and floating-point data in value arrays.

``` TypeScript
let arrNum: number[] = [1, 1.1, 2]; // Use both integer data and floating-point data in a value array.

let arrUnion: (number | string)[] = [1, 'hello'];  // Union array.
```

Place the data of the same type in the same array based on service requirements.
``` TypeScript
let arrInt: number[] = [1, 2, 3];
let arrDouble: number[] = [0.1, 0.2, 0.3];
let arrString: string[] = ['hello', 'world'];
```


## Exception

### Avoiding Frequent Exceptions

When an exception occurs during creation, abnormal stack frames are constructed, causing performance loss. Avoid frequently throwing exceptions in performance-sensitive scenarios, for example, in **for** loop statements.

Before optimization

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

After optimization

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
