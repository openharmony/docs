# @ohos.multimedia.sendableImage (基于Sendable对象的图片处理)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

本模块基于Sendable对象，提供图片处理效果，包括通过属性创建PixelMap、读取图像像素数据、读取区域内的图片数据等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { sendableImage } from '@kit.ImageKit';
```

## sendableImage.createPixelMap

createPixelMap(colors: ArrayBuffer, options: image.InitializationOptions): Promise\<PixelMap>

通过属性创建PixelMap，默认采用BGRA_8888格式处理数据，通过Promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | 是   | 默认按照BGRA_8888格式处理的颜色数组。                                        |
| options | [image.InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建像素的属性，包括透明度，尺寸，缩略值，像素格式和是否可编辑。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](#pixelmap)> | 返回Pixelmap。<br>当创建的pixelmap大小超过原图大小时，返回原图pixelmap大小。|

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
    let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
    sendableImage.createPixelMap(color, opts).then((pixelMap: sendableImage.PixelMap) => {
        console.info('Succeeded in creating pixelmap.');
    }).catch((error: BusinessError) => {
        console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
    })
}
```

## sendableImage.createPixelMapFromParcel

createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap

从MessageSequence中获取PixelMap。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是   | 保存有PixelMap信息的MessageSequence。      |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

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
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MySequence implements rpc.Parcelable {
    pixel_map: sendableImage.PixelMap;
    constructor(conPixelmap: sendableImage.PixelMap) {
        this.pixel_map = conPixelmap;
    }
    marshalling(messageSequence: rpc.MessageSequence) {
        this.pixel_map.marshalling(messageSequence);
        return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence) {
        try {
            this.pixel_map = sendableImage.createPixelMapFromParcel(messageSequence);
        } catch(e) {
            let error = e as BusinessError;
            console.error(`createPixelMapFromParcel error. code is ${error.code}, message is ${error.message}`);
            return false;
        }
      return true;
    }
}
async function Demo() {
   const color: ArrayBuffer = new ArrayBuffer(96);
   let bufferArr: Uint8Array = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i++) {
      bufferArr[i] = 0x80;
   }
   let opts: image.InitializationOptions = {
      editable: true,
      pixelFormat: 4,
      size: { height: 4, width: 6 },
      alphaType: 3
   }
   let pixelMap: sendableImage.PixelMap | undefined = undefined;
   await sendableImage.createPixelMap(color, opts).then((srcPixelMap: sendableImage.PixelMap) => {
      pixelMap = srcPixelMap;
   })
   if (pixelMap != undefined) {
     // 序列化。
     let parcelable: MySequence = new MySequence(pixelMap);
     let data: rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);

     // 反序列化 rpc获取到data。
     let ret: MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);

     // 获取到pixelmap。
     let unmarshPixelmap = ret.pixel_map;
   }
}
```

## sendableImage.createPixelMapFromSurface

createPixelMapFromSurface(surfaceId: string, region: image.Region): Promise\<PixelMap>

从Surface id创建一个PixelMap对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                 | 必填 | 说明                                     |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | 是   | 从[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件获取的surfaceId。|
| region                 | [image.Region](../apis-image-kit/arkts-apis-image-i.md#region8)  | 是   | 裁剪的尺寸。                         |

**返回值：**
| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap)> | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | Invalid input parameter|
| 62980105 | Failed to get the data|
| 62980178 | Failed to create the PixelMap|

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(surfaceId: string) {
    let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
    sendableImage.createPixelMapFromSurface(surfaceId, region).then(() => {
        console.info('Succeeded in creating pixelmap from Surface');
    }).catch((error: BusinessError) => {
        console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
    });
}
```

## sendableImage.createPixelMapSync

createPixelMapSync(colors: ArrayBuffer, options: image.InitializationOptions): PixelMap

通过属性创建PixelMap，同步返回PixelMap结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | 是   | BGRA_8888格式的颜色数组。                                        |
| options | [image.InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建像素的属性，包括透明度，尺寸，缩略值，像素格式和是否可编辑。 |

**返回值：**
| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
    let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
    let pixelMap : sendableImage.PixelMap = sendableImage.createPixelMapSync(color, opts);
    return pixelMap;
}
```

## sendableImage.convertFromPixelMap

convertFromPixelMap(pixelMap: image.PixelMap): PixelMap

通过image下的PixelMap创建出一个sendableImage下的PixelMap，同步返回PixelMap结果。原PixelMap的方法均不可再调用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| pixelMap | [image.PixelMap](arkts-apis-image-PixelMap.md) | 是   | image下的非sendable的PixelMap。 |

**返回值：**
| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | 成功同步返回sendable的PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 62980104 | Failed to initialize the internal object.|

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
    let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
    let pixelMap : image.PixelMap = image.createPixelMapSync(color, opts);
    let sendablePixelMap : sendableImage.PixelMap = sendableImage.convertFromPixelMap(pixelMap);
    return sendablePixelMap;
}
```

