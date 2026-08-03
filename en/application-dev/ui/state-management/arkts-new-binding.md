# !! Syntax: Enabling Two-Way Binding
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Cuecuexiaoyu-->
<!--Designer: @VictorS67-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:05:09.774Z pushedAt=2026-07-24T01:13:46.492Z -->

In state management V1, [$$](./arkts-two-way-sync.md) is recommended for implementing two-way binding for built-in components.

In state management V2, the **!!** syntax is recommended for unified two-way binding handling.

>**NOTE**
>
>The **!!** syntax is supported since API version 12.
>

## Overview

The `!!` two-way binding syntax is a syntactic sugar that facilitates two-way data binding for developers. It is used to initialize properties decorated by [\@Param](arkts-new-param.md) and events decorated by [\@Event](arkts-new-event.md) in child components. The \@Event method name must be declared as "$" + the \@Param property name. For details, see [Use Scenarios](#use-scenarios).

- When **!!** is used, changes in the parent component are synchronized to the child component, and vice versa, achieving two-way synchronization.
- If **!!** is not used, changes flow only from the parent to the child, which means one-way synchronization.

## Use Scenarios

### Two-Way Binding Between Custom Components
1. In the **Index** component, construct a child **Star** component and use **!!** to enable two-way binding for the **value** attribute. This automatically initializes the child component's **@Param value** and **@Event $value**.

   Two-way binding syntax sugar used with the @Param and @Event decorators.

   <!-- @[ArkUI_Star_binding1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUI_Binding/entry/src/main/ets/pages/Binding_Star_Param_Event.ets) -->  

   ``` TypeScript
   Star({ value: this.value, $value: (val: number) => { this.value = val; } })
   ```
   The preceding syntax can be simplified as the **!!** syntactic sugar:

    <!-- @[ArkUI_Star_binding3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUI_Binding/entry/src/main/ets/pages/Binding_Star.ets) -->

    ``` TypeScript
    Star({ value: this.value!! })
    ```

2. Use the **@Param value** and **@Event $value** syntax to implement two-way binding of customized components.

    <!-- @[ArkUI_Star_binding4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUI_Binding/entry/src/main/ets/pages/Binding_Star_Param_Event.ets) -->  

    ``` TypeScript
    @Entry
    @ComponentV2
    struct Index {
      @Local value: number = 0;
    
      build() {
        Column() {
          Text(`${this.value}`)
          // Click the Button in Index to change the value. The Text components in the parent component Index and child component Star are synchronously updated.
          Button(`change value in parent component`).onClick(() => {
            this.value++;
          })
          // Use the @Param and @Event syntax to implement two-way binding of customized components.
          Star({ value: this.value, $value: (val: number) => { this.value = val; } })
          // ...
        // ···
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
          // Click the Button in the child component Star to call the `this.$value(10)` method. The Text components in the parent component Index and child component Star are synchronously updated.
          Button(`change value in child component`).onClick(() => {
            this.$value(10);
          })
        }
      }
    }
    ```

3. Use the **!!** syntax sugar to implement two-way binding of custom components.

   <!-- @[ArkUI_Star_binding2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUI_Binding/entry/src/main/ets/pages/Binding_Star.ets) -->

   ``` TypeScript
   @Entry
   @ComponentV2
   struct Index {
     @Local value: number = 0;
   
     build() {
       Column() {
         Text(`${this.value}`)
         // Clicking the button in Index (parent) increments the value of value, and the Text components in both Index and Star (child) are updated.
         Button(`change value in parent component`).onClick(() => {
           this.value++;
         })
         // Use the !! syntax sugar to implement two-way binding of custom components.
         Star({ value: this.value!! })
         // ...
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
         // Clicking the button in Star (child) calls this.$value(10), and the Text components in both Index and Star are updated.
         Button(`change value in child component`).onClick(() => {
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

The meaning of the internal state is determined by the component or attribute. For example, the `isShow` parameter of the [bindMenu](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11) attribute.

<!-- @[ArkUI_Sys_binding](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUI_Binding/entry/src/main/ets/pages/Sys_Binding.ets) -->

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = 'click show Menu';
const DOMAIN = 0xFF00;

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
                  hilog.info(DOMAIN, TAG, 'handle Menu1 click');
                }
              },
              {
                value: 'Menu2',
                action: () => {
                  hilog.info(DOMAIN, TAG, 'handle Menu2 click');
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

**Rules of Use**

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
  | [SideBarContainer](../../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md) | [sideBarWidth](../../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md#sidebarwidth) | 18   |
  | [Navigation](../../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md) | [navBarWidth](../../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#navbarwidth9) | 18   |
  | [Toggle](../../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md#toggleoptions18) | isOn | 18   |
  | [Checkbox](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md) | [select](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md#select) | 18   |
  | [CheckboxGroup](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md) | [selectAll](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md#selectall) | 18   |
  | [Radio](../../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md) | [checked](../../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md#checked) | 18   |
  | [Rating](../../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md#ratingoptions18) | rating | 18   |
  | [Slider](../../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md#slideroptions) | value | 18   |
  | [Select](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md) | [selected](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md#selected) | 18   |
  | Select | [value](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md#value) | 18   |
  | [MenuItem](../../reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md) | [selected](../../reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md#selected) | 18   |