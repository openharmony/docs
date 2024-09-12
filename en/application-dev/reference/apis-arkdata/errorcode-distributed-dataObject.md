# Distributed Data Object Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 15400001 Failed to Create the In-Memory Database

**Error Message**

Create table failed.

**Description**

The in-memory database fails to be created.

**Possible Causes**

The same session ID is set for another distributed data object.

**Solution**

Use [genSessionId](../../reference/apis-arkdata/js-apis-data-distributedobject.md#distributeddataobjectgensessionid) to generate a random session ID to avoid using an existing session ID.
