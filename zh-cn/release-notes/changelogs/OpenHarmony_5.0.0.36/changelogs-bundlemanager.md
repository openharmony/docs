# 包管理子系统变更说明

## cl.bundlemanager.1 bm命令行工具变更

**访问级别**

其他

**变更原因**

bm install、bm uninstall命令在-u未指定情况下，默认为全部用户，需要变更为当前活跃用户，提高安全性。

**变更影响**

该变更为不兼容变更。

变更前：
bm install、bm uninstall命令在-u未指定情况下，默认为全部用户。

变更后：
bm install、bm uninstall命令在-u未指定情况下，默认当前活跃用户。

**API Level**

不涉及

**变更发生版本**

从系统OpenHarmony 5.0.0.36 版本开始。

**适配指导**

不涉及