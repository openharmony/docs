# TypeScript and JavaScript High-Performance Programming Practices and Tools

## Overview

This document is intended to help you develop high-performance applications in TypeScript and JavaScript, by providing programming practices and profiling tool guidelines based on industry standards and real-world performance improvement experience.

For details about coding standards and best practices to follow, see [TypeScript and JavaScript Coding Style Guide](../../contribute/OpenHarmony-Application-Typescript-JavaScript-coding-guide.md).

## TypeScript and JavaScript High-Performance Programming Practices

This section outlines some methods and suggestions for writing performant code, which are summarized during development. During service implementation, follow these methods and suggestions as appropriate.

Each code example in this section is marked with "Correct" or "Incorrect."

### Attribute Access, Addition, and Deletion

#### Extracting Constants in Hotspot Loops to Reduce Attribute Access Times

In the following example extracted from real-world use cases, a large number of constant access operations are performed in the loop. As the constants do not change in the loop, they can be extracted outside the loop to reduce the number of access times.

[Incorrect Example]

``` TypeScript
// Code before optimization
private getDay(year: number): number {
  /* Year has (12 * 29 =) 348 days at least */
  let totalDays: number = 348;
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    // The system searches for INFO and START of Time for multiple times, and the values found each time are the same.
    totalDays += ((Time.INFO[year- Time.START] & index) !== 0) ? 1 : 0;
  }
  return totalDays + this.getDays(year);
}
```

You can extract hotspot function constants from **Time.INFO[year - Time.START]**. In this way, the number of attribute access times can be greatly reduced, which can lead to huge performance improvement.

[Correct Example]

``` TypeScript
// Code after optimization
private getDay(year: number): number {
  /* Year has (12 * 29 =) 348 days at least */
  let totalDays: number = 348;
  const info = Time.INFO[year - Time.START]; // 1. Extract invariants from the loop.
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    if ((info & index) !== 0) {
      totalDays++;
    }
  }
  return totalDays + this.getDays(year);
}
```

#### Avoid Frequent Use of delete

If an attribute of an object is deleted, the layout of the object will be changed, which affects runtime optimization and deteriorates the execution performance.

> **NOTE**
>
> When possible, avoid using **delete** to delete any attribute of an object. If necessary, you are advised to use **map** and **set** or the [high-performance container classes](../arkts-utils/container-overview.md) implemented by the engine.

[Incorrect Example]

``` TypeScript
class O1 {
  x: string | undefined = "";
  y: string | undefined = "";
}
let obj: O1 = {x: "", y: ""};

obj.x = "xxx";
obj.y = "yyy";
delete obj.x;
```

You are advised to use either of the following methods to add or delete attributes:

[Correct Example]

``` TypeScript
// Example 1: Set the attributes that are no longer used in the object to null.
class O1 {
  x: string | null = "";
  y: string | null = "";
}
let obj: O1 = {x: "", y: ""};

obj.x = "xxx";
obj.y = "yyy";
obj.x = null;

// Example 2: Use a container class to operate attributes.
import HashMap from '@ohos.util.HashMap'; 
let myMap= new HashMap();

myMap.set("x", "xxx");
myMap.set("y", "yyy");
myMap.remove("x");
```

### Numerical Calculation

#### Avoiding Overflow in Arithmetic Operations

When arithmetic operations run into overflow, the engine enters the slow logic branch for processing overflow, affecting subsequent performance. Below are arithmetic operations that are prone to overflow:

- Addition, subtraction, multiplication, and exponentiation: To prevent integer overflow, ensure that the value is not greater than INT32_MAX or less than INT32_MIN.

- Operations with & (and), >>> (unsigned right shift), or other operators: To prevent integer overflow, ensure that the value is not greater than INT32_MAX.

### Data Structure

#### Using a Proper Data Structure

In the following example extracted from real-world use cases, the JavaScript Object is used as the container to process the map logic. You are advised to use **HashMap** instead.

[Incorrect Example]

``` TypeScript
getInfo(t1, t2) {
  if (!this.check(t1, t2)) {
    return "";
  }
  // The JavaScript Object is used as the container.
  let info= {};  
  this.setInfo(info);
  let t1= info[t2];
  return (t1!= null) ? t1: "";
}
setInfo(info) {
  // The map operation is performed inside the API.
  info[T1] ='Seventy six';  
  info[T2] = 'Ninety one';
  ... ...
  info[T3] = 'Twelve';
}
```

