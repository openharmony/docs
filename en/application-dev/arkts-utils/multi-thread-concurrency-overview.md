# Multithread Concurrency Overview


## Overview

Concurrency models are used to implement concurrent tasks in different scenarios. Common concurrency models are classified into shared memory models and message passing models.

A typical message passing model is actor. It provides a relatively high degree of concurrency while eliminating a series of complex and occasional issues caused by locks. For these reasons, ArkTS chooses the actor model.

Due to the memory isolation feature of the actor model, cross-thread serialization is required.


## Data Transfer Objects

Data objects that can be transferred are classified into three types: [common objects](#common-objects), [transferable objects](#transferable-objects), and [shared objects](#shared-objects).


### Common Objects

The structured clone algorithm is used for serialization of common objects. This algorithm recursively transfers an object by clone. It supports more object types than other serialization algorithms.

The following object types are supported: basic types except Symbol, Date, String, RegExp, Array, Map, Set, Object (simple objects only, for example, objects created using **{}** or **new Object**), ArrayBuffer, and typedArray. (Note that only attributes can be transferred for common objects. Prototypes and methods cannot be transferred.)


### Transferable Objects

Transferable objects are serialized through address transfer. It transfers the ownership of an object of the ArrayBuffer type object, rather than the content in it. After the ownership is transferred, the object becomes unavailable in the sender and can be used only in the receiver.


```js
// Define a transferable object.
let buffer = new ArrayBuffer(100);
```


### Shared Objects

A shared object is of the **SharedArrayBuffer** type, has a fixed length, and can store any type of data including numbers and strings.

An object of the SharedArrayBuffer type can be transferred between multiple threads. The objects before and after the transfer point to the same memory block, achieving memory sharing.

If multiple operations are simultaneously performed to modify data stored in an object of the SharedArrayBuffer type, you must use atomics to ensure data synchronization. Atomics ensure that the current operation is complete before the next operation starts.


```js
// Define a shared object, which uses atomics to ensure data synchronization.
let sharedBuffer = new SharedArrayBuffer(1024);
```


## TaskPool and Worker

ArkTS provides two multithread concurrency capabilities: **TaskPool** and **Worker**, which differ in their implementation features and use cases. For details, see [Comparison Between TaskPool and Worker](taskpool-vs-worker.md).
