# 企业类应用可用权限

以下权限面向<!--Del-->系统应用和<!--DelEnd-->企业类应用开放，企业类应用包括企业普通应用和MDM（Mobile Device Management）设备管理应用。

企业类应用的分发类型分别为enterprise_normal（企业普通应用）和enterprise_mdm（MDM应用），开发者可在<!--RP1-->[HarmonyAppProvision配置文件](../app-provision-structure.md)中查询字段`app-distribution-type`。<!--RP1End-->

企业类应用可参考[声明权限](declare-permissions.md)，申请以下权限。

## ohos.permission.SET_FILE_GUARD_POLICY

允许应用下发文件管控策略。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

**变更信息**：API 10-14时，其权限级别为system_core，仅面向MDM应用开放；从API 14开始，权限级别变更为system_basic，开发范围从MDM应用变更为企业普通应用。

## ohos.permission.FILE_GUARD_MANAGER

允许应用进行公共目录扫描及设置文件扩展属性。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

**变更信息**：API 10-14时，其权限级别为system_core，仅面向MDM应用开放；从API 14开始，权限级别变更为system_basic，开发范围从MDM应用变更为企业普通应用。

### ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

允许系统应用和运营商应用设置eSIM昵称和激活eSIM。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：14

**变更信息**：从API 14开始，权限级别变更为system_basic，开发范围从所有应用变更为企业普通应用。

