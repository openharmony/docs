# PageAbility的生命周期


PageAbility生命周期是PageAbility被调度到INACTIVE、ACTIVE、BACKGROUND等各个状态的统称。PageAbility生命周期流转及状态说明如图1、表1所示。

  **图1** PageAbility生命周期流转

![page-ability-lifecycle](figures/page-ability-lifecycle.png)


  **表1** PageAbility生命周期状态说明

| 生命周期状态 | 生命周期状态说明 |
| -------- | -------- |
| UNINITIALIZED | 未初始状态，为临时状态，PageAbility被创建后会由UNINITIALIZED状态进入INITIAL状态。 |
| INITIAL | 初始化状态，也表示停止状态，表示当前PageAbility未运行，PageAbility被启动后由INITIAL态进入INACTIVE状态。 |
| INACTIVE | 失去焦点状态，表示当前窗口已显示但是无焦点状态。 |
| ACTIVE | 前台激活状态，表示当前窗口已显示，并获取焦点。 |
| BACKGROUND | 后台状态，表示当前PageAbility退到后台，PageAbility在被销毁后由BACKGROUND状态进入INITIAL状态，或者重新被激活后由BACKGROUND状态进入ACTIVE状态。 |


应用开发者可以在app.js/app.ets中实现生命周期相关回调函数，PageAbility生命周期相关回调函数见下表。


  **表2** PageAbility生命周期回调接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| onCreate() | Ability第一次启动创建Ability时调用onCreate方法，开发者可以在该方法里做一些应用初始化工作。 |
| onDestroy() | 应用退出，销毁Ability对象前调用onDestroy方法，开发者可以在该方法里做一些回收资源、清空缓存等应用退出前的准备工作。 |
| onActive() | Ability切换到前台，并且已经获取焦点时调用onActive方法。 |
| onInactive() | Ability失去焦点时调用onInactive方法，Ability在进入后台状态时会先失去焦点，再进入后台。 |
| onShow() | Ability由后台不可见状态切换到前台可见状态调用onShow方法，此时用户在屏幕可以看到该Ability。 |
| onHide() | Ability由前台切换到后台不可见状态时调用onHide方法，此时用户在屏幕看不到该Ability。 |


PageAbility生命周期回调与生命周期状态的关系如下图所示。

  **图2** PageAbility生命周期回调与生命周期状态的关系

![fa-pageAbility-lifecycle](figures/fa-pageAbility-lifecycle.png)


> **说明：**
>
> 1. PageAbility的生命周期回调均为同步接口。
> 2. 目前app.js环境中仅支持onCreate和onDestroy回调，app.ets环境支持全量生命周期回调。
