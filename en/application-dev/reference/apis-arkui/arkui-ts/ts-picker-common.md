# Picker Common APIs
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @HelloCrease-->

This topic covers the common APIs of picker components.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## PickerTextStyle

Defines the text style configuration for the picker component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type                                    | Read-Only| Optional| Description                     |
| ----- | ---------------------------------------- | ---- | ------------------------- | ------------------------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | No  | Yes  | Text color.                    |
| font  | [Font](ts-types.md#font)                 | No  | Yes  | Text style.|

## PickerDialogButtonStyle<sup>12+</sup>

Defines the picker button style.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type                                    | Read-Only| Optional| Description                     |
| ----- | ---------------------------------------- | ---- | ------------------------- | ------------------------- |
| type | [ButtonType](ts-basic-components-button.md#buttontype) | No  | Yes  | Button type.                    |
| style  | [ButtonStyleMode](ts-basic-components-button.md#buttonstylemode11)                 | No  | Yes  | Style and importance of the button.|
| role | [ButtonRole](ts-basic-components-button.md#buttonrole12) | No  | Yes  | Role of the button.                    |
| fontSize  | [Length](ts-types.md#length)                 | No  | Yes  | Font size of the button.|
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | No  | Yes  | Color of button text.                    |
| fontWeight  | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string| No  | Yes  | Font weight of button text For the number type, the value ranges from 100 to 900, at an interval of 100. A larger value indicates a heavier font weight. For the string type, only strings that represent a number, for example, **"200"**, and the following enumerated values of **FontWeight** are supported: **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**.|
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | No  | Yes  | Font style of button text.                    |
| fontFamily  |  [Resource](ts-types.md#resource) \| string  | No  | Yes  | Font family. The 'HarmonyOS Sans' font and [registered custom fonts](../js-apis-font.md) are supported.|
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | No  | Yes  | Background color of the button.                    |
| borderRadius  | [Length](ts-types.md#length) \| [BorderRadiuses](ts-types.md#borderradiuses9)| No  | Yes  | Corner radius of the button.|
| primary  | boolean | No  | Yes  | Whether the button responds to the **Enter** key by default when the dialog box has focus and the **Tab** key is not pressed for sequential focus navigation.|

## DateRange<sup>19+</sup>

Defines the date range, which specifies the start and end dates.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type      | Read-Only     | Optional  | Description                           |
| ----------- | ---------- | ------| --------------------------------- | --------------------------------- |
| start | Date | No| Yes  | Start date of the date range.|
| end | Date | No  | Yes  | End date of the date range.|
