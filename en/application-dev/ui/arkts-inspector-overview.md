# Inspecting Page Layouts

You can use the Inspector to examine page layouts. Its bidirectional positioning feature helps quickly locate components, modify attributes, and debug components in DevEco Studio, thereby improving development efficiency.

ArkUI obtains information about all components in the currently displayed page, including the parent-child structure of the component tree, size, position, styles, attributes, and states. After obtaining the component tree information, it generates and displays it as an Inspector component tree. For details about the usage in DevEco Studio, see [Using ArkUI Inspector](ui-inspector-profiler.md#using-arkui-inspector).

## Constraints

1. The real-time update functionality is not supported for animation-type components in the component tree.

2. Component attributes and styles can be obtained, but **Controller** and **Builder** objects cannot.

3. Component methods and events cannot be obtained.

## Querying Component Tree and Component Information Using UIContext

ArkUI provides the @ohos.arkui.UIContext (UIContext) extension capability. Use [getFilteredInspectorTree](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getfilteredinspectortree12) to obtain the component tree and component attributes, and [getFilteredInspectorTreeById](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getfilteredinspectortreebyid12) to obtain attributes of specified components and their child components. Querying with filter conditions is supported.

The following example demonstrates the basic usage of **getFilteredInspectorTree** and **getFilteredInspectorTreeById**.

```ts
import { UIContext } from '@kit.ArkUI';
@Entry
@Component
struct ComponentPage {
  loopConsole(inspectorStr: string, i: string) {
    console.log(`InsTree ${i}| type: ${JSON.parse(inspectorStr).$type}, ID: ${JSON.parse(inspectorStr).$ID}`);
    if (JSON.parse(inspectorStr).$children) {
      i += '-';
      for (let index = 0; index < JSON.parse(inspectorStr).$children.length; index++) {
        this.loopConsole(JSON.stringify(JSON.parse(inspectorStr).$children[index]), i);
      }
    }
  }

  build() {
    Column() {
      Text("Hello World")
        .fontSize(20)
        .id("TEXT")
      Button('content').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        let inspectorStr = uiContext.getFilteredInspectorTree(['content']);
        console.log(`InsTree : ${inspectorStr}`);
        inspectorStr = JSON.stringify(JSON.parse(inspectorStr));
        this.loopConsole(inspectorStr, '-');
      })
      Button('isLayoutInspector').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        let inspectorStr = uiContext.getFilteredInspectorTree(['isLayoutInspector']);
        console.log(`InsTree : ${inspectorStr}`);
        inspectorStr = JSON.stringify(JSON.parse(inspectorStr).content);
        this.loopConsole(inspectorStr, '-');
      })
      Button('getFilteredInspectorTreeById').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        try {
          let inspectorStr = uiContext.getFilteredInspectorTreeById('TEXT', 1, ["id", "src"]);
          console.info(`result1: ${inspectorStr}`);
          inspectorStr = JSON.stringify(JSON.parse(inspectorStr)['$children'][0]);
          console.info(`result2: ${inspectorStr}`);
          inspectorStr = uiContext.getFilteredInspectorTreeById('TEXT', 1, ["src"]);
          inspectorStr = JSON.stringify(JSON.parse(inspectorStr)['$children'][0]);
          console.info(`result3: ${inspectorStr}`);
        } catch(e) {
          console.info(`getFilteredInspectorTreeById error: ${e}`);
        }
      })

    }
    .width('100%')
    .height('100%')
  }
}
```

## Using Layout Callbacks

The [@ohos.arkui.inspector (Layout Callback)](../reference/apis-arkui/js-apis-arkui-inspector.md) module provides APIs for registering the component layout and drawing completion callbacks.

The following example demonstrates the basic usage of layout callbacks.

```ts
import { inspector } from '@kit.ArkUI'

@Entry
@Component
struct ImageExample {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row({ space: 5 }) {
          Image($r('app.media.app_icon'))
            .width(110)
            .height(110)
            .border({ width: 1 })
            .id('IMAGE_ID')
        }
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }

  listener:inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('IMAGE_ID')

  aboutToAppear() {
    let onLayoutComplete:()=>void=():void=>{
      // Add functionality to be implemented.
    }
    let onDrawComplete:()=>void=():void=>{
      // Add functionality to be implemented.
    }
    let onDrawChildrenComplete:()=>void=():void=>{
      // Add functionality to be implemented.
    }
    let FuncLayout = onLayoutComplete // Bind to the current JS object.
    let FuncDraw = onDrawComplete // Bind to the current JS object.
    let FuncDrawChildren = onDrawChildrenComplete // Bind to the current JS object.
    let OffFuncLayout = onLayoutComplete // Bind to the current JS object.
    let OffFuncDraw = onDrawComplete // Bind to the current JS object.
    let OffFuncDrawChildren = onDrawChildrenComplete // Bind to the current JS object.

    this.listener.on('layout', FuncLayout)
    this.listener.on('draw', FuncDraw)
    this.listener.on('drawChildren', FuncDrawChildren)

    // Unregister callbacks through the handle. You should decide when to call these APIs.
    // this.listener.off('layout', OffFuncLayout)
    // this.listener.off('draw', OffFuncDraw)
    // this.listener.off('drawChildren', OffFuncDrawChildren)
  }
}
```

## Using the Extended Capabilities for Component Identification Attributes

The following APIs provide extended capabilities for component identification attributes:
- [getInspectorByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectorbykey9): obtains all attributes of the component with the specified ID.
- [getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectortree9): obtains the component tree with component attributes.
- [sendEventByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#sendeventbykey9): sends an event to the component with the specified ID.

The following example demonstrates the basic usage of **getInspectorByKey**, **getInspectorTree**, and **sendEventByKey**.

```ts
@Entry
@Component
struct ComponentPage {
  build() {
    Column() {
      Text("Hello World")
        .fontSize(20)
        .id("TEXT")
        .onClick(() => {
          console.info(`Text is clicked`);
        })
      Button('getInspectorByKey').onClick(() => {
        let result = getInspectorByKey("TEXT");
        console.info(`result is ${result}`);
      })
      Button('getInspectorTree').onClick(() => {
        let result = getInspectorTree();
        console.info(`result is ${JSON.stringify(result)}`);
      })
      Button('sendEventByKey').onClick(() => {
        sendEventByKey("TEXT", 10, "");
      })
    }
    .width('100%')
    .height('100%')
  }
}
```
<!--no_check-->