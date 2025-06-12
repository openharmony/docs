# @ohos.PiPWindow (PiP Window)

The PiPWindow module provides basic APIs for manipulating Picture in Picture (PiP). For example, you can use the APIs to check whether the PiP feature is supported and create a PiP controller to start or stop a PiP window. PiP is mainly used in video playback, video calls, or video meetings.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> This module must be used on the device that supports the **SystemCapability.Window.SessionManager** capability. <!--RP1-->For details, see [SystemCapability](../syscap.md).<!--RP1End-->

## Modules to Import

```ts
import { PiPWindow } from '@kit.ArkUI';
```

## PiPWindow.isPiPEnabled

isPiPEnabled(): boolean

Checks whether the PiP feature is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type      | Description                                 |
|----------|-------------------------------------|
| boolean  | Check result. The value **true** means that the PiP feature is supported, and **false** means the opposite.|

**Example**

```ts
let enable: boolean = PiPWindow.isPiPEnabled();
console.info('isPipEnabled:' + enable);
```

## PiPWindow.create

create(config: PiPConfiguration): Promise&lt;PiPController&gt;

Creates a PiP controller. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                                      | Mandatory       | Description                                                                                                                                                                                                                                    |
|--------------|------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| config       | [PiPConfiguration](#pipconfiguration)    | Yes        | Options for creating the PiP controller. This parameter cannot be empty, and **context** and **componentController** that are used to construct this parameter cannot be empty. When constructing this parameter, **templateType** (if specified) must be a value defined in [PiPTemplateType](#piptemplatetype), and **controlGroups** (if specified) must match the value of **templateType**. For details, see [PiPControlGroup](#pipcontrolgroup12).|

**Return value**

| Type                                                        | Description                      |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller)&gt;  | Promise used to return the PiP controller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                                                        |
|-------|----------------------------------------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { BuilderNode, FrameNode, NodeController, UIContext } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

class Params {
  text: string = '';
  constructor(text: string) {
    this.text = text;
  }
}

// You can use the @Builder decorator to construct layouts.
@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(20)
      .fontColor(Color.Red)
  }
  .width('100%') // The PiP window is displayed at full size in the width direction.
  .height('100%') // The PiP window is displayed at full size in the height direction.
}

// You can extend NodeController to customize the UI controller.
class TextNodeController extends NodeController {
  private message: string;
  private textNode: BuilderNode<[Params]> | null = null;
  constructor(message: string) {
    super();
    this.message = message;
  }

  // Use BuilderNode to load the custom layouts.
  makeNode(context: UIContext): FrameNode | null {
    this.textNode = new BuilderNode(context);
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message));
    return this.textNode.getFrameNode();
  }

  // You can customize this method to update layouts.
  update(message: string) {
    console.log(`update message: ${message}`);
    if (this.textNode !== null) {
      this.textNode.update(new Params(message));
    }
  }
}

let pipController: PiPWindow.PiPController | undefined = undefined;
let mXComponentController: XComponentController = new XComponentController(); // Use the mXComponentController to initialize the XComponent: XComponent( {id: 'video', type: 'surface', controller: mXComponentController} ). This ensures that the XComponent content can be migrated to the PiP window.
let nodeController: TextNodeController = new TextNodeController('this is custom UI');
let navId: string = "page_1"; // The navigation ID of the current page is page_1. For details, see the definition of PiPConfiguration. The navigation name is customized.
let contentWidth: number = 800; // The content width is 800 px.
let contentHeight: number = 600; // The content height is 600 px.
let para: Record<string, number> = { 'PropA': 47 };
let localStorage: LocalStorage = new LocalStorage(para);
let res: boolean = localStorage.setOrCreate('PropB', 121);
let ctx = this.getUIContext().getHostContext() as common.UIAbilityContext; // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let defaultWindowSize: number = 1; // Set the window to be a small window when first pulled up in PiP.
let config: PiPWindow.PiPConfiguration = {
  context: ctx,
  componentController: mXComponentController,
  navigationId: navId,
  templateType: PiPWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: contentWidth,
  contentHeight: contentHeight,
  controlGroups: [PiPWindow.VideoPlayControlGroup.VIDEO_PREVIOUS_NEXT],
  customUIController: nodeController, // Optional. Set this parameter if you want to display the custom UI at the top of the PiP window.
  localStorage: localStorage, // Optional. Set this parameter if you want to track the main window instance.
  defaultWindowSizeType: defaultWindowSize // Optional. If you need to configure the default window size upon launch, set this parameter.
};

