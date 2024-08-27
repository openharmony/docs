# @ohos.screenshot (Screenshot)

The **Screenshot** module provides the screen capture capability.

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

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| left   | number | Yes  | Left boundary of the screen region to capture, in px. The value must be an integer.|
| top    | number | Yes  | Top boundary of the screen region to capture, in px. The value must be an integer.|
| width  | number | Yes  | Width of the screen region to capture, in px. The value must be an integer.|
| height | number | Yes  | Height of the screen region to capture, in px. The value must be an integer.|

## PickInfo

Describes the screenshot options.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core


| Name                | Type         | Mandatory| Description                                                        |
| -------------------- | ------------- | ---- | ------------------------------------------------------------ |
| pickRect             | [Rect](#rect) | Yes  | Region of the screen to capture.                      |
| pixelMap             | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)  | Yes  | **PixelMap** object of the captured image.|

## screenshot.pick

pick(): Promise&lt;PickInfo&gt;

Takes a screenshot. This API can be used only on 2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                         | Description                                           |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[PickInfo](#pickinfo)&gt; | Promise used to return the **PickInfo** object.|

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
    console.log('Failed to pick. Code: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to pick Code: ' + JSON.stringify(exception));
};
```
