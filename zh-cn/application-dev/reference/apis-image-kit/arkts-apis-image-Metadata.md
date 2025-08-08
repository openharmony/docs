# Interface (Metadata)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 13开始支持。

图像元数据类，用于存储图像的元数据。目前支持的元数据类型可参考[MetadataType](arkts-apis-image-e.md#metadatatype13)。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## getProperties<sup>13+</sup>

getProperties(key: Array\<string>): Promise\<Record\<string, string | null>>

获取图像中属性的值，使用Promise形式返回。如要查询属性值信息请参考[PropertyKey](arkts-apis-image-e.md#propertykey7)、[FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13)和[GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型           | 必填 | 说明                     |
| ------ | -------------- | ---- | ------------------------ |
| key    | Array\<string> | 是   | 要获取其值的属性的名称。 |

**返回值：**

| 类型                                     | 说明                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| Promise\<Record<string, string \| null>> | Promise对象，返回元数据要获取的属性的值，如获取失败则返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); //图片包含exif metadata。
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    await metaData.getProperties(["ImageWidth", "ImageLength"]).then((data2) => {
      console.info('Get properties ',JSON.stringify(data2));
    }).catch((error: BusinessError) => {
      console.error('Get properties failed error.code: ' +JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## setProperties<sup>13+</sup>

setProperties(records: Record\<string, string | null>): Promise\<void>

批量设置图片元数据中的指定属性的值，使用Promise形式返回。如要查询属性值信息请参考[PropertyKey](arkts-apis-image-e.md#propertykey7)、[FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13)和[GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                           | 必填 | 说明                     |
| ------- | ------------------------------ | ---- | ------------------------ |
| records | Record<string, string \| null> | 是   | 要修改的属性和值的数组。 |

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise对象，如获取失败则返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function SetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); //图片包含exif metadata。
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    let setkey: Record<string, string | null> = {
      "ImageWidth": "200",
      "ImageLength": "300"
    };
    await metaData.setProperties(setkey).then(async () => {
      console.info('Set auxpictureobj properties success.');
    }).catch((error: BusinessError) => {
      console.error('Failed to set metadata Properties. code is ${error.code}, message is ${error.message}');
    })
  } else {
    console.error('AuxPictureObj metadata is null. ');
  }
}
```

## getAllProperties<sup>13+</sup>

getAllProperties(): Promise\<Record<string, string | null>>

获取图片中所有元数据的属性和值，使用Promise形式返回。如要查询属性值信息请参考[PropertyKey](arkts-apis-image-e.md#propertykey7)、[FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13)和[GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20)。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                                     | 说明                                        |
| ---------------------------------------- | ------------------------------------------- |
| Promise\<Record<string, string \| null>> | Promise对象，返回元数据拥有的所有属性的值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetAllProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); //图片包含exif metadata。
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    await metaData.getAllProperties().then((data2) => {
      const count = Object.keys(data2).length;
      console.info('Metadata have ', count, ' properties');
      console.info('Get metadata all properties: ', JSON.stringify(data2));
    }).catch((error: BusinessError) => {
      console.error('Get metadata all properties failed error.code: ' +JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## clone<sup>13+</sup>

clone(): Promise\<Metadata>

对元数据进行克隆，用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                              | 说明                              |
| --------------------------------- | --------------------------------- |
| Promise\<[Metadata](arkts-apis-image-Metadata.md)> | Promise对象，成功返回元数据实例。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function clone(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); //图片包含exif metadata。
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    let new_metadata: image.Metadata = await metaData.clone();
    new_metadata.getProperties(["ImageWidth"]).then((data1) => {
      console.info('Clone new_metadata and get Properties.', JSON.stringify(data1));
    }).catch((err: BusinessError) => {
      console.error('Clone new_metadata failed.', JSON.stringify(err));
    });
  } else {
    console.error('Metadata is null.');
  }
}
```
