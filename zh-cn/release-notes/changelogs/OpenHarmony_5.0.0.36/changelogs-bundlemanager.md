# 包管理子系统变更说明

## cl.bundlemanager.1 bm命令行工具变更

**访问级别**

其他

**变更原因**

bm install、bm uninstall命令在-u未指定情况下，默认为全部用户，基于安全考虑，变更为当前活跃用户。

**变更影响**

该变更为不兼容变更。

变更前：
bm install、bm uninstall命令在-u未指定情况下，默认为全部用户。

变更后：
bm install、bm uninstall命令在-u未指定情况下，默认当前活跃用户。如果需要为全部用户安装或卸载应用，需要通过-u指定用户id逐一进行安装或卸载。

**API Level**

不涉及

**变更发生版本**

从系统OpenHarmony 5.0.0.36 版本开始。

**适配指导**

不涉及