## sendableImage.convertToPixelMap

convertToPixelMap(pixelMap: PixelMap): image.PixelMap

通过sendableImage下的PixelMap创建出一个image下的PixelMap，同步返回PixelMap结果。原PixelMap的方法均不可再调用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| pixelMap | [PixelMap](#pixelmap) | 是   | sendableImage下的PixelMap。 |

**返回值：**
| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功同步返回image下的非sendable的PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 62980104 | Failed to initialize the internal object.|

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
    let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
    let sendablePixelMap : sendableImage.PixelMap = sendableImage.createPixelMapSync(color, opts);
    let pixelMap : image.PixelMap = sendableImage.convertToPixelMap(sendablePixelMap);
    return pixelMap;
}
```

## PixelMap

图像像素类，用于读取或写入图像数据以及获取图像信息。在调用PixelMap的方法前，需要先通过[createPixelMap](#sendableimagecreatepixelmap)创建一个PixelMap实例。目前pixelmap序列化大小最大128MB，超过会送显失败。大小计算方式为(宽\*高\*每像素占用字节数)。

sendableImage下的PixelMap支持sendable属性，支持worker线程共享。sendableImage下的PixelMap，可以利用[Convert](#sendableimageconverttopixelmap)方法与image下的PixelMap进行互相转换。转换后，原对象的方法均不允许再调用，否则将报错501 无法调用接口。跨线程处理PixelMap时，需要考虑多线程问题。

在调用PixelMap的方法前，需要先通过[sendableImage.createPixelMap](#sendableimagecreatepixelmap)构建一个PixelMap对象。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型    | 只读 | 可选 | 说明                       |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable        | boolean | 是   | 否   | true表示图像像素可被编辑，false表示不可被编辑。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| isStrideAlignment | boolean | 是   | 否   | true表示图像内存为DMA内存，false表示非DMA内存。DMA内存的PixelMap会做256字节内存对齐，行末会存在padding区域。 |

### readPixelsToBuffer

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

读取图像像素数据，结果写入ArrayBuffer里，使用Promise形式返回。指定BGRA_8888格式创建pixelmap，读取的像素数据与原数据保持一致。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                                                  |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sendableImage } from '@kit.ImageKit';

async function Demo(pixelMap : sendableImage.PixelMap) {
    const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
    if (pixelMap != undefined) {
        pixelMap.readPixelsToBuffer(readBuffer).then(() => {
            console.info('Succeeded in reading image pixel data.'); // 符合条件则进入。 
        }).catch((error: BusinessError) => {
            console.error(`Failed to read image pixel data. code is ${error.code}, message is ${error.message}`);// 不符合条件则进入。
        })
    }
}
```

### readPixelsToBufferSync

readPixelsToBufferSync(dst: ArrayBuffer): void

以同步方法读取PixelMap到Buffer里。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sendableImage } from '@kit.ImageKit';

async function Demo(pixelMap: sendableImage.PixelMap) {
    const bufferSize = pixelMap.getPixelBytesNumber();
    const readBuffer: ArrayBuffer = new ArrayBuffer(bufferSize);
    if (pixelMap != undefined) {
        pixelMap.readPixelsToBufferSync(readBuffer);
    }
}
```

### readPixels

readPixels(area: image.PositionArea): Promise\<void>

读取区域内的图片数据，使用Promise形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域大小，根据区域读取。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise实例，用于获取读取结果，失败时返回错误信息。 |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const area: image.PositionArea = {
        pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    if (pixelMap != undefined) {
        pixelMap.readPixels(area).then(() => {
            console.info('Succeeded in reading the image data in the area.'); //符合条件则进入。
        }).catch((error: BusinessError) => {
            console.error(`Failed to read the image data in the area. code is ${error.code}, message is ${error.message}`);// 不符合条件则进入。
        })
    }
}
```

### readPixelsSync

readPixelsSync(area: image.PositionArea): void

