# UIAbility组件概述


## 概述

UIAbility组件是一种包含UI界面的应用组件，主要用于和用户交互。

UIAbility组件是系统调度的基本单元，为应用提供绘制界面的窗口；一个UIAbility组件中可以通过多个页面来实现一个功能模块。每一个UIAbility组件实例，都对应于一个最近任务列表中的任务。


## 声明配置

为使应用能够正常使用UIAbility，需要在[module.json5配置文件](../quick-start/module-configuration-file.md)的[abilities标签](../quick-start/module-configuration-file.md#abilities标签)中声明UIAbility的名称、入口、标签等相关信息。


```json
{
  "module": {
    // ...
    "abilities": [
      {
        "name": "EntryAbility", // UIAbility组件的名称
        "srcEntrance": "./ets/entryability/EntryAbility.ts", // UIAbility组件的代码路径
        "description": "$string:EntryAbility_desc", // UIAbility组件的描述信息
        "icon": "$media:icon", // UIAbility组件的图标
        "label": "$string:EntryAbility_label", // UIAbility组件的标签
        "startWindowIcon": "$media:icon", // UIAbility组件启动页面图标资源文件的索引
        "startWindowBackground": "$color:start_window_background", // UIAbility组件启动页面背景颜色资源文件的索引
        // ...
      }
    ]
  }
}
```

> **说明：**
> Ability的组成请参见在[模块中添加Ability](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/ohos-adding-ability-0000001218280664-V3)。
