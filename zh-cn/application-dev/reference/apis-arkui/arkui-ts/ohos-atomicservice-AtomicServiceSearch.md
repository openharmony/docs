# AtomicServiceSearch

AtomicServiceSearch为开发者提供满足定制化需求的功能，内容包括默认显示的搜索区、可自定义的选择区和功能区（最多两个）。各区域的样式、位置和大小均固定。

> **说明：**
>
> 该组件从API version 16开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { AtomicServiceSearch } from '@kit.ArkUI';
```


## AtomicServiceSearch
```ts
AtomicServiceSearch({
  value?: ResourceStr,
  placeholder?: ResourceStr,
  controller?: SearchController,
  select?: SelectParams,
  search?: SearchParams,
  operation?: OperationParams,
})
```

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**装饰器类型**： @Component

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称      | 类型         | 必填 | 装饰器类型 | 说明                                                         |
| ----------- | :--------------- | ---- | ---------- | ------------------------------------------------------------ |
| value       | [ResourceColor](ts-types.md#resourcecolor) | 否 | @Prop | 设置当前显示的搜索文本内容。默认值为空字符串。 |
| placeholder | [ResourceColor](ts-types.md#resourcecolor) | 否 | @Prop | 搜索框内默认显示的提示文本。默认值：Search |
| controller  | [SearchController](ts-basic-components-search.md#searchcontroller) | 否   | - | 原生Search组件控制器，用于设置输入光标的位置、退出编辑态等操作。默认值：undefined |
| select      | [SelectParams](#selectparams) | 否 | @Prop | select选择区的内容、事件及样式。默认值：undefined |
| search      | [SearchParams](#searchparams) | 否 | @Prop | search搜索区可支持的事件及样式。默认值：undefined |
| operation   | [OperationParams](#operationparams) | 否 | - | 选择区（右侧）的功能设置项。默认值：undefined |


## SelectParams

AtomicServiceSearch中“选择区”的初始化参数。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称                    | 类型                   | 必填                         | 说明                                                         |
| ----------------------- | -------------------------------------------- | ------------------------------------------------------------ | ---- |
| options                 | Array&lt;[SelectOption](ts-basic-components-select.md#selectoption对象说明)&gt; | 否 | 下拉选项内容。默认值为undefined。 |
| selected                | number| 否 | 设置下拉菜单初始选项的索引。第一项的索引为0。当不设置selected属性时，默认选择值为-1，菜单项不选中。 |
| selectValue             | [ResourceStr](ts-types.md#resourcestr) | 否 | 设置下拉按钮本身的文本内容。默认值为undefined。 |
| onSelect                | [OnSelectCallback](#onselectcallback) | 否 | 下拉菜单选中某一项的回调。默认值为undefined。 |
| menuItemContentModifier | [ContentModifier&lt;MenuItemConfiguration&gt;](ts-basic-components-select.md#menuitemconfiguration12对象说明) | 否 | 	在Select组件上，定制下拉菜单项内容区的方法。<br/>modifier: 内容修改器，开发者需要自定义class实现ContentModifier接口。 |
| divider                 | [Optional](ts-universal-attributes-custom-property.md#optional12)&lt;[DividerOptions](ts-basic-components-textpicker.md#divideroptions12对象说明)&gt; \| null; | 否 | 1.设置DividerOptions，则按设置的样式显示分割线。<br/>默认值：<br/>{<br/>strokeWidth: '1px' , <br/>color: '#33182431'<br/>}<br/>2.设置为null时，不显示分割线。<br/>3.strokeWidth设置过宽时，会覆盖文字。分割线会从每一个Item底部开始，同时向上向下画分割线。<br/>4.startMargin和endMargin的默认值与不设置divider属性时的分割线样式保持一致。startMargin和endMargin的和与optionWidth的值相等时，不显示分割线。 startMargin和endMargin的和超过optionWidth的值时，按照默认样式显示分割线。 |
| font                    | [Font](ts-types.md#font) | 否 | 下拉按钮本身的文本样式。<br/>API Version 11及以前默认值：<br/>{<br/>size:&nbsp;`$r('sys.float.ohos_id_text_size_button1')`,<br/>weight:&nbsp;FontWeight.Medium<br/>} <br/>API Version 12以后，如果设置controlSize的值为：controlSize.SMALL，size默认值是`$r('sys.float.ohos_id_text_size_button2')`，否则为`$r('sys.float.ohos_id_text_size_button1')`。 |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor) | 否 | 下拉菜单选中项的文本颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_activated')   |
| selectedOptionBgColor   | [ResourceColor](ts-types.md#resourcecolor) | 否 | 下拉菜单选中项的背景色。<br/>默认值：`$r('sys.color.ohos_id_color_component_activated')`混合`$r('sys.color.ohos_id_alpha_highlight_bg')`的透明度。 |
| selectedOptionFont      | [Font](ts-types.md#font) | 否 | 下拉菜单选中项的文本样式。<br/>默认值：<br/>{<br/>size:&nbsp;$r('sys.color.ohos_id_text_size_body1'),<br/>weight:&nbsp;FontWeight.Regular<br/>} |
| selectedOptionFontColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 下拉菜单选中项的文本颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_activated') |
| optionBgColor           | [ResourceColor](ts-types.md#resourcecolor) | 否 | 下拉菜单项的背景色。<br/>默认值：<br/>API version 11之前，默认值为Color.White。<br/>API version 11及之后，默认值为Color.Transparent。 |
| optionFont              | [Font](ts-types.md#font) | 否 | 下拉菜单项的文本样式。<br/>默认值：<br/>{<br/>size:&nbsp;$r('sys.float.ohos_id_text_size_body1'),<br/>weight:&nbsp;FontWeight.Regular<br/>} |
| optionFontColor         | [ResourceColor](ts-types.md#resourcecolor) | 否 | 下拉菜单项的文本颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary') |
| optionWidth             | [Dimension](ts-types.md#dimension10) \| [OptionWidthMode](ts-appendix-enums.md#optionwidthmode11) | 否 | 设置下拉菜单项的宽度，不支持设置百分比。OptionWidthMode类型为枚举类型，OptionWidthMode决定下拉菜单是否继承下拉按钮宽度。当设置为异常值或小于最小宽度56vp时，属性不生效，菜单项宽度设为默认值，即菜单默认宽度为2栅格。 |
| optionHeight            | [Dimension](ts-types.md#dimension10) | 否 | 设置下拉菜单显示的最大高度，不支持设置百分比。下拉菜单的默认最大高度是屏幕可用高度的80%，设置的菜单最大高度不能超过默认最大高度。 |
| space                   | [Length](ts-types.md#length) | 否 | 下拉菜单项的文本与箭头之间的间距。<br/>默认值：8 |
| arrowPosition           | [ArrowPosition](ts-basic-components-select.md#arrowposition10枚举说明) | 否 | 下拉菜单项的文本与箭头之间的对齐方式。<br/>默认值：ArrowPosition.END |
| menuAlign               | [MenuAlignParams](#menualignparams) | 否 | 设置下拉按钮与下拉菜单间的对齐方式。<br/>默认值：{alignType：MenuAlignType.START, <br/> offset: {dx: 0, dy: 0}} |
| menuBackgroundColor     | [ResourceColor](ts-types.md#resourcecolor) | 否 | 下拉菜单的背景色。<br/>默认值：<br/>API version 11之前，默认值为$r('sys.color.ohos_id_color_card_bg')。<br/>API version 11及之后，默认值为Color.Transparent。   |
| menuBackgroundBlurStyle | [BlurStyle](ts-universal-attributes-background.md#blurstyle9) | 否 | 下拉菜单的背景模糊材质。<br/>默认值：BlurStyle.COMPONENT_ULTRA_THICK |


## SearchParams

AtomicServiceSearch中“搜索区”的初始化参数。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称                     | 类型            | 必填                                   | 说明                                                         |
| ------------------------ | ---------------------------------------------- | ------------------------------------------------------------ | ---- |
| componentBackgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 设置组件的背景色。   |
| pressedBackgroundColor   | [ResourceColor](ts-types.md#resourcecolor) | 否 | 设置组件按压态的背景色。   |
| searchButton             | [SearchButtonParams](#searchbuttonparams) | 否 | 设置搜索框末尾搜索按钮。点击搜索按钮，同时触发onSubmit与onClick回调。<br />-value：搜索框末尾搜索按钮文本内容。<br /> -option: 配置搜索框文本样式。<br />默认值：<br />{<br />fontSize: '16fp',<br />fontColor: '#ff3f97e9'<br />} |
| placeholderColor         | [ResourceColor](ts-types.md#resourcecolor) | 否 | placeholder文本颜色。<br />默认值：'#99182431'。   |
| placeholderFont          | [Font](ts-types.md#font) | 否 | 设置placeholder文本样式，包括字体大小，字体粗细，字体族，字体风格。 |
| textFont                 | [Font](ts-types.md#font) | 否 | 设置搜索框内输入文本样式，包括字体大小，字体粗细，字体族，字体风格。目前仅支持默认字体族。 |
| textAlign                | [TextAlign](ts-appendix-enums.md#textalign) | 否 | 文本在搜索框中的对齐方式。<br/>默认值：TextAlign.Start   |
| copyOptions              | [CopyOptions](ts-appendix-enums.md#copyoptions9) | 否 | 输入的文本是否可复制。<br />默认值：CopyOptions.LocalDevice，支持设备内复制。   |
| searchIcon               | [IconOptions](ts-basic-components-search.md#iconoptions10对象说明) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否 | 左侧搜索图标样式。<!--RP1--><br />浅色模式默认值：<br />{<br />size: '16vp',<br />color: '#99182431',<br />src: ' '<br />}<br />深色模式默认值：<br />{<br />size: '16vp',<br />color: '#99ffffff',<br />src: ' '<br />} <!--RP1End--> |
| cancelIcon               | [IconOptions](ts-basic-components-search.md#iconoptions10对象说明) | 否 | 右侧清除按钮样式。<br>默认值：<br />{<br/>style: CancelButtonStyle.INPUT,<br/>icon:&nbsp;{<br/>size: '16vp',<br/>color: '#99ffffff',<br/>src: ' '<br/>}<br/>}<br/>当style为CancelButtonStyle.CONSTANT时，默认显示清除样式。   |
| fontColor                | [ResourceColor](ts-types.md#resourcecolor) | 否 |  输入文本的字体颜色。<br />默认值：'#FF182431'。 |
| caretStyle               | [CaretStyle](ts-text-common.md#caretstyle10) | 否 | 光标样式。<br />默认值：<br />{<br />width: '1.5vp',<br />color: '#007DFF'<br />}   |
| enableKeyboardOnFocus    | boolean | 否 | Search获焦时，是否主动拉起软键盘。<br/>默认值：true。   |
| hideSelectionMenu        | boolean | 否 | 是否不弹出系统文本选择菜单。<br />设置为true时，单击输入框光标、长按输入框、双击输入框、三击输入框或者右键输入框，不弹出系统文本选择菜单。<br />设置为false时，弹出系统文本选择菜单。<br />默认值：false   |
| type                     | [SearchType](ts-basic-components-search.md#searchtype11枚举说明) | 否 | 输入框类型。<br/>默认值：SearchType.Normal   |
| maxLength                | number | 否 | 设置文本的最大输入字符数。默认不设置最大输入字符数限制。到达文本最大字符限制，将无法继续输入字符。   |
| enterKeyType             | [EnterKeyType](ts-basic-components-textinput.md#enterkeytype枚举说明) | 否 | 输入法回车键类型。<br/>默认值：EnterKeyType.Search   |
| decoration               | [TextDecorationOptions](ts-types.md#textdecorationoptions12对象说明) | 否 |  文本装饰线对象。<br />默认值：{<br/>&nbsp;type:&nbsp;TextDecorationType.None,<br/>&nbsp;color:&nbsp;Color.Black,<br/>&nbsp;style:&nbsp;TextDecorationStyle.SOLID&nbsp;<br/>}   |
| letterSpacing            | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 否 | 设置文本字符间距。设置该值为百分比时，按默认值显示。设置该值为0时，按默认值显示。当取值为负值时，文字会发生压缩，负值过小时会将组件内容区大小压缩为0，导致无内容显示。 |
| fontFeature              | [ResourceStr](ts-types.md#resourcestr) | 否 | 设置文字特性效果，比如数字等宽的特性。<br />格式为：normal \| \<feature-tag-value\><br />\<feature-tag-value\>的格式为：\<string\> \[ \<integer\> \| on \| off ]<br />\<feature-tag-value\>的个数可以有多个，中间用','隔开。<br />例如，使用等宽数字的输入格式为："ss01" on。   |
| selectedBackgroundColor  | [ResourceColor](ts-types.md#resourcecolor) | 否 | 文本选中底板颜色。<br/>默认为20%不透明度。 |
| inputFilter              | [InputFilterParams](#inputfilterparams) | 否 | 通过正则表达式设置输入过滤器。匹配表达式的输入允许显示，不匹配的输入将被过滤。仅支持单个字符匹配，不支持字符串匹配。<br /> -value: 正则表达式。 <br /> -error: 正则匹配失败时，返回被过滤的内容。 |
| textIndent               | [Dimension](ts-types.md#dimension10) | 否 | 首行文本缩进。<br/>默认值：0   |
| minFontSize              | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 否 | 设置文本最小显示字号。   |
| maxFontSize              | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 否 | 设置文本最大显示字号。   |
| editMenuOptions          | [EditMenuOptions](ts-text-common.md#editmenuoptions) | 否 | 设置自定义菜单扩展项，允许用户设置扩展项的文本内容、图标、回调方法。   |
| enablePreviewText        | boolean | 否 | 是否开启输入预上屏。<br/>默认值：true <br/> 预上屏内容定义为文字暂存态，目前不支持文字拦截功能，因此不触发onWillInsert、onDidInsert、onWillDelete、onDidDelete回调。   |
| enableHapticFeedback     | boolean | 否 | 是否开启触控反馈。<br/>默认值：true   |
| onSubmit                 | Callback&lt;string&gt; \| [SearchSubmitCallback](ts-basic-components-search.md#searchsubmitcallback14) | 否 | 点击搜索图标、搜索按钮或者按下软键盘搜索按钮时触发该回调。   |
| onChange                 | [EditableTextOnChangeCallback](ts-text-common.md#editabletextonchangecallback12) | 否 | 输入内容发生变化时，触发该回调。   |
| onCopy                   | Callback&lt;string&gt; | 否 | 进行复制操作时，触发该回调。   |
| onCut                    | Callback&lt;string&gt; | 否 | 进行剪切操作时，触发该回调。   |
| onPaste                  | [OnPasteCallback](#onpastecallback) | 否 | 进行粘贴操作时，触发该回调。   |
| onTextSelectionChange    | [OnTextSelectionChangeCallback](#ontextselectionchangecallback) | 否 | 文本选择的位置发生变化或编辑状态下光标位置发生变化时，触发该回调。   |
| onContentScroll          | [OnContentScrollCallback](#oncontentscrollcallback) | 否 | 文本内容滚动时，触发该回调。   |
| onEditChange             | Callback&lt;boolean&gt; | 否 | 输入状态变化时，触发该回调。有光标时为编辑态，无光标时为非编辑态。isEditing为true表示正在输入。   |
| onWillInsert             | Callback&lt;InsertValue, boolean&gt; | 否 | 在将要输入时，触发该回调。   |
| onDidInsert              | Callback&lt;InsertValue&gt; | 否 | 在输入完成时，触发该回调。   |
| onWillDelete             | Callback&lt;DeleteValue, boolean&gt; | 否 | 在将要删除时，触发该回调。   |
| onDidDelete              | Callback&lt;DeleteValue&gt; | 否 | 在删除完成时，触发该回调。   |


## OperationParams

AtomicServiceSearch中“功能区”的初始化参数。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型        | 必填  | 说明                          |
| ------------- | --------------- | ---------------------------- | ---- |
| auxiliaryItem | [OperationOption ](ohos-arkui-advanced-SubHeader.md#operationoption)| 否 | 附属于搜索区（右侧）的功能位。默认值：undefined |
| auxiliaryItem | [OperationOption ](ohos-arkui-advanced-SubHeader.md#operationoption)| 否 | 独立于搜索区（右侧）的功能位。默认值：undefined |


## InputFilterParams

搜索框过滤设置项。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称             | 类型         | 必填 | 说明                               |
| ---------------- | ---------------- | ---- | ---------------------------------- |
| inputFilterValue | [ResourceStr](ts-types.md#resourcestr) | 是 | 正则表达式。 |
| error | Callback<string> | 否 | 正则匹配失败时，返回被过滤的内容。 |


## SearchButtonParams

搜索框末尾搜索按钮设置项。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型            | 必填 | 说明                                                         |
| ----------------- | ------------------- | ---- | ------------------------------------------------------------ |
| searchButtonValue | [ResourceStr](ts-types.md#resourcestr) | 是   | 搜索框末尾搜索按钮文本内容。 |
| options | [SearchButtonOptions](ts-basic-components-search.md#searchbuttonoptions10对象说明) | 否   | 配置搜索框文本样式。默认值：{fontSize: '16fp',fontColor: '#ff3f97e9'} |


## MenuAlignParams

下拉按钮与下拉菜单间的对齐方式设置项。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型      | 必填 | 说明                                                         |
| --------- | ------------- | ---- | ------------------------------------------------------------ |
| alignType | [MenuAlignType](ts-basic-components-select.md#menualigntype10枚举说明) | 是 | 对齐方式类型。默认值：MenuAlignType.START |
| offset | [Offset](ts-types.md#offset) | 否 | 按照对齐类型对齐后，下拉菜单相对下拉按钮的偏移量。默认值：{dx: 0, dy: 0} |


## OnSelectCallback

type OnSelectCallback = (index: number, selectValue: string) => void

下拉菜单选中某一项的回调。

**卡片能力** 从API version 16开始，该接口支持在ArkTs卡片中使用。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| index | number | 是 | 选中项的索引。 |
| selectValue | string | 是 | 选中项的值。 |


## OnPasteCallback

type OnPasteCallback = (pasteValue: string, event: PasteEvent) => void

进行粘贴操作时，触发该回调

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| pasteValue | string | 是 | 要粘贴的文本内容。 |
| event | [PasteEvent](ts-basic-components-richeditor.md#pasteevent) | 是 | 用户自定义粘贴事件。 |


## OnTextSelectionChangeCallback

type OnTextSelectionChangeCallback = (selectionStart: number, selectionEnd: number) => void

文本选择的位置发生变化或编辑状态下光标位置发生变化时，触发该回调。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| selectionStart | number | 是 | 文本选择区域的起始位置。 |
| selectionEnd | number | 是 | 文本选择区域的结束位置。 |


## OnContentScrollCallback

type OnContentScrollCallback = (totalOffsetX: number, totalOffsetY: number) => void

文本内容滚动时，触发该回调。

**原子化服务API**： 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| totalOffsetX | number | 是 | 文本在内容区的横坐标偏移量。 |
| totalOffsetY | number | 是 | 文本在荣内区的纵坐标偏移量。 |


## 示例

### 示例1（基础默认AtomicServiceSearch）
```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 6 }) {
      Text('基础默认AtomicServiceSearch').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})
      
      AtomicServiceSearch();
    }.padding({ left: 16, right: 16 })
  }

  private alert(message: string): void {
    AlertDialog.show({
      message: message
    })
  }
}
```

### 示例2（AtomicServiceSearch添加选择区）
```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 6 }) {
      Text('AtomicServiceSearch添加选择区').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})
      
      AtomicServiceSearch({
        select: {
          options: [
            { value: 'Select1', icon: $r("app.media.sweep") }, // 自定义资源
            { value: 'Select2', icon: $r("app.media.sweep") }, // 自定义资源
            { value: 'Select3', icon: $r("app.media.sweep") }, // 自定义资源
            { value: 'Select4', icon: $r("app.media.sweep") } // 自定义资源
          ],
          selected: -1,
          selectValue: 'Select1',
          onSelect: (index: number) => { // 自定义事件
            if (index === 0) {
              this.alert('Select1');
            } else if (index === 1) {
              this.alert('Select2');
            } else if (index === 2) {
              this.alert('Select3');
            } else if (index === 3) {
              this.alert('Select4');
            }
          },
        }
      })
    }.padding({ left: 16, right: 16 })
  }

  private alert(message: string): void {
    AlertDialog.show({
      message: message
    })
  }
}
```


### 示例3（AtomicServiceSearch添加功能位）
```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 6 }) {
      Text('AtomicServiceSearch添加功能位').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})
      
      AtomicServiceSearch({
        operation: {
          // 附属于Search组件的功能位
          auxiliaryItem: {
            value: $r("app.media.sweep"), // 自定义资源
            action: () => {
              this.alert('扫一扫'); // 自定义事件
            }
          },
          // 独立于Search组件的功能位
          independentItem: {
            value: $r("app.media.dingding"), // 自定义资源
            action: () => {
              this.alert('通知'); // 自定义事件
            }
          }
        }
      })
    }.padding({ left: 16, right: 16 })
  }

  private alert(message: string): void {
    AlertDialog.show({
      message: message
    })
  }
}
```

### 示例4（AtomicServiceSearch添加选择区及功能位）
```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 6 }) {
      Text('AtomicServiceSearch+选择区+功能位').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        select: {
          options: [
            { value: 'Select1', icon: $r("app.media.sweep") }, // 自定义资源
            { value: 'Select2', icon: $r("app.media.sweep") }, // 自定义资源
            { value: 'Select3', icon: $r("app.media.sweep") }, // 自定义资源
            { value: 'Select4', icon: $r("app.media.sweep") } // 自定义资源
          ],
          selected: -1,
          selectValue: 'Select1',
          onSelect: (index: number) => {
            if (index === 0) {
              this.alert('Select1');
            } else if (index === 1) {
              this.alert('Select2');
            } else if (index === 2) {
              this.alert('Select3');
            } else if (index === 3) {
              this.alert('Select4');
            }
          },
        },
        operation: {
          auxiliaryItem: {
            value: $r("app.media.sweep"), // 自定义资源
            action: () => {
              this.alert('扫一扫'); // 自定义事件
            }
          },
          independentItem: {
            value: $r("app.media.dingding"), // 自定义资源
            action: () => {
              this.alert('通知'); // 自定义事件
            }
          }
        }
      })
    }.padding({ left: 16, right: 16 })
  }

  private alert(message: string): void {
    AlertDialog.show({
      message: message
    })
  }
}
```

### 示例5（search回调事件, 自定义键盘避让）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State insertValue: string = "";
  @State deleteValue: string = "";
  @State insertOffset: number = 0;
  @State deleteOffset: number = 0;
  @State deleteDirection: number = 0;
  @State startIndex: number = 0;
  @State endIndex: number = 0;
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State changeValue: string = '';
  @State value: string = 'false';
  @State submitValue: string = '';
  @State text: string = 'Search editMenuOptions';

  build() {
    Column({ space: 6 }) {
      Text('AtomicServiceSearch绑定事件').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      Column({ space: 6 }) {
        Text('editing: ' + this.value).width('100%').height(25).borderRadius(15).padding({ left: 15 })
          .backgroundColor('rgba(0, 0, 0, 0.1)').maxLines(1).textOverflow({ overflow: TextOverflow.MARQUEE });
        Text('onSubmit:' + this.submitValue).width('100%').height(25).borderRadius(15).padding({ left: 15 })
          .backgroundColor('rgba(0, 0, 0, 0.1)').maxLines(1).textOverflow({ overflow: TextOverflow.MARQUEE });
        Text('onChange:' + this.changeValue).width('100%').height(25).borderRadius(15).padding({ left: 15 })
          .backgroundColor('rgba(0, 0, 0, 0.1)').maxLines(1).textOverflow({ overflow: TextOverflow.MARQUEE });
        Text('offset x:' + this.offsetX + ' y:' + this.offsetY).width('100%').height(25).borderRadius(15).padding({ left: 15 })
          .backgroundColor('rgba(0, 0, 0, 0.1)').maxLines(1).textOverflow({ overflow: TextOverflow.MARQUEE });
        Text("insertValue:" + this.insertValue + "  insertOffset:" + this.insertOffset).width('100%').height(25)
          .borderRadius(15).padding({ left: 15 }).backgroundColor('rgba(0, 0, 0, 0.1)').maxLines(1)
          .textOverflow({ overflow: TextOverflow.MARQUEE });
        Text("deleteValue:" + this.deleteValue + "  deleteOffset:" + this.deleteOffset).width('100%').height(25)
          .borderRadius(15).padding({ left: 15 }).backgroundColor('rgba(0, 0, 0, 0.1)').maxLines(1)
          .textOverflow({ overflow: TextOverflow.MARQUEE });
        Text("deleteDirection:" + (this.deleteDirection == 0 ? "BACKWARD" : "FORWARD")).width('100%').height(25)
          .borderRadius(15).padding({ left: 15 }).backgroundColor('rgba(0, 0, 0, 0.1)').maxLines(1)
          .textOverflow({ overflow: TextOverflow.MARQUEE });
        AtomicServiceSearch({
          select: {
            options: [
              { value: 'Select1', icon: $r("app.media.sweep") },
              { value: 'Select2', icon: $r("app.media.sweep") },
              { value: 'Select3', icon: $r("app.media.sweep") },
              { value: 'Select4', icon: $r("app.media.sweep") }
            ],
            selected: -1,
            selectValue: 'Select1',
            onSelect: (index: number) => {
              if (index === 0) {
                this.alert('Select1');
              } else if (index === 1) {
                this.alert('Select2');
              } else if (index === 2) {
                this.alert('Select3');
              } else if (index === 3) {
                this.alert('Select4');
              }
            },
          },
          search: {
            onSubmit: (value: string) => {
              this.submitValue = value
            },
            onChange: (value: string) => {
              this.changeValue = value
            },
            onCopy: () => {
              this.alert('onCopy');
            },
            onCut: () => {
              this.alert('onCut');
            },
            onPaste: () => {
              this.alert('onPaste');
            },
            onTextSelectionChange: (selectionStart: number, selectionEnd: number) => {
              this.startIndex = selectionStart
              this.endIndex = selectionEnd
            },
            onContentScroll: (totalOffsetX: number, totalOffsetY: number) => {
              this.offsetX = totalOffsetX
              this.offsetY = totalOffsetY
            },
            onEditChange: (data: boolean) => {
              this.value = data ? 'true' : 'false'
            },
            onWillInsert: (info: InsertValue) => {
              this.insertValue = info.insertValue
              return true;
            },
            onDidInsert: (info: InsertValue) => {
              this.insertOffset = info.insertOffset
            },
            onWillDelete: (info: DeleteValue) => {
              this.deleteValue = info.deleteValue
              info.direction
              return true;
            },
            onDidDelete: (info: DeleteValue) => {
              this.deleteOffset = info.deleteOffset
              this.deleteDirection = info.direction
            }
          }
        })
      }
    }.padding({ left: 16, right: 16 })
  }

  private alert(message: string): void {
    AlertDialog.show({
      message: message
    })
  }
}
```

