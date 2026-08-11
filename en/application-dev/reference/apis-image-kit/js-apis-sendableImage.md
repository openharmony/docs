# @ohos.multimedia.sendableImage (Image Processing Based on Sendable Objects)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=a569cef255f0bfd2be482f42d11f341117248869 translatedAt=2026-08-03T04:07:11.191Z pushedAt=2026-08-04T02:13:19.637Z -->

The module provides APIs for image processing based on the [Sendable](../../arkts-utils/arkts-sendable.md) object. You can use the APIs to create a PixelMap object with specified properties or read pixels of an image (or even in a region of an image).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { sendableImage } from '@kit.ImageKit';
```

## sendableImage.createPixelMap

createPixelMap(colors: ArrayBuffer, options: image.InitializationOptions): Promise\<PixelMap>

Creates a PixelMap object with the default BGRA_8888 format and specified pixel properties. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format.                                       |
| options | [image.InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editability.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](#pixelmap)> | Promise used to return the PixelMap object.<br>If the size of the created PixelMap exceeds that of the original image, the PixelMap size of the original image is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMap() {
    const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
    let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
    sendableImage.createPixelMap(color, opts).then((pixelMap: sendableImage.PixelMap) => {
        console.info('Succeeded in creating pixelmap.');
    }).catch((error: BusinessError) => {
        console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
    })
}
```

## sendableImage.createPixelMapFromParcel

createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap

Creates a PixelMap object from a MessageSequence object.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object that stores the PixelMap information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | Operation failed|
| 62980097 | IPC error|
| 62980115 | Invalid input parameter|
| 62980105 | Failed to get the data|
| 62980177 | Abnormal API environment|
| 62980178 | Failed to create the PixelMap|
| 62980179 | Abnormal buffer size|
| 62980180 | FD mapping failed|
| 62980246 | Failed to read the PixelMap|

**Example**

```ts
// EntryAbility.ets
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MySequence implements rpc.Parcelable {
  pixel_map: sendableImage.PixelMap;
  constructor(conPixelmap: sendableImage.PixelMap) {
    this.pixel_map = conPixelmap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    try {
      this.pixel_map = sendableImage.createPixelMapFromParcel(messageSequence);
    } catch(e) {
      let error = e as BusinessError;
      console.error(`Failed to create a PixelMap from a parcel. Code: ${error.code}, message: ${error.message}.`);
      return false;
    }
    return true;
  }
}
async function CreatePixelMapFromParcel() {
  const color: ArrayBuffer = new ArrayBuffer(96);
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = 0x80;
  }
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: 4,
    size: { height: 4, width: 6 },
    alphaType: 3
  }
  let pixelMap: sendableImage.PixelMap | undefined = undefined;
  await sendableImage.createPixelMap(color, opts).then((srcPixelMap: sendableImage.PixelMap) => {
    pixelMap = srcPixelMap;
  })
  if (pixelMap != undefined) {
    // Implement serialization.
    let parcelable: MySequence = new MySequence(pixelMap);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // Implement deserialization to obtain data through the RPC.
    let ret: MySequence = new MySequence(pixelMap);
    data.readParcelable(ret);

    // Obtain the PixelMap object.
    let newPixelMap = ret.pixel_map;
  }
}
```

## sendableImage.createPixelMapFromSurface

createPixelMapFromSurface(surfaceId: string, region: image.Region): Promise\<PixelMap>

