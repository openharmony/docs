# @ohos.multimedia.image (Image Processing)

The **Image** module provides APIs for image processing. You can use the APIs to create a **PixelMap** object with specified properties or read pixels of an image (or even in a region of an image).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - Since API version 12, the APIs of this module are supported in ArkTS widgets.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>

Creates a **PixelMap** object with the default BGRA_8888 format and specified pixel properties. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format.                                       |
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.<br>If the size of the created pixel map exceeds that of the original image, the pixel map size of the original image is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
  image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating pixelmap.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
  })
}
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object with the default BGRA_8888 format and specified pixel properties. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format. |
| options  | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties.                    |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the **PixelMap** object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
  image.createPixelMap(color, opts, (error: BusinessError, pixelMap: image.PixelMap) => {
    if(error) {
      console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
      return;
    } else {
      console.info('Succeeded in creating pixelmap.');
    }
  })
}
```

## image.createPixelMapFromParcel<sup>11+</sup>

createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap

Creates a **PixelMap** object from a **MessageSequence** object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | **MessageSequence** object that stores the **PixelMap** information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | Returns a **PixelMap** object if the operation is successful; throws an error otherwise.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | Operation failed|
| 62980097 | IPC error.|
| 62980115 | Invalid input parameter|
| 62980105 | Failed to get the data|
| 62980177 | Abnormal API environment|
| 62980178 | Failed to create the PixelMap|
| 62980179 | Abnormal buffer size|
| 62980180 | FD mapping failed|
| 62980246 | Failed to read the PixelMap|

**Example**

```ts
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MySequence implements rpc.Parcelable {
  pixel_map: image.PixelMap;
  constructor(conPixelmap: image.PixelMap) {
    this.pixel_map = conPixelmap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    try {
      this.pixel_map = image.createPixelMapFromParcel(messageSequence);
    } catch(e) {
      let error = e as BusinessError;
      console.error(`createPixelMapFromParcel error. code is ${error.code}, message is ${error.message}`);
      return false;
    }
    return true;
  }
}
async function Demo() {
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
  let pixelMap: image.PixelMap | undefined = undefined;
  image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
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
    let unmarshPixelmap = ret.pixel_map;
  }
}
```

## image.createPixelMapFromSurface<sup>11+</sup>

createPixelMapFromSurface(surfaceId: string, region: Region): Promise\<PixelMap>

Creates a **PixelMap** object from a surface ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|
| region                 | [Region](#region7)  | Yes  | Size of the image.                        |

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | If the image parameter invalid.|
| 62980105 | Failed to get the data|
| 62980178 | Failed to create the PixelMap|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(surfaceId: string) {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  image.createPixelMapFromSurface(surfaceId, region).then(() => {
    console.info('Succeeded in creating pixelmap from Surface');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
  });
} 
```

## image.createPixelMapFromSurfaceSync<sup>12+</sup>

createPixelMapFromSurfaceSync(surfaceId: string, region: Region): PixelMap

Creates a **PixelMap** object from a surface ID. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|
| region                 | [Region](#region7)  | Yes  | Size of the image.                        |

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | Returns a **PixelMap** object if the operation is successful; throws an error otherwise.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|
| 62980105 | Failed to get the data|
| 62980178 | Failed to create the PixelMap|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(surfaceId: string) {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  let pixelMap : image.PixelMap = image.createPixelMapFromSurfaceSync(surfaceId, region);
  return pixelMap;
}
```

## image.createPixelMapSync<sup>12+</sup>

createPixelMapSync(colors: ArrayBuffer, options: InitializationOptions): PixelMap

Creates a **PixelMap** object with the specified pixel properties. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format.                                       |
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | Returns a **PixelMap** object if the operation is successful; throws an error otherwise.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
  let pixelMap : image.PixelMap = image.createPixelMapSync(color, opts);
  return pixelMap;
}
```

## image.createPixelMapSync<sup>12+</sup>

createPixelMapSync(options: InitializationOptions): PixelMap

Creates a **PixelMap** object with the specified pixel properties. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | Returns a **PixelMap** object if the operation is successful; throws an error otherwise.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
  let pixelMap : image.PixelMap = image.createPixelMapSync(opts);
  return pixelMap;
}
```

## image.createPremultipliedPixelMap<sup>12+</sup>

createPremultipliedPixelMap(src: PixelMap, dst: PixelMap, callback: AsyncCallback\<void>): void

Converts a non-premultiplied alpha of a pixel map to a premultiplied one and stores the converted data to a target pixel map. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](#pixelmap7) | Yes  | Source **PixelMap** object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target **PixelMap** object.|
|callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|
|  62980103     | The image data is not supported |
|  62980246      | Failed to read the pixelMap |
|  62980248     | Pixelmap not allow modify |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 2, width: 2 } , alphaType: 3}
  let srcPixelmap = image.createPixelMapSync(color, opts);
  let dstPixelMap = image.createPixelMapSync(opts);
  image.createPremultipliedPixelMap(srcPixelmap, dstPixelMap, (error: BusinessError) => {
    if(error) {
      console.error(`Failed to convert pixelmap. code is ${error.code}, message is ${error.message}`);
      return;
    } else {
      console.info('Succeeded in converting pixelmap.');
    }
  })
}
```

## image.createPremultipliedPixelMap<sup>12+</sup>

createPremultipliedPixelMap(src: PixelMap, dst: PixelMap): Promise\<void>

Converts a non-premultiplied alpha of a pixel map to a premultiplied one and stores the converted data to a target pixel map. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](#pixelmap7) | Yes  | Source **PixelMap** object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target **PixelMap** object.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|
|  62980103     | The image data is not supported |
|  62980246      | Failed to read the pixelMap |
|  62980248     | Pixelmap not allow modify |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 2, width: 2 } , alphaType: 2}
  let srcPixelmap = image.createPixelMapSync(color, opts);
  let dstPixelMap = image.createPixelMapSync(opts);
  image.createPremultipliedPixelMap(srcPixelmap, dstPixelMap).then(() => {
    console.info('Succeeded in converting pixelmap.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to convert pixelmap. code is ${error.code}, message is ${error.message}`);
  })
}
```

## image.createUnpremultipliedPixelMap<sup>12+</sup>

createUnpremultipliedPixelMap(src: PixelMap, dst: PixelMap, callback: AsyncCallback\<void>): void

Converts a premultiplied alpha of a pixel map to a non-premultiplied one and stores the converted data to a target pixel map. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](#pixelmap7) | Yes  | Source **PixelMap** object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target **PixelMap** object.|
|callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|
|  62980103     | The image data is not supported |
|  62980246      | Failed to read the pixelMap |
|  62980248     | Pixelmap not allow modify |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 2, width: 2 } , alphaType: 2}
  let srcPixelmap = image.createPixelMapSync(color, opts);
  let dstPixelMap = image.createPixelMapSync(opts);
  image.createUnpremultipliedPixelMap(srcPixelmap, dstPixelMap, (error: BusinessError) => {
    if(error) {
      console.error(`Failed to convert pixelmap. code is ${error.code}, message is ${error.message}`);
      return;
    } else {
      console.info('Succeeded in converting pixelmap.');
    }
  })
}
```

## image.createUnpremultipliedPixelMap<sup>12+</sup>

createUnpremultipliedPixelMap(src: PixelMap, dst: PixelMap): Promise\<void>

Converts a premultiplied alpha of a pixel map to a non-premultiplied one and stores the converted data to a target pixel map. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| src | [PixelMap](#pixelmap7) | Yes  | Source **PixelMap** object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target **PixelMap** object.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|
|  62980103    | The image data is not supported |
|  62980246    | Failed to read the pixelMap. |
|  62980248    | PixelMap not allow modify. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 2, width: 2 } , alphaType: 3}
  let srcPixelmap = image.createPixelMapSync(color, opts);
  let dstPixelMap = image.createPixelMapSync(opts);
  image.createUnpremultipliedPixelMap(srcPixelmap, dstPixelMap).then(() => {
    console.info('Succeeded in converting pixelmap.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to convert pixelmap. code is ${error.code}, message is ${error.message}`);
  })
}
```


## PixelMap<sup>7+</sup>

Provides APIs to read or write image data and obtain image information. Before calling any API in **PixelMap**, you must use [createPixelMap](#imagecreatepixelmap8) to create a **PixelMap** object. Currently, the maximum size of a serialized pixel map is 128 MB. A larger size will cause a display failure. The size is calculated as follows: Width * Height * Number of bytes occupied by each pixel.

Since API version 11, **PixelMap** supports cross-thread calls through workers. If a **PixelMap** object is invoked by another thread through [Worker](../apis-arkts/js-apis-worker.md), all APIs of the **PixelMap** object cannot be called in the original thread. Otherwise, error 501 is reported, indicating that the server cannot complete the request. 

Before calling any API in **PixelMap**, you must use [image.createPixelMap](#imagecreatepixelmap8) to create a **PixelMap** object.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Type   | Readable| Writable| Description                      |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable        | boolean | Yes  | No  | Whether the pixels of an image are editable.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| isStrideAlignment<sup>11+</sup> | boolean | Yes  | No  | Whether the image memory is the DMA memory.|

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

Reads the pixels of this image and writes the data to the buffer based on the pixel format of the pixel map. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                                                                 |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | Yes  | Buffer to which the pixels will be written. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber7).|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBuffer(readBuffer).then(() => {
      console.info('Succeeded in reading image pixel data.'); // Called if the condition is met.
    }).catch((error: BusinessError) => {
      console.error(`Failed to read image pixel data. code is ${error.code}, message is ${error.message}`); // Called if no condition is met.
    })
  }
}
```

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads the pixels of this image and writes the data to the buffer based on the pixel format of the pixel map. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Buffer to which the pixels will be written. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber7).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBuffer(readBuffer, (error: BusinessError, res: void) => {
      if(error) {
        console.error(`Failed to read image pixel data. code is ${error.code}, message is ${error.message}`); // Called if no condition is met.
        return;
      } else {
        console.info('Succeeded in reading image pixel data.');  // Called if the condition is met.
      }
    })
  }
}
```

### readPixelsToBufferSync<sup>12+</sup>

readPixelsToBufferSync(dst: ArrayBuffer): void

Reads the pixels of this image and writes the data to the buffer based on the pixel format of the pixel map. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Buffer to which the pixels will be written. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber7).|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBufferSync(readBuffer);
  }
}
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

Reads the pixels from an area of this image and writes the data to the buffer based on the BGRA_8888 format. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](#positionarea7) | Yes  | Area from which the pixels will be read.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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
      console.error(`Failed to read the image data in the area. code is ${error.code}, message is ${error.message}`);// Called if no condition is met.
    })
  }
}
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

Reads the pixels from an area of this image and writes the data to the buffer based on the BGRA_8888 format. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                          | Mandatory| Description                          |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](#positionarea7) | Yes  | Area from which the pixels will be read.      |
| callback | AsyncCallback\<void>           | Yes  |  Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  if (pixelMap != undefined) {
    pixelMap.readPixels(area, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to read pixelmap from the specified area. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info('Succeeded in reading pixelmap from the specified area.');
      }
    })
  }
}
```

### readPixelsSync<sup>12+</sup>

readPixelsSync(area: PositionArea): void

Reads the pixels from an area of this image and writes the data to the buffer based on the BGRA_8888 format. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](#positionarea7) | Yes  | Area from which the pixels will be read.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### writePixels<sup>7+</sup>

writePixels(area: PositionArea): Promise\<void>

Writes the pixels of this image to the specified area based on the BGRA_8888 format. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](#positionarea7) | Yes  | Area to which the pixels will be written.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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
      console.info('Succeeded in writing pixelmap into the specified area.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

Writes the pixels of this image to the specified area based on the BGRA_8888 format. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name   | Type                          | Mandatory| Description                          |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](#positionarea7) | Yes  | Area to which the pixels will be written.          |
| callback  | AsyncCallback\<void>           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const area: image.PositionArea = { pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writePixels(area, (error : BusinessError) => {
      if (error) {
        console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info('Succeeded in writing pixelmap into the specified area.');
      }
    })
  }
}
```

### writePixelsSync<sup>12+</sup>

writePixelsSync(area: PositionArea): void

Writes the pixels of this image to the specified area based on the BGRA_8888 format. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](#positionarea7) | Yes  | Area to which the pixels will be written.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

Reads the pixels in the buffer and writes the data to the pixel map based on the pixel format of the pixel map. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Buffer from which the image data will be read.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
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

### writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads the pixels in the buffer and writes the data to the pixel map based on the pixel format of the pixel map. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | Yes  | Buffer from which the image data will be read.                |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color: ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writeBufferToPixels(color, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to write data from a buffer to a PixelMap. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info("Succeeded in writing data from a buffer to a PixelMap.");
      }
    })
  }
}
```

### writeBufferToPixelsSync<sup>12+</sup>

writeBufferToPixelsSync(src: ArrayBuffer): void

Reads the pixels in the buffer and writes the data to the pixel map based on the pixel format of the pixel map. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Buffer from which the image data will be read.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
  let bufferArr : Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writeBufferToPixelsSync(color);
  }
}
```


### getImageInfo<sup>7+</sup>

getImageInfo(): Promise\<ImageInfo>

Obtains the image information. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](#imageinfo)> | Promise used to return the image information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### getImageInfo<sup>7+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains the image information. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the image information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.getImageInfo((error: BusinessError, imageInfo: image.ImageInfo) => {
      if (error) {
        console.error(`Failed to obtain the image pixel map information. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info("Succeeded in obtaining the image pixel map information."+ imageInfo.size.height);
      }
    })
  }
}
```

### getImageInfoSync<sup>12+</sup>

getImageInfoSync(): ImageInfo

Obtains the image information. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| [ImageInfo](#imageinfo)           | Image information.                                               |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    let imageInfo : image.ImageInfo = pixelMap.getImageInfoSync();
    return imageInfo;
  }
  return undefined;
}
```

### getBytesNumberPerRow<sup>7+</sup>

getBytesNumberPerRow(): number

Obtains the number of bytes per row of this image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Number of bytes per row.|

**Example**

```ts
let rowCount: number = pixelMap.getBytesNumberPerRow();
```

### getPixelBytesNumber<sup>7+</sup>

getPixelBytesNumber(): number

Obtains the total number of bytes of this image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Total number of bytes.|

**Example**

```ts
let pixelBytesNumber: number = pixelMap.getPixelBytesNumber();
```

### getDensity<sup>9+</sup>

getDensity():number

Obtains the density of this image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description           |
| ------ | --------------- |
| number | Density of the image.|

**Example**

```ts
let getDensity: number = pixelMap.getDensity();
```

### opacity<sup>9+</sup>

opacity(rate: number, callback: AsyncCallback\<void>): void

Sets an opacity rate for this image. This API uses an asynchronous callback to return the result. It is invalid for YUV images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | Yes  | Opacity rate.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let rate: number = 0.5;
  if (pixelMap != undefined) {
    pixelMap.opacity(rate, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to set opacity. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in setting opacity.");
      }
    })
  }
}
```

### opacity<sup>9+</sup>

opacity(rate: number): Promise\<void>

Sets an opacity rate for this image. This API uses a promise to return the result. It is invalid for YUV images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | Yes  | Opacity rate.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### opacitySync<sup>12+</sup>

opacitySync(rate: number): void

Sets an opacity rate for this image. This API returns the result synchronously. It is invalid for YUV images.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | Yes  | Opacity rate.  |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let rate : number = 0.5;
  if (pixelMap != undefined) {
    pixelMap.opacitySync(rate);
  }
}
```

### createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

Creates a **PixelMap** object that contains only the alpha channel information. This object can be used for the shadow effect. This API uses a promise to return the result. It is invalid for YUV images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                       |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.createAlphaPixelmap().then((alphaPixelMap: image.PixelMap) => {
      console.info('Succeeded in creating alpha pixelmap.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to create alpha pixelmap. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object that contains only the alpha channel information. This object can be used for the shadow effect. This API uses an asynchronous callback to return the result. It is invalid for YUV images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                    |
| -------- | ------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)> | Yes  |  Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the **PixelMap** object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.createAlphaPixelmap((err: BusinessError, alphaPixelMap: image.PixelMap) => {
      if (alphaPixelMap == undefined) {
        console.error(`Failed to obtain new pixel map. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info('Succeeded in obtaining new pixel map.');
      }
    })
  }
}
```

### createAlphaPixelmapSync<sup>12+</sup>

createAlphaPixelmapSync(): PixelMap

Creates a **PixelMap** object that contains only the alpha channel information. This object can be used for the shadow effect. This API returns the result synchronously. It is invalid for YUV images.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | Returns a **PixelMap** object if the operation is successful; throws an error otherwise.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    let pixelmap : image.PixelMap = pixelMap.createAlphaPixelmapSync();
    return pixelmap;
  }
  return undefined;
}
```

### scale<sup>9+</sup>

scale(x: number, y: number, callback: AsyncCallback\<void>): void

Scales this image based on a given scaling multiple of the width and height. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | Yes  | Scaling multiple of the width.|
| y        | number               | Yes  | Scaling multiple of the height.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scale(scaleX, scaleY, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to scale pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in scaling pixelmap.");
      }
    })
  }
}
```

### scale<sup>9+</sup>

scale(x: number, y: number): Promise\<void>

Scales this image based on a given scaling multiple of the width and height. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scaling multiple of the width.|
| y      | number | Yes  | Scaling multiple of the height.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### scaleSync<sup>12+</sup>

scaleSync(x: number, y: number): void

Scales this image based on a given width and height. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scaling multiple of the width.|
| y      | number | Yes  | Scaling multiple of the height.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scaleSync(scaleX, scaleY);
  }
}
```

### scale<sup>12+</sup>

scale(x: number, y: number, level: AntiAliasingLevel): Promise\<void>

Scales this image based on a given scaling multiple of the width and height. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scaling multiple of the width.|
| y      | number | Yes  | Scaling multiple of the height.|
| level  | [AntiAliasingLevel](#antialiasinglevel12) | Yes  | Anti-aliasing level.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scale(scaleX, scaleY, image.AntiAliasingLevel.LOW).then(() => {
      console.info('Succeeded in scaling pixelmap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to scale pixelmap. code is ${err.code}, message is ${err.message}`);

    })
  }
}
```

### scaleSync<sup>12+</sup>

scaleSync(x: number, y: number, level: AntiAliasingLevel): void

Scales this image based on a given width and height. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scaling multiple of the width.|
| y      | number | Yes  | Scaling multiple of the height.|
| level  | [AntiAliasingLevel](#antialiasinglevel12) | Yes  | Anti-aliasing level.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scaleSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
  }
}
```

### translate<sup>9+</sup>

translate(x: number, y: number, callback: AsyncCallback\<void>): void

Translates this image based on given coordinates. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| x        | number               | Yes  | X coordinate to translate.                 |
| y        | number               | Yes  | Y coordinate to translate.                 |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let translateX: number = 50.0;
  let translateY: number = 10.0;
  if (pixelMap != undefined) {
    pixelMap.translate(translateX, translateY, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to translate pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in translating pixelmap.");
      }
    })
  }
}
```

### translate<sup>9+</sup>

translate(x: number, y: number): Promise\<void>

Translates this image based on given coordinates. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| x      | number | Yes  | X coordinate to translate.|
| y      | number | Yes  | Y coordinate to translate.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### translateSync<sup>12+</sup>

translateSync(x: number, y: number): void

Translates this image based on given coordinates. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | Yes  | Scaling multiple of the width.|
| y        | number               | Yes  | Scaling multiple of the height.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let translateX : number = 50.0;
  let translateY : number = 10.0;
  if (pixelMap != undefined) {
    pixelMap.translateSync(translateX, translateY);
  }
}
```

### rotate<sup>9+</sup>

rotate(angle: number, callback: AsyncCallback\<void>): void

Rotates this image based on a given angle. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Angle to rotate.             |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let angle: number = 90.0;
  if (pixelMap != undefined) {
    pixelMap.rotate(angle, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to rotate pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in rotating pixelmap.");
      }
    })
  }
}
```

### rotate<sup>9+</sup>

rotate(angle: number): Promise\<void>

Rotates this image based on a given angle. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                         |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | Yes  | Angle to rotate.             |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### rotateSync<sup>12+</sup>

rotateSync(angle: number): void

Rotates this image based on a given angle. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Angle to rotate.             |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let angle : number = 90.0;
  if (pixelMap != undefined) {
    pixelMap.rotateSync(angle);
  }
}
```

### flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void

Flips this image horizontally or vertically, or both. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description                         |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally.                   |
| vertical   | boolean              | Yes  | Whether to flip the image vertically.                   |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let horizontal: boolean = true;
  let vertical: boolean = false;
  if (pixelMap != undefined) {
    pixelMap.flip(horizontal, vertical, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to flip pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in flipping pixelmap.");
      }
    })
  }
}
```

### flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean): Promise\<void>

Flips this image horizontally or vertically, or both. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type   | Mandatory| Description     |
| ---------- | ------- | ---- | --------- |
| horizontal | boolean | Yes  | Whether to flip the image horizontally.|
| vertical   | boolean | Yes  | Whether to flip the image vertically.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### flipSync<sup>12+</sup>

flipSync(horizontal: boolean, vertical: boolean): void

Flips this image horizontally or vertically, or both. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description                         |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally.                   |
| vertical   | boolean              | Yes  | Whether to flip the image vertically.                   |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let horizontal : boolean = true;
  let vertical : boolean = false;
  if (pixelMap != undefined) {
    pixelMap.flipSync(horizontal, vertical);
  }
}
```

### crop<sup>9+</sup>

crop(region: Region, callback: AsyncCallback\<void>): void

Crops this image based on a given size. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](#region7)   | Yes  | Size of the image after cropping.                 |
| callback | AsyncCallback\<void> | Yes  |  Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  if (pixelMap != undefined) {
    pixelMap.crop(region, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to crop pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in cropping pixelmap.");
      }
    })
  }
}
```

### crop<sup>9+</sup>

crop(region: Region): Promise\<void>

Crops this image based on a given size. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type              | Mandatory| Description       |
| ------ | ------------------ | ---- | ----------- |
| region | [Region](#region7) | Yes  | Size of the image after cropping.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
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

### cropSync<sup>12+</sup>

cropSync(region: Region): void

Crops this image based on a given size. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](#region7)   | Yes  | Size of the image after cropping.                 |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let region : image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  if (pixelMap != undefined) {
    pixelMap.cropSync(region);
  }
}
```

### getColorSpace<sup>10+</sup>

getColorSpace(): colorSpaceManager.ColorSpaceManager

Obtains the color space of this image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                               | Description            |
| ----------------------------------- | ---------------- |
| [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Color space obtained.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980101| If the image data abnormal.            |
| 62980103| If the image data unsupport.             |
| 62980115| If the image parameter invalid.            |

**Example**

```ts
async function Demo() {
  if (pixelMap != undefined) {
    let csm = pixelMap.getColorSpace();
  }
}
```

### setColorSpace<sup>10+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void

Sets the color space for this image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                               | Mandatory| Description           |
| ---------- | ----------------------------------- | ---- | --------------- |
| colorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Color space to set.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980111| If the operation invalid.        |
| 62980115| If the image parameter invalid.             |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
async function Demo() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let csm: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.setColorSpace(csm);
  }
}
```

### applyColorSpace<sup>11+</sup>

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager, callback: AsyncCallback\<void>): void

Performs color space conversion (CSC) on the image pixel color based on a given color space. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Target color space. SRGB, DCI_P3, DISPLAY_P3, and ADOBE_RGB_1998 are supported.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.applyColorSpace(targetColorSpace, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to apply color space for pixelmap object. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info('Succeeded in applying color space for pixelmap object.');
      }
    })
  }
}
```

### applyColorSpace<sup>11+</sup>

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager): Promise\<void>

