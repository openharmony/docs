# Interface (Picture)

> **NOTE**
>
> The initial APIs of this module are supported since API version 13. Newly added APIs will be marked with a superscript to indicate their earliest API version.

An image that contains special information can be decoded into a picture object, which generally contains the main picture, auxiliary picture, and metadata. The main picture contains most information about the image and is mainly used to render the image. The auxiliary picture is used to store data related to but different from the main picture, revealing more comprehensive details. The metadata is generally used to store information about the image file. The picture object class is used to read or write picture objects. Before calling any API in Picture, you must use [createPicture](arkts-apis-image-f.md#imagecreatepicture13) to create a Picture object.

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
import { image } from '@kit.ImageKit';

async function GetHdrComposedPixelmap() {
  let funcName = "getHdrComposedPixelmap";
  if (pictureObj != null) { // An HDR image is contained.
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

Obtains the PixelMap object of the gain map.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                     | Description                                  |
| ------------------------- | -------------------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) \| null | PixelMap object obtained. If there is no PixelMap object, null is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function GetGainmapPixelmap() {
  let funcName = "getGainmapPixelmap";
  if (pictureObj != null) { // A gain map is contained.
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

Sets an auxiliary picture.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name          | Type                | Mandatory| Description        |
| ---------------- | -------------------- | ---- | ------------ |
| type             | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | Yes  | Type of the auxiliary picture.|
| auxiliaryPicture | [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md)     | Yes  | AuxiliaryPicture object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
import { image } from '@kit.ImageKit';

async function SetAuxiliaryPicture(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // Support for HDR images is required.
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

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**Example**

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

Sets the metadata for this Picture object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name      | Type        | Mandatory| Description        |
| ------------ | ------------ | ---- | ------------ |
| metadataType | [MetadataType](arkts-apis-image-e.md#metadatatype13) | Yes  | Metadata type.|
| metadata     | [Metadata](arkts-apis-image-Metadata.md)     | Yes  | Metadata object.|

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

async function SetPictureObjMetadata(exifContext: Context) {
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

Obtains the metadata of this Picture object.

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

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 7600202  | Unsupported metadata. Possible causes: 1. Unsupported metadata type. 2. The metadata type does not match the auxiliary picture type. |

**Example**

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

Marshals this Picture object and writes it to a MessageSequence object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                                               | Mandatory| Description                     |
| -------- | ------------------------------------------------------------------- | ---- | ------------------------- |
| sequence | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.                                                   |

**Example**

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

Releases this Picture object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Example**

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
