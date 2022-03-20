# Show/Hide Event


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

  | Name | Bubble Supported | Description | 
| -------- | -------- | -------- |
| onAppear(callback: () =&gt; void) | No | Called when the component is displayed. | 
| onDisappear(callback: () =&gt; void) | No | Called when the component disappears. | 


## Example


```
import prompt from '@system.prompt'

@Entry
@Component
struct AppearExample {
  @State isShow: boolean = true
  private myText: string = 'Text for onAppear'
  private changeAppear: string = 'Hide Text'

  build() {
    Column() {
      Button(this.changeAppear)
        .onClick(() => {
          this.isShow = !this.isShow
        }).margin(3).backgroundColor(0x2788D9)
      if (this.isShow) {
        Text(this.myText)
          .onAppear(() => {
            this.changeAppear = 'Show Text'
            prompt.showToast({ message: 'The text is shown', duration: 2000 })
          })
          .onDisAppear(() => {
            this.changeAppear = 'Hide Text'
            prompt.showToast({ message: 'The text is hidden', duration: 2000 })
          })
      }
    }.padding(30).width('100%')
  }
}
```

![en-us_image_0000001211898468](figures/en-us_image_0000001211898468.gif)
