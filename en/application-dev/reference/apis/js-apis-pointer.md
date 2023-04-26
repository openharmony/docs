# @ohos.multimodalInput.pointer (Mouse Pointer)

The **pointer** module provides APIs related to pointer attribute management.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import pointer from '@ohos.multimodalInput.pointer';
```

## pointer.setPointerVisible<sup>9+</sup>

setPointerVisible(visible: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the visible status of the mouse pointer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| visible  | boolean                   | Yes   | Whether the mouse pointer is visible.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

```js
try {
  pointer.setPointerVisible(true, (error) => {
    if (error) {
      console.log(`Set pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set pointer visible success`);
  });
} catch (error) {
  console.log(`Set pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerVisible<sup>9+</sup>

setPointerVisible(visible: boolean): Promise&lt;void&gt;

Sets the visible status of the mouse pointer. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name     | Type     | Mandatory  | Description                                      |
| ------- | ------- | ---- | ---------------------------------------- |
| visible | boolean | Yes   | Whether the mouse pointer is visible.|

**Return value**

| Name                 | Description                 |
| ------------------- | ------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
try {
  pointer.setPointerVisible(false).then(() => {
    console.log(`Set pointer visible success`);
  });
} catch (error) {
  console.log(`Set pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.isPointerVisible<sup>9+</sup>

isPointerVisible(callback: AsyncCallback&lt;boolean&gt;): void

Checks the visible status of the mouse pointer. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name      | Type                          | Mandatory  | Description            |
| -------- | ---------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result.|

**Example**

```js
try {
  pointer.isPointerVisible((error, visible) => {
    if (error) {
      console.log(`Get pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get pointer visible success, visible: ${JSON.stringify(visible)}`);
  });
} catch (error) {
  console.log(`Get pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.isPointerVisible<sup>9+</sup>

isPointerVisible(): Promise&lt;boolean&gt;

Checks the visible status of the mouse pointer. This API uses a promise to return the result. 

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Return value**

| Name                    | Description                 |
| ---------------------- | ------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```js
try {
  pointer.isPointerVisible().then((visible) => {
    console.log(`Get pointer visible success, visible: ${JSON.stringify(visible)}`);
  });
} catch (error) {
  console.log(`Get pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerSpeed<sup>9+</sup>

setPointerSpeed(speed: number, callback: AsyncCallback&lt;void&gt;): void

Sets the mouse movement speed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| speed    | number                    | Yes   | Mouse movement speed. The value ranges from **1** to **11**. The default value is **5**.  |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

```js
try {
  pointer.setPointerSpeed(5, (error) => {
    if (error) {
      console.log(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set pointer speed success`);
  });
} catch (error) {
  console.log(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerSpeed<sup>9+</sup>

setPointerSpeed(speed: number): Promise&lt;void&gt;

Sets the mouse movement speed. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| speed | number | Yes   | Mouse movement speed. The value ranges from **1** to **11**. The default value is **5**.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
try {
  pointer.setPointerSpeed(5).then(() => {
    console.log(`Set pointer speed success`);
  });
} catch (error) {
  console.log(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSpeed<sup>9+</sup>

getPointerSpeed(callback: AsyncCallback&lt;number&gt;): void

Obtains the mouse movement speed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.|

**Example**

```js
try {
  pointer.getPointerSpeed((error, speed) => {
    if (error) {
      console.log(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);
  });
} catch (error) {
  console.log(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSpeed<sup>9+</sup>

getPointerSpeed(): Promise&lt;number&gt;

Obtains the mouse movement speed. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```js
try {
  pointer.getPointerSpeed().then(speed => {
    console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);
  });
} catch (error) {
  console.log(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerStyle<sup>9+</sup>

getPointerStyle(windowId: number, callback: AsyncCallback&lt;PointerStyle&gt;): void

Obtains the mouse pointer style. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name      | Type                                      | Mandatory  | Description            |
| -------- | ---------------------------------------- | ---- | -------------- |
| windowId | number                                   | Yes   | Window ID.   |
| callback | AsyncCallback&lt;[PointerStyle](#pointerstyle9)&gt; | Yes   | Callback used to return the result.|

**Example**

```js
import window from '@ohos.window';

window.getLastWindow(this.context, (error, win) => {
  if (error.code) {
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(error));
    return;
  }
  let windowId = win.getWindowProperties().id;
  if (windowId < 0) {
    console.log(`Invalid windowId`);
    return;
  }
  try {
    pointer.getPointerStyle(windowId, (error, style) => {
      console.log(`Get pointer style success, style: ${JSON.stringify(style)}`);
    });
  } catch (error) {
    console.log(`Get pointer style failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  }
});
```

## pointer.getPointerStyle<sup>9+</sup>

getPointerStyle(windowId: number): Promise&lt;PointerStyle&gt;

Obtains the mouse pointer style. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name    | Type  | Mandatory| Description    |
| -------- | ------ | ---- | -------- |
| windowId | number | Yes  | Window ID.|

**Return value**

| Name                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[PointerStyle](#pointerstyle9)&gt; | Promise used to return the result.|

**Example**

```js
import window from '@ohos.window';

window.getLastWindow(this.context, (error, win) => {
  if (error.code) {
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(error));
    return;
  }
  let windowId = win.getWindowProperties().id;
  if (windowId < 0) {
    console.log(`Invalid windowId`);
    return;
  }
  try {
    pointer.getPointerStyle(windowId).then((style) => {
      console.log(`Get pointer style success, style: ${JSON.stringify(style)}`);
    });
  } catch (error) {
    console.log(`Get pointer style failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  }
});
```

## pointer.setPointerStyle<sup>9+</sup>

setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback&lt;void&gt;): void

Sets the mouse pointer style. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name          | Type                            | Mandatory  | Description                                 |
| ------------ | ------------------------------ | ---- | ----------------------------------- |
| windowId     | number                         | Yes   | Window ID.                         |
| pointerStyle | [PointerStyle](#pointerstyle9) | Yes   | Mouse pointer style ID.                            |
| callback     | AsyncCallback&lt;void&gt;      | Yes   | Callback used to return the result.|

**Example**

```js
import window from '@ohos.window';

window.getLastWindow(this.context, (error, win) => {
  if (error.code) {
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(error));
    return;
  }
  let windowId = win.getWindowProperties().id;
  if (windowId < 0) {
    console.log(`Invalid windowId`);
    return;
  }
  try {
    pointer.setPointerStyle(windowId, pointer.PointerStyle.CROSS, error => {
      console.log(`Set pointer style success`);
    });
  } catch (error) {
    console.log(`Set pointer style failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  }
});
```
## pointer.setPointerStyle<sup>9+</sup>

setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise&lt;void&gt;

Sets the mouse pointer style. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**Parameters**

| Name                 | Type                            | Mandatory  | Description              |
| ------------------- | ------------------------------ | ---- | ---------------- |
| windowId            | number                         | Yes   | Window ID.      |
| pointerStyle        | [PointerStyle](#pointerstyle9) | Yes   | Mouse pointer style ID.         |
| Promise&lt;void&gt; | void                           | Yes   | Promise used to return the result.|

**Example**

```js
import window from '@ohos.window';

window.getLastWindow(this.context, (error, win) => {
  if (error.code) {
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(error));
    return;
  }
  let windowId = win.getWindowProperties().id;
  if (windowId < 0) {
    console.log(`Invalid windowId`);
    return;
  }
  try {
    pointer.setPointerStyle(windowId, pointer.PointerStyle.CROSS).then(() => {
      console.log(`Set pointer style success`);
    });
  } catch (error) {
    console.log(`Set pointer style failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  }
});
```
## PointerStyle<sup>9+</sup>

Enumerates mouse pointer styles.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

| Name                              | Value   | Description    |Legend|
| -------------------------------- | ---- | ------ |------ |
| DEFAULT                          | 0    | Default     |![Default.png](./figures/Default.png)|
| EAST                             | 1    | East arrow  |![East.png](./figures/East.png)|
| WEST                             | 2    | West arrow  |![West.png](./figures/West.png)|
| SOUTH                            | 3    | South arrow  |![South.png](./figures/South.png)|
| NORTH                            | 4    | North arrow  |![North.png](./figures/North.png)|
| WEST_EAST                        | 5    | West-east arrow |![West_East.png](./figures/West_East.png)|
| NORTH_SOUTH                      | 6    | North-south arrow |![North_South.png](./figures/North_South.png)|
| NORTH_EAST                       | 7    | North-east arrow |![North_East.png](./figures/North_East.png)|
| NORTH_WEST                       | 8    | North-west arrow |![North_West.png](./figures/North_West.png)|
| SOUTH_EAST                       | 9    | South-east arrow |![South_East.png](./figures/South_East.png)|
| SOUTH_WEST                       | 10   | South-west arrow |![South_West.png](./figures/South_West.png)|
| NORTH_EAST_SOUTH_WEST            | 11   | North-east and south-west adjustment|![North_East_South_West.png](./figures/North_East_South_West.png)|
| NORTH_WEST_SOUTH_EAST            | 12   | North-west and south-east adjustment|![North_West_South_East.png](./figures/North_West_South_East.png)|
| CROSS                            | 13   | Cross (accurate selection)  |![Cross.png](./figures/Cross.png)|
| CURSOR_COPY                      | 14   | Copy cursor    |![Copy.png](./figures/Copy.png)|
| CURSOR_FORBID                    | 15   | Forbid cursor   |![Forbid.png](./figures/Forbid.png)|
| COLOR_SUCKER                     | 16   | Sucker    |![Colorsucker.png](./figures/Colorsucker.png)|
| HAND_GRABBING                    | 17   | Grabbing hand  |![Hand_Grabbing.png](./figures/Hand_Grabbing.png)|
| HAND_OPEN                        | 18   | Opening hand  |![Hand_Open.png](./figures/Hand_Open.png)|
| HAND_POINTING                    | 19   | Hand-shaped pointer  |![Hand_Poniting.png](./figures/Hand_Pointing.png)|
| HELP                             | 20   | Help   |![Help.png](./figures/Help.png)|
| MOVE                             | 21   | Move    |![Move.png](./figures/Move.png)|
| RESIZE_LEFT_RIGHT                | 22   | Left and right resizing|![Resize_Left_Right.png](./figures/Resize_Left_Right.png)|
| RESIZE_UP_DOWN                   | 23   | Up and down resizing|![Resize_Up_Down.png](./figures/Resize_Up_Down.png)|
| SCREENSHOT_CHOOSE                | 24   | Screenshot crosshair|![Screenshot_Cross.png](./figures/Screenshot_Cross.png)|
| SCREENSHOT_CURSOR                | 25   | Screenshot cursor    |![Screenshot_Cursor.png](./figures/Screenshot_Cursor.png)|
| TEXT_CURSOR                      | 26   | Text cursor  |![Text_Cursor.png](./figures/Text_Cursor.png)|
| ZOOM_IN                          | 27   | Zoom in    |![Zoom_In.png](./figures/Zoom_In.png)|
| ZOOM_OUT                         | 28   | Zoom out    |![Zoom_Out.png](./figures/Zoom_Out.png)|
| MIDDLE_BTN_EAST                  | 29   | Scrolling east  |![MID_Btn_East.png](./figures/MID_Btn_East.png)|
| MIDDLE_BTN_WEST                  | 30   | Scrolling west  |![MID_Btn_West.png](./figures/MID_Btn_West.png)|
| MIDDLE_BTN_SOUTH                 | 31   | Scrolling south  | ![MID_Btn_South.png](./figures/MID_Btn_South.png)            |
| MIDDLE_BTN_NORTH                 | 32   | Scrolling north  |![MID_Btn_North.png](./figures/MID_Btn_North.png)|
| MIDDLE_BTN_NORTH_SOUTH           | 33   | Scrolling north-south |![MID_Btn_North_South.png](./figures/MID_Btn_North_South.png)|
| MIDDLE_BTN_NORTH_EAST            | 34   | Scrolling north-east |![MID_Btn_North_East.png](./figures/MID_Btn_North_East.png)|
| MIDDLE_BTN_NORTH_WEST            | 35   | Scrolling north-west |![MID_Btn_North_West.png](./figures/MID_Btn_North_West.png)|
| MIDDLE_BTN_SOUTH_EAST            | 36   | Scrolling south-east |![MID_Btn_South_East.png](./figures/MID_Btn_South_East.png)|
| MIDDLE_BTN_SOUTH_WEST            | 37   | Scrolling south-west |![MID_Btn_South_West.png](./figures/MID_Btn_South_West.png)|
| MIDDLE_BTN_NORTH_SOUTH_WEST_EAST | 38   | Moving as a cone in four directions|![MID_Btn_North_South_West_East.png](./figures/MID_Btn_North_South_West_East.png)|
