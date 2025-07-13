# Interface (ImageReceiver)

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 9开始支持。

图像接收类，用于获取组件surface id，接收最新的图片和读取下一张图片，以及释放ImageReceiver实例。ImageReceiver做为图片的接收方、消费者，它的参数属性实际上不会对接收到的图片产生影响。图片属性的配置应在发送方、生产者进行，如相机预览流[createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput)。

在调用以下方法前需要先创建ImageReceiver实例。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

| 名称     | 类型                         | 只读 | 可选 | 说明               |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| size<sup>9+</sup>     | [Size](arkts-apis-image-i.md#size)                | 是   | 否   | 图片大小。该参数不会影响接收到的图片大小，实际返回大小由生产者决定，如相机。         |
| capacity<sup>9+</sup> | number                       | 是   | 否   | 同时访问的图像数。该参数仅作为期望值，实际capacity由设备硬件决定。 |
| format<sup>9+</sup>   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | 是   | 否   | 图像格式，取值为[ImageFormat](arkts-apis-image-e.md#imageformat9)常量（目前仅支持 ImageFormat:JPEG，实际返回格式由生产者决定，如相机）        |

## getReceivingSurfaceId<sup>9+</sup>

getReceivingSurfaceId(callback: AsyncCallback\<string>): void

用于获取一个surface id供Camera或其他组件使用。使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                   | 必填 | 说明                       |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<string> | 是   | 回调函数，当获取surface id成功，err为undefined，data为获取到的surface id；否则为错误对象。 |

**示例:**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.getReceivingSurfaceId((err: BusinessError, id: string) => {
  if (err) {
    console.error(`Failed to get the ReceivingSurfaceId.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting the ReceivingSurfaceId.');
  }
});
```

## getReceivingSurfaceId<sup>9+</sup>

getReceivingSurfaceId(): Promise\<string>

用于获取一个surface id供Camera或其他组件使用。使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<string> | Promise对象，返回surface id。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.getReceivingSurfaceId().then((id: string) => { 
  console.info('Succeeded in getting the ReceivingSurfaceId.');
}).catch((error: BusinessError) => {
  console.error(`Failed to get the ReceivingSurfaceId.code ${error.code},message is ${error.message}`);
})
```

## readLatestImage<sup>9+</sup>

readLatestImage(callback: AsyncCallback\<Image>): void

从ImageReceiver读取最新的图片，并使用callback返回结果。

**注意**：此接口需要在[on](#on9)回调触发后调用，才能正常的接收到数据。且此接口返回的[Image](arkts-apis-image-Image.md)对象使用完毕后需要调用[release](arkts-apis-image-Image.md#release9)方法释放，释放后才可以继续接收新的数据。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名     | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<[Image](arkts-apis-image-Image.md)> | 是   | 回调函数，当读取最新图片成功，err为undefined，data为获取到的最新图片；否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readLatestImage((err: BusinessError, img: image.Image) => {
  if (err) {
    console.error(`Failed to read the latest Image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in reading the latest Image.');
  }
});
```

## readLatestImage<sup>9+</sup>

readLatestImage(): Promise\<Image>

从ImageReceiver读取最新的图片，并使用promise返回结果。

**注意**：此接口需要在[on](#on9)回调触发后调用，才能正常的接收到数据。且此接口返回的[Image](arkts-apis-image-Image.md)对象使用完毕后需要调用[release](arkts-apis-image-Image.md#release9)方法释放，释放后才可以继续接收新的数据。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明               |
| ------------------------- | ------------------ |
| Promise<[Image](arkts-apis-image-Image.md)> | Promise对象，返回最新图片。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readLatestImage().then((img: image.Image) => {
  console.info('Succeeded in reading the latest Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to read the latest Image.code ${error.code},message is ${error.message}`);
})
```

## readNextImage<sup>9+</sup>

readNextImage(callback: AsyncCallback\<Image>): void

从ImageReceiver读取下一张图片，并使用callback返回结果。

**注意**：此接口需要在[on](#on9)回调触发后调用，才能正常的接收到数据。且此接口返回的[Image](arkts-apis-image-Image.md)对象使用完毕后需要调用[release](arkts-apis-image-Image.md#release9)方法释放，释放后才可以继续接收新的数据。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                            | 必填 | 说明                       |
| -------- | ------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[Image](arkts-apis-image-Image.md)> | 是   | 回调函数，当获取下一张图片成功，err为undefined，data为获取到的下一张图片；否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readNextImage((err: BusinessError, img: image.Image) => {
  if (err) {
    console.error(`Failed to read the next Image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in reading the next Image.');
  }
});
```

## readNextImage<sup>9+</sup>

readNextImage(): Promise\<Image>

从ImageReceiver读取下一张图片，并使用promise返回结果。

**注意**：此接口需要在[on](#on9)回调触发后调用，才能正常的接收到数据。且此接口返回的[Image](arkts-apis-image-Image.md)对象使用完毕后需要调用[release](arkts-apis-image-Image.md#release9)方法释放，释放后才可以继续接收新的数据。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型                      | 说明                 |
| ------------------------- | -------------------- |
| Promise<[Image](arkts-apis-image-Image.md)> | Promise对象，返回下一张图片。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.readNextImage().then((img: image.Image) => {
  console.info('Succeeded in reading the next Image.');
}).catch((error: BusinessError) => {
  console.error(`Failed to read the next Image.code ${error.code},message is ${error.message}`);
})
```

## on<sup>9+</sup>

on(type: 'imageArrival', callback: AsyncCallback\<void>): void

接收图片时注册回调。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                   |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| type     | string               | 是   | 注册事件的类型，固定为'imageArrival'，接收图片时触发。 |
| callback | AsyncCallback\<void> | 是   | 回调函数，当注册事件触发成功，err为undefined，否则为错误对象。                                        |

**示例：**

```ts
receiver.on('imageArrival', () => {
  // image arrival, do something.
})
```

## off<sup>13+</sup>

off(type: 'imageArrival', callback?: AsyncCallback\<void>): void

释放buffer时移除注册回调。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                     |
| -------- | -------------------- |----|----------------------------------------|
| type     | string               | 是  | 注册事件的类型，固定为'imageArrival'，释放buffer时触发。 |
| callback | AsyncCallback\<void> | 否  | 移除的回调函数。         |

**示例：**

```ts
let callbackFunc = ()=>{
    // do something.
}
receiver.on('imageArrival', callbackFunc)
receiver.off('imageArrival', callbackFunc)
```

## release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

释放ImageReceiver实例并使用回调返回结果。

ArkTS有内存回收机制，ImageReceiver对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数，当释放ImageReceiver实例成功，err为undefined，否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release the receiver.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing the receiver.');
  }
})
```

## release<sup>9+</sup>

release(): Promise\<void>

释放ImageReceiver实例并使用promise返回结果。

ArkTS有内存回收机制，ImageReceiver对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**返回值：**

| 类型           | 说明               |
| -------------- | ------------------ |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

receiver.release().then(() => {
  console.info('Succeeded in releasing the receiver.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release the receiver.code ${error.code},message is ${error.message}`);
})
```
