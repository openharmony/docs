# 加密/解密介绍及算法规格

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

在HUKS中已经有密钥，需要对一段数据加密或是解密，均可以使用HUKS完成加密/解密操作。

## 支持的算法

以下为密钥加密/解密支持的规格说明。
<!--Del-->
面向OpenHarmony的厂商适配密钥管理服务规格分为必选规格和可选规格。必选规格为所有厂商均支持的算法规格。而对于可选规格，厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。

**建议开发者使用必选规格开发应用，可保证全平台兼容。**
<!--DelEnd-->

**<!--RP1-->标准设备<!--RP1End-->规格**

| 算法/分组模式/填充模式 | 备注 | API级别 | <!--DelCol4-->是否必选规格 |
| -------- | -------- | -------- | -------- |
| <!--DelRow-->AES/ECB/NoPadding<br/>AES/ECB/PKCS7 | ECB模式下，若填充模式选择为NoPadding，因为该模式下要求明文数据必须按照固定长度的块进行加密，如果输入的数据长度不是16的倍数，就需要业务方自行填充，以满足块长度的要求。 | 8+ | 否 |
| AES/CBC/NoPadding<br/>AES/CBC/PKCS7<br/>AES/CTR/NoPadding | IV参数必选；CBC模式下，若填充模式选择为NoPadding，因为该模式下要求明文数据必须按照固定长度的块进行加密，如果输入的数据长度不是16的倍数，就需要业务方自行填充，以满足块长度的要求。 | 8+ | 是 |
| AES/GCM/NoPadding | 加密：Nonce参数必选。<br/>解密：Nonce、TAG参数必选。 | 8+ | 是 |
| RSA/ECB/NoPadding<br/>RSA/ECB/PKCS1_V1_5<br/>RSA/ECB/OAEP | OAEP填充模式支持的摘要算法：SHA256/SHA384/SHA512。 | 8+ | 是 |
| <!--DelRow-->SM4/ECB/NoPadding<br/>SM4/ECB/PKCS7 | ECB模式不推荐使用。 | 9+ | 否 |
| SM4/ECB/PKCS7 | ECB模式不推荐使用。 | 20+ | 是 |
| SM4/CBC/PKCS7 | IV 参数必选。 | 9+ | 是 |
| SM4/CTR/NoPadding<br/>SM4/CBC/NoPadding<br/>SM4/CFB/NoPadding<br/>SM4/OFB/NoPadding | IV 参数必选。 | 12+ | 是 |
| SM2/-/NoPadding | 摘要算法SM3。 | 11+ | 是 |
| DES/CBC/NoPadding<br/>DES/ECB/NoPadding | CBC模式下 IV 参数必选。 | 18+ | 是 |
| 3DES/CBC/NoPadding<br/>3DES/ECB/NoPadding | CBC模式下 IV 参数必选。 | 18+ | 是 |

**<!--RP2-->轻量级设备<!--RP2End-->规格**

<!--Del-->
轻量级设备所列规格，OEM厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。
<!--DelEnd-->

| 算法/分组模式/填充模式 | 备注 | API级别 |
| -------- | -------- | -------- |
| AES/GCM/NoPadding | 加密：Nonce参数必选。<br/>解密：Nonce、TAG参数必选。 | 8+ |
| AES/CBC/NoPadding<br/>AES/CTR/NoPadding | IV参数必选。 | 11+ |
| DES/ECB/NoPadding | - | 12+ |
| DES/CBC/NoPadding | IV参数必选。 | 12+ |
| 3DES/ECB/NoPadding | - | 12+ |
| 3DES/CBC/NoPadding | IV参数必选。 | 12+ |
| RSA/ECB/NoPadding | - | 12+ |
| RSA/ECB/PKCS1_V1_5 | - | 12+ |
| RSA/ECB/OAEP | 摘要算法SHA256。 | 12+ |