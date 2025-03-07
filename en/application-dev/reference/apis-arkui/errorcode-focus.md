# Focus Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 150001 Component Not Focusable

**Error Message**

This component is not focusable.

**Description**

This error code is reported when the current component is not focusable.

**Possible Causes**

The component is not focusable by default or has been set to not focusable through attribute methods such as **focusable**.

**Solution**

N/A

## 150002 Ancestor Component Not Focusable

**Error Message**

This component has an unfocusable ancestor.

**Description**

This error code is reported when an ancestor of the current component is not focusable.

**Possible Causes**

The ancestor component is not focusable by default or has been set to not focusable through attribute methods such as **focusable**.

**Solution**

N/A

## 150003 Component Doesn't Exist

**Error Message**

The component doesn't exist, is currently invisible, or has been disabled.

**Description**

This error code is reported when the provided ID points to a non-existent, detached, or invisible component.

**Possible Causes**

The provided ID is incorrect, or the component has been destroyed.

**Solution**

N/A
