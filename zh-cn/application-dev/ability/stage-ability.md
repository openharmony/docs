# Ability开发指导
## 场景介绍
Stage模型是区别于FA模型的一种应用开发模型，对此模型的介绍详见[Stage模型综述](stage-brief.md)。开发Stage模型应用时，需要在module.json5和app.json5配置文件中对应用的包结构进行声明，对应用包结构配置文件的说明详见[应用包结构配置文件的说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/stage-structure.md)。基于Stage模型的Ability应用开发，主要涉及如下功能逻辑：
- 创建支持使用屏幕浏览及人机交互的Ability应用，包括实现Ability的生命周期、获取Ability配置信息、向用户申请授权及环境变化通知等场景。
- 启动Ability应用，包括相同设备启动Ability、跨设备启动Ability以及指定页面启动Ability等场景。
- 通用组件Call功能，详见[Call调用开发指导](stage-call.md)。
- 连接ServiceExtensionAbility，与ServiceExtensionAbility断开连接，详见[ServiceExtensionAbility开发指导](stage-serviceextension.md)。
- 应用迁移，详见[应用迁移开发指导](stage-ability-continuation.md)。

### 启动模式
Ability支持单实例、多实例和指定实例3种启动模式，在module.json5中通过launchType配置。启动模式对应Ability被启动时的行为，对启动模式的详细说明如下：

| 启动模式     | 描述     |说明             |
| ----------- | -------  |---------------- |
| standard    | 标准模式   | 每次startAbility都会启动一个新的实例。 |
| singleton   | 单实例模式   | 系统中只存在唯一一个实例，startAbility时，如果已存在，则复用系统中的唯一一个实例。 |
| specified   | 指定实例 | 运行时由Ability内部业务决定是否创建多实例。 |

缺省情况下是singleton模式，module.json5示例如下：
```json
{
  "module": {
    "abilities": [
      {
        "launchType": "singleton",
      }
    ]
  }
}
```
## 创建Ability
### 接口说明
AbilityStage功能如下（AbilityStage类，拥有context属性，具体的API详见[接口文档](../reference/apis/js-apis-application-abilitystage.md)）：

**表1** AbilityStage API接口功能介绍
|接口名|描述|
|:------|:------|
|onCreate(): void|AbilityStage初始化时被调用。|
|onAcceptWant(want: Want): string|启动指定Ability时被调用。|
|onConfigurationUpdated(config: Configuration): void|全局配置发生变更时被调用。|

Ability功能如下（Ability类，具体的API详见[接口文档](../reference/apis/js-apis-application-ability.md)）：

**表2** Ability API接口功能介绍

|接口名|描述|
|:------|:------|
|onCreate(want: Want, param: AbilityConstant.LaunchParam): void|Ability生命周期回调，Ability启动时被调用。|
|onDestroy(): void|Ability生命周期回调，Ability销毁时被调用。|
|onWindowStageCreate(windowStage: window.WindowStage): void|Ability生命周期回调，创建window stage时被调用，应用开发者可通过window.WindowStage的接口执行页面加载等操作。|
|onWindowStageDestroy(): void|Ability生命周期回调，销毁window stage时被调用。|
|onForeground(): void|Ability生命周期回调，Ability切换至前台时被调用。|
|onBackground(): void|Ability生命周期回调，Ability切换至后台时被调用。|
|onNewWant(want: Want, launchParams: AbilityConstant.LaunchParam): void|Ability回调，Ability的启动模式设置为单例时被调用。|
|onConfigurationUpdated(config: Configuration): void|Ability回调，Ability的系统配置更新时被调用。|
### 实现AbilityStage及Ability生命周期
创建Stage模型的Page Ability应用，需实现AbilityStage接口及Ability生命周期接口，并使用窗口提供的方法设置页面。具体示例代码如下：
1. 导入AbilityStage模块。
   ```
   import AbilityStage from "@ohos.application.AbilityStage"
   ```
2. 实现AbilityStage接口，接口生成的默认相对路径：entry\src\main\ets\Application\AbilityStage.ts。
   ```ts
   export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
    }
   }
   ```
3. 导入Ability模块。
   ```js
   import Ability from '@ohos.application.Ability'
   ```
4. 实现Ability生命周期接口，接口默认生成的相对路径：entry\src\main\ets\MainAbility\MainAbility.ts。

   在`onWindowStageCreate(windowStage)`中通过loadContent接口设置应用要加载的页面，window接口的使用详见[窗口开发指导](../windowmanager/application-window-stage.md)。
   ```ts
   export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.log("MainAbility onCreate")
    }

    onDestroy() {
        console.log("MainAbility onDestroy")
    }

    onWindowStageCreate(windowStage) {
        console.log("MainAbility onWindowStageCreate")

        windowStage.loadContent("pages/index").then(() => {
            console.log("MainAbility load content succeed")
        }).catch((error) => {
            console.error("MainAbility load content failed with error: " + JSON.stringify(error))
        })
    }

    onWindowStageDestroy() {
        console.log("MainAbility onWindowStageDestroy")
    }

    onForeground() {
        console.log("MainAbility onForeground")
    }

    onBackground() {
        console.log("MainAbility onBackground")
    }
   }
   ```
