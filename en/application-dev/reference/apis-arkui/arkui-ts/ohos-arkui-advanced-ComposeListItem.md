# ComposeListItem


The **ComposeListItem** component is a container that presents a series of items arranged in a column with the same width. You can use it to present data of the same type in a multiple and coherent row style, for example, images or text.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { ComposeListItem } from "@kit.ArkUI"
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are supported.


## ComposeListItem

ComposeListItem({contentItem?: ContentItem, operateItem?: OperateItem})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full


| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| contentItem | [ContentItem](#contentitem) | No| \@Prop | Elements on the left and in the center.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| operateItem | [OperateItem](#operateitem) | No| \@Prop | Element on the right.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

## ContentItem

**System capability**: SystemCapability.ArkUI.ArkUI.Full


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| iconStyle | [IconType](#icontype) | No| Icon style of the element on the left.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| icon | [ResourceStr](ts-types.md#resourcestr) | No| Icon resource of the element on the left.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| primaryText | [ResourceStr](ts-types.md#resourcestr) | No| Primary text of the element in the center.<br>**Text processing rules**: Text will wrap to a new line when it exceeds the length limit.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| secondaryText | [ResourceStr](ts-types.md#resourcestr) | No| Secondary text of the element in the center.<br>**Text processing rules**: Text will wrap to a new line when it exceeds the length limit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| description | [ResourceStr](ts-types.md#resourcestr) | No| Description of the element in the center.<br>**Text processing rules**: Text will wrap to a new line when it exceeds the length limit.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |

## IconType

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| BADGE | 1 | Badge with an icon size of 8 x 8 vp.|
| NORMAL_ICON | 2 | Small icon with an icon size of 16 x 16 vp.|
| SYSTEM_ICON | 3 | System icon with an icon size of 24 x 24 vp.|
| HEAD_SCULPTURE | 4 | Profile picture with an icon size of 40 x 40 vp.|
| APP_ICON | 5 | Application icon with an icon size of 64 x 64 vp.|
| PREVIEW | 6 | Preview image with an icon size of 96 x 96 vp.|
| LONGITUDINAL | 7 | Icon with a horizontal special ratio (width is greater than height), keeping the longest side at 96 vp.|
| VERTICAL | 8 | Icon with a vertical special ratio (height is greater than width), keeping the longest side at 96 vp.|

## OperateItem

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| arrow | [OperateIcon](#operateicon) | No| Arrow with a size of 12 x 24 vp.|
| icon | [OperateIcon](#operateicon) | No| First icon with a size of 24 x 24 vp.|
| subIcon | [OperateIcon](#operateicon) | No| Second icon with a size of 24 x 24 vp.|
| button | [OperateButton](#operatebutton) | No| Button.|
| switch | [OperateCheck](#operatecheck) | No| Switch.|
| checkbox | [OperateCheck](#operatecheck) | No| Check box with a size of 24 x 24 vp.|
| radio | [OperateCheck](#operatecheck) | No| Radio button with a size of 24 x 24 vp.|
| image | [ResourceStr](ts-types.md#resourcestr) | No| Image with a size of 48 x 48 vp.|
| text | [ResourceStr](ts-types.md#resourcestr) | No| Text.|

## OperateIcon

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description                                                                                                                                                                                                                                                  |
| -------- | -------- | -------- |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| value | [ResourceStr](ts-types.md#resourcestr) | Yes| Resource of the icon or arrow on the right.                                                                                                                                                                                                                                          |
| action | ()=&gt;void | No| Click event of the icon or arrow on the right.                                                                                                                                                                                                                                        |

## OperateButton

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | [ResourceStr](ts-types.md#resourcestr) | No| Text of the button on the right.|

## OperateCheck

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description                                                                                                                                                                                                                                                                                  |
| -------- | -------- | -------- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| isCheck | boolean | No| Whether the switch, check box, or radio button on the right is selected.<br> Default value: **false**<br> **true**: selected<br> **false**: not selected                                                                                                                                                                              |
| onChange | (value: boolean)=&gt;void | No| Callback invoked when the selected state of the switch, check box, or radio button on the right is changed.<br> **true**: from not selected to selected<br> **false**: from selected to not selected                                                                                                                                                                                        |

## Events
The [universal events](ts-universal-events-click.md) are supported.

## Example
This example demonstrates how to create a simple list item that includes a primary text, a secondary text, a description, and a button with accompanying text on the right.
```ts
// This example demonstrates the basic functionality of the component, including the use of elements on the left and right.
import { IconType, ComposeListItem, promptAction } from '@kit.ArkUI';

@Entry
@Component
struct ComposeListItemExample {
  build() {
    Column() {
      List() {
        ListItem() {
          ComposeListItem({
            contentItem: ({
              iconStyle: IconType.NORMAL_ICON,
              icon: $r('sys.media.ohos_app_icon'),
              primaryText: 'Two-line list',
              secondaryText: 'Secondary text',
              description: 'Description'
            }),
            operateItem: ({
              icon: {
                value: $r('sys.media.ohos_app_icon'),
                action: () => {
                  promptAction.showToast({ message: 'icon' });
                } },
              text: 'Text on the right'
            })
          })
        }
      }
    }
  }
}
```
![ComposeListItem with left and right elements+text](figures/en-us_image_composelistitem_demo_01.jpg)

