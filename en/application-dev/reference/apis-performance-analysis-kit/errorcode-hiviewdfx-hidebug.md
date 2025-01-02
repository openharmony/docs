# HiDebug Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 11400101 Failed to Obtain the System Service

**Error Message**

ServiceId invalid. The system ability does not exist.

**Description**
This error code is reported if a system service cannot be obtained based on the specified service ID.

**Possible Causes**

The specified service ID is incorrect.

**Procedure**

Specify a correct system service ID.

## 11400102 Repeated Trace

**Error Message**

Capture trace already enabled.

**Description**
This error code is reported if capture trace has already been enabled for the current process.

**Possible Causes**

The trace function enabled previously is not disabled.

**Procedure**

Disable the previously enabled trace.

## 11400103 Permission Verification Failed

**Error Message**

No write permission on the file.

**Description**
This error code is reported if you do not have the permission to write the trace file in the current directory.

**Possible Causes**

The current directory does not exist or is deleted by mistake.

**Procedure**

Run the trace again to generate a correct trace file in the current directory.

## 11400104 Internal Error

**Error Message**

Abnormal trace status.

**Description**
This error code is reported if the current trace encounters an internal error.

**Possible Causes**

This issue is probably caused by a system kernel breakdown or application process crash.

**Procedure**

Restart the application or system.

## 11400105 Trace Not Enabled

**Error Message**

No capture trace running.

**Description**
This error code is reported if no trace is in progress.

**Possible Causes**

Trace has not been enabled.

**Procedure**

Start a trace.
