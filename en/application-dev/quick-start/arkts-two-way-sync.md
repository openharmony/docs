# $$ Syntax: Two-Way Synchronization of Built-in Components


The $$ operator provides a TS variable by-reference to a built-in component so that the variable value and the internal state of that component are kept in sync.


What the internal state is depends on the component. For example, for the [bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md) attribute method, it is the **show** parameter.


## Rules of Use

- $$ supports variables of simple types and variables decorated by **\@State**, **\@Link**, or **\@Prop**.

- $$ supports the components listed below.

  | Component                                                        | Supported Parameter/Attribute| Initial API Version|
  | ------------------------------------------------------------ | --------------- | ----------- |
  | [Checkbox](../reference/arkui-ts/ts-basic-components-checkbox.md) | select          | 10          |
  | [CheckboxGroup](../reference/arkui-ts/ts-basic-components-checkboxgroup.md) | selectAll       | 10          |
  | [DatePicker](../reference/arkui-ts/ts-basic-components-datepicker.md) | selected        | 10          |
  | [TimePicker](../reference/arkui-ts/ts-basic-components-timepicker.md) | selected        | 10          |
  | [MenuItem](../reference/arkui-ts/ts-basic-components-menuitem.md) | selected        | 10          |
  | [Panel](../reference/arkui-ts/ts-container-panel.md)         | mode            | 10          |
  | [Radio](../reference/arkui-ts/ts-basic-components-radio.md)  | checked         | 10          |
  | [Rating](../reference/arkui-ts/ts-basic-components-rating.md) | rating          | 10          |
  | [Search](../reference/arkui-ts/ts-basic-components-search.md) | value           | 10          |
  | [SideBarContainer](../reference/arkui-ts/ts-container-sidebarcontainer.md) | showSideBar     | 10          |
  | [Slider](../reference/arkui-ts/ts-basic-components-slider.md) | value           | 10          |
  | [Stepper](../reference/arkui-ts/ts-basic-components-stepper.md) | index           | 10          |
  | [Swiper](../reference/arkui-ts/ts-container-swiper.md)       | index       | 10          |
  | [Tabs](../reference/arkui-ts/ts-container-tabs.md)           | index           | 10          |
  | [TextArea](../reference/arkui-ts/ts-basic-components-textarea.md) | text            | 10          |
  | [TextInput](../reference/arkui-ts/ts-basic-components-textinput.md) | text            | 10          |
  | [TextPicker](../reference/arkui-ts/ts-basic-components-textpicker.md) | selected, value| 10          |
  | [Toggle](../reference/arkui-ts/ts-basic-components-toggle.md) | isOn            | 10          |
  | [AlphabetIndexer](../reference/arkui-ts/ts-container-alphabet-indexer.md) | selected        | 10          |
  | [Select](../reference/arkui-ts/ts-basic-components-select.md) | selected, value| 10          |
  | [BindSheet](../reference/arkui-ts/ts-universal-attributes-sheet-transition.md) | isShow | 10          |
  | [BindContentCover](../reference/arkui-ts/ts-universal-attributes-modal-transition.md) | isShow | 10          |
  | [bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md) | show | 8 |
  | [Refresh](../reference/arkui-ts/ts-container-refresh.md) | refreshing | 8 |

- When the variable bound to $$ changes, the UI is re-rendered synchronously.


## Example

This example uses the **text** parameter of the [\<TextInput>](../reference/arkui-ts/ts-basic-components-textinput.md) component.


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
