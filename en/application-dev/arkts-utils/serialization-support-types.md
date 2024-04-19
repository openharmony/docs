# Serialization Types Supported by TaskPool and Worker

Both TaskPool and Worker are developed on the actor model. Due to the memory isolation feature of the actor model, cross-thread serialization is required for the execution of multithreaded tasks and the transmission of results. Data objects that can be transferred are classified into the following types: [common objects](#common-objects), [transferable objects](#transferable-objects), [shared objects](#shared-objects), [native binding objects](#native-binding-objects), and [sendable objects](#sendable-objects).


## Common Objects

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


## Transferable Objects

Transferable objects are ArrayBuffer-type objects whose ownership (but not its content) can be transferred. They are serialized through address transfer. After the ownership of an object is transferred, it becomes unavailable in the sender and can be used only in the receiver.


```ts
// Define a transferable object.
let buffer: ArrayBuffer = new ArrayBuffer(100);
```


## Shared Objects

A shared object is of the SharedArrayBuffer type, has a fixed length, and can store any type of data including numbers and strings.

An object of the SharedArrayBuffer type can be transferred between multiple threads. The objects before and after the transfer point to the same memory block, achieving memory sharing.

If multiple operations are simultaneously performed to modify data stored in an object of the SharedArrayBuffer type, you must use atomic operations to ensure data synchronization. Atomic operations ensure that the current operation is complete before the next operation starts.


```ts
// Define a shared object, which uses atomic operations to ensure data synchronization.
let sharedBuffer: SharedArrayBuffer = new SharedArrayBuffer(1024);
```


## Native Binding Objects

Native binding objects are provided by the system. They are bound to underlying system services and enable direct access to these services.

Currently, native bound objects that support serialization include [Context](../application-models/application-context-stage.md), [RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject), and [PixelMap](../reference/apis-image-kit/js-apis-image.md#pixelmap7).

The **Context** object provides the context information of an application component. It provides a way to access system services and resources so that the application component can interact with the system. For details about how to obtain context information, see [Context (Stage Model)](../application-models/application-context-stage.md).

The **RemoteObject** object implements remote communication. It transfers the reference of an object between processes so that these processes can share the status and methods of the object. The service provider must inherit this class. For details about how to create a **RemoteObject** object, see [RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject).

The **PixelMap** object can read or write image data and obtain image information. It is usually used to display images in applications or systems. For details about how to create a **PixelMap** object, see the [API Reference](../reference/apis-image-kit/js-apis-image.md#imagecreatepixelmap8).


## Sendable Objects

Sendable objects, decorated by the ArkTS decorator [@Sendable](../arkts-utils/arkts-sendable.md), can be transferred between threads. Sendable objects support two transfer modes: reference transfer (not supported yet) and serialized transfer. Currently, the following types are sendable : boolean, number, string, Bigint, and [SendableClass] (../arkts-utils/arkts-sendable.md#basic-concepts).


```ts
// Use @Sendable to decorate a class object.
@Sendable
class TestClass {
  name: string = "TestClass ";
  num: number = 5;
  printName() {
    console.info("sendable: this class name is: " + this.name);
  }
}
```
