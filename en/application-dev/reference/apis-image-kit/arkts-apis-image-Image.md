# Interface (Image)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

The Image class is used by ImageReceiver and ImageCreator for transferring image objects, with the actual content determined by the producer. For example, the Image object provided by a camera preview stream contains YUV data, whereas the image object provided by a camera photo contains a JPEG file.

An Image instance is returned when [readNextImage](arkts-apis-image-ImageReceiver.md#readnextimage9) and [readLatestImage](arkts-apis-image-ImageReceiver.md#readlatestimage9) are called.

Image properties are initialized only during image creation and cannot be changed later. These properties do not affect the actual image content. You should always rely on the properties written by the image producer, that is, the content actually sent to the [ImageReceiver](./arkts-apis-image-ImageReceiver.md) by the data source.

Images occupy a large amount of memory. When you finish using an Image instance, call [release](#release9) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 9.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    | Type              | Read Only| Optional| Description                                              |
| -------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect<sup>9+</sup> | [Region](arkts-apis-image-i.md#region8) | No  | No  | Image area to be cropped. It is always equal to the entire image and cannot be modified.                                |
| size<sup>9+</sup>     | [Size](arkts-apis-image-i.md#size)      | Yes  | No  | Image size.<br>If the Image object stores camera preview stream data (YUV image data), the width and height in **size** reflect the dimensions of the YUV image.<br>If the Image object stores camera capture stream data (JPEG image data), given that it is an encoded file, the width in **size** is the size of the JPEG file, while the height is set to **1**.<br>Whether the data stored in the Image object is a preview stream or a capture stream depends on whether the application passes **surfaceId** in the receiver to the camera via the [createPreviewOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput) or [createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutputdeprecated) API.<br>For details about the best practices of camera preview and photo capture, see [Dual-Channel Preview (ArkTS)](../../media/camera/camera-dual-channel-preview.md) and [Photo Capture Sample (ArkTS)](../../media/camera/camera-shooting-case.md).|
| format<sup>9+</sup>    | number             | Yes  | No  | Image format. For details, see [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_format).|
| timestamp<sup>12+</sup> | number         | Yes     | No  | Image timestamp. Timestamps, measured in nanoseconds, are usually monotonically increasing. The specific meaning and baseline of these timestamps are determined by the image producer, which is the camera in the camera preview and photo scenarios. As a result, images from different producers may carry timestamps with distinct meanings and baselines, making direct comparison between them infeasible. To obtain the generation time of a photo, you can use the [getImageProperty](arkts-apis-image-ImageSource.md#getimageproperty11) API to read the Exif timestamp information.|
| colorSpace<sup>23+</sup> | [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace) | Yes| No| Color space of the image.<br>**Model restriction**: This API can be used only in the stage model.|

## getComponent<sup>9+</sup>

getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void

Obtains the component buffer from the Image instance based on the color component type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                                   | Mandatory| Description                |
| ------------- | --------------------------------------- | ---- | -------------------- |
| componentType | [ComponentType](arkts-apis-image-e.md#componenttype9)        | Yes  | Component type. (Currently, only **ComponentType:JPEG** is supported. The actual format is determined by the producer, for example, camera.)   |
| callback      | AsyncCallback<[Component](arkts-apis-image-i.md#component9)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the component buffer obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetComponent(img : image.Image) {
  img.getComponent(image.ComponentType.JPEG, (err: BusinessError, component: image.Component) => {
    if (err) {
      console.error(`Failed to get the component.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in getting component.');
    }
  })
}
```

## getComponent<sup>9+</sup>

getComponent(componentType: ComponentType): Promise\<Component>

Obtains the component buffer from the Image instance based on the color component type. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| componentType | [ComponentType](arkts-apis-image-e.md#componenttype9) | Yes  | Component type. (Currently, only **ComponentType:JPEG** is supported. The actual format is determined by the producer, for example, camera.)|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise<[Component](arkts-apis-image-i.md#component9)> | Promise used to return the component buffer.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetComponent(img : image.Image) {
  img.getComponent(image.ComponentType.JPEG).then((component: image.Component) => {
    console.info('Succeeded in getting component.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to get the component.code ${error.code},message is ${error.message}`);
  })
}
```

## release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this Image instance. This API uses an asynchronous callback to return the result.

The corresponding resources must be released before another image arrives.

Images occupy a large amount of memory. When you finish using an Image instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description          |
| -------- | -------------------- | ---- | -------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release(img : image.Image) {
  img.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the image instance.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in releasing the image instance.');
    }
  })
}
```

## release<sup>9+</sup>

release(): Promise\<void>

Releases this Image instance. This API uses a promise to return the result.

The corresponding resources must be released before another image arrives.

Images occupy a large amount of memory. When you finish using an Image instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release(img : image.Image) {
  img.release().then(() => {
    console.info('Succeeded in releasing the image instance.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to release the image instance.code ${error.code},message is ${error.message}`);
  })
}
```

## getBufferData<sup>23+</sup>

getBufferData(): ImageBufferData | null

Obtains ImageBufferData from an image.
> **NOTE**
>
> **byteBuffer** in **ImageBufferData** is a shallow copy of the internal buffer. When the lifecycle of an image ends, do not perform any operations on **byteBuffer**, as this may lead to undefined behavior.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| [ImageBufferData](arkts-apis-image-i.md#imagebufferdata23) \| null | Struct that encapsulates the image data buffer. If no struct is obtained, **null** is returned.|

**Example**

```ts
function GetBufferData(img: image.Image) {
  const bufferData = img.getBufferData();
  if (bufferData == null) {
    console.error('Failed to get the bufferData: bufferData is null.');
    return;
  }
  console.info('Succeeded in getting bufferData.');
}
```

## getMetadata<sup>23+</sup>

getMetadata(key: HdrMetadataKey): HdrMetadataValue | null

Obtains the HDR metadata from an image based on the HDR metadata type.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12) | Yes  | HDR metadata key.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| [HdrMetadataValue](arkts-apis-image-t.md#hdrmetadatavalue12) \| null | Value of the HDR metadata key. If the image does not have HDR metadata, **null** is returned.|

**Error codes**:

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| Error Code| Error Message|
| ------- | --------------------------------------------|
| 7600206 | Invalid parameter.          |
| 7600302 | Memory copy failed.         |

**Example**

```ts
async function GetMetadata(img : image.Image) {
  try {
    let staticMetadata = img.getMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA);
    console.info(`getMetadata:${staticMetadata}`);
  } catch (err) {
    console.error('Failed to getMetadata.' + err);
  }
}
```
