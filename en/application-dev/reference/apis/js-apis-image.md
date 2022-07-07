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

**System capability**: SystemCapability.Multimedia.Image

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
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then((pixelmap) => {
        })
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | Yes  | Color array in BGRA_8888 format. |
| options  | [InitializationOptions](#initializationoptions8) | Yes  | Pixel properties.                    |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```js
const color = new ArrayBuffer(96);
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (pixelmap) => {
        })
```

## PixelMap<sup>7+</sup>

Provides APIs to read or write image pixel map data and obtain image pixel map information. Before calling any API in **PixelMap**, you must use **createPixelMap** to create a **PixelMap** object.

 ### Attributes

**System capability**: SystemCapability.Multimedia.Image

| Name                   | Type   | Readable| Writable| Description                      |
| ----------------------- | ------- | ---- | ---- | -------------------------- |
| isEditable<sup>7+</sup> | boolean | Yes  | No  | Whether the image pixel map is editable.|

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

Reads image pixel map data and writes the data to an **ArrayBuffer**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type       | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| dst    | ArrayBuffer | Yes  | Buffer to which the image pixel map data will be written.|

**Return value**

| Type          | Description                                           |
| :------------- | :---------------------------------------------- |
| Promise\<void> | Promise used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
pixelmap.readPixelsToBuffer(ReadBuffer).then(() => {
    console.log('readPixelsToBuffer succeeded.'); // Called if the condition is met.
}).catch(error => {
    console.log('readPixelsToBuffer failed.'); // Called if no condition is met.
})
```

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads image pixel map data and writes the data to an **ArrayBuffer**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| dst      | ArrayBuffer          | Yes  | Buffer to which the image pixel map data will be written.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the operation result. If the operation fails, an error message is returned.                              |

**Example**

