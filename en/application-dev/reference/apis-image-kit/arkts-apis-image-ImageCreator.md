# Interface (ImageCreator)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 9.

The **ImageCreator** class provides APIs for applications to request an image data area and compile image data.

Before calling any APIs in ImageCreator, you must create an ImageCreator instance. ImageCreator does not support multiple threads.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

| Name    | Type                        | Read Only| Optional| Description              |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| capacity<sup>9+</sup> | number                       | Yes  | No  | Maximum number of images that can be accessed at the same time.|
| format<sup>9+</sup>   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | Yes  | No  | Image format.        |

## dequeueImage<sup>9+</sup>

dequeueImage(callback: AsyncCallback\<Image>): void

Obtains an image buffer from the idle queue and writes image data into it. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name       | Type                                   | Mandatory| Description                |
| ------------- | ---------------------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<[Image](arkts-apis-image-Image.md)>  | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the latest image obtained; otherwise, **err** is an error object. |

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

## dequeueImage<sup>9+</sup>

dequeueImage(): Promise\<Image>

Obtains an image buffer from the idle queue and writes image data into it. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Return value**

| Type            | Description          |
| --------------- | ------------- |
| Promise\<[Image](arkts-apis-image-Image.md)> | Promise used to return the latest image.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

creator.dequeueImage().then((img: image.Image) => {
  console.info('Succeeded in dequeuing the Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to dequeue the Image.code ${error.code},message is ${error.message}`);
})
```

## queueImage<sup>9+</sup>

queueImage(interface: Image, callback: AsyncCallback\<void>): void

Places the drawn image in the queue. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name       | Type                    | Mandatory| Description                |
| ------------- | -------------------------| ---- | -------------------- |
| interface     | [Image](arkts-apis-image-Image.md)                    | Yes  | Drawn image.|
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

## queueImage<sup>9+</sup>

queueImage(interface: Image): Promise\<void>

Places the drawn image in the queue. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name         | Type    | Mandatory| Description               |
| ------------- | --------| ---- | ------------------- |
| interface     | [Image](arkts-apis-image-Image.md)   | Yes  | Drawn image.|

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

## on<sup>9+</sup>

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

## off<sup>13+</sup>

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

## release<sup>9+</sup>

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

## release<sup>9+</sup>

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
