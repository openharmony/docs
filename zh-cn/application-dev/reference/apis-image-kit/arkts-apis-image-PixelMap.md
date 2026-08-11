# Interface (PixelMap)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->

图像像素类，用于读取或写入图像数据以及获取图像信息，同时支持图像变换（缩放、平移、旋转、翻转、裁剪）、设置不透明度、提取Alpha通道、色彩空间设置等操作，适用于图像处理、图像编辑、图像显示等需要进行像素级数据操作的场景。在调用PixelMap的方法前，需要先通过[image.createPixelMapFromPixels](arkts-apis-image-f.md#imagecreatepixelmapfrompixels)或[image.createPixelMapUsingAllocator](arkts-apis-image-f.md#imagecreatepixelmapusingallocator20)系列接口传入像素数据创建一个PixelMap对象，也可以通过[ImageSource](arkts-apis-image-ImageSource.md)进行图片解码创建PixelMap对象。目前PixelMap序列化大小最大为128MiB，超过会渲染失败。PixelMap大小的计算方式为：宽 \* 高 \* 每像素占用字节数（详情请参考[PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7)）。

从API version 11开始，PixelMap支持通过[@ohos.worker (启动一个Worker)](../apis-arkts/js-apis-worker.md)跨线程调用。当PixelMap通过Worker或[@ohos.taskpool (启动任务池)](../apis-arkts/js-apis-taskpool.md)跨线程传输后，原线程的PixelMap的所有接口均不能继续调用，否则将抛出501或7600106（详情请参考[Image错误码](errorcode-image.md)）。

开发原子化服务请通过[ImageSource](arkts-apis-image-ImageSource.md)构建PixelMap对象。

图像占用的内存往往较大，当PixelMap对象使用完成后，应主动调用[release](#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 7开始支持。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称              | 类型    | 只读 | 可选 | 说明                       |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable<sup>7+</sup>        | boolean | 是   | 否   | 图像像素是否可被编辑。true表示可被编辑，false表示不可被编辑。为false时，图像的渲染和传输性能更好。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br>**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。 |
| isStrideAlignment<sup>11+</sup> | boolean | 是   | 否   | 图像的行数据是否已进行内存对齐。true表示已进行内存对齐，每行数据的末尾有空白填充字节以满足对齐要求（如果数据本身已满足对齐要求，则不会有填充字节）；false表示未进行内存对齐，每行数据紧密排列，末尾无空白填充字节。 |

## readAllPixelsToBuffer

readAllPixelsToBuffer(dst: ArrayBuffer): Promise\<void\>

读取整个PixelMap的像素数据，并按照PixelMap的像素格式存入缓冲区。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 目标缓冲区，获取的像素数据会被拷贝至该缓冲区。缓冲区内像素的格式与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小可通过[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readAllPixelsToBuffer(pixelMap: image.PixelMap) {
  const readBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());

  pixelMap.readAllPixelsToBuffer(readBuffer)
    .then(() => {
      console.info('Succeeded in reading pixel data from the PixelMap to readBuffer.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## readAllPixelsToBufferSync

readAllPixelsToBufferSync(dst: ArrayBuffer): void

读取整个PixelMap的像素数据，并按照PixelMap的像素格式存入缓冲区。同步返回结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 目标缓冲区，获取的像素数据会被拷贝至该缓冲区。缓冲区内像素的格式与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readAllPixelsToBufferSync(pixelMap: image.PixelMap) {
  const readBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());

  try {
    pixelMap.readAllPixelsToBufferSync(readBuffer);
    console.info('Succeeded in reading pixel data from the PixelMap to readBuffer.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

读取整个PixelMap的像素数据，并按照PixelMap的像素格式存入缓冲区。使用Promise异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[readAllPixelsToBuffer](#readallpixelstobuffer)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                                                                  |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | 是   | 目标缓冲区，获取的像素数据会被拷贝至该缓冲区。缓冲区内像素的格式与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToBuffer(pixelMap: image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  pixelMap.readPixelsToBuffer(readBuffer).then(() => {
    console.info('Succeeded in reading image pixel data.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to read image pixel data. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

读取整个PixelMap的像素数据，并按照PixelMap的像素格式存入缓冲区。使用callback异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[readAllPixelsToBuffer](#readallpixelstobuffer)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 目标缓冲区，获取的像素数据会被拷贝至该缓冲区。缓冲区内像素的格式与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当读取像素数据到ArrayBuffer成功，err为undefined，否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToBuffer(pixelMap: image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  pixelMap.readPixelsToBuffer(readBuffer, (err: BusinessError, res: void) => {
    if (err) {
      console.error(`Failed to read image pixel data. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in reading image pixel data.');
  });
}
```

## readPixelsToBufferSync<sup>12+</sup>

readPixelsToBufferSync(dst: ArrayBuffer): void

读取整个PixelMap的像素数据，并按照PixelMap的像素格式存入缓冲区。同步返回结果。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[readAllPixelsToBufferSync](#readallpixelstobuffersync)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | 是   | 目标缓冲区，获取的像素数据会被拷贝至该缓冲区。缓冲区内像素的格式与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小由[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToBufferSync(pixelMap: image.PixelMap) {
  const readBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  try {
    pixelMap.readPixelsToBufferSync(readBuffer);
    console.info('Succeeded in reading image pixel data.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read image pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## readPixelsToArea

readPixelsToArea(area: PositionArea): Promise\<void\>

读取PixelMap指定区域内的像素数据并存入缓冲区。如果PixelMap的像素格式为YUV类型，则按照PixelMap的像素格式存入缓冲区，否则按照BGRA_8888格式存入缓冲区。使用Promise异步回调。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：读取区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：读取区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 读取的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，获取的像素数据会被拷贝至[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区。如果PixelMap的像素格式为YUV类型，则获取的像素数据格式与PixelMap相同，否则会被转换为BGRA_8888格式。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToAreaRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8, // 跨距，即每行像素所占的字节数，在没有行末填充字节的情况下取值为：width * 4。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  pixelMap.readPixelsToArea(area)
    .then(() => {
      console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
      console.info('BGRA data: ', new Uint8Array(area.pixels));
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}

function readPixelsToAreaYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 2, // 跨距，即每行像素所占的字节数，在没有行末填充字节的情况下取值为：width * 1（1倍Y分量）。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  pixelMap.readPixelsToArea(area)
    .then(() => {
      console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
      console.info('YUV data: ', new Uint8Array(area.pixels));
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## readPixelsToAreaSync

readPixelsToAreaSync(area: PositionArea): void

读取PixelMap指定区域内的像素数据并存入缓冲区。如果PixelMap的像素格式为YUV类型，则按照PixelMap的像素格式存入缓冲区，否则按照BGRA_8888格式存入缓冲区。同步返回结果。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：读取区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：读取区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 读取的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，获取的像素数据会被拷贝至[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区。如果PixelMap的像素格式为YUV类型，则获取的像素数据格式与PixelMap相同，否则会被转换为BGRA_8888格式。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToAreaSyncRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8, // 跨距，即每行像素所占的字节数，在没有行末填充字节的情况下取值为：width * 4。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  try {
    pixelMap.readPixelsToAreaSync(area);
    console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
    console.info('BGRA data: ', new Uint8Array(area.pixels));
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}

function readPixelsToAreaSyncYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 2, // 跨距，即每行像素所占的字节数，在没有行末填充的字节情况下取值为：width * 1（1倍Y分量）。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  try {
    pixelMap.readPixelsToAreaSync(area);
    console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
    console.info('YUV data: ', new Uint8Array(area.pixels));
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

读取PixelMap指定区域内的像素数据并存入缓冲区。如果PixelMap的像素格式为YUV类型，则按照PixelMap的像素格式存入缓冲区，否则按照BGRA_8888格式存入缓冲区。使用Promise异步回调。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：读取区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：读取区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）
>
> 从API版本26.0.0开始，建议使用[readPixelsToArea](#readpixelstoarea)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 读取的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，获取的像素数据会被拷贝至[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区。如果PixelMap的像素格式为YUV类型，则获取的像素数据格式与PixelMap相同，否则会被转换为BGRA_8888格式。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area).then(() => {
    console.info('Succeeded in reading the image data in the area from the specified area.');
    console.info('BGRA data: ', new Uint8Array(area.pixels));
  }).catch((err: BusinessError) => {
    console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}

function readPixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6),  // 6为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area).then(() => {
    console.info('Succeeded in reading the image data in the area from the specified area.');
    console.info('YUV data: ', new Uint8Array(area.pixels));
  }).catch((err: BusinessError) => {
    console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

读取PixelMap指定区域内的像素数据并存入缓冲区。如果PixelMap的像素格式为YUV类型，则按照PixelMap的像素格式存入缓冲区，否则按照BGRA_8888格式存入缓冲区。使用callback异步回调。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：读取区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：读取区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）
>
> 从API版本26.0.0开始，建议使用[readPixelsToArea](#readpixelstoarea)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                           | 必填 | 说明                           |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 读取的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，获取的像素数据会被拷贝至[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区。如果PixelMap的像素格式为YUV类型，则获取的像素数据格式与PixelMap相同，否则会被转换为BGRA_8888格式。 |
| callback | AsyncCallback\<void>           | 是   |  回调函数。当读取区域内的图片数据成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in reading the image data from the specified area.');
    console.info('BGRA data: ', new Uint8Array(area.pixels));
  });
}

function readPixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in reading the image data from the specified area.');
    console.info('YUV data: ', new Uint8Array(area.pixels));
  });
}
```

## readPixelsSync<sup>12+</sup>

readPixelsSync(area: PositionArea): void

读取PixelMap指定区域内的像素数据并存入缓冲区。如果PixelMap的像素格式为YUV类型，则按照PixelMap的像素格式存入缓冲区，否则按照BGRA_8888格式存入缓冲区。同步返回结果。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：读取区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：读取区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）
>
> 从API版本26.0.0开始，建议使用[readPixelsToAreaSync](#readpixelstoareasync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                     |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 读取的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，获取的像素数据会被拷贝至[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区。如果PixelMap的像素格式为YUV类型，则获取的像素数据格式与PixelMap相同，否则会被转换为BGRA_8888格式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsSync(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  try {
    pixelMap.readPixelsSync(area);
    console.info('Succeeded in reading the image data from the specified area.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writePixelsFromArea

writePixelsFromArea(area: PositionArea): Promise\<void\>

将缓冲区内的像素数据写入PixelMap的指定区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的数据会按照PixelMap的像素格式解析，否则按照BGRA_8888格式解析。使用Promise异步回调。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：写入区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：写入区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 写入的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区内的像素数据会被写入PixelMap的该区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的像素数据格式需与PixelMap相同，否则需要为BGRA_8888格式。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsFromAreaRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8, // 跨距，即每行像素所占的字节数，在没有行末填充字节的情况下取值为：width * 4。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // 数据源的格式必须是BGRA_8888，下列数组索引依次为：B通道、G通道、R通道、A通道。
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  pixelMap.writePixelsFromArea(area)
    .then(() => {
      console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}

function writePixelsFromAreaYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 2, // PixelMap为YUV格式时，writePixelsFromArea函数不使用该变量。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  const ySize = area.region.size.width * area.region.size.height;
  for (let i = 0; i < ySize; i++) { // Y平面。
    bufferArr[i] = 0xFF;
  }
  for (let i = ySize; i < bufferArr.length; i++) { // UV交错平面。
    bufferArr[i] = 0x80;
  }

  pixelMap.writePixelsFromArea(area)
    .then(() => {
      console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## writePixelsFromAreaSync

writePixelsFromAreaSync(area: PositionArea): void

将缓冲区内的像素数据写入PixelMap的指定区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的数据会按照PixelMap的像素格式解析，否则按照BGRA_8888格式解析。同步返回结果。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：写入区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：写入区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                                                                  |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 写入的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区内的像素数据会被写入PixelMap的该区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的像素数据格式需与PixelMap相同，否则需要为BGRA_8888格式。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsFromAreaSyncRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8, // 跨距，即每行像素所占的字节数，在没有行末填充字节的情况下取值为：width * 4。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // 数据源的格式必须是BGRA_8888，下列数组索引依次为：B通道、G通道、R通道、A通道。
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  try {
    pixelMap.writePixelsFromAreaSync(area);
    console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}

function writePixelsFromAreaSyncYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 2, // PixelMap为YUV格式时，writePixelsFromAreaSync函数不使用该变量。
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  const ySize = area.region.size.width * area.region.size.height;
  for (let i = 0; i < ySize; i++) { // Y平面。
    bufferArr[i] = 0xFF;
  }
  for (let i = ySize; i < bufferArr.length; i++) { // UV交错平面。
    bufferArr[i] = 0x80;
  }

  try {
    pixelMap.writePixelsFromAreaSync(area);
    console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writePixels<sup>7+</sup>

writePixels(area: PositionArea): Promise\<void>

将缓冲区内的像素数据写入PixelMap的指定区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的数据会按照PixelMap的像素格式解析，否则按照BGRA_8888格式解析。使用Promise异步回调。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：写入区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：写入区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）
>
> 从API版本26.0.0开始，建议使用[writePixelsFromArea](#writepixelsfromarea)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 写入的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区内的像素数据会被写入PixelMap的该区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的像素数据格式需与PixelMap相同，否则需要为BGRA_8888格式。 |

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area).then(() => {
    console.info('Succeeded in writing pixels into the specified area.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}

function writePixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 8, // PixelMap为YUV格式时，writePixels函数不使用该变量。
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area).then(() => {
    console.info('Succeeded in writing pixels into the specified area.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

将缓冲区内的像素数据写入PixelMap的指定区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的数据会按照PixelMap的像素格式解析，否则按照BGRA_8888格式解析。使用callback异步回调。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：写入区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：写入区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）
>
> 从API版本26.0.0开始，建议使用[writePixelsFromArea](#writepixelsfromarea)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名    | 类型                           | 必填 | 说明                           |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 写入的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区内的像素数据会被写入PixelMap的该区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的像素数据格式需与PixelMap相同，否则需要为BGRA_8888格式。 |
| callback  | AsyncCallback\<void>           | 是   | 回调函数，当写入成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8为需要创建的像素缓冲区大小，取值为：width * height * 4。
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in writing pixels into the specified area.');
  });
}

function writePixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6为需要创建的像素缓冲区大小，取值为：width * height * 1.5。
    offset: 0,
    stride: 8, // PixelMap为YUV格式时，writePixels函数不使用该变量。
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in writing pixels into the specified area.');
  });
}
```

## writePixelsSync<sup>12+</sup>

writePixelsSync(area: PositionArea): void

将缓冲区内的像素数据写入PixelMap的指定区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的数据会按照PixelMap的像素格式解析，否则按照BGRA_8888格式解析。同步返回结果。

> **说明：**
>
> 可使用公式计算PositionArea需要申请的缓冲区大小。
>
> - RGBA的区域计算公式：写入区域像素数量（Region.size {width * height}）* 4（1倍R分量 + 1倍G分量 + 1倍B分量 + 1倍A分量）
> - YUV的区域计算公式：写入区域像素数量（Region.size {width * height}）* 1.5（1倍Y分量 + 0.25倍U分量 + 0.25倍V分量）
>
> 从API版本26.0.0开始，建议使用[writePixelsFromAreaSync](#writepixelsfromareasync)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                           | 必填 | 说明                 |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | 是   | 写入的区域数据。<br>该区域由[PositionArea](arkts-apis-image-i.md#positionarea7).region指定，[PositionArea](arkts-apis-image-i.md#positionarea7).pixels缓冲区内的像素数据会被写入PixelMap的该区域。如果PixelMap的像素格式为YUV类型，则缓冲区内的像素数据格式需与PixelMap相同，否则需要为BGRA_8888格式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsSync(pixelMap: image.PixelMap) {
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
  try {
    pixelMap.writePixelsSync(area);
    console.info('Succeeded in writing pixels into the specified area.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writeAllPixelsFromBuffer

writeAllPixelsFromBuffer(src: ArrayBuffer): Promise\<void\>

将缓冲区内的像素数据写入整个PixelMap。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| src      | ArrayBuffer          | 是   | 源数据缓冲区，该缓冲区内的图像像素数据会被写入PixelMap。缓冲区内的像素数据必须是整个PixelMap的像素数据，且像素格式需与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小可通过[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeAllPixelsFromBuffer(pixelMap: image.PixelMap) {
  const writeBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  const bufferArr = new Uint8Array(writeBuffer);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // 假设pixelMap的像素格式为RGBA_8888，则下列数组索引依次为：R通道、G通道、B通道、A通道。
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  pixelMap.writeAllPixelsFromBuffer(writeBuffer)
    .then(() => {
      console.info('Succeeded in writing pixel data from writeBuffer to the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## writeAllPixelsFromBufferSync

writeAllPixelsFromBufferSync(src: ArrayBuffer): void

将缓冲区内的像素数据写入整个PixelMap。同步返回结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| src      | ArrayBuffer          | 是   | 源数据缓冲区，该缓冲区内的图像像素数据会被写入PixelMap。缓冲区内的像素数据必须是整个PixelMap的像素数据，且像素格式需与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小可通过[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeAllPixelsFromBufferSync(pixelMap: image.PixelMap) {
  const writeBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  const bufferArr = new Uint8Array(writeBuffer);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // 假设pixelMap的像素格式为RGBA_8888，则下列数组索引依次为：R通道、G通道、B通道、A通道。
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  try {
    pixelMap.writeAllPixelsFromBufferSync(writeBuffer);
    console.info('Succeeded in writing pixel data from writeBuffer to the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

将缓冲区内的像素数据写入整个PixelMap。使用Promise异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[writeAllPixelsFromBuffer](#writeallpixelsfrombuffer)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明           |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | 是   | 源数据缓冲区，该缓冲区内的图像像素数据会被写入PixelMap。缓冲区内的像素数据必须是整个PixelMap的像素数据，且像素格式需与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小可通过[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeBufferToPixels(pixelMap: image.PixelMap) {
  const color: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writeBufferToPixels(color).then(() => {
    console.info('Succeeded in writing data from the buffer to the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to write data from the buffer to the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

将缓冲区内的像素数据写入整个PixelMap。使用callback异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[writeAllPixelsFromBuffer](#writeallpixelsfrombuffer)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | 是   | 源数据缓冲区，该缓冲区内的图像像素数据会被写入PixelMap。缓冲区内的像素数据必须是整个PixelMap的像素数据，且像素格式需与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小可通过[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当缓冲区中的图像像素数据写入PixelMap成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeBufferToPixels(pixelMap: image.PixelMap) {
  const color: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writeBufferToPixels(color, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to write data from the buffer to the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in writing data from the buffer to the PixelMap.');
  });
}
```

## writeBufferToPixelsSync<sup>12+</sup>

writeBufferToPixelsSync(src: ArrayBuffer): void

将缓冲区内的像素数据写入整个PixelMap。同步返回结果。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[writeAllPixelsFromBufferSync](#writeallpixelsfrombuffersync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明           |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | 是   | 源数据缓冲区，该缓冲区内的图像像素数据会被写入PixelMap。缓冲区内的像素数据必须是整个PixelMap的像素数据，且像素格式需与PixelMap相同，不包含内存对齐填充字节。缓冲区的大小可通过[getPixelBytesNumber](#getpixelbytesnumber7)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeBufferToPixelsSync(pixelMap: image.PixelMap) {
  const color: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  try {
    pixelMap.writeBufferToPixelsSync(color);
    console.info('Succeeded in writing data from the buffer to the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write data from the buffer to the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getImageInfo<sup>7+</sup>

getImageInfo(): Promise\<ImageInfo>

获取图像像素信息。使用Promise异步回调。

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

function getImageInfo(pixelMap: image.PixelMap) {
  pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
    console.info(`Succeeded in obtaining information of the PixelMap with size ${imageInfo.size} and pixel format ${imageInfo.pixelFormat}.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain information of the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## getImageInfo<sup>7+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

获取图像像素信息。使用callback异步回调。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | 是   | 回调函数。当获取图像像素信息成功，err为undefined，data为获取到的图像像素信息；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getImageInfo(pixelMap: image.PixelMap) {
  pixelMap.getImageInfo((err: BusinessError, imageInfo: image.ImageInfo) => {
    if (err) {
      console.error(`Failed to obtain information of the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in obtaining information of the PixelMap with size ${imageInfo.size} and pixel format ${imageInfo.pixelFormat}.`);
  });
}
```

## getImageInfoSync<sup>12+</sup>

getImageInfoSync(): ImageInfo

获取图像像素信息。同步返回结果。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型                              | 说明                                                        |
| --------------------------------- | ----------------------------------------------------------- |
| [ImageInfo](arkts-apis-image-i.md#imageinfo)           | 图像像素信息。                          |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getImageInfoSync(pixelMap: image.PixelMap) {
  try {
    let imageInfo: image.ImageInfo = pixelMap.getImageInfoSync();
    console.info(`Succeeded in obtaining information of the PixelMap with size ${imageInfo.size} and pixel format ${imageInfo.pixelFormat}.`);
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to obtain information of the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getBytesNumberPerRow<sup>7+</sup>

getBytesNumberPerRow(): number

获取图像每行像素的字节数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的行字节数。单位：字节（Byte）。 |

**示例：**

```ts
function getBytesNumberPerRow(pixelMap: image.PixelMap) {
  let rowBytes: number = pixelMap.getBytesNumberPerRow();
}
```

## getPixelBytesNumber<sup>7+</sup>

getPixelBytesNumber(): number

获取图像所有像素占用的总字节数，不包含内存对齐填充字节。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 图像像素的总字节数。单位：字节（Byte）。 |

**示例：**

```ts
function getPixelBytesNumber(pixelMap: image.PixelMap) {
  let pixelBytesNumber: number = pixelMap.getPixelBytesNumber();
}
```

## getDensity<sup>9+</sup>

getDensity(): number

获取图像的像素密度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明            |
| ------ | --------------- |
| number | 图像的像素密度，单位：ppi（像素/英寸）。|

**示例：**

```ts
function getDensity(pixelMap: image.PixelMap) {
  let density: number = pixelMap.getDensity();
}
```

## setOpacity

setOpacity(value: number): Promise\<void\>

设置PixelMap的不透明度，指定的不透明度值将被应用于所有像素，不受原图不透明度的影响。YUV格式的图像不支持设置不透明度。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                 |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------- |
| value    | number               | 是   | 不透明度值。取值范围是(0.0, 1.0]，1.0表示完全不透明，数值越接近0.0则透明度越高。                           |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. Possible cause: The specified value is out of range. |
| 7600207 | Unsupported data format. Possible cause: Alpha type is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setOpacity(pixelMap: image.PixelMap) {
  const opacity: number = 0.5;
  pixelMap.setOpacity(opacity)
    .then(() => {
      console.info('Succeeded in setting opacity.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## setOpacitySync

setOpacitySync(value: number): void

设置PixelMap的不透明度，指定的不透明度值将被应用于所有像素，不受原图不透明度的影响。YUV格式的图像不支持设置不透明度。同步返回结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                 |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------- |
| value    | number               | 是   | 不透明度值。取值范围是(0.0, 1.0]，1.0表示完全不透明，数值越接近0.0则透明度越高。                           |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. Possible cause: The specified value is out of range. |
| 7600207 | Unsupported data format. Possible cause: Alpha type is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setOpacitySync(pixelMap: image.PixelMap) {
  const opacity: number = 0.5;
  try {
    pixelMap.setOpacitySync(opacity);
    console.info('Succeeded in setting opacity.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## opacity<sup>9+</sup>

opacity(rate: number, callback: AsyncCallback\<void>): void

设置PixelMap的不透明度，指定的不透明度值将被应用于所有像素，不受原图不透明度的影响。YUV格式的图像不支持设置不透明度。使用callback异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[setOpacity](#setopacity)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | 是   | 不透明度的值，取值范围是(0, 1]。1.0表示完全不透明，数值越接近0.0则透明度越高。  |
| callback | AsyncCallback\<void> | 是   | 回调函数。当设置透明比率成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function opacity(pixelMap: image.PixelMap) {
  const rate: number = 0.5;
  pixelMap.opacity(rate, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in setting opacity.");
  });
}
```

## opacity<sup>9+</sup>

opacity(rate: number): Promise\<void>

设置PixelMap的不透明度，指定的不透明度值将被应用于所有像素，不受原图不透明度的影响。YUV格式的图像不支持设置不透明度。使用Promise异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[setOpacity](#setopacity)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | 是   | 不透明度的值，取值范围是(0, 1]。1.0表示完全不透明，数值越接近0.0则透明度越高。|

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function opacity(pixelMap: image.PixelMap) {
  const rate: number = 0.5;
  pixelMap.opacity(rate).then(() => {
    console.info('Succeeded in setting opacity.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## opacitySync<sup>12+</sup>

opacitySync(rate: number): void

设置PixelMap的不透明度，指定的不透明度值将被应用于所有像素，不受原图不透明度的影响。YUV格式的图像不支持设置不透明度。同步返回结果。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[setOpacitySync](#setopacitysync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | 是   | 不透明度的值，取值范围是(0, 1]。1.0表示完全不透明，数值越接近0.0则透明度越高。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function opacitySync(pixelMap: image.PixelMap) {
  const rate: number = 0.5;
  try {
    pixelMap.opacitySync(rate);
    console.info('Succeeded in setting opacity.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## extractAlphaPixelMap

extractAlphaPixelMap(): Promise\<PixelMap\>

提取当前PixelMap的Alpha通道数据，并生成一个仅包含Alpha通道信息的ALPHA_U8格式的PixelMap。生成的新PixelMap不可编辑，可用于阴影效果。YUV格式不支持此接口。使用Promise异步回调。

> **说明：**
>
> 若原PixelMap的格式是ALPHA_F16，则新生成的PixelMap将维持ALPHA_F16格式。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                                             |
| -------------- | ------------------------------------------------ |
| Promise\<PixelMap\> | Promise对象，返回仅包含Alpha通道信息的ALPHA_U8格式的PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The current PixelMap has been released. |
| 7600106 | The current PixelMap has been passed across threads. |
| 7600305 | Failed to create the PixelMap. Possible cause: Current PixelMap data is corrupted. |
| 7600306 | Failed to convert the data. Possible causes: 1. Failed to perform pixel format conversion. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function extractAlphaPixelMap(pixelMap: image.PixelMap) {
  pixelMap.extractAlphaPixelMap()
    .then((alphaMap: image.PixelMap) => {
      console.info('Succeeded in creating alpha PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## extractAlphaPixelMapSync

extractAlphaPixelMapSync(): PixelMap

提取当前PixelMap的Alpha通道数据，并生成一个仅包含Alpha通道信息的ALPHA_U8格式的PixelMap。生成的新PixelMap不可编辑，可用于阴影效果。YUV格式不支持此接口。同步返回结果。

> **说明：**
>
> 若原PixelMap的格式是ALPHA_F16，则新生成的PixelMap将维持ALPHA_F16格式。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                                             |
| -------------- | ----------------------------------------------- |
| PixelMap       | 返回仅包含Alpha通道信息的ALPHA_U8格式的PixelMap。  |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The current PixelMap has been released. |
| 7600106 | The current PixelMap has been passed across threads. |
| 7600305 | Failed to create the PixelMap. Possible cause: Current PixelMap data is corrupted. |
| 7600306 | Failed to convert the data. Possible causes: 1. Failed to perform pixel format conversion. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function extractAlphaPixelMapSync(pixelMap: image.PixelMap) {
  try {
    const alphaMap = pixelMap.extractAlphaPixelMapSync();
    console.info('Succeeded in creating alpha PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

根据Alpha通道的信息，生成一个仅包含Alpha通道信息的ALPHA_8格式的PixelMap，生成的新PixelMap不可编辑，可用于阴影效果。YUV格式不支持此接口。使用Promise异步回调。

> **说明：**
>
> - 若原PixelMap的格式是ALPHA_F16，则新生成的PixelMap将维持ALPHA_F16格式。
> - 从API版本26.0.0开始，建议使用[extractAlphaPixelMap](#extractalphapixelmap)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                        |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回仅包含Alpha通道信息的ALPHA_8格式的PixelMap。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createAlphaPixelmap(pixelMap: image.PixelMap) {
  pixelMap.createAlphaPixelmap().then((alphaPixelMap: image.PixelMap) => {
    console.info('Succeeded in creating alpha PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void

根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的ALPHA_8格式的PixelMap，生成的新PixelMap不可编辑，可用于阴影效果。YUV格式不支持此接口。使用callback异步回调。

> **说明：**
>
> - 若原PixelMap的格式是ALPHA_F16，则新生成的PixelMap将维持ALPHA_F16格式。
> - 从API版本26.0.0开始，建议使用[extractAlphaPixelMap](#extractalphapixelmap)代替，以获得更完善的异常处理能力。

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

function createAlphaPixelmap(pixelMap: image.PixelMap) {
  pixelMap.createAlphaPixelmap((err: BusinessError, alphaPixelMap: image.PixelMap) => {
    if (err) {
      console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in creating alpha PixelMap.');
  });
}
```

## createAlphaPixelmapSync<sup>12+</sup>

createAlphaPixelmapSync(): PixelMap

根据Alpha通道的信息，生成一个仅包含Alpha通道信息的ALPHA_8格式的PixelMap，生成的新PixelMap不可编辑，可用于阴影效果。YUV格式不支持此接口。同步返回结果。

> **说明：**
>
> - 若原PixelMap的格式是ALPHA_F16，则新生成的PixelMap将维持ALPHA_F16格式。
> - 从API版本26.0.0开始，建议使用[extractAlphaPixelMapSync](#extractalphapixelmapsync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功同步返回仅包含Alpha通道信息的ALPHA_8格式的PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createAlphaPixelmapSync(pixelMap: image.PixelMap) {
  try {
    let alphaPixelMap: image.PixelMap = pixelMap.createAlphaPixelmapSync();
    if (alphaPixelMap == undefined) {
      console.error(`Failed to create alpha PixelMap.`);
      return;
    }
    console.info('Succeeded in creating alpha PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyScale

applyScale(x: number, y: number, level?: AntiAliasingLevel): Promise\<void\>

根据指定的宽高缩放倍数和缩放算法对PixelMap进行缩放。使用Promise异步回调。

> **说明：**
>
> - 建议宽高的缩放倍数取正数，否则会产生翻转效果。
> - 缩放倍数 = 缩放后的图像尺寸 / 缩放前的图像尺寸。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------- |
| x        | number               | 是   | 宽度的缩放倍数。取值不能为0。                                |
| y        | number               | 是   | 高度的缩放倍数。取值不能为0。                                |
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法。该参数对于ASTC格式的PixelMap不生效。默认值为AntiAliasingLevel.NONE。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyScale(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.5;
  pixelMap.applyScale(scaleX, scaleY, image.AntiAliasingLevel.LOW)
    .then(() => {
      console.info('Succeeded in scaling the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyScaleSync

applyScaleSync(x: number, y: number, level?: AntiAliasingLevel): void

根据指定的宽高缩放倍数和缩放算法对PixelMap进行缩放。同步返回结果。

> **说明：**
>
> - 建议宽高的缩放倍数取正数，否则会产生翻转效果。
> - 缩放倍数 = 缩放后的图像尺寸 / 缩放前的图像尺寸。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------- |
| x        | number               | 是   | 宽度的缩放倍数。取值不能为0。                                |
| y        | number               | 是   | 高度的缩放倍数。取值不能为0。                                |
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法。该参数对于ASTC格式的PixelMap不生效。默认值为AntiAliasingLevel.NONE。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyScaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.5;
  try {
    pixelMap.applyScaleSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
    console.info('Succeeded in scaling the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## scale<sup>9+</sup>

scale(x: number, y: number, callback: AsyncCallback\<void>): void

根据输入的宽高的缩放倍数对图片进行缩放。使用callback异步回调。

> **说明：**
>
> - 建议宽高的缩放倍数取正数，否则会产生翻转效果。
> - 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。
> - 从API版本26.0.0开始，建议使用[applyScale](#applyscale)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | 是   | 宽度的缩放倍数。取值不能为0。 |
| y        | number               | 是   | 高度的缩放倍数。取值不能为0。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图片进行缩放成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scale(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.scale(scaleX, scaleY, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in scaling the PixelMap.");
  });
}
```

## scale<sup>9+</sup>

scale(x: number, y: number): Promise\<void>

根据输入的宽高的缩放倍数对图片进行缩放。使用Promise异步回调。

> **说明：**
>
> - 建议宽高的缩放倍数取正数，否则会产生翻转效果。
> - 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。
> - 从API版本26.0.0开始，建议使用[applyScale](#applyscale)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y      | number | 是   | 高度的缩放倍数。取值不能为0。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scale(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.scale(scaleX, scaleY).then(() => {
    console.info('Succeeded in scaling the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## scaleSync<sup>12+</sup>

scaleSync(x: number, y: number): void

根据输入的宽高的缩放倍数对图片进行缩放。同步返回结果。

> **说明：**
>
> - 建议宽高的缩放倍数取正数，否则会产生翻转效果。
> - 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。
> - 从API版本26.0.0开始，建议使用[applyScaleSync](#applyscalesync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y      | number | 是   | 高度的缩放倍数。取值不能为0。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  try {
    pixelMap.scaleSync(scaleX, scaleY);
    console.info('Succeeded in scaling the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## scale<sup>12+</sup>

scale(x: number, y: number, level: AntiAliasingLevel): Promise\<void>

根据指定的缩放算法和输入的宽高的缩放倍数对图片进行缩放。使用Promise异步回调。

> **说明：**
>
> - 建议宽高的缩放倍数取正数，否则会产生翻转效果。
> - 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。
> - 从API版本26.0.0开始，建议使用[applyScale](#applyscale)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y      | number | 是   | 高度的缩放倍数。取值不能为0。 |
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 是   | 采用的缩放算法。该参数对于ASTC格式的PixelMap不生效。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.scale(scaleX, scaleY, image.AntiAliasingLevel.LOW).then(() => {
    console.info('Succeeded in scaling the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## scaleSync<sup>12+</sup>

scaleSync(x: number, y: number, level: AntiAliasingLevel): void

根据指定的缩放算法和输入的宽高的缩放倍数对图片进行缩放。同步返回结果。

> **说明：**
>
> - 建议宽高的缩放倍数取正数，否则会产生翻转效果。
> - 宽高的缩放倍数 = 缩放后的图片宽高 / 缩放前的图片宽高。
> - 从API版本26.0.0开始，建议使用[applyScaleSync](#applyscalesync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y      | number | 是   | 高度的缩放倍数。取值不能为0。 |
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 是   | 采用的缩放算法。该参数对于ASTC格式的PixelMap不生效。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  try {
    pixelMap.scaleSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
    console.info('Succeeded in scaling the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## createScaledPixelMap<sup>18+</sup>

createScaledPixelMap(x: number, y: number, level?: AntiAliasingLevel): Promise\<PixelMap>

根据指定的缩放算法和输入的宽高的缩放倍数，基于当前PixelMap创建一个新的缩放后的PixelMap，生成的新PixelMap不可编辑。使用Promise异步回调。

> **说明：**
>
> 该接口不会拷贝原图像的HDR元数据和EXIF信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y      | number | 是   | 高度的缩放倍数。取值不能为0。 |
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法，默认值为AntiAliasingLevel.NONE。该参数对于ASTC格式的PixelMap不生效。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回缩放后的PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createScaledPixelMap(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.createScaledPixelMap(scaleX, scaleY, image.AntiAliasingLevel.LOW).then((scaledPixelMap: image.PixelMap) => {
    console.info('Succeeded in creating scaled PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## createScaledPixelMapSync<sup>18+</sup>

createScaledPixelMapSync(x: number, y: number, level?: AntiAliasingLevel): PixelMap

根据指定的缩放算法和输入的宽高的缩放倍数，基于当前PixelMap创建一个新的缩放后的PixelMap，生成的新PixelMap不可编辑。同步返回结果。

> **说明：**
>
> 该接口不会拷贝原图像的HDR元数据和EXIF信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y      | number | 是   | 高度的缩放倍数。取值不能为0。 |
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法，默认值为AntiAliasingLevel.NONE。该参数对于ASTC格式的PixelMap不生效。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功同步返回缩放后的PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createScaledPixelMapSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  try {
    let scaledPixelMap = pixelMap.createScaledPixelMapSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
    console.info('Succeeded in creating scaled PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## createCroppedAndScaledPixelMap<sup>22+</sup>

createCroppedAndScaledPixelMap(region: Region, x: number, y: number, level?: AntiAliasingLevel): Promise\<PixelMap\>

根据指定的裁剪区域、宽高的缩放倍数和缩放算法，基于当前PixelMap创建一个新的裁剪并缩放后的PixelMap。使用Promise异步回调。

> **说明：**
>
> 该接口不会拷贝原图像的EXIF信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | ------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8) | 是   | 裁剪的区域。取值范围不能超过图片的宽和高。单位：像素（px）。 |
| x        | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y        | number | 是   | 高度的缩放倍数。取值不能为0。 |
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法。默认值为AntiAliasingLevel.NONE。该参数对于ASTC格式的PixelMap不生效。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)\> | Promise对象，返回裁剪并缩放后的PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 7600201 | The PixelMap has been released. |
| 7600204 | Invalid region. |
| 7600205 | Unsupported memory format or pixel format. |
| 7600301 | Memory alloc failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createCroppedAndScaledPixelMap(pixelMap: image.PixelMap) {
  const imageInfo = pixelMap.getImageInfoSync();
  const region: image.Region = {
    size: { width: imageInfo.size.width / 2, height: imageInfo.size.height / 2 },
    x: imageInfo.size.width / 4,
    y: imageInfo.size.height / 4
  };
  const scaleX: number = 2.0;
  const scaleY: number = 2.0;
  pixelMap.createCroppedAndScaledPixelMap(region, scaleX, scaleY, image.AntiAliasingLevel.HIGH)
    .then((croppedAndScaled: image.PixelMap) => {
      console.info('Succeeded in creating cropped and scaled PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to create cropped and scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## createCroppedAndScaledPixelMapSync<sup>22+</sup>

createCroppedAndScaledPixelMapSync(region: Region, x: number, y: number, level?: AntiAliasingLevel): PixelMap

根据指定的裁剪区域、宽高的缩放倍数和缩放算法，基于当前PixelMap创建一个新的裁剪并缩放后的PixelMap。同步返回结果。

> **说明：**
>
> 该接口不会拷贝原图像的EXIF信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | ------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8) | 是   | 裁剪的区域。取值范围不能超过图片的宽和高。单位：像素（px）。 |
| x        | number | 是   | 宽度的缩放倍数。取值不能为0。 |
| y        | number | 是   | 高度的缩放倍数。取值不能为0。 |
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | 否   | 采用的缩放算法。默认值为AntiAliasingLevel.NONE。该参数对于ASTC格式的PixelMap不生效。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功则同步返回裁剪并缩放后的PixelMap对象，失败则抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 7600201 | The PixelMap has been released. |
| 7600204 | Invalid region. |
| 7600205 | Unsupported memory format or pixel format. |
| 7600301 | Memory alloc failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createCroppedAndScaledPixelMapSync(pixelMap: image.PixelMap) {
  const imageInfo = pixelMap.getImageInfoSync();
  const region: image.Region = {
    size: { width: imageInfo.size.width / 2, height: imageInfo.size.height / 2 },
    x: imageInfo.size.width / 4,
    y: imageInfo.size.height / 4
  };
  const scaleX: number = 2.0;
  const scaleY: number = 2.0;
  try {
    const croppedAndScaled = pixelMap.createCroppedAndScaledPixelMapSync(region, scaleX, scaleY, image.AntiAliasingLevel.HIGH);
    console.info('Succeeded in creating cropped and scaled PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create cropped and scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## clone<sup>18+</sup>

clone(): Promise\<PixelMap>

拷贝一份当前的PixelMap对象。使用Promise异步回调。

> **说明：**
>
> 该接口不会拷贝原图像的EXIF信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回拷贝的PixelMap。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of creating empty pixelmap. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function clone(pixelMap: image.PixelMap) {
  pixelMap.clone().then((clonedPixelMap: image.PixelMap) => {
    console.info('Succeeded in cloning the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to clone the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## cloneSync<sup>18+</sup>

cloneSync(): PixelMap

拷贝一份当前的PixelMap对象。同步返回结果。

> **说明：**
>
> 该接口不会拷贝原图像的EXIF信息。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 成功同步返回拷贝的PixelMap对象，失败抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of creating empty pixelmap. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function cloneSync(pixelMap: image.PixelMap) {
  try {
    let clonedPixelMap: image.PixelMap = pixelMap.cloneSync();
    console.info('Succeeded in cloning the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to clone the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyTranslate

applyTranslate(x: number, y: number): Promise\<void\>

根据指定的横向和纵向距离对PixelMap进行平移。使用Promise异步回调。

> **说明：**
>
> 平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| x        | number               | 是   | 横向平移的距离。方向为正数向右，负数向左。取值范围是(-图像宽度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像左侧起的x列像素。 |
| y        | number               | 是   | 纵向平移的距离。方向为正数向下，负数向上。取值范围是(-图像高度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像上方起的y行像素。 |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyTranslate(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  pixelMap.applyTranslate(translateX, translateY)
    .then(() => {
      console.info('Succeeded in translating the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyTranslateSync

applyTranslateSync(x: number, y: number): void

根据指定的横向和纵向距离对PixelMap进行平移。同步返回结果。

> **说明：**
>
> 平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| x        | number               | 是   | 横向平移的距离。方向为正数向右，负数向左。取值范围是(-图像宽度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像左侧起的x列像素。 |
| y        | number               | 是   | 纵向平移的距离。方向为正数向下，负数向上。取值范围是(-图像高度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像上方起的y行像素。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyTranslateSync(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  try {
    pixelMap.applyTranslateSync(translateX, translateY);
    console.info('Succeeded in translating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## translate<sup>9+</sup>

translate(x: number, y: number, callback: AsyncCallback\<void>): void

根据输入的坐标对图片进行位置变换。使用callback异步回调。

> **说明：**
>
> - 平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。
> - 从API版本26.0.0开始，建议使用[applyTranslate](#applytranslate)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| x        | number               | 是   | 横向平移的距离。方向为正数向右，负数向左。取值范围是(-图像宽度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像左侧起的x列像素。 |
| y        | number               | 是   | 纵向平移的距离。方向为正数向下，负数向上。取值范围是(-图像高度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像上方起的y行像素。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图片进行位置变换成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function translate(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  pixelMap.translate(translateX, translateY, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in translating the PixelMap.");
  });
}
```

## translate<sup>9+</sup>

translate(x: number, y: number): Promise\<void>

根据输入的坐标对图片进行位置变换。使用Promise异步回调。

> **说明：**
>
> - 平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。
> - 从API版本26.0.0开始，建议使用[applyTranslate](#applytranslate)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明        |
| ------ | ------ | ---- | ----------- |
| x        | number               | 是   | 横向平移的距离。方向为正数向右，负数向左。取值范围是(-图像宽度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像左侧起的x列像素。 |
| y        | number               | 是   | 纵向平移的距离。方向为正数向下，负数向上。取值范围是(-图像高度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像上方起的y行像素。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function translate(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  pixelMap.translate(translateX, translateY).then(() => {
    console.info('Succeeded in translating the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## translateSync<sup>12+</sup>

translateSync(x: number, y: number): void

根据输入的坐标对图片进行位置变换。同步返回结果。

> **说明：**
>
> - 平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。
> - 从API版本26.0.0开始，建议使用[applyTranslateSync](#applytranslatesync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | 是   | 横向平移的距离。方向为正数向右，负数向左。取值范围是(-图像宽度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像左侧起的x列像素。 |
| y        | number               | 是   | 纵向平移的距离。方向为正数向下，负数向上。取值范围是(-图像高度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像上方起的y行像素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function translateSync(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  try {
    pixelMap.translateSync(translateX, translateY);
    console.info('Succeeded in translating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyRotate

applyRotate(angle: number): Promise\<void\>

根据指定的角度对PixelMap进行旋转。YUV格式仅支持90°倍数的旋转角。使用Promise异步回调。

> **说明：**
>
> - 图像旋转角度的取值范围为[0, 360]。超出取值范围时，将根据圆周360°自动矫正。例如，-100°与260°效果相同。
> - 当旋转角度不是90°的倍数时，图像的尺寸会扩大为旋转后的外接矩形尺寸，以容纳旋转后的图像内容。例如：正方形图像旋转45°后，输出图像的尺寸（边长）变为原图像的√2倍。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| angle    | number               | 是   | 旋转的角度。方向为正数顺时针，负数逆时针。单位：角度（°）。                                  |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyRotate(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  pixelMap.applyRotate(angle)
    .then(() => {
      console.info('Succeeded in rotating the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyRotateSync

applyRotateSync(angle: number): void

根据指定的角度对PixelMap进行旋转。YUV格式仅支持90°倍数的旋转角。同步返回结果。

> **说明：**
>
> - 图像旋转角度的取值范围为[0, 360]。超出取值范围时，将根据圆周360°自动矫正。例如，-100°与260°效果相同。
> - 当旋转角度不是90°的倍数时，图像的尺寸会扩大为旋转后的外接矩形尺寸，以容纳旋转后的图像内容。例如：正方形图像旋转45°后，输出图像的尺寸（边长）变为原图像的√2倍。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| angle    | number               | 是   | 旋转的角度。方向为正数顺时针，负数逆时针。单位：角度（°）。                                  |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyRotateSync(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  try {
    pixelMap.applyRotateSync(angle);
    console.info('Succeeded in rotating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## rotate<sup>9+</sup>

rotate(angle: number, callback: AsyncCallback\<void>): void

根据输入的角度对图片进行旋转，YUV格式仅支持90°倍数的旋转角。使用callback异步回调。

> **说明：**
>
> - 图像旋转的角度取值范围：[0, 360]。超出取值范围时，根据圆周360°自动矫正。例如，-100°与260°效果相同。
> - 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。
> - 从API版本26.0.0开始，建议使用[applyRotate](#applyrotate)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | 是   | 图像旋转的角度。方向为正数顺时针，负数逆时针。单位：角度（°）。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图片进行旋转成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function rotate(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  pixelMap.rotate(angle, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in rotating the PixelMap.");
  });
}
```

## rotate<sup>9+</sup>

rotate(angle: number): Promise\<void>

根据输入的角度对图片进行旋转，YUV格式仅支持90°倍数的旋转角。使用Promise异步回调。

> **说明：**
>
> - 图像旋转的角度取值范围：[0, 360]。超出取值范围时，根据圆周360°自动矫正。例如，-100°与260°效果相同。
> - 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。
> - 从API版本26.0.0开始，建议使用[applyRotate](#applyrotate)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                          |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | 是   | 图像旋转的角度。方向为正数顺时针，负数逆时针。单位：角度（°）。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function rotate(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  pixelMap.rotate(angle).then(() => {
    console.info('Succeeded in rotating the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## rotateSync<sup>12+</sup>

rotateSync(angle: number): void

根据输入的角度对图片进行旋转，YUV格式仅支持90°倍数的旋转角。同步返回结果。

> **说明：**
>
> - 图像旋转的角度取值范围：[0, 360]。超出取值范围时，根据圆周360°自动矫正。例如，-100°与260°效果相同。
> - 如果图片旋转的角度不是90的整数倍，旋转后图片的尺寸会发生改变。
> - 从API版本26.0.0开始，建议使用[applyRotateSync](#applyrotatesync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | 是   | 图像旋转的角度。方向为正数顺时针，负数逆时针。单位：角度（°）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function rotateSync(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  try {
    pixelMap.rotateSync(angle);
    console.info('Succeeded in rotating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyFlip

applyFlip(horizontal: boolean, vertical: boolean): Promise\<void\>

根据指定的水平或垂直翻转条件对PixelMap进行翻转。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| horizontal | boolean            | 是   | 是否进行水平翻转。true表示进行水平翻转，false表示不进行水平翻转。                            |
| vertical   | boolean            | 是   | 是否进行垂直翻转。true表示进行垂直翻转，false表示不进行垂直翻转。                            |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible cause: The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyFlip(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  pixelMap.applyFlip(horizontal, vertical)
    .then(() => {
      console.info('Succeeded in flipping the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyFlipSync

applyFlipSync(horizontal: boolean, vertical: boolean): void

根据指定的水平或垂直翻转条件对PixelMap进行翻转。同步返回结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| horizontal | boolean            | 是   | 是否进行水平翻转。true表示进行水平翻转，false表示不进行水平翻转。                            |
| vertical   | boolean            | 是   | 是否进行垂直翻转。true表示进行垂直翻转，false表示不进行垂直翻转。                            |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible cause: The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyFlipSync(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  try {
    pixelMap.applyFlipSync(horizontal, vertical);
    console.info('Succeeded in flipping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void

根据输入的水平或垂直翻转条件对图片进行翻转。使用callback异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[applyFlip](#applyflip)代替，以获得更完善的异常处理能力。

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

function flip(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  pixelMap.flip(horizontal, vertical, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in flipping the PixelMap.");
  });
}
```

## flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean): Promise\<void>

根据输入的水平或垂直翻转条件对图片进行翻转。使用Promise异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[applyFlip](#applyflip)代替，以获得更完善的异常处理能力。

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
| Promise\<void> |  Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function flip(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  pixelMap.flip(horizontal, vertical).then(() => {
    console.info('Succeeded in flipping the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## flipSync<sup>12+</sup>

flipSync(horizontal: boolean, vertical: boolean): void

根据输入的水平或垂直翻转条件对图片进行翻转。同步返回结果。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[applyFlipSync](#applyflipsync)代替，以获得更完善的异常处理能力。

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
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function flipSync(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  try {
    pixelMap.flipSync(horizontal, vertical);
    console.info('Succeeded in flipping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyCrop

applyCrop(region: Region): Promise\<void\>

根据指定的区域信息对PixelMap进行裁剪。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | 是   | 裁剪的区域，区域范围不能超过图片的宽高。单位：像素（px）。              |

**返回值：**

| 类型           | 说明                                            |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。                        |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600204 | The specified region is invalid or out of range. |
| 7600301 | Failed to allocate memory. Possible causes: 1. Failed to process pixel data. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyCrop(pixelMap: image.PixelMap) {
  const currSize = pixelMap.getImageInfoSync().size;
  const region: image.Region = { // 裁剪区域设为图像中心四分之一的区域。
    x: currSize.width / 4,
    y: currSize.height / 4,
    size: {
      width: currSize.width / 2,
      height: currSize.height / 2
    }
  };

  pixelMap.applyCrop(region)
    .then(() => {
      console.info('Succeeded in cropping the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyCropSync

applyCropSync(region: Region): void

根据指定的区域信息对PixelMap进行裁剪。同步返回结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | 是   | 裁剪的区域，区域范围不能超过图片的宽高。单位：像素（px）。              |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600204 | The specified region is invalid or out of range. |
| 7600301 | Failed to allocate memory. Possible causes: 1. Failed to process pixel data. 2. The system is out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyCropSync(pixelMap: image.PixelMap) {
  const currSize = pixelMap.getImageInfoSync().size;
  const region: image.Region = { // 裁剪区域设为图像中心四分之一的区域。
    x: currSize.width / 4,
    y: currSize.height / 4,
    size: {
      width: currSize.width / 2,
      height: currSize.height / 2
    }
  };

  try {
    pixelMap.applyCropSync(region);
    console.info('Succeeded in cropping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## crop<sup>9+</sup>

crop(region: Region, callback: AsyncCallback\<void>): void

根据输入的尺寸对图片进行裁剪。使用callback异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[applyCrop](#applycrop)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | 是   | 裁剪的区域，包含起始坐标和宽高。取值范围不能超过图片的宽高。单位：像素（px）。 |
| callback | AsyncCallback\<void> | 是   |  回调函数。当对图片进行裁剪成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function crop(pixelMap: image.PixelMap) {
  const region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  pixelMap.crop(region, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in cropping the PixelMap.");
  });
}
```

## crop<sup>9+</sup>

crop(region: Region): Promise\<void>

根据输入的尺寸对图片进行裁剪。使用Promise异步回调。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[applyCrop](#applycrop)代替，以获得更完善的异常处理能力。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明        |
| ------ | ------------------ | ---- | ----------- |
| region | [Region](arkts-apis-image-i.md#region8) | 是   | 裁剪的区域，包含起始坐标和宽高。取值范围不能超过图片的宽高。单位：像素（px）。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象，无返回结果。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function crop(pixelMap: image.PixelMap) {
  const region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  pixelMap.crop(region).then(() => {
    console.info('Succeeded in cropping the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## cropSync<sup>12+</sup>

cropSync(region: Region): void

根据输入的尺寸裁剪图片。同步返回结果。

> **说明：**
>
> 从API版本26.0.0开始，建议使用[applyCropSync](#applycropsync)代替，以获得更完善的异常处理能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | 是   | 裁剪的区域，包含起始坐标和宽高。取值范围不能超过图片的宽高。单位：像素（px）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function cropSync(pixelMap: image.PixelMap) {
  const region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  try {
    pixelMap.cropSync(region);
    console.info('Succeeded in cropping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getColorSpace<sup>10+</sup>

getColorSpace(): colorSpaceManager.ColorSpaceManager

获取图像的色彩空间。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                                | 说明             |
| ----------------------------------- | ---------------- |
| [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 图像色彩空间信息。如果图像不含色彩空间信息，则会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------------------ |
| 62980101 | The image data is abnormal.                |
| 62980103 | The image data is not supported.           |
| 62980115 | Invalid image parameter.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getColorSpace(pixelMap: image.PixelMap) {
  try {
    const csm = pixelMap.getColorSpace();
    console.info(`Succeeded in getting color space: ${csm.getColorSpaceName()}.`);
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to get color space. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## setColorSpace<sup>10+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void

设置图像的色彩空间。如需同时对图像的像素颜色进行色彩空间转换，请使用[applyColorSpace](#applycolorspace11)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名     | 类型                                | 必填 | 说明            |
| ---------- | ----------------------------------- | ---- | --------------- |
| colorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 是   | 图像色彩空间信息。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| -------- | --------------------------------------------|
| 62980111 | The image source data is incomplete.        |
| 62980115 | If the image parameter invalid.             |

**示例：**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

function setColorSpace(pixelMap: image.PixelMap) {
  const colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  const csm: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  try {
    pixelMap.setColorSpace(csm);
    console.info('Succeeded in setting color space.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set color space. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyColorSpace<sup>11+</sup>

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager, callback: AsyncCallback\<void>): void

根据输入的目标色彩空间对图像的像素颜色进行色彩空间转换。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                          |
| -------- | -------------------- | ---- | ----------------------------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 是   | 目标色彩空间，支持SRGB、DCI_P3、DISPLAY_P3、ADOBE_RGB_1998。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当对图像像素颜色进行色彩空间转换成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

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

function applyColorSpace(pixelMap: image.PixelMap) {
  const colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  const targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  pixelMap.applyColorSpace(targetColorSpace, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to apply color space. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in applying color space.');
  });
}
```

## applyColorSpace<sup>11+</sup>

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager): Promise\<void>

根据输入的目标色彩空间对图像的像素颜色进行色彩空间转换。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明        |
| ------ | ------------------ | ---- | ----------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | 是   | 目标色彩空间，支持SRGB、DCI_P3、DISPLAY_P3、ADOBE_RGB_1998。|

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

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

function applyColorSpace(pixelMap: image.PixelMap) {
  const colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  const targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  pixelMap.applyColorSpace(targetColorSpace).then(() => {
    console.info('Succeeded in applying color space.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to apply color space. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## toSdr<sup>12+</sup>

toSdr(): Promise\<void>

将HDR的图像内容转换为SDR的图像内容。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980137 | Invalid image operation.              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function toSdr(context: Context) {
  // 此处'app.media.startIcon'需要替换为本地HDR图片。
  let img = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id);
  let imageSource = image.createImageSource(img.buffer.slice(0));
  let decodingOptions: image.DecodingOptions = {
    desiredDynamicRange: image.DecodingDynamicRange.AUTO
  };
  let pixelmap = imageSource.createPixelMapSync(decodingOptions);
  if (pixelmap != undefined) {
    console.info('Succeeded in creating the PixelMap object.');
    pixelmap.toSdr().then(() => {
      let imageInfo = pixelmap.getImageInfoSync();
      console.info("Succeeded in converting to SDR. imageInfo.isHdr: " + imageInfo.isHdr);
    }).catch((err: BusinessError) => {
      console.error(`Failed to convert to SDR. Code: ${err.code}, message: ${err.message}`);
    });
  } else {
    console.error('Failed to create the PixelMap.');
  }
}
```

## getMetadata<sup>12+</sup>

getMetadata(key: HdrMetadataKey): HdrMetadataValue

从PixelMap中获取HDR元数据。

> **说明：**
>
> 该接口仅支持DMA内存类型的PixelMap调用。详情请参考[图片解码内存优化(ArkTS)](../../media/image/image-allocator-type.md)。

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

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401| Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMetadata(context: Context) {
  // 此处'app.media.startIcon'需要替换为本地HDR图片。
  let img = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id);
  let imageSource = image.createImageSource(img.buffer.slice(0));
  let decodingOptions: image.DecodingOptions = {
    desiredDynamicRange: image.DecodingDynamicRange.AUTO
  };
  let pixelMap = imageSource.createPixelMapSync(decodingOptions);
  if (pixelMap != undefined) {
    console.info('Succeeded in creating the PixelMap object.');
    try {
      let staticMetadata = pixelMap.getMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA);
      console.info('Succeeded in getting the metadata.');
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to get the metadata. Code: ${err.code}, message: ${err.message}`);
    }
  } else {
    console.error('Failed to create the PixelMap.');
  }
}
```

## setMetadata<sup>12+</sup>

setMetadata(key: HdrMetadataKey, value: HdrMetadataValue): Promise\<void>

设置PixelMap的HDR元数据。使用Promise异步回调。

> **说明：**
>
> 该接口仅支持DMA内存类型的PixelMap调用。详情请参考[图片解码内存优化(ArkTS)](../../media/image/image-allocator-type.md)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12) | 是   | HDR元数据的关键字，用于设置对应值。 |
| value | [HdrMetadataValue](arkts-apis-image-t.md#hdrmetadatavalue12) | 是   | 元数据的值。 |

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise\<void> |  Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401|  Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMetadata(pixelMap: image.PixelMap) { // 入参pixelMap内存类型需为DMA_ALLOC内存类型，其创建方法请参考上方说明。
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
  pixelMap.setMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA, staticMetadata).then(() => {
    console.info('Succeeded in setting the metadata.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the metadata. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## setTransferDetached<sup>12+</sup>

setTransferDetached(detached: boolean): void

设置PixelMap在跨线程传输后断开原线程的引用。适用于需要立即释放PixelMap的场景。

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
// EntryAbility.ets
import { common } from '@kit.AbilityKit';
import { taskpool } from '@kit.ArkTS';

@Concurrent
// 子线程方法。
async function loadPixelMap(rawFileDescriptor: number): Promise<image.PixelMap> {
  // 创建ImageSource。
  const imageSource = image.createImageSource(rawFileDescriptor);
  // 创建PixelMap。
  const pixelMap = imageSource.createPixelMapSync();
  // 释放ImageSource。
  imageSource.release();
  // 使PixelMap在跨线程传输完成后，断开原线程的引用。
  pixelMap.setTransferDetached(true);
  // 返回PixelMap给主线程。
  return pixelMap;
}

@Entry
@Component
struct Demo {
  @State pixelMap: image.PixelMap | undefined = undefined;
  // 主线程方法。
  private loadImageFromThread(): void {
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    const resourceMgr = context.resourceManager;
    // 此处'example.jpg'仅作示例，请开发者自行替换，否则创建失败会导致后续无法正常执行。
    resourceMgr.getRawFd('example.jpg').then(rawFileDescriptor => {
      taskpool.execute(loadPixelMap, rawFileDescriptor).then(pixelMap => {
        if (pixelMap) {
          this.pixelMap = pixelMap as image.PixelMap;
          console.info('Succeeded in creating the PixelMap.');
          // 主线程释放PixelMap。由于子线程返回PixelMap前已调用setTransferDetached(true)，所以此处能够立即释放PixelMap，不需要等待子线程被销毁。
          this.pixelMap.release();
        } else {
          console.error('Failed to create the PixelMap.');
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
// EntryAbility.ets
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixelMap: image.PixelMap;
  constructor(pixelMap: image.PixelMap) {
    this.pixelMap = pixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixelMap.marshalling(messageSequence);
    console.info('Marshalled the PixelMap.');
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height: 4, width: 6 }}).then((pixelParcel: image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: image.PixelMap) => {
        this.pixelMap = pixelMap;
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
          console.info(`Unmarshalled information: height = ${imageInfo.size.height}, width = ${imageInfo.size.width}.`);
        });
      });
    });
    return true;
  }
}

async function marshal() {
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
  };
  let pixelMap: image.PixelMap | undefined = undefined;
  await image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
    pixelMap = srcPixelMap;
  })
  if (pixelMap != undefined) {
    // 序列化。
    let parcelable: MySequence = new MySequence(pixelMap);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // 反序列化rpc获取到data。
    let seq: MySequence = new MySequence(pixelMap);
    data.readParcelable(seq);
  }
}
```

## unmarshalling<sup>10+</sup>

unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>

从MessageSequence中反序列化并获取PixelMap。使用Promise异步回调。

> **说明：**
>
> 如需使用同步方式反序列化并创建PixelMap可使用：[createPixelMapFromParcel](arkts-apis-image-f.md#imagecreatepixelmapfromparcel11)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是   | 保存有PixelMap信息的MessageSequence。      |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回反序列化后的PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.              |
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.         |

**示例：**

```ts
// EntryAbility.ets
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixelMap: image.PixelMap;
  constructor(pixelMap: image.PixelMap) {
    this.pixelMap = pixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixelMap.marshalling(messageSequence);
    console.info('Marshalled the PixelMap.');
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height: 4, width: 6 }}).then((pixelParcel: image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: image.PixelMap) => {
        this.pixelMap = pixelMap;
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
          console.info(`Unmarshalled information: height = ${imageInfo.size.height}, width = ${imageInfo.size.width}.`);
        });
      });
    });
    return true;
  }
}

async function unmarshal() {
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
  };
  let pixelMap: image.PixelMap | undefined = undefined;
  await image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
    pixelMap = srcPixelMap;
  })
  if (pixelMap != undefined) {
    // 序列化。
    let parcelable: MySequence = new MySequence(pixelMap);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // 反序列化rpc获取到data。
    let seq: MySequence = new MySequence(pixelMap);
    data.readParcelable(seq);
  }
}
```

## release<sup>7+</sup>

release(): Promise\<void\>

释放PixelMap对象。释放后，任何访问该对象内部数据的方法调用都会失败。使用Promise异步回调。

图片使用的内存往往较大，在PixelMap对象使用完成后，应主动调用该方法及时释放内存。

释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

> **注意：**
>
> 释放指的是ArkTS对象释放与之关联的native对象的管理权。仅当所有管理该native对象的ArkTS对象都被释放时，native对象占用的内存才会被回收。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function release(pixelMap: image.PixelMap) {
  pixelMap.release().then(() => {
    console.info('Succeeded in releasing the PixelMap object.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to release the PixelMap object. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## release<sup>7+</sup>

release(callback: AsyncCallback\<void\>): void

释放PixelMap对象。释放后，任何访问该对象内部数据的方法调用都会失败。使用callback异步回调。

图片使用的内存往往较大，在PixelMap对象使用完成后，应主动调用该方法及时释放内存。

释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

> **注意：**
>
> 释放指的是ArkTS对象释放与之关联的native对象的管理权。仅当所有管理该native对象的ArkTS对象都被释放时，native对象占用的内存才会被回收。

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

function release(pixelMap: image.PixelMap) {
  pixelMap.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the PixelMap object. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in releasing the PixelMap object.');
  });
}
```

## convertPixelFormat<sup>12+</sup>

convertPixelFormat(targetPixelFormat: PixelMapFormat): Promise\<void>

YUV和RGB类型互转。使用Promise异步回调。

支持NV12/NV21与RGB_888/RGBA_8888/RGB_565/BGRA_8888/RGBA_F16互转，YCRCB_P010/YCBCR_P010与RGBA_1010102互转。

从API version 18开始，可用于ASTC_4x4类型转为RGBA_8888类型，目前仅支持ASTC_4x4转为RGBA_8888。

> **注意：**
>
> 仅在ASTC_4x4格式的图像需要进行像素访问时，建议调用此接口将ASTC_4x4类型转为RGBA_8888类型。由于使用ASTC_4x4反解为RGBA_8888时延较高，其余情况下不推荐使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| targetPixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | 是   | 目标像素格式，用于YUV和RGB类型互转，或者ASTC_4x4类型转为RGBA_8888类型。目前仅支持NV12/NV21与RGB_888/RGBA_8888/RGB_565/BGRA_8888/RGBA_F16互转，YCRCB_P010/YCBCR_P010与RGBA_1010102互转，ASTC_4x4转为RGBA_8888。 |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

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

function convertPixelFormat(pixelMap: image.PixelMap) {
  // 设置目标像素格式为NV12。
  let targetPixelFormat = image.PixelMapFormat.NV12;
  pixelMap.convertPixelFormat(targetPixelFormat).then(() => {
    console.info('Succeeded in converting pixel format.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to convert pixel format. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## setMemoryNameSync<sup>13+</sup>

setMemoryNameSync(name: string): void

设置PixelMap的内存标识符，便于在内存调试或问题定位时识别该内存。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| name | string | 是   | PixelMap内存标识符，只允许DMA和SHARE_MEMORY内存类型的PixelMap设置。DMA内存设置名称长度取值范围为[1, 255]字节，SHARE_MEMORY内存设置名称长度取值范围为[1, 244]字节。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.The length of the input parameter is too long. 2.Parameter verification failed. |
| 501 | Resource unavailable. |
| 62980286 | Memory format not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMemoryNameSync(pixelMap: image.PixelMap) {
  try {
    pixelMap.setMemoryNameSync("PixelMapName Test");
    console.info('Succeeded in setting memory name.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set memory name. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getUniqueId<sup>22+</sup>

getUniqueId(): number

获取PixelMap的唯一ID。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 唯一ID。取值为正整数。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 7600201 | The PixelMap has been released. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getUniqueId(pixelMap: image.PixelMap) {
  try {
    const uniqueId: number = pixelMap.getUniqueId();
    console.info(`Succeeded in getting the unique ID: ${uniqueId}.`);
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to get the unique ID. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## isReleased<sup>22+</sup>

isReleased(): boolean

检查PixelMap对象是否已被释放。如果已被释放，则任何访问该对象内部数据的方法调用将会失败。

> **注意：**
>
> 释放指的是ArkTS对象释放与之关联的native对象的管理权。仅当所有管理该native对象的ArkTS对象都被释放时，native对象占用的内存才会被回收。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| boolean | PixelMap是否已被释放。返回true表示已被释放，否则返回false。 |

**示例：**

```ts
async function isReleased(pixelMap: image.PixelMap) { // 未释放的PixelMap。
  pixelMap.isReleased(); // 返回false。
  await pixelMap.release();
  pixelMap.isReleased(); // 返回true。
}
```
