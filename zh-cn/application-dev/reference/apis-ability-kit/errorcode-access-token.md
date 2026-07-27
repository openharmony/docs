# 访问控制错误码

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 12100001 入参错误

**错误信息**

Invalid Parameter. Error message: messageInfo.

**错误描述**

当入参错误时，将返回该错误码。

**可能原因**

1. tokenId值为0。
2. 指定的权限名为空或者权限名长度大于256。
3. 请求授权/撤销权限的flag取值非法。
4. 注册监听的参数检查错误。
5. 指定的Context不属于当前应用。
6. 请求的权限不属于同一个权限组。
7. 请求的权限中存在应用未声明的权限。
8. 请求的全局开关类型非法。
9. 指定的权限名不是[user_grant权限](../../security/AccessToken/permissions-for-all-user.md)。
10. 指定的数组成员个数超过1024或成员均为无效值。
11. 请求查看权限使用记录的起始结束时间不合法。
12. 指定的权限名未在应用中声明。

**处理步骤**

检查入参，修正参数值为有效值，有效值请参考[@ohos.abilityAccessCtrl (程序访问控制管理)](js-apis-abilityAccessCtrl.md)中对应接口的参数说明。

<!--Del-->
## 12100002 tokenId不存在

**错误信息**

TokenId does not exist.

**错误描述**

当指定的tokenId不存在或对应的进程非应用进程时，将返回该错误码。

**可能原因**

1. 指定的tokenId不存在。
2. 指定的tokenId对应的进程非应用进程。

**处理步骤**

检查入参，确认tokenId值是否为目标应用的身份标识。

<!--Del-->
## 12100003 权限名不存在

**错误信息**

Permission does not exist.

**错误描述**

当指定的权限不存在或未被申请时，将返回该错误码。

**可能原因**

1. 系统中不存在指定的权限，包括权限未定义、权限类型不匹配。
2. 请求授权/撤销权限场景下，指定的应用tokenId未申请过指定的权限名。
3. 权限使用记录场景下，指定的权限名非用户授权的敏感权限。

**处理步骤**

检查入参，修正参数值为有效值，有效值请参考[权限列表](../../security/AccessToken/app-permissions.md)。
<!--DelEnd-->

## 12100004 接口未配套使用

**错误信息**

The API is not used in pair with others.

**错误描述**

当接口未按配套关系调用，或在未解除配套关系前重复调用时，将返回该错误码。

**可能原因**

1. 当前接口在未解除配套关系前，使用相同入参重复调用。
2. 当前接口在未配套使用的情况下，单独调用。

**处理步骤**

检查当前接口是否有配套使用：

- 注册监听接口和注销监听接口需配套使用：调用注册监听接口后，在未调用对应注销监听接口前，不可再次使用相同的入参调用注册监听接口；注销监听接口需要在对应注册监听接口调用之后方可调用。
<!--Del-->
- 启动记录的接口和停止记录的接口需配套使用：调用启动记录的接口后，在未调用对应停止记录的接口前，不可再次使用相同的入参调用启动记录接口；停止记录的接口需要在对应启动记录的接口调用之后方可调用。
<!--DelEnd-->

