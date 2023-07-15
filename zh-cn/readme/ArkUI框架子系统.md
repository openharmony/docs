# ArkUI框架子系统

## 简介

ArkUI框架是OpenHarmony UI开发框架，提供开发者进行应用UI开发时所必需的能力，包括UI组件、动画、绘制、交互事件、JS API扩展机制等。ArkUI框架提供了两种开发范式，分别是基于ArkTS的声明式开发范式（简称“声明式开发范式”）和兼容JS的类Web开发范式（简称“类Web开发范式”）。

**框架结构**

![zh-cn_image_0000001183709904](../application-dev/ui/figures/arkui-framework.png)

从上图可以看出，类Web开发范式与声明式开发范式的UI后端引擎和语言运行时是共用的，其中，UI后端引擎实现了ArkUI框架的六种基本能力。声明式开发范式无需JS Framework进行页面DOM管理，渲染更新链路更为精简，占用内存更少，因此更推荐开发者选用声明式开发范式来搭建应用UI界面。


## 目录

ArkUI开发框架源代码在/foundation/arkui下，目录结构如下图所示：

```
/foundation/arkui
├── ace_engine                       # ArkUI框架
├── ace_engine_lite                  # 轻量级ArkUI框架
└── napi                             # JS API扩展Native开发模块
```

## 相关仓

**ArkUI框架子系统**

[arkui\_ace\_engine](https://gitee.com/openharmony/arkui_ace_engine)

[arkui\_ace\_engine\_lite](https://gitee.com/openharmony/arkui_ace_engine_lite)

[arkui\_napi](https://gitee.com/openharmony/arkui_napi)

