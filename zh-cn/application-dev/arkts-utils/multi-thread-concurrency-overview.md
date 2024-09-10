# 多线程并发概述 (TaskPool和Worker)


## 简介

并发模型是用来实现不同应用场景中并发任务的编程模型，常见的并发模型分为基于内存共享的并发模型和基于消息通信的并发模型。

Actor并发模型作为基于消息通信并发模型的典型代表，不需要开发者去面对线程锁带来的一系列复杂偶发的问题，同时并发度也相对较高，因此得到了广泛的支持和使用。

当前ArkTS提供了TaskPool和Worker两种并发能力，TaskPool和Worker都基于Actor并发模型实现。

更多基于Actor模型进行多线程并发编程的例子可参考[Actor并发模型对比内存共享并发模型](actor-model-development-samples.md)。


## TaskPool和Worker

ArkTS提供了TaskPool和Worker两种并发能力供开发者选择，各自的运作机制和注意事项请见[TaskPool简介](taskpool-introduction.md)和[Worker简介](worker-introduction.md)，两者之间实现的特点和适用场景也存在差异，请见[TaskPool和Worker的对比](taskpool-vs-worker.md)。


## 相关实例

针对多线程开发，有以下相关实例可供参考：

- [多线程任务（ArkTS）(API9)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/LaunguageBaseClassLibrary/ConcurrentModule)
