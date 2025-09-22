# drag_and_drop.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## Overview

Declares the APIs of **NativeDrag**.

**File to include**: <arkui/drag_and_drop.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md) | ArkUI_NodeEvent | Defines a struct for a component event.|
| [ArkUI_Context](capi-arkui-nativemodule-arkui-context.md) | ArkUI_Context | Defines a struct for a UI context object.|
| [ArkUI_Context*](capi-arkui-nativemodule-arkui-context8h.md) | ArkUI_ContextHandle | Defines the handle to the native UI context.|
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md) | ArkUI_DragEvent | Defines a struct for a drag event.|
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md) | ArkUI_DragPreviewOption | Defines a struct for custom drag preview options.|
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md) | ArkUI_DragAction | Defines a struct for a drag action.|
| [ArkUI_DragAndDropInfo](capi-arkui-nativemodule-arkui-draganddropinfo.md) | ArkUI_DragAndDropInfo | Defines a struct for drag and drop information returned through a drag status listener.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_DragResult](#arkui_dragresult) | ArkUI_DragResult | Defines an enum for drag results, which are set by the data receiver and transferred by the system to the drag source so that the drag source is aware of the data processing result of the receiver.|
| [ArkUI_DropOperation](#arkui_dropoperation) | ArkUI_DropOperation | Defines an enum for data processing modes used when data is dropped, which affects the display of the badge.|
| [ArkUI_PreDragStatus](#arkui_predragstatus) | ArkUI_PreDragStatus | Defines an enum for interaction states prior to a drop and drop operation.|
| [ArkUI_DragPreviewScaleMode](#arkui_dragpreviewscalemode) | ArkUI_DragPreviewScaleMode | Defines an enum for drag preview scale modes.|
| [ArkUI_DragStatus](#arkui_dragstatus) | ArkUI_DragStatus | Enumerates dragging states.|

### Callback

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent* OH_ArkUI_NodeEvent_GetDragEvent(ArkUI_NodeEvent* nodeEvent)](#oh_arkui_nodeevent_getdragevent) | Obtains a **DragEvent** object from the specified **NodeEvent** object.|
| [ArkUI_PreDragStatus OH_ArkUI_NodeEvent_GetPreDragStatus(ArkUI_NodeEvent* nodeEvent)](#oh_arkui_nodeevent_getpredragstatus) | Obtains the state prior to a drop and drop operation.|
| [int32_t OH_ArkUI_DragEvent_DisableDefaultDropAnimation(ArkUI_DragEvent* event, bool disable)](#oh_arkui_dragevent_disabledefaultdropanimation) | Sets whether to disable the default drop animation, which is enabled by default. Use this API to apply a custom drop animation.|
| [int32_t OH_ArkUI_DragEvent_SetSuggestedDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation dropOperation)](#oh_arkui_dragevent_setsuggesteddropoperation) | Sets the data processing mode.|
| [int32_t OH_ArkUI_DragEvent_SetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult result)](#oh_arkui_dragevent_setdragresult) | Sets the result for a drag event.|
| [int32_t OH_ArkUI_DragEvent_SetData(ArkUI_DragEvent* event, OH_UdmfData* data)](#oh_arkui_dragevent_setdata) | Set drag data for a drag event.|
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_SetDataLoadParams(ArkUI_DragEvent* event, OH_UdmfDataLoadParams* dataLoadParams)](#oh_arkui_dragevent_setdataloadparams) | This API provides data loading parameters to the system instead of directly providing a complete data object. When the user drops data on the target application, the system will use **dataLoadParams** to request data. This can greatly improve the efficiency of dragging large amounts of data and the efficiency of processing dropped data in the target application. This API must always be used in preference to [OH_ArkUI_DragEvent_SetData](capi-drag-and-drop-h.md#oh_arkui_dragevent_setdata). For details about how to create and prepare data loading parameters, see [OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create) in **udmf.h**. If this API conflicts with [OH_ArkUI_DragEvent_SetData](capi-drag-and-drop-h.md#oh_arkui_dragevent_setdata), the system always uses the last called API.|
| [int32_t OH_ArkUI_DragEvent_GetUdmfData(ArkUI_DragEvent* event, OH_UdmfData *data)](#oh_arkui_dragevent_getudmfdata) | Obtains the default drag data from a drag event.|
| [int32_t OH_ArkUI_DragEvent_GetDataTypeCount(ArkUI_DragEvent* event, int32_t* count)](#oh_arkui_dragevent_getdatatypecount) | Obtains the number of drag data types from a drag event.|
| [int32_t OH_ArkUI_DragEvent_GetDataTypes(ArkUI_DragEvent *event, char *eventTypeArray[], int32_t length, int32_t maxStrLen)](#oh_arkui_dragevent_getdatatypes) | Obtains the type list of drag data types from a drag event.|
| [int32_t OH_ArkUI_DragEvent_GetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult* result)](#oh_arkui_dragevent_getdragresult) | Obtains the drag and drop result from the drag event.|
| [int32_t OH_ArkUI_DragEvent_GetDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation* operation)](#oh_arkui_dragevent_getdropoperation) | Obtains the data handling method from the drag event.|
| [float OH_ArkUI_DragEvent_GetPreviewTouchPointX(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewtouchpointx) | Obtains the x-coordinate of the touch point for a drag preview from a drag event.|
| [float OH_ArkUI_DragEvent_GetPreviewTouchPointY(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewtouchpointy) | Obtains the y-coordinate of the touch point on the preview image from a drag event.|
| [float OH_ArkUI_DragEvent_GetPreviewRectWidth(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewrectwidth) | Obtains the width of a drag preview from a drag event.|
| [float OH_ArkUI_DragEvent_GetPreviewRectHeight(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewrectheight) | Obtains the height of a drag preview from a drag event.|
| [float OH_ArkUI_DragEvent_GetTouchPointXToWindow(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointxtowindow) | Obtains the x-coordinate of the touch point relative to the window from a drag event.|
| [float OH_ArkUI_DragEvent_GetTouchPointYToWindow(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointytowindow) | Obtains the y-coordinate of the touch point relative to the window from a drag event.|
| [float OH_ArkUI_DragEvent_GetTouchPointXToDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointxtodisplay) | Obtains the x-coordinate of the touch point relative to the display from a drag event.|
| [float OH_ArkUI_DragEvent_GetTouchPointYToDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointytodisplay) | Obtains the y-coordinate of the touch point relative to the display from a drag event.|
| [float OH_ArkUI_DragEvent_GetVelocityX(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getvelocityx) | Obtains the dragging velocity along the x-axis.|
| [float OH_ArkUI_DragEvent_GetVelocityY(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getvelocityy) | Obtains the dragging velocity along the y-axis.|
| [float OH_ArkUI_DragEvent_GetVelocity(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getvelocity) | Obtains the dragging velocity along the main axis.|
| [int32_t OH_ArkUI_DragEvent_GetModifierKeyStates(ArkUI_DragEvent* event, uint64_t* keys)](#oh_arkui_dragevent_getmodifierkeystates) | Obtains the pressed status of modifier keys.|
| [int32_t OH_ArkUI_DragEvent_StartDataLoading(ArkUI_DragEvent* event, OH_UdmfGetDataParams* options, char* key, unsigned int keyLen)](#oh_arkui_dragevent_startdataloading) | Starts data synchronization using the specified synchronization parameters.|
| [int32_t OH_ArkUI_CancelDataLoading(ArkUI_ContextHandle uiContext, const char* key)](#oh_arkui_canceldataloading) | Cancels the ongoing data synchronization.|
| [int32_t OH_ArkUI_DisableDropDataPrefetchOnNode(ArkUI_NodeHandle node, bool disabled)](#oh_arkui_disabledropdataprefetchonnode) | Configures whether to disable the data prefetching process before executing the **onDrop** callback. The system will retry data fetching until the maximum time limit (currently 2.4 seconds) is reached, which is useful for cross-device drag and drop operations as it helps stabilize system communication. However, this feature is redundant for the [OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading) API. Since this API uses an asynchronous mechanism to fetch data, when [OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading) is used in **onDrop**, this field must be set to **true** to prevent accidental data fetching before **onDrop** is executed.|
| [int32_t OH_ArkUI_SetDragEventStrictReportWithNode(ArkUI_NodeHandle node, bool enabled)](#oh_arkui_setdrageventstrictreportwithnode) | Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a specific component node on the current UI instance for association.|
| [int32_t OH_ArkUI_SetDragEventStrictReportWithContext(ArkUI_ContextHandle uiContext, bool enabled)](#oh_arkui_setdrageventstrictreportwithcontext) | Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a specific UI instance for association.|
| [int32_t OH_ArkUI_SetNodeAllowedDropDataTypes(ArkUI_NodeHandle node, const char* typesArray[], int32_t count)](#oh_arkui_setnodealloweddropdatatypes) | Sets the types of data that can be dropped to the specified component. This API resets the settings configured through [OH_ArkUI_DisallowNodeAnyDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_disallownodeanydropdatatypes) or [OH_ArkUI_AllowNodeAllDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_allownodealldropdatatypes).|
| [int32_t OH_ArkUI_DisallowNodeAnyDropDataTypes(ArkUI_NodeHandle node)](#oh_arkui_disallownodeanydropdatatypes) | Configures the specified component to disallow any data types. This API resets the settings configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_setnodealloweddropdatatypes).|
| [int32_t OH_ArkUI_AllowNodeAllDropDataTypes(ArkUI_NodeHandle node)](#oh_arkui_allownodealldropdatatypes) | Configures the specified component to allow any data types. This API resets the settings configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_setnodealloweddropdatatypes).|
| [int32_t OH_ArkUI_SetNodeDraggable(ArkUI_NodeHandle node, bool enabled)](#oh_arkui_setnodedraggable) | Sets whether the component is draggable.|
| [int32_t OH_ArkUI_SetNodeDragPreview(ArkUI_NodeHandle node, OH_PixelmapNative* preview)](#oh_arkui_setnodedragpreview) | Sets a custom drag preview for the specified component.|
| [ArkUI_DragPreviewOption* OH_ArkUI_CreateDragPreviewOption(void)](#oh_arkui_createdragpreviewoption) | Creates an **ArkUI_DragPreviewOption** object.|
| [void OH_ArkUI_DragPreviewOption_Dispose(ArkUI_DragPreviewOption* option)](#oh_arkui_dragpreviewoption_dispose) | Disposes of an **ArkUI_DragPreviewOption** object.|
| [int32_t OH_ArkUI_DragPreviewOption_SetScaleMode(ArkUI_DragPreviewOption* option, ArkUI_DragPreviewScaleMode scaleMode)](#oh_arkui_dragpreviewoption_setscalemode) | Sets the scale mode for an **ArkUI_DragPreviewOption** object.|
| [int32_t OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setdefaultshadowenabled) | Sets whether to enable the default shadow effect for an **ArkUI_DragPreviewOption** object. The effect is disabled by default.|
| [int32_t OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setdefaultradiusenabled) | Sets whether to enable the default corner radius effect for an **ArkUI_DragPreviewOption** object. The effect is disabled by default.|
| [int32_t OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setnumberbadgeenabled) | Sets whether to enable the badge for an **ArkUI_DragPreviewOption** object. If this feature is enabled, a badge that contains the number of dragged items is displayed.|
| [int32_t OH_ArkUI_DragPreviewOption_SetBadgeNumber(ArkUI_DragPreviewOption* option, uint32_t forcedNumber)](#oh_arkui_dragpreviewoption_setbadgenumber) | Sets the count on the badge. The settings will overwrite the value in the **SetDragPreviewNumberBadgeEnabled** API.|
| [int32_t OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setdefaultanimationbeforeliftingenabled) | Sets whether to enable the default animation on a click or touch.|
| [int32_t OH_ArkUI_SetNodeDragPreviewOption(ArkUI_NodeHandle node, ArkUI_DragPreviewOption* option)](#oh_arkui_setnodedragpreviewoption) | Sets an **ArkUI_DragPreviewOption** object for the specified component.|
| [ArkUI_DragAction* OH_ArkUI_CreateDragActionWithNode(ArkUI_NodeHandle node)](#oh_arkui_createdragactionwithnode) | Creates a drag action object. The object needs to be associated with a UI instance, which can be specified by passing in a component node of the current UI instance.|
| [ArkUI_DragAction* OH_ArkUI_CreateDragActionWithContext(ArkUI_ContextHandle uiContext)](#oh_arkui_createdragactionwithcontext) | Creates a drag action object for the specified UI instance.|
| [void OH_ArkUI_DragAction_Dispose(ArkUI_DragAction* dragAction)](#oh_arkui_dragaction_dispose) | Disposes of an **ArkUI_DragAction** object.|
| [int32_t OH_ArkUI_DragAction_SetPointerId(ArkUI_DragAction* dragAction, int32_t pointer)](#oh_arkui_dragaction_setpointerid) | Sets the pointer ID. If only one finger is operating on the screen, the pointer ID is 0. In general cases, you can set the pointer ID to 0.|
| [int32_t OH_ArkUI_DragAction_SetPixelMaps(ArkUI_DragAction* dragAction, OH_PixelmapNative* pixelmapArray[], int32_t size)](#oh_arkui_dragaction_setpixelmaps) | Sets the drag previews for a drag action.|
| [int32_t OH_ArkUI_DragAction_SetTouchPointX(ArkUI_DragAction* dragAction, float x)](#oh_arkui_dragaction_settouchpointx) | Sets the touch point relative to the upper left corner of the first drag preview (pixel map).|
| [int32_t OH_ArkUI_DragAction_SetTouchPointY(ArkUI_DragAction* dragAction, float y)](#oh_arkui_dragaction_settouchpointy) | Sets the touch point relative to the upper left corner of the first drag preview (pixel map).|
| [int32_t OH_ArkUI_DragAction_SetData(ArkUI_DragAction* dragAction, OH_UdmfData* data)](#oh_arkui_dragaction_setdata) | Sets the drag data.|
| [ArkUI_ErrorCode OH_ArkUI_DragAction_SetDataLoadParams(ArkUI_DragAction* dragAction,OH_UdmfDataLoadParams* dataLoadParams)](#oh_arkui_dragaction_setdataloadparams) | This API provides data loading parameters to the system instead of directly providing a complete data object. When the user drops data on the target application, the system will use **dataLoadParams** to request data. This can significantly improve the efficiency of dragging large volumes of data and the efficiency of processing the dropped data in the target application. This API must always be used in preference to [OH_ArkUI_DragAction_SetData](capi-drag-and-drop-h.md#oh_arkui_dragaction_setdata). For details about how to create and prepare data loading parameters, see [OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create) in **udmf.h**. If this API conflicts with [OH_ArkUI_DragAction_SetData](capi-drag-and-drop-h.md#oh_arkui_dragaction_setdata), the system always uses the last called API.|
| [int32_t OH_ArkUI_DragAction_SetDragPreviewOption(ArkUI_DragAction* dragAction, ArkUI_DragPreviewOption* option)](#oh_arkui_dragaction_setdragpreviewoption) | Sets an **ArkUI_DragPreviewOption** object for the specified drag action object.|
| [int32_t OH_ArkUI_DragAction_RegisterStatusListener(ArkUI_DragAction* dragAction, void* userData,void(\*listener)(ArkUI_DragAndDropInfo* dragAndDropInfo, void* userData))](#oh_arkui_dragaction_registerstatuslistener) | Registers a drag status listener. This listener can be used to check whether the data is successfully received and processed.|
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDisplayId(ArkUI_DragEvent event, int32_t* displayId)](#oh_arkui_dragevent_getdisplayid) | Obtains the ID of the screen where this drag event occurs. This API is not supported when **eventType** is **NODE_ON_DRAG_END**.|
| [void OH_ArkUI_DragAction_UnregisterStatusListener(ArkUI_DragAction* dragAction)](#oh_arkui_dragaction_unregisterstatuslistener) | Unregisters a drag status listener.|
| [ArkUI_DragStatus OH_ArkUI_DragAndDropInfo_GetDragStatus(ArkUI_DragAndDropInfo* dragAndDropInfo)](#oh_arkui_draganddropinfo_getdragstatus) | Obtains the drag status of a drag action. Returns **ArkUI_DRAG_STATUS_UNKNOWN** if the acquisition fails.|
| [ArkUI_DragEvent* OH_ArkUI_DragAndDropInfo_GetDragEvent(ArkUI_DragAndDropInfo* dragAndDropInfo)](#oh_arkui_draganddropinfo_getdragevent) | Obtains a drag event based on the specified drag and drop information. The drag event can then be used to obtain the drag result.|
| [int32_t OH_ArkUI_StartDrag(ArkUI_DragAction* dragAction)](#oh_arkui_startdrag) | Initiates a drag action through the specified **DragAction** object.|
| [int32_t OH_ArkUI_DragEvent_RequestDragEndPending(ArkUI_DragEvent* event, int32_t* requestIdentify)](#oh_arkui_dragevent_requestdragendpending) | Requests deferred processing of the drag end event, allowing the application to asynchronously confirm the operation result. The application must pass the final result back to the system via the [OH_ArkUI_NotifyDragResult](capi-drag-and-drop-h.md#oh_arkui_notifydragresult) API, and call [OH_ArkUI_NotifyDragEndPendingDone](capi-drag-and-drop-h.md#oh_arkui_notifydragendpendingdone) after all processing is completed. The maximum waiting time is 2 seconds.|
| [int32_t OH_ArkUI_NotifyDragResult(int32_t requestIdentify, ArkUI_DragResult result)](#oh_arkui_notifydragresult) | Notifies the system of the final drag result. The system will verify whether the request identifier matches that returned by [OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending). If they do not match, this call will be ignored.|
| [int32_t OH_ArkUI_NotifyDragEndPendingDone(int32_t requestIdentify)](#oh_arkui_notifydragendpendingdone) | Notifies the system that all asynchronous processing has been completed and the drag end pending state can be terminated.|
| [ArkUI_ErrorCode OH_ArkUI_EnableDropDisallowedBadge(ArkUI_ContextHandle uiContext, bool enabled)](#oh_arkui_enabledropdisallowedbadge) | Sets whether the drop-disallowed badge can be displayed.|
| [float OH_ArkUI_DragEvent_GetTouchPointXToGlobalDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointxtoglobaldisplay) | Obtains the x-coordinate of the drag touch point relative to the global display from the specified **ArkUI_DragEvent** object.|
| [float OH_ArkUI_DragEvent_GetTouchPointYToGlobalDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointytoglobaldisplay) | Obtains the y-coordinate of the drag touch point relative to the global display from the specified **ArkUI_DragEvent** object.|
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDragSource(ArkUI_DragEvent* event, char *bundleName, int32_t length)](#oh_arkui_dragevent_getdragsource) | Obtains the bundle name of the drag source application. The caller must provide a character array with a minimum length of 128 characters to store the bundle name.|
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_IsRemote(ArkUI_DragEvent* event, bool* isRemote)](#oh_arkui_dragevent_isremote) | Checks whether the current drag operation is a cross-device drag.|

## Enum Description

### ArkUI_DragResult

```
enum ArkUI_DragResult
```

**Description**


Defines an enum for drag results, which are set by the data receiver and transferred by the system to the drag source so that the drag source is aware of the data processing result of the receiver.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_DRAG_RESULT_SUCCESSFUL = 0 | The drag and drop operation succeeded.|
| ARKUI_DRAG_RESULT_FAILED | The drag and drop operation failed.|
| ARKUI_DRAG_RESULT_CANCELED | The drag and drop operation was canceled.|

### ArkUI_DropOperation

```
enum ArkUI_DropOperation
```

**Description**


Defines an enum for data processing modes used when data is dropped, which affects the display of the badge.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_DROP_OPERATION_COPY = 0 | Copy.|
| ARKUI_DROP_OPERATION_MOVE | Cut.|

### ArkUI_PreDragStatus

```
enum ArkUI_PreDragStatus
```

**Description**


Defines an enum for interaction states prior to a drop and drop operation.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_PRE_DRAG_STATUS_UNKNOWN = -1 | Unknown.|
| ARKUI_PRE_DRAG_STATUS_ACTION_DETECTING | A drag gesture is being detected.|
| ARKUI_PRE_DRAG_STATUS_READY_TO_TRIGGER_DRAG | The component is ready to be dragged.|
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_STARTED | A lift animation is started.|
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_FINISHED | A lift animation is finished.|
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_STARTED | A drop animation is started.|
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_FINISHED | A drop animation is finished.|
| ARKUI_PRE_DRAG_STATUS_CANCELED_BEFORE_DRAG | A drop animation is terminated.|

### ArkUI_DragPreviewScaleMode

```
enum ArkUI_DragPreviewScaleMode
```

**Description**


Defines an enum for drag preview scale modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_DRAG_PREVIEW_SCALE_AUTO = 0 | Enables the system to automatically change the position of the dragged point based on the scenario and apply scaling transformations to the drag preview based on set rules.|
| ARKUI_DRAG_PREVIEW_SCALE_DISABLED | Disables the system's scaling behavior for the drag preview.|

### ArkUI_DragStatus

```
enum ArkUI_DragStatus
```

**Description**


Enumerates dragging states.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_DRAG_STATUS_UNKNOWN = -1 | Unknown.|
| ARKUI_DRAG_STATUS_STARTED | Started.|
| ARKUI_DRAG_STATUS_ENDED | Ended.|


## Function Description

### OH_ArkUI_NodeEvent_GetDragEvent()

```
ArkUI_DragEvent* OH_ArkUI_NodeEvent_GetDragEvent(ArkUI_NodeEvent* nodeEvent)
```

**Description**


Obtains a **DragEvent** object from the specified **NodeEvent** object.

**Since**: 12


**Parameters**

| Name                           | Description|
|--------------------------------| -- |
| [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)* nodeEvent | Pointer to the target **ArkUI_NodeEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* | Returns the pointer to an **ArkUI_DragEvent** object; returns null if the parameter passed in is invalid or is not a drag-related event.|

### OH_ArkUI_NodeEvent_GetPreDragStatus()

```
ArkUI_PreDragStatus OH_ArkUI_NodeEvent_GetPreDragStatus(ArkUI_NodeEvent* nodeEvent)
```

**Description**


Obtains the state prior to a drop and drop operation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)* nodeEvent | Pointer to the target **ArkUI_NodeEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_PreDragStatus](capi-drag-and-drop-h.md#arkui_predragstatus) | State prior to the drop and drop operation.|

### OH_ArkUI_DragEvent_DisableDefaultDropAnimation()

```
int32_t OH_ArkUI_DragEvent_DisableDefaultDropAnimation(ArkUI_DragEvent* event, bool disable)
```

**Description**


Sets whether to disable the default drop animation, which is enabled by default. Use this API to apply a custom drop animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| bool disable | Whether to disable the default drop animation. The value **true** means to disable the default drop animation, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_SetSuggestedDropOperation()

```
int32_t OH_ArkUI_DragEvent_SetSuggestedDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation dropOperation)
```

**Description**


Sets the data processing mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [ArkUI_DropOperation](capi-drag-and-drop-h.md#arkui_dropoperation) dropOperation | Type of the suggested drop operation.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_SetDragResult()

```
int32_t OH_ArkUI_DragEvent_SetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult result)
```

**Description**


Sets the result for a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [ArkUI_DragResult](capi-drag-and-drop-h.md#arkui_dragresult) result | Drag data processing result.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_SetData()

```
int32_t OH_ArkUI_DragEvent_SetData(ArkUI_DragEvent* event, OH_UdmfData* data)
```

**Description**


Set drag data for a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)* data | Drag data configuration.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_SetDataLoadParams()

```
ArkUI_ErrorCode OH_ArkUI_DragEvent_SetDataLoadParams(ArkUI_DragEvent* event, OH_UdmfDataLoadParams* dataLoadParams)
```

**Description**


This API provides data loading parameters to the system instead of directly providing a complete data object. When the user drops data on the target application, the system will use **dataLoadParams** to request data. This can significantly improve the efficiency of dragging large volumes of data and the efficiency of processing the dropped data in the target application. This API must always be used in preference to [OH_ArkUI_DragEvent_SetData](capi-drag-and-drop-h.md#oh_arkui_dragevent_setdata). For details about how to create and prepare data loading parameters, see [OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create) in **udmf.h**. If this API conflicts with [OH_ArkUI_DragEvent_SetData](capi-drag-and-drop-h.md#oh_arkui_dragevent_setdata), the system always uses the last called API.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [OH_UdmfDataLoadParams](../apis-arkdata/capi-udmf-oh-udmfdataloadparams.md)* dataLoadParams | Data loading parameters used during a drop operation.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_GetUdmfData()

```
int32_t OH_ArkUI_DragEvent_GetUdmfData(ArkUI_DragEvent* event, OH_UdmfData *data)
```

**Description**


Obtains the default drag data from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md) *data | pointer to an **OH_UdmfData** object. The application needs to create a pointer for receiving data by using the [OH_UdmfData_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdata_create) API.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_GetDataTypeCount()

```
int32_t OH_ArkUI_DragEvent_GetDataTypeCount(ArkUI_DragEvent* event, int32_t* count)
```

**Description**


Obtains the number of drag data types from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| int32_t* count | Number of drag data types returned.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_GetDataTypes()

```
int32_t OH_ArkUI_DragEvent_GetDataTypes(ArkUI_DragEvent *event, char *eventTypeArray[], int32_t length, int32_t maxStrLen)
```

**Description**


Obtains the type list of drag data types from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md) *event | Pointer to the target **ArkUI_DragEvent** object.|
| char *eventTypeArray[] | List of the drag data types. You need to create a string array first.|
| int32_t length | Total length of the array, which cannot be less than the number obtained using **OH_ArkUI_DragEvent_GetDataTypesCount**.|
| int32_t maxStrLen | Maximum length of each data type string.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the provided buffer size is insufficient.|

### OH_ArkUI_DragEvent_GetDragResult()

```
int32_t OH_ArkUI_DragEvent_GetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult* result)
```

**Description**


Obtains the drag and drop result from the drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [ArkUI_DragResult](capi-drag-and-drop-h.md#arkui_dragresult)* result | Drag result returned.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_GetDropOperation()

```
int32_t OH_ArkUI_DragEvent_GetDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation* operation)
```

**Description**


Obtains the data handling method from the drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [ArkUI_DropOperation](capi-drag-and-drop-h.md#arkui_dropoperation)* operation | Data handling method.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>                Possible causes: 1. Parameters are null or the event is not a valid DragEvent.|

### OH_ArkUI_DragEvent_GetPreviewTouchPointX()

```
float OH_ArkUI_DragEvent_GetPreviewTouchPointX(ArkUI_DragEvent* event)
```

**Description**


Obtains the x-coordinate of the touch point for a drag preview from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate of the touch point, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetPreviewTouchPointY()

```
float OH_ArkUI_DragEvent_GetPreviewTouchPointY(ArkUI_DragEvent* event)
```

**Description**


Obtains the y-coordinate of the touch point on the preview image from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate of the touch point, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetPreviewRectWidth()

```
float OH_ArkUI_DragEvent_GetPreviewRectWidth(ArkUI_DragEvent* event)
```

**Description**


Obtains the width of a drag preview from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Width of the drag preview, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetPreviewRectHeight()

```
float OH_ArkUI_DragEvent_GetPreviewRectHeight(ArkUI_DragEvent* event)
```

**Description**


Obtains the height of a drag preview from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Height of the drag preview, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetTouchPointXToWindow()

```
float OH_ArkUI_DragEvent_GetTouchPointXToWindow(ArkUI_DragEvent* event)
```

**Description**


Obtains the x-coordinate of the touch point relative to the window from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate of the touch point relative to the window, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetTouchPointYToWindow()

```
float OH_ArkUI_DragEvent_GetTouchPointYToWindow(ArkUI_DragEvent* event)
```

**Description**


Obtains the y-coordinate of the touch point relative to the window from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate of the touch point relative to the window, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetTouchPointXToDisplay()

```
float OH_ArkUI_DragEvent_GetTouchPointXToDisplay(ArkUI_DragEvent* event)
```

**Description**


Obtains the x-coordinate of the touch point relative to the display from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate of the touch point relative to the display, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetTouchPointYToDisplay()

```
float OH_ArkUI_DragEvent_GetTouchPointYToDisplay(ArkUI_DragEvent* event)
```

**Description**


Obtains the y-coordinate of the touch point relative to the display from a drag event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate of the touch point relative to the display, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetVelocityX()

```
float OH_ArkUI_DragEvent_GetVelocityX(ArkUI_DragEvent* event)
```

**Description**


Obtains the dragging velocity along the x-axis.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Dragging velocity along the x-axis, in px/s, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetVelocityY()

```
float OH_ArkUI_DragEvent_GetVelocityY(ArkUI_DragEvent* event)
```

**Description**


Obtains the dragging velocity along the y-axis.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Dragging velocity along the y-axis, in px/s, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetVelocity()

```
float OH_ArkUI_DragEvent_GetVelocity(ArkUI_DragEvent* event)
```

**Description**


Obtains the dragging velocity along the main axis.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Dragging velocity along the main axis, in px/s, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetModifierKeyStates()

```
int32_t OH_ArkUI_DragEvent_GetModifierKeyStates(ArkUI_DragEvent* event, uint64_t* keys)
```

**Description**


Obtains the pressed status of modifier keys.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| uint64_t* keys | Pointer to a variable where the current combination of pressed modifier keys will be returned. The application can use bitwise operations to determine the state of each modifier key.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_StartDataLoading()

```
int32_t OH_ArkUI_DragEvent_StartDataLoading(ArkUI_DragEvent* event, OH_UdmfGetDataParams* options, char* key, unsigned int keyLen)
```

**Description**


Starts data synchronization using the specified synchronization parameters.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| [OH_UdmfGetDataParams](../apis-arkdata/capi-udmf-oh-udmfgetdataparams.md)* options | Pointer to the **OH_UdmfGetDataParams** object.|
| char* key | Key value returned after successful data setting. The length of the string must be no less than [UDMF_KEY_BUFFER_LEN](../apis-arkdata/capi-udmf-h.md#udmf_key_buffer_len).|
| unsigned int keyLen | Length of the **key** string.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CancelDataLoading()

```
int32_t OH_ArkUI_CancelDataLoading(ArkUI_ContextHandle uiContext, const char* key)
```

**Description**


Cancels the ongoing data synchronization.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | Pointer to the UI instance.|
| const char* key | Data key value, which is returned via [OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading).|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns **ARKUI_ERROR_CODE_OPERATION_FAILED** if no data synchronization task is in progress.|

### OH_ArkUI_DisableDropDataPrefetchOnNode()

```
int32_t OH_ArkUI_DisableDropDataPrefetchOnNode(ArkUI_NodeHandle node, bool disabled)
```

**Description**


Configures whether to disable the data prefetching process before executing the **onDrop** callback. The system will retry data fetching until the maximum time limit (currently 2.4 seconds) is reached, which is useful for cross-device drag and drop operations as it helps stabilize system communication. However, this feature is redundant for the [OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading) API. Since this API uses an asynchronous mechanism to fetch data, when [OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading) is used in **onDrop**, this field must be set to **true** to prevent accidental data fetching before **onDrop** is executed.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|
| bool disabled | Whether to disable the data prefetching process. The value **true** means to disable the data prefetching process, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SetDragEventStrictReportWithNode()

```
int32_t OH_ArkUI_SetDragEventStrictReportWithNode(ArkUI_NodeHandle node, bool enabled)
```

**Description**


Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a specific component node on the current UI instance for association.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|
| bool enabled | Whether to enable strict reporting on drag events. The value **true** means to enable strict reporting on drag events, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SetDragEventStrictReportWithContext()

```
int32_t OH_ArkUI_SetDragEventStrictReportWithContext(ArkUI_ContextHandle uiContext, bool enabled)
```

**Description**


Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a specific UI instance for association.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | Pointer to the UI instance.|
| bool enabled | Whether to enable strict reporting on drag events. The value **true** means to enable strict reporting on drag events, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SetNodeAllowedDropDataTypes()

```
int32_t OH_ArkUI_SetNodeAllowedDropDataTypes(ArkUI_NodeHandle node, const char* typesArray[], int32_t count)
```

**Description**


Sets the types of data that can be dropped to the specified component. This API resets the settings configured through [OH_ArkUI_DisallowNodeAnyDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_disallownodeanydropdatatypes) or [OH_ArkUI_AllowNodeAllDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_allownodealldropdatatypes).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|
| const char* typesArray[] | Array of types of data that can be dropped.|
| int32_t count | Length of the array.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DisallowNodeAnyDropDataTypes()

```
int32_t OH_ArkUI_DisallowNodeAnyDropDataTypes(ArkUI_NodeHandle node)
```

**Description**


Configures the specified component to disallow any data types. This API resets the settings configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_setnodealloweddropdatatypes).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AllowNodeAllDropDataTypes()

```
int32_t OH_ArkUI_AllowNodeAllDropDataTypes(ArkUI_NodeHandle node)
```

**Description**


Configures the specified component to allow any data types. This API resets the settings configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_setnodealloweddropdatatypes).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SetNodeDraggable()

```
int32_t OH_ArkUI_SetNodeDraggable(ArkUI_NodeHandle node, bool enabled)
```

**Description**


Sets whether the component is draggable.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|
| bool enabled | Whether the component is draggable. The value **true** means that the component is draggable, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SetNodeDragPreview()

```
int32_t OH_ArkUI_SetNodeDragPreview(ArkUI_NodeHandle node, OH_PixelmapNative* preview)
```

**Description**


Sets a custom drag preview for the specified component.

**Since**: 12


**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|
| OH_PixelmapNative* preview                                   | Custom drag preview, which is a pixel map.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CreateDragPreviewOption()

```
ArkUI_DragPreviewOption* OH_ArkUI_CreateDragPreviewOption(void)
```

**Description**


Creates an **ArkUI_DragPreviewOption** object.

**Since**: 12

**Return value**

| Type                          | Description|
|------------------------------| -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* | **ArkUI_DragPreviewOption** object.|

### OH_ArkUI_DragPreviewOption_Dispose()

```
void OH_ArkUI_DragPreviewOption_Dispose(ArkUI_DragPreviewOption* option)
```

**Description**


Disposes of an **ArkUI_DragPreviewOption** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|

### OH_ArkUI_DragPreviewOption_SetScaleMode()

```
int32_t OH_ArkUI_DragPreviewOption_SetScaleMode(ArkUI_DragPreviewOption* option, ArkUI_DragPreviewScaleMode scaleMode)
```

**Description**


Sets the scale mode for an **ArkUI_DragPreviewOption** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|
| [ArkUI_DragPreviewScaleMode](capi-drag-and-drop-h.md#arkui_dragpreviewscalemode) scaleMode | Scale mode to set.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**Description**


Sets whether to enable the default shadow effect for an **ArkUI_DragPreviewOption** object. The effect is disabled by default.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|
| bool enabled | Whether to enable the default shadow effect. The value **true** means to enable the default shadow effect, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**Description**


Sets whether to enable the default corner radius effect for an **ArkUI_DragPreviewOption** object. The effect is disabled by default.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|
| bool enabled | Whether to enable the default corner radius effect. The value **true** means to enable the default corner radius effect, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**Description**


Sets whether to enable the badge for an **ArkUI_DragPreviewOption** object. If this feature is enabled, a badge that contains the number of dragged items is displayed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|
| bool enabled | Whether to enable the badge. The value **true** means to enable the badge, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragPreviewOption_SetBadgeNumber()

```
int32_t OH_ArkUI_DragPreviewOption_SetBadgeNumber(ArkUI_DragPreviewOption* option, uint32_t forcedNumber)
```

**Description**


Sets the count on the badge. The settings will overwrite the value in the **SetDragPreviewNumberBadgeEnabled** API.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|
| uint32_t forcedNumber | Number of badges.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**Description**


Sets whether to enable the default animation on a click or touch.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|
| bool enabled | Whether to enable the default animation on a click or touch. The value **true** means to enable the default animation on a click or touch, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_SetNodeDragPreviewOption()

```
int32_t OH_ArkUI_SetNodeDragPreviewOption(ArkUI_NodeHandle node, ArkUI_DragPreviewOption* option)
```

**Description**


Sets an **ArkUI_DragPreviewOption** object for the specified component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_CreateDragActionWithNode()

```
ArkUI_DragAction* OH_ArkUI_CreateDragActionWithNode(ArkUI_NodeHandle node)
```

**Description**


Creates a drag action object. The object needs to be associated with a UI instance, which can be specified by passing in a component node of the current UI instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Pointer to the component node.|

**Return value**

| Type                   | Description|
|-----------------------| -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* | Pointer to the created drag action object, or null if the operation fails.|

### OH_ArkUI_CreateDragActionWithContext()

```
ArkUI_DragAction* OH_ArkUI_CreateDragActionWithContext(ArkUI_ContextHandle uiContext)
```

**Description**


Creates a drag action object for the specified UI instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | Pointer to the UI instance.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* | Pointer to the created drag action object, or null if the operation fails.|

### OH_ArkUI_DragAction_Dispose()

```
void OH_ArkUI_DragAction_Dispose(ArkUI_DragAction* dragAction)
```

**Description**


Disposes of an **ArkUI_DragAction** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|

### OH_ArkUI_DragAction_SetPointerId()

```
int32_t OH_ArkUI_DragAction_SetPointerId(ArkUI_DragAction* dragAction, int32_t pointer)
```

**Description**


Sets the pointer ID. If only one finger is operating on the screen, the pointer ID is 0. In general cases, you can set the pointer ID to 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|
| int32_t pointer | Pointer ID. The value ranges from 0 to 9.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_SetPixelMaps()

```
int32_t OH_ArkUI_DragAction_SetPixelMaps(ArkUI_DragAction* dragAction, OH_PixelmapNative* pixelmapArray[], int32_t size)
```

**Description**


Sets the drag previews for a drag action.

**Since**: 12


**Parameters**

| Name                                                                                 | Description|
|--------------------------------------------------------------------------------------| -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction          | Pointer to the target drag action object.|
| OH_PixelmapNative* pixelmapArray[] | Array of the drag previews to set, which must be pixel maps.|
| int32_t size                                                                         | Number of drag previews.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_SetTouchPointX()

```
int32_t OH_ArkUI_DragAction_SetTouchPointX(ArkUI_DragAction* dragAction, float x)
```

**Description**


Sets the touch point relative to the upper left corner of the first drag preview (pixel map).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|
| float x | X-coordinate of the touch point, in px.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_SetTouchPointY()

```
int32_t OH_ArkUI_DragAction_SetTouchPointY(ArkUI_DragAction* dragAction, float y)
```

**Description**


Sets the touch point relative to the upper left corner of the first drag preview (pixel map).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|
| float y | Y-coordinate of the touch point, in px.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_SetData()

```
int32_t OH_ArkUI_DragAction_SetData(ArkUI_DragAction* dragAction, OH_UdmfData* data)
```

**Description**


Sets the drag data.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)* data | Drag data configuration.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_SetDataLoadParams()

```
ArkUI_ErrorCode OH_ArkUI_DragAction_SetDataLoadParams(ArkUI_DragAction* dragAction,OH_UdmfDataLoadParams* dataLoadParams)
```

**Description**


This API provides data loading parameters to the system instead of directly providing a complete data object. When the user drops data on the target application, the system will use **dataLoadParams** to request data. This can significantly improve the efficiency of dragging large volumes of data and the efficiency of processing the dropped data in the target application. This API must always be used in preference to [OH_ArkUI_DragAction_SetData](capi-drag-and-drop-h.md#oh_arkui_dragaction_setdata). For details about how to create and prepare data loading parameters, see [OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create) in **udmf.h**. If this API conflicts with [OH_ArkUI_DragAction_SetData](capi-drag-and-drop-h.md#oh_arkui_dragaction_setdata), the system always uses the last called API.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|
| [OH_UdmfDataLoadParams](../apis-arkdata/capi-udmf-oh-udmfdataloadparams.md)* dataLoadParams | Data loading parameters used during a drop operation.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_SetDragPreviewOption()

```
int32_t OH_ArkUI_DragAction_SetDragPreviewOption(ArkUI_DragAction* dragAction, ArkUI_DragPreviewOption* option)
```

**Description**


Sets an **ArkUI_DragPreviewOption** object for the specified drag action object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | Custom parameters.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_RegisterStatusListener()

```
int32_t OH_ArkUI_DragAction_RegisterStatusListener(ArkUI_DragAction* dragAction, void* userData,void(*listener)(ArkUI_DragAndDropInfo* dragAndDropInfo, void* userData))
```

**Description**


Registers a drag status listener. This listener can be used to check whether the data is successfully received and processed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|
| void* userData | Custom user data.|
| listener | Listener to register. When the callback is invoked, the system returns a pointer to the drag status object. The pointer is destroyed after the callback is complete and the application should not hold it anymore.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_GetDisplayId()

```
ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDisplayId(ArkUI_DragEvent event, int32_t* displayId)
```

**Description**


Obtains the ID of the screen where this drag event occurs. This API is not supported when **eventType** is **NODE_ON_DRAG_END**.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md) event | Pointer to the target **ArkUI_DragEvent** object.|
| int32_t* displayId | ID of the screen where the current drag event occurs.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragAction_UnregisterStatusListener()

```
void OH_ArkUI_DragAction_UnregisterStatusListener(ArkUI_DragAction* dragAction)
```

**Description**


Unregisters a drag status listener.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Pointer to the target drag action object.|

### OH_ArkUI_DragAndDropInfo_GetDragStatus()

```
ArkUI_DragStatus OH_ArkUI_DragAndDropInfo_GetDragStatus(ArkUI_DragAndDropInfo* dragAndDropInfo)
```

**Description**


Obtains the drag status of a drag action.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAndDropInfo](capi-arkui-nativemodule-arkui-draganddropinfo.md)* dragAndDropInfo | Drag and drop information returned by the drag status listener.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_DragStatus](capi-drag-and-drop-h.md#arkui_dragstatus) | **ArkUI_DragStatus** object, or **ArkUI_DRAG_STATUS_UNKNOWN** if an error occurs.|

### OH_ArkUI_DragAndDropInfo_GetDragEvent()

```
ArkUI_DragEvent* OH_ArkUI_DragAndDropInfo_GetDragEvent(ArkUI_DragAndDropInfo* dragAndDropInfo)
```

**Description**


Obtains a drag event based on the specified drag and drop information. The drag event can then be used to obtain the drag result.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAndDropInfo](capi-arkui-nativemodule-arkui-draganddropinfo.md)* dragAndDropInfo | Drag and drop information returned by the drag status listener.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* | **ArkUI_DragEvent** object, or null if an error occurs.|

### OH_ArkUI_StartDrag()

```
int32_t OH_ArkUI_StartDrag(ArkUI_DragAction* dragAction)
```

**Description**


Initiates a drag action through the specified **DragAction** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | Drag action object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_RequestDragEndPending()

```
int32_t OH_ArkUI_DragEvent_RequestDragEndPending(ArkUI_DragEvent* event, int32_t* requestIdentify)
```

**Description**


Requests deferred processing of the drag end event, allowing the application to asynchronously confirm the operation result. The application must pass the final result back to the system via the [OH_ArkUI_NotifyDragResult](capi-drag-and-drop-h.md#oh_arkui_notifydragresult) API, and call [OH_ArkUI_NotifyDragEndPendingDone](capi-drag-and-drop-h.md#oh_arkui_notifydragendpendingdone) after all processing is completed. The maximum waiting time is 2 seconds.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| int32_t* requestIdentify | System-generated request identifier, which is an output parameter and must point to a valid address.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-native-type-h.md#arkui_errorcode) if the API is not called during the drop phase.|

### OH_ArkUI_NotifyDragResult()

```
int32_t OH_ArkUI_NotifyDragResult(int32_t requestIdentify, ArkUI_DragResult result)
```

**Description**


Notifies the system of the final drag result. The system will verify whether the request identifier matches that returned by [OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending). If they do not match, this call will be ignored.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| int32_t requestIdentify | Identifier returned by [OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending).|
| [ArkUI_DragResult](capi-drag-and-drop-h.md#arkui_dragresult) result | Enumerated value of the drag result (of the [ArkUI_DragResult](capi-drag-and-drop-h.md#arkui_dragresult) type).|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-native-type-h.md#arkui_errorcode) if the API is not called during the drop phase.|

### OH_ArkUI_NotifyDragEndPendingDone()

```
int32_t OH_ArkUI_NotifyDragEndPendingDone(int32_t requestIdentify)
```

**Description**


Notifies the system that all asynchronous processing has been completed and the drag end pending state can be terminated.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| int32_t requestIdentify | Identifier returned by [OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending).|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-native-type-h.md#arkui_errorcode) if the API is not called during the drop phase.|

### OH_ArkUI_EnableDropDisallowedBadge()

```
ArkUI_ErrorCode OH_ArkUI_EnableDropDisallowedBadge(ArkUI_ContextHandle uiContext, bool enabled)
```

**Description**


Sets whether the drop-disallowed badge can be displayed.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | Pointer to the UI instance.|
| bool enabled | Whether the drop-disallowed badge can be displayed. The value **true** means that the drop-disallowed badge can be displayed, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_GetTouchPointXToGlobalDisplay()

```
float OH_ArkUI_DragEvent_GetTouchPointXToGlobalDisplay(ArkUI_DragEvent* event)
```

**Description**


Obtains the x-coordinate of the drag touch point relative to the global display from the specified **ArkUI_DragEvent** object.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | X-coordinate of the touch point relative to the global display, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetTouchPointYToGlobalDisplay()

```
float OH_ArkUI_DragEvent_GetTouchPointYToGlobalDisplay(ArkUI_DragEvent* event)
```

**Description**


Obtains the y-coordinate of the drag touch point relative to the global display from the specified **ArkUI_DragEvent** object.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Y-coordinate of the touch point relative to the global display, in px, or the default value **0** if the input parameter is invalid.|

### OH_ArkUI_DragEvent_GetDragSource()

```
ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDragSource(ArkUI_DragEvent* event, char *bundleName, int32_t length)
```

**Description**


Obtains the bundle name of the drag source application. The caller must provide a character array with a minimum length of 128 characters to store the bundle name.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| char *bundleName | Character array to store the bundle name string, with a length of at least 128 characters.|
| int32_t length | Length of the character array to store the bundle name string. The minimum length is 128 characters.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DragEvent_IsRemote()

```
ArkUI_ErrorCode OH_ArkUI_DragEvent_IsRemote(ArkUI_DragEvent* event, bool* isRemote)
```

**Description**


Checks whether the current drag operation is a cross-device drag.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | Pointer to the target **ArkUI_DragEvent** object.|
| bool* isRemote | Pointer to a boolean variable to store the result. The value **true** means that the current drag operation is a cross-device drag, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
