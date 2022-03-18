# Stepper


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Stepper&gt;** component provides a step navigator.


## Required Permissions

None


## Child Components

Only the child component **&lt;[StepperItem](ts-basic-components-stepperitem.md)&gt;** is supported.


## APIs

Stepper(value?: { index?: number })


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | index | number | No | 0 | Index&nbsp;of&nbsp;the&nbsp;**&lt;StepperItem&gt;**&nbsp;that&nbsp;is&nbsp;currently&nbsp;displayed. | 


## Attributes

None


## Events

  | Name | Description | 
| -------- | -------- |
| onFinish(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;**nextLabel**&nbsp;of&nbsp;the&nbsp;last&nbsp;**&lt;StepperItem&gt;**&nbsp;in&nbsp;the&nbsp;**&lt;Stepper&gt;**&nbsp;is&nbsp;clicked. | 
| onSkip(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;current&nbsp;**&lt;StepperItem&gt;**&nbsp;is&nbsp;**ItemState.Skip**&nbsp;and&nbsp;the&nbsp;**nextLabel**&nbsp;is&nbsp;clicked. | 
| onChange(callback:&nbsp;(prevIndex?:&nbsp;number,&nbsp;index?:&nbsp;number)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;text&nbsp;button&nbsp;on&nbsp;the&nbsp;left&nbsp;or&nbsp;right&nbsp;is&nbsp;clicked&nbsp;to&nbsp;switch&nbsp;between&nbsp;steps.<br/>-&nbsp;**prevIndex**:&nbsp;index&nbsp;of&nbsp;the&nbsp;step&nbsp;page&nbsp;before&nbsp;the&nbsp;switching.<br/>-&nbsp;**index**:&nbsp;index&nbsp;of&nbsp;the&nbsp;step&nbsp;page&nbsp;after&nbsp;the&nbsp;switching,&nbsp;that&nbsp;is,&nbsp;index&nbsp;of&nbsp;the&nbsp;previous&nbsp;or&nbsp;next&nbsp;page. | 


## Example



```
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
          .margin({top:250})
      }
      .nextLabel('')
      .position({x: '35%', y: 0})
      StepperItem() {
        Text('Page Two')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({top:250})
          .onClick(()=>{
            this.firstState = this.firstState === ItemState.Skip ? ItemState.Normal : ItemState.Skip
          })
      }
      .nextLabel('Next')
      .prevLabel('Previous')
      .status(this.firstState)
      .position({x: '35%', y: 0})
      StepperItem() {
        Text('Page Three')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({top:250})
          .onClick(()=>{
            this.secondState = this.secondState === ItemState.Waiting ? ItemState.Normal : ItemState.Waiting
          })
      }
      .position({x: '35%', y: 0})
      .status(this.secondState)
      StepperItem() {
        Text('Page four')
          .fontSize(35)
          .fontColor(Color.Blue)
          .width(200)
          .lineHeight(50)
          .margin({top:250})
      }
      .position({x: '35%', y: 0})
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

