# Ability Kit（程序框架服务）<!--ability-kit-->

- [Ability Kit简介](abilitykit-overview.md)
- [应用模型](application-models.md)
- Stage模型开发指导<!--stage-model-development-->
  - [Stage模型开发概述](stage-model-development-overview.md)
  - Stage模型应用组件<!--stage-model-application-components-->
    - [应用/组件级配置](application-component-configuration-stage.md)
    - UIAbility组件<!--uiability-->
      - [UIAbility组件概述](uiability-overview.md)
      - [UIAbility组件生命周期](uiability-lifecycle.md)
      - [UIAbility组件启动模式](uiability-launch-type.md)
      - [UIAbility组件基本用法](uiability-usage.md)
      - [UIAbility组件与UI的数据同步](uiability-data-sync-with-ui.md)
      - [启动应用内的UIAbility组件](uiability-intra-device-interaction.md)
      - [UIAbility备份恢复](ability-recover-guideline.md)
    - [ExtensionAbility组件](extensionability-overview.md)
      <!--Del-->
      - [ServiceExtensionAbility（仅对系统应用开放）](serviceextensionability.md)
      - [UIServiceExtension（仅对系统应用开放）](uiserviceextension-sys.md)
      - [UIExtensionAbility（仅对系统应用开放）](uiextensionability.md)
      - [AutoFillExtensionAbility（仅对系统应用开放）](autofillextensionablility-guide.md)
      <!--DelEnd-->
      - [UIServiceExtension](uiserviceextension.md)
      - [EmbeddedUIExtensionAbility](embeddeduiextensionability.md)
      - [使用AppServiceExtensionAbility实现后台服务](app-service-extension-ability.md)
    - [AbilityStage组件容器](abilitystage.md)
    - [应用上下文Context](application-context-stage.md)
    - 信息传递载体Want<!--want-->
      - [Want概述](want-overview.md)
      - [显式Want与隐式Want匹配规则](explicit-implicit-want-mappings.md)
      - [使用显式Want启动应用组件](ability-startup-with-explicit-want.md)
      - [常见action与entities（不推荐使用）](actions-entities.md)
    - [组件启动规则（Stage模型）](component-startup-rules.md)
    - [应用启动框架AppStartup](app-startup.md)
    - [获取应用异常退出原因](ability-exit-info-record.md)
    <!--Del-->
    - 应用组件跨设备交互（流转）<!--hop-->
      - [流转概述](inter-device-interaction-hop-overview.md)
      - [跨端迁移](hop-cross-device-migration.md)
      - [多端协同](hop-multi-device-collaboration.md)
    <!--DelEnd-->
    - [订阅系统环境变量的变化](subscribe-system-environment-variable-changes.md)
  - 应用间跳转<!--inter-app-redirection-->
    - [应用间跳转概述](link-between-apps-overview.md)
    - 拉起指定应用<!--directional-redirection-->
      - [拉起指定应用概述](app-startup-overview.md)
      - [（可选）使用canOpenLink判断应用是否可访问](canopenlink.md)
      - [使用Deep Linking实现应用间跳转](deep-linking-startup.md)
      <!--Del-->
      - [使用App Linking实现应用间跳转](app-linking-startup.md)
      <!--DelEnd-->
      - [显式Want跳转切换应用链接跳转适配指导](uiability-startup-adjust.md)
      - [应用链接说明](app-uri-config.md)
    - 拉起指定类型的应用<!--specified-type-app-redirection-->
      - [拉起指定类型的应用概述](start-intent-panel.md)
      - [拉起导航类应用（startAbilityByType）](start-navigation-apps.md)
      - [拉起邮件类应用（startAbilityByType）](start-email-apps.md)
      - [拉起邮件类应用（mailto方式）](start-email-apps-by-mailto.md)
      - [拉起金融类应用（startAbilityByType）](start-finance-apps.md)
      - [拉起航班类应用（startAbilityByType）](start-flight-apps.md)
      - [拉起快递类应用（startAbilityByType）](start-express-apps.md)
      - [拉起图片编辑类应用（startAbilityByType）](photoEditorExtensionAbility.md)
      - [拉起文件处理类应用（startAbility）](file-processing-apps-startup.md)
    - [拉起系统应用](system-app-startup.md)
  - [进程模型](process-model-stage.md)
  - [线程模型](thread-model-stage.md)
  <!--Del-->
  - 任务（Mission）管理（仅对系统应用开放）<!--mission-management-->
    - [任务（Mission）管理场景介绍](mission-management-overview.md)
    - [任务（Mission）与启动模式](mission-management-launch-type.md)
    - [页面栈及任务链](page-mission-stack.md)
    - [设置任务快照的图标和名称](mission-set-icon-name-for-task-snapshot.md)
  <!--DelEnd-->
  - [Stage模型应用配置文件](config-file-stage.md)
