# @ohos.multimedia.image (Image Processing)

The **Image** module provides APIs for image processing. You can use the APIs to create a **PixelMap** object with specified properties or read image pixel data (even in an area).

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import image from '@ohos.multimedia.image';
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>

Creates a **PixelMap** object with the default BGRA_8888 format and pixel properties specified. This API uses a promise to return the result.

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
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap : image.PixelMap) => {
  console.log('Succeeded in creating pixelmap.');
}).catch((error : BusinessError) => {
  console.error('Failed to create pixelmap.');
})
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object with the default BGRA_8888 format and pixel properties specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format. |
| options  | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties.                    |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (error : BusinessError, pixelMap : image.PixelMap) => {
    if(error) {
        console.error('Failed to create pixelmap.');
    } else {
        console.log('Succeeded in creating pixelmap.');
    }
})
```

## image.createPixelMapFromParcel<sup>11+</sup>

createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap

Unmarshals a **MessageSequence** object to obtain a **PixelMap** object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](js-apis-rpc.md#messagesequence9) | Yes  | **MessageSequence** object that stores the **PixelMap** information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | Returns a **PixelMap** object if the operation is successful; throws an error otherwise.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | If the operation failed|
| 62980097 | If the ipc error|
| 62980115 | Invalid input parameter|
| 62980105 | Failed to get the data|
| 62980177 | Abnormal API environment|
| 62980178 | Failed to create the PixelMap|
| 62980179 | Abnormal buffer size|
| 62980180 | FD mapping failed|
| 62980246 | Failed to read the PixelMap|

**Example**

```ts
import image from '@ohos.multimedia.image';
import rpc from '@ohos.rpc';
class MySequence implements rpc.Parcelable {
    pixel_map : image.PixelMap;
    constructor(conPixelmap : image.PixelMap) {
        this.pixel_map = conPixelmap;
    }
    marshalling(messageSequence : rpc.MessageSequence) {
        this.pixel_map.marshalling(messageSequence);
        return true;
    }
    unmarshalling(messageSequence : rpc.MessageSequence) {
        try {
            this.pixel_map = image.createPixelMapFromParcel(messageSequence);
        } catch(e) {
            console.error('createPixelMapFromParcel error: '+ e);
        }
      return true;
    }
}
async function Demo() {
   const color : ArrayBuffer = new ArrayBuffer(96);
   let bufferArr : Uint8Array = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i++) {
      bufferArr[i] = 0x80;
   }
   let opts : image.InitializationOptions = {
      editable: true,
      pixelFormat: 4,
      size: { height: 4, width: 6 },
      alphaType: 3
   }
   let pixelMap : image.PixelMap | undefined = undefined;
   await image.createPixelMap(color, opts).then((srcPixelMap : image.PixelMap) => {
      pixelMap = srcPixelMap;
   })
   if (pixelMap != undefined) {
     // Implement serialization.
     let parcelable : MySequence = new MySequence(pixelMap);
     let data : rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);

     // Deserialize to obtain data through the RPC.
     let ret : MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);

     // Obtain the PixelMap object.
     let unmarshPixelmap = ret.pixel_map;
   }
}
```

## PixelMap<sup>7+</sup>

Provides APIs to read or write image pixel map data and obtain image pixel map information. Before calling any API in **PixelMap**, you must use **createPixelMap** to create a **PixelMap** object. Currently, the maximum size of a serialized pixel map is 128 MB. A larger size will cause a display failure. The size is calculated as follows: Width * Height * Number of bytes occupied by each pixel.

Since API version 11, **PixelMap** supports cross-thread calls through workers. If a **PixelMap** object is invoked by another thread through [Worker](js-apis-worker.md), all APIs of the **PixelMap** object cannot be called in the original thread. Otherwise, error 501 is reported, indicating that the server cannot complete the request.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.Core

| Name      | Type   | Readable| Writable| Description                      |
| ---------- | ------- | ---- | ---- | -------------------------- |
| isEditable | boolean | Yes  | No  | Whether the image pixel map is editable.|

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

Reads data of this pixel map and writes the data to an **ArrayBuffer**. This API uses a promise to return the result. If this pixel map is created in the BGRA_8888 format, the data read is the same as the original data.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                                                                 |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | Yes  | Buffer to which the image pixel map data will be written. The buffer size is obtained by calling **getPixelBytesNumber**.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const readBuffer : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
pixelMap.readPixelsToBuffer(readBuffer).then(() => {
    console.log('Succeeded in reading image pixel data.'); // Called if the condition is met.
}).catch((error : BusinessError) => {
    console.error('Failed to read image pixel data.');  // Called if no condition is met.
})
```

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads data of this pixel map and writes the data to an **ArrayBuffer**. This API uses an asynchronous callback to return the result. If this pixel map is created in the BGRA_8888 format, the data read is the same as the original data.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Buffer to which the image pixel map data will be written. The buffer size is obtained by calling **getPixelBytesNumber**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.                                                                       |

**Example**

```ts
import {BusinessError} from '@ohos.base';
const readBuffer : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
pixelMap.readPixelsToBuffer(readBuffer, (err : BusinessError, res : void) => {
    if(err) {
        console.error('Failed to read image pixel data.');  // Called if no condition is met.
    } else {
        console.log('Succeeded in reading image pixel data.'); // Called if the condition is met.
    }
})
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

Reads image pixel map data in an area. This API uses a promise to return the data read.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](#positionarea7) | Yes  | Area from which the image pixel map data will be read.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const area : image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
}
pixelMap.readPixels(area).then(() => {
    console.log('Succeeded in reading the image data in the area.'); // Called if the condition is met.
}).catch((error : BusinessError) => {
    console.error('Failed to read the image data in the area.'); // Called if no condition is met.
})
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

Reads image pixel map data in an area. This API uses an asynchronous callback to return the data read.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                          | Mandatory| Description                          |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](#positionarea7) | Yes  | Area from which the image pixel map data will be read.      |
| callback | AsyncCallback\<void>           | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (err : BusinessError, pixelMap : image.PixelMap) => {
    if(pixelMap == undefined){
        console.error('createPixelMap failed.');
    } else {
        const area : image.PositionArea = { pixels: new ArrayBuffer(8),
            offset: 0,
            stride: 8,
            region: { size: { height: 1, width: 2 }, x: 0, y: 0 }};
        pixelMap.readPixels(area, (err : BusinessError) => {
            if (err != undefined) {
	        console.error('Failed to read pixelmap from the specified area.');
	    } else {
	        console.info('Succeeded to read pixelmap from the specified area.');
	    }
        })
    }
})
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea): Promise\<void>

Writes image pixel map data to an area. This API uses a promise to return the operation result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](#positionarea7) | Yes  | Area to which the image pixel map data will be written.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then( (pixelMap : image.PixelMap)  => {
        if (pixelMap == undefined) {
            console.error('createPixelMap failed.');
            return;
        }
        const area : image.PositionArea = { pixels: new ArrayBuffer(8),
            offset: 0,
            stride: 8,
            region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
        }
        let bufferArr : Uint8Array = new Uint8Array(area.pixels);
        for (let i = 0; i < bufferArr.length; i++) {
            bufferArr[i] = i + 1;
        }
        pixelMap.writePixels(area).then(() => {
            console.info('Succeeded to write pixelmap into the specified area.');
        }).catch((error : BusinessError) => {
            console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
        })
    }).catch((error : BusinessError) => {
        console.error('error: ' + error);
    })
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

Writes image pixel map data to an area. This API uses an asynchronous callback to return the operation result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name   | Type                          | Mandatory| Description                          |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](#positionarea7) | Yes  | Area to which the image pixel map data will be written.          |
| callback  | AsyncCallback\<void>           | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const area : image.PositionArea = { pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
}
let bufferArr : Uint8Array = new Uint8Array(area.pixels);
for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
}
pixelMap.writePixels(area, (error : BusinessError) => {
    if (error != undefined) {
        console.error('Failed to write pixelmap into the specified area.');
    } else {
        console.info('Succeeded to write pixelmap into the specified area.');
    }
})
```

### writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

Reads image data in an **ArrayBuffer** and writes the data to a **PixelMap** object. This API uses a promise to return the result.

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
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let bufferArr : Uint8Array = new Uint8Array(color);
for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
}
pixelMap.writeBufferToPixels(color).then(() => {
    console.log("Succeeded in writing data from a buffer to a PixelMap.");
}).catch((error : BusinessError) => {
    console.error("Failed to write data from a buffer to a PixelMap.");
})
```

### writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads image data in an **ArrayBuffer** and writes the data to a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | Yes  | Buffer from which the image data will be read.                |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let bufferArr : Uint8Array = new Uint8Array(color);
for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
}
pixelMap.writeBufferToPixels(color, (err : BusinessError) => {
    if (err != undefined) {
        console.error("Failed to write data from a buffer to a PixelMap.");
        return;
    } else {
	console.log("Succeeded in writing data from a buffer to a PixelMap.");
    }
});
```

### getImageInfo<sup>7+</sup>

getImageInfo(): Promise\<ImageInfo>

Obtains pixel map information of this image. This API uses a promise to return the information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](#imageinfo)> | Promise used to return the pixel map information. If the operation fails, an error message is returned.|

**Example**

```ts
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 2, size: { height: 6, width: 8 } }
image.createPixelMap(color, opts).then((pixelMap : image.PixelMap) => {
    if (pixelMap == undefined) {
        console.error("Failed to obtain the image pixel map information.");
    }
    pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
        if (imageInfo == undefined) {
            console.error("Failed to obtain the image pixel map information.");
        }
        if (imageInfo.size.height == 4 && imageInfo.size.width == 6) {
            console.log("Succeeded in obtaining the image pixel map information.");
        }
    })
})
```

### getImageInfo<sup>7+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains pixel map information of this image. This API uses an asynchronous callback to return the information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the pixel map information. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (err : BusinessError, pixelMap : image.PixelMap) => {
    if (pixelMap == undefined) {
        console.error("Failed to obtain the image pixel map information.");
    }
    pixelMap.getImageInfo((err : BusinessError, imageInfo : image.ImageInfo) => {
        if (imageInfo == undefined) {
            console.error("Failed to obtain the image pixel map information.");
        }
        if (imageInfo.size.height == 4 && imageInfo.size.width == 6) {
            console.log("Succeeded in obtaining the image pixel map information.");
        }
    })
})
```

### getBytesNumberPerRow<sup>7+</sup>

getBytesNumberPerRow(): number

Obtains the number of bytes per row of this image pixel map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Number of bytes per row.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (err : BusinessError, pixelMap : image.PixelMap) => {
    let rowCount : number = pixelMap.getBytesNumberPerRow();
})
```

### getPixelBytesNumber<sup>7+</sup>

getPixelBytesNumber(): number

Obtains the total number of bytes of this image pixel map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Total number of bytes.|

**Example**

```ts
let pixelBytesNumber : number = pixelMap.getPixelBytesNumber();
```

### getDensity<sup>9+</sup>

getDensity():number

Obtains the density of this image pixel map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description           |
| ------ | --------------- |
| number | Density of the image pixel map.|

**Example**

```ts
let getDensity : number = pixelMap.getDensity();
```

### opacity<sup>9+</sup>

opacity(rate: number, callback: AsyncCallback\<void>): void

Sets an opacity rate for this image pixel map. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | Yes  | Opacity rate to set.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
let rate = 0.5;
pixelMap.opacity(rate, (err : BusinessError) => {
	if (err) {
        console.error("Failed to set opacity.");
        return;
    } else {
        console.log("Succeeded in setting opacity.");
	}
})
```

### opacity<sup>9+</sup>

opacity(rate: number): Promise\<void>

Sets an opacity rate for this image pixel map. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | Yes  | Opacity rate to set.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
async function Demo() {
    await pixelMap.opacity(0.5);
}
```

### createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

Creates a **PixelMap** object that contains only the alpha channel information. This object can be used for the shadow effect. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                       |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Example**

```ts
async function Demo() {
    await pixelMap.createAlphaPixelmap();
}   
```

### createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object that contains only the alpha channel information. This object can be used for the shadow effect. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                    |
| -------- | ------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<PixelMap> | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
pixelMap.createAlphaPixelmap((err : BusinessError, alphaPixelMap : image.PixelMap) => {
    if (alphaPixelMap == undefined) {
        console.error('Failed to obtain new pixel map.');
    } else {
        console.info('Succeed in obtaining new pixel map.');
    }
})
```

### scale<sup>9+</sup>

scale(x: number, y: number, callback: AsyncCallback\<void>): void

Scales this image based on the input width and height. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | Yes  | Scaling ratio of the width.|
| y        | number               | Yes  | Scaling ratio of the height.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned. |

**Example**

```ts
async function Demo() {
    await pixelMap.scale(2.0, 1.0);
}
```

### scale<sup>9+</sup>

scale(x: number, y: number): Promise\<void>

Scales this image based on the input width and height. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scaling ratio of the width.|
| y      | number | Yes  | Scaling ratio of the height.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
async function Demo() {
    await pixelMap.scale(2.0, 1.0);
}
```

### translate<sup>9+</sup>

translate(x: number, y: number, callback: AsyncCallback\<void>): void

Translates this image based on the input coordinates. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| x        | number               | Yes  | X coordinate to translate.                 |
| y        | number               | Yes  | Y coordinate to translate.                 |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
async function Demo() {
    await pixelMap.translate(3.0, 1.0);
}
```

### translate<sup>9+</sup>

translate(x: number, y: number): Promise\<void>

Translates this image based on the input coordinates. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| x      | number | Yes  | X coordinate to translate.|
| y      | number | Yes  | Y coordinate to translate.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
async function Demo() {
    await pixelMap.translate(3.0, 1.0);
}
```

### rotate<sup>9+</sup>

rotate(angle: number, callback: AsyncCallback\<void>): void

Rotates this image based on the input angle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Angle to rotate.             |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
let angle = 90.0;
pixelMap.rotate(angle, (err : BusinessError) => {
    if (err != undefined) {
        console.error("Failed to set rotation.");
        return;
    } else {
        console.log("Succeeded in setting rotation.");
    }
})
```

### rotate<sup>9+</sup>

rotate(angle: number): Promise\<void>

Rotates this image based on the input angle. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                         |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | Yes  | Angle to rotate.             |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
async function Demo() {
    await pixelMap.rotate(90.0);
}
```

### flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void

Flips this image horizontally or vertically, or both. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description                         |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally.                   |
| vertical   | boolean              | Yes  | Whether to flip the image vertically.                   |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
async function Demo() {
    await pixelMap.flip(false, true);
}
```

### flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean): Promise\<void>

Flips this image horizontally or vertically, or both. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type   | Mandatory| Description     |
| ---------- | ------- | ---- | --------- |
| horizontal | boolean | Yes  | Whether to flip the image horizontally.|
| vertical   | boolean | Yes  | Whether to flip the image vertically.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
async function Demo() {
    await pixelMap.flip(false, true);
}
```

### crop<sup>9+</sup>

crop(region: Region, callback: AsyncCallback\<void>): void

