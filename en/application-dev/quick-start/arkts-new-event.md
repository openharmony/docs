# \@Event Decorator: Component Output

You can use \@Event, a variable decorator in state management V2, to enable a child component to require the parent component to update the \@Param decorated variables.

>**NOTE**
>
>The \@Event decorator is supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.

## Overview

The variables decorated by \@Param cannot be changed locally. You can use the \@Event decorator to decorate a callback, which is called to change the variables of the data source. You can synchronize the changes to \@Param by using the synchronization mechanism of \@Local. In this way, the variables decorated by \@Param can be updated actively.

When using \@Event to decorate a component:

- You need to determine the parameters and return value in the callback decorated by \@Event.

- Variables of non-callback types decorated by \@Event do not take effect. If \@Event is not initialized, an empty function will be automatically generated as the default callback.
- If \@Event is not initialized externally but has a default value, the default function will be used for processing.

\@Param indicates the input of a component, and this variable is affected by the parent component. \@Event indicates the output of a component, and the output method affects the parent component. Decorating a callback with \@Event indicates that the callback is the output of the custom component. The parent component needs to determine whether to provide the corresponding method for the child component to change the data source of the \@Param variable.

## Decorator Description

| \@Event Decorator| Description|
| ------------------- | ------------------------------------------------------------ |
| Decorator parameters| None.|
| Allowed variable types| Callback, such as **()=>void** and **(x:number)=>boolean**. You can determine the return value and whether the callback contains parameters.|
| Allowed function types| Arrow function.|

## Constraints

- \@Event can be used only in custom components decorated by \@ComponentV2. \@Event does not take effect if the decorated variable is not a function.

  ```ts
  @ComponentV2
  struct Index {
    @Event changeFactory: ()=>void = ()=>{}; // Correct usage.
    @Event message: string = "abcd"; // Incorrect usage. The variable decorated is not a function.
  }
  @Component
  struct CompA {
    @Event changeFactory: ()=>void = ()=>{}; // Incorrect usage.
  }
  ```


## Use Scenarios

### Changing Variables in the Parent Component

You can use \@Event to change a variable in the parent component. When the variable is used as the data source of the \@Param variable in the child component, this change will be synchronized accordingly.

```ts
@Entry
@ComponentV2
struct Index {
  @Local title: string = "Titile One";
  @Local fontColor: Color = Color.Red;

  build() {
    Column() {
      Child({
        title: this.title,
        fontColor: this.fontColor,
        changeFactory: (type: number) => {
          if (type == 1) {
            this.title = "Title One";
            this.fontColor = Color.Red;
          } else if (type == 2) {
            this.title = "Title Two";
            this.fontColor = Color.Green;
          }
        }
      })
    }
  }
}

@ComponentV2
struct Child {
  @Param title: string = '';
  @Param fontColor: Color = Color.Black;
  @Event changeFactory: (x: number) => void = (x: number) => {};

  build() {
    Column() {
      Text(`${this.title}`)
      Button("change to Title Two")
        .onClick(() => {
          this.changeFactory(2)
        })
      Button("change to Title One")
        .onClick(() => {
          this.changeFactory(1)
        })
    }
  }
}
````
