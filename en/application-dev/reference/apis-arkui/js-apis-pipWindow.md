# @ohos.PiPWindow (PiP Window)

The **PiPWindow** module provides basic APIs for manipulating Picture in Picture (PiP). For example, you can use the APIs to check whether the PiP feature is enabled and create a PiP controller to start or stop a PiP window. PiP is mainly used in video playback, video call, or video meeting scenarios.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> This module must be used on the device that supports the **SystemCapability.Window.SessionManager** capability.<!--RP1--> For details, see [SystemCapability](../syscap.md).<!--RP1End-->

## Modules to Import

```ts
import { PiPWindow } from '@kit.ArkUI';
```

## PiPWindow.isPiPEnabled

isPiPEnabled(): boolean

Checks whether the PiP feature is enabled.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type      | Description                                 |
|----------|-------------------------------------|
| boolean  | Status of the PiP feature. The value **true** means that the PiP feature is enabled, and **false** means the opposite. |

**Example**

```ts
let enable: boolean = PiPWindow.isPiPEnabled();
console.info('isPipEnabled:' + enable);
```

## PiPWindow.create

create(config: PiPConfiguration): Promise&lt;PiPController&gt;

Creates a PiP controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                                      | Mandatory       | Description                                                                                                                                                                                                                                    |
|--------------|------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| config       | [PiPConfiguration](#pipconfiguration)    | Yes        | Options for creating the PiP controller. This parameter cannot be empty, and **context** and **componentController** that are used to construct this parameter cannot be empty. When constructing this parameter, **templateType** (if specified) must be a value defined in [PiPTemplateType](#piptemplatetype), and **controlGroups** (if specified) must match the value of **templateType**. For details, see [PiPControlGroup](#pipcontrolgroup12). |

**Return value**

| Type                                                        | Description                      |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller)&gt;  | Promise used to return the PiP controller. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                                                                                                        |
|-------|----------------------------------------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let pipController: PiPWindow.PiPController | undefined = undefined;
let mXComponentController: XComponentController = new XComponentController(); // Use the mXComponentController to initialize the XComponent: XComponent( {id: 'video', type: 'surface', controller: mXComponentController} ). This ensures that the XComponent content can be migrated to the PiP window.
let navId: string = "page_1"; // The navigation ID of the current page is page_1. For details, see the definition of PiPConfiguration. The navigation name is customized.
let contentWidth: number = 800; // The content width is 800 px.
let contentHeight: number = 600; // The content height is 600 px.
let config: PiPWindow.PiPConfiguration = {
  context: getContext(this),
  componentController: mXComponentController,
  navigationId: navId,
  templateType: PiPWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: contentWidth,
  contentHeight: contentHeight,
  controlGroups: [PiPWindow.VideoPlayControlGroup.VIDEO_PREVIOUS_NEXT],
};

