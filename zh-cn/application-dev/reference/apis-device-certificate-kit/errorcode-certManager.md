# 证书管理错误码

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 17500001 内部错误

**错误信息**

Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error.

**错误描述**

内部错误。可能原因：1. IPC通信失败；2. 内存操作错误；3. 文件操作错误。

**可能原因**

调用API时发生内部错误。

**处理步骤**

检查内部运行情况是否正常。

## 17500002 证书不存在

**错误信息**

The certificate does not exist.

**错误描述**

证书不存在。

**可能原因**

证书管理过程中发现证书不存在。

**处理步骤**

检查证书是否存在。

## 17500003 证书或凭据无效

**错误信息**

The keystore is in an invalid format or the keystore password is incorrect.

**错误描述**

密钥库格式无效或密钥库密码错误。

**可能原因**

输入不是有效的证书或凭据。

**处理步骤**

检查证书或凭据的有效性。

## 17500004 证书或凭据数量达到上限

**错误信息**

The number of certificates or credentials reaches the maximum allowed.

**错误描述**

证书或凭据的数量已达到允许的最大值。

**可能原因**

已安装的证书或凭据数量达到最大值。

**处理步骤**

清理过期的证书或凭据。

## 17500005 应用未经用户授权

**错误信息**

The application is not authorized by the user.

**错误描述**

应用未经过用户授权。

**可能原因**

用户没有将输入的凭据授权给当前应用使用。

**处理步骤**

检查输入的凭据是否正确或当前应用申请授权。

## 17500007 设备进入坚盾守护模式

**错误信息**

The device enters advanced security mode.

**错误描述**

设备进入坚盾守护模式。

**可能原因**

用户已开启坚盾守护模式。

**处理步骤**

需要在应用界面提醒用户关闭坚盾守护模式。

<!--Del-->
## 17500008 密码错误

**错误信息**

The input password is error.

**错误描述**

输入的密码错误。

**可能原因**

输入的密码错误。

**处理步骤**

检查密码是否正确，使用正确的密码再次尝试。
<!--DelEnd-->

## 17500009 不支持指定的证书存储路径

**错误信息**

The device does not support the specified certificate store path.

**错误描述**

设备不支持指定的证书存储路径。

**可能原因**

设备不支持指定的证书存储路径。

**处理步骤**

检查输入的证书类型是否正确。

## 17500010 访问USB证书凭据失败

**错误信息**

The USB key service access failed.

**错误描述**

USB Key服务访问失败。

**可能原因**

USB硬件驱动服务发生异常。

**处理步骤**

检查USB是否正常连接或USB驱动是否正常工作。

## 17500011 入参校验失败

**错误信息**

The input parameters validation failed.

**错误描述**

入参校验失败。

**可能原因**

参数格式异常或参数范围无效。

**处理步骤**

检查接口入参格式或范围。
