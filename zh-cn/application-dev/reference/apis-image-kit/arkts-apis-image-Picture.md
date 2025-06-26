# Interface (Picture)

> **说明：**
>
> 本模块首批接口从API version 13开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

一些包含特殊信息的图片可以解码为多图对象，多图对象一般包含主图、辅助图和元数据。其中主图包含图像的大部分信息，主要用于显示图像内容；辅助图用于存储与主图相关但不同的数据，展示图像更丰富的信息；元数据一般用来存储关于图像文件的信息。多图对象类用于读取或写入多图对象。在调用Picture的方法前，需要先通过[createPicture](arkts-apis-image-f.md#imagecreatepicture13)创建一个Picture实例。

## getMainPixelmap<sup>13+</sup>

getMainPixelmap(): PixelMap

获取主图的pixelmap。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                | 说明                   |
| ------------------- | ---------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 同步返回PixelMap对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetMainPixelmap() {
  let funcName = "getMainPixelmap";
  if (pictureObj != null) {
    let mainPixelmap: image.PixelMap = pictureObj.getMainPixelmap();
    if (mainPixelmap != null) {
      mainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info('GetMainPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed error.code: ${error.code} ,error.message: ${error.message}');
      });
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

## getHdrComposedPixelmap<sup>13+</sup>

getHdrComposedPixelmap(): Promise\<PixelMap>

合成hdr图并获取hdr图的pixelmap，使用Promise形式返回结果。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                          | 说明                        |
| ----------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 7600901  | Inner unknown error. Please check the logs for detailed information. |
| 7600201  | Unsupported operation. e.g.,1. The picture does not has a gainmap. 2. MainPixelMap's allocator type is not DMA. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetHdrComposedPixelmap() {
  let funcName = "getHdrComposedPixelmap";
  if (pictureObj != null) { //图片包含Hdr图。
    let hdrComposedPixelmap: image.PixelMap = await pictureObj.getHdrComposedPixelmap();
    if (hdrComposedPixelmap != null) {
      hdrComposedPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info('GetHdrComposedPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed error.code: ${error.code} ,error.message: ${error.message}');
      });
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

## getGainmapPixelmap<sup>13+</sup>

getGainmapPixelmap(): PixelMap | null

获取增益图的pixelmap。

**系统能力：** SystemCapability.Multimedia.Image.Core

**返回值：**

| 类型                      | 说明                                   |
| ------------------------- | -------------------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) \| null | 返回Pixelmap对象，如果没有则返回null。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetGainmapPixelmap() {
  let funcName = "getGainmapPixelmap";
  if (pictureObj != null) { //图片包含增益图。
    let gainPixelmap: image.PixelMap | null = pictureObj.getGainmapPixelmap();
    if (gainPixelmap != null) {
      gainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info('GetGainmapPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
        } else {
          console.error('GainPixelmap is null');
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, 'Failed error.code: ${error.code} ,error.message: ${error.message}');
      });
    } else {
      console.info('GainPixelmap is null');
    }
  } else {
    console.error('PictureObj is null');
  }
}
```

## setAuxiliaryPicture<sup>13+</sup>

setAuxiliaryPicture(type: AuxiliaryPictureType, auxiliaryPicture: AuxiliaryPicture): void

设置辅助图。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名           | 类型                 | 必填 | 说明         |
| ---------------- | -------------------- | ---- | ------------ |
| type             | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | 是   | 辅助图类型。 |
| auxiliaryPicture | [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md)     | 是   | 辅助图对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
import { image } from '@kit.ImageKit';

async function SetAuxiliaryPicture(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg");//需要支持hdr的图片。
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let pixelMap: image.PixelMap = await imageSource.createPixelMap();
  let auxPicture: image.Picture = image.createPicture(pixelMap);
  if (auxPicture != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }

  if (pictureObj != null) {
    let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
    let auxPictureObj: image.AuxiliaryPicture | null = await auxPicture.getAuxiliaryPicture(type);
    if (auxPictureObj != null) {
      pictureObj.setAuxiliaryPicture(type, auxPictureObj);
    }
  }
}
```

## getAuxiliaryPicture<sup>13+</sup>

getAuxiliaryPicture(type: AuxiliaryPictureType): AuxiliaryPicture | null

根据类型获取辅助图。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                 | 必填 | 说明         |
| ------ | -------------------- | ---- | ------------ |
| type   | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | 是   | 辅助图类型。 |

**返回值：**

| 类型                   | 说明                                           |
| ---------------------- | ---------------------------------------------- |
| [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md) \| null | 返回AuxiliaryPicture对象，如果没有则返回null。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
import { image } from '@kit.ImageKit';

