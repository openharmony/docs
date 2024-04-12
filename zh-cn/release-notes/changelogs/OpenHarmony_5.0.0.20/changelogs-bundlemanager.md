# 包管理子系统删除说明

## cl.bundlemanager.1 RouterItem结构体中删除pageModule字段

**访问级别**

公开接口

**删除原因**

RouterItem结构体中，已不再需要pageModule字段。

**删除影响**

该变更为非兼容性修改。开发者若使用RouterItem结构体中的pageModule字段，将会编译失败。

**API Level**

12

**删除发生版本**

从OpenHarmony SDK 5.0.0.20开始。

**删除的接口/组件**

RouterItem结构体中，删除pageModule字段。

**适配指导**

删除RouterItem结构体中的pageModule字段。

## cl.bundlemanager.2 router_map配置文件中删除pageModule字段

**访问级别**

公开接口

**删除原因**

路由表配置文件router_map.json的schema文件中删除pageModule字段。

**删除影响**

该变更为非兼容性修改。开发者若在路由表配置文件中配置pageModule字段，将会json schema校验失败，导致编译失败。

**API Level**

12

**删除发生版本**

从OpenHarmony SDK 5.0.0.20开始。

**删除的接口/组件**

路由表配置文件router_map.json的schema文件中删除pageModule字段。

**适配指导**

删除路由表配置文件中的pageModule字段。