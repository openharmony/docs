# HiCollie Error Codes

> **Note:**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 29800001 Failed to Obtain the System Service

**Error Message**

Wrong thread context.The function can not be called from main thread.

**Description**
The API fails to be called from the thread.

**Possible Causes**

The API cannot be called from the main thread.

**Solution**

Call the API from a non-main thread.

## 29800002 Failed to Call the Remote API

**Error Message**

Remote call failed.

**Description**
The API fails to be called for the remote service.

**Possible Causes**

The service is not started or crashes.
