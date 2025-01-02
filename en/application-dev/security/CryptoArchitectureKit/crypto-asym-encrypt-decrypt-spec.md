# Asymmetric Key Encryption and Decryption Algorithm Specifications


This topic describes the supported algorithms and specifications for asymmetric key encryption and decryption.


For details about the cipher modes supported by each algorithm, see the specifications of each algorithm.


## RSA

[RSA](crypto-asym-key-generation-conversion-spec.md#rsa) is an asymmetric cipher, with fixed-length blocks. If the data length does not meet the requirement, padding is required.

The Crypto framework supports the following padding modes for RSA encryption and decryption:

- [NoPadding](#nopadding): No padding. The length of the input or output data must be the same as that of the RSA modulus (**n** in bytes).

- [PKCS1](#pkcs1): RSAES-PKCS1-V1_5 mode in RFC3447, corresponding to RSA_PKCS1_PADDING in OpenSSL.
  
  The RSA converts the source data (**D**) into encryption blocks (EBs). In encryption, the length of the input data must be less than or equal to the RSA modulus minus 11. The length of the output data is the same as that of the RSA modulus.

- [PKCS1_OAEP](#pkcs1_oaep): RSAES-OAEP mode in RFC 3447, corresponding to RSA_PKCS1_OAEP_PADDING in OpenSSL.
  
  In this mode, two message digests (**md** and **mgf1_md**) need to be set. In encryption, the input data must meet the following requirements:<br>Input data length < RSA modulus length – **md** length (bytes) – **mgf1_md** length (bytes) – 2<br>The length of the output data is the same as that of the RSA modulus.

  You can also set the **pSource** byte stream to define the encoding input for OAEP padding and obtain the PKCS1_OAEP parameters (as listed in the following table).

  | PKCS1_OAEP Parameter| Description|
  | -------- | -------- |
  | md | MD algorithm.|
  | mgf | Mask generation function. Currently, only MGF1 is supported.|
  | mgf1_md | MD algorithm used in MGF1.|
  | pSource | byte stream, which is the source for encoding input P in OAEP padding.|

> **NOTE**
>
> It takes time to generate an RSA2048, RSA3072, RSA4096, or RSA8192 asymmetric key pair or when the plaintext length exceeds 2048 bits. Since the execution of the main thread has a time limit, the operation may fail if you use a synchronous API. You are advised to use asynchronous APIs or use [multithread concurrent tasks](../../arkts-utils/multi-thread-concurrency-overview.md) to generate a key of a large size.

### NoPadding

The RSA encryption and decryption can be implemented based a string parameter. When creating a **Cipher** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type and padding mode (which is **NoPadding**) with a vertical bar (|) in between.

| Asymmetric Key Type| String Parameter| API Version|
| -------- | -------- | -------- |
| RSA512 | RSA512\|NoPadding | 9+ |
| RSA768 | RSA768\|NoPadding | 9+ |
| RSA1024 | RSA1024\|NoPadding | 9+ |
| RSA2048 | RSA2048\|NoPadding | 9+ |
| RSA3072 | RSA3072\|NoPadding | 9+ |
| RSA4096 | RSA4096\|NoPadding | 9+ |
| RSA8192 | RSA8192\|NoPadding | 9+ |
| RSA | RSA\|NoPadding | 10+ |

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the encryption or decryption operation varies depending on the actual key length.


### PKCS1

The RSA encryption and decryption can be implemented based a string parameter. When creating a **Cipher** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type and padding mode (which is **PKCS1**) with a vertical bar (|) in between.

| Asymmetric Key Type| String Parameter| API Version|
| -------- | -------- | -------- |
| RSA512 | RSA512\|PKCS1 | 9+ |
| RSA768 | RSA768\|PKCS1 | 9+ |
| RSA1024 | RSA1024\|PKCS1 | 9+ |
| RSA2048 | RSA2048\|PKCS1 | 9+ |
| RSA3072 | RSA3072\|PKCS1 | 9+ |
| RSA4096 | RSA4096\|PKCS1 | 9+ |
| RSA8192 | RSA8192\|PKCS1 | 9+ |
| RSA | RSA\|PKCS1 | 10+ |

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the encryption or decryption operation varies depending on the actual key length.


### PKCS1_OAEP

The RSA encryption and decryption can be implemented based a string parameter. When creating a **Cipher** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type, padding mode (which is **PKCS1_OAEP**), MD algorithm, and mask digest algorithm with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter.

For example, if the asymmetric key type is **RSA2048**, the padding mode is **PKCS1_OAEP**, the MD algorithm is **SHA256**, and the mask digest algorithm is **MGF1_SHA256**, the string parameter is **RSA2048|PKCS1_OAEP|SHA256|MGF1\_SHA256**.

> **NOTE**
>
> Input data length < RSA key modulus – **md** length – **mgf1_md** length – 2<br> For example, if the RSA key is of 512 bits, **SHA512** cannot be used.

| Asymmetric Key Type| Padding Mode| MD Algorithm| Mask Digest Algorithm| API Version|
| -------- | -------- | -------- | -------- | -------- |
| RSA512 | PKCS1_OAEP | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256] | 9+ |
| RSA512 | PKCS1_OAEP | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256] | 9+ |
| RSA512 | PKCS1_OAEP | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256] | 9+ |
| RSA768 | PKCS1_OAEP | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA768 | PKCS1_OAEP | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA768 | PKCS1_OAEP | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA768 | PKCS1_OAEP | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384] | 9+ |
| RSA1024 | PKCS1_OAEP | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA1024 | PKCS1_OAEP | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA1024 | PKCS1_OAEP | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA1024 | PKCS1_OAEP | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA1024 | PKCS1_OAEP | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA2048 | PKCS1_OAEP | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA2048 | PKCS1_OAEP | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA2048 | PKCS1_OAEP | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA2048 | PKCS1_OAEP | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA2048 | PKCS1_OAEP | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA2048 | PKCS1_OAEP | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA3072 | PKCS1_OAEP | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA3072 | PKCS1_OAEP | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA3072 | PKCS1_OAEP | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA3072 | PKCS1_OAEP | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA3072 | PKCS1_OAEP | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA3072 | PKCS1_OAEP | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA4096 | PKCS1_OAEP | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA4096 | PKCS1_OAEP | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA4096 | PKCS1_OAEP | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA4096 | PKCS1_OAEP | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA4096 | PKCS1_OAEP | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA4096 | PKCS1_OAEP | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA8192 | PKCS1_OAEP | MD5 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA8192 | PKCS1_OAEP | SHA1 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA8192 | PKCS1_OAEP | SHA224 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA8192 | PKCS1_OAEP | SHA256 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA8192 | PKCS1_OAEP | SHA384 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA8192 | PKCS1_OAEP | SHA512 | [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512] | 9+ |
| RSA | PKCS1_OAEP | MD algorithm that meets the length requirements| MGF1_ MD algorithm that meets the length requirements| 10+ |

