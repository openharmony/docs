# NodeController

The **NodeController** module provides APIs for managing custom nodes, such as creating, showing, and updating custom nodes, and APIs for mounting custom nodes to a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> **NodeController** is not available in DevEco Studio Previewer.

## Modules to Import

```ts
import {  NodeController  } from '@kit.ArkUI';
```

## NodeController

Implements a **NodeController** instance to manage the bound [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component. One **NodeController** instance can be bound to only one [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### makeNode

abstract makeNode(uiContext : UIContext): FrameNode | null

Called when the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance is created. This callback returns a node, which will be mounted to the **NodeContainer**.
This callback can also be invoked through the **rebuild()** method of **NodeController**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                                                                                                         |
| --------- | ----------------------------------------- | ---- | ------------------------------------------------------------------------------------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context of the bound **NodeContainer** component.|

**Return value**

| Type            | Description                                                                                                                                                                                                                                                       |
| ---------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [FrameNode](./js-apis-arkui-frameNode.md#framenode)\| null | **FrameNode** object, which will be mounted to the placeholder node of the **NodeContainer** component. If a **null** object is returned, the child nodes of the corresponding **NodeContainer** component are removed.|

### aboutToAppear

aboutToAppear?(): void

Called after the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance is attached and about to appear.

> **NOTE**
>
> For details about the callback timing, see [onAppear](arkui-ts/ts-universal-events-show-hide.md#onappear).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### aboutToDisappear

aboutToDisappear?(): void

Called when the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance is detached and about to be hidden.

> **NOTE**
>
> For details about the callback timing, see [onDisAppear](arkui-ts/ts-universal-events-show-hide.md#ondisappear).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onAttach<sup>18+</sup>

onAttach?(): void

Called when the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance is attached to the main node tree.

> **NOTE**
>
> For details about the callback timing, see [onAttach](arkui-ts/ts-universal-events-show-hide.md#onattach12).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onDetach<sup>18+</sup>

onDetach?(): void

Called when the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance is detached from the main node tree.

> **NOTE**
>
> For details about the callback timing, see [onDetach](arkui-ts/ts-universal-events-show-hide.md#ondetach12).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onWillBind<sup>18+</sup>

onWillBind?(containerId: number): void

Called when this **NodeController** instance is about to be bound to a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                                                                                                         |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | Yes  | ID of the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component to which the **NodeController** instance is about to be bound.|

### onWillUnbind<sup>18+</sup>

onWillUnbind?(containerId: number): void

Called when this **NodeController** instance is about to be unbound from a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                                                                                                         |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | Yes  | ID of the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component from which the **NodeController** instance is about to be unbound.|

### onBind<sup>18+</sup>

onBind?(containerId: number): void

Called after this **NodeController** instance is bound to a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                                                                                                         |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | Yes  | ID of the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component to which the **NodeController** instance is bound.|

### onUnbind<sup>18+</sup>

onUnbind?(containerId: number): void

Called after this **NodeController** instance is unbound from a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                                                                                                         |
| ----------- | ------ |----- |---------------------------------------------------------------------------------------------------------------------------------- |
| containerId | number | Yes  | ID of the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component from which the **NodeController** instance is unbound.|

### aboutToResize

aboutToResize?(size: Size): void

Called when the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance is resized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                    | Mandatory| Description                                    |
| ------ | ---------------------------------------- | ---- | ---------------------------------------- |
| size   | [Size](./js-apis-arkui-graphics.md#size) | Yes  | Width and height of the component, in vp.|

### onTouchEvent

onTouchEvent?(event: TouchEvent): void

Called when the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance receives a touch event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                                     | Mandatory| Description      |
| ------ | ------------------------------------------------------------------------- | ---- | ---------- |
| event  | [TouchEvent](arkui-ts/ts-universal-events-touch.md#touchevent) | Yes  | Touch event.|

### rebuild

rebuild(): void

Instructs the [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component bound to this **NodeController** instance to call the [makeNode](#makenode) API again to change child nodes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

> **NOTE**
> Since the **rebuild** API is actively called by the application and is tied to the UI, you need to ensure that the UI context is valid at the time of the call, that is, it must be consistent with the UI context of the bound NodeContainer.
>
> In cases where the UI context is unclear, for example, during event callbacks, you can use the [runScopedTask](./js-apis-arkui-UIContext.md#runscopedtask) method of [UIContext](./js-apis-arkui-UIContext.md) to explicitly define the UI context at the time of the call.

## Example

### Example 1: Implementing Lifecycle Callbacks for Node Layout, Touch, Mounting, and Unmounting Events

This example demonstrates how to manage the lifecycle of a **NodeContainer** component using **aboutToResize**, **onTouchEvent**,

**aboutToAppear**, and **aboutToDisappear**.

It also shows how to mount a BuilderNode using **NodeController**.

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

### Example 2: Implementing Lifecycle Callbacks for Node Binding/Unbinding and Tree Attachment/Detachment

This example demonstrates how to manage the lifecycle of a **NodeContainer** component when it is attached to or detached from the main node tree and

when it is bound or unbound, using **onAttach**, **onDetach**, **onWillBind**, **onWillUnbind**, **onBind**, and **onUnbind**.

```ts
import { NodeController, BuilderNode, Size, FrameNode, UIContext } from '@kit.ArkUI';
class Params {
  text: string = "this is a text"
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
      this.buttonNode.build(this.wrapBuilder, { text: "This is a Button" })
    }
    return this.buttonNode!.getFrameNode()!;
  }

  onAttach(): void {
    console.log("myButton on attach");
  }

  onDetach(): void {
    console.log("myButton on detach");
  }

  onWillBind(containerId: number): void{
    console.log("myButton on WillBind" + containerId);
  }

  onWillUnbind(containerId: number): void{
    console.log("myButton on WillUnbind" + containerId);
  }

  onBind(containerId: number): void {
    console.log("myButton on bind: " + containerId);
  }

  onUnbind(containerId: number): void {
    console.log("myButton on unbind: " + containerId);
  }
}

@Entry
@Component
struct Index {
  @State buttonShow: boolean = true
  @State buttonIndex: number = 0
  private buttonController: MyNodeController = new MyNodeController();
  private buttonNull: null = null;
  private buttonControllerArray: Array < MyNodeController | null > = [this.buttonController,this.buttonNull]

  build() {
    Column() {
      Row(){
        Button("Bind/Unbind")
          .onClick(() => {
            this.buttonIndex++;
          }).margin(5)
        Button("onAttach/onDetach")
          .onClick(() => {
            this.buttonShow = !this.buttonShow
          }).margin(5)
      }
      if(this.buttonShow){
        NodeContainer(this.buttonControllerArray[this.buttonIndex % this.buttonControllerArray.length])
      }
    }
    .padding({ left: 35, right: 35})
    .width("100%")
    .height("100%")
  }
}
```

![patternlock2](figures/node_controller2.jpg)
