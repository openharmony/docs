# User Preference Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 15500000 Internal Error
**Error Message**

Inner error.

**Description**

An internal error occurred.

**Possible Causes**

The persistent file fails to be read or written.

**Procedure**

Locate the cause based on the log information or contact the technical support.

## 15500010 Failed to Delete the User Preference Persistence File
**Error Message**

Failed to delete preferences file.

**Description**

The operation of deleting the user preference persistence file failed.

**Possible Causes**

The possible causes are as follows:
1. The file name is incorrect.
2. The file path is incorrect.

**Solution**

1. Check that the file name is correct.
2. Check that the file path is correct.

## 15500019 Failed to Obtain the Subscription Service

**Error Message**

Failed to obtain subscription service.

**Description**

Failed to obtain the subscription service in inter-process event subscription.

**Possible Causes**

The platform does not support service subscription.

**Solution**

Deploy the subscription service on the platform.

## 15501001 Stage Model Required

**Error Message**

 Only supported in stage mode.

**Description**

This operation can be performed only on the stage model.

**Possible Causes**

The context is not a stage model.

**Solution**

Perform the operation on the stage model.

## 15501002 The dataGroupId parameter in Options is invalid.

**Error Message**

The data group id is not valid.

**Description**

The **dataGroupId** parameter is invalid.

**Possible Causes**

The **dataGroupId** is not obtained from the AppGallery.

**Solution**

Obtain **dataGroupId** from the AppGallery and pass it correctly.
