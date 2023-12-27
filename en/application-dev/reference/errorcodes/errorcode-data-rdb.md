# RDB Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

##  14800000 Internal Error

**Error Message**

Inner error.

**Description**

An error occurs at the underlying database.

**Possible Causes**

Invalid SQL statement is passed in.

**Solution**

Determine the cause of the error based on the log information.

## 14800010 Invalid Database Path

**Error Message**

Failed to open or delete database by invalid database path.

**Description**

The RDB store path is invalid.

**Possible Causes**

The RDB store path is invalid.

**Solution**

Check the RDB store path.

## 14800011 Database File Corrupted

**Error Message**

Failed to open database by database corrupted.

**Description**

The RDB store is corrupted when an API for adding, deleting, querying, or synchronizing data is invoked.

**Possible Causes**

The RDB store file has been corrupted.

**Solution**

1. Restore the RDB store using the backup file.
2. If no RDB backup file is available, delete the RDB store and create it again.

## 14800012 Empty Result Set or Invalid Position

**Error Message**

The result set is empty or the specified location is invalid.

**Description**

The result set is empty or the specified location is invalid.

**Possible Causes**

The result set is empty, or the specified row number in the result set is out of range [0, m - 1]. **m** is **resultsetV9.rowCount**.

**Solution**

Check whether the result set is empty or whether the specified row number is out of range.

## 14800013 Null Column Value or Column Data Type Incompatible With the API Called

**Error Message**

The column value is null or the column type is incompatible.

**Description**

The column value is null, or the column data type is incompatible with the API called.

**Possible Causes**

1. The result set is empty.
2. The current row number in the result set is out of range [0, m - 1]. **m** is **resultsetV9.rowCount**.
3. The column number is out of the range [0, n - 1]. **n** is **resultsetV9.columnCount**.
4. The API called does not support the type of the column data.

**Solution**

1. Check whether the result set is empty.
2. Check whether the row number and column number of the result set are out of range.
3. Check whether the column data type is supported.

## 14800047 WAL File Size Exceeds the Default Limit

**Error Message**

The WAL file size exceeds the default limit.

**Description**

The WAL file size exceeds 200 MB, which is the default limit.

**Possible Causes**

Data is added, deleted, and modified continuously without closing the read transaction or result set.

**Solution**

1. Check for unclosed result sets or transactions.

2. Close all result sets or transactions.

## 14800050 Failed to Obtain the Subscription Service

**Error Message**

Failed to obtain subscription service.

**Description**

The error code is returned when the subscription service failed to be obtained.

**Possible Causes**

The platform does not support service subscription.

**Solution**

Deploy the subscription service on the platform.

## 14801001 Stage Model Required

**Error Message**

 Only supported in stage mode.

**Description**

This operation can be performed only on the stage model.

**Possible Causes**

The context is not a stage model.

**Solution**

Perform the operation on the stage model.

## 14801002 Invalid dataGroupId in storeConfig

**Error Message**

The data group id is not valid.

**Description**

The **dataGroupId** parameter is invalid.

**Possible Causes**

The **dataGroupId** is not obtained from the AppGallery.

**Solution**

Obtain **dataGroupId** from the AppGallery and pass it to **storeConfig** correctly.

## 14800051 Inconsistent Distributed Table Type

**Error Message**

The type of the distributed table does not match.

**Description**

Different distributed table types are set for the same database table.

**Possible Causes**

The database table is set with different [distributed table types](../apis/js-apis-data-relationalStore.md#distributedtype10).

**Solution**

A database table can be synchronized either between devices or between device and cloud.
