# 签名/验签介绍及算法规格


为实现数据完整性保护和防抵赖，可使用生成/导入的密钥，对数据进行签名验签操作。


## 支持的算法

以下为密钥签名/验签支持的规格说明。

面向OpenHarmony的厂商适配密钥管理服务规格分为必选规格和可选规格。必选规格为所有厂商均支持的算法规格。而对于可选规格，厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。

**建议开发者使用必选规格开发应用，可保证全平台兼容。**

| 算法/摘要算法/填充模式 | 备注 | API级别 | 是否必选规格 | 
| -------- | -------- | -------- | -------- |
| RSA/MD5/PKCS1_V1_5<br/>RSA/SHA1/PKCS1_V1_5<br/>RSA/SHA224/PKCS1_V1_5<br/>RSA/SHA224/PSS | - | 8+ | 否 | 
| RSA/SHA256/PKCS1_V1_5<br/>RSA/SHA384/PKCS1_V1_5<br/>RSA/SHA512/PKCS1_V1_5<br/>RSA/SHA256/PSS<br/>RSA/SHA384/PSS<br/>RSA/SHA512/PSS | - | 8+ | 是 |
| RSA/NoDigest/PKCS1_V1_5 | NoDigest需要指定TAG HuksKeyDigest.HUSK_DIGEST_NONE | 9+ | 否 | 
| DSA/SHA1<br/>DSA/SHA224<br/>DSA/SHA256<br/>DSA/SHA384<br/>DSA/SHA512 | - | 8+ | 否 | 
| DSA/NoDigest | NoDigest需要指定TAG HuksKeyDigest.HUSK_DIGEST_NONE | 9+ | 否 | 
| ECC/SHA1<br/>ECC/SHA224 | - | 8+ | 否 | 
| ECC/SHA256<br/>ECC/SHA384<br/>ECC/SHA512 | - | 8+ | 是 |
| ECC/NoDigest | NoDigest需要指定TAG HuksKeyDigest.HUSK_DIGEST_NONE | 9+ | 否 | 
| ED22519/NoDigest | NoDigest需要指定TAG HuksKeyDigest.HUSK_DIGEST_NONE | 8+ | 是 | 
| SM2/SM3 | - | 9+ | 是 | 
