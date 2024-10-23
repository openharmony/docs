# SharedArrayBuffer对象

SharedArrayBuffer内部包含一块Native内存，支持跨并发实例间共享，但是访问及修改需要采用Atomics类，防止数据竞争。SharedArrayBuffer可以用于多个并发实例间的状态共享或者数据共享。通信过程如下图所示：

![sharedarraybufer](figures/sharedarraybufer.png)
