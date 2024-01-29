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

## NavDestinationInfo

Provides information about the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | Yes  | ID of the **\<Navigation>** component that contains the target **\<NavDestination>** component.|
| name         | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | Yes  | Name of the **\<NavDestination>** component.                  |
| state        | [NavDestinationState](#navdestinationstate)        | Yes  | State of the **\<NavDestination>** component.                  |

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', callback: Callback\<NavDestinationInfo\>): void

Subscribes to status changes of the **\<NavDestination>** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                                 | Mandatory| Description                                                                    |
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

| Name    | Type                                                 | Mandatory| Description                                                                    |
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

| Name    | Type                                                                | Mandatory| Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **\<NavDestination>** component.|
| options  | { navigationId: [ResourceStr](../arkui-ts/ts-types.md#resourcestr) } | Yes  | ID of the **\<Navigation>** component that contains the target **\<NavDestination>** component.                                              |
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

| Name    | Type                                                                | Mandatory| Description                                                                    |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'navDestinationUpdate'**, which indicates the status change event of the **\<NavDestination>** component.|
| options  | { navigationId: [ResourceStr](../arkui-ts/ts-types.md#resourcestr) } | Yes  | ID of the **\<Navigation>** component that contains the target **\<NavDestination>** component.                                              |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>                | No  | Callback used to return the current state of the **\<NavDestination>** component.                            |

**Example**

```ts
observer.off('navDestinationUpdate', { navigationId: "testId" });
```
