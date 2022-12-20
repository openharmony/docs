# SideBarContainer

The **\<SideBarContainer>** component contains a sidebar and content area as its child components. The sidebar is the first child component and can be shown or hidden as needed. The content area is the second child component.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported


## APIs

SideBarContainer( type?: SideBarContainerType )

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | SideBarContainerType | No| Display type of the sidebar.<br>Default value: **SideBarContainerType.Embed**|

## SideBarContainerType enums

| Name| Description|
| -------- | -------- |
| Embed | The sidebar is embedded in the component and displayed side by side with the content area.|
| Overlay | The sidebar is displayed overlaid on the content area.|

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| showSideBar | boolean | Whether to display the sidebar.<br>Default value: **true**|
| controlButton | ButtonStyle                                                | Attributes of the sidebar control button.|
| showControlButton | boolean | Whether to display the sidebar control button.<br>Default value: **true**|
| sideBarWidth | number \| Length<sup>9+</sup> | Width of the sidebar.<br>Default value: **200**, in vp|
| minSideBarWidth | number \| Length<sup>9+</sup> | Minimum width of the sidebar.<br>Default value: **200**, in vp|
| maxSideBarWidth | number \| Length<sup>9+</sup> | Maximum width of the sidebar.<br>Default value: **280**, in vp|
| autoHide<sup>9+</sup> | boolean | Whether to automatically hide the sidebar when it is dragged to be smaller than the minimum width.<br>Default value: **true**|
| sideBarPosition<sup>9+</sup> | SideBarPosition | Position of the sidebar.<br>Default value: **SideBarPosition.Start**|

## ButtonStyle

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| left | number | No| Spacing between the sidebar control button and the left of the container.<br>Default value: **16**, in vp|
| top | number | No| Spacing between the sidebar control button and the top of the container.<br>Default value: **48**, in vp|
| width | number | No| Width of the sidebar control button.<br>Default value: **32**, in vp|
| height | number | No| Height of the sidebar control button.<br>Default value: **32**, in vp|
| icons | {<br>shown: string \| PixelMap \| [Resource](ts-types.md) ,<br>hidden: string \| PixelMap \| [Resource](ts-types.md) ,<br>switching?: string \| PixelMap \| [Resource](ts-types.md) <br>} | No| Icons of the sidebar control button.<br> </p> - **shown**: icon of the control button when the sidebar is shown.<br>- **hidden**: icon of the control button when the sidebar is hidden.<br>- **switching**: icon of the control button when the sidebar is switching between the shown and hidden states.|

## SideBarPosition<sup>9+</sup>

| Name| Description|
| -------- | -------- |
| Start | The sidebar is on the left side of the container.|
| End | The sidebar is on the right side of the container.|

## Events

| Name| Description|
| -------- | -------- |
| onChange(callback: (value: boolean) =&gt; void) | Triggered when the status of the sidebar switches between shown and hidden. <p>The value **true** means that the sidebar is shown, and **false** means the opposite.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct SideBarContainerExample {
  normalIcon : Resource = $r("app.media.icon")
  selectedIcon: Resource = $r("app.media.icon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1

  build() {
    SideBarContainer(SideBarContainerType.Embed)
    {
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
