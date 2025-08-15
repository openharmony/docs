# Interface (ImagePacker)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

图片编码器类，用于图片压缩和编码。在调用ImagePacker的方法前，需要先通过[createImagePacker](arkts-apis-image-f.md#imagecreateimagepacker)构建一个ImagePacker实例，当前支持格式有：jpeg、webp、png、heif<sup>12+</sup>（不同硬件设备支持情况不同）。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

| 名称             | 类型           | 只读 | 可选 | 说明                       |
| ---------------- | -------------- | ---- | ---- | -------------------------- |
| supportedFormats | Array\<string> | 是   | 否   | 图片编码支持的格式 jpeg、webp、png、heic<sup>12+</sup>（不同硬件设备支持情况不同）。 |

## packToData<sup>13+</sup>

packToData(source: ImageSource, options: PackingOption): Promise\<ArrayBuffer>

图片压缩或重新编码，使用Promise形式返回结果。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](arkts-apis-image-ImageSource.md)     | 是   | 编码的ImageSource。 |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | If the parameter is invalid. |
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**返回值：**

| 类型                         | 说明                                          |
| ---------------------------- | --------------------------------------------- |
| Promise\<ArrayBuffer>        | Promise对象，返回压缩或编码后的数据。 |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource会创建失败导致后续无法正常执行。
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packToData(imageSourceApi, packOpts)
  .then((data: ArrayBuffer) => {
    console.info('Succeeded in packing the image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
```

## packToData<sup>13+</sup>

packToData(source: PixelMap, options: PackingOption): Promise\<ArrayBuffer>

图片压缩或重新编码，使用Promise形式返回结果。

> **注意：**
> 接口如果返回401错误码，表明参数异常，可能是PixelMap对象被提前释放了。需要调用方排查，在该方法调用结束后再释放PixelMap对象。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明               |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](arkts-apis-image-PixelMap.md)           | 是   | 编码的PixelMap源。 |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。     |

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise对象，返回压缩或编码后的数据。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | If the parameter is invalid. |
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packToData(pixelMap, packOpts)
    .then((data: ArrayBuffer) => {
      console.info('Succeeded in packing the image.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create PixelMap.code ${error.code},message is ${error.message}`);
})
```

## packing<sup>13+</sup>

packing(picture: Picture, options: PackingOption): Promise\<ArrayBuffer>

将图像压缩或重新编码，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名           | 类型                                                 | 必填 | 说明                 |
| ---------------- | ---------------------------------------------------- | ---- | -------------------- |
| picture | [Picture](arkts-apis-image-Picture.md)                           | 是   | 编码的Picture对象。 |
| options          | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。       |

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise\<ArrayBuffer> | Promise对象，返回压缩或编码后的数据。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800301  | Encode failed.                                         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function Packing(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  let funcName = "Packing";
  if (imagePackerApi != null) {
    let opts: image.PackingOption = {
      format: "image/jpeg",
      quality: 98,
      bufferSize: 10,
      desiredDynamicRange: image.PackingDynamicRange.AUTO,
      needsPackProperties: true};
    await imagePackerApi.packing(pictureObj, opts).then((data: ArrayBuffer) => {
        console.info(funcName, 'Succeeded in packing the image.'+ data);
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed to pack the image.code ${error.code},message is ${error.message}');
      });
  }
}
```

## packToDataFromPixelmapSequence<sup>18+</sup>

packToDataFromPixelmapSequence(pixelmapSequence: Array\<PixelMap>, options: PackingOptionsForSequence): Promise\<ArrayBuffer>

