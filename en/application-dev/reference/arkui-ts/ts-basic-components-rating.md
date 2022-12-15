# Rating

The **\<Rating>** component provides a rating bar.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Rating(options?: { rating: number, indicator?: boolean })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rating | number | Yes| Value to rate.<br>Default value: **0**|
| indicator | boolean | No| Whether the component is used only as an indicator and cannot be operated.<br>Default value: **false**|


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| stars | number | Total number of stars.<br>Default value: **5**|
| stepSize | number | Step of an operation.<br>Default value: **0.5**|
| starStyle | {<br>backgroundUri: string,<br>foregroundUri: string,<br>secondaryUri?: string<br>} | **backgroundUri**: image link of the unselected star. You can use the default image or a custom local image.<br>**foregroundUri**: image path of the selected star. You can use the default image or a custom local image.<br>**secondaryUir**: image path of the partially selected star. You can use the default image or a custom local image.|


## Events

| Name| Description|
| -------- | -------- |
| onChange(callback:(value: number) =&gt; void) | Triggered when the rating value changes.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct RatingExample {
  @State rating: number = 3.5

  build() {
    Column() {
      Column() {
        Rating({ rating: this.rating, indicator: false })
          .stars(5)
          .stepSize(0.5)
          .margin({ top: 24 })
          .onChange((value: number) => {
            this.rating = value
          })
        Text('current score is ' + this.rating)
          .fontSize(16)
          .fontColor('rgba(24,36,49,0.60)')
          .margin({ top: 16 })
      }.width(360).height(113).backgroundColor('#FFFFFF').margin({ top: 68 })

      Row() {
        Image('common/testImage.jpg')
          .width(40)
          .height(40)
          .borderRadius(20)
          .margin({ left: 24 })
        Column() {
          Text('Yue')
            .fontSize(16)
            .fontColor('#182431')
            .fontWeight(500)
          Row() {
            Rating({ rating: 3.5, indicator: true }).margin({ top: 1, right: 8 })
            Text('2021/06/02')
              .fontSize(10)
              .fontColor('#182431')
          }
        }.margin({ left: 12 }).alignItems(HorizontalAlign.Start)

        Text('1st Floor')
          .fontSize(10)
          .fontColor('#182431')
          .position({ x: 295, y: 8 })
      }.width(360).height(56).backgroundColor('#FFFFFF').margin({ top: 64 })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![rating](figures/rating.gif)
