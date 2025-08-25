# Interface (AuxiliaryPicture)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 13.

The auxiliary picture is generally used to assist the main picture in displaying special information, so that the image includes richer information. The **AuxiliaryPicture** class is used to read or write auxiliary picture data of an image and obtain auxiliary picture information of an image. Before calling any API in AuxiliaryPicture, you must use [createAuxiliaryPicture](arkts-apis-image-f.md#imagecreateauxiliarypicture13) to create a AuxiliaryPicture object.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## writePixelsFromBuffer<sup>13+</sup>

writePixelsFromBuffer(data: ArrayBuffer): Promise\<void>

Reads pixels from an ArrayBuffer and writes the data to this AuxiliaryPicture object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description            |
| ------ | ----------- | ---- | ---------------- |
| data   | ArrayBuffer | Yes  | Pixels of the auxiliary picture.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function WritePixelsFromBuffer(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // Support for HDR images is required.
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
    console.info('Write pixels from buffer success.');
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
import { image } from '@kit.ImageKit';

async function ReadPixelsToBuffer(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // Support for HDR images is required.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(image.AuxiliaryPictureType.GAINMAP);
  if(auxPictureObj != null) {
    await auxPictureObj.readPixelsToBuffer().then((pixelsBuffer: ArrayBuffer) => {
      console.info('Read pixels to buffer success.' );
    }).catch((error: BusinessError) => {
      console.error('Read pixels to buffer failed error.code: ' + JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
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
import { image } from '@kit.ImageKit';

async function GetAuxiliaryPictureType() {
  if (auxPictureObj != null) {
    let type: image.AuxiliaryPictureType = auxPictureObj.getType();
    console.info('Success get auxiliary picture type ' +  JSON.stringify(type));
  } else {
    console.error('Failed get auxiliary picture type ');
  }
}
```

## setMetadata<sup>13+</sup>

setMetadata(metadataType: MetadataType, metadata: Metadata): Promise\<void>

Sets the metadata for this auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type                           | Mandatory| Description                                |
| ------------ | ------------------------------- | ---- | ------------------------------------ |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | Yes  | Metadata type, which is used to set the corresponding metadata.|
| metadata     | [Metadata](arkts-apis-image-Metadata.md)         | Yes  | Metadata object.                        |

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function SetAuxPictureObjMetadata(exifContext: Context) {
  const exifResourceMgr = exifContext.resourceManager;
  const exifRawFile = await exifResourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
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

  if (auxPictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let exifMetaData: image.Metadata = await exifPictureObj.getMetadata(metadataType);
    auxPictureObj.setMetadata(metadataType, exifMetaData).then(() => {
      console.info('Set metadata success');
    }).catch((error: BusinessError) => {
      console.error('Set metadata failed.error.code: ${error.code}, error.message: ${error.message}');
    });
  } else {
    console.error('AuxPictureObjMetaData is null');
  }
}
```

## getMetadata<sup>13+</sup>

getMetadata(metadataType: MetadataType): Promise\<Metadata>

Obtains the metadata of this auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type                           | Mandatory| Description                                  |
| ------------ | ------------------------------- | ---- | -------------------------------------- |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | Yes  | Metadata type, which is used to obtain metadata of the corresponding type.|

**Return value**

| Type                            | Description            |
| -------------------------------- | ---------------- |
| Promise<[Metadata](arkts-apis-image-Metadata.md)> | Metadata object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function GetAuxPictureObjMetadata() {
  if (auxPictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let auxPictureObjMetaData: image.Metadata | null = await auxPictureObj.getMetadata(metadataType);
    if (auxPictureObjMetaData != null) {
      console.info('Get auxpictureobj Metadata success' );
    } else {
      console.error('Get auxpictureobj Metadata failed');
    }
  } else {
    console.error('Get auxpictureobj is null.');
  }
}
```

## getAuxiliaryPictureinfo<sup>13+</sup>

getAuxiliaryPictureInfo(): AuxiliaryPictureInfo

Obtains the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| [AuxiliaryPictureInfo](arkts-apis-image-i.md#auxiliarypictureinfo13) | Promise used to return the auxiliary picture information.|

**Example**

```ts
import { image } from '@kit.ImageKit';

async function GetAuxiliaryPictureInfo() {
  if(auxPictureObj != null) {
    let auxinfo: image.AuxiliaryPictureInfo = auxPictureObj.getAuxiliaryPictureInfo();
    console.info('GetAuxiliaryPictureInfo Type: ' + auxinfo.auxiliaryPictureType +
      ' height: ' + auxinfo.size.height + ' width: ' + auxinfo.size.width +
      ' rowStride: ' +  auxinfo.rowStride +  ' pixelFormat: ' + auxinfo.pixelFormat +
      ' colorSpace: ' +  auxinfo.colorSpace);
  } else {
    console.error('Get auxiliary picture information failed');
  }
}
```

## setAuxiliaryPictureinfo<sup>13+</sup>

setAuxiliaryPictureInfo(info: AuxiliaryPictureInfo): void

Sets the auxiliary picture information.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                                           | Mandatory| Description              |
| ------ | ----------------------------------------------- | ---- | ------------------ |
| info   | [AuxiliaryPictureInfo](arkts-apis-image-i.md#auxiliarypictureinfo13) | Yes  | Auxiliary picture information.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | :----------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { image } from '@kit.ImageKit';

async function SetAuxiliaryPictureInfo() {
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

**System capability**: SystemCapability.Multimedia.Image.Core

**Example**

```ts
import { image } from '@kit.ImageKit';

async function Release() {
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
