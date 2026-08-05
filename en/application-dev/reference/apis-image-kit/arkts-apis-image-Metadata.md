# Interface (Metadata)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=a569cef255f0bfd2be482f42d11f341117248869 translatedAt=2026-08-03T03:56:17.415Z pushedAt=2026-08-04T03:23:13.940Z -->

The **Metadata** class provides APIs for storing image metadata. For details about the supported metadata types, see [MetadataType](arkts-apis-image-e.md#metadatatype13).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 13.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## getProperties<sup>13+</sup>

getProperties(key: Array\<string>): Promise\<Record\<string, string \| null>>

Obtains the values of properties from the image's metadata. This API uses a promise to return the result.

For information about the property values, see [PropertyKey](arkts-apis-image-e.md#propertykey7), [FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13), [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20), and [HeifsPropertyKey](arkts-apis-image-e.md#heifspropertykey23).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type          | Mandatory| Description                    |
| ------ | -------------- | ---- | ------------------------ |
| key    | Array\<string> | Yes  | Names of the properties.|

**Return value**

| Type                                    | Description                                                        |
| ---------------------------------------- | ------------------------------------------------------------ |
| Promise\<Record\<string, string \| null>> | Promise used to return the property values. If the operation fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // An image containing Exif metadata is required.
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
      console.error(`Failed to get properties. error.code is ${error.code}, error.message is ${error.message}`);
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## setProperties<sup>13+</sup>

setProperties(records: Record\<string, string \| null>): Promise\<void>

Sets the values of properties for the image's metadata in batches. This API uses a promise to return the result.

For information about the property values, see [PropertyKey](arkts-apis-image-e.md#propertykey7), [FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13), [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20), and [HeifsPropertyKey](arkts-apis-image-e.md#heifspropertykey23).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                          | Mandatory| Description                    |
| ------- | ------------------------------ | ---- | ------------------------ |
| records | Record\<string, string \| null> | Yes  | Array of properties and their values.|

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function SetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // An image containing Exif metadata is required.
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
      console.info('Succeeded in setting AuxPictureObj properties.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to set metadata Properties. code is ${error.code}, message is ${error.message}`);
    })
  } else {
    console.error('AuxPictureObj metadata is null. ');
  }
}
```

## getAllProperties<sup>13+</sup>

getAllProperties(): Promise\<Record\<string, string \| null>>

Obtains all properties and values from the image's metadata. This API uses a promise to return the result.

For information about the property values, see [PropertyKey](arkts-apis-image-e.md#propertykey7), [FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13), [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20), and [HeifsPropertyKey](arkts-apis-image-e.md#heifspropertykey23).

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                    | Description                                       |
| ---------------------------------------- | ------------------------------------------- |
| Promise\<Record\<string, string \| null>> | Promise used to return the values of all properties.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetAllProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // An image containing Exif metadata is required.
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
      console.info(`Get metadata all properties: ${data2}`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to get metadata all properties. error.code is ${error.code}, error.message is ${error.message}`);
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## clone<sup>13+</sup>

clone(): Promise\<Metadata>

Clones the metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise\<[Metadata](arkts-apis-image-Metadata.md)> | Promise used to return the metadata instance.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Clone(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // An image containing Exif metadata is required.
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
      console.info(`Clone new_metadata and get Properties: ${data1}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to clone new_metadata, error : ${err}`);
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## getBlob<sup>23+</sup>

getBlob(): Promise\<ArrayBuffer>

Obtains the metadata in binary format. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise\<ArrayBuffer> | Promise that returns the binary data of the metadata.|

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg'; // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function GetBlob(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let pictureObj: image.Picture = await imageSource.createPicture();
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    let blob = await metaData.getBlob();
    if (blob != undefined) {
      console.info("Succeeded in getting blob.");
    }
  }
}
```

## setBlob<sup>23+</sup>

setBlob(blob: ArrayBuffer): Promise\<void>

Replaces the current metadata with binary data. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                |
| ------ | ----------- | ---- | -------------------- |
| blob   | ArrayBuffer | Yes  | Binary data used to replace the metadata.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 7600206  | Invalid parameter. Possible causes: The blob is empty or has a length of 0. |

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg'; // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function setBlob(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let pictureObj: image.Picture = await imageSource.createPicture();
  let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
  let metaData: image.Metadata | null = await pictureObj.getMetadata(metadataType);
  if (metaData != null) {
    let blob = await metaData.getBlob();
    if (blob != undefined) {
      console.info("Succeeded in getting blob.");
      metaData.setBlob(blob);
    }
    let new_blob = metaData.getBlob();
    if (new_blob != undefined) {
      console.info("new_blob is not undefined");
    }
  }
}
```