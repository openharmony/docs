# $$语法：内置组件双向同步


$$运算符为系统内置组件提供TS变量的引用，使得TS变量和系统内置组件的内部状态保持同步。


内部状态具体指什么取决于组件。例如，[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)组件的text参数。


> **说明：**
>
> $$还用于[@Builder装饰器的按引用传递参数](arkts-builder.md#按引用传递参数)，开发者需要注意两种用法的区别。


## 使用规则

- 当前$$支持基础类型变量，以及[\@State](arkts-state.md)、[\@Link](arkts-link.md)和[\@Prop](arkts-prop.md)装饰的变量。

- 当前$$支持的组件：

  | 组件                                                         | 支持的参数/属性 | 起始API版本 |
  | ------------------------------------------------------------ | --------------- | ----------- |
  | [Checkbox](../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md) | select          | 10          |
  | [CheckboxGroup](../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md) | selectAll       | 10          |
  | [DatePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-datepicker.md) | selected        | 10          |
  | [TimePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md) | selected        | 10          |
  | [MenuItem](../reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md) | selected        | 10          |
  | [Panel](../reference/apis-arkui/arkui-ts/ts-container-panel.md)         | mode            | 10          |
  | [Radio](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md)  | checked         | 10          |
  | [Rating](../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md) | rating          | 10          |
  | [Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md) | value           | 10          |
  | [SideBarContainer](../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md) | showSideBar     | 10          |
  | [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md) | value           | 10          |
  | [Stepper](../reference/apis-arkui/arkui-ts/ts-basic-components-stepper.md) | index           | 10          |
  | [Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md)       | index       | 10          |
  | [Tabs](../reference/apis-arkui/arkui-ts/ts-container-tabs.md)           | index           | 10          |
  | [TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md) | text            | 10          |
  | [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md) | text            | 10          |
  | [TextPicker](../reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md) | selected、value | 10          |
  | [Toggle](../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md) | isOn            | 10          |
  | [AlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md) | selected        | 10          |
  | [Select](../reference/apis-arkui/arkui-ts/ts-basic-components-select.md) | selected、value | 10          |
  | [BindSheet](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md) | isShow | 10          |
  | [BindContentCover](../reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md) | isShow | 10          |
  | [Refresh](../reference/apis-arkui/arkui-ts/ts-container-refresh.md) | refreshing | 8 |
  | [GridItem](../reference/apis-arkui/arkui-ts/ts-container-griditem.md) | selected | 10 |
  | [ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md) | selected | 10 |

- $$绑定的变量变化时，会触发UI的同步刷新。


## 使用示例

以[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)方法的text参数为例：


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
