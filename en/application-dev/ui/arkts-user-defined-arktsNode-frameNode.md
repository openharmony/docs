# FrameNode

## Overview

For third-party frameworks with their own front-end defined DSL, the process of converting it into ArkUI's declarative description relies on additional data-driven binding to the [Builder](../quick-start/arkts-builder.md), which is complex and has lower performance. These frameworks generally depend on ArkUI's layout and event capabilities, as well as basic node operations and customization capabilities. Most components are completed through customization, but some native components need to be mixed and displayed. The design of [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) is to solve the above problems.

FrameNode represents the entity node of the component tree. In conjunction with custom placeholder container components such as [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md), it mounts a custom node tree in the placeholder container and dynamically adds, modifies, and deletes nodes in this node tree. The basic FrameNode can set common attributes, set event callbacks, and provide complete customization capabilities, including custom measurement, layout, and drawing.

In addition, the ArkUI framework also provides the ability to obtain and traverse the proxy FrameNode objects corresponding to native components, referred to as proxy nodes in the following text. Proxy nodes can be used when it is necessary to traverse the entire UI tree structure, and support obtaining specific information of native component nodes or registering additional component event listening callbacks.

## Creating and Deleting Nodes

FrameNode provides the ability to create and delete nodes. Custom FrameNode nodes can be created through the constructor of FrameNode, and the nodes created by the constructor correspond to an entity node. At the same time, the binding relationship with the entity node can be released through the [dispose](../reference/apis-arkui/js-apis-arkui-frameNode.md#dispose12) interface in FrameNode.

> **NOTE**
>
> - When creating a FrameNode object, the required parameter UIContext must be passed. If no UIContext object is passed or an illegal one is passed, an exception will be thrown when the node is created.
>
> - When the custom placeholder component displays the node, it is necessary to ensure the consistency of the UI context, otherwise, there will be display exceptions.
>
> - If the FrameNode object is not held, it will be recycled during GC.

## Determine if the Node is Modifiable

[isModifiable](../reference/apis-arkui/js-apis-arkui-frameNode.md#ismodifiable12) is used to query whether the current node type is a proxy node of the native component. When the FrameNode node acts as a proxy node for the native component, the node is not modifiable. That is, it is not possible to modify the attributes of the proxy node itself and the structure of its child nodes.

## Obtain the Corresponding RenderNode Node

FrameNode provides the [getRenderNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#getrendernode) interface, which is used to obtain the RenderNode in FrameNode. Operations on the obtained RenderNode object can dynamically modify the rendering-related attributes on FrameNode, and the specific modifiable attributes refer to the interface of RenderNode.

> **NOTE**
>
> - It is not possible to obtain the RenderNode object of the native component proxy FrameNode.
>
> - The FrameNode node object obtained by calling [getFrameNode](../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode) in BuilderNode can obtain the corresponding root node's RenderNode object through getRenderNode.

## Operating Node Tree

FrameNode provides the ability to add, delete, query, and modify nodes, which can modify the subtree structure of non-proxy nodes; it can query the parent and child nodes of all FrameNode nodes and return the query results.

> **NOTE**
>
> When performing add, delete, and modify operations on nodes, exceptions will be thrown for illegal operations.
>
> The proxy nodes obtained through query only have the function of querying node information and do not have the function of modifying node attributes; proxy nodes do not hold the entity nodes of the components, that is, they do not affect the lifecycle of the corresponding nodes.
>
> The query nodes only query nodes related to UI and do not return syntax nodes.
>
> In the scenario of using custom components, it may be possible to query and obtain additional nodes of custom components, and the node type is " __Common__ ".

```ts
import { BuilderNode, FrameNode, NodeController, UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

const TEST_TAG: string = "FrameNode"

class Params {
  text: string = "this is a text"
}

@Builder
function buttonBuilder(params: Params) {
  Column({ space: 10 }) {
    Button(params.text)
      .fontSize(12)
      .borderRadius(8)
      .borderWidth(2)
      .backgroundColor(Color.Orange)

    Button(params.text)
      .fontSize(12)
      .borderRadius(8)
      .borderWidth(2)
      .backgroundColor(Color.Pink)
  }
}

class MyNodeController extends NodeController {
  public buttonNode: BuilderNode<[Params]> | null = null;
  public frameNode: FrameNode | null = null;
  public childList: Array<FrameNode> = new Array<FrameNode>();
  public rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(buttonBuilder);

  makeNode(uiContext: UIContext): FrameNode | null {
    this.uiContext = uiContext;
    if (this.rootNode == null) {
      this.rootNode = new FrameNode(uiContext);
      this.rootNode.commonAttribute
        .width("50%")
        .height(100)
        .borderWidth(1)
        .backgroundColor(Color.Gray)
    }

    if (this.frameNode == null) {
      this.frameNode = new FrameNode(uiContext);
      this.frameNode.commonAttribute
        .width("100%")
        .height(50)
        .borderWidth(1)
        .position({ x: 200, y: 0 })
        .backgroundColor(Color.Pink);
      this.rootNode.appendChild(this.frameNode);
    }
    if (this.buttonNode == null) {
      this.buttonNode = new BuilderNode<[Params]>(uiContext);
      this.buttonNode.build(this.wrapBuilder, { text: "This is a Button" })
      this.rootNode.appendChild(this.buttonNode.getFrameNode())
    }
    return this.rootNode;
  }

  operationFrameNodeWithFrameNode(frameNode: FrameNode | undefined | null) {
    if (frameNode) {
      console.log(TEST_TAG + " get ArkTSNode success.")
      console.log(TEST_TAG + " check rootNode whether is modifiable " + frameNode.isModifiable());
    }
    if (this.uiContext) {
      let frameNode1 = new FrameNode(this.uiContext);
      let frameNode2 = new FrameNode(this.uiContext);
      frameNode1.commonAttribute.size({ width: 150, height: 150 })
        .backgroundColor(Color.Black)
        .position({ x: 50, y: 0 })
      frameNode2.commonAttribute.size({ width: 150, height: 150 })
        .backgroundColor(Color.Orange)
        .position({ x: 150, y: 25 })
      try {
        frameNode?.appendChild(frameNode1);
        console.log(TEST_TAG + " appendChild success ");
      } catch (err) {
        console.log(TEST_TAG + " appendChild fail :" + (err as BusinessError).code + " : " + (err as BusinessError).message);
      }
      try {
        frameNode?.insertChildAfter(frameNode2, null);
        console.log(TEST_TAG + " clearChildren success ");
      } catch (err) {
        console.log(TEST_TAG + " insertChildAfter fail : " + (err as BusinessError).code + " : " + (err as BusinessError).message);
      }
      setTimeout(() => {
        try {
          frameNode?.removeChild(frameNode?.getChild(0))
          console.log(TEST_TAG + " removeChild success ");
        } catch (err) {
          console.log(TEST_TAG + " removeChild fail : " + (err as BusinessError).code + " : " + (err as BusinessError).message);
        }
      }, 2000)
      setTimeout(() => {
        try {
          frameNode?.clearChildren();
          console.log(TEST_TAG + " clearChildren success ");
        } catch (err) {
          console.log(TEST_TAG + " clearChildren fail : " + (err as BusinessError).code + " : " + (err as BusinessError).message);
        }
      }, 4000)
    }
  }

  testInterfaceAboutSearch(frameNode: FrameNode | undefined | null): string {
    let result: string = "";
    if (frameNode) {
      result = result + `current node is ${frameNode.getNodeType()} \n`;
      result = result + `parent node is ${frameNode.getParent()?.getNodeType()} \n`;
      result = result + `child count is ${frameNode.getChildrenCount()} \n`;
      result = result + `first child node is ${frameNode.getFirstChild()?.getNodeType()} \n`;
      result = result + `seconde child node is ${frameNode.getChild(1)?.getNodeType()} \n`;
      result = result + `previousSibling node is ${frameNode.getPreviousSibling()?.getNodeType()} \n`;
      result = result + `nextSibling node is ${frameNode.getNextSibling()?.getNodeType()} \n`;
    }
    return result;
  }

  checkAppendChild(parent: FrameNode | undefined | null, child: FrameNode | undefined | null) {
    try {
      if (parent && child) {
        parent.appendChild(child);
        console.log(TEST_TAG + " appendChild success ");
      }
    } catch (err) {
      console.log(TEST_TAG + " appendChild fail : " + (err as BusinessError).code + " : " + (err as BusinessError).message);
    }
  }
}

@Entry
@Component
struct Index {
  @State index: number = 0;
  @State result: string = ""
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Column({ space: 5 }) {
            Text("Verify the add, delete, and modify functions of FrameNode child nodes")
            Button ("Operate custom FrameNode")
              .fontSize(16)
              .width(400)
              .onClick(() => {
              // Perform add, delete, and modify operations on FrameNode nodes, which is properly implemented.
                this.myNodeController.operationFrameNodeWithFrameNode(this.myNodeController?.frameNode);
              })
          Button("Operate on proxy nodes in BuilderNode")
              .fontSize(16)
              .width(400)
              .onClick(() => {
              // Perform add, delete, and modify operations on BuilderNode proxy nodes, capturing exception information.
                this.myNodeController.operationFrameNodeWithFrameNode(this.myNodeController?.buttonNode?.getFrameNode());
              })
          Button("Operate proxy nodes in native components")
              .fontSize(16)
              .width(400)
              .onClick(() => {
              // Perform add, delete, and modify operations on proxy nodes, capturing exception information.
                this.myNodeController.operationFrameNodeWithFrameNode(this.myNodeController?.rootNode?.getParent());
              })
          }
        }

        ListItem() {
          Column({ space: 5 }) {
            Text("Verify Special Scenarios for Adding Child Nodes to FrameNode")
            Button("Add a proxy node of BuilderNode to a custom FrameNode")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                let buttonNode = new BuilderNode<[Params]>(this.getUIContext());
                buttonNode.build(wrapBuilder<[Params]>(buttonBuilder), { text: "BUTTON" })
                this.myNodeController.checkAppendChild(this.myNodeController?.frameNode, buttonNode?.getFrameNode());
              })
            Button ("Add built-in component proxy node for custom FrameNode")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                this.myNodeController.checkAppendChild(this.myNodeController?.frameNode, this.myNodeController?.rootNode?.getParent());
              })
            Button ("Add a custom node with an existing parent node for a custom FrameNode.")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                this.myNodeController.checkAppendChild(this.myNodeController?.frameNode, this.myNodeController?.rootNode);
              })
          }
        }

        ListItem() {
          Column({ space: 5 }) {
            Text("Verify the query function of the FrameNode node.")
            Button ("Operate custom FrameNode")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // Query the FrameNode node. The current node is a child node of NodeContainer.
                this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.rootNode);
                setTimeout(() => {
                  //Query the FrameNode node. First subnode under rootNode.
                  this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.frameNode);
                }, 2000)
              })
            Button ("Operate on proxy node in BuilderNode")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // Query the BuilderNode agent node. The current node is a Column node in BuilderNode.
                this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.buttonNode?.getFrameNode());
              })
            Button ("Perform operations on the proxy node in the native component")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // Query the proxy node. The current node is NodeContainer.
                this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.rootNode?.getParent());
              })
          }
        }
      }.height("50%")

      Text(`Result: \n${this.result}`)
        .fontSize(16)
        .width(400)
        .height(200)
        .borderWidth(1)
      Column() {
        Text("This is a NodeContainer.")
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0xFFFFFF)
          .width('100%')
          .fontSize(16)
        NodeContainer(this.myNodeController)
          .borderWidth(1)
          .width(400)
          .height(150)
      }
    }
    .padding({ left: 35, right: 35, top: 35, bottom: 35 })
    .width("100%")
    .height("100%")
  }
}
```

## Setting Common Attributes and Event Callbacks for Nodes

The `FrameNode` provides two objects: [commonAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#commonattribute12) and [commonEvent](../reference/apis-arkui/js-apis-arkui-frameNode.md#commonevent12), for setting common attributes of nodes and defining event callbacks, respectively.

> **NOTE**
> 
> - Since the properties of proxy nodes are immutable, modifying the basic properties of nodes through `commonAttribute` on a proxy node will not take effect.
> 
> - The basic events set in parallel with the events defined by the native component, participate in event competition; the basic events set will not overwrite the events of the native component. When both events are set, the native component's event callback will be called first.

```ts
import { BuilderNode, FrameNode, NodeController, UIContext } from '@kit.ArkUI'

class Params {
  text: string = "this is a text"
}

@Builder
function buttonBuilder(params: Params) {
  Button(params.text)
    .fontSize(12)
    .borderRadius(8)
    .borderWidth(2)
    .backgroundColor(Color.Orange)
    .onClick((event: ClickEvent) => {
      console.log(`Button ${JSON.stringify(event)}`);
    })
}

class MyNodeController extends NodeController {
  public buttonNode: BuilderNode<[Params]> | null = null;
  public frameNode: FrameNode | null = null;
  public rootNode: FrameNode | null = null;
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(buttonBuilder);

  makeNode(uiContext: UIContext): FrameNode | null {
    if (this.rootNode == null) {
      this.rootNode = new FrameNode(uiContext);
      // Modify the attributes of the rootNode, this node is a custom FrameNode node, modification takes effect
      this.rootNode.commonAttribute
        .width("100%")
        .height(100)
        .borderWidth(1)
        .backgroundColor(Color.Gray)
    }

    if (this.frameNode == null) {
      this.frameNode = new FrameNode(uiContext);
      // Modify the attributes of the frameNode, this node is a custom FrameNode node, modification takes effect
      this.frameNode.commonAttribute
        .width("50%")
        .height(50)
        .borderWidth(1)
        .backgroundColor(Color.Pink);
      this.rootNode.appendChild(this.frameNode);
    }
    if (this.buttonNode == null) {
      this.buttonNode = new BuilderNode<[Params]>(uiContext);
      this.buttonNode.build(this.wrapBuilder, { text: "This is a Button" })
      // Modify the attributes of the FrameNode obtained from the BuilderNode, this node is not a custom FrameNode node, modification does not take effect
      this.buttonNode?.getFrameNode()?.commonAttribute.position({ x: 100, y: 100 })
      this.rootNode.appendChild(this.buttonNode.getFrameNode())
    }
    return this.rootNode;
  }

  modifyNode(frameNode: FrameNode | null | undefined, sizeValue: SizeOptions, positionValue: Position) {
    if (frameNode) {
      frameNode.commonAttribute.size(sizeValue).position(positionValue);
    }
  }

  addClickEvent(frameNode: FrameNode | null | undefined) {
    if (frameNode) {
      frameNode.commonEvent.setOnClick((event: ClickEvent) => {
        console.log(`FrameNode ${JSON.stringify(event)}`);
      })
    }
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Column({ space: 10 }) {
        Text("Modify General Node Attributes-Width and Height")
        Button("modify ArkTS-FrameNode")
          .onClick(() => {
            // The FrameNode object created by the developer on the current page is obtained. The node can be modified. That is, the node size and location.
            console.log("Check the weather the node can be modified " + this.myNodeController?.rootNode?.getParent()
            ?.isModifiable());
            this.myNodeController.modifyNode(this.myNodeController?.frameNode, { width: 150, height: 100 }, {
              x: 100,
              y: 0
            })
          })
        Button("modify FrameNode get by BuilderNode")
          .onClick(() => {
            // The root node of BuilderNode on the current page is obtained. This node cannot be modified. That is, the size and position of the node do not change.
            console.log("Check the weather the node can be modified " + this.myNodeController?.buttonNode?.getFrameNode()
            ?.isModifiable());
            this.myNodeController.modifyNode(this.myNodeController?.buttonNode?.getFrameNode(), {
              width: 100,
              height: 100
            }, { x: 50, y: 50 })
          })
        Button("modify proxyFrameNode get by search")
          .onClick(() => {
            // The rootNode calls getParent() to obtain the NodeContainer node on the current page. This node cannot be modified. That is, the size and position of the node do not change.
            console.log("Check the weather the node can be modified " + this.myNodeController?.rootNode?.getParent()
            ?.isModifiable());
            this.myNodeController.modifyNode(this.myNodeController?.rootNode?.getParent(), {
              width: 500,
              height: 500
            }, {
              x: 0,
              y: 0
            })
          })
      }.padding({ left: 35, right: 35, top: 35, bottom: 35 })

      Column({ space: 10 }) {
        Text("Modify Node Click Event")
        Button("add click event to ArkTS-FrameNode")
          .onClick(() => {
            // The FrameNode object created by the developer on the current page is obtained. Click events can be added to this node.
            // The added click event participates in event competition. That is, the click event is consumed on the node and no pop-up message is displayed to the parent component.
            console.log("Check the weather the node can be modified " + this.myNodeController?.rootNode?.getParent()
            ?.isModifiable());
            this.myNodeController.addClickEvent(this.myNodeController?.frameNode)
          })
        Button("add click event to FrameNode get by BuilderNode")
          .onClick(() => {
            // The root node of BuilderNode on the current page is obtained. Click events can be added to this type of node.
            // When a user clicks a button, the click event callback set through the native component interface is called back first, and then the click listener added through commonEvent is called back.
            console.log("Check the weather the node can be modified " + this.myNodeController?.buttonNode?.getFrameNode()
            ?.isModifiable());
            this.myNodeController.addClickEvent(this.myNodeController?.buttonNode?.getFrameNode())
          })
        Button("add click event to proxyFrameNode get by search")
          .onClick(() => {
            // The rootNode calls getParent() to obtain the NodeContainer node on the current page. Click events can be added to this type of node.
            console.log("Check the weather the node can be modified " + this.myNodeController?.rootNode?.getParent()
            ?.isModifiable());
            this.myNodeController.addClickEvent(this.myNodeController?.rootNode?.getParent());
          })
      }.padding({ left: 35, right: 35, top: 35, bottom: 35 })

      NodeContainer(this.myNodeController)
        .borderWidth(1)
        .width("100%")
        .height(100)
        .onClick((event: ClickEvent) => {
          console.log(`NodeContainer ${JSON.stringify(event)}`);
        })
    }
    .padding({ left: 35, right: 35, top: 35, bottom: 35 })
    .width("100%")
    .height("100%")
  }
}
```

## Custom Measurement Layout and Drawing

By overriding the [onDraw](../reference/apis-arkui/js-apis-arkui-frameNode.md#ondraw12) method, you can customize the drawing content of FrameNode. The [invalidate](../reference/apis-arkui/js-apis-arkui-frameNode.md#invalidate12) API can trigger a redraw of the node.

By overriding the [onMeasure](../reference/apis-arkui/js-apis-arkui-frameNode.md#onmeasure12), you can customize the measurement method of FrameNode, and using [measure](../reference/apis-arkui/js-apis-arkui-frameNode.md#measure12) can trigger a re-measurement by passing layout constraints.

By overriding the [onLayout](../reference/apis-arkui/js-apis-arkui-frameNode.md#onlayout12) method, you can customize the layout method of FrameNode, and using [layout](../reference/apis-arkui/js-apis-arkui-frameNode.md#layout12) can trigger a re-layout by passing position information.

[setNeedsLayout](../reference/apis-arkui/js-apis-arkui-frameNode.md#setneedslayout12) can mark the current node to trigger a re-layout in the next frame.

> **Note:**
> 
> - After disposing the reference of a node, since the `FrameNode` object no longer corresponds to a physical node, `invalidate` cannot trigger a refresh of the original bound node.
> 
> - The custom drawing performed by the `onDraw` method cannot exceed the size of the component.

```ts
import { DrawContext, FrameNode, NodeController, Position, Size, UIContext } from '@kit.ArkUI';
import { LayoutConstraint } from '@ohos.arkui.node';
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
    for (let i = 0;i < this.getChildrenCount(); i++) {
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
    for (let i = 0;i < this.getChildrenCount(); i++) {
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

## Finding Nodes and Getting Basic Information

`FrameNode` provides a query interface to return basic information of the physical node. For specific information returned, refer to the interfaces provided in `FrameNode`.

There are three ways to obtain `FrameNode`:

1. Using [getFrameNodeById](../reference/apis-arkui/js-apis-arkui-UIContext.md#getframenodebyid12).

2. Using [getFrameNodeByUniqueId](../reference/apis-arkui/js-apis-arkui-UIContext.md#getframenodebyuniqueid12).

3. Using an [observer API](../reference/apis-arkui/js-apis-arkui-observer.md).

> **NOTE**
>
> The information available from the current interface includes:
>
> - Node size: getMeasuredSize, getUserConfigSize
> 
> - Layout information: getPositionToWindow, getPositionToParent, getLayoutPosition, getUserConfigBorderWidth, getUserConfigPadding, getUserConfigMargin
> 
> - Node information: getId, getUniqueId, getNodeType, getOpacity, isVisible, isClipToFrame, isAttached, getInspectorInfo, getCustomProperty

<!--no_check-->