相关方法：
<!--Del-->
- 开始使用权限：[privacyManager.startUsingPermission](js-apis-privacyManager-sys.md#privacymanagerstartusingpermission)
- 停止使用权限：[privacyManager.stopUsingPermission](js-apis-privacyManager-sys.md#privacymanagerstopusingpermission)
- 订阅权限使用状态变更事件：[privacyManager.on](js-apis-privacyManager-sys.md#privacymanageron)
- 取消订阅权限使用状态变更事件：[privacyManager.off](js-apis-privacyManager-sys.md#privacymanageroff)
<!--DelEnd-->
- 订阅自身权限状态变更事件：[on](js-apis-abilityAccessCtrl.md#on18)
- 取消订阅自身权限状态变更事件：[off](js-apis-abilityAccessCtrl.md#off18)


## 12100005 监听器数量超过限制

**错误信息**

The number of listeners exceeds the limit.

**错误描述**

当监听器数量超过限制时，将返回该错误码。

**可能原因**

注册的监听器数量超过系统限制的200个上限。

**处理步骤**

及时释放已注册的无用的监听器。

<!--Del-->
## 12100006 指定的应用不支持被授予或被取消授予指定的权限

**错误信息**

The specified application does not support the permissions granted or ungranted as specified.

**错误描述**

当指定的应用不支持被授予或被取消授予指定的权限时，将返回该错误码。

**可能原因**

1. 输入的tokenId是远端设备的身份标识，尚未支持分布式授权和取消授权。
2. 入参指定的tokenId为沙箱应用，被禁止申请指定的权限。

**处理步骤**

1. 请确认tokenId的获取方式是否正确。
2. 确认待授权的沙箱应用是否为特殊的受限沙箱应用进程，部分模式下的沙箱应用被禁止授予大部分权限。
<!--DelEnd-->

## 12100007 系统服务工作异常

**错误信息**

Service exception.

**错误描述**

当系统服务工作异常时，将返回该错误码。

**可能原因**

1. 权限管理服务无法正常启动。
2. IPC（Inter-Process Communication，进程间通信）数据读取写入失败。

**处理步骤**

系统服务内部工作异常，请稍后重试，或者重启设备。

<!--Del-->
## 12100008 内存申请失败

**错误信息**

Out of memory.

**错误描述**

当内存申请失败时，将返回该错误码。

**可能原因**

系统内存不足，无法完成内存申请操作。

**处理步骤**

系统内存不足，请稍后重试，或者重启设备。
<!--DelEnd-->

## 12100009 服务内部错误

**错误信息**

Common inner error.

**错误描述**

当服务内部发生错误或权限弹窗发生错误时，将返回该错误码。

**可能原因**

1. 内部错误
   - 系统服务内部异常或数据库错误。
2. 权限弹窗错误
   - 应用处于后台，无法正常拉起弹窗。
   - 设备处于锁屏状态，无法正常弹出弹窗。
   - 拉起弹窗后未及时处理，弹窗进程因应用退出而被系统回收，例如用户在多任务界面清理应用进程。

**处理步骤**

1. 内部错误
   - 建议重启设备后重试。
2. 权限弹窗错误
   - 确认应用处于前台状态后再发起弹窗请求。
   - 确认设备处于解锁状态后再发起弹窗请求。
   - 确认弹窗已被及时处理，若弹窗进程因应用退出而被系统回收则无需额外操作。
3. 若问题仍无法解决，请开发者通过在线提交工单反馈问题说明及日志信息，技术支持人员会及时处理。

## 12100010 存在未被处理的请求

**错误信息**

The request already exists.

**错误描述**

当存在未被处理的请求时，将返回该错误码。

**可能原因**

上一次请求未被处理。

**处理步骤**

请等待上一次权限请求完成，并根据上一次请求的返回结果完成授权处理后再重新发起请求。


## 12100011 输入的所有权限均已被授权

**错误信息**

All permissions in the permission list have been granted.

**错误描述**

当输入的所有权限均已被授权时，将返回该错误码。

**可能原因**

所有权限均已被授权。

**处理步骤**

无需处理，返回此错误码表示申请权限已被授权，不会弹出权限设置弹窗。

## 12100012 输入的权限中存在未被用户拒绝过的权限

**错误信息**

The permission list contains the permission that has not been revoked by the user.

**错误描述**

当输入的权限中存在未被用户拒绝过的权限时，将返回该错误码。

**可能原因**

存在未被用户拒绝过的权限。

**处理步骤**

请先调用requestPermissionsFromUser向用户申请权限。

## 12100013 全局开关已开启

**错误信息**

The specific global switch is already open.

**错误描述**

当全局开关已开启时，将返回该错误码。

**可能原因**

全局开关已开启。

**处理步骤**

无需处理，返回此错误码表示全局开关已开启，不会弹出全局开关设置弹窗。

## 12100014 非预期的权限

**错误信息**

Unexpected permission.

**错误描述**

当输入的权限不符合使用场景时，将返回该错误码。

**可能原因**

1. 调用[requestPermissionOnSetting](js-apis-abilityAccessCtrl.md#requestpermissiononsetting12)再次弹出权限设置弹窗时，传入了manual_settings授权方式的权限。
2. 授权或取消授权时，传入了非user_grant和manual_settings授权方式的权限。
3. 调用[openPermissionOnSetting](js-apis-abilityAccessCtrl.md#openpermissiononsetting22)拉起跳转设置页弹窗时，传入了非manual_settings授权方式的权限。

**处理步骤**

请确认输入的权限是否符合使用场景。

<!--Del-->
## 12100015 查询的数据超过上限

**错误信息**

The queried data exceeds the upper limit.

**错误描述**

当查询的数据超过上限时，将返回该错误码。

**可能原因**

1. 批量查询的权限列表超过系统设定的单次查询上限。
2. 批量查询的应用tokenID列表超过系统设定的单次查询上限。

**处理步骤**

请减少单次查询的权限或应用数量，分批进行查询。具体上限请参考[queryStatusByPermission](js-apis-abilityAccessCtrl-sys.md#querystatusbypermission)和[queryStatusByTokenID](js-apis-abilityAccessCtrl-sys.md#querystatusbytokenid)接口的参数说明。
<!--DelEnd-->
