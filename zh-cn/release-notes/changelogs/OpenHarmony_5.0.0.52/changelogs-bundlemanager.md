# 包管理子系统Changelog

## cl.bundlemanager.1 禁止bm命令进行跨用户操作

**访问级别**

公开接口

**变更原因**

bm命令行工具未对sh调用方用户身份做校验，用户A可以通过bm命令安装、卸载其他用户空间下的应用，并且可以通过bm命令嗅探其他空间下已安装的应用，违反安全规范。

**变更影响**

该变更为不兼容变更。

变更前：
bm命令中install（安装）、uninstall（卸载）、dump（查询）、clean（清空缓存）、disable（禁用应用，仅限root）、enable（使能应用，仅限root）等命令可以通过-u参数指定其他用户。

变更后：
bm命令中install、uninstall、dump、clean、disable、enable等命令通过-u参数指定其他用户无效，仅支持对当前用户下的应用进行相应操作。

**起始API Level**

API 13

**变更发生版本**

从OpenHarmony 5.0.0.52 版本开始。

**变更的接口/组件**

bm命令行工具

**适配指导**

若要对其他用户下的应用执行bm命令行的相关操作，必须先切换至相应的用户，才能执行。