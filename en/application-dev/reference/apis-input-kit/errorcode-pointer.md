# Mouse Pointer Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 26500001 Invalid Window ID

**Error Message**

Invalid windowId. Possible causes: The window id does not belong to the current process.

**Description**

This error code is reported if the window ID is invalid.

**Possible Causes**

The window ID does not belong to the current process.

**Solution**

Pass in the window ID of the current process. You can obtain the attributes of the current window by calling [getWindowProperties()](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9). The window ID is contained in the returned window attributes.
