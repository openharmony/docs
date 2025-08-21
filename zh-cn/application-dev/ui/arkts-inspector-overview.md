# 检查页面布局
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

inspector用于检查页面布局，通过inspector双向定位功能帮助开发者在DevEco Studio中快速定位组件、修改属性和调试组件，以提高开发效率。

ArkUI获取当前显示页面中所有组件的信息，包括组件树的父子结构、尺寸、位置、样式、属性和状态。获取组件树信息后，生成并展示为Inspector组件树。DevEco Studio的使用具体可以参考[Inspector调试能力](ui-inspector-profiler.md#inspector调试能力)。

inspector针对UI组件的布局或绘制送显完成，还提供了注册与取消监听函数的C API接口，具体使用可以参考[监听组件布局和绘制送显事件](ndk-inspector-component-observer.md)。

## 使用约束

1. 不支持动效类组件的控件树实时刷新功能。

2. 支持获取组件的属性和样式，但不支持获取controller和Builder对象。

3. 不支持获取组件的方法、事件。

## UIContext查询组件树和组件信息能力

ArkUI提供@ohos.arkui.UIContext(UIContext)扩展能力，通过[getFilteredInspectorTree](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getfilteredinspectortree12)获取组件树及组件属性，通过[getFilteredInspectorTreeById](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getfilteredinspectortreebyid12)获取指定的组件及其子组件的属性。支持设置过滤条件进行查询。

下述示例，展示了getFilteredInspectorTree和getFilteredInspectorTreeById的基本用法。

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
          console.error(`getFilteredInspectorTreeById error: ${e}`);
        }
      })

    }
    .width('100%')
    .height('100%')
  }
}
```

## 布局回调

通过[@ohos.arkui.arkui.inspector(布局回调)](../reference/apis-arkui/js-apis-arkui-inspector.md)提供注册组件布局和组件绘制完成的回调通知能力。

下述示例，展示了布局回调的基本用法。

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
      // 补充待实现的功能
    }
    let onDrawComplete:()=>void=():void=>{
      // 补充待实现的功能
    }
    let onDrawChildrenComplete:()=>void=():void=>{
      // 补充待实现的功能
    }
    let FuncLayout = onLayoutComplete // 绑定当前js对象
    let FuncDraw = onDrawComplete // 绑定当前js对象
    let FuncDrawChildren = onDrawChildrenComplete // 绑定当前js对象
    let OffFuncLayout = onLayoutComplete // 绑定当前js对象
    let OffFuncDraw = onDrawComplete // 绑定当前js对象
    let OffFuncDrawChildren = onDrawChildrenComplete // 绑定当前js对象

    this.listener.on('layout', FuncLayout)
    this.listener.on('draw', FuncDraw)
    this.listener.on('drawChildren', FuncDrawChildren)

    // 通过句柄向对应的查询条件取消注册回调，由开发者自行决定在何时调用。
    // this.listener.off('layout', OffFuncLayout)
    // this.listener.off('draw', OffFuncDraw)
    // this.listener.off('drawChildren', OffFuncDrawChildren)
  }
}
```

## 组件标识属性的扩展能力

通过getInspectorByKey、getInspectorTree、sendEventByKey提供组件标识属性扩展能力，具体如下：
- [getInspectorByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectorbykey9)，获取指定id的组件的所有属性。
- [getInspectorTree](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#getinspectortree9)，获取组件树及组件属性。
- [sendEventByKey](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#sendeventbykey9)，给指定id的组件发送事件。

下述示例，展示了getInspectorByKey、getInspectorTree和sendEventByKey的基本用法。

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