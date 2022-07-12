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


## Display

Describes the attributes of a display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | number | Yes| No| ID of the display.|
| name | string | Yes| No| Name of the display.|
| alive | boolean | Yes| No| Whether the display is alive.|
| state | [DisplayState](#displaystate) | Yes| No| State of the display.|
| refreshRate | number | Yes| No| Refresh rate of the display.|
| rotation | number | Yes| No| Screen rotation angle of the display.|
| width | number | Yes| No| Width of the display, in pixels.|
| height | number | Yes| No| Height of the display, in pixels.|
| densityDPI | number | Yes| No| Screen density of the display, in DPI.|
| densityPixels | number | Yes| No| Screen density of the display, in pixels.|
| scaledDensity | number | Yes| No| Scaling factor for fonts displayed on the display.|
| xDPI | number | Yes| No| Exact physical dots per inch of the screen in the horizontal direction.|
| yDPI | number | Yes| No| Exact physical dots per inch of the screen in the vertical direction.|


## display.getDefaultDisplay

getDefaultDisplay(callback: AsyncCallback&lt;Display&gt;): void

Obtains the default display object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Display](#display)&gt; | Yes| Callback used to return the default display object.|

**Example**
  ```js
  var displayClass = null;
  display.getDefaultDisplay((err, data) => {
      if (err.code) {
          console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
      displayClass = data;
  });
  ```

## display.getDefaultDisplay

getDefaultDisplay(): Promise&lt;Display&gt;

Obtains the default display object. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

  | Type                              | Description                                          |
  | ---------------------------------- | ---------------------------------------------- |
  | Promise&lt;[Display](#display)&gt; | Promise used to return the default display object.|

**Example**

  ```js
  let promise = display.getDefaultDisplay();
  promise.then(() => {
      console.log('getDefaultDisplay success');
  }).catch((err) => {
      console.log('getDefaultDisplay fail: ' + JSON.stringify(err));
  });
  ```

## display.getDefaultDisplaySync<sup>9+</sup>

getDefaultDisplaySync(): Display

Obtains the default display object. This API returns the result synchronously.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                          | Description                                          |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | Default display object.|

**Example**

```js
var displayClass = display.getDefaultDisplaySync();
```

## display.getAllDisplay

getAllDisplay(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

Obtains all display objects. This API uses an asynchronous callback to return the result.

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
      console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data))
  });
  ```

## display.getAllDisplay

getAllDisplay(): Promise&lt;Array&lt;Display&gt;&gt;

Obtains all display objects. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

  | Type                                           | Description                                                   |
  | ----------------------------------------------- | ------------------------------------------------------- |
  | Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise used to return all the display objects.|

**Example**

  ```js
  let promise = display.getAllDisplay();
  promise.then(() => {
      console.log('getAllDisplay success');
  }).catch((err) => {
      console.log('getAllDisplay fail: ' + JSON.stringify(err));
  });
  ```

## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

Subscribes to display changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type.<br>- **add**, indicating the display addition event.<br>- **remove**, indicating the display removal event.<br>- **change**, indicating the display change event.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the ID of the display.|

**Example**
  ```js
  var callback = (data) => {
      console.info('Listening enabled. Data: ' + JSON.stringify(data))
  }
  display.on("add", callback);
  ```


## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

Unsubscribes from display changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type.<br>- **add**, indicating the display addition event.<br>- **remove**, indicating the display removal event.<br>- **change**, indicating the display change event.|
  | callback | Callback&lt;number&gt; | No| Callback used to return the ID of the display.|

**Example**
  ```js
  display.off("remove");
  ```
