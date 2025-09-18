# @ohos.screen (Screen) (System API)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk; @logn-->
<!--Designer: @hejunfei1991-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

The module implements basic screen management. You can use the APIs of this module to obtain a Screen object, listen for screen changes, and create and destroy virtual screens.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { screen } from '@kit.ArkUI';
```

## screen.getAllScreens

getAllScreens(callback: AsyncCallback&lt;Array&lt;Screen&gt;&gt;): void

Obtains all screens. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                                  |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Screen](#screen)&gt;&gt; | Yes  | Callback used to return all the Screen objects obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
screen.getAllScreens((err: BusinessError, data: Array<screen.Screen>) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get all screens. Code:${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting all screens. Data: ${JSON.stringify(data)}`);
  if(data.length > 0 ){
    screenClass = data[0];
  }
});
```

## screen.getAllScreens

getAllScreens(): Promise&lt;Array&lt;Screen&gt;&gt;

Obtains all screens. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                         | Description                                     |
| --------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Screen](#screen)&gt;&gt; | Promise used to return all the Screen objects obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
let promise: Promise<Array<screen.Screen>> = screen.getAllScreens();
promise.then((data: Array<screen.Screen>) => {
  if(data.length > 0){
  	screenClass = data[0];
  }
  console.info(`Succeeded in getting all screens. Data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get all screens. Code: ${err.code}, message : ${err.message}`);
});
```

## screen.on('connect' | 'disconnect' | 'change')

on(eventType: 'connect' | 'disconnect' | 'change', callback: Callback&lt;number&gt;): void

Subscribes to events related to the screen state.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type                  | Mandatory| Description                                                       |
| --------- | ---------------------- | ---- | ----------------------------------------------------------- |
| eventType | string                 | Yes  | Event type.<br>- **connect**: an event indicating that the screen is connected.<br>- **disconnect**: an event indicating that the screen is disconnected.<br>- **change**: an event indicating that the screen state changes.|
| callback  | Callback&lt;number&gt; | Yes  | Callback used to return the screen ID, which is an integer.                                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
let callback: Callback<number> = (data: number) => {
  console.info(`Succeeded in registering the callback for screen changes. Data: ${data}`)
};
screen.on('connect', callback);
```

## screen.off('connect' | 'disconnect' | 'change')

off(eventType: 'connect' | 'disconnect' | 'change', callback?: Callback&lt;number&gt;): void

Unsubscribes from events related to the screen state.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type                  | Mandatory| Description                                                        |
| --------- | ---------------------- | ---- | ------------------------------------------------------------ |
| eventType | string                 | Yes  | Event type.<br>- **connect**: an event indicating that the screen is connected.<br>- **disconnect**: an event indicating that the screen is disconnected.<br>- **change**: an event indicating that the screen state changes.|
| callback  | Callback&lt;number&gt; | No  | Callback used to return the screen ID, which is an integer.                                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
let callback: Callback<number> = (data: number) => {
  console.info(`Succeeded in unregistering the callback for screen changes. Data: ${data}`)
};
screen.off('connect', callback);
screen.off('connect');
```

## screen.makeMirror

makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

