# 包管理子系统Changelog

## cl.bundlemanager.1 快捷方式配置文件中不支持通过资源索引的方式（以$字符起始）配置shortcutId字段

**访问级别**

公开接口

**变更原因**

系统不支持应用的快捷方式配置文件中[shortcutId字段](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/module-configuration-file.md#shortcuts%E6%A0%87%E7%AD%BE)通过索引方式（以`$`字符起始）配置。

**变更影响**

该变更涉及应用适配。

变更前：可以通过资源索引的方式（以`$`字符起始）配置shortcutId字段。

变更后：不可以通过资源索引的方式（以`$`字符起始）配置shortcutId字段。

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.1.0.50 版本开始。

**变更的接口/组件**

module.json5中shortcuts标签。

**适配指导**

快捷方式配置文件中shortcutId字段如果配置以`$`起始的资源索引方式的字符串，需要更改为普通字符串（不以`$`字符起始）。