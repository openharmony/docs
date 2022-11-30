# Show/Hide Event

The show/hide event is triggered when a component is mounted or unmounted from the component tree. A component appears when mounted to the component tree and disappears when unmounted from the component tree.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Events

| Name                                            | Bubbling Supported| Description                  |
| ------------------------------------------------ | -------- | -------------------------- |
| onAppear(event: () =&gt; void)    | No      | Triggered when the component is displayed.|
| onDisappear(event: () =&gt; void) | No      | Triggered when the component is hidden. |


## Example

```ts
// xxx.ets
import prompt from '@ohos.prompt'

@Entry
@Component
struct AppearExample {
  @State isShow: boolean = true
  @State changeAppear: string = 'Hide Text'
  private myText: string = 'Text for onAppear'

  build() {
    Column() {
      Button(this.changeAppear)
        .onClick(() => {
          this.isShow = !this.isShow
        }).margin(15)
      if (this.isShow) {
        Text(this.myText).fontSize(26).fontWeight(FontWeight.Bold)
          .onAppear(() => {
            this.changeAppear = 'Hide Text'
            prompt.showToast({
              message: 'The text is shown',
              duration: 2000
            })
          })
          .onDisAppear(() => {
            this.changeAppear = 'Show Text'
            prompt.showToast({
              message: 'The text is hidden',
              duration: 2000
            })
          })
      }
    }.padding(30).width('100%')
  }
}
```

![en-us_image_0000001219864151](figures/en-us_image_0000001219864151.gif)
