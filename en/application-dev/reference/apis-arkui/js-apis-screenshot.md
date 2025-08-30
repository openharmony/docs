# @ohos.screenshot (Screenshot)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk; @logn-->
<!--Designer: @hejunfei1991-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

The module provides the screen capture capability.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { screenshot } from '@kit.ArkUI';
```

## Rect

Describes the region of the screen to capture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type  | Read-Only| Optional| Description                                                        |
| ------ | ------ | ---- | ----  | ------------------------------------------------------------ |
| left   | number | No  | No   | Left boundary of the screen region to capture, in px. The value must be an integer.|
| top    | number | No  | No   | Top boundary of the screen region to capture, in px. The value must be an integer.|
| width  | number | No  | No   | Width of the screen region to capture, in px. The value must be an integer.|
| height | number | No  | No   | Height of the screen region to capture, in px. The value must be an integer.|

## CaptureOption<sup>14+</sup>

Describes the capture options.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type  | Read-Only| Optional| Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| displayId | number |  No  | Yes| ID of the [display](js-apis-display.md#display) to capture. The default value is **0**. The value must be an integer greater than or equal to 0. If a non-integer is passed, a parameter error is reported.|

## PickInfo

Describes the screenshot options.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                | Type         | Read-Only| Optional| Description                                                        |
| -------------------- | ------------- | ---- | ---- | ------------------------------------------------------------ |
| pickRect             | [Rect](#rect) | No  | No  | Region of the screen to capture.                      |
| pixelMap             | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)  | No  | No  | PixelMap object of the captured image.|

## screenshot.pick

pick(): Promise&lt;PickInfo&gt;

Takes a screenshot. Currently, this API only supports taking screenshots of the screen with displayId 0. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: This API can be properly called on 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Return value**

| Type                         | Description                                           |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[PickInfo](#pickinfo)&gt; | Promise used to return the PickInfo object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 801 | Capability not supported on this device. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = screenshot.pick();
  promise.then((pickInfo: screenshot.PickInfo) => {
    console.log('pick Pixel bytes number: ' + pickInfo.pixelMap.getPixelBytesNumber());
    console.log('pick Rect: ' + pickInfo.pickRect);
    pickInfo.pixelMap.release(); // Release the memory in time after the PixelMap is no longer needed.
  }).catch((err: BusinessError) => {
    console.log(`Failed to pick. Code: ' + Code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to pick Code: ' + Code: ${exception.code}, message: ${exception.message}`);
};
```

## screenshot.capture<sup>14+</sup>

capture(options?: CaptureOption): Promise&lt;image.PixelMap&gt;

Takes a screenshot of the entire screen. This API uses a promise to return the result.

This API allows you to take screenshots of different screens by setting various **displayId** values, but only full-screen captures are supported. The [pick](#screenshotpick) API allows you to take screenshots of a specified region.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Required permissions**: ohos.permission.CUSTOM_SCREEN_CAPTURE

**Parameters**

| Name | Type                                   | Mandatory| Description                                                        |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [CaptureOption](#captureoption14) | No|  Capture options. The value can contain the display ID. If this parameter is left blank, the display with ID 0 is captured by default.|

**Return value**

| Type                         | Description                                           |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise used to return a PixelMap object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801 | Capability not supported on this device.|
| 1400003 | This display manager service works abnormally.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let captureOption: screenshot.CaptureOption = {
  "displayId": 0
};
try {
  let promise = screenshot.capture(captureOption);
  promise.then((pixelMap: image.PixelMap) => {
    console.log('Succeeded in saving screenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
    pixelMap.release(); // Release the memory in time after the PixelMap is used.
  }).catch((err: BusinessError) => {
    console.error(`Failed to save screenshot. Code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to save screenshot. Code: ${exception.code}, message: ${exception.message}`);
};

```