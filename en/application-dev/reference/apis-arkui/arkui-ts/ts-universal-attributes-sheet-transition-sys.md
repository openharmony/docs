# Sheet Transition (System API)

You can bind a sheet to a component through the **bindSheet** attribute. You can also set the sheet to the preset or custom height for when the component is inserted.

>  **NOTE**
>
>  This feature is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
>  Route hopping is not supported.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [bindSheet](./ts-universal-attributes-sheet-transition.md#bindsheet).

## SheetOptions

Optional attributes of the sheet. Inherits from [BindOptions](./ts-universal-attributes-sheet-transition.md#bindoptions).

| Name             | Type                                      | Mandatory  | Description             |
| --------------- | ---------------------------------------- | ---- | --------------- |
| offset<sup>14+</sup>       | [Position](ts-types.md#position) | Yes   | Bottom spacing, which is effective only when the sheet is a bottom sheet. When it is specified, the height detent cannot be set for the sheet.<br> Default value: 0 vp for both the x-axis and y-axis<br>**System API**: This is a system API.<br> **System capability**: SystemCapability.ArkUI.ArkUI.Full|
