# Class (ScrollActionProposal)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1679aa2b39603a323ce91f1907155d8cbd2b330b translatedAt=2026-08-11T01:53:22.257Z pushedAt=2026-08-11T06:05:00.478Z -->

Smart gesture scroll action handling, with the default direction being forward scrolling, including rightward and downward. When dynamically customizing smart gesture behavior through the [registerMonitor](./arkts-apis-uicontext-smartgesturecontroller.md#registermonitor) API, setting **selectedProposal** of the return value [Class (GestureHandlingResolution)](./arkts-apis-uicontext-gesturehandlingresolution.md) to an object of this type triggers the scroll operation of the target component.

**Since**: 26.0.0

## constructor

constructor(node: FrameNode, distance: number)

Constructor for smart gesture scroll action handling.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| node | [FrameNode](js-apis-arkui-frameNode.md#framenode-1) | Yes | Target node that responds to the scroll action. |
| distance | number | Yes | Scroll distance.<br>Value range: [0, +∞). Values less than 0 are treated as 0.<br>Unit: vp. |

## Properties

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| distance | number | No | Yes | Smart gesture scroll distance.<br>Value range: [0, +∞). Values less than 0 are treated as 0.<br>Unit: vp. |

**Example**

This example implements custom smart gesture action handling as smart gesture scroll action handling in the smart gesture listening callback. For the complete example, see [Example 1 (Enabling Smart Gestures and Customizing Action Handling)](./arkts-apis-uicontext-smartgesturecontroller.md#example-1-enabling-smart-gestures-and-customizing-action-handling).

```ts
import {
  BaseGestureHandlingProposal,
  GestureHandlingResolution,
  ScrollActionProposal,
} from '@kit.ArkUI';

@Entry
@Component
struct SmartGestureControllerExample {
  private controller = this.getUIContext().getSmartGestureController();
  private arrayList = [0, 1, 2, 3, 4, 5, 6];
  private smartGestureMonitor = (proposal: BaseGestureHandlingProposal) => {
    let result = new GestureHandlingResolution(true);
    let node = this.getUIContext().getFrameNodeById('target_list');
    if (node) {
      let scrollProposal = new ScrollActionProposal(node, 60);
      result.selectedProposal = scrollProposal;
    }
    return result;
  };

  aboutToAppear(): void {
    this.controller.enableSmartTapAndSlideGestures(true);
    this.controller.registerMonitor(this.smartGestureMonitor);
  }

  aboutToDisappear(): void {
    this.controller.clearMonitors();
    this.controller.enableSmartTapAndSlideGestures(false);
  }

  build() {
    Scroll() {
      Column({ space: 12 }) {
        List({ space: 8 }) {
          ForEach(this.arrayList, (item: number) => {
            ListItem() {
              Column({ space: 6 }) {
                Text(`inner list item ${item}`)
                  .id(`inner_list_item_${item}`)
                  .fontSize(14)
                  .padding(8)
                  .width('100%')
                  .borderRadius(10)
                  .borderWidth(1)
                  .smartGestureShortcut({ action: GestureShortcut.PRIMARY, enabled: true, selectable: true })
                  .onClick(() => {
                    console.info('smartGesture click is triggered');
                  })
              }
              .width('100%')
            }
          }, (item: number) => item.toString())
        }
        .id('target_list')
        .width('100%')
        .height(80)
        .borderRadius(12)
        .borderWidth(1)
      }.width('100%')
    }
    .layoutWeight(1)
    .width('100%')
    .height('100%')
    .padding(12)
  }
}
```

![smartgesture_05](figures/smartgesture_05.png)