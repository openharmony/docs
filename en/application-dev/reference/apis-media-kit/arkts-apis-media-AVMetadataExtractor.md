# Interface (AVMetadataExtractor)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

AVImageGenerator is a class for metadata retrieval. It provides APIs to obtain metadata and thumbnails from media assets. Before calling any API of AVMetadataExtractor, you must use [media.createAVMetadataExtractor](arkts-apis-media-f.md#mediacreateavmetadataextractor11) to create an AVMetadataExtractor instance.

For details about the demo of obtaining audio or video metadata and video thumbnails, see [Using AVMetadataExtractor to Extract Audio and Video Metadata (ArkTS)](../../media/media/avmetadataextractor.md).

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

| Name                                               | Type                                                        | Readable| Writable| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fdSrc<sup>11+</sup>                                  | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                       | Yes  | Yes  | Media file descriptor, which specifies the data source. Before obtaining metadata, you must set the data source through either **fdSrc** or **dataSrc**.<br> **Example:**<br>There is a media file that stores continuous assets, the address offset is 0, and the byte length is 100. Its file descriptor is **AVFileDescriptor { fd = resourceHandle; offset = 0; length = 100; }**.<br>**NOTE**<br> - After the resource handle (FD) is transferred to an AVMetadataExtractor instance, do not use the resource handle to perform other read and write operations, including but not limited to transferring this handle to other AVPlayer, AVMetadataExtractor, AVImageGenerator, or AVTranscoder instance. Competition occurs when multiple AVMetadataExtractor use the same resource handle to read and write files at the same time, resulting in errors in obtaining data.|
| dataSrc<sup>11+</sup>                               | [AVDataSrcDescriptor](arkts-apis-media-i.md#avdatasrcdescriptor10)                | Yes  | Yes  | Streaming media resource descriptor, which specifies the data source. Before obtaining metadata, you must set the data source through either **fdSrc** or **dataSrc**.<br> When an application obtains a media file from the remote, you can set **dataSrc** to obtain the metadata before the application finishes the downloading.|

### setUrlSource<sup>20+</sup>

setUrlSource(url: string, headers?: Record\<string, string>): Promise\<void>

Sets the data source for a network on-demand resource. This API uses a promise to return the result. Only network metadata ([fetchMetadata](#fetchmetadata11)) and thumbnails ([fetchFrameByTime](#fetchframebytime20)) can be obtained. The media resource URL must be set before the retrieval.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| url | string       | Yes  | URL of the media resource.<br>1. The video formats MP4, MPEG-TS, and MKV are supported.<br>2. The audio formats M4A, AAC, MP3, OGG, WAV, FLAC, and AMR are supported.<br>**Example of supported URLs**:<br>1. HTTP: http\://xx<br>2. HTTPS: https\://xx<br>**NOTE**<br>- HLS/DASH and live streaming resources cannot be set.<br>- To set a network resource path, you must declare the [ohos.permission.INTERNET](../../security/AccessToken/permissions-for-all.md#ohospermissioninternet) permission by following the instructions provided in [Declaring Permissions](../../security/AccessToken/declare-permissions.md). The error code [201](../errorcode-universal.md) may be reported.|
| headers | Record\<string, string> | No  | Custom HTTP headers for accessing the network resource. The default value is empty.|

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201      | Permission denied, requires internet access permission. Returned by promise.  |
| 5400102  | Operation not allowed, the URL source has already been set and cannot be modified. Returned by promise. |
| 5400108  | Parameter check failed. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

let avMetadataExtractor: media.AVMetadataExtractor | undefined = undefined;

media.createAVMetadataExtractor(async (error: BusinessError, extractor: media.AVMetadataExtractor) => {
  if (extractor != null) {
    avMetadataExtractor = extractor;
    console.info('Succeeded in creating AVMetadataExtractor');
    let url = "http://xx";
    let headers: Record<string, string> = {
      "User-Agent" : "User-Agent-Value"
    };
    await avMetadataExtractor.setUrlSource(url, headers).then(() => {
    }).catch((error: BusinessError) => {
      console.error(`Failed to setUrlSource, code: ${error.code} message: ${error.message}`);
    });
  } else {
    console.error(`Failed to create AVMetadataExtractor, error message:${error.message}`);
  }
});
```

### fetchFrameByTime<sup>20+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams): Promise\<image.PixelMap>

Obtains a video thumbnail. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | Yes  | Time of the video for which a thumbnail is to be obtained, in us.|
| options | [AVImageQueryOptions](arkts-apis-media-e.md#avimagequeryoptions12)     | Yes  | Relationship between the time passed in and the video frame.|
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
| 5400108  | Parameter check failed. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';

let avMetadataExtractor: media.AVMetadataExtractor | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// Initialize input parameters.
let timeUs: number = 0;
let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_PREVIOUS_SYNC;
let param: media.PixelMapParams = {
  width : 300,
  height : 300
};
// Obtain the thumbnail.
media.createAVMetadataExtractor((error: BusinessError, extractor: media.AVMetadataExtractor) => {
  if (extractor != null) {
    avMetadataExtractor = extractor;
    console.info('Succeeded in creating AVMetadataExtractor');
    avMetadataExtractor.fetchFrameByTime(timeUs, queryOption, param).then((pixelMap: image.PixelMap) => {
      pixel_map = pixelMap;
    }).catch((error: BusinessError) => {
      console.error(`Failed to fetch FrameByTime, error message:${error.message}`);
    });
  } else {
    console.error(`Failed to create AVMetadataExtractor, error message:${error.message}`);
  }
});
```

## fetchMetadata<sup>11+</sup>

fetchMetadata(callback: AsyncCallback\<AVMetadata>): void

Obtains media metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<[AVMetadata](arkts-apis-media-i.md#avmetadata11)>       | Yes  | Callback used to return the result, which is an AVMetadata instance.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.fetchMetadata((error: BusinessError, metadata: media.AVMetadata) => {
  if (error) {
    console.error(`Failed to fetch Metadata, err = ${JSON.stringify(error)}`);
    return;
  }
  console.info(`Succeeded in fetching Metadata, genre: ${metadata.genre}`);
});
```

## fetchMetadata<sup>11+</sup>

fetchMetadata(): Promise\<AVMetadata>

Obtains media metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[AVMetadata](arkts-apis-media-i.md#avmetadata11)>  | Promise used to return the result. which is an AVMetadata instance.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.fetchMetadata().then((metadata: media.AVMetadata) => {
  console.info(`Succeeded in fetching Metadata, genre: ${metadata.genre}`);
}).catch((error: BusinessError) => {
  console.error(`Failed to fetch Metadata, error message:${error.message}`);
});
```

## fetchAlbumCover<sup>11+</sup>

fetchAlbumCover(callback: AsyncCallback\<image.PixelMap>): void

Obtains the cover of the audio album. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)>    | Yes  | Callback used to return the album cover.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let pixel_map : image.PixelMap | undefined = undefined;

avMetadataExtractor.fetchAlbumCover((error: BusinessError, pixelMap: image.PixelMap) => {
  if (error) {
    console.error(`Failed to fetch AlbumCover, error = ${JSON.stringify(error)}`);
    return;
  }
  pixel_map = pixelMap;
});
```

## fetchAlbumCover<sup>11+</sup>

fetchAlbumCover(): Promise\<image.PixelMap>

Obtains the cover of the audio album. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)> |  Promise used to return the album cover.|

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

let pixel_map : image.PixelMap | undefined = undefined;

avMetadataExtractor.fetchAlbumCover().then((pixelMap: image.PixelMap) => {
  pixel_map = pixelMap;
}).catch((error: BusinessError) => {
  console.error(`Failed to fetch AlbumCover, error message:${error.message}`);
});
```

## release<sup>11+</sup>

release(callback: AsyncCallback\<void>): void

Releases this AVMetadataExtractor instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<void>                   | Yes  |Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.release((error: BusinessError) => {
  if (error) {
    console.error(`Failed to release, err = ${JSON.stringify(error)}`);
    return;
  }
  console.info(`Succeeded in releasing.`);
});
```

## release<sup>11+</sup>

release(): Promise\<void>

Releases this AVMetadataExtractor instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

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

avMetadataExtractor.release().then(() => {
  console.info(`Succeeded in releasing.`);
}).catch((error: BusinessError) => {
  console.error(`Failed to release, error message:${error.message}`);
});
```
