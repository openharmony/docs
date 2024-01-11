# @ohos.PiPWindow (PiP Window)

The **PiPWindow** module provides basic APIs for manipulating Picture in Picture (PiP). For example, you can use the APIs to check whether the PiP feature is enabled and create a PiP controller to start or stop a PiP window. PiP is mainly used in video playback, video call, or video meeting scenarios.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> This module must be used on the device that supports the **SystemCapability.Window.SessionManager** capability. For details, see [SystemCapability](../syscap.md).

## Modules to Import

```ts
import pipWindow from '@ohos.PiPWindow';
```

## pipWindow.isPiPEnabled

isPiPEnabled(): boolean

Checks whether the PiP feature is enabled.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type      | Description                                 |
|----------|-------------------------------------|
| boolean  | Status of the PiP feature. The value **true** means that the PiP feature is enabled, and **false** means the opposite.|

**Example**

```ts
let enable: boolean = pipWindow.isPiPEnabled();
console.info('isPipEnabled:' + enable);
```

## pipWindow.create

create(config: PiPConfiguration, callback: AsyncCallback&lt;PiPController&gt;): void

Creates a PiP controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name       | Type                                                   | Mandatory    | Description              |
|------------|-------------------------------------------------------|--------|------------------|
| config     | [PiPConfiguration](#pipconfiguration)                 | Yes     | Parameters for creating the PiP controller.   |
| callback   | AsyncCallback&lt;[PiPController](#pipcontroller)&gt;  | Yes     | Callback used to return the PiP controller.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let pipController: pipWindow.PiPController | undefined = undefined;
let mXComponentController: XComponentController = new XComponentController(); // Use the mXComponentController to initialize the XComponent: XComponent( {id: 'video', type: 'surface', controller: mXComponentController} ). This ensures that the XComponent content can be migrated to the PiP window.
let navId: string = "page_1"; // The navigation ID of the current page is page_1. For details, see the definition of PiPConfiguration. The navigation name is customized.
let contentWidth: number = 800; // The content width is 800 pixels.
let contentHeight: number = 600; // The content height is 600 pixels.

let config: pipWindow.PiPConfiguration = {
  context: getContext(this),
  componentController: mXComponentController,
  navigationId: navId,
  templateType: pipWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: contentWidth,
  contentHeight: contentHeight,
};

pipWindow.create(config, (err: BusinessError, data : pipWindow.PiPController) => {
  if (err.code) {
    console.error(`Failed to create pip controller. Cause:${err.code}, message:${err.message}`);
    return;
  }
  pipController = data;
  console.info(`Succeeded in creating pip controller. Data:${data}`);
});
```

## pipWindow.create

create(config: PiPConfiguration): Promise&lt;PiPController&gt;

Creates a PiP controller. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                                      | Mandatory       | Description            |
|--------------|------------------------------------------|-----------|----------------|
| config       | [PiPConfiguration](#pipconfiguration)    | Yes        | Parameters for creating the PiP controller.  |

**Return value**

| Type                                                        | Description                      |
|------------------------------------------------------------|--------------------------|
| Promise&lt;[PiPController](#pipcontroller)&gt;  | Promise used to return the PiP controller.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
let pipController: pipWindow.PiPController | undefined = undefined;
let mXComponentController: XComponentController = new XComponentController(); // Use the mXComponentController to initialize the XComponent: XComponent( {id: 'video', type: 'surface', controller: mXComponentController} ). This ensures that the XComponent content can be migrated to the PiP window.
let navId: string = "page_1"; // The navigation ID of the current page is page_1. For details, see the definition of PiPConfiguration. The navigation name is customized.
let contentWidth: number = 800; // The content width is 800 pixels.
let contentHeight: number = 600; // The content height is 600 pixels.
let config: pipWindow.PiPConfiguration = {
  context: getContext(this),
  componentController: mXComponentController,
  navigationId: navId,
  templateType: pipWindow.PiPTemplateType.VIDEO_PLAY,
  contentWidth: contentWidth,
  contentHeight: contentHeight,
};

let promise : Promise<pipWindow.PiPController> = pipWindow.create(config);
promise.then((data : pipWindow.PiPController) => {
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
| context             | [BaseContext](js-apis-inner-application-baseContext.md)               | Yes  | Context environment.                                                                                                                                                                                                                                                                                                                                    |
| componentController | [XComponentController](../arkui-ts/ts-basic-components-xcomponent.md) | Yes  | Original [XComponent](../../ui/arkts-common-components-xcomponent.md) controller.                                                                                                                                                                                                                                                                        |
| navigationId        | string                                                                | No  | Navigation ID of the current page.<br>- When the UIAbility uses [Navigation](../arkui-ts/ts-basic-components-navigation.md) to manage pages, set the ID of the **<\Navigation>** component for the PiP controller. This ensures that the original page can be restored from the PiP window.<br>- When the UIAbility uses [Router](js-apis-router.md) to manage pages, you do not need to set the navigation ID. (This navigation mode is not recommended in PiP scenarios.) After a PiP window is started in this scenario, do not switch between pages. Otherwise, exceptions may occur during restoration.<br>- If the UIAbility has only one page, you do not need to set the navigation ID. The original page can be restored from the PiP window. |
| templateType        | [PiPTemplateType](#piptemplatetype)                                   | No  | Template type, which is used to distinguish video playback, video call, and video meeting scenarios.                                                                                                                                                                                                                                                                                                                    |
| contentWidth        | number                                                                | No  | Width of the original content, in pixels. It is used to determine the aspect ratio of the PiP window.                                                                                                                                                                                                                                                                                                                   |
| contentHeight       | number                                                                | No  | Height of the original content, in pixels. It is used to determine the aspect ratio of the PiP window.                                                                                                                                                                                                                                                                                                                   |

## PiPTemplateType

Enumerates the PIP template types.

**System capability**: SystemCapability.Window.SessionManager

| Name                    | Value      | Description                                     |
|------------------------|---------|-----------------------------------------|
| VIDEO_PLAY             | 0       | Video playback template. A PiP window will be started during video playback, and the video playback template is loaded.     |
| VIDEO_CALL             | 1       | Video call template. A PiP window will be started during a video call, and the video call template will be loaded.   |
| VIDEO_MEETING          | 2       | Video meeting template. A PiP window will be started during a video meeting, and the video meeting template will be loaded.   |

## PiPState

Enumerates the PiP states.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Value  | Description                   |
|----------------------|-----|-----------------------|
| ABOUT_TO_START       | 1   | PiP is about to start.           |
| STARTED              | 2   | PiP is started.           |
| ABOUT_TO_STOP        | 3   | PiP is about to stop.           |
| STOPPED              | 4   | PiP is stopped.           |
| ABOUT_TO_RESTORE     | 5   | The original page is about to restore.|
| ERROR                | 6   | An error occurs during the execution of the PiP lifecycle.  |

## PiPActionEventType

Enumerates the PiP action event types.

**System capability**: SystemCapability.Window.SessionManager

| Type                                              | Description           |
|--------------------------------------------------|---------------|
| [PiPVideoActionEvent](#pipvideoactionevent)      | PiP action event during video playback.  |
| [PiPCallActionEvent](#pipcallactionevent)        | PiP action event in a video call.  |
| [PiPMeetingActionEvent](#pipmeetingactionevent)  | PiP action event in a video meeting.  |

## PiPVideoActionEvent

Defines the PiP action event during video playback.

**System capability**: SystemCapability.Window.SessionManager

| Name                    | Type      | Description                                                                                                 |
|------------------------|----------|-----------------------------------------------------------------------------------------------------|
| PiPVideoActionEvent    | string   | The options are as follows:<br>- **'playbackStateChanged'**: The playback status changes.<br>- **'nextVideo'**: Play the next video.<br>- **'previousVideo'**: Play the previous video.|

## PiPCallActionEvent

Defines the PiP action event in a video call.

**System capability**: SystemCapability.Window.SessionManager

| Name                    | Type    | Description                 |
|------------------------|--------|---------------------|
| PiPCallActionEvent     | string | The value is fixed at **'hangUp'**, indicating that the video call is hung up.|

## PiPMeetingActionEvent

Defines the PiP action event in a video meeting.

**System capability**: SystemCapability.Window.SessionManager

| Name                        | Type        | Description                 |
|----------------------------|------------|---------------------|
| PiPMeetingActionEvent      | string     | The value is fixed at **'hangUp'**, indicating that the video meeting is hung up.|

## PiPController

Implements a PiP controller that starts, stops, or updates a PiP window and registers callbacks.

Before calling any of the following APIs, you must use [pipWindow.create()](#pipwindowcreate) to create a **PiPController** instance.

**System capability**: SystemCapability.Window.SessionManager

### startPiP

startPiP(callback: AsyncCallback&lt;void&gt;): void

Starts a PiP window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name        | Type                         | Mandatory  | Description                |
|-------------|-----------------------------|------|--------------------|
| callback    | AsyncCallback&lt;void&gt;   | Yes   | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID     | Error Message                                                  |
|------------|--------------------------------------------------------|
| 1300012    | If PiP window state is abnormal.                       |
| 1300013    | Create pip window failed.                              |
| 1300014    | Error when load PiP window content or show PiP window. |
| 1300015    | If window has created.                                 |

**Example**

```ts
pipController.startPiP((err: BusinessError) => {
  if (err.code) {
    console.error(`Failed to start pip. Cause:${err.code}, message:${err.message}`);
    return;
  }
  console.info('Succeeded in starting pip.');
});
```

### startPiP

startPiP(): Promise&lt;void&gt;

Starts a PiP window. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                    | Description                |
|------------------------|--------------------|
| Promise&lt;void&gt;    | Promise that returns no value.  |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID     | Error Message                                                  |
|------------|--------------------------------------------------------|
| 1300012    | If PiP window state is abnormal.                       |
| 1300013    | Create pip window failed.                              |
| 1300014    | Error when load PiP window content or show PiP window. |
| 1300015    | If window has created.                                 |

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

stopPiP(callback: AsyncCallback&lt;void&gt;): void

Stops a PiP window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name        | Type                         | Mandatory  | Description       |
|-------------|-----------------------------|------|-----------|
| callback    | AsyncCallback&lt;void&gt;   | Yes   | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID  | Error Message                            |
|---------|----------------------------------|
| 1300011 | Stop PiP window failed.          |
| 1300012 | If PiP window state is abnormal. |
| 1300015 | If window is stopping.           |

**Example**

```ts
pipController.stopPiP((err: BusinessError) => {
  if (err.code) {
    console.error(`Failed to stop pip. Cause:${err.code}, message:${err.message}`);
    return;
  }
  console.info('Succeeded in stopping pip.');
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

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID  | Error Message                            |
|---------|----------------------------------|
| 1300011 | Stop PiP window failed.          |
| 1300012 | If PiP window state is abnormal. |
| 1300015 | If window is stopping.           |

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
| enable   | boolean   | Yes    | The value **true** means to automatically start a PiP window in such a case, and **false** means the opposite. |

```ts
let enable: boolean = true;
pipController.setAutoStartEnabled(enable);
```

### updateContentSize

updateContentSize(width: number, height: number): void

Updates the media content size when the media content is switched.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type    | Mandatory | Description                          |
|--------|--------|-----|------------------------------|
| width  | number | Yes  | Width of the media content, in pixels. It is used to update the aspect ratio of the PiP window.  |
| height | number | Yes  | Width of the media content, in pixels. It is used to update the aspect ratio of the PiP window.  |

```ts
let width: number = 540; // The content width changes to 540 pixels.
let height: number = 960; // The content height changes to 960 pixels.
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
| callback   | function  | Yes   | Callback used to return the result, which includes the following information:<br>- **state**: [PiPState](#pipstate), indicating the new PiP state.<br>- **reason**: a string indicating the reason for the state change. |

```ts
pipController.on('stateChange', (state: pipWindow.PiPState, reason: string) => {
  let curState: string = '';
  switch (state) {
    case pipWindow.PiPState.ABOUT_TO_START:
      curState = 'ABOUT_TO_START';
      break;
    case pipWindow.PiPState.STARTED:
      curState = 'STARTED';
      break;
    case pipWindow.PiPState.ABOUT_TO_STOP:
      curState = 'ABOUT_TO_STOP';
      break;
    case pipWindow.PiPState.STOPPED:
      curState = 'STOPPED';
      break;
    case pipWindow.PiPState.ABOUT_TO_RESTORE:
      curState = 'ABOUT_TO_RESTORE';
      break;
    case pipWindow.PiPState.ERROR:
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

on(type: 'controlPanelActionEvent', callback: (event: PiPActionEventType) => void): void

Subscribes to PiP action events.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type        | Mandatory   | Description                                                                                                                            |
|----------|------------|-------|--------------------------------------------------------------------------------------------------------------------------------|
| type     | string     | Yes    | Event type. The value **'controlPanelActionEvent'** indicates the PiP action event.                                                                                   |
| callback | function   | Yes    | Callback used to return the result, which includes the following information:<br>**event**: [PiPActionEventType](#pipactioneventtype), indicating the type of the PiP action event. The application performs processing based on the event. For example, if the **'playbackStateChanged'** event is triggered, the application starts or stops the video. |

```ts
pipController.on('controlPanelActionEvent', (event: pipWindow.PiPActionEventType) => {
  switch (event) {
    case 'playbackStateChanged':
      // Start or stop the video.
      break;
    case 'nextVideo':
      // Switch to the next video.
      break;
    case 'previousVideo':
      // Switch to the previous video.
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
