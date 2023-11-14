# @ohos.multimedia.image (图片处理)

本模块提供图片处理效果，包括通过属性创建PixelMap、读取图像像素数据、读取区域内的图片数据等。

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import image from '@ohos.multimedia.image';
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>

通过属性创建PixelMap，默认采用BGRA_8888格式处理数据，通过Promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | 是   | BGRA_8888格式的颜色数组。                                        |
| options | [InitializationOptions](#initializationoptions8) | 是   | 创建像素的属性，包括透明度，尺寸，缩略值，像素格式和是否可编辑。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | 返回Pixelmap。<br>当创建的pixelmap大小超过原图大小时，返回原图pixelmap大小。|

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap : image.PixelMap) => {
  console.log('Succeeded in creating pixelmap.');
}).catch((error : BusinessError) => {
  console.error('Failed to create pixelmap.');
})
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void

通过属性创建PixelMap，默认采用BGRA_8888格式处理数据，通过回调函数返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | 是   | BGRA_8888格式的颜色数组。  |
| options  | [InitializationOptions](#initializationoptions8) | 是   | 属性。                     |
| callback | AsyncCallback\<[PixelMap](#pixelmap7)>           | 是   | 通过回调返回PixelMap对象。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (error : BusinessError, pixelMap : image.PixelMap) => {
    if(error) {
        console.log('Failed to create pixelmap.');
    } else {
        console.log('Succeeded in creating pixelmap.');
    }
})
```

## image.createPixelMapFromParcel<sup>11+</sup>

createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap

从MessageSequence中获取PixelMap。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](js-apis-rpc.md#messagesequence9) | 是   | 保存有PixelMap信息的MessageSequence。      |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap7) | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
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

**示例：**

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
     // 序列化
     let parcelable : MySequence = new MySequence(pixelMap);
     let data : rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);

     // 反序列化 rpc获取到data
     let ret : MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);

     // 获取到pixelmap
     let unmarshPixelmap = ret.pixel_map;
   }
}
```

## PixelMap<sup>7+</sup>

图像像素类，用于读取或写入图像数据以及获取图像信息。在调用PixelMap的方法前，需要先通过createPixelMap创建一个PixelMap实例。目前pixelmap序列化大小最大128MB，超过会送显失败。大小计算方式为(宽\*高\*每像素占用字节数)。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称       | 类型    | 可读 | 可写 | 说明                       |
| ---------- | ------- | ---- | ---- | -------------------------- |
| isEditable | boolean | 是   | 否   | 设定是否图像像素可被编辑。 |

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

读取图像像素数据，结果写入ArrayBuffer里，使用Promise形式返回。指定BGRA_8888格式创建pixelmap，读取的像素数据与原数据保持一致。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                                                  |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由getPixelBytesNumber接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const readBuffer : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
pixelMap.readPixelsToBuffer(readBuffer).then(() => {
    console.log('Succeeded in reading image pixel data.');  //符合条件则进入 
}).catch((error : BusinessError) => {
    console.error('Failed to read image pixel data.');  //不符合条件则进入
})
```

### readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

读取图像像素数据，结果写入ArrayBuffer里，使用callback形式返回。指定BGRA_8888格式创建pixelmap，读取的像素数据与原数据保持一致。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由getPixelBytesNumber接口获取。 |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。                                                                        |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const readBuffer : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
pixelMap.readPixelsToBuffer(readBuffer, (err : BusinessError, res : void) => {
    if(err) {
        console.error('Failed to read image pixel data.');  //不符合条件则进入
    } else {
        console.log('Succeeded in reading image pixel data.');  //符合条件则进入
    }
})
```

### readPixels<sup>7+</sup>

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
const area : image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
}
pixelMap.readPixels(area).then(() => {
    console.log('Succeeded in reading the image data in the area.'); //符合条件则进入
}).catch((error : BusinessError) => {
    console.error('Failed to read the image data in the area.'); //不符合条件则进入
})
```

### readPixels<sup>7+</sup>

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
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (err : BusinessError, pixelMap : image.PixelMap) => {
    if(pixelMap == undefined){
        console.info('createPixelMap failed.');
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
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts)
    .then( (pixelMap : image.PixelMap)  => {
        if (pixelMap == undefined) {
            console.info('createPixelMap failed.');
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
        })
    }).catch((error : BusinessError) => {
        console.error('error: ' + error);
    })
```

### writePixels<sup>7+</sup>

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
```

### writeBufferToPixels<sup>7+</sup>

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
});
```

### getImageInfo<sup>7+</sup>

getImageInfo(): Promise\<ImageInfo>

