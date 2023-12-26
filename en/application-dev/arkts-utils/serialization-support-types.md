# Serialization Types Supported by TaskPool and Worker
Both **TaskPool** and **Worker** are developed on the actor model. Due to the memory isolation feature of the actor model, cross-thread serialization is required for the execution of multithread tasks and the transmission of results. Data objects that can be transferred are classified into the following types: [common objects](#common-objects), [transferable objects](#transferable-objects), [shared objects](#shared-objects), and [native binding objects](#native-binding-objects).


### Common Objects

The structured clone algorithm is used for serialization of common objects. This algorithm recursively transfers an object by clone. It supports more object types than other serialization algorithms.

The following object types are supported:

- Basic types except Symbol

- Date

- String

- RegExp

- Array

- Map

- Set

- Object (simple objects only, for example, objects created using **{}** or **new Object**)

  Note that only attributes can be transferred for common objects. Prototypes and methods cannot be transferred.

- ArrayBuffer

- typedArray


### Transferable Objects

Transferable objects are ArrayBuffer-type objects whose ownership (but not its content) can be transferred. They are serialized through address transfer. After the ownership of an object is transferred, it becomes unavailable in the sender and can be used only in the receiver.


```ts
// Define a transferable object.
let buffer: ArrayBuffer = new ArrayBuffer(100);
```


### Shared Objects

A shared object is of the SharedArrayBuffer type, has a fixed length, and can store any type of data including numbers and strings.

An object of the SharedArrayBuffer type can be transferred between multiple threads. The objects before and after the transfer point to the same memory block, achieving memory sharing.

If multiple operations are simultaneously performed to modify data stored in an object of the SharedArrayBuffer type, you must use atomics to ensure data synchronization. Atomics ensure that the current operation is complete before the next operation starts.


```ts
// Define a shared object, which uses atomics to ensure data synchronization.
let sharedBuffer: SharedArrayBuffer = new SharedArrayBuffer(1024);
```

### Native Binding Objects

Native binding objects are provided by the system. They are bound to underlying system services and enable direct access to these services.

Currently, native bound objects that support serialization include [Context](../application-models/application-context-stage.md) and [RemoteObject](../reference/apis/js-apis-rpc.md#remoteobject).

The **Context** object provides the context information of an application component. It provides a way to access system services and resources so that the application component can interact with the system. For details about how to obtain context information, see [Context (Stage Model)](../application-models/application-context-stage.md).

The **RemoteObject** object implements remote communication. It transfers the reference of an object between processes so that these processes can share the status and methods of the object. The service provider must inherit this class. For details about how to create a **RemoteObject** object, see [RemoteObject](../reference/apis/js-apis-rpc.md#remoteobject).
