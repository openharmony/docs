# RPC Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

The APIs of the **rpc** module return exceptions since API version 9.

## 1900001 Failed to Call mmap

**Error Message**

Call mmap function failed.

**Description**

The mmap function failed.

**Possible Causes**

1. The mapping area is too large.
2. There is no sufficient memory for mapping.

**Solution**

1. Check whether the memory specified in **Ashmem::create()** is too large.
2. Check whether the system has sufficient memory for the mapping operation.

## 1900002 Failed to Call ioctl

**Error Message**

Call os ioctl function failed.

**Description**

Failed to call **ioctl** with the shared memory file descriptor.

**Possible Causes**

1. Invalid kernel parameters are set.
2. The specified type does not comply with the types specified when the shared memory is mapped.

**Solution**

1. Check whether the specified parameters are **PROT_EXEC**, **PROT_READ**, and **PROT_WRITE** of the **Ashmem** class.
2. Check whether the type specified is one of the types specified when the shared memory is mapped.

## 1900003 Failed to Write Data to the Shared Memory

**Error Message**

Write to ashmem failed.

**Description**

Failed to write data to the shared memory.

**Possible Causes**

1. The size of a single write or total size of continuous writes exceeds the size of the shared memory.
2. The PROT_WRITE mode is not enabled for the shared memory.

**Solution**

1. Check whether the data to be written to the shared memory exceeds the total size of the shared memory mapped.
2. Check that PROT_WRITE is enabled for the shared memory.

## 1900004 Failed to Read Data from the Shared Memory

**Error Message**

Read from ashmem failed.

**Description**

Failed to read data from the shared memory.

**Possible Causes**

1. The size of a single write or total size of continuous writes exceeds the size of the shared memory.
2. The PROT_READ mode is not enabled for the shared memory.

**Solution**

1. Check whether the data to be written to the shared memory exceeds the total size of the shared memory mapped.
2. Check that PROT_READ is enabled for the shared memory.

## 1900005 Operation Allowed Only for the Proxy Object

**Error Message**

Only proxy object permitted.

**Description**

This operation is allowed only on the proxy object.

**Possible Causes**

A method supported only by the **RemoteProxy** object is called for the **RemoteObject** object.

**Solution**

Check whether a method supported only by the **RemoteProxy** object is called for the **RemoteObject** object.

## 1900006 Operation Allowed Only for the Remote Object

**Error Message**

Only remote object permitted.

**Description**

This operation is allowed only on the remote object.

**Possible Causes**

A method supported only by the **RemoteObject** object is called for the **RemoteProxy** object.

**Solution**

Check whether a method supported only by the **RemoteObject** object is called for the **RemoteProxy** object.

## 1900007 Failed to Communicate with the Remote Object

**Error Message**

Communication failed.

**Description**

Failed to communicate with the remote object over IPC.

**Possible Causes**

1. The remote object has been destroyed.
2. The remote object is re-created, but the proxy object held by the local end has expired.

**Solution**

1. Check whether the remote object has been destroyed.
2. Check whether an observer for listening for the dead status of the remote object is registered, and whether the remote object is destructed and created again.

## 1900008 Invalid IPC Object

**Error Message**

Proxy or remote object is invalid.

**Description**

The proxy or remote object is invalid.

**Possible Causes**

1. The proxy object is invalid.
2. The remote object has been destroyed.

**Solution**

1. Check whether an exception occurs when the proxy object is obtained.
2. Check whether the remote object is destructed.

## 1900009 Failed to Write Data to MessageSequence

**Error Message**

Write data to message sequence failed.

**Description**

Failed to write data to **MessageSequence**.

**Possible Causes**

The default **MessageSequence** space is full.

**Solution**

Use the method provided by **MessageSequence** to check whether **MessageSequence** has sufficient space.

## 1900010 Failed to Read Data from MessageSequence

**Error Message**

Read data from message sequence failed.

**Description**

Failed to read data from **MessageSequence**.

**Possible Causes**

The data read sequence is different from the data write sequence.

**Solution**

Check that the data read sequence is the same as the data write sequence.

## 1900011 Memory Allocation Failed

**Error Message**

Sequence memory alloc failed.

**Description**

Failed to allocate memory during serialization.

**Possible Causes**

The data to write is too large.

**Solution**

Check whether the data to write is too large or whether parameters are set improperly.

## 1900012 JS Callback Failed

**Error Message**

Call JS callback function failed.

**Description**

Failed to invoke the JS callback.

**Possible Causes**

The JS function of the service returns a failure message.

**Solution**

Check whether the JS function is successfully executed.

## 1900013 Failed to Invoke dup

**Error Message**

Call os dup function failed.

**Description**

Failed to call dup.

**Possible Causes**

1. The file handle resources of the process are used up.
2. The specified **fd** is closed.

**Solution**

1. Check whether the input parameter** fd** is valid.
2. Check whether there are file handle resources of the process.
