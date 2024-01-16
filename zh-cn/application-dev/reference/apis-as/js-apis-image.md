# @ohos.multimedia.image (图片处理)

本模块提供图片处理效果，包括通过解码获取PixelMap、获取图片信息、对图片压缩和打包等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import image from '@ohos.multimedia.image';
```

## PixelMap<sup>7+</sup>

图像像素类，需要先通过[createPixelMap](#createpixelmap7)创建一个PixelMap实例。目前pixelmap序列化大小最大128MB，超过会送显失败。大小计算方式为(宽\*高\*每像素占用字节数)。

从API version 11开始，PixelMap支持通过worker跨线程调用。当PixelMap通过[Worker](js-apis-worker.md)跨线程后，原线程的PixelMap的所有接口均不能调用，否则将报错501 服务器不具备完成请求的功能。


### 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型    | 可读 | 可写 | 说明                       |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable        | boolean | 是   | 否   | 设定是否图像像素可被编辑。 |
| isStrideAlignment | boolean | 是   | 否   | 设定图像内存是否为DMA内存。 |


### readPixelsToBuffer<sup>11+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

读取图像像素数据，结果写入ArrayBuffer里，使用Promise形式返回。指定BGRA_8888格式创建pixelmap，读取的像素数据与原数据保持一致。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                                                  |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const readBuffer : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
    pixelMap.readPixelsToBuffer(readBuffer).then(() => {
        console.log('Succeeded in reading image pixel data.');  //符合条件则进入 
    }).catch((error : BusinessError) => {
        console.error('Failed to read image pixel data.');  //不符合条件则进入
    })
}
```

### readPixelsToBuffer<sup>11+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

读取图像像素数据，结果写入ArrayBuffer里，使用callback形式返回。指定BGRA_8888格式创建pixelmap，读取的像素数据与原数据保持一致。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。                                                                        |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const readBuffer : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
    pixelMap.readPixelsToBuffer(readBuffer, (err : BusinessError, res : void) => {
        if(err) {
            console.error('Failed to read image pixel data.');  //不符合条件则进入
            return;
        } else {
            console.log('Succeeded in reading image pixel data.');  //符合条件则进入
        }
    })
}
```

### readPixels<sup>11+</sup>

readPixels(area: PositionArea): Promise\<void>

读取区域内的图片数据，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](#positionarea7) | 是   | 区域大小，根据区域读取。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise实例，用于获取读取结果，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const area : image.PositionArea = {
        pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    pixelMap.readPixels(area).then(() => {
        console.log('Succeeded in reading the image data in the area.'); //符合条件则进入
    }).catch((error : BusinessError) => {
        console.error('Failed to read the image data in the area.'); //不符合条件则进入
    })
}
```

### readPixels<sup>11+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

