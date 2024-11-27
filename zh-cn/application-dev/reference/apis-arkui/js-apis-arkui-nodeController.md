# NodeController

NodeController用于实现自定义节点的创建、显示、更新等操作的管理，并负责将自定义节点挂载到[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)上。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 当前不支持在预览器中使用NodeController。

## 导入模块

```ts
import {  NodeController  } from '@kit.ArkUI';
```

## NodeController

通常搭配[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)进行使用。用于创建控制器管理绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)组件。一个NodeController只允许与一个[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)进行绑定。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### makeNode

abstract makeNode(uiContext : UIContext): FrameNode | null

当实例绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)创建的时候进行回调。回调方法将返回一个节点，将该节点挂载至[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)。
或者可以通过NodeController的rebuild()方法进行回调的触发。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                                                                                                          |
| --------- | ----------------------------------------- | ---- | ------------------------------------------------------------------------------------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 回调该方法的时候，绑定[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)的UI上下文。 |

**返回值：**

| 类型             | 说明                                                                                                                                                                                                                                                        |
| ---------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [FrameNode](./js-apis-arkui-frameNode.md#framenode)\| null | 一个FrameNode对象，返回的节点将被挂载至[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)的占位节点上。若返回null对象，将清空对应[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)的子节点。 |

### aboutToAppear

aboutToAppear?(): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)挂载显示后触发此回调。

> **说明：**
>
> 回调时机参考[onAppear](arkui-ts/ts-universal-events-show-hide.md#onappear)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### aboutToDisappear

aboutToDisappear?(): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)卸载消失时触发此回调。

> **说明：**
>
> 回调时机参考[onDisAppear](arkui-ts/ts-universal-events-show-hide.md#ondisappear)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### aboutToResize

aboutToResize?(size: Size): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)布局的时候触发此回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                                     |
| ------ | ---------------------------------------- | ---- | ---------------------------------------- |
| size   | [Size](./js-apis-arkui-graphics.md#size) | 是   | 用于返回组件布局大小的宽和高，单位为vp。 |

### onTouchEvent

onTouchEvent?(event: TouchEvent): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)收到Touch事件时触发此回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                                      | 必填 | 说明       |
| ------ | ------------------------------------------------------------------------- | ---- | ---------- |
| event  | [TouchEvent](arkui-ts/ts-universal-events-touch.md#touchevent对象说明) | 是   | 触摸事件。 |

### rebuild

rebuild(): void

调用此接口通知[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)组件重新回调[makeNode](#makenode)方法，更改子节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

> **说明：**
> 由于rebuild方法为应用主动调用的方法，且该操作与UI相关。需要开发者自行保证调用该接口时UI上下文有效，即与绑定的NodeContainer保持UI上下文一致。
>
> 监听回调等UI上下文不明确时，可以通过[UIContext](./js-apis-arkui-UIContext.md)的[runScopedTask](./js-apis-arkui-UIContext.md#runscopedtask)方法明确调用时的UI上下文。

### 示例

```ts
import {  NodeController, BuilderNode, Size, FrameNode ,UIContext } from '@kit.ArkUI';

class Params {
  text: string = "this is a text"
}

@Builder
function buttonBuilder(params: Params) {
  Column() {
    Button(params.text)
      .fontSize(12)
      .borderRadius(8)
      .borderWidth(2)
      .backgroundColor(Color.Orange)
  }
}

class MyNodeController extends NodeController {
  private buttonNode: BuilderNode<[Params]> | null = null;
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(buttonBuilder);

  makeNode(uiContext: UIContext): FrameNode {
    if (this.buttonNode == null) {
      this.buttonNode = new BuilderNode(uiContext);
      this.buttonNode.build(this.wrapBuilder, { text: "This is a Button" })
    }
    return this.buttonNode!.getFrameNode()!;
  }

  aboutToResize(size: Size) {
    console.log("aboutToResize width : " + size.width + " height : " + size.height)
  }

  aboutToAppear() {
    console.log("aboutToAppear")
  }

  aboutToDisappear() {
    console.log("aboutToDisappear");
  }

  onTouchEvent(event:TouchEvent) {
    console.log("onTouchEvent");
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
    }
    .padding({ left: 35, right: 35, top: 35 })
    .width("100%")
    .height("100%")
  }
}
```
![patternlock](figures/node_controller.jpg)