let promise : Promise<PiPWindow.PiPController> = PiPWindow.create(config);
promise.then((data : PiPWindow.PiPController) => {
  pipController = data;
  console.info(`Succeeded in creating pip controller. Data:${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create pip controller. Cause:${err.code}, message:${err.message}`);
});
```

## PiPConfiguration

Defines the parameters for creating a PiP controller.

**System capability**: SystemCapability.Window.SessionManager

| Name                 | Type                                                                   | Mandatory | Description                                                                                                                                                                                                                                                                                                                                          |
|---------------------|-----------------------------------------------------------------------|-----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context             | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)               | Yes  | Context environment.                                                                                                                                                                                                                                                                                                                                    |
| componentController | [XComponentController](arkui-ts/ts-basic-components-xcomponent.md) | Yes  | Original [XComponent](../../ui/arkts-common-components-xcomponent.md) controller.                                                                                                                                                                                                                                                                        |
| navigationId        | string                                                                | No  | Navigation ID of the current page.<br>1. When the UIAbility uses [Navigation](arkui-ts/ts-basic-components-navigation.md) to manage pages, set the ID of the **<\Navigation>** component for the PiP controller. This ensures that the original page can be restored from the PiP window.<br>2. When the UIAbility uses [Router](js-apis-router.md) to manage pages, you do not need to set the navigation ID. (This navigation mode is not recommended in PiP scenarios.) After a PiP window is started in this scenario, do not switch between pages. Otherwise, exceptions may occur during restoration.<br>3. If the UIAbility has only one page, you do not need to set the navigation ID. The original page can be restored from the PiP window. |
| templateType        | [PiPTemplateType](#piptemplatetype)                                   | No  | Template type, which is used to distinguish video playback, video call, and video meeting scenarios.                                                                                                                                                                                                                                                                                                                    |
| contentWidth        | number                                                                | No  | Width of the original content, in px. It is used to determine the aspect ratio of the PiP window.                                                                                                                                                                                                                                                                                                                   |
| contentHeight       | number                                                                | No  | Height of the original content, in px. It is used to determine the aspect ratio of the PiP window.                                                                                                                                                                                                                                                                                                                   |
| controlGroups<sup>12+</sup>       | Array<[PiPControlGroup](#pipcontrolgroup12)>                                                                | No  | Describes the optional component groups of the PiP controller. An application can configure whether to display these optional components. If this parameter is not set for an application, the basic controls of the template (for example, the play/pause control of the video playback control group) are displayed. This parameter is supported since API version 12. |

## PiPTemplateType

Enumerates the PIP template types.

**System capability**: SystemCapability.Window.SessionManager

| Name           | Value  | Description                                  |
|---------------|-----|--------------------------------------|
| VIDEO_PLAY    | 0   | Video playback template. A PiP window will be started during video playback, and the video playback template is loaded.  |
| VIDEO_CALL    | 1   | Video call template. A PiP window will be started during a video call, and the video call template will be loaded. |
| VIDEO_MEETING | 2   | Video meeting template. A PiP window will be started during a video meeting, and the video meeting template will be loaded. |
| VIDEO_LIVE    | 3   | Live template. A PiP window will be started during a live, and the live template is loaded.    |

## PiPState

Enumerates the PiP states.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| ABOUT_TO_START       | 1   | PiP is about to start.           |
| STARTED              | 2   | PiP is started.           |
| ABOUT_TO_STOP        | 3   | PiP is about to stop.           |
| STOPPED              | 4   | PiP is stopped.           |
| ABOUT_TO_RESTORE     | 5   | The original page is about to restore. |
| ERROR                | 6   | An error occurs during the execution of the PiP lifecycle.  |

## PiPControlGroup<sup>12+</sup>

type PiPControlGroup = VideoPlayControlGroup | VideoCallControlGroup | VideoMeetingControlGroup

Describes the optional component groups of the PiP controller. An application can configure whether to display these optional components. By default, the controller displays only basic components (such as the play/pause component of the video playback component group).

**System capability**: SystemCapability.Window.SessionManager

| Type                                             | Description         |
|-------------------------------------------------|-------------|
| [VideoPlayControlGroup](#videoplaycontrolgroup12)     | Video playback component group. |
| [VideoCallControlGroup](#videocallcontrolgroup12)       | Video call component group. |
| [VideoMeetingControlGroup](#videomeetingcontrolgroup12) | Video meeting component group. |


## VideoPlayControlGroup<sup>12+</sup>

Enumerates the video playback component groups. It is used only when [PiPTemplateType](#piptemplatetype) is set to **VIDEO_PLAY**.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| VIDEO_PREVIOUS_NEXT       | 101   | Previous/Next component group for video playback.<br>This component group is mutually exclusive with the fast-forward/rewind component group. It cannot be added if the fast-forward/rewind component group is added.          |
| FAST_FORWARD_BACKWARD    | 102   | Fast-forward/Rewind component group for video playback.<br>This component group is mutually exclusive with the previous/next component group. It cannot be added if the previous/next control component group is added.          |

## VideoCallControlGroup<sup>12+</sup>

Enumerates the video call component groups. It is used only when [PiPTemplateType](#piptemplatetype) is set to **VIDEO_CALL**.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| MICROPHONE_SWITCH       | 201   | Microphone on/off component group.           |
| HANG_UP_BUTTON    | 202   | Hang-up component group.          |
| CAMERA_SWITCH    | 203   | Camera on/off component group.           |

## VideoMeetingControlGroup<sup>12+</sup>

Enumerates the video meeting component groups. It is used only when [PiPTemplateType](#piptemplatetype) is set to **VIDEO_MEETING**.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| HANG_UP_BUTTON       | 301   | Hang-up component group.         |
| CAMERA_SWITCH    | 302   | Camera on/off component group.          |
| MUTE_SWITCH    | 303   | Mute/Unmute component group.           |

## PiPActionEventType

type PiPActionEventType = PiPVideoActionEvent | PiPCallActionEvent | PiPMeetingActionEvent | PiPLiveActionEvent

Enumerates the PiP action event types.

**System capability**: SystemCapability.Window.SessionManager

| Type                                             | Description         |
|-------------------------------------------------|-------------|
| [PiPVideoActionEvent](#pipvideoactionevent)     | PiP action event during video playback. |
| [PiPCallActionEvent](#pipcallactionevent)       | PiP action event in a video call. |
| [PiPMeetingActionEvent](#pipmeetingactionevent) | PiP action event in a video meeting. |
| [PiPLiveActionEvent](#pipliveactionevent)       | PiP action event in a live.  |

## PiPVideoActionEvent

type PiPVideoActionEvent = 'playbackStateChanged' | 'nextVideo' | 'previousVideo' | 'fastForward' | 'fastBackward'

Defines the PiP action event during video playback.

**System capability**: SystemCapability.Window.SessionManager

| Type                        | Description                                     |
| ---------------------------- | ----------------------------------------- |
| 'playbackStateChanged'       | The playback status changes.                     |
| 'nextVideo'                  | Plays the next video.                         |
| 'previousVideo'              | Plays the previous video.                         |
| 'fastForward'<sup>12+</sup>  | Fast forwards the video. This value is supported since API version 12. |
| 'fastBackward'<sup>12+</sup> | Rewinds the video. This value is supported since API version 12. |

## PiPCallActionEvent

type PiPCallActionEvent = 'hangUp' | 'micStateChanged' | 'videoStateChanged'

Defines the PiP action event in a video call.

**System capability**: SystemCapability.Window.SessionManager

| Type               | Description              |
| ------------------- | ------------------ |
| 'hangUp             | The video call is hung up.    |
| 'micStateChanged'   | The microphone is muted or unmuted. |
| 'videoStateChanged' | The camera is turned on or off. |



## PiPMeetingActionEvent

type PiPMeetingActionEvent = 'hangUp' | 'voiceStateChanged' | 'videoStateChanged'

Defines the PiP action event in a video meeting.

**System capability**: SystemCapability.Window.SessionManager

| Type               | Description              |
| ------------------- | ------------------ |
| 'hangUp'            | The video meeting is hung up.    |
| 'voiceStateChanged' | The speaker is muted or unmuted.  |
| 'videoStateChanged' | The camera is turned on or off. |



## PiPLiveActionEvent

type PiPLiveActionEvent = 'playbackStateChanged'

Defines the PiP action event in a live.

**System capability**: SystemCapability.Window.SessionManager

| Type                  | Description            |
| ---------------------- | ---------------- |
| 'playbackStateChanged' | The live is played or paused. |



## ControlPanelActionEventCallback<sup>12+</sup>

type ControlPanelActionEventCallback = (event: PiPActionEventType, status?: number) => void

Describes the action event callback of the PiP controller.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name                      | Type          | Mandatory   | Description                               |
|--------------------------|--------------|--------------|-----------------------------------|
| event       |  [PiPActionEventType](#pipactioneventtype)       | Yes | Action event callback, which includes the following information:<br>The application performs processing based on the event. For example, if the **'playbackStateChanged'** event is triggered, the application starts or stops the video. |
| status | number | No | Status of a component that can be switched. For example, for a microphone on/off component group, a camera on/off component group, and a mute/unmute component group, the value **1** means that the component is enabled and **0** means that the component is disabled. For other components, the default value **-1** is used. |

## PiPController

Implements a PiP controller that starts, stops, or updates a PiP window and registers callbacks.

Before calling any of the following APIs, you must use [PiPWindow.create()](#pipwindowcreate) to create a **PiPController** instance.

**System capability**: SystemCapability.Window.SessionManager

### startPiP

startPiP(): Promise&lt;void&gt;

Starts a PiP window. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                    | Description                |
|------------------------|--------------------|
| Promise&lt;void&gt;    | Promise that returns no value.  |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID   | Error Message                                               |
|------------|--------------------------------------------------------|
| 1300012    | The PiP window state is abnormal.                      |
| 1300013    | Failed to create the PiP window.                       |
| 1300014    | PiP internal error.                                    |
| 1300015    | Repeated PiP operation.                                |

**Example**

```ts
let promise : Promise<void> = pipController.startPiP();
promise.then(() => {
  console.info(`Succeeded in starting pip.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to start pip. Cause:${err.code}, message:${err.message}`);
});
```

### stopPiP

stopPiP(): Promise&lt;void&gt;

Stops a PiP window. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                  | Description                 |
|----------------------|---------------------|
| Promise&lt;void&gt;  | Promise that returns no value.   |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID  | Error Message                         |
|---------|-----------------------------------|
| 1300011 | Failed to destroy the PiP window. |
| 1300012 | The PiP window state is abnormal. |
| 1300015 | Repeated PiP operation.           |

**Example**

```ts
let promise : Promise<void> = pipController.stopPiP();
promise.then(() => {
  console.info(`Succeeded in stopping pip.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to stop pip. Cause:${err.code}, message:${err.message}`);
});
```

### setAutoStartEnabled

setAutoStartEnabled(enable: boolean): void

Sets whether to automatically start a PiP window when the user returns to the home screen.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type       | Mandatory   | Description                             |
|----------|-----------|-------|---------------------------------|
| enable   | boolean   | Yes    | Whether to automatically start a PiP window when the user returns to the home screen. The value **true** means to automatically start a PiP window in such a case, and **false** means the opposite. If the automatic PiP startup feature is disabled in Settings, a PiP window will not be automatically started in such a case even if this parameter is set to **true**. |

**Example**

```ts
let enable: boolean = true;
pipController.setAutoStartEnabled(enable);
```

### updateContentSize

updateContentSize(width: number, height: number): void

Updates the media content size when the media content is switched.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type    | Mandatory | Description                                    |
|--------|--------|-----|----------------------------------------|
| width  | number | Yes  | Width of the media content, in px. The value must be a number greater than 0. It is used to update the aspect ratio of the PiP window. |
| height | number | Yes  | Height of the media content, in px. The value must be a number greater than 0. It is used to update the aspect ratio of the PiP window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                                                                       |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
let width: number = 540; // The content width changes to 540 px.
let height: number = 960; // The content height changes to 960 px.
pipController.updateContentSize(width, height);
```

