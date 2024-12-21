# drag_and_drop.h


## 概述

提供NativeDrag相关接口定义。

**库：** libace_ndk.z.so

**引用文件：** <arkui/drag_and_drop.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) [ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) | 组件事件的通用结构类型。  | 
| typedef struct [ArkUI_Context](_ark_u_i___native_module.md#arkui_context) [ArkUI_Context](_ark_u_i___native_module.md#arkui_context) | native UI的上下文实例对象。  | 
| typedef struct [ArkUI_Context](_ark_u_i___native_module.md#arkui_context) \* [ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) | native UI的上下文实例对象指针定义。  | 
| typedef struct [ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) [ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) | 拖拽事件。 | 
| typedef struct [ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) [ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) | 设置拖拽跟手图的相关自定义参数。  | 
| typedef struct [ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) [ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) | 拖拽行为，用于主动发起拖拽。  | 
| typedef struct [ArkUI_DragAndDropInfo](_ark_u_i___native_module.md#arkui_draganddropinfo) [ArkUI_DragAndDropInfo](_ark_u_i___native_module.md#arkui_draganddropinfo) | 主动发起拖拽后，通过拖拽状态监听返回的系统拖拽相关数据。  | 
| typedef struct [OH_UdmfData](_ark_u_i___native_module.md#oh_udmfdata) [OH_UdmfData](_ark_u_i___native_module.md#oh_udmfdata) | UDMF 统一数据定义。  | 
| typedef struct [OH_PixelmapNative](_ark_u_i___native_module.md#oh_pixelmapnative) [OH_PixelmapNative](_ark_u_i___native_module.md#oh_pixelmapnative) | Pixelmap结构体类型，用于执行Pixelmap相关操作。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_DragResult](_ark_u_i___native_module.md#arkui_dragresult) { [ARKUI_DRAG_RESULT_SUCCESSFUL](_ark_u_i___native_module.md), [ARKUI_DRAG_RESULT_FAILED](_ark_u_i___native_module.md), [ARKUI_DRAG_RESULT_CANCELED](_ark_u_i___native_module.md) } | 拖拽结果定义，由数据接收方设置，并由系统传递给数据拖出方，拖出方可感知接收方对数据的处理结果。  | 
| [ArkUI_DropProposal](_ark_u_i___native_module.md#arkui_dropproposal) { [ARKUI_DROP_PROPOSAL_COPY](_ark_u_i___native_module.md), [ARKUI_DROP_PROPOSAL_MOVE](_ark_u_i___native_module.md) } | 定义拖拽释放时的数据处理方式，可影响角标的显示。  | 
| [ArkUI_PreDragStatus](_ark_u_i___native_module.md#arkui_predragstatus) {<br/>[ARKUI_PRE_DRAG_STATUS_UNKNOWN](_ark_u_i___native_module.md) = -1, [ARKUI_PRE_DRAG_STATUS_ACTION_DETECTING](_ark_u_i___native_module.md), [ARKUI_PRE_DRAG_STATUS_READY_TO_TRIGGER_DRAG](_ark_u_i___native_module.md), [ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_STARTED](_ark_u_i___native_module.md),<br/>[ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_FINISHED](_ark_u_i___native_module.md), [ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_STARTED](_ark_u_i___native_module.md), [ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_FINISHED](_ark_u_i___native_module.md), [ARKUI_PRE_DRAG_STATUS_CANCELED_BEFORE_DRAG](_ark_u_i___native_module.md)<br/>} | 定义拖拽发起前的长按交互阶段的变化状态。  | 
| [ArkUI_DragPreviewScaleMode](_ark_u_i___native_module.md#arkui_dragpreviewscalemode) { [ARKUI_DRAG_PREVIEW_SCALE_AUTO](_ark_u_i___native_module.md), [ARKUI_DRAG_PREVIEW_SCALE_DISABLED](_ark_u_i___native_module.md) } | 拖拽预览缩放模式。  | 
| [ArkUI_DragStatus](_ark_u_i___native_module.md#arkui_dragstatus) { [ArkUI_DRAG_STATUS_UNKNOWN](_ark_u_i___native_module.md), [ArkUI_DRAG_STATUS_STARTED](_ark_u_i___native_module.md), [ArkUI_DRAG_STATUS_ENDED](_ark_u_i___native_module.md) } | 拖拽状态  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \* [OH_ArkUI_NodeEvent_GetDragEvent](_ark_u_i___native_module.md#oh_arkui_nodeevent_getdragevent) ([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*nodeEvent) | 从 NodeEvent 中获取DragEvent。  | 
| [ArkUI_PreDragStatus](_ark_u_i___native_module.md#arkui_predragstatus) [OH_ArkUI_NodeEvent_GetPreDragStatus](_ark_u_i___native_module.md#oh_arkui_nodeevent_getpredragstatus) ([ArkUI_NodeEvent](_ark_u_i___native_module.md#arkui_nodeevent-12) \*nodeEvent) | 获取预览拖拽事件状态。  | 
| int32_t [OH_ArkUI_DragEvent_DisableDefaultDropAnimation](_ark_u_i___native_module.md#oh_arkui_dragevent_disabledefaultdropanimation) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, bool disable) | 设置是否禁用松手时的系统默认动效，默认不禁用，通常在应用需要自定义落位动效时配置。  | 
| int32_t [OH_ArkUI_DragEvent_SetSuggestedDropOperation](_ark_u_i___native_module.md#oh_arkui_dragevent_setsuggesteddropoperation) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, [ArkUI_DropProposal](_ark_u_i___native_module.md#arkui_dropproposal) proposal) | 设置数据处理方式。  | 
| int32_t [OH_ArkUI_DragEvent_SetDragResult](_ark_u_i___native_module.md#oh_arkui_dragevent_setdragresult) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, [ArkUI_DragResult](_ark_u_i___native_module.md#arkui_dragresult) result) | 设置拖拽事件的结果。  | 
| int32_t [OH_ArkUI_DragEvent_SetData](_ark_u_i___native_module.md#oh_arkui_dragevent_setdata) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, [OH_UdmfData](_ark_u_i___native_module.md#oh_udmfdata) \*data) | 向ArkUI_DragEvent中设置拖拽数据。  | 
| int32_t [OH_ArkUI_DragEvent_GetUdmfData](_ark_u_i___native_module.md#oh_arkui_dragevent_getudmfdata) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, [OH_UdmfData](_ark_u_i___native_module.md#oh_udmfdata) \*data) | 从ArkUI_DragEvent中获取拖拽默认相关数据。  | 
| int32_t [OH_ArkUI_DragEvent_GetDataTypesCount](_ark_u_i___native_module.md#oh_arkui_dragevent_getdatatypescount) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, int32_t \*count) | 从ArkUI_DragEvent中获取所拖拽的数据类型种类个数。  | 
| int32_t [OH_ArkUI_DragEvent_GetDataTypes](_ark_u_i___native_module.md#oh_arkui_dragevent_getdatatypes) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, char \*\*result[], int32_t length) | 从ArkUI_DragEvent中获取拖拽数据的类型列表。  | 
| int32_t [OH_ArkUI_DragEvent_GetDragResult](_ark_u_i___native_module.md#oh_arkui_dragevent_getdragresult) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, [ArkUI_DragResult](_ark_u_i___native_module.md#arkui_dragresult) \*result) | 从ArkUI_DragEvent中获取拖拽结果。  | 
| float [OH_ArkUI_DragEvent_GetPreviewTouchPointX](_ark_u_i___native_module.md#oh_arkui_dragevent_getpreviewtouchpointx) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取预览图跟手点的x轴坐标。  | 
| float [OH_ArkUI_DragEvent_GetPreviewTouchPointY](_ark_u_i___native_module.md#oh_arkui_dragevent_getpreviewtouchpointy) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取预览图跟手点的y轴坐标。  | 
| float [OH_ArkUI_DragEvent_GetPreviewRectWidth](_ark_u_i___native_module.md#oh_arkui_dragevent_getpreviewrectwidth) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取预览图的宽。  | 
| float [OH_ArkUI_DragEvent_GetPreviewRectHeight](_ark_u_i___native_module.md#oh_arkui_dragevent_getpreviewrectheight) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取预览图的高。  | 
| float [OH_ArkUI_DragEvent_GetTouchPointXToWindow](_ark_u_i___native_module.md#oh_arkui_dragevent_gettouchpointxtowindow) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取跟手点相对于window的x轴坐标。  | 
| float [OH_ArkUI_DragEvent_GetTouchPointYToWindow](_ark_u_i___native_module.md#oh_arkui_dragevent_gettouchpointytowindow) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取跟手点相对于window的y轴坐标。  | 
| float [OH_ArkUI_DragEvent_GetTouchPointXToDisplay](_ark_u_i___native_module.md#oh_arkui_dragevent_gettouchpointxtodisplay) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取跟手点相对于当前Display的x轴坐标。  | 
| float [OH_ArkUI_DragEvent_GetTouchPointYToDisplay](_ark_u_i___native_module.md#oh_arkui_dragevent_gettouchpointytodisplay) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 从ArkUI_DragEvent中获取跟手点相对于当前Display的y轴坐标。  | 
| float [OH_ArkUI_DragEvent_GetVelocityX](_ark_u_i___native_module.md#oh_arkui_dragevent_getvelocityx) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 获取当前拖拽的x轴方向拖动速度。  | 
| float [OH_ArkUI_DragEvent_GetVelocityY](_ark_u_i___native_module.md#oh_arkui_dragevent_getvelocityy) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 获取当前拖拽的y轴方向拖动速度。  | 
| float [OH_ArkUI_DragEvent_GetVelocity](_ark_u_i___native_module.md#oh_arkui_dragevent_getvelocity) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event) | 获取当前拖拽的主方向拖动速度。  | 
| int32_t [OH_ArkUI_DragEvent_GetModifierKeyStates](_ark_u_i___native_module.md#oh_arkui_dragevent_getmodifierkeystates) ([ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \*event, int64_t \*keys) | 获取功能键按压状态。  | 
| int32_t [OH_ArkUI_SetDragEventStrictReportWithNode](_ark_u_i___native_module.md#oh_arkui_setdrageventstrictreportwithnode) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool enabled) | 控制是否使能严格dragEvent上报，建议开启；默认是不开启的； 当不开启时，从父组件拖移进子组件时，父组件并不会收到leave的通知；而开启之后，只要前后两个组件发生变化，上一个组件就会收到 leave，新的组件收到enter通知；该配置与具体的UI实例相关，需要通过传入一个当前UI实例上的一个具体的组件节点来关联。  | 
| int32_t [OH_ArkUI_SetDragEventStrictReportWithContext](_ark_u_i___native_module.md#oh_arkui_setdrageventstrictreportwithcontext) ([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext, bool enabled) | 控制是否使能严格dragEvent上报，建议开启；默认是不开启的; 当不开启时，从父组件拖移进子组件时，父组件并不会收到leave的通知；而开启之后，只要前后两个组件发生变化，上一个组件就会收到 leave，新的组件收到enter通知；该配置与具体的UI实例相关，可通过传入一个UI实例进行关联。  | 
| int32_t [OH_ArkUI_SetNodeAllowedDropDataTypes](_ark_u_i___native_module.md#oh_arkui_setnodealloweddropdatatypes) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, const char \*typesArray[], int32_t count) | 配置组件允许接受落入的数据类型，该接口会重置通过 [OH_ArkUI_DisallowNodeAnyDropDataTypes](_ark_u_i___native_module.md#oh_arkui_disallownodeanydropdatatypes) 或 [OH_ArkUI_AllowNodeAllDropDataTypes](_ark_u_i___native_module.md#oh_arkui_allownodealldropdatatypes)进行的配置。  | 
| int32_t [OH_ArkUI_DisallowNodeAnyDropDataTypes](_ark_u_i___native_module.md#oh_arkui_disallownodeanydropdatatypes) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 配置组件不允许接受任何数据类型，该接口会重置通过[OH_ArkUI_SetNodeAllowedDropDataTypes](_ark_u_i___native_module.md#oh_arkui_setnodealloweddropdatatypes)配置的数据类型。  | 
| int32_t [OH_ArkUI_AllowNodeAllDropDataTypes](_ark_u_i___native_module.md#oh_arkui_allownodealldropdatatypes) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 配置组件允许接受任意数据类型，该接口会重置通过[OH_ArkUI_SetNodeAllowedDropDataTypes](_ark_u_i___native_module.md#oh_arkui_setnodealloweddropdatatypes)配置的数据类型。  | 
| int32_t [OH_ArkUI_SetNodeDraggable](_ark_u_i___native_module.md#oh_arkui_setnodedraggable) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool enabled) | 设置该组件是否允许进行拖拽。  | 
| int32_t [OH_ArkUI_SetNodeDragPreview](_ark_u_i___native_module.md#oh_arkui_setnodedragpreview) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [OH_PixelmapNative](_ark_u_i___native_module.md#oh_pixelmapnative) \*preview) | 设置组件在被拖拽时的自定义跟手图。  | 
| [ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \* [OH_ArkUI_CreateDragPreviewOption](_ark_u_i___native_module.md#oh_arkui_createdragpreviewoption) (void) | 构建一个ArkUI_DragPreviewOption对象。  | 
| void [OH_ArkUI_DragPreviewOption_Dispose](_ark_u_i___native_module.md#oh_arkui_dragpreviewoption_dispose) ([ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option) | 销毁跟手图自定义参数对象实例。  | 
| int32_t [OH_ArkUI_DragPreviewOption_SetScaleMode](_ark_u_i___native_module.md#oh_arkui_dragpreviewoption_setscalemode) ([ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option, [ArkUI_DragPreviewScaleMode](_ark_u_i___native_module.md#arkui_dragpreviewscalemode) scaleMode) | 设置拖拽跟手图是否根据系统定义自动进行缩放。  | 
| int32_t [OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled](_ark_u_i___native_module.md#oh_arkui_dragpreviewoption_setdefaultshadowenabled) ([ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option, bool enabled) | 设置跟手图背板默认的投影效果，默认使能。  | 
| int32_t [OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled](_ark_u_i___native_module.md#oh_arkui_dragpreviewoption_setdefaultradiusenabled) ([ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option, bool enabled) | 设置跟手图背板默认的圆角效果，默认使能。  | 
| int32_t [OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled](_ark_u_i___native_module.md#oh_arkui_dragpreviewoption_setnumberbadgeenabled) ([ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option, bool enabled) | 设置跟手图背板是否显示角标,默认使能,开启后,系统会根据拖拽数量自动进行角标显示。  | 
| int32_t [OH_ArkUI_DragPreviewOption_SetBadgeNumber](_ark_u_i___native_module.md#oh_arkui_dragpreviewoption_setbadgenumber) ([ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option, uint32_t forcedNumber) | 强制显示角标的数量,覆盖SetDragPreviewNumberBadgeEnabled设置的值。  | 
| int32_t [OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled](_ark_u_i___native_module.md#oh_arkui_dragpreviewoption_setdefaultanimationbeforeliftingenabled) ([ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option, bool enabled) | 配置是否开启点按时的默认动画。  | 
| int32_t [OH_ArkUI_SetNodeDragPreviewOption](_ark_u_i___native_module.md#oh_arkui_setnodedragpreviewoption) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option) | 将构造的ArkUI_DragPreviewOption设置给组件。  | 
| [ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \* [OH_ArkUI_CreateDragActionWithNode](_ark_u_i___native_module.md#oh_arkui_createdragactionwithnode) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 创建一个拖拽操作对象，该对象需与一个UI实例相关联，可通过传入一个当前UI实例的某个组件节点来指定。  | 
| [ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \* [OH_ArkUI_CreateDragActionWithContext](_ark_u_i___native_module.md#oh_arkui_createdragactionwithcontext) ([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext) | 创建一个拖拽操作对象，该对象需与一个UI实例相关联，可通过传入一个UI实例指针来关联。  | 
| void [OH_ArkUI_DragAction_Dispose](_ark_u_i___native_module.md#oh_arkui_dragaction_dispose) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction) | 销毁创建的 ArkUI_DragAction 对象。  | 
| int32_t [OH_ArkUI_DragAction_SetPointerId](_ark_u_i___native_module.md#oh_arkui_dragaction_setpointerid) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction, int32_t pointer) | 设置手指ID，当屏幕上仅有一只手指在操作时，pointer ID 为 0；一般情况下，配置 0 即可。  | 
| int32_t [OH_ArkUI_DragAction_SetPixelMaps](_ark_u_i___native_module.md#oh_arkui_dragaction_setpixelmaps) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction, [OH_PixelmapNative](_ark_u_i___native_module.md#oh_pixelmapnative) \*pixelmapArray[], int32_t size) | 设置拖拽跟手图，只能使用 pixelmap 格式对象。  | 
| int32_t [OH_ArkUI_DragAction_SetTouchPointX](_ark_u_i___native_module.md#oh_arkui_dragaction_settouchpointx) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction, float x) | 设置跟手点,相对于设置的第一个pixelmap的左上角。  | 
| int32_t [OH_ArkUI_DragAction_SetTouchPointY](_ark_u_i___native_module.md#oh_arkui_dragaction_settouchpointy) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction, float y) | 设置跟手点,相对于设置的第一个pixelmap的左上角。  | 
| int32_t [OH_ArkUI_DragAction_SetData](_ark_u_i___native_module.md#oh_arkui_dragaction_setdata) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction, [OH_UdmfData](_ark_u_i___native_module.md#oh_udmfdata) \*data) | 设置拖拽数据。  | 
| int32_t [OH_ArkUI_DragAction_SetDragPreviewOption](_ark_u_i___native_module.md#oh_arkui_dragaction_setdragpreviewoption) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction, [ArkUI_DragPreviewOption](_ark_u_i___native_module.md#arkui_dragpreviewoption) \*option) | 将构造的ArkUI_DragPreviewOption设置给ArkUI_DragAction。  | 
| int32_t [OH_ArkUI_DragAction_RegisterStatusListener](_ark_u_i___native_module.md#oh_arkui_dragaction_registerstatuslistener) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction, void \*userData, void(\*listener)([ArkUI_DragAndDropInfo](_ark_u_i___native_module.md#arkui_draganddropinfo) \*dragAndDropInfo, void \*userData)) | 注册拖拽状态监听回调,该回调可感知到拖拽已经发起或用户松手结束的状态, 可通过该监听获取到落入方对数据的接收处理是否成功。  | 
| void [OH_ArkUI_DragAction_UnregisterStatusListener](_ark_u_i___native_module.md#oh_arkui_dragaction_unregisterstatuslistener) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction) | 解注册拖拽状态监听回调。 | 
| [ArkUI_DragStatus](_ark_u_i___native_module.md#arkui_dragstatus) [OH_ArkUI_DragAndDropInfo_GetDragStatus](_ark_u_i___native_module.md#oh_arkui_draganddropinfo_getdragstatus) ([ArkUI_DragAndDropInfo](_ark_u_i___native_module.md#arkui_draganddropinfo) \*dragAndDropInfo) | 获取dragaction发起拖拽的状态,获取异常时返回 ArkUI_DRAG_STATUS_UNKNOWN。  | 
| [ArkUI_DragEvent](_ark_u_i___native_module.md#arkui_dragevent) \* [OH_ArkUI_DragAndDropInfo_GetDragEvent](_ark_u_i___native_module.md#oh_arkui_draganddropinfo_getdragevent) ([ArkUI_DragAndDropInfo](_ark_u_i___native_module.md#arkui_draganddropinfo) \*dragAndDropInfo) | 通过dragAndDropInfo获取到DragEvent，可通过DragEvent获取释放结果等。  | 
| int32_t [OH_ArkUI_StartDrag](_ark_u_i___native_module.md#oh_arkui_startdrag) ([ArkUI_DragAction](_ark_u_i___native_module.md#arkui_dragaction) \*dragAction) | 通过构造的DragAction对象发起拖拽。  | 
