# Custom Component Built-in APIs

Custom component built-in APIs are APIs predefined on the base class of custom components in the ArkUI framework. You can call these APIs on the instance of a custom component to obtain information, such as the UI context, about the instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## getUIContext

getUIContext(): UIContext

Obtains the **UIContext** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                     | Description                   |
| --------------------------------------------------------- | ----------------------- |
| [UIContext](../js-apis-arkui-UIContext.md#uicontext) | **UIContext** instance obtained. |

**Example**

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

Obtains the unique ID of this component. This unique ID is assigned by the system to each component. If this API is called before the component is built, an invalid value **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                     | Description                   |
| --------------------------------------------------------- | ----------------------- |
| number | Unique ID of the current Component. |

**Example**

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

Queries the **NavDestination** information of this custom component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                                      | Description     |
| -------------------------------------------------------------------------- | --------- |
| [NavDestinationInfo](../js-apis-arkui-observer.md#navdestinationinfo) \| undefined | **NavDestinationInfo** instance obtained. |

**Example**

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
    // this refers to the custom node MyComponent and searches for the nearest parent node of the NavDestination type from this node upwards.
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

Queries the **Navigation** information of this custom component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                                      | Description     |
| -------------------------------------------------------------------------- | --------- |
| [NavigationInfo](../js-apis-arkui-observer.md#navigationinfo12) \| undefined | **NavigationInfo** instance obtained. |

**Example**

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
    // this refers to the custom node PageOne and searches for the nearest parent node of the Navigation type from this node upwards.
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

Obtains a **RouterPageInfo** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [RouterPageInfo](../js-apis-arkui-observer.md#routerpageinfo) \| undefined | **RouterPageInfo** instance obtained. |

**Example**

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
