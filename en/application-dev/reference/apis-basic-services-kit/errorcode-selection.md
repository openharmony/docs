# Word Selection Service Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 33600001 Word Selection Service Error

**Error Message**

Selection service exception.

**Description**

This error code is reported when the word selection service is abnormal.

**Possible Causes**

An error is thrown when an application calls the word selection service or its dependent services.

**Solution**

Restart the device and try again.

## 33600002 Word Selection Panel Has Been Destroyed

**Error Message**

This selection window has been destroyed.

**Description**

This error code is reported when the word selection panel has been destroyed.

**Possible Causes**

1. The word selection panel object is invalid.
2. The word selection panel is not created.

**Solution**

1. Ensure the word selection panel object is valid before operating the panel.
2. Do not operate the destroyed word selection panel object.

## 33600003 Invalid Application for Word Selection

**Error Message**

Invalid operation. The selection app is not valid.

**Description**

This error code is reported when an invalid application calls the word selection API.

**Possible Causes**

An invalid application calls the word selection API.

**Solution**

Ensure the current application is valid for using word selection.
