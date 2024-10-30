# ArkUI数据更新场景

当需要网络下载或者本地生成的数据需要发送到UI线程进行展示时，因为ArkUI的标注和\@Sendable不能同时修饰变量和对象，所以对于此类场景，需要使用makeObserved在ArkUI中导入可观察的Sendable共享数据。

具体可见相关：[makeObserved接口：将非观察数据变为可观察数据](../quick-start/arkts-new-makeObserved.md)。

