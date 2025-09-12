# Interface (ImageCreator)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 9开始支持。

图像创建模块，用于请求图像数据区域，并开放给应用编译图像数据的能力。
在调用以下方法前需要先通过[createImageCreator](arkts-apis-image-f.md#imagecreateimagecreator11)创建ImageCreator实例，ImageCreator不支持多线程。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

| 名称     | 类型                         | 只读 | 可选 | 说明               |
| -------- | ---------------------------- | ---- | ---- | ------------------ |
| capacity<sup>9+</sup> | number                       | 是   | 否   | 同时访问的图像数。该参数仅作为期望值，实际capacity由设备硬件决定。 |
| format<sup>9+</sup>   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | 是   | 否   | 图像格式。         |

## dequeueImage<sup>9+</sup>

dequeueImage(callback: AsyncCallback\<Image>): void

从空闲队列中获取buffer图片，用于绘制UI内容，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名        | 类型                                    | 必填 | 说明                 |
| ------------- | ---------------------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<[Image](arkts-apis-image-Image.md)>  | 是   | 回调函数，当获取最新图片成功，err为undefined，data为获取到的最新图片；否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function DequeueImage(creator : image.ImageCreator) {
  creator.dequeueImage((err: BusinessError, img: image.Image) => {
    if (err) {
      console.error(`Failed to dequeue the Image.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in dequeuing the Image.');
    }
  });
}
```

## dequeueImage<sup>9+</sup>

dequeueImage(): Promise\<Image>

从空闲队列中获取buffer图片，用于绘制UI内容，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**返回值：**

| 类型             | 说明           |
| --------------- | ------------- |
| Promise\<[Image](arkts-apis-image-Image.md)> | Promise对象，返回最新图片。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function DequeueImage(creator : image.ImageCreator) {
  creator.dequeueImage().then((img: image.Image) => {
    console.info('Succeeded in dequeuing the Image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to dequeue the Image.code ${error.code},message is ${error.message}`);
  })
}
```

## queueImage<sup>9+</sup>

queueImage(image: Image, callback: AsyncCallback\<void>): void

将绘制好的图片放入队列，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名        | 类型                     | 必填 | 说明                 |
| ------------- | -------------------------| ---- | -------------------- |
| image     | [Image](arkts-apis-image-Image.md)                    | 是   | 绘制好的buffer图像。 |
| callback      | AsyncCallback\<void>     | 是   | 回调函数，当将图片放入队列成功，err为undefined，否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function QueueImage(creator : image.ImageCreator) {
  creator.dequeueImage().then((img: image.Image) => {
    // 绘制图片。
    img.getComponent(4).then((component : image.Component) => {
      let bufferArr: Uint8Array = new Uint8Array(component.byteBuffer);
      for (let i = 0; i < bufferArr.length; i += 4) {
        bufferArr[i] = 0; // B
        bufferArr[i + 1] = 0; // G
        bufferArr[i + 2] = 255; // R
        bufferArr[i + 3] = 255; // A
      }
    })
    creator.queueImage(img, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to queue the Image.code ${err.code},message is ${err.message}`);
      } else {
        console.info('Succeeded in queuing the Image.');
      }
    })
  })
}
```

## queueImage<sup>9+</sup>

queueImage(image: Image): Promise\<void>

将绘制好的图片放入队列，并使用promise返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名          | 类型     | 必填 | 说明                |
| ------------- | --------| ---- | ------------------- |
| image     | [Image](arkts-apis-image-Image.md)   | 是   | 绘制好的buffer图像。 |

**返回值：**

| 类型            | 说明           |
| -------------- | ------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function QueueImage(creator : image.ImageCreator) {
  creator.dequeueImage().then((img: image.Image) => {
    // 绘制图片。
    img.getComponent(4).then((component: image.Component) => {
      let bufferArr: Uint8Array = new Uint8Array(component.byteBuffer);
      for (let i = 0; i < bufferArr.length; i += 4) {
        bufferArr[i] = 0; // B
        bufferArr[i + 1] = 0; // G
        bufferArr[i + 2] = 255; // R
        bufferArr[i + 3] = 255; // A
      }
    })
    creator.queueImage(img).then(() => {
      console.info('Succeeded in queuing the Image.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to queue the Image.code ${error.code},message is ${error.message}`);
    })
  })
}
```

## on<sup>9+</sup>

on(type: 'imageRelease', callback: AsyncCallback\<void>): void

监听imageRelease事件，并使用callback返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名        | 类型                     | 必填 | 说明                 |
| ------------- | -------------------------| ---- | -------------------- |
| type          | string                   | 是   | 监听事件类型，如'imageRelease'。 |
| callback      | AsyncCallback\<void>     | 是   | 回调函数，当监听事件触发成功，err为undefined，否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function On(creator : image.ImageCreator) {
  creator.on('imageRelease', (err: BusinessError) => {
    if (err) {
      console.error(`Failed to get the imageRelease callback.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in getting imageRelease callback.');
    }
  })
}
```

## off<sup>13+</sup>

off(type: 'imageRelease', callback?: AsyncCallback\<void>): void

释放buffer时，移除注册的回调函数。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名        | 类型                     | 必填 | 说明                                         |
| ------------- | -------------------------|----|--------------------------------------------|
| type          | string                   | 是  | 监听事件类型，如'imageRelease'。                    |
| callback      | AsyncCallback\<void>     | 否  | 将被移除的回调函数。 |

**示例：**

```ts
async function Off(creator : image.ImageCreator) {
  let callbackFunc = ()=>{
      // 实现回调函数逻辑。
  }
  creator.on('imageRelease', callbackFunc)
  creator.off('imageRelease', callbackFunc)
}
```

## release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

释放当前图像，并使用callback返回结果。

ArkTS有内存回收机制，ImageCreator对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名           | 类型                     | 必填 | 说明                 |
| ------------- | -------------------------| ---- | -------------------- |
| callback      | AsyncCallback\<void>     | 是   | 回调函数，当图像释放成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release(creator : image.ImageCreator) {
  creator.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the creator.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in releasing creator.');
    }
  });
}
```

## release<sup>9+</sup>

release(): Promise\<void>

释放当前图像，并使用promise返回结果。

ArkTS有内存回收机制，ImageCreator对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**返回值：**

| 类型            | 说明           |
| -------------- | ------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release(creator : image.ImageCreator) {
  creator.release().then(() => {
    console.info('Succeeded in releasing creator.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to release the creator.code ${error.code},message is ${error.message}`);
  })
}
```
