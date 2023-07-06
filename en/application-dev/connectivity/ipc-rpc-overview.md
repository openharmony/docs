# IPC & RPC Overview


## Basic Concepts

Inter-process communication (IPC) and remote procedure call (RPC) are used to implement cross-process communication. IPC uses the Binder driver to implement cross-process communication within a device, whereas RPC uses the DSoftBus driver to implement cross-process communication across devices. Cross-process communication is required because each process has its own independent resources and memory space and one process is not allowed to access the resources and memory space of other processes.

> **NOTE**
> The applications in the stage model cannot use IPC or RPC directly, and must use the following capabilities to implement related service scenarios:
>- [Background services](../application-models/background-services.md): use IPC to implement service invocation across processes.
>- [Multi-device collaboration](../application-models/hop-multi-device-collaboration.md): uses RPC to call remote interfaces and transfer data.


## Implementation Principles

IPC and RPC usually use the client-server model, where the client (service requester, that is, the process that requests a service) obtains the proxy of the server (service provider, that is, the process that provides the service) and uses the proxy to read and write data to implement data communication across processes. More specifically, the client constructs a proxy object of the server. The proxy object has the same functions as the server. To access a certain API of the server, you only need to access the corresponding API in the proxy object. The proxy object sends the request to the server, and the server processes the received request and returns the processing result to the proxy object through the driver. Then, the proxy object forwards the processing result to the client. The server registers system abilities (SAs) with the system ability manager (SAMgr), which manages the SAs and provides APIs for clients. To communicate with a specific SA, the client must obtain the proxy of the SA from SAMgr. In the following sections, proxy represents the service requester, and stub represents the service provider.

![IPC & RPC communication mechanisms] (figures/IPC_RPC_communication.PNG)


## Constraints

- A maximum of 1 MB data can be transferred in cross-process communication on a single device. If the amount of data to be transmitted is larger than 1 MB, use [anonymous shared memory](../reference/apis/js-apis-rpc.md#ashmem8).

- Subscription to death notifications of anonymous stub objects (not registered with SAMgr) is prohibited in RPC.

- During cross-process communication across processes, a proxy object cannot be passed back to the device that hosts the stub object pointed by the proxy object. That is, the proxy object pointing to the stub object of the remote device cannot be passed across processes twice on the local device.
