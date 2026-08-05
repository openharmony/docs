# Interface (ImageSource)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

The **ImageSource** class provides APIs to obtain image information.

Before calling any API in ImageSource, you must use [image.createImageSource](arkts-apis-image-f.md#imagecreateimagesource) to create an ImageSource instance.

All APIs in ImageSource cannot be called concurrently.

Images occupy a large amount of memory. When you finish using an ImageSource instance, call [release](#release) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Image.ImageSource

| Name            | Type          | Read Only| Optional| Description                                                        |
| ---------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| supportedFormats | Array\<string> | Yes  | No  | Supported image formats,<br>including PNG, JPEG, BMP, GIF, WebP, DNG, HEIC<sup>12+</sup>, WBMP<sup>23+</sup>, HEIFS<sup>23+</sup>, and TIFF<sup>23+</sup>. Since API version 26.0.0, the AVIF and AVIS formats are supported.<br>Decoding support for certain formats depends on the specific device hardware. You are advised to use the [image.getImageSourceSupportedFormats](arkts-apis-image-f.md#imagegetimagesourcesupportedformats20) API before calling this API to dynamically query the decoding capabilities of the current device.|

## getImageInfo

getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void

Obtains the image information with the specified index. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| index    | number                                 | Yes  | Index of the image source. The default value is **0**, indicating the first image. If this parameter is set to N, the (N+1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).                  |
| callback | AsyncCallback<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the image information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageInfo(imageSourceObj : image.ImageSource) {
  imageSourceObj.getImageInfo(0, (error: BusinessError, imageInfo: image.ImageInfo) => {
    if (error) {
      console.error(`Failed to obtain the image information.code is ${error.code}, message is ${error.message}`);
    } else {
      console.info('Succeeded in obtaining the image information.');
    }
  })
}
```

## getImageInfo

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains the image information. This API uses an asynchronous callback to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                  | Mandatory| Description                                    |
| -------- | -------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the image information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageInfo(imageSourceObj : image.ImageSource) {
  imageSourceObj.getImageInfo((err: BusinessError, imageInfo: image.ImageInfo) => {
    if (err) {
      console.error(`Failed to obtain the image information.code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('Succeeded in obtaining the image information.');
    }
  })
}
```

## getImageInfo

getImageInfo(index?: number): Promise\<ImageInfo>

Obtains the image information. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | No  | Index of the image source. The default value is **0**, indicating the first image. If this parameter is set to N, the (N+1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| Promise<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Promise used to return the image information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageInfo(imageSourceObj : image.ImageSource) {
  imageSourceObj.getImageInfo(0)
    .then((imageInfo: image.ImageInfo) => {
      console.info('Succeeded in obtaining the image information.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to obtain the image information.code is ${error.code}, message is ${error.message}`);
    })
}
```

## getImageInfoSync<sup>12+</sup>

getImageInfoSync(index?: number): ImageInfo

Obtains the image information with the specified index. This API returns the result synchronously.

> **NOTE**
>
> This API operates synchronously and will block the current thread during execution. It should not be invoked from the main thread, as doing so can lead to application lag, frame drops, or delayed responsiveness. For details, see [Overview of Concurrency in Time-Consuming Tasks](../../arkts-utils/time-consuming-task-overview.md).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ----- | ------ | ---- | ------------------------------------- |
| index | number | No  | Index of the image source. The default value is **0**, indicating the first image. If this parameter is set to N, the (N+1)th image is used. For single-frame images, the value is always **0**. For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).|

**Return value**

| Type                            | Description                  |
| -------------------------------- | ---------------------- |
| [ImageInfo](arkts-apis-image-i.md#imageinfo) | Image information.|

**Example**

```ts
function GetImageInfoSync(context : Context) {
  // "test.jpg" is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
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
}
```

## getImageProperty<sup>11+</sup>

getImageProperty(key:PropertyKey, options?: ImagePropertyOptions): Promise\<string>

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF<sup>12+</sup>, WEBP<sup>23+</sup>, or DNG<sup>23+</sup> format and contain Exif information. (The supported formats may vary depending on the hardware.)

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | [PropertyKey](arkts-apis-image-e.md#propertykey7)                                               | Yes  | Name of the property.                        |
| options | [ImagePropertyOptions](arkts-apis-image-i.md#imagepropertyoptions11) | No  | Image properties, including the image index and default property value.|

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise used to return the property value. If the operation fails, the default value is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;              |
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980103 | The image data is not supported.         |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.       |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be corrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.   |
| 62980123| The image does not support EXIF decoding. |
| 62980135| The EXIF value is invalid.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageProperty(imageSourceObj : image.ImageSource) {
  let options: image.ImagePropertyOptions = { index: 0, defaultValue: '9999' }
  imageSourceObj.getImageProperty(image.PropertyKey.BITS_PER_SAMPLE, options)
    .then((data: string) => {
      console.info('Succeeded in getting the value of the specified attribute key of the image.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to get the value of the specified attribute key of the image, error.code ${error.code}, error.message ${error.message}`);
  })
}
```

## getImageProperties<sup>12+</sup>

getImageProperties(key: Array&#60;PropertyKey&#62;): Promise<Record<PropertyKey, string|null>>

Obtains the values of properties with the given names in this image. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF, WEBP<sup>23+</sup>, or DNG<sup>23+</sup>format and contain the Exif information. (The supported formats may vary depending on the hardware.)

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | Array\<[PropertyKey](arkts-apis-image-e.md#propertykey7)>                                 | Yes  | Array of properties names.                        |

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<Record<[PropertyKey](arkts-apis-image-e.md#propertykey7), string \| null>> | Promise used to return the property values. If the operation fails, **null** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;     |
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110| The image source data is incorrect.            |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be corrupted.            |
| 62980116| Failed to decode the image.            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageProperties(imageSourceObj : image.ImageSource) {
  let key = [image.PropertyKey.IMAGE_WIDTH, image.PropertyKey.IMAGE_LENGTH];
  imageSourceObj.getImageProperties(key).then((data) => {
    console.info(JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get the properties, error.code ${err.code}, error.message ${err.message}`);
  });
}
```

## getImagePropertySync<sup>20+</sup>

getImagePropertySync(key:PropertyKey): string

Obtains the value of a specified Exif property. This API returns the result synchronously.

>**NOTE**
>
> - This API applies only to images that are in JPEG, PNG, HEIF, WEBP<sup>23+</sup>, or DNG<sup>23+</sup>format and contain the Exif information. (The supported formats may vary depending on the hardware.)
>
> - Exif information is metadata of the image, including shooting time, camera model, aperture, focal length, and ISO.
>
>- This API operates synchronously and will block the current thread during execution. It should not be invoked from the main thread, as doing so can lead to application lag, frame drops, or delayed responsiveness. For details, see [Overview of Concurrency in Time-Consuming Tasks](../../arkts-utils/time-consuming-task-overview.md).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | [PropertyKey](arkts-apis-image-e.md#propertykey7)                                               | Yes  | Name of the property.                        |

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| string | Value of the specified Exif property. If retrieval fails, the default value of the property is returned. For details about the meaning of each data value, see [PropertyKey](arkts-apis-image-e.md#propertykey7).|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed.|
| 7700102 | Unsupported MIME type.|
| 7700202 | Unsupported metadata. For example, key is not supported.|

**Example**

```ts
function GetImagePropertySync(context : Context) {
  let resourceMgr = context.resourceManager;
  if (resourceMgr == null) {
    return;
  }
  let fd = resourceMgr.getRawFdSync("example.jpg");

  const imageSourceObj = image.createImageSource(fd);
  console.info("getImagePropertySync");
  let bits_per_sample = imageSourceObj.getImagePropertySync(image.PropertyKey.BITS_PER_SAMPLE);
  console.info("bits_per_sample : " + bits_per_sample);
}
```

## modifyImageProperty<sup>11+</sup>

modifyImageProperty(key: PropertyKey, value: string): Promise\<void>

Modifies the value of a property in this image. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF<sup>12+</sup>, or WEBP<sup>23+</sup> format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> - The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.
> 
> - When calling the **modifyImageProperty** API to modify the **Exif** field, ensure that the corresponding image file has write permission. Otherwise, the field modification will fail.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| key     | [PropertyKey](arkts-apis-image-e.md#propertykey7)   | Yes  | Name of the property.|
| value   | string | Yes  | New value of the property.    |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;    |
| 62980123| The image does not support EXIF decoding.             |
| 62980133| The EXIF data is out of range.             |
| 62980135| The EXIF value is invalid.             |
| 62980146| The EXIF data failed to be written to the file.        |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ModifyImageProperty(imageSourceObj : image.ImageSource) {
  imageSourceObj.modifyImageProperty(image.PropertyKey.IMAGE_WIDTH, "120").then(() => {
    imageSourceObj.getImageProperty(image.PropertyKey.IMAGE_WIDTH).then((width: string) => {
      console.info(`ImageWidth is :${width}`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to get the Image Width, error.code ${error.code}, error.message ${error.message}`);
    })
  }).catch((error: BusinessError) => {
    console.error(`Failed to modify the Image Width, error.code ${error.code}, error.message ${error.message}`);
  })
}
```

## modifyImageProperties<sup>12+</sup>

modifyImageProperties(records: Record<PropertyKey, string|null>): Promise\<void>

Modifies the values of properties in this image. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF, or WEBP<sup>23+</sup> format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> - The property byte length is changed when the **modifyImageProperties** API is called to modify the values of properties. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.
> - When calling the **modifyImageProperties** API to modify the **Exif** field, ensure that the corresponding image file has write permission. Otherwise, the field modification will fail.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| records     | Record<[PropertyKey](arkts-apis-image-e.md#propertykey7), string \| null>   | Yes  | Array of property names and property values.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401  | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed;      |
| 62980123| The image does not support EXIF decoding.             |
| 62980135| The EXIF value is invalid.             |
| 62980146| The EXIF data failed to be written to the file.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ModifyImageProperties(imageSourceObj : image.ImageSource) {
  let keyValues: Record<PropertyKey, string|null> = {
    [image.PropertyKey.IMAGE_WIDTH] : "1024",
    [image.PropertyKey.IMAGE_LENGTH] : "1024"
  };
  let checkKey = [image.PropertyKey.IMAGE_WIDTH, image.PropertyKey.IMAGE_LENGTH];
  imageSourceObj.modifyImageProperties(keyValues).then(() => {
    imageSourceObj.getImageProperties(checkKey).then((data) => {
      console.info(`Image Width and Image Height:${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to modify the Image Width and Image Height, error.code ${err.code}, error.message ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to modify the Image Width and Image Height, error.code ${err.code}, error.message ${err.message}`);
  });
}
```

## modifyImagePropertiesEnhanced<sup>22+</sup>

modifyImagePropertiesEnhanced(records: Record\<string, string | null\>): Promise\<void\>

Modifies image properties in batches. This API uses a promise to return the result.

> **NOTE**
>
> - Calling this API to modify properties alters the property byte length. You are advised to create an [image.createImageSource](arkts-apis-image-f.md#imagecreateimagesource7) instance by passing a file descriptor or an [image.createImageSource](arkts-apis-image-f.md#imagecreateimagesource) instance by passing a URI.
> - This API modifies batch data in memory and writes the data to the file in a single operation. It is more efficient than [modifyImageProperties](#modifyimageproperties12).
> - This API applies only to images that are in JPEG, PNG, HEIF, or WEBP format and contain the Exif information.
> - When calling the **modifyImagePropertiesEnhanced** API to modify the **Exif** field, ensure that the corresponding image file has write permission. Otherwise, the field modification will fail.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| records | Record\<string, string \| null>|Yes| Key-value pairs of image property names and property values.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 7700102 | Unsupported MIME type.             |
| 7700202 | Unsupported metadata. For example, the property key is not supported, or the property value is invalid.             |
| 7700304 | Failed to write image properties to the file.             |

**Example**
```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ModifyImagePropertiesEnhanced(imageSourceObj : image.ImageSource) {
  let keyValues: Record<string, string|null> = {
    "ImageWidth" : "1024",
    "ImageLength" : "1024"
  };
  let checkKey = [image.PropertyKey.IMAGE_WIDTH, image.PropertyKey.IMAGE_LENGTH];
  imageSourceObj.modifyImagePropertiesEnhanced(keyValues).then(() => {
    imageSourceObj.getImageProperties(checkKey).then((data) => {
      console.info(`Image Width and Image Height:${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to modify the Image Width and Image Height, error.code ${err.code}, error.message ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to modify the Image Width and Image Height, error.code ${err.code}, error.message ${err.message}`);
  });
}
```

## readImageMetadata<sup>23+</sup>

readImageMetadata(propertyKeys?: string[], index?: number): Promise\<ImageMetadata>

Reads image metadata. You can use **propertyKeys** to specify the keys of metadata. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF, WebP, DNG, GIF, TIFF, HEIFS, JFIF, or AVIS format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> When reading a DNG image, this API applies special handling to some **propertyKeys**. For details about the values of the following properties, see [PropertyKey](arkts-apis-image-e.md#propertykey7):
> - **NewSubfileType**, **ImageWidth**, **ImageLength**, **DefaultCropSize**, **Orientation**, **Compression**, **PhotometricInterpretation**, **PlanarConfiguration**, **RowsPerStrip**, **StripOffsets**, **StripByteCounts**, **SamplesPerPixel**, **BitsPerSample**, **YCbCrCoefficients**, **YCbCrSubSampling**, **YCbCrPositioning**, **ReferenceBlackWhite**, **XResolution**, **YResolution**, and **ResolutionUnit**: For these properties, values related to the main image are returned.
> - **ImageUniqueID**: The value is verified based on the specifications. If the value fails to comply with the specifications, an empty string is returned.
> - **ExifVersion**, **FlashpixVersion**, and **ColorSpace**: If the image does not contain these properties, an error code is returned.
> - **DNGVersion**: If the value is earlier than **1.0.0.0**, **1.0.0.0** is returned.
> - **GPSVersionID**: If there is no valid GPS data, the GPS version number is cleared and **0** is returned.
> - **GPSAltitudeRef**: If **GPSAltitude** is not set, this property is set to **0xFFFFFFFF**.
> - **ISOSpeedRatings**: If its value is **0** or **65535**, the recommended exposure index is used first. If the recommended exposure index does not exist, the standard output sensitivity, ISO speed, and exposure index are used in sequence.
> - Since API version 24, DNG metadata can be read. For details about the properties, see [DngPropertyKey](arkts-apis-image-e.md#dngpropertykey24).
> - Since API version 24, HEIFS metadata can be read. For details about the properties, see [HeifsPropertyKey](arkts-apis-image-e.md#heifspropertykey23).
> - Since API version 26.0.0, PNG metadata can be read. For details about the properties, see [PngPropertyKey](arkts-apis-image-e.md#pngpropertykey).
> - Since API version 26.0.0, JFIF metadata can be read. For details about the properties, see [JfifPropertyKey](arkts-apis-image-e.md#jfifpropertykey).
> - Since API version 26.0.0, TIFF metadata can be read. For details about the properties, see [TiffPropertyKey](arkts-apis-image-e.md#tiffpropertykey).
> - Since API version 26.0.0, GIF metadata can be read. For details about the properties, see [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20).
> - Since API version 26.0.0, XMP metadata of JPEG, PNG, GIF, DNG, and TIFF images can be read. For details about how to operate XMP metadata, see [XMPMetadata](arkts-apis-image-XMPMetadata.md).
> - Since API version 26.0.0, AVIS metadata can be read. For details about the properties, see [AvisPropertyKey](arkts-apis-image-e.md#avispropertykey).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name      | Type    | Mandatory| Description                     |
| ------------ | -------- | ---- | ------------------------- |
| propertyKeys | string[] | No  | Array of properties names. If **propertyKeys** is not specified, all supported metadata is returned.       |
| index        | number   | No  | Index of the property to be obtained. The default value is **0**.|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[ImageMetadata](arkts-apis-image-i.md#imagemetadata23)> | Promise used to return the **ImageMetadata** object, which contains the metadata object corresponding to the image property name. You can obtain the image property values through this metadata object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 7700102  | Unsupported MIME type. |
| 7700202  | Unsupported metadata.  |
| 7700204  | Invalid parameter. Possible causes: 1. The index is negative. 2. The index is greater than or equal to the number of frames in the image.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ReadImageMetadata(imageSourceObj : image.ImageSource) {
  let propertyKeys = ["ImageWidth", "HwMnoteIsXmageSupported"];
  await imageSourceObj.readImageMetadata(propertyKeys).then((metaData: image.ImageMetadata) => {
    if (metaData != undefined && metaData.exifMetadata != undefined &&
      metaData.makerNoteHuaweiMetadata != undefined) {
      console.info("ImageWidth: " + metaData.exifMetadata.imageWidth +
        " HwMnoteIsXmageSupported: " + metaData.makerNoteHuaweiMetadata.isXmageSupported);
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to read image metadata. error.code is ${error.code}, error.message is ${error.message}`);
  })
}
```

## writeImageMetadata<sup>23+</sup>

writeImageMetadata(imageMetadata: ImageMetadata): Promise\<void>

Modifies image properties in batches. This API uses a promise to return the result.

> **NOTE**
>
> - Calling this API to modify properties alters the property byte length. You are advised to create an [image.createImageSource](arkts-apis-image-f.md#imagecreateimagesource7) instance by passing a file descriptor or an [image.createImageSource](arkts-apis-image-f.md#imagecreateimagesource) instance by passing a URI.
> - This API modifies batch data in memory and writes the data to the file in a single operation. It is more efficient than [modifyImageProperties](#modifyimageproperties12).
> - This API applies only to images that are in JPEG, PNG, or HEIF format and contain the Exif information. Before modifying properties, use the **supportedFormats** property to check whether the device supports Exif information read/write in HEIF format.
> - Since API version 26.0.0, XMP metadata of JPEG, PNG, and GIF images can be read. For details about how to operate XMP metadata, see [XMPMetadata](arkts-apis-image-XMPMetadata.md).
> - When calling the **writeImageMetadata** API to modify the **Exif** field, ensure that the corresponding image file has write permission. Otherwise, the field modification will fail.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name       | Type                                                  | Mandatory| Description            |
| ------------- | ------------------------------------------------------ | ---- | ---------------- |
| imageMetadata | [ImageMetadata](arkts-apis-image-i.md#imagemetadata23) | Yes  | Image metadata set. If all property values in **imageMetadata** are empty, all Exif metadata is cleared.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 7700102  | Unsupported MIME type. |
| 7700202  | Unsupported metadata.  |
| 7700204  | Invalid parameter. Possible causes: The imageSource object is released.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function WriteImageMetadata(imageSourceObj : image.ImageSource) {
  let propertyKeys = ["ImageWidth", "HwMnoteIsXmageSupported"];
  let metaData = await imageSourceObj.readImageMetadata(propertyKeys);
  if (metaData != undefined && metaData.exifMetadata != undefined) {
    metaData.exifMetadata.imageLength = 3072;
  }
  await imageSourceObj.writeImageMetadata(metaData).then(() => {
    console.info(`Succeeded in writing image metadata.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to write image metadata. error.code is ${error.code}, error.message is ${error.message}`);
  });
}
```

## readImageMetadataByType<sup>24+</sup>

readImageMetadataByType(metadataTypes?: MetadataType[], index?: number): Promise\<ImageMetadata>

Reads the metadata of an image source. You can use **metadataTypes** to specify the metadata types. If **metadataTypes** is not specified, all supported metadata is returned. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF, WebP, DNG, GIF, TIFF, HEIFS, JFIF, or AVIS format. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> - **EXIF_METADATA** applies to JPEG, PNG, HEIF, WEBP, and DNG images.
> - **HEIFS_METADATA** applies to HEIFS images.
> - If the input **MetadataType** does not match the image format, error code **7700102** will be returned.
> - Since API version 24, DNG metadata can be read. For details about the properties, see [DngPropertyKey](arkts-apis-image-e.md#dngpropertykey24).
> - Since API version 24, HEIFS metadata can be read. For details about the properties, see [HeifsPropertyKey](arkts-apis-image-e.md#heifspropertykey23).
> - Since API version 26.0.0, PNG metadata can be read. For details about the properties, see [PngPropertyKey](arkts-apis-image-e.md#pngpropertykey).
> - Since API version 26.0.0, JFIF metadata can be read. For details about the properties, see [JfifPropertyKey](arkts-apis-image-e.md#jfifpropertykey).
> - Since API version 26.0.0, TIFF metadata can be read. For details about the properties, see [TiffPropertyKey](arkts-apis-image-e.md#tiffpropertykey).
> - Since API version 26.0.0, GIF metadata can be read. For details about the properties, see [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20).
> - Since API version 26.0.0, XMP metadata of JPEG, PNG, GIF, DNG, and TIFF images can be read. For details about how to operate XMP metadata, see [XMPMetadata](arkts-apis-image-XMPMetadata.md).
> - Since API version 26.0.0, AVIS metadata can be read. For details about the properties, see [AvisPropertyKey](arkts-apis-image-e.md#avispropertykey).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name       | Type           | Mandatory| Description                     |
| ------------- | -------------- | ---- | ------------------------- |
| metadataTypes | [MetadataType](arkts-apis-image-e.md#metadatatype13)[] | No  | Metadata type array. If this parameter is left empty, all supported metadata is obtained.|
| index         | number         | No  | Image frame number for metadata retrieval. The default value is **0**.<br>- For single-frame images, the value can only be 0.<br>- For multi-frame images such as animations, the value ranges from 0 to (Number of frames – 1).|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[ImageMetadata](arkts-apis-image-i.md#imagemetadata23)> | Promise used to return the **ImageMetadata** object, which contains the corresponding metadata object. You can obtain the image property values through this metadata object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 7700102  | Unsupported MIME type. |
| 7700202  | Unsupported metadata.  |
| 7700204  | Invalid parameter. Possible causes: 1.The index is negative.2. The index is greater than or equal to the number of frames in the image. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

async function ReadImageMetadataByType(imageSource : image.ImageSource, type: image.MetadataType) {
  let types: image.MetadataType[] = [type];
  await imageSource.readImageMetadataByType(types, 0).then((metaData: image.ImageMetadata) => {
    if (metaData != undefined && metaData.exifMetadata != undefined) {
      console.info("ImageWidth: " + metaData.exifMetadata.imageWidth);
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to read image metadata by type. error.code is ${error.code}, error.message is ${error.message}`);
  })
}
```

## createImageRawData<sup>24+</sup>

createImageRawData(): Promise\<ImageRawData>

Obtains image raw data. This API uses a promise to return the result. Currently, only the raw data of DNG images can be obtained.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<[ImageRawData](arkts-apis-image-i.md#imagerawdata24)> | Promise used to return the ImageRawData object, which contains the data buffer and pixel bits.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 7700101  | Bad source.  |
| 7700102  | Unsupported MIME type. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function createImageRawData(imageSourceObj: image.ImageSource) {
  await imageSourceObj.createImageRawData().then((data: image.ImageRawData) => {
    console.info(`createImageRawData successfully. length: ${data.buffer.byteLength}, bitPerPixel:${data.bitsPerPixel}`);
    if (data.bitsPerPixel == 16) {
      let array: Uint16Array = new Uint16Array();
      let value: string = "";
      array = new Uint16Array(data.buffer);
      for (let i = 0; i < array.length && i < 10; i++) {
        value += array[i] + ', ';
      }
      console.info(`get dng rawdata is:${value}.`);
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to create image rawData. error.code is ${error.code}, error.message is ${error.message}`);
  });
}
```

## updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number): Promise\<void>

Updates incremental data. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type       | Mandatory| Description        |
| ---------- | ----------- | ---- | ------------ |
| buf        | ArrayBuffer         | Yes  | Buffer for storing the incremental data.          |
| isFinished | boolean             | Yes  | Whether data update is complete. The value **true** means that the data update is complete and the last segment of data is stored in the buffer. The value **false** means that the data update is still in progress.|
| offset      | number              | Yes  | Offset of the data in the buffer, measured from the start of the entire image file, in bytes.            |
| length     | number              | Yes  | Length of the buffer, in bytes.           |

**Return value**

| Type          | Description                      |
| -------------- | -------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function UpdateDatay(imageSourceObj : image.ImageSource) {
  const array: ArrayBuffer = new ArrayBuffer(100);
  imageSourceObj.updateData(array, false, 0, 10).then(() => {
    console.info('Succeeded in updating data.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
  })
}
```


## updateData<sup>9+</sup>

updateData(buf: ArrayBuffer, isFinished: boolean, offset: number, length: number, callback: AsyncCallback\<void>): void

Updates incremental data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type               | Mandatory| Description                |
| ---------- | ------------------- | ---- | -------------------- |
| buf        | ArrayBuffer         | Yes  | Buffer for storing the incremental data.          |
| isFinished | boolean             | Yes  | Whether data update is complete. The value **true** means that the data update is complete and the last segment of data is stored in the buffer. The value **false** means that the data update is still in progress.|
| offset      | number              | Yes  | Offset of the data in the buffer, measured from the start of the entire image file, in bytes.            |
| length     | number              | Yes  | Length of the buffer, in bytes.           |
| callback   | AsyncCallback\<void> | Yes  |  Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function UpdateDatay(imageSourceObj : image.ImageSource) {
  const array: ArrayBuffer = new ArrayBuffer(100);
  imageSourceObj.updateData(array, false, 0, 10, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to update data.code is ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in updating data.');
    }
  })
}
```

## createPicture<sup>13+</sup>

createPicture(options?: DecodingOptionsForPicture): Promise\<Picture>

Creates a Picture object based on decoding options. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using a Picture instance, call [release](./arkts-apis-image-Picture.md#release13) to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                  | Mandatory| Description      |
| ------- | ------------------------------------------------------ | ---- | ---------- |
| options | [DecodingOptionsForPicture](arkts-apis-image-i.md#decodingoptionsforpicture13) | No  | Decoding options.|

**Return value**

| Type                        | Description                      |
| ---------------------------- | -------------------------- |
| Promise\<[Picture](arkts-apis-image-Picture.md)> | Promise used to return the Picture object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified.2.Incorrect parameter types; 3.Parameter verification failed. |
| 7700203  | Unsupported options. For example, unsupported desiredPixelFormat causes a failure in converting an image into the desired pixel format. <br>Applicable versions: 24+|
| 7700301  | Decode failed.                                               |

**Example**

```ts
async function CreatePicture(imageSourceObj : image.ImageSource) {
  let options: image.DecodingOptionsForPicture = {
    desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP indicates the type of the auxiliary picture to be decoded.
  };
  let pictureObj: image.Picture = await imageSourceObj.createPicture(options);
  if (pictureObj != null) {
    console.info('Succeeded in creating picture.');
  } else {
    console.error('Failed to create picture.');
  }
}
```

## createPictureAtIndex<sup>20+</sup>

createPictureAtIndex(index: number): Promise\<Picture>

Creates a Picture object from the image with the specified index. This API uses a promise to return the result.

> **NOTE**
>
> - The GIF and HEIF<sup>23+</sup> image sequence formats are supported. Since API version 26.0.0, the AVIS format is supported.
> - Images occupy a large amount of memory. When you finish using a Picture instance, call [release](./arkts-apis-image-Picture.md#release13) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name| Type   | Mandatory| Description                                             |
| ------ | ------ | ---- | ------------------------------------------------ |
| index  | number | Yes  | Index of the image. The value range is [0, Number of frames – 1].|

**Return value**

| Type                        | Description                        |
| ---------------------------- | ---------------------------- |
| Promise\<[Picture](arkts-apis-image-Picture.md)> | Promise used to return the Picture object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 7700101  | Bad source. |
| 7700102  | Unsupported MIME type. |
| 7700103  | Image too large. |
| 7700203  | Unsupported options. For example, index is invalid. |
| 7700301  | Decoding failed. |

**Example**

```ts
async function CreatePictures(imageSourceObj : image.ImageSource) {
  let frameCount: number = await imageSourceObj.getFrameCount();
  for (let index = 0; index < frameCount; index++) {
    try {
      let pictureObj: image.Picture = await imageSourceObj.createPictureAtIndex(index);
      console.info('Succeeded in creating picture for frame: ' + index);
    } catch (e) {
      console.error('Failed to create picture for frame: ' + index);
    }
  }
}
```

## createPixelMap<sup>7+</sup>

createPixelMap(options?: DecodingOptions): Promise\<PixelMap>

Creates a PixelMap object based on decoding options. This API uses a promise to return the result. This API uses a promise to return the result.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocator](#createpixelmapusingallocator15). This API can be used to specify the memory type [AllocatorType](arkts-apis-image-e.md#allocatortype15) of the output PixelMap. For details, see [Optimizing Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

> **NOTE**
>
> - This method is not thread-safe and does not support concurrent calls on the same ImageSource instance.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                | Mandatory| Description      |
| ------- | ------------------------------------ | ---- | ---------- |
| options | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | No  | Decoding options.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMap(imageSourceObj : image.ImageSource) {
  imageSourceObj.createPixelMap().then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating pixelMap object through image decoding parameters.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create pixelMap object through image decoding parameters, error.code ${error.code}, error.message ${error.message}`);
  })
}
```

## createPixelMap<sup>7+</sup>

createPixelMap(callback: AsyncCallback\<PixelMap>): void

Creates a PixelMap object based on the default parameters. This API uses an asynchronous callback to return the result.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocator](#createpixelmapusingallocator15). This API can be used to specify the memory type [AllocatorType](arkts-apis-image-e.md#allocatortype15) of the output PixelMap. For details, see [Optimizing Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

> **NOTE**
>
> - This method is not thread-safe and does not support concurrent calls on the same ImageSource instance.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[PixelMap](arkts-apis-image-PixelMap.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMap(imageSourceObj : image.ImageSource) {
  imageSourceObj.createPixelMap((err: BusinessError, pixelMap: image.PixelMap) => {
    if (err) {
      console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in creating pixelMap object.');
    }
  })
}
```

## createPixelMap<sup>7+</sup>

createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void

Creates a PixelMap object based on decoding options. This API uses a promise to return the result. This API uses an asynchronous callback to return the result.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocator](#createpixelmapusingallocator15). This API can be used to specify the memory type [AllocatorType](arkts-apis-image-e.md#allocatortype15) of the output PixelMap. For details, see [Optimizing Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

> **NOTE**
>
> - This method is not thread-safe and does not support concurrent calls on the same ImageSource instance.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7)  | Yes  | Decoding options.                |
| callback | AsyncCallback<[PixelMap](arkts-apis-image-PixelMap.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMap(imageSourceObj : image.ImageSource) {
  let decodingOptions: image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 1, height: 2 },
    rotate: 10,
    desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
    desiredRegion: { size: { width: 1, height: 2 }, x: 0, y: 0 },
    // If both desiredSize and desiredRegion are passed to the decoding API, you must also include cropAndScaleStrategy to determine whether to crop or scale first. CROP_FIRST is recommended.
    cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
    index: 0
  };
  imageSourceObj.createPixelMap(decodingOptions, (err: BusinessError, pixelMap: image.PixelMap) => {
    if (err) {
      console.error(`Failed to create pixelMap.code is ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in creating pixelMap object.');
    }
  })
}
```

## createPixelMapSync<sup>12+</sup>

createPixelMapSync(options?: DecodingOptions): PixelMap

Creates a PixelMap object based on decoding options. This API returns the result synchronously.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

Starting from API version 15, you are advised to use [createPixelMapUsingAllocatorSync](#createpixelmapusingallocatorsync15). This API can be used to specify the memory type [AllocatorType](arkts-apis-image-e.md#allocatortype15) of the output PixelMap. For details, see [Optimizing Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

> **NOTE**
>
> This API operates synchronously and will block the current thread during execution. It should not be invoked from the main thread, as doing so can lead to application lag, frame drops, or delayed responsiveness. For details, see [Overview of Concurrency in Time-Consuming Tasks](../../arkts-utils/time-consuming-task-overview.md).

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7)  | No  | Decoding options.                |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object.|

**Example**

```ts
function CreatePixelMapSync(context : Context) {
  // "test.jpg" is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
  let filePath: string = context.filesDir + "/test.jpg";
  let imageSource = image.createImageSource(filePath);
  let decodingOptions: image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 1, height: 2 },
    rotate: 10,
    desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
    desiredRegion: { size: { width: 1, height: 2 }, x: 0, y: 0 },
    // If both desiredSize and desiredRegion are passed to the decoding API, you must also include cropAndScaleStrategy to determine whether to crop or scale first. CROP_FIRST is recommended.
    cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
    index: 0
  };
  let pixelmap = imageSource.createPixelMapSync(decodingOptions);
  if (pixelmap != undefined) {
    console.info('Succeeded in creating pixelMap object.');
  } else {
    console.error('Failed to create pixelMap.');
  }
}
```

## createPixelMapList<sup>10+</sup>

createPixelMapList(options?: DecodingOptions): Promise<Array\<PixelMap>>

Creates an array of PixelMap objects based on decoding options. This API uses a promise to return the result.

For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

> **NOTE**
>
> - This method is not thread-safe and does not support concurrent calls on the same ImageSource instance.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.
> - This API decodes all frames at once. When there are too many frames or a single frame is too large (for example, a 100-frame GIF image with 2000 × 3000 pixels per frame), this API may consume a significant amount of memory, causing system memory pressure. In such cases, you are advised to use the **Image** component to display animated images, as the **Image** component decodes frames one by one and uses less memory than this API.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| options  | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7)  | No  | Decoding options.                |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise<Array<[PixelMap](arkts-apis-image-PixelMap.md)>> | Promise used to return an array of PixelMap objects.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
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

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapList(imageSourceObj : image.ImageSource) {
  let decodeOpts: image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 198, height: 202 },
    rotate: 0,
    desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
    index: 0,
  };
  imageSourceObj.createPixelMapList(decodeOpts).then((pixelMapList: Array<image.PixelMap>) => {
    console.info('Succeeded in creating pixelMapList object.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create pixelMapList object, error code is ${err}`);
  })
}
```

## createPixelMapList<sup>10+</sup>

createPixelMapList(callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of PixelMap objects based on the default parameters. This API uses an asynchronous callback to return the result.

For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

> **NOTE**
>
> - This method is not thread-safe and does not support concurrent calls on the same ImageSource instance.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.
> - This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name    | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<Array<[PixelMap](arkts-apis-image-PixelMap.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the array of PixelMap objects obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
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

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapList(imageSourceObj : image.ImageSource) {
  imageSourceObj.createPixelMapList((err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
    if (err) {
      console.error(`Failed to create pixelMapList object, error code is ${err}`);
    } else {
      console.info('Succeeded in creating pixelMapList object.');
    }
  })
}
```

## createPixelMapList<sup>10+</sup>

createPixelMapList(options: DecodingOptions, callback: AsyncCallback<Array\<PixelMap>>): void

Creates an array of PixelMap objects based on decoding options. This API uses an asynchronous callback to return the result.

For dynamic images such as GIF and WebP images, this API returns the data of each frame of the image. For static images, this API returns the data of the unique frame of the image.

> **NOTE**
>
> - This method is not thread-safe and does not support concurrent calls on the same ImageSource instance.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.
> - This function decodes all frames at once. If the number of frames is high or the size of individual frames is large, it can lead to significant memory usage. In these cases, you are advised to use the **Image** component for displaying animations. The **Image** component decodes frames one by one, which uses less memory than this function.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| options | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | Yes| Decoding options.|
| callback | AsyncCallback<Array<[PixelMap](arkts-apis-image-PixelMap.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the array of PixelMap objects obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
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

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreatePixelMapList(imageSourceObj : image.ImageSource) {
  let decodeOpts: image.DecodingOptions = {
    sampleSize: 1,
    editable: true,
    desiredSize: { width: 198, height: 202 },
    rotate: 0,
    desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
    index: 0,
  };
  imageSourceObj.createPixelMapList(decodeOpts, (err: BusinessError, pixelMapList: Array<image.PixelMap>) => {
    if (err) {
      console.error(`Failed to create pixelMapList object, error code is ${err}`);
    } else {
      console.info('Succeeded in creating pixelMapList object.');
    }
  })
}
```

## createPixelMapUsingAllocator<sup>15+</sup>

createPixelMapUsingAllocator(options?: DecodingOptions, allocatorType?: AllocatorType): Promise\<PixelMap>

Creates a PixelMap object based on decoding options and memory type. This API uses a promise to return the result. For details, see [Optimizing Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

> **NOTE**
>
> - This method is not thread-safe and does not support concurrent calls on the same ImageSource instance.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.
> - When the calling process has sandbox isolation enabled and **AllocatorType.DMA** is specified, or when DMA memory is selected by **AllocatorType.AUTO**, the SELinux permissions for accessing DMA memory‑related resources must be configured for the sandbox process. Otherwise, the API call may be blocked or fail due to SELinux policy restrictions.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name       | Type                                | Mandatory| Description                    |
| ------------- | ------------------------------------ | ---- | ------------------------ |
| options        | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | No  | Decoding options.              |
| allocatorType | [AllocatorType](arkts-apis-image-e.md#allocatortype15)   | No  | Type of the memory. The default value is **AllocatorType.AUTO**.|

**Return value**

| Type                            | Description                       |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types;3.Parameter verification failed. |
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed. |
| 7700102  | Unsupported mimetype.                                        |
| 7700103  | Image too large.  This status code is thrown when an error occurs during the process of checking size. |
| 7700201  | Unsupported allocator type, e.g., use share memory to decode a HDR image as only DMA supported hdr metadata. |
| 7700203  | Unsupported options, e.g., cannot convert image into desired pixel format. |
| 7700301  | Failed to decode image.                                      |
| 7700302  | Failed to allocate memory.                                   |

**Example**

```ts
async function CreatePixelMapUsingAllocator(context : Context) {
  // "test.jpg" is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
  let filePath: string = context.filesDir + "/test.jpg";
  let imageSource = image.createImageSource(filePath);
  let decodingOptions: image.DecodingOptions = {
    editable: true,
    desiredSize: { width: 3072, height: 4096 },
    rotate: 10,
    desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
    desiredRegion: { size: { width: 3072, height: 4096 }, x: 0, y: 0 },
    // If both desiredSize and desiredRegion are passed to the decoding API, you must also include cropAndScaleStrategy to determine whether to crop or scale first. CROP_FIRST is recommended.
    cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
    index: 0
  };
  let pixelmap = imageSource.createPixelMapUsingAllocator(decodingOptions, image.AllocatorType.AUTO);
  if (pixelmap != undefined) {
    console.info('Succeeded in creating pixelMap object.');
  } else {
    console.error('Failed to create pixelMap.');
  }
}
```

## createPixelMapUsingAllocatorSync<sup>15+</sup>

createPixelMapUsingAllocatorSync(options?: DecodingOptions, allocatorType?: AllocatorType): PixelMap

Creates a PixelMap object based on decoding options and memory type. This API returns the result synchronously. For details, see [Optimizing Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> - This API operates synchronously and will block the current thread during execution. It should not be invoked from the main thread, as doing so can lead to application lag, frame drops, or delayed responsiveness. For details, see [Overview of Concurrency in Time-Consuming Tasks](../../arkts-utils/time-consuming-task-overview.md).
> - When the calling process has sandbox isolation enabled and **AllocatorType.DMA** is specified, or when DMA memory is selected by **AllocatorType.AUTO**, the SELinux permissions for accessing DMA memory‑related resources must be configured for the sandbox process. Otherwise, the API call may be blocked or fail due to SELinux policy restrictions.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name       | Type                                | Mandatory| Description                    |
| ------------- | ------------------------------------ | ---- | ------------------------ |
| options        | [DecodingOptions](arkts-apis-image-i.md#decodingoptions7) | No  | Decoding options.              |
| allocatorType | [AllocatorType](arkts-apis-image-e.md#allocatortype15)   | No  | Type of the memory. The default value is **AllocatorType.AUTO**.|

**Return value**

| Type                  | Description                  |
| ---------------------- | ---------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | PixelMap object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types;3.Parameter verification failed. |
| 7700101  | Bad source. e.g.,1. Image has invalid width or height. 2. Image source incomplete. 3. Read image data failed. 4. Codec create failed. |
| 7700102  | Unsupported mimetype.                                        |
| 7700103  | Image too large.  This status code is thrown when an error occurs during the process of checking size. |
| 7700201  | Unsupported allocator type, e.g., use share memory to decode a HDR image as only DMA supported hdr metadata. |
| 7700203  | Unsupported options, e.g., cannot convert image into desired pixel format. |
| 7700301  | Failed to decode image.                                      |
| 7700302  | Failed to allocate memory.                                   |

**Example**

```ts
async function CreatePixelMapUsingAllocator(context : Context) {
  // "test.jpg" is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
  let filePath: string = context.filesDir + "/test.jpg";
  let imageSource = image.createImageSource(filePath);
  let decodingOptions: image.DecodingOptions = {
    editable: true,
    desiredSize: { width: 3072, height: 4096 },
    rotate: 10,
    desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
    desiredRegion: { size: { width: 3072, height: 4096 }, x: 0, y: 0 },
    // If both desiredSize and desiredRegion are passed to the decoding API, you must also include cropAndScaleStrategy to determine whether to crop or scale first. CROP_FIRST is recommended.
    cropAndScaleStrategy: image.CropAndScaleStrategy.CROP_FIRST,
    index: 0
  };
  let pixelmap = imageSource.createPixelMapUsingAllocatorSync(decodingOptions, image.AllocatorType.AUTO);
  if (pixelmap != undefined) {
    console.info('Succeeded in creating pixelMap object.');
  } else {
    console.error('Failed to create pixelMap.');
  }
}
```

## createThumbnail

createThumbnail(options?: DecodingOptionsForThumbnail): Promise\<PixelMap \| undefined>

Creates a thumbnail PixelMap object based on image decoding options. This API uses a promise to return the result.

Currently, thumbnail PixelMap objects can be created for JPEG and HEIF images.

Thumbnails contained in image files are decoded preferentially. If an image file does not contain a thumbnail, the original image is decoded.

> **NOTE**
>
> - Concurrent calls to this API on the same ImageSource instance are not supported.
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                        | Mandatory| Description      |
| ------- | ------------------------------------------------------------ | ---- | ---------- |
| options | [DecodingOptionsForThumbnail](arkts-apis-image-i.md#decodingoptionsforthumbnail) | No  | Decoding options, which control whether to generate a thumbnail and the target dimensions of the thumbnail.<br>Default behavior:<br>- If the image has a thumbnail, the original thumbnail is decoded, and the width and height of the returned PixelMap object are the same as those of the original thumbnail.<br>- If the original image does not have a thumbnail, the image is decoded and a thumbnail is generated through downsampling based on the decoding options. The width and height of the generated thumbnail PixelMap object are limited to 512 pixels.|

**Return value**

| Type                                                        | Description                       |
| ------------------------------------------------------------ | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md) \| undefined> | Promise used to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 7700102  | Unsupported mimetype.                          |
| 7700103  | Image too large.                               |
| 7700204  | Invalid parameter, e.g, invalid generate size. |
| 7700301  | Decode failed.                                 |
| 7700303  | Image does not carry thumbnail data.           |
| 7700305  | Thumbnail generation failed.                   |

**Example**

```ts
async function CreateThumbnail(imageSource: image.ImageSource): Promise<image.PixelMap | undefined> {
  try {
    if (!imageSource) {
      console.error('CreateThumbnail: imageSource is null or undefined');
      return undefined;
    }
    const imageInfo = await imageSource.getImageInfo();
    const supportedMimeTypes = ['image/jpeg', 'image/heif', 'image/heic'];
    if (!supportedMimeTypes.includes(imageInfo.mimeType)) {
      console.error(`CreateThumbnail: Unsupported MIME type: ${imageInfo.mimeType}`);
      return undefined;
    }

    const decodingOptions: image.DecodingOptionsForThumbnail = {
      generateThumbnailIfAbsent: true,
      maxGeneratedPixelDimension: 200,
    };

    const pixelmap = await imageSource.createThumbnail(decodingOptions);
    if (pixelmap) {
      console.info('Succeeded in creating thumbnail pixelMap object.');
      return pixelmap;
    } else {
      console.error('Failed to create thumbnail pixelMap.');
      return undefined;
    }
  } catch (error) {
    console.error('CreateThumbnail error:', JSON.stringify(error));
    return undefined;
  }
}
```

## createThumbnailSync

createThumbnailSync(options?: DecodingOptionsForThumbnail): PixelMap \| undefined

Creates a thumbnail synchronously based on image decoding options. This API returns a [PixelMap](arkts-apis-image-PixelMap.md) object.

Currently, thumbnail PixelMap objects can be created for JPEG and HEIF images.

Thumbnails contained in image files are decoded preferentially. If an image file does not contain a thumbnail, the original image is decoded.

> **NOTE**
>
> - Images occupy a large amount of memory. When you finish using a PixelMap instance, call [release](./arkts-apis-image-PixelMap.md#release7) to free the memory promptly.
> - Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.
> - This API operates synchronously and will block the current thread during execution. It should not be invoked from the main thread, as doing so can lead to application lag, frame drops, or delayed responsiveness. For details, see [Overview of Concurrency in Time-Consuming Tasks](../../arkts-utils/time-consuming-task-overview.md).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                        | Mandatory| Description      |
| ------- | ------------------------------------------------------------ | ---- | ---------- |
| options | [DecodingOptionsForThumbnail](arkts-apis-image-i.md#decodingoptionsforthumbnail) | No  | Decoding options, which control whether to generate a thumbnail and the target dimensions of the thumbnail.<br>Default behavior:<br>- If the image has a thumbnail, the original thumbnail is decoded, and the width and height of the returned PixelMap object are the same as those of the original thumbnail.<br>- If the original image does not have a thumbnail, the image is decoded and a thumbnail is generated through downsampling based on the decoding options. The width and height of the generated thumbnail PixelMap object are limited to 512 pixels.|

**Return value**

| Type                                                 | Description                  |
| ----------------------------------------------------- | ---------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) \| undefined | PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 7700102  | Unsupported mimetype.                          |
| 7700103  | Image too large.                               |
| 7700204  | Invalid parameter, e.g, invalid generate size. |
| 7700301  | Decode failed.                                 |
| 7700303  | Image does not carry thumbnail data.           |
| 7700305  | Thumbnail generation failed.                   |

**Example**

```ts
async function CreateThumbnailSync(imageSource: image.ImageSource): Promise<image.PixelMap | undefined> {
  try {
    if (!imageSource) {
      console.error('CreateThumbnailSync: imageSource is null or undefined');
      return undefined;
    }
    const imageInfo = await imageSource.getImageInfo();
    const supportedMimeTypes = ['image/jpeg', 'image/heif', 'image/heic'];
    if (!supportedMimeTypes.includes(imageInfo.mimeType)) {
      console.error(`CreateThumbnailSync: Unsupported MIME type: ${imageInfo.mimeType}`);
      return undefined;
    }

    const decodingOptionsForThumbnail: image.DecodingOptionsForThumbnail = {
      generateThumbnailIfAbsent: true,
      maxGeneratedPixelDimension: 200,
    };

    const pixelmap = imageSource.createThumbnailSync(decodingOptionsForThumbnail);

    if (pixelmap) {
      console.info('Succeeded in creating thumbnail pixelMap object.');
      return pixelmap;
    } else {
      console.error('Failed to create thumbnail pixelMap.');
      return undefined;
    }
  } catch (error) {
    console.error('CreateThumbnailSync error:', JSON.stringify(error));
    return undefined;
  }
}
```

## getDelayTimeList<sup>10+</sup>

getDelayTimeList(callback: AsyncCallback<Array\<number>>): void

Obtains an array of delay times. This API uses an asynchronous callback to return the result. This API applies only to images in GIF or WebP format.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback<Array\<number>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the array of delay times obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.              |
| 62980110| The image source data is incorrect.             |
| 62980111| The image source data is incomplete.            |
| 62980115 | Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| Failed to decode the image header. |
| 62980149 | Invalid MIME type for the image source. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetDelayTimeList(imageSourceObj : image.ImageSource) {
  imageSourceObj.getDelayTimeList((err: BusinessError, delayTimes: Array<number>) => {
    if (err) {
      console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in getting delayTimes object.');
    }
  })
}
```

## getDelayTimeList<sup>10+</sup>

getDelayTimeList(): Promise<Array\<number>>

Obtains an array of delay times. This API uses a promise to return the result. This API applies only to images in GIF or WebP format.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<Array\<number>> | Promise used to return an array of delay times.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980110 | The image source data is incorrect.      |
| 62980111 | The image source data is incomplete. |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.  |
| 62980122 | Failed to decode the image header.   |
| 62980149 | Invalid MIME type for the image source.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetDelayTimeList(imageSourceObj : image.ImageSource) {
  imageSourceObj.getDelayTimeList().then((delayTimes: Array<number>) => {
    console.info('Succeeded in getting delayTimes object.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get delayTimes object.code is ${err.code},message is ${err.message}`);
  })
}
```

## getFrameCount<sup>10+</sup>

getFrameCount(callback: AsyncCallback\<number>): void

Obtains the number of frames. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of frames obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096| The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980111| The image source data is incomplete. |
| 62980112| The image format does not match. |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be corrupted.            |
| 62980115| Invalid image parameter. |
| 62980116| Failed to decode the image. |
| 62980118| Failed to create the image plugin. |
| 62980122| Failed to decode the image header. |
| 62980137| Invalid media operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetFrameCount(imageSourceObj : image.ImageSource) {
  imageSourceObj.getFrameCount((err: BusinessError, frameCount: number) => {
    if (err) {
      console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in getting frame count.');
    }
  })
}
```

## getFrameCount<sup>10+</sup>

getFrameCount(): Promise\<number>

Obtains the number of frames. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<number> | Promise used to return the number of frames.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.             |
| 62980111 | The image source data is incomplete. |
| 62980112 | The image format does not match.        |
| 62980113| Unknown image format.The image data provided is not in a recognized or supported format, or it may be corrupted.            |
| 62980115 | Invalid image parameter.      |
| 62980116 | Failed to decode the image.          |
| 62980118 | Failed to create the image plugin.   |
| 62980122 | Failed to decode the image header.  |
| 62980137 | Invalid media operation.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetFrameCount(imageSourceObj : image.ImageSource) {
  imageSourceObj.getFrameCount().then((frameCount: number) => {
    console.info('Succeeded in getting frame count.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get frame count.code is ${err.code},message is ${err.message}`);
  })
}
```

## getDisposalTypeList<sup>12+</sup>

getDisposalTypeList(): Promise\<Array\<number>>

Obtains the list of disposal types. This API uses a promise to return the result. It is used only for GIF images.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<Array\<number>> | Promise used to return an array of disposal types.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.      |
| 62980101 | The image data is abnormal. |
| 62980137 | Invalid media operation.        |
| 62980149 | Invalid MIME type for the image source.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetDisposalTypeList(imageSourceObj : image.ImageSource) {
  imageSourceObj.getDisposalTypeList().then((disposalTypes: Array<number>) => {
    console.info('Succeeded in getting disposalTypes object.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to get disposalTypes object.code ${err.code},message is ${err.message}`);
  })
}
```

## release

release(callback: AsyncCallback\<void>): void

Releases this ImageSource instance. This API uses an asynchronous callback to return the result.

Images occupy a large amount of memory. When you finish using an ImageSource instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release(imageSourceObj : image.ImageSource) {
  imageSourceObj.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the image source instance.code ${err.code},message is ${err.message}`);
    } else {
      console.info('Succeeded in releasing the image source instance.');
    }
  })
}
```

## release

release(): Promise\<void>

Releases this ImageSource instance. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using an ImageSource instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function Release(imageSourceObj : image.ImageSource) {
  imageSourceObj.release().then(() => {
    console.info('Succeeded in releasing the image source instance.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to release the image source instance.code ${error.code},message is ${error.message}`);
  })
}
```

## getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>

Obtains the value of a property with the specified index in this image. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF<sup>12+</sup>, or WEBP<sup>23+</sup> format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> This API is supported since API version 7 and is deprecated since API version 11. You are advised to use [getImageProperty](#getimageproperty11) instead.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type                                                | Mandatory| Description                                |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------ |
| key     | string                                               | Yes  | Name of the property.                        |
| options | [GetImagePropertyOptions](arkts-apis-image-i.md#getimagepropertyoptionsdeprecated) | No  | Image properties, including the image index and default property value.|

**Return value**

| Type            | Description                                                             |
| ---------------- | ----------------------------------------------------------------- |
| Promise\<string> | Promise used to return the property value. If the operation fails, the default value is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageProperty(imageSourceObj : image.ImageSource) {
  imageSourceObj.getImageProperty("BitsPerSample")
    .then((data: string) => {
      console.info('Succeeded in getting the value of the specified attribute key of the image.');
    }).catch((error: BusinessError) => {
    console.error(`Failed to get the value of the specified attribute key of the image, error.code ${error.code}, error.message ${error.message}`);
  })
}
```

## getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, callback: AsyncCallback\<string>): void

Obtains the value of a property with the specified index in this image. This API uses an asynchronous callback to return the result.

This API applies only to images that are in JPEG, PNG, HEIF<sup>12+</sup>, or WEBP<sup>23+</sup> format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> This API is supported since API version 7 and is deprecated since API version 11. You are advised to use [getImageProperty](#getimageproperty11) instead.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| key      | string                 | Yes  | Name of the property.                                                |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the property value obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageProperty(imageSourceObj : image.ImageSource) {
  imageSourceObj.getImageProperty("BitsPerSample", (error: BusinessError, data: string) => {
    if (error) {
      console.error('Failed to get the value of the specified attribute key of the image.');
    } else {
      console.info('Succeeded in getting the value of the specified attribute key of the image.');
    }
  })
}
```

## getImageProperty<sup>(deprecated)</sup>

getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void

Obtains the value of a property in this image. This API uses an asynchronous callback to return the result.

This API applies only to images that are in JPEG, PNG, HEIF<sup>12+</sup>, or WEBP<sup>23+</sup> format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> This API is supported since API version 7 and is deprecated since API version 11. You are advised to use [getImageProperty](#getimageproperty11) instead.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                         |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------- |
| key      | string                                               | Yes  | Name of the property.                                                 |
| options  | [GetImagePropertyOptions](arkts-apis-image-i.md#getimagepropertyoptionsdeprecated) | Yes  | Image properties, including the image index and default property value.                         |
| callback | AsyncCallback\<string>                               | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the property value obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function GetImageProperty(imageSourceObj : image.ImageSource) {
  let property: image.GetImagePropertyOptions = { index: 0, defaultValue: '9999' }
  imageSourceObj.getImageProperty("BitsPerSample", property, (error: BusinessError, data: string) => {
    if (error) {
      console.error('Failed to get the value of the specified attribute key of the image.');
    } else {
      console.info('Succeeded in getting the value of the specified attribute key of the image.');
    }
  })
}
```

