# Custom Declarative Node (BuilderNode)

## Overview

[BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md) is a custom declarative nodedesigned to seamlessly mount built-in components. With BuilderNode, you can build a custom component tree within stateless UI environments through the [global custom builder function](../quick-start/arkts-builder.md#global-custom-builder-function), which is decorated by @Builder. Once your custom component tree is established, you can obtain its root [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) by calling [getFrameNode](../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode). The root node can be directly returned by [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) and mounted under a [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md). **BuilderNode** facilitates embedding of embedding declarative components within **FrameNode** and [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md) trees for mixed display. **BuilderNode** also offers a feature for exporting textures, which can be used for rendering within the same layer of the [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

The ArkTS built-in component tree constructed by **BuilderNode** can be used together with custom nodes, such as FrameNodes and RenderNodes, to achieve the mixed display effect. **BuilderNode** offers a suite of APIs designed to integrate built-in components within third-party frameworks. This is particularly beneficial for scenarios where these frameworks require interaction with custom nodes

**BuilderNode** offers the capability to pre-create components, allowing you to dictate when built-in components are instantiated. This feature is useful for dynamically mounting and displaying components, especially for those that have a longer initialization period, such as [Web](../reference/apis-arkweb/ts-basic-components-web.md) and [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

![builder-node](figures/builder-node.png)

## Basic Concepts

- [Built-in component](arkts-ui-development-overview.md): component provided directly by ArkUI. Components are essential elements of the UI, working together to shape the UI.

- Entity node: native node created by the backend.

A BuilderNode can be used only as a leaf node. If an update is required, you are advised to use the [update](../reference/apis-arkui/js-apis-arkui-builderNode.md#update) API provided by the BuilderNode, rather than making modifications directly to the RenderNode obtained from it. 

> **NOTE**
> 
> - The BuilderNode only supports a single [global custom build function(../quick-start/arkts-builder.md#global-custom-builder-function) decorated by @Builder and wrapped by [wrapBuilder](../quick-start/arkts-wrapBuilder.md).
> 
> - A newly created BuilderNode can only obtain a **FrameNode** object pointing to the root node through [getFrameNode](../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode) after [build](../reference/apis-arkui/js-apis-arkui-builderNode.md#build); otherwise, it returns **null**.
> 
> - If the root node of the passed Builder is a syntactic node (such as **if/else** and **ForEach**), an additional FrameNode must be generated, which will be displayed as "BuilderProxyNode" in the node tree.
> 
> - If BuilderNode mounts a node onto another FrameNode through **getFrameNode**, or mounts it as a child node onto a **NodeContainer**, the node uses the layout constraints of the parent component for layout.
> 
> - If a BuilderNode's FrameNode mounts its node onto a RenderNode through [getRenderNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#getrendernode), its size defaults to **0** since its FrameNode is not yet part of the tree. To display it properly, you must explicitly specify the layout constraint size through [selfIdeaSize](../reference/apis-arkui/js-apis-arkui-builderNode.md#renderoptions) in the constructor.
> 
> - Pre-creation with the BuilderNode does not reduce the creation time of components. For the **Web** component, resources must be loaded in the kernel during creation, and pre-creation cannot reduce this time. However, it enables the kernel to preload resources, which can reduce the loading time when the component is used.

## Creating a BuilderNode Object

When creating a **BuilderNode** object, which is a template class, you must specify a type that matches the type of the [WrappedBuilder](../quick-start/arkts-wrapBuilder.md) used in the **build** method later on. Mismatches can cause compilation warnings and failures.

## Creating a Built-in Component Tree

Use the **build** API of **BuilderNode** to create a built-in component tree. The tree is constructed based on the **WrappedBuilder** object passed in, and the root node of the component tree is retained.

> **NOTE**
>
> Stateless UI methods using the global @Builder can have at most one root node.
>
> The @Builder within the **build** method accepts only one input parameter.
>
> In scenarios where @Builder is nested within another @Builder in the **build** method, ensure that the parameters of the nested @Builder match the input parameters provided to the **build** method.
> 
> For scenarios where @Builder is nested within another @Builder, if the parameter types do not match, you must include the [BuilderOptions](../reference/apis-arkui/js-apis-arkui-builderNode.md#buildoptions12) field as a parameter for the [build](../reference/apis-arkui/js-apis-arkui-builderNode.md#build12) method.
> 
> To operate objects in a BuilderNode, ensure that the reference to the BuilderNode is not garbage collected. Once a BuilderNode object is collected by the virtual machine, its FrameNode and RenderNode objects will also be dereferenced from the backend nodes. This means that any FrameNode objects obtained from a BuilderNode will no longer correspond to any actual node if the BuilderNode is garbage collected.

Create offline nodes and built-in component trees, and use them in conjunction with FrameNodes.

The root node of the BuilderNode is directly used as the return value of [makeNode](../reference/apis-arkui/js-apis-arkui-nodeController.md#makenode) of [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md).

```ts
import { BuilderNode, FrameNode, NodeController, UIContext } from '@kit.ArkUI';

class Params {
  text: string = "";

  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
  }
}

class TextNodeController extends NodeController {
  private textNode: BuilderNode<[Params]> | null = null;
  private message: string = "DEFAULT";

  constructor(message: string) {
    super();
    this.message = message;
  }

  makeNode(context: UIContext): FrameNode | null {
    this.textNode = new BuilderNode(context);
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message))
    return this.textNode.getFrameNode();
  }
}

@Entry
@Component
struct Index {
  @State message: string = "hello";

  build() {
    Row() {
      Column() {
        NodeContainer(new TextNodeController(this.message))
          .width('100%')
          .height(100)
          .backgroundColor('#FFF0F0F0')
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

When combining a BuilderNode with a RenderNode, note the following:

If you mount the RenderNode from the BuilderNode under another RenderNode, you must explicitly specify [selfIdeaSize](../reference/apis-arkui/js-apis-arkui-builderNode.md#renderoptions) as the layout constraint for the BuilderNode. This approach to mounting nodes is not recommended.

```ts
import { NodeController, BuilderNode, FrameNode, UIContext, RenderNode } from "@kit.ArkUI";

class Params {
  text: string = "";

  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
  }
}

class TextNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private textNode: BuilderNode<[Params]> | null = null;
  private message: string = "DEFAULT";

  constructor(message: string) {
    super();
    this.message = message;
  }

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);
    let renderNode = new RenderNode();
    renderNode.clipToFrame = false;
    this.textNode = new BuilderNode(context, { selfIdealSize: { width: 150, height: 150 } });
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message));
    const textRenderNode = this.textNode?.getFrameNode()?.getRenderNode();

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
      renderNode.appendChild(textRenderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  @State message: string = "hello";

  build() {
    Row() {
      Column() {
        NodeContainer(new TextNodeController(this.message))
          .width('100%')
          .height(100)
          .backgroundColor('#FFF0F0F0')
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

## Updating the Built-in Component Tree

Create a built-in component tree using the **build** API of a **BuilderNode** object. The tree is constructed based on the **WrappedBuilder** object passed in, and the root node of the component tree is retained.

Custom component updates follow the update mechanisms of [state management](../quick-start/arkts-state-management-overview.md). For custom components used directly in a **WrappedBuilder** object, their parent component is the **BuilderNode** object. Therefore, to update child components defined in the **WrappedBuilder** objects, you need to define the relevant state variables with the [\@Prop](../quick-start/arkts-prop.md) or [\@ObjectLink](../quick-start/arkts-observed-and-objectlink.md) decorator, in accordance with the specifications of state management and the needs of your application development.

To update nodes within a BuilderNode:

- Use the **update** API to update individual nodes within the BuilderNode.
- Use the [updateConfiguration](../reference/apis-arkui/js-apis-arkui-builderNode.md#updateconfiguration12) API to trigger a full update of all nodes within the BuilderNode.

 

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI";

class Params {
  text: string = "";
  constructor(text: string) {
    this.text = text;
  }
}

// Custom component
@Component
struct TextBuilder {
  // The @Prop decorated attribute is the attribute to be updated in the custom component. It is a basic attribute.
  @Prop message: string = "TextBuilder";

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .margin({ bottom: 36 })
          .backgroundColor(Color.Gray)
      }
    }
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
    TextBuilder({ message: params.text }) // Custom component
  }
}

class TextNodeController extends NodeController {
  private textNode: BuilderNode<[Params]> | null = null;
  private message: string = "";

  constructor(message: string) {
    super()
    this.message = message
  }

  makeNode(context: UIContext): FrameNode | null {
    this.textNode = new BuilderNode(context);
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message))
    return this.textNode.getFrameNode();
  }

  update(message: string) {
    if (this.textNode !== null) {
      // Call update to perform an update.
      this.textNode.update(new Params(message));
    }
  }
}

@Entry
@Component
struct Index {
  @State message: string = "hello";
  private textNodeController: TextNodeController = new TextNodeController(this.message);
  private count = 0;

  build() {
    Row() {
      Column() {
        NodeContainer(this.textNodeController)
          .width('100%')
          .height(200)
          .backgroundColor('#FFF0F0F0')
        Button('Update')
          .onClick(() => {
            this.count += 1;
            const message = "Update " + this.count.toString();
            this.textNodeController.update(message);
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

## Canceling the Reference to the Entity Node

A **BuilderNode** object is mapped to a backend entity node, and its memory release is usually contingent on the disposal of the frontend object. To directly release the backend node object, you can call the [dispose](../reference/apis-arkui/js-apis-arkui-builderNode.md#dispose12) API to break the reference to the entity node. Once this is done, the frontend **BuilderNode** object will no longer affect the lifecycle of the entity node.

> **NOTE**
>
> Calling **dispose** on a **BuilderNode** object breaks its reference to the backend entity node, and also simultaneously severs the references of its contained FrameNode and RenderNode to their respective entity nodes.

## Injecting a Touch Event

Use the [postTouchEvent](../reference/apis-arkui/js-apis-arkui-builderNode.md#posttouchevent) API in the BuilderNode to inject a [touch event](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md) into the bound component for event simulation and forwarding.

 

The following example forwards a touch event from one **Column** component to another in the BuilderNode, so that when the lower **Column** component is touched, the upper **Column** component also receives the same touch event. The API returns **true** if the button's event is successfully recognized.

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

class Params {
  text: string = "this is a text";
}

@Builder
function ButtonBuilder(params: Params) {
  Column() {
    Button(`button ` + params.text)
      .borderWidth(2)
      .backgroundColor(Color.Orange)
      .width("100%")
      .height("100%")
      .gesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            console.log("TapGesture");
          })
      )
  }
  .width(500)
  .height(300)
  .backgroundColor(Color.Gray)
}

class MyNodeController extends NodeController {
  private rootNode: BuilderNode<[Params]> | null = null;
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(ButtonBuilder);

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new BuilderNode(uiContext);
    this.rootNode.build(this.wrapBuilder, { text: "this is a string" })
    return this.rootNode.getFrameNode();
  }

  postTouchEvent(touchEvent: TouchEvent): void {
    if (this.rootNode == null) {
      return;
    }
    let result = this.rootNode.postTouchEvent(touchEvent);
    console.log("result " + result);
  }
}

@Entry
@Component
struct MyComponent {
  private nodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.nodeController)
        .height(300)
        .width(500)
      Column()
        .width(500)
        .height(300)
        .backgroundColor(Color.Pink)
        .onTouch((event) => {
          if (event != undefined) {
            this.nodeController.postTouchEvent(event);
          }
        })
    }
  }
}
```

## Reusing a BuilderNode

To reuse a BuilderNode, pass the [reuse](../reference/apis-arkui/js-apis-arkui-builderNode.md#reuse12) and [recycle](../reference/apis-arkui/js-apis-arkui-builderNode.md#recycle12) events to the custom components within the BuilderNode.

```ts
import { FrameNode,NodeController,BuilderNode,UIContext } from "@kit.ArkUI";

class MyDataSource {
  private dataArray: string[] = [];
  private listener: DataChangeListener | null = null

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number) {
    return this.dataArray[index];
  }

  public pushData(data: string) {
    this.dataArray.push(data);
  }

  public reloadListener(): void {
    this.listener?.onDataReloaded();
  }

  public registerDataChangeListener(listener: DataChangeListener): void {
    this.listener = listener;
  }

  public unregisterDataChangeListener(): void {
    this.listener = null;
  }
}

class Params {
  item: string = '';

  constructor(item: string) {
    this.item = item;
  }
}

@Builder
function buildNode(param: Params = new Params("hello")) {
  ReusableChildComponent2({ item: param.item });
}

class MyNodeController extends NodeController {
  public builderNode: BuilderNode<[Params]> | null = null;
  public item: string = "";

  makeNode(uiContext: UIContext): FrameNode | null {
    if (this.builderNode == null) {
      this.builderNode = new BuilderNode(uiContext, { selfIdealSize: { width: 300, height: 200 } });
      this.builderNode.build(wrapBuilder<[Params]>(buildNode), new Params(this.item));
    }
    return this.builderNode.getFrameNode();
  }
}

@Reusable
@Component
struct ReusableChildComponent {
  @State item: string = '';
  private controller: MyNodeController = new MyNodeController();

  aboutToAppear() {
    this.controller.item = this.item;
  }

  aboutToRecycle(): void {
    console.log("ReusableChildComponent aboutToRecycle " + this.item);
    this.controller?.builderNode?.recycle();
  }

  aboutToReuse(params: object): void {
    console.log("ReusableChildComponent aboutToReuse " + JSON.stringify(params));
    this.controller?.builderNode?.reuse(params);
  }

  build() {
    NodeContainer(this.controller);
  }
}

@Component
struct ReusableChildComponent2 {
  @Prop item: string = "false";

  aboutToReuse(params: Record<string, object>) {
    console.log("ReusableChildComponent2 Reusable 2 " + JSON.stringify(params));
  }

  aboutToRecycle(): void {
    console.log("ReusableChildComponent2 aboutToRecycle 2 " + this.item);
  }

  build() {
    Row() {
      Text(this.item)
        .fontSize(20)
        .backgroundColor(Color.Yellow)
        .margin({ left: 10 })
    }.margin({ left: 10, right: 10 })
  }
}


@Entry
@Component
struct Index {
  @State data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0;i < 100; i++) {
      this.data.pushData(i.toString());
    }
  }

  build() {
    Column() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            ReusableChildComponent({ item: item })
          }
        }, (item: string) => item)
      }
      .width('100%')
      .height('100%')
    }
  }
}
```

## Updating Nodes Based on System Environment Changes

Use the [updateConfiguration](../reference/apis-arkui/js-apis-arkui-builderNode.md#reuse12) API to listen for [system environment changes](../reference/apis-ability-kit/js-apis-app-ability-configuration.md). This will trigger a full update of all nodes within the BuilderNode.

> **NOTE**
>
> The **updateConfiguration** API is designed to inform objects of the need to update, with the updates reflecting changes in the application's current system environment.

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI";
import { AbilityConstant, Configuration, EnvironmentCallback } from '@kit.AbilityKit';

class Params {
  text: string = ""

  constructor(text: string) {
    this.text = text;
  }
}

// Custom component
@Component
struct TextBuilder {
  // The @Prop decorated attribute is the attribute to be updated in the custom component. It is a basic attribute.
  @Prop message: string = "TextBuilder";

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .margin({ bottom: 36 })
          .fontColor($r(`app.color.text_color`))
          .backgroundColor($r(`app.color.start_window_background`))
      }
    }
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
      .fontColor($r(`app.color.text_color`))
    TextBuilder({ message: params.text }) // Custom component
  }.backgroundColor($r(`app.color.start_window_background`))
}

class TextNodeController extends NodeController {
  private textNode: BuilderNode<[Params]> | null = null;
  private message: string = "";

  constructor(message: string) {
    super()
    this.message = message;
  }

  makeNode(context: UIContext): FrameNode | null {
    return this.textNode?.getFrameNode() ? this.textNode?.getFrameNode() : null;
  }

  createNode(context: UIContext) {
    this.textNode = new BuilderNode(context);
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message));
    builderNodeMap.push(this.textNode);
  }

  deleteNode() {
    let node = builderNodeMap.pop();
    node?.dispose();
  }

  update(message: string) {
    if (this.textNode !== null) {
      // Call update to perform an update.
      this.textNode.update(new Params(message));
    }
  }
}

// Record the created custom node object.
const builderNodeMap: Array<BuilderNode<[Params]>> = new Array();

function updateColorMode() {
  builderNodeMap.forEach((value, index) => {
    // Notify BuilderNode of the environment changes.
    value.updateConfiguration();
  })
}

@Entry
@Component
struct Index {
  @State message: string = "hello"
  private textNodeController: TextNodeController = new TextNodeController(this.message);
  private count = 0;

  aboutToAppear(): void {
    let environmentCallback: EnvironmentCallback = {
      onMemoryLevel: (level: AbilityConstant.MemoryLevel): void => {
        console.log('onMemoryLevel');
      },
      onConfigurationUpdated: (config: Configuration): void => {
        console.log('onConfigurationUpdated ' + JSON.stringify(config));
        updateColorMode();
      }
    }
    // Register a callback.
    this.getUIContext().getHostContext()?.getApplicationContext().on('environment', environmentCallback);
    // Create a custom node and add it to the map.
    this.textNodeController.createNode(this.getUIContext());
  }

  aboutToDisappear(): void {
    // Remove the reference to the custom node from the map and release the node.
    this.textNodeController.deleteNode();
  }

  build() {
    Row() {
      Column() {
        NodeContainer(this.textNodeController)
          .width('100%')
          .height(200)
          .backgroundColor('#FFF0F0F0')
        Button('Update')
          .onClick(() => {
            this.count += 1;
            const message = "Update " + this.count.toString();
            this.textNodeController.update(message);
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```
