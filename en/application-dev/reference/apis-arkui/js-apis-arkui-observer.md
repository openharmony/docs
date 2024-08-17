# @ohos.arkui.observer (Observer)

The **Observer** module provides APIs for listening for UI component behavior changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```ts
import { uiObserver as observer } from '@kit.ArkUI';
```

## NavDestinationState

Describes the state of the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Value | Description                    |
| --------- | --- | ------------------------ |
| ON_SHOWN  | 0   | The **NavDestination** component is displayed.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 11. |
| ON_HIDDEN | 1   | The **NavDestination** component is hidden.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 11. |
| ON_APPEAR<sup>12+</sup> | 2   | The **NavDestination** component is mounted to the component tree.<br> **Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| ON_DISAPPEAR<sup>12+</sup> | 3   | The **NavDestination** component is unmounted from the component tree.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| ON_WILL_SHOW<sup>12+</sup> | 4   | The **NavDestination** is about to be displayed.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| ON_WILL_HIDE<sup>12+</sup> | 5   | The **NavDestination** component is about to be hidden.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12. |
| ON_WILL_APPEAR<sup>12+</sup>| 6   | The **NavDestination** component is about to be mounted to the component tree.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| ON_WILL_DISAPPEAR<sup>12+</sup>| 7   | The **NavDestination** component is about to be unmounted from the component tree.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| ON_BACKPRESS<sup>12+</sup> | 100   | The back button is pressed on the **NavDestination** component.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|

## ScrollEventType<sup>12+</sup>

Enumerates the scroll event types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Value | Description                    |
| --------- | --- | ------------------------ |
| SCROLL_START  | 0   | The scroll event starts. |
| SCROLL_STOP   | 1   | The scroll event ends. |

## RouterPageState

Enumerates the states of a page during routing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Value | Description                   |
| ----------------- | --- | ----------------------- |
| ABOUT_TO_APPEAR       | 0   | The page is about to be displayed.           |
| ABOUT_TO_DISAPPEAR    | 1   | The page is about to be destroyed.        |
| ON_PAGE_SHOW          | 2   | The page is displayed.               |
| ON_PAGE_HIDE          | 3   | The page is hidden.               |
| ON_BACK_PRESS         | 4   | The page is returned.             |

## TabContentState<sup>12+</sup>

Enumerates the states of the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Value | Description                   |
| ----------------- | --- | ----------------------- |
| ON_SHOW           | 0   | The **TabContent** component is displayed.   |
| ON_HIDE           | 1   | The **TabContent** component is hidden.   |

## NavDestinationInfo