- FA模型开发指导<!--fa-model-development-->
  - [FA模型开发概述](fa-model-development-overview.md)
  - FA模型应用组件<!--fa-model-application-components-->
    - [应用/组件级配置](application-component-configuration-fa.md)
    - PageAbility组件开发指导<!--pageability-->
      - [PageAbility组件概述](pageability-overview.md)
      - [PageAbility组件配置](pageability-configuration.md)
      - [PageAbility的生命周期](pageability-lifecycle.md)
      - [PageAbility的启动模式](pageability-launch-type.md)
      - [创建PageAbility](create-pageability.md)
      - [启动本地PageAbility](start-local-pageability.md)
      - [停止PageAbility](stop-pageability.md)
      <!--Del-->
      - [启动远程PageAbility（仅对系统应用开放）](start-remote-pageability.md)
      <!--DelEnd-->
      - [启动指定页面](start-page.md)
      - [窗口属性](window-properties.md)
      - [申请授权](request-permissions.md)
      - [跳转规则](redirection-rules.md)
    - ServiceAbility组件开发指导<!--serviceability-->
      - [ServiceAbility组件概述](serviceability-overview.md)
      - [ServiceAbility组件配置](serviceability-configuration.md)
      - [ServiceAbility的生命周期](serviceability-lifecycle.md)
      - [创建ServiceAbility](create-serviceability.md)
      - [启动ServiceAbility](start-serviceability.md)
      - [连接ServiceAbility](connect-serviceability.md)
    - DataAbility组件开发指导<!--dataability-->
      - [DataAbility组件概述](dataability-overview.md)
      - [DataAbility组件配置](dataability-configuration.md)
      - [DataAbility的生命周期](dataability-lifecycle.md)
      - [创建DataAbility](create-dataability.md)
      - [启动DataAbility](start-dataability.md)
      - [访问DataAbility](access-dataability.md)
      - [DataAbility权限控制](dataability-permission-control.md)
    - [FA模型的Context](application-context-fa.md)
    - [信息传递载体Want](want-fa.md)
    - [组件启动规则（FA模型）](component-startup-rules-fa.md)
  - [进程模型](process-model-fa.md)
  - [线程模型](thread-model-fa.md)
  <!--Del-->
  - [任务管理（仅对系统应用开放）](mission-management-fa.md)
  <!--DelEnd-->
  - [FA模型应用配置文件](config-file-fa.md)
<!--Del-->
- FA模型与Stage模型应用组件互通指导<!--fa-stage-interaction-->
  - [FA模型与Stage模型应用组件互通综述](fa-stage-interaction-overview.md)
  - [FA模型启动Stage模型UIAbility](start-uiability-from-fa.md)
  - [FA模型绑定Stage模型ServiceExtensionAbility](bind-serviceextensionability-from-fa.md)
  - [FA模型访问Stage模型DataShareExtensionAbility](access-datashareextensionability-from-fa.md)
  - [Stage模型启动FA模型PageAbility](start-pageability-from-stage.md)
  - [Stage模型绑定FA模型ServiceAbility](bind-serviceability-from-stage.md)
- FA模型切换Stage模型指导<!--fa-to-stage-switc-->
  - [模型切换概述](model-switch-overview.md)
  - 配置文件切换<!--configuration-file-switch-->
    - [配置文件的差异](configuration-file-diff.md)
    - [app和deviceConfig的切换](app-deviceconfig-switch.md)
    - [module的切换](module-switch.md)
  - 组件切换<!--component-switch-->
    - [PageAbility切换](pageability-switch.md)
    - [ServiceAbility切换](serviceability-switch.md)
    - [DataAbility切换](dataability-switch.md)
  - [卡片切换](widget-switch.md)
  - API切换<!--api-switch-->
    - [API切换概述](api-switch-overview.md)
    - [Context接口切换](context-switch.md)
    - [featureAbility接口切换](featureability-switch.md)
    - [particleAbility接口切换](particleability-switch.md)
    - [LifecycleForm接口切换](lifecycleform-switch.md)
    - [LifecycleApp接口切换](lifecycleapp-switch.md)
    - [LifecycleService接口切换](lifecycleservice-switch.md)
    - [LifecycleData接口切换](lifecycledata-switch.md)
    - [DataAbilityHelper接口切换](dataabilityhelper-switch.md)
    - [request接口切换](request-switch.md)
    - [resourceManager接口切换](resourcemanager-switch.md)
    - [window接口切换](window-switch.md)
    - [Storage接口切换](storage-switch.md)
<!--DelEnd-->
- Native子进程开发指导<!--native-childprocess-development-->
    - [创建Native子进程](capi_nativechildprocess_development_guideline.md)
    - [获取Native子进程退出信息](capi-nativechildprocess-exit-info.md)
