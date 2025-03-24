# HiCollie Error Codes

> **Note:**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 29800001 Failed to Obtain the System Service

**Error Message**

Wrong thread context. The function cannot be called from main thread.

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

## 29800003 Invalid Timer Name

**Error Message**

Invalid timer name.

**Description**

The timer name is invalid.

**Possible Causes**

The timer name is a null pointer or empty.

## 29800004 Invalid Timeout Value

**Error Message**

Invalid timeout value.

**Description**

The value of **timeout** is invalid.

**Possible Causes**

The value of **timeout** is **0**.

## 29800005 Incorrect Process Context

**Error Message**

Wrong process context.

**Description**

The process context is incorrect.

**Possible Causes**

The appspawn or nativespawn process is used to access the timer.

## 29800006 Incorrect Timer ID

**Error Message**

Wrong timer id output param.

**Description**

The timer task ID is incorrect.

**Possible Causes**

- The pointer to the timer ID is null.
- The number of concurrent tasks in the process that accesses the HiCollie timer reaches the maximum value 128.
