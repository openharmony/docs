# 绑定模态页面概述

模态页面是一种大面板大视图交互式的弹窗，和其他弹窗组件一样，通常用于在保持当前的上下文环境时，临时展示用户需关注的信息或待处理的操作。相比于其他弹窗组件，模态页面的内容都需要开发者通过自定义组件来填充实现，可展示的视图往往也很大。默认需要用户进行交互才能够退出模态页面。ArkUI当前提供了**半模态**和**全模态**两类模态页面组件。

* **​半模态：​**开发者可以利用此模态页面实现多形态效果。支持不同宽度设备显示不同样式的半模态页面。允许用户通过侧滑，点击蒙层，点击关闭按钮，下拉关闭半模态页面。
* **全模态：​**开发者可以利用此模态页面实现全屏的模态弹窗效果。默认需要侧滑才能关闭。

## 使用场景

| 接口|使用场景  |
| ----------| ----------------------------------- |
| [bindContentCover](arkts-contentcover-page.md) | 用于自定义全屏的模态展示界面，结合转场动画和共享元素动画可实现复杂转场动画效果，如缩略图片点击后查看大图。 |
| [bindSheet](arkts-sheet-page.md)  | 用于半模态展示界面，如分享框。 |
| [openBindSheet/ updateBindSheet/closeBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#openbindsheet12) | 用于不依赖UI组件的场景，如全局拉起、更新、关闭。|

## 规格约束

* 建议在<!--Del-->除[ServiceExtension](../../application-dev/application-models/serviceextensionability.md)等<!--DelEnd-->无UI界面的场景外，均使用UIContext中的弹窗方法，其他规格约束，具体可参考 [openBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#openbindsheet12)、[updateBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatebindsheet12)、[closeBindSheet](../reference/apis-arkui/js-apis-arkui-UIContext.md#closebindsheet12) 说明。

