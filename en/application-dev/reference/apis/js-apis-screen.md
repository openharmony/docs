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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let screenClass = null;
screen.getAllScreens((err, data) => {
    if (err.code) {
        console.error('Failed to get all screens. Cause:  ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in getting all screens. Data:' + JSON.stringify(data));
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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let screenClass = null;
let promise = screen.getAllScreens();
promise.then((data) => {
    screenClass = data[0];
    console.log('Succeeded in getting all screens. Data:'+ JSON.stringify(data));
}).catch((err) => {
    console.log('Failed to get all screens. Cause: ' + JSON.stringify(err));
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
try {
    let callback = (data) => {
        console.info('Succeeded in registering the callback for screen changes. Data: ' + JSON.stringify(data))
    };
    screen.on('connect', callback);
} catch (exception) {
    console.error('Failed to register the callback for screen changes. Code: ' + JSON.stringify(exception));
};
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
try {
    let callback = (data) => {
        console.info('Succeeded in unregistering the callback for screen changes. Data: ' + JSON.stringify(data))
    };
    screen.off('connect', callback);
} catch (exception) {
    console.error('Failed to register the callback for screen changes. Code: ' + JSON.stringify(exception));
};
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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
try {
    let groupId = null;
    screen.makeExpand([{screenId: 0, startX: 0, startY: 0}, {screenId: 1, startX: 1080, startY: 0}], (err, data) => {
      if (err.code) {
        console.error('Failed to expand the screen. Code:' + JSON.stringify(err));
        return;
      }
      groupId = data;
      console.info('Succeeded in expanding the screen. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to expand the screen. Code: ' + JSON.stringify(exception));
};
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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
try {
    screen.makeExpand([{screenId: 0, startX: 0, startY: 0}, {screenId: 1, startX: 1080, startY: 0}]).then((data) => {
      console.info('Succeeded in expanding the screen. Data: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error('Failed to expand the screen. Code:' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to expand the screen. Code: ' + JSON.stringify(exception));
};
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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let mainScreenId = 0;
let mirrorScreenIds = [1, 2, 3];
try {
    screen.makeMirror(mainScreenId, mirrorScreenIds, (err, data) => {
      if (err.code) {
        console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in setting screen mirroring. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(exception));
};
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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let mainScreenId = 0;
let mirrorScreenIds = [1, 2, 3];
try {
    screen.makeMirror(mainScreenId, mirrorScreenIds).then((data) => {
      console.info('Succeeded in setting screen mirroring. Data: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(exception));
};
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback&lt;Screen&gt;): void

Creates a virtual screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (mandatory when **VirtualScreenOption.surfaceId** is valid; available only to system applications)

**Parameters**

| Name  | Type                                       | Mandatory| Description                              |
| -------- | ------------------------------------------- | ---- | ---------------------------------- |
| options  | [VirtualScreenOption](#virtualscreenoption) | Yes  | Virtual screen parameters.          |
| callback | AsyncCallback&lt;[Screen](#screen)&gt;      | Yes  | Callback used to return the created virtual screen.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let screenClass = null;
try {
    screen.createVirtualScreen({
      name: 'screen01',
      width: 1080,
      height: 2340,
      density: 2,
      surfaceId: ''
    }, (err, data) => {
      if (err.code) {
        console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));
        return;
      }
      screenClass = data;
      console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption): Promise&lt;Screen&gt;

Creates a virtual screen. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (mandatory when **VirtualScreenOption.surfaceId** is valid; available only to system applications)

**Parameters**

| Name | Type                                       | Mandatory| Description                    |
| ------- | ------------------------------------------- | ---- | ------------------------ |
| options | [VirtualScreenOption](#virtualscreenoption) | Yes  | Virtual screen parameters.|

**Return value**

| Type                            | Description                                 |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Screen](#screen)&gt; | Promise used to return the created virtual screen.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let screenClass = null;
try {
    screen.createVirtualScreen({
      name: 'screen01',
      width: 1080,
      height: 2340,
      density: 2,
      surfaceId: ''
    }).then((data) => {
      screenClass = data;
      console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number, callback: AsyncCallback&lt;void&gt;): void

Destroys a virtual screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId | number                    | Yes  | Screen ID.                                                  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the virtual screen is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------------- |
| 1400002 | Unauthorized operation. |

**Example**

```js
let screenId = 1;
try {
    screen.destroyVirtualScreen(screenId, (err,data) => {
      if (err.code) {
        console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in destroying the virtual screen.');
    });
} catch (exception) {
    console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number): Promise&lt;void&gt;

Destroys a virtual screen. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | ---- | ---------- |
| screenId | number | Yes  | Screen ID.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------------- |
| 1400002 | Unauthorized operation. |

**Example**

```js
let screenId = 1;
try {
    screen.destroyVirtualScreen(screenId).then((data) => {
      console.info('Succeeded in destroying the virtual screen.');
    }).catch((err) => {
      console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback&lt;void&gt;): void

Sets the surface for a virtual screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId  | number                    | Yes  | Screen ID.                                                  |
| surfaceId | string                    | Yes  | Surface ID.                                               |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the virtual screen surface is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let screenId = 1;
let surfaceId = '2048';
try {
  screen.setVirtualScreenSurface(screenId, surfaceId, (err,data) => {
    if (err.code) {
      console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in setting the surface for the virtual screen.');
  });
} catch (exception) {
    console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string): Promise&lt;void&gt;

Sets the surface for a virtual screen. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name   | Type  | Mandatory| Description         |
| --------- | ------ | ---- | ------------- |
| screenId  | number | Yes  | Screen ID.   |
| surfaceId | string | Yes  | Surface ID.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**Example**

```js
let screenId = 1;
let surfaceId = '2048';
try {
    screen.setVirtualScreenSurface(screenId, surfaceId).then((data) => {
      console.info('Succeeded in setting the surface for the virtual screen.');
    }).catch((err) => {
      console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.isScreenRotationLocked

isScreenRotationLocked(): Promise&lt;boolean&gt;

Checks whether auto rotate is locked. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                  | Description                                 |
| ---------------------- | ------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If **true** is returned, auto rotate is locked. If **false** is returned, auto rotate is unlocked.|

**Example**

```js
screen.isScreenRotationLocked().then((isLocked) => {
  console.info('Succeeded in getting the screen rotation lock status. isLocked:'+ JSON.stringify(isLocked));
}).catch((err) => {
  console.error('Failed to get the screen rotation lock status. Cause:' + JSON.stringify(err));
});
```

## screen.isScreenRotationLocked

isScreenRotationLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether auto rotate is locked. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type                         | Mandatory| Description                                                        |
| --------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If **true** is returned, auto rotate is locked. If **false** is returned, auto rotate is unlocked.|

**Example**

```js
screen.isScreenRotationLocked((err, isLocked) => {
  if (err.code) {
    console.error('Failed to get the screen rotation lock status. Cause:' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in getting the screen rotation lock status. isLocked:' + JSON.stringify(isLocked));
});
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean): Promise&lt;void&gt;

Sets whether to lock auto rotate. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type  | Mandatory| Description         |
| --------- | ------ | ---- | ------------- |
| isLocked  | boolean | Yes  | Whether to lock auto rotate. The value **true** means to lock auto rotate, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let isLocked = false;
try {
    screen.setScreenRotationLocked(isLocked).then((data) => {
      console.info('Succeeded in unlocking auto rotate');
    }).catch((err) => {
      console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(exception));
};
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to lock auto rotate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| isLocked  | boolean                   | Yes  | Whether to lock auto rotate. The value **true** means to lock auto rotate, and **false** means the opposite.                |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
let isLocked = false;
try {
    screen.setScreenRotationLocked(isLocked, (err, data) => {
      if (err.code) {
        console.error('Failed to unlock auto rotate. Cause:' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in unlocking auto rotate.');
    });
} catch (exception) {
    console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(exception));
};
```

## ExpandOption

Defines the parameters for expanding a screen.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name    | Type| Readable| Writable| Description               |
| -------- | -------- | ---- | ---- | ------------------- |
| screenId | number   | Yes  | Yes  | Screen ID.         |
| startX   | number   | Yes  | Yes  | Start X coordinate of the screen.|
| startY   | number   | Yes  | Yes  | Start Y coordinate of the screen.|

## VirtualScreenOption

Defines virtual screen parameters.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type| Readable| Writable| Description                     |
| --------- | -------- | ---- | ---- | ------------------------- |
| name      | string   | Yes  | Yes  | Name of a virtual screen.     |
| width     | number   | Yes  | Yes  | Width of the virtual screen.     |
| height    | number   | Yes  | Yes  | Height of the virtual screen.     |
| density   | number   | Yes  | Yes  | Density of the virtual screen.     |
| surfaceId | string   | Yes  | Yes  | Surface ID of the virtual screen.|

## Screen

Implements a **Screen** instance.

Before calling any API in **Screen**, you must use **[getAllScreens()](#screengetallscreens)** or **[createVirtualScreen()](#screencreatevirtualscreen)** to obtain a **Screen** instance.

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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```js
try {
    screenClass.setOrientation(screen.Orientation.VERTICAL, (err, data) => {
        if (err.code) {
            console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the vertical orientation. data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));
};
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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```js
try {
    let promise = screenClass.setOrientation(screen.Orientation.VERTICAL);
    promise.then((data) => {
        console.info('Succeeded in setting the vertical orientation. Data: ' + JSON.stringify(data));
    }).catch((err) => {
        console.error('Failed to set the vertical orientation. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));
};
```

### setScreenActiveMode

setScreenActiveMode(modeIndex: number, callback: AsyncCallback&lt;void&gt;): void

Sets the active mode of the screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| modeIndex | number                    | Yes  | Index of the mode to set.                                                  |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the active mode is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```js
let modeIndex = 0;
try {
    screenClass.setScreenActiveMode(modeIndex, (err, data) => {
        if (err.code) {
            console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting screen active mode 0. data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(exception));
};
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

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```js
let modeIndex = 0;
try {
    let promise = screenClass.setScreenActiveMode(modeIndex);
      promise.then((data) => {
          console.info('Succeeded in setting screen active mode 0. Data: ' + JSON.stringify(data));
      }).catch((err) => {
          console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(err));
      });
} catch (exception) {
    console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(exception));
};
```

### setDensityDpi

setDensityDpi(densityDpi: number, callback: AsyncCallback&lt;void&gt;): void;

Sets the pixel density of the screen. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name    | Type                     | Mandatory| Description                                                        |
| ---------- | ------------------------- | ---- | ------------------------------------------------------------ |
| densityDpi | number                    | Yes  | Pixel density. The value ranges from 80 to 640.                          |
| callback   | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the pixel density is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```js
let densityDpi = 320;
try {
    screenClass.setDensityDpi(densityDpi, (err, data) => {
        if (err.code) {
            console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeed in setting the pixel density of the screen to 320. data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(exception));
};
```

### setDensityDpi

setDensityDpi(densityDpi: number): Promise&lt;void&gt;

Sets the pixel density of the screen. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| densityDpi | number | Yes  | Pixel density. The value ranges from 80 to 640.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Display Error Codes](../errorcodes/errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**Example**

```js
let densityDpi = 320;
try {
    let promise = screenClass.setDensityDpi(densityDpi);
    promise.then((data) => {
        console.info('Succeeded in setting the pixel density of the screen to 320. Data: ' + JSON.stringify(data));
    }).catch((err) => {
        console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(exception));
};
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

## ScreenModeInfo

Defines the screen mode information.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name       | Type| Readable| Writable| Description                                              |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| id          | number   | Yes  | Yes  | Mode ID. The supported mode is determined by the device resolution and refresh rate.|
| width       | number   | Yes  | Yes  | Screen width.                                      |
| height      | number   | Yes  | Yes  | Screen height.                                      |
| refreshRate | number   | Yes  | Yes  | Screen refresh rate.                                    |
