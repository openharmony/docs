# Interface (Picture)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=a569cef255f0bfd2be482f42d11f341117248869 translatedAt=2026-08-03T03:56:57.248Z pushedAt=2026-08-04T03:21:17.349Z -->

An image that contains special information can be decoded into a picture object, which generally contains the main picture, auxiliary picture, and metadata. The main picture contains most information about the image and is mainly used to render the image. The auxiliary picture is used to store data related to but different from the main picture, revealing more comprehensive details. The metadata is generally used to store information about the image file. The picture object class is used to read or write picture objects. Before calling any API in Picture, you must use [image.createPicture](arkts-apis-image-f.md#imagecreatepicture13) to create a Picture object.

Images occupy a large amount of memory. When you finish using a Picture instance, call [release](#release13) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 13.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## getMainPixelmap<sup>13+</sup>

getMainPixelmap(): PixelMap

Obtains the PixelMap object of the main picture. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type               | Description                  |
| ------------------- | ---------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetMainPixelmap(pictureObj : image.Picture) {
  let funcName = "getMainPixelmap";
  if (pictureObj != null) {
    let mainPixelmap: image.PixelMap = pictureObj.getMainPixelmap();
    if (mainPixelmap != null) {
      mainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info(`Succeeded in getting main PixelMap information. Height: ${imageInfo.size.height}, width: ${imageInfo.size.width}.`);
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, `Failed to get main PixelMap information. Code: ${error.code}, message: ${error.message}.`);
      });
    }
  } else {
    console.error('Picture object is null.');
  }
}
```

## getHdrComposedPixelmap<sup>13+</sup>

getHdrComposedPixelmap(): Promise\<PixelMap>

Generates a High Dynamic Range (HDR) image and obtains its PixelMap object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                         | Description                       |
| ----------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 7600901  | Inner unknown error. Please check the logs for detailed information. |
| 7600201  | Unsupported operation. e.g.,1. The picture does not has a gainmap. 2. MainPixelMap's allocator type is not DMA. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetHdrComposedPixelmap(pictureObj : image.Picture) {
  let funcName = "getHdrComposedPixelmap";
  if (pictureObj != null) { // An HDR image is contained.
    let hdrComposedPixelmap: image.PixelMap = await pictureObj.getHdrComposedPixelmap();
    if (hdrComposedPixelmap != null) {
      hdrComposedPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info(`Succeeded in getting HDR composed PixelMap information. Height: ${imageInfo.size.height}, width: ${imageInfo.size.width}.`);
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, `Failed to get HDR composed PixelMap information. Code: ${error.code}, message: ${error.message}.`);
      });
    }
  } else {
    console.error('Picture object is null.');
  }
}
```

## getHdrComposedPixelmapWithOptions<sup>23+</sup>

getHdrComposedPixelmapWithOptions(options?: HdrComposeOptions): Promise\<PixelMap | undefined>

Composites an HDR image and returns PixelMap of the image. Composition options (such as PixelMapFormat) can be passed. This API uses a promise to return the result.

The Picture object that calls this API must contain the main picture, gain map, and metadata.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name          | Type                | Mandatory| Description        |
| ---------------- | -------------------- | ---- | ------------ |
| options             | [HdrComposeOptions](arkts-apis-image-i.md#hdrcomposeoptions23) | No  | Options for HDR composition.|

**Return value**

| Type                         | Description                       |
| ----------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md) \| undefined> | Promise, which returns the PixelMap object or **undefined**.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 7600201 | Unsupported operation.|

**Example**

