# 证书错误码

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 19020001 内存错误

**错误信息**

Memory malloc failed.

**错误描述**

内存错误。

**可能原因**

当前系统内存分配失败。

**处理步骤**

1. 检查当前系统功能是否正常。
2. 业务检查数据是否超长，导致系统无法分配内存。

## 19020002 运行时错误

**错误信息**

Runtime error.

**错误描述**

运行时错误。

**可能原因**

系统出现的不可预期的错误。

**处理步骤**

检查当前系统功能是否正常。

## 19020003 参数检查失败

**错误信息**

Parameter check failed.

**错误描述**

参数检查失败。

**可能原因**

输入枚举值不在范围内。

**处理步骤**

检查输入参数的正确性。

## 19030001 调用三方算法库API出错

**错误信息**

Crypto operation error.

**错误描述**

调用三方算法库API出错。

**可能原因**

加解密算法框架与三方算法库交互时，出现错误。

**处理步骤**

1. 检查输入参数的正确性。
2. 检查三方算法库功能是否正常。

## 19030002 证书签名验证错误

**错误信息**

The certificate signature verification failed.

**错误描述**

证书签名验证错误。

**可能原因**

证书校验过程中，证书的签名信息不对。

**处理步骤**

检查证书的正确性。

## 19030003 证书尚未生效

**错误信息**

The certificate has not taken effect.

**错误描述**

证书尚未生效。

**可能原因**

证书尚未生效。证书的生效时间晚于当前系统时间或者业务指定的时间点。

**处理步骤**

1. 检查证书的正确性。
2. 检查获取的系统时间是否正确。
3. 与当前系统时间进行比对，检查证书的生效时间。

## 19030004 证书过期

**错误信息**

The certificate has expired.

**错误描述**

证书过期。

**可能原因**

证书失效。基于当前系统时间或者业务指定的时间点，证书已经失效。

**处理步骤**

1. 检查证书的正确性。
2. 检查获取的系统时间是否正确。
3. 与当前系统时间进行比对，检查证书的失效时间。

## 19030005 无法获取证书的颁发者

**错误信息**

Failed to obtain the certificate issuer.

**错误描述**

无法获取证书的颁发者。

**可能原因**

证书校验过程中，无法获取当前证书的颁发者。

**处理步骤**

检查证书的正确性。

## 19030006 证书的密钥用途不含证书签名

**错误信息**

The key cannot be used for signing a certificate.

**错误描述**

证书的密钥用途不含证书签名。

**可能原因**

证书的密钥用途不包括证书签名。

**处理步骤**

检查证书的正确性。

## 19030007 证书的密钥用途不含数字签名

**错误信息**

The key cannot be used for digital signature.

**错误描述**

证书的密钥用途不含数字签名。

**可能原因**

证书的密钥用途不包括数字签名。

**处理步骤**

检查证书的正确性。

## 19030008 私钥密码错误

**错误信息**

Maybe wrong password.

**错误描述**

私钥密码错误。

**可能原因**

私钥密码错误。

**处理步骤**

检查私钥的密码是否正确。

## 19030009 证书不受信任

**错误信息**

Untrusted certificate.

**错误描述**

证书不受信任。

**可能原因**

证书链验证过程中，证书不在信任锚范围内。

**处理步骤**

若信任待验证证书的根证书，则将其添加到信任证书列表参数中，再次尝试校验。若不信任待验证证书的根证书，请不要信任该证书。

## 19030010 证书已被吊销

**错误信息**

The certificate has been revoked.

**错误描述**

证书已被吊销。

**可能原因**

证书在CRL吊销列表中或OCSP响应显示证书已被吊销。

**处理步骤**

证书已被吊销，请不要信任该证书。请更换有效证书。

## 19030011 未知的关键扩展

**错误信息**

Unsupported critical extension.

**错误描述**

证书包含未知的关键扩展。

**可能原因**

证书中存在未被识别的关键扩展，根据X.509标准必须处理所有关键扩展。

**处理步骤**

