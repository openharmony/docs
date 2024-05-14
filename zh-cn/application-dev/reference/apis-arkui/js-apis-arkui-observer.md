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

| 名称                            | 值   | 说明                                                         |
| ------------------------------- | ---- | ------------------------------------------------------------ |
| ON_SHOWN                        | 0    | NavDestination组件显示。<br/>**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| ON_HIDDEN                       | 1    | NavDestination组件隐藏。<br/>**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| ON_APPEAR<sup>12+</sup>         | 2    | NavDestination从组件树上挂载。<br/>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。                               |
| ON_DISAPPEAR<sup>12+</sup>      | 3    | NavDestination从组件树上卸载。<br/>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。                               |
| ON_WILL_SHOW<sup>12+</sup>      | 4    | NavDestination组件显示之前。  <br/>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。                               |
| ON_WILL_HIDE<sup>12+</sup>      | 5    | NavDestination组件隐藏之前。  <br/>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。                               |
| ON_WILL_APPEAR<sup>12+</sup>    | 6    | NavDestination挂载到组件树之前。  <br/>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。                           |
| ON_WILL_DISAPPEAR<sup>12+</sup> | 7    | NavDestination从组件树上卸载之前。<br/>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。                           |
| ON_BACKPRESS<sup>12+</sup>      | 100  | NavDestination组件返回。 <br/>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。                                    |

## ScrollEventType<sup>12+</sup>

滚动事件的类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 值  | 说明                     |
| --------- | --- | ------------------------ |
| SCROLL_START  | 0   | 滚动事件开始。 |
| SCROLL_STOP   | 1   | 滚动事件结束。 |

## RouterPageState

routerPage生命周期触发时对应的状态。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 值  | 说明                    |
| ----------------- | --- | ----------------------- |
| ABOUT_TO_APPEAR       | 0   | page即将显示            |
| ABOUT_TO_DISAPPEAR    | 1   | page即将销毁            |
| ON_PAGE_SHOW          | 2   | page显示                |
| ON_PAGE_HIDE          | 3   | page隐藏                |
| ON_BACK_PRESS         | 4   | page返回时              |

## NavDestinationInfo

