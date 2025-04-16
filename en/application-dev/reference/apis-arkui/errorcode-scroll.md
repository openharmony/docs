# Scrollable Component Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 100004 Controller Not Bound to Component

**Error Message**

Controller not bound to component.

**Description**

This error code is reported when an API is called through a controller but no controller is bound to the component. The error code is a string.

**Possible Causes**

The API called requires a controller, but the component is not bound to one.
