# RDB Error Codes

## 14800010 Invalid RDB Name

**Error Message**

Invalid database name.

**Description**

The RDB store name is invalid.

**Possible Causes**

The RDB store name is empty or exceeds 1024 bytes.

**Solution**

Check that the RDB store name is not empty and does not exceed 1024 bytes.

## 14800011 Database File Corrupted

**Error Message**

Database corrupted.

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
