# Signing and Signature Verification Overview and Algorithm Specifications

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=d93383360d36e72d15ef3e14ccb0a6b358a4f8a5 translatedAt=2026-08-12T07:10:03.970Z pushedAt=2026-08-12T07:29:25.317Z -->

The digital signature can be used to verify whether the data came from the stated sender and has been changed.

This topic describes the supported algorithms and specifications for signing and signature verification.

 > **NOTE**
 > 
 > Currently, C/C++ APIs support signature verification since API version 12 and support signing since API version 20.

## RSA

The Crypto framework supports the following padding modes for RSA signing and signature verification:

- [PKCS1](#pkcs1): RSAES-PKCS1-V1_5 mode in RFC3447, corresponding to RSA_PKCS1_PADDING in OpenSSL.

  If this mode is used, you need to set the message digest (**md**). The length of the MD output must be less than the length of the RSA key. For example, the length of the RSA2048 key is 256 bytes.

- [PSS](#pss): RSASSA-PSS mode in RFC 3447, corresponding to RSA_PKCS1_PSS_PADDING in OpenSSL.

  If this mode is used, you need to set two digests (**md** and **mgf1_md**), and the total length of the **md** digest, **saltLen**, and **2** must be less than or equal to the length of the RSA key.

  You can also set the salt length **saltLen** to obtain PSS-related parameters.  

  | PSS-related Parameter| Description| 
  | -------- | -------- |
  | md | MD algorithm.| 
  | mgf | Mask generation function. Currently, only MGF1 is supported.| 
  | mgf1_md | MD algorithm used in MGF1.| 
  | saltLen | Salt length, in bytes.| 
  | trailer_field | Integer used for encoding. The value can only be **1**.| 

> **NOTE**
>
> It takes time to generate an RSA2048, RSA3072, RSA4096, or RSA8192 asymmetric key pair or when the plaintext length exceeds 2048 bits.
>
> Since the execution of the main thread has a time limit, the operation may fail if you use a synchronous API. You are advised to use asynchronous APIs or use [multithread concurrent tasks](../../arkts-utils/multi-thread-concurrency-overview.md) to generate a key of a large size.

### PKCS1

When creating an RSA asymmetric signing (**Sign**) or signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type, padding mode PKCS1, and MD algorithm with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **RSA512**, the padding mode is **PKCS1**, and the MD algorithm is **MD5**, the string parameter is **RSA512|PKCS1|MD5**.

> **NOTE**
>
> In RSA signing and signature verification, the MD length must be less than the length of the RSA key. For example, if the RSA key is 512 bits, **SHA512** cannot be used.

| Asymmetric Key Type| Padding Mode| MD Algorithm| API Version| 
| -------- | -------- | -------- | -------- |
| RSA512 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384] | 9+ | 
| RSA768 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA1024 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA2048 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA3072 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA4096 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA8192 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA | PKCS1 | MD algorithm that meets the length requirements| 10+ | 

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the signing or signature verification operation varies depending on the actual key length.

### PSS

When creating an RSA asymmetric signing (**Sign**) or signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type, padding mode PSS, MD, and mask digest with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **RSA2048**, the padding mode is **PSS**, the MD algorithm is **SHA256**, and the mask digest is **MGF1_SHA256**, the string parameter is **RSA2048|PSS|SHA256|MGF1_SHA256**.

| Asymmetric Key Type| Padding Mode| MD| Mask Digest| API Version| 
| -------- | -------- | -------- | -------- | -------- |
| RSA512 | PSS | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256] | 9+ | 
| RSA512 | PSS | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256] | 9+ | 
| RSA512 | PSS | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256] | 9+ | 
| RSA512 | PSS | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224] | 9+ | 
| RSA768 | PSS | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA768 | PSS | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA768 | PSS | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA768 | PSS | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384] | 9+ | 
| RSA768 | PSS | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256] | 9+ | 
| RSA768 | PSS | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224] | 9+ | 
| RSA1024 | PSS | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA1024 | PSS | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA1024 | PSS | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA1024 | PSS | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA1024 | PSS | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA1024 | PSS | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384] | 9+ | 
| RSA2048 | PSS | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA2048 | PSS | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA2048 | PSS | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA2048 | PSS | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA2048 | PSS | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA2048 | PSS | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA3072 | PSS | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA3072 | PSS | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA3072 | PSS | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA3072 | PSS | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA3072 | PSS | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA3072 | PSS | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA4096 | PSS | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA4096 | PSS | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA4096 | PSS | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA4096 | PSS | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA4096 | PSS | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA4096 | PSS | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA8192 | PSS | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA8192 | PSS | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA8192 | PSS | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA8192 | PSS | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA8192 | PSS | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA8192 | PSS | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ | 
| RSA | PSS | MD algorithm that meets the length requirements| MGF1_ MD algorithm that meets the length requirements| 10+ | 

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the signing or signature verification operation varies depending on the actual key length.

