# Pasteboard Error Codes

## 12900001 Index Out of Range

**Error Message**

The index is out of range.

**Description**

This error code is reported when the index passed in to the called API, such as **getRecord**, is out of range.

**Possible Causes**

The index passed in the API is beyond the record index range of the **PasteData** object. For example, the index passed in to **getRecord** exceeds the number of records.

**Solution**

Check the index range and call the API again with a valid index.

## 12900002 Maximum Number of Records Reached

**Error Message**

The number of record exceeds the maximum limit.

**Description**

This error code is reported when no new **PasteData** record can be added.

**Possible Causes**

The number of **PasteData** records has reached the maximum.

**Solution**

1. Check whether the number of **PasteData** records has reached the maximum.
2. If the number of **PasteData** records has reached the maximum, delete some records before adding new ones.

## 12900003 Another Copy or Paste Operation in Progress

**Error Message**

Another copy or paste is in progress.

**Description**

This error code is reported when a new copy or paste attempt is made before the previous one is completed.

**Possible Causes**

The copy and paste APIs are both asynchronous APIs. If the data to be copied or pasted is in large amount, the time required may be long. New copy or paste operations can be performed only after the previous operations have been completed.

**Solution**

1. Before copying or pasting data, check the status of the last copy or paste operation.
2. Perform subsequent operations only after the previous copy/paste operation is completed.

## 12900004 Copy Prohibited

**Error Message**

Replication is prohibited.

**Description**

This error code is reported when an attempt is made to copy data that cannot be copied.

**Possible Causes**

The target data cannot be copied, such as read-only data.

**Solution**

Make sure the target data allows the copy action.