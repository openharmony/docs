# Graphics Subsystem Changelog

## cl.graphic.1 **getPixelMap** Replaced by **getEffectPixelMap**

**Access Level**

Public

**Reason for Change**

**getPixelMap** is a synchronous API. Its running takes a long time and may block the main thread. Therefore, it is deprecated and replaced by an asynchronous API.

**Change Impact**

The change is not compatible with earlier versions. Use the new API in your code.

**API Level**
9

**Deprecated Since**

OpenHarmony SDK 4.1.5.5

**Deprecated APIs**

| API                                                    | Description                                                    | Substitute API                                                    |
| ------------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| getPixelMap():image.PixelMap; | This API takes a long time and is replaced by an asynchronous API.  | getEffectPixelMap():Promise<image.PixelMap>; |

**Adaptation Guide**

In the sample code below:

```ts
import image from "@ohos.multimedia.image";
import effectKit from "@ohos.effectKit";

const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
};
image.createPixelMap(color, opts).then((pixelMap) => {
  let pixel = effectKit.createEffect(pixelMap).grayscale().getPixelMap();
  console.log('getPixelBytesNumber = ', pixel.getPixelBytesNumber());
})
```
Before change:
```ts
let pixel = effectKit.createEffect(pixelMap).grayscale().getPixelMap();
```
After change:
```ts
effectKit.createEffect(pixelMap).grayscale().getEffectPixelMap().then(data => {
    let pixel = data;
}).catch(ex => console.log("getEffectPixelMap error: " + ex.toString()));
```
In summary, replace **getPixelMap** with **getEffectPixelMap**, and use a promise to receive the **pixelMap** object.

