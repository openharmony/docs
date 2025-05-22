# SideBarContainer

The **SideBarContainer** component contains a sidebar and content area as its child components. The sidebar is the first child component and can be shown or hidden as needed. The content area is the second child component.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported

>  **NOTE**
>
>  - Built-in components and custom components are allowed, without support for ([if/else](../../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.
>  - This component must contain two child components.
>  - If there are three or more child components, only the first and second child components are displayed. If there is only one child component, the sidebar is displayed, and the content area is blank.


## APIs

SideBarContainer( type?: SideBarContainerType )

Creates a sidebar container.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | [SideBarContainerType](#sidebarcontainertype) | No| Display type of the sidebar.<br>Default value: **SideBarContainerType.Embed**|

## SideBarContainerType

Enumerates the types of sidebars in a container.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Description|
| -------- | -------- |
| Embed | The sidebar is embedded in the component and displayed side by side with the content area.<br>When the component size is less than the sum of **minContentWidth** and **minSideBarWidth** and **showSideBar** is not set, the sidebar is automatically hidden.<br>If **minSideBarWidth** or **minContentWidth** is not set, the default value will be used for calculation.<br> The user can bring out the sidebar in Overlay mode by clicking the control button.|
| Overlay | The sidebar is displayed overlaid on the content area.|
| AUTO<sup>10+</sup> | The sidebar is displayed in Embed mode when the component size is greater than or equal to the sum of **minSideBarWidth** and **minContentWidth**<br>and in Overlay mode otherwise.<br>If **minSideBarWidth** or **minContentWidth** is not set, the default value will be used for calculation. If the calculation result is less than 600 vp, 600 vp will be used as the breakpoint value for mode switching.|

## Attributes

In addition to the [universal attributes](ts-component-general-attributes.md), the following attributes are supported.

### showSideBar

showSideBar(value: boolean)

Specifies whether to display the sidebar.

Since API version 10, this attribute supports two-way binding through [$$](../../../quick-start/arkts-two-way-sync.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to display the sidebar.<br>**true**: The sidebar is displayed.<br>**false**: The sidebar is not displayed.<br>Default value: **true**|

### controlButton

controlButton(value: ButtonStyle)

Sets the attributes of the sidebar control button.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                               | Mandatory| Description                  |
| ------ | ----------------------------------- | ---- | ---------------------- |
| value  | [ButtonStyle](#buttonstyle) | Yes  | Attributes of the sidebar control button.|

### showControlButton

showControlButton(value: boolean)

Specifies whether to display the sidebar control button.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to display the sidebar control button.<br>**true**: The sidebar control button is displayed.<br>**false**: The sidebar control button is not displayed.<br>Default value: **true**|

### sideBarWidth

sideBarWidth(value: number)

Sets the width of the sidebar. If a value less than 0 is set, the default value is used. The value must comply with the width constraints. If it is not within the valid range, the valid value closest to the set one is used.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Width of the sidebar.<br>Default value: **240vp**<br>Unit: vp<br>Value range: [0, +∞).<br>**NOTE**<br>In API version 9 and earlier versions, the default value is **200vp**. In API version 10, the default value is **240vp**.|

### sideBarWidth<sup>9+</sup>

sideBarWidth(value: Length)

Sets the width of the sidebar. If a value less than 0 is set, the default value is used. The value must comply with the width constraints. If it is not within the valid range, the valid value closest to the set one is used. Compared to [sideBarWidth](#sidebarwidth), this API supports percentage strings and other [pixel units](ts-pixel-units.md) for the **value** parameter.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Length](ts-types.md#length) | Yes  | Width of the sidebar.<br>Default value: **240vp**.<br>Unit: vp.<br>Value range: [0, +∞).<br>**NOTE**<br>The default value is **200vp** in API version 9 and **240vp** in API version 10.|

### minSideBarWidth

minSideBarWidth(value: number)

Sets the minimum width of the sidebar. If a value less than 0 is set, the default value is used. The value cannot exceed the width of the sidebar container itself. Otherwise, the width of the sidebar container itself is used.

**minSideBarWidth**, whether it is specified or kept at the default value, takes precedence over **minWidth** of the sidebar child components.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Minimum width of the sidebar.<br>Default value: In API version 9 and earlier versions, the default value is **200vp**. In API version 10, the default value is **240vp**.<br>Value range: [0, +∞).|

### minSideBarWidth<sup>9+</sup>

minSideBarWidth(value: Length)

Sets the minimum width of the sidebar. If a value less than 0 is set, the default value is used. The value cannot exceed the width of the sidebar container itself. Otherwise, the width of the sidebar container itself is used. Compared to [minSideBarWidth](#minsidebarwidth), this API supports percentage strings and other [pixel units](ts-pixel-units.md) for the **value** parameter.

**minSideBarWidth**, whether it is specified or kept at the default value, takes precedence over **minWidth** of the sidebar child components.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Length](ts-types.md#length) | Yes  | Minimum width of the sidebar.<br>Default value: In API version 9 and earlier versions, the default value is **200vp**. In API version 10, the default value is **240vp**.<br>Value range: [0, +∞).|

### maxSideBarWidth

maxSideBarWidth(value: number)

Sets the maximum width of the sidebar. If a value less than 0 is set, the default value is used. The value cannot exceed the width of the sidebar container itself. Otherwise, the width of the sidebar container itself is used.

**maxSideBarWidth**, whether it is specified or kept at the default value, takes precedence over **maxWidth** of the sidebar child components.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                               |
| ------ | ------------------------------------------------------------ | ---- | --------------------------------------------------- |
| value  | number | Yes  | Maximum width of the sidebar.<br>Default value: **280vp**<br>Unit: vp.<br>Value range: [0, +∞).|

### maxSideBarWidth<sup>9+</sup>

maxSideBarWidth(value: Length)

Sets the maximum width of the sidebar. If a value less than 0 is set, the default value is used. The value cannot exceed the width of the sidebar container itself. Otherwise, the width of the sidebar container itself is used.

**maxSideBarWidth**, whether it is specified or kept at the default value, takes precedence over **maxWidth** of the sidebar child components.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                               |
| ------ | ------------------------------------------------------------ | ---- | --------------------------------------------------- |
| value  | [Length](ts-types.md#length) | Yes  | Maximum width of the sidebar.<br>Default value: **280vp**<br>Unit: vp.<br>Value range: [0, +∞).|

### autoHide<sup>9+</sup>

autoHide(value: boolean)

Specifies whether to automatically hide the sidebar when it is dragged to be smaller than the minimum width. The value is subject to the **minSideBarWidth** attribute method. If it is not set in **minSideBarWidth**, the default value is used.

Whether the sidebar should be hidden is determined when it is being dragged. When it is dragged to be smaller than the minimum width, the damping effect is required to trigger hiding (a distance out of range).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to automatically hide the sidebar when it is dragged to be smaller than the minimum width.<br>**true**: The sidebar is automatically hidden.<br>**false**: The sidebar is not automatically hidden.<br>Default value: **true**|

### sideBarPosition<sup>9+</sup>

sideBarPosition(value: SideBarPosition)

Sets the position of the sidebar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                        | Mandatory| Description                                              |
| ------ | -------------------------------------------- | ---- | -------------------------------------------------- |
| value  | [SideBarPosition](#sidebarposition9) | Yes  | Position of the sidebar.<br>Default value: **SideBarPosition.Start**|

### divider<sup>10+</sup>

divider(value: DividerStyle | null)

Sets the divider style.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                     | Mandatory| Description                                                        |
| ------ | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [DividerStyle](#dividerstyle10) \| null | Yes  | Divider style.<br>- **DividerStyle** (default): The divider is displayed.<br>- **null** or **undefined**: No action is taken, and the divider style remains consistent with the default.<br>**NOTE**<br>In API version 11 and earlier versions, **null** results in the divider not being displayed.|

### minContentWidth<sup>10+</sup>

minContentWidth(value: Dimension)

Sets the minimum content area width of the sidebar container.

If this attribute is set to a value less than 0, the default value **360vp** will be used. If this attribute is not set, the width of the content area can shrink to 0.

In Embed mode, when the component size is increased, only the content area is enlarged;

when the component size is decreased, the content area is shrunk until its width reaches the value defined by **minContentWidth**; if the component size is further decreased, while respecting the **minContentWidth** settings, the sidebar is shrunk

until its width reaches the value defined by **minSideBarWidth**; if the component size is further decreased, then:

- If **autoHide** is set to **false**, while respecting the **minSideBarWidth** and **minContentWidth** settings, the content area has its content clipped.
- If **autoHide** is set to **true**, the sidebar is hidden first, and then the content area is shrunk. After its width reaches the value defined by **minContentWidth**, the content area has its content clipped.

**minContentWidth**, whether it is specified or kept at the default value, takes precedence over **minSideBarWidth** and **sideBarWidth** of the sidebar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                | Mandatory| Description                                                        |
| ------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Dimension](ts-types.md#dimension10) | Yes  | Minimum content area width of the sidebar container.<br>Default value: **360vp**<br>Unit: vp|

## ButtonStyle

Describes the style of the sidebar control button.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| left | number | No| Spacing between the sidebar control button and the left of the container.<br>Default value: **16vp**<br>Unit: vp.<br>Value range: [0, +∞).|
| top | number | No| Spacing between the sidebar control button and the top of the container.<br>Default value: **48vp**<br>Unit: vp.<br>Value range: [0, +∞).|
| width | number | No| Width of the sidebar control button.<br>Default value:<br>API version 9 and earlier versions: **32vp**<br>API version 10 and later versions: **24vp**<br>Unit: vp.<br>Value range: [0, +∞).|
| height | number | No| Height of the sidebar control button.<br>Default value:<br>API version 9 and earlier versions: **32vp**<br>API version 10 and later versions: **24vp**<br>Unit: vp.<br>Value range: [0, +∞).|
| icons | [ButtonIconOptions<sup>14+</sup>](#buttoniconoptions14) | No| Icons of the sidebar control button.|

## ButtonIconOptions<sup>14+</sup>

Describes the icons of the sidebar control button.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                          | Mandatory| Description                                       |
| --------- | -------------------------------| ---- | ------------------------------------------ |
| shown<sup>8+</sup>     | string \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | Yes  | Icon of the control button when the sidebar is displayed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.             |
| hidden<sup>8+</sup>    | string \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | Yes  | Icon of the control button when the sidebar is hidden.<br>**Atomic service API**: This API can be used in atomic services since API version 11.             |
| switching<sup>8+</sup> | string \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | No  | Icon of the control button when the sidebar is switching between the shown and hidden states.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

> **NOTE**
>
> When an error occurs during resource obtaining, the default icon is used.

## SideBarPosition<sup>9+</sup>

Enumerates the positions of the sidebar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Description|
| -------- | -------- |
| Start | The sidebar is on the left side of the container.|
| End | The sidebar is on the right side of the container.|

## DividerStyle<sup>10+</sup>

Sets the divider style.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type     | Mandatory| Description                                    |
| ----------- | ------------- | ---- | ---------------------------------------- |
| strokeWidth | [Length](ts-types.md#length)        | Yes  | Stroke width of the divider.<br>Default value: **1vp**|
| color       | [ResourceColor](ts-types.md#resourcecolor) | No  | Color of the divider.<br>Default value: **#000000, 3%**  |
| startMargin | [Length](ts-types.md#length)        | No  | Distance between the divider and the top of the sidebar.<br>Default value: **0**|
| endMargin   | [Length](ts-types.md#length)        | No  | Distance between the divider and the bottom of the sidebar.<br>Default value: **0**|
>  **NOTE**
>
>  The settings of the [universal size attributes](ts-universal-attributes-size.md) **width** and **height** do not take effect for the sidebar child component.
>  The settings do not take effect for the sidebar content area either. By default, the sidebar content area takes up the remaining space of the sidebar container.
>
>  If the **showSideBar** attribute is not set, the sidebar's visibility is subject to its size.
>
>  - If the size is less than the sum of **minSideBarWidth** and **minContentWidth**, the sidebar is not displayed by default.
>  - If the size is greater than or equal to the sum of **minSideBarWidth** and **minContentWidth**, the sidebar is displayed by default.

## Events

In addition to the [universal events](ts-component-general-events.md), the following events are supported.

### onChange

onChange(callback: (value: boolean) =&gt; void)

Triggered when the status of the sidebar switches between shown and hidden.

This event is triggered when any of the following conditions is met:

1. The value of **showSideBar** changes.

2. The **showSideBar** attribute adapts to behavior changes.

3. The **autoHide** API is triggered when the divider is dragged.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                         |
| ------ | ------- | ---- | ----------------------------- |
| value  | boolean | Yes  | The value **true** means that the sidebar is displayed, and **false** means the opposite.|


## Example

This example demonstrates how to use the **SideBarContainer** component and implement the page layout.

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
        ForEach(this.arr, (item: number) => {
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
        }, (item: string) => item)
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
    .minContentWidth(0)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
    .divider({ strokeWidth: '1vp', color: Color.Gray, startMargin: '4vp', endMargin: '4vp' })
  }
}
```

![](figures/sidebarcontainer.png)
