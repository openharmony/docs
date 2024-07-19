# \@Once: Implementing Initialization Once


To initialize data only once and deny subsequent changes, you can use \@Once decorator together with \@Param decorator.


> **NOTE**
>
> The \@Once decorator is supported in custom components decorated by \@ComponentV2 since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.



## Overview

The \@Once decorator accepts values passed in only during variable initialization. When the data source changes, the decorator does not synchronize the changes to child components:

- \@Once must be used with \@Param. Using it independently or with other decorators is not allowed.
- \@Once does not affect the observation capability of \@Param. Only changes in data source are intercepted.
- The sequence of the variables decorated by \@Once and \@Param does not affect the actual features.
- When \@Once and \@Param are used together, you can change the value of \@Param variables locally.

## Rules of Use

As an auxiliary decorator, the \@Once decorator does not have requirements on the decoration type and the capability of observing variables.

| \@Once Variable Decorator| Description                                     |
| ---------------- | ----------------------------------------- |
| Decorator parameters      | None.                                     |
| Condition        | It cannot be used independently and must be used together with the \@Param decorator.|


## Constraints

- \@Once can be used only in custom components decorated by \@ComponentV2 and can be used only with \@Param.

  ```ts
  @ComponentV2
  struct CompA {
    @Param @Once onceParam: string = "onceParam"; // Correct usage.
    @Once onceStr: string = "Once"; // Incorrect usage. @Once cannot be used independently.
    @Local @Once onceLocal: string = "onceLocal"; // Incorrect usage. @Once cannot be used with @Local.
  }
  @Component
  struct Index {
    @Once @Param onceParam: string = "onceParam"; // Incorrect usage.
  }
  ```

- The order of \@Once and \@Param does not matter. Both \@Param \@Once and \@Once \@Param are correct.

  ```ts
  @ComponentV2
  struct CompA {
    @Param @Once param1: number;
    @Once @Param param2: number;
  }
  ```

## Use Scenarios

### Initializing Variables Only Once

\@Once is used in the scenario where the expected variables synchronize the data source once during initialization and then stop synchronizing the subsequent changes.

```ts
@ComponentV2
struct CompA {
  @Param @Once onceParam: string = '';
  build() {
  	Column() {
  	  Text(`onceParam: ${this.onceParam}`)
  	}
  }
}
@Entry
@ComponentV2
struct CompB {
  @Local message: string = "Hello World";
  build() {
  	Column() {
      Text(`Parent message: ${this.message}`)
      Button("change message")
        .onClick(() => {
          this.message = "Hello Tomorrow";
        })
      CompA({ onceParam: this.message })
  	}
  }
}
```

### Changing the \@Param Variables Locally

When \@Once is used together with \@Param, the constraint that \@Param cannot be changed locally can be removed, and this change triggers UI re-rendering. In this case, using \@Param and \@Once is equivalent to using \@Local. The difference is that \@Param and \@Once can accept the external initialization passed in.

```ts
@ObservedV2
class Info {
  @Trace name: string;
  constructor(name: string) {
    this.name = name;
  }
}
@ComponentV2
struct Child {
  @Param @Once onceParamNum: number = 0;
  @Param @Once @Require onceParamInfo: Info;

  build() {
    Column() {
      Text(`Child onceParamNum: ${this.onceParamNum}`)
      Text(`Child onceParamInfo: ${this.onceParamInfo.name}`)
      Button("changeOnceParamNum")
        .onClick(() => {
          this.onceParamNum++;
        })
      Button("changeParamInfo")
        .onClick(() => {
          this.onceParamInfo = new Info("Cindy");
        })
    }
  }
}
@Entry
@ComponentV2
struct Index {
  @Local localNum: number = 10;
  @Local localInfo: Info = new Info("Tom");

  build() {
    Column() {
      Text(`Parent localNum: ${this.localNum}`)
      Text(`Parent localInfo: ${this.localInfo.name}`)
      Button("changeLocalNum")
        .onClick(() => {
          this.localNum++;
        })
      Button("changeLocalInfo")
        .onClick(() => {
          this.localInfo = new Info("Cindy");
        })
      Child({
        onceParamNum: this.localNum,
        onceParamInfo: this.localInfo
      })
    }
  }
}
```
