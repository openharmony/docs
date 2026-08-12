# Interface (PhotoSession)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-11T01:59:51.789Z pushedAt=2026-08-11T11:02:00.811Z -->

**PhotoSession** inherits from [Session](arkts-apis-camera-Session.md), [Flash](arkts-apis-camera-Flash.md), [AutoExposure](arkts-apis-camera-AutoExposure.md), [WhiteBalance](arkts-apis-camera-WhiteBalance.md), [Focus](arkts-apis-camera-Focus.md), [Zoom](arkts-apis-camera-Zoom.md), [ColorManagement](arkts-apis-camera-ColorManagement.md), [AutoDeviceSwitch](arkts-apis-camera-AutoDeviceSwitch.md), [Macro](arkts-apis-camera-Macro.md), [ManualExposure](arkts-apis-camera-ManualExposure.md), [ManualFocus](arkts-apis-camera-ManualFocus.md), [ManualIso](arkts-apis-camera-ManualIso.md), [OIS](arkts-apis-camera-OIS.md), and [Aperture](arkts-apis-camera-Aperture.md).

It implements a photo session, which provides operations on the flash, exposure, white balance, focus, zoom, color space, macro mode, manual exposure, manual focus, manual ISO setting, optical image stabilization (OIS), and aperture.

**PhotoSession** is provided for the default photo mode. It is used to take standard photos. It supports multiple photo formats and resolutions, which are suitable for most daily photo capture scenarios.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## canPreconfig<sup>12+</sup>

canPreconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): boolean

Checks whether this session supports a preconfigured resolution.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name           | Type                                 | Mandatory | Description             |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](arkts-apis-camera-e.md#preconfigtype12)   | Yes  | Resolution type.     |
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | No  | Aspect ratio. The default value is 4:3. |

**Return value**

| Type     | Description                                     |
|---------|-----------------------------------------|
| boolean | Whether a preconfigured resolution is supported. **true** if supported, **false** otherwise.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function testCanPreconfig(photoSession: camera.PhotoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    let result = photoSession.canPreconfig(preconfigType, preconfigRatio);
    console.info(`canPreconfig ${preconfigType} ${preconfigRatio} result is : ${result}`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The canPreconfig call failed. error code: ${err.code}`);
  }
}
```

## preconfig<sup>12+</sup>

preconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): void

Preconfigures this session.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name           | Type                                 | Mandatory | Description             |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](arkts-apis-camera-e.md#preconfigtype12)   | Yes  | Resolution type.     |
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | No  | Aspect ratio. The default value is 4:3. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function testPreconfig(photoSession: camera.PhotoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    photoSession.preconfig(preconfigType, preconfigRatio);
    console.info(`preconfig success preconfigType: ${preconfigType}, preconfigRatio: ${preconfigRatio}`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The preconfig call failed. error code: ${err.code}`);
  }
}
```

## on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PhotoSession** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](arkts-apis-camera-Session.md#beginconfig11), [commitConfig](arkts-apis-camera-Session.md#commitconfig11), and [addInput](arkts-apis-camera-Session.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Photo session error code: ${err.code}`);
}

function registerSessionError(photoSession: camera.PhotoSession): void {
  photoSession.on('error', callback);
}
```

## off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PhotoSession** error events. This API uses a callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                          |
| -------- | -------------------------------- | ---- | ------------------------------ |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSessionError(photoSession: camera.PhotoSession): void {
  photoSession.off('error');
}
```

## on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in autofocus mode.|
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.on('focusStateChange', callback);
}
```

## off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.off('focusStateChange');
}
```

## on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](arkts-apis-camera-i.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.on('smoothZoomInfoAvailable', callback);
}
```

## off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](arkts-apis-camera-i.md#smoothzoominfo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('smoothZoomInfoAvailable');
}
```

## on('autoDeviceSwitchStatusChange')<sup>13+</sup>

on(type: 'autoDeviceSwitchStatusChange', callback: AsyncCallback\<AutoDeviceSwitchStatus\>): void

Subscribes to automatic camera switch status change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                                  | Mandatory| Description                                                    |
| -------- |----------------------------------------------------------------------| ---- |--------------------------------------------------------|
| type     | string                                                               | Yes  | Event type. The value is fixed at **'autoDeviceSwitchStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](arkts-apis-camera-i.md#autodeviceswitchstatus13)\> | Yes  | Callback function, which is used to obtain the status of automatic camera switch.                                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, autoDeviceSwitchStatus: camera.AutoDeviceSwitchStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isDeviceSwitched: ${autoDeviceSwitchStatus.isDeviceSwitched}, isDeviceCapabilityChanged: ${autoDeviceSwitchStatus.isDeviceCapabilityChanged}`);
}

