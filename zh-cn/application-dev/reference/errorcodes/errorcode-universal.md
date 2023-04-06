# 通用错误码

## 201 权限校验失败

**错误信息**

Permission verification failed, usually the result returned by VerifyAccessToken.

**错误描述**

权限校验失败，应用无权限使用该API，需要申请权限。

**可能原因**

该错误码表示权限校验失败，通常为没有权限，却调用了需要权限的API。

**处理步骤**

请检查是否有调用API的权限。

## 202 系统API权限校验失败

**错误信息**

Permission verification failed, application which is not a system application uses system API.

**错误描述**

权限校验失败，非系统应用使用了系统API。

**可能原因**

非系统应用，使用了系统API，请校验是否使用了系统API。

**处理步骤**

请检查是否调用了系统API，并且去掉。

## 401 参数检查失败

**错误信息**

BusinessError 401: Parameter error. The type of "${参数名}" must be ${正确的类型}[or ${其他正确的输入}].

**错误描述**

参数检查失败，包括必选参数没有传入，参数类型错误。

**可能原因**

必选参数没有传入，或者参数类型错误。

**处理步骤**

请检查必选参数是否没有传入，或者传的参数类型是否错误。

## 801 该设备不支持此API

**错误信息**

BusinessError 801: Capability not supported. function ${函数名} can not work correctly due to limited device capabilities.

**错误描述**

该设备不支持此API，通常用于在设备已支持该SysCap时，针对其少量的API的支持处理。

**可能原因**

该设备不支持此API。

**处理步骤**

请检查设备是否支持使用的API。
