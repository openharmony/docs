# !! Syntax: Two-Way Binding
In state management V1, [$$](./arkts-two-way-sync.md) is used for two-way binding of built-in components.
In state management V2, the **!!** syntactic sugar is used to implement two-way binding of components in a unified manner.


>**NOTE**
>
>The **!!** syntax is supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.

## Overview

**!!** is a syntactic sugar used to implement two-way binding of components in initialization of \@Param and \@Event of the child components. The \@Event method name must be declared as "$" + \@Param attribute name. For details, see [Use Scenarios](#use-scenarios).

- If the parent component uses **!!**, the change of the parent component will be synchronized to the child component, and vice versa.
- If the parent component does not use **!!**, the change of the parent component is unidirectional.


## Constraints
**!!** does not support multi-layer parent-child component transfer.


## Use Scenarios

### Two-Way Binding Between Custom Components
1. Construct the **Star** child component in the **Index** component, bind the value in the parent and child components bidirectionally, and initialize **@Param value** and **@Event $value** of the child component.
- The two-way binding syntactic sugar can be considered as:

    ```
    Star({ value: this.value, $value: (val: number) => { this.value = val }})
    ```
2. Click the button in the **Index** component to change the value, and **Text** in both the parent component **Index** and child component **Star** will be updated.
3. Click the button in the child component **Star** to invoke **this.$value(10)**, and **Text** in both the parent component **Index** and child component **Star** will be updated.

```ts
@Entry
@ComponentV2
struct Index {
  @Local value: number = 0;

  build() {
    Column() {
      Text(`${this.value}`)
      Button(`change value`).onClick(() => {
        this.value++;
      })
      Star({ value: this.value!! })
    }
  }
}


@ComponentV2
struct Star {
  @Param value: number = 0;
  @Event $value: (val: number) => void = (val: number) => {};

  build() {
    Column() {
      Text(`${this.value}`)
      Button(`change value `).onClick(() => {
        this.$value(10);
      })
    }
  }
}
```