As indicated by the last row in the preceding table, you can specify the RSA key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the encryption or decryption operation varies depending on the actual key length.


### Getting and Setting of OAEP Parameters

Since API version 10, OAEP parameters can be set and obtained when PKCS1_OAEP is used with RSA. In ths following table, the symbol "√" indicates that the parameter can be obtained or set.

| OAEP Parameter| Value| Get| Set|
| -------- | -------- | -------- | -------- |
| md | OAEP_MD_NAME_STR | √ | - |
| mgf | OAEP_MGF_NAME_STR | √ | - |
| mgf1_md | OAEP_MGF1_MD_STR | √ | - |
| pSource | OAEP_MGF1_PSRC_UINT8ARR | √ | √ |


## SM2

[SM2](crypto-asym-key-generation-conversion-spec.md#sm2) is an asymmetric encryption algorithm with a fixed length. Currently, the Crypto framework supports data encryption and decryption in the format defined in GM/T 0009-2012.

The SM2 asymmetric encryption result consists of C1, C2, and C3. C1 is the elliptic curve points calculated based on the random number generated. C2 is the ciphertext data. C3 is the value calculated using the specified MD algorithm.

SM2 encryption and decryption can be implemented based on a string parameter. When creating a **Cipher** instance, you need to specify the algorithm specifications in a string parameter. The string parameter consists of the asymmetric key type (algorithm_key length) and padding mode with a vertical bar (|) in between.

In the following table, the options included in the square brackets ([]) are mutually exclusive. You can use only one of them in a string parameter. The SM2 algorithm and key length are separated by an underscore (_).

For example, if the key length is 256 bits and the digest algorithm is MD5, the string parameter is **SM2_256|MD5**.
| Asymmetric Key Type| MD Algorithm| API Version|
| -------- | -------- | -------- |
| SM2_256 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3] | 10+ |
| SM2 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3] | 10+ |

As indicated by the last row in the preceding table, you can specify the SM2 key type without the key length to ensure compatibility with the key generated based on the key parameter. In this case, the encryption or decryption operation varies depending on the actual key length.


### SM2 MD Algorithm Parameter

Since API version 11, SM2 MD digest algorithm parameter can be obtained. The symbol "√" indicates that the parameter can be obtained or set.

| SM2 MD Algorithm Parameter| Value| Get| Set|
| -------- | -------- | -------- | -------- |
| md | SM2_MD_NAME_STR | √ | - |


### SM2 Ciphertext Format

Since API version 12, SM2 format conversion is supported. Currently, the SM2 ciphertext is in ASN.1 format, in which the parameters are in the **C1C3C2** order.

You can convert the SM2 ciphertext into ASN.1 format based on the SM2 parameters specified or obtain SM2 parameters from the SM2 ciphertext in ASN.1 format.

SM2 ciphertext consists of the following parameters:

- **xCoordinate**: coordinate X of C1, that is, **C1_X**.

- **yCoordinate**: coordinate Y of C1, that is, **C1_Y**. You can obtain **C1** based on **xCoordinate** and **yCoordinate**. **C1** is a point on the elliptic curve generated using a random number.

- **cipherTextData**: ciphertext, that is, **C2**.

- **hashData**: hash value, that is, **C3**.

A string parameter can be used to specify the SM2 ciphertext format conversion mode.

| SM2 Ciphertext Format Conversion Mode| Generate SM2 Ciphertext Based on Parameters| Obtain Parameters from SM2 Ciphertext|
| --------  | -------- | -------- |
| C1C3C2 | √ | √ |
