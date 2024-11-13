# \@Track Decorator: Class Object Property-level Update


\@Track is a decorator used to decorate properties of class objects. When a property decorated by \@Track changes, only the UI associated with the property is updated.


> **NOTE**
>
> Since API version 11, this decorator is supported in ArkTS widgets.


## Overview

\@Track enables property-level UI updates. When a property of a class object is decorated by \@Track, changes to the property will trigger only updates to the UI associated with the property. Properties not decorated by \@Track cannot be used in the UI.


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

Using the @Track decorator can avoid redundant re-renders.

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
        Text(this.logTrack.str1) // UINode1
          .fontSize(this.isRender(1))
          .fontWeight(FontWeight.Bold)
        Text(this.logTrack.str2) // UINode2
          .fontSize(this.isRender(2))
          .fontWeight(FontWeight.Bold)
        Button('change logTrack.str1')
          .onClick(() => {
            this.logTrack.str1 = 'Bye';
          })
        Text(this.logNotTrack.str1) // UINode3
          .fontSize(this.isRender(3))
          .fontWeight(FontWeight.Bold)
        Text(this.logNotTrack.str2) // UINode4
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

1. All attributes in the **LogTrack** class are decorated by @Track. After the **change logTrack.str1** button is clicked, **UINode1** is re-rendered, but **UINode2** is not, as indicated by that only one log record is generated.
```ts
Text 1 is rendered
```

2. None of the attributes in the **logNotTrack** class is decorated by @Track. After the **change logTrack.str1** button is clicked, both **UINode3** and **UINode4** are re-rendered, as indicated by that two log records are generated. Redundant re-renders occur.
```ts
Text 3 is rendered
Text 4 is rendered
```

## Constraints

- Properties that are not decorated by \@Track cannot be used in the UI, which means that such properties cannot be bound to components or be used to initialize child components. Incorrect use will cause JavaScript crashes. Yet, these properties can be used in non-UI cases, such as event callback functions and lifecycle functions.

- Whenever possible, avoid any combination of class objects that contain \@Track and those that do not in, for example, union types and class inheritance.


## Usage Scenarios

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
            // The properties without @Track can be used in the event handler.
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