```js
pixelmap.readPixelsToBuffer(ReadBuffer, (err, res) => {
    if(err) {
        console.log('readPixelsToBuffer failed.'); // Called if no condition is met.
    } else {
        console.log('readPixelsToBuffer succeeded.'); // Called if the condition is met.
    }
})
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

Reads image pixel map data in an area. This API uses a promise to return the data read.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](#positionarea7) | Yes  | Area from which the image pixel map data will be read.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
pixelmap.readPixels(Area).then((data) => {
    console.log('readPixels succeeded.'); // Called if the condition is met.
}).catch(error => {
    console.log('readPixels failed.'); // Called if no condition is met.
})
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

Reads image pixel map data in an area. This API uses an asynchronous callback to return the data read.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                          | Mandatory| Description                          |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](#positionarea7) | Yes  | Area from which the image pixel map data will be read.      |
| callback | AsyncCallback\<void>           | Yes  | Callback used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
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

Writes image pixel map data to an area. This API uses a promise to return the operation result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](#positionarea7) | Yes  | Area to which the image pixel map data will be written.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
const color = new ArrayBuffer(96);
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

Writes image pixel map data to an area. This API uses an asynchronous callback to return the operation result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name   | Type                          | Mandatory| Description                          |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](#positionarea7) | Yes  | Area to which the image pixel map data will be written.          |
| callback: | AsyncCallback\<void>           | Yes  | Callback used to return the operation result. If the operation fails, `error` contains an error object.|

**Example**

```js
pixelmap.writePixels(Area, (error) => {
    if (error!=undefined) {
		console.info('writePixels failed.');
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

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Buffer from which the image data will be read.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
PixelMap.writeBufferToPixels(color).then(() => {
    console.log("Succeeded in writing data from a buffer to a PixelMap.");
}).catch((err) => {
    console.error("Failed to write data from a buffer to a PixelMap.");
})
```

### writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads image data in an **ArrayBuffer** and writes the data to a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | Yes  | Buffer from which the image data will be read.                |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
PixelMap.writeBufferToPixels(color, function(err) {
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

**System capability**: SystemCapability.Multimedia.Image

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](#imageinfo)> | Promise used to return the pixel map information. If the operation fails, an error message is returned.|

**Example**

```js
PixelMap.getImageInfo().then(function(info) {
    console.log("Succeeded in obtaining the image pixel map information.");
}).catch((err) => {
    console.error("Failed to obtain the image pixel map information.");
});
```

### getImageInfo<sup>7+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains pixel map information of this image. This API uses an asynchronous callback to return the information.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the pixel map information. If the operation fails, an error message is returned.|

**Example**

```js
pixelmap.getImageInfo((imageInfo) => { 
    console.log("getImageInfo succeeded.");
}).catch((err) => {
    console.error("getImageInfo failed.");
})
```

### getBytesNumberPerRow<sup>7+</sup>

getBytesNumberPerRow(): number

Obtains the number of bytes per line of the image pixel map.

**System capability**: SystemCapability.Multimedia.Image

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Number of bytes per line.|

**Example**

```js
image.createPixelMap(clolr, opts, (err,pixelmap) => {
    let rowCount = pixelmap.getBytesNumberPerRow();
})
```

### getPixelBytesNumber<sup>7+</sup>

getPixelBytesNumber(): number

Obtains the total number of bytes of the image pixel map.

**System capability**: SystemCapability.Multimedia.Image

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

**System capability**: SystemCapability.Multimedia.Image

**Return value**

| Type          | Description              |
| -------------- | ------------------ |
| Promise\<void> | Promise used to return the operation result.|

**Example**

```js
image.createPixelMap(color, opts, (pixelmap) => {
    pixelmap.release().then(() => {
	    console.log('release succeeded.');
    }).catch(error => {
	    console.log('release failed.');
    })
})
```

### release<sup>7+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the operation result.|

**Example**

```js
image.createPixelMap(color, opts, (pixelmap) => {
    pixelmap.release().then(() => {
	    console.log('release succeeded.');
    }).catch(error => {
	    console.log('release failed.');
    })
})
```

## image.createImageSource

createImageSource(uri: string): ImageSource

Creates an **ImageSource** instance based on the URI.

**System capability**: SystemCapability.Multimedia.Image

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

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| fd     | number | Yes  | File descriptor.|

**Return value**

| Type                       | Description                                        |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **undefined** otherwise.|

**Example**

```js
const imageSourceApi = image.createImageSource(0);
```

## ImageSource

Provides APIs to obtain image information. Before calling any API in **ImageSource**, you must use **createImageSource** to create an **ImageSource** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Image

| Name            | Type          | Readable| Writable| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats, including png, jpeg, wbmp, bmp, gif, webp, and heif.|

### getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

Obtains information about an image with the specified index. This API uses an asynchronous callback to return the information.

**System capability**: SystemCapability.Multimedia.Image

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

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the image information.|

**Example**

```js
imageSourceApi.getImageInfo(imageInfo => { 
    console.log('getImageInfo succeeded.');
}).catch(error => {
	console.log('getImageInfo failed.');
})
```

### getImageInfo

getImageInfo(index?: number): Promise\<ImageInfo>

Obtains information about an image with the specified index. This API uses a promise to return the image information.

**System capability**: SystemCapability.Multimedia.Image

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
		console.log('getImageInfo succeeded.');
	}).catch(error => {
		console.log('getImageInfo failed.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

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
		console.log('getImageProperty succeeded.');
	}).catch(error => {
		console.log('getImageProperty failed.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

Obtains the value of a property with the specified index in this image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

 **Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | Yes  | Name of the property.                                                |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```js
imageSourceApi.getImageProperty("BitsPerSample",(error,data) => { 
    if(error) {
        console.log('getImageProperty failed.');
    } else {
        console.log('getImageProperty succeeded.');
    }
})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

Obtains the value of a property in this image. This API uses an asynchronous callback to return the property value in a string.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                                               | Yes  | Name of the property.                                                |
| options  | [GetImagePropertyOptions](#getimagepropertyoptions7) | Yes  | Image properties, including the image index and default property value.                        |
| callback | AsyncCallback\<string>                               | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```js
imageSourceApi.getImageProperty("BitsPerSample",Property,(error,data) => { 
    if(error) {
        console.log('getImageProperty failed.');
    } else {
        console.log('getImageProperty succeeded.');
    }
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

Creates a **PixelMap** object based on image decoding parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

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
    console.log('createPixelMap succeeded.');
}).catch(error => {
    console.log('createPixelMap failed.');
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on the default parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```js
imageSourceApi.createPixelMap(pixelmap => { 
    console.log('createPixelMap succeeded.');
}).catch(error => {
    console.log('createPixelMap failed.');
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on image decoding parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | Yes  | Image decoding parameters.                |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```js
imageSourceApi.createPixelMap(decodingOptions, pixelmap => { 
    console.log('createPixelMap succeeded.');
}).catch(error => {
    console.log('createPixelMap failed.');
}) 
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImageSource** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback invoked for instance release. If the operation fails, an error message is returned.|

**Example**

```js
imageSourceApi.release(() => { 
    console.log('release succeeded.');
}).catch(error => {
    console.log('release failed.');
})
```

### release

release(): Promise\<void>

Releases this **ImageSource** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the operation result.|

**Example**

```js
imageSourceApi.release().then(()=>{
    console.log('release succeeded.');
}).catch(error => {
    console.log('release failed.');
})
```

## image.createImagePacker

createImagePacker(): ImagePacker

Creates an **ImagePacker** instance.

**System capability**: SystemCapability.Multimedia.Image

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

**System capability**: SystemCapability.Multimedia.Image

| Name            | Type          | Readable| Writable| Description                      |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | Yes  | No  | Supported image format, which can be jpeg.|

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                              | Mandatory| Description                              |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)        | Yes  | Image to pack.                    |
| option   | [PackingOption](#packingoption)    | Yes  | Option for image packing.                    |
| callback | AsyncCallback\<ArrayBuffer>        | Yes  | Callback used to return the packed data.|

**Example**

```js
let packOpts = { format:"image/jpeg", quality:98 };
imagePackerApi.packing(ImageSourceApi, packOpts, data => {})
```

### packing

packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>

Packs an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

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
let packOpts = { format:["image/jpeg"], quality:98 }
imagePackerApi.packing(ImageSourceApi, packOpts)
    .then( data => {
        console.log('packing succeeded.');
	}).catch(error => {
	    console.log('packing failed.');
	})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                           | Mandatory| Description                              |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [PixelMap](#pixelmap)           | Yes  | **PixelMap** object to pack.              |
| option   | [PackingOption](#packingoption) | Yes  | Option for image packing.                    |
| callback | AsyncCallback\<ArrayBuffer>     | Yes  | Callback used to return the packed data.|

**Example**

```js
let packOpts = { format:["image/jpeg"], quality:98 }
imagePackerApi.packing(PixelMapApi, packOpts, data => { 
    console.log('packing succeeded.');
}).catch(error => {
	console.log('packing failed.');
})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>

Packs an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

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
let packOpts = { format:["image/jpeg"], quality:98 }
imagePackerApi.packing(PixelMapApi, packOpts)
    .then( data => {
	    console.log('packing succeeded.');
	}).catch(error => {
	    console.log('packing failed.');
	})
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImagePacker** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback invoked for instance release. If the operation fails, an error message is returned.|

**Example**

```js
imagePackerApi.release(()=>{ 
    console.log('release succeeded.');
}).catch(error => {
	console.log('release failed.');
})
```

### release

release(): Promise\<void>

Releases this **ImagePacker** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Return value**

| Type          | Description                                                   |
| :------------- | :------------------------------------------------------ |
| Promise\<void> | Promise used to return the instance release result. If the operation fails, an error message is returned.|

**Example**

```js
imagePackerApi.release().then(()=>{
    console.log('release succeeded.');
}).catch((error)=>{ 
    console.log('release failed.'); 
}) 
```

## image.createImageReceiver<sup>9+</sup>

createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver

Create an **ImageReceiver** instance by specifying the image width, height, format, and capacity.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| width    | number | Yes  | Default image width.      |
| height   | number | Yes  | Default image height.      |
| format   | number | Yes  | Image format.            |
| capacity | number | Yes  | Maximum number of images that can be accessed at the same time.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver9) | Returns an **ImageReceiver** instance if the operation is successful.|

**Example**

```js
var receiver = image.createImageReceiver(8192, 8, 4, 8);
```

## ImageReceiver<sup>9+</sup>

Provides APIs to obtain the surface ID of a component, read the latest image, read the next image, and release the **ImageReceiver** instance.

Before calling any APIs in **ImageReceiver**, you must create an **ImageReceiver** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name                 | Type                        | Readable| Writable| Description              |
| --------------------- | ---------------------------- | ---- | ---- | ------------------ |
| size<sup>9+</sup>     | [Size](#size)                | Yes  | No  | Image size.        |
| capacity<sup>9+</sup> | number                       | Yes  | No  | Maximum number of images that can be accessed at the same time.|
| format<sup>9+</sup>   | [ImageFormat](#imageformat9) | Yes  | No  | Image format.        |

### getReceivingSurfaceId<sup>9+</sup>

getReceivingSurfaceId(callback: AsyncCallback\<string>): void

Obtains a surface ID for the camera or other components. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the surface ID.|

**Example**

```js
 receiver.getReceivingSurfaceId((err, id) => { 
    if(err) {
        console.log('getReceivingSurfaceId failed.');
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

```js
receiver.getReceivingSurfaceId().then( id => { 
    console.log('getReceivingSurfaceId succeeded.');
}).catch(error => {
    console.log('getReceivingSurfaceId failed.');
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

```js
receiver.readLatestImage((err, img) => { 
    if(err) {
        console.log('readLatestImage failed.');
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
| Promise<[Image](#image8)> | Promise used to return the latest image.|

**Example**

```js
receiver.readLatestImage().then(img => {
    console.log('readLatestImage succeeded.');
}).catch(error => {
    console.log('readLatestImage failed.');
})
```

### readNextImage<sup>9+</sup>

readNextImage(callback: AsyncCallback\<Image>): void

Reads the next image from the **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type                           | Mandatory| Description                      |
| -------- | ------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[Image](#image9)> | Yes  | Callback used to return the next image.|

**Example**

```js
receiver.readNextImage((err, img) => { 
    if(err) {
        console.log('readNextImage failed.');
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

```js
receiver.readNextImage().then(img => {
    console.log('readNextImage succeeded.');
}).catch(error => {
    console.log('readNextImage failed.');
})
```

### on('imageArrival')<sup>9+</sup>

on(type: 'imageArrival', callback: AsyncCallback\<void>): void

Listens for image arrival events.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type                | Mandatory| Description                                                  |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **imageArrival**, which is triggered when an image is received.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked for the event.                                      |

**Example**

```js
receiver.on('imageArrival', () => {})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **ImageReceiver** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
receiver.release(() => {})
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

```js
receiver.release().then(() => {
    console.log('release succeeded.');
}).catch(error => {
    console.log('release failed.');
})
```

## Image<sup>9+</sup>

Provides APIs for basic image operations, including obtaining image information and reading and writing image data. An **Image** instance is returned when [readNextImage](#readnextimage9) and [readLatestImage](#readlatestimage9) are called.

### Attributes

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                 | Type              | Readable| Writable| Description                                              |
| --------------------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect<sup>9+</sup> | [Region](#region7) | Yes  | Yes  | Image area to be cropped.                                |
| size<sup>9+</sup>     | [Size](#size)      | Yes  | No  | Image size.                                        |
| format<sup>9+</sup>   | number             | Yes  | No  | Image format. For details, see [PixelMapFormat](#pixelmapformat7).|

### getComponent<sup>9+</sup>

getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void

Obtains the component buffer from the **Image** instance based on the color component type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name         | Type                                   | Mandatory| Description                |
| ------------- | --------------------------------------- | ---- | -------------------- |
| componentType | [ComponentType](#componenttype9)        | Yes  | Color component type of the image.    |
| callback      | AsyncCallback<[Component](#component9)> | Yes  | Callback used to return the component buffer.|

**Example**

```js
img.getComponent(4, (err, component) => {
    if(err) {
        console.log('getComponent failed.');
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

| Name         | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| componentType | [ComponentType](#componenttype9) | Yes  | Color component type of the image.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise<[Component](#component9)> | Promise used to return the component buffer.|

**Example**

```js
img.getComponent(4).then(component => { })
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **Image** instance. This API uses an asynchronous callback to return the result.

The corresponding resources must be released before another image arrives.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description          |
| -------- | -------------------- | ---- | -------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
img.release(() =>{ 
    console.log('release succeeded.');
}).catch(error => {
    console.log('release failed.');
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

```js
img.release().then(() =>{
    console.log('release succeeded.');
}).catch(error => {
    console.log('release failed.');
})
```

## PositionArea<sup>7+</sup>

Describes area information in an image.

**System capability**: SystemCapability.Multimedia.Image

| Name  | Type              | Readable| Writable| Description                                                        |
| ------ | ------------------ | ---- | ---- | ------------------------------------------------------------ |
| pixels | ArrayBuffer        | Yes  | No  | Pixels of the image.                                                      |
| offset | number             | Yes  | No  | Offset for data reading.                                                    |
| stride | number             | Yes  | No  | Number of bytes from one row of pixels in memory to the next row of pixels in memory. The value of **stride** must be greater than or equal to the value of **region.size.width** multiplied by 4.                   |
| region | [Region](#region7) | Yes  | No  | Region to read or write. The width of the region to write plus the X coordinate cannot be greater than the width of the original image. The height of the region to write plus the Y coordinate cannot be greater than the height of the original image.|

## ImageInfo

Describes image information.

**System capability**: SystemCapability.Multimedia.Image

| Name| Type         | Readable| Writable| Description      |
| ---- | ------------- | ---- | ---- | ---------- |
| size | [Size](#size) | Yes  | Yes  | Image size.|

## Size

Describes the size of an image.

**System capability**: SystemCapability.Multimedia.Image

| Name  | Type  | Readable| Writable| Description          |
| ------ | ------ | ---- | ---- | -------------- |
| height | number | Yes  | Yes  | Image height.|
| width  | number | Yes  | Yes  | Image width.|

## PixelMapFormat<sup>7+</sup>

Enumerates the pixel formats of images.

**System capability**: SystemCapability.Multimedia.Image

| Name     | Default Value| Description             |
| --------- | ------ | ----------------- |
| UNKNOWN   | 0      | Unknown format.       |
| RGBA_8888 | 3      | RGBA_8888.|
| RGB_565   | 2      | RGB_565.  |

## AlphaType<sup>9+</sup>

Enumerates the alpha types of images.

**System capability**: SystemCapability.Multimedia.Image

| Name    | Default Value| Description                   |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | Unknown alpha type.           |
| OPAQUE   | 1      | There is no alpha or the image is opaque.|
| PREMUL   | 2      | Premultiplied alpha.         |
| UNPREMUL | 3      | Unpremultiplied alpha, that is, straight alpha.       |

## ScaleMode<sup>9+</sup>

Enumerates the scale modes of images.

**System capability**: SystemCapability.Multimedia.Image

| Name           | Default Value| Description                                              |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | The image is scaled in such a way that it fits the dimensions of the target and centered in the target.|
| FIT_TARGET_SIZE | 2      | The image size is reduced to fit the dimensions of the target.                          |

## InitializationOptions<sup>8+</sup>

Defines pixel map initialization options.

**System capability**: SystemCapability.Multimedia.Image

| Name                  | Type                              | Readable| Writable| Description          |
| ---------------------- | ---------------------------------- | ---- | ---- | -------------- |
| alphaType<sup>9+</sup> | [AlphaType](#alphatype9)           | Yes  | Yes  | Alpha type.      |
| editable               | boolean                            | Yes  | Yes  | Whether the image is editable.  |
| pixelFormat            | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format.    |
| scaleMode<sup>9+</sup> | [ScaleMode](#scalemode9)           | Yes  | Yes  | Scale mode.      |
| size                   | [Size](#size)                      | Yes  | Yes  | Image size.|

## DecodingOptions<sup>7+</sup>

Defines image decoding options.

**System capability**: SystemCapability.Multimedia.Image

| Name              | Type                              | Readable| Writable| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | Yes  | Yes  | Thumbnail sampling size.|
| rotate             | number                             | Yes  | Yes  | Rotation angle.      |
| editable           | boolean                            | Yes  | Yes  | Whether the image is editable.    |
| desiredSize        | [Size](#size)                      | Yes  | Yes  | Expected output size.  |
| desiredRegion      | [Region](#region7)                 | Yes  | Yes  | Region to decode.      |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format for decoding.|
| index              | number                              | Yes  | Yes  | Index of the image to decode.    |

## Region<sup>7+</sup>

Describes region information.

**System capability**: SystemCapability.Multimedia.Image

| Name| Type         | Readable| Writable| Description        |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | Yes  | Yes  | Region size.  |
| x    | number        | Yes  | Yes  | X coordinate of the region.|
| y    | number        | Yes  | Yes  | Y coordinate of the region.|

## PackingOption

Describes the option for image packing.

**System capability**: SystemCapability.Multimedia.Image

| Name   | Type  | Readable| Writable| Description          |
| ------- | ------ | ---- | ---- | -------------- |
| format  | string | Yes  | Yes  | Format of the packed image.    |
| quality | number | Yes  | Yes  | Quality of the output image during JPEG encoding. The value ranges from 1 to 100.|

## GetImagePropertyOptions<sup>7+</sup>

Describes image properties.

**System capability**: SystemCapability.Multimedia.Image

| Name        | Type  | Readable| Writable| Description        |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | Yes  | Yes  | Index of an image.  |
| defaultValue | string | Yes  | Yes  | Default property value.|

## PropertyKey<sup>7+</sup>

Describes the exchangeable image file format (Exif) information of an image.

**System capability**: SystemCapability.Multimedia.Image

| Name             | Default Value           | Description                |
| ----------------- | ----------------- | -------------------- |
| BITS_PER_SAMPLE   | "BitsPerSample"   | Number of bits per pixel.    |
| ORIENTATION       | "Orientation"     | Image orientation.          |
| IMAGE_LENGTH      | "ImageLength"     | Image length.          |
| IMAGE_WIDTH       | "ImageWidth"      | Image width.          |
| GPS_LATITUDE      | "GPSLatitude"     | Image latitude.          |
| GPS_LONGITUDE     | "GPSLongitude"    | Image longitude.          |
| GPS_LATITUDE_REF  | "GPSLatitudeRef"  | Latitude reference, for example, N or S.|
| GPS_LONGITUDE_REF | "GPSLongitudeRef" | Longitude reference, for example, W or E.|

## ImageFormat<sup>9+</sup>

Enumerates the image formats.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name        | Default Value| Description                |
| ------------ | ------ | -------------------- |
| YCBCR_422_SP | 1000   | YCBCR422 semi-planar format.|
| JPEG         | 2000   | JPEG encoding format.      |

## ComponentType<sup>9+</sup>

Enumerates the color component types of images.

**System capability**: SystemCapability.Multimedia.Image.ImageReceiver

| Name | Default Value| Description       |
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
