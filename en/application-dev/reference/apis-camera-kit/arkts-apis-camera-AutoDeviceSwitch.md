# Interface (AutoDeviceSwitch)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 13.

AutoDeviceSwitch extends [AutoDeviceSwitchQuery](arkts-apis-camera-AutoDeviceSwitch.md).

It is used to enable or disable automatic camera switch. This class inherits from [AutoDeviceSwitchQuery](arkts-apis-camera-AutoDeviceSwitch.md).

It is recommended that the system completes input device switch, session configuration, and parameter connection during automatic camera switch. If the system detects that the zoom ranges of the two cameras are different, it notifies the application through the **isDeviceCapabilityChanged** field in [AutoDeviceSwitchStatus](arkts-apis-camera-i.md#autodeviceswitchstatus13). The application needs to process the UX change by itself. For example, if the zoom range is different, the application needs to call [getZoomRatioRange](arkts-apis-camera-ZoomQuery.md#getzoomratiorange11) to obtain data and update the UX. Therefore, this class is more applicable to a simplified UX exchange scenario.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## enableAutoDeviceSwitch<sup>13+</sup>

enableAutoDeviceSwitch(enabled: boolean): void

Enables or disables automatic camera switch. You can use [isAutoDeviceSwitchSupported](arkts-apis-camera-AutoDeviceSwitchQuery.md#isautodeviceswitchsupported13) to check whether the device supports automatic camera switch.

> **NOTE**
>
> This API is used only for foldable devices with multiple front cameras. In different fold states, the system can automatically switch to an available front camera. It does not enable automatic switching between front and rear cameras.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type | Mandatory| Description |
| ----------- |---------------------- |---| -------------------------- |
| enabled | boolean  | Yes| Whether to enable automatic camera switch. **true** to enable, **false** otherwise.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                                                                                                                      |
|---------|------------------------------------------------------------------------------------------------------------------------------------------------|
| 7400101 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameters verification failed. |
| 7400102 | Operation not allowed.                                                                                                                         |
| 7400103 | Session not config.                                                                                                                            |
| 7400201 | Camera service fatal error.                                                                                                                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableAutoDeviceSwitch(session: camera.PhotoSession, isEnable: boolean): void {
  try {
    session.enableAutoDeviceSwitch(isEnable);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The enableAutoDeviceSwitch call failed, error code: ${err.code}`);
  }
}
```