获取图像像素信息，使用Promise形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                              | 说明                                                        |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](#imageinfo)> | Promise实例，用于异步获取图像像素信息，失败时返回错误信息。 |

**示例：**

```ts
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
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

获取图像像素信息，使用callback形式返回获取的图像像素信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](#imageinfo)> | 是   | 获取图像像素信息回调，异步返回图像像素信息，失败时返回错误信息。 |

**示例:**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
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

获取图像像素每行字节数。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的行字节数。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base';
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (err : BusinessError, pixelMap : image.PixelMap) => {
    let rowCount : number = pixelMap.getBytesNumberPerRow();
})
```

### getPixelBytesNumber<sup>7+</sup>

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

### getDensity<sup>9+</sup>

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

### opacity<sup>9+</sup>

opacity(rate: number, callback: AsyncCallback\<void>): void

通过设置透明比率来让PixelMap达到对应的透明效果，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | 是   | 透明比率的值,取值范围：0-1。   |
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

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

通过设置透明比率来让PixelMap达到对应的透明效果，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | 是   | 透明比率的值，取值范围：0-1。|

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```ts
async function Demo() {
    await pixelMap.opacity(0.5);
}
```

### createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的pixelmap，可用于阴影效果，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                        |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap7)> | Promise实例，返回pixelmap。 |

**示例：**

```ts
async function Demo() {
    await pixelMap.createAlphaPixelmap();
}   
```

### createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的pixelmap，可用于阴影效果，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                     |
| -------- | ------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<PixelMap> | 是   | 获取回调，异步返回结果。 |

**示例：**

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

根据输入的宽高对图片进行缩放，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | 是   | 宽度的缩放值，其值为输入的倍数。|
| y        | number               | 是   | 高度的缩放值，其值为输入的倍数。|
| callback | AsyncCallback\<void> | 是   | 获取回调，失败时返回错误信息。  |

**示例：**

```ts
async function Demo() {
    await pixelMap.scale(2.0, 1.0);
}
```

### scale<sup>9+</sup>

scale(x: number, y: number): Promise\<void>

根据输入的宽高对图片进行缩放，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放值，其值为输入的倍数。|
| y      | number | 是   | 高度的缩放值，其值为输入的倍数。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
async function Demo() {
    await pixelMap.scale(2.0, 1.0);
}
```

### translate<sup>9+</sup>

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
async function Demo() {
    await pixelMap.translate(3.0, 1.0);
}
```

### translate<sup>9+</sup>

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
async function Demo() {
    await pixelMap.translate(3.0, 1.0);
}
```

### rotate<sup>9+</sup>

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
async function Demo() {
    await pixelMap.rotate(90.0);
}
```

### flip<sup>9+</sup>

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
async function Demo() {
    await pixelMap.flip(false, true);
}
```

### flip<sup>9+</sup>

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
async function Demo() {
    await pixelMap.flip(false, true);
}
```

### crop<sup>9+</sup>

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
async function Demo() {
    await pixelMap.crop({ x: 0, y: 0, size: { height: 100, width: 100 } } as image.Region);
}
```

### crop<sup>9+</sup>

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
async function Demo() {
    await pixelMap.crop({ x: 0, y: 0, size: { height: 100, width: 100 } } as image.Region);
}
```

### getColorSpace<sup>10+</sup>

getColorSpace(): colorSpaceManager.ColorSpaceManager

获取图像广色域信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                                | 说明             |
| ----------------------------------- | ---------------- |
| [colorSpaceManager.ColorSpaceManager](js-apis-colorSpaceManager.md#colorspacemanager) | 图像广色域信息。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980101| If the image data abnormal              |
| 62980103| If the image data unsupport              |
| 62980115| If the image parameter invalid             |

**示例：**

```ts
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';
async function Demo() {
    let csm : Object = pixelMap.getColorSpace();
}
```

### setColorSpace<sup>10+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void

设置图像广色域信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型                                | 必填 | 说明            |
| ---------- | ----------------------------------- | ---- | --------------- |
| colorSpace | [colorSpaceManager.ColorSpaceManager](js-apis-colorSpaceManager.md#colorspacemanager) | 是   | 图像广色域信息。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980111| If the operation invalid              |
| 62980115| If the image parameter invalid             |

**示例：**

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

将PixelMap序列化后写入MessageSequence。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](js-apis-rpc.md#messagesequence9)  | 是   | 新创建的MessageSequence。                 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | If the input parameter invalid              |
| 62980097 | If the ipc error              |

**示例：**

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
     // 序列化
     let parcelable : MySequence = new MySequence(pixelMap);
     let data : rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);


     // 反序列化 rpc获取到data
     let ret : MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);
   }
}
```

### unmarshalling<sup>10+</sup>

unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>

从MessageSequence中获取PixelMap，
如需使用同步方式创建PixelMap可使用：[createPixelMapFromParcel](#imagecreatepixelmapfromparcel11)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](js-apis-rpc.md#messagesequence9) | 是   | 保存有PixelMap信息的MessageSequence。      |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | 异步返回Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | If the input parameter invalid              |
| 62980097 | If the ipc error              |
| 62980096 | If fail to create async work            |

**示例：**

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
     // 序列化
     let parcelable : MySequence = new MySequence(pixelMap);
     let data : rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);


     // 反序列化 rpc获取到data
     let ret : MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);
   }
}
```

### release<sup>7+</sup>

release():Promise\<void>

释放PixelMap对象，使用Promise形式返回释放结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void> | Promise实例，异步返回释放结果。 |

**示例：**

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

释放PixelMap对象，使用callback形式返回释放结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | 是   | 异步返回释放结果。 |

**示例：**

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

通过传入的uri创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型   | 必填 | 说明                               |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | 是   | 图片路径，当前仅支持应用沙箱路径。</br>当前支持格式有：.jpg .png .gif .bmp .webp RAW [SVG<sup>10+</sup>](#svg标签说明)。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
//Stage模型
const context : Context = getContext(this);
const path : string = context.cacheDir + "/test.jpg";
const imageSourceApi : image.ImageSource = image.createImageSource(path);
```

```ts
//FA模型
import featureAbility from '@ohos.ability.featureAbility';

const context : featureAbility.Context = featureAbility.getContext();
const path : string = context.getCacheDir() + "/test.jpg";
const imageSourceApi : image.ImageSource = image.createImageSource(path);
```

## image.createImageSource<sup>9+</sup>

createImageSource(uri: string, options: SourceOptions): ImageSource

通过传入的uri创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| uri     | string                          | 是   | 图片路径，当前仅支持应用沙箱路径。</br>当前支持格式有：.jpg .png .gif .bmp .webp RAW [SVG<sup>10+</sup>](#svg标签说明)。 |
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

## image.createImageSource<sup>10+</sup>

createImageSource(rawFileDescriptor: resourceManager.RawFileDescriptor, options: SourceOptions): ImageSource

通过图像资源文件的RawFileDescriptor创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型                             | 必填 | 说明                                 |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| rawFileDescriptor | [resourceManager.RawFileDescriptor](js-apis-resource-manager.md#rawfiledescriptor8) | 是 | 图像资源文件的RawFileDescriptor。 |
| options | [SourceOptions](#sourceoptions9) | 是 | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

Stage模型

```ts
// Stage模型
const context : Context = getContext(this);
// 获取resourceManager资源管理器
const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
const rawFileDescriptor : resourceManager.RawFileDescriptor = await resourceMgr.getRawFd('test.jpg');
const imageSourceApi : image.ImageSource = image.createImageSource(rawFileDescriptor);
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer): ImageSource

