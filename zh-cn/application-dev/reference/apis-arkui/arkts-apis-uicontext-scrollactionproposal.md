# Class (ScrollActionProposal)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

智慧手势滚动动作处理，默认方向为向前滚动，包括向右和向下。当通过[registerMonitor](./arkts-apis-uicontext-smartgesturecontroller.md#registermonitor)接口动态自定义智慧手势行为时，设置返回值[Class (GestureHandlingResolution)](./arkts-apis-uicontext-gesturehandlingresolution.md)的selectedProposal为该类型对象，会触发目标组件的滚动操作。

**起始版本：** 26.0.0

## constructor

constructor(node: FrameNode, distance: number)

智慧手势滚动动作处理的构造函数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| node | [FrameNode](js-apis-arkui-frameNode.md#framenode-1) | 是 | 响应滚动动作的目标节点。 |
| distance | number | 是 | 滚动距离。<br>取值范围：[0, +∞)，小于0时按0处理。<br>单位为vp。 |

## 属性

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| distance | number | 否 | 是 | 智慧手势滚动距离。<br>取值范围：[0, +∞)，小于0时按0处理。<br>单位为vp。 |

**示例：**

本示例实现了在智慧手势监听回调中，自定义智慧手势动作处理为智慧手势滚动动作处理，完整示例请参考[示例1（启用智慧手势并自定义动作处理）](./arkts-apis-uicontext-smartgesturecontroller.md#示例1启用智慧手势并自定义动作处理)。

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
