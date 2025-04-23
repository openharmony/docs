# @ohos.arkui.theme(Theme)

You can define a custom theme to apply to components in your application.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { Theme, ThemeControl, CustomColors, Colors, CustomTheme } from '@kit.ArkUI';
```

## Theme

Defines the **Theme** object in use, which can be obtained through [onWillApplyTheme](arkui-ts/ts-custom-component-lifecycle.md#onwillapplytheme12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type               | Readable | Writable | Description      |
| ------ |-------------------|-----|-----|----------|
| colors | [Colors](#colors) | No  | No  |  Color resources of the theme. |

## Colors

Defines the color resources of a theme.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                          | Type                                                | Readable | Writable | Description              |
|-------------------------------|-----------------------------------------------------|-----|-----|------------------|
| brand                         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Brand color.            |
| warning                       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Warning color.          |
| alert                         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Alert color.          |
| confirm                       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Confirmation color.            |
| fontPrimary                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Primary font color.       |
| fontSecondary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Secondary font color.       |
| fontTertiary                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Tertiary font color.       |
| fontFourth                    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Fourth-level font color.       |
| fontEmphasize                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Emphasis font color.         |
| fontOnPrimary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Primary inverted font color used on color background. |
| fontOnSecondary               | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Secondary inverted font color used on color background. |
| fontOnTertiary                | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Tertiary inverted font color used on color background. |
| fontOnFourth                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Fourth-level inverted font color used on color background. |
| iconPrimary                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Primary icon color.         |
| iconSecondary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Secondary icon color.         |
| iconTertiary                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Tertiary icon color.         |
| iconFourth                    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Fourth-level icon color.         |
| iconEmphasize                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Emphasis icon color.         |
| iconSubEmphasize              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Color of the emphasis auxiliary icon.       |
| iconOnPrimary                 | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Primary inverted icon color used on color background. |
| iconOnSecondary               | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Secondary inverted icon color used on color background. |
| iconOnTertiary                | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Tertiary inverted icon color used on color background. |
| iconOnFourth                  | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Fourth-level inverted icon color used on color background. |
| backgroundPrimary             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Primary background color (solid, opaque). |
| backgroundSecondary           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Secondary background color (solid, opaque). |
| backgroundTertiary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Tertiary background color (solid, opaque). |
| backgroundFourth              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Fourth-level background color (solid, opaque). |
| backgroundEmphasize           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Emphasis background color (solid, opaque). |
| compForegroundPrimary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Foreground.            |
| compBackgroundPrimary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | White background.           |
| compBackgroundPrimaryTran     | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | White transparent background.         |
| compBackgroundPrimaryContrary | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Always-on background.           |
| compBackgroundGray            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Gray background.           |
| compBackgroundSecondary       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Secondary background.           |
| compBackgroundTertiary        | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Tertiary background.           |
| compBackgroundEmphasize       | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Emphasis background.           |
| compBackgroundNeutral         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Black, neutral, emphasis background.     |
| compEmphasizeSecondary        | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | 20% emphasis background color.      |
| compEmphasizeTertiary         | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | 10% emphasis background color.      |
| compDivider                   | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common divider color.        |
| compCommonContrary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common inverted color.         |
| compBackgroundFocus           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Background color in the focused state.        |
| compFocusedPrimary            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Primary inverted color in the focused state.      |
| compFocusedSecondary          | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Secondary inverted color in the focused state.      |
| compFocusedTertiary           | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Tertiary inverted color in the focused state.      |
| interactiveHover              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common interactive color for the hover state.      |
| interactivePressed            | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common interactive color for the pressed state.      |
| interactiveFocus              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common interactive color for the focused state.      |
| interactiveActive             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common interactive color for the active state.      |
| interactiveSelect             | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common interactive color for the selected state.      |
| interactiveClick              | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | No  | Common interactive color for the clicked state.      |

## CustomTheme

Defines a custom theme object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                          | Type                                                | Read Only | Optional | Description        |
|-------------------------------|-----------------------------------------------------|-----|-----|------------|
| colors | [CustomColors](#customcolors) | No  | Yes  | Color resources of the custom theme. |

## CustomColors

type CustomColors = Partial\<Colors>

Defines the color resources of a custom theme.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type | Description          |
|-----|--------------|
| Partial<[Colors](#colors)>   | Color resources of the custom theme. |

## ThemeControl

Implements a **ThemeControl** object to apply the custom theme to the components in the application.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### setDefaultTheme

setDefaultTheme(theme: [CustomTheme](#customtheme)): void

Sets a custom theme as the default, application-level theme so that it is applied to components in the application.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                          | Mandatory | Description            |
|--------------|------------------------------|------|----------------|
| theme | [CustomTheme](#customtheme)  | Yes   | Custom theme to set. |

**Example**

```ts
import { CustomTheme, CustomColors, ThemeControl } from '@kit.ArkUI';
// Custom theme color
class BlueColors implements CustomColors {
  fontPrimary = Color.White;
  backgroundPrimary = Color.Blue;
  brand = Color.Blue; // Brand color
}

class PageCustomTheme implements CustomTheme {
  colors?: CustomColors;

  constructor(colors: CustomColors) {
    this.colors = colors;
  }
}
// Create an instance.
const BlueColorsTheme = new PageCustomTheme(new BlueColors());
// Call ThemeControl.setDefaultTheme before page build to set the default application style to BlueColorsTheme.
ThemeControl.setDefaultTheme(BlueColorsTheme);
```
