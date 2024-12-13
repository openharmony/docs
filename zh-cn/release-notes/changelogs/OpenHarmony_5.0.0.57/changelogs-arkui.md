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

场景1：List设置initialIndex为0 (默认也是0)，并在首次布局前调用scrollToIndex(1)。

| 变更前 | 变更后 |
|------ |--------|
|List首次布局将从index为0的ListItem开始布局。</br>![listdemo1](figures/listdemo1.png)|List首次布局将从index为1的ListItem开始布局。</br>![listdemo2](figures/listdemo2.png)|

场景2：List设置initialIndex为0 (默认也是0)，并在首次布局前调用scrollEdge(Edge.Bottom)。

| 变更前 | 变更后 |
|------ |--------|
|List首次布局将展示在顶部，即index为0的ListItem处于顶部。</br>![listdemo1](figures/listdemo1.png)|List首次布局将展示在底部，即index为最大值的ListItem处于底部。</br>![listdemo3](figures/listdemo3.png)|


**起始API Level**

API 7

**变更发生版本**

从OpenHarmony 5.0.0.57开始。

**变更的接口/组件**

List组件的initialIndex接口和Scroller控制器的跳转接口（scrollToIndex、scrollToItemInGroup和scrollEdge）。

**适配指导**

需要对使用List组件的页面进行排查，检查是否在onAppear或其他List组件首次布局之前的阶段，同时设置了initialIndex并调用了scrollToIndex,、scrollToItemInGroup或scrollEdge接口。在变更后，initialIndex的生效优先级将低于scrollToIndex、scrollToItemInGroup或scrollEdge的优先级。

## cl.arkui.4  CanvasRenderingContext2D的drawImage接口联合阴影绘制由阴影无法正确绘制变更为阴影正确绘制

**访问级别**

公开接口

**变更原因**

drawImage同名接口根据传入参数的不同，视为不同方法。当drawImage传入image、dx和dy三个参数，且与阴影颜色（shadowColor）、阴影偏置距离（shadowOffsetX和shadowOffsetY）联合绘制时，阴影无法正确绘制。变更后，阴影可以正确绘制。

**变更影响**

该变更为不兼容变更。

- 变更前：当drawImage接口传入image、dx和dy三个参数，且与阴影进行联合绘制时，阴影无法正确绘制。
- 变更后：当drawImage接口传入image、dx和dy三个参数，且与阴影进行联合绘制时，阴影可以正确绘制。

|               变更前                |              变更后               |
| :---------------------------------: | :-------------------------------: |
| ![](figures/drawImage_without_shadow.jpg) | ![](figures/drawImage_with_shadow.jpg) |

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.57 版本开始。

**变更的接口/组件**

CanvasRenderingContext2D的drawImage接口

**适配指导**

API version 15及以后，使用drawImage接口与阴影进行联合绘制时，阴影能够被正确绘制。

**示例**

```ts
@Entry
@Component
struct Page1 {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  private img: ImageBitmap = new ImageBitmap("common/images/example.png")

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .onReady(() => {
          this.context.shadowColor = "rgb(213,213,213)"
          this.context.shadowOffsetX = 40
          this.context.shadowOffsetY = 40
          this.context.drawImage(this.img, 20, 20)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## cl.arkui.5  CanvasRenderingContext2D的measureText接口测算文本的结果变更

**访问级别**

公开接口

**变更原因**

在运用measureText接口进行文本尺寸测量时，在下述场景1与场景2中，所测得的文本宽度呈现异常值：
- 场景1：当Context与某一Canvas解除绑定后，再与另一Canvas重新绑定时，若未重新设定font属性，或在重新设定font属性时遗漏了font-size的指定，那么在绘制文本时将采用重置后的font-size（即默认值）。然而，在进行文本尺寸测量时，系统会错误地沿用前一Canvas中设定的font-size，从而导致文本宽度测量结果出现偏差；
- 场景2：在font属性的设定过程中，若首次已明确指定font-style，而第二次设定了不同的font-style，虽然在绘制文本时会采用新设定的font-style，但在进行文本尺寸测量时，系统却依旧沿用上一次设定的font-style，同样造成文本宽度测量结果的不准确。

**变更影响**

该变更为不兼容变更。

使用measureText接口进行文本测算时：

- 变更前：在场景1和场景2中，文本测算得到的文本宽度均为错误值；
- 变更后：在场景1和场景2中，文本测算得到的文本宽度均为正确值。

运行场景1的示例：

```ts
@Entry
@Component
struct example1 {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  @State flag: boolean = false

  build() {
    Column() {
      Button('transfer')
        .position({x:200, y:0})
        .width(100)
        .height(40)
        .onClick(() => {
          this.flag = !this.flag
        })
      Canvas(this.context)
        .position({x:100, y:45})
        .width('300')
        .height('100')
        .backgroundColor('rgb(39,135,237)')
        .onReady(() => {
          this.context.textAlign = 'center'
          this.context.font = '20vp'
          this.context.fillText('width:' + this.context.measureText('Hello World').width, this.context.width/2, 30)
        })
      if (this.flag) {
        Canvas(this.context)
          .position({x:100, y:145})
          .width('300')
          .height('100')
          .backgroundColor('rgb(213,213,213)')
          .onReady(() => {
            this.context.textAlign = 'center'
            this.context.fillText('width:' + this.context.measureText('Hello World').width, this.context.width/2, 30)
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

|                   变更前                   |                 变更后                  |
| :----------------------------------------: | :-------------------------------------: |
| ![](figures/measureText_1.gif) | ![](figures/measureText_2.gif) |

运行场景2的示例：

```ts
@Entry
@Component
struct example2 {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('rgb(255,192,0)')
        .onReady(() => {
          this.context.font = 'italic 25vp'
          this.context.fillText('width:' + this.context.measureText('Hello World').width, 10, 50)
          this.context.font = 'normal'
          this.context.fillText('width:' + this.context.measureText('Hello World').width, 10, 100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

|                   变更前                   |                 变更后                  |
| :----------------------------------------: | :-------------------------------------: |
| ![](figures/measureText_3.jpg) | ![](figures/measureText_4.jpg) |

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.57 版本开始。

**变更的接口/组件**

CanvasRenderingContext2D的measureText接口

**适配指导**

无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。