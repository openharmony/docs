# SideBarContainer

The **\<SideBarContainer>** component contains a sidebar and content area as its child components. The sidebar is the first child component and can be shown or hidden as needed. The content area is the second child component.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported

>  **NOTE**
>
>  - Built-in components and custom components are allowed, without support for ([if/else](../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.
>  - This component must contain two child components.
>  - If there are three or more child components, only the first and second child components are displayed. If there is only one child component, the sidebar is displayed, and the content area is blank.


## APIs

SideBarContainer( type?: SideBarContainerType )

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | SideBarContainerType | No| Display type of the sidebar.<br>Default value: **SideBarContainerType.Embed**|

## SideBarContainerType

| Name| Description|
| -------- | -------- |
| Embed | The sidebar is embedded in the component and displayed side by side with the content area.|
| Overlay | The sidebar is displayed overlaid on the content area.|
| AUTO | The sidebar is displayed in Embed mode when the component size is greater than or equal to the sum of **minSideBarWidth** and **minContentWidth**<br>and in Overlay mode otherwise.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| showSideBar | boolean | Whether to display the sidebar.<br>Default value: **true**<br>Since API version 10, this attribute supports [$$](../../quick-start/arkts-two-way-sync.md) for two-way binding of variables.|
| controlButton | [ButtonStyle](#buttonstyle)                            | Attributes of the sidebar control button.|
| showControlButton | boolean | Whether to display the sidebar control button.<br>Default value: **true**|
| sideBarWidth | number \| [Length](ts-types.md#length)<sup>9+</sup> | Width of the sidebar.<br>Default value: **200**<br>Unit: vp<br>**NOTE**<br>A value less than 0 evaluates to the default value.<br>The value must comply with the width constraints. If it is not within the valid range, the value closest to the set one is used.<br>The width of the sidebar, whether it is specified or kept at the default, takes precedence over that of the sidebar child components.|
| minSideBarWidth | number \| [Length](ts-types.md#length)<sup>9+</sup> | Minimum width of the sidebar.<br>Default value: **200**, in vp<br>**NOTE**<br>A value less than 0 evaluates to the default value.<br>The value cannot exceed the width of the sidebar container itself. Otherwise, the width of the sidebar container itself is used.<br>When set, the minimum width of the sidebar takes precedence over that of the sidebar child components. If it is not set, however, the minimum width of the sidebar child component takes precedence.|
| maxSideBarWidth | number \| [Length](ts-types.md#length)<sup>9+</sup> | Maximum width of the sidebar.<br>Default value: **280**, in vp<br>**NOTE**<br>A value less than 0 evaluates to the default value.<br>The value cannot exceed the width of the sidebar container itself. Otherwise, the width of the sidebar container itself is used.<br>When set, the maximum width of the sidebar takes precedence over that of the sidebar child components. If it is not set, however, the maximum width of the sidebar child component takes precedence.|
| autoHide<sup>9+</sup> | boolean | Whether to automatically hide the sidebar when it is dragged to be smaller than the minimum width.<br>Default value: **true**<br>**NOTE**<br>The value is subject to the **minSideBarWidth** attribute method. If it is not set in **minSideBarWidth**, the default value is used.<br>Whether the sidebar should be hidden is determined when it is being dragged. When its width is less than the minimum width, the damping effect is required to trigger hiding (a distance out of range).|
| sideBarPosition<sup>9+</sup> | [SideBarPosition](#sidebarposition9) | Position of the sidebar.<br>Default value: **SideBarPosition.Start**|
| divider<sup>10+</sup>        | [DividerStyle](#dividerstyle10) \| null | Divider style.<br>- **DividerStyle** (default): The divider is displayed.<br>- **null**: The divider is not displayed.|
| minContentWidth<sup>10+</sup> | Dimension | Minimum width of the content area of the sidebar container.<br>Default value: **360**<br>Unit: vp|

## ButtonStyle

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| left | number | No| Spacing between the sidebar control button and the left of the container.<br>Default value: **16**<br>Unit: vp|
| top | number | No| Spacing between the sidebar control button and the top of the container.<br>Default value: **48**<br>Unit: vp|
| width | number | No| Width of the sidebar control button.<br>Default value: **32**<br>Unit: vp|
| height | number | No| Height of the sidebar control button.<br>Default value: **32**<br>Unit: vp|
| icons | {<br>shown: string \| PixelMap \| [Resource](ts-types.md) ,<br>hidden: string \| PixelMap \| [Resource](ts-types.md) ,<br>switching?: string \| PixelMap \| [Resource](ts-types.md) <br>} | No| Icons of the sidebar control button.<br> </p> - **shown**: icon of the control button when the sidebar is shown.<br>**NOTE**<br>When an error occurs during resource obtaining, the default icon is used.<br>- **hidden**: icon of the control button when the sidebar is hidden.<br>- **switching**: icon of the control button when the sidebar is switching between the shown and hidden states.|

## SideBarPosition<sup>9+</sup>

| Name| Description|
| -------- | -------- |
| Start | The sidebar is on the left side of the container.|
| End | The sidebar is on the right side of the container.|

## DividerStyle<sup>10+</sup>

| Name       | Type     | Mandatory| Description                                    |
| ----------- | ------------- | ---- | ---------------------------------------- |
| strokeWidth | [Length](ts-types.md#length)        | Yes  | Stroke width of the divider.<br>Default value: **1**<br>Unit: vp|
| color       | [ResourceColor](ts-types.md#resourcecolor) | No  | Color of the divider.<br>Default value: **#000000, 3%**  |
| startMargin | [Length](ts-types.md#length)        | No  | Distance between the divider and the top of the sidebar.<br>Default value: **0**|
| endMargin   | [Length](ts-types.md#length)        | No  | Distance between the divider and the bottom of the sidebar.<br>Default value: **0**|
>  **NOTE**
>
>  When the universal attributes [width and height](ts-universal-attributes-size.md) are set for the sidebar, the **width** setting takes effect only when the sidebar container width is not set, and the **height** settings does not take effect.
>  The settings of the universal attributes **width** and **height** do not take effect for the sidebar content area. By default, sidebar content area takes up the remaining space of the sidebar container.
>
>  If the attribute method is not used, the sidebar is displayed depending on the size.
>
>  - If the size is less than 520 vp, the sidebar is not displayed by default.
>  - If the size is greater than or equal to 520 vp, the sidebar is displayed by default.
>  -  
>  -  

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name| Description|
| -------- | -------- |
| onChange(callback: (value: boolean) =&gt; void) | Triggered when the status of the sidebar switches between shown and hidden. The value **true** means that the sidebar is displayed, and **false** means the opposite.<br>This event is triggered when any of the following conditions is met:<br>1. The value of **showSideBar** changes.<br>2. The **showSideBar** attribute adapts to behavior changes.<br>3. The **autoHide** API is triggered when the divider is dragged.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct SideBarContainerExample {
  normalIcon: Resource = $r("app.media.icon")
  selectedIcon: Resource = $r("app.media.icon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1

  build() {
    SideBarContainer(SideBarContainerType.Embed) {
      Column() {
        ForEach(this.arr, (item, index) => {
          Column({ space: 5 }) {
            Image(this.current === item ? this.selectedIcon : this.normalIcon).width(64).height(64)
            Text("Index0" + item)
              .fontSize(25)
              .fontColor(this.current === item ? '#0A59F7' : '#999')
              .fontFamily('source-sans-pro,cursive,sans-serif')
          }
          .onClick(() => {
            this.current = item
          })
        }, item => item)
      }.width('100%')
      .justifyContent(FlexAlign.SpaceEvenly)
      .backgroundColor('#19000000')


      Column() {
        Text('SideBarContainer content text1').fontSize(25)
        Text('SideBarContainer content text2').fontSize(25)
      }
      .margin({ top: 50, left: 20, right: 30 })
    }
    .controlButton({
      icons: {
        hidden: $r('app.media.drawer'),
        shown: $r('app.media.drawer'),
        switching: $r('app.media.drawer')
      }
    })
    .sideBarWidth(150)
    .minSideBarWidth(50)
    .maxSideBarWidth(300)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
  }
}
```

![](figures/sidebarcontainer.png)
