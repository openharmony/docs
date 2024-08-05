# @ohos.arkui.performanceMonitor (Performance Monitor) (System API)

The **performanceMonitor** module provides APIs for performance monitoring indicators: response delay, completion delay, and frame loss rate.

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

Enumerates types of actions that trigger user scenes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value | Description |
| -- | -- | -- |
| LAST_DOWN | 0 | Pressing against the screen. |
| LAST_UP | 1 | Lifting a finger off the screen. |
| FIRST_MOVE | 2 | First swiping on the screen. |


## performanceMonitor.begin

begin(scene: string, startInputType: ActionType, note?: string): void

Starts a user scene.


**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 

| Name | Type | Mandatory | Description |
| -- | -- | -- | -- |
| scene | string | Yes | User scene ID. |
| startInputType | [ActionType](#actiontype)| Yes | Type of action that triggers the user scene. |
| note | string| No | Important information about the user scene. |

**Example** 
  ```ts
performanceMonitor.begin("LAUNCHER_APP_LAUNCH_FROM_ICON", performanceMonitor.ActionType.LAST_UP, "APP_START_BEGIN");
  ```


## performanceMonitor.end

end(scene: string): void

Ends a user scene.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters** 
| Name | Type | Mandatory | Description |
| -- | -- | -- | -- |
| scene | string | Yes | User scene ID, which corresponds to that in **begin**. |

**Example** 
  ```ts
performanceMonitor.end("LAUNCHER_APP_LAUNCH_FROM_ICON");
  ```
