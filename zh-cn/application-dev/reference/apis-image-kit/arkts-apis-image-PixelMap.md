# Interface (PixelMap)

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

图像像素类，用于读取或写入图像数据以及获取图像信息。在调用PixelMap的方法前，需要先通过[createPixelMap](arkts-apis-image-f.md#imagecreatepixelmap8)创建一个PixelMap实例。目前pixelmap序列化大小最大128MB，超过会送显失败。大小计算方式为(宽\*高\*每像素占用字节数)。

从API version 11开始，PixelMap支持通过worker跨线程调用。当PixelMap通过[Worker](../apis-arkts/js-apis-worker.md)跨线程后，原线程的PixelMap的所有接口均不能调用，否则将报错501 服务器不具备完成请求的功能。  

在调用PixelMap的方法前，需要先通过[image.createPixelMap](arkts-apis-image-f.md#imagecreatepixelmap8)构建一个PixelMap对象。

开发原子化服务请通过[ImageSoure](arkts-apis-image-ImageSource.md)构建PixelMap对象。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型    | 只读 | 可选 | 说明                       |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable        | boolean | 是   | 否   | true表示图像像素可被编辑，false表示不可被编辑。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| isStrideAlignment<sup>11+</sup> | boolean | 是   | 否   | true表示图像内存为DMA内存，false表示非DMA内存。 |

## readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

按照PixelMap的像素格式，读取PixelMap的图像像素数据，并写入缓冲区中，使用Promise形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                                                  |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadPixelsToBuffer(pixelMap : image.PixelMap) {
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

## readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

按照PixelMap的像素格式，读取PixelMap的图像像素数据，并写入缓冲区中，使用callback形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当读取像素数据到ArrayBuffer成功，err为undefined，否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadPixelsToBuffer(pixelMap : image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBuffer(readBuffer, (error: BusinessError, res: void) => {
      if(error) {
        console.error(`Failed to read image pixel data. code is ${error.code}, message is ${error.message}`);// 不符合条件则进入。
        return;
      } else {
        console.info('Succeeded in reading image pixel data.');  //符合条件则进入。
      }
    })
  }
}
```

## readPixelsToBufferSync<sup>12+</sup>

readPixelsToBufferSync(dst: ArrayBuffer): void

按照PixelMap的像素格式，读取PixelMap的图像像素数据，并写入缓冲区中，同步返回结果。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 缓冲区，函数执行结束后获取的图像像素数据写入到该内存区域内。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadPixelsToBufferSync(pixelMap : image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
  if (pixelMap != undefined) {
    pixelMap.readPixelsToBufferSync(readBuffer);
  }
}
```

## readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

固定按照BGRA_8888格式，读取PixelMap指定区域内的图像像素数据，并写入[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区中，该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，使用Promise形式返回。

可用公式计算PositionArea需要申请的内存大小。

YUV的区域计算公式：读取区域（region.size{width * height}）* 1.5 （1倍的Y分量+0.25倍U分量+0.25倍V分量）

RGBA的区域计算公式：读取区域（region.size{width * height}）* 4 （1倍的R分量+1倍G分量+1倍B分量+1倍A分量）

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域大小，根据区域读取。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadPixelsRGBA(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8为需要创建的像素buffer大小，取值为：height * width *4。
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

async function ReadPixelsYUV(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6),  // 6为需要创建的像素buffer大小，取值为：height * width *1.5。
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
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

## readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

固定按照BGRA_8888格式，读取PixelMap指定区域内的图像像素数据，并写入[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区中，该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，使用callback形式返回。

可用公式计算PositionArea需要申请的内存大小。

YUV的区域计算公式：读取区域（region.size{width * height}）* 1.5 （1倍的Y分量+0.25倍U分量+0.25倍V分量）

RGBA的区域计算公式：读取区域（region.size{width * height}）* 4 （1倍的R分量+1倍G分量+1倍B分量+1倍A分量）

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                           | 必填 | 说明                           |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域大小，根据区域读取。       |
| callback | AsyncCallback\<void>           | 是   |  回调函数。当读取区域内的图片数据成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadPixelsRGBA(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8为需要创建的像素buffer大小，取值为：height * width *4。
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  if (pixelMap != undefined) {
    pixelMap.readPixels(area, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to read pixelmap from the specified area. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info('Succeeded in reading pixelmap from the specified area.');
      }
    })
  }
}

async function ReadPixelsYUV(pixelMap : image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6为需要创建的像素buffer大小，取值为：height * width *1.5。
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  if (pixelMap != undefined) {
    pixelMap.readPixels(area, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to read pixelmap from the specified area. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info('Succeeded in reading pixelmap from the specified area.');
      }
    })
  }
}
```

## readPixelsSync<sup>12+</sup>

readPixelsSync(area: PositionArea): void

固定按照BGRA_8888格式，读取PixelMap指定区域内的图像像素数据，并写入[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区中，该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，同步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域大小，根据区域读取。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ReadPixelsSync(pixelMap : image.PixelMap) {
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

## writePixels<sup>7+</sup>

writePixels(area: PositionArea): Promise\<void>

固定按照BGRA_8888格式，读取[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区中的图像像素数据，并写入PixelMap指定区域内，该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，使用Promise形式返回。

可用公式计算PositionArea需要申请的内存大小。

YUV的区域计算公式：读取区域（region.size{width * height}）* 1.5 （1倍的Y分量+0.25倍U分量+0.25倍V分量）

RGBA的区域计算公式：读取区域（region.size{width * height}）* 4 （1倍的R分量+1倍G分量+1倍B分量+1倍A分量）

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域，根据区域写入。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WritePixelsRGBA() {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8为需要创建的像素buffer大小，取值为：height * width *4。
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
      console.info('Succeeded in writing pixelmap into the specified area.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
    })
  }
}

async function WritePixelsYUV() {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6为需要创建的像素buffer大小，取值为：height * width *1.5。
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writePixels(area).then(() => {
      console.info('Succeeded in writing pixelmap into the specified area.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

## writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

固定按照BGRA_8888格式，读取[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区中的图像像素数据，并写入PixelMap指定区域内，该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，使用callback形式返回。

可用公式计算PositionArea需要申请的内存大小。

YUV的区域计算公式：读取区域（region.size{width * height}）* 1.5 （1倍的Y分量+0.25倍U分量+0.25倍V分量）

RGBA的区域计算公式：读取区域（region.size{width * height}）* 4 （1倍的R分量+1倍G分量+1倍B分量+1倍A分量）

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名    | 类型                           | 必填 | 说明                           |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域，根据区域写入。           |
| callback  | AsyncCallback\<void>           | 是   | 回调函数，当写入成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WritePixelsRGBA() {
  const area: image.PositionArea = { pixels: new ArrayBuffer(8), // 8为需要创建的像素buffer大小，取值为：height * width *4。
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writePixels(area, (error : BusinessError) => {
      if (error) {
        console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info('Succeeded in writing pixelmap into the specified area.');
      }
    })
  }
}

async function WritePixelsYUV() {
  const area: image.PositionArea = { pixels: new ArrayBuffer(6), // 6为需要创建的像素buffer大小，取值为：height * width *1.5。
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writePixels(area, (error : BusinessError) => {
      if (error) {
        console.error(`Failed to write pixelmap into the specified area. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info('Succeeded in writing pixelmap into the specified area.');
      }
    })
  }
}
```

## writePixelsSync<sup>12+</sup>

writePixelsSync(area: PositionArea): void

固定按照BGRA_8888格式，读取[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区中的图像像素数据，并写入PixelMap指定区域内，该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，同步返回结果。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 区域，根据区域写入。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WritePixelsSync() {
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

## writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

按照PixelMap的像素格式，读取缓冲区中的图像像素数据，并写入PixelMap，使用Promise形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明           |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | 是   | 缓冲区，函数执行时会将该缓冲区中的图像像素数据写入到PixelMap。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteBufferToPixels() {
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

## writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

按照PixelMap的像素格式，读取缓冲区中的图像像素数据，并写入PixelMap，使用callback形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | 是   | 缓冲区，函数执行时会将该缓冲区中的图像像素数据写入到PixelMap。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当缓冲区中的图像像素数据写入PixelMap成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteBufferToPixels() {
  const color: ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4。
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writeBufferToPixels(color, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to write data from a buffer to a PixelMap. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info("Succeeded in writing data from a buffer to a PixelMap.");
      }
    })
  }
}
```