Provides information about the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory | Description                                        |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | Yes  | ID of the **Navigation** component that contains the target **NavDestination** component. |
| name         | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | Yes  | Name of the **NavDestination** component. |
| state        | [NavDestinationState](#navdestinationstate)        | Yes  | State of the **NavDestination** component. |
| index<sup>12+</sup>        | number        | Yes  | Index of the **NavDestination** component in the navigation stack.                  |
| param<sup>12+</sup>        | Object        | No  | Parameters of the **NavDestination** component.                  |
| navDestinationId<sup>12+</sup>        | string        | Yes  | Unique ID of the **NavDestination** component.                  |

## NavigationInfo<sup>12+</sup>

Provides information about the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory | Description                                        |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | string | Yes  | ID of the **Navigation** component. |
| pathStack         | [NavPathStack](arkui-ts/ts-basic-components-navigation.md#navpathstack10) | Yes  | Routing stack of the **Navigation** component.                  |

## ScrollEventInfo<sup>12+</sup>

Provides the scroll event information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory | Description                                        |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| id           | string                                             | Yes  | ID of the scrollable component.                              |
| uniqueId           | number                                             | Yes  | Unique ID of the scrollable component.                              |
| scrollEvent    | [ScrollEventType](#scrolleventtype12)                | Yes  | Type of the scroll event.                            |
| offset       | number                                             | Yes  | Current offset of the scrollable component.                       |

## ObserverOptions<sup>12+</sup>

Describes the observer options.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory | Description                                        |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| id           | string                                             | Yes  | Component ID.                              |

## RouterPageInfo

Provides the information about a page during routing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                | Type                                                        | Mandatory | Description                                          |
| -------------------- | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| context              | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) \| [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context of the router page that invokes the lifecycle callback. |
| index                | number                                                       | Yes  | Position of the router page that invokes the lifecycle callback, in the navigation stack.        |
| name                 | string                                                       | Yes  | Name of the page that invokes the lifecycle callback.          |
| path                 | string                                                       | Yes  | Path of the page that invokes the lifecycle callback.          |
| state                | [RouterPageState](#routerpagestate)                          | Yes  | State of the router page that invokes the lifecycle callback.          |
| pageId<sup>12+</sup> | string                                                       | Yes  | Unique ID of the router page that invokes the lifecycle callback.      |

## DensityInfo<sup>12+</sup>

Provides the information contained in the callback when the screen pixel density changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                     | Mandatory | Description                                  |
| ------- | ----------------------------------------- | ---- | -------------------------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context corresponding to the page when the screen pixel density changes. |
| density | number                                    | Yes  | Screen pixel density after the change.                |

## NavDestinationSwitchInfo<sup>12+</sup>

Provides the information about page switching of the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory | Description                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| context      | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) \| [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information corresponding to **Navigation** component that triggers page switching. |
| from         | [NavDestinationInfo](#navdestinationinfo) \| [NavBar](./arkui-ts/ts-basic-components-navigation.md#navbar12) | Yes  | Source page for page switching.        |
| to           | [NavDestinationInfo](#navdestinationinfo) \| [NavBar](./arkui-ts/ts-basic-components-navigation.md#navbar12) | Yes  | Destination page for page switching.        |
| operation    | [NavigationOperation](./arkui-ts/ts-basic-components-navigation.md#navigationoperation11) | Yes  | Page switching operation type.        |

## NavDestinationSwitchObserverOptions<sup>12+</sup>

Provides the observer options for the page switching event of the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory | Description                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | Yes  | ID of the target **Navigation** component. |

## TabContentInfo<sup>12+</sup>

Provides the **TabContent** switching information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory | Description                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| tabContentId | string                                             | Yes  | ID of the **TabContent** component.                         |
| tabContentUniqueId | number                                       | Yes  | Unique ID of the **TabContent** component.                   |
| state        | [TabContentState](#tabcontentstate12)              | Yes  | State of the **TabContent** component.                       |
| id           | string                                             | Yes  | ID of the **Tabs** component.                               |
| uniqueId     | number                                             | Yes  | Unique ID of the **Tabs** component.                         |

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', callback: Callback\<NavDestinationInfo\>): void

Subscribes to status changes of the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                 | Mandatory | Description                                                                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **NavDestination** component. |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | Yes  | Callback used to return the current state of the **NavDestination** component.                            |

**Example**

```ts
observer.on('navDestinationUpdate', (info) => {
  console.info('NavDestination state update', JSON.stringify(info));
});
```

## observer.off('navDestinationUpdate')

off(type: 'navDestinationUpdate', callback?: Callback\<NavDestinationInfo\>): void

Unsubscribes from status changes of the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                 | Mandatory | Description                                                                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **NavDestination** component. |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | No  | Callback used to return the current state of the **NavDestination** component.                            |

**Example**

```ts
observer.off('navDestinationUpdate');
```

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback: Callback\<NavDestinationInfo\>): void

Subscribes to status changes of the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                                | Mandatory | Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **NavDestination** component. |
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | Yes  | ID of the **Navigation** component that contains the target **NavDestination** component.                                              |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>                | Yes  | Callback used to return the current state of the **NavDestination** component.                            |

**Example**

```ts
observer.on('navDestinationUpdate', { navigationId: "testId" }, (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

## observer.off('navDestinationUpdate')

off(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback?: Callback\<NavDestinationInfo\>): void

Unsubscribes from status changes of the **NavDestination** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                                | Mandatory | Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **NavDestination** component. |
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | Yes  | ID of the **Navigation** component that contains the target **NavDestination** component.                                              |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>                | No  | Callback used to return the current state of the **NavDestination** component.                            |

**Example**

```ts
observer.off('navDestinationUpdate', { navigationId: "testId" });
```

## observer.on('scrollEvent')<sup>12+</sup>

on(type: 'scrollEvent', callback: Callback\<ScrollEventInfo\>): void

Subscribes to the start and end of a scroll event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                 | Mandatory | Description                                                                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value **'scrollEvent'** indicates the start and end of a scroll event.                  |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>       | Yes  | Callback used to return the Callback used to return the information about the scroll event.                                          |

**Example**

See the example of [offscrollevent](#observeroffscrollevent12-1).

## observer.off('scrollEvent')<sup>12+</sup>

off(type: 'scrollEvent', callback?: Callback\<ScrollEventInfo\>): void

Unsubscribes from the start and end of a scroll event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                 | Mandatory | Description                                                                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value **'scrollEvent'** indicates the start and end of a scroll event.                  |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>       | No  | Callback used to return the Callback used to return the information about the scroll event.                                          |

**Example**

See the example of [offscrollevent](#observeroffscrollevent12-1).

## observer.on('scrollEvent')<sup>12+</sup>

on(type: 'scrollEvent', options: ObserverOptions, callback: Callback\<ScrollEventInfo\>): void

Subscribes to the start and end of a scroll event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                                | Mandatory | Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value **'scrollEvent'** indicates the start and end of a scroll event.                  |
| options  | [ObserverOptions](#observeroptions12)                                  | Yes  | ID of the target scrollable component.                                                |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>                      | Yes  | Callback used to return the Callback used to return the information about the scroll event.                                           |

**Example**

See the example of [offscrollevent](#observeroffscrollevent12-1).

## observer.off('scrollEvent')<sup>12+</sup>

off(type: 'scrollEvent', options: ObserverOptions, callback?: Callback\<ScrollEventInfo\>): void

Unsubscribes from the start and end of a scroll event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                                | Mandatory | Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value **'scrollEvent'** indicates the start and end of a scroll event.                  |
| options  | [ObserverOptions](#observeroptions12)                                  | Yes  | ID of the target scrollable component.                                                |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>                      | No  | Callback used to return the Callback used to return the information about the scroll event.                                           |

**Example**

```ts
import { uiObserver as observer } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  scroller: Scroller = new Scroller();
  options: observer.ObserverOptions = { id:"testId" };
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7]

  build() {
    Row() {
      Column() {
        Scroll(this.scroller) {
          Column() {
            ForEach(this.arr, (item: number) => {
              Text(item.toString())
                .width('90%')
                .height(150)
                .backgroundColor(0xFFFFFF)
                .borderRadius(15)
                .fontSize(16)
                .textAlign(TextAlign.Center)
                .margin({ top: 10 })
            }, (item: string) => item)
          }.width('100%')
        }
        .id("testId")
        .height('80%')
      }
      .width('100%')

      Row() {
        Button('UIObserver on')
          .onClick(() => {
            observer.on('scrollEvent', (info) => {
              console.info('scrollEventInfo', JSON.stringify(info));
            });
          })
        Button('UIObserver off')
          .onClick(() => {
            observer.off('scrollEvent');
          })
      }

      Row() {
        Button('UIObserverWithId on')
          .onClick(() => {
            observer.on('scrollEvent', this.options, (info) => {
              console.info('scrollEventInfo', JSON.stringify(info));
            });
          })
        Button('UIObserverWithId off')
          .onClick(() => {
            observer.off('scrollEvent', this.options);
          })
      }
    }
    .height('100%')
  }
}
```

## observer.on('routerPageUpdate')<sup>11+</sup>

on(type: 'routerPageUpdate', context: UIAbilityContext | UIContext, callback: Callback\<RouterPageInfo\>): void

Subscribes to state changes of the page during routing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'routerPageUpdate'**, which indicates the state change event of the page during routing. |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for. |
| callback | Callback\<[RouterPageInfo](#routerpageinfo)\>        | Yes  | Callback used to return the If **pageInfo** is passed, the current page state is returned.                |

**Example**

```ts
// used in UIAbility
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { UIContext, window, uiObserver as observer } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  private uiContext: UIContext | null = null;

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // Subscribe to the target events within the scope of the page under the ability context.
    observer.on('routerPageUpdate', this.context, (info: observer.RouterPageInfo) => {
      console.info('[uiObserver][abilityContext] got info: ' + JSON.stringify(info))
    })
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      windowStage.getMainWindow((err: BusinessError, data) => {
        let windowInfo: window.Window = data;
        // Obtain a UIContext instance.
        this.uiContext = windowInfo.getUIContext();
        // Subscribe to the target events within the scope of the page under the UI context.
        observer.on('routerPageUpdate', this.uiContext, (info: observer.RouterPageInfo)=>{
          console.info('[uiObserver][uiContext] got info: ' + JSON.stringify(info))
        })
      })
    });
  }

  // ... other function in EntryAbility
}
```

## observer.off('routerPageUpdate')<sup>11+</sup>

off(type: 'routerPageUpdate', context: UIAbilityContext | UIContext, callback?: Callback\<RouterPageInfo\>): void

Unsubscribes to state changes of the page during routing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'routerPageUpdate'**, which indicates the state change event of the page during routing. |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for. |
| callback | Callback\<[RouterPageInfo](#routerpageinfo)\>        | No  | Callback to be unregistered.                |

**Example**

```ts
// used in UIAbility
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { uiObserver as observer, UIContext } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // Before actual use, uiContext must be assigned a value. For details, see the example of observer.on('routerPageUpdate').
  private uiContext: UIContext | null = null;

  onDestroy(): void {
    // Unregister all callbacks for the routerPageUpdate event under the current ability context.
    observer.off('routerPageUpdate', this.context)
  }

  onWindowStageDestroy(): void {
    // Unregister all callbacks for the routerPageUpdate event under the UI context.
    if (this.uiContext) {
      observer.off('routerPageUpdate', this.uiContext);
    }
  }

  // ... other function in EntryAbility
}
```

## observer.on('densityUpdate')<sup>12+</sup>

on(type: 'densityUpdate', context: UIContext, callback: Callback\<DensityInfo\>): void

Subscribes to the pixel density changes of the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'densityUpdate'** indicates the pixel density changes of the screen. |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for. |
| callback | Callback\<[DensityInfo](#densityinfo12)\>        | Yes  | Callback used to return the screen pixel density after the change.                |

**Example**

```ts
import { uiObserver as observer } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State density: number = 0;
  @State message: string = 'Listener not registered'

  densityUpdateCallback = (info: observer.DensityInfo) => {
    this.density = info.density;
    this.message = 'DPI after change:' + this.density.toString();
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      Button ('Subscribe to Screen Pixel Density Changes')
        .onClick(() => {
          this.message = 'Listener registered'
          observer.on('densityUpdate', this.getUIContext(), this.densityUpdateCallback);
        })
    }
  }
}
```

## observer.off('densityUpdate')<sup>12+</sup>

off(type: 'densityUpdate', context: UIContext, callback?: Callback\<DensityInfo\>): void

Unsubscribes from the pixel density changes of the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                     | Mandatory | Description                                                                                          |
| -------- | ----------------------------------------- | ---- | ---------------------------------------------------------------------------------------------- |
| type     | string                                    | Yes  | Event type. The value **'densityUpdate'** indicates the pixel density changes of the screen.                                         |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for.                                                            |
| callback | Callback\<[DensityInfo](#densityinfo12)\> | No  | Callback to be unregistered. If this parameter is not specified, this API unregisters all callbacks for the **densityUpdate** event under the current UI context. |

```ts
import { uiObserver as observer, UIContext } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State density: number = 0;
  @State message: string = 'Listener not registered'

  densityUpdateCallback = (info: observer.DensityInfo) => {
    this.density = info.density;
    this.message = 'DPI after change:' + this.density.toString();
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      Button ('Subscribe to Screen Pixel Density Changes')
        .onClick(() => {
          this.message = 'Listener registered'
          observer.on('densityUpdate', this.getUIContext(), this.densityUpdateCallback);
        })
      Button ('Unsubscribe from Screen Pixel Density Changes')
        .onClick(() => {
          this.message = 'Listener not registered'
          observer.off('densityUpdate', this.getUIContext(), this.densityUpdateCallback);
        })
    }
  }
}
```

## observer.on('willDraw')<sup>12+</sup>

on(type: 'willDraw', context: UIContext, callback: Callback\<void\>): void

Subscribes to the dispatch of drawing instructions in each frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event event. The value **'willDraw'** indicates whether drawing is about to occur. |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for. |
| callback | Callback\<void\>        | Yes  | Callback used to return the                |

**Example**

```ts
import { uiObserver as observer } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  willDrawCallback = () => {
    console.info("willDraw instruction dispatched.")
  }
  build() {
    Column() {
      Button('Subscribe to Drawing Instruction Dispatch')
        .onClick(() => {
          observer.on('willDraw', this.getUIContext(), this.willDrawCallback);
        })
    }
  }
}
```

## observer.off('willDraw')<sup>12+</sup>

off(type: 'willDraw', context: UIContext, callback?: Callback\<void\>): void

Unsubscribes from the dispatch of drawing instructions in each frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                     | Mandatory | Description                                                 |
| -------- | ----------------------------------------- | ---- | ----------------------------------------------------- |
| type     | string                                    | Yes  | Event event. The value **'willDraw'** indicates whether drawing is about to occur. |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for.                   |
| callback | Callback\<void\>   | No  | Callback to be unregistered.                               |

```ts
import { uiObserver as observer } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  willDrawCallback = () => {
    console.info("willDraw instruction dispatched.")
  }

  build() {
    Column() {
      Button('Subscribe to Drawing Instruction Dispatch')
        .onClick(() => {
          observer.on('willDraw', this.getUIContext(), this.willDrawCallback);
        })
      Button('Unsubscribe from Drawing Instruction Dispatch')
        .onClick(() => {
          observer.off('willDraw', this.getUIContext(), this.willDrawCallback);
        })
    }
  }
}
```

## observer.on('didLayout')<sup>12+</sup>

on(type: 'didLayout', context: UIContext, callback: Callback\<void\>): void

Subscribes to layout completion status in each frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'didLayout'** indicates whether the layout has been completed. |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for. |
| callback | Callback\<void\>        | Yes  | Callback used to return the                |

**Example**

```ts
import { uiObserver as observer } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  didLayoutCallback = () => {
    console.info("Layout completed.");
  }
  build() {
    Column() {
      Button('Subscribe to Layout Completion')
        .onClick(() => {
          observer.on('didLayout', this.getUIContext(), this.didLayoutCallback);
        })
    }
  }
}
```

## observer.off('didLayout')<sup>12+</sup>

off(type: 'didLayout', context: UIContext, callback?: Callback\<void\>): void

Unsubscribes from layout completion status in each frame.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                     | Mandatory | Description                                                 |
| -------- | ----------------------------------------- | ---- | ----------------------------------------------------- |
| type     | string                                    | Yes  | Event type. The value **'didLayout'** indicates whether the layout has been completed. |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for.                   |
| callback | Callback\<void\>   | No  | Callback to be unregistered.                               |

```ts
import { uiObserver as observer } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  didLayoutCallback = () => {
    console.info("Layout completed.");
  }

  build() {
    Column() {
      Button('Subscribe to Layout Completion')
        .onClick(() => {
          observer.on('didLayout', this.getUIContext(), this.didLayoutCallback);
        })
      Button ('Unsubscribe from Layout Completion')
        .onClick(() => {
          observer.off('didLayout', this.getUIContext(), this.didLayoutCallback);
        })
    }
  }
}
```

## observer.on('navDestinationSwitch')<sup>12+</sup>

on(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, callback: Callback\<NavDestinationSwitchInfo\>): void

Subscribes to the page switching event of the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'navDestinationSwitch'** indicates the page switching event of the **Navigation** component. |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page switching event to be listened for. |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | Yes  | Callback used to return the information about the page switching event.                |

**Example**

```ts
// EntryAbility.ets
// observer.on('navDestinationSwitch', UIAbilityContext, callback) demo
// observer.off('navDestinationSwitch', UIAbilityContext, callback)
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { uiObserver as observer, window } from '@kit.ArkUI';
import { hilog } from "@kit.PerformanceAnalysisKit"

