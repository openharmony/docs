# Interface (Metadata)

> **NOTE**
>
> The initial APIs of this module are supported since API version 13. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **Metadata** class is used to store image metadata. For details about the supported metadata types, see [MetadataType](arkts-apis-image-e.md#metadatatype13).

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## getProperties<sup>13+</sup>

getProperties(key: Array\<string>): Promise\<Record\<string, string | null>>

Obtains the values of properties from the image's metadata. This API uses a promise to return the result. For details about how to obtain the property values, see [PropertyKey](arkts-apis-image-e.md#propertykey7), [FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13), and [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type          | Mandatory| Description                    |
| ------ | -------------- | ---- | ------------------------ |
| key    | Array\<string> | Yes  | Names of the properties.|

**Return value**

| Type                                    | Description                                                        |
| ---------------------------------------- | ------------------------------------------------------------ |
| Promise\<Record<string, string \| null>> | Promise used to return the property values. If the operation fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
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

Sets the values of properties for the image's metadata. This API uses a promise to return the result. For details about how to obtain the property values, see [PropertyKey](arkts-apis-image-e.md#propertykey7), [FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13), and [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                          | Mandatory| Description                    |
| ------- | ------------------------------ | ---- | ------------------------ |
| records | Record<string, string \| null> | Yes  | Array of properties and their values.|

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed; |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function SetProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
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

Obtains all properties and values from the image's metadata. This API uses a promise to return the result. For details about how to obtain the property values, see [PropertyKey](arkts-apis-image-e.md#propertykey7), [FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13), and [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20).

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                    | Description                                       |
| ---------------------------------------- | ------------------------------------------- |
| Promise\<Record<string, string \| null>> | Promise used to return the values of all properties.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetAllProperties(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
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

Clones the metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| Promise\<[Metadata](arkts-apis-image-Metadata.md)> | Promise used to return the metadata instance.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function clone(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("exif.jpg"); // The image contains EXIF metadata.
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
