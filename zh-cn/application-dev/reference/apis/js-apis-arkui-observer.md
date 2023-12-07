# @ohos.arkui.observer (无感监听)

提供UI组件行为变化的无感监听能力。

> **说明：**
>
> 从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>

## 导入模块

```ts
import observer from '@ohos.arkui.observer'
```

## NavDestinationState

NavDestination组件状态。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 值   | 说明                     |
| --------- | ---- | ------------------------ |
| ON_SHOWN  | 0    | NavDestination组件显示。 |
| ON_HIDDEN | 1    | NavDestination组件隐藏。 |

## NavDestinationInfo

NavDestination组件信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名       | 类型                                               | 必填 | 说明                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | 是   | 包含NavDestination组件的Navigation组件的id。 |
| name         | [ResourceStr](../arkui-ts/ts-types.md#resourcestr) | 是   | NavDestination组件的名称。                   |
| state        | [NavDestinationState](#navdestinationstate)        | 是   | NavDestination组件的状态。                   |

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', callback: Callback\<NavDestinationInfo\>): void

监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | 是   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
observer.on('navDestinationUpdate', (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

## observer.off('navDestinationUpdate')

off(type: 'navDestinationUpdate', callback?: Callback\<NavDestinationInfo\>): void

取消监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | 否   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
observer.off('navDestinationUpdate');
```

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback: Callback<NavDestinationInfo>): void

监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](../arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                   |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>        | 是   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
observer.on('navDestinationUpdate', { navigationId: "testId" }, (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

## observer.off('navDestinationUpdate')

off(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback?: Callback<NavDestinationInfo>): void

取消监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](../arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                   |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>        | 否   | 回调函数。返回当前的NavDestination组件状态。                 |

**示例：**

```ts
observer.off('navDestinationUpdate', { navigationId: "testId" });
```
