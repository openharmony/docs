# TS&JS高性能编程实践及使用工具的指导

## 概述

本文参考业界标准，并结合应用TS&JS部分的性能优化实践经验，从应用编程指南、高性能编程实践、性能优化调试工具等维度，为应用开发者提供参考指导，助力开发者开发出高性能的应用。

本文主要提供TS&JS高性能编程实践及如何使用性能优化工具的相关建议。

## 应用TS&JS高性能编程实践

高性能编程实践，是在开发过程中逐步总结出来的一些高性能的写法和建议，在业务功能实现过程中，我们要同步思考并理解高性能写法的原理，运用到代码逻辑实现中。

本文中的实践示例代码，会统一标注正例或者反例，正例为推荐写法，反例为不推荐写法。

### 属性访问与属性增删

#### 热点循环中常量提取，减少属性访问次数

在实际的应用场景中抽离出来如下用例，其在循环中会大量进行一些常量的访问操作，该常量在循环中不会改变，可以提取到循环外部，减少属性访问的次数。

【反例】

``` TypeScript
// 优化前代码
class Time {
  static START: number = 1987;
  static INFO: number[] = [2001, 2002, 2003, 2004, 2005, 2006]
}

function getDay(year: number): number {
  let totalDays: number = 348;
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    // 此处会多次对Time的INFO及START进行查找，并且每次查找出来的值是相同的
    totalDays += ((Time.INFO[year - Time.START] & index) !== 0) ? 1 : 0;
  }
  return totalDays;
}
```

可以将`Time.INFO[year - Time.START]`进行热点函数常量提取操作，这样可以大幅减少属性的访问次数，性能收益明显。

【正例】

``` TypeScript
// 优化后代码
class Time {
  static START: number = 1987;
  static INFO: number[] = [2001, 2002, 2003, 2004, 2005, 2006];
}

function getDay(year: number): number {
  let totalDays: number = 348;
  // 从循环中提取不变量
  const info = Time.INFO[year - Time.START]; 
  for (let index: number = 0x8000; index > 0x8; index >>= 1) {
    if ((info & index) !== 0) {
      totalDays++;
    }
  }
  return totalDays;
}
```

#### 避免频繁使用delete

delete对象的某一个属性会改变其布局，影响运行时优化效果，导致执行性能下降。

> **说明：**
>
> 不建议直接使用delete删除对象的任何属性，如果有需要，建议使用map和set或者引擎实现的[高性能容器类](../arkts-utils/container-overview.md)。

【反例】

``` TypeScript
class O1 {
  x: string | undefined = "";
  y: string | undefined = "";
}

let obj: O1 = { x: "", y: "" };

obj.x = "xxx";
obj.y = "yyy";
delete obj.x;
```

建议使用如下两种写法之一实现属性的增删。

【正例】

``` TypeScript
// 例1：将Object中不再使用的属性设置为null
class O1 {
  x: string | null = "";
  y: string | null = "";
}

let obj: O1 = { x: "", y: "" };

obj.x = "xxx";
obj.y = "yyy";
obj.x = null;

// 例2：使用高性能容器类操作属性
import HashMap from '@ohos.util.HashMap';

let myMap = new HashMap<string, string>();

myMap.set("x", "xxx");
myMap.set("y", "yyy");
myMap.remove("x");
```

### 数值计算

#### 数值计算避免溢出

常见的可能导致溢出的数值计算包括如下场景，溢出之后，会导致引擎走入慢速的溢出逻辑分支处理，影响后续的性能。

- 针对加法、减法、乘法、指数运算等运算操作，应避免数值大于INT32_MAX或小于INT32_MIN，否则会导致int溢出。

- 针对&（and）、>>>（无符号右移）等运算操作，应避免数值大于INT32_MAX，否则会导致int溢出。

### 数据结构

#### 使用合适的数据结构

