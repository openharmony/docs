# Class (BaseGestureHandlingProposal)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1679aa2b39603a323ce91f1907155d8cbd2b330b translatedAt=2026-08-11T01:52:47.083Z pushedAt=2026-08-11T06:04:50.152Z -->

Base class for smart gesture handling. When the [registerMonitor](./arkts-apis-uicontext-smartgesturecontroller.md#registermonitor) API is used to dynamically customize smart gesture behaviors, the callback parameter is an instance of a specific subclass type.

**Since**: 26.0.0

## Properties

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| action | [SmartGestureAction](arkui-ts/ts-appendix-enums.md#smartgestureaction) | No | No | Final action executed by the smart gesture. |
| operateIntention | [OperateIntention](arkui-ts/ts-appendix-enums.md#operateintention) | No | No | Underlying operation intention of the smart gesture. |

**Example**

This example demonstrates how to obtain smart gesture handling information from BaseGestureHandlingProposal in the smart gesture listening callback. For the complete example, see [Example 1 (Enabling Smart Gestures and Customizing Action Handling)](./arkts-apis-uicontext-smartgesturecontroller.md#example-1-enabling-smart-gestures-and-customizing-action-handling).

```ts
import {
  BaseGestureHandlingProposal, GestureHandlingResolution,
} from '@kit.ArkUI';

@Entry
@Component
struct SmartGestureControllerExample {
  private controller = this.getUIContext().getSmartGestureController();
  private smartGestureMonitor = (proposal: BaseGestureHandlingProposal) => {
    console.info('smartGesture action is ', proposal.action, ', operateIntention is ', proposal.operateIntention);
    return new GestureHandlingResolution(true);
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
        Text('Text component')
          .id('target_text')
          .fontSize(18)
          .width('100%')
          .padding(12)
          .borderRadius(10)
          .borderWidth(1)
          .smartGestureShortcut({ action: GestureShortcut.PRIMARY, enabled: true, selectable: true })
          .onClick(() => {
            console.info('smartGesture click is triggered');
          })
      }.width('100%')
    }
    .layoutWeight(1)
    .width('100%')
    .height('100%')
    .padding(12)
  }
}
```

![smartgesture_01](figures/smartgesture_01.PNG)