Performs CSC on the image pixel color based on a given color space. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type              | Mandatory| Description       |
| ------ | ------------------ | ---- | ----------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Target color space. SRGB, DCI_P3, DISPLAY_P3, and ADOBE_RGB_1998 are supported.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.applyColorSpace(targetColorSpace).then(() => {
      console.info('Succeeded in applying color space for pixelmap object.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to apply color space for pixelmap object. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### toSdr<sup>12+<sup>

toSdr(): Promise\<void>

Converts an HDR image into an SDR image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980137 | Invalid image operation.              |

**Example**

```ts
import image from '@ohos.multimedia.image'
import resourceManager from '@ohos.resourceManager'
import { BusinessError } from '@kit.BasicServicesKit';

// 'hdr.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let img = await getContext(this).resourceManager.getMediaContent($r('app.media.hdr'));
let imageSource = image.createImageSource(img.buffer.slice(0));
let decodingOptions: image.DecodingOptions = {
  desiredDynamicRange: image.DecodingDynamicRange.AUTO
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
  try {
    await pixelmap.toSdr();
    let imageInfo = pixelmap.getImageInfoSync();
    console.info("after toSdr ,imageInfo isHdr:" + imageInfo.isHdr);
  } catch (e) {
    console.info('toSdr failed' + e);
  }
} else {
  console.info('Failed to create pixelMap.');
}
```

### getMetadata<sup>12+</sup>

getMetadata(key: HdrMetadataKey): HdrMetadataValue

Obtains the value of the metadata with a given key in this pixel map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](#hdrmetadatakey12) | Yes  | Key of the HDR metadata.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| [HdrMetadataValue](#hdrmetadatavalue12) | Value of the metadata with the given key.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401| Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980173 | Memory copy failed.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import image from '@ohos.multimedia.image'

// Replace 'app.media.test' with a local HDR image.
let img = await getContext(this).resourceManager.getMediaContent($r('app.media.test'));
let imageSource = image.createImageSource(img.buffer.slice(0));
let decodingOptions: image.DecodingOptions = {
  desiredDynamicRange: image.DecodingDynamicRange.AUTO
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
  try {
    let staticMetadata = pixelmap.getMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA);
    console.info("getmetadata:" + JSON.stringify(staticMetadata));
  } catch (e) {
    console.info('pixelmap create failed' + e);
  }
} else {
  console.info('Failed to create pixelMap.');
}
```

### setMetadata<sup>12+</sup>

setMetadata(key: HdrMetadataKey, value: HdrMetadataValue): Promise\<void>

Sets the value for the metadata with a given key in this pixel map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](#hdrmetadatakey12) | Yes  | Key of the HDR metadata.|
| value | [HdrMetadataValue](#hdrmetadatavalue12) | Yes  | Value of the metadata.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401|  Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980173 | Memory copy failed.          |

**Example**

```ts
import image from '@ohos.multimedia.image'
import { BusinessError } from '@kit.BasicServicesKit';
@State pixelmap: image.PixelMap | undefined = undefined;

async Demo() {
  let staticMetadata: image.HdrStaticMetadata = {
    displayPrimariesX: [1.1, 1.1, 1.1],
    displayPrimariesY: [1.2, 1.2, 1.2],
    whitePointX: 1.1,
    whitePointY: 1.2,
    maxLuminance: 2.1,
    minLuminance: 1.0,
    maxContentLightLevel: 2.1,
    maxFrameAverageLightLevel: 2.1,
  }
  this.pixelmap?.setMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA, staticMetadata);
}
```

### setTransferDetached<sup>12+<sup>

setTransferDetached(detached: boolean): void

Sets whether to detach from the original thread when this pixel map is transmitted across threads. This API applies to the scenario where the pixel map needs to be released immediately.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type              | Mandatory| Description                         |
| ------- | ------------------ | ---- | ----------------------------- |
| detached | boolean   | Yes  | Whether to detach from the original thread.                 |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.setTransferDetached(true);
  }
}
```

### marshalling<sup>10+</sup>

marshalling(sequence: rpc.MessageSequence): void

Marshals this **PixelMap** object and writes it to a **MessageSequence** object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)  | Yes  | **MessageSequence** object.                |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error.             |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixel_map: image.PixelMap;
  constructor(conPixelMap : image.PixelMap) {
    this.pixel_map = conPixelMap;
  }
  marshalling(messageSequence : rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    console.info('marshalling');
    return true;
  }
  unmarshalling(messageSequence : rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel: image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: image.PixelMap) => {
        this.pixel_map = pixelMap;
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
          console.info("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
        })
      })
    });
    return true;
  }
}
async function Demo() {
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
  let pixelMap: image.PixelMap | undefined = undefined;
  image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
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

### unmarshalling<sup>10+</sup>

unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>

Unmarshals a **MessageSequence** object to obtain a **PixelMap** object.
To create a **PixelMap** object in synchronous mode, use [createPixelMapFromParcel](#imagecreatepixelmapfromparcel11).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | **MessageSequence** object that stores the **PixelMap** information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> |Promise used to return the **PixelMap** object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error.              |
| 62980096 | The operation failed.         |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixel_map: image.PixelMap;
  constructor(conPixelMap: image.PixelMap) {
    this.pixel_map = conPixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    console.info('marshalling');
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel : image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap : image.PixelMap) => {
        this.pixel_map = pixelMap;
        pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
          console.info("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
        })
      })
    });
    return true;
  }
}
async function Demo() {
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
  let pixelMap: image.PixelMap | undefined = undefined;
  image.createPixelMap(color, opts).then((srcPixelMap : image.PixelMap) => {
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

### release<sup>7+</sup>

release():Promise\<void>

Releases this **PixelMap** object. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **PixelMap** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the **PixelMap** object is no longer required.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.release().then(() => {
      console.info('Succeeded in releasing pixelmap object.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to release pixelmap object. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### release<sup>7+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **PixelMap** object. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **PixelMap** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the **PixelMap** object is no longer required.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.release((err: BusinessError) => {
      if (err) {
        console.error(`Failed to release pixelmap object. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info('Succeeded in releasing pixelmap object.');
      }
    })
  }
}
```

## image.createImageSource

createImageSource(uri: string): ImageSource

Creates an **ImageSource** instance based on a given URI.


**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | Yes  | Image path. Currently, only the application sandbox path is supported.<br>The following formats are supported: .jpg, .png, .gif, .bmp, .webp, .dng, [.svg<sup>10+</sup>](#svg-tags), and .ico<sup>11+</sup>.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
const context: Context = getContext(this);
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
```

## image.createImageSource<sup>9+</sup>

createImageSource(uri: string, options: SourceOptions): ImageSource

Creates an **ImageSource** instance based on a given URI.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                               |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| uri     | string                          | Yes  | Image path. Currently, only the application sandbox path is supported.<br>Currently, the following formats are supported: .jpg, .png, .gif, .bmp, .webp, .dng, [.svg<sup>10+</sup>](#svg-tags), and .ico<sup>11+</sup>.|
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
const context: Context = getContext(this);
// 'test.png' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.png";
let imageSourceApi: image.ImageSource = image.createImageSource(path, sourceOptions);
```

## image.createImageSource<sup>7+</sup>

createImageSource(fd: number): ImageSource

Creates an **ImageSource** instance based on a given file descriptor.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description         |
| ------ | ------ | ---- | ------------- |
| fd     | number | Yes  | File descriptor.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';

const context: Context = getContext(this);
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
const imageSourceApi: image.ImageSource = image.createImageSource(file.fd);
```

## image.createImageSource<sup>9+</sup>

createImageSource(fd: number, options: SourceOptions): ImageSource

Creates an **ImageSource** instance based on a given file descriptor.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                               |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| fd      | number                          | Yes  | File descriptor.                     |
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';

let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
const context: Context = getContext();
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const filePath: string = context.filesDir + "/test.jpg";
let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
const imageSourceApi: image.ImageSource = image.createImageSource(file.fd, sourceOptions);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer): ImageSource

Creates an **ImageSource** instance based on buffers.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type       | Mandatory| Description            |
| ------ | ----------- | ---- | ---------------- |
| buf    | ArrayBuffer | Yes  | Array of image buffers.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|


**Example**

```ts
const buf: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
const imageSourceApi: image.ImageSource = image.createImageSource(buf);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource

Creates an **ImageSource** instance based on buffers.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type                            | Mandatory| Description                                |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| buf    | ArrayBuffer                      | Yes  | Array of image buffers.                    |
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
const data: ArrayBuffer = new ArrayBuffer(112);
let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
const imageSourceApi: image.ImageSource = image.createImageSource(data, sourceOptions);
```

## image.createImageSource<sup>11+</sup>

createImageSource(rawfile: resourceManager.RawFileDescriptor, options?: SourceOptions): ImageSource

Creates an **ImageSource** instance based on the raw file descriptor of an image resource file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type                            | Mandatory| Description                                |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| rawfile | [resourceManager.RawFileDescriptor](../apis-localization-kit/js-apis-resource-manager.md#rawfiledescriptor8) | Yes| Raw file descriptor of the image resource file.|
| options | [SourceOptions](#sourceoptions9) | No| Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
import { resourceManager } from '@kit.LocalizationKit';

const context: Context = getContext(this);
// Obtain a resource manager.
const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor: resourceManager.RawFileDescriptor) => {
  const imageSourceApi: image.ImageSource = image.createImageSource(rawFileDescriptor);
}).catch((error: BusinessError) => {
  console.error(`Failed to get RawFileDescriptor.code is ${error.code}, message is ${error.message}`);
})
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer): ImageSource

Creates an **ImageSource** instance in incremental mode based on buffers. Such an instance does not support reading or writing of EXIF information.

The **ImageSource** instance created in incremental mode supports the following capabilities (applicable to synchronous, callback, and promise modes):
- Obtaining image information: Call [getImageInfo](#getimageinfo) to obtain image information by index, or call [getImageInfo](#getimageinfo-1) to directly obtain image information.
- Obtaining an image property: Call [getImageProperty](#getimageproperty11) to obtain the value of a property with the specified index in an image.
- Obtaining image properties: Call [getImageProperties](#getimageproperties12) to obtain the values of properties with the given names in an image.
- Updating incremental data: Call [updateData](#updatedata9) to update data.
- Creating a **PixelMap** object: Call [createPixelMap](#createpixelmap7) or [createPixelMap](#createpixelmap7-2) to create a pixel map based on image decoding parameters, or call [createPixelMap](#createpixelmap7-1) to create a pixel map based on default parameters.
- Releasing an **ImageSource** instance: Call [release](#release) to release an image source.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type       | Mandatory| Description     |
| ------- | ------------| ---- | ----------|
| buf     | ArrayBuffer | Yes  | Incremental data.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns undefined otherwise.|

**Example**

```ts
const context: Context = getContext(this)
let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon')) // Obtain the image resource.
// 'app.media.startIcon' is only an example. Replace it with the actual one in use. Otherwise, the imageArray instance fails to be created, and subsequent operations cannot be performed.
let splitBuff1 = imageArray.slice(0, imageArray.byteLength / 2) // Image slice.
let splitBuff2 = imageArray.slice(imageArray.byteLength / 2)
const imageSourceIncrementalSApi: image.ImageSource = image.CreateIncrementalSource(new ArrayBuffer(imageArray.byteLength));
imageSourceIncrementalSApi.updateData(splitBuff1, false, 0, splitBuff1.byteLength).then(() => {
  imageSourceIncrementalSApi.updateData(splitBuff2, true, 0, splitBuff2.byteLength).then(() => {
    let pixelMap = imageSourceIncrementalSApi.createPixelMapSync()
    let imageInfo = pixelMap.getImageInfoSync()
    console.info('Succeeded in creating pixelMap')
  }).catch((error : BusinessError) => {
    console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`)
  })
}).catch((error : BusinessError) => {
  console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`)
})
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource

Creates an **ImageSource** instance in incremental mode based on buffers. Such an instance does not support reading or writing of EXIF information.

The capabilities supported by the **ImageSource** instance created by this API are the same as those supported by the instance created by [CreateIncrementalSource(buf: ArrayBuffer): ImageSource](#imagecreateincrementalsource9).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                                |
| ------- | ------------------------------- | ---- | ------------------------------------ |
| buf     | ArrayBuffer                     | Yes  | Incremental data.                          |
| options | [SourceOptions](#sourceoptions9) | No  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns undefined otherwise.|

**Example**

```ts
const context: Context = getContext(this)
let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon')) // Obtain the image resource.
// 'app.media.startIcon' is only an example. Replace it with the actual one in use. Otherwise, the imageArray instance fails to be created, and subsequent operations cannot be performed.
let splitBuff1 = imageArray.slice(0, imageArray.byteLength / 2) // Image slice.
let splitBuff2 = imageArray.slice(imageArray.byteLength / 2)
let sourceOptions: image.SourceOptions = { sourceDensity: 120};

const imageSourceIncrementalSApi: image.ImageSource = image.CreateIncrementalSource(new ArrayBuffer(imageArray.byteLength), sourceOptions);
imageSourceIncrementalSApi.updateData(splitBuff1, false, 0, splitBuff1.byteLength).then(() => {
  imageSourceIncrementalSApi.updateData(splitBuff2, true, 0, splitBuff2.byteLength).then(() => {
    let pixelMap = imageSourceIncrementalSApi.createPixelMapSync()
    let imageInfo = pixelMap.getImageInfoSync()
    console.info('Succeeded in creating pixelMap')
  }).catch((error : BusinessError) => {
    console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`)
  })
}).catch((error : BusinessError) => {
  console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`)
})
```

## ImageSource

Provides APIs to obtain image information. Before calling any API in **ImageSource**, you must use [createImageSource](#imagecreateimagesource) to create an **ImageSource** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name            | Type          | Readable| Writable| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats, including PNG, JPEG, BMP, GIF, WebP, and DNG.|

### getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

Obtains information about an image with the specified index. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | Yes  | Index of the image.                    |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the image information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageInfo(0, (error: BusinessError, imageInfo: image.ImageInfo) => {
  if (error) {
    console.error(`Failed to obtain the image information.code is ${error.code}, message is ${error.message}`);
  } else {
    console.info('Succeeded in obtaining the image information.');
  }
})
```

### getImageInfo

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains information about this image. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the image information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageInfo((err: BusinessError, imageInfo: image.ImageInfo) => {
  if (err) {
    console.error(`Failed to obtain the image information.code is ${err.code}, message is ${err.message}`);
  } else {
    console.info('Succeeded in obtaining the image information.');
  }
})
```

### getImageInfo

getImageInfo(index?: number): Promise\<ImageInfo>

Obtains information about an image with the specified index. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | No  | Index of the image. If this parameter is not set, the default value **0** is used.|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](#imageinfo)> | Promise used to return the image information obtained.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageInfo(0)
  .then((imageInfo: image.ImageInfo) => {
    console.info('Succeeded in obtaining the image information.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to obtain the image information.code is ${error.code}, message is ${error.message}`);
  })
```

### getImageInfoSync<sup>12+</sup>

getImageInfoSync(index?: number): ImageInfo

Obtains information about an image with the specified index. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | No  | Index of the image. If this parameter is not set, the default value **0** is used.|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| [ImageInfo](#imageinfo) | Image information.|

**Example**

```ts
import { image } from '@kit.ImageKit';

const context: Context = getContext(this);
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let imageInfo = imageSource.getImageInfoSync(0);
if (imageInfo == undefined) {
  console.error('Failed to obtain the image information.');
} else {
  console.info('Succeeded in obtaining the image information.');
  console.info('imageInfo.size.height:' + imageInfo.size.height);
  console.info('imageInfo.size.width:' + imageInfo.size.width);
}
```

### getImageProperty<sup>11+</sup>

getImageProperty(key:PropertyKey, options?: ImagePropertyOptions): Promise\<string>

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result. The image must be in JPEG or PNG format and contain EXIF information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | [PropertyKey](#propertykey7)                                               | Yes  | Name of the property.                        |
| options | [ImagePropertyOptions](#imagepropertyoptions11) | No  | Image properties, including the image index and default property value.|

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise used to return the property value. If the operation fails, the default value is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;              |
| 62980096 | The operation failed.             |
| 62980103 | The image data is not supported.         |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.       |
| 62980113 | Unknown image format.        |
| 62980115 | Invalid image parameter.      |
| 62980116| Failed to decode the image.            |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.   |
| 62980123| Images in EXIF format are not supported.             |
| 62980135| The EXIF value is invalid.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: image.ImagePropertyOptions = { index: 0, defaultValue: '9999' }
imageSourceApi.getImageProperty(image.PropertyKey.BITS_PER_SAMPLE, options)
.then((data: string) => {
  console.info('Succeeded in getting the value of the specified attribute key of the image.');
}).catch((error: BusinessError) => {
  console.error('Failed to get the value of the specified attribute key of the image.');
})
```

### getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result. The image must be in JPEG or PNG format and contain EXIF information.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [getImageProperty](#getimageproperty11).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                               | Yes  | Name of the property.                        |
| options | [GetImagePropertyOptions](#getimagepropertyoptionsdeprecated) | No  | Image properties, including the image index and default property value.|

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise used to return the property value. If the operation fails, the default value is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageProperty("BitsPerSample")
  .then((data: string) => {
    console.info('Succeeded in getting the value of the specified attribute key of the image.');
  }).catch((error: BusinessError) => {
    console.error('Failed to get the value of the specified attribute key of the image.');
  })
```

### getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

Obtains the value of a property with the specified index in this image. This API uses an asynchronous callback to return the result. The image must be in JPEG or PNG format and contain EXIF information.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [getImageProperty](#getimageproperty11).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | Yes  | Name of the property.                                                |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the property value obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageProperty("BitsPerSample", (error: BusinessError, data: string) => {
  if (error) {
    console.error('Failed to get the value of the specified attribute key of the image.');
  } else {
    console.info('Succeeded in getting the value of the specified attribute key of the image.');
  }
})
```

### getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

Obtains the value of a property in this image. This API uses an asynchronous callback to return the result. The image must be in JPEG or PNG format and contain EXIF information.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [getImageProperty](#getimageproperty11).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                         |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------- |
| key      | string                                               | Yes  | Name of the property.                                                 |
| options  | [GetImagePropertyOptions](#getimagepropertyoptionsdeprecated) | Yes  | Image properties, including the image index and default property value.                         |
| callback | AsyncCallback\<string>                               | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the property value obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let property: image.GetImagePropertyOptions = { index: 0, defaultValue: '9999' }
imageSourceApi.getImageProperty("BitsPerSample", property, (error: BusinessError, data: string) => {
  if (error) {
    console.error('Failed to get the value of the specified attribute key of the image.');
  } else {
    console.info('Succeeded in getting the value of the specified attribute key of the image.');
  }
})
```

### getImageProperties<sup>12+</sup>

getImageProperties(key: Array&#60;PropertyKey&#62;): Promise<Record<PropertyKey, string|null>>

Obtains the values of properties with the given names in this image. This API uses a promise to return the result. The image must be in JPEG or PNG format and contain EXIF information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | Array\<[PropertyKey](#propertykey7)>                                 | Yes  | Array of properties names.                        |

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<Record<[PropertyKey](#propertykey7), string \| null>> | Promise used to return the property values. If the operation fails, **null** is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;     |
| 62980096| The operation failed.             |
| 62980110| The image source data is incorrect.            |
| 62980113| Unknown image format.            |
| 62980116| Failed to decode the image.            |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let key = [image.PropertyKey.IMAGE_WIDTH, image.PropertyKey.IMAGE_LENGTH];
imageSourceApi.getImageProperties(key).then((data) => {
  console.info(JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

### modifyImageProperty<sup>11+</sup>

modifyImageProperty(key: PropertyKey, value: string): Promise\<void>

Modifies the value of a property in this image. This API uses a promise to return the result. The image must be in JPEG or PNG format and contain EXIF information.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an **ImageSource** instance created based on a file descriptor or path, but not an **ImageSource** instance created based on buffers.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| key     | [PropertyKey](#propertykey7)   | Yes  | Name of the property.|
| value   | string | Yes  | New value of the property.    |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;    |
| 62980123| Images in EXIF format are not supported.             |
| 62980133| The EXIF data is out of range.             |
| 62980135| The EXIF value is invalid.             |
| 62980146| The EXIF data failed to be written to the file.        |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.modifyImageProperty(image.PropertyKey.IMAGE_WIDTH, "120").then(() => {
  imageSourceApi.getImageProperty(image.PropertyKey.IMAGE_WIDTH).then((width: string) => {
    console.info(`ImageWidth is :${width}`);
  }).catch((error: BusinessError) => {
    console.error('Failed to get the Image Width.');
  })
}).catch((error: BusinessError) => {
  console.error('Failed to modify the Image Width');
})
```

### modifyImageProperty<sup>(deprecated)</sup>

modifyImageProperty(key: string, value: string): Promise\<void>

Modifies the value of a property in this image. This API uses a promise to return the result. The image must be in JPEG or PNG format and contain EXIF information.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an **ImageSource** instance created based on a file descriptor or path, but not an **ImageSource** instance created based on buffers.
>
> This API is deprecated since API version 11. You are advised to use [modifyImageProperty](#modifyimageproperty11).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| key     | string | Yes  | Name of the property.|
| value   | string | Yes  | New value of the property.    |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.modifyImageProperty("ImageWidth", "120").then(() => {
  imageSourceApi.getImageProperty("ImageWidth").then((width: string) => {
    console.info(`ImageWidth is :${width}`);
  }).catch((error: BusinessError) => {
    console.error('Failed to get the Image Width.');
  })
}).catch((error: BusinessError) => {
  console.error('Failed to modify the Image Width');
})
```

### modifyImageProperty<sup>(deprecated)</sup>

modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void

Modifies the value of a property in this image. This API uses an asynchronous callback to return the result. The image must be in JPEG or PNG format and contain EXIF information.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an **ImageSource** instance created based on a file descriptor or path, but not an **ImageSource** instance created based on buffers.
> 
>This API is deprecated since API version 11. You are advised to use [modifyImageProperty](#modifyimageproperty11).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type               | Mandatory| Description                          |
| -------- | ------------------- | ---- | ------------------------------ |
| key      | string              | Yes  | Name of the property.                  |
| value    | string              | Yes  | New value of the property.                      |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.modifyImageProperty("ImageWidth", "120", (err: BusinessError) => {
  if (err) {
    console.error(`Failed to modify the Image Width.code is ${err.code}, message is ${err.message}`);
  } else {
    console.info('Succeeded in modifying the Image Width.');
  }
})
```

### modifyImageProperties<sup>12+</sup>

modifyImageProperties(records: Record<PropertyKey, string|null>): Promise\<void>

Modifies the values of properties in this image. This API uses a promise to return the result. The image must be in JPEG or PNG format and contain EXIF information.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperties** API is called to modify the values of properties. Currently, you can call the API in an **ImageSource** instance created based on a file descriptor or path, but not an **ImageSource** instance created based on buffers.
>

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| records     | Record<[PropertyKey](#propertykey7), string \| null>   | Yes  | Array of property names and property values.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;      |
| 62980123| Images in EXIF format are not supported.             |
| 62980133| The EXIF data is out of range.             |
| 62980135| The EXIF value is invalid.             |
| 62980146| The EXIF data failed to be written to the file.             |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyValues: Record<PropertyKey, string|null> = {
    [image.PropertyKey.IMAGE_WIDTH] : "1024",
    [image.PropertyKey.IMAGE_LENGTH] : "1024"
};
let checkKey = [image.PropertyKey.IMAGE_WIDTH, image.PropertyKey.IMAGE_LENGTH];
imageSourceApi.modifyImageProperties(keyValues).then(() => {
  imageSourceApi.getImageProperties(checkKey).then((data) => {
    console.info(JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(JSON.stringify(err));
  });
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

### updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number): Promise\<void>

Updates incremental data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type       | Mandatory| Description        |
| ---------- | ----------- | ---- | ------------ |
| buf        | ArrayBuffer | Yes  | Incremental data.  |
| isFinished | boolean     | Yes  | Whether the update is complete.|
| offset      | number      | Yes  | Offset for data reading.    |
| length     | number      | Yes  | Array length.    |

**Return value**

| Type          | Description                      |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const array: ArrayBuffer = new ArrayBuffer(100);
imageSourceApi.updateData(array, false, 0, 10).then(() => {
  console.info('Succeeded in updating data.');
}).catch((err: BusinessError) => {
  console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
})
```


### updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number, callback: AsyncCallback\<void>): void

Updates incremental data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type               | Mandatory| Description                |
| ---------- | ------------------- | ---- | -------------------- |
| buf        | ArrayBuffer         | Yes  | Incremental data.          |
| isFinished | boolean             | Yes  | Whether the update is complete.        |
| offset      | number              | Yes  | Offset for data reading.            |
| length     | number              | Yes  | Array length.            |
| callback   | AsyncCallback\<void> | Yes  |  Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const array: ArrayBuffer = new ArrayBuffer(100);
imageSourceApi.updateData(array, false, 0, 10, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in updating data.');
  }
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

Creates a **PixelMap** object based on image decoding parameters. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                | Mandatory| Description      |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [DecodingOptions](#decodingoptions7) | No  | Image decoding parameters.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.createPixelMap().then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelMap object through image decoding parameters.');
}).catch((error: BusinessError) => {
  console.error('Failed to create pixelMap object through image decoding parameters.');
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on the default parameters. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the **PixelMap** object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.createPixelMap((err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in creating pixelMap object.');
  }
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on image decoding parameters. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | Yes  | Image decoding parameters.                |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the **PixelMap** object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decodingOptions: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 1, height: 2 },
  rotate: 10,
  desiredPixelFormat: 3,
  desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 },
  index: 0
};
imageSourceApi.createPixelMap(decodingOptions, (err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in creating pixelMap object.');
  }
})
```

### createPixelMapSync<sup>12+</sup>

createPixelMapSync(options?: DecodingOptions): PixelMap

Creates a **PixelMap** object based on image decoding parameters. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | No  | Image decoding parameters.                |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | **PixelMap** object.|

**Example**

```ts
import { image } from '@kit.ImageKit';

const context: Context = getContext(this);
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let decodingOptions: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 1, height: 2 },
  rotate: 10,
  desiredPixelFormat: 3,
  desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 },
  index: 0
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
} else {
  console.info('Failed to create pixelMap.');
}
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options?: DecodingOptions): Promise<Array\<PixelMap>>

Creates an array of **PixelMap** objects based on image decoding parameters. This API uses a promise to return the result. For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | No  | Image decoding parameters.                |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise<Array<[PixelMap](#pixelmap7)>> | Promise used to return an array of **PixelMap** objects.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed.              |
| 62980099 | The shared memory data is abnormal. |
| 62980101 | The image data is abnormal. |
| 62980103| The image data is not supported.             |
| 62980106 | The image is too large. |
| 62980109 | Failed to crop the image. |
| 62980110| The image source data is incorrect.             |
| 62980111| The image source data is incomplete.           |
| 62980112 | The image format does not match. |
| 62980113 | Unknown image format. |
| 62980115 | Invalid image parameter. |
| 62980116 | Failed to decode the image. |
| 62980118| Failed to create the image plugin.             |
| 62980122 | The image decoding header is abnormal. |
| 62980137 | Invalid media operation. |
| 62980173 | The DMA memory does not exist. |
| 62980174 | The DMA memory data is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decodeOpts: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 198, height: 202 },
  rotate: 0,
  desiredPixelFormat: 3,
  index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts).then((pixelMapList: Array<image.PixelMap>) => {
  console.info('Succeeded in creating pixelMapList object.');
}).catch((err: BusinessError) => {
  console.error(`Failed to create pixelMapList object.code is ${err.code},message is ${err.message}`);
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of **PixelMap** objects based on the default parameters. This API uses an asynchronous callback to return the result. For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the array of **PixelMap** objects obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed.             |
| 62980099 | The shared memory data is abnormal.  |
| 62980101 | The image data is abnormal.          |
| 62980103 | The image data is not supported.         |
| 62980106 | The image is too large.              |
| 62980109 | Failed to crop the image.            |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.       |
| 62980113 | Unknown image format.        |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.         |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | The image decoding header is abnormal.   |
| 62980137 | Invalid media operation.     |
| 62980173 | The DMA memory does not exist.        |
| 62980174 | The DMA memory data is abnormal.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.createPixelMapList((err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
  if (err) {
    console.error(`Failed to create pixelMapList object.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in creating pixelMapList object.');
  }
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options: DecodingOptions, callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of **PixelMap** objects based on image decoding parameters. This API uses an asynchronous callback to return the result. For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| options | [DecodingOptions](#decodingoptions7) | Yes| Image decoding parameters.|
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the array of **PixelMap** objects obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed.            |
| 62980099 | The shared memory data is abnormal.  |
| 62980101 | The image data is abnormal.         |
| 62980103 | The image data is not supported.        |
| 62980106 | The image is too large.              |
| 62980109 | Failed to crop the image.           |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113 | Unknown image format.         |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.         |
| 62980118 | Failed to create the image plugin.  |
| 62980122 | The image decoding header is abnormal.   |
| 62980137 | Invalid media operation.      |
| 62980173 | The DMA memory does not exist.         |
| 62980174 | The DMA memory data is abnormal.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decodeOpts: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 198, height: 202 },
  rotate: 0,
  desiredPixelFormat: 3,
  index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts, (err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
  if (err) {
    console.error(`Failed to create pixelMapList object.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in creating pixelMapList object.');
  }
})
```

### getDelayTimeList<sup>10+</sup>

getDelayTimeList(callback: AsyncCallback<Array\<number>>): void

Obtains an array of delay times. This API uses an asynchronous callback to return the result. This API applies only to images in GIF or WebP format.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback<Array\<number>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the array of delay times obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed.              |
| 62980110| The image source data is incorrect.             |
| 62980111| The image source data is incomplete.            |
| 62980112 | The image format does not match. |
| 62980113| Unknown image format. |
| 62980115 | Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| The image decoding header is abnormal. |
| 62980137 | Invalid media operation. |
| 62980149 | Invalid media parameter. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getDelayTimeList((err: BusinessError, delayTimes: Array<number>) => {
  if (err) {
    console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting delayTimes object.');
  }
})
```

### getDelayTimeList<sup>10+</sup>

getDelayTimeList(): Promise<Array\<number>>

Obtains an array of delay times. This API uses a promise to return the result. This API applies only to images in GIF or WebP format.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<Array\<number>> | Promise used to return an array of delay times.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed.             |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113 | Unknown image format.         |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.  |
| 62980122 | The image decoding header is abnormal.   |
| 62980137 | Invalid media operation.      |
| 62980149 | Invalid media parameter.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getDelayTimeList().then((delayTimes: Array<number>) => {
  console.info('Succeeded in getting delayTimes object.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
})
```

### getFrameCount<sup>10+</sup>

getFrameCount(callback: AsyncCallback\<number>): void

Obtains the number of frames. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of frames obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed.              |
| 62980110| The image source data is incorrect. |
| 62980111| The image source data is incomplete. |
| 62980112| The image format does not match. |
| 62980113| Unknown image format. |
| 62980115| Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| The image decoding header is abnormal. |
| 62980137| Invalid media operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getFrameCount((err: BusinessError, frameCount: number) => {
  if (err) {
    console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting frame count.');
  }
})
```

### getFrameCount<sup>10+</sup>

getFrameCount(): Promise\<number>

Obtains the number of frames. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<number> | Promise used to return the number of frames.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed.             |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113 | Unknown image format.         |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | The image decoding header is abnormal.  |
| 62980137 | Invalid media operation.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getFrameCount().then((frameCount: number) => {
  console.info('Succeeded in getting frame count.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
})
```

### getDisposalTypeList<sup>12+</sup>

getDisposalTypeList(): Promise\<Array\<number>>

Obtains the list of disposal types. This API uses a promise to return the result. It is used only for GIF images.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<Array\<number>> | Promise used to return an array of disposal types.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed.      |
| 62980101 | The image data is abnormal. |
| 62980137 | Invalid media operation.        |
| 62980149 | Invalid image source mime type.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
imageSourceApi.getDisposalTypeList().then((disposalTypes: Array<number>) => {
  console.info('Succeeded in getting disposalTypes object.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get disposalTypes object.code ${err.code},message is ${err.message}`);
})
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImageSource** instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImageSource** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release the image source instance.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing the image source instance.');
  }
})
```

### release

release(): Promise\<void>

Releases this **ImageSource** instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImageSource** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.release().then(() => {
  console.info('Succeeded in releasing the image source instance.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release the image source instance.code ${error.code},message is ${error.message}`);
})
```

## image.createImagePacker

createImagePacker(): ImagePacker

Creates an **ImagePacker** instance.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type                       | Description                 |
| --------------------------- | --------------------- |
| [ImagePacker](#imagepacker) | **ImagePacker** instance created.|

**Example**

```ts
const imagePackerApi: image.ImagePacker = image.createImagePacker();
```

## ImagePacker

Provides APIs to pack images. Before calling any API in **ImagePacker**, you must use [createImagePacker](#imagecreateimagepacker) to create an **ImagePacker** instance. The image formats JPEG, WebP, and PNG are supported.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name            | Type          | Readable| Writable| Description                      |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats, which can be JPEG, WebP, and PNG.|

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                              | Mandatory| Description                              |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)        | Yes  | Image to pack.                    |
| option   | [PackingOption](#packingoption)    | Yes  | Option for image packing.                     |
| callback | AsyncCallback\<ArrayBuffer>        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the packed image data; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const context: Context = getContext();
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
imagePackerApi.packing(imageSourceApi, packOpts, (err: BusinessError, data: ArrayBuffer) => {
  if (err) {
    console.error(`Failed to pack the image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in packing the image.');
  }
})
```

### packing

packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>

Packs an image. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | Yes  | Image to pack.|
| option | [PackingOption](#packingoption) | Yes  | Option for image packing.|

**Return value**

| Type                        | Description                                         |
| ---------------------------- | --------------------------------------------- |
| Promise\<ArrayBuffer>        | Promise used to return the packed image data.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const context: Context = getContext();
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
imagePackerApi.packing(imageSourceApi, packOpts)
  .then((data: ArrayBuffer) => {
    console.info('Succeeded in packing the image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                              |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [PixelMap](#pixelmap7)           | Yes  | **PixelMap** object to pack.              |
| option   | [PackingOption](#packingoption) | Yes  | Option for image packing.                    |
| callback | AsyncCallback\<ArrayBuffer>     | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the packed image data; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  imagePackerApi.packing(pixelMap, packOpts, (err: BusinessError, data: ArrayBuffer) => {
    if (err) {
      console.error(`Failed to pack the image.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in packing the image.');
    }
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create the PixelMap.code ${error.code},message is ${error.message}`);
})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>

Packs an image. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description              |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](#pixelmap7)           | Yes  | **PixelMap** object to pack.|
| option | [PackingOption](#packingoption) | Yes  | Option for image packing.    |

**Return value**

| Type                 | Description                                        |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the packed image data.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  imagePackerApi.packing(pixelMap, packOpts)
    .then((data: ArrayBuffer) => {
      console.info('Succeeded in packing the image.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create PixelMap.code ${error.code},message is ${error.message}`);
})
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImagePacker** instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImagePacker** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imagePackerApi.release((err: BusinessError)=>{
  if (err) {
    console.error(`Failed to release image packaging.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing image packaging.');
  }
})
```

### release

release(): Promise\<void>

Releases this **ImagePacker** instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImagePacker** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type          | Description                                                  |
| -------------- | ------------------------------------------------------ |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imagePackerApi.release().then(() => {
  console.info('Succeeded in releasing image packaging.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release image packaging.code ${error.code},message is ${error.message}`);
})
```

### packToFile<sup>11+</sup>

packToFile(source: ImageSource, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void

Encodes an **ImageSource** instance and packs it into a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                          |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [ImageSource](#imagesource)     | Yes  | Image to pack.                |
| fd       | number                          | Yes  | File descriptor.                  |
| options   | [PackingOption](#packingoption) | Yes  | Option for image packing.                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

const context: Context = getContext(this);
// 'test.png' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.png";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath: string = context.filesDir + "/image_source.jpg";
let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packToFile(imageSourceApi, file.fd, packOpts, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to pack the image to file.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in packing the image to file.');
  }
})
```

### packToFile<sup>11+</sup>

packToFile (source: ImageSource, fd: number, options: PackingOption): Promise\<void>

Encodes an **ImageSource** instance and packs it into a file. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | Yes  | Image to pack.|
| fd     | number                          | Yes  | File descriptor.  |
| options | [PackingOption](#packingoption) | Yes  | Option for image packing.|

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

const context: Context = getContext(this);
// 'test.png' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.png";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath: string = context.filesDir + "/image_source.jpg";
let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packToFile(imageSourceApi, file.fd, packOpts).then(() => {
  console.info('Succeeded in packing the image to file.');
}).catch((error: BusinessError) => { 
  console.error(`Failed to pack the image to file.code ${error.code},message is ${error.message}`);
}) 
```

### packToFile<sup>11+</sup>

packToFile (source: PixelMap, fd: number, options: PackingOption,  callback: AsyncCallback\<void>): void;

Encodes a **PixelMap** instance and packs it into a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                          |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [PixelMap](#pixelmap7)          | Yes  | **PixelMap** object to pack.          |
| fd       | number                          | Yes  | File descriptor.                  |
| options   | [PackingOption](#packingoption) | Yes  | Option for image packing.                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
const context: Context = getContext(this);
const path: string = context.filesDir + "/pixel_map.jpg";
image.createPixelMap(color, opts).then((pixelmap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  let file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packToFile(pixelmap, file.fd, packOpts, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to pack the image to file.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in packing the image to file.');
    }
  })
})
```

### packToFile<sup>11+</sup>

packToFile (source: PixelMap, fd: number, options: PackingOption): Promise\<void>

Encodes a **PixelMap** instance and packs it into a file. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description                |
| ------ | ------------------------------- | ---- | -------------------- |
| source | [PixelMap](#pixelmap7)          | Yes  | **PixelMap** object to pack.|
| fd     | number                          | Yes  | File descriptor.        |
| options | [PackingOption](#packingoption) | Yes  | Option for image packing.      |

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
const context: Context = getContext(this);
const path: string = context.filesDir + "/pixel_map.jpg";
image.createPixelMap(color, opts).then((pixelmap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  let file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packToFile(pixelmap, file.fd, packOpts)
    .then(() => {
      console.info('Succeeded in packing the image to file.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image to file.code ${error.code},message is ${error.message}`);
  })
})
```

## image.createImageReceiver<sup>11+</sup>

createImageReceiver(size: Size, format: ImageFormat, capacity: number): ImageReceiver

Creates an **ImageReceiver** instance by specifying the image size, format, and capacity.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| size    | [Size](#size)  | Yes  | Default size of the image.      |
| format   | [ImageFormat](#imageformat9) | Yes  | Image format, which is a constant of [ImageFormat](#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.)            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver9) | Returns an **ImageReceiver** instance if the operation is successful.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401| Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;   |

**Example**

```ts
let size: image.Size = {
  height: 8192,
  width: 8
}
let receiver: image.ImageReceiver = image.createImageReceiver(size, image.ImageFormat.JPEG, 8);
```

## image.createImageReceiver<sup>(deprecated)</sup>

createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver

Creates an **ImageReceiver** instance by specifying the image width, height, format, and capacity.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [createImageReceiver](#imagecreateimagereceiver11).

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| width    | number | Yes  | Default image width.      |
| height   | number | Yes  | Default image height.      |
| format   | number | Yes  | Image format, which is a constant of [ImageFormat](#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.) |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver9) | Returns an **ImageReceiver** instance if the operation is successful.|

**Example**

```ts
let receiver: image.ImageReceiver = image.createImageReceiver(8192, 8, image.ImageFormat.JPEG, 8);
```

## ImageReceiver<sup>9+</sup>

Provides APIs to obtain the surface ID of a component, read the latest image, read the next image, and release the **ImageReceiver** instance.

Before calling any APIs in **ImageReceiver**, you must create an **ImageReceiver** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name    | Type                        | Readable| Writable| Description              |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| size     | [Size](#size)                | Yes  | No  | Image size.        |
| capacity | number                       | Yes  | No  | Maximum number of images that can be accessed at the same time.|
| format   | [ImageFormat](#imageformat9) | Yes  | No  | Image format.        |

### getReceivingSurfaceId<sup>9+</sup>

getReceivingSurfaceId(callback: AsyncCallback\<string>): void

Obtains a surface ID for the camera or other components. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                  | Mandatory| Description                      |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the surface ID obtained. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.getReceivingSurfaceId((err: BusinessError, id: string) => {
  if (err) {
    console.error(`Failed to get the ReceivingSurfaceId.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting the ReceivingSurfaceId.');
  }
});
```

### getReceivingSurfaceId<sup>9+</sup>

getReceivingSurfaceId(): Promise\<string>

Obtains a surface ID for the camera or other components. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<string> | Promise used to return the surface ID.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.getReceivingSurfaceId().then((id: string) => { 
  console.info('Succeeded in getting the ReceivingSurfaceId.');
}).catch((error: BusinessError) => {
  console.error(`Failed to get the ReceivingSurfaceId.code ${error.code},message is ${error.message}`);
})
```

### readLatestImage<sup>9+</sup>

readLatestImage(callback: AsyncCallback\<Image>): void

Reads the latest image from the **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

**NOTE**: When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<[Image](#image9)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the latest image obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readLatestImage((err: BusinessError, img: image.Image) => {
  if (err) {
    console.error(`Failed to read the latest Image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in reading the latest Image.');
  }
});
```

### readLatestImage<sup>9+</sup>

readLatestImage(): Promise\<Image>

Reads the latest image from the **ImageReceiver** instance. This API uses a promise to return the result.

**NOTE**: When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description              |
| ------------------------- | ------------------ |
| Promise<[Image](#image9)> | Promise used to return the latest image.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readLatestImage().then((img: image.Image) => {
  console.info('Succeeded in reading the latest Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to read the latest Image.code ${error.code},message is ${error.message}`);
})
```

### readNextImage<sup>9+</sup>

readNextImage(callback: AsyncCallback\<Image>): void

Reads the next image from the **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

**NOTE**: When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                           | Mandatory| Description                      |
| -------- | ------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[Image](#image9)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the next image obtained. Otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readNextImage((err: BusinessError, img: image.Image) => {
  if (err) {
    console.error(`Failed to read the next Image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in reading the next Image.');
  }
});
```

### readNextImage<sup>9+</sup>

readNextImage(): Promise\<Image>

Reads the next image from the **ImageReceiver** instance. This API uses a promise to return the result.

**NOTE**: When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description                |
| ------------------------- | -------------------- |
| Promise<[Image](#image9)> | Promise used to return the next image.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readNextImage().then((img: image.Image) => {
  console.info('Succeeded in reading the next Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to read the next Image.code ${error.code},message is ${error.message}`);
})
```

### on<sup>9+</sup>

on(type: 'imageArrival', callback: AsyncCallback\<void>): void

Listens for image arrival events.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                | Mandatory| Description                                                  |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **'imageArrival'**, which is triggered when an image is received.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                                       |

**Example**

```ts
receiver.on('imageArrival', () => {
  // image arrival, do something.
})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImageReceiver** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release the receiver.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing the receiver.');
  }
})
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases this **ImageReceiver** instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImageReceiver** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type          | Description              |
| -------------- | ------------------ |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.release().then(() => {
  console.info('Succeeded in releasing the receiver.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release the receiver.code ${error.code},message is ${error.message}`);
})
```

## image.createImageCreator<sup>11+</sup>

createImageCreator(size: Size, format: ImageFormat, capacity: number): ImageCreator

Creates an **ImageCreator** instance by specifying the image size, format, and capacity.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| size    | [Size](#size)  | Yes  | Default size of the image.      |
| format   | [ImageFormat](#imageformat9) | Yes  | Image format, for example, YCBCR_422_SP or JPEG.            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                          | Description                                   |
| ------------------------------ | --------------------------------------- |
| [ImageCreator](#imagecreator9) | Returns an **ImageCreator** instance if the operation is successful.|


**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401| Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;          |

**Example**

```ts
let size: image.Size = {
  height: 8192,
  width: 8
}
let creator: image.ImageCreator = image.createImageCreator(size, image.ImageFormat.JPEG, 8);
```

## image.createImageCreator<sup>(deprecated)</sup>

createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator

Creates an **ImageCreator** instance by specifying the image width, height, format, and capacity.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [createImageCreator](#imagecreateimagecreator11).

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| width    | number | Yes  | Default image width.      |
| height   | number | Yes  | Default image height.      |
| format   | number | Yes  | Image format, for example, YCBCR_422_SP or JPEG.            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                          | Description                                   |
| ------------------------------ | --------------------------------------- |
| [ImageCreator](#imagecreator9) | Returns an **ImageCreator** instance if the operation is successful.|

**Example**

```ts
let creator: image.ImageCreator = image.createImageCreator(8192, 8, image.ImageFormat.JPEG, 8);
```

## ImageCreator<sup>9+</sup>

Provides APIs for applications to request an image native data area and compile native image data.
Before calling any APIs in **ImageCreator**, you must create an [ImageCreator](#imagecreator9) instance. **ImageCreator** does not support multiple threads.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

| Name    | Type                        | Readable| Writable| Description              |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| capacity | number                       | Yes  | No  | Maximum number of images that can be accessed at the same time.|
| format   | [ImageFormat](#imageformat9) | Yes  | No  | Image format.        |

### dequeueImage<sup>9+</sup>

dequeueImage(callback: AsyncCallback\<Image>): void

Obtains an image buffer from the idle queue and writes image data into it. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name       | Type                                   | Mandatory| Description                |
| ------------- | ---------------------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<[Image](#image9)>  | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the latest image obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.dequeueImage((err: BusinessError, img: image.Image) => {
  if (err) {
    console.error(`Failed to dequeue the Image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in dequeuing the Image.');
  }
});
```

### dequeueImage<sup>9+</sup>

dequeueImage(): Promise\<Image>

Obtains an image buffer from the idle queue and writes image data into it. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Return value**

| Type            | Description          |
| --------------- | ------------- |
| Promise\<[Image](#image9)> | Promise used to return the latest image.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.dequeueImage().then((img: image.Image) => {
  console.info('Succeeded in dequeuing the Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to dequeue the Image.code ${error.code},message is ${error.message}`);
})
```

### queueImage<sup>9+</sup>

queueImage(interface: Image, callback: AsyncCallback\<void>): void

Places the drawn image in the dirty queue. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name       | Type                    | Mandatory| Description                |
| ------------- | -------------------------| ---- | -------------------- |
| interface     | [Image](#image9)                    | Yes  | Drawn image.|
| callback      | AsyncCallback\<void>     | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.dequeueImage().then((img: image.Image) => {
  // Draw the image.
  img.getComponent(4).then((component : image.Component) => {
    let bufferArr: Uint8Array = new Uint8Array(component.byteBuffer);
    for (let i = 0; i < bufferArr.length; i += 4) {
      bufferArr[i] = 0; //B
      bufferArr[i + 1] = 0; //G
      bufferArr[i + 2] = 255; //R
      bufferArr[i + 3] = 255; //A
    }
  })
  creator.queueImage(img, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to queue the Image.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in queuing the Image.');
    }
  })
})

```

### queueImage<sup>9+</sup>

queueImage(interface: Image): Promise\<void>

Places the drawn image in the dirty queue. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name         | Type    | Mandatory| Description               |
| ------------- | --------| ---- | ------------------- |
| interface     | [Image](#image9)   | Yes  | Drawn image.|

**Return value**

| Type           | Description          |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.dequeueImage().then((img: image.Image) => {
  // Draw the image.
  img.getComponent(4).then((component: image.Component) => {
    let bufferArr: Uint8Array = new Uint8Array(component.byteBuffer);
    for (let i = 0; i < bufferArr.length; i += 4) {
      bufferArr[i] = 0; //B
      bufferArr[i + 1] = 0; //G
      bufferArr[i + 2] = 255; //R
      bufferArr[i + 3] = 255; //A
    }
  })
  creator.queueImage(img).then(() => {
    console.info('Succeeded in queuing the Image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to queue the Image.code ${error.code},message is ${error.message}`);
  })
})

```

### on<sup>9+</sup>

on(type: 'imageRelease', callback: AsyncCallback\<void>): void

Listens for image release events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name       | Type                    | Mandatory| Description                |
| ------------- | -------------------------| ---- | -------------------- |
| type          | string                   | Yes  | Type of event, which is **'imageRelease'**.|
| callback      | AsyncCallback\<void>     | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.on('imageRelease', (err: BusinessError) => {
  if (err) {
    console.error(`Failed to get the imageRelease callback.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting imageRelease callback.');
  }
})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **ImageCreator** instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImageCreator** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name          | Type                    | Mandatory| Description                |
| ------------- | -------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<void>     | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release the creator.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing creator.');
  }
});
```
### release<sup>9+</sup>

release(): Promise\<void>

Releases this **ImageCreator** instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **ImageCreator** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Return value**

| Type           | Description          |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.release().then(() => {
  console.info('Succeeded in releasing creator.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release the creator.code ${error.code},message is ${error.message}`);
})
```

## Image<sup>9+</sup>

Provides APIs for basic image operations, including obtaining image information and reading and writing image data. An **Image** instance is returned when [readNextImage](#readnextimage9) and [readLatestImage](#readlatestimage9) are called.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    | Type              | Readable| Writable| Description                                              |
| -------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect | [Region](#region7) | Yes  | Yes  | Image area to be cropped.                                |
| size     | [Size](#size)      | Yes  | No  | Image size.                                        |
| format   | number             | Yes  | No  | Image format. For details, see [OH_NativeBuffer_Format](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_format).|
| timestamp<sup>12+</sup> | number         | Yes     | No  | Image timestamp.|

### getComponent<sup>9+</sup>

getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void

Obtains the component buffer from the **Image** instance based on the color component type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                                   | Mandatory| Description                |
| ------------- | --------------------------------------- | ---- | -------------------- |
| componentType | [ComponentType](#componenttype9)        | Yes  | Color component type of the image. (Currently, only **ComponentType:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.)   |
| callback      | AsyncCallback<[Component](#component9)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the component buffer obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

img.getComponent(4, (err: BusinessError, component: image.Component) => {
  if (err) {
    console.error(`Failed to get the component.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting component.');
  }
})
```

### getComponent<sup>9+</sup>

getComponent(componentType: ComponentType): Promise\<Component>

Obtains the component buffer from the **Image** instance based on the color component type. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| componentType | [ComponentType](#componenttype9) | Yes  | Color component type of the image. (Currently, only **ComponentType:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.)|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise<[Component](#component9)> | Promise used to return the component buffer.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

img.getComponent(4).then((component: image.Component) => {
  console.info('Succeeded in getting component.');
}).catch((error: BusinessError) => {
  console.error(`Failed to get the component.code ${error.code},message is ${error.message}`);
})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **Image** instance. This API uses an asynchronous callback to return the result.

The corresponding resources must be released before another image arrives.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **Image** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description          |
| -------- | -------------------- | ---- | -------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

img.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release the image instance.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing the image instance.');
  }
})
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases this **Image** instance. This API uses a promise to return the result.

The corresponding resources must be released before another image arrives.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the **Image** object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

img.release().then(() => {
  console.info('Succeeded in releasing the image instance.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release the image instance.code ${error.code},message is ${error.message}`);
})
```

## PositionArea<sup>7+</sup>

Describes area information in an image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type              | Read Only|  Optional| Description                                                        |
| ------ | ------------------ | ---| -----|------------------------------------------------------- |
| pixels | ArrayBuffer        | No|   No  | Pixels of the image.                                                      |
| offset | number             | No|   No |  Offset for data reading.                                                    |
| stride | number             | No|   No | Number of bytes from one row of pixels in memory to the next row of pixels in memory. The value of **stride** must be greater than or equal to the value of **region.size.width** multiplied by 4.                  |
| region | [Region](#region7) | No|   No |Region to read or write. The width of the region to write plus the X coordinate cannot be greater than the width of the original image. The height of the region to write plus the Y coordinate cannot be greater than the height of the original image.|

## ImageInfo

Describes image information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Read Only| Optional| Description      |
| ---- | ------------- | --- |-----|---------- |
| size<sup>6+</sup> | [Size](#size) | No|  No |Image size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| density<sup>9+</sup> | number | No | No|Pixel density, in ppi.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| stride<sup>11+</sup> | number | No | No | Number of bytes from one row of pixels in memory to the next row of pixels in memory.stride >= region.size.width*4 <br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| pixelFormat<sup>12+</sup> | [PixelMapFormat](#pixelmapformat7) | No |  No| Pixel format.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| alphaType<sup>12+</sup> | [AlphaType](#alphatype9)  | No |  No |Alpha type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| mimeType<sup>12+</sup> | string  |  No |   No |Actual image format (MIME type). |
| isHdr<sup>12+</sup> | boolean  |  No | No | Whether the image is in High Dynamic Range (HDR) format. For [ImageSource](#imagesource), this parameter specifies whether the source image is in HDR format. For [PixelMap](#pixelmap7), this parameter specifies whether the decoded pixel map is in HDR format.|

## Size

Describes the size of an image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type  | Read Only|  Optional |Description          |
| ------ | ------ | -- |-----| -------------- |
| height | number | No |  No |Image height, in px.|
| width  | number | No |  No| Image width, in px.|

## PixelMapFormat<sup>7+</sup>

Enumerates the pixel formats of images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | Unknown format.       |
| RGB_565                | 2      | RGB_565.    |
| RGBA_8888              | 3      | RGBA_8888.|
| BGRA_8888<sup>9+</sup> | 4      | BGRA_8888.|
| RGB_888<sup>9+</sup>   | 5      | RGB_888.  |
| ALPHA_8<sup>9+</sup>   | 6      | ALPHA_8.  |
| RGBA_F16<sup>9+</sup>  | 7      | RGBA_F16. |
| NV21<sup>9+</sup>      | 8      | NV21.     |
| NV12<sup>9+</sup>      | 9      | NV12.     |

## AlphaType<sup>9+</sup>

Enumerates the alpha types of images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    |   Value  | Description                   |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | Unknown alpha type.           |
| OPAQUE   | 1      | There is no alpha or the image is opaque.|
| PREMUL   | 2      | Premultiplied alpha.        |
| UNPREMUL | 3      | Unpremultiplied alpha, that is, straight alpha.      |

## ScaleMode<sup>9+</sup>

Enumerates the scale modes of images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name           |   Value  | Description                                              |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | Scales the image so that it fills the requested bounds of the target and crops the extra.|
| FIT_TARGET_SIZE | 0      | Reduces the image size to the dimensions of the target.                          |

## SourceOptions<sup>9+</sup>

Defines image source initialization options.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Type                              | Read Only| Optional| Description              |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| sourceDensity     | number                             | No  | No  | Pixel density of the image resource, in DPI.<br>If **desiredSize** is not set in [DecodingOptions](# decodingoptions7) and **SourceOptions.sourceDensity** and **DecodingOptions.fitDensity** are not 0, the pixel map output after decoding will be scaled.<br>The formula for calculating the width after scaling is as follows (the same applies to the height): (width * fitDensity + (sourceDensity >> 1)) / sourceDensity.|
| sourcePixelFormat | [PixelMapFormat](#pixelmapformat7) | No  | Yes  | Image pixel format. The default value is **UNKNOWN**.    |
| sourceSize        | [Size](#size)                      | No  | Yes  | Image pixel size. The default value is null.    |


## InitializationOptions<sup>8+</sup>

Defines pixel map initialization options.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                    | Type                              | Read Only|Optional|  Description          |
| ------------------------ | ---------------------------------- | ----| -----|  -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](#alphatype9)           | No  | Yes| Alpha type. The default value is **IMAGE_ALPHA_TYPE_PREMUL**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| editable                 | boolean                            | No  | Yes| Whether the image is editable. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| srcPixelFormat<sup>12+</sup>  | [PixelMapFormat](#pixelmapformat7) | No| Yes| Pixel format of the passed-in buffer data. The default value is **BGRA_8888**.|
| pixelFormat              | [PixelMapFormat](#pixelmapformat7) | No| Yes| Pixel format of the generated pixel map. The default value is **RGBA_8888**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.    |
| scaleMode<sup>9+</sup>   | [ScaleMode](#scalemode9)           | No | Yes| Scale mode. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| size                     | [Size](#size)                      | No | No|Image size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|

## DecodingOptions<sup>7+</sup>

Describes the image decoding options.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name              | Type                              | Read Only| Optional| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | No  | Yes  | Sampling size of the thumbnail. The default value is **1**. Currently, the value can only be **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| rotate             | number                             | No  | Yes  | Rotation angle. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| editable           | boolean                            | No  | Yes  | Whether the image is editable. The default value is **false**. If this option is set to **false**, the image cannot be edited again, and operations such as writing pixels will fail.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12. |
| desiredSize        | [Size](#size)                      | No  | Yes  | Expected output size. The default value is null.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| desiredRegion      | [Region](#region7)                 | No  | Yes  | Region to decode. The default value is null.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | No  | Yes  | Pixel format for decoding. The default value is **RGBA_8888**. Only RGBA_8888, BGRA_8888, and RGB_565 are supported. RGB_565 is not supported for images with alpha channels, such as PNG, GIF, ICO, and WEBP.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| index              | number                             | No  | Yes  | Index of the image to decode. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| fitDensity<sup>9+</sup> | number                        | No  | Yes  | Pixel density, in ppi. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| desiredColorSpace<sup>11+</sup> | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | No  | Yes  | Target color space. The default value is **UNKNOWN**.|
| desiredDynamicRange<sup>12+</sup> | [DecodingDynamicRange](#decodingdynamicrange12) | No  | Yes  | Desired dynamic range. The default value is **SDR**.<br>This property cannot be set for an image source created using [CreateIncrementalSource](#imagecreateincrementalsource9). By default, the image source is decoded as SDR content.<br>If the platform does not support HDR, the setting is invalid and the content is decoded as SDR content by default.|

## Region<sup>7+</sup>

Describes the region information.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Read Only| Optional| Description        |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | No  | No  | Region size.  |
| x    | number        | No  | No | X coordinate to translate.|
| y    | number        | No | No | Y coordinate of the region.|

## PackingOption

Describes the options for image packing.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name   | Type  | Read Only| Optional| Description                                               |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | No  | No  | Format of the packed image.<br>Currently, only **"image/jpeg"**, **"image/webp"**, and **"image/png"** are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| quality | number | No  | No  | Quality of the output image in JPEG encoding. The value ranges from 0 to 100. The value **0** means the lowest quality, and **100** means the highest quality. The higher the quality, the larger the space occupied by the generated image.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| bufferSize<sup>9+</sup> | number | No  | Yes  | Size of the buffer for receiving the encoded data, in bytes. If the size is not set, the default value 25 MB is used. If the size of an image exceeds 25 MB, you must specify the size. The value of **bufferSize** must be greater than the size of the encoded image. The use of [packToFile](#packtofile11) is not restricted by this parameter.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| desiredDynamicRange<sup>12+</sup> | [PackingDynamicRange](#packingdynamicrange12) | No  | Yes  | Desired dynamic range. The default value is **SDR**.|
| needsPackProperties<sup>12+</sup> | boolean | No  | Yes  | Whether to encode image property information, for example, EXIF. The default value is **false**.|

## ImagePropertyOptions<sup>11+</sup>

Describes the image properties.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name        | Type  | Read Only| Optional| Description        |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | Yes  | Yes  | Index of the image. The default value is **0**.  |
| defaultValue | string | Yes  | Yes  | Default property value. The default value is null.|

## GetImagePropertyOptions<sup>(deprecated)</sup>

Describes the image properties.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [ImagePropertyOptions](#imagepropertyoptions11).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name        | Type  | Read Only| Optional| Description        |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | No  | Yes  | Index of the image. The default value is **0**.  |
| defaultValue | string | No  | Yes  | Default property value. The default value is null.|

## PropertyKey<sup>7+</sup>

Describes the exchangeable image file format (EXIF) data of an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name              |   Value                   |   Description                   |
| ----------------- | ----------------------- |---------------------------|
| NEW_SUBFILE_TYPE <sup>12+</sup>           | "NewSubfileType"            | **Read/Write capability**: readable and writable<br> Data type of a subfile, such as a full-resolution image, a thumbnail, or a part of a multi-frame image. The value is a bit mask. The value 0 indicates a full-resolution image, **1** indicates a thumbnail, and **2** indicates a part of a multi-frame image.|
| SUBFILE_TYPE <sup>12+</sup>               | "SubfileType"               | **Read/Write capability**: readable and writable<br> Type of data contained in this subfile. This tag has been deprecated. Use **NewSubfileType** instead.|
| IMAGE_WIDTH                               | "ImageWidth"                | **Read/Write capability**: readable and writable<br> Image width.|
| IMAGE_LENGTH                              | "ImageLength"               | **Read/Write capability**: readable and writable<br> Image length.|
| BITS_PER_SAMPLE                           | "BitsPerSample"             | **Read/Write capability**: readable and writable<br> Number of bits per component.|
| COMPRESSION <sup>12+</sup>                | "Compression"               | **Read/Write capability**: readable and writable<br> Compression scheme used on the image data.|
| PHOTOMETRIC_INTERPRETATION <sup>12+</sup> | "PhotometricInterpretation" | **Read/Write capability**: readable and writable<br> Color space of the image data, for example, RGB or YCbCr.|
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"          | **Read/Write capability**: readable and writable<br> Image description.|
| MAKE<sup>10+</sup>                        | "Make"                      | **Read/Write capability**: readable and writable<br> Manufacturer.|
| MODEL<sup>10+</sup>                       | "Model"                     | **Read/Write capability**: readable and writable<br> Device model.|
| STRIP_OFFSETS <sup>12+</sup>              | "StripOffsets"              | **Read/Write capability**: readable and writable<br> Byte offset of each strip.|
| ORIENTATION                               | "Orientation"               | **Read/Write capability**: readable and writable<br> Image orientation.<br>- 1: **Top-left**: The image is not rotated.<br>- 2: **Top-right**: The image is flipped horizontally.<br>- 3: **Bottom-right**: The image is rotated by 180°.<br>- 4: **Bottom-left**: The image is flipped vertically.<br>- 5: **Left-top**: The image is flipped horizontally and then rotated clockwise by 270°.<br>- 6: **Right-top**: The image is rotated clockwise by 90°.<br>- 7: **Right-bottom**: The image is vertically flipped and then rotated clockwise by 90°.<br>- 8: **Left-bottom**: The image is rotated clockwise by 270°.<br>- **Unknown Value**: No value is defined.|
| SAMPLES_PER_PIXEL <sup>12+</sup>          | "SamplesPerPixel"           | **Read/Write capability**: readable and writable<br> Number of components per pixel. The value is 3 for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data.|
| ROWS_PER_STRIP <sup>12+</sup>             | "RowsPerStrip"              | **Read/Write capability**: readable and writable<br> Number of rows per strip.|
| STRIP_BYTE_COUNTS <sup>12+</sup>          | "StripByteCounts"           | **Read/Write capability**: readable and writable<br> Number of bytes in each strip after compression.|
| X_RESOLUTION <sup>12+</sup>               | "XResolution"               | **Read/Write capability**: readable and writable<br> Number of pixels per ResolutionUnit in the image width (X) direction.|
| Y_RESOLUTION <sup>12+</sup>               | "YResolution"               | **Read/Write capability**: readable and writable<br> Number of pixels per ResolutionUnit in the image height (Y) direction.|
| PLANAR_CONFIGURATION <sup>12+</sup>       | "PlanarConfiguration"       | **Read/Write capability**: readable and writable<br> Storage format of components of each pixel, which can be chunky or planar.|
| RESOLUTION_UNIT <sup>12+</sup>            | "ResolutionUnit"            | **Read/Write capability**: readable and writable<br> Unit of measurement for XResolution and YResolution.|
| TRANSFER_FUNCTION <sup>12+</sup>          | "TransferFunction"          | **Read/Write capability**: readable and writable<br> Transfer function for the image, which is usually used for color correction.|
| SOFTWARE <sup>12+</sup>                   | "Software"                  | **Read/Write capability**: readable and writable<br> Name and version number of the software used to create the image.|
| DATE_TIME<sup>10+</sup>                   | "DateTime"                  | **Read/Write capability**: readable and writable<br> Date and time of image creation.|
| ARTIST <sup>12+</sup>                     | "Artist"                    | **Read/Write capability**: readable and writable<br> Person who created the image.|
| WHITE_POINT <sup>12+</sup>                | "WhitePoint"                | **Read/Write capability**: readable and writable<br> Chromaticity of the white point of the image.|
| PRIMARY_CHROMATICITIES <sup>12+</sup>     | "PrimaryChromaticities"     | **Read/Write capability**: readable and writable<br> Chromaticities of the primaries of the image.|
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode"                 | **Read/Write capability**: readable and writable<br> Photographing mode.|
| JPEG_INTERCHANGE_FORMAT <sup>12+</sup>    | "JPEGInterchangeFormat"     | **Read/Write capability**: readable and writable<br> Offset of the SOI marker of a JPEG interchange format bitstream.|
| JPEG_INTERCHANGE_FORMAT_LENGTH <sup>12+</sup> | "JPEGInterchangeFormatLength" | **Read/Write capability**: readable and writable<br> Number of bytes of the JPEG stream.|
| YCBCR_COEFFICIENTS <sup>12+</sup>         | "YCbCrCoefficients"         | **Read/Write capability**: readable and writable<br> Transformation from RGB to YCbCr image data.|
| YCBCR_SUB_SAMPLING <sup>12+</sup>         | "YCbCrSubSampling"          | **Read/Write capability**: readable and writable<br> Subsampling factors used for the chrominance components of a YCbCr image.|
| YCBCR_POSITIONING <sup>12+</sup>          | "YCbCrPositioning"          | **Read/Write capability**: readable and writable<br> Positioning of subsampled chrominance components relative to luminance samples.|
| REFERENCE_BLACK_WHITE <sup>12+</sup>      | "ReferenceBlackWhite"       | **Read/Write capability**: readable and writable<br> A pair of headroom and footroom image data values (codes) for each pixel component.|
| COPYRIGHT <sup>12+</sup>                  | "Copyright"                 | **Read/Write capability**: readable and writable<br> Copyright notice of the image.|
| EXPOSURE_TIME<sup>9+</sup>                | "ExposureTime"              | **Read/Write capability**: readable and writable<br> Exposure time, for example, 1/33 seconds.|
| F_NUMBER<sup>9+</sup>                     | "FNumber"                   | **Read/Write capability**: readable and writable<br> F number, for example, f/1.8.|
| EXPOSURE_PROGRAM <sup>12+</sup>           | "ExposureProgram"           | **Read/Write capability**: readable and writable<br> Class of the program used by the camera to set exposure when the image was captured.|
| SPECTRAL_SENSITIVITY <sup>12+</sup>       | "SpectralSensitivity"       | **Read/Write capability**: readable and writable<br> Spectral sensitivity of each channel of the camera.|
| GPS_VERSION_ID <sup>12+</sup>             | "GPSVersionID"              | **Read/Write capability**: readable and writable<br> Version of GPSInfoIFD.|
| GPS_LATITUDE_REF                          | "GPSLatitudeRef"            | **Read/Write capability**: readable and writable<br> Whether the latitude is north or south latitude.|
| GPS_LATITUDE                              | "GPSLatitude"               | **Read/Write capability**: readable and writable<br> Image latitude.|
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"           | **Read/Write capability**: readable and writable<br> Whether the longitude is east or west longitude.|
| GPS_LONGITUDE                             | "GPSLongitude"              | **Read/Write capability**: readable and writable<br> Image longitude.|
| GPS_ALTITUDE_REF <sup>12+</sup>           | "GPSAltitudeRef"            | **Read/Write capability**: readable and writable<br> Whether the latitude is north or south latitude.|
| GPS_ALTITUDE <sup>12+</sup>               | "GPSAltitude"               | **Read/Write capability**: readable and writable<br> Altitude based on the reference in GPSAltitudeRef.|
| GPS_TIME_STAMP<sup>10+</sup>              | "GPSTimeStamp"              | **Read/Write capability**: readable and writable<br> GPS timestamp.|
| GPS_SATELLITES <sup>12+</sup>             | "GPSSatellites"             | **Read/Write capability**: readable and writable<br> GPS satellites used for measurement.|
| GPS_STATUS <sup>12+</sup>                 | "GPSStatus"                 | **Read/Write capability**: readable and writable<br> Status of the GPS receiver when the image was recorded.|
| GPS_MEASURE_MODE <sup>12+</sup>           | "GPSMeasureMode"            | **Read/Write capability**: readable and writable<br> GPS measurement pmode.|
| GPS_DOP <sup>12+</sup>                    | "GPSDOP"                    | **Read/Write capability**: readable and writable<br> GPS DOP (data degree of precision)|
| GPS_SPEED_REF <sup>12+</sup>              | "GPSSpeedRef"               | **Read/Write capability**: readable and writable<br> Unit used to express the movement speed of the GPS receiver.|
| GPS_SPEED <sup>12+</sup>                  | "GPSSpeed"                  | **Read/Write capability**: readable and writable<br> Movement speed of the GPS receiver.|
| GPS_TRACK_REF <sup>12+</sup>              | "GPSTrackRef"               | **Read/Write capability**: readable and writable<br> Reference of the movement direction of the GPS receiver.|
| GPS_TRACK <sup>12+</sup>                  | "GPSTrack"                  | **Read/Write capability**: readable and writable<br> Movement direction of the GPS receiver.|
| GPS_IMG_DIRECTION_REF <sup>12+</sup>      | "GPSImgDirectionRef"        | **Read/Write capability**: readable and writable<br> Reference of the direction of the image when it was captured.|
| GPS_IMG_DIRECTION <sup>12+</sup>          | "GPSImgDirection"           | **Read/Write capability**: readable and writable<br> Direction of the image when it was captured.|
| GPS_MAP_DATUM <sup>12+</sup>              | "GPSMapDatum"               | **Read/Write capability**: readable and writable<br> Geodetic survey data used by the GPS receiver.|
| GPS_DEST_LATITUDE_REF <sup>12+</sup>      | "GPSDestLatitudeRef"        | **Read/Write capability**: readable and writable<br> Whether the latitude of the destination point is north or south latitude.|
| GPS_DEST_LATITUDE <sup>12+</sup>          | "GPSDestLatitude"           | **Read/Write capability**: readable and writable<br> Latitude of the destination point.|
| GPS_DEST_LONGITUDE_REF <sup>12+</sup>     | "GPSDestLongitudeRef"       | **Read/Write capability**: readable and writable<br> Whether the longitude of the destination point is east or west longitude.|
| GPS_DEST_LONGITUDE <sup>12+</sup>         | "GPSDestLongitude"          | **Read/Write capability**: readable and writable<br> Longitude of the destination point.|
| GPS_DEST_BEARING_REF <sup>12+</sup>       | "GPSDestBearingRef"         | **Read/Write capability**: readable and writable<br> Reference of the bearing to the destination point.|
| GPS_DEST_BEARING <sup>12+</sup>           | "GPSDestBearing"            | **Read/Write capability**: readable and writable<br> Bearing to the destination point.|
| GPS_DEST_DISTANCE_REF <sup>12+</sup>      | "GPSDestDistanceRef"        | **Read/Write capability**: readable and writable<br> Unit used to express the distance to the destination point.|
| GPS_DEST_DISTANCE <sup>12+</sup>          | "GPSDestDistance"           | **Read/Write capability**: readable and writable<br> Distance to the destination point.|
| GPS_PROCESSING_METHOD <sup>12+</sup>      | "GPSProcessingMethod"       | **Read/Write capability**: readable and writable<br> String that records the name of the method used for positioning.|
| GPS_AREA_INFORMATION <sup>12+</sup>       | "GPSAreaInformation"        | **Read/Write capability**: readable and writable<br> String that records the name of the GPS area.|
| GPS_DATE_STAMP<sup>10+</sup>              | "GPSDateStamp"              | **Read/Write capability**: readable and writable<br> GPS date stamp.|
| GPS_DIFFERENTIAL <sup>12+</sup>           | "GPSDifferential"           | **Read/Write capability**: readable and writable<br> Whether differential correction is applied to the GPS receiver. It is critical to accurate location accuracy.|
| GPS_H_POSITIONING_ERROR <sup>12+</sup>    | "GPSHPositioningError"      | **Read/Write capability**: readable and writable<br> Horizontal positioning error, in meters.|
| ISO_SPEED_RATINGS<sup>9+</sup>            | "ISOSpeedRatings"           | **Read/Write capability**: readable and writable<br> ISO sensitivity or ISO speed, for example, 400.|
| PHOTOGRAPHIC_SENSITIVITY <sup>12+</sup>   | "PhotographicSensitivity"   | **Read/Write capability**: readable and writable<br> Sensitivity of the camera or input device when the image was captured.|
| OECF <sup>12+</sup>                       | "OECF"                      | **Read/Write capability**: readable and writable<br> Opto-Electric Conversion Function (OECF) specified in ISO 14524.|
| SENSITIVITY_TYPE<sup>10+</sup>            | "SensitivityType"           | **Read/Write capability**: readable and writable<br> Sensitivity type.|
| STANDARD_OUTPUT_SENSITIVITY<sup>10+</sup> | "StandardOutputSensitivity" | **Read/Write capability**: readable and writable<br> Standard output sensitivity.|
| RECOMMENDED_EXPOSURE_INDEX<sup>10+</sup>  | "RecommendedExposureIndex"  | **Read/Write capability**: readable and writable<br> Recommended exposure index.|
| ISO_SPEED<sup>10+</sup>                   | "ISOSpeedRatings"           | **Read/Write capability**: readable and writable<br> ISO speed.|
| ISO_SPEED_LATITUDE_YYY <sup>12+</sup>     | "ISOSpeedLatitudeyyy"       | **Read/Write capability**: readable and writable<br> ISO speed latitude yyy value of the camera or input device, which is defined in ISO 12232.|
| ISO_SPEED_LATITUDE_ZZZ <sup>12+</sup>     | "ISOSpeedLatitudezzz"       | **Read/Write capability**: readable and writable<br> ISO speed latitude zzz value of the camera or input device, which is defined in ISO 12232.|
| EXIF_VERSION <sup>12+</sup>               | "ExifVersion"               | **Read/Write capability**: readable and writable<br> Version of the supported EXIF standard.|
| DATE_TIME_ORIGINAL<sup>9+</sup>           | "DateTimeOriginal"          | **Read/Write capability**: readable and writable<br> Time when the original image data was generated, for example, 2022:09:06 15:48:00.|
| DATE_TIME_DIGITIZED <sup>12+</sup>        | "DateTimeDigitized"         | **Read/Write capability**: readable and writable<br> Date and time when the image was stored as digital data, in the format of YYYY:MM:DD HH:MM:SS.|
| OFFSET_TIME <sup>12+</sup>                | "OffsetTime"                | **Read/Write capability**: readable and writable<br> Time with an offset from UTC when the image was captured, in the format of ±HH:MM.|
| OFFSET_TIME_ORIGINAL <sup>12+</sup>       | "OffsetTimeOriginal"        | **Read/Write capability**: readable and writable<br> Time with an offset from UTC when the original image was created. It is critical for time-sensitive applications.|
| OFFSET_TIME_DIGITIZED <sup>12+</sup>      | "OffsetTimeDigitized"       | **Read/Write capability**: readable and writable<br> Time with an offset from UTC when the image was digitized. It helps to accurately adjust the timestamp.|
| COMPONENTS_CONFIGURATION <sup>12+</sup>   | "ComponentsConfiguration"   | **Read/Write capability**: readable and writable<br> Specific information about compressed data.|
| COMPRESSED_BITS_PER_PIXEL <sup>12+</sup>  | "CompressedBitsPerPixel"    | **Read/Write capability**: readable and writable<br> Number of bits per pixel. It is specific to compressed data.|
| SHUTTER_SPEED <sup>12+</sup>              | "ShutterSpeedValue"         | **Read/Write capability**: readable and writable<br> Shutter speed, expressed in Additive System of Photographic Exposure (APEX) values.|
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"             | **Read/Write capability**: readable and writable<br> Lens aperture.|
| BRIGHTNESS_VALUE <sup>12+</sup>           | "BrightnessValue"           | **Read/Write capability**: readable and writable<br> Value of brightness, expressed in APEX values.|
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"         | **Read/Write capability**: readable and writable<br> Exposure bias.|
| MAX_APERTURE_VALUE <sup>12+</sup>         | "MaxApertureValue"          | **Read/Write capability**: readable and writable<br> Smallest F number of the lens.|
| SUBJECT_DISTANCE <sup>12+</sup>           | "SubjectDistance"           | **Read/Write capability**: readable and writable<br> Distance to the subject, in meters.|
| METERING_MODE<sup>10+</sup>               | "MeteringMode"              | **Read/Write capability**: readable and writable<br> Metering mode.|
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"               | **Read/Write capability**: readable and writable<br> Light source.|
| FLASH <sup>10+</sup>                      | "Flash"                     | **Read/Write capability**: readable and writable<br> Flash status.|
| FOCAL_LENGTH <sup>10+</sup>               | "FocalLength"               | **Read/Write capability**: readable and writable<br> Focal length of the lens.|
| SUBJECT_AREA <sup>12+</sup>               | "SubjectArea"               | **Read/Write capability**: readable and writable<br> Location and area of the main subject in the entire scene.|
| MAKER_NOTE <sup>12+</sup>                 | "MakerNote"                 | **Read/Write capability**: read-only<br> Marker used by EXIF/DCF manufacturers to record any required information.|
| SCENE_POINTER <sup>12+</sup>              | "HwMnoteScenePointer"       | **Read/Write capability**: read-only<br> Pointer to the scene.|
| SCENE_VERSION <sup>12+</sup>              | "HwMnoteSceneVersion"       | **Read/Write capability**: read-only<br> Scene algorithm version.|
| SCENE_FOOD_CONF<sup>11+</sup>             | "HwMnoteSceneFoodConf"      | **Read/Write capability**: read-only<br> Photographing scene: food.|
| SCENE_STAGE_CONF<sup>11+</sup>            | "HwMnoteSceneStageConf"     | **Read/Write capability**: read-only<br> Photographing scene: stage.|
| SCENE_BLUE_SKY_CONF<sup>11+</sup>         | "HwMnoteSceneBlueSkyConf"   | **Read/Write capability**: read-only<br> Photographing scene: blue sky.|
| SCENE_GREEN_PLANT_CONF<sup>11+</sup>      | "HwMnoteSceneGreenPlantConf" | **Read/Write capability**: read-only<br> Photographing scene: green plant.|
| SCENE_BEACH_CONF<sup>11+</sup>            | "HwMnoteSceneBeachConf"     | **Read/Write capability**: read-only<br> Photographing scene: beach.|
| SCENE_SNOW_CONF<sup>11+</sup>             | "HwMnoteSceneSnowConf"      | **Read/Write capability**: read-only<br> Photographing scene: snow.|
| SCENE_SUNSET_CONF<sup>11+</sup>           | "HwMnoteSceneSunsetConf"    | **Read/Write capability**: read-only<br> Photographing scene: sunset.|
| SCENE_FLOWERS_CONF<sup>11+</sup>          | "HwMnoteSceneFlowersConf"   | **Read/Write capability**: read-only<br> Photographing scene: flowers.|
| SCENE_NIGHT_CONF<sup>11+</sup>            | "HwMnoteSceneNightConf"     | **Read/Write capability**: read-only<br> Photographing scene: night.|
| SCENE_TEXT_CONF<sup>11+</sup>             | "HwMnoteSceneTextConf"      | **Read/Write capability**: read-only<br> Photographing scene: text.|
| FACE_POINTER <sup>12+</sup>               | "HwMnoteFacePointer"        | **Read/Write capability**: read-only<br> Face pointer.|
| FACE_VERSION <sup>12+</sup>               | "HwMnoteFaceVersion"        | **Read/Write capability**: read-only<br> Facial recognition algorithm version.|
| FACE_COUNT<sup>11+</sup>                  | "HwMnoteFaceCount"          | **Read/Write capability**: read-only<br> Number of faces.|
| FACE_CONF <sup>12+</sup>                  | "HwMnoteFaceConf"           | **Read/Write capability**: read-only<br> Face confidence.|
| FACE_SMILE_SCORE <sup>12+</sup>           | "HwMnoteFaceSmileScore"     | **Read/Write capability**: read-only<br> Smile score of for faces.|
| FACE_RECT <sup>12+</sup>                  | "HwMnoteFaceRect"           | **Read/Write capability**: read-only<br> Face rectangle.|
| FACE_LEYE_CENTER <sup>12+</sup>           | "HwMnoteFaceLeyeCenter"     | **Read/Write capability**: read-only<br> Left eye centered.|
| FACE_REYE_CENTER <sup>12+</sup>           | "HwMnoteFaceReyeCenter"     | **Read/Write capability**: read-only<br> Right eye centered.|
| FACE_MOUTH_CENTER <sup>12+</sup>          | "HwMnoteFaceMouthCenter"    | **Read/Write capability**: read-only<br> Mouth centered.|
| CAPTURE_MODE <sup>10+</sup>               | "HwMnoteCaptureMode"        | **Read/Write capability**: readable and writable<br> Capture mode.|
| BURST_NUMBER <sup>12+</sup>               | "HwMnoteBurstNumber"        | **Read/Write capability**: read-only<br> Number of burst shooting times.|
| FRONT_CAMERA <sup>12+</sup>               | "HwMnoteFrontCamera"        | **Read/Write capability**: read-only<br> Whether the front camera is used to take a selfie.|
| ROLL_ANGLE <sup>11+</sup>                 | "HwMnoteRollAngle"          | **Read/Write capability**: read-only<br> Roll angle.|
| PITCH_ANGLE<sup>11+</sup>                 | "HwMnotePitchAngle"         | **Read/Write capability**: read-only<br> Pitch angle.|
| PHYSICAL_APERTURE <sup>10+</sup>          | "HwMnotePhysicalAperture"   | **Read/Write capability**: read-only<br> Physical aperture.|
| FOCUS_MODE<sup>11+</sup>                  | "HwMnoteFocusMode"          | **Read/Write capability**: read-only<br> Focus mode.|
| USER_COMMENT <sup>10+</sup>               | "UserComment"               | **Read/Write capability**: readable and writable<br> User comments.|
| SUBSEC_TIME <sup>12+</sup>                | "SubsecTime"                | **Read/Write capability**: readable and writable<br> Tag used to record fractions of seconds for the **DateTime** tag.|
| SUBSEC_TIME_ORIGINAL <sup>12+</sup>       | "SubsecTimeOriginal"        | **Read/Write capability**: readable and writable<br> Tag used to record fractions of seconds for the **DateTimeOriginal** tag.|
| SUBSEC_TIME_DIGITIZED <sup>12+</sup>      | "SubsecTimeDigitized"       | **Read/Write capability**: readable and writable<br> Tag used to record fractions of seconds for the **DateTimeDigitized** tag.|
| FLASHPIX_VERSION <sup>12+</sup>           | "FlashpixVersion"           | **Read/Write capability**: readable and writable<br> FlashPix format version supported by an FPXR file. It is used to enhance device compatibility.|
| COLOR_SPACE <sup>12+</sup>                | "ColorSpace"                | **Read/Write capability**: readable and writable<br> Color space information, which is usually recorded as a color space specifier.|
| PIXEL_X_DIMENSION <sup>10+</sup>          | "PixelXDimension"           | **Read/Write capability**: readable and writable<br> Pixel X dimension.|
| PIXEL_Y_DIMENSION<sup>10+</sup>           | "PixelYDimension"           | **Read/Write capability**: readable and writable<br> Pixel Y dimension.|
| RELATED_SOUND_FILE <sup>12+</sup>         | "RelatedSoundFile"          | **Read/Write capability**: readable and writable<br> Name of an audio file related to the image data.|
| FLASH_ENERGY <sup>12+</sup>               | "FlashEnergy"               | **Read/Write capability**: readable and writable<br> Strobe energy at the time the image was captured, in Beam Candle Power Seconds (BCPS).|
| SPATIAL_FREQUENCY_RESPONSE <sup>12+</sup> | "SpatialFrequencyResponse"  | **Read/Write capability**: readable and writable<br> Spatial frequency table of the camera or input device.|
| FOCAL_PLANE_X_RESOLUTION <sup>12+</sup>   | "FocalPlaneXResolution"     | **Read/Write capability**: readable and writable<br> Number of pixels in the image width (X) direction per FocalPlaneResolutionUnit.|
| FOCAL_PLANE_Y_RESOLUTION <sup>12+</sup>   | "FocalPlaneYResolution"     | **Read/Write capability**: readable and writable<br> Number of pixels in the image height (Y) direction per FocalPlaneResolutionUnit.|
| FOCAL_PLANE_RESOLUTION_UNIT <sup>12+</sup> | "FocalPlaneResolutionUnit"  | **Read/Write capability**: readable and writable<br> Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution.|
| SUBJECT_LOCATION <sup>12+</sup>           | "SubjectLocation"           | **Read/Write capability**: readable and writable<br> Location of the main subject relative to the left edge.|
| EXPOSURE_INDEX <sup>12+</sup>             | "ExposureIndex"             | **Read/Write capability**: readable and writable<br> Exposure index selected at the time the image is captured.|
| SENSING_METHOD <sup>12+</sup>             | "SensingMethod"             | **Read/Write capability**: readable and writable<br> Type of the image sensor on the camera.|
| FILE_SOURCE <sup>12+</sup>                | "FileSource"                | **Read/Write capability**: readable and writable<br> Image source.|
| SCENE_TYPE<sup>9+</sup>                   | "SceneType"                 | **Read/Write capability**: readable and writable<br> Type of the scene, for example, portrait, scenery, motion, and night.|
| CFA_PATTERN <sup>12+</sup>                | "CFAPattern"                | **Read/Write capability**: readable and writable<br> Color Filter Array (CFA) geometric pattern of the image sensor.|
| CUSTOM_RENDERED <sup>12+</sup>            | "CustomRendered"            | **Read/Write capability**: readable and writable<br> Special processing on image data.|
| EXPOSURE_MODE <sup>12+</sup>              | "ExposureMode"              | **Read/Write capability**: readable and writable<br> Exposure mode set when the image was captured.|
| WHITE_BALANCE <sup>10+</sup>              | "WhiteBalance"              | **Read/Write capability**: readable and writable<br> White balance.|
| DIGITAL_ZOOM_RATIO <sup>12+</sup>         | "DigitalZoomRatio"          | **Read/Write capability**: readable and writable<br> Digital zoom ratio when the image was captured.|
| FOCAL_LENGTH_IN_35_MM_FILM <sup>10+</sup> | "FocalLengthIn35mmFilm"     | **Read/Write capability**: readable and writable<br> Focal length in 35mm film.|
| SCENE_CAPTURE_TYPE <sup>12+</sup>         | "SceneCaptureType"          | **Read/Write capability**: readable and writable<br> Type of the scene that was captured.|
| GAIN_CONTROL <sup>12+</sup>               | "GainControl"               | **Read/Write capability**: readable and writable<br> Degree of overall image gain adjustment.|
| CONTRAST <sup>12+</sup>                   | "Contrast"                  | **Read/Write capability**: readable and writable<br> Direction of contrast processing used by the camera.|
| SATURATION <sup>12+</sup>                 | "Saturation"                | **Read/Write capability**: readable and writable<br> Direction of saturation processing used by the camera.|
| SHARPNESS <sup>12+</sup>                  | "Sharpness"                 | **Read/Write capability**: readable and writable<br> Direction of sharpness processing used by the camera.|
| DEVICE_SETTING_DESCRIPTION <sup>12+</sup> | "DeviceSettingDescription"  | **Read/Write capability**: readable and writable<br> Information about the photographing conditions of a specific camera model.|
| SUBJECT_DISTANCE_RANGE <sup>12+</sup>     | "SubjectDistanceRange"      | **Read/Write capability**: readable and writable<br> Distance to the subject.|
| IMAGE_UNIQUE_ID <sup>12+</sup>            | "ImageUniqueID"             | **Read/Write capability**: readable and writable<br> Unique identifier assigned to each image.|
| CAMERA_OWNER_NAME <sup>12+</sup>          | "CameraOwnerName"           | **Read/Write capability**: readable and writable<br> Name of the camera owner.|
| BODY_SERIAL_NUMBER <sup>12+</sup>         | "BodySerialNumber"          | **Read/Write capability**: readable and writable<br> Serial number of the camera body.|
| LENS_SPECIFICATION <sup>12+</sup>         | "LensSpecification"         | **Read/Write capability**: readable and writable<br> Specifications of the lens.|
| LENS_MAKE <sup>12+</sup>                  | "LensMake"                  | **Read/Write capability**: readable and writable<br> Manufacturer of the lens.|
| LENS_MODEL <sup>12+</sup>                 | "LensModel"                 | **Read/Write capability**: readable and writable<br> Model of the lens.|
| LENS_SERIAL_NUMBER <sup>12+</sup>         | "LensSerialNumber"          | **Read/Write capability**: readable and writable<br> Serial number of the lens.|
| COMPOSITE_IMAGE <sup>12+</sup>            | "CompositeImage"            | **Read/Write capability**: readable and writable<br> Whether the image is a composite image.|
| SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE <sup>12+</sup>   | "SourceImageNumberOfCompositeImage"       | **Read/Write capability**: readable and writable<br> Number of source images of the composite image.|
| SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE <sup>12+</sup> | "SourceExposureTimesOfCompositeImage"     | **Read/Write capability**: readable and writable<br> Exposure time of source images of the composite image.|
| GAMMA <sup>12+</sup>                      | "Gamma"                     | **Read/Write capability**: readable and writable<br> Gamma value.|
| DNG_VERSION <sup>12+</sup>                | "DNGVersion"                | **Read/Write capability**: readable and writable<br> DNG version. It encodes the DNG 4-tier version number.|
| DEFAULT_CROP_SIZE <sup>12+</sup>          | "DefaultCropSize"           | **Read/Write capability**: readable and writable<br> Size of the final image area, in raw image coordinates, taking into account extra pixels around the edges of the final image.|
| GIF_LOOP_COUNT <sup>12+</sup>             | "GIFLoopCount"              | **Read/Write capability**: read-only<br> Number of GIF loops. The value **0** means an infinite loop, and other values means the number of loops.|

## ImageFormat<sup>9+</sup>

Enumerates the image formats.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        |   Value  | Description                |
| ------------ | ------ | -------------------- |
| YCBCR_422_SP | 1000   | YCBCR422 semi-planar format.|
| JPEG         | 2000   | JPEG encoding format.      |

## ComponentType<sup>9+</sup>

Enumerates the color component types of images.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name |   Value  | Description       |
| ----- | ------ | ----------- |
| YUV_Y | 1      | Luminance component. |
| YUV_U | 2      | Chrominance component. |
| YUV_V | 3      | Chrominance component. |
| JPEG  | 4      | JPEG type.|

## Component<sup>9+</sup>

Describes the color components of an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type                            | Read Only| Optional| Description        |
| ------------- | -------------------------------- | ---- | ---- | ------------ |
| componentType | [ComponentType](#componenttype9) | Yes  | No  | Color component type.  |
| rowStride     | number                           | Yes  | No  | Row stride.      |
| pixelStride   | number                           | Yes  | No  | Pixel stride.  |
| byteBuffer    | ArrayBuffer                      | Yes  | No  | Component buffer.|

## DecodingDynamicRange<sup>12+</sup>

Describes the desired dynamic range of an image during decoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| AUTO          | 0    | The image is decoded based on the format. If the image is in HDR format, it is decoded based on the HDR content; otherwise, it is decoded based on the SDR content. The image source created by calling [CreateIncrementalSource](#imagecreateincrementalsource9) is decoded into SDR content. |
| SDR           | 1    | The image is decoded according to the standard dynamic range.  |
| HDR           | 2    | The image is decoded according to the high dynamic range. The image source created by calling [CreateIncrementalSource](#imagecreateincrementalsource9) is decoded into SDR content.    |

## PackingDynamicRange<sup>12+</sup>

Describes the desired dynamic range of a pixel map during encoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| AUTO          | 0    | Adaptive. The [pixelmap](#pixelmap7) is encoded based on the format. If the pixel map is in HDR format, it is encoded based on the HDR content; otherwise, it is encoded based on the SDR content. |
| SDR           | 1    | The image is decoded according to the standard dynamic range.  |

## HdrMetadataKey<sup>12+</sup>

Enumerates the keys of HDR metadata used by [pixelmap](#pixelmap7).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| HDR_METADATA_TYPE    | 0    | Metadata type used by [pixelmap](#pixelmap7). |
| HDR_STATIC_METADATA  | 1    | Static metadata.  |
| HDR_DYNAMIC_METADATA | 2    | Dynamic metadata.  |
| HDR_GAINMAP_METADATA | 3    | Metadata used by gain maps.  |

## HdrMetadataType<sup>12+</sup>

Enumerates the values available for **HDR_METADATA_TYPE** in [HdrMetadataKey](#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| NONE     | 0    | No metadata. |
| BASE     | 1    | Metadata used for base graphics.  |
| GAINMAP  | 2    | Metadata used for gain maps.  |
| ALTERNATE| 3    | Metadata used for synthesized HDR graphics.  |

## HdrStaticMetadata<sup>12+</sup>

Describes the static metadata keys, that is, the values available for **HDR_STATIC_METADATA** in [HdrMetadataKey](#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Description        |
| ------------- | ----------| ------------ |
| displayPrimariesX     | Array\<number>    | X coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. |
| displayPrimariesY     | Array\<number>    | Y coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. |
| whitePointX  | number    | X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].  |
| whitePointY  | number     | X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].  |
| maxLuminance  | number    | Maximum luminance of the main monitor. The unit is 1, and the maximum value is 65535.  |
| minLuminance  | number     | Minimum luminance of the main monitor. The unit is 0.0001, and the maximum value is 6.55535.  |
| maxContentLightLevel  | number    | Maximum luminance of the displayed content. The unit is 1, and the maximum value is 65535.  |
| maxFrameAverageLightLevel  | number     | Maximum average luminance of the displayed content. The unit is 1, and the maximum value is 65535.|

## GainmapChannel<sup>12+</sup>

Describes the data content of a single channel of the gain map. For details, see ISO 21496-1.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Description        |
| ------------- | ----------| ------------ |
| gainmapMax     | number   | Maximum value of the gain map. For details, see ISO 21496-1. |
| gainmapMin     | number   | Minimum value of the gain map. For details, see ISO 21496-1. |
| gamma  | number    | Gamma. For details, see ISO 21496-1.  |
| baseOffset  | number     | Offset of the base graphic. For details, see ISO 21496-1.  |
| alternateOffset  | number    | Offset of the alternative graphic that can be extracted. For details, see ISO 21496-1.   |

## HdrGainmapMetadata<sup>12+</sup>

Describes the metadata keys used by a gain map, that is, the values available for **HDR_GAINMAP_METADATA** in [HdrMetadataKey](#hdrmetadatakey12). For details, see ISO 21496-1.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Description        |
| ------------- | ----------| ------------ |
| writerVersion     | number   | Version used by the metadata editor. |
| miniVersion     | number   | Minimum version that needs to be understood for metadata parsing. |
| gainmapChannelCount  | number    | Number of color channels of the gain map. When the value is 3, the metadata values of the RGB channels are different. When the value is 1, the metadata values of the RGB channels are the same. For details, see ISO 21496-1. |
| useBaseColorFlag  | boolean     | Whether to use the color space of the base graphic. For details, see ISO 21496-1.  |
| baseHeadroom  | number    |  Headroom of the base graphic, which means the additional brightness that can be added to the base graphic. For details, see ISO 21496-1.  |
| alternateHeadroom  | number     |  Headroom of the alternate graphic. For details, see ISO 21496-1. |
| channels  | Array<[GainmapChannel](#gainmapchannel12)> | Number of channels. The length is 3. For details, see ISO 21496-1.|

## HdrMetadataValue<sup>12+</sup>

type HdrMetadataValue = HdrMetadataType | HdrStaticMetadata | ArrayBuffer | HdrGainmapMetadata

Describes the HDR metadata values used by a pixel map, which corresponds to the values available for [HdrMetadataKey](#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Type               | Description                                           |
| ------------------- | ----------------------------------------------- |
| [HdrMetadataType](#hdrmetadatatype12) | Metadata value corresponding to the **HDR_GAINMAP_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|
| [HdrStaticMetadata](#hdrstaticmetadata12) | Metadata value corresponding to the **HDR_STATIC_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|
| ArrayBuffer | Metadata value corresponding to the **HDR_DYNAMIC_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|
| [HdrGainmapMetadata](#hdrgainmapmetadata12) | Metadata value corresponding to the **HDR_GAINMAP_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|

## AntiAliasingLevel<sup>12+</sup>

Enumerates the anti-aliasing levels.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| NONE                | 0      | The nearest neighbor interpolation algorithm is used by default.       |
| LOW                 | 1      | Bilinear interpolation.    |
| MEDIUM              | 2      | Bilinear interpolation with mipmap enabled.|
| HIGH                | 3      | Cubic convolution.|

## Supplementary Information
### SVG Tags

The SVG tags are supported since API version 10. The used version is (SVG) 1.1. An XML declaration that starts with **<?xml** needs to be added to an SVG file, and the width and height of the SVG tag need to be set. Currently, the following tags are supported:
- a
- circla
- clipPath
- defs
- ellipse
- feBlend
- feColorMatrix
- feComposite
- feDiffuseLighting
- feDisplacementMap
- feDistantLight
- feFlood
- feGaussianBlur
- feImage
- feMorphology
- feOffset
- fePointLight
- feSpecularLighting
- feSpotLight
- feTurbulence
- filter
- g
- image
- line
- linearGradient
- mask
- path
- pattern
- polygon
- polyline
- radialGradient
- rect
- stop
- svg
- text
- textPath
- tspan
- use
