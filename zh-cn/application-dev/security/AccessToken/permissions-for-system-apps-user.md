# 系统应用可用权限（用户授权）

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

在申请目标权限前，建议开发者先了解[不同权限的申请路径](determine-application-mode.md)，对权限的工作流程有基本了解后，再结合以下权限字段的具体说明，判断应用能否申请目标权限，提高开发效率。

> **说明：**
>
> - 以下权限仅对APL等级为system_basic及以上的应用开放，不向APL等级为normal的应用开放。
> - 以下权限的授权方式均为user_grant（用户授权）。
> - 以下权限可通过[访问控制列表（ACL）](app-permission-mgmt-overview.md#权限机制中的基本概念)的方式跨级别申请。

申请流程可参考[选择申请权限的方式](determine-application-mode.md)。

## ohos.permission.GET_INSTALLED_BUNDLE_LIST

允许应用读取已安装应用列表。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：10

## ohos.permission.ANSWER_CALL

允许应用接听来电。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：9

## ohos.permission.MANAGE_VOICEMAIL

允许应用在语音信箱中留言。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.READ_CALL_LOG

允许应用读取通话记录。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.READ_CELL_MESSAGES

允许应用读取设备收到的小区广播信息。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.READ_MESSAGES

允许应用读取短信息。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.RECEIVE_MMS

允许应用接收和处理彩信。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.RECEIVE_SMS

允许应用接收和处理短信。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.RECEIVE_WAP_MESSAGES

允许应用接收和处理WAP消息。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.SEND_MESSAGES

允许应用发送短信。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.WRITE_CALL_LOG

允许应用添加、移除或更改通话记录。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**起始版本**：8

## ohos.permission.cli.WRITE_ACCESSIBILITY_CONFIG_VISION

允许系统应用通过CLI命令使用无障碍视觉辅助功能。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.WRITE_ACCESSIBILITY_CONFIG_HEARING

允许系统应用通过CLI命令使用无障碍听觉辅助功能。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.WRITE_ACCESSIBILITY_CONFIG_ACTION

允许系统应用通过CLI命令使用无障碍行为辅助功能。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.BUNDLE_ACTIVE_INFO

允许应用通过CLI命令查询应用运行状态。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：26.0.0

## ohos.permission.cli.INSTALL_BUNDLE

允许应用通过CLI命令安装、卸载除企业应用外的其他应用。

**权限级别**：system_core

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.UNINSTALL_BUNDLE

允许应用通过CLI命令卸载应用。

**权限级别**：system_core

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.GET_BUNDLE_INFO_PRIVILEGED

允许应用通过CLI命令查询应用信息，如应用包名、版本等。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.REMOVE_BUNDLE_DATA_AND_CACHE_FILES

允许应用通过CLI命令清理指定应用的缓存和数据（包括内部存储和外部存储）。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.MANAGE_DISPOSED_APP_STATUS

允许应用通过CLI命令设置和查询应用的处置状态。

**权限级别**：system_core

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.MANAGE_WIFI_TOGGLE

允许应用通过CLI命令设置Wi-Fi开关。

**权限级别**：system_core

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.MANAGE_WIFI_SCAN

允许应用通过CLI命令设置Wi-Fi扫描。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0

## ohos.permission.cli.MANAGE_WIFI_CONNECT

允许应用通过CLI命令设置Wi-Fi连接。

**权限级别**：system_core

**授权方式**：用户授权（user_grant）

**是否支持证书授权**：true

**支持设备**：Phone | PC/2in1 | Tablet | TV | Wearable | Car

**起始版本**：26.0.0
