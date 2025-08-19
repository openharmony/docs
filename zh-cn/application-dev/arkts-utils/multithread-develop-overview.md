# 应用多线程开发概述
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

在ArkTS应用开发中，不同业务场景需要不同的并发能力和任务类型。

常见的业务场景分为三种并发任务：

[耗时任务](time-consuming-task-overview.md)：业务逻辑包含较大计算量或多次I/O读写等需要长时间执行的任务。

[长时任务](long-time-task-overview.md)：业务逻辑包含监听或定期采集数据等需要长时间保持运行的任务。

[常驻任务](resident-task-overview.md)：业务逻辑跟随主线程生命周期或与主线程绑定的任务。

不同任务类型可以进一步细分，例如，典型的耗时任务包括CPU密集型任务、I/O密集型任务和同步任务，每种任务类型对应不同的业务场景。TaskPool和Worker均支持多线程并发，请开发者根据业务场景选择合适的并发能力，具体请参考[TaskPool和Worker适用场景对比](taskpool-vs-worker.md#适用场景对比)。

接下来的章节将列举多线程开发中常见的场景及其实践案例。
