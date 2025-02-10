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

If data loss is acceptable, delete the RDB store and create a new one. Otherwise, restore the RDB store from the backup file. For details, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

## 14800012 Empty Result Set or Invalid Position

**Error Message**

Row out of bounds.

**Description**

The result set is empty or the specified location is invalid.

**Possible Causes**

The result set is empty, or the specified row number in the result set is out of range [0, m - 1]. **m** is **resultsetV9.rowCount**.

**Solution**

Check whether the result set is empty or whether the specified row number is out of range.

## 14800013 Null Column Value or Column Data Type Incompatible With the API Called

**Error Message**

Column out of bounds.

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

## 14800014 RdbStore or ResultSet Closed

**Error Message**

Already closed.

**Description**

The RDB store or result set is closed.

**Possible Causes**

**close()** is called to close the RDB store or result set, or the RDB store or result set fails to be opened.

**Solution**

Open the RDB store or obtain the result set.

## 14800015 RDB Store Not Respond

**Error Message**

The database does not respond.

**Description**

The RDB store does not respond.

**Possible Causes**

A read, write, attach, or detach operation is being performed, and cannot be complete within the specified time (2s by default).

**Solution**

1. Try again later.
2. For the [attach](./js-apis-data-relationalStore.md#attach12) or [detach](./js-apis-data-relationalStore.md#detach12) API, increase the value of **waitTime**.

## 14800016 Duplicate RDB Alias

**Error Message**

The database alias already exists.

**Description**

The RDB store alias already exists.

**Possible Causes**

The RDB store alias already exists.

**Solution**

Stop the attach operation or change the RDB store alias.

## 14800017 Key Configuration Changed

**Error Message**

Config changed.

**Description**

The key configuration of the RDB store has been modified.

**Possible Causes**

Key configuration, such as **area** and **securityLevel**, of the RDB store is changed.

**Solution**

Restore the original configuration if required. Otherwise, delete the old RDB store, use the new configuration to create a new RDB store, and import the data to the new RDB store.

## 14800018 No Match

**Error Message**

No data meets the condition.

**Description**

No data matching the search criteria is found.

**Possible Causes**

The SQL statement used for query is incorrect, or the data does not exist.

**Solution**

Use the correct query statement or add data.
 
## 14800019 SQL Query Statement Required

**Error Message**

The SQL must be a query statement.

**Description**

The SQL statement used is not a query statement.

**Possible Causes**

The SQL statement used for query does not meet specifications.

**Solution**

Use SQL statements that comply with specifications.

## 14800020 Key Damaged or Lost

**Error Message**

The secret key is corrupted or lost.

**Description**

The operation for obtaining the secret key fails.

**Possible Causes**

The root key is lost, the application does not have the permission to read the key file, or the key file is damaged.

**Solution**

1. Check the permission for accessing the key file and the content of the key file.
2. Rebuild or restore the database.

## 14800021 SQLite: Generic Error

**Error Message**

SQLite: Generic error.

**Description**

An SQLite generic error occurs.

**Possible Causes**

An SQL statement is executed to perform any of the following operations:
1. Insert or update data in a table that is not created.
2. Insert or update data in a column that does not exist.
3. Call an undefined function. For details, see SQLITE_ERROR.

**Solution**

Analyze the SQL statement and identify the error.

## 14800022 SQLite: Asynchronous Callback Request Aborted

**Error Message**

SQLite: Callback routine requested an abort.

**Description**

The asynchronous callback request is aborted.

**Possible Causes**

1. The callback in a custom function in SQLite is aborted.
2. See SQLITE_ABORT.

**Solution**

Check that the hook functions (callbacks) of SQLite are implemented correctly.

## 14800023 SQLite: Access Denied

**Error Message**

SQLite: Access permission denied.

**Description**

SQLite access is denied.

**Possible Causes**

1. SQLite does not have the required permission to access or modify a file.
2. See SQLITE_PERM.

**Solution**

1. Ensure that the file is not read-only. If the file is read-only, remove the read-only property.
2. Check that the caller has the required permissions to access the file or folder.
3. Check whether the file system is read-only. If yes, change it to writable.
4. Check that the database file is not being used by another process. Terminate the process that is using the file.
5. When handling permission issues, ensure that you have the permission to change the permissions on the file or folder.

## 14800024 SQLite: Database File Locked

**Error Message**

SQLite: The database file is locked.

**Description**

The SQLite database file is locked.

**Possible Causes**

1. Two processes of the same application, for example, UIability and DataShareability, perform addition, deletion, and modification operations in the same database, or processes in the same group of different applications perform addition, deletion, and modification operations in the same database via the group.
2. See SQLITE_BUSY.

**Solution**

1. Avoid concurrent database operations from processes.
2. Wait for a while and try again.

## 14800025 SQLite: Database Table Locked

**Error Message**

SQLite: A table in the database is locked.

**Description**

An SQLite database table is locked.

**Possible Causes**

1. The database file to write has been locked by another process. A transaction is being performed in the RDB store, or the write attempt is blocked by a lock mechanism.
2. See SQLITE_LOCKED.

**Solution**

1. Check that the database file is not being written by another process or thread.
2. Check that no write operation is performed after a transaction is started and before the transaction is committed.
3. Check whether the write operation is blocked by other lock mechanisms (such as file locks).
4. Check that the database connection instance is closed after the database operation is complete.
5. In a multi-thread environment, ensure that synchronization mechanisms, such as locks, are used to prevent data races.

## 14800026 SQLite: Insufficient Database Memory

**Error Message**

SQLite: The database is out of memory.

**Description**

The database memory is insufficient.

**Possible Causes**
 
The data volume is too large or the memory allocated is insufficient.

**Solution**

Reduce the data volume or increase the memory allocated.

## 14800027 SQLite: Attempt to Write a Read-only Database

**Error Message**

SQLite: Attempt to write a readonly database.

**Description**

A write operation is invoked on a read-only database.

**Possible Causes**

1. An attempt is made to write an SQLite database file that is opened in read-only mode. The access is denied because the target file is in a read-only file system or the database is marked as read-only.
2. See SQLITE_READONLY.

**Solution**

1. Ensure that the caller has the permission to write data to the database file.
2. If the file system is read-only, change it to read/write.
3. Check that no read-only parameter is used when the database is opened.

## 14800028 SQLite: I/O Error

**Error Message**

SQLite: Some kind of disk I/O error occurred.

**Description**

A disk I/O error occurs. 

**Possible Causes**

The possible causes include the following:
1. The target file does not exist.
2. The target file is read-only.
3. The disk space is insufficient.
4. The target file is damaged.
5. See SQLITE_IOERR.

**Solution**

1. Check whether the file path is correct and whether the file exists.
2. Check that the file is not read-only.
3. Delete unnecessary files to ensure sufficient disk space.
4. Check that the caller has permissions to read and write the file.

## 14800029 SQLite: Database Is Full

**Error Message**

SQLite: The database is full.

**Description**

The SQLite database is full.

**Possible Causes**

The data volume is too large or the disk space is insufficient.

**Solution**

Reduce the data volume or increase the disk space.

## 14800030 SQLite: Unable to Open the Database File

**Error Message**

SQLite: Unable to open the database file.

**Description**

The database file fails to be opened.

**Possible Causes**

1. The file does not exist, and the RDB store fails to be created.
2. The file exists, but the database file is damaged.
3. The caller does not have the permission to access the file using SQLite.
4. The disk space is insufficient.
5. See SQLITE_CANTOPEN.

**Solution**

1. Check that the database file path is correct and the caller has the permission to read and write the file.
2. Check that the disk space is sufficient.

## 14800031 SQLite: TEXT or BLOB Exceeds the Limit

**Error Message**

SQLite: TEXT or BLOB exceeds size limit.

**Description**

The size of the text or BLOB exceeds the limit.

**Possible Causes**

1. The result set returned exceeds the size limit that SQLite can process.
2. See SQLITE_TOOBIG.

**Solution**

Divide the query operation into multiple small queries, which process part of the data each time.

## 14800032 SQLite: Abort Due to Constraint Violation

**Error Message**

SQLite: Abort due to constraint violation.

**Description**

The database operation violates the constraint rule and is aborted.

**Possible Causes**

1. The data write operation violates the constraints on the database integrity.
2. See SQLITE_CONSTRAINT.

**Solution**

Check whether the data to be inserted or updated violates the constraints.

## 14800033 SQLite: Data Types Mismatch

**Error Message**

SQLite: Data type mismatch.

**Description**

The data types mismatch.

**Possible Causes**

1. The data type specified in an SQL statement does not match the type of the data stored in the database.
2. See SQLITE_MISMATCH.

**Solution**

Check the type of the data in the specified column in the SQL statement and ensure that the type of the data to be inserted, updated, or queried matches the data type of the column.

## 14800034 Incorrect Use of SQLite Library

**Error Message**

SQLite: Library used incorrectly.

**Description**

The SQLite interface is used incorrectly.

**Possible Causes**

1. The database operation or context is incorrect. This error usually occurs in the following cases:
    - The next operation is performed before a database operation is complete.
    - A database operation is performed on a closed database connection.
    - A released or invalid database object is used to perform data operation.
2. See SQLITE_MISUSE.

**Solution**

1. Check that proper synchronization mechanisms like locks are used between database operations.
2. Check that a database connection is opened before use and closed after the operation is complete.
3. Check that all database objects are correctly released after being used.

## 14800047 WAL File Size Exceeds the Default Limit

**Error Message**

The WAL file size exceeds the default limit.

**Description**

The WAL file exceeds 512 MB, which is the default limit.

**Possible Causes**

Data is added, deleted, and modified continuously without closing the read transaction or result set.

**Solution**

1. Check for unclosed result sets or transactions.

2. Close all result sets or transactions.

## 14800050 Failed to Obtain the Subscription Service

**Error Message**

Failed to obtain the subscription service.

**Description**

The error code is returned when the subscription service failed to be obtained.

**Possible Causes**

The platform does not support service subscription.

**Solution**

Deploy the subscription service on the platform.

## 14801001 Stage Model Required

**Error Message**

The operation is supported in the stage model only.

**Description**

This operation can be performed only on the stage model.

**Possible Causes**

The context is not a stage model.

**Solution**

Perform the operation on the stage model.

## 14801002 Invalid dataGroupId in storeConfig

**Error Message**

Invalid data ground ID.

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
