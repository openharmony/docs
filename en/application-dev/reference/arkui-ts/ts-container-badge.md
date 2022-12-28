# Badge

The **\<Badge>** component is a container that can be attached to another component for tagging.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component supports only one child component.


## APIs

**API 1**: Badge(value: {count: number, position?: BadgePosition, maxCount?: number, style: BadgeStyle})

Creates a badge.

**Parameters**
| Name| Type| Mandatory| Default Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| count | number | Yes| - | Number of notifications.|
| position | [BadgePosition](#badgeposition) | No| BadgePosition.RightTop | Position to display the badge relative to the parent component.|
| maxCount | number | No| 99 | Maximum number of notifications. When the maximum number is reached, only **maxCount+** is displayed.|
| style | [BadgeStyle](#badgestyle) | Yes| - | Style of the badge, including the font color, font size, badge color, and badge size.|

**API 2**: Badge(value: {value: string, position?: BadgePosition, style: BadgeStyle})

Creates a badge based on the given string.

**Parameters**

| Name| Type| Mandatory| Default Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| value | string | Yes| - | Prompt content.|
| position | [BadgePosition](#badgeposition) | No| BadgePosition.RightTop | Position to display the badge relative to the parent component.|
| style | [BadgeStyle](#badgestyle) | Yes| - | Style of the badge, including the font color, font size, badge color, and badge size.|

## BadgePosition

| Name| Description|
| -------- | -------- |
| RightTop | The badge is displayed in the upper right corner of the parent component.|
| Right | The badge is vertically centered on the right of the parent component.|
| Left | The badge is vertically centered on the left of the parent component.|

## BadgeStyle

| Name      | Type                                      | Mandatory| Default Value     | Description                                       |
| ---------- | ------------------------------------------ | ---- | ----------- | ------------------------------------------- |
| color      | [ResourceColor](ts-types.md#resourcecolor) | No  | Color.White | Font color.                                 |
| fontSize   | number \| string                 | No  | 10          | Font size, in vp.                         |
| badgeSize  | number \| string                 | No  | 16          | Badge size, in vp. This parameter cannot be set in percentage. If it is set to an invalid value, the default value is used.|
| badgeColor | [ResourceColor](ts-types.md#resourcecolor) | No  | Color.Red   | Badge color.                              |

## Example

```ts
// xxx.ets
@Entry
@Component
struct BadgeExample {
  @Builder TabBuilder(index: number) {
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

  @Builder itemBuilder(value: string) {
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
      Text('dotsBadge').fontSize(18).fontColor('#182431').fontWeight(500).margin(24)
      Tabs() {
        TabContent()
          .tabBar(this.TabBuilder(0))
        TabContent()
          .tabBar(this.TabBuilder(1))
        TabContent()
          .tabBar(this.TabBuilder(2))
        TabContent()
          .tabBar(this.TabBuilder(3))
      }
      .width(360)
      .height(56)
      .backgroundColor('#F1F3F5')

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
        .divider({ strokeWidth: 0.5, color: 'rgba(0,0,0,0.1)', startMargin: 60, endMargin: 12 })
      }.width('100%').backgroundColor('#F1F3F5').padding({ bottom: 12 })
    }.width('100%')
  }
}
```

![badge](figures/badge.png)