The code can be modified as follows. In addition to the standard built-in map provided by the engine, you can also use the [high-performance container classes](../arkts-utils/container-overview.md).

[Correct Example]

``` TypeScript
import HashMap from '@ohos.util.HashMap'; 

getInfo(t1, t2) {
  if (!this.check(t1, t2)) {
    return "";
  }
  // Replace the JavaScript Object with HashMap as the container.
  let info= new HashMap();
  this.setInfo(info);
  let t1= info.get(t2);
  return (t1!= null) ? t1: "";
}
setInfo(info) {
  // The map operation is performed inside the API.
  info.set (T1,'Seventy six');  
  info.set (T2, 'Ninety one');
  ... ...
  info.set (T3,'Twelve');
}
```

#### Prioritizing TypedArray for Value Arrays

Where only arithmetic operations are involved, prefer TypedArrays over Arrays.

Common TypedArrays include Int8Array, Uint8Array, Uint8ClampedArray, Int16Array, Uint16Array, Int32Array, Uint32Array, Float32Array, Float64Array, BigInt64Array, and BigUint64Array.

[Correct Example]

``` TypeScript
const typedArray1 = new Int8Array([1, 2, 3]); // In this scenario, avoid using new Array([1, 2, 3]).
const typedArray2 = new Int8Array([4, 5, 6]); // In this scenario, avoid using new Array([4, 5, 6]).
let res = new Int8Array(3);
for (let i = 0; i < 3; i++) {
  res[i] = typedArray1[i] + typedArray2[i];
}
```

#### Avoiding Sparse Arrays

When allocating an array, avoid its size exceeding 1024 or forming a sparse array.

When allocating an array whose size exceeds 1024 or forms a sparse array, a VM uses a hash table to store elements. This mode, compared with using an offset to access array elements, results in slower access speeds.

Therefore, during development, avoid changing arrays into sparse arrays.

[Incorrect Example]

``` TypeScript
// An array becomes a sparse array in the following scenarios:
// 1. The array is allocated with a count of 100000. In this scenario, the VM uses the hash table to store elements.
let count = 100000;
let result: number[] = new Array(count);

// 2. After the array is allocated, it is initialized at 9999 and becomes a sparse array.
let result: number[] = new Array();
result[9999] = 0;

// 3. The element attribute of the array is deleted. In this scenario, the VM also uses the hash table to store elements.
let result = [0, 1, 2, 3, 4];
delete result[0];
```

### Object Initialization

#### Using Literals to Create Objects

Objects can be created with dynamic properties. This approach to creating objects, however, does not allow more information to be obtained during front-end parsing. As a result, optimization information is not available for runtime.

[Incorrect Example]

``` TypeScript
let arr = new Array(); // Create an array.

let obj = new Object();  // Create a common object.

let oFruit = new Object();
oFruit.color = "red";
oFruit.name = "apple"; // Create an object and set its properties.
```

In scenarios where high performance is required, literals can be used to create objects so that instruction-level optimization can be achieved at runtime.

[Correct Example]

``` TypeScript
let arr = [];  // Create an array.

let obj = {}; // Create a common object.

class O1 {
  color: string = "";
  name: string = "";
}
let oFruit: O1 = {color: "red", name: "apple"};  // Create an object and set its properties.
```

#### Object Constructor Initialization

When constructing an object, provide default values for property initialization, and do not access uninitialized properties.

[Incorrect Example]

``` TypeScript
// Do not access uninitialized properties.
class A {
  x: number;
}

// Initialize the property in the constructor.
class A {
  x: number;
  constructor() {
  }
}

let a = new A();
// No value is assigned to x when it is used. In this case, the entire prototype chain is accessed.
print(a.x);
```

[Correct Example]

``` TypeScript
// Recommendation 1: Declare initialization.
class A {
  x: number = 0;
}

// Recommendation 2: Directly assign an initial value to the constructor.
class A {
  constructor() {
    this.x = 0;
  }
}

let a = new A();
print(a.x);
```

#### Correctly InitializIng Variables of Numeric Types

For variables of numeric types, the compiler distinguishes the integer type from the floating-point type during optimization. During initialization, if the expected value is an integer, initialize the variable to **0**. If the expected value is a floating-point value, initialize the variable to **0.0**. Do not initialize a numeric type variable to **undefined** or **null**.

