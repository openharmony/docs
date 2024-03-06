# 包管理子系统变更说明

## cl.bundlemanager.1 HapModuleInfo中fileContextMenu字段变更

**访问级别**

公开接口

**变更原因**

字段命名不合理，难以理解。

**变更影响**

该变更为不兼容变更，使用到该字段的应用需要将fileContextMenu修改为fileContextMenuConfig。仅字段名称发生改变，字段含义、用法不变。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3版本开始。

**变更的接口/组件**

HapModuleInfo中fileContextMenu字段修改为fileContextMenuConfig。

**适配指导**

使用到该字段的应用需要将fileContextMenu修改为fileContextMenuConfig。
