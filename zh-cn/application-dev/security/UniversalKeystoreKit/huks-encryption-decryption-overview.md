# 加密/解密介绍及算法规格

在HUKS中已经有密钥，需要对一段数据加密或是解密，均可以使用HUKS完成加密/解密操作。

## 支持的算法

以下为密钥加密/解密支持的规格说明。

面向OpenHarmony的厂商适配密钥管理服务规格分为必选规格和可选规格。必选规格为所有厂商均支持的算法规格。而对于可选规格，厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。

**建议开发者使用必选规格开发应用，可保证全平台兼容。**

| 算法/分组模式/填充模式 | 备注 | API级别 | 是否必选规格 | 
| -------- | -------- | -------- | -------- |
| AES/ECB/NoPadding<br/>AES/ECB/PKCS7 | - | 8+ | 否 | 
| AES/CBC/NoPadding<br/>AES/CBC/PKCS7<br/>AES/CTR/NoPadding | IV参数必选 | 8+ | 是 | 
| AES/GCM/NoPadding | 加密：Nonce、AAD参数必选<br/>解密：Nonce、AAD、AEAD参数必选 | 8+ | 是 | 
| RSA/ECB/NoPadding<br/>RSA/ECB/PKCS1_V1_5<br/>RSA/ECB/OAEP | OAEP填充模式支持的摘要算法：SHA256/SHA384/SHA512 | 8+ | 是 |
| SM4/ECB/NoPadding<br/>SM4/ECB/PKCS7<br/>SM4/CBC/PKCS7 | CBC模式下 IV 参数必选 | 9+ | 否 | 
| SM4/CTR/NoPadding<br/>SM4/CBC/NoPadding | IV 参数必选 | 9+ | 是 | 
| SM2/-/NoPadding | 摘要算法SM3 | 11+ | 是 | 