## writeBufferToPixelsSync<sup>12+</sup>

writeBufferToPixelsSync(src: ArrayBuffer): void

按照PixelMap的像素格式，读取缓冲区中的图像像素数据，并写入PixelMap，同步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明           |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | 是   | 缓冲区，函数执行时会将该缓冲区中的图像像素数据写入到PixelMap。缓冲区大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteBufferToPixelsSync() {
  const color : ArrayBuffer = new ArrayBuffer(96);  //96为需要创建的像素buffer大小，取值为：height * width *4。
  let bufferArr : Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  if (pixelMap != undefined) {
    pixelMap.writeBufferToPixelsSync(color);
  }
}
```


## getImageInfo<sup>7+</sup>

getImageInfo(): Promise\<ImageInfo>

获取图像像素信息，使用Promise形式返回获取的图像像素信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                              | 说明                                                        |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Promise对象，返回图像像素信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageInfo() {
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

## getImageInfo<sup>7+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

获取图像像素信息，使用callback形式返回获取的图像像素信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | 是   | 回调函数。当获取图像像素信息成功，err为undefined，data为获取到的图像像素信息；否则为错误对象。 |

**示例:**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageInfo() {
  if (pixelMap != undefined) {
    pixelMap.getImageInfo((error: BusinessError, imageInfo: image.ImageInfo) => {
      if (error) {
        console.error(`Failed to obtain the image pixel map information. code is ${error.code}, message is ${error.message}`);
        return;
      } else {
        console.info("Succeeded in obtaining the image pixel map information."+ imageInfo.size.height);
      }
    })
  }
}
```

