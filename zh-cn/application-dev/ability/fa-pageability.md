# PageAbility开发指导

## PageAbility介绍

Page模板（以下简称“Page”）是FA唯一支持的模板，用于提供与用户交互的能力。

## PageAbility的生命周期

**Ability生命周期介绍**（Ability Life Cycle）是Ability被调度到INACTIVE、ACTIVE、BACKGROUND等各个状态的统称（主要涉及PageAbility类型和ServiceAbility类型的Ability）。

  - **PageAbility类型的Ability生命周期流转如下图所示**

![PageAbility-Lifecycle](figures/page-ability-lifecycle.png)


**Ability生命周期状态说明：**

  - **UNINITIALIZED**：未初始状态，为临时状态，Ability被创建后会由UNINITIALIZED状态进入INITIAL状态。

  - **INITIAL**：初始化状态，也表示停止状态，表示当前Ability未运行，Ability被启动后由INITIAL态进入INACTIVE状态。

  - **INACTIVE**：失去焦点状态，表示当前窗口已显示但是无焦点状态。

  - **ACTIVE**：前台激活状态，表示当前窗口已显示，并获取焦点。

  - **BACKGROUND**: 后台状态，表示当前Ability退到后台，Ability在被销毁后由BACKGROUND状态进入INITIAL状态，或者重新被激活后由BACKGROUND状态进入ACTIVE状态。

**PageAbility类型Ability生命周期回调如下图所示：**

![fa-pageAbility-lifecycle](figures/fa-pageAbility-lifecycle.png)

PageAbility提供如下生命周期回调，开发者可以在  app.js/app.ets 中重写生相关命周期函数 。

* onShow()

  Ability由后台不可见状态切换到前台可见状态调用onShow方法，此时用户在屏幕可以看到该Ability。

* onHide()

  Ability由前台切换到后台不可见状态时调用onHide方法，此时用户在屏幕看不到该Ability。

* onDestroy()

  应用退出，销毁Ability对象前调用onDestroy方法，开发者可以在该方法里做一些回收资源、清空缓存等应用退出前的准备工作。

* onCreate()

  Ability第一次启动创建Ability时调用onCreate方法，开发者可以在该方法里做一些应用初始化工作。

* onInactive()

  Ability失去焦点时调用onInactive方法，Ability在进入后台状态时会先失去焦点，再进入后台。

* onActive()

  Ability切换到前台，并且已经获取焦点时调用onActive方法。

* 示例

```javascript
export default {
  onCreate() {
    console.info('Application onCreate')
  },
  onDestroy() {
    console.info('Application onDestroy')
  },
  onShow(){
    console.info('Application onShow')
  },
  onHide(){
    console.info('Application onHide')
  },
  onInactive(){
    console.info('Application onInactive')
  },
  onActive(){
    console.info('Application onActive')
  },
}
```

## 启动本地PageAbility

 * 导入模块

```
import featureAbility from '@ohos.ability.featureAbility'
```
```
 featureAbility.startAbility(parameter: StartAbilityParameter, callback: AsyncCallback<number>)
```

* 接口说明

  启动新的ability(callback形式)

* 示例

```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.startAbility({
  want:
  {
    action: "",
    entities: [""],
    type: "",
    options: {
      // indicates the grant to perform read operations on the URI
      authReadUriPermission: true,
      // indicates the grant to perform write operations on the URI
      authWriteUriPermission: true,
      // support forward intent result to origin ability
      abilityForwardResult: true,
      // used for marking the ability start-up is triggered by continuation
      abilityContinuation: true,
      // specifies whether a component does not belong to ohos
      notOhosComponent: true,
      // specifies whether an ability is started
      abilityFormEnabled: true,
      // indicates the grant for possible persisting on the URI.
      authPersistableUriPermission: true,
      // indicates the grant for possible persisting on the URI.
      authPrefixUriPermission: true,
      // support distributed scheduling system start up multiple devices
      abilitySliceMultiDevice: true,
      // indicates that an ability using the service template is started regardless of whether the
      // host application has been started.
      startForegroundAbility: true,
      // install the specified ability if it's not installed.
      installOnDemand: true,
      // return result to origin ability slice
      abilitySliceForwardResult: true,
      // install the specified ability with background mode if it's not installed.
      installWithBackgroundMode: true
    },
    deviceId: "",
    bundleName: "com.example.startability",
    abilityName: "com.example.startability.MainAbility",
    uri: ""
  },
},
);
```
want参数也可以使用parameters参数，使用key-value的方式输入。
* 示例
```javascript
import featureAbility from '@ohos.ability.featureAbility'
featureAbility.startAbility({
    want:
    {
        bundleName: "com.example.startability",
        uri: "",
        parameters: {
            abilityName: "com.example.startability.MainAbility"
        }
    },
},
);
```
## 启动远程PageAbility

* 导入模块

```
import featureAbility from '@ohos.ability.featureAbility'
```

```
featureAbility.startAbility(parameter: StartAbilityParameter)
```
* 接口说明

  启动远程的ability(promise形式)
  前提：通过deviceManager获取远程deviceid

* 示例

```javascript
var promise = await featureAbility.startAbility({
    want:
    {
        deviceId: this.deviceId,
        bundleName: "com.example.test",
        abilityName: "com.example.test.MainAbility",
    },
}
);
```