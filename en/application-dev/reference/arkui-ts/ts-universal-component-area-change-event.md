# Component Area Change Event


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

  | Name | Bubble Supported | Description | 
| -------- | -------- | -------- |
| onAreaChange(event: (oldValue: Area, newValue: Area) =&gt; void) | No | Triggered when the component area changes. For details about the **Area** type, see **Area** attributes. | 


## Example


```
@Entry
@Component
struct AreaExample {
  @State value: string = 'Text'
  @State size: string = ''

  build() {
    Column() {
      Text(this.value)
        .backgroundColor(Color.Green).margin(30).fontSize(20)
        .onClick(() => {
          this.value = this.value + 'Text'
        })
        .onAreaChange((oldValue: Area, newValue: Area) => {
          console.info(`Ace: on area change, oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
          this.size = JSON.stringify(newValue)
        })
      Text('new area is: \n' + this.size).margin({ right: 30, left: 30 })
    }
    .width('100%').height('100%').margin({ top: 30 })
  }
}
```

![en-us_image_0000001257058403](figures/en-us_image_0000001257058403.gif)