## getImageInfoSync<sup>12+</sup>

getImageInfoSync(): ImageInfo

以同步方法获取图像像素信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

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
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageInfoSync() {
  if (pixelMap != undefined) {
    let imageInfo : image.ImageInfo = pixelMap.getImageInfoSync();
    return imageInfo;
  }
  return undefined;
}
```

## getBytesNumberPerRow<sup>7+</sup>

getBytesNumberPerRow(): number

获取图像像素每行字节数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的行字节数。 |

**示例：**

```ts
let rowCount: number = pixelMap.getBytesNumberPerRow();
```

## getPixelBytesNumber<sup>7+</sup>

getPixelBytesNumber(): number

获取图像像素的总字节数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的总字节数。 |

**示例：**

```ts
let pixelBytesNumber: number = pixelMap.getPixelBytesNumber();
```

## getDensity<sup>9+</sup>

getDensity():number

获取当前图像像素的密度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明            |
| ------ | --------------- |
| number | 图像像素的密度，单位为ppi。|

**示例：**

```ts
let getDensity: number = pixelMap.getDensity();
```

## opacity<sup>9+</sup>

opacity(rate: number, callback: AsyncCallback\<void>): void

通过设置透明比率来让PixelMap达到对应的透明效果，yuv图片不支持设置透明度，使用callback形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | 是   | 透明比率的值，取值范围是(0,1]。  |
| callback | AsyncCallback\<void> | 是   | 回调函数。当设置透明比率成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Opacity() {
  let rate: number = 0.5;
  if (pixelMap != undefined) {
    pixelMap.opacity(rate, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to set opacity. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in setting opacity.");
      }
    })
  }
}
```

## opacity<sup>9+</sup>

opacity(rate: number): Promise\<void>

通过设置透明比率来让PixelMap达到对应的透明效果，yuv图片不支持设置透明度，使用Promise形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | 是   | 透明比率的值，取值范围是(0,1]。|

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Opacity() {
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

## opacitySync<sup>12+</sup>

opacitySync(rate: number): void

设置PixelMap的透明比率，yuv图片不支持设置透明度，初始化PixelMap并同步返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | 是   | 透明比率的值，取值范围是(0,1]。   |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function OpacitySync() {
  let rate : number = 0.5;
  if (pixelMap != undefined) {
    pixelMap.opacitySync(rate);
  }
}
```

## createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的pixelmap，可用于阴影效果，yuv格式不支持此接口，使用Promise形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                        |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回PixelMap。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateAlphaPixelmap() {
  if (pixelMap != undefined) {
    pixelMap.createAlphaPixelmap().then((alphaPixelMap: image.PixelMap) => {
      console.info('Succeeded in creating alpha pixelmap.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to create alpha pixelmap. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

## createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的pixelmap，可用于阴影效果，yuv格式不支持此接口，使用callback形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                     |
| -------- | ------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<[PixelMap](arkts-apis-image-PixelMap.md)> | 是   |  回调函数，当创建PixelMap成功，err为undefined，data为获取到的PixelMap对象；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateAlphaPixelmap() {
  if (pixelMap != undefined) {
    pixelMap.createAlphaPixelmap((err: BusinessError, alphaPixelMap: image.PixelMap) => {
      if (alphaPixelMap == undefined) {
        console.error(`Failed to obtain new pixel map. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info('Succeeded in obtaining new pixel map.');
      }
    })
  }
}
```

## createAlphaPixelmapSync<sup>12+</sup>

createAlphaPixelmapSync(): PixelMap

根据Alpha通道的信息，生成一个仅包含Alpha通道信息的PixelMap，可用于阴影效果，yuv格式不支持此接口，同步返回PixelMap类型的结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateAlphaPixelmapSync() {
  if (pixelMap != undefined) {
    let pixelmap : image.PixelMap = pixelMap.createAlphaPixelmapSync();
    return pixelmap;
  }
  return undefined;
}
```