Sets the screen to mirror mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                       | Mandatory| Description                |
| ------------ | --------------------------- | ---- |--------------------|
| mainScreen   | number                      | Yes  | ID of the primary screen. The ID must be an integer. |
| mirrorScreen | Array&lt;number&gt;         | Yes  | Array of IDs of secondary screens. Each ID must be an integer.|
| callback     | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the group ID of the secondary screens, where the ID is an integer. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mainScreenId: number = 0;
let mirrorScreenIds: Array<number> = [1, 2, 3];
screen.makeMirror(mainScreenId, mirrorScreenIds, (err: BusinessError, data: number) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set screen mirroring. Code:${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting screen mirroring. Data: ${data}`);
});
```

## screen.makeMirror

makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;): Promise&lt;number&gt;

Sets the screen to mirror mode. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type               | Mandatory| Description                |
| ------------ | ------------------- | ---- |--------------------|
| mainScreen   | number              | Yes  | ID of the primary screen. The ID must be an integer. |
| mirrorScreen | Array&lt;number&gt; | Yes  | Array of IDs of secondary screens. Each ID must be an integer.|

**Return value**

| Type                 | Description                             |
| --------------------- |---------------------------------|
| Promise&lt;number&gt; | Promise used to return the group ID of the secondary screens, where the ID is an integer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mainScreenId: number = 0;
let mirrorScreenIds: Array<number> = [1, 2, 3];
screen.makeMirror(mainScreenId, mirrorScreenIds).then((data: number) => {
  console.info(`Succeeded in setting screen mirroring. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set screen mirroring. Code:${err.code}, message is ${err.message}`);
});
```

## screen.stopMirror<sup>10+</sup>

stopMirror(mirrorScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;void&gt;): void

Stops mirror mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description                                     |
| ------------ | --------------------------- | --- |-----------------------------------------|
| mirrorScreen | Array&lt;number&gt;         | Yes  | Array of IDs of secondary screens. Each ID must be an integer. The size of the mirrorScreen array cannot exceed 1000.|
| callback     | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If mirror mode is stopped, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mirrorScreenIds: Array<number> = [1, 2, 3];
screen.stopMirror(mirrorScreenIds, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to stop mirror screens. Code:${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in stopping mirror screens.');
});
```

## screen.stopMirror<sup>10+</sup>

stopMirror(mirrorScreen:Array&lt;number&gt;): Promise&lt;void&gt;

Stops mirror mode. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------------ | ------------------- | --- |--------------------|
| mirrorScreen | Array&lt;number&gt; | Yes  | Array of IDs of secondary screens. Each ID must be an integer. The size of the **mirrorScreen** array cannot exceed 1000.|

**Return value**

| Type| Description|
| --------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mirrorScreenIds: Array<number> = [1, 2, 3];
screen.stopMirror(mirrorScreenIds).then(() => {
  console.info('Succeeded in stopping mirror screens.');
}).catch((err: BusinessError) => {
  console.error(`Failed to stop mirror screens.Code:${err.code}, message is ${err.message}`);
});
```

## screen.makeUnique<sup>18+</sup>

makeUnique(uniqueScreen: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Sets the screen to independent display mode. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type  | Mandatory| Description         |
| --------- | ------ | ---- | ------------- |
| uniqueScreen  | Array&lt;number&gt; | Yes  | Arry of independent screen IDs. Each ID must be an integer greater than 0; otherwise, error code 401 is returned.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to returns the independent screen IDs, where each ID is an integer greater than 0.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed, non-system application uses system API. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let uniqueScreenIds: Array<number> = [1001, 1002, 1003];
screen.makeUnique(uniqueScreenIds).then((data: Array<number>) => {
  console.info('Succeeded in making unique screens.');
}).catch((err: BusinessError) => {
  console.error(`Failed to make unique screens. Code:${err.code}, message is ${err.message}`);
});
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback&lt;Screen&gt;): void

Creates a virtual screen. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN

**Parameters**

| Name  | Type                                       | Mandatory| Description                              |
| -------- | ------------------------------------------- | ---- | ---------------------------------- |
| options  | [VirtualScreenOption](#virtualscreenoption) | Yes  | Virtual screen parameters.          |
| callback | AsyncCallback&lt;[Screen](#screen)&gt;      | Yes  | Callback used to return the created virtual screen.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = { 
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};
screen.createVirtualScreen(option, (err: BusinessError, data: screen.Screen) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
    return;
  }
  screenClass = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
});
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption): Promise&lt;Screen&gt;

Creates a virtual screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN

**Parameters**

| Name | Type                                       | Mandatory| Description                    |
| ------- | ------------------------------------------- | ---- | ------------------------ |
| options | [VirtualScreenOption](#virtualscreenoption) | Yes  | Virtual screen parameters.|

**Return value**

| Type                            | Description                                 |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Screen](#screen)&gt; | Promise used to return the created virtual screen.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = { 
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

screen.createVirtualScreen(option).then((data: screen.Screen) => {
  screenClass = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number, callback: AsyncCallback&lt;void&gt;): void

Destroys a virtual screen. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId | number                    | Yes  | Screen ID. The value must be an integer.                                                  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the virtual screen is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400002 | Unauthorized operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenId: number = 1;
screen.destroyVirtualScreen(screenId, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to destroy the virtual screen. Code:${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in destroying the virtual screen.');
});
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number): Promise&lt;void&gt;

Destroys a virtual screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | ---- | ---------- |
| screenId | number | Yes  | Screen ID. The value must be an integer.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400002 | Unauthorized operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenId: number = 1;
screen.destroyVirtualScreen(screenId).then(() => {
  console.info('Succeeded in destroying the virtual screen.');
}).catch((err: BusinessError) => {
  console.error(`Failed to destroy the virtual screen.Code:${err.code}, message is ${err.message}`);
});
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback&lt;void&gt;): void

Sets the surface for a virtual screen. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId  | number                    | Yes  | Screen ID. The value must be an integer.                                                  |
| surfaceId | string                    | Yes  | Surface ID of the virtual screen. The value can be customized.                                               |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the virtual screen surface is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenId: number = 1;
let surfaceId: string = '2048';
screen.setVirtualScreenSurface(screenId, surfaceId, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the surface for the virtual screen. Code:${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the surface for the virtual screen.');
});
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string): Promise&lt;void&gt;

Sets the surface for a virtual screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.CAPTURE_SCREEN (available only to system applications)

**Parameters**

| Name   | Type  | Mandatory| Description         |
| --------- | ------ | ---- | ------------- |
| screenId  | number | Yes  | Screen ID. The value must be an integer.   |
| surfaceId | string | Yes  | Surface ID of the virtual screen. The value can be customized.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenId: number = 1;
let surfaceId: string = '2048';
screen.setVirtualScreenSurface(screenId, surfaceId).then(() => {
  console.info('Succeeded in setting the surface for the virtual screen.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the surface for the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

## screen.setScreenPrivacyMaskImage<sup>19+</sup>

setScreenPrivacyMaskImage(screenId:number, image?: image.PixelMap): Promise&lt;void&gt;

Sets a privacy mask image for the screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type  | Mandatory| Description         |
| --------- | ------ | ---- | ------------- |
| screenId  | number | Yes  | Screen ID. The value must be a positive integer.   |
| image | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | No  | Privacy mask image. If no value is passed, the default privacy mask image is used.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelmap.');
  let screenId: number = 1;
  screen.setScreenPrivacyMaskImage(screenId, pixelMap).then(() => {
    console.info('Succeeded in setting the privacy mask image for the screen.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the privacy mask image for the screen. Code:${err.code}, message is ${err.message}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create pixelmap. code is ${error.code}, message is ${error.message}`);
})
```

## screen.isScreenRotationLocked

isScreenRotationLocked(): Promise&lt;boolean&gt;

Checks whether auto rotate is locked. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                  | Description                                 |
| ---------------------- | ------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If **true** is returned, auto rotate is locked. If **false** is returned, auto rotate is unlocked.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

screen.isScreenRotationLocked().then((isLocked: boolean) => {
  console.info(`Succeeded in getting the screen rotation lock status. isLocked: ${islocked}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get the screen rotation lock status. Code:${err.code}, message is ${err.message}`);
});
```

