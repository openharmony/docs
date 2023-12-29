# @ohos.display (Display)

The **Display** module provides APIs for managing displays, such as obtaining information about the default display, obtaining information about all displays, and listening for the addition and removal of displays.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import display from '@ohos.display';
```

## DisplayState

Enumerates the display states.

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

Enumerates the orientations of the display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| PORTRAIT | 0 | The display is in portrait mode.|
| LANDSCAPE | 1 | The display is in landscape mode.|
| PORTRAIT_INVERTED | 2 | The display is in reverse portrait mode.|
| LANDSCAPE_INVERTED | 3 | The display is in reverse landscape mode.|

## FoldStatus<sup>10+</sup>

Enumerates the folding statuses of a foldable device.

**System capability**: SystemCapability.Window.SessionManager

| Name| Value| Description|
| -------- | -------- | -------- |
| FOLD_STATUS_UNKNOWN | 0 | The folding status of the device is unknown.|
| FOLD_STATUS_EXPANDED | 1 | The device is fully open.|
| FOLD_STATUS_FOLDED | 2 | The device is folded (completely closed).|
| FOLD_STATUS_HALF_FOLDED | 3 | The device is half-folded, somehow between fully open and completely closed.|

## FoldDisplayMode<sup>10+</sup>

Enumerates the display modes of a foldable device.

**System capability**: SystemCapability.Window.SessionManager

| Name| Value| Description|
| -------- | -------- | -------- |
| FOLD_DISPLAY_MODE_UNKNOWN | 0 | The display mode of the device is unknown.|
| FOLD_DISPLAY_MODE_FULL | 1 | The device is displayed in full screen.|
| FOLD_DISPLAY_MODE_MAIN | 2 | The main screen of the device is displayed.|
| FOLD_DISPLAY_MODE_SUB | 3 | The subscreen of the device is displayed.|
| FOLD_DISPLAY_MODE_COORDINATION | 4 | Both screens of the device are displayed in collaborative mode.|

## FoldCreaseRegion<sup>10+</sup>

Defines the crease region of a foldable device.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Readable| Writable| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| displayId   | number   | Yes  | No  | ID of the screen where the crease is located.|
| creaseRects    | Array\<[Rect](#rect9)>   | Yes  | No  | Crease region.|

## Rect<sup>9+</sup>

Describes a rectangle on the display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Readable| Writable| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | Yes  | Yes  | Left boundary of the rectangle, in pixels. The value must be an integer.|
| top    | number   | Yes  | Yes  | Top boundary of the rectangle, in pixels. The value must be an integer.|
| width  | number   | Yes  | Yes  | Width of the rectangle, in pixels. The value must be an integer.  |
| height | number   | Yes  | Yes  | Height of the rectangle, in pixels. The value must be an integer.  |

## WaterfallDisplayAreaRects<sup>9+</sup>

Describes the curved area (an area that is not intended for displaying content) on the waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type     | Readable| Writable| Description              |
| ------ | ------------- | ---- | ---- | ------------------ |
| left   | [Rect](#rect9) | Yes  | No  | Bounding rectangle for the curved area, which is located on the left of the display surface.|
| top    | [Rect](#rect9) | Yes  | No  | Bounding rectangle for the curved area, which is located at the top of the display surface.|
| right  | [Rect](#rect9) | Yes  | No  | Bounding rectangle for the curved area, which is located on the right of the display surface.|
| bottom | [Rect](#rect9) | Yes  | No  | Bounding rectangle for the curved area, which is located at the bottom of the display surface.|

## CutoutInfo<sup>9+</sup>

Describes the cutout, which is an area that is not intended for displaying content on the display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                       | Type     | Readable| Writable| Description              |
| --------------------------- | ------------- | ---- | ---- | ------------------ |
| boundingRects                | Array\<[Rect](#rect9)> | Yes  | No  | Bounding rectangle for punch holes and notches.|
| waterfallDisplayAreaRects   | [WaterfallDisplayAreaRects](#waterfalldisplayarearects9) | Yes| No| Curved area on the waterfall display.|

## display.getDefaultDisplaySync<sup>9+</sup>

getDefaultDisplaySync(): Display

Obtains the default display object. This API returns the result synchronously.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                          | Description                                          |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | Default display object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import display from '@ohos.display';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

Obtains all display objects. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Display](#display)&gt;&gt; | Yes| Callback used to return all the display objects.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display';

let displayClass: Array<display.Display> = [];
display.getAllDisplays((err: BusinessError, data: Array<display.Display>) => {
  displayClass = data;
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
});
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(): Promise&lt;Array&lt;Display&gt;&gt;

Obtains all display objects. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise used to return all the display objects.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display';

let displayClass: Array<display.Display> =[];
let promise: Promise<Array<display.Display>> = display.getAllDisplays();
promise.then((data: Array<display.Display>) => {
  displayClass = data;
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
});
```

