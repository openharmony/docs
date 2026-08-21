# 加解密介绍

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

在数据存储或传输场景中，可以使用加解密操作保证数据的机密性，防止敏感数据泄露。

使用加解密操作时，典型的场景有：

1. 使用对称密钥的加解密操作。

2. 使用非对称密钥的加解密操作。

3. 使用RSA（PKCS1_OAEP填充模式）时，获取、设置CipherSpecItem参数。

## 对称密钥加解密算法规格

当前章节将说明系统目前支持的算法及其对应的规格。

对于每种算法采用支持的加密模式，将会在具体的每个算法规格中介绍。

### AES

算法库当前提供了[AES](crypto-key-generation-conversion.md#aes)加解密常用的7种加密模式：ECB、CBC、OFB、CFB、CTR、GCM和CCM。不同的加密模式适用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

由于AES为分组加密算法，分组长度为16字节。在实际应用中，最后一组明文可能不足16字节，此时可以通过不同的[填充模式](#填充模式)进行数据填充。

由于需要填充至分组大小，所以实际算法库中的PKCS5和PKCS7都是以分组大小作为填充长度的，即AES加密填充至16字节。

> **说明：**
>
> ECB、CBC加密模式，明文长度不是16字节整数倍，必须使用填充方法补足。
> CCM加密模式，必须指定附加验证数据aad且其长度必须大于等于1字节且小于等于2048字节。

当前支持以字符串参数完成AES加解密，具体的“字符串参数”由“对称密钥类型（加解密算法+密钥长度）”、“分组模式”和“填充模式”使用符号“|”拼接而成，用于在创建对称加解密实例时，指定算法规格。

- 如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。
  
  举例说明：
  - 当需要分组模式为ECB、密钥长度为128bit、填充模式为PKCS7，其字符串参数为"AES128|ECB|PKCS7"。
  
  - 当需要分组模式为CFB、密钥长度为256bit、填充模式为NoPadding，其字符串参数为"AES256|CFB|NoPadding"。

  | 分组模式 | 密钥长度（bit） | 填充模式 | API版本 | 
  | -------- | -------- | -------- | -------- |
  | ECB | [128\|192\|256] | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | CBC | [128\|192\|256] | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | CTR | [128\|192\|256] | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | OFB | [128\|192\|256] | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | CFB | [128\|192\|256] | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | GCM | [128\|192\|256] | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | CCM | [128\|192\|256] | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | XTS | [128\|256] | [NoPadding] | 26.0.0+ | 

- 从API版本10开始，支持对称加解密不带密钥长度的规格。加解密参数输入密钥类型时，支持不带长度，加解密运算取决于实际输入的密钥长度。
  
  举例说明，当需要分组模式为CFB、不带密钥长度、填充模式为NoPadding，其字符串参数为"AES|CFB|NoPadding"。

### DES

[DES](crypto-key-generation-conversion.md#des)算法的加密过程包含16轮相同的加密函数，每轮都使用不同的子密钥。子密钥是通过对原始密钥进行一系列的置换和移位操作生成的。在每一轮中，明文块被分为左右两部分，然后通过一系列的置换、替换和异或操作进行加密。

算法库当前提供了DES加解密常用的4种加密模式：ECB、CBC、OFB和CFB。不同的加密模式适用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

> **说明：**
>
> ECB、CBC加密模式，明文长度不是64位整数倍，必须使用填充方法补足。

当前支持以字符串参数完成DES加解密，具体的“字符串参数”由“对称密钥类型（加解密算法+密钥长度）”、“分组模式”和“填充模式”使用符号“|”拼接而成，用于在创建对称加解密实例时，指定算法规格。

- 如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。
  
  举例说明：
  - 当需要分组模式为ECB、密钥长度为64bit、填充模式为PKCS7，其字符串参数为"DES64|ECB|PKCS7"。
  
  - 当需要分组模式为OFB、密钥长度为64bit、填充模式为NoPadding，其字符串参数为"DES64|OFB|NoPadding"。

  | 分组模式 | 密钥长度（bit） | 填充模式 | API版本 | 
  | -------- | -------- | -------- | -------- |
  | ECB | 64 | [NoPadding\|PKCS5\|PKCS7] | 20+ | 
  | CBC | 64 | [NoPadding\|PKCS5\|PKCS7] | 20+ | 
  | OFB | 64 | [NoPadding\|PKCS5\|PKCS7] | 20+ | 
  | CFB | 64 | [NoPadding\|PKCS5\|PKCS7] | 20+ | 

- 从API版本10开始，支持对称加解密不带密钥长度的规格。加解密参数输入密钥类型时，支持不带长度，加解密运算取决于实际输入的密钥长度。

  举例说明，当需要分组模式为CFB、不带密钥长度、填充模式为NoPadding，其字符串参数为"DES|CFB|NoPadding"。

### 3DES

[3DES](crypto-key-generation-conversion.md#3des)算法的加解密过程分别是对明文/密文数据进行三次DES加密或解密，得到相应的密文或明文。

算法库当前提供了3DES加解密常用的4种加密模式：ECB、CBC、OFB和CFB。不同的加密模式适用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

由于DES为分组加密算法，分组长度为8字节。在实际应用中，最后一组明文可能不足8字节，此时可以通过不同的[填充模式](#填充模式)进行数据填充。

由于需要填充至分组大小，所以实际算法库中的PKCS5和PKCS7都是以分组大小作为填充长度的，即3DES加密填充至8字节。

> **说明：**
>
> ECB、CBC加密模式，明文长度不是8字节整数倍，必须使用填充方法补足。

当前支持以字符串参数完成3DES加解密，具体的“字符串参数”由“对称密钥类型（加解密算法+密钥长度）”、“分组模式”和“填充模式”使用符号“|”拼接而成，用于在创建对称加解密实例时，指定算法规格。

- 如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。
  
  举例说明：
  - 当需要分组模式为ECB、密钥长度为192bit、填充模式为PKCS7，其字符串参数为"3DES192|ECB|PKCS7"。
  
  - 当需要分组模式为OFB、密钥长度为192bit、填充模式为NoPadding，其字符串参数为"3DES192|OFB|NoPadding"。

  | 分组模式 | 密钥长度（bit） | 填充模式 | API版本 | 
  | -------- | -------- | -------- | -------- |
  | ECB | 192 | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | CBC | 192 | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | OFB | 192 | [NoPadding\|PKCS5\|PKCS7] | 9+ | 
  | CFB | 192 | [NoPadding\|PKCS5\|PKCS7] | 9+ | 

- 从API版本10开始，支持对称加解密不带密钥长度的规格。加解密参数输入密钥类型时，支持不带长度，加解密运算取决于实际输入的密钥长度。

  举例说明，当需要分组模式为CFB、不带密钥长度、填充模式为NoPadding，其字符串参数为"3DES|CFB|NoPadding"。

### SM4

算法库当前提供了[SM4](crypto-key-generation-conversion.md#sm4)加解密常用的7种加密模式：ECB、CBC、CTR、OFB、CFB、CFB128和GCM。不同的加密模式适用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

由于SM4为分组加密算法，分组长度为16字节。在实际应用中，最后一组明文可能不足16字节，此时可以通过不同的[填充模式](#填充模式)进行数据填充。

由于需要填充至分组大小，所以实际算法库中的PKCS5和PKCS7都是以分组大小作为填充长度的，即SM4加密填充至16字节。

> **说明：**
>
> ECB、CBC加密模式，明文长度不是16字节整数倍，必须使用填充方法补足。

当前支持以字符串参数完成SM4加解密，具体的“字符串参数”由“对称密钥类型（加解密算法+密钥长度）”、“分组模式”和“填充模式”使用符号“|”拼接而成，用于在创建对称加解密实例时，指定算法规格。

- 如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。SM4算法和密钥长度中间采用符号“_”拼接。
  
  举例说明：
  - 当需要分组模式为ECB、密钥长度为128bit、填充模式为PKCS7，其字符串参数为"SM4_128|ECB|PKCS7"。
  
  - 当需要分组模式为CFB、密钥长度为128bit、填充模式为NoPadding，其字符串参数为"SM4_128|CFB|NoPadding"。

  - 当需要分组模式为GCM、密钥长度为128bit、填充模式为NoPadding，其字符串参数为"SM4_128|GCM|NoPadding"。

  | 分组模式 | 密钥长度（bit） | 填充模式 | API版本 | 
  | -------- | -------- | -------- | -------- |
  | ECB | 128 | [NoPadding\|PKCS5\|PKCS7] | 10+ | 
  | CBC | 128 | [NoPadding\|PKCS5\|PKCS7] | 10+ | 
  | CTR | 128 | [NoPadding\|PKCS5\|PKCS7] | 10+ | 
  | OFB | 128 | [NoPadding\|PKCS5\|PKCS7] | 10+ | 
  | CFB | 128 | [NoPadding\|PKCS5\|PKCS7] | 10+ | 
  | CFB128 | 128 | [NoPadding\|PKCS5\|PKCS7] | 10+ | 
  | GCM | 128 | [NoPadding\|PKCS5\|PKCS7] | 12+ | 

### AES-WRAP

算法库提供AES-WRAP算法，该算法是一种基于[AES](crypto-key-generation-conversion.md#aes)的加密算法，用于安全地存储或传输对称密钥。它的主要目的是通过加密保护密钥，防止密钥在存储或传输过程中被泄露或篡改。

| 算法名称 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| AES128_WRAP | AES128_WRAP | 22+ | 
| AES192_WRAP | AES192_WRAP | 22+ | 
| AES256_WRAP | AES256_WRAP | 22+ | 

### 填充模式

分组加密算法有固定的分组长度，在实际应用中，最后一组明文的数据量可能无法达到固定的长度要求，此时可以通过不同的填充模式进行数据填充。填充模式有：

- NoPadding：不带填充。输入数据需要与分组长度匹配。

- PKCS5：填充字符由一个字节序列组成，而且每个字节填充的值与要填充的字节序列长度相同。PKCS5为8字节填充，即需将数据填充为八字节的倍数。

- PKCS7：填充方法和PKCS5一致。但PKCS7可以在1-255字节之间任意填充，PKCS5固定为8字节。

对于CFB、OFB、CTR、GCM、CCM这类将分组密码转化为流模式实现的模式，不需要填充，因此无论是否指定填充模式，都会按照NoPadding实现。

### ChaCha20

从API版本22开始，算法库支持该算法。

算法库当前提供了[ChaCha20](crypto-key-generation-conversion.md#chacha20)加解密，默认的ChaCha20加解密时需要传入IV。默认ChaCha20需要的加解密参数为[IvParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ivparamsspec)。

常用的加密模式：Poly1305。Poly1305模式适用的加解密参数为[Poly1305ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#poly1305paramsspec22)。

由于ChaCha20是流算法，无需填充算法。

当前支持以字符串参数完成ChaCha20加解密，具体的“字符串参数”由“对称密钥类型”和“分组模式”使用符号“|”拼接而成，用于在创建对称加解密实例时，指定算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。

| 对称算法名 | 密钥长度（bit） | 字符串参数 | API版本 | 
| -------- | -------- | -------- | -------- |
| ChaCha20 | 256 | ChaCha20 | 22+ | 
| ChaCha20 | 256 | ChaCha20\|Poly1305 | 22+ | 

### RC2

从API版本26.0.0开始，支持分组密码算法[RC2](crypto-key-generation-conversion.md#rc2)，分组长度为8字节，密钥长度支持8位～1024位，且该值须为8的倍数。

算法库当前提供了RC2加解密常用的分组模式：ECB、CBC、OFB、CFB。不同的加密模式适用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

> **说明：**
>
> ECB、CBC加密模式，明文长度不是8字节整数倍，必须使用填充方法补足。

当前支持以字符串参数完成RC2加解密，具体的“字符串参数”由“对称密钥类型”、“分组模式”和“填充模式”使用符号“|”拼接而成。字符串参数为RC2。

CBC、OFB、CFB模式需传入IV，IV长度为8字节，对应[IvParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ivparamsspec)。

| 分组模式 | 字符串参数 | 填充模式 | API版本 | 
| -------- | -------- | -------- | -------- |
| ECB | RC2 | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| CBC | RC2 | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| OFB | RC2 | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| CFB | RC2 | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 

### RC4

从API版本26.0.0开始，支持流密码算法[RC4](crypto-key-generation-conversion.md#rc4)，无需分组与填充。密钥长度支持8位～4096位，且该值须为8的倍数。

算法库当前提供RC4加解密，RC4为流密码模式，无需分组模式和填充模式。

当前支持以字符串参数完成RC4加解密，字符串参数为RC4：

| 对称算法名 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| RC4 | RC4 | 26.0.0+ | 

### Blowfish（BF）

从API版本26.0.0开始，支持密码算法[Blowfish](crypto-key-generation-conversion.md#blowfishbf)，是一种分组密码算法，分组长度为8字节，密钥长度支持32位～448位，且该值须为8的倍数。

> **说明：**
>
> ECB、CBC加密模式，明文长度不是8字节整数倍，必须使用填充方法补足。

CBC、OFB、CFB模式需传入IV，IV长度为8字节，对应[IvParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ivparamsspec)。

当前支持以字符串参数完成Blowfish加解密，字符串参数为Blowfish：

| 分组模式 | 字符串参数 | 填充模式 | API版本 | 
| -------- | -------- | -------- | -------- |
| ECB | Blowfish | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| CBC | Blowfish | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| OFB | Blowfish | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| CFB | Blowfish | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 

### CAST

从API版本26.0.0开始，支持分组密码算法[CAST](crypto-key-generation-conversion.md#cast)，分组长度为8字节，密钥长度支持40位～128位，且该值须为8的倍数。

[CAST](crypto-key-generation-conversion.md#cast)为分组密码算法，分组长度为8字节，密钥长度支持40位～128位，且该值须为8的倍数。

算法库当前提供了CAST加解密常用的分组模式：ECB、CBC、OFB、CFB。不同的加密模式适用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。

> **说明：**
>
> ECB、CBC加密模式，明文长度不是8字节整数倍，必须使用填充方法补足。

当前支持以字符串参数完成CAST加解密，字符串参数为CAST：

CBC、OFB、CFB模式需传入IV，IV长度为8字节，对应[IvParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#ivparamsspec)。
 
| 分组模式 | 字符串参数 | 填充模式 | API版本 | 
| -------- | -------- | -------- | -------- |
| ECB | CAST | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| CBC | CAST | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| OFB | CAST | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 
| CFB | CAST | [NoPadding\|PKCS5\|PKCS7] | 26.0.0+ | 

## 非对称密钥加解密算法规格

本章说明系统支持的算法及其规格。

每种算法支持的加密模式在具体规格中介绍。

### RSA

[RSA](crypto-key-generation-conversion.md#rsa)为非对称加密算法，加密数据长度需满足固定长度要求，在实际应用中，如果数据量无法达到固定的长度要求，可以通过不同的填充模式进行数据填充。

算法库目前提供了RSA加解密常用的三种模式。

- NoPadding：不带填充，输入的数据必须与RSA密钥字节长度一样长；输出数据长度与RSA密钥字节长度一样长。

- PKCS1：即RFC3447规范中的RSAES-PKCS1-V1_5模式，对应OpenSSL中的RSA_PKCS1_PADDING。
  
  RSA运算时，源数据D转化为Encryption block（EB），加密时，输入数据最大长度 <= RSA密钥字节长度 - 11；输出数据长度与RSA密钥字节长度相同。

- PKCS1_OAEP：即RFC3447规范中的RSAES-OAEP模式，对应OpenSSL中的RSA_PKCS1_OAEP_PADDING。
  
  此模式需要设置两个摘要（md和mgf1_md），加密时，输入数据长度必须小于RSA密钥字节长度 - 2 * md摘要字节长度 - 2；输出数据长度与RSA密钥字节长度相同。

  此模式可设置pSource字节流以定义OAEP填充的编码输入，并获取PKCS1_OAEP的相关参数。

  | PKCS1_OAEP的相关参数 | 说明 | 
  | -------- | -------- |
  | md | 摘要算法。 | 
  | mgf | 掩码生成算法，目前仅支持MGF1。 | 
  | mgf1_md | MGF1算法中使用的摘要算法。 | 
  | pSource | 字节流，用于编码输入。 | 

- 以RSA2048|SHA256举例说明输入数据长度与算法之间的关系。
  | 填充模式 | 输入数据的最大字节长度 | 输出数据的最大字节长度 |
  | -------- | -------- | -------- |
  | NoPadding | 256(RSA密钥字节长度) | 256 |
  | PKCS1 | 245(RSA密钥字节长度 - 11) | 256 |
  | PKCS1_OAEP | 190(RSA密钥字节长度 - 2 * md摘要字节长度 - 2) | 256 |

> **注意：**
>
> 使用同步接口生成RSA2048、RSA3072、RSA4096、RSA8192非对称密钥或明文长度超过2048均会增加耗时。
>
> 系统对主线程有时间限制，耗时较长会导致失败。建议生成大位数密钥时，使用异步接口或[使用多线程并发能力](../../arkts-utils/multi-thread-concurrency-overview.md)。

**填充模式为NoPadding**

以字符串参数完成RSA加解密。字符串参数由“非对称密钥类型”和“填充模式 NoPadding”使用符号“|”拼接而成，用于在创建非对称加解密实例时指定算法规格。

| 非对称密钥类型 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| RSA512 | RSA512\|NoPadding | 9+ | 
| RSA768 | RSA768\|NoPadding | 9+ | 
| RSA1024 | RSA1024\|NoPadding | 9+ | 
| RSA2048 | RSA2048\|NoPadding | 9+ | 
| RSA3072 | RSA3072\|NoPadding | 9+ | 
| RSA4096 | RSA4096\|NoPadding | 9+ | 
| RSA8192 | RSA8192\|NoPadding | 9+ | 
| RSA | RSA\|NoPadding | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度，加解密运算依据实际输入的密钥长度。

**填充模式为PKCS1**

以字符串参数完成RSA加解密，具体的“字符串参数”由“非对称密钥类型”和“填充模式 PKCS1”使用符号“|”拼接而成，用于在创建非对称加解密实例时指定算法规格。

| 非对称密钥类型 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| RSA512 | RSA512\|PKCS1 | 9+ | 
| RSA768 | RSA768\|PKCS1 | 9+ | 
| RSA1024 | RSA1024\|PKCS1 | 9+ | 
| RSA2048 | RSA2048\|PKCS1 | 9+ | 
| RSA3072 | RSA3072\|PKCS1 | 9+ | 
| RSA4096 | RSA4096\|PKCS1 | 9+ | 
| RSA8192 | RSA8192\|PKCS1 | 9+ | 
| RSA | RSA\|PKCS1 | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度，加解密运算取决于实际输入的密钥长度。

**填充模式为PKCS1_OAEP**

以字符串参数完成RSA加解密。字符串参数由“非对称密钥类型”、“填充模式 PKCS1_OAEP”、摘要和掩码摘要组成，使用符号“|”拼接，用于在创建非对称加解密实例时指定算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。

举例说明，当需要非对称密钥类型为RSA2048、填充模式为PKCS1_OAEP、摘要算法为SHA256、掩码摘要为MGF1_SHA256的RSA密钥，其字符串参数为"RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA256"。

| 非对称密钥类型 | 填充模式 | 摘要 | 掩码摘要 | API版本 | 
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
| RSA | PKCS1_OAEP | 符合长度要求的摘要算法 | MGF1_符合长度要求的摘要算法 | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度。加解密运算取决于实际输入的密钥长度。

**获取/设置OAEP填充模式的参数**

从API版本10开始，支持RSA使用PKCS1_OAEP填充模式时获取和设置相关参数，“√”表示支持获取或设置该参数。

| OAEP参数 | 枚举值 | 获取 | 设置 | 
| -------- | -------- | -------- | -------- |
| md | OAEP_MD_NAME_STR | √ | - | 
| mgf | OAEP_MGF_NAME_STR | √ | - | 
| mgf1_md | OAEP_MGF1_MD_STR | √ | - | 
| pSource | OAEP_MGF1_PSRC_UINT8ARR | √ | √ | 

### SM2

[SM2](crypto-key-generation-conversion.md#sm2)为非对称加密算法，加密数据长度需满足固定长度要求。算法库目前支持以GM/T 0009-2012定义的格式加密或解密数据。

SM2非对称加密的结果由C1、C2、C3三部分组成。其中C1是根据生成的随机数计算出的椭圆曲线点，C2是密文数据，C3是通过指定的摘要算法计算的值。

当前支持以字符串参数完成SM2加解密，具体的“字符串参数”由“非对称密钥类型（加解密算法+密钥长度）”、“摘要算法”使用符号“|”拼接而成，用于在创建非对称加解密实例时，指定算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。SM2算法和密钥长度之间采用符号“_”进行拼接。

举例说明，当密钥长度为256bit、摘要算法为MD5的SM2密钥，其字符串参数为"SM2_256|MD5"。
| 非对称密钥类型 | 摘要算法 | API版本 | 
| -------- | -------- | -------- |
| SM2_256 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3] | 10+ | 
| SM2 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3] | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，SM2加解密参数在输入密钥类型时支持不带长度。加解密运算取决于实际输入的密钥长度。

**获取SM2摘要算法参数**

从API版本11开始，支持SM2获取摘要算法参数，“√”表示支持获取或设置该参数。

| SM2加解密参数 | 枚举值 | 获取 | 设置 | 
| -------- | -------- | -------- | -------- |
| md | SM2_MD_NAME_STR | √ | - | 

**转换SM2密文格式**

从API版本12开始，支持SM2格式转换。当前支持的SM2密文格式为国密标准的ASN.1格式，其中各参数组合顺序为C1C3C2。

开发者可指定SM2密文参数，转换为符合国密标准的ASN.1格式密文。同样，可以从国密标准的ASN.1格式密文中提取SM2密文参数，便于重新组合成其他格式的SM2密文。

SM2密文参数，包括：

- xCoordinate：x分量，即C1_X。

- yCoordinate：y分量，即C1_Y。xCoordinate和yCoordinate可以转换成C1。

- cipherTextData：密文，即C2。

- hashData：杂凑值，即C3。

当前支持以字符串参数指定SM2密文格式转换的模式，如下表所示，“√”表示支持获取或设置该参数。

| SM2密文格式转换模式 | 基于参数生成SM2密文 | 从SM2密文中获取参数 |
| --------  | -------- | -------- |
| C1C3C2 | √ | √ | 

## 分段加解密说明

在加解密的过程中，算法库没有对单次或累计的传入数据量设置大小限制，但在传入的数据量较大时（如数据量大于2MB），建议开发者将数据分段，完成分段加解密，提高效率。

### 对称加解密

对称密钥的分段加解密，通过调用[Cipher.update](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#update-1)实现。

开发者可自定义单次传入的数据量（示例中的updateLength），多次调用update传入数据。

当前单次支持传入的最大长度为INT_MAX（Uint8Array类型的最大长度）。

**开发者应当对每次update和doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。**

**开发示例：** [使用aes对称密钥gcm模式分段加解密](crypto-aes-sym-encrypt-decrypt.md#使用aes对称密钥gcm模式分段加解密)

**开发示例：** [使用sm4对称密钥gcm模式分段加解密](crypto-sm4-sym-encrypt-decrypt.md#使用sm4对称密钥gcm模式分段加解密)

### 非对称加解密

非对称加解密，不支持update操作，仅需要调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)和[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)完成加解密。

非对称密钥的分段加密是指当明文大于单次加密支持的数据长度时（具体长度请查[非对称密钥加解密算法规格](crypto-encryption-decryption.md)），需要将待加密数据分为合适长度的数据段，并对每个数据段执行加密操作，即创建Cipher，然后调用[Cipher.init](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-1)和[Cipher.doFinal](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#dofinal-1)接口。

严格意义上说，是数据的拆分加解密，此时单次传入的数据量长度与密钥规格的长度相关。

- RSA：填充模式不同，输入的数据的规则不同。请根据[RSA算法规格](crypto-encryption-decryption.md#rsa)确认单次传入的数据量长度。

**开发者应当对每次doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。**

**开发示例：** [使用RSA非对称密钥分段加解密](crypto-rsa-asym-encrypt-decrypt.md#使用rsa非对称密钥分段加解密)

### 常见问题

- 分段加解密中，每次更新的数据量，与加密模式是否有关？

   每次更新的数据量，由开发者自定义，与加密模式无关。

   不同的加密模式，仅对加解密参数产生影响，不同的加密模式使用的加解密参数不同，具体请参考[ParamsSpec](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#paramsspec)。
