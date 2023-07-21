# 多线程并发概述


## 简介

并发模型是用来实现不同应用场景中并发任务的编程模型，常见的并发模型分为基于内存共享的并发模型和基于消息通信的并发模型。

Actor并发模型作为基于消息通信并发模型的典型代表，不需要开发者去面对锁带来的一系列复杂偶发的问题，同时并发度也相对较高，因此得到了广泛的支持和使用，也是当前ArkTS语言选择的并发模型。

因为Actor模型的内存隔离特性，所以需要进行跨线程的数据序列化传输。


## 数据传输对象

目前支持传输的数据对象可以分为[普通对象](#普通对象)、[可转移对象](#可转移对象)、[可共享对象](#可共享对象)三种。


### 普通对象

普通对象传输采用标准的结构化克隆算法（Structured Clone）进行序列化，此算法可以通过递归的方式拷贝传输对象，相较于其他序列化的算法，支持的对象类型更加丰富。

序列化支持的类型包括：除Symbol之外的基础类型、Date、String、RegExp、Array、Map、Set、Object（仅限简单对象，比如通过“{}”或者“new Object”创建，普通对象仅支持传递属性，不支持传递其原型及方法）、ArrayBuffer、TypedArray。


### 可转移对象

可转移对象（Transferable object）传输采用地址转移进行序列化，不需要内容拷贝，会将ArrayBuffer的所有权转移给接收该ArrayBuffer的线程，转移后该ArrayBuffer在发送它的线程中变为不可用，不允许再访问。


```js
// 定义可转移对象
let buffer = new ArrayBuffer(100);
```


### 可共享对象

共享对象SharedArrayBuffer，拥有固定长度，可以存储任何类型的数据，包括数字、字符串等。

共享对象传输指SharedArrayBuffer支持在多线程之间传递，传递之后的SharedArrayBuffer对象和原始的SharedArrayBuffer对象可以指向同一块内存，进而达到内存共享的目的。

SharedArrayBuffer对象存储的数据在同时被修改时，需要通过原子操作保证其同步性，即下个操作开始之前务必需要等到上个操作已经结束。


```js
// 定义可共享对象，可以使用Atomics进行操作
let sharedBuffer = new SharedArrayBuffer(1024);
```


## TaskPool和Worker

ArkTS提供了TaskPool和Worker两种并发能力供开发者选择，其具体的实现特点和各自的适用场景存在差异，详细请参见[TaskPool和Worker的对比](taskpool-vs-worker.md)。


## 相关实例

针对多线程开发，有以下相关实例可供参考：

- [ConcurrentModule：多线程任务](https://gitee.com/openharmony/applications_app_samples/tree/master/code/LaunguageBaseClassLibrary/ConcurrentModule)
