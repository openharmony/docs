图片处理
==========

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

 导入模块
---------

```
import image from './@ohos.multimedia.image';
```

## image.createPixelMap
createPixelMap(colors: ArrayBuffer, opts: InitializetionOptions): Promise\<PixelMap>

通过colors和opts创建pixelmap。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称   | 类型                                            | 必填 | 说明                                                         |
| ------ | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| colors | ArrayBuffer                                     | 是   | 颜色数组。                                                   |
| opts   | [InitializetionOptions](#InitializationOptions) | 是   | 创建像素的属性，包括透明度，尺寸，缩略值，像素格式和是否可编辑。 |

**返回值：**

| 类型               | 说明           |
| ------------------ | -------------- |
| Promise\<PixelMap> | 返回pixelmap。 |

**示例：**

```js
image.createPixelMap(Color, opts)
            .then((pixelmap) => {
            expect(pixelmap !== null).assertTrue()
                done()
            })
```

## image.createPixelMap

createPixelMap(colors: ArrayBuffer, opts: InitializetionOptions) callback: AsyncCallback\<PixelMap>): void

通过属性创建pixelmap。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                            | 必填 | 说明                 |
| -------- | ----------------------------------------------- | ---- | -------------------- |
| colors   | ArrayBuffer                                     | 是   | 颜色数组。           |
| opts     | [InitializetionOptions](#InitializationOptions) | 是   | 属性。               |
| callback | AsyncCallback\<PixelMap>                        | 是   | 回调表示成功或失败。 |

**示例：**

```js
image.createPixelMap(Color, opts, (pixelmap) => {
                expect(pixelmap !== null).assertTrue()
                done()
            })
```

## PixelMap<a name="PixelMap"></a>

图像像素类，用于读取或写入图像数据以及获取图像信息。在调用PixelMap的方法前，需要先通过createPixelMap创建一个PixelMap实例。

 ### 属性

| 名称       | 类型    | 可读 | 可写 | 说明                                                         |
| ---------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| isEditable | boolean | 是   | 否   | 设定是否图像像素可被编辑。<br/>**系统能力：** SystemCapability.Multimedia.Image |

### readPixelsToBuffer

```
readPixelsToBuffer(dst: ArrayBuffer): Promise<void>
```

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

### readPixelsToBuffer

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

读取图像像素数据，结果写入ArrayBuffer里,使用callback形式返回。

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

### readPixels

readPixels(area: PositionArea): Promise\<void>

读取区域内的图片数据，使用Promise形式返回读取结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型                          | 必填 | 说明                     |
| ------ | ----------------------------- | ---- | ------------------------ |
| area   | [PositionArea](#PositionArea) | 是   | 区域大小，根据区域读取。 |

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

### readPixels

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

读区域的像素。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                          | 必填 | 说明                           |
| -------- | ----------------------------- | ---- | ------------------------------ |
| area     | [PositionArea](#PositionArea) | 是   | 区域大小，根据区域读取。       |
| callback | AsyncCallback\<void>          | 是   | 获取回调，失败时返回错误信息。 |

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

### writePixels

writePixels(area: PositionArea): Promise\<void>

先创建pixelmap，将pixelmap写入指定区域内，使用Promise形式返回写入结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：** 

| 参数名 | 类型                          | 必填 | 说明                 |
| ------ | ----------------------------- | ---- | -------------------- |
| area   | [PositionArea](#PositionArea) | 是   | 区域，根据区域写入。 |

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

### writePixels

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

将指定的像素信息写入指定区域内。

**系统能力：** SystemCapability.Multimedia.Image

**参数：** 

| 参数名    | 类型                          | 必填 | 说明                           |
| --------- | ----------------------------- | ---- | ------------------------------ |
| area      | [PositionArea](#PositionArea) | 是   | 区域，根据区域写入。           |
| callback: | AsyncCallback\<void>          | 是   | 获取回调，失败时返回错误信息。 |

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

### writeBufferToPixels

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

将缓冲区的内容写入像素。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型        | 必填 | 说明     |
| ------ | ----------- | ---- | -------- |
| src    | ArrayBuffer | 是   | 缓冲区。 |

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

### writeBufferToPixels

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

将缓冲区的内容写入像素。

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

### getImageInfo

getImageInfo(): Promise\<ImageInfo>

获取图像像素信息，使用Promise形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型                | 说明                                                        |
| ------------------- | ----------------------------------------------------------- |
| Promise\<ImageInfo> | Promise实例，用于异步获取图像像素信息，失败时返回错误信息。 |

**示例：**

```js
pixelMap.getImageInfo().then(function(info) {
    console.log("Succeeded in obtaining the image pixel map information.");
}).catch((err) => {
    console.error("Failed to obtain the image pixel map information.");
});
```

### getImageInfo

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

获取图像像素信息，使用callback形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<ImageInfo> | 是   | 获取图像像素信息回调，异步返回图像像素信息，失败时返回错误信息。 |

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

### getBytesNumberPerRow

getBytesNumberPerRow(): Promise\<number>

获取图像像素每行字节数。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型             | 说明                                          |
| ---------------- | --------------------------------------------- |
| Promise\<number> | Promise实例，用于异步获取图像像素的行字节数。 |

**示例：**

```js
pixelmap.getBytesNumberPerRow().then((num) => {
          console.info('TC_025 num is ' + num)
          expect(num == expectNum).assertTrue()
          done()
        })
```

### getBytesNumberPerRow

getBytesNumberPerRow(callback: AsyncCallback\<number>): void

获取图像像素每行字节数。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                   | 必填 | 说明               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | 是   | 通过回调返回结果。 |

**示例：**

```js
pixelmap.getBytesNumberPerRow( num => {
            console.info('TC_025-1 num is ' + num);
            expect(num == expectNum).assertTrue();
            done();
        })
```

### getPixelBytesNumber

getPixelBytesNumber(): Promise\<number>

获取图像像素的总字节数。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型             | 说明                                          |
| ---------------- | --------------------------------------------- |
| Promise\<number> | Promise实例，用于异步获取图像像素的总字节数。 |

**示例：**

```js
pixelmap.getPixelBytesNumber().then((num) => {
          console.info('TC_026 num is ' + num)
          expect(num == expectNum).assertTrue()
          done()
        })
```

### getPixelBytesNumber

getPixelBytesNumber(callback: AsyncCallback\<number>): void

获取图像像素的总字节数。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                   | 必填 | 说明               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | 是   | 通过回调返回结果。 |

**示例：**

```js
pixelmap.getPixelBytesNumber((num) => {
        console.info('TC_026-1 num is ' + num)
        expect(num == expectNum).assertTrue()
        done()
      })
```

### release

release(): void

释放pixelmap对象，使用Promise形式返回释放结果。

**系统能力：** SystemCapability.Multimedia.Image

**示例：**

```js
pixelmap.release()
        expect(true).assertTrue()
        done()
```

## image.createImageSource

createImageSource(uri: string): ImageSource

创建图片源。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| uri    | string | 是   | 图片路径。 |

**返回值：**

| 类型        | 说明         |
| ----------- | ------------ |
| ImageSource | 返回图片源。 |

**示例：**

```js
const imageSourceApi = image.createImageSource('/data/local/tmp/test.jpg')
```

## image.createImageSource

createImageSource(fd: number): ImageSource

创建图片源。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| fd     | number | 是   | 基于fd创建图片源。 |

**返回值：**

| 类型        | 说明         |
| ----------- | ------------ |
| ImageSource | 返回图片源。 |

**示例：**

```js
const imageSourceApi = image.createImageSource(0)
```

## image.createImageSource

createImageSource(data: ArrayBuffer): ImageSource

创建图片源。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型        | 必填 | 说明   |
| ------ | ----------- | ---- | ------ |
| data   | ArrayBuffer | 是   | 数组。 |

**返回值：**

| 类型        | 说明         |
| ----------- | ------------ |
| ImageSource | 返回图片源。 |

**示例：**

```js
const data = new ArrayBuffer(96);
const imageSourceApi = image.createImageSource(data);
```

## image.createIncrementalSource

createIncrementalSource(data: ArrayBuffer): ImageSource

创建增量图片源。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型        | 必填 | 说明 |
| ------ | ----------- | ---- | ---- |
| data   | ArrayBuffer | 是   | 数组 |

**返回值：**

| 类型        | 说明         |
| ----------- | ------------ |
| ImageSource | 返回图片源。 |

**示例：**

```js
const data = new ArrayBuffer(96);
const imageSourceApi = image.createIncrementalSource(data);
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

| 参数名   | 类型                                   | 必填 | 说明                                            |
| -------- | -------------------------------------- | ---- | ----------------------------------------------- |
| index    | number                                 | 是   | 图片序号，创建图片源时的序号，不选择时默认为0。 |
| callback | AsyncCallback<[ImageInfo](#ImageInfo)> | 是   | 获取图片信息回调，异步返回图片信息对象。        |

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

获取指定序号的图片信息，使用callback形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                   | 必填 | 说明                                     |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#ImageInfo)> | 是   | 获取图片信息回调，异步返回图片信息对象。 |

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

| 名称  | 类型   | 必填 | 说明                                            |
| ----- | ------ | ---- | ----------------------------------------------- |
| index | number | 否   | 图片序号，创建图片源时的序号，不选择时默认为0。 |

**返回值：**

| 类型                              | 说明                   |
| --------------------------------- | ---------------------- |
| Promise\<[ImageInfo](#ImageInfo)> | 返回获取到的图片信息。 |

**示例：**

```js
imageSourceApi.getImageInfo(0)
            .then(imageInfo => {
                console.info('TC_047 imageInfo');
                expect(imageInfo !== null).assertTrue();
                done();
            })
```

### getImageProperty

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

获取图片中给定索引处图像的指定属性键的值。

**系统能力：** SystemCapability.Multimedia.Image

 **参数：**

| 名称    | 类型                                                | 必填 | 说明                                 |
| ------- | --------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                              | 是   | 图片属性名。                         |
| options | [GetImagePropertyOptions](#GetImagePropertyOptions) | 否   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<string> | Promise实例，用于异步获取图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```js
const w = imageSourceApi.getImageProperty("ImageWidth")
```

### getImageProperty

getImageProperty(key:string, callback: AsyncCallback\<string>): void

获取图片中给定索引处图像的指定属性键的值，使用callback形式返回结果。

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

### getImageProperty

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

获取图片指定属性键的值，callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                                         |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                                              | 是   | 图片属性名。                                                 |
| options  | [GetImagePropertyOptions](#GetImagePropertyOptions) | 是   | 图片属性，包括图片序号与默认属性值。                         |
| callback | AsyncCallback\<string>                              | 是   | 获取图片属性回调，返回图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```js
 imageSourceApi.getImageProperty("ImageWidth",PropertyOptions,(w)=>{})
```

### modifyImageProperty

modifyImageProperty(key:string, value:string, options?: GetImagePropertyOptions): Promise\<void>

修改属性的值。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名  | 类型                                                | 必填 | 说明                                 |
| ------- | --------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                              | 是   | 图片属性名。                         |
| value   | string                                              | 是   | 属性值。                             |
| options | [GetImagePropertyOptions](#GetImagePropertyOptions) | 是   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

**示例：**

```js
imageSourceApi.modifyImageProperty("ImageWidth", "abc")
            .then(() => {
                const w = imageSourceApi.getImageProperty("ImageWidth")
                console.info('w', w);
                expect(w == 'abc').assertTrue();
                done();
            })
```

### modifyImageProperty

modifyImageProperty(key:string, value:string, callback: AsyncCallback\<void>): void

修改属性的值，callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| key      | string               | 是   | 图片属性名。                   |
| value    | string               | 是   | 属性值。                       |
| callback | AsyncCallback\<void> | 是   | 修改属性值，callback返回结果。 |

**示例：**

```js
imageSourceApi.modifyImageProperty("ImageWidth", "abc",() => {})
```

### modifyImageProperty

modifyImageProperty(key:string, value:string, options: GetImagePropertyOptions,callback: AsyncCallback\<void>): void

修改属性的值，callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                 |
| -------- | --------------------------------------------------- | ---- | ------------------------------------ |
| key      | string                                              | 是   | 图片属性名。                         |
| value    | string                                              | 是   | 属性值。                             |
| options  | [GetImagePropertyOptions](#GetImagePropertyOptions) | 是   | 图片属性，包括图片序号与默认属性值。 |
| callback | AsyncCallback\<void>                                | 是   | 修改属性值，callback返回结果。       |

**示例：**

```js
let PropertyOptions = {
                    index:0,
                    defaultValue:'a'
imageSourceApi.modifyImageProperty("ImageWidth", "abc",PropertyOptions,() => {
                
                };
```

### createPixelMap

createPixelMap(index: number, options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

通过图片解码参数创建pixelmap对象，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称          | 类型                                 | 必填 | 说明                 |
| ------------- | ------------------------------------ | ---- | -------------------- |
| options       | [DecodingOptions](#DecodingOptions)  | 是   | 解码参数。           |
| index         | number                               | 是   | 图片索引。           |
| AsyncCallback | AsyncCallback<[PixelMap](#PixelMap)> | 是   | 回调表示成功或失败。 |

**示例：**

```js
imageSourceApi.createPixelMap().then(pixelmap => {
                console.info('TC_050-11 createPixelMap ');
                expect(pixelmap !== null ).assertTrue();
                done();
            })
```

### createPixelMap

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

通过图片解码参数创建pixelmap对象。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                 | 必填 | 说明                 |
| -------- | ------------------------------------ | ---- | -------------------- |
| options  | [DecodingOptions](#DecodingOptions)  | 是   | 解码参数。           |
| callback | AsyncCallback<[PixelMap](#PixelMap)> | 是   | 回调表示成功或失败。 |

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

### createPixelMap

createPixelMap(opts: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

通过图片解码参数创建pixelmap对象。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                                 | 必填 | 说明                 |
| -------- | ------------------------------------ | ---- | -------------------- |
| opts     | [DecodingOptions](#DecodingOptions)  | 是   | 解码参数。           |
| callback | AsyncCallback<[PixelMap](#PixelMap)> | 是   | 回调表示成功或失败。 |

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

### updateData

updateData(data: Array\<number>, isFinal: boolean, offset: number, length: number, callback: AsyncCallback\<boolean>): void

更新增量数据。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                    | 必填 | 说明                 |
| -------- | ----------------------- | ---- | -------------------- |
| data     | Array\<number>          | 是   | 增量数据。           |
| isFinal  | boolean                 | 是   | 是否更新完。         |
| offset   | number                  | 是   | 偏移量。             |
| length   | number                  | 是   | 数组长。             |
| callback | AsyncCallback\<boolean> | 是   | 回调表示成功或失败。 |

**示例：**

```js
imageSourceIncrementalSApi.updateData(array, false, 0, 10,(error,data )=> {
            if(data !== undefined){
                expect(data).assertTrue();
                console.info('TC_053-1 success');
                done();      
            }
```

### updateData

updateData(data: Array\<number>, isFinal: boolean, offset?: number, length?: number): Promise\<boolean>

更新增量数据。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称    | 类型           | 必填 | 说明         |
| ------- | -------------- | ---- | ------------ |
| data    | Array\<number> | 是   | 增量数据。   |
| isFinal | boolean        | 是   | 是否更新完。 |
| offset  | boolean        | 否   | 偏移量。     |
| length  | number         | 否   | 数组长。     |

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise\<boolean> | Promise实例，异步返回成功或失败。 |

**示例：**

```js
 imageSourceIncrementalSApi.updateData(array, false, 0, 10).then(data => {
            expect(data).assertTrue();
            console.info('TC_053 success');
            done();
        })
```

### updateData

updateData(data: Array\<number>, isFinal: boolean, callback: AsyncCallback\<boolean>): void

更新增量数据。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 名称     | 类型                    | 必填 | 说明                 |
| -------- | ----------------------- | ---- | -------------------- |
| data     | Array\<number>          | 是   | 增量数据。           |
| isFinal  | boolean                 | 是   | 是否更新完。         |
| callback | AsyncCallback\<boolean> | 是   | 回调表示成功或失败。 |

**示例：**

```js
imageSourceIncrementalSApi.updateData(array, false,(error,data) => {
            if(data !== undefined){
                expect(data).assertTrue();
                console.info('TC_053-2 success');
                done();      
            }      
```

### release

release(callback: AsyncCallback\<void>): void

释放图片源。

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

释放图片源。

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

创建imagepacker实例。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型        | 说明              |
| ----------- | ----------------- |
| ImagePacker | 返回ImagePacker。 |

**示例：**

```js
const imagePackerApi = image.createImagePacker();
```

## ImagePacker

图片打包器类，用于图片压缩和打包。在调用ImagePacker的方法前，需要先通过createImagePacker构建一个ImagePacker实例。

### 属性

| 名称             | 类型           | 可读 | 可写 | 说明                                                         |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | 是   | 否   | 图片打包支持的格式，jpg。<br/>**系统能力：** SystemCapability.Multimedia.Image |

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback<Array\<number>>): void

图片压缩或重新打包，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                            | 必填 | 说明                               |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#ImageSource)     | 是   | 打包的图片源。                     |
| option   | [PackingOption](#PackingOption) | 是   | 设置打包参数。                     |
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

图片压缩或重新打包，使用promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#ImageSource)     | 是   | 打包的图片源。 |
| option | [PackingOption](#PackingOption) | 是   | 设置打包参数。 |

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

释放packer对象。

**系统能力：** SystemCapability.Multimedia.Image

**参数：**

| 参数名   | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<void> | 是   | 回调表示成功还是失败。 |

**示例：**

```js
imagePackerApi.release(()=>{
            console.info('TC_063-1 release');
            expect(true).assertTrue();
            done();
```

### release

release(): Promise\<void>

释放packer对象。

**系统能力：** SystemCapability.Multimedia.Image

**返回值：**

| 类型           | 说明                            |
| :------------- | :------------------------------ |
| Promise\<void> | Promise实例，用于异步返回结果。 |

**示例：**

```js
imagePackerApi.release();
 console.info('TC_063 release');
 expect(true).assertTrue();
 done();
```

## PositionArea<a name="PositionArea"></a>

| 名称   | 类型              | 可读 | 可写 | 说明                                                         |
| ------ | ----------------- | ---- | ---- | ------------------------------------------------------------ |
| pixels | ArrayBuffer       | 是   | 否   | 像素。<br>**系统能力：** SystemCapability.Multimedia.Image   |
| offset | number            | 是   | 否   | 偏移量。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| stride | number            | 是   | 否   | 像素间距。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| region | [Region](#Region) | 是   | 否   | 区域，按照区域读写。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## **ImageInfo<a name="ImageInfo"></a>**

| 名称        | 类型                              | 可读 | 可写 | 说明                                                         |
| ----------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| size        | [Size](#Size)                     | 是   | 是   | 图片大小。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| pixelFormat | [PixelMapFormat](#PixelMapFormat) | 是   | 是   | 图片格式。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| colorSpace  | [ColorSpace](#ColorSpace)         | 是   | 是   | 色域。<br/>**系统能力：** SystemCapability.Multimedia.Image  |
| alphaType   | [AlphaType](#AlphaType)           | 是   | 是   | 透明度。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## Size<a name="Size"></a>

| 名称   | 类型   | 可读 | 可写 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| height | number | 是   | 是   | 输出图片的高。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| width  | number | 是   | 是   | 输出图片的宽。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## PixelMapFormat<a name="PixelMapFormat"></a>

枚举，像素格式。

| 名称      | 默认值 | 描述                                                         |
| --------- | ------ | ------------------------------------------------------------ |
| UNKNOWN   | 0      | 未知格式。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| ARGB_8888 | 1      | 格式为ARGB_8888。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| RGB_565   | 2      | 格式为RGB_565。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## ColorSpace<a name="ColorSpace"></a>

枚举，色块。

| 名称                 | 默认值 | 描述                                                         |
| -------------------- | ------ | ------------------------------------------------------------ |
| UNKNOWN              | 0      | 色块基于unknown color space。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| DISPLAY_P3           | 1      | 色块基于 SMPTE RP 431-2-2007 and IEC 61966-2.1:199。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| SRGB                 | 2      | 色块基于IEC 61966-2.1:1999。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| LINEAR_SRGB          | 3      | 色块基于the IEC 61966-2.1:1999。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| EXTENDED_SRGB        | 4      | 色块基于IEC 61966-2-2:2003。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| LINEAR_EXTENDED_SRGB | 5      | 色块基于IEC 61966-2-2:2003。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| GENERIC_XYZ          | 6      | 色块基于D50。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| GENERIC_LAB          | 7      | 色块基于 CIE XYZ D50。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| ACES                 | 8      | 色块基于SMPTE ST 2065-1:2012。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| ACES_CG              | 9      | 色块基于Academy S-2014-004。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| ADOBE_RGB_1998       | 10     | 色块基于 Adobe RGB。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| DCI_P3               | 11     | 色块基于SMPTE RP 431-2-2007。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| ITU_709              | 12     | 色块基于Rec.ITU-R BT.709-5。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| ITU_2020             | 13     | 色块基于Rec.ITU-R BT.2020-1。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| ROMM_RGB             | 14     | 色块基于ISO 22028-2:2013。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| NTSC_1953            | 15     | 色块基于NTSC 1953 standard。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| SMPTE_C              | 16     | 色块基于 SMPTE C。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## AlphaType<a name="AlphaType"></a>

枚举，透明度。

| 名称     | 默认值 | 描述                                                         |
| -------- | ------ | ------------------------------------------------------------ |
| UNKNOWN  | 0      | 未知透明度。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| OPAQUE   | 1      | 没有alpha或图片全透明。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| PREMUL   | 2      | RGB前乘alpha。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| UNPREMUL | 3      | RGB不前乘alpha。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## ScaleMode<a name="ScaleMode"></a>

枚举，缩略值。

| 名称            | 默认值 | 描述                                                         |
| --------------- | ------ | ------------------------------------------------------------ |
| CENTER_CROP     | 1      | 缩放图像以填充目标图像区域并居中裁剪区域外的效果。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| FIT_TARGET_SIZE | 2      | 图像适合目标尺寸的效果。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## InitializationOptions<a name="InitializationOptions"></a>

| 名称        | 类型                              | 可读 | 可写 | 说明                                                         |
| ----------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| alphaType   | [AlphaType](#AlphaType)           | 是   | 是   | 透明度。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| editable    | boolean                           | 是   | 是   | 是否可编辑。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| pixelFormat | [PixelMapFormat](#PixelMapFormat) | 是   | 是   | 像素格式。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| scalemode   | [ScaleMode](#ScaleMode)           | 是   | 是   | 缩略值。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| size        | [Size](#Size)                     | 是   | 是   | 创建图片大小。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## DecodingOptions<a name="DecodingOptions"></a>

解码设置选项。

| 名称               | 类型                              | 可读 | 可写 | 说明                                                         |
| ------------------ | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| sampleSize         | number                            | 是   | 是   | 缩略图采样大小。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| rotateDegrees      | number                            | 是   | 是   | 旋转角度。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| editable           | boolean                           | 是   | 是   | 是否可编辑。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| desiredSize        | [Size](#Size)                     | 是   | 是   | 期望输出大小。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| desiredRegion      | [Region](#Region)                 | 是   | 是   | 解码区域。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| desiredPixelFormat | [PixelMapFormat](#PixelMapFormat) | 是   | 是   | 解码的像素格式。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| reusedPixelMap     | [PixelMap](#PixelMap)             | 是   | 是   | 将当前buffer地址给新创建的pixelmap。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## Region<a name="Region"></a>

| 名称 | 类型          | 可读 | 可写 | 说明                                                         |
| ---- | ------------- | ---- | ---- | ------------------------------------------------------------ |
| size | [Size](#Size) | 是   | 是   | 区域大小。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| x    | number        | 是   | 是   | 区域坐标。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| y    | number        | 是   | 是   | 区域坐标。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## PackingOption<a name="PackingOption"></a>

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| format  | string | 是   | 是   | 目标格式。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| quality | number | 是   | 是   | 目标图片质量。<br/>**系统能力：** SystemCapability.Multimedia.Image |

## GetImagePropertyOptions<a name="GetImagePropertyOptions"></a>

| 名称         | 类型   | 可读 | 可写 | 说明       |
| ------------ | ------ | ---- | ---- | ---------- |
| index        | number | 是   | 是   | 图片序号。<br/>**系统能力：** SystemCapability.Multimedia.Image |
| defaultValue | string | 是   | 是   | 默认属性值<br/>**系统能力：** SystemCapability.Multimedia.Image |

