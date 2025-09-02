# $$ Syntax: Implementing Two-Way Synchronization for Built-in Components
<!--Kit: ArkUI--> 
<!--Subsystem: ArkUI--> 
<!--Owner: @Cuecuexiaoyu--> 
<!--Designer: @lixingchi1--> 
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

The **$$** operator provides a TypeScript variable by-reference to a built-in component so that the variable's value and the component's internal state are kept in sync.


The specific meaning of "internal state" varies by component. For example, for the [TextInput](../../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md) component, it refers to the **text** parameter.


## Usage Rules

- Currently, **$$* supports variables of basic types. When such variables are decorated with state management V1 decorators such as [\@State](arkts-state.md), [\@Link](arkts-link.md), [\@Prop](arkts-prop.md), and [\@Provide](arkts-provide-and-consume.md), or state management V2 decorators such as [\@Local](arkts-new-local.md), changes in variable values will trigger UI updates.

- Components supported by **$$** are listed below.

  | Component                                                        | Parameter/Attribute| Initial API Version|
  | ------------------------------------------------------------ | --------------- | ----------- |
  | [Checkbox](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md) | select          | 10          |
  | [CheckboxGroup](../../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md) | selectAll       | 10          |
  | [DatePicker](../../reference/apis-arkui/arkui-ts/ts-basic-components-datepicker.md) | selected        | 10          |
  | [TimePicker](../../reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md) | selected        | 10          |
  | [MenuItem](../../reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md) | selected        | 10          |
  | [Panel](../../reference/apis-arkui/arkui-ts/ts-container-panel.md)         | mode            | 10          |
  | [Radio](../../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md)  | checked         | 10          |
  | [Rating](../../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md) | rating          | 10          |
  | [Search](../../reference/apis-arkui/arkui-ts/ts-basic-components-search.md) | value           | 10          |
  | [SideBarContainer](../../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md) | showSideBar     | 10          |
  | [Slider](../../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md) | value           | 10          |
  | [Stepper](../../reference/apis-arkui/arkui-ts/ts-basic-components-stepper.md) | index           | 10          |
  | [Swiper](../../reference/apis-arkui/arkui-ts/ts-container-swiper.md)       | index       | 10          |
  | [Tabs](../../reference/apis-arkui/arkui-ts/ts-container-tabs.md)           | index           | 10          |
  | [TextArea](../../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md) | text            | 10          |
  | [TextInput](../../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md) | text            | 10          |
  | [TextPicker](../../reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md) | selected, value| 10          |
  | [Toggle](../../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md) | isOn            | 10          |
  | [AlphabetIndexer](../../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md) | selected        | 10          |
  | [Select](../../reference/apis-arkui/arkui-ts/ts-basic-components-select.md) | selected, value| 10          |
  | [BindSheet](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet) | isShow | 10          |
  | [BindContentCover](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover) | isShow | 10          |
  | [Refresh](../../reference/apis-arkui/arkui-ts/ts-container-refresh.md) | refreshing | 8 |
  | [GridItem](../../reference/apis-arkui/arkui-ts/ts-container-griditem.md) | selected | 10 |
  | [ListItem](../../reference/apis-arkui/arkui-ts/ts-container-listitem.md) | selected | 10 |

- When a variable bound using **$$** changes, it triggers synchronous UI re-rendering.


## Example

This example demonstrates two-way data binding using the **$$** operator with the **text** parameter of the [TextInput](../../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md) component.


```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = ''
  controller: TextInputController = new TextInputController()

  build() {
    Column({ space: 20 }) {
      Text(this.text)
      TextInput({ text: $$this.text, placeholder: 'input your word...', controller: this.controller })
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .caretColor(Color.Blue)
        .width(300)
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)
  }
}
```


![TextInputDouble](figures/TextInputDouble.gif)
