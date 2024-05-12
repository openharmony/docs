# 自定义组件内置方法

自定义组件内置方法是由ArkUI开发框架提供给应用开发者的，定义在自定义组件基类上的API。应用开发者可以在自定义组件的实例上调用对应的API以获取当前自定义组件实例相关的信息。例如，查询当前自定组件上下文的UIContext信息。

> **说明：**
>
> 本模块首批接口从API version 11开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## getUIContext

getUIContext(): UIContext

获取UIContext对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                      | 说明                    |
| --------------------------------------------------------- | ----------------------- |
| [UIContext](../js-apis-arkui-UIContext.md#uicontext) | 返回UIContext实例对象。 |

**示例：**

```ts
import { UIContext } from '@ohos.arkui.UIContext';

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

获取当前Component的UniqueId。UniqueId为系统为每个组件分配的Id，可保证唯一性。若在组件未构建时获取，返回无效UniqueId：-1。

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

获取NavDestinationInfo实例对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                                       | 说明      |
| -------------------------------------------------------------------------- | --------- |
| [NavDestinationInfo](../js-apis-arkui-observer.md#navdestinationinfo) \| undefined | 返回NavDestinationInfo实例对象。 |

**示例：**

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct MyComponent {
  aboutToAppear() {
    let info: observer.NavDestinationInfo | undefined = this.queryNavDestinationInfo();
  }

  build() {
    // ...
  }
}
```

## queryNavigationInfo<sup>12+</sup>

queryNavigationInfo(): NavigationInfo | undefined

获取NavigationInfo实例对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                                       | 说明      |
| -------------------------------------------------------------------------- | --------- |
| [NavigationInfo](../js-apis-arkui-observer.md#navigationinfo) \| undefined | 返回NavigationInfo实例对象。 |

**示例：**

```ts
// index.ets
// an independent page in harPackage
import { example1 } from 'harPackage'
// another independent page in hspPackage
import { example2 } from 'hspPackage'

@Entry
@Component
struct MainPage {
  @Provide('pageInfo') pageInfos: NavPathStack = new NavPathStack()

  build() {
    Navigation(this.pageInfos) {
      Column() {
        Button('jumpTo Example1 in HarPackage', { stateEffect: true, type: ButtonType.Capsule })
          .onClick(() => {
            this.PageInfos.pushPath({ name: 'Example1', param: 'Example1'})
          })
        Button('jumpTo Example2 in HspPackage', { stateEffect: true, type: ButtonType.Capsule })
          .onClick(() => {
            this.PageInfos.pushPath({ name: 'Example2', param: 'Example2'})
          })
      }
    }
  }
}
```

```json
// router_map.json in HarPackage
{
  "routerMap": [
    {
      "name": "Example1",
      "pageSourceFile": "src/main/ets/pages/example1.ets",
      "buildFunction": "Example1",
      "data": {
        "data": "test"
      }
    }
  ]
}
```

```ts
// example1.ets in HarPackage
import observer from '@ohos.arkui.observer'

@Builder
export function Example1(name: string, param: Object) {
  NavDestination() {
    CustomNode()
  }.title('Example1')
  .id('NavdestinationExample1')
}

@Component
export struct CustomNode() {
  pathStack: NavPathStack = new NavPathStack()

  aboutToAppear() {
    // query Navigation Info of index.ets
    let navigationInfo: observer.NavigationInfo | undefined = this.queryNavigationInfo()
    console.log('get navigationInfo: ' + JSON.stringfy(navigationInfo))
    if (navigationInfo !== undefined) {
      this.pathStack = navigation.pathStack
    }
  }

  build() {
    // xxx
  }
}
```

```json
// router_map.json in HsprPackage
{
  "routerMap": [
    {
      "name": "Example2",
      "pageSourceFile": "src/main/ets/pages/example2.ets",
      "buildFunction": "Example2",
      "data": {
        "data": "test"
      }
    }
  ]
}
```

```ts
// example2.ets in HarPackage
import observer from '@ohos.arkui.observer'

@Builder
export function Example2(name: string, param: Object) {
  NavDestination() {
    CustomNode()
  }.title('Example2')
  .id('NavdestinationExample2')
}

@Component
export struct CustomNode() {
  pathStack: NavPathStack = new NavPathStack()

  aboutToAppear() {
    // query Navigation Info of index.ets
    let navigationInfo: observer.NavigationInfo | undefined = this.queryNavigationInfo()
    console.log('get navigationInfo: ' + JSON.stringfy(navigationInfo))
    if (navigationInfo !== undefined) {
      this.pathStack = navigation.pathStack
    }
  }

  build() {
    // xxx
  }
}
```
