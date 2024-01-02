# 包管理子系统变更说明

## cl.bundlemanager.1 ApplicationReservedFlag枚举和ApplicationInfo中的applicationReservedFlag字段删除

**访问级别**

公开接口

**删除原因**

applicationReservedFlag命名过于复杂，不易理解，且当前存储信息没有使用方，可以删除。

**删除影响**

该变更为非兼容性变更。ApplicationInfo中的applicationReservedFlag原本用于存储应用的保留字段，当前仅存储应用是否加密的信息。废弃后，无法再通过applicationReservedFlag获取应用的保留信息。

**删除发生版本**

从OpenHarmony SDK 4.1.5.5开始

**删除的接口/组件**

| 接口声明 | 废弃说明 |
| --------------- | ------- |
| enum ApplicationReservedFlag | 不再需要该枚举来获取相应信息。 |
| readonly applicationReservedFlag: number; | 命名过于复杂，不易理解，当前存储信息没有使用方。 |

**适配指导**

当前该接口没有使用方，applicationReservedFlag中存储的应用加密信息，应用无需感知。
