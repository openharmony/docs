# 绘制组件

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## setXComponentSurfaceSize

ArkTS1.1接口声明：[setXComponentSurfaceSize(value: {surfaceWidth: number, surfaceHeight: number}): void](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#setXComponentSurfaceSizedeprecated)

替代的ArkTS1.2接口声明：[setXComponentSurfaceRect(rect: SurfaceRect): void](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#setxcomponentsurfacerect12)

适配方法如下：

ArkTS1.1

```ts
@Entry
@Component
struct XComponentExample {
  xComponentController: XComponentController = new XComponentController();

  build() {
    Column() {
      XComponent({
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
        .onClick(() => {
          this.xComponentController.setXComponentSurfaceSize({ surfaceWidth: 100, surfaceHeight: 100 });
        })
    }
  }
}
```

ArkTS1.2

```ts
@Entry
@Component
struct XComponentExample {
  xComponentController: XComponentController = new XComponentController();

  build() {
    Column() {
      XComponent({
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
        .onClick(() => {
          this.xComponentController.setXComponentSurfaceRect({ surfaceWidth: 100, surfaceHeight: 100 } as SurfaceRect);
        })
    }
  }
}
```

## XComponent

ArkTS1.1接口声明：[XComponent(value: {id: string, type: string, libraryname?: string, controller?: XComponentController})](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#xcomponentdeprecated)

替代的ArkTS1.2接口声明：[XComponent(options: XComponentOptions)](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#xcomponent12)

适配方法如下：

ArkTS1.1

```ts
@Entry
@Component
struct XComponentExample {
  build() {
    Column() {
      XComponent({
        id: 'xc',
        type: 'surface'
      })
    }
  }
}
```

ArkTS1.2

```ts
@Entry
@Component
struct XComponentExample {
  build() {
    Column() {
      XComponent({
        type: XComponentType.SURFACE,
        controller: new XComponentController()
      } as XComponentOptions)
    }
  }
}
```

## XComponentType

### XComponentType.COMPONENT

ArkTS1.1接口声明：[XComponentType.COMPONENT](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#xcomponenttype10)

替代的ArkTS1.2接口声明：[Column(options?: ColumnOptions)](../reference/apis-arkui/arkui-ts/ts-container-column.md#column-1)

适配方法如下：

ArkTS1.1

```ts
@Entry
@Component
struct XComponentExample {
  build() {
    Column() {
      XComponent({ type: XComponentType.COMPONENT }) {
        Text('hello world');
      }
    }
  }
}
```

ArkTS1.2

```ts
@Entry
@Component
struct XComponentExample {
  build() {
    Column() {
      Column() {
        Text('hello world');
      }
    }
  }
}
```

### XComponentType.NODE

ArkTS1.1接口声明：[XComponentType.NODE](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#xcomponenttype10)

替代的ArkTS1.2接口声明：[ArkTS侧接口：ContentSlot(content: Content)](state-management/arkts-rendering-control-contentslot.md#arkts侧接口)

适配方法如下：

ArkTS1.1

```ts
@Entry
@Component
struct XComponentExample {
  build() {
    Column() {
      XComponent({ id: 'xc', type: XComponentType.NODE });
    }
  }
}
```

ArkTS1.2

```ts
import { NodeContent } from '@kit.ArkUI';

@Entry
@Component
struct XComponentExample {
  private nodeContent: Content = new NodeContent();

  build() {
    Column() {
      ContentSlot(this.nodeContent);
    }
  }
}
```

## XComponentNode

在ArkTS1.2中，不再支持`XComponentNode`及其相关接口。

### constructor

ArkTS1.1接口声明：[constructor(uiContext: UIContext, options: RenderOptions, id: string, type: XComponentType, libraryName?: string)](../reference/apis-arkui/js-apis-arkui-xcomponentNode.md#constructor)

替代的ArkTS1.2接口声明：[createNode(context: UIContext, nodeType: 'XComponent'): XComponent](../reference/apis-arkui/js-apis-arkui-frameNode.md#createnodexcomponent12)

适配方法如下：

ArkTS1.1

```ts
import { XComponentNode, NodeController } from '@kit.ArkUI';

class XComponentNodeController extends NodeController {
  private xComponentNode: MyXComponentNode | null = null;

  makeNode(context: UIContext): FrameNode | null {
    this.xComponentNode =
      new MyXComponentNode(context, { selfIdealSize: { width: 200, height: 200 } }, "xc", XComponentType.SURFACE);
    return this.xComponentNode;
  }
}

class MyXComponentNode extends XComponentNode {
}
```

ArkTS1.2

```ts
import { NodeController, typeNode } from '@kit.ArkUI';

class XComponentNodeController extends NodeController {
  makeNode(context: UIContext): FrameNode | null {
    let opt: XComponentOptions =
      { type: XComponentType.SURFACE, controller: new XComponentController() } as XComponentOptions;
    let node = typeNode.createNode(context, 'XComponent', opt);
    return node;
  }
}
```

### onCreate

ArkTS1.1接口声明：[onCreate(event?: Object): void](../reference/apis-arkui/js-apis-arkui-xcomponentNode.md#oncreate)

替代的ArkTS1.2接口声明：[onSurfaceCreated(surfaceId: string): void](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#onsurfacecreated12)

适配方法如下：

ArkTS1.1

```ts
import { XComponentNode, NodeController } from '@kit.ArkUI';

class XComponentNodeController extends NodeController {
  private xComponentNode: MyXComponentNode | null = null;

  makeNode(context: UIContext): FrameNode | null {
    this.xComponentNode =
      new MyXComponentNode(context, { selfIdealSize: { width: 200, height: 200 } }, "xc", XComponentType.SURFACE);
    return this.xComponentNode;
  }
}

class MyXComponentNode extends XComponentNode {
  onCreate() {
    console.log('onCreate');
  }
}
```

ArkTS1.2

```ts
import { NodeController, typeNode } from '@kit.ArkUI';

class MyXComponentController extends XComponentController {
  onSurfaceCreated(surfaceId: string): void {
    console.log('onCreate');
  }
}

class XComponentNodeController extends NodeController {
  makeNode(context: UIContext): FrameNode | null {
    let opt: XComponentOptions =
      { type: XComponentType.SURFACE, controller: new MyXComponentController() } as XComponentOptions;
    let node = typeNode.createNode(context, 'XComponent', opt);
    return node;
  }
}
```

### onDestroy

ArkTS1.1接口声明：[onDestroy(): void](../reference/apis-arkui/js-apis-arkui-xcomponentNode.md#ondestroy)

替代的ArkTS1.2接口声明：[onDestroy(event: VoidCallback): XComponentAttribute](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#ondestroy)

适配方法如下：

ArkTS1.1

```ts
import { XComponentNode, NodeController } from '@kit.ArkUI';

class XComponentNodeController extends NodeController {
  private xComponentNode: MyXComponentNode | null = null;

  makeNode(context: UIContext): FrameNode | null {
    this.xComponentNode =
      new MyXComponentNode(context, { selfIdealSize: { width: 200, height: 200 } }, "xc", XComponentType.SURFACE);
    return this.xComponentNode;
  }
}

class MyXComponentNode extends XComponentNode {
  onDestroy() {
    console.log('onDestroy');
  }
}
```

ArkTS1.2

```ts
import { NodeController, typeNode } from '@kit.ArkUI';

class XComponentNodeController extends NodeController {
  makeNode(context: UIContext): FrameNode | null {
    let opt: XComponentOptions =
      { type: XComponentType.SURFACE, controller: new XComponentController() } as XComponentOptions;
    let node = typeNode.createNode(context, 'XComponent', opt);
    node.attribute.onDestroy(() => {
      console.log('onDestroy');
    })
    return node;
  }
}
```

### changeRenderType

ArkTS1.1接口声明：[changeRenderType(type: NodeRenderType): boolean](../reference/apis-arkui/js-apis-arkui-xcomponentNode.md#changeRenderType)

替代的ArkTS1.2接口声明：[constructor(uiContext: UIContext, options?: RenderOptions)](../reference/apis-arkui/js-apis-arkui-builderNode.md#constructor)

适配方法如下：

ArkTS1.1

```ts
import { XComponentNode, NodeRenderType, UIContext } from '@kit.ArkUI';

class MyNodeController {
  testChangeRenderType(context: UIContext): void {
    let node = new XComponentNode(context, {}, 'xc', XComponentType.SURFACE);
    node.changeRenderType(NodeRenderType.RENDER_TYPE_TEXTURE);
  }
}
```

ArkTS1.2

```ts
import { BuilderNode, RenderOptions, NodeRenderType, UIContext } from '@kit.ArkUI';

class MyNodeController {
  testChangeRenderType(context: UIContext): void {
    let node = new BuilderNode(context, { type: NodeRenderType.RENDER_TYPE_TEXTURE } as RenderOptions);
  }
}
```