### 获取AbilityStage及Ability的配置信息
AbilityStage类及Ability类均拥有context属性，应用可以通过`this.context`获取Ability实例的上下文，进而获取详细的配置信息。

如下示例展示了AbilityStage通过context属性获取包代码路径、hap包名、Ability名以及系统语言的方法。具体示例代码如下：

```ts
import AbilityStage from "@ohos.application.AbilityStage"
export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
        let context = this.context
        console.log("MyAbilityStage bundleCodeDir" + context.bundleCodeDir)

        let currentHapModuleInfo = context.currentHapModuleInfo
        console.log("MyAbilityStage hap module name" + currentHapModuleInfo.name)
        console.log("MyAbilityStage hap module mainAbilityName" + currentHapModuleInfo.mainAbilityName)

        let config = this.context.config
        console.log("MyAbilityStage config language" + config.language)
    }
}
```

如下示例展示了Ability通过context属性获取包代码路径、hap包名、Ability名以及系统语言的方法。具体示例代码如下：
```ts
import Ability from '@ohos.application.Ability'
export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.log("MainAbility onCreate")
        let context = this.context
        console.log("MainAbility bundleCodeDir" + context.bundleCodeDir)

        let abilityInfo = this.context.abilityInfo;
        console.log("MainAbility ability bundleName" + abilityInfo.bundleName)
        console.log("MainAbility ability name" + abilityInfo.name)

        let config = this.context.config
        console.log("MainAbility config language" + config.language)
    }
}
```
### 应用向用户申请授权
应用需要获取用户的隐私信息或使用系统能力时，比如获取位置信息、使用相机拍摄照片或录制视频等，需要向用户申请授权。在开发过程中，首先需要明确涉及的敏感权限并在module.json5中声明需要的权限，同时通过接口`requestPermissionsFromUser`以动态弹窗的方式向用户申请授权。以访问日历为例，具体示例代码如下：

在module.json5声明需要的权限：
```json
"requestPermissions": [
    {
    "name": "ohos.permission.READ_CALENDAR"
    }
]
```
通过动态弹窗向用户申请授权：
```ts
let context = this.context
let permissions: Array<string> = ['ohos.permission.READ_CALENDAR']
context.requestPermissionsFromUser(permissions).then((data) => {
    console.log("Succeed to request permission from user with data: " + JSON.stringify(data))
}).catch((error) => {
    console.log("Failed to request permission from user with error: " + JSON.stringify(error))
})
```
### 系统环境变化通知
环境变化，包括全局配置的变化和Ability配置的变化。全局配置指全局的、系统的配置，目前包括“语言”和“颜色模式”，全局配置的变化一般由“设置”中的配置项或“控制中心”中的图标触发。Ability配置指与单个Ability实例相关的配置，目前包括“displayId”（物理屏幕Id）、“屏幕分辨率”，“横竖屏”，这些配置与Ability所在的Display有关，Ability配置的变化一般由窗口触发。配置项目前均定义在[Configuration](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-configuration.md)类中。

对于Stage模型的应用，配置发生变化时，不会重启Ability，会触发应用的`onConfigurationUpdated(config: Configuration)`回调，若应用希望根据配置变化做相应处理，可以重写`onConfigurationUpdated`回调，若无需处理配置变化，则可以不必实现`onConfigurationUpdated`回调。应该注意的是，回调中的Configuration对象包括当前Ability所有的配置，不仅是发生变化的配置。

如下示例展示了AbilityStage的`onConfigurationUpdated`回调实现，系统语言和颜色模式发生变化时触发该回调。具体示例代码如下：
```ts
import AbilityStage from '@ohos.application.AbilityStage'
import ConfigurationConstant from '@ohos.application.ConfigurationConstant'

export default class MyAbilityStage extends AbilityStage {
    onConfigurationUpdated(config) {
        if (config.colorMode === ConfigurationConstant.ColorMode.COLOR_MODE_DARK) {
            console.log('colorMode changed to dark')
        }
    }
}
```

