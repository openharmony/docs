# @ohos.arkui.UIContext (UIContext) (System API)

In the stage model, a window stage or window can use the **loadContent** API to load pages, create a UI instance, and render page content to the associated window. Naturally, UI instances and windows are associated on a one-by-one basis. Some global UI APIs are executed in the context of certain UI instances. When calling these APIs, you must identify the UI context, and consequently UI instance, by tracing the call chain. If these APIs are called on a non-UI page or in some asynchronous callback, the current UI context may fail to be identified, resulting in API execution errors.

**@ohos.window** adds the [getUIContext](./js-apis-window.md#getuicontext10) API in API version 10 for obtaining the **UIContext** object of a UI instance. The API provided by the **UIContext** object can be directly applied to the corresponding UI instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device, but not in DevEco Studio Previewer.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.arkui.UIContext (UIContext)](js-apis-arkui-UIContext.md).

## UIContext

In the following API examples, you must first use [getUIContext()](./js-apis-window.md#getuicontext10) in **@ohos.window** to obtain a **UIContext** instance, and then call the APIs using the obtained instance. In this document, the **UIContext** instance is represented by **uiContext**.

### setDynamicDimming<sup>12+<sup>

setDynamicDimming(id: string, value: number): void

Sets the dynamic dimming degree of the component.


> **NOTE**
>
> Applying other visual effects after this API is called may result in conflicts.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| id | string | Yes| Component ID.|
| value | number | Yes| Dynamic dimming degree of the component. The value range is [0, 1]. The component is brighter with a larger value.|

**Example**

```ts
@Entry
@Component
struct Index {
  @State
  myCount : number = 100

  build() {
    Column(){
      Image($r('app.media.testImage')).width(500).height(800).id("test")
    }.width("100%").height("100%").onClick(()=>{
      this.getUIContext().setDynamicDimming("test",1)
      animateTo({duration:5000 },()=>{
        this.getUIContext().setDynamicDimming("test",0)
      })
    })
  }
}
```
![api-switch-overview](../apis-arkui/figures/dynamicDinning.gif)

### animateToImmediately<sup>12+</sup>

animateToImmediately(param: AnimateParam , event: () => void): void

Implements immediate delivery of an explicit animation through a **UIContext** object. When multiple property animations are loaded at once, you can call this API to immediately execute the transition animation for state changes caused by the specified closure function.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                      | Mandatory  | Description                                   |
| ----- | ---------------------------------------- | ---- | ------------------------------------- |
| param | [AnimateParam](arkui-ts/ts-explicit-animation.md#animateparam) | Yes   | Animation settings.                          |
| event | () => void                               | Yes   | Closure function that displays the animation. The system automatically inserts the transition animation if the state changes in the closure function.|

**Example**

This example shows how to use **animateToImmediately** to implement immediate delivery of an explicit animation through a **UIContext** object.

```ts
// xxx.ets
@Entry
@Component
struct AnimateToImmediatelyExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State opacitySize: number = 0
  private flag: boolean = true
  uiContext: UIContext | null | undefined = this.getUIContext();

  build() {
    Column() {
      Column()
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Green)
        .opacity(this.opacitySize)
      Button('change size')
        .margin(30)
        .onClick(() => {
          if (this.flag) {
            this.uiContext?.animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.opacitySize = 1
            })
            this.uiContext?.animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.widthSize = 150
              this.heightSize = 60
            })
          } else {
            this.uiContext?.animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.widthSize = 250
              this.heightSize = 100
            })
            this.uiContext?.animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.opacitySize = 0
            })
          }
          this.flag = !this.flag
        })
    }.width('100%').margin({ top: 5 })
  }
}
```
![animateToImmediately](figures/animateToImmediately.gif)

### freezeUINode<sup>18+</sup>

freezeUINode(id: string, isFrozen: boolean): void

Sets whether to freeze a specific component by **id** to prevent it from marking itself as dirty and triggering layout updates.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type   | Mandatory  | Description     |
| --- | --- | --- | --- |
| id | string | Yes| ID of the target component.|
| isFrozen | boolean | Yes| Whether to freeze the component.<br>Default value: **false**|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The caller is not a system application. |

```js
@Entry
@Component
struct Index {
  @State columnWidth1: string = '100%';
  @State currentIndex: number = 0;
  private controller: TabsController = new TabsController();

  build() {
    Column() {
      Tabs({ 
        barPosition: BarPosition.Start, 
        index: this.currentIndex, 
        controller: this.controller 
      }) {
        TabContent() {
          Column()
          .width(this.columnWidth1)
          .height('100%')
          .backgroundColor('#00CB87')
        }
        .tabBar('green')
        .id('tab1')
        .onWillHide(() => {
          this.getUIContext().freezeUINode('tab1', true);
        })
        .onWillShow(() => {
          this.getUIContext().freezeUINode('tab1', false);
        })

        TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#007DFF')
        }
        .tabBar('blue')
        .id('tab2')
        .onWillHide(() => {
          this.getUIContext().freezeUINode('tab2', true);
        })
        .onWillShow(() => {
          this.getUIContext().freezeUINode('tab1', true);
          this.columnWidth1 = '50%';
          setTimeout(() => {
            this.getUIContext().freezeUINode('tab1', false);
            this.columnWidth1 = '20%';
          }, 5000)
        })

         TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#FFBF00')
        }
        .tabBar('yellow')
        .id('tab3')
        .onWillHide(() => {
          this.getUIContext().freezeUINode('tab3', true);
        })
        .onWillShow(() => {
          this.getUIContext().freezeUINode('tab3', false);
        })

      }
      .vertical(false)
      .barMode(BarMode.Fixed)
      .barWidth(360)
      .barHeight(56)
      .animationDuration(0)
      .onChange((index: number) => {
        this.currentIndex = index;
      })
      .width(360)
      .height(296)
      .margin({ top: 52 })
      .backgroundColor('#F1F3F5')
    }.width('100%')
  }
}
```

### freezeUINode<sup>18+</sup>

freezeUINode(uniqueId: number, isFrozen: boolean): void

Sets whether to freeze a specific component by **uniqueId** to prevent it from marking itself as dirty and triggering layout updates.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type   | Mandatory  | Description     |
| --- | --- | --- | --- |
| uniqueId | number | Yes| Unique ID of the target component.|
| isFrozen | boolean | Yes| Whether to freeze the component.<br>Default value: **false**|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The caller is not a system application. |

```js
@Entry
@Component
struct Index {
  @State columnWidth1: string = '100%';
  @State currentIndex: number = 0;
  private controller: TabsController = new TabsController();

  build() {
    Column() {
      Tabs({ 
        barPosition: BarPosition.Start, 
        index: this.currentIndex, 
        controller: this.controller 
      }) {
        TabContent() {
          Column()
          .width(this.columnWidth1)
          .height('100%')
          .backgroundColor('#00CB87')
        }
        .tabBar('green')
        .id('tab1')
        .onWillHide(() => {
          const node = this.getUIContext().getFrameNodeById('tab1');
          const uniqueId = node?.getUniqueId();
          this.getUIContext().freezeUINode(uniqueId, true);
        })
        .onWillShow(() => {
          const node = this.getUIContext().getFrameNodeById('tab1');
          const uniqueId = node?.getUniqueId();
          this.getUIContext().freezeUINode(uniqueId, false)
        })

        TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#007DFF')
        }
        .tabBar('blue')
        .id('tab2')
        .onWillHide(() => {
          const node = this.getUIContext().getFrameNodeById('tab2');
          const uniqueId = node?.getUniqueId();
          this.getUIContext().freezeUINode(uniqueId, true);
        })
        .onWillShow(() => {
          const node = this.getUIContext().getFrameNodeById('tab1');
          const uniqueId = node?.getUniqueId();
          this.getUIContext().freezeUINode(uniqueId, true);

          this.columnWidth1 = '50%';
          setTimeout(() => {
            this.getUIContext().freezeUINode(uniqueId, false);
            this.columnWidth1 = '20%';
          }, 5000)
        })

         TabContent() {
          Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#FFBF00')
        }
        .tabBar('yellow')
        .id('tab3')
        .onWillHide(() => {
          const node = this.getUIContext().getFrameNodeById('tab3');
          const uniqueId = node?.getUniqueId();
          this.getUIContext().freezeUINode(uniqueId, true);
        })
        .onWillShow(() => {
          const node = this.getUIContext().getFrameNodeById('tab3');
          const uniqueId = node?.getUniqueId();
          this.getUIContext().freezeUINode(uniqueId, false);
        })

      }
      .vertical(false)
      .barMode(BarMode.Fixed)
      .barWidth(360)
      .barHeight(56)
      .animationDuration(0)
      .onChange((index: number) => {
        this.currentIndex = index;
      })
      .width(360)
      .height(296)
      .margin({ top: 52 })
      .backgroundColor('#F1F3F5')
    }.width('100%')
  }
}
```
