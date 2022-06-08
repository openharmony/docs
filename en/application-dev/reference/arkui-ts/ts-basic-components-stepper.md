# Stepper


> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Stepper&gt;** component provides a step navigator.


## Required Permissions

None


## Child Components

Only the child component **&lt;[StepperItem](ts-basic-components-stepperitem.md)&gt;** is supported.


## APIs

Stepper(value?: { index?: number })


- Parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | index | number | No | 0 | Index of the **&lt;StepperItem&gt;** that is currently displayed. | 


## Attributes

None


## Events

| Name | Description | 
| -------- | -------- |
| onFinish(callback: () =&gt; void) | Invoked when the **nextLabel** of the last **&lt;StepperItem&gt;** in the **&lt;Stepper&gt;** is clicked. | 
| onSkip(callback: () =&gt; void) | Invoked when the current **&lt;StepperItem&gt;** is **ItemState.Skip** and the **nextLabel** is clicked. | 
| onChange(callback: (prevIndex?: number, index?: number) =&gt; void) | Invoked when the text button on the left or right is clicked to switch between steps.<br/>- **prevIndex**: index of the step page before the switching.<br/>- **index**: index of the step page after the switching, that is, index of the previous or next page. | 


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

