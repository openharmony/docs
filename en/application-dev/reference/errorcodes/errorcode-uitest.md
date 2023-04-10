# UiTest Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 17000001 Initialization Failure

**Error Message**

Initialize failed.

**Description**

This error code is reported when the framework fails to be initialized.

**Possible Causes**

The accessibility service cannot be accessed.

**Solution**

Run the **param set persist.ace.testmode.enabled 1** command and restart the device.

## 17000002 Unable to Call the API
**Error Message**

API does not allow calling concurrently.

**Description**

This error code is reported when the API fails to be called.

**Possible Causes**

The API was not called using **await**.

**Solution**

Check test cases and make sure asynchronous APIs are called using **await**.

## 17000003 Assertion Failure
**Error Message**

Component existence assertion failed.

**Description**

This error code is reported when the user assertion fails.

**Possible Causes**

The component that the user asserts to exist does not exist.

**Solution**

Check the existence of the component that is asserted to exist.

## 17000004 Target Component/Window Lost
**Error Message**

Component lost/UiWindow lost.

**Description**

This error code is reported when the target component or window is lost and cannot be operated.

**Possible Causes**

After the target component or window is obtained, the page changes. As a result, the target component or window is lost.

**Solution**

Check whether the loss is caused by page changes.

## 17000005 Operation Not Supported
**Error Message**

This operation is not supported.

**Description**

This error code is reported when the performed operation is not supported by the UI object.

**Possible Causes**

The component or window attribute does not support the performed operation.

**Solution**

Make sure the operation to perform is supported by the component or window attribute.
