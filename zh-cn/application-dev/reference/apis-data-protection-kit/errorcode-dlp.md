# DLP服务错误码
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--Designer: @QRF-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

> **说明：**
> 
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 19100001 入参错误

**错误信息**

Invalid parameter value.

**错误描述**

非法参数。

**可能原因**

1. 账号为空或账号长度大于1024字符。

2. 账号类型错误。

3. aesKey或iv非法。

4. 系统时间晚于授权到期时间。

5. fd（文件描述符，File Descriptor）小于0。

6. tokenId等于0。

7. 包名为空。

8. appIndex小于0。

9. userId小于0。

**处理步骤**

请检查并传入符合要求的参数，包括账号长度、类型、aesKey、iv格式、系统时间与授权时间关系、fd、tokenId、包名、appIndex、userId等。

## 19100002 加解密出错

**错误信息**

Credential service busy due to too many tasks or duplicate tasks.

**错误描述**

加解密服务繁忙。

**可能原因**

1. 当前运行的加解密任务数大于100。

2. 加解密任务重复。

**处理步骤**

请等待一段时间后重试，或控制并发任务数不超过100个以避免此类错误。

## 19100003 加解密超时

**错误信息**

Credential task time out.

**错误描述**

DLP（数据防泄露，Data Loss Prevention）文件加解密操作在规定时间内未完成，导致操作超时失败。

**可能原因**

DLP文件加解密时间超过10秒。

**处理步骤**

请等待一段时间后重试。

## 19100004 凭据服务错误

**错误信息**

Credential service error.

**错误描述**

DLP凭据服务发生内部错误，无法正常提供凭据相关服务。

**可能原因**

1. DLP凭据服务不存在。

2. DLP凭据服务异常。

**处理步骤**

请等待一段时间后重试，或者重启设备。

## 19100005 凭据认证服务器错误

**错误信息**

Credential authentication server error.

**错误描述**

与凭据认证服务器通信时发生错误，无法完成凭据认证流程。

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

请确认当前应用是否为DLP沙箱应用，当前接口仅允许DLP沙箱应用调用。

## 19100007 DLP沙箱应用不允许调用此接口

**错误信息**

No permission to call this API, which is available only for non-DLP sandbox applications.

**错误描述**

调用方不可以是DLP沙箱应用。

**可能原因**

调用方是DLP沙箱应用。

**处理步骤**

请确认当前应用不是DLP沙箱应用，该接口不允许DLP沙箱应用调用。

## 19100008 非DLP文件

**错误信息**

The file is not a DLP file.

**错误描述**

文件不是DLP文件。

**可能原因**

对非DLP格式的文件执行了DLP相关操作。

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

4. 同时打开的DLP文件数超过1000个。

**处理步骤**

1. 请确认访问权限。

2. 请等待一段时间或重启后重试，并注意控制同时打开的DLP文件数量不超过1000个。

<!--Del-->
## 19100010 只读DLP文件

**错误信息**

The DLP file is read only.

**错误描述**

DLP文件被设置为只读模式，不允许进行写入或修改权限等操作。

**可能原因**

1. 尝试去掉只读DLP文件的权限。

2. 尝试写只读DLP文件。

**处理步骤**

该DLP文件为只读文件，请勿尝试修改其权限或写入内容。
<!--DelEnd-->

## 19100011 系统服务工作异常

**错误信息**

The system ability works abnormally.

**错误描述**

DLP相关的系统服务无法正常运行，导致相关功能不可用。

**可能原因**

1. DLP权限服务无法正常启动。

2. DLP权限服务的RPC（远程过程调用，Remote Procedure Call）对象无法获取。

3. DLP权限服务依赖的其他服务无法正常启动。

4. IPC（进程间通信，Inter-Process Communication）数据读取写入失败。

5. 服务未初始化。

**处理步骤**

系统服务内部工作异常，请稍后重试，或者重启设备尝试。

## 19100012 内存申请失败

**错误信息**

System memory is insufficient.

**错误描述**

系统内存不足，无法为DLP操作申请所需的内存资源。

**可能原因**

系统内存不足。

**处理步骤**

系统内存不足，请稍后重试或重启设备。

## 19100013 用户无权限

**错误信息**

The user does not have the permission.

**错误描述**

当前登录的用户没有执行该操作或访问该DLP文件的权限。

**可能原因**

当前登录账号无此文件的权限。

**处理步骤**

请检查当前登录账号是否有该文件的访问权限。

## 19100014 账号未登录

**错误信息**

Account not logged in.

**错误描述**

执行该操作需要用户先登录账号，当前账号未登录或登录状态已失效。

