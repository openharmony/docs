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

## 11400106 The API Call Quota Has Been Exceeded

**Error Message**

Quota exceeded.

**Description**
The API call quota has been exceeded.

**Possible Causes**

1. This API is called by a process for more than one time per day.

2. This API is called by the system for more than five times per week.

**Procedure**

Wait for the update of the API call quota.

## 11400107 Failed to Fork The Dump Child process

**Error Message**

Fork operation failed.

**Description**
Failed to fork the dump child process.

**Possible Causes**

The system resource is insufficient.

**Procedure**

Fork the dump child process again. If the fork still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400108 Failed to Wait for the Dump Child Process to Finish

**Error Message**

Failed to wait for the child process to finish.

**Description**
Failed to wait for the dump child process to finish.

**Possible Causes**

The system resource is insufficient.

**Procedure**

Wait for the dump child process to finish again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400109 The Dump Child Process Times Out

**Error Message**

Timeout while waiting for the child process to finish.

**Description**
The dump child process times out.

**Possible Causes**

The system load is high, and the dump process takes a long time.

**Procedure**

Wait for the dump child process to finish again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400110 The Disk Space Is Insufficient

**Error Message**

Failed to create dump file.

**Description**
The disk space is insufficient.

**Possible Causes**

The free disk space is less than 30 GB.

**Procedure**

Release the disk space to ensure that the available space is greater than 30 GB.

## 11400111 Failed to Call the Node-API

**Error Message**

Napi interface call exception.

**Description**
Failed to call the Node-API.

**Possible Causes**

The JavaScript VM is abnormal.

**Procedure**

Call the Node-API again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400112 The Data Dump Is Repeated

**Error Message**

Repeated data dump.

**Description**
The data dump is repeated.

**Possible Causes**

This API has been called and is called repeatedly before the calling is complete.

**Procedure**

Optimize the code logic to ensure that a new dump is started after the previous dump is complete.

## 11400113 Failed to Create a Dump File

**Error Message**

Failed to create dump file.
**Description**

Failed to create a dump file.

**Possible Causes**

1. A file with the same name exists in the process directory.

2. System resources are insufficient.

**Procedure**

Create a dump file again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-setup-hilog-V5#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->
