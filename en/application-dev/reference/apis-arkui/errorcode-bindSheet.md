# Sheet Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 120001 Incorrect bindSheetContent

**Error Message**

The bindSheetContent is incorrect.

**Description**

This error code is reported when the provided **bindSheetContent** is incorrect.

**Possible Causes**

The configuration for **bindSheetContent** is incorrect.

**Solution**

Verify the **bindSheetContent** configuration.

## 120002 Modal for bindSheetContent Already Exists

**Error Message**

The bindSheetContent already exists.

**Description**

This error code is reported when an attempt is made to open a modal that is already displayed.

**Possible Causes**

The modal corresponding to the provided **bindSheetContent** is already displayed.

**Solution**

Verify the **bindSheetContent** configuration.

## 120003 No Matching Modal Found

**Error Message**

The bindSheetContent cannot be found.

**Description**

This error code is reported when an API is called to close or update the modal that is not currently open.

**Possible Causes**

The modal corresponding to the provided **bindSheetContent** is not currently displayed. 

**Solution**

Verify the **bindSheetContent** configuration.

## 120004 Specified targetId Does Not Exist

**Error Message**

The targetId does not exist.

**Description**

This error code is reported when no node could be found based on **targetId**.

**Possible Causes**

The **targetId** is invalid, or the corresponding node has been destroyed.

**Solution**

1. Make sure the value of **targetId** is not a negative number.
2. Verify that the node corresponding to the **targetId** is valid.

## 120005 Node Specified by targetId Is Not in the Component Tree

**Error Message**

The node of targetId is not in the component tree.

**Description**

This error code is reported when the node corresponding to the specified **targetId** is not in the component tree during an attempt to use the modal in EMBEDDED mode.

**Possible Causes**

The node corresponding to the specified **targetId** is not yet part of the component tree.

**Solution**

Wait for the node corresponding to the **targetId** to be attached to the component tree before calling the API again; or consider setting the modal to OVERLAY mode.

## 120006 Node Specified by targetId Is Not a Child of a Page Node or NavDestination Node

**Error Message**

The node of targetId is not a child of the page node or NavDestination node.

**Description**

This error code is reported when the node corresponding to the specified **targetId** is not a child of a page node or **NavDestination** node during an attempt to use the modal in EMBEDDED mode.

**Possible Causes**

The **targetId** does not correspond to a node that is a child of a page or **NavDestination** node.

**Solution**

Select a different **targetId** that is a child of a page or **NavDestination** node; or use the OVERLAY mode for the modal.
