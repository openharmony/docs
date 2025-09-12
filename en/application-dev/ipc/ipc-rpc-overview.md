# Introduction to IPC Kit
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--SE: @zhaopeng_gitee-->
<!--TSE: @maxiaorong2-->


## Basic Concepts

|Abbreviation   |Full Name                       |Description    |Meaning |
| -------|----------------------------|-------------|------|
|IPC     |Inter Process Communication |Inter-process communication  |Inter-process communication within a device.|
|RPC     |Remote Procedure Call       |Remote procedure call|Inter-process communication across devices.|
|Client  |Client                      |Client      |A proxy that requests services.|
|Server  |Server                      |Server      |A stub that provides services.|


> **NOTE**
>
>- Before using IPC and RPC for inter-process communication, you need to call the ability API for service connection to obtain the proxy object. IPC and RPC are typically used in the following scenarios:
>
>  - IPC is typically used in background services, which use the IPC mechanism to provide the capability of cross-process API calling and data transfer on a single device.
>
>  - RPC is used <!--Del-->[<!--DelEnd-->in multi-device collaboration<!--Del-->](../application-models/hop-multi-device-collaboration.md)<!--DelEnd--> to implement remote API calls and data transfer cross devices.


## Working Principles

Both IPC and RPC implement cross-process communication. IPC uses the Binder driver to implement cross-process communication in a device, while RPC uses the DSoftBus driver to implement cross-process communication across devices. Each process has its own resources and independent memory space, and one process is not allowed to access the resources and memory space of other processes. That is why cross-process communication is required.

IPC and RPC use the client-server model where the client process obtains the proxy of the process where the server is located. The stub object uses the proxy to read and write data to implement inter-process communication. The proxy and stub provide a group of APIs defined by services. The proxy implements each specific request method, and the stub implements the processing method of each specific request and the content of the response data.

## Constraints

- A maximum of 200 KB data can be transferred in cross-process communication on a single device. If the amount of data to be transmitted is larger than 200 KB, use [anonymous shared memory](../reference/apis-ipc-kit/js-apis-rpc.md#ashmem8).

- Subscription to [death notifications](subscribe-remote-state.md) of anonymous stub objects (not registered with SAMgr) is not supported in RPC.

- During cross-process communication, a proxy object cannot be passed back to the device that hosts the stub object pointed to by the proxy object.

- The proxy object pointing to the stub object of the remote device cannot be passed across processes twice on the local device.
