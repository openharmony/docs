# @ohos.mediaquery (Media Query)

The **mediaquery** module provides different styles for different media types.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> This module cannot be used in the file declaration of the [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md). In other words, the APIs of this module can be used only after a component instance is created; they cannot be called in the lifecycle of the UIAbility.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](js-apis-arkui-UIContext.md#uicontext).
>
> Since API version 10, you can use the [getMediaQuery](js-apis-arkui-UIContext.md#getmediaquery) API in [UIContext](js-apis-arkui-UIContext.md#uicontext) to obtain the [MediaQuery](js-apis-arkui-UIContext.md#mediaquery) object associated with the current UI context.


## Modules to Import

```ts
import { mediaquery } from '@kit.ArkUI';
```


## mediaquery.matchMediaSync

matchMediaSync(condition: string): MediaQueryListener

Sets the media query condition. This API returns the corresponding media query listener.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| condition | string | Yes  | Media query condition. For details, see [Syntax](../../ui/arkts-layout-development-media-query.md#syntax).|

**Return value**

| Type              | Description                                        |
| ------------------ | -------------------------------------------- |
| [MediaQueryListener](#mediaquerylistener) | Media query listener, which is used to register or deregister the listening callback.|

**Example**

```ts
import { mediaquery } from '@kit.ArkUI';

let listener: mediaquery.MediaQueryListener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen for landscape events.
```


## MediaQueryListener

Implements the media query listener, including the first query result when the listener is applied for. The specified media query condition, for example, **'(width <= 600vp)'**, is compared system information. If related information is not initialized during the first query, **matches** returns **false**.

Inherits from [MediaQueryResult](#mediaqueryresult).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


### on('change')

on(type: 'change', callback: Callback&lt;MediaQueryResult&gt;): void

Registers a media query listener. The callback is triggered when the media attributes change.

> **NOTE**
>
> The **on** or **off** function cannot be called in the registered callback.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                 | Mandatory| Description                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------ |
| type     | string                                                | Yes  | Listener type. The value is fixed at **'change'**.|
| callback | Callback&lt;[MediaQueryResult](#mediaqueryresult)&gt; | Yes  | Callback registered with media query.    |

**Example**

  See the example of [off](#offchange).


### off('change')

off(type: 'change', callback?: Callback&lt;MediaQueryResult&gt;): void

Deregisters a media query listener, so that no callback is triggered when the media attributes change.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                            | Mandatory| Description                                                      |
| -------- | -------------------------------- | ---- | ---------------------------------------------------------- |
| type     | string                           | Yes  | Listener type. The value is fixed at **'change'**.                                  |
| callback | Callback&lt;[MediaQueryResult](#mediaqueryresult)&gt; | No  | Callback to be deregistered. If the default value is used, all callbacks of the handle are deregistered.|

**Example**

  ```ts
import { mediaquery } from '@kit.ArkUI';

let listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen for landscape events.
function onPortrait(mediaQueryResult:mediaquery.MediaQueryResult) {
  if (mediaQueryResult.matches) {
    // do something here
  } else {
    // do something here
  }
}
listener.on('change', onPortrait) // Register the media query listener.
listener.off('change', onPortrait) // Deregister the listener.
  ```

## MediaQueryResult

Provides the media query result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


### Properties

| Name   | Type   | Readable| Writable| Description                |
| ------- | ------- | ---- | ---- | -------------------- |
| matches | boolean | Yes  | No  | Whether the media query condition is met. The value **true** means that the query conditions are met, and **false** means the opposite. |
| media   | string  | Yes  | No  | Media query condition.|


### Example

> **NOTE**
>
> You are advised to use the [getMediaQuery](js-apis-arkui-UIContext.md#getmediaquery) API in [UIContext](js-apis-arkui-UIContext.md#uicontext) to obtain the [MediaQuery](js-apis-arkui-UIContext.md#mediaquery) object associated with the current UI context.

```ts
import { mediaquery } from '@kit.ArkUI';

@Entry
@Component
struct MediaQueryExample {
  @State color: string = '#DB7093'
  @State text: string = 'Portrait'
  listener = mediaquery.matchMediaSync('(orientation: landscape)') // You are advised to use this.getUIContext().getMediaQuery().matchMediaSync().

  onPortrait(mediaQueryResult:mediaquery.MediaQueryResult) {
    if (mediaQueryResult.matches) {
      this.color = '#FFD700'
      this.text = 'Landscape'
    } else {
      this.color = '#DB7093'
      this.text = 'Portrait'
    }
  }

  aboutToAppear() {
    let portraitFunc = (mediaQueryResult: mediaquery.MediaQueryResult): void => this.onPortrait(mediaQueryResult)
    // Register the callback.
    this.listener.on('change', portraitFunc);
  }

  aboutToDisappear() {
    // Unregister the callback.
    this.listener.off('change');
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(this.text).fontSize(24).fontColor(this.color)
    }
    .width('100%').height('100%')
  }
}
```