[Correct Example]

``` TypeScript
function foo(d: number) : number {
  // Variable i is expected to be an integer. Do not declare it as undefined/null or 0.0. Initialize it to 0.
  let i: number = 0; 
  i += d;
  return i;
}
```

#### Avoiding Dynamically Adding Properties

When creating an object, if you plan to add properties to it later, set the properties to **undefined**. Dynamically adding properties causes object layout changes, affecting compiler and runtime optimization effects.

[Incorrect Example]

``` TypeScript
// The z property needs to be added to obj.
class O1 {
  x: string = "";
  y: string = "";
}
let obj: O1 = {"x": xxx, "y": "yyy"};
...
// This dynamic addition mode is not recommended.
obj.z = "zzz";
```

[Correct Example]

``` TypeScript
class O1 {
  x: string = "";
  y: string = "";
  z: string = "";
}
let obj: O1 = {"x": "xxx", "y": "yyy", "z": ""};
...
obj.z = "zzz";
```

#### Matching Input Parameters for Invoking Constructors with Type Annotations

TypeScript uses type annotation to specify the data types for identifiers, which is optional at compile time. If the actual type of the argument does not match the annotated type, the internal optimization effect of the engine is affected.

[Incorrect Example]

``` TypeScript
class A {
    private a: number | undefined;
    private b: number | undefined;
    private c: number | undefined;
    constructor(a?: number, b?: number, c?: number) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}
// No parameter is passed in the new process. Therefore, the initial value of undefined is assigned to a, b, and c, which is inconsistent with the annotated type.
let a = new A();
```

In the preceding example, there is a high probability that the input parameter type is number.

Therefore, the code must be modified as follows, so that the type of the passed parameter is number, instead of undefined.

[Correct Example]

``` TypeScript
class A {
    private a: number | undefined;
    private b: number | undefined;
    private c: number | undefined;
    constructor(a?: number, b?: number, c?: number) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}
// The default value 0 is passed in during initialization.
let a = new A(0, 0, 0);
```

#### Declaring Immutable Variables as Constants

If a variable is immutable, initialize it with **const**.

[Incorrect Example]

``` TypeScript
// This variable does not change in the subsequent process. You are advised to declare it as a constant.
let N = 10000;

function getN() {
  return N;
}
```

[Correct Example]

``` TypeScript
const N = 10000; 

function getN() {
  return N;
}
```

### Interfaces and Inheritance

#### Avoiding Use of type Annotations

If the type of an input parameter is annotated as **type**, the actual argument passed in may be an object literal or a class. As the type is not fixed, the compiler and VM cannot make optimization based on compile-time assumptions.

[Incorrect Example]

``` TypeScript
// The type cannot be determined at compile time. It may be an object literal or another class Person.
type Person = {
  name: string;
  age: number;
};
 
function greet(person: Person) {
  return "Hello " + person.name;
}

// The type mode is not recommended, because it can be used in the following two modes, resulting in failure to determine the type at compile time.
// Invocation mode 1
class O1 {
  name: string = "";
  age: number = 0;
}
let objectliteral: O1 = {name : "zhangsan", age: 20 };
greet(objectliteral);

// Invocation mode 2
class Person {
  name: string = "zhangsan";
  age: number = 20;
}
let person = new Person();
greet(person);
```

[Correct Example]

``` TypeScript
interface Person {
  name: string ;
  age: number;
}
 
function greet(person: Person) {
  return "Hello " + person.name;
}

class Person {
  name: string = "zhangsan";
  age: number = 20;
}

let person = new Person();
greet(person);
```

### Function Invocation

#### Maintaining Consistency Between Declarations and Actual Parameters

The declared number and type of parameters must be the same as those of the actual arguments. If no type is specified, the parameter is processed as **undefined**, which may result in inconsistency with the actual input parameter type and cause the system to enter a slow path during running, affecting the performance.

[Incorrect Example]

``` TypeScript
function add(a: number, b: number) {
  return a + b;
}
// The count of parameters passed in is 3, inconsistent with the declared count (2).
add(1, 2, 3);
// The count of parameters passed in is 1, inconsistent with the declared count (2).
add(1);
// The type of parameters passed in is string, inconsistent with the declared type (number).
add("hello", "world");
```

[Correct Example]

``` TypeScript
function add(a: number, b: number) {
  return a + b;
}
// The count and type of parameters passed in are consistent with the declarations.
add(1, 2);
```

