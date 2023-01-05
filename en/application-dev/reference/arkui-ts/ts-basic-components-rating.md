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
  @State rating: number = 1
  @State indicator: boolean = false

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('current score is ' + this.rating).fontSize(20)
      Rating({ rating: this.rating, indicator: this.indicator })
        .stars(5)
        .stepSize(0.5)
        .onChange((value: number) => {
          this.rating = value
        })
    }.width(350).height(200).padding(35)
  }
}
```

![en-us_image_0000001257058423](figures/en-us_image_0000001257058423.gif)
