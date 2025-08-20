# 仅MDM应用可用权限

<!--Kit: ArkUI-->
<!--Subsystem: Security-->
<!--Owner: @harylee-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

以下权限仅对MDM（Mobile Device Management）设备管理应用开放。MDM应用的详细介绍，请参考[MDM Kit简介](../../mdm/mdm-kit-intro.md)。

> **注意：**
> 
> 以下权限不支持自动签名，因此在调试和发布阶段，均需参照[手动签名](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-signing#section297715173233)的步骤，完成手动签名。

## ohos.permission.ENTERPRISE_GET_DEVICE_INFO

允许应用激活设备管理应用。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_GET_NETWORK_INFO

允许设备管理应用查询网络信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_INSTALL_BUNDLE

允许设备管理应用安装和卸载包。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

允许设备管理应用设置应用运行管理策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_RESET_DEVICE

允许设备管理应用恢复设备出厂设置。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

允许设备管理应用设置账户管理策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

允许设备管理应用设置包安装管理策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_SET_DATETIME

允许设备管理应用设置系统时间。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：9

## ohos.permission.ENTERPRISE_SET_NETWORK

允许设备管理应用设置网络信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_SET_WIFI

允许设备管理应用设置和查询WiFi信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

允许设备管理应用订阅管理事件。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：9

## ohos.permission.ENTERPRISE_RESTRICT_POLICY

允许设备管理员下发和获取限制类策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_SET_SCREENOFF_TIME

允许设备管理员设置系统休眠时间。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_MANAGE_USB

允许设备管理员管理USB。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_MANAGE_NETWORK

允许设备管理员管理网络。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

允许设备管理员管理证书。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_GET_SETTINGS

允许设备管理员查询“设置”应用数据。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE

允许在企业设备上安装企业MDM应用包。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.INSTALL_SELF_BUNDLE

允许企业MDM应用在企业设备上自升级。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

允许设备设置/取消浏览器策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：10

## ohos.permission.SET_ENTERPRISE_INFO

允许设备管理应用设置企业信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：9

## ohos.permission.ENTERPRISE_MANAGE_SECURITY

允许设备设置安全管理策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

允许设备管理应用设置和查询蓝牙信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_MANAGE_SYSTEM

允许设备管理系统设置参数策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_MANAGE_WIFI

允许设备管理应用设置和查询WIFI信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

允许设备管理应用管理限制策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_MANAGE_APPLICATION

允许设备管理应用管理应用策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_MANAGE_LOCATION

允许设备管理应用设置和查询位置信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_REBOOT

允许设备管理应用进行关机重启操作。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_LOCK_DEVICE

允许设备管理应用锁定设备。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_MANAGE_SETTINGS

允许设备管理应用管理设置。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：11

## ohos.permission.ENTERPRISE_OPERATE_DEVICE

允许设备管理应用操作设备。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：12

## ohos.permission.ENTERPRISE_ADMIN_MANAGE

允许应用管理设备管理应用。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：12

## ohos.permission.ENTERPRISE_RECOVERY_KEY

允许应用管理企业级恢复密钥。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：13

## ohos.permission.ENTERPRISE_MANAGE_DELEGATED_POLICY

允许设备管理应用委托其他应用设置设备管控策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：14

## ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

允许设备管理应用获取设备所有应用信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

允许设备管理应用限制用户修改系统设置。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.ENTERPRISE_MANAGE_APN

允许设备管理应用管理设备APN策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

允许设备管理应用管理设备通话策略。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.ENTERPRISE_SET_KIOSK

允许设备管理应用设置Kiosk模式。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.ENTERPRISE_MANAGE_LOCAL_PUBLICSPACES

允许企业应用启用、创建、删除工作空间。

获取此权限后，应用可以设置空间切换免密登录时间、用户照片、不允许删除的空间列表等。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：PC/2in1

**起始版本**：20

## ohos.permission.ENTERPRISE_FILE_TRANSFER_AUDIT_POLICY_MANAGEMENT

允许MDM应用管理文件传输的策略和审计信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：PC/2in1

**起始版本**：20

## ohos.permission.ENTERPRISE_SET_WALLPAPER

允许设备管理应用设置壁纸。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.MANAGE_PREINSTALLED_ANTIVIRUS

允许MDM应用管理系统预装的防病毒软件。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：PC/2in1

**起始版本**：20

## ohos.permission.ENTERPRISE_MANAGE_USER_GRANT_PERMISSION

允许设备管理应用（MDM）设置user_grant类权限策略。

获取该权限后，MDM应用可设置被管理应用user_grant类权限策略，策略支持静默授予，拒绝授予以及默认（即不影响应用申请）。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20