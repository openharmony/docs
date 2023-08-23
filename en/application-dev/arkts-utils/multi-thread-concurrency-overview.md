# Multithread Concurrency Overview


## Overview

Concurrency models are used to implement concurrent tasks in different scenarios. Common concurrency models are classified into shared memory models and message passing models.

A typical message passing model is actor. It provides a relatively high degree of concurrency while eliminating a series of complex and occasional issues caused by locks. For these reasons, ArkTS chooses the actor model.

Due to the memory isolation feature of the actor model, cross-thread serialization is required.


## Data Transfer Objects

Data objects that can be transferred are classified into the following types: [common objects](#common-objects), [transferable objects](#transferable-objects), [shared objects](#shared-objects), and [native binding objects](#native-binding-objects).


### Common Objects

The structured clone algorithm is used for serialization of common objects. This algorithm recursively transfers an object by clone. It supports more object types than other serialization algorithms.

The following object types are supported: basic types except Symbol, Date, String, RegExp, Array, Map, Set, Object (simple objects only, for example, objects created using **{}** or **new Object**), ArrayBuffer, and typedArray. (Note that only attributes can be transferred for common objects. Prototypes and methods cannot be transferred.)


### Transferable Objects

Transferable objects are serialized through address transfer. It transfers the ownership of an object of the ArrayBuffer type, rather than the content in it. After the ownership is transferred, the object becomes unavailable in the sender and can be used only in the receiver.


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


### Native Binding Objects

Native binding objects are provided by the system. They are bound to underlying system services and enables direct access to these services.

Currently, native bound objects that support serialization include [Context](../application-models/application-context-stage.md) and [RemoteObject](../reference/apis/js-apis-rpc.md#remoteobject).

The **Context** object provides the context information about an application component. It provides a way to access system services and resources so that the application component can interact with the system. For details about how to obtain context information, see [Context (Stage Model)](../application-models/application-context-stage.md).

The **RemoteObject** object implements remote communication. It transfers the reference of an object between processes so that these processes can share the status and methods of the object. The service provider must inherit this class. For details about how to create a **RemoteObject** object, see [RemoteObject](../reference/apis/js-apis-rpc.md#remoteobject).

## TaskPool and Worker

ArkTS provides two multithread concurrency capabilities: **TaskPool** and **Worker**, which differ in their implementation features and use cases. For details, see [Comparison Between TaskPool and Worker](taskpool-vs-worker.md).
