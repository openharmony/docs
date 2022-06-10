# Image Processing

> **NOTE**<br/>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> API version 9 is a canary release for trial use. The APIs of this version may be unstable.

## Modules to Import

```
import image from '@ohos.multimedia.image';
```

## image.createPixelMap<sup>8+</sup>
createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>

Creates a **PixelMap** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name   | Type                                            | Mandatory| Description                                                        |
| ------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| colors  | ArrayBuffer                                      | Yes  | Color array.                                                  |
| options | [InitializetionOptions](#initializationoptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**

| Type                            | Description          |
| -------------------------------- | -------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object.|

**Example**

```js
image.createPixelMap(Color, opts)
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
| colors   | ArrayBuffer                                      | Yes  | Color array.                |
| options  | [InitializetionOptions](#initializationoptions8) | Yes  | Pixel properties.                    |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | Yes  | Callback used to return the **PixelMap** object.|

**Example**

```js
image.createPixelMap(Color, opts, (pixelmap) => {
            })
```

## PixelMap<sup>7+</sup>

Provides APIs to read or write image pixel map data and obtain image pixel map information. Before calling any API in **PixelMap**, you must use **createPixelMap** to create a **PixelMap** object.

 ### Attributes

| Name                   | Type   | Readable| Writable| Description                                                        |
| ----------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| isEditable<sup>7+</sup> | boolean | Yes  | No  | Whether the image pixel map is editable.<br>**System capability**: SystemCapability.Multimedia.Image|

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
pixelmap.readPixelsToBuffer(readBuffer).then(() => {
                        // Called if the condition is met.
                }).catch(error => {
                // Called if no condition is met.
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
pixelmap.readPixelsToBuffer(readBuffer, () => {
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
pixelmap.readPixels(area).then((data) => {
                  // Called if the condition is met.     
                }).catch(error => {
                // Called if no condition is met.
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
          console.info('createPixelMap failed');
          expect(false).assertTrue();
          done();
      }else{
          const area = { pixels: new ArrayBuffer(8),
                    offset: 0,
                    stride: 8,
                    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }}
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
            console.info('createPixelMap failed');
            expect(false).assertTrue()
            done();
        }
        const area = { pixels: new ArrayBuffer(8),
            offset: 0,
            stride: 8,
            region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
        }
        var bufferArr = new Uint8Array(area.pixels);
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
    })
    .catch(error => {
        console.log('error: ' + error);
        expect().assertFail();
        done();
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
| callback: | AsyncCallback\<void>           | Yes  | Callback used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
pixelmap.writePixels(area, () => {
                const readArea = {
                    pixels: new ArrayBuffer(20),
                    offset: 0,
                    stride: 8,
                    region: { size: { height: 1, width: 2 }, x: 0, y: 0 },
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
pixelMap.writeBufferToPixels(colorBuffer).then(() => {
    console.log("Succeeded in writing data from a buffer to a PixelMap.");
}).catch((err) => {
    console.error("Failed to write data from a buffer to a PixelMap.");
});
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
pixelMap.writeBufferToPixels(colorBuffer, function(err) {
    if (err) {
        console.error("Failed to write data from a buffer to a PixelMap.");
        return;
    }
    console.log("Succeeded in writing data from a buffer to a PixelMap.");
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
pixelMap.getImageInfo().then(function(info) {
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
pixelmap.getImageInfo((imageInfo) => {})
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
rowCount = pixelmap.getBytesNumberPerRow()
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
pixelBytesNumber = pixelmap.getPixelBytesNumber()
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
 pixelmap.release().then(() => { })
            .catch(error => {})
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
pixelmap.release(()=>{ })   
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
const imageSourceApi = image.createImageSource(0)
```

## ImageSource

Provides APIs to obtain image information. Before calling any API in **ImageSource**, you must use **createImageSource** to create an **ImageSource** instance.

### Attributes

| Name            | Type          | Readable| Writable| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats, including png, jpeg, wbmp, bmp, gif, webp, and heif.<br>**System capability**: SystemCapability.Multimedia.Image|

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
imageSourceApi.getImageInfo(0,(error, imageInfo) => {})
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
imageSourceApi.getImageInfo(imageInfo => {})
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
            .then(imageInfo => {})
			.catch(error => {})
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
            .then(data => {})
            .catch(error => {})
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
imageSourceApi.getImageProperty("BitsPerSample",(error,data) => {})
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
imageSourceApi.getImageProperty("BitsPerSample",property,(error,data) => {})
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
imageSourceApi.createPixelMap().then(pixelmap => {})
    						.catch(error => {})
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
imageSourceApi.createPixelMap(pixelmap => {})
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
imageSourceApi.createPixelMap(decodingOptions, pixelmap => {})    
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
imageSourceApi.release(() => {})
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
imageSourceApi.release().then(()=>{ }).catch(error => {})
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

| Name            | Type          | Readable| Writable| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported image format, which can be jpeg.<br>**System capability**: SystemCapability.Multimedia.Image|

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

Packs an image. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                              | Mandatory| Description                              |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)        | Yes  | Image to pack.                    |
| option   | [PackingOption](#packingoption)    | Yes  | Option for image packing.                    |
| callback | AsyncCallback\<ArrayBuffer> | Yes  | Callback used to return the packed data.|

**Example**

```js
let packOpts = { format:["image/jpeg"], quality:98 }
imagePackerApi.packing(imageSourceApi, packOpts, data => {})
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
imagePackerApi.packing(imageSourceApi, packOpts)
    .then( data => { })
	.catch(error => {})
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
imagePackerApi.packing(pixelMapApi, packOpts, data => {})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>

Packs an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [PixelMap](#pixelmap)           | Yes  | **PixelMap** object to pack.|
| option | [PackingOption](#packingoption) | Yes  | Option for image packing.|

**Return value**

| Type                        | Description                                         |
| :--------------------------- | :-------------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the packed data.|

**Example**

```js
let packOpts = { format:["image/jpeg"], quality:98 }
imagePackerApi.packing(pixelMapApi, packOpts)
    .then( data => { })
	.catch(error => {})
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
imagePackerApi.release(()=>{})
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
            }).catch((error)=>{}) 
