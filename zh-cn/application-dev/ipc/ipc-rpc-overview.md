# IPC Kit简介
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong2-->
<!--Adviser: @zhang_yixin13-->


## 基本概念

|缩写    |全称                        |中文描述     |说明  |
| -------|----------------------------|-------------|------|
|IPC     |Inter Process Communication |进程间通信   |指设备内的进程间通信。|
|RPC     |Remote Procedure Call       |远程过程调用 |指设备间的进程间通信。|
|Client  |Client                      |客户端       |请求服务的一端，称为代理（Proxy）。|
|Server  |Server                      |服务端       |提供服务的一端，称为Stub。|


> **说明：**
>
>- 使用IPC和RPC进行跨进程通信时，需要先调用元能力的连接服务接口获取Proxy对象。IPC和RPC的典型使用场景包括：
>
>  - IPC典型使用场景是后台服务，后台服务通过IPC机制提供单设备跨进程接口调用与数据传递能力。
>
>  - RPC典型使用场景是<!--Del-->[<!--DelEnd-->多端协同<!--Del-->](../application-models/hop-multi-device-collaboration.md)<!--DelEnd-->，多端协同通过RPC机制提供跨设备远端接口调用与数据传递能力。


## 实现原理

IPC和RPC用于实现跨进程通信。IPC使用Binder驱动，适用于设备内的跨进程通信；RPC使用软总线驱动，适用于跨设备的跨进程通信。每个进程拥有独立的资源和内存空间，其他进程无法直接访问，因此需要使用IPC和RPC实现跨进程通信。

IPC和RPC采用客户端-服务端（Client-Server）模型。在使用时，Client进程可以获取Server进程的代理（Proxy），通过Proxy读写数据和发起请求，Stub处理请求并应答结果，实现进程间通信。Proxy和Stub提供了一组由服务/业务自定义的接口，Proxy实现每一个具体的请求方法，Stub实现对应的每一个具体请求的处理方法以及应答数据的内容。

## 约束与限制

- 单个设备上跨进程通信时，传输的数据量最大为200KB。超过200KB的数据量传输可以使用[匿名共享内存](../reference/apis-ipc-kit/js-apis-rpc.md#ashmem8)。

- 不支持在RPC中订阅匿名Stub对象（没有向SAMgr注册的Stub对象）的[死亡通知](subscribe-remote-state.md)。

- 不支持把跨设备的Proxy对象回传到该Proxy对象指向的Stub对象所在的设备。

- 指向远端设备Stub的Proxy对象不能在本设备内二次跨进程传递。