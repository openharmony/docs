#  用户认证错误码

## 201 权限验证失败

**错误信息**

Permission verification failed.

**可能原因**

该应用没有调用相关接口的权限:
调用userAuth模块的getVersion、getAvailableStatus、start和cancel接口都需要ohos.permission.ACCESS_BIOMETRIC权限。

**处理步骤**

申请权限。在module.json5文件的requestPermissions对象中配置ohos.permission.ACCESS_BIOMETRIC权限。更多配置信息[应用包结构配置文件的说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/stage-structure.md)。

## 202 调用方不是一个系统应用

**错误信息**

The caller is not a system application.

**可能原因**

faceAuth模块的setSurfaceId当前只允许系统应用进行调用，非系统应用调用则会返回202错误码。

**处理步骤**

应用需要更改签名配置文件中的app-feature字段值为hos_system_app，使其成为系统应用才可以调用setSurfaceId接口。

## 401 参数不正确

**错误信息**

Incorrect parameters.

**可能原因**

该错误码表示调用接口时传入的参数不正确（包括参数个数和参数的取值）
例如调用userAuth模块的getAvailableStatus接口时，如果只传入1个参数，或者authTrustLevel的取值不在[ATL1, ATL2, ATL3, ATL4]范围，则会返回401错误码。

**处理步骤**

请检查传入的参数个数和参数取值等信息。

## 12500002 一般的操作错误

**错误信息**

General operation error.

**可能原因**

NAPI层解析参数出错。
用户认证服务的进程没有启动。
IPC通信的proxy客户端写数据出错。
IPC通信的stub服务端解析数据出错。
获取driver服务出错。

**处理步骤**

重启设备，重新调用接口。

## 12500005 认证类型不支持

**错误信息**

The authentication type is not supported.

**可能原因**

传入的认证类型参数不支持，例如调用userAuth模块的getAvailableStatus接口时传入的参数不是FACE或FINGERPRINT类型，则会返回12500005错误码。

**处理步骤**

请检查传入的认证类型参数，重新调用接口。

## 12500006 认证信任等级不支持

**错误信息**

The authentication trust level is not supported.

**可能原因**

调用userAuth模块的getAvailableStatus或getAuthInstance接口时，传入的authTrustLevel参数不在[ATL1, ATL2, ATL3, ATL4]范围内。
当前的设备的确不支持该认证信任等级。

**处理步骤**

检查传入的authTrustLevel是否在合理范围，如果在合理范围，则是当前的设备不支持该认证信任等级。

## 12500010 该类型的凭据没有录入

**错误信息**

The type of credential has not been enrolled.

**可能原因**

例如调用userAuth模块的getAvailableStatus接口，传入的authType参数为FACE，但是当前的设备没有录入人脸凭据，则会返回12500010错误码。
调用start接口发起人脸认证，但是目前的设备没有录入人脸凭据，则会返回12500010错误码。

**处理步骤**

检查是否录入该类型的凭据，如果没有录入，则需要成功录入该类型凭据后再调用相关接口。

## 12700001 人脸录入过程中的操作失败

**错误信息**

The operation is failed.

**可能原因**

例如调用faceAuth模块的setSurfaceId接口时，人脸认证服务未启动，则会返回12700001错误码。
IPC通信的proxy客户端写数据出错。
IPC通信的stub服务端解析数据出错。
人脸driver层调用出错。

**处理步骤**

一般主要检查人脸认证服务的进程是否启动。
