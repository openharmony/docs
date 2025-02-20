# Badge

The **Badge** component is a container that can be attached to another component for notification and reminder purposes.

>  **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component supports only one child component.

>  **NOTE**
>
>  Supported types of child components: built-in components and custom components, with support for ([if/else](../../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.


## APIs

### Badge

Badge(value: BadgeParamWithNumber)

Creates a badge with the given numerical value.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value |  [BadgeParamWithNumber](#badgeparamwithnumber)| Yes| Options of the numeric badge.|

### Badge

Badge(value: BadgeParamWithString)

Creates a badge with the given string.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

This component supports the scaling effect for visibility transition since API version 12.

**Parameters**

| Name| Type                                             | Mandatory| Description            |
| ------ | ----------------------------------------------------- | ---- | -------------------- |
| value  | [BadgeParamWithString](#badgeparamwithstring) | Yes  | Options of the string-type badge.|

## BadgeParam

Provides basic parameters for creating a badge.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| position | [BadgePosition](#badgeposition)\|[Position<sup>10+</sup>](ts-types.md#position) | No| Position to display the badge relative to the parent component.<br>Default value: **BadgePosition.RightTop**<br>**NOTE**<br> With the **Position** type, percentage values are not supported. If an invalid value is set, the default value **(0,0)** which indicates the upper left corner of the component, will be used.<br>With the **BadgePosition** type, the position is mirrored based on the [Direction](ts-appendix-enums.md#direction) property.|
| style | [BadgeStyle](#badgestyle) | Yes| Style of the badge, including the font color, font size, badge color, and badge size.|


## BadgeParamWithNumber

Inherits from [BadgeParam](#badgeparam) and has all attributes of **BadgeParam**.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| count | number | Yes| Number of notifications.<br>**NOTE**<br>If the value is less than or equal to 0 and less than the value of **maxCount**, no badge is displayed.<br>Value range: [-2147483648, 2147483647]<br>If the value is out of the range, it will be adjusted by adding or subtracting 4294967296 to bring it back within the range. If the value is not an integer, it is rounded off to the nearest integer. For example, 5.5 is rounded off to 5.|
| maxCount | number | No| Maximum number of notifications. When the maximum number is reached, only **maxCount+** is displayed.<br>Default value: **99**<br>Value range: [-2147483648, 2147483647]<br>If the value is out of the range, it will be adjusted by adding or subtracting 4294967296 to bring it back within the range. If the value is not an integer, it is rounded off to the nearest integer. For example, 5.5 is rounded off to 5.|

## BadgeParamWithString

Inherits from [BadgeParam](#badgeparam) and has all attributes of **BadgeParam**.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string | Yes| Prompt content.|

## BadgePosition

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- |-------- |
| RightTop | 0 | The badge is displayed in the upper right corner of the parent component.|
| Right | 1 | The badge is vertically centered on the right of the parent component.|
| Left | 2 | The badge is vertically centered on the left of the parent component.|

## BadgeStyle

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                     | Type                                                        | Mandatory| Description                                                        |
| ------------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| color                     | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Font color.<br>Default value: **Color.White**<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.|
| fontSize                  | number \| string                                   | No  | Font size.<br>Default value: **10**<br>Unit: fp<br>**NOTE**<br>This parameter cannot be set in percentage.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.|
| badgeSize                 | number \| string                                   | No  | Badge size.<br>Default value: **16**<br>Unit: vp<br>**NOTE**<br>This parameter cannot be set in percentage. If it is set to an invalid value, the default value is used.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.|
| badgeColor                | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Badge color.<br>Default value: **Color.Red**<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.|
| fontWeight<sup>10+</sup>  | number \|[FontWeight](ts-appendix-enums.md#fontweight) \| string | No  | Font weight of the text.<br>Default value: **FontWeight.Normal**<br>**NOTE**<br>This parameter cannot be set in percentage.|
| borderColor<sup>10+</sup> | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Border color of the background.<br>Default value: **Color.Red**                        |
| borderWidth<sup>10+</sup> | [Length](ts-types.md#length)                                 | No  | Border width of the background.<br>Default value: **1**<br>Unit: vp<br>**NOTE**<br>This parameter cannot be set in percentage.|

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

## Events

The [universal events](ts-universal-events-click.md) are supported.

## Example

### Example 1: Setting the Badge Content

This example illustrates the varying visual effects of the **Badge** component when it receives empty values, character strings, and numerical values through the **value** and **count** properties.

```ts
// xxx.ets
@Entry
@Component
struct BadgeExample {
  @Builder
  tabBuilder(index: number) {
    Column() {
      if (index === 2) {
        Badge({
          value: '',
          style: { badgeSize: 6, badgeColor: '#FA2A2D' }
        }) {
          Image('/common/public_icon_off.svg')
            .width(24)
            .height(24)
        }
        .width(24)
        .height(24)
        .margin({ bottom: 4 })
      } else {
        Image('/common/public_icon_off.svg')
          .width(24)
          .height(24)
          .margin({ bottom: 4 })
      }
      Text('Tab')
        .fontColor('#182431')
        .fontSize(10)
        .fontWeight(500)
        .lineHeight(14)
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)
  }

  @Builder
  itemBuilder(value: string) {
    Row() {
      Image('common/public_icon.svg').width(32).height(32).opacity(0.6)
      Text(value)
        .width(177)
        .height(21)
        .margin({ left: 15, right: 76 })
        .textAlign(TextAlign.Start)
        .fontColor('#182431')
        .fontWeight(500)
        .fontSize(16)
        .opacity(0.9)
      Image('common/public_icon_arrow_right.svg').width(12).height(24).opacity(0.6)
    }.width('100%').padding({ left: 12, right: 12 }).height(56)
  }

  build() {
    Column() {
      // Badge of the red dot type
      Text('dotsBadge').fontSize(18).fontColor('#182431').fontWeight(500).margin(24)
      Tabs() {
        TabContent()
          .tabBar(this.tabBuilder(0))
        TabContent()
          .tabBar(this.tabBuilder(1))
        TabContent()
          .tabBar(this.tabBuilder(2))
        TabContent()
          .tabBar(this.tabBuilder(3))
      }
      .width(360)
      .height(56)
      .backgroundColor('#F1F3F5')

      // Create a badge with the given string.
      Column() {
        Text('stringBadge').fontSize(18).fontColor('#182431').fontWeight(500).margin(24)
        List({ space: 12 }) {
          ListItem() {
            Text('list1').fontSize(14).fontColor('#182431').margin({ left: 12 })
          }
          .width('100%')
          .height(56)
          .backgroundColor('#FFFFFF')
          .borderRadius(24)
          .align(Alignment.Start)

          ListItem() {
            Badge({
              value: 'New',
              position: BadgePosition.Right,
              style: { badgeSize: 16, badgeColor: '#FA2A2D' }
            }) {
              Text('list2').width(27).height(19).fontSize(14).fontColor('#182431')
            }.width(49.5).height(19)
            .margin({ left: 12 })
          }
          .width('100%')
          .height(56)
          .backgroundColor('#FFFFFF')
          .borderRadius(24)
          .align(Alignment.Start)
        }.width(336)

        // Create a badge with the given numerical value.
        Text('numberBadge').fontSize(18).fontColor('#182431').fontWeight(500).margin(24)
        List() {
          ListItem() {
            this.itemBuilder('list1')
          }

          ListItem() {
            Row() {
              Image('common/public_icon.svg').width(32).height(32).opacity(0.6)
              Badge({
                count: 1,
                position: BadgePosition.Right,
                style: { badgeSize: 16, badgeColor: '#FA2A2D' }
              }) {
                Text('list2')
                  .width(177)
                  .height(21)
                  .textAlign(TextAlign.Start)
                  .fontColor('#182431')
                  .fontWeight(500)
                  .fontSize(16)
                  .opacity(0.9)
              }.width(240).height(21).margin({ left: 15, right: 11 })

              Image('common/public_icon_arrow_right.svg').width(12).height(24).opacity(0.6)
            }.width('100%').padding({ left: 12, right: 12 }).height(56)
          }

          ListItem() {
            this.itemBuilder('list3')
          }

          ListItem() {
            this.itemBuilder('list4')
          }
        }
        .width(336)
        .height(232)
        .backgroundColor('#FFFFFF')
        .borderRadius(24)
        .padding({ top: 4, bottom: 4 })
        .divider({
          strokeWidth: 0.5,
          color: 'rgba(0,0,0,0.1)',
          startMargin: 60,
          endMargin: 12
        })
      }.width('100%').backgroundColor('#F1F3F5').padding({ bottom: 12 })
    }.width('100%')
  }
}
```

![badge](figures/badge.png)

### Example 2: Controlling the Badge Visibility with Numbers

This example shows how to use the **count** property to toggle the visibility of the **Badge** component. Specifically, when the **count** property is set to **0**, the badge is hidden; when it is set to **1**, the badge becomes visible.

```ts
// This example implements scaling when the badge visibility changes.
@Entry
@Component
struct Index {
  @State badgeCount: number = 1

  build() {
    Column({ space: 40 }) {
      Badge({
        count: this.badgeCount,
        style: {},
        position: BadgePosition.RightTop,
      }) {
        Image($r("app.media.startIcon"))
          .width(50)
          .height(50)
      }
      .width(55)

      Button('count 0').onClick(() => {
        this.badgeCount = 0
      })
      Button('count 1').onClick(() => {
        this.badgeCount = 1
      })
    }
    .margin({ top: 20 })
  }
}
```

![badgeScale](figures/badgeScale.gif)
