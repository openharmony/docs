# Rating


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Rating&gt;** component provides a rating bar.


## Required Permissions

None


## Child Components

None


## APIs

Rating(options?: { rating: number, indicator?: boolean })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | rating | number | Yes | 0 | Value&nbsp;to&nbsp;rate. | 
  | indicator | boolean | No | false | Used&nbsp;only&nbsp;as&nbsp;an&nbsp;indicator&nbsp;and&nbsp;cannot&nbsp;be&nbsp;operated. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| stars | number | 5 | Total&nbsp;number&nbsp;of&nbsp;stars. | 
| stepSize | number | 0.5 | Step&nbsp;of&nbsp;an&nbsp;operation. | 
| starStyle | {<br/>backgroundUri:&nbsp;string,<br/>foregroundUri:&nbsp;string,<br/>secondaryUri?:&nbsp;string<br/>} | - | **backgroundSrc**:&nbsp;image&nbsp;link&nbsp;of&nbsp;the&nbsp;unselected&nbsp;star.&nbsp;You&nbsp;can&nbsp;customize&nbsp;the&nbsp;image&nbsp;or&nbsp;use&nbsp;the&nbsp;default&nbsp;image.&nbsp;Only&nbsp;local&nbsp;images&nbsp;are&nbsp;supported.<br/>**foregroundSrc**:&nbsp;image&nbsp;path&nbsp;of&nbsp;the&nbsp;selected&nbsp;star.&nbsp;You&nbsp;can&nbsp;customize&nbsp;the&nbsp;image&nbsp;or&nbsp;use&nbsp;the&nbsp;default&nbsp;image.&nbsp;Only&nbsp;local&nbsp;images&nbsp;are&nbsp;supported.<br/>**secondarySrc**:&nbsp;image&nbsp;path&nbsp;of&nbsp;the&nbsp;partially&nbsp;selected&nbsp;star.&nbsp;You&nbsp;can&nbsp;customize&nbsp;the&nbsp;image&nbsp;or&nbsp;use&nbsp;the&nbsp;default&nbsp;image.&nbsp;Only&nbsp;local&nbsp;images&nbsp;are&nbsp;supported. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(callback:(value:&nbsp;number)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;rating&nbsp;value&nbsp;changes. | 


## Example


```
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
