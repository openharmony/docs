# Log Library Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 21300001 Specified File Not Exist

**Error Message**

The specified file does not exist.

**Description**

When the **copy**, **move**, or **delete** API is called to perform file operations, the file with the specified name does not exist in the specified type of logs.

**Possible Cause**

1. The input file name is incorrect.
2. The file with the input file name does not exist.

**Procedure**

Check whether the input file name is correct.
