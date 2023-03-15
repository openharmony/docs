# Hap包签名工具概述

为了保证OpenHarmony应用的完整性和来源可靠，在应用构建时需要对应用进行签名。经过签名的应用才能在真机设备上安装、运行、和调试。[developtools_hapsigner仓](https://gitee.com/openharmony/developtools_hapsigner)提供了签名工具的源码，包含密钥对生成、CSR文件生成、证书生成、Profile文件签名、Hap包签名等功能。

> **说明：** 针对无需通过ACL跨级别申请权限的应用，DevEco Studio为开发者提供了自动化签名方案，可以一键完成应用/服务签名。具体可参考[自动化签名方案](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465)。

## 基本概念

Hap包签名工具支持本地签名需求的开发，为OpenHarmony应用提供完整性保护和来源管控机制，该签名工具基于PKI公钥证书的机制实现，在进行开发前，开发者应了解以下基本概念：

 - 非对称密钥对：

   非对称密钥算法是数据签名/验签的基础，应用签名工具实现了标准的非对称密钥对生成功能（支持的密钥对类型包括ECC P384/256、RSA2048/3072/4096）

 - CSR：

   CSR（Certificate Signing Request）证书签发请求是生成证书的前提，他包括证书的公钥、证书主题和私钥签名，在申请证书之前，需要先基于密钥对生成CSR，然后提交给CA签发证书。

 - 证书：

   OpenHarmony采用RFC5280标准构建X509证书信任体系。用于应用签名的OpenHarmony证书共有三级，分为：根CA证书、中间CA证书、最终实体证书，其中最终实体证书分为应用签名证书和profile签名证书。应用签名证书表示应用开发者的身份，可保证系统上安装的应用来源可追溯，profile签名证书实现对profile文件的签名进行验签，保证profile文件的完整性。

 - HAP：

   HAP（OpenHarmony Ability Package）是Ability的部署包，OpenHarmony应用代码围绕Ability组件展开，它是由一个或者多个Ability组成。

 - Profile文件：

   [HarmonyAppProvision配置文件](app-provision-structure.md)，hap包中的描述文件，该描述文件描述了已授权的证书权限和设备ID信息等信息。

## 约束与限制

 - Hap包签名工具基于Java语言开发，需要Java8以上Java环境运行。

 - 一键签名等脚本文件基于Python语言开发，使用需配置环境python3.5及以上。
