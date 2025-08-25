# Functions
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## image.createPicture<sup>13+</sup>

createPicture(mainPixelmap : PixelMap): Picture

Creates a Picture object based on a main PixelMap.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type               | Mandatory| Description            |
| ------------ | ------------------- | ---- | ---------------- |
| mainPixelmap | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Main PixelMap.|

**Return value**

| Type              | Description             |
| ------------------ | ----------------- |
| [Picture](arkts-apis-image-Picture.md) | Picture object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function CreatePicture(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  if (pictureObj != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }
}
```

## image.createPictureFromParcel<sup>13+</sup>

createPictureFromParcel(sequence: rpc.MessageSequence): Picture

Creates a Picture object from a MessageSequence object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                                               | Mandatory| Description                                |
| -------- | ------------------------------------------------------------------- | ---- | ------------------------------------ |
| sequence | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object that stores the Picture information.|

**Return value**

| Type              | Description             |
| ------------------ | ----------------- |
| [Picture](arkts-apis-image-Picture.md) | Picture object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 62980097 |  IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.                                        |

**Example**

```ts
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

class MySequence implements rpc.Parcelable {
  picture: image.Picture | null = null;
  constructor(conPicture: image.Picture) {
    this.picture = conPicture;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    if(this.picture != null) {
      this.picture.marshalling(messageSequence);
      console.info('Marshalling success !');
      return true;
    } else {
      console.error('Marshalling failed !');
      return false;
    }
  }
  unmarshalling(messageSequence : rpc.MessageSequence) {
    this.picture = image.createPictureFromParcel(messageSequence);
    this.picture.getMainPixelmap().getImageInfo().then((imageInfo : image.ImageInfo) => {
      console.info('Unmarshalling to get mainPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
    }).catch((error: BusinessError) => {
      console.error('Unmarshalling failed error.code: ${error.code} ,error.message: ${error.message}');
    });
    return true;
  }
}

async function Marshalling_UnMarshalling(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  if (pictureObj != null) {
    let parcelable: MySequence = new MySequence(pictureObj);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    // marshalling.
    data.writeParcelable(parcelable);
    let ret: MySequence = new MySequence(pictureObj);
    // unmarshalling.
    data.readParcelable(ret);
  } else {
    console.error('PictureObj is null');
  }
}
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>

Creates a PixelMap object with the specified properties. By default, the BGRA_8888 format is used to process data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap object.<br>If the size of the created PixelMap exceeds that of the original image, the PixelMap size of the original image is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
  image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating pixelmap.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
  })
}
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void

Creates a PixelMap object with the specified properties. By default, the BGRA_8888 format is used to process data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options  | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| callback | AsyncCallback\<[PixelMap](arkts-apis-image-PixelMap.md)>           | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
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

## image.createPixelMapUsingAllocator<sup>20+</sup>

createPixelMapUsingAllocator(colors: ArrayBuffer, param: InitializationOptions, allocatorType?: AllocatorType): Promise\<PixelMap>