#### Prioritizing Parameters in Transferring Internal Variables of Functions

Whenever possible, use parameters to transfer internal variables of functions, instead of closures. As a parameter, a closure is created and accessed one more time.

[Incorrect Example]

``` TypeScript
let arr = [0, 1, 2];

function foo() {
  // Whenever possible, use parameters to transfer arr.
  return arr[0] + arr[1];
}
foo();
```

[Correct Example]

``` TypeScript
let arr = [0, 1, 2];

function foo(array: Array) : number {
  // Whenever possible, use parameters to transfer arr.
  return array[0] + array[1];
}
foo(arr);
```

### Function and Class Declaration

#### Avoiding Dynamic Declarations of Functions and Classes

Whenever possible, avoid dynamic declarations of functions and classes.

In the following example, class **Add** and class **Sub** are dynamically declared. As a result, each time **foo** is called, these two classes are re-created, which affects the memory and performance.

[Incorrect Example]

``` TypeScript
function foo(f: boolean) {
  if (f) {
    return class Add{};
  } else {
    return class Sub{};
  }
}
```

[Correct Example]

``` TypeScript
class Add{};
class Sub{};
function foo(f: boolean) {
  if (f) {
    return Add;
  } else {
    return Sub;
  }
}
```

## TypeScript and JavaScript Performance Profiling Tools

Depending on the use case, you can use different performance profiling tools to track the execution times on a phase-by-phase basis and make informed optimization.

The available tools are as follows:

1. To start with, use the provided [Smartperf](../../device-dev/device-test/smartperf-host.md) tool to gain a big-picture view of your application's execution times and quickly identify the modules for performance improvement.
2. Regarding the modules identified at step 1, determine whether the time consumption is caused by TypeScript and JavaScript code or C++ code. If the issue lies in C++ code, use the Hiperf tool for further analysis. If the issue lies in TypeScript and JavaScript code, use the [CPU Profiler](application-performance-analysis.md) tool.
3. For VM developers, you may also need the RUNTIME_STAT tool for further analysis.

### Smartperf

With [Smartperf](../../device-dev/device-test/smartperf-host.md), you can collect the time consumption information while the application is running at a specific phase. Most of the time consumption information is about garbage collection (GC). If most APIs at the phase are implemented in TypeScript and JavaScript, and the trace shows that this phase is time-consuming, you can use [CPU Profiler](application-performance-analysis.md) to further analyze the time consumption of the TypeScript and JavaScript code.

In addition to viewing system traces, you can add some trace points to key processes of application source code for performance analysis. **startTrace** is used to record the start point of a trace, and **finishTrace** the end point of the trace. Below is an example of adding trace points.

``` TypeScript
import hiTraceMeter from '@ohos.hiTraceMeter';
... ...
hiTraceMeter.startTrace("fillText1", 100);
... ...
hiTraceMeter.finishTrace("fillText1", 100);
```

For details about how to add trace points at the application layer or Native layer, see [Development of Performance Tracing (ArkTS)](../dfx/hitracemeter-guidelines.md).

### Hiperf

For details about how to use Hiperf integrated in SmartPerf, see [Hiperf Usage](https://gitee.com/openharmony/developtools_smartperf_host/blob/master/ide/src/doc/md/quickstart_hiperf.md).

For details about how to use the standalone Hiperf tool, see [Hiperf](https://gitee.com/openharmony/developtools_hiperf).

### Time Consumption Analysis Tool at the TypeScript and JavaScript and NAPI Layer

The time required at the TypeScript and JavaScript layer is classified into the following types:

1. Time required for the ability lifecycle callbacks

2. Time required for the TypeScript and JavaScript service code callbacks of components

3. Time required for applying the TypeScript and JavaScript logic code

The time required at the NAPI layer is classified into the following types:

1. Time required by the TypeScript and JavaScript service code to call JavaScript APIs

2. Time required when the TypeScript and JavaScript service code calls the C/C++ implementation encapsulated through the NAPI

For the above time consumption scenarios, the [CPU Profiler](application-performance-analysis.md) tool is provided to identify hotspot functions and time-consuming code.

This tool supports the following collection modes:

- Real-time collection with DevEco Studio

- CLI-based collection with hdc shell

With CPU Profiler, you can collect information about hotspot functions executed in TypeScript and JavaScript. Based on the collected information, you can then conduct further analysis.
