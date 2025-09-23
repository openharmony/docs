# Class (ClientAuthenticationHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

Web组件返回的SSL客户端证书请求事件用户处理功能对象。示例代码参考[onClientAuthenticationRequest事件](./arkts-basic-components-web-events.md#onclientauthenticationrequest9)。

> **说明：**
>
> - 该组件从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## constructor<sup>9+</sup>

constructor()

ClientAuthenticationHandler的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## confirm<sup>(deprecated)</sup>

confirm(priKeyFile : string, certChainFile : string): void

通知Web组件使用指定的私钥和客户端证书链。

> **说明：**
>
> 从API version 9开始支持，从API version 22开始废弃。建议使用[confirm](./arkts-basic-components-web-ClientAuthenticationHandler.md#confirm10)<sup>10+</sup>替代。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名           | 类型   | 必填   | 说明               |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | 是    | 存放私钥文件的完整路径。  |
| certChainFile | string | 是    | 存放证书链文件的完整路径。 |

## confirm<sup>10+</sup>

confirm(authUri : string): void

通知Web组件使用指定的凭据(从证书管理模块获得)。

> **说明：**
>
> 需要配置权限：ohos.permission.ACCESS_CERT_MANAGER。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名     | 类型   | 必填   | 说明    |
| ------- | ------ | ---- | ------- |
| authUri | string | 是    | 凭据的关键值。 |

支持的证书签名算法以及秘钥长度详见下表。
| 签名算法     | 秘钥长度   | 
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

## cancel<sup>9+</sup>

cancel(): void

通知Web组件取消相同host和port服务器发送的客户端证书请求事件。同时，相同host和port服务器的请求，不重复上报该事件。

**系统能力：** SystemCapability.Web.Webview.Core

## ignore<sup>9+</sup>

ignore(): void

通知Web组件忽略本次请求。

**系统能力：** SystemCapability.Web.Webview.Core