Crops this image based on the input size. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](#region7)   | Yes  | Size of the image after cropping.                 |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
async function Demo() {
    await pixelMap.crop({ x: 0, y: 0, size: { height: 100, width: 100 } } as image.Region);
}
```

### crop<sup>9+</sup>

crop(region: Region): Promise\<void>

Crops this image based on the input size. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type              | Mandatory| Description       |
| ------ | ------------------ | ---- | ----------- |
| region | [Region](#region7) | Yes  | Size of the image after cropping.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
async function Demo() {
    await pixelMap.crop({ x: 0, y: 0, size: { height: 100, width: 100 } } as image.Region);
}
```

### getColorSpace<sup>10+</sup>

getColorSpace(): colorSpaceManager.ColorSpaceManager

Obtains the color space of this image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                               | Description            |
| ----------------------------------- | ---------------- |
| [colorSpaceManager.ColorSpaceManager](js-apis-colorSpaceManager.md#colorspacemanager) | Color space obtained.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980101| If the image data abnormal              |
| 62980103| If the image data unsupport              |
| 62980115| If the image parameter invalid             |

**Example**

```ts
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';
async function Demo() {
    let csm : Object = pixelMap.getColorSpace();
}
```

### setColorSpace<sup>10+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void

Sets the color space for this image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                               | Mandatory| Description           |
| ---------- | ----------------------------------- | ---- | --------------- |
| colorSpace | [colorSpaceManager.ColorSpaceManager](js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Color space to set.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980111| If the operation invalid        |
| 62980115| If the image parameter invalid             |

**Example**

```ts
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';
async function Demo() {
    let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
    let csm : colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
    pixelMap.setColorSpace(csm);
}
```

### marshalling<sup>10+</sup>

marshalling(sequence: rpc.MessageSequence): void

Marshals this **PixelMap** object and writes it to a **MessageSequence** object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](js-apis-rpc.md#messagesequence9)  | Yes  | **MessageSequence** object.                |

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | If the input parameter invalid              |
| 62980097 | If the ipc error              |

**Example**

```ts
import image from '@ohos.multimedia.image';
import rpc from '@ohos.rpc';
class MySequence implements rpc.Parcelable {
    pixel_map : image.PixelMap;
    constructor(conPixelMap : image.PixelMap) {
        this.pixel_map = conPixelMap;
    }
    marshalling(messageSequence : rpc.MessageSequence) {
        this.pixel_map.marshalling(messageSequence);
        console.log('marshalling');
        return true;
    }
    unmarshalling(messageSequence : rpc.MessageSequence) {
      image.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel : image.PixelMap) => {
        pixelParcel.unmarshalling(messageSequence).then(async (pixelMap : image.PixelMap) => {
          this.pixel_map = pixelMap;
          await pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
            console.log("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
          })
        })
      });
      return true;
    }
}
async function Demo() {
   const color : ArrayBuffer = new ArrayBuffer(96);
   let bufferArr : Uint8Array = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i++) {
      bufferArr[i] = 0x80;
   }
   let opts : image.InitializationOptions = {
      editable: true,
      pixelFormat: 4,
      size: { height: 4, width: 6 },
      alphaType: 3
   }
   let pixelMap : image.PixelMap | undefined = undefined;
   await image.createPixelMap(color, opts).then((srcPixelMap : image.PixelMap) => {
      pixelMap = srcPixelMap;
   })
   if (pixelMap != undefined) {
     // Implement serialization.
     let parcelable : MySequence = new MySequence(pixelMap);
     let data : rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);


     // Deserialize to obtain data through the RPC.
     let ret : MySequence = new MySequence(pixelMap);
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
| sequence               | [rpc.MessageSequence](js-apis-rpc.md#messagesequence9) | Yes  | **MessageSequence** object that stores the **PixelMap** information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | If the input parameter invalid              |
| 62980097 | If the ipc error              |
| 62980096 | If fail to create async work         |

**Example**

```ts
import image from '@ohos.multimedia.image';
import rpc from '@ohos.rpc';
class MySequence implements rpc.Parcelable {
    pixel_map : image.PixelMap;
    constructor(conPixelMap : image.PixelMap) {
        this.pixel_map = conPixelMap;
    }
    marshalling(messageSequence : rpc.MessageSequence) {
        this.pixel_map.marshalling(messageSequence);
        console.log('marshalling');
        return true;
    }
    unmarshalling(messageSequence : rpc.MessageSequence) {
      image.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel : image.PixelMap) => {
        pixelParcel.unmarshalling(messageSequence).then(async (pixelMap : image.PixelMap) => {
          this.pixel_map = pixelMap;
          await pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
            console.log("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
          })
        })
      });
      return true;
    }
}
async function Demo() {
   const color : ArrayBuffer = new ArrayBuffer(96);
   let bufferArr : Uint8Array = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i++) {
      bufferArr[i] = 0x80;
   }
   let opts : image.InitializationOptions = {
      editable: true,
      pixelFormat: 4,
      size: { height: 4, width: 6 },
      alphaType: 3
   }
   let pixelMap : image.PixelMap | undefined = undefined;
   await image.createPixelMap(color, opts).then((srcPixelMap : image.PixelMap) => {
      pixelMap = srcPixelMap;
   })
   if (pixelMap != undefined) {
     // Implement serialization.
     let parcelable : MySequence = new MySequence(pixelMap);
     let data : rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);


     // Deserialize to obtain data through the RPC.
     let ret : MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);
   }
}
```

### release<sup>7+</sup>

release():Promise\<void>

Releases this **PixelMap** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
pixelMap.release().then(() => {
    console.log('Succeeded in releasing pixelmap object.');
}).catch((error : BusinessError) => {
    console.error('Failed to release pixelmap object.');
})
```

### release<sup>7+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
pixelMap.release((err : BusinessError) => {
    if (err != undefined) {
        console.error('Failed to release pixelmap object.');
    } else {
        console.log('Succeeded in releasing pixelmap object.');
    }
})
```

## image.createImageSource

createImageSource(uri: string): ImageSource

Creates an **ImageSource** instance based on the URI.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | Yes  | Image path. Currently, only the application sandbox path is supported.<br>Currently, the following formats are supported: .jpg, .png, .gif, .bmp, .webp, raw [SVG<sup>10+</sup>](#svg), and .ico<sup>11+</sup>.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
// Stage model
const context : Context = getContext(this);
const path : string = context.cacheDir + "/test.jpg";
const imageSourceApi : image.ImageSource = image.createImageSource(path);
```

```ts
// FA model
import featureAbility from '@ohos.ability.featureAbility';

const context : featureAbility.Context = featureAbility.getContext();
const path : string = context.getCacheDir() + "/test.jpg";
const imageSourceApi : image.ImageSource = image.createImageSource(path);
```

## image.createImageSource<sup>9+</sup>

createImageSource(uri: string, options: SourceOptions): ImageSource

Creates an **ImageSource** instance based on the URI.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                               |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| uri     | string                          | Yes  | Image path. Currently, only the application sandbox path is supported.<br>Currently, the following formats are supported: .jpg, .png, .gif, .bmp, .webp, raw [SVG<sup>10+</sup>](#svg), and .ico<sup>11+</sup>.|
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image index and default property value.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
let sourceOptions : image.SourceOptions = { sourceDensity: 120 };
let imageSource : image.ImageSource = image.createImageSource('test.png', sourceOptions);
```

## image.createImageSource<sup>7+</sup>

createImageSource(fd: number): ImageSource

Creates an **ImageSource** instance based on the file descriptor.

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
const imageSourceApi : image.ImageSource = image.createImageSource(0);
```

## image.createImageSource<sup>9+</sup>

createImageSource(fd: number, options: SourceOptions): ImageSource

Creates an **ImageSource** instance based on the file descriptor.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                               |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| fd      | number                          | Yes  | File descriptor.                     |
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image index and default property value.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
let sourceOptions : image.SourceOptions = { sourceDensity: 120 };
const imageSourceApi : image.ImageSource = image.createImageSource(0, sourceOptions);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer): ImageSource

Creates an **ImageSource** instance based on the buffers.

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
const buf : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
const imageSourceApi : image.ImageSource = image.createImageSource(buf);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource

Creates an **ImageSource** instance based on the buffers.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type                            | Mandatory| Description                                |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| buf    | ArrayBuffer                      | Yes  | Array of image buffers.                    |
| options | [SourceOptions](#sourceoptions9) | Yes  | Image properties, including the image index and default property value.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
const data : ArrayBuffer= new ArrayBuffer(112);
let sourceOptions : image.SourceOptions = { sourceDensity: 120 };
const imageSourceApi : image.ImageSource = image.createImageSource(data, sourceOptions);
```

## image.createImageSource<sup>11+</sup>

createImageSource(rawfile: resourceManager.RawFileDescriptor, options: SourceOptions): ImageSource

Creates an **ImageSource** instance by using the raw file descriptor of the image resource file.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type                            | Mandatory| Description                                |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| rawfile | [resourceManager.RawFileDescriptor](js-apis-resource-manager.md#rawfiledescriptor8) | Yes| Raw file descriptor of the image resource file.|
| options | [SourceOptions](#sourceoptions9) | No| Image properties, including the image index and default property value.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

Stage model

```ts
// Code on the stage model
const context : Context = getContext(this);
// Obtain a resource manager.
const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
const rawFileDescriptor : resourceManager.RawFileDescriptor = await resourceMgr.getRawFd('test.jpg');
const imageSourceApi : image.ImageSource = image.createImageSource(rawFileDescriptor);
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer): ImageSource

Creates an **ImageSource** instance in incremental mode based on the buffers.

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
const buf : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
const imageSourceIncrementalSApi : image.ImageSource = image.CreateIncrementalSource(buf);
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource

Creates an **ImageSource** instance in incremental mode based on the buffers.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                           | Mandatory| Description                                |
| ------- | ------------------------------- | ---- | ------------------------------------ |
| buf     | ArrayBuffer                     | Yes  | Incremental data.                          |
| options | [SourceOptions](#sourceoptions9) | No  | Image properties, including the image index and default property value.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns undefined otherwise.|

**Example**

```ts
const buf : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
const imageSourceIncrementalSApi : image.ImageSource = image.CreateIncrementalSource(buf);
```

## ImageSource

Provides APIs to obtain image information. Before calling any API in **ImageSource**, you must use **createImageSource** to create an **ImageSource** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name            | Type          | Readable| Writable| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats, including PNG, JPEG, BMP, GIF, WebP, and RAW.|

### getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

Obtains information about an image with the specified index. This API uses an asynchronous callback to return the information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | Yes  | Index of the image.                    |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the image information.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.getImageInfo(0,(error : BusinessError, imageInfo : image.ImageInfo) => { 
    if(error) {
        console.error('getImageInfo failed.');
    } else {
        console.log('getImageInfo succeeded.');
    }
})
```

### getImageInfo

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains information about this image. This API uses an asynchronous callback to return the information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the image information.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.getImageInfo((err : BusinessError, imageInfo : image.ImageInfo) => { 
    if (err != undefined) {
        console.error(`Failed to obtaining the image information.code is ${err.code}, message is ${err.message}`);
    } else {
        console.log('Succeeded in obtaining the image information.');
    }
})
```

### getImageInfo

getImageInfo(index?: number): Promise\<ImageInfo>

Obtains information about an image with the specified index. This API uses a promise to return the image information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | No  | Index of the image. If this parameter is not set, the default value **0** is used.|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](#imageinfo)> | Promise used to return the image information.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.getImageInfo(0)
    .then((imageInfo : image.ImageInfo) => {
		console.log('Succeeded in obtaining the image information.');
	}).catch((error : BusinessError) => {
		console.error('Failed to obtain the image information.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result. The image must be in JPEG format and contain EXIF information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                               | Yes  | Name of the property.                        |
| options | [GetImagePropertyOptions](#getimagepropertyoptions7) | No  | Image properties, including the image index and default property value.|

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise used to return the property value. If the operation fails, the default value is returned.|

**Example**

```ts
imageSourceApi.getImageProperty("BitsPerSample")
    .then((data : string) => {
		console.log('Succeeded in getting the value of the specified attribute key of the image.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

Obtains the value of a property with the specified index in this image. This API uses an asynchronous callback to return the result. The image must be in JPEG format and contain EXIF information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | Yes  | Name of the property.                                                |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.getImageProperty("BitsPerSample",(error : BusinessError, data : string) => { 
    if(error) {
        console.error('Failed to get the value of the specified attribute key of the image.');
    } else {
        console.log('Succeeded in getting the value of the specified attribute key of the image.');
    }
})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

Obtains the value of a property in this image. This API uses an asynchronous callback to return the property value in a string. The image must be in JPEG format and contain EXIF information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                         |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------- |
| key      | string                                               | Yes  | Name of the property.                                                 |
| options  | [GetImagePropertyOptions](#getimagepropertyoptions7) | Yes  | Image properties, including the image index and default property value.                         |
| callback | AsyncCallback\<string>                               | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
let property : image.GetImagePropertyOptions = { index: 0, defaultValue: '9999' }
imageSourceApi.getImageProperty("BitsPerSample",property,(error : BusinessError, data : string) => { 
    if(error) {
        console.error('Failed to get the value of the specified attribute key of the image.');
    } else {
        console.log('Succeeded in getting the value of the specified attribute key of the image.');
    }
})
```

### modifyImageProperty<sup>9+</sup>

modifyImageProperty(key: string, value: string): Promise\<void>

Modifies the value of a property in this image. This API uses a promise to return the result. The image must be in JPEG format and contain EXIF information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| key     | string | Yes  | Name of the property.|
| value   | string | Yes  | New value of the property.    |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
imageSourceApi.modifyImageProperty("ImageWidth", "120").then(() => {
    imageSourceApi.getImageProperty("ImageWidth").then((width : string) => {
        console.info(`ImageWidth is :${width}`);
    })
})
```

### modifyImageProperty<sup>9+</sup>

modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void

Modifies the value of a property in this image. This API uses an asynchronous callback to return the result. The image must be in JPEG format and contain EXIF information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type               | Mandatory| Description                          |
| -------- | ------------------- | ---- | ------------------------------ |
| key      | string              | Yes  | Name of the property.                  |
| value    | string              | Yes  | New value of the property.                      |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.modifyImageProperty("ImageWidth", "120",(err : BusinessError) => {
    if (err != undefined) {
        console.error('modifyImageProperty Failed');
    } else {
        console.info('modifyImageProperty Succeeded');
    }
})
```

### updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>

Updates incremental data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type       | Mandatory| Description        |
| ---------- | ----------- | ---- | ------------ |
| buf        | ArrayBuffer | Yes  | Incremental data.  |
| isFinished | boolean     | Yes  | Whether the update is complete.|
| value      | number      | Yes  | Offset for data reading.    |
| length     | number      | Yes  | Array length.    |

**Return value**

| Type          | Description                      |
| -------------- | -------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const array : ArrayBuffer = new ArrayBuffer(100);
imageSourceApi.updateData(array, false, 0, 10).then(() => {
    console.info('Succeeded in updating data.');
}).catch((err: BusinessError) => {
    console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
})
```


### updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number, callback: AsyncCallback\<void>): void

Updates incremental data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type               | Mandatory| Description                |
| ---------- | ------------------- | ---- | -------------------- |
| buf        | ArrayBuffer         | Yes  | Incremental data.          |
| isFinished | boolean             | Yes  | Whether the update is complete.        |
| value      | number              | Yes  | Offset for data reading.            |
| length     | number              | Yes  | Array length.            |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const array : ArrayBuffer = new ArrayBuffer(100);
imageSourceApi.updateData(array, false, 0, 10, (err: BusinessError) => {
    if (err != undefined) {
        console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
    } else {
        console.info('Succeeded in updating data.');
    }
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

Creates a **PixelMap** object based on image decoding parameters. This API uses a promise to return the result.

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
import {BusinessError} from '@ohos.base';
imageSourceApi.createPixelMap().then((pixelMap : image.PixelMap) => {
    console.log('Succeeded in creating pixelMap object through image decoding parameters.');
}).catch((error : BusinessError) => {
    console.error('Failed to create pixelMap object through image decoding parameters.');
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on the default parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.createPixelMap((err : BusinessError, pixelMap : image.PixelMap) => {
    console.info('Succeeded in creating pixelMap object.');
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on image decoding parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | Yes  | Image decoding parameters.                |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
let decodingOptions : image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 1, height: 2 },
    rotate: 10,
    desiredPixelFormat: 3,
    desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 },
    index: 0
};
imageSourceApi.createPixelMap(decodingOptions, (err : BusinessError, pixelMap : image.PixelMap) => { 
    console.log('Succeeded in creating pixelMap object.');
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options?: DecodingOptions): Promise<Array\<PixelMap>>

Creates an array of **PixelMap** objects based on image decoding parameters. This API uses a promise to return the result.

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

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980103| If the image data unsupport             |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980118| If the image plugin create failed             |

**Example**

```ts
import {BusinessError} from '@ohos.base';
let decodeOpts: image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 198, height: 202 },
    rotate: 0,
    desiredPixelFormat: 3,
    index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts).then((pixelMapList: Array<image.PixelMap>) => {
    console.log('Succeeded in creating pixelMapList object.');
}).catch((err: BusinessError) => {
    console.error(`Failed to create pixelMapList object.code is ${err.code},message is ${err.message}`);
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of **PixelMap** objects based on the default parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | Yes  | Callback used to return an array of **PixelMap** objects.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980103| If the image data unsupport             |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980118| If the image plugin create failed             |

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.createPixelMapList((err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
    if (err != undefined) {
        console.error(`Failed to create pixelMapList object.code is ${err.code},message is ${err.message}`);
    } else {
        console.info('Succeeded in creating pixelMapList object.');
    }
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options: DecodingOptions, callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of **PixelMap** objects based on image decoding parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| options | [DecodingOptions](#decodingoptions7) | Yes| Image decoding parameters.|
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | Yes  | Callback used to return an array of **PixelMap** objects.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980103| If the image data unsupport             |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980118| If the image plugin create failed             |

**Example**

```ts
import {BusinessError} from '@ohos.base';
let decodeOpts : image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 198, height: 202 },
    rotate: 0,
    desiredPixelFormat: 3,
    index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts, (err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
    if (err != undefined) {
        console.error(`Failed to create pixelMapList object.code is ${err.code},message is ${err.message}`);
    } else {
        console.log('Succeeded in creating pixelMapList object.');
    }
})
```

### getDelayTimeList<sup>10+</sup>

getDelayTimeList(callback: AsyncCallback<Array\<number>>): void

Obtains an array of delay times. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback<Array\<number>> | Yes  | Callback used to return an array of delay times.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.getDelayTimeList((err: BusinessError, delayTimes: Array<number>) => {
    if (err != undefined) {
        console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
    } else {
        console.log('Succeeded in delayTimes object.');
    }
})
```

### getDelayTimeList<sup>10+</sup>

getDelayTimeList(): Promise<Array\<number>>

Obtains an array of delay times. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<Array\<number>> | Promise used to return an array of delay times.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**Example**

```ts
imageSourceApi.getDelayTimeList().then((delayTimes : Array<number>) => {
    console.log('Succeeded in delayTimes object.');
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
| callback | AsyncCallback\<number> | Yes  | Callback used to return the number of frames.|

**Error codes**

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.getFrameCount((err: BusinessError, frameCount: number) => {
    if (err != undefined) {
        console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
    } else {
        console.log('Succeeded in getting frame count.');
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

For details about the error codes, see [Image Error Codes](../errorcodes/errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**Example**

```ts
imageSourceApi.getFrameCount().then((frameCount: number) => {
    console.log('Succeeded in getting frame count.');
}).catch((err : BusinessError) => {
    console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
})
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImageSource** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback invoked for instance release. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.release((err : BusinessError) => { 
    if (err != undefined) {
        console.error('Failed to release the image source instance.');
    } else {
        console.log('Succeeded in releasing the image source instance.');
    }
})
```

### release

release(): Promise\<void>

Releases this **ImageSource** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.release().then(()=>{
    console.log('Succeeded in releasing the image source instance.');
}).catch((error : BusinessError) => {
    console.error('Failed to release the image source instance.');
})
```

## image.createImagePacker

createImagePacker(): ImagePacker

Creates an **ImagePacker** instance.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type                       | Description                 |
| --------------------------- | --------------------- |
| [ImagePacker](#imagepacker) | **ImagePacker** instance created.|

**Example**

```ts
const imagePackerApi : image.ImagePacker = image.createImagePacker();
```

## ImagePacker

Provides APIs to pack images. Before calling any API in **ImagePacker**, you must use **createImagePacker** to create an **ImagePacker** instance. The image formats JPEG, WebP, and PNG are supported.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name            | Type          | Readable| Writable| Description                      |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats, which can be JPEG, WebP, and PNG.|

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                              | Mandatory| Description                              |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)        | Yes  | Image to pack.                    |
| option   | [PackingOption](#packingoption)    | Yes  | Option for image packing.                     |
| callback | AsyncCallback\<ArrayBuffer>        | Yes  | Callback used to return the packed data.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const imageSourceApi : image.ImageSource = image.createImageSource(0);
let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 };
imagePackerApi.packing(imageSourceApi, packOpts, (err : BusinessError, data : ArrayBuffer) => {})
```

### packing

packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>

Packs an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | Yes  | Image to pack.|
| option | [PackingOption](#packingoption) | Yes  | Option for image packing.|

**Return value**

| Type                        | Description                                         |
| ---------------------------- | --------------------------------------------- |
| Promise\<ArrayBuffer>        | Promise used to return the packed data.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const imageSourceApi : image.ImageSource = image.createImageSource(0);
let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 }
imagePackerApi.packing(imageSourceApi, packOpts)
    .then( (data : ArrayBuffer) => {
        console.log('packing succeeded.');
	}).catch((error : BusinessError) => {
	    console.error('packing failed.');
	})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                              |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [PixelMap](#pixelmap)           | Yes  | **PixelMap** object to pack.              |
| option   | [PackingOption](#packingoption) | Yes  | Option for image packing.                    |
| callback | AsyncCallback\<ArrayBuffer>     | Yes  | Callback used to return the packed data.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap : image.PixelMap) => {
    let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 }
    imagePackerApi.packing(pixelMap, packOpts, (err : BusinessError, data : ArrayBuffer) => { 
        console.log('Succeeded in packing the image.');
    })
}).catch((error : BusinessError) => {
	console.error('createPixelMap failed.');
})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>

Packs an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name| Type                           | Mandatory| Description              |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](#pixelmap)           | Yes  | **PixelMap** object to pack.|
| option | [PackingOption](#packingoption) | Yes  | Option for image packing.    |

**Return value**

| Type                 | Description                                        |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the packed data.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap : image.PixelMap) => {
    let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 }
    imagePackerApi.packing(pixelMap, packOpts)
        .then( (data : ArrayBuffer) => {
            console.log('Succeeded in packing the image.');
        }).catch((error : BusinessError) => {
            console.error('Failed to pack the image..');
        })
}).catch((error : BusinessError) => {
	console.error('createPixelMap failed.');
})
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImagePacker** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback invoked for instance release. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imagePackerApi.release((err : BusinessError)=>{ 
    if (err != undefined) {
        console.error('Failed to release image packaging.'); 
    } else {
        console.log('Succeeded in releasing image packaging.');
    }
})
```

### release

release(): Promise\<void>

Releases this **ImagePacker** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type          | Description                                                  |
| -------------- | ------------------------------------------------------ |
| Promise\<void> | Promise used to return the instance release result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
imagePackerApi.release().then(()=>{
    console.log('Succeeded in releasing image packaging.');
}).catch((error : BusinessError)=>{ 
    console.error('Failed to release image packaging.'); 
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
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base'
import fs from '@ohos.file.fs'

const context : Context = getContext(this);
const path : string = context.filesDir + "/test.png";
const imageSourceApi : image.ImageSource = image.createImageSource(path);
let packOpts : image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath : string = context.cacheDir + "/image_source.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const imagePackerApi : image.ImagePacker = image.createImagePacker();
imagePackerApi.packToFile(imageSourceApi, file.fd, packOpts, (err : BusinessError) => {})
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
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base'
import fs from '@ohos.file.fs'

const context : Context = getContext(this);
const path : string = context.filesDir + "/test.png";
const imageSourceApi : image.ImageSource = image.createImageSource(path);
let packOpts : image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath : string = context.cacheDir + "/image_source.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const imagePackerApi : image.ImagePacker = image.createImagePacker();
imagePackerApi.packToFile(imageSourceApi, file.fd, packOpts).then(()=>{
    console.log('Succeeded in packToFile.');
}).catch((error : BusinessError)=>{ 
    console.log('Failed to packToFile.'); 
}) 
```

### packToFile<sup>11+</sup>

packToFile (source: Pixelmap, fd: number, options: PackingOption,  callback: AsyncCallback\<void>): void;

Encodes a **PixelMap** instance and packs it into a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                           | Mandatory| Description                          |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [PixelMap](#pixelmap7)          | Yes  | **PixelMap** object to pack.          |
| fd       | number                          | Yes  | File descriptor.                  |
| options   | [PackingOption](#packingoption) | Yes  | Option for image packing.                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base'
import fs from '@ohos.file.fs'

const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelmap : image.PixelMap) => {
    let packOpts : image.PackingOption = { format: "image/jpeg", quality: 98 }
    const context : Context = getContext(this);
	const path : string = context.cacheDir + "/pixel_map.jpg";
    let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    const imagePackerApi : image.ImagePacker = image.createImagePacker();
    imagePackerApi.packToFile(pixelmap, file.fd, packOpts, (err : BusinessError) => {})
})
```

### packToFile<sup>11+</sup>

packToFile (source: Pixelmap, fd: number, options: PackingOption): Promise\<void>

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
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base'
import fs from '@ohos.file.fs'

const color : ArrayBuffer = new ArrayBuffer(96);  // 96 is the size of the pixel map buffer to create. The value is calculated as follows: height x width x 4.
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelmap : image.PixelMap) => {
    let packOpts : image.PackingOption = { format: "image/jpeg", quality: 98 }
    const context : Context = getContext(this);
    const path : string = context.cacheDir + "/pixel_map.jpg";
    let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    const imagePackerApi : image.ImagePacker = image.createImagePacker();
    imagePackerApi.packToFile(pixelmap, file.fd, packOpts)
        .then(() => {
            console.log('Succeeded in packToFile.');
        }).catch((error : BusinessError) => {
            console.log('Failed to packToFile.');
        })
})
```

## image.createImageReceiver<sup>9+</sup>

createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver

Creates an **ImageReceiver** instance by specifying the image width, height, format, and capacity.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| width    | number | Yes  | Default image width.      |
| height   | number | Yes  | Default image height.      |
| format   | number | Yes  | Image format, which is a constant of [ImageFormat](#imageformat9). (Currently, only **ImageFormat:JPEG** is supported.) |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver9) | Returns an **ImageReceiver** instance if the operation is successful.|

**Example**

```ts
let receiver : image.ImageReceiver = image.createImageReceiver(8192, 8, image.ImageFormat.JPEG, 8);
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
| callback | AsyncCallback\<string> | Yes  | Callback used to return the surface ID.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
receiver.getReceivingSurfaceId((err : BusinessError, id : string) => { 
    if(err) {
        console.error('getReceivingSurfaceId failed.');
    } else {
        console.log('getReceivingSurfaceId succeeded.');
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
import {BusinessError} from '@ohos.base';
receiver.getReceivingSurfaceId().then( (id : string) => { 
    console.log('getReceivingSurfaceId succeeded.');
}).catch((error : BusinessError) => {
    console.error('getReceivingSurfaceId failed.');
})
```

### readLatestImage<sup>9+</sup>

readLatestImage(callback: AsyncCallback\<Image>): void

Reads the latest image from the **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<[Image](#image9)> | Yes  | Callback used to return the latest image.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
receiver.readLatestImage((err : BusinessError, img : image.Image) => { 
    if(err) {
        console.error('readLatestImage failed.');
    } else {
        console.log('readLatestImage succeeded.');
    }
});
```

### readLatestImage<sup>9+</sup>

readLatestImage(): Promise\<Image>

Reads the latest image from the **ImageReceiver** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description              |
| ------------------------- | ------------------ |
| Promise<[Image](#image9)> | Promise used to return the latest image.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
receiver.readLatestImage().then((img : image.Image) => {
    console.log('readLatestImage succeeded.');
}).catch((error : BusinessError) => {
    console.error('readLatestImage failed.');
})
```

### readNextImage<sup>9+</sup>

readNextImage(callback: AsyncCallback\<Image>): void

Reads the next image from the **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                           | Mandatory| Description                      |
| -------- | ------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[Image](#image9)> | Yes  | Callback used to return the next image.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
receiver.readNextImage((err : BusinessError, img : image.Image) => { 
    if(err) {
        console.error('readNextImage failed.');
    } else {
        console.log('readNextImage succeeded.');
    }
});
```

### readNextImage<sup>9+</sup>

readNextImage(): Promise\<Image>

Reads the next image from the **ImageReceiver** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                     | Description                |
| ------------------------- | -------------------- |
| Promise<[Image](#image9)> | Promise used to return the next image.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
receiver.readNextImage().then((img : image.Image) => {
    console.log('readNextImage succeeded.');
}).catch((error : BusinessError) => {
    console.error('readNextImage failed.');
})
```

### on<sup>9+</sup>

on(type: 'imageArrival', callback: AsyncCallback\<void>): void

Listens for image arrival events.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                | Mandatory| Description                                                  |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **imageArrival**, which is triggered when an image is received.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked for the event.                                      |

**Example**

```ts
receiver.on('imageArrival', () => {})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base'
receiver.release((err : BusinessError) => {})
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases this **ImageReceiver** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type          | Description              |
| -------------- | ------------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
receiver.release().then(() => {
    console.log('release succeeded.');
}).catch((error : BusinessError) => {
    console.error('release failed.');
})
```

## image.createImageCreator<sup>9+</sup>

createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator

Creates an **ImageCreator** instance by specifying the image width, height, format, and capacity.

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
let creator : image.ImageCreator = image.createImageCreator(8192, 8, image.ImageFormat.JPEG, 8);
```

## ImageCreator<sup>9+</sup>

Provides APIs for applications to request an image native data area and compile native image data.
Before calling any APIs in **ImageCreator**, you must create an **ImageCreator** instance. **ImageCreator** does not support multiple threads.

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
| callback      | AsyncCallback\<Image>                   | Yes  | Callback used to return the drawn image.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
creator.dequeueImage((err : BusinessError, img : image.Image) => {
    if (err) {
        console.error('dequeueImage failed.');
    } else {
        console.info('dequeueImage succeeded.');
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
| Promise\<Image> | Promise used to return the drawn image.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
creator.dequeueImage().then((img : image.Image) => {
    console.info('dequeueImage succeeded.');
}).catch((error : BusinessError) => {
    console.error('dequeueImage failed: ' + error);
})
```

### queueImage<sup>9+</sup>

queueImage(interface: Image, callback: AsyncCallback\<void>): void

Places the drawn image in the dirty queue. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name       | Type                    | Mandatory| Description                |
| ------------- | -------------------------| ---- | -------------------- |
| interface     | Image                    | Yes  | Drawn image.|
| callback      | AsyncCallback\<void>     | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
creator.dequeueImage().then((img : image.Image) => {
    // Draw the image.
    img.getComponent(4).then( (component : image.Component) => {
        let bufferArr : Uint8Array = new Uint8Array(component.byteBuffer);
        for (let i = 0; i < bufferArr.length; i += 4) {
            bufferArr[i] = 0; //B
            bufferArr[i + 1] = 0; //G
            bufferArr[i + 2] = 255; //R
            bufferArr[i + 3] = 255; //A
        }
    })
    creator.queueImage(img, (err : BusinessError) => {
        if (err) {
            console.error('queueImage failed: ' + err);
        } else {
            console.info('queueImage succeeded');
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
| interface     | Image   | Yes  | Drawn image.|

**Return value**

| Type           | Description          |
| -------------- | ------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
creator.dequeueImage().then((img : image.Image) => {
    // Draw the image.
    img.getComponent(4).then((component : image.Component) => {
        let bufferArr : Uint8Array = new Uint8Array(component.byteBuffer);
        for (let i = 0; i < bufferArr.length; i += 4) {
            bufferArr[i] = 0; //B
            bufferArr[i + 1] = 0; //G
            bufferArr[i + 2] = 255; //R
            bufferArr[i + 3] = 255; //A
        }
    })
    creator.queueImage(img).then(() => {
        console.info('queueImage succeeded.');
    }).catch((error : BusinessError) => {
        console.error('queueImage failed: ' + error);
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
| callback      | AsyncCallback\<void>     | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
creator.on('imageRelease', (err : BusinessError) => {
    if (err) {
        console.error('on faild' + err);
    } else {
        console.info('on succeeded');
    }
})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **ImageCreator** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Parameters**

| Name          | Type                    | Mandatory| Description                |
| ------------- | -------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<void>     | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
creator.release((err : BusinessError) => {
    if (err) {
        console.error('release failed: ' + err);
    } else {
        console.info('release succeeded');
    }
});
```
### release<sup>9+</sup>

release(): Promise\<void>

Releases this **ImageCreator** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageCreator

**Return value**

| Type           | Description          |
| -------------- | ------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
creator.release().then(() => {
    console.info('release succeeded');
}).catch((error : BusinessError) => {
    console.error('release failed');
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
| format   | number             | Yes  | No  | Image format. For details, see [PixelMapFormat](#pixelmapformat7).|

### getComponent<sup>9+</sup>

getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void

Obtains the component buffer from the **Image** instance based on the color component type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                                   | Mandatory| Description                |
| ------------- | --------------------------------------- | ---- | -------------------- |
| componentType | [ComponentType](#componenttype9)        | Yes  | Color component type of the image.    |
| callback      | AsyncCallback<[Component](#component9)> | Yes  | Callback used to return the component buffer.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
img.getComponent(4, (err : BusinessError, component : image.Component) => {
    if(err) {
        console.error('getComponent failed.');
    } else {
        console.log('getComponent succeeded.');
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
| componentType | [ComponentType](#componenttype9) | Yes  | Color component type of the image.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise<[Component](#component9)> | Promise used to return the component buffer.|

**Example**

```ts
img.getComponent(4).then((component : image.Component) => { })
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **Image** instance. This API uses an asynchronous callback to return the result.

The corresponding resources must be released before another image arrives.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description          |
| -------- | -------------------- | ---- | -------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
img.release((err : BusinessError) =>{ 
    if (err != undefined) {
        console.error('Failed to release the image source instance.');
    } else {
        console.log('Succeeded in releasing the image source instance.');
    }
}) 
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases this **Image** instance. This API uses a promise to return the result.

The corresponding resources must be released before another image arrives.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
img.release().then(() =>{
    console.log('release succeeded.');
}).catch((error : BusinessError) => {
    console.error('release failed.');
})
```

## PositionArea<sup>7+</sup>

Describes area information in an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type              | Readable| Writable| Description                                                        |
| ------ | ------------------ | ---- | ---- | ------------------------------------------------------------ |
| pixels | ArrayBuffer        | Yes  | No  | Pixels of the image.                                                      |
| offset | number             | Yes  | No  | Offset for data reading.                                                    |
| stride | number             | Yes  | No  | Number of bytes from one row of pixels in memory to the next row of pixels in memory. The value of **stride** must be greater than or equal to the value of **region.size.width** multiplied by 4.                  |
| region | [Region](#region7) | Yes  | No  | Region to read or write. The width of the region to write plus the X coordinate cannot be greater than the width of the original image. The height of the region to write plus the Y coordinate cannot be greater than the height of the original image.|

## ImageInfo

Describes image information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Readable| Writable| Description      |
| ---- | ------------- | ---- | ---- | ---------- |
| size | [Size](#size) | Yes  | Yes  | Image size.|
| density<sup>9+</sup> | number | Yes  | Yes  | Pixel density, in ppi.|

## Size

Describes the size of an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type  | Readable| Writable| Description          |
| ------ | ------ | ---- | ---- | -------------- |
| height | number | Yes  | Yes  | Image height.|
| width  | number | Yes  | Yes  | Image width.|

## PixelMapFormat<sup>7+</sup>

Enumerates the pixel formats of images.

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

**System capability**: SystemCapability.Multimedia.Image.Core

| Name    |   Value  | Description                   |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | Unknown alpha type.           |
| OPAQUE   | 1      | There is no alpha or the image is opaque.|
| PREMUL   | 2      | Premultiplied alpha.        |
| UNPREMUL | 3      | Unpremultiplied alpha, that is, straight alpha.      |

## ScaleMode<sup>9+</sup>

Enumerates the scale modes of images.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name           |   Value  | Description                                              |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | Scales the image so that it fills the requested bounds of the target and crops the extra.|
| FIT_TARGET_SIZE | 0      | Reduces the image size to the dimensions of the target.                          |

## SourceOptions<sup>9+</sup>

Defines image source initialization options.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Type                              | Readable| Writable| Description              |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| sourceDensity     | number                             | Yes  | Yes  | Density of the image source.|
| sourcePixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel format of the image source.    |
| sourceSize        | [Size](#size)                      | Yes  | Yes  | Pixel size of the image source.    |


## InitializationOptions<sup>8+</sup>

Defines pixel map initialization options.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                    | Type                              | Readable| Writable| Description          |
| ------------------------ | ---------------------------------- | ---- | ---- | -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](#alphatype9)           | Yes  | Yes  | Alpha type.      |
| editable                 | boolean                            | Yes  | Yes  | Whether the image is editable.  |
| pixelFormat              | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format.    |
| scaleMode<sup>9+</sup>   | [ScaleMode](#scalemode9)           | Yes  | Yes  | Scale mode.      |
| size                     | [Size](#size)                      | Yes  | Yes  | Image size.|

## DecodingOptions<sup>7+</sup>

Defines image decoding options.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name              | Type                              | Readable| Writable| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | Yes  | Yes  | Thumbnail sampling size. Currently, this option can only be set to **1**.|
| rotate             | number                             | Yes  | Yes  | Rotation angle.      |
| editable           | boolean                            | Yes  | Yes  | Whether the image is editable. If this option is set to **false**, the image cannot be edited again, and operations such as cropping will fail. |
| desiredSize        | [Size](#size)                      | Yes  | Yes  | Expected output size.  |
| desiredRegion      | [Region](#region7)                 | Yes  | Yes  | Region to decode.      |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format for decoding.|
| index              | number                             | Yes  | Yes  | Index of the image to decode.  |
| fitDensity<sup>9+</sup> | number                        | Yes  | Yes  | Image pixel density, in ppi.  |

## Region<sup>7+</sup>

Describes region information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Readable| Writable| Description        |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | Yes  | Yes  | Region size.  |
| x    | number        | Yes  | Yes  | X coordinate to translate.|
| y    | number        | Yes  | Yes  | Y coordinate of the region.|

## PackingOption

Defines the option for image packing.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name   | Type  | Readable| Writable| Description                                               |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | Yes  | Yes  | Format of the packed image.<br>Currently, only JPG, WebP, and PNG are supported.|
| quality | number | Yes  | Yes  | Quality of the output image in JPEG encoding. The value ranges from 1 to 100.|
| bufferSize<sup>9+</sup> | number | Yes  | Yes  | Size of the buffer for receiving the encoded data, in bytes. The default value is 10 MB. The value of **bufferSize** must be greater than the size of the encoded image.|

## GetImagePropertyOptions<sup>7+</sup>

Describes image properties.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name        | Type  | Readable| Writable| Description        |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | Yes  | Yes  | Index of an image.  |
| defaultValue | string | Yes  | Yes  | Default property value.|

## PropertyKey<sup>7+</sup>

Describes the exchangeable image file format (EXIF) data of an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             |   Value                   | Description                    |
| ----------------- | ----------------------- | ------------------------ |
| BITS_PER_SAMPLE                           | "BitsPerSample"              | Number of bits per pixel.                           |
| ORIENTATION                               | "Orientation"                | Image orientation.                                 |
| IMAGE_LENGTH                              | "ImageLength"                | Image length.                                 |
| IMAGE_WIDTH                               | "ImageWidth"                 | Image width.                                 |
| GPS_LATITUDE                              | "GPSLatitude"                | Image latitude.                                 |
| GPS_LONGITUDE                             | "GPSLongitude"               | Image longitude.                                 |
| GPS_LATITUDE_REF                          | "GPSLatitudeRef"             | Latitude reference, for example, N or S.                       |
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"            | Longitude reference, for example, W or E.                       |
| DATE_TIME_ORIGINAL<sup>9+</sup>           | "DateTimeOriginal"           | Shooting time, for example, 2022:09:06 15:48:00.        |
| EXPOSURE_TIME<sup>9+</sup>                | "ExposureTime"               | Exposure time, for example, 1/33 sec.                   |
| SCENE_TYPE<sup>9+</sup>                   | "SceneType"                  | Shooting scene type, for example, portrait, scenery, motion, and night.|
| ISO_SPEED_RATINGS<sup>9+</sup>            | "ISOSpeedRatings"            | ISO sensitivity or ISO speed, for example, 400.                       |
| F_NUMBER<sup>9+</sup>                     | "FNumber"                    | Aperture, for example, f/1.8.                        |
| DATE_TIME<sup>10+</sup>                   | "DateTime"                   | Date and time.                                 |
| GPS_TIME_STAMP<sup>10+</sup>              | "GPSTimeStamp"               | GPS timestamp.                                  |
| GPS_DATE_STAMP<sup>10+</sup>              | "GPSDateStamp"               | GPS date stamp.                                  |
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"           | Image description.                               |
| MAKE<sup>10+</sup>                        | "Make"                       | Manufacturer.                                     |
| MODEL<sup>10+</sup>                       | "Model"                      | Device model.                                   |
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode "                 | Photographing mode.                                   |
| SENSITIVITY_TYPE<sup>10+</sup>            | "SensitivityType"            | Sensitivity type.                                 |
| STANDARD_OUTPUT_SENSITIVITY<sup>10+</sup> | "StandardOutputSensitivity"  | Standard output sensitivity.                             |
| RECOMMENDED_EXPOSURE_INDEX<sup>10+</sup>  | "RecommendedExposureIndex"   | Recommended exposure index.                               |
| ISO_SPEED<sup>10+</sup>                   | "ISOSpeedRatings"            | ISO speed.                                |
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"              | Aperture value.                                     |
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"          | Exposure bias value.                                 |
| METERING_MODE<sup>10+</sup>               | "MeteringMode"               | Metering mode.                                   |
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"                | Light source.                                       |
| FLASH <sup>10+</sup>                      | "Flash"                      | Flash status.                      |
| FOCAL_LENGTH <sup>10+</sup>               | "FocalLength"                | Focal length.                                       |
| USER_COMMENT <sup>10+</sup>               | "UserComment"                | User comment.                                   |
| PIXEL_X_DIMENSION <sup>10+</sup>          | "PixelXDimension"            | Pixel X dimension.                                  |
| PIXEL_Y_DIMENSION<sup>10+</sup>           | "PixelYDimension"            | Pixel Y dimension.                                  |
| WHITE_BALANCE <sup>10+</sup>              | "WhiteBalance"               | White balance.                                     |
| FOCAL_LENGTH_IN_35_MM_FILM <sup>10+</sup> | "FocalLengthIn35mmFilm"      | Focal length in 35mm film.                             |
| CAPTURE_MODE <sup>10+</sup>               | "HwMnoteCaptureMode"         | Capture mode. Currently, this attribute is read-only.                 |
| PHYSICAL_APERTURE <sup>10+</sup>          | "HwMnotePhysicalAperture"    | Physical aperture. Currently, this attribute is read-only.       |
| ROLL_ANGLE <sup>11+</sup>                 | "HwMnoteRollAngle"           | Rolling angle. Currently, this attribute is read-only.                 |
| PITCH_ANGLE<sup>11+</sup>                | "HwMnotePitchAngle"          | Pitch angle. Currently, this attribute is read-only.                 |
| SCENE_FOOD_CONF<sup>11+</sup>             | "HwMnoteSceneFoodConf"       | Photographing scene: food. Currently, this attribute is read-only.           |
| SCENE_STAGE_CONF<sup>11+</sup>           | "HwMnoteSceneStageConf"     | Photographing scene: stage. Currently, this attribute is read-only.           |
| SCENE_BLUE_SKY_CONF<sup>11+</sup>       | "HwMnoteSceneBlueSkyConf"    | Photographing scene: blue sky. Currently, this attribute is read-only.           |
| SCENE_GREEN_PLANT_CONF<sup>11+</sup>      | "HwMnoteSceneGreenPlantConf" | Photographing scene: green plants. Currently, this attribute is read-only.      |
| SCENE_BEACH_CONF<sup>11+</sup>            | "HwMnoteSceneBeachConf"      | Photographing scene: beach. Currently, this attribute is read-only.           |
| SCENE_SNOW_CONF<sup>11+</sup>             | "HwMnoteSceneSnowConf"       | Photographing scene: snow. Currently, the attribute is read-only.           |
| SCENE_SUNSET_CONF<sup>11+</sup>           | "HwMnoteSceneSunsetConf"     | Photographing scene: sunset. Currently, this attribute is read-only.           |
| SCENE_FLOWERS_CONF<sup>11+</sup>          | "HwMnoteSceneFlowersConf"    | Photographing scene: flowers. Currently, this attribute is read-only.             |
| SCENE_NIGHT_CONF<sup>11+</sup>            | "HwMnoteSceneNightConf"      | Photographing scene: night. Currently, this attribute is read-only.           |
| SCENE_TEXT_CONF<sup>11+</sup>             | "HwMnoteSceneTextConf"       | Photographing scene: text. Currently, this attribute is read-only.           |
| FACE_COUNT<sup>11+</sup>                  | "HwMnoteFaceCount"           | Number of faces. Currently, this attribute is read-only.                 |
| FOCUS_MODE<sup>11+</sup>                  | "HwMnoteFocusMode"           | Focus mode. Currently, this attribute is read-only.                 |

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

| Name         | Type                            | Readable| Writable| Description        |
| ------------- | -------------------------------- | ---- | ---- | ------------ |
| componentType | [ComponentType](#componenttype9) | Yes  | No  | Color component type.  |
| rowStride     | number                           | Yes  | No  | Row stride.      |
| pixelStride   | number                           | Yes  | No  | Pixel stride.  |
| byteBuffer    | ArrayBuffer                      | Yes  | No  | Component buffer.|

## Supplementary Information
### SVG Tags

The SVG tags are supported since API version 10. The used version is (SVG) 1.1. Currently, the following tags are supported:
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
