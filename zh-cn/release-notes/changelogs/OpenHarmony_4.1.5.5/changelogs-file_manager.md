# 文件管理子系统变更说明

## c1.file_manager.1 文件管理模块接口以及相关参数废弃

**访问级别**

系统接口

**废弃原因**

该接口为API11授权方案新增接口，后续因考虑API10已有方案的兼容性问题，授权方案调整，在原有的AMS接口GrantUriPermission上兼容实现，不需要提供这个新的接口，因此该API需要废弃。

**废弃影响**

系统接口的非兼容变更，当前未有发布版本带入，为开发版本接口变更，无需适配。

**API level**

<11>

**废弃发生版本**

从OpenHarmony SDK 4.1.5.1开始。

**废弃的接口/参数**

function grantPermission(tokenId: number, policies: Array<PolicyInfo>, policyFlag: number): Promise<void>

export enum policyFlag

FORBID_PERSISTENCE = 0b10

ALLOW_PERSISTENCE = 0b1

**适配指导**

该接口为API11授权方案新增接口，当前还未有相应版本发布，所以不存在存量应用使用，目前无需开发者适配。