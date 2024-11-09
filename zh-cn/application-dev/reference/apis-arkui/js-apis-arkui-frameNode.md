# FrameNode

FrameNode表示组件树的实体节点。[NodeController](./js-apis-arkui-nodeController.md#nodecontroller)可通过[BuilderNode](./js-apis-arkui-builderNode.md#buildernode)持有的FrameNode将其挂载到[NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer)上，也可通过FrameNode获取[RenderNode](./js-apis-arkui-renderNode.md#rendernode)，挂载到其他FrameNode上。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 当前不支持在预览器中使用FrameNode节点。
>
> FrameNode节点暂不支持拖拽。

## 导入模块

```ts
import { FrameNode, LayoutConstraint, typeNode, NodeAdapter } from "@kit.ArkUI";
```

## FrameNode

### constructor

constructor(uiContext: UIContext)

FrameNode的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                               |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |

### getRenderNode

getRenderNode(): RenderNode | null

获取FrameNode中持有的RenderNode。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                                                             |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [RenderNode](./js-apis-arkui-renderNode.md#rendernode) \| null | 一个RenderNode对象。若该FrameNode不包含RenderNode，则返回空对象null。如果当前FrameNode为声明式组件创建的节点，则返回null。 |

**示例：**

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

判断当前节点是否可修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型    | 说明                                                                                                                                  |
| ------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| boolean | 判断当前节点是否可修改。当返回false的时候，当前FrameNode不支持appendChild、insertChildAfter、removeChild、clearChildren的操作。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### appendChild<sup>12+</sup> 

appendChild(node: FrameNode): void

在FrameNode最后一个子节点后添加新的子节点。当前FrameNode如果不可修改，抛出异常信息。[typeNode](#typenode12)在appendChild时会校验子组件类型或个数，不满足抛出异常信息，限制情况请查看[typeNode](#typenode12)描述。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                    | 必填 | 说明                  |
| ------ | ----------------------- | ---- | --------------------- |
| node   | [FrameNode](#framenode) | 是   | 需要添加的FrameNode。<br/>**说明：**<br/> node节点不可以为声明式创建的节点，即不可修改的FrameNode。仅有从BuilderNode中获取的声明式节点可以作为子节点。若子节点不符合规格，则抛出异常信息。<br/> node节点不可以拥有父节点，否则抛出异常信息。|

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### insertChildAfter<sup>12+</sup> 

insertChildAfter(child: FrameNode, sibling: FrameNode | null): void

在FrameNode指定子节点之后添加新的子节点。当前FrameNode如果不可修改，抛出异常信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                                         |
| ------- | ----------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| child   | [FrameNode](#framenode)                   | 是   | 需要添加的子节点。<br/>**说明：**<br/> child节点不可以为声明式创建的节点，即不可修改的FrameNode。仅有从BuilderNode中获取的声明式节点可以作为子节点。若子节点不符合规格，则抛出异常信息。<br/> child节点不可以拥有父节点，否则抛出异常信息。                                                           |
| sibling | [FrameNode](#framenode)&nbsp;\|&nbsp;null | 是   | 新节点将插入到该节点之后。若该参数设置为空，则新节点将插入到首个子节点之前。 |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### removeChild<sup>12+</sup> 

removeChild(node: FrameNode): void

从FrameNode中删除指定的子节点。当前FrameNode如果不可修改，抛出异常信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                    | 必填 | 说明               |
| ------ | ----------------------- | ---- | ------------------ |
| node   | [FrameNode](#framenode) | 是   | 需要删除的子节点。 |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### clearChildren<sup>12+</sup> 

clearChildren(): void

清除当前FrameNode的所有子节点。当前FrameNode如果不可修改，抛出异常信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 100021   | The FrameNode is not modifiable. |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getChild<sup>12+</sup> 

getChild(index: number): FrameNode | null

获取当前节点指定位置的子节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| index  | number | 是   | 需要查询的子节点的序列号。 |

**返回值：**

| 类型                            | 说明                                                          |
| ------------------------------- | ------------------------------------------------------------- |
| [FrameNode](#framenode) \| null | 子节点。若该FrameNode不包含所查询的子节点，则返回空对象null。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。
### getFirstChild<sup>12+</sup> 

getFirstChild(): FrameNode | null

获取当前FrameNode的第一个子节点

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                            | 说明                                                      |
| ------------------------------- | --------------------------------------------------------- |
| [FrameNode](#framenode) \| null | 首个子节点。若该FrameNode不包含子节点，则返回空对象null。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getNextSibling<sup>12+</sup> 

getNextSibling(): FrameNode | null

获取当前FrameNode的下一个同级节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                            | 说明                                                                                 |
| ------------------------------- | ------------------------------------------------------------------------------------ |
| [FrameNode](#framenode) \| null | 当前FrameNode的下一个同级节点。若该FrameNode不包含下一个同级节点，则返回空对象null。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getPreviousSibling<sup>12+</sup> 

getPreviousSibling(): FrameNode | null

获取当前FrameNode的上一个同级节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                             | 说明                                                                                 |
| -------------------------------- | ------------------------------------------------------------------------------------ |
| [FrameNode](#framenode) \| null | 当前FrameNode的上一个同级节点。若该FrameNode不包含上一个同级节点，则返回空对象null。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getParent<sup>12+</sup> 

getParent(): FrameNode | null;

获取当前FrameNode的父节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                             | 说明                                                                 |
| -------------------------------- | -------------------------------------------------------------------- |
| [FrameNode](#framenode) \| null | 当前FrameNode的父节点。若该FrameNode不包含父节点，则返回空对象null。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。


### getChildrenCount<sup>12+</sup> 

  getChildrenCount(): number;

获取当前FrameNode的子节点数量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                            |
| -------- | ------------------------------- |
| number | 获取当前FrameNode的子节点数量。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getPositionToWindow<sup>12+</sup> 

  getPositionToWindow(): Position

获取FrameNode相对于窗口的位置偏移，单位为VP。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                            |
| -------- | ------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | 节点相对于窗口的位置偏移，单位为VP。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。


### getPositionToParent<sup>12+</sup>

getPositionToParent(): Position

获取FrameNode相对于父组件的位置偏移，单位为VP。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | 节点相对于父组件的位置偏移，单位为VP。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getPositionToScreen<sup>12+</sup> 

  getPositionToScreen(): Position

获取FrameNode相对于屏幕的位置偏移，单位为VP。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                            |
| -------- | ------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | 节点相对于屏幕的位置偏移，单位为VP。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。


### getPositionToParentWithTransform<sup>12+</sup>

getPositionToParentWithTransform(): Position

获取FrameNode相对于父组件带有绘制属性的位置偏移，单位为VP，绘制属性比如transform, translate等，返回的坐标是组件布局时左上角变换后的坐标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | 节点相对于父组件的位置偏移，单位为VP。 当设置了其他（比如：transform, translate等）绘制属性，由于浮点数精度的影响，返回值会有微小偏差。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getPositionToWindowWithTransform<sup>12+</sup>

getPositionToWindowWithTransform(): Position

获取FrameNode相对于窗口带有绘制属性的位置偏移，单位为VP，绘制属性比如transform, translate等，返回的坐标是组件布局时左上角变换后的坐标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | 节点相对于窗口的位置偏移，单位为VP。 当设置了其他（比如：transform, translate等）绘制属性，由于浮点数精度的影响，返回值会有微小偏差。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getPositionToScreenWithTransform<sup>12+</sup>

getPositionToScreenWithTransform(): Position

获取FrameNode相对于屏幕带有绘制属性的位置偏移，单位为VP，绘制属性比如transform, translate等，返回的坐标是组件布局时左上角变换后的坐标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | 节点相对于屏幕的位置偏移，单位为VP。 当设置了其他（比如：transform, translate等）绘制属性，由于浮点数精度的影响，返回值会有微小偏差。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。


### getMeasuredSize<sup>12+</sup>

getMeasuredSize(): Size

获取FrameNode测量后的大小，单位为PX。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Size](./js-apis-arkui-graphics.md#size) | 节点测量后的大小，单位为PX。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。


### getLayoutPosition<sup>12+</sup>

getLayoutPosition(): Position

获取FrameNode布局后相对于父组件的位置偏移，单位为PX。该偏移是父容器对该节点进行布局之后的结果，因此布局之后生效的offset属性和不参与布局的position属性不影响该偏移值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Position](./js-apis-arkui-graphics.md#position) | 节点布局后相对于父组件的位置偏移，单位为PX。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getUserConfigBorderWidth<sup>12+</sup>

getUserConfigBorderWidth(): Edges\<LengthMetrics\>

获取用户设置的边框宽度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | 用户设置的边框宽度。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getUserConfigPadding<sup>12+</sup>

getUserConfigPadding(): Edges\<LengthMetrics\>

获取用户设置的内边距。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | 用户设置的内边距。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getUserConfigMargin<sup>12+</sup>

getUserConfigMargin(): Edges\<LengthMetrics\>

获取用户设置的外边距。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [Edges](./js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | 用户设置的外边距。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getUserConfigSize<sup>12+</sup>

getUserConfigSize(): SizeT\<LengthMetrics\>

获取用户设置的宽高。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                         | 说明             |
| ------------------------------------------------------------ | ---------------- |
| [SizeT](./js-apis-arkui-graphics.md#sizett12)\<[LengthMetrics](./js-apis-arkui-graphics.md#lengthmetrics12)\> | 用户设置的宽高。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getId<sup>12+</sup>

getId(): string

获取用户设置的节点ID（通用属性设置的[ID](./arkui-ts/ts-universal-attributes-component-id.md)）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| string | 用户设置的节点ID（通用属性设置的[ID](./arkui-ts/ts-universal-attributes-component-id.md)）。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getUniqueId<sup>12+</sup>

getUniqueId(): number

获取系统分配的唯一标识的节点UniqueID。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| number | 系统分配的唯一标识的节点UniqueID。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getNodeType<sup>12+</sup>

getNodeType(): string

获取节点的类型。内置组件类型为组件名称，例如，按钮组件Button的类型为Button。而对于自定义组件，若其有渲染内容，则其类型为__Common__。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| string | 节点的类型。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getOpacity<sup>12+</sup>

getOpacity(): number

获取节点的不透明度，最小值为0，最大值为1。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| number | 节点的不透明度。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### isVisible<sup>12+</sup>

isVisible(): boolean

获取节点是否可见。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | 节点是否可见。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### isClipToFrame<sup>12+</sup>

isClipToFrame(): boolean

获取节点是否是剪裁到组件区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | 节点是否是剪裁到组件区域。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### isAttached<sup>12+</sup>

isAttached(): boolean

获取节点是否被挂载到主节点树上。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| boolean | 节点是否被挂载到主节点树上。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getInspectorInfo<sup>12+</sup>

getInspectorInfo(): Object

获取节点的结构信息，该信息和DevEco Studio内置ArkUI Inspector工具里面的一致。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| Object | 节点的结构信息。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### getCustomProperty<sup>12+</sup>

getCustomProperty(name: string): Object | undefined

通过名称获取组件的自定义属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                                         |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name  | string | 是   | 自定义属性的名称。 |

**返回值：**

| 类型                                                           | 说明                                                                  |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| Object \| undefined | 自定义属性的值。 |

**示例：**

请参考[节点操作示例](#节点操作示例)。

### dispose<sup>12+</sup>

dispose(): void

立即解除当前FrameNode对象对实体FrameNode节点的引用关系。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

> **说明：**
>
> FrameNode对象调用dispose后，由于不对应任何实体FrameNode节点，在调用部分查询接口(getPositionToParent、getPositionToScreen、getPositionToWindow、getPositionToParentWithTransform、getPositionToScreenWithTransform、getPositionToWindowWithTransform、getMeasuredSize、getLayoutPosition、getUserConfigBorderWidth、getUserConfigPadding、getUserConfigMargin、getUserConfigSize)的时候会导致应用出现jscrash。
>
> 通过[getUniqueId](#getuniqueid12)可以判断当前FrameNode是否对应一个实体FrameNode节点。当UniqueId大于0时表示该对象对应一个实体FrameNode节点。

**示例：**

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

获取FrameNode中持有的CommonAttribute接口，用于设置通用属性。

仅可以修改自定义节点的属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                                                             |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| CommonAttribute | 获取FrameNode中持有的CommonAttribute接口，用于设置通用属性。|

> **说明：**
>
> FrameNode的效果参考对齐方式为顶部起始端的[Stack](./arkui-ts/ts-container-stack.md)容器组件。
>
> FrameNode的属性支持范围参考[CommonModifier](./arkui-ts/ts-universal-attributes-attribute-modifier.md#自定义modifier)。

**示例：**

请参考[基础事件示例](#基础事件示例)。

### commonEvent<sup>12+</sup>

get commonEvent(): UICommonEvent

获取FrameNode中持有的UICommonEvent对象，用于设置基础事件。设置的基础事件与声明式定义的事件平行，参与事件竞争；设置的基础事件不覆盖原有的声明式事件。同时设置两个事件回调的时候，优先回调声明式事件。

LazyForEach场景下，由于存在节点的销毁重建，对于重建的节点需要重新设置事件回调才能保证监听事件正常响应。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                           | 说明                                                                                                             |
| -------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [UICommonEvent](./arkui-ts/ts-uicommonevent.md#设置事件回调) | UICommonEvent对象，用于设置基础事件。 |

**示例：**

请参考[基础事件示例](#基础事件示例)和[LazyForEach场景基础事件使用示例](#lazyforeach场景基础事件使用示例)。

### onDraw<sup>12+</sup>

onDraw?(context: DrawContext): void

FrameNode的自绘制方法，该方法会在FrameNode进行内容绘制时被调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| context | [DrawContext](./js-apis-arkui-graphics.md#drawcontext) | 是   | 图形绘制上下文。自绘制区域无法超出组件自身大小。 |

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### onMeasure<sup>12+</sup>

onMeasure(constraint: LayoutConstraint): void

FrameNode的自定义测量方法，该方法会重写默认测量方法，在FrameNode进行测量时被调用，测量FrameNode及其内容的大小。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| constraint | [LayoutConstraint](#layoutconstraint12) | 是   | 组件进行测量时使用的布局约束。 |

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### LayoutConstraint<sup>12+</sup>

描述组件的布局约束。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            |  类型  | 必填  | 说明                                       |
| -------------- | ------ | ----- | ------------------------------------------ |
| maxSize           | [Size](./js-apis-arkui-graphics.md#size) | 是    | 最大尺寸。              |
| minSize            | [Size](./js-apis-arkui-graphics.md#size) | 是    | 最小尺寸。                  |
| percentReference      | [Size](./js-apis-arkui-graphics.md#size) | 是    | 子节点计算百分比时的尺寸基准。

### onLayout<sup>12+</sup>

onLayout(position: Position): void

FrameNode的自定义布局方法，该方法会重写默认布局方法，在FrameNode进行布局时被调用，为FrameNode及其子节点指定位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | 是   | 组件进行布局时使用的位置信息。 |

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### setMeasuredSize<sup>12+</sup>

setMeasuredSize(size: Size): void

设置FrameNode的测量后的尺寸，默认单位PX。若设置的宽高为负数，自动取零。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| size | [Size](./js-apis-arkui-graphics.md#size) | 是   | FrameNode的测量后的尺寸。 |

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### setLayoutPosition<sup>12+</sup>

setLayoutPosition(position: Position): void

设置FrameNode的布局后的位置，默认单位PX。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | 是   | FrameNode的布局后的位置。 |

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### measure<sup>12+</sup>

measure(constraint: LayoutConstraint): void

调用FrameNode的测量方法，根据父容器的布局约束，对FrameNode进行测量，计算出尺寸，如果测量方法被重写，则调用重写的方法。建议在[onMeasure](#onmeasure12)方法中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| constraint | [LayoutConstraint](#layoutconstraint12) | 是   | 组件进行测量时使用的父容器布局约束。 |

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### layout<sup>12+</sup>

layout(position: Position): void

调用FrameNode的布局方法，为FrameNode及其子节点指定布局位置，如果布局方法被重写，则调用重写的方法。建议在[onLayout](#onlayout12)方法中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| position | [Position](./js-apis-arkui-graphics.md#position) | 是   | 组件进行布局时使用的位置信息。 |

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### setNeedsLayout<sup>12+</sup>

setNeedsLayout(): void

该方法会将FrameNode标记为需要布局的状态，下一帧将会进行重新布局。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

### invalidate<sup>12+</sup>

invalidate(): void

该方法会触发FrameNode自绘制内容的重新渲染。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### addComponentContent<sup>12+</sup>

addComponentContent\<T>(content: ComponentContent\<T>): void

支持添加ComponentContent类型的组件内容。要求当前节点是一个可修改的节点，即[isModifiable](#ismodifiable12)的返回值为true，否则抛出异常信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| content | [ComponentContent](./js-apis-arkui-ComponentContent.md#componentcontent)\<T> | 是   | FrameNode节点中显示的组件内容。 |

**错误码：**

| 错误码ID | 错误信息                         |
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

下树并递归释放当前节点为根的子树。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

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

**示例：**

请参考[节点自定义示例](#节点自定义示例)。

## TypedFrameNode<sup>12+</sup>

TypedFrameNode继承自[FrameNode](#framenode)，用于声明具体类型的FrameNode。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型 | 只读 | 可选 | 说明                                                         |
| ---------- | ---- | ---- | ---- | ------------------------------------------------------------ |
| initialize | C    | 否   | 否   | 该接口用于创建对应组件的构造参数，用于设置/更新组件的初始值。 |
| attribute  | T    | 否   | 否   | 该接口用于获取对应组件的属性设置对象，用于设置/更新组件的通用、私有属性。 |

## typeNode<sup>12+</sup>

typeNode提供创建具体类型的FrameNode能力，可通过FrameNode的基础接口进行自定义的挂载，使用占位容器进行显示。

使用typeNode创建Text、Image、Select、Toggle节点时，当传入的[UIContext](./js-apis-arkui-UIContext.md)对应的UI实例销毁后，调用该接口会返回一个无效的FrameNode节点，无法正常挂载和显示。

**示例：**

请参考[自定义具体类型节点示例](#自定义具体类型节点示例)。

### Text<sup>12+</sup>
type Text = TypedFrameNode&lt;TextInterface, TextAttribute&gt;

Text类型的FrameNode节点类型。不允许添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                               | 说明                                                         |
| -------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;TextInterface, TextAttribute&gt; | 提供Text类型FrameNode节点。<br/>**说明：**<br/> TextInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Text组件的构造函数类型。 <br/> TextAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Text组件的属性设置对象。 |

### createNode('Text')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Text'): Text

创建Text类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Text' | 是 | 创建Text类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Text](#text12) | Text类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Text');
```

### Column<sup>12+</sup>
type Column = TypedFrameNode&lt;ColumnInterface, ColumnAttribute&gt;

Column类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                   | 说明                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ColumnInterface, ColumnAttribute&gt; | 提供Column类型FrameNode节点。<br/>**说明：**<br/> ColumnInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Column组件的构造函数类型。 <br/> ColumnAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Column组件的属性设置对象。 |

### createNode('Column')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Column'): Column

创建Column类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Column' | 是 | 创建Column类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Column](#column12) | Column类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Column');
```
### Row<sup>12+</sup>
type Row = TypedFrameNode&lt;RowInterface, RowAttribute&gt;

Row类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                             | 说明                                                         |
| ------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;RowInterface, RowAttribute&gt; | 提供Row类型FrameNode节点。<br/>**说明：**<br/> RowInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Row组件的构造函数类型。 <br/> RowAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Row组件的属性设置对象。 |

### createNode('Row')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Row'): Row

创建Row类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Row' | 是 | 创建Row类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Row](#row12) | Row类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Row');
```
### Stack<sup>12+</sup>
type Stack = TypedFrameNode&lt;StackInterface, StackAttribute&gt;

Stack类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                 | 说明                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;StackInterface, StackAttribute&gt; | 提供Stack类型FrameNode节点。<br/>**说明：**<br/> StackInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Stack组件的构造函数类型。 <br/> StackAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Stack组件的属性设置对象。 |

### createNode('Stack')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Stack'): Stack

创建Stack类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Stack' | 是 | 创建Stack类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Stack](#stack12) | Stack类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Stack');
```
### GridRow<sup>12+</sup>
type GridRow = TypedFrameNode&lt;GridRowInterface, GridRowAttribute&gt;

GridRow类型的FrameNode节点类型。只允许添加GridCol类型子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                     | 说明                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;GridRowInterface, GridRowAttribute&gt; | 提供GridRow类型FrameNode节点。<br/>**说明：**<br/> GridRowInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为GridRow组件的构造函数类型。 <br/> GridRowAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回GridRow组件的属性设置对象。 |

### createNode('GridRow')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'GridRow'): GridRow

创建GridRow类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'GridRow' | 是 | 创建GridRow类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [GridRow](#gridrow12) | GridRow类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'GridRow');
```
### GridCol<sup>12+</sup>
type GridCol = TypedFrameNode&lt;GridColInterface, GridColAttribute&gt;

GridCol类型的FrameNode节点类型。不允许添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                     | 说明                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;GridColInterface, GridColAttribute&gt; | 提供GridCol类型FrameNode节点。<br/>**说明：**<br/> GridColInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为GridCol组件的构造函数类型。 <br/> GridColAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回GridCol组件的属性设置对象。 |

### createNode('GridCol')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'GridCol'): GridCol

创建GridCol类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'GridCol' | 是 | 创建GridCol类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [GridCol](#gridcol12) | GridCol类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'GridCol');
```
### Flex<sup>12+</sup>
type Flex = TypedFrameNode&lt;FlexInterface, FlexAttribute&gt;

Flex类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                               | 说明                                                         |
| -------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;FlexInterface, FlexAttribute&gt; | 提供Flex类型FrameNode节点。<br/>**说明：**<br/> FlexInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Flex组件的构造函数类型。 <br/> FlexAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Flex组件的属性设置对象。 |

### createNode('Flex')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Flex'): Flex

创建Flex类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Flex' | 是 | 创建Flex类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Flex](#flex12) | Flex类型的FrameNode节点。 |

**示例： **

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Flex');
```
### Swiper<sup>12+</sup>
type Swiper = TypedFrameNode&lt;SwiperInterface, SwiperAttribute&gt;

Swiper类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                   | 说明                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;SwiperInterface, SwiperAttribute&gt; | 提供Swiper类型FrameNode节点。<br/>**说明：**<br/> SwiperInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Swiper组件的构造函数类型。 <br/> SwiperAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Swiper组件的属性设置对象。 |

### createNode('Swiper')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Swiper'): Swiper

创建Swiper类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Swiper' | 是 | 创建Swiper类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Swiper](#swiper12) | Swiper类型的FrameNode节点。 |

**示例： ** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Swiper');
```
### Progress<sup>12+</sup>
type Progress = TypedFrameNode&lt;ProgressInterface, ProgressAttribute&gt;

Progress类型的FrameNode节点类型。不允许添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                       | 说明                                                         |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ProgressInterface, ProgressAttribute&gt; | 提供Progress类型FrameNode节点。<br/>**说明：**<br/> ProgressInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Progress组件的构造函数类型。 <br/> ProgressAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Progress组件的属性设置对象。 |

### createNode('Progress')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Progress'): Progress

创建Progress类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Progress' | 是 | 创建Progress类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Progress](#progress12) | Progress类型的FrameNode节点。 |

**示例：**

```ts
typeNode.createNode(uiContext, 'Progress');
```
### Scroll<sup>12+</sup>
type Scroll = TypedFrameNode&lt;ScrollInterface, ScrollAttribute&gt;

Scroll类型的FrameNode节点类型。允许添加一个子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                   | 说明                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ScrollInterface, ScrollAttribute&gt; | 提供Scroll类型FrameNode节点。<br/>**说明：**<br/> ScrollInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Scroll组件的构造函数类型。 <br/> ScrollAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Scroll组件的属性设置对象。 |

### createNode('Scroll')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Scroll'): Scroll

创建Scroll类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Scroll' | 是 | 创建Scroll类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Scroll](#scroll12) | Scroll类型的FrameNode节点。 |

**示例：**

```ts
typeNode.createNode(uiContext, 'Scroll');
```
### RelativeContainer<sup>12+</sup>
type RelativeContainer = TypedFrameNode&lt;RelativeContainerInterface, RelativeContainerAttribute&gt;

RelativeContainer类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;RelativeContainerInterface, RelativeContainerAttribute&gt; | 提供RelativeContainer类型FrameNode节点。<br/>**说明：**<br/> RelativeContainerInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为RelativeContainer组件的构造函数类型。 <br/> RelativeContainerAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回RelativeContainer组件的属性设置对象。 |

### createNode('RelativeContainer')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'RelativeContainer'): RelativeContainer

创建RelativeContainer类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'RelativeContainer' | 是 | 创建RelativeContainer类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [RelativeContainer](#relativecontainer12) | RelativeContainer类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'RelativeContainer');
```
### Divider<sup>12+</sup>
type Divider = TypedFrameNode&lt;DividerInterface, DividerAttribute&gt;

Divider类型的FrameNode节点类型。不允许添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                     | 说明                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;DividerInterface, DividerAttribute&gt; | 提供Divider类型FrameNode节点。<br/>**说明：**<br/> DividerInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为RelativeContainer组件的构造函数类型。 <br/> DividerAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Divider组件的属性设置对象。 |

### createNode('Divider')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Divider'): Divider

创建Divider类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Divider' | 是 | 创建Divider类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Divider](#divider12) | Divider类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Divider');
```
### LoadingProgress<sup>12+</sup>
type LoadingProgress = TypedFrameNode&lt;LoadingProgressInterface, LoadingProgressAttribute&gt;

LoadingProgress类型的FrameNode节点类型。不允许添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;LoadingProgressInterface, LoadingProgressAttribute&gt; | 提供LoadingProgress类型FrameNode节点。<br/>**说明：**<br/> LoadingProgressInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为LoadingProgress组件的构造函数类型。 <br/> LoadingProgressAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回LoadingProgress组件的属性设置对象。 |

### createNode('LoadingProgress')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'LoadingProgress'): LoadingProgress

创建LoadingProgress类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'LoadingProgress' | 是 | 创建LoadingProgress类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [LoadingProgress](#loadingprogress12) | LoadingProgress类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'LoadingProgress');
```
### Search<sup>12+</sup>
type Search = TypedFrameNode&lt;SearchInterface, SearchAttribute&gt;

Search类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                   | 说明                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;SearchInterface, SearchAttribute&gt; | 提供Search类型FrameNode节点。<br/>**说明：**<br/> SearchInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Search组件的构造函数类型。 <br/> SearchAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Search组件的属性设置对象。 |

### createNode('Search')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Search'): Search

创建Search类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Search' | 是 | 创建Search类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Search](#search12) | Search类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Search');
```
### Blank<sup>12+</sup>
type Blank = TypedFrameNode&lt;BlankInterface, BlankAttribute&gt;

Blank类型的FrameNode节点类型。不允许添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                 | 说明                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;BlankInterface, BlankAttribute&gt; | 提供Blank类型FrameNode节点。<br/>**说明：**<br/> BlankInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Blank组件的构造函数类型。 <br/> BlankAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Blank组件的属性设置对象。 |

### createNode('Blank')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Blank'): Blank;

创建Blank类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Blank' | 是 | 创建Blank类型的FrameNode节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Blank](#blank12) | Blank类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Blank');
```
### Image<sup>12+</sup>
type Image = TypedFrameNode&lt;ImageInterface, ImageAttribute&gt;

Image类型的FrameNode节点类型。不允许添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                 | 说明                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ImageInterface, ImageAttribute&gt; | 提供Image类型FrameNode节点。<br/>**说明：**<br/> ImageInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Image组件的构造函数类型。 <br/> ImageAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Image组件的属性设置对象。 |

### createNode('Image')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Image'): Image

创建Image类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Image' | 是 | 创建Image类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Image](#image12) | Image类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Image');
```
### List<sup>12+</sup>
type List = TypedFrameNode&lt;ListInterface, ListAttribute&gt;

List类型的FrameNode节点类型。只允许添加ListItem、ListItemGroup类型子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                               | 说明                                                         |
| -------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ListInterface, ListAttribute&gt; | 提供List类型FrameNode节点。<br/>**说明：**<br/> ListInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为List组件的构造函数类型。 <br/> ListAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回List组件的属性设置对象。 |

### createNode('List')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'List'): List

创建List类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'List' | 是 | 创建List类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [List](#list12) | List类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'List');
```
### ListItem<sup>12+</sup>
type ListItem = TypedFrameNode&lt;ListItemInterface, ListItemAttribute&gt;

ListItem类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                       | 说明                                                         |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;ListItemInterface, ListItemAttribute&gt; | 提供ListItem类型FrameNode节点。<br/>**说明：**<br/> ListItemInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为ListItem组件的构造函数类型。 <br/> ListItemAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回ListItem组件的属性设置对象。 |

### createNode('ListItem')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'ListItem'): ListItem

创建ListItem类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'ListItem' | 是 | 创建ListItem类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [ListItem](#listitem12) | ListItem类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'ListItem');
```

### TextInput<sup>12+</sup>
type TextInput = TypedFrameNode&lt;TextInputInterface, TextInputAttribute&gt;

TextInput类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;TextInputInterface, TextInputAttribute&gt; | 提供TextInput类型FrameNode节点。<br/>**说明：**<br/> TextInputInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为TextInput组件的构造函数类型。 <br/> TextInputAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回TextInput组件的属性设置对象。 |

### createNode('TextInput')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'TextInput'): TextInput

创建TextInput类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'TextInput' | 是 | 创建TextInput类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [TextInput](#textinput12) | TextInput类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextInput');
```

### Button<sup>12+</sup>
type Button = TypedFrameNode&lt;ButtonInterface, ButtonAttribute&gt;

Button类型的FrameNode节点类型。以子组件模式创建允许添加一个子组件。以label模式创建不可以添加子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                                                   | 说明                                                         |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ButtonInterface, ButtonAttribute&gt; | 提供Button类型FrameNode节点。<br/>**说明：**<br/> ButtonInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Button组件的构造函数类型。 <br/> ButtonAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Button组件的属性设置对象。<br/> 接口入参label不为空时，以label模式创建Button组件，以此模式创建无法包含子组件,并且不允许再设置子组件，否则会抛出异常。且label模式和子组件模式在第一次initialize创建之后无法在后续的initialize进行动态修改，如需要包含子组件，第一次initialize时不要设置label参数。<br/> 以子组件模式创建时，只能包含一个子组件，不能设置多个子组件，否则会抛出异常。 |

### createNode('Button')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'Button'): Button

创建Button类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Button' | 是 | 创建Button类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Button](#button12) | Button类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Button');
```

### ListItemGroup<sup>12+</sup>
type ListItemGroup = TypedFrameNode&lt;ListItemGroupInterface, ListItemGroupAttribute&gt;

ListItemGroup类型的FrameNode节点类型。只允许添加ListItem类型子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;ListItemGroupInterface, ListItemGroupAttribute&gt; | 提供ListItemGroup类型FrameNode节点。<br/>**说明：**<br/> ListItemGroupInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为ListItemGroup组件的构造函数类型。 <br/> ListItemGroupAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回ListItemGroup组件的属性设置对象。 |

### createNode('ListItemGroup')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'ListItemGroup'): ListItemGroup

创建ListItemGroup类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'ListItemGroup' | 是 | 创建ListItemGroup类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [ListItemGroup](#listitemgroup12) | ListItemGroup类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'ListItemGroup');
```

### WaterFlow<sup>12+</sup>
type WaterFlow = TypedFrameNode&lt;WaterFlowInterface, WaterFlowAttribute&gt;

WaterFlow类型的FrameNode节点类型。只允许添加FlowItem类型子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;WaterFlowInterface, WaterFlowAttribute&gt; | 提供WaterFlow类型FrameNode节点。<br/>**说明：**<br/> WaterFlowInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为WaterFlow组件的构造函数类型。 <br/> WaterFlowAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回WaterFlow组件的属性设置对象。 |

### createNode('WaterFlow')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'WaterFlow'): WaterFlow

创建WaterFlow类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'WaterFlow' | 是 | 创建WaterFlow类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [WaterFlow](#waterflow12) | WaterFlow类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'WaterFlow');
```

### FlowItem<sup>12+</sup>
type FlowItem = TypedFrameNode&lt;FlowItemInterface, FlowItemAttribute&gt;

FlowItem类型的FrameNode节点类型。允许添加一个子组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                                                       | 说明                                                         |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| TypedFrameNode&lt;FlowItemInterface, FlowItemAttribute&gt; | 提供FlowItem类型FrameNode节点。<br/>**说明：**<br/> FlowItemInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为FlowItem组件的构造函数类型。 <br/> FlowItemAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回FlowItem组件的属性设置对象。 |

### createNode('FlowItem')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'FlowItem'): FlowItem

创建FlowItem类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'FlowItem' | 是 | 创建FlowItem类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [FlowItem](#flowitem12) | FlowItem类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'FlowItem');
```

### XComponent<sup>12+</sup>
type XComponent = TypedFrameNode&lt;XComponentInterface, XComponentAttribute&gt;

XComponent类型的FrameNode节点类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| TypedFrameNode&lt;XComponentInterface, XComponentAttribute&gt; | 提供XComponent类型FrameNode节点。<br/>**说明：**<br/> XComponentInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为XComponent组件的构造函数类型。 <br/> XComponentAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回XComponent组件的属性设置对象。 |

### createNode('XComponent')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'XComponent'): XComponent

创建XComponent类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'XComponent' | 是 | 创建XComponent类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [XComponent](#xcomponent12) | XComponent类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'XComponent');
```

### createNode('XComponent')<sup>12+</sup>
createNode(context: UIContext, nodeType: 'XComponent', options: XComponentOptions): XComponent

按照options中的配置参数创建XComponent类型的FrameNode节点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'XComponent' | 是 | 创建XComponent类型的节点。 |
| options | [XComponentOptions](./arkui-ts/ts-basic-components-xcomponent.md#xcomponentoptions12) | 是 | 定义XComponent的具体配置参数。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [XComponent](#xcomponent12) | XComponent类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
let controller: XComponentController = new XComponentController();
let options: XComponentOptions = {
  type: XComponentType.TEXTURE,
  controller: controller
};
typeNode.createNode(uiContext, 'XComponent', options);
```

### QRCode<sup>13+</sup>
type QRCode = TypedFrameNode&lt;QRCodeInterface, QRCodeAttribute&gt;

QRCode类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;QRCodeInterface, QRCodeAttribute&gt; | 提供QRCode类型FrameNode节点。<br/>**说明：**<br/> QRCodeInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为QRCode组件的构造函数类型。 <br/> QRCodeAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回QRCode组件的属性设置对象。 |

### createNode('QRCode')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'QRCode'): QRCode

创建QRCode类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'QRCode' | 是 | 创建QRCode类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [QRCode](#qrcode13) | QRCode类型的FrameNode节点。 |

**示例：**

```ts
typeNode.createNode(uiContext, 'QRCode');
```

### Badge<sup>13+</sup>
type Badge = TypedFrameNode&lt;BadgeInterface, BadgeAttribute&gt;

Badge类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;BadgeInterface, BadgeAttribute&gt; | 提供Badge类型FrameNode节点。<br/>**说明：**<br/> BadgeInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Badge组件的构造函数类型。 <br/> BadgeAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Badge组件的属性设置对象。 |

### createNode('Badge')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Badge'): Badge

创建Badge类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Badge' | 是 | 创建Badge类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Badge](#badge13) | Badge类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Badge');
```

### Grid<sup>13+</sup>
type Grid = TypedFrameNode&lt;GridInterface, GridAttribute&gt;

Grid类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;GridInterface, GridAttribute&gt; | 提供Grid类型FrameNode节点。<br/>**说明：**<br/> GridInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Grid组件的构造函数类型。 <br/> GridAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Grid组件的属性设置对象。 |

### createNode('Grid')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Grid'): Grid

创建Grid类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Grid' | 是 | 创建Grid类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Grid](#grid13) | Grid类型的FrameNode节点。 |

**示例： ** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Grid');
```

### GridItem<sup>13+</sup>
type GridItem = TypedFrameNode&lt;GridItemInterface, GridItemAttribute&gt;

GridItem类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;GridItemInterface, GridItemAttribute&gt; | 提供GridItem类型FrameNode节点。<br/>**说明：**<br/> GridItemInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为GridItem组件的构造函数类型。 <br/> GridItemAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回GridItem组件的属性设置对象。 |

### createNode('GridItem')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'GridItem'): GridItem

创建GridItem类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'GridItem' | 是 | 创建GridItem类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [GridItem](#griditem13) | GridItem类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'GridItem');
```

### TextClock<sup>13+</sup>
type TextClock = TypedFrameNode&lt;TextClockInterface, TextClockAttribute&gt;

TextClock类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;TextClockInterface, TextClockAttribute&gt; | 提供TextClock类型FrameNode节点。<br/>**说明：**<br/> TextClockInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为TextClock组件的构造函数类型。 <br/> TextClockAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回TextClock组件的属性设置对象。 |

### createNode('TextClock')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'TextClock'): TextClock

创建TextClock类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'TextClock' | 是 | 创建TextClock类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [TextClock](#textclock13) | TextClock类型的FrameNode节点。 |

**示例： ** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextClock');
```

### TextTimer<sup>13+</sup>
type TextTimer = TypedFrameNode&lt;TextTimerInterface, TextTimerAttribute&gt;

TextTimer类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;TextTimerInterface, TextTimerAttribute&gt; | 提供TextTimer类型FrameNode节点。<br/>**说明：**<br/> TextTimerInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为TextTimer组件的构造函数类型。 <br/> TextTimerAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回TextTimer组件的属性设置对象。 |

### createNode('TextTimer')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'TextTimer'): TextTimer

创建TextTimer类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'TextTimer' | 是 | 创建TextTimer类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [TextTimer](#texttimer13) | TextTimer类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextTimer');
```

### Marquee<sup>13+</sup>
type Marquee = TypedFrameNode&lt;MarqueeInterface, MarqueeAttribute&gt;

Marquee类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;MarqueeInterface, MarqueeAttribute&gt; | 提供Marquee类型FrameNode节点。<br/>**说明：**<br/> MarqueeInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Marquee组件的构造函数类型。 <br/> MarqueeAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Marquee组件的属性设置对象。 |

### createNode('Marquee')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Marquee'): Marquee

创建Marquee类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Marquee' | 是 | 创建Marquee类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Marquee](#marquee13) | Marquee类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Marquee');
```

### TextArea<sup>13+</sup>
type TextArea = TypedFrameNode&lt;TextAreaInterface, TextAreaAttribute&gt;

TextArea类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;TextAreaInterface, TextAreaAttribute&gt; | 提供TextArea类型FrameNode节点。<br/>**说明：**<br/> TextAreaInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为TextArea组件的构造函数类型。 <br/> TextAreaAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回TextArea组件的属性设置对象。 |

### createNode('TextArea')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'TextArea'): TextArea

创建TextArea类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'TextArea' | 是 | 创建TextArea类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [TextArea](#textarea13) | TextArea类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'TextArea');
```

### SymbolGlyph<sup>13+</sup>
type SymbolGlyph = TypedFrameNode&lt;SymbolGlyphInterface, SymbolGlyphAttribute&gt;

SymbolGlyph类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SymbolGlyphInterface, SymbolGlyphAttribute&gt; | 提供SymbolGlyph类型FrameNode节点。<br/>**说明：**<br/> SymbolGlyphInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为SymbolGlyph组件的构造函数类型。 <br/> SymbolGlyphAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回SymbolGlyph组件的属性设置对象。 |

### createNode('SymbolGlyph')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'SymbolGlyph'): SymbolGlyph

创建SymbolGlyph类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'SymbolGlyph' | 是 | 创建SymbolGlyph类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [SymbolGlyph](#symbolglyph13) | SymbolGlyph类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'SymbolGlyph');
```

### Checkbox<sup>13+</sup>
type Checkbox = TypedFrameNode&lt;CheckboxInterface, CheckboxAttribute&gt;

Checkbox类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;CheckboxInterface, CheckboxAttribute&gt; | 提供Checkbox类型FrameNode节点。<br/>**说明：**<br/> CheckboxInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Checkbox组件的构造函数类型。 <br/> CheckboxAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Checkbox组件的属性设置对象。 |

### createNode('Checkbox')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Checkbox'): Checkbox

创建Checkbox类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Checkbox' | 是 | 创建Checkbox类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Checkbox](#checkbox13) | Checkbox类型的FrameNode节点。 |

**示例： ** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Checkbox');
```

### CheckboxGroup<sup>13+</sup>
type CheckboxGroup = TypedFrameNode&lt;CheckboxGroupInterface, CheckboxGroupAttribute&gt;

CheckboxGroup类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;CheckboxGroupInterface, CheckboxGroupAttribute&gt; | 提供CheckboxGroup类型FrameNode节点。<br/>**说明：**<br/> CheckboxGroupInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为CheckboxGroup组件的构造函数类型。 <br/> CheckboxGroupAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回CheckboxGroup组件的属性设置对象。 |

### createNode('CheckboxGroup')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'CheckboxGroup'): CheckboxGroup

创建CheckboxGroup类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'CheckboxGroup' | 是 | 创建CheckboxGroup类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [CheckboxGroup](#checkboxgroup13) | CheckboxGroup类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'CheckboxGroup');
```

### Rating<sup>13+</sup>
type Rating = TypedFrameNode&lt;RatingInterface, RatingAttribute&gt;

Rating类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;RatingInterface, RatingAttribute&gt; | 提供Rating类型FrameNode节点。<br/>**说明：**<br/> RatingInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Rating组件的构造函数类型。 <br/> RatingAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Rating组件的属性设置对象。 |

### createNode('Rating')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Rating'): Rating

创建Rating类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Rating' | 是 | 创建Rating类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Rating](#rating13) | Rating类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Rating');
```

### Radio<sup>13+</sup>
type Radio = TypedFrameNode&lt;RadioInterface, RadioAttribute&gt;

Radio类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;RadioInterface, RadioAttribute&gt; | 提供Radio类型FrameNode节点。<br/>**说明：**<br/> RadioInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Radio组件的构造函数类型。 <br/> RadioAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Radio组件的属性设置对象。 |

### createNode('Radio')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Radio'): Radio

创建Radio类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Radio' | 是 | 创建Radio类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Radio](#radio13) | Radio类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Radio');
```

### Slider<sup>13+</sup>
type Slider = TypedFrameNode&lt;SliderInterface, SliderAttribute&gt;

Slider类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SliderInterface, SliderAttribute&gt; | 提供Slider类型FrameNode节点。<br/>**说明：**<br/> SliderInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Slider组件的构造函数类型。 <br/> SliderAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Slider组件的属性设置对象。 |

### createNode('Slider')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Slider'): Slider

创建Slider类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Slider' | 是 | 创建Slider类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Slider](#slider13) | Slider类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Slider');
```

### Select<sup>13+</sup>
type Select = TypedFrameNode&lt;SelectInterface, SelectAttribute&gt;

Select类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;SelectInterface, SelectAttribute&gt; | 提供Select类型FrameNode节点。<br/>**说明：**<br/> SelectInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Select组件的构造函数类型。 <br/> SelectAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Select组件的属性设置对象。 |

### createNode('Select')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Select'): Select

创建Select类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Select' | 是 | 创建Select类型的节点。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Select](#select13) | Select类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
typeNode.createNode(uiContext, 'Select');
```

### Toggle<sup>13+</sup>
type Toggle = TypedFrameNode&lt;ToggleInterface, ToggleAttribute&gt;

Toggle类型的FrameNode节点类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明                   |
| ----------------------------- | -------------------- |
| TypedFrameNode&lt;ToggleInterface, ToggleAttribute&gt; | 提供Toggle类型FrameNode节点。<br/>**说明：**<br/> ToggleInterface用于[TypedFrameNode](#typedframenode12)的[initialize](#属性)接口的入参，入参为Toggle组件的构造函数类型。 <br/> ToggleAttribute用于TypedFrameNode的[attribute](#属性)接口的返回值，返回Toggle组件的属性设置对象。 |

### createNode('Toggle')<sup>13+</sup>
createNode(context: UIContext, nodeType: 'Toggle', options?: ToggleOptions): Toggle

创建Toggle类型的FrameNode节点。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| ------------------ | ------------------ | ------------------- | ------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时所需的UI上下文。 |
| nodeType | 'Toggle' | 是 | 创建Toggle类型的节点。 |
| options | ToggleOptions | 否 | 创建Toggle节点的接口参数。 |

**返回值：**

| 类型                  | 说明      |
| ------------------ | ------------------ |
| [Toggle](#toggle13) | Toggle类型的FrameNode节点。 |

**示例：** 

<!--code_no_check-->

```ts
let toggleOptions: ToggleOptions = {type: ToggleType.Button, isOn: false};
typeNode.createNode(uiContext, 'Toggle', toggleOptions);
```

## NodeAdapter<sup>12+</sup>

NodeAdapter提供FrameNode的数据懒加载能力。

> **说明：**
>
> 入参不能为负数，入参为负数时不做处理。

**示例：**

请参考[NodeAdapter使用示例](#nodeadapter使用示例)。

### constructor<sup>12+</sup>

constructor()

NodeAdapter的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### dispose<sup>12+</sup>

dispose(): void

立即释放当前的NodeAdapter。如果是已绑定的状态，会先进行解绑操作，再释放当前的NodeAdapter。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### totalNodeCount<sup>12+</sup>

set totalNodeCount(count: number)

设置数据节点总数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| count | number | 是   | 数据节点总数。 |

get totalNodeCount(): number

获取数据节点总数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                     | 说明                 |
| ----------------- | ------------ |
| number | 数据节点总数。 |

### reloadAllItems<sup>12+</sup>

reloadAllItems(): void

重新加载全部数据操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### reloadItem<sup>12+</sup>

reloadItem(start: number, count: number): void

从索引值开始重新加载指定数量的节点数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| start | number | 是   | 重新加载的节点开始索引值。 |
| count | number | 是   | 重新加载数据节点的数量。 |

### removeItem<sup>12+</sup>

removeItem(start: number, count: number): void

从索引值开始删除指定数量的节点数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| start | number | 是   | 删除的节点开始索引值。 |
| count | number | 是   | 删除数据节点的数量。 |

### insertItem<sup>12+</sup>

insertItem(start: number, count: number): void

从索引值开始新增指定数量的节点数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| start | number | 是   | 新增的节点开始索引值。 |
| count | number | 是   | 新增数据节点的数量。 |

### moveItem<sup>12+</sup>

moveItem(from: number, to: number): void

将数据从原始索引移动到目的索引。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| from | number | 是   | 数据移动的原始索引值。 |
| to | number | 是   | 数据移动的目的索引值。 |

### getAllAvailableItems<sup>12+</sup>

getAllAvailableItems(): Array&lt;FrameNode&gt;

获取所有有效数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                     | 说明                 |
| ----------------- | ------------ |
| Array&lt;FrameNode&gt; | FrameNode数据节点集合。 |

### onAttachToNode<sup>12+</sup>

onAttachToNode?(target: FrameNode): void

FrameNode绑定NodeAdapter时回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| target | FrameNode | 是   | 绑定NodeAdapter的FrameNode节点。 |

### onDetachFromNode<sup>12+</sup>

onDetachFromNode?(): void

解除绑定时回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onGetChildId<sup>12+</sup>

onGetChildId?(index: number): number

节点首次加载或新节点滑入时回调。用于生成自定义的Id，需要开发者自行保证Id的唯一性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| index | number | 是   | 加载节点索引值。 |

**返回值：**

| 类型                     | 说明                 |
| ----------------- | ------------ |
| number | 返回开发者自定义生成的Id，需要开发者自行保证Id的唯一性。 |

### onCreateChild<sup>12+</sup>

onCreateChild?(index: number): FrameNode

节点首次加载或新节点滑入时回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| index | number | 是   | 加载节点索引值。 |

**返回值：**

| 类型                     | 说明                 |
| ----------------- | ------------ |
| FrameNode | 返回开发者创建的FrameNode节点。 |

### onDisposeChild<sup>12+</sup>

onDisposeChild?(id: number, node: FrameNode): void

子节点即将销毁时回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| id | number | 是   | 即将销毁的子节点id。 |
| node | FrameNode | 是   | 即将销毁的FrameNode节点。 |

### onUpdateChild<sup>12+</sup>

onUpdateChild?(id: number, node: FrameNode): void

重新加载的数据节点被复用时回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| id | number | 是   | 复用节点索引值。 |
| node | FrameNode | 是   | 被复用的FrameNode节点。 |

### attachNodeAdapter<sup>12+</sup>

static attachNodeAdapter(adapter: NodeAdapter, node: FrameNode): boolean

给FrameNode绑定一个NodeAdapter。一个节点只能绑定一个NodeAdapter。已经绑定NodeAdapter的再次绑定会失败并返回false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| adapter | [NodeAdapter](#nodeadapter12) | 是   | 定义懒加载的NodeAdapter类。 |
| node | FrameNode | 是   | 绑定的FrameNode节点。 |

**返回值：**

| 类型                     | 说明                 |
| ----------------- | ------------ |
| boolean | 绑定结果，返回true绑定成功，false绑定失败。 |

### detachNodeAdapter<sup>12+</sup>

static detachNodeAdapter(node: FrameNode): void

解除绑定操作，解除FrameNode节点绑定的NodeAdapter。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明             |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| node | FrameNode | 是   | 要解除绑定的FrameNode节点。 |

## 自定义具体类型节点示例

以Text节点为例，创建Text类型节点。

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

## 节点操作示例
```ts
import { NodeController, FrameNode, UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
## 基础事件示例
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

## LazyForEach场景基础事件使用示例

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

  // 该方法为框架侧调用，为LazyForEach组件向其数据源处添加listener监听
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // 该方法为框架侧调用，为对应的LazyForEach组件在数据源处去除listener监听
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  // 通知LazyForEach组件需要重载所有子组件
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // 通知LazyForEach组件需要在index对应索引处添加子组件
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // 通知LazyForEach组件在index对应索引处数据有变化，需要重建该子组件
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // 通知LazyForEach组件需要在index对应索引处删除该子组件
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  // 通知LazyForEach组件将from索引和to索引处的子组件进行交换
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
          // 通过TrackNode对组件进行封装埋点
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
    // 构建埋点的虚拟树，获取的node为当前页面的根节点（用例中为Row）。
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
    // 通过setOnVisibleAreaApproximateChange监听记录埋点组件的可视区域。
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

  // 通过全局dump输出埋点树的信息
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
    // 通过无感监听获取FrameNode查找埋点信息。
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
## 节点自定义示例

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
## NodeAdapter使用示例

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
