# Navigator


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Navigator&gt;** component provides redirection.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Navigator(value?: {target: string, type?: NavigationType})

Creates a navigator.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | target | string | Yes | - | Path&nbsp;of&nbsp;the&nbsp;target&nbsp;page&nbsp;to&nbsp;be&nbsp;redirected&nbsp;to. | 
  | type | NavigationType | No | NavigationType.Push | Navigation&nbsp;type. | 

- NavigationType enums
    | Name | Description | 
  | -------- | -------- |
  | Push | Navigates&nbsp;to&nbsp;a&nbsp;specified&nbsp;page&nbsp;in&nbsp;the&nbsp;application. | 
  | Replace | Replaces&nbsp;the&nbsp;current&nbsp;page&nbsp;with&nbsp;another&nbsp;one&nbsp;in&nbsp;the&nbsp;application&nbsp;and&nbsp;destroys&nbsp;the&nbsp;current&nbsp;page. | 
  | Back | Returns&nbsp;to&nbsp;the&nbsp;previous&nbsp;page&nbsp;or&nbsp;a&nbsp;specified&nbsp;page. | 


## Attributes

  | Name | Parameters | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| active | boolean | - | Whether&nbsp;the&nbsp;**&lt;Navigator&gt;**&nbsp;component&nbsp;is&nbsp;activated.&nbsp;If&nbsp;the&nbsp;component&nbsp;is&nbsp;activated,&nbsp;the&nbsp;corresponding&nbsp;navigation&nbsp;takes&nbsp;effect. | 
| params | Object | undefined | Data&nbsp;that&nbsp;needs&nbsp;to&nbsp;be&nbsp;passed&nbsp;to&nbsp;the&nbsp;target&nbsp;page&nbsp;during&nbsp;redirection.&nbsp;You&nbsp;can&nbsp;use&nbsp;**router.getParams()**&nbsp;to&nbsp;obtain&nbsp;the&nbsp;data&nbsp;on&nbsp;the&nbsp;target&nbsp;page. | 


## Example

  
```
// Navigator Page
@Entry
@Component
struct NavigatorExample {
  @State active: boolean = false
  @State Text: string = 'news'

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Detail', type: NavigationType.Push }) {
        Text('Go to ' + this.Text + ' page').width('100%').textAlign(TextAlign.Center)
      }.params({ text: this.Text })

      Navigator() {
        Text('Back to previous page').width('100%').textAlign(TextAlign.Center)
      }.active(this.active)
      .onClick(() => {
        this.active = true
      })
    }.height(150).width(350).padding(35)
  }
}
```

  
```
// Detail Page
import router from '@system.router'

@Entry
@Component
struct DetailExample {
  @State text: string = router.getParams().text

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Back', type: NavigationType.Push }) {
        Text('Go to back page').width('100%').height(20)
      }

      Text('This is ' + this.text + ' page').width('100%').textAlign(TextAlign.Center)
    }
    .width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}

```

  
```
// Back Page
@Entry
@Component
struct BackExample {
  build() {
    Column() {
      Navigator({ target: 'pages/container/navigator/Navigator', type: NavigationType.Back }) {
        Text('Return to Navigator Page').width('100%').textAlign(TextAlign.Center)
      }
    }.width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![en-us_image_0000001212058486](figures/en-us_image_0000001212058486.gif)
