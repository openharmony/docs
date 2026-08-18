# Interface (AudioRecordingManager)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=2fdda33ed977e9eb00b7b643ab233c994134ccf5 translatedAt=2026-08-10T06:25:11.711Z pushedAt=2026-08-10T07:24:43.897Z -->

Manages recording policies, and provides collaborative recording and recording control capabilities.

Before using the APIs of AudioRecordingManager, you need to first obtain an AudioRecordingManager instance through [getRecordingManager](arkts-apis-audio-AudioManager.md#getrecordingmanager).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 26.0.0.
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## enableSystemRecordController

enableSystemRecordController(show: boolean, config: SystemRecordControllerConfig): Promise&lt;void&gt;

Enables or disables the system recording control panel. This API uses a promise to return the result.

> **NOTE**
>
> - An app can call this API before starting recording to launch the recording control panel in Control Center, allowing users to select a recording device or audio effect parameters, and then start the recording service.
> - If this API is called during recording, switching the recording device or audio effect parameters in the recording control panel will cause inconsistent audio effects in the recording.
> - The app must be in the foreground to enable the panel. If the app is in the background, the enable operation does not take effect. Disabling the panel is not restricted by the application's foreground or background state.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type | Mandatory | Description |
| :--- | :--- | :--- | :--- |
| show | boolean | Yes | Whether to enable the system recording control panel. The value **true** indicates yes, and **false** indicates no. |
| config | [SystemRecordControllerConfig](arkts-apis-audio-i.md#systemrecordcontrollerconfig) | Yes | Configuration information of the system recording control panel. |

**Return value**

| Type | Description |
| :--- | :--- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID | Error Message |
| :--- | :--- |
| 6800101 | Parameter verification failed. |
| 6800301 | Audio service error occurs like service died. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let config: audio.SystemRecordControllerConfig = {
  sourceType: audio.SourceType.SOURCE_TYPE_MIC
};

audioRecordingManager.enableSystemRecordController(true, config).then(() => {
  console.info('Succeeded in enabling system record controller.');
}).catch((err: BusinessError) => {
  console.error(`Failed to enable system record controller. Code: ${err.code}, message: ${err.message}`);
});
```