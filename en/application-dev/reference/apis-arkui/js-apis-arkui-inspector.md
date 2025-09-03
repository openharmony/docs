# @ohos.arkui.inspector (Layout Callback)

The **Inspector** module provides APIs for registering the component layout and drawing completion callbacks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

<!--deprecated_code_no_check-->
```ts
import { inspector } from '@kit.ArkUI';
```

## inspector.createComponentObserver<sup>(deprecated)</sup>

createComponentObserver(id: string): ComponentObserver

Binds to the specified component and returns the corresponding observation handle.

> **NOTE**
> 
> This API is deprecated since API version 18. You are advised to use [createComponentObserver](js-apis-arkui-UIContext.md#createcomponentobserver) instead on the obtained [UIInspector](js-apis-arkui-UIContext.md#uiinspector) object.
>
> Since API version 10, you can use the [getUIInspector](js-apis-arkui-UIContext.md#getuiinspector) API in [UIContext](js-apis-arkui-UIContext.md#uicontext) to obtain the [UIInspector](js-apis-arkui-UIContext.md#uiinspector) object associated with the current UI context.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| id     | string | Yes  | ID of the target component, set using the universal attributes [id](./arkui-ts/ts-universal-attributes-component-id.md#id) or [key](./arkui-ts/ts-universal-attributes-component-id.md#key12).|

**Return value**

| Type             | Description                                            |
| ----------------- | ------------------------------------------------ |
|[ComponentObserver](#componentobserver)| Component observer handle, which is used to register and unregister callbacks.|

**Example**
```ts
let listener:inspector.ComponentObserver = inspector.createComponentObserver('COMPONENT_ID'); // Listen for callback events for the component whose ID is COMPONENT_ID.
```

## ComponentObserver

Implements an observer for layout and drawing completion callbacks for components, containing the initial query results from when the observer was created.

### on('layout')

on(type: 'layout', callback: () => void): void

Registers a layout completion callback through this handle.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description|
| -------- | ------ | ---- | -------------------------------------|
| type     | string | Yes  | Event type. The value is fixed at **'layout'**.<br>**'layout'**: completion of component layout.|
| callback | () => void   | Yes  | Layout completion callback.|

### off('layout')

off(type: 'layout', callback?: () => void): void

Unregisters the layout completion callback through this handle.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description|
| -------- | ------ | ---- | -------------------------------------------- |
| type     | string | Yes  | Event type. The value is fixed at **'layout'**.<br>**'layout'**: completion of component layout.|
| callback | () => void   | No  | Callback to unregister. If this parameter is not specified, all callbacks under this handle are unregistered. The callback must be the same object as the one registered with the [on('layout')](#onlayout) API to successfully unregister.|

### on('draw')

on(type: 'draw', callback: () => void): void

Registers a drawing completion callback through this handle.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type. The value is fixed at **'draw'**.<br>**'draw'**: completion of component drawing.|
| callback | () => void   | Yes  | Drawing completion callback.                                    |

### off('draw')

off(type: 'draw', callback?: () => void): void

Unregisters the drawing completion callback through this handle.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type. The value is fixed at **'draw'**.<br>**'draw'**: completion of component drawing.|
| callback | () => void   | No  | Callback to unregister. If this parameter is not specified, all callbacks under this handle are unregistered. The callback must be the same object as the one registered with the [on('draw')](#ondraw) API to successfully unregister.|

**Example**

> **NOTE**
>
> You are advised to use the [getUIInspector](./js-apis-arkui-UIContext.md#getuiinspector) API in [UIContext](./js-apis-arkui-UIContext.md#uicontext) to obtain the [UIInspector](./js-apis-arkui-UIContext.md#uiinspector) object associated with the current UI context.

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

    listener:inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('IMAGE_ID')

    aboutToAppear() {
      let onLayoutComplete:()=>void=():void=>{
          // do something here
      }
      let onDrawComplete:()=>void=():void=>{
          // do something here
      }
      let FuncLayout = onLayoutComplete // bind current js instance
      let FuncDraw = onDrawComplete // bind current js instance
      let OffFuncLayout = onLayoutComplete // bind current js instance
      let OffFuncDraw = onDrawComplete // bind current js instance

      this.listener.on('layout', FuncLayout)
      this.listener.on('draw', FuncDraw)

      // Unregister callbacks through the handle. You should decide when to call these APIs.
      // this.listener.off('layout', OffFuncLayout)
      // this.listener.off('draw', OffFuncDraw)
    }
  }
  ```