## display.hasPrivateWindow<sup>9+</sup>

hasPrivateWindow(displayId: number): boolean

Checks whether there is a visible privacy window on a display. The privacy window can be set by calling [setWindowPrivacyMode()](js-apis-window.md#setwindowprivacymode9). The content in the privacy window cannot be captured or recorded.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- |----------|
| id     | number                    | Yes  | ID of the display. The value must be an integer.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- |-----------------------------------------------------------------------|
|boolean | Whether there is a visible privacy window on the display.<br>The value **true** means that there is a visible privacy window on the display, and **false** means the opposite.<br>|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import display from '@ohos.display';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let ret: boolean = true;
  try {
    ret = display.hasPrivateWindow(displayClass.id);
  } catch (exception) {
    console.error('Failed to check has privateWindow or not. Code: ' + JSON.stringify(exception));
  }
  if (ret == undefined) {
    console.log("Failed to check has privateWindow or not.");
  }
  if (ret) {
    console.log("There has privateWindow.");
  } else if (!ret) {
    console.log("There has no privateWindow.");
  }
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

Subscribes to display changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description                                                                                                                             |
| -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------------------------|
| type | string | Yes| Event type.<br>- **add**, indicating the display addition event. Example: event that a display is connected.<br>- **remove**, indicating the display removal event. Example: event that a display is disconnected.<br>- **change**, indicating the display change event. Example: event that the display orientation is changed.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the ID of the display, which is an integer.                                                                                                    |

**Example**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<number> = (data: number) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on("add", callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

Unsubscribes from display changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **add**, indicating the display addition event. Example: event that a display is connected.<br>- **remove**, indicating the display removal event. Example: event that a display is disconnected.<br>- **change**, indicating the display change event. Example: event that the display orientation is changed.|
| callback | Callback&lt;number&gt; | No| Callback used to return the ID of the display, which is an integer.|

**Example**

```ts
try {
  display.off("remove");
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.on('privateModeChange')<sup>10+</sup>

on(type: 'privateModeChange', callback: Callback&lt;boolean&gt;): void

Subscribes to privacy mode changes of this display. When there is a privacy window in the foreground of the display, the display is in privacy mode, and the content in the privacy window cannot be captured or recorded.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The value is fixed at 'privateModeChange', indicating the event of display privacy mode changes.|
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return whether the privacy mode of the display is changed. The value **true** means that the display changes to the privacy mode, and **false** means the opposite.|

**Example**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<boolean> = (data: boolean) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on("privateModeChange", callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('privateModeChange')<sup>10+</sup>

off(type: 'privateModeChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from privacy mode changes of this display. When there is a privacy window in the foreground of the display, the display is in privacy mode, and the content in the privacy window cannot be captured or recorded.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The value is fixed at 'privateModeChange', indicating the event of display privacy mode changes.|
| callback | Callback&lt;boolean&gt; | No  | Callback used to return whether the privacy mode of the display is changed. The value **true** means that the display changes to the privacy mode, and **false** means the opposite.|

**Example**

```ts
try {
  display.off("privateModeChange");
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.isFoldable<sup>10+</sup>
isFoldable(): boolean

Checks whether the device is foldable.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| boolean | Returns **true** if the device is foldable, and returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import display from '@ohos.display';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let ret: boolean = false;
  try {
    ret = display.isFoldable();
  } catch (exception) {
    console.error('Failed to check is foldable or not. Code: ' + JSON.stringify(exception));
  }
  if (ret == undefined) {
    console.log("Failed to check is foldable or not.");
  }
  if (ret) {
    console.log("The device is foldable.");
  } else if (!ret) {
    console.log("The device is not foldable.");
  }
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## display.setFoldDisplayMode<sup>10+</sup>
setFoldDisplayMode(mode: FoldDisplayMode): void

Sets the display mode of the foldable device.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| mode     | [FoldDisplayMode](#folddisplaymode10)    | Yes  | Display mode.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import display from '@ohos.display';

try {
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_FULL;
  display.setFoldDisplayMode(mode);
} catch (exception) {
  console.error('Failed to change the fold display mode. Code: ' + JSON.stringify(exception));
}
```

## display.getFoldStatus<sup>10+</sup>
getFoldStatus(): FoldStatus

Obtains the folding status of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldStatus](#foldstatus10) | Folding status of the device.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import display from '@ohos.display';

try {
  display.getFoldStatus();
} catch (exception) {
  console.error('Failed to obtain the fold status. Code: ' + JSON.stringify(exception));
}
```

## display.getFoldDisplayMode<sup>10+</sup>
getFoldDisplayMode(): FoldDisplayMode

Obtains the display mode of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldDisplayMode](#folddisplaymode10) | Display mode of the device.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import display from '@ohos.display';

try {
  display.getFoldDisplayMode();
} catch (exception) {
  console.error('Failed to obtain the fold display mode. Code: ' + JSON.stringify(exception));
}
```

## display.getCurrentFoldCreaseRegion<sup>10+</sup>
getCurrentFoldCreaseRegion(): FoldCreaseRegion

Obtains the crease region of the foldable device in the current display mode.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type| Description|
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldCreaseRegion](#foldcreaseregion10) | Crease region of the device.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import display from '@ohos.display';

try {
  display.getCurrentFoldCreaseRegion();
} catch (exception) {
  console.error('Failed to obtain the current fold crease region. Code: ' + JSON.stringify(exception));
}
```

## display.on('foldStatusChange')<sup>10+</sup>

on(type: 'foldStatusChange', callback: Callback&lt;FoldStatus&gt;): void

Subscribes to folding status change events of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldStatusChange'** is triggered when the folding status of the device changes.|
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | Yes  | Callback used to return the folding status.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on('foldStatusChange', callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('foldStatusChange')<sup>10+</sup>

off(type: 'foldStatusChange', callback?: Callback&lt;FoldStatus&gt;): void

Unsubscribes from folding status change events of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldStatusChange'** is triggered when the folding status of the device changes.|
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | No  | Callback used to return the folding status.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
try {
  display.off('foldStatusChange');
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.on('foldDisplayModeChange')<sup>10+</sup>

on(type: 'foldDisplayModeChange', callback: Callback&lt;FoldDisplayMode&gt;): void

Subscribes to display mode change events of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldDisplayModeChange'** is triggered when the display mode of the device changes.|
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | Yes  | Callback used to return the display mode.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on('foldDisplayModeChange', callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('foldDisplayModeChange')<sup>10+</sup>

off(type: 'foldDisplayModeChange', callback?: Callback&lt;FoldDisplayMode&gt;): void

Unsubscribes from display mode change events of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The event **'foldDisplayModeChange'** is triggered when the display mode of the device changes.|
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | No  | Callback used to return the display mode.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
try {
  display.off('foldDisplayModeChange');
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
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
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
display.getDefaultDisplay((err: BusinessError, data: display.Display) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
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
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
let promise: Promise<display.Display> = display.getDefaultDisplay();
promise.then((data: display.Display) => {
  displayClass = data;
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
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
import { BusinessError } from '@ohos.base';

display.getAllDisplay((err: BusinessError, data: Array<display.Display>) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
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
import { BusinessError } from '@ohos.base';

let promise: Promise<Array<display.Display>> = display.getAllDisplay();
promise.then((data: Array<display.Display>) => {
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
});
```

## Display
Implements a **Display** instance, with properties and APIs defined.

Before calling any API in **Display**, you must use [getAllDisplays()](#displaygetalldisplays9) or [getDefaultDisplaySync()](#displaygetdefaultdisplaysync9) to obtain a **Display** instance.

### Attributes

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Readable| Writable| Description                                                                                                           |
| -------- | -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------|
| id | number | Yes| No| ID of the display. The value must be an integer.                                                                                            |
| name | string | Yes| No| Name of the display.                                                                                                     |
| alive | boolean | Yes| No| Whether the display is alive.                                                                                                    |
| state | [DisplayState](#displaystate) | Yes| No| State of the display.                                                                                                     |
| refreshRate | number | Yes| No| Refresh rate of the display. The value must be an integer.                                                                                            |
| rotation | number | Yes| No| Screen rotation angle of the display.<br>The value **0** indicates that the screen of the display rotates by 0°.<br>The value **1** indicates that the screen of the display rotates by 90°.<br>The value **2** indicates that the screen of the display rotates by 180°.<br>The value **3** indicates that the screen of the display rotates by 270°.|
| width | number | Yes| No| Width of the display, in pixels. The value must be an integer.                                                                                       |
| height | number | Yes| No| Height of the display, in pixels. The value must be an integer.                                                                                       |
| densityDPI | number | Yes| No| Screen density of the display, that is, the number of dots per inch. The value must be a floating point number. Generally, the value is **160.0** or **480.0**.                                                                  |
| orientation<sup>10+</sup> | [Orientation](#orientation10) | Yes| No| Orientation of the display.                                                                                                 |
| densityPixels | number | Yes| No| Logical density of the display, which is a scaling coefficient independent of the pixel unit. The value must be a floating point number. Generally, the value is **1.0** or **3.0**.                                                                 |
| scaledDensity | number | Yes| No| Scaling factor for fonts displayed on the display. The value must be a floating point number. Generally, the value is the same as that of **densityPixels**.                                                                   |
| xDPI | number | Yes| No| Exact physical dots per inch of the screen in the horizontal direction. The value must be a floating point number.                                                                                   |
| yDPI | number | Yes| No| Exact physical dots per inch of the screen in the vertical direction. The value must be a floating point number.                                                                                   |

### getCutoutInfo<sup>9+</sup>
getCutoutInfo(callback: AsyncCallback&lt;CutoutInfo&gt;): void

Obtains the cutout information of the display. This API uses an asynchronous callback to return the result. You are advised not to use the cutout area during application layout.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;[CutoutInfo](#cutoutinfo9)&gt;   | Yes  | Callback used to return the **CutoutInfo** object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  displayClass.getCutoutInfo((err: BusinessError, data: display.CutoutInfo) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to get cutoutInfo. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in getting cutoutInfo. data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```
### getCutoutInfo<sup>9+</sup>
getCutoutInfo(): Promise&lt;CutoutInfo&gt;

Obtains the cutout information of the display. This API uses a promise to return the result. You are advised not to use the cutout area during application layout.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[CutoutInfo](#cutoutinfo9)&gt; | Promise used to return the **CutoutInfo** object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let promise: Promise<display.CutoutInfo> = displayClass.getCutoutInfo();
  promise.then((data: display.CutoutInfo) => {
    console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```
### hasImmersiveWindow<sup>11+</sup>

hasImmersiveWindow(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this screen contains an immersive window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;boolean&gt;   | Yes  | Callback used to return the result. The value **true** means that the screen contains immersive windows, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display'

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}

try {
  displayClass.hasImmersiveWindow((err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(exception));
}
```
### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(): Promise&lt;boolean&gt;

Checks whether this screen contains an immersive window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the screen contains immersive windows, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display'

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}

let promise = displayClass.hasImmersiveWindow();
promise.then((data) => {
  console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(exception));
})
```
