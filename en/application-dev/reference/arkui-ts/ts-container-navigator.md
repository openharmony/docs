# Navigator


> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **\<Navigator>** component provides redirection to the target page.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Navigator(value?: {target: string, type?: NavigationType})

Creates a navigator.

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | target | string | Yes | - | Path of the target page to be redirected to. |
  | type | NavigationType | No | NavigationType.Push | Navigation type. |

- NavigationType enums
  | Name | Description |
  | -------- | -------- |
  | Push | Navigates to a specified page in the application. |
  | Replace | Replaces the current page with another one in the application and destroys the current page. |
  | Back | Returns to the previous page or a specified page. |


## Attributes

| Name | Parameters | Default Value | Description |
| -------- | -------- | -------- | -------- |
| active | boolean | - | Whether the **\<Navigator>** component is activated. If the component is activated, the corresponding navigation takes effect. |
| params | Object | undefined | Data that needs to be passed to the target page during redirection. You can use **router.getParams()** to obtain the data on the target page. |


## Example


```ts
// Navigator.ets
@Entry
@Component
struct NavigatorExample {
  @State active: boolean = false
  @State Text: object = {name: 'news'}

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Detail', type: NavigationType.Push }) {
        Text('Go to ' + this.Text['name'] + ' page')
            .width('100%').textAlign(TextAlign.Center)
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


```ts
// Detail.ets
import router from '@system.router'

@Entry
@Component
struct DetailExample {
  @State text: any = router.getParams().text

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Back', type: NavigationType.Push }) {
        Text('Go to back page').width('100%').height(20)
      }

      Text('This is ' + this.text['name'] + ' page')
          .width('100%').textAlign(TextAlign.Center)
    }
    .width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}

```

```ts
// Back.ets
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