```ts
// EntryAbility.ets
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function GetHdrComposedPixelmapWithOptions(picture : image.Picture) {
  if (picture == null) {
    console.error('Picture is null.');
    return;
  }

  let opt: image.HdrComposeOptions = {
    desiredPixelFormat: image.PixelMapFormat.RGBA_1010102
  };
  let hdrComposedPixelmap: image.PixelMap | undefined = await picture.getHdrComposedPixelmapWithOptions(opt);
  if (hdrComposedPixelmap == null || hdrComposedPixelmap == undefined) {
    console.error(`Failed to get an HDR composed PixelMap with options.`);
    return;
  }

  hdrComposedPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
    if (imageInfo !== null) {
      console.info(`Succeeded in getting HDR composed PixelMap information with options. Height: ${imageInfo.size.height}, width: ${imageInfo.size.width}.`);
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to get HDR composed PixelMap information with options. Code: ${error.code}, message: ${error.message}.`);
  });
}
```

## hdrComposeToMainPixelmap

hdrComposeToMainPixelmap(): Promise\<void>

Composes the main picture and gain map of a Picture object into an HDR image. After composition, the main picture of the original Picture is replaced with the HDR image, and the gain map of the original Picture is deleted. This API uses a promise to return the result.

The Picture object on which this API is called must contain a main picture and a gain map.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Image.Core

**Returns**

| Type                          | Description                        |
| ----------------------------- | ---------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Image Error Codes](errorcode-image.md).

| ID   | Error Message               |
| ---- | --------------------------- |
| 7600201 | Unsupported operation. For example: 1. The picture does not have a gainmap. 2. pixelMap's allocator type is not DMA. |

**Example**

```ts
// EntryAbility.ets
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function HdrComposeToMainPixelmap(picture : image.Picture) {
  if (picture == null) {
    console.error('picture is null');
    return;
  }
  try {
    await picture.hdrComposeToMainPixelmap();
  } catch(error) {
    console.error(`Failed to do HdrComposeToMainPixelmap. error.code: ${error.code} ,error.message: ${error.message}`);
  }
}
```

## getGainmapPixelmap<sup>13+</sup>

getGainmapPixelmap(): PixelMap | null

Obtains the PixelMap object of the gain map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                     | Description                                  |
| ------------------------- | -------------------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) \| null | PixelMap object obtained. If there is no PixelMap object, null is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetGainmapPixelmap(pictureObj : image.Picture) {
  let funcName = "getGainmapPixelmap";
  if (pictureObj != null) { // A gain map is contained.
    let gainPixelmap: image.PixelMap | null = pictureObj.getGainmapPixelmap();
    if (gainPixelmap != null) {
      gainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
        if (imageInfo != null) {
          console.info(`Succeeded in getting gainmap PixelMap information. Height: ${imageInfo.size.height}, width: ${imageInfo.size.width}.`);
        } else {
          console.error('Gainmap PixelMap is null.');
        }
      }).catch((error: BusinessError) => {
        console.error(funcName, `Failed to get gainmap PixelMap information. Code: ${error.code}, message: ${error.message}.`);
      });
    } else {
      console.info('Gainmap PixelMap is null.');
    }
  } else {
    console.error('Picture object is null.');
  }
}
```

## setAuxiliaryPicture<sup>13+</sup>

setAuxiliaryPicture(type: AuxiliaryPictureType, auxiliaryPicture: AuxiliaryPicture): void

Sets an auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name          | Type                | Mandatory| Description        |
| ---------------- | -------------------- | ---- | ------------ |
| type             | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | Yes  | Type of the auxiliary picture.|
| auxiliaryPicture | [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md)     | Yes  | AuxiliaryPicture object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
async function SetAuxiliaryPicture(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // An HDR-compatible image is required.
  let ops: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, ops);
  let pixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(pixelMap);
  if (pictureObj != null) {
    console.info('Succeeded in creating picture.');
  } else {
    console.error('Failed to create picture.');
  }

  if (pictureObj != null) {
    let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
    let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(type);
    if (auxPictureObj != null) {
      pictureObj.setAuxiliaryPicture(type, auxPictureObj);
    }
  }
}
```

## getAuxiliaryPicture<sup>13+</sup>

getAuxiliaryPicture(type: AuxiliaryPictureType): AuxiliaryPicture | null

Obtains an auxiliary picture by type.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                | Mandatory| Description        |
| ------ | -------------------- | ---- | ------------ |
| type   | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | Yes  | Type of the auxiliary picture.|

**Return value**

| Type                  | Description                                          |
| ---------------------- | ---------------------------------------------- |
| [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md) \| null | AuxiliaryPicture object. If there is no AuxiliaryPicture object, null is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
async function GetAuxiliaryPicture(pictureObj : image.Picture) {
  if (pictureObj != null) {
    let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
    let auxPictureObj: image.AuxiliaryPicture | null = pictureObj.getAuxiliaryPicture(type);
  }
}
```

