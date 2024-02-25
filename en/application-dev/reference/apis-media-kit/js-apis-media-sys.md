# @ohos.multimedia.media (Media) (System API)

The multimedia subsystem provides a set of simple and easy-to-use APIs for you to access the system and use media resources.

This subsystem offers the following audio and video services:

- Obtaining video thumbnails ([AVImageGenerator](#avimagegenerator11)<sup>11+</sup>)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.media (Media)](js-apis-media.md).

## Modules to Import

```ts
import media from '@ohos.multimedia.media';
```

## media.createAVImageGenerator<sup>11+</sup>

createAVImageGenerator(callback: AsyncCallback\<AVImageGenerator>): void

Creates an **AVImageGenerator** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVImageGenerator](#avimagegenerator11)> | Yes  | Callback used to return the result. If the operation is successful, an **AVImageGenerator** instance is returned; otherwise, **null** is returned. The interface can be used to obtain a video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let avImageGenerator: media.AVImageGenerator;
media.createAVImageGenerator((error: BusinessError, generator: media.AVImageGenerator) => {
  if (generator != null) {
    avImageGenerator = generator;
    console.info('createAVImageGenerator success');
  } else {
    console.error(`createAVImageGenerator fail, error message:${error.message}`);
  }
});
```

## media.createAVImageGenerator<sup>11+</sup>

createAVImageGenerator(): Promise\<AVImageGenerator>

Creates an **AVImageGenerator** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVImageGenerator](#avimagegenerator11)> | Promise used to return the result. If the operation is successful, an **AVImageGenerator** instance is returned; otherwise, **null** is returned. The interface can be used to obtain a video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let avImageGenerator: media.AVImageGenerator;
media.createAVImageGenerator().then((generator: media.AVImageGenerator) => {
  if (generator != null) {
    avImageGenerator = generator;
    console.info('createAVImageGenerator success');
  } else {
    console.error('createAVImageGenerator fail');
  }
}).catch((error: BusinessError) => {
  console.error(`AVImageGenerator catchCallback, error message:${error.message}`);
});
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void

Creates a **VideoRecorder** instance. This API uses an asynchronous callback to return the result.

Only one **VideoRecorder** instance can be created per device.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[VideoRecorder](#videorecorder9)> | Yes  | Callback used to return the result. If the operation is successful, a **VideoRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record video.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let videoRecorder: media.VideoRecorder;
media.createVideoRecorder((error: BusinessError, video: media.VideoRecorder) => {
  if (video != null) {
    videoRecorder = video;
    console.info('video createVideoRecorder success');
  } else {
    console.error(`video createVideoRecorder fail, error message:${error.message}`);
  }
});
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(): Promise\<VideoRecorder>

Creates a **VideoRecorder** instance. This API uses a promise to return the result.

Only one **VideoRecorder** instance can be created per device.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[VideoRecorder](#videorecorder9)> | Promise used to return the result. If the operation is successful, a **VideoRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record video.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let videoRecorder: media.VideoRecorder;
media.createVideoRecorder().then((video: media.VideoRecorder) => {
  if (video != null) {
    videoRecorder = video;
    console.info('video createVideoRecorder success');
  } else {
    console.error('video createVideoRecorder fail');
  }
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error message:${error.message}`);
});
```

## AVImageGenerator<sup>11+</sup>

Provides APIs to obtain a thumbnail from a video. Before calling any API of **AVImageGenerator**, you must use [createAVImageGenerator()](#mediacreateavimagegenerator11) to create an **AVImageGenerator** instance.

For details about the demo for obtaining video thumbnails, see [Obtaining Video Thumbnails](../../media/avimagegenerator.md).

### Attributes

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

| Name                                               | Type                                                        | Readable| Writable| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fdSrc<sup>11+</sup>                                  | [AVFileDescriptor](js-apis-media.md#avfiledescriptor9)                       | Yes  | Yes  | Media file descriptor, which specifies the data source.<br>**Example:**<br>There is a media file that stores continuous assets, the address offset is 0, and the byte length is 100. Its file descriptor is **AVFileDescriptor {fd = resourceHandle; offset = 0; length = 100; }**. |

### fetchFrameByTime<sup>11+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams, callback: AsyncCallback\<image.PixelMap>): void

Obtains a video thumbnail. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | Yes  | Time of the video for which a thumbnail is to be obtained, in μs.|
| options | [AVImageQueryOptions](#avimagequeryoptions11)     | Yes  | Relationship between the time passed in and the video frame.|
| param | [PixelMapParams](#pixelmapparams11)      | Yes  | Format parameters of the thumbnail to be obtained.|
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)>   | Yes  | Callback used to return the video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import media from '@ohos.multimedia.media';
import image from '@ohos.multimedia.image';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// Initialize input parameters.
let timeUs: number = 0

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
  colorFormat : media.PixelFormat.RGB_565
}

// Obtain the thumbnail.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.error(`createAVImageGenerator success`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param, (error: BusinessError, pixelMap) => {
      if (error) {
        console.error(`fetchFrameByTime callback failed, err = ${JSON.stringify(error)}`)
        return
      }
      pixel_map = pixelMap;
    });
  } else {
    console.error(`createAVImageGenerator fail, error message:${err.messag-e}`);
  };
});
```