### on('stateChange')

on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void

Subscribes to PiP state events.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name       | Type       | Mandatory  | Description                                                                                               |
|------------|-----------|------|---------------------------------------------------------------------------------------------------|
| type       | string    | Yes   | Event type. The event **'stateChange'** is triggered when the PiP state changes.                                                            |
| callback   | function  | Yes   | Callback used to return the result, which includes the following information:<br>- **state**: [PiPState](#pipstate), indicating the new PiP state.<br>- **reason**: a string indicating the reason for the state change.  |

**Example**

```ts
pipController.on('stateChange', (state: PiPWindow.PiPState, reason: string) => {
  let curState: string = '';
  switch (state) {
    case PiPWindow.PiPState.ABOUT_TO_START:
      curState = 'ABOUT_TO_START';
      break;
    case PiPWindow.PiPState.STARTED:
      curState = 'STARTED';
      break;
    case PiPWindow.PiPState.ABOUT_TO_STOP:
      curState = 'ABOUT_TO_STOP';
      break;
    case PiPWindow.PiPState.STOPPED:
      curState = 'STOPPED';
      break;
    case PiPWindow.PiPState.ABOUT_TO_RESTORE:
      curState = 'ABOUT_TO_RESTORE';
      break;
    case PiPWindow.PiPState.ERROR:
      curState = 'ERROR';
      break;
    default:
      break;
  }
  console.info('stateChange:' + curState + ' reason:' + reason);
});
```

### off('stateChange')

off(type: 'stateChange'): void

Unsubscribes from PiP state events.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name      | Type           | Mandatory   | Description                                    |
|-----------|---------------|-------|----------------------------------------|
| type      | string        | Yes    | Event type. The event **'stateChange'** is triggered when the PiP state changes. |

**Example**

```ts
pipController.off('stateChange');
```

### on('controlPanelActionEvent')

on(type: 'controlPanelActionEvent', callback: ControlPanelActionEventCallback): void

Subscribes to PiP action events.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type        | Mandatory   | Description                                                                                                                            |
|----------|------------|-------|--------------------------------------------------------------------------------------------------------------------------------|
| type     | string     | Yes    | Event type. The value **'controlPanelActionEvent'** indicates the PiP action event.                                                                                   |
| callback | [ControlPanelActionEventCallback](#controlpanelactioneventcallback12)  | Yes    | Action event callback of the PiP controller. |

**Example**

```ts
pipController.on('controlPanelActionEvent', (event: PiPWindow.PiPActionEventType, status?: number) => {
  switch (event) {
    case 'playbackStateChanged':
      if (status === 0) {
        // Stop the video.
      } else if (status === 1) {
        // Play the video.
      }
      break;
    case 'nextVideo':
      // Switch to the next video.
      break;
    case 'previousVideo':
      // Switch to the previous video.
      break;
    case 'fastForward':
      // Fast forward the video.
      break;
    case 'fastBackward':
      // Rewind the video.
      break;
    default:
      break;
  }
  console.info('registerActionEventCallback, event:' + event);
});
```

### off('controlPanelActionEvent')

off(type: 'controlPanelActionEvent'): void

Unsubscribes from PiP action events.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name       | Type                          | Mandatory  | Description                                           |
|------------|------------------------------|------|-----------------------------------------------|
| type       | string                       | Yes   | Event type. The value **'controlPanelActionEvent'** indicates the PiP action event.  |

**Example**

```ts
pipController.off('controlPanelActionEvent');
```
