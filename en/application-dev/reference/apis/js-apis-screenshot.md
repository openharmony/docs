# Screenshot
Provides APIs for you to set information such as the region to capture and the size of the screen region when capturing a screen.

> **NOTE**
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

save(options?: ScreenshotOptions, callback: AsyncCallback&lt;image.PixelMap&gt;): void

Takes a screenshot and saves it as a **PixelMap** object. This method uses a callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [ScreenshotOptions](#screenshotoptions) | No  | Consists of **screenRect**, **imageSize**, **rotation**, and **displayId**. You can set them separately.|
| callback | AsyncCallback&lt;image.PixelMap&gt;     | Yes  | Callback used to return a **PixelMap** object.                                  |

**Example**

  ```js
  var ScreenshotOptions = {
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
  screenshot.save(ScreenshotOptions, (err, data) => {
  	if (err) {
  		console.error('Failed to save the screenshot. Error: ' + JSON.stringify(err));
  		return;
  	}
  	console.info('Screenshot saved. Data: ' + JSON.stringify(data));
  });
  ```

## screenshot.save

save(options?: ScreenshotOptions): Promise&lt;image.PixelMap&gt;

Takes a screenshot and saves it as a **PixelMap** object. This method uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name | Type                                   | Mandatory| Description                                                        |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ScreenshotOptions](#screenshotoptions) | No  | Consists of **screenRect**, **imageSize**, **rotation**, and **displayId**. You can set them separately.|

**Return value**

| Type                         | Description                                           |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;image.PixelMap&gt; | Promise used to return a **PixelMap** object.|

**Example**

  ```js
  var ScreenshotOptions = {
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
  let promise = screenshot.save(ScreenshotOptions);
  promise.then(() => {
      console.log('screenshot save success');
  }).catch((err) => {
      console.log('screenshot save fail: ' + JSON.stringify(err));
  });
  ```