Creates a PixelMap object with the specified properties and memory type. By default, the BGRA_8888 format is used to process data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| param  | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| allocatorType  | [AllocatorType](arkts-apis-image-e.md#allocatortype15)          | No  | Memory type for creating the PixelMap. The default memory type is **AllocatorType.AUTO**.<br> 1. **image.AllocatorType.AUTO**: The following formats are not supported for this memory type: UNKNOWN, YCBCR_P010, YCRCB_P010, and ASTC_4x4. For RGBA_1010102, DMA memory is allocated by default. For other formats (RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16), DMA memory is allocated if the dimensions exceed 512*512; otherwise, shared memory is allocated.<br>2. **image.AllocatorType.DMA**: The formats RGBA_1010102, RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16 support DMA memory types. Other formats do not support DMA memory types.<br>3. **image.AllocatorType.SHARED**: The formats UNKNOWN, RGBA_1010102, YCBCR_P010, YCRCB_P010, and ASTC_4x4 do not support shared memory. Other formats support shared memory.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation. |
|  7600301    | Memory alloc failed. |
|  7600302    | Memory copy failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapUseAllocator() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
  image.createPixelMapUsingAllocator(color, opts, image.AllocatorType.AUTO).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating pixelmap.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
  })
}
```

## image.createPixelMapFromParcel<sup>11+</sup>

createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap

Creates a PixelMap object from a MessageSequence object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object that stores the PixelMap information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.|
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.|
| 62980115 | Invalid input parameter.|
| 62980105 | Failed to get the data.|
| 62980177 | Abnormal API environment.|
| 62980178 | Failed to create the PixelMap.|
| 62980179 | Abnormal buffer size.|
| 62980180 | FD mapping failed. Possible cause: 1. Size and address does not match. 2. Memory map in memalloc failed.|
| 62980246 | Failed to read the PixelMap.|

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
async function CreatePixelMapFromParcel() {
  const color: ArrayBuffer = new ArrayBuffer(96);
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = 0x80;
  }
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: image.PixelMapFormat.BGRA_8888,
    size: { height: 4, width: 6 },
    alphaType: image.AlphaType.UNPREMUL
  }
  let pixelMap: image.PixelMap | undefined = undefined;
  await image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
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

Creates a PixelMap object based on the surface ID and region information. The size of the region is specified by [Region](arkts-apis-image-i.md#region8).size. This API uses a promise to return the result.

> **NOTE**
>
> When working with foldable devices, switching between folded and unfolded states may cause the API call to fail due to the rotation angle of surface. To address this, you need to adjust the width and height according to the rotation angle. In such cases, [image.createPixelMapFromSurface](#imagecreatepixelmapfromsurface15) is recommended.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which can be obtained through the preview component, for example, [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|
| region                 | [Region](arkts-apis-image-i.md#region8)  | Yes  | Region information. The width and height in [Region](arkts-apis-image-i.md#region8).size must be the same as those of the preview stream.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | If the image parameter invalid.|
| 62980105 | Failed to get the data.|
| 62980178 | Failed to create the PixelMap.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapFromSurface(surfaceId: string) {
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

Creates a PixelMap object based on the surface ID and region information. This API returns the result synchronously. The size of the region is specified by [Region](arkts-apis-image-i.md#region8).size.

> **NOTE**
>
> When working with foldable devices, switching between folded and unfolded states may cause the API call to fail due to the rotation angle of surface. To address this, you need to adjust the width and height according to the rotation angle. In such cases, [image.createPixelMapFromSurfaceSync](#imagecreatepixelmapfromsurfacesync15) is recommended.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which can be obtained through the preview component, for example, [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|
| region                 | [Region](arkts-apis-image-i.md#region8)  | Yes  | Region information. The width and height in [Region](arkts-apis-image-i.md#region8).size must be the same as those of the preview stream.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 62980105 | Failed to get the data.|
| 62980178 | Failed to create the PixelMap.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(surfaceId: string) {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  let pixelMap : image.PixelMap = image.createPixelMapFromSurfaceSync(surfaceId, region);
  return pixelMap;
}
```

## image.createPixelMapFromSurface<sup>15+</sup>

createPixelMapFromSurface(surfaceId: string): Promise\<PixelMap>

Creates a PixelMap object from a surface ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which can be obtained through the preview component, for example, [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap object.|

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
  image.createPixelMapFromSurface(surfaceId).then(() => {
    console.info('Succeeded in creating pixelmap from Surface');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
  });
} 
```

## image.createPixelMapFromSurfaceSync<sup>15+</sup>

createPixelMapFromSurfaceSync(surfaceId: string): PixelMap

Creates a PixelMap object from a surface ID. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which can be obtained through the preview component, for example, [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object. If the operation fails, an error is thrown.|

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
  let pixelMap : image.PixelMap = image.createPixelMapFromSurfaceSync(surfaceId);
  return pixelMap;
}
```
## image.createPixelMapSync<sup>12+</sup>

createPixelMapSync(colors: ArrayBuffer, options: InitializationOptions): PixelMap

Creates a PixelMap object with the specified properties. By default, the BGRA_8888 format is used to process data. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapSync() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
  let pixelMap : image.PixelMap = image.createPixelMapSync(color, opts);
  return pixelMap;
}
```

## image.createPixelMapSync<sup>12+</sup>

createPixelMapSync(options: InitializationOptions): PixelMap

Creates a PixelMap object with the specified pixel properties. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| options | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapSync() {
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
  let pixelMap : image.PixelMap = image.createPixelMapSync(opts);
  return pixelMap;
}
```