通过缓冲区以增量的方式创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型        | 必填 | 说明      |
| ------- | ------------| ---- | ----------|
| buf     | ArrayBuffer | 是   | 增量数据。|

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| [ImageSource](#imagesource) | 返回图片源，失败时返回undefined。 |

**示例：**

```ts
const buf : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
const imageSourceIncrementalSApi : image.ImageSource = image.CreateIncrementalSource(buf);
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource

通过缓冲区以增量的方式创建图片源实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                 |
| ------- | ------------------------------- | ---- | ------------------------------------ |
| buf     | ArrayBuffer                     | 是   | 增量数据。                           |
| options | [SourceOptions](#sourceoptions9) | 否   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| [ImageSource](#imagesource) | 返回图片源，失败时返回undefined。 |

**示例：**

```ts
const buf : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
const imageSourceIncrementalSApi : image.ImageSource = image.CreateIncrementalSource(buf);
```

## ImageSource

图片源类，用于获取图片相关信息。在调用ImageSource的方法前，需要先通过createImageSource构建一个ImageSource实例。

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
import {BusinessError} from '@ohos.base'
imageSourceApi.getImageInfo(0,(error : BusinessError, imageInfo : image.ImageInfo) => { 
    if(error) {
        console.log('getImageInfo failed.');
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
import {BusinessError} from '@ohos.base'
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
| Promise<[ImageInfo](#imageinfo)> | 返回获取到的图片信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.getImageInfo(0)
    .then((imageInfo : image.ImageInfo) => {
		console.log('Succeeded in obtaining the image information.');
	}).catch((error : BusinessError) => {
		console.log('Failed to obtain the image information.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

获取图片中给定索引处图像的指定属性键的值，用Promise形式返回结果，仅支持JPEG文件，且需要包含exif信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                                 |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                               | 是   | 图片属性名。                         |
| options | [GetImagePropertyOptions](#getimagepropertyoptions7) | 否   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型             | 说明                                                              |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise实例，用于异步获取图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```ts
imageSourceApi.getImageProperty("BitsPerSample")
    .then((data : string) => {
		console.log('Succeeded in getting the value of the specified attribute key of the image.');
	})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

获取图片中给定索引处图像的指定属性键的值，用callback形式返回结果，仅支持JPEG文件，且需要包含exif信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | 是   | 图片属性名。                                                 |
| callback | AsyncCallback\<string> | 是   | 获取图片属性回调，返回图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.getImageProperty("BitsPerSample",(error : BusinessError, data : string) => { 
    if(error) {
        console.log('Failed to get the value of the specified attribute key of the image.');
    } else {
        console.log('Succeeded in getting the value of the specified attribute key of the image.');
    }
})
```

### getImageProperty<sup>7+</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

获取图片指定属性键的值，callback形式返回结果，仅支持JPEG文件，且需要包含exif信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                          |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------- |
| key      | string                                               | 是   | 图片属性名。                                                  |
| options  | [GetImagePropertyOptions](#getimagepropertyoptions7) | 是   | 图片属性，包括图片序号与默认属性值。                          |
| callback | AsyncCallback\<string>                               | 是   | 获取图片属性回调，返回图片属性值，如获取失败则返回属性默认值。|

**示例：**

```ts
import {BusinessError} from '@ohos.base'
let property : image.GetImagePropertyOptions = { index: 0, defaultValue: '9999' }
imageSourceApi.getImageProperty("BitsPerSample",property,(error : BusinessError, data : string) => { 
    if(error) {
        console.log('Failed to get the value of the specified attribute key of the image.');
    } else {
        console.log('Succeeded in getting the value of the specified attribute key of the image.');
    }
})
```

### modifyImageProperty<sup>9+</sup>

modifyImageProperty(key: string, value: string): Promise\<void>

通过指定的键修改图片属性的值，使用Promise形式返回结果，仅支持JPEG文件，且需要包含exif信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| key     | string | 是   | 图片属性名。 |
| value   | string | 是   | 属性值。     |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
imageSourceApi.modifyImageProperty("ImageWidth", "120").then(() => {
    imageSourceApi.getImageProperty("ImageWidth").then((width : string) => {
        console.info(`ImageWidth is :${width}`);
    })
})
```

### modifyImageProperty<sup>9+</sup>

modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void

通过指定的键修改图片属性的值，callback形式返回结果，仅支持JPEG文件，且需要包含exif信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                | 必填 | 说明                           |
| -------- | ------------------- | ---- | ------------------------------ |
| key      | string              | 是   | 图片属性名。                   |
| value    | string              | 是   | 属性值。                       |
| callback | AsyncCallback\<void> | 是   | 修改属性值，callback返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.modifyImageProperty("ImageWidth", "120",(err : BusinessError) => {
    if (err != undefined) {
        console.info('modifyImageProperty Failed');
    } else {
        console.info('modifyImageProperty Succeeded');
    }
})
```

### updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number): Promise\<void>

更新增量数据，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型        | 必填 | 说明         |
| ---------- | ----------- | ---- | ------------ |
| buf        | ArrayBuffer | 是   | 增量数据。   |
| isFinished | boolean     | 是   | 是否更新完。 |
| value      | number      | 是   | 偏移量。     |
| length     | number      | 是   | 数组长。     |

**返回值：**

| 类型           | 说明                       |
| -------------- | -------------------------- |
| Promise\<void> | Promise实例，异步返回结果。|

**示例：**

```ts
import {BusinessError} from '@ohos.base'
const array : ArrayBuffer = new ArrayBuffer(100);
imageSourceApi.updateData(array, false, 0, 10).then(() => {
    console.info('Succeeded in updating data.');
}).catch((err: BusinessError) => {
    console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
})
```


### updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, value: number, length: number, callback: AsyncCallback\<void>): void

更新增量数据，callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型                | 必填 | 说明                 |
| ---------- | ------------------- | ---- | -------------------- |
| buf        | ArrayBuffer         | 是   | 增量数据。           |
| isFinished | boolean             | 是   | 是否更新完。         |
| value      | number              | 是   | 偏移量。             |
| length     | number              | 是   | 数组长。             |
| callback   | AsyncCallback\<void> | 是   | 回调表示成功或失败。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
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

通过图片解码参数创建PixelMap对象。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                 | 必填 | 说明       |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [DecodingOptions](#decodingoptions7) | 否   | 解码参数。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap7)> | 异步返回Promise对象。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.createPixelMap().then((pixelmap : image.PixelMap) => {
    console.log('Succeeded in creating pixelmap object through image decoding parameters.');
}).catch((error : BusinessError) => {
    console.log('Failed to create pixelmap object through image decoding parameters.');
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
import {BusinessError} from '@ohos.base'
imageSourceApi.createPixelMap((err : BusinessError, pixelmap : image.PixelMap) => {
    console.info('Succeeded in creating pixelmap object.');
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
import {BusinessError} from '@ohos.base'
let decodingOptions : image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 1, height: 2 },
    rotate: 10,
    desiredPixelFormat: 3,
    desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 },
    index: 0
};
imageSourceApi.createPixelMap(decodingOptions, (err : BusinessError, pixelmap : image.PixelMap) => { 
    console.log('Succeeded in creating pixelmap object.');
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options?: DecodingOptions): Promise<Array\<PixelMap>>;

通过图片解码参数创建PixelMap数组。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](#decodingoptions7)  | 否   | 解码参数。                 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise<Array<[PixelMap](#pixelmap7)>> | 异步返回PixeMap数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980103| If the image data unsupport             |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980118| If the image plugin create failed             |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
let decodeOpts: image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 198, height: 202 },
    rotate: 0,
    desiredPixelFormat: 3,
    index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts).then((pixelmaplist: Array<image.PixelMap>) => {
    console.log('Succeeded in creating pixelmaplist object.');
}).catch((err: BusinessError) => {
    console.error(`Failed to create pixelmaplist object.code is ${err.code},message is ${err.message}`);
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(callback: AsyncCallback<Array\<PixelMap>>): void

通过默认参数创建PixelMap数组，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | 是   | 通过回调返回PixelMap数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980103| If the image data unsupport             |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980118| If the image plugin create failed             |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.createPixelMapList((err: BusinessError, pixelmaplist: Array<image.PixelMap>) => {
    if (err != undefined) {
        console.error(`Failed to create pixelmaplist object.code is ${err.code},message is ${err.message}`);
    } else {
        console.info('Succeeded in creating pixelmaplist object.');
    }
})
```

### createPixelMapList<sup>10+</sup>

createPixelMapList(options: DecodingOptions, callback: AsyncCallback<Array\<PixelMap>>): void;

通过图片解码参数创建PixelMap数组，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| options | [DecodingOptions](#decodingoptions7) | 是 | 解码参数。 |
| callback | AsyncCallback<Array<[PixelMap](#pixelmap7)>> | 是   | 通过回调返回PixelMap数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980103| If the image data unsupport             |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980118| If the image plugin create failed             |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
let decodeOpts : image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 198, height: 202 },
    rotate: 0,
    desiredPixelFormat: 3,
    index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts, (err: BusinessError, pixelmaplist: Array<image.PixelMap>) => {
    if (err != undefined) {
        console.error(`Failed to create pixelmaplist object.code is ${err.code},message is ${err.message}`);
    } else {
        console.log('Succeeded in creating pixelmaplist object.');
    }
})
```

### getDelayTimeList<sup>10+</sup>

getDelayTimeList(callback: AsyncCallback<Array\<number>>): void;

获取图像延迟时间数组，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback<Array\<number>> | 是   | 通过回调返回延迟时间数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.getDelayTimeList((err: BusinessError, delayTimes: Array<number>) => {
    if (err != undefined) {
        console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
    } else {
        console.log('Succeeded in delayTimes object.');
    }
})
```

### getDelayTimeList<sup>10+</sup>

getDelayTimeList(): Promise<Array\<number>>;

获取图像延迟时间数组，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<Array\<number>> | Promise实例，异步返回延迟时间数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**示例：**

```ts
imageSourceApi.getDelayTimeList().then((delayTimes : Array<number>) => {
    console.log('Succeeded in delayTimes object.');
}).catch((err: BusinessError) => {
    console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
})
```

### getFrameCount<sup>10+</sup>

getFrameCount(callback: AsyncCallback\<number>): void;

获取图像帧数，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<number> | 是   | 通过回调返回图像帧数。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.getFrameCount((err: BusinessError, frameCount: number) => {
    if (err != undefined) {
        console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
    } else {
        console.log('Succeeded in getting frame count.');
    }
})
```

### getFrameCount<sup>10+</sup>

getFrameCount(): Promise\<number>;

获取图像帧数，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<number> | Promise实例，异步返回图像帧数。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](../errorcodes/errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| If the operation failed              |
| 62980110| If the image source data error              |
| 62980111| If the image source data incomplete            |
| 62980113| If the image format unknown            |
| 62980116| If the image decode failed            |
| 62980118| If the image plugin create failed             |
| 62980122| If the image decode head abnormal             |

**示例：**

```ts
imageSourceApi.getFrameCount().then((frameCount: number) => {
    console.log('Succeeded in getting frame count.');
}).catch((err : BusinessError) => {
    console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
})
```

### release

release(callback: AsyncCallback\<void>): void

释放图片源实例，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | 是   | 资源释放回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.release((err : BusinessError) => { 
    if (err != undefined) {
        console.log('Failed to release the image source instance.');
    } else {
        console.log('Succeeded in releasing the image source instance.');
    }
})
```

### release

release(): Promise\<void>

释放图片源实例，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imageSourceApi.release().then(()=>{
    console.log('Succeeded in releasing the image source instance.');
}).catch((error : BusinessError) => {
    console.log('Failed to release the image source instance.');
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

图片打包器类，用于图片压缩和打包。在调用ImagePacker的方法前，需要先通过createImagePacker构建一个ImagePacker实例，当前支持格式有：jpeg webp png。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称             | 类型           | 可读 | 可写 | 说明                       |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | 是   | 否   | 图片打包支持的格式 jpeg webp png。 |

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
import {BusinessError} from '@ohos.base'
const imageSourceApi : image.ImageSource = image.createImageSource(0);
let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 };
imagePackerApi.packing(imageSourceApi, packOpts, (err : BusinessError, data : ArrayBuffer) => {})
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
import {BusinessError} from '@ohos.base'
const imageSourceApi : image.ImageSource = image.createImageSource(0);
let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 }
imagePackerApi.packing(imageSourceApi, packOpts)
    .then( (data : ArrayBuffer) => {
        console.log('packing succeeded.');
	}).catch((error : BusinessError) => {
	    console.log('packing failed.');
	})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

图片压缩或重新打包，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                            | 必填 | 说明                               |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [PixelMap](#pixelmap)           | 是   | 打包的PixelMap资源。               |
| option   | [PackingOption](#packingoption) | 是   | 设置打包参数。                     |
| callback | AsyncCallback\<ArrayBuffer>     | 是   | 获取图片打包回调，返回打包后数据。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelmap : image.PixelMap) => {
    let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 }
    imagePackerApi.packing(pixelmap, packOpts, (err : BusinessError, data : ArrayBuffer) => { 
        console.log('Succeeded in packing the image.');
    })
})
```

### packing<sup>8+</sup>

packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>

图片压缩或重新打包，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明               |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](#pixelmap)           | 是   | 打包的PixelMap源。 |
| option | [PackingOption](#packingoption) | 是   | 设置打包参数。     |

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise实例，用于异步获取压缩或打包后的数据。|

**示例：**

```ts
import {BusinessError} from '@ohos.base'
const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4
let bufferArr : Uint8Array = new Uint8Array(color);
let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelmap : image.PixelMap) => {
    let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 }
    imagePackerApi.packing(pixelmap, packOpts)
        .then( (data : ArrayBuffer) => {
            console.log('Succeeded in packing the image.');
        }).catch((error : BusinessError) => {
            console.log('Failed to pack the image..');
        })
})
```

### release

release(callback: AsyncCallback\<void>): void

释放图片打包实例，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | 是   | 释放回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imagePackerApi.release((err : BusinessError)=>{ 
    if (err != undefined) {
        console.log('Failed to release image packaging.'); 
    } else {
        console.log('Succeeded in releasing image packaging.');
    }
})
```

