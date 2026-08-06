# NodeController
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

NodeController用于管理自定义节点的创建、显示、更新等操作，并负责将自定义节点挂载到[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)上，适用于需要在页面中动态创建、更新、复用自定义节点的场景。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - NodeController对象不支持使用JSON序列化。

## 导入模块

```ts
import { NodeController } from '@kit.ArkUI';
```

## NodeController

通常搭配[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)使用。用于创建控制器，管理绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)组件。一个NodeController只允许与一个[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)进行绑定。最佳实践请参考组件动态创建-[组件动态添加、更新和删除](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/arkts-ui-component-dynamic-creation#组件动态添加更新和删除)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### makeNode

abstract makeNode(uiContext : UIContext): FrameNode | null

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)创建时触发此回调。回调方法将返回一个节点，该节点将被挂载至[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)。

或者可以通过NodeController的rebuild()方法触发回调。

> **说明：**
>
> [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)不支持跨实例复用。如果出现跨实例复用[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)，传入[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的[NodeController](#nodecontroller-1)触发[makeNode](#makenode)回调方法时，入参中的[UIContext](./arkts-apis-uicontext-uicontext.md)对象可能为undefined，此时需要开发者判断该对象是否为undefined，防止后续使用此入参时出现[UIContext无效的JS异常](../../ui/arkts-wrong-uicontext-debug.md#定位uicontext错误问题)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                                                                                                          |
| --------- | ----------------------------------------- | ---- | ------------------------------------------------------------------------------------------------------------- |
| uiContext | [UIContext](./arkts-apis-uicontext-uicontext.md) | 是   | 回调该方法时，绑定[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的UI上下文。跨实例复用[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)时，该参数可能为undefined，需要开发者自行判断。 |

**返回值：**

| 类型             | 说明                                                                                                                                                                                                                                                        |
| ---------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [FrameNode](./js-apis-arkui-frameNode.md) \| null | 一个FrameNode对象，返回的节点将被挂载至[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的占位节点上。若返回null对象，将清空对应[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的子节点。 |

### aboutToAppear

aboutToAppear?(): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)挂载显示后触发此回调。

> **说明：**
>
> 回调时机参考[onAppear](arkui-ts/ts-universal-events-show-hide.md#onappear)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### aboutToDisappear

aboutToDisappear?(): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)销毁时触发此回调。

> **说明：**
>
> 回调时机参考[onDisAppear](arkui-ts/ts-universal-events-show-hide.md#ondisappear)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onAttach<sup>18+</sup>

onAttach?(): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)挂载至主节点树时触发此回调。与[aboutToAppear](#abouttoappear)不同，aboutToAppear在NodeContainer挂载显示后触发，onAttach在NodeContainer挂载至主节点树时触发，两者触发时机可能不同。

> **说明：**
>
> 回调时机参考[onAttach](arkui-ts/ts-universal-events-show-hide.md#onattach12)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onDetach<sup>18+</sup>

onDetach?(): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)从主节点树卸载时触发此回调。与[aboutToDisappear](#abouttodisappear)不同，aboutToDisappear在NodeContainer销毁时触发，onDetach在NodeContainer从主节点树卸载时触发，两者触发时机可能不同。

> **说明：**
>
> 回调时机参考[onDetach](arkui-ts/ts-universal-events-show-hide.md#ondetach12)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillBind<sup>18+</sup>

onWillBind?(containerId: number): void

当NodeController与[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)即将绑定前触发此回调。该回调先于[onBind](#onbind18)触发，两者均为可选回调，可根据需要在绑定前或绑定后执行相应逻辑。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                                                                                                          |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | 是   | 回调该方法时，即将与NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的标识。|

### onWillUnbind<sup>18+</sup>

onWillUnbind?(containerId: number): void

当NodeController与[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)即将解绑前触发此回调。该回调先于[onUnbind](#onunbind18)触发，两者均为可选回调，可根据需要在解绑前或解绑后执行相应逻辑。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                                                                                                          |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | 是   | 回调该方法时，即将与NodeController解绑的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的标识。|

### onBind<sup>18+</sup>

onBind?(containerId: number): void

当NodeController与[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)绑定后触发此回调。该回调后于[onWillBind](#onwillbind18)触发，两者均为可选回调，可根据需要在绑定前或绑定后执行相应逻辑。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                                                                                                          |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | 是   | 回调该方法时，已完成与NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的标识。|

### onUnbind<sup>18+</sup>

onUnbind?(containerId: number): void

当NodeController与[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)解绑后触发此回调。该回调后于[onWillUnbind](#onwillunbind18)触发，两者均为可选回调，可根据需要在解绑前或解绑后执行相应逻辑。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                                                                                                          |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | 是   | 回调该方法时，已完成与NodeController解绑的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)的标识。|

### aboutToResize

aboutToResize?(size: Size): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)布局时触发此回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                                     |
| ------ | ---------------------------------------- | ---- | ---------------------------------------- |
| size   | [Size](./js-apis-arkui-graphics.md#size) | 是   | 组件布局大小的宽和高，单位为vp。 |

### onTouchEvent

onTouchEvent?(event: TouchEvent): void

当NodeController绑定的[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)收到触摸事件时触发此回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                                      | 必填 | 说明       |
| ------ | ------------------------------------------------------------------------- | ---- | ---------- |
| event  | [TouchEvent](arkui-ts/ts-universal-events-touch.md#touchevent对象说明) | 是   | 触摸事件，包含触摸点的坐标、触摸动作类型等信息，具体结构详见TouchEvent。 |

### rebuild

rebuild(): void

调用此接口通知[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md)组件重新回调[makeNode](#makenode)方法，更改子节点。例如，当NodeContainer展示的内容数据发生变化、需要更新显示的子节点时，可调用此方法触发重新构建。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

> **说明：**
>
> 由于rebuild方法为应用主动调用的方法，且该操作与UI相关，需要开发者自行保证调用该接口时UI上下文有效，即与绑定的NodeContainer保持UI上下文一致。
>
> 监听回调等[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)时，可以通过[UIContext](./arkts-apis-uicontext-uicontext.md)的[runScopedTask](./arkts-apis-uicontext-uicontext.md#runscopedtask)方法明确调用时的UI上下文。

## 示例

### 示例1（添加节点布局、Touch、挂载和销毁时的生命周期回调）

该示例通过aboutToResize、onTouchEvent，实现了NodeContainer节点布局、收到Touch事件时的生命周期回调功能。

并通过aboutToAppear、aboutToDisappear接口，实现了NodeContainer节点挂载、销毁时的生命周期回调功能。

该示例还通过NodeController挂载BuilderNode节点。

```ts
import { NodeController, BuilderNode, Size, FrameNode, UIContext } from '@kit.ArkUI';

class Params {
  text: string = 'this is a text';
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
      this.buttonNode.build(this.wrapBuilder, { text: 'This is a Button' });
    }
    return this.buttonNode!.getFrameNode()!;
  }

  aboutToResize(size: Size) {
    console.info(`aboutToResize width : ${size.width} height : ${size.height}`);
  }

  aboutToAppear() {
    console.info('aboutToAppear');
  }

  aboutToDisappear() {
    this.buttonNode?.dispose();
    console.info('aboutToDisappear');
  }

  onTouchEvent(event: TouchEvent) {
    console.info('onTouchEvent');
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
    .width('100%')
    .height('100%')
  }
}
```
![nodecontroller](figures/node_controller.jpg)

### 示例2（添加节点上下树和绑定解绑前后的生命周期回调）

该示例通过onAttach、onDetach接口，实现了NodeContainer节点上下主节点树的生命周期回调功能。

并通过onWillBind、onWillUnbind、onBind、onUnbind接口，实现了NodeContainer节点绑定和解绑前后的生命周期回调功能。

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

class Params {
  text: string = 'this is a text';
}

@Builder
function buttonBuilder(params: Params) {
  Column() {
    Button(params.text)
      .fontSize(20)
      .borderRadius(8)
      .borderWidth(2)
      .backgroundColor(Color.Grey)
  }
}

class MyNodeController extends NodeController {
  private buttonNode: BuilderNode<[Params]> | null = null;
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(buttonBuilder);

  makeNode(uiContext: UIContext): FrameNode {
    if (this.buttonNode == null) {
      this.buttonNode = new BuilderNode(uiContext);
      this.buttonNode.build(this.wrapBuilder, { text: 'This is a Button' });
    }
    return this.buttonNode!.getFrameNode()!;
  }

  onAttach(): void {
    console.info('myButton on attach');
  }

  onDetach(): void {
    console.info('myButton on detach');
  }

  onWillBind(containerId: number): void {
    console.info(`myButton on WillBind${containerId}`);
  }

  onWillUnbind(containerId: number): void {
    console.info(`myButton on WillUnbind${containerId}`);
  }

  onBind(containerId: number): void {
    console.info(`myButton on bind: ${containerId}`);
  }

  onUnbind(containerId: number): void {
    console.info(`myButton on unbind: ${containerId}`);
  }

  aboutToDisappear() {
    this.buttonNode?.dispose();
  }
}

@Entry
@Component
struct Index {
  @State buttonShow: boolean = true;
  @State buttonIndex: number = 0;
  private buttonController: MyNodeController = new MyNodeController();
  private buttonNull: null = null;
  private buttonControllerArray: Array<MyNodeController | null> = [this.buttonController, this.buttonNull];

  build() {
    Column() {
      Row() {
        Button('Bind/Unbind')
          .onClick(() => {
            this.buttonIndex++;
          }).margin(5)
        Button('onAttach/onDetach')
          .onClick(() => {
            this.buttonShow = !this.buttonShow;
          }).margin(5)
      }

      if (this.buttonShow) {
        NodeContainer(this.buttonControllerArray[this.buttonIndex % this.buttonControllerArray.length])
      }
    }
    .padding({ left: 35, right: 35 })
    .width('100%')
    .height('100%')
  }
}
```

![nodecontroller2](figures/node_controller2.jpg)