## image.createPixelMapUsingAllocatorSync<sup>20+</sup>

createPixelMapUsingAllocatorSync(colors: ArrayBuffer, param: InitializationOptions, allocatorType?: AllocatorType): PixelMap

Creates a PixelMap object with the specified properties and memory type. By default, the BGRA_8888 format is used to process data. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| param | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| allocatorType  | [AllocatorType](arkts-apis-image-e.md#allocatortype15)          | No  | Memory type for creating the PixelMap. The default memory type is **AllocatorType.AUTO**.<br> 1. **image.AllocatorType.AUTO**: The following formats are not supported for this memory type: UNKNOWN, YCBCR_P010, YCRCB_P010, and ASTC_4x4. For RGBA_1010102, DMA memory is allocated by default. For other formats (RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16), DMA memory is allocated if the dimensions exceed 512*512; otherwise, shared memory is allocated.<br>2. **image.AllocatorType.DMA**: The formats RGBA_1010102, RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16 support DMA memory types. Other formats do not support DMA memory types.<br>3. **image.AllocatorType.SHARED**: The formats UNKNOWN, RGBA_1010102, YCBCR_P010, YCRCB_P010, and ASTC_4x4 do not support shared memory. Other formats support shared memory.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation. |
|  7600301    | Memory alloc failed. |
|  7600302    | Memory copy failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapSync() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
  let pixelMap : image.PixelMap = image.createPixelMapUsingAllocatorSync(color, opts, image.AllocatorType.AUTO);
  return pixelMap;
}
```

## image.createPixelMapUsingAllocatorSync<sup>20+</sup>

createPixelMapUsingAllocatorSync(param: InitializationOptions, allocatorType?: AllocatorType): PixelMap

Creates a PixelMap object with the specified pixel properties. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| param | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| allocatorType  | [AllocatorType](arkts-apis-image-e.md#allocatortype15)          | No  | Memory type for creating the PixelMap. The default memory type is **AllocatorType.AUTO**.<br> 1. **image.AllocatorType.AUTO**: The following formats are not supported for this memory type: UNKNOWN and ASTC_4x4. For RGBA_1010102, YCBCR_P010, and YCRCB_P010, DMA memory is allocated by default. For other formats (RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16), DMA memory is allocated if the dimensions exceed 512*512; otherwise, shared memory is allocated.<br>2. **image.AllocatorType.DMA**: The formats RGB_565, RGBA_8888, BGRA_8888, RGBAF_16, RGBA_1010102, YCBCR_P010, and YCRCB_P010 support DMA memory type. Other formats do not support DMA memory type.<br>3. **image.AllocatorType.SHARED**: The formats UNKNOWN, RGBA_1010102, YCBCR_P010, YCRCB_P010, and ASTC_4x4 do not support shared memory. Other formats support shared memory.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation.|
|  7600301    | Memory alloc failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapSync() {
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
  let pixelMap : image.PixelMap = image.createPixelMapUsingAllocatorSync(opts, image.AllocatorType.AUTO);
  return pixelMap;
}
```

## image.createPremultipliedPixelMap<sup>12+</sup>

createPremultipliedPixelMap(src: PixelMap, dst: PixelMap, callback: AsyncCallback\<void>): void

Converts a non-premultiplied alpha of a PixelMap to a premultiplied one and stores the converted data to a target PixelMap. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Source PixelMap object.|
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Target PixelMap object.|
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

