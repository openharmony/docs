# LoadingProgress

The **\<LoadingProgress>** component is used to create a loading animation.

>  **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

LoadingProgress()

Creates a **\<LoadingProgress>** component.

This API can be used in ArkTS widgets since API version 9.

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | Foreground color of the **\<LoadingProgress>** component.<br>Default value:<br>API version 10 or earlier: **'#99666666'**<br>API version 11 or later: **'#ff666666'**<br>This API can be used in ArkTS widgets since API version 9.|
| enableLoading<sup>10+</sup> | boolean | Whether to show the loading animation.<br>Default value: **true**<br>**NOTE**<br> The component still takes up space in the layout when the loading animation is not shown.<br>Unlike the universal attribute **Visibility.Hidden**, which hides the entire component, including borders and paddings, **enableLoading=false** hides the loading animation only.|

## Events

The [universal events](ts-universal-events-click.md) are supported.

## Example

```ts
// xxx.ets
@Entry
@Component
struct LoadingProgressExample {
  build() {
    Column({ space: 5 }) {
      Text('Orbital LoadingProgress ').fontSize(9).fontColor(0xCCCCCC).width('90%')
      LoadingProgress()
        .color(Color.Blue)
        .layoutWeight(1)
    }.width('100%').margin({ top: 5 })
  }
}
```

![LoadingProgress](figures/LoadingProgress.gif)