读取区域内的图片数据并同步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域大小，根据区域读取。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const area : image.PositionArea = {
        pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    if (pixelMap != undefined) {
        pixelMap.readPixelsSync(area);
    }
}
```

### writePixels

writePixels(area: image.PositionArea): Promise\<void>

将PixelMap写入指定区域内，使用Promise形式返回写入结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域，根据区域写入。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise实例，用于获取写入结果，失败时返回错误信息。 |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const area: image.PositionArea = {
        pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    let bufferArr: Uint8Array = new Uint8Array(area.pixels);
    for (let i = 0; i < bufferArr.length; i++) {
        bufferArr[i] = i + 1;
    }
    if (pixelMap != undefined) {
        pixelMap.writePixels(area).then(() => {
            console.info('Succeeded to write pixelmap into the specified area.');
        }).catch((error: BusinessError) => {
            console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
        })
    }
}
```

### writePixelsSync

writePixelsSync(area: image.PositionArea): void

以同步方法将PixelMap写入指定区域内。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [image.PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域，根据区域写入。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const area: image.PositionArea = {
        pixels: new ArrayBuffer(8),
        offset: 0,
        stride: 8,
        region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
    };
    let bufferArr: Uint8Array = new Uint8Array(area.pixels);
    for (let i = 0; i < bufferArr.length; i++) {
        bufferArr[i] = i + 1;
    }
    if (pixelMap != undefined) {
        pixelMap.writePixelsSync(area);
    }
}
```

### writeBufferToPixels

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

读取缓冲区中的图片数据，结果写入PixelMap中，使用Promise形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
    let bufferArr: Uint8Array = new Uint8Array(color);
    for (let i = 0; i < bufferArr.length; i++) {
        bufferArr[i] = i + 1;
    }
    if (pixelMap != undefined) {
        pixelMap.writeBufferToPixels(color).then(() => {
            console.info("Succeeded in writing data from a buffer to a PixelMap.");
        }).catch((error: BusinessError) => {
            console.error(`Failed to write data from a buffer to a PixelMap. code is ${error.code}, message is ${error.message}`);
        })
    }
}
```

### writeBufferToPixelsSync

writeBufferToPixelsSync(src: ArrayBuffer): void

读取缓冲区中的图片数据，结果写入PixelMap并同步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明           |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | 是   | 图像像素数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(pixelMap: sendableImage.PixelMap) {
    const bufferSize = pixelMap.getPixelBytesNumber();
    const color : ArrayBuffer = new ArrayBuffer(bufferSize);
    let bufferArr : Uint8Array = new Uint8Array(color);
    for (let i = 0; i < bufferArr.length; i++) {
        bufferArr[i] = i + 1;
    }
    if (pixelMap != undefined) {
        pixelMap.writeBufferToPixelsSync(color);
    }
}
```

### getImageInfo

getImageInfo(): Promise\<image.ImageInfo>

获取图像像素信息，使用Promise形式返回获取的图像像素信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                              | 说明                                                        |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Promise实例，用于异步获取图像像素信息，失败时返回错误信息。 |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    if (pixelMap != undefined) {
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
            if (imageInfo != undefined) {
                console.info("Succeeded in obtaining the image pixel map information."+ imageInfo.size.height);
            }
        }).catch((error: BusinessError) => {
            console.error(`Failed to obtain the image pixel map information. code is ${error.code}, message is ${error.message}`);
        })
    }
}
```

### getImageInfoSync

getImageInfoSync(): image.ImageInfo

以同步方法获取图像像素信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型                              | 说明                                                        |
| --------------------------------- | ----------------------------------------------------------- |
| [ImageInfo](arkts-apis-image-i.md#imageinfo)           | 图像像素信息。                                                |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**示例：**
 
```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    if (pixelMap != undefined) {
        let imageInfo : image.ImageInfo = pixelMap.getImageInfoSync();
    }
}
```

### getBytesNumberPerRow

getBytesNumberPerRow(): number

获取图像像素每行字节数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的行字节数。 |

**示例：**

```ts
let rowCount: number = pixelMap.getBytesNumberPerRow();
```

### getPixelBytesNumber

getPixelBytesNumber(): number

获取图像像素的总字节数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的总字节数。 |

**示例：**

```ts
let pixelBytesNumber: number = pixelMap.getPixelBytesNumber();
```

### getDensity

getDensity():number

获取当前图像像素的密度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明            |
| ------ | --------------- |
| number | 图像像素的密度，单位为ppi。|

**示例：**

```ts
let getDensity: number = pixelMap.getDensity();
```

### opacity

opacity(rate: number): Promise\<void>

通过设置透明比率来让PixelMap达到对应的透明效果，使用Promise形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | 是   | 透明比率的值，取值范围是(0,1]。|

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise实例，用于获取结果，失败时返回错误信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let rate: number = 0.5;
    if (pixelMap != undefined) {
        pixelMap.opacity(rate).then(() => {
            console.info('Succeeded in setting opacity.');
        }).catch((err: BusinessError) => {
            console.error(`Failed to set opacity. code is ${err.code}, message is ${err.message}`);
        })
    }
}
```

### opacitySync

opacitySync(rate: number): void

设置PixelMap的透明比率，初始化PixelMap。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | 是   | 透明比率的值，取值范围是(0,1]。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let rate : number = 0.5;
    if (pixelMap != undefined) {
        pixelMap.opacitySync(rate);
    }
}
```