function registerAutoDeviceSwitchStatus(photoSession: camera.PhotoSession): void {
  photoSession.on('autoDeviceSwitchStatusChange', callback);
}
```

## off('autoDeviceSwitchStatusChange')<sup>13+</sup>

off(type: 'autoDeviceSwitchStatusChange', callback?: AsyncCallback\<AutoDeviceSwitchStatus\>): void

Unsubscribes from automatic camera switch status change events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                          | Mandatory| Description                      |
| -------- |----------------------------------------------| ---- | ------------------------ |
| type     | string                                       | Yes  | Event type. The value is fixed at **'autoDeviceSwitchStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](arkts-apis-camera-i.md#autodeviceswitchstatus13)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('autoDeviceSwitchStatusChange');
}
```

## on('systemPressureLevelChange')<sup>20+</sup>

on(type: 'systemPressureLevelChange', callback: AsyncCallback\<SystemPressureLevel\>): void

Subscribes to system pressure level change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name | Type                                                     | Mandatory| Description                                                             |
|---------|----------------------------------------------------------|------|-------------------------------------------------------------------|
|type     | string                                                   | Yes  | Event type. The value is fixed at **'systemPressureLevelChange'**. The event can be listened for when a session is created.|
|callback | AsyncCallback\<[SystemPressureLevel](arkts-apis-camera-e.md#systempressurelevel20)\> | Yes | Callback used to return the current system pressure level. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, systemPressureLevel: camera.SystemPressureLevel): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`systemPressureLevel: ${systemPressureLevel}`);
}

function registerSystemPressureLevelChangeCallback(photoSession: camera.PhotoSession): void {
    photoSession.on('systemPressureLevelChange', callback);
}
```

## off('systemPressureLevelChange')<sup>20+</sup>

off(type: 'systemPressureLevelChange', callback?: AsyncCallback\<SystemPressureLevel\>): void

Unsubscribes from system pressure level change events.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                          | Mandatory   | Description                                                            |
|----------|--------------------------------|---------|------------------------------------------------------------------|
| type     | string                         | Yes     | Event type. The value is fixed at **'systemPressureLevelChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SystemPressureLevel](arkts-apis-camera-e.md#systempressurelevel20)\> | No| Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSystemPressureLevelChangeCallback(photoSession: camera.PhotoSession): void {
  photoSession.off('systemPressureLevelChange');
}
```

## on('macroStatusChanged')<sup>20+</sup>

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

Subscribes to macro state change events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\>     | Yes  | Callback used to return the macro state. **true** if enabled, **false** otherwise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, macroStatus: boolean): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Macro state: ${macroStatus}`);
}

function registerMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.on('macroStatusChanged', callback);
}
```

## off('macroStatusChanged')<sup>20+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from macro state change events.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                                                                    |
| -------- | ------------------------ | ---- |------------------------------------------------------------------------|
| type     | string                   | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```

## onIsoInfoChange<sup>24+</sup>

onIsoInfoChange(callback: Callback\<IsoInfo\>): void

Subscribes to ISO information change events.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| callback | Callback\<[IsoInfo](arkts-apis-camera-i.md#isoinfo22)\> | Yes  | Callback used to obtain the ISO information.|

**Example**

```ts
function onIsoInfoChange(photoSession: camera.PhotoSession): void {
  photoSession.onIsoInfoChange((isoInfo: camera.IsoInfo) => {
    console.info(`ISO info changed, iso: ${isoInfo.iso}`);
  });
}
```

## offIsoInfoChange<sup>24+</sup>

offIsoInfoChange(callback?: Callback\<IsoInfo\>): void

Unsubscribes from ISO information change events.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| callback | Callback\<[IsoInfo](arkts-apis-camera-i.md#isoinfo22)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function offIsoInfoChange(photoSession: camera.PhotoSession): void {
  photoSession.offIsoInfoChange();
}
```

## onExposureInfoChange<sup>24+</sup>

onExposureInfoChange(callback: Callback\<ExposureInfo\>): void

Subscribes to exposure information change events. After the exposure parameters are modified, the system returns the updated exposure information. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| callback | Callback\<[ExposureInfo](arkts-apis-camera-i.md#exposureinfo24)\> | Yes  | Callback used to obtain the exposure information.|

**Example**

```ts
function onExposureInfoChange(photoSession: camera.PhotoSession): void {
  photoSession.onExposureInfoChange((exposureInfo: camera.ExposureInfo) => {
    console.info(`Exposure info changed, exposureTime: ${exposureInfo.exposureTime}`);
  });
}
```

## offExposureInfoChange<sup>24+</sup>

offExposureInfoChange(callback?: Callback\<ExposureInfo\>): void

Unsubscribes from exposure information change events. If you have subscribed to exposure information change events, cancel the subscription before releasing the camera object. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| callback | Callback\<[ExposureInfo](arkts-apis-camera-i.md#exposureinfo24)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function offExposureInfoChange(photoSession: camera.PhotoSession): void {
  photoSession.offExposureInfoChange();
}
```