### release

release(): Promise\<void>

释放图片打包实例，使用Promise形式返回释放结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**返回值：**

| 类型           | 说明                                                   |
| -------------- | ------------------------------------------------------ |
| Promise\<void> | Promise实例，用于异步获取释放结果，失败时返回错误信息。|

**示例：**

```ts
import {BusinessError} from '@ohos.base'
imagePackerApi.release().then(()=>{
    console.log('Succeeded in releasing image packaging.');
}).catch((error : BusinessError)=>{ 
    console.log('Failed to release image packaging.'); 
}) 
```

## image.createImageReceiver<sup>9+</sup>

createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver

通过宽、高、图片格式、容量创建ImageReceiver实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| width    | number | 是   | 图像的默认宽度。       |
| height   | number | 是   | 图像的默认高度。       |
| format   | number | 是   | 图像格式，取值为[ImageFormat](#imageformat9)常量（目前仅支持 ImageFormat:JPEG 和 4）。  |
| capacity | number | 是   | 同时访问的最大图像数。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver9) | 如果操作成功，则返回ImageReceiver实例。 |

**示例：**

```ts
let receiver : image.ImageReceiver = image.createImageReceiver(8192, 8, 2000, 8);
```

## ImageReceiver<sup>9+</sup>

图像接收类，用于获取组件surface id，接收最新的图片和读取下一张图片，以及释放ImageReceiver实例。

