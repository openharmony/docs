# NodeAdapter Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 106104 Adapter Not Bound

**Error Message**

A listener is required to add the NodeAdapter.

**Description**

This error code is reported when the NodeAdapter requires a listener to be added.

**Possible Causes**

The NodeAdapter has not been bound to a DataChangeListener.

**Solution**

Set a listener for the NodeAdapter.

## 106105 Adapter Already Exists

**Error Message**

The NodeAdapter already exists.

**Description**

This error code is reported when an attempt is made to create a duplicate NodeAdapter instance.

**Possible Causes**

The NodeAdapter already exists and does not support adding or removing child nodes.

**Solution**

Remove the existing NodeAdapter or perform child node operations elsewhere.

## 106106 Child Node Exists

**Error Message**

This component already has a child node.

**Description**

This error code is reported when the component already has a child node.

**Possible Causes**

The component already has a child node, and the NodeAdapter cannot be applied to non-empty components.

**Solution**

Remove the existing child node or select a parent component for the NodeAdapter.