读取区域内的图片数据，使用callback形式返回读取结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                           | 必填 | 说明                           |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](#positionarea7) | 是   | 区域大小，根据区域读取。       |
| callback | AsyncCallback\<void>           | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const area : image.PositionArea = {
        pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    pixelMap.readPixels(area, (err : BusinessError) => {
        if (err != undefined) {
            console.error('Failed to read pixelmap from the specified area.');
            return;
        } else {
            console.info('Succeeded to read pixelmap from the specified area.');
        }
    })
}
```

### writePixels<sup>11+</sup>

writePixels(area: PositionArea): Promise\<void>

将PixelMap写入指定区域内，使用Promise形式返回写入结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](#positionarea7) | 是   | 区域，根据区域写入。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise实例，用于获取写入结果，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const area : image.PositionArea = {
        pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    let bufferArr : Uint8Array = new Uint8Array(area.pixels);
    for (let i = 0; i < bufferArr.length; i++) {
        bufferArr[i] = i + 1;
    }
    pixelMap.writePixels(area).then(() => {
        console.info('Succeeded to write pixelmap into the specified area.');
    }).catch((error : BusinessError) => {
        console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
    })
}
```

### writePixels<sup>11+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

将PixelMap写入指定区域内，使用callback形式返回写入结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名    | 类型                           | 必填 | 说明                           |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](#positionarea7) | 是   | 区域，根据区域写入。           |
| callback  | AsyncCallback\<void>           | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const area : image.PositionArea = { pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    let bufferArr : Uint8Array = new Uint8Array(area.pixels);
    for (let i = 0; i < bufferArr.length; i++) {
        bufferArr[i] = i + 1;
    }
    pixelMap.writePixels(area, (error : BusinessError) => {
        if (error != undefined) {
            console.error('Failed to write pixelmap into the specified area.');
            return;
        } else {
            console.info('Succeeded to write pixelmap into the specified area.');
        }
    })
}
```

### writeBufferToPixels<sup>11+</sup>

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

读取缓冲区中的图片数据，结果写入PixelMap中，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明           |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | 是   | 图像像素数据。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
    let bufferArr : Uint8Array = new Uint8Array(color);
    for (let i = 0; i < bufferArr.length; i++) {
        bufferArr[i] = i + 1;
    }
    pixelMap.writeBufferToPixels(color).then(() => {
        console.log("Succeeded in writing data from a buffer to a PixelMap.");
    }).catch((error : BusinessError) => {
        console.error("Failed to write data from a buffer to a PixelMap.");
    })
}
```

### writeBufferToPixels<sup>11+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

读取缓冲区中的图片数据，结果写入PixelMap中，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | 是   | 图像像素数据。                 |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
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
    })
}
```

### getImageInfo<sup>11+</sup>

getImageInfo(): Promise\<ImageInfo>

获取图像像素信息，使用Promise形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                              | 说明                                                        |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](#imageinfo)> | Promise实例，用于异步获取图像像素信息，失败时返回错误信息。 |

**示例：**

```ts
async function Demo() {
    pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
        if (imageInfo == undefined) {
            console.error("Failed to obtain the image pixel map information.");
        }
        if (imageInfo.size.height == 4 && imageInfo.size.width == 6) {
            console.log("Succeeded in obtaining the image pixel map information.");
        }
    })
}
```

### getImageInfo<sup>11+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

获取图像像素信息，使用callback形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](#imageinfo)> | 是   | 获取图像像素信息回调，异步返回图像像素信息，失败时返回错误信息。 |

**示例:**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    pixelMap.getImageInfo((err : BusinessError, imageInfo : image.ImageInfo) => {
        if (imageInfo == undefined) {
            console.error("Failed to obtain the image pixel map information.");
            return;
        }
        if (imageInfo.size.height == 4 && imageInfo.size.width == 6) {
            console.log("Succeeded in obtaining the image pixel map information.");
        }
    })
}
```

### getBytesNumberPerRow<sup>11+</sup>

getBytesNumberPerRow(): number

获取图像像素每行字节数。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的行字节数。 |

**示例：**

```ts
let rowCount : number = pixelMap.getBytesNumberPerRow();
```

### getPixelBytesNumber<sup>11+</sup>

getPixelBytesNumber(): number

获取图像像素的总字节数。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的总字节数。 |

**示例：**

```ts
let pixelBytesNumber : number = pixelMap.getPixelBytesNumber();
```

### getDensity<sup>11+</sup>

getDensity():number

获取当前图像像素的密度。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明            |
| ------ | --------------- |
| number | 图像像素的密度。|

**示例：**

```ts
let getDensity : number = pixelMap.getDensity();
```

### opacity<sup>11+</sup>

opacity(rate: number, callback: AsyncCallback\<void>): void

通过设置透明比率来让PixelMap达到对应的透明效果，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | 是   | 透明比率的值。   |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let rate : number = 0.5;
    pixelMap.opacity(rate, (err : BusinessError) => {
        if (err) {
            console.error("Failed to set opacity.");
            return;
        } else {
            console.log("Succeeded in setting opacity.");
        }
    })
}
```

### opacity<sup>11+</sup>

opacity(rate: number): Promise\<void>

通过设置透明比率来让PixelMap达到对应的透明效果，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | 是   | 透明比率的值。|

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let rate : number = 0.5;
    await pixelMap.opacity(rate).then(() => {
        console.log('Sucessed in setting opacity.');
    }).catch((err : BusinessError) => {
        console.error('Failed to set opacity.');
    })
}
```

