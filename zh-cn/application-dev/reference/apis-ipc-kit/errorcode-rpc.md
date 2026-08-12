# RPC错误码
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 概述

RPC（Remote Procedure Call）错误码用于标识IPC通信过程中发生的各类异常情况。本模块提供了IPC/RPC通信相关的标准错误码定义，帮助开发者快速定位和解决通信问题。

## 1900001 系统调用mmap失败

**错误信息**

Failed to call mmap.

**错误描述**

执行系统调用mmap失败。

**可能原因**

1. 映射区域过大。
2. 系统内存压力大，没有足够内存可以用来进行映射。

**处理步骤**

1. 请检查调用Ashmem::create()时是否指定了超过系统限制的内存大小。
2. 请检查执行映射时系统是否有足够的内存可用。

## 1900002 系统调用ioctl失败

**错误信息**

Failed to call ioctl.

**错误描述**

在共享内存文件描述符上执行系统调用ioctl失败。

**可能原因**

1. 设置的参数为内核非法参数。
2. 设置的类型超过了共享内存映射时指定的类型。

**处理步骤**

1. 请检查调用指定的参数是否来自Ashmem类的PROT_EXEC、PROT_READ和PROT_WRITE。
2. 请检查指定的参数是否为映射共享内存时所指类型的子集。

## 1900003 共享内存写数据失败

**错误信息**

Failed to write data to the shared memory.

**错误描述**

向共享内存写数据失败。

**可能原因**

1. 单次写或者连续写的总内容超过了映射的共享内存大小。
2. 没有对共享内存设置PROT_WRITE模式。

**处理步骤**

1. 请检查当前向共享内存写入的内容是否已经超过了映射的总大小。
2. 请检查是否设置了PROT_WRITE保护权限。

## 1900004 共享内存读数据失败

**错误信息**

Failed to read data from the shared memory.

**错误描述**

从共享内存读数据失败。

**可能原因**

1. 单次读或者连续读的总内容超过了映射的共享内存大小。
2. 没有对共享内存设置PROT_READ模式。

**处理步骤**

1. 请检查当前从共享内存读取的内容是否已经超过了映射的总大小。
2. 请检查是否设置了PROT_READ保护权限。

## 1900005 IPC对象权限错误

**错误信息**

Operation allowed only for the proxy object.

**错误描述**

只有RemoteProxy对象允许该操作。

**可能原因**

在RemoteObject对象上调用了只有RemoteProxy对象支持的方法。

**处理步骤**

请检查是否在RemoteObject对象上调用了只有RemoteProxy对象支持的方法。

## 1900006 IPC对象权限错误

**错误信息**

Operation allowed only for the remote object.

**错误描述**

只有RemoteObject对象允许该操作。

**可能原因**

在RemoteProxy对象上调用了只有RemoteObject对象支持的方法。

**处理步骤**

请检查是否在RemoteProxy对象上调用了只有RemoteObject对象支持的方法。

## 1900007 远端对象通信失败

**错误信息**

Communication failed.

**错误描述**

和远程对象进行进程间通信失败。

**可能原因**

1. 远程对象已经销毁。
2. 远程对象发生了销毁然后重新创建，本地持有的代理对象已经过期。

**处理步骤**

1. 请检查远程对象是否已经销毁。
2. 请检查是否注册了死亡监听。如果远程对象被销毁后重新创建，需要重新获取代理对象并更新本地引用。

## 1900008 非法的IPC对象

**错误信息**

The proxy or remote object is invalid.

**错误描述**

无效的代理对象或远程对象。

**可能原因**

1. 代理对象已经失效。
2. 远程对象已经销毁。

**处理步骤**

1. 请检查Proxy对象获取过程是否有异常。
2. 请检查远程对象是否已经析构。

## 1900009 向MessageSequence写入数据失败

**错误信息**

Failed to write data to the message sequence.

**错误描述**

向MessageSequence写数据失败。

**可能原因**

MessageSequence默认空间已满。

**处理步骤**

请使用MessageSequence提供的获取缓冲区空间相关方法确认是否还有剩余空间。

## 1900010 读取MessageSequence数据失败

**错误信息**

Failed to read data from the message sequence.

**错误描述**

读取MessageSequence数据失败。MessageSequence采用顺序读写方式，读取顺序必须与写入顺序严格一致。

**可能原因**

读取和写入顺序不一致。

**处理步骤**

请检查读取的顺序和写入的顺序保持严格一致。

## 1900011 内存分配失败

**错误信息**

Memory allocation failed.

**错误描述**

序列化过程中内存分配失败。

**可能原因**

写入的数据过大，数据取决于当前堆上还有多少可以连续分配的内存。

**处理步骤**

请检查写入的数据或者设置的参数是否过大。

## 1900012 JS回调方法执行失败

**错误信息**

Failed to call the JS callback function.

**错误描述**

执行JS回调方法失败。

**可能原因**

业务的JS方法返回失败。

**处理步骤**

请检查业务JS方法是否执行成功。

## 1900013 系统调用dup失败

**错误信息**

Failed to call dup.

**错误描述**

执行系统调用dup失败。

**可能原因**

1. 进程的文件句柄资源已经耗尽。
2. 入参fd已经被关闭。

**处理步骤**

1. 请检查入参fd是否依然有效（如：fd值大于等于0，且未被关闭）。
2. 请排查进程是否已经耗尽了fd资源。