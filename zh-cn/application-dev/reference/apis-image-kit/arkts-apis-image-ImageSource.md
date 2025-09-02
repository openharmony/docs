# Interface (ImageSource)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

ImageSource类，用于获取图片相关信息。在调用ImageSource的方法前，需要先通过[createImageSource](arkts-apis-image-f.md#imagecreateimagesource)构建一个ImageSource实例。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

| 名称             | 类型           | 只读 | 可选 | 说明                                                         |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | 是   | 否   | 支持的图片格式，包括：png，jpeg，bmp，gif，webp，dng，heic<sup>12+</sup>（不同硬件设备支持情况不同）。 |

## getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

获取指定序号的图片信息，使用callback形式返回图片信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                     |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | 是   | 创建ImageSource时的序号。默认值为0，表示第一张图片。当取值为N时，表示第N+1张图片。单帧图片场景中index取值只能为0，动图等多帧图片场景中index的取值范围为：0~（帧数-1）。                   |
| callback | AsyncCallback<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | 是   | 回调函数。当获取图片信息成功，err为undefined，data为获取到的图片信息；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageInfo(0, (error: BusinessError, imageInfo: image.ImageInfo) => {
  if (error) {
    console.error(`Failed to obtain the image information.code is ${error.code}, message is ${error.message}`);
  } else {
    console.info('Succeeded in obtaining the image information.');
  }
})
```

## getImageInfo

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

获取图片信息，使用callback形式返回图片信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                     |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | 是   | 回调函数。当获取图片信息成功，err为undefined，data为获取到的图片信息；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageInfo((err: BusinessError, imageInfo: image.ImageInfo) => {
  if (err) {
    console.error(`Failed to obtain the image information.code is ${err.code}, message is ${err.message}`);
  } else {
    console.info('Succeeded in obtaining the image information.');
  }
})
```

## getImageInfo

getImageInfo(index?: number): Promise\<ImageInfo>

获取图片信息，使用Promise形式返回图片信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名| 类型   | 必填 | 说明                                  |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | 否   | 创建ImageSource时的序号。默认值为0，表示第一张图片。当取值为N时，表示第N+1张图片。单帧图片场景中index取值只能为0，动图等多帧图片场景中index的取值范围为：0~（帧数-1）。 |

**返回值：**

| 类型                             | 说明                   |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Promise对象，返回获取到的图片信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageInfo(0)
  .then((imageInfo: image.ImageInfo) => {
    console.info('Succeeded in obtaining the image information.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to obtain the image information.code is ${error.code}, message is ${error.message}`);
  })
```

## getImageInfoSync<sup>12+</sup>

getImageInfoSync(index?: number): ImageInfo

获取指定序号的图片信息，使用同步形式返回图片信息。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名| 类型   | 必填 | 说明                                  |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | 否   | 创建ImageSource时的序号。默认值为0，表示第一张图片。当取值为N时，表示第N+1张图片。单帧图片场景中index取值只能为0，动图等多帧图片场景中index的取值范围为：0~（帧数-1）。 |

**返回值：**

| 类型                             | 说明                   |
| -------------------------------- | ---------------------- |
| [ImageInfo](arkts-apis-image-i.md#imageinfo) | 同步返回获取到的图片信息。 |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { image } from '@kit.ImageKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let imageInfo = imageSource.getImageInfoSync(0);
if (imageInfo == undefined) {
  console.error('Failed to obtain the image information.');
} else {
  console.info('Succeeded in obtaining the image information.');
  console.info('imageInfo.size.height:' + imageInfo.size.height);
  console.info('imageInfo.size.width:' + imageInfo.size.width);
}
```

## getImageProperty<sup>11+</sup>

getImageProperty(key:PropertyKey, options?: ImagePropertyOptions): Promise\<string>

获取图片中给定索引处图像的指定属性键的值，用Promise形式返回结果，仅支持JPEG、PNG和HEIF<sup>12+</sup>（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                                 |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | [PropertyKey](arkts-apis-image-e.md#propertykey7)                                               | 是   | 图片属性名。                         |
| options | [ImagePropertyOptions](arkts-apis-image-i.md#imagepropertyoptions11) | 否   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型             | 说明                                                              |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise对象，返回图片属性值，如获取失败则返回属性默认值。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;              |
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980103 | The image data is not supported.         |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.       |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.   |
| 62980123| The image does not support EXIF decoding. |
| 62980135| The EXIF value is invalid.             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: image.ImagePropertyOptions = { index: 0, defaultValue: '9999' }
imageSourceApi.getImageProperty(image.PropertyKey.BITS_PER_SAMPLE, options)
.then((data: string) => {
  console.info('Succeeded in getting the value of the specified attribute key of the image.');
}).catch((error: BusinessError) => {
  console.error('Failed to get the value of the specified attribute key of the image.');
})
```

## getImageProperties<sup>12+</sup>

getImageProperties(key: Array&#60;PropertyKey&#62;): Promise<Record<PropertyKey, string|null>>

批量获取图片中的指定属性键的值，用Promise形式返回结果。仅支持JPEG、PNG和HEIF（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                                 |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | Array\<[PropertyKey](arkts-apis-image-e.md#propertykey7)>                                 | 是   | 图片属性名的数组。                         |

**返回值：**

| 类型             | 说明                                                              |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<Record<[PropertyKey](arkts-apis-image-e.md#propertykey7), string \| null>> | Promise对象，返回图片属性值，如获取失败则返回null。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;     |
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110| The image source data is incorrect.            |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980116| Failed to decode the image.            |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let key = [image.PropertyKey.IMAGE_WIDTH, image.PropertyKey.IMAGE_LENGTH];
imageSourceApi.getImageProperties(key).then((data) => {
  console.info(JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## getImagePropertySync<sup>20+</sup>

getImagePropertySync(key:PropertyKey): string

获取图片exif指定属性键的值，使用同步形式返回结果。

>**说明：**
>
> 该方法仅支持JPEG、PNG和HEIF（不同硬件设备支持情况不同）文件，且需要包含exif信息。
>
> exif信息是图片的元数据，包含拍摄时间、相机型号、光圈、焦距、ISO等。


**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                                 |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | [PropertyKey](arkts-apis-image-e.md#propertykey7)                                               | 是   | 图片属性名。                         |

**返回值：**

| 类型             | 说明                                                              |
| ---------------- | ----------------------------------------------------------------- |
| string | 返回图片exif中指定属性键的值（如获取失败则返回属性默认值），各个数据值作用请参考[PropertyKey](arkts-apis-image-e.md#propertykey7)。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。
| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed.|
| 7700102 | Unsupported MIME type.|
| 7700202 | Unsupported metadata. For example, key is not supported.|

**示例：**

<!--code_no_check-->
```ts
import { image } from '@kit.ImageKit';
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let resourceMgr = context.resourceManager;
if (resourceMgr == null) {
  return;
}
let fd = resourceMgr.getRawFdSync("example.jpg");

const imageSourceApi = image.createImageSource(fd);
console.info("getImagePropertySync");
let bits_per_sample = imageSourceApi.getImagePropertySync(image.PropertyKey.BITS_PER_SAMPLE);
console.info("bits_per_sample : " + bits_per_sample);
```

## modifyImageProperty<sup>11+</sup>

modifyImageProperty(key: PropertyKey, value: string): Promise\<void>

通过指定的键修改图片属性的值，使用Promise形式返回结果，仅支持JPEG、PNG和HEIF<sup>12+</sup>（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

> **说明：**
>
> 调用modifyImageProperty修改属性会改变属性字节长度，使用buffer创建的ImageSource调用modifyImageProperty会导致buffer内容覆盖，目前buffer创建的ImageSource不支持调用此接口，请改用fd或path创建的ImageSource。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| key     | [PropertyKey](arkts-apis-image-e.md#propertykey7)   | 是   | 图片属性名。 |
| value   | string | 是   | 属性值。     |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;    |
| 62980123| The image does not support EXIF decoding.             |
| 62980133| The EXIF data is out of range.             |
| 62980135| The EXIF value is invalid.             |
| 62980146| The EXIF data failed to be written to the file.        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.modifyImageProperty(image.PropertyKey.IMAGE_WIDTH, "120").then(() => {
  imageSourceApi.getImageProperty(image.PropertyKey.IMAGE_WIDTH).then((width: string) => {
    console.info(`ImageWidth is :${width}`);
  }).catch((error: BusinessError) => {
    console.error('Failed to get the Image Width.');
  })
}).catch((error: BusinessError) => {
  console.error('Failed to modify the Image Width');
})
```

## modifyImageProperties<sup>12+</sup>

modifyImageProperties(records: Record<PropertyKey, string|null>): Promise\<void>

批量通过指定的键修改图片属性的值，使用Promise形式返回结果。仅支持JPEG、PNG和HEIF（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

> **说明：**
>
> 调用modifyImageProperties修改属性会改变属性字节长度，使用buffer创建的ImageSource调用modifyImageProperties会导致buffer内容覆盖，目前buffer创建的ImageSource不支持调用此接口，请改用fd或path创建的ImageSource。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| records     | Record<[PropertyKey](arkts-apis-image-e.md#propertykey7), string \| null>   | 是   | 包含图片属性名和属性值的数组。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;      |
| 62980123| The image does not support EXIF decoding.             |
| 62980135| The EXIF value is invalid.             |
| 62980146| The EXIF data failed to be written to the file.             |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyValues: Record<PropertyKey, string|null> = {
    [image.PropertyKey.IMAGE_WIDTH] : "1024",
    [image.PropertyKey.IMAGE_LENGTH] : "1024"
};
let checkKey = [image.PropertyKey.IMAGE_WIDTH, image.PropertyKey.IMAGE_LENGTH];
imageSourceApi.modifyImageProperties(keyValues).then(() => {
  imageSourceApi.getImageProperties(checkKey).then((data) => {
    console.info(JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(JSON.stringify(err));
  });
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number): Promise\<void>

更新增量数据，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型        | 必填 | 说明         |
| ---------- | ----------- | ---- | ------------ |
| buf        | ArrayBuffer         | 是   | 存放增量数据的buffer。           |
| isFinished | boolean             | 是   | true表示数据更新完成，当前buffer内存放最后一段数据；false表示数据还未更新完成，需要继续更新。|
| offset      | number              | 是   | 即当前buffer中的数据首地址，相对于整个图片文件首地址的偏移量。单位：字节。             |
| length     | number              | 是   | 当前buffer的长度。单位：字节。            |

**返回值：**

| 类型           | 说明                       |
| -------------- | -------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const array: ArrayBuffer = new ArrayBuffer(100);
imageSourceApi.updateData(array, false, 0, 10).then(() => {
  console.info('Succeeded in updating data.');
}).catch((err: BusinessError) => {
  console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
})
```


## updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number, callback: AsyncCallback\<void>): void

更新增量数据，callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型                | 必填 | 说明                 |
| ---------- | ------------------- | ---- | -------------------- |
| buf        | ArrayBuffer         | 是   | 存放增量数据的buffer。           |
| isFinished | boolean             | 是   | true表示数据更新完成，当前buffer内存放最后一段数据；false表示数据还未更新完成，需要继续更新。|
| offset      | number              | 是   | 即当前buffer中的数据首地址，相对于整个图片文件首地址的偏移量。单位：字节。             |
| length     | number              | 是   | 当前buffer的长度。单位：字节。            |
| callback   | AsyncCallback\<void> | 是   |  回调函数，当更新增量数据成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const array: ArrayBuffer = new ArrayBuffer(100);
imageSourceApi.updateData(array, false, 0, 10, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in updating data.');
  }
})
```

## createPicture<sup>13+</sup>

createPicture(options?: DecodingOptionsForPicture): Promise\<Picture>

通过图片解码参数创建Picture对象,使用Promise形式返回。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明       |
| ------- | ------------------------------------------------------ | ---- | ---------- |
| options | [DecodingOptionsForPicture](arkts-apis-image-i.md#decodingoptionsforpicture13) | 否   | 解码参数。 |

**返回值：**

| 类型                         | 说明                       |
| ---------------------------- | -------------------------- |
| Promise\<[Picture](arkts-apis-image-Picture.md)> | Promise对象，返回Picture。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified.2.Incorrect parameter types; 3.Parameter verification failed. |
| 7700301  | Failed to decode image.                                      |

**示例：**

```ts
import { image } from '@kit.ImageKit';

async function CreatePicture() {
  let options: image.DecodingOptionsForPicture = {
    desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] //GAINMAP为需要解码的辅助图类型。 
  };
  let pictureObj: image.Picture = await imageSourceApi.createPicture(options);
  if (pictureObj != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }
}
```

## createPictureAtIndex<sup>20+</sup>

createPictureAtIndex(index: number): Promise\<Picture>

通过指定序号的图片（目前仅支持GIF格式）创建Picture对象。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型    | 必填 | 说明                                              |
| ------ | ------ | ---- | ------------------------------------------------ |
| index  | number | 是   | 解码图片序号。图片序号有效的取值范围为：[0，帧数-1]。 |

**返回值：**

| 类型                         | 说明                         |
| ---------------------------- | ---------------------------- |
| Promise\<[Picture](arkts-apis-image-Picture.md)> | Promise对象，返回Picture。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 7700101  | Bad source. |
| 7700102  | Unsupported MIME type. |
| 7700103  | Image too large. |
| 7700203  | Unsupported options. For example, index is invalid. |
| 7700301  | Decoding failed. |

**示例：**

```ts
import { image } from '@kit.ImageKit';

async function CreatePictures() {
  let frameCount: number = await imageSourceApi.getFrameCount();
  for (let index = 0; index < frameCount; index++) {
    try {
      let pictureObj: image.Picture = await imageSourceApi.createPictureAtIndex(index);
      console.info('Create picture succeeded for frame: ' + index);
    } catch (e) {
      console.error('Create picture failed for frame: ' + index);
    }
  }
}
```

## createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

通过图片解码参数创建PixelMap对象。

从API version 15开始，推荐使用[createPixelMapUsingAllocator](#createpixelmapusingallocator15)，该接口可以指定输出pixelMap的内存类型[AllocatorType](arkts-apis-image-e.md#allocatortype15)，详情请参考[申请图片解码内存(ArkTS)](../../media/image/image-allocator-type.md)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                 | 必填 | 说明       |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | 否   | 解码参数。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回PixelMap。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.createPixelMap().then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelMap object through image decoding parameters.');
}).catch((error: BusinessError) => {
  console.error('Failed to create pixelMap object through image decoding parameters.');
})
```

## createPixelMap<sup>7+</sup>

createPixelMap(callback: AsyncCallback\<PixelMap>): void

通过默认参数创建PixelMap对象，使用callback形式返回结果。

从API version 15开始，推荐使用[createPixelMapUsingAllocator](#createpixelmapusingallocator15)，该接口可以指定输出pixelMap的内存类型[AllocatorType](arkts-apis-image-e.md#allocatortype15)，详情请参考[申请图片解码内存(ArkTS)](../../media/image/image-allocator-type.md)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[PixelMap](arkts-apis-image-PixelMap.md)> | 是   | 回调函数，当创建PixelMap对象成功，err为undefined，data为获取到的PixelMap对象；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.createPixelMap((err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in creating pixelMap object.');
  }
})
```

## createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

通过图片解码参数创建PixelMap对象。

从API version 15开始，推荐使用[createPixelMapUsingAllocator](#createpixelmapusingallocator15)，该接口可以指定输出pixelMap的内存类型[AllocatorType](arkts-apis-image-e.md#allocatortype15)，详情请参考[申请图片解码内存(ArkTS)](../../media/image/image-allocator-type.md)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7)  | 是   | 解码参数。                 |
| callback | AsyncCallback<[PixelMap](arkts-apis-image-PixelMap.md)> | 是   | 回调函数，当创建PixelMap对象成功，err为undefined，data为获取到的PixelMap对象；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decodingOptions: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 1, height: 2 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 1, height: 2 }, x: 0, y: 0 },
  // 若解码接口同时传入了desiredSize参数与desiredRegion参数，需进一步传入cropAndScaleStrategy参数指定缩放与裁剪的先后顺序，推荐设置CROP_FIRST。
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
  index: 0
};
imageSourceApi.createPixelMap(decodingOptions, (err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in creating pixelMap object.');
  }
})
```

## createPixelMapSync<sup>12+</sup>

createPixelMapSync(options?: DecodingOptions): PixelMap

通过图片解码参数同步创建PixelMap对象。

从API version 15开始，推荐使用[createPixelMapUsingAllocatorSync](#createpixelmapusingallocatorsync15)，该接口可以指定输出pixelMap的内存类型[AllocatorType](arkts-apis-image-e.md#allocatortype15)，详情请参考[申请图片解码内存(ArkTS)](../../media/image/image-allocator-type.md)。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7)  | 否   | 解码参数。                 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 用于同步返回创建结果。 |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { image } from '@kit.ImageKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
//此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let decodingOptions: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 1, height: 2 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 1, height: 2 }, x: 0, y: 0 },
  // 若解码接口同时传入了desiredSize参数与desiredRegion参数，需进一步传入cropAndScaleStrategy参数指定缩放与裁剪的先后顺序，推荐设置CROP_FIRST。
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
  index: 0
};
let pixelmap = imageSource.createPixelMapSync(decodingOptions);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
} else {
  console.error('Failed to create pixelMap.');
}
```

## createPixelMapList<sup>10+</sup>

createPixelMapList(options?: DecodingOptions): Promise<Array\<PixelMap>>

通过图片解码参数创建PixelMap数组。针对动图如Gif、Webp，此接口返回每帧图片数据；针对静态图，此接口返回唯一的一帧图片数据。

> **注意：**
> 此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7)  | 否   | 解码参数。                 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise<Array<[PixelMap](arkts-apis-image-PixelMap.md)>> | 异步返回PixeMap数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980099 | The shared memory data is abnormal. |
| 62980101 | The image data is abnormal. |
| 62980103| The image data is not supported.             |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980109 | Failed to crop the image. |
| 62980111| The image source data is incomplete.           |
| 62980115 | Invalid image parameter. |
| 62980116 | Failed to decode the image. |
| 62980118| Failed to create the image plugin.             |
| 62980137 | Invalid media operation. |
| 62980173 | The DMA memory does not exist. |
| 62980174 | The DMA memory data is abnormal. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decodeOpts: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 198, height: 202 },
  rotate: 0,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts).then((pixelMapList: Array<image.PixelMap>) => {
  console.info('Succeeded in creating pixelMapList object.');
}).catch((err: BusinessError) => {
  console.error(`Failed to create pixelMapList object, error code is ${err}`);
})
```

## createPixelMapList<sup>10+</sup>

createPixelMapList(callback: AsyncCallback<Array\<PixelMap>>): void

通过默认参数创建PixelMap数组，使用callback形式返回结果。针对动图如Gif、Webp，此接口返回每帧图片数据；针对静态图，此接口返回唯一的一帧图片数据。

> **注意：**
> 此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                       |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<Array<[PixelMap](arkts-apis-image-PixelMap.md)>> | 是   | 回调函数，当创建PixelMap对象数组成功，err为undefined，data为获取到的PixelMap对象数组；否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980099 | The shared memory data is abnormal.  |
| 62980101 | The image data is abnormal.          |
| 62980103 | The image data is not supported.         |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980109 | Failed to crop the image.            |
| 62980111 | The image source data is incomplete. |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.         |
| 62980118 | Failed to create the image plugin.   |
| 62980137 | Invalid media operation.     |
| 62980173 | The DMA memory does not exist.        |
| 62980174 | The DMA memory data is abnormal.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.createPixelMapList((err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
  if (err) {
    console.error(`Failed to create pixelMapList object, error code is ${err}`);
  } else {
    console.info('Succeeded in creating pixelMapList object.');
  }
})
```

## createPixelMapList<sup>10+</sup>

createPixelMapList(options: DecodingOptions, callback: AsyncCallback<Array\<PixelMap>>): void

通过图片解码参数创建PixelMap数组，使用callback形式返回结果。针对动图如Gif、Webp，此接口返回每帧图片数据；针对静态图，此接口返回唯一的一帧图片数据。

> **注意：**
> 此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| options | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | 是 | 解码参数。 |
| callback | AsyncCallback<Array<[PixelMap](arkts-apis-image-PixelMap.md)>> | 是   | 回调函数，当创建PixelMap对象数组成功，err为undefined，data为获取到的PixelMap对象数组；否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.            |
| 62980099 | The shared memory data is abnormal.  |
| 62980101 | The image data is abnormal.         |
| 62980103 | The image data is not supported.        |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |
| 62980109 | Failed to crop the image.           |
| 62980111 | The image source data is incomplete. |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.         |
| 62980118 | Failed to create the image plugin.  |
| 62980137 | Invalid media operation.      |
| 62980173 | The DMA memory does not exist.         |
| 62980174 | The DMA memory data is abnormal.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decodeOpts: image.DecodingOptions = {
  sampleSize: 1,
  editable: true,
  desiredSize: { width: 198, height: 202 },
  rotate: 0,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  index: 0,
};
imageSourceApi.createPixelMapList(decodeOpts, (err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
  if (err) {
    console.error(`Failed to create pixelMapList object, error code is ${err}`);
  } else {
    console.info('Succeeded in creating pixelMapList object.');
  }
})
```

## createPixelMapUsingAllocator<sup>15+</sup>

createPixelMapUsingAllocator(options?: DecodingOptions, allocatorType?: AllocatorType): Promise\<PixelMap>

使用指定的分配器根据图像解码参数异步创建PixelMap对象。使用Promise异步回调。接口使用详情请参考[申请图片解码内存(ArkTS)](../../media/image/image-allocator-type.md)。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名        | 类型                                 | 必填 | 说明                     |
| ------------- | ------------------------------------ | ---- | ------------------------ |
| options        | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | 否   | 解码参数。               |
| allocatorType | [AllocatorType](arkts-apis-image-e.md#allocatortype15)   | 否   | 用于图像解码的内存类型。默认值为AllocatorType.AUTO。 |

**返回值：**

| 类型                             | 说明                        |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types;3.Parameter verification failed. |
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed. |
| 7700102  | Unsupported mimetype.                                        |
| 7700103  | Image too large.  This status code is thrown when an error occurs during the process of checking size. |
| 7700201  | Unsupported allocator type, e.g., use share memory to decode a HDR image as only DMA supported hdr metadata. |
| 7700203  | Unsupported options, e.g., cannot convert image into desired pixel format. |
| 7700301  | Failed to decode image.                                      |
| 7700302  | Failed to allocate memory.                                   |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let decodingOptions: image.DecodingOptions = {
  editable: true,
  desiredSize: { width: 3072, height: 4096 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 3072, height: 4096 }, x: 0, y: 0 },
  // 若解码接口同时传入了desiredSize参数与desiredRegion参数，需进一步传入cropAndScaleStrategy参数指定缩放与裁剪的先后顺序，推荐设置CROP_FIRST。
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
  index: 0
};
let pixelmap = imageSource.createPixelMapUsingAllocator(decodingOptions, image.AllocatorType.AUTO);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
} else {
  console.error('Failed to create pixelMap.');
}
```

## createPixelMapUsingAllocatorSync<sup>15+</sup>

createPixelMapUsingAllocatorSync(options?: DecodingOptions, allocatorType?: AllocatorType): PixelMap

根据指定的分配器同步创建一个基于图像解码参数的PixelMap对象。接口使用详情请参考[申请图片解码内存(ArkTS)](../../media/image/image-allocator-type.md)。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名        | 类型                                 | 必填 | 说明                     |
| ------------- | ------------------------------------ | ---- | ------------------------ |
| options        | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | 否   | 解码参数。               |
| allocatorType | [AllocatorType](arkts-apis-image-e.md#allocatortype15)   | 否   | 用于图像解码的内存类型。默认值为AllocatorType.AUTO。 |

**返回值：**

| 类型                   | 说明                   |
| ---------------------- | ---------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 用于同步返回创建结果。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types;3.Parameter verification failed. |
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed. |
| 7700102  | Unsupported mimetype.                                        |
| 7700103  | Image too large.  This status code is thrown when an error occurs during the process of checking size. |
| 7700201  | Unsupported allocator type, e.g., use share memory to decode a HDR image as only DMA supported hdr metadata. |
| 7700203  | Unsupported options, e.g., cannot convert image into desired pixel format. |
| 7700301  | Failed to decode image.                                      |
| 7700302  | Failed to allocate memory.                                   |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import image from '@ohos.multimedia.image';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
let filePath: string = context.filesDir + "/test.jpg";
let imageSource = image.createImageSource(filePath);
let decodingOptions: image.DecodingOptions = {
  editable: true,
  desiredSize: { width: 3072, height: 4096 },
  rotate: 10,
  desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
  desiredRegion: { size: { width: 3072, height: 4096 }, x: 0, y: 0 },
  // 若解码接口同时传入了desiredSize参数与desiredRegion参数，需进一步传入cropAndScaleStrategy参数指定缩放与裁剪的先后顺序，推荐设置CROP_FIRST。
  cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
  index: 0
};
let pixelmap = imageSource.createPixelMapUsingAllocatorSync(decodingOptions, image.AllocatorType.AUTO);
if (pixelmap != undefined) {
  console.info('Succeeded in creating pixelMap object.');
} else {
  console.error('Failed to create pixelMap.');
}
```

## getDelayTimeList<sup>10+</sup>

getDelayTimeList(callback: AsyncCallback<Array\<number>>): void

获取图像延迟时间数组，使用callback形式返回结果。此接口仅用于gif图片和webp图片。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback<Array\<number>> | 是   | 回调函数，当获取图像延迟时间数组成功，err为undefined，data为获取到的图像延时时间数组；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980110| The image source data is incorrect.             |
| 62980111| The image source data is incomplete.            |
| 62980115 | Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| Failed to decode the image header. |
| 62980149 | Invalid MIME type for the image source. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getDelayTimeList((err: BusinessError, delayTimes: Array<number>) => {
  if (err) {
    console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting delayTimes object.');
  }
})
```

## getDelayTimeList<sup>10+</sup>

getDelayTimeList(): Promise<Array\<number>>

获取图像延迟时间数组，使用Promise形式返回结果。此接口仅用于gif图片和webp图片。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<Array\<number>> | Promise对象，返回延迟时间数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.  |
| 62980122 | Failed to decode the image header.   |
| 62980149 | Invalid MIME type for the image source.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getDelayTimeList().then((delayTimes: Array<number>) => {
  console.info('Succeeded in getting delayTimes object.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
})
```

## getFrameCount<sup>10+</sup>

getFrameCount(callback: AsyncCallback\<number>): void

获取图像帧数，使用callback形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数，当获取图像帧数成功，err为undefined，data为获取到的图像帧数；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980111| The image source data is incomplete. |
| 62980112| The image format does not match. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115| Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| Failed to decode the image header. |
| 62980137| Invalid media operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getFrameCount((err: BusinessError, frameCount: number) => {
  if (err) {
    console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in getting frame count.');
  }
})
```

## getFrameCount<sup>10+</sup>

getFrameCount(): Promise\<number>

获取图像帧数，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<number> | Promise对象，返回图像帧数。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be occorrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.  |
| 62980137 | Invalid media operation.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getFrameCount().then((frameCount: number) => {
  console.info('Succeeded in getting frame count.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
})
```

## getDisposalTypeList<sup>12+</sup>

getDisposalTypeList(): Promise\<Array\<number>>

获取图像帧过渡模式数组，使用Promise形式返回结果。此接口仅用于gif图片。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<Array\<number>> | Promise对象，返回帧过渡模式数组。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.      |
| 62980101 | The image data is abnormal. |
| 62980137 | Invalid media operation.        |
| 62980149 | Invalid MIME type for the image source.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
imageSourceApi.getDisposalTypeList().then((disposalTypes: Array<number>) => {
  console.info('Succeeded in getting disposalTypes object.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get disposalTypes object.code ${err.code},message is ${err.message}`);
})
```

## release

release(callback: AsyncCallback\<void>): void

释放ImageSource实例，使用callback形式返回结果。

ArkTS有内存回收机制，ImageSource对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数，当资源释放成功，err为undefined，否则为错误对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release the image source instance.code ${err.code},message is ${err.message}`);
  } else {
    console.info('Succeeded in releasing the image source instance.');
  }
})
```

## release

release(): Promise\<void>

释放ImageSource实例，使用Promise形式返回结果。

ArkTS有内存回收机制，ImageSource对象不调用release方法，内存最终也会由系统统一释放。但图片使用的内存往往较大，为尽快释放内存，建议应用在使用完成后主动调用release方法提前释放内存。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.release().then(() => {
  console.info('Succeeded in releasing the image source instance.');
}).catch((error: BusinessError) => {
  console.error(`Failed to release the image source instance.code ${error.code},message is ${error.message}`);
})
```

## getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

获取图片中给定索引处图像的指定属性键的值，用Promise形式返回结果，仅支持JPEG、PNG和HEIF<sup>12+</sup>（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

> **说明：**
>
> 从API version 11开始不再维护，建议使用[getImageProperty](#getimageproperty11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                                                 | 必填 | 说明                                 |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                               | 是   | 图片属性名。                         |
| options | [GetImagePropertyOptions](arkts-apis-image-i.md#getimagepropertyoptionsdeprecated) | 否   | 图片属性，包括图片序号与默认属性值。 |

**返回值：**

| 类型             | 说明                                                              |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise对象，返回图片属性值，如获取失败则返回属性默认值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageProperty("BitsPerSample")
  .then((data: string) => {
    console.info('Succeeded in getting the value of the specified attribute key of the image.');
  }).catch((error: BusinessError) => {
    console.error('Failed to get the value of the specified attribute key of the image.');
  })
```

## getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

获取图片中给定索引处图像的指定属性键的值，用callback形式返回结果，仅支持JPEG、PNG和HEIF<sup>12+</sup>（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

> **说明：**
>
> 从API version 11开始不再维护，建议使用[getImageProperty](#getimageproperty11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | 是   | 图片属性名。                                                 |
| callback | AsyncCallback\<string> | 是   | 回调函数，当获取图片属性值成功，err为undefined，data为获取到的图片属性值；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.getImageProperty("BitsPerSample", (error: BusinessError, data: string) => {
  if (error) {
    console.error('Failed to get the value of the specified attribute key of the image.');
  } else {
    console.info('Succeeded in getting the value of the specified attribute key of the image.');
  }
})
```

## getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

获取图片指定属性键的值，callback形式返回结果，仅支持JPEG、PNG和HEIF<sup>12+</sup>（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

> **说明：**
>
> 从API version 11开始不再维护，建议使用[getImageProperty](#getimageproperty11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                          |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------- |
| key      | string                                               | 是   | 图片属性名。                                                  |
| options  | [GetImagePropertyOptions](arkts-apis-image-i.md#getimagepropertyoptionsdeprecated) | 是   | 图片属性，包括图片序号与默认属性值。                          |
| callback | AsyncCallback\<string>                               | 是   | 回调函数，当获取图片属性值成功，err为undefined，data为获取到的图片属性值；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let property: image.GetImagePropertyOptions = { index: 0, defaultValue: '9999' }
imageSourceApi.getImageProperty("BitsPerSample", property, (error: BusinessError, data: string) => {
  if (error) {
    console.error('Failed to get the value of the specified attribute key of the image.');
  } else {
    console.info('Succeeded in getting the value of the specified attribute key of the image.');
  }
})
```

## modifyImageProperty<sup>(deprecated)</sup>

modifyImageProperty(key: string, value: string): Promise\<void>

通过指定的键修改图片属性的值，使用Promise形式返回结果，仅支持JPEG、PNG和HEIF<sup>12+</sup>（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

> **说明：**
>
> 调用modifyImageProperty修改属性会改变属性字节长度，使用buffer创建的ImageSource调用modifyImageProperty会导致buffer内容覆盖，目前buffer创建的ImageSource不支持调用此接口，请改用fd或path创建的ImageSource。
>
> 从API version 11开始不再维护，建议使用[modifyImageProperty](#modifyimageproperty11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型   | 必填 | 说明         |
| ------- | ------ | ---- | ------------ |
| key     | string | 是   | 图片属性名。 |
| value   | string | 是   | 属性值。     |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> |  Promise对象。无返回结果的Promise对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.modifyImageProperty("ImageWidth", "120").then(() => {
  imageSourceApi.getImageProperty("ImageWidth").then((width: string) => {
    console.info(`ImageWidth is :${width}`);
  }).catch((error: BusinessError) => {
    console.error('Failed to get the Image Width.');
  })
}).catch((error: BusinessError) => {
  console.error('Failed to modify the Image Width');
})
```

## modifyImageProperty<sup>(deprecated)</sup>

modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void

通过指定的键修改图片属性的值，callback形式返回结果，仅支持JPEG、PNG和HEIF<sup>12+</sup>（不同硬件设备支持情况不同）文件，且需要包含exif信息。其中可以通过supportedFormats属性查询是否支持HEIF格式的exif读写。

> **说明：**
>
> 调用modifyImageProperty修改属性会改变属性字节长度，使用buffer创建的ImageSource调用modifyImageProperty会导致buffer内容覆盖，目前buffer创建的ImageSource不支持调用此接口，请改用fd或path创建的ImageSource。
> 
>从API version 11开始不再维护，建议使用[modifyImageProperty](#modifyimageproperty11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名   | 类型                | 必填 | 说明                           |
| -------- | ------------------- | ---- | ------------------------------ |
| key      | string              | 是   | 图片属性名。                   |
| value    | string              | 是   | 属性值。                       |
| callback | AsyncCallback\<void> | 是   | 回调函数，当修改图片属性值成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageSourceApi.modifyImageProperty("ImageWidth", "120", (err: BusinessError) => {
  if (err) {
    console.error(`Failed to modify the Image Width.code is ${err.code}, message is ${err.message}`);
  } else {
    console.info('Succeeded in modifying the Image Width.');
  }
})
```
