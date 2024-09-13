# FrameNode

## 概述

对于具备自己前端定义的三方框架，需要将特定的dsl转换成为ArkUI的声明式描述。这个转换过程需依赖额外的数据驱动绑定至[Builder](../quick-start/arkts-builder.md)中，转换比较复杂且性能较低。这一类框架一般依赖系统ArkUI框架的布局、事件能力，以及最基础的节点操作和自定义能力，大部分组件通过自定义完成，但是需要使用部分原生组件混合显示。[FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md)的设计就是为了解决上述的问题。

FrameNode表示组件树的实体节点，配合自定义占位容器组件[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)等，在占位容器内挂载一棵自定义的节点树，并对这个节点树中的节点进行动态的增加、修改、删除等操作。基础的FrameNode可以设置通用属性、设置事件回调，并提供完整的自定义能力，包括自定义测量、布局以及绘制。

除此之外，ArkUI框架还提供获取和遍历获得原生组件对应的代理FrameNode对象的能力，下文简称代理节点。代理节点可以用于需要遍历整个UI的树形结构，并支持获取原生组件节点的具体信息或者额外注册组件的事件监听回调。

## 创建和删除节点

FrameNode提供了节点创建和删除的能力。可以通过FrameNode的构造函数创建自定义FrameNode节点，通过构造函数创建的节点对应一个实体的节点。同时，可以通过FrameNode中的[dispose](../reference/apis-arkui/js-apis-arkui-frameNode.md#dispose12)接口来实现与实体节点的绑定关系的解除。

> **说明：**
>
> - 在创建FrameNode对象的时候需要传入必选参数UIContext，若未传入UIContext对象或者传入不合法，则节点创建抛出异常。
>
> - 自定义占位组件将节点进行显示的时候需要保证UI上下文一致，否则会出现显示异常。
>
> - 若不持有FrameNode对象，则该对象会在GC的时候被回收。

## 判断节点是否可修改

[isModifiable](../reference/apis-arkui/js-apis-arkui-frameNode.md#ismodifiable12)用于查询当前节点类型是否为原生组件的代理节点。当FrameNode节点作为原生组件的代理节点的时候，该节点不可修改。即无法修改代理节点的自身属性以及其子节点的结构。

## 获取对应的RenderNode节点

FrameNode提供了[getRenderNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#getrendernode)接口，用于获取FrameNode中的RenderNode。可以通过对获取到的RenderNode对象进行操作，动态修改FrameNode上绘制相关的属性，具体可修改的属性参考RenderNode的接口。

> **说明：**
>
> - 无法获取原生组件代理FrameNode的RenderNode对象。
> 
> - BuilderNode中调用[getFrameNode](../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode)获取得到的FrameNode节点对象中，可以通过getRenderNode获取对应的根节点的RenderNode对象。

## 操作节点树

FrameNode提供了节点的增、删、查、改的能力，能够修改非代理节点的子树结构。可以对所有FrameNode的节点的父子节点做出查询操作，并返回查询结果。

> **说明：**
>
> 对节点进行增、删、改操作的时候，会对非法操作抛出异常信息。
>
> 通过查询获得的原生组件的代理节点，仅具备查询节点信息的作用，不具备修改节点属性的功能。代理节点不持有组件的实体节点，即不影响对应的节点的生命周期。
>
> 查询节点仅查询获得UI相关的节点，不返回语法节点。
>
> 使用自定义组件的场景下，可能查询获得自定义组件的新增节点，节点类型为“\_\_Common\_\_”。

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
      frameNode1.commonAttribute.size({ width: 50, height: 50 })
        .backgroundColor(Color.Black)
        .position({ x: 50, y: 60 })
      frameNode2.commonAttribute.size({ width: 50, height: 50 })
        .backgroundColor(Color.Orange)
        .position({ x: 120, y: 60 })
      try {
        frameNode?.appendChild(frameNode1);
        console.log(TEST_TAG + " appendChild success ");
      } catch (err) {
        console.log(TEST_TAG + " appendChild fail :" + (err as BusinessError).code + " : " + (err as BusinessError).message);
      }
      try {
        frameNode?.insertChildAfter(frameNode2, null);
        console.log(TEST_TAG + " insertChildAfter success ");
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
      result = result + `second child node is ${frameNode.getChild(1)?.getNodeType()} \n`;
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
            Text("验证FrameNode子节点的增、删、改功能")
            Button("对自定义FrameNode进行操作")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // 对FrameNode节点进行增、删、改操作，正常实现。
                this.myNodeController.operationFrameNodeWithFrameNode(this.myNodeController?.frameNode);
              })
            Button("对BuilderNode中的代理节点进行操作")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // 对BuilderNode代理节点进行增、删、改操作，捕获异常信息。
                this.myNodeController.operationFrameNodeWithFrameNode(this.myNodeController?.buttonNode?.getFrameNode());
              })
            Button("对原生组件中的代理节点进行操作")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // 对代理节点进行增、删、改操作，捕获异常信息。
                this.myNodeController.operationFrameNodeWithFrameNode(this.myNodeController?.rootNode?.getParent());
              })
          }
        }

        ListItem() {
          Column({ space: 5 }) {
            Text("验证FrameNode添加子节点的特殊场景")
            Button("新增BuilderNode的代理节点")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                let buttonNode = new BuilderNode<[Params]>(this.getUIContext());
                buttonNode.build(wrapBuilder<[Params]>(buttonBuilder), { text: "BUTTON" })
                this.myNodeController.checkAppendChild(this.myNodeController?.frameNode, buttonNode?.getFrameNode());
              })
            Button("新增原生组件代理节点")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                this.myNodeController.checkAppendChild(this.myNodeController?.frameNode, this.myNodeController?.rootNode?.getParent());
              })
            Button("新增已有父节点的自定义节点")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                this.myNodeController.checkAppendChild(this.myNodeController?.frameNode, this.myNodeController?.rootNode);
              })
          }
        }

        ListItem() {
          Column({ space: 5 }) {
            Text("验证FrameNode节点的查询功能")
            Button("对自定义FrameNode进行操作")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // 对FrameNode节点进行进行查询。当前节点为NodeContainer的子节点。
                this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.rootNode);
                setTimeout(() => {
                  // 对FrameNode节点进行进行查询。rootNode下的第一个子节点。
                  this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.frameNode);
                }, 2000)
              })
            Button("对BuilderNode中的代理节点进行操作")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // 对BuilderNode代理节点进行进行查询。当前节点为BuilderNode中的Column节点。
                this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.buttonNode?.getFrameNode());
              })
            Button("对原生组件中的代理节点进行操作")
              .fontSize(16)
              .width(400)
              .onClick(() => {
                // 对代理节点进行查询。当前节点为NodeContainer。
                this.result = this.myNodeController.testInterfaceAboutSearch(this.myNodeController?.rootNode?.getParent());
              })
          }
        }
      }.height("50%")

      Text(`Result：\n${this.result}`)
        .fontSize(16)
        .width(400)
        .height(200)
        .padding(30)
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

