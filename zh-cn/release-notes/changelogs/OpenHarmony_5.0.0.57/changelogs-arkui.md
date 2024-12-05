# ArkUI子系统Changelog

## cl.arkui.1 FrameNode的isAttached接口返回值含义发生变更

**访问级别**

公开接口

**变更原因**

用户使用FrameNode的isAttached接口时，实际返回当前节点是否可见，即通用属性中的Visibility是否为Visible，而非当前节点是否被挂载到主节点树上。

**变更影响**

该变更为不兼容变更。

变更前：返回当前节点是否可见。

变更后：返回当前节点是否被挂载到主节点树上。

不兼容场景：
当用户通过该接口获取目标节点是否被挂载到主节点树上，而目标节点为节点树上的不可见节点或未上树的可见节点时，会出现不兼容情况; 例如：
```ts
import { FrameNode, NodeController } from '@ohos.arkui.node';
import { UIContext } from '@ohos.arkui.UIContext';

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private notAttachedNode: FrameNode | null = null;
  private notVisibleNode: FrameNode | null = null;

  makeNode(uiContext: UIContext) {
    this.rootNode = new FrameNode(uiContext);
    this.notAttachedNode = new FrameNode(uiContext);
    this.notVisibleNode = new FrameNode(uiContext);
    this.notVisibleNode.commonAttribute.visibility(Visibility.Hidden);
    this.rootNode.appendChild(this.notVisibleNode);
    return this.rootNode;
  }

  printInfo(): void {
    if (this.notVisibleNode) {
      // 主节点树上的不可见节点，变更前为false，变更后为true
      console.log('notVisibleNode:', this.notVisibleNode.isAttached());
    }
    if (this.notAttachedNode) {
      // 未上树的可见节点，变更前为true，变更后为false
      console.log('notAttachedNode:', this.notAttachedNode.isAttached());
    }
  }
}

@Entry
@Component
struct MyComponent {
  @State myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
      Button('click').onClick(() => {
        this.myNodeController.printInfo();
      })
    }
    .width('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

FrameNode.d.ts文件isAttached接口。

**适配指导**

```ts
// 变更前FrameNode的isAttached接口行为和isVisible接口一致，若需保持变更前行为，使用isVisible接口替换即可。
node.isAttached(); // 变更前
node.isVisible(); // 变更后
```

## cl.arkui.2 RenderNode的rotation接口角度单位从vp变为度

**访问级别**

公开接口

**变更原因**

用户使用RenderNode的rotation接口时，传入的默认角度单位是vp，这不是正常规格的角度单位，需要变更为度。

**变更影响**

该变更为不兼容变更。

变更前：角度单位为vp，需要经过px2vp单位转换才能转为角度。

变更后：角度单位为度，直接传入数值即可，无需单位转换。

不兼容场景：
当用户通过该接口设置RenderNode的旋转时，会出现不兼容情况; 例如：
```ts
import { FrameNode, NodeController, RenderNode, UIContext } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext) {
    this.rootNode = new FrameNode(uiContext);

    // 直接传入90
    const renderNodeSrc = new RenderNode();
    renderNodeSrc.backgroundColor = 0xffdddddd;
    renderNodeSrc.frame = { x: 10, y: 110, width: 200, height: 100 };
    const renderNodeDst  = new RenderNode();
    renderNodeDst.backgroundColor = 0xfffcc0ea;
    renderNodeDst.frame = { x: 10, y: 110, width: 200, height: 100 };
    renderNodeDst.rotation = { x: 0, y: 0, z: 90 };

    // 传入px2vp(90)
    const renderNodeSrc1 = new RenderNode();
    renderNodeSrc1.backgroundColor = 0xffdddddd;
    renderNodeSrc1.frame = { x: 10, y: 360, width: 200, height: 100 };
    const renderNodeDst1  = new RenderNode();
    renderNodeDst1.backgroundColor = 0xfffcc0ea;
    renderNodeDst1.frame = { x: 10, y: 360, width: 200, height: 100 };
    renderNodeDst1.rotation = { x: 0, y: 0, z: px2vp(90) };

    // 传入vp2px(90)
    const renderNodeSrc2 = new RenderNode();
    renderNodeSrc2.backgroundColor = 0xffdddddd;
    renderNodeSrc2.frame = { x: 10, y: 610, width: 200, height: 100 };
    const renderNodeDst2  = new RenderNode();
    renderNodeDst2.backgroundColor = 0xfffcc0ea;
    renderNodeDst2.frame = { x: 10, y: 610, width: 200, height: 100 };
    renderNodeDst2.rotation = { x: 0, y: 0, z: vp2px(90) };

    const rootRenderNode = this.rootNode.getRenderNode();
    rootRenderNode?.appendChild(renderNodeSrc);
    rootRenderNode?.appendChild(renderNodeDst);
    rootRenderNode?.appendChild(renderNodeSrc1);
    rootRenderNode?.appendChild(renderNodeDst1);
    rootRenderNode?.appendChild(renderNodeSrc2);
    rootRenderNode?.appendChild(renderNodeDst2);

    return this.rootNode;
  }
}

