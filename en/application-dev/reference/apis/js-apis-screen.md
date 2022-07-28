# Screen
The **Screen** module implements basic screen management. You can use the APIs of this module to obtain a **Screen** object, listen for screen changes, and create and destroy virtual screens.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs provided by this module are system APIs.
## Modules to Import

```js
import screen from '@ohos.screen';
```

## screen.getAllScreens

getAllScreens(callback: AsyncCallback&lt;Array&lt;Screen&gt;&gt;): void

Obtains all screens. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                                  |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Screen](#screen)&gt;&gt; | Yes  | Callback used to return all the **Screen** objects obtained.|

**Example**

```js
var screenClass = null;
screen.getAllScreens((err, data) => {
    if (err.code) {
        console.error('Failed to get all screens . Cause:  ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in getting all screens . Data:' + JSON.stringify(data));
    screenClass = data[0];
});
```
## screen.getAllScreens

getAllScreens(): Promise&lt;Array&lt;Screen&gt;&gt;

Obtains all screens. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**
| Type                                         | Description                                     |
| --------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Screen](#screen)&gt;&gt; | Promise used to return all the **Screen** objects obtained.|

**Example**

```js
var screenClass = null;
let promise = screen.getAllScreens();
promise.then((data) => {
    screenClass = data[0];
    console.log('Succeeded in getting all screens . Data:'+ JSON.stringify(data));
}).catch((err) => {
    console.log('Failed to get all screens . Cause: ' + JSON.stringify(err));
});
```
## screen.on('connect' | 'disconnect' | 'change')
on(eventType: 'connect' | 'disconnect' | 'change', callback: Callback&lt;number&gt;): void

Subscribes to events related to the screen state.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
| Name   | Type                  | Mandatory| Description                                                        |
| --------- | ---------------------- | ---- | ------------------------------------------------------------ |
| eventType | string                 | Yes  | Event type.<br>- **connect**: an event indicating that the screen is connected.<br>- **disconnect**: an event indicating that the screen is disconnected.<br>- **change**: an event indicating that the screen state changes.|
| callback  | Callback&lt;number&gt; | Yes  | Callback used to return the screen ID.                                    |

**Example**
```js
var callback = (data) => {
    console.info('Register the callback for screen changes. Data: ' + JSON.stringify(data))
};
screen.on("connect", callback);
```
## screen.off('connect' | 'disconnect' | 'change')
off(eventType: 'connect' | 'disconnect' | 'change', callback?: Callback&lt;number&gt;): void

Unsubscribes from events related to the screen state.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
| Name   | Type                  | Mandatory| Description                                                        |
| --------- | ---------------------- | ---- | ------------------------------------------------------------ |
| eventType | string                 | Yes  | Event type.<br>- **connect**: an event indicating that the screen is connected.<br>- **disconnect**: an event indicating that the screen is disconnected.<br>- **change**: an event indicating that the screen state changes.|
| callback  | Callback&lt;number&gt; | No  | Callback used to return the screen ID.                                    |

**Example**
```js
var callback = (data) => {
    console.info('Unegister the callback for screen changes. Data: ' + JSON.stringify(data))
};
screen.off("connect", callback);
```

## screen.makeExpand
makeExpand(options:Array&lt;ExpandOption&gt;, callback: AsyncCallback&lt;number&gt;): void

Sets the screen to the expanded mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
| Name  | Type                                      | Mandatory| Description                            |
| -------- | ------------------------------------------ | ---- | -------------------------------- |
| options  | Array&lt;[ExpandOption](#expandoption)&gt; | Yes  | Parameters for expanding the screen.        |
| callback | Callback&lt;number&gt;                     | Yes  | Callback used to return the group ID of the expanded screens.|

**Example**

```js
var groupId = null;
screen.makeExpand([{screenId: 0, startX: 0, startY: 0}, {screenId: 1, startX: 1080, startY: 0}], (err, data) => {
  if (err.code) {
    console.error('Failed to make screens as expand-screen. Cause:' + JSON.stringify(err));
    return;
  }
  groupId = data;
  console.info('Succeeded in making screens as expand-screen.Data:' + JSON.stringify(data));
});
```

## screen.makeExpand
makeExpand(options:Array&lt;ExpandOption&gt;): Promise&lt;number&gt;

Sets the screen to the expanded mode. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                                      | Mandatory| Description                    |
| ------- | ------------------------------------------ | ---- | ------------------------ |
| options | Array&lt;[ExpandOption](#expandoption)&gt; | Yes  | Parameters for expanding the screen.|

**Return value**
| Type                 | Description                               |
| --------------------- | ----------------------------------- |
| Promise&lt;number&gt; | Promise used to return the group ID of the expanded screens.|

**Example**
```js
screen.makeExpand([{screenId: 0, startX: 0, startY: 0}, {screenId: 1, startX: 1080, startY: 0}]).then((data) => {
  console.info('Succeeded in making screens as expand-screen.Data:' + JSON.stringify(data));
}).catch((err) => {
  console.error('Failed to make screens as expand-screen. Cause:' + JSON.stringify(err));
});
```

## screen.makeMirror
makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

Sets screen mirroring. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                       | Mandatory| Description             |
| ------------ | --------------------------- | ---- |-----------------|
| mainScreen   | number                      | Yes  | ID of the primary screen.         |
| mirrorScreen | Array&lt;number&gt;         | Yes  | IDs of secondary screens.      |
| callback     | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the group ID of the secondary screens.|

**Example**
```js
var mainScreenId = 0;
var mirrorScreenIds = [1, 2, 3];
screen.makeMirror(mainScreenId, mirrorScreenIds, (err, data) => {
  if (err.code) {
    console.error('Failed to make screens as mirror-screen.Cause:' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in making screens as mirror-screen.Data:' + JSON.stringify(data));
});
```

## screen.makeMirror
makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;): Promise&lt;number&gt;

Sets screen mirroring. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type               | Mandatory| Description       |
| ------------ | ------------------- | ---- |-----------|
| mainScreen   | number              | Yes  | ID of the primary screen.   |
| mirrorScreen | Array&lt;number&gt; | Yes  | IDs of secondary screens.|

**Return value**
| Type                 | Description                               |
| --------------------- | ----------------------------------- |
| Promise&lt;number&gt; | Promise used to return the group ID of the secondary screens.|

**Example**
```js
var mainScreenId = 0;
var mirrorScreenIds = [1, 2, 3];
screen.makeMirror(mainScreenId, mirrorScreenIds).then((data) => {
  console.info('Succeeded in making screens as mirror-screen.Data:' + JSON.stringify(data));
}).catch((err) => {
  console.error('Failed to make screens as mirror-screen.Cause:' + JSON.stringify(err));
});
```

## ExpandOption
Defines the parameters for expanding a screen.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name    | Type| Readable| Writable| Description               |
| -------- | -------- | ---- | ---- | ------------------- |
| screenId | number   | Yes  | Yes  | Screen ID.         |
| startX   | number   | Yes  | Yes  | Start X coordinate of the screen.|
| startY   | number   | Yes  | Yes  | Start Y coordinate of the screen.|


## Screen
Implements a **Screen** instance.

Before calling any API in **Screen**, you must use **[getAllScreens()](#screengetallscreens)** to obtain a **Screen** instance.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name             | Type                                      | Readable| Writable| Description                  |
| ----------------- | ---------------------------------------------- | ---- | ---- | ---------------------- |
| id                | number                                         | Yes  | No  | Screen ID.            |
| parent            | number                                         | Yes  | No  | ID of the group to which a screen belongs.    |
| supportedModeInfo | Array&lt;[ScreenModeInfo](#screenmodeinfo)&gt; | Yes  | No  | Mode set supported by the screen.  |
| activeModeIndex   | number                                         | Yes  | No  | Index of the active screen mode.|
| orientation       | [Orientation](#orientation)                     | Yes  | No  | Screen orientation.            |

### setOrientation
setOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

Sets the screen orientation. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| orientation | [Orientation](#orientation) | Yes  | Screen orientation.                                                  |
| callback    | AsyncCallback&lt;void&gt;   | Yes  | Callback used to return the result. If the screen orientation is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**
```js
screenClass.setOrientation(screen.Orientation.VERTICAL, (err, data) => {
    if (err.code) {
        console.error('Failed to setOrientation VERTICAL. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting Orientation VERTICAL. data: ' + JSON.stringify(data));
})
```
### setOrientation
setOrientation(orientation: Orientation): Promise&lt;void&gt;

Sets the screen orientation. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type                       | Mandatory| Description      |
| ----------- | --------------------------- | ---- | ---------- |
| orientation | [Orientation](#orientation) | Yes  | Screen orientation.|

**Return value**
| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```js
let promise = screenClass.setOrientation(screen.Orientation.VERTICAL);
promise.then((data) => {
    console.info('Succeeded in setting Orientation VERTICAL. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to set Orientation VERTICAL. Cause: ' + JSON.stringify(err));
})
```
### setScreenActiveMode
setScreenActiveMode(modeIndex: number, callback: AsyncCallback&lt;void&gt;): void

Sets the active mode of the screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| modeIndex | number                    | Yes  | Index of the mode to set.                                                  |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the active mode is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
var modeIndex = 0;
screenClass.setScreenActiveMode(modeIndex, (err, data) => {
    if (err.code) {
        console.error('Failed to set ScreenActiveMode 0. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting ScreenActiveMode 0. data: ' + JSON.stringify(data));
})
```
### setScreenActiveMode
setScreenActiveMode(modeIndex: number): Promise&lt;void&gt;

Sets the active mode of the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name   | Type  | Mandatory| Description      |
| --------- | ------ | ---- | ---------- |
| modeIndex | number | Yes  | Index of the mode to set.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**
```js
var modeIndex = 0;
let promise = screenClass.setScreenActiveMode(modeIndex);
promise.then((data) => {
    console.info('Succeeded in setting ScreenActiveMode 0. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to set ScreenActiveMode 0. Cause: ' + JSON.stringify(err));
})
```

## Orientation
Enumerates the screen orientations.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Value  | Description                            |
| ------------------ | ---- | -------------------------------- |
| UNSPECIFIED        | 0    | Unspecified. The screen orientation is determined by the system.|
| VERTICAL           | 1    | Vertical.        |
| HORIZONTAL         | 2    | Horizontal.        |
| REVERSE_VERTICAL   | 3    | Reverse vertical.    |
| REVERSE_HORIZONTAL | 4    | Reverse horizontal.    |
| SENSOR             | 5    | The screen orientation follows the sensor direction.    |
| SENSOR_VERTICAL    | 6    | The screen orientation follows the sensor direction vertically.|
| SENSOR_HORIZONTAL  | 7    | The screen orientation follows the sensor direction horizontally.|

## ScreenModeInfo
Defines the screen mode information.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name       | Type| Readable| Writable| Description                                              |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| id          | number   | Yes  | Yes  | Mode ID. The supported mode is determined by the device resolution and refresh rate.|
| width       | number   | Yes  | Yes  | Screen width.                                      |
| height      | number   | Yes  | Yes  | Screen height.                                      |
| refreshRate | number   | Yes  | Yes  | Screen refresh rate.                                    |
