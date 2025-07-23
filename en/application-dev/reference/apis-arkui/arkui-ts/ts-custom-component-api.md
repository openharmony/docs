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
| [UIContext](../js-apis-arkui-UIContext.md#uicontext) | **UIContext** instance obtained.|

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

Obtains the unique ID of this component. This unique ID is assigned by the system to each component. If this API is called before the component's corresponding node is created or after it has been destroyed, an invalid unique ID, which is **-1**, will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                     | Description                   |
| --------------------------------------------------------- | ----------------------- |
| number | Unique ID of the current Component.|

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

Queries the **NavDestination** information of this custom component. This API has effect only when the component is contained within a **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                                      | Description     |
| -------------------------------------------------------------------------- | --------- |
| [NavDestinationInfo](../js-apis-arkui-observer.md#navdestinationinfo) \| undefined | **NavDestinationInfo** instance obtained.|

**Example**

```ts
import { uiObserver } from '@kit.ArkUI';

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
    console.log('get navDestinationInfo: ' + JSON.stringify(this.navDesInfo));
  }

  build() {
    // ...
  }
}
```

## queryNavDestinationInfo<sup>18+</sup>

queryNavDestinationInfo(isInner: Optional\<boolean>): NavDestinationInfo | undefined

Queries the information about the nearest **NavDestination** component in the navigation stack for a custom component.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                         | Mandatory| Description                                         |
| ------ | --------------------------------------------- | ---- | --------------------------------------------- |
| isInner  | [Optional](ts-universal-attributes-custom-property.md#optional12)\<boolean> | Yes  | Whether to search inward for the nearest **NavDestination** component in the navigation stack.<br>**true**: Search inward.<br>**false**: Search outward.|

**Return value**

| Type                                                                      | Description     |
| -------------------------------------------------------------------------- | --------- |
| [NavDestinationInfo](../js-apis-arkui-observer.md#navdestinationinfo) \| undefined | **NavDestinationInfo** instance obtained.|

**Example**

```ts
// Index.ets
@Entry
@Component
struct NavigationExample {
  pageInfo: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageInfo) {
      Column() {
        Button('pageOne', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
          })
      }
    }.title('NavIndex')
  }
}
```

```ts
// PageOne.ets
import { uiObserver } from '@kit.ArkUI';

@Builder
export function PageOneBuilder() {
  PageOneComponent()
}

@Component
export struct PageOneComponent {
  navDesInfo: uiObserver.NavDestinationInfo | undefined;
  @State text: string = '';
  build() {
    NavDestination() {
      Column() {
        Button('Search Inward')
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            // Search inward for the NavDestination information for PageOne.
            this.navDesInfo = this.queryNavDestinationInfo(true);
            this.text = JSON.stringify(this.navDesInfo?.name).toString();
          })
        Text('The NavDestination component found inward is:' + this.text)
          .width('80%')
          .height(50)
          .margin(50)
          .fontSize(20)
        MyComponent()
      }.width('100%').height('100%')
    }
    .title('pageOne')
  }
}

@Component
struct MyComponent {
  navDesInfo: uiObserver.NavDestinationInfo | undefined;
  @State text: string = '';

  build() {
    Column() {
      Button('Search Outward')
        .width('80%')
        .height(40)
        .margin(20)
        .onClick(() => {
          // Search outward for the NavDestination information for PageOne.
          this.navDesInfo = this.queryNavDestinationInfo(false);
          this.text = JSON.stringify(this.navDesInfo?.name).toString();
        })
      Text('The NavDestination component found outward is:' + this.text)
        .width('80%')
        .height(50)
        .margin(50)
        .fontSize(20)
    }
  }
}
```

```ts
//route_map.json
{
  "routerMap": [
    {
      "name": "pageOne",
      "pageSourceFile": "src/main/ets/pages/PageOne.ets",
      "buildFunction": "PageOneBuilder",
      "data": {
        "description": "this is pageOne"
      }
    }
  ]
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
| [NavigationInfo](../js-apis-arkui-observer.md#navigationinfo12) \| undefined | **NavigationInfo** instance obtained.|

**Example**

```ts
// index.ets
import { uiObserver } from '@kit.ArkUI';

@Entry
@Component
struct MainPage {
  pathStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pathStack) {
      // ...
    }.id("NavigationId")
  }
}


@Component
export struct PageOne {
  pathStack: NavPathStack = new NavPathStack();

  aboutToAppear() {
    // this refers to the custom node PageOne and searches for the nearest parent node of the Navigation type from this node upwards.
    let navigationInfo: uiObserver.NavigationInfo | undefined = this.queryNavigationInfo();
    console.log('get navigationInfo: ' + JSON.stringify(navigationInfo));
    if (navigationInfo !== undefined) {
      this.pathStack = navigationInfo.pathStack;
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
| [RouterPageInfo](../js-apis-arkui-observer.md#routerpageinfo) \| undefined | **RouterPageInfo** instance obtained.|

**Example**

```ts
import { uiObserver } from '@kit.ArkUI';

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

## getDialogController<sup>18+</sup>

getDialogController(): PromptActionDialogController | undefined

Obtains a **PromptActionDialogController** instance.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [PromptActionDialogController](#promptactiondialogcontroller18) \| undefined | **PromptActionDialogController** instance obtained.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ComponentContent } from '@kit.ArkUI';

class Params {
  text: string = "";
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
  @Local message: string = "hello";

  build() {
    Row() {
      Column({ space: 10 }) {
        Button('click me')
          .fontSize(20)
          .onClick(() => {
            let ctx = this.getUIContext();
            let promptAction = ctx.getPromptAction();
            promptAction.openCustomDialog(new ComponentContent(ctx, wrapBuilder(buildText), new Params(this.message)))
              .catch((err: BusinessError) => {
                console.error("openCustomDialog error: " + err.code + " " + err.message);
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

## PromptActionDialogController<sup>18+</sup>

type PromptActionDialogController = promptAction.DialogController

Defines a custom dialog box controller, which can be used to control a custom dialog box, including actions such as closing the dialog box. For details, see [promptAction.DialogController](../js-apis-promptAction.md#dialogcontroller18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [promptAction.DialogController](../js-apis-promptAction.md#dialogcontroller18) | Instance of **promptAction.DialogController**.|