### Getting and Setting of PSS Parameters

The following table lists the parameters that can be set or obtained when the PSS mode is used. The symbol "√" indicates that the parameter can be obtained or set.

| PSS Parameter| Value| Get| Set|
| -------- | -------- | -------- | -------- |
| md | PSS_MD_NAME_STR | √ | N/A |
| mgf | PSS_MGF_NAME_STR | √ | N/A |
| mgf1_md | PSS_MGF1_MD_STR | √ | N/A |
| saltLen | PSS_SALT_LEN_NUM | √ | √ |
| trailer_field | PSS_TRAILER_FIELD_NUM | √ | N/A |

### OnlySign/OnlyVerify in PKCS1 Mode

The Crypto framework provides RSA signing without MD. Since API version 26.0.0, signature verification without MD is also supported.

When creating an RSA asymmetric signing (**Sign**) instance, you need to specify the signing specifications in a string parameter. The string parameter consists of the asymmetric key type, padding mode, MD algorithm, signing mode, and signature verification with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **RSA2048**, padding mode is **PKCS1**, MD algorithm is **SHA256**, and signing mode is **OnlySign**, the string parameter is **RSA2048|PKCS1|SHA256|OnlySign**. If the signature verification mode is **OnlyVerify**, the string parameter is **RSA2048|PKCS1|SHA256|OnlyVerify**.

> **NOTE**
>
> When the RSA is used for signing only, the length of the data to be signed must meet the following requirements:
>
> 1. If the padding mode is **PKCS1** and no MD algorithm is set (**NoHash**), the data must be less than the RSA key length minus 11 (PKCS #1 padding length), in bytes.
> 2. If the padding mode is **PKCS1** and an MD algorithm is set, the data to be signed must be the MD data.
> 3. If the padding mode is **NoPadding** and no MD algorithm is set (**NoHash**), the length of the data to be signed must be equal to that of the RSA key (in bytes) and the value must be less than the RSA modulus.

> **NOTE**
>
> Signature verification supports the OnlyVerify mode since API version 26.0.0.

| Asymmetric Key Type| Padding Mode| MD Algorithm| Signing/Signature Verification Mode| API Version| 
| -------- | -------- | -------- | -------- | -------- | 
| RSA512 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256] | OnlySign/OnlyVerify | 12+ | 
| RSA768 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 12+ | 
| RSA1024 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 12+ | 
| RSA2048 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 12+ | 
| RSA3072 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 12+ | 
| RSA4096 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 12+ | 
| RSA8192 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 12+ | 
| [RSA512\|RSA768\|RSA1024\|RSA2048\|RSA3072\|RSA4096\|RSA8192\|RSA] | NoPadding | NoHash | OnlySign/OnlyVerify | 12+ | 
| RSA | PKCS1 | MD algorithm that meets the length requirements| OnlySign/OnlyVerify | 12+ | 

As shown in the last row of the table, to be compatible with the key generated by the key parameter, the number of bits may not be specified when the key type is entered for RSA signing/signature verification (that is, RSA is used). In this case, whether the algorithm specification is supported depends on the actual number of bits of the key passed during signing/signature verification initialization. For example, if RSA|PKCS1|SHA384 is used and an RSA512 key is passed during initialization, this specification is not supported because the length constraint is not met.

### OnlySign/OnlyVerify in PSS Mode

> **NOTE**
>
> Since API version 26.0.0, **OnlySign** and **OnlyVerify** in PSS mode are supported.
>
> The requirements for the asymmetric key type, digest and mask digest value range, and length limit are the same as those for signature verification in PSS mode.

The specifications of **OnlySign** and **OnlyVerify** in PSS mode are the same as those of PSS signature verification. The only difference is the mode (**OnlySign** or **OnlyVerify**) at the end of the string parameter.

String format: "Asymmetric key type|PSS|MD algorithm|Mask MD algorithm|OnlySign/OnlyVerify".

For example, if the asymmetric key type is **RSA2048**, padding mode is **PSS**, MD algorithm is **SHA256**, mask MD algorithm is **MGF1_SHA256**, and signing mode is **OnlySign**, the string parameter is **RSA2048|PSS|SHA256|MGF1_SHA256|OnlySign**. If the signature verification mode is **OnlyVerify**, the string parameter is **RSA2048|PSS|SHA256|MGF1_SHA256|OnlyVerify**.

### Signature Verification Mode Recover

The Crypto framework provides the functionality of recovering the original data based on an RSA signature.

When creating an RSA signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type, padding mode, MD algorithm, and signature verification mode with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **RSA2048**, padding mode is **PKCS1**, MD algorithm is **SHA256**, and signature verification mode is **Recover**, the string parameter is **RSA2048|PKCS1|SHA256|Recover**.

