# HiSysEvent概述


## 简介 

HiSysEvent是面向OpenHarmony系统开发者提供的系统打点功能，通过在关键路径埋点来记录系统在运行过程中的重要信息，辅助开发者定位问题，此外还支持开发者将打点数据上传到云进行大数据质量度量。

HiSysEvent包括HiSysEvent打点配置、HiSysEvent打点、HiSysEvent订阅、HiSysEvent查询以及HiSysEvent工具模块，各模块能力介绍如下：

- [HiSysEvent打点配置](subsys-dfx-hisysevent-logging-config.md)：提供了事件打点配置的相关能力，支持在yaml文件中对打点事件进行定义。

- [HiSysEvent打点](subsys-dfx-hisysevent-logging.md)：提供了事件打点的相关接口能力，支持对打点事件进行落盘。

- [HiSysEvent订阅](subsys-dfx-hisysevent-listening.md)：提供了事件订阅的相关接口能力，支持根据事件领域和事件名称来对打点事件进行订阅。

- [HiSysEvent查询](subsys-dfx-hisysevent-query.md)：提供了事件查询的相关接口能力，支持根据事件领域和事件名称来对打点事件进行查询。

- [HiSysEvent工具](subsys-dfx-hisysevent-tool.md)：提供了HiSysEvent工具，支持通过该工具来实时订阅打点事件及查询历史打点事件。

## 参考

如果您想了解更多关于HiSysEvent特性的源码及使用信息，请参考[HiSysEvent代码仓](https://gitee.com/openharmony/hiviewdfx_hisysevent)。