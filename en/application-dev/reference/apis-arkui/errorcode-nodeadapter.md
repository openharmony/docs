# NodeAdapter Error Codes

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiaxiaguang-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=c8d89821f92b220ca7659a1de29fb1e3b0412c5b translatedAt=2026-08-13T01:25:56.707Z pushedAt=2026-08-13T01:44:45.487Z -->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 106104 Adapter Not Bound

**Error Message**

The lazy loading adapter is not bound to the component.

**Description**

This error code is reported when no NodeAdapter is bound to the component.

**Possible Causes**

The component does not have a NodeAdapter set. The NodeAdapter must be bound to the component before node operations can be performed.

**Solution**

Set a NodeAdapter for the component.

## 106105 Adapter Already Exists

**Error Message**

The adapter already exists.

**Description**

This error code is reported when the NodeAdapter already exists.

**Possible Causes**

The NodeAdapter already exists and does not support adding or deleting child nodes.

**Solution**

Remove the NodeAdapter or perform child node adding or deletion elsewhere.

## 106106 Child Node Exists

**Error Message**

The corresponding node already has a child node and cannot add an adapter.

**Description**

This error code is reported when the component already has a child node.

**Possible Causes**

The component already has a child node, and the NodeAdapter cannot be set.

**Solution**

Remove the existing child node or set the NodeAdapter elsewhere.

## 106107 Parameter Index Out of Range in the Component Event

**Error Message**

The parameter index in the component event is out of range.

**Description**

This error code is reported when the **index** parameter in the component event is out of range.

**Possible Causes**

The **index** parameter passed exceeds the array length limit.

**Solution**

Make sure the index parameter does not exceed the length limit of the input array.

## 106108 Data Requested by the Caller Does Not Exist in the Component Event

**Error Message**

The data does not exist in the component event.

**Description**

This error code is reported when the data requested by the caller does not exist in the component event.

**Possible Causes**

The data to access is not included in the event.

**Solution**

Check whether the current event contains the data to be queried.

## 106109 Return Value Not Supported

**Error Message**

The component event does not support return values.

**Description**

This error code is reported when the component event does not support return values.

**Possible Causes**

An attempt is made to obtain a return value from the component event.

**Solution**

Remove the code related to obtaining the event return value.

## 106110 Unsupported Event Type

**Error Message**

The event type is not supported.

**Description**

This error code is reported when the event type passed when registering a universal event is not supported.

**Possible Causes**

The passed event type is not among the supported event types.

**Solution**

Check whether the event type value of the function input parameter falls within the range of supported event types.