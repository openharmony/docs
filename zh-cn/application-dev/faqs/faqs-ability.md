# 应用模型常见问题

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @ccllee1-->
<!--SE: @ccllee1-->
<!--TSE: @lixueqing513-->


## 如何获取设备横竖屏的状态变化通知(API 9)

**问题现象**

当设备发生横竖屏变化时，开发者应如何获取到变化的事件通知？

**解决措施**

使用UIAbility.onConfigurationUpdate()回调方法订阅系统环境变量的变化（包括语言，颜色模式，屏幕方向等）。

**参考文档**

[订阅系统环境变量的变化](../application-models/subscribe-system-environment-variable-changes.md#在uiability组件中订阅回调)


## 点击服务卡片如何跳转至指定的页面(API 9)

**解决措施**

参考文档，配置卡片事件，指定需要跳转的目标Ability，然后在目标UIAbility的onWindowStageCreate()中调用loadContent跳转至指定的page页面。

**参考链接**

[开发卡片事件](../form/arkts-ui-widget-configuration.md)


## 如何在Stage模型中创建后台服务(API 9)

**问题现象**

Stage模型中的ServiceExtensionAbility是系统接口，第三方应用不支持调用，如何在Stage模型中如何创建后台服务？

**解决措施**

Stage模型可通过后台任务实现该功能。

**参考链接**

[后台任务](../task-management/background-task-overview.md)


## FA和Stage模型中，应用是否可以创建并指定UIAbility运行在哪个进程(API 9)

**解决措施**

FA和Stage模型中，应用可以创建进程并指定UIAbility运行在某个进程。

- FA模型

  FA模型支持多进程，默认情况下，同一应用的所有组件均在相同进程中运行，且大多数应用都不应该改变这一点。但是如果应用自身业务需要某个组件独立进程运行，可在config配置文件中配置；配置清单中，ability标签的process子标签可指定该组件在哪个进程中运行，应用可以设置通过该属性使每个组件均在各自的进程中运行，但process子标签仅支持系统应用配置，三方应用配置不生效。

- Stage模型

  Stage模型支持多进程：Stage模型的进程模型由系统定义，三方应用不能配置多进程；如果需要自定义配置独立进程，需要申请特殊权限；配置清单中，module标签的process子标签可指定该Hap下Ability在哪个进程中运行，应用可以设置通过该属性使每个Hap的Ability组件均在各自的进程中运行。如果不配置，进程名默认为包名。


## Stage模型与FA模型在进程内对象共享方面有哪些差异(API 9)

**解决措施**

- Stage模型中，多个应用组件共享同一个ArkTS引擎实例，因此在Stage模型中，应用组件之间可以方便的共享对象和状态，同时减少复杂应用运行对内存的占用。

- FA模型中，每个应用组件独享一个ArkTS引擎实例。Stage模型作为主推的应用模型，开发者通过它能够更加便利地开发出分布式场景下的复杂应用。

**参考链接**

[UIAbility组件与UI的数据同步](../application-models/uiability-data-sync-with-ui.md)


## 如何使用AbilityStage的生命周期函数(API 9)

**解决措施**

在module.json5里的module中加上srcEntry字段"srcEntry": "./ets/myabilitystage/MyAbilityStage.ts"。

**参考链接**

[AbilityStage组件管理器](../application-models/abilitystage.md)


## 多实例场景下当前Ability调用terminateSelf后，桌面最近任务列表如何设置不保留快照(API 9)

**解决措施**

可在module.json5配置文件中配置removeMissionAfterTerminate为true。


## 调用方法的时候，方法内部的this变成了undefined(API 9)

**解决措施**

方式一：在调用方法的时候加上.bind(this)；

方式二：使用箭头函数。


## 启动UIAbility时报错：must have required property 'startWindowIcon'(API 9)

**解决措施**

UIAbility配置中缺少startWindowIcon属性配置，需要在module.json5中abilities中配置startWindowIcon。

**代码示例**

```
{
  "module": {
    // do something
    "abilities": [{
      // do something
      "startWindowIcon": "$media:space",
      "startWindowBackground": "$color:white",
    }]
  }
}
```

**参考链接**

[Stage模型配置文件](../quick-start/module-configuration-file.md)


## Stage模型是否推荐使用globalThis获取Context(API 9)

不推荐，Stage模型使用globalThis去获取Context是错误的使用方式。

在Stage模型中，整个应用进程共用一个js虚拟机实例，其中可以运行多个Ability实例，共用一个global对象。在同一个js虚拟机内的不同的Ability中使用globalThis获取Context，存在被覆盖从而发生错误的风险。

**参考链接**

[UIAbility组件与UI的数据同步](../application-models/uiability-data-sync-with-ui.md)


## 部署HAP时上报安装内容过大错误(API 9)

**问题现象**

部署hap时，上报如下错误：

Failure[INSTALL_FAILED_SIZE_TOO_LARGE] error while deploying hap？

**解决措施**

将其拆分为多个HAP即可解决。


## 调用方使用startAbilityForResult时，被调用方如何返回数据(API 9)

**解决措施**

被调用方使用AbilityContext.terminateSelfWithResult方法，销毁被调用方ability，传递参数给startAbilityForResult回调函数。

**参考链接**

[启动应用内的UIAbility并获取返回结果](../application-models/uiability-intra-device-interaction.md)


## 如何获取系统时间戳(API 9)

**解决措施**

使用\@ohos.systemDateTime的getCurrentTime来获取系统系统时间和时区。

**代码示例**

使用\@ohos.systemDateTime接口：

```
try {
  systemDateTime.getCurrentTime(true, (error, time) => {
    if (error) {
      console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
      return;
    }
    console.info(`Succeeded in getting currentTime : ${time}`);
  });
} catch(e) {
  console.info(`Failed to get currentTime. message: ${e.message}, code: ${e.code}`);
}
```

## 如何获取当前应用程序缓存目录(API 9)

**解决措施**

使用Context.cacheDir获取应用程序的缓存目录。

**参考链接**

[cacheDir](../application-models/application-context-stage.md#获取应用文件路径)


## 服务卡片生命周期回调函数在哪个js文件中调用(API 9)

**解决措施**

新建卡片时会生成一个FormAblity.ts文件，其中包含卡片对应的生命周期。

参考链接

[FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)


## 使用ServiceExtensionAbility和DataShareExtensionAbility的相关接口后DevEco Studio无法编译(API 9)

**问题现象**

使用ServiceExtensionAbility和DataShareExtensionAbility的相关接口后，DevEco Studio报错无法编译。

**问题原因**

当前SDK类型有：

- public-sdk : 面向应用开发者提供，不包含需要使用系统权限的系统接口。

- full-sdk : 面向OEM厂商提供，包含了需要使用系统权限的系统接口。

DevEco Studio默认下载是public-sdk。

**解决措施**

三方应用不支持开发ServiceExtensionAbility和DataShareExtensionAbility。若开发系统应用，请[下载full-sdk](full-sdk-switch-guide.md)。


## 如何获取应用级别的temp路径和files路径(API 9)

**解决措施**

通过应用上下文context获取。如：this.context.getApplicationContext.tempDir来获取temp路径；this.context.getApplicationContext.filesDir来获取files路径。

**参考链接**

[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)


## terminateSelf方法销毁当前应用之后并没有在后台任务列表中删除(API 9)

**解决措施**

在当前应用对应UIAbility的module.json5配置文件中，配置abilities标签的removeMissionAfterTerminate字段，设置为true即为销毁应用的同时删除应用快照记录，缺省值为false。

**参考链接**

[module.json5配置文件](../quick-start/module-configuration-file.md)


## Stage模型下开发的应用如何拉起 FA 模型开发的应用(API 9)

**问题现象**

已在stage模型下的应用如何拉起FA模型

**解决措施**

该功能目前已支持，具体实现可参考如下代码：

示例：

```
let want = {
    deviceId: "", // deviceId为空表示本设备
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
    moduleName: "Module1", // moduleName非必选
    parameters: { // 自定义信息
    },
}
// context为意图拉起的FA模型的AbilityContext
context.startAbility(want).then(() => {
    ...
}).catch((err) => {
    ...
})
```


## 原子化服务是否可以全程使用js实现(API 9)

**解决措施**

目前新建的卡片的目录结构都是css+hml+json，不能完全靠js实现，事件的触发和参数的传递都可以在json文件里面处理。


## FA卡片上架后在用户的服务中心展示时可否触发生命周期，从而实现用户没有打开过FA应用的情况下获取到用户的登录信息(API 9)

**问题现象**

FA卡片的生命周期以及信息显示

**解决措施**

服务卡片在添加卡片后就触发了onCreate()生命周期，在不启用app的情况下也可以显示相关的用户信息-静默登录，但服务卡片目前要在app安装之后手动添加。


## JS/ArkTS跳转到其他应用时报错“[c4d4d3492eb8531, 0, 0] ContextDeal::startAbility fetchAbilities failed”(API 9)

**问题现象**

JS/ArkTS跳转时, startAbility报错

**解决措施**

一般用startAbility，实现如下：

```
import featureAbility from '@ohos.ability.featureAbility'
function onStartRemoteAbility() {
console.info('onStartRemoteAbility begin');
let params;
let wantValue = {
    bundleName: 'ohos.samples.etsDemo',
    abilityName: 'ohos.samples.etsDemo.RemoteAbility',
    deviceId: getRemoteDeviceId(),
    parameters: params
};
console.info('onStartRemoteAbility want=' + JSON.stringify(wantValue));
featureAbility.startAbility({
    want: wantValue
}).then((data) => {
console.info('onStartRemoteAbility finished, ' + JSON.stringify(data));
});
console.info('onStartRemoteAbility end');
}
```

**参考链接**

可参考[启动本地PageAbility](../application-models/start-local-pageability.md)。


## 如何通过卡片点击实现业务登录场景(API 9)

**解决措施**

可以先创建FA模型的卡片,步骤如下：

1. 实现卡片生命周期接口

2. 配置卡片配置文件

3. 卡片信息的持久化

4. 卡片数据交互

5. 开发卡片页面

6. 开发卡片事件：通过点击卡片拉起响应的Ability后，通过Ability来实现业务登录场景

**参考链接**

[FA卡片开发指导](../form/widget-development-fa.md)


## 如何跳转到设置中应用详情页面(API 9)

**解决措施**

参考如下代码实现，示例：

```
this.context.startAbility(
{
  action: "action.settings.app.info",
  parameters: { "settingsParamBundleName": "your app bundlename" }
})
```


## stage模型，\@Component组件内如何获取UIAbilityContext(API 9)

**解决措施**

可以通过UIAbility. Context获取。

**代码示例**

```
import common from '@ohos.app.ability.common';

@Entry
@Component
struct AbilityContextTest {
  // abilityContext
  @State UIAbilityInfo: string = '获取 abilityInfo'
  UIAbilityContext: common.UIAbilityContext

  aboutToAppear() {
    // getContext获取Context，转为abilityContext
    this.UIAbilityContext = getContext(this) as common.UIAbilityContext
  }

  build() {
    Row() {
      Column({ space: 20 }) {
        Text(this.UIAbilityInfo)
          .fontSize(20)
          .onClick(() => {
            this.UIAbilityInfo = JSON.stringify(this.UIAbilityContext.abilityInfo)
            console.log(`ContextDemo abilityInfo = ${this.UIAbilityInfo}`)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


## 后台长时任务启动失败(API 9)

**问题现象**

调用featureAbility.startAbility()接口启动ServiceAbility，在ServiceAbility中启动后台长时任务报错，错误信息：{"code":201,"message":"BussinessError 201: Permission denied."}

**解决措施**

启动后台长时任务需要在module.json5文件中配置长时任务权限ohos.permission.KEEP_BACKGROUND_RUNNING、同时为需要使用长时任务的ability声明相应的后台模式类型。

```
"module": {
    "abilities": [
        {
            "backgroundModes": [
            "dataTransfer",
            "location"
            ], // 后台模式类型
        }
    ],
    "requestPermissions": [
        {
            "name": "ohos.permission.KEEP_BACKGROUND_RUNNING"  // 长时任务权限
        }
    ]
}
```

**参考链接**

[ServiceAbility组件配置-后台模式类型](../application-models/serviceability-configuration.md)

[长时任务权限](../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running)


## FA卡片如何进行数据交互(API 9)

卡片通过postCardAction接口触发和提供方的交互，在提供方中通过updateForm方法更新数据。

**参考链接**

[服务卡片开发指导](../form/widget-development-fa.md)

## 系统是否支持在桌面上创建应用的快捷入口，直接打开指定页面？(API 10)

当前不支持
