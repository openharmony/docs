# FA模型综述

## 整体架构
鸿蒙用户程序的开发本质上就是开发Ability，OpenHarmony系统也是通过调度Ability，通过系统提供的一致性调度契约对Ability进行生命周期管理，从而实现对用户程序的调度。FA模型中Ability分为PageAbility、ServiceAbility和DataAbility三种类型。其中PageAbility具备ArkUI的Ability，是用户具体可见并可以交互的Ability实例；ServiceAbility也是Ability一种，但是没有UI，提供其他Ability调用自定义的服务，在后台运行；DataAbility也是没有UI，提供其他Ability进行数据的增删查服务，在后台运行。

## 应用包结构
**应用包结构如下图所示：**
![fa-package-info](figures/fa-package-info.png)

## 生命周期

**pageAbility生命周期回调如下图所示：**

![fa-pageAbility-lifecycle](figures/fa-pageAbility-lifecycle.png)

开发者可以在 app.js/app.ets 中重写生命周期函数，在对应的生命周期函数内处理应用相应逻辑。


## 进程线程模型
应用独享独立进程，Ability独享独立线程，应用进程在Ability第一次启动时创建，并为启动的Ability创建线程，应用启动后再启动应用内其他Ability，会为每一个Ability创建相应的线程。每个Ability绑定一个独立的JSRuntime实例，因此Ability之间是隔离的。

![fa-threading-nodel](figures/fa-threading-model.png)