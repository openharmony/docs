# Custom Node Error Codes
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangchensu1-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 100021 FrameNode Not Modifiable

**Error Message**

The FrameNode is not modifiable.

**Description**

This error code is reported when the current FrameNode is unmodifiable, preventing the requested operation, for example, setting properties, adding or removing child nodes, or binding controllers.

**Possible Causes**

An attempt is made to modify a declarative node.

**Solution**

Avoid modifying unmodifiable nodes. Use try-catch to handle errors and prevent impact on other logic.

## 100022 Cross-Language Attribute Configuration Not Supported

**Error Message**

The FrameNode cannot be set whether to support cross-language common attribute setting.

**Description**

This error code is reported when the target FrameNode does not support cross-language attribute configuration.

**Possible Causes**

An attempt is made to adjust the cross-language attribute permission of the target FrameNode.

**Solution**

NA

## 100023 Parameter Error

**Error Message**

Parameter error. Possible causes: 1. The component type of the node is incorrect. 2. The node is null or undefined. 3. The controller is null or undefined.

**Description**

This error code is reported when the parameters passed to the API are incorrect.

**Possible Causes**

1. The component type of the provided node is incorrect.
2. The provided node is null or undefined.
3. The provided controller is null or undefined.

**Solution**

Adjust the passed parameter values or perform pre-checks.

## 106103 Operation Not Allowed on Nodes Created by ArkTS

**Error Message**

The corresponding operation does not support nodes created by ArkTS.

**Description**

This error code is reported when the operation does not support nodes created by ArkTS.

**Possible Causes**

The current operation is incompatible with nodes created by ArkTS.

**Solution**

Pass nodes not created by ArkTS.

## 106203 Passed Node Not Mounted to Component Tree

**Error Message**

**Description**

This error code is reported when the passed node is not mounted to the component tree.

**Possible Causes**

The passed node is not mounted to the component tree when the API is called.

**Solution**

Adjust the API call timing to ensure the node is mounted to the component tree.

## 106204 Operations on the Provided Node Not Supported on Non-UI Threads

**Error Message**

Operation on passed in nodes in non UI threads is not supported.

**Description**

This error code is reported when an attempt is made to manipulate nodes on a non-UI thread.

**Possible Causes**

1. The API can be called only on the UI thread.
2. The API supports multi-threaded calls, but the passed node has already been mounted to the main UI tree.
3. The API supports multi-threaded calls, but the passed node is not created using the thread-safe [createNode](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API.

**Solution**

1. Adjust the API call timing to ensure the API is called from the UI thread.
2. Unmount the passed node from the main UI tree before calling the API.
3. Use the thread-safe [createNode](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API to create nodes before calling this API.