在实际的应用场景中抽离出来如下用例，该接口中使用JS Object来作为容器去处理Map的逻辑，建议使用HashMap来进行处理。

【反例】

``` TypeScript
class InfoUtil {
  getInfo(t1: string, t2: string): string {
    if (t1 === t2) {
      return "";
    }
    // 此处使用Record普通对象作为容器
    let info: Record<string, string> = {};
    this.setInfo(info);
    let t3 = info[t2];
    return (t3 != null) ? t3 : "";
  }

  setInfo(info: Record<string, string>) {
    // 接口内部实际上进行的是map的操作
    info.aaa = 'aaa';
    info.bbb = 'bbb';
    info.ccc = 'ccc';
  }
}
```

代码可以进行如下修改，除了使用引擎中提供的标准内置map之外，还可以使用ArkTS提供的[高性能容器类](../arkts-utils/container-overview.md)。

【正例】

``` TypeScript
import HashMap from '@ohos.util.HashMap';

class InfoUtil {
  getInfo(t1: string, t2: string): string {
    if (t1 === t2) {
      return "";
    }
    // 此处改为使用HashMap进行读写操作
    let info: HashMap<string, string> = new HashMap();
    this.setInfo(info);
    let t3 = info.get(t2);
    return (t3 != null) ? t3 : "";
  }
  setInfo(info:HashMap<string, string>) {
    // ...
    info.set('aaa','aaa');
    info.set('bbb','bbb');
    info.set('ccc','ccc');
  }
}
```

#### 数值数组推荐使用TypedArray

如果是涉及纯数值计算的场合，推荐使用TypedArray数据结构。

常见的TypedArray包括：Int8Array、Uint8Array、Uint8ClampedArray、Int16Array、Uint16Array、Int32Array、Uint32Array、Float32Array、Float64Array、BigInt64Array、BigUint64Array。

【正例】

``` TypeScript
const typedArray1 = new Int8Array([1, 2, 3]); // 针对这一场景，建议不要使用new Array([1, 2, 3])
const typedArray2 = new Int8Array([4, 5, 6]); // 针对这一场景，建议不要使用new Array([4, 5, 6])
let res = new Int8Array(3);
for (let i = 0; i < 3; i++) {
  res[i] = typedArray1[i] + typedArray2[i];
}
```

#### 避免使用稀疏数组

分配数组时，应避免其大小超过1024或形成稀疏数组。

虚拟机在分配超过1024大小的数组或者针对稀疏数组，均采用hash表来存储元素，相对使用偏移来访问数组元素速度较慢。

在开发时，尽量避免数组变成稀疏数组。

【反例】

``` TypeScript
// 如下几种情形会变成稀疏数组
// 1. 直接分配100000大小的数组，虚拟机会处理成用hash表来存储元素
let count = 100000;
let result: number[] = new Array(count);

// 2. 分配数组之后直接，在9999处初始化，会变成稀疏数组
let result: number[] = new Array();
result[9999] = 0;

// 3. 删除数组的element属性，虚拟机也会处理成用hash表来存储元素
let result = [0, 1, 2, 3, 4];
delete result[0];
```

### 对象初始化

#### 对象构造初始化

对象构造的时候，要提供默认值初始化，不要访问未初始化的属性。

【反例】

``` TypeScript
// 不要访问未初始化的属性
class A {
  x: number;
}

// 构造函数中要对属性进行初始化
class A {
  x: number;
  constructor() {
  }
}

let a = new A();
// x使用时还未赋值，这种情况会访问整个原型链
console.log((a.x).toString());
```

【正例】

``` TypeScript
// 推荐一：声明初始化
class A {
  x: number = 0;
}

// 推荐二：构造函数直接赋初值
class A {
  constructor() {
    this.x = 0;
  }
}

let a = new A();
console.log((a.x).toString());
```

#### number正确初始化

针对number类型，编译器在优化时会区分整型和浮点类型。开发者在初始化时如果预期是整型就初始化成0，如果预期是浮点型就初始化为0.0，不要把一个number类型初始化成undefined或者null。

