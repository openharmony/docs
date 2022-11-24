# Visibility

The visibility attribute controls whether a component is visible.

>  **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name        | Type                       | Description                                        |
| ---------- | ---------------------------- | ------------------------------------------ |
| visibility | [Visibility](ts-appendix-enums.md#visibility) | Whether the component is visible.<br>Default value: **Visibility.Visible** |


## Example

```ts
// xxx.ets
@Entry
@Component
struct VisibilityExample {
  build() {
    Column() {
      Column() {
        Text('Visible').fontSize(9).width('90%').fontColor(0xCCCCCC)
        Row().visibility(Visibility.Visible).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('None').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // The component is hidden, and no placeholder is used.
        Row().visibility(Visibility.None).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('Hidden').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // The component is hidden, and a placeholder is used for it in the layout.
        Row().visibility(Visibility.Hidden).width('90%').height(80).backgroundColor(0xAFEEEE)
      }.width('90%').border({ width: 1 })
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001257058421](figures/en-us_image_0000001257058421.gif)