Creates a PixelMap object based on the surface ID and region information. The size of the region is specified by [Region](arkts-apis-image-i.md#region8).size. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which can be obtained through the preview component, for example, [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|
| region                 | [image.Region](arkts-apis-image-i.md#region8)  | Yes  | Area of the image to capture. Capture must start from the top-left corner of the screen, so **x** and **y** in **Region** must be **0**, and **Width** and **height** in **Region.size** must be within the range [1, preview stream width] and [1, preview stream height], respectively. To capture any area, first obtain the full screen, and then use [crop](#crop) to capture the desired area.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap)> | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | If the image parameter invalid.|
| 62980105 | Failed to get the data|
| 62980178 | Failed to create the PixelMap|

**Example**

```ts

import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapFromSurface(surfaceId: string) {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  sendableImage.createPixelMapFromSurface(surfaceId, region).then(() => {
    console.info('Succeeded in creating pixelmap from Surface');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
  });
}
```

## sendableImage.createPixelMapSync

createPixelMapSync(colors: ArrayBuffer, options: image.InitializationOptions): PixelMap

Creates a PixelMap object with the specified pixel properties. This API returns the result synchronously.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format.                                       |
| options | [image.InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editability.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapSync() {
    const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
    let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
    let pixelMap : sendableImage.PixelMap = sendableImage.createPixelMapSync(color, opts);
    return pixelMap;
}
```

## sendableImage.convertFromPixelMap

convertFromPixelMap(pixelmap: image.PixelMap): PixelMap

Creates a PixelMap object under **sendableImage** from a PixelMap object under **image**. This API returns the result synchronously. The APIs of the PixelMap object under **image** cannot be called anymore.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| pixelmap | [image.PixelMap](arkts-apis-image-PixelMap.md) | Yes  | PixelMap object under image.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | PixelMap object, which is sendable. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | If the image parameter invalid. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 62980104 | Failed to initialize the internal object.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';

async function ConvertFromPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
  let pixelMap : image.PixelMap = image.createPixelMapSync(color, opts);
  let sendablePixelMap : sendableImage.PixelMap = sendableImage.convertFromPixelMap(pixelMap);
  return sendablePixelMap;
}
```

## sendableImage.convertToPixelMap

convertToPixelMap(pixelmap: PixelMap): image.PixelMap

Creates a PixelMap object under **image** from a PixelMap object under **sendableImage**. This API returns the result synchronously. The APIs of the PixelMap object under **sendableImage** cannot be called anymore.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| pixelmap | [PixelMap](#pixelmap) | Yes  | PixelMap object under **sendableImage**.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [image.PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object, which is not sendable. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | If the image parameter invalid. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 62980104 | Failed to initialize the internal object.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';

async function ConvertToPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
  let sendablePixelMap : sendableImage.PixelMap = sendableImage.createPixelMapSync(color, opts);
  let pixelMap : image.PixelMap = sendableImage.convertToPixelMap(sendablePixelMap);
  return pixelMap;
}
```

## ISendable

type ISendable = lang.ISendable

**ISendable** is the parent type of all sendable types except null and undefined. It does not have any necessary methods or properties.

**System capability**: SystemCapability.Multimedia.Image.Core

| Type               | Description                    |
| ------------------ | ------------------------ |
| [lang.ISendable](../apis-arkts/js-apis-arkts-lang.md#langisendable)  | Parent type of all sendable types.              |

## PixelMap

Provides APIs to read or write image data and obtain image information. Before calling any API in PixelMap, you must use [createPixelMap](#sendableimagecreatepixelmap) to create a PixelMap object. Currently, the maximum size of a serialized PixelMap is 128 MB. A larger size will cause a display failure. The size is calculated as follows: Width × Height × Bytes each pixel.

The PixelMap object under **sendableImage** supports the **sendable** attribute and sharing of the worker thread. The [Convert](#sendableimageconverttopixelmap) API can be used to convert a PixelMap object in **sendableImage** to a PixelMap object in **image**, and vise versa. After the conversion, the APIs of the original object cannot be called. Otherwise, error 501 is reported. When processing a PixelMap object across threads, you need to consider the multithreaded problem.

Before calling any API in PixelMap, you must use [sendableImage.createPixelMap](#sendableimagecreatepixelmap) to create a PixelMap object.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

### Properties

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Type   | Read-Only| Optional| Description                      |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable        | boolean | Yes  | No  | Whether the PixelMap is editable. The value **true** means that the PixelMap is editable, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| isStrideAlignment | boolean | Yes  | No  | Whether the PixelMap uses DMA memory. The value** true** means that the PixelMap uses DMA memory, and **false** means the opposite. The PixelMap in DMA memory is aligned to 256-byte boundaries, with padding areas at the end of each row.|

### readPixelsToBuffer

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

Reads the pixels of this image and writes the data to an ArrayBuffer. This API uses a promise to return the result.

If the PixelMap is created in the BGRA_8888 format, the data read is the same as the original data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                                                                 |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | Yes  | Buffer to which the pixels will be written. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber).|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sendableImage } from '@kit.ImageKit';

async function ReadPixelsToBuffer(pixelMap : sendableImage.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBuffer(readBuffer).then(() => {
      console.info('Succeeded in reading image pixel data.'); // Called if the condition is met.
    }).catch((error: BusinessError) => {
      console.error(`Failed to read image pixel data. code is ${error.code}, message is ${error.message}`); // Called if no condition is met.
    })
  }
}
```

### readPixelsToBufferSync

readPixelsToBufferSync(dst: ArrayBuffer): void

Reads the pixels of this image and writes the data to an ArrayBuffer. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Buffer to which the pixels will be written. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function ReadPixelsToBufferSync(pixelMap: sendableImage.PixelMap) {
  const bufferSize = pixelMap.getPixelBytesNumber();
  const readBuffer: ArrayBuffer = new ArrayBuffer(bufferSize);
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBufferSync(readBuffer);
  }
}
```

### readPixels

readPixels(area: image.PositionArea): Promise\<void>

Reads the pixels in an area. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area from which the pixels will be read.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ReadPixels(pixelMap : sendableImage.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  if (pixelMap != undefined) {
    pixelMap.readPixels(area).then(() => {
      console.info('Succeeded in reading the image data in the area.'); // Called if the condition is met.
    }).catch((error: BusinessError) => {
      console.error(`Failed to read the image data in the area. code is ${error.code}, message is ${error.message}`); // Called if no condition is met.
    })
  }
}
```

### readPixelsSync

readPixelsSync(area: image.PositionArea): void

Reads the pixels in an area. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area from which the pixels will be read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';

async function ReadPixelsSync(pixelMap : sendableImage.PixelMap) {
  const area : image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  if (pixelMap != undefined) {
    pixelMap.readPixelsSync(area);
  }
}
```

### writePixels

writePixels(area: image.PositionArea): Promise\<void>

Writes the pixels to an area. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to which the pixels will be written.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function WritePixels(pixelMap : sendableImage.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writePixels(area).then(() => {
      console.info('Succeeded to write pixelmap into the specified area.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### writePixelsSync

writePixelsSync(area: image.PositionArea): void

Writes the pixels to an area. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to which the pixels will be written.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';

async function WritePixelsSync(pixelMap : sendableImage.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writePixelsSync(area);
  }
}
```

### writeBufferToPixels

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

Reads the pixels in the buffer and writes the result to a PixelMap. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Buffer from which the image data will be read.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteBufferToPixels(pixelMap : sendableImage.PixelMap) {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writeBufferToPixels(color).then(() => {
      console.info("Succeeded in writing data from a buffer to a PixelMap.");
    }).catch((error: BusinessError) => {
      console.error(`Failed to write data from a buffer to a PixelMap. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### writeBufferToPixelsSync

writeBufferToPixelsSync(src: ArrayBuffer): void

Reads the pixels in the buffer and writes the result to a PixelMap. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Buffer from which the image data will be read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function WriteBufferToPixelsSync(pixelMap: sendableImage.PixelMap) {
  const bufferSize = pixelMap.getPixelBytesNumber();
  const color : ArrayBuffer = new ArrayBuffer(bufferSize);
  let bufferArr : Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writeBufferToPixelsSync(color);
  }
}
```

### getImageInfo

getImageInfo(): Promise\<image.ImageInfo>

Obtains the image information. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[image.ImageInfo](arkts-apis-image-i.md#imageinfo)> | Promise used to return the image information. If the operation fails, an error message is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageInfo(pixelMap : sendableImage.PixelMap) {
  if (pixelMap != undefined) {
    pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
      if (imageInfo != undefined) {
        console.info("Succeeded in obtaining the image pixel map information."+ imageInfo.size.height);
      }
    }).catch((error: BusinessError) => {
      console.error(`Failed to obtain the image pixel map information. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### getImageInfoSync

getImageInfoSync(): image.ImageInfo

Obtains the image information. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| [image.ImageInfo](arkts-apis-image-i.md#imageinfo)           | Image information.                                               |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { sendableImage } from '@kit.ImageKit';

async function GetImageInfoSync(pixelMap : sendableImage.PixelMap) {
  if (pixelMap != undefined) {
    let imageInfo : image.ImageInfo = pixelMap.getImageInfoSync();
  }
}
```

### getBytesNumberPerRow

getBytesNumberPerRow(): number

Obtains the number of bytes per row of this image. Unit: bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Number of bytes per row.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function GetBytesNumberPerRow(pixelMap : sendableImage.PixelMap) {
  let rowCount: number = pixelMap.getBytesNumberPerRow();
}
```

### getPixelBytesNumber

getPixelBytesNumber(): number

Obtains the total number of bytes of this image. Unit: bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Total number of bytes.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function GetPixelBytesNumber(pixelMap : sendableImage.PixelMap) {
  let pixelBytesNumber: number = pixelMap.getPixelBytesNumber();
}
```

### getDensity

getDensity():number

Obtains the pixel density of this image.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description           |
| ------ | --------------- |
| number | Pixel density, in ppi.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function GetDensity(pixelMap : sendableImage.PixelMap) {
  let getDensity: number = pixelMap.getDensity();
}
```

### opacity

opacity(rate: number): Promise\<void>

Sets the opacity rate to enable the PixelMap to achieve the corresponding opacity effect. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | Yes  | Opacity rate. The value range is (0,1].|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Opacity(pixelMap : sendableImage.PixelMap) {
  let rate: number = 0.5;
  if (pixelMap != undefined) {
    pixelMap.opacity(rate).then(() => {
      console.info('Succeeded in setting opacity.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to set opacity. code is ${err.code}, message is ${err.message}`);
    })
  }
}
```

### opacitySync

opacitySync(rate: number): void

Sets the opacity rate for this PixelMap and initializes the PixelMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | Yes  | Opacity rate. The value range is (0,1].  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function OpacitySync(pixelMap : sendableImage.PixelMap) {
  let rate : number = 0.5;
  if (pixelMap != undefined) {
    pixelMap.opacitySync(rate);
  }
}
```

### createAlphaPixelmap

createAlphaPixelmap(): Promise\<PixelMap>

Creates a PixelMap object that contains only the alpha channel information. This object can be used for the shadow effect. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                       |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap)> | Promise used to return the PixelMap object.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateAlphaPixelmap(pixelMap : sendableImage.PixelMap) {
  if (pixelMap != undefined) {
    pixelMap.createAlphaPixelmap().then((alphaPixelMap: sendableImage.PixelMap) => {
      console.info('Succeeded in creating alpha pixelmap.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to create alpha pixelmap. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### createAlphaPixelmapSync

createAlphaPixelmapSync(): PixelMap

Creates a PixelMap object that contains only the alpha channel information. This object can be used for the shadow effect. This API returns the result synchronously.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function CreateAlphaPixelmapSync(pixelMap : sendableImage.PixelMap) {
  let resPixelMap : sendableImage.PixelMap = pixelMap.createAlphaPixelmapSync();
  return resPixelMap;
}
```

### scale

scale(x: number, y: number): Promise\<void>

Scales this PixelMap based on a given width and height. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Scale(pixelMap : sendableImage.PixelMap) {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scale(scaleX, scaleY).then(() => {
      console.info('Succeeded in scaling pixelmap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to scale pixelmap. code is ${err.code}, message is ${err.message}`);

    })
  }
}
```

### scaleSync

scaleSync(x: number, y: number): void

Scales this image based on a given width and height. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function ScaleSync(pixelMap : sendableImage.PixelMap) {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scaleSync(scaleX, scaleY);
  }
}
```

### translate

translate(x: number, y: number): Promise\<void>

Translates this PixelMap based on given coordinates. This API uses a promise to return the result.

The size of the translated image is changed to width+X and height+Y. It is recommended that the new width and height not exceed the width and height of the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| x      | number | Yes  | X coordinate, in px.|
| y      | number | Yes  | Y coordinate, in px.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Translate(pixelMap : sendableImage.PixelMap) {
  let translateX: number = 50.0;
  let translateY: number = 10.0;
  if (pixelMap != undefined) {
    pixelMap.translate(translateX, translateY).then(() => {
      console.info('Succeeded in translating pixelmap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to translate pixelmap. code is ${err.code}, message is ${err.message}`);
    })
  }
}
```

### translateSync

translateSync(x: number, y: number): void

Translates this image based on given coordinates. This API returns the result synchronously.

The size of the translated image is changed to width+X and height+Y. It is recommended that the new width and height not exceed the width and height of the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x      | number | Yes  | X coordinate, in px.|
| y      | number | Yes  | Y coordinate, in px.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function TranslateSync(pixelMap : sendableImage.PixelMap) {
  let translateX : number = 50.0;
  let translateY : number = 10.0;
  if (pixelMap != undefined) {
    pixelMap.translateSync(translateX, translateY);
  }
}
```

### rotate

rotate(angle: number): Promise\<void>

Rotates this PixelMap based on a given angle. This API uses a promise to return the result.

> **NOTE**
>
> - The allowable range for image rotation angles is [0, 360]. Angles outside this range are automatically adjusted according to the 360-degree cycle. For example, an angle of -100 degrees will produce the same result as 260 degrees.
> - If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                         |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | Yes  | Angle to rotate. Unit: degrees.             |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Rotate(pixelMap : sendableImage.PixelMap) {
  let angle: number = 90.0;
  if (pixelMap != undefined) {
    pixelMap.rotate(angle).then(() => {
      console.info('Succeeded in rotating pixelmap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to rotate pixelmap. code is ${err.code}, message is ${err.message}`);
    })
  }
}
```

### rotateSync

rotateSync(angle: number): void

Rotates this image based on a given angle. This API returns the result synchronously.

> **NOTE**
>
> - The allowable range for image rotation angles is [0, 360]. Angles outside this range are automatically adjusted according to the 360-degree cycle. For example, an angle of -100 degrees will produce the same result as 260 degrees.
> - If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Angle to rotate. Unit: degrees.             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function RotateSync(pixelMap : sendableImage.PixelMap) {
  let angle : number = 90.0;
  if (pixelMap != undefined) {
    pixelMap.rotateSync(angle);
  }
}
```

### flip

flip(horizontal: boolean, vertical: boolean): Promise\<void>

Flips this PixelMap horizontally or vertically, or both. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type   | Mandatory| Description     |
| ---------- | ------- | ---- | --------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. The value **true** means to flip the image horizontally, and **false** means the opposite.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. The value **true** means to flip the image vertically, and **false** means the opposite.           |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Flip(pixelMap : sendableImage.PixelMap) {
  let horizontal: boolean = true;
  let vertical: boolean = false;
  if (pixelMap != undefined) {
    pixelMap.flip(horizontal, vertical).then(() => {
      console.info('Succeeded in flipping pixelmap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to flip pixelmap. code is ${err.code}, message is ${err.message}`);

    })
  }
}
```

### flipSync

flipSync(horizontal: boolean, vertical: boolean): void

Flips this image horizontally or vertically, or both. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description                         |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. The value **true** means to flip the image horizontally, and **false** means the opposite.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. The value **true** means to flip the image vertically, and **false** means the opposite.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function FlipSync(pixelMap : sendableImage.PixelMap) {
  let horizontal : boolean = true;
  let vertical : boolean = false;
  if (pixelMap != undefined) {
    pixelMap.flipSync(horizontal, vertical);
  }
}
```

### crop

crop(region: image.Region): Promise\<void>

Crops this PixelMap based on a given size. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type              | Mandatory| Description       |
| ------ | ------------------ | ---- | ----------- |
| region | [image.Region](../apis-image-kit/arkts-apis-image-i.md#region8) | Yes  | Size of the image after cropping.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Crop(pixelMap : sendableImage.PixelMap) {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  if (pixelMap != undefined) {
    pixelMap.crop(region).then(() => {
      console.info('Succeeded in cropping pixelmap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to crop pixelmap. code is ${err.code}, message is ${err.message}`);

    });
  }
}
```

### cropSync

cropSync(region: image.Region): void

Crops this image based on a given size. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [image.Region](../apis-image-kit/arkts-apis-image-i.md#region8)   | Yes  | Size of the image after cropping.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';

async function CropSync(pixelMap : sendableImage.PixelMap) {
  let region : image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  if (pixelMap != undefined) {
    pixelMap.cropSync(region);
  }
}
```

### getColorSpace

getColorSpace(): colorSpaceManager.ColorSpaceManager

Obtains the color space of this image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                               | Description            |
| ----------------------------------- | ---------------- |
| [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Color space.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980101| If the image data abnormal.            |
| 62980103| If the image data unsupport.             |
| 62980115| If the image parameter invalid.            |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function GetColorSpace(pixelMap : sendableImage.PixelMap) {
  if (pixelMap != undefined) {
    let csm = pixelMap.getColorSpace();
  }
}
```

### setColorSpace

setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void

Sets the color space for this image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                               | Mandatory| Description           |
| ---------- | ----------------------------------- | ---- | --------------- |
| colorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Color space.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980111| If the operation invalid.        |
| 62980115| If the image parameter invalid.             |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

async function SetColorSpace(pixelMap : sendableImage.PixelMap) {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB; // The colorSpaceManager.ColorSpace object is supported only on 2-in-1 devices/PCs.
  let csm: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.setColorSpace(csm);
  }
}
```

### applyColorSpace

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager): Promise\<void>

Performs Color Space Converters (CSC) on the image pixel color based on a given color space. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type              | Mandatory| Description       |
| ------ | ------------------ | ---- | ----------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Target color space. SRGB, DCI_P3, DISPLAY_P3, and ADOBE_RGB_1998 are supported.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

async function ApplyColorSpace(pixelMap : sendableImage.PixelMap) {
    let colorSpaceName = colorSpaceManager.ColorSpace.SRGB; // The colorSpaceManager.ColorSpace object is supported only on 2-in-1 devices/PCs.
    let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
    pixelMap.applyColorSpace(targetColorSpace).then(() => {
        console.info('Succeeded in applying color space for pixelmap object.');
    }).catch((error: BusinessError) => {
        console.error(`Failed to apply color space for pixelmap object. code is ${error.code}, message is ${error.message}`); 
    })
}
```

### marshalling

marshalling(sequence: rpc.MessageSequence): void

Marshals this PixelMap object and writes it to a MessageSequence object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)  | Yes  | MessageSequence object.                |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error.             |

**Example**

```ts
// EntryAbility.ets
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixel_map: sendableImage.PixelMap;
  constructor(conPixelMap : sendableImage.PixelMap) {
    this.pixel_map = conPixelMap;
  }
  marshalling(messageSequence : rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    console.info('Succeeded in marshalling a PixelMap.');
    return true;
  }
  unmarshalling(messageSequence : rpc.MessageSequence) {
    sendableImage.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel: sendableImage.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: sendableImage.PixelMap) => {
        this.pixel_map = pixelMap;
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
          console.info(`Succeeded in unmarshalling a PixelMap. Height: ${imageInfo.size.height}, width: ${imageInfo.size.width}.`);
        })
      })
    });
    return true;
  }
}