async function GetAuxiliaryPicture() {
  if (pictureObj != null) {
    let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
    let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(type);
  }
}
```

## setMetadata<sup>13+</sup>

setMetadata(metadataType: MetadataType, metadata: Metadata): Promise\<void>

设置主图的元数据。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名       | 类型         | 必填 | 说明         |
| ------------ | ------------ | ---- | ------------ |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | 是   | 元数据类型。 |
| metadata     | [Metadata](arkts-apis-image-Metadata.md)     | 是   | 元数据对象。 |

**返回值：**

| 类型           | 说明                                   |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function SetPictureObjMetadata(exifContext: Context) {
  const exifResourceMgr = exifContext.resourceManager;
  const exifRawFile = await exifResourceMgr.getRawFileContent("exif.jpg");//含有exif metadata的图片。
  let exifOps: image.SourceOptions = {
    sourceDensity: 98,
  }
  let exifImageSource: image.ImageSource = image.createImageSource(exifRawFile.buffer as ArrayBuffer, exifOps);
  let exifCommodityPixelMap: image.PixelMap = await exifImageSource.createPixelMap();
  let exifPictureObj: image.Picture = image.createPicture(exifCommodityPixelMap);
  if (exifPictureObj != null) {
    console.info('Create picture succeeded');
  } else {
    console.error('Create picture failed');
  }

  if (pictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let exifMetaData: image.Metadata = await exifPictureObj.getMetadata(metadataType);
    pictureObj.setMetadata(metadataType, exifMetaData).then(() => {
      console.info('Set metadata success');
    }).catch((error: BusinessError) => {
      console.error('Failed to set metadata. error.code: ' +JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
    });
  } else {
    console.error('PictureObj is null');
  }
}
```

## getMetadata<sup>13+</sup>

getMetadata(metadataType: MetadataType): Promise\<Metadata>

获取主图的元数据。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名       | 类型         | 必填 | 说明         |
| ------------ | ------------ | ---- | ------------ |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | 是   | 元数据类型。 |

**返回值：**

| 类型               | 说明                      |
| ------------------ | ------------------------- |
| Promise\<[Metadata](arkts-apis-image-Metadata.md)> | Promise对象。返回元数据。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**示例：**

```ts
import { image } from '@kit.ImageKit';

async function GetPictureObjMetadataProperties() {
  if (pictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let pictureObjMetaData: image.Metadata = await pictureObj.getMetadata(metadataType);
    if (pictureObjMetaData != null) {
      console.info('get picture metadata success');
    } else {
      console.error('get picture metadata is failed');
    }
  } else {
    console.error(" pictureObj is null");
  }
}
```

## marshalling<sup>13+</sup>

marshalling(sequence: rpc.MessageSequence): void

将picture序列化后写入MessageSequence。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                                                | 必填 | 说明                      |
| -------- | ------------------------------------------------------------------- | ---- | ------------------------- |
| sequence | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是   | 新创建的MessageSequence。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.                                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  picture: image.Picture | null = null;
  constructor(conPicture: image.Picture) {
    this.picture = conPicture;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    if(this.picture != null) {
      this.picture.marshalling(messageSequence);
      console.info('Marshalling success !');
      return true;
    } else {
      console.error('Marshalling failed !');
      return false;
    }
  }
  unmarshalling(messageSequence : rpc.MessageSequence) {
    this.picture = image.createPictureFromParcel(messageSequence);
    this.picture.getMainPixelmap().getImageInfo().then((imageInfo : image.ImageInfo) => {
      console.info('Unmarshalling to get mainPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width);
    }).catch((error: BusinessError) => {
      console.error('Unmarshalling failed error.code: ${error.code} ,error.message: ${error.message}');
    });
    return true;
  }
}

async function Marshalling_UnMarshalling() {
  if (pictureObj != null) {
    let parcelable: MySequence = new MySequence(pictureObj);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    // marshalling.
    data.writeParcelable(parcelable);
    let ret: MySequence = new MySequence(pictureObj);
    // unmarshalling.
    data.readParcelable(ret);
  } else {
    console.error('PictureObj is null');
  }
}
```

## release<sup>13+</sup>

release(): void

释放picture对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**示例：**

```ts
import { image } from '@kit.ImageKit';

async function Release() {
  let funcName = "Release";
  if (pictureObj != null) {
    pictureObj.release();
    if (pictureObj.getMainPixelmap() == null) {
      console.info(funcName, 'Success !');
    } else {
      console.error(funcName, 'Failed !');
    }
  } else {
    console.error('PictureObj is null');
  }
}
```
