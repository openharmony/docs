# Ability框架开发常见问题

## Stage模型中是否有类似FA模型的DataAbility的开发指导文档

适用于：OpenHarmony SDK 3.2.3.5版本， API9 Stage模型

Stage模型中DataShareExtensionAbility提供了向其他应用共享以及管理其数据的方法。

参考文档：[数据共享开发指导](../database/database-datashare-guidelines.md)

## 拉起Ability在界面上没反应

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 如果是通过startAbility的方式拉起，检查want中abilityName字段是否携带了bundleName做前缀，如果有，请删除;

2. 检查MainAbility.ts文件中onWindowStageCreate方法配置的Ability首页文件是否在main_pages.json中有定义，如果没有定义，请补齐;

3. SDK和OpenHarmony SDK系统推荐同一天的版本。

参考文档：[OpenHarmony版本转测试信息](https://gitee.com/openharmony-sig/oh-inner-release-management/blob/master/Release-Testing-Version.md)

## 如何将Ability的UI界面设置成透明

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

将最上层容器组件背景色设置为透明，然后通过设置XComponent组件的opacity属性值为0.01来实现。

  示例：

```
build() {
  Stack() {
    XComponent({
    id: 'componentId',
    type: 'surface',
    })
    .width('100%')
    .height('100%')
    .opacity(0.01)
    // 页面内容
  }
  .width('100%')
  .height('100%')
  .backgroundColor('rgba(255,255,255, 0)')
}
```

## 调用方法的时候，如何解决方法内部的this变成undefined

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

方式一：在调用方法的时候加上.bind(this)。

方式二：使用箭头函数。

## 如何解决must have required property 'startWindowIcon'报错

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

Ability配置中缺少startWindowIcon属性配置，需要在module.json5中abilities中配置startWindowIcon。

参考文档：[Stage模型应用程序包结构](../quick-start/module-configuration-file.md)

示例：

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

## 如何获取设备横竖屏的状态变化的通知

适用于：OpenHarmony SDK 3.2.3.5版本， API9 Stage模型

使用Ability的onConfigurationUpdated回调实现，系统语言、颜色模式以及Display相关的参数，比如方向、Density，发生变化时触发该回调。

## Stage模型是否推荐用globalThis去获取Context

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

不推荐，Stage模型使用globalThis去获取Context是错误的使用方式。在Stage模型中，整个应用进程共用一个js虚拟机实例，其中可以运行多个Ability实例，共用一个global对象。在同一个js虚拟机内的不同的Ability中使用globalThis获取Context，存在被覆盖从而发生错误的风险。

推荐使用方式参考：[Stage模型的Context详细介绍](../application-models/application-context-stage.md)。

## 如何在应用A中去获取应用B的HAP包的安装路径

适用于：OpenHarmony SDK 3.0以上版本， API9 Stage模型

首先需要申请系统权限，具体参看文档：[自动化签名](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465)。导入bundle模块，通过调用bundle.getApplicationInfo()接口，通过Bundle名称获取应用信息。然后通过application.moduleSourceDirs获取应用存储路径。

## 调用方使用startAbilityForResult，被调用方如何返回数据

适用于：OpenHarmony SDK3.0, API9 Stage模型

被调用方使用AbilityContext.terminateSelfWithResult方法，销毁被调用方ability，传递参数给startAbilityForResult回调函数，具体用法请参考[AbilityContext](../reference/apis/js-apis-ability-context.md#abilitycontextterminateselfwithresult)

## FA卡片上架后在用户的服务中心展示时可否触发生命周期，从而实现用户没有打开过FA应用的情况下获取到用户的登录信息？

适用于：OpenHarmony SDK 3.2.5.5版本, API8 FA模型

服务卡片在添加卡片后就触发了oncreate()生命周期，在不启用app的情况下也可以显示相关的用户信息-静默登录，但服务卡片目前要在app安装之后手动添加。

## 如何获取context

适用于：OpenHarmony SDK 3.2.7.5版本, API9 Stage模型

在MainAbility.ts文件中可以直接使用this.context获取context，在组件页面中可以使用getContext(this)获取context。

## 访问控制管理模块abilityAccessCtrl中grantUserGrantedPermission方法在API8语法校验提示未定义

适用于：OpenHarmony SDK 3.0版本, API8 FA模型

当前SDK有fullSDK和publicSDK两个版本，IDE默认下载的是publicSDK。其中，publicSDK版本不会包含系统API，如果要用系统API，需要使用fullSDK。具体参考[full-SDK替换指南](../quick-start/full-sdk-switch-guide.md)。

## public sdk支持哪几种ExtensionAbility（ServiceExtensionAbility、FormExtensionAbility、DataShareExtensionAbility）

适用于：OpenHarmony SDK 3.2.5.6版本， API9 Stage模型

上述ExtensionAbility 中，public sdk 仅可以使用FormExtensionAbility。ServiceExtensionAbility和DataShareExtensionAbility 为系统接口，需要使用full sdk。

Public SDK : 面向应用开发者提供，不包含需要使用系统权限的系统接口。

Full SDK : 面向OEM厂商提供，包含了需要使用系统权限的系统接口。

## 服务卡片无法循环播放gif图

适用于：OpenHarmony SDK 3.2.5.6版本， API9 Stage模型

目前暂不支持播放GIF图片。

## 如何通过卡片点击实现业务登录场景

适用于：OpenHarmony SDK 3.2.5.5版本， API9 Stage模型

可以通过点击卡片拉起响应的Ability后，通过Ability来实现业务登录场景。

## 如何跳转到设置中应用详情页面

使用于：OpenHarmony SDK 3.2.6.5版本

参考如下代码实现，示例：

```
this.context.startAbility(
{
  action: "action.settings.app.info",
  parameters: { "settingsParamBundleName": "your app bundlename" }
})
```

## 如何监听屏幕旋转

使用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

参考如下代码实现，示例：

```
let listener = mediaquery.matchMediaSync('(orientation: landscape)')
onPortrait(mediaQueryResult) {
if (mediaQueryResult.matches) {
// do something here
    } else {
// do something here
    }
}
listener.on('change', onPortrait)
```

## 如何控制checkbox选中切换过程中阴影背景的大小

使用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

设置checkbox组件padding属性，可控制阴影大小

## 如何设置卡片背景为透明

适用：OpenHarmony SDK 3.2.5.5版本

1. 在卡片根目录widget新建widget/resources/styles/default.json文件

2. 在default.json中书写如下代码：

```
{  
 "style": {   
      "app_background": "#00000000"   
   } 
}
```

## FA卡片如何的传参和接参

适用：OpenHarmony SDK 3.2.5.5版本

使用featureAbility.getWant()和featureAbility.getContext()在json文件中router跳转发送数据，在js文件中用featureAbility方法接收

## router.disableAlertBeforeBackPage和router.enableAlertBeforeBackPage怎么触发

适用：OpenHarmony SDK 3.2.5.5版本

需要满足两个条件

1. router.disableAlertBeforeBackPage和router.enableAlertBeforeBackPage类似一个开关，disableAlertBeforeBackPage是返回上一级页面时关闭弹窗提示，enableAlertBeforeBackPage是打开弹窗提示，默认是关闭的，当你需要使用时，首先要在一个函数里面开启功能，然后再执行跳转

2. 必须要使用系统的返回按键才能触发效果。
