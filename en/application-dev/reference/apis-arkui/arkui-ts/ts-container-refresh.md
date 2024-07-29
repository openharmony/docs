# Refresh

 The **\<Refresh>** component is a container that provides the pull-to-refresh feature.

>  **NOTE**
>
>  - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
>  - This component provides linkage with a vertical scrolling **Swiper** and **Web** component since API version 12. The linkage does not work if the **loop** attribute of **Swiper** is set to **true**.

## Child Components

This component supports only one child component.

Since API version 11, this component's child component moves down with the pull-down gesture.

## APIs

Refresh(value: RefreshOptions)

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Value Type| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value |  [RefreshOptions](#refreshoptions)| Yes| Parameters of the **\<Refresh>** component.|

## RefreshOptions

| Name        | Value Type                                     | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| refreshing | boolean                                  | Yes   | Whether the current component is being refreshed.<br>Default value: **false**<br>This parameter supports two-way binding through [$$](../../../quick-start/arkts-two-way-sync.md).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| offset<sup>(deprecated)</sup>    | string \| number               | No   | Distance from the pull-down starting point to the top of the component.<br>Default value: **16**, in vp<br>This API is deprecated since API version 11. No substitute API is provided.<br>**NOTE**<br>The value range of **offset** is [0vp, 64vp]. If the value is greater than 64 vp, the value 64 vp will be used. The value cannot be a percentage or a negative number.|
| friction<sup>(deprecated)</sup>   | number \| string               | No   | Coefficient of friction, which indicates the **<Refresh\>** component's sensitivity to the pull-down gesture. The value ranges from 0 to 100.<br>Default value: **62**<br>- **0** indicates that the **\<Refresh>** component is not sensitive to the pull-down gesture.<br>- **100** indicates that the **\<Refresh>** component is highly sensitive to the pull-down gesture.<br>- A larger value indicates a more sensitive response of the **\<Refresh>** component to the pull-down gesture.<br>This API is deprecated since API version 11. No substitute API is provided.|
| builder<sup>10+</sup>    | [CustomBuilder](ts-types.md#custombuilder8) | No   | Component with a custom refresh style set for the pull-down gesture.<br>**NOTE**<br>In API version 10 and earlier versions, there is a height limit of 64 vp on custom components. This restriction is removed since API version 11.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| promptText<sup>12+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Text displayed at the bottom of the component.<br>**NOTE**<br>For details about the restrictions on the text, see the Text component. When the builder is used to customize the refresh style, promptText is not displayed.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

### refreshOffset<sup>12+</sup>

refreshOffset(value: number)

Sets the pull-down offset that initiates a refresh.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Value Type| Type                                       | Mandatory| Description                                                      |
| ------ | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| value  | number |  Yes| Pull-down offset, in vp.<br>Default value: 64 vp<br>If the value specified is 0 or less than 0, the default value is used.
### pullToRefresh<sup>12+</sup>

pullToRefresh(value: boolean)

Sets whether to initiate a refresh when the pull-down distance exceeds the value of **refreshOffset**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Value Type| Type                                       | Mandatory| Description                                                      |
| ------ | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| value  | boolean |  Yes| Whether to initiate a refresh.<br>Default value: **true**|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onStateChange

onStateChange(callback: (state: RefreshStatus) => void)

Called when the refresh status changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Value Type| Type                                   | Mandatory| Description      |
| ------ | --------------------------------------- | ---- | ---------- |
| state  | [RefreshStatus](#refreshstatus) | Yes  | Refresh status.|

### onRefreshing

onRefreshing(callback: () => void)

Called when the component starts refreshing.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onOffsetChange<sup>12+</sup>

onOffsetChange(callback: Callback\<number>)

Called when the pull-down distance changes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Value Type| Type                                   | Mandatory| Description      |
| ------ | --------------------------------------- | ---- | ---------- |
| value  | number | Yes  | Pull-down distance.<br>Unit: vp|


## RefreshStatus

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name      | Value      | Description                  |
| -------- | -------- | -------------------- |
| Inactive | 0 | The component is not pulled down. This is the default value.            |
| Drag     | 1 | The component is being pulled down, but the pull-down distance is shorter than the minimum length required to trigger the refresh.     |
| OverDrag | 2 | The component is being pulled down, and the pull-down distance exceeds the minimum length required to trigger the refresh.     |
| Refresh  | 3 | The pull-down ends, and the component rebounds to the minimum length required to trigger the refresh and enters the refresh state.|
| Done     | 4 | The refresh is complete, and the component returns to the initial state (top).    |


## Example
### Example 1

This example implements a **\<Refresh>** in the default style.

```ts
// xxx.ets
@Entry
@Component
struct RefreshExample {
  @State isRefreshing: boolean = false
  @State arr: String[] = ['0', '1', '2', '3', '4','5','6','7','8','9','10']

  build() {
    Column() {
      Refresh({ refreshing: $$this.isRefreshing}) {
        List() {
          ForEach(this.arr, (item: string) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }
          }, (item: string) => item)
        }
        .onScrollIndex((first: number) => {
          console.info(first.toString())
        })
        .width('100%')
        .height('100%')
        .divider({strokeWidth:1,color:Color.Yellow,startMargin:10,endMargin:10})
        .scrollBar(BarState.Off)
      }
      .onStateChange((refreshStatus: RefreshStatus) => {
        console.info('Refresh onStatueChange state is ' + refreshStatus)
      })
      .onOffsetChange((value: number) => {
        console.info('Refresh onOffsetChange offset:' + value)
      })
      .onRefreshing(() => {
        setTimeout(() => {
          this.isRefreshing = false
        }, 2000)
        console.log('onRefreshing test')
      })
      .backgroundColor(0x89CFF0)
      .refreshOffset(64)
      .pullToRefresh(true)
    }
  }
}
```

![en-us_image_refresh_example1](figures/en-us_image_refresh_example1.gif)

### Example 2

This example implements a **\<Refresh>** component in a custom style.

```ts
// xxx.ets
@Entry
@Component
struct RefreshExample {
  @State isRefreshing: boolean = false
  @State arr: String[] = ['0', '1', '2', '3', '4','5','6','7','8','9','10']
  @Builder
  customRefreshComponent()
  {
    Stack()
    {
      Row()
      {
        LoadingProgress().height(32)
        Text("Refreshing...").fontSize(16).margin({left:20})
      }
      .alignItems(VerticalAlign.Center)
    }.width("100%").align(Alignment.Center)
  }

  build() {
    Column() {
      Refresh({ refreshing: $$this.isRefreshing,builder:this.customRefreshComponent()}) {
        List() {
          ForEach(this.arr, (item: string) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }
          }, (item: string) => item)
        }
        .onScrollIndex((first: number) => {
          console.info(first.toString())
        })
        .width('100%')
        .height('100%')
        .divider({strokeWidth:1,color:Color.Yellow,startMargin:10,endMargin:10})
        .scrollBar(BarState.Off)
      }
      .onStateChange((refreshStatus: RefreshStatus) => {
        console.info('Refresh onStatueChange state is ' + refreshStatus)
      })
      .onRefreshing(() => {
        setTimeout(() => {
          this.isRefreshing = false
        }, 2000)
        console.log('onRefreshing test')
      })
      .backgroundColor(0x89CFF0)
      .refreshOffset(64)
      .pullToRefresh(true)
    }
  }
}
```

![en-us_image_refresh_example2](figures/en-us_image_refresh_example2.gif)
