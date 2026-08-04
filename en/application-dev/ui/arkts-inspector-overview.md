# Inspecting Page Layouts

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=2127cc50993e6c62760e64970efb1d5e9c01f9c8 translatedAt=2026-08-01T00:27:53.615Z pushedAt=2026-08-01T05:56:49.342Z -->

You can use the Inspector tool in DevEco Studio to inspect page layouts. Its bidirectional positioning feature enables quick component location, attribute modification, and component debugging, significantly improving development efficiency.

ArkUI obtains information about all components on the currently displayed page, including the parent-child structure, size, position, style, attributes, and state of the component tree. After the component tree information is obtained, it is generated and displayed as an inspector component tree. For details about using DevEco Studio, see [Inspector Debugging Capability](ui-inspector-profiler.md#inspector-debugging-capability).

Inspector also provides C APIs for registering and unregistering listeners for UI component layout or drawing display events. For more details, see [Adding an Event Listener](ndk-add-component-events.md).

## Constraints

1. The real-time update functionality is not supported for animation-type components in the component tree.

2. Component attributes and styles can be obtained, but **Controller** and **Builder** objects cannot.

3. Component methods and events cannot be obtained.

## Querying Component Tree and Component Information Using UIContext

ArkUI provides the @ohos.arkui.UIContext([UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md)) extension capability. Use [getFilteredInspectorTree](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getfilteredinspectortree12) to obtain the component tree and component attributes, and [getFilteredInspectorTreeById](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getfilteredinspectortreebyid12) to obtain attributes of specified components and their child components. Querying with filter conditions is supported.

The following example demonstrates the basic usage of **getFilteredInspectorTree** and **getFilteredInspectorTreeById**.

<!-- @[uiContextTree_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/checkpage/entry/src/main/ets/pages/ComponentPage.ets) --> 

``` TypeScript
import { UIContext } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct ComponentPage {
  loopConsole(inspectorStr: string, i: string) {
    hilog.info(0x0000, `InsTree ${i}| type: ${JSON.parse(inspectorStr).$type}, ID: ${JSON.parse(inspectorStr).$ID}`,
      'InsTree');
    if (JSON.parse(inspectorStr).$children) {
      i += '-';
      for (let index = 0; index < JSON.parse(inspectorStr).$children.length; index++) {
        this.loopConsole(JSON.stringify(JSON.parse(inspectorStr).$children[index]), i);
      }
    }
  }

  build() {
    Column() {
      Text('Hello World')
        .fontSize(20)
        .id('TEXT')
      Button('content').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        let inspectorStr = uiContext.getFilteredInspectorTree(['content']);
        hilog.info(0x0000,`InsTree : ${inspectorStr}`, 'InsTree');
        inspectorStr = JSON.stringify(JSON.parse(inspectorStr));
        this.loopConsole(inspectorStr, '-');
      })
      Button('isLayoutInspector').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        let inspectorStr = uiContext.getFilteredInspectorTree(['isLayoutInspector']);
        hilog.info(0x0000,`InsTree : ${inspectorStr}`, 'InsTree');
        inspectorStr = JSON.stringify(JSON.parse(inspectorStr).content);
        this.loopConsole(inspectorStr, '-');
      })
      Button('getFilteredInspectorTreeById').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        try {
          let inspectorStr = uiContext.getFilteredInspectorTreeById('TEXT', 1, ['id', 'src']);
          hilog.info(0x0000,`result1: ${inspectorStr}`, 'result1');
          inspectorStr = JSON.stringify(JSON.parse(inspectorStr)['$children'][0]);
          hilog.info(0x0000,`result2: ${inspectorStr}`, 'result2');
          inspectorStr = uiContext.getFilteredInspectorTreeById('TEXT', 1, ['src']);
          inspectorStr = JSON.stringify(JSON.parse(inspectorStr)['$children'][0]);
          hilog.info(0x0000,`result3: ${inspectorStr}`, 'result3');
        } catch (e) {
          hilog.error(0x0000, `getFilteredInspectorTreeById error: ${e}`, 'error');
        }
      })

    }
    .width('100%')
    .height('100%')
  }
}
```

## Using Layout Callbacks

ArkUI provides the ability to register callbacks for component layout and drawing completion notifications via [@ohos.arkui.inspector (Layout Callback)](../reference/apis-arkui/js-apis-arkui-inspector.md).

The following example demonstrates the basic usage of layout callbacks.

<!-- @[uiContextInspector_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/checkpage/entry/src/main/ets/pages/ImagePage.ets) --> 

``` TypeScript
import { inspector } from '@kit.ArkUI';

@Entry
@Component
struct ImageExample {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row({ space: 5 }) {
          // Replace $r('app.media.startIcon') with the actual resource file.
          Image($r('app.media.startIcon'))
            .width(110)
            .height(110)
            .border({ width: 1 })
            .id('IMAGE_ID')
        }
        .id('ROW_ID')
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }

  listenerForImage: inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('IMAGE_ID');
  listenerForRow: inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('ROW_ID');

  aboutToAppear() {
    let onLayoutComplete: () => void = (): void => {
      // Add functionality to be implemented.
    };
    let onDrawComplete: () => void = (): void => {
      // Add functionality to be implemented.
    };
    let onDrawChildrenComplete: () => void = (): void => {
      // Add functionality to be implemented.
    };
    let funcLayout = onLayoutComplete; // Bind to the current JS object.
    let funcDraw = onDrawComplete; // Bind to the current JS object.
    let funcDrawChildren = onDrawChildrenComplete; // Bind to the current JS object.
    let offFuncLayout = onLayoutComplete; // Bind to the current JS object.
    let offFuncDraw = onDrawComplete; // Bind to the current JS object.
    let offFuncDrawChildren = onDrawChildrenComplete; // Bind to the current JS object.

    this.listenerForImage.on('layout', funcLayout);
    this.listenerForImage.on('draw', funcDraw);
    this.listenerForRow.on('drawChildren', funcDrawChildren);

    // Unregister callbacks through the handle. You should decide when to call these APIs.
    // this.listenerForImage.off('layout', offFuncLayout)
    // this.listenerForImage.off('draw', offFuncDraw)
    // this.listenerForRow.off('drawChildren', offFuncDrawChildren)
  }
}
```

## Using the Extended Capabilities for Component Identification Attributes

The following APIs provide extended capabilities for component identification attributes:

- [getInspectorByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectorbykey9): obtains all attributes of the component with the specified ID.

- [getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectortree9): obtains the component tree with component attributes.

- [sendEventByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#sendeventbykey9): sends an event to the component with the specified ID.

The following example demonstrates the basic usage of **getInspectorByKey**, **getInspectorTree**, and **sendEventByKey**.

<!-- @[componentIdentifier_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/checkpage/entry/src/main/ets/pages/ComponentPage1.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';
@Entry
@Component
struct ComponentPage {
  build() {
    Column() {
      Text('Hello World')
        .fontSize(20)
        .id('TEXT')
        .onClick(() => {
          hilog.info(0x0000,`Text is clicked`, 'isClicked');
        })
      Button('getInspectorByKey').onClick(() => {
        let result = getInspectorByKey('TEXT');
        hilog.info(0x0000,`result is ${result}`, 'result');
      })
      Button('getInspectorTree').onClick(() => {
        let result = getInspectorTree();
        hilog.info(0x0000,`result is ${JSON.stringify(result)}`, 'result');
      })
      Button('sendEventByKey').onClick(() => {
        sendEventByKey('TEXT', 10, '');
      })
    }
    .width('100%')
    .height('100%')
  }
}
```