### fetchFrameByTime<sup>11+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams): Promise<image.PixelMap>

Obtains a video thumbnail. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | Yes  | Time of the video for which a thumbnail is to be obtained, in μs.|
| options | [AVImageQueryOptions](#avimagequeryoptions11)     | Yes  | Relationship between the time passed in and the video frame.|
| param | [PixelMapParams](#pixelmapparams11)      | Yes  | Format parameters of the thumbnail to be obtained.|

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | Promise used to return the video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import media from '@ohos.multimedia.media';
import image from '@ohos.multimedia.image';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// Initialize input parameters.
let timeUs: number = 0

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
  colorFormat : media.PixelFormat.RGB_565
}

// Obtain the thumbnail.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.error(`createAVImageGenerator success`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param).then((pixelMap: image.PixelMap) => {
      pixel_map = pixelMap;
    }).catch((error: BusinessError) => {
      console.error(`fetchFrameByTime catchCallback, error message:${error.message}`);
    });
  } else {
    console.error(`createAVImageGenerator fail, error message:${err.message}`);
  };
});
```

### release<sup>11+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **AVMetadataExtractor** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import media from '@ohos.multimedia.media';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

// Release the instance.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.error(`createAVImageGenerator success`);
    avImageGenerator.release((error: BusinessError) => {
      if (error) {
        console.error(`release failed, err = ${JSON.stringify(error)}`);
        return;
      }
      console.info(`release success.`);
    });
  } else {
    console.error(`createAVImageGenerator fail, error message:${err.message}`);
  };
});
```

### release<sup>11+</sup>

release(): Promise\<void>

Releases this **AVMetadataExtractor** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import media from '@ohos.multimedia.media';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

