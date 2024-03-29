# 包管理子系统变更说明

## cl.bundlemanager.1 bm命令行工具变更

**访问级别**

其他

**变更原因**

bm disable、bm enable命令权限过大，一些应用被禁用后会导致必要的流程被跳过。为了保证安全，所以在user版本下禁用bm disable、bm enable命令。
bm clean命令会导致应用的数据被清除，所以在user版本下bm clean命令只有打开开发者模式可用。

**变更影响**

该变更为非兼容性变更。

user版本bm disable、bm enable命令不可用。
user版本bm clean命令在非开发模式下不可用。

**API Level**

不涉及

**变更发生版本**

从系统OpenHarmony 5.0.0.17 版本开始。

**适配指导**

不涉及