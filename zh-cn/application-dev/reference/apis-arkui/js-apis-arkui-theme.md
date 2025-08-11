# @ohos.arkui.theme(主题换肤)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @lushi871202-->
<!--SE: @lushi871202-->
<!--TSE: @sally__-->

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

| 名称                           | 类型                                                 | 只读 | 可选 | 说明               |
|-------------------------------|-----------------------------------------------------|-----|-----|------------------|
| brand                         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 品牌色。             |
| warning                       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级警示色。           |
| alert                         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级提示色。           |
| confirm                       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 确认色。             |
| fontPrimary                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级文本字体颜色。        |
| fontSecondary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级文本字体颜色。        |
| fontTertiary                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级文本字体颜色。        |
| fontFourth                    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级文本字体颜色。        |
| fontEmphasize                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮字体颜色。          |
| fontOnPrimary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级文本反转颜色，用于彩色背景。 |
| fontOnSecondary               | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级文本反转颜色，用于彩色背景。 |
| fontOnTertiary                | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级文本反转颜色，用于彩色背景。 |
| fontOnFourth                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级文本反转颜色，用于彩色背景。 |
| iconPrimary                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级图标颜色。          |
| iconSecondary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级图标颜色。          |
| iconTertiary                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级图标颜色。          |
| iconFourth                    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级图标颜色。          |
| iconEmphasize                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮图标颜色。          |
| iconSubEmphasize              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮辅助图标颜色。        |
| iconOnPrimary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级图标反转颜色，用于彩色背景。 |
| iconOnSecondary               | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级图标反转颜色，用于彩色背景。 |
| iconOnTertiary                | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级图标反转颜色，用于彩色背景。 |
| iconOnFourth                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级图标反转颜色，用于彩色背景。 |
| backgroundPrimary             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 一级背景颜色（实色，不透明）。  |
| backgroundSecondary           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级背景颜色（实色，不透明）。  |
| backgroundTertiary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级背景颜色（实色，不透明）。  |
| backgroundFourth              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 四级背景颜色（实色，不透明）。  |
| backgroundEmphasize           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮背景颜色（实色，不透明）。  |
| compForegroundPrimary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 前背景。             |
| compBackgroundPrimary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 白色背景。            |
| compBackgroundPrimaryTran     | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 白色透明背景。          |
| compBackgroundPrimaryContrary | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 常亮背景。            |
| compBackgroundGray            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 灰色背景。            |
| compBackgroundSecondary       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 二级背景。            |
| compBackgroundTertiary        | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 三级背景。            |
| compBackgroundEmphasize       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 高亮背景。            |
| compBackgroundNeutral         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 黑色中性高亮背景颜色。      |
| compEmphasizeSecondary        | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 20%高亮背景颜色。       |
| compEmphasizeTertiary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 10%高亮背景颜色。       |
| compDivider                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用分割线颜色。         |
| compCommonContrary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用反转颜色。          |
| compBackgroundFocus           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态背景颜色。         |
| compFocusedPrimary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态一级反转颜色。       |
| compFocusedSecondary          | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态二级反转颜色。       |
| compFocusedTertiary           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 获焦态三级反转颜色。       |
| interactiveHover              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用悬停交互式颜色。       |
| interactivePressed            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用按压交互式颜色。       |
| interactiveFocus              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用获焦交互式颜色。       |
| interactiveActive             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用激活交互式颜色。       |
| interactiveSelect             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用选择交互式颜色。       |
| interactiveClick              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 否   | 否   | 通用点击交互式颜色。       |

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

将用户自定义Theme设置应用级默认主题，实现应用风格跟随Theme切换。建议在onWindowStageCreate阶段里windowStage.loadContent的完成时回调中使用，详细代码可参考[设置应用内组件自定义主题色](../../ui/theme_skinning.md#设置应用内组件自定义主题色)。

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
  fontPrimary = Color.White;
  backgroundPrimary = Color.Blue;
  brand = Color.Blue; //品牌色
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
```
