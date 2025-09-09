# @ohos.arkui.theme(主题换肤)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @lushi871202-->
<!--Designer: @lushi871202-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

支持自定义主题风格，实现App组件风格跟随Theme切换。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { Theme, ThemeControl, CustomColors, Colors, CustomTheme, CustomDarkColors } from '@kit.ArkUI';
```

## Theme

当前生效的主题风格对象，可从[onWillApplyTheme](arkui-ts/ts-custom-component-lifecycle.md#onwillapplytheme12)中获取。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                | 只读 | 可选 | 说明       |
| ------ |-------------------|-----|-----|----------|
| colors | [Colors](#colors) | 否   | 否   |  主题颜色资源。 |

## Colors

主题颜色资源。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

<!--RP1--><!--RP1End-->

| 名称                           | 类型                                                 | 只读 | 可选 | 说明               |
|-------------------------------|-----------------------------------------------------|-----|-----|------------------|
| brand                         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 品牌色。</br>**影响组件：** [TextInput](./arkui-ts/ts-basic-components-textinput.md)、[Search](./arkui-ts/ts-basic-components-search.md)        |
| warning                       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级警示色。</br>**影响组件：** [TipsDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#tipsdialog)、[AlertDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#alertdialog)、[CustomContentDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#customcontentdialog12)、</br>[Badge](./arkui-ts/ts-container-badge.md)、[Button](./arkui-ts/ts-basic-components-button.md)          |
| alert                         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级提示色。</br>**影响组件：** 暂无组件使用。           |
| confirm                       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 确认色。</br>**影响组件：** 暂无组件使用。             |
| fontPrimary                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级文本字体颜色。</br>**影响组件：** [EditableTitleBar](./arkui-ts/ohos-arkui-advanced-EditableTitleBar.md)、[LoadingDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#loadingdialog)、[TipsDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#tipsdialog)、</br>[ConfirmDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#confirmdialog)、[AlertDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#alertdialog)、[SelectDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#selectdialog)、</br>[CustomContentDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#customcontentdialog12)、[Swiper](./arkui-ts/ts-container-swiper.md)、[Text](./arkui-ts/ts-basic-components-text.md)、</br>[SubHeader](./arkui-ts/ohos-arkui-advanced-SubHeader.md)、[ProgressButton](./arkui-ts/ohos-arkui-advanced-ProgressButton.md)、[AlphabetIndexer](./arkui-ts/ts-container-alphabet-indexer.md)、</br>[Popup](./arkui-ts/ohos-arkui-advanced-Popup.md)、[Select](./arkui-ts/ts-basic-components-select.md)、[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md)、</br>[ToolBar](./arkui-ts/ohos-arkui-advanced-ToolBar.md)、[Menu](./arkui-ts/ts-basic-components-menu.md)、[TextInput](./arkui-ts/ts-basic-components-textinput.md)、</br>[Search](./arkui-ts/ts-basic-components-search.md)、[Counter](./arkui-ts/ts-container-counter.md)、[TimePicker](./arkui-ts/ts-basic-components-timepicker.md)、[DatePicker](./arkui-ts/ts-basic-components-datepicker.md)、</br>[TextPicker](./arkui-ts/ts-basic-components-textpicker.md)、[ComposeListItem](./arkui-ts/ohos-arkui-advanced-ComposeListItem.md)、[TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)        |
| fontSecondary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级文本字体颜色。</br>**影响组件：** [EditableTitleBar](./arkui-ts/ohos-arkui-advanced-EditableTitleBar.md)、[AlertDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#alertdialog)、[CustomContentDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#customcontentdialog12)、</br>[SubHeader](./arkui-ts/ohos-arkui-advanced-SubHeader.md)、[AlphabetIndexer](./arkui-ts/ts-container-alphabet-indexer.md)、[Popup](./arkui-ts/ohos-arkui-advanced-Popup.md)、</br>[TextInput](./arkui-ts/ts-basic-components-textinput.md)、[Search](./arkui-ts/ts-basic-components-search.md)、[ComposeListItem](./arkui-ts/ohos-arkui-advanced-ComposeListItem.md)、</br>[TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)        |
| fontTertiary                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级文本字体颜色。</br>**影响组件：** [ComposeListItem](./arkui-ts/ohos-arkui-advanced-ComposeListItem.md)        |
| fontFourth                    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级文本字体颜色。</br>**影响组件：** 暂无组件使用。        |
| fontEmphasize                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮字体颜色。</br>**影响组件：** [TipsDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#tipsdialog)、[ConfirmDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#confirmdialog)、[AlertDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#alertdialog)、</br>[SelectDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#selectdialog)、[CustomContentDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#customcontentdialog12)、[SubHeader](./arkui-ts/ohos-arkui-advanced-SubHeader.md)、</br>[AlphabetIndexer](./arkui-ts/ts-container-alphabet-indexer.md)、[Popup](./arkui-ts/ohos-arkui-advanced-Popup.md)、[Button](./arkui-ts/ts-basic-components-button.md)、</br>[Select](./arkui-ts/ts-basic-components-select.md)、[ToolBar](./arkui-ts/ohos-arkui-advanced-ToolBar.md)、[Search](./arkui-ts/ts-basic-components-search.md)、</br>[TimePicker](./arkui-ts/ts-basic-components-timepicker.md)、[DatePicker](./arkui-ts/ts-basic-components-datepicker.md)、[TextPicker](./arkui-ts/ts-basic-components-textpicker.md)          |
| fontOnPrimary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级文本反转颜色，用于彩色背景。</br>**影响组件：** [Badge](./arkui-ts/ts-container-badge.md)、[Button](./arkui-ts/ts-basic-components-button.md)、[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md) |
| fontOnSecondary               | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级文本反转颜色，用于彩色背景。</br>**影响组件：** 暂无组件使用。 |
| fontOnTertiary                | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级文本反转颜色，用于彩色背景。</br>**影响组件：** 暂无组件使用。 |
| fontOnFourth                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级文本反转颜色，用于彩色背景。</br>**影响组件：** 暂无组件使用。 |
| iconPrimary                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级图标颜色。</br>**影响组件：** [EditableTitleBar](./arkui-ts/ohos-arkui-advanced-EditableTitleBar.md)、[Swiper](./arkui-ts/ts-container-swiper.md)、[ToolBar](./arkui-ts/ohos-arkui-advanced-ToolBar.md)、</br>[TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)          |
| iconSecondary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级图标颜色。</br>**影响组件：** [LoadingDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#loadingdialog)、[SubHeader](./arkui-ts/ohos-arkui-advanced-SubHeader.md)、[LoadingProgress](./arkui-ts/ts-basic-components-loadingprogress.md)、</br>[Popup](./arkui-ts/ohos-arkui-advanced-Popup.md)、[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md)、[Search](./arkui-ts/ts-basic-components-search.md)、</br>[TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)          |
| iconTertiary                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级图标颜色。</br>**影响组件：** [SubHeader](./arkui-ts/ohos-arkui-advanced-SubHeader.md)          |
| iconFourth                    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级图标颜色。</br>**影响组件：** [Checkbox](./arkui-ts/ts-basic-components-checkbox.md)、[CheckboxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)、[Radio](./arkui-ts/ts-basic-components-radio.md)          |
| iconEmphasize                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮图标颜色。</br>**影响组件：** [ToolBar](./arkui-ts/ohos-arkui-advanced-ToolBar.md)          |
| iconSubEmphasize              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮辅助图标颜色。</br>**影响组件：** 暂无组件使用。        |
| iconOnPrimary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级图标反转颜色，用于彩色背景。</br>**影响组件：** [Checkbox](./arkui-ts/ts-basic-components-checkbox.md)、[CheckboxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)、[Radio](./arkui-ts/ts-basic-components-radio.md) |
| iconOnSecondary               | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级图标反转颜色，用于彩色背景。</br>**影响组件：** [Chip](./arkui-ts/ohos-arkui-advanced-Chip.md) |
| iconOnTertiary                | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级图标反转颜色，用于彩色背景。</br>**影响组件：** 暂无组件使用。 |
| iconOnFourth                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级图标反转颜色，用于彩色背景。</br>**影响组件：** [ProgressButton](./arkui-ts/ohos-arkui-advanced-ProgressButton.md) |
| backgroundPrimary             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级背景颜色（实色，不透明）。</br>**影响组件：** [TextInput](./arkui-ts/ts-basic-components-textinput.md)、[QRCode](./arkui-ts/ts-basic-components-qrcode.md)  |
| backgroundSecondary           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级背景颜色（实色，不透明）。</br>**影响组件：** 暂无组件使用。  |
| backgroundTertiary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级背景颜色（实色，不透明）。</br>**影响组件：** 暂无组件使用。  |
| backgroundFourth              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级背景颜色（实色，不透明）。</br>**影响组件：** 暂无组件使用。  |
| backgroundEmphasize           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮背景颜色（实色，不透明）。</br>**影响组件：** [Progress](./arkui-ts/ts-basic-components-progress.md)、[Button](./arkui-ts/ts-basic-components-button.md)、[Slider](./arkui-ts/ts-basic-components-slider.md)  |
| compForegroundPrimary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 前背景。</br>**影响组件：** [QRCode](./arkui-ts/ts-basic-components-qrcode.md)            |
| compBackgroundPrimary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 白色背景。</br>**影响组件：** 暂无组件使用。            |
| compBackgroundPrimaryTran     | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 白色透明背景。</br>**影响组件：** 暂无组件使用。         |
| compBackgroundPrimaryContrary | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 常亮背景。</br>**影响组件：** [Toggle](./arkui-ts/ts-basic-components-toggle.md)、[Slider](./arkui-ts/ts-basic-components-slider.md)           |
| compBackgroundGray            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 灰色背景。</br>**影响组件：** 暂无组件使用。            |
| compBackgroundSecondary       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级背景。</br>**影响组件：** [Swiper](./arkui-ts/ts-container-swiper.md)、[Slider](./arkui-ts/ts-basic-components-slider.md)            |
| compBackgroundTertiary        | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级背景。</br>**影响组件：** [EditableTitleBar](./arkui-ts/ohos-arkui-advanced-EditableTitleBar.md)、[Progress](./arkui-ts/ts-basic-components-progress.md)、[AlphabetIndexer](./arkui-ts/ts-container-alphabet-indexer.md)、</br>[Button](./arkui-ts/ts-basic-components-button.md)、[Select](./arkui-ts/ts-basic-components-select.md)、[Toggle](./arkui-ts/ts-basic-components-toggle.md)、</br>[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md)、[TextInput](./arkui-ts/ts-basic-components-textinput.md)、[Search](./arkui-ts/ts-basic-components-search.md)            |
| compBackgroundEmphasize       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮背景。</br>**影响组件：** [Swiper](./arkui-ts/ts-container-swiper.md)、[Toggle](./arkui-ts/ts-basic-components-toggle.md)、[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md)、</br>[Checkbox](./arkui-ts/ts-basic-components-checkbox.md)、[CheckboxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)、[Radio](./arkui-ts/ts-basic-components-radio.md)            |
| compBackgroundNeutral         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 黑色中性高亮背景颜色。</br>**影响组件：** [PatternLock](./arkui-ts/ts-basic-components-patternlock.md)      |
| compEmphasizeSecondary        | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 20%高亮背景颜色。</br>**影响组件：** [Progress](./arkui-ts/ts-basic-components-progress.md)、[ProgressButton](./arkui-ts/ohos-arkui-advanced-ProgressButton.md)、[AlphabetIndexer](./arkui-ts/ts-container-alphabet-indexer.md)、</br>[Select](./arkui-ts/ts-basic-components-select.md)、[Toggle](./arkui-ts/ts-basic-components-toggle.md)       |
| compEmphasizeTertiary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 10%高亮背景颜色。</br>**影响组件：** 暂无组件使用。       |
| compDivider                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用分割线颜色。</br>**影响组件：** [SelectDialog](./arkui-ts/ohos-arkui-advanced-Dialog.md#selectdialog)、[PatternLock](./arkui-ts/ts-basic-components-patternlock.md)、[Divider](./arkui-ts/ts-basic-components-divider.md)         |
| compCommonContrary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用反转颜色。</br>**影响组件：** 暂无组件使用。          |
| compBackgroundFocus           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态背景颜色。</br>**影响组件：** 暂无组件使用。         |
| compFocusedPrimary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态一级反转颜色。</br>**影响组件：** 暂无组件使用。       |
| compFocusedSecondary          | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态二级反转颜色。</br>**影响组件：** 暂无组件使用。       |
| compFocusedTertiary           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态三级反转颜色。</br>**影响组件：** [Scroll](arkui-ts/ts-container-scroll.md)       |
| interactiveHover              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用悬停交互式颜色。</br>**影响组件：** [EditableTitleBar](./arkui-ts/ohos-arkui-advanced-EditableTitleBar.md)、[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md)、[TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)      |
| interactivePressed            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用按压交互式颜色。</br>**影响组件：** [EditableTitleBar](./arkui-ts/ohos-arkui-advanced-EditableTitleBar.md)、[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md)、[TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)       |
| interactiveFocus              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用获焦交互式颜色。</br>**影响组件：** [EditableTitleBar](./arkui-ts/ohos-arkui-advanced-EditableTitleBar.md)、[Chip](./arkui-ts/ohos-arkui-advanced-Chip.md)、[TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)       |
| interactiveActive             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用激活交互式颜色。</br>**影响组件：** [TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)       |
| interactiveSelect             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用选择交互式颜色。</br>**影响组件：** [TreeView](./arkui-ts/ohos-arkui-advanced-TreeView.md)       |
| interactiveClick              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用点击交互式颜色。</br>**影响组件：** 暂无组件使用。       |

## CustomTheme

自定义主题风格对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                           | 类型                                                 | 只读  | 可选  | 说明         |
|-------------------------------|-----------------------------------------------------|-----|-----|------------|
| colors | [CustomColors](#customcolors) | 否   | 是   | 自定义主题颜色资源。</br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| darkColors<sup>20+</sup> | [CustomDarkColors](#customdarkcolors20) | 否   | 是   | 自定义深色主题颜色资源。</br>**说明：** 如果未设置darkColors，颜色值将与浅色模式下的colors配置相同，并且不会随着颜色模式的变化而变化，除非该颜色是通过dark目录下的资源进行设置的。</br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## CustomColors

type CustomColors = Partial\<Colors>

自定义主题颜色资源类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型  | 说明           |
|-----|--------------|
| Partial<[Colors](#colors)>   | 自定义主题颜色资源类型。 |

## CustomDarkColors<sup>20+</sup>

type CustomDarkColors = Partial\<Colors>

自定义深色主题颜色资源类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型  | 说明           |
|-----|--------------|
| Partial<[Colors](#colors)>   | 自定义深色主题颜色资源类型。 |

## ThemeControl

ThemeControl将自定义Theme应用于App组件内，实现App组件风格跟随Theme切换。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setDefaultTheme

setDefaultTheme(theme: [CustomTheme](#customtheme)): void

将用户自定义Theme设置应用级默认主题，以实现应用风格跟随Theme切换。若在页面中使用此接口设置应用级默认主题，需确保该接口在页面build前执行。若在UIAbility中使用此接口设置应用级默认主题，需确保该接口在onWindowStageCreate阶段里windowStage.[loadContent](./arkts-apis-window-Window.md#loadcontent9)接口调用完成的回调函数中执行。详细代码可参考[设置应用内组件自定义主题色](../../ui/theme_skinning.md#设置应用内组件自定义主题色)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型                           | 必填 | 说明             |
|--------------|------------------------------|------|----------------|
| theme | [CustomTheme](#customtheme)  | 是    | 表示设置的自定义主题风格。 |

**示例**

```ts
import { CustomTheme, CustomColors, ThemeControl } from '@kit.ArkUI';
// 自定义主题颜色
class BlueColors implements CustomColors {
  fontPrimary = Color.Red;
  backgroundPrimary = Color.Blue;
  brand = "#FFEEAAFF"; // 品牌色
}

class PageCustomTheme implements CustomTheme {
  colors?: CustomColors;

  constructor(colors: CustomColors) {
    this.colors = colors;
  }
}
// 创建实例
const BlueColorsTheme = new PageCustomTheme(new BlueColors());
// 在页面build之前执行ThemeControl.setDefaultTheme，设置App默认样式风格为BlueColorsTheme。
ThemeControl.setDefaultTheme(BlueColorsTheme);

@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        // 文本颜色应用fontPrimary
        Text('这是一段文本')
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .margin('5%')
        // 二维码背景色应用backgroundPrimary
        QRCode('Hello')
          .width(100)
          .height(100)
        // 输入框光标颜色应用brand
        TextInput({placeholder: 'input your word...'})
          .width('80%')
          .height(40)
          .margin(20)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
