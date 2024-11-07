# Introduction to IPC Kit


## Basic Concepts

Inter-process communication (IPC) and remote procedure call (RPC) implement cross-process communication. IPC uses the Binder driver to implement cross-process communication within a device, whereas RPC uses the DSoftBus driver to implement cross-process communication across devices. Cross-process communication is required because each process has its own resources and independent memory space and one process is not allowed to access the resources and memory space of other processes.

> **NOTE**
> The applications based on the stage model cannot use IPC or RPC directly, and must use the following capabilities to implement related service scenarios:
>- IPC is used in background services to provide service calling across processes.
>- RPC is used in <!--Del-->[<!--DelEnd-->multi-device collaboration<!--Del-->](../application-models/hop-multi-device-collaboration.md)<!--DelEnd--> to implement remote API calling and data transfer.


## Working Principles

IPC and RPC use the client-server model, where the client (service requester, that is, the process that requests a service) obtains the proxy of the server (service provider, that is, the process that provides the service) and uses the proxy to read and write data to implement data communication across processes. More specifically, you need to construct a proxy object of the server for the client. The proxy object has the same functions as the server. To access an API of the server, the client only needs to access the API of the proxy object. The proxy object forward the request to the server, and the server processes the received request and returns the processing result to the proxy object through the driver. Then, the proxy object forwards the processing result to the client. 

The server registers system abilities (SAs) with the system ability manager (SAMgr), which manages the SAs and provides APIs for clients. To communicate with a specific SA, the client must obtain the proxy of the SA from SAMgr. 

In the following, proxy represents the service requester, and stub represents the service provider.

![IPC & RPC communication mechanisms](figures/IPC_RPC_communication.png)


## Constraints

- A maximum of 1 MB data can be transferred in cross-process communication on a single device. If the amount of data to be transmitted is larger than 1 MB, use [anonymous shared memory](../reference/apis-ipc-kit/js-apis-rpc.md#ashmem8).

- Subscription to death notifications of anonymous stub objects (not registered with SAMgr) is not supported in RPC.

- During cross-process communication, a proxy object cannot be passed back to the device that hosts the stub object pointed to by the proxy object. That is, the proxy object pointing to the stub object of the remote device cannot be passed across processes twice on the local device.
