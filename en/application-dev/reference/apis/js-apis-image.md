Image Processing
==========

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

 Modules to Import
---------

```
import image from '@ohos.multimedia.image';
```

## image.createPixelMap<sup>8+</sup>
createPixelMap(colors: ArrayBuffer, opts: InitializetionOptions): Promise\<PixelMap>

Creates a **PixelMap** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                                            | Mandatory| Description                                                        |
| ------ | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| colors | ArrayBuffer                                      | Yes  | Color array.                                                  |
| opts   | [InitializetionOptions](#InitializationOptions8) | Yes  | Pixel properties, including the alpha type, size, scale mode, pixel format, and editable.|

**Return value**

| Type                            | Description          |
| -------------------------------- | -------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise used to return the **PixelMap** object created.|

**Example**

```js
image.createPixelMap(Color, opts)
            .then((pixelmap) => {
            expect(pixelmap !== null).assertTrue()
                done()
            })
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, opts: InitializetionOptions) callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                            | Mandatory| Description                |
| -------- | ------------------------------------------------ | ---- | -------------------- |
| colors   | ArrayBuffer                                      | Yes  | Color array.          |
| opts     | [InitializetionOptions](#InitializationOptions8) | Yes  | Pixel properties.              |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | Yes  | Callback used to return the **PixelMap** object obtained.|

**Example**

```js
image.createPixelMap(Color, opts, (pixelmap) => {
                expect(pixelmap !== null).assertTrue()
                done()
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
                    var bufferArr = new Uint8Array(readBuffer)
                    var res = true
                    for (var i = 0; i < bufferArr.length; i++) {
                        if (res) {
                            if (bufferArr[i] !== 0) {
                                res = false
                                console.info('TC_020 Success')
                                expect(true).assertTrue()
                                done()
                                break
                            }
                        }
                    }
                    if (res) {
                        console.info('TC_020 buffer is all empty')
                        expect(false).assertTrue()
                        done()
                    }
                })
```

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads image pixel map data and writes the data to an **ArrayBuffer**. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| dst      | ArrayBuffer          | Yes  | Buffer to which the image pixel map data will be written.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the operation result. If the operation fails, an error message is returned.                              |

**Example**

```js
pixelmap.readPixelsToBuffer(readBuffer, () => {
                var bufferArr = new Uint8Array(readBuffer)
                var res = true
                for (var i = 0; i < bufferArr.length; i++) {
                    if (res) {
                        if (bufferArr[i] !== 0) {
                            res = false
                            console.info('TC_020-1 Success')
                            expect(true).assertTrue()
                            done()
                            break
                        }
                    }
                }
                if (res) {
                    console.info('TC_020-1 buffer is all empty')
                    expect(false).assertTrue()
                    done()
                }
            })
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

Reads pixel map data in an area. This API uses a promise to return the data read.

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
                        if(data !== null){
                        var bufferArr = new Uint8Array(area.pixels);
                        var res = true;
                        for (var i = 0; i < bufferArr.length; i++) {
                            console.info('TC_021 buffer ' + bufferArr[i]);
                            if(res) {
                                if (bufferArr[i] == 0) {
                                    res = false;
                                    console.info('TC_021 Success');
                                    expect(true).assertTrue();
                                    done();
                                    break;
                                }
                            }
                        }
                        if (res) {
                            console.info('TC_021 buffer is all empty');
                            expect(false).assertTrue()
                            done();
                        }
                    }
                })
```

### readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

Reads image pixel map data in an area. This API uses a callback to return the data read.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                          | Mandatory| Description                          |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](#positionarea7) | Yes  | Area from which the image pixel map data will be read.      |
| callback | AsyncCallback\<void>           | Yes  | Callback used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
pixelmap.readPixels(area,(data) => {
            if(data !== null) {
                var bufferArr = new Uint8Array(area.pixels);
                var res = true;
                for (var i = 0; i < bufferArr.length; i++) {
                    console.info('TC_021-1 buffer ' + bufferArr[i]);
                    if(res) {
                        if(bufferArr[i] == 0) {
                            res = false;
                            console.info('TC_021-1 Success');
                            expect(true).assertTrue();
                            done();
                            break;
                        }
                    }
                }
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea): Promise\<void>

Writes image pixel map data to an area. This API uses a promise to return the operation result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](#PositionArea7) | Yes  | Area to which the pixel map data will be written.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise used to return the operation result. If the operation fails, an error message is returned.|

**Example**

```js
pixelMap.writePixels(area).then(() => {
    console.log("Succeeded in writing pixels.");
}).catch((err) => {
    console.error("Failed to write pixels.");
});
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

