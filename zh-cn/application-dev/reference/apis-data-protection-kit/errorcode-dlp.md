# DLP服务错误码

> **说明：**
> 
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 19100001 入参错误

**错误信息**

Invalid parameter.

**错误描述**

非法参数。

**可能原因**

1. 账号长度为空或长度大于1024。

2. 账号类型错误。

3. aeskey或iv非法。

4. 授权到期时间低于系统时间。

5. Fd小于0。

6. tokenid等于0。

7. 包名为空。

8. appIndex小于0。

9. userId小于0。

**处理步骤**

请传入正确的参数。

## 19100002 加解密出错

**错误信息**

Begin encryption or decryption error.

**错误描述**

启动加解密出错。

**可能原因**

1. 当前运行的加解密任务数大于100。

2. 加解密任务重复。

**处理步骤**

请等待一段时间后重试。

## 19100003 加解密超时

**错误信息**

Encryption or decryption timeout.

**错误描述**

加解密超时。

**可能原因**

DLP文件加解密时间超过10秒。

**处理步骤**

请等待一段时间后重试。

## 19100004 凭据服务错误

**错误信息**

Credential service error.

**错误描述**

凭据服务错误。

**可能原因**

1. DLP凭据服务不存在。

2. DLP凭据服务异常。

**处理步骤**

请等待一段时间后重试，或者重启设备。

## 19100005 凭据认证服务器错误

**错误信息**

Credential authentication server error.

**错误描述**

凭据认证服务器错误。

**可能原因**

1. 凭据认证服务器无法连接。

2. 凭据认证服务器不存在。

**处理步骤**

请检查凭据认证服务器后重试。

## 19100006 非DLP沙箱应用

**错误信息**

No permission to call this API, which is available only for DLP sandbox applications.

**错误描述**

调用方不是DLP沙箱应用。

**可能原因**

调用方不是DLP沙箱应用。

**处理步骤**

请确认调用场景后重试。

## 19100007 DLP沙箱应用不允许调用此接口

**错误信息**

No permission to call this API, which is available only for non-DLP sandbox applications.

**错误描述**

调用方不可以是DLP沙箱应用。

**可能原因**

调用方不可以是DLP沙箱应用。

**处理步骤**

请确认调用场景后重试。

## 19100008 非DLP文件

**错误信息**

The file is not a DLP file.

**错误描述**

文件不是DLP文件。

**可能原因**

操作非DLP文件格式文件。

**处理步骤**

请使用经过DLP加密的DLP文件。

## 19100009 操作DLP文件失败

**错误信息**

Failed to operate the DLP file.

**错误描述**

操作DLP文件失败。

**可能原因**

1. 当前用户不在授权范围内。

2. 安装沙箱应用失败。

3. 关联link文件失败。

4. 打开DLP文件数大于1000。

**处理步骤**

step1：请确认访问权限。

step2：请等待一段时间或重启后重试。

## 19100010 只读DLP文件

**错误信息**

The DLP file is read only.

**错误描述**

DLP文件只读。

**可能原因**

1. 尝试去掉只读DLP文件的权限。

2. 尝试写只读DLP文件。

**处理步骤**

请确认文件权限。

## 19100011 系统服务工作异常

**错误信息**

The system ability works abnormally.

**错误描述**

系统服务工作异常。

**可能原因**

1. DLP权限服务无法正常启动。

2. DLP权限服务的RPC对象无法获取。

3. DLP权限服务依赖的其他服务无法正常启动。

4. IPC数据读取写入失败。

5. 服务未初始化。

**处理步骤**

系统服务内部工作异常，请稍后重试，或者重启设备尝试。

## 19100012 内存申请失败

**错误信息**

Out of memory.

**错误描述**

内存申请失败。

**可能原因**

系统内存不足。

**处理步骤**

系统内存不足，请稍后重试，或者重启设备。

## 19100013 用户无权限

**错误信息**

The user does not have the permission.

**错误描述**

用户无权限。

**处理步骤**

请检查权限。

## 19100014 账号未登录

**错误信息**

Account not logged in.

**错误描述**

账号未登录。

**处理步骤**

请登录账号。

## 19100015 系统需要升级

**错误信息**

Upgrade required.

**错误描述**

系统需要升级。

**处理步骤**

请升级系统。

## 19100016 want参数中没有uri

**错误信息**

uri missing in want.

**错误描述**

want参数中没有uri。

**处理步骤**

请传入正确的参数。

## 19100017 want参数中parameters内没有displayName

**错误信息**

displayName missing in want.

**错误描述**

want参数中parameters内没有displayName。

**处理步骤**

请传入正确的参数。

## 19100018 应用未授权

**错误信息**

Application not authorized.

**错误描述**

应用未授权。

**可能原因**

应用不在授信应用白名单中。

**处理步骤**

请设置授信应用白名单。

## 19100019 DLP文件已过期

**错误信息**

The DLP file has expired.

**错误描述**

DLP文件已过期。

**处理步骤**

请联系文件拥有者重新授权。

## 19100020 网络未连接

**错误信息**

No network connection.

**错误描述**

网络未连接。

**处理步骤**

请连接网络。