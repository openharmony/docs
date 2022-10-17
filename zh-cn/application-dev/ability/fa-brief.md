# FA模型综述

## 整体架构
OpenHarmony用户程序的开发本质上就是开发Ability。OpenHarmony系统是通过对Ability调度，结合系统提供的一致性调度契约对Ability进行生命周期管理，从而实现对用户程序的调度。

Ability框架在API 8及更早版本使用FA模型。FA模型中Ability分为PageAbility、ServiceAbility、DataAbility、FormAbility几种类型。其中：
- PageAbility是具备ArkUI实现的Ability，是用户具体可见并可以交互的Ability实例。
- ServiceAbility也是Ability一种，但是没有UI，提供其他Ability调用自定义的服务，在后台运行。
- DataAbility也是没有UI的Ability，提供其他Ability进行数据的增删查服务，在后台运行。
- FormAbility是卡片Ability，是一种界面展示形式。

## 生命周期

在所有Ability中，PageAbility因为具有界面，也是应用的交互入口，因此生命周期更加复杂。
**PageAbility生命周期回调如下图所示：**

![fa-pageAbility-lifecycle](figures/fa-pageAbility-lifecycle.png)

其他类型Ability的生命周期可参考PageAbility生命周期去除前后台切换以及`onShow`的部分进行理解。
开发者可以在 `app.js/app.ets` 中重写生命周期函数，在对应的生命周期函数内处理应用相应逻辑。

目前`app.js`环境中仅支持onCreate和onDestroy回调，`app.ets`环境支持全量生命周期回调。


## 进程线程模型
应用独享独立进程，Ability独享独立线程，应用进程在Ability第一次启动时创建，并为启动的Ability创建线程，应用启动后再启动应用内其他Ability，会为每一个Ability创建相应的线程。每个Ability绑定一个独立的JSRuntime实例，因此Ability之间是隔离的。

![fa-threading-model](figures/fa-threading-model.png)

## 应用包结构

FA模型的应用包的工程目录结构，请参考[OpenHarmony工程介绍](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-project-overview-0000001218440650#section4154183910141)。

对FA模型的应用包结构的配置说明，请参考[应用包结构说明（FA模型）](../quick-start/package-structure.md)。



## 相关实例

针对FA模型下的Ability开发，有以下相关实例可供参考：

- [`FaModel`：FA模型（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/FaModel)
- [`DistributedCalc`：分布式计算器（JS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/common/DistributeCalc)
- [`DistributedCalc`：分布式计算器（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/Preset/DistributeCalc)
- [`DistributeGraffiti`：分布式涂鸦（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/ability/DistributedGraffiti)
- [分布式调度启动远程FA（JS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/RemoteStartFA)
- [分布式新闻客户端（JS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/NewsDemo)
- [分布式手写板（ArkTS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/DistributeDatabaseDrawEts)
- [分布式鉴权（JS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/GameAuthOpenH)
- [分布式游戏手柄（ArkTS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/HandleGameApplication)
- [分布式邮件（ArkTS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/OHMailETS)
- [分布式亲子早教系统（ArkTS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/OpenHarmonyPictureGame)
- [分布式遥控器（ArkTS）（API8）](https://gitee.com/openharmony/codelabs/tree/master/Distributed/RemoteControllerETS)