function callBackFunc(info: observer.NavDestinationSwitchInfo) {
  console.info(`testTag navDestinationSwitch from: ${JSON.stringify(info.from)} to: ${JSON.stringify(info.to)}`)
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    observer.on('navDestinationSwitch', this.context, callBackFunc);
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
    observer.off('navDestinationSwitch', this.context, callBackFunc);
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

```ts
// Index.ets
// observer.on('navDestinationSwitch', UIContext, callback) demo
// observer.off('navDestinationSwitch', UIContext, callback)
import { uiObserver as observer } from '@kit.ArkUI';

@Component
struct PageOne {
  build() {
    NavDestination() {
      Text("pageOne")
    }.title("pageOne")
  }
}

function callBackFunc(info: observer.NavDestinationSwitchInfo) {
  console.info(`testTag navDestinationSwitch from: ${JSON.stringify(info.from)} to: ${JSON.stringify(info.to)}`)
}

@Entry
@Component
struct Index {
  private stack: NavPathStack = new NavPathStack();

  @Builder
  PageBuilder(name: string) {
    PageOne()
  }

  aboutToAppear() {
    observer.on('navDestinationSwitch', this.getUIContext(), callBackFunc)
  }

  aboutToDisappear() {
    observer.off('navDestinationSwitch', this.getUIContext(), callBackFunc)
  }

  build() {
    Column() {
      Navigation(this.stack) {
        Button("push").onClick(() => {
          this.stack.pushPath({name: "pageOne"});
        })
      }
      .title("Navigation")
      .navDestination(this.PageBuilder)
    }
    .width('100%')
    .height('100%')
  }
}
```

## observer.off('navDestinationSwitch')<sup>12+</sup>

off(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, callback?: Callback\<NavDestinationSwitchInfo\>): void

Unsubscribes from the page switching event of the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'navDestinationSwitch'** indicates the page switching event of the **Navigation** component. |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page switching event to be listened for. |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | No  | Callback to be unregistered.                |

**Example**

See the example of [observer.on('navDestinationSwitch')](#observeronnavdestinationswitch12).

## observer.on('navDestinationSwitch')<sup>12+</sup>

on(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, observerOptions: NavDestinationSwitchObserverOptions, callback: Callback\<NavDestinationSwitchInfo\>): void

Subscribes to the page switching event of the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'navDestinationSwitch'** indicates the page switching event of the **Navigation** component. |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page switching event to be listened for. |
| observerOptions | [NavDestinationSwitchObserverOptions](#navdestinationswitchobserveroptions12)        | Yes  | Observer options.  |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | Yes  | Callback used to return the information about the page switching event.                |

**Example**

```ts
// EntryAbility.ets
// observer.on('navDestinationSwitch', UIAbilityContext, NavDestinationSwitchObserverOptions, callback) demo
// observer.off('navDestinationSwitch', UIAbilityContext, NavDestinationSwitchObserverOptions, callback)
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { uiObserver as observer, window } from '@kit.ArkUI';
import { hilog } from "@kit.PerformanceAnalysisKit"

function callBackFunc(info: observer.NavDestinationSwitchInfo) {
  console.info(`testTag navDestinationSwitch from: ${JSON.stringify(info.from)} to: ${JSON.stringify(info.to)}`)
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    observer.on('navDestinationSwitch', this.context, { navigationId: "myNavId" }, callBackFunc);
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
    observer.off('navDestinationSwitch', this.context, { navigationId: "myNavId" }, callBackFunc);
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

```ts
// Index.ets
// observer.on('navDestinationSwitch', UIContext, NavDestinationSwitchObserverOptions, callback) demo
// observer.off('navDestinationSwitch', UIContext, NavDestinationSwitchObserverOptions, callback)
import { uiObserver as observer } from '@kit.ArkUI';

@Component
struct PageOne {
  build() {
    NavDestination() {
      Text("pageOne")
    }.title("pageOne")
  }
}

function callBackFunc(info: observer.NavDestinationSwitchInfo) {
  console.info(`testTag navDestinationSwitch from: ${JSON.stringify(info.from)} to: ${JSON.stringify(info.to)}`)
}

@Entry
@Component
struct Index {
  private stack: NavPathStack = new NavPathStack();

  @Builder
  PageBuilder(name: string) {
    PageOne()
  }

  aboutToAppear() {
    observer.on('navDestinationSwitch', this.getUIContext(), { navigationId: "myNavId" }, callBackFunc)
  }

  aboutToDisappear() {
    observer.off('navDestinationSwitch', this.getUIContext(), { navigationId: "myNavId" }, callBackFunc)
  }

  build() {
    Column() {
      Navigation(this.stack) {
        Button("push").onClick(() => {
          this.stack.pushPath({name: "pageOne"});
        })
      }
      .id("myNavId")
      .title("Navigation")
      .navDestination(this.PageBuilder)
    }
    .width('100%')
    .height('100%')
  }
}
```

## observer.off('navDestinationSwitch')<sup>12+</sup>

off(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, observerOptions: NavDestinationSwitchObserverOptions, callback?: Callback\<NavDestinationSwitchInfo\>): void

Unsubscribes from the page switching event of the **Navigation** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'navDestinationSwitch'** indicates the page switching event of the **Navigation** component. |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page switching event to be listened for. |
| observerOptions | [NavDestinationSwitchObserverOptions](#navdestinationswitchobserveroptions12)        | Yes  | Observer options.  |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | No  | Callback to be unregistered.                |

**Example**

See the example of [observer.on('navDestinationSwitch')](#observeronnavdestinationswitch12-1).

## observer.on('tabContentUpdate')<sup>12+</sup>

on(type: 'tabContentUpdate', callback: Callback\<TabContentInfo\>): void

Subscribes to the **TabContent** switching event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'tabContentUpdate'** indicates the **TabContent** switching event. |
| callback | Callback\<[TabContentInfo](#tabcontentinfo12)\>              | Yes  | Callback used to return the information about the **TabContent** switching event. |

**Example**

```ts
import { uiObserver as observer } from '@kit.ArkUI';

function callbackFunc(info: observer.TabContentInfo) {
  console.info('tabContentUpdate', JSON.stringify(info));
}

@Entry
@Component
struct TabsExample {

  aboutToAppear(): void {
    observer.on('tabContentUpdate', callbackFunc);
  }

  aboutToDisappear(): void {
    observer.off('tabContentUpdate', callbackFunc);
  }

  build() {
    Column() {
      Tabs() {
        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#00CB87')
        }.tabBar('green').id('tabContentId0')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#007DFF')
        }.tabBar('blue').id('tabContentId1')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#FFBF00')
        }.tabBar('yellow').id('tabContentId2')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#E67C92')
        }.tabBar('pink').id('tabContentId3')
      }
      .width(360)
      .height(296)
      .backgroundColor('#F1F3F5')
      .id('tabsId')
    }.width('100%')
  }
}
```

## observer.off('tabContentUpdate')<sup>12+</sup>

off(type: 'tabContentUpdate', callback?: Callback\<TabContentInfo\>): void

Unsubscribes from the **TabContent** switching event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'tabContentUpdate'** indicates the **TabContent** switching event. |
| callback | Callback\<[TabContentInfo](#tabcontentinfo12)\>              | No  | Callback to be unregistered. |

**Example**

See the example of [observer.on('tabContentUpdate')](#observerontabcontentupdate12).

## observer.on('tabContentUpdate')<sup>12+</sup>

on(type: 'tabContentUpdate', options: ObserverOptions, callback: Callback\<TabContentInfo\>): void

Subscribes to the **TabContent** switching event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'tabContentUpdate'** indicates the **TabContent** switching event. |
| options  | [ObserverOptions](#observeroptions12)                        | Yes  | ID of the target **Tabs** component. |
| callback | Callback\<[TabContentInfo](#tabcontentinfo12)\>              | Yes  | Callback used to return the information about the **TabContent** switching event. |

**Example**

```ts
import { uiObserver as observer } from '@kit.ArkUI';