## modifyImageProperty<sup>(deprecated)</sup>

modifyImageProperty(key: string, value: string): Promise\<void>

Modifies the value of a property in this image. This API uses a promise to return the result.

This API applies only to images that are in JPEG, PNG, HEIF<sup>12+</sup>, or WEBP<sup>23+</sup> format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> - The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.
>
> - This API is supported since API version 9 and is deprecated since API version 11. You are advised to use [modifyImageProperty](#modifyimageproperty11) instead.
> - When calling the **modifyImageProperty** API to modify the **Exif** field, ensure that the corresponding image file has write permission. Otherwise, the field modification will fail.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| key     | string | Yes  | Name of the property.|
| value   | string | Yes  | New value of the property.    |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ModifyImageProperty(imageSourceObj : image.ImageSource) {
  imageSourceObj.modifyImageProperty("ImageWidth", "120").then(() => {
    imageSourceObj.getImageProperty("ImageWidth").then((width: string) => {
      console.info(`ImageWidth is :${width}`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to get the Image Width, error.code ${error.code}, error.message ${error.message}`);
    })
  }).catch((error: BusinessError) => {
    console.error(`Failed to modify the Image Width, error.code ${error.code}, error.message ${error.message}`);
  })
}
```

## modifyImageProperty<sup>(deprecated)</sup>

modifyImageProperty(key: string, value: string, callback: AsyncCallback\<void>): void

Modifies the value of a property in this image. This API uses an asynchronous callback to return the result.

This API applies only to images that are in JPEG, PNG, HEIF<sup>12+</sup>, or WEBP<sup>23+</sup> format and contain the Exif information. (The supported formats may vary depending on the hardware.)

> **NOTE**
>
> - The property byte length is changed when the **modifyImageProperty** API is called to modify the value of a property. Currently, you can call the API in an ImageSource instance created based on a file descriptor or path, but not an ImageSource instance created based on buffers.
>
> - This API is supported since API version 9 and is deprecated since API version 11. You are advised to use [modifyImageProperty](#modifyimageproperty11) instead.
> - When calling the **modifyImageProperty** API to modify the **Exif** field, ensure that the corresponding image file has write permission. Otherwise, the field modification will fail.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Parameters**

| Name  | Type               | Mandatory| Description                          |
| -------- | ------------------- | ---- | ------------------------------ |
| key      | string              | Yes  | Name of the property.                  |
| value    | string              | Yes  | New value of the property.                      |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function ModifyImageProperty(imageSourceObj : image.ImageSource) {
  imageSourceObj.modifyImageProperty("ImageWidth", "120", (err: BusinessError) => {
    if (err) {
      console.error(`Failed to modify the Image Width.code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('Succeeded in modifying the Image Width.');
    }
  })
}
```
