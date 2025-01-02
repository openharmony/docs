# 自定义组件内置方法

自定义组件内置方法是由ArkUI开发框架提供给应用开发者的，定义在自定义组件基类上的API。应用开发者可以在自定义组件的实例上调用对应的API以获取当前自定义组件实例相关的信息。例如，查询当前自定义组件上下文的UIContext信息。

> **说明：**
>
> 本模块首批接口从API version 11开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## getUIContext

getUIContext(): UIContext

获取UIContext对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                      | 说明                    |
| --------------------------------------------------------- | ----------------------- |
| [UIContext](../js-apis-arkui-UIContext.md#uicontext) | 返回UIContext实例对象。 |

**示例：**

```ts
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    let uiContext: UIContext = this.getUIContext();
  }

  build() {
    // ...
  }
}
```

## getUniqueId<sup>12+</sup>

getUniqueId(): number

获取当前Component的UniqueId。UniqueId为系统为每个组件分配的Id，可保证当前应用中的唯一性。若在组件对应的节点未创建或已销毁时获取，返回无效UniqueId：-1。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                      | 说明                    |
| --------------------------------------------------------- | ----------------------- |
| number | 返回当前Component的UniqueId。 |

**示例：**

```ts
@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    let uniqueId: number = this.getUniqueId();
  }

  build() {
    // ...
  }
}
```

## queryNavDestinationInfo

queryNavDestinationInfo(): NavDestinationInfo | undefined;

查询自定义组件所属的NavDestination信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                                       | 说明      |
| -------------------------------------------------------------------------- | --------- |
| [NavDestinationInfo](../js-apis-arkui-observer.md#navdestinationinfo) \| undefined | 返回NavDestinationInfo实例对象。 |

**示例：**

```ts
import { uiObserver } from '@kit.ArkUI'

@Component
export struct NavDestinationExample {
  build() {
    NavDestination() {
      MyComponent()
    }
  }
}

@Component
struct MyComponent {
  navDesInfo: uiObserver.NavDestinationInfo | undefined

  aboutToAppear() {
    // this指代MyComponent自定义节点，并从该节点向上查找其最近的一个类型为NavDestination的父亲节点
    this.navDesInfo = this.queryNavDestinationInfo();
    console.log('get navDestinationInfo: ' + JSON.stringify(this.navDesInfo))
  }

  build() {
    // ...
  }
}
```

## queryNavigationInfo<sup>12+</sup>

queryNavigationInfo(): NavigationInfo | undefined

查询自定义组件所属的Navigation信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                                       | 说明      |
| -------------------------------------------------------------------------- | --------- |
| [NavigationInfo](../js-apis-arkui-observer.md#navigationinfo12) \| undefined | 返回NavigationInfo实例对象。 |

**示例：**

```ts
// index.ets
import { uiObserver } from '@kit.ArkUI'

@Entry
@Component
struct MainPage {
  pathStack: NavPathStack = new NavPathStack()

  build() {
    Navigation(this.pathStack) {
      // ...
    }.id("NavigationId")
  }
}


@Component
export struct PageOne {
  pathStack: NavPathStack = new NavPathStack()

  aboutToAppear() {
    // this指代PageOne自定义节点，并从该节点向上查找其最近的一个类型为Navigation的父亲节点
    let navigationInfo: uiObserver.NavigationInfo | undefined = this.queryNavigationInfo()
    console.log('get navigationInfo: ' + JSON.stringify(navigationInfo))
    if (navigationInfo !== undefined) {
      this.pathStack = navigationInfo.pathStack
    }
  }

  build() {
    NavDestination() {
      // ...
    }.title('PageOne')
  }
}
```

## queryRouterPageInfo<sup>12+</sup>

queryRouterPageInfo(): RouterPageInfo | undefined;

获取RouterPageInfo实例对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                         | 说明                         |
| ------------------------------------------------------------ | ---------------------------- |
| [RouterPageInfo](../js-apis-arkui-observer.md#routerpageinfo) \| undefined | 返回RouterPageInfo实例对象。 |

**示例：**

```ts
import { uiObserver } from '@kit.ArkUI'

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    let info: uiObserver.RouterPageInfo | undefined = this.queryRouterPageInfo();
  }

  build() {
    // ...
  }
}
```

## getDialogController<sup>16+</sup>

getDialogController(): PromptActionDialogController | undefined

获取PromptActionDialogController实例对象。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                         | 说明                         |
| ------------------------------------------------------------ | ---------------------------- |
| [PromptActionDialogController](#promptactiondialogcontroller16) \| undefined | 返回PromptActionDialogController实例对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ComponentContent } from '@kit.ArkUI';

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

@ComponentV2
struct MyComponent {
  build() {
    Column() {
      Button('Close Dialog')
        .onClick(() => {
          let ctrl: PromptActionDialogController = this.getDialogController();
          if (ctrl != undefined) {
            ctrl.close();
          }
        })
    }
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
    MyComponent()
  }.backgroundColor('#FFF0F0F0')
}

@Entry
@ComponentV2
struct Index {
  @Local message: string = "hello"

  build() {
    Row() {
      Column({ space: 10 }) {
        Button('click me')
          .fontSize(20)
          .onClick(() => {
            let ctx = this.getUIContext()
            let promptAction = ctx.getPromptAction()
            promptAction.openCustomDialog(new ComponentContent(ctx, wrapBuilder(buildText), new Params(this.message)))
              .catch((err: BusinessError) => {
                console.error("openCustomDialog error: " + err.code + " " + err.message)
              })
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

## PromptActionDialogController<sup>16+</sup>

type PromptActionDialogController = promptAction.DialogController

自定义弹窗控制器，可以控制当前自定义弹窗，具体控制能力包括关闭弹窗等，详见[promptAction.DialogController](../js-apis-promptAction.md#dialogcontroller16)。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                         |
| ------------------------------------------------------------ | ---------------------------- |
| [promptAction.DialogController](../js-apis-promptAction.md#dialogcontroller16) | 表示对象类型为promptAction.DialogController实例对象。 |