### createAlphaPixelmap

createAlphaPixelmap(): Promise\<PixelMap>

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的PixelMap，可用于阴影效果，使用Promise形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                        |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](#pixelmap)> | Promise实例，返回pixelmap。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    if (pixelMap != undefined) {
        pixelMap.createAlphaPixelmap().then((alphaPixelMap: sendableImage.PixelMap) => {
            console.info('Succeeded in creating alpha pixelmap.');
        }).catch((error: BusinessError) => {
            console.error(`Failed to create alpha pixelmap. code is ${error.code}, message is ${error.message}`);
        })
    }
}
```

### createAlphaPixelmapSync

createAlphaPixelmapSync(): PixelMap

根据Alpha通道的信息，生成一个仅包含Alpha通道信息的PixelMap，可用于阴影效果，同步返回PixelMap类型的结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](#pixelmap) | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sendableImage } from '@kit.ImageKit';

async function Demo(pixelMap : sendableImage.PixelMap) {
    let resPixelMap : sendableImage.PixelMap = pixelMap.createAlphaPixelmapSync();
    return resPixelMap;
}
```

### scale

scale(x: number, y: number): Promise\<void>

根据输入的宽高对图片进行缩放，使用Promise形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let scaleX: number = 2.0;
    let scaleY: number = 1.0;
    if (pixelMap != undefined) {
        pixelMap.scale(scaleX, scaleY).then(() => {
            console.info('Succeeded in scaling pixelmap.');
        }).catch((err: BusinessError) => {
            console.error(`Failed to scale pixelmap. code is ${err.code}, message is ${err.message}`);
            
        })   
    }
}
```

### scaleSync

scaleSync(x: number, y: number): void

以同步方法根据输入的宽高对图片进行缩放。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let scaleX: number = 2.0;
    let scaleY: number = 1.0;
    if (pixelMap != undefined) {
        pixelMap.scaleSync(scaleX, scaleY);
    }
}
```

### translate

translate(x: number, y: number): Promise\<void>

根据输入的坐标对图片进行位置变换，使用Promise形式返回。

translate后的图片尺寸改变为：width+X，height+Y，建议translate后的图片尺寸宽高不超过屏幕的宽高。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明        |
| ------ | ------ | ---- | ----------- |
| x      | number | 是   | 区域横坐标。单位：像素。|
| y      | number | 是   | 区域纵坐标。单位：像素。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let translateX: number = 50.0;
    let translateY: number = 10.0;
    if (pixelMap != undefined) {
        pixelMap.translate(translateX, translateY).then(() => {
            console.info('Succeeded in translating pixelmap.');
        }).catch((err: BusinessError) => {
            console.error(`Failed to translate pixelmap. code is ${err.code}, message is ${err.message}`);
        })
    }
}
```

### translateSync

translateSync(x: number, y: number): void

根据输入的坐标对图片进行位置变换并同步返回结果。

translate后的图片尺寸改变为：width+X，height+Y，建议translate后的图片尺寸宽高不超过屏幕的宽高。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | 是   | 宽度的缩放倍数。|
| y        | number               | 是   | 高度的缩放倍数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let translateX : number = 50.0;
    let translateY : number = 10.0;
    if (pixelMap != undefined) {
        pixelMap.translateSync(translateX, translateY);
    }
}
```

### rotate

rotate(angle: number): Promise\<void>

根据输入的角度对图片进行旋转，使用Promise形式返回。

> **说明：**
>
> - 图片旋转的角度取值范围：[0, 360]。超出取值范围时，根据圆周360度自动矫正。例如，-100度与260度效果相同。
> - 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let angle: number = 90.0;
    if (pixelMap != undefined) {
        pixelMap.rotate(angle).then(() => {
            console.info('Succeeded in rotating pixelmap.');
        }).catch((err: BusinessError) => {
            console.error(`Failed to rotate pixelmap. code is ${err.code}, message is ${err.message}`); 
        })
    }
}
```

### rotateSync

rotateSync(angle: number): void

根据输入的角度对图片进行旋转并同步返回结果。

> **说明：**
>
> - 图片旋转的角度取值范围：[0, 360]。超出取值范围时，根据圆周360度自动矫正。例如，-100度与260度效果相同。
> - 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | 是   | 图片旋转的角度。              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let angle : number = 90.0;
    if (pixelMap != undefined) {
        pixelMap.rotateSync(angle);
    }
}
```

