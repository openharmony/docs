# @ohos.arkui.drawableDescriptor (DrawableDescriptor)

The **DrawableDescriptor** module provides APIs for obtaining **pixelMap** objects, including the foreground, background, mask, and layered icons.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor';
```

## DrawableDescriptor

### getPixelMap

getPixelMap(): image.PixelMap

Obtains this **pixelMap** object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | **PixelMap** object.|

**Example**
  ```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'
let resManager = getContext().resourceManager
let pixmap: DrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.icon')
    .id)) as DrawableDescriptor;
let pixmapNew: object = pixmap.getPixelMap()
  ```

Creates a **DrawableDescriptor** object when the passed resource ID or name belongs to a common image.

## LayeredDrawableDescriptor

Creates a **LayeredDrawableDescriptor** object when the passed resource ID or name belongs to a JSON file that contains foreground and background resources. This API is inherited from [DrawableDescriptor](#drawabledescriptor).

The **drawable.json** file is located under **entry/src/main/resources/base/media** in the project directory. Below shows the file content:

```json
{
  "layered-image":
  {
    "background" : "$media:background",
    "foreground" : "$media:foreground"
  }
}
```

**Example**
```ts
// xxx.ets
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'

@Entry
@Component
struct Index {
  private resManager = getContext().resourceManager

  build() {
    Row() {
      Column() {
        Image((this.resManager.getDrawableDescriptor($r('app.media.drawable').id) as LayeredDrawableDescriptor))
        Image(((this.resManager.getDrawableDescriptor($r('app.media.drawable')
          .id) as LayeredDrawableDescriptor).getForeground()).getPixelMap())
      }.height('50%')
    }.width('50%')
  }
}
```

### getPixelMap

getPixelMap(): image.PixelMap

Obtains the **pixelMap** object where the foreground, background, and mask are blended and cropped.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | **PixelMap** object.|

**Example**
  ```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'
let resManager = getContext().resourceManager
let pixmap: LayeredDrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.drawable')
    .id)) as LayeredDrawableDescriptor;
let pixmapNew: object = pixmap.getPixelMap()
  ```

### getForeground
getForeground(): DrawableDescriptor;

Obtains the **DrawableDescriptor** object of the foreground.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description                  |
| ---------------------------------------- | -------------------- |
| [DrawableDescriptor](#drawabledescriptor) | **DrawableDescriptor** object.|

**Example**
  ```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'
let resManager = getContext().resourceManager
let drawable: LayeredDrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.drawable')
    .id)) as LayeredDrawableDescriptor;
let drawableNew: object = drawable.getForeground()
  ```

### getBackground

getBackground(): DrawableDescriptor;

Obtains the **DrawableDescriptor** object of the background.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description                  |
| ---------------------------------------- | -------------------- |
| [DrawableDescriptor](#drawabledescriptor) | **DrawableDescriptor** object.|

**Example**
  ```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'
let resManager = getContext().resourceManager
let drawable: LayeredDrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.drawable')
    .id)) as LayeredDrawableDescriptor;
let drawableNew: object = drawable.getBackground()
  ```

### getMask

getMask(): DrawableDescriptor

Obtains the **DrawableDescriptor** object of the mask.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description                  |
| ---------------------------------------- | -------------------- |
| [DrawableDescriptor](#drawabledescriptor) | **DrawableDescriptor** object.|

**Example**
  ```ts
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'
let resManager = getContext().resourceManager
let drawable: LayeredDrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.drawable')
    .id)) as LayeredDrawableDescriptor;
let drawableNew: object = drawable.getMask()
  ```
### getMaskClipPath

static getMaskClipPath(): string

Obtains the built-in clipping path parameters of the system. It is a static method of **LayeredDrawableDescriptor**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                      | Description                  |
| ---------------------------------------- | -------------------- |
| string | String of the clipping path.|

**Example**

  ```ts
// xxx.ets
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Image($r('app.media.icon'))
          .width('200px').height('200px')
          .clip(new Path({commands:LayeredDrawableDescriptor.getMaskClipPath()}))
        Text(`Obtain the built-in clip path parameters:`)
          .fontWeight(800)
        Text(JSON.stringify(LayeredDrawableDescriptor.getMaskClipPath()))
          .padding({ left: 20, right: 20 })
      }.height('100%').justifyContent(FlexAlign.Center)
    }.width('100%')
  }
}
  ```
