# @ohos.multimedia.image (Image Processing)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - Since API version 12, the APIs of this module are supported in ArkTS widgets.

The module provides capabilities for image decoding, encoding, editing, metadata processing, and image receiving.

This module contains the following classes:

- [ImageSource](#imagesource): provides the capabilities of obtaining [image information](#imageinfo), decoding images to PixelMaps or Pictures, and reading and modifying [image properties](#propertykey7). [Supported image formats for decoding](#properties-2) include png, jpeg, bmp, gif, webp, dng, and heic<sup>12+</sup>.

- [ImagePacker](#imagepacker): provides the capability of encoding images into compressed data streams or files. Encoding requires the ImageSource, PixelMap, or Picture of an image as the input. [Supported image formats for encoding](#properties-3) include jpeg, webp, png, heic<sup>12+</sup>, and gif<sup>18+</sup>.

- [PixelMap](#pixelmap7): an object containing pixel data and [image information](#imageinfo). It can be used for reading/writing pixel data and performing operations such as cropping, scaling, translating, rotating, and mirroring. It can also be directly passed to the [Image component](../apis-arkui/arkui-ts/ts-basic-components-image.md) for display. Additionally, it provides APIs for obtaining and setting the color gamut and HDR metadata of images.

- [Picture](#picture13): a multi-picture object composed of a main picture, auxiliary pictures, and metadata. The main picture contains the primary image information; auxiliary pictures store additional information related to the main picture; metadata stores other information related to the image. Picture provides methods for obtaining the main picture, compositing HDR images, obtaining and setting auxiliary pictures, and obtaining and setting metadata.

- [AuxiliaryPicture](#auxiliarypicture13): Auxiliary pictures are used to display special information alongside the main picture, enriching the overall content of the image. The supported types of auxiliary pictures can be found in [AuxiliaryPictureType](#auxiliarypicturetype13).

- [Metadata](#metadata13): used for storing image metadata. The supported metadata types can be found in [MetadataType](#metadatatype13). It includes EXIF metadata and watermark cropping metadata, both stored in Key-Value pairs. The keys for EXIF metadata can be found in [PropertyKey](#propertykey7), and the keys for watermark cropping metadata can be found in [FragmentPropertyKey](#fragmentmappropertykey13).

- [ImageReceiver](#imagereceiver9): acts as a consumer of images, used for receiving and reading images from a surface.

- [ImageCreator](#imagecreator9): acts as a producer of images, used for writing images into a surface.

- [Image](#image9): used by ImageReceiver and ImageCreator for transferring image objects, with the actual content determined by the producer. For example, the Image object provided by a camera preview stream contains YUV data, whereas the Image object provided by a camera photo contains a JPEG file.

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
| mainPixelmap | [PixelMap](#pixelmap7) | Yes  | Main PixelMap.|

**Return value**

| Type              | Description             |
| ------------------ | ----------------- |
| [Picture](#picture13) | Picture object.|

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
| [Picture](#picture13) | Picture object.|

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

Creates a PixelMap object with the default BGRA_8888 format and specified pixel properties. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.<br>If the size of the created PixelMap exceeds that of the original image, the PixelMap size of the original image is returned.|

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

Creates a PixelMap object with the default BGRA_8888 format and specified pixel properties. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options  | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

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

createPixelMapUsingAllocator(colors: ArrayBuffer, options: InitializationOptions, allocatorType?: AllocatorType): Promise\<PixelMap>

Creates a PixelMap object with the specified properties and memory type. By default, the BGRA_8888 format is used to process data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options  | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| allocatorType  | [AllocatorType](#allocatortype15)          | No  | Memory type of the PixelMap. The default memory type is **AllocatorType.AUTO**.<br> 1. **image.AllocatorType.AUTO**: The following formats are not supported this memory type: **UNKNOWN**, **YCBCR_P010**, **YCRCB_P010**, and **ASTC_4x4**. For RGBA_1010102, DMA memory is allocated by default. For other formats (RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16), DMA memory is allocated if the dimensions exceed 512*512; otherwise, shared memory is allocated.<br>2. **image.AllocatorType.DMA**: The formats RGBA_1010102, RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16 support DMA memory types. Other formats do not.<br>3. **image.AllocatorType.SHARED**: The formats UNKNOWN, RGBA_1010102, YCBCR_P010, YCRCB_P010, and ASTC_4x4 do not support shared memory. Other formats support shared memory.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation. e.g.,1. The picture does not has a gainmap. 2. MainPixelMap's allocator type is not DMA. |
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
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.|
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

Creates a PixelMap object based on the surface ID and region information. The size of the region is specified by [Region](#region8).size. This API uses a promise to return the result.

> **NOTE**
>
> When working with foldable devices, switching between folded and unfolded states may cause the API call to fail due to the rotation angle of surface. To address this, you need to adjust the width and height according to the rotation angle. In such cases, [image.createPixelMapFromSurface](#imagecreatepixelmapfromsurface15) is recommended.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which can be obtained through the preview component, for example, [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|
| region                 | [Region](#region8)  | Yes  | Region information. The width and height in [Region](#region8).size must be the same as those of the preview stream.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

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

Creates a PixelMap object based on the surface ID and region information. This API returns the result synchronously. The size of the region is specified by [Region](#region8).size.

> **NOTE**
>
> When working with foldable devices, switching between folded and unfolded states may cause the API call to fail due to the rotation angle of surface. To address this, you need to adjust the width and height according to the rotation angle. In such cases, [image.createPixelMapFromSurfaceSync](#imagecreatepixelmapfromsurfacesync15) is recommended.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                | Mandatory| Description                                    |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | Yes  | Surface ID, which can be obtained through the preview component, for example, [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|
| region                 | [Region](#region8)  | Yes  | Region information. The width and height in [Region](#region8).size must be the same as those of the preview stream.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

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
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

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
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

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

Creates a PixelMap object with the default BGRA_8888 format and specified pixel properties. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

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
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

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

createPixelMapUsingAllocatorSync(colors: ArrayBuffer, options: InitializationOptions, allocatorType?: AllocatorType): PixelMap

Creates a PixelMap object with the specified properties and memory type. By default, the BGRA_8888 format is used to process data. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | Yes  | Buffer for storing the pixel data. It is used to initialize the pixels of the PixelMap. Before initialization, the pixel format in the buffer must be specified by [InitializationOptions](#initializationoptions8).srcPixelFormat.<br>**NOTE**: The length of the buffer required for storing the pixel data is determined by multiplying the width, height, and the number of bytes per pixel.|
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| allocatorType  | [AllocatorType](#allocatortype15)          | No  | Memory type of the PixelMap. The default memory type is **AllocatorType.AUTO**.<br> 1. **image.AllocatorType.AUTO**: The following formats are not supported this memory type: **UNKNOWN**, **YCBCR_P010**, **YCRCB_P010**, and **ASTC_4x4**. For RGBA_1010102, DMA memory is allocated by default. For other formats (RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16), DMA memory is allocated if the dimensions exceed 512*512; otherwise, shared memory is allocated.<br>2. **image.AllocatorType.DMA**: The formats RGBA_1010102, RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16 support DMA memory types. Other formats do not.<br>3. **image.AllocatorType.SHARED**: The formats UNKNOWN, RGBA_1010102, YCBCR_P010, YCRCB_P010, and ASTC_4x4 do not support shared memory. Other formats support shared memory.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation. e.g.,1. The picture does not has a gainmap. 2. MainPixelMap's allocator type is not DMA. |
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

createPixelMapUsingAllocatorSync(options: InitializationOptions, allocatorType?: AllocatorType): PixelMap

Creates a PixelMap object with the specified pixel properties. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                                            | Mandatory| Description                                                            |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|
| allocatorType  | [AllocatorType](#allocatortype15)          | No  | Memory type of the PixelMap. The default memory type is **AllocatorType.AUTO**.<br> 1. **image.AllocatorType.AUTO**: The following formats are not supported for this memory type: UNKNOWN and ASTC_4x4. For RGBA_1010102, YCBCR_P010, and YCRCB_P010, DMA memory is allocated by default. For other formats (RGB_565, RGBA_8888, BGRA_8888, and RGBAF_16), DMA memory is allocated if the dimensions exceed 512*512; otherwise, shared memory is allocated.<br>2. **image.AllocatorType.DMA**: The formats RGB_565, RGBA_8888, BGRA_8888, RGBAF_16, RGBA_1010102, YCBCR_P010, and YCRCB_P010 support DMA memory type. Other formats do not support DMA memory type.<br>3. **image.AllocatorType.SHARED**: The formats UNKNOWN, RGBA_1010102, YCBCR_P010, YCRCB_P010, and ASTC_4x4 do not support shared memory. Other formats support shared memory.|

**Return value**
| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation. e.g.,1. The picture does not has a gainmap. 2. MainPixelMap's allocator type is not DMA. |
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
| src | [PixelMap](#pixelmap7) | Yes  | Source PixelMap object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target PixelMap object.|
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
| src | [PixelMap](#pixelmap7) | Yes  | Source PixelMap object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target PixelMap object.|

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
| src | [PixelMap](#pixelmap7) | Yes  | Source PixelMap object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target PixelMap object.|
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
| src | [PixelMap](#pixelmap7) | Yes  | Source PixelMap object.|
| dst | [PixelMap](#pixelmap7) | Yes  | Target PixelMap object.|

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


## Picture<sup>13+</sup>

An image that contains special information can be decoded into a picture object, which generally contains the main picture, auxiliary picture, and metadata. The main picture contains most information about the image and is mainly used to render the image. The auxiliary picture is used to store data related to but different from the main picture, revealing more comprehensive details. The metadata is generally used to store information about the image file. The picture object class is used to read or write picture objects. Before calling any API in Picture, you must use [createPicture](#imagecreatepicture13) to create a Picture object.

### Properties

**System capability**: SystemCapability.Multimedia.Image.Core

### getMainPixelmap<sup>13+</sup>

getMainPixelmap(): PixelMap

Obtains the PixelMap object of the main picture. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type               | Description                  |
| ------------------- | ---------------------- |
| [PixelMap](#pixelmap7) | PixelMap object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetMainPixelmap() {
  let funcName = "getMainPixelmap";
  if (pictureObj != null) {
    let mainPixelmap: image.PixelMap = pictureObj.getMainPixelmap();
    if (mainPixelmap != null) {
      mainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info('GetMainPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed error.code: ${error.code} ,error.message: ${error.message}');
      });
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

### getHdrComposedPixelmap<sup>13+</sup>

getHdrComposedPixelmap(): Promise\<PixelMap>

Generates a High Dynamic Range (HDR) image and obtains its PixelMap object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                         | Description                       |
| ----------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 7600901  | Inner unknown error. Please check the logs for detailed information. |
| 7600201  | Unsupported operation. e.g.,1. The picture does not has a gainmap. 2. MainPixelMap's allocator type is not DMA. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetHdrComposedPixelmap() {
  let funcName = "getHdrComposedPixelmap";
  if (pictureObj != null) { // An HDR image is contained.
    let hdrComposedPixelmap: image.PixelMap = await pictureObj.getHdrComposedPixelmap();
    if (hdrComposedPixelmap != null) {
      hdrComposedPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info('GetHdrComposedPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed error.code: ${error.code} ,error.message: ${error.message}');
      });
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

### getGainmapPixelmap<sup>13+</sup>

getGainmapPixelmap(): PixelMap | null

Obtains the PixelMap object of the gain map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                     | Description                                  |
| ------------------------- | -------------------------------------- |
| [PixelMap](#pixelmap7) \| null | PixelMap object obtained. If there is no PixelMap object, null is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetGainmapPixelmap() {
  let funcName = "getGainmapPixelmap";
  if (pictureObj != null) { // A gain map is contained.
    let gainPixelmap: image.PixelMap | null = pictureObj.getGainmapPixelmap();
    if (gainPixelmap != null) {
      gainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info('GetGainmapPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
        } else {
          console.error('GainPixelmap is null');
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed error.code: ${error.code} ,error.message: ${error.message}');
      });
    } else {
      console.info('GainPixelmap is null');
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

### setAuxiliaryPicture<sup>13+</sup>

setAuxiliaryPicture(type: AuxiliaryPictureType, auxiliaryPicture: AuxiliaryPicture): void

Sets an auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name          | Type                | Mandatory| Description        |
| ---------------- | -------------------- | ---- | ------------ |
| type             | [AuxiliaryPictureType](#auxiliarypicturetype13) | Yes  | Type of the auxiliary picture.|
| auxiliaryPicture | [AuxiliaryPicture](#auxiliarypicture13)     | Yes  | AuxiliaryPicture object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function SetAuxiliaryPicture(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // Support for HDR images is required.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let pixelMap: image.PixelMap = await imageSource.createPixelMap();
  let auxPicture: image.Picture = image.createPicture(pixelMap);
  if (auxPicture != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }

  if (pictureObj != null) {
    let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
    let auxPictureObj: image.AuxiliaryPicture | null = await auxPicture.getAuxiliaryPicture(type);
    if (auxPictureObj != null) {
      pictureObj.setAuxiliaryPicture(type, auxPictureObj);
    }
  }
}
```

### getAuxiliaryPicture<sup>13+</sup>

getAuxiliaryPicture(type: AuxiliaryPictureType): AuxiliaryPicture | null

Obtains an auxiliary picture by type.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                | Mandatory| Description        |
| ------ | -------------------- | ---- | ------------ |
| type   | [AuxiliaryPictureType](#auxiliarypicturetype13) | Yes  | Type of the auxiliary picture.|

**Return value**

| Type                  | Description                                          |
| ---------------------- | ---------------------------------------------- |
| [AuxiliaryPicture](#auxiliarypicture13) \| null | AuxiliaryPicture object. If there is no AuxiliaryPicture object, null is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function GetAuxiliaryPicture() {
  if (pictureObj != null) {
    let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
    let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(type);
  }
}
```

### setMetadata<sup>13+</sup>

setMetadata(metadataType: MetadataType, metadata: Metadata): Promise\<void>

Sets the metadata for this Picture object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type        | Mandatory| Description        |
| ------------ | ------------ | ---- | ------------ |
| metadataType | [MetadataType](#metadatatype13) | Yes  | Metadata type.|
| metadata     | [Metadata](#metadata13)     | Yes  | Metadata object.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function SetPictureObjMetadata(exifContext: Context) {
  const exifResourceMgr = exifContext.resourceManager;
  const exifRawFile = await exifResourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
  let exifOps: image.SourceOptions = {
    sourceDensity: 98,
  }
  let exifImageSource: image.ImageSource = image.createImageSource(exifRawFile.buffer as ArrayBuffer, exifOps);
  let exifCommodityPixelMap: image.PixelMap = await exifImageSource.createPixelMap();
  let exifPictureObj: image.Picture = image.createPicture(exifCommodityPixelMap);
  if (exifPictureObj != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }

  if (pictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let exifMetaData: image.Metadata = await exifPictureObj.getMetadata(metadataType);
    pictureObj.setMetadata(metadataType, exifMetaData).then(() => {
      console.info('Set metadata success');
    }).catch((error: BusinessError) => {
      console.error('Failed to set metadata. error.code: ' +JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
    });
  } else {
    console.error('PictureObj is null');
  }
}
```

### getMetadata<sup>13+</sup>

getMetadata(metadataType: MetadataType): Promise\<Metadata>

Obtains the metadata of this Picture object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type        | Mandatory| Description        |
| ------------ | ------------ | ---- | ------------ |
| metadataType | [MetadataType](#metadatatype13) | Yes  | Metadata type.|

**Return value**

| Type              | Description                     |
| ------------------ | ------------------------- |
| Promise\<[Metadata](#metadata13)> | Promise used to return the metadata.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function GetPictureObjMetadataProperties() {
  if (pictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let pictureObjMetaData: image.Metadata = await pictureObj.getMetadata(metadataType);
    if (pictureObjMetaData != null) {
      console.info('get picture metadata success');
    } else {
      console.error('get picture metadata is failed');
    }
  } else {
    console.error(" pictureObj is null");
  }
}
```

### marshalling<sup>13+</sup>

marshalling(sequence: rpc.MessageSequence): void

Marshals this Picture object and writes it to a MessageSequence object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                                               | Mandatory| Description                     |
| -------- | ------------------------------------------------------------------- | ---- | ------------------------- |
| sequence | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.                                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

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

async function Marshalling_UnMarshalling() {
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

### release<sup>13+</sup>

release(): void

Releases this Picture object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Example**

```ts
import { image } from '@kit.ImageKit';

async function Release() {
  let funcName = "Release";
  if (pictureObj != null) {
    pictureObj.release();
    if (pictureObj.getMainPixelmap() == null) {
      console.info(funcName, 'Success !');
    } else {
      console.error(funcName, 'Failed !');
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

## PixelMap<sup>7+</sup>

Provides APIs to read or write image data and obtain image information. Before calling any API in PixelMap, you must use [createPixelMap](#imagecreatepixelmap8) to create a PixelMap object. Currently, the maximum size of a serialized PixelMap is 128 MB. A larger size will cause a display failure. The size is calculated as follows: Width * Height * Number of bytes occupied by each pixel.

Since API version 11, PixelMap supports cross-thread calls through workers. If a PixelMap object is invoked by another thread through [Worker](../apis-arkts/js-apis-worker.md), all APIs of the PixelMap object cannot be called in the original thread. Otherwise, error 501 is reported, indicating that the server cannot complete the request. 

Before calling any API in PixelMap, you must use [image.createPixelMap](#imagecreatepixelmap8) to create a PixelMap object.

To develop an atomic service, use [ImageSoure](#imagesource) to create a PixelMap object.

### Properties

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Type   | Read Only| Optional| Description                      |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable        | boolean | Yes  | No  | Whether the PixelMap is editable. The value **true** means that the PixelMap is editable, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| isStrideAlignment<sup>11+</sup> | boolean | Yes  | No  | Whether the PixelMap uses DMA memory. The value** true** means that the PixelMap uses DMA memory, and **false** means the opposite.|

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

Reads the pixels of this PixelMap object based on the PixelMap's pixel format and writes the data to the buffer. This API uses a promise to return the result.

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
import { image } from '@kit.ImageKit';

async function ReadPixelsToBuffer(pixelMap : image.PixelMap) {
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

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads the pixels of this PixelMap object based on the PixelMap's pixel format and writes the data to the buffer. This API uses an asynchronous callback to return the result.

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
import { image } from '@kit.ImageKit';

async function ReadPixelsToBuffer(pixelMap : image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
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

Reads the pixels of this PixelMap object based on the PixelMap's pixel format and writes the data to the buffer. This API returns the result synchronously.

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
import { image } from '@kit.ImageKit';

async function ReadPixelsToBufferSync(pixelMap : image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBufferSync(readBuffer);
  }
}
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

Reads the pixels in the area specified by [PositionArea](#positionarea7).region of this PixelMap object in the BGRA_8888 format and writes the data to the [PositionArea](#positionarea7).pixels buffer. This API uses a promise to return the result.

You can use a formula to calculate the size of the memory to be applied for based on **PositionArea**.

YUV region calculation formula: region to read (region.size{width * height}) * 1.5 (1 * Y component + 0.25 * U component + 0.25 * V component)

RGBA region calculation formula: region to read (region.size{width * height}) * 4 (1 * R component + 1 * G component + 1 * B component + 1 * A component)

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
import { image } from '@kit.ImageKit';

async function ReadPixelsRGBA(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 4.
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

async function ReadPixelsYUV(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6),  // 6 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 1.5.
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
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

### readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

Reads the pixels in the area specified by [PositionArea](#positionarea7).region of this PixelMap object in the BGRA_8888 format and writes the data to the [PositionArea](#positionarea7).pixels buffer. This API uses an asynchronous callback to return the result.

You can use a formula to calculate the size of the memory to be applied for based on **PositionArea**.

YUV region calculation formula: region to read (region.size{width * height}) * 1.5 (1 * Y component + 0.25 * U component + 0.25 * V component)

RGBA region calculation formula: region to read (region.size{width * height}) * 4 (1 * R component + 1 * G component + 1 * B component + 1 * A component)

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
import { image } from '@kit.ImageKit';

async function ReadPixelsRGBA(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 4.
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

async function ReadPixelsYUV(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6),  // 6 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 1.5.
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
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

Reads the pixels in the area specified by [PositionArea](#positionarea7).region of this PixelMap object in the BGRA_8888 format and writes the data to the [PositionArea](#positionarea7).pixels buffer. This API returns the result synchronously.

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

async function ReadPixelsSync(pixelMap : image.PixelMap) {
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

Reads the pixels in the [PositionArea](#positionarea7).pixels buffer in the BGRA_8888 format and writes the data to the area specified by [PositionArea](#positionarea7).region in this PixelMap object. This API uses a promise to return the result.

You can use a formula to calculate the size of the memory to be applied for based on **PositionArea**.

YUV region calculation formula: region to read (region.size{width * height}) * 1.5 (1 * Y component + 0.25 * U component + 0.25 * V component)

RGBA region calculation formula: region to read (region.size{width * height}) * 4 (1 * R component + 1 * G component + 1 * B component + 1 * A component)

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

async function WritePixelsRGBA() {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 4.
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

async function WritePixelsYUV() {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6),  // 6 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 1.5.
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
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

Reads the pixels in the [PositionArea](#positionarea7).pixels buffer in the BGRA_8888 format and writes the data to the area specified by [PositionArea](#positionarea7).region in this PixelMap object. This API uses an asynchronous callback to return the result.

You can use a formula to calculate the size of the memory to be applied for based on **PositionArea**.

YUV region calculation formula: region to read (region.size{width * height}) * 1.5 (1 * Y component + 0.25 * U component + 0.25 * V component)

RGBA region calculation formula: region to read (region.size{width * height}) * 4 (1 * R component + 1 * G component + 1 * B component + 1 * A component)

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

async function WritePixelsRGBA() {
  const area: image.PositionArea = { pixels: new ArrayBuffer(8), // 8 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 4.
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

async function WritePixelsYUV() {
  const area: image.PositionArea = { pixels: new ArrayBuffer(6), // 6 is the size of the PixelMap buffer to create. The value is calculated as follows: height * width * 1.5.
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
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

Reads the pixels in the [PositionArea](#positionarea7).pixels buffer in the BGRA_8888 format and writes the data to the area specified by [PositionArea](#positionarea7).region in this PixelMap object. This API returns the result synchronously.

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

async function WritePixelsSync() {
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

Reads the pixels in the buffer based on the PixelMap's pixel format and writes the data to this PixelMap object. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Buffer from which the pixels are read. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber7).|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteBufferToPixels() {
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

### writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads the pixels in the buffer based on the PixelMap's pixel format and writes the data to this PixelMap object. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | Yes  | Buffer from which the pixels are read. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber7).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the pixels in the buffer are successfully written to the PixelMap, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteBufferToPixels() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
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

Reads the pixels in the buffer based on the PixelMap's pixel format and writes the data to this PixelMap object. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Buffer from which the pixels are read. The buffer size is obtained by calling [getPixelBytesNumber](#getpixelbytesnumber7).|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteBufferToPixelsSync() {
  const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
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

async function GetImageInfo() {
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

async function GetImageInfo() {
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

async function GetImageInfoSync() {
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

Obtains the pixel density of this image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description           |
| ------ | --------------- |
| number | Pixel density, in ppi.|

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
| rate     | number               | Yes  | Opacity rate. The value range is (0,1]. |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Opacity() {
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
| rate   | number | Yes  | Opacity rate. The value range is (0,1].|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Opacity() {
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
| rate     | number               | Yes  | Opacity rate. The value range is (0,1].  |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function OpacitySync() {
  let rate : number = 0.5;
  if (pixelMap != undefined) {
    pixelMap.opacitySync(rate);
  }
}
```

### createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

Creates a PixelMap object that contains only the alpha channel information. This object can be used for the shadow effect. This API uses a promise to return the result. It is invalid for YUV images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                       |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateAlphaPixelmap() {
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

Creates a PixelMap object that contains only the alpha channel information. This object can be used for the shadow effect. This API uses an asynchronous callback to return the result. It is invalid for YUV images.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                    |
| -------- | ------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)> | Yes  |  Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateAlphaPixelmap() {
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

Creates a PixelMap object that contains only the alpha channel information. This object can be used for the shadow effect. This API returns the result synchronously. It is invalid for YUV images.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateAlphaPixelmapSync() {
  if (pixelMap != undefined) {
    let pixelmap : image.PixelMap = pixelMap.createAlphaPixelmapSync();
    return pixelmap;
  }
  return undefined;
}
```

### scale<sup>9+</sup>

scale(x: number, y: number, callback: AsyncCallback\<void>): void

Scales this image based on the scale factors of the width and height. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You are advised to set the scale factors to non-negative numbers to avoid a flipping effect.
>
> Scale factors of the width and height = Width and height of the resized image/Width and height of the original image

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | Yes  | Scale factor of the width.|
| y        | number               | Yes  | Scale factor of the height.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Scale() {
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

Scales this image based on the scale factors of the width and height. This API uses a promise to return the result.

> **NOTE**
>
> You are advised to set the scale factors to non-negative numbers to avoid a flipping effect.
>
> Scale factors of the width and height = Width and height of the resized image/Width and height of the original image

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Scale() {
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

Scales this image based on the scale factors of the width and height. This API returns the result synchronously.

> **NOTE**
>
> You are advised to set the scale factors to non-negative numbers to avoid a flipping effect.
>
> Scale factors of the width and height = Width and height of the resized image/Width and height of the original image

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ScaleSync() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scaleSync(scaleX, scaleY);
  }
}
```

### scale<sup>12+</sup>

scale(x: number, y: number, level: AntiAliasingLevel): Promise\<void>

Scales this image based on the specified anti-aliasing level and the scale factors for the width and height. This API uses a promise to return the result.

> **NOTE**
>
> You are advised to set the scale factors to non-negative numbers to avoid a flipping effect.
>
> Scale factors of the width and height = Width and height of the resized image/Width and height of the original image

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|
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

async function Scale() {
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

Scales this image based on the specified anti-aliasing level and the scale factors for the width and height. This API returns the result synchronously.

> **NOTE**
>
> You are advised to set the scale factors to non-negative numbers to avoid a flipping effect.
>
> Scale factors of the width and height = Width and height of the resized image/Width and height of the original image

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|
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

async function ScaleSync() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scaleSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
  }
}
```

### createScaledPixelMap<sup>18+</sup>

createScaledPixelMap(x: number, y: number, level?: AntiAliasingLevel): Promise\<PixelMap>

Creates an image that has been resized based on the specified anti-aliasing level and the scale factors of the width and height. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|
| level  | [AntiAliasingLevel](#antialiasinglevel12) | No  | Anti-aliasing level.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateScaledPixelMap() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
      pixelMap.createScaledPixelMap(scaleX, scaleY, image.AntiAliasingLevel.LOW).then((scaledPixelMap: image.PixelMap) => {
      console.info('Succeeded in creating scaledPixelMap.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to create scaledPixelMap. Error code is ${error.code}, error message is ${error.message}`);
    })
  }
}
```

### createScaledPixelMapSync<sup>18+</sup>

createScaledPixelMapSync(x: number, y: number, level?: AntiAliasingLevel): PixelMap

Creates an image that has been resized based on the specified anti-aliasing level and the scale factors of the width and height. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width.|
| y      | number | Yes  | Scale factor of the height.|
| level  | [AntiAliasingLevel](#antialiasinglevel12) | No  | Anti-aliasing level.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateScaledPixelMapSync() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    let scaledPixelMap = pixelMap.createScaledPixelMapSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
  }
}
```

### clone<sup>18+</sup>

clone(): Promise\<PixelMap>

Copies this PixelMap object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of createing empty pixelmap. |
| 62980106 | The image data is to large. This status code is thrown when an error occurs during the process of checking size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.clone().then((clonePixelMap: image.PixelMap) => {
      console.info('Succeeded clone pixelmap.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to clone pixelmap. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

### cloneSync<sup>18+</sup>

cloneSync(): PixelMap

Copies this PixelMap object. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------------- |
| [PixelMap](#pixelmap7) | PixelMap object. If the operation fails, an error is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of createing empty pixelmap. |
| 62980106 | The image data is to large. This status code is thrown when an error occurs during the process of checking size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(pixelMap: image.PixelMap) {
  if (pixelMap != undefined) {
    try {
      let clonedPixelMap = pixelMap.cloneSync();
    } catch(e) {
      let error = e as BusinessError;
      console.error(`clone pixelmap error. code is ${error.code}, message is ${error.message}`);
    }
  }
}
```

### translate<sup>9+</sup>

translate(x: number, y: number, callback: AsyncCallback\<void>): void

Translates this image based on given coordinates. This API uses an asynchronous callback to return the result.

The size of the translated image is changed to width+X and height+Y. It is recommended that the new width and height not exceed the width and height of the screen.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| x        | number               | Yes  | X coordinate to translate, in px.|
| y        | number               | Yes  | Y coordinate to translate, in px.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Translate() {
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

The size of the translated image is changed to width+X and height+Y. It is recommended that the new width and height not exceed the width and height of the screen.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| x      | number | Yes  | X coordinate to translate, in px.|
| y      | number | Yes  | Y coordinate to translate, in px.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Translate() {
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

The size of the translated image is changed to width+X and height+Y. It is recommended that the new width and height not exceed the width and height of the screen.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | Yes  | X coordinate to translate, in px.|
| y        | number               | Yes  | Y coordinate to translate, in px.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function TranslateSync() {
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

> **NOTE**
>
> The allowable range for image rotation angles is between 0 and 360 degrees. Angles outside this range are automatically adjusted according to the 360-degree cycle. For example, an angle of -100 degrees will produce the same result as 260 degrees.
>
> If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Angle to rotate.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Rotate() {
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

> **NOTE**
>
> The allowable range for image rotation angles is between 0 and 360 degrees. Angles outside this range are automatically adjusted according to the 360-degree cycle. For example, an angle of -100 degrees will produce the same result as 260 degrees.
>
> If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                         |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | Yes  | Angle to rotate.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Rotate() {
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

> **NOTE**
>
> The allowable range for image rotation angles is between 0 and 360 degrees. Angles outside this range are automatically adjusted according to the 360-degree cycle. For example, an angle of -100 degrees will produce the same result as 260 degrees.
>
> If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Angle to rotate.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function RotateSync() {
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
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. The value **true** means to flip the image horizontally, and **false** means the opposite.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. The value **true** means to flip the image vertically, and **false** means the opposite.           |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Flip() {
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
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. The value **true** means to flip the image horizontally, and **false** means the opposite.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. The value **true** means to flip the image vertically, and **false** means the opposite.           |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Flip() {
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
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. The value **true** means to flip the image horizontally, and **false** means the opposite.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. The value **true** means to flip the image vertically, and **false** means the opposite.           |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function FlipSync() {
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
| region   | [Region](#region8)   | Yes  | Size of the image after cropping. The value cannot exceed the width or height of the image.|
| callback | AsyncCallback\<void> | Yes  |  Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Crop() {
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
| region | [Region](#region8) | Yes  | Size of the image after cropping. The value cannot exceed the width or height of the image.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Crop() {
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
| region   | [Region](#region8)   | Yes  | Size of the image after cropping. The value cannot exceed the width or height of the image.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CropSync() {
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
async function GetColorSpace() {
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
| 62980111| The image source data is incomplete.        |
| 62980115| If the image parameter invalid.             |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
async function SetColorSpace() {
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
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

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

async function ApplyColorSpace() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.applyColorSpace(targetColorSpace, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to apply color space for pixelmap object, error code is ${error}`);
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

async function ApplyColorSpace() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.applyColorSpace(targetColorSpace).then(() => {
      console.info('Succeeded in applying color space for pixelmap object.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to apply color space for pixelmap object, error code is ${error}`);
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

<!--code_no_check-->
```ts
import image from '@ohos.multimedia.image';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'hdr.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let img = context.resourceManager.getMediaContentSync($r('app.media.hdr'));
let imageSource = image.createImageSource(img.buffer.slice(0));
let decodingOptions: image.DecodingOptions = {
  desiredDynamicRange: image.DecodingDynamicRange.AUTO
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
  pixelmap.toSdr().then(() => {
    let imageInfo = pixelmap.getImageInfoSync();
    console.info("after toSdr ,imageInfo isHdr:" + imageInfo.isHdr);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set sdr. code is ${err.code}, message is ${err.message}`);
  });
} else {
  console.error('Failed to create pixelMap.');
}
```

### getMetadata<sup>12+</sup>

getMetadata(key: HdrMetadataKey): HdrMetadataValue

Obtains the value of the metadata with a given key in this PixelMap.

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
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.          |

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// Replace 'app.media.test' with a local HDR image.
let img = context.resourceManager.getMediaContentSync($r('app.media.test'));
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
    console.error('pixelmap create failed' + e);
  }
} else {
  console.error('Failed to create pixelMap.');
}
```

### setMetadata<sup>12+</sup>

setMetadata(key: HdrMetadataKey, value: HdrMetadataValue): Promise\<void>

Sets the value for the metadata with a given key in this PixelMap.

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
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.         |

**Example**

```ts
import image from '@ohos.multimedia.image';
import { BusinessError } from '@kit.BasicServicesKit';

let staticMetadata: image.HdrStaticMetadata = {
  displayPrimariesX: [1.1, 1.1, 1.1],
  displayPrimariesY: [1.2, 1.2, 1.2],
  whitePointX: 1.1,
  whitePointY: 1.2,
  maxLuminance: 2.1,
  minLuminance: 1.0,
  maxContentLightLevel: 2.1,
  maxFrameAverageLightLevel: 2.1,
};
const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } };
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  pixelMap.setMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA, staticMetadata).then(() => {
    console.info('Succeeded in setting pixelMap metadata.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to set the metadata.code ${error.code},message is ${error.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create the PixelMap.code ${error.code},message is ${error.message}`);
})

```

### setTransferDetached<sup>12+<sup>

setTransferDetached(detached: boolean): void

Sets whether to detach from the original thread when this PixelMap is transmitted across threads. This API applies to the scenario where the PixelMap needs to be released immediately.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type              | Mandatory| Description                         |
| ------- | ------------------ | ---- | ----------------------------- |
| detached | boolean   | Yes  | Whether to detach from the original thread. The value **true** means to detach from the original thread, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';
import taskpool from '@ohos.taskpool';

@Concurrent
// Child thread method.
async function loadPixelMap(rawFileDescriptor: number): Promise<PixelMap> {
  // Create an ImageSource instance.
  const imageSource = image.createImageSource(rawFileDescriptor);
  // Create a pixelMap.
  const pixelMap = imageSource.createPixelMapSync();
  // Release the ImageSource instance.
  imageSource.release();
  // Disconnect the reference of the original thread after the cross-thread transfer of the pixelMap is complete.
  pixelMap.setTransferDetached(true);
  // Return the pixelMap to the main thread.
  return pixelMap;
}

@Component
struct Demo {
  @State pixelMap: PixelMap | undefined = undefined;
  // Main thread method.
  private loadImageFromThread(): void {
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    const resourceMgr = context.resourceManager;
    // 'example.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
    resourceMgr.getRawFd('example.jpg').then(rawFileDescriptor => {
      taskpool.execute(loadPixelMap, rawFileDescriptor).then(pixelMap => {
        if (pixelMap) {
          this.pixelMap = pixelMap as PixelMap;
          console.log('Succeeded in creating pixelMap.');
          // The main thread releases the pixelMap. Because setTransferDetached has been called when the child thread returns pixelMap, the pixelMap can be released immediately.
          this.pixelMap.release();
        } else {
          console.error('Failed to create pixelMap.');
        }
      });
    });
  }
  build() {
    // ...
  }
}
```

### marshalling<sup>10+</sup>

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
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.            |

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
async function Marshalling() {
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

Unmarshals a MessageSequence object to obtain a PixelMap object.
To create a PixelMap object in synchronous mode, use [createPixelMapFromParcel](#imagecreatepixelmapfromparcel11).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object that stores the PixelMap information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> |Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.              |
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.         |

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
async function Unmarshalling() {
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

Releases this PixelMap object. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the PixelMap object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

async function Release() {
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

Releases this PixelMap object. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the PixelMap object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

async function Release() {
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

### convertPixelFormat<sup>12+</sup>

convertPixelFormat(targetPixelFormat: PixelMapFormat): Promise\<void>

Performs a conversion between YUV and RGB formats. Currently, only conversion between NV12/NV21 and RGB888/RGBA8888/RGB565/BGRA8888/RGBAF16 and conversion between YCRCB_P010/YCBCR_P010 and RGBA1010102 are supported.

Since API version 18, this API can be used for conversion from ASTC_4x4 to RGBA_8888.

> **NOTE**
>
> Call this API to convert the format from ASTC_4x4 to RGBA_8888 only when you need to access pixels of images in ASTC_4x4 format. The conversion from ASTC_4x4 to RGBA_8888 is slow and is not recommended in other cases.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| targetPixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Target pixel format. Currently, only conversion between NV12/NV21 and RGB888/RGBA8888/RGB565/BGRA8888/RGBAF16, conversion between YCRCB_P010/YCBCR_P010 and RGBA1010102, and conversion from ASTC_4x4 to RGBA_8888 are supported.|

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980111 | The image source data is incomplete. |
| 62980115 | Invalid input parameter.              |
| 62980178 | Failed to create the pixelmap. |
| 62980274 | The conversion failed |
| 62980276 | The type to be converted is an unsupported target pixel format|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (pixelMap != undefined) {
  // Set the target pixel format to NV12.
  let targetPixelFormat = image.PixelMapFormat.NV12;
  pixelMap.convertPixelFormat(targetPixelFormat).then(() => {
    // The pixelMap is converted to the NV12 format.
    console.info('PixelMapFormat convert Succeeded');
  }).catch((error: BusinessError) => {
    // The pixelMap fails to be converted to the NV12 format.
    console.error(`PixelMapFormat convert Failed. code is ${error.code}, message is ${error.message}`);
  })
}
```

### setMemoryNameSync<sup>13+</sup>

setMemoryNameSync(name: string): void

Sets a memory name for this PixelMap.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| name | string | Yes  | Memory name, which can be set only for a PixelMap with the DMA or ASHMEM memory format. The length ranges from 1 to 31 bits.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.The length of the input parameter is too long. 2.Parameter verification failed. |
| 501 | Resource unavailable. |
| 62980286 | Memory format not supported. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function SetMemoryNameSync() {
  if (pixelMap != undefined) {
    try {
      pixelMap.setMemoryNameSync("PixelMapName Test");
    } catch(e) {
      let error = e as BusinessError;
      console.error(`setMemoryNameSync error. code is ${error.code}, message is ${error.message}`);
    }
  }
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
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

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
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

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
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

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
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

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

Creates an ImageSource instance based on buffers. The data passed by **buf** must be undecoded. Do not pass the pixel buffer data such as RBGA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [image.createPixelMapSync](#createpixelmapsync12).

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
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|


**Example**

```ts
const buf: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
const imageSourceApi: image.ImageSource = image.createImageSource(buf);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource

Creates an ImageSource instance based on buffers. The data passed by **buf** must be undecoded. Do not pass the pixel buffer data such as RBGA and YUV. If you want to create a PixelMap based on the pixel buffer data, call [image.createPixelMapSync](#createpixelmapsync12).

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
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

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
| options | [SourceOptions](#sourceoptions9) | No| Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

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
- Obtaining image information: Call [getImageInfo](#getimageinfo) to obtain image information by index, or call [getImageInfo](#getimageinfo-1) to directly obtain image information.
- Obtaining an image property: Call [getImageProperty](#getimageproperty11) to obtain the value of a property with the specified index in an image.
- Obtaining image properties: Call [getImageProperties](#getimageproperties12) to obtain the values of properties with the given names in an image.
- Updating incremental data: Call [updateData](#updatedata9) to update data.
- Creating a PixelMap object: Call [createPixelMap](#createpixelmap7) or [createPixelMap](#createpixelmap7-2) to create a PixelMap based on decoding options, or call [createPixelMap](#createpixelmap7-1) to create a PixelMap based on default parameters.
- Releasing an ImageSource instance: Call [release](#release) to release an image source.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type       | Mandatory| Description     |
| ------- | ------------| ---- | ----------|
| buf     | ArrayBuffer | Yes  | Incremental data.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon')); // Obtain the image resource.
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
| options | [SourceOptions](#sourceoptions9) | No  | Image properties, including the image pixel density, pixel format, and image size.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [ImageSource](#imagesource) | ImageSource instance. If the operation fails, undefined is returned.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon')) // Obtain the image resource.
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

## ImageSource

Provides APIs to obtain image information. Before calling any API in ImageSource, you must use [createImageSource](#imagecreateimagesource) to create an ImageSource instance.

### Properties

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name            | Type          | Read Only| Optional| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported formats, including .png, .jpeg, .bmp, .gif, .webp, .dng., and .heic<sup>12+</sup> (depending on the hardware).|

### getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

Obtains information about an image with the specified index. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | Yes  | Index of the image source. The default value is **0**, indicating the first image. If this parameter is set to N, the (N-1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).                  |
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
| index | number | No  | Index of the image source. The default value is **0**, indicating the first image. If this parameter is set to N, the (N-1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](#imageinfo)> | Promise used to return the image information.|

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
| index | number | No  | Index of the image source. The default value is **0**, indicating the first image. If this parameter is set to N, the (N-1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| [ImageInfo](#imageinfo) | Image information.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { image } from '@kit.ImageKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result. This API applies only to images that are in JPEG, PNG, or HEIF<sup>12+</sup> (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

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
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980103 | The image data is not supported.         |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.       |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980116| Failed to decode the image.            |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.   |
| 62980123| The image does not support EXIF decoding. |
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

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result. This API applies only to images that are in JPEG, PNG, or HEIF<sup>12+</sup> (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

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

Obtains the value of a property with the specified index in this image. This API uses an asynchronous callback to return the result. This API applies only to images that are in JPEG, PNG, or HEIF<sup>12+</sup> (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

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

Obtains the value of a property in this image. This API uses an asynchronous callback to return the result. This API applies only to images that are in JPEG, PNG, or HEIF<sup>12+</sup> (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

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

Obtains the values of properties with the given names in this image. This API uses a promise to return the result. This API applies only to images that are in JPEG, PNG, or HEIF (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

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
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110| The image source data is incorrect.            |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
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

### getImagePropertySync<sup>20+</sup>

getImagePropertySync(key:PropertyKey): string

Obtains the value of a specified EXIF property. This API returns the property value in a string.

>**NOTE**
>
> This API applies only to images that are in JPEG, PNG, or HEIF (depending on the hardware) format and contain the EXIF information.
>
> EXIF information is metadata of the image, including shooting time, camera model, aperture, focal length, and ISO.


**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | [PropertyKey](#propertykey7)                                               | Yes  | Name of the property.                        |

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| string | Value of the specified EXIF property. If retrieval fails, the default value of the property is returned. For details about the meaning of each data value, see [PropertyKey](#propertykey7).|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).
| ID| Error Message|
| ------- | --------------------------------------------|
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed.|
| 7700102 | Unsupported MIME type.|
| 7700202 | Unsupported metadata. For example, key is not supported.|

**Example**

<!--code_no_check-->
```ts
import { image } from '@kit.ImageKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let resourceMgr = context.resourceManager;
if (resourceMgr == null) {
  return;
}
let fd = resourceMgr.getRawFdSync("example.jpg");

const imageSourceApi = image.createImageSource(fd);
console.info("getImagePropertySync");
let bits_per_sample = imageSourceApi.getImagePropertySync(image.PropertyKey.BITS_PER_SAMPLE);
console.info("bits_per_sample : " + bits_per_sample);
```

### modifyImageProperty<sup>11+</sup>

modifyImageProperty(key: PropertyKey, value: string): Promise\<void>

Modifies the value of a property in this image. This API uses a promise to return the result. This API applies only to images that are in JPEG, PNG, or HEIF<sup>12+</sup> (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.

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
| 62980123| The image does not support EXIF decoding.             |
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

Modifies the value of a property in this image. This API uses a promise to return the result. This API applies only to images that are in JPEG, PNG, or HEIF<sup>12+</sup> (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.
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

Modifies the value of a property in this image. This API uses an asynchronous callback to return the result. This API applies only to images that are in JPEG, PNG, or HEIF<sup>12+</sup> (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.
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

Modifies the values of properties in this image. This API uses a promise to return the result. This API applies only to images that are in JPEG, PNG, or HEIF (depending on the hardware) format and contain the EXIF information. You can use the **supportedFormats** property to check whether the EXIF read/write operation for images in HEIF format is supported.

> **NOTE**
>
> The property byte length is changed when the **modifyImageProperties** API is called to modify the values of properties. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.
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
| 62980123| The image does not support EXIF decoding.             |
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
| buf        | ArrayBuffer         | Yes  | Buffer for storing the incremental data.          |
| isFinished | boolean             | Yes  | Whether data update is complete. The value **true** means that the data update is complete and the last segment of data is stored in the buffer. The value **false** means that the data update is still in progress.|
| offset      | number              | Yes  | Offset of the data in the buffer, measured from the start of the entire image file, in bytes.            |
| length     | number              | Yes  | Length of the buffer, in bytes.           |

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
| buf        | ArrayBuffer         | Yes  | Buffer for storing the incremental data.          |
| isFinished | boolean             | Yes  | Whether data update is complete. The value **true** means that the data update is complete and the last segment of data is stored in the buffer. The value **false** means that the data update is still in progress.|
| offset      | number              | Yes  | Offset of the data in the buffer, measured from the start of the entire image file, in bytes.            |
| length     | number              | Yes  | Length of the buffer, in bytes.           |
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

### createPicture<sup>13+</sup>

createPicture(options?: DecodingOptionsForPicture): Promise\<Picture>

Creates a Picture object based on decoding options. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                  | Mandatory| Description      |
| ------- | ------------------------------------------------------ | ---- | ---------- |
| options | [DecodingOptionsForPicture](#decodingoptionsforpicture13) | No  | Decoding options.|

**Return value**

| Type                        | Description                      |
| ---------------------------- | -------------------------- |
| Promise\<[Picture](#picture13)> | Promise used to return the Picture object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified.2.Incorrect parameter types; 3.Parameter verification failed. |
| 7700301  | Failed to decode image.                                      |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function CreatePicture() {
  let options: image.DecodingOptionsForPicture = {
    desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP indicates the type of the auxiliary picture to be decoded.
  };
  let pictureObj: image.Picture = await imageSourceApi.createPicture(options);
  if (pictureObj != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }
}
```

### createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

Creates a PixelMap object based on decoding options. This API uses a promise to return the result.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocator](#createpixelmapusingallocator15). This API can be used to specify the memory type [AllocatorType](#allocatortype15) of the output PixelMap. For details, see [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                | Mandatory| Description      |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [DecodingOptions](#decodingoptions7) | No  | Decoding options.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

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

Creates a PixelMap object based on the default parameters. This API uses an asynchronous callback to return the result.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocator](#createpixelmapusingallocator15). This API can be used to specify the memory type [AllocatorType](#allocatortype15) of the output PixelMap. For details, see [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

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

Creates a PixelMap object based on decoding options. This API uses an asynchronous callback to return the result.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocator](#createpixelmapusingallocator15). This API can be used to specify the memory type [AllocatorType](#allocatortype15) of the output PixelMap. For details, see [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | Yes  | Decoding options.                |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decodingOptions: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 1, height: 2 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 1, height: 2 }, x: 0, y: 0 },
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
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

Creates a PixelMap object based on decoding options. This API returns the result synchronously.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocatorSync](#createpixelmapusingallocatorsync15). This API can be used to specify the memory type [AllocatorType](#allocatortype15) of the output PixelMap. For details, see [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | No  | Decoding options.                |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | PixelMap object.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { image } from '@kit.ImageKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let decodingOptions: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 1, height: 2 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 1, height: 2 }, x: 0, y: 0 },
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
  index: 0
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
} else {
  console.error('Failed to create pixelMap.');
}
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options?: DecodingOptions): Promise<Array\<PixelMap>>

Creates an array of PixelMap objects based on decoding options. This API uses a promise to return the result. For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

> **NOTE**
>
> This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | No  | Decoding options.                |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise<Array<[PixelMap](#pixelmap7)>> | Promise used to return an array of PixelMap objects.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980099 | The shared memory data is abnormal. |
| 62980101 | The image data is abnormal. |
| 62980103| The image data is not supported.             |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980109 | Failed to crop the image. |
| 62980110| The image source data is incorrect.             |
| 62980111| The image source data is incomplete.           |
| 62980112 | The image format does not match. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter. |
| 62980116 | Failed to decode the image. |
| 62980118| Failed to create the image plugin.             |
| 62980122 | Failed to decode the image header. |
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
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts).then((pixelMapList: Array<image.PixelMap>) => {
  console.info('Succeeded in creating pixelMapList object.');
}).catch((err: BusinessError) => {
  console.error(`Failed to create pixelMapList object, error code is ${err}`);
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of PixelMap objects based on the default parameters. This API uses an asynchronous callback to return the result. For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

> **NOTE**
>
> This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the array of PixelMap objects obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980099 | The shared memory data is abnormal.  |
| 62980101 | The image data is abnormal.          |
| 62980103 | The image data is not supported.         |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980109 | Failed to crop the image.            |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.       |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.         |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.   |
| 62980137 | Invalid media operation.     |
| 62980173 | The DMA memory does not exist.        |
| 62980174 | The DMA memory data is abnormal.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.createPixelMapList((err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
  if (err) {
    console.error(`Failed to create pixelMapList object, error code is ${err}`);
  } else {
    console.info('Succeeded in creating pixelMapList object.');
  }
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options: DecodingOptions, callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of PixelMap objects based on decoding options. This API uses an asynchronous callback to return the result. For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

> **NOTE**
>
> This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| options | [DecodingOptions](#decodingoptions7) | Yes| Decoding options.|
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the array of PixelMap objects obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.            |
| 62980099 | The shared memory data is abnormal.  |
| 62980101 | The image data is abnormal.         |
| 62980103 | The image data is not supported.        |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980109 | Failed to crop the image.           |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.         |
| 62980118 | Failed to create the image plugin.  |
| 62980122 | Failed to decode the image header.   |
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
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts, (err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
  if (err) {
    console.error(`Failed to create pixelMapList object, error code is ${err}`);
  } else {
    console.info('Succeeded in creating pixelMapList object.');
  }
})
```

### createPixelMapUsingAllocator<sup>15+</sup>

createPixelMapUsingAllocator(options?: DecodingOptions, allocatorType?: AllocatorType): Promise\<PixelMap>

Creates a PixelMap object based on decoding options and memory type. This API uses a promise to return the result. For details about how to use the API, see [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name       | Type                                | Mandatory| Description                    |
| ------------- | ------------------------------------ | ---- | ------------------------ |
| options        | [DecodingOptions](#decodingoptions7) | No  | Decoding options.              |
| allocatorType | [AllocatorType](#allocatortype15)   | No  | Type of the memory. The default value is **AllocatorType.AUTO**.|

**Return value**

| Type                            | Description                       |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types;3.Parameter verification failed. |
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed. |
| 7700102  | Unsupported mimetype.                                        |
| 7700103  | Image too large.  This status code is thrown when an error occurs during the process of checking size. |
| 7700201  | Unsupported allocator type, e.g., use share memory to decode a HDR image as only DMA supported hdr metadata. |
| 7700203  | Unsupported options, e.g., cannot convert image into desired pixel format. |
| 7700301  | Failed to decode image.                                      |
| 7700302  | Failed to allocate memory.                                   |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let decodingOptions: image.DecodingOptions = {
  editable: true,
  desiredSize: { width: 3072, height: 4096 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 3072, height: 4096 }, x: 0, y: 0 },
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
  index: 0
};
let pixelmap = imageSource.createPixelMapUsingAllocator(decodingOptions, image.AllocatorType.AUTO);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
} else {
  console.error('Failed to create pixelMap.');
}
```

### createPixelMapUsingAllocatorSync<sup>15+</sup>

createPixelMapUsingAllocatorSync(options?: DecodingOptions, allocatorType?: AllocatorType): PixelMap

Creates a PixelMap object based on decoding options and memory type. This API returns the result synchronously. For details about how to use the API, see [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name       | Type                                | Mandatory| Description                    |
| ------------- | ------------------------------------ | ---- | ------------------------ |
| options        | [DecodingOptions](#decodingoptions7) | No  | Decoding options.              |
| allocatorType | [AllocatorType](#allocatortype15)   | No  | Type of the memory. The default value is **AllocatorType.AUTO**.|

**Return value**

| Type                  | Description                  |
| ---------------------- | ---------------------- |
| [PixelMap](#pixelmap7) | PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types;3.Parameter verification failed. |
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed. |
| 7700102  | Unsupported mimetype.                                        |
| 7700103  | Image too large.  This status code is thrown when an error occurs during the process of checking size. |
| 7700201  | Unsupported allocator type, e.g., use share memory to decode a HDR image as only DMA supported hdr metadata. |
| 7700203  | Unsupported options, e.g., cannot convert image into desired pixel format. |
| 7700301  | Failed to decode image.                                      |
| 7700302  | Failed to allocate memory.                                   |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let decodingOptions: image.DecodingOptions = {
  editable: true,
  desiredSize: { width: 3072, height: 4096 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 3072, height: 4096 }, x: 0, y: 0 },
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
  index: 0
};
let pixelmap = imageSource.createPixelMapUsingAllocatorSync(decodingOptions, image.AllocatorType.AUTO);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
} else {
  console.error('Failed to create pixelMap.');
}
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
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980110| The image source data is incorrect.             |
| 62980111| The image source data is incomplete.            |
| 62980112 | The image format does not match. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| Failed to decode the image header. |
| 62980137 | Invalid media operation. |
| 62980149 | Invalid MIME type for the image source. |

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
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.  |
| 62980122 | Failed to decode the image header.   |
| 62980137 | Invalid media operation.      |
| 62980149 | Invalid MIME type for the image source.      |

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
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110| The image source data is incorrect. |
| 62980111| The image source data is incomplete. |
| 62980112| The image format does not match. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115| Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| Failed to decode the image header. |
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
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.  |
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
| 62980096 | Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.      |
| 62980101 | The image data is abnormal. |
| 62980137 | Invalid media operation.        |
| 62980149 | Invalid MIME type for the image source.      |

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

Releases this ImageSource instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImageSource object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

Releases this ImageSource instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImageSource object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

## image.getImageSourceSupportedFormats<sup>20+</sup>

getImageSourceSupportedFormats(): string[]

Obtains the supported decoding formats, represented by MIME types.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type    | Description                                      |
| -------- | ------------------------------------------ |
| string[] | List of supported encoding formats (MIME types).|

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
| [ImagePacker](#imagepacker) | ImagePacker instance created.|

**Example**

```ts
const imagePackerApi: image.ImagePacker = image.createImagePacker();
```

## ImagePacker

Provides APIs to compress and encode images. Before calling any API in ImagePacker, you must use [createImagePacker](#imagecreateimagepacker) to create an ImagePacker object. Currently, this class applies only to images in .jpeg, .webp, .png, or heif<sup>12+</sup> (depending on the hardware).

### Properties

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name            | Type          | Read Only| Optional| Description                      |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | Yes  | No  | Supported formats, including .jpeg, .webp, .png, and heic<sup>12+</sup> (depending on the hardware).|

### packToData<sup>13+</sup>

packToData(source: ImageSource, options: PackingOption): Promise\<ArrayBuffer>

Compresses or re-encodes an image. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | Yes  | Image source to compress or re-encode.|
| options | [PackingOption](#packingoption) | Yes  | Encoding parameters.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | If the parameter is invalid. |
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**Return value**

| Type                        | Description                                         |
| ---------------------------- | --------------------------------------------- |
| Promise\<ArrayBuffer>        | Promise used to return the compressed or encoded image data.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packToData(imageSourceApi, packOpts)
  .then((data: ArrayBuffer) => {
    console.info('Succeeded in packing the image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
```

### packToData<sup>13+</sup>

packToData(source: PixelMap, options: PackingOption): Promise\<ArrayBuffer>

Compresses or re-encodes an image. This API uses a promise to return the result.

> **NOTE**
>
> If error code 401 is returned, the parameters are abnormal. The possible cause is that the PixelMap object is released in advance. You need to check the code and ensure that the PixelMap object is released after this API is called.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description              |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](#pixelmap7)           | Yes  | PixelMap to compress or re-encode.|
| options | [PackingOption](#packingoption) | Yes  | Encoding parameters.    |

**Return value**

| Type                 | Description                                        |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the compressed or encoded image data.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | If the parameter is invalid. |
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packToData(pixelMap, packOpts)
    .then((data: ArrayBuffer) => {
      console.info('Succeeded in packing the image.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create PixelMap.code ${error.code},message is ${error.message}`);
})
```

### packing<sup>13+</sup>

packing(picture: Picture, options: PackingOption): Promise\<ArrayBuffer>

Compresses or re-encodes an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name          | Type                                                | Mandatory| Description                |
| ---------------- | ---------------------------------------------------- | ---- | -------------------- |
| picture | [Picture](#picture13)                           | Yes  | Picture to compress or re-encode.|
| options          | [PackingOption](#packingoption) | Yes  | Encoding parameters.      |

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the compressed or encoded image data.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800301  | Encode failed.                                         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function Packing(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  let funcName = "Packing";
  if (imagePackerApi != null) {
    let opts: image.PackingOption = {
      format: "image/jpeg",
      quality: 98,
      bufferSize: 10,
      desiredDynamicRange: image.PackingDynamicRange.AUTO,
      needsPackProperties: true};
    await imagePackerApi.packing(pictureObj, opts).then((data: ArrayBuffer) => {
        console.info(funcName, 'Succeeded in packing the image.'+ data);
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed to pack the image.code ${error.code},message is ${error.message}');
      });
  }
}
```

### packToDataFromPixelmapSequence<sup>18+</sup>

packToDataFromPixelmapSequence(pixelmapSequence: Array\<PixelMap>, options: PackingOptionsForSequence): Promise\<ArrayBuffer>

Encodes multiple PixelMap objects into GIF data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name          | Type                                                     | Mandatory| Description                  |
| ---------------- | --------------------------------------------------------- | ---- | ---------------------- |
| pixelmapSequence | Array\<[PixelMap](#pixelmap7)>                            | Yes  | PixelMaps to encode.|
| options          | [PackingOptionsForSequence](#packingoptionsforsequence18) | Yes  | Options for encoding animated images.        |

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the encoded data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800201  | Unsupported packing options.                                 |
| 7800301  | Failed to encode image.                                      |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import image from "@ohos.multimedia.image";

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const resourceMgr = context.resourceManager;
// 'moving_test.gif' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const fileData = resourceMgr.getRawFileContent('moving_test.gif');
const color = fileData.buffer;
let imageSource = image.createImageSource(color);
let pixelMapList = imageSource.createPixelMapList();
let ops: image.PackingOptionsForSequence = {
  frameCount: 3, // Set the number of frames in GIF encoding to 3.
  delayTimeList: [10, 10, 10], // Set the delay time of three frames in GIF encoding to 100 ms, 100 ms, and 100 ms, respectively.
  disposalTypes: [3, 2, 3], // Specify the frame transition modes of the three frames in GIF encoding as 3 (restore to the previous state), 2 (restore to the background color), and 3 (restore to the previous state).
  loopCount: 0 // Set the number of loops in GIF encoding to infinite.
};
let Packer = image.createImagePacker();
Packer.packToDataFromPixelmapSequence(pixelMapList, ops)
  .then((data: ArrayBuffer) => {
    console.info('Succeeded in packing.');
  }).catch((error: BusinessError) => {
  console.error('Failed to packing.');
  })
```

### packing<sup>(deprecated)</sup>

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Compresses or re-encodes an image. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 13. Use [packToData](#packtodata13) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                              | Mandatory| Description                              |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)        | Yes  | Image source to compress or re-encode.                    |
| option   | [PackingOption](#packingoption)    | Yes  | Encoding parameters.                     |
| callback | AsyncCallback\<ArrayBuffer>        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the compressed or encoded image data; otherwise, **err** is an error object. |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packing(imageSourceApi, packOpts, (err: BusinessError, data: ArrayBuffer) => {
  if (err) {
    console.error(`Failed to pack the image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in packing the image.');
  }
})
```

### packing<sup>(deprecated)</sup>

packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>

Compresses or re-encodes an image. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 13. Use [packToData](#packtodata13) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | Yes  | Image source to compress or re-encode.|
| option | [PackingOption](#packingoption) | Yes  | Encoding parameters.|

**Return value**

| Type                        | Description                                         |
| ---------------------------- | --------------------------------------------- |
| Promise\<ArrayBuffer>        | Promise used to return the compressed or encoded image data.|

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packing(imageSourceApi, packOpts)
  .then((data: ArrayBuffer) => {
    console.info('Succeeded in packing the image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
```

### packing<sup>(deprecated)</sup>

packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Compresses or re-encodes an image. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 13. Use [packToData](#packtodata13) instead.

> **NOTE**
> If the message "PixelMap mismatch" is returned, the parameters are abnormal. The possible cause is that the PixelMap object is released in advance. You need to check the code and ensure that the PixelMap object is released after this API is called.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                              |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [PixelMap](#pixelmap7)           | Yes  | PixelMap to compress or re-encode.              |
| option   | [PackingOption](#packingoption) | Yes  | Encoding parameters.                    |
| callback | AsyncCallback\<ArrayBuffer>     | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the compressed or encoded image data; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
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

### packing<sup>(deprecated)</sup>

packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>

Compresses or re-encodes an image. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 13. Use [packToData](#packtodata13) instead.
>
> If the message "PixelMap mismatch" is returned, the parameters are abnormal. The possible cause is that the PixelMap object is released in advance. You need to check the code and ensure that the PixelMap object is released after this API is called.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description              |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](#pixelmap7)           | Yes  | PixelMap to compress or re-encode.|
| option | [PackingOption](#packingoption) | Yes  | Encoding parameters.    |

**Return value**

| Type                 | Description                                        |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the compressed or encoded image data.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
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

Releases this ImagePacker instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImagePacker object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const imagePackerApi: image.ImagePacker = image.createImagePacker();
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

Releases this ImagePacker instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImagePacker object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type          | Description                                                  |
| -------------- | ------------------------------------------------------ |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.release().then(() => {
  console.info('Succeeded in releasing image packaging.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release image packaging.code ${error.code},message is ${error.message}`);
})
```

### packToFile<sup>11+</sup>

packToFile(source: ImageSource, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void

Encodes the image source into a file based on the specified encoding parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                          |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [ImageSource](#imagesource)     | Yes  | Image source to encode.                |
| fd       | number                          | Yes  | File descriptor.                  |
| options   | [PackingOption](#packingoption) | Yes  | Encoding parameters.                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.png' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.png";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath: string = context.filesDir + "/image_source.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
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

Encodes the image source into a file based on the specified encoding parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | Yes  | Image source to encode.|
| fd     | number                          | Yes  | File descriptor.  |
| options | [PackingOption](#packingoption) | Yes  | Encoding parameters.|

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'test.png' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.png";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath: string = context.filesDir + "/image_source.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packToFile(imageSourceApi, file.fd, packOpts).then(() => {
  console.info('Succeeded in packing the image to file.');
}).catch((error: BusinessError) => { 
  console.error(`Failed to pack the image to file.code ${error.code},message is ${error.message}`);
}) 
```

### packToFile<sup>11+</sup>

packToFile (source: PixelMap, fd: number, options: PackingOption,  callback: AsyncCallback\<void>): void

Encodes the PixelMap into a file based on the specified encoding parameters. This API uses an asynchronous callback to return the result.

> **NOTE**
> If error code 62980115 is returned, the parameters are abnormal. The possible cause is that the PixelMap object is released in advance. You need to check the code and ensure that the PixelMap object is released after this API is called.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                          |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [PixelMap](#pixelmap7)          | Yes  | PixelMap to encode.          |
| fd       | number                          | Yes  | File descriptor.                  |
| options   | [PackingOption](#packingoption) | Yes  | Encoding parameters.                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.filesDir + "/pixel_map.jpg";
image.createPixelMap(color, opts).then((pixelmap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
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

Encodes the PixelMap into a file based on the specified encoding parameters. This API uses a promise to return the result.

> **NOTE**
> If error code 62980115 is returned, the parameters are abnormal. The possible cause is that the PixelMap object is released in advance. You need to check the code and ensure that the PixelMap object is released after this API is called.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description                |
| ------ | ------------------------------- | ---- | -------------------- |
| source | [PixelMap](#pixelmap7)          | Yes  | PixelMap to encode.|
| fd     | number                          | Yes  | File descriptor.        |
| options | [PackingOption](#packingoption) | Yes  | Encoding parameters.      |

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| Operation failed.Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.filesDir + "/pixel_map.jpg";
image.createPixelMap(color, opts).then((pixelmap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packToFile(pixelmap, file.fd, packOpts)
    .then(() => {
      console.info('Succeeded in packing the image to file.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image to file.code ${error.code},message is ${error.message}`);
  })
})
```

### packToFile<sup>13+</sup>

packToFile(picture: Picture, fd: number, options: PackingOption): Promise\<void>

Encodes the Picture into a file based on the specified encoding parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name | Type                        | Mandatory| Description                |
| ------- | ---------------------------- | ---- | -------------------- |
| picture  | [Picture](#picture13)          | Yes  | Picture to encode.|
| fd      | number                       | Yes  | File descriptor.        |
| options | [PackingOption](#packingoption) | Yes  | Encoding parameters.      |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800301  | Encode failed.                                         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function PackToFile(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);

  let funcName = "PackToFile";
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  if (imagePackerApi != null) {
    const filePath: string = context.filesDir + "/test.jpg";
    let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    let packOpts: image.PackingOption = {
      format: "image/jpeg",
      quality: 98,
      bufferSize: 10,
      desiredDynamicRange: image.PackingDynamicRange.AUTO,
      needsPackProperties: true};
    await imagePackerApi.packToFile(pictureObj, file.fd, packOpts).then(() => {
      console.info(funcName, 'Succeeded in packing the image to file.');
    }).catch((error: BusinessError) => {
      console.error(funcName, 'Failed to pack the image to file.code ${error.code},message is ${error.message}');
    });
  }
}
```

### packToFileFromPixelmapSequence<sup>18+</sup>

packToFileFromPixelmapSequence(pixelmapSequence: Array\<PixelMap>, fd: number, options: PackingOptionsForSequence): Promise\<void>

Encodes multiple PixelMaps into a GIF file. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name          | Type                                                     | Mandatory| Description                  |
| ---------------- | --------------------------------------------------------- | ---- | ---------------------- |
| pixelmapSequence | Array<[PixelMap](#pixelmap7)>                             | Yes  | PixelMaps to encode.|
| fd               | number                                                    | Yes  | File descriptor.          |
| options          | [PackingOptionsForSequence](#packingoptionsforsequence18) | Yes  | Options for encoding animated images.        |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800201  | Unsupported packing options.                                 |
| 7800301  | Failed to encode image.                                      |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import fs from '@ohos.file.fs';
import image from "@ohos.multimedia.image";

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const resourceMgr = context.resourceManager;
// 'moving_test.gif' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const fileData = await resourceMgr.getRawFileContent('moving_test.gif');
const color = fileData.buffer;
let imageSource = image.createImageSource(color);
let pixelMapList = await imageSource.createPixelMapList();
let path: string = context.cacheDir + '/result.gif';
let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
let ops: image.PackingOptionsForSequence = {
  frameCount: 3, // Set the number of frames in GIF encoding to 3.
  delayTimeList: [10, 10, 10], // Set the delay time of three frames in GIF encoding to 100 ms, 100 ms, and 100 ms, respectively.
  disposalTypes: [3, 2, 3], // Specify the frame transition modes of the three frames in GIF encoding as 3 (restore to the previous state), 2 (restore to the background color), and 3 (restore to the previous state).
  loopCount: 0 // Set the number of loops in GIF encoding to infinite.
};
let Packer = image.createImagePacker();
Packer.packToFileFromPixelmapSequence(pixelMapList, file.fd, ops)
  .then(() => {
    console.info('Succeeded in packToFileMultiFrames.');
  }).catch((error: BusinessError) => {
  console.error('Failed to packToFileMultiFrames.');
  })
```

## image.getImagePackerSupportedFormats<sup>20+</sup>

getImagePackerSupportedFormats(): string[]

Obtains the supported encoding formats, represented by MIME types.

**System capability**: SystemCapability.Multimedia.Image.Core

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
| size   | [Size](#size)                                   | Yes  | Size of the auxiliary picture, in px.   |
| type   | [AuxiliaryPictureType](#auxiliarypicturetype13) | Yes  | Type of the auxiliary picture.                |

**Return value**

| Type                                   | Description                                      |
| --------------------------------------- | ------------------------------------------ |
| [AuxiliaryPicture](#auxiliarypicture13) | AuxiliaryPicture instance.|

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

## AuxiliaryPicture<sup>13+</sup>

The auxiliary picture is generally used to assist the main picture in displaying special information, so that the image includes richer information. The **AuxiliaryPicture** class is used to read or write auxiliary picture data of an image and obtain auxiliary picture information of an image. Before calling any API in AuxiliaryPicture, you must use [createAuxiliaryPicture](#imagecreateauxiliarypicture13) to create an AuxiliaryPicture object.

### Properties

**System capability**: SystemCapability.Multimedia.Image.Core

### writePixelsFromBuffer<sup>13+</sup>

writePixelsFromBuffer(data: ArrayBuffer): Promise\<void>

Reads pixels from an ArrayBuffer and writes the data to this AuxiliaryPicture object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description            |
| ------ | ----------- | ---- | ---------------- |
| data   | ArrayBuffer | Yes  | Pixels of the auxiliary picture.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600301  | Memory alloc failed.                                         |
| 7600302  | Memory copy failed.                                          |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function WritePixelsFromBuffer(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // Support for HDR images is required.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(image.AuxiliaryPictureType.GAINMAP);
  if(auxPictureObj != null) {
    let auxBuffer: ArrayBuffer = await auxPictureObj.readPixelsToBuffer();
    await auxPictureObj.writePixelsFromBuffer(auxBuffer);
    console.info('Write pixels from buffer success.');
  } else {
    console.error('AuxPictureObj is null.');
  }
}
```

### readPixelsToBuffer<sup>13+</sup>

readPixelsToBuffer(): Promise\<ArrayBuffer>

Reads pixels of this auxiliary picture and writes the data to an ArrayBuffer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the pixels of the auxiliary picture.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message            |
| -------- | -------------------- |
| 7600301  | Memory alloc failed. |
| 7600302  | Memory copy failed.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadPixelsToBuffer(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // Support for HDR images is required.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(image.AuxiliaryPictureType.GAINMAP);
  if(auxPictureObj != null) {
    await auxPictureObj.readPixelsToBuffer().then((pixelsBuffer: ArrayBuffer) => {
      console.info('Read pixels to buffer success.' );
    }).catch((error: BusinessError) => {
      console.error('Read pixels to buffer failed error.code: ' + JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
    });
  } else {
    console.error('AuxPictureObj is null.');
  }
}
```

### getType<sup>13+</sup>

getType(): AuxiliaryPictureType

Obtains the type of this auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                           | Description                        |
| ----------------------------------------------- | ---------------------------- |
| [AuxiliaryPictureType](#auxiliarypicturetype13) | Type of the auxiliary picture.|

**Example**

```ts
import { image } from '@kit.ImageKit';

async function GetAuxiliaryPictureType() {
  if (auxPictureObj != null) {
    let type: image.AuxiliaryPictureType = auxPictureObj.getType();
    console.info('Success get auxiliary picture type ' +  JSON.stringify(type));
  } else {
    console.error('Failed get auxiliary picture type ');
  }
}
```

### setMetadata<sup>13+</sup>

setMetadata(metadataType: MetadataType, metadata: Metadata): Promise\<void>

Sets the metadata for this auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type                           | Mandatory| Description                                |
| ------------ | ------------------------------- | ---- | ------------------------------------ |
| metadataType | [MetadataType](#metadatatype13) | Yes  | Metadata type, which is used to set the corresponding metadata.|
| metadata     | [Metadata](#metadata13)         | Yes  | Metadata object.                        |

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function SetAuxPictureObjMetadata(exifContext: Context) {
  const exifResourceMgr = exifContext.resourceManager;
  const exifRawFile = await exifResourceMgr.getRawFileContent("exif.jpg");// The image contains EXIF metadata.
  let exifOps: image.SourceOptions = {
    sourceDensity: 98,
  }
  let exifImageSource: image.ImageSource = image.createImageSource(exifRawFile.buffer as ArrayBuffer, exifOps);
  let exifCommodityPixelMap: image.PixelMap = await exifImageSource.createPixelMap();
  let exifPictureObj: image.Picture = image.createPicture(exifCommodityPixelMap);
  if (exifPictureObj != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }

  if (auxPictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let exifMetaData: image.Metadata = await exifPictureObj.getMetadata(metadataType);
    auxPictureObj.setMetadata(metadataType, exifMetaData).then(() => {
      console.info('Set metadata success');
    }).catch((error: BusinessError) => {
      console.error('Set metadata failed.error.code: ${error.code}, error.message: ${error.message}');
    });
  } else {
    console.error('AuxPictureObjMetaData is null');
  }
}
```

### getMetadata<sup>13+</sup>

getMetadata(metadataType: MetadataType): Promise\<Metadata>

Obtains the metadata of this auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type                           | Mandatory| Description                                  |
| ------------ | ------------------------------- | ---- | -------------------------------------- |
| metadataType | [MetadataType](#metadatatype13) | Yes  | Metadata type, which is used to obtain metadata of the corresponding type.|

**Return value**

| Type                            | Description            |
| -------------------------------- | ---------------- |
| Promise<[Metadata](#metadata13)> | Metadata object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function GetAuxPictureObjMetadata() {
  if (auxPictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let auxPictureObjMetaData: image.Metadata | null = await auxPictureObj.getMetadata(metadataType);
    if (auxPictureObjMetaData != null) {
      console.info('Get auxpictureobj Metadata success' );
    } else {
      console.error('Get auxpictureobj Metadata failed');
    }
  } else {
    console.error('Get auxpictureobj is null.');
  }
}
```

### getAuxiliaryPictureinfo<sup>13+</sup>

getAuxiliaryPictureInfo(): AuxiliaryPictureInfo

Obtains the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| [AuxiliaryPictureInfo](#auxiliarypictureinfo13) | Promise used to return the auxiliary picture information.|

**Example**

```ts
import { image } from '@kit.ImageKit';

async function GetAuxiliaryPictureInfo() {
  if(auxPictureObj != null) {
    let auxinfo: image.AuxiliaryPictureInfo = auxPictureObj.getAuxiliaryPictureInfo();
    console.info('GetAuxiliaryPictureInfo Type: ' + auxinfo.auxiliaryPictureType +
      ' height: ' + auxinfo.size.height + ' width: ' + auxinfo.size.width +
      ' rowStride: ' +  auxinfo.rowStride +  ' pixelFormat: ' + auxinfo.pixelFormat +
      ' colorSpace: ' +  auxinfo.colorSpace);
  } else {
    console.error('Get auxiliary picture information failed');
  }
}
```

### setAuxiliaryPictureinfo<sup>13+</sup>

setAuxiliaryPictureInfo(info: AuxiliaryPictureInfo): void

Sets the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                                           | Mandatory| Description              |
| ------ | ----------------------------------------------- | ---- | ------------------ |
| info   | [AuxiliaryPictureInfo](#auxiliarypictureinfo13) | Yes  | Auxiliary picture information.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | :----------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { image } from '@kit.ImageKit';

async function SetAuxiliaryPictureInfo() {
  if(auxPictureObj != null) {
    let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
    let info: image.AuxiliaryPictureInfo = {
      auxiliaryPictureType: image.AuxiliaryPictureType.GAINMAP,
      size: {height: 100, width: 200},
      pixelFormat: image.PixelMapFormat.RGBA_8888,
      rowStride: 0,
      colorSpace: colorSpaceManager.create(colorSpaceName),
    };
    auxPictureObj.setAuxiliaryPictureInfo(info);
  }
}
```

### release<sup>13+</sup>

release():void

Releases this AuxiliaryPicture object. No value is returned.

**System capability**: SystemCapability.Multimedia.Image.Core

**Example**

```ts
import { image } from '@kit.ImageKit';

async function Release() {
  let funcName = "Release";
  if (auxPictureObj != null) {
    auxPictureObj.release();
    if (auxPictureObj.getType() == null) {
      console.info(funcName, 'Success !');
    } else {
      console.error(funcName, 'Failed !');
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

## Metadata<sup>13+</sup>

A class used to store image metadata. For details about the supported metadata types, see [MetadataType](#metadatatype13).

### Properties

**System capability**: SystemCapability.Multimedia.Image.Core

### getProperties<sup>13+</sup>

getProperties(key: Array\<string>): Promise\<Record\<string, string | null>>

Obtains the values of properties from the image's metadata. This API uses a promise to return the result. For details about how to obtain the property values, see [PropertyKey](#propertykey7) and [FragmentMapPropertyKey](#fragmentmappropertykey13).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type          | Mandatory| Description                    |
| ------ | -------------- | ---- | ------------------------ |
| key    | Array\<string> | Yes  | Names of the properties.|

**Return value**

| Type                                    | Description                                                        |
| ---------------------------------------- | ------------------------------------------------------------ |
| Promise\<Record<string, string \| null>> | Promise used to return the property values. If the retrieval operation fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    await metaData.getProperties(["ImageWidth", "ImageLength"]).then((data2) => {
      console.info('Get properties ',JSON.stringify(data2));
    }).catch((error: BusinessError) => {
      console.error('Get properties failed error.code: ' +JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

### setProperties<sup>13+</sup>

setProperties(records: Record\<string, string | null>): Promise\<void>

Sets the values of properties for the image's metadata. This API uses a promise to return the result. For details about how to obtain the property values, see [PropertyKey](#propertykey7) and [FragmentMapPropertyKey](#fragmentmappropertykey13).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                          | Mandatory| Description                    |
| ------- | ------------------------------ | ---- | ------------------------ |
| records | Record<string, string \| null> | Yes  | Array of properties and their values.|

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function SetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    let setkey: Record<string, string | null> = {
      "ImageWidth": "200",
      "ImageLength": "300"
    };
    await metaData.setProperties(setkey).then(async () => {
      console.info('Set auxpictureobj properties success.');
    }).catch((error: BusinessError) => {
      console.error('Failed to set metadata Properties. code is ${error.code}, message is ${error.message}');
    })
  } else {
    console.error('AuxPictureObj metadata is null. ');
  }
}
```

### getAllProperties<sup>13+</sup>

getAllProperties(): Promise\<Record<string, string | null>>

Obtains all properties and values from the image's metadata. This API uses a promise to return the result. For details about how to obtain the property values, see [PropertyKey](#propertykey7) and [FragmentMapPropertyKey](#fragmentmappropertykey13).

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                    | Description                                       |
| ---------------------------------------- | ------------------------------------------- |
| Promise\<Record<string, string \| null>> | Promise used to return the values of all properties.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetAllProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    await metaData.getAllProperties().then((data2) => {
      const count = Object.keys(data2).length;
      console.info('Metadata have ', count, ' properties');
      console.info('Get metadata all properties: ', JSON.stringify(data2));
    }).catch((error: BusinessError) => {
      console.error('Get metadata all properties failed error.code: ' +JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

### clone<sup>13+</sup>

clone(): Promise\<Metadata>

Clones the metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise\<[Metadata](#metadata13)> | Promise used to return the metadata instance.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message            |
| -------- | -------------------- |
| 7600301  | Memory alloc failed. |
| 7600302  | Memory copy failed.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function clone(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    let new_metadata: image.Metadata = await metaData.clone();
    new_metadata.getProperties(["ImageWidth"]).then((data1) => {
      console.info('Clone new_metadata and get Properties.', JSON.stringify(data1));
    }).catch((err: BusinessError) => {
      console.error('Clone new_metadata failed.', JSON.stringify(err));
    });
  } else {
    console.error('Metadata is null.');
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
| size    | [Size](#size)  | Yes  | Default size of the image. This parameter does not affect the size of the received image. The actual returned size is determined by the producer, for example, the camera.      |
| format   | [ImageFormat](#imageformat9) | Yes  | Image format, which is a constant of [ImageFormat](#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.)            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver9) | ImageReceiver instance.|

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
| format   | number | Yes  | Image format, which is a constant of [ImageFormat](#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.) |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver9) | ImageReceiver instance.|

**Example**

```ts
let receiver: image.ImageReceiver = image.createImageReceiver(8192, 8, image.ImageFormat.JPEG, 8);
```

## ImageReceiver<sup>9+</sup>

Provides APIs to obtain the surface ID of a component, read the latest image, read the next image, and release the ImageReceiver instance. The ImageReceiver acts as the receiver and consumer of images. Its parameter properties do not actually affect the received images. The configuration of image properties should be done on the sending side (the producer), such as when creating a camera preview stream with [createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput).

Before calling any APIs in ImageReceiver, you must create an ImageReceiver instance.

### Properties

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name    | Type                        | Read Only| Optional| Description              |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| size     | [Size](#size)                | Yes  | No  | Image size. This parameter does not affect the size of the received image. The actual returned size is determined by the producer, for example, the camera.        |
| capacity | number                       | Yes  | No  | Maximum number of images that can be accessed at the same time.|
| format   | [ImageFormat](#imageformat9) | Yes  | No  | Image format, which is a constant of [ImageFormat](#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.)       |

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

Reads the latest image from the ImageReceiver instance. This API uses an asynchronous callback to return the result.

**NOTE**: This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

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

Reads the latest image from the ImageReceiver instance. This API uses a promise to return the result.

**NOTE**: This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

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

Reads the next image from the ImageReceiver instance. This API uses an asynchronous callback to return the result.

**NOTE**: This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

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

Reads the next image from the ImageReceiver instance. This API uses a promise to return the result.

**NOTE**: This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](#image9) object returned by this API is no longer needed, call [release](#release9-4) to release the object. New data can be received only after the release.

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

### off<sup>13+</sup>

off(type: 'imageArrival', callback?: AsyncCallback\<void>): void

Unregisters the callback function that is triggered when the buffer is released.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                | Mandatory| Description                                    |
| -------- | -------------------- |----|----------------------------------------|
| type     | string               | Yes | Type of event, which is **'imageArrival'**.|
| callback | AsyncCallback\<void> | No | Callback to unregister.        |

**Example**

```ts
let callbackFunc = ()=>{
    // do something.
}
receiver.on('imageArrival', callbackFunc)
receiver.off('imageArrival', callbackFunc)
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this ImageReceiver instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImageReceiver object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

Releases this ImageReceiver instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImageReceiver object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

Creates an ImageCreator instance by specifying the image size, format, and capacity.

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
| [ImageCreator](#imagecreator9) | ImageCreator instance.|


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
| [ImageCreator](#imagecreator9) | ImageCreator instance.|

**Example**

```ts
let creator: image.ImageCreator = image.createImageCreator(8192, 8, image.ImageFormat.JPEG, 8);
```

## ImageCreator<sup>9+</sup>

Provides APIs for applications to request an image data area and compile image data.
Before calling any APIs in ImageCreator, you must create an [ImageCreator](#imagecreator9) instance. ImageCreator does not support multiple threads.

### Properties

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

| Name    | Type                        | Read Only| Optional| Description              |
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

Places the drawn image in the queue. This API uses an asynchronous callback to return the result.

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

Places the drawn image in the queue. This API uses a promise to return the result.

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

### off<sup>13+</sup>

off(type: 'imageRelease', callback?: AsyncCallback\<void>): void

Unregisters the callback function that is triggered when the buffer is released.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name       | Type                    | Mandatory| Description                                        |
| ------------- | -------------------------|----|--------------------------------------------|
| type          | string                   | Yes | Type of event, which is **'imageRelease'**.                   |
| callback      | AsyncCallback\<void>     | No | Callback to unregister.|

**Example**

```ts
let callbackFunc = ()=>{
    // do something.
}
creator.on('imageRelease', callbackFunc)
creator.off('imageRelease', callbackFunc)
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this ImageCreator instance. This API uses an asynchronous callback to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImageCreator object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

Releases this ImageCreator instance. This API uses a promise to return the result.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the ImageCreator object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

Provides APIs for basic image operations, including obtaining image information and reading and writing image data. An Image instance is returned when [readNextImage](#readnextimage9) and [readLatestImage](#readlatestimage9) are called.

### Properties

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    | Type              | Read Only| Optional| Description                                              |
| -------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect | [Region](#region8) | Yes  | Yes  | Image area to be cropped.                                |
| size     | [Size](#size)      | Yes  | No  | Image size. If the image object stores the camera preview stream data (YUV image data), the width and height in **size** obtained correspond to those of the YUV image. If the image object stores the camera photo stream data (JPEG image data, which is already encoded), the width in **size** obtained is the JPEG data size, and the height is 1. The type of data stored in the image object depends on whether the application passes the surface ID in the receiver to a previewOutput or captureOutput object of the camera. For details about the best practices of camera preview and photo capture, see [Dual-Channel Preview (ArkTS)](../../media/camera/camera-dual-channel-preview.md) and [Photo Capture Sample (ArkTS)](../../media/camera/camera-shooting-case.md).                               |
| format   | number             | Yes  | No  | Image format. For details, see [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format).|
| timestamp<sup>12+</sup> | number         | Yes     | No  | Image timestamp. Timestamps, measured in nanoseconds, are usually monotonically increasing. The specific meaning and baseline of these timestamps are determined by the image producer, which is the camera in the camera preview and photo scenarios. As a result, images from different producers may carry timestamps with distinct meanings and baselines, making direct comparison between them infeasible. To obtain the generation time of a photo, you can use [getImageProperty](#getimageproperty11) to read the related EXIF information.|

### getComponent<sup>9+</sup>

getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void

Obtains the component buffer from the Image instance based on the color component type. This API uses an asynchronous callback to return the result.

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

Obtains the component buffer from the Image instance based on the color component type. This API uses a promise to return the result.

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

Releases this Image instance. This API uses an asynchronous callback to return the result.

The corresponding resources must be released before another image arrives.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the Image object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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

Releases this Image instance. This API uses a promise to return the result.

The corresponding resources must be released before another image arrives.

ArkTS supports memory reclamation. Even if the application does not call **release()**, the memory of the Image object will be released by the system. However, images usually occupy a large amount of memory. Therefore, it is recommended that the application proactively call the API to release the memory when the object is no longer required.

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
| pixels | ArrayBuffer        | No|   No | Pixels of the image. Only pixel data in BGRA_8888 format is supported.|
| offset | number             | No|   No |  Offset for data reading, in bytes.                                                    |
| stride | number             | No|   No | Number of bytes from one row of pixels in memory to the next row of pixels in memory. The value of **stride** must be greater than or equal to the value of **region.size.width** multiplied by 4.                  |
| region | [Region](#region8) | No|   No |Region to read or write. The width of the region to write plus the X coordinate cannot be greater than the width of the original image. The height of the region to write plus the Y coordinate cannot be greater than the height of the original image.|

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
| isHdr<sup>12+</sup> | boolean  |  No | No | Whether the image is an HDR image. The value **true** means an HDR image, and **false** means an SDR image. For [ImageSource](#imagesource), this parameter specifies whether the source image is in HDR format. For [PixelMap](#pixelmap7), this parameter specifies whether the decoded PixelMap is in HDR format.|

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

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | Unknown format.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.       |
| ARGB_8888<sup>18+</sup> | 1 | The color information consists of four components: alpha, R (Red), G (Green), and B (Blue). Each component occupies 8 bits, and the total length is 32 bits. Currently, this format supports only PixelMap APIs.|
| RGB_565                | 2      | The color information consists of three components: R (Red), G (Green), and B (Blue), which occupies five bits, six bits, and five bits, respectively. The total length is 16 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.    |
| RGBA_8888              | 3      | The color information consists of four components: R (Red), G (Green), B (Blue), and alpha. Each component occupies 8 bits, and the total length is 32 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| BGRA_8888<sup>9+</sup> | 4      | The color information consists of four components: B (Blue), G (Green), R (Red), and alpha. Each component occupies 8 bits, and the total length is 32 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| RGB_888<sup>9+</sup>   | 5      | The color information consists of three components: R (Red), G (Green), and B (Blue). Each component occupies 8 bits, and the total length is 24 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| ALPHA_8<sup>9+</sup>   | 6      | The color information consists of only the alpha component, which occupies eight bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| RGBA_F16<sup>9+</sup>  | 7      | The color information consists of four components: R (Red), G (Green), B (Blue), and alpha. Each component occupies 16 bits, and the total length is 64 bits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12. |
| NV21<sup>9+</sup>      | 8      | YVU pixel arrangement, where the V component precedes the U component. The color information consists of the luminance component Y and the interleaved chrominance components V and U. The Y component occupies 8 bits, and the UV components occupy 4 bits on average due to 4:2:0 sampling. The total length is 12 bits on average.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| NV12<sup>9+</sup>      | 9      | YUV pixel arrangement, where the U component precedes the V component. The color information consists of the luminance component Y and the interleaved chrominance components U and V. The Y component occupies 8 bits, and the UV components occupy 4 bits on average due to 4:2:0 sampling. The total length is 12 bits on average.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| RGBA_1010102<sup>12+</sup> | 10 | The color information consists of four components: R (Red), G (Green), B (Blue), and alpha. R, G, and B each occupy 10 bits, and alpha occupies 2 bits. The total length is 32 bits.|
| YCBCR_P010<sup>12+</sup> | 11 | The color information consists of the luminance component Y and the chrominance components Cb and Cr. Each component has effective 10 bits. In storage, the Y plane uses 16 bits per pixel (10 of which are effective). The UV plane is interleaved, with every four pixels taking up 32 bits of data (each chrominance component having 10 effective bits), resulting in an average of 15 effective bits overall.
| YCRCB_P010<sup>12+</sup> | 12 | The color information consists of the luminance component Y and the chrominance components Cr and Cb. Each component has effective 10 bits. In storage, the Y plane uses 16 bits per pixel (10 of which are effective). The UV plane is interleaved, with every four pixels taking up 32 bits of data (each chrominance component having 10 effective bits), resulting in an average of 15 effective bits overall. |
| ASTC_4x4<sup>18+</sup> | 102 | The storage format is ASTC_4x4, and the memory usage is only 1/4 of that of RGBA_8888. This format is used only for direct display and does not support pixel access or post-processing editing. |

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
| UNPREMUL | 3      | RGB non-premultiplied alpha.      |

## AuxiliaryPictureType<sup>13+</sup>

Enumerates the auxiliary pictures types.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| GAINMAP       | 1    | Gain map, a mechanism for transforming an SDR image into an HDR image capable of display adjustment. It is a set of combinations describing how to apply gain map metadata.    |
| DEPTH_MAP     | 2    | Depth map, which stores the depth data of an image. It captures the distance between each pixel and the camera to provide 3D scene structure. It is usually used for 3D modeling and scene comprehension.    |
| UNREFOCUS_MAP | 3    | Defocused portrait original image, which provides a method to emphasize background blur in portrait photographing. It helps users select a focus region in post-processing, allowing for greater creative control.  |
| LINEAR_MAP    | 4    | Linear map, which is used to provide additional viewpoints or supplementary information. It is usually used to enhance visual effects and can contain linear representations of lighting, colors, or other visual elements in a scene.    |
| FRAGMENT_MAP  | 5    | Fragment map, which indicates regions obscured by watermarks in the original image. It is used to remove or correct the watermark interference, thereby enhancing the image completeness and visibility.|

## AuxiliaryPictureInfo<sup>13+</sup>

Describes the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                     | Type                                                        | Read Only| Optional| Description                                                        |
| ------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| auxiliaryPictureType      | [AuxiliaryPictureType](#auxiliarypicturetype13)              | No  | No  | Auxiliary picture type.                                          |
| size         | [Size](#size)                                                | No  | No  | Image size.|
| rowStride                 | number                                                       | No  | No  | Row stride.                                                      |
| pixelFormat | [PixelMapFormat](#pixelmapformat7)                           | No  | No  | Pixel format.|
| colorSpace                | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | No  | No  | Color space.                                              |

## MetadataType<sup>13+</sup>

Enumerates image metadata types.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Value  | Description              |
| ----------------- | ---- | ------------------ |
| EXIF_METADATA     | 1    | EXIF data.        |
| FRAGMENT_METADATA | 2    | Fragment map metadata.|

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
| sourceDensity     | number                             | No  | No  | Pixel density of the image resource, in ppi.<br>If **desiredSize** is not set in [DecodingOptions](#decodingoptions7) and **SourceOptions.sourceDensity** and **DecodingOptions.fitDensity** are not 0, the PixelMap output after decoding will be scaled.<br>The formula for calculating the width after scaling is as follows (the same applies to the height): (width * fitDensity + (sourceDensity >> 1)) / sourceDensity.|
| sourcePixelFormat | [PixelMapFormat](#pixelmapformat7) | No  | Yes  | Image pixel format. The default value is **UNKNOWN**.    |
| sourceSize        | [Size](#size)                      | No  | Yes  | Image pixel size. The default value is null.    |


## InitializationOptions<sup>8+</sup>

Defines PixelMap initialization options.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                    | Type                              | Read Only|Optional|  Description          |
| ------------------------ | ---------------------------------- | ----| -----|  -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](#alphatype9)           | No  | Yes| Alpha type. The default value is **IMAGE_ALPHA_TYPE_PREMUL**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.     |
| editable                 | boolean                            | No  | Yes| Whether the image is editable. The value **true** means that the image is editable, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| srcPixelFormat<sup>12+</sup>  | [PixelMapFormat](#pixelmapformat7) | No| Yes| Pixel format of the passed-in buffer data. The default value is **BGRA_8888**.|
| pixelFormat              | [PixelMapFormat](#pixelmapformat7) | No| Yes| Pixel format of the generated PixelMap. The default value is **RGBA_8888**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.    |
| scaleMode<sup>9+</sup>   | [ScaleMode](#scalemode9)           | No | Yes| Scale mode. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| size                     | [Size](#size)                      | No | No|Image size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|

## DecodingOptions<sup>7+</sup>

Describes the image decoding options.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name              | Type                              | Read Only| Optional| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | No  | Yes  | Sampling size of the thumbnail. The default value is **1**. Currently, the value can only be **1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| rotate             | number                             | No  | Yes  | Rotation angle. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| editable           | boolean                            | No  | Yes  | Whether the image is editable. The value **true** means that the image is editable, and **false** means the opposite. The default value is **false**. If this option is set to **false**, the image cannot be edited again, and operations such as writing pixels will fail.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12. |
| desiredSize        | [Size](#size)                      | No  | Yes  | Expected output size. The value must be a positive integer and defaults to the original image size. If the output size is different from the original size, the output is stretched or scaled to the specified size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| desiredRegion      | [Region](#region8)                 | No  | Yes  | Rectangle specified by **Region** in the decoded image. When the original image is large and only a specific part of the image is required, you can set this parameter to improve performance. The default value is the original image size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.      |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | No  | Yes  | Pixel format for decoding. The default value is **RGBA_8888**. Only RGBA_8888, BGRA_8888, and RGB_565 are supported. RGB_565 is not supported for images with alpha channels, such as PNG, GIF, ICO, and WEBP.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| index              | number                             | No  | Yes  | Index of the image to decode. The default value is **0**, indicating the first image. If this parameter is set to N, the (N-1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| fitDensity<sup>9+</sup> | number                        | No  | Yes  | Pixel density, in ppi. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.  |
| desiredColorSpace<sup>11+</sup> | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | No  | Yes  | Target color space. The default value is **UNKNOWN**.|
| desiredDynamicRange<sup>12+</sup> | [DecodingDynamicRange](#decodingdynamicrange12) | No  | Yes  | Desired dynamic range. The default value is **SDR**.<br>This property cannot be set for an image source created using [CreateIncrementalSource](#imagecreateincrementalsource9). By default, the image source is decoded as SDR content.<br>If the platform does not support HDR, the setting is invalid and the content is decoded as SDR content by default.|
| cropAndScaleStrategy<sup>18+</sup> | [CropAndScaleStrategy](#cropandscalestrategy18) | No  | Yes  | If **desiredRegion** and **desiredSize** are both specified, the order of cropping and scaling is determined.<br>Only **SCALE_FIRST** and **CROP_FIRST** are supported.|

## DecodingOptionsForPicture<sup>13+</sup>

Describes the image decoding options.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name                    | Type                                                   | Read Only| Optional| Description                                                        |
| ------------------------ | ------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| desiredAuxiliaryPictures | Array\<[AuxiliaryPictureType](#auxiliarypicturetype13)> | No  | No  | Auxiliary picture type. By default, all auxiliary picture types are decoded.|

## Region<sup>8+</sup>

Describes the region information.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Read Only| Optional| Description        |
| ---- | ------------- | ---- | ---- | ------------ |
| size<sup>7+</sup> | [Size](#size) | No  | No  | Region size.  |
| x<sup>7+</sup>    | number        | No  | No | X coordinate of the upper left corner of the region, in px.|
| y<sup>7+</sup>    | number        | No | No | Y coordinate of the upper left corner of the region, in px.|

## PackingOption

Describes the options for image encoding.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name   | Type  | Read Only| Optional| Description                                               |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | No  | No  | Format of the packed image.<br>Currently, only the following formats are supported: image/jpeg, image/webp, image/png, image/heic (or image/heif)<sup>12+</sup>, image/sdr_astc_4x4<sup>18+</sup>, and image/sdr_sut_superfast_4x4<sup>18+</sup> (depending on the hardware).<br>**NOTE**: The JPEG format does not support the alpha channel. If the JPEG format with the alpha channel is used for data encoding, the transparent color turns black.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| quality | number | No  | No  | Quality of the output image set. This parameter takes effect only for JPEG and HEIF images. The value ranges from 0 to 100. The value **0** means the lowest quality, and **100** means the highest quality. The higher the quality, the larger the space occupied by the generated image. WebP and PNG images are lossless.<br>In the case of sdr_astc_4x4 encoding, the parameter can be set to **92** and **85**.<br>In the case of sut encoding, the parameter can be set to **92**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| bufferSize<sup>9+</sup> | number | No  | Yes  | Size of the buffer for receiving the encoded data, in bytes. If this parameter is not set, the default value 25 MB is used. If the size of an image exceeds 25 MB, you must specify the size. The value of **bufferSize** must be greater than the size of the encoded image. The use of [packToFile](#packtofile11) is not restricted by this parameter.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| desiredDynamicRange<sup>12+</sup> | [PackingDynamicRange](#packingdynamicrange12) | No  | Yes  | Desired dynamic range. The default value is **SDR**.|
| needsPackProperties<sup>12+</sup> | boolean | No  | Yes  | Whether to encode image property information, for example, EXIF. The value **true** means to encode image property information, and **false** means the opposite. The default value is **false**.|

## PackingOptionsForSequence<sup>18+</sup>

Defines the options for encoding animated images.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name         | Type          | Read Only| Optional| Description                                                        |
| ------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| frameCount    | number         | No  | No  | Number of frames specified in GIF encoding.                                       |
| delayTimeList | Array\<number> | No  | No  | Delay time of each frame in GIF encoding. The value must be greater than 0.<br>The unit is 10 milliseconds. For example, if this parameter is set to 10, the actual delay per frame is 100 ms.<br>If the array length is less than **frameCount**, the last value in the array will be used for the remaining frames.|
| disposalTypes | Array\<number> | No  | Yes  | Array that defines how each image frame transitions. If the array length is less than **frameCount**, the last value in the array will be used for the remaining frames. The values can be:<br>- **0**: No operation is required.<br>- **1**: Keeps the image unchanged.<br>- **2**: Restores the background color.<br>- **3**: Restores to the previous state.|
| loopCount     | number         | No  | Yes  | Number of times that the output image in GIF encoding loops. The value range is [0, 65535].<br>The value **0** means an infinite loop. If this field is not carried, loop playback is not performed.|

## ImagePropertyOptions<sup>11+</sup>

Describes the image properties.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name        | Type  | Read Only| Optional| Description        |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | No  | Yes  | Index of the image. The default value is **0**.  |
| defaultValue | string | No  | Yes  | Default property value. The default value is null.|

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
| BITS_PER_SAMPLE                           | "BitsPerSample"             | **Read/Write capability**: readable and writable<br> Number of bits per sample. For example, for RGB, which has three components, the format is 8, 8, 8.|
| COMPRESSION <sup>12+</sup>                | "Compression"               | **Read/Write capability**: readable and writable<br> Compression scheme used on the image data.|
| PHOTOMETRIC_INTERPRETATION <sup>12+</sup> | "PhotometricInterpretation" | **Read/Write capability**: readable and writable<br> Color space of the image data, for example, RGB or YCbCr.|
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"          | **Read/Write capability**: readable and writable<br> Image description.|
| MAKE<sup>10+</sup>                        | "Make"                      | **Read/Write capability**: readable and writable<br> Manufacturer.|
| MODEL<sup>10+</sup>                       | "Model"                     | **Read/Write capability**: readable and writable<br> Device model.|
| STRIP_OFFSETS <sup>12+</sup>              | "StripOffsets"              | **Read/Write capability**: readable and writable<br> Byte offset of each strip.|
| ORIENTATION                               | "Orientation"               | **Read/Write capability**: readable and writable<br> Image orientation.<br>- 1: **Top-left**: The image is not rotated.<br>- 2: **Top-right**: The image is flipped horizontally.<br>- 3: **Bottom-right**: The image is rotated by 180°.<br>- 4: **Bottom-left**: The image is flipped vertically.<br>- 5: **Left-top**: The image is flipped horizontally and then rotated clockwise by 270°.<br>- 6: **Right-top**: The image is rotated clockwise by 90°.<br>- 7: **Right-bottom**: The image is vertically flipped and then rotated clockwise by 90°.<br>- 8: **Left-bottom**: The image is rotated clockwise by 270°.<br>- If an undefined value is read, **Unknown Value 0** is returned. The value of the property obtained is returned as a string. When modifying the property, you can specify the property either in the form of a number or a string.|
| SAMPLES_PER_PIXEL <sup>12+</sup>          | "SamplesPerPixel"           | **Read/Write capability**: readable and writable<br> Number of components per pixel. The value is 3 for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data.|
| ROWS_PER_STRIP <sup>12+</sup>             | "RowsPerStrip"              | **Read/Write capability**: readable and writable<br> Number of rows per strip.|
| STRIP_BYTE_COUNTS <sup>12+</sup>          | "StripByteCounts"           | **Read/Write capability**: readable and writable<br> Number of bytes in each strip after compression.|
| X_RESOLUTION <sup>12+</sup>               | "XResolution"               | **Read/Write capability**: readable and writable<br> Number of pixels per ResolutionUnit in the image width (X) direction.|
| Y_RESOLUTION <sup>12+</sup>               | "YResolution"               | **Read/Write capability**: readable and writable<br> Number of pixels per ResolutionUnit in the image height (Y) direction.|
| PLANAR_CONFIGURATION <sup>12+</sup>       | "PlanarConfiguration"       | **Read/Write capability**: readable and writable<br> Storage format of components of each pixel, which can be chunky or planar.|
| RESOLUTION_UNIT <sup>12+</sup>            | "ResolutionUnit"            | **Read/Write capability**: readable and writable<br> Unit of measurement for XResolution and YResolution.|
| TRANSFER_FUNCTION <sup>12+</sup>          | "TransferFunction"          | **Read/Write capability**: readable and writable<br> Transfer function for the image, which is usually used for color correction.|
| SOFTWARE <sup>12+</sup>                   | "Software"                  | **Read/Write capability**: readable and writable<br> Name and version number of the software used to create the image.|
| DATE_TIME<sup>10+</sup>                   | "DateTime"                  | **Read/Write capability**: readable and writable<br> Date and time of image creation. An example in the correct format is 2024:01:25 05:51:34.|
| ARTIST <sup>12+</sup>                     | "Artist"                    | **Read/Write capability**: readable and writable<br> Person who created the image.|
| WHITE_POINT <sup>12+</sup>                | "WhitePoint"                | **Read/Write capability**: readable and writable<br> Chromaticity of the white point of the image.|
| PRIMARY_CHROMATICITIES <sup>12+</sup>     | "PrimaryChromaticities"     | **Read/Write capability**: readable and writable<br> Chromaticities of the primaries of the image.|
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode"                 | **Read/Write capability**: readable and writable<br> Photographing mode.|
| JPEG_INTERCHANGE_FORMAT <sup>12+</sup>    | "JPEGInterchangeFormat"     | **Read/Write capability**: read-only<br> Offset of the SOI marker of a JPEG interchange format bitstream.|
| JPEG_INTERCHANGE_FORMAT_LENGTH <sup>12+</sup> | "JPEGInterchangeFormatLength" | **Read/Write capability**: read-only<br> Number of bytes of the JPEG stream.|
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
| GPS_LATITUDE                              | "GPSLatitude"               | **Read/Write capability**: readable and writable<br> Image latitude. The value must be in the format of degree,minute,second, for example, 39,54,7.542.|
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"           | **Read/Write capability**: readable and writable<br> Whether the longitude is east or west longitude.|
| GPS_LONGITUDE                             | "GPSLongitude"              | **Read/Write capability**: readable and writable<br> Image longitude. The value must be in the format of degree,minute,second, for example, 116,19,42.16.|
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
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"             | **Read/Write capability**: readable and writable<br> Lens aperture. An example in the correct format is 4/1.|
| BRIGHTNESS_VALUE <sup>12+</sup>           | "BrightnessValue"           | **Read/Write capability**: readable and writable<br> Value of brightness, expressed in APEX values.|
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"         | **Read/Write capability**: readable and writable<br> Exposure bias.|
| MAX_APERTURE_VALUE <sup>12+</sup>         | "MaxApertureValue"          | **Read/Write capability**: readable and writable<br> Smallest F number of the lens.|
| SUBJECT_DISTANCE <sup>12+</sup>           | "SubjectDistance"           | **Read/Write capability**: readable and writable<br> Distance to the subject, in meters.|
| METERING_MODE<sup>10+</sup>               | "MeteringMode"              | **Read/Write capability**: readable and writable<br> Metering mode.|
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"               | **Read/Write capability**: readable and writable<br> Light source. An example value is **Fluorescent**.|
| FLASH <sup>10+</sup>                      | "Flash"                     | **Read/Write capability**: readable and writable<br> Flash status.|
| FOCAL_LENGTH <sup>10+</sup>               | "FocalLength"               | **Read/Write capability**: readable and writable<br> Focal length of the lens.|
| SUBJECT_AREA <sup>12+</sup>               | "SubjectArea"               | **Read/Write capability**: readable and writable<br> Location and area of the main subject in the entire scene.|
| MAKER_NOTE <sup>12+</sup>                 | "MakerNote"                 | **Read/Write capability**: readable and writable<br> Marker used by EXIF/DCF manufacturers to record any required information.<br>This field is read-only in API versions 12 to 19 and is readable and writable in API version 20 and later.|
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
| IS_XMAGE_SUPPORTED <sup>12+</sup> | "HwMnoteIsXmageSupported" | **Read/Write capability**: readable and writable<br>Whether XMAGE is supported.|
| XMAGE_MODE <sup>12+</sup> | "HwMnoteXmageMode" | **Read/Write capability**: readable and writable<br>XMAGE watermark mode.|
| XMAGE_LEFT <sup>12+</sup> | "HwMnoteXmageLeft" | **Read/Write capability**: readable and writable<br>X1 coordinate of the watermark region.|
| XMAGE_TOP <sup>12+</sup> | "HwMnoteXmageTop" | **Read/Write capability**: readable and writable<br>Y1 coordinate of the watermark region.|
| XMAGE_RIGHT <sup>12+</sup> | "HwMnoteXmageRight" | **Read/Write capability**: readable and writable<br>X2 coordinate of the watermark region.|
| XMAGE_BOTTOM <sup>12+</sup> | "HwMnoteXmageBottom" | **Read/Write capability**: readable and writable<br>Y2 coordinate of the watermark region.|
| CLOUD_ENHANCEMENT_MODE <sup>12+</sup> | "HwMnoteCloudEnhancementMode" | **Read/Write capability**: readable and writable<br>Cloud enhancement mode.|
| WIND_SNAPSHOT_MODE <sup>12+</sup> | "HwMnoteWindSnapshotMode" | **Read/Write capability**: read-only<br>Motion snapshot mode.|

## FragmentMapPropertyKey<sup>13+</sup>

Enumerates the fragment map information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value                   | Description                               |
| ------------- | --------------------- | ----------------------------------- |
| X_IN_ORIGINAL | "XInOriginal"         | X coordinate of the upper left corner of the fragment map in the original image.|
| Y_IN_ORIGINAL | "YInOriginal"         | Y coordinate of the upper left corner of the fragment map in the original image.|
| WIDTH         | "FragmentImageWidth"  | Width of the fragment map.                   |
| HEIGHT        | "FragmentImageHeight" | Height of the fragment map.                   |

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
| rowStride     | number                           | Yes  | No  | Row stride. The camera preview stream data needs to be read by stride. For details, see [Solution to Screen Artifacts During Camera Preview](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-deal-stride-solution).      |
| pixelStride   | number                           | Yes  | No  | Pixel stride.  |
| byteBuffer    | ArrayBuffer                      | Yes  | No  | Component buffer.|

## DecodingDynamicRange<sup>12+</sup>

Enumerates the desired dynamic range of an image during decoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| AUTO          | 0    | The image is decoded based on the format. If the image is in HDR format, it is decoded based on the HDR content; otherwise, it is decoded based on the SDR content. The image source created by calling [CreateIncrementalSource](#imagecreateincrementalsource9) is decoded into SDR content. |
| SDR           | 1    | The image is decoded according to the standard dynamic range.  |
| HDR           | 2    | The image is decoded according to the high dynamic range. The image source created by calling [CreateIncrementalSource](#imagecreateincrementalsource9) is decoded into SDR content.    |

## PackingDynamicRange<sup>12+</sup>

Enumerates the desired dynamic range of an image during encoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| AUTO          | 0    | Adaptive. The [pixelmap](#pixelmap7) is encoded based on the format. If the PixelMap is in HDR format, it is encoded based on the HDR content; otherwise, it is encoded based on the SDR content. |
| SDR           | 1    | The image is decoded according to the standard dynamic range.  |

## CropAndScaleStrategy<sup>18+</sup>

Enumerates the order of cropping and scaling.

If the **cropAndScaleStrategy** parameter is not specified in [DecodingOptions](#decodingoptions7) and both **desiredRegion** and **desiredSize** are set, the final decoding result may vary slightly due to differences in decoding algorithms used for different image formats.

For example, if the original image size is 200x200, and you specify **desiredSize:{width: 150, height: 150}, desiredRegion:{x: 0, y: 0, width: 100, height: 100}**, the expectation is to decode the top-left 1/4 region of the original image and then scale the pixelMap size to 150x150.

For JPEG and WebP images (as well as some DNG images that decode a JPEG preview within the file and therefore are treated as JPEG format), the system first performs downsampling. For instance, it might downsample by 7/8 and then crop the region based on a 175x175 image size. As a result, the final cropped region will be slightly larger than the top-left 1/4 of the original image.

For SVG images, which are vector-based and can be scaled without losing clarity, the system scales the image based on the ratio of **desiredSize** to the original image size and then crops the region. This results in a decoded region that may differ from the exact 1/4 region of the original image.

To ensure consistent results when both **desiredRegion** and **desiredSize** are set, set the **cropAndScaleStrategy** parameter to **CROP_FIRST**.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Value      | Description        |
| ------------- | ----------| ------------ |
| SCALE_FIRST   | 1    | If both **desiredRegion** and **desiredSize** are specified, the image is first scaled based on **desiredSize** and then cropped based on **desiredRegion**.    |
| CROP_FIRST    | 2    | If both **desiredRegion** and **desiredSize** are specified, the image is first cropped based on **desiredRegion** and then scaled based on **desiredSize**.    |

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

| Name         | Type      | Read Only| Optional| Description        |
| ------------- | ----------| -- | -- | ------------ |
| displayPrimariesX     | Array\<number>  | No| No| X coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. |
| displayPrimariesY     | Array\<number>  | No| No| Y coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. |
| whitePointX  | number  | No| No| X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].  |
| whitePointY  | number   | No| No| Y coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].  |
| maxLuminance  | number  | No| No| Maximum luminance of the main monitor. The unit is 1, and the maximum value is 65535.  |
| minLuminance  | number   | No| No| Minimum luminance of the main monitor. The unit is 0.0001, and the maximum value is 6.55535.  |
| maxContentLightLevel  | number  | No| No| Maximum luminance of the displayed content. The unit is 1, and the maximum value is 65535.  |
| maxFrameAverageLightLevel  | number  | No| No| Maximum average luminance of the displayed content. The unit is 1, and the maximum value is 65535.|

## GainmapChannel<sup>12+</sup>

Describes the data content of a single channel of the gain map. For details, see ISO 21496-1.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Read Only| Optional| Description        |
| ------------- | ----------| -- | -- | ------------ |
| gainmapMax     | number   | No| No| Maximum value of the gain map. For details, see ISO 21496-1. |
| gainmapMin     | number   | No| No| Minimum value of the gain map. For details, see ISO 21496-1. |
| gamma  | number    | No| No| Gamma. For details, see ISO 21496-1.  |
| baseOffset  | number     | No| No| Offset of the base graphic. For details, see ISO 21496-1.  |
| alternateOffset  | number    | No| No| Offset of the alternative graphic that can be extracted. For details, see ISO 21496-1.   |

## HdrGainmapMetadata<sup>12+</sup>

Describes the metadata keys used by a gain map, that is, the values available for **HDR_GAINMAP_METADATA** in [HdrMetadataKey](#hdrmetadatakey12). For details, see ISO 21496-1.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name         | Type      | Read Only| Optional| Description        |
| ------------- | ----------| -- | -- | ------------ |
| writerVersion     | number   | No| No| Version used by the metadata editor. |
| miniVersion     | number   | No| No| Minimum version that needs to be understood for metadata parsing. |
| gainmapChannelCount  | number    | No| No| Number of color channels of the gain map. When the value is 3, the metadata values of the RGB channels are different. When the value is 1, the metadata values of the RGB channels are the same. For details, see ISO 21496-1. |
| useBaseColorFlag  | boolean     | No| No| Whether to use the color space of the base graphic. For details, see ISO 21496-1. The value **true** means to use the color space of the base graphic, and **false** means the opposite.  |
| baseHeadroom  | number    | No| No|  Headroom of the base graphic, which means the additional brightness that can be added to the base graphic. For details, see ISO 21496-1.  |
| alternateHeadroom  | number     | No| No|  Headroom of the alternate graphic. For details, see ISO 21496-1. |
| channels  | Array<[GainmapChannel](#gainmapchannel12)> | No| No| Number of channels. The length is 3. For details, see ISO 21496-1.|

## HdrMetadataValue<sup>12+</sup>

type HdrMetadataValue = HdrMetadataType | HdrStaticMetadata | ArrayBuffer | HdrGainmapMetadata

Describes the HDR metadata values used by a PixelMap, which corresponds to the values available for [HdrMetadataKey](#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Type               | Description                                           |
| ------------------- | ----------------------------------------------- |
| [HdrMetadataType](#hdrmetadatatype12) | Metadata value corresponding to the **HDR_GAINMAP_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|
| [HdrStaticMetadata](#hdrstaticmetadata12) | Metadata value corresponding to the **HDR_STATIC_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|
| ArrayBuffer | Metadata value corresponding to the **HDR_DYNAMIC_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|
| [HdrGainmapMetadata](#hdrgainmapmetadata12) | Metadata value corresponding to the **HDR_GAINMAP_METADATA** key in [HdrMetadataKey](#hdrmetadatakey12).|

## AntiAliasingLevel<sup>12+</sup>

Enumerates the anti-aliasing levels.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| NONE                | 0      | Nearest neighbor interpolation.  |
| LOW                 | 1      | Bilinear interpolation.  |
| MEDIUM              | 2      | Bilinear interpolation with mipmap enabled. You are advised to use this value when zooming out an image.  |
| HIGH                | 3      | Cubic interpolation.  |

## AllocatorType<sup>15+</sup>

Enumerates the types of the memory used for image decoding.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        | Value  | Description                              |
| ------------ | ---- | ---------------------------------- |
| AUTO         | 0    | The system determines whether DMA memory or shared memory is used.    |
| DMA          | 1    | DMA memory is used.           |
| SHARE_MEMORY | 2    | Shared memory is used.|

## Supplementary Information

### SVG Tags

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

<!--no_check-->