### flip

flip(horizontal: boolean, vertical: boolean): Promise\<void>

根据输入的条件对图片进行翻转，使用Promise形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型    | 必填 | 说明      |
| ---------- | ------- | ---- | --------- |
| horizontal | boolean              | 是   | true表示进行水平翻转，false表示不进行水平翻转。            |
| vertical   | boolean              | 是   | true表示进行垂直翻转，false表示不进行垂直翻转。            |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let horizontal: boolean = true;
    let vertical: boolean = false;
    if (pixelMap != undefined) {
        pixelMap.flip(horizontal, vertical).then(() => {
            console.info('Succeeded in flipping pixelmap.');
        }).catch((err: BusinessError) => {
            console.error(`Failed to flip pixelmap. code is ${err.code}, message is ${err.message}`);
            
        })
    }
}
```

### flipSync

flipSync(horizontal: boolean, vertical: boolean): void

根据输入的条件对图片进行翻转并同步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                          |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | 是   | true表示进行水平翻转，false表示不进行水平翻转。            |
| vertical   | boolean              | 是   | true表示进行垂直翻转，false表示不进行垂直翻转。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let horizontal : boolean = true;
    let vertical : boolean = false;
    if (pixelMap != undefined) {
        pixelMap.flipSync(horizontal, vertical);
    }
}
```

### crop

crop(region: image.Region): Promise\<void>

根据输入的尺寸对图片进行裁剪，使用Promise形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明        |
| ------ | ------------------ | ---- | ----------- |
| region | [Region](../apis-image-kit/arkts-apis-image-i.md#region8) | 是   | 裁剪的尺寸。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
    if (pixelMap != undefined) {
        pixelMap.crop(region).then(() => {
            console.info('Succeeded in cropping pixelmap.');
        }).catch((err: BusinessError) => {
            console.error(`Failed to crop pixelmap. code is ${err.code}, message is ${err.message}`);

        });
    }
}
```

### cropSync

cropSync(region: image.Region): void

根据输入的尺寸裁剪图片。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](../apis-image-kit/arkts-apis-image-i.md#region8)   | 是   | 裁剪的尺寸。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  501    | Resource Unavailable. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
    let region : image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
    if (pixelMap != undefined) {
        pixelMap.cropSync(region);
    }
}
```

### getColorSpace

getColorSpace(): colorSpaceManager.ColorSpaceManager

