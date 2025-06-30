# !! Syntax: Two-Way Binding
In state management V1, [$$](./arkts-two-way-sync.md) is used for two-way binding of built-in components.
In state management V2, the **!!** syntactic sugar is used to implement two-way binding of components in a unified manner.


>**NOTE**
>
>The **!!** syntax is supported since API version 12.
>

## Overview

**!!** is a syntactic sugar used to implement two-way binding of components in initialization of \@Param and \@Event of the child components. The \@Event method name must be declared as "$" + \@Param attribute name. For details, see [Use Scenarios](#use-scenarios).

- If the parent component uses **!!**, the change of the parent component will be synchronized to the child component, and vice versa.
- If the parent component does not use **!!**, the change of the parent component is unidirectional.


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


## Constraints
- **!!** does not support multi-layer parent-child component transfer.
- **!!** cannot be used together with @Event. Since API version 18, when **!!** is used to pass parameters to the @Event method of a child component, a compilation error is reported.
- When three or more exclamation marks (!!!, !!!!, or !!!!!) are used, two-way binding is not supported.


### Two-Way Binding Between Built-in Component Parameters

The **!!** operator provides a TypeScript variable by-reference to a built-in component so that the variable value and the internal state of that component are kept in sync. Add this operator after the variable name, for example, **isShow!!**.

What the internal state is depends on the component. For example, the **isShow** parameter of the [bindMenu](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md) component.

#### Rules of Use

- Currently, **!!** supports two-way binding of the following parameters of the basic types, that is, the parameters can synchronize the current menu or popup state. In addition, **!!** supports two-way binding of variables of the basic types as well. When a variable is decorated by [\@Local](arkts-new-local.md) of V2 or [\@State](arkts-state.md) of V1, the change of the variable value triggers the UI re-render.

  | Attribute                                                        | Supported Parameter| Initial API Version|
  | ------------------------------------------------------------ | --------------- | ----------- |
  | [bindMenu](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11) | isShow | 13          |
  | [bindContextMenu](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu12) | isShown | 13          |
  | [bindPopup](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#bindpopup) | show | 13   |
  | [TextInput](../../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#textinputoptions)| text | 18   |
  | [TextArea](../../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#textareaoptions)| text | 18   |
  | [Search](../../reference/apis-arkui/arkui-ts/ts-basic-components-search.md#searchoptions18)| value | 18   |
  | [BindSheet](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md) | isShow | 18   |
  | [BindContentCover](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md) | isShow | 18   |
  | [Toggle](../../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md#toggleoptions18)| isOn | 18   |
  | [Checkbox](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md#select) | select | 18   |
  | [CheckboxGroup](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md#selectall) | selectAll | 18   |  
  | [Radio](../../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md#checked) | checked | 18   |  
  | [Rating](../../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md#ratingoptions18)| rating | 18   |  
  | [Slider](../../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md#slideroptions)| value | 18   |  
  | [Select](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md#selected) | selected | 18   |  
  | [Select](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md#value) | value | 18   |
  | [MenuItem](../../reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md#selected) | selected | 18   |
- When the [\@Local](arkts-new-local.md) decorated variable bound to **!!** changes, the UI is rendered synchronously.


#### Example

Two-way binding of the **isShow** parameter of the **bindMenu** API:

```ts
@Entry
@ComponentV2
struct BindMenuInterface {
  @Local isShow: boolean = false;

  build() {
    Column() {
      Row() {
        Text('click show Menu')
          .bindMenu(this.isShow!!, // Two-way binding.
            [
              {
                value: 'Menu1',
                action: () => {
                  console.info('handle Menu1 click');
                }
              },
              {
                value: 'Menu2',
                action: () => {
                  console.info('handle Menu2 click');
                }
              },
            ])
      }.height('50%')
      Text("isShow: " + this.isShow).fontSize(18).fontColor(Color.Red)
      Row() {
        Button("Click")
          .onClick(() => {
            this.isShow = true;
          })
          .width(100)
          .fontSize(20)
          .margin(10)
      }
    }.width('100%')
  }
}
```

![bindMenu](figures/bindmenu_doublebind.gif)
