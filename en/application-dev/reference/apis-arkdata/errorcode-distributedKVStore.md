# Distributed KV Store Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 15100001 Subscription Count Reaches the Limit

**Error Message**

Upper limit exceeded.

**Description**

The number of subscriptions or the number of opened result sets has reached the limit.

**Possible Causes**

1.  The number of subscriptions made through **on()** reaches 8.
2.  The number of result sets opened by **getResultSet()** reaches 8.

**Solution**

1. Cancel the subscriptions that are not required.
2. Close the result sets that are no longer required.

## 15100002 Parameter Configuration Changes

**Error Message**

The options configuration changes when the API is called to obtain a KV store.

**Description**

The **options** configuration changes when **getKVStore()** is called to obtain a KV store.

**Possible Causes**

The possible causes are as follows:
1. An existing **storeId** is used to create a KV store.
2. You want to change the **options** parameter of a KV store.

**Solution**

1. When creating a KV store, do not use a duplicate **storeId**.
2. Currently, the **options** parameter of a KV store cannot be changed. To apply the change, delete the KV store and create a KV store with the required **options** settings.

## 15100003 KV Store Corrupted

**Error Message**

Database corrupted.

**Description**

The target KV store is corrupted.

**Possible Causes**

The target KV store is corrupted.

**Solution**

1. Restore the KV store from a backup file.
2. If no backup file is available, delete the corrupted KV store and create a new one.

## 15100004 Failed to Find Data

**Error Message**

Data not found.

**Description**

Related data is not found when **deleteKVStore()**, **sync()**, or **get()** is called.

**Possible Causes**

The possible causes are as follows:
1. The KV store to delete does not exist or has been deleted.
2. The data queried does not exist or has been deleted.
3. The KV store specified for the data sync operation does not exist or has been deleted.

**Solution**

1. Before deleting a KV store, check that the KV store exists.
2. When querying data in a KV store, check whether the query keywords are correct.
3. Before synchronizing data, check that the related KV store is available.

## 15100005 KV Store or Result Set Closed

**Error Message**

Database or result set already closed.

**Description**

The KV store or result set to operate is already closed.

**Possible Causes**

The KV store or result set is closed manually before the operation.

**Solution**

1. Obtain the KV store and try again.
2. Obtain the result set and try again.