async function Marshalling() {
  const color: ArrayBuffer = new ArrayBuffer(96);
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = 0x80;
  }
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: 4,
    size: { height: 4, width: 6 },
    alphaType: 3
  }
  let pixelMap: sendableImage.PixelMap | undefined = undefined;
  await sendableImage.createPixelMap(color, opts).then((srcPixelMap: sendableImage.PixelMap) => {
    pixelMap = srcPixelMap;
  })
  if (pixelMap != undefined) {
    // Implement serialization.
    let parcelable: MySequence = new MySequence(pixelMap);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // Implement deserialization to obtain data through the RPC.
    let ret: MySequence = new MySequence(pixelMap);
    data.readParcelable(ret);
  }
}
```

### unmarshalling

unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>

Unmarshals a MessageSequence object to obtain a PixelMap object. This API uses a promise to return the result.

To create a PixelMap object in synchronous mode, use [createPixelMapFromParcel](#sendableimagecreatepixelmapfromparcel).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object that stores the PixelMap information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap)> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error.              |
| 62980096 | The operation failed.         |

**Example**

```ts
// EntryAbility.ets
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixel_map: sendableImage.PixelMap;
  constructor(conPixelMap: sendableImage.PixelMap) {
    this.pixel_map = conPixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    console.info('Succeeded in marshalling a PixelMap.');
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    sendableImage.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel : sendableImage.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap : sendableImage.PixelMap) => {
        this.pixel_map = pixelMap;
        pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
          console.info(`Succeeded in unmarshalling a PixelMap. Height: ${imageInfo.size.height}, width: ${imageInfo.size.width}.`);
        })
      })
    });
    return true;
  }
}

