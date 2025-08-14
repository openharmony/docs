# 用户认证错误码

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--SE: @lichangting518-->
<!--TSE: @jane_lz-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 12500001 认证失败

**错误信息**

Authentication failed.

**可能原因**

当前凭据与设备里已经录入的凭据比对失败。

**处理步骤**

重新发起认证。

## 12500002 一般的操作错误

**错误信息**

General operation error.

**可能原因**

1. NAPI层解析参数出错。
2. 用户认证服务的进程没有启动。
3. IPC通信的proxy客户端写数据出错。
4. IPC通信的stub服务端解析数据出错。
5. 获取driver服务出错。

**处理步骤**

系统服务内部工作异常，请稍后重新调用接口，或者重启设备尝试。

## 12500003 认证被取消

**错误信息**

Authentication canceled.

**可能原因**

当前的认证操作已经被取消。

**处理步骤**

重新调用认证接口，发起认证。

## 12500004 认证操作超时

**错误信息**

Authentication timeout.

**可能原因**

当前的认证操作超过了设定的时限。

**处理步骤**

重新调用认证接口，发起认证。

## 12500005 认证类型不支持

**错误信息**

The authentication type is not supported.

**可能原因**

1. 传入的认证类型参数不支持，例如调用userAuth模块的getAvailableStatus接口时传入的参数不是FACE或FINGERPRINT类型，则会返回12500005错误码。
2. 传入的认证类型参数在本设备上不支持，例如在没有部署指纹传感器的设备上发起指纹认证，则会返回12500005错误码。

**处理步骤**

请检查传入的认证类型参数，重新调用接口。

## 12500006 认证信任等级不支持

**错误信息**

The authentication trust level is not supported.

**可能原因**

1. 调用userAuth模块的getAvailableStatus或getAuthInstance接口时，传入的authTrustLevel参数不在[ATL1, ATL2, ATL3, ATL4]范围内。
2. 当前的设备不支持该认证信任等级，例如在只部署了2D摄像头的设备上发起支付级别的人脸认证，则会返回12500006错误码。

**处理步骤**

检查传入的authTrustLevel是否在合理范围，如果在合理范围，则是当前的设备不支持该认证信任等级。

## 12500007 认证服务已经繁忙

**错误信息**

Authentication service is busy.

**可能原因**

当前已经存在某个尚未结束的认证，又发起了一次认证。

**处理步骤**

稍后重新发起认证。

## 12500008 参数校验失败

**错误信息**

The parameter is out of range.

**错误描述**

参数校验不通过。

**可能原因**

参数错误。

**处理步骤**

检查接口参数重新发起请求。

## 12500009 认证被锁定

**错误信息**

Authentication is locked out.

**可能原因**

当前认证失败的次数超过了上限，触发防爆模式，认证被锁定。

**处理步骤**

稍后重新发起一次成功的认证。

## 12500010 该类型的凭据没有录入

**错误信息**

The type of credential has not been enrolled.

**可能原因**

例如调用userAuth模块的getAvailableStatus接口，传入的authType参数为FACE，但是当前的设备没有录入人脸凭据，则会返回12500010错误码。调用start接口发起人脸认证，但是目前的设备没有录入人脸凭据，则会返回12500010错误码。

**处理步骤**

检查是否录入该类型的凭据，如果没有录入，则需要成功录入该类型凭据后再调用相关接口。

## 12500011 提示/通知切换自定义认证

**错误信息**

Switched to the custom authentication process.

**可能原因**

当前的认证操作被用户从控件取消，返回这个错误码，标识使用应用自定义认证。例如用户点击使用自定义认证，返回到应用自定义认证流程。

**处理步骤**

重新调用认证接口，发起认证。

## 12500013 密码过期

**错误信息**

Operation failed because of PIN expired.

**可能原因**

由于系统锁屏口令过期，认证操作执行失败。当用户发起口令、指纹或者人脸认证，但是系统锁屏口令过期时，将会返回12500013错误码。

**处理步骤**

用户前往设置更新系统锁屏口令，再次发起认证。

<!--Del-->
## 12500015 AuthToken完整性校验失败

**错误信息**

Operation failed because of authToken integrity check failed.

**可能原因**

当验证的AuthToken无效时，会返回12500015错误码。

**处理步骤**

重新发起认证，签发有效token。

## 12500016 AuthToken过期

**错误信息**

Operation failed because of authToken has expired.

**可能原因**

当AuthToken的签发时间至发起验证时的时间间隔超过传入的最大有效时长时，会返回12500016错误码。

**处理步骤**

重新发起认证，签发有效token。

## 12500017 复用身份认证结果失败

**错误信息**

Failed to reuse authtication result.

**错误描述**

复用身份认证结果失败。

**可能原因**

1. 认证类型与指定的类型不匹配。
2. 认证结果超过了可复用时长（可复用时长最长为5分钟）。

**处理步骤**

发起认证请求，用户手动认证通过后获取有效的authToken。

## 12700001 人脸服务不可用

**错误信息**

The service is unavailable.

**可能原因**

1. 例如调用faceAuth模块的setSurfaceId接口时，人脸认证服务未启动，则会返回12700001错误码。
2. IPC通信的proxy客户端写数据出错。
3. IPC通信的stub服务端解析数据出错。
4. 人脸driver层调用出错。

**处理步骤**

系统服务内部工作异常，请稍后重新调用接口，或者重启设备尝试。
<!--DelEnd-->
