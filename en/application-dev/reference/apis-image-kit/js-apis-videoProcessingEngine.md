# @ohos.multimedia.videoProcessingEngine (Video Processing Engine)

The module provides the capabilities for enhancing the clarity and scaling of image content.

This module includes a base class: [ImageProcessor](#imageprocessor).

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { videoProcessingEngine } from '@kit.ImageKit';
```

## videoProcessingEngine.initializeEnvironment

initializeEnvironment(): Promise\<void>

Initializes the environment. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Return value**

|  Type| Description |
| ------------ | ------------ |
|  Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Video Processing Engine Error Codes](errorcode-videoprocessingengine.md).


| ID | Error Message |
| :------------ | :------------ |
| 801  | Capability not supported. Function initializeEnvironment can not work correctly due to limited device capabilities.|
| 29200002  | The global environment initialization for image processing failed, such as failure to initialize the GPU environment.  |
| 29200006  | The operation is not permitted. This may be caused by incorrect status.  |
| 29200007  | Out of memory.  |

**Example**

```ts
import { videoProcessingEngine } from '@kit.ImageKit';
async function initializeEnvironment() {
videoProcessingEngine.initializeEnvironment();
}
```

## videoProcessingEngine.deinitializeEnvironment

deinitializeEnvironment(): Promise\<void>

Deinitializes the environment. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Return value**

|  Type| Description |
| ------------ | ------------ |
|  Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Video Processing Engine Error Codes](errorcode-videoprocessingengine.md).

| ID | Error Message |
| :------------ | :------------ |
| 29200006  | The operation is not permitted. This may be caused by incorrect status.  |

**Example**

```ts
import { videoProcessingEngine } from '@kit.ImageKit';
async function deinitializeEnvironment() {
  videoProcessingEngine.initializeEnvironment();
  videoProcessingEngine.deinitializeEnvironment();
}
```

## videoProcessingEngine.create

create(): ImageProcessor

Creates an instance of the image processing module. If the operation fails, null is returned.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Return value**

|  Type| Description |
| ------------ | ------------ |
|  [ImageProcessor](#imageprocessor) | Instance of the image processing module. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Video Processing Engine Error Codes](errorcode-videoprocessingengine.md).

| ID | Error Message |
| :------------ | :------------ |
| 801  | Capability not supported. Function create can not work correctly due to limited device capabilities.|
| 29200003  | Failed to create image processing instance. For example, the number of instances exceeds the upper limit. |
| 29200007  | Out of memory.  |

**Example**

```ts
import { videoProcessingEngine } from '@kit.ImageKit';
async function create() {
videoProcessingEngine.initializeEnvironment();
let imageProcessor = videoProcessingEngine.create() as videoProcessingEngine.ImageProcessor;
}
```

## ImageProcessor

Image processing class, which provides capabilities for enhancing the clarity and scaling of image content. It performs necessary scaling operations based on the source image's width and height to generate the target image. It offers different scaling methods to balance performance and image quality.

Constraints:

- Only Standard Dynamic Range (SDR) images can be processed.
- Images in RGBA, BGRA, NV12, and NV21 pixel formats can be processed. The output format is the same as the input format.

### enhanceDetail

enhanceDetail(sourceImage: image.PixelMap, width: number, height: number, level?: QualityLevel): Promise\<image.PixelMap\>

Carries out detail enhancement processing. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Parameters**

|  Name| Type | Mandatory | Description |
| :------------ | :------------ | :------------ | :------------ |
|  sourceImage | [image.PixelMap](arkts-apis-image-PixelMap.md)  | Yes | Input image. |
|  width |  number | Yes | Target width, in px. |
|  height |  number | Yes |  Target height, in px.|
|  level | [QualityLevel](#qualitylevel)| No |  Algorithm level (**HIGH**, **MEDIUM**, **LOW**, or **NONE**). The default value is **NONE**.|

**Return value**

|  Type| Description |
| ------------ | ------------ |
| Promise\<[image.PixelMap](arkts-apis-image-PixelMap.md)\>  |  Promise usd to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Video Processing Engine Error Codes](errorcode-videoprocessingengine.md).

| ID | Error Message |
| :------------ | :------------ |
| 801  | Capability not supported. Function enhanceDetail can not work correctly due to limited device capabilities.|
|  29200007  | Out of memory.  |
|  29200009  | Input value is invalid. This error is returned for all of the following error conditions: <br>1 - Invalid input or output image buffer - The image buffer width(height) is too large or colorspace is incorrect. <br>2 - Invalid parameter - The parameter does not contain valid information, such as detail enhancer level is incorrect. |

**Example**

```ts
import { image, videoProcessingEngine } from '@kit.ImageKit';
async function enhanceDetail(sourceImage: image.PixelMap, width: number, height: number) {
  videoProcessingEngine.initializeEnvironment();
  let imageProcessor = videoProcessingEngine.create() as videoProcessingEngine.ImageProcessor;
  let enhancedPixelmap: Promise<image.PixelMap> = imageProcessor.enhanceDetail(sourceImage, width, height, videoProcessingEngine.QualityLevel.HIGH);
}
```

### enhanceDetail

enhanceDetail(sourceImage: image.PixelMap, scale: number, level?: QualityLevel): Promise\<image.PixelMap\>

Carries out detail enhancement processing. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Parameters**

|  Name| Type | Mandatory | Description |
| :------------ | :------------ | :------------ | :------------ |
|  sourceImage | [image.PixelMap](arkts-apis-image-PixelMap.md)  | Yes | Input image. |
|  scale |  number |  Yes|  Target scale factor.|
|  level | [QualityLevel](#qualitylevel)| No |  Algorithm level (**HIGH**, **MEDIUM**, **LOW**, or **NONE**). The default value is **NONE**.|

**Return value**

|  Type| Description |
| ------------ | ------------ |
| Promise\<[image.PixelMap](arkts-apis-image-PixelMap.md)\>  |  Promise usd to return the PixelMap object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Video Processing Engine Error Codes](errorcode-videoprocessingengine.md).

| ID | Error Message |
| :------------ | :------------ |
| 801  | Capability not supported. Function enhanceDetail can not work correctly due to limited device capabilities.|
|  29200007  | Out of memory.  |
|  29200009  | Input value is invalid. This error is returned for all of the following error conditions: <br>1 - Invalid input or output image buffer - The image buffer width(height) is too large or colorspace is incorrect. <br>2 - Invalid parameter - The parameter does not contain valid information, such as detail enhancer level is incorrect.  |

**Example**

```ts
import { image, videoProcessingEngine } from '@kit.ImageKit';
async function enhanceDetail(sourceImage: image.PixelMap, scale: number) {
  videoProcessingEngine.initializeEnvironment();
  let imageProcessor = videoProcessingEngine.create() as videoProcessingEngine.ImageProcessor;
  let enhancedPixelmap: Promise<image.PixelMap> = imageProcessor.enhanceDetail(sourceImage, scale, videoProcessingEngine.QualityLevel.HIGH);
}
```

### enhanceDetailSync

enhanceDetailSync(sourceImage: image.PixelMap, width: number, height: number, level?: QualityLevel): image.PixelMap

Carries out detail enhancement processing. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Parameters**

|  Name| Type | Mandatory | Description |
| :------------ | :------------ | :------------ | :------------ |
|  sourceImage | [image.PixelMap](arkts-apis-image-PixelMap.md)  | Yes | Input image. |
|  width |  number | Yes | Target width, in px. |
|  height |  number | Yes|  Target height, in px.|
|  level | [QualityLevel](#qualitylevel)| No |  Algorithm level (**HIGH**, **MEDIUM**, **LOW**, or **NONE**). The default value is **NONE**.|

**Return value**

|  Type| Description |
| ------------ | ------------ |
| [image.PixelMap](arkts-apis-image-PixelMap.md)  |  PixelMap object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Video Processing Engine Error Codes](errorcode-videoprocessingengine.md).

| ID | Error Message |
| :------------ | :------------ |
| 801  | Capability not supported. Function enhanceDetailSync can not work correctly due to limited device capabilities.|
|  29200004  | Failed to process image buffer. For example, the processing times out.  |
|  29200007  | Out of memory.  |
|  29200009  | Input value is invalid. This error is returned for all of the following error conditions: <br>1 - Invalid input or output image buffer - The image buffer width(height) is too large or colorspace is incorrect. <br>2 - Invalid parameter - The parameter does not contain valid information, such as detail enhancer level is incorrect. |

**Example**

```ts
import { image, videoProcessingEngine } from '@kit.ImageKit';
async function enhanceDetailSync(sourceImage:image.PixelMap, width: number, height: number) {
  videoProcessingEngine.initializeEnvironment();
  let imageProcessor = videoProcessingEngine.create() as videoProcessingEngine.ImageProcessor;
  let enhancedPixelmap: image.PixelMap = imageProcessor.enhanceDetailSync(
sourceImage, width, height, videoProcessingEngine.QualityLevel.HIGH);
}
```

### enhanceDetailSync

enhanceDetailSync(sourceImage: image.PixelMap, scale: number, level?: QualityLevel): image.PixelMap

Carries out detail enhancement processing. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Parameters**

|  Name| Type | Mandatory | Description |
| :------------ | :------------ | :------------ | :------------ |
|  sourceImage | [image.PixelMap](arkts-apis-image-PixelMap.md)  | Yes | Input image. |
|  scale |  number |  Yes|  Target scale factor.|
|  level | [QualityLevel](#qualitylevel)| No |  Algorithm level (**HIGH**, **MEDIUM**, **LOW**, or **NONE**). The default value is **NONE**.|

**Return value**

|  Type| Description |
| ------------ | ------------ |
| [image.PixelMap](arkts-apis-image-PixelMap.md)  |  PixelMap object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Video Processing Engine Error Codes](errorcode-videoprocessingengine.md).

| ID | Error Message |
| :------------ | :------------ |
| 801  | Capability not supported. Function enhanceDetailSync can not work correctly due to limited device capabilities.|
|  29200004  | Failed to process image buffer. For example, the processing times out.  |
|  29200007  | Out of memory.  |
|  29200009  | Input value is invalid. This error is returned for all of the following error conditions: <br>1 - Invalid input or output image buffer - The image buffer width(height) is too large or colorspace is incorrect. <br>2 - Invalid parameter - The parameter does not contain valid information, such as detail enhancer level is incorrect.  |

**Example**

```ts
import { image, videoProcessingEngine } from '@kit.ImageKit';
async function enhanceDetailSync(sourceImage:image.PixelMap, scale: number) {
  videoProcessingEngine.initializeEnvironment();
  let imageProcessor = videoProcessingEngine.create() as videoProcessingEngine.ImageProcessor;
  let enhancedPixelmap: image.PixelMap = imageProcessor.enhanceDetailSync(
sourceImage, scale, videoProcessingEngine.QualityLevel.HIGH);
}
```

## QualityLevel

Enumerates the algorithm levels.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

| Name | Value | Description |
| ------------ | ------------ | ------------ |
| NONE  | 0  | Applies only to scaling scenarios. Changing the aspect ratio is supported.<br>- Input resolution requirements (in px): width: [32, 3000]; height: [32, 3000]<br>- Output resolution requirements (in px): width: [32, 3000]; height: [32, 3000] |
|  LOW |  1 | Applies only to scaling scenarios. Changing the aspect ratio is supported.<br>- Input resolution requirements (in px): width: [32, 3000]; height: [32, 3000]<br>- Output resolution requirements (in px): width: [32, 3000]; height: [32, 3000] |
|  MEDIUM | 2  | Applies only to scaling scenarios. Changing the aspect ratio is supported.<br>- Input resolution requirements (in px): width: [32, 3000]; height: [32, 3000]<br>- Output resolution requirements (in px): width: [32, 3000]; height: [32, 3000] |
|  HIGH |  3 |  1. In scaling scenarios: Changing the aspect ratio is not supported.<br>- Input resolution requirements (in px): width: (32, 512) (2000, 8192]; height: (32, 512) (2000, 8192]<br>- Output resolution requirements (in px): width: (32, 512) (2000, 8192]; height: (32, 512) (2000, 8192]<br>2. In clarity enhancement and scaling scenarios: Changing the aspect ratio is supported.<br>- Input resolution requirements (in px): width: [512, 2000]; height: [512, 2000]<br>- Output resolution requirements (in px): width: [512, 2000]; height: [512, 2000]|