## screen.isScreenRotationLocked

isScreenRotationLocked(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether auto rotate is locked. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type                         | Mandatory| Description                                                        |
| --------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If **true** is returned, auto rotate is locked. If **false** is returned, auto rotate is unlocked.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

screen.isScreenRotationLocked((err: BusinessError, isLocked: boolean) => {
const errCode: number = err.code;
if (errCode) {
  console.error(`Failed to get the screen rotation lock status. Code:${err.code}, message is ${err.message}`);
  return;
}
console.info(`Succeeded in getting the screen rotation lock status. isLocked: ${islocked}`);
});
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean): Promise&lt;void&gt;

Sets whether to lock auto rotate. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: This API takes effect only on devices that support sensor-driven rotation. If this API is called on other devices, no error is reported.

**Parameters**

| Name   | Type  | Mandatory| Description         |
| --------- | ------ | ---- | ------------- |
| isLocked  | boolean | Yes  | Whether to lock auto rotate. **true** to lock, **false** otherwise.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isLocked: boolean = false;
screen.setScreenRotationLocked(isLocked).then(() => {
  console.info('Succeeded in unlocking auto rotate');
}).catch((err: BusinessError) => {
  console.error(`Failed to unlock auto rotate. Code:${err.code}, message is ${err.message}`);
});
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to lock auto rotate. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: This API takes effect only on devices that support sensor-driven rotation. If this API is called on other devices, no error is reported.

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| isLocked  | boolean                   | Yes  | Whether to lock auto rotate. **true** to lock, **false** otherwise.                |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isLocked: boolean = false;
screen.setScreenRotationLocked(isLocked, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to unlock auto rotate. Code:${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in unlocking auto rotate.');
});
```

## screen.setMultiScreenMode<sup>13+</sup>

setMultiScreenMode(primaryScreenId: number, secondaryScreenId: number, secondaryScreenMode: MultiScreenMode): Promise&lt;void&gt;

Sets the display mode (mirror or extend) of the secondary screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                | Mandatory| Description               |
| ------------ | ------------------- | ---- |--------------------|
| primaryScreenId   | number           | Yes | ID of the primary screen. The value must be an integer.|
| secondaryScreenId | number           | Yes | ID of the secondary screen. The value must be an integer.|
| secondaryScreenMode | [MultiScreenMode](#multiscreenmode13)  | Yes | Display mode of the secondary screen.|

**Return value**

| Type              | Description                    |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed, non-system application uses system API. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let primaryScreenId: number = 0;
let secondaryScreenId: number = 12;
let screenMode: screen.MultiScreenMode = screen.MultiScreenMode.SCREEN_MIRROR;
screen.setMultiScreenMode(primaryScreenId, secondaryScreenId, screenMode).then(() => {
  console.info('Succeeded in setting multi screen mode. Data: ');
}).catch((err: BusinessError) => {
  console.error(`Failed to set multi screen mode. Code:${err.code}, message is ${err.message}`);
});
```

