# Collaboration Edit Object Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 15410000 Internal Error

**Error Message**

Internal error.

**Description**

An internal error occurs.

**Possible Causes**

View the error log to determine the cause of the error. Possible causes include the following:

1. Incorrect use of APIs.

2. System errors, such as null pointer, insufficient memory, IPC exception, and JS engine exception.

**Solution**

1. Check whether the APIs are called correctly. If not, apply necessary corrections.
2. If the problem persists, ask the user to restart or update the application or upgrade the device version.

## 15410001 Unsupported Operation

**Error Message**

Unsupported operation.

**Description**

The current operation is not supported.

**Possible Causes**

The conditions for calling the API are not satisfied.

**Solution**

Check whether the conditions for calling the API are satisfied. For example, the APIs of **Node** and **Text** can be called only after the node object or text object is inserted into the collaboration edit object.

## 15410002 Index Out of Range

**Error Message**

Index out of range.

**Description**

The specified index is out of the value range.

**Possible Causes**

The index value passed in is incorrect.

**Solution**

Ensure that the index value is correct.

## 15410003 Database Error

**Error Message**

Database error.

**Description**

A database error occurs.

**Possible Causes**

1. The database kernel APIs are not correctly called when the collaboration edit object APIs are used to insert, delete, or query data in the database.
2. The database file is corrupted.

**Solution**

1. Check whether the parameters of the API are correct.
2. Analyze the relationship between the shared data types and check that the APIs are correctly called.
3. Delete the local database, and create a new one by synchronizing data from the cloud.
