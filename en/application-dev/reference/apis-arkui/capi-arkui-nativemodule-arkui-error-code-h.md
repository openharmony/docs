# error_code.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=c8d89821f92b220ca7659a1de29fb1e3b0412c5b translatedAt=2026-08-12T07:59:04.864Z pushedAt=2026-08-13T02:01:02.968Z -->

## Overview

Enumerates error codes of ArkUI native APIs, which are used to indicate the results or failure causes of API calls.

**File to include:** <arkui/error_code.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_ErrorCode](#arkui_errorcode) | ArkUI_ErrorCode | Enumerates error codes of ArkUI native APIs, which are used to indicate the results or failure causes of API calls. |

## Enum Description

### ArkUI_ErrorCode

```c
enum ArkUI_ErrorCode
```

**Description**

Enumerates error codes of ArkUI native APIs, which are used to indicate the results or failure causes of API calls.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_ERROR_CODE_NO_ERROR = 0 | No error.<br>**Since:** 12 |
| ARKUI_ERROR_CODE_PARAM_INVALID = 401 | Parameter error. <br>**Since:** 12 |
| ARKUI_ERROR_CODE_CAPI_INIT_ERROR = 500 |  API initialization error.<br>**Since:** 18 |
| ARKUI_ERROR_CODE_INTERNAL_ERROR = 100001 | Internal error, such as API call failure due to abnormal running environment or operation failure caused by API internal execution errors.<br>**Since:** 15 |
| ARKUI_ERROR_CODE_PARAM_ERROR = 100023 |  Parameter error. For details about the error code, see [100023 Parameter Error](errorcode-node.md#100023-parameter-error).<br>**Since:** 21 |
| ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID = 103501 |  The **XComponent** is in an invalid or unsupported state. For details about the error code, see [XComponent Error Codes](errorcode-xcomponent.md).<br>**Since:** 18 |
| ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102 | The component does not support specific attributes or events. For details about the error code, see [Interaction Event Error Codes](errorcode-event.md).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED = 106103 | The corresponding operations cannot be performed on the node created by ArkTS. For details about the error code, see [106103 Operation Not Allowed on Nodes Created by ArkTS](errorcode-node.md#106103-operation-not-allowed-on-nodes-created-by-arkts).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_ADAPTER_NOT_BOUND = 106104 | The adapter for lazy loading is not bound to the component. For details about the error code, see [106104 Adapter Not Bound](errorcode-nodeadapter.md#106104-adapter-not-bound).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_ADAPTER_EXIST = 106105 | The adapter already exists. For details about the error code, see [106105 Adapter Already Exists](errorcode-nodeadapter.md#106105-adapter-already-exists).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_CHILD_NODE_EXIST = 106106 | Failed to add the adapter because the corresponding node already has a child node. For details about the error code, see [106106 Child Node Exists](errorcode-nodeadapter.md#106106-child-node-exists).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107 | The index parameter in the component event exceeds the array length limit. For details about the error code, see [106107 Parameter Index Out of Range in the Component Event](errorcode-nodeadapter.md#106107-parameter-index-out-of-range-in-the-component-event).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108 | The data requested by the caller does not exist in the component event. For details about the error code, see [106108 Data Requested by the Caller Does Not Exist in the Component Event](errorcode-nodeadapter.md#106108-data-requested-by-the-caller-does-not-exist-in-the-component-event).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109 | The component event does not support return values. For details about the error code, see [106109 Return Value Not Supported](errorcode-nodeadapter.md#106109-return-value-not-supported).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_NODE_UNSUPPORTED_EVENT_TYPE = 106110 | This event type is not supported. For details about the error code, see [106110 Unsupported Event Type](errorcode-nodeadapter.md#106110-unsupported-event-type).<br>**Since:** 21 |
| ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200 | Invalid index.<br>For details about the error code, see [106200 Invalid Index Value](errorcode-router.md#106200-invalid-index-value).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201 | Failed to obtain the route navigation information.<br>For details about the error code, see [106201 Failed to Obtain Route Navigation Information](errorcode-router.md#106201-failed-to-obtain-route-navigation-information).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202 | The buffer size passed is insufficient to accommodate the target data.<br/>For details about the error code, see [106202 Buffer Size Not Sufficient to Hold the Target Data](errorcode-router.md#106202-buffer-size-not-sufficient-to-hold-the-target-data).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE = 106203 |  The passed node is not mounted to the component tree. For details about the error code, see [106203 Passed Node Not Mounted to Component Tree](errorcode-node.md#106203-passed-node-not-mounted-to-component-tree).<br>**Since:** 15 |
| ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD = 106204 |  Operations on the provided node are not supported on non-UI threads. For details about the error code, see [106204 Operations on the Provided Node Not Supported on Non-UI Threads](errorcode-node.md#106204-operations-on-the-provided-node-not-supported-on-non-ui-threads).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_FORCE_DARK_CONFIG_INVALID = 106205 |  The input parameter for the color inversion capability is incorrect. For details about the error code, see [106205 Color Inversion Capability Configuration Error](errorcode-force-dark.md#106205-color-inversion-capability-configuration-error).<br>**Since:** 20 |
| ARKUI_ERROR_CODE_NODE_IS_ADOPTED = 106206 |  The node has been accepted as an auxiliary node. For details about the error code, see [106206 The Node Has Been Accepted as an Auxiliary Node](errorcode-adopt.md#106206-the-node-has-been-accepted-as-an-auxiliary-node).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_NODE_HAS_PARENT = 106207 |  The accepted node already has a parent node. For details about the error code, see [106207 The Auxiliary Node to Accept Has a Parent Node](errorcode-adopt.md#106207-the-auxiliary-node-to-accept-has-a-parent-node).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_NODE_CAN_NOT_BE_ADOPTED = 106208 |  The node cannot be accepted as an auxiliary node. For details about the error code, see [106208 The Node Cannot Be Accepted as an Auxiliary Node](errorcode-adopt.md#106208-the-node-cannot-be-accepted-as-an-auxiliary-node).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_NODE_CAN_NOT_ADOPT_TO = 106209 |  The node cannot accept other nodes. For details about the error code, see [106209 The Node Cannot Accept Other Nodes](errorcode-adopt.md#106209-the-node-cannot-accept-other-nodes).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_NODE_IS_NOT_IN_ADOPTED_CHILDREN = 106210 |  The node is not an auxiliary node accepted by the target node. For details about the error code, see [106210 The Node Is Not an Affiliated Node Accepted by the Target Node](errorcode-adopt.md#106210-the-node-is-not-an-affiliated-node-accepted-by-the-target-node).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_NOT_CUSTOM_NODE = 106401 |  The current node is not a custom node. For details, see [Render Node Error Codes](errorcode-node-render.md).<br>**Since:** 20 |
| ARKUI_ERROR_CODE_CHILD_EXISTED = 106402 |  The current node already has child nodes. For details, see [Render Node Error Codes](errorcode-node-render.md).<br>**Since:** 20 |
| ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED = 106403 |  The current render node has a parent component. For details, see [Render Node Error Codes](errorcode-node-render.md).<br>**Since:** 20 |
| ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST = 106404 |  Corresponding render child node not found. For details, see [Render Node Error Codes](errorcode-node-render.md).<br>**Since:** 20 |
| ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE = 106405 |  The parameter value is out of range. For details, see [Render Node Error Codes](errorcode-node-render.md).<br>**Since:** 20 |
| ARKUI_ERROR_CODE_RENDER_IS_FROM_FRAME_NODE = 106406 |  The current render node is obtained from a [FrameNode](js-apis-arkui-frameNode.md). For details about the error code, see [106406 Current Render Node Is Obtained from FrameNode](errorcode-node-render.md#106406-current-render-node-is-obtained-from-framenode).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_RENDER_HAS_INVALID_FRAME_NODE = 106407 |  The current render node is obtained from a [FrameNode](js-apis-arkui-frameNode.md) and the [FrameNode](js-apis-arkui-frameNode.md) has not been adopted as an affiliated node or has been disposed of. For details about the error code, see [106407 Current Render Node Is Obtained from FrameNode and the FrameNode Is Disposed or No Longer Adopted](errorcode-node-render.md#106407-current-render-node-is-obtained-from-framenode-and-the-framenode-is-disposed-or-no-longer-adopted).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_RENDER_NOT_ADOPTED_NODE = 106408 |  The current node is not in the adopted state. For details about the error code, see [106408 Current Node Is Not in Adopted State](errorcode-node-render.md#106408-current-node-is-not-in-adopted-state).<br>**Since:** 22 |
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE = 150001 |  The current node is not focusable. For details about the error code, see [150001 Component Not Focusable](errorcode-focus.md#150001-component-not-focusable).<br>**Since:** 15 |
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR = 150002 |  An ancestor of the current node is not focusable. For details about the error code, see [150002 Ancestor Component Not Focusable](errorcode-focus.md#150002-ancestor-component-not-focusable).<br>**Since:** 15 |
| ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT = 150003 |  The current node does not exist. For details about the error code, see [150003 Component Does Not Exist](errorcode-focus.md#150003-component-does-not-exist).<br>**Since:** 15 |
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT = 160002 |  Snapshot timed out. For details, see [Snapshot Error Codes](errorcode-snapshot.md).<br>**Since:** 15 |
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_MODE_NOT_SUPPORTED = 160003 | The color space or dynamic range mode set in the screenshot options is not supported. For details about the error code, see [Snapshot Error Codes](errorcode-snapshot.md).<br>**Since:** 23 |
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_AUTO_NOT_SUPPORTED = 160004 | The **isAuto** parameter corresponding to the color space or dynamic range mode cannot be set to **true** for offscreen node screenshots. For details about the error code, see [Screenshot Error Codes](errorcode-snapshot.md).<br>**Since:** 23 |
| ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER = 180001 | The component is not a scrollable container. For details about the error code, see [Interaction Event Error Codes](errorcode-event.md).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH = 180002 | The buffer is not large enough. For details about the error code, see [Interaction Event Error Codes](errorcode-event.md).<br>**Since:** 12 |
| ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT = 180003 |  The event is not a cloned event. For details about the error code, see [Interaction Event Error Codes](errorcode-event.md).<br>**Since:** 15 |
| ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL = 180004 |  The component status is abnormal. For details about the error code, see [Interaction Event Error Codes](errorcode-event.md).<br>**Since:** 15 |
| ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT = 180005 |  No component hit to respond to the event. For details about the error code, see [Interaction Event Error Codes](errorcode-event.md).<br>**Since:** 15 |
| ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED = 180006 |  Input event type not supported.<br>**Since:** 20 |
| ARKUI_ERROR_CODE_INVALID_STYLED_STRING = 180101 |  Invalid styled string. For details, see [Styled String Error Codes](errorcode-styled-string.md).<br>**Since:** 14 |
| ARKUI_ERROR_CODE_UI_CONTEXT_INVALID = 190001 |  Invalid UIContext object. For details about the error code, see [UI Context Error Codes](errorcode-uicontext.md).<br>**Since:** 18 |
| ARKUI_ERROR_CODE_CALLBACK_INVALID = 190002 |  Invalid callback function. For details about the error code, see [UI Context Error Codes](errorcode-uicontext.md).<br>**Since:** 18 |
| ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED = 180102 |  The gesture recognizer type is not supported. For details about the error code, see [Interaction Event Error Codes](errorcode-event.md).<br>**Since:** 18 |
| ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED = 190004 | The requested operation is not allowed in the current drag and drop event processing phase. For details about the error code, see [Drag Event Error Codes](errorcode-drag-event.md).<br>**Since:** 19 |