NavDestination组件信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填 | 说明                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | 是   | 包含NavDestination组件的Navigation组件的id。|
| name         | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | 是   | NavDestination组件的名称。 |
| state        | [NavDestinationState](#navdestinationstate)        | 是   | NavDestination组件的状态。 |
| index<sup>12+</sup>        | number        | 是   | NavDestination在页面栈中的索引。                   |
| param<sup>12+</sup>        | Object        | 否   | NavDestination组件的参数。                   |
| navDestinationId<sup>12+</sup>        | string        | 是   | NavDestination组件的唯一标识ID。                   |

## ScrollEventInfo<sup>12+</sup>

ScrollEvent滚动信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填 | 说明                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| id           | string                                             | 是   | 滚动组件的id。                               |
| scrollEvent     | [ScrollEventType](#scrolleventtype12)                | 是   | 滚动事件的类型。                             |
| offset       | number                                             | 是   | 滚动组件的当前偏移量。                        |

## ObserverOptions<sup>12+</sup>

Observer选项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填 | 说明                                         |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| id           | string                                             | 是   | 组件的id。                               |

## RouterPageInfo

RouterPageInfo包含的信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填 | 说明                                          |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| context      | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) / [UIContext](./js-apis-arkui-UIContext.md) | 是   | 触发生命周期的routerPage页面对应的上下文信息 |
| index        | number                                             | 是   | 触发生命周期的routerPage在栈中的位置。         |
| name         | string                                             | 是   | 触发生命周期的routerPage页面的名称。           |
| path         | string                                             | 是   | 触发生命周期的routerPage页面的路径。           |
| state        | [RouterPageState](#routerpagestate)                | 是   | 触发生命周期的routerPage页面的状态             |

## DensityInfo<sup>12+</sup>

屏幕像素密度变化回调包含的信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                      | 必填 | 说明                                   |
| ------- | ----------------------------------------- | ---- | -------------------------------------- |
| context | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 屏幕像素密度变化时页面对应的上下文信息 |
| density | number                                    | 是   | 变化后的屏幕像素密度。                 |

## NavDestinationSwitchInfo<sup>12+</sup>

Navigation组件页面切换的信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填 | 说明                                          |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| context      | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) \| [UIContext](./js-apis-arkui-UIContext.md) | 是   | 触发页面切换的Navigation对应的上下文信息。 |
| from         | [NavDestinationInfo](#navdestinationinfo) \| "navBar" | 是   | 页面切换的源页面。         |
| to           | [NavDestinationInfo](#navdestinationinfo) \| "navBar" | 是   | 页面切换的目的页面。         |
| operation    | [NavigationOperation](./arkui-ts/ts-basic-components-navigation.md#navigationoperation11枚举说明) | 是   | 页面切换操作类型。         |

## NavDestinationSwitchObserverOptions<sup>12+</sup>

Navigation组件页面切换事件的监听选项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填 | 说明                                          |
| ------------ | -------------------------------------------------- | ---- | -------------------------------------------- |
| navigationId | [ResourceStr](arkui-ts/ts-types.md#resourcestr) | 是   | 指定需要监听的Navigation的ID |

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', callback: Callback\<NavDestinationInfo\>): void

监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                                     |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | 是   | 回调函数。返回当前的NavDestination组件状态。                             |

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

| 参数名   | 类型                                                  | 必填 | 说明                                                                     |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\> | 否   | 回调函数。返回当前的NavDestination组件状态。                             |

**示例：**

```ts
observer.off('navDestinationUpdate');
```

## observer.on('navDestinationUpdate')

on(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback: Callback\<NavDestinationInfo\>): void

监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                                 | 必填 | 说明                                                                     |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                               |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>                | 是   | 回调函数。返回当前的NavDestination组件状态。                             |

**示例：**

```ts
observer.on('navDestinationUpdate', { navigationId: "testId" }, (info) => {
    console.info('NavDestination state update', JSON.stringify(info));
});
```

## observer.off('navDestinationUpdate')

off(type: 'navDestinationUpdate', options: { navigationId: ResourceStr }, callback?: Callback\<NavDestinationInfo\>): void

取消监听NavDestination组件的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                                 | 必填 | 说明                                                                     |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | 是   | 监听事件，固定为'navDestinationUpdate'，即NavDestination组件的状态变化。 |
| options  | { navigationId: [ResourceStr](arkui-ts/ts-types.md#resourcestr) } | 是   | 指定监听的Navigation的id。                                               |
| callback | Callback\<[NavDestinationInfo](#navdestinationinfo)\>                | 否   | 回调函数。返回当前的NavDestination组件状态。                             |

**示例：**

```ts
observer.off('navDestinationUpdate', { navigationId: "testId" });
```

## observer.on('scrollEvent')<sup>12+</sup>

on(type: 'scrollEvent', callback: Callback\<ScrollEventInfo\>): void

监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                                     |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。                   |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>       | 是   | 回调函数。返回滚动事件的信息。                                           |

**示例：**

请参考[offscrollevent示例](#observeroffscrollevent12-1)

## observer.off('scrollEvent')<sup>12+</sup>

off(type: 'scrollEvent', callback?: Callback\<ScrollEventInfo\>): void

取消监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                  | 必填 | 说明                                                                     |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。                   |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>       | 否   | 回调函数。返回滚动事件的信息。                                           |

**示例：**

请参考[offscrollevent示例](#observeroffscrollevent12-1)

## observer.on('scrollEvent')<sup>12+</sup>

on(type: 'scrollEvent', options: ObserverOptions, callback: Callback\<ScrollEventInfo\>): void

监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                                 | 必填 | 说明                                                                     |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。                   |
| options  | [ObserverOptions](#observeroptions12)                                  | 是   | 指定监听的滚动组件的id。                                                 |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>                      | 是   | 回调函数。返回滚动事件的信息。                                            |

**示例：**

请参考[offscrollevent示例](#observeroffscrollevent12-1)

## observer.off('scrollEvent')<sup>12+</sup>

off(type: 'scrollEvent', options: ObserverOptions, callback?: Callback\<ScrollEventInfo\>): void

取消监听滚动事件的开始和结束。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                                 | 必填 | 说明                                                                     |
| -------- | -------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| type     | string                                                               | 是   | 监听事件，固定为'scrollEvent'，即滚动事件的开始和结束。                   |
| options  | [ObserverOptions](#observeroptions12)                                  | 是   | 指定监听的滚动组件的id。                                                 |
| callback | Callback\<[ScrollEventInfo](#scrolleventinfo12)\>                      | 否   | 回调函数。返回滚动事件的信息。                                            |

**示例：**

```ts
import observer from '@ohos.arkui.observer'

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

监听router中page页面的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'routerPageUpdate'，即router中page页面的状态变化。 |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围 |
| callback | Callback\<[RouterPageInfo](#routerpageinfo)\>        | 是   | 回调函数。携带pageInfo，返回当前的page页面状态。                 |

**示例：**

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

取消监听router中page页面的状态变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'routerPageUpdate'，即router中page页面的状态变化。 |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围 |
| callback | Callback\<[RouterPageInfo](#routerpageinfo)\>        | 否   | 需要被注销的回调函。                 |

**示例：**

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

## observer.on('densityUpdate')<sup>12+</sup>

on(type: 'densityUpdate', context: UIContext, callback: Callback\<DensityInfo\>): void

监听屏幕像素密度变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'densityUpdate'，即屏幕像素密度变化。 |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围 |
| callback | Callback\<[DensityInfo](#densityinfo12)\>        | 是   | 回调函数。携带densityInfo，返回变化后的屏幕像素密度。                 |

**示例：**

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  @State density: number = 0;
  @State message: string = '未注册监听'

  densityUpdateCallback = (info: observer.DensityInfo) => {
    this.density = info.density;
    this.message = '变化后的DPI：' + this.density.toString();
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      Button('注册屏幕像素密度变化监听')
        .onClick(() => {
          this.message = '已注册监听'
          observer.on('densityUpdate', this.getUIContext(), this.densityUpdateCallback);
        })
    }
  }
}
```

## observer.off('densityUpdate')<sup>12+</sup>

off(type: 'densityUpdate', context: UIContext, callback?: Callback\<DensityInfo\>): void

取消监听屏幕像素密度的变化。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                      | 必填 | 说明                                                                                           |
| -------- | ----------------------------------------- | ---- | ---------------------------------------------------------------------------------------------- |
| type     | string                                    | 是   | 监听事件，固定为'densityUpdate'，即屏幕像素密度变化。                                          |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围                                                             |
| callback | Callback\<[DensityInfo](#densityinfo12)\> | 否   | 需要被注销的回调函数。若不指定具体的回调函数，则注销指定UIContext下所有densityUpdate事件监听。 |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  @State density: number = 0;
  @State message: string = '未注册监听'

  densityUpdateCallback = (info: observer.DensityInfo) => {
    this.density = info.density;
    this.message = '变化后的DPI：' + this.density.toString();
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      Button('注册屏幕像素密度变化监听')
        .onClick(() => {
          this.message = '已注册监听'
          observer.on('densityUpdate', this.getUIContext(), this.densityUpdateCallback);
        })
      Button('解除注册屏幕像素密度变化监听')
        .onClick(() => {
          this.message = '未注册监听'
          observer.off('densityUpdate', this.getUIContext(), this.densityUpdateCallback);
        })
    }
  }
}
```

## observer.on('willDraw')<sup>12+</sup>

on(type: 'willDraw', context: UIContext, callback: Callback\<void\>): void

监听每一帧绘制指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'willDraw'，即是否将要绘制。 |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围。 |
| callback | Callback\<void\>        | 是   | 回调函数。                 |

**示例：**

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  willDrawCallback = () => {
    console.log("willDraw指令下发");
  }
  build() {
    Column() {
      Button('注册绘制指令下发监听')
        .onClick(() => {
          observer.on('willDraw', this.getUIContext(), this.willDrawCallback);
        })
    }
  }
}
```

## observer.off('willDraw')<sup>12+</sup>

off(type: 'willDraw', context: UIContext, callback?: Callback\<void\>): void

取消监听每一帧绘制指令下发情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                      | 必填 | 说明                                                  |
| -------- | ----------------------------------------- | ---- | ----------------------------------------------------- |
| type     | string                                    | 是   | 监听事件，固定为'willDraw'，即是否将要绘制。 |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围。                    |
| callback | Callback\<void\>   | 否   | 需要被注销的回调函数。                                |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  willDrawCallback = () => {
    console.log("willDraw指令下发")
  }

  build() {
    Column() {
      Button('注册绘制指令下发监听')
        .onClick(() => {
          observer.on('willDraw', this.getUIContext(), this.willDrawCallback);
        })
      Button('解除注册绘制指令下发监听')
        .onClick(() => {
          observer.off('willDraw', this.getUIContext(), this.willDrawCallback);
        })
    }
  }
}
```

## observer.on('didLayout')<sup>12+</sup>

on(type: 'didLayout', context: UIContext, callback: Callback\<void\>): void

监听每一帧布局完成情况

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'didLayout'，即是否布局完成。 |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围。 |
| callback | Callback\<void\>        | 是   | 回调函数。                 |

**示例：**

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  didLayoutCallback = () => {
    console.log("Layout布局完成");
  }
  build() {
    Column() {
      Button('注册布局完成监听')
        .onClick(() => {
          observer.on('didLayout', this.getUIContext(), this.didLayoutCallback);
        })
    }
  }
}
```

## observer.off('didLayout')<sup>12+</sup>

off(type: 'didLayout', context: UIContext, callback?: Callback\<void\>): void

取消监听每一帧布局完成情况。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                      | 必填 | 说明                                                  |
| -------- | ----------------------------------------- | ---- | ----------------------------------------------------- |
| type     | string                                    | 是   | 监听事件，固定为'didLayout'，即是否布局完成。 |
| context  | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面的范围。                    |
| callback | Callback\<void\>   | 否   | 需要被注销的回调函数。                                |

```ts
import observer from '@ohos.arkui.observer';

@Entry
@Component
struct Index {
  didLayoutCallback = () => {
    console.log("Layout布局完成")
  }

  build() {
    Column() {
      Button('注册布局完成监听')
        .onClick(() => {
          observer.on('didLayout', this.getUIContext(), this.didLayoutCallback);
        })
      Button('解除布局完成s监听')
        .onClick(() => {
          observer.off('didLayout', this.getUIContext(), this.didLayoutCallback);
        })
    }
  }
}
```

## observer.on('navDestinationSwitch')<sup>12+</sup>

on(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, callback: Callback\<NavDestinationSwitchInfo\>): void

监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面切换事件的范围。 |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | 是   | 回调函数。携带NavDestinationSwitchInfo，返回页面切换事件的信息。                 |

**示例：**

```ts
// 在UIAbility中使用
import observer from '@ohos.arkui.observer';
import { UIContext } from '@ohos.arkui.UIContext';
// callBackFunc 是开发者定义的监听回调函数
function callBackFunc(info: observer.NavDestinationSwitchInfo) {}
observer.on('navDestinationSwitch', this.context, callBackFunc);
// 可以通过窗口的getUIContext()方法获取对应的UIContent
uiContext: UIContext | null = null;
observer.on('navDestinationSwitch', this.uiContext, callBackFunc);
```

## observer.off('navDestinationSwitch')<sup>12+</sup>

off(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, callback?: Callback\<NavDestinationSwitchInfo\>): void

取消监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面切换事件的范围。 |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | 否   | 需要被注销的回调函数。                 |

**示例：**

```ts
// 在UIAbility中使用
import observer from '@ohos.arkui.observer';
import { UIContext } from '@ohos.arkui.UIContext';
// callBackFunc 是开发者定义的监听回调函数
function callBackFunc(info: observer.NavDestinationSwitchInfo) {}
observer.off('navDestinationSwitch', this.context, callBackFunc);
// 可以通过窗口的getUIContext()方法获取对应的UIContent
uiContext: UIContext | null = null;
observer.off('navDestinationSwitch', this.uiContext, callBackFunc);
```

## observer.on('navDestinationSwitch')<sup>12+</sup>

on(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, observerOptions: NavDestinationSwitchObserverOptions, callback: Callback\<NavDestinationSwitchInfo\>): void

监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面切换事件的范围。 |
| observerOptions | [NavDestinationSwitchObserverOptions](#navdestinationswitchobserveroptions12)        | 是   | 监听选项。   |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | 是   | 回调函数。携带NavDestinationSwitchInfo，返回页面切换事件的信息。                 |

**示例：**

```ts
// 在UIAbility中使用
import observer from '@ohos.arkui.observer';
import { UIContext } from '@ohos.arkui.UIContext';
// callBackFunc 是开发者定义的监听回调函数
function callBackFunc(info: observer.NavDestinationSwitchInfo) {}
observer.on('navDestinationSwitch', this.context, { navigationId: "myNavId" }, callBackFunc);
// 可以通过窗口的getUIContext()方法获取对应的UIContent
uiContext: UIContext | null = null;
observer.on('navDestinationSwitch', this.uiContext, { navigationId: "myNavId" }, callBackFunc);
```

## observer.off('navDestinationSwitch')<sup>12+</sup>

off(type: 'navDestinationSwitch', context: UIAbilityContext | UIContext, observerOptions: NavDestinationSwitchObserverOptions, callback?: Callback\<NavDestinationSwitchInfo\>): void

取消监听Navigation的页面切换事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'navDestinationSwitch'，即Navigation的页面切换事件。 |
| context  | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)&nbsp;\|&nbsp;[UIContext](./js-apis-arkui-UIContext.md) | 是   | 上下文信息，用以指定监听页面切换事件的范围。 |
| observerOptions | [NavDestinationSwitchObserverOptions](#navdestinationswitchobserveroptions12)        | 是   | 监听选项。   |
| callback | Callback\<[NavDestinationSwitchInfo](#navdestinationswitchinfo12)\>        | 否   | 需要被注销的回调函数。                 |

**示例：**

```ts
// 在UIAbility中使用
import observer from '@ohos.arkui.observer';
import { UIContext } from '@ohos.arkui.UIContext';
// callBackFunc 是开发者定义的监听回调函数
function callBackFunc(info: observer.NavDestinationSwitchInfo) {}
observer.off('navDestinationSwitch', this.context, { navigationId: "myNavId" }, callBackFunc);
// 可以通过窗口的getUIContext()方法获取对应的UIContent
uiContext: UIContext | null = null;
observer.off('navDestinationSwitch', this.uiContext, { navigationId: "myNavId" }, callBackFunc);
```
