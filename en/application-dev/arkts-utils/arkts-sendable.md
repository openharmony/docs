# Sendable Development

## Basic Concepts

### Sendable Protocol

The Sendable protocol defines the sendable object system and its specifications of ArkTS. Data that complies with the Sendable protocol (referred to as [sendable data](#sendable-data-types)) can be passed between ArkTS concurrent instances.

By default, sendable data is passed by reference between ArkTS concurrent instances (including the main thread and the worker thread of TaskPool or Worker) and is allocated in the shared heap. Pass-by-copy is also supported. Non-sendable data is allocated in the local heap, which is private.

Data races may occur when multiple concurrent instances attempt to update mutable sendable data at the same time. To address this issue, ArkTS introduces the asynchronous lock.

**Figure 1** Sendable data and shared heap

![Sendable](figures/sendable.png)

**Figure 2** Pass-by-copy of serialized data

![Serialize](figures/serialize.png)

**Example**

```ts
import { taskpool, worker } from '@kit.ArkTS';

@Sendable
class A {}

let a: A = new A();

@Concurrent
function foo(a: A) {}
let task: taskpool.Task = new taskpool.Task(foo, a)

let w = new worker.ThreadWorker("entry/ets/workers/Worker.ets")

// 1. Implementation of TaskPool pass-by-sharing
taskpool.execute(task).then(() => {})

// 2. Implementation of Worker pass-by-sharing
w.postMessageWithSharedSendable(a)

// 3. Implementation of TaskPool pass-by-copy
task.setCloneList([a])
taskpool.execute(task).then(() => {})

// 4. Implementation of Worker pass-by-copy
w.postMessage(a)
```


### Sendable Class

> **NOTE**
>
> Since API version 11, the @Sendable decorator can be used to verify the sendable class.

A sendable class must meet the following requirements:
1. Be marked by and only by the [@Sendable decorator](#sendable-decorator-declaring-and-verifying-a-sendable-class).
2. Meet the [sendable usage rules](#sendable-usage-rules).

### Sendable Function

> **NOTE**
>
> Since API version 12, the @Sendable decorator can be used to verify the sendable function.
>
> To use a sendable function in API version 12, you must configure "compatibleSdkVersionStage": "beta3" in the project. Otherwise, the function does not take effect. For details, see [build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5).

A sendable function must meet the following requirements:
1. Be marked by and only by the [@Sendable decorator](#sendable-decorator-declaring-and-verifying-a-sendable-function).
2. Meet the [sendable usage rules](#sendable-usage-rules).

### Sendable Interface
A sendable interface must meet the following requirements:
1. Be [ISendable](#isendable) or inherit from [ISendable](#isendable).
2. Meet the [sendable usage rules](#sendable-usage-rules).


### Sendable Data Types

- All basic ArkTS data types: boolean, number, string, bigint, null, and undefined.
- Container type defined in the ArkTS common library. In this case, [@arkts.collections](../reference/apis-arkts/js-apis-arkts-collections.md) must be explicitly imported.
- **AsyncLock** object defined in the ArkTS common library. In this case, [@arkts.utils](../reference/apis-arkts/js-apis-arkts-utils.md) must be explicitly imported.
- Interfaces that inherit [ISendable](#isendable).
- Class marked with the [@Sendable decorator](#sendable-decorator-declaring-and-verifying-a-sendable-class).
- Function marked with the [@Sendable decorator](#sendable-decorator-declaring-and-verifying-a-sendable-function).
- System objects that have accessed the Sendable class. For details, see [Sendable System Objects](arkts-sendable-system-object-list.md).
- Elements whose union type data is of the sendable type.

> **NOTE**
>
> - JS built-in objects are passed between concurrent instances in compliance with the structured clone algorithm, and the semantics is passed by copy. Therefore, the instance of a JS built-in object is not of the sendable type.
>
> - Object literals and array literals are passed between concurrent instances in compliance with the structured clone algorithm, and the semantics is passed by copy. Therefore, object literals and array literals are not of the sendable type.
>
> - For details about the behavior differences between ArkTS collections APIs and native APIs, see [Behavior Differences](arkts-collections-vs-native-api-comparison.md).


### ISendable

The interface **ISendable {}** is introduced to the ArkTS common library [@arkts.lang](../reference/apis-arkts/js-apis-arkts-lang.md) without any necessary method or property. **ISendable** is the parent type of all sendable types except null and undefined. **ISendable** is mainly used when you want to customize the sendable data struct. The class decorator [@Sendable](#sendable-decorator-declaring-and-verifying-a-sendable-class) is the syntax sugar for implementing **ISendable**.


##  \@Sendable Decorator: Declaring and Verifying a Sendable Class

### Decorator Description
| \@Sendable Decorator        | Description                                                                  |
| ------------------------- | ---------------------------------------------------------------------- |
| Decorator parameters                | None.                                                                  |
| Use scenario restrictions              | The decorator can be used only in projects of the stage model. It can be used only in .ets files.                   |
| Inheritance relationship restrictions for decorated classes       | A sendable class can inherit only from another sendable class. A common class cannot inherit from a sendable class. |
| Property type restrictions for decorated objects | 1. The following types are supported: string, number, boolean, bigint, null, undefined, Sendable class, collections.Array, collections.Map, and collections.Set.<br>2. Closure variables are not allowed.<br>3. Private properties must be defined using **private**, rather than the number sign (#).<br>4. Computed properties are not supported.          |
| Other property restrictions for decorated objects| Member properties must be explicitly declared and initialized. They cannot be followed by exclamation marks (!).|
| Method parameters restrictions for decorated objects | Local variables, input parameters, and variables imported through **import** are supported. Closure variables are not allowed.          |
| Sendable class restrictions     | Properties cannot be added or deleted, but can be modified. The property types before and after the modification must be the same. Methods cannot be modified.  |
| Use scenario                 | 1. The class methods can be used in TaskPool or Worker.<br>2. The sendable type is used when a large amount of data needs to be transmitted.        |


### Decorator Example

```ts
@Sendable
class SendableTestClass {
  desc: string = "sendable: this is SendableTestClass ";
  num: number = 5;
  printName() {
    console.info("sendable: SendableTestClass desc is: " + this.desc);
  }
  get getNum(): number {
    return this.num;
  }
}
```

##  \@Sendable Decorator: Declaring and Verifying a Sendable Function

### Decorator Description
| \@Sendable Decorator        | Description                                                                  |
| ------------------------- | ---------------------------------------------------------------------- |
| Decorator parameters                | None.                                                                  |
| Use scenario restrictions              | The decorator can be used only in projects of the stage model. It can be used only in .ets files.                   |
| Restrictions for decorated function types         | Only common functions and async functions can be decorated by @Sendable. |
| Restrictions for the decorated function body           | Do not use closure variables, except the sendable class and sendable function defined at the top layer.|
| Sendable function restrictions   | Properties cannot be added, deleted, or modified.  |
| Use scenario                 | 1. The sendable function can be used in TaskPool or Worker.<br>2. The sendable type is used when a large amount of data needs to be transmitted.|


### Decorator Example

```ts
@Sendable
type SendableFuncType = () => void;

@Sendable
class TopLevelSendableClass {
  num: number = 1;
  PrintNum() {
    console.info("Top level sendable class");
  }
}

@Sendable
function TopLevelSendableFunction() {
  console.info("Top level sendable function");
}

@Sendable
function SendableTestFunction() {
  const topClass = new TopLevelSendableClass (); // Top-level sendable class.
  topClass.PrintNum();
  TopLevelSendableFunction (); // Top-level sendable function.
  console.info("Sendable test function");
}

@Sendable
class SendableTestClass {
  constructor(func: SendableFuncType) {
    this.callback = func;
  }
  callback: SendableFuncType; // Top-level sendable function.

  CallSendableFunc() {
    SendableTestFunction (); // Top-level sendable function.
  }
}

let sendableClass = new SendableTestClass(SendableTestFunction);
sendableClass.callback();
sendableClass.CallSendableFunc();
```

## Sendable Usage Rules

### 1. A sendable class can inherit only from another sendable class.

> **NOTE**
>
> The class here does not include variables. In other words, a sendable class cannot inherit from a variable.

**Positive example:**
```ts
@Sendable
class A {
  constructor() {
  }
}

@Sendable
class B extends A {
  constructor() {
    super()
  }
}
```

**Negative example:**
```ts
class A {
  constructor() {
  }
}

@Sendable
class B extends A {
  constructor() {
    super()
  }
}
```

### 2. A non-sendable class can inherit only from a non-sendable class.

**Positive example:**
```ts
class A {
  constructor() {
  }
}

class B extends A {
  constructor() {
    super()
  }
}
```

**Negative example:**
```ts
@Sendable
class A {
  constructor() {
  }
}

class B extends A {
  constructor() {
    super()
  }
}
```

### 3. A non-sendable class can implement only a non-sendable interface.

**Positive example:**
```ts
interface I {};

class B implements I {};
```

**Negative example:**
```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {};

class B implements I {};
```

### 4. The member variables of a sendable class or interface must be of a sendable data type.

**Positive example:**
```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**Negative example:**
```ts
@Sendable
class A {
  constructor() {
  }
  b: Array<number> = [1, 2, 3] // collections.Array must be used.
}
```

### 5. The member variables of a sendable class or interface cannot use the exclamation mark (!) for assertion.

**Positive example:**
```ts
@Sendable
class A {
  constructor() {
  }
  a: number = 0;
}
```

**Negative example:**
```ts
@Sendable
class A {
  constructor() {
  }
  a!: number;
}
```

### 6. The member variables of a sendable class or interface do not support computed property names.

**Positive example:**
```ts
@Sendable
class A {
    num1: number = 1;
    num2: number = 2;
    add(): number {
      return this.num1 + this.num2;
    }
}
```

**Negative example:**
```ts
enum B {
    b1 = "bbb"
}
@Sendable
class A {
    ["aaa"]: number = 1; // ["aaa"] is allowed in other classes in ets files
    [B.b1]: number = 2; // [B.b1] is allowed in other classes in ets files
}
```

### 7. The template type of a sendable class, collections.Array, collections.Map, and collections.Set in the generic class must be Sendable.

**Positive example:**
```ts
import { collections } from '@kit.ArkTS';

try {
  let arr1: collections.Array<number> = new collections.Array<number>();
  let num: number = 1;
  arr1.push(num)
} catch (e) {
  console.error(`taskpool execute: Code: ${e.code}, message: ${e.message}`);
}
```

**Negative example:**
```ts
import { collections } from '@kit.ArkTS';

try {
  let arr1: collections.Array<Array<number>> = new collections.Array<Array<number>>();
  let arr2: Array<number> = new Array<number>()
  arr2.push(1)
  arr1.push(arr2)
} catch (e) {
  console.error(`taskpool execute: Code: ${e.code}, message: ${e.message}`);
}
```

### 8. Variables defined in the context of the current module cannot be used in a sendable class.

Because the context of a sendable object varies among concurrent instances, direct access may cause unexpected behavior. A sendable object cannot use the variables defined in the context of the current module. Otherwise, a compile-time error is reported.

> **NOTE**
>
> Since API version 12, a sendable class object of the top level can be used internally by the sendable class itself.

**Positive example:**
```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {}

@Sendable
class B implements I {
  static o: number = 1;
  static bar(): B {
    return new B();
  }
}

@Sendable
class C {
  v: I = new B();
  u: number = B.o;

  foo() {
    return B.bar();
  }
}
```

**Negative example:**
```ts
import { lang } from '@kit.ArkTS';

type ISendable = lang.ISendable;

interface I extends ISendable {}

@Sendable
class B implements I {}

function bar(): B {
  return new B();
}

let b = new B();

{
  @Sendable
  class A implements I {}

  @Sendable
  class C {
    u: I = bar(); // bar is not a sendable class object. A compile-time error is reported.
    v: I = new A(); // A is not defined in the top level. A compile-time error is reported.

    foo() {
      return b; // b is not a sendable class object but an instance of the sendable class. A compile-time error is reported.
    }
  }
}

```

### 9. A sendable class and sendable function can only use the @Sendable decorator.

If the class decorator is defined in a .ts file, any modification to the class layout causes a runtime error.

**Positive example:**
```ts
@Sendable
class A {
  num: number = 1;
}
```

**Negative example:**
```ts
@Sendable
@Observed
class C {
  num: number = 1;
}
```

### 10. The Sendable type cannot be initialized using an object literal or array literal.

A sendable data type can be created only by using the **new** expression of the Sendable type.

**Positive example:**
```ts
import { collections } from '@kit.ArkTS';

let arr1: collections.Array<number> = new collections.Array<number>(1, 2, 3); // The type is Sendable.
```

**Negative example:**
```ts
import { collections } from '@kit.ArkTS';

let arr2: collections.Array<number> = [1, 2, 3]; // The type is not Sendable. A compile-time error is reported.
let arr3: number[] = [1, 2, 3]; // The type is not Sendable. No error is reported.
let arr4: number[] = new collections.Array<number>(1, 2, 3); // A compile-time error is reported.
```

### 11. A non-sendable type cannot be converted to a sendable type using **as**.

> **NOTE**
>
> A sendable type must be compatible with a non-sendable type without violating the sendable usage rules. Therefore, a sendable type can be converted to a non-sendable type using **as**.

**Positive example:**
```ts
class A {
  state: number = 0;
}

@Sendable
class SendableA {
  state: number = 0;
}

let a1: A = new SendableA() as A;
```

**Negative example:**
```ts
class A {
  state: number = 0;
}

@Sendable
class SendableA {
  state: number = 0;
}

let a2: SendableA = new A() as SendableA;
```

### 12. An arrow function is not sendable.
An arrow function cannot be decorated by @Sendable.

**Positive example:**
```ts
@Sendable
type SendableFuncType = () => void;

@Sendable
function SendableFunc() {
  console.info("Sendable func");
}

@Sendable
class SendableClass {
  constructor(f: SendableFuncType) {
    this.func = f;
  }
  func: SendableFuncType;
}

let sendableClass = new SendableClass(SendableFunc)
```

**Negative example:**
```ts
@Sendable
type SendableFuncType = () => void;
let func: SendableFuncType = () => {}; // A compile-time error is reported.

@Sendable
class SendableClass {
  func: SendableFuncType = () => {}; // A compile-time error is reported.
}
```

### 13. \@Sendable supports type decoration for functions only.
The @Sendable decorator supports type decoration for functions only.

**Positive example:**
```ts
@Sendable
type SendableFuncType = () => void;
```

**Negative example:**
```ts
@Sendable
type A = number; // A compile-time error is reported.

@Sendable
class C {}

@Sendable
type D = C; // A compile-time error is reported.
```

## Precautions

When using **Sendable** in HAR, enable the configuration of generating TS files. For details, see [Building TS Files](../quick-start/har-package.md#building-ts-files).

## Rules for Interaction with TS/JS

### ArkTS General Rules (Only for Sendable Objects Currently)

| Rule Description       |
| ----------- |
| When a sendable object is passed to a TS/JS interface, the object layout cannot be operated (adding or deleting properties, or changing property types).|
| When a sendable object is set to a TS/JS object, the object layout cannot be operated (adding or deleting properties, or changing property types) after the TS/JS object obtains the sendable object.|
| When a sendable object is placed in a TS/JS container, the object layout cannot be operated (adding or deleting properties, or changing property types) after the TS/JS object obtains the sendable object.|

> **NOTE**
>
> Changes of the property types do not include changes of the sendable object types, for example, from Sendable class A to Sendable class B.


### Native API Rules (Only for Sendable Objects Currently)

| Rule Description       |
| ----------- |
| Do not delete properties. The **napi_delete_property** interface cannot be used.|
| Do not add properties. The following interfaces cannot be used: **napi_set_property**, **napi_set_named_property**, and **napi_define_properties**.	|
| Do not modify property types. The following interfaces cannot be used: **napi_set_property**, **napi_set_named_property**, and **napi_define_properties**.|
| Symbol-related interfaces and types are not supported. The following interfaces cannot be used: **napi_create_symbol**, **napi_is_symbol_object**, and **napi_symbol**.|


## When to Use

Sendable objects can be passed by reference between concurrent instances. Compared with serialization, pass-by-reference is more efficient and does not cause the loss of member methods carried in the class. The sendable mode is used in the following scenarios:
1. Transferring a large amount of data (for example, more than 100 KB) across concurrent instances
2. Passing a class instance object carrying methods across concurrent instances

### Transferring a Large Amount of Data Across Concurrent Instances

The overhead of serialization across concurrent instances increases linearly with the data volume. When a large amount of data is transmitted (100 KB data takes about 1 ms to transmit), the overhead of data copy across concurrent instances is high, adversely affecting the parallelization performance. On the contrary, passing objects by reference improves performance.

**Example**
```ts
// index.ets
import { taskpool } from '@kit.ArkTS';
import { testTypeA, testTypeB, Test } from './sendable'

// Simulate data processing in a concurrent function.
@Concurrent
async function taskFunc(obj: Test) {
  console.info("test task res1 is: " + obj.data1.name + " res2 is: " + obj.data2.name);
}

async function test() {
  // Use TaskPool for data transfer.
  let a: testTypeA = new testTypeA("testTypeA");
  let b: testTypeB = new testTypeB("testTypeB");
  let obj: Test = new Test(a, b);
  let task: taskpool.Task = new taskpool.Task(taskFunc, obj);
  await taskpool.execute(task);
}

test();
```

```ts
// sendable.ets
// Assemble the data of a large size in a sendable class.
@Sendable
export class testTypeA {
  name: string = "A";
  constructor(name: string) {
    this.name = name;
  }
}

@Sendable
export class testTypeB {
  name: string = "B";
  constructor(name: string) {
    this.name = name;
  }
}

@Sendable
export class Test {
  data1: testTypeA;
  data2: testTypeB;
  constructor(arg1: testTypeA, arg2: testTypeB) {
    this.data1 = arg1;
    this.data2 = arg2;
  }
}
```


### Passing a Class Instance Object Carrying Methods Across Concurrent Instances

Methods will be lost during serialization of instance objects. In scenarios where instance methods must be called, use pass-by-reference. If data needs to be parsed during data processing, use the [ASON tool](../reference/apis-arkts/js-apis-arkts-utils.md#arktsutilsason).

**Example**
```ts
// Index.ets
import { taskpool, ArkTSUtils } from '@kit.ArkTS'
import { SendableTestClass, ISendable } from './sendable'

// Simulate data processing in a concurrent function.
@Concurrent
async function taskFunc(sendableObj: SendableTestClass) {
  console.info("SendableTestClass: name is: " + sendableObj.printName() + ", age is: " + sendableObj.printAge() + ", sex is: " + sendableObj.printSex());
  sendableObj.setAge(28);
  console.info("SendableTestClass: age is: " + sendableObj.printAge());

  // Parse the sendableObj.arr data to generate a JSON string.
  let str = ArkTSUtils.ASON.stringify(sendableObj.arr);
  console.info("SendableTestClass: str is: " + str);

  // Parse the data and generate ISendable data.
  let jsonStr = '{"name": "Alexa", "age": 23, "sex": "female"}';
  let obj = ArkTSUtils.ASON.parse(jsonStr) as ISendable;
  console.info("SendableTestClass: type is: " + typeof obj);
  console.info("SendableTestClass: name is: " + (obj as object)?.["name"]); // output: 'Alexa'
  console.info("SendableTestClass: age is: " + (obj as object)?.["age"]); // output: 23
  console.info("SendableTestClass: sex is: " + (obj as object)?.["sex"]); // output: 'female'
}
async function test() {
  // Use TaskPool for data transfer.
  let obj: SendableTestClass = new SendableTestClass();
  let task: taskpool.Task = new taskpool.Task(taskFunc, obj);
  await taskpool.execute(task);
}

test();
```

```ts
// sendable.ets
// Define a Test class to simulate the transfer of a class carrying methods.
import { lang, collections  } from '@kit.ArkTS'

export type ISendable = lang.ISendable;

@Sendable
export class SendableTestClass {
  name: string = 'John';
  age: number = 20;
  sex: string = "man";
  arr: collections.Array<number> = new collections.Array<number>(1, 2, 3);
  constructor() {
  }
  setAge(age: number) : void {
    this.age = age;
  }

  printName(): string {
    return this.name;
  }

  printAge(): number {
    return this.age;
  }

  printSex(): string {
    return this.sex;
  }
}
```
