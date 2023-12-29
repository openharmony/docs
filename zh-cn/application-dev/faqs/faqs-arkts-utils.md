# ArkTS语言基础类库开发常见问题


## TaskPool、Worker和各个ArkTS引擎实例之间是否内存隔离

TaskPool和Worker基于Actor模型实现并发，Actor模型具备内存隔离的特性，所以TaskPool、Worker和各个ArkTS引擎实例之间是内存隔离的。


## 在TaskPool的生命周期中TaskPool线程什么时候会被销毁

TaskPool的生命周期无需开发者手动去管理。有一定时间没有执行新的任务，或者在TaskPool线程上没有执行监听任务的情况下，线程可能会被销毁。


## TaskPool对于任务时间有没有限制

任务时常上限3分钟（不包含Promise和async/await异步调用的耗时）。


## 对于预加载任务量大的场景推荐使用Worker还是TaskPool

Worker存在数量限制，支持最多同时存在8个Worker。所以针对预加载任务量大的场景，推荐使用TaskPool。更多TaskPool和Worker的特点和场景选择，可见[Worker和TaskPool的对比](../arkts-utils/taskpool-vs-worker.md#实现特点对比)。


## 存在线程复用的并发场景，推荐使用Worker还是TaskPool

同一个Worker无法执行不同的任务，所以针对线程复用的并发场景，推荐使用TaskPool。