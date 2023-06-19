# Upload and Download Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 13400001 File Operation Error

**Error Message**

File operation error.

**Description**

This error code is reported when a file operation error occurs in invoking the **uploadFile** or **downloadFile** API.

**Possible Causes**

The file permission is insufficient.

**Solution**

Make sure you have the required permission on the target files.

## 13400002 File Path Error

**Error Message**

Bad file path.

**Description**

This error code is reported when a file path error occurs in invoking the **uploadFile** or **downloadFile** API.

**Possible Causes**

The file path is incorrect or the file aready exists in the path.

**Solution**

Verify the file path.

## 13400003 Service Error

**Error Message**

Task manager service error.

**Description**

This error code is reported when a task manager service error occurs in invoking the **downloadFile** API.

**Possible Causes**

The task fails to be created.

**Solution**

Verify the task settings.
