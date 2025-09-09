# Interface (AVImageGenerator)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

AVImageGenerator is a class for video thumbnail retrieval. It provides APIs to obtain a thumbnail from a video. Before calling any API in AVImageGenerator, you must use [createAVImageGenerator()](arkts-apis-media-f.md#mediacreateavimagegenerator12) to create an AVImageGenerator instance.

For details about the demo for obtaining video thumbnails, see [Obtaining Video Thumbnails](../../media/media/avimagegenerator.md).

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

| Name                                               | Type                                                        | Read-Only| Optional| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fdSrc<sup>12+</sup>                                  | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                       | No  | Yes  | Media file descriptor, which specifies the data source.<br> **Example:**<br>There is a media file that stores continuous assets, the address offset is 0, and the byte length is 100. Its file descriptor is **AVFileDescriptor { fd = resourceHandle; offset = 0; length = 100; }**.<br>**NOTE**<br> After the resource handle (FD) is transferred to an AVImageGenerator instance, do not use the resource handle to perform other read and write operations, including but not limited to transferring this handle to other AVPlayer, AVMetadataExtractor, AVImageGenerator, or AVTranscoder instance. Competition occurs when multiple AVImageGenerator use the same resource handle to read and write files at the same time, resulting in errors in obtaining data.|

## fetchFrameByTime<sup>12+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams, callback: AsyncCallback\<image.PixelMap>): void

Obtains a video thumbnail. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | Yes  | Time of the video for which a thumbnail is to be obtained, in μs.|
| options | [AVImageQueryOptions](arkts-apis-media-e.md#avimagequeryoptions12)     | Yes  | Relationship between the thumbnail timestamp in and the video frame.|
| param | [PixelMapParams](arkts-apis-media-i.md#pixelmapparams12)     | Yes  | Format parameters of the thumbnail to be obtained.|
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)>   | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the PixelMap instance obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// Initialize input parameters.
let timeUs: number = 0;

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC;

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
};

// Obtain the thumbnail.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param, (error: BusinessError, pixelMap) => {
      if (error) {
        console.error(`Failed to fetch FrameByTime, err = ${JSON.stringify(error)}`);
        return;
      }
      pixel_map = pixelMap;
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

## fetchFrameByTime<sup>12+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams): Promise<image.PixelMap>

Obtains a video thumbnail. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | Yes  | Time of the video for which a thumbnail is to be obtained, in μs.|
| options | [AVImageQueryOptions](arkts-apis-media-e.md#avimagequeryoptions12)     | Yes  | Relationship between the thumbnail timestamp in and the video frame.|
| param | [PixelMapParams](arkts-apis-media-i.md#pixelmapparams12)    | Yes  | Format parameters of the thumbnail to be obtained.|

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)> | Promise used to return the video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// Initialize input parameters.
let timeUs: number = 0;

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC;

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
};

// Obtain the thumbnail.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param).then((pixelMap: image.PixelMap) => {
      pixel_map = pixelMap;
    }).catch((error: BusinessError) => {
      console.error(`Failed to fetch FrameByTime, error message:${error.message}`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

## fetchScaledFrameByTime<sup>20+</sup>

fetchScaledFrameByTime(timeUs: number, queryMode: AVImageQueryOptions, outputSize?: OutputSize):Promise\<image.PixelMap\>

Fetches a scaled thumbnail from the video at a particular timestamp. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name    | Type                                         | Mandatory| Description                                                |
| ---------- | --------------------------------------------- | ---- | ---------------------------------------------------- |
| timeUs     | number                                        | Yes  | Timestamp, in microseconds (μs), at which the thumbnail is to be fetched from the video.|
| queryMode  | [AVImageQueryOptions](arkts-apis-media-e.md#avimagequeryoptions12) | Yes  | Relationship between the thumbnail timestamp in and the video frame.          |
| outputSize | [OutputSize ](arkts-apis-media-i.md#outputsize20)                  | No  | Output size of the thumbnail. By default, the original image size is used.              |

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)> | Promise used to return the video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';
let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;
// Initialize input parameters.
let timeUs: number = 0;
let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC;
let outputSize: media.OutputSize = {
  width : 300,
  height : 300,
};
// Obtain the thumbnail.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.fetchScaledFrameByTime(timeUs, queryOption, outputSize).then((pixelMap: image.PixelMap) => {
      pixel_map = pixelMap;
    }).catch((error: BusinessError) => {
      console.error(`Failed to fetch ScaledFrameByTime, error message:${error.message}`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

## release<sup>12+</sup>

release(callback: AsyncCallback\<void>): void

Releases this AVImageGenerator instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

// Release the resources.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.release((error: BusinessError) => {
      if (error) {
        console.error(`Failed to release, err = ${JSON.stringify(error)}`);
        return;
      }
      console.info(`Succeeded in releasing`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

## release<sup>12+</sup>

release(): Promise\<void>

Releases this AVImageGenerator instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

// Release the instance.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.release().then(() => {
      console.info(`Succeeded in releasing.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to release, error message:${error.message}`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```
