# Ability开发常见问题

## 如何获取设备横竖屏的状态变化通知

适用于：OpenHarmony 3.2 Beta5 API 9

**问题现象**

当设备发生横竖屏变化时，开发者应如何获取到变化的事件通知？

**解决措施**

使用UIAbility.onConfigurationUpdate\(\)回调方法订阅系统环境变量的变化（包括语言，颜色模式，屏幕方向等）。

**参考文档**

[订阅系统环境变量的变化](../application-models/subscribe-system-environment-variable-changes.md#在uiability组件中订阅回调)

## 点击服务卡片如何跳转至指定的页面

适用于：OpenHarmony 3.2 Beta5 API 9

**解决措施**

参考文档，配置卡片事件，指定需要跳转的目标Ability，然后在目标UIAbility的onWindowStageCreate\(\)中调用loadContent跳转至指定的page页面。

**参考链接**

[开发卡片事件](../application-models/arkts-ui-widget-configuration.md)

## 如何在Stage模型中创建后台服务

适用于：Openharmony 3.2 Beta5

**问题现象**

Stage模型中的ServiceExtensionAbility是系统接口，第三方应用不支持调用，如何在Stage模型中如何创建后台服务？

**解决措施**

Stage模型可通过后台任务实现该功能。

**参考链接**

[后台任务](../task-management/background-task-overview.md)

## FA和Stage模型中，应用是否可以创建并指定UIAbility运行在哪个进程

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

FA和Stage模型中，应用可以创建进程并指定UIAbility运行在某个进程。

-   FA模型

    FA模型支持多进程，默认情况下，同一应用的所有组件均在相同进程中运行，且大多数应用都不应该改变这一点。但是如果应用自身业务需要某个组件独立进程运行，可在config配置文件中配置；配置清单中，ability标签的process子标签可指定该组件在哪个进程中运行，应用可以设置通过该属性使每个组件均在各自的进程中运行，但process子标签仅支持系统应用配置，三方应用配置不生效。

-   Stage模型

    Stage模型支持多进程：Stage模型的进程模型由系统定义，三方应用不能配置多进程；如果需要自定义配置独立进程，需要申请特殊权限；配置清单中，module标签的process子标签可指定该Hap下Ability在哪个进程中运行，应用可以设置通过该属性使每个Hap的Ability组件均在各自的进程中运行。如果不配置，进程名默认为包名。


## Stage模型与FA模型在进程内对象共享方面有哪些差异

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

-   Stage模型中，多个应用组件共享同一个ArkTS引擎实例，因此在Stage模型中，应用组件之间可以方便的共享对象和状态，同时减少复杂应用运行对内存的占用。
-   FA模型中，每个应用组件独享一个ArkTS引擎实例。Stage模型作为主推的应用模型，开发者通过它能够更加便利地开发出分布式场景下的复杂应用。

**参考链接**

[UIAbility组件与UI的数据同步](../application-models/uiability-data-sync-with-ui.md)

## 如何使用AbilityStage的生命周期函数

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

在module.json5里的module中加上srcEntry字段"srcEntry": "./ets/myabilitystage/MyAbilityStage.ts"。

**参考链接**

[AbilityStage组件容器](../application-models/abilitystage.md)


## 多实例场景下当前Ability调用terminateSelf后，桌面最近任务列表如何设置不保留快照

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

可在module.json5配置文件中配置removeMissionAfterTerminate为true。

## 通过startAbility\(\)方法无法启动UIAbility实例

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

-   如果是通过startAbility的方式拉起，检查want中abilityName字段是否携带了bundleName做前缀，如果有，请删除。
-   检查MainAbility.ts文件中onWindowStageCreate方法配置的Ability首页文件是否在main\_pages.json中有定义，如果没有定义，请补齐。SDK和OpenHarmony SDK系统推荐同一天的版本。

## 调用方法的时候，方法内部的this变成了undefined

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

方式一：在调用方法的时候加上.bind\(this\)；

方式二：使用箭头函数。

## 启动UIAbility时报错：must have required property 'startWindowIcon'

适用于：Openharmony 3.2 Beta5 API 9

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

## Stage模型是否推荐使用globalThis获取Context

适用于：Openharmony 3.2 Beta5 API 9

不推荐，Stage模型使用globalThis去获取Context是错误的使用方式。

在Stage模型中，整个应用进程共用一个js虚拟机实例，其中可以运行多个Ability实例，共用一个global对象。在同一个js虚拟机内的不同的Ability中使用globalThis获取Context，存在被覆盖从而发生错误的风险。

**参考链接**

[UIAbility组件与UI的数据同步](../application-models/uiability-data-sync-with-ui.md)

## 部署HAP时上报安装内容过大错误

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

部署hap时，上报如下错误：

Failure\[INSTALL\_FAILED\_SIZE\_TOO\_LARGE\] error while deploying hap？

**解决措施**

将其拆分为多个HAP即可解决。

## 调用方使用startAbilityForResult时，被调用方如何返回数据

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

被调用方使用AbilityContext.terminateSelfWithResult方法，销毁被调用方ability，传递参数给startAbilityForResult回调函数。

**参考链接**

[启动应用内的UIAbility并获取返回结果](../application-models/uiability-intra-device-interaction.md)


## 如何获取系统时间戳

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

在Openharmony中使用@ohos.systemDateTime的getCurrentTime来获取系统系统时间和时区。

**代码示例**

使用@ohos.systemDateTime接口：

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


**参考链接**

[系统时间、时区](../reference/apis/js-apis-system-date-time.md#systemdatetimegetcurrenttime)

## 如何获取当前应用程序缓存目录

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

在Openharmony中使用Context.cacheDir获取应用程序的缓存目录。

**参考链接**

[cacheDir](../application-models/application-context-stage.md#获取应用文件路径)

## 服务卡片生命周期回调函数在哪个js文件中调用

适用于：Openharmony 3.2 Beta5 API 9

**解决措施**

新建卡片时会生成一个FormAblity.ts文件，其中包含卡片对应的生命周期。

参考链接

[FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md)

## 使用ServiceExtensionAbility和DataShareExtensionAbility的相关接口后DevEco Studio无法编译

适用于：Openharmony 3.2 Beta5 API 9

**问题现象**

使用ServiceExtensionAbility和DataShareExtensionAbility的相关接口后，DevEco Studio报错无法编译。

**问题原因**

当前SDK类型有：

-   public-sdk : 面向应用开发者提供，不包含需要使用系统权限的系统接口。
-   full-sdk : 面向OEM厂商提供，包含了需要使用系统权限的系统接口。

DevEco Studio默认下载是public-sdk。

**解决措施**

三方应用不支持开发ServiceExtensionAbility和DataShareExtensionAbility。若开发系统应用，请[下载full-sdk](../quick-start/full-sdk-switch-guide.md)。

## 如何获取应用级别的temp路径和files路径

适用于：OpenHarmony 3.2 Beta5 

**解决措施**

通过应用上下文context获取。如：this.context.getApplicationContext.tempDir来获取temp路径；this.context.getApplicationContext.filesDir来获取files路径。

**参考链接**

[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)


## FA卡片上架后在用户的服务中心展示时可否触发生命周期，从而实现用户没有打开过FA应用的情况下获取到用户的登录信息  

适用于：OpenHarmony 3.2 Beta 5 API 9

**问题现象**

FA卡片的生命周期以及信息显示

**解决措施**

服务卡片在添加卡片后就触发了oncreat（）生命周期，在不启用app的情况下也可以显示相关的用户信息-静默登录，但服务卡片目前要在app安装之后手动添加。

## 如何通过卡片点击实现业务登录场景

适用于: OpenHarmony 3.2 Beta5  API 9

**解决措施**

可以先创建FA模型的卡片,步骤如下：

1. 实现卡片生命周期接口

2. 配置卡片配置文件

3. 卡片信息的持久化

4. 卡片数据交互

5. 开发卡片页面

6. 开发卡片事件：通过点击卡片拉起响应的Ability后，通过Ability来实现业务登录场景

**参考链接**

[FA卡片开发指导](../application-models/widget-development-fa.md)

## 如何跳转到设置中应用详情页面 

适用于：OpenHarmony 3.2 Beta5  API 9

**解决措施**

参考如下代码实现，示例：

```
this.context.startAbility(
{
  action: "action.settings.app.info",
  parameters: { "settingsParamBundleName": "your app bundlename" }
})
```

## stage模型，@Component组件内如何获取UIAbilityContext 

适用于：OpenHarmony 3.2 Beta5 API9

**解决措施**

可以通过UIAbility. Context获取。

**代码示例**

```
import UIAbility from '@ohos.app.ability.UIAbility';

let UIAbilityContext = UIAbility.context;
let ApplicationContext = UIAbility.context.getApplicationContext();
@Entry
@Component
struct AbilityContextTest {
  // abilityContext
  @State UIabilityInfo: string = '获取 abilityInfo'
  UIabilityContext: UIAbilityContext

  aboutToAppear() {
    // getContext获取Context，转为abilityContext 
    this.UIabilityContext = getContext(this) as UIAbilityContext
  }

  build() {
    Row() {
      Column({ space: 20 }) {
        Text(this.abilityInfo)
          .fontSize(20)
          .onClick(()=>{
            this.UIabilityInfo = JSON.stringify(this.UIabilityContext.UIabilityInfo)
            console.log(`ContextDemo abilityInfo= ${this.UIabilityInfo}`)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
