# 不可通过ACL申请的系统应用可用权限（系统授权）

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

在申请目标权限前，建议开发者先了解[不同权限的申请路径](determine-application-mode.md)，对权限的工作流程有基本了解后，再结合以下权限字段的具体说明，判断应用能否申请目标权限，提高开发效率。

> **说明：**
>
> - 以下权限仅对APL等级为system_basic及以上的应用开放，不向APL等级为normal的应用开放。
> - 以下权限的授权方式均为system_grant（系统授权）。
> - 以下权限不可用通过访问控制列表（ACL）的方式跨级别申请。

申请流程可参考[选择申请权限的方式](determine-application-mode.md)。

## ohos.permission.RECEIVER_STARTUP_COMPLETED

允许应用订阅开机广播。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：9

## ohos.permission.SYSTEM_LIGHT_CONTROL

允许控制系统灯，包括打开、关闭等操作。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：11

## ohos.permission.GET_ALL_APP_ACCOUNTS

允许应用查询所有的应用账号信息。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：7

## ohos.permission.MANAGE_DEVICE_AUTH_CRED

允许应用调用设备认证账号凭据管理应用接口。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：10

## ohos.permission.ACCESS_AUTH_RESPOOL

允许SA注册认证执行器。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：9

## ohos.permission.READ_ACCESSIBILITY_CONFIG

允许应用读取无障碍配置信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：9

## ohos.permission.WRITE_APP_PUSH_DATA

允许推送服务往应用中写入数据。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：10

## ohos.permission.READ_APP_PUSH_DATA

允许推送服务读取应用中推送服务存储的数据。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：10

## ohos.permission.NETSYS_INTERNAL

允许SA服务调用网络管理netsys中的网络诊断、wifi、网卡监听、iptables设置等功能接口。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：10

## ohos.permission.DISTRIBUTED_SOFTBUS_CENTER

允许不同设备之间进行组网处理。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：9

## ohos.permission.RESTRICT_APPLICATION_ACTIVE

允许待机续航部件发布一个自定义的限网事件。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：10

## ohos.permission.CONNECT_CELLULAR_CALL_SERVICE

允许系统服务访问蜂窝通话SA。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：10

## ohos.permission.CONNECT_IMS_SERVICE

允许系统服务访问IMS SA。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：10

## ohos.permission.ENFORCE_USER_IDM

允许SA无token删除IAM用户信息。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：9

## ohos.permission.WRITE_ACCESSIBILITY_CONFIG

允许应用设置无障碍配置信息。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：9

## ohos.permission.ENABLE_DISTRIBUTED_HARDWARE

允许系统服务使能分布式硬件资源。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：11

## ohos.permission.ACCESS_SUPER_HUB

允许应用拉起"中转站"。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：12

## ohos.permission.CALLED_UIEXTENSION_ON_LOCK_SCREEN

允许UIExtensionAbility显示在锁屏之上。

**权限级别**：system_core

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：14

## ohos.permission.USE_USER_ACCESS_MANAGER

允许应用查询和配置用户身份认证策略、校验用户身份认证结果。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：18

## ohos.permission.SET_LAUNCH_REASON_MESSAGE

允许系统应用拉起其他应用时设置拉起原因。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：18

## ohos.permission.ACCESS_USER_ACCOUNT_INFO

允许系统应用获取账号提供的数据。

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：false

**起始版本**：18
