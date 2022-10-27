# 通用误码

## 201 权限校验失败

**错误信息**

Permission verification failed, usually the result returned by VerifyAccessToken.

**错误描述**

权限校验失败，通常为VerifyAccessToken返回的结果导致。

**可能原因**

该错误码表示权限校验失败，通常为没有权限，却调用了需要权限的API。

**处理步骤**

请检查是否有调用API的权限。

## 202 系统API权限校验失败

**错误信息**

Permission verification failed, non-system application uses system API.

**错误描述**

权限校验失败，非系统应用使用了系统API。

**可能原因**

非系统应用，使用了系统API，请校验是否使用了系统API。

**处理步骤**

请检查是否调用了系统API，并且去掉。

## 401 参数检查失败

**错误信息**

The parameter check failed, including the required parameter is not passed in, or the parameter type is wrong.

**错误描述**

参数检查失败，包括必选参数没有传入，参数类型错误。

**可能原因**

必选参数没有传入，或者参数类型错误。

**处理步骤**

请检查必选参数是否没有传入，或者传的参数类型是否错误。

## 801 该设备不支持此API

**错误信息**

The device does not support this API, it is usually used to support a small number of APIs when the device supports the SysCap.

**错误描述**

该设备不支持此API，通常用于在设备已支持该SysCap时，针对其少量的API的支持处理。

**可能原因**

该设备不支持此API。

**处理步骤**

请检查设备是否支持使用的API。

## 901 该操作系统或运行环境不支持此API

**错误信息**

The operating system or operating environment does not support this API, and it is used for processing that the cross-platform API cannot be enabled on a certain platform.

**错误描述**

该操作系统或运行环境不支持此API，用于跨平台API在某个平台不能使用的处理。

**可能原因**

跨平台API在某个平台不能使用的处理。

**处理步骤**

请检查跨平台API在对应的平台是否可以使用。

