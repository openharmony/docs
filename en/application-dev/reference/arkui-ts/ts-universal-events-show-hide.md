# Show/Hide Event

The show/hide event is triggered when a component is mounted or unmounted from the component tree. A component appears when mounted to the component tree and disappears when unmounted from the component tree.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Events

| Name                                            | Bubbling Supported| Description                  |
| ------------------------------------------------ | -------- | -------------------------- |
| onAppear(event: () =&gt; void)    | No      | Triggered when the component is displayed.|
| onDisappear(event: () =&gt; void) | No      | Triggered when the component disappears.|


## Example

```ts
// xxx.ets
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
