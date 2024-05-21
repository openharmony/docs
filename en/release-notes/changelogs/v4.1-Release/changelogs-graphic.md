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

| API                           | Description                                                  | Substitute API                               |
| ----------------------------- | ------------------------------------------------------------ | -------------------------------------------- |
| getPixelMap():image.PixelMap; | This API takes a long time and is replaced by an asynchronous API. | getEffectPixelMap():Promise<image.PixelMap>; |

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

## cl.blendMode.1 blendMode Changed

**Access Level**

Public API

**Reason for Change**

The API behavior fails to meet the requirements of third-party applications in multiple scenarios.  

**Change Impact**

This change is a non-compatible change.

1. The enumerated values of **blendMode** are changed. Specifically, **NORMAL** is changed to **NONE**, **SOURCE_IN** is changed to **SRC_IN**, and **DESTINATION_IN** is changed to **DST_IN**.
2. The API behavior is changed. Before the change, the API blends the component background with the subnode content. After the change, the API blends the component content (including the subnode content) with the content of the canvas (possibly offscreen canvas).

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

The enumerated values and behavior of **blendMode** are changed.

**Adaptation Guide**

1. Change the enumerated values in your code. Specifically, change **NORMAL** to **NONE**, **SOURCE_IN** to **SRC_IN**, and **DESTINATION_IN** to **DST_IN**.
2. The API behavior is changed. Before the change, the API provides two offscreen operations, which are used to the component background and subnode content, respectively. After the change, the API supports only one offscreen operation, which must be triggered by calling **BlendApplyType.OFFSCREEN**. If you want to retain the original behavior, call **BlendApplyType.OFFSCREEN** twice to trigger two offscreen operations to draw the component background and subnode content.<br>
   
   The sample code is as follows:
   
     ```ts
     // In the .ets file that uses the new API, you can call BlendApplyType.OFFSCREEN twice to trigger two offscreen operations.
     @Entry
     @Component
     struct Index {
       build() {
         Column() {
           // The second offscreen operation is used to draw the subnode content.
           Text("test")
             .fontSize(144)
             .fontWeight(FontWeight.Bold)
             .fontColor('#ffff0101')
             .blendMode(BlendMode.SRC_IN, BlendApplyType.OFFSCREEN)
         }
        // The first offscreen operation is used to draw the component background.
         .blendMode(BlendMode.SRC_OVER, BlendApplyType.OFFSCREEN)
         .height('100%')
         .width('100%')
         .backgroundColor('#ff08ff00')
       }
     }
     
     // In the .ets file that uses the original API, two offscreen operations are triggered by default.
     @Entry
     @Component
     struct Index {
       build() {
         Column() {
           // The second offscreen operation is used to draw the subnode content.
           Text("test")
             .fontSize(144)
             .fontWeight(FontWeight.Bold)
             .fontColor('#ffff0101')
         }
         // The first offscreen operation is used to draw the component background.
         .blendMode(BlendMode.SRC_IN)
         .height('100%')
         .width('100%')
         .backgroundColor('#ff08ff00')
       }
     }
     ```