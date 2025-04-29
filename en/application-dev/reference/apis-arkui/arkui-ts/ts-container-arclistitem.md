# ArcListItem

The **ArcListItem** component is used to display individual child components in an [ArcList](ts-container-arclist.md) component and must be used in conjunction with **ArcList**.

> **NOTE**
>
> - This component is supported since API version 18. Updates will be marked with a superscript to indicate their earliest API version.
> - This component can be used only as a child of [ArcList](ts-container-arclist.md).
> - When this component is used with [LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md), its child components are created when it is created. When this component is used with [if/else](../../../quick-start/arkts-rendering-control-ifelse.md) or [ForEach](../../../quick-start/arkts-rendering-control-foreach.md), or when the parent component is [ArcList](ts-container-arclist.md), its child components are created when it is laid out.

## Modules to Import

```ts
import { ArcListItem, ArcListItemAttribute } from '@kit.ArkUI';
```

## Child Components

This component can contain a single child component.

## APIs

### ArcListItem

ArcListItem()

Creates an item for the **ArcList** component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

## Attributes

In addition to the [universal attributes](ts-component-general-attributes.md), the following attributes are supported.

### autoScale

autoScale(enable: Optional\<boolean>)

Sets whether to enable auto-scaling for the **ArcListItem** component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name| Type              | Mandatory| Description                                       |
| ------ | ------------------ | ---- | ------------------------------------------- |
| enable | Optional\<boolean> | Yes  | Whether to enable auto-scaling.<br>**true**: Enable auto-scaling.<br>**false**: Disable auto-scaling.<br>Default value: **true**.|

### swipeAction

swipeAction(options: Optional\<SwipeActionOptions>)

Sets the swipe action item displayed when the **ArcListItem** component is swiped out from the screen edge.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

**Parameters**

| Name | Type                                                        | Mandatory| Description                   |
| ------- | ------------------------------------------------------------ | ---- | ----------------------- |
| options | [Optional\<SwipeActionOptions>](ts-container-listitem.md#swipeactionoptions9) | No  | Swipe action item displayed when the **ArcListItem** component is swiped out from the screen edge.|

## Example

This example demonstrates the visual differences when auto-scaling is enabled or disabled for child items in an **ArcList** component.

```ts
// xxx.ets
import { LengthMetrics } from "@kit.ArkUI";
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@kit.ArkUI';

@Entry
@Component
struct ArcListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  private watchSize: string = '466px' // Default watch size: 466*466
  private itemSize: string = '414px' // Item width

  @Builder
  buildList() {
    Stack() {
      Column() {
      }
      .width(this.watchSize)
      .height(this.watchSize)
      .clip(new Circle({ width: '100%', height: '100%' }))
      .backgroundColor(0x707070)

      ArcList({ initialIndex: 3}) {
        ForEach(this.arr, (item: number) => {
          ArcListItem() {
            Button('' + item, { type: ButtonType.Capsule })
              .width(this.itemSize)
              .height('70px')
              .fontSize('40px')
              .backgroundColor(0x17A98D)
          }
          .autoScale(item % 3 == 0 || item % 5 == 0)
        }, (item: string) => item)
      }
      .space(LengthMetrics.px(10))
      .borderRadius(this.watchSize)
    }
    .width(this.watchSize)
    .height(this.watchSize)
  }

  build() {
    Column() {
      this.buildList()
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
    .justifyContent(FlexAlign.Center)
  }
}
```

![arkts-arclistitem](figures/arkts-arclistitem.png)
