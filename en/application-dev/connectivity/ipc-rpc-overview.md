# IPC & RPC Overview


## Basic Concepts

Inter-process communication (IPC) and remote procedure call (RPC) are used to implement cross-process communication. IPC uses the Binder driver to implement inter-process communication within a device, whereas RPC uses the intelligent software bus driver to implement inter-process communication across devices. IPC and RPC generally use the client-server model for communication. The client (service requester) obtains the proxy of the server (service provider) and uses this proxy to read and write data. The server registers system abilities (SAs) with the system ability manager (SAMgr), which manages the SAs and provides interfaces for clients. To interact with an SA, the client must obtain the proxy of the SA from SAMgr. In OpenHarmony documents, proxy represents the service requester, and stub represents the service provider.


## Constraints

The data transmitted for inter-process communication within a device cannot exceed 1 MB. If more data needs to be transmitted, use the anonymous shared memory.
The cross-device proxy object cannot be passed to the device hosting the stub object pointed by this proxy object.


## Related Modules

Distributed Scheduler
