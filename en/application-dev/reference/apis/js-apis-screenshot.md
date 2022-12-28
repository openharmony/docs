# @ohos.screenshot

The **Screenshot** module provides APIs for you to set information such as the region to capture and the size of the screen region when capturing a screen.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import screenshot from '@ohos.screenshot';
```

## ScreenshotOptions

Describes screenshot options.

**System capability**: SystemCapability.WindowManager.WindowManager.Core


| Name                | Type         | Mandatory| Description                                                        |
| ---------------------- | ------------- | ---- | ------------------------------------------------------------ |
| screenRect             | [Rect](#rect) | No  | Region of the screen to capture. If this parameter is null, the full screen will be captured.                      |
| imageSize              | [Size](#size) | No  | Size of the screen region to capture. If this parameter is null, the full screen will be captured.                      |
| rotation               | number        | No  | Rotation angle of the screenshot. Currently, the value can be **0** only. The default value is **0**.    |
| displayId<sup>8+</sup> | number        | No  | ID of the [display](js-apis-display.md#display) device on which the screen region is to be captured.|


## Rect

Describes the region of the screen to capture.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| left   | number | Yes  | Left boundary of the screen region to capture.|
| top    | number | Yes  | Top boundary of the screen region to capture.|
| width  | number | Yes  | Width of the screen region to capture.|
| height | number | Yes  | Height of the screen region to capture.|


## Size

Describes the size of the screen region to capture.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| width  | number | Yes  | Width of the screen region to capture.|
| height | number | Yes  | Height of the screen region to capture.|

## screenshot.save

save(options: ScreenshotOptions, callback: AsyncCallback&lt;image.PixelMap&gt;): void

Takes a screenshot and saves it as a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [ScreenshotOptions](#screenshotoptions) | Yes  | Screenshot settings consist of **screenRect**, **imageSize**, **rotation**, and **displayId**. You can set the parameters separately.|
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt;     | Yes  | Callback used to return a **PixelMap** object.                                  |

**Example**

  ```js
  let screenshotOptions = {
    "screenRect": {
        "left": 200,
        "top": 100,
        "width": 200,
        "height": 200},
    "imageSize": {
        "width": 300,
        "height": 300},
    "rotation": 0,
    "displayId": 0
  };
  try {
    screenshot.save(screenshotOptions, (err, pixelMap) => {
      if (err) {
          console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));
          return;
      }
      console.log('Succeeded in saving sreenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
      pixelMap.release(); // Release the memory in time after the PixelMap is used.
    });
  } catch (exception) {
    console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));
  };
  ```

## screenshot.save

save(callback: AsyncCallback&lt;image.PixelMap&gt;): void

Takes a screenshot and saves it as a **PixelMap** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt;     | Yes  | Callback used to return a **PixelMap** object.                                  |

**Example**

  ```js
  try {
    screenshot.save((err, pixelMap) => {
      if (err) {
          console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));
          return;
      }
      console.log('Succeeded in saving sreenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
      pixelMap.release(); // Release the memory in time after the PixelMap is used.
    });
  } catch (exception) {
    console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));
  };
  ```

## screenshot.save

save(options?: ScreenshotOptions): Promise&lt;image.PixelMap&gt;

Takes a screenshot and saves it as a **PixelMap** object. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name | Type                                   | Mandatory| Description                                                        |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ScreenshotOptions](#screenshotoptions) | No  | Screenshot settings consist of **screenRect**, **imageSize**, **rotation**, and **displayId**. You can set the parameters separately.|

**Return value**

| Type                         | Description                                           |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise used to return a **PixelMap** object.|

**Example**

  ```js
  let screenshotOptions = {
  	"screenRect": {
  		"left": 200,
  		"top": 100,
  		"width": 200,
  		"height": 200},
  	"imageSize": {
  		"width": 300,
  		"height": 300},
  	"rotation": 0,
  	"displayId": 0
  };
  try {
    let promise = screenshot.save(screenshotOptions);
    promise.then((pixelMap) => {
        console.log('Succeeded in saving sreenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
        pixelMap.release(); // Release the memory in time after the PixelMap is used.
    }).catch((err) => {
        console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));
    });
  } catch (exception) {
    console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));
  };
  ```