## scale<sup>9+</sup>

scale(x: number, y: number, callback: AsyncCallback\<void>): void

根据输入的宽高的缩放倍数对图片进行缩放，使用callback形式返回。

> **说明：**
>
> 1. 建议宽高的缩放倍数取非负数，否则会产生翻转效果。
> 2. 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | 是   | 宽度的缩放倍数。|
| y        | number               | 是   | 高度的缩放倍数。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图片进行缩放成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Scale() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scale(scaleX, scaleY, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to scale pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in scaling pixelmap.");
      }
    })
  }
}
```

## scale<sup>9+</sup>

scale(x: number, y: number): Promise\<void>

根据输入的宽高的缩放倍数对图片进行缩放，使用Promise形式返回。

> **说明：**
>
> 1. 建议宽高的缩放倍数取非负数，否则会产生翻转效果。
> 2. 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Scale() {
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

## scaleSync<sup>12+</sup>

scaleSync(x: number, y: number): void

根据输入的宽高的缩放倍数对图片进行缩放，同步返回结果。

> **说明：**
>
> 1. 建议宽高的缩放倍数取非负数，否则会产生翻转效果。
> 2. 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ScaleSync() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scaleSync(scaleX, scaleY);
  }
}
```

## scale<sup>12+</sup>

scale(x: number, y: number, level: AntiAliasingLevel): Promise\<void>

根据指定的缩放算法和输入的宽高的缩放倍数对图片进行缩放，使用Promise形式返回。

> **说明：**
>
> 1. 建议宽高的缩放倍数取非负数，否则会产生翻转效果。
> 2. 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 是   | 采用的缩放算法。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Scale() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scale(scaleX, scaleY, image.AntiAliasingLevel.LOW).then(() => {
      console.info('Succeeded in scaling pixelmap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to scale pixelmap. code is ${err.code}, message is ${err.message}`);

    })
  }
}
```

## scaleSync<sup>12+</sup>

scaleSync(x: number, y: number, level: AntiAliasingLevel): void

根据指定的缩放算法和输入的宽高的缩放倍数对图片进行缩放，同步返回结果。

> **说明：**
>
> 1. 建议宽高的缩放倍数取非负数，否则会产生翻转效果。
> 2. 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 是   | 采用的缩放算法。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ScaleSync() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    pixelMap.scaleSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
  }
}
```

## createScaledPixelMap<sup>18+</sup>

createScaledPixelMap(x: number, y: number, level?: AntiAliasingLevel): Promise\<PixelMap>

根据指定的缩放算法和输入的宽高的缩放倍数，创建一个新的缩放后的图片，使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateScaledPixelMap() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
      pixelMap.createScaledPixelMap(scaleX, scaleY, image.AntiAliasingLevel.LOW).then((scaledPixelMap: image.PixelMap) => {
      console.info('Succeeded in creating scaledPixelMap.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to create scaledPixelMap. Error code is ${error.code}, error message is ${error.message}`);
    })
  }
}
```

## createScaledPixelMapSync<sup>18+</sup>

createScaledPixelMapSync(x: number, y: number, level?: AntiAliasingLevel): PixelMap

根据指定的缩放算法和输入的宽高的缩放倍数，创建一个新的缩放后的图片，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。|
| y      | number | 是   | 高度的缩放倍数。|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法。|

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateScaledPixelMapSync() {
  let scaleX: number = 2.0;
  let scaleY: number = 1.0;
  if (pixelMap != undefined) {
    let scaledPixelMap = pixelMap.createScaledPixelMapSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
  }
}
```

## clone<sup>18+</sup>

clone(): Promise\<PixelMap>

拷贝一份当前Pixelmap对象，使用Promise形式返回。