async function Unmarshalling() {
  const color: ArrayBuffer = new ArrayBuffer(96);
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = 0x80;
  }
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: 4,
    size: { height: 4, width: 6 },
    alphaType: 3
  }
  let pixelMap: sendableImage.PixelMap | undefined = undefined;
  await sendableImage.createPixelMap(color, opts).then((srcPixelMap : sendableImage.PixelMap) => {
    pixelMap = srcPixelMap;
  })
  if (pixelMap != undefined) {
    // Implement serialization.
    let parcelable: MySequence = new MySequence(pixelMap);
    let data : rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // Implement deserialization to obtain data through the RPC.
    let ret : MySequence = new MySequence(pixelMap);
    data.readParcelable(ret);
  }
}
```

### release

release():Promise\<void>

Releases this PixelMap object. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sendableImage } from '@kit.ImageKit';

async function Release(pixelMap: sendableImage.PixelMap) {
  if (pixelMap != undefined) {
    await pixelMap.release().then(() => {
      console.info('Succeeded in releasing pixelmap object.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to release pixelmap object. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

## Size

Describes the size of an image.

It inherits from [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type  | Read-Only| Optional| Description          |
| ------ | ------ | ---- | ---- | -------------- |
| height | number | No  | No  | Height of the output image, in px.|
| width  | number | No  | No  | Width of the output image, in px.|

## Region

Describes the region information.

It inherits from [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Read-Only| Optional| Description        |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | No  | No  | Region size.  |
| x    | number        | No  | No  | X coordinate, in px.|
| y    | number        | No  | No  | Y coordinate, in px.|

## sendableImage.createImageSource

createImageSource(uri: string): ImageSource

Creates an ImageSource instance based on a given URI.

Images occupy a large amount of memory. When you finish using an ImageSource instance, call [release](#release-1) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | Yes  | Image path. Currently, only the application sandbox path is supported.<br>The following formats are supported: .jpg, .png, .gif, .bmp, .webp, .dng [SVG](arkts-apis-image-f.md#svg-tags), and ico.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function CreateImageSource(context : Context) {
  const path: string = context.cacheDir + "/test.jpg";
  const sendableImageSourceObj: sendableImage.ImageSource = sendableImage.createImageSource(path);
}
```