@Entry
@Component
struct MyComponent {
  @State myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      Column() {
        Text('90')
        Text('px2vp(90)')
        Text('vp2px(90)')
      }
      .justifyContent(FlexAlign.SpaceAround)
      .height('100%')
      .width('30%')
      NodeContainer(this.myNodeController)
        .height('100%')
        .width('70%')
    }
    .width('100%')
    .alignItems(VerticalAlign.Top)
  }
}
```

![demoRenderNodeRotation](figures/demoRenderNodeRotation.png)

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.57开始。

**变更的接口/组件**

RenderNode.d.ts文件rotation接口。

**适配指导**

```ts
// 变更前RenderNode的rotation接口的旋转角度单位为“vp”，变更后单位为“度”，若需保持变更前行为，使用vp2px进行单位转换即可。
renderNode.rotation = { x: 0, y: 0, z: 90 }; // 变更前
renderNode.rotation = { x: 0, y: 0, z: vp2px(90) }; // 变更后
```

## cl.arkui.3 List组件首次创建布局时，Scroller控制器的跳转方法优先级变更为高于initialIndex的优先级

**访问级别**

公开接口

**变更原因**

initialIndex仅支持设定起始index，并默认将列表头部对齐，这使得开发者无法自定义对齐策略。scrollToIndex允许指定index与对齐方式，然而其效果会被 initialIndex覆盖。因此，需要提升scrollToIndex的优先级，使其高于initialIndex。这样一来，在组件初次布局时，如果开发者希望设定起始index并同时指定对齐方式，即可通过使用scrollToIndex来达成目标。


**变更影响**

该变更为不兼容变更。

变更前行为：
- List首次布局时如果同时设置了initialIndex和调用滚动控制器的scrollToIndex，会生效initialIndex，不生效scrollToIndex。例如设置initialIndex为0（默认也是0），并在首次布局前调用了scrollToIndex，指定index为1，那么首次布局将从index为0的ListItem开始布局。

- List首次布局时如果同时设置了initialIndex和调用滚动控制器的scrollEdge(Edge.Bottom)，会生效initialIndex，不生效scrollEdge(Edge.Bottom)。例如设置initialIndex为0（默认也是0），并在首次布局前调用了scrollEdge(Edge.Bottom)，那么首次布局将从index为0的ListItem开始布局。

变更后行为：
- 当List在首次布局时，如果同时指定了initialIndex和调用了滚动控制器的scrollToIndex方法，将仅生效initialIndex，而scrollToIndex不会生效。例如，若initialIndex设置为0（这也是默认值），并在首次布局前调用了scrollToIndex方法，指定index为1，那么首次布局依然会从index为0的ListItem开始，而非从index为1开始。

- List首次布局时如果同时设置了initialIndex和调用滚动控制器的scrollEdge(Edge.Bottom)，会生效initialIndex，不生效scrollEdge(Edge.Bottom)。例如设置initialIndex为0（默认也是0），并在首次布局前调用了scrollEdge(Edge.Bottom)，那么首次布局将从List末尾的ListItem从List底部开始向上布局。

**起始API Level**

API 7

**变更发生版本**

从OpenHarmony 5.0.0.57开始。

**变更的接口/组件**

List组件的initialIndex接口和Scroller控制器的跳转接口（scrollToIndex、scrollToItemInGroup和scrollEdge）。

**适配指导**

需要对使用List组件的页面进行排查，检查是否在onAppear或其他List组件首次布局之前的阶段，同时设置了initialIndex并调用了scrollToIndex,、scrollToItemInGroup或scrollEdge接口。在变更后，initialIndex的生效优先级将低于scrollToIndex、scrollToItemInGroup或scrollEdge的优先级。