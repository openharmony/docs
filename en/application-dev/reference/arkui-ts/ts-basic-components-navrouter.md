# NavRouter

The **\<NavRouter>** component provides default processing logic for responding to clicks, eliminating the need for manual logic definition.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

This component must contain two child components, the second of which must be **[\<NavDestination>](ts-basic-components-navdestination.md)**.

> **NOTE**
>
>  
> 1. If there is only one child component, the navigation to the **\<NavDestination>** component does not work.
> 2. If there is only the **\<NavDestination>** child component, the navigation does not work.
> 3. If there are more than two child components, the excess child components are not displayed.
> 4. If the second child component is not **\<NavDestination>**, the navigation does not work.

## APIs

### NavRouter

NavRouter()

### NavRouter<sup>10+</sup>

NavRouter(value: RouteInfo)

Provides route information so that clicking the **\<NavRouter>** component redirects the user to the specified navigation destination page.


**Parameters**

| Name    | Type                               | Mandatory  | Description         |
| ------- | ----------------------------------- | ---- | ------------- |
| value   | [RouteInfo](#routeinfo10) | No   | Route information.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                           | Type                                    | Description                                      |
| ----------------------------- | ---------------------------------------- | ---------------------------------------- |
| mode                  | [NavRouteMode](#navroutemode)                                  | Route mode used for redirection.<br>Default value: **NavRouteMode.PUSH_WITH_RECREATE**|

## RouteInfo<sup>10+</sup>

| Name                | Type                                                    | Mandatory| Description                                                        |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| name             | string            | Yes  | Name of the navigation destination page to be redirected to.|
| param             | unknown            | No  | Parameter transferred during redirection.|

## NavRouteMode

| Name   | Description              |
| ----- | ---------------- |
| PUSH_WITH_RECREATE | The new navigation destination page replaces the current one. The current page is destroyed, but the information about this page is retained in the navigation stack.|
| PUSH   | The new navigation destination page overwrites the current one. The current page is not destroyed, and the information about this page is retained in the navigation stack.|
| REPLACE   | The new navigation destination page replaces the current one. The current page is destroyed, and the information about this page is removed from the navigation stack.|

## Events

| Name                                                   | Description                                                    |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| onStateChange(callback: (isActivated: boolean) => void) | Called when the component activation status changes. The value **true** means that component is activated, and **false** means the opposite.<br>**NOTE**<br>**onStateChange(true)** is called when the **\<NavRouter>** component is activated and its **\<NavDestination>** child component is loaded. **onStateChange(false)** is called when the **\<NavDestination>** child component is not displayed.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct NavRouterExample {
  private arr: number[] = [0, 1, 2, 3]
  @State isActive: boolean = false
  @State dex: number = -1

  build() {
    Column() {
      Navigation() {
        List({ space: 12, initialIndex: 0 }) {
          ForEach(this.arr, (item: number, index: number = 0) => {
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
                if(isActivated) {
                  this.dex = index;
                }
              })
            }
          }, (item:number) => item.toString())
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