将多个PixelMap编码成GIF数据。使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名           | 类型                                                      | 必填 | 说明                   |
| ---------------- | --------------------------------------------------------- | ---- | ---------------------- |
| pixelmapSequence | Array\<[PixelMap](arkts-apis-image-PixelMap.md)>                            | 是   | 待编码的PixelMap序列。 |
| options          | [PackingOptionsForSequence](arkts-apis-image-i.md#packingoptionsforsequence18) | 是   | 动图编码参数。         |

**返回值：**

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise\<ArrayBuffer> | Promise对象，返回编码后的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800301  | Failed to encode image.                                      |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import image from "@ohos.multimedia.image";

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const resourceMgr = context.resourceManager;
// 此处'moving_test.gif'仅作示例，请开发者自行替换。否则imageSource会创建失败，导致后续无法正常执行。
const fileData = resourceMgr.getRawFileContent('moving_test.gif');
const color = fileData.buffer;
let imageSource = image.createImageSource(color);
let pixelMapList = imageSource.createPixelMapList();
let ops: image.PackingOptionsForSequence = {
  frameCount: 3,  // 指定GIF编码中的帧数为3。
  delayTimeList: [10, 10, 10],  // 指定GIF编码中3帧的延迟时间分别为100ms、100ms、100ms。
  disposalTypes: [3, 2, 3], // 指定GIF编码中3帧的帧过渡模式分别为3（恢复到之前的状态）、2（恢复背景色)、3(恢复到之前的状态)。
  loopCount: 0 // 指定GIF编码中循环次数为无限循环。
};
let Packer = image.createImagePacker();
Packer.packToDataFromPixelmapSequence(pixelMapList, ops)
  .then((data: ArrayBuffer) => {
    console.info('Succeeded in packing.');
  }).catch((error: BusinessError) => {
  console.error('Failed to packing.');
  })
```

## release

release(callback: AsyncCallback\<void>): void

释放图片编码实例，使用callback形式返回结果。

ArkTS有内存回收机制，ImagePacker对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数，当释放图片编码实例成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.release((err: BusinessError)=>{
  if (err) {
    console.error(`Failed to release image packaging.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing image packaging.');
  }
})
```

## release

release(): Promise\<void>

释放图片编码实例，使用Promise形式返回释放结果。

ArkTS有内存回收机制，ImagePacker对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**返回值：**

| 类型           | 说明                                                   |
| -------------- | ------------------------------------------------------ |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.release().then(() => {
  console.info('Succeeded in releasing image packaging.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release image packaging.code ${error.code},message is ${error.message}`);
})
```

## packToFile<sup>11+</sup>

packToFile(source: ImageSource, fd: number, options: PackingOption, callback: AsyncCallback\<void>): void

指定编码参数，将ImageSource直接编码进文件。使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                            | 必填 | 说明                           |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [ImageSource](arkts-apis-image-ImageSource.md)     | 是   | 编码的ImageSource。                 |
| fd       | number                          | 是   | 文件描述符。                   |
| options   | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。                 |
| callback | AsyncCallback\<void>            | 是   | 回调函数，当编码进文件成功，err为undefined，否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'test.png'仅作示例，请开发者自行替换，否则imageSource会创建失败导致后续无法正常执行。
const path: string = context.filesDir + "/test.png";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath: string = context.filesDir + "/image_source.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packToFile(imageSourceApi, file.fd, packOpts, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to pack the image to file.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in packing the image to file.');
  }
})
```

## packToFile<sup>11+</sup>

packToFile (source: ImageSource, fd: number, options: PackingOption): Promise\<void>

指定编码参数，将ImageSource直接编码进文件。使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](arkts-apis-image-ImageSource.md)     | 是   | 编码的ImageSource。 |
| fd     | number                          | 是   | 文件描述符。   |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。 |

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'test.png'仅作示例，请开发者自行替换，否则imageSource会创建失败导致后续无法正常执行。
const path: string = context.filesDir + "/test.png";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const filePath: string = context.filesDir + "/image_source.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packToFile(imageSourceApi, file.fd, packOpts).then(() => {
  console.info('Succeeded in packing the image to file.');
}).catch((error: BusinessError) => { 
  console.error(`Failed to pack the image to file.code ${error.code},message is ${error.message}`);
}) 
```

## packToFile<sup>11+</sup>

packToFile (source: PixelMap, fd: number, options: PackingOption,  callback: AsyncCallback\<void>): void

指定编码参数，将PixelMap直接编码进文件。使用callback形式返回结果。

> **注意：**
> 接口如果返回62980115错误码，表明参数异常，可能是PixelMap对象被提前释放了。需要调用方排查，在该方法调用结束后再释放PixelMap对象。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                            | 必填 | 说明                           |
| -------- | ------------------------------- | ---- | ------------------------------ |
| source   | [PixelMap](arkts-apis-image-PixelMap.md)          | 是   | 编码的PixelMap资源。           |
| fd       | number                          | 是   | 文件描述符。                   |
| options   | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。                 |
| callback | AsyncCallback\<void>            | 是   | 回调函数，当编码图片进文件成功，err为undefined，否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.filesDir + "/pixel_map.jpg";
image.createPixelMap(color, opts).then((pixelmap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packToFile(pixelmap, file.fd, packOpts, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to pack the image to file.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in packing the image to file.');
    }
  })
})
```

## packToFile<sup>11+</sup>

packToFile (source: PixelMap, fd: number, options: PackingOption): Promise\<void>

指定编码参数，将PixelMap直接编码进文件。使用Promise形式返回结果。

