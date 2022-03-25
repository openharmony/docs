# 概述

基于JS扩展的类Web开发范式的方舟开发框架是UI开发框架，提供基础类、容器类、画布类等UI组件和标准CSS动画能力，支持类Web范式编程。


## 基础能力

  采用类HTML和CSS Web编程语言作为页面布局和页面样式的开发语言，页面业务逻辑则支持ECMAScript规范的JavaScript语言。方舟开发框架提供的类Web编程范式，可以让开发者避免编写UI状态切换的代码，视图配置信息更加直观。


## 整体架构

使用基于JS扩展的类Web开发范式的方舟开发框架，包括应用层（Application）、前端框架层（Framework）、引擎层（Engine）和平台适配层（Porting Layer）。



![zh-cn_image_0000001117452952](figures/zh-cn_image_0000001117452952.png)

- **Application**
  应用层表示开发者开发的FA应用，这里的FA应用特指JS FA应用。

- **Framework**
  前端框架层主要完成前端页面解析，以及提供MVVM（Model-View-ViewModel）开发模式、页面路由机制和自定义组件等能力。

- **Engine**
  引擎层主要提供动画解析、DOM（Document Object Model）树构建、布局计算、渲染命令构建与绘制、事件管理等能力。

- **Porting Layer**
  适配层主要完成对平台层进行抽象，提供抽象接口，可以对接到系统平台。比如：事件对接、渲染管线对接和系统生命周期对接等。
