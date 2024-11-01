# 包管理子系统变更说明

## cl.bundlemanager.1 RouterItem下data字段类型变更和路由表配置文件中data字段的类型变更

**访问级别**

公开接口

**变更原因**

在之前的[路由表data字段变更](../OpenHarmony_5.0.0.24/changelogs-bundlemanager.md)中，引入了非兼容性修改，特此回退非兼容性修改（回退data类型变更）。

**变更影响**

该变更为非兼容性变更。开发者在路由表配置文件中使用了任意类型的自定义数据，则会编译报错。开发者如果不修改data字段的类型，会导致编译失败。

**变更发生版本**

从OpenHarmony SDK 5.0.0.30版本开始。

**变更的接口/组件**

路由表配置文件中data字段，由可以配置任意数据类型的自定义数据修改为只能配置字符串类型的自定义数据。包管理提供的RouterItem结构体中data字段由修改为DataItem数组类型。

**适配指导**

开发者在路由表配置文件中，data字段只能配置字符串类型的键值对，若开发者想配置任意类型的自定义数据，可以使用customData字段代替。
开发者在代码中使用了包管理结构体RouterItem中data字段，需要适配data字段的类型更改。