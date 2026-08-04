# 工具访问控制错误码

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @gcw_3MIoLA9y-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

工具访问控制模块提供了对系统工具的访问权限管理能力，支持权限的查询、授权和签发执行凭据等操作，适用于需要对应用访问系统工具进行权限管控的场景。

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 24010000 入参错误

**错误信息**

Invalid Parameter. Error message: messageInfo.

**错误描述**

当入参错误时，将返回该错误码。

**可能原因**

1. 权限名长度超过256个字符。
2. permissionStatus取值非法。
3. 权限查询信息permissionQuery为无效值。
4. 用户授权结果userAuthResult为无效值。
5. 远程授权包ticketInfo为无效值。
6. 远程设备信息remoteInfo为无效值。
7. 远程授权状态值remoteGrantStatus取值非法。

**处理步骤**

检查入参，修正参数值为有效值，有效值请参考各接口参数说明[@ohos.abilityToolAccessCtrl](js-apis-abilityToolAccessCtrl-sys.md)。

## 24010001 系统服务工作异常

**错误信息**

The service is abnormal.

**错误描述**

当系统服务异常时，将返回该错误码。

**可能原因**

1. IPC通信失败。
2. 工具管理服务无法正常启动。

**处理步骤**

1. 稍后重试。该异常可能由临时性IPC通信失败导致，重试即可恢复。
2. 若问题持续，检查系统日志确认工具管理服务已正常启动。
3. 如服务启动失败，重启设备后重试。

## 24010002 服务内部错误

**错误信息**

Common internal error.

**错误描述**

当工具访问控制服务内部发生错误（如依赖的系统服务不可用、资源访问失败）时，接口将返回该错误码，表示服务端处理失败，接口调用未成功执行。

**可能原因**

1. 依赖的系统服务不可用。
2. 资源访问失败。

**处理步骤**

1. 检查依赖的系统服务是否正常运行。
2. 检查资源访问权限和路径是否正确。
3. 重启设备后重试。

## 24010003 环境错误

**错误信息**

Environment error. The account is not logged in, network is unavailable, timeout, etc.

**错误描述**

当运行环境不满足条件时，将返回该错误码。

**可能原因**

1. 当前账号未登录。
2. 网络不可用。
3. 操作超时。

**处理步骤**

1. 确认当前账号已登录。
2. 确认设备网络连接正常。
3. 稍后重试，确认是否因超时导致。

## 24010004 权限不存在

**错误信息**

Invalid permission. A permission in permissionInfo does not exist.

**错误描述**

当指定的权限不存在时，将返回该错误码。

**可能原因**

1. permissionInfo中的权限名在系统中不存在。
2. 权限名未在应用的module.json5文件中声明。

**处理步骤**

检查入参，修正权限名为有效值，有效值参考[权限列表](../../security/AccessToken/app-permissions.md)。

## 24010005 授权失败

**错误信息**

Grant permission failed. The application specified by the tokenID is not allowed to be granted with the specified permission, or the specified permission cannot be granted by user, etc.

**错误描述**

当授权操作失败时，将返回该错误码。

**可能原因**

1. 指定的tokenID对应的应用不支持被授予指定的权限。
2. 指定的权限无法通过用户授权方式授予。

**处理步骤**

1. 确认tokenID对应的应用是否允许被授予该权限。
2. 确认指定权限是否为可通过用户授权方式授予的权限类型。

## 24010006 设备处于锁屏状态时不允许执行操作

**错误信息**

The requested operation is not allowed to be executed while the device is locked.

**错误描述**

当设备处于锁屏状态时，请求锁屏下不可执行的操作，将返回该错误码。

**可能原因**

设备处于锁屏状态时，请求了锁屏下不可执行的操作。

**处理步骤**

确认设备处于解锁状态后再发起操作请求。