let promise: Promise<PiPWindow.PiPController> = PiPWindow.create(config);
promise.then((data: PiPWindow.PiPController) => {
  pipController = data;
  console.info(`Succeeded in creating pip controller. Data:${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create pip controller. Cause:${err.code}, message:${err.message}`);
});
```

## PiPWindow.create<sup>12+</sup>

create(config: PiPConfiguration, contentNode: typeNode.XComponent): Promise&lt;PiPController&gt;

Creates a PiP controller through a type node. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**
 
| Name         | Type                                      | Mandatory       | Description                                                                                                                                                                                                                                    |
|--------------|------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| config       | [PiPConfiguration](#pipconfiguration)    | Yes        | Options for creating the PiP controller. This parameter cannot be empty, and **context** that is used to construct this parameter cannot be empty. When constructing this parameter, **templateType** (if specified) must be a value defined in [PiPTemplateType](#piptemplatetype), and **controlGroups** (if specified) must match the value of **templateType**. For details, see [PiPControlGroup](#pipcontrolgroup12).|
| contentNode       | [typeNode.XComponent](js-apis-arkui-frameNode.md#xcomponent12)    | Yes        | Content to be rendered in the PiP window. The parameter value cannot be empty. |

**Return value**

| Type                                                        | Description                      |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller)&gt;  | Promise used to return the PiP controller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                                                        |
|-------|----------------------------------------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { PiPWindow, typeNode, UIContext } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

let pipController: PiPWindow.PiPController | undefined = undefined;
let xComponentController: XComponentController = new XComponentController();
let ctx = this.getUIContext().getHostContext() as common.UIAbilityContext; // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let options: XComponentOptions = {
  type: XComponentType.SURFACE,
  controller: xComponentController
}
let xComponent = typeNode.createNode(this.getUIContext(), 'XComponent', options);
let contentWidth: number = 800; // The content width is 800 px.
let contentHeight: number = 600; // The content height is 600 px.
let config: PiPWindow.PiPConfiguration = {
  context: ctx,
  componentController: xComponentController,
  templateType: PiPWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: contentWidth,
  contentHeight: contentHeight
};

let promise: Promise<PiPWindow.PiPController> = PiPWindow.create(config, xComponent);
promise.then((data: PiPWindow.PiPController) => {
  pipController = data;
  console.info(`Succeeded in creating pip controller. Data:${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create pip controller. Cause:${err.code}, message:${err.message}`);
});
```

## PiPConfiguration

Defines the parameters for creating a PiP controller.

**System capability**: SystemCapability.Window.SessionManager

| Name                 | Type                                                                        | Mandatory | Description                                                                                                                                                                                                                                                                                                                                       |
|---------------------|----------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context             | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Context environment.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                                                                                                                                                                 |
| componentController | [XComponentController](arkui-ts/ts-basic-components-xcomponent.md#xcomponentcontroller) | Yes  | Original [XComponent](arkui-ts/ts-basic-components-xcomponent.md) controller.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                                                                                                     |
| navigationId        | string                                                                     | No  | Navigation ID of the current page. If no value is passed, the page does not need to be cached.<br>1. When the UIAbility uses [Navigation](arkui-ts/ts-basic-components-navigation.md) to manage pages, set the ID of the **Navigation** component for the PiP controller. This ensures that the original page can be restored from the PiP window.<br>2. When the UIAbility uses [Router](js-apis-router.md) to manage pages, you do not need to set the ID of the **Navigation** component for the PiP controller.<br>3. If the UIAbility has only one page, you do not need to set the navigation ID. The original page can be restored from the PiP window.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| templateType        | [PiPTemplateType](#piptemplatetype)                                        | No  | Template type, which is used to distinguish video playback, video call, and video meeting scenarios. If no value is passed, the video playback template is used.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                                                                                                                                                 |
| contentWidth        | number                                                                     | No  | Width of the original content, in px. It is used to determine the aspect ratio of the PiP window. When the PiP controller is created in [typeNode mode](#pipwindowcreate12), the default value is 1920. When the PiP controller is created [not in typeNode mode](#pipwindowcreate), the default value is the width of the [XComponent](arkui-ts/ts-basic-components-xcomponent.md).<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                |
| contentHeight       | number                                                                     | No  | Height of the original content, in px. It is used to determine the aspect ratio of the PiP window. When the PiP controller is created in [typeNode mode](#pipwindowcreate12), the default value is 1080. When the PiP controller is created [not in typeNode mode](#pipwindowcreate), the default value is the height of the [XComponent](arkui-ts/ts-basic-components-xcomponent.md).<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                |
| controlGroups<sup>12+</sup>       | Array<[PiPControlGroup](#pipcontrolgroup12)>                               | No  | A list of optional component groups of the PiP controller. An application can configure whether to display these optional components. If this parameter is not set for an application, the basic components (for example, play/pause of the video playback component group) are displayed. A maximum of three components can be configured in the list. <br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                                                                                |
| customUIController<sup>12+</sup>      | [NodeController](js-apis-arkui-nodeController.md)           | No  | Custom UI that can be displayed at the top of the PiP window. If no value is passed, custom UI is not used.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                                                                                                                          |
| localStorage<sup>17+</sup>      | [LocalStorage](../../ui/state-management/arkts-localstorage.md)           | No  | A page-level UI state storage unit. In multi-instance scenarios, it can be used to track the UI state storage object of the main window instance. If no value is passed, you cannot retrieve the main window's UI storage object through the PiP window.<br>**Atomic service API**: This API can be used in atomic services since API version 17.                                                                                                                                                                                                                                                                                          |
| defaultWindowSizeType<sup>19+</sup>| number                                                                     | No  |  Size of the window when first pulled up in PiP.<br>The value **0** means that no size is set, and the window will launch at the size it was before being closed in the previous PiP session.<br>The value **1** means a small window, and **2** means a large window.<br>If no value is passed, **0** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 19.                                                                |

## PiPWindowSize<sup>15+</sup>

Describes the size of a PiP window.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Readable| Writable| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | Yes  | No  | Window width, in px. The value must be a positive integer and cannot be greater than the screen width.|
| height | number   | Yes  | No  | Window height, in px. The value must be a positive integer and cannot be greater than the screen height.|
| scale  | number   | Yes  | No  | Scale factor of the window, representing the display size relative to the width and height. The value is a floating point number in the range (0.0, 1.0]. The value **1** means that the window matches the specified width and height.|

## PiPWindowInfo<sup>15+</sup>

Describes the PiP window information.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Readable| Writable| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| windowId  | number   | Yes  | No  | ID of the PiP window.|
| size  | [PiPWindowSize](#pipwindowsize15)  | Yes  | No  | Size of the PiP window.|

## PiPTemplateType

Enumerates the PIP template types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name           | Value  | Description                                  |
|---------------|-----|--------------------------------------|
| VIDEO_PLAY    | 0   | Video playback template. A PiP window will be started during video playback, and the video playback template is loaded.  |
| VIDEO_CALL    | 1   | Video call template. A PiP window will be started during a video call, and the video call template will be loaded.|
| VIDEO_MEETING | 2   | Video meeting template. A PiP window will be started during a video meeting, and the video meeting template will be loaded.|
| VIDEO_LIVE    | 3   | Live template. A PiP window will be started during a live, and the live template is loaded.    |

## PiPState

Enumerates the PiP states.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| ABOUT_TO_START       | 1   | PiP is about to start.           |
| STARTED              | 2   | PiP is started.           |
| ABOUT_TO_STOP        | 3   | PiP is about to stop.           |
| STOPPED              | 4   | PiP is stopped.           |
| ABOUT_TO_RESTORE     | 5   | The original page is about to restore.|
| ERROR                | 6   | An error occurs during the execution of the PiP lifecycle.  |

## PiPControlGroup<sup>12+</sup>

type PiPControlGroup = VideoPlayControlGroup | VideoCallControlGroup | VideoMeetingControlGroup | VideoLiveControlGroup

Describes the optional component groups of the PiP controller. An application can configure whether to display these optional components. By default, the controller displays only basic components (such as the play/pause component of the video playback component group).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Type                                             | Description         |
|-------------------------------------------------|-------------|
| [VideoPlayControlGroup](#videoplaycontrolgroup12)     | Video playback component group.|
| [VideoCallControlGroup](#videocallcontrolgroup12)       | Video call component group.|
| [VideoMeetingControlGroup](#videomeetingcontrolgroup12) | Video meeting component group.|
| [VideoLiveControlGroup](#videolivecontrolgroup12)     | Live video component group.|


## VideoPlayControlGroup<sup>12+</sup>

Enumerates the video playback component groups. They are used only when [PiPTemplateType](#piptemplatetype) is set to **VIDEO_PLAY**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| VIDEO_PREVIOUS_NEXT       | 101   | Previous/Next component group for video playback.<br>This component group is mutually exclusive with the fast-forward/rewind component group. It cannot be added if the fast-forward/rewind component group is added.          |
| FAST_FORWARD_BACKWARD    | 102   | Fast-forward/Rewind component group for video playback.<br>This component group is mutually exclusive with the previous/next component group. It cannot be added if the previous/next component group is added.          |

## VideoCallControlGroup<sup>12+</sup>

Enumerates the video call component groups. They are used only when [PiPTemplateType](#piptemplatetype) is set to **VIDEO_CALL**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| MICROPHONE_SWITCH       | 201   | Microphone on/off component group.           |
| HANG_UP_BUTTON    | 202   | Hang-up component group.          |
| CAMERA_SWITCH    | 203   | Camera on/off component group.           |
| MUTE_SWITCH    | 204   | Mute/Unmute component group.           |

## VideoMeetingControlGroup<sup>12+</sup>

Enumerates the video meeting component groups. They are used only when [PiPTemplateType](#piptemplatetype) is set to **VIDEO_MEETING**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| HANG_UP_BUTTON       | 301   | Hang-up component group.         |
| CAMERA_SWITCH    | 302   | Camera on/off component group.          |
| MUTE_SWITCH    | 303   | Mute/Unmute component group.           |
| MICROPHONE_SWITCH       | 304   | Microphone on/off component group.           |

## VideoLiveControlGroup<sup>12+</sup>

Enumerates the live video component groups. They are used only when [PiPTemplateType](#piptemplatetype) is set to **VIDEO_LIVE**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| VIDEO_PLAY_PAUSE     | 401   |   Play/Pause component group for live video.|
| MUTE_SWITCH         | 402   | Mute/Unmute component group.           |

## PiPActionEventType

type PiPActionEventType = PiPVideoActionEvent | PiPCallActionEvent | PiPMeetingActionEvent | PiPLiveActionEvent

Enumerates the types of action events of the PiP controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Type                                             | Description         |
|-------------------------------------------------|-------------|
| [PiPVideoActionEvent](#pipvideoactionevent)     | Action event for components displayed on the video playback controller.|
| [PiPCallActionEvent](#pipcallactionevent)       | Action event for components displayed on the video call controller.|
| [PiPMeetingActionEvent](#pipmeetingactionevent) | Action event for components displayed on the video meeting controller.|
| [PiPLiveActionEvent](#pipliveactionevent)       | Action event for components displayed on the live video controller.  |

## PiPVideoActionEvent

type PiPVideoActionEvent = 'playbackStateChanged' | 'nextVideo' | 'previousVideo' | 'fastForward' | 'fastBackward'

Defines the PiP action event during video playback.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Type                        | Description                                     |
| ---------------------------- | ----------------------------------------- |
| 'playbackStateChanged'       | The playback status changes.                     |
| 'nextVideo'                  | Plays the next video.                         |
| 'previousVideo'              | Plays the previous video.                         |
| 'fastForward'<sup>12+</sup>  | Fast forwards the video. This value is supported since API version 12.|
| 'fastBackward'<sup>12+</sup> | Rewinds the video. This value is supported since API version 12.|

## PiPCallActionEvent

type PiPCallActionEvent = 'hangUp' | 'micStateChanged' | 'videoStateChanged' | 'voiceStateChanged'

Defines the PiP action event in a video call.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Type               | Description              |
| ------------------- | ------------------ |
| 'hangUp'             | The video call is hung up.    |
| 'micStateChanged'   | The microphone is muted or unmuted.|
| 'videoStateChanged' | The camera is turned on or off.|
| 'voiceStateChanged'<sup>12+</sup> | The speaker is muted or unmuted.  |


## PiPMeetingActionEvent

type PiPMeetingActionEvent = 'hangUp' | 'voiceStateChanged' | 'videoStateChanged' | 'micStateChanged'

Defines the PiP action event in a video meeting.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Type               | Description              |
| ------------------- | ------------------ |
| 'hangUp'            | The video meeting is hung up.    |
| 'voiceStateChanged' | The speaker is muted or unmuted.  |
| 'videoStateChanged' | The camera is turned on or off.|
| 'micStateChanged'<sup>12+</sup>   | The microphone is muted or unmuted.|


## PiPLiveActionEvent

type PiPLiveActionEvent = 'playbackStateChanged' | 'voiceStateChanged'

Defines the PiP action event in a live.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Type                  | Description            |
| ---------------------- | ---------------- |
| 'playbackStateChanged' | The live is played or paused.|
| 'voiceStateChanged'<sup>12+</sup> | The speaker is muted or unmuted.  |


## PiPControlStatus<sup>12+</sup>

Enumerates the statuses of components displayed on the PiP controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| PLAY       | 1   | Play.         |
| PAUSE    | 0   | Pause.          |
| OPEN    | 1   | Open.           |
| CLOSE       | 0   | Close.         |

## PiPControlType<sup>12+</sup>

Enumerates the types of components displayed on the PiP controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name               | Value  | Description                                  |
|-------------------|-----|--------------------------------------|
| VIDEO_PLAY_PAUSE  | 0   | Play/Pause component.  |
| VIDEO_PREVIOUS    | 1   | Previous component in video scenarios.|
| VIDEO_NEXT        | 2   | Next component in video scenarios.|
| FAST_FORWARD      | 3   | Fast-forward component in video scenarios.    |
| FAST_BACKWARD     | 4   | Rewind component in video scenarios.  |
| HANG_UP_BUTTON           | 5   | Hang-up component.|
| MICROPHONE_SWITCH | 6  | Microphone on/off component.|
| CAMERA_SWITCH     | 7   | Camera on/off component.    |
| MUTE_SWITCH       | 8   | Mute/Unmute component.    |


## ControlPanelActionEventCallback<sup>12+</sup>

type ControlPanelActionEventCallback = (event: PiPActionEventType, status?: number) => void

Describes the action event callback of the PiP controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name                      | Type          | Mandatory   | Description                               |
|--------------------------|--------------|--------------|-----------------------------------|
| event       |  [PiPActionEventType](#pipactioneventtype)       | Yes| Type of the action event of the PiP controller.<br>The application performs processing based on the action event. For example, if the **'playbackStateChanged'** event is triggered, the application starts or stops the video.|
| status | number | No| Status of a component that can be switched. For example, for a microphone on/off component group, a camera on/off component group, and a mute/unmute component group, the value **1** means that the component is enabled and **0** means that the component is disabled. For other components, the default value **-1** is used.|

## ControlEventParam<sup>12+</sup>

Describes the parameters in the callback of the action event of the PiP controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                      | Type          | Mandatory   | Description                                                                                                                               |
|--------------------------|--------------|--------------|-----------------------------------------------------------------------------------------------------------------------------------|
| controlType       |  [PiPControlType](#pipcontroltype12)      | Yes| Type of the action event of the PiP controller. The application performs processing based on the component type. For example, if the video play/pause component is touched, the application starts or stops the video.                                                                     |
| status | [PiPControlStatus](#pipcontrolstatus12) | No| Status of a component that can be switched. For example, for a microphone on/off component group, a camera on/off component group, and a mute/unmute component group, the value **PiPControlStatus.PLAY** means that the component is enabled and **PiPControlStatus.PAUSE** means that the component is disabled. For the hang-up component, the default value is **-1**.|

## PiPController

Implements a PiP controller that starts, stops, or updates a PiP window and registers callbacks.

Before calling any of the following APIs, you must use [PiPWindow.create()](#pipwindowcreate) to create a **PiPController** instance.

**System capability**: SystemCapability.Window.SessionManager

### startPiP

startPiP(): Promise&lt;void&gt;

Starts a PiP window. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

**Atomic service API**: This API can be used in atomic services since API version 12.

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

Sets whether to automatically start a PiP window when the user returns to the home screen. By default, no PiP window is started.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

Updates the media content size when the media content changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type    | Mandatory | Description                                    |
|--------|--------|-----|----------------------------------------|
| width  | number | Yes  | Width of the media content, in px. The value must be a number greater than 0. It is used to update the aspect ratio of the PiP window. |
| height | number | Yes  | Height of the media content, in px. The value must be a number greater than 0. It is used to update the aspect ratio of the PiP window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                       |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
let width: number = 540; // The content width changes to 540 px.
let height: number = 960; // The content height changes to 960 px.
pipController.updateContentSize(width, height);
```

### updatePiPControlStatus<sup>12+</sup>
updatePiPControlStatus(controlType: PiPControlType, status: PiPControlStatus): void

Updates the PiP component status.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type    | Mandatory | Description                                                                                                |
|--------|--------|-----|----------------------------------------------------------------------------------------------------|
| controlType  | [PiPControlType](#pipcontroltype12)  | Yes  | Type of the component displayed on the PiP controller. Currently, only **VIDEO_PLAY_PAUSE**, **MICROPHONE_SWITCH**, **CAMERA_SWITCH**, and **MUTE_SWITCH** are supported.|
| status | [PiPControlStatus](#pipcontrolstatus12)  | Yes  | Status of the component displayed on the PiP controller.                                                                                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                       |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed |

**Example**

```ts
let controlType: PiPWindow.PiPControlType = PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE; // Play/Pause component displayed on the video playback control panel.
let status: PiPWindow.PiPControlStatus = PiPWindow.PiPControlStatus.PLAY; // The Play/Pause component displayed on the video playback control panel is in the playing state.
pipController.updatePiPControlStatus(controlType, status);
```

### updateContentNode<sup>18+</sup>
updateContentNode(contentNode: typeNode.XComponent): Promise&lt;void&gt;

Updates the PiP node content.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                                      | Mandatory       | Description                                                                                                                                                                                                                                    |
|--------------|------------------------------------------|-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| contentNode       | [typeNode.XComponent](js-apis-arkui-frameNode.md#xcomponent12)    | Yes        | Content to be rendered in the PiP window. The parameter value cannot be empty. |

**Return value**

| Type                  | Description                 |
|----------------------|---------------------|
| Promise&lt;void&gt;  | Promise that returns no value.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                       |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |

**Example**

```ts
import { typeNode, UIContext } from '@kit.ArkUI';

let context: UIContext | undefined = undefined; // You can pass UIContext or use this.getUIContext() in the layout to assign a valid value to context.

try {
  let contentNode = typeNode.createNode(context, "XComponent");
  pipController.updateContentNode(contentNode);
} catch (exception) {
  console.error(`Failed to update content node. Cause: ${exception.code}, message: ${exception.message}`);
}
```

### setPiPControlEnabled<sup>12+</sup>
setPiPControlEnabled(controlType: PiPControlType, enabled: boolean): void

Sets the enabled status for a component displayed on the PiP controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name        | Type    | Mandatory | Description                                    |
|-------------|--------|-----|----------------------------------------|
| controlType | [PiPControlType](#pipcontroltype12)  | Yes  | Type of the component displayed on the PiP controller. |
| enabled     | boolean | Yes  | Enabled status of the component displayed on the PiP controller. The value **true** means that the component is enabled, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                       |
|-------|-------------------------------------------------------------------------------------------------------------|
| 401   | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed |

**Example**

```ts
let controlType: PiPWindow.PiPControlType = PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE; // Play/Pause component displayed on the video playback control panel.
let enabled: boolean = false; // The Play/Pause component displayed on the video playback control panel is in the disabled state.
pipController.setPiPControlEnabled(controlType, enabled);
```
### getPiPWindowInfo<sup>15+</sup>
getPiPWindowInfo(): Promise&lt;[PiPWindowInfo](#pipwindowinfo15)&gt;

Obtains the PIP window information.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                  | Description                 |
|----------------------|---------------------|
| Promise&lt;[PiPWindowInfo](#pipwindowinfo15)&gt;  | Promise used to return the information about the current PIP window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                                                                                       |
|-------|-------------------------------------------------------------------------------------------------------------|
| 801   | Capability not supported. Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |

**Example**

```ts
let pipWindowInfo: PiPWindow.PiPWindowInfo | undefined = undefined;
try {
  let promise : Promise<PiPWindow.PiPWindowInfo> = pipController.getPiPWindowInfo();
  promise.then((data) => {
    pipWindowInfo = data;
    console.info('Success in get pip window info. Info: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get pip window info. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to get pip window info. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('stateChange')

on(type: 'stateChange', callback: (state: PiPState, reason: string) => void): void

Subscribes to PiP state events. To avoid potential memory leaks, you are advised to stop listening when it is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name       | Type       | Mandatory  | Description                                                                                               |
|------------|-----------|------|---------------------------------------------------------------------------------------------------|
| type       | string    | Yes   | Event type. The event **'stateChange'** is triggered when the PiP state changes.                                                            |
| callback   | function  | Yes   | Callback used to return the result, which includes the following information:<br>- **state**: [PiPState](#pipstate), indicating the new PiP state.<br>- **reason**: a string indicating the reason for the state change. |

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

**Atomic service API**: This API can be used in atomic services since API version 12.

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

Subscribes to PiP action events. To avoid potential memory leaks, you are advised to stop listening when it is no longer needed. The [on('controlEvent')](#oncontrolevent12) API is preferred.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type        | Mandatory   | Description                                               |
|----------|------------|-------|---------------------------------------------------|
| type     | string     | Yes    | Event type. The value **'controlPanelActionEvent'** indicates the PiP action event.|
| callback | [ControlPanelActionEventCallback](#controlpanelactioneventcallback12)  | Yes    | Action event callback of the PiP controller.                               |

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

### on('controlEvent')<sup>12+</sup>

on(type: 'controlEvent', callback: Callback&lt;ControlEventParam&gt;): void

Subscribes to PiP action events. To avoid potential memory leaks, you are advised to stop listening when it is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                                                 | Mandatory   | Description                                    |
|----------|-----------------------------------------------------|-------|----------------------------------------|
| type     | string                                              | Yes    | Event type. The value **'controlEvent'** indicates the PiP action event.|
| callback | Callback<[ControlEventParam](#controleventparam12)> | Yes    | Action event callback of the PiP controller.                    |

**Example**

```ts
pipController.on('controlEvent', (control) => {
  switch (control.controlType) {
    case PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE:
      if (control.status === PiPWindow.PiPControlStatus.PAUSE) {
        // Stop the video.
      } else if (control.status === PiPWindow.PiPControlStatus.PLAY) {
        // Play the video.
      }
      break;
    case PiPWindow.PiPControlType.VIDEO_NEXT:
      // Switch to the next video.
      break;
    case PiPWindow.PiPControlType.VIDEO_PREVIOUS:
      // Switch to the previous video.
      break;
    case PiPWindow.PiPControlType.FAST_FORWARD:
      // Fast forward the video.
      break;
    case PiPWindow.PiPControlType.FAST_BACKWARD:
      // Rewind the video.
      break;
    default:
      break;
  }
  console.info('registerControlEventCallback, controlType:' + control.controlType + ', status' + control.status);
});
```

### off('controlPanelActionEvent')

off(type: 'controlPanelActionEvent'): void

Unsubscribes from PiP action events. The **[off('controlEvent')](#offcontrolevent12)** API is preferred.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name       | Type                          | Mandatory  | Description                                           |
|------------|------------------------------|------|-----------------------------------------------|
| type       | string                       | Yes   | Event type. The value **'controlPanelActionEvent'** indicates the PiP action event.  |

**Example**

```ts
pipController.off('controlPanelActionEvent');
```

### off('controlEvent')<sup>12+</sup>

off(type: 'controlEvent', callback?: Callback&lt;ControlEventParam&gt;): void

Unsubscribes from PiP action events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name       | Type                                                 | Mandatory| Description                                                    |
|------------|-----------------------------------------------------|----|--------------------------------------------------------|
| type       | string                                              | Yes | Event type. The value **'controlEvent'** indicates the PiP action event.                |
| callback | Callback<[ControlEventParam](#controleventparam12)> | No | Action event callback of the PiP controller. If no value is passed in, all subscriptions to the specified event are canceled.|

**Example**

```ts
pipController.off('controlEvent', () => {});
```

### on('pipWindowSizeChange')<sup>15+</sup>

on(type: 'pipWindowSizeChange', callback: Callback&lt;PiPWindowSize&gt;): void

Subscribes to PiP window size change events. To avoid potential memory leaks, you are advised to stop listening when it is no longer needed.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                                         | Mandatory   | Description                                               |
|----------|---------------------------------------------|-------|---------------------------------------------------|
| type     | string                                      | Yes    | Event type. The value is fixed at **'pipWindowSizeChange'**, indicating the PiP window size change event.|
| callback | Callback<[PiPWindowSize](#pipwindowsize15)> | Yes    | Callback used to return the size of the current PiP window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |    

**Example**

```ts
try {
  pipController.on('pipWindowSizeChange', (size: PiPWindow.PiPWindowSize) => {
    console.info('Succeeded in enabling the listener for pip window size changes. size: ' + JSON.stringify(size));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for pip window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('pipWindowSizeChange')<sup>15+</sup>

off(type: 'pipWindowSizeChange', callback?: Callback&lt;PiPWindowSize&gt;): void

Unsubscribes from the PiP window size change event.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type        | Mandatory| Description                                                                 |
|----------|------------|----|---------------------------------------------------------------------|
| type     | string     | Yes | Event type. The value is fixed at **'pipWindowSizeChange'**, indicating the PiP window size change event.                        |
| callback | Callback<[PiPWindowSize](#pipwindowsize15)> | No | Callback used to return the size of the current PiP window. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Params error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801   | Capability not supported.Failed to call the API due to limited device capabilities.                                                       |
| 1300014    | PiP internal error.                                    |    

**Example**

```ts
const callback = (size: PiPWindow.PiPWindowSize) => {
  // ...
}
try {
  // Enable listening through the on API.
  pipController.on('pipWindowSizeChange', callback);
} catch (exception) {
  console.error(`Failed to enable the listener for pip window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}

try {
  // Disable the listening of a specified callback.
  pipController.off('pipWindowSizeChange', callback);
  // Unregister all the callbacks that have been registered through on().
  pipController.off('pipWindowSizeChange');
} catch (exception) {
  console.error(`Failed to disable the listener for pip window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
