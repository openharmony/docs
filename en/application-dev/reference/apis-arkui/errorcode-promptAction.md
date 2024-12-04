# promptAction Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 100001 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported when an internal error that cannot be rectified by developers occurs. The internal error type is included in the error information.

**Possible Causes**

The operation for obtaining the rendering engine or parsing parameters fails.

**Solution**

N/A

## 103301 Dialog Content Error

**Error Message**

Dialog content error.

**Description**

This error code is reported when there is an issue with the content node of the custom dialog box, which prevents the node from being rendered.

**Possible Causes**

The custom component node passed to the dialog box is empty or incorrect.

**Solution**

N/A

## 103302 Custom Dialog Box Already Exists

**Error Message**

Dialog content already exists.

**Description**

This error code is reported when an attempt is made to open a custom dialog box that is already open.

**Possible Causes**

The custom dialog box associated with the content node is currently displayed.

**Solution**

N/A

## 103303 Custom Dialog Box Not Found

**Error Message**

Dialog content not found.

**Description**

This error code is reported when an attempt is made to close or update a custom dialog box that is not open.

**Possible Causes**

The custom dialog box associated with the content node is not open.

**Solution**

N/A