【正例】

``` TypeScript
function foo(d: number) : number {
  // 变量i预期是整型，不要声明成undefined/null或0.0，直接初始化为0
  let i: number = 0; 
  i += d;
  return i;
}
```

#### 避免动态添加属性

对象在创建的时候，如果开发者明确后续还需要添加属性，可以提前置为undefined。动态添加属性会导致对象布局变化，影响编译器和运行时优化效果。

【反例】

``` TypeScript
// 后续obj需要再添加z属性
class O1 {
  x: string = "";
  y: string = "";
}
let obj: O1 = {"x": "xxx", "y": "yyy"};
// ...
// 这种动态添加方式是不推荐的
obj.z = "zzz";
```

【正例】

``` TypeScript
class O1 {
  x: string = "";
  y: string = "";
  z: string = "";
}
let obj: O1 = {"x": "xxx", "y": "yyy", "z": ""};
// ...
obj.z = "zzz";
```

#### 调用构造函数的入参要与标注类型匹配

由于TS语言类型系统是一种标注类型，不是编译期强制约束，如果入参的实际类型与标注类型不匹配，会影响引擎内部的优化效果。

【反例】

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
// new的过程中没有传入参数，a，b，c会获取一个undefined的初值，和标注类型不符
let a = new A();
```

针对上文的示例场景，开发者大概率预期该入参类型是number类型，需要显式写出来。

参照正例进行如下修改，不然会造成标注的入参是number，实际传入的是undefined。

【正例】

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
// 初始化直接传入默认值0
let a = new A(0, 0, 0);
```

#### 不变的变量声明为const

不变的变量推荐使用const进行初始化。

【反例】

``` TypeScript
// 该变量在后续过程中并未发生更改，建议声明为常量
let N = 10000;

function getN() {
  return N;
}
```

【正例】

``` TypeScript
const N = 10000; 

function getN() {
  return N;
}
```

### 接口及继承

#### 避免使用type类型标注

如果传入的参数类型是type类型，实际入参可能是一个object literal，也可能是一个class，编译器及虚拟机因为类型不固定，无法做编译期假设进而进行相应的优化。

【反例】

``` TypeScript
// type类型无法在编译期确认, 可能是一个object literal，也可能是另一个class Person
type Person = {
  name: string;
  age: number;
};
 
function greet(person: Person) {
  return "Hello " + person.name;
}

// type方式是不推荐的，因为其有如下两种使用方式，type类型无法在编译期确认
// 调用方式一
class O1 {
  name: string = "";
  age: number = 0;
}
let objectliteral: O1 = {name : "zhangsan", age: 20 };
greet(objectliteral);

// 调用方式二
class Person {
  name: string = "zhangsan";
  age: number = 20;
}
let person = new Person();
greet(person);
```

【正例】

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

### 函数调用

#### 声明参数要和实际的参数一致

声明的参数要和实际的传入参数个数及类型一致，如果不传入参数，则会作为undefined处理，可能造成与实际入参类型不匹配的情况，从而导致运行时走入慢速路径，影响性能。

【反例】

``` TypeScript
function add(a: number, b: number) {
  return a + b;
}
// 参数个数是2，不能给3个
add(1, 2, 3);
// 参数个数是2，不能给1个
add(1);
// 参数类型是number，不能给string
add("hello", "world");
```

【正例】

``` TypeScript
function add(a: number, b: number) {
  return a + b;
}
// 按照函数参数个数及类型要求传入参数
add(1, 2);
```

#### 函数内部变量尽量使用参数传递

能传递参数的尽量传递参数，不要使用闭包。闭包作为参数会多一次闭包创建和访问。

【反例】

``` TypeScript
let arr = [0, 1, 2];

function foo() {
  // arr 尽量通过参数传递
  return arr[0] + arr[1];
}
foo();
```

