# Display
The **Display** module provides APIs for managing displays, such as obtaining information about the default display, obtaining information about all displays, and listening for the addition and removal of displays.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
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

## Rect<sup>9+</sup>

Describes a rectangle on the display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Readable| Writable| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | Yes  | Yes  | Left boundary of the rectangle.|
| top    | number   | Yes  | Yes  | Top boundary of the rectangle.|
| width  | number   | Yes  | Yes  | Width of the rectangle.  |
| height | number   | Yes  | Yes  | Height of the rectangle.  |

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

```js
let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();
} catch (exception) {
    console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
};
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

```js
let displayClass = null;
display.getAllDisplays((err, data) => {
    displayClass = data;
    if (err.code) {
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

```js
let displayClass = null;
let promise = display.getAllDisplays();
promise.then((data) => {
    displayClass = data;
    console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err) => {
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
| id     | number                    | Yes  | ID of the display.|

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

```js
let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();
} catch (exception) {
    console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
    return;
};

let ret = undefined;
try {
    ret = display.hasPrivateWindow(displayClass.id);
} catch (exception) {
    console.error('Failed to check has privateWindow or not. Code: ' + JSON.stringify(exception));
};
if (ret == undefined) {
  console.log("Failed to check has privateWindow or not.");
}
if (ret) {
  console.log("There has privateWindow.");
} else if (!ret) {
  console.log("There has no privateWindow.");
};
```

## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

Subscribes to display changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **add**, indicating the display addition event. Example: event indicating that a display is connected to a PC.<br>- **remove**, indicating the display removal event. Example: event that a display is disconnected from a PC.<br>- **change**, indicating the display change event. Example: event that the display orientation is changed.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the ID of the display.|

**Example**

```js
let callback = (data) => {
    console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
    display.on("add", callback);
} catch (exception) {
    console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
};
```

## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

Unsubscribes from display changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **add**, indicating the display addition event. Example: event indicating that a display is connected to a PC.<br>- **remove**, indicating the display removal event. Example: event that a display is disconnected from a PC.<br>- **change**, indicating the display change event. Example: event that the display orientation is changed.|
| callback | Callback&lt;number&gt; | No| Callback used to return the ID of the display.|

**Example**

```js
try {
    display.off("remove");
} catch (exception) {
    console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
};
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

```js
let displayClass = null;
display.getDefaultDisplay((err, data) => {
    if (err.code) {
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

```js
let displayClass = null;
let promise = display.getDefaultDisplay();
promise.then((data) => {
    displayClass = data;
    console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
}).catch((err) => {
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

```js
display.getAllDisplay((err, data) => {
    if (err.code) {
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

```js
let promise = display.getAllDisplay();
promise.then((data) => {
    console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
});
```

## Display
Implements a **Display** instance, with properties and APIs defined.

Before calling any API in **Display**, you must use [getAllDisplays()](#displaygetalldisplays9) or [getDefaultDisplaySync()](#displaygetdefaultdisplaysync9) to obtain a **Display** instance.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | number | Yes| No| ID of the display.|
| name | string | Yes| No| Name of the display.|
| alive | boolean | Yes| No| Whether the display is alive.|
| state | [DisplayState](#displaystate) | Yes| No| State of the display.|
| refreshRate | number | Yes| No| Refresh rate of the display.|
| rotation | number | Yes| No| Screen rotation angle of the display.<br>The value **0** indicates that the screen of the display rotates by 0°.<br>The value **1** indicates that the screen of the display rotates by 90°.<br>The value **2** indicates that the screen of the display rotates by 180°.<br>The value **3** indicates that the screen of the display rotates by 270°.|
| width | number | Yes| No| Width of the display, in pixels.|
| height | number | Yes| No| Height of the display, in pixels.|
| densityDPI | number | Yes| No| Screen density of the display, in DPI.|
| densityPixels | number | Yes| No| Screen density of the display, in pixels.|
| scaledDensity | number | Yes| No| Scaling factor for fonts displayed on the display.|
| xDPI | number | Yes| No| Exact physical dots per inch of the screen in the horizontal direction.|
| yDPI | number | Yes| No| Exact physical dots per inch of the screen in the vertical direction.|

### getCutoutInfo<sup>9+</sup>
getCutoutInfo(callback: AsyncCallback&lt;CutoutInfo&gt;): void

Obtains the cutout information of the display. This API uses an asynchronous callback to return the result. You are advised not to use the cutout area during application layout.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;[CutoutInfo](#cutoutinfo9)&gt;   | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the **CutoutInfo** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();
} catch (exception) {
    console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
};

displayClass.getCutoutInfo((err, data) => {
    if (err.code) {
        console.error('Failed to get cutoutInfo. Code: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in getting cutoutInfo. data: ' + JSON.stringify(data));
});
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

```js
let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();
} catch (exception) {
    console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
};

let promise = displayClass.getCutoutInfo();
promise.then((data) => {
    console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(data));
});
```