### createAlphaPixelmap<sup>11+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的pixelmap，可用于阴影效果，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                        |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise实例，返回pixelmap。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    await pixelMap.createAlphaPixelmap().then((alphaPixelMap : image.PixelMap) => {
        console.log('Succeeded in creating alpha pixelmap.');
    }).catch((error : BusinessError) => {
        console.error('Failed to create alpha pixelmap.');
    })
}
```

### createAlphaPixelmap<sup>11+</sup>

createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的pixelmap，可用于阴影效果，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                     |
| -------- | ------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)> | 是   | 获取回调，异步返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    pixelMap.createAlphaPixelmap((err : BusinessError, alphaPixelMap : image.PixelMap) => {
        if (alphaPixelMap == undefined) {
            console.error('Failed to obtain new pixel map.');
            return;
        } else {
            console.info('Succeed in obtaining new pixel map.');
        }
    })
}
```

### scale<sup>11+</sup>

scale(x: number, y: number, callback: AsyncCallback\<void>): void

根据输入的宽高对图片进行缩放，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | 是   | 宽度的缩放倍数。|
| y        | number               | 是   | 高度的缩放倍数。|
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。  |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let scaleX : number = 2.0;
    let scaleY : number = 1.0;
    pixelMap.scale(scaleX, scaleY, (err : BusinessError) => {
        if (err) {
            console.error("Failed to scale pixelmap.");
            return;
        } else {
            console.log("Succeeded in scaling pixelmap.");
        }
    })
}
```

### scale<sup>11+</sup>

scale(x: number, y: number): Promise\<void>

根据输入的宽高对图片进行缩放，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let scaleX : number = 2.0;
    let scaleY : number = 1.0;
    await pixelMap.scale(scaleX, scaleY).then(() => {
        console.log('Sucessed in scaling pixelmap.');
    }).catch((err : BusinessError) => {
        console.error('Failed to scale pixelmap.');
    })
}
```

### translate<sup>11+</sup>

translate(x: number, y: number, callback: AsyncCallback\<void>): void

根据输入的坐标对图片进行位置变换，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| x        | number               | 是   | 区域横坐标。                  |
| y        | number               | 是   | 区域纵坐标。                  |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。|

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let translateX : number = 50.0;
    let translateY : number = 10.0;
    pixelMap.translate(translateX, translateY, (err : BusinessError) => {
        if (err) {
            console.error("Failed to translate pixelmap.");
            return;
        } else {
            console.log("Succeeded in translating pixelmap.");
        }
    })
}
```

### translate<sup>11+</sup>

translate(x: number, y: number): Promise\<void>

根据输入的坐标对图片进行位置变换，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明        |
| ------ | ------ | ---- | ----------- |
| x      | number | 是   | 区域横坐标。|
| y      | number | 是   | 区域纵坐标。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let translateX : number = 50.0;
    let translateY : number = 10.0;
    await pixelMap.translate(translateX, translateY).then(() => {
        console.log('Sucessed in translating pixelmap.');
    }).catch((err : BusinessError) => {
        console.error('Failed to translate pixelmap.');
    })
}
```

### rotate<sup>11+</sup>

rotate(angle: number, callback: AsyncCallback\<void>): void

根据输入的角度对图片进行旋转，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | 是   | 图片旋转的角度。              |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。|

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let angle : number = 90.0;
    pixelMap.rotate(angle, (err : BusinessError) => {
        if (err != undefined) {
            console.error("Failed to rotate pixelmap.");
            return;
        } else {
            console.log("Succeeded in rotating pixelmap.");
        }
    })
}
```

### rotate<sup>11+</sup>

rotate(angle: number): Promise\<void>

根据输入的角度对图片进行旋转，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                          |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | 是   | 图片旋转的角度。              |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let angle : number = 90.0;
    await pixelMap.rotate(angle).then(() => {
        console.log('Sucessed in rotating pixelmap.');
    }).catch((err : BusinessError) => {
        console.error('Failed to rotate pixelmap.');
    })
}
```

### flip<sup>11+</sup>

flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void

