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


## Constraints

- Properties that are not decorated by \@Track cannot be used in the UI, which means that such properties cannot be bound to components or be used to initialize child components. Incorrect use will cause JavaScript crashes. Yet, these properties can be used in non-UI cases, such as event callback functions and lifecycle functions.

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

2. In response to the change of the \@State decorated variable **log**, the \@Track decorated property **logInfo** is updated, and the **\<Text>** component is re-rendered.
