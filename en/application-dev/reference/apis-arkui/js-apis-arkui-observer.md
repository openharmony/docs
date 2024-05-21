# @ohos.arkui.observer (Observer)

The **Observer** module provides APIs for listening for UI component behavior changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```ts
import observer from '@ohos.arkui.observer'
```

## NavDestinationState

Describes the state of the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Value | Description                    |
| --------- | --- | ------------------------ |
| ON_SHOWN  | 0   | The **\<NavDestination>** component is displayed.|
| ON_HIDDEN | 1   | The **\<NavDestination>** component is hidden.|

## RouterPageState

Enumerates the states of a page during routing.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Value | Description                   |
| ----------------- | --- | ----------------------- |
| ABOUT_TO_APPEAR       | 0   | The page is about to be displayed.           |
| ABOUT_TO_DISAPPEAR    | 1   | The page is about to be destroyed.           |
| ON_PAGE_SHOW          | 2   | The page is displayed.               |
| ON_PAGE_HIDE          | 3   | The page is hidden.               |
| ON_BACK_PRESS         | 4   | The page is returned.             |

## NavDestinationInfo

Provides information about the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | Yes  | ID of the **\<Navigation>** component that contains the target **\<NavDestination>** component.|
| name         | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | Yes  | Name of the **\<NavDestination>** component.                  |
| state        | [NavDestinationState](#navdestinationstate)        | Yes  | State of the **\<NavDestination>** component.                  |

## RouterPageInfo

Provides the information about a page during routing.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| context      | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) / [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context of the page that invokes the lifecycle callback.|
| index        | number                                             | Yes  | Position of the page that invokes the lifecycle callback, in the navigation stack.        |
| name         | string                                             | Yes  | Name of the page that invokes the lifecycle callback.          |
| path         | string                                             | Yes  | Path of the page that invokes the lifecycle callback.          |
| state        | [RouterPageState](#routerpagestate)                | Yes  | State of the page that invokes the lifecycle callback.            |

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', callback: Callback\<NavDestinationInfo\>): void

Subscribes to status changes of the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **\<NavDestination>** component.|
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | Yes  | Callback used to return the current state of the **\<NavDestination>** component.                            |

**Example**

```ts
observer.on('navDestinationUpdate', (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

## observer.off('navDestinationUpdate')

off(type: 'navDestinationUpdate', callback?: Callback\<NavDestinationInfo\>): void

Unsubscribes from status changes of the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **\<NavDestination>** component.|
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | No  | Callback used to return the current state of the **\<NavDestination>** component.                            |

**Example**

```ts
observer.off('navDestinationUpdate');
```

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback: Callback\<NavDestinationInfo\>): void

Subscribes to status changes of the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                                | Mandatory| Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **\<NavDestination>** component.|
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | Yes  | ID of the **\<Navigation>** component that contains the target **\<NavDestination>** component.                                              |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>                | Yes  | Callback used to return the current state of the **\<NavDestination>** component.                            |

**Example**

```ts
observer.on('navDestinationUpdate', { navigationId: "testId" }, (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

## observer.off('navDestinationUpdate')

off(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback?: Callback\<NavDestinationInfo\>): void

Unsubscribes from status changes of the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                                | Mandatory| Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **\<NavDestination>** component.|
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | Yes  | ID of the **\<Navigation>** component that contains the target **\<NavDestination>** component.                                              |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>                | No  | Callback used to return the current state of the **\<NavDestination>** component.                            |

**Example**

```ts
observer.off('navDestinationUpdate', { navigationId: "testId" });
```

## observer.on('routerPageUpdate')<sup>11+</sup>

on(type: 'routerPageUpdate', context: UIAbilityContext | UIContext, callback: Callback\<RouterPageInfo\>): void

Subscribes to state changes of the page during routing.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'routerPageUpdate'**, which indicates the state change event of the page during routing.|
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) / [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for.|
| callback | Callback\<[RouterPageInfo](#routerpageinfo)\>        | Yes  | Callback used to return the If **pageInfo** is passed, the current page state is returned.                |

**Example**

```ts
// used in UIAbility
import observer from '@ohos.arkui.observer';
import { UIContext } from '@ohos.arkui.UIContext';
function callBackFunc(info: observer.RouterPageInfo) {}
// callBackFunc is user defined function
observer.on('routerPageUpdate', this.context, callBackFunc);
// uiContext could be got by window's function: getUIContext()
uiContext: UIContext | null = null;
observer.on('routerPageUpdate', this.uiContext, callBackFunc);
```

## observer.off('routerPageUpdate')<sup>11+</sup>

off(type: 'routerPageUpdate', context: UIAbilityContext | UIContext, callback?: Callback\<RouterPageInfo\>): void

Unsubscribes to state changes of the page during routing.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'routerPageUpdate'**, which indicates the state change event of the page during routing.|
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) / [UIContext](./js-apis-arkui-UIContext.md) | Yes  | Context information, which is used to specify the scope of the page to be listened for.|
| callback | Callback\<[RouterPageInfo](#routerpageinfo)\>        | No  | Callback to be unregistered.                |

**Example**

```ts
// used in UIAbility
import observer from '@ohos.arkui.observer';
import { UIContext } from '@ohos.arkui.UIContext';
function callBackFunc(info: observer.RouterPageInfo) {}
// callBackFunc is user defined function
observer.off('routerPageUpdate', this.context, callBackFunc);
// uiContext could be got by window's function: getUIContext()
uiContext: UIContext | null = null;
observer.off('routerPageUpdate', this.uiContext, callBackFunc);
```
<!--no_check-->