Writes image pixel map data to an area. This API uses a callback to return the operation result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name   | Type                          | Mandatory| Description                          |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](#PositionArea7) | Yes  | Area to which the pixel map data will be written.          |
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

Reads image data in an **ArrayBuffer** and writes the data to a **PixelMap** object. This API uses a callback to return the result.

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

Obtains pixel map information about this image. This API uses a promise to return the information.

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

Obtains pixel map information about this image. This API uses a callback to return the information.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the pixel map information. If the operation fails, an error message is returned.|

**Example**

```js
pixelmap.getImageInfo((imageInfo) => {
                if (imageInfo !== null) {
                    console.info('TC_024-1 imageInfo is ready')
                    expect(imageInfo.size.height == 4).assertTrue()
                    expect(imageInfo.size.width == 6).assertTrue()
                    expect(imageInfo.pixelFormat == 1).assertTrue()
                    done()
                } else {
                    console.info('TC_024-1 imageInfo is empty')
                    expect(false).assertTrue()
                    done()
                }
            })
```

### getBytesNumberPerRow<sup>7+</sup>

getBytesNumberPerRow(): number

Obtains the number of bytes in each line of the image pixel map.

**System capability**: SystemCapability.Multimedia.Image

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Number of bytes in each line.|

**Example**

```js
pixelmap.getBytesNumberPerRow().then((num) => {
          console.info('TC_025 num is ' + num)
          expect(num == expectNum).assertTrue()
          done()
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
pixelmap.getPixelBytesNumber().then((num) => {
          console.info('TC_026 num is ' + num)
          expect(num == expectNum).assertTrue()
          done()
        })
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
pixelmap.release()
        expect(true).assertTrue()
        done()
```

### release<sup>7+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **PixelMap** object. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the operation result.|

**Example**

```js
pixelmap.release(()=>{
                expect(true).assertTrue();
                console.log('TC_027-1 success');
                done();
            })   
```

## image.createImageSource

createImageSource(uri: string): ImageSource

Creates an **ImageSource** instance based on the URI.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | Yes  | Image source URI. Currently, only the local absolute path is supported.|

**Return value**

| Type                       | Description                                   |
| --------------------------- | --------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **null** otherwise.|

**Example**

```js
const imageSourceApi = image.createImageSource('/data/local/tmp/test.jpg')
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

| Type                       | Description                                   |
| --------------------------- | --------------------------------------- |
| [ImageSource](#imagesource) | Returns the **ImageSource** instance if the operation is successful; returns **null** otherwise.|

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

Obtains information about an image with the specified index. This API uses a callback to return the information.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | Yes  | Index of the image.                    |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the image information.|

**Example**

```js
it('TC_046', 0, async function (done) {
        const imageSourceApi = image.createImageSource('/sdcard/test.jpg');
        if (imageSourceApi == null) {
            console.info('TC_046 create image source failed');
            expect(false).assertTrue();
            done();
        } else {
            imageSourceApi.getImageInfo(0,(error, imageInfo) => {
                console.info('TC_046 imageInfo');
                expect(imageInfo !== null).assertTrue();
                done();
            })
        }
    })
```

### getImageInfo

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains information about this image. This API uses a callback to return the information.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | Yes  | Callback used to return the image information.|

**Example**

```js
imageSourceApi.getImageInfo(imageInfo => {
                console.info('TC_045 imageInfo');
                expect(imageInfo !== null).assertTrue();
                done();
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
                console.info('TC_047 imageInfo');
                expect(imageInfo !== null).assertTrue();
                done();
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
const w = imageSourceApi.getImageProperty("ImageWidth")
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

Obtains the value of a property with the specified index in this image. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

 **Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | Yes  | Name of the property.                                                |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```js
const w = imageSourceApi.getImageProperty("ImageWidth",w=>{})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

Obtains the value of a property in this image. This API uses a callback to return the property value in a string.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                                               | Yes  | Name of the property.                                                |
| options  | [GetImagePropertyOptions](#getimagepropertyoptions7) | Yes  | Image properties, including the image index and default property value.                        |
| callback | AsyncCallback\<string>                               | Yes  | Callback used to return the property value. If the operation fails, the default value is returned.|

**Example**

```js
 imageSourceApi.getImageProperty("ImageWidth",PropertyOptions,(w)=>{})
```

### createPixelMap<sup>7+</sup>

createPixelMap(index: number, options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on image decoding parameters. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name         | Type                                 | Mandatory| Description                |
| ------------- | ------------------------------------- | ---- | -------------------- |
| options       | [DecodingOptions](#decodingoptions7)  | Yes  | Image decoding parameters.          |
| index         | number                                | Yes  | Image index.          |
| AsyncCallback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the operation result.|

**Example**

```js
imageSourceApi.createPixelMap().then(pixelmap => {
                console.info('TC_050-11 createPixelMap ');
                expect(pixelmap !== null ).assertTrue();
                done();
            })
```

### createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on image decoding parameters. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                 | Mandatory| Description                |
| -------- | ------------------------------------- | ---- | -------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | Yes  | Image decoding parameters.          |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the operation result.|

**Example**

```js
let decodingOptions = {
                sampleSize:1,
                editable: true, 
                desiredSize:{ width:1, height:2},
                rotateDegrees:10,
                desiredPixelFormat:1,
                desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 },
            };
            imageSourceApi.createPixelMap(0,decodingOptions, pixelmap => {
                console.info('TC_050-1 createPixelMap ');
                expect(pixelmap !== null ).assertTrue();
                done();
            })
```

### createPixelMap<sup>7+</sup>

createPixelMap(opts: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a **PixelMap** object based on image decoding parameters. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                                 | Mandatory| Description                |
| -------- | ------------------------------------- | ---- | -------------------- |
| opts     | [DecodingOptions](#decodingoptions7)  | Yes  | Image decoding parameters.          |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | Yes  | Callback used to return the operation result.|

**Example**

```js
let decodingOptions = {
                sampleSize:1,
                editable: true, 
                desiredSize:{ width:1, height:2},
                rotateDegrees:10,
                desiredPixelFormat:1,
                desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 },
                index:1
            };
            imageSourceApi.createPixelMap(decodingOptions, pixelmap => {
                console.info('TC_050-1 createPixelMap ');
                expect(pixelmap !== null ).assertTrue();
                done();
            })    
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImageSource** instance. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name    | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback invoked for instance release. If the operation fails, an error message is returned.|

**Example**

```js
imageSourceApi.release(() => {
                console.info('TC_044-1 Success');
                expect(true).assertTrue();
                done();
            })
        }
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
 imageSourceApi.release(() => {
                console.info('TC_044-1 Success');
                expect(true).assertTrue();
                done();
            })
```

## image.createImagePacker

createImagePacker(): ImagePacker

Creates an **ImagePacker** instance.

**System capability**: SystemCapability.Multimedia.Image

**Return value**

| Type       | Description                  |
| ----------- | ---------------------- |
| ImagePacker | **ImagePacker** instance created.|

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

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback<Array\<number>>): void

