# Layout Constraints

Layout constraints refer to constraints on the aspect ratio and display priority of components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## aspectRatio

aspectRatio(value: number)

Sets the aspect ratio of the component.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Aspect ratio of the component, which can be obtained using the following formula: Width/Height. If **width**, **height**, and **aspectRatio** are all set, **height** is ignored, and the width and height are calculated based on **width** and aspectRatio. After **aspectRatio** is set, the width and height of the component are constrained by the size of the parent component's content area.<br>The default value varies by API version.<br>API version 9 and earlier: **1.0**<br><br>API version 10: none<br>**NOTE**<br>This attribute does not take effect when it is not set or is set to an invalid value.<br>For example, if a **Row** component has only its width set and does not have any child component, then when **aspectRatio** is not set or is set to a negative value, the height of the **Row** component is 0.|

## displayPriority

displayPriority(value: number)

Sets the display priority for the component in the layout container.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Display priority of the component in the layout container.<br>Default value: **1**<br>**NOTE**<br>This parameter is only effective in [Row](./ts-container-row.md), [Column](./ts-container-column.md), and [Flex (single-line)](./ts-container-flex.md) container components.<br> The digits after the decimal point are not counted in determining the display priority. That is, numbers in the [x, x + 1) range are considered to represent the same priority. For example, **1.0** and **1.9** represent the same priority.<br>If the **displayPriority** value of all child components is not greater than 1, there is no difference in priority.<br>When the **displayPriority** value of a child component is greater than 1, a larger value indicates higher priority. If the parent container does not have enough space, child components with lower priority are hidden. If child components of a certain priority are hidden, those with an even lower priority are also hidden.|

## pixelRound<sup>11+</sup>

pixelRound(value: PixelRoundPolicy)

Describes the rounding strategy for component pixel-level alignment.

**Widget capability**: This API can be used in ArkTS widgets since API version 11.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value | [PixelRoundPolicy](ts-types.md#pixelroundpolicy11) | Yes| Rounding strategy for component pixel-level alignment.<br>**NOTE**<br>This attribute is applicable in scenarios where artifacts occur due to floating-point drawing.<br>The current pixel rounding rule is as follows:<br>In the horizontal direction, the distance from the component's left and right boundaries to the screen's left edge is rounded.<br>In the vertical direction, the distance from the component's top and bottom boundaries to the screen's top edge is rounded.<br>After the rounded positions of the top, bottom, left, and right boundaries are calculated, the final width and height of the component can be determined. Therefore, the rounding result is not only related to the component's width and height but also to its position. Even if the component's width and height are set to be the same, due to different floating-point positions described, the final width and height of the component may also be different after rounding.|

## Example

### Example 1

```ts
// xxx.ets
@Entry
@Component
struct AspectRatioExample {
  private children: string[] = ['1', '2', '3', '4', '5', '6']

  build() {
    Column({ space: 20 }) {
      Text('using container: row').fontSize(14).fontColor(0xCCCCCC).width('100%')
      Row({ space: 10 }) {
        ForEach(this.children, (item:string) => {
          // Component width = Component height x 1.5 = 90
          Text(item)
            .backgroundColor(0xbbb2cb)
            .fontSize(20)
            .aspectRatio(1.5)
            .height(60)
          // Component height = Component width/1.5 = 60/1.5 = 40
          Text(item)
            .backgroundColor(0xbbb2cb)
            .fontSize(20)
            .aspectRatio(1.5)
            .width(60)
        }, (item:string) => item)
      }
      .size({ width: "100%", height: 100 })
      .backgroundColor(0xd2cab3)
      .clip(true)

      // Grid child component width/height = 3/2
      Text('using container: grid').fontSize(14).fontColor(0xCCCCCC).width('100%')
      Grid() {
        ForEach(this.children, (item:string) => {
          GridItem() {
            Text(item)
              .backgroundColor(0xbbb2cb)
              .fontSize(40)
              .width('100%')
              .aspectRatio(1.5)
          }
        }, (item:string) => item)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .size({ width: "100%", height: 165 })
      .backgroundColor(0xd2cab3)
    }.padding(10)
  }
}
```

**Figure 1** Portrait display<br>
![en-us_image_0000001219744205](figures/en-us_image_0000001219744205.PNG)

**Figure 2** Landscape display<br>
![en-us_image_0000001174264382](figures/en-us_image_0000001174264382.PNG)

### Example 2

```ts
class ContainerInfo {
  label: string = '';
  size: string = '';
}

class ChildInfo {
  text: string = '';
  priority: number = 0;
}

@Entry
@Component
struct DisplayPriorityExample {
  // Display the container size.
  private container: ContainerInfo[] = [
    { label: 'Big container', size: '90%' },
    { label: 'Middle container', size: '50%' },
    { label: 'Small container', size: '30%' }
  ]
  private children: ChildInfo[] = [
    { text: '1\n(priority:2)', priority: 2 },
    { text: '2\n(priority:1)', priority: 1 },
    { text: '3\n(priority:3)', priority: 3 },
    { text: '4\n(priority:1)', priority: 1 },
    { text: '5\n(priority:2)', priority: 2 }
  ]
  @State currentIndex: number = 0;

  build() {
    Column({ space: 10 }) {
      // Switch the size of the parent container.
      Button(this.container[this.currentIndex].label).backgroundColor(0x317aff)
        .onClick(() => {
          this.currentIndex = (this.currentIndex + 1) % this.container.length;
        })
      // Set the width for the parent flex container through variables.
      Flex({ justifyContent: FlexAlign.SpaceBetween }) {
        ForEach(this.children, (item:ChildInfo) => {
          // Bind the display priority to the child component through displayPriority.
          Text(item.text)
            .width(120)
            .height(60)
            .fontSize(24)
            .textAlign(TextAlign.Center)
            .backgroundColor(0xbbb2cb)
            .displayPriority(item.priority)
        }, (item:ChildInfo) => item.text)
      }
      .width(this.container[this.currentIndex].size)
      .backgroundColor(0xd2cab3)
    }.width("100%").margin({ top: 50 })
  }
}
```

Landscape display in containers of different sizes

![en-us_image_0000001212058504](figures/en-us_image_0000001212058504.gif)

### Example 3

Example of using **pixelRound**:

```ts
@Entry
@Component
struct PixelRoundExample {
  build() {
    Column() {
      Row() {
        Row() {
        }
        .width('100%')
        .height('100%')
        .backgroundColor(Color.Yellow)
      }
      .width('300.6px')
      .height('300.6px')
      .backgroundColor(Color.Red)
      .position({x: '200.2px', y: '100.2px'})
      .pixelRound({
        start:PixelRoundCalcPolicy.FORCE_CEIL,
        top:PixelRoundCalcPolicy.FORCE_CEIL
       })
    }
    .width("100%")
    .height('100%')
    .backgroundColor('#ffe5e5e5')
  }
}
```
**Figure 1** Layout with pixelRound

![en-us_image_pixel_round_disable.png](figures/en-us_image_pixel_round_enable.png)

**Figure 2** Layout without pixelRound

![en-us_image_pixel_round_disable.png](figures/en-us_image_pixel_round_disable.png)
