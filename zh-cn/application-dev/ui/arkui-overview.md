# 方舟开发框架概述

## 框架介绍

方舟开发框架（简称：ArkUI），是一套UI开发框架，提供开发者进行应用UI开发时所必需的能力。


## 基本概念

- 组件：组件是界面搭建与显示的最小单位。开发者通过多种组件的组合，构建出满足自身应用诉求的完整界面。

- 页面：page页面是方舟开发框架最小的调度分割单位。开发者可以将应用设计为多个功能页面，每个页面进行单独的文件管理，并通过路由API实现页面的调度管理，以实现应用内功能的解耦。


## 主要特征

- UI组件：方舟开发框架不仅提供了多种基础组件，如文本显示、图片显示、按键交互等，也提供了支持视频播放能力的媒体组件。并且针对不同类型设备进行了组件设计，提供了组件在不同平台上的样式适配能力，此种组件称为“多态组件”。

- 布局：UI界面设计离不开布局的参与。方舟开发框架提供了多种布局方式，不仅保留了经典的弹性布局能力，也提供了列表、宫格、栅格布局和适应多分辨率场景开发的原子布局能力。

- 动画：方舟开发框架对于UI界面的美化，除了组件内置动画效果外，也提供了属性动画、转场动画和自定义动画能力。

- 绘制：方舟开发框架提供了多种绘制能力，以满足开发者绘制自定义形状的需求，支持图形绘制、颜色填充、文本绘制、图片绘制等。

- 交互事件：方舟开发框架提供了多种交互能力，满足应用在不同平台通过不同输入设备均可正常进行UI交互响应，默认适配了触摸手势、遥控器、鼠标等输入操作，同时也提供事件通知能力。

- 平台API通道：方舟开发框架提供了API扩展机制，平台能力通过此种机制进行封装，提供风格统一的JS接口。

- 两种开发范式：方舟开发框架针对不同目的和技术背景的开发者提供了两种开发范式，分别是基于JS扩展的类Web开发范式（简称“类Web开发范式”）和基于TS扩展的声明式开发范式（简称“声明式开发范式”）。

  | 开发范式名称   | 简介                                       | 适用场景             | 适用人群                |
  | -------- | ---------------------------------------- | ---------------- | ------------------- |
  | 类Web开发范式 | 采用经典的HML、CSS、JavaScript三段式开发方式。使用HML标签文件进行布局搭建，使用CSS文件进行样式描述，使用JavaScript文件进行逻辑处理。UI组件与数据之间通过单向数据绑定的方式建立关联，当数据发生变化时，UI界面自动触发更新。此种开发方式，更接近Web前端开发者的使用习惯，快速将已有的Web应用改造成方舟开发框架应用。 | 界面较为简单的中小型应用和卡片  | Web前端开发人员           |
  | 声明式开发范式  | 采用TS语言并进行声明式UI语法扩展，从组件、动效和状态管理三个维度提供了UI绘制能力。UI开发更接近自然语义的编程方式，让开发者直观地描述UI界面，不必关心框架如何实现UI绘制和渲染，实现极简高效开发。同时，选用有类型标注的TS语言，引入编译期的类型校验。 | 复杂度较大、团队合作度较高的程序 | 移动系统应用开发人员、系统应用开发人员 |



### 框架结构

![zh-cn_image_0000001183709904](figures/zh-cn_image_0000001183709904.png)

从上图可以看出，类Web开发范式与声明式开发范式的UI后端引擎和语言运行时是共用的，其中，UI后端引擎实现了方舟开发框架的六种基本能力。声明式开发范式无需JS Framework进行页面DOM管理，渲染更新链路更为精简，占用内存更少，因此更推荐开发者选用声明式开发范式来搭建应用UI界面。
