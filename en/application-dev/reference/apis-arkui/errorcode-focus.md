# Focus Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 150001 Node Cannot Be Focused

**Error Message**

This component is not focusable.

**Description**

The current node cannot be focused.

**Possible Causes**

By default, a node cannot be focused. Developers cannot set a node to be focused by using attribute methods such as focusable.

**Solution**

NA

## 150002 The ancestor node cannot be focused.

**Error Message**

This component has unfocusable ancestor.

**Description**

Some ancestor nodes corresponding to the current node cannot be focused.

**Possible Causes**

By default, the ancestor node cannot be focused. Developers cannot set the ancestor node to be focused by using attribute methods such as focusable.

**Solution**

NA

## 150003 Node Does Not Exist

**Error Message**

The component doesn't exist, is currently invisible, or has been disabled.

**Description**

The input ID points to a node that does not exist, is not mounted to a tree, or is invisible.

**Possible Causes**

The input ID is incorrect, or the node has been destroyed.

**Solution**

NA
