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

**变更信息**：API 10-14时，其权限级别为system_core，仅面向MDM应用开放；从API 14开始，权限级别变更为system_basic，开发范围变更为企业普通应用。

## ohos.permission.FILE_GUARD_MANAGER

允许应用进行公共目录扫描及设置文件扩展属性。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

**变更信息**：API 10-14时，其权限级别为system_core，仅面向MDM应用开放；从API 14开始，权限级别变更为system_basic，开发范围变更为企业普通应用。

## ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

允许应用跨系统本地账号交互。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：7

**变更信息**：API 7-13该权限仅向系统应用开放；从API 14开始，开放范围变更为企业普通应用。

## ohos.permission.GET_WIFI_CONFIG

允许应用获取Wi-Fi的配置信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8

**变更信息**：API 8-14该权限仅向系统应用开放；从API 15开始，开放范围变更为企业普通应用。

## ohos.permission.SET_WIFI_CONFIG

允许应用配置Wi-Fi信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8

**变更信息**：API 8-14该权限仅向系统应用开放；从API 15开始，开放范围变更为企业普通应用。

## ohos.permission.GET_DOMAIN_ACCOUNTS

允许应用查询域账号信息。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

**变更信息**：API 10-13该权限仅向系统应用开放；从API 14开始，开放范围变更为企业普通应用。

## ohos.permission.QUERY_AUDIT_EVENT

允许应用查询安全审计事件。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：12

**变更信息**：API 12-13该权限仅面向MDM应用开放；从API 14开始，开放范围变更为企业普通应用。

## ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

允许系统应用和运营商应用设置eSIM昵称和激活eSIM。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：14

**变更信息**：从API 14开始，权限级别变更为system_basic，开发范围从所有应用变更为企业普通应用。

## ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

允许应用管理Wi-Fi的连接。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：15

## ohos.permission.ACCESS_ENTERPRISE_USER_TRUSTED_CERT

允许应用管理企业设备的用户CA证书。

在企业设备上企业应用使用私有的CA证书认证企业服务器时，该权限用于允许企业应用把私有CA证书安装到企业设备上，并对安装的CA证书进行管理操作。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：16

## ohos.permission.MANAGE_NET_FIREWALL

允许系统应用配置防火墙规则。

当前仅2in1设备应用可申请此权限。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：12

**变更信息**：API 12-14该权限仅向系统应用开放；从API 15开始，开放范围变更为企业普通应用。

## ohos.permission.GET_NET_FIREWALL

允许系统应用查询防火墙规则和查询防火墙拦截记录。

当前仅2in1设备应用可申请此权限。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：12

**变更信息**：API 12-14该权限仅向系统应用开放；从API 15开始，开放范围变更为企业普通应用。

## ohos.permission.GET_DOMAIN_ACCOUNT_SERVER_CONFIGS

允许应用获取域账号服务器配置。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：16

## ohos.permission.MANAGE_DOMAIN_ACCOUNT_SERVER_CONFIGS

允许应用管理域账号服务器配置。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：16

## ohos.permission.MANAGE_DOMAIN_ACCOUNTS

允许应用管理域账号。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：16

## ohos.permission.GET_SIGNATURE_INFO

允许应用获取应用包的签名信息。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：16
