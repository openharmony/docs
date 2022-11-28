#  用户认证错误码

## 201 权限验证失败

具体参见[通用错误码](./errorcode-universal.md)

## 202 调用方不是一个系统应用

具体参见[通用错误码](./errorcode-universal.md)

## 401 参数不正确

具体参见[通用错误码](./errorcode-universal.md)

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

重启设备，重新调用接口。

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

1. 例如调用faceAuth模块的setSurfaceId接口时，人脸认证服务未启动，则会返回12700001错误码。
2. IPC通信的proxy客户端写数据出错。
3. IPC通信的stub服务端解析数据出错。
4. 人脸driver层调用出错。

**处理步骤**

主要检查人脸认证服务的进程是否启动。
