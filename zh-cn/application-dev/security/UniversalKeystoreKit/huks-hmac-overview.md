# HMAC介绍及算法规格

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

MAC（Message Authentication Code）提供了一种在不可靠介质上检验传输或存储信息完整性的方法，HMAC是密钥相关的哈希运算消息认证码（Hash-based Message Authentication Code），是一种基于Hash函数和密钥进行消息认证的方法。HMAC可以与任何加密哈希函数（例如SHA256、SM3等）结合使用，HUKS支持了HMAC结合主流的摘要算法进行使用。

## 支持的算法

以下为HMAC支持的规格说明。
<!--Del-->
面向OpenHarmony的厂商适配密钥管理服务规格分为必选规格和可选规格。必选规格为所有厂商均支持的算法规格。而对于可选规格，厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。

**建议开发者使用必选规格开发应用，可保证全平台兼容。**
<!--DelEnd-->
| 摘要算法 | 支持的密钥长度 | API级别 | <!--DelCol4-->是否必选规格 |
| -------- | -------- | -------- | -------- |
| <!--DelRow-->SHA1、SHA224 | 8 - 1024 | 8+ | 否 |
| SHA256 | 192 - 1024 | 8+ | 是 |
| SHA384、SHA512 | 256 - 1024 | 8+ | 是 |
| SM3 | <!--RP1-->8 - 4096<!--RP1End--> | 8+ | 是 |