| Asymmetric Key Type | Padding Mode | Digest Algorithm | Verify Mode | API Version |
| -------- | -------- | -------- | -------- | -------- |
| RSA512 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256] | Recover | 12+ |
| RSA768 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ |
| RSA1024 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ |
| RSA2048 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ |
| RSA3072 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ |
| RSA4096 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ |
| RSA8192 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ |
| [RSA512\|RSA768\|RSA1024\|RSA2048\|RSA3072\|RSA4096\|RSA8192\|RSA] | NoPadding | NoHash | Recover | 12+ |
| RSA | PKCS1 | a digest algorithm that meets the length requirement | Recover | 12+ |

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the signature restore operation varies depending on the actual key length.

## ECDSA

ECDSA (Elliptic Curve Digital Signature Algorithm) is a digital signature algorithm (DSA) based on elliptic curve cryptography (ECC). Compared with DLP (Discrete Logarithm Problem) and IFP (Integer Factorization Problem), elliptic curve cryptography offers higher strength per bit than other public-key cryptosystems.

The Crypto framework provides ECDSA signing and signature verification capabilities that combine a variety of elliptic curves and MD algorithms, and support **OnlySign** and **OnlyVerify**.

When creating an ECDSA asymmetric signing (**Sign**) or signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type and MD with a vertical bar (|) in between.

As shown in the table, you can select only one option from each value range (the content in []) for string concatenation. For example, if you need a key with the asymmetric key type ECC224 and the digest algorithm SHA256, the string parameter is "ECC224|SHA256". For signing and verification in **OnlySign** and **OnlyVerify** modes, the string parameters are "ECC224|SHA256|OnlySign" and "ECC224|SHA256|OnlyVerify", respectively.

> **NOTE**
>
> Since API version 26.0.0, **OnlySign** and **OnlyVerify** in ECC mode are supported.
>
> Signature verification for empty messages is not supported.

| Asymmetric Key Type| MD| Signing/Signature Verification Mode| API Version|
| -------- | -------- | -------- | -------- |
| ECC192 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 26.0.0+ |
| ECC224 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 9+ |
| ECC256 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 9+ |
| ECC384 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 9+ |
| ECC521 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 9+ |
| ECC_BrainPoolP160r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP160t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP192r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP192t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP224r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP224t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP256r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP256t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP320r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP320t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP384r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP384t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP512r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_BrainPoolP512t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 11+ |
| ECC_Secp256k1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 14+ |
| ECC | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign/OnlyVerify | 10+ |

As indicated by the last row in the preceding table, you can specify the key type without the key length and curve name to ensure compatibility with the key generated based on the key parameter. In this case, the signing or signature verification operation varies depending on the actual key length.

## DSA

The Digital Signature Algorithm (DSA) stands out with great compatibility and applicability.

When creating a DSA asymmetric signing (**Sign**) or signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type and MD with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **DSA1024** and the MD algorithm is **SHA256**, the string parameter is **DSA1024|SHA256**.

| Asymmetric Key Type| MD| API Version| 
| -------- | -------- | -------- |
| DSA1024 | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 
| DSA2048 | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 
| DSA3072 | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 
| DSA | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 

As indicated by the last row in the preceding table, you can specify the DSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the signing or signature verification operation varies depending on the actual key length.

> **NOTE**
>
> If DSA is used with the MD algorithm set to **NoHash**, signing or signature verification by segment is not supported.

## SM2

SM2 is a digital signature algorithm based on ECC.

When creating an SM2 asymmetric signing (**Sign**) or signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type and MD with a vertical bar (|) in between.

Currently, SM2 signing support only SM3.

| Asymmetric Key Type| MD| String Parameter| API Version| 
| -------- | -------- | -------- | -------- |
| SM2_256 | SM3 | SM2_256\|SM3 | 10+ | 
| SM2 | SM3 | SM2\|SM3 | 10+ | 

As indicated by the last row in the preceding table, you can specify the SM2 key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the signing or signature verification operation varies depending on the actual key length.

## Ed25519

Ed25519 is a signing and signature verification algorithm based on the ECC.

When creating an Ed25519 asymmetric signing (Sign) or signature verification (Verify) instance, you need to specify the algorithm specifications in a string parameter.

| Asymmetric Key Type| String Parameter| API Version| 
| -------- | -------- | -------- |
| Ed25519 | Ed25519 | 11+ | 

## ML-DSA

Starting from API version 26.0.0, the ML-DSA (Module-Lattice-Based Digital Signature Algorithm) is supported. This algorithm is a post-quantum cryptographic digital signature algorithm based on module lattices.

Create an ML-DSA signing or signature verification instance using a string parameter.

| Asymmetric Key Type | String Parameter | API Version |
| -------- | -------- | -------- |
| ML-DSA | ML-DSA | 26.0.0+ |