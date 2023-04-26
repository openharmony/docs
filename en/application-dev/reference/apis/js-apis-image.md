# Image Processing

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import image from '@ohos.multimedia.image';
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>

Creates a **PixelMap** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name   | Type                                            | Mandatory| Description                                                        |
| ------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| colors  | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format.                                   |
| options | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**

| Type                            | Description          |
| -------------------------------- | -------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Example**

```js
const color = new ArrayBuffer(96);
let bufferArr = new Uint8Array(color);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then((pixelmap) => {
        })
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format. |
| options  | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties.                    |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```js
const color = new ArrayBuffer(96);
let bufferArr = new Uint8Array(color);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (pixelmap) => {
        })
```

## PixelMap<sup>7+</sup>

Provides APIs to read or write image pixel map data and obtain image pixel map information. Before calling any API in **PixelMap**, you must use **createPixelMap** to create a **PixelMap** object. Currently, the maximum size of a serialized pixel map is 128 MB. A larger size will cause a display failure. The size is calculated as follows: Width * Height * Number of bytes occupied by each pixel.

 ### Attributes

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                   | Type   | Readable| Writable| Description                      |
| ----------------------- | ------- | ---- | ---- | -------------------------- |
| isEditable<sup>7+</sup> | boolean | Yes  | No  | Whether the image pixel map is editable.|

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

Reads image pixel map data and writes the data to an **ArrayBuffer**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| dst    | ArrayBuffer | Yes  | Buffer to which the image pixel map data will be written.|

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```js
const readBuffer = new ArrayBuffer(400);
pixelmap.readPixelsToBuffer(readBuffer).then(() => {
    console.log('Succeeded in reading image pixel data.'); // Called if the condition is met.
}).catch(error => {
    console.log('Failed to read image pixel data.');  // Called if no condition is met.
})
```

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads image pixel map data and writes the data to an **ArrayBuffer**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| dst      | ArrayBuffer          | Yes  | Buffer to which the image pixel map data will be written.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.                              |

**Example**

```js
const readBuffer = new ArrayBuffer(400);
pixelmap.readPixelsToBuffer(readBuffer, (err, res) => {
    if(err) {
        console.log('Failed to read image pixel data.');  // Called if no condition is met.
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

```js
const area = new ArrayBuffer(400);
pixelmap.readPixels(area).then(() => {
    console.log('Succeeded in reading the image data in the area.'); // Called if the condition is met.
}).catch(error => {
    console.log('Failed to read the image data in the area.'); // Called if no condition is met.
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

```js
const color = new ArrayBuffer(96);
let bufferArr = new Uint8Array(color);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (err, pixelmap) => {
    if(pixelmap == undefined){
        console.info('createPixelMap failed.');
    } else {
        const area = { pixels: new ArrayBuffer(8),
            offset: 0,
            stride: 8,
            region: { size: { height: 1, width: 2 }, x: 0, y: 0 }};
        pixelmap.readPixels(area, () => {
            console.info('readPixels success');
        })
    }
})
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea): Promise\<void>

Writes image pixel map data to an area. This API uses a promise to return the result.

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

```js
const color = new ArrayBuffer(96);
let bufferArr = new Uint8Array(color);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then( pixelmap => {
        if (pixelmap == undefined) {
            console.info('createPixelMap failed.');
        }
        const area = { pixels: new ArrayBuffer(8),
            offset: 0,
            stride: 8,
            region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
        }
        let bufferArr = new Uint8Array(area.pixels);
        for (var i = 0; i < bufferArr.length; i++) {
            bufferArr[i] = i + 1;
        }

        pixelmap.writePixels(area).then(() => {
            const readArea = { pixels: new ArrayBuffer(8),
                offset: 0,
                stride: 8,
                // region.size.width + x < opts.width, region.size.height + y < opts.height
                region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
            }        
        })
    }).catch(error => {
        console.log('error: ' + error);
    })
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

Writes image pixel map data to an area. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name   | Type                          | Mandatory| Description                          |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](#positionarea7) | Yes  | Area to which the image pixel map data will be written.          |
| callback | AsyncCallback\<void>           | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Example**

```js
const area = new ArrayBuffer(400);
pixelmap.writePixels(area, (error) => {
    if (error!=undefined) {
		console.info('Failed to write pixelmap into the specified area.');
	} else {
	    const readArea = {
            pixels: new ArrayBuffer(20),
            offset: 0,
            stride: 8,
            region: { size: { height: 1, width: 2 }, x: 0, y: 0 },
        }
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

```js
const color = new ArrayBuffer(96);
const pixelMap = new ArrayBuffer(400);
let bufferArr = new Uint8Array(color);
pixelMap.writeBufferToPixels(color).then(() => {
    console.log("Succeeded in writing data from a buffer to a PixelMap.");
}).catch((err) => {
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

```js
const color = new ArrayBuffer(96);\
const pixelMap = new ArrayBuffer(400);
let bufferArr = new Uint8Array(color);
pixelMap.writeBufferToPixels(color, function(err) {
    if (err) {
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

```js
const pixelMap = new ArrayBuffer(400);
pixelMap.getImageInfo().then(function(info) {
    console.log("Succeeded in obtaining the image pixel map information.");
}).catch((err) => {
    console.error("Failed to obtain the image pixel map information.");
});
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

```js
pixelmap.getImageInfo((imageInfo) => { 
    console.log("Succeeded in obtaining the image pixel map information.");
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

```js
const color = new ArrayBuffer(96);
let bufferArr = new Uint8Array(color);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (err,pixelmap) => {
    let rowCount = pixelmap.getBytesNumberPerRow();
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

```js
let pixelBytesNumber = pixelmap.getPixelBytesNumber();
```

### release<sup>7+</sup>

release():Promise\<void>

Releases this **PixelMap** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description              |
| -------------- | ------------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
const color = new ArrayBuffer(96);
let bufferArr = new Uint8Array(color);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (pixelmap) => {
    pixelmap.release().then(() => {
	    console.log('Succeeded in releasing pixelmap object.');
    }).catch(error => {
	    console.log('Failed to release pixelmap object.');
    })
})
```

### release<sup>7+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
const color = new ArrayBuffer(96);
let bufferArr = new Uint8Array(color);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (pixelmap) => {
    pixelmap.release().then(() => {
	    console.log('Succeeded in releasing pixelmap object.');
    }).catch(error => {
	    console.log('Failed to release pixelmap object.');
    })
})
```

## image.createImageSource

createImageSource(uri: string): ImageSource

Creates an **ImageSource** instance based on the URI.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | Yes  | Image path. Currently, only the application sandbox path is supported.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```js
let path = this.context.getApplicationContext().fileDirs + "test.jpg";
const imageSourceApi = image.createImageSource(path);
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

```js
const imageSourceApi = image.createImageSource(0)
```

## ImageSource

Provides APIs to obtain image information. Before calling any API in **ImageSource**, you must use **createImageSource** to create an **ImageSource** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name            | Type          | Readable| Writable| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats, including png, jpeg, wbmp, bmp, gif, webp, and heif.|

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

```js
imageSourceApi.getImageInfo(0,(error, imageInfo) => { 
    if(error) {
        console.log('getImageInfo failed.');
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

| Name    | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the image information.|

**Example**

```js
imageSourceApi.getImageInfo(imageInfo => { 
    console.log('Succeeded in obtaining the image information.');
})
```

### getImageInfo

getImageInfo(index?: number): Promise\<ImageInfo>

Obtains information about an image with the specified index. This API uses a promise to return the image information.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description                                 |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | No  | Index of the image. If this parameter is not set, the default value **0** is used.|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](#imageinfo)> | Promise used to return the image information.|

**Example**

```js
imageSourceApi.getImageInfo(0)
    .then(imageInfo => {
		console.log('Succeeded in obtaining the image information.');
	}).catch(error => {
		console.log('Failed to obtain the image information.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

 **Parameters**

| Name   | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                               | Yes  | Name of the property.                        |
| options | [GetImagePropertyOptions](#getimagepropertyoptions7) | No  | Image properties, including the image index and default property value.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<string> | Promise used to return the property value. If the operation fails, the default value is returned.|

**Example**

```js
imageSourceApi.getImageProperty("BitsPerSample")
    .then(data => {
		console.log('Succeeded in getting the value of the specified attribute key of the image.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

Obtains the value of a property with the specified index in this image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

 **Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | Yes  | Name of the property.                                                |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```js
imageSourceApi.getImageProperty("BitsPerSample",(error,data) => { 
    if(error) {
        console.log('Failed to get the value of the specified attribute key of the image.');
    } else {
        console.log('Succeeded in getting the value of the specified attribute key of the image.');
    }
})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

Obtains the value of a property in this image. This API uses an asynchronous callback to return the property value in a string.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                                               | Yes  | Name of the property.                                                |
| options  | [GetImagePropertyOptions](#getimagepropertyoptions7) | Yes  | Image properties, including the image index and default property value.                        |
| callback | AsyncCallback\<string>                               | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```js
const property = new ArrayBuffer(400);
imageSourceApi.getImageProperty("BitsPerSample",property,(error,data) => { 
    if(error) {
        console.log('Failed to get the value of the specified attribute key of the image.');
    } else {
        console.log('Succeeded in getting the value of the specified attribute key of the image.');
    }
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

Creates a **PixelMap** object based on image decoding parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name   | Type                                | Mandatory| Description      |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [DecodingOptions](#decodingoptions7) | No  | Image decoding parameters.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Example**

```js
imageSourceApi.createPixelMap().then(pixelmap => {
    console.log('Succeeded in creating pixelmap object through image decoding parameters.');
}).catch(error => {
    console.log('Failed to create pixelmap object through image decoding parameters.');
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

```js
imageSourceApi.createPixelMap(pixelmap => { 
    console.log('Succeeded in creating pixelmap object.');
}).catch(error => {
    console.log('Failed to create pixelmap object.');
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on image decoding parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | Yes  | Image decoding parameters.                |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```js
const decodingOptions = new ArrayBuffer(400);
imageSourceApi.createPixelMap(decodingOptions, pixelmap => { 
    console.log('Succeeded in creating pixelmap object.');
})
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImageSource** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback invoked for instance release. If the operation fails, an error message is returned.|

**Example**

```js
imageSourceApi.release(() => { 
    console.log('release succeeded.');
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

```js
imageSourceApi.release().then(()=>{
    console.log('Succeeded in releasing the image source instance.');
}).catch(error => {
    console.log('Failed to release the image source instance.');
})
```

## image.createImagePacker

createImagePacker(): ImagePacker

Creates an **ImagePacker** instance.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Return value**

| Type                       | Description                 |
| --------------------------- | --------------------- |
| [ImagePacker](#imagepacker) | **ImagePacker** instance created.|

**Example**

```js
const imagePackerApi = image.createImagePacker();
```

## ImagePacker

Provide APIs to pack images. Before calling any API in **ImagePacker**, you must use **createImagePacker** to create an **ImagePacker** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name            | Type          | Readable| Writable| Description                      |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | Yes  | No  | Supported image format, which can be jpeg.|

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Parameters**

| Name  | Type                              | Mandatory| Description                              |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)        | Yes  | Image to pack.                    |
| option   | [PackingOption](#packingoption)    | Yes  | Option for image packing.                    |
| callback | AsyncCallback\<ArrayBuffer>        | Yes  | Callback used to return the packed data.|

**Example**

```js
let packOpts = { format:"image/jpeg", quality:98 };
const imageSourceApi = new ArrayBuffer(400);
imagePackerApi.packing(imageSourceApi, packOpts, data => {})
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
| :--------------------------- | :-------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the packed data.|

**Example**

```js
let packOpts = { format:"image/jpeg", quality:98 }
const imageSourceApi = new ArrayBuffer(400);
imagePackerApi.packing(imageSourceApi, packOpts)
    .then( data => {
        console.log('packing succeeded.');
	}).catch(error => {
	    console.log('packing failed.');
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

```js
let packOpts = { format:"image/jpeg", quality:98 }
const pixelMapApi = new ArrayBuffer(400);
imagePackerApi.packing(pixelMapApi, packOpts, data => { 
    console.log('Succeeded in packing the image.');
}).catch(error => {
	console.log('Failed to pack the image.');
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

| Type                        | Description                                         |
| :--------------------------- | :-------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the packed data.|

**Example**

```js
let packOpts = { format:"image/jpeg", quality:98 }
const pixelMapApi = new ArrayBuffer(400);
imagePackerApi.packing(pixelMapApi, packOpts)
    .then( data => {
	    console.log('Succeeded in packing the image.');
	}).catch(error => {
	    console.log('Failed to pack the image.');
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

```js
imagePackerApi.release(()=>{ 
    console.log('Succeeded in releasing image packaging.');
})
```

### release

release(): Promise\<void>

Releases this **ImagePacker** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

**Return value**

| Type          | Description                                                   |
| :------------- | :------------------------------------------------------ |
| Promise\<void> | Promise used to return the instance release result. If the operation fails, an error message is returned.|

**Example**

```js
imagePackerApi.release().then(()=>{
    console.log('Succeeded in releasing image packaging.');
}).catch((error)=>{ 
    console.log('Failed to release image packaging.'); 
}) 
```


## PositionArea<sup>7+</sup>

Describes area information in an image.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name  | Type              | Readable| Writable| Description                                                        |
| ------ | ------------------ | ---- | ---- | ------------------------------------------------------------ |
| pixels | ArrayBuffer        | Yes  | No  | Pixels of the image.                                                      |
| offset | number             | Yes  | No  | Offset for data reading.                                                    |
| stride | number             | Yes  | No  | Number of bytes from one row of pixels in memory to the next row of pixels in memory. The value of **stride** must be greater than or equal to the value of **region.size.width** multiplied by 4.                   |
| region | [Region](#region7) | Yes  | No  | Region to read or write. The width of the region to write plus the X coordinate cannot be greater than the width of the original image. The height of the region to write plus the Y coordinate cannot be greater than the height of the original image.|

## ImageInfo

Describes image information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Readable| Writable| Description      |
| ---- | ------------- | ---- | ---- | ---------- |
| size | [Size](#size) | Yes  | Yes  | Image size.|

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

| Name     | Default Value| Description             |
| --------- | ------ | ----------------- |
| UNKNOWN   | 0      | Unknown format.       |
| RGBA_8888 | 3      | RGBA_8888.|
| RGB_565   | 2      | RGB_565.  |



## InitializationOptions<sup>8+</sup>

Defines pixel map initialization options.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                  | Type                              | Readable| Writable| Description          |
| ---------------------- | ---------------------------------- | ---- | ---- | -------------- |
| editable               | boolean                            | Yes  | Yes  | Whether the image is editable.  |
| pixelFormat            | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format.    |
| size                   | [Size](#size)                      | Yes  | Yes  | Image size.|

## DecodingOptions<sup>7+</sup>

Defines image decoding options.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name              | Type                              | Readable| Writable| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | Yes  | Yes  | Thumbnail sampling size.|
| rotate             | number                             | Yes  | Yes  | Rotation angle.      |
| editable           | boolean                            | Yes  | Yes  | Whether the image is editable.    |
| desiredSize        | [Size](#size)                      | Yes  | Yes  | Expected output size.  |
| desiredRegion      | [Region](#region7)                 | Yes  | Yes  | Region to decode.      |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format for decoding.|
| index              | number                             | Yes  | Yes  | Index of the image to decode.  |

## Region<sup>7+</sup>

Describes region information.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name| Type         | Readable| Writable| Description        |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | Yes  | Yes  | Region size.  |
| x    | number        | Yes  | Yes  | X coordinate of the region.|
| y    | number        | Yes  | Yes  | Y coordinate of the region.|

## PackingOption

Defines the option for image packing.

**System capability**: SystemCapability.Multimedia.Image.ImagePacker

| Name   | Type  | Readable| Writable| Description          |
| ------- | ------ | ---- | ---- | -------------- |
| format  | string | Yes  | Yes  | Format of the packed image.    |
| quality | number | Yes  | Yes  | Quality of the output image during JPEG encoding. The value ranges from 1 to 100.|

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

| Name             | Default Value           | Description               |
| ----------------- | ----------------- | ------------------- |
| BITS_PER_SAMPLE   | "BitsPerSample"   | Number of bits per pixel.   |
| ORIENTATION       | "Orientation"     | Image orientation.         |
| IMAGE_LENGTH      | "ImageLength"     | Image length.         |
| IMAGE_WIDTH       | "ImageWidth"      | Image width.         |
| GPS_LATITUDE      | "GPSLatitude"     | Image latitude.         |
| GPS_LONGITUDE     | "GPSLongitude"    | Image longitude.         |
| GPS_LATITUDE_REF  | "GPSLatitudeRef"  | Latitude reference, for example, N or S.|
| GPS_LONGITUDE_REF | "GPSLongitudeRef" | Longitude reference, for example, W or E.|


## ResponseCode

Enumerates the response codes returned upon build errors.


| Name                               | Value      | Description                                               |
| ----------------------------------- | -------- | --------------------------------------------------- |
| ERR_MEDIA_INVALID_VALUE             | -1       | Invalid value.                                         |
| SUCCESS                             | 0        | Operation successful.                                         |
| ERROR                               | 62980096 | Operation failed.                                         |
| ERR_IPC                             | 62980097 | IPC error.                                          |
| ERR_SHAMEM_NOT_EXIST                | 62980098 | The shared memory does not exist.                                     |
| ERR_SHAMEM_DATA_ABNORMAL            | 62980099 | The shared memory is abnormal.                                     |
| ERR_IMAGE_DECODE_ABNORMAL           | 62980100 | An error occurs during image decoding.                                     |
| ERR_IMAGE_DATA_ABNORMAL             | 62980101 | The input image data is incorrect.                                 |
| ERR_IMAGE_MALLOC_ABNORMAL           | 62980102 | An error occurs during image memory allocation.                                   |
| ERR_IMAGE_DATA_UNSUPPORT            | 62980103 | Unsupported image type.                                   |
| ERR_IMAGE_INIT_ABNORMAL             | 62980104 | An error occurs during image initialization.                                   |
| ERR_IMAGE_GET_DATA_ABNORMAL         | 62980105 | An error occurs during image data retrieval.                                 |
| ERR_IMAGE_TOO_LARGE                 | 62980106 | The image data is too large.                                     |
| ERR_IMAGE_TRANSFORM                 | 62980107 | An error occurs during image transformation.                                     |
| ERR_IMAGE_COLOR_CONVERT             | 62980108 | An error occurs during image color conversion.                                 |
| ERR_IMAGE_CROP                      | 62980109 | An error occurs during image cropping.                                         |
| ERR_IMAGE_SOURCE_DATA               | 62980110 | The image source data is incorrect.                                   |
| ERR_IMAGE_SOURCE_DATA_INCOMPLETE    | 62980111 | The image source data is incomplete.                                 |
| ERR_IMAGE_MISMATCHED_FORMAT         | 62980112 | The image formats do not match.                                   |
| ERR_IMAGE_UNKNOWN_FORMAT            | 62980113 | Unknown image format.                                     |
| ERR_IMAGE_SOURCE_UNRESOLVED         | 62980114 | The image source is not parsed.                                     |
| ERR_IMAGE_INVALID_PARAMETER         | 62980115 | Invalid image parameter.                                     |
| ERR_IMAGE_DECODE_FAILED             | 62980116 | Decoding failed.                                         |
| ERR_IMAGE_PLUGIN_REGISTER_FAILED    | 62980117 | Failed to register the plug-in.                                     |
| ERR_IMAGE_PLUGIN_CREATE_FAILED      | 62980118 | Failed to create the plug-in.                                     |
| ERR_IMAGE_ENCODE_FAILED             | 62980119 | Failed to encode the image.                                     |
| ERR_IMAGE_ADD_PIXEL_MAP_FAILED      | 62980120 | Failed to add the image pixel map.                             |
| ERR_IMAGE_HW_DECODE_UNSUPPORT       | 62980121 | Unsupported image hardware decoding.                               |
| ERR_IMAGE_DECODE_HEAD_ABNORMAL      | 62980122 | The image decoding header is incorrect.                                   |
| ERR_IMAGE_DECODE_EXIF_UNSUPPORT     | 62980123 | EXIF decoding is not supported.                             |
| ERR_IMAGE_PROPERTY_NOT_EXIST        | 62980124 | The image property does not exist. The error codes for the image start from 150.|
| ERR_IMAGE_READ_PIXELMAP_FAILED      | 62980246 | Failed to read the pixel map.                                 |
| ERR_IMAGE_WRITE_PIXELMAP_FAILED     | 62980247 | Failed to write the pixel map.                                 |
| ERR_IMAGE_PIXELMAP_NOT_ALLOW_MODIFY | 62980248 | Modification to the pixel map is not allowed.                               |
| ERR_IMAGE_CONFIG_FAILED             | 62980259 | The configuration is incorrect.                                         |