**系统能力：**: SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回PixelMap。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of createing empty pixelmap. |
| 62980106 | The image data is to large. This status code is thrown when an error occurs during the process of checking size. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo() {
  if (pixelMap != undefined) {
    pixelMap.clone().then((clonePixelMap: image.PixelMap) => {
      console.info('Succeeded clone pixelmap.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to clone pixelmap. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

## cloneSync<sup>18+</sup>

cloneSync(): PixelMap

拷贝一份当前Pixelmap对象, 同步返回结果。

**系统能力：**: SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功同步返回PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of createing empty pixelmap. |
| 62980106 | The image data is to large. This status code is thrown when an error occurs during the process of checking size. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Demo(pixelMap: image.PixelMap) {
  if (pixelMap != undefined) {
    try {
      let clonedPixelMap = pixelMap.cloneSync();
    } catch(e) {
      let error = e as BusinessError;
      console.error(`clone pixelmap error. code is ${error.code}, message is ${error.message}`);
    }
  }
}
```

## translate<sup>9+</sup>

translate(x: number, y: number, callback: AsyncCallback\<void>): void

根据输入的坐标对图片进行位置变换，使用callback形式返回。

translate后的图片尺寸改变为：width+X ，height+Y，建议translate后的图片尺寸宽高不要超过屏幕的宽高。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| x        | number               | 是   | 区域横坐标。单位：像素。 |
| y        | number               | 是   | 区域纵坐标。单位：像素。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图片进行位置变换成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Translate() {
  let translateX: number = 50.0;
  let translateY: number = 10.0;
  if (pixelMap != undefined) {
    pixelMap.translate(translateX, translateY, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to translate pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in translating pixelmap.");
      }
    })
  }
}
```

## translate<sup>9+</sup>

translate(x: number, y: number): Promise\<void>

根据输入的坐标对图片进行位置变换，使用Promise形式返回。

translate后的图片尺寸改变为：width+X ，height+Y，建议translate后的图片尺寸宽高不要超过屏幕的宽高。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明        |
| ------ | ------ | ---- | ----------- |
| x      | number | 是   | 区域横坐标。单位：像素。 |
| y      | number | 是   | 区域纵坐标。单位：像素。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Translate() {
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

## translateSync<sup>12+</sup>

translateSync(x: number, y: number): void

根据输入的坐标对图片进行位置变换，同步返回结果。

translate后的图片尺寸改变为：width+X ，height+Y，建议translate后的图片尺寸宽高不要超过屏幕的宽高。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | 是   | 区域横坐标。单位：像素。 |
| y        | number               | 是   | 区域纵坐标。单位：像素。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function TranslateSync() {
  let translateX : number = 50.0;
  let translateY : number = 10.0;
  if (pixelMap != undefined) {
    pixelMap.translateSync(translateX, translateY);
  }
}
```

## rotate<sup>9+</sup>

rotate(angle: number, callback: AsyncCallback\<void>): void

根据输入的角度对图片进行旋转，使用callback形式返回。

> **说明：**
>
> 1. 图片旋转的角度取值范围：0-360。超出取值范围时，根据圆周360度自动矫正。例如，-100度与260度效果相同。
> 2. 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | 是   | 图片旋转的角度。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图片进行旋转成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Rotate() {
  let angle: number = 90.0;
  if (pixelMap != undefined) {
    pixelMap.rotate(angle, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to rotate pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in rotating pixelmap.");
      }
    })
  }
}
```

## rotate<sup>9+</sup>

rotate(angle: number): Promise\<void>

根据输入的角度对图片进行旋转，使用Promise形式返回。

> **说明：**
>
> 1. 图片旋转的角度取值范围：0-360。超出取值范围时，根据圆周360度自动矫正。例如，-100度与260度效果相同。
> 2. 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                          |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | 是   | 图片旋转的角度。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Rotate() {
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

## rotateSync<sup>12+</sup>

rotateSync(angle: number): void

根据输入的角度对图片进行旋转，同步返回结果。

> **说明：**
>
> 1. 图片旋转的角度取值范围：0-360。超出取值范围时，根据圆周360度自动矫正。例如，-100度与260度效果相同。
> 2. 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | 是   | 图片旋转的角度。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function RotateSync() {
  let angle : number = 90.0;
  if (pixelMap != undefined) {
    pixelMap.rotateSync(angle);
  }
}
```

## flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void

根据输入的条件对图片进行翻转，使用callback形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                          |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | 是   | true表示进行水平翻转，false表示不进行水平翻转。            |
| vertical   | boolean              | 是   | true表示进行垂直翻转，false表示不进行垂直翻转。            |
| callback   | AsyncCallback\<void> | 是   | 回调函数，当对图片翻转成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Flip() {
  let horizontal: boolean = true;
  let vertical: boolean = false;
  if (pixelMap != undefined) {
    pixelMap.flip(horizontal, vertical, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to flip pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in flipping pixelmap.");
      }
    })
  }
}
```

## flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean): Promise\<void>

根据输入的条件对图片进行翻转，使用Promise形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型    | 必填 | 说明      |
| ---------- | ------- | ---- | --------- |
| horizontal | boolean              | 是   | true表示进行水平翻转，false表示不进行水平翻转。            |
| vertical   | boolean              | 是   | true表示进行垂直翻转，false表示不进行垂直翻转。            |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Flip() {
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

## flipSync<sup>12+</sup>

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

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function FlipSync() {
  let horizontal : boolean = true;
  let vertical : boolean = false;
  if (pixelMap != undefined) {
    pixelMap.flipSync(horizontal, vertical);
  }
}
```

## crop<sup>9+</sup>

crop(region: Region, callback: AsyncCallback\<void>): void

根据输入的尺寸对图片进行裁剪，使用callback形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | 是   | 裁剪的尺寸。取值范围不能超过图片的宽高。 |
| callback | AsyncCallback\<void> | 是   |  回调函数。当对图片进行裁剪成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Crop() {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  if (pixelMap != undefined) {
    pixelMap.crop(region, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to crop pixelmap. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info("Succeeded in cropping pixelmap.");
      }
    })
  }
}
```

## crop<sup>9+</sup>

crop(region: Region): Promise\<void>

根据输入的尺寸对图片进行裁剪，使用Promise形式返回。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明        |
| ------ | ------------------ | ---- | ----------- |
| region | [Region](arkts-apis-image-i.md#region8) | 是   | 裁剪的尺寸。取值范围不能超过图片的宽高。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Crop() {
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

## cropSync<sup>12+</sup>

cropSync(region: Region): void

根据输入的尺寸裁剪图片。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | 是   | 裁剪的尺寸。取值范围不能超过图片的宽高。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CropSync() {
  let region : image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  if (pixelMap != undefined) {
    pixelMap.cropSync(region);
  }
}
```

## getColorSpace<sup>10+</sup>

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
async function GetColorSpace() {
  if (pixelMap != undefined) {
    let csm = pixelMap.getColorSpace();
  }
}
```

## setColorSpace<sup>10+</sup>

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
| 62980111| The image source data is incomplete.        |
| 62980115| If the image parameter invalid.             |

**示例：**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
async function SetColorSpace() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let csm: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.setColorSpace(csm);
  }
}
```

## applyColorSpace<sup>11+</sup>

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager, callback: AsyncCallback\<void>): void

根据输入的目标色彩空间对图像像素颜色进行色彩空间转换，使用callback形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 是   | 目标色彩空间，支持SRGB、DCI_P3、DISPLAY_P3、ADOBE_RGB_1998。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图像像素颜色进行色彩空间转换成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**示例：**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

async function ApplyColorSpace() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.applyColorSpace(targetColorSpace, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to apply color space for pixelmap object, error code is ${error}`);
        return;
      } else {
        console.info('Succeeded in applying color space for pixelmap object.');
      }
    })
  }
}
```

## applyColorSpace<sup>11+</sup>

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
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**示例：**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

async function ApplyColorSpace() {
  let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  let targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  if (pixelMap != undefined) {
    pixelMap.applyColorSpace(targetColorSpace).then(() => {
      console.info('Succeeded in applying color space for pixelmap object.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to apply color space for pixelmap object, error code is ${error}`);
    })
  }
}
```

## toSdr<sup>12+<sup>

toSdr(): Promise\<void>

将HDR的图像内容转换为SDR的图像内容，异步使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980137 | Invalid image operation.              |

**示例：**

<!--code_no_check-->
```ts
import image from '@ohos.multimedia.image';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'hdr.jpg'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
let img = context.resourceManager.getMediaContentSync($r('app.media.hdr'));
let imageSource = image.createImageSource(img.buffer.slice(0));
let decodingOptions: image.DecodingOptions = {
  desiredDynamicRange: image.DecodingDynamicRange.AUTO
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
  pixelmap.toSdr().then(() => {
    let imageInfo = pixelmap.getImageInfoSync();
    console.info("after toSdr ,imageInfo isHdr:" + imageInfo.isHdr);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set sdr. code is ${err.code}, message is ${err.message}`);
  });
} else {
  console.error('Failed to create pixelMap.');
}
```

## getMetadata<sup>12+</sup>

getMetadata(key: HdrMetadataKey): HdrMetadataValue

从PixelMap中获取元数据。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12) | 是   | HDR元数据的关键字，可用于查询对应值。 |

**返回值：**

| 类型                              | 说明                              |
| --------------------------------- | --------------------------------- |
| [HdrMetadataValue](arkts-apis-image-t.md#hdrmetadatavalue12) | 返回元数据的值。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401| Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.          |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 'app.media.test'需要替换为本地hdr图片。
let img = context.resourceManager.getMediaContentSync($r('app.media.test'));
let imageSource = image.createImageSource(img.buffer.slice(0));
let decodingOptions: image.DecodingOptions = {
  desiredDynamicRange: image.DecodingDynamicRange.AUTO
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
  try {
    let staticMetadata = pixelmap.getMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA);
    console.info("getmetadata:" + JSON.stringify(staticMetadata));
  } catch (e) {
    console.error('pixelmap create failed' + e);
  }
} else {
  console.error('Failed to create pixelMap.');
}
```

## setMetadata<sup>12+</sup>

setMetadata(key: HdrMetadataKey, value: HdrMetadataValue): Promise\<void>

设置PixelMap元数据。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12) | 是   | HDR元数据的关键字，用于设置对应值。 |
| value | [HdrMetadataValue](arkts-apis-image-t.md#hdrmetadatavalue12) | 是   | 元数据的值。 |

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401|  Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.         |

**示例：**

```ts
import image from '@ohos.multimedia.image';
import { BusinessError } from '@kit.BasicServicesKit';

let staticMetadata: image.HdrStaticMetadata = {
  displayPrimariesX: [1.1, 1.1, 1.1],
  displayPrimariesY: [1.2, 1.2, 1.2],
  whitePointX: 1.1,
  whitePointY: 1.2,
  maxLuminance: 2.1,
  minLuminance: 1.0,
  maxContentLightLevel: 2.1,
  maxFrameAverageLightLevel: 2.1,
};
const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } };
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  pixelMap.setMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA, staticMetadata).then(() => {
    console.info('Succeeded in setting pixelMap metadata.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to set the metadata.code ${error.code},message is ${error.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create the PixelMap.code ${error.code},message is ${error.message}`);
})

```

## setTransferDetached<sup>12+<sup>

setTransferDetached(detached: boolean): void

pixelmap在跨线程传输时，断开原线程的引用。适用于需立即释放pixelmap的场景。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型               | 必填 | 说明                          |
| ------- | ------------------ | ---- | ----------------------------- |
| detached | boolean   | 是   | true表示断开原线程引用，false表示不断开原线程引用。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';
import taskpool from '@ohos.taskpool';

@Concurrent
// 子线程方法。
async function loadPixelMap(rawFileDescriptor: number): Promise<PixelMap> {
  // 创建imageSource。
  const imageSource = image.createImageSource(rawFileDescriptor);
  // 创建pixelMap。
  const pixelMap = imageSource.createPixelMapSync();
  // 释放imageSource。
  imageSource.release();
  // 使pixelMap在跨线程传输完成后，断开原线程的引用。
  pixelMap.setTransferDetached(true);
  // 返回pixelMap给主线程。
  return pixelMap;
}

@Component
struct Demo {
  @State pixelMap: PixelMap | undefined = undefined;
  // 主线程方法。
  private loadImageFromThread(): void {
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    const resourceMgr = context.resourceManager;
    // 此处‘example.jpg’仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
    resourceMgr.getRawFd('example.jpg').then(rawFileDescriptor => {
      taskpool.execute(loadPixelMap, rawFileDescriptor).then(pixelMap => {
        if (pixelMap) {
          this.pixelMap = pixelMap as PixelMap;
          console.log('Succeeded in creating pixelMap.');
          // 主线程释放pixelMap。由于子线程返回pixelMap时已调用setTransferDetached，所以此处能够立即释放pixelMap。
          this.pixelMap.release();
        } else {
          console.error('Failed to create pixelMap.');
        }
      });
    });
  }
  build() {
    // ...
  }
}
```

## marshalling<sup>10+</sup>

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
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.            |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixel_map: image.PixelMap;
  constructor(conPixelMap : image.PixelMap) {
    this.pixel_map = conPixelMap;
  }
  marshalling(messageSequence : rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    console.info('marshalling');
    return true;
  }
  unmarshalling(messageSequence : rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel: image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: image.PixelMap) => {
        this.pixel_map = pixelMap;
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
          console.info("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
        })
      })
    });
    return true;
  }
}
async function Marshalling() {
  const color: ArrayBuffer = new ArrayBuffer(96);
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = 0x80;
  }
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: image.PixelMapFormat.BGRA_8888,
    size: { height: 4, width: 6 },
    alphaType: image.AlphaType.UNPREMUL
  }
  let pixelMap: image.PixelMap | undefined = undefined;
  image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
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