Packs an image. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                           | Mandatory| Description                              |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)     | Yes  | Image to pack.                    |
| option   | [PackingOption](#packingoption) | Yes  | Option for image packing.                    |
| callback | AsyncCallback<Array\<number>>   | Yes  | Callback used to return the packed data.|

**Example**

```js
let packOpts = { format:["image/jpeg"], quality:98 }
                imagePackerApi.packing(imageSourceApi, packOpts, data => {
                    console.info('TC_062-1 finished');
                    expect(data !== null).assertTrue();
                    done();
                })
```

### packing

packing(source: ImageSource, option: PackingOption): Promise<Array\<number>>

Packs an image. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | Yes  | Image to pack.|
| option | [PackingOption](#packingoption) | Yes  | Option for image packing.|

**Return value**

| Type                   | Description                                         |
| :---------------------- | :-------------------------------------------- |
| Promise<Array\<number>> | Promise used to return the packed data.|

**Example**

```js
let packOpts = { format:["image/jpeg"], quality:98 }
                imagePackerApi.packing(imageSourceApi, packOpts)
                .then( data => {
                    console.info('TC_062 finished');
                    expect(data !== null).assertTrue();
                    done();
                })
```

### release

release(callback: AsyncCallback\<void>): void

Releases this **ImagePacker** instance. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Image

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback invoked for instance release. If the operation fails, an error message is returned.|

**Example**

```js
imagePackerApi.release(()=>{
            console.info('TC_063-1 release');
            expect(true).assertTrue();
            done();
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
imagePackerApi.release();
 console.info('TC_063 release');
 expect(true).assertTrue();
 done();
```

## PositionArea<sup>7+</sup>

Describes area information in an image.

**System capability**: SystemCapability.Multimedia.Image

| Name  | Type              | Readable| Writable| Description                |
| ------ | ------------------ | ---- | ---- | -------------------- |
| pixels | ArrayBuffer        | Yes  | No  | Pixels of the image.              |
| offset | number             | Yes  | No  | Offset for data reading.            |
| stride | number             | Yes  | No  | Number of bytes to read.          |
| region | [Region](#region8) | Yes  | No  | Region to read or write.|

## **ImageInfo**

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

## AlphaType<sup>8+</sup>

Enumerates alpha types.

**System capability**: SystemCapability.Multimedia.Image

| Name    | Default Value| Description                   |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | Unknown alpha type.           |
| OPAQUE   | 1      | There is no alpha or the image is fully transparent.|
| PREMUL   | 2      | Premultiplied alpha.         |
| UNPREMUL | 3      | Unpremultiplied alpha, that is, straight alpha.       |

## ScaleMode<sup>8+</sup>

Enumerates scale modes.

**System capability**: SystemCapability.Multimedia.Image

| Name           | Default Value| Description                                              |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | Scales the image so that it fills the requested bounds of the target and crops the extra.|
| FIT_TARGET_SIZE | 2      | Reduces the image size to the dimensions of the target.                          |

## InitializationOptions<sup>8+</sup>

**System capability**: SystemCapability.Multimedia.Image

| Name       | Type                              | Readable| Writable| Description          |
| ----------- | ---------------------------------- | ---- | ---- | -------------- |
| alphaType   | [AlphaType](#alphatype8)           | Yes  | Yes  | Alpha type.      |
| editable    | boolean                            | Yes  | Yes  | Whether the image is editable.  |
| pixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format.    |
| scaleMode   | [ScaleMode](#scalemode8)           | Yes  | Yes  | Scale mode.      |
| size        | [Size](#size)                      | Yes  | Yes  | Image size.|

## DecodingOptions<sup>7+</sup>

Describes the decoding options.

**System capability**: SystemCapability.Multimedia.Image

| Name              | Type                              | Readable| Writable| Description            |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | Yes  | Yes  | Thumbnail sampling size.|
| rotateDegrees      | number                             | Yes  | Yes  | Rotation angle.      |
| editable           | boolean                            | Yes  | Yes  | Whether the image is editable.    |
| desiredSize        | [Size](#size)                      | Yes  | Yes  | Expected output size.  |
| desiredRegion      | [Region](#region8)                 | Yes  | Yes  | Region to decode.      |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | Yes  | Yes  | Pixel map format for decoding.|
| index              | numer                              | Yes  | Yes  | Index of the image to decode.    |

## Region<sup>8+</sup>

Describes region information.

**System capability**: SystemCapability.Multimedia.Image

| Name| Type         | Readable| Writable| Description      |
| ---- | ------------- | ---- | ---- | ---------- |
| size | [Size](#size) | Yes  | Yes  | Region size.|
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

| Name             | Default Value           | Description                |
| ----------------- | ----------------- | -------------------- |
| BITS_PER_SAMPLE   | "BitsPerSample"   | Number of bytes in each pixel.    |
| ORIENTATION       | "Orientation"     | Image orientation.          |
| IMAGE_LENGTH      | "ImageLength"     | Image length.          |
| IMAGE_WIDTH       | "ImageWidth"      | Image width.          |
| GPS_LATITUDE      | "GPSLatitude"     | Image latitude.          |
| GPS_LONGITUDE     | "GPSLongitude"    | Image longitude.          |
| GPS_LATITUDE_REF  | "GPSLatitudeRef"  | Latitude reference, for example, N or S.|
| GPS_LONGITUDE_REF | "GPSLongitudeRef" | Longitude reference, for example, W or E.|
