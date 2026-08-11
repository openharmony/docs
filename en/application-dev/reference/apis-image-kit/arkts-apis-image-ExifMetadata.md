# Class (ExifMetadata)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

ExifMetadata implements Metadata

Exchangeable Image File Format (Exif) metadata.

> **NOTE**
>
> The initial APIs of this module are supported since API version 23. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

For details about the property values, see [PropertyKey](arkts-apis-image-e.md#propertykey7).

| Name                               | Type                                              | Read-Only| Optional| Description                                                        |
| ----------------------------------- | -------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| newSubfileType                      | number                                             | No  | Yes  | Data type of a subfile (for example, basic types such as text or image, rather than specific storage formats).                   |
| subfileType                         | number                                             | No  | Yes  | Data type of a subfile. It has been deprecated. Use **newSubfileType** instead.|
| imageWidth                          | number                                             | No  | Yes  | Image width. The unit is px.                                                  |
| imageLength                         | number                                             | No  | Yes  | Image length. The unit is px.                                                  |
| bitsPerSample                       | number[]                                           | No  | Yes  | Number of bits for each pixel component. For example, RGB has 3 components with a format of 8,8,8.             |
| compression                         | number                                             | No  | Yes  | Algorithm standard for image compression.                                        |
| photometricInterpretation           | number                                             | No  | Yes  | Pixel composition, such as RGB (Red, Green, Blue) and YCbCr (Luma, Blue-difference Chroma, Red-difference Chroma).|
| imageDescription                    | string                                             | No  | Yes  | Image description.                                                  |
| make                                | string                                             | No  | Yes  | Manufacturer name of the capture device.                                  |
| model                               | string                                             | No  | Yes  | Camera model.                                                  |
| stripOffsets                        | number[]                                           | No  | Yes  | Strip storage offset of the image data, in bytes.<br>To improve the efficiency of large image access, the original pixel data is divided into multiple contiguous blocks (called strips).<br>This property stores the starting offset of each strip in the file sequentially.|
| orientation                         | [Orientation](arkts-apis-image-e.md#orientation23) | No  | Yes  | Image orientation.                                                  |
| samplesPerPixel                     | number                                             | No  | Yes  | Number of color components per pixel, applicable to RGB and YCbCr color models.<br>Since both the models are three-component models (three color channels, or one luminance component plus two chroma components), the standard value for this property is 3.<br>For JPEG-compressed images, this property will be replaced by the corresponding JPEG marker.|
| rowsPerStrip                        | number                                             | No  | Yes  | Number of rows per image strip.                                        |
| stripByteCounts                     | number[]                                           | No  | Yes  | Number of bytes in each strip after compression.                                  |
| xResolution                         | number                                             | No  | Yes  | Image resolution in the width direction.                                    |
| yResolution                         | number                                             | No  | Yes  | Image resolution in the height direction.                                    |
| planarConfiguration                 | number                                             | No  | Yes  | Whether the pixel components are recorded in chunked or planar format.                        |
| resolutionUnit                      | number                                             | No  | Yes  | Unit of the image resolution in the width and height directions.|
| transferFunction                    | string                                             | No  | Yes  | Transfer function for the image, which is usually used for color correction.                          |
| software                            | string                                             | No  | Yes  | Name and version number of the software used to create the image.                            |
| dateTime                            | string                                             | No  | Yes  | Date and time when the image is created.<br>In this standard, it refers to the file date and time. The value format is *YYYY:MM:DD HH:MM:SS* (24-hour clock). For example, 2025:12:15 18:44:59.|
| artist                              | string                                             | No  | Yes  | Name of the person who creates the image.                                        |
| whitePoint                          | number[]                                           | No  | Yes  | Chromaticity of the image white point.                                            |
| primaryChromaticities               | number[]                                           | No  | Yes  | Chromaticity of the image primaries.                                            |
| photoMode                           | number                                             | No  | Yes  | Image mode.                                                  |
| jpegInterchangeFormat               | number                                             | No  | Yes  | Start of Image (SOI) marker of the JPEG bitstream in interchange format.|
| jpegInterchangeFormatLength         | number                                             | No  | Yes  | Number of bytes in the JPEG stream.                                            |
| yCbCrCoefficients                   | number[]                                           | No  | Yes  | Transformation matrix coefficients for converting RGB image data to YCbCr image data.                  |
| yCbCrSubSampling                    | number[]                                           | No  | Yes  | Sampling ratios of the chroma components and luminance component.                                |
| yCbCrPositioning                    | number                                             | No  | Yes  | Position of chroma components relative to the luminance component.                              |
| referenceBlackWhite                 | number[]                                           | No  | Yes  | Reference black point value and white point value.                                        |
| copyright                           | string                                             | No  | Yes  | Copyright notice of the image.                                            |
| exposureTime                        | number                                             | No  | Yes  | Exposure time, in seconds.                                                  |
| fNumber                             | number                                             | No  | Yes  | F number, for example, f/1.8.                                           |
| exposureProgram                     | number                                             | No  | Yes  | Class used for exposure setting when the camera captures a photo.                      |
| spectralSensitivity                 | string                                             | No  | Yes  | Spectral sensitivity of each channel of the camera.                          |
| gpsVersionID                        | number[]                                           | No  | Yes  | GPS information format version identifier.                                     |
| gpsLatitudeRef                      | string                                             | No  | Yes  | GPS latitude reference. For example, **N** indicates north latitude, and **S** indicates south latitude.                   |
| gpsLatitude                         | number[]                                           | No  | Yes  | GPS latitude.<br>The latitude is represented by three RATIONAL values (numeric values stored in fractional form), corresponding to degrees, minutes, and seconds, in the **dd/1, mm/1, ss/1** format.<br>When using degrees and minutes, the minutes are stored with up to two decimal places, in the **dd/1, mmmm/100, 0/1** format.|
| gpsLongitudeRef                     | string                                             | No  | Yes  | GPS longitude reference. For example, **E** indicates east longitude, and **W** indicates west longitude.                   |
| gpsLongitude                        | number[]                                           | No  | Yes  | GPS longitude.<br>The longitude is represented by three RATIONAL values (numeric values stored in fractional form), corresponding to degrees, minutes, and seconds, in the **dd/1, mm/1, ss/1** format.<br>When using degrees and minutes, the minutes are stored with up to two decimal places, in the **dd/1, mmmm/100, 0/1** format.|
| gpsAltitudeRef                      | number                                             | No  | Yes  | GPS altitude reference.                                         |
| gpsAltitude                         | number                                             | No  | Yes  | GPS altitude based on **GPSAltitudeRef**.                            |
| gpsTimestamp                        | number[]                                           | No  | Yes  | GPS timestamp.                                                 |
| gpsSatellites                       | string                                             | No  | Yes  | GPS satellite used for measurement. Generally, the value is the GPS satellite's pseudo-random noise (PRN) number.                                         |
| gpsStatus                           | string                                             | No  | Yes  | Status of the GPS receiver when the image is recorded.                                 |
| gpsMeasureMode                      | string                                             | No  | Yes  | GPS measurement mode.                                               |
| gpsDop                              | number                                             | No  | Yes  | Dilution of Precision (DOP) of the GPS data.                                        |
| gpsSpeedRef                         | string                                             | No  | Yes  | Speed unit of the GPS receiver.                               |
| gpsSpeed                            | number                                             | No  | Yes  | Speed of the GPS receiver.                                       |
| gpsTrackRef                         | string                                             | No  | Yes  | Reference for the GPS receiver movement direction.                               |
| gpsTrack                            | number                                             | No  | Yes  | Movement direction of the GPS receiver.                                       |
| gpsImgDirectionRef                  | string                                             | No  | Yes  | Reference of the image orientation.                                            |
| gpsImgDirection                     | number                                             | No  | Yes  | Image orientation at the time of capture.                                          |
| gpsMapDatum                         | string                                             | No  | Yes  | Geodetic data used by the GPS receiver.                               |
| gpsDestLatitudeRef                  | string                                             | No  | Yes  | Latitude reference of the destination.                                      |
| gpsDestLatitude                     | number[]                                           | No  | Yes  | Latitude of the destination.                                              |
| gpsDestLongitudeRef                 | string                                             | No  | Yes  | Longitude reference of the destination.                                      |
| gpsDestLongitude                    | number[]                                           | No  | Yes  | Longitude of the destination.                                              |
| gpsDestBearingRef                   | string                                             | No  | Yes  | Bearing reference to the destination.                                      |
| gpsDestBearing                      | number                                             | No  | Yes  | Bearing to the destination.                                          |
| gpsDestDistanceRef                  | string                                             | No  | Yes  | Unit used to express the distance to the destination.                                    |
| gpsDestDistance                     | number                                             | No  | Yes  | Distance to the destination.                                            |
| gpsProcessingMethod | string | No| Yes| Name of the positioning method.|
| gpsAreaInformation                  | string                                             | No  | Yes  | String of the GPS area name.                                   |
| gpsDateStamp                        | string                                             | No  | Yes  | GPS date stamp.                                                 |
| gpsDifferential                     | number                                             | No  | Yes  | Whether differential correction has been applied to the GPS data, which is crucial for precise positioning accuracy. |
| gpsHPositioningError                | number                                             | No  | Yes  | Horizontal positioning error, in meters.                        |
| isoSpeedRatings                     | number                                             | No  | Yes  | ISO speed and latitude of the camera or input device, which are specified in ISO 12232.|
| photographicSensitivity             | number[]                                           | No  | Yes  | Sensitivity of the camera or input device during image capture.                |
| oecf                                | ArrayBuffer                                        | No  | Yes  | Opto-Electric Conversion Function (OECF) specified in ISO 14524.|
| sensitivityType                     | number                                             | No  | Yes  | Sensitivity type.                                                |
| standardOutputSensitivity           | number                                             | No  | Yes  | Standard output sensitivity.                                            |
| recommendedExposureIndex            | number                                             | No  | Yes  | Recommended exposure index.                                               |
| isoSpeedLatitudeyyy                 | number                                             | No  | Yes  | Maximum dynamic range recordable by the camera sensor in a single exposure. The unit is EV.|
| isoSpeedLatitudezzz                 | number                                             | No  | Yes  | Highlight retention capacity of the camera sensor in overexposure. The unit is EV.|
| exifVersion                         | string                                             | No  | Yes  | Version of the supported Exif standard.                                      |
| dateTimeOriginal                    | string                                             | No  | Yes  | Date and time when the original image data is generated.<br>For a digital still camera (DSC), the date and time when a photo is taken are recorded. The value format is *YYYY:MM:DD HH:MM:SS* (24-hour clock).|
| dateTimeDigitized                   | string                                             | No  | Yes  | Date and time when the image is stored as digital data.<br>For example, if a DSC captures an image and records the file at the same time, the values of **DateTimeOriginal** and **DateTimeDigitized** are the same. The value format is *YYYY:MM:DD HH:MM:SS* (24-hour clock).|
| offsetTime                          | string                                             | No  | Yes  | Supplement to **DateTime**, which resolves the timestamp ambiguity caused by geographical time zone changes.|
| offsetTimeOriginal                  | string                                             | No  | Yes  | Geographical time zone of the device.                                        |
| offsetTimeDigitized                 | string                                             | No  | Yes  | Coordinated Universal Time (UTC) offset at the time of image digitization, which helps to precisely adjust the timestamp. |
| componentsConfiguration             | string                                             | No  | Yes  | Information about the compressed data.                                        |
| compressedBitsPerPixel              | number                                             | No  | Yes  | Image compression scheme. The unit is bit/pixel.                  |
| shutterSpeedValue                   | number                                             | No  | Yes  | Shutter speed, expressed as an Additive System of Photographic Exposure (APEX) value.|
| apertureValue                       | number                                             | No  | Yes  | Lens aperture. The unit is APEX.                |
| brightnessValue                     | number                                             | No  | Yes  | Image brightness. The unit is APEX.                                |
| exposureBiasValue                   | number                                             | No  | Yes  | Exposure bias.                                                |
| maxApertureValue                    | number                                             | No  | Yes  | Minimum aperture value of the lens.                                          |
| subjectDistance                     | number                                             | No  | Yes  | Distance from the capture device to the photographed object, in meters.                        |
| meteringMode                        | number                                             | No  | Yes  | Metering mode.                                                  |
| lightSource                         | number                                             | No  | Yes  | Light source.                                                      |
| flash                               | number                                             | No  | Yes  | Flash.                                                      |
| focalLength                         | number                                             | No  | Yes  | Focal length of the lens, in millimeters.                                                      |
| subjectArea                         | number[]                                           | No  | Yes  | Location and area of the main object in the entire scene.                  |
| makerNote                           | ArrayBuffer                                        | No  | Yes  | Information required by the Exif/Design rule for Camera File system (DCF) writer manufacturer.                    |
| userComment                         | string                                             | No  | Yes  | User comments.                                                  |
| subsecTime                          | string                                             | No  | Yes  | Second fraction of **DateTime**.                        |
| subsecTimeOriginal                  | string                                             | No  | Yes  | Second of **DateTimeOriginal**.              |
| subsecTimeDigitized                 | string                                             | No  | Yes  | Second of **DateTimeDigitized**.             |
| flashpixVersion                     | string                                             | No  | Yes  | FlashPix format version supported by the FlashPix Extension Resource (FPXR), which is used to enhance device compatibility.|
| colorSpace                          | number                                             | No  | Yes  | Color space information, which is usually recorded as a color space descriptor.                |
| pixelXDimension                     | number                                             | No  | Yes  | Image size on the X axis (horizontal axis in a two-dimensional coordinate system). The unit is px.          |
| pixelYDimension                     | number                                             | No  | Yes  | Image size on the Y axis (vertical axis in a two-dimensional coordinate system). The unit is px.             |
| relatedSoundFile                    | string                                             | No  | Yes  | Name of the audio file related to the image data.                            |
| flashEnergy                         | number                                             | No  | Yes  | Flash energy at the time the image is captured. The unit is beam candlepower seconds (BCPS).|
| spatialFrequencyResponse            | ArrayBuffer                                        | No  | Yes  | Spatial frequency table of the camera or input device.                                  |
| focalPlaneXResolution               | number                                             | No  | Yes  | Number of pixels per unit physical length in the X-axis of the sensor's physical plane.         |
| focalPlaneYResolution               | number                                             | No  | Yes  | Number of pixels per unit physical length in the Y-axis of the sensor's physical plane.         |
| focalPlaneResolutionUnit            | number                                             | No  | Yes  | Measurement unit of **FocalPlaneXResolution** and **FocalPlaneYResolution**.      |
| subjectLocation                     | number[]                                           | No  | Yes  | Pixel coordinates of the primary object in the image (based on the origin in the upper left corner).                    |
| exposureIndex                       | number                                             | No  | Yes  | Exposure index selected at the time the image is captured.                                      |
| sensingMethod                       | number                                             | No  | Yes  | Type of the image sensor on the camera.                                    |
| fileSource                          | ArrayBuffer                                        | No  | Yes  | Image source.                                                |
| sceneType                           | ArrayBuffer                                        | No  | Yes  | Scene type.                                                  |
| cfaPattern                          | ArrayBuffer                                        | No  | Yes  | Color filter array (CFA) geometric pattern of the image sensor.                     |
| customRendered | number | No| Yes| Special processing of image data, such as HDR composition and AI scene enhancement.|
| exposureMode                        | number                                             | No  | Yes  | Exposure mode.                                  |
| whiteBalance                        | number                                             | No  | Yes  | White balance.                                                    |
| digitalZoomRatio                    | number                                             | No  | Yes  | Digital zoom ratio used when the image is captured.                                        |
| focalLengthIn35mmFilm               | number                                             | No  | Yes  | 35 mm equivalent focal length, in millimeters.                                            |
| sceneCaptureType                    | number                                             | No  | Yes  | Type of the scene that is captured.                                            |
| gainControl                         | number                                             | No  | Yes  | Degree of overall image gain adjustment.                                      |
| contrast                            | number                                             | No  | Yes  | Contrast optimization policy applied by the camera. For example, standard processing and contrast reduction.    |
| saturation                          | number                                             | No  | Yes  | Color saturation adjustment policy applied by the camera. For example, standard processing and saturation reduction.    |
| sharpness                           | number                                             | No  | Yes  | Edge enhancement processing method applied by the camera. For example, weak sharpening and standard sharpening.      |
| deviceSettingDescription            | ArrayBuffer                                        | No  | Yes  | Capture condition information of a specific camera model.                                |
| subjectDistanceRange                | number                                             | No  | Yes  | Distance range to the object.                                      |
| imageUniqueId                       | string                                             | No  | Yes  | Unique ID assigned to each image.                                |
| cameraOwnerName                     | string                                             | No  | Yes  | Name of the camera owner.                                          |
| bodySerialNumber                    | string                                             | No  | Yes  | Serial number of the camera body.                                          |
| lensSpecification                   | number[]                                           | No  | Yes  | Specifications of the lens.                                            |
| lensMake                            | string                                             | No  | Yes  | Manufacturer of the lens.                                              |
| lensModel                           | string                                             | No  | Yes  | Model of the lens.                                            |
| lensSerialNumber                    | string                                             | No  | Yes  | Serial number of the lens.                                              |
| compositeImage                      | number                                             | No  | Yes  | Whether the image is a composite image.                                    |
| sourceImageNumberOfCompositeImage   | number[]                                           | No  | Yes  | Number of source images of the composite image.                                  |
| sourceExposureTimesOfCompositeImage | ArrayBuffer                                        | No  | Yes  | Exposure time of source images for the composite image, for example, 1/33 s.                    |
| gamma                               | number                                             | No  | Yes  | Gamma value of each component.                                          |

## createInstance

static createInstance(): ExifMetadata

Creates an empty [ExifMetadata](arkts-apis-image-ExifMetadata.md) instance.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                            | Description                      |
| ------------------------------------------------ | -------------------------- |
| [ExifMetadata](arkts-apis-image-ExifMetadata.md) | Empty **ExifMetadata** instance.|

**Example**

```ts
async function exifMetadataCreateInstance(context: Context) {
  let exifMetadata = image.ExifMetadata.createInstance();
  if (exifMetadata != undefined) {
    console.info("Succeeded in creating an ExifMetadata instance.");
  }
}
```

## getProperties

getProperties(key: Array\<string>): Promise\<Record\<string, string \| null>>

Obtains the property values from image metadata. This API returns the result asynchronously through a promise.

For details about the properties, see [PropertyKey](arkts-apis-image-e.md#propertykey7).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type          | Mandatory| Description                  |
| ------ | -------------- | ---- | ---------------------- |
| key    | Array\<string> | Yes  | Names of the properties to query.|

**Return value**

| Type                                    | Description                                         |
| ---------------------------------------- | --------------------------------------------- |
| Promise\<Record\<string, string \| null>> | Promise used to return the obtained image metadata property values.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| Error Code| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 7600202  | Unsupported metadata. Possible causes: unsupported metadata type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg';  // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function exifMetadataGetProperties(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let metaData = await imageSource.readImageMetadata(["ImageWidth", "ImageLength"]);
  if (metaData != undefined && metaData.exifMetadata != undefined) {
    await metaData.exifMetadata.getProperties(["ImageWidth", "ImageLength"]).then((data) => {
      console.info(`Succeeded in getting properties. Data: ${JSON.stringify(data)}.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to get properties. Code: ${error.code}, message: ${error.message}.`);
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## setProperties

setProperties(records: Record\<string, string \| null>): Promise\<void>

Sets the values of specified properties in image metadata in batches. This API returns the result asynchronously through a promise.

For details about the properties, see [PropertyKey](arkts-apis-image-e.md#propertykey7).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name | Type                          | Mandatory| Description                    |
| ------- | ------------------------------ | ---- | ------------------------ |
| records | Record\<string, string \| null> | Yes  | Set of key-value pairs representing properties and corresponding values of the **ExifMetadata** object.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| Error Code| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 7600202  | Unsupported metadata. Possible causes: unsupported metadata type. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg';  // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function exifMetadataSetProperties(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let metaData = await imageSource.readImageMetadata(["ImageWidth", "ImageLength"]);
  if (metaData != undefined && metaData.exifMetadata != undefined) {
    let setkey: Record<string, string | null> = {
      "ImageWidth": "200",
      "ImageLength": "300"
    };
    await metaData.exifMetadata.setProperties(setkey).then(async () => {
      console.info('Succeeded in setting properties.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to set metadata Properties. code is ${error.code}, message is ${error.message}`);
    })
  } else {
    console.error('metadata is null. ');
  }
}
```

## getAllProperties

getAllProperties(): Promise\<Record\<string, string \| null>>

Obtains all properties and their values from the image metadata. This API returns the result asynchronously through a promise.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                    | Description                                       |
| ---------------------------------------- | ------------------------------------------- |
| Promise\<Record\<string, string \| null>> | Promise used to return the values of all properties.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg';  // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function exifMetadataGetAllProperties(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let metaData = await imageSource.readImageMetadata(["ImageWidth", "ImageLength"]);
  if (metaData != undefined && metaData.exifMetadata != undefined) {
    await metaData.exifMetadata.getAllProperties().then((data) => {
      const count = Object.keys(data).length;
      console.info(`Succeeded in getting all properties. Count: ${count}, data: ${JSON.stringify(data)}.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to get all properties. Code: ${error.code}, message: ${error.message}.`);
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## clone

clone(): Promise\<ExifMetadata>

Clones the Exif metadata. This API returns the result asynchronously through a promise.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                                                      | Description                                 |
| ---------------------------------------------------------- | ------------------------------------- |
| Promise\<[ExifMetadata](arkts-apis-image-ExifMetadata.md)> | Promise used to return the Exif metadata instance if the operation is successful.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg';  // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function exifMetadataClone(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let metaData = await imageSource.readImageMetadata(["ImageWidth", "ImageLength"]);
  if (metaData != undefined && metaData.exifMetadata != undefined) {
    let new_metadata = await metaData.exifMetadata.clone();
    new_metadata.getProperties(["ImageWidth"]).then((data1) => {
      console.info(`Succeeded in cloning metadata and getting properties. Data: ${JSON.stringify(data1)}.`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to clone metadata and get properties. Code: ${err.code}, message: ${err.message}.`);
    });
  } else {
    console.error('Metadata is null.');
  }
}
```

## getBlob

getBlob(): Promise\<ArrayBuffer>

Obtains the metadata in binary format. This API returns the result asynchronously through a promise.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise\<ArrayBuffer> | Promise used to return the binary data of the metadata.|

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg';  // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function exifMetadataGetBlob(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let metaData = await imageSource.readImageMetadata(["ImageWidth", "ImageLength"]);
  if (metaData != undefined && metaData.exifMetadata != undefined) {
    let blob = await metaData.exifMetadata.getBlob();
    if (blob != undefined) {
      console.info("Succeeded in getting blob.");
    }
  }
}
```

## setBlob

setBlob(blob: ArrayBuffer): Promise\<void>

Replaces the current metadata with binary data. This API returns the result asynchronously through a promise.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                |
| ------ | ----------- | ---- | -------------------- |
| blob   | ArrayBuffer | Yes  | Binary data used to replace the metadata.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| Error Code| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 7600206  | Invalid parameter. Possible causes: The blob is empty or has a length of 0. |

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';

function getFileFd(context: Context): number | undefined {
  const filePath: string = context.cacheDir + '/exif.jpg';  // An image containing Exif metadata is required.
  const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  const fd: number = file?.fd;
  return fd;
}

async function exifMetadataSetBlob(context: Context) {
  let fd = getFileFd(context);
  let imageSource = image.createImageSource(fd);
  let metaData = await imageSource.readImageMetadata(["ImageWidth", "ImageLength"]);
  if (metaData != undefined && metaData.exifMetadata != undefined) {
    let blob = await metaData.exifMetadata.getBlob();
    if (blob != undefined) {
      console.info("Succeeded in getting blob.");
      metaData.exifMetadata.setBlob(blob);
    }
    let new_blob = metaData.exifMetadata.getBlob();
    if (new_blob != undefined) {
      console.info("new_blob is not undefined");
    }
  }
}
```
