# 自定义节点常见问题
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

本文档介绍自定义节点的常见问题并提供参考。

## 自定义组件的aboutToDisappear回调异常

**问题现象**

从API version 12开始，自定义节点的子节点在页面退出后未立即回调自定义组件的[aboutToDisappear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear)方法。自定义组件的aboutToDisappear通常在其销毁的时候触发，页面销毁后未立即回调则说明该自定义组件在页面销毁后未立即销毁。

**可能原因**

- 自定义组件存在父节点且父节点未销毁。
- 自定义组件由[BuilderNode](./arkts-user-defined-arktsNode-builderNode.md)创建，该前端对象既未被回收，也未解除对后端自定义组件的引用。BuilderNode创建时，默认持有后端节点的强引   用。
- 通过调用[OH_ArkUI_GetNodeHandleFromNapiValue](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnodehandlefromnapivalue)方法，可以获取BuilderNode或ComponentContent对象中的root节点，此操作会使后端节点的引用计数加一。。
- 在[NodeContent](../reference/apis-arkui/js-apis-arkui-NodeContent.md)中，通过[addFrameNode](../reference/apis-arkui/js-apis-arkui-NodeContent.md#addframenode12)方法增加了对被添加的FrameNode对象节点的引用关系。然而，该NodeContent对象未被回收，且未通过[removeFrameNode](../reference/apis-arkui/js-apis-arkui-NodeContent.md#removeframenode12)接口删除所增加的引用关系。

**解决措施**

- 将需要释放的自定义组件从父节点上移除，排除父节点对自定义组件生命周期的影响。
- 自定义组件由[BuilderNode](./arkts-user-defined-arktsNode-builderNode.md)创建时，调用[dispose](../reference/apis-arkui/js-apis-arkui-builderNode.md#dispose12)接口，立即释放前端BuilderNode对象对于后端节点的强引用。
- 对于使用OH_ArkUI_GetNodeHandleFromNapiValue获取BuilderNode或ComponentContent对象的root节点，
调用[disposenode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode)减少OH_ArkUI_GetNodeHandleFromNapiValue增加的引用计数。
- 未调用dispose时，当前端的BuilderNode对象在[GC](../arkts-utils/gc-introduction.md)中被回收会释放对后端根节点的引用。调试阶段可使用[hidumper](../dfx/hidumper.md)指令触发GC或[查询堆内存](../dfx/hidumper.md#查询虚拟机堆内存)来分析引用关系。

**示例代码**

下文中，根节点表示BuilderNode的根节点，aboutToDisappear表示BuilderNode中构建的自定义组件（即BuilderNodePage）中的回调。

- 跳转至pageOneTmp页面后返回，通过指令触发GC，继续操作设备后可以看到aboutToDisappear回调。根节点相关的引用关系和解决方案：
  - NodeContent对根节点的引用关系：需要触发NodeContent对象的回收，或主动调用removeFrameNode接口。
  - 全局对象对BuilderNode的引用关系：通过[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)的[clear](../reference/apis-arkts/js-apis-arraylist.md#clear)方法清除对BuilderNode的引用。
  - BuilderNode对象对根节点的引用关系：确保BuilderNode对象无其他引用关系，触发该对象的回收可以解除其对根节点的引用。

- 跳转至pageTwoTmp页面后返回，可以直接看到aboutToDisappear回调。根节点相关的引用关系以及解决方案：
  - NodeContent对根节点的引用关系：通过NodeContent的removeFrameNode接口解除引用关系。
  - BuilderNode对象对根节点的引用关系：通过BuilderNode的dispose接口直接解除引用关系。

- 跳转至pageThreeTmp页面后返回，可以直接看到aboutToDisappear回调。根节点相关的引用关系以及解决方案：
  - 根节点的父节点对其的引用关系：由于父节点为FrameNode对象对应的节点，可以直接通过FrameNode的removeChild方法解除引用关系。
  - BuilderNode对象对根节点的引用关系：通过BuilderNode的dispose接口直接解除引用关系。

```ts

import { BuilderNode, FrameNode, NodeContent } from '@kit.ArkUI';
import { ArrayList } from '@kit.ArkTS';

const CUSTOM_COMPONENT_CONT: string = "CustomComponentCont"
AppStorage.setOrCreate<number>(CUSTOM_COMPONENT_CONT, 0);
let globalBuilderNodeList: ArrayList<BuilderNode<[]>> = new ArrayList<BuilderNode<[]>>();

@Component
struct BuilderNodePage {
  aboutToAppear(): void {
    const count: number | undefined = AppStorage.get<number>(CUSTOM_COMPONENT_CONT);
    const current: number = count ? count + 1 : 1;
    AppStorage.setOrCreate<number>(CUSTOM_COMPONENT_CONT, current);
    console.info("BuilderNodePage", "aboutToAppear " + AppStorage.get<number>(CUSTOM_COMPONENT_CONT))
  }

  aboutToDisappear(): void {
    setTimeout(() => {
      const count: number | undefined = AppStorage.get<number>(CUSTOM_COMPONENT_CONT);
      console.info("BuilderNodePage", "aboutToDisappear " + count)
      const current: number = count ? count - 1 : -1;
      AppStorage.set<number>(CUSTOM_COMPONENT_CONT, current)
      console.info("BuilderNodePage", "aboutToDisappear " + AppStorage.get<number>(CUSTOM_COMPONENT_CONT))
    }, 1)
  }

  build() {
    Text("This is a BuilderNode")
  }
}

@Builder
function BuilderNodeBuilder() {
  BuilderNodePage();
}

@Entry
@Component
struct NavigationExample {
  @Provide('pageInfos') pageInfos: NavPathStack = new NavPathStack()
  private arr: number[] = [1, 2, 3];
  @StorageProp(CUSTOM_COMPONENT_CONT) customComponentCount: number | undefined =
    AppStorage.get<number>(CUSTOM_COMPONENT_CONT);

  @Builder
  pageMap(name: string) {
    if (name === "NavDestinationTitle1") {
      pageOneTmp();
    } else if (name === "NavDestinationTitle2") {
      pageTwoTmp();
    } else if (name === "NavDestinationTitle3") {
      pageThreeTmp();
    }
  }

  onPageShow(): void {
    console.log("NavigationExample " + this.customComponentCount);
  }

  build() {
    Column() {
      Navigation(this.pageInfos) {
        Text("BuilderNode中自定义组件的遗留数量 " + this.customComponentCount)
          .width("90%")
          .height(40)
          .backgroundColor('#FFFFFF')
        Button("移除全局引用")
          .onClick(() => {
            // 清除所有全局引用。
            // 可以使用hidumper指令触发GC验证引用关系是否清零。
            globalBuilderNodeList.clear();
          })
        List({ space: 12 }) {
          ForEach(this.arr, (item: number) => {
            ListItem() {
              Text("Page" + item)
                .width("100%")
                .height(72)
                .backgroundColor('#FFFFFF')
                .borderRadius(24)
                .fontSize(16)
                .fontWeight(500)
                .textAlign(TextAlign.Center)
                .onClick(() => {
                  this.pageInfos.pushPath({ name: "NavDestinationTitle" + item });
                })
            }
          }, (item: number) => item.toString())
        }
        .width("100%")
        .margin({ top: 12 })
      }
      .title("主标题")
      .mode(NavigationMode.Stack)
      .navDestination(this.pageMap)
    }
    .height('100%')
    .width('100%')
    .backgroundColor('#F1F3F5')
  }
}

// PageOne.ets
@Component
export struct pageOneTmp {
  @Consume('pageInfos') pageInfos: NavPathStack;
  private builderNode: BuilderNode<[]> = new BuilderNode(this.getUIContext());
  private content: NodeContent = new NodeContent();

  aboutToAppear(): void {
    console.info("pageOneTmp", "aboutToAppear")
    this.builderNode.build(wrapBuilder(BuilderNodeBuilder));
    if (this.builderNode.getFrameNode()) {
      this.content.addFrameNode(this.builderNode.getFrameNode());
    }
    // 添加全局引用，该对象在全局引用移除前无法被GC。
    globalBuilderNodeList.add(this.builderNode);
  }

  aboutToDisappear(): void {
    console.info("pageOneTmp", "aboutToDisappear")
  }

  build() {
    NavDestination() {
      Column() {
        Text("pageOneTmp")
        ContentSlot(this.content)
      }.width('100%').height('100%')
    }.title("NavDestinationTitle1")
    .onBackPressed(() => {
      const popDestinationInfo = this.pageInfos.pop(); // 弹出路由栈栈顶元素。
      console.log('pop' + '返回值' + JSON.stringify(popDestinationInfo));
      return true;
    })
  }
}

// PageTwo.ets
@Component
export struct pageTwoTmp {
  @Consume('pageInfos') pageInfos: NavPathStack;
  private builderNode: BuilderNode<[]> = new BuilderNode(this.getUIContext());
  private content: NodeContent = new NodeContent();

  aboutToAppear(): void {
    console.info("pageTwoTmp", "aboutToAppear")
    this.builderNode!.build(wrapBuilder(BuilderNodeBuilder));
    if (this.builderNode!.getFrameNode()) {
      // 将BuilderNode的根节点挂载至NodeContent对象中。
      // 如果要触发builderNode的根节点的析构，需要主动从NodeContent对象中移除该节点，或者等待NodeContent对象被GC。
      // 否则，BuilderNode的根节点无法触发析构。
      this.content.addFrameNode(this.builderNode!.getFrameNode());
    }
  }

  aboutToDisappear(): void {
    console.info("pageTwoTmp", "aboutToDisappear")
    if (this.builderNode?.getFrameNode()) {
      // 将BuilderNode的根节点从NodeContent对象中移除。
      // 需要在BuilderNode的dispose操作之前执行，否则无法获得该BuilderNode的根节点。
      this.content.removeFrameNode(this.builderNode?.getFrameNode());
    }
    this.builderNode?.dispose();
  }

  build() {
    NavDestination() {
      Column() {
        Text("pageTwoTmp")
        ContentSlot(this.content)
      }.width('100%').height('100%')
    }.title("NavDestinationTitle2")
    .onBackPressed(() => {
      const popDestinationInfo = this.pageInfos.pop(); // 弹出路由栈栈顶元素。
      console.log('pop' + '返回值' + JSON.stringify(popDestinationInfo));
      return true;
    })
  }
}

// PageThree.ets
@Component
export struct pageThreeTmp {
  @Consume('pageInfos') pageInfos: NavPathStack;
  private builderNode: BuilderNode<[]> = new BuilderNode(this.getUIContext());
  private content: NodeContent = new NodeContent();
  private rootNode: FrameNode = new FrameNode(this.getUIContext());

  aboutToAppear(): void {
    console.info("pageThreeTmp", "aboutToAppear")
    this.builderNode!.build(wrapBuilder(BuilderNodeBuilder));
    if (this.builderNode!.getFrameNode()) {
      this.content.addFrameNode(this.rootNode);
      // BuilderNode的根节点被挂载至FrameNode对象对应的节点中。
      // BuilderNode的根节点如果要触发析构需要从主动从FrameNode对象对应的节点中移除，或者等待FrameNode对象对应的节点析构。
      // 否则，BuilderNode的根节点无法触发析构。
      this.rootNode.appendChild(this.builderNode.getFrameNode());
    }
  }

  aboutToDisappear(): void {
    console.info("pageThreeTmp", "aboutToDisappear")
    if (this.builderNode?.getFrameNode()) {
      // 将BuilderNode的根节点从FrameNode对象对应的节点中移除。
      // 需要在BuilderNode的dispose操作以及FrameNode对象dispose之前执行，否则无法获得他们对应的节点。
      this.rootNode.removeChild(this.builderNode?.getFrameNode());
    }
    this.builderNode?.dispose();
  }

  build() {
    NavDestination() {
      Column() {
        Text("pageThreeTmp")
        ContentSlot(this.content)
      }.width('100%').height('100%')
    }.title("NavDestinationTitle3")
    .onBackPressed(() => {
      const popDestinationInfo = this.pageInfos.pop(); // 弹出路由栈栈顶元素。
      console.log('pop' + '返回值' + JSON.stringify(popDestinationInfo));
      return true;
    })
  }
}

```
