# 组件启动规则（Stage模型）


启动组件是指一切启动或连接应用组件的行为：


- 启动UIAbility、ServiceExtensionAbility、DataShareExtensionAbility，如使用startAbility()、startServiceExtensionAbility()、startAbilityByCall()等相关接口。

- 连接ServiceExtensionAbility、DataShareExtensionAbility，如使用connectServiceExtensionAbility()、createDataShareHelper()等相关接口。


在OpenHarmony中，为了保证用户具有更好的使用体验，对以下几种易影响用户体验与系统安全的行为做了限制：


- 后台应用任意弹框，如各种广告弹窗，影响用户使用。

- 后台应用相互唤醒，不合理的占用系统资源，导致系统功耗增加或系统卡顿。

- 前台应用任意跳转至其他应用，如随意跳转到其他应用的支付页面，存在安全风险。


鉴于此，OpenHarmony制订了一套组件启动规则，主要包括：


- **跨应用启动组件，需校验目标组件Visible**
  - 若目标组件visible字段配置为false，则需校验`ohos.permission.START_INVISIBLE_ABILITY`权限
  - [组件visible配置参考](../quick-start/module-configuration-file.md#abilities标签)

- **位于后台的应用，启动组件需校验BACKGROUND权限**
  - 应用前后台判断标准：若应用进程获焦或所属的UIAbility位于前台则判定为前台应用，否则为后台应用
  - 需校验`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限

- **使用startAbilityByCall接口，需校验CALL权限**（使用方式参考：[Call调用开发指南（同设备）](uiability-intra-device-interaction.md#通过call调用实现uiability交互仅对系统应用开放)，[Call调用开发指南（跨设备）](hop-multi-device-collaboration.md#通过跨设备call调用实现多端协同)）
  - 需校验`ohos.permission.ABILITY_BACKGROUND_COMMUNICATION`权限


> **说明：**
> 1. 组件启动管控自OpenHarmony v3.2 Release版本开始落地。
> 
> 2. 与原本的启动规则不同，新的组件启动规则较为严格，开发者需熟知启动规则，避免业务功能异常。

启动组件的具体校验流程见下文。


## 同设备组件启动规则

  设备内启动组件，不同场景下的规则不同，可分为如下两种场景：

- 启动或连接组件：UIAbility、ServiceExtensionAbility、DataShareExtensionAbility。

- 通过startAbilityByCall接口启动UIAbility。

![startup-rule](figures/component-startup-inner-stage.png)


## 分布式跨设备组件启动规则

  跨设备启动组件，不同场景下的规则不同，可分为如下两种场景：

- 启动或连接组件：UIAbility、ServiceExtensionAbility、DataShareExtensionAbility。

- 通过startAbilityByCall接口启动UIAbility。

![component-startup-rules](figures/component-startup-inter-stage.png)