根据输入的条件对图片进行翻转，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                          |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | 是   | 水平翻转。                    |
| vertical   | boolean              | 是   | 垂直翻转。                    |
| callback   | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。|

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let horizontal : boolean = true;
    let vertical : boolean = false;
    pixelMap.flip(horizontal, vertical, (err : BusinessError) => {
        if (err != undefined) {
            console.error("Failed to flip pixelmap.");
            return;
        } else {
            console.log("Succeeded in flipping pixelmap.");
        }
    })
}
```

### flip<sup>11+</sup>

flip(horizontal: boolean, vertical: boolean): Promise\<void>

根据输入的条件对图片进行翻转，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型    | 必填 | 说明      |
| ---------- | ------- | ---- | --------- |
| horizontal | boolean | 是   | 水平翻转。|
| vertical   | boolean | 是   | 垂直翻转。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let horizontal : boolean = true;
    let vertical : boolean = false;
    await pixelMap.flip(horizontal, vertical).then(() => {
        console.log('Sucessed in flipping pixelmap.');
    }).catch((err : BusinessError) => {
        console.error('Failed to flip pixelmap.');
    })
}
```

### crop<sup>11+</sup>

crop(region: Region, callback: AsyncCallback\<void>): void

根据输入的尺寸对图片进行裁剪，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](#region7)   | 是   | 裁剪的尺寸。                  |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。|

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let region : image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
    pixelMap.crop(region, (err : BusinessError) => {
        if (err != undefined) {
            console.error("Failed to crop pixelmap.");
            return;
        } else {
            console.log("Succeeded in cropping pixelmap.");
        }
    })
}
```

### crop<sup>11+</sup>

crop(region: Region): Promise\<void>

根据输入的尺寸对图片进行裁剪，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明        |
| ------ | ------------------ | ---- | ----------- |
| region | [Region](#region7) | 是   | 裁剪的尺寸。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
async function Demo() {
    let region : image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
    await pixelMap.crop(region).then(() => {
        console.log('Sucessed in cropping pixelmap.');
    }).catch((err : BusinessError) => {
        console.error('Failed to crop pixelmap.');
    });
}
```

## image.createImageSource

createImageSource(uri: string): ImageSource