```

## PositionArea<sup>7+</sup>

Describes area information in an image.

**System capability**: SystemCapability.Multimedia.Image

| Name  | Type              | Readable| Writable| Description                                                        |
| ------ | ------------------ | ---- | ---- | ------------------------------------------------------------ |
| pixels | ArrayBuffer        | Yes  | No  | Pixels of the image.                                                      |
| offset | number             | Yes  | No  | Offset for data reading.                                                    |
| stride | number             | Yes  | No  | Number of bytes from one row of pixels in memory to the next row of pixels in memory. The value of **stride** must be greater than or equal to the value of **region.size.width** multiplied by 4.                    |
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

Enumerates pixel map formats.

**System capability**: SystemCapability.Multimedia.Image

| Name     | Default Value| Description             |
| --------- | ------ | ----------------- |
| UNKNOWN   | 0      | Unknown format.       |
| RGBA_8888 | 3      | RGBA_8888.|
| RGB_565   | 2      | RGB_565.  |

## AlphaType<sup>9+</sup>

Enumerates alpha types.

**System capability**: SystemCapability.Multimedia.Image

| Name    | Default Value| Description                   |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | Unknown alpha type.           |
| OPAQUE   | 1      | There is no alpha or the image is opaque.|
| PREMUL   | 2      | Premultiplied alpha.         |
| UNPREMUL | 3      | Unpremultiplied alpha, that is, straight alpha.       |

## ScaleMode<sup>9+</sup>

Enumerates scale modes.

**System capability**: SystemCapability.Multimedia.Image

| Name           | Default Value| Description                                              |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | The image is scaled in such a way that it fits the dimensions of the target and centered in the target.|
| FIT_TARGET_SIZE | 2      | The image size is reduced to fit the dimensions of the target.                          |

## InitializationOptions<sup>8+</sup>

**System capability**: SystemCapability.Multimedia.Image

| Name       | Type                              | Readable| Writable| Description          |
| ----------- | ---------------------------------- | ---- | ---- | -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](#alphatype9)           | Yes  | Yes  | Alpha type.      |
| editable    | boolean                            | Yes  | Yes  | Whether the image is editable.  |
| pixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format.    |
| scaleMode<sup>9+</sup>   | [ScaleMode](#scalemode9)           | Yes  | Yes  | Scale mode.      |
| size        | [Size](#size)                      | Yes  | Yes  | Image size.|

## DecodingOptions<sup>7+</sup>

Describes the decoding options.

**System capability**: SystemCapability.Multimedia.Image

| Name              | Type                              | Readable| Writable| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | Yes  | Yes  | Thumbnail sampling size.|
| rotate             | number                             | Yes  | Yes  | Rotation angle.      |
| editable           | boolean                            | Yes  | Yes  | Whether the image is editable.    |
| desiredSize        | [Size](#size)                      | Yes  | Yes  | Expected output size.  |
| desiredRegion      | [Region](#region7)                 | Yes  | Yes  | Region to decode.      |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format for decoding.|
| index              | numer                              | Yes  | Yes  | Index of the image to decode.    |

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
| quality | number | Yes  | Yes  | Quality of the packed image.|

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
