# Text Component Common APIs (System API)

This topic covers the common APIs of text components.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  This topic describes only the system APIs provided by the module. For details about its public APIs, see [Basic Types](ts-types.md) and [Text Component Common APIs](ts-text-common.md).

## TextContentControllerBase

Represents the base controller for **TextInput**, **TextArea**, and **Search** components.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getText<sup>19+</sup>

getText(range?: TextRange): string

Obtains the text content within a specified range.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory  | Description |
| ------- | ------ | ---- | ----- |
| range | [TextRange](ts-text-common.md#textrange12) | No   | Range of the text content to obtain, defined by start and end positions.<br>If the range is not specified, the entire text is obtained by default. If the start position is not specified, it defaults to index 0. If the end position is not specified, it defaults to the end of the text.|

**Return value**

| Type   | Description              |
| ------ | ---------------- |
| string | Text content within the specified range.|

## KeyboardGradientMode<sup>20+</sup>

Enumerates keyboard gradient effects.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                                | Value| Description                                      |
| ---------------------------------- | --- | ---------------------------------------- |
| NONE | 0 | No gradient effect.|
| LINEAR_GRADIENT | 1 | Linear gradient effect.|

## KeyboardFluidLightMode<sup>20+</sup>

Enumerates keyboard fluid lighting effects.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                                | Value| Description                                      |
| ---------------------------------- | --- | ---------------------------------------- |
| NONE | 0 | No fluid lighting effect.|
| BACKGROUND_FLUID_LIGHT | 1 | Background fluid lighting effect enabled.|

## KeyboardAppearanceConfig<sup>20+</sup>

Describes the keyboard visual style configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Mandatory| Description                                                   |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| gradientMode  | [KeyboardGradientMode](#keyboardgradientmode20) | No  | Keyboard gradient effect.<br>Default value: **KeyboardGradientMode.NONE**.|
| fluidLightMode  | [KeyboardFluidLightMode](#keyboardfluidlightmode20) | No  | Keyboard fluid lighting effect.<br>Default value: **KeyboardFluidLightMode.NONE**.|
