# Snapshot Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 100001 Internal Error

**Error Message**

Internal error.

**Symptom**

This error code is reported when an error with the internal runtime state occurs.

**Possible Cause**

The correct UI instance cannot be obtained, a null pointer exception is encountered, or the internal state validation fails within the UI instance.

**Solution**

N/A

## 160001 Image Loading Error

**Error Message**

ComponentSnapshot error.

**Symptom**

This error code is reported when image loading fails.

**Possible Cause**

The **Image** component fails to decode the image properly or the node fails to load the image before the screenshot API is called.

**Solution**

N/A
