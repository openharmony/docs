# Transition of Shared Elements


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This animationis supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


Shared element transition can be used for transition between pages, for example, transition from an image on the current page to the next page.


## Type

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| sharedTransition | id:&nbsp;string,<br/>options?:&nbsp;Object | - | If&nbsp;the&nbsp;same&nbsp;ID&nbsp;is&nbsp;configured&nbsp;for&nbsp;a&nbsp;component&nbsp;on&nbsp;the&nbsp;two&nbsp;pages,&nbsp;this&nbsp;shared&nbsp;component&nbsp;is&nbsp;transited.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;set&nbsp;to&nbsp;an&nbsp;empty&nbsp;string,&nbsp;no&nbsp;shared&nbsp;elements&nbsp;are&nbsp;transited. | 

- options parameters
    | Name | Type | Default&nbsp;Value | Mandatory | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | duration | number | 1000 | No | Animation&nbsp;duration,&nbsp;in&nbsp;ms.&nbsp;The&nbsp;default&nbsp;duration&nbsp;is&nbsp;1000&nbsp;ms. | 
  | curve | Curve&nbsp;\|&nbsp;Curves | Linear | No | The&nbsp;default&nbsp;curve&nbsp;is&nbsp;linear.&nbsp;For&nbsp;details&nbsp;about&nbsp;the&nbsp;valid&nbsp;values,&nbsp;see&nbsp;**Curve&nbsp;enums**. | 
  | delay | number | 0 | No | Delay&nbsp;of&nbsp;animation&nbsp;playback,&nbsp;in&nbsp;ms.&nbsp;By&nbsp;default,&nbsp;the&nbsp;playback&nbsp;is&nbsp;not&nbsp;delayed. | 


## Example

The example shows the transition of a shared element from a page and page B.

  
```
@Entry
@Component
struct SharedTransitionExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    List() {
      ListItem() {
        Row() {
          Navigator({ target: 'pages/common/Animation/transAnimation/PageB', type: NavigationType.Push }) {
            Image($r('app.media.ic_health_heart')).width(50).height(50)
              .sharedTransition('sharedImage1', { duration: 800, curve: Curve.Linear, delay: 100 })
          }.padding({ left: 10 })
          .onClick(() => {
            this.active = true
          })

          Text('SharedTransition').width(80).height(80).textAlign(TextAlign.Center)
        }
      }
    }
  }
}
```

  
```
// PageB
@Entry
@Component
struct BExample {
  build() {
    Stack() {
      Image($r('app.media.ic_health_heart')).width(150).height(150).sharedTransition('sharedImage1')
    }.width('100%').height(400)
  }
}
```

![en-us_image_0000001211898494](figures/en-us_image_0000001211898494.gif)
