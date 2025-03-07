# FrameNode

**FrameNode** represents an entity node in the component tree. It can be used by a [NodeController](./js-apis-arkui-nodeController.md#nodecontroller) to mount a [BuilderNode](./js-apis-arkui-builderNode.md#buildernode) (that holds the FrameNode) to a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) or mount a [RenderNode](./js-apis-arkui-renderNode.md#rendernode) to another FrameNode.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> **FrameNode** is not available in DevEco Studio Previewer.
>
> FrameNodes cannot be dragged.

## Modules to Import

```ts
import { FrameNode, LayoutConstraint, ExpandMode, typeNode, NodeAdapter } from "@kit.ArkUI";
```

## CrossLanguageOptions<sup>15+</sup>

Used to set or obtain the cross-language options of the FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  | Read Only| Optional| Description                  |
| ------ | ------ | ---- | ---- | ---------------------- |
| attributeSetting  | boolean | No  | Yes  | Whether the FrameNode supports cross-language attribute settings. The default value is **false**.|

## ExpandMode<sup>15+</sup>

Enumerates the expansion mode of child nodes.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| NOT_EXPAND | 0 | The child nodes of the current FrameNode are not expanded. If the FrameNode contains [LazyForEach](./arkui-ts/ts-rendering-control-lazyforeach.md) child nodes, the child nodes are not expanded when the nodes in the main tree are being obtained. The child node sequence numbers are calculated based on the nodes in the main tree.|
| EXPAND | 1 | The child nodes of the current FrameNode are expanded. If the FrameNode contains [LazyForEach](./arkui-ts/ts-rendering-control-lazyforeach.md) child nodes, all child nodes are expanded when being obtained. The child node sequence numbers are calculated based on all child nodes.|
| LAZY_EXPAND | 2 | The child nodes of the current FrameNode are expanded on demand. If the FrameNode contains [LazyForEach](./arkui-ts/ts-rendering-control-lazyforeach.md) child nodes, the child nodes are not expanded when the nodes in the main tree are being obtained, but are expanded when nodes not in the main tree are being obtained. The child node sequence numbers are calculated based on all child nodes.|

## FrameNode

### constructor

constructor(uiContext: UIContext)

Constructor used to create a FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|

### getRenderNode

getRenderNode(): RenderNode | null

Obtains the RenderNode instance held in this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                                                            |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [RenderNode](./js-apis-arkui-renderNode.md#rendernode) \| null | **RenderNode** instance. If the current FrameNode does not hold any RenderNode, **null** is returned. If the current FrameNode is a node created by a declarative component, **null** is returned.|

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
| boolean | Whether the current FrameNode is modifiable. When **false** is returned, the FrameNode does not support the **appendChild**, **insertChildAfter**, **removeChild**, and **clearChildren** operations.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### appendChild<sup>12+</sup> 

appendChild(node: FrameNode): void

Appends a child node to the end of this FrameNode. If this FrameNode is not modifiable, an exception is thrown. When **appendChild** is called, [typeNode](#typenode12) validates the type or number of child nodes. If the validation fails, an exception is thrown. For specific limitations, see [typeNode](#typenode12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                   | Mandatory| Description                 |
| ------ | ----------------------- | ---- | --------------------- |
| node   | [FrameNode](#framenode) | Yes  | Child node to append.<br>**NOTE**<br> The child node cannot be one created declaratively, which is not modifiable. Only declarative nodes obtained from a BuilderNode can be used as child nodes. If the child node does not meet the specifications, an exception is thrown.<br> The FrameNode cannot have a parent node. Otherwise, an exception is thrown.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Example of Node Operations](#example-of-node-operations).

### insertChildAfter<sup>12+</sup> 

insertChildAfter(child: FrameNode, sibling: FrameNode | null): void

Inserts a child node after the specified child node of this FrameNode. If this FrameNode is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                     | Mandatory| Description                                                                        |
| ------- | ----------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| child   | [FrameNode](#framenode)                   | Yes  | Child node to add.<br>**NOTE**<br> The child node cannot be a declarative node, that is, a FrameNode that cannot be modified. Only declarative nodes obtained from a BuilderNode can be used as child nodes. If the child node does not meet the specifications, an exception is thrown.<br> The child node cannot have a parent node. Otherwise, an exception is thrown.                                                          |
| sibling | [FrameNode](#framenode) \| null | Yes  | Node after which the new child node will be inserted. If this parameter is left empty, the new node is inserted before the first subnode.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Example of Node Operations](#example-of-node-operations).

### removeChild<sup>12+</sup> 

removeChild(node: FrameNode): void

Deletes the specified child node from this FrameNode. If this FrameNode is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                   | Mandatory| Description              |
| ------ | ----------------------- | ---- | ------------------ |
| node   | [FrameNode](#framenode) | Yes  | Child node to delete.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Example of Node Operations](#example-of-node-operations).

### clearChildren<sup>12+</sup> 

clearChildren(): void

Clears all child nodes of this FrameNode. If this FrameNode is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getChild<sup>12+</sup> 

getChild(index: number, expandMode?: ExpandMode): FrameNode | null

Obtains the child node in the specified position of this RenderNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| index  | number | Yes  | Index of the child node to obtain.|
| expandMode<sup>15+</sup> | [ExpandMode](#expandmode15) | No| Expansion mode of the child node.<br>Default value: **ExpandMode.Expand**|

**Return value**

| Type                           | Description                                                         |
| ------------------------------- | ------------------------------------------------------------- |
| [FrameNode](#framenode) \| null | Child node obtained. If the FrameNode does not contain the specified child node, null is returned.|

**Example**

See [Example of Node Operations](#example-of-node-operations) and [Example of Node Operations in the LazyForEach Scenario](#example-of-node-operations-in-the-lazyforeach-scenario).

### getFirstChildIndexWithoutExpand<sup>15+</sup> 

getFirstChildIndexWithoutExpand(): number

Obtains the sequence number of the first child node of this node that is in the main node tree. The child node sequence numbers are calculated based on all child nodes.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                                     |
| ------ | ---------------------------------------- |
| number | Sequence number of the first child node of this node that is in the main node tree.|

**Example**

See [Example of Node Operations in the LazyForEach Scenario](#example-of-node-operations-in-the-lazyforeach-scenario).

### getLastChildIndexWithoutExpand<sup>15+</sup> 

getLastChildIndexWithoutExpand(): number

Obtains the sequence number of the last child node of this node that is in the main node tree. The child node sequence numbers are calculated based on all child nodes.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                                       |
| ------ | ------------------------------------------ |
| number | Sequence number of the last child node of this node that is in the main node tree.|

**Example**

See [Example of Node Operations in the LazyForEach Scenario](#example-of-node-operations-in-the-lazyforeach-scenario).

### getFirstChild<sup>12+</sup> 

getFirstChild(): FrameNode | null

Obtains the first child node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                           | Description                                                     |
| ------------------------------- | --------------------------------------------------------- |
| [FrameNode](#framenode) \| null | First child node. If the FrameNode does not contain any child node, null is returned.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getNextSibling<sup>12+</sup> 

getNextSibling(): FrameNode | null

Obtains the next sibling node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                           | Description                                                                                |
| ------------------------------- | ------------------------------------------------------------------------------------ |
| [FrameNode](#framenode) \| null | Next sibling node of the current FrameNode. If the FrameNode does not have the next sibling node, null is returned.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getPreviousSibling<sup>12+</sup> 

getPreviousSibling(): FrameNode | null

Obtains the previous sibling node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                                                                                |
| -------------------------------- | ------------------------------------------------------------------------------------ |
| [FrameNode](#framenode) \| null | Previous sibling node of the current FrameNode. If the FrameNode does not have the previous sibling node, null is returned.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getParent<sup>12+</sup> 

getParent(): FrameNode | null;

Obtains the parent node of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                            | Description                                                                |
| -------------------------------- | -------------------------------------------------------------------- |
| [FrameNode](#framenode) \| null | Parent node of the current FrameNode. If the FrameNode does not contain a parent node, null is returned.|

**Example**

See [Example of Node Operations](#example-of-node-operations).


### getChildrenCount<sup>12+</sup> 

  getChildrenCount(): number;

Obtains the number of child nodes of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                           |
| -------- | ------------------------------- |
| number | Number of child nodes of the current FrameNode.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### moveTo<sup>16+</sup>

moveTo(targetParent: FrameNode, index?: number): void

Moves this FrameNode to a specified position within the target FrameNode. If this FrameNode is not modifiable, an exception is thrown. When **targetParent** is a [typeNode](#typenode12), the API validates the type or number of child nodes. If the validation fails, an exception is thrown. For specific limitations, see [typeNode](#typenode12).

> **NOTE**
>
> Currently, only the following types of [TypedFrameNode](#typedframenode12) are supported for the movement operations: [Stack](#stack12), [XComponent](#xcomponent12).

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                   | Mandatory| Description                 |
| ------------ | ----------------------- | ---- | --------------------- |
| targetParent | [FrameNode](#framenode) | Yes  | Target parent node.<br>**NOTE**<br>The target parent node must not be a declaratively created node, that is, a FrameNode that is not modifiable. If it does not meet the specifications, an exception is thrown.|
| index        | number                  | No  | Sequence number of the child node. The current FrameNode will be inserted before the child node at the specified sequence number in the target FrameNode. If the target FrameNode has *n* nodes, the value range for **index** is 0 to *n*-1.<br>If the parameter is invalid or not specified, the current FrameNode will be added to the end of the target FrameNode.<br>Default value: **-1**|

**Error codes**

| ID| Error Message                         |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getPositionToWindow<sup>12+</sup> 

  getPositionToWindow(): Position

Obtains the position offset of this FrameNode relative to the window, in vp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                           |
| -------- | ------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the window, in vp.|

**Example**

See [Example of Node Operations](#example-of-node-operations).


### getPositionToParent<sup>12+</sup>

getPositionToParent(): Position

Obtains the position offset of this FrameNode relative to the parent component, in vp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the parent component, in vp.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getPositionToScreen<sup>12+</sup> 

  getPositionToScreen(): Position

Obtains the position offset of this FrameNode relative to the screen, in vp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                           |
| -------- | ------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the screen, in vp.|

**Example**

See [Example of Node Operations](#example-of-node-operations).


### getPositionToParentWithTransform<sup>12+</sup>

getPositionToParentWithTransform(): Position

Obtains the position offset of this FrameNode relative to the parent component, taking into account drawing attributes such as **transform** and **translate**. The coordinates returned are the coordinates of the upper left corner during layout after transformation. The unit is vp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the parent component, in vp. If other drawing attributes (such as **transform** and **translate**) are set, the return value may slightly deviate due to the precision of floating point numbers.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getPositionToWindowWithTransform<sup>12+</sup>

getPositionToWindowWithTransform(): Position

Obtains the position offset of this FrameNode relative to the window, taking into account drawing attributes such as **transform** and **translate**. The coordinates returned are the coordinates of the upper left corner during layout after transformation. The unit is vp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the window, in vp. If other drawing attributes (such as **transform** and **translate**) are set, the return value may slightly deviate due to the precision of floating point numbers.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getPositionToScreenWithTransform<sup>12+</sup>

getPositionToScreenWithTransform(): Position

Obtains the position offset of this FrameNode relative to the screen, taking into account drawing attributes such as **transform** and **translate**. The coordinates returned are the coordinates of the upper left corner during layout after transformation. The unit is vp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the node relative to the screen, in vp. If other drawing attributes (such as **transform** and **translate**) are set, the return value may slightly deviate due to the precision of floating point numbers.|

**Example**

See [Example of Node Operations](#example-of-node-operations).


### getMeasuredSize<sup>12+</sup>

getMeasuredSize(): Size

Obtains the measured size of this FrameNode, in px.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Size](./js-apis-arkui-graphics.md#size) | Measured size of the node, in px.|

**Example**

See [Example of Node Operations](#example-of-node-operations).


### getLayoutPosition<sup>12+</sup>

getLayoutPosition(): Position

Obtains the position offset of this FrameNode relative to the parent component after layout, in px. The offset is the result of the parent component's layout on this node; therefore, the **offset** attribute that takes effect after layout and the **position** attribute that does not participate in layout do not affect this offset value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | Position offset of the current FrameNode relative to the parent component after layout, in px.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getUserConfigBorderWidth<sup>12+</sup>

getUserConfigBorderWidth(): Edges\<LengthMetrics\>

Obtains the border width set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Border width set by the user.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getUserConfigPadding<sup>12+</sup>

getUserConfigPadding(): Edges\<LengthMetrics\>

Obtains the padding set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Padding set by the user.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getUserConfigMargin<sup>12+</sup>

getUserConfigMargin(): Edges\<LengthMetrics\>

Obtains the margin set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Margin set by the user.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getUserConfigSize<sup>12+</sup>

getUserConfigSize(): SizeT\<LengthMetrics\>

Obtains the width and height set by the user.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                        | Description            |
| ------------------------------------------------------------ | ---------------- |
| [SizeT](./js-apis-arkui-graphics.md#sizett12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | Width and height set by the user.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getId<sup>12+</sup>

getId(): string

Obtains the node ID set by the user (the [ID](./arkui-ts/ts-universal-attributes-component-id.md) set in the universal attributes).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| string | Node ID set by the user (the [ID](./arkui-ts/ts-universal-attributes-component-id.md) set in the universal attributes).|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getUniqueId<sup>12+</sup>

getUniqueId(): number

Obtains the system-assigned unique ID of the node.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| number | System-assigned unique ID of the node.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getNodeType<sup>12+</sup>

getNodeType(): string

Obtains the type of the node. Built-in component types are named after the components themselves, for example, the type of a **Button** component is Button. For custom components, if they have rendering content, their type is __Common__.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| string | Type of the node.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getOpacity<sup>12+</sup>

getOpacity(): number

Obtains the opacity of the node. The minimum value is 0, and the maximum value is 1.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| number | Opacity of the node.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### isVisible<sup>12+</sup>

isVisible(): boolean

Obtains whether the node is visible.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | Whether the node is visible.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### isClipToFrame<sup>12+</sup>

isClipToFrame(): boolean

Checks whether the node is clipped to the component area. This API returns **true** after the [dispose](#dispose12) API is called to release the reference to the FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | Whether the node is clipped to the component area.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### isAttached<sup>12+</sup>

isAttached(): boolean

Obtains whether the node is mounted to the main node tree.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | Whether the node is mounted to the main node tree.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getInspectorInfo<sup>12+</sup>

getInspectorInfo(): Object

Obtains the structure information of the node, which is consistent with what is found in DevEco Studio's built-in <!--RP1-->ArkUI Inspector <!--RP1End-->tool.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| Object | Structure information of the node.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getCustomProperty<sup>12+</sup>

getCustomProperty(name: string): Object | undefined

Obtains the component's custom property by its name.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name  | string | Yes  | Name of the custom property.|

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| Object \| undefined | Value of the custom property.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

### dispose<sup>12+</sup>

dispose(): void

Immediately releases the reference to the underlying FrameNode entity.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

> **NOTE**
>
> After the **dispose** API is called, the FrameNode object no longer corresponds to any entity FrameNode. In this case, attempts to call certain query APIs, such as [getMeasuredSize](#getmeasuredsize12) and [getLayoutPosition](#getlayoutposition12), will result in a JS crash in the application.
>
> To check whether the current FrameNode object corresponds to an entity FrameNode, you can use [getUniqueId](#getuniqueid12) API. A **UniqueId** value greater than 0 indicates that the object is associated with an entity FrameNode.

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

Obtains the **CommonAttribute** object held in this FrameNode for setting common attributes.

Note that only the attributes of a custom node can be modified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                                                            |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| CommonAttribute | **CommonAttribute** object held in the current FrameNode for setting common attributes.|

> **NOTE**
>
> The visual representation of the FrameNode is similar to that of a [Stack](./arkui-ts/ts-container-stack.md) container that is aligned to the top start edge.
>
> For details about the supported attributes, see [CommonModifier](./arkui-ts/ts-universal-attributes-attribute-modifier.md#custom-modifier).

**Example**

See [Basic Event Example](#basic-event-example).

### commonEvent<sup>12+</sup>

get commonEvent(): UICommonEvent

Obtains the **UICommonEvent** object held in this FrameNode to set basic events. The set basic events will compete with declaratively defined events for event handling without overriding them. If two event callbacks are set at the same time, the callback for the declaratively defined event is prioritized.

In scenarios involving **LazyForEach**, where nodes may be destroyed and reconstructed, you need to reset or re-attach event listeners to the newly created nodes to ensure they respond to events correctly.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                                                            |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [UICommonEvent](./arkui-ts/ts-uicommonevent.md#common-event-callback)| **UICommonEvent** object, which is used to set basic events.|

**Example**

See [Basic Event Example](#basic-event-example) and [Example of Using Basic Events in the LazyForEach Scenario](#example-of-using-basic-events-in-the-lazyforeach-scenario).

### gestureEvent<sup>14+</sup>

get gestureEvent(): UIGestureEvent

Obtains the **UIGestureEvent** object held by this FrameNode, which is used to set gesture events bound to the component. Gesture events set using the **gestureEvent** API will not override gestures bound using the [declarative gesture API](./arkui-ts/ts-gesture-settings.md). If both APIs are used to set gestures, the declarative API takes precedence.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                                                            |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [UIGestureEvent](./arkui-ts/ts-uigestureevent.md) | **UIGestureEvent** object, which is used to set the gestures bound to the component.|

**Example**

For details, see [Gesture Event Example](#gesture-event-example).

### onDraw<sup>12+</sup>

onDraw?(context: DrawContext): void

Called when this FrameNode performs content rendering.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| context | [DrawContext](./js-apis-arkui-graphics.md#drawcontext) | Yes  | Graphics drawing context. The self-drawing area cannot exceed the component's own size.|

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

### onMeasure<sup>12+</sup>

onMeasure(constraint: LayoutConstraint): void

Called when this FrameNode needs to determine its size. This API provides custom measurement and overrides the default measurement method.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| constraint | [LayoutConstraint](#layoutconstraint12) | Yes  | Layout constraints used by the component for measurement.|

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

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

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | Yes  | Position information used in layout.|

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

### setMeasuredSize<sup>12+</sup>

setMeasuredSize(size: Size): void

Sets the measured size of this FrameNode. The default unit is PX. If the configured width and height are negative numbers, the value is automatically set to 0.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| size | [Size](./js-apis-arkui-graphics.md#size) | Yes  | Measured size of the FrameNode.|

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

### setLayoutPosition<sup>12+</sup>

setLayoutPosition(position: Position): void

Sets the position of this FrameNode after layout. The default unit is PX.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | Yes  | Position of the FrameNode after layout.|

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

### measure<sup>12+</sup>

measure(constraint: LayoutConstraint): void

Measures this FrameNode and calculates its size based on the layout constraints of the parent container. If the measurement method is overridden, the overridden method is called. It is recommended that this API be called in [onMeasure](#onmeasure12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| constraint | [LayoutConstraint](#layoutconstraint12) | Yes  | Parent container layout constraints used for measurement.|

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

### layout<sup>12+</sup>

layout(position: Position): void

Lays out this FrameNode, specifying the layout positions for the FrameNode and its child nodes. If the layout method is overridden, the overridden method is called. It is recommended that this API be called in [onLayout](#onlayout12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | Yes  | Position information used in layout.|

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

### setNeedsLayout<sup>12+</sup>

setNeedsLayout(): void

Marks this FrameNode as needing layout, so that it will be relaid out in the next frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

See [Example of Customizing a Node](#example-of-customizing-a-node).

### invalidate<sup>12+</sup>

invalidate(): void

Invalidates this FrameNode to trigger a re-rendering of the self-drawing content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### addComponentContent<sup>12+</sup>

addComponentContent\<T>(content: ComponentContent\<T>): void

Adds component content. The current node must be modifiable, which means the return value of [isModifiable](#ismodifiable12) must be **true**. If the node is not modifiable, an exception is thrown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| content | [ComponentContent](./js-apis-arkui-ComponentContent.md#componentcontent)\<T> | Yes  | Component content to display on the FrameNode.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

```ts
import { NodeController, FrameNode, ComponentContent, typeNode } from '@kit.ArkUI';

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
    if (row4.isModifiable()) {
      row4.addComponentContent(component)
      col.appendChild(row4)
    }
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
import { FrameNode, NodeController, BuilderNode } from '@kit.ArkUI';

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

See [Example of Customizing a Node](#example-of-customizing-a-node).

### setCrossLanguageOptions<sup>15+</sup>

setCrossLanguageOptions(options: CrossLanguageOptions): void

Sets the cross-language options for this FrameNode. If the FrameNode is not modifiable or does not support setting cross-language options, an exception is thrown.

> **NOTE**
>
> Currently, only the following types of [TypedFrameNode](#typedframenode12) support setting cross-language options: [Scroll](#scroll12).

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                   | Mandatory| Description                 |
| ------------ | ----------------------- | ---- | --------------------- |
| options | [CrossLanguageOptions](#crosslanguageoptions15) | Yes  | Cross-language options.|

**Error codes**

| ID| Error Message                         |
| -------- | -------------------------------- |
| 100022   | The FrameNode cannot be set whether to support cross-language common attribute setting. |

**Example**

See [Example of Node Operations](#example-of-node-operations).

### getCrossLanguageOptions<sup>15+</sup>

getCrossLanguageOptions(): CrossLanguageOptions

Obtains the cross-language options of this FrameNode.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                   | Description                 |
| ----------------------- | --------------------- |
| [CrossLanguageOptions](#crosslanguageoptions15) | Cross-language options.|

**Example**

See [Example of Node Operations](#example-of-node-operations).

## TypedFrameNode<sup>12+</sup>

Inherits from [FrameNode](#framenode), used to declare a specific type of FrameNode.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type| Read-Only| Optional| Description                                                        |
| ---------- | ---- | ---- | ---- | ------------------------------------------------------------ |
| initialize | C    | No  | No  | Creates construction parameters of a component to set or update the initial value of the component.|
| attribute  | T    | No  | No  | Obtains the attribute setting object of a component to set or update the common and private attributes of the component.|

> **NOTE**
>
> The [commonAttribute](#commonattribute12) API is only effective on **CustomFrameNode**. For **TypedFrameNode**, the behavior of** commonAttribute** is undefined. For setting universal attributes, it is recommended that you use the [attribute](#properties) API, such as **node.attribute.backgroundColor(Color.Pink)**, rather than [commonAttribute](#commonattribute12).

## typeNode<sup>12+</sup>

Provides APIs for creating a specific type of FrameNode, which can be mounted through the basic API of the FrameNode and be displayed using a placeholder container.

When **typeNode** is used to create nodes such as **Text**, **Image**, **Select**, or **Toggle**, if the [UIContext](./js-apis-arkui-UIContext.md) instance corresponding to the passed **UIContext** is destroyed, calling this API will return an invalid FrameNode. This invalid node cannot be properly mounted or displayed.

**Example**

For details, see [Example of Customizing a Node of a Specific Type](#example-of-customizing-a node-of-a-specific-type).

### Text<sup>12+</sup>
type Text = TypedFrameNode&lt;TextInterface, TextAttribute&gt;

Represents a FrameNode of the **Text** type. This type of node does not allow child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                              | Description                                                        |
| -------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;TextInterface, TextAttribute&gt; | FrameNode of the **Text** type.<br>**NOTE**<br> **TextInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Text** component.<br> **TextAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Text** component.|

### createNode('Text')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Text'): Text

Creates a FrameNode of the **Text** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Text' | Yes| Node type, which is **Text** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Text](#text12) | FrameNode node of the **Text** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Text');
```

### Column<sup>12+</sup>
type Column = TypedFrameNode&lt;ColumnInterface, ColumnAttribute&gt;

Represents a FrameNode of the **Column** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                  | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ColumnInterface, ColumnAttribute&gt; | FrameNode of the **Column** type.<br>**NOTE**<br> **ColumnInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Column** component.<br> **ColumnAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Column** component.|

### createNode('Column')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Column'): Column

Creates a FrameNode of the **Column** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Column' | Yes| Node type, which is **Column** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Column](#column12) | FrameNode node of the **Column** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Column');
```
### Row<sup>12+</sup>
type Row = TypedFrameNode&lt;RowInterface, RowAttribute&gt;

Represents a FrameNode of the **Row** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                            | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;RowInterface, RowAttribute&gt; | FrameNode of the **Row** type.<br>**NOTE**<br> **RowInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Row** component.<br> **RowAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Row** component.|

### createNode('Row')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Row'): Row

Creates a FrameNode of the Row type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Row' | Yes| Node type, which is Row in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Row](#row12) | FrameNode node of the **Row** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Row');
```
### Stack<sup>12+</sup>
type Stack = TypedFrameNode&lt;StackInterface, StackAttribute&gt;

Represents a FrameNode of the **Stack** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;StackInterface, StackAttribute&gt; | FrameNode of the **Stack** type.<br>**NOTE**<br> **StackInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Stack** component.<br> **StackAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Stack** component.|

### createNode('Stack')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Stack'): Stack

Creates a FrameNode of the **Stack** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Stack' | Yes| Node type, which is **Stack** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Stack](#stack12) | FrameNode node of the **Stack** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Stack');
```
### GridRow<sup>12+</sup>
type GridRow = TypedFrameNode&lt;GridRowInterface, GridRowAttribute&gt;

Represents a FrameNode of the **GridRow** type. This type of node only allows child components of the **GridCol** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                    | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;GridRowInterface, GridRowAttribute&gt; | FrameNode of the **GridRow** type.<br>**NOTE**<br> **GridRowInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **GridRow** component.<br> **GridRowAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **GridRow** component.|

### createNode('GridRow')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'GridRow'): GridRow

Creates a FrameNode of the **GridRow** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'GridRow' | Yes| Node type, which is **GridRow** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [GridRow](#gridrow12) | FrameNode node of the **GridRow** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'GridRow');
```
### GridCol<sup>12+</sup>
type GridCol = TypedFrameNode&lt;GridColInterface, GridColAttribute&gt;

Represents a FrameNode of the **GridCol** type. This type of node does not allow child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                    | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;GridColInterface, GridColAttribute&gt; | FrameNode of the GridCol type.<br>**NOTE**<br> **GridColInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **GridCol** component.<br> **GridColAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **GridCol** component.|

### createNode('GridCol')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'GridCol'): GridCol

Creates a FrameNode of the **GridCol** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'GridCol' | Yes| Node type, which is **GridCol** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [GridCol](#gridcol12) | FrameNode node of the **GridCol** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'GridCol');
```
### Flex<sup>12+</sup>
type Flex = TypedFrameNode&lt;FlexInterface, FlexAttribute&gt;

Represents a FrameNode of the Flex type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                              | Description                                                        |
| -------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;FlexInterface, FlexAttribute&gt; | FrameNode of the Flex type.<br>**NOTE**<br> **FlexInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Flex** component.<br> **FlexAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Flex** component.|

### createNode('Flex')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Flex'): Flex

Creates a FrameNode of the Flex type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Flex' | Yes| Node type, which is **Flex** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Flex](#flex12) | FrameNode node of the **Flex** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Flex');
```
### Swiper<sup>12+</sup>
type Swiper = TypedFrameNode&lt;SwiperInterface, SwiperAttribute&gt;

Represents a FrameNode of the **Swiper** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                  | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;SwiperInterface, SwiperAttribute&gt; | FrameNode of the **Swiper** type.<br>**NOTE**<br> **SwiperInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Swiper** component.<br> **SwiperAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Swiper** component.|

### createNode('Swiper')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Swiper'): Swiper

Creates a FrameNode of the **Swiper** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Swiper' | Yes| Node type, which is **Swiper** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Swiper](#swiper12) | FrameNode node of the **Swiper** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Swiper');
```
### Progress<sup>12+</sup>
type Progress = TypedFrameNode&lt;ProgressInterface, ProgressAttribute&gt;

Represents a FrameNode of the **Progress** type. This type of node does not allow child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                      | Description                                                        |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ProgressInterface, ProgressAttribute&gt; | FrameNode of the **Progress** type.<br>**NOTE**<br> **ProgressInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Progress** component.<br> **ProgressAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Progress** component.|

### createNode('Progress')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Progress'): Progress

Creates a FrameNode of the **Progress** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Progress' | Yes| Node type, which is **Progress** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Progress](#progress12) | FrameNode node of the **Progress** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Progress');
```
### Scroll<sup>12+</sup>
type Scroll = TypedFrameNode&lt;ScrollInterface, ScrollAttribute&gt;

Represents a FrameNode of the Scroll type. This type of node allows only one child component to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                  | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ScrollInterface, ScrollAttribute&gt; | FrameNode of the Scroll type.<br>**NOTE**<br> **ScrollInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Scroll** component.<br> **ScrollAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Scroll** component.|

### createNode('Scroll')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Scroll'): Scroll

Creates a FrameNode of the **Scroll** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Scroll' | Yes| Node type, which is **Scroll** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Scroll](#scroll12) | FrameNode node of the **Scroll** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Scroll');
```

### getAttribute('Scroll')<sup>15+</sup>
getAttribute(node: FrameNode, nodeType: 'Scroll'): ScrollAttribute | undefined

Obtains the attributes of a **Scroll** node. If the node is not created using ArkTS, cross-language access must be enabled; otherwise, **undefined** is returned. This API does not support declaratively created nodes.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| node | [FrameNode](./js-apis-arkui-frameNode.md) | Yes  | Target node from which to obtain attributes.|
| nodeType | 'Scroll' | Yes| Node type.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| ScrollAttribute \| undefined | Attributes of the **Scroll** node, or **undefined** if they fail to be obtained.|

**Example**

<!--code_no_check-->

```ts
typeNode.getAttribute(node, 'Scroll');
```

### bindController('Scroll')<sup>15+</sup>
bindController(node: FrameNode, controller: Scroller, nodeType: 'Scroll'): void

Binds a **Scroller** controller to a **Scroll** node. If the node is not created using ArkTS, cross-language access must be enabled; otherwise, an exception is returned. This API does not support declaratively created nodes.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| node | [FrameNode](./js-apis-arkui-frameNode.md) | Yes  | Target node to which the scroll controller is bound.|
| controller | [Scroller](arkui-ts/ts-container-scroll.md#scroller) | Yes  | Scroll controller.|
| nodeType | 'Scroll' | Yes| Node type, which is **Scroll** in this API.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. The type of the node is error; 2.The node is null or undefined. |
| 100021   | The FrameNode is not modifiable. |

**Example**

<!--code_no_check-->

```ts
typeNode.bindController(node, scroller, 'Scroll');
```
### RelativeContainer<sup>12+</sup>
type RelativeContainer = TypedFrameNode&lt;RelativeContainerInterface, RelativeContainerAttribute&gt;

Represents a FrameNode of the **RelativeContainer** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;RelativeContainerInterface, RelativeContainerAttribute&gt; | FrameNode of the RelativeContainer type.<br>**NOTE**<br> **RelativeContainerInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **RelativeContainer** component.<br> **RelativeContainerAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **RelativeContainer** component.|

### createNode('RelativeContainer')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'RelativeContainer'): RelativeContainer

Creates a FrameNode of the **RelativeContainer** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'RelativeContainer' | Yes| Node type, which is **RelativeContainer** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [RelativeContainer](#relativecontainer12) | FrameNode node of the **RelativeContainer** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'RelativeContainer');
```
### Divider<sup>12+</sup>
type Divider = TypedFrameNode&lt;DividerInterface, DividerAttribute&gt;

Represents a FrameNode of the Divider type. This type of node does not allow child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                    | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;DividerInterface, DividerAttribute&gt; | FrameNode of the **Divider** type.<br>**NOTE**<br> **DividerInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Divider** component.<br> **DividerAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Divider** component.|

### createNode('Divider')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Divider'): Divider

Creates a FrameNode of the **Divider** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Divider' | Yes| Node type, which is **Divider** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Divider](#divider12) | FrameNode node of the **Divider** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Divider');
```
### LoadingProgress<sup>12+</sup>
type LoadingProgress = TypedFrameNode&lt;LoadingProgressInterface, LoadingProgressAttribute&gt;

Represents a FrameNode of the **LoadingProgress** type. This type of node does not allow child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;LoadingProgressInterface, LoadingProgressAttribute&gt; | FrameNode of the **LoadingProgress** type.<br>**NOTE**<br> **LoadingProgressInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **LoadingProgress** component.<br> **LoadingProgressAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **LoadingProgress** component.|

### createNode('LoadingProgress')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'LoadingProgress'): LoadingProgress

Creates a FrameNode of the **LoadingProgress** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'LoadingProgress' | Yes| Node type, which is **LoadingProgress** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [LoadingProgress](#loadingprogress12) | FrameNode node of the **LoadingProgress** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'LoadingProgress');
```
### Search<sup>12+</sup>
type Search = TypedFrameNode&lt;SearchInterface, SearchAttribute&gt;

Represents a FrameNode of the **Search** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                  | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;SearchInterface, SearchAttribute&gt; | FrameNode of the **Search** type.<br>**NOTE**<br> **SearchInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Search** component.<br> **SearchAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Search** component.|

### createNode('Search')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Search'): Search

Creates a FrameNode of the **Search** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Search' | Yes| Node type, which is **Search** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Search](#search12) | FrameNode node of the **Search** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Search');
```
### Blank<sup>12+</sup>
type Blank = TypedFrameNode&lt;BlankInterface, BlankAttribute&gt;

Represents a FrameNode of the **Blank** type. This type of node does not allow child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;BlankInterface, BlankAttribute&gt; | FrameNode of the **Blank** type.<br>**NOTE**<br> **BlankInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Blank** component.<br> **BlankAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Blank** component.|

### createNode('Blank')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Blank'): Blank;

Creates a FrameNode of the **Blank** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Blank' | Yes| Node type, which is **Blank** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Blank](#blank12) | FrameNode node of the **Blank** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Blank');
```
### Image<sup>12+</sup>
type Image = TypedFrameNode&lt;ImageInterface, ImageAttribute&gt;

Represents a FrameNode of the **Image** type. This type of node does not allow child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ImageInterface, ImageAttribute&gt; | FrameNode of the **Image** type.<br>**NOTE**<br> **ImageInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Image** component.<br> **ImageAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Image** component.|

### createNode('Image')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Image'): Image

Creates a FrameNode of the **Image** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Image' | Yes| Node type, which is **Image** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Image](#image12) | FrameNode node of the **Image** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Image');
```
### List<sup>12+</sup>
type List = TypedFrameNode&lt;ListInterface, ListAttribute&gt;

Represents a FrameNode of the **List** type. This type of node only allows child components of the **ListItem** and **ListItemGroup** types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                              | Description                                                        |
| -------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ListInterface, ListAttribute&gt; | FrameNode of the **List** type.<br>**NOTE**<br> **ListInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **List** component.<br> **ListAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **List** component.|

### createNode('List')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'List'): List

Creates a FrameNode of the **List** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'List' | Yes| Node type, which is **List** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [List](#list12) | FrameNode node of the **List** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'List');
```
### ListItem<sup>12+</sup>
type ListItem = TypedFrameNode&lt;ListItemInterface, ListItemAttribute&gt;

Represents a FrameNode of the **ListItem** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                      | Description                                                        |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ListItemInterface, ListItemAttribute&gt; | FrameNode of the **ListItem** type.<br>**NOTE**<br> **ListItemInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **ListItem** component.<br> **ListItemAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **ListItem** component.|

### createNode('ListItem')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'ListItem'): ListItem

Creates a FrameNode of the **ListItem** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'ListItem' | Yes| Node type, which is **ListItem** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [ListItem](#listitem12) | FrameNode node of the **ListItem** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'ListItem');
```

### TextInput<sup>12+</sup>
type TextInput = TypedFrameNode&lt;TextInputInterface, TextInputAttribute&gt;

Represents a FrameNode of the **TextInput** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;TextInputInterface, TextInputAttribute&gt; | FrameNode of the **TextInput** type.<br>**NOTE**<br> **TextInputInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **TextInput** component.<br> **TextInputAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **TextInput** component.|

### createNode('TextInput')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'TextInput'): TextInput

Creates a FrameNode of the **TextInput** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'TextInput' | Yes| Node type, which is **TextInput** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [TextInput](#textinput12) | FrameNode node of the **TextInput** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextInput');
```

### Button<sup>12+</sup>
type Button = TypedFrameNode&lt;ButtonInterface, ButtonAttribute&gt;

Represents a FrameNode of the **Button** type. When created in child component mode, this type of node allows only one child component to be added. When created in label mode, it does not child components to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                  | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ButtonInterface, ButtonAttribute&gt; | FrameNode of the **Button** type.<br>**NOTE**<br> **ButtonInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Button** component.<br> **ButtonAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Button** component.<br> If a value is specified for the **label** parameter, a **Button** component is created in label mode. This component cannot contain child components, and any attempt to set child components will result in an exception. The mode in which the **Button** component is created cannot be dynamically modified in subsequent **initialize** calls. As such, to include child components, do not set the **label** parameter during the first **initialize** call.<br> When created in child component mode, a **Button** component can contain a single child component. Any attempt to set multiple child components will result in an exception.|

### createNode('Button')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Button'): Button

Creates a FrameNode of the **Button** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Button' | Yes| Node type, which is **Button** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Button](#button12) | FrameNode node of the **Button** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Button');
```

### ListItemGroup<sup>12+</sup>
type ListItemGroup = TypedFrameNode&lt;ListItemGroupInterface, ListItemGroupAttribute&gt;

Represents a FrameNode of the **ListItemGroup** type. This type of node only allows child components of the **ListItem** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ListItemGroupInterface, ListItemGroupAttribute&gt; | FrameNode of the **ListItemGroup** type.<br>**NOTE**<br> **ListItemGroupInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **ListItemGroup** component.<br> **ListItemGroupAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **ListItemGroup** component.|

### createNode('ListItemGroup')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'ListItemGroup'): ListItemGroup

Creates a FrameNode of the **ListItemGroup** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'ListItemGroup' | Yes| Node type, which is **ListItemGroup** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [ListItemGroup](#listitemgroup12) | FrameNode node of the **ListItemGroup** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'ListItemGroup');
```

### WaterFlow<sup>12+</sup>
type WaterFlow = TypedFrameNode&lt;WaterFlowInterface, WaterFlowAttribute&gt;

Represents a FrameNode of the **WaterFlow** type. This type of node only allows child components of the **FlowItem** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;WaterFlowInterface, WaterFlowAttribute&gt; | FrameNode of the **WaterFlow** type.<br>**NOTE**<br> **WaterFlowInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **WaterFlow** component.<br> **WaterFlowAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **WaterFlow** component.|

### createNode('WaterFlow')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'WaterFlow'): WaterFlow

Creates a FrameNode of the **WaterFlow** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'WaterFlow' | Yes| Node type, which is **WaterFlow** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [WaterFlow](#waterflow12) | FrameNode node of the **WaterFlow** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'WaterFlow');
```

### FlowItem<sup>12+</sup>
type FlowItem = TypedFrameNode&lt;FlowItemInterface, FlowItemAttribute&gt;

Represents a FrameNode of the **FlowItem** type. This type of node allows only one child component to be added.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                      | Description                                                        |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;FlowItemInterface, FlowItemAttribute&gt; | FrameNode of the **FlowItem** type.<br>**NOTE**<br> **FlowItemInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **FlowItem** component.<br> **FlowItemAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **FlowItem** component.|

### createNode('FlowItem')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'FlowItem'): FlowItem

Creates a FrameNode of the **FlowItem** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'FlowItem' | Yes| Node type, which is **FlowItem** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [FlowItem](#flowitem12) | FrameNode node of the **FlowItem** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'FlowItem');
```

### XComponent<sup>12+</sup>
type XComponent = TypedFrameNode&lt;XComponentInterface, XComponentAttribute&gt;

Represents a FrameNode of the **XComponent** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;XComponentInterface, XComponentAttribute&gt; | FrameNode of the **XComponent** type.<br>**NOTE**<br> **XComponentInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **XComponent** component.<br> **XComponentAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **XComponent** component.|

### createNode('XComponent')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'XComponent'): XComponent

Creates a FrameNode of the **XComponent** type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'XComponent' | Yes| Node type, which is **XComponent** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [XComponent](#xcomponent12) | FrameNode node of the **XComponent** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'XComponent');
```

### createNode('XComponent')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'XComponent', options: XComponentOptions): XComponent

Creates a FrameNode of the **XComponent** type based on the settings specified in **options**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'XComponent' | Yes| Node type, which is XComponent in this API.|
| options | [XComponentOptions](./arkui-ts/ts-basic-components-xcomponent.md#xcomponentoptions12) | Yes| Options of the **XComponent**.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [XComponent](#xcomponent12) | FrameNode node of the XComponent type.|

**Example**

<!--code_no_check-->

```ts
let controller: XComponentController = new XComponentController();
let options: XComponentOptions = {
  type: XComponentType.TEXTURE,
  controller: controller
};
typeNode.createNode(uiContext, 'XComponent', options);
```

### QRCode<sup>14+</sup>
type QRCode = TypedFrameNode&lt;QRCodeInterface, QRCodeAttribute&gt;

Represents a FrameNode of the **QRCode** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;QRCodeInterface, QRCodeAttribute&gt; | FrameNode of the **QRCode** type.<br>**NOTE**<br> **QRCodeInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **QRCode** component.<br> **QRCodeAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **QRCode** component.|

### createNode('QRCode')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'QRCode'): QRCode

Creates a FrameNode of the **QRCode** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'QRCode' | Yes| Node type, which is **QRCode** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [QRCode](#qrcode14) | FrameNode node of the **QRCode** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'QRCode');
```

### Badge<sup>14+</sup>
type Badge = TypedFrameNode&lt;BadgeInterface, BadgeAttribute&gt;

Represents a FrameNode of the **Badge** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;BadgeInterface, BadgeAttribute&gt; | FrameNode of the **Badge** type.<br>**NOTE**<br> **BadgeInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Badge** component.<br> **BadgeAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Badge** component.|

### createNode('Badge')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'Badge'): Badge

Creates a FrameNode of the **Badge** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Badge' | Yes| Node type, which is **Badge** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Badge](#badge14) | FrameNode node of the **Badge** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Badge');
```

### Grid<sup>14+</sup>
type Grid = TypedFrameNode&lt;GridInterface, GridAttribute&gt;

Represents a FrameNode of the **Grid** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;GridInterface, GridAttribute&gt; | FrameNode of the **Grid** type.<br>**NOTE**<br> **GridInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Grid** component.<br> **GridAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Grid** component.|

### createNode('Grid')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'Grid'): Grid

Creates a FrameNode of the **Grid** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Grid' | Yes| Node type, which is **Grid** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Grid](#grid14) | FrameNode node of the **Grid** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Grid');
```

### GridItem<sup>14+</sup>
type GridItem = TypedFrameNode&lt;GridItemInterface, GridItemAttribute&gt;

Represents a FrameNode of the **GridItem** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;GridItemInterface, GridItemAttribute&gt; | FrameNode of the **GridItem** type.<br>**NOTE**<br> **GridItemInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **GridItem** component.<br> **GridItemAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **GridItem** component.|

### createNode('GridItem')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'GridItem'): GridItem

Creates a FrameNode of the **GridItem** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'GridItem' | Yes| Node type, which is **GridItem** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [GridItem](#griditem14) | FrameNode node of the **GridItem** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'GridItem');
```

### TextClock<sup>14+</sup>
type TextClock = TypedFrameNode&lt;TextClockInterface, TextClockAttribute&gt;

Represents a FrameNode of the **TextClock** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;TextClockInterface, TextClockAttribute&gt; | FrameNode of the **TextClock** type.<br>**NOTE**<br> **TextClockInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **TextClock** component.<br> **TextClockAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **TextClock** component.|

### createNode('TextClock')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'TextClock'): TextClock

Creates a FrameNode of the **TextClock** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'TextClock' | Yes| Node type, which is **TextClock** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [TextClock](#textclock14) | FrameNode node of the **TextClock** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextClock');
```

### TextTimer<sup>14+</sup>
type TextTimer = TypedFrameNode&lt;TextTimerInterface, TextTimerAttribute&gt;

Represents a FrameNode of the **TextTimer** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;TextTimerInterface, TextTimerAttribute&gt; | FrameNode of the **TextTimer** type.<br>**NOTE**<br> **TextTimerInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **TextTimer** component.<br> **TextTimerAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **TextTimer** component.|

### createNode('TextTimer')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'TextTimer'): TextTimer

Creates a FrameNode of the **TextTimer** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'TextTimer' | Yes| Node type, which is **TextTimer** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [TextTimer](#texttimer14) | FrameNode node of the **TextTimer** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextTimer');
```

### Marquee<sup>14+</sup>
type Marquee = TypedFrameNode&lt;MarqueeInterface, MarqueeAttribute&gt;

Represents a FrameNode of the **Marquee** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;MarqueeInterface, MarqueeAttribute&gt; | FrameNode of the **Marquee** type.<br>**NOTE**<br> **MarqueeInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Marquee** component.<br> **MarqueeAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Marquee** component.|

### createNode('Marquee')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'Marquee'): Marquee

Creates a FrameNode of the **Marquee** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Marquee' | Yes| Node type, which is **Marquee** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Marquee](#marquee14) | FrameNode node of the **Marquee** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Marquee');
```

### TextArea<sup>14+</sup>
type TextArea = TypedFrameNode&lt;TextAreaInterface, TextAreaAttribute&gt;

Represents a FrameNode of the **TextArea** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;TextAreaInterface, TextAreaAttribute&gt; | FrameNode of the **TextArea** type.<br>**NOTE**<br> **TextAreaInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **TextArea** component.<br> **TextAreaAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **TextArea** component.|

### createNode('TextArea')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'TextArea'): TextArea

Creates a FrameNode of the **TextArea** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'TextArea' | Yes| Node type, which is **TextArea** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [TextArea](#textarea14) | FrameNode node of the **TextArea** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextArea');
```

### SymbolGlyph<sup>14+</sup>
type SymbolGlyph = TypedFrameNode&lt;SymbolGlyphInterface, SymbolGlyphAttribute&gt;

Represents a FrameNode of the **SymbolGlyph** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SymbolGlyphInterface, SymbolGlyphAttribute&gt; | FrameNode of the **SymbolGlyph** type.<br>**NOTE**<br> **SymbolGlyphInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **SymbolGlyph** component.<br> **SymbolGlyphAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **SymbolGlyph** component.|

### createNode('SymbolGlyph')<sup>14+</sup>
createNode(context: UIContext, nodeType: 'SymbolGlyph'): SymbolGlyph

Creates a FrameNode of the **SymbolGlyph** type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'SymbolGlyph' | Yes| Node type, which is **SymbolGlyph** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [SymbolGlyph](#symbolglyph14) | FrameNode node of the **SymbolGlyph** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'SymbolGlyph');
```

### Checkbox<sup>16+</sup>
type Checkbox = TypedFrameNode&lt;CheckboxInterface, CheckboxAttribute&gt;

Represents a FrameNode of the **Checkbox** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;CheckboxInterface, CheckboxAttribute&gt; | FrameNode of the **Checkbox** type.<br>**NOTE**<br> **CheckboxInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Checkbox** component.<br> **CheckboxAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Checkbox** component.|

### createNode('Checkbox')<sup>16+</sup>
createNode(context: UIContext, nodeType: 'Checkbox'): Checkbox

Creates a FrameNode of the **Checkbox** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Checkbox' | Yes| Node type, which is **Checkbox** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Checkbox](#checkbox16) | FrameNode node of the **Checkbox** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Checkbox');
```

### CheckboxGroup<sup>16+</sup>
type CheckboxGroup = TypedFrameNode&lt;CheckboxGroupInterface, CheckboxGroupAttribute&gt;

Represents a FrameNode of the **CheckboxGroup** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;CheckboxGroupInterface, CheckboxGroupAttribute&gt; | FrameNode of the **CheckboxGroup** type.<br>**NOTE**<br> **CheckboxGroupInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **CheckboxGroup** component.<br> **CheckboxGroupAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **CheckboxGroup** component.|

### createNode('CheckboxGroup')<sup>16+</sup>
createNode(context: UIContext, nodeType: 'CheckboxGroup'): CheckboxGroup

Creates a FrameNode of the **CheckboxGroup** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'CheckboxGroup' | Yes| Node type, which is **CheckboxGroup** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [CheckboxGroup](#checkboxgroup16) | FrameNode node of the **CheckboxGroup** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'CheckboxGroup');
```

### Rating<sup>16+</sup>
type Rating = TypedFrameNode&lt;RatingInterface, RatingAttribute&gt;

Represents a FrameNode of the **Rating** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;RatingInterface, RatingAttribute&gt; | FrameNode of the **Rating** type.<br>**NOTE**<br> **RatingInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Rating** component.<br> **RatingAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Rating** component.|

### createNode('Rating')<sup>16+</sup>
createNode(context: UIContext, nodeType: 'Rating'): Rating

Creates a FrameNode of the **Rating** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Rating' | Yes| Node type, which is **Rating** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Rating](#rating16) | FrameNode node of the **Rating** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Rating');
```

### Radio<sup>16+</sup>
type Radio = TypedFrameNode&lt;RadioInterface, RadioAttribute&gt;

Represents a FrameNode of the **Radio** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;RadioInterface, RadioAttribute&gt; | FrameNode of the **Radio** type.<br>**NOTE**<br> **RadioInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Radio** component.<br> **RadioAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Radio** component.|

### createNode('Radio')<sup>16+</sup>
createNode(context: UIContext, nodeType: 'Radio'): Radio

Creates a FrameNode of the **Radio** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Radio' | Yes| Node type, which is **Radio** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Radio](#radio16) | FrameNode node of the **Radio** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Radio');
```

### Slider<sup>16+</sup>
type Slider = TypedFrameNode&lt;SliderInterface, SliderAttribute&gt;

Represents a FrameNode of the **Slider** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SliderInterface, SliderAttribute&gt; | FrameNode of the **Slider** type.<br>**NOTE**<br> **SliderInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Slider** component.<br> **SliderAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Slider** component.|

### createNode('Slider')<sup>16+</sup>
createNode(context: UIContext, nodeType: 'Slider'): Slider

Creates a FrameNode of the **Slider** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Slider' | Yes| Node type, which is **Slider** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Slider](#slider16) | FrameNode node of the **Slider** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Slider');
```

### Select<sup>16+</sup>
type Select = TypedFrameNode&lt;SelectInterface, SelectAttribute&gt;

Represents a FrameNode of the **Select** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SelectInterface, SelectAttribute&gt; | FrameNode of the **Select** type.<br>**NOTE**<br> **SelectInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Select** component.<br> **SelectAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Select** component.|

### createNode('Select')<sup>16+</sup>
createNode(context: UIContext, nodeType: 'Select'): Select

Creates a FrameNode of the **Select** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Select' | Yes| Node type, which is **Select** in this API.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Select](#select16) | FrameNode node of the **Select** type.|

**Example**

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Select');
```

### Toggle<sup>16+</sup>
type Toggle = TypedFrameNode&lt;ToggleInterface, ToggleAttribute&gt;

Represents a FrameNode of the **Toggle** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                           | Description                  |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ToggleInterface, ToggleAttribute&gt; | FrameNode of the **Toggle** type.<br>**NOTE**<br> **ToggleInterface** is used as the input parameter of the [initialize](#properties) API of [TypedFrameNode](#typedframenode12). The input parameter is of the constructor type for the **Toggle** component.<br> **ToggleAttribute** is used as the return value of the [attribute](#properties) API of **TypedFrameNode**. It returns the attribute setting object of the **Toggle** component.|

### createNode('Toggle')<sup>16+</sup>
createNode(context: UIContext, nodeType: 'Toggle', options?: ToggleOptions): Toggle

Creates a FrameNode of the **Toggle** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|
| nodeType | 'Toggle' | Yes| Node type, which is **Toggle** in this API.|
| options | ToggleOptions | No| Options for creating the **Toggle** node.|

**Return value**

| Type                 | Description     |
| ------------------ | ------------------ |
| [Toggle](#toggle16) | FrameNode node of the **Toggle** type.|

**Example**

<!--code_no_check-->

```ts
let toggleOptions: ToggleOptions = {type: ToggleType.Button, isOn: false};
typeNode.createNode(uiContext, 'Toggle', toggleOptions);
```

## NodeAdapter<sup>12+</sup>

Provides the lazy loading capability for the FrameNodes.

> **NOTE**
>
> The input parameter cannot be a negative number; otherwise, no processing is performed.

**Example**

For details, see [NodeAdapter Usage Example](#nodeadapter-usage-example).

### constructor<sup>12+</sup>

constructor()

A constructor used to create a **NodeAdapter** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### dispose<sup>12+</sup>

dispose(): void

Disposes of this **NodeAdapter** object. Bindings, if any, of the object will be cleared before the object is disposed of.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### totalNodeCount<sup>12+</sup>

set totalNodeCount(count: number)

Sets the total number of items in this node.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| count | number | Yes  | Total number of items.|

get totalNodeCount(): number

Obtains the total number of items in this node.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                    | Description                |
| ----------------- | ------------ |
| number | Total number of items.|

### reloadAllItems<sup>12+</sup>

reloadAllItems(): void

Reloads all items in this node.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### reloadItem<sup>12+</sup>

reloadItem(start: number, count: number): void

Reloads a specified number of items starting from a specific index.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| start | number | Yes  | Starting index of the items to reload.|
| count | number | Yes  | Number of the items to reload.|

### removeItem<sup>12+</sup>

removeItem(start: number, count: number): void

Removes a specified number of items starting from a specific index.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| start | number | Yes  | Starting index of the items to remove.|
| count | number | Yes  | Number of the items to remove.|

### insertItem<sup>12+</sup>

insertItem(start: number, count: number): void

Inserts a specified number of items starting from a specific index.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| start | number | Yes  | Starting index of the items to insert.|
| count | number | Yes  | Number of the items to insert.|

### moveItem<sup>12+</sup>

moveItem(from: number, to: number): void

Moves items from the starting index to the ending index.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| from | number | Yes  | Original index from which the data will be moved.|
| to | number | Yes  | Target index to which the data will be moved.|

### getAllAvailableItems<sup>12+</sup>

getAllAvailableItems(): Array&lt;FrameNode&gt;

Obtains all available items.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                    | Description                |
| ----------------- | ------------ |
| Array&lt;FrameNode&gt; | Array of items in the FrameNode.|

### onAttachToNode<sup>12+</sup>

onAttachToNode?(target: FrameNode): void

Called when a FrameNode is attached to the NodeAdapter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| target | FrameNode | Yes  | FrameNode attached to the NodeAdapter.|

### onDetachFromNode<sup>12+</sup>

onDetachFromNode?(): void

Called when detachment occurs.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onGetChildId<sup>12+</sup>

onGetChildId?(index: number): number

Called when this node is loaded for the first time or a new child node is detected. This API is used to generate custom IDs. You must ensure the uniqueness of the IDs.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| index | number | Yes  | Index of the loaded node.|

**Return value**

| Type                    | Description                |
| ----------------- | ------------ |
| number | ID customized by you. Make sure the ID is unique.|

### onCreateChild<sup>12+</sup>

onCreateChild?(index: number): FrameNode

Called when this node is loaded for the first time or a new child node is detected.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| index | number | Yes  | Index of the loaded node.|

**Return value**

| Type                    | Description                |
| ----------------- | ------------ |
| FrameNode | FrameNode created by you.|

### onDisposeChild<sup>12+</sup>

onDisposeChild?(id: number, node: FrameNode): void

Called when a child node is about to be disposed of.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| id | number | Yes  | ID of the child node to be disposed of.|
| node | FrameNode | Yes  | FrameNode to be disposed of.|

### onUpdateChild<sup>12+</sup>

onUpdateChild?(id: number, node: FrameNode): void

Called when a loaded node is reused.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| id | number | Yes  | ID of the node that is reused.|
| node | FrameNode | Yes  | FrameNode that is reused.|

### attachNodeAdapter<sup>12+</sup>

static attachNodeAdapter(adapter: NodeAdapter, node: FrameNode): boolean

Attaches a FrameNode to a NodeAdapter. Each node can be bound to only one NodeAdapter. Attempts to re-attach to a NodeAdapter that has already been attached to will fail and return **false**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| adapter | [NodeAdapter](#nodeadapter12) | Yes  | NodeAdapter class for lazy loading.|
| node | FrameNode | Yes  | FrameNode to be attached to the NodeAdapter.|

**Return value**

| Type                    | Description                |
| ----------------- | ------------ |
| boolean | Attachment result. Returns **true** if the attachment is successful; returns **false** otherwise.|

### detachNodeAdapter<sup>12+</sup>

static detachNodeAdapter(node: FrameNode): void

Detaches a FrameNode from a NodeAdapter.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory| Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| node | FrameNode | Yes  | FrameNode to detach.|

## Example of Customizing a Node of a Specific Type

The following example shows how to create a node of the Text type.

```ts
import { NodeController, FrameNode, typeNode } from '@kit.ArkUI';

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

## Example of Node Operations
```ts
import { NodeController, FrameNode, UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

const TEST_TAG: string = "FrameNode "

class MyNodeController extends NodeController {
  public frameNode: FrameNode | null = null;
  public childList: Array<FrameNode> = new Array<FrameNode>();
  private rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;
  private childrenCount: number = 0;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.uiContext = uiContext;

    this.frameNode = new FrameNode(uiContext);
    this.frameNode.commonAttribute.backgroundColor(Color.Pink);
    this.frameNode.commonAttribute.size({ width: 100, height: 100 });

    this.rootNode.appendChild(this.frameNode);
    this.childrenCount = this.childrenCount + 1;
    for (let i = 0; i < 10; i++) {
      let childNode = new FrameNode(uiContext);
      this.childList.push(childNode);
      this.frameNode.appendChild(childNode);
    }
    return this.rootNode;
  }

  createFrameNode() {
    let frameNode = new FrameNode(this.uiContext!);
    frameNode.commonAttribute.backgroundColor(Color.Pink);
    frameNode.commonAttribute.size({ width: 100, height: 100 });
    frameNode.commonAttribute.position({ x: this.childrenCount * 120, y: 0 });

    return frameNode;
  }

  appendChild() {
    const childNode = this.createFrameNode();
    this.rootNode!.appendChild(childNode);
    this.childrenCount = this.childrenCount + 1;
  }

  insertChildAfter(index: number) {
    let insertNode = this.createFrameNode();
    let childNode = this.rootNode!.getChild(index);
    this.rootNode!.insertChildAfter(insertNode, childNode);
    this.childrenCount = this.childrenCount + 1;
  }

  removeChild(index: number) {
    let childNode = this.rootNode!.getChild(index);
    if (childNode == null) {
      console.log(`${TEST_TAG} getchild at index {${index}} : fail`);
      return;
    }
    this.rootNode!.removeChild(childNode);
    this.childrenCount = this.childrenCount - 1;
  }

  getChildNumber() {
    console.log(TEST_TAG + " getChildNumber " + this.rootNode!.getChildrenCount())
    console.log(TEST_TAG + " children count is " + this.childrenCount);
  }

  clearChildren() {
    this.rootNode!.clearChildren();
  }

  searchFrameNode() {
    if (this.rootNode!.getFirstChild() === null) {
      console.log(TEST_TAG + " the rootNode does not have child node.")
    }
    if (this.rootNode!.getFirstChild() === this.frameNode) {
      console.log(TEST_TAG +
        " getFirstChild  result: success. The first child of the rootNode is equals to frameNode.");
    } else {
      console.log(TEST_TAG +
        " getFirstChild  result: fail. The first child of the rootNode is not equals to frameNode.");
    }
    if (this.frameNode!.getChild(5) === this.frameNode!.getChild(4)!.getNextSibling()) {
      console.log(TEST_TAG + " getNextSibling  result: success.");
    } else {
      console.log(TEST_TAG + " getNextSibling  result: fail.");
    }
    if (this.frameNode!.getChild(3) === this.frameNode!.getChild(4)!.getPreviousSibling()) {
      console.log(TEST_TAG + " getPreviousSibling  result: success.");
    } else {
      console.log(TEST_TAG + " getPreviousSibling  result: fail.");
    }
    if (this.rootNode!.getFirstChild() !== null && this.rootNode!.getFirstChild()!.getParent() === this.rootNode) {
      console.log(TEST_TAG + " getParent  result: success.");
    } else {
      console.log(TEST_TAG + " getParent  result: fail.");
    }
    if (this.rootNode!.getParent() !== undefined || this.rootNode!.getParent() !== null) {
      console.log(TEST_TAG + " get ArkTsNode success.")
      console.log(TEST_TAG + " check rootNode whether is modifiable " + this.rootNode!.isModifiable())
      console.log(TEST_TAG + " check getParent whether is modifiable " + this.rootNode!.getParent()!.isModifiable())
    } else {
      console.log(TEST_TAG + " get ArkTsNode fail.");
    }
  }

  moveFrameNode() {
    const currentNode = this.frameNode!.getChild(4);
    try {
      currentNode!.moveTo(this.rootNode, 0);
      if (this.rootNode!.getChild(0) === currentNode) {
        console.log(TEST_TAG + " moveTo  result: success.");
      } else {
        console.log(TEST_TAG + " moveTo  result: fail.");
      }
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " + (err as BusinessError).message);
      console.log(TEST_TAG + " moveTo  result: fail.");
    }
  }

  getPositionToWindow() {
    let positionToWindow = this.rootNode?.getPositionToWindow();
    console.log(TEST_TAG + JSON.stringify(positionToWindow));
  }

  getPositionToParent() {
    let positionToParent = this.rootNode?.getPositionToParent();
    console.log(TEST_TAG + JSON.stringify(positionToParent));
  }

  getPositionToScreen() {
    let positionToScreen = this.rootNode?.getPositionToScreen();
    console.log(TEST_TAG + JSON.stringify(positionToScreen));
  }

  getPositionToWindowWithTransform() {
    let positionToWindowWithTransform = this.rootNode?.getPositionToWindowWithTransform();
    console.log(TEST_TAG + JSON.stringify(positionToWindowWithTransform));
  }

  getPositionToParentWithTransform() {
    let positionToParentWithTransform = this.rootNode?.getPositionToParentWithTransform();
    console.log(TEST_TAG + JSON.stringify(positionToParentWithTransform));
  }

  getPositionToScreenWithTransform() {
    let positionToScreenWithTransform = this.rootNode?.getPositionToScreenWithTransform();
    console.log(TEST_TAG + JSON.stringify(positionToScreenWithTransform));
  }

  getMeasuredSize() {
    let measuredSize = this.frameNode?.getMeasuredSize();
    console.log(TEST_TAG + JSON.stringify(measuredSize));
  }

  getLayoutPosition() {
    let layoutPosition = this.frameNode?.getLayoutPosition();
    console.log(TEST_TAG + JSON.stringify(layoutPosition));
  }

  getUserConfigBorderWidth() {
    let userConfigBorderWidth = this.frameNode?.getUserConfigBorderWidth();
    console.log(TEST_TAG + JSON.stringify(userConfigBorderWidth));
  }

  getUserConfigPadding() {
    let userConfigPadding = this.frameNode?.getUserConfigPadding();
    console.log(TEST_TAG + JSON.stringify(userConfigPadding));
  }

  getUserConfigMargin() {
    let userConfigMargin = this.frameNode?.getUserConfigMargin();
    console.log(TEST_TAG + JSON.stringify(userConfigMargin));
  }

  getUserConfigSize() {
    let userConfigSize = this.frameNode?.getUserConfigSize();
    console.log(TEST_TAG + JSON.stringify(userConfigSize));
  }

  getId() {
    let id = this.frameNode?.getId();
    console.log(TEST_TAG + id);
  }

  getUniqueId() {
    let uniqueId = this.frameNode?.getUniqueId();
    console.log(TEST_TAG + uniqueId);
  }

  getNodeType() {
    let nodeType = this.frameNode?.getNodeType();
    console.log(TEST_TAG + nodeType);
  }

  getOpacity() {
    let opacity = this.frameNode?.getOpacity();
    console.log(TEST_TAG + JSON.stringify(opacity));
  }

  isVisible() {
    let visible = this.frameNode?.isVisible();
    console.log(TEST_TAG + JSON.stringify(visible));
  }

  isClipToFrame() {
    let clipToFrame = this.frameNode?.isClipToFrame();
    console.log(TEST_TAG + JSON.stringify(clipToFrame));
  }

  isAttached() {
    let attached = this.frameNode?.isAttached();
    console.log(TEST_TAG + JSON.stringify(attached));
  }

  getInspectorInfo() {
    let inspectorInfo = this.frameNode?.getInspectorInfo();
    console.log(TEST_TAG + JSON.stringify(inspectorInfo));
  }

  setCrossLanguageOptions() {
    console.log(TEST_TAG + " getCrossLanguageOptions " + JSON.stringify(this.frameNode?.getCrossLanguageOptions()));
    try {
      this.frameNode?.setCrossLanguageOptions({
        attributeSetting: true
      });
      console.log(TEST_TAG + " setCrossLanguageOptions success.");
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " + (err as BusinessError).message);
      console.log(TEST_TAG + " setCrossLanguageOptions fail.");
    }
    console.log(TEST_TAG + " getCrossLanguageOptions " + JSON.stringify(this.frameNode?.getCrossLanguageOptions()));
  }

  throwError() {
    try {
      this.rootNode!.getParent()!.clearChildren();
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " + (err as BusinessError).message);
    }
    try {
      this.rootNode!.getParent()!.appendChild(new FrameNode(this.uiContext));
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " + (err as BusinessError).message);
    }
    try {
      this.rootNode!.getParent()!.removeChild(this.rootNode!.getParent()!.getChild(0));
    } catch (err) {
      console.log(TEST_TAG + " " + (err as BusinessError).code + " : " + (err as BusinessError).message);
    }
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();
  private scroller: Scroller = new Scroller();
  @State index: number = 0;

  build() {
    Scroll(this.scroller) {
      Column({ space: 8 }) {
        Column() {
          Row() {
            Button("ADD")
              .onClick(() => {
                this.index++;
              })
            Button("DEC")
              .onClick(() => {
                this.index--;
              })
          }

          Text("Current index is " + this.index)
            .textAlign(TextAlign.Center)
            .borderRadius(10)
            .backgroundColor(0xFFFFFF)
            .width('100%')
            .fontSize(16)
        }

        Column() {
          Text("This is a NodeContainer.")
            .textAlign(TextAlign.Center)
            .borderRadius(10)
            .backgroundColor(0xFFFFFF)
            .width('100%')
            .fontSize(16)
          NodeContainer(this.myNodeController)
            .borderWidth(1)
            .width(300)
            .height(100)
        }

        Button("appendChild")
          .width(300)
          .onClick(() => {
            this.myNodeController.appendChild();
          })
        Button("insertChildAfter")
          .width(300)
          .onClick(() => {
            this.myNodeController.insertChildAfter(this.index);
          })
        Button("removeChild")
          .width(300)
          .onClick(() => {
            this.myNodeController.removeChild(this.index);
          })
        Button("clearChildren")
          .width(300)
          .onClick(() => {
            this.myNodeController.clearChildren();
          })
        Button("getChildNumber")
          .width(300)
          .onClick(() => {
            this.myNodeController.getChildNumber();
          })
        Button("searchFrameNode")
          .width(300)
          .onClick(() => {
            this.myNodeController.searchFrameNode();
          })
        Button("moveFrameNode")
          .width(300)
          .onClick(() => {
            this.myNodeController.moveFrameNode();
          })
        Button("getPositionToWindow")
          .width(300)
          .onClick(() => {
            this.myNodeController.getPositionToWindow();
          })
        Button("getPositionToParent")
          .width(300)
          .onClick(() => {
            this.myNodeController.getPositionToParent();
          })
        Button("getPositionToScreen")
          .width(300)
          .onClick(() => {
            this.myNodeController.getPositionToScreen();
          })
        Button("getPositionToParentWithTransform")
          .width(300)
          .onClick(() => {
            this.myNodeController.getPositionToParentWithTransform();
          })
        Button("getPositionToWindowWithTransform")
          .width(300)
          .onClick(() => {
            this.myNodeController.getPositionToWindowWithTransform();
          })
        Button("getPositionToScreenWithTransform")
          .width(300)
          .onClick(() => {
            this.myNodeController.getPositionToScreenWithTransform();
          })
        Button("getMeasuredSize")
          .width(300)
          .onClick(() => {
            this.myNodeController.getMeasuredSize();
          })
        Button("getLayoutPosition")
          .width(300)
          .onClick(() => {
            this.myNodeController.getLayoutPosition();
          })
        Button("getUserConfigBorderWidth")
          .width(300)
          .onClick(() => {
            this.myNodeController.getUserConfigBorderWidth();
          })
        Button("getUserConfigPadding")
          .width(300)
          .onClick(() => {
            this.myNodeController.getUserConfigPadding();
          })
        Button("getUserConfigMargin")
          .width(300)
          .onClick(() => {
            this.myNodeController.getUserConfigMargin();
          })
        Button("getUserConfigSize")
          .width(300)
          .onClick(() => {
            this.myNodeController.getUserConfigSize();
          })
        Button("getId")
          .width(300)
          .onClick(() => {
            this.myNodeController.getId();
          })
        Button("getUniqueId")
          .width(300)
          .onClick(() => {
            this.myNodeController.getUniqueId();
          })
        Button("getNodeType")
          .width(300)
          .onClick(() => {
            this.myNodeController.getNodeType();
          })
        Button("getOpacity")
          .width(300)
          .onClick(() => {
            this.myNodeController.getOpacity();
          })
        Button("isVisible")
          .width(300)
          .onClick(() => {
            this.myNodeController.isVisible();
          })
        Button("isClipToFrame")
          .width(300)
          .onClick(() => {
            this.myNodeController.isClipToFrame();
          })
        Button("isAttached")
          .width(300)
          .onClick(() => {
            this.myNodeController.isAttached();
          })
        Button("getInspectorInfo")
          .width(300)
          .onClick(() => {
            this.myNodeController.getInspectorInfo();
          })
        Button("getCustomProperty")
          .width(300)
          .onClick(() => {
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
        Button("setCrossLanguageOptions")
          .width(300)
          .onClick(() => {
            this.myNodeController.setCrossLanguageOptions();
          })
        Button("throwError")
          .width(300)
          .onClick(() => {
            this.myNodeController.throwError();
          })
      }
      .width("100%")
    }
    .scrollable(ScrollDirection.Vertical) // The scrollbar scrolls in the vertical direction.
  }
}
```

## Example of Node Operations in the LazyForEach Scenario

```ts
import { NodeController, FrameNode, UIContext, BuilderNode, ExpandMode, LengthUnit } from '@kit.ArkUI';

const TEST_TAG: string = "FrameNode "

// BasicDataSource implements the IDataSource API to manage listeners and notify LazyForEach of data updates.
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
      // Method 2: listener.onDatasetChange([{type: DataOperationType.ADD, index: index}]);
    })
  }

  // Notify LazyForEach that the data item with the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
      // Method 2: listener.onDatasetChange([{type: DataOperationType.CHANGE, index: index}]);
    })
  }

  // Notify LazyForEach that the child component that matches the specified index needs to be deleted.
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
      // Method 2: listener.onDatasetChange([{type: DataOperationType.DELETE, index: index}]);
    })
  }

  // Notify LazyForEach that data needs to be swapped between the from and to positions.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
      // Method 2: listener.onDatasetChange ()
      //         [{type: DataOperationType.EXCHANGE, index: {start: from, end: to}}]);
    })
  }

  notifyDatasetChange(operations: DataOperation[]): void {
    this.listeners.forEach(listener => {
      listener.onDatasetChange(operations);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = []

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

class Params {
  data: MyDataSource | null = null;
  scroller: Scroller | null = null;
  constructor(data: MyDataSource, scroller: Scroller) {
    this.data = data;
    this.scroller = scroller;
  }
}

@Builder
function buildData(params: Params) {
  List({ scroller: params.scroller }) {
    LazyForEach(params.data, (item: string) => {
      ListItem() {
        Column() {
          Text(item)
            .fontSize(20)
            .onAppear(() => {
              console.log(TEST_TAG + " node appear: " + item)
            })
            .backgroundColor(Color.Pink)
            .margin({
              top: 30,
              bottom: 30,
              left: 10,
              right: 10
            })
        }
      }
      .id(item)
    }, (item: string) => item)
  }
  .cachedCount(5)
  .listDirection(Axis.Horizontal)
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;
  private data: MyDataSource = new MyDataSource();
  private scroller: Scroller = new Scroller();

  makeNode(uiContext: UIContext): FrameNode | null {
    this.uiContext = uiContext;
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`N${i}`);
    }
    const params: Params = new Params(this.data, this.scroller);
    const dataNode: BuilderNode<[Params]> = new BuilderNode(uiContext);
    dataNode.build(wrapBuilder<[Params]>(buildData), params);
    this.rootNode = dataNode.getFrameNode();
    const scrollToIndexOptions: ScrollToIndexOptions = {
      extraOffset: {
        value: 20, unit: LengthUnit.VP
      }
    };
    this.scroller.scrollToIndex(6, true, ScrollAlign.START, scrollToIndexOptions);
    return this.rootNode;
  }

  getFirstChildIndexWithoutExpand() {
    console.log(`${TEST_TAG} getFirstChildIndexWithoutExpand: ${this.rootNode!.getFirstChildIndexWithoutExpand()}`);
  }

  getLastChildIndexWithoutExpand() {
    console.log(`${TEST_TAG} getLastChildIndexWithoutExpand: ${this.rootNode!.getLastChildIndexWithoutExpand()}`);
  }

  getChildWithNotExpand() {
    const childNode = this.rootNode!.getChild(3, ExpandMode.NOT_EXPAND);
    console.log(TEST_TAG + " getChild(3, ExpandMode.NOT_EXPAND): " + childNode!.getId());
    if (childNode!.getId() === "N9") {
      console.log(TEST_TAG + " getChild(3, ExpandMode.NOT_EXPAND)  result: success.");
    } else {
      console.log(TEST_TAG + " getChild(3, ExpandMode.NOT_EXPAND)  result: fail.");
    }
  }

  getChildWithExpand() {
    const childNode = this.rootNode!.getChild(3, ExpandMode.EXPAND);
    console.log(TEST_TAG + " getChild(3, ExpandMode.EXPAND): " + childNode!.getId());
    if (childNode!.getId() === "N3") {
      console.log(TEST_TAG + " getChild(3, ExpandMode.EXPAND)  result: success.");
    } else {
      console.log(TEST_TAG + " getChild(3, ExpandMode.EXPAND)  result: fail.");
    }
  }
  
  getChildWithLazyExpand() {
    const childNode = this.rootNode!.getChild(3, ExpandMode.LAZY_EXPAND);
    console.log(TEST_TAG + " getChild(3, ExpandMode.LAZY_EXPAND): " + childNode!.getId());
    if (childNode!.getId() === "N3") {
      console.log(TEST_TAG + " getChild(3, ExpandMode.LAZY_EXPAND)  result: success.");
    } else {
      console.log(TEST_TAG + " getChild(3, ExpandMode.LAZY_EXPAND)  result: fail.");
    }
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();
  private scroller: Scroller = new Scroller();

  build() {
    Scroll(this.scroller) {
      Column({ space: 8 }) {
        Column() {
          Text("This is a NodeContainer.")
            .textAlign(TextAlign.Center)
            .borderRadius(10)
            .backgroundColor(0xFFFFFF)
            .width('100%')
            .fontSize(16)
          NodeContainer(this.myNodeController)
            .borderWidth(1)
            .width(300)
            .height(100)
        }

        Button("getFirstChildIndexWithoutExpand")
          .width(300)
          .onClick(() => {
            this.myNodeController.getFirstChildIndexWithoutExpand();
          })
        Button("getLastChildIndexWithoutExpand")
          .width(300)
          .onClick(() => {
            this.myNodeController.getLastChildIndexWithoutExpand();
          })
        Button("getChildWithNotExpand")
          .width(300)
          .onClick(() => {
            this.myNodeController.getChildWithNotExpand();
          })
        Button("getChildWithExpand")
          .width(300)
          .onClick(() => {
            this.myNodeController.getChildWithExpand();
          })
        Button("getChildWithLazyExpand")
          .width(300)
          .onClick(() => {
            this.myNodeController.getChildWithLazyExpand();
          })
      }
      .width("100%")
    }
    .scrollable(ScrollDirection.Vertical) // The scrollbar scrolls in the vertical direction.
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

<!--code_no_check-->

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

<!--code_no_check-->

```ts
// ./track.ets
import { FrameNode, Rect } from '@kit.ArkUI';

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
## Gesture Event Example
```ts
import { NodeController, FrameNode } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  public rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.rootNode.commonAttribute.width(100)
      .overlay('This is a FrameNode')
      .backgroundColor(Color.Pink)
      .width('100%')
      .height('100%');
    this.addGestureEvent(this.rootNode);
    return this.rootNode;
  }

  addGestureEvent(frameNode: FrameNode) {
    frameNode.gestureEvent.addGesture(new PanGestureHandler()
        .onActionStart((event: GestureEvent) => {
            console.log(`Pan start: ${JSON.stringify(event)}`);
        })
        .onActionUpdate((event: GestureEvent) => {
            console.log(`Pan update: ${JSON.stringify(event)}`);
        })
        .onActionEnd((event: GestureEvent) => {
            console.log(`Pan end: ${JSON.stringify(event)}`);
        })
        .onActionCancel(() => {
            console.log('Pan cancel');
        })
    )
    frameNode.gestureEvent.addGesture(new LongPressGestureHandler()
        .onAction((event: GestureEvent) => {
            console.log(`Long press action: ${JSON.stringify(event)}`);
        })
        .onActionEnd((event: GestureEvent) => {
            console.log(`Long press action end: ${JSON.stringify(event)}`);
        })
        .onActionCancel(() => {
            console.log('Long press cancel');
        })
    )
    frameNode.gestureEvent.addGesture(new TapGestureHandler()
        .onAction((event: GestureEvent) => {
            console.log(`Tap action: ${JSON.stringify(event)}`);
        })
    )
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
        .borderWidth(1)
        .width(300)
        .height(300)
    }.width("100%")
  }
}
```
## Example of Customizing a Node

```ts
import { UIContext, DrawContext, FrameNode, NodeController, LayoutConstraint, Size, Position } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

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
## NodeAdapter Usage Example

```ts
import { FrameNode, NodeController, NodeAdapter, typeNode } from '@kit.ArkUI';

class MyNodeAdapter extends NodeAdapter {
  uiContext: UIContext
  cachePool: Array<FrameNode> = new Array();
  changed: boolean = false
  reloadTimes: number = 0;
  data: Array<string> = new Array();
  hostNode?: FrameNode

  constructor(uiContext: UIContext, count: number) {
    super();
    this.uiContext = uiContext;
    this.totalNodeCount = count;
    this.loadData();
  }

  reloadData(count: number): void {
    this.reloadTimes++;
    NodeAdapter.attachNodeAdapter(this, this.hostNode);
    this.totalNodeCount = count;
    this.loadData();
    this.reloadAllItems();
  }

  refreshData(): void {
    let items = this.getAllAvailableItems()
    console.log("UINodeAdapter get All items:" + items.length);
    this.reloadAllItems();
  }

  detachData(): void {
    NodeAdapter.detachNodeAdapter(this.hostNode);
    this.reloadTimes = 0;
  }

  loadData(): void {
    for (let i = 0; i < this.totalNodeCount; i++) {
      this.data[i] = "Adapter ListItem " + i + " r:" + this.reloadTimes;
    }
  }

  changeData(from: number, count: number): void {
    this.changed = !this.changed;
    for (let i = 0; i < count; i++) {
      let index = i + from;
      this.data[index] = "Adapter ListItem " + (this.changed ? "changed:" : "") + index + " r:" + this.reloadTimes;
    }
    this.reloadItem(from, count);
  }

  insertData(from: number, count: number): void {
    for (let i = 0; i < count; i++) {
      let index = i + from;
      this.data.splice(index, 0, "Adapter ListItem " + from + "-" + i);
    }
    this.insertItem(from, count);
    this.totalNodeCount += count;
    console.log("UINodeAdapter after insert count:" + this.totalNodeCount);
  }

  removeData(from: number, count: number): void {
    let arr = this.data.splice(from, count);
    this.removeItem(from, count);
    this.totalNodeCount -= arr.length;
    console.log("UINodeAdapter after remove count:" + this.totalNodeCount);
  }

  moveData(from: number, to: number): void {
    let tmp = this.data.splice(from, 1);
    this.data.splice(to, 0, tmp[0]);
    this.moveItem(from, to);
  }

  onAttachToNode(target: FrameNode): void {
    console.log("UINodeAdapter onAttachToNode id:" + target.getUniqueId());
    this.hostNode = target;
  }

  onDetachFromNode(): void {
    console.log("UINodeAdapter onDetachFromNode");
  }

  onGetChildId(index: number): number {
    console.log("UINodeAdapter onGetChildId:" + index);
    return index;
  }

  onCreateChild(index: number): FrameNode {
    console.log("UINodeAdapter onCreateChild:" + index);
    if (this.cachePool.length > 0) {
      let cacheNode = this.cachePool.pop();
      if (cacheNode !== undefined) {
        console.log("UINodeAdapter onCreateChild reused id:" + cacheNode.getUniqueId());
        let text = cacheNode?.getFirstChild();
        let textNode = text as typeNode.Text;
        textNode?.initialize(this.data[index]).fontSize(20);
        return cacheNode;
      }
    }
    console.log("UINodeAdapter onCreateChild createNew");
    let itemNode = typeNode.createNode(this.uiContext, "ListItem");
    let textNode = typeNode.createNode(this.uiContext, "Text");
    textNode.initialize(this.data[index]).fontSize(20);
    itemNode.appendChild(textNode);
    return itemNode;
  }

  onDisposeChild(id: number, node: FrameNode): void {
    console.log("UINodeAdapter onDisposeChild:" + id);
    if (this.cachePool.length < 10) {
      if (!this.cachePool.includes(node)) {
        console.log("UINodeAdapter caching node id:" + node.getUniqueId());
        this.cachePool.push(node);
      }
    } else {
      node.dispose();
    }
  }

  onUpdateChild(id: number, node: FrameNode): void {
    let index = id;
    let text = node.getFirstChild();
    let textNode = text as typeNode.Text;
    textNode?.initialize(this.data[index]).fontSize(20);
  }
}

class MyNodeAdapterController extends NodeController {
  rootNode: FrameNode | null = null;
  nodeAdapter: MyNodeAdapter | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    let listNode = typeNode.createNode(uiContext, "List");
    listNode.initialize({ space: 3 }).borderWidth(2).borderColor(Color.Black);
    this.rootNode.appendChild(listNode);
    this.nodeAdapter = new MyNodeAdapter(uiContext, 100);
    NodeAdapter.attachNodeAdapter(this.nodeAdapter, listNode);
    return this.rootNode;
  }
}

@Entry
@Component
struct ListNodeTest {
  adapterController: MyNodeAdapterController = new MyNodeAdapterController();

  build() {
    Column() {
      Text("ListNode Adapter");
      NodeContainer(this.adapterController)
        .width(300).height(300)
        .borderWidth(1).borderColor(Color.Black);
      Row() {
        Button("Reload")
          .onClick(() => {
            this.adapterController.nodeAdapter?.reloadData(50);
          })
        Button("Change")
          .onClick(() => {
            this.adapterController.nodeAdapter?.changeData(5, 10)
          })
        Button("Insert")
          .onClick(() => {
            this.adapterController.nodeAdapter?.insertData(10, 10);
          })
      }

      Row() {
        Button("Remove")
          .onClick(() => {
            this.adapterController.nodeAdapter?.removeData(10, 10);
          })
        Button("Move")
          .onClick(() => {
            this.adapterController.nodeAdapter?.moveData(2, 5);
          })
        Button("Refresh")
          .onClick(() => {
            this.adapterController.nodeAdapter?.refreshData();
          })
        Button("Detach")
          .onClick(() => {
            this.adapterController.nodeAdapter?.detachData();
          })
      }
    }.borderWidth(1)
    .width("100%")
  }
}

```