async function CreatePremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel buffer to create. The value is calculated as follows: height * width * 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.UNPREMUL}
  let srcPixelmap = image.createPixelMapSync(color, optsForUnpre);
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.PREMUL}
  let dstPixelMap = image.createPixelMapSync(optsForPre);
  image.createPremultipliedPixelMap(srcPixelmap, dstPixelMap, (error: BusinessError) => {
    if(error) {
      console.error(`Failed to convert pixelmap, error code is ${error}`);
      return;
    } else {
      console.info('Succeeded in converting pixelmap.');
    }
  })
}
```

## image.createPremultipliedPixelMap<sup>12+</sup>

createPremultipliedPixelMap(src: PixelMap, dst: PixelMap): Promise\<void>

Converts a non-premultiplied alpha of a PixelMap to a premultiplied one and stores the converted data to a target PixelMap. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Source PixelMap object.|
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Target PixelMap object.|

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

async function CreatePremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel buffer to create. The value is calculated as follows: height * width * 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.UNPREMUL}
  let srcPixelmap = image.createPixelMapSync(color, optsForUnpre);
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.PREMUL}
  let dstPixelMap = image.createPixelMapSync(optsForPre);
  image.createPremultipliedPixelMap(srcPixelmap, dstPixelMap).then(() => {
    console.info('Succeeded in converting pixelmap.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to convert pixelmap, error code is ${error}`);
  })
}
```

## image.createUnpremultipliedPixelMap<sup>12+</sup>

createUnpremultipliedPixelMap(src: PixelMap, dst: PixelMap, callback: AsyncCallback\<void>): void

Converts a premultiplied alpha of a PixelMap to a non-premultiplied one and stores the converted data to a target PixelMap. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Source PixelMap object.|
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Target PixelMap object.|
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

async function CreateUnpremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel buffer to create. The value is calculated as follows: height * width * 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.PREMUL}
  let srcPixelmap = image.createPixelMapSync(color, optsForPre);
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.UNPREMUL}
  let dstPixelMap = image.createPixelMapSync(optsForUnpre);
  image.createUnpremultipliedPixelMap(srcPixelmap, dstPixelMap, (error: BusinessError) => {
    if(error) {
      console.error(`Failed to convert pixelmap, error code is ${error}`);
      return;
    } else {
      console.info('Succeeded in converting pixelmap.');
    }
  })
}
```

## image.createUnpremultipliedPixelMap<sup>12+</sup>

createUnpremultipliedPixelMap(src: PixelMap, dst: PixelMap): Promise\<void>

Converts a premultiplied alpha of a PixelMap to a non-premultiplied one and stores the converted data to a target PixelMap. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Source PixelMap object.|
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | Yes  | Target PixelMap object.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
|  62980103    | The image data is not supported. |
|  62980246    | Failed to read the pixelMap. |
|  62980248    | Pixelmap not allow modify. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateUnpremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16 is the size of the pixel buffer to create. The value is calculated as follows: height * width * 4.
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i+1] = 255;
    bufferArr[i+2] = 122;
    bufferArr[i+3] = 122;
  }
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.PREMUL}
  let srcPixelmap = image.createPixelMapSync(color, optsForPre);
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 } , alphaType: image.AlphaType.UNPREMUL}
  let dstPixelMap = image.createPixelMapSync(optsForUnpre);
  image.createUnpremultipliedPixelMap(srcPixelmap, dstPixelMap).then(() => {
    console.info('Succeeded in converting pixelmap.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to convert pixelmap, error code is ${error}`);
  })
}
```

## image.createImageSource

createImageSource(uri: string): ImageSource

Creates an ImageSource instance based on a given URI.


**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | Yes  | Image path. Currently, only the application sandbox path is supported.<br>The following formats are supported: .jpg, .png, .gif, .bmp, .webp, .dng, .heic<sup>12+</sup> (depending on the hardware), [.svg<sup>10+</sup>](#svg-tags), and .ico<sup>11+</sup>.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
```

## image.createImageSource<sup>9+</sup>

createImageSource(uri: string, options: SourceOptions): ImageSource

