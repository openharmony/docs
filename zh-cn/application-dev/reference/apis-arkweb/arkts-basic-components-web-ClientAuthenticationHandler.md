# Class (ClientAuthenticationHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

ClientAuthenticationHandler是Web组件中处理SSL客户端证书认证请求的类。当服务器请求客户端证书进行TLS双向认证时，该处理器通过`onClientAuthenticationRequest`事件回调提供给应用，允许应用选择合适的证书凭据进行响应。示例代码参考[onClientAuthenticationRequest](./arkts-basic-components-web-events.md#onclientauthenticationrequest9)事件。

> **说明：**
>
> - 该组件从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
>
> - 示例效果请以真机运行为准。

## constructor<sup>9+</sup>

constructor()

ClientAuthenticationHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

通知Web组件使用指定的私钥和客户端证书链。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明               |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | 是    | 存放私钥文件的完整路径。 |
| certChainFile | string | 是    | 存放证书链文件的完整路径。 |

## confirm<sup>10+</sup>

confirm(authUri : string): void

通知Web组件使用指定的凭据（从证书管理模块获得）。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填   | 说明    |
| ------- | ------ | ---- | ------- |
| authUri | string | 是    | 凭据的关键值。 |

支持的证书签名算法以及密钥长度详见下表。
| 签名算法     | 密钥长度   | 
| ------- | ------ |
| SSL_SIGN_RSA_PKCS1_SHA256 | 1024（API version 18后开始支持）、2048、3072、4096 | 
| SSL_SIGN_RSA_PKCS1_SHA384 | 1024（API version 18后开始支持）、2048、3072、4096 | 
| SSL_SIGN_RSA_PKCS1_SHA512 | 1024（API version 18后开始支持）、2048、3072、4096 | 
| SSL_SIGN_RSA_PSS_SHA256 | 1024（API version 18后开始支持）、2048、3072、4096 | 
| SSL_SIGN_RSA_PSS_SHA384 | 1024（API version 18后开始支持）、2048、3072、4096 | 
| SSL_SIGN_RSA_PSS_SHA512 | 1024（API version 18后开始支持）、2048、3072、4096 | 
| SSL_SIGN_ECDSA_SECP256R1_SHA256 | 256 | 
| SSL_SIGN_ECDSA_SECP384R1_SHA384 | 384 | 
| SSL_SIGN_ECDSA_SECP521R1_SHA512 | 521 | 

## confirm<sup>22+</sup>

confirm(identity: string, credentialTypeOrCertChainFile: CredentialType \| string): void

通知Web组件使用从证书管理模块获取的指定凭据和凭据类型。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填   | 说明    |
| ------- | ------ | ---- | ------- |
| identity | string | 是    | 用于识别凭据的唯一标识值。 |
| credentialTypeOrCertChainFile | [CredentialType](./arkts-basic-components-web-e.md#credentialtype22) \| string | 是 | 类型为CredentialType时，代表凭据类型；类型为string时，表示证书链文件路径。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息                   |
| -------- | ------------------------- |
|  801     | Capability not supported. |

## cancel<sup>9+</sup>

cancel(): void

通知Web组件取消客户端证书请求事件。对来自相同host和port服务器的后续请求，不再重复上报该事件。

**系统能力：** SystemCapability.Web.Webview.Core

## ignore<sup>9+</sup>

ignore(): void

通知Web组件忽略本次请求。

**系统能力：** SystemCapability.Web.Webview.Core