function callbackFunc(info: observer.TabContentInfo) {
  console.info('tabContentUpdate', JSON.stringify(info));
}

@Entry
@Component
struct TabsExample {

  aboutToAppear(): void {
    observer.on('tabContentUpdate', { id: 'tabsId' }, callbackFunc);
  }

  aboutToDisappear(): void {
    observer.off('tabContentUpdate', { id: 'tabsId' }, callbackFunc);
  }

  build() {
    Column() {
      Tabs() {
        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#00CB87')
        }.tabBar('green').id('tabContentId0')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#007DFF')
        }.tabBar('blue').id('tabContentId1')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#FFBF00')
        }.tabBar('yellow').id('tabContentId2')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#E67C92')
        }.tabBar('pink').id('tabContentId3')
      }
      .width(360)
      .height(296)
      .backgroundColor('#F1F3F5')
      .id('tabsId')
    }.width('100%')
  }
}
```

## observer.off('tabContentUpdate')<sup>12+</sup>

off(type: 'tabContentUpdate', options: ObserverOptions, callback?: Callback\<TabContentInfo\>): void

Unsubscribes from the **TabContent** switching event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type                                                        | Mandatory | Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value **'tabContentUpdate'** indicates the **TabContent** switching event. |
| options  | [ObserverOptions](#observeroptions12)                        | Yes  | ID of the target **Tabs** component. |
| callback | Callback\<[TabContentInfo](#tabcontentinfo12)\>              | No  | Callback to be unregistered. |

**Example**

See the example of [observer.on('tabContentUpdate')](#observerontabcontentupdate12-1).
<!--no_check-->