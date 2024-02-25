# 概述

兼容JS的类Web开发范式的方舟开发框架，采用经典的HML、CSS、JavaScript三段式开发方式。使用HML标签文件进行布局搭建，使用CSS文件进行样式描述，使用JavaScript文件进行逻辑处理。UI组件与数据之间通过单向数据绑定的方式建立关联，当数据发生变化时，UI界面自动触发更新。此种开发方式，更接近Web前端开发者的使用习惯，快速将已有的Web应用改造成方舟开发框架应用。主要适用于界面较为简单的中小型应用开发。

请参考[兼容JS的类Web开发范式API](../reference/apis-arkui/arkui-js/js-components-common-attributes.md)文档，全面地了解组件，更好地开发应用。


## 整体架构

兼容JS的类Web开发范式的方舟开发框架，包括应用层（Application）、前端框架层（Framework）、引擎层（Engine）和平台适配层（Porting Layer）。



![zh-cn_image_0000001117452952](figures/zh-cn_image_0000001117452952.png)

- **Application**

  应用层表示开发者开发的FA应用，这里的FA应用特指JS FA应用。

- **Framework**

  前端框架层主要完成前端页面解析，并提供MVVM（Model-View-ViewModel）开发模式、页面路由机制和自定义组件等能力。

- **Engine**

  引擎层主要提供动画解析、DOM（Document Object Model）树构建、布局计算、渲染命令构建与绘制、事件管理等能力。

- **Porting Layer**

  适配层主要对平台层进行抽象，提供抽象接口，可以对接到系统平台。比如：事件对接、渲染管线对接和系统生命周期对接等。
