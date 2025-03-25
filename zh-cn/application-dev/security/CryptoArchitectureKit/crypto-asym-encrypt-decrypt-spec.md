# 非对称密钥加解密算法规格

当前章节将说明系统目前支持的算法及其对应的规格。

对于每种算法采用支持的加密模式，将会在具体的每个算法规格中介绍。

## RSA

[RSA](crypto-asym-key-generation-conversion-spec.md#rsa)为非对称加密算法，加密长度需要在固定长度进行，在实际应用中，数据量可能无法达到固定的长度要求，此时可以通过不同的填充模式进行数据填充。

算法库目前提供了RSA加解密常用的三种模式有：

- [NoPadding](#填充模式为nopadding)：不带填充，输入的数据必须与RSA密钥字节长度一样长；输出数据长度与RSA密钥字节长度一样长。

- [PKCS1](#填充模式为pkcs1)：即RFC3447规范中的RSAES-PKCS1-V1_5模式，对应OpenSSL中的RSA_PKCS1_PADDING。
  
  在进行RSA运算时需要将源数据D转化为Encryption block（EB），加密时，输入的数据最大长度 &lt;= RSA密钥字节长度 - 11；输出数据长度与RSA密钥字节长度一样长。

- [PKCS1_OAEP](#填充模式为pkcs1_oaep)：即RFC3447规范中的RSAES-OAEP模式，对应OpenSSL中的RSA_PKCS1_OAEP_PADDING。
  
  此模式需要设置两个摘要（md和mgf1_md），加密时，输入的数据必须小于RSA密钥字节长度 - 2 *md摘要字节长度- 2；输出数据长度与RSA密钥字节长度一样长。

  此模式还可额外设置pSource字节流来定义OAEP填充的编码输入，并且可以获取PKCS1_OAEP的相关参数（如表所示）。

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
> 使用同步接口生成RSA2048、RSA3072、RSA4096、RSA8192非对称密钥或者明文长度超过2048会导致耗时增加。
>
> 由于系统对主线程有时间限制，耗时较长会导致失败，建议开发者在生成位数较大的密钥时，使用对应的异步接口，或是[使用多线程并发能力](../../arkts-utils/multi-thread-concurrency-overview.md)进行开发。

### 填充模式为NoPadding

以字符串参数完成RSA加解密，具体的“字符串参数”由“非对称密钥类型”和“填充模式 NoPadding”使用符号“|”拼接而成，用于在创建非对称加解密实例时，指定算法规格。

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

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度，加解密运算取决于实际输入的密钥长度。

### 填充模式为PKCS1

以字符串参数完成RSA加解密，具体的“字符串参数”由“非对称密钥类型”和“填充模式 PKCS1”使用符号“|”拼接而成，用于在创建非对称加解密实例时，指定算法规格。

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

### 填充模式为PKCS1_OAEP

以字符串参数完成RSA加解密，具体的“字符串参数”由“非对称密钥类型”、“填充模式 PKCS1_OAEP”、摘要、掩码摘要，使用符号“|”拼接而成，用于在创建非对称加解密实例时，指定算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。

举例说明，当需要非对称密钥类型为RSA2048、填充模式为PKCS1_OAEP、摘要算法为SHA256、掩码摘要为MGF1_SHA256的RSA密钥，其字符串参数为"RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA256"。

> **说明：**
>
> 输入的数据必须小于RSA密钥字节长度 - md摘要长度 - mgf1_md摘要长度 - 2。比如，当RSA密钥为512位时，不支持SHA512。

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

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度，加解密运算取决于实际输入的密钥长度。

### 获取/设置OAEP填充模式的参数

从API版本10开始支持RSA使用PKCS1_OAEP填充模式时，获取、设置相关参数，“√”表示支持对获取或设置该参数。

| OAEP参数 | 枚举值 | 获取 | 设置 | 
| -------- | -------- | -------- | -------- |
| md | OAEP_MD_NAME_STR | √ | - | 
| mgf | OAEP_MGF_NAME_STR | √ | - | 
| mgf1_md | OAEP_MGF1_MD_STR | √ | - | 
| pSource | OAEP_MGF1_PSRC_UINT8ARR | √ | √ | 

## SM2

[SM2](crypto-asym-key-generation-conversion-spec.md#sm2)为非对称加密算法，加密长度需要在固定长度进行。算法库目前支持以GM/T 0009-2012定义的格式加密或解密数据。

SM2非对称加密的结果由C1,C2,C3三部分组成。其中C1是根据生成的随机数计算出的椭圆曲线点，C2是密文数据，C3是通过指定摘要算法计算的值。

当前支持以字符串参数完成SM2加解密，具体的“字符串参数”由“非对称密钥类型（加解密算法+密钥长度）”、“摘要算法”使用符号“|”拼接而成，用于在创建对称加解密实例时，指定算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。SM2算法和密钥长度中间采用符号“_”拼接。

举例说明，当密钥长度为256bit、摘要算法为MD5的SM2密钥，其字符串参数为"SM2_256|MD5"。
| 非对称密钥类型 | 摘要算法 | API版本 | 
| -------- | -------- | -------- |
| SM2_256 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3] | 10+ | 
| SM2 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3] | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，SM2加解密参数输入密钥类型时支持不带长度，加解密运算取决于实际输入的密钥长度。

### 获取SM2摘要算法参数

从API版本11开始支持SM2获取摘要算法参数，“√”表示支持对获取或设置该参数。

| SM2加解密参数 | 枚举值 | 获取 | 设置 | 
| -------- | -------- | -------- | -------- |
| md | SM2_MD_NAME_STR | √ | - | 

### 转换SM2密文格式

从API版本12开始，支持SM2格式转换。当前支持的SM2密文格式为国密标准的ASN.1格式，其中各参数组合顺序为C1C3C2。

开发者可指定SM2密文的参数，将其转换成符合国密标准的ASN.1格式密文。反之，也可以从国密标准的ASN.1格式密文中提取具体的SM2密文参数，便于开发者自行组合成其他格式的SM2密文。

SM2密文参数，包括：

- xCoordinate：x分量，即C1_X。

- yCoordinate：y分量，即C1_Y。xCoordinate和yCoordinate可以转换成C1。

- cipherTextData：密文，即C2。

- hashData：杂凑值，即C3。

当前支持以字符串参数指定SM2密文格式转换的模式，如下表所示，“√”表示支持对获取或设置该参数。

| SM2密文格式转换模式 | 基于参数生成SM2密文 | 从SM2密文中获取参数 |
| --------  | -------- | -------- |
| C1C3C2 | √ | √ | 