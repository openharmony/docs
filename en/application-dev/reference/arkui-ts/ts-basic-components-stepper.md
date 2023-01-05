# Stepper

The **\<Stepper>** component provides a step navigator.


>  **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Only the child component **\<[StepperItem](ts-basic-components-stepperitem.md)>** is supported.


## APIs

Stepper(value?: { index?: number })


**Parameters**

| Name| Type| Mandatory | Description|
| ------| -------- | --------------- | -------- |
| index | number   | No| Index of the **\<StepperItem>** that is currently displayed.<br>Default value: **0**|


## Attributes

None


## Events

| Name| Description|
| -------- | -------- |
| onFinish(callback: () =&gt; void) | Invoked when the **nextLabel** of the last **\<StepperItem>** in the **\<Stepper>** is clicked.|
| onSkip(callback: () =&gt; void) | Invoked when the current **\<StepperItem>** is **ItemState.Skip** and the **nextLabel** is clicked.|
| onChange(callback: (prevIndex?: number, index?: number) =&gt; void) | Invoked when the user switches to the previous or next step.<br>- **prevIndex**: index of the step page before the switching.<br>- **index**: index of the step page after the switching, that is, index of the previous or next page.|
| onNext(callback: (index?: number, pendingIndex?: number) =&gt; void) | Invoked when a user switches to the next step.<br>- **index**: index of the current step page.<br>- **pendingIndex**: index of the next page.|
| onPrevious(callback: (index?: number, pendingIndex?: number) =&gt; void) | Invoked when a user switches to the previous step.<br>- **index**: index of the current step page.<br>- **pendingIndex**: index of the previous page.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct StepperExample {
  @State currentIndex: number = 0;
  @State firstState: ItemState = ItemState.Normal;
  @State secondState: ItemState = ItemState.Normal;
  @State thirdState: ItemState = ItemState.Normal;

  build() {
    Stepper({
      index: this.currentIndex
    }) {
      // First step page
      StepperItem() {
        Column() {
          Text('Page One')
            .fontSize(35)
            .fontColor(Color.Blue)
            .lineHeight(50)
            .margin({ top: 250, bottom: 50 })
          Button('change status:' + this.firstState)
            .onClick(() => {
              this.firstState = this.firstState === ItemState.Skip ? ItemState.Normal : ItemState.Skip;
            })
        }.width('100%')
      }
      .nextLabel('Next')
      .status(this.firstState)
      // Second step page
      StepperItem() {
        Column() {
          Text('Page Two')
            .fontSize(35)
            .fontColor(Color.Blue)
            .lineHeight(50)
            .margin({ top: 250, bottom: 50 })
          Button('change status:' + this.secondState)
            .onClick(() => {
              this.secondState = this.secondState === ItemState.Disabled ? ItemState.Normal : ItemState.Disabled;
            })
        }.width('100%')
      }
      .nextLabel('Next')
      .prevLabel('Previous')
      .status(this.secondState)
      // Third step page
      StepperItem() {
        Column() {
          Text('Page Three')
            .fontSize(35)
            .fontColor(Color.Blue)
            .lineHeight(50)
            .margin({ top: 250, bottom: 50 })
          Button('change status:' + this.thirdState)
            .onClick(() => {
              this.thirdState = this.thirdState === ItemState.Waiting ? ItemState.Normal : ItemState.Waiting;
            })
        }.width('100%')
      }
      .status(this.thirdState)
      // Fourth step page
      StepperItem() {
        Text('Page four')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width('100%')
          .textAlign(TextAlign.Center)
          .lineHeight(50)
          .margin({ top: 250 })
      }
      .nextLabel('Finish')
    }
    .onFinish(() => {
      // Define the processing logic for when Finish on the last page is clicked, for example, redirection.
      console.info('onFinish');
    })
    .onSkip(() => {
      // Define the processing logic for when Skip on the page is clicked, for example, dynamically changing the index of the <Stepper> to redirect to a specific step.
      console.info('onSkip');
    })
    .onChange((prevIndex: number, index: number) => {
      this.currentIndex = index;
    })
  }
}
```


![en-us_image_0000001250678457](figures/en-us_image_0000001250678457.gif)
