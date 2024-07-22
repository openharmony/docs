# FrameNode

**FrameNode** represents an entity node in the component tree. It can be used by a [NodeController](./js-apis-arkui-nodeController.md#nodecontroller) to mount a [BuilderNode](./js-apis-arkui-builderNode.md#buildernode) (that holds the FrameNode) to a [\<NodeContainer>](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) or mount a [RenderNode](./js-apis-arkui-renderNode.md#rendernode) to another FrameNode.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> **FrameNode** is not available in DevEco Studio Previewer.
>
> FrameNodes cannot be dragged.

## Modules to Import

```ts
import { FrameNode, LayoutConstraint, typeNode, NodeAdapter } from "@kit.ArkUI";
```

## FrameNode

### constructor

constructor(uiContext: UIContext)

Constructor used to create a FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory | Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |

### getRenderNode

getRenderNode(): RenderNode | null

Obtains the RenderNode instance held in this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                                                            |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [RenderNode](./js-apis-arkui-renderNode.md#rendernode) \| null | **RenderNode** instance. If the current FrameNode does not hold any RenderNode, **null** is returned. If the current FrameNode is a node created by a declarative component, **null** is returned. |

**Example**

```ts
import { NodeController, FrameNode } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const renderNode = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      renderNode.size = { width: 100, height: 100 };
      renderNode.backgroundColor = 0XFFFF0000;
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```
### isModifiable<sup>12+</sup> 

isModifiable(): boolean

Checks whether this FrameNode is modifiable.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type   | Description                                                                                                                                 |
| ------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| boolean | Whether the current FrameNode is modifiable. When **false** is returned, the FrameNode does not support the **appendChild**, **insertChildAfter**, **removeChild**, and **clearChildren** operations. |

**Example**

See [Node Operation Example](#node-operation-example).

### appendChild<sup>12+</sup> 

appendChild(node: FrameNode): void

Appends a child node to this FrameNode. If this FramNode is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                   | Mandatory | Description                 |
| ------ | ----------------------- | ---- | --------------------- |
| node   | [FrameNode](#framenode) | Yes  | Child node to append.<br>**NOTE**<br> The child node cannot be one created declaratively, which is not modifiable. Only declarative nodes obtained from a BuilderNode can be used as child nodes. If the child node does not meet the specifications, an exception is thrown.<br> The FrameNode cannot have a parent node. Otherwise, an exception is thrown.|

**Error codes**

| ID | Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Node Operation Example](#node-operation-example).

### insertChildAfter<sup>12+</sup> 

insertChildAfter(child: FrameNode, sibling: FrameNode | null): void

Inserts a child node after the specified child node of this FramNode. If this FramNode is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                     | Mandatory | Description                                                                        |
| ------- | ----------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| child   | [FrameNode](#framenode)                   | Yes  | Child node to add.<br>**NOTE**<br> The child node cannot be a declarative node, that is, a FrameNode that cannot be modified. Only declarative nodes obtained from a BuilderNode can be used as child nodes. If the child node does not meet the specifications, an exception is thrown.<br> The child node cannot have a parent node. Otherwise, an exception is thrown.                                                          |
| sibling | [FrameNode](#framenode)&nbsp;\|&nbsp;null | Yes  | Node after which the new child node will be inserted. If this parameter is left empty, the new node is inserted before the first subnode. |

**Error codes**

| ID | Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Node Operation Example](#node-operation-example).

### removeChild<sup>12+</sup> 

removeChild(node: FrameNode): void

Deletes the specified child node from this FrameNode. If this FramNode is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                   | Mandatory | Description              |
| ------ | ----------------------- | ---- | ------------------ |
| node   | [FrameNode](#framenode) | Yes  | Child node to delete. |

**Error codes**

| ID | Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Node Operation Example](#node-operation-example).

### clearChildren<sup>12+</sup> 

clearChildren(): void

Clears all child nodes of this FrameNode. If this FramNode is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Error codes**

| ID | Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Node Operation Example](#node-operation-example).

### getChild<sup>12+</sup> 

getChild(index: number): FrameNode | null

Obtains the child node in the specified position of this RenderNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| index  | number | Yes  | Index of the child node to obtain. |

**Return value**

| Type                           | Description                                                         |
| ------------------------------- | ------------------------------------------------------------- |
| [FrameNode](#framenode) \| null | Child node obtained. If the FrameNode does not contain the specified child node, null is returned. |

**Example**

See [Node Operation Example](#node-operation-example).
### getFirstChild<sup>12+</sup> 

getFirstChild(): FrameNode | null

Obtains the first child node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                           | Description                                                     |
| ------------------------------- | --------------------------------------------------------- |
| [FrameNode](#framenode) \| null | First child node. If the FrameNode does not contain any child node, null is returned. |

**Example**

See [Node Operation Example](#node-operation-example).

### getNextSibling<sup>12+</sup> 

getNextSibling(): FrameNode | null

Obtains the next sibling node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                           | Description                                                                                |
| ------------------------------- | ------------------------------------------------------------------------------------ |
| [FrameNode](#framenode) \| null | Next sibling node of the current FrameNode. If the FrameNode does not have the next sibling node, null is returned. |

**Example**

See [Node Operation Example](#node-operation-example).

### getPreviousSibling<sup>12+</sup> 

getPreviousSibling(): FrameNode | null

Obtains the previous sibling node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                                                                                |
| -------------------------------- | ------------------------------------------------------------------------------------ |
| [FrameNode](#framenode) \| null | Previous sibling node of the current FrameNode. If the FrameNode does not have the previous sibling node, null is returned. |

**Example**

See [Node Operation Example](#node-operation-example).

### getParent<sup>12+</sup> 

getParent(): FrameNode | null;

Obtains the parent node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                                                                |
| -------------------------------- | -------------------------------------------------------------------- |
| [FrameNode](#framenode) \| null | Parent node of the current FrameNode. If the FrameNode does not contain a parent node, null is returned. |

**Example**

See [Node Operation Example](#node-operation-example).


### getChildrenCount<sup>12+</sup> 

  getChildrenCount(): number;

Obtains the number of child nodes of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                           |
| -------- | ------------------------------- |
| number | Number of child nodes of the current FrameNode. |

**Example**

See [Node Operation Example](#node-operation-example).

### getPositionToWindow<sup>12+</sup> 

  getPositionToWindow(): Position

Obtains the position offset of this FrameNode relative to the window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                           |
| -------- | ------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the window. |

**Example**

See [Node Operation Example](#node-operation-example).


### getPositionToParent<sup>12+</sup>

getPositionToParent(): Position

Obtains the position offset of this FrameNode relative to the parent component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the parent component. |

**Example**

See [Node Operation Example](#node-operation-example).

### getPositionToScreen<sup>12+</sup> 

  getPositionToScreen(): Position

Obtains the position offset of this FrameNode relative to the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                           |
| -------- | ------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the screen. |

**Example**

See [Node Operation Example](#node-operation-example).


### getPositionToParentWithTransform<sup>12+</sup>

getPositionToParentWithTransform(): Position

Obtains the position offset of this FrameNode relative to the parent component, taking into account drawing attributes such as **transform** and **translate**. The coordinates returned are the coordinates of the upper left corner during layout after transformation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the parent component. If other drawing attributes (such as **transform** and **translate**) are set, the return value may slightly deviate due to the precision of floating point numbers. |

**Example**

See [Node Operation Example](#node-operation-example).

### getPositionToWindowWithTransform<sup>12+</sup>

getPositionToWindowWithTransform(): Position

Obtains the position offset of this FrameNode relative to the window, taking into account drawing attributes such as **transform** and **translate**. The coordinates returned are the coordinates of the upper left corner during layout after transformation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the window. If other drawing attributes (such as **transform** and **translate**) are set, the return value may slightly deviate due to the precision of floating point numbers. |

**Example**

See [Node Operation Example](#node-operation-example).

### getPositionToScreenWithTransform<sup>12+</sup>

getPositionToScreenWithTransform(): Position

Obtains the position offset of this FrameNode relative to the screen, taking into account drawing attributes such as **transform** and **translate**. The coordinates returned are the coordinates of the upper left corner during layout after transformation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the screen. If other drawing attributes (such as **transform** and **translate**) are set, the return value may slightly deviate due to the precision of floating point numbers. |

**Example**

See [Node Operation Example](#node-operation-example).


### getMeasuredSize<sup>12+</sup>

getMeasuredSize(): Size

Obtains the measured size of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Size](./js-apis-arkui-graphics.md#size) | Measured size of the node. |

**Example**

See [Node Operation Example](#node-operation-example).


### getLayoutPosition<sup>12+</sup>

getLayoutPosition(): Position

Obtains the position offset of this FrameNode relative to the parent component after layout. The offset is the result of the parent component's layout on this node; therefore, the **offset** attribute that takes effect after layout and the **position** attribute that does not participate in layout do not affect this offset value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset relative to the parent component after layout. |

**Example**

See [Node Operation Example](#node-operation-example).

### getUserConfigBorderWidth<sup>12+</sup>

getUserConfigBorderWidth(): Edges\<LengthMetrics\>

Obtains the border width set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Border width set by the user. |

**Example**

See [Node Operation Example](#node-operation-example).

### getUserConfigPadding<sup>12+</sup>

getUserConfigPadding(): Edges\<LengthMetrics\>

Obtains the padding set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Padding set by the user. |

**Example**

See [Node Operation Example](#node-operation-example).

### getUserConfigMargin<sup>12+</sup>

getUserConfigMargin(): Edges\<LengthMetrics\>

Obtains the margin set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Margin set by the user. |

**Example**

See [Node Operation Example](#node-operation-example).

### getUserConfigSize<sup>12+</sup>

getUserConfigSize(): SizeT\<LengthMetrics\>

Obtains the width and height set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                        | Description            |
| ------------------------------------------------------------ | ---------------- |
| [SizeT](./js-apis-arkui-graphics.md#sizet12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Width and height set by the user. |

**Example**

See [Node Operation Example](#node-operation-example).

### getId<sup>12+</sup>

getId(): string

Obtains the node ID set by the user (the [ID](./arkui-ts/ts-universal-attributes-component-id.md) set in the universal attributes).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| string | Node ID set by the user (the [ID](./arkui-ts/ts-universal-attributes-component-id.md) set in the universal attributes). |

**Example**

See [Node Operation Example](#node-operation-example).

### getUniqueId<sup>12+</sup>

getUniqueId(): number

Obtains the system-assigned unique ID of the node.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| number | System-assigned unique ID of the node. |

**Example**

See [Node Operation Example](#node-operation-example).

### getNodeType<sup>12+</sup>

getNodeType(): string

Obtains the type of the node. Built-in component types are named after the components themselves, for example, the type of a **\<Button>** component is Button. For custom components, if they have rendering content, their type is __Common__.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| string | Type of the node. |

**Example**

See [Node Operation Example](#node-operation-example).

### getOpacity<sup>12+</sup>

getOpacity(): number

Obtains the opacity of the node. The minimum value is 0, and the maximum value is 1.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| number | Opacity of the node. |

**Example**

See [Node Operation Example](#node-operation-example).

### isVisible<sup>12+</sup>

isVisible(): boolean

Obtains whether the node is visible.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | Whether the node is visible. |

**Example**

See [Node Operation Example](#node-operation-example).

### isClipToFrame<sup>12+</sup>

isClipToFrame(): boolean

Obtains whether the node is clipped to the component area.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | Whether the node is clipped to the component area. |

**Example**

See [Node Operation Example](#node-operation-example).

### isAttached<sup>12+</sup>

isAttached(): boolean

Obtains whether the node is mounted to the main node tree.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | Whether the node is mounted to the main node tree. |

**Example**

See [Node Operation Example](#node-operation-example).

### getInspectorInfo<sup>12+</sup>

getInspectorInfo(): Object

Obtains the structure information of the node, which is consistent with what is found in DevEco Studio's built-in ArkUI Inspector tool.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| Object | Structure information of the node. |

**Example**

See [Node Operation Example](#node-operation-example).

### getCustomProperty<sup>12+</sup>

getCustomProperty(name: string): Object | undefined

Obtains the component's custom property by its name.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type                                                | Mandatory | Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name  | string | Yes  | Name of the custom property. |

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| Object \| undefined | Value of the custom property. |

**Example**

See [Node Operation Example](#node-operation-example).

### dispose<sup>12+</sup>

dispose(): void

Disposes of thisFrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { NodeController, FrameNode, BuilderNode } from '@kit.ArkUI';

@Component
struct TestComponent {
  build() {
    Column() {
      Text('This is a BuilderNode.')
        .fontSize(16)
        .fontWeight(FontWeight.Bold)
    }
    .width('100%')
    .backgroundColor(Color.Gray)
  }

  aboutToAppear() {
    console.error('aboutToAppear');
  }

  aboutToDisappear() {
    console.error('aboutToDisappear');
  }
}

@Builder
function buildComponent() {
  TestComponent()
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private builderNode: BuilderNode<[]> | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.builderNode = new BuilderNode(uiContext, { selfIdealSize: { width: 200, height: 100 } });
    this.builderNode.build(new WrappedBuilder(buildComponent));

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.size = { width: 200, height: 200 };
      rootRenderNode.backgroundColor = 0xff00ff00;
      rootRenderNode.appendChild(this.builderNode!.getFrameNode()!.getRenderNode());
    }

    return this.rootNode;
  }

  disposeFrameNode() {
    if (this.rootNode !== null && this.builderNode !== null) {
      this.rootNode.removeChild(this.builderNode.getFrameNode());
      this.builderNode.dispose();

      this.rootNode.dispose();
    }
  }

  removeBuilderNode() {
    const rootRenderNode = this.rootNode!.getRenderNode();
    if (rootRenderNode !== null && this.builderNode !== null && this.builderNode.getFrameNode() !== null) {
      rootRenderNode.removeChild(this.builderNode!.getFrameNode()!.getRenderNode());
    }
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column({ space: 4 }) {
      NodeContainer(this.myNodeController)
      Button('FrameNode dispose')
        .onClick(() => {
          this.myNodeController.disposeFrameNode();
        })
        .width('100%')
    }
  }
}
```

### commonAttribute<sup>12+</sup>

get commonAttribute(): CommonAttribute

Obtains the **CommonAttribute** API held in this FrameNode to set common attributes.

Only the attributes of nodes created using commands can be modified.

Attributes passed as [CustomBuilder](./arkui-ts/ts-types.md#custombuilder8) or lambda expressions are not supported; events and gestures are not supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                                                            |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| CommonAttribute | **CommonAttribute** API held in this FrameNode to set common attributes.|

> **NOTE**
>
> For details about the range and effect supported by the basic attributes of the FrameNode, see the [Stack](./arkui-ts/ts-container-stack.md) container with an alignment of **start** at the top

**Example**

See [Basic Event Example](#basic-event-example).

### commonEvent<sup>12+</sup>

get commonEvent(): UICommonEvent

Obtains the **UICommonEvent **object held in this FrameNode to set basic events. The set basic events will coexist with declaratively defined events and participate in the event handling process without overriding them. When two event callbacks are set at the same time, the declaratively defined event is triggered first.

In scenarios involving **LazyForEach**, where nodes may be destroyed and reconstructed, you need to reset or re-attach event listeners to the newly created nodes to ensure they respond to events correctly.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                                                            |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [UICommonEvent](./arkui-ts/ts-uicommonevent.md#common-event-callback) | **UICommonEvent** object, which is used to set basic events. |

**Example**

For details, see [Basic Event Example](#basic-event-example) and [Example of Using Basic Events in the LazyForEach Scenario](#example-of-using-basic-events-in-the-lazyforeach-scenario).

### onDraw<sup>12+</sup>

onDraw?(context: DrawContext): void

Called when this FrameNode performs content rendering.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| context | [DrawContext](./js-apis-arkui-graphics.md#drawcontext) | Yes  | Graphics drawing context. The self-drawing area cannot exceed the component's own size. |

**Example**

See [Example of Node Customization](#example-of-node-customization).

### onMeasure<sup>12+</sup>

onMeasure(constraint: LayoutConstraint): void

Called when this FrameNode needs to determine its size. This API provides custom measurement and overrides the default measurement method.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| constraint | [LayoutConstraint](#layoutconstraint12) | Yes  | Layout constraints used by the component for measurement. |

**Example**

See [Example of Node Customization](#example-of-node-customization).

### LayoutConstraint<sup>12+</sup>

Describes the layout constraints of the component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           |  Type | Mandatory | Description                                      |
| -------------- | ------ | ----- | ------------------------------------------ |
| maxSize           | [Size](./js-apis-arkui-graphics.md#size) | Yes   | Maximum size.             |
| minSize            | [Size](./js-apis-arkui-graphics.md#size) | Yes   | Minimum size.                 |
| percentReference      | [Size](./js-apis-arkui-graphics.md#size) | Yes   | Size reference for calculating the percentage of a child node.

### onLayout<sup>12+</sup>

onLayout(position: Position): void

Called when this FrameNode needs to determine its layout. This API provides custom layout and overrides the default layout method. It can be used to specify how the FrameNode and its child nodes are positioned and sized within the layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | Yes  | Position information used in layout. |

**Example**

See [Example of Node Customization](#example-of-node-customization).

### setMeasuredSize<sup>12+</sup>

setMeasuredSize(size: Size): void

Sets the measured size of this FrameNode. The default unit is PX. If the configured width and height are negative numbers, the value is automatically set to 0.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| size | [Size](./js-apis-arkui-graphics.md#size) | Yes  | Measured size of the FrameNode. |

**Example**

See [Example of Node Customization](#example-of-node-customization).

### setLayoutPosition<sup>12+</sup>

setLayoutPosition(position: Position): void

Sets the position of this FrameNode after layout. The default unit is PX.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | Yes  | Position of the FrameNode after layout. |

**Example**

See [Example of Node Customization](#example-of-node-customization).

### measure<sup>12+</sup>

measure(constraint: LayoutConstraint): void

Measures this FrameNode and calculates its size based on the layout constraints of the parent container. If the measurement method is overridden, the overridden method is called. It is recommended that this API be called in [onMeasure](#onmeasure12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| constraint | [LayoutConstraint](#layoutconstraint12) | Yes  | Parent container layout constraints used for measurement. |

**Example**

See [Example of Node Customization](#example-of-node-customization).

### layout<sup>12+</sup>

layout(position: Position): void

Lays out this FrameNode, specifying the layout positions for the FrameNode and its child nodes. If the layout method is overridden, the overridden method is called. It is recommended that this API be called in [onLayout](#onlayout12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | Yes  | Position information used in layout. |

**Example**

See [Example of Node Customization](#example-of-node-customization).

### setNeedsLayout<sup>12+</sup>

setNeedsLayout(): void

Marks this FrameNode as needing layout, so that it will be relaid out in the next frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

See [Example of Node Customization](#example-of-node-customization).

### invalidate<sup>12+</sup>

invalidate(): void

Invalidates this FrameNode to trigger a re-rendering of the self-drawing content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### addComponentContent<sup>12+</sup>

addComponentContent\<T>(content: ComponentContent\<T>): void

Adds component content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| content | [ComponentContent](./js-apis-arkui-ComponentContent.md#componentcontent)\<T> | Yes  | Component content to display on the FrameNode. |

```ts
import { typeNode, NodeController, FrameNode, ComponentContent } from '@ohos.arkui.node';

@Builder
function buildText() {
  Column() {
    Text('hello')
      .width(50)
      .height(50)
      .backgroundColor(Color.Yellow)
  }
}

class MyNodeController extends NodeController {
  makeNode(uiContext: UIContext): FrameNode | null {
    let node = new FrameNode(uiContext)
    node.commonAttribute.width(300).height(300).backgroundColor(Color.Red)
    let col = typeNode.createNode(uiContext, "Column")
    col.initialize({ space: 10 })
    node.appendChild(col)
    let row4 = typeNode.createNode(uiContext, "Row")
    row4.attribute.width(200)
      .height(200)
      .borderWidth(1)
      .borderColor(Color.Black)
      .backgroundColor(Color.Green)
    let component = new ComponentContent<Object>(uiContext, wrapBuilder(buildText))
    row4.addComponentContent(component)
    col.appendChild(row4)
    return node
  }
}

@Entry
@Component
struct FrameNodeTypeTest {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController);
    }
  }
}
```

### disposeTree<sup>12+</sup>

disposeTree(): void

Traverses down the tree and recursively releases the subtree with this node as the root.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

```ts
import { FrameNode, NodeController, BuilderNode } from "@kit.ArkUI"

@Component
struct TestComponent {
  private myNodeController: MyNodeController = new MyNodeController(wrapBuilder(buildComponent2));

  build() {
    Column() {
      Text('This is a BuilderNode.')
        .fontSize(16)
        .fontWeight(FontWeight.Bold)
      NodeContainer(this.myNodeController)
    }
    .width('100%')
    .backgroundColor(Color.Gray)
  }

  aboutToAppear() {
    console.error('BuilderNode aboutToAppear');
  }

  aboutToDisappear() {
    console.error('BuilderNode aboutToDisappear');
  }
}

@Component
struct TestComponent2 {
  private myNodeController: MyNodeController = new MyNodeController(wrapBuilder(buildComponent3));
  private myNodeController2: MyNodeController = new MyNodeController(wrapBuilder(buildComponent4));

  build() {
    Column() {
      Text('This is a BuilderNode 2.')
        .fontSize(16)
        .fontWeight(FontWeight.Bold)
      NodeContainer(this.myNodeController)
      NodeContainer(this.myNodeController2)
    }
    .width('100%')
    .backgroundColor(Color.Gray)
  }

  aboutToAppear() {
    console.error('BuilderNode 2 aboutToAppear');
  }

  aboutToDisappear() {
    console.error('BuilderNode 2 aboutToDisappear');
  }
}

@Component
struct TestComponent3 {
  build() {
    Column() {
      Text('This is a BuilderNode 3.')
        .fontSize(16)
        .fontWeight(FontWeight.Bold)

    }
    .width('100%')
    .backgroundColor(Color.Gray)
  }

  aboutToAppear() {
    console.error('BuilderNode 3 aboutToAppear');
  }

  aboutToDisappear() {
    console.error('BuilderNode 3 aboutToDisappear');
  }
}

@Component
struct TestComponent4 {
  build() {
    Column() {
      Text('This is a BuilderNode 4.')
        .fontSize(16)
        .fontWeight(FontWeight.Bold)

    }
    .width('100%')
    .backgroundColor(Color.Gray)
  }

  aboutToAppear() {
    console.error('BuilderNode 4 aboutToAppear');
  }

  aboutToDisappear() {
    console.error('BuilderNode 4 aboutToDisappear');
  }
}

@Builder
function buildComponent() {
  TestComponent()
}

@Builder
function buildComponent2() {
  TestComponent2()
}

@Builder
function buildComponent3() {
  TestComponent3()
}

@Builder
function buildComponent4() {
  TestComponent4()
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private builderNode: BuilderNode<[]> | null = null;
  private wrappedBuilder: WrappedBuilder<[]>;

  constructor(builder: WrappedBuilder<[]>) {
    super();
    this.wrappedBuilder = builder;
  }

  makeNode(uiContext: UIContext): FrameNode | null {
    this.builderNode = new BuilderNode(uiContext, { selfIdealSize: { width: 200, height: 100 } });
    this.builderNode.build(this.wrappedBuilder);

    return this.builderNode.getFrameNode();
  }

  dispose() {
    if (this.builderNode !== null) {
      this.builderNode.getFrameNode()?.disposeTree()
    }
  }

  removeBuilderNode() {
    const rootRenderNode = this.rootNode!.getRenderNode();
    if (rootRenderNode !== null && this.builderNode !== null && this.builderNode.getFrameNode() !== null) {
      rootRenderNode.removeChild(this.builderNode!.getFrameNode()!.getRenderNode());
    }
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController(wrapBuilder(buildComponent));

  build() {
    Column({ space: 4 }) {
      NodeContainer(this.myNodeController)
      Button('BuilderNode dispose')
        .onClick(() => {
          this.myNodeController.dispose();
        })
        .width('100%')
      Button('BuilderNode rebuild')
        .onClick(() => {
          this.myNodeController.rebuild();
        })
        .width('100%')
    }
  }
}
```

**Example**

See [Example of Node Customization](#example-of-node-customization).

## TypedFrameNode<sup>12+</sup>

Inherits from [FrameNode](#framenode), used to declare a specific type of FrameNode.

### initialize<sup>12+</sup>

initialize: C

Creates construction parameters of a component to set or update the initial value of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### attribute<sup>12+</sup>

attribute(): T

Obtains the attribute setting object of a component to set or update the common and private attributes of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## typeNode<sup>12+</sup>

Provides APIs for creating a specific type of FrameNode, which can be mounted through the basic API of the FrameNode and be displayed using a placeholder container.

**Example**

See [Example of Node Customization of a Specific Type](#example-of-node-customization-of-a-specific-type)。

### Text<sup>12+</sup>
type Text = TypedFrameNode&lt;TextInterface, TextAttribute&gt;

Represents a FrameNode of the Text type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;TextInterface, TextAttribute&gt; | FrameNode of the Text type.<br>**NOTE**<br> **TextInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Text>** component.<br> **TextAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Text>** component. |

### createNode('Text')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Text'): Text

Create a FrameNode of the Text type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Text' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Text](#text12) | FrameNode node of the Text type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Text');
```

### Column<sup>12+</sup>
type Column = TypedFrameNode&lt;ColumnInterface, ColumnAttribute&gt;

Represents a FrameNode of the Column type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ColumnInterface, ColumnAttribute&gt; | FrameNode of the Column type.<br>**NOTE**<br> **ColumnInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Column>** component.<br> **ColumnAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Column>** component. |

### createNode('Column')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Column'): Column

Creates a FrameNode of the Column type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Column' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Column](#column12) | FrameNode node of the Column type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Column');
```
### Row<sup>12+</sup>
type Row = TypedFrameNode&lt;RowInterface, RowAttribute&gt;

Represents a FrameNode of the Row type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;RowInterface, RowAttribute&gt; | FrameNode of the Row type.<br>**NOTE**<br> **RowInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Row>** component.<br> **RowAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Row>** component. |

### createNode('Row')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Row'): Row

Creates a FrameNode of the Row type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Row' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Row](#row12) | FrameNode node of the Row type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Row');
```
### Stack<sup>12+</sup>
type Stack = TypedFrameNode&lt;StackInterface, StackAttribute&gt;

Represents a FrameNode of the Stack type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;StackInterface, StackAttribute&gt; | FrameNode of the Stack type.<br>**NOTE**<br> **StackInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Stack>** component.<br> **StackAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Stack>** component. |

### createNode('Stack')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Stack'): Stack

Creates a FrameNode of the Stack type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Stack' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Stack](#stack12) | FrameNode node of the Stack type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Stack');
```
### GridRow<sup>12+</sup>
type GridRow = TypedFrameNode&lt;GridRowInterface, GridRowAttribute&gt;

Represents a FrameNode of the GridRow type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;GridRowInterface, GridRowAttribute&gt; | FrameNode of the GridRow type.<br>**NOTE**<br> **GridRowInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<GridRow>** component.<br> **GridRowAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<GridRow>** component. |

### createNode('GridRow')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'GridRow'): GridRow

Creates a FrameNode of the GridRow type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'GridRow' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [GridRow](#gridrow12) | FrameNode node of the GridRow type. |

**Example**

```ts
typeNode.createNode(uiContext, 'GridRow');
```
### GridCol<sup>12+</sup>
type GridCol = TypedFrameNode&lt;GridColInterface, GridColAttribute&gt;

Represents a FrameNode of the GridCol type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;GridColInterface, GridColAttribute&gt; | FrameNode of the GridCol type.<br>**NOTE**<br> **GridColInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<GridCol>** component.<br> **GridColAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<GridCol>** component. |

### createNode('GridCol')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'GridCol'): GridCol

Creates a FrameNode of the GridCol type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'GridCol' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [GridCol](#gridcol12) | FrameNode node of the GridCol type. |

**Example**

```ts
typeNode.createNode(uiContext, 'GridCol');
```
### Flex<sup>12+</sup>
type Flex = TypedFrameNode&lt;FlexInterface, FlexAttribute&gt;

Represents a FrameNode of the Flex type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;FlexInterface, FlexAttribute&gt; | FrameNode of the Flex type.<br>**NOTE**<br> **FlexInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Flex>** component.<br> **FlexInterface** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Flex>** component. |

### createNode('Flex')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Flex'): Flex

Creates a FrameNode of the Flex type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Flex' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Flex](#flex12) | FrameNode node of the Flex type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Flex');
```
### Swiper<sup>12+</sup>
type Swiper = TypedFrameNode&lt;SwiperInterface, SwiperAttribute&gt;

Represents a FrameNode of the Swiper type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SwiperInterface, SwiperAttribute&gt; | FrameNode of the Swiper type.<br>**NOTE**<br> **SwiperInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Swiper>** component.<br> **SwiperAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Swiper>** component. |

### createNode('Swiper')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Swiper'): Swiper

Creates a FrameNode of the Swiper type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Swiper' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Swiper](#swiper12) | FrameNode node of the Swiper type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Swiper');
```
### Progress<sup>12+</sup>
type Progress = TypedFrameNode&lt;ProgressInterface, ProgressAttribute&gt;

Represents a FrameNode of the Progress type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ProgressInterface, ProgressAttribute&gt; | FrameNode of the Progress type.<br>**NOTE**<br> **ProgressInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Progress>** component.<br> **ProgressAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Progress>** component. |

### createNode('Progress')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Progress'): Progress

Creates a FrameNode of the Progress type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Progress' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Progress](#progress12) | FrameNode node of the Progress type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Progress');
```
### Scroll<sup>12+</sup>
type Scroll = TypedFrameNode&lt;ScrollInterface, ScrollAttribute&gt;

Represents a FrameNode of the Scroll type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ScrollInterface, ScrollAttribute&gt; | FrameNode of the Scroll type.<br>**NOTE**<br> **ScrollInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Scroll>** component.<br> **ScrollAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Scroll>** component. |

### createNode('Scroll')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Scroll'): Scroll

Creates a FrameNode of the Scroll type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Scroll' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Scroll](#scroll12) | FrameNode node of the Scroll type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Scroll');
```
### RelativeContainer<sup>12+</sup>
type RelativeContainer = TypedFrameNode&lt;RelativeContainerInterface, RelativeContainerAttribute&gt;

Represents a FrameNode of the RelativeContainer type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;RelativeContainerInterface, RelativeContainerAttribute&gt; | FrameNode of the RelativeContainer type.<br>**NOTE**<br> **RelativeContainerInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<RelativeContainer>** component.<br> **RelativeContainerAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<RelativeContainer>** component. |

### createNode('RelativeContainer')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'RelativeContainer'): RelativeContainer

Creates a FrameNode of the RelativeContainer type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'RelativeContainer' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [RelativeContainer](#relativecontainer12) | FrameNode node of the RelativeContainer type. |

**Example**

```ts
typeNode.createNode(uiContext, 'RelativeContainer');
```
### Divider<sup>12+</sup>
type Divider = TypedFrameNode&lt;DividerInterface, DividerAttribute&gt;

Represents a FrameNode of the Divider type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;DividerInterface, DividerAttribute&gt; | FrameNode of the Divider type.<br>**NOTE**<br> **DividerInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Divider>** component.<br> **DividerAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Divider>** component. |

### createNode('Divider')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Divider'): Divider

Creates a FrameNode of the Divider type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Divider' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Divider](#divider12) | FrameNode node of the Divider type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Divider');
```
### LoadingProgress<sup>12+</sup>
type LoadingProgress = TypedFrameNode&lt;LoadingProgressInterface, LoadingProgressAttribute&gt;

Represents a FrameNode of the LoadingProgress type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;LoadingProgressInterface, LoadingProgressAttribute&gt; | FrameNode of the LoadingProgress type.<br>**NOTE**<br> **LoadingProgressInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<LoadingProgress>** component.<br> **LoadingProgressAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<LoadingProgress>** component. |

### createNode('LoadingProgress')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'LoadingProgress'): LoadingProgress

Creates a FrameNode of the LoadingProgress type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'LoadingProgress' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [LoadingProgress](#loadingprogress12) | FrameNode node of the LoadingProgress type. |

**Example**

```ts
typeNode.createNode(uiContext, 'LoadingProgress');
```
### Search<sup>12+</sup>
type Search = TypedFrameNode&lt;SearchInterface, SearchAttribute&gt;

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SearchInterface, SearchAttribute&gt; | FrameNode of the Search type.<br>**NOTE**<br> **SearchInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Search>** component.<br> **SearchAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Search>** component. |

### createNode('Search')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Search'): Search

Creates a FrameNode of the Search type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Search' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Search](#search12) | FrameNode node of the Search type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Search');
```
### Blank<sup>12+</sup>
type Blank = TypedFrameNode&lt;BlankInterface, BlankAttribute&gt;

Represents a FrameNode of the Blank type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;BlankInterface, BlankAttribute&gt; | FrameNode of the Blank type.<br>**NOTE**<br> **BlankInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Blank>** component.<br> **BlankAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Blank>** component. |

### createNode('Blank')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Blank'): Blank;

Creates a FrameNode of the Blank type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Blank' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Blank](#blank12) | FrameNode node of the Blank type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Blank');
```
### Image<sup>12+</sup>
type Image = TypedFrameNode&lt;ImageInterface, ImageAttribute&gt;

Represents a FrameNode of the Image type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ImageInterface, ImageAttribute&gt; | FrameNode of the Image type.<br>**NOTE**<br> **ImageInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<Image>** component.<br> **ImageAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<Image>** component. |

### createNode('Image')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Image'): Image

Creates a FrameNode of the Image type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'Image' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Image](#image12) | FrameNode node of the Image type. |

**Example**

```ts
typeNode.createNode(uiContext, 'Image');
```
### List<sup>12+</sup>
type List = TypedFrameNode&lt;ListInterface, ListAttribute&gt;

Represents a FrameNode of the List type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ListInterface, ListAttribute&gt; | FrameNode of the List type.<br>**NOTE**<br> **ListInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<List>** component.<br> **ListAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<List>** component. |

### createNode('List')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'List'): List

Creates a FrameNode of the List type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'List' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [List](#list12) | FrameNode node of the List type. |

**Example**

```ts
typeNode.createNode(uiContext, 'List');
```
### ListItem<sup>12+</sup>
type ListItem = TypedFrameNode&lt;ListItemInterface, ListItemAttribute&gt;

Represents a FrameNode of the ListItem type.

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ListItemInterface, ListItemAttribute&gt; | FrameNode of the ListItem type.<br>**NOTE**<br> **ListItemInterface** is used as the input parameter of the [initialize](#initialize12) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **\<ListItem>** component.<br> **ListItemAttribute** is used as the return value of the [attribute](#attribute12) API of **TypedFrameNode**. It returns the attribute setting object of the **\<ListItem>** component. |

### createNode('ListItem')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'ListItem'): ListItem

Creates a FrameNode of the ListItem type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node. |
| nodeType | 'ListItem' | Yes | Node type. |

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [ListItem](#listitem12) | FrameNode node of the ListItem type. |

**Example**

```ts
typeNode.createNode(uiContext, 'ListItem');
```

## Example of Node Customization of a Specific Type

The following example shows how to create a node of the Text type.

```ts
import { typeNode, NodeController, FrameNode } from '@ohos.arkui.node';

class MyNodeController extends NodeController {
  makeNode(uiContext: UIContext): FrameNode | null {
    let node = new FrameNode(uiContext);
    node.commonAttribute.width(100)
      .height(50)
      .borderColor(Color.Gray)
      .borderWidth(1)
      .margin({ left: 10 });
    let col = typeNode.createNode(uiContext, 'Column');
    col.initialize({ space: 5 })
      .width('100%').height('100%').margin({ top: 5 });
    node.appendChild(col);
    let text = typeNode.createNode(uiContext, 'Text');
    text.initialize("Hello").fontColor(Color.Blue).fontSize(14);
    col.appendChild(text);
    return node;
  }
}

@Entry
@Component
struct FrameNodeTypeTest {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController);
    }
  }
}
```

![FrameNodeTextTest](figures/FrameNodeTextTest.png)

## Node Operation Example
```ts
import { FrameNode, NodeController } from "@ohos.arkui.node";
import { UIContext } from '@ohos.arkui.UIContext';
import { BusinessError } from '@ohos.base';
const TEST_TAG : string = "FrameNode"
class MyNodeController extends NodeController {
  public frameNode: FrameNode | null = null;
  public childList:Array<FrameNode> = new Array<FrameNode>();
  private rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;
  private childrenCount: number = 0;
  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.childrenCount = this.childrenCount + 1;
    this.uiContext = uiContext;
    this.frameNode =  new FrameNode(uiContext);
    this.rootNode.appendChild(this.frameNode);
    for (let i = 0; i < 10; i++) {
      let childNode = new FrameNode(uiContext);
      this.childList.push(childNode);
      this.frameNode.appendChild(childNode);
    }
    return this.rootNode;
  }
  appendChild()
  {
    let childNode = new FrameNode(this.uiContext!);
    this.rootNode!.appendChild(childNode);
    this.childrenCount = this.childrenCount + 1;
  }
  insertChildAfter(index : number)
  {
    let insertNode = new FrameNode(this.uiContext!);
    let childNode = this.rootNode!.getChild(index);
    this.rootNode!.insertChildAfter(insertNode,childNode);
    this.childrenCount = this.childrenCount + 1;
  }
  removeChild(index : number)
  {
    let childNode = this.rootNode!.getChild(index);
    if(childNode == null)
    {
      console.log(`${TEST_TAG} getchild at index {${index}} : fail`);
      return;
    }
    this.rootNode!.removeChild(childNode);
    this.childrenCount = this.childrenCount - 1;
  }
  getChildNumber()
  {
    console.log(TEST_TAG + " getChildNumber " + this.rootNode!.getChildrenCount())
    console.log(TEST_TAG + " children count is " + this.childrenCount);

  }
  clearChildren()
  {
    this.rootNode!.clearChildren();
  }
  searchFrameNode()
  {
    if(this.rootNode!.getFirstChild() === null)
    {
      console.log(TEST_TAG + " the rootNode does not have child node.")
    }
    if(this.rootNode!.getFirstChild() === this.frameNode) {
      console.log(TEST_TAG + " getFirstChild  result: success. The first child of the rootNode is equals to frameNode.");
    } else {
      console.log(TEST_TAG + " getFirstChild  result: fail. The first child of the rootNode is not equals to frameNode.");
    }
    if(this.frameNode!.getChild(5) === this.frameNode!.getChild(4)!.getNextSibling()) {
      console.log(TEST_TAG + " getNextSibling  result: success.");
    } else {
      console.log(TEST_TAG + " getNextSibling  result: fail.");
    }
    if(this.frameNode!.getChild(3) === this.frameNode!.getChild(4)!.getPreviousSibling()) {
      console.log(TEST_TAG + " getPreviousSibling  result: success.");
    } else {
      console.log(TEST_TAG + " getPreviousSibling  result: fail.");
    }
    if(this.rootNode!.getFirstChild() !== null && this.rootNode!.getFirstChild()!.getParent() === this.rootNode) {
      console.log(TEST_TAG + " getParent  result: success.");
    } else {
      console.log(TEST_TAG + " getParent  result: fail.");
    }
    if(this.rootNode!.getParent() !== undefined || this.rootNode!.getParent() !== null)
    {
      console.log(TEST_TAG + " get ArkTsNode success.")
      console.log(TEST_TAG + " check rootNode whether is modifiable " + this.rootNode!.isModifiable())
      console.log(TEST_TAG + " check getParent whether is modifiable " + this.rootNode!.getParent()!.isModifiable())
    } else {
      console.log(TEST_TAG + " get ArkTsNode fail.");
    }
  }
  getPositionToWindow()
  {
    let positionToWindow = this.rootNode?.getPositionToWindow();
    console.log(TEST_TAG + JSON.stringify(positionToWindow));
  }
  getPositionToParent()
  {
    let positionToParent = this.rootNode?.getPositionToParent();
    console.log(TEST_TAG + JSON.stringify(positionToParent));
  }
  getPositionToScreen()
  {
    let positionToScreen = this.rootNode?.getPositionToScreen();
    console.log(TEST_TAG + JSON.stringify(positionToScreen));
  }
  getPositionToWindowWithTransform()
  {
    let positionToWindowWithTransform = this.rootNode?.getPositionToWindowWithTransform();
    console.log(TEST_TAG + JSON.stringify(positionToWindowWithTransform));
  }
  getPositionToParentWithTransform()
  {
    let positionToParentWithTransform = this.rootNode?.getPositionToParentWithTransform();
    console.log(TEST_TAG + JSON.stringify(positionToParentWithTransform));
  }
  getPositionToScreenWithTransform()
  {
    let positionToScreenWithTransform = this.rootNode?.getPositionToScreenWithTransform();
    console.log(TEST_TAG + JSON.stringify(positionToScreenWithTransform));
  }
  getMeasuredSize()
  {
    let measuredSize = this.frameNode?.getMeasuredSize();
    console.log(TEST_TAG + JSON.stringify(measuredSize));
  }
  getLayoutPosition()
  {
    let layoutPosition = this.frameNode?.getLayoutPosition();
    console.log(TEST_TAG + JSON.stringify(layoutPosition));
  }
  getUserConfigBorderWidth()
  {
    let userConfigBorderWidth = this.frameNode?.getUserConfigBorderWidth();
    console.log(TEST_TAG + JSON.stringify(userConfigBorderWidth));
  }
  getUserConfigPadding()
  {
    let userConfigPadding = this.frameNode?.getUserConfigPadding();
    console.log(TEST_TAG + JSON.stringify(userConfigPadding));
  }
  getUserConfigMargin()
  {
    let userConfigMargin = this.frameNode?.getUserConfigMargin();
    console.log(TEST_TAG + JSON.stringify(userConfigMargin));
  }
  getUserConfigSize()
  {
    let userConfigSize = this.frameNode?.getUserConfigSize();
    console.log(TEST_TAG + JSON.stringify(userConfigSize));
  }
  getId()
  {
    let id = this.frameNode?.getId();
    console.log(TEST_TAG + id);
  }
  getUniqueId()
  {
    let uniqueId = this.frameNode?.getUniqueId();
    console.log(TEST_TAG + uniqueId);
  }
  getNodeType()
  {
    let nodeType = this.frameNode?.getNodeType();
    console.log(TEST_TAG + nodeType);
  }
  getOpacity()
  {
    let opacity = this.frameNode?.getOpacity();
    console.log(TEST_TAG + JSON.stringify(opacity));
  }
  isVisible()
  {
    let visible = this.frameNode?.isVisible();
    console.log(TEST_TAG + JSON.stringify(visible));
  }
  isClipToFrame()
  {
    let clipToFrame = this.frameNode?.isClipToFrame();
    console.log(TEST_TAG + JSON.stringify(clipToFrame));
  }
  isAttached()
  {
    let attached = this.frameNode?.isAttached();
    console.log(TEST_TAG + JSON.stringify(attached));
  }
  getInspectorInfo()
  {
    let inspectorInfo = this.frameNode?.getInspectorInfo();
    console.log(TEST_TAG + JSON.stringify(inspectorInfo));
  }

  throwError()
  {
    try{
      this.rootNode!.getParent()!.clearChildren();
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " +(err as BusinessError).message);
    }
    try{
      this.rootNode!.getParent()!.appendChild(new FrameNode(this.uiContext));
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " +(err as BusinessError).message);
    }
    try{
      this.rootNode!.getParent()!.removeChild(this.rootNode!.getParent()!.getChild(0));
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " +(err as BusinessError).message);
    }
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();
  @State index : number = 0;
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Column(){
        Row()
        {
          Button("ADD")
            .onClick(()=>{this.index++;})
          Button("DEC")
            .onClick(()=>{this.index--;})
        }
        Text("Current index is " + this.index)
          .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          .width('100%').fontSize(16)
      }
      Button("appendChild")
        .width(300)
        .onClick(()=>{
          this.myNodeController.appendChild();
        })
      Button("insertChildAfter")
        .width(300)
        .onClick(()=>{
          this.myNodeController.insertChildAfter(this.index);
        })
      Button("removeChild")
        .width(300)
        .onClick(()=>{
          this.myNodeController.removeChild(this.index);
        })
      Button("clearChildren")
        .width(300)
        .onClick(()=>{
          this.myNodeController.clearChildren();
        })
      Button("getChildNumber")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getChildNumber();
        })
      Button("searchFrameNode")
        .width(300)
        .onClick(()=>{
          this.myNodeController.searchFrameNode();
        })
      Button("getPositionToWindow")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getPositionToWindow();
        })
      Button("getPositionToParent")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getPositionToParent();
        })
      Button("getPositionToScreen")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getPositionToScreen();
        })
      Button("getPositionToParentWithTransform")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getPositionToParentWithTransform();
        })
      Button("getPositionToWindowWithTransform")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getPositionToWindowWithTransform();
        })
      Button("getPositionToScreenWithTransform")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getPositionToScreenWithTransform();
        })
      Button("getMeasuredSize")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getMeasuredSize();
        })
      Button("getLayoutPosition")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getLayoutPosition();
        })
      Button("getUserConfigBorderWidth")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getUserConfigBorderWidth();
        })
      Button("getUserConfigPadding")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getUserConfigPadding();
        })
      Button("getUserConfigMargin")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getUserConfigMargin();
        })
      Button("getUserConfigSize")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getUserConfigSize();
        })
      Button("getId")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getId();
        })
      Button("getUniqueId")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getUniqueId();
        })
      Button("getNodeType")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getNodeType();
        })
      Button("getOpacity")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getOpacity();
        })
      Button("isVisible")
        .width(300)
        .onClick(()=>{
          this.myNodeController.isVisible();
        })
      Button("isClipToFrame")
        .width(300)
        .onClick(()=>{
          this.myNodeController.isClipToFrame();
        })
      Button("isAttached")
        .width(300)
        .onClick(()=>{
          this.myNodeController.isAttached();
        })
      Button("getInspectorInfo")
        .width(300)
        .onClick(()=>{
          this.myNodeController.getInspectorInfo();
        })
      Button("getCustomProperty")
        .width(300)
        .onClick(()=>{
          const uiContext: UIContext = this.getUIContext();
          if (uiContext) {
            const node: FrameNode | null = uiContext.getFrameNodeById("Test_Button") || null;
            if (node) {
              for (let i = 1; i < 4; i++) {
                const key = 'customProperty' + i;
                const property = node.getCustomProperty(key);
                console.log(TEST_TAG + key, JSON.stringify(property));
              }
            }
          }
        })
        .id('Test_Button')
        .customProperty('customProperty1', {
          'number': 10,
          'string': 'this is a string',
          'bool': true,
          'object': {
            'name': 'name',
            'value': 100
          }
        })
        .customProperty('customProperty2', {})
        .customProperty('customProperty2', undefined)
      Button("throwError")
        .width(300)
        .onClick(()=>{
          this.myNodeController.throwError();
        })
      Column(){
        Text("This is a NodeContainer.")
          .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          .width('100%').fontSize(16)
        NodeContainer(this.myNodeController)
          .borderWidth(1)
          .width(300)
          .height(100)
      }
    }
    .padding({ left: 35, right: 35, top: 35, bottom: 35 })
    .width("100%")
    .height("100%")
  }
}
```
## Basic Event Example
```ts
import { NodeController, FrameNode } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  public rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.rootNode.commonAttribute.width(100)
      .height(100)
      .backgroundColor(Color.Pink);
    this.addCommonEvent(this.rootNode);
    return this.rootNode;
  }

  addCommonEvent(frameNode: FrameNode) {
    frameNode.commonEvent.setOnHover(((isHover: boolean, event: HoverEvent): void => {
      console.log(`isHover FrameNode: ${isHover}`);
      console.log(`isHover FrameNode: ${JSON.stringify(event)}`);
      event.stopPropagation();
    }))
    frameNode.commonEvent.setOnClick((event: ClickEvent) => {
      console.log(`Click FrameNode: ${JSON.stringify(event)}`)
    })
    frameNode.commonEvent.setOnTouch((event: TouchEvent) => {
      console.log(`touch FrameNode: ${JSON.stringify(event)}`)
    })
    frameNode.commonEvent.setOnAppear(() => {
      console.log(`on Appear FrameNode`)
    })
    frameNode.commonEvent.setOnDisappear(() => {
      console.log(`onDisAppear FrameNode`)
    })
    frameNode.commonEvent.setOnFocus(() => {
      console.log(`onFocus FrameNode`)
    })
    frameNode.commonEvent.setOnBlur(() => {
      console.log(`onBlur FrameNode`)
    })
    frameNode.commonEvent.setOnKeyEvent((event: KeyEvent) => {
      console.log(`Key FrameNode: ${JSON.stringify(event)}`)
    })
    frameNode.commonEvent.setOnMouse((event: MouseEvent) => {
      console.log(`Mouse FrameNode: ${JSON.stringify(event)}`)
    })
    frameNode.commonEvent.setOnSizeChange((oldValue: SizeOptions, newValue: SizeOptions) => {
      console.info(`onSizeChange FrameNode: oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
    })
  }
}

@Entry
@Component
struct Index {
  @State index: number = 0;
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      Button("add CommonEvent to Text")
        .onClick(() => {
          this.myNodeController!.addCommonEvent(this.myNodeController!.rootNode!.getParent()!.getPreviousSibling() !)
        })
      Text("this is a Text")
        .fontSize(16)
        .borderWidth(1)
        .onHover(((isHover: boolean, event: HoverEvent): void => {
          console.log(`isHover Text: ${isHover}`);
          console.log(`isHover Text: ${JSON.stringify(event)}`);
          event.stopPropagation();
        }))
        .onClick((event: ClickEvent) => {
          console.log(`Click Text    : ${JSON.stringify(event)}`)
        })
        .onTouch((event: TouchEvent) => {
          console.log(`touch Text    : ${JSON.stringify(event)}`)
        })
        .onAppear(() => {
          console.log(`on Appear Text`)
        })
        .onDisAppear(() => {
          console.log(`onDisAppear Text`)
        })
        .onFocus(() => {
          console.log(`onFocus Text`)
        })
        .onBlur(() => {
          console.log(`onBlur Text`)
        })
        .onKeyEvent((event: KeyEvent) => {
          console.log(`Key Text    : ${JSON.stringify(event)}`)
        })
        .onMouse((event: MouseEvent) => {
          console.log(`Mouse Text : ${JSON.stringify(event)}`)
        })
        .onSizeChange((oldValue: SizeOptions, newValue: SizeOptions) => {
          console.info(`onSizeChange Text: oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
        })
      NodeContainer(this.myNodeController)
        .borderWidth(1)
        .width(300)
        .height(100)
    }.width("100%")
  }
}
```


## Example of Using Basic Events in the LazyForEach Scenario
```ts
// index.ets
import {Track, TrackManager, TrackNode} from "./track"

@Builder
function page1() {
  Column() {
    Text("Page1")
    PageList().height("90%")
    Button("DumpMessage")
      .onClick(() => {
        TrackManager.get().dump()
      })

  }.width("100%").height("100%")
}

class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  // This method is called by the framework to add a listener to the LazyForEach data source.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // This method is called by the framework to remove the listener from the LazyForEach data source.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  // Notify LazyForEach that all child components need to be reloaded.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // Notify LazyForEach that a child component needs to be added for the data item with the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // Notify LazyForEach that the data item with the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // Notify LazyForEach that the child component that matches the specified index needs to be deleted.
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  // Notify LazyForEach that data needs to be swapped between the from and to positions.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Component
struct PageList {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 100; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          // Encapsulate and instrument the component with tracking through TrackNode.
          TrackNode({track: new Track().tag("xxx"+ item).id(index + 30000)}) {
            Row() {
              Text(item).fontSize(30)
                .onClick(() => {
                })
            }.margin({ left: 10, right: 10 })
          }
        }
      }, (item: string) => item)
    }.cachedCount(5)
  }
}


@Entry
@Component
struct TrackTest {
  pageInfos: NavPathStack = new NavPathStack()
  build() {
    Row() {
      TrackNode({ track: new Track().tag("root").id(10000)}) {
        page1()
      }
    }
  }

  aboutToAppear(): void {
    TrackManager.get().startListenClick(this.getUIContext())
  }
}
```

```ts
// ./track.ets
import { FrameNode } from '@kit.ArkUI';
import { Rect } from '@ohos.arkui.node';

@Component
export struct TrackNode {
  @BuilderParam closer: VoidCallback = this.defaultBuilder
  track: Track | null = null
  trackShadow: TrackShadow = new TrackShadow()

  @Builder defaultBuilder() {
  }

  build() {
    this.closer()
  }

  aboutToAppear(): void {
    // use onDidBuild later
  }

  aboutToDisappear(): void {
    TrackManager.get().removeTrack(this.trackShadow.id)
    console.log("Track disappear:" + this.trackShadow.id)
  }

  onDidBuild(): void {
    // Construct a virtual tree with the tracing point. The obtained node is the root node of the current page (Row in the case).
    let uid = this.getUniqueId()
    let node: FrameNode | null = this.getUIContext().getFrameNodeByUniqueId(uid);
    console.log("Track onDidBuild node:" + node?.getNodeType())
    if (node === null) {
      return
    }
    this.trackShadow.node = node
    this.trackShadow.id = node?.getUniqueId()
    this.trackShadow.track = this.track;
    TrackManager.get().addTrack(this.trackShadow.id, this.trackShadow)
    // Use setOnVisibleAreaApproximateChange to listen for and record changes in the visible area of the tracked component.
    node?.commonEvent.setOnVisibleAreaApproximateChange(
      { ratios: [0, 0.1, 0.2, 0.5, 0.8, 1], expectedUpdateInterval: 500 },
      (ratioInc: boolean, ratio: number) => {
        console.log(`Node ${node?.getUniqueId()}:${node?.getNodeType()} is visibleRatio is ${ratio}`);
        this.trackShadow.visibleRatio = ratio
      })

    let parent: FrameNode | null = node?.getParent()

    let attachTrackToParent: (parent: FrameNode | null) => boolean =
      (parent: FrameNode | null) => {
        while (parent !== null) {
          let parentTrack = TrackManager.get().getTrackById(parent.getUniqueId())
          if (parentTrack !== undefined) {
            parentTrack.childIds.add(this.trackShadow.id)
            this.trackShadow.parentId = parentTrack.id
            return true;
          }
          parent = parent.getParent()
        }
        return false;
      }
    let attached = attachTrackToParent(parent);

    if (!attached) {
      node?.commonEvent.setOnAppear(() => {
        let attached = attachTrackToParent(parent);
        if (attached) {
          console.log("Track lazy attached:" + this.trackShadow.id)
        }
      })
    }
  }
}

export class Track {
  public areaPercent: number = 0
  private trackTag: string = ""
  private trackId: number = 0

  constructor() {
  }

  tag(newTag: string): Track {
    this.trackTag = newTag;
    return this;
  }

  id(newId: number): Track {
    this.trackId = newId;
    return this;
  }
}

export class TrackShadow {
  public node: FrameNode | null = null
  public id: number = -1
  public track: Track | null = null
  public childIds: Set<number> = new Set()
  public parentId: number = -1
  public visibleRect: Rect = { left: 0, top: 0, right: 0, bottom: 0 }
  public area: number = 0
  public visibleRatio: number = 0

  // Output the tracing point tree information through global dump.
  dump(depth: number = 0): void {
    console.log("Track Dp:" + depth + " id:" + this.id + " areaPer:" + this.track?.areaPercent + " visibleRatio:" + this.visibleRatio)
    this.childIds.forEach((value: number) => {
      TrackManager.get().getTrackById(value)?.dump(depth + 1)
    })
  }
}

export class TrackManager {
  static instance: TrackManager
  private trackMap: Map<number, TrackShadow> = new Map()
  private rootTrack: TrackShadow | null = null

  static get(): TrackManager {
    if (TrackManager.instance !== undefined) {
      return TrackManager.instance
    }
    TrackManager.instance = new TrackManager()
    return TrackManager.instance
  }

  addTrack(id: number, track: TrackShadow) {
    if (this.trackMap.size == 0) {
      this.rootTrack = track
    }
    console.log("Track add id:" + id)
    this.trackMap.set(id, track)
  }

  removeTrack(id: number) {
    let current = this.getTrackById(id)
    if (current !== undefined) {
      this.trackMap.delete(id)
      let parent = this.getTrackById(current?.parentId)
      parent?.childIds.delete(id)
    }
  }

  getTrackById(id: number): TrackShadow | undefined {
    return this.trackMap.get(id)
  }

  startListenClick(context: UIContext) {
    // Obtain the FrameNode through listening for tracing point information.
    context.getUIObserver().on("willClick", (event: ClickEvent, node?: FrameNode) => {
      console.log("Track clicked:" + node)
      if (node == undefined) {
        return
      }
      let track = this.getTrackById(node.getUniqueId())
      track?.dump(0);
    })
  }

  updateVisibleInfo(track: TrackShadow): void {
    // do something
  }

  dump(): void {
    this.rootTrack?.dump(0)
  }
}
```
## Example of Node Customization

```ts
import { UIContext } from '@ohos.arkui.UIContext';
import { DrawContext, FrameNode, NodeController, LayoutConstraint, Size, Position } from '@ohos.arkui.node';
import drawing from '@ohos.graphics.drawing';

function GetChildLayoutConstraint(constraint: LayoutConstraint, child: FrameNode): LayoutConstraint {
  const size = child.getUserConfigSize();
  const width = Math.max(
    Math.min(constraint.maxSize.width, size.width.value), 
    constraint.minSize.width
    );
  const height = Math.max(
    Math.min(constraint.maxSize.height, size.height.value), 
    constraint.minSize.height
    );
  const finalSize: Size = { width, height };
  const res: LayoutConstraint = {
    maxSize: finalSize,
    minSize: finalSize,
    percentReference: finalSize
  };

  return res;
}

class MyFrameNode extends FrameNode {
  public width: number = 10;
  private space: number = 1;

  onMeasure(constraint: LayoutConstraint): void {
    let sizeRes: Size = { width: 100, height: 100 };
    for (let i = 0;i < this.getChildrenCount();i++) {
      let child = this.getChild(i);
      if (child) {
        let childConstraint = GetChildLayoutConstraint(constraint, child);
        child.measure(childConstraint);
        let size = child.getMeasuredSize();
        sizeRes.height += size.height + this.space;
        sizeRes.width = Math.max(sizeRes.width, size.width);
      }
    }
    this.setMeasuredSize(sizeRes);
  }

  onLayout(position: Position): void {
    let y = 0;
    for (let i = 0;i < this.getChildrenCount();i++) {
      let child = this.getChild(i);
      if (child) {
        child.layout({
          x: 20,
          y: y
        });
        y += child.getMeasuredSize().height + this.space;
      }
    }
    this.setLayoutPosition(position);
  }

  onDraw(context: DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({ alpha: 255, red: 255, green: 0, blue: 0 });
    canvas.attachPen(pen);
    canvas.drawRect({ left: 0, right: this.width, top: 0, bottom: this.width });
    canvas.detachPen();
  }

  addWidth() {
    this.width += 10;
  }
}

class MyNodeController extends NodeController {
  public rootNode: MyFrameNode | null = null;

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new MyFrameNode(context);
    this.rootNode?.commonAttribute?.size({ width: 100, height: 100 }).backgroundColor(Color.Green);
    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private nodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      Column() {
        NodeContainer(this.nodeController)
          .width('100%')
          .height(100)
          .backgroundColor('#FFF0F0F0')
        Button('Invalidate')
          .onClick(() => {
            this.nodeController?.rootNode?.addWidth();
            this.nodeController?.rootNode?.invalidate();
          })
        Button('UpdateLayout')
          .onClick(() => {
            this.nodeController?.rootNode?.setNeedsLayout();
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```
