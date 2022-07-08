# HiSysEvent概述


## 概述

HiSysEvent是面向OpenHarmony系统开发者提供的系统打点功能，通过在关键路径埋点来记录系统在运行过程中的重要信息，辅助开发者定位问题，此外还支持开发者将打点数据上传到云进行大数据质量度量。

HiSysEvent提供给开发者的打点相关能力主要包括事件配置、事件埋点、事件订阅、事件查询以及事件调试工具，各模块能力介绍如下：

- 事件配置：提供了事件的yaml配置能力，支持在yaml文件中对HiSysEvent事件进行定义。

- 事件埋点：提供了事件埋点的相关接口能力，支持对打点的HiSysEvent事件进行落盘。

- 事件订阅：提供了事件订阅的相关接口能力，支持根据事件领域和事件名称来对HiSysEvent事件进行订阅。

- 事件查询：提供了事件查询的相关接口能力，支持根据事件领域和事件名称来对HiSysEvent事件进行查询。

- 事件调试工具：提供了hisysevent工具，支持通过该工具来实时订阅HiSysEvent事件及查询历史HiSysEvent事件。

## 参考

如果您想了解更多关于HiSysEvent特性的源码及使用信息，请参考[HiSysEvent代码仓](https://gitee.com/openharmony/hiviewdfx_hisysevent)。