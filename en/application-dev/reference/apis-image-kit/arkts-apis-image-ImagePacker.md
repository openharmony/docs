# Interface (ImagePacker)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **ImagePacker** class provides APIs to compress and encode images. Before calling any API in ImagePacker, you must use [createImagePacker](arkts-apis-image-f.md#imagecreateimagepacker) to create an ImagePacker object. Currently, this class applies only to images in .jpeg, .webp, .png, or heif<sup>12+</sup> (depending on the hardware).

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name            | Type          | Read Only| Optional| Description                      |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | Yes  | No  | Supported formats, including .jpeg, .webp, .png, and heic<sup>12+</sup> (depending on the hardware).|

## packToData<sup>13+</sup>

packToData(source: ImageSource, options: PackingOption): Promise\<ArrayBuffer>

Compresses or re-encodes an image. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](arkts-apis-image-ImageSource.md)     | Yes  | Image source to compress or re-encode.|
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | If the parameter is invalid. |
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
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

## packToData<sup>13+</sup>

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
| source | [PixelMap](arkts-apis-image-PixelMap.md)           | Yes  | PixelMap to compress or re-encode.|
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.    |

**Return value**

| Type                 | Description                                        |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the compressed or encoded image data.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | If the parameter is invalid. |
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
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

## packing<sup>13+</sup>

packing(picture: Picture, options: PackingOption): Promise\<ArrayBuffer>

Compresses or re-encodes an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name          | Type                                                | Mandatory| Description                |
| ---------------- | ---------------------------------------------------- | ---- | -------------------- |
| picture | [Picture](arkts-apis-image-Picture.md)                           | Yes  | Picture to compress or re-encode.|
| options          | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.      |

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

## packToDataFromPixelmapSequence<sup>18+</sup>

packToDataFromPixelmapSequence(pixelmapSequence: Array\<PixelMap>, options: PackingOptionsForSequence): Promise\<ArrayBuffer>

Encodes multiple PixelMap objects into GIF data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name          | Type                                                     | Mandatory| Description                  |
| ---------------- | --------------------------------------------------------- | ---- | ---------------------- |
| pixelmapSequence | Array\<[PixelMap](arkts-apis-image-PixelMap.md)>                            | Yes  | PixelMaps to encode.|
| options          | [PackingOptionsForSequence](arkts-apis-image-i.md#packingoptionsforsequence18) | Yes  | Options for encoding animated images.        |

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the encoded data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
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

## release

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

## release

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

## packToFile<sup>11+</sup>

packToFile(source: ImageSource, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void

Encodes the image source into a file based on the specified encoding parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                          |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [ImageSource](arkts-apis-image-ImageSource.md)     | Yes  | Image source to encode.                |
| fd       | number                          | Yes  | File descriptor.                  |
| options   | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
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

## packToFile<sup>11+</sup>

packToFile (source: ImageSource, fd: number, options: PackingOption): Promise\<void>

Encodes the image source into a file based on the specified encoding parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](arkts-apis-image-ImageSource.md)     | Yes  | Image source to encode.|
| fd     | number                          | Yes  | File descriptor.  |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.|

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
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

## packToFile<sup>11+</sup>

packToFile (source: PixelMap, fd: number, options: PackingOption,  callback: AsyncCallback\<void>): void

Encodes the PixelMap into a file based on the specified encoding parameters. This API uses an asynchronous callback to return the result.

> **NOTE**
> If error code 62980115 is returned, the parameters are abnormal. The possible cause is that the PixelMap object is released in advance. You need to check the code and ensure that the PixelMap object is released after this API is called.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                          |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [PixelMap](arkts-apis-image-PixelMap.md)          | Yes  | PixelMap to encode.          |
| fd       | number                          | Yes  | File descriptor.                  |
| options   | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
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

## packToFile<sup>11+</sup>

packToFile (source: PixelMap, fd: number, options: PackingOption): Promise\<void>

Encodes the PixelMap into a file based on the specified encoding parameters. This API uses a promise to return the result.

> **NOTE**
> If error code 62980115 is returned, the parameters are abnormal. The possible cause is that the PixelMap object is released in advance. You need to check the code and ensure that the PixelMap object is released after this API is called.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description                |
| ------ | ------------------------------- | ---- | -------------------- |
| source | [PixelMap](arkts-apis-image-PixelMap.md)          | Yes  | PixelMap to encode.|
| fd     | number                          | Yes  | File descriptor.        |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.      |

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
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

## packToFile<sup>13+</sup>

packToFile(picture: Picture, fd: number, options: PackingOption): Promise\<void>

Encodes the Picture into a file based on the specified encoding parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name | Type                        | Mandatory| Description                |
| ------- | ---------------------------- | ---- | -------------------- |
| picture  | [Picture](arkts-apis-image-Picture.md)          | Yes  | Picture to encode.|
| fd      | number                       | Yes  | File descriptor.        |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.      |

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

## packToFileFromPixelmapSequence<sup>18+</sup>

packToFileFromPixelmapSequence(pixelmapSequence: Array\<PixelMap>, fd: number, options: PackingOptionsForSequence): Promise\<void>

Encodes multiple PixelMaps into a GIF file. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name          | Type                                                     | Mandatory| Description                  |
| ---------------- | --------------------------------------------------------- | ---- | ---------------------- |
| pixelmapSequence | Array<[PixelMap](arkts-apis-image-PixelMap.md)>                             | Yes  | PixelMaps to encode.|
| fd               | number                                                    | Yes  | File descriptor.          |
| options          | [PackingOptionsForSequence](arkts-apis-image-i.md#packingoptionsforsequence18) | Yes  | Options for encoding animated images.        |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
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

## packing<sup>(deprecated)</sup>

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
| source   | [ImageSource](arkts-apis-image-ImageSource.md)        | Yes  | Image source to compress or re-encode.                    |
| option   | [PackingOption](arkts-apis-image-i.md#packingoption)    | Yes  | Encoding parameters.                     |
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

## packing<sup>(deprecated)</sup>

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
| source | [ImageSource](arkts-apis-image-ImageSource.md)     | Yes  | Image source to compress or re-encode.|
| option | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.|

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

## packing<sup>(deprecated)</sup>

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
| source   | [PixelMap](arkts-apis-image-PixelMap.md)           | Yes  | PixelMap to compress or re-encode.              |
| option   | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.                    |
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

## packing<sup>(deprecated)</sup>

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
| source | [PixelMap](arkts-apis-image-PixelMap.md)           | Yes  | PixelMap to compress or re-encode.|
| option | [PackingOption](arkts-apis-image-i.md#packingoption) | Yes  | Encoding parameters.    |

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
