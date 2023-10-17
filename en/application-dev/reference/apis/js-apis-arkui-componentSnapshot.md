# @ohos.arkui.componentSnapshot (Component Snapshot)

The **componentSnapshot** module provides APIs for obtaining component snapshots, including snapshots of components that have been loaded and snapshots of components that have not been loaded yet. Note that a component snapshot does not contain content drawn outside of the area of the owning component or the parent component.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.


## Modules to Import

```ts
import componentSnapshot from "@ohos.arkui.componentSnapshot";
```

## componentSnapshot.get

get(id: string, callback: AsyncCallback<image.PixelMap>): void

Obtains the snapshot of a component that has been loaded. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The snapshot captures content rendered in the last frame. If this API is called when the component triggers an update, the re-rendered content will not be included in the obtained snapshot.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                 | Mandatory  | Description                                      |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| id       | string                              | Yes   | [ID](../arkui-ts/ts-universal-attributes-component-id.md) of the target component.|
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes   | Callback used to return the result.                              |

**Error codes**

| ID| Error Message           |
| -------- | ------------------- |
| 100001   | if id is not valid. |

**Example**

```ts
import componentSnapshot from '@ohos.arkui.componentSnapshot'
import image from '@ohos.multimedia.image'

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap|undefined = undefined

  build() {
    Column() {
      Image(this.pixmap)
        .width(300).height(300)
      // ...Component
      // ...Component
      // ...Component
      Button("click to generate UI snapshot")
        .onClick(() => {
          componentSnapshot.get("root", (error: Error, pixmap: image.PixelMap) => {
                 this.pixmap = pixmap
                 // save pixmap to file
                 // ....
             })
        })
    }
    .width('80%')
    .margin({ left: 10, top: 5, bottom: 5 })
    .height(200)
    .border({ color: '#880606', width: 2 })
    .id("root")
  }
}
```

## componentSnapshot.get

get(id: string): Promise<image.PixelMap>

Obtains the snapshot of a component that has been loaded. This API uses a promise to return the result.

> **NOTE**
>
> The snapshot captures content rendered in the last frame. If this API is called when the component triggers an update, the re-rendered content will not be included in the obtained snapshot.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| id   | string | Yes   | [ID](../arkui-ts/ts-universal-attributes-component-id.md) of the target component.|

**Return value**

| Type                           | Description      |
| ----------------------------- | -------- |
| Promise&lt;image.PixelMap&gt; | Promise used to return the result.|

**Error codes**

| ID | Error Message               |
| ------ | ------------------- |
| 100001 | if id is not valid. |

**Example**

```ts
import componentSnapshot from '@ohos.arkui.componentSnapshot'
import image from '@ohos.multimedia.image'

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap|undefined = undefined

  build() {
    Column() {
      Image(this.pixmap)
        .width(300).height(300)
      // ...Component
      // ...Component
      // ...Component
      Button("click to generate UI snapshot")
        .onClick(() => {
          componentSnapshot.get("root")
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap
              // save pixmap to file
              // ....
            })
        })
    }
    .width('80%')
    .margin({ left: 10, top: 5, bottom: 5 })
    .height(200)
    .border({ color: '#880606', width: 2 })
    .id("root")
  }
}
```

## componentSnapshot.createFromBuilder

createFromBuilder(builder: CustomBuilder, callback: AsyncCallback<image.PixelMap>): void

Renders a custom component in the application background and outputs its snapshot. This API uses an asynchronous callback to return the result. The coordinates and size of the offscreen component's drawing area can be obtained through the callback.

> **NOTE**
>
> To account for the time spent in awaiting component building and rendering, the callback of offscreen snapshots has a delay of less than 500 ms.
>
> If a component is on a time-consuming task, for example, an **\<Image>** or **\<Web>** component that is loading online images, its loading may be still in progress when this API is called. In this case, the output snapshot does not represent the component in the way it looks when the loading is successfully completed.


**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description        |
| -------- | ---------------------------------------- | ---- | ---------- |
| builder  | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) | Yes   | Builder of the custom component.|
| callback | AsyncCallback&lt;image.PixelMap&gt;      | Yes   | Callback used to return the result. The coordinates and size of the offscreen component's drawing area can be obtained through the callback.|

**Error codes**

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 100001   | if builder is not a valid build function. |

**Example**

```ts
import componentSnapshot from '@ohos.arkui.componentSnapshot'
import image from '@ohos.multimedia.image'
import componentUtils from '@ohos.arkui.componentUtils'

@Entry
@Component
struct OffscreenSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined

  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }

  build() {
    Column() {
      Button("click to generate offscreen UI snapshot")
        .onClick(() => {
          componentSnapshot.createFromBuilder(()=>{this.RandomBuilder()},
            (error: Error, pixmap: image.PixelMap) => {
              this.pixmap = pixmap
              // save pixmap to file
              // ....
              // get component size and location
              let info = componentUtils.getRectangleById("builder")
              console.log(info.size.width + ' ' + info.size.height + ' ' + info.localOffset.x + ' ' + info.localOffset.y + ' ' + info.windowOffset.x + ' ' + info.windowOffset.y)
            })
        })
    }.width('80%').margin({ left: 10, top: 5, bottom: 5 }).height(200)
    .border({ color: '#880606', width: 2 })
  }
}
```

## componentSnapshot.createFromBuilder

createFromBuilder(builder: CustomBuilder): Promise<image.PixelMap>

Renders a custom component in the application background and outputs its snapshot. This API uses a promise to return the result. The coordinates and size of the offscreen component's drawing area can be obtained through the callback.

> **NOTE**
>
> To account for the time spent in awaiting component building and rendering, the callback of offscreen snapshots has a delay of less than 500 ms.
>
> If a component is on a time-consuming task, for example, an **\<Image>** or **\<Web>** component that is loading online images, its loading may be still in progress when this API is called. In this case, the output snapshot does not represent the component in the way it looks when the loading is successfully completed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                      | Mandatory  | Description        |
| ------- | ---------------------------------------- | ---- | ---------- |
| builder | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) | Yes   | Builder of the custom component.|

**Return value**

| Type                           | Description      |
| ----------------------------- | -------- |
| Promise&lt;image.PixelMap&gt; | Promise used to return the result.|

**Error codes**

| ID | Error Message                                    |
| ------ | ---------------------------------------- |
| 100001 | if builder is not a valid build function. |

**Example**

```ts
import componentSnapshot from '@ohos.arkui.componentSnapshot'
import image from '@ohos.multimedia.image'
import componentUtils from '@ohos.arkui.componentUtils'

@Entry
@Component
struct OffscreenSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined

  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }

  build() {
    Column() {
      Button("click to generate offscreen UI snapshot")
        .onClick(() => {
          componentSnapshot.createFromBuilder(()=>{this.RandomBuilder()})
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap
              // save pixmap to file
              // ....
              // get component size and location
              let info = componentUtils.getRectangleById("builder")
              console.log(info.size.width + ' ' + info.size.height + ' ' + info.localOffset.x + ' ' + info.localOffset.y + ' ' + info.windowOffset.x + ' ' + info.windowOffset.y)
            })
        })
    }.width('80%').margin({ left: 10, top: 5, bottom: 5 }).height(200)
    .border({ color: '#880606', width: 2 })
  }
}
```
