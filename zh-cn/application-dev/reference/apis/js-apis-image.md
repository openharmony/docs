# 图片处理

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import image from '@ohos.multimedia.image';
```

## image.createPixelMap<sup>8+</sup>
createPixelMap(colors: ArrayBuffer, opts: InitializetionOptions): Promise\<PixelMap>

通过属性创建Pixelmap，通过Promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称    | 类型                                             | 必填 | 说明                                                         |
| ------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| colors  | ArrayBuffer                                      | 是   | 颜色数组。                                                   |
| options | [InitializetionOptions](#InitializationOptions8) | 是   | 创建像素的属性，包括透明度，尺寸，缩略值，像素格式和是否可编辑。 |

**返回值：**

| 类型                             | 说明           |
| -------------------------------- | -------------- |
| Promise\<[PixelMap](#pixelmap7)> | 返回pixelmap。 |

**示例：**

```js
image.createPixelMap(Color, opts)
            .then((pixelmap) => {
            expect(pixelmap !== null).assertTrue()
                done()
            })
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, opts: InitializetionOptions) callback: AsyncCallback\<PixelMap>): void

通过属性创建Pixelmap，通过回调函数返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                             | 必填 | 说明                 |
| -------- | ------------------------------------------------ | ---- | -------------------- |
| colors   | ArrayBuffer                                      | 是   | 颜色数组。           |
| options  | [InitializetionOptions](#InitializationOptions8) | 是   | 属性。               |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | 是   | 回调表示成功或失败。 |

**示例：**

```js
image.createPixelMap(Color, opts, (pixelmap) => {
                expect(pixelmap !== null).assertTrue()
                done()
            })
```

## PixelMap<sup>7+</sup>

图像像素类，用于读取或写入图像数据以及获取图像信息。在调用PixelMap的方法前，需要先通过createPixelMap创建一个PixelMap实例。

 ### 属性

| 名称                    | 类型    | 可读 | 可写 | 说明                                                         |
| ----------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| isEditable<sup>7+</sup> | boolean | 是   | 否   | 设定是否图像像素可被编辑。<br/>**系统能力：** SystemCapability.Multimedia.Image |

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

读取图像像素数据，结果写入ArrayBuffer里，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                         |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| dst    | ArrayBuffer | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。 |

**返回值：**

| 类型           | 说明                                            |
| :------------- | :---------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

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

读取图像像素数据，结果写入ArrayBuffer里，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| dst      | ArrayBuffer          | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。 |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。                               |

**示例：**

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

读取区域内的图片数据，使用Promise形式返回读取结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](#positionarea7) | 是   | 区域大小，根据区域读取。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise实例，用于获取读取结果，失败时返回错误信息。 |

**示例：**

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

读取区域内的图片数据，使用callback形式返回读取结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                           | 必填 | 说明                           |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](#positionarea7) | 是   | 区域大小，根据区域读取。       |
| callback | AsyncCallback\<void>           | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

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

将Pixelmap写入指定区域内，使用Promise形式返回写入结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：** 

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](#PositionArea7) | 是   | 区域，根据区域写入。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise实例，用于获取写入结果，失败时返回错误信息。 |

**示例：**

```js
pixelMap.writePixels(area).then(() => {
    console.log("Succeeded in writing pixels.");
}).catch((err) => {
    console.error("Failed to write pixels.");
});
```

### writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

将Pixelmap写入指定区域内，使用callback形式返回写入结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：** 

| 参数名    | 类型                           | 必填 | 说明                           |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](#PositionArea7) | 是   | 区域，根据区域写入。           |
| callback: | AsyncCallback\<void>           | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

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

读取缓冲区中的图片数据，结果写入Pixelmap中，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型        | 必填 | 说明           |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | 是   | 图像像素数据。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```js
pixelMap.writeBufferToPixels(colorBuffer).then(() => {
    console.log("Succeeded in writing data from a buffer to a PixelMap.");
}).catch((err) => {
    console.error("Failed to write data from a buffer to a PixelMap.");
});
```

### writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

读取缓冲区中的图片数据，结果写入Pixelmap中，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | 是   | 图像像素数据。                 |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

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

获取图像像素信息，使用Promise形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型                              | 说明                                                        |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](#imageinfo)> | Promise实例，用于异步获取图像像素信息，失败时返回错误信息。 |

**示例：**

```js
pixelMap.getImageInfo().then(function(info) {
    console.log("Succeeded in obtaining the image pixel map information.");
}).catch((err) => {
    console.error("Failed to obtain the image pixel map information.");
});
```

### getImageInfo<sup>7+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

获取图像像素信息，使用callback形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](#imageinfo)> | 是   | 获取图像像素信息回调，异步返回图像像素信息，失败时返回错误信息。 |

**示例:**

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

获取图像像素每行字节数。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的行字节数。 |

**示例：**

```js
pixelmap.getBytesNumberPerRow().then((num) => {
          console.info('TC_025 num is ' + num)
          expect(num == expectNum).assertTrue()
          done()
        })
```

### getPixelBytesNumber<sup>7+</sup>

getPixelBytesNumber(): number

获取图像像素的总字节数。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的总字节数。 |

**示例：**

```js
pixelmap.getPixelBytesNumber().then((num) => {
          console.info('TC_026 num is ' + num)
          expect(num == expectNum).assertTrue()
          done()
        })
```

### release<sup>7+</sup>

release():Promise\<void>

释放Pixelmap对象，使用Promise形式返回释放结果。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型           | 说明               |
| -------------- | ------------------ |
| Promise\<void> | 异步返回释放结果。 |

**示例：**

```js
pixelmap.release()
        expect(true).assertTrue()
        done()
```

### release<sup>7+</sup>

release(callback: AsyncCallback\<void>): void

释放Pixelmap对象，使用callback形式返回释放结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | 是   | 异步返回释放结果。 |

**示例：**

```js
pixelmap.release(()=>{
                expect(true).assertTrue();
                console.log('TC_027-1 success');
                done();
            })   
```

## image.createImageSource

createImageSource(uri: string): ImageSource

通过传入的uri创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型   | 必填 | 说明                               |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | 是   | 图片路径，当前仅支持本地绝对路径。 |

**返回值：**

| 类型                        | 说明                                    |
| --------------------------- | --------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回null。 |

**示例：**

```js
const imageSourceApi = image.createImageSource('/data/local/tmp/test.jpg')
```

## image.createImageSource<sup>7+</sup>

createImageSource(fd: number): ImageSource

通过传入文件描述符来创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| fd     | number | 是   | 文件描述符fd。 |

**返回值：**

| 类型                        | 说明                                    |
| --------------------------- | --------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回null。 |

**示例：**

```js
const imageSourceApi = image.createImageSource(0)
```

## ImageSource

图片源类，用于获取图片相关信息。在调用ImageSource的方法前，需要先通过createImageSource构建一个ImageSource实例。

### 属性

| 名称             | 类型           | 可读 | 可写 | 说明                                                         |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | 是   | 否   | 支持的图片格式，包括：png，jpeg，wbmp，bmp，gif，webp，heif等。<br/>**系统能力：** SystemCapability.Multimedia.Image |

### getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

获取指定序号的图片信息，使用callback形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                     |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | 是   | 创建图片源时的序号。                     |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | 是   | 获取图片信息回调，异步返回图片信息对象。 |

**示例：**

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

获取图片信息，使用callback形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                   | 必填 | 说明                                     |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | 是   | 获取图片信息回调，异步返回图片信息对象。 |

**示例：**

```js
imageSourceApi.getImageInfo(imageInfo => {
                console.info('TC_045 imageInfo');
                expect(imageInfo !== null).assertTrue();
                done();
            })
```

### getImageInfo

getImageInfo(index?: number): Promise\<ImageInfo>

获取图片信息，使用Promise形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称  | 类型   | 必填 | 说明                                  |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | 否   | 创建图片源时的序号，不选择时默认为0。 |

**返回值：**

| 类型                             | 说明                   |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](#imageinfo)> | 返回获取到的图片信息。 |

**示例：**

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

获取图片中给定索引处图像的指定属性键的值，用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

 **参数：**

| 名称    | 类型                                                 | 必填 | 说明                                 |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                               | 是   | 图片属性名。                         |
| options | [GetImagePropertyOptions](#getimagepropertyoptions7) | 否   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<string> | Promise实例，用于异步获取图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```js
const w = imageSourceApi.getImageProperty("ImageWidth")
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

获取图片中给定索引处图像的指定属性键的值，用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

 **参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | 是   | 图片属性名。                                                 |
| callback | AsyncCallback\<string> | 是   | 获取图片属性回调，返回图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```js
const w = imageSourceApi.getImageProperty("ImageWidth",w=>{})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

获取图片指定属性键的值，callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                                               | 是   | 图片属性名。                                                 |
| options  | [GetImagePropertyOptions](#getimagepropertyoptions7) | 是   | 图片属性，包括图片序号与默认属性值。                         |
| callback | AsyncCallback\<string>                               | 是   | 获取图片属性回调，返回图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```js
 imageSourceApi.getImageProperty("ImageWidth",PropertyOptions,(w)=>{})
```

### createPixelMap<sup>7+</sup>

createPixelMap(index: number, options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

通过图片解码参数创建Pixelmap对象，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称          | 类型                                  | 必填 | 说明                 |
| ------------- | ------------------------------------- | ---- | -------------------- |
| options       | [DecodingOptions](#decodingoptions7)  | 是   | 解码参数。           |
| index         | number                                | 是   | 图片索引。           |
| AsyncCallback | AsyncCallback<[PixelMap](#pixelmap7)> | 是   | 回调表示成功或失败。 |

**示例：**

```js
imageSourceApi.createPixelMap().then(pixelmap => {
                console.info('TC_050-11 createPixelMap ');
                expect(pixelmap !== null ).assertTrue();
                done();
            })
```

### createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

通过图片解码参数创建pixelmap对象。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                  | 必填 | 说明                 |
| -------- | ------------------------------------- | ---- | -------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | 是   | 解码参数。           |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | 是   | 回调表示成功或失败。 |

**示例：**

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

通过图片解码参数创建pixelmap对象。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                  | 必填 | 说明                 |
| -------- | ------------------------------------- | ---- | -------------------- |
| opts     | [DecodingOptions](#decodingoptions7)  | 是   | 解码参数。           |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | 是   | 回调表示成功或失败。 |

**示例：**

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

释放图片源实例，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | 是   | 资源释放回调，失败时返回错误信息。 |

**示例：**

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

释放图片源实例，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```js
 imageSourceApi.release(() => {
                console.info('TC_044-1 Success');
                expect(true).assertTrue();
                done();
            })
```

## image.createImagePacker

createImagePacker(): ImagePacker

创建ImagePacker实例。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型        | 说明                   |
| ----------- | ---------------------- |
| ImagePacker | 返回ImagePackers实例。 |

**示例：**

```js
const imagePackerApi = image.createImagePacker();
```

## ImagePacker

图片打包器类，用于图片压缩和打包。在调用ImagePacker的方法前，需要先通过createImagePacker构建一个ImagePacker实例。

### 属性

| 名称             | 类型           | 可读 | 可写 | 说明                                                         |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | 是   | 否   | 图片打包支持的格式，jpeg。<br/>**系统能力：** SystemCapability.Multimedia.Image |

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback<Array\<number>>): void

图片压缩或重新打包，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                            | 必填 | 说明                               |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)     | 是   | 打包的图片源。                     |
| option   | [PackingOption](#packingoption) | 是   | 设置打包参数。                     |
| callback | AsyncCallback<Array\<number>>   | 是   | 获取图片打包回调，返回打包后数据。 |

**示例：**

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

图片压缩或重新打包，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | 是   | 打包的图片源。 |
| option | [PackingOption](#packingoption) | 是   | 设置打包参数。 |

**返回值：**

| 类型                    | 说明                                          |
| :---------------------- | :-------------------------------------------- |
| Promise<Array\<number>> | Promise实例，用于异步获取压缩或打包后的数据。 |

**示例：**

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

释放图片打包实例，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | 是   | 释放回调，失败时返回错误信息。 |

**示例：**

```js
imagePackerApi.release(()=>{
            console.info('TC_063-1 release');
            expect(true).assertTrue();
            done();
```

### release

release(): Promise\<void>

释放图片打包实例，使用Promise形式返回释放结果。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型           | 说明                                                    |
| :------------- | :------------------------------------------------------ |
| Promise\<void> | Promise实例，用于异步获取释放结果，失败时返回错误信息。 |

**示例：**

```js
imagePackerApi.release();
 console.info('TC_063 release');
 expect(true).assertTrue();
 done();
```

## PositionArea<sup>7+</sup>

表示图片指定区域内的数据。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称   | 类型               | 可读 | 可写 | 说明                 |
| ------ | ------------------ | ---- | ---- | -------------------- |
| pixels | ArrayBuffer        | 是   | 否   | 像素。               |
| offset | number             | 是   | 否   | 偏移量。             |
| stride | number             | 是   | 否   | 像素间距。           |
| region | [Region](#region8) | 是   | 否   | 区域，按照区域读写。 |

## **ImageInfo**

表示图片信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称 | 类型          | 可读 | 可写 | 说明       |
| ---- | ------------- | ---- | ---- | ---------- |
| size | [Size](#size) | 是   | 是   | 图片大小。 |

## Size

表示图片尺寸。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称   | 类型   | 可读 | 可写 | 说明           |
| ------ | ------ | ---- | ---- | -------------- |
| height | number | 是   | 是   | 输出图片的高。 |
| width  | number | 是   | 是   | 输出图片的宽。 |

## PixelMapFormat<sup>7+</sup>

枚举，像素格式。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称      | 默认值 | 描述              |
| --------- | ------ | ----------------- |
| UNKNOWN   | 0      | 未知格式。        |
| RGBA_8888 | 3      | 格式为RGBA_8888。 |
| RGB_565   | 2      | 格式为RGB_565。   |

## AlphaType<sup>8+</sup>

枚举，透明度。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称     | 默认值 | 描述                    |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | 未知透明度。            |
| OPAQUE   | 1      | 没有alpha或图片全透明。 |
| PREMUL   | 2      | RGB前乘alpha。          |
| UNPREMUL | 3      | RGB不前乘alpha。        |

## ScaleMode<sup>8+</sup>

枚举，缩略值。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称            | 默认值 | 描述                                               |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | 缩放图像以填充目标图像区域并居中裁剪区域外的效果。 |
| FIT_TARGET_SIZE | 2      | 图像适合目标尺寸的效果。                           |

## InitializationOptions<sup>8+</sup>

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称        | 类型                               | 可读 | 可写 | 说明           |
| ----------- | ---------------------------------- | ---- | ---- | -------------- |
| alphaType   | [AlphaType](#alphatype8)           | 是   | 是   | 透明度。       |
| editable    | boolean                            | 是   | 是   | 是否可编辑。   |
| pixelFormat | [PixelMapFormat](#pixelmapformat7) | 是   | 是   | 像素格式。     |
| scaleMode   | [ScaleMode](#scalemode8)           | 是   | 是   | 缩略值。       |
| size        | [Size](#size)                      | 是   | 是   | 创建图片大小。 |

## DecodingOptions<sup>7+</sup>

解码设置选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称               | 类型                               | 可读 | 可写 | 说明             |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | 是   | 是   | 缩略图采样大小。 |
| rotateDegrees      | number                             | 是   | 是   | 旋转角度。       |
| editable           | boolean                            | 是   | 是   | 是否可编辑。     |
| desiredSize        | [Size](#size)                      | 是   | 是   | 期望输出大小。   |
| desiredRegion      | [Region](#region8)                 | 是   | 是   | 解码区域。       |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | 是   | 是   | 解码的像素格式。 |
| index              | numer                              | 是   | 是   | 解码图片序号     |

## Region<sup>8+</sup>

表示区域信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称 | 类型          | 可读 | 可写 | 说明       |
| ---- | ------------- | ---- | ---- | ---------- |
| size | [Size](#size) | 是   | 是   | 区域大小。 |
| x    | number        | 是   | 是   | 区域坐标。 |
| y    | number        | 是   | 是   | 区域坐标。 |

## PackingOption

表示图片打包选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称    | 类型   | 可读 | 可写 | 说明           |
| ------- | ------ | ---- | ---- | -------------- |
| format  | string | 是   | 是   | 目标格式。     |
| quality | number | 是   | 是   | 目标图片质量。 |

## GetImagePropertyOptions<sup>7+</sup>

表示查询图片属性的索引。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Image

| 名称         | 类型   | 可读 | 可写 | 说明         |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | 是   | 是   | 图片序号。   |
| defaultValue | string | 是   | 是   | 默认属性值。 |

## PropertyKey<sup>7+</sup>

枚举，Exif（Exchangeable image file format）图片信息。

| 名称              | 默认值            | 说明                 |
| ----------------- | ----------------- | -------------------- |
| BITS_PER_SAMPLE   | "BitsPerSample"   | 每个像素字节数。     |
| ORIENTATION       | "Orientation"     | 图片方向。           |
| IMAGE_LENGTH      | "ImageLength"     | 图片长度。           |
| IMAGE_WIDTH       | "ImageWidth"      | 图片宽度。           |
| GPS_LATITUDE      | "GPSLatitude"     | 图片纬度。           |
| GPS_LONGITUDE     | "GPSLongitude"    | 图片经度。           |
| GPS_LATITUDE_REF  | "GPSLatitudeRef"  | 纬度引用，例如N或S。 |
| GPS_LONGITUDE_REF | "GPSLongitudeRef" | 经度引用，例如W或E。 |