**可能原因**

对应类型账号未登录。

**处理步骤**

请登录账号。

<!--Del-->
## 19100015 系统需要升级

**错误信息**

The system needs to be upgraded.

**错误描述**

当前系统版本不支持该DLP功能，需要升级系统到支持版本才能使用。

**可能原因**

当前系统版本需要升级。

**处理步骤**

请升级系统。
<!--DelEnd-->

## 19100016 want参数中没有uri

**错误信息**

The uri field is missing in the want parameter.

**错误描述**

调用接口时want参数中缺少必需的uri字段。

**可能原因**

调用DLP文件相关API时，want参数中未包含uri参数。want参数用于指定操作目标和参数配置，uri参数为必填参数。

**处理步骤**

请传入正确的参数。

## 19100017 want参数中parameters内没有displayName

**错误信息**

The displayName field is missing in the want parameter.

**错误描述**

调用接口时want参数的parameters对象中缺少必需的displayName字段。

**可能原因**

调用DLP文件相关API时，want参数的parameters字段中未包含displayName。displayName参数在DLP文件操作中为必填参数。

**处理步骤**

请传入正确的参数。

## 19100018 应用未授权

**错误信息**

The application is not authorized.

**错误描述**

当前应用未在DLP授权名单中，无权访问或操作DLP相关功能。

**可能原因**

应用不在授信应用名单中。

**处理步骤**

请申请加入授信应用名单。<!--RP1--><!--RP1End-->

<!--Del-->
## 19100019 DLP文件已过期

**错误信息**

The DLP file has expired.

**错误描述**

DLP文件已超过授权期限，无法继续访问或操作文件内容。

**可能原因**

当前时间超出授权期限。

**处理步骤**

请联系文件拥有者重新授权。
<!--DelEnd-->

<!--Del-->
## 19100020 网络未连接

**错误信息**

No network connection.

**错误描述**

执行该操作需要网络连接，当前设备网络未连接或未认证。

**可能原因**

网络未连接或未认证。

**处理步骤**

请连接网络。
<!--DelEnd-->

## 19100021 设置企业应用策略失败

**错误信息**

Failed to set the enterprise policy.

**错误描述**

设置企业应用策略失败。

**可能原因**

输入策略格式异常。

**处理步骤**

请检查策略格式，并进行重试。

## 19110001 参数错误

**错误信息**

Parameter error.

**错误描述**

参数错误。

**可能原因**

1. 策略格式错误。

2. 参数范围错误。

**处理步骤**

请检查以下参数：
1. 确保策略格式符合要求。
2. 确保参数在有效范围内。

## 19110002 文件敏感信息识别超时

**错误信息**

Sensitive file content identification timed out.

**错误描述**

对文件进行敏感信息识别时超时，无法在规定时间内完成识别流程。

**可能原因**

文件敏感信息识别处理时间超过系统设定的超时阈值。可能原因包括：文件过大、文件内容复杂度高、系统资源占用较高等。

**处理步骤**

请等待一段时间后重试。

## 19110003 文件不支持

**错误信息**

The file is not supported.

**错误描述**

传入的文件不被当前操作支持，可能是路径、类型或权限不符合要求。

**可能原因**

1. 文件路径不存在。

2. 文件类型不支持。

3. 文件权限不支持。

**处理步骤**

请检查以下内容：
1. 确保文件路径存在且可访问。
2. 确保文件类型受支持。
3. 确保文件权限满足要求。

## 19110004 系统功能运行异常

**错误信息**

A system error has occurred.

**错误描述**

系统内部功能模块运行异常，导致文件敏感信息识别相关操作无法正常执行。

**可能原因**

1. 服务无法正常启动。

2. 服务依赖的服务无法正常启动。

3. IPC数据读写失败。

4. 服务未初始化。

**处理步骤**

系统服务内部工作异常，请稍后重试或重启设备。

## 19100023 指定的用户ID与当前用户ID不一致

**错误信息**

The specified userId is inconsistent with the current userId.

**错误描述**

指定的用户ID与当前用户ID不一致。

**可能原因**

指定的用户ID与当前用户ID不一致。

**处理步骤**

请确保传入的用户ID与当前用户ID一致。当前用户ID可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。

## 19100024 个人空间用户不支持设置受控应用

**错误信息**

The specified userId belongs to a personal space user and cannot be managed.

**错误描述**

指定的用户ID属于个人空间用户，无法设置受控应用列表。

**可能原因**

指定的用户ID属于个人空间用户，无法设置受控应用列表。

**处理步骤**

请确保传入的用户ID不属于个人空间用户。