可以通过设置[ignoreErrs](js-apis-cert.md#certvalidationparams)参数忽略该错误，然后通过证书算法库相关接口获取该扩展数据自行进行校验。

## 19030012 主机名不匹配

**错误信息**

Hostname mismatch in the certificate.

**错误描述**

证书主机名不匹配。

**可能原因**

证书的主题备用名（SAN）或通用名（CN）不包含指定的主机名。

**处理步骤**

检查[hostnames](js-apis-cert.md#certvalidationparams)参数是否正确。若正确，请不要信任该证书。

## 19030013 邮箱地址不匹配

**错误信息**

Email address mismatch in the certificate.

**错误描述**

证书邮箱地址不匹配。

**可能原因**

证书不包含指定的邮箱地址。

**处理步骤**

检查[emailAddresses](js-apis-cert.md#certvalidationparams)参数是否正确。若正确，请不要信任该证书。

## 19030014 密钥用途不匹配

**错误信息**

Key usage mismatch in the certificate.

**错误描述**

证书密钥用途不匹配。

**可能原因**

证书的密钥用途扩展不包含指定的密钥用途。

**处理步骤**

检查[keyUsage](js-apis-cert.md#certvalidationparams)参数是否正确。若正确，请不要信任该证书。

## 19030015 无法获取证书吊销列表

**错误信息**

Failed to obtain the certificate revocation list.

**错误描述**

无法获取证书吊销列表。

**可能原因**

1. 未提供CRL数据。
2. 证书不包含CRL分发点（CDP）扩展。
3. 无法从CDP扩展下载CRL。

**处理步骤**

1. 检查是否提供了CRL数据。
2. 若开启了在线下载CRL，检查证书是否包含CDP扩展。
3. 若开启了在线下载CRL，检查网络连接是否正常，且保证可以正常访问网络。
4. 若允许在校验证书吊销状态时忽略未找到证书吊销列表的错误，可以通过设置[ignoreErrs](js-apis-cert.md#certvalidationparams)参数忽略该错误。

## 19030016 证书吊销列表尚未生效

**错误信息**

The certificate revocation list has not taken effect.

**错误描述**

证书吊销列表尚未生效。

**可能原因**

CRL的生效时间晚于当前验证时间。

**处理步骤**

1. 若允许CRL的生效时间晚于当前验证时间，可以通过设置[ignoreErrs](js-apis-cert.md#certvalidationparams)参数忽略该错误。
2. 若未配置[date](js-apis-cert.md#certvalidationparams)参数，请检查设备时间是否正确。
3. 若配置了[date](js-apis-cert.md#certvalidationparams)参数，请检查该参数是否合理。

## 19030017 证书吊销列表已过期

**错误信息**

The certificate revocation list has expired.

**错误描述**

证书吊销列表已过期。

**可能原因**

CRL的失效时间早于当前验证时间。

**处理步骤**

1. 若允许CRL的失效时间早于当前验证时间，可以通过设置[ignoreErrs](js-apis-cert.md#certvalidationparams)参数忽略该错误。
2. 若未配置[date](js-apis-cert.md#certvalidationparams)参数，请检查设备时间是否正确。
3. 若配置了[date](js-apis-cert.md#certvalidationparams)参数，请检查该参数是否合理。

## 19030018 证书吊销列表签名验证失败

**错误信息**

Failed to verify the signature of the certificate revocation list.

**错误描述**

证书吊销列表签名验证失败。

**可能原因**

CRL的签名验证失败，可能是签名错误或颁发者证书不匹配。

**处理步骤**

检查CRL数据的正确性和颁发者证书。

## 19030019 无法获取证书吊销列表颁发者

**错误信息**

Failed to find the issuer of the certificate revocation list.

**错误描述**

无法获取证书吊销列表颁发者。

**可能原因**

无法找到签发CRL的证书。

**处理步骤**

一般在部分证书链校验场景可能出现该错误，建议在该场景仅校验终端实体证书的吊销状态。若要校验所有证书的吊销状态，建议不要设置部分证书链校验。

## 19030020 无法获取在线证书状态协议（OCSP）响应

**错误信息**

Failed to obtain the OCSP response.

**错误描述**

无法获取在线证书状态协议（OCSP）响应。

**可能原因**

1. 未提供OCSP响应数据。
2. 证书不包含AIA扩展中的OCSP URL。
3. 无法从OCSP服务器获取响应。

**处理步骤**

1. 检查是否提供了OCSP响应数据。
2. 若开启了在线OCSP检查，检查证书是否包含OCSP URL。
3. 若开启了在线OCSP检查，检查网络连接是否正常，且保证可以正常访问网络。
4. 若允许在校验证书吊销状态时忽略未找到OCSP响应的错误，可以通过设置[ignoreErrs](js-apis-cert.md#certvalidationparams)参数忽略该错误。

## 19030021 无效的OCSP响应

**错误信息**

Invalid OCSP response.

**错误描述**

OCSP响应无效。

**可能原因**

OCSP响应数据格式错误、无法解析或已过期。

**处理步骤**

1. 检查OCSP响应数据的正确性。

## 19030022 OCSP签名验证失败

**错误信息**

Failed to verify the OCSP signature. 

**错误描述**

OCSP签名验证失败。

**可能原因**

OCSP响应的签名验证失败，可能是签名错误或签名者证书不匹配。

**处理步骤**

将OCSP响应的签名者证书以及颁发者证书添加到不信任证书或信任证书列表中，并将其根添加到信任证书列表中。

## 19030023 OCSP证书状态未知

**错误信息**

Unknown OCSP certificate status.

**错误描述**

OCSP证书状态未知。

**可能原因**

OCSP服务器无法确定证书的状态。

**处理步骤**

检查OCSP服务器是否正常工作，或使用其他方式验证证书吊销状态。

## 19030024 网络连接超时

**错误信息**

Network connection timed out.

**错误描述**

网络连接超时。

**可能原因**

1. 下载中间CA证书超时。
2. 下载CRL超时。
3. OCSP请求超时。

**处理步骤**

检查网络连接状态，确保能够访问相关服务器。