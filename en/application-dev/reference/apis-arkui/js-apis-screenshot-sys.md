# @ohos.screenshot (Screenshot) (System API)

The **Screenshot** module provides APIs for you to set information such as the region to capture and the size of the screen region when capturing a screen.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.screenshot](js-apis-screenshot.md).

## Modules to Import

```ts
import { screenshot } from '@kit.ArkUI';
```

## ScreenshotOptions

Describes screenshot options.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                | Type         | Mandatory| Description                                                        |
| ---------------------- | ------------- | ---- | ------------------------------------------------------------ |
| screenRect             | [Rect](js-apis-screenshot.md#rect) | No  | Region of the screen to capture. If no value is passed, the region of the logical screen associated with the specified display ID is returned.                      |
| imageSize              | [Size](#size) | No  | Size of the captured image. If no value is passed, the size of the logical screen associated with the specified display ID is returned. If **screenRect** is smaller than **imageSize**, the image is stretched to **imageSize**; otherwise, it is compressed to **imageSize**.                      |
| rotation               | number        | No  | Angle by which the captured image should be rotated. Currently, the value can be **0** only. The default value is **0**.    |
| displayId<sup>8+</sup> | number        | No  | ID of the [display](js-apis-display.md#display) device on which the screen region is to be captured. The value must be an integer.|
| isNotificationNeeded<sup>14+</sup>| boolean        | No  | Whether to send a notification after a snapshot is captured. The value **true** means to send a notification, and **false** means the opposite. The default value is **true**. Such a notification can be listened for through [captureStatusChange](js-apis-display.md#displayoncapturestatuschange12).  |
| isCaptureFullOfScreen<sup>19+</sup> | boolean        | No  | Whether to capture all displays on the current screen. If the screen contains multiple displays, the value **true** means that the entire screen is captured, and **false** means that only the region of the logical screen associated with the specified display ID is captured.|

## Size

Describes the size of the screen region to capture.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| width  | number | Yes  | Width of the screen region to capture, in px. The value must be an integer.|
| height | number | Yes  | Height of the screen region to capture, in px. The value must be an integer.|

## screenshot.save

save(options: ScreenshotOptions, callback: AsyncCallback&lt;image.PixelMap&gt;): void

Takes a screenshot and saves it as a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [ScreenshotOptions](#screenshotoptions) | Yes  | Information about the snapshot.|
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt;     | Yes  | Callback used to return a **PixelMap** object. The size of the **PixelMap** object is **imageSize**. If **imageSize** is not specified, the size of the logical screen associated with the specified display ID is used.                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------- |
| 201     | Permission verification failed.|
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import  { image } from '@kit.ImageKit';

let screenshotOptions: screenshot.ScreenshotOptions = {
  "screenRect": {
    "left": 200,
    "top": 100,
    "width": 200,
    "height": 200 },
  "imageSize": {
    "width": 300,
    "height": 300 },
  "rotation": 0,
  "displayId": 0,
  "isNotificationNeeded": true,
  "isCaptureFullOfScreen": true
};
screenshot.save(screenshotOptions, (err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error('Failed to save screenshot. Code: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in saving screenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
  pixelMap.release(); // Release the memory in time after the PixelMap is used.
});
```

## screenshot.save

save(callback: AsyncCallback&lt;image.PixelMap&gt;): void

Takes a screenshot and saves it as a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt;     | Yes  | Callback used to return a **PixelMap** object.                                  |


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------- |
| 201     | Permission verification failed.|
| 202     | Permission verification failed. A non-system application calls a system API.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

screenshot.save((err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error('Failed to save screenshot. Code: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in saving screenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
  pixelMap.release(); // Release the memory in time after the PixelMap is used.
});
```

## screenshot.save

save(options?: ScreenshotOptions): Promise&lt;image.PixelMap&gt;

Takes a screenshot and saves it as a **PixelMap** object. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name | Type                                   | Mandatory| Description                                                        |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ScreenshotOptions](#screenshotoptions) | No  | Information about the snapshot.|

**Return value**

| Type                         | Description                                           |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Promise used to return a **PixelMap** object.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------- |
| 201     | Permission verification failed.|
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let screenshotOptions: screenshot.ScreenshotOptions = {
  "screenRect": {
    "left": 200,
    "top": 100,
    "width": 200,
    "height": 200 },
  "imageSize": {
    "width": 300,
    "height": 300 },
  "rotation": 0,
  "displayId": 0,
  "isNotificationNeeded": true,
  "isCaptureFullOfScreen": true
};
try {
  let promise = screenshot.save(screenshotOptions);
  promise.then((pixelMap: image.PixelMap) => {
    console.log('Succeeded in saving screenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
    pixelMap.release(); // Release the memory in time after the PixelMap is used.
  }).catch((err: BusinessError) => {
    console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));
};
```
