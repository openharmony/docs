# oh_window_pip.h
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## Overview

The file declares the APIs related to the Picture in Picture (PiP) feature, including creating and deleting a PiP controller, and starting and stopping PiP. PiP is mainly used in video playback, live streaming, video calls, or video meetings.

**File to include**: <window_manager/oh_window_pip.h>

**Library**: libnative_window_manager.so

**System capability**: SystemCapability.Window.SessionManager

**Since**: 20

**Related module**: [WindowManager](capi-windowmanager.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [PictureInPicture_PipTemplateType](#pictureinpicture_piptemplatetype) | PictureInPicture_PipTemplateType | Enumerates the types of PiP templates.|
| [PictureInPicture_PipControlGroup](#pictureinpicture_pipcontrolgroup) | PictureInPicture_PipControlGroup | Enumerates the types of component groups displayed on the PiP controller.|
| [PictureInPicture_PipControlType](#pictureinpicture_pipcontroltype) | PictureInPicture_PipControlType | Enumerates the types of components displayed on the PiP controller.|
| [PictureInPicture_PipControlStatus](#pictureinpicture_pipcontrolstatus) | PictureInPicture_PipControlStatus | Enumerates the statuses of components displayed on the PiP controller.|
| [PictureInPicture_PipState](#pictureinpicture_pipstate) | PictureInPicture_PipState | Enumerates the PiP lifecycle states.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*WebPipStartPipCallback)(uint32_t controllerId, uint8_t requestId, uint64_t surfaceId)](#webpipstartpipcallback) | WebPipStartPipCallback | Defines a callback function for PiP window creation.|
| [typedef void (\*WebPipLifecycleCallback)(uint32_t controllerId, PictureInPicture_PipState state, int32_t errcode)](#webpiplifecyclecallback) | WebPipLifecycleCallback | Defines a callback function for PiP window lifecycle changes.|
| [typedef void (\*WebPipControlEventCallback)(uint32_t controllerId, PictureInPicture_PipControlType controlType,PictureInPicture_PipControlStatus status)](#webpipcontroleventcallback) | WebPipControlEventCallback | Defines a callback function for the component click event of the PiP window.|
| [typedef void (\*WebPipResizeCallback)(uint32_t controllerId, uint32_t width, uint32_t height, double scale)](#webpipresizecallback) | WebPipResizeCallback | Defines a callback function for PiP window size changes.|
| [int32_t OH_PictureInPicture_CreatePipConfig(PictureInPicture_PipConfig* pipConfig)](#oh_pictureinpicture_createpipconfig) | - | Creates a PiP configuration.|
| [int32_t OH_PictureInPicture_DestroyPipConfig(PictureInPicture_PipConfig* pipConfig)](#oh_pictureinpicture_destroypipconfig) | - | Destroys a PiP configuration.|
| [int32_t OH_PictureInPicture_SetPipMainWindowId(PictureInPicture_PipConfig pipConfig, uint32_t mainWindowId)](#oh_pictureinpicture_setpipmainwindowid) | - | Sets the ID of the main window that launches PiP.|
| [int32_t OH_PictureInPicture_SetPipTemplateType(PictureInPicture_PipConfig pipConfig,PictureInPicture_PipTemplateType pipTemplateType)](#oh_pictureinpicture_setpiptemplatetype) | - | Sets the PiP template type. The default value is video playback.|
| [int32_t OH_PictureInPicture_SetPipRect(PictureInPicture_PipConfig pipConfig, uint32_t width, uint32_t height)](#oh_pictureinpicture_setpiprect) | - | Sets the size of the PiP window for calculating the aspect ratio.|
| [int32_t OH_PictureInPicture_SetPipControlGroup(PictureInPicture_PipConfig pipConfig,PictureInPicture_PipControlGroup* controlGroup, uint8_t controlGroupLength)](#oh_pictureinpicture_setpipcontrolgroup) | - | Sets a PiP component group, which must match the template type.|
| [int32_t OH_PictureInPicture_SetPipNapiEnv(PictureInPicture_PipConfig pipConfig, void* env)](#oh_pictureinpicture_setpipnapienv) | - | Sets the runtime environment for launching PiP.|
| [int32_t OH_PictureInPicture_CreatePip(PictureInPicture_PipConfig pipConfig, uint32_t* controllerId)](#oh_pictureinpicture_createpip) | - | Creates a PiP controller.|
| [int32_t OH_PictureInPicture_DeletePip(uint32_t controllerId)](#oh_pictureinpicture_deletepip) | - | Deletes a PiP controller.|
| [int32_t OH_PictureInPicture_StartPip(uint32_t controllerId)](#oh_pictureinpicture_startpip) | - | Starts PiP.|
| [int32_t OH_PictureInPicture_StopPip(uint32_t controllerId)](#oh_pictureinpicture_stoppip) | - | Stops PiP.|
| [int32_t OH_PictureInPicture_UpdatePipContentSize(uint32_t controllerId, uint32_t width, uint32_t height)](#oh_pictureinpicture_updatepipcontentsize) | - | Updates the media content size when the media content changes.|
| [int32_t OH_PictureInPicture_UpdatePipControlStatus(uint32_t controllerId, PictureInPicture_PipControlType controlType,PictureInPicture_PipControlStatus status)](#oh_pictureinpicture_updatepipcontrolstatus) | - | Updates the PiP component status.|
| [int32_t OH_PictureInPicture_SetPipControlEnabled(uint32_t controllerId, PictureInPicture_PipControlType controlType,bool enabled)](#oh_pictureinpicture_setpipcontrolenabled) | - | Sets the PiP component enabled status.|
| [int32_t OH_PictureInPicture_RegisterStartPipCallback(uint32_t controllerId, WebPipStartPipCallback callback)](#oh_pictureinpicture_registerstartpipcallback) | - | Registers a callback to listen for the completion of PiP surface creation.|
| [int32_t OH_PictureInPicture_UnregisterStartPipCallback(uint32_t controllerId, WebPipStartPipCallback callback)](#oh_pictureinpicture_unregisterstartpipcallback) | - | Unregisters the callback used to listen for the completion of PiP surface creation.|
| [int32_t OH_PictureInPicture_UnregisterAllStartPipCallbacks(uint32_t controllerId)](#oh_pictureinpicture_unregisterallstartpipcallbacks) | - | Unregisters all the callbacks used to listen for the completion of PiP surface creation.|
| [int32_t OH_PictureInPicture_RegisterLifecycleListener(uint32_t controllerId, WebPipLifecycleCallback callback)](#oh_pictureinpicture_registerlifecyclelistener) | - | Registers a callback to listen for PiP lifecycle state changes.|
| [int32_t OH_PictureInPicture_UnregisterLifecycleListener(uint32_t controllerId, WebPipLifecycleCallback callback)](#oh_pictureinpicture_unregisterlifecyclelistener) | - | Unregisters the callback used to listen for PiP lifecycle state changes.|
| [int32_t OH_PictureInPicture_UnregisterAllLifecycleListeners(uint32_t controllerId)](#oh_pictureinpicture_unregisteralllifecyclelisteners) | - | Unregisters all the callbacks used to listen for PiP lifecycle state changes.|
| [int32_t OH_PictureInPicture_RegisterControlEventListener(uint32_t controllerId, WebPipControlEventCallback callback)](#oh_pictureinpicture_registercontroleventlistener) | - | Registers a callback to listen for control panel action events in PiP mode.|
| [int32_t OH_PictureInPicture_UnregisterControlEventListener(uint32_t controllerId, WebPipControlEventCallback callback)](#oh_pictureinpicture_unregistercontroleventlistener) | - | Unregisters the callback used to listen for control panel action events in PiP mode.|
| [int32_t OH_PictureInPicture_UnregisterAllControlEventListeners(uint32_t controllerId)](#oh_pictureinpicture_unregisterallcontroleventlisteners) | - | Unregisters all the callbacks used to listen for control panel action events in PiP mode.|
| [int32_t OH_PictureInPicture_RegisterResizeListener(uint32_t controllerId, WebPipResizeCallback callback)](#oh_pictureinpicture_registerresizelistener) | - | Registers a callback to listen for PiP window size changes.|
| [int32_t OH_PictureInPicture_UnregisterResizeListener(uint32_t controllerId, WebPipResizeCallback callback)](#oh_pictureinpicture_unregisterresizelistener) | - | Unregisters the callback used to listen for PiP window size changes.|
| [int32_t OH_PictureInPicture_UnregisterAllResizeListeners(uint32_t controllerId)](#oh_pictureinpicture_unregisterallresizelisteners) | - | Unregisters all the callbacks used to listen for PiP window size changes.|
| [int32_t OH_PictureInPicture_SetPipInitialSurfaceRect(uint32_t controllerId, int32_t positionX, int32_t positionY,uint32_t width, uint32_t height)](#oh_pictureinpicture_setpipinitialsurfacerect) | - | Sets the initial position and size of the PiP surface when the PiP launch animation starts. It can be used to achieve a seamless transition effect.|
| [int32_t OH_PictureInPicture_UnsetPipInitialSurfaceRect(uint32_t controllerId)](#oh_pictureinpicture_unsetpipinitialsurfacerect) | - | Cancels the previously set initial position and size for the PiP surface.|

## Enum Description

### PictureInPicture_PipTemplateType

```
enum PictureInPicture_PipTemplateType
```

**Description**

Enumerates the types of PiP templates.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| VIDEO_PLAY = 0 | Video playback template. A PiP window will be started during video playback, and the video playback template is loaded.|
| VIDEO_CALL = 1 | Video call template. A PiP window will be started during a video call, and the video call template will be loaded.|
| VIDEO_MEETING = 2 | Video meeting template. A PiP window will be started during a video meeting, and the video meeting template will be loaded.|
| VIDEO_LIVE = 3 | Live template. A PiP window will be started during a live, and the live template is loaded.|

### PictureInPicture_PipControlGroup

```
enum PictureInPicture_PipControlGroup
```

**Description**

Enumerates the types of component groups displayed on the PiP controller.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| VIDEO_PLAY_VIDEO_PREVIOUS_NEXT = 101 | Previous/Next component group for video playback. This component group is mutually exclusive with the fast-forward/rewind component group. It cannot be added if the fast-forward/rewind component group is added.|
| VIDEO_PLAY_FAST_FORWARD_BACKWARD = 102 | Fast-forward/Rewind component group for video playback. This component group is mutually exclusive with the previous/next component group. It cannot be added if the previous/next component group is added.|
| VIDEO_CALL_MICROPHONE_SWITCH = 201 | Microphone on/off component group for video calls.|
| VIDEO_CALL_HANG_UP_BUTTON = 202 | Hang-up component group for video calls.|
| VIDEO_CALL_CAMERA_SWITCH = 203 | Camera on/off component group for video calls.|
| VIDEO_CALL_MUTE_SWITCH = 204 | Mute component group for video calls.|
| VIDEO_MEETING_HANG_UP_BUTTON = 301 | Hang-up component group for video meetings.|
| VIDEO_MEETING_CAMERA_SWITCH = 302 | Camera on/off component group for video meetings.|
| VIDEO_MEETING_MUTE_SWITCH = 303 | Mute component group for video meetings.|
| VIDEO_MEETING_MICROPHONE_SWITCH = 304 | Microphone on/off component group for video meetings.|
| VIDEO_LIVE_VIDEO_PLAY_PAUSE = 401 | Play/Pause component group for live streaming.|
| VIDEO_LIVE_MUTE_SWITCH = 402 | Mute component group for live streaming.|

### PictureInPicture_PipControlType

```
enum PictureInPicture_PipControlType
```

**Description**

Enumerates the types of components displayed on the PiP controller.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| VIDEO_PLAY_PAUSE = 0 | Play/Pause component.|
| VIDEO_PREVIOUS = 1 | Previous component in video scenarios.|
| VIDEO_NEXT = 2 | Next component in video scenarios.|
| FAST_FORWARD = 3 | Fast-forward component in video scenarios.|
| FAST_BACKWARD = 4 | Rewind component in video scenarios.|
| HANG_UP_BUTTON = 5 | Hang-up component.|
| MICROPHONE_SWITCH = 6 | Microphone on/off component.|
| CAMERA_SWITCH = 7 | Camera on/off component.|
| MUTE_SWITCH = 8 | Mute/Unmute component.|

### PictureInPicture_PipControlStatus

```
enum PictureInPicture_PipControlStatus
```

**Description**

Enumerates the statuses of components displayed on the PiP controller.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| PLAY = 1 | A video is playing.|
| PAUSE = 0 | A video is paused.|
| OPEN = 1 | The camera, microphone, and mute components are enabled.|
| CLOSE = 0 | The camera, microphone, and mute components are disabled.|

### PictureInPicture_PipState

```
enum PictureInPicture_PipState
```

**Description**

Enumerates the PiP lifecycle states.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| ABOUT_TO_START = 1 | PiP is about to start.|
| STARTED = 2 | PiP is started.|
| ABOUT_TO_STOP = 3 | PiP is about to stop.|
| STOPPED = 4 | PiP is stopped.|
| ABOUT_TO_RESTORE = 5 | The original page is about to restore.|
| ERROR = 6 | An error occurs during the execution of the PiP lifecycle.|


## Function Description

### WebPipStartPipCallback()

```
typedef void (*WebPipStartPipCallback)(uint32_t controllerId, uint8_t requestId, uint64_t surfaceId)
```

**Description**

Defines a callback function for PiP window creation.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
|  uint8_t requestId | Request ID, which indicates the number of times the PiP window has been requested to be pulled up.|
|  uint64_t surfaceId | Surface ID of the **XComponent** in PiP. It is used for application rendering.|

### WebPipLifecycleCallback()

```
typedef void (*WebPipLifecycleCallback)(uint32_t controllerId, PictureInPicture_PipState state, int32_t errcode)
```

**Description**

Defines a callback function for PiP window lifecycle changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
|  PictureInPicture_PipState state | PiP lifecycle state.|
|  int32_t errcode | Common status codes of PiP APIs. For details, see [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode).|

### WebPipControlEventCallback()

```
typedef void (*WebPipControlEventCallback)(uint32_t controllerId, PictureInPicture_PipControlType controlType, PictureInPicture_PipControlStatus status)
```

**Description**

Defines a callback function for the component click event of the PiP window.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
|  PictureInPicture_PipControlType controlType | Type of component displayed on the PiP controller.|
| [PictureInPicture_PipControlStatus](#pictureinpicture_pipcontrolstatus) status | Status of the component displayed on the PiP controller.|

### WebPipResizeCallback()

```
typedef void (*WebPipResizeCallback)(uint32_t controllerId, uint32_t width, uint32_t height, double scale)
```

**Description**

Defines a callback function for PiP window size changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
|  uint32_t width | PiP window width, in px. The value is a positive integer and cannot be greater than the screen width.|
|  uint32_t height | PiP window height, in px. The value is a positive integer and cannot be greater than the screen height.|
|  double scale | Scale factor of the PiP window, representing the display size relative to the width and height. The value is a floating-point number in the range (0.0, 1.0]. The value **1** means that the PiP window matches the specified width and height.|

### OH_PictureInPicture_CreatePipConfig()

```
int32_t OH_PictureInPicture_CreatePipConfig(PictureInPicture_PipConfig* pipConfig)
```

**Description**

Creates a PiP configuration.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md)* pipConfig | Pointer to the PiP parameter configuration.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.|

### OH_PictureInPicture_DestroyPipConfig()

```
int32_t OH_PictureInPicture_DestroyPipConfig(PictureInPicture_PipConfig* pipConfig)
```

**Description**

Destroys a PiP configuration.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md)* pipConfig | Pointer to the PiP configuration.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.|

### OH_PictureInPicture_SetPipMainWindowId()

```
int32_t OH_PictureInPicture_SetPipMainWindowId(PictureInPicture_PipConfig pipConfig, uint32_t mainWindowId)
```

**Description**

Sets the ID of the main window that launches PiP.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md) pipConfig | PiP configuration.|
| uint32_t mainWindowId | ID of the main window that launches PiP.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.|

### OH_PictureInPicture_SetPipTemplateType()

```
int32_t OH_PictureInPicture_SetPipTemplateType(PictureInPicture_PipConfig pipConfig, PictureInPicture_PipTemplateType pipTemplateType)
```

**Description**

Sets the PiP template type. The default value is video playback.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md) pipConfig | PiP configuration.|
| [PictureInPicture_PipTemplateType](#pictureinpicture_piptemplatetype) pipTemplateType | Type of the PiP template.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.|

### OH_PictureInPicture_SetPipRect()

```
int32_t OH_PictureInPicture_SetPipRect(PictureInPicture_PipConfig pipConfig, uint32_t width, uint32_t height)
```

**Description**

Sets the size of the PiP window for calculating the aspect ratio.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md) pipConfig | PiP configuration.|
| uint32_t width | Width of the original content, in px. The value must be a positive integer. It is used to determine the aspect ratio of the PiP window.|
| uint32_t height | Height of the original content, in px. The value must be a positive integer. It is used to determine the aspect ratio of the PiP window.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.|

### OH_PictureInPicture_SetPipControlGroup()

```
int32_t OH_PictureInPicture_SetPipControlGroup(PictureInPicture_PipConfig pipConfig, PictureInPicture_PipControlGroup* controlGroup, uint8_t controlGroupLength)
```

**Description**

Sets a PiP component group, which must match the template type.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md) pipConfig | PiP configuration.|
| [PictureInPicture_PipControlGroup](#pictureinpicture_pipcontrolgroup)* controlGroup | Pointer to an optional component group of the PiP controller. An application can configure whether to display these optional components. If this parameter is not set for an application, the basic components (for example, play/pause of the video playback component group) are displayed. A maximum of three components can be configured.|
| uint8_t controlGroupLength | Number of components in the PiP component group. The value ranges from 0 to 3.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.|

### OH_PictureInPicture_SetPipNapiEnv()

```
int32_t OH_PictureInPicture_SetPipNapiEnv(PictureInPicture_PipConfig pipConfig, void* env)
```

**Description**

Sets the runtime environment for launching PiP.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md) pipConfig | PiP configuration.|
| void* env | Pointer to the NAPI environment.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.|

### OH_PictureInPicture_CreatePip()

```
int32_t OH_PictureInPicture_CreatePip(PictureInPicture_PipConfig pipConfig, uint32_t* controllerId)
```

**Description**

Creates a PiP controller.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [PictureInPicture_PipConfig](capi-pictureinpicture-pipconfig.md) pipConfig | PiP configuration.|
| uint32_t* controllerId | Pointer to the ID of the PiP controller created.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_DeletePip()

```
int32_t OH_PictureInPicture_DeletePip(uint32_t controllerId)
```

**Description**

Deletes a PiP controller.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.|

### OH_PictureInPicture_StartPip()

```
int32_t OH_PictureInPicture_StartPip(uint32_t controllerId)
```

**Description**

Starts PiP.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_PIP_STATE_ABNORMAL**: The PiP window is abnormal.<br>**WINDOW_MANAGER_ERRORCODE_PIP_CREATE_FAILED**: Creating the PiP window fails.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_REPEATED_OPERATION**: The PiP window is manipulated repeatedly.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.|

### OH_PictureInPicture_StopPip()

```
int32_t OH_PictureInPicture_StopPip(uint32_t controllerId)
```

**Description**

Stops PiP.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_PIP_DESTROY_FAILED**: Destroying the PiP window fails.<br>**WINDOW_MANAGER_ERRORCODE_PIP_STATE_ABNORMAL**: The PiP window is abnormal.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_REPEATED_OPERATION**: The PiP window is manipulated repeatedly.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.|

### OH_PictureInPicture_UpdatePipContentSize()

```
int32_t OH_PictureInPicture_UpdatePipContentSize(uint32_t controllerId, uint32_t width, uint32_t height)
```

**Description**

Updates the media content size when the media content changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| uint32_t width | Width of the media content, in px. The value must be a positive integer. It is used to update the aspect ratio of the PiP window.|
| uint32_t height | Height of the media content, in px. The value must be a positive integer. It is used to update the aspect ratio of the PiP window.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UpdatePipControlStatus()

```
int32_t OH_PictureInPicture_UpdatePipControlStatus(uint32_t controllerId, PictureInPicture_PipControlType controlType, PictureInPicture_PipControlStatus status)
```

**Description**

Updates the PiP component status.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [PictureInPicture_PipControlType](#pictureinpicture_pipcontroltype) controlType | Type of the component displayed on the PiP controller. Currently, only **VIDEO_PLAY_PAUSE**, **MICROPHONE_SWITCH**, **CAMERA_SWITCH**, and **MUTE_SWITCH** are supported.|
| [PictureInPicture_PipControlStatus](#pictureinpicture_pipcontrolstatus) status | Status of the component displayed on the PiP controller.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_SetPipControlEnabled()

```
int32_t OH_PictureInPicture_SetPipControlEnabled(uint32_t controllerId, PictureInPicture_PipControlType controlType, bool enabled)
```

**Description**

Sets the PiP component enabled status.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [PictureInPicture_PipControlType](#pictureinpicture_pipcontroltype) controlType | Type of the component displayed on the PiP controller.|
| bool enabled | Enabled status of the component displayed on the PiP controller. **true** if enabled, **false** otherwise.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_RegisterStartPipCallback()

```
int32_t OH_PictureInPicture_RegisterStartPipCallback(uint32_t controllerId, WebPipStartPipCallback callback)
```

**Description**

Registers a callback to listen for the completion of PiP surface creation.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipStartPipCallback](#webpipstartpipcallback) callback | Callback function for PiP window creation.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterStartPipCallback()

```
int32_t OH_PictureInPicture_UnregisterStartPipCallback(uint32_t controllerId, WebPipStartPipCallback callback)
```

**Description**

Unregisters the callback used to listen for the completion of PiP surface creation.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipStartPipCallback](#webpipstartpipcallback) callback | Callback function for PiP window creation.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterAllStartPipCallbacks()

```
int32_t OH_PictureInPicture_UnregisterAllStartPipCallbacks(uint32_t controllerId)
```

**Description**

Unregisters all the callbacks used to listen for the completion of PiP surface creation.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_RegisterLifecycleListener()

```
int32_t OH_PictureInPicture_RegisterLifecycleListener(uint32_t controllerId, WebPipLifecycleCallback callback)
```

**Description**

Registers a callback to listen for PiP lifecycle state changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipLifecycleCallback](#webpiplifecyclecallback) callback | Callback function for PiP window lifecycle changes.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterLifecycleListener()

```
int32_t OH_PictureInPicture_UnregisterLifecycleListener(uint32_t controllerId, WebPipLifecycleCallback callback)
```

**Description**

Unregisters the callback used to listen for PiP lifecycle state changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipLifecycleCallback](#webpiplifecyclecallback) callback | Callback function for PiP window lifecycle changes.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterAllLifecycleListeners()

```
int32_t OH_PictureInPicture_UnregisterAllLifecycleListeners(uint32_t controllerId)
```

**Description**

Unregisters all the callbacks used to listen for PiP lifecycle state changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_RegisterControlEventListener()

```
int32_t OH_PictureInPicture_RegisterControlEventListener(uint32_t controllerId, WebPipControlEventCallback callback)
```

**Description**

Registers a callback to listen for control panel action events in PiP mode.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipControlEventCallback](#webpipcontroleventcallback) callback | Callback function for the component click event of the PiP window.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterControlEventListener()

```
int32_t OH_PictureInPicture_UnregisterControlEventListener(uint32_t controllerId, WebPipControlEventCallback callback)
```

**Description**

Unregisters the callback used to listen for control panel action events in PiP mode.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipControlEventCallback](#webpipcontroleventcallback) callback | Callback function for the component click event of the PiP window.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterAllControlEventListeners()

```
int32_t OH_PictureInPicture_UnregisterAllControlEventListeners(uint32_t controllerId)
```

**Description**

Unregisters all the callbacks used to listen for control panel action events in PiP mode.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_RegisterResizeListener()

```
int32_t OH_PictureInPicture_RegisterResizeListener(uint32_t controllerId, WebPipResizeCallback callback)
```

**Description**

Registers a callback to listen for PiP window size changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipResizeCallback](#webpipresizecallback) callback | Callback function for PiP window size changes.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterResizeListener()

```
int32_t OH_PictureInPicture_UnregisterResizeListener(uint32_t controllerId, WebPipResizeCallback callback)
```

**Description**

Unregisters the callback used to listen for PiP window size changes.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| [WebPipResizeCallback](#webpipresizecallback) callback | Callback function for PiP window size changes.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnregisterAllResizeListeners()

```
int32_t OH_PictureInPicture_UnregisterAllResizeListeners(uint32_t controllerId)
```

**Description**

Unregisters all the callbacks used to listen for PiP window size changes.

**Since**: 20

**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The device does not support PiP.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_SetPipInitialSurfaceRect()

```
int32_t OH_PictureInPicture_SetPipInitialSurfaceRect(uint32_t controllerId, int32_t positionX, int32_t positionY,uint32_t width, uint32_t height)
```

**Description**

Sets the initial position and size of the PiP surface when the PiP launch animation starts. It can be used to achieve a seamless transition effect.

**Since**: 20

**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|
| int32_t positionX | X coordinate of the PiP window relative to the top-left corner of the screen when the PiP window is started, in px.|
| int32_t positionY | Y coordinate of the PiP window relative to the top-left corner of the screen when the PiP window is started, in px.|
| uint32_t width | Width of the PiP window when the PiP window is started. The value is greater than 0, measured in px.|
| uint32_t height | Height of the PiP window when the PiP window is started. The value is greater than 0, measured in px.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|

### OH_PictureInPicture_UnsetPipInitialSurfaceRect()

```
int32_t OH_PictureInPicture_UnsetPipInitialSurfaceRect(uint32_t controllerId)
```

**Description**

Cancels the previously set initial position and size for the PiP surface.

**Since**: 20

**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t controllerId | ID of the PiP controller. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br>**OK**: The function is successfully called.<br>**WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM**: A parameter is incorrect.<br>**WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR**: An internal error occurs in PiP.|
