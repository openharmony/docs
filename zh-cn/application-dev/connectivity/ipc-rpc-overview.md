# IPC与RPC通信概述


## 基本概念

IPC（Inter-Process Communication）与RPC（Remote Procedure Call）用于实现跨进程通信，不同的是前者使用Binder驱动，用于设备内的跨进程通信，后者使用软总线驱动，用于跨设备跨进程通信。需要跨进程通信的原因是因为每个进程都有自己独立的资源和内存空间，其他进程不能随意访问不同进程的内存和资源，IPC/RPC便是为了突破这一点。IPC和RPC通常采用客户端-服务器（Client-Server）模型，在使用时，请求服务的（Client）一端进程可获取提供服务（Server）一端所在进程的代理（Proxy），并通过此代理读写数据来实现进程间的数据通信，更具体的讲，首先请求服务的（Client）一端会建立一个服务提供端（Server）的代理对象，这个代理对象具备和服务提供端（Server）一样的功能，若想访问服务提供端（Server）中的某一个方法，只需访问代理对象中对应的方法即可，代理对象会将请求发送给服务提供端（Server）；然后服务提供端（Server）处理接受到的请求，处理完之后通过驱动返回处理结果给代理对象；最后代理对象将请求结果进一步返回给请求服务端（Client）。通常，Server会先注册系统能力（System Ability）到系统能力管理者（System Ability Manager，缩写SAMgr）中，SAMgr负责管理这些SA并向Client提供相关的接口。Client要和某个具体的SA通信，必须先从SAMgr中获取该SA的代理，然后使用代理和SA通信。下文直接使用Proxy表示服务请求方，Stub表示服务提供方。


## 约束与限制

单个设备上跨进程通信时，传输的数据量最大约为1MB，过大的数据量请使用匿名共享内存。不支持的第一个场景是在RPC中订阅匿名Stub对象的死亡通知。
不支持把跨设备的Proxy对象传递回该Proxy对象所指向的Stub对象所在的设备，即指向远端A侧Stub的Proxy对象不能在本设备内进行二次跨进程传递。

## 使用建议

首先，需要编写接口类，接口类中必须定义消息码，供通信双方标识操作，还可以有未实现的的方法，还需要实现AsObject方法及OnRemoteRequest方法，必然地，也需要编写Proxy端，实现接口类中的方法和AsObject方法，也可以封装一些额外的方法用于调用SendRequest向对端发送数据。以上三者都具备后，便可以向SAMgr注册SA了，此时的注册应该在Stub所在进程完成。最后，在需要的地方从SAMgr中获取Proxy，便可通过Proxy实现与Stub的跨进程通信了。

相关步骤：

- 实现接口类：需继承IRemoteBroker，需定义消息码，可声明不在此类实现的方法。

- 实现服务提供端（Stub）：需继承IRemoteStub或者RemoteObject，需重写AsObject方法及OnRemoteRequest方法。

- 实现服务请求端（Proxy）：需继承IRemoteProxy或RemoteProxy，需重写AsObject方法，封装所需方法调用SendRequest。

- 注册SA：申请SA的唯一ID，向SAMgr注册SA。

- 获取SA：通过SA的ID和设备ID获取Proxy，使用Proxy与远端通信


## 相关模块

[分布式任务调度子系统](https://gitee.com/openharmony/ability_dmsfwk)
