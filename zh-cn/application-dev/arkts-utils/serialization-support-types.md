# TaskPool和Worker支持的序列化类型
TaskPool和Worker的底层模型为Actor模型，基于Actor模型的内存隔离特性，执行多线程任务和取得结果需要通过跨线程序列化传输。目前支持传输的数据对象可以分为[普通对象](#普通对象)、[可转移对象](#可转移对象)、[可共享对象](#可共享对象)、[Native绑定对象](#native绑定对象)四种。


### 普通对象

普通对象传输采用标准的结构化克隆算法（Structured Clone）进行序列化，此算法可以通过递归的方式拷贝传输对象，相较于其他序列化的算法，支持的对象类型更加丰富。

序列化支持的类型包括：除Symbol之外的基础类型、Date、String、RegExp、Array、Map、Set、Object（仅限简单对象，比如通过“{}”或者“new Object”创建，普通对象仅支持传递属性，不支持传递其原型及方法）、ArrayBuffer、TypedArray。


### 可转移对象

可转移对象（Transferable object）传输采用地址转移进行序列化，不需要内容拷贝，会将ArrayBuffer的所有权转移给接收该ArrayBuffer的线程，转移后该ArrayBuffer在发送它的线程中变为不可用，不允许再访问。


```ts
// 定义可转移对象
let buffer: ArrayBuffer = new ArrayBuffer(100);
```


### 可共享对象

共享对象SharedArrayBuffer，拥有固定长度，可以存储任何类型的数据，包括数字、字符串等。

共享对象传输指SharedArrayBuffer支持在多线程之间传递，传递之后的SharedArrayBuffer对象和原始的SharedArrayBuffer对象可以指向同一块内存，进而达到内存共享的目的。

SharedArrayBuffer对象存储的数据在同时被修改时，需要通过原子操作保证其同步性，即下个操作开始之前务必需要等到上个操作已经结束。


```ts
// 定义可共享对象，可以使用Atomics进行操作
let sharedBuffer: SharedArrayBuffer = new SharedArrayBuffer(1024);
```

### Native绑定对象

Native绑定对象（Native Binding Object）是系统所提供的对象，该对象与底层系统功能进行绑定，提供直接访问底层系统功能的能力。

当前支持序列化传输的Native绑定对象主要包含：[Context](../application-models/application-context-stage.md)和[RemoteObject](../reference/apis/js-apis-rpc.md#remoteobject)。

Context对象包含应用程序组件的上下文信息，它提供了一种访问系统服务和资源的方式，使得应用程序组件可以与系统进行交互。获取Context信息的方法可以参考[获取上下文信息](../application-models/application-context-stage.md)。

RemoteObject对象的主要作用是实现远程通信的功能，它允许在不同的进程间传递对象的引用，使得不同进程之间可以共享对象的状态和方法，服务提供者必须继承此类，RemoteObject对象的创建可以参考[RemoteObject的实现](../reference/apis/js-apis-rpc.md#remoteobject)。
