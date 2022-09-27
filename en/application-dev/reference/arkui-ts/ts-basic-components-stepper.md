# Stepper

The **\<Stepper>** component provides a step navigator.


>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Only the child component **\<[StepperItem](ts-basic-components-stepperitem.md)>** is supported.


## APIs

Stepper(value?: { index?: number })

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | No| Index of the **\<StepperItem>** that is currently displayed.<br>Default value: **0** |


## Attributes

None


## Events

| Name| Description|
| -------- | -------- |
| onFinish(callback: () =&gt; void) | Invoked when the **nextLabel** of the last **\<StepperItem>** in the **\<Stepper>** is clicked. |
| onSkip(callback: () =&gt; void) | Invoked when the current **\<StepperItem>** is **ItemState.Skip** and the **nextLabel** is clicked. |
| onChange(callback: (prevIndex?: number, index?: number) =&gt; void) | Invoked when the text button on the left or right is clicked to switch between steps.<br>- **prevIndex**: index of the step page before the switching.<br>- **index**: index of the step page after the switching, that is, index of the previous or next page. |
| onNext(callback: (index?: number, pendingIndex?: number) =&gt; void) | Invoked when a user switches to the next step.<br>- **index**: index of the current step page.<br>- **pendingIndex**: index of the next page. |
| onPrevious(callback: (index?: number, pendingIndex?: number) =&gt; void) | Invoked when a user switches to the previous step.<br>- **index**: index of the current step page.<br>- **pendingIndex**: index of the previous page. |


## Example

```ts
// xxx.ets
@Entry
@Component
struct StepperExample {
  @State currentIndex: number = 0
  @State firstState: ItemState = ItemState.Normal
  @State secondState: ItemState = ItemState.Normal

  build() {
    Stepper({
      index: this.currentIndex
    }) {
      StepperItem() {
        Text('Page One')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({ top: 250 })
      }
      .nextLabel('')
      .position({ x: '35%', y: 0 })

      StepperItem() {
        Text('Page Two')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({ top: 250 })
          .onClick(() => {
            this.firstState = this.firstState === ItemState.Skip ? ItemState.Normal : ItemState.Skip
          })
      }
      .nextLabel('Next')
      .prevLabel('Previous')
      .status(this.firstState)
      .position({ x: '35%', y: 0 })

      StepperItem() {
        Text('Page Three')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({ top: 250 })
          .onClick(() => {
            this.secondState = this.secondState === ItemState.Waiting ? ItemState.Normal : ItemState.Waiting
          })
      }
      .position({ x: '35%', y: 0 })
      .status(this.secondState)

      StepperItem() {
        Text('Page four')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({ top: 250 })
      }
      .position({ x: '35%', y: 0 })
      .nextLabel('Finish')
    }
    .onFinish(() => {
      console.log('onFinish')
    })
    .onSkip(() => {
      console.log('onSkip')
    })
    .onChange((prevIndex: number, index: number) => {
      this.currentIndex = index
    })
    .align(Alignment.Center)
  }
}
```


![en-us_image_0000001250678457](figures/en-us_image_0000001250678457.gif)
