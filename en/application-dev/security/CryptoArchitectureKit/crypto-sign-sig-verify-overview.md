# Signing and Signature Verification Overview and Algorithm Specifications

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

The digital signature can be used to verify whether the data came from the stated sender and has been changed.

This topic describes the supported algorithms and specifications for signing and signature verification.

> **NOTE**
>
> Currently, the C/C++ APIs support signature verification but not signing.

## RSA

The Crypto framework supports the following padding modes for RSA signing and signature verification:

- [PKCS1](#pkcs1): RSAES-PKCS1-V1_5 mode in RFC3447, corresponding to RSA_PKCS1_PADDING in OpenSSL.
  
  If this mode is used, you need to set the message digest (**md**). The length of the MD output must be less than the length of the RSA key. For example, the length of the RSA2048 key is 256 bytes.

- [PSS](#pss): RSASSA-PSS mode in RFC 3447, corresponding to RSA_PKCS1_PSS_PADDING in OpenSSL.
  
  If this padding mode is used, two message digests (**md** and **mgf1_md**) must be set, and the total length of **md** and **mgf1_md** must be less than the length of the RSA key. For example, the length of the RSA2048 key is 256 bytes.

  You can also set the salt length **saltLen** to obtain PSS-related parameters.  

  | PSS-related Parameter| Description| 
  | -------- | -------- |
  | md | MD algorithm.| 
  | mgf | Mask generation function. Currently, only MGF1 is supported.| 
  | mgf1_md | MD algorithm used in MGF1.| 
  | saltLen | Salt length, in bites.| 
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
> In RSA signing and signature verification, the MD length must be less than the length of the RSA key. For example, if the RSA key is 512 bits, SHA512 cannot be used.

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

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **RSA2048**, the padding mode is **PSS**, the MD algorithm is **SHA256**, and the mask digest is **MGF1_SHA256**, the string parameter is **RSA2048|PSS|SHA256|MGF1\_SHA256**.

> **NOTE**
>
> If PSS padding mode is used in RSA signing or signature verification, the total length of **md** and **mgf1_md** must be less than the length of the RSA key. For example, if the RSA key is 512 bits, **md** and **mgf1_md** cannot be **SHA256** at the same time.

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
| md | PSS_MD_NAME_STR | √ | - | 
| mgf | PSS_MGF_NAME_STR | √ | - | 
| mgf1_md | PSS_MGF1_MD_STR | √ | - | 
| saltLen | PSS_SALT_LEN_NUM | √ | √ | 
| trailer_field | PSS_TRAILER_FIELD_NUM | √ | - | 

### Signing Mode OnlySign

The Crypto framework provides RSA signing without MD.

When creating an RSA asymmetric signing (**Sign**) instance, you need to specify the signing specifications in a string parameter. The string parameter consists of the asymmetric key type, padding mode, MD algorithm, and signing mode with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **RSA2048**, the padding mode is **PKCS1**, the MD algorithm is **SHA256**, and the signing mode is **OnlySign**, the string parameter is **RSA2048|PKCS1|SHA256|OnlySign**.

> **NOTE**
>
> When the RSA is used for signing only, the length of the data to be signed must meet the following requirements:
>
> 1. If the padding mode is **PKCS1** and no MD algorithm is set (**NoHash**), the data must be less than the RSA key length minus 11 (PKCS #1 padding length), in bytes.
> 2. If the padding mode is **PKCS1** and an MD algorithm is set, the data to be signed must be the MD data.
> 3. If the padding mode is **NoPadding** and no MD algorithm is set (**NoHash**), the length of the data to be signed must be equal to that of the RSA key (in bytes) and the value must be less than the RSA modulus.

| Asymmetric Key Type| Padding Mode| MD Algorithm| Signing Mode| API Version| 
| -------- | -------- | -------- | -------- | -------- | 
| RSA512 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256] | OnlySign | 12+ | 
| RSA768 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA1024 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA2048 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA3072 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA4096 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA8192 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| [RSA512\|RSA768\|RSA1024\|RSA2048\|RSA3072\|RSA4096\|RSA8192\|RSA] | NoPadding | NoHash | OnlySign | 12+ | 
| RSA | PKCS1 | MD algorithm that meets the length requirements| OnlySign | 12+ | 

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the signing operation varies depending on the actual key length.

### Signature Verification Mode Recover

The Crypto framework provides the functionality of recovering the original data based on an RSA signature.

When creating an RSA signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type, padding mode, MD algorithm, and signature verification mode with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **RSA2048**, the padding mode is **PKCS1**, the MD algorithm is **SHA256**, and the signature verification mode is **Recover**, the string parameter is **RSA2048|PKCS1|SHA256|Recover**.

| Asymmetric Key Type| Padding Mode| MD Algorithm| Signing Mode| API Version| 
| -------- | -------- | -------- | -------- | -------- | 
| RSA512 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256] | Recover | 12+ | 
| RSA768 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA1024 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA2048 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA3072 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA4096 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA8192 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| [RSA512\|RSA768\|RSA1024\|RSA2048\|RSA3072\|RSA4096\|RSA8192\|RSA] | NoPadding | NoHash | Recover | 12+ | 
| RSA | PKCS1 | MD algorithm that meets the length requirements| Recover | 12+ | 

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the signature restore operation varies depending on the actual key length.

## ECDSA

Elliptic Curve Digital Signature Algorithm (ECDSA) is a digital signature algorithm (DSA) based on Elliptic Curve Cryptography (ECC). Compared with the ordinary Discrete Logarithm Problem (DLP) and Integer Factorization Problem (IFP), the ECC provides a higher unit bit strength than other public-key cryptographic systems.

The Crypto Framework provides ECDSA signing and signature verification capabilities that combine a variety of elliptic curves and digest algorithms.

When creating an ECDSA asymmetric signing (**Sign**) or signature verification (**Verify**) instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type and MD with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. For example, if the asymmetric key type is **ECC224** and the MD algorithm is **SHA256**, the string parameter is **ECC224|SHA256**.

| Asymmetric Key Type| MD| API Version| 
| -------- | -------- | -------- |
| ECC224 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| ECC256 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| ECC384 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| ECC521 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| ECC_BrainPoolP160r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP160t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP192r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP192t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP224r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP224t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP256r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP256t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP320r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP320t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP384r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP384t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP512r1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_BrainPoolP512t1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 11+ | 
| ECC_Secp256k1 | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 14+ | 
| ECC | [SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 

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
> If DSA is used with the digest algorithm **NoHash**, signing or signature verification by segment is not supported.

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