// Release the instance.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.error(`creatAVImageGenerator success`);
    avImageGenerator.release().then(() => {
      console.info(`release success.`);
    }).catch((error: BusinessError) => {
      console.error(`release catchCallback, error message:${error.message}`);
    });
  } else {
    console.error(`creatAVImageGenerator fail, error message:${err.message}`);
  };
});
```

## AVImageQueryOptions<sup>11+</sup>

Enumerates the relationship between the video frame and the time at which the video thumbnail is obtained.

The time passed in for obtaining the thumbnail may be different from the time of the video frame for which the thumbnail is actually obtained. Therefore, you need to specify their relationship.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| AV_IMAGE_QUERY_NEXT_SYNC       | 0   | The key frame at or next to the specified time is selected.                      |
| AV_IMAGE_QUERY_PREVIOUS_SYNC        | 1    | The key frame at or prior to the specified time is selected.|
| AV_IMAGE_QUERY_CLOSEST_SYNC        | 2    | The key frame closest to the specified time is selected.                |
| AV_IMAGE_QUERY_CLOSEST          | 3      | The frame (not necessarily a key frame) closest to the specified time is selected.    |

## PixelMapParams<sup>11+</sup>

Defines the format parameters of the video thumbnail to be obtained.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

| Name    | Type  |  Readable  |   Writable   |  Description                  |
| -------- | ------ |   ------| ------ | ---------------------- |
| width     | number |  Yes  |  Yes  |  Width of the thumbnail.        |
| height | number |  Yes  |  Yes  | Height of the thumbnail.|
| colorFormat  | [PixelFormat](#pixelformat11) |  Yes  |  Yes  | Color format of the thumbnail.        |

## PixelFormat<sup>11+</sup>

Enumerates the color formats supported by the video thumbnail.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**System API**: This is a system API.

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| RGB_565       | 2   | RGB_565.                      |
| RGBA_8888        | 3    | RGBA_8888.|
| RGB_888        | 5    | RGB_888.                |

## VideoRecorder<sup>9+</sup>

> **NOTE**
> This class is deprecated after AVRecorder<sup>9+</sup> is released. You are advised to use [AVRecorder](js-apis-media.md#avrecorder9) instead.

Implements video recording. Before calling any API in the **VideoRecorder** class, you must use [createVideoRecorder()](#mediacreatevideorecorder9) to create a [VideoRecorder](#videorecorder9) instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name              | Type                                  | Readable| Writable| Description            |
| ------------------ | -------------------------------------- | ---- | ---- | ---------------- |
| state<sup>9+</sup> | [VideoRecordState](#videorecordstate9) | Yes  | No  | Video recording state.|

### prepare<sup>9+</sup>

prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void

Sets video recording parameters. This API uses an asynchronous callback to return the result.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| config   | [VideoRecorderConfig](#videorecorderconfig9) | Yes  | Video recording parameters to set.           |
| callback | AsyncCallback\<void>                         | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 201      | Permission denied. Return by callback.     |
| 401      | Parameter error. Return by callback.       |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// Configure the parameters based on those supported by the hardware device.
let videoProfile: media.VideoRecorderProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : media.CodecMimeType.AUDIO_AAC,
  audioSampleRate : 48000,
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,
  videoBitrate : 2000000,
  videoCodec : media.CodecMimeType.VIDEO_AVC,
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
}

let videoConfig: media.VideoRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : videoProfile,
  url : 'fd://xx', // The file must be created by the caller and granted with proper permissions.
  rotation : 0,
  location : { latitude : 30, longitude : 130 }
}

// asyncallback
videoRecorder.prepare(videoConfig, (err: BusinessError) => {
  if (err == null) {
    console.info('prepare success');
  } else {
    console.error('prepare failed and error is ' + err.message);
  }
})
```

### prepare<sup>9+</sup>

prepare(config: VideoRecorderConfig): Promise\<void>

Sets video recording parameters. This API uses a promise to return the result.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name| Type                                        | Mandatory| Description                    |
| ------ | -------------------------------------------- | ---- | ------------------------ |
| config | [VideoRecorderConfig](#videorecorderconfig9) | Yes  | Video recording parameters to set.|

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201      | Permission denied. Return by promise.     |
| 401      | Parameter error. Return by promise.       |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// Configure the parameters based on those supported by the hardware device.
let videoProfile: media.VideoRecorderProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : media.CodecMimeType.AUDIO_AAC,
  audioSampleRate : 48000,
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,
  videoBitrate : 2000000,
  videoCodec : media.CodecMimeType.VIDEO_AVC,
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
}

let videoConfig: media.VideoRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : videoProfile,
  url : 'fd://xx', // The file must be created by the caller and granted with proper permissions.
  rotation : 0,
  location : { latitude : 30, longitude : 130 }
}