## unmarshalling<sup>10+</sup>

unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>

从MessageSequence中获取PixelMap，如需使用同步方式创建PixelMap可使用：[createPixelMapFromParcel](arkts-apis-image-f.md#imagecreatepixelmapfromparcel11)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是   | 保存有PixelMap信息的MessageSequence。      |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> |Promise对象，返回PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.              |
| 62980096 | Operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.         |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixel_map: image.PixelMap;
  constructor(conPixelMap: image.PixelMap) {
    this.pixel_map = conPixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixel_map.marshalling(messageSequence);
    console.info('marshalling');
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height:4, width: 6}}).then((pixelParcel : image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap : image.PixelMap) => {
        this.pixel_map = pixelMap;
        pixelMap.getImageInfo().then((imageInfo : image.ImageInfo) => {
          console.info("unmarshalling information h:" + imageInfo.size.height + "w:" + imageInfo.size.width);
        })
      })
    });
    return true;
  }
}
async function Unmarshalling() {
  const color: ArrayBuffer = new ArrayBuffer(96);
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = 0x80;
  }
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: image.PixelMapFormat.BGRA_8888,
    size: { height: 4, width: 6 },
    alphaType: image.AlphaType.UNPREMUL
  }
  let pixelMap: image.PixelMap | undefined = undefined;
  image.createPixelMap(color, opts).then((srcPixelMap : image.PixelMap) => {
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

## release<sup>7+</sup>

release():Promise\<void>

释放PixelMap对象，使用Promise形式返回释放结果。

ArkTS有内存回收机制，PixelMap对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release() {
  if (pixelMap != undefined) {
    pixelMap.release().then(() => {
      console.info('Succeeded in releasing pixelmap object.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to release pixelmap object. code is ${error.code}, message is ${error.message}`);
    })
  }
}
```

## release<sup>7+</sup>

release(callback: AsyncCallback\<void>): void

释放PixelMap对象，使用callback形式返回释放结果。

ArkTS有内存回收机制，PixelMap对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当对PixelMap对象释放成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release() {
  if (pixelMap != undefined) {
    pixelMap.release((err: BusinessError) => {
      if (err) {
        console.error(`Failed to release pixelmap object. code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info('Succeeded in releasing pixelmap object.');
      }
    })
  }
}
```

## convertPixelFormat<sup>12+</sup>

convertPixelFormat(targetPixelFormat: PixelMapFormat): Promise\<void>

YUV和RGB类型互转，目前仅支持NV12/NV21与RGB888/RGBA8888/RGB565/BGRA8888/RGBAF16互转，YCRCB_P010/YCBCR_P010与RGBA1010102互转。

从API18开始，可用于ASTC_4x4类型转为RGBA_8888类型，目前仅支持ASTC_4x4转为RGBA_8888。

> **注意：**
> 仅在ASTC_4x4格式的图像需要进行像素访问时，建议调用此接口将ASTC_4x4类型转为RGBA_8888类型。由于使用ASTC_4x4反解为RGBA_8888时延较高，其余情况下不推荐使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| targetPixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 是   | 目标像素格式，用于YUV和RGB类型互转，或者ASTC_4x4类型转为RGBA_8888类型。目前仅支持NV12/NV21与RGB888/RGBA8888/RGB565/BGRA8888/RGBAF16互转，YCRCB_P010/YCBCR_P010与RGBA1010102互转，ASTC_4x4转为RGBA_8888。 |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980111 | The image source data is incomplete. |
| 62980115 | Invalid input parameter.              |
| 62980178 | Failed to create the pixelmap. |
| 62980274 | The conversion failed |
| 62980276 | The type to be converted is an unsupported target pixel format|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (pixelMap != undefined) {
  // 设置目标像素格式为NV12。
  let targetPixelFormat = image.PixelMapFormat.NV12;
  pixelMap.convertPixelFormat(targetPixelFormat).then(() => {
    // pixelMap转换成NV12格式成功。
    console.info('PixelMapFormat convert Succeeded');
  }).catch((error: BusinessError) => {
    // pixelMap转换成NV12格式失败。
    console.error(`PixelMapFormat convert Failed. code is ${error.code}, message is ${error.message}`);
  })
}
```

## setMemoryNameSync<sup>13+</sup>

setMemoryNameSync(name: string): void

设置PixelMap内存标识符。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| name | string | 是   | pixelmap内存标识符，只允许DMA和ASHMEM内存形式的piexelmap设置，支持1-31位长度。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.The length of the input parameter is too long. 2.Parameter verification failed. |
| 501 | Resource unavailable. |
| 62980286 | Memory format not supported. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

async function SetMemoryNameSync() {
  if (pixelMap != undefined) {
    try {
      pixelMap.setMemoryNameSync("PixelMapName Test");
    } catch(e) {
      let error = e as BusinessError;
      console.error(`setMemoryNameSync error. code is ${error.code}, message is ${error.message}`);
    }
  }
}
```
