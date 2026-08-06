# Glossary

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8142f3daf812f1fee026bbca8a8ec3c84d38922c translatedAt=2026-08-04T13:29:19.347Z pushedAt=2026-08-05T07:00:22.481Z -->

## D

### DeathRecipient

A callback mechanism for subscribing to the lifecycle status of a remote stub object. After the proxy registers a callback, the callback is automatically invoked when the process hosting the remote stub exits or when the SoftBus connection used by RPC is disconnected. This mechanism allows the proxy to release local proxy objects and related resources.

## I

### Inter Process Communication (IPC)

An intra-device inter-process communication mechanism implemented on top of the Binder driver. IPC follows a client-server model. The client obtains a proxy for the server, sends requests through the proxy, and the server-side stub processes the requests and returns the results. IPC is typically used for background services to provide cross-process API invocation and data transfer within a device.

## R

### Remote Procedure Call (RPC)

A cross-device inter-process communication mechanism implemented on top of SoftBus. RPC uses the same client-server architecture and proxy-stub model as IPC. It is typically used for distributed scenarios that require remote API invocation and data transfer across devices. Unlike IPC, which communicates only within a device through the Binder driver, RPC communicates across devices through SoftBus.

## S

### Stub

In the IPC/RPC communication model, the server-side object is called a stub, and the client-side object is called a proxy. The stub receives requests from the proxy, processes them, and returns the results. The stub implements the request handling logic, while the proxy provides the corresponding request invocation methods.