Creates an ImageSource instance based on a given URI.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                               |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| uri     | string                          | Yes  | Image path. Currently, only the application sandbox path is supported.<br>The following formats are supported: .jpg, .png, .gif, .bmp, .webp, .dng, .heic<sup>12+</sup> (depending on the hardware), [.svg<sup>10+</sup>](#svg-tags), and .ico<sup>11+</sup>.|
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.png' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.png";
let imageSourceApi: image.ImageSource = image.createImageSource(path, sourceOptions);
```

## image.createImageSource<sup>7+</sup>

createImageSource(fd: number): ImageSource

Creates an ImageSource instance based on a given file descriptor.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description         |
| ------ | ------ | ---- | ------------- |
| fd     | number | Yes  | File descriptor.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const imageSourceApi: image.ImageSource = image.createImageSource(file.fd);
```

## image.createImageSource<sup>9+</sup>

createImageSource(fd: number, options: SourceOptions): ImageSource

Creates an ImageSource instance based on a given file descriptor.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                               |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| fd      | number                          | Yes  | File descriptor.                     |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const filePath: string = context.filesDir + "/test.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const imageSourceApi: image.ImageSource = image.createImageSource(file.fd, sourceOptions);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer): ImageSource

Creates an ImageSource instance based on buffers. The data passed by **buf** must be undecoded. Do not pass the pixel buffer data such as RBGA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [image.createPixelMapSync](arkts-apis-image-ImageSource.md#createpixelmapsync12).

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
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|


**Example**

```ts
const buf: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
const imageSourceApi: image.ImageSource = image.createImageSource(buf);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource

Creates an ImageSource instance based on buffers. The data passed by **buf** must be undecoded. Do not pass the pixel buffer data such as RBGA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [image.createPixelMapSync](arkts-apis-image-ImageSource.md#createpixelmapsync12).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type                            | Mandatory| Description                                |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| buf    | ArrayBuffer                      | Yes  | Array of image buffers.                    |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

```ts
const data: ArrayBuffer = new ArrayBuffer(112);
let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
const imageSourceApi: image.ImageSource = image.createImageSource(data, sourceOptions);
```

## image.createImageSource<sup>11+</sup>

createImageSource(rawfile: resourceManager.RawFileDescriptor, options?: SourceOptions): ImageSource

Creates an ImageSource instance based on the raw file descriptor of an image resource file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type                            | Mandatory| Description                                |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| rawfile | [resourceManager.RawFileDescriptor](../apis-localization-kit/js-apis-resource-manager.md#rawfiledescriptor9) | Yes| Raw file descriptor of the image resource file.|
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | No| Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { resourceManager } from '@kit.LocalizationKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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

Creates an ImageSource instance in incremental mode based on buffers. Such an instance does not support reading or writing of EXIF information.

The ImageSource instance created in incremental mode supports the following capabilities (applicable to synchronous, callback, and promise modes):

- Obtaining image information: Call [getImageInfo](arkts-apis-image-ImageSource.md#getimageinfo) to obtain image information by index, or call [getImageInfo](arkts-apis-image-ImageSource.md#getimageinfo-1) to directly obtain image information.
- Obtaining an image property: Call [getImageProperty](arkts-apis-image-ImageSource.md#getimageproperty11) to obtain the value of a property with the specified index in an image.
- Obtaining image properties: Call [getImageProperties](arkts-apis-image-ImageSource.md#getimageproperties12) to obtain the values of properties with the given names in an image.
- Updating incremental data: Call [updateData](arkts-apis-image-ImageSource.md#updatedata9).
- Creating a PixelMap object: Call [createPixelMap](arkts-apis-image-ImageSource.md#createpixelmap7) or [createPixelMap](arkts-apis-image-ImageSource.md#createpixelmap7-2) to create a PixelMap object based on decoding options; call [createPixelMap](arkts-apis-image-ImageSource.md#createpixelmap7-1) to create a PixelMap object based on default parameters.
- Releasing an ImageSource instance: Call [release](arkts-apis-image-ImageSource.md#release).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type       | Mandatory| Description     |
| ------- | ------------| ---- | ----------|
| buf     | ArrayBuffer | Yes  | Incremental data.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { resourceManager } from '@kit.LocalizationKit';
import { image } from '@kit.ImageKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id); // Obtain the image resource.
// 'app.media.startIcon' is only an example. Replace it with the actual one in use. Otherwise, the imageArray instance fails to be created, and subsequent operations cannot be performed.
let splitBuff1 = imageArray.slice(0, imageArray.byteLength / 2);  // Image slice.
let splitBuff2 = imageArray.slice(imageArray.byteLength / 2);
const imageSourceIncrementalSApi: image.ImageSource = image.CreateIncrementalSource(new ArrayBuffer(imageArray.byteLength));
imageSourceIncrementalSApi.updateData(splitBuff1, false, 0, splitBuff1.byteLength).then(() => {
  imageSourceIncrementalSApi.updateData(splitBuff2, true, 0, splitBuff2.byteLength).then(() => {
    let pixelMap = imageSourceIncrementalSApi.createPixelMapSync();
    let imageInfo = pixelMap.getImageInfoSync();
    console.info('Succeeded in creating pixelMap');
  }).catch((error : BusinessError) => {
    console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
  })
}).catch((error : BusinessError) => {
  console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
})
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource

Creates an ImageSource instance in incremental mode based on buffers. Such an instance does not support reading or writing of EXIF information.

The capabilities supported by the ImageSource instance created by this API are the same as those supported by the instance created by [CreateIncrementalSource(buf: ArrayBuffer): ImageSource](#imagecreateincrementalsource9).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                                |
| ------- | ------------------------------- | ---- | ------------------------------------ |
| buf     | ArrayBuffer                     | Yes  | Incremental data.                          |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | No  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { resourceManager } from '@kit.LocalizationKit';
import { image } from '@kit.ImageKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id) // Obtain the image resource.
// 'app.media.startIcon' is only an example. Replace it with the actual one in use. Otherwise, the imageArray instance fails to be created, and subsequent operations cannot be performed.
let splitBuff1 = imageArray.slice(0, imageArray.byteLength / 2);  // Image slice.
let splitBuff2 = imageArray.slice(imageArray.byteLength / 2);
let sourceOptions: image.SourceOptions = { sourceDensity: 120};

const imageSourceIncrementalSApi: image.ImageSource = image.CreateIncrementalSource(new ArrayBuffer(imageArray.byteLength), sourceOptions);
imageSourceIncrementalSApi.updateData(splitBuff1, false, 0, splitBuff1.byteLength).then(() => {
  imageSourceIncrementalSApi.updateData(splitBuff2, true, 0, splitBuff2.byteLength).then(() => {
    let pixelMap = imageSourceIncrementalSApi.createPixelMapSync();
    let imageInfo = pixelMap.getImageInfoSync();
    console.info('Succeeded in creating pixelMap');
  }).catch((error : BusinessError) => {
    console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
  })
}).catch((error : BusinessError) => {
  console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
})
```

## image.getImageSourceSupportedFormats<sup>20+</sup>

getImageSourceSupportedFormats(): string[]

Obtains the supported decoding formats, represented by MIME types.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type    | Description                                      |
| -------- | ------------------------------------------ |
| string[] | List of supported decoding formats (MIME types).|

**Example**

```ts
import { image } from '@kit.ImageKit';
function GetImageSourceSupportedFormats() {
    let formats = image.getImageSourceSupportedFormats();
    console.info('formats:', formats);
}
```

## image.createImagePacker

createImagePacker(): ImagePacker

Creates an ImagePacker instance.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type                       | Description                 |
| --------------------------- | --------------------- |
| [ImagePacker](arkts-apis-image-ImagePacker.md) | ImagePacker instance created.|

**Example**

```ts
const imagePackerApi: image.ImagePacker = image.createImagePacker();
```

## image.getImagePackerSupportedFormats<sup>20+</sup>

getImagePackerSupportedFormats(): string[]

Obtains the supported encoding formats, represented by MIME types.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type    | Description                                      |
| -------- | ------------------------------------------ |
| string[] | List of supported encoding formats (MIME types).|

**Example**

```ts
import { image } from '@kit.ImageKit';
function GetImagePackerSupportedFormats() {
    let formats = image.getImagePackerSupportedFormats();
    console.info('formats:', formats);
}
```

## image.createAuxiliaryPicture<sup>13+</sup>

createAuxiliaryPicture(buffer: ArrayBuffer, size: Size, type: AuxiliaryPictureType): AuxiliaryPicture

Creates an AuxiliaryPicture instance based on the ArrayBuffer image data, auxiliary picture size, and auxiliary picture type.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                                           | Mandatory| Description                        |
| ------ | ----------------------------------------------- | ---- | ---------------------------- |
| buffer | ArrayBuffer                                     | Yes  | Image data stored in the buffer. |
| size   | [Size](arkts-apis-image-i.md#size)                                   | Yes  | Size of the auxiliary picture, in px.   |
| type   | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | Yes  | Type of the auxiliary picture.                |

**Return value**

| Type                                   | Description                                      |
| --------------------------------------- | ------------------------------------------ |
| [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md) | AuxiliaryPicture instance.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function CreateAuxiliaryPicture(context: Context) {
  let funcName = "CreateAuxiliaryPicture";
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // Support for HDR images is required.
  let auxBuffer: ArrayBuffer = rawFile.buffer as ArrayBuffer;
  let auxSize: Size = {
    height: 180,
    width: 240
  };
  let auxType: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
  let auxPictureObj: image.AuxiliaryPicture | null = image.createAuxiliaryPicture(auxBuffer, auxSize, auxType);
  if(auxPictureObj != null) {
    let type: image.AuxiliaryPictureType = auxPictureObj.getType();
    console.info(funcName, 'CreateAuxiliaryPicture succeeded this.Aux_picture.type.' + JSON.stringify(type));
  } else {
    console.error(funcName, 'CreateAuxiliaryPicture failed');
  }
}
```

## image.createImageReceiver<sup>11+</sup>

createImageReceiver(size: Size, format: ImageFormat, capacity: number): ImageReceiver

Creates an ImageReceiver instance by specifying the image size, format, and capacity. The ImageReceiver acts as the receiver and consumer of images. Its parameter properties do not actually affect the received images. The configuration of image properties should be done on the sending side (the producer), such as when creating a camera preview stream with [createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput).

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| size    | [Size](arkts-apis-image-i.md#size)  | Yes  | Default size of the image. This parameter does not affect the size of the received image. The actual returned size is determined by the producer, for example, the camera.      |
| format   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | Yes  | Image format, which is a constant of [ImageFormat](arkts-apis-image-e.md#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.)            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](arkts-apis-image-ImageReceiver.md) | ImageReceiver instance.|

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

## image.createImageCreator<sup>11+</sup>

createImageCreator(size: Size, format: ImageFormat, capacity: number): ImageCreator

Creates an ImageCreator instance by specifying the image size, format, and capacity.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| size    | [Size](arkts-apis-image-i.md#size)  | Yes  | Default size of the image.      |
| format   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | Yes  | Image format, for example, YCBCR_422_SP or JPEG.            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                          | Description                                   |
| ------------------------------ | --------------------------------------- |
| [ImageCreator](arkts-apis-image-ImageCreator.md) | ImageCreator instance.|


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

## image.createImageReceiver<sup>(deprecated)</sup>

createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver

Creates an ImageReceiver instance by specifying the image width, height, format, and capacity. The ImageReceiver acts as the receiver and consumer of images. Its parameter properties do not actually affect the received images. The configuration of image properties should be done on the sending side (the producer), such as when creating a camera preview stream with [createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput).

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [createImageReceiver](#imagecreateimagereceiver11).

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| width    | number | Yes  | Default image width, in px. This parameter does not affect the width of the received image. The actual width is determined by the producer, for example, the camera.      |
| height   | number | Yes  | Default image height, in px. This parameter does not affect the height of the received image. The actual height is determined by the producer, for example, the camera.      |
| format   | number | Yes  | Image format, which is a constant of [ImageFormat](arkts-apis-image-e.md#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.) |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](arkts-apis-image-ImageReceiver.md) | ImageReceiver instance.|

**Example**

```ts
let receiver: image.ImageReceiver = image.createImageReceiver(8192, 8, image.ImageFormat.JPEG, 8);
```

## image.createImageCreator<sup>(deprecated)</sup>

createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator

Creates an ImageCreator instance by specifying the image width, height, format, and capacity.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [createImageCreator](#imagecreateimagecreator11).

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| width    | number | Yes  | Default image width, in px.      |
| height   | number | Yes  | Default image height, in px.      |
| format   | number | Yes  | Image format, for example, YCBCR_422_SP or JPEG.            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                          | Description                                   |
| ------------------------------ | --------------------------------------- |
| [ImageCreator](arkts-apis-image-ImageCreator.md) | ImageCreator instance.|

**Example**

```ts
let creator: image.ImageCreator = image.createImageCreator(8192, 8, image.ImageFormat.JPEG, 8);
```

## SVG Tags

The SVG tags are supported since API version 10. The used version is (SVG) 1.1, and the width and height of the SVG tag must be set. An XML declaration can be added to an SVG file and start with **<?xml**. The following tags are supported:

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
