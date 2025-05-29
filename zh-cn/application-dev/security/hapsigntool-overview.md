# 应用包签名工具概述

为了保证OpenHarmony应用和调试工具的完整性和来源可靠，需要对应用和调试工具进行签名。经过签名的应用和调试工具才能在真机设备上安装、运行、和调试。[developtools_hapsigner仓](https://gitee.com/openharmony/developtools_hapsigner)提供了签名工具的源码，包含密钥对生成、CSR文件生成、证书生成、Profile文件签名、应用包签名、调试工具签名等功能。
在支持强制代码签名机制的设备上，该机制可以为应用提供运行时的合法性校验以及完整性保护，杜绝未经审核的恶意代码在端侧任意执行，或应用代码被攻击者恶意篡改。 
签名工具默认开启代码签名，若用户确定不需要强制执行代码签名，可参考以下说明，关闭代码签名功能。签名工具当前仅支持对hap、hsp、hqf格式的应用包和二进制工具执行代码签名。

> **说明：** 
>
> 针对无需通过ACL跨级别申请权限的应用，DevEco Studio为开发者提供了自动化签名方案，可以一键完成应用/服务签名。具体可参考[自动化签名方案](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465)。

## 基本概念

应用包签名工具支持本地签名需求的开发，为OpenHarmony应用和调试工具提供完整性保护和来源管控机制，该签名工具基于PKI公钥证书的机制实现，在进行开发前，开发者应了解以下基本概念：

 - 非对称密钥对：

   非对称密钥算法是数据签名/验签的基础，应用签名工具实现了标准的非对称密钥对生成功能（支持的密钥对类型包括ECC P384/256、RSA2048/3072/4096）

 - CSR：

   CSR（Certificate Signing Request）证书签发请求是生成证书的前提，他包括证书的公钥、证书主题和私钥签名，在申请证书之前，需要先基于密钥对生成CSR，然后提交给CA签发证书。

 - 证书：

   OpenHarmony采用RFC5280标准构建X509证书信任体系。用于应用签名的OpenHarmony证书共有三级，分为：根CA证书、中间CA证书、最终实体证书，其中最终实体证书分为应用签名证书和profile签名证书。应用签名证书表示应用开发者的身份，可保证系统上安装的应用来源可追溯，profile签名证书实现对profile文件的签名进行验签，保证profile文件的完整性。

 - HAP：

   HAP（OpenHarmony Ability Package）是Ability的部署包，OpenHarmony应用代码围绕Ability组件展开，它是由一个或者多个Ability组成。

 - HSP：

   HSP（OpenHarmony Shared Package）是动态共享包，按照使用场景可以分为应用内HSP和应用间HSP。

 - HQF：

   HQF（OpenHarmony Ability Package Quick Fix）是修复HAP中问题的快速修复包，用于安装到设备上的快速修复单元。

 - 调试工具

   为开发者提供c++调试功能的工具链。如：[LLDB工具](../tools/lldb-tool.md)

 - Profile文件：

   [HarmonyAppProvision配置文件](app-provision-structure.md)，应用包中的描述文件，该描述文件描述了已授权的证书权限和设备ID信息等信息。

## 约束与限制

 - 应用包签名工具基于Java与C++语言开发，Java需要Java8以上Java环境运行；C++需要openharmony标准系统并使用C++17及以上的编译环境运行。

 - 一键签名等脚本文件（仅JAVA版本支持）基于Python语言开发，使用需配置环境python3.5及以上。
