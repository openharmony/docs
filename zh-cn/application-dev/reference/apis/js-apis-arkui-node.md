# @ohos.arkui.node 

Node将自定义节点中涉及的API进行汇总，方便开发者进行导出使用。提供了自定义节点BuidlerNode的创建接口。提供了NodeController的相关接口，用于实现自定义节点的显示、更新等操作的管理。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## UIContext获取方法
1.使用ohos.window中的[getUIContext()](./js-apis-window.md#getuicontext10)方法获取UIContext实例。

2.可以通过自定义组件内置方法[getUIContext()](../arkui-ts/ts-custom-component-api.md#getuicontext)获取。

3.可以在[NodeController](#nodecontroller)的[makeNode](#makenode)回调方法中获取。

## BaseNode

作为自定义节点的基类对象，为子类提供公共的构造函数。不支持定义为状态变量。

### constructor

constructor(uiContext: [UIContext](./js-apis-arkui-UIContext.md))

BaseNode的构造函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型      | 必填 | 说明                               |
| --------- | --------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时候所需要的UI上下文。 |


**示例：**

```ts
new BaseNode(uicontext); // uiContext is the UIContext used to create the BaseNode.
```

## BuilderNode<Args extends Object[]>

继承自[BaseNode](#basenode)。Builder类型的BaseNode，支持通过无状态的UI方法[@Builder](../../quick-start/arkts-builder.md)生成组件树，并持有组件树的根节点。

### build

build(builder: WrappedBuilder<Args>, arg?: Object): void

依照传入的对象创建组件树，并持有组件树的根节点。无状态的UI方法[@Builder](../../quick-start/arkts-builder.md)最多拥有一个根节点。
支持自定义组件。不支持使用自定义组件使用[@Reusable](../../quick-start/arkts-create-custom-components.md#自定义组件的基本结构)、[@Link](../../quick-start/arkts-link.md)、[@Prop](../../quick-start/arkts-prop.md)、[@Provide](../../quick-start/arkts-provide-and-consume.md)、[@Consume](../../quick-start/arkts-provide-and-consume.md)等装饰器用于当前页面与自定义组件的状态同步。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                   | 必填 | 说明                                                                                     |
| ------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------- |
| builder | WrappedBuilder<Args> | 是   | 创建对应节点树的时候所需的无状态UI方法[@Builder](../../quick-start/arkts-builder.md)。 |
| arg     | Object                 | 否   | 对象，作为builder的入参使用。                                      |

**示例：**

```ts
declare class Params{
  text:string
}

@Builder
function buttonBuilder(params : Params)
{
  Column()
  {
    Button(`button ` + params.text )
      .borderWidth(2)
      .backgroundColor(Color.Orange)
  }
}

let wrapBuilder  = new WrappedBuilder(buttonBuilder);
let rootNode = new BuilderNode(uiContext); // uiContext is the UIContext used to create the BuilderNode.
rootNode.build(wrapBuilder,{text:"update"})

```

### postTouchEvent

postTouchEvent(event: TouchEvent): boolean

将原始事件派发到某个BuilderNode创建出的FrameNode上。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                   | 必填 | 说明                                                                                     |
| ------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------- |
| event | [TouchEvent](../arkui-ts/ts-universal-events-touch.md#touchevent对象说明) | 是   | 触摸事件。 |

**返回值：**

| 类型     | 说明                                                              |
| -------- | ----------------------------------------------------------------- |
| boolean | 派发事件是否成功。 |

**示例：**

```ts
import { UIContext } from '@ohos.arkui.UIContext';
import { NodeController, BuilderNode, FrameNode } from '@ohos.arkui.node';

class Params {
  text: string = "this is a text"
}

@Builder
function ButtonBuilder(Params: Params) {
  Column() {
    Button(`button ` + Params.text)
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

class myNodeController extends NodeController {
  private rootnode: BuilderNode<Params[]> = null;
  private wrapBuilder = new WrappedBuilder(ButtonBuilder);

  makeNode(uiContext: UIContext): FrameNode | null {
    if (this.rootnode == null) {
      this.rootnode = new BuilderNode(uiContext);
      this.rootnode.build(this.wrapBuilder, { text: "this is a string" })
    }
    return this.rootnode.getFrameNode();
  }

  getBuilderNode(): FrameNode {
    return this.rootnode.getFrameNode();
  }

  setBuilderNode(rootNode: BuilderNode<Params[]>): void {
    this.rootnode = rootNode;
  }
}

@Entry
@Component
struct MyComponent {
  private rootnode: BuilderNode<Params[]> = null;
  private nodeController: myNodeController = new myNodeController()
  private wrapBuilder = new WrappedBuilder(ButtonBuilder);

  aboutToAppear() {
    this.rootnode = new BuilderNode(this.getUIContext());
    this.rootnode.build(this.wrapBuilder, { text: "this is a string" })
    this.nodeController.setBuilderNode(this.rootnode)
    this.nodeController.rebuild()
  }

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
          let result = this.rootnode.postTouchEvent(event)
          console.log("result " + result);
        })
    }
  }
}

```


## Size

用于返回组件布局大小的宽和高，单位为vp。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| width  | number | 是   | Size的宽度，单位为vp。 |
| height | number | 是   | Size的高度，单位为vp。 |


## NodeController

通常搭配[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)进行使用。用于创建控制器管理绑定的[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)组件。一个NodeController只允许与一个[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)进行绑定。



**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### makeNode

abstract makeNode(uiContext : UIContext): BaseNode | null

当实例绑定的[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)创建的时候进行回调。回调方法将返回一个节点，将该节点挂载至[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)。
或者可以通过NodeConroller的rebuild()方法进行回调的触发。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型      | 必填 | 说明                                        |
| --------- | --------- | ---- | ------------------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 回调该方法的绑定的[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)的UI上下文。 |

**返回值：**

| 类型     | 说明                                                              |
| -------- | ----------------------------------------------------------------- |
| BaseNode | 一个BaseNode对象，返回的节点将被挂载至[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)的占位节点上。 |
| null     | null对象，返回空将会将对应[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)的子节点清空。             |

### aboutToAppear

aboutToAppear?(): void

当NodeController绑定的[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)挂载显示时触发此回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### aboutToDisappear

aboutToDisappear?(): void

当NodeController绑定的[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)卸载消失时触发此回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### aboutToResize

aboutToResize?(size: Size): void

当NodeController绑定的[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)布局的时候触发此回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明                                     |
| ------ | ------------- | ---- | ---------------------------------------- |
| size   | [Size](#size) | 是   | 用于返回组件布局大小的宽和高，单位为vp。 |

### onTouchEvent

onTouchEvent?(event: TouchEvent): void

当NodeController绑定的[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)收到Touch事件时触发此回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                   | 必填 | 说明                                                                                     |
| ------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------- |
| event | [TouchEvent](../arkui-ts/ts-universal-events-touch.md#touchevent对象说明) | 是   | 触摸事件。 |

### rebuild

rebuild(): void

调用此接口通知[NodeContainer](../arkui-ts/ts-basic-components-nodecontainer.md#nodecontanier)组件重新回调[makeNode](#makenode)方法，更改子节点。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 示例

```ts
import { UIContext } from '@ohos.arkui.UIContext';
import { NodeController,BuilderNode, Size, BaseNode }  from '@ohos.arkui.node';

class Params{
  text:string = "this is a text"
}


@Builder
function buttonBuilder(params:Params)
{
  Column()
  {
    Button(`button ` + params.text )
      .borderWidth(2)
      .backgroundColor(Color.Orange)
  }
}

class MyNodeController extends NodeController {
  private rootNode :BuilderNode<Params[]> | null= null;
  private wrapBuilder  = new WrappedBuilder(buttonBuilder);

  makeNode(uiContext:UIContext) : BaseNode | null
  {
    if(this.rootNode == null)
    {
      this.rootNode = new BuilderNode(uiContext);
      this.rootNode.build(this.wrapBuilder,{ text:"this is a string" })
    }
    return this.rootNode;
  }

  aboutToResize(size:Size)
  {
    console.log("aboutToResize width : "+ size.width  +  " height : " + size.height )
  }

  aboutToAppear()
  {
    console.log("aboutToAppear")
  }

  aboutToDisappear()
  {
    console.log("aboutToDisappear");
  }

  update()
  {
    if(this.rootNode == null)
    {
      return;
    }
    this.rootNode.build(this.wrapBuilder, { text:"this is a update string" })
    this.rebuild();
  }

  onTouchEvent(event:TouchEvent)
  {
    console.log("onTouchEvent");
  }
}


@Entry
@Component
struct Index {
  @State myNodeController :MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
        .onClick(()=>{
          this.myNodeController.update();
        })
    }
  }
}


```
