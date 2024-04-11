# ArkUI子系统变更说明

## cl.arkui.1 Router默认转场动效变更

**访问级别**

公开接口

**变更原因**

ArkUI目前有两套路由框架，Router和Navigation。Navigation在实现时应用了最新UX转场动效的设计规格，为保证体验的一致性，Router也需要按UX转场动效设计规格调整动效时长。

**变更影响**

Router默认转场动效变更。

变更前：动效时长为300ms，效果如图所示。

![Router变更前默认转场动效图](figures/preRouterTransition.gif)

变更后：默认转场动效曲线设置为物理曲线，时长由物理曲线计算得出，约600ms，效果如图所示。

![Router变更后默认转场动效图](figures/curRouterTransition.gif)

**API Level**

起始支持版本为 API 8。

**变更发生版本**

从OpenHarmony SDK 5.0.0.18开始。

**适配指导**

系统默认样式变更调整，无需适配。