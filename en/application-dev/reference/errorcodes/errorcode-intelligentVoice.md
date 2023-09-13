# Intelligent Voice Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 22700101 Insufficient Memory

**Error Message**

No memory.

**Error Description**

This error code is reported if a memory allocation failure or null pointer occurs when an API is called.

**Possible Causes**

1. The system does not have sufficient memory for mapping.
2. Invalid instances are not destroyed in time to release the memory.

**Solution**

1. Stop the current operation or suspend other applications to free up memory.
2. Clear invalid instances to free up memory, and then create new instances as needed. If the problem persists, stop related operations.

## 22700102 Invalid Parameter

**Error Message**

Input parameter value error.

**Error Description**

This error code is reported if a certain parameter passed in the API is invalid.

**Possible Cause**

The parameter is invalid. For example, the parameter value is not within the range supported.

**Solution**

Pass the correct parameters in the API.

## 22700103 Initialization Failed

**Error Message**

Init failed.

**Error Description**

This error code is reported if an error occurs while the enrollment engine is initialized.

**Possible Cause**

1. Repeated initialization.
2. Lack of resources for initialization of the enrollment engine.

**Solution**

1. Avoid performing initialization repeatedly.
2. Ensure that the resources required for initialization, such as acoustic model files, are ready.

## 22700104 Enrollment Commit Failure

**Error Message**

Commit enroll failed.

**Error Description**

This error code is reported if an error occurs after the [commit()](../apis/js-apis-intelligentVoice.md#commit) API of the enrollment engine is called.

**Possible Cause**

The specified number of enrollment procedures are not completed.

**Solution**

Commit the enrollment after the specified number of enrollment procedures are completed.