获取图像广色域信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                                | 说明             |
| ----------------------------------- | ---------------- |
| [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 图像广色域信息。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980101| If the image data abnormal.            |
| 62980103| If the image data unsupport.             |
| 62980115| If the image parameter invalid.            |

**示例：**

```ts
async function Demo() {
    if (pixelMap != undefined) {
        let csm = pixelMap.getColorSpace();
    }
}
```

### setColorSpace

setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void

设置图像广色域信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型                                | 必填 | 说明            |
| ---------- | ----------------------------------- | ---- | --------------- |
| colorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 是   | 图像广色域信息。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980111| If the operation invalid.        |
| 62980115| If the image parameter invalid.             |

**示例：**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
async function Demo() {
    let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
    let csm: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
    if (pixelMap != undefined) {
        pixelMap.setColorSpace(csm);
    }
}
```

### applyColorSpace

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager): Promise\<void>

根据输入的目标色彩空间对图像像素颜色进行色彩空间转换，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明        |
| ------ | ------------------ | ---- | ----------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 是   | 目标色彩空间，支持SRGB、DCI_P3、DISPLAY_P3、ADOBE_RGB_1998。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**示例：**

```ts
import { sendableImage } from '@kit.ImageKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(pixelMap : sendableImage.PixelMap) {
    let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
    let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
    pixelMap.applyColorSpace(targetColorSpace).then(() => {
        console.info('Succeeded in applying color space for pixelmap object.');
    }).catch((error: BusinessError) => {
        console.error(`Failed to apply color space for pixelmap object. code is ${error.code}, message is ${error.message}`); 
    })
}
```

### marshalling

marshalling(sequence: rpc.MessageSequence): void

将PixelMap序列化后写入MessageSequence。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)  | 是   | 新创建的MessageSequence。                 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error.             |

**示例：**
```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
    pixel_map: sendableImage.PixelMap;
    constructor(conPixelMap : sendableImage.PixelMap) {
        this.pixel_map = conPixelMap;
    }
    marshalling(messageSequence : rpc.MessageSequence) {
        this.pixel_map.marshalling(messageSequence);
        console.info('marshalling');
        return true;
    }
    unmarshalling(messageSequence : rpc.MessageSequence) {
      sendableImage.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel: sendableImage.PixelMap) => {
        pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: sendableImage.PixelMap) => {
          this.pixel_map = pixelMap;
          pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
            console.info("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
          })
        })
      });
      return true;
    }
}
async function Demo() {
   const color: ArrayBuffer = new ArrayBuffer(96);
   let bufferArr: Uint8Array = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i++) {
      bufferArr[i] = 0x80;
   }
   let opts: image.InitializationOptions = {
      editable: true,
      pixelFormat: 4,
      size: { height: 4, width: 6 },
      alphaType: 3
   }
   let pixelMap: sendableImage.PixelMap | undefined = undefined;
   await sendableImage.createPixelMap(color, opts).then((srcPixelMap: sendableImage.PixelMap) => {
      pixelMap = srcPixelMap;
   })
   if (pixelMap != undefined) {
    // 序列化。
     let parcelable: MySequence = new MySequence(pixelMap);
     let data: rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);

    // 反序列化 rpc获取到data。
     let ret: MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);
   }
}
```

### unmarshalling

unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>

从MessageSequence中获取PixelMap，
如需使用同步方式创建PixelMap可使用：[createPixelMapFromParcel](#sendableimagecreatepixelmapfromparcel)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是   | 保存有PixelMap信息的MessageSequence。      |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](#pixelmap)> | Promise实例，用于异步获取结果，失败时返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error.              |
| 62980096 | The operation failed.         |

**示例：**

```ts
import { sendableImage } from '@kit.ImageKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
    pixel_map: sendableImage.PixelMap;
    constructor(conPixelMap: sendableImage.PixelMap) {
        this.pixel_map = conPixelMap;
    }
    marshalling(messageSequence: rpc.MessageSequence) {
        this.pixel_map.marshalling(messageSequence);
        console.info('marshalling');
        return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence) {
      sendableImage.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel : sendableImage.PixelMap) => {
        pixelParcel.unmarshalling(messageSequence).then(async (pixelMap : sendableImage.PixelMap) => {
          this.pixel_map = pixelMap;
          pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
            console.info("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
          })
        })
      });
      return true;
    }
}
async function Demo() {
   const color: ArrayBuffer = new ArrayBuffer(96);
   let bufferArr: Uint8Array = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i++) {
      bufferArr[i] = 0x80;
   }
   let opts: image.InitializationOptions = {
      editable: true,
      pixelFormat: 4,
      size: { height: 4, width: 6 },
      alphaType: 3
   }
   let pixelMap: sendableImage.PixelMap | undefined = undefined;
   await sendableImage.createPixelMap(color, opts).then((srcPixelMap : sendableImage.PixelMap) => {
      pixelMap = srcPixelMap;
   })
   if (pixelMap != undefined) {
    // 序列化。
     let parcelable: MySequence = new MySequence(pixelMap);
     let data : rpc.MessageSequence = rpc.MessageSequence.create();
     data.writeParcelable(parcelable);

    // 反序列化 rpc获取到data。
     let ret : MySequence = new MySequence(pixelMap);
     data.readParcelable(ret);
   }
}
```

### release

release():Promise\<void>

释放PixelMap对象，使用Promise形式返回释放结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void> | Promise实例，异步返回释放结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sendableImage } from '@kit.ImageKit';

async function Demo(pixelMap: sendableImage.PixelMap) {
    if (pixelMap != undefined) {
        await pixelMap.release().then(() => {
            console.info('Succeeded in releasing pixelmap object.');
        }).catch((error: BusinessError) => {
            console.error(`Failed to release pixelmap object. code is ${error.code}, message is ${error.message}`);
        })
    }
}
```

## Size

