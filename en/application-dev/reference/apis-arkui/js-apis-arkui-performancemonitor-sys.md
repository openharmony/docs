# @ohos.arkui.performanceMonitor (Performance Monitoring) (System API)

The **performanceMonitor** module provides APIs for monitoring performance metrics related to user scenes. By calling the **begin** and **end** APIs at the start and end of a scene respectively, you can obtain relevant performance metrics such as response latency, completion latency, and frame drops.

> **NOTE**
>
> The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.


## Modules to Import

```ts
import { performanceMonitor } from '@kit.ArkUI';
```


## ActionType

Enumerates the trigger modes for user scenes (typically scenes involving animations).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -- | -- | -- |
| LAST_DOWN | 0 | Pressing against the screen. |
| LAST_UP | 1 | Lifting a finger off the screen.|
| FIRST_MOVE | 2 | First swiping on the screen.|


## SourceType<sup>12+</sup>

Enumerates the trigger source types of user scenes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -- | -- | -- |
| PERF_TOUCH_EVENT | 0 | Touchscreen event.|
| PERF_MOUSE_EVENT | 1 | Mouse event.|
| PERF_TOUCHPAD_EVENT | 2 | Touchpad event.|
| PERF_JOYSTICK_EVENT | 3 | Joystick event.|
| PERF_KEY_EVENT | 4 | Keyboard event.|


## performanceMonitor.begin

begin(scene: string, startInputType: ActionType, note?: string): void

Marks the start of a user scene. Call this API when the scene begins.


**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| scene | string | Yes| User scene ID. <br>Length limit: 50 characters.<br>Recommended format: uppercase letters with underscores (_), for example, **LAUNCHER_APP_LAUNCH_FROM_ICON**.|
| startInputType | [ActionType](#actiontype)| Yes| Trigger mode of the user scene.|
| note | string| No| Remarks for the user scene. <br>Length limit: 30 characters.<br>If this parameter is omitted, performance metrics will not include remarks.|

**Example**

Start point of the user scene where the user taps an icon to launch an application, triggered by a release event (**LAST_UP**).
  ```ts
performanceMonitor.begin("LAUNCHER_APP_LAUNCH_FROM_ICON", performanceMonitor.ActionType.LAST_UP, "APP_START_BEGIN");
  ```


## performanceMonitor.end

end(scene: string): void

Marks the end of a user scene. Call this API when the scene ends.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| scene | string | Yes| User scene ID, which must be strictly consistent with that in **begin**; otherwise, the monitoring will be invalid.|

**Example**

End point of the user scene where the user taps an icon to launch an application.
  ```ts
performanceMonitor.end("LAUNCHER_APP_LAUNCH_FROM_ICON");
  ```

## performanceMonitor.recordInputEventTime<sup>12+</sup>

recordInputEventTime(type: ActionType, sourceType: SourceType, time: number): void

Records the trigger event type and time before the start of the animation scene.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name| Type| Mandatory| Description|
| -- | -- | -- | -- |
| type | [ActionType](#actiontype)| Yes| Trigger mode of the user scene.|
| sourceType | [SourceType](#sourcetype12) | Yes| Trigger source of the user scene.|
| time | number | Yes| Trigger time (ms) of the user scene, represented as a 13-digit timestamp, for example, **1751508570794**. Incorrect parameters may cause abnormal response latency metrics. Negative values will be automatically converted to the current system time, while positive values will be used as-is.|

**Example**

```ts
import { systemDateTime, BusinessError } from '@kit.BasicServicesKit';
import { performanceMonitor } from '@kit.ArkUI';

// Obtain the current system time.
let time = systemDateTime.getTime(false);
// Update the user trigger event type and time.
performanceMonitor.recordInputEventTime(performanceMonitor.ActionType.LAST_UP, performanceMonitor.SourceType.PERF_MOUSE_EVENT, time);
```