## screen.setMultiScreenRelativePosition<sup>13+</sup>

setMultiScreenRelativePosition(mainScreenOptions: MultiScreenPositionOptions, secondaryScreenOptions: MultiScreenPositionOptions): Promise&lt;void&gt;

Sets the positions of the primary and secondary screens in extend mode. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                | Mandatory| Description              |
| ------------ | ------------------- | ---- |--------------------|
| mainScreenOptions      | [MultiScreenPositionOptions](#multiscreenpositionoptions13)  | Yes | Position of the primary screen.|
| secondaryScreenOptions | [MultiScreenPositionOptions](#multiscreenpositionoptions13)  | Yes | Position of the secondary screen.|

**Return value**

| Type               | Description                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed, non-system application uses system API. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mainScreenOptions: screen.MultiScreenPositionOptions = {
  id : 0,
  startX : 0,
  startY : 0
};

let secondaryScreenOptions: screen.MultiScreenPositionOptions = {
  id : 12,
  startX : 1000,
  startY : 1000
};

screen.setMultiScreenRelativePosition(mainScreenOptions, secondaryScreenOptions).then(() => {
  console.info('Succeeded in setting multi screen relative position.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set multi screen relative position. Code:${err.code}, message is ${err.message}`);
});
```

## screen.makeMirrorWithRegion<sup>19+</sup>

makeMirrorWithRegion(mainScreen:number, mirrorScreen:Array&lt;number&gt;, mainScreenRegion:Rect): Promise&lt;number&gt;

Sets a rectangle on the screen to mirror mode. This API uses a promise to return the result. After this API is called, you are advised not to rotate or fold the screen further. Otherwise, the mirrored content may be abnormal.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type               | Mandatory| Description                |
| ------------ | ------------------- | ---- |--------------------|
| mainScreen   | number              | Yes  | ID of the primary screen. The ID must be a positive integer. |
| mirrorScreen | Array&lt;number&gt; | Yes  | Array of IDs of secondary screens. Each ID must be a positive integer. |
| mainScreenRegion | [Rect](#rect19) | Yes  | Rectangle on the primary screen to be mirrored.        |

**Return value**

| Type                 | Description                             |
| --------------------- |---------------------------------|
| Promise&lt;number&gt; | Promise used to return the group ID of the secondary screens, where the ID is a positive integer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mainScreenId: number = 0;
let mirrorScreenIds: Array<number> = [1, 2, 3];
let mainScreenRegion: screen.Rect = {
  left : 0,
  top : 0,
  width : 1920,
  height : 1080
};
screen.makeMirrorWithRegion(mainScreenId, mirrorScreenIds, mainScreenRegion).then((data: number) => {
  console.info(`Succeeded in setting screen mirroring. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set screen area mirroring. Code:${err.code}, message is ${err.message}`);
});
```

## screen.makeExpand<sup>(deprecated)</sup>

makeExpand(options:Array&lt;ExpandOption&gt;, callback: AsyncCallback&lt;number&gt;): void

Sets the screen to extended mode. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 9 and deprecated since API version 20.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                        |
| -------- | ------------------------------------------ | ---- |----------------------------|
| options  | Array&lt;[ExpandOption](#expandoption)&gt; | Yes  | Parameters for expanding the screen.              |
| callback | AsyncCallback&lt;number&gt;                     | Yes  | Callback used to return the group ID of the extended screens, where the ID is an integer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let groupId: number | null = null;
class ExpandOption {
  screenId: number = 0;
  startX: number = 0;
  startY: number = 0;
}
let mainScreenOption: ExpandOption = { screenId: 0, startX: 0, startY: 0 };
let otherScreenOption: ExpandOption = { screenId: 1, startX: 1080, startY: 0 };
let expandOptionArray : ExpandOption[] = [ mainScreenOption, otherScreenOption ];
screen.makeExpand(expandOptionArray, (err: BusinessError, data: number) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to expand the screen. Code:${err.code}, message is ${err.message}`);
    return;
  }
  groupId = data;
  console.info(`Succeeded in expanding the screen. Data: ${data}`);
});
```

## screen.makeExpand<sup>(deprecated)</sup>

makeExpand(options:Array&lt;ExpandOption&gt;): Promise&lt;number&gt;

Sets the screen to extended mode. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 9 and deprecated since API version 20.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                                      | Mandatory| Description                    |
| ------- | ------------------------------------------ | ---- | ------------------------ |
| options | Array&lt;[ExpandOption](#expandoption)&gt; | Yes  | Parameters for expanding the screen.|

**Return value**

| Type                 | Description                             |
| --------------------- |---------------------------------|
| Promise&lt;number&gt; | Promise used to return the group ID of the extended screens, where the ID is an integer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class ExpandOption {
  screenId: number = 0;
  startX: number = 0;
  startY: number = 0;
}
let mainScreenOption: ExpandOption = { screenId: 0, startX: 0, startY: 0 };
let otherScreenOption: ExpandOption = { screenId: 1, startX: 1080, startY: 0 };
let expandOptionArray : ExpandOption[] = [ mainScreenOption, otherScreenOption ];
screen.makeExpand(expandOptionArray).then((
  data: number) => {
  console.info(`Succeeded in expanding the screen. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to expand the screen. Code:${err.code}, message is ${err.message}`);
});
```

## screen.stopExpand<sup>(deprecated)</sup>

stopExpand(expandScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;void&gt;): void

Stops extended mode. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 10 and deprecated since API version 20.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description                                     |
| ------------ | --------------------------- | --- |-----------------------------------------|
| expandScreen | Array&lt;number&gt;         | Yes  | IDs of the extended screens. Each ID is an integer. The size of the **expandScreen** array cannot exceed 1000. |
| callback     | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If extended mode is stopped, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let expandScreenIds: Array<number> = [1, 2, 3];
screen.stopExpand(expandScreenIds, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to stop expand screens. Code:${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in stopping expand screens.');
});
```

## screen.stopExpand<sup>(deprecated)</sup>

stopExpand(expandScreen:Array&lt;number&gt;): Promise&lt;void&gt;

Stops extended mode. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 10 and deprecated since API version 20.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------------ | ------------------- | --- |--------------------|
| expandScreen | Array&lt;number&gt; | Yes  | IDs of the extended screens. Each ID is an integer. The size of the expandScreen array cannot exceed 1000.|

**Return value**

| Type| Description|
| --------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400001 | Invalid display or screen. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let expandScreenIds: Array<number> = [1, 2, 3];
screen.stopExpand(expandScreenIds).then(() => {
  console.info('Succeeded in stopping expand screens.');
}).catch((err: BusinessError) => {
  console.error(`Failed to stop expand screens. Code:${err.code}, message is ${err.message}`);
});
```

## ExpandOption

Defines the parameters for expanding a screen.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name    | Type| Read-Only| Optional| Description               |
| -------- | -------- | ---- | ---- | ------------------- |
| screenId | number   | No  | No  | Screen ID. The value must be an integer.         |
| startX   | number   | No  | No  | Start X coordinate of the screen. The value must be an integer.|
| startY   | number   | No  | No  | Start Y coordinate of the screen. The value must be an integer.|

## MultiScreenMode<sup>13+</sup>

Enumerates the display modes of secondary screens.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name             | Value | Description                           |
| ------------------ | ---- | -------------------------------- |
| SCREEN_MIRROR      | 0    | Mirror mode.|
| SCREEN_EXTEND      | 1    | Extend mode.|

## MultiScreenPositionOptions<sup>13+</sup>

Describes the screen position information.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name   | Type    | Read-Only| Optional | Description               |
| -------- | -------- | ---- | ---- | ------------------- |
| id       | number   | No  | No  | Screen ID. The value must be a positive integer. Any non-positive integer values will be considered invalid and result in an error.|
| startX   | number   | No  | No  | Start X coordinate of the screen. The top-left vertex of the bounding rectangle formed by the two screens is used as the origin, with the positive direction being rightwards. The value must be a positive integer. Any non-positive integer values will be considered invalid and result in an error.|
| startY   | number   | No  | No  | Start Y coordinate of the screen. The top-left vertex of the bounding rectangle formed by the two screens is used as the origin, with the positive direction being downwards. The value must be a positive integer. Any non-positive integer values will be considered invalid and result in an error.|

## VirtualScreenOption

Defines virtual screen parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type| Read-Only| Optional| Description                      |
| --------- | -------- | ---- | ---- |--------------------------|
| name      | string   | No  | No  | Name of a virtual screen.              |
| width     | number   | No  | No  | Width of the virtual screen, in px. The value must be an integer.|
| height    | number   | No  | No  | Height of the virtual screen, in px. The value must be an integer.|
| density   | number   | No  | No  | Density of the virtual screen, in px. The value must be a floating-point number.|
| surfaceId | string   | No  | No  | Surface ID of the virtual screen.       |

## Screen

Implements a Screen instance.

Before calling any API in Screen, you must use [getAllScreens()](#screengetallscreens) or [createVirtualScreen()](#screencreatevirtualscreen) to obtain a Screen instance.

### Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core


| Name             | Type                                      | Read-Only| Optional| Description                                                         |
| ----------------- | ---------------------------------------------- | ---- | ---- |-------------------------------------------------------------|
| id                | number                                         | Yes  | No  | Screen ID, which is an integer.                          |
| rsId<sup>21+</sup> |number | Yes| No| Screen port ID, which is an integer.|
| parent            | number                                         | Yes  | No  | ID of the group to which a screen belongs, where the ID is an integer.            |
| supportedModeInfo | Array&lt;[ScreenModeInfo](#screenmodeinfo)&gt; | Yes  | No  | Mode set supported by the screen.  |
| activeModeIndex   | number                                         | Yes  | No  | Index of the active screen mode. The current value and value range of this parameter vary according to the screen resolution, refresh rate, and device hardware. The value is an integer.|
| orientation       | [Orientation](#orientation)                     | Yes  | No  | Screen orientation.      |
| sourceMode<sup>10+</sup> | [ScreenSourceMode](#screensourcemode10)            | Yes  | No  | Source mode of the screen.    |
| serialNumber<sup>15+</sup> | string        | Yes  | Yes  | Serial number of the extended screen. By default, the value is an empty string.<br> **Device behavior differences**: This API can be called on 2-in-1 devices but is unavailable for other devices. |       

### setOrientation

setOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

Sets the screen orientation. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| orientation | [Orientation](#orientation) | Yes  | Screen orientation. The value must be an enumerated value of **Orientation**.               |
| callback    | AsyncCallback&lt;void&gt;   | Yes  | Callback used to return the result. If the screen orientation is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  screenClass.setOrientation(screen.Orientation.VERTICAL, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the vertical orientation. Code:${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the vertical orientation.');
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

### setOrientation

setOrientation(orientation: Orientation): Promise&lt;void&gt;

Sets the screen orientation. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                       | Mandatory| Description      |
| ----------- | --------------------------- | ---- | ---------- |
| orientation | [Orientation](#orientation) | Yes  | Screen orientation. The value must be an enumerated value of **Orientation**.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  let promise: Promise<void> = screenClass.setOrientation(screen.Orientation.VERTICAL);
  promise.then(() => {
    console.info('Succeeded in setting the vertical orientation.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the vertical orientation. Code:${err.code}, message is ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

### setScreenActiveMode

setScreenActiveMode(modeIndex: number, callback: AsyncCallback&lt;void&gt;): void

Sets the active mode of the screen. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| modeIndex | number                    | Yes  | Index of the mode to set. The current value and value range of this parameter vary according to the screen resolution, refresh rate, and device hardware. The value must be an integer. The index is the mode ID in the [ScreenModeInfo](#screenmodeinfo) property of the screen.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the active mode is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  let modeIndex: number = 0;
  screenClass.setScreenActiveMode(modeIndex, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set screen active mode 0. Code:${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the screen active mode 0.');
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

### setScreenActiveMode

setScreenActiveMode(modeIndex: number): Promise&lt;void&gt;

Sets the active mode of the screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type  | Mandatory| Description      |
| --------- | ------ | ---- | ---------- |
| modeIndex | number | Yes  | Index of the mode to set. The current value and value range of this parameter vary according to the screen resolution, refresh rate, and device hardware. The value must be an integer.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  let modeIndex: number = 0;
  let promise: Promise<void> = screenClass.setScreenActiveMode(modeIndex);
  promise.then(() => {
    console.info('Succeeded in setting screen active mode 0.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set screen active mode 0.Code:${err.code}, message is ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

### setDensityDpi

setDensityDpi(densityDpi: number, callback: AsyncCallback&lt;void&gt;): void;

Sets the pixel density of the screen. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type                     | Mandatory| Description                                      |
| ---------- | ------------------------- | ---- |------------------------------------------|
| densityDpi | number                    | Yes  | Pixel density. The value must be an integer in the range [80, 640].      |
| callback   | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the pixel density is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let densityDpi: number = 320;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  screenClass.setDensityDpi(densityDpi, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the pixel density of the screen to 320. Code:${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the density dpi.');
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

### setDensityDpi

setDensityDpi(densityDpi: number): Promise&lt;void&gt;

Sets the pixel density of the screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                |
| ---------- | ------ | ---- |------------------------------------|
| densityDpi | number | Yes  | Pixel density. The value must be an integer in the range [80, 640].|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let densityDpi: number = 320;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let option : VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  let promise: Promise<void> = screenClass.setDensityDpi(densityDpi);
  promise.then(() => {
    console.info('Succeeded in setting the pixel density of the screen to 320.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the pixel density of the screen to 320. Code:${err.code}, message is ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code}, message is ${err.message}`);
});
```

## Orientation

Enumerates the screen orientations.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Value  | Description                            |
| ------------------ | ---- | -------------------------------- |
| UNSPECIFIED        | 0    | Unspecified. The screen orientation is determined by the system.|
| VERTICAL           | 1    | Vertical.        |
| HORIZONTAL         | 2    | Horizontal.        |
| REVERSE_VERTICAL   | 3    | Reverse vertical.    |
| REVERSE_HORIZONTAL | 4    | Reverse horizontal.    |

## ScreenSourceMode<sup>10+</sup>

Enumerates the sources of the content displayed on the screen.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name              | Value  | Description                            |
| ------------------ | ---- | -------------------------------- |
| SCREEN_MAIN         | 0    | Content from the primary screen (default).|
| SCREEN_MIRROR       | 1    | Content from a mirror screen.        |
| SCREEN_EXTEND       | 2    | Content from an extended screen.        |
| SCREEN_ALONE        | 3    | The source is unspecified.    |

## ScreenModeInfo

Defines the screen mode information.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name       | Type| Read-Only| Optional| Description                                              |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| id          | number   | No  | No  | Mode ID. The supported mode is determined by the device resolution and refresh rate. The value is an integer.| 
| width       | number   | No  | No  | Width of the screen, in px. The value is an integer.                               |
| height      | number   | No  | No  | Height of the screen, in px. The value is an integer.                               |
| refreshRate | number   | No  | No  | Refresh rate of the screen, in hz. The value is an integer.                                    |

## Rect<sup>19+</sup>

Describes the rectangle information.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name       | Type| Read-Only| Optional| Description                                              |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| left    | number   | No  | No  | X coordinate of the vertex in the top-left corner of the rectangle, in px. The value must be an integer.|
| top     | number   | No  | No  | Y coordinate of the vertex in the top-left corner of the rectangle, in px. The value must be an integer.|
| width   | number   | No  | No  | Width of the rectangle, in px. The value must be an integer.            |
| height  | number   | No  | No  | Height of the rectangle, in px. The value must be an integer.            |
