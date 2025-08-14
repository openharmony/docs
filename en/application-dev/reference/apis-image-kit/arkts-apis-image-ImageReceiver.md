# Interface (ImageReceiver)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 9.

The **ImageReceiver** class provides APIs to obtain the surface ID of a component, read the latest image, read the next image, and release the ImageReceiver instance. The ImageReceiver acts as the receiver and consumer of images. Its parameter properties do not actually affect the received images. The configuration of image properties should be done on the sending side (the producer), such as when creating a camera preview stream with [createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput).

Before calling any APIs in ImageReceiver, you must create an ImageReceiver instance.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name    | Type                        | Read Only| Optional| Description              |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| size<sup>9+</sup>     | [Size](arkts-apis-image-i.md#size)                | Yes  | No  | Image size. This parameter does not affect the size of the received image. The actual returned size is determined by the producer, for example, the camera.        |
| capacity<sup>9+</sup> | number                       | Yes  | No  | Maximum number of images that can be accessed at the same time. This parameter is used only as an expected value. The actual capacity is determined by the device hardware.|
| format<sup>9+</sup>   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | Yes  | No  | Image format, which is a constant of [ImageFormat](arkts-apis-image-e.md#imageformat9). (Currently, only **ImageFormat:JPEG** is supported. The format actually returned is determined by the producer, for example, camera.)       |

## getReceivingSurfaceId<sup>9+</sup>

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

## getReceivingSurfaceId<sup>9+</sup>

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

## readLatestImage<sup>9+</sup>

readLatestImage(callback: AsyncCallback\<Image>): void

Reads the latest image from the ImageReceiver instance. This API uses an asynchronous callback to return the result.

This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](arkts-apis-image-Image.md) object returned by this API is no longer needed, call [release](arkts-apis-image-Image.md#release9) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<[Image](arkts-apis-image-Image.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the latest image obtained; otherwise, **err** is an error object. |

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

## readLatestImage<sup>9+</sup>

readLatestImage(): Promise\<Image>

Reads the latest image from the ImageReceiver instance. This API uses a promise to return the result.

This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](arkts-apis-image-Image.md) object returned by this API is no longer needed, call [release](arkts-apis-image-Image.md#release9) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description              |
| ------------------------- | ------------------ |
| Promise<[Image](arkts-apis-image-Image.md)> | Promise used to return the latest image.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readLatestImage().then((img: image.Image) => {
  console.info('Succeeded in reading the latest Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to read the latest Image.code ${error.code},message is ${error.message}`);
})
```

## readNextImage<sup>9+</sup>

readNextImage(callback: AsyncCallback\<Image>): void

Reads the next image from the ImageReceiver instance. This API uses an asynchronous callback to return the result.

This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](arkts-apis-image-Image.md) object returned by this API is no longer needed, call [release](arkts-apis-image-Image.md#release9) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                           | Mandatory| Description                      |
| -------- | ------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[Image](arkts-apis-image-Image.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the next image obtained. Otherwise, **err** is an error object. |

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

## readNextImage<sup>9+</sup>

readNextImage(): Promise\<Image>

Reads the next image from the ImageReceiver instance. This API uses a promise to return the result.

This API can be called to receive data only after the [on](#on9) callback is triggered. When the [Image](arkts-apis-image-Image.md) object returned by this API is no longer needed, call [release](arkts-apis-image-Image.md#release9) to release the object. New data can be received only after the release.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description                |
| ------------------------- | -------------------- |
| Promise<[Image](arkts-apis-image-Image.md)> | Promise used to return the next image.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readNextImage().then((img: image.Image) => {
  console.info('Succeeded in reading the next Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to read the next Image.code ${error.code},message is ${error.message}`);
})
```

## on<sup>9+</sup>

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

## off<sup>13+</sup>

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

## release<sup>9+</sup>

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

## release<sup>9+</sup>

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
