# !! Syntax: Enabling Two-Way Binding
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Cuecuexiaoyu-->
<!--Designer: @lixingchi1-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

In state management V1, two-way binding for built-in components is implemented using [$$](./arkts-two-way-sync.md).
In state management V2, the **!!** syntactic sugar provides a unified way to achieve two-way binding for components.

>**NOTE**
>
>The **!!** syntax is supported since API version 12.
>

## Overview

The **!!** syntactic sugar enables two-way binding for components by initializing the [\@Param](arkts-new-param.md) and [\@Event](arkts-new-event.md) decorated variables of child components. For this to work, the \@Event decorated method name must be declared as **$** + the name of the \@Param decorated attribute. For details, see [Use Scenarios](#use-scenarios).

- When **!!** is used, changes in the parent component are synchronized to the child component, and vice versa, achieving two-way synchronization.
- If **!!** is not used, changes flow only from the parent to the child, which means one-way synchronization.

## Use Scenarios

### Two-Way Binding Between Custom Components
1. In the **Index** component, construct a child **Star** component and use **!!** to enable two-way binding for the **value** attribute. This automatically initializes the child component's **@Param value** and **@Event $value**.

   **!!** syntactic sugar for two-way binding:

   ```
   Star({ value: this.value, $value: (val: number) => { this.value = val; }})
   ```
2. Clicking the button in **Index** (parent) increments the value of **value**, and the **Text** components in both **Index** and **Star** (child) are updated.
3. Clicking the button in **Star** (child) calls **this.$value(10)**, and the **Text** components in both **Index** and **Star** are updated.

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
         Button(`change value`).onClick(() => {
           this.$value(10);
         })
       }
     }
   }
   ```

**Constraints**
- **!!** does not support two-way binding across multiple layers of parent-child components.
- **!!** cannot be used together with \@Event. Since API version 18, using **!!** to pass parameters to a child component's @Event method causes a compilation error.
- Using three or more exclamation marks (such as **!!!** and **!!!!**) does not enable two-way binding.


### Two-Way Binding Between Built-in Component Parameters

The **!!** operator passes a TypeScript variable by reference to a built-in component, ensuring the variable's value and the component's internal state stay in sync. To use this operator, append it to the variable name, for example, **isShow!!**.

The specific meaning of the "internal state" is determined by the component implementation. For example, the **isShow** parameter in [bindMenu](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11) controls menu visibility.

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
      Text('isShow: ' + this.isShow).fontSize(18).fontColor(Color.Red)
      Row() {
        Button('Click')
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

**Usage Rules**

- Currently, two-way binding with **!!** supports variables of basic types. When such variables are decorated with state management V1 decorators such as [\@State](arkts-state.md), or state management V2 decorators such as [\@Local](arkts-new-local.md), changes in variable values will trigger UI updates.

  | Attribute                                                        | Supported Parameter| Initial API Version|
  | ------------------------------------------------------------ | --------------- | ----------- |
  | [bindMenu](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11) | isShow | 18        |
  | [bindContextMenu](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu12) | isShown | 18          |
  | [bindPopup](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#bindpopup) | show | 18   |
  | [TextInput](../../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#textinputoptions) | text | 18   |
  | [TextArea](../../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#textareaoptions) | text | 18   |
  | [Search](../../reference/apis-arkui/arkui-ts/ts-basic-components-search.md#searchoptions18) | value | 18   |
  | [BindSheet](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet) | isShow | 18   |
  | [BindContentCover](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover) | isShow | 18   |
  | [SideBarContainer](../../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md#sidebarwidth) | sideBarWidth | 18   |
  | [Navigation](../../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navbarwidth9) | navBarWidth | 18   |
  | [Toggle](../../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md#toggleoptions18) | isOn | 18   |
  | [Checkbox](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md#select) | select | 18   |
  | [CheckboxGroup](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md#selectall) | selectAll | 18   |  
  | [Radio](../../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md#checked) | checked | 18   |  
  | [Rating](../../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md#ratingoptions18) | rating | 18   |  
  | [Slider](../../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md#slideroptions) | value | 18   |  
  | [Select](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md#selected) | selected | 18   |  
  | [Select](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md#value) | value | 18   |
  | [MenuItem](../../reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md#selected) | selected | 18   |
