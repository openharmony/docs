# Opacity
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

You can set the opacity of a component.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## opacity

opacity(value: number | Resource): T

Sets the opacity of the component.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | number&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | Yes  | Component opacity. Value range: 0 to 1. Values less than 0 are treated as 0. Values greater than 1 are treated as 1. **1**: fully opaque. **0**: fully transparent (where the component is hidden but occupies layout space).<br> Default value: **1**.<br>**NOTE**<br> Child components inherit parent opacity and combine with their own opacity. Example: Parent opacity 0.1 x Child opacity 0.8 = Effective opacity 0.08.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| T | Current component.|

## opacity<sup>18+</sup>

opacity(opacity: Optional\<number | Resource>): T

Sets the opacity of the component. Compared with [opacity](#opacity-1), this API supports the **undefined** type for the **opacity** parameter.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| opacity | Optional\<number&nbsp;\|&nbsp;[Resource](ts-types.md#resource)> | Yes  | Component opacity. Value range: 0 to 1. Values less than 0 are treated as 0. Values greater than 1 are treated as 1. **1**: fully opaque. **0**: fully transparent (where the component is hidden but occupies layout space).<br> Default value: **1**.<br>**NOTE**<br> Child components inherit parent opacity and combine with their own opacity. Example: Parent opacity 0.1 x Child opacity 0.8 = Effective opacity 0.08.<br>When **opacity** is **undefined**, the component reverts to the default opacity of **1**.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| T | Current component.|


## Example

This example shows how to set the opacity of a component using **opacity**.

```ts
// xxx.ets
@Entry
@Component
struct OpacityExample {
  build() {
    Column({ space: 5 }) {
      Text('opacity(1)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(1).backgroundColor(0xAFEEEE)
      Text('opacity(0.7)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0.7).backgroundColor(0xAFEEEE)
      Text('opacity(0.4)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0.4).backgroundColor(0xAFEEEE)
      Text('opacity(0.1)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0.1).backgroundColor(0xAFEEEE)
      Text('opacity(0)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0).backgroundColor(0xAFEEEE)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![opacity.png](figures/opacity.png)
