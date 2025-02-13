# Form Kit（卡片开发服务）<!--form-kit-->
- [Form Kit简介](formkit-overview.md)
- 服务卡片开发指导（Stage模型）<!--arkts-ui-widget-stage-->
  - 开发基于ArkTS UI的卡片<!--arkts-ui-widget-->
    - [ArkTS卡片运行机制](arkts-ui-widget-working-principles.md)
    - [ArkTS卡片相关模块](arkts-ui-widget-modules.md)
    - ArkTS卡片开发指导<!--arkts-ui-widget-dev-->
      - [创建一个ArkTS卡片](arkts-ui-widget-creation.md)
      - [配置卡片的配置文件](arkts-ui-widget-configuration.md)
      - [卡片生命周期管理](arkts-ui-widget-lifecycle.md)
      - 开发卡片页面<!--arkts-ui-widget-page-->
        - [卡片页面能力说明](arkts-ui-widget-page-overview.md)
        - [卡片使用动效能力](arkts-ui-widget-page-animation.md)
        - [卡片使用自定义绘制能力](arkts-ui-widget-page-custom-drawing.md)
      - 开发卡片事件<!--arkts-ui-widget-event-->
        - [卡片事件能力说明](arkts-ui-widget-event-overview.md)
        - [拉起卡片提供方的UIAbility(router事件)](arkts-ui-widget-event-router.md)
        - [拉起卡片提供方的UIAbility到后台(call事件)](arkts-ui-widget-event-call.md)
        - [通过message事件刷新卡片内容](arkts-ui-widget-event-formextensionability.md)
        - [通过router或call事件刷新卡片内容](arkts-ui-widget-event-uiability.md)
      - 卡片数据交互<!--arkts-ui-widget-interaction-->
        - [卡片内容更新](arkts-ui-widget-interaction-overview.md)
        - [卡片定时刷新](arkts-ui-widget-update-by-time.md)
        - [卡片定点刷新](arkts-ui-widget-update-by-time-point.md)
        <!--Del-->
        - [卡片代理刷新](arkts-ui-widget-update-by-proxy.md)
        - [卡片条件刷新](arkts-ui-widget-update-by-conditions.md)
        - [卡片使用方主动请求刷新卡片内容（仅对系统应用开放）](arkts-ui-widget-content-update.md)
        <!--DelEnd-->
        - [刷新本地图片和网络图片](arkts-ui-widget-image-update.md)
        - [根据卡片状态刷新不同内容](arkts-ui-widget-update-by-status.md)
    <!--Del-->
    - [卡片使用方开发指导（仅对系统应用开放）](widget-host-development-guide.md)
    <!--DelEnd-->
  - [开发基于JS UI的卡片](js-ui-widget-development.md)
- [服务卡片开发指导（FA模型）](widget-development-fa.md)