# Custom Declarative Node (BuilderNode)

## Overview

[BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md) is a custom declarative nodedesigned to seamlessly mount built-in components. With BuilderNode, you can build a custom component tree within stateless UI environments through the [global custom builder function](../ui/state-management/arkts-builder.md#global-custom-builder-function), which is decorated by @Builder. Once your custom component tree is established, you can obtain its root [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) by calling [getFrameNode](../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode). The root node can be directly returned by [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) and mounted under a [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md). **BuilderNode** facilitates embedding of embedding declarative components within **FrameNode** and [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md) trees for mixed display. **BuilderNode** also offers a feature for exporting textures, which can be used for rendering within the same layer of the [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

The ArkTS component tree constructed by **BuilderNode** can be used together with custom nodes, such as FrameNodes and RenderNodes, to achieve the mixed display effect. **BuilderNode** offers a suite of APIs designed to integrate built-in components within third-party frameworks. This is particularly beneficial for scenarios where these frameworks require interaction with custom nodes

**BuilderNode** offers the capability to pre-create components, allowing you to dictate when built-in components are instantiated. This feature is useful for dynamically mounting and displaying components, especially for those that have a longer initialization period, such as [Web](../reference/apis-arkweb/arkts-basic-components-web.md) and [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

![builder-node](figures/builder-node.png)

## Basic Concepts

- [Built-in component](arkts-ui-development-overview.md): component provided directly by ArkUI. Components are essential elements of the UI, working together to shape the UI.

- Entity node: native node created by the backend.

A BuilderNode can be used only as a leaf node. If an update is required, you are advised to use the [update](../reference/apis-arkui/js-apis-arkui-builderNode.md#update) API provided by the BuilderNode, rather than making modifications directly to the RenderNode obtained from it. 

> **NOTE**
> 
> - The BuilderNode only supports a single [global custom build function](../ui/state-management/arkts-builder.md#global-custom-builder-function) decorated by @Builder and wrapped by [wrapBuilder](../ui/state-management/arkts-wrapBuilder.md).
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

When creating a **BuilderNode** object, which is a template class, you must specify a type that matches the type of the [WrappedBuilder](../ui/state-management/arkts-wrapBuilder.md) used in the **build** method later on. Mismatches can cause compilation warnings and failures.

## Creating a Component Tree

Use the **build** API of **BuilderNode** to create a component tree. The tree is constructed based on the **WrappedBuilder** object passed in, and the root node of the component tree is retained.

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

Create offline nodes and component trees, and use them in conjunction with FrameNodes.

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

## Updating a Component Tree

The **build** API of a **BuilderNode** object constructs a component tree by accepting a **WrappedBuilder** object and maintains a reference to the root node of the created component tree.

Custom component updates follow the update mechanisms of [state management](../ui/state-management/arkts-state-management-overview.md). For custom components used directly in a **WrappedBuilder** object, their parent component is the **BuilderNode** object. Therefore, to update child components defined in the **WrappedBuilder** objects, you need to define the relevant state variables with the [\@Prop](../ui/state-management/arkts-prop.md) or [\@ObjectLink](../ui/state-management/arkts-observed-and-objectlink.md) decorator, in accordance with the specifications of state management and the needs of your application development.


To update nodes within a BuilderNode:<br>Use the **update** API to update individual nodes within the BuilderNode.

Use the [updateConfiguration](../reference/apis-arkui/js-apis-arkui-builderNode.md#updateconfiguration12) API to trigger a full update of all nodes within the BuilderNode.

 

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
>
> If the frontend object BuilderNode cannot be released, memory leaks may occur. To avoid this, be sure to call **dispose** on the BuilderNode when you no longer need it. This reduces the complexity of reference relationships and lowers the risk of memory leaks.

## Injecting a Touch Event

Use the [postTouchEvent](../reference/apis-arkui/js-apis-arkui-builderNode.md#posttouchevent) API in **BuilderNode** to inject a [touch event](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md) into the bound component for event simulation and forwarding.

 

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

## Implementing Node Reuse with the BuilderNode reuse and recycle APIs

To implement component reuse within a BuilderNode, you need to call the [reuse](../reference/apis-arkui/js-apis-arkui-builderNode.md#reuse12) and [recycle](../reference/apis-arkui/js-apis-arkui-builderNode.md#recycle12) APIs. These APIs pass reuse and recycle events to custom components inside the BuilderNode.

In the following example, the custom component **ReusableChildComponent** can pass reuse and recycle events to its nested custom component **ChildComponent3**. However, these events cannot automatically reach another custom component, **ChildComponent2**, as it is separated by a BuilderNode. To enable reuse for **ChildComponent2**, you must explicitly call the **reuse** and **recycle** APIs on the BuilderNode to forward these events to the component.

![en-us_image_reuse-recycle](figures/reuse-recycle.png)


```ts
import { FrameNode, NodeController, BuilderNode, UIContext } from "@kit.ArkUI";

const TEST_TAG: string = "Reuse+Recycle";

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
  Row() {
    Text(`C${param.item} -- `)
    ChildComponent2({ item: param.item }) // This custom component cannot be correctly reused in the BuilderNode.
  }
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

// The custom component that is reused and recycled will have its state variables updated, and the state variables of the nested ChildComponent3 will also be updated. However, the BuilderNode will block this propagation process.
@Reusable
@Component
struct ReusableChildComponent {
  @Prop item: string = '';
  @Prop switch: string = '';
  private controller: MyNodeController = new MyNodeController();

  aboutToAppear() {
    this.controller.item = this.item;
  }

  aboutToRecycle(): void {
    console.log(`${TEST_TAG} ReusableChildComponent aboutToRecycle ${this.item}`);

    // When the switch is open, pass the recycle event to the nested custom component, such as ChildComponent2, through the BuilderNode's recycle API to complete recycling.
    if (this.switch === 'open') {
      this.controller?.builderNode?.recycle();
    }
  }

  aboutToReuse(params: object): void {
    console.log(`${TEST_TAG} ReusableChildComponent aboutToReuse ${JSON.stringify(params)}`);

    // When the switch is open, pass the reuse event to the nested custom component, such as ChildComponent2, through the BuilderNode's reuse API to complete reuse.
    if (this.switch === 'open') {
      this.controller?.builderNode?.reuse(params);
    }
  }

  build() {
    Row() {
      Text(`A${this.item}--`)
      ChildComponent3({ item: this.item })
      NodeContainer(this.controller);
    }
  }
}

@Component
struct ChildComponent2 {
  @Prop item: string = "false";

  aboutToReuse(params: Record<string, object>) {
    console.log(`${TEST_TAG} ChildComponent2 aboutToReuse ${JSON.stringify(params)}`);
  }

  aboutToRecycle(): void {
    console.log(`${TEST_TAG} ChildComponent2 aboutToRecycle ${this.item}`);
  }

  build() {
    Row() {
      Text(`D${this.item}`)
        .fontSize(20)
        .backgroundColor(Color.Yellow)
        .margin({ left: 10 })
    }.margin({ left: 10, right: 10 })
  }
}

@Component
struct ChildComponent3 {
  @Prop item: string = "false";

  aboutToReuse(params: Record<string, object>) {
    console.log(`${TEST_TAG} ChildComponent3 aboutToReuse ${JSON.stringify(params)}`);
  }

  aboutToRecycle(): void {
    console.log(`${TEST_TAG} ChildComponent3 aboutToRecycle ${this.item}`);
  }

  build() {
    Row() {
      Text(`B${this.item}`)
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
    for (let i = 0; i < 100; i++) {
      this.data.pushData(i.toString());
    }
  }

  build() {
    Column() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            ReusableChildComponent({
              item: item,
              switch: 'open' // Changing open to close can be used to observe the behavior of custom components inside the BuilderNode when reuse and recycle events are not passed through the BuilderNode's reuse and recycle APIs.
            })
          }
        }, (item: string) => item)
      }
      .width('100%')
      .height('100%')
    }
  }
}
```


## Using the @Reusable Decorator with BuilderNode Child Components

The reuse mechanism of **BuilderNode** is fundamentally incompatible with the component reuse behavior enabled by the [@Reusable](./state-management/arkts-reusable.md) decorator. Therefore, when a BuilderNode contains a custom component as its child nodes, that component cannot be decorated with @Reusable. Attempting to do so will trigger a JS crash. To use the @Reusable decorator, first wrap the target custom component with a regular custom component.

In the following example, when **ReusableChildComponent** serves as a direct child of the BuilderNode, it cannot be decorated with @Reusable. By wrapping it with **ChildComponent2**, **ReusableChildComponent** can then safely use the @Reusable decorator.

![BuilderNode-Reusable](figures/BuilderNode-Reusable.png)

```ts
import { FrameNode, NodeController, BuilderNode, UIContext } from '@kit.ArkUI';

const TEST_TAG: string = "Reusable";

class Params {
  item: string = '';

  constructor(item: string) {
    this.item = item;
  }
}

@Builder
function buildNode(param: Params = new Params("Hello")) {
  ChildComponent2({ item: param.item })
  // If ReusableChildComponent is used directly, a compilation error is reported.
  // ReusableChildComponent({ item: param.item })
}

class MyNodeController extends NodeController {
  public builderNode: BuilderNode<[Params]> | null = null;
  public item: string = "";

  constructor(item: string) {
    super();
    this.item = item;
  }

  makeNode(uiContext: UIContext): FrameNode | null {
    if (this.builderNode == null) {
      this.builderNode = new BuilderNode(uiContext, { selfIdealSize: { width: 300, height: 200 } });
      this.builderNode.build(wrapBuilder<[Params]>(buildNode), new Params(this.item));
    }
    return this.builderNode.getFrameNode();
  }
}

// This custom component is decorated with @Reusable and therefore cannot be directly mounted as a child node of the BuilderNode.
@Reusable
@Component
struct ReusableChildComponent {
  @Prop item: string = '';

  aboutToReuse(params: object): void {
    console.log(`${TEST_TAG} ReusableChildComponent aboutToReuse ${JSON.stringify(params)}`);
  }

  aboutToRecycle(): void {
    console.log(`${TEST_TAG} ReusableChildComponent aboutToRecycle ${this.item}`);
  }

  build() {
    Text(`A--${this.item}`)
  }
}

// Custom component not decorated with @Reusable
@Component
struct ChildComponent2 {
  @Prop item: string = "";

  aboutToReuse(params: Record<string, object>) {
    console.log(`${TEST_TAG} ChildComponent2 aboutToReuse ${JSON.stringify(params)}`);
  }

  aboutToRecycle(): void {
    console.log(`${TEST_TAG} ChildComponent2 aboutToRecycle ${this.item}`);
  }

  build() {
    ReusableChildComponent({ item: this.item })
  }
}


@Entry
@Component
struct Index {
  @State controller: MyNodeController = new MyNodeController("Child");

  build() {
    Column() {
      NodeContainer(this.controller)
    }
    .width('100%')
    .height('100%')
  }
}
```

## Updating Nodes Based on System Environment Changes

Use the [updateConfiguration](../reference/apis-arkui/js-apis-arkui-builderNode.md#updateconfiguration12) API to listen for [system environment changes](../reference/apis-ability-kit/js-apis-app-ability-configuration.md). This will trigger a full update of all nodes within the BuilderNode.

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

## Cross-Page Reuse Considerations

With use of [routing](../reference/apis-arkui/arkts-apis-uicontext-router.md) APIs such as [router.replaceUrl](../reference/apis-arkui/arkts-apis-uicontext-router.md#replaceurl), [router.back](../reference/apis-arkui/arkts-apis-uicontext-router.md#back), [router.clear](../reference/apis-arkui/arkts-apis-uicontext-router.md#clear), and [router.replaceNamedRoute](../reference/apis-arkui/arkts-apis-uicontext-router.md#replacenamedroute) to navigate between pages, issues may arise when you reuse a cached BuilderNode from a page that is about to be destroyed. Specifically, the reused BuilderNode might not update its data correctly, or newly created nodes might not display as expected. For example, when you use [router.replaceNamedRoute](../reference/apis-arkui/arkts-apis-uicontext-router.md#replacenamedroute), consider the following scenario: When the **router replace** button is clicked, the page switches to PageTwo, and the flag **isShowText** is set to **false**.

```ts
// ets/pages/Index.ets
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI";
import "ets/pages/PageTwo"

@Builder
function buildText() {
  // Use syntax nodes to generate a BuilderProxyNode within @Builder.
  if (true) {
    MyComponent()
  }
}

@Component
struct MyComponent {
  @StorageLink("isShowText") isShowText: boolean = true;

  build() {
    if (this.isShowText) {
      Column() {
        Text("BuilderNode Reuse")
          .fontSize(36)
          .fontWeight(FontWeight.Bold)
          .padding(16)
      }
    }
  }
}

class TextNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private textNode: BuilderNode<[]> | null = null;

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);

    if (AppStorage.has("textNode")) {
      // Reuse the BuilderNode from AppStorage.
      this.textNode = AppStorage.get<BuilderNode<[]>>("textNode") as BuilderNode<[]>;
      const parent = this.textNode.getFrameNode()?.getParent();
      if (parent) {
        parent.removeChild(this.textNode.getFrameNode());
      }
    } else {
      this.textNode = new BuilderNode(context);
      this.textNode.build(wrapBuilder<[]>(buildText));
      // Save the created BuilderNode to AppStorage.
      AppStorage.setOrCreate<BuilderNode<[]>>("textNode", this.textNode);
    }
    this.rootNode.appendChild(this.textNode.getFrameNode());

    return this.rootNode;
  }
}

@Entry({ routeName: "myIndex" })
@Component
struct Index {
  aboutToAppear(): void {
    AppStorage.setOrCreate<boolean>("isShowText", true);
  }

  build() {
    Row() {
      Column() {
        NodeContainer(new TextNodeController())
          .width('100%')
          .backgroundColor('#FFF0F0F0')
        Button('Router pageTwo')
          .onClick(() => {
            // Change the state variable in AppStorage to trigger re-creation of the Text node.
            AppStorage.setOrCreate<boolean>("isShowText", false);

            this.getUIContext().getRouter().replaceNamedRoute({ name: "pageTwo" });
          })
          .margin({ top: 16 })
      }
      .width('100%')
      .height('100%')
      .padding(16)
    }
    .height('100%')
  }
}
```

The implementation of **PageTwo** is as follows:

```ts
// ets/pages/PageTwo.ets
// This page contains a button to navigate back to the home page, where the original text disappears.
import "ets/pages/Index"

@Entry({ routeName: "pageTwo" })
@Component
struct PageTwo {
  build() {
    Column() {
      Button('Router replace to index')
        .onClick(() => {
          this.getUIContext().getRouter().replaceNamedRoute({ name: "myIndex" });
        })
    }
    .height('100%')
    .width('100%')
    .alignItems(HorizontalAlign.Center)
    .padding(16)
  }
}
```

![BuilderNode Reuse Example](./figures/builder_node_reuse.gif)

In versions earlier than API version 16, you need to manually remove the BuilderNode from the cache, AppStorage in this example, when the page is destroyed.

Since API version 16, the BuilderNode automatically refreshes its content when reused in a new page. This means you no longer need to remove the BuilderNode from the cache when the page is destroyed.

```ts
// ets/pages/Index.ets
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI";
import "ets/pages/PageTwo"

@Builder
function buildText() {
  // Use syntax nodes to generate a BuilderProxyNode within @Builder.
  if (true) {
    MyComponent()
  }
}

@Component
struct MyComponent {
  @StorageLink("isShowText") isShowText: boolean = true;

  build() {
    if (this.isShowText) {
      Column() {
        Text("BuilderNode Reuse")
          .fontSize(36)
          .fontWeight(FontWeight.Bold)
          .padding(16)
      }
    }
  }
}

class TextNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private textNode: BuilderNode<[]> | null = null;

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);

    if (AppStorage.has("textNode")) {
      // Reuse the BuilderNode from AppStorage.
      this.textNode = AppStorage.get<BuilderNode<[]>>("textNode") as BuilderNode<[]>;
      const parent = this.textNode.getFrameNode()?.getParent();
      if (parent) {
        parent.removeChild(this.textNode.getFrameNode());
      }
    } else {
      this.textNode = new BuilderNode(context);
      this.textNode.build(wrapBuilder<[]>(buildText));
      // Save the created BuilderNode to AppStorage.
      AppStorage.setOrCreate<BuilderNode<[]>>("textNode", this.textNode);
    }
    this.rootNode.appendChild(this.textNode.getFrameNode());

    return this.rootNode;
  }
}

@Entry({ routeName: "myIndex" })
@Component
struct Index {
  aboutToAppear(): void {
    AppStorage.setOrCreate<boolean>("isShowText", true);
  }

  build() {
    Row() {
      Column() {
        NodeContainer(new TextNodeController())
          .width('100%')
          .backgroundColor('#FFF0F0F0')
        Button('Router pageTwo')
          .onClick(() => {
            // Change the state variable in AppStorage to trigger re-creation of the Text node.
            AppStorage.setOrCreate<boolean>("isShowText", false);
            // Remove the BuilderNode from AppStorage.
            AppStorage.delete("textNode");

            this.getUIContext().getRouter().replaceNamedRoute({ name: "pageTwo" });
          })
          .margin({ top: 16 })
      }
      .width('100%')
      .height('100%')
      .padding(16)
    }
    .height('100%')
  }
}
```


## Using the LocalStorage in the BuilderNode

Since API version 12, custom components can receive [LocalStorage](../ui/state-management/arkts-localstorage.md) instances. You can use LocalStorage related decorators such as [@LocalStorageProp](../ui/state-management/arkts-localstorage.md#localstorageprop) and [@LocalStorageLink](../ui/state-management/arkts-localstorage.md#localstoragelink) by [passing LocalStorage instances](../ui/state-management/arkts-localstorage.md#example-of-providing-a-custom-component-with-access-to-a-localstorage-instance).

```ts
import { BuilderNode, NodeController, UIContext } from '@kit.ArkUI';

let localStorage1: LocalStorage = new LocalStorage();
localStorage1.setOrCreate('PropA', 'PropA');

let localStorage2: LocalStorage = new LocalStorage();
localStorage2.setOrCreate('PropB', 'PropB');

@Entry(localStorage1)
@Component
struct Index {
  // PropA is in two-way synchronization with PropA in localStorage1.
  @LocalStorageLink('PropA') PropA: string = 'Hello World';
  @State count: number = 0;
  private controller: NodeController = new MyNodeController(this.count, localStorage2);

  build() {
    Row() {
      Column() {
        Text(this.PropA)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        // Use the LocalStorage instance localStorage2.
        Child({ count: this.count }, localStorage2)
        NodeContainer(this.controller)
      }
      .width('100%')
    }
    .height('100%')
  }
}

interface Params {
  count: number;
  localStorage: LocalStorage;
}

@Builder
function CreateChild(params: Params) {
  // Pass localStorage during construction.
  Child({ count: params.count }, params.localStorage)
}

class MyNodeController extends NodeController {
  private count?: number;
  private localStorage ?: LocalStorage;

  constructor(count: number, localStorage: LocalStorage) {
    super();
    this.count = count;
    this.localStorage = localStorage;
  }

  makeNode(uiContext: UIContext): FrameNode | null {
    let builderNode = new BuilderNode<[Params]>(uiContext);
    // Pass localStorage during construction.
    builderNode.build(wrapBuilder(CreateChild), { count: this.count, localStorage: this.localStorage });
    return builderNode.getFrameNode();
  }
}

@Component
struct Child {
  @Prop count: number;
  // 'Hello World' is in two-way synchronization with 'PropB' in localStorage2. If there is no 'PropB' in localStorage2, the default value 'Hello World' is used.
  @LocalStorageLink('PropB') PropB: string = 'Hello World';

  build() {
    Text(this.PropB)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```

## Checking BuilderNode Reference Status

All frontend nodes are bound to corresponding backend entity nodes. After **dispose()** is called, subsequent calls may cause crashes or return default values.

Since API version 20, you can use the [isDisposed](../reference/apis-arkui/js-apis-arkui-builderNode.md#isdisposed20) API to check whether a **BuilderNode** object has released its reference to backend entity nodes. This enables validation before node operations to prevent potential risks.

```ts
import { NodeController, FrameNode, BuilderNode } from '@kit.ArkUI';

@Builder
function buildText() {
  Text("Test")
    .fontSize(20)
    .fontWeight(FontWeight.Bold)
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private builderNode: BuilderNode<[]> | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.rootNode.commonAttribute.width(100).height(100).backgroundColor(Color.Pink);
    this.builderNode = new BuilderNode<[]>(uiContext);
    this.builderNode.build(wrapBuilder<[]>(buildText));

    // Mount the BuilderNode.
    this.rootNode.appendChild(this.builderNode.getFrameNode());
    return this.rootNode;
  }

  disposeBuilderNode() {
    // Remove the reference relationship between the BuilderNode and backend entity nodes.
    this.builderNode?.dispose();
  }

  isDisposed() : string {
    if (this.builderNode !== null) {
      // Check BuilderNode reference status.
      if (this.builderNode.isDisposed()) {
        return 'builderNode isDisposed is true';
      }
      else {
        return 'builderNode isDisposed is false';
      }
    }
    return 'builderNode is null';
  }
}

@Entry
@Component
struct Index {
  @State text: string = ''
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column({ space: 4 }) {
      NodeContainer(this.myNodeController)
      Button('BuilderNode dispose')
        .onClick(() => {
          this.myNodeController.disposeBuilderNode();
          this.text = '';
        })
        .width(200)
        .height(50)
      Button('BuilderNode isDisposed')
        .onClick(() => {
          this.text = this.myNodeController.isDisposed();
        })
        .width(200)
        .height(50)
      Text(this.text)
        .fontSize(25)
    }
    .width('100%')
    .height('100%')
  }
}
```

## Configuring BuilderNode Freeze Inheritance

ArkUI supports [custom component freezing](./state-management/arkts-custom-components-freeze.md), which suspends refresh capabilities for inactive components. When frozen, components will not trigger UI re-rendering even if bound state variables change, reducing refresh load in complex UI scenarios.

Since API version 20, a BuilderNode can inherit freeze policies from its parent custom component (the first custom component found when traversing up from the BuilderNode) using the [inheritFreezeOptions](../reference/apis-arkui/js-apis-arkui-builderNode.md#inheritfreezeoptions20) API. When freeze inheritance is enabled: If the parent component has freezing enabled ([freezeWhenInactive](./state-management/arkts-create-custom-components.md#freezewheninactive11) set to **true**), the BuilderNode will freeze when inactive and thaw when active, and update using cached data upon reactivation.

The BuilderNode has its freeze policy updated only during the tree operations listed below.

| Class| API|
| -------- | -------- |
| [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) | [appendChild](../reference/apis-arkui/js-apis-arkui-frameNode.md#appendchild12), [insertChildAfter](../reference/apis-arkui/js-apis-arkui-frameNode.md#insertchildafter12), [removeChild](../reference/apis-arkui/js-apis-arkui-frameNode.md#removechild12), [clearChildren](../reference/apis-arkui/js-apis-arkui-frameNode.md#clearchildren12), [addComponentContent](../reference/apis-arkui/js-apis-arkui-frameNode.md#addcomponentcontent12)|
| [NodeContent](../reference/apis-arkui/js-apis-arkui-NodeContent.md) | [addFrameNode](../reference/apis-arkui/js-apis-arkui-NodeContent.md#addframenode12), [removeFrameNode](../reference/apis-arkui/js-apis-arkui-NodeContent.md#removeframenode12)|
| [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) | [makeNode](../reference/apis-arkui/js-apis-arkui-nodeController.md#makenode) |
| [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md) | [appendChild](../reference/apis-arkui/js-apis-arkui-renderNode.md#appendchild), [insertChildAfter](../reference/apis-arkui/js-apis-arkui-renderNode.md#insertchildafter), [removeChild](../reference/apis-arkui/js-apis-arkui-renderNode.md#removechild), [clearChildren](../reference/apis-arkui/js-apis-arkui-renderNode.md#clearchildren)|
| [NodeAdaper](../reference/apis-arkui/js-apis-arkui-frameNode.md#nodeadapter12) | Lazy loading operations using [LazyForEach](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md)|

> **NOTE**
>
> When freeze inheritance is enabled, the BuilderNode's freeze policy stays synchronized with its nearest parent (custom component or BuilderNode).
>
> Frozen BuilderNodes ignore [update](../reference/apis-arkui/js-apis-arkui-builderNode.md#update) calls. Requested node updates occur only after thawing.

```ts

import { BuilderNode, FrameNode, NodeController } from '@kit.ArkUI';

class Params {
  count: number = 0;

  constructor(count: number) {
    this.count = count;
  }
}

@Builder
function buildText(params: Params) {

  Column() {
    TextBuilder({ message: params.count })
  }
}

class TextNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private textNode: BuilderNode<[Params]> | null = null;
  private count: number = 0;

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);
    this.textNode = new BuilderNode(context, { selfIdealSize: { width: 150, height: 150 } });
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.count));
    this.textNode.inheritFreezeOptions(true); // Configure the BuilderNode to inherit the freeze policy from its parent component.
    if (this.rootNode !== null) {
      this.rootNode.appendChild(this.textNode.getFrameNode()); // Mount the BuilderNode to the component tree.
    }
    return this.rootNode;
  }

  update(): void {
    if (this.textNode !== null) {
      this.count += 1;
      this.textNode.update(new Params(this.count)); // Update the BuilderNode data, which triggers logs.
    }

  }
}

const textNodeController: TextNodeController = new TextNodeController();

@Entry
@Component
struct MyNavigationTestStack {
  @Provide('pageInfo') pageInfo: NavPathStack = new NavPathStack();
  @State message: number = 0;
  @State logNumber: number = 0;

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      pageOneStack({ message: this.message, logNumber: this.logNumber })
    } else if (name === 'pageTwo') {
      pageTwoStack({ message: this.message, logNumber: this.logNumber })
    }
  }

  build() {
    Column() {
      Button('update builderNode') // Clicking the button updates builderNode.
        .onClick(() => {
          textNodeController.update();
        })
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
    }
  }
}

@Component
struct pageOneStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @State index: number = 1;
  @Link message: number;
  @Link logNumber: number;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index, logNumber: this.logNumber })
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pop();
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct pageTwoStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @State index: number = 2;
  @Link message: number;
  @Link logNumber: number;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index, logNumber: this.logNumber })
        Text('BuilderNode is frozen')
          .fontWeight(FontWeight.Bold)
          .margin({ top: 48, bottom: 48 })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pop();
          })
      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component({ freezeWhenInactive: true }) // Set the freeze policy to freeze when inactive.
struct NavigationContentMsgStack {
  @Link message: number;
  @Link index: number;
  @Link logNumber: number;

  build() {
    Column() {
      if (this.index === 1) {
        NodeContainer(textNodeController)
      }
    }
  }
}

@Component({ freezeWhenInactive: true }) // Set the freeze policy to freeze when inactive.
struct TextBuilder {
  @Prop @Watch("info") message: number = 0;

  info() {
    console.info(`freeze-test TextBuilder message callback ${this.message}`); // Print logs based on the message content change to determine whether the freeze occurs.
  }

  build() {
    Row() {
      Column() {
        Text(`Update count: ${this.message}`)
          .fontWeight(FontWeight.Bold)
          .margin({ top: 48, bottom: 48 })
      }
    }
  }
}
```



## Configuring the BuilderNode for Cross-Boundary @Provide-@Consume Communication

Since API version 20, the BuilderNode supports cross-boundary state sharing between [@Consume](./state-management/arkts-provide-and-consume.md) and [@Provide](./state-management/arkts-provide-and-consume.md) through the **BuildOptions** configuration. This feature enables seamless data flow from the host pages into BuilderNode's internal custom components.

For implementation, see [Example](../reference/apis-arkui/js-apis-arkui-builderNode.md#example-7-configuring-the-buildernode-for-cross-boundary-provide-consume-communication).

## Implementing Page Pre-Rendering with BuilderNode and Web Components

Pre-rendering is particularly suitable for scenarios such as web page initialization and navigation transitions. By integrating with BuilderNode, **Web** components can be pre-rendered offline in advance. These components are not mounted to the page immediately, but rather dynamically attached and displayed through **NodeController** when needed. This approach significantly enhances page transition smoothness and improves user experience.

> **NOTE**
>
> The **ohos.permission.INTERNET** permission is required for accessing online web pages. For details about how to apply for a permission, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

1. Create a host ability and a **Web** component.
   ```ts
   // Host ability
   // EntryAbility.ets
   import { createNWeb } from "../pages/common";
   import { UIAbility } from '@kit.AbilityKit';
   import { window } from '@kit.ArkUI';
   
   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage): void {
       windowStage.loadContent('pages/Index', (err, data) => {
         // Create a dynamic Web component with UIContext. The component can be created at any time after loadContent() is called.
         createNWeb("https://www.example.com", windowStage.getMainWindowSync().getUIContext());
         if (err.code) {
           return;
         }
       });
     }
   }
   ```
2. Create a NodeContainer and the corresponding NodeController for background rendering.

    ```ts
    // Create a NodeController instance.
    // common.ets
    import { UIContext } from '@kit.ArkUI';
    import { webview } from '@kit.ArkWeb';
    import { NodeController, BuilderNode, Size, FrameNode }  from '@kit.ArkUI';
    // @Builder content for dynamic component content
    // Data class for input parameters
    class Data{
      url: string = 'https://www.example.com';
      controller: WebviewController = new webview.WebviewController();
    }
    // Use the Boolean variable shouldInactive to stop rendering after the web page is pre-rendered in the background.
    let shouldInactive: boolean = true;
    @Builder
    function WebBuilder(data:Data) {
      Column() {
        Web({ src: data.url, controller: data.controller })
          .onPageBegin(() => {
            // Call onActive to enable rendering.
            data.controller.onActive();
          })
          .onFirstMeaningfulPaint(() =>{
            if (!shouldInactive) {
              return;
            }
            // Triggered when the pre-rendering is complete to stop rendering.
            data.controller.onInactive();
            shouldInactive = false;
          })
          .width("100%")
          .height("100%")
      }
    }
    let wrap = wrapBuilder<Data[]>(WebBuilder);
    // The NodeController instance must be used with a NodeContainer for controlling and feeding back the behavior of the nodes in the NodeContainer.
    export class myNodeController extends NodeController {
      private rootnode: BuilderNode<Data[]> | null = null;
      // This function must be overridden, which is used to construct the number of nodes and return nodes to be mounted in NodeContainer.
      // Called when the corresponding NodeContainer is created or called by the rebuild method.
      makeNode(uiContext: UIContext): FrameNode | null {
        console.info(" uicontext is undifined : "+ (uiContext === undefined));
        if (this.rootnode != null) {
          // Return the FrameNode object.
          return this.rootnode.getFrameNode();
        }
        // Return null to detach the dynamic component from the bound node.
        return null;
      }
      // Called when the layout size changes.
      aboutToResize(size: Size) {
        console.info("aboutToResize width : " + size.width  +  " height : " + size.height );
      }
      // Called when the NodeContainer bound to the controller is about to appear.
      aboutToAppear() {
        console.info("aboutToAppear");
        // Keep rendering active when the page is brought to the foreground.
        shouldInactive = false;
      }
      // Called when the NodeContainer bound to the controller is about to disappear.
      aboutToDisappear() {
        console.info("aboutToDisappear");
      }
      // This function is a custom function and can be used for initialization.
      // Initialize the BuilderNode through UIContext, and then initialize the content in @Builder through the build API in BuilderNode.
      initWeb(url:string, uiContext:UIContext, control:WebviewController) {
        if(this.rootnode != null){
          return;
        }
        // Create a node, during which the UIContext should be passed.
        this.rootnode = new BuilderNode(uiContext);
        // Create a dynamic Web component.
        this.rootnode.build(wrap, { url:url, controller:control });
      }
    }
    // Create a Map to store the required NodeController instance.
    let NodeMap:Map<string, myNodeController | undefined> = new Map();
    // Create a Map to store the required WebViewController instance.
    let controllerMap:Map<string, WebviewController | undefined> = new Map();
    // UIContext is required for initialization and needs to be obtained from the ability.
    export const createNWeb = (url: string, uiContext: UIContext) => {
      // Create a NodeController instance.
      let baseNode = new myNodeController();
      let controller = new webview.WebviewController() ;
      // Initialize the custom Web component.
      baseNode.initWeb(url, uiContext, controller);
      controllerMap.set(url, controller);
      NodeMap.set(url, baseNode);
    }
    // Customize the API for obtaining the NodeController instance.
    export const getNWeb = (url : string) : myNodeController | undefined => {
      return NodeMap.get(url);
    }
    ```
3. Display the pre-rendered page through **NodeContainer**.

    ```ts
    // Page component using NodeController
    // Index.ets
    import { createNWeb, getNWeb } from "./common";
      
    @Entry
    @Component
    struct Index {
      build() {
        Row() {
          Column() {
            // NodeContainer is used to bind to the NodeController. A rebuild call triggers makeNode.
            // The Page page is bound to the NodeController through the NodeContainer API to display the dynamic component.
            NodeContainer(getNWeb("https://www.example.com"))
              .height("90%")
              .width("100%")
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```
<!--no_check-->