【正例】

``` TypeScript
let arr = [0, 1, 2];

function foo(array: Array) : number {
  // arr 尽量通过参数传递
  return array[0] + array[1];
}
foo(arr);
```

### 函数与类声明

#### 避免动态声明function与class

不建议动态声明function和class。

以如下用例为例，动态声明了class Add和class Sub，每次调用`foo`都会重新创建class Add和class Sub，对内存和性能都会有影响。

【反例】

``` TypeScript
function foo(f: boolean) {
  if (f) {
    return class Add{};
  } else {
    return class Sub{};
  }
}
```

【正例】

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

## TS&JS性能优化工具使用

通过如下工具和使用方法，能够帮助开发者查看待分析场景下各阶段的耗时分布情况，并进一步针对耗时情况使用对应的工具做细化分析。

工具使用介绍：

1. 针对应用开发者，推荐使用自带的[Smartperf工具](../../device-dev/device-test/smartperf-host.md)来进行辅助分析，可以从宏观角度查看应用各个阶段耗时分布情况，快速找到待分析优化模块。
2. 针对第一步分析得到的待优化模块，需要进行进一步分析确认耗时点是在TS&JS部分还是C++部分。C++部分耗时模块细化分析建议使用hiperf工具；针对TS&JS部分耗时，可以使用[CPU Profiler工具](application-performance-analysis.md)。
3. 针对虚拟机开发者，如果需要进一步拆分细化，推荐使用虚拟机提供的RUNTIME_STAT工具。

### Smartperf工具使用指导

以如下某个应用场景使用过程的trace为例，可以通过[Smartperf工具](../../device-dev/device-test/smartperf-host.md)抓取到应用使用阶段的耗时信息，其中大部分为GC（Garbage Collection，垃圾回收）等操作。如果此接口大部分是应用开发者通过TS&JS实现，并且在trace中体现此阶段比较耗时，则可以继续使用[CPU Profiler工具](application-performance-analysis.md)来进一步分析TS&JS部分耗时情况。

除了可以查看系统的trace之外，还可以在应用的源码的关键流程中加入一些trace点，用于做性能分析。startTrace用于记录trace起点，finishTrace用于记录trace终点，在应用中增加trace点的方式如下：

``` TypeScript
import hiTraceMeter from '@ohos.hiTraceMeter';
// ...
hiTraceMeter.startTrace("fillText1", 100);
// ...
hiTraceMeter.finishTrace("fillText1", 100);
```

### hiperf工具使用指导

集成在Smartperf的hiperf工具使用指导，具体可见 [HiPerf的抓取和展示说明](https://gitee.com/openharmony/developtools_smartperf_host/blob/master/ide/src/doc/md/quickstart_hiperf.md)。

hiperf工具的单独使用指导，具体可见 [hiperf应用性能优化工具](https://gitee.com/openharmony/developtools_hiperf)。

### TS&JS及NAPI层面耗时分析工具

TS&JS层面耗时主要分为如下几种情况：

1. Ability的生命周期回调的耗时。

2. 组件的TS&JS业务代码的回调的耗时。

3. 应用TS&JS逻辑代码耗时。

NAPI层面的耗时主要分为如下几种情况：

1. TS&JS业务代码通过调用JS API产生的耗时。

2. TS&JS业务代码调用开发者通过NAPI封装的C/C++实现时产生的耗时。

针对应用中的TS&JS及NAPI两种业务场景的耗时分析，我们提供了[CPU Profiler工具](application-performance-analysis.md)，用来识别热点函数及耗时代码。

其支持的采集方式如下：

- DevEco Studio连接设备实时采集；

- hdc shell连接设备进行命令行采集。

可以通过CPU Profiler工具，对TS&JS中执行的热点函数进行抓取。以应用实际使用场景为例，在此场景中，可以抓到应用中的某一热点函数，在此基础上，针对该接口做进一步分析。
