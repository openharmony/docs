# Refresh

The **<Refresh\>** component is used to refresh a page through a pull-down gesture.

> **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

None

## Child Components

This component supports only one child component.

## APIs

Refresh\(value: \{refreshing: boolean, offset?: Length, friction?: number | string\}\)

- Parameters

  | Name| Value Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | refreshing | boolean | Yes| - | Whether the current component is being refreshed.|
  | offset | Length | No| 16 | Distance to the top of the parent component from the **<Refresh\>** component that comes to rest after a successful pull-down gesture.|
  | friction | number \| string | No| 62 | Coefficient of friction, which indicates the **<Refresh\>** component's sensitivity to the pull-down gesture. The value ranges from 0 to 100. <br/>- **0** indicates that the **<Refresh\>** component is not sensitive to the pull-down gesture. <br/>- **100** indicates that the **<Refresh\>** component is highly sensitive to the pull-down gesture. <br/>- A larger value indicates a more sensitive response of the **<Refresh\>** component to the pull-down gesture.|



## Events


| Name| Description|
| -------- | -------- |
| onStateChange(callback: (state: RefreshStatus) => void)| Triggered when the refresh status changes. <br/>**state** indicates the refresh status.|
| onRefreshing(callback: () => void)| Triggered when the component enters the refresh state.|

- RefreshStatus enums

  | Name| Description|
  | -------- | -------- |
  | Inactive | The component is not pulled down. This is the default value.|
  | Drag | The component is being pulled down, but the pulled distance is shorter than the minimum length required to trigger the refresh.|
  | OverDrag | The component is being pulled down, and the pulled distance exceeds the minimum length required to trigger the refresh.|
  | Refresh | The pull-down ends, and the component rebounds to the minimum length required to trigger the refresh and enters the refresh state.|
  | Done | The refresh is complete, and the component returns to the initial state (top).|


## Example

```
@Entry
@Component
struct RefreshExample {
  @State isRefreshing: boolean = false
  @State counter: number = 0

  build() {
    Column() {
      Refresh({refreshing: this.isRefreshing, offset: 120, friction: 100}) {
        Text('Pull Down and refresh: ' + this.counter)
          .fontSize(30)
          .margin(10)
      }
      .onStateChange((refreshStatus: RefreshStatus) => {
        console.info('Refresh onStatueChange state is ' + refreshStatus)
      })
      .onRefreshing(() => {
        setTimeout(() => {
          this.counter++
          this.isRefreshing = false
        }, 1000)
        console.log('onRefreshing test')
      })
    }
  }
}
```

![](figures/refresh.gif)