## sendableImage.createImageSource

createImageSource(fd: number): ImageSource

Creates an ImageSource instance based on a given file descriptor.

Images occupy a large amount of memory. When you finish using an ImageSource instance, call [release](#release-1) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description         |
| ------ | ------ | ---- | ------------- |
| fd     | number | Yes  | File descriptor.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { fileIo } from '@kit.CoreFileKit';

async function CreateImageSource(context : Context) {
  const path: string = context.cacheDir + "/test.jpg";
  let file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const sendableImageSourceObj: sendableImage.ImageSource = sendableImage.createImageSource(file.fd);
}
```

## sendableImage.createImageSource

createImageSource(buf: ArrayBuffer): ImageSource

Creates an ImageSource instance based on buffers. The data passed by **buf** must be undecoded. Do not pass the pixel buffer data such as RBGA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [sendableImage.createPixelMap](#sendableimagecreatepixelmap).

Images occupy a large amount of memory. When you finish using an ImageSource instance, call [release](#release-1) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type       | Mandatory| Description            |
| ------ | ----------- | ---- | ---------------- |
| buf    | ArrayBuffer | Yes  | Array of image buffers.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';

async function CreateImageSource() {
  const buf: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  const sendableImageSourceObj: sendableImage.ImageSource = sendableImage.createImageSource(buf);
}
```

## sendableImage.createImageReceiver

createImageReceiver(size: image.Size, format: image.ImageFormat, capacity: number): ImageReceiver

Creates an ImageReceiver instance based on the specified image size, format, and capacity.

Images occupy a large amount of memory. When you finish using an ImageReceiver instance, call [release](#release-3) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| size    | [image.Size](./arkts-apis-image-i.md#size)  | Yes  | Default size of the image.      |
| format   | [image.ImageFormat](./arkts-apis-image-e.md#imageformat9) | Yes  | Image format, which is a constant of **image.ImageFormat**. (Currently, only **ImageFormat:JPEG** is supported.)            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time. This parameter is used only as an expected value. The actual capacity is determined by the device hardware.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver) | ImageReceiver instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    |  The parameter check failed. |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';

async function CreateImageReceiver() {
    let size: image.Size = {
        height: 8192,
        width: 8
    } 
    let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
}
```

## ImageSource

Provides APIs to obtain image information. Before calling any API in ImageSource, you must use [sendableImage.createImageSource](#sendableimagecreateimagesource) to create an ImageSource instance.

Images occupy a large amount of memory. When you finish using an ImageSource instance, call [release](#release-1) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

### createPixelMap

createPixelMap(options?: image.DecodingOptions): Promise\<PixelMap>

Creates a PixelMap object based on decoding options. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                | Mandatory| Description      |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [image.DecodingOptions](./arkts-apis-image-i.md#decodingoptions7) | No  | Decoding options.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap)> | Promise used to return the PixelMap object.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMap(context : Context) {
  const path: string = context.cacheDir + "/test.jpg";
  const sendableImageSourceObj: sendableImage.ImageSource = sendableImage.createImageSource(path);
  sendableImageSourceObj.createPixelMap().then((pixelMap: sendableImage.PixelMap) => {
    console.info('Succeeded in creating pixelMap object through image decoding parameters.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelMap object through image decoding parameters. code ${error.code}, message is ${error.message}`);
  })
}
```

### release

release(): Promise\<void>

Releases this ImageSource instance. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using an ImageSource instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Release(context : Context) {
  const path: string = context.cacheDir + "/test.jpg";
  const sendableImageSourceObj: sendableImage.ImageSource = sendableImage.createImageSource(path);
  sendableImageSourceObj.release().then(() => {
    console.info('Succeeded in releasing the image source instance.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to release the image source instance. code ${error.code}, message is ${error.message}`);
  })
}
```

## Image

Provides APIs for basic image operations, including obtaining image information and reading and writing image data. An Image instance is returned when [readNextImage](#readnextimage) and [readLatestImage](#readlatestimage) are called. This class inherits from [ISendable](../../arkts-utils/arkts-sendable.md#isendable).

Images occupy a large amount of memory. When you finish using an Image instance, call [release](#release-2) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

### Properties

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    | Type              | Read-Only| Optional| Description                                              |
| -------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect | [Region](#region) | No  | No  | Image area to be cropped.                                |
| size     | [Size](#size)      | Yes  | No  | Image size.<br>If the Image object stores camera preview stream data (YUV image data), the width and height in **size** reflect the dimensions of the YUV image.<br>If the Image object stores camera capture stream data (JPEG image data), given that it is an encoded file, the width in **size** is the size of the JPEG file, while the height is set to **1**.<br>The type of data stored in the Image object depends on whether the application passes the surface ID in the receiver to a previewOutput or captureOutput object of the camera.<br>For details about the best practices of camera preview and photo capture, see [Dual-Channel Preview (ArkTS)](../../media/camera/camera-dual-channel-preview.md) and [Photo Capture Sample (ArkTS)](../../media/camera/camera-shooting-case.md).|
| format   | number             | Yes  | No  | Image format. For details, see [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_format).|
| timestamp| number         | Yes     | No  | Image timestamp. Timestamps, measured in nanoseconds, are usually monotonically increasing. The specific meaning and baseline of these timestamps are determined by the image producer, which is the camera in the camera preview and photo scenarios. As a result, images from different producers may carry timestamps with distinct meanings and baselines, making direct comparison between them infeasible. To obtain the generation time of a photo, you can use [getImageProperty](arkts-apis-image-ImageSource.md#getimageproperty11) to read the related Exif information.|

### getComponent

getComponent(componentType: image.ComponentType): Promise\<image.Component>

Obtains the component buffer from the Image instance based on the color component type. This API uses a promise to return the result. The thread that runs **getComponent** is insecure.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| componentType | [image.ComponentType](./arkts-apis-image-e.md#componenttype9) | Yes  | Color component type of the image.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise<[image.Component](./arkts-apis-image-i.md#component9)> | Promise used to return the component buffer.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetComponent() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  let img = await receiver.readNextImage();
  img.getComponent(image.ComponentType.JPEG).then((component: image.Component) => {
    console.info('Succeeded in getting an image component.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to get an image component. Code: ${error.code}, message: ${error.message}.`);
  })
}
```

### release

release(): Promise\<void>

Releases this Image instance. This API uses a promise to return the result.

The corresponding resources must be released before another image arrives.

Images occupy a large amount of memory. When you finish using an Image instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function Release() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  let img = await receiver.readNextImage();
  img.release().then(() => {
    console.info('Succeeded in releasing an image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to release an image. Code: ${error.code}, message: ${error.message}.`);
  })
}
```

## ImageReceiver

Image receiver class. You can use it to obtain the surface ID of a component, read the latest image and the next image, and release **ImageReceiver** instances.

Before calling any APIs in ImageReceiver, you must create an ImageReceiver instance.

### Properties

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name    | Type                        | Read-Only| Optional| Description              |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| size     | [image.Size](./arkts-apis-image-i.md#size)                | Yes  | No  | Image size.        |
| capacity | number                       | Yes  | No  | Maximum number of images that can be accessed at the same time. This parameter is used only as an expected value. The actual capacity is determined by the device hardware.|
| format   | [image.ImageFormat](./arkts-apis-image-e.md#imageformat9) | Yes  | No  | Image format.        |

### getReceivingSurfaceId

getReceivingSurfaceId(): Promise\<string>

Obtains a surface ID for the camera or other components. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<string> | Asynchronously returns the surface ID.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetReceivingSurfaceId() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  receiver.getReceivingSurfaceId().then((id: string) => {
    console.info('Succeeded in getting the ReceivingSurfaceId.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to get the ReceivingSurfaceId.code ${error.code}, message is ${error.message}`);
  })
}
```

### readLatestImage

readLatestImage(): Promise\<Image>

Reads the latest image from the ImageReceiver instance. This API uses a promise to return the result.

> **NOTE**
>This API can be called to receive data only after the [on](#on) callback is triggered. When the [Image](#image) object returned by this API is no longer needed, call [release](#release-2) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description              |
| ------------------------- | ------------------ |
| Promise<[Image](#image)> | Promise used to return the latest image.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadLatestImage() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  receiver.readLatestImage().then((img: sendableImage.Image) => {
    console.info('Succeeded in reading the latest image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to read the latest image. Code: ${error.code}, message: ${error.message}.`);
  })
}
```

### readNextImage

readNextImage(): Promise\<Image>

Reads the next image from the ImageReceiver instance. This API uses a promise to return the result.

> **NOTE**
>This API can be called to receive data only after the [on](#on) callback is triggered. When the [Image](#image) object returned by this API is no longer needed, call [release](#release-2) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description                |
| ------------------------- | -------------------- |
| Promise<[Image](#image)> | Promise used to return the next image.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadNextImage() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  receiver.readNextImage().then((img: sendableImage.Image) => {
    console.info('Succeeded in reading the next image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to read the next image. Code: ${error.code}, message: ${error.message}.`);
  })
}
```

### on

on(type: 'imageArrival', callback: AsyncCallback\<void>): void

Listens for image arrival events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                | Mandatory| Description                                                  |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **'imageArrival'**, which is triggered when an image is received.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked for the event.                                      |

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';

async function On() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  receiver.on('imageArrival', () => {
    // Implement the callback logic when an image is received.
  })
}
```

### release

release(): Promise\<void>

Releases this ImageReceiver instance. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using an ImageReceiver instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type          | Description              |
| -------------- | ------------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { sendableImage } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function Release() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  receiver.release().then(() => {
    console.info('Succeeded in releasing an image receiver.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to release an image receiver. Code: ${error.code}, message: ${error.message}.`);
  })
}
```