## 设置节点通用属性和事件回调

FrameNode提供了[commonAttribute](../reference/apis-arkui/js-apis-arkui-frameNode.md#commonattribute12)和[commonEvent](../reference/apis-arkui/js-apis-arkui-frameNode.md#commonevent12)两个对象用于对设置节点的[通用属性](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md)和[设置事件回调](../reference/apis-arkui/arkui-ts/ts-uicommonevent.md)。

> **说明：**
> 
> - 由于代理节点的属性不可修改，因此通过代理节点的commonAttribute修改节点的基础属性不生效。
> 
> - 设置的基础事件与原生组件定义的事件平行，参与事件竞争。设置的基础事件不覆盖原生组件事件。同时设置两个事件回调的时候，优先回调原生组件事件。

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
      // 对rootNode进行属性修改，该节点为自定义的FrameNode节点，修改生效
      this.rootNode.commonAttribute
        .width("100%")
        .height(100)
        .borderWidth(1)
        .backgroundColor(Color.Gray)
    }

    if (this.frameNode == null) {
      this.frameNode = new FrameNode(uiContext);
      // 对frameNode进行属性修改，该节点为自定义的FrameNode节点，修改生效
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
      // 对BuilderNode中获取的FrameNode进行属性修改，该节点非自定义的FrameNode节点，修改不生效
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
        Text("修改节点通用属性-宽高")
        Button("modify ArkTS-FrameNode")
          .onClick(() => {
            // 获取到的是当前页面中的开发者创建的FrameNode对象，该节点可修改。即节点大小与位置。
            console.log("Check the weather the node can be modified " + this.myNodeController?.frameNode
            ?.isModifiable());
            this.myNodeController.modifyNode(this.myNodeController?.frameNode, { width: 150, height: 100 }, {
              x: 100,
              y: 0
            })
          })
        Button("modify FrameNode get by BuilderNode")
          .onClick(() => {
            // 获取到的是当前页面中的BuilderNode的根节点，该节点不可修改。即节点大小与位置未发生改变。
            console.log("Check the weather the node can be modified " + this.myNodeController?.buttonNode?.getFrameNode()
            ?.isModifiable());
            this.myNodeController.modifyNode(this.myNodeController?.buttonNode?.getFrameNode(), {
              width: 100,
              height: 100
            }, { x: 50, y: 50 })
          })
        Button("modify proxyFrameNode get by search")
          .onClick(() => {
            // rootNode调用getParent()获取到的是当前页面中的NodeContainer节点，该节点不可修改。即节点大小与位置未发生改变。
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
        Text("修改节点点击事件")
        Button("add click event to ArkTS-FrameNode")
          .onClick(() => {
            // 获取到的是当前页面中的开发者创建的FrameNode对象，该节点可增加点击事件。
            // 增加的点击事件参与事件竞争，即点击事件会在该节点被消费且不不再向父组件冒泡。
            console.log("Check the weather the node can be modified " + this.myNodeController?.rootNode?.getParent()
            ?.isModifiable());
            this.myNodeController.addClickEvent(this.myNodeController?.frameNode)
          })
        Button("add click event to FrameNode get by BuilderNode")
          .onClick(() => {
            // 获取到的是当前页面中的BuilderNode的根节点，该类节点可增加点击事件。
            // 点击的时候优先回调通过原生组件接口设置的click事件回调，然后回调通过commonEvent增加的click监听。
            console.log("Check the weather the node can be modified " + this.myNodeController?.buttonNode?.getFrameNode()
            ?.isModifiable());
            this.myNodeController.addClickEvent(this.myNodeController?.buttonNode?.getFrameNode())
          })
        Button("add click event to proxyFrameNode get by search")
          .onClick(() => {
            // rootNode调用getParent()获取到的是当前页面中的NodeContainer节点，该类节点可增加点击事件。
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

## 自定义测量布局与绘制

通过重写[onDraw](../reference/apis-arkui/js-apis-arkui-frameNode.md#ondraw12)方法，可以自定义FrameNode的绘制内容。[invalidate](../reference/apis-arkui/js-apis-arkui-frameNode.md#invalidate12)接口可以主动触发节点的重新绘制。

通过重写[onMeasure](../reference/apis-arkui/js-apis-arkui-frameNode.md#onmeasure12)可以自定义FrameNode的测量方式，使用[measure](../reference/apis-arkui/js-apis-arkui-frameNode.md#measure12)可以主动传递布局约束触发重新测量。

通过重写[onLayout](../reference/apis-arkui/js-apis-arkui-frameNode.md#onlayout12)方法可以自定义FrameNode的布局方式，使用[layout](../reference/apis-arkui/js-apis-arkui-frameNode.md#layout12)方法可以主动传递位置信息并触发重新布局。

[setNeedsLayout](../reference/apis-arkui/js-apis-arkui-frameNode.md#setneedslayout12)可以将当前节点标记，在下一帧触发重新布局。

> **说明：**
> 
> - 对节点进行dispose解引用后，由于FrameNode对象不再对应一个实体节点，invalidate无法触发原有绑定节点的刷新。
> 
> - 通过onDraw方法进行的自定义绘制，绘制内容大小无法超出组件大小。

```ts
import { DrawContext, FrameNode, NodeController, Position, Size, UIContext, LayoutConstraint } from '@kit.ArkUI';
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
  public width: number = 100;
  public offsetY: number = 0;
  private space: number = 1;

  onMeasure(constraint: LayoutConstraint): void {
    let sizeRes: Size = { width: vp2px(100), height: vp2px(100) };
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
          x: vp2px(100),
          y: vp2px(this.offsetY)
        });
        y += child.getMeasuredSize().height + this.space;
      }
    }
    this.setLayoutPosition(position);
  }

  onDraw(context: DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(15);
    pen.setColor({ alpha: 255, red: 255, green: 0, blue: 0 });
    canvas.attachPen(pen);
    canvas.drawRect({  
      left: 50, 
      right: this.width + 50, 
      top: 50, 
      bottom: this.width + 50,
    });
    canvas.detachPen();
  }

  addWidth() {
    this.width = (this.width + 10) % 50 + 100;
  }
}

class MyNodeController extends NodeController {
  public rootNode: MyFrameNode | null = null;

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new MyFrameNode(context);
    this.rootNode?.commonAttribute?.size({ width: 100, height: 100 }).backgroundColor(Color.Green);
    let frameNode: FrameNode = new FrameNode(context);
    this.rootNode.appendChild(frameNode);
    frameNode.commonAttribute.width(10).height(10).backgroundColor(Color.Pink);
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
          .height(200)
          .backgroundColor('#FFF0F0F0')
        Button('Invalidate')
          .margin(10)
          .onClick(() => {
            this.nodeController?.rootNode?.addWidth();
            this.nodeController?.rootNode?.invalidate();
          })
        Button('UpdateLayout')
          .onClick(() => {
            let node = this.nodeController.rootNode;
            node!.offsetY = (node!.offsetY + 10) % 110;
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

## 查找节点及获取基础信息

FrameNode提供了查询接口用于返回实体节点的基础信息。具体返回的信息内容参考FrameNode中提供的接口。

查找获得FrameNode的方式包括三种：

1. 使用[getFrameNodeById](../reference/apis-arkui/js-apis-arkui-UIContext.md#getframenodebyid12)获取。

2. 使用[getFrameNodeByUniqueId](../reference/apis-arkui/js-apis-arkui-UIContext.md#getframenodebyuniqueid12)获取。

3. 通过[无感监听](../reference/apis-arkui/js-apis-arkui-observer.md)获取。

> **说明：**
>
> 当前接口提供的可查询的信息包括：
>
> - 节点大小：[getMeasuredSize](../reference/apis-arkui/js-apis-arkui-frameNode.md#getmeasuredsize12)，[getUserConfigSize](../reference/apis-arkui/js-apis-arkui-frameNode.md#getuserconfigsize12)
> 
> - 布局信息：[getPositionToWindow](../reference/apis-arkui/js-apis-arkui-frameNode.md#getpositiontowindow12)，[getPositionToParent](../reference/apis-arkui/js-apis-arkui-frameNode.md#getpositiontoparent12)，[getLayoutPosition](../reference/apis-arkui/js-apis-arkui-frameNode.md#getlayoutposition12)，[getUserConfigBorderWidth](../reference/apis-arkui/js-apis-arkui-frameNode.md#getuserconfigborderwidth12)，[getUserConfigPadding](../reference/apis-arkui/js-apis-arkui-frameNode.md#getuserconfigpadding12)，[getUserConfigMargin](../reference/apis-arkui/js-apis-arkui-frameNode.md#getuserconfigmargin12)
> 
> - 节点信息：[getId](../reference/apis-arkui/js-apis-arkui-frameNode.md#getid12) ，[getUniqueId](../reference/apis-arkui/js-apis-arkui-frameNode.md#getuniqueid12)，[getNodeType](../reference/apis-arkui/js-apis-arkui-frameNode.md#getnodetype12)，[getOpacity](../reference/apis-arkui/js-apis-arkui-frameNode.md#getopacity12)，[isVisible](../reference/apis-arkui/js-apis-arkui-frameNode.md#isvisible12)，[isClipToFrame](../reference/apis-arkui/js-apis-arkui-frameNode.md#iscliptoframe12)，[isAttached](../reference/apis-arkui/js-apis-arkui-frameNode.md#isattached12)，[getInspectorInfo](../reference/apis-arkui/js-apis-arkui-frameNode.md#getinspectorinfo12)，[getCustomProperty](../reference/apis-arkui/js-apis-arkui-frameNode.md#getcustomproperty12)
