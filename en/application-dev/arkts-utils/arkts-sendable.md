# \@Sendable Decorator: Declaring and Verifying the Sendable Class

## Overview
If a concurrent function executed in the [TaskPool](../reference/apis-arkts/js-apis-taskpool.md) needs to transfer a class object and use the internal methods of the class, the class must be decorated with \@Sendable. The Sendable class has the following features:

- It can be serialized. Objects are allocated to their respective VM memory space and do not compete for access. Different threads can read and write objects simultaneously.

- Reference can be transferred during cross-thread transfer (not supported yet).


> **NOTE**
>
> Since API version 11, the @Sendable decorator can be used to verify the sendable class.
>
> Currently, the decorator can only be cloned and must be used together with [setCloneList](../reference/apis-arkts/js-apis-taskpool.md#setclonelist11). Otherwise, an exception is thrown.

## Basic Concepts

 Sendable class: a class decorated by @Sendable.


## Decorator Description
| \@Sendable Decorator        | Description                                                                  |
| ------------------------- | ---------------------------------------------------------------------- |
| Decorator parameters                | None.                                                                  |
| Use scenario restrictions              | This decorator can be used only in projects of the stage model. It can be used only in .ets files.                   |
| Inheritance relationship restrictions for decorated classes       | A Sendable class can inherit only from a Sendable class. A common class can inherit from a Sendable class. |
| Attribute type restrictions for decorated objects | The object type can be string, number, boolean, or SendableClass. Closure variables are not allowed. Private attributes must be defined using **private**, rather than the number sign (#). Calculation attributes are not supported.          |
| Other attribute restrictions for decorated objects| Member attributes must be initialized explicitly. Member attributes cannot be followed by question marks (?) or exclamation marks (!).|
| Method parameters restrictions for decorated objects | Local variables, input parameters, and variables imported through **import** are supported. Closure variables are not allowed.          |
| Sendable class restrictions     | Attributes cannot be added, deleted, or modified. The attribute types before and after the modification must be the same. Methods cannot be modified. The Sendable class must be declared or defined at the top layer of the file and cannot be defined in a function.  |
| Other restrictions                 | The file to export cannot contain non-SendableClass attributes. Only classes can be decorated. Interfaces and enums cannot be decorated.  |
| Use scenario                 | This decorator is recommended when TaskPool uses class methods or transfers a large amount of object data.        |


## Example

```ts
@Sendable
class TaskpoolTestClass {
  desc: string = "sendable: this is TaskpoolTestClass ";
  taskNum: number = 5;
  printName() {
    console.info("sendable: TaskpoolTestClass desc is: " + this.desc);
  }
  get getTaskNum(): number {
    return this.taskNum;
  }
}
```
