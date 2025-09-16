# HiDebug Error Codes

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 11400101 Failed to Obtain the System Service

**Error Message**

ServiceId invalid. The system ability does not exist.

**Description**
The system service cannot be obtained based on the specified service ID.

**Possible Causes**

The specified service ID is incorrect or the corresponding service is not started.

**Solution**

Specify a correct system service ID.

## 11400102 Repeated Trace Collection

**Error Message**

Capture trace already enabled.

**Description**
The trace collection has been enabled for the process.

**Possible Causes**

The trace collection is in progress.

**Solution**

Wait until the trace collection is complete or call **OH_HiDebug_StopAppTraceCapture** to stop the trace collection.

## 11400103 Permission Verification Failed

**Error Message**

No write permission on the file.

**Description**
You do not have the permission to write the trace file in the current directory.

**Possible Causes**

The directory does not exist or is deleted by mistake.

**Solution**

Run the trace collection again to generate a correct trace file in the current directory.

## 11400104 Internal Error

**Error Message**

Abnormal trace status.

**Description**
This error code is reported if the current trace encounters an internal error.

**Possible Causes**

The system kernel crashes or the application process freezes.

**Solution**

Restart the application or system.

## 11400105 Trace Collection Is Not Enabled

**Error Message**

No capture trace running.

**Description**
This error code is reported if no trace is in progress.

**Possible Causes**

Trace collection is not enabled.

**Solution**

Enable trace collection and then stop it.

## 11400106 The API Call Quota Is Exceeded

**Error Message**

Quota exceeded.

**Description**
The API call quota is exceeded.

**Possible Causes**

1. This API is called by a process more than once per day.

2. This API is called by the system more than five times per week.

**Solution**

Wait for the update of the API call quota.

## 11400107 Failed to Fork The Child Dump Process

**Error Message**

Fork operation failed.

**Description**
Failed to fork the child dump process.

**Possible Causes**

The system resources are insufficient. You are advised to check the system load.

**Solution**

Fork the child dump process again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-setup-hilog#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400108 Failed to Wait for the Child Dump Process to Finish

**Error Message**

Failed to wait for the child process to finish.

**Description**
Failed to wait for the child dump process to finish.

**Possible Causes**

The system resources are insufficient. You are advised to check the system load.

**Solution**

Fork the child dump process again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-setup-hilog#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400109 Waiting for the Child Dump Process Times Out

**Error Message**

Timeout while waiting for the child process to finish.

**Description**
The child dump process times out.

**Possible Causes**

The dump process takes a long time. You are advised to check the system load.

**Solution**

Fork the child dump process again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-setup-hilog#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400110 Insufficient Disk Space

**Error Message**

Failed to create dump file.

**Description**
The disk space is insufficient.

**Possible Causes**

The available disk space is less than 30 GB.

**Solution**

Release the disk space to ensure that the available space is greater than 30 GB.

## 11400111 Failed to Call the Node-API

**Error Message**

Napi interface call exception.

**Description**
An exception occurs when the Node-API is called.

**Possible Causes**

The VM is abnormal.

**Solution**

Fork the child dump process again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-setup-hilog#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400112 Repeated Data Dump

**Error Message**

Repeated data dump.

**Description**
Dump data is collected repeatedly.

**Possible Causes**

This API has been called and is called repeatedly before the calling is complete.

**Solution**

Optimize the code logic to ensure that the next dump task starts after the previous dump task is complete.

## 11400113 Failed to Create a Dump File

**Error Message**

Failed to create dump file.

**Description**

Failed to create the dump file.

**Possible Causes**

1. A file with the same name exists in the process directory.

2. System resources are insufficient.

**Solution**

Fork the child dump process again. If it still fails, filter **Error** logs to locate the fault. For details, see [Log Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-setup-hilog#section2114542680). If the problem persists, <!--RP1-->contact us.<!--RP1End-->

## 11400114 Failed to Enable GWP-Asan

**Error Message**

The number of GWP-ASAN applications of this device overflowed after last boot.

**Description**

After the device is restarted, the number of applications for which GWP-Asan is enabled exceeds the system limit.

**Possible Causes**

A maximum of 20 applications can be enabled with GWP-Asan during the running of a single device. The limit is exceeded.

**Solution**

Restart the system to update the device quota.
