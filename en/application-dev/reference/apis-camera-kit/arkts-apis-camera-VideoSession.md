# Interface (VideoSession)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

VideoSession inherits from [Session](arkts-apis-camera-Session.md), [Flash](arkts-apis-camera-Flash.md), [AutoExposure](arkts-apis-camera-AutoExposure.md), [WhiteBalance](arkts-apis-camera-WhiteBalance.md), [Focus](arkts-apis-camera-Focus.md), [Zoom](arkts-apis-camera-Zoom.md), [Stabilization](arkts-apis-camera-Stabilization.md), [ColorManagement](arkts-apis-camera-ColorManagement.md), [AutoDeviceSwitch](arkts-apis-camera-AutoDeviceSwitch.md), [Macro](arkts-apis-camera-Macro.md), and [ControlCenter](arkts-apis-camera-ControlCenter.md).

It implements a video session, which provides operations on the flash, exposure, white balance, focus, zoom, video stabilization, color space, macro mode, and controller.

> **NOTE**
>
> VideoSession is provided for the default video recording mode. It applies to common scenarios. It supports recording at various resolutions (such as 720p and 1080p) and frame rates (such as 30 fps and 60 fps).

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
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | No  | Aspect ratio. The default value is 16:9.|

**Return value**

| Type     | Description                                     |
|---------|-----------------------------------------|
| boolean | **true**: The preconfigured resolution is supported.<br>**false**: The preconfigured resolution is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function testCanPreconfig(videoSession: camera.VideoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    let result = videoSession.canPreconfig(preconfigType, preconfigRatio);
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
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | No  | Aspect ratio. The default value is 16:9.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function testPreconfig(videoSession: camera.VideoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    videoSession.preconfig(preconfigType, preconfigRatio);
    console.info(`preconfig ${preconfigType} ${preconfigRatio} success`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The preconfig call failed. error code: ${err.code}`);
  }
}
```

## on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to VideoSession error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type             | Mandatory| Description                          |
| -------- | ------------------ | ---- | ------------------------------ |
| type     | string             | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](arkts-apis-camera-Session.md#beginconfig11), [commitConfig](arkts-apis-camera-Session.md#commitconfig11), and [addInput](arkts-apis-camera-Session.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)      | Yes  | Callback used to return an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode).  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Video session error code: ${err.code}`);
}

function registerSessionError(videoSession: camera.VideoSession): void {
  videoSession.on('error', callback);
}
```

## off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from VideoSession error events. This API uses a callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                         | Mandatory| Description                          |
| -------- | --------------------------- | ---- | ------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSessionError(videoSession: camera.VideoSession): void {
  videoSession.off('error');
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
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
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

function registerFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.on('focusStateChange', callback);
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
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | No | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.off('focusStateChange');
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

function registerSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.on('smoothZoomInfoAvailable', callback);
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
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('smoothZoomInfoAvailable');
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

| Name    | Type                                                                  | Mandatory| Description                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'autoDeviceSwitchStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](arkts-apis-camera-i.md#autodeviceswitchstatus13)\> | Yes  | Callback function, which is used to obtain the status of automatic camera switch. |

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

function registerAutoDeviceSwitchStatus(videoSession: camera.VideoSession): void {
  videoSession.on('autoDeviceSwitchStatusChange', callback);
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
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('autoDeviceSwitchStatusChange');
}
```

## setQualityPrioritization<sup>14+</sup>

setQualityPrioritization(quality : QualityPrioritization) : void;

Sets the priority level for video recording quality.

> **NOTE**
> The default value is **HIGH_QUALITY**. Switching to **POWER_BALANCE** will compromise video recording quality to achieve lower power usage. The extent of power conservation achieved varies depending on the platform.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name | Type                                             | Mandatory| Description                                      |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------ |
| quality | [QualityPrioritization](arkts-apis-camera-e.md#qualityprioritization14) | Yes  | Priority level to set. The default value is **HIGH_QUALITY**.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                                                                                                                                       |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 7400103  | Session not config. The session has not been committed or configured.                                                                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setQualityPrioritization(videoSession: camera.VideoSession): void {
  try {
    videoSession.setQualityPrioritization(camera.QualityPrioritization.POWER_BALANCE);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setQualityPrioritization call failed. error code: ${err.code}`);
  }
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
|callback | AsyncCallback\<[SystemPressureLevel](arkts-apis-camera-e.md#systempressurelevel20)\> | Yes| Callback used to return the current system pressure level.|

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

function registerSystemPressureLevelChangeCallback(videoSession: camera.VideoSession): void {
    videoSession.on('systemPressureLevelChange', callback);
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
function unregisterSystemPressureLevelChangeCallback(videoSession: camera.VideoSession): void {
  videoSession.off('systemPressureLevelChange');
}
```

## on('controlCenterEffectStatusChange')<sup>20+</sup>

on(type: 'controlCenterEffectStatusChange', callback: AsyncCallback\<ControlCenterStatusInfo\>): void

Subscribes to events indicating that the camera controller effect status changes. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type| Mandatory| Description|
|----------|-------|----|------------------------------------------------------------------------|
| type     | string | Yes| Event type. The value is fixed at **'controlCenterEffectStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[ControlCenterStatusInfo](arkts-apis-camera-i.md#controlcenterstatusinfo20)\> | Yes| Callback used to return the effect status of the current controller.|

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, status: camera.ControlCenterStatusInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`controlCenterEffectStatusChange: ${status}`);
}

function registerControlCenterEffectStatusChangeCallback(videoSession: camera.VideoSession): void {
  videoSession.on('controlCenterEffectStatusChange', callback);
}
```

## off('controlCenterEffectStatusChange')<sup>20+</sup>

off(type: 'controlCenterEffectStatusChange', callback?: AsyncCallback\<ControlCenterStatusInfo\>): void

Unsubscribes from events indicating that the camera controller effect status changes.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type| Mandatory| Description|
|----------|-------|----|------------------------------------------------------------------------|
| type     | string | Yes| Event type. The value is fixed at **'controlCenterEffectStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[ControlCenterStatusInfo](arkts-apis-camera-i.md#controlcenterstatusinfo20)\> | No| Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterControlCenterEffectStatusChange(videoSession: camera.VideoSession): void {
  videoSession.off('controlCenterEffectStatusChange');
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

function registerMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.on('macroStatusChanged', callback);
}
```

## off('macroStatusChanged')<sup>20+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from macro state change events.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                    | Mandatory| Description                                                                    |
| -------- | ------------------------ | ---- |------------------------------------------------------------------------|
| type     | string                   | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.                     |
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|


**Example**

```ts
function unregisterMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.off('macroStatusChanged');
}
```
