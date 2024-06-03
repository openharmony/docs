# RDB Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

##  14800000 Internal Error

**Error Message**

Inner error.

**Description**

Internal error.

**Possible Causes**

View the error log to determine the cause of the error. Possible causes include the following:
1. The SQL statement fails to be executed.
2. The internal state is abnormal.
3. There is API that is incorrectly used.
4. A system error, such as null pointer, insufficient memory, unexpected restart of data service, I/O error, IPC exception, and JS engine exception, occurs.

**Solution**

1. Check whether SQL statements and predicates are correctly used.
2. Check whether a closed object is reused.
3. Check whether the APIs are correctly used.
4. If the problem persists, ask the user to restart or upgrade the application or upgrade the device version.

## 14800010 Invalid Database Path

**Error Message**

Invalid database path.

**Description**

The RDB store path is invalid.

**Possible Causes**

The RDB store path is invalid.

**Solution**

Check the RDB store path.

## 14800011 Database File Corrupted

**Error Message**

Database corrupted.

**Description**

The RDB store is corrupted when an API for adding, deleting, querying, or synchronizing data is invoked.

**Possible Causes**

The RDB store file has been corrupted.

**Solution**

1. Restore the RDB store using a backup file.
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

- The result set is empty.
- The current row number in the result set is out of range [0, m - 1]. **m** is **resultsetV9.rowCount**.
- The column number is out of the range [0, n - 1]. **n** is **resultsetV9.columnCount**.
- The API called does not support the type of the column data.

**Solution**

1. Check whether the result set is empty.
2. Check whether the row number and column number of the result set are out of range.
3. Check whether the column data type is supported.

## 14800015 RDB Store Not Respond

**Error Message**

The database does not respond.

**Description**

The RDB store does not respond.

**Possible Causes**

A read or write operation is being performed, and the current operation cannot be performed within the specified time (2s by default).

**Solution**

1. Try again later.
2. For the [attach](./js-apis-data-relationalStore.md#attach12) or [detach](./js-apis-data-relationalStore.md#detach12) API, increase the value of **waitTime**.

## 14800016 Duplicate RDB Alias

**Error Message**

The database is already attached.

**Description**

The RDB store alias already exists.

**Possible Causes**

The RDB store alias already exists.

**Solution**

Stop the attach operation or change the RDB store alias.

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

The same database table is set with different [DistributedType](js-apis-data-relationalStore.md#distributedtype10).

**Solution**

A database table can be synchronized either between devices or between device and cloud.
