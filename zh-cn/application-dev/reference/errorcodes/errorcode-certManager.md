# 证书管理错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

## 17500001 内部错误

**错误信息**

There is an generic error occurred when calling the API.

**可能原因**

调用API时发生内部错误。

**处理步骤**

检查内部运行情况是否正常。

## 17500002 证书不存在

**错误信息**

The certificate do not exist

**可能原因**

证书管理过程中发现证书不存在。

**处理步骤**

检查证书是否存在。

## 17500003 证书或凭据无效

**错误信息**

The keystore is not valid format or keystorePwd is not correct.

**可能原因**

输入不是有效的证书或凭据。

**处理步骤**

检查证书或凭据的有效性。