在调用以下方法前需要先创建ImageReceiver实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

| 名称     | 类型                         | 可读 | 可写 | 说明               |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| size     | [Size](#size)                | 是   | 否   | 图片大小。         |
| capacity | number                       | 是   | 否   | 同时访问的图像数。 |
| format   | [ImageFormat](#imageformat9) | 是   | 否   | 图像格式。         |

### getReceivingSurfaceId<sup>9+</sup>

getReceivingSurfaceId(callback: AsyncCallback\<string>): void

用于获取一个surface id供Camera或其他组件使用。使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                   | 必填 | 说明                       |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<string> | 是   | 回调函数，返回surface id。 |

**示例:**

```ts
import {BusinessError} from '@ohos.base'
receiver.getReceivingSurfaceId((err : BusinessError, id : string) => { 
    if(err) {
        console.log('getReceivingSurfaceId failed.');
    } else {
        console.log('getReceivingSurfaceId succeeded.');
    }
});
```

### getReceivingSurfaceId<sup>9+</sup>

getReceivingSurfaceId(): Promise\<string>

用于获取一个surface id供Camera或其他组件使用。使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<string> | 异步返回surface id。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
receiver.getReceivingSurfaceId().then( (id : string) => { 
    console.log('getReceivingSurfaceId succeeded.');
}).catch((error : BusinessError) => {
    console.log('getReceivingSurfaceId failed.');
})
```

### readLatestImage<sup>9+</sup>

readLatestImage(callback: AsyncCallback\<Image>): void

从ImageReceiver读取最新的图片，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名     | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<[Image](#image9)> | 是   | 回调函数，返回最新图像。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
receiver.readLatestImage((err : BusinessError, img : image.Image) => { 
    if(err) {
        console.log('readLatestImage failed.');
    } else {
        console.log('readLatestImage succeeded.');
    }
});
```

### readLatestImage<sup>9+</sup>

readLatestImage(): Promise\<Image>

从ImageReceiver读取最新的图片，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明               |
| ------------------------- | ------------------ |
| Promise<[Image](#image9)> | 异步返回最新图片。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
receiver.readLatestImage().then((img : image.Image) => {
    console.log('readLatestImage succeeded.');
}).catch((error : BusinessError) => {
    console.log('readLatestImage failed.');
})
```

### readNextImage<sup>9+</sup>

readNextImage(callback: AsyncCallback\<Image>): void

从ImageReceiver读取下一张图片，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                            | 必填 | 说明                       |
| -------- | ------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[Image](#image9)> | 是   | 回调函数，返回下一张图片。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
receiver.readNextImage((err : BusinessError, img : image.Image) => { 
    if(err) {
        console.log('readNextImage failed.');
    } else {
        console.log('readNextImage succeeded.');
    }
});
```

### readNextImage<sup>9+</sup>

readNextImage(): Promise\<Image>

从ImageReceiver读取下一张图片，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明                 |
| ------------------------- | -------------------- |
| Promise<[Image](#image9)> | 异步返回下一张图片。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
receiver.readNextImage().then((img : image.Image) => {
    console.log('readNextImage succeeded.');
}).catch((error : BusinessError) => {
    console.log('readNextImage failed.');
})
```

### on<sup>9+</sup>

on(type: 'imageArrival', callback: AsyncCallback\<void>): void

接收图片时注册回调。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                   |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| type     | string               | 是   | 注册事件的类型，固定为'imageArrival'，接收图片时触发。 |
| callback | AsyncCallback\<void> | 是   | 注册的事件回调。                                       |

**示例：**

```ts
receiver.on('imageArrival', () => {})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

释放ImageReceiver实例并使用回调返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回操作结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
receiver.release((err : BusinessError) => {})
```

### release<sup>9+</sup>

release(): Promise\<void>

释放ImageReceiver实例并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型           | 说明               |
| -------------- | ------------------ |
| Promise\<void> | 异步返回操作结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
receiver.release().then(() => {
    console.log('release succeeded.');
}).catch((error : BusinessError) => {
    console.log('release failed.');
})
```

## image.createImageCreator<sup>9+</sup>

createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator

通过宽、高、图片格式、容量创建ImageCreator实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| width    | number | 是   | 图像的默认宽度。       |
| height   | number | 是   | 图像的默认高度。       |
| format   | number | 是   | 图像格式，如YCBCR_422_SP，JPEG。             |
| capacity | number | 是   | 同时访问的最大图像数。 |

**返回值：**

| 类型                           | 说明                                    |
| ------------------------------ | --------------------------------------- |
| [ImageCreator](#imagecreator9) | 如果操作成功，则返回ImageCreator实例。 |

**示例：**

```ts
let creator : image.ImageCreator = image.createImageCreator(8192, 8, 4, 8);
```

## ImageCreator<sup>9+</sup>

图像创建模块，用于请求图像原生数据区域，并开放给应用编译原生图像数据的能力。
在调用以下方法前需要先创建ImageCreator实例，ImageCreator不支持多线程。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

| 名称     | 类型                         | 可读 | 可写 | 说明               |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| capacity | number                       | 是   | 否   | 同时访问的图像数。 |
| format   | [ImageFormat](#imageformat9) | 是   | 否   | 图像格式。         |

### dequeueImage<sup>9+</sup>

dequeueImage(callback: AsyncCallback\<Image>): void

从空闲队列中获取buffer图片，用于绘制UI内容，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名        | 类型                                    | 必填 | 说明                 |
| ------------- | ---------------------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<Image>                   | 是   | 回调函数，返回最新图片。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
creator.dequeueImage((err : BusinessError, img : image.Image) => {
    if (err) {
        console.info('dequeueImage failed.');
    }
    console.info('dequeueImage succeeded.');
});
```

### dequeueImage<sup>9+</sup>

dequeueImage(): Promise\<Image>

从空闲队列中获取buffer图片，用于绘制UI内容，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**返回值：**

| 类型             | 说明           |
| --------------- | ------------- |
| Promise\<Image> | 返回绘制的图像。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
creator.dequeueImage().then((img : image.Image) => {
    console.info('dequeueImage succeeded.');
}).catch((error : BusinessError) => {
    console.log('dequeueImage failed: ' + error);
})
```

### queueImage<sup>9+</sup>

queueImage(interface: Image, callback: AsyncCallback\<void>): void

将绘制好的图片放入Dirty队列，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名        | 类型                     | 必填 | 说明                 |
| ------------- | -------------------------| ---- | -------------------- |
| interface     | Image                    | 是   | 绘制好的buffer图像。 |
| callback      | AsyncCallback\<void>     | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
creator.dequeueImage().then((img : image.Image) => {
    //绘制图片
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
            console.info('queueImage failed: ' + err);
        }
        console.info('queueImage succeeded');
    })
})

```

### queueImage<sup>9+</sup>

queueImage(interface: Image): Promise\<void>

将绘制好的图片放入Dirty队列，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名          | 类型     | 必填 | 说明                |
| ------------- | --------| ---- | ------------------- |
| interface     | Image   | 是   | 绘制好的buffer图像。 |

**返回值：**

| 类型            | 说明           |
| -------------- | ------------- |
| Promise\<void> | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
creator.dequeueImage().then((img : image.Image) => {
    //绘制图片
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
        console.info('queueImage failed: ' + error);
    })
})

```

### on<sup>9+</sup>

on(type: 'imageRelease', callback: AsyncCallback\<void>): void

监听imageRelease事件，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名        | 类型                     | 必填 | 说明                 |
| ------------- | -------------------------| ---- | -------------------- |
| type          | string                   | 是   | 监听事件类型，如'imageRelease'。 |
| callback      | AsyncCallback\<void>     | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
creator.on('imageRelease', (err : BusinessError) => {
    if (err) {
        console.info('on faild' + err);
    }
    console.info('on succeeded');
})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

释放当前图像，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名           | 类型                     | 必填 | 说明                 |
| ------------- | -------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<void>     | 是   | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
creator.release((err : BusinessError) => {
    if (err) {
        console.info('release failed: ' + err);
    }
    console.info('release succeeded');
});
```
### release<sup>9+</sup>

release(): Promise\<void>

释放当前图像，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**返回值：**

| 类型            | 说明           |
| -------------- | ------------- |
| Promise\<void> | 获取回调，失败时返回错误信息。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
creator.release().then(() => {
    console.info('release succeeded');
}).catch((error : BusinessError) => {
    console.info('release failed');
})
```

## Image<sup>9+</sup>

提供基本的图像操作，包括获取图像信息、读写图像数据。调用[readNextImage](#readnextimage9)和[readLatestImage](#readlatestimage9)接口时会返回image。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称     | 类型               | 可读 | 可写 | 说明                                               |
| -------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect | [Region](#region7) | 是   | 是   | 要裁剪的图像区域。                                 |
| size     | [Size](#size)      | 是   | 否   | 图像大小。                                         |
| format   | number             | 是   | 否   | 图像格式，参考[PixelMapFormat](#pixelmapformat7)。 |

### getComponent<sup>9+</sup>

getComponent(componentType: ComponentType, callback: AsyncCallback\<Component>): void

根据图像的组件类型从图像中获取组件缓存并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                                    | 必填 | 说明                 |
| ------------- | --------------------------------------- | ---- | -------------------- |
| componentType | [ComponentType](#componenttype9)        | 是   | 图像的组件类型。     |
| callback      | AsyncCallback<[Component](#component9)> | 是   | 用于返回组件缓冲区。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
img.getComponent(4, (err : BusinessError, component : image.Component) => {
    if(err) {
        console.log('getComponent failed.');
    } else {
        console.log('getComponent succeeded.');
    }
})
```

### getComponent<sup>9+</sup>

getComponent(componentType: ComponentType): Promise\<Component>

根据图像的组件类型从图像中获取组件缓存并使用Promise方式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| componentType | [ComponentType](#componenttype9) | 是   | 图像的组件类型。 |

**返回值：**

| 类型                              | 说明                              |
| --------------------------------- | --------------------------------- |
| Promise<[Component](#component9)> | 用于返回组件缓冲区的promise实例。 |

**示例：**

```ts
img.getComponent(4).then((component : image.Component) => { })
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

释放当前图像并使用callback返回结果。

在接收另一个图像前必须先释放对应资源。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明           |
| -------- | -------------------- | ---- | -------------- |
| callback | AsyncCallback\<void> | 是   | 返回操作结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
img.release((err : BusinessError) =>{ 
    if (err != undefined) {
        console.log('Failed to release the image source instance.');
    } else {
        console.log('Succeeded in releasing the image source instance.');
    }
}) 
```

### release<sup>9+</sup>

release(): Promise\<void>

释放当前图像并使用Promise方式返回结果。

在接收另一个图像前必须先释放对应资源。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise\<void> | promise返回操作结果。 |

**示例：**

```ts
import {BusinessError} from '@ohos.base'
img.release().then(() =>{
    console.log('release succeeded.');
}).catch((error : BusinessError) => {
    console.log('release failed.');
})
```

## PositionArea<sup>7+</sup>

表示图片指定区域内的数据。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型               | 可读 | 可写 | 说明                                                         |
| ------ | ------------------ | ---- | ---- | ------------------------------------------------------------ |
| pixels | ArrayBuffer        | 是   | 否   | 像素。                                                       |
| offset | number             | 是   | 否   | 偏移量。                                                     |
| stride | number             | 是   | 否   | 像素间距，stride >= region.size.width*4。                   |
| region | [Region](#region7) | 是   | 否   | 区域，按照区域读写。写入的区域宽度加X坐标不能大于原图的宽度，写入的区域高度加Y坐标不能大于原图的高度。 |

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

## PixelMapFormat<sup>7+</sup>

枚举，图片像素格式。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | 未知格式。        |
| RGB_565                | 2      | 格式为RGB_565     |
| RGBA_8888              | 3      | 格式为RGBA_8888 |
| BGRA_8888<sup>9+</sup> | 4      | 格式为BGRA_8888 |
| RGB_888<sup>9+</sup>   | 5      | 格式为RGB_888   |
| ALPHA_8<sup>9+</sup>   | 6      | 格式为ALPHA_8   |
| RGBA_F16<sup>9+</sup>  | 7      | 格式为RGBA_F16  |
| NV21<sup>9+</sup>      | 8      | 格式为NV21      |
| NV12<sup>9+</sup>      | 9      | 格式为NV12      |

## AlphaType<sup>9+</sup>

枚举，图像的透明度类型。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称     |   值   | 说明                    |
| -------- | ------ | ----------------------- |
| UNKNOWN  | 0      | 未知透明度。            |
| OPAQUE   | 1      | 没有alpha或图片全透明。 |
| PREMUL   | 2      | RGB前乘alpha。         |
| UNPREMUL | 3      | RGB不前乘alpha。       |

## ScaleMode<sup>9+</sup>

枚举，图像的缩放模式。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称            |   值   | 说明                                               |
| --------------- | ------ | -------------------------------------------------- |
| CENTER_CROP     | 1      | 缩放图像以填充目标图像区域并居中裁剪区域外的效果。 |
| FIT_TARGET_SIZE | 0      | 图像适合目标尺寸的效果。                           |

## SourceOptions<sup>9+</sup>

ImageSource的初始化选项。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型                               | 可读 | 可写 | 说明               |
| ----------------- | ---------------------------------- | ---- | ---- | ------------------ |
| sourceDensity     | number                             | 是   | 是   | ImageSource的密度。|
| sourcePixelFormat | [PixelMapFormat](#pixelmapformat7) | 是   | 是   | 图片像素格式。     |
| sourceSize        | [Size](#size)                      | 是   | 是   | 图像像素大小。     |


## InitializationOptions<sup>8+</sup>

PixelMap的初始化选项。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称                     | 类型                               | 可读 | 可写 | 说明           |
| ------------------------ | ---------------------------------- | ---- | ---- | -------------- |
| alphaType<sup>9+</sup>   | [AlphaType](#alphatype9)           | 是   | 是   | 透明度。       |
| editable                 | boolean                            | 是   | 是   | 是否可编辑。   |
| pixelFormat              | [PixelMapFormat](#pixelmapformat7) | 是   | 是   | 像素格式。     |
| scaleMode<sup>9+</sup>   | [ScaleMode](#scalemode9)           | 是   | 是   | 缩略值。       |
| size                     | [Size](#size)                      | 是   | 是   | 创建图片大小。 |

## DecodingOptions<sup>7+</sup>

图像解码设置选项。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称               | 类型                               | 可读 | 可写 | 说明             |
| ------------------ | ---------------------------------- | ---- | ---- | ---------------- |
| sampleSize         | number                             | 是   | 是   | 缩略图采样大小，当前只能取1。 |
| rotate             | number                             | 是   | 是   | 旋转角度。       |
| editable           | boolean                            | 是   | 是   | 是否可编辑。当取值为false时，图片不可二次编辑，如crop等操作将失败。  |
| desiredSize        | [Size](#size)                      | 是   | 是   | 期望输出大小。   |
| desiredRegion      | [Region](#region7)                 | 是   | 是   | 解码区域。       |
| desiredPixelFormat | [PixelMapFormat](#pixelmapformat7) | 是   | 是   | 解码的像素格式。 |
| index              | number                             | 是   | 是   | 解码图片序号。   |
| fitDensity<sup>9+</sup> | number                        | 是   | 是   | 图像像素密度，单位为ppi。   |

## Region<sup>7+</sup>

表示区域信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 可读 | 可写 | 说明         |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | 是   | 是   | 区域大小。   |
| x    | number        | 是   | 是   | 区域横坐标。 |
| y    | number        | 是   | 是   | 区域纵坐标。 |

## PackingOption

表示图片打包选项。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称    | 类型   | 可读 | 可写 | 说明                                                |
| ------- | ------ | ---- | ---- | --------------------------------------------------- |
| format  | string | 是   | 是   | 目标格式。</br>当前只支持jpg、webp 和 png。 |
| quality | number | 是   | 是   | JPEG编码中设定输出图片质量的参数，取值范围为1-100。 |
| bufferSize<sup>9+</sup> | number | 是   | 是   | 接收编码数据的缓冲区大小，单位为Byte。默认为10MB。bufferSize需大于编码后图片大小。 |

## GetImagePropertyOptions<sup>7+</sup>

表示查询图片属性的索引。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称         | 类型   | 可读 | 可写 | 说明         |
| ------------ | ------ | ---- | ---- | ------------ |
| index        | number | 是   | 是   | 图片序号。   |
| defaultValue | string | 是   | 是   | 默认属性值。 |

## PropertyKey<sup>7+</sup>

枚举，Exif（Exchangeable image file format）图片信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              |   值                    | 说明                     |
| ----------------- | ----------------------- | ------------------------ |
| BITS_PER_SAMPLE                           | "BitsPerSample"              | 每个像素比特数。                            |
| ORIENTATION                               | "Orientation"                | 图片方向。                                  |
| IMAGE_LENGTH                              | "ImageLength"                | 图片长度。                                  |
| IMAGE_WIDTH                               | "ImageWidth"                 | 图片宽度。                                  |
| GPS_LATITUDE                              | "GPSLatitude"                | 图片纬度。                                  |
| GPS_LONGITUDE                             | "GPSLongitude"               | 图片经度。                                  |
| GPS_LATITUDE_REF                          | "GPSLatitudeRef"             | 纬度引用，例如N或S。                        |
| GPS_LONGITUDE_REF                         | "GPSLongitudeRef"            | 经度引用，例如W或E。                        |
| DATE_TIME_ORIGINAL<sup>9+</sup>           | "DateTimeOriginal"           | 拍摄时间，例如2022:09:06 15:48:00。         |
| EXPOSURE_TIME<sup>9+</sup>                | "ExposureTime"               | 曝光时间，例如1/33 sec。                    |
| SCENE_TYPE<sup>9+</sup>                   | "SceneType"                  | 拍摄场景模式，例如人像、风光、运动、夜景等。 |
| ISO_SPEED_RATINGS<sup>9+</sup>            | "ISOSpeedRatings"            | ISO感光度，例如400。                        |
| F_NUMBER<sup>9+</sup>                     | "FNumber"                    | 光圈值，例如f/1.8。                         |
| DATE_TIME<sup>10+</sup>                   | "DateTime"                   | 日期时间。                                  |
| GPS_TIME_STAMP<sup>10+</sup>              | "GPSTimeStamp"               | GPS时间戳。                                   |
| GPS_DATE_STAMP<sup>10+</sup>              | "GPSDateStamp"               | GPS日期戳。                                   |
| IMAGE_DESCRIPTION<sup>10+</sup>           | "ImageDescription"           | 图像信息描述。                                |
| MAKE<sup>10+</sup>                        | "Make"                       | 生产商。                                      |
| MODEL<sup>10+</sup>                       | "Model"                      | 设备型号。                                    |
| PHOTO_MODE<sup>10+</sup>                  | "PhotoMode "                 | 拍照模式。                                    |
| SENSITIVITY_TYPE<sup>10+</sup>            | "SensitivityType"            | 灵敏度类型。                                  |
| STANDARD_OUTPUT_SENSITIVITY<sup>10+</sup> | "StandardOutputSensitivity"  | 标准输出灵敏度。                              |
| RECOMMENDED_EXPOSURE_INDEX<sup>10+</sup>  | "RecommendedExposureIndex"   | 推荐曝光指数。                                |
| ISO_SPEED<sup>10+</sup>                   | "ISOSpeedRatings"            | ISO速度等级。                                 |
| APERTURE_VALUE<sup>10+</sup>              | "ApertureValue"              | 光圈值。                                      |
| EXPOSURE_BIAS_VALUE<sup>10+</sup>         | "ExposureBiasValue"          | 曝光偏差值。                                  |
| METERING_MODE<sup>10+</sup>               | "MeteringMode"               | 测光模式。                                    |
| LIGHT_SOURCE<sup>10+</sup>                | "LightSource"                | 光源。                                        |
| FLASH <sup>10+</sup>                      | "Flash"                      | 闪光灯,记录闪光灯状态。                       |
| FOCAL_LENGTH <sup>10+</sup>               | "FocalLength"                | 焦距。                                        |
| USER_COMMENT <sup>10+</sup>               | "UserComment"                | 用户注释。                                    |
| PIXEL_X_DIMENSION <sup>10+</sup>          | "PixelXDimension"            | 像素X尺寸。                                   |
| PIXEL_Y_DIMENSION<sup>10+</sup>           | "PixelYDimension"            | 像素Y尺寸。                                   |
| WHITE_BALANCE <sup>10+</sup>              | "WhiteBalance"               | 白平衡。                                      |
| FOCAL_LENGTH_IN_35_MM_FILM <sup>10+</sup> | "FocalLengthIn35mmFilm"      | 焦距35毫米胶片。                              |
| CAPTURE_MODE <sup>10+</sup>               | "HwMnoteCaptureMode"         | 捕获模式，当前为只读属性。                  |
| PHYSICAL_APERTURE <sup>10+</sup>          | "HwMnotePhysicalAperture"    | 物理孔径，光圈大小，当前为只读属性。        |
| ROLL_ANGLE <sup>11+</sup>                 | "HwMnoteRollAngle"           | 滚动角度，当前为只读属性。                  |
| PITCH_ANGLE<sup>11+</sup>                | "HwMnotePitchAngle"          | 俯仰角度，当前为只读属性。                  |
| SCENE_FOOD_CONF<sup>11+</sup>             | "HwMnoteSceneFoodConf"       | 拍照场景：食物，当前为只读属性。            |
| SCENE_STAGE_CONF<sup>11+</sup>           | "HwMnoteSceneStageConf"     | 拍照场景：舞台，当前为只读属性。            |
| SCENE_BLUESKY_CONF<sup>11+</sup>          | "HwMnoteSceneBlueSkyConf"    | 拍照场景：蓝天，当前为只读属性。            |
| SCENE_GREENPLANT_CONF<sup>11+</sup>       | "HwMnoteSceneGreenPlantConf" | 拍照场景：绿植，当前为只读属性。       |
| SCENE_BEACH_CONF<sup>11+</sup>            | "HwMnoteSceneBeachConf"      | 拍照场景：沙滩，当前为只读属性。            |
| SCENE_SNOW_CONF<sup>11+</sup>             | "HwMnoteSceneSnowConf"       | 拍照场景：下雪，当前为只读属性。            |
| SCENE_SUNSET_CONF<sup>11+</sup>           | "HwMnoteSceneSunsetConf"     | 拍照场景：日落，当前为只读属性。            |
| SCENE_FLOWERS_CONF<sup>11+</sup>          | "HwMnoteSceneFlowersConf"    | 拍照场景：花，当前为只读属性。              |
| SCENE_NIGHT_CONF<sup>11+</sup>            | "HwMnoteSceneNightConf"      | 拍照场景：夜晚，当前为只读属性。            |
| SCENE_TEXT_CONF<sup>11+</sup>             | "HwMnoteSceneTextConf"       | 拍照场景：文本，当前为只读属性。            |
| FACE_COUNT<sup>11+</sup>                  | "HwMnoteFaceCount"           | 人脸数量，当前为只读属性。                  |
| FOCUS_MODE<sup>11+</sup>                  | "HwMnoteFocusMode"           | 对焦模式，当前为只读属性。                  |

## ImageFormat<sup>9+</sup>

枚举，图片格式。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称         |   值   | 说明                 |
| ------------ | ------ | -------------------- |
| YCBCR_422_SP | 1000   | YCBCR422半平面格式。 |
| JPEG         | 2000   | JPEG编码格式。       |

## ComponentType<sup>9+</sup>

枚举，图像的组件类型。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

| 名称  |   值   | 说明        |
| ----- | ------ | ----------- |
| YUV_Y | 1      | 亮度信息。  |
| YUV_U | 2      | 色度信息。  |
| YUV_V | 3      | 色度信息。  |
| JPEG  | 4      | JPEG 类型。 |

## Component<sup>9+</sup>

描述图像颜色分量。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称          | 类型                             | 可读 | 可写 | 说明         |
| ------------- | -------------------------------- | ---- | ---- | ------------ |
| componentType | [ComponentType](#componenttype9) | 是   | 否   | 组件类型。   |
| rowStride     | number                           | 是   | 否   | 行距。       |
| pixelStride   | number                           | 是   | 否   | 像素间距。   |
| byteBuffer    | ArrayBuffer                      | 是   | 否   | 组件缓冲区。 |

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
