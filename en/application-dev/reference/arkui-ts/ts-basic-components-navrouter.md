# NavRouter

The **\<NavRouter>** component provides default logic for click response processing, eliminating the need for manual logic definition.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

This component must contain two child components, the second of which must be **[\<NavDestination>](ts-basic-components-navdestination.md)**.

## APIs

NavRouter()


## Events

| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onStateChange(callback: (isActivated: boolean) => void) | Invoked when the component activation status changes. The value **true** means that component is activated, and **false** means the opposite.<br> **NOTE**<br>After the user clicks **NavRouter**, if the **\<NavRouter>** component is activated and the corresponding **\<NavDestination>** child component loaded, **onStateChange(true)** is called. If the corresponding **\<NavDestination>** child component is no longer displayed, **onStateChange(false)** is called. |

## Example

```ts
// xxx.ets
@Entry
@Component
struct NavRouterExample {
  private arr: number[] = [0, 1, 2, 3]
  @State isActive: boolean = false
  @State dex: number = 0

  build() {
    Column() {
      Navigation() {
        List({ space: 12, initialIndex: 0 }) {
          ForEach(this.arr, (item: number, index: number) => {
            ListItem() {
              NavRouter() {
                Row() {
                  Image($r('app.media.icon')).width(30).height(30).borderRadius(30).margin({ left: 3, right: 10 })
                  Text(`NavRouter${item + 1}`)
                    .fontSize(22)
                    .fontWeight(500)
                    .textAlign(TextAlign.Center)
                }
                .width(180)
                .height(72)
                .backgroundColor(this.dex === index ? '#ccc' : '#fff')
                .borderRadius(24)

                NavDestination() {
                  Text (`I am NavDestination page ${item + 1}`).fontSize (50)
                  Flex({ direction: FlexDirection.Row }) {
                    Row() {
                      Image($r('app.media.icon')).width(40).height(40).borderRadius(40).margin({ right: 15 })
                      Text('7 classes today').fontSize(30)
                    }.padding({ left: 15 })
                  }
                }.backgroundColor('#ccc')
                .title(`NavDestination${item + 1}`)
              }.onStateChange((isActivated: boolean) => {
                this.dex = index
              })
            }
          }, item => item)
        }
        .height('100%')
        .margin({ top: 12, left: 12 })
      }
      .mode(NavigationMode.Split)
      .hideTitleBar(true)
      .hideToolBar(true)
    }.height('100%')
  }
}
```