表示图片尺寸。
继承自[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型   | 只读 | 可选 | 说明           |
| ------ | ------ | ---- | ---- | -------------- |
| height | number | 否   | 否   | 输出图片的高，单位：像素。 |
| width  | number | 否   | 否   | 输出图片的宽，单位：像素。 |

## Region

表示区域信息。
继承自[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 只读 | 可选 | 说明         |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | 否   | 否   | 区域大小。   |
| x    | number        | 否   | 否   | 区域横坐标。单位：像素。 |
| y    | number        | 否   | 否   | 区域纵坐标。单位：像素。 |

## sendableImage.createImageSource

createImageSource(uri: string): ImageSource

通过传入的uri创建ImageSource实例。


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型   | 必填 | 说明                               |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | 是   | 图片路径，当前仅支持应用沙箱路径。</br>当前支持格式有：.jpg .png .gif .bmp .webp .dng [SVG](arkts-apis-image-f.md#svg标签说明) .ico。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.cacheDir + "/test.jpg";
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(path);
```

## sendableImage.createImageSource

createImageSource(fd: number): ImageSource

通过传入文件描述符来创建ImageSource实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.cacheDir + "/test.jpg";
let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(file.fd);
```

## sendableImage.createImageSource

createImageSource(buf: ArrayBuffer): ImageSource

通过缓冲区创建ImageSource实例。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
const buf: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(buf);
```

## sendableImage.createImageReceiver

createImageReceiver(size: image.Size, format: image.ImageFormat, capacity: number): ImageReceiver

通过图片大小、图片格式、容量创建ImageReceiver实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| size    | [image.Size](./arkts-apis-image-i.md#size)  | 是   | 图像的默认大小。       |
| format   | [image.ImageFormat](./arkts-apis-image-e.md#imageformat9) | 是   | 图像格式，取值为image.ImageFormat常量，目前仅支持 ImageFormat:JPEG。             |
| capacity | number | 是   | 同时访问的最大图像数。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver) | 如果操作成功，则返回ImageReceiver实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
import { image } from '@kit.ImageKit';

let size: image.Size = {
    height: 8192,
    width: 8
} 
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
```

## ImageSource

ImageSource类，用于获取图片相关信息。在调用ImageSource的方法前，需要先通过[createImageSource](#sendableimagecreateimagesource)构建一个ImageSource实例。


### createPixelMap

createPixelMap(options?: image.DecodingOptions): Promise\<PixelMap>

通过图片解码参数创建PixelMap对象。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                 | 必填 | 说明       |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [image.DecodingOptions](./arkts-apis-image-i.md#decodingoptions7) | 否   | 解码参数。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap]> | Promise实例，用于异步返回创建结果。 |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.cacheDir + "/test.jpg";
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(path);
sendableImageSourceApi.createPixelMap().then((pixelMap: sendableImage.PixelMap) => {
    console.info('Succeeded in creating pixelMap object through image decoding parameters.');
}).catch((error: BusinessError) => {
    console.error(`Failed to create pixelMap object through image decoding parameters. code ${error.code}, message is ${error.message}`);
})
```

### release

release(): Promise\<void>

释放ImageSource实例，使用Promise形式返回结果。release是线程不安全的。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.cacheDir + "/test.jpg";
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(path);
sendableImageSourceApi.release().then(() => {
    console.info('Succeeded in releasing the image source instance.');
}).catch((error: BusinessError) => {
    console.error(`Failed to release the image source instance. code ${error.code}, message is ${error.message}`);
})
```

## Image

提供基本的图像操作，包括获取图像信息、读写图像数据。调用[readNextImage](#readnextimage)和[readLatestImage](#readlatestimage)接口时会返回image。继承自[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称     | 类型               | 只读 | 可选 | 说明                                               |
| -------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect | [Region](#region) | 否   | 否   | 要裁剪的图像区域。                                 |
| size     | [Size](#size)      | 是   | 否   | 图像大小。如果image对象所存储的是相机预览流数据，即YUV图像数据，那么获取到的size中的宽高分别对应YUV图像的宽高； 如果image对象所存储的是相机拍照流数据，即JPEG图像，由于已经是编码后的文件，size中的宽等于JPEG文件大小，高等于1。image对象所存储的数据是预览流还是拍照流，取决于应用将receiver中的surfaceId传给相机的previewOutput还是captureOutput。相机预览与拍照最佳实践请参考[双路预览(ArkTS)](../../media/camera/camera-dual-channel-preview.md)与[拍照实现方案(ArkTS)](../../media/camera/camera-shooting-case.md)。                                         |
| format   | number             | 是   | 否   | 图像格式，参考[OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format)。 |
| timestamp<sup>12+</sup> | number         | 是      | 否   | 图像时间戳。时间戳以纳秒为单位，通常是单调递增的。时间戳的具体含义和基准取决于图像的生产者，在相机预览/拍照场景，生产者就是相机。来自不同生产者的图像的时间戳可能有不同的含义和基准，因此可能无法进行比较。如果要获取某张照片的生成时间，可以通过[getImageProperty](arkts-apis-image-ImageSource.md#getimageproperty11)接口读取相关的EXIF信息。|

### getComponent

getComponent(componentType: image.ComponentType): Promise\<image.Component>

根据图像的组件类型从图像中获取组件缓存并使用Promise方式返回结果。getComponent是线程不安全的。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| componentType | [image.ComponentType](./arkts-apis-image-e.md#componenttype9) | 是   | 图像的组件类型。 |

**返回值：**

| 类型                              | 说明                              |
| --------------------------------- | --------------------------------- |
| Promise<[image.Component](./arkts-apis-image-i.md#component9)> | Promise实例，用于异步返回组件缓冲区。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function Demo() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  let img = await receiver.readNextImage();
  img.getComponent(4).then((component: image.Component) => {
    console.info('getComponent succeeded.');
  }).catch((error: BusinessError) => {
    console.error(`getComponent failed code ${error.code}, message is ${error.message}`);
  })
}
```

### release

release(): Promise\<void>

释放当前图像并使用Promise方式返回结果。

在接收另一个图像前必须先释放对应资源。release是线程不安全的。


**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise\<void> | promise返回操作结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function Demo() {
  let size: image.Size = {
    height: 8192,
    width: 8
  }
  let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
  let img = await receiver.readNextImage();
  img.release().then(() => {
    console.info('release succeeded.');
  }).catch((error: BusinessError) => {
    console.error(`release failed. code ${error.code}, message is ${error.message}`);
  })
}
```

## ImageReceiver

图像接收类，用于获取组件surface id，接收最新的图片和读取下一张图片，以及释放ImageReceiver实例。

在调用以下方法前需要先创建ImageReceiver实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

| 名称     | 类型                         | 只读 | 可选 | 说明               |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| size     | [image.Size](./arkts-apis-image-i.md#size)                | 是   | 否   | 图片大小。         |
| capacity | number                       | 是   | 否   | 同时访问的图像数。 |
| format   | [image.ImageFormat](./arkts-apis-image-e.md#imageformat9) | 是   | 否   | 图像格式。         |

### getReceivingSurfaceId

getReceivingSurfaceId(): Promise\<string>

用于获取一个surface id供Camera或其他组件使用。使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<string> | 异步返回surface id。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.getReceivingSurfaceId().then((id: string) => {
    console.info('Succeeded in getting the ReceivingSurfaceId.');
}).catch((error: BusinessError) => {
    console.error(`Failed to get the ReceivingSurfaceId.code ${error.code}, message is ${error.message}`);
})
```

### readLatestImage

readLatestImage(): Promise\<Image>

从ImageReceiver读取最新的图片，并使用promise返回结果。

**注意**：此接口需要在[on](#on)回调触发后调用，才能正常的接收到数据。且此接口返回的[Image](#image)对象使用完毕后需要调用[release](#release-2)方法释放，释放后才可以继续接收新的数据。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明               |
| ------------------------- | ------------------ |
| Promise<[Image](#image)> | 异步返回最新图片。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.readLatestImage().then((img: image.Image) => {
    console.info('readLatestImage succeeded.');
}).catch((error: BusinessError) => {
    console.error(`readLatestImage failed. code ${error.code}, message is ${error.message}`);
})
```

### readNextImage

readNextImage(): Promise\<Image>

从ImageReceiver读取下一张图片，并使用promise返回结果。

**注意**：此接口需要在[on](#on)回调触发后调用，才能正常的接收到数据。且此接口返回的[Image](#image)对象使用完毕后需要调用[release](#release-2)方法释放，释放后才可以继续接收新的数据。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明                 |
| ------------------------- | -------------------- |
| Promise<[Image](#image)> | 异步返回下一张图片。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.readNextImage().then((img: image.Image) => {
    console.info('readNextImage succeeded.');
}).catch((error: BusinessError) => {
    console.error(`readNextImage failed. code ${error.code}, message is ${error.message}`);
})
```

### on

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
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.on('imageArrival', () => {
    // image arrival, do something.
})
```

### release

release(): Promise\<void>

释放ImageReceiver实例并使用promise返回结果。release是线程不安全的。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型           | 说明               |
| -------------- | ------------------ |
| Promise\<void> | 异步返回操作结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.release().then(() => {
    console.info('release succeeded.');
}).catch((error: BusinessError) => {
    console.error(`release failed. code ${error.code}, message is ${error.message}`);
})
```
