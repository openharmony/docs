# drag_and_drop.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供NativeDrag相关接口定义，支持获取拖拽事件、设置和获取拖拽数据、配置拖拽预览、发起拖拽操作及监听拖拽状态，适用于应用实现原生拖拽交互、数据拖入拖出和自定义拖拽效果等场景。

**引用文件：** <arkui/drag_and_drop.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[NativeDragDrop](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeDragDrop)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md) | ArkUI_NodeEvent | 定义组件事件的通用结构类型。 |
| [ArkUI_Context](capi-arkui-nativemodule-arkui-context.md) | ArkUI_Context | ArkUI native UI 的上下文实例对象，用于表示组件所在页面的 UIContext。其指针类型为 [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md)，开发者可通过 [OH_ArkUI_GetContextByNode](capi-native-node-h.md#oh_arkui_getcontextbynode) 获取对应上下文，并将其作为拖拽操作、动画、UI 任务调度等接口的上下文入参。 |
| [ArkUI_Context*](capi-arkui-nativemodule-arkui-context8h.md) | ArkUI_ContextHandle | ArkUI 在 Native 侧的上下文实例对象指针，用于表示组件所在页面的 UIContext。开发者可通过[OH_ArkUI_GetContextByNode](capi-native-node-h.md#oh_arkui_getcontextbynode)或[OH_ArkUI_GetContextFromNapiValue](capi-native-node-napi-h.md#oh_arkui_getcontextfromnapivalue)获取该指针，并将其作为 UI 任务调度、动画、焦点控制等接口的上下文入参。 |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md) | ArkUI_DragEvent | 拖拽事件，用于表示ArkUI组件拖拽过程中的事件信息，开发者可通过相关拖拽事件接口获取拖拽状态和事件数据。 |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md) | ArkUI_DragPreviewOption | 设置拖拽跟手图的自定义参数（如投影、圆角效果等），用于在拖拽场景中自定义预览图显示效果，帮助应用提供更符合业务需求的拖拽交互体验。 |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md) | ArkUI_DragAction | 拖拽行为句柄，用于主动发起拖拽操作，即由开发者主动调用接口启动拖拽，区别于被动响应拖拽事件。开发者可结合主动拖拽流程了解ArkUI_DragAction的创建、配置和执行机制，相关说明请参见[绑定拖拽事件](../../ui/ndk-drag-event.md)。 |
| [ArkUI_DragAndDropInfo](capi-arkui-nativemodule-arkui-draganddropinfo.md) | ArkUI_DragAndDropInfo | 主动发起拖拽后，通过拖拽状态监听返回的系统拖拽相关数据，帮助应用根据拖拽状态进行后续处理。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_DragResult](#arkui_dragresult) | ArkUI_DragResult | 拖拽结果定义，由数据接收方设置，并由系统传递给数据拖出方，拖出方可感知接收方对数据的处理结果。 |
| [ArkUI_DropOperation](#arkui_dropoperation) | ArkUI_DropOperation | 定义拖拽释放时的数据处理方式，影响角标的显示。当设置为复制行为时角标显示加号，设置为剪切行为时角标不显示加号。 |
| [ArkUI_PreDragStatus](#arkui_predragstatus) | ArkUI_PreDragStatus | 定义拖拽发起前的长按交互阶段的变化状态。 |
| [ArkUI_DragPreviewScaleMode](#arkui_dragpreviewscalemode) | ArkUI_DragPreviewScaleMode | 拖拽预览缩放模式。 |
| [ArkUI_DragStatus](#arkui_dragstatus) | ArkUI_DragStatus | 拖拽状态。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkUI_DragEvent* OH_ArkUI_NodeEvent_GetDragEvent(ArkUI_NodeEvent* nodeEvent)](#oh_arkui_nodeevent_getdragevent) | 从 NodeEvent 中获取DragEvent。 |
| [ArkUI_PreDragStatus OH_ArkUI_NodeEvent_GetPreDragStatus(ArkUI_NodeEvent* nodeEvent)](#oh_arkui_nodeevent_getpredragstatus) | 获取预览拖拽事件状态。 |
| [int32_t OH_ArkUI_DragEvent_DisableDefaultDropAnimation(ArkUI_DragEvent* event, bool disable)](#oh_arkui_dragevent_disabledefaultdropanimation) | 设置是否禁用松手时的系统默认动效，默认不禁用，通常在应用需要自定义落位动效时配置。 |
| [int32_t OH_ArkUI_DragEvent_SetSuggestedDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation dropOperation)](#oh_arkui_dragevent_setsuggesteddropoperation) | 设置数据处理方式。 |
| [int32_t OH_ArkUI_DragEvent_SetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult result)](#oh_arkui_dragevent_setdragresult) | 设置拖拽事件的结果。 |
| [int32_t OH_ArkUI_DragEvent_SetData(ArkUI_DragEvent* event, OH_UdmfData* data)](#oh_arkui_dragevent_setdata) | 向ArkUI_DragEvent中设置拖拽数据。 |
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_SetDataLoadParams(ArkUI_DragEvent* event, OH_UdmfDataLoadParams* dataLoadParams)](#oh_arkui_dragevent_setdataloadparams) | 使用此方法为系统提供一个数据加载参数，而不是直接提供一个完整的数据对象。当用户拖拽到目标应用并落入时，系统将使用dataLoadParams请求数据。可以极大地提高拖拽大量数据的效率，以及目标应用中处理落入数据的效率。此方法应始终优先于[OH_ArkUI_DragEvent_SetData](#oh_arkui_dragevent_setdata)使用。请参考<b>udmf.h</b>中的[OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create)了解如何创建和准备数据加载参数。该方法与[OH_ArkUI_DragEvent_SetData](#oh_arkui_dragevent_setdata)存在冲突，系统始终以最后调用的方法为准。 |
| [int32_t OH_ArkUI_DragEvent_GetUdmfData(ArkUI_DragEvent* event, OH_UdmfData *data)](#oh_arkui_dragevent_getudmfdata) | 从ArkUI_DragEvent中获取拖拽默认相关数据。 |
| [int32_t OH_ArkUI_DragEvent_GetDataTypeCount(ArkUI_DragEvent* event, int32_t* count)](#oh_arkui_dragevent_getdatatypecount) | 从ArkUI_DragEvent中获取所拖拽的数据类型种类个数。 |
| [int32_t OH_ArkUI_DragEvent_GetDataTypes(ArkUI_DragEvent *event, char *eventTypeArray[], int32_t length, int32_t maxStrLen)](#oh_arkui_dragevent_getdatatypes) | 从ArkUI_DragEvent中获取拖拽数据的类型列表。 |
| [int32_t OH_ArkUI_DragEvent_GetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult* result)](#oh_arkui_dragevent_getdragresult) | 从ArkUI_DragEvent中获取拖拽结果。 |
| [int32_t OH_ArkUI_DragEvent_GetDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation* operation)](#oh_arkui_dragevent_getdropoperation) | 从ArkUI_DragEvent中获取数据处理方式。 |
| [float OH_ArkUI_DragEvent_GetPreviewTouchPointX(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewtouchpointx) | 从ArkUI_DragEvent中获取预览图跟手点的x轴坐标。 |
| [float OH_ArkUI_DragEvent_GetPreviewTouchPointY(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewtouchpointy) | 从ArkUI_DragEvent中获取预览图跟手点的y轴坐标。 |
| [float OH_ArkUI_DragEvent_GetPreviewRectWidth(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewrectwidth) | 从ArkUI_DragEvent中获取预览图的宽。 |
| [float OH_ArkUI_DragEvent_GetPreviewRectHeight(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getpreviewrectheight) | 从ArkUI_DragEvent中获取预览图的高。 |
| [float OH_ArkUI_DragEvent_GetTouchPointXToWindow(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointxtowindow) | 从ArkUI_DragEvent中获取跟手点相对于window的x轴坐标。 |
| [float OH_ArkUI_DragEvent_GetTouchPointYToWindow(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointytowindow) | 从ArkUI_DragEvent中获取跟手点相对于window的y轴坐标。 |
| [float OH_ArkUI_DragEvent_GetTouchPointXToDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointxtodisplay) | 从ArkUI_DragEvent中获取跟手点相对于当前Display的x轴坐标。 |
| [float OH_ArkUI_DragEvent_GetTouchPointYToDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointytodisplay) | 从ArkUI_DragEvent中获取跟手点相对于当前Display的y轴坐标。 |
| [float OH_ArkUI_DragEvent_GetVelocityX(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getvelocityx) | 获取当前拖拽的x轴方向拖动速度。 |
| [float OH_ArkUI_DragEvent_GetVelocityY(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getvelocityy) | 获取当前拖拽的y轴方向拖动速度。 |
| [float OH_ArkUI_DragEvent_GetVelocity(ArkUI_DragEvent* event)](#oh_arkui_dragevent_getvelocity) | 获取当前拖拽的主方向拖动速度。 |
| [int32_t OH_ArkUI_DragEvent_GetModifierKeyStates(ArkUI_DragEvent* event, uint64_t* keys)](#oh_arkui_dragevent_getmodifierkeystates) | 获取修饰键按压状态。 |
| [int32_t OH_ArkUI_DragEvent_StartDataLoading(ArkUI_DragEvent* event, OH_UdmfGetDataParams* options, char* key, unsigned int keyLen)](#oh_arkui_dragevent_startdataloading) | 使用指定的同步参数开始数据同步。 |
| [int32_t OH_ArkUI_CancelDataLoading(ArkUI_ContextHandle uiContext, const char* key)](#oh_arkui_canceldataloading) | 取消正在进行的数据同步。 |
| [int32_t OH_ArkUI_DisableDropDataPrefetchOnNode(ArkUI_NodeHandle node, bool disabled)](#oh_arkui_disabledropdataprefetchonnode) | 设置是否在执行[NODE_ON_DROP](./capi-native-node-h.md#arkui_nodeeventtype)之前禁用数据预获取过程。系统将重试获取数据，直到达到最大时间限制（目前为2.4秒），这对跨设备的拖动操作非常有用，因为它有助于系统稳定通信。然而，对于[OH_ArkUI_DragEvent_StartDataLoading](#oh_arkui_dragevent_startdataloading)方法而言，这一特性显得多余。该方法采用异步机制获取数据，因此在NODE_ON_DROP中使用[OH_ArkUI_DragEvent_StartDataLoading](#oh_arkui_dragevent_startdataloading)时，为了避免在NODE_ON_DROP执行前意外获取数据，必须将此字段设置为true。 |
| [int32_t OH_ArkUI_SetDragEventStrictReportWithNode(ArkUI_NodeHandle node, bool enabled)](#oh_arkui_setdrageventstrictreportwithnode) | 设置是否开启严格dragEvent上报。建议开启，默认不开启。不开启时，从父组件拖移进子组件时，父组件不会收到leave通知；开启后，前后组件发生变化时，上一个组件会收到leave通知，新组件会收到enter通知。该配置与具体的UI实例相关，需通过传入一个当前UI实例上的组件节点来关联。 |
| [int32_t OH_ArkUI_SetDragEventStrictReportWithContext(ArkUI_ContextHandle uiContext, bool enabled)](#oh_arkui_setdrageventstrictreportwithcontext) | 设置是否开启严格dragEvent上报。建议开启，默认不开启。不开启时，从父组件拖移进子组件时，父组件不会收到leave通知；开启后，前后组件发生变化时，上一个组件会收到leave通知，新组件会收到enter通知。该配置与具体的UI实例相关，可通过传入一个UI实例来关联。 |
| [int32_t OH_ArkUI_SetNodeAllowedDropDataTypes(ArkUI_NodeHandle node, const char* typesArray[], int32_t count)](#oh_arkui_setnodealloweddropdatatypes) | 配置组件允许接受落入的数据类型，该接口会重置通过 [OH_ArkUI_DisallowNodeAnyDropDataTypes](#oh_arkui_disallownodeanydropdatatypes) 或[OH_ArkUI_AllowNodeAllDropDataTypes](#oh_arkui_allownodealldropdatatypes)进行的配置。 |
| [int32_t OH_ArkUI_DisallowNodeAnyDropDataTypes(ArkUI_NodeHandle node)](#oh_arkui_disallownodeanydropdatatypes) | 配置组件不允许接受任何数据类型，该接口会重置通过[OH_ArkUI_SetNodeAllowedDropDataTypes](#oh_arkui_setnodealloweddropdatatypes)配置的数据类型。 |
| [int32_t OH_ArkUI_AllowNodeAllDropDataTypes(ArkUI_NodeHandle node)](#oh_arkui_allownodealldropdatatypes) | 配置组件允许接受任意数据类型，该接口会重置通过[OH_ArkUI_SetNodeAllowedDropDataTypes](#oh_arkui_setnodealloweddropdatatypes)配置的数据类型。 |
| [int32_t OH_ArkUI_SetNodeDraggable(ArkUI_NodeHandle node, bool enabled)](#oh_arkui_setnodedraggable) | 设置该组件是否允许进行拖拽。 |
| [int32_t OH_ArkUI_SetNodeDragPreview(ArkUI_NodeHandle node, OH_PixelmapNative* preview)](#oh_arkui_setnodedragpreview) | 设置组件在被拖拽时的自定义跟手图。 |
| [ArkUI_DragPreviewOption* OH_ArkUI_CreateDragPreviewOption(void)](#oh_arkui_createdragpreviewoption) | 构建一个ArkUI_DragPreviewOption对象。 |
| [void OH_ArkUI_DragPreviewOption_Dispose(ArkUI_DragPreviewOption* option)](#oh_arkui_dragpreviewoption_dispose) | 销毁跟手图自定义参数对象实例。 |
| [int32_t OH_ArkUI_DragPreviewOption_SetScaleMode(ArkUI_DragPreviewOption* option, ArkUI_DragPreviewScaleMode scaleMode)](#oh_arkui_dragpreviewoption_setscalemode) | 设置拖拽跟手图是否根据系统定义自动进行缩放。 |
| [int32_t OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setdefaultshadowenabled) | 设置跟手图背板默认的投影效果，默认不开启。 |
| [int32_t OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setdefaultradiusenabled) | 设置跟手图背板默认的圆角效果（默认圆角半径为12.0vp），默认不开启。 |
| [int32_t OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setnumberbadgeenabled) | 设置跟手图背板是否显示角标，开启后，系统会根据拖拽数量自动进行角标显示。 |
| [int32_t OH_ArkUI_DragPreviewOption_SetBadgeNumber(ArkUI_DragPreviewOption* option, uint32_t forcedNumber)](#oh_arkui_dragpreviewoption_setbadgenumber) | 强制显示角标的数量，覆盖[OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled](#oh_arkui_dragpreviewoption_setnumberbadgeenabled)设置的值。 |
| [int32_t OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled(ArkUI_DragPreviewOption* option, bool enabled)](#oh_arkui_dragpreviewoption_setdefaultanimationbeforeliftingenabled) | 配置是否开启点按时的默认动画，适用于需要在拖拽浮起前提供按压视觉反馈的场景。 |
| [int32_t OH_ArkUI_SetNodeDragPreviewOption(ArkUI_NodeHandle node, ArkUI_DragPreviewOption* option)](#oh_arkui_setnodedragpreviewoption) | 将构造的ArkUI_DragPreviewOption设置给组件。 |
| [ArkUI_DragAction* OH_ArkUI_CreateDragActionWithNode(ArkUI_NodeHandle node)](#oh_arkui_createdragactionwithnode) | 创建一个拖拽操作对象，该对象需与一个UI实例相关联，可通过传入一个当前UI实例的某个组件节点来指定。 |
| [ArkUI_DragAction* OH_ArkUI_CreateDragActionWithContext(ArkUI_ContextHandle uiContext)](#oh_arkui_createdragactionwithcontext) | 创建一个拖拽操作对象，该对象需与一个UI实例相关联，可通过传入一个UI实例指针来关联。 |
| [void OH_ArkUI_DragAction_Dispose(ArkUI_DragAction* dragAction)](#oh_arkui_dragaction_dispose) | 销毁创建的 ArkUI_DragAction 对象。 |
| [int32_t OH_ArkUI_DragAction_SetPointerId(ArkUI_DragAction* dragAction, int32_t pointer)](#oh_arkui_dragaction_setpointerid) | 设置手指ID，当屏幕上仅有一只手指在操作时，手指ID为0；一般情况下，配置0即可。 |
| [int32_t OH_ArkUI_DragAction_SetPixelMaps(ArkUI_DragAction* dragAction, OH_PixelmapNative* pixelmapArray[], int32_t size)](#oh_arkui_dragaction_setpixelmaps) | 设置拖拽跟手图，只能使用 pixelmap 格式对象。 |
| [int32_t OH_ArkUI_DragAction_SetTouchPointX(ArkUI_DragAction* dragAction, float x)](#oh_arkui_dragaction_settouchpointx) | 设置跟手点，相对于设置的第一个pixelmap的左上角。 |
| [int32_t OH_ArkUI_DragAction_SetTouchPointY(ArkUI_DragAction* dragAction, float y)](#oh_arkui_dragaction_settouchpointy) | 设置跟手点，相对于设置的第一个pixelmap的左上角。 |
| [int32_t OH_ArkUI_DragAction_SetData(ArkUI_DragAction* dragAction, OH_UdmfData* data)](#oh_arkui_dragaction_setdata) | 设置拖拽数据。 |
| [ArkUI_ErrorCode OH_ArkUI_DragAction_SetDataLoadParams(ArkUI_DragAction* dragAction,OH_UdmfDataLoadParams* dataLoadParams)](#oh_arkui_dragaction_setdataloadparams) | 使用此方法为系统提供一个数据加载参数，而不是直接提供一个完整的数据对象。当用户拖拽到目标应用并落入时，系统将使用dataLoadParams请求数据。可以极大地提高拖拽大量数据的效率，以及目标应用中处理落入数据的效率。此方法应始终优先于[OH_ArkUI_DragAction_SetData](#oh_arkui_dragaction_setdata)使用。请参考<b>udmf.h</b>中的[OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create)了解如何创建和准备数据加载参数。该方法与[OH_ArkUI_DragAction_SetData](#oh_arkui_dragaction_setdata)存在冲突，系统始终以最后调用的方法为准。 |
| [int32_t OH_ArkUI_DragAction_SetDragPreviewOption(ArkUI_DragAction* dragAction, ArkUI_DragPreviewOption* option)](#oh_arkui_dragaction_setdragpreviewoption) | 将构造的ArkUI_DragPreviewOption设置给ArkUI_DragAction。 |
| [int32_t OH_ArkUI_DragAction_RegisterStatusListener(ArkUI_DragAction* dragAction, void* userData,void(\*listener)(ArkUI_DragAndDropInfo* dragAndDropInfo, void* userData))](#oh_arkui_dragaction_registerstatuslistener) | 注册拖拽状态监听回调，该回调可感知到拖拽已经发起或用户松手结束的状态，可通过该监听获取到落入方对数据的接收处理是否成功。 |
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDisplayId(ArkUI_DragEvent* event, int32_t* displayId)](#oh_arkui_dragevent_getdisplayid) | 获取当前拖拽事件发生时所在的屏幕ID，不支持当eventType为NODE_ON_DRAG_END时获取。 |
| [void OH_ArkUI_DragAction_UnregisterStatusListener(ArkUI_DragAction* dragAction)](#oh_arkui_dragaction_unregisterstatuslistener) | 解注册拖拽状态监听回调。 |
| [ArkUI_DragStatus OH_ArkUI_DragAndDropInfo_GetDragStatus(ArkUI_DragAndDropInfo* dragAndDropInfo)](#oh_arkui_draganddropinfo_getdragstatus) | 获取[ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)发起拖拽的状态，获取异常时返回 ArkUI_DRAG_STATUS_UNKNOWN。 |
| [ArkUI_DragEvent* OH_ArkUI_DragAndDropInfo_GetDragEvent(ArkUI_DragAndDropInfo* dragAndDropInfo)](#oh_arkui_draganddropinfo_getdragevent) | 通过dragAndDropInfo获取到DragEvent，可通过DragEvent获取释放结果等。 |
| [int32_t OH_ArkUI_StartDrag(ArkUI_DragAction* dragAction)](#oh_arkui_startdrag) | 通过构造的DragAction对象发起拖拽。 |
| [int32_t OH_ArkUI_DragEvent_RequestDragEndPending(ArkUI_DragEvent* event, int32_t* requestIdentify)](#oh_arkui_dragevent_requestdragendpending) | 请求延迟处理拖拽结束事件，等待应用确认操作结果。应用需通过 [OH_ArkUI_NotifyDragResult](#oh_arkui_notifydragresult)接口将最终结果回传至系统，并在所有处理完成后调用 [OH_ArkUI_NotifyDragEndPendingDone](#oh_arkui_notifydragendpendingdone)。最大等待时间为2秒。 |
| [int32_t OH_ArkUI_NotifyDragResult(int32_t requestIdentify, ArkUI_DragResult result)](#oh_arkui_notifydragresult) | 通知系统最终拖拽结果。系统会校验请求标识符是否与[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)返回的一致，不一致则忽略本次调用。 |
| [int32_t OH_ArkUI_NotifySuggestedDropOperation(int32_t requestIdentity, ArkUI_DropOperation operation)](#oh_arkui_notifysuggesteddropoperation) | 通知拖拽发起方本次落入的行为类型，该函数需在落入阶段调用。拖拽发起方可以在拖拽结束的回调中调用[OH_ArkUI_DragEvent_GetDropOperation](#oh_arkui_dragevent_getdropoperation)获取本次落入的行为类型，进行自定义处理。也可以选择忽略该通知，不进行处理。拖拽失败时，本次落入的行为类型不可信，此时调用[OH_ArkUI_DragEvent_GetDropOperation](#oh_arkui_dragevent_getdropoperation)获取到的行为类型恒为ARKUI_DROP_OPERATION_COPY。系统会校验requestIdentity是否与[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)返回的一致，不一致则本次调用不生效。 |
| [int32_t OH_ArkUI_NotifyDisableDefaultDropAnimation(int32_t requestIdentity, bool disable)](#oh_arkui_notifydisabledefaultdropanimation) | 通知系统是否禁用默认的落入动画，该函数需在落入阶段调用。拖拽失败时，默认的落入动画为扩散动画，拖拽成功时默认的落入动画为收缩淡出动画。调用此方法可禁用默认动画，根据需要实现自定义落入动画。系统会校验requestIdentity是否与[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)返回的一致，不一致则本次调用不生效。 |
| [int32_t OH_ArkUI_NotifyDragEndPendingDone(int32_t requestIdentify)](#oh_arkui_notifydragendpendingdone) | 通知系统所有异步处理已完成，可结束拖拽结束挂起状态。 |
| [ArkUI_ErrorCode OH_ArkUI_EnableDropDisallowedBadge(ArkUI_ContextHandle uiContext, bool enabled)](#oh_arkui_enabledropdisallowedbadge) | 设置是否可以显示禁用角标。 |
| [float OH_ArkUI_DragEvent_GetTouchPointXToGlobalDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointxtoglobaldisplay) | 从ArkUI_DragEvent中获取跟手点相对于全局屏幕的x轴坐标。 |
| [float OH_ArkUI_DragEvent_GetTouchPointYToGlobalDisplay(ArkUI_DragEvent* event)](#oh_arkui_dragevent_gettouchpointytoglobaldisplay) | 从ArkUI_DragEvent中获取跟手点相对于全局屏幕的y轴坐标。 |
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDragSource(ArkUI_DragEvent* event, char *bundleName, int32_t length)](#oh_arkui_dragevent_getdragsource) | 获取拖拽发起方的应用包名信息，可用于识别拖拽来源应用、按来源进行校验或执行差异化处理；调用时需要传递一个字符数组来接收包名字符串，并显式指明数组长度，该数组长度不小于128个字符。 |
| [ArkUI_ErrorCode OH_ArkUI_DragEvent_IsRemote(ArkUI_DragEvent* event, bool* isRemote)](#oh_arkui_dragevent_isremote) | 判断当前的拖拽操作是否是跨设备拖拽。 |

## 枚举类型说明

### ArkUI_DragResult

```c
enum ArkUI_DragResult
```

**描述：**


拖拽结果定义，由数据接收方设置，并由系统传递给数据拖出方，拖出方可感知接收方对数据的处理结果。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DRAG_RESULT_SUCCESSFUL = 0 | 拖拽处理成功。 |
| ARKUI_DRAG_RESULT_FAILED = 1 | 拖拽处理失败。 |
| ARKUI_DRAG_RESULT_CANCELED = 2 | 拖拽处理取消。 |

### ArkUI_DropOperation

```c
enum ArkUI_DropOperation
```

**描述：**


定义拖拽释放时的数据处理方式，影响角标的显示。当设置为复制行为时角标显示加号，设置为剪切行为时角标不显示加号。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DROP_OPERATION_COPY = 0 | 复制行为。 |
| ARKUI_DROP_OPERATION_MOVE = 1 | 剪切行为。 |

### ArkUI_PreDragStatus

```c
enum ArkUI_PreDragStatus
```

**描述：**


定义拖拽发起前的长按交互阶段的变化状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_PRE_DRAG_STATUS_UNKNOWN = -1 | 获取拖拽发起前状态失败。 |
| ARKUI_PRE_DRAG_STATUS_ACTION_DETECTING = 0 | 拖拽手势启动阶段。 |
| ARKUI_PRE_DRAG_STATUS_READY_TO_TRIGGER_DRAG = 1 | 拖拽准备完成，可发起拖拽阶段。 |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_STARTED = 2 | 拖拽浮起动效发起阶段。 |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_FINISHED = 3 | 拖拽浮起动效结束阶段。 |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_STARTED = 4 | 拖拽落回动效发起阶段。 |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_FINISHED = 5 | 拖拽落回动效结束阶段。 |
| ARKUI_PRE_DRAG_STATUS_CANCELED_BEFORE_DRAG = 6 | 拖拽浮起落位动效中断。 |

### ArkUI_DragPreviewScaleMode

```c
enum ArkUI_DragPreviewScaleMode
```

**描述：**


拖拽预览缩放模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DRAG_PREVIEW_SCALE_AUTO = 0 | 系统根据拖拽场景自动改变跟手点位置，根据规则自动对拖拽背板图进行缩放变换等。 |
| ARKUI_DRAG_PREVIEW_SCALE_DISABLED = 1 | 禁用系统对拖拽背板图的缩放行为。 |

### ArkUI_DragStatus

```c
enum ArkUI_DragStatus
```

**描述：**


拖拽状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DRAG_STATUS_UNKNOWN = -1 | 未知的拖拽状态。 |
| ARKUI_DRAG_STATUS_STARTED = 0 | 拖拽开始。 |
| ARKUI_DRAG_STATUS_ENDED = 1 | 拖拽结束。 |


## 函数说明

### OH_ArkUI_NodeEvent_GetDragEvent()

```c
ArkUI_DragEvent* OH_ArkUI_NodeEvent_GetDragEvent(ArkUI_NodeEvent* nodeEvent)
```

**描述：**


从 NodeEvent 中获取DragEvent。

**起始版本：** 12


**参数：**

| 参数项                            | 描述 |
|--------------------------------| -- |
| [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)* nodeEvent | ArkUI_NodeEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* | ArkUI_DragEvent 事件指针，当传入的 NodeEvent 无效或不是拖拽相关的事件时，则返回空。 |

### OH_ArkUI_NodeEvent_GetPreDragStatus()

```c
ArkUI_PreDragStatus OH_ArkUI_NodeEvent_GetPreDragStatus(ArkUI_NodeEvent* nodeEvent)
```

**描述：**


获取预览拖拽事件状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)* nodeEvent | ArkUI_NodeEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_PreDragStatus](#arkui_predragstatus) | ArkUI_PreDragStatus 拖拽发起前交互状态。 |

### OH_ArkUI_DragEvent_DisableDefaultDropAnimation()

```c
int32_t OH_ArkUI_DragEvent_DisableDefaultDropAnimation(ArkUI_DragEvent* event, bool disable)
```

**描述：**


设置是否禁用松手时的系统默认动效，默认不禁用，通常在应用需要自定义落位动效时配置。与[OH_ArkUI_NotifyDisableDefaultDropAnimation](#oh_arkui_notifydisabledefaultdropanimation)功能相同，区别在于：本方法在同步的拖拽事件回调中直接设置，适用于不需要延迟处理拖拽结束事件的场景；OH_ArkUI_NotifyDisableDefaultDropAnimation在异步的RequestDragEndPending流程中通知，适用于已调用[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)延迟处理拖拽结束事件的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| bool disable | 是否禁用松手时的系统默认动效，true禁用，false不禁用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_SetSuggestedDropOperation()

```c
int32_t OH_ArkUI_DragEvent_SetSuggestedDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation dropOperation)
```

**描述：**


设置数据处理方式。与[OH_ArkUI_NotifySuggestedDropOperation](#oh_arkui_notifysuggesteddropoperation)功能相同，区别在于：本方法在同步的拖拽事件回调中直接设置，适用于不需要延迟处理拖拽结束事件的场景；OH_ArkUI_NotifySuggestedDropOperation在异步的RequestDragEndPending流程中通知，适用于已调用[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)延迟处理拖拽结束事件的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [ArkUI_DropOperation](#arkui_dropoperation) dropOperation | 数据处理方式，用于设置拖拽释放时的操作类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_SetDragResult()

```c
int32_t OH_ArkUI_DragEvent_SetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult result)
```

**描述：**


设置拖拽事件的结果。与[OH_ArkUI_NotifyDragResult](#oh_arkui_notifydragresult)功能相同，区别在于：本方法在同步的拖拽事件回调中直接设置，适用于不需要延迟处理拖拽结束事件的场景；OH_ArkUI_NotifyDragResult在异步的RequestDragEndPending流程中通知，适用于已调用[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)延迟处理拖拽结束事件的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [ArkUI_DragResult](#arkui_dragresult) result | 拖拽数据处理结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_SetData()

```c
int32_t OH_ArkUI_DragEvent_SetData(ArkUI_DragEvent* event, OH_UdmfData* data)
```

**描述：**


向ArkUI_DragEvent中设置拖拽数据。应优先使用[OH_ArkUI_DragEvent_SetDataLoadParams](capi-drag-and-drop-h.md#oh_arkui_dragevent_setdataloadparams)提供数据加载参数，以提高拖拽大量数据及目标应用处理落入数据的效率。该方法与[OH_ArkUI_DragEvent_SetDataLoadParams](capi-drag-and-drop-h.md#oh_arkui_dragevent_setdataloadparams)存在冲突，系统始终以最后调用的方法为准。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)* data | 要设置的拖拽数据对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_SetDataLoadParams()

```c
ArkUI_ErrorCode OH_ArkUI_DragEvent_SetDataLoadParams(ArkUI_DragEvent* event, OH_UdmfDataLoadParams* dataLoadParams)
```

**描述：**


使用此方法为系统提供一个数据加载参数，而不是直接提供一个完整的数据对象。当用户拖拽到目标应用并落入时，系统将使用dataLoadParams请求数据。可以极大地提高拖拽大量数据的效率，以及目标应用中处理落入数据的效率。此方法应始终优先于[OH_ArkUI_DragEvent_SetData](#oh_arkui_dragevent_setdata)使用。请参考<b>udmf.h</b>中的[OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create)了解如何创建和准备数据加载参数。该方法与[OH_ArkUI_DragEvent_SetData](#oh_arkui_dragevent_setdata)存在冲突，系统始终以最后调用的方法为准。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [OH_UdmfDataLoadParams](../apis-arkdata/capi-udmf-oh-udmfdataloadparams.md)* dataLoadParams | 落入操作时使用的数据加载参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_GetUdmfData()

```c
int32_t OH_ArkUI_DragEvent_GetUdmfData(ArkUI_DragEvent* event, OH_UdmfData *data)
```

**描述：**


从ArkUI_DragEvent中获取拖拽默认相关数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md) *data | OH_UdmfData 拖拽的数据指针，应用在接收时需通过 [OH_UdmfData_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdata_create) 方法创建一个用于接收数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_GetDataTypeCount()

```c
int32_t OH_ArkUI_DragEvent_GetDataTypeCount(ArkUI_DragEvent* event, int32_t* count)
```

**描述：**


从ArkUI_DragEvent中获取所拖拽的数据类型种类个数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| int32_t* count | 出参，返回所拖拽数据的类型的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_GetDataTypes()

```c
int32_t OH_ArkUI_DragEvent_GetDataTypes(ArkUI_DragEvent *event, char *eventTypeArray[], int32_t length, int32_t maxStrLen)
```

**描述：**


从ArkUI_DragEvent中获取拖拽数据的类型列表。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md) *event | ArkUI_DragEvent事件指针。 |
| char *eventTypeArray[] | 返回拖拽数据的类型列表，需要先自行创建字符串数组。 |
| int32_t length | 数组总长度，不应少于使用[OH_ArkUI_DragEvent_GetDataTypeCount](#oh_arkui_dragevent_getdatatypecount)获取到的数量。 |
| int32_t maxStrLen | 拖拽数据类型的最大字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 传入的缓冲区大小异常。 |

### OH_ArkUI_DragEvent_GetDragResult()

```c
int32_t OH_ArkUI_DragEvent_GetDragResult(ArkUI_DragEvent* event, ArkUI_DragResult* result)
```

**描述：**


从ArkUI_DragEvent中获取拖拽结果。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [ArkUI_DragResult](capi-drag-and-drop-h.md#arkui_dragresult)* result | 出参，返回拖拽事件对应的拖拽结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_GetDropOperation()

```c
int32_t OH_ArkUI_DragEvent_GetDropOperation(ArkUI_DragEvent* event, ArkUI_DropOperation* operation)
```

**描述：**


从ArkUI_DragEvent中获取数据处理方式。拖拽失败时，本次落入的行为类型不可信，此时获取到的行为类型恒为ARKUI_DROP_OPERATION_COPY。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [ArkUI_DropOperation](capi-drag-and-drop-h.md#arkui_dropoperation)* operation | 返回拖拽事件的数据处理方式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>                可能原因：1. 参数为空或event非有效的DragEvent。 |

### OH_ArkUI_DragEvent_GetPreviewTouchPointX()

```c
float OH_ArkUI_DragEvent_GetPreviewTouchPointX(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取预览图跟手点的x轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手点的x轴坐标，单位为px，传入参数无效时返回默认值0。 |

### OH_ArkUI_DragEvent_GetPreviewTouchPointY()

```c
float OH_ArkUI_DragEvent_GetPreviewTouchPointY(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取预览图跟手点的y轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手点的y轴坐标，单位为px，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetPreviewRectWidth()

```c
float OH_ArkUI_DragEvent_GetPreviewRectWidth(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取预览图的宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手图宽度，单位为px，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetPreviewRectHeight()

```c
float OH_ArkUI_DragEvent_GetPreviewRectHeight(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取预览图的高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手图高度，单位为px，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetTouchPointXToWindow()

```c
float OH_ArkUI_DragEvent_GetTouchPointXToWindow(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取跟手点相对于window的x轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回跟手点相对于window的x轴坐标，单位为px，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetTouchPointYToWindow()

```c
float OH_ArkUI_DragEvent_GetTouchPointYToWindow(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取跟手点相对于window的y轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回跟手点相对于window的y轴坐标，单位为px，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetTouchPointXToDisplay()

```c
float OH_ArkUI_DragEvent_GetTouchPointXToDisplay(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取跟手点相对于当前Display的x轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手点相对于当前Display的x轴坐标，单位为px，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetTouchPointYToDisplay()

```c
float OH_ArkUI_DragEvent_GetTouchPointYToDisplay(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取跟手点相对于当前Display的y轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手点相对于当前Display的y轴坐标，单位为px，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetVelocityX()

```c
float OH_ArkUI_DragEvent_GetVelocityX(ArkUI_DragEvent* event)
```

**描述：**


获取当前拖拽的x轴方向拖动速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回当前拖拽的x轴方向移动速度，单位为px/s，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetVelocityY()

```c
float OH_ArkUI_DragEvent_GetVelocityY(ArkUI_DragEvent* event)
```

**描述：**


获取当前拖拽的y轴方向拖动速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回当前拖拽的y轴方向移动速度，单位为px/s，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetVelocity()

```c
float OH_ArkUI_DragEvent_GetVelocity(ArkUI_DragEvent* event)
```

**描述：**


获取当前拖拽的主方向拖动速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回当前拖拽移动速度，单位为px/s，传入参数无效时返回默认值0。|

### OH_ArkUI_DragEvent_GetModifierKeyStates()

```c
int32_t OH_ArkUI_DragEvent_GetModifierKeyStates(ArkUI_DragEvent* event, uint64_t* keys)
```

**描述：**


获取修饰键按压状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| uint64_t* keys | 返回当前处于按下状态的修饰键组合。取值为各修饰键对应比特位掩码的按位或结果：Ctrl键对应第0位（掩码值0x1），Shift键对应第1位（掩码值0x2），Alt键对应第2位（掩码值0x4）。应用可通过位运算判断对应修饰键是否处于按下状态，例如使用(*keys & 0x1)判断Ctrl键是否按下。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_StartDataLoading()

```c
int32_t OH_ArkUI_DragEvent_StartDataLoading(ArkUI_DragEvent* event, OH_UdmfGetDataParams* options, char* key, unsigned int keyLen)
```

**描述：**


使用指定的同步参数开始数据同步。在NODE_ON_DROP中使用该方法时，为了避免在NODE_ON_DROP执行前意外获取数据，需先通过[OH_ArkUI_DisableDropDataPrefetchOnNode](capi-drag-and-drop-h.md#oh_arkui_disabledropdataprefetchonnode)将数据预获取过程设置为禁用。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| [OH_UdmfGetDataParams](../apis-arkdata/capi-udmf-oh-udmfgetdataparams.md)* options | 数据获取参数指针，用于配置本次拖拽数据同步时的数据请求选项。 |
| char* key | 返回数据设置成功之后的key值，用于接收key值的字符数组长度不小于[UDMF_KEY_BUFFER_LEN](../apis-arkdata/capi-udmf-h.md#宏定义)。 |
| unsigned int keyLen | 表示key字符串的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CancelDataLoading()

```c
int32_t OH_ArkUI_CancelDataLoading(ArkUI_ContextHandle uiContext, const char* key)
```

**描述：**


取消正在进行的数据同步。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI实例对象指针。 |
| const char* key | 表示通过 [OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading) 返回的数据key值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DisableDropDataPrefetchOnNode()

```c
int32_t OH_ArkUI_DisableDropDataPrefetchOnNode(ArkUI_NodeHandle node, bool disabled)
```

**描述：**


设置是否在执行[NODE_ON_DROP](./capi-native-node-h.md#arkui_nodeeventtype)之前禁用数据预获取过程。系统将重试获取数据，直到达到最大时间限制（目前为2.4秒），这对跨设备的拖动操作非常有用，因为它有助于系统稳定通信。然而，对于[OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading)方法而言，这一特性显得多余。该方法采用异步机制获取数据，因此在NODE_ON_DROP中使用[OH_ArkUI_DragEvent_StartDataLoading](capi-drag-and-drop-h.md#oh_arkui_dragevent_startdataloading)时，为了避免在NODE_ON_DROP执行前意外获取数据，必须将此字段设置为true。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |
| bool disabled | 表示是否禁用数据预取过程。true表示禁止，false表示不禁止。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SetDragEventStrictReportWithNode()

```c
int32_t OH_ArkUI_SetDragEventStrictReportWithNode(ArkUI_NodeHandle node, bool enabled)
```

**描述：**


设置是否开启严格dragEvent上报。建议开启，默认不开启。不开启时，从父组件拖移进子组件时，父组件不会收到leave通知；开启后，前后组件发生变化时，上一个组件会收到leave通知，新组件会收到enter通知。该配置与具体的UI实例相关，需通过传入一个当前UI实例上的组件节点来关联。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |
| bool enabled | 是否开启严格上报。true表示开启严格上报，false表示关闭严格上报。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SetDragEventStrictReportWithContext()

```c
int32_t OH_ArkUI_SetDragEventStrictReportWithContext(ArkUI_ContextHandle uiContext, bool enabled)
```

**描述：**


设置是否开启严格dragEvent上报。建议开启，默认不开启。不开启时，从父组件拖移进子组件时，父组件不会收到leave通知；开启后，前后组件发生变化时，上一个组件会收到leave通知，新组件会收到enter通知。该配置与具体的UI实例相关，可通过传入一个UI实例来关联。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI实例指针。 |
| bool enabled | 是否开启严格上报。true表示开启严格上报，false表示关闭严格上报。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SetNodeAllowedDropDataTypes()

```c
int32_t OH_ArkUI_SetNodeAllowedDropDataTypes(ArkUI_NodeHandle node, const char* typesArray[], int32_t count)
```

**描述：**


配置组件允许接受落入的数据类型，该接口会重置通过 [OH_ArkUI_DisallowNodeAnyDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_disallownodeanydropdatatypes) 或[OH_ArkUI_AllowNodeAllDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_allownodealldropdatatypes)进行的配置。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |
| const char* typesArray[] | 允许落入的数据类型数组，数组元素为UDMF定义的统一数据类型标识符字符串。 |
| int32_t count | 数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DisallowNodeAnyDropDataTypes()

```c
int32_t OH_ArkUI_DisallowNodeAnyDropDataTypes(ArkUI_NodeHandle node)
```

**描述：**


配置组件不允许接受任何数据类型，该接口会重置通过[OH_ArkUI_SetNodeAllowedDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_setnodealloweddropdatatypes)配置的数据类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AllowNodeAllDropDataTypes()

```c
int32_t OH_ArkUI_AllowNodeAllDropDataTypes(ArkUI_NodeHandle node)
```

**描述：**


配置组件允许接受任意数据类型，该接口会重置通过[OH_ArkUI_SetNodeAllowedDropDataTypes](capi-drag-and-drop-h.md#oh_arkui_setnodealloweddropdatatypes)配置的数据类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SetNodeDraggable()

```c
int32_t OH_ArkUI_SetNodeDraggable(ArkUI_NodeHandle node, bool enabled)
```

**描述：**


设置该组件是否允许进行拖拽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |
| bool enabled | 是否支持拖出。true表示支持拖出，false表示不支持拖出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SetNodeDragPreview()

```c
int32_t OH_ArkUI_SetNodeDragPreview(ArkUI_NodeHandle node, OH_PixelmapNative* preview)
```

**描述：**


设置组件在被拖拽时的自定义跟手图。

**起始版本：** 12


**参数：**

| 参数项                                                              | 描述 |
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 目标组件节点指针。 |
| [OH_PixelmapNative](capi-arkui-nativemodule-oh-pixelmapnative8h.md)* preview                                   | 自定义跟手图，使用 pixelmap 格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CreateDragPreviewOption()

```c
ArkUI_DragPreviewOption* OH_ArkUI_CreateDragPreviewOption(void)
```

**描述：**


构建一个ArkUI_DragPreviewOption对象。对象使用完成后，需要调用[OH_ArkUI_DragPreviewOption_Dispose](#oh_arkui_dragpreviewoption_dispose)销毁该对象，避免资源未及时释放。

**起始版本：** 12

**返回：**

| 类型                           | 说明 |
|------------------------------| -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* | ArkUI_DragPreviewOption对象，用于配置拖拽跟手图的自定义参数。 |

### OH_ArkUI_DragPreviewOption_Dispose()

```c
void OH_ArkUI_DragPreviewOption_Dispose(ArkUI_DragPreviewOption* option)
```

**描述：**


销毁跟手图自定义参数对象实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 待销毁的拖拽跟手图自定义参数对象。 |

### OH_ArkUI_DragPreviewOption_SetScaleMode()

```c
int32_t OH_ArkUI_DragPreviewOption_SetScaleMode(ArkUI_DragPreviewOption* option, ArkUI_DragPreviewScaleMode scaleMode)
```

**描述：**


设置拖拽跟手图是否根据系统定义自动进行缩放，适用于需要在拖拽过程中按系统规则调整跟手图大小，或需要保持自定义跟手图原始尺寸的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 拖拽跟手图自定义参数对象，用于设置跟手图缩放模式。 |
| [ArkUI_DragPreviewScaleMode](capi-drag-and-drop-h.md#arkui_dragpreviewscalemode) scaleMode | 设置组件拖拽过程中的跟手图缩放模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled()

```c
int32_t OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**描述：**


设置跟手图背板默认的投影效果，默认不开启。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 拖拽跟手图自定义参数对象，用于设置跟手图背板默认投影效果。 |
| bool enabled | 是否使用默认投影效果。true表示使用默认投影效果，false表示不使用默认投影效果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled()

```c
int32_t OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**描述：**


设置跟手图背板默认的圆角效果（默认圆角半径为12.0vp），默认不开启。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 拖拽跟手图自定义参数对象，用于设置跟手图背板默认圆角效果。 |
| bool enabled | 是否开启圆角效果显示。true表示开启圆角效果显示，false表示不开启圆角效果显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled()

```c
int32_t OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**描述：**


设置跟手图背板是否显示角标，开启后，系统会根据拖拽数量自动进行角标显示。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 拖拽跟手图自定义参数对象，用于设置跟手图背板是否显示数量角标。 |
| bool enabled | 是否开启角标显示。true表示开启角标显示，false表示不开启角标显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragPreviewOption_SetBadgeNumber()

```c
int32_t OH_ArkUI_DragPreviewOption_SetBadgeNumber(ArkUI_DragPreviewOption* option, uint32_t forcedNumber)
```

**描述：**


强制显示角标的数量，覆盖[OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled](#oh_arkui_dragpreviewoption_setnumberbadgeenabled)设置的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 拖拽跟手图自定义参数对象，用于设置强制显示的角标数量。 |
| uint32_t forcedNumber | 角标的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled()

```c
int32_t OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled(ArkUI_DragPreviewOption* option, bool enabled)
```

**描述：**


配置是否开启点按时的默认动画，适用于需要在拖拽浮起前提供按压视觉反馈的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 拖拽跟手图自定义参数对象。 |
| bool enabled | 是否开启默认点按效果。true表示开启默认点按效果，false表示不开启默认点按效果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SetNodeDragPreviewOption()

```c
int32_t OH_ArkUI_SetNodeDragPreviewOption(ArkUI_NodeHandle node, ArkUI_DragPreviewOption* option)
```

**描述：**


将构造的ArkUI_DragPreviewOption设置给组件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 要设置到目标组件上的拖拽跟手图自定义参数对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CreateDragActionWithNode()

```c
ArkUI_DragAction* OH_ArkUI_CreateDragActionWithNode(ArkUI_NodeHandle node)
```

**描述：**


创建一个拖拽操作对象，该对象需与一个UI实例相关联，可通过传入一个当前UI实例的某个组件节点来指定。对象使用完成后，需要调用[OH_ArkUI_DragAction_Dispose](#oh_arkui_dragaction_dispose)销毁该对象，避免资源未及时释放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 组件节点指针。 |

**返回：**

| 类型                    | 说明 |
|-----------------------| -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* | ArkUI_DragAction对象指针，用于配置并主动发起拖拽操作；如果创建失败，则返回空。 |

### OH_ArkUI_CreateDragActionWithContext()

```c
ArkUI_DragAction* OH_ArkUI_CreateDragActionWithContext(ArkUI_ContextHandle uiContext)
```

**描述：**


创建一个拖拽操作对象，该对象需与一个UI实例相关联，可通过传入一个UI实例指针来关联。对象使用完成后，需要调用[OH_ArkUI_DragAction_Dispose](#oh_arkui_dragaction_dispose)销毁该对象，避免资源未及时释放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI实例对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* | ArkUI_DragAction对象，用于配置并主动发起拖拽操作；如果创建失败，则返回空。 |

### OH_ArkUI_DragAction_Dispose()

```c
void OH_ArkUI_DragAction_Dispose(ArkUI_DragAction* dragAction)
```

**描述：**


销毁创建的 ArkUI_DragAction 对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |

### OH_ArkUI_DragAction_SetPointerId()

```c
int32_t OH_ArkUI_DragAction_SetPointerId(ArkUI_DragAction* dragAction, int32_t pointer)
```

**描述：**


设置手指ID，当屏幕上仅有一只手指在操作时，手指ID为0；一般情况下，配置0即可。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |
| int32_t pointer | 手指ID，范围0～9。取值超出时默认置为-1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_SetPixelMaps()

```c
int32_t OH_ArkUI_DragAction_SetPixelMaps(ArkUI_DragAction* dragAction, OH_PixelmapNative* pixelmapArray[], int32_t size)
```

**描述：**


设置拖拽跟手图，只能使用 pixelmap 格式对象。

**起始版本：** 12


**参数：**

| 参数项                                                                                  | 描述 |
|--------------------------------------------------------------------------------------| -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction          | 拖拽行为对象。 |
| [OH_PixelmapNative](capi-arkui-nativemodule-oh-pixelmapnative8h.md)* pixelmapArray[] | 拖拽跟手图位图数组。<br>**说明：** 该参数必须为堆上分配对象，请开发者手动管理其生命周期。 |
| int32_t size | 拖拽跟手图数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_SetTouchPointX()

```c
int32_t OH_ArkUI_DragAction_SetTouchPointX(ArkUI_DragAction* dragAction, float x)
```

**描述：**


设置跟手点，相对于设置的第一个pixelmap的左上角。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |
| float x | 跟手点坐标x值，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_SetTouchPointY()

```c
int32_t OH_ArkUI_DragAction_SetTouchPointY(ArkUI_DragAction* dragAction, float y)
```

**描述：**


设置跟手点，相对于设置的第一个pixelmap的左上角。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |
| float y | 跟手点坐标y值，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_SetData()

```c
int32_t OH_ArkUI_DragAction_SetData(ArkUI_DragAction* dragAction, OH_UdmfData* data)
```

**描述：**


设置拖拽数据。应优先使用[OH_ArkUI_DragAction_SetDataLoadParams](capi-drag-and-drop-h.md#oh_arkui_dragaction_setdataloadparams)提供数据加载参数，以提高拖拽大量数据及目标应用处理落入数据的效率。该方法与[OH_ArkUI_DragAction_SetDataLoadParams](capi-drag-and-drop-h.md#oh_arkui_dragaction_setdataloadparams)存在冲突，系统始终以最后调用的方法为准。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |
| [OH_UdmfData](../apis-arkdata/capi-udmf-oh-udmfdata.md)* data | 要设置的拖拽数据对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_SetDataLoadParams()

```c
ArkUI_ErrorCode OH_ArkUI_DragAction_SetDataLoadParams(ArkUI_DragAction* dragAction, OH_UdmfDataLoadParams* dataLoadParams)
```

**描述：**


使用此方法为系统提供一个数据加载参数，而不是直接提供一个完整的数据对象。当用户拖拽到目标应用并落入时，系统将使用dataLoadParams请求数据。可以极大地提高拖拽大量数据的效率，以及目标应用中处理落入数据的效率。此方法应始终优先于[OH_ArkUI_DragAction_SetData](#oh_arkui_dragaction_setdata)使用。请参考<b>udmf.h</b>中的[OH_UdmfDataLoadParams_Create](../apis-arkdata/capi-udmf-h.md#oh_udmfdataloadparams_create)了解如何创建和准备数据加载参数。该方法与[OH_ArkUI_DragAction_SetData](#oh_arkui_dragaction_setdata)存在冲突，系统始终以最后调用的方法为准。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |
| [OH_UdmfDataLoadParams](../apis-arkdata/capi-udmf-oh-udmfdataloadparams.md)* dataLoadParams | 在落入操作时使用的数据加载参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_SetDragPreviewOption()

```c
int32_t OH_ArkUI_DragAction_SetDragPreviewOption(ArkUI_DragAction* dragAction, ArkUI_DragPreviewOption* option)
```

**描述：**


将构造的ArkUI_DragPreviewOption设置给ArkUI_DragAction。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |
| [ArkUI_DragPreviewOption](capi-arkui-nativemodule-arkui-dragpreviewoption.md)* option | 要设置到ArkUI_DragAction上的拖拽跟手图自定义参数对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_RegisterStatusListener()

```c
int32_t OH_ArkUI_DragAction_RegisterStatusListener(ArkUI_DragAction* dragAction, void* userData, void(*listener)(ArkUI_DragAndDropInfo* dragAndDropInfo, void* userData))
```

**描述：**


注册拖拽状态监听回调，该回调可感知到拖拽已经发起或用户松手结束的状态，可通过该监听获取到落入方对数据的接收处理是否成功。不再需要监听拖拽状态时，需要调用[OH_ArkUI_DragAction_UnregisterStatusListener](#oh_arkui_dragaction_unregisterstatuslistener)解注册该回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |
| void* userData | 应用自定义数据，注册状态监听后会在回调触发时通过listener的userData参数传回。 |
| void(\*listener)(ArkUI_DragAndDropInfo\* dragAndDropInfo, void\* userData) | 状态监听回调。dragAndDropInfo为系统返回的拖拽状态对象指针，该指针会在回调执行完成后被销毁，应用不应再持有；userData为注册时传入的应用自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_GetDisplayId()

```c
ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDisplayId(ArkUI_DragEvent* event, int32_t* displayId)
```

**描述：**


获取当前拖拽事件发生时所在的屏幕ID，不支持当eventType为NODE_ON_DRAG_END时获取。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |
| int32_t* displayId | 返回当前拖拽事件发生时所在的屏幕ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragAction_UnregisterStatusListener()

```c
void OH_ArkUI_DragAction_UnregisterStatusListener(ArkUI_DragAction* dragAction)
```

**描述：**


解注册拖拽状态监听回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽行为对象。 |

### OH_ArkUI_DragAndDropInfo_GetDragStatus()

```c
ArkUI_DragStatus OH_ArkUI_DragAndDropInfo_GetDragStatus(ArkUI_DragAndDropInfo* dragAndDropInfo)
```

**描述：**


获取[ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)发起拖拽的状态，获取异常时返回 ArkUI_DRAG_STATUS_UNKNOWN。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAndDropInfo](capi-arkui-nativemodule-arkui-draganddropinfo.md)* dragAndDropInfo | 拖拽状态监听返回的拖拽相关信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_DragStatus](capi-drag-and-drop-h.md#arkui_dragstatus) | 拖拽状态，如果获取失败，返回默认值 ArkUI_DRAG_STATUS_UNKNOWN。 |

### OH_ArkUI_DragAndDropInfo_GetDragEvent()

```c
ArkUI_DragEvent* OH_ArkUI_DragAndDropInfo_GetDragEvent(ArkUI_DragAndDropInfo* dragAndDropInfo)
```

**描述：**


通过dragAndDropInfo获取到DragEvent，可通过DragEvent获取释放结果。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAndDropInfo](capi-arkui-nativemodule-arkui-draganddropinfo.md)* dragAndDropInfo | 拖拽状态监听返回的拖拽相关信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* | 拖拽事件对象，如果获取失败，则返回空。 |

### OH_ArkUI_StartDrag()

```c
int32_t OH_ArkUI_StartDrag(ArkUI_DragAction* dragAction)
```

**描述：**


通过构造的DragAction对象发起拖拽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragAction](capi-arkui-nativemodule-arkui-dragaction.md)* dragAction | 拖拽action对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_RequestDragEndPending()

```c
int32_t OH_ArkUI_DragEvent_RequestDragEndPending(ArkUI_DragEvent* event, int32_t* requestIdentify)
```

**描述：**


请求延迟处理拖拽结束事件，等待应用确认操作结果。应用需通过 [OH_ArkUI_NotifyDragResult](#oh_arkui_notifydragresult)接口将最终结果回传至系统，并在所有处理完成后调用 [OH_ArkUI_NotifyDragEndPendingDone](#oh_arkui_notifydragendpendingdone)。最大等待时间为2秒。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | 指向 <b>ArkUI_DragEvent</b> 对象的指针。 |
| int32_t* requestIdentify | 系统自动生成的请求标识符，是一个输出参数，需要为一个有效的地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  函数参数异常。<br>         [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  当前拖放事件处理阶段不允许执行请求的操作。 |

### OH_ArkUI_NotifyDragResult()

```c
int32_t OH_ArkUI_NotifyDragResult(int32_t requestIdentify, ArkUI_DragResult result)
```

**描述：**


通知系统最终拖拽结果。系统会校验请求标识符是否与[OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending)返回的一致，不一致则忽略本次调用。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t requestIdentify | 由 [OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending) 返回的标识符。 |
| [ArkUI_DragResult](capi-drag-and-drop-h.md#arkui_dragresult) result | 拖拽结果枚举值（[ArkUI_DragResult](capi-drag-and-drop-h.md#arkui_dragresult) 类型）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  函数参数异常。<br>         [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  当前拖放事件处理阶段不允许执行请求的操作。 |

### OH_ArkUI_NotifySuggestedDropOperation()

```c
int32_t OH_ArkUI_NotifySuggestedDropOperation(int32_t requestIdentity, ArkUI_DropOperation operation)
```

**描述：**


通知拖拽发起方本次落入的行为类型，该函数需在落入阶段调用。拖拽发起方可以在拖拽结束的回调中调用[OH_ArkUI_DragEvent_GetDropOperation](#oh_arkui_dragevent_getdropoperation)获取本次落入的行为类型，进行自定义处理。也可以选择忽略该通知，不进行处理。拖拽失败时，本次落入的行为类型不可信，此时调用[OH_ArkUI_DragEvent_GetDropOperation](#oh_arkui_dragevent_getdropoperation)获取到的行为类型恒为ARKUI_DROP_OPERATION_COPY。系统会校验requestIdentity是否与[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)返回的一致，不一致则本次调用不生效。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t requestIdentity | 由[OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending)返回的标识符，用来标识本次拖拽事件。 |
| [ArkUI_DropOperation](capi-drag-and-drop-h.md#arkui_dropoperation) operation | 落入行为类型[ArkUI_DropOperation](capi-drag-and-drop-h.md#arkui_dropoperation)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数未在落入阶段调用。 |

### OH_ArkUI_NotifyDisableDefaultDropAnimation()

```c
int32_t OH_ArkUI_NotifyDisableDefaultDropAnimation(int32_t requestIdentity, bool disable)
```

**描述：**


通知系统是否禁用默认的落入动画，该函数需在落入阶段调用。拖拽失败时，默认的落入动画为扩散动画，拖拽成功时默认的落入动画为收缩淡出动画。调用此方法可禁用默认动画，根据需要实现自定义落入动画。系统会校验requestIdentity是否与[OH_ArkUI_DragEvent_RequestDragEndPending](#oh_arkui_dragevent_requestdragendpending)返回的一致，不一致则本次调用不生效。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t requestIdentity | 由[OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending)返回的标识符，用来标识本次拖拽事件。 |
| bool disable | 通知是否禁用系统默认落入动画。true表示禁用系统默认落入动画，false表示使用系统默认落入动画。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数未在落入阶段调用。 |

### OH_ArkUI_NotifyDragEndPendingDone()

```c
int32_t OH_ArkUI_NotifyDragEndPendingDone(int32_t requestIdentify)
```

**描述：**


通知系统所有异步处理已完成，可结束拖拽结束挂起状态。系统会校验requestIdentify是否与[OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending)返回的标识符一致，不一致或当前不在落入阶段时，则本次调用不生效。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t requestIdentify | 由 [OH_ArkUI_DragEvent_RequestDragEndPending](capi-drag-and-drop-h.md#oh_arkui_dragevent_requestdragendpending) 返回的标识符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  函数参数异常。<br>         [ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)  当前拖放事件处理阶段不允许执行请求的操作。 |

### OH_ArkUI_EnableDropDisallowedBadge()

```c
ArkUI_ErrorCode OH_ArkUI_EnableDropDisallowedBadge(ArkUI_ContextHandle uiContext, bool enabled)
```

**描述：**


设置是否可以显示禁用角标，适用于拖拽到不允许落入或不支持接收当前数据类型的目标区域时，需要通过禁用角标提示用户的场景。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI实例对象指针。 |
| bool enabled | 是否可以显示禁用角标。true表示可以显示禁用角标，false表示不可以显示禁用角标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_GetTouchPointXToGlobalDisplay()

```c
float OH_ArkUI_DragEvent_GetTouchPointXToGlobalDisplay(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取跟手点相对于全局屏幕的x轴坐标。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手点相对于全局屏幕的x轴坐标，单位为px，传入参数无效时返回默认值0。 |

### OH_ArkUI_DragEvent_GetTouchPointYToGlobalDisplay()

```c
float OH_ArkUI_DragEvent_GetTouchPointYToGlobalDisplay(ArkUI_DragEvent* event)
```

**描述：**


从ArkUI_DragEvent中获取跟手点相对于全局屏幕的y轴坐标。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | ArkUI_DragEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回拖拽跟手点相对于全局屏幕的y轴坐标，单位为px，传入参数无效时返回默认值0。 |

### OH_ArkUI_DragEvent_GetDragSource()

```c
ArkUI_ErrorCode OH_ArkUI_DragEvent_GetDragSource(ArkUI_DragEvent* event, char *bundleName, int32_t length)
```

**描述：**


获取拖拽发起方的应用包名信息，可用于识别拖拽来源应用、按来源进行校验或执行差异化处理；调用时需要传递一个字符数组来接收包名字符串，并显式指明数组长度，该数组长度不小于128个字符。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | 指向<b>ArkUI_DragEvent</b>对象的指针。 |
| char *bundleName | 用来接收拖起方包名的字符串数组，长度不应小于128个字符。 |
| int32_t length | 用来显式指明传入的字符串数组长度，不应小于128个字符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DragEvent_IsRemote()

```c
ArkUI_ErrorCode OH_ArkUI_DragEvent_IsRemote(ArkUI_DragEvent* event, bool* isRemote)
```

**描述：**


判断当前的拖拽操作是否是跨设备拖拽，适用于需要区分本地拖拽和跨设备拖拽的场景。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DragEvent](capi-arkui-nativemodule-arkui-dragevent.md)* event | 指向<b>ArkUI_DragEvent</b>对象的指针。 |
| bool* isRemote | 布尔变量指针，用来接收是否是跨设备拖拽。true表示是跨设备拖拽，false表示非跨设备拖拽。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

