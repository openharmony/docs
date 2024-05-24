# @ohos.multimedia.sendableImage (基于Sendable对象的图片处理)

本模块基于Sendable对象，提供图片处理效果，包括通过属性创建PixelMap、读取图像像素数据、读取区域内的图片数据等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import sendableImage from '@ohos.multimedia.sendableImage';
```

## Size

表示图片尺寸。
继承自[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称   | 类型   | 只读 | 可选 | 说明           |
| ------ | ------ | ---- | ---- | -------------- |
| height | number | 否   | 否   | 输出图片的高，单位：像素。 |
| width  | number | 否   | 否   | 输出图片的宽，单位：像素。 |

## Region

表示区域信息。
继承自[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称 | 类型          | 只读 | 可选 | 说明         |
| ---- | ------------- | ---- | ---- | ------------ |
| size | [Size](#size) | 否   | 否   | 区域大小。   |
| x    | number        | 否   | 否   | 区域横坐标。 |
| y    | number        | 否   | 否   | 区域纵坐标。 |

## sendableImage.createImageSource

createImageSource(uri: string): ImageSource

通过传入的uri创建图片源实例。


**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型   | 必填 | 说明                               |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | 是   | 图片路径，当前仅支持应用沙箱路径。</br>当前支持格式有：.jpg .png .gif .bmp .webp .dng [SVG](./js-apis-image.md#svg标签说明) .ico。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](#imagesource) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
const context: Context = getContext(this);
const path: string = context.cacheDir + "/test.jpg";
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(path);
```

## sendableImage.createImageSource

createImageSource(fd: number): ImageSource

通过传入文件描述符来创建图片源实例。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

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
import fs from '@ohos.file.fs'

const context: Context = getContext(this);
const path: string = context.cacheDir + "/test.jpg";
let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(file.fd);
```

## sendableImage.createImageSource

createImageSource(buf: ArrayBuffer): ImageSource

通过缓冲区创建图片源实例。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

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
const buf: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(buf);
```

## sendableImage.createImageReceiver

createImageReceiver(size: image.Size, format: image.ImageFormat, capacity: number): ImageReceiver

通过图片大小、图片格式、容量创建ImageReceiver实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| size    | [image.Size](./js-apis-image.md#size)  | 是   | 图像的默认大小。       |
| format   | [image.ImageFormat](./js-apis-image.md#imageformat9) | 是   | 图像格式，取值为image.ImageFormat常量，目前仅支持 ImageFormat:JPEG。             |
| capacity | number | 是   | 同时访问的最大图像数。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](#imagereceiver) | 如果操作成功，则返回ImageReceiver实例。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401| Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;   |

**示例：**

```ts
let size: image.Size = {
    height: 8192,
    width: 8
} 
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
```

## ImageSource

图片源类，用于获取图片相关信息。在调用ImageSource的方法前，需要先通过[createImageSource](#sendableimagecreateimagesource)构建一个ImageSource实例。


### createPixelMap

createPixelMap(options?: image.DecodingOptions): Promise\<PixelMap>

通过图片解码参数创建PixelMap对象。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                 | 必填 | 说明       |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [image.DecodingOptions](./js-apis-image.md#decodingoptions7) | 否   | 解码参数。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap]> | Promise实例，用于异步返回创建结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

const context: Context = getContext(this);
const path: string = context.cacheDir + "/test.jpg";
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(path);
sendableImageSourceApi.createPixelMap().then((pixelMap: sendableImage.PixelMap) => {
    console.info('Succeeded in creating pixelMap object through image decoding parameters.');
}).catch((error: BusinessError) => {
    console.error('Failed to create pixelMap object through image decoding parameters.');
})
```

### release

release(): Promise\<void>

释放图片源实例，使用Promise形式返回结果。
release是线程不安全的。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise实例，异步返回结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

const context: Context = getContext(this);
const path: string = context.cacheDir + "/test.jpg";
const sendableImageSourceApi: sendableImage.ImageSource = sendableImage.createImageSource(path);
sendableImageSourceApi.release().then(() => {
    console.info('Succeeded in releasing the image source instance.');
}).catch((error: BusinessError) => {
    console.error('Failed to release the image source instance.');
})
```

## Image

提供基本的图像操作，包括获取图像信息、读写图像数据。调用[readNextImage](#readnextimage)和[readLatestImage](#readlatestimage)接口时会返回image。
继承自[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)。

### 属性

**系统能力：** SystemCapability.Multimedia.Image.Core

| 名称     | 类型               | 只读 | 可选 | 说明                                               |
| -------- | ------------------ | ---- | ---- | -------------------------------------------------- |
| clipRect | [Region](#region) | 否   | 否   | 要裁剪的图像区域。                                 |
| size     | [Size](#size)      | 是   | 否   | 图像大小。                                         |
| format   | number             | 是   | 否   | 图像格式，参考[OH_NativeBuffer_Format](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_format)。 |
| timestamp<sup>12+</sup> | number         | 是      | 否   | 图像时间戳。|

### getComponent

getComponent(componentType: image.ComponentType): Promise\<image.Component>

根据图像的组件类型从图像中获取组件缓存并使用Promise方式返回结果。
getComponent是线程不安全的。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明             |
| ------------- | -------------------------------- | ---- | ---------------- |
| componentType | [image.ComponentType](./js-apis-image.md#componenttype9) | 是   | 图像的组件类型。 |

**返回值：**

| 类型                              | 说明                              |
| --------------------------------- | --------------------------------- |
| Promise<[image.Component](./js-apis-image.md#component9)> | Promise实例，用于异步返回组件缓冲区。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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
    console.error('getComponent failed');
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
import { BusinessError } from '@ohos.base';

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
    console.error('release failed.');
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
| size     | [image.Size](./js-apis-image.md#size)                | 是   | 否   | 图片大小。         |
| capacity | number                       | 是   | 否   | 同时访问的图像数。 |
| format   | [image.ImageFormat](./js-apis-image.md#imageformat9) | 是   | 否   | 图像格式。         |

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
import { BusinessError } from '@ohos.base';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.getReceivingSurfaceId().then((id: string) => { 
    console.info('getReceivingSurfaceId succeeded.');
}).catch((error: BusinessError) => {
    console.error('getReceivingSurfaceId failed.');
})
```

### readLatestImage

readLatestImage(): Promise\<Image>

从ImageReceiver读取最新的图片，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明               |
| ------------------------- | ------------------ |
| Promise<[Image](#image)> | 异步返回最新图片。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.readLatestImage().then((img: image.Image) => {
    console.info('readLatestImage succeeded.');
}).catch((error: BusinessError) => {
    console.error('readLatestImage failed.');
})
```

### readNextImage

readNextImage(): Promise\<Image>

从ImageReceiver读取下一张图片，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明                 |
| ------------------------- | -------------------- |
| Promise<[Image](#image)> | 异步返回下一张图片。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.readNextImage().then((img: image.Image) => {
    console.info('readNextImage succeeded.');
}).catch((error: BusinessError) => {
    console.error('readNextImage failed.');
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
import { BusinessError } from '@ohos.base';

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

释放ImageReceiver实例并使用promise返回结果。
release是线程不安全的。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型           | 说明               |
| -------------- | ------------------ |
| Promise\<void> | 异步返回操作结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let size: image.Size = {
    height: 8192,
    width: 8
}
let receiver: sendableImage.ImageReceiver = sendableImage.createImageReceiver(size, image.ImageFormat.JPEG, 8);
receiver.release().then(() => {
    console.info('release succeeded.');
}).catch((error: BusinessError) => {
    console.error('release failed.');
})
```
