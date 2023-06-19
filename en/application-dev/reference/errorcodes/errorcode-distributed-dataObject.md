# Distributed Data Object Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 15400001 Failed to Create the In-Memory Database

**Error Message**

Create table failed.

**Description**

The in-memory database fails to be created.

**Possible Causes**

An object with the same session ID already exists.

**Solution**

Check for the object has been added to the same session.
