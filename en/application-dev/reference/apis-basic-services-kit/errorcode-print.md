# Print Service Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 13100001 Generic Print Error

**Error Message**

Generic failure of print.

**Possible Causes**


1. Failed to create a task object in the **print** module.

**Solution**

Close the print page and try again later, or restart the device.

## 13100002 RPC Error

**Error Message**

RPC failure.

**Possible Causes**


1. Failed to obtain the SA service object.
2. Failed to conduct inter-process communication.

**Solution**

Close the print page and try again later, or restart the device.

## 13100003 Print Service Error

**Error Message**

Failure of print service.

**Possible Causes**


1. Failed to start the print service.
2. Failed to start the cups service.

**Solution**

Close the print page and try again later, or restart the device.

## 13100004 Invalid Print Extension

**Error Message**

Invalid print extension.

**Possible Causes**


1. Cannot find the print extension.
2. An error occurred when printing extended parameters.
3. An error occurred when printing the extended status.

**Solution**

Close the print page and try again later, or restart the device.

## 13100005 Invalid Printer

**Error Message**

Invalid printer.

**Possible Causes**


1. Incorrect printer ID.
2. The cups failed to query the printer list.
3. The cups failed to query the printer information.

**Solution**

Close the print page and try again later, or restart the device.

## 13100006 Invalid Print Job

**Error Message**

Invalid print job.

**Possible Causes**


1. Incorrect print job ID.
2. Incorrect print job status.
3. Cannot find the print job.

**Solution**

Cancel the job, close the print page, or restart the device.
