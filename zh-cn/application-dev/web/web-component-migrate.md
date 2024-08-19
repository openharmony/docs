# Web组件在不同的窗口间迁移

Web组件可以在不同在窗口的页面上进行挂载或移除操作。开发者可以基于这一能力，实现同一个Web组件在不同窗口间的迁移。使用该能力，可以实现诸如浏览器tab页拖出成独立窗口等功能。



以下示例中，主窗Ability在启动时，通过命令式的方式创建了一个Web组件。开发者可以通过`common.ets`中提供的方法和类，实现Web组件的挂载和移除。`Index.ets`则展示了一种挂载和移除Web组件的方法。通过这一方式，开发者可以实现Web组件在不同窗口中页面的挂载与移除，即Web组件在不同窗口间的迁移。

> ![icon-note.gif](../public_sys-resources/icon-note.gif) **说明：**
> 不要将一个Web组件同时挂载在两个父节点下，这会导致非预期行为。

```ts
// 主窗Ability
// EntryAbility.ets
import { createNWeb, defaultUrl } from '../pages/common'

// ...

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      // 创建Web动态组件（需传入UIContext），loadContent之后的任意时机均可创建，应用仅创建一个web组件
      createNWeb(defaultUrl, windowStage.getMainWindowSync().getUIContext());
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

// ...
```

```ts
// 提供动态挂载Web组件能力
// pages/common.ets
import { UIContext, NodeController, BuilderNode, FrameNode } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';
import { hilog } from '@kit.PerformanceAnalysisKit';

export const defaultUrl : string = 'https://www.example.com';

// @Builder中为动态组件的具体组件内容
// Data为入参封装类
class Data{
  url: string = '';
  webController: webview.WebviewController | null = null;

  constructor(url: string, webController: webview.WebviewController) {
    this.url = url;
    this.webController = webController;
  }
}

@Builder
function WebBuilder(data:Data) {
  Web({ src: data.url, controller: data.webController })
    .width("100%")
    .height("100%")
    .borderStyle(BorderStyle.Dashed)
    .borderWidth(2)
}

let wrap = wrapBuilder<[Data]>(WebBuilder);

// 用于控制和反馈对应的NodeContainer上的节点的行为，需要与NodeContainer一起使用
export class MyNodeController extends NodeController {
  private builderNode: BuilderNode<[Data]> | null | undefined = null;
  private webController : webview.WebviewController | null | undefined = null;
  private rootNode : FrameNode | null = null;

  constructor(builderNode : BuilderNode<[Data]> | undefined, webController : webview.WebviewController | undefined) {
    super();
    this.builderNode = builderNode;
    this.webController = webController;
  }

  // 必须要重写的方法，用于构建节点数、返回节点挂载在对应NodeContainer中
  // 在对应NodeContainer创建的时候调用或者通过rebuild方法调用刷新
  makeNode(uiContext: UIContext): FrameNode | null {
    // 该节点会被挂载在NodeContainer的父节点下
    return this.rootNode;
  }

  // 挂载Webview
  attachWeb() : void {
    if (this.builderNode) {
      let frameNode : FrameNode | null = this.builderNode.getFrameNode();
      if (frameNode?.getParent() != null) {
        // 挂载自定义节点前判断该节点是否已经被挂载
        hilog.error(0x0000, 'testTag', '%{public}s', 'The frameNode is already attached');
        return;
      }
      this.rootNode = this.builderNode.getFrameNode();
    }
  }

  // 卸载Webview
  detachWeb() : void {
    this.rootNode = null;
  }

  getWebController() : webview.WebviewController | null | undefined {
    return this.webController;
  }
}

// 创建Map保存所需要的BuilderNode
let builderNodeMap : Map<string, BuilderNode<[Data]> | undefined> = new Map();
// 创建Map保存所需要的webview.WebviewController
let webControllerMap : Map<string, webview.WebviewController | undefined> = new Map();

// 初始化需要UIContext 需在Ability获取
export const createNWeb = (url: string, uiContext: UIContext) => {
  // 创建WebviewController
  let webController = new webview.WebviewController() ;
  // 创建BuilderNode
  let builderNode : BuilderNode<[Data]> = new BuilderNode(uiContext);
  // 创建动态Web组件
  builderNode.build(wrap, new Data(url, webController));

  // 保存BuilderNode
  builderNodeMap.set(url, builderNode);
  // 保存WebviewController
  webControllerMap.set(url, webController);
}

// 自定义获取BuilderNode的接口
export const getBuilderNode = (url : string) : BuilderNode<[Data]> | undefined => {
  return builderNodeMap.get(url);
}
// 自定义获取WebviewController的接口
export const getWebviewController = (url : string) : webview.WebviewController | undefined => {
  return webControllerMap.get(url);
}

```

```ts
// 使用NodeController的Page页
// pages/Index.ets
import { getBuilderNode, MyNodeController, defaultUrl, getWebviewController } from "./common"

@Entry
@Component
struct Index {
  private nodeController : MyNodeController =
    new MyNodeController(getBuilderNode(defaultUrl), getWebviewController(defaultUrl));

  build() {
    Row() {
      Column() {
        Button("Attach Webview")
          .onClick(() => {
            // 注意不要将同一个节点同时挂载在不同的页面上！
            this.nodeController.attachWeb();
            this.nodeController.rebuild();
          })
        Button("Detach Webview")
          .onClick(() => {
            this.nodeController.detachWeb();
            this.nodeController.rebuild();
          })
        // NodeContainer用于与NodeController节点绑定，rebuild会触发makeNode
        // Page页通过NodeContainer接口绑定NodeController，实现动态组件页面显示
        NodeContainer(this.nodeController)
          .height("80%")
          .width("80%")
      }
      .width('100%')
    }
    .height('100%')
  }
}

```

