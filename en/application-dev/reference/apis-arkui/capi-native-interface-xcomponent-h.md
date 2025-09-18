# native_interface_xcomponent.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @ZhangYu-Coder-->
<!--Designer: @sunbees-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

## Overview

Declares the APIs for accessing Native XComponent features.

**File to include**: <ace/xcomponent/native_interface_xcomponent.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 8

**Related module**: [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeXComponent_HistoricalPoint](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-historicalpoint.md) | OH_NativeXComponent_HistoricalPoint | Represents a historical touch point.|
| [OH_NativeXComponent_TouchPoint](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-touchpoint.md) | OH_NativeXComponent_TouchPoint | Describes the touch point of the touch event.|
| [OH_NativeXComponent_TouchEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-touchevent.md) | OH_NativeXComponent_TouchEvent | Describes the touch event.|
| [OH_NativeXComponent_MouseEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-mouseevent.md) | OH_NativeXComponent_MouseEvent | Describes the mouse event.|
| [OH_NativeXComponent_Callback](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-callback.md) | OH_NativeXComponent_Callback | Registers callbacks for the surface lifecycle and touch event.|
| [OH_NativeXComponent_MouseEvent_Callback](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-mouseevent-callback.md) | OH_NativeXComponent_MouseEvent_Callback | Registers callbacks for the mouse event.|
| [OH_NativeXComponent_ExpectedRateRange](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-expectedraterange.md) | OH_NativeXComponent_ExpectedRateRange | Defines the expected frame rate range.|
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) | OH_NativeXComponent | Provides an encapsulated **OH_NativeXComponent** instance.|
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md) | OH_NativeXComponent_KeyEvent | Provides an encapsulated **OH_NativeXComponent_KeyEvent** instance.|
| [OH_NativeXComponent_ExtraMouseEventInfo](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-extramouseeventinfo.md) | OH_NativeXComponent_ExtraMouseEventInfo | Provides an encapsulated instance of extended mouse event information.|
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) | OH_ArkUI_SurfaceHolder | Provides an encapsulated **OH_ArkUI_SurfaceHolder** instance.|
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) | OH_ArkUI_SurfaceCallback | Defines surface lifecycle callback functions.|
| [OHNativeWindow](capi-oh-nativexcomponent-native-xcomponent-nativewindow.md) | OHNativeWindow | Provides an encapsulated **NativeWindow** instance.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [anonymous](#anonymous) | - | Enumerates the API access states.|
| [ArkUI_XComponent_ImageAnalyzerState](#arkui_xcomponent_imageanalyzerstate) | ArkUI_XComponent_ImageAnalyzerState | Enumerates the AI image analyzer error codes of the XComponent.|
| [OH_NativeXComponent_TouchEventType](#oh_nativexcomponent_toucheventtype) | OH_NativeXComponent_TouchEventType | Enumerates the touch event types.|
| [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype) | OH_NativeXComponent_TouchPointToolType | Enumerates the touch point tool types.|
| [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype) | OH_NativeXComponent_EventSourceType | Enumerates the touch event source types.|
| [OH_NativeXComponent_MouseEventAction](#oh_nativexcomponent_mouseeventaction) | OH_NativeXComponent_MouseEventAction | Enumerates the mouse event actions.|
| [OH_NativeXComponent_MouseEventButton](#oh_nativexcomponent_mouseeventbutton) | OH_NativeXComponent_MouseEventButton | Enumerates the mouse event buttons.|
| [OH_NativeXComponent_TouchEvent_SourceTool](#oh_nativexcomponent_touchevent_sourcetool) | OH_NativeXComponent_TouchEvent_SourceTool | Enumerates the source tool types of touch events.|

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_NativeXComponent_GetXComponentId(OH_NativeXComponent* component, char* id, uint64_t* size)](#oh_nativexcomponent_getxcomponentid) | Obtains the ID of ArkUI XComponent.|
| [int32_t OH_NativeXComponent_GetXComponentSize(OH_NativeXComponent* component, const void* window, uint64_t* width, uint64_t* height)](#oh_nativexcomponent_getxcomponentsize) | Obtains the size of the surface held by the ArkUI XComponent.|
| [int32_t OH_NativeXComponent_GetXComponentOffset(OH_NativeXComponent* component, const void* window, double* x, double* y)](#oh_nativexcomponent_getxcomponentoffset) | Obtains the offset of the surface held by the XComponent relative to the upper left corner of its parent component.|
| [int32_t OH_NativeXComponent_GetTouchEvent(OH_NativeXComponent* component, const void* window, OH_NativeXComponent_TouchEvent* touchEvent)](#oh_nativexcomponent_gettouchevent) | Obtains the touch event scheduled by the ArkUI XComponent.|
| [int32_t OH_NativeXComponent_GetTouchPointToolType(OH_NativeXComponent* component, uint32_t pointIndex, OH_NativeXComponent_TouchPointToolType* toolType)](#oh_nativexcomponent_gettouchpointtooltype) | Obtains the ArkUI XComponent touch point tool type.|
| [int32_t OH_NativeXComponent_GetTouchPointTiltX(OH_NativeXComponent* component, uint32_t pointIndex, float* tiltX)](#oh_nativexcomponent_gettouchpointtiltx) | Obtains the angle between the Y-Z plane of the ArkUI XComponent touch point and the x-axis.|
| [int32_t OH_NativeXComponent_GetTouchPointTiltY(OH_NativeXComponent* component, uint32_t pointIndex, float* tiltY)](#oh_nativexcomponent_gettouchpointtilty) | Obtains the angle between the X-Z plane of the ArkUI XComponent touch point and the y-axis.|
| [int32_t OH_NativeXComponent_GetTouchPointWindowX(OH_NativeXComponent* component, uint32_t pointIndex, float* windowX)](#oh_nativexcomponent_gettouchpointwindowx) | Obtains the x-coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.|
| [int32_t OH_NativeXComponent_GetTouchPointWindowY(OH_NativeXComponent* component, uint32_t pointIndex, float* windowY)](#oh_nativexcomponent_gettouchpointwindowy) | Obtains the y-coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.|
| [int32_t OH_NativeXComponent_GetTouchPointDisplayX(OH_NativeXComponent* component, uint32_t pointIndex, float* displayX)](#oh_nativexcomponent_gettouchpointdisplayx) | Obtains the x-coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.|
| [int32_t OH_NativeXComponent_GetTouchPointDisplayY(OH_NativeXComponent* component, uint32_t pointIndex, float* displayY)](#oh_nativexcomponent_gettouchpointdisplayy) | Obtains the y-coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.|
| [int32_t OH_NativeXComponent_GetHistoricalPoints(OH_NativeXComponent* component, const void* window, int32_t* size, OH_NativeXComponent_HistoricalPoint** historicalPoints)](#oh_nativexcomponent_gethistoricalpoints) | Obtains the historical touch point data for the touch event of an **OH_NativeXComponent** instance. Some input devices report touch points at very high frequencies (up to 1 ms intervals). However, since UI updates typically do not require such high-frequency updates, the system consolidates touch events and reports them once per frame. All touch points collected during the current frame are preserved as historical touch points for applications that need direct access to this raw data.|
| [int32_t OH_NativeXComponent_GetMouseEvent(OH_NativeXComponent* component, const void* window, OH_NativeXComponent_MouseEvent* mouseEvent)](#oh_nativexcomponent_getmouseevent) | Obtains the mouse event scheduled by the ArkUI XComponent.|
| [int32_t OH_NativeXComponent_RegisterCallback(OH_NativeXComponent* component, OH_NativeXComponent_Callback* callback)](#oh_nativexcomponent_registercallback) | Registers a callback for the [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [int32_t OH_NativeXComponent_RegisterMouseEventCallback(OH_NativeXComponent* component, OH_NativeXComponent_MouseEvent_Callback* callback)](#oh_nativexcomponent_registermouseeventcallback) | Registers a mouse event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [int32_t OH_NativeXComponent_GetExtraMouseEventInfo(OH_NativeXComponent* component, OH_NativeXComponent_ExtraMouseEventInfo** extraMouseEventInfo)](#oh_nativexcomponent_getextramouseeventinfo) | Obtains extended mouse event information from this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [int32_t OH_NativeXComponent_GetMouseEventModifierKeyStates (OH_NativeXComponent_ExtraMouseEventInfo* extraMouseEventInfo, uint64_t* keys)](#oh_nativexcomponent_getmouseeventmodifierkeystates) | Obtains the state of modifier keys from an [OH_NativeXComponent_ExtraMouseEventInfo](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-extramouseeventinfo.md) instance.|
| [int32_t OH_NativeXComponent_RegisterFocusEventCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))](#oh_nativexcomponent_registerfocuseventcallback) | Registers a focus event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [int32_t OH_NativeXComponent_RegisterKeyEventCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))](#oh_nativexcomponent_registerkeyeventcallback) | Registers a key event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [int32_t OH_NativeXComponent_RegisterBlurEventCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))](#oh_nativexcomponent_registerblureventcallback) | Registers a blur event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [int32_t OH_NativeXComponent_GetKeyEvent(OH_NativeXComponent* component, OH_NativeXComponent_KeyEvent** keyEvent)](#oh_nativexcomponent_getkeyevent) | Obtains the key event scheduled by the ArkUI XComponent.|
| [int32_t OH_NativeXComponent_GetKeyEventAction(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_KeyAction* action)](#oh_nativexcomponent_getkeyeventaction) | Obtains the action of the specified key event.|
| [int32_t OH_NativeXComponent_GetKeyEventCode(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_KeyCode* code)](#oh_nativexcomponent_getkeyeventcode) | Obtains the key code of the specified key event.|
| [int32_t OH_NativeXComponent_GetKeyEventSourceType(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_EventSourceType* sourceType)](#oh_nativexcomponent_getkeyeventsourcetype) | Obtains the source type of the specified key event.|
| [int32_t OH_NativeXComponent_GetKeyEventDeviceId(OH_NativeXComponent_KeyEvent* keyEvent, int64_t* deviceId)](#oh_nativexcomponent_getkeyeventdeviceid) | Obtains the device ID of the specified key event.|
| [int32_t OH_NativeXComponent_GetKeyEventTimestamp(OH_NativeXComponent_KeyEvent* keyEvent, int64_t* timestamp)](#oh_nativexcomponent_getkeyeventtimestamp) | Obtains the timestamp of the specified key event.|
| [int32_t OH_NativeXComponent_GetKeyEventModifierKeyStates(OH_NativeXComponent_KeyEvent* keyEvent, uint64_t* keys)](#oh_nativexcomponent_getkeyeventmodifierkeystates) | Obtains the state of modifier keys from a key event.|
| [int32_t OH_NativeXComponent_GetKeyEventNumLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isNumLockOn)](#oh_nativexcomponent_getkeyeventnumlockstate) | Obtains the state of the NumLock key from a key event.|
| [int32_t OH_NativeXComponent_GetKeyEventCapsLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isCapsLockOn)](#oh_nativexcomponent_getkeyeventcapslockstate) | Obtains the state of the CapsLock key from a key event.|
| [int32_t OH_NativeXComponent_GetKeyEventScrollLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isScrollLockOn)](#oh_nativexcomponent_getkeyeventscrolllockstate) | Obtains the state of the ScrollLock key from a key event.|
| [int32_t OH_NativeXComponent_SetExpectedFrameRateRange(OH_NativeXComponent* component, OH_NativeXComponent_ExpectedRateRange* range)](#oh_nativexcomponent_setexpectedframeraterange) | Sets the expected frame rate range.|
| [int32_t OH_NativeXComponent_RegisterOnFrameCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, uint64_t timestamp, uint64_t targetTimestamp))](#oh_nativexcomponent_registeronframecallback) | Registers the display update callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and enables the callback for each frame.|
| [int32_t OH_NativeXComponent_UnregisterOnFrameCallback(OH_NativeXComponent* component)](#oh_nativexcomponent_unregisteronframecallback) | Deregisters the display update callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and disables the callback for each frame.|
| [int32_t OH_NativeXComponent_AttachNativeRootNode(OH_NativeXComponent* component, ArkUI_NodeHandle root)](#oh_nativexcomponent_attachnativerootnode) | Attaches the UI component created through the native API of ArkUI to this **OH_NativeXComponent** instance.|
| [int32_t OH_NativeXComponent_DetachNativeRootNode(OH_NativeXComponent* component, ArkUI_NodeHandle root)](#oh_nativexcomponent_detachnativerootnode) | Detaches the native component of ArkUI from this **OH_NativeXComponent** instance.|
| [int32_t OH_NativeXComponent_RegisterUIInputEventCallback(OH_NativeXComponent *component, void (\*callback)(OH_NativeXComponent *component, ArkUI_UIInputEvent *event,ArkUI_UIInputEvent_Type type),ArkUI_UIInputEvent_Type type)](#oh_nativexcomponent_registeruiinputeventcallback) | Registers a UI input event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and enables this callback to be invoked when a UI input event is received. Currently, only axis events are supported.|
| [int32_t OH_NativeXComponent_RegisterOnTouchInterceptCallback(OH_NativeXComponent* component, HitTestMode (\*callback)(OH_NativeXComponent* component, ArkUI_UIInputEvent* event))](#oh_nativexcomponent_registerontouchinterceptcallback) | Registers a custom event intercept callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and enables this callback to be invoked during hit testing. UI input–related operations are not supported on event objects received through this callback. For full functionality, use the [NODE_ON_TOUCH_INTERCEPT](capi-native-node-h.md#arkui_nodeeventtype) event on native nodes instead.|
| [int32_t OH_NativeXComponent_SetNeedSoftKeyboard(OH_NativeXComponent* component, bool needSoftKeyboard)](#oh_nativexcomponent_setneedsoftkeyboard) | Sets whether the soft keyboard is required for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [int32_t OH_NativeXComponent_RegisterSurfaceShowCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))](#oh_nativexcomponent_registersurfaceshowcallback) | Registers a surface display callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. This callback is invoked after the application is switched to the foreground.|
| [int32_t OH_NativeXComponent_RegisterSurfaceHideCallback(OH_NativeXComponent* component, void (\*callback)(OH_NativeXComponent* component, void* window))](#oh_nativexcomponent_registersurfacehidecallback) | Registers a surface hiding callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. This callback is invoked after the application is switched to the background.|
| [int32_t OH_NativeXComponent_GetTouchEventSourceType(OH_NativeXComponent* component, int32_t pointId, OH_NativeXComponent_EventSourceType* sourceType)](#oh_nativexcomponent_gettoucheventsourcetype) | Obtains the touch event source type of an **OH_NativeXComponent** instance.|
| [OH_NativeXComponent* OH_NativeXComponent_GetNativeXComponent(ArkUI_NodeHandle node)](#oh_nativexcomponent_getnativexcomponent) | Obtains a pointer of the [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) type based on the specified component instance created by the native API.|
| [int32_t OH_NativeXComponent_GetNativeAccessibilityProvider(OH_NativeXComponent* component, ArkUI_AccessibilityProvider** handle)](#oh_nativexcomponent_getnativeaccessibilityprovider) | Obtains the accessibility provider handle for an ArkUI XComponent.|
| [int32_t OH_NativeXComponent_RegisterKeyEventCallbackWithResult(OH_NativeXComponent* component, bool (\*callback)(OH_NativeXComponent* component, void* window))](#oh_nativexcomponent_registerkeyeventcallbackwithresult) | Registers a key event callback with a return value for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. The callback must return a result (**true** or **false**). If the callback returns **true**, the event will not be further propagated. If it returns **false**, the event will continue to be processed according to the normal event handling flow.|
| [int32_t OH_ArkUI_XComponent_StartImageAnalyzer(ArkUI_NodeHandle node, void* userData, void (\*callback)(ArkUI_NodeHandle node, ArkUI_XComponent_ImageAnalyzerState statusCode, void* userData))](#oh_arkui_xcomponent_startimageanalyzer) | Starts AI image analysis for this XComponent instance. Before calling this API, make sure the AI image analyzer is enabled.|
| [int32_t OH_ArkUI_XComponent_StopImageAnalyzer(ArkUI_NodeHandle node)](#oh_arkui_xcomponent_stopimageanalyzer) | Stops AI image analysis for this XComponent instance.|
| [OH_ArkUI_SurfaceHolder* OH_ArkUI_SurfaceHolder_Create(ArkUI_NodeHandle node)](#oh_arkui_surfaceholder_create) | Creates an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) object for an **XComponent**.|
| [void OH_ArkUI_SurfaceHolder_Dispose(OH_ArkUI_SurfaceHolder* surfaceHolder)](#oh_arkui_surfaceholder_dispose) | Disposes an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) object.|
| [int32_t OH_ArkUI_SurfaceHolder_SetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder, void* userData)](#oh_arkui_surfaceholder_setuserdata) | Stores custom data in an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| [void* OH_ArkUI_SurfaceHolder_GetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder)](#oh_arkui_surfaceholder_getuserdata) | Obtains the custom data stored in an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| [OH_ArkUI_SurfaceCallback* OH_ArkUI_SurfaceCallback_Create()](#oh_arkui_surfacecallback_create) | Creates an [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) object.|
| [void OH_ArkUI_SurfaceCallback_Dispose(OH_ArkUI_SurfaceCallback* callback)](#oh_arkui_surfacecallback_dispose) | Disposes an [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) object.|
| [void OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent(OH_ArkUI_SurfaceCallback* callback,void (\*onSurfaceCreated)(OH_ArkUI_SurfaceHolder* surfaceHolder))](#oh_arkui_surfacecallback_setsurfacecreatedevent) | Sets the creation callback event in the surface lifecycle callbacks.|
| [void OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent(OH_ArkUI_SurfaceCallback* callback,void (\*onSurfaceChanged)(OH_ArkUI_SurfaceHolder* surfaceHolder, uint64_t width, uint64_t height))](#oh_arkui_surfacecallback_setsurfacechangedevent) | Sets the size change callback event in the surface lifecycle callbacks.|
| [void OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent(OH_ArkUI_SurfaceCallback* callback,void (\*onSurfaceDestroyed)(OH_ArkUI_SurfaceHolder* surfaceHolder))](#oh_arkui_surfacecallback_setsurfacedestroyedevent) | Sets the destruction callback event in the surface lifecycle callbacks.|
| [int32_t OH_ArkUI_SurfaceHolder_AddSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder,OH_ArkUI_SurfaceCallback* callback)](#oh_arkui_surfaceholder_addsurfacecallback) | Adds a surface lifecycle callback to an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| [int32_t OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder,OH_ArkUI_SurfaceCallback* callback)](#oh_arkui_surfaceholder_removesurfacecallback) | Removes a previously added surface lifecycle callback from an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| [OHNativeWindow* OH_ArkUI_XComponent_GetNativeWindow(OH_ArkUI_SurfaceHolder* surfaceHolder)](#oh_arkui_xcomponent_getnativewindow) | Obtains the **NativeWindow** instance associated with an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| [int32_t OH_ArkUI_XComponent_SetAutoInitialize(ArkUI_NodeHandle node, bool autoInitialize)](#oh_arkui_xcomponent_setautoinitialize) | Sets whether the **XComponent** component needs to automatically initialize the surface.|
| [int32_t OH_ArkUI_XComponent_Initialize(ArkUI_NodeHandle node)](#oh_arkui_xcomponent_initialize) | Initializes the surface held by the **XComponent** component.|
| [int32_t OH_ArkUI_XComponent_Finalize(ArkUI_NodeHandle node)](#oh_arkui_xcomponent_finalize) | Destroys the surface held by the **XComponent** component.|
| [int32_t OH_ArkUI_XComponent_IsInitialized(ArkUI_NodeHandle node, bool* isInitialized)](#oh_arkui_xcomponent_isinitialized) | Checks whether the surface held by the **XComponent** component is initialized.|
| [int32_t OH_ArkUI_XComponent_SetExpectedFrameRateRange(ArkUI_NodeHandle node, OH_NativeXComponent_ExpectedRateRange range)](#oh_arkui_xcomponent_setexpectedframeraterange) | Sets the expected frame rate range for the XComponent.|
| [int32_t OH_ArkUI_XComponent_RegisterOnFrameCallback(ArkUI_NodeHandle node,void (\*callback)(ArkUI_NodeHandle node, uint64_t timestamp, uint64_t targetTimestamp))](#oh_arkui_xcomponent_registeronframecallback) | Registers a frame callback function for the XComponent.|
| [int32_t OH_ArkUI_XComponent_UnregisterOnFrameCallback(ArkUI_NodeHandle node)](#oh_arkui_xcomponent_unregisteronframecallback) | Unregisters the frame callback function for the XComponent.|
| [int32_t OH_ArkUI_XComponent_SetNeedSoftKeyboard(ArkUI_NodeHandle node, bool needSoftKeyboard)](#oh_arkui_xcomponent_setneedsoftkeyboard) | Sets whether the soft keyboard is required for the XComponent.|
| [ArkUI_AccessibilityProvider* OH_ArkUI_AccessibilityProvider_Create(ArkUI_NodeHandle node)](#oh_arkui_accessibilityprovider_create) | Creates an [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) instance for this **XComponent** instance.|
| [void OH_ArkUI_AccessibilityProvider_Dispose(ArkUI_AccessibilityProvider* provider)](#oh_arkui_accessibilityprovider_dispose) | Disposes the [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) instance created using [OH_ArkUI_AccessibilityProvider_Create](capi-native-interface-xcomponent-h.md#oh_arkui_accessibilityprovider_create).|
| [void OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent(OH_ArkUI_SurfaceCallback* callback, void (\*onSurfaceShow)(OH_ArkUI_SurfaceHolder* surfaceHolder))](#oh_arkui_surfacecallback_setsurfaceshowevent) | Sets a surface display callback for this [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) instance. This callback is invoked when the application window has moved from the background to the foreground.|
| [void OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent(OH_ArkUI_SurfaceCallback* callback, void (\*onSurfaceHide)(OH_ArkUI_SurfaceHolder* surfaceHolder))](#oh_arkui_surfacecallback_setsurfacehideevent) | Sets a surface hiding callback for this [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) instance. This callback is invoked when the application window has moved from the foreground to the background.|

### Variables

| Name| Description|
| -- | -- |
| const uint32_t OH_XCOMPONENT_ID_LEN_MAX = 128 | Maximum length of the ArkUI XComponent ID.<br>**Since**: 8|
| const uint32_t OH_MAX_TOUCH_POINTS_NUMBER = 10 | Maximum number of identifiable touch points in a touch event.<br>**Since**: 8|

## Enum Description

### anonymous

```
enum anonymous
```

**Description**


Enumerates the API access states.

**Since**: 8

| Value| Description|
| -- | -- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0 | Success.|
| OH_NATIVEXCOMPONENT_RESULT_FAILED = -1 | Failure.|
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2 | Invalid parameter.|

### ArkUI_XComponent_ImageAnalyzerState

```
enum ArkUI_XComponent_ImageAnalyzerState
```

**Description**


Enumerates the AI image analyzer error codes of the XComponent.

**Since**: 18

| Value| Description|
| -- | -- |
| ARKUI_XCOMPONENT_AI_ANALYSIS_FINISHED = 0 | AI image analysis is complete.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_DISABLED = 110000 | AI image analysis is disabled.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_UNSUPPORTED = 110001 | The device does not support AI image analysis.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_ONGOING = 110002 | AI image analysis is in progress.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_STOPPED = 110003 | AI image analysis has been stopped.|

### OH_NativeXComponent_TouchEventType

```
enum OH_NativeXComponent_TouchEventType
```

**Description**


Enumerates the touch event types.

**Since**: 8

| Value| Description|
| -- | -- |
| OH_NATIVEXCOMPONENT_DOWN = 0 | The touch event is triggered when a finger is pressed.|
| OH_NATIVEXCOMPONENT_UP | The touch event is triggered when a finger is lifted.|
| OH_NATIVEXCOMPONENT_MOVE | The touch event is triggered when a finger is moved on the screen.|
| OH_NATIVEXCOMPONENT_CANCEL | The event is triggered when a touch event is canceled.|
| OH_NATIVEXCOMPONENT_UNKNOWN | Invalid touch type.|

### OH_NativeXComponent_TouchPointToolType

```
enum OH_NativeXComponent_TouchPointToolType
```

**Description**


Enumerates the touch point tool types.

**Since**: 9

| Value| Description|
| -- | -- |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN = 0 | Unknown tool type.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER | Finger.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN | Stylus.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER | Rubber.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH | Brush.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL | Pencil.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH | Air brush.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE | Mouse.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS | Lens.|

### OH_NativeXComponent_EventSourceType

```
enum OH_NativeXComponent_EventSourceType
```

**Description**


Enumerates the touch event source types.

**Since**: 9

| Value| Description|
| -- | -- |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN = 0 | Unknown source type.|
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE | Source that generates a mouse multi-click event.|
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN | Source that generates a touchscreen multitouch event.|
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD | Source that generates a touchpad multitouch event.|
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK | Source that generates a joystick multitouch event.|
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD | Source that generates a key event.<br>**Since**: 10|

### OH_NativeXComponent_MouseEventAction

```
enum OH_NativeXComponent_MouseEventAction
```

**Description**


Enumerates the mouse event actions.

**Since**: 9

| Value| Description                             |
| -- |---------------------------------|
| OH_NATIVEXCOMPONENT_MOUSE_NONE = 0 | Invalid mouse event.                        |
| OH_NATIVEXCOMPONENT_MOUSE_PRESS | Mouse button press.                 |
| OH_NATIVEXCOMPONENT_MOUSE_RELEASE | Mouse button release.                 |
| OH_NATIVEXCOMPONENT_MOUSE_MOVE | Mouse movement.               |
| OH_NATIVEXCOMPONENT_MOUSE_CANCEL | Mouse button canceling.<br>**Since**: 18|

### OH_NativeXComponent_MouseEventButton

```
enum OH_NativeXComponent_MouseEventButton
```

**Description**


Enumerates the mouse event buttons.

**Since**: 9

| Value| Description|
| -- | -- |
| OH_NATIVEXCOMPONENT_NONE_BUTTON = 0 | No button.|
| OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01 | Left mouse button.|
| OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02 | Right mouse button.|
| OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04 | Middle mouse button.|
| OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08 | Back button on the left of the mouse.|
| OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10 | Forward key on the left of the mouse.|

### OH_NativeXComponent_TouchEvent_SourceTool

```
enum OH_NativeXComponent_TouchEvent_SourceTool
```

**Description**


Enumerates the source tool types of touch events.

**Since**: 10

| Value| Description|
| -- | -- |
| OH_NATIVEXCOMPONENT_SOURCETOOL_UNKNOWN = 0 | Unknown source tool.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_FINGER = 1 | Finger.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_PEN = 2 | Pen.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_RUBBER = 3 | Eraser.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_BRUSH = 4 | Brush.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_PENCIL = 5 | Pencil.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_AIRBRUSH = 6 | Airbrush.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_MOUSE = 7 | Mouse pointer.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_LENS = 8 | Lens.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_TOUCHPAD = 9 | Touchpad.|


## Function Description

### OH_NativeXComponent_GetXComponentId()

```
int32_t OH_NativeXComponent_GetXComponentId(OH_NativeXComponent* component, char* id, uint64_t* size)
```

**Description**


Obtains the ID of ArkUI XComponent.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| char* id | Pointer to the character buffer for storing the ID of the [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. Note that null terminators will be attached to the character buffer, so the size of the character buffer should be at least one unit greater than the length of the real ID. The recommended size is \[[OH_XCOMPONENT_ID_LEN_MAX](#variables) + 1].|
| uint64_t* size | Pointer to the length of the ID, used to receive the length information of the ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetXComponentSize()

```
int32_t OH_NativeXComponent_GetXComponentSize(OH_NativeXComponent* component, const void* window, uint64_t* width, uint64_t* height)
```

**Description**


Obtains the size of the surface held by the ArkUI XComponent.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| const void* window | Handle to the **NativeWindow** instance.|
| uint64_t* width | Pointer to the width of the current surface.|
| uint64_t* height | Pointer to the height of the current surface.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetXComponentOffset()

```
int32_t OH_NativeXComponent_GetXComponentOffset(OH_NativeXComponent* component, const void* window, double* x, double* y)
```

**Description**


Obtains the offset of the surface held by the XComponent relative to the upper left corner of its parent component.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| const void* window | Handle to the **NativeWindow** instance.|
| double* x | Pointer to the x-coordinate of the current surface relative to the upper left corner of the XComponent's parent component.|
| double* y | Pointer to the y-coordinate of the current surface relative to the upper left corner of the XComponent's parent component.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetTouchEvent()

```
int32_t OH_NativeXComponent_GetTouchEvent(OH_NativeXComponent* component, const void* window, OH_NativeXComponent_TouchEvent* touchEvent)
```

**Description**


Obtains the touch event scheduled by the ArkUI XComponent.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| const void* window | Handle to the **NativeWindow** instance.|
| [OH_NativeXComponent_TouchEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-touchevent.md)* touchEvent | Pointer to the current touch event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetTouchPointToolType()

```
int32_t OH_NativeXComponent_GetTouchPointToolType(OH_NativeXComponent* component, uint32_t pointIndex,OH_NativeXComponent_TouchPointToolType* toolType)
```

**Description**


Obtains the ArkUI XComponent touch point tool type.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| uint32_t pointIndex | Pointer to the index of the touch point.|
| [OH_NativeXComponent_TouchPointToolType](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_touchpointtooltype)* toolType | Pointer to the tool type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetTouchPointTiltX()

```
int32_t OH_NativeXComponent_GetTouchPointTiltX(OH_NativeXComponent* component, uint32_t pointIndex, float* tiltX)
```

**Description**


Obtains the angle between the Y-Z plane of the ArkUI XComponent touch point and the x-axis.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| uint32_t pointIndex | Pointer to the index of the touch point.|
| float* tiltX | Pointer to the angle between the Y-Z plane of the touch point and the x-axis.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetTouchPointTiltY()

```
int32_t OH_NativeXComponent_GetTouchPointTiltY(OH_NativeXComponent* component, uint32_t pointIndex, float* tiltY)
```

**Description**


Obtains the angle between the X-Z plane of the ArkUI XComponent touch point and the y-axis.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| uint32_t pointIndex | Pointer to the index of the touch point.|
| float* tiltY | Pointer to the angle between the X-Z plane of the touch point and the y-axis.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetTouchPointWindowX()

```
int32_t OH_NativeXComponent_GetTouchPointWindowX(OH_NativeXComponent* component, uint32_t pointIndex, float* windowX)
```

**Description**


Obtains the x-coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| uint32_t pointIndex | Pointer to the index of the touch point.|
| float* windowX | Pointer to the x-coordinate of the touch point relative to the upper left corner of the application window.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if the component, windowX, or native XComponent is a null pointer.|

### OH_NativeXComponent_GetTouchPointWindowY()

```
int32_t OH_NativeXComponent_GetTouchPointWindowY(OH_NativeXComponent* component, uint32_t pointIndex, float* windowY)
```

**Description**


Obtains the y-coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| uint32_t pointIndex | Pointer to the index of the touch point.|
| float* windowY | Pointer to the y-coordinate of the touch point relative to the upper left corner of the application window.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br> Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br> Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if the component, windowY, or native XComponent is a null pointer.|

### OH_NativeXComponent_GetTouchPointDisplayX()

```
int32_t OH_NativeXComponent_GetTouchPointDisplayX(OH_NativeXComponent* component, uint32_t pointIndex, float* displayX)
```

**Description**


Obtains the x-coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| uint32_t pointIndex | Pointer to the index of the touch point.|
| float* displayX | Pointer to the x-coordinate of the touch point relative to the upper left corner of the screen.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if the component, displayX, or native XComponent is a null pointer.|

### OH_NativeXComponent_GetTouchPointDisplayY()

```
int32_t OH_NativeXComponent_GetTouchPointDisplayY(OH_NativeXComponent* component, uint32_t pointIndex, float* displayY)
```

**Description**


Obtains the y-coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| uint32_t pointIndex | Pointer to the index of the touch point.|
| float* displayY | Pointer to the y-coordinate of the touch point relative to the upper left corner of the screen.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if the component, displayY, or native XComponent is a null pointer.|

### OH_NativeXComponent_GetHistoricalPoints()

```
int32_t OH_NativeXComponent_GetHistoricalPoints(OH_NativeXComponent* component, const void* window,int32_t* size, OH_NativeXComponent_HistoricalPoint** historicalPoints)
```

**Description**


Obtains the historical touch point data for the touch event of an **OH_NativeXComponent** instance. Some input devices report touch points at very high frequencies (up to 1 ms intervals). However, since UI updates typically do not require such high-frequency updates, the system consolidates touch events and reports them once per frame. All touch points collected during the current frame are preserved as historical touch points for applications that need direct access to this raw data.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| const void* window | Handle to the **NativeWindow** instance.|
| int32_t* size | Length of the historical touch point array.|
| [OH_NativeXComponent_HistoricalPoint](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-historicalpoint.md)** historicalPoints | Pointer to the historical touch point array.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetMouseEvent()

```
int32_t OH_NativeXComponent_GetMouseEvent(OH_NativeXComponent* component, const void* window, OH_NativeXComponent_MouseEvent* mouseEvent)
```

**Description**


Obtains the mouse event scheduled by the ArkUI XComponent.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| const void* window | Handle to the **NativeWindow** instance.|
| [OH_NativeXComponent_MouseEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-mouseevent.md)* mouseEvent | Pointer to the current mouse event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_RegisterCallback()

```
int32_t OH_NativeXComponent_RegisterCallback(OH_NativeXComponent* component, OH_NativeXComponent_Callback* callback)
```

**Description**


Registers a callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [OH_NativeXComponent_Callback](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-callback.md)* callback | Pointer to the surface lifecycle and touch event callback.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_RegisterMouseEventCallback()

```
int32_t OH_NativeXComponent_RegisterMouseEventCallback(OH_NativeXComponent* component, OH_NativeXComponent_MouseEvent_Callback* callback)
```

**Description**


Registers a mouse event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [OH_NativeXComponent_MouseEvent_Callback](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-mouseevent-callback.md)* callback | Pointer to the mouse event callback.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetExtraMouseEventInfo()

```
int32_t OH_NativeXComponent_GetExtraMouseEventInfo(OH_NativeXComponent* component, OH_NativeXComponent_ExtraMouseEventInfo** extraMouseEventInfo)
```

**Description**


Obtains extended mouse event information from this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [OH_NativeXComponent_ExtraMouseEventInfo](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-extramouseeventinfo.md)** extraMouseEventInfo | Address of a pointer to the [OH_NativeXComponent_ExtraMouseEventInfo](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-extramouseeventinfo.md) type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_GetMouseEventModifierKeyStates()

```
int32_t OH_NativeXComponent_GetMouseEventModifierKeyStates(OH_NativeXComponent_ExtraMouseEventInfo* extraMouseEventInfo, uint64_t* keys)
```

**Description**


Obtains the state of modifier keys from an [OH_NativeXComponent_ExtraMouseEventInfo](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-extramouseeventinfo.md) instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_ExtraMouseEventInfo](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-extramouseeventinfo.md)* extraMouseEventInfo | Pointer to the extended mouse event information instance.|
| uint64_t* keys | Address of a 64-bit unsigned integer to receive the modifier key press state information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_RegisterFocusEventCallback()

```
int32_t OH_NativeXComponent_RegisterFocusEventCallback(OH_NativeXComponent* component, void (*callback)(OH_NativeXComponent* component, void* window))
```

**Description**


Registers a focus event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void (\*callback)(OH_NativeXComponent* component, void* window) | Pointer to the focus event callback. - **window**: handle to the **NativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_RegisterKeyEventCallback()

```
int32_t OH_NativeXComponent_RegisterKeyEventCallback(OH_NativeXComponent* component, void (*callback)(OH_NativeXComponent* component, void* window))
```

**Description**


Registers a key event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void (\*callback)(OH_NativeXComponent* component, void* window) | Pointer to the key event callback. - **window**: handle to the **NativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.|

### OH_NativeXComponent_RegisterBlurEventCallback()

```
int32_t OH_NativeXComponent_RegisterBlurEventCallback(OH_NativeXComponent* component, void (*callback)(OH_NativeXComponent* component, void* window))
```

**Description**


Registers a blur event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void (\*callback)(OH_NativeXComponent* component, void* window) | Pointer to the blur event callback. - **window**: handle to the **NativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.|

### OH_NativeXComponent_GetKeyEvent()

```
int32_t OH_NativeXComponent_GetKeyEvent(OH_NativeXComponent* component, OH_NativeXComponent_KeyEvent** keyEvent)
```

**Description**


Obtains the key event scheduled by the ArkUI XComponent.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)** keyEvent | Pointer to the current key event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetKeyEventAction()

```
int32_t OH_NativeXComponent_GetKeyEventAction(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_KeyAction* action)
```

**Description**


Obtains the action of the specified key event.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to an [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md) instance.|
| [OH_NativeXComponent_KeyAction](capi-native-xcomponent-key-event-h.md#oh_nativexcomponent_keyaction)* action | Pointer to the key event action.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetKeyEventCode()

```
int32_t OH_NativeXComponent_GetKeyEventCode(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_KeyCode* code)
```

**Description**


Obtains the key code of the specified key event.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to an [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md) instance.|
| [OH_NativeXComponent_KeyCode](capi-native-xcomponent-key-event-h.md#oh_nativexcomponent_keycode)* code | Pointer to the key code of the key event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetKeyEventSourceType()

```
int32_t OH_NativeXComponent_GetKeyEventSourceType(OH_NativeXComponent_KeyEvent* keyEvent, OH_NativeXComponent_EventSourceType* sourceType)
```

**Description**


Obtains the source type of the specified key event.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to an [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md) instance.|
| [OH_NativeXComponent_EventSourceType](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_eventsourcetype)* sourceType | Pointer to the source type of the key event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetKeyEventDeviceId()

```
int32_t OH_NativeXComponent_GetKeyEventDeviceId(OH_NativeXComponent_KeyEvent* keyEvent, int64_t* deviceId)
```

**Description**


Obtains the device ID of the specified key event.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to an [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md) instance.|
| int64_t* deviceId | Pointer to the device ID of the key event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetKeyEventTimestamp()

```
int32_t OH_NativeXComponent_GetKeyEventTimestamp(OH_NativeXComponent_KeyEvent* keyEvent, int64_t* timestamp)
```

**Description**


Obtains the timestamp of the specified key event.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to an [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md) instance.|
| int64_t* timestamp | Pointer to the timestamp of the key event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_GetKeyEventModifierKeyStates()

```
int32_t OH_NativeXComponent_GetKeyEventModifierKeyStates(OH_NativeXComponent_KeyEvent* keyEvent, uint64_t* keys)
```

**Description**


Obtains the state of modifier keys from a key event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to the key event.|
| uint64_t* keys | Address of a 64-bit unsigned integer to receive the modifier key press state information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_GetKeyEventNumLockState()

```
int32_t OH_NativeXComponent_GetKeyEventNumLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isNumLockOn)
```

**Description**


Obtains the state of the NumLock key from a key event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to the key event.|
| bool* isNumLockOn | Address of a boolean variable to receive the state of the NumLock key.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_GetKeyEventCapsLockState()

```
int32_t OH_NativeXComponent_GetKeyEventCapsLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isCapsLockOn)
```

**Description**


Obtains the state of the CapsLock key from a key event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to the key event.|
| bool* isCapsLockOn | Address of a boolean variable to receive the state of the CapsLock key.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_GetKeyEventScrollLockState()

```
int32_t OH_NativeXComponent_GetKeyEventScrollLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isScrollLockOn)
```

**Description**


Obtains the state of the ScrollLock key from a key event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent_KeyEvent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-keyevent.md)* keyEvent | Pointer to the key event.|
| bool* isScrollLockOn | Address of a boolean variable to receive the state of the ScrollLock key.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_SetExpectedFrameRateRange()

```
int32_t OH_NativeXComponent_SetExpectedFrameRateRange(OH_NativeXComponent* component, OH_NativeXComponent_ExpectedRateRange* range)
```

**Description**


Sets the expected frame rate range.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [OH_NativeXComponent_ExpectedRateRange](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-expectedraterange.md)* range | Pointer to the expected frame rate information object of the [OH_NativeXComponent_ExpectedRateRange](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-expectedraterange.md) type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_RegisterOnFrameCallback()

```
int32_t OH_NativeXComponent_RegisterOnFrameCallback(OH_NativeXComponent* component,void (*callback)(OH_NativeXComponent* component, uint64_t timestamp, uint64_t targetTimestamp))
```

**Description**


Registers the display update callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and enables the callback for each frame.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void (\*callback)(OH_NativeXComponent* component, uint64_t timestamp, uint64_t targetTimestamp) | Pointer to the display update callback. - **timestamp**: time when the current frame arrives, in nanoseconds. - **targetTimestamp**: expected arrival time of the next frame, in nanoseconds.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.|

### OH_NativeXComponent_UnregisterOnFrameCallback()

```
int32_t OH_NativeXComponent_UnregisterOnFrameCallback(OH_NativeXComponent* component)
```

**Description**


Deregisters the display update callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and disables the callback for each frame.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_AttachNativeRootNode()

```
int32_t OH_NativeXComponent_AttachNativeRootNode(OH_NativeXComponent* component, ArkUI_NodeHandle root)
```

**Description**


Attaches the UI component created through the native API of ArkUI to this **OH_NativeXComponent** instance.

**Since**: 12

**Deprecated from**: 20

**Substitute**: [OH_ArkUI_NodeContent_AddNode](capi-native-node-h.md#oh_arkui_nodecontent_addnode)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) root | Pointer to the component instance created through the native API.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if a parameter error occurs.|

### OH_NativeXComponent_DetachNativeRootNode()

```
int32_t OH_NativeXComponent_DetachNativeRootNode(OH_NativeXComponent* component, ArkUI_NodeHandle root)
```

**Description**


Detaches the native component of ArkUI from this **OH_NativeXComponent** instance.

**Since**: 12

**Deprecated from**: 20

**Substitute**: [OH_ArkUI_NodeContent_RemoveNode](capi-native-node-h.md#oh_arkui_nodecontent_removenode)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) root | Pointer to the component instance created through the native API.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if a parameter error occurs.|

### OH_NativeXComponent_RegisterUIInputEventCallback()

```
int32_t OH_NativeXComponent_RegisterUIInputEventCallback(OH_NativeXComponent *component,void (*callback)(OH_NativeXComponent *component, ArkUI_UIInputEvent *event,ArkUI_UIInputEvent_Type type),ArkUI_UIInputEvent_Type type)
```

**Description**


Registers a UI input event callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and enables this callback to be invoked when a UI input event is received. Currently, only axis events are supported.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) *component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void (*callback)(OH_NativeXComponent *component, ArkUI_UIInputEvent *event,ArkUI_UIInputEvent_Type type) | Pointer to the UI input event callback. - **event**: pointer to the UI input event.|
| [ArkUI_UIInputEvent_Type](capi-ui-input-event-h.md#arkui_uiinputevent_type) type | Type of the current UI input event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_RegisterOnTouchInterceptCallback()

```
int32_t OH_NativeXComponent_RegisterOnTouchInterceptCallback(OH_NativeXComponent* component, HitTestMode (*callback)(OH_NativeXComponent* component, ArkUI_UIInputEvent* event))
```

**Description**


Registers a custom event intercept callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance and enables this callback to be invoked during hit testing. UI input–related operations are not supported on event objects received through this callback. For full functionality, use the [NODE_ON_TOUCH_INTERCEPT](capi-native-node-h.md#arkui_nodeeventtype) event on native nodes instead.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| HitTestMode (*callback)(OH_NativeXComponent* component, ArkUI_UIInputEvent* event) | Pointer to the custom event intercept callback. - **event**: pointer to the UI input event.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_NativeXComponent_SetNeedSoftKeyboard()

```
int32_t OH_NativeXComponent_SetNeedSoftKeyboard(OH_NativeXComponent* component, bool needSoftKeyboard)
```

**Description**


Sets whether the soft keyboard is required for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| bool needSoftKeyboard | Whether the soft keyboard is required for the current [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.|

### OH_NativeXComponent_RegisterSurfaceShowCallback()

```
int32_t OH_NativeXComponent_RegisterSurfaceShowCallback(OH_NativeXComponent* component, void (*callback)(OH_NativeXComponent* component, void* window))
```

**Description**


Registers a surface display callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. This callback is invoked after the application is switched to the foreground.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void (\*callback)(OH_NativeXComponent* component, void* window) | Pointer to the surface display callback. - **window**: handle to the **NativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.|

### OH_NativeXComponent_RegisterSurfaceHideCallback()

```
int32_t OH_NativeXComponent_RegisterSurfaceHideCallback(OH_NativeXComponent* component, void (*callback)(OH_NativeXComponent* component, void* window))
```

**Description**


Registers a surface hiding callback for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. This callback is invoked after the application is switched to the background.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| void (\*callback)(OH_NativeXComponent* component, void* window) | Pointer to the surface hiding callback. - **window**: handle to the **NativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.|

### OH_NativeXComponent_GetTouchEventSourceType()

```
int32_t OH_NativeXComponent_GetTouchEventSourceType(OH_NativeXComponent* component, int32_t pointId, OH_NativeXComponent_EventSourceType* sourceType)
```

**Description**


Obtains the touch event source type of an **OH_NativeXComponent** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| int32_t pointId | ID of the touch point. The touch event source type can be correctly returned only when the ID passed in is the ID of the touch point that triggers the touch event. Otherwise, **OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER** is returned.|
| [OH_NativeXComponent_EventSourceType](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_eventsourcetype)* sourceType | Pointer to the touch event source type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if a parameter error occurs.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_FAILED](capi-native-interface-xcomponent-h.md#anonymous) if any other error occurs.|

### OH_NativeXComponent_GetNativeXComponent()

```
OH_NativeXComponent* OH_NativeXComponent_GetNativeXComponent(ArkUI_NodeHandle node)
```

**Description**


Obtains a pointer of the [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) type based on the specified component instance created by the native API.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component instance created through the native API.|

**Returns**

| Type                      | Description|
|--------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|

### OH_NativeXComponent_GetNativeAccessibilityProvider()

```
int32_t OH_NativeXComponent_GetNativeAccessibilityProvider(OH_NativeXComponent* component, ArkUI_AccessibilityProvider** handle)
```

**Description**


Obtains the accessibility provider handle for an ArkUI XComponent.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)** handle | Pointer to an [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if a parameter error occurs.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_FAILED](capi-native-interface-xcomponent-h.md#anonymous) if any other error occurs.|

### OH_NativeXComponent_RegisterKeyEventCallbackWithResult()

```
int32_t OH_NativeXComponent_RegisterKeyEventCallbackWithResult(OH_NativeXComponent* component, bool (*callback)(OH_NativeXComponent* component, void* window))
```

**Description**


Registers a key event callback with a return value for this [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance. The callback must return a result (**true** or **false**). If the callback returns **true**, the event will not be further propagated. If it returns **false**, the event will continue to be processed according to the normal event handling flow.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | Pointer to an [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md) instance.|
| bool (*callback)(OH_NativeXComponent* component, void* window) | Pointer to the key event callback. - **window**: handle to the **NativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](capi-native-interface-xcomponent-h.md#anonymous) if the operation is successful.<br>Returns [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](capi-native-interface-xcomponent-h.md#anonymous) if a parameter error occurs.|

### OH_ArkUI_XComponent_StartImageAnalyzer()

```
int32_t OH_ArkUI_XComponent_StartImageAnalyzer(ArkUI_NodeHandle node, void* userData,void (*callback)(ArkUI_NodeHandle node, ArkUI_XComponent_ImageAnalyzerState statusCode, void* userData))
```

**Description**


Starts AI image analysis for this XComponent instance. Before calling this API, make sure the AI image analyzer is enabled.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | XComponent instance.|
|  void* userData | Pointer to the data that you need to obtain when the callback function is executed.|
| void (*callback)(ArkUI_NodeHandle node, ArkUI_XComponent_ImageAnalyzerState statusCode, void* userData) | Callback function triggered when the AI image analysis status is updated. - **statusCode**: one of the input parameters of the callback function, indicating the current image analysis status.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_XComponent_StopImageAnalyzer()

```
int32_t OH_ArkUI_XComponent_StopImageAnalyzer(ArkUI_NodeHandle node)
```

**Description**


Stops AI image analysis for this XComponent instance.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | XComponent instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SurfaceHolder_Create()

```
OH_ArkUI_SurfaceHolder* OH_ArkUI_SurfaceHolder_Create(ArkUI_NodeHandle node)
```

**Description**


Creates an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) object for an **XComponent**.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the XComponent instance created through the native API.|

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md)* | Pointer to the created [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) object.|

### OH_ArkUI_SurfaceHolder_Dispose()

```
void OH_ArkUI_SurfaceHolder_Dispose(OH_ArkUI_SurfaceHolder* surfaceHolder)
```

**Description**


Disposes an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) object.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md)* surfaceHolder | Pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|

### OH_ArkUI_SurfaceHolder_SetUserData()

```
int32_t OH_ArkUI_SurfaceHolder_SetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder, void* userData)
```

**Description**


Stores custom data in an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md)* surfaceHolder | Pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| void* userData | Pointer to the custom data to be stored.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SurfaceHolder_GetUserData()

```
void* OH_ArkUI_SurfaceHolder_GetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder)
```

**Description**


Obtains the custom data stored in an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md)* surfaceHolder | Pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| void* | Custom data.|

### OH_ArkUI_SurfaceCallback_Create()

```
OH_ArkUI_SurfaceCallback* OH_ArkUI_SurfaceCallback_Create()
```

**Description**


Creates an [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) object.

**Since**: 19

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* | Pointer to the created [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) object.|

### OH_ArkUI_SurfaceCallback_Dispose()

```
void OH_ArkUI_SurfaceCallback_Dispose(OH_ArkUI_SurfaceCallback* callback)
```

**Description**


Disposes an [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) object.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the target [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) instance.|

### OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent(OH_ArkUI_SurfaceCallback* callback,void (*onSurfaceCreated)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**


Sets the creation callback event in the surface lifecycle callbacks.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the surface lifecycle callback.|
| onSurfaceCreated | Callback event triggered when the surface is created. - **surfaceHolder**: pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|

### OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent(OH_ArkUI_SurfaceCallback* callback,void (*onSurfaceChanged)(OH_ArkUI_SurfaceHolder* surfaceHolder, uint64_t width, uint64_t height))
```

**Description**


Sets the size change callback event in the surface lifecycle callbacks.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the surface lifecycle callback.|
| onSurfaceChanged | Callback event triggered when the surface size changes. - **surfaceHolder**: pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance. - **width**: new width of the surface after the size change. - **height**: new height of the surface after the size change.|

### OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent(OH_ArkUI_SurfaceCallback* callback,void (*onSurfaceDestroyed)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**


Sets the destruction callback event in the surface lifecycle callbacks.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the surface lifecycle callback.|
| onSurfaceDestroyed | Callback event triggered when the surface is destroyed. - **surfaceHolder**: pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|

### OH_ArkUI_SurfaceHolder_AddSurfaceCallback()

```
int32_t OH_ArkUI_SurfaceHolder_AddSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder,OH_ArkUI_SurfaceCallback* callback)
```

**Description**


Adds a surface lifecycle callback to an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md)* surfaceHolder | Pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the new callback.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback()

```
int32_t OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder,OH_ArkUI_SurfaceCallback* callback)
```

**Description**


Removes a previously added surface lifecycle callback from an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md)* surfaceHolder | Pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the callback to be removed.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_XComponent_GetNativeWindow()

```
OHNativeWindow* OH_ArkUI_XComponent_GetNativeWindow(OH_ArkUI_SurfaceHolder* surfaceHolder)
```

**Description**


Obtains the **NativeWindow** instance associated with an [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md)* surfaceHolder | Pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|

**Returns**

| Type                 | Description|
|---------------------| -- |
| [OHNativeWindow](capi-oh-nativexcomponent-native-xcomponent-nativewindow.md)* | **NativeWindow** instance associated with the [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|

### OH_ArkUI_XComponent_SetAutoInitialize()

```
int32_t OH_ArkUI_XComponent_SetAutoInitialize(ArkUI_NodeHandle node, bool autoInitialize)
```

**Description**


Sets whether the **XComponent** component needs to automatically initialize the surface.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the **XComponent** component instance.|
| bool autoInitialize | Whether the XComponent needs to automatically initialize the surface. If **autoInitialize** is **true**, the **OnSurfaceCreated** callback will be triggered when the component is attached to the tree, and the **OnSurfaceDestroyed** callback will be triggered when the component is detached from the tree. The default value of **autoInitialize** is **true**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_XComponent_Initialize()

```
int32_t OH_ArkUI_XComponent_Initialize(ArkUI_NodeHandle node)
```

**Description**


Initializes the surface held by the **XComponent** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the **XComponent** component instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>Returns [ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID](capi-native-type-h.md#arkui_errorcode) if the surface held by the **XComponent** component has been initialized.|

### OH_ArkUI_XComponent_Finalize()

```
int32_t OH_ArkUI_XComponent_Finalize(ArkUI_NodeHandle node)
```

**Description**


Destroys the surface held by the **XComponent** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the **XComponent** component instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>Returns [ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID](capi-native-type-h.md#arkui_errorcode) if the surface held by the **XComponent** component has been destroyed.|

### OH_ArkUI_XComponent_IsInitialized()

```
int32_t OH_ArkUI_XComponent_IsInitialized(ArkUI_NodeHandle node, bool* isInitialized)
```

**Description**


Checks whether the surface held by the **XComponent** component is initialized.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the **XComponent** component instance.|
| bool* isInitialized | Whether the surface held by the **XComponent** component is initialized.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_XComponent_SetExpectedFrameRateRange()

```
int32_t OH_ArkUI_XComponent_SetExpectedFrameRateRange(ArkUI_NodeHandle node, OH_NativeXComponent_ExpectedRateRange range)
```

**Description**


Sets the expected frame rate range for the XComponent.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | XComponent instance.|
| [OH_NativeXComponent_ExpectedRateRange](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-expectedraterange.md) range | Expected frame rate information object of the [OH_NativeXComponent_ExpectedRateRange](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-expectedraterange.md) type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_XComponent_RegisterOnFrameCallback()

```
int32_t OH_ArkUI_XComponent_RegisterOnFrameCallback(ArkUI_NodeHandle node,void (*callback)(ArkUI_NodeHandle node, uint64_t timestamp, uint64_t targetTimestamp))
```

**Description**


Registers a frame callback function for the XComponent.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | XComponent instance.|
| void (*callback)(ArkUI_NodeHandle node, uint64_t timestamp, uint64_t targetTimestamp) | Pointer to the frame callback function. - **timestamp**: time when the current frame arrives, in nanoseconds. - **targetTimestamp**: expected arrival time of the next frame, in nanoseconds.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_XComponent_UnregisterOnFrameCallback()

```
int32_t OH_ArkUI_XComponent_UnregisterOnFrameCallback(ArkUI_NodeHandle node)
```

**Description**


Unregisters the frame callback function for the XComponent.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | XComponent instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_XComponent_SetNeedSoftKeyboard()

```
int32_t OH_ArkUI_XComponent_SetNeedSoftKeyboard(ArkUI_NodeHandle node, bool needSoftKeyboard)
```

**Description**


Sets whether the soft keyboard is required for the XComponent.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | XComponent instance.|
| bool needSoftKeyboard | Whether the soft keyboard is required. The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityProvider_Create()

```
ArkUI_AccessibilityProvider* OH_ArkUI_AccessibilityProvider_Create(ArkUI_NodeHandle node)
```

**Description**


Creates an [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) instance for this **XComponent** instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | XComponent instance.|

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* | Pointer of the [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) type.|

### OH_ArkUI_AccessibilityProvider_Dispose()

```
void OH_ArkUI_AccessibilityProvider_Dispose(ArkUI_AccessibilityProvider* provider)
```

**Description**


Disposes the [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) instance created using [OH_ArkUI_AccessibilityProvider_Create](capi-native-interface-xcomponent-h.md#oh_arkui_accessibilityprovider_create).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* provider | [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) instance created using [OH_ArkUI_AccessibilityProvider_Create](capi-native-interface-xcomponent-h.md#oh_arkui_accessibilityprovider_create).|

### OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent(OH_ArkUI_SurfaceCallback* callback,void (*onSurfaceShow)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**


Sets a surface display callback for this [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) instance. This callback is invoked when the application window has moved from the background to the foreground.

**Since**: 20


**Parameters**

| Name                                   | Description|
|----------------------------------------| -- |
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the target [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) instance.|
| onSurfaceShow                          | Pointer to the surface display callback. - **surfaceHolder**: pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|

### OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent(OH_ArkUI_SurfaceCallback* callback,void (*onSurfaceHide)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**


Sets a surface hiding callback for this [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) instance. This callback is invoked when the application window has moved from the foreground to the background.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md)* callback | Pointer to the target [OH_ArkUI_SurfaceCallback](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfacecallback.md) instance.|
| onSurfaceHide | Pointer to the surface hiding callback. - **surfaceHolder**: pointer to the target [OH_ArkUI_SurfaceHolder](capi-oh-nativexcomponent-native-xcomponent-oh-arkui-surfaceholder.md) instance.|
