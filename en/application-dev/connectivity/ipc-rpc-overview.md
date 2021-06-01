# IPC & RPC Overview<a name="EN-US_TOPIC_0000001103870800"></a>

-   [Basic Concepts](#section175012297491)
-   [Limitations and Constraints](#section2029921310472)
-   [Related Modules](#section1189019299446)

## Basic Concepts<a name="section175012297491"></a>

The inter-process communication \(IPC\) and remote procedure call \(RPC\) mechanisms are used to implement cross-process communication. The difference between them lies in that IPC uses the Binder driver to implement cross-process communication within a device, whereas RPC uses the Intelligent Soft Bus driver to implement cross-process communication across devices. IPC and RPC generally use a client-server model. The service requester \(client\) can obtain the proxy of the service provider \(server\) and use the proxy to read and write data, thus implementing data communication between processes. Generally, the server registers system abilities \(SAs\) with the system ability manager \(SAMgr\), which manages the SAs and provides APIs for the client. To communicate with a specific SA, the client must obtain the proxy of the SA from SAMgr. In this document, Proxy represents the service requester, and Stub represents the service provider.

## Limitations and Constraints<a name="section2029921310472"></a>

Currently, cross-device RPC communication is not supported.

## Related Modules<a name="section1189019299446"></a>

Distributed Scheduler subsystem

