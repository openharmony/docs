# RichEditor (System API)

**RichEditor** is a component that supports interactive text editing and mixture of text and imagery.

>  **NOTE**
>
>  This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
>  This topic describes only system APIs provided by the module. For details about its public APIs, see [RichEditor](ts-basic-components-richeditor.md).
> 
## RichEditorBuilderSpanOptions<sup>11+</sup>

Defines the options for adding a builder span.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type    | Mandatory  | Description                                   |
| ------ | ------ | ---- | ------------------------------------- |
| dragBackgroundColor<sup>18+</sup> | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No   | Background color of the builder when it is dragged independently. If no valid value is specified, the default color is used. |
| isDragShadowNeeded<sup>18+</sup> | boolean | No   | Whether to apply a shadow when the builder is dragged independently. If no valid value is specified, a shadow is applied.|

## RichEditorGesture<sup>11+</sup>

Defines the callback for user interactions.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name         | Type        | Mandatory  | Description           |
| ----------- | ---------- | ---- | ------------- |
| onDoubleClick<sup>14+</sup> | Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent)\>  | No   | Callback for double-click events.<br>**Atomic service API**: This API can be used in atomic services since API version 14. |