### 示例6（AtomicServiceSearch修改Select样式）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 6 }) {
      Text('AtomicServiceSearch修改Select样式').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        select: {
          options: [
            { value: 'Select1', icon: $r("app.media.sweep") },
            { value: 'Select2', icon: $r("app.media.sweep") },
            { value: 'Select3', icon: $r("app.media.sweep") },
            { value: 'Select4', icon: $r("app.media.sweep") }
          ],
          selected: -1,
          selectValue: 'Select1',
          onSelect: (index: number) => {
            if (index === 0) {
              this.alert('Select1');
            } else if (index === 1) {
              this.alert('Select2');
            } else if (index === 2) {
              this.alert('Select3');
            } else if (index === 3) {
              this.alert('Select4');
            }
          },
          font: {
            size: 16,
            weight: 700,
          },
          fontColor: Color.Red,
          selectedOptionBgColor: Color.Blue,
          selectedOptionFont: {
            size: 8,
            weight: 400,
          },
          optionFont: {
            size: 16,
            weight: 700,
          },
          optionBgColor: Color.Gray,
          optionFontColor: Color.Green,
          menuBackgroundColor: Color.Yellow,
          optionWidth: 200,
          optionHeight: 300,
          space: 20,
          arrowPosition: ArrowPosition.START,
          menuAlign: {
            alignType: MenuAlignType.CENTER,
            offset: { dx: 100, dy: 100 }
          },
          divider: ({
            strokeWidth: 1,
            color: Color.Blue,
            startMargin: 10,
            endMargin: 10
          })
        }
      });
    }.padding({ left: 16, right: 16 })
  }

  private alert(message: string): void {
    AlertDialog.show({
      message: message
    })
  }
}
```

### 示例7（AtomicServiceSearch修改Search样式）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('AtomicServiceSearch修改Search样式').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        select: {
          options: [
            { value: '选项1', icon: $r("app.media.sweep") },
            { value: '选项2', icon: $r("app.media.sweep") },
            { value: '选项3', icon: $r("app.media.sweep") },
            { value: '选项4', icon: $r("app.media.sweep") }
          ],
          selected: -1,
          selectValue: '选项1',
          onSelect: (index: number) => {
            if (index === 0) {
              this.alert('选项1');
            } else if (index === 1) {
              this.alert('选项2');
            } else if (index === 2) {
              this.alert('选项3');
            } else if (index === 3) {
              this.alert('选项4');
            }
          },
          font: {
            size: 12,
            weight: 700,
          },
          optionFont: {
            size: 12,
          },
          selectedOptionFont: {
            size: 12
          }
        },
        operation: {
          auxiliaryItem: {
            value: $r(`app.media.sweep`),
            action: () => {
              this.alert('扫一扫');
            }
          },
          independentItem: {
            value: $r(`app.media.dingding`),
            action: () => {
              this.alert('通知');
            }
          }
        },
        search: {
          searchButton: {
            searchButtonValue: 'SEARCH',
            options: { fontSize: '12fp', fontColor: '#ff0e1216' }
          },
          textFont: {
            size: 12,
          },
          placeholderFont: {
            size: 12,
          },
        }
      });
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例8（通过controller实现光标位置的设置）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  controller: SearchController = new SearchController();

  build() {
    Column({ space : 10 }) {
      Text('通过controller实现光标位置的设置').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch(
        {
          value: 'Default Value',
          placeholder: 'Type to Search...',
          controller: this.controller,
          search: {
            searchButton: {
              searchButtonValue: 'SEARCH',
              options: { fontSize: '12fp', fontColor: '#ff0e1216' }
            }
          }
        },
      );
      Button('caretPosition to 1').onClick(() => {
        this.controller.caretPosition(1);
      }).width('100%')
      Button('stopEditing').onClick(() => {
        this.controller.stopEditing();
      }).width('100%')
      Button('Selection [0,3]').onClick(() => {
        this.controller.setTextSelection(0, 3)
      }).width('100%')
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例9（设置搜索和删除图标的效果）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('设置搜索和删除图标的效果').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch(
        {
          search: {
            searchButton: {
              searchButtonValue: 'SEARCH',
              options: { fontSize: '12fp', fontColor: '#ff774747' }
            },
            searchIcon: {
              size: 15,
              color: '#ff774747',
              src: $r(`app.media.search`)
            },
            cancelIcon: {
              size: 15,
              color: '#ff774747',
              src: $r(`app.media.close`)
            },
            placeholderColor: '#ff774747',
            placeholderFont: { size: 14, weight: 400 },
            textFont: { size: 14, weight: 400 },
            componentBackgroundColor : '#F5F5F5'
          }
        },
      );
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例10（设置输入法回车键类型）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State enterTypes: Array<EnterKeyType> = [EnterKeyType.Go, EnterKeyType.Search, EnterKeyType.Send, EnterKeyType.Done, EnterKeyType.Next, EnterKeyType.PREVIOUS, EnterKeyType.NEW_LINE]
  @State index: number = 0

  build() {
    Column({ space : 10 }) {
      Text('输入法回车键类型为搜索').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        placeholder: '输入法回车键类型为搜索',
        search: {
          enterKeyType: this.enterTypes[this.index]
        }
      })

      Button('改变EnterKeyType').onClick(() => {
        this.index = (this.index + 1) % this.enterTypes.length;
      }).width('100%')

    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例11（设置文本样式）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('设置文本样式').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      Text('letterSpacing').fontSize(9).fontColor(0xCCCCCC)
      AtomicServiceSearch({
        value: 'letterSpacing 0'
      }).margin({bottom: 10})
      AtomicServiceSearch({
        value: 'letterSpacing 3',
        search: {
          letterSpacing: 3
        }
      }).margin({bottom: 10})
      AtomicServiceSearch({
        value: 'letterSpacing -1',
        search: {
          letterSpacing: -1
        }
      }).margin({bottom: 10})

      Text('decoration').fontSize(9).fontColor(0xCCCCCC)
      AtomicServiceSearch({
        value: 'LineThrough, Red',
        search: {
          decoration: {type: TextDecorationType.LineThrough, color: Color.Red}
        }
      }).margin({bottom: 10})
      AtomicServiceSearch({
        value: 'Overline, Red, DOTTED',
        search: {
          decoration: {type: TextDecorationType.Overline, color: Color.Red, style: TextDecorationStyle.DOTTED}
        }
      }).margin({bottom: 10})
      AtomicServiceSearch({
        value: 'Underline, Red, WAVY',
        search: {
          decoration: {type: TextDecorationType.Underline, color: Color.Red, style: TextDecorationStyle.WAVY}
        }
      }).margin({bottom: 10})
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例12（设置文字特性效果）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column({ space : 10 }) {
      Text('设置文字特性效果').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        value: 'This is ss01 on : 0123456789',
        search: {
          fontFeature: "\"ss012\" on"
        }
      });
      
      AtomicServiceSearch({
        value: 'This is ss01 off : 0123456789',
        search: {
          fontFeature: "\"ss01\" off"
        }
      });
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例13（设置文本自适应）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column({ space : 10 }) {
      Text('设置文本自适应').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        value: 'This is the text without the adaptive font',
      }).width('80%').height(40).borderWidth(1).borderRadius(20)

      AtomicServiceSearch({
        value: 'This is the text without the adaptive font',
        search: {
          minFontSize: 4,
          maxFontSize: 40
        }
      }).width('80%').height(40).borderWidth(1).borderRadius(20)
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例14（文本扩展自定义菜单）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  onCreateMenu = (menuItems: Array<TextMenuItem>) => {
    let item1: TextMenuItem = {
      content: 'custom1',
      icon: $r('app.media.startIcon'),
      id: TextMenuItemId.of('custom1'),
    }
    let item2: TextMenuItem = {
      content: 'custom2',
      id: TextMenuItemId.of('custom2'),
      icon: $r('app.media.startIcon'),
    }
    menuItems.push(item1)
    menuItems.unshift(item2)
    return menuItems
  }

  onMenuItemClick = (menuItem: TextMenuItem, textRange: TextRange) => {
    if (menuItem.id.equals(TextMenuItemId.of("custom2"))) {
      console.log("拦截 id: custom2 start:" + textRange.start + "; end:" + textRange.end)
      return true
    }
    if (menuItem.id.equals(TextMenuItemId.COPY)) {
      console.log("拦截 COPY start:" + textRange.start + "; end:" + textRange.end)
      return true
    }
    if (menuItem.id.equals(TextMenuItemId.SELECT_ALL)) {
      console.log("不拦截 SELECT_ALL start:" + textRange.start + "; end:" + textRange.end)
      return false
    }
    return false
  }

  @State editMenuOptions: EditMenuOptions = {
    onCreateMenu: this.onCreateMenu, onMenuItemClick: this.onMenuItemClick
  }

  build() {
    Column({ space : 10 }) {
      Text('设置文本自适应').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        value:'Default input',
        search: {
          editMenuOptions : this.editMenuOptions
        }
      })
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例15（设置文本是否可复制）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State copyValue: string = '';
  @State cutValue: string = '';

  build() {
    Column() {
      Column({ space: 10 }) {
        Text('设置文本是否可复制').alignSelf(ItemAlign.Start).decoration({
          type: TextDecorationType.Underline,
          color: Color.Black,
          style: TextDecorationStyle.SOLID
        }).margin({top:20, bottom: 20})

        AtomicServiceSearch({
          value: 'Search CopyOption:None',
          search: {
            copyOptions: CopyOptions.None,
            onCopy: (value:string) => {
              this.copyValue = value;
            },
            onCut:(value: string) => {
              this.cutValue = value;
            }
          },
        })

        AtomicServiceSearch({
          value: 'Search CopyOption:InApp',
          search: {
            copyOptions: CopyOptions.InApp,
            onCopy: (value:string) => {
              this.copyValue = value;
            },
            onCut:(value: string) => {
              this.cutValue = value;
            }
          },
        })

        AtomicServiceSearch({
          value: 'Search CopyOption:LocalDevice',
          search: {
            copyOptions: CopyOptions.LocalDevice,
            onCopy: (value:string) => {
              this.copyValue = value;
            },
            onCut:(value: string) => {
              this.cutValue = value;
            }
          },
        })

        Text("copy: " + this.copyValue).alignSelf(ItemAlign.Start)
        Text("cut:" + this.cutValue).alignSelf(ItemAlign.Start)
      }
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例16（设置文本水平对齐/光标样式/选中背景色）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('设置文本水平对齐/光标样式/选中背景色').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        value: 'Search textAlign sample',
        search: {
          textAlign: TextAlign.Center,
          caretStyle: { width: 3, color: Color.Green },
          selectedBackgroundColor: Color.Gray
        }
      })
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例17（关闭系统文本选择菜单）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Text('关闭系统文本选择菜单').alignSelf(ItemAlign.Start).decoration({
        type: TextDecorationType.Underline,
        color: Color.Black,
        style: TextDecorationStyle.SOLID
      }).margin({top:20, bottom: 20})

      AtomicServiceSearch({
        value: '123456',
        search: {
          hideSelectionMenu: true
        }
      })
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

### 示例18（对输入的文本进行过滤）

```ts
import { AtomicServiceSearch } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State filterValue: string = '';

  build() {
    Column() {
      Column({ space: 10 }) {
        Text('对输入的文本进行过滤').alignSelf(ItemAlign.Start).decoration({
          type: TextDecorationType.Underline,
          color: Color.Black,
          style: TextDecorationStyle.SOLID
        }).margin({top:20, bottom: 20})
        AtomicServiceSearch({
          placeholder: 'please enter...',
          search: {
            inputFilter: {
              inputFilterValue : '[a-z]',
              error: (filterValue: string) => {this.filterValue = filterValue}
            }
          }
        })
        Text('Filter:' + this.filterValue).alignSelf(ItemAlign.Start)

      }
    }.padding({ left: 16, right: 16 })
  }

  public alert(message: string): void {
    AlertDialog.show({
      message: message,
    })
  }
}
```

