# 系统账号介绍

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @pan9f-->
<!--Adviser: @zengyawen-->

## 系统账号ID体系

在OpenHarmony中，每个系统账号在创建时都会被分配一个唯一的整型标识，称为**系统账号ID**，对应[OsAccountInfo](../../reference/apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo)中的`localId`字段。系统账号ID按用途可划分为以下类别：

| 范围 | 类别  | 用途 |
|------|------|------|
| ID=0 | 系统级公共服务账号 | 系统级服务与应用安装并运行在此账号下。 |
| ID=1 | 企业级公共服务账号 | 企业级服务与应用安装并运行在此账号下。 |
| ID=2~99 | 预留的系统账号 | 系统预留，暂未定义。 |
| ID=100+ | 自然人用户账号   | 由自然人使用的账号，ID从100开始。 |

> **说明**：
> 
> 各类系统账号下应用的安装规格，请参考[应用安装说明文档](../../tools/bm-tool.md#userid)。

## 相关文档

- [OsAccountInfo](../../reference/apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo)
