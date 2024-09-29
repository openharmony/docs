# IPC Kit简介


## 基本概念

IPC（Inter-Process Communication）与RPC（Remote Procedure Call）用于实现跨进程通信，不同的是前者使用Binder驱动，用于设备内的跨进程通信，后者使用软总线驱动，用于跨设备跨进程通信。需要跨进程通信的原因是因为每个进程都有自己独立的资源和内存空间，其他进程不能随意访问不同进程的内存和资源，IPC/RPC便是为了突破这一点。

> **说明：**
> Stage模型不能直接使用本文介绍的IPC和RPC，需要通过以下能力实现相关业务场景：
>- IPC典型使用场景在后台服务，应用的后台服务通过IPC机制提供跨进程的服务调用能力。
>- RPC典型使用场景在<!--Del-->[<!--DelEnd-->多端协同<!--Del-->](../application-models/hop-multi-device-collaboration.md)<!--DelEnd-->，多端协同通过RPC机制提供远端接口调用与数据传递能力。


## 实现原理

IPC和RPC通常采用客户端-服务器（Client-Server）模型，在使用时，请求服务的（Client）一端进程可获取提供服务（Server）一端所在进程的代理（Proxy），并通过此代理读写数据来实现进程间的数据通信，更具体的讲，首先请求服务的（Client）一端会建立一个服务提供端（Server）的代理对象，这个代理对象具备和服务提供端（Server）一样的功能，若想访问服务提供端（Server）中的某一个方法，只需访问代理对象中对应的方法即可，代理对象会将请求发送给服务提供端（Server）；然后服务提供端（Server）处理接受到的请求，处理完之后通过驱动返回处理结果给代理对象；最后代理对象将请求结果进一步返回给请求服务端（Client）。通常，Server会先注册系统能力（System Ability）到系统能力管理者（System Ability Manager，缩写SAMgr）中，SAMgr负责管理这些SA并向Client提供相关的接口。Client要和某个具体的SA通信，必须先从SAMgr中获取该SA的代理，然后使用代理和SA通信。下文直接使用Proxy表示服务请求方，Stub表示服务提供方。

![IPC&RPC通信机制](figures/075sd302-aeb9-481a-bb8f-e552sdb61ead.PNG)


## 约束与限制

- 单个设备上跨进程通信时，传输的数据量最大约为1MB，过大的数据量请使用[匿名共享内存](../reference/apis-ipc-kit/js-apis-rpc.md#ashmem8)。

- 不支持在RPC中订阅匿名Stub对象（没有向SAMgr注册Stub对象）的死亡通知。

- 不支持把跨设备的Proxy对象传递回该Proxy对象所指向的Stub对象所在的设备，即指向远端设备Stub的Proxy对象不能在本设备内进行二次跨进程传递。