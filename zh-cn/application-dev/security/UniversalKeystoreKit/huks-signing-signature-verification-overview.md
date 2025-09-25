# 签名/验签介绍及算法规格

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

为实现数据完整性保护和防抵赖，可使用生成/导入的密钥，对数据进行签名验签操作。

## 支持的算法

以下为密钥签名/验签支持的规格说明。
<!--Del-->
面向OpenHarmony的厂商适配密钥管理服务规格分为必选规格和可选规格。必选规格为所有厂商均支持的算法规格。而对于可选规格，厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。

**建议开发者使用必选规格开发应用，可保证全平台兼容。**
<!--DelEnd-->

**<!--RP3-->标准设备<!--RP3End-->规格**

| 算法/摘要算法/填充模式 | 备注 | API级别 | <!--DelCol4-->是否必选规格 |
| -------- | -------- | -------- | -------- |
| <!--DelRow-->RSA/MD5/PKCS1_V1_5<br/>RSA/SHA1/PKCS1_V1_5<br/>RSA/SHA224/PKCS1_V1_5<br/>RSA/SHA224/PSS | 对于PSS模式，salt长度支持设置为摘要长度和最大长度（最大长度=密钥长度-摘要长度-2），对应枚举值详见[HuksRsaPssSaltLenType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksrsapsssaltlentype10)。| 8+ | 否 |
| RSA/SHA256/PKCS1_V1_5<br/>RSA/SHA384/PKCS1_V1_5<br/>RSA/SHA512/PKCS1_V1_5<br/>RSA/SHA256/PSS<br/>RSA/SHA384/PSS<br/>RSA/SHA512/PSS | 对于PSS模式，salt长度支持设置为摘要长度和最大长度（最大长度=密钥长度-摘要长度-2），对应枚举值详见[HuksRsaPssSaltLenType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksrsapsssaltlentype10)。 | 8+ | 是 |
| RSA/NoDigest/PKCS1_V1_5 | NoDigest需要指定TAG HuksKeyDigest.HUKS_DIGEST_NONE。由业务对明文做哈希，再将哈希后的数据传入，哈希后的数据长度必须满足RSA签名验签支持的摘要算法规格。 | 9+ | 是 |
| RSA/NoDigest/NoPadding | NoDigest需要指定TAG HuksKeyDigest.HUKS_DIGEST_NONE。明文长度必须等于密钥长度。 | 20+ | 是 |
| <!--DelRow-->DSA/SHA1<br/>DSA/SHA224<br/>DSA/SHA256<br/>DSA/SHA384<br/>DSA/SHA512 | - | 8+ | 否 |
| <!--DelRow-->DSA/NoDigest | NoDigest需要指定TAG HuksKeyDigest.HUKS_DIGEST_NONE。 | 9+ | 否 |
| <!--DelRow-->ECC/SHA1<br/>ECC/SHA224 | 签名是ASN1格式。 | 8+ | 否 |
| ECC/SHA256<br/>ECC/SHA384<br/>ECC/SHA512 | 签名是ASN1格式。<br/>ECC算法支持的椭圆曲线函数包括：P-256、P-384、P-521。 | 8+ | 是 |
| <!--DelRow-->ECC/NoDigest | 签名是ASN1格式。<br/>NoDigest需要指定TAG HuksKeyDigest.HUKS_DIGEST_NONE。 | 9+ | 否 |
| ED25519/NoDigest | NoDigest需要指定TAG HuksKeyDigest.HUKS_DIGEST_NONE。 | 8+ | 是 |
| SM2/SM3 | 签名是ASN1格式。 | 9+ | 是 |
| SM2/NoDigest | 签名是ASN1格式。<br/>NoDigest需要指定TAG HuksKeyDigest.HUKS_DIGEST_NONE。由业务对明文做SM3哈希，再将哈希后的数据传入，哈希后的数据长度必须满足SM2签名验签支持的摘要算法规格。 | 22+ | 是 |

**<!--RP4-->轻量级设备<!--RP4End-->规格**

<!--Del-->
轻量级设备所列规格，OEM厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。
<!--DelEnd-->

| 算法/摘要算法/填充模式 | 备注 | API级别 |
| -------- | -------- | -------- |
| RSA/SHA256/PKCS1_V1_5 | - | 12+ |
| RSA/SHA256/PSS | - | 12+ |
| RSA/SHA1/ISO_IEC_9796_2 | 数据最小长度=密钥长度-21字节 | 12+ |
| RSA/NoDigest/NoPadding | NoDigest需要指定TAG HuksKeyDigest.HUKS_DIGEST_NONE。明文长度必须等于密钥长度。 | 20+ |

<!--RP1--><!--RP1End-->

<!--RP2--><!--RP2End-->