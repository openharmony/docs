# Drag Event Error Codes
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 190001 Data Not Found

**Error Message**

Data not found.

**Description**

This error code is reported when no data is obtained after an application calls the **GetData()** API of **DragEvent**.

**Possible Causes**

The **DragEvent** data has not been obtained.

**Solution**

N/A

## 190002 Data Retrieval Error

**Error Message**

Data error.

**Description**

This error code is reported when incorrect data is obtained after an application calls the **GetData()** API of **DragEvent**.

**Possible Causes**

The obtained data is incorrect.

**Solution**

N/A

## 190003 Operation Not Allowed in the Current Phase

**Error Message**

Operation not allowed for current phase.

**Description**

This error code is reported when the **startDataLoading()** API of **DragEvent** is called outside the **onDrop** phase.

**Possible Causes**

The operation is not allowed in the current phase.

**Solution**

N/A

## 190004 Operation Failed

**Error Message**

Operation failed.

**Description**

This error code is reported when an operation fails during the current phase.

**Possible Causes**

Invalid or incorrect parameters are passed to the API.

**Solution**

N/A
