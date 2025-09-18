# NodeAdapter Error Codes
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @kangshihui-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 106104 Adapter Not Bound

**Error Message**

The lazy loading adapter is not bound to the component.

**Description**

This error code is reported when the NodeAdapter requires a listener to be added.

**Possible Causes**

The NodeAdapter has not been bound to a DataChangeListener.

**Solution**

Set a listener for the NodeAdapter.

## 106105 Adapter Already Exists

**Error Message**

The adapter already exists.

**Description**

This error code is reported when an attempt is made to create a duplicate NodeAdapter instance.

**Possible Causes**

The NodeAdapter already exists and does not support adding or removing child nodes.

**Solution**

Remove the existing NodeAdapter or perform child node operations elsewhere.

## 106106 Child Node Exists

**Error Message**

The corresponding node already has a child node and cannot add an adapter.

**Description**

This error code is reported when the component already has a child node.

**Possible Causes**

The component already has a child node, and the NodeAdapter cannot be applied to non-empty components.

**Solution**

Remove the existing child node or select a parent component for the NodeAdapter.

## 106107 Index Out of Range

**Error Message**

The parameter length in the parameter event exceeds the limit.

**Description**

This error code is reported when the **index** parameter in a component event exceeds the array length limit.

**Possible Causes**

The provided **index** parameter exceeds the length limit of the input array.

**Solution**

Make sure the index parameter does not exceed the length limit of the input array.

## 106108 Data Not Found

**Error Message**

The data does not exist.

**Description**

This error code is reported when the specified data does not exist in the component event.

**Possible Causes**

The data to access is not included in the event.

**Solution**

Verify that the target data exists in the current event.

## 106109 Return Value Not Supported

**Error Message**

The event has not return value.

**Description**

This error code is reported when an attempt is made to obtain a return value from a component event that does not support return values.

**Possible Causes**

The component event does not support return values.

**Solution**

Check whether the current event supports return values.

## 106110 Event Type Not Supported

**Error Message**

The event type is not supported.

**Description**

This error code is reported when an incorrect event type is passed during common event registration.

**Possible Causes**

The provided event type parameter is incorrect and not among the supported event types.

**Solution**

Check the specific value of the event type parameter passed to the function.