通过传入的uri创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型   | 必填 | 说明                               |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | 是   | 图片路径，当前仅支持应用沙箱路径。</br>当前支持格式有：.jpg .png .gif .bmp .webp RAW [SVG<sup>10+</sup>](#svg标签说明) .ico<sup>11+</sup>。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
const context : Context = getContext(this);
const path : string = context.cacheDir + "/test.jpg";
const imageSourceApi : image.ImageSource = image.createImageSource(path);
```

## image.createImageSource<sup>9+</sup>

createImageSource(uri: string, options: SourceOptions): ImageSource

通过传入的uri创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| uri     | string                          | 是   | 图片路径，当前仅支持应用沙箱路径。</br>当前支持格式有：.jpg .png .gif .bmp .webp RAW [SVG<sup>10+</sup>](#svg标签说明) .ico<sup>11+</sup>。 |
| options | [SourceOptions](#sourceoptions9) | 是   | 图片属性，包括图片序号与默认属性值。|

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
let sourceOptions : image.SourceOptions = { sourceDensity: 120 };
let imageSource : image.ImageSource = image.createImageSource('test.png', sourceOptions);
```

## image.createImageSource<sup>7+</sup>

createImageSource(fd: number): ImageSource

通过传入文件描述符来创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型   | 必填 | 说明          |
| ------ | ------ | ---- | ------------- |
| fd     | number | 是   | 文件描述符fd。|

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
const imageSourceApi : image.ImageSource = image.createImageSource(0);
```

## image.createImageSource<sup>9+</sup>

createImageSource(fd: number, options: SourceOptions): ImageSource

通过传入文件描述符来创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| fd      | number                          | 是   | 文件描述符fd。                      |
| options | [SourceOptions](#sourceoptions9) | 是   | 图片属性，包括图片序号与默认属性值。|

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
let sourceOptions : image.SourceOptions = { sourceDensity: 120 };
const imageSourceApi : image.ImageSource = image.createImageSource(0, sourceOptions);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer): ImageSource

通过缓冲区创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型        | 必填 | 说明             |
| ------ | ----------- | ---- | ---------------- |
| buf    | ArrayBuffer | 是   | 图像缓冲区数组。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |


**示例：**

```ts
const buf : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
const imageSourceApi : image.ImageSource = image.createImageSource(buf);
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource

通过缓冲区创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型                             | 必填 | 说明                                 |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| buf    | ArrayBuffer                      | 是   | 图像缓冲区数组。                     |
| options | [SourceOptions](#sourceoptions9) | 是   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
const data : ArrayBuffer= new ArrayBuffer(112);
let sourceOptions : image.SourceOptions = { sourceDensity: 120 };
const imageSourceApi : image.ImageSource = image.createImageSource(data, sourceOptions);
```

## image.createImageSource<sup>11+</sup>

createImageSource(rawfile: resourceManager.RawFileDescriptor, options?: SourceOptions): ImageSource

通过图像资源文件的RawFileDescriptor创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型                             | 必填 | 说明                                 |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| rawfile | [resourceManager.RawFileDescriptor](js-apis-resource-manager.md#rawfiledescriptor8) | 是 | 图像资源文件的RawFileDescriptor。 |
| options | [SourceOptions](#sourceoptions9) | 否 | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
import resourceManager from '@ohos.resourceManager';

const context : Context = getContext(this);
// 获取resourceManager资源管理器
const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor : resourceManager.RawFileDescriptor) => {
    const imageSourceApi: image.ImageSource = image.createImageSource(rawFileDescriptor);
}).catch((error : BusinessError) => {
    console.error(`Failed to get RawFileDescriptor.code is ${error.code}, message is ${error.message}`);
})
```

## ImageSource

图片源类，用于获取图片相关信息。在调用ImageSource的方法前，需要先通过[createImageSource](#imagecreateimagesource)构建一个ImageSource实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称             | 类型           | 可读 | 可写 | 说明                                                         |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | 是   | 否   | 支持的图片格式，包括：png，jpeg，bmp，gif，webp，RAW。 |

### getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

获取指定序号的图片信息，使用callback形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                     |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | 是   | 创建图片源时的序号。                     |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | 是   | 获取图片信息回调，异步返回图片信息对象。 |

**示例：**

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

获取图片信息，使用callback形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                     |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](#imageinfo)> | 是   | 获取图片信息回调，异步返回图片信息对象。 |

**示例：**

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

获取图片信息，使用Promise形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名| 类型   | 必填 | 说明                                  |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | 否   | 创建图片源时的序号，不选择时默认为0。 |

**返回值：**

| 类型                             | 说明                   |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](#imageinfo)> | Promise实例，用于异步返回获取到的图片信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.getImageInfo(0)
    .then((imageInfo : image.ImageInfo) => {
		console.log('Succeeded in obtaining the image information.');
	}).catch((error : BusinessError) => {
		console.error('Failed to obtain the image information.');
	})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

通过图片解码参数创建PixelMap对象。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                 | 必填 | 说明       |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [DecodingOptions](#decodingoptions7) | 否   | 解码参数。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise实例，用于异步返回创建结果。 |

**示例：**

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

通过默认参数创建PixelMap对象，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | 是   | 通过回调返回PixelMap对象。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
imageSourceApi.createPixelMap((err : BusinessError, pixelMap : image.PixelMap) => {
    if (err != undefined) {
        console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
    } else {
        console.info('Succeeded in creating pixelMap object.');
    }
})
```

### createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

通过图片解码参数创建PixelMap对象。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | 是   | 解码参数。                 |
| callback | AsyncCallback<[PixelMap](#pixelmap7)> | 是   | 通过回调返回PixelMap对象。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
let decodingOptions : image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 1, height: 2 },
    rotate: 10,
    index: 0
};
imageSourceApi.createPixelMap(decodingOptions, (err : BusinessError, pixelMap : image.PixelMap) => { 
    if (err != undefined) {
        console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
    } else {
        console.log('Succeeded in creating pixelMap object.');
    }
})
```

## image.createImagePacker

createImagePacker(): ImagePacker

创建ImagePacker实例。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**返回值：**

| 类型                        | 说明                  |
| --------------------------- | --------------------- |
| [ImagePacker](#imagepacker) | 返回ImagePacker实例。 |

**示例：**

```ts
const imagePackerApi : image.ImagePacker = image.createImagePacker();
```

## ImagePacker

图片打包器类，用于图片压缩和打包。在调用ImagePacker的方法前，需要先通过[createImagePacker](#imagecreateimagepacker)构建一个ImagePacker实例，当前支持格式有：jpeg、webp、png。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称             | 类型           | 可读 | 可写 | 说明                       |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | 是   | 否   | 图片打包支持的格式 jpeg、webp、png。 |

### packing

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

图片压缩或重新打包，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                               | 必填 | 说明                               |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](#imagesource)        | 是   | 打包的图片源。                     |
| option   | [PackingOption](#packingoption)    | 是   | 设置打包参数。                      |
| callback | AsyncCallback\<ArrayBuffer>        | 是   | 获取图片打包回调，返回打包后数据。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const imageSourceApi : image.ImageSource = image.createImageSource(0);
let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 };
imagePackerApi.packing(imageSourceApi, packOpts, (err : BusinessError, data : ArrayBuffer) => {
    if(err) {
        console.error('packing failed.');
    } else {
        console.log('packing succeeded.');
    }
})
```

### packing

packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>

图片压缩或重新打包，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](#imagesource)     | 是   | 打包的图片源。 |
| option | [PackingOption](#packingoption) | 是   | 设置打包参数。 |

**返回值：**

| 类型                         | 说明                                          |
| ---------------------------- | --------------------------------------------- |
| Promise\<ArrayBuffer>        | Promise实例，用于异步获取压缩或打包后的数据。 |

**示例：**

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

图片压缩或重新打包，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                            | 必填 | 说明                               |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [PixelMap](#pixelmap7)           | 是   | 打包的PixelMap资源。               |
| option   | [PackingOption](#packingoption) | 是   | 设置打包参数。                     |
| callback | AsyncCallback\<ArrayBuffer>     | 是   | 获取图片打包回调，返回打包后数据。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const imageSourceApi : image.ImageSource = image.createImageSource(0);
imageSourceApi.createPixelMap().then((pixelMap : image.PixelMap) => {
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

图片压缩或重新打包，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明               |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](#pixelmap7)           | 是   | 打包的PixelMap源。 |
| option | [PackingOption](#packingoption) | 是   | 设置打包参数。     |

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise实例，用于异步获取压缩或打包后的数据。|

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const imageSourceApi : image.ImageSource = image.createImageSource(0);
imageSourceApi.createPixelMap().then((pixelMap : image.PixelMap) => {
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

## ImageInfo

表示图片信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 可读 | 可写 | 说明       |
| ---- | ------------- | ---- | ---- | ---------- |
| size | [Size](#size) | 是   | 是   | 图片大小。 |
| density<sup>9+</sup> | number | 是   | 是   | 像素密度，单位为ppi。 |

## Size

表示图片尺寸。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型   | 可读 | 可写 | 说明           |
| ------ | ------ | ---- | ---- | -------------- |
| height | number | 是   | 是   | 输出图片的高。 |
| width  | number | 是   | 是   | 输出图片的宽。 |


## SourceOptions<sup>9+</sup>

ImageSource的初始化选项。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型                               | 可读 | 可写 | 说明               |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| sourceDensity     | number                             | 是   | 是   | ImageSource的密度。|
| sourceSize        | [Size](#size)                      | 是   | 是   | 图像像素大小。     |


## DecodingOptions<sup>7+</sup>

图像解码设置选项。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称               | 类型                               | 可读 | 可写 | 说明             |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | 是   | 是   | 缩略图采样大小，当前只能取1。 |
| rotate             | number                             | 是   | 是   | 旋转角度。       |
| editable           | boolean                            | 是   | 是   | 是否可编辑。当取值为false时，图片不可二次编辑，如crop等操作将失败。  |
| desiredSize        | [Size](#size)                      | 是   | 是   | 期望输出大小。   |
| index              | number                             | 是   | 是   | 解码图片序号。   |
| fitDensity<sup>9+</sup> | number                        | 是   | 是   | 图像像素密度，单位为ppi。   |


## PackingOption

表示图片打包选项。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称    | 类型   | 可读 | 可写 | 说明                                                |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | 是   | 是   | 目标格式。</br>当前只支持jpg、webp 和 png。 |
| quality | number | 是   | 是   | JPEG编码中设定输出图片质量的参数，取值范围为0-100。 |
| bufferSize<sup>9+</sup> | number | 是   | 是   | 接收编码数据的缓冲区大小，单位为Byte。默认为10MB。bufferSize需大于编码后图片大小。 |


## 补充说明
### SVG标签说明

从API version 10开始支持SVG标签，使用版本为(SVG) 1.1，当前支持的标签列表有：
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