如下示例展示了Ability的`onConfigurationUpdated`回调实现，系统语言、颜色模式以及Display相关的参数，比如方向、Density，发生变化时触发该回调。具体示例代码如下：
```ts
import Ability from '@ohos.application.Ability'
import ConfigurationConstant from '@ohos.application.ConfigurationConstant'

export default class MainAbility extends Ability {
    direction : number;

    onCreate(want, launchParam) {
        this.direction = this.context.config.direction
    }

    onConfigurationUpdated(config) {
        if (this.direction !== config.direction) {
            console.log(`direction changed to ${config.direction}`)
        }
    }
}
```
## 启动Ability
### 接口说明
Ability类拥有context属性，context属性为AbilityContext类，AbilityContext类拥有abilityInfo、currentHapModuleInfo等属性，启动Ability等方法。具体的API详见[接口文档](../reference/apis/js-apis-ability-context.md)。

**表3** AbilityContext API接口功能介绍
|接口名|描述|
|:------|:------|
|startAbility(want: Want, callback: AsyncCallback\<void>): void|启动Ability。|
|startAbility(want: Want, options?: StartOptions): Promise\<void>|启动Ability。|
|startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void|带AccountId启动Ability。|
|startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>|带AccountId启动Ability。|
|startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>): void|带返回结果启动Ability。|
|startAbilityForResult(want: Want, options?: StartOptions): Promise\<AbilityResult>|带返回结果启动Ability。|
|startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void|带返回结果及AccountId启动Ability。|
|startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult>|带返回结果及AccountId启动Ability。|
### 相同设备启动Ability
应用可以通过`this.context`获取Ability实例的上下文，进而使用AbilityContext中的StartAbility相关接口启动Ability。启动Ability可指定Want、StartOptions、accountId，通过callback形式或promise形式实现。具体示例代码如下：
```ts
let context = this.context
var want = {
    "deviceId": "",
    "bundleName": "com.example.MyApplication",
    "abilityName": "MainAbility"
};
context.startAbility(want).then(() => {
    console.log("Succeed to start ability")
}).catch((error) => {
    console.error("Failed to start ability with error: "+ JSON.stringify(error))
})
```

### 跨设备启动Ability（当前仅对系统应用开放）
>说明：由于DeviceManager的getTrustedDeviceListSync接口仅对系统应用开放，当前跨设备启动Ability仅支持系统应用
跨设备场景下，需指定对端设备deviceId，具体示例代码如下：
```ts
let context = this.context
var want = {
    "deviceId": getRemoteDeviceId(),
    "bundleName": "com.example.MyApplication",
    "abilityName": "MainAbility"
};
context.startAbility(want).then(() => {
    console.log("Succeed to start remote ability")
}).catch((error) => {
    console.error("Failed to start remote ability with error: " + JSON.stringify(error))
})
```
从DeviceManager获取指定设备的deviceId。具体示例代码如下：
```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';
function getRemoteDeviceId() {
    if (typeof dmClass === 'object' && dmClass != null) {
        var list = dmClass.getTrustedDeviceListSync();
        if (typeof (list) == 'undefined' || typeof (list.length) == 'undefined') {
            console.log("MainAbility onButtonClick getRemoteDeviceId err: list is null");
            return;
        }
        console.log("MainAbility onButtonClick getRemoteDeviceId success:" + list[0].deviceId);
        return list[0].deviceId;
    } else {
        console.log("MainAbility onButtonClick getRemoteDeviceId err: dmClass is null");
    }
}
```
向用户申请数据同步'ohos.permission.DISTRIBUTED_DATASYNC'的权限。申请授权示例代码见[应用向用户申请授权](#应用向用户申请授权)。
### 指定页面启动Ability
当Ability的启动模式设置为单例时，若Ability已被拉起，再次启动Ability会触发onNewWant回调。应用开发者可以通过want传递启动参数，比如希望指定页面启动Ability，可以通过want中的uri参数或parameters参数传递pages信息。目前，Stage模型中Ability暂时无法直接使用router的能力，可以将启动参数传递给自定义组件，在自定义组件的生命周期中调用router接口显示指定页面。具体示例代码如下：

使用startAbility再次拉起Ability，通过want中的uri参数传递页面信息：
```ts
async function reStartAbility() {
  try {
    await this.context.startAbility({
      bundleName: "com.sample.MyApplication",
      abilityName: "MainAbility",
      uri: "pages/second"
    })
    console.log('start ability succeed')
  } catch (error) {
    console.error(`start ability failed with ${error.code}`)
  }
}
```

在Ability的onNewWant回调中获取包含页面信息的want参数：
```ts
import Ability from '@ohos.application.Ability'

export default class MainAbility extends Ability {
  onNewWant(want, launchParams) {
    globalThis.newWant = want
  }
}
```

在自定义组件中获取包含页面信息的want参数并根据uri做路由处理：
```ts
import router from '@ohos.router'

@Entry
@Component
struct Index {
  newWant = undefined

  onPageShow() {
    console.info('Index onPageShow')
    let newWant = globalThis.newWant
    if (newWant.hasOwnProperty("uri")) {
      router.push({ uri: newWant.uri });
      globalThis.newWant = undefined
    }
  }
}
```