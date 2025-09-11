# Signing and Signature Verification Overview and Algorithm Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

To ensure data integrity and non-repudiation, you can use the generated or imported key to perform signing and signature verification.

## Supported Algorithms

The following table lists the supported specifications for signing and signature verification.
<!--Del-->
The key management service specifications include mandatory specifications and optional specifications. Mandatory specifications are algorithm specifications that must be supported. Optional specifications can be used based on actual situation. Before using the optional specifications, refer to the documents provided by the vendor to ensure that the specifications are supported.

**You are advised to use mandatory specifications in your development for compatibility purposes.**
<!--DelEnd-->

**Specifications****<!--RP3--> for standard devices<!--RP3End-->**

| Algorithm/MD Algorithm/Padding Mode| Description| API Version| <!--DelCol4-->Mandatory|
| -------- | -------- | -------- | -------- |
| <!--DelRow-->RSA/MD5/PKCS1_V1_5<br>RSA/SHA1/PKCS1_V1_5<br>RSA/SHA224/PKCS1_V1_5<br>RSA/SHA224/PSS | In PSS mode, the salt length can be set to the digest length or maximum length (Maximum length = Key length - Digest length - 2). For details, see [HuksRsaPssSaltLenType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksrsapsssaltlentype10).| 8+ | No|
| RSA/SHA256/PKCS1_V1_5<br>RSA/SHA384/PKCS1_V1_5<br>RSA/SHA512/PKCS1_V1_5<br>RSA/SHA256/PSS<br>RSA/SHA384/PSS<br>RSA/SHA512/PSS | In PSS mode, the salt length can be set to the digest length or maximum length (Maximum length = Key length - Digest length - 2). For details, see [HuksRsaPssSaltLenType](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksrsapsssaltlentype10).| 8+ | Yes|
| RSA/NoDigest/PKCS1_V1_5 | **TAG HuksKeyDigest.HUKS_DIGEST_NONE** must be specified with **NoDigest**. The service side hashes the plaintext and passes in the hashed data. The length of the hashed data must meet the MD algorithm specifications supported by RSA signing and signature verification.| 9+ | Yes|
| RSA/NoDigest/NoPadding | **TAG HuksKeyDigest.HUKS_DIGEST_NONE** must be specified with **NoDigest**. The plaintext length must be equal to the key length.| 20+ | Yes|
| <!--DelRow-->DSA/SHA1<br>DSA/SHA224<br>DSA/SHA256<br>DSA/SHA384<br>DSA/SHA512 | - | 8+ | No|
| <!--DelRow-->DSA/NoDigest | **TAG HuksKeyDigest.HUKS_DIGEST_NONE** must be specified with **NoDigest**.| 9+ | No|
| <!--DelRow-->ECC/SHA1<br>ECC/SHA224 | The signature is in the ASN1 format.| 8+ | No|
| ECC/SHA256<br>ECC/SHA384<br>ECC/SHA512 | The signature is in the ASN1 format.<br>The ECC algorithm supports the following elliptic curve functions: P-256, P-384, and P-521.| 8+ | Yes|
| <!--DelRow-->ECC/NoDigest | The signature is in the ASN1 format.<br>**TAG HuksKeyDigest.HUKS_DIGEST_NONE** must be specified with **NoDigest**.| 9+ | No|
| ED25519/NoDigest | **TAG HuksKeyDigest.HUKS_DIGEST_NONE** must be specified with **NoDigest**.| 8+ | Yes|
| SM2/SM3 | The signature is in the ASN1 format.| 9+ | Yes|

**Specifications****<!--RP4--> for mini-system devices<!--RP4End-->**

<!--Del-->
Before implementing the specifications for mini-system devices, determine whether your device supports the related specifications.
<!--DelEnd-->

| Algorithm/MD Algorithm/Padding Mode| Description| API Version|
| -------- | -------- | -------- |
| RSA/SHA256/PKCS1_V1_5 | - | 12+ |
| RSA/SHA256/PSS | - | 12+ |
| RSA/SHA1/ISO_IEC_9796_2 | Minimum data length = Key length - 21 bytes| 12+ |
| RSA/NoDigest/NoPadding | **TAG HuksKeyDigest.HUKS_DIGEST_NONE** must be specified with **NoDigest**. The plaintext length must be equal to the key length.| 20+ |

<!--RP1--><!--RP1End-->

<!--RP2--><!--RP2End-->