// promise
videoRecorder.prepare(videoConfig).then(() => {
  console.info('prepare success');
}).catch((err: BusinessError) => {
  console.error('prepare failed and catch error is ' + err.message);
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(callback: AsyncCallback\<string>): void

Obtains the surface required for recording. This API uses an asynchronous callback to return the result. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp must be based on the system startup time.

This API can be called only after [prepare()](#prepare9) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// asyncallback
let surfaceID: string; // Surface ID passed to the external system.
videoRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
  if (err == null) {
    console.info('getInputSurface success');
    surfaceID = surfaceId;
  } else {
    console.error('getInputSurface failed and error is ' + err.message);
  }
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(): Promise\<string>;

 Obtains the surface required for recording. This API uses a promise to return the result. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp must be based on the system startup time.

This API can be called only after [prepare()](#prepare9-1) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<string> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// promise
let surfaceID: string; // Surface ID passed to the external system.
videoRecorder.getInputSurface().then((surfaceId: string) => {
  console.info('getInputSurface success');
  surfaceID = surfaceId;
}).catch((err: BusinessError) => {
  console.error('getInputSurface failed and catch error is ' + err.message);
});
```

### start<sup>9+</sup>

start(callback: AsyncCallback\<void>): void

Starts recording. This API uses an asynchronous callback to return the result.

This API can be called only after [prepare()](#prepare9) and [getInputSurface()](#getinputsurface9) are called, because the data source must pass data to the surface first.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// asyncallback
videoRecorder.start((err: BusinessError) => {
  if (err == null) {
    console.info('start videorecorder success');
  } else {
    console.error('start videorecorder failed and error is ' + err.message);
  }
});
```

### start<sup>9+</sup>

start(): Promise\<void>

Starts recording. This API uses a promise to return the result.

This API can be called only after [prepare()](#prepare9-1) and [getInputSurface()](#getinputsurface9-1) are called, because the data source must pass data to the surface first.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// promise
videoRecorder.start().then(() => {
  console.info('start videorecorder success');
}).catch((err: BusinessError) => {
  console.error('start videorecorder failed and catch error is ' + err.message);
});
```

### pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses recording. This API uses an asynchronous callback to return the result.

This API can be called only after [start()](#start9) is called. You can resume recording by calling [resume()](#resume9).

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// asyncallback
videoRecorder.pause((err: BusinessError) => {
  if (err == null) {
    console.info('pause videorecorder success');
  } else {
    console.error('pause videorecorder failed and error is ' + err.message);
  }
});
```

### pause<sup>9+</sup>

pause(): Promise\<void>

Pauses recording. This API uses a promise to return the result.

This API can be called only after [start()](#start9-1) is called. You can resume recording by calling [resume()](#resume9-1).

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// promise
videoRecorder.pause().then(() => {
  console.info('pause videorecorder success');
}).catch((err: BusinessError) => {
  console.error('pause videorecorder failed and catch error is ' + err.message);
});
```

### resume<sup>9+</sup>

resume(callback: AsyncCallback\<void>): void

Resumes recording. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// asyncallback
videoRecorder.resume((err: BusinessError) => {
  if (err == null) {
    console.info('resume videorecorder success');
  } else {
    console.error('resume videorecorder failed and error is ' + err.message);
  }
});
```

### resume<sup>9+</sup>

resume(): Promise\<void>

Resumes recording. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// promise
videoRecorder.resume().then(() => {
  console.info('resume videorecorder success');
}).catch((err: BusinessError) => {
  console.error('resume videorecorder failed and catch error is ' + err.message);
});
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

Stops recording. This API uses an asynchronous callback to return the result.

To start another recording, you must call [prepare()](#prepare9) and [getInputSurface()](#getinputsurface9) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// asyncallback
videoRecorder.stop((err: BusinessError) => {
  if (err == null) {
    console.info('stop videorecorder success');
  } else {
    console.error('stop videorecorder failed and error is ' + err.message);
  }
});
```

### stop<sup>9+</sup>

stop(): Promise\<void>

Stops recording. This API uses a promise to return the result.

To start another recording, you must call [prepare()](#prepare9-1) and [getInputSurface()](#getinputsurface9-1) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// promise
videoRecorder.stop().then(() => {
  console.info('stop videorecorder success');
}).catch((err: BusinessError) => {
  console.error('stop videorecorder failed and catch error is ' + err.message);
});
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases the video recording resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                            |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// asyncallback
videoRecorder.release((err: BusinessError) => {
  if (err == null) {
    console.info('release videorecorder success');
  } else {
    console.error('release videorecorder failed and error is ' + err.message);
  }
});
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases the video recording resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                     |
| -------------- | ----------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// promise
videoRecorder.release().then(() => {
  console.info('release videorecorder success');
}).catch((err: BusinessError) => {
  console.error('release videorecorder failed and catch error is ' + err.message);
});
```

### reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

Resets video recording. This API uses an asynchronous callback to return the result.

To start another recording, you must call [prepare()](#prepare9) and [getInputSurface()](#getinputsurface9) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | I/O error. Return by callback.    |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// asyncallback
videoRecorder.reset((err: BusinessError) => {
  if (err == null) {
    console.info('reset videorecorder success');
  } else {
    console.error('reset videorecorder failed and error is ' + err.message);
  }
});
```

### reset<sup>9+</sup>

reset(): Promise\<void>

Resets video recording. This API uses a promise to return the result.

To start another recording, you must call [prepare()](#prepare9-1) and [getInputSurface()](#getinputsurface9-1) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | I/O error. Return by promise.    |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// promise
videoRecorder.reset().then(() => {
  console.info('reset videorecorder success');
}).catch((err: BusinessError) => {
  console.error('reset videorecorder failed and catch error is ' + err.message);
});
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to video recording error events. After an error event is reported, you must handle the event and exit the recording.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during video recording.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback invoked when the event is triggered.                                      |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | I/O error. Return by callback.    |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

// This event is reported when an error occurs during the retrieval of videoRecordState.
videoRecorder.on('error', (error: BusinessError) => { // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
})
```

## VideoRecordState<sup>9+</sup>

Enumerates the video recording states. You can obtain the state through the **state** attribute.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name    | Type  | Description                  |
| -------- | ------ | ---------------------- |
| idle     | string | The video recorder is idle.        |
| prepared | string | The video recording parameters are set.|
| playing  | string | Video recording is in progress.        |
| paused   | string | Video recording is paused.        |
| stopped  | string | Video recording is stopped.        |
| error    | string | Video recording is in the error state.            |

## VideoRecorderConfig<sup>9+</sup>

Describes the video recording parameters.

The **audioSourceType** and **videoSourceType** parameters are used to distinguish video-only recording from audio and video recording. (For audio-only recording, use [AVRecorder](js-apis-media.md#avrecorder9) or [AudioRecorder](js-apis-media.md#audiorecorderdeprecated).) For video-only recording, set only **videoSourceType**. For audio and video recording, set both **audioSourceType** and **videoSourceType**.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name           | Type                                          | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](js-apis-media.md#audiosourcetype9)           | No  | Type of the audio source for video recording. This parameter is mandatory for audio recording.                     |
| videoSourceType | [VideoSourceType](js-apis-media.md#videosourcetype9)           | Yes  | Type of the video source for video recording.                                      |
| profile         | [VideoRecorderProfile](#videorecorderprofile9) | Yes  | Video recording profile.                                         |
| rotation        | number                                         | No  | Rotation angle of the recorded video. The value can only be 0 (default), 90, 180, or 270.      |
| location        | [Location](js-apis-media.md#location)                          | No  | Geographical location of the recorded video. By default, the geographical location information is not recorded.                |
| url             | string                                         | Yes  | Video output URL. Supported: fd://xx (fd number)<br>![](figures/en-us_image_url.png) |

## VideoRecorderProfile<sup>9+</sup>

Describes the video recording profile.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name            | Type                                        | Mandatory| Description            |
| ---------------- | -------------------------------------------- | ---- | ---------------- |
| audioBitrate     | number                                       | No  | Audio encoding bit rate. This parameter is mandatory for audio recording.|
| audioChannels    | number                                       | No  | Number of audio channels. This parameter is mandatory for audio recording.|
| audioCodec       | [CodecMimeType](js-apis-media.md#codecmimetype8)             | No  | Audio encoding format. This parameter is mandatory for audio recording.  |
| audioSampleRate  | number                                       | No  | Audio sampling rate. This parameter is mandatory for audio recording.    |
| fileFormat       | [ContainerFormatType](js-apis-media.md#containerformattype8) | Yes  | Container format of a file.|
| videoBitrate     | number                                       | Yes  | Video encoding bit rate.|
| videoCodec       | [CodecMimeType](js-apis-media.md#codecmimetype8)             | Yes  | Video encoding format.  |
| videoFrameWidth  | number                                       | Yes  | Width of the recorded video frame.|
| videoFrameHeight | number                                       | Yes  | Height of the recorded video frame.|
| videoFrameRate   | number                                       | Yes  | Video frame rate.  |
