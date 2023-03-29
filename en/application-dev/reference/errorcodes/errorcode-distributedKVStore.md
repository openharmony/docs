# Distributed KV Store Error Codes

## 15100001 Subscription Count Reaches the Limit

**Error Message**

Over max subscribe limits.

**Description**

The number of subscriptions has reached the limit for **on('dataChange')**.

**Possible Causes**

The number of subscriptions has reached the limit for **on('dataChange')**.

**Solution**

Unregister unnecessary subscriptions and try again.

## 15100002 Parameter Configuration Changes

**Error Message**

Open existed database with changed options.

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

Not found.

**Description**

Related data is found when **deleteKVStore()**, **delete()**, **deleteBatch()**, or **get()** is called.

**Possible Causes**

The possible causes are as follows:
1. The KV store to delete does not exist or has been deleted.
2. The data queried does not exist or has been deleted.
3. The data to delete does not exist or has been deleted.

**Solution**

1. Before deleting a KV store, check that the KV store exists.
2. When querying data in a KV store, check whether the query keywords are correct.
3. When deleting data from a KV store, check that the keyword for the deletion is correct and the data to delete exists.

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
