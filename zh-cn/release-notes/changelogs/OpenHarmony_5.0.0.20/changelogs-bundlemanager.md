# 包管理子系统删除说明

## cl.bundlemanager.1 路由表配置文件中pageModule字段删除

**访问级别**

公开接口

**删除原因**

在路由表整体方案设计里，路由表配置文件routerMap.json中不再需要pageModule字段，故删除该字段。

**删除影响**

该变更为非兼容性修改。开发者若在路由表配置文件中配置pageModule字段，将会JSON schema校验失败，导致编译失败。开发者若使用定义在bundleManager模块下HapModuleInfo.d.ts文件中的RouterItem结构体中的pageModule字段，也会导致编译失败。

**API Level**

12

**删除发生版本**

从OpenHarmony SDK 5.0.0.20开始。

**删除的接口/组件**

路由表配置文件routerMap.json中删除pageModule字段，定义在HapModuleInfo.d.ts文件中的RouterItem结构体中删除pageModule字段。

**适配指导**

删除路由表配置文件中的pageModule字段，删除RouterItem结构体中的pageModule字段。