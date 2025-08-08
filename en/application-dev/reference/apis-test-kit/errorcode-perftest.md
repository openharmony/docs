# PerfTest Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 32400001 Initialization Failed

**Error Message**

Initialization failed.

**Description**

The framework fails to be initialized.

**Possible Causes**

The bundle name of the application cannot be obtained.

**Solution**

Run the **ps** command to check whether the application process exists. Ensure that the application process exists.

## 32400002 Internal Error
**Error Message**

Internal error.

**Description**

An internal error occurs in the framework.

**Possible Causes**

1. IPC transmission fails.
2. The **PerfTest** object does not exist.

**Solution**

1. Retry the IPC transmission.
2. Check whether the **PerfTest** object has been destroyed. If yes, create a **PerfTest** object again. For details, see the [create](js-apis-perftest.md#create) API.

## 32400003 Parameter Verification Failed
**Error Message**

Parameter verification failed.

**Description**

Parameter verification failed.

**Possible Causes**

The parameter type is incorrect or the parameter value is out of the specified range.

**Solution**

Check whether the input parameters of the API meet the requirements.

## 32400004 Failed to Execute the Callback
**Error Message**

Failed to execute the callback.

**Description**

Failed to execute the callback.

**Possible Causes**

1. An exception is thrown in the callback.
2. The callback execution times out.

**Solution**

Check the internal logic of the callback to ensure that no exception is thrown and that the callback execution does not time out.

## 32400005 Failed to Collect Performance Data
**Error Message**

Failed to collect metric data.

**Description**

Failed to collect performance data.

**Possible Causes**

The application process does not exist during performance data collection.

**Solution**

Run the **ps** command to check whether the application process exists during performance data collection. Ensure that the application process exists.

## 32400006 Failed to Obtain Performance Data
**Error Message**

Failed to obtain the measurement result.

**Description**

Failed to obtain the test data of the specified performance metric.

**Possible Causes**

The data collection is not complete.

**Solution**

Ensure that the [PerfTest.run](js-apis-perftest.md#run) API has been executed and no exception is thrown. Ensure that the data collection is complete before obtaining the specified data.

## 32400007 API Does Not Support Concurrent Calls
**Error Message**

The API does not support concurrent calls.

**Description**

The API does not support concurrent calls.

**Possible Causes**

The async API does not use **await** to wait until the asynchronous execution is complete. As a result, the API is called concurrently.

**Solution**

Use **await** to wait until the asynchronous function execution is complete.
