# UIAbility组件概述


## 概述

UIAbility组件是一种包含UI的应用组件，主要用于和用户交互。

UIAbility的设计理念：

1. 原生支持应用组件级的[跨端迁移](hop-cross-device-migration.md)和[多端协同](hop-multi-device-collaboration.md)。

2. 支持多设备和多窗口形态。

> **说明：**
>
> 详细请参见[Stage模型的设计理念](application-model-description.md)。

UIAbility划分原则与建议：

UIAbility组件是系统调度的基本单元，为应用提供绘制界面的窗口。一个应用可以包含一个或多个UIAbility组件。例如，在支付应用中，可以将入口功能和收付款功能分别配置为独立的UIAbility。

每一个UIAbility组件实例都会在最近任务列表中显示一个对应的任务。

对于开发者而言，可以根据具体场景选择单个还是多个UIAbility，划分建议如下：

- 如果开发者希望在任务视图中看到一个任务，则建议使用一个UIAbility，多个页面的方式。

- 如果开发者希望在任务视图中看到多个任务，或者需要同时开启多个窗口，则建议使用多个UIAbility开发不同的模块功能。

## 声明配置

为使应用能够正常使用UIAbility，需要在[module.json5配置文件](../quick-start/module-configuration-file.md)的[abilities标签](../quick-start/module-configuration-file.md#abilities标签)中声明UIAbility的名称、入口、标签等相关信息。


```json
{
  "module": {
    ...
    "abilities": [
      {
        "name": "EntryAbility", // UIAbility组件的名称
        "srcEntry": "./ets/entryability/EntryAbility.ts", // UIAbility组件的代码路径
        "description": "$string:EntryAbility_desc", // UIAbility组件的描述信息
        "icon": "$media:icon", // UIAbility组件的图标
        "label": "$string:EntryAbility_label", // UIAbility组件的标签
        "startWindowIcon": "$media:icon", // UIAbility组件启动页面图标资源文件的索引
        "startWindowBackground": "$color:start_window_background", // UIAbility组件启动页面背景颜色资源文件的索引
        ...
      }
    ]
  }
}
```
