# Media Query

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import mediaquery from '@ohos.mediaquery'
```


## Required Permissions

None.


## mediaquery.matchMediaSync

matchMediaSync(condition: string): MediaQueryListener

Sets the media query criteria and returns the corresponding listening handle.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name      | Type    | Mandatory  | Description                                      |
| --------- | ------ | ---- | ---------------------------------------- |
| condition | string | Yes   | Matching condition of a media event. For details, see [Syntax of Media Query Conditions](../../ui/ui-ts-layout-mediaquery.md#syntax-of-media-query-conditions).|

**Return value**
| Type                | Description                    |
| ------------------ | ---------------------- |
| MediaQueryListener | Listening handle to a media event, which is used to register or deregister the listening callback.|

**Example**
  ```js
listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen for landscape events.
  ```


## MediaQueryListener

Media query handle, including the first query result when the handle is applied for.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Attributes

| Name     | Type   | Readable  | Writable  | Description        |
| ------- | ------- | ---- | ---- | ---------- |
| matches | boolean | Yes   | No   | Whether the match condition is met. |
| media   | string  | Yes   | No   | Matching condition of a media event.|


### on

on(type: 'change', callback: Callback&lt;MediaQueryResult&gt;): void

Registers a callback with the corresponding query condition by using the handle. This callback is triggered when the media attributes change.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name     | Type                              | Mandatory  | Description              |
| -------- | -------------------------------- | ---- | ---------------- |
| type     | string                           | Yes   | Must enter the string **change**.|
| callback | Callback&lt;MediaQueryResult&gt; | Yes   | Callback registered with media query.      |

**Example**
  For details, see [off Example](#off).


### off

off(type: 'change', callback?: Callback&lt;MediaQueryResult&gt;): void

Deregisters a callback with the corresponding query condition by using the handle, so that no callback is triggered when the media attributes change.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name     | Type                              | Mandatory  | Description                           |
| -------- | -------------------------------- | ---- | ----------------------------- |
| type     | boolean                          | Yes   | Must enter the string **change**.             |
| callback | Callback&lt;MediaQueryResult&gt; | No   | Callback to be deregistered. If the default value is used, all callbacks of the handle are deregistered.|

**Example**
  ```js
    import mediaquery from '@ohos.mediaquery'
    
    listener = mediaquery.matchMediaSync('(orientation: landscape)'); // Listen for landscape events.
    function onPortrait(mediaQueryResult) {
        if (mediaQueryResult.matches) {
            // do something here
        } else {
            // do something here
        }
    }
    listener.on('change', onPortrait) // Register a callback.
    listener.off('change', onPortrait) // Deregister a callback.
  ```


## MediaQueryResult


### Attributes

| Name     | Type   | Readable  | Writable  | Description        |
| ------- | ------- | ---- | ---- | ---------- |
| matches | boolean | Yes   | No   | Whether the match condition is met. |
| media   | string  | Yes   | No   | Matching condition of a media event.|


### Example

```js
import mediaquery from '@ohos.mediaquery'

let portraitFunc = null

@Entry
@Component
struct MediaQueryExample {
  @State color: string = '#DB7093'
  @State text: string = 'Portrait'
  listener = mediaquery.matchMediaSync('(orientation: landscape)')

  onPortrait(mediaQueryResult) {
    if (mediaQueryResult.matches) {
      this.color = '#FFD700'
      this.text = 'Landscape'
    } else {
      this.color = '#DB7093'
      this.text = 'Portrait'
    }
  }

  aboutToAppear() {
    portraitFunc = this.onPortrait.bind(this) //bind current js instance
    this.listener.on('change', portraitFunc)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text(this.text).fontSize(24).fontColor(this.color)
    }
    .width('100%').height('100%')
  }
}
```
