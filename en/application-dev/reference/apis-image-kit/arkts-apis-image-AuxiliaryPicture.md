# Interface (AuxiliaryPicture)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=a569cef255f0bfd2be482f42d11f341117248869 translatedAt=2026-08-03T03:54:57.890Z pushedAt=2026-08-04T03:36:08.540Z -->

The **AuxiliaryPicture** class is used to read or write auxiliary picture data of an image and obtain auxiliary picture information of an image. The supported types of auxiliary pictures can be found in [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13).

Before calling any API in AuxiliaryPicture, you must create an AuxiliaryPicture instance using [image.createAuxiliaryPicture](arkts-apis-image-f.md#imagecreateauxiliarypicture13) or [getAuxiliaryPicture](./arkts-apis-image-Picture.md#getauxiliarypicture13) in Picture.

Images occupy a large amount of memory. When you finish using an AuxiliaryPicture instance, call [release](#release13) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 13.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## writePixelsFromBuffer<sup>13+</sup>

writePixelsFromBuffer(data: ArrayBuffer): Promise\<void>

Reads auxiliary picture data from the ArrayBuffer and writes the data to the AuxiliaryPicture object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description            |
| ------ | ----------- | ---- | ---------------- |
| data   | ArrayBuffer | Yes  | Pixels of the auxiliary picture.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
async function WritePixelsFromBuffer(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // An HDR-compatible image is required.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(image.AuxiliaryPictureType.GAINMAP);
  if(auxPictureObj != null) {
    let auxBuffer: ArrayBuffer = await auxPictureObj.readPixelsToBuffer();
    await auxPictureObj.writePixelsFromBuffer(auxBuffer);
    console.info('Succeeded in writing pixels from buffer.');
  } else {
    console.error('AuxPictureObj is null.');
  }
}
```

## readPixelsToBuffer<sup>13+</sup>

readPixelsToBuffer(): Promise\<ArrayBuffer>

Reads pixels of this auxiliary picture and writes the data to an ArrayBuffer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the pixels of the auxiliary picture.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ReadPixelsToBuffer(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // An HDR-compatible image is required.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(image.AuxiliaryPictureType.GAINMAP);
  if(auxPictureObj != null) {
    await auxPictureObj.readPixelsToBuffer().then((pixelsBuffer: ArrayBuffer) => {
      console.info('Succeeded in reading pixels to buffer success.' );
    }).catch((error: BusinessError) => {
      console.error(`Failed to read pixels to buffer. error.code: ${error.code}, error.message: ${error.message}`);
    });
  } else {
    console.error('AuxPictureObj is null.');
  }
}
```

## getType<sup>13+</sup>

getType(): AuxiliaryPictureType

Obtains the type of this auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                           | Description                        |
| ----------------------------------------------- | ---------------------------- |
| [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | Type of the auxiliary picture.|

**Example**

```ts
async function GetAuxiliaryPictureType(auxPictureObj : image.AuxiliaryPicture) {
  if (auxPictureObj != null) {
    let type: image.AuxiliaryPictureType = auxPictureObj.getType();
    console.info('Succeeded in getting auxiliary picture type ' +  JSON.stringify(type));
  } else {
    console.error('Failed to get auxiliary picture type.');
  }
}
```

## setMetadata<sup>13+</sup>

setMetadata(metadataType: MetadataType, metadata: Metadata): Promise\<void>

Sets the metadata for this auxiliary picture. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type                           | Mandatory| Description                                |
| ------------ | ------------------------------- | ---- | ------------------------------------ |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | Yes  | Metadata type, which is used to set the corresponding metadata.|
| metadata     | [Metadata](arkts-apis-image-Metadata.md)         | Yes  | Metadata object.                        |

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function SetAuxPictureObjMetadata(exifContext: Context, auxPictureObj: image.AuxiliaryPicture) {
  const exifResourceMgr = exifContext.resourceManager;
  const exifRawFile = await exifResourceMgr.getRawFileContent("exif.jpg"); // An image containing Exif metadata is required.
  let exifOps: image.SourceOptions = {
    sourceDensity: 98,
  }
  let exifImageSource: image.ImageSource = image.createImageSource(exifRawFile.buffer as ArrayBuffer, exifOps);
  let exifCommodityPixelMap: image.PixelMap = await exifImageSource.createPixelMap();
  let exifPictureObj: image.Picture = image.createPicture(exifCommodityPixelMap);
  if (exifPictureObj != null) {
    console.info('Succeeded in creating picture.');
  } else {
    console.error('Failed to create picture.');
  }

  if (auxPictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let exifMetaData: image.Metadata = await exifPictureObj.getMetadata(metadataType);
    auxPictureObj.setMetadata(metadataType, exifMetaData).then(() => {
      console.info('Succeeded in setting metadata.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to set metadata. error.code: ${error.code}, error.message: ${error.message}`);
    });
  } else {
    console.error('AuxPictureObjMetaData is null');
  }
}
```

## getMetadata<sup>13+</sup>

getMetadata(metadataType: MetadataType): Promise\<Metadata>

Obtains the metadata of this auxiliary picture. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type                           | Mandatory| Description                                  |
| ------------ | ------------------------------- | ---- | -------------------------------------- |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | Yes  | Metadata type, which is used to obtain metadata of the corresponding type.|

**Return value**

| Type                            | Description            |
| -------------------------------- | ---------------- |
| Promise<[Metadata](arkts-apis-image-Metadata.md)> | Promise that returns the metadata.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
async function GetAuxPictureObjMetadata(auxPictureObj: image.AuxiliaryPicture) {
  if (auxPictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let auxPictureObjMetaData: image.Metadata | null = await auxPictureObj.getMetadata(metadataType);
    if (auxPictureObjMetaData != null) {
      console.info('Succeeded in getting AuxPictureObj Metadata.' );
    } else {
      console.error('Failed to get AuxPictureObj Metadata.');
    }
  } else {
    console.error('Get AuxPictureObj is null.');
  }
}
```

## getAuxiliaryPictureInfo<sup>13+</sup>

getAuxiliaryPictureInfo(): AuxiliaryPictureInfo

Obtains the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| [AuxiliaryPictureInfo](arkts-apis-image-i.md#auxiliarypictureinfo13) | Auxiliary picture information.|

**Example**

```ts
async function GetAuxiliaryPictureInfo(auxPictureObj: image.AuxiliaryPicture) {
  if(auxPictureObj != null) {
    let auxinfo: image.AuxiliaryPictureInfo = auxPictureObj.getAuxiliaryPictureInfo();
    console.info('GetAuxiliaryPictureInfo Type: ' + auxinfo.auxiliaryPictureType +
      ' height: ' + auxinfo.size.height + ' width: ' + auxinfo.size.width +
      ' rowStride: ' +  auxinfo.rowStride +  ' pixelFormat: ' + auxinfo.pixelFormat +
      ' colorSpace: ' +  auxinfo.colorSpace);
  } else {
    console.error('Failed to get auxiliary picture information.');
  }
}
```

## setAuxiliaryPictureInfo<sup>13+</sup>

setAuxiliaryPictureInfo(info: AuxiliaryPictureInfo): void

Sets the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                                           | Mandatory| Description              |
| ------ | ----------------------------------------------- | ---- | ------------------ |
| info   | [AuxiliaryPictureInfo](arkts-apis-image-i.md#auxiliarypictureinfo13) | Yes  | Auxiliary picture information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | :----------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';

async function SetAuxiliaryPictureInfo(auxPictureObj: image.AuxiliaryPicture) {
  if(auxPictureObj != null) {
    let colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
    let info: image.AuxiliaryPictureInfo = {
      auxiliaryPictureType: image.AuxiliaryPictureType.GAINMAP,
      size: {height: 100, width: 200},
      pixelFormat: image.PixelMapFormat.RGBA_8888,
      rowStride: 0,
      colorSpace: colorSpaceManager.create(colorSpaceName),
    };
    auxPictureObj.setAuxiliaryPictureInfo(info);
  }
}
```

## release<sup>13+</sup>

release():void

Releases this AuxiliaryPicture object. No value is returned.

Images occupy a large amount of memory. When you finish using an AuxiliaryPicture instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Example**

```ts
async function Release(auxPictureObj: image.AuxiliaryPicture) {
  let funcName = "Release";
  if (auxPictureObj != null) {
    auxPictureObj.release();
    if (auxPictureObj.getType() == null) {
      console.info(funcName, 'Success !');
    } else {
      console.error(funcName, 'Failed !');
    }
  } else {
    console.error('PictureObj is null');
  }
}
```