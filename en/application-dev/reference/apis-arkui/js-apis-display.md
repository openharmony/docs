# @ohos.display (Display)

The Display module provides APIs for managing displays, such as obtaining information about the default display, obtaining information about all displays, and listening for the addition and removal of displays.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { display } from '@kit.ArkUI';
```

## DisplayState

Enumerates the states of a display.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| STATE_UNKNOWN | 0 | Unknown.|
| STATE_OFF | 1 | The display is shut down.|
| STATE_ON | 2 | The display is powered on.|
| STATE_DOZE | 3 | The display is in sleep mode.|
| STATE_DOZE_SUSPEND | 4 | The display is in sleep mode, and the CPU is suspended.|
| STATE_VR | 5 | The display is in VR mode.|
| STATE_ON_SUSPEND | 6 | The display is powered on, and the CPU is suspended.|

## Orientation<sup>10+</sup>

Enumerates the orientations of a display.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| PORTRAIT | 0 | The display is in portrait mode.|
| LANDSCAPE | 1 | The display is in landscape mode.|
| PORTRAIT_INVERTED | 2 | The display is in reverse portrait mode.|
| LANDSCAPE_INVERTED | 3 | The display is in reverse landscape mode.|

## DisplaySourceMode<sup>18+</sup>

Enumerates the display modes for screen content.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

| Name| Value| Description|
| -------- | -------- | -------- |
| NONE | 0 | The device is currently not in use.|
| MAIN | 1 | The primary screen of the device is currently in use.|
| MIRROR | 2 | The device is currently in mirror display mode.|
| EXTEND | 3 | The device is currently in extended display mode.|
| ALONE | 4 | The device is currently in independent display mode.|

## FoldStatus<sup>10+</sup>

Enumerates the fold statuses of a foldable device. For dual-fold axis devices, when oriented with the charging port at the bottom, the hinges are identified from right to left as the first and second fold axes, respectively.

**System capability**: SystemCapability.Window.SessionManager

| Name| Value| Description|
| -------- | -------- | -------- |
| FOLD_STATUS_UNKNOWN<sup>10+</sup> | 0 | The fold status of the device is unknown.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FOLD_STATUS_EXPANDED<sup>10+</sup> | 1 | The device is fully open. For dual-fold axis devices, the first fold axis is fully open, and the second fold axis is folded.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FOLD_STATUS_FOLDED<sup>10+</sup> | 2 | The device is folded (completely closed). For dual-fold axis devices, the first fold axis is folded, and the second fold axis is folded.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FOLD_STATUS_HALF_FOLDED<sup>10+</sup> | 3 | The device is half-folded, somehow between fully open and completely closed. For dual-fold axis devices, the first fold axis is half-folded, and the second fold axis is folded.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FOLD_STATUS_EXPANDED_WITH_SECOND_EXPANDED<sup>15+</sup> | 11 | For dual-fold axis devices, the first fold axis is fully open, and the second fold axis is fully open.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| FOLD_STATUS_EXPANDED_WITH_SECOND_HALF_FOLDED<sup>15+</sup> | 21 | For dual-fold axis devices, the first fold axis is fully open, and the second fold axis is half-folded.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| FOLD_STATUS_FOLDED_WITH_SECOND_EXPANDED<sup>15+</sup> | 12 | For dual-fold axis devices, the first fold axis is folded, and the second fold axis is fully open.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| FOLD_STATUS_FOLDED_WITH_SECOND_HALF_FOLDED<sup>15+</sup> | 22 | For dual-fold axis devices, the first fold axis is folded, and the second fold axis is fully folded.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| FOLD_STATUS_HALF_FOLDED_WITH_SECOND_EXPANDED<sup>15+</sup> | 13 | For dual-fold axis devices, the first fold axis is half-folded, and the second fold axis is fully open.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| FOLD_STATUS_HALF_FOLDED_WITH_SECOND_HALF_FOLDED<sup>15+</sup> | 23 | For dual-fold axis devices, the first fold axis is half-folded, and the second fold axis is half-folded.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|

>**NOTE**

> Devices with only one fold axis can be in the **FOLD_STATUS_EXPANDED**, **FOLD_STATUS_FOLDED**, or **FOLD_STATUS_HALF_FOLDED** state.

> Devices with two fold axes can be in any of the states provided in the table above, except for **FOLD_STATUS_UNKNOWN**, which indicates an unusable fold status.

## FoldDisplayMode<sup>10+</sup>

Enumerates the display modes of a foldable device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name| Value| Description|
| -------- | -------- | -------- |
| FOLD_DISPLAY_MODE_UNKNOWN | 0 | The display mode of the device is unknown.|
| FOLD_DISPLAY_MODE_FULL | 1 | The device is displayed in full screen.|
| FOLD_DISPLAY_MODE_MAIN | 2 | The primary screen of the device is displayed.|
| FOLD_DISPLAY_MODE_SUB | 3 | The secondary screen of the device is displayed.|
| FOLD_DISPLAY_MODE_COORDINATION | 4 | Both screens of the device are displayed in collaborative mode.|

>**NOTE**
>For foldable devices where both the inner and outer screens can serve as the primary screen, the inner screen's display mode is **FOLD_DISPLAY_MODE_FULL**, and the outer screen's display mode is **FOLD_DISPLAY_MODE_MAIN**.<br>
>
>For foldable devices where the outer screen serves only as an auxiliary display, the inner screen's display mode is **FOLD_DISPLAY_MODE_MAIN**, and the outer screen's display mode is **FOLD_DISPLAY_MODE_SUB**.

## FoldCreaseRegion<sup>10+</sup>

Defines the crease region of a foldable device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Readable| Writable| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| displayId   | number   | Yes  | No  | ID of the display where the crease is located.|
| creaseRects    | Array\<[Rect](#rect9)>   | Yes  | No  | Crease region.|

## Rect<sup>9+</sup>

Describes a rectangle on the display.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Readable| Writable| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | Yes  | Yes  | Left boundary of the rectangle, in px. The value must be an integer.|
| top    | number   | Yes  | Yes  | Top boundary of the rectangle, in px. The value must be an integer.|
| width  | number   | Yes  | Yes  | Width of the rectangle, in px. The value must be an integer.  |
| height | number   | Yes  | Yes  | Height of the rectangle, in px. The value must be an integer.  |

## WaterfallDisplayAreaRects<sup>9+</sup>

Describes the curved area on a waterfall display.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type     | Readable| Writable| Description              |
| ------ | ------------- | ---- | ---- | ------------------ |
| left   | [Rect](#rect9) | Yes  | No  | Rectangle of the curved area on the left of the waterfall display.|
| top    | [Rect](#rect9) | Yes  | No  | Rectangle of the curved area on the top of the waterfall display.|
| right  | [Rect](#rect9) | Yes  | No  | Rectangle of the curved area on the right of the waterfall display.|
| bottom | [Rect](#rect9) | Yes  | No  | Rectangle of the curved area at the bottom of the waterfall display.|

## CutoutInfo<sup>9+</sup>

Describes the unusable area of a display, including punch hole, notch, and curved area of a waterfall display.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                       | Type     | Readable| Writable| Description              |
| --------------------------- | ------------- | ---- | ---- | ------------------ |
| boundingRects                | Array\<[Rect](#rect9)> | Yes  | No  | Unusable areas (bounding rectangles) designed for punch holes and notches. If there are no punch holes or notches, an empty array is returned.|
| waterfallDisplayAreaRects   | [WaterfallDisplayAreaRects](#waterfalldisplayarearects9) | Yes| No| Curved area on a waterfall display.|

## DisplayPhysicalResolution<sup>12+</sup>
Describes the display mode of a foldable device and the corresponding physical screen resolution information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                       | Type     | Read-Only| Optional| Description              |
| --------------------------- | ------------- | ---- | ---- | ------------------ |
| foldDisplayMode             | [FoldDisplayMode](#folddisplaymode10) | Yes  | No  | Display mode of the foldable device.|
| physicalWidth   | number | Yes| No| Width of the foldable device, in px. The value must be an integer greater than 0.|
| physicalHeight  | number | Yes| No| Height of the foldable device, in px. The value must be an integer greater than 0.|

## ScreenShape<sup>18+</sup>

Enumerates the screen shapes of a display.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| RECTANGLE | 0 | The screen is in the shape of a rectangle.|
| ROUND | 1 | The screen is in the shape of a circle.|

## display.getDisplayByIdSync<sup>12+</sup>

getDisplayByIdSync(displayId: number): Display

Obtains a **Display** object based on the display ID.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- |----------|
| displayId     | number                    | Yes  | Display ID. The value must be an integer greater than or equal to 0. An object can be obtained only when the passed-in display ID is correct. You can use the value of the **displayId** property in [WindowProperties](js-apis-window.md#windowproperties) as the input parameter.|

**Return value**

| Type                          | Description                                          |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | **Display** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types. 3. Parameter verification failed.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;

try {
  // Use the value of the displayId property in WindowProperties as the input parameter.
  let displayId = 0; 
  displayClass = display.getDisplayByIdSync(displayId);
} catch (exception) {
  console.error(`Failed to get display. Code: ${exception.code}, message: ${exception.message}`);
}
```

## display.getAllDisplayPhysicalResolution<sup>12+</sup>

getAllDisplayPhysicalResolution(): Promise&lt;Array&lt;DisplayPhysicalResolution&gt;&gt;

Obtains the display mode of the current foldable device and the corresponding physical screen resolution information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[DisplayPhysicalResolution](#displayphysicalresolution12)&gt;&gt; | Promise used to return all the **DisplayPhysicalResolution** objects.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let promise = display.getAllDisplayPhysicalResolution();
promise.then((resolutionObjects) => {
  console.info('Obtaining physical resolution length: ' + resolutionObjects.length);
  for (let i = 0; i < resolutionObjects.length; i++) {
     console.info(`resolutionObjects[${i}].foldDisplayMode: ${resolutionObjects[i].foldDisplayMode}`);
     console.info(`resolutionObjects[${i}].physicalWidth: ${resolutionObjects[i].physicalWidth}`); 
     console.info(`resolutionObjects[${i}].physicalHeight: ${resolutionObjects[i].physicalHeight}`); 
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain physical resolution. Code: ${err.code}, message: ${err.message}`);
});
```

## display.getDefaultDisplaySync<sup>9+</sup>

getDefaultDisplaySync(): Display

Obtains the default display object. This API returns the result synchronously.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                          | Description                                          |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | Default display object.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;

displayClass = display.getDefaultDisplaySync();
```

## display.getPrimaryDisplaySync<sup>14+</sup>

getPrimaryDisplaySync(): Display

Obtains the information about the primary display. For devices other than 2-in-1 devices, the **Display** object obtained is the built-in screen. For 2-in-1 devices with an external screen, the **Display** object obtained is the primary screen. For 2-in-1 devices without an external screen, the Display object obtained is the built-in screen.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 14.

**Return value**

| Type                          | Description                                          |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | **Display** object of the primary screen.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;

displayClass = display.getPrimaryDisplaySync();
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

Obtains all display objects. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Display](#display)&gt;&gt; | Yes| Callback used to return all the display objects.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: Array<display.Display> = [];
display.getAllDisplays((err: BusinessError, data: Array<display.Display>) => {
  displayClass = data;
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
});
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(): Promise&lt;Array&lt;Display&gt;&gt;

Obtains all display objects. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise used to return all the display objects.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: Array<display.Display> =[];
let promise: Promise<Array<display.Display>> = display.getAllDisplays();
promise.then((data: Array<display.Display>) => {
  displayClass = data;
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
});
```

## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

Subscribes to display changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description                                                                                                                             |
| -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------------------------|
| type | string | Yes| Event type.<br>- **add**, indicating the display addition event. Example: event that a display is connected.<br>- **remove**, indicating the display removal event. Example: event that a display is disconnected.<br>- **change**, indicating the display change event. Example: event that the display orientation is changed.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the ID of the display, which is an integer.                                                                                                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<number> = (data: number) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};

display.on("add", callback);
```

## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

Unsubscribes from display changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **add**, indicating the display addition event. Example: event that a display is connected.<br>- **remove**, indicating the display removal event. Example: event that a display is disconnected.<br>- **change**, indicating the display change event. Example: event that the display orientation is changed.|
| callback | Callback&lt;number&gt; | No| Callback used to return the ID of the display, which is an integer. If this parameter is not specified, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts

// Unregister all the callbacks that have been registered through on().
display.off("remove");

let callback: Callback<number> = (data: number) => {
  console.info('Succeeded in unregistering the callback for display remove. Data: ' + JSON.stringify(data))
};
// Unregister the specified callback.
display.off('remove', callback);
```

## display.isFoldable<sup>10+</sup>
isFoldable(): boolean

Checks whether the current device is foldable.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| boolean | Returns **true** if the device is foldable, and returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let ret: boolean = false;
ret = display.isFoldable();
```

## display.getFoldStatus<sup>10+</sup>
getFoldStatus(): FoldStatus

Obtains the fold status of the foldable device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldStatus](#foldstatus10) | Fold status of the device.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let data: display.FoldStatus = display.getFoldStatus();
console.info('Succeeded in obtaining fold status. Data: ' + JSON.stringify(data));
```

## display.getFoldDisplayMode<sup>10+</sup>
getFoldDisplayMode(): FoldDisplayMode

Obtains the display mode of the foldable device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldDisplayMode](#folddisplaymode10) | Display mode of the device.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let data: display.FoldDisplayMode = display.getFoldDisplayMode();
console.info('Succeeded in obtaining fold display mode. Data: ' + JSON.stringify(data));
```

## display.getCurrentFoldCreaseRegion<sup>10+</sup>
getCurrentFoldCreaseRegion(): FoldCreaseRegion

Obtains the crease region of the foldable device in the current display mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldCreaseRegion](#foldcreaseregion10) | Crease region of the device.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let data: display.FoldCreaseRegion = display.getCurrentFoldCreaseRegion();
console.info('Succeeded in obtaining current fold crease region. Data: ' + JSON.stringify(data));
```

## display.on('foldStatusChange')<sup>10+</sup>

on(type: 'foldStatusChange', callback: Callback&lt;FoldStatus&gt;): void

Subscribes to fold status change events of the foldable device.

Note that [display.on('foldDisplayModeChange')](#displayonfolddisplaymodechange10) subscribes to display mode change events of the foldable device.

The two are different. In terms of time sequence, the fold status changes first, and the bottom layer matches the display mode status based on the fold status.

To check whether the content is displayed on the inner or outer screen of the foldable device, use [display.on('foldDisplayModeChange')](#displayonfolddisplaymodechange10).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldStatusChange'** is triggered when the fold status of the device changes.|
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | Yes  | Callback used to return the fold status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';

/**
 * The callback parameter used for subscription must be passed as an object.
 * If an anonymous function is used for registration, a new underlying object is created each time the function is called, causing memory leakage.
*/
let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
display.on('foldStatusChange', callback);
```

## display.off('foldStatusChange')<sup>10+</sup>

off(type: 'foldStatusChange', callback?: Callback&lt;FoldStatus&gt;): void

Unsubscribes from fold status change events of the foldable device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldStatusChange'** is triggered when the fold status of the device changes.|
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | No  | Callback used to return the fold status. If this parameter is not specified, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts

// Unregister all the callbacks that have been registered through on().
display.off('foldStatusChange');

let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
  console.info('unregistering FoldStatus changes callback. Data: ' + JSON.stringify(data));
};
// Unregister the specified callback.
display.off('foldStatusChange', callback);
```

## display.on('foldAngleChange')<sup>12+</sup>

on(type: 'foldAngleChange', callback: Callback&lt;Array&lt;number&gt;&gt;): void

Subscribes to folding angle change events of the foldable device. Note that there are two folding angles for dual-fold axis devices. When oriented with the charging port at the bottom, the hinges are identified from right to left as the first and second fold axes, respectively.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes| Event type. The event **'foldAngleChange'** is triggered when the folding angle of the device changes.|
| callback | Callback&lt;Array&lt;number&gt;&gt; | Yes| Callback used to return the folding angle (0–180 degrees). For dual-fold axis devices, the array contains two angles. The first value represents the folding angle of the first fold axis, while the second value represents the folding angle of the second fold axis.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<Array<number>> = (angles: Array<number>) => {
  console.info('Listening fold angles length: ' + angles.length);
};
display.on('foldAngleChange', callback);
```

## display.off('foldAngleChange')<sup>12+</sup>

off(type: 'foldAngleChange', callback?: Callback&lt;Array&lt;number&gt;&gt;): void

Unsubscribes from folding angle change events of the foldable device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |-------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                    | Yes | Event type. The event **'foldAngleChange'** is triggered when the folding angle of the device changes.|
| callback | Callback&lt;Array&lt;number&gt;&gt; | No | Callback used to return the folding angle (0–180 degrees). If this parameter is not specified, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
display.off('foldAngleChange');
```

## display.on('captureStatusChange')<sup>12+</sup>

on(type: 'captureStatusChange', callback: Callback&lt;boolean&gt;): void

Subscribes to screen capture, casting, or recording status changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |-------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes| Event type. The event **'captureStatusChange'** is triggered when the screen capture, casting, or recording status changes.|
| callback | Callback&lt;boolean&gt; | Yes| Callback used to return the screen capture, casting, or recording status change. The value **true** means that the device starts screen capture, casting, or recording, and **false** means that the device stops screen capture, casting, or recording.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<boolean> = (captureStatus: boolean) => {
  console.info('Listening capture status: ' + captureStatus);
};
display.on('captureStatusChange', callback);
```

## display.off('captureStatusChange')<sup>12+</sup>

off(type: 'captureStatusChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from screen capture, casting, or recording status changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |-------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes| Event type. The event **'captureStatusChange'** is triggered when the screen capture, casting, or recording status changes.|
| callback | Callback&lt;boolean&gt; | No| Callback used to return the screen capture, casting, or recording status change. The value **true** means that the device starts screen capture, casting, or recording, and **false** means that the device stops screen capture, casting, or recording. If this parameter is not specified, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
display.off('captureStatusChange');
```

## display.isCaptured<sup>12+</sup>
isCaptured(): boolean

Checks whether the display is being captured, projected, or recorded.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| boolean | **true**: The display is being captured, projected, or recorded.<br> **false**: The display is not being captured, projected, or recorded.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let ret: boolean = false;
ret = display.isCaptured();
```

## display.on('foldDisplayModeChange')<sup>10+</sup>

on(type: 'foldDisplayModeChange', callback: Callback&lt;FoldDisplayMode&gt;): void

Subscribes to display mode change events of the foldable device.

Subscribes to display mode change events of the foldable device. Note that [display.on('foldStatusChange')](#displayonfoldstatuschange10) subscribes to fold status change events of the foldable device. 

The two are different. In terms of time sequence, the fold status changes first, and the bottom layer matches the display mode status based on the fold status.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldDisplayModeChange'** is triggered when the display mode of the device changes.|
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | Yes  | Callback used to return the display mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';

/**
 * The callback parameter used for subscription must be passed as an object.
 * If an anonymous function is used for registration, a new underlying object is created each time the function is called, causing memory leakage.
*/
let callback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
}; 
display.on('foldDisplayModeChange', callback);
```

## display.off('foldDisplayModeChange')<sup>10+</sup>

off(type: 'foldDisplayModeChange', callback?: Callback&lt;FoldDisplayMode&gt;): void

Unsubscribes from display mode change events of the foldable device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldDisplayModeChange'** is triggered when the display mode of the device changes.|
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | No  | Callback used to return the display mode. If this parameter is not specified, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts

// Unregister all the callbacks that have been registered through on().
display.off('foldDisplayModeChange');

let callback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {
  console.info('unregistering FoldDisplayMode changes callback. Data: ' + JSON.stringify(data));
};
// Unregister the specified callback.
display.off('foldDisplayModeChange', callback);
```


## display.getDefaultDisplay<sup>(deprecated)</sup>

getDefaultDisplay(callback: AsyncCallback&lt;Display&gt;): void

Obtains the default display object. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getDefaultDisplaySync()](#displaygetdefaultdisplaysync9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[Display](#display)&gt; | Yes| Callback used to return the default display object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
display.getDefaultDisplay((err: BusinessError, data: display.Display) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the default display object. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
  displayClass = data;
});
```

## display.getDefaultDisplay<sup>(deprecated)</sup>

getDefaultDisplay(): Promise&lt;Display&gt;

Obtains the default display object. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getDefaultDisplaySync()](#displaygetdefaultdisplaysync9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                              | Description                                          |
| ---------------------------------- | ---------------------------------------------- |
| Promise&lt;[Display](#display)&gt; | Promise used to return the default display object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
let promise: Promise<display.Display> = display.getDefaultDisplay();
promise.then((data: display.Display) => {
  displayClass = data;
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the default display object. Code: ${err.code}, message: ${err.message}`);
});
```

## display.getAllDisplay<sup>(deprecated)</sup>

getAllDisplay(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

Obtains all display objects. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getAllDisplays()](#displaygetalldisplays9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                | Mandatory| Description                           |
| -------- | ---------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Display](#display)&gt;&gt; | Yes  | Callback used to return all the display objects.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

display.getAllDisplay((err: BusinessError, data: Array<display.Display>) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
});
```

## display.getAllDisplay<sup>(deprecated)</sup>

getAllDisplay(): Promise&lt;Array&lt;Display&gt;&gt;

Obtains all display objects. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getAllDisplays()](#displaygetalldisplays9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                           | Description                                                   |
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise used to return all the display objects.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise: Promise<Array<display.Display>> = display.getAllDisplay();
promise.then((data: Array<display.Display>) => {
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
});
```

## Display
Implements a **Display** instance, with properties and APIs defined.

Before calling any API in **Display**, you must use [getAllDisplays()](#displaygetalldisplays9) or [getDefaultDisplaySync()](#displaygetdefaultdisplaysync9) to obtain a **Display** instance.

### Properties

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Read-Only| Optional| Description                                                                                                           |
| -------- | -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------|
| id | number | Yes| No| ID of the display. The value must be an integer.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                            |
| name | string | Yes| No| Name of the display.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                     |
| alive | boolean | Yes| No| Whether the display is alive.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                    |
| state | [DisplayState](#displaystate) | Yes| No| State of the display.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                     |
| refreshRate | number | Yes| No| Refresh rate of the display, in hz. The value must be an integer.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                            |
| rotation | number | Yes| No| Clockwise rotation angle of the display.<br>The value **0** indicates that the display rotates clockwise by 0°.<br>The value **1** indicates that the display rotates clockwise by 90°.<br>The value **2** indicates that the display rotates clockwise by 180°.<br>The value **3** indicates that the display rotates clockwise by 270°.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| width | number | Yes| No| Width of the display, in px. The value must be an integer.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                       |
| height | number | Yes| No| Height of the display, in px. The value must be an integer.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                       |
| densityDPI | number | Yes| No| Physical pixel density of the display, that is, the number of pixels per inch. The value is a floating point number, in px. Generally, the value is **160.0** or **480.0**. The actual value depends on the optional values provided by the device in use.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                  |
| orientation<sup>10+</sup> | [Orientation](#orientation10) | Yes| No| Orientation of the display.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                 |
| densityPixels | number | Yes| No| Logical pixel density of the display, which is the scaling coefficient between physical pixels and logical pixels. The calculation method is as follows:<br>![densityPixels](figures/densityPixels.jpg)<br>The value is a floating point number and is restricted by the range of **densityDPI**. The value range is [0.5, 4.0]. Generally, the value is **1.0** or **3.0**. The actual value depends on the density DPI provided by the device in use.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                 |
| scaledDensity | number | Yes| No| Scaling factor for fonts displayed on the display. The value must be a floating point number. Generally, the value is the same as that of **densityPixels**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                   |
| xDPI | number | Yes| No| Exact physical pixels per inch of the display in the X dimension. The value must be a floating point number.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                   |
| yDPI | number | Yes| No| Exact physical pixels per inch of the display in the Y dimension. The value must be a floating point number.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                   |
| colorSpaces<sup>11+</sup> | Array<[colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md)> | Yes| No| All color spaces supported by the display.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                               |
| hdrFormats<sup>11+</sup> | Array<[hdrCapability.HDRFormat](../apis-arkgraphics2d/js-apis-hdrCapability.md)> | Yes| No| All HDR formats supported by the display.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                              |
| availableWidth<sup>12+</sup> | number | Yes| No| Width of the available area on a 2-in-1 device, in px. The value is an integer greater than 0.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                   |
| availableHeight<sup>12+</sup> | number | Yes| No| Height of the available area on a 2-in-1 device, in px. The value is an integer greater than 0.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                   |
| screenShape<sup>18+</sup> | [ScreenShape](#screenshape18) | Yes| Yes| Screen shape of the display. The default value is **RECTANGLE**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.
| sourceMode<sup>18+</sup> | [DisplaySourceMode](#displaysourcemode18) | Yes| Yes| Display mode for screen content.<br>**System capability**: SystemCapability.Window.SessionManager<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                   |
| x<sup>18+</sup> | number | Yes| Yes| X coordinate of the upper left corner of the screen relative to the origin, which is the upper left corner of the primary screen, measured in px. The value is an integer.<br>**System capability**: SystemCapability.Window.SessionManager<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                   |
| y<sup>18+</sup> | number | Yes| Yes| Y coordinate of the upper left corner of the screen relative to the origin, which is the upper left corner of the primary screen, measured in px. The value is an integer.<br>**System capability**: SystemCapability.Window.SessionManager<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                   |


### getCutoutInfo<sup>9+</sup>
getCutoutInfo(callback: AsyncCallback&lt;CutoutInfo&gt;): void

Obtains the cutout information of the display. This API uses an asynchronous callback to return the result. You are advised not to use the cutout area during application layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;[CutoutInfo](#cutoutinfo9)&gt;   | Yes  | Callback used to return the **CutoutInfo** object.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();

displayClass.getCutoutInfo((err: BusinessError, data: display.CutoutInfo) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get cutoutInfo. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in getting cutoutInfo. data: ' + JSON.stringify(data));
});
```
### getCutoutInfo<sup>9+</sup>
getCutoutInfo(): Promise&lt;CutoutInfo&gt;

Obtains the cutout information of the display. This API uses a promise to return the result. You are advised not to use the cutout area during application layout.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[CutoutInfo](#cutoutinfo9)&gt; | Promise used to return the **CutoutInfo** object.|

**Error codes**

For details about the error codes, see [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
let promise: Promise<display.CutoutInfo> = displayClass.getCutoutInfo();
promise.then((data: display.CutoutInfo) => {
  console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
});
```

### getAvailableArea<sup>12+</sup>
getAvailableArea(): Promise&lt;Rect&gt;

Obtains the available area of the display of the current device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[Rect](#rect9)&gt; | Promise used to return the available area, which is a rectangle.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  let promise = displayClass.getAvailableArea();
  promise.then((data) => {
    console.info('Succeeded get the available area in this display. data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get the available area in this display. Code: ${err.code}, message: ${err.message}`);
  })
} catch (exception) {
  console.error(`Failed to obtain the default display object. Code: ${exception.code}, message: ${exception.message}`);
}
```

### on('availableAreaChange')<sup>12+</sup>
on(type: 'availableAreaChange', callback: Callback&lt;Rect&gt;): void

Subscribes to changes of the available area on the display of the current device. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'availableAreaChange'** is triggered when the available area of the display changes.|
| callback | Callback&lt;[Rect](#rect9)&gt; | Yes  | Callback used to return the new available area.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let callback: Callback<display.Rect> = (data: display.Rect) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  displayClass.on("availableAreaChange", callback);
} catch (exception) {
  console.error(`Failed to register callback. Code: ${exception.code}, message: ${exception.message}`);
}
```

### off('availableAreaChange')<sup>12+</sup>

off(type: 'availableAreaChange', callback?: Callback&lt;Rect&gt;): void

Unsubscribes from changes of the available area on the display of the current device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'availableAreaChange'** is triggered when the available area of the display changes.|
| callback | Callback&lt;[Rect](#rect9)&gt; | No  | Callback used to return the new available area. If this parameter is not specified, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let callback: Callback<display.Rect> = (data: display.Rect) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  displayClass.off("availableAreaChange", callback);
} catch (exception) {
  console.error(`Failed to unregister callback. Code: ${exception.code}, message: ${exception.message}`);
}
```
