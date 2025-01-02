# Sendable Object Overview

On the traditional JS engine, there is only one way to optimize the concurrent communication overhead of objects. That is, the implementation is moved to the Native side, and the concurrent communication overhead is reduced through the transferable object (transferabled-object.md) transfer or sharing mode. However, developers still have the requirement for concurrent communication of a large number of objects. This problem has not been solved in the JS engine implementation in the industry.

ArkTS provides the Sendable object type to solve the preceding problem through reference transfer during concurrent communication.

The Sendable object can be shared. It points to the same JS object across threads. If the Sendable object contains JS or Native content, it can be directly shared. If the bottom layer is implemented by Native, thread security must be considered. The following figure shows the communication process.

![sendable](figures/sendable.png)

Unlike other ArkTS objects, data objects that comply with the Sendable protocol must be of a fixed type at run time.

When multiple concurrent instances attempt to update Sendable data at the same time, data contention occurs, for example, multi-thread operations of [ArkTS shared container](arkts-collections-introduction.md). Therefore, ArkTS provides the asynchronous lock (arkts-async-lock-introduction.md) mechanism to avoid data competition between different concurrent instances. In addition, you can use the object freezing interface (sendable-freeze.md) to freeze an object and change it to a read-only object. In this way, you do not need to consider data competition.

The Sendable object provides efficient communication between concurrent instances, that is, the reference transfer capability. It is applicable to scenarios where developers customize large objects that require inter-thread communication. For example, a sub-thread reads data from the database and returns the data to the host thread.

## Basic Concepts

### Sendable Protocol

The Sendable protocol defines the sendable object system and its specifications of ArkTS. Data that complies with the Sendable protocol (hereinafter referred to as Sendable objects) can be transferred between ArkTS concurrent instances.

By default, sendable data is passed by reference between ArkTS concurrent instances (including the main thread and the worker thread of TaskPool or Worker). Pass-by-copy is also supported.

### ISendable

The interface **ISendable {}** is introduced to the ArkTS common library [@arkts.lang](../reference/apis-arkts/js-apis-arkts-lang.md) without any necessary method or property. **ISendable** is the parent type of all sendable types except null and undefined. **ISendable** is mainly used when you want to customize the sendable data struct. The class decorator [@Sendable decorator](#sendable-decorator) is the syntax sugar for implementing ISendable.

### Sendable Class

> **NOTE**
>
> Since API version 11, the @Sendable decorator can be used to verify the sendable class.

A sendable class must meet the following requirements:

1. This function is available only when the [@Sendable decorator](#sendable-decorator) is marked.

2. The Sendable constraints must be met. For details, see [Sendable Usage Rules](sendable-constraints.md).

### Sendable Function

> **NOTE**
>
> - Since API version 12, the @Sendable decorator can be used to verify the sendable function.
>
> - To use a sendable function in API version 12, you must configure "compatibleSdkVersionStage": "beta3" in the project. Otherwise, the function does not take effect. For details, see [build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5).

A sendable function must meet the following requirements:

1. This function is available only when the [@Sendable decorator](#sendable-decorator) is marked.

2. The Sendable constraints must be met. For details, see [Sendable Usage Rules](sendable-constraints.md).

### Sendable Interface

A sendable interface must meet the following requirements:

1. Be [ISendable](#isendable) or inherit from [ISendable](#isendable).

2. The Sendable constraints must be met. For details, see [Sendable Usage Rules](sendable-constraints.md).

### Sendable Data Types

- All basic ArkTS data types: boolean, number, string, bigint, null, and undefined.

- [Container type data](arkts-collections-introduction.md) defined in the ArkTS language standard library ([@arkts.collections](../reference/apis-arkts/js-apis-arkts-collections.md) must be explicitly introduced).

- [Asynchronous lock object](arkts-async-lock-introduction.md) defined in the ArkTS language standard library ([@arkts.utils](../reference/apis-arkts/js-apis-arkts-utils.md) must be explicitly introduced).

- Interfaces that inherit [ISendable](#isendable).

- Class labeled with the [@Sendable decorator](#sendable-decorator).

- Function labeled with the [@Sendable decorator](#sendable-decorator).

- Sendable System Objects
  - [Sendable User Preferences](../reference/apis-arkdata/js-apis-data-sendablePreferences.md)
  - [Sendable Color Space Management](../reference/apis-arkgraphics2d/js-apis-sendableColorSpaceManager.md)
  - [Sendable Object-based Image Processing](../reference/apis-image-kit/js-apis-sendableImage.md)
  - [Resource Management](../reference/apis-localization-kit/js-apis-sendable-resource-manager.md)
  - [SendableContext Object Management](../reference/apis-ability-kit/js-apis-app-ability-sendableContextManager.md)

- Elements whose union type data is of the sendable type.

> **NOTE**
>
> - The transfer of JS built-in objects between concurrent instances complies with the structured clone algorithm. The cross-thread behavior is copy transfer. Therefore, the instance of a JS built-in object is not of the sendable type.
>
> - Object literals and array literals are passed between concurrent instances in compliance with the structured clone algorithm, and the semantics is passed by copy. Therefore, object literals and array literals are not of the sendable type.


## Implementation Principle of the Sendable Function

To implement reference transfer of [Sendable data](#sendable-data-types) between different concurrent instances, the Sendable shared object is allocated in the shared heap to implement memory sharing across concurrent instances.

The shared heap is a process-level heap space. Different from the local heap of a VM, the local heap can be accessed only by a single concurrent instance, while the shared heap can be accessed by all threads. The cross-thread behavior of a Sendable shared object is reference passing. Therefore, the Sendable may be referenced by multiple concurrent instances. Whether the Sendable shared object is alive depends on whether the objects of all concurrent instances have references to the Sendable shared object.

Relationship between SharedHeap and LocalHeap

![image_0000002001521153](figures/image_0000002001521153.png)

The LocalHeap of each concurrent instance is isolated. The SharedHeap is a process-level heap and can be referenced by all concurrent instances. However, SharedHeap cannot reference objects in LocalHeap.


## @Sendable Decorator

Declare and verify the Sendable class and Sendable function.

| @Sendable decorator| Description|
| -------- | -------- |
| Decorator parameters| None.|
| Use scenario restrictions| The decorator can be used only in projects of the stage model. It can be used only in .ets files.|
| Restrictions for decorated function types| Only common functions and async functions can be decorated by @Sendable.|
| Inheritance relationship restrictions for decorated classes| A sendable class can inherit only from another sendable class. A common class cannot inherit from a sendable class.|
| Property type restrictions for decorated objects| 1. The following types are supported: string, number, boolean, bigint, null, undefined, Sendable class, collections.Array, collections.Map, and collections.Set.<br>2. Closure variables are not allowed.<br>3. Private attributes cannot be defined using \#. Use private instead.<br>4. Computed properties are not supported.|
| Other property restrictions for decorated objects| Member properties must be initialized explicitly. They cannot be followed by exclamation marks (!).|
| Restrictions on method parameters in decorated functions or class objects| Local variables, input parameters, and variables imported through **import** are supported. Do not use closure variables, except the sendable class and sendable function defined at the top layer.|
| Restrictions on the Sendable Class and Sendable Function| Properties cannot be added or deleted, but can be modified. The property types before and after the modification must be the same. Methods cannot be modified.|
| Use scenario| 1. Use the class method or Sendable function in TaskPool or Worker.<br>2. The sendable type is used when a large amount of data needs to be transmitted.|

The following is an example of using a decorator to modify a class:

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

The following is an example of using the decorator to decorate a function:

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