> **注意：**
> 接口如果返回62980115错误码，表明参数异常，可能是PixelMap对象被提前释放了。需要调用方排查，在该方法调用结束后再释放PixelMap对象。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明                 |
| ------ | ------------------------------- | ---- | -------------------- |
| source | [PixelMap](arkts-apis-image-PixelMap.md)          | 是   | 编码的PixelMap资源。 |
| fd     | number                          | 是   | 文件描述符。         |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。       |

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980101 | The image data is abnormal. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid input parameter. |
| 62980119 | Failed to encode the image. |
| 62980120 | Add pixelmap out of range. |
| 62980172 | Failed to encode icc. |
| 62980252 | Failed to create surface. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const path: string = context.filesDir + "/pixel_map.jpg";
image.createPixelMap(color, opts).then((pixelmap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packToFile(pixelmap, file.fd, packOpts)
    .then(() => {
      console.info('Succeeded in packing the image to file.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image to file.code ${error.code},message is ${error.message}`);
  })
})
```

## packToFile<sup>13+</sup>

packToFile(picture: Picture, fd: number, options: PackingOption): Promise\<void>

指定编码参数，将Picture直接编码进文件。使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名  | 类型                         | 必填 | 说明                 |
| ------- | ---------------------------- | ---- | -------------------- |
| picture  | [Picture](arkts-apis-image-Picture.md)          | 是   | 编码的Picture资源。 |
| fd      | number                       | 是   | 文件描述符。         |
| options | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。       |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800301  | Encode failed.                                         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function PackToFile(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);

  let funcName = "PackToFile";
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  if (imagePackerApi != null) {
    const filePath: string = context.filesDir + "/test.jpg";
    let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    let packOpts: image.PackingOption = {
      format: "image/jpeg",
      quality: 98,
      bufferSize: 10,
      desiredDynamicRange: image.PackingDynamicRange.AUTO,
      needsPackProperties: true};
    await imagePackerApi.packToFile(pictureObj, file.fd, packOpts).then(() => {
      console.info(funcName, 'Succeeded in packing the image to file.');
    }).catch((error: BusinessError) => {
      console.error(funcName, 'Failed to pack the image to file.code ${error.code},message is ${error.message}');
    });
  }
}
```

## packToFileFromPixelmapSequence<sup>18+</sup>

packToFileFromPixelmapSequence(pixelmapSequence: Array\<PixelMap>, fd: number, options: PackingOptionsForSequence): Promise\<void>

指定编码参数，将多个PixelMap编码成GIF文件。使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名           | 类型                                                      | 必填 | 说明                   |
| ---------------- | --------------------------------------------------------- | ---- | ---------------------- |
| pixelmapSequence | Array<[PixelMap](arkts-apis-image-PixelMap.md)>                             | 是   | 待编码的PixelMap序列。 |
| fd               | number                                                    | 是   | 文件描述符。           |
| options          | [PackingOptionsForSequence](arkts-apis-image-i.md#packingoptionsforsequence18) | 是   | 动图编码参数。         |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7800301  | Failed to encode image.                                      |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import fs from '@ohos.file.fs';
import image from "@ohos.multimedia.image";

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
const resourceMgr = context.resourceManager;
// 此处'moving_test.gif'仅作示例，请开发者自行替换。否则imageSource会创建失败，导致后续无法正常执行。
const fileData = await resourceMgr.getRawFileContent('moving_test.gif');
const color = fileData.buffer;
let imageSource = image.createImageSource(color);
let pixelMapList = await imageSource.createPixelMapList();
let path: string = context.cacheDir + '/result.gif';
let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
let ops: image.PackingOptionsForSequence = {
  frameCount: 3,  // 指定GIF编码中的帧数为3。
  delayTimeList: [10, 10, 10],  // 指定GIF编码中3帧的延迟时间分别为100ms、100ms、100ms。
  disposalTypes: [3, 2, 3], // 指定GIF编码中3帧的帧过渡模式分别为3（恢复到之前的状态）、2（恢复背景色)、3(恢复到之前的状态)。
  loopCount: 0 // 指定GIF编码中循环次数为无限循环。
};
let Packer = image.createImagePacker();
Packer.packToFileFromPixelmapSequence(pixelMapList, file.fd, ops)
  .then(() => {
    console.info('Succeeded in packToFileMultiFrames.');
  }).catch((error: BusinessError) => {
  console.error('Failed to packToFileMultiFrames.');
  })
```

## packing<sup>(deprecated)</sup>

packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

图片压缩或重新编码，使用callback形式返回结果。

> **说明：**
>
> 从API version 6开始支持，从API version 13开始废弃，建议使用[packToData](#packtodata13)代替。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                               | 必填 | 说明                               |
| -------- | ---------------------------------- | ---- | ---------------------------------- |
| source   | [ImageSource](arkts-apis-image-ImageSource.md)        | 是   | 编码的ImageSource。                     |
| option   | [PackingOption](arkts-apis-image-i.md#packingoption)    | 是   | 设置编码参数。                      |
| callback | AsyncCallback\<ArrayBuffer>        | 是   | 回调函数，当图片编码成功，err为undefined，data为获取到的压缩或编码数据；否则为错误对象。  |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource会创建失败导致后续无法正常执行。
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 };
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packing(imageSourceApi, packOpts, (err: BusinessError, data: ArrayBuffer) => {
  if (err) {
    console.error(`Failed to pack the image.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in packing the image.');
  }
})
```

## packing<sup>(deprecated)</sup>

packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>

图片压缩或重新编码，使用Promise形式返回结果。

> **说明：**
>
> 从API version 6开始支持，从API version 13开始废弃，建议使用[packToData](#packtodata13)代替。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| source | [ImageSource](arkts-apis-image-ImageSource.md)     | 是   | 编码的ImageSource。 |
| option | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。 |

**返回值：**

| 类型                         | 说明                                          |
| ---------------------------- | --------------------------------------------- |
| Promise\<ArrayBuffer>        | Promise对象，返回压缩或编码后的数据。 |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource会创建失败导致后续无法正常执行。
let filePath: string = context.filesDir + "/test.jpg";
const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
const imagePackerApi: image.ImagePacker = image.createImagePacker();
imagePackerApi.packing(imageSourceApi, packOpts)
  .then((data: ArrayBuffer) => {
    console.info('Succeeded in packing the image.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
```

