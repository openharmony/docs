# RPC Error Codes

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=ceec5d18179ba29b1eca79fa9240e27795b5216c translatedAt=2026-07-28T02:21:13.500Z pushedAt=2026-07-29T07:23:03.340Z -->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## Overview

Remote Procedure Call (RPC) error codes are used to identify various exceptions that occur during IPC communication. This module provides standard error code definitions related to IPC/RPC communication, helping you quickly locate and resolve communication issues.

## 1900001 Failed to Call mmap

**Error Message**

Failed to call mmap.

**Description**

The mmap function failed.

**Possible Causes**

1. The mapping area is too large.

2. There is no sufficient memory for mapping.

**Solution**

1. Check whether an excessively large memory size is specified when **Ashmem::create()** is called.

2. Check whether the system has sufficient memory for the mapping operation.

## 1900002 Failed to Call ioctl

**Error Message**

Failed to call ioctl.

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

Failed to write data to the shared memory.

**Description**

Failed to write data to the shared memory.

**Possible Causes**

1. The size of a single write or total size of continuous writes exceeds the size of the shared memory.

2. The PROT_WRITE mode is not enabled for the shared memory.

**Solution**

1. Check whether the content written to the shared memory exceeds the total mapped size.

2. Check that PROT_WRITE is enabled for the shared memory.

## 1900004 Failed to Read Data from the Shared Memory

**Error Message**

Failed to read data from the shared memory.

**Description**

Failed to read data from the shared memory.

**Possible Causes**

1. The total content read in a single read or in consecutive reads exceeds the mapped shared memory size.

2. The PROT_READ mode is not enabled for the shared memory.

**Solution**

1. Check whether the content currently being read from the shared memory has exceeded the total mapped size.

2. Check that PROT_READ is enabled for the shared memory.

## 1900005 IPC Object Permission Error

**Error Message**

Operation allowed only for the proxy object.

**Description**

This operation is allowed only on the **RemoteProxy** object.

**Possible Causes**

A method supported only by the **RemoteProxy** object is called for the **RemoteObject** object.

**Solution**

Check whether a method supported only by the **RemoteProxy** object is called for the **RemoteObject** object.

## 1900006 IPC Object Permission Error

**Error Message**

Operation allowed only for the remote object.

**Description**

This operation is allowed only on the **RemoteObject** object.

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

2. The remote object was destroyed and then re-created, and the proxy object held by the local end has expired.

**Solution**

1. Check whether the remote object has been destroyed.

2. Check whether a listener for the death event of the remote object is registered. If the remote object is re-created after being destroyed, obtain the proxy object again and update the local reference.

## 1900008 Invalid IPC Object

**Error Message**

The proxy or remote object is invalid.

**Description**

Invalid proxy or remote object.

**Possible Causes**

1. The proxy object is invalid.

2. The remote object has been destroyed.

**Solution**

1. Check whether an exception occurs when the proxy object is obtained.

2. Check whether the remote object has been destructed.

## 1900009 Failed to Write Data to MessageSequence

**Error Message**

Failed to write data to the message sequence.

**Description**

Failed to write data to **MessageSequence**.

**Possible Causes**

The default sequence space is full.

**Solution**

Use the method provided by **MessageSequence** to check whether **MessageSequence** has sufficient space.

## 1900010 Failed to Read Data from MessageSequence

**Error Message**

Failed to read data from the message sequence.

**Description**

Failed to read data from **MessageSequence**.

**Possible Causes**

The data read sequence is different from the data write sequence.

**Solution**

Check that the data read sequence is the same as the data write sequence.

## 1900011 Memory Allocation Failed

**Error Message**

Memory allocation failed.

**Description**

Failed to allocate memory during serialization.

**Possible Causes**

The data to write is too large, which depends on the available contiguous memory on the current heap.

**Solution**

Check whether the data to write is too large or whether parameters are set improperly.

## 1900012 JS Callback Execution Failed

**Error Message**

Failed to call the JS callback function.

**Description**

Failed to invoke the JS callback.

**Possible Causes**

The JS function of the service returns a failure message.

**Solution**

Check whether the JS function is successfully executed.

## 1900013 Failed to Invoke dup

**Error Message**

Failed to call dup.

**Description**

Failed to call dup.

**Possible Causes**

1. The file handle resources of the process are used up.

2. The specified **fd** is closed.

**Solution**

1. Check whether the input parameter **fd** is still valid.

2. Check whether the process has exhausted its file descriptor resources.