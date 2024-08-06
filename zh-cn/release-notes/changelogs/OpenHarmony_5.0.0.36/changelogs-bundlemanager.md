# 包管理子系统变更说明

## cl.bundlemanager.1 bm命令行工具变更

**访问级别**

其他

**变更原因**

bm install、bm uninstall命令在-u未指定情况下，默认为全部用户，存在安全隐患。

**变更影响**

该变更为非兼容性变更。

 bm install、bm uninstall命令在-u未指定情况下，修改为默认当前活跃用户。

**API Level**

不涉及

**变更发生版本**

从系统OpenHarmony 5.0.0.36 版本开始。

**适配指导**

不涉及