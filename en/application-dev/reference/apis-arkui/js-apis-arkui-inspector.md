# @ohos.arkui.inspector (Layout Callback)

The **Inspector** module provides APIs for registering the component layout and drawing completion callbacks.

> **NOTE**
>
> The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> Since API version 10, you can use the [getUIInspector](./js-apis-arkui-UIContext.md#getuiinspector) API in [UIContext](./js-apis-arkui-UIContext.md#uicontext) to obtain the [UIInspector](./js-apis-arkui-UIContext.md#uiinspector) object associated with the current UI context.

## Modules to Import

```ts
import { inspector } from '@kit.ArkUI'
```

## inspector.createComponentObserver

createComponentObserver(id: string): ComponentObserver

Creates an observer for the specified component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type  | Mandatory | Description      |
| ------ | ------ | ---- | ---------- |
| id     | string | Yes  | Component ID. |

**Return value** 

| Type             | Description                                            |
| ----------------- | ------------------------------------------------ |
|[ComponentObserver](#componentobserver)| Component observer, which is used to register and unregister listeners. |

**Example** 

```ts
let listener:inspector.ComponentObserver = inspector.createComponentObserver('COMPONENT_ID'); // Listen for callback events of the component whose ID is COMPONENT_ID.
```

## ComponentObserver

Implements a component observer for completion of component layout and drawing, including the first query result when the observer is requested.

### on

on(type: 'layout', callback: () => void): void

Registers a listener for completion of component layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type  | Mandatory | Description|
| -------- | ------ | ---- | -------------------------------------|
| type     | string | Yes  | Type of the listener. The value must be **'layout'** or **'draw'**.<br>**'layout'**: completion of component layout.<br>**'draw'**: completion of component drawing. |
| callback | void   | Yes  | Callback invoked upon completion of component layout or drawing.|

### off

off(type: 'layout', callback?: () => void): void

Unregisters the listener for completion of component layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type  | Mandatory | Description |
| -------- | ------ | ---- | -------------------------------------------- |
| type     | string | Yes  | Type of the listener. The value must be **'layout'** or **'draw'**.<br>**'layout'**: completion of component layout.<br>**'draw'**: completion of component drawing. |
| callback | void   | No  | Callback to unregister. If this parameter is not specified, all callbacks of the specified type are unregistered.|

### on

on(type: 'draw', callback: () => void): void

Registers a listener for completion of component drawing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type  | Mandatory | Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Type of the listener. The value must be **'layout'** or **'draw'**.<br>**'layout'**: completion of component layout.<br>**'draw'**: completion of component drawing. |
| callback | void   | Yes  | Callback invoked upon completion of component layout or drawing.                                    |

### off

off(type: 'draw', callback?: () => void): void

Unregisters the listener for completion of component drawing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name  | Type  | Mandatory | Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Type of the listener. The value must be **'layout'** or **'draw'**.<br>**'layout'**: completion of component layout.<br>**'draw'**: completion of component drawing. |
| callback | void   | No  | Callback to unregister. If this parameter is not specified, all callbacks of the specified type are unregistered. |

**Example**

  ```ts
  import { inspector } from '@kit.ArkUI'

  @Entry
  @Component
  struct ImageExample {
    build() {
      Column() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
          Row({ space: 5 }) {
            Image($r('app.media.app_icon'))
              .width(110)
              .height(110)
              .border({ width: 1 })
              .id('IMAGE_ID')
          }
        }
      }.height(320).width(360).padding({ right: 10, top: 10 })
    }

    listener:inspector.ComponentObserver = inspector.createComponentObserver('IMAGE_ID')

    aboutToAppear() {
      let onLayoutComplete:()=>void=():void=>{
          // do something here
      }
      let onDrawComplete:()=>void=():void=>{
          // do something here
      }
      let offLayoutComplete:()=>void=():void=>{
          // do something here
      }
      let offDrawComplete:()=>void=():void=>{
          // do something here
      }
      let FuncLayout = onLayoutComplete // bind current js instance
      let FuncDraw = onDrawComplete // bind current js instance
      let OffFuncLayout = offLayoutComplete // bind current js instance
      let OffFuncDraw = offDrawComplete // bind current js instance

      this.listener.on('layout', FuncLayout)
      this.listener.on('draw', FuncDraw)

      // Unregister the callback with the corresponding query condition by using the handle. You can determine when to call this API.
      // this.listener.off('layout', OffFuncLayout)
      // this.listener.off('draw', OffFuncDraw)
    }
  }
  ```
