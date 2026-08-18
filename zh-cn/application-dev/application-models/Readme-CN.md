# Ability Kit（程序框架服务）<!--ability-kit-->

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @jayleehw-->
<!--Designer: @jayleehw-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->


- [Ability Kit简介](abilitykit-overview.md)
- 应用模型<!--application-models-->
  - [应用模型概述](stage-model-development-overview.md)
  - 应用组件<!--stage-model-application-components-->
    - [应用/组件级配置](application-component-configuration-stage.md)
    - UIAbility组件<!--uiability-->
      - [UIAbility组件概述](uiability-overview.md)
      - [UIAbility组件生命周期](uiability-lifecycle.md)
      - [UIAbility组件启动模式](uiability-launch-type.md)
      - [UIAbility组件基本用法](uiability-usage.md)
      - [UIAbility组件与UI的数据同步](uiability-data-sync-with-ui.md)
      - [启动应用内的UIAbility组件](uiability-intra-device-interaction.md)
      - [通过Call调用实现多端协同](uiability-cross-device-interaction.md)
      - [UIAbility备份恢复](ability-recover-guideline.md)
    - [ExtensionAbility组件](extensionability-overview.md)
      <!--Del-->
      - [使用AgentExtensionAbility组件提供的智能体服务（仅对系统应用开放）](agent-manager-sys.md)
      - [ServiceExtensionAbility（仅对系统应用开放）](serviceextensionability-sys.md)
      - [UIServiceExtension（仅对系统应用开放）](uiserviceextension-sys.md)
      - [UIExtensionAbility（仅对系统应用开放）](uiextensionability-sys.md)
      - [使用AutoFillExtensionAbility实现自动填充功能（仅对系统应用开放）](autofillextensionability-guide-sys.md)
      - [使用通过UIServiceExtensionAbility实现的系统悬浮窗](uiserviceextension.md)
      <!--DelEnd-->
      - [EmbeddedUIExtensionAbility](embeddeduiextensionability.md)
      - [使用AppServiceExtensionAbility组件实现后台服务](app-service-extension-ability.md)
    - [AbilityStage组件管理器](abilitystage.md)
    - [应用上下文Context](application-context-stage.md)
    - 信息传递载体Want<!--want-->
      - [Want概述](want-overview.md)
      - [显式Want与隐式Want匹配规则](explicit-implicit-want-mappings.md)
      - [使用显式Want启动应用组件](ability-startup-with-explicit-want.md)
      - [常见action与entities（不推荐使用）](actions-entities.md)
    - [组件启动规则](component-startup-rules.md)
    - [获取/设置环境变量](subscribe-system-environment-variable-changes.md)
    <!--Del-->
    - 应用组件跨设备交互（流转）<!--hop-->
      - [流转概述](inter-device-interaction-hop-overview.md)
      - [跨端迁移](hop-cross-device-migration.md)
      - [多端协同](hop-multi-device-collaboration.md)
    <!--DelEnd-->  
  - 进程模型<!--process-model-stage-->
    - [进程模型概述](process-model-overview.md)
    - 扩展进程开发指导<!--extended-process-development-->
      - [子进程开发指导（ArkTS）](arkts-child-process-development-guideline.md)
      - [子进程开发指导（C/C++）](capi-nativechildprocess-development-guideline.md)
    - [独立进程开发指导](isolation-process-development-guideline.md)
  - [线程模型](thread-model-stage.md)
  <!--Del-->
  - 任务（Mission）管理（仅对系统应用开放）<!--mission-management-->
    - [任务（Mission）管理场景介绍（仅对系统应用开放）](mission-management-overview-sys.md)
    - [任务（Mission）与启动模式（仅对系统应用开放）](mission-management-launch-type-sys.md)
    - [页面栈及任务链（仅对系统应用开放）](page-mission-stack-sys.md)
    - [设置任务快照的图标和名称（仅对系统应用开放）](mission-set-icon-name-for-task-snapshot-sys.md)
  <!--DelEnd-->
  - [应用配置文件](config-file-stage.md)
- 应用生命周期<!--app-lifecycle-->
  - [应用生命周期概述](application-lifecycle.md)
  - 应用启动<!--app-start-->
    - [应用启动流程](application-startup-process.md)
    - [应用启动设置](application-startup-options.md)
    - [应用启动框架AppStartup](app-startup.md)
    - [应用预加载](preload-application.md)
    - [应用快启](hyperstartup-application.md)
  - [应用退出](app-stop.md)<!--RP2--><!--RP2End-->
  - [应用重启](app-restart.md)
  - [获取应用异常退出原因](ability-exit-info-record.md)
- 应用间跳转<!--inter-app-redirection-->
  - [应用间跳转概述](link-between-apps-overview.md)
  - 拉起指定应用<!--directional-redirection-->
    - [拉起指定应用概述](app-startup-overview.md)
    - [（可选）使用canOpenLink判断应用是否可访问](canopenlink.md)
    - [获取目标应用的URL信息](obtaining-target-app-url-info.md)
    - [使用Deep Linking实现应用间跳转](deep-linking-startup.md)
    - [使用App Linking实现应用间跳转](app-linking-startup.md)
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
  - [拉起系统应用](system-app-startup.md)<!--RP1--><!--RP1End-->
- 方舟智能开发框架开发指导<!--ark-agentic-framework-->
  - [方舟智能开发框架概述](arkaf-overview.md)
  - 意图框架开发指导<!--insight-intent-->
    - [意图框架概述](insight-intent-overview.md)
    - 开发意图<!--insight-intent-development-->
      - [意图开发概述](insight-intent-definition.md)
      - [使用配置文件开发意图](insight-intent-config-development.md)
      - [使用装饰器开发意图](insight-intent-decorator-development.md)
      - [附录：标准意图接入规范](insight-intent-access-specifications.md)
    - [调试意图](insight-intent-debug.md)
  - [基于ArkTS脚本的应用Skill开发指导](arkts-skill-development-guide.md)
  - 端侧A2A框架开发指导<!--agent-guideline-->
    - [端侧A2A框架概述](agent-overview.md)
    - 开发端侧智能体<!--agent-development-->
      - [使用AgentExtensionAbility组件实现智能体服务](agent-extension-ability.md)
      - [AgentExtensionAbility配置文件说明](agent-extension-configuration.md)
      <!--Del-->
      - [使用AgentExtensionAbility组件提供的智能体服务（仅对系统应用开放）](agent-manager-sys.md)
      <!--DelEnd-->
- 基于ModularObjectExtensionAbility的模块化对象开发指导 (C/C++)<!--modular-object-extension-ability-->
  - [模块化对象模型概述 (C/C++)](modular-object-extension-overview.md)
  - [使用ModularObjectExtensionAbility实现模块化对象 (C/C++)](modular-object-extension-development.md)
  - [使用Taihe实现ModularObjectExtensionAbility的IPC通信 (C/C++)](modular-object-extension-ability-taihe.md)
  - [使用ModularObjectDispatcher实现动态接口调用 (C/C++)](modular-object-dispatcher-development.md)
- [Ability Kit术语](ability-terminology.md)