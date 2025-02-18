# \@Track Decorator: Class Object Property-level Update


\@Track is a decorator used to decorate properties of class objects. Any changes to the properties decorated by \@Track will trigger only updates to the UI associated with those properties.


Before reading this topic, you are advised to read [\@State](./arkts-state.md) to have a basic understanding of the observation capabilities of state management.

> **NOTE**
>
> This decorator is supported in ArkTS widgets since API version 11.


## Overview

\@Track enables property-level update for the class object. When a class object is a state variable, the change of the \@Track decorated property triggers only the update of the property associated UI. If the class uses the \@Track decorator, the properties that are not decorated by \@Track cannot be used in the UI. Otherwise, a runtime error is reported.


## Decorator Description

| \@Track Decorator | Description                 |
| ------------------ | -------------------- |
| Decorator parameters  | None.|
| Allowed variable types| Non-static properties of class objects.|

## Observed Changes and Behavior

When a class object is a state variable, any changes to its properties decorated by \@Track will trigger only updates to the UI associated with those properties.

> **NOTE**
>
> When no property in the class object is decorated with \@Track, the behavior remains unchanged. \@Track is unable to observe changes of nested objects.

Using the @Track decorator can avoid redundant updates.

```ts
class LogTrack {
  @Track str1: string;
  @Track str2: string;

  constructor(str1: string) {
    this.str1 = str1;
    this.str2 = 'World';
  }
}

class LogNotTrack {
  str1: string;
  str2: string;

  constructor(str1: string) {
    this.str1 = str1;
    this.str2 = 'World';
  }
}

@Entry
@Component
struct AddLog {
  @State logTrack: LogTrack = new LogTrack('Hello');
  @State logNotTrack: LogNotTrack = new LogNotTrack('Hello');

  isRender(index: number) {
    console.log(`Text ${index} is rendered`);
    return 50;
  }

  build() {
    Row() {
      Column() {
        Text(this.logTrack.str1) // Text1
          .fontSize(this.isRender(1))
          .fontWeight(FontWeight.Bold)
        Text(this.logTrack.str2) // Text2
          .fontSize(this.isRender(2))
          .fontWeight(FontWeight.Bold)
        Button('change logTrack.str1')
          .onClick(() => {
            this.logTrack.str1 = 'Bye';
          })
        Text(this.logNotTrack.str1) // Text3
          .fontSize(this.isRender(3))
          .fontWeight(FontWeight.Bold)
        Text(this.logNotTrack.str2) // Text4
          .fontSize(this.isRender(4))
          .fontWeight(FontWeight.Bold)
        Button('change logNotTrack.str1')
          .onClick(() => {
            this.logNotTrack.str1 = 'Goodbye';
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

In the preceding example:

1. All properties in the **LogTrack** class are decorated by \@Track. After the **change logTrack.str1** button is clicked, **Text1** is updated, but **Text2** is not, as indicated by that only one log record is generated.
    ```ts
    Text 1 is rendered
    ```

2. None of the properties in the **logNotTrack** class is decorated by \@Track. After the **change logTrack.str1** button is clicked, both **Text3** and **Text4** are updated, as indicated by that two log records are generated. Redundant updates occur.
    ```ts
    Text 3 is rendered
    Text 4 is rendered
    ```

## Constraints

- If the \@Track decorator is used in a class, the non-\@Track decorated properties in the class cannot be used in the UI. For example, these properties cannot be bound to components nor be used to initialize child components; otherwise, an error is reported during runtime. For details, see [Improperly Using Non-\@Track Decorated Properties Causes Errors](#improperly-using-non-track-decorated-properties-causes-errors). Non-\@Track decorated properties can be used in non-UI functions, such as event callback functions and lifecycle functions.

- Whenever possible, avoid any combination of class objects that contain \@Track and those that do not in, for example, union types and class inheritance.


## Use Scenarios

### \@Track and Custom Component Updates

This example is used to clarify the processing steps of custom component updates and \@Track. The **log** object is a state variable decorated by \@State. Its **logInfo** property is decorated by \@Track, but other properties are not, and the values of these other properties are not updated through the UI.


```ts
class Log {
  @Track logInfo: string;
  owner: string;
  id: number;
  time: Date;
  location: string;
  reason: string;

  constructor(logInfo: string) {
    this.logInfo = logInfo;
    this.owner = 'OH';
    this.id = 0;
    this.time = new Date();
    this.location = 'CN';
    this.reason = 'NULL';
  }
}

@Entry
@Component
struct AddLog {
  @State log: Log = new Log('origin info.');

  build() {
    Row() {
      Column() {
        Text(this.log.logInfo)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // Properties that are not decorated by @Track can be used in click events.
            console.log('owner: ' + this.log.owner +
              ' id: ' + this.log.id +
              ' time: ' + this.log.time +
              ' location: ' + this.log.location +
              ' reason: ' + this.log.reason);
            this.log.time = new Date();
            this.log.id++;

            this.log.logInfo += ' info.';
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

Processing steps:

1. The click event **Text.onClick** of the **AddLog** custom component increases the value of **info**.

2. In response to the change of the \@State decorated variable **log**, the \@Track decorated property **logInfo** is updated, and the **Text** component is re-rendered.

## FAQs

### Improperly Using Non-\@Track Decorated Properties Causes Errors

If a property that is not decorated by \@Track is used in the UI, an error is reported during runtime.

```ts
class Person {
  // id is decorated by @Track.
  @Track id: number;
  // age is not decorated by @Track.
  age: number;

  constructor(id: number, age: number) {
    this.id = id;
    this.age = age;
  }
}

@Entry
@Component
struct Parent {
  @State parent: Person = new Person(2, 30);

  build() {
    // Property that is not decorated by @Track cannot be used in the UI. Otherwise, an error is reported during runtime.
    Text(`Parent id is: ${this.parent.id} and Parent age is: ${this.parent.age}`)
  }
}
```