## packing<sup>(deprecated)</sup>

packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void

图片压缩或重新编码，使用callback形式返回结果。

> **说明：**
>
> 从API version 8开始支持，从API version 13开始废弃，建议使用[packToData](#packtodata13)代替。

> **注意：**
> 接口如果返回"PixelMap mismatch"，表明参数异常，可能是PixelMap对象被提前释放了。需要调用方排查，在该方法调用结束后再释放PixelMap对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名   | 类型                            | 必填 | 说明                               |
| -------- | ------------------------------- | ---- | ---------------------------------- |
| source   | [PixelMap](arkts-apis-image-PixelMap.md)           | 是   | 编码的PixelMap资源。               |
| option   | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。                     |
| callback | AsyncCallback\<ArrayBuffer>     | 是   | 回调函数，当图片编码成功，err为undefined，data为获取到的压缩或编码数据；否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packing(pixelMap, packOpts, (err: BusinessError, data: ArrayBuffer) => {
    if (err) {
      console.error(`Failed to pack the image.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in packing the image.');
    }
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create the PixelMap.code ${error.code},message is ${error.message}`);
})
```

## packing<sup>(deprecated)</sup>

packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>

图片压缩或重新编码，使用Promise形式返回结果。

> **说明：**
>
> 从API version 8开始支持，从API version 13开始废弃，建议使用[packToData](#packtodata13)代替。

> **注意：**
> 接口如果返回"PixelMap mismatch"，表明参数异常，可能是PixelMap对象被提前释放了。需要调用方排查，在该方法调用结束后再释放PixelMap对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**参数：**

| 参数名 | 类型                            | 必填 | 说明               |
| ------ | ------------------------------- | ---- | ------------------ |
| source | [PixelMap](arkts-apis-image-PixelMap.md)           | 是   | 编码的PixelMap源。 |
| option | [PackingOption](arkts-apis-image-i.md#packingoption) | 是   | 设置编码参数。     |

**返回值：**

| 类型                  | 说明                                         |
| --------------------- | -------------------------------------------- |
| Promise\<ArrayBuffer> | Promise对象，返回压缩或编码后的数据。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4。
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  let packOpts: image.PackingOption = { format: "image/jpeg", quality: 98 }
  const imagePackerApi: image.ImagePacker = image.createImagePacker();
  imagePackerApi.packing(pixelMap, packOpts)
    .then((data: ArrayBuffer) => {
      console.info('Succeeded in packing the image.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to pack the image.code ${error.code},message is ${error.message}`);
  })
}).catch((error: BusinessError) => {
  console.error(`Failed to create PixelMap.code ${error.code},message is ${error.message}`);
})
```
