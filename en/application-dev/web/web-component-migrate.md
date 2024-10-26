# Migrating Web Components Between Different Windows

**Web** components can be mounted or removed on different pages in the window. Based on this capability, you can migrate the same **Web** component between different windows and drag a browser tab page out as an independent window.



In the following example, a **Web** component is created using a command when the main window ability is started. You can use the functions and classes provided in **common.ets** to mount and remove **Web** components. **Index.ets** shows a method to mount and remove **Web** components. In this way, you can mount and remove **Web** components in different windows, in other words, migrate **Web** components between different windows.

> ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**
> Do not mount a **Web** component under two parent nodes at the same time. Otherwise, unexpected behavior occurs.

```ts
// Main window ability.
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
      // Create a dynamic **Web** component, in which the **UIContext** should be passed. (The component can be created at any time after **loadContent()** is called, and only one web component is created for the application.)
      createNWeb(defaultUrl, windowStage.getMainWindowSync().getUIContext());
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

// ...
```

```ts
// Provide the capability for mounting **Web** components dynamically.
// pages/common.ets
import { UIContext, NodeController, BuilderNode, FrameNode } from '@kit.ArkUI';
import { webview } from '@kit.ArkWeb';
import { hilog } from '@kit.PerformanceAnalysisKit';

export const defaultUrl : string = 'https://www.example.com';

// @Builder contains the specific information of the dynamic component.
// Data is an input parameter of encapsulation class.
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

// Used to control and report the behavior of the node on the NodeContainer. This function must be used together with NodeContainer.
export class MyNodeController extends NodeController {
  private builderNode: BuilderNode<[Data]> | null | undefined = null;
  private webController : webview.WebviewController | null | undefined = null;
  private rootNode : FrameNode | null = null;

  constructor(builderNode : BuilderNode<[Data]> | undefined, webController : webview.WebviewController | undefined) {
    super();
    this.builderNode = builderNode;
    this.webController = webController;
  }

  // This function must be overridden, which is used to construct the number of nodes, return the nodes and mount them to the NodeContainer.
  // Call it or rebuild() to refresh when the NodeContainer is created.
  makeNode(uiContext: UIContext): FrameNode | null {
    // This node will be mounted to the parent node of NodeContainer.
    return this.rootNode;
  }

  // Mount the Webview.
  attachWeb() : void {
    if (this.builderNode) {
      let frameNode : FrameNode | null = this.builderNode.getFrameNode();
      if (frameNode?.getParent() != null) {
        // Check whether the node is mounted before mounting the custom node.
        hilog.error(0x0000, 'testTag', '%{public}s', 'The frameNode is already attached');
        return;
      }
      this.rootNode = this.builderNode.getFrameNode();
    }
  }

  // Uninstall the Webview.
  detachWeb() : void {
    this.rootNode = null;
  }

  getWebController() : webview.WebviewController | null | undefined {
    return this.webController;
  }
}

// Create the BuilderNode required for saving the Map.
let builderNodeMap : Map<string, BuilderNode<[Data]> | undefined> = new Map();
// Create the webview.WebviewController required for saving the map.
let webControllerMap : Map<string, webview.WebviewController | undefined> = new Map();

// UIContext is required for initialization, which is obtained from Ability.
export const createNWeb = (url: string, uiContext: UIContext) => {
  // Create a WebviewController.
  let webController = new webview.WebviewController() ;
  // Create a BuilderNode.
  let builderNode : BuilderNode<[Data]> = new BuilderNode(uiContext);
  // Create a dynamic Web component.
  builderNode.build(wrap, new Data(url, webController));

  // Save the BuilderNode.
  builderNodeMap.set(url, builderNode);
  // Save the WebviewController.
  webControllerMap.set(url, webController);
}

// Customize the API for obtaining BuilderNode.
export const getBuilderNode = (url : string) : BuilderNode<[Data]> | undefined => {
  return builderNodeMap.get(url);
}
// Customize the API for obtaining WebviewController.
export const getWebviewController = (url : string) : webview.WebviewController | undefined => {
  return webControllerMap.get(url);
}

```

```ts
// Use the Page of NodeController.
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
            // Do not mount the same node to different pages at the same time.
            this.nodeController.attachWeb();
            this.nodeController.rebuild();
          })
        Button("Detach Webview")
          .onClick(() => {
            this.nodeController.detachWeb();
            this.nodeController.rebuild();
          })
        // NodeContainer is used to bind to the NodeController node. Calling rebuild() triggers makeNode().
        // The Page is bound to NodeController() through NodeContainer(). As a result, the dynamic component page is successfully displayed.
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