## setMetadata<sup>13+</sup>

setMetadata(metadataType: MetadataType, metadata: Metadata): Promise\<void>

Sets the metadata for this Picture object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type        | Mandatory| Description        |
| ------------ | ------------ | ---- | ------------ |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | Yes  | Metadata type.|
| metadata     | [Metadata](arkts-apis-image-Metadata.md)     | Yes  | Metadata object.|

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

async function SetPictureObjMetadata(exifContext: Context) {
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

  if (exifPictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let exifMetaData: image.Metadata = await exifPictureObj.getMetadata(metadataType);
    exifPictureObj.setMetadata(metadataType, exifMetaData).then(() => {
      console.info('Succeeded in setting metadata.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to set metadata. error.code: ${error.code} ,error.message: ${error.message}`);
    });
  } else {
    console.error('exifPictureObj is null');
  }
}
```

## getMetadata<sup>13+</sup>

getMetadata(metadataType: MetadataType): Promise\<Metadata>

Obtains the metadata of this Picture object. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type        | Mandatory| Description        |
| ------------ | ------------ | ---- | ------------ |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | Yes  | Metadata type.|

**Return value**

| Type              | Description                     |
| ------------------ | ------------------------- |
| Promise\<[Metadata](arkts-apis-image-Metadata.md)> | Promise used to return the metadata.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

```ts
async function GetPictureObjMetadataProperties(pictureObj : image.Picture) {
  if (pictureObj != null) {
    let metadataType: image.MetadataType = image.MetadataType.EXIF_METADATA;
    let pictureObjMetaData: image.Metadata = await pictureObj.getMetadata(metadataType);
    if (pictureObjMetaData != null) {
      console.info('Succeeded in getting picture metadata.');
    } else {
      console.error('Failed to get picture metadata.');
    }
  } else {
    console.error(" pictureObj is null");
  }
}
```

## marshalling<sup>13+</sup>

marshalling(sequence: rpc.MessageSequence): void

Marshals this Picture object and writes it to a MessageSequence object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                                               | Mandatory| Description                     |
| -------- | ------------------------------------------------------------------- | ---- | ------------------------- |
| sequence | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.                                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  picture: image.Picture | null = null;
  constructor(conPicture: image.Picture) {
    this.picture = conPicture;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    if(this.picture != null) {
      this.picture.marshalling(messageSequence);
      console.info('Succeeded in marshalling a picture.');
      return true;
    } else {
      console.error('Failed to marshall a picture.');
      return false;
    }
  }
  unmarshalling(messageSequence : rpc.MessageSequence) {
    this.picture = image.createPictureFromParcel(messageSequence);
    this.picture.getMainPixelmap().getImageInfo().then((imageInfo : image.ImageInfo) => {
      console.info(`Succeeded in unmarshalling a picture and getting main PixelMap information. Height: ${imageInfo.size.height}, width: ${imageInfo.size.width}.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to unmarshall a picture. Code: ${error.code}, message: ${error.message}.`);
    });
    return true;
  }
}

async function Marshalling_UnMarshalling(pictureObj : image.Picture) {
  if (pictureObj != null) {
    let parcelable: MySequence = new MySequence(pictureObj);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    // Implement serialization.
    data.writeParcelable(parcelable);
    let ret: MySequence = new MySequence(pictureObj);
    // Implement deserialization.
    data.readParcelable(ret);
  } else {
    console.error('Picture object is null.');
  }
}
```

## release<sup>13+</sup>

release(): void

Releases this Picture object.

Images occupy a large amount of memory. When you finish using a Picture instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.Core

**Example**

```ts
async function Release(pictureObj : image.Picture) {
  let funcName = "Release";
  if (pictureObj != null) {
    pictureObj.release();
    if (pictureObj.getMainPixelmap() == null) {
      console.info(funcName, 'Succeeded in releasing a picture.');
    } else {
      console.error(funcName, 'Failed to release a picture.');
    }
  } else {
    console.error('Picture object is null.');
  }
}
```