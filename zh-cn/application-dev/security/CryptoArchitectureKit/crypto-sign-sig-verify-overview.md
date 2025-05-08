# 签名验签介绍及算法规格

当需要判断接收的数据是否被篡改、数据是否为指定对象发送的数据时，可以使用签名验签操作。

接下来将说明系统目前支持的算法及其对应的规格。

> **说明：**
>
> 当前使用C/C++的方式开发只支持验签，不支持签名。

## RSA

算法库框架目前提供了两种RSA签名验签的填充模式：

- [PKCS1](#填充模式为pkcs1)：即RFC3447规范中的RSAES-PKCS1-V1_5模式，对应OpenSSL中的RSA_PKCS1_PADDING。
  
  使用该模式时需要设置摘要（md），摘要算法输出的长度需要小于RSA密钥长度。例如RSA2048的密钥字节长度为256。

- [PSS](#填充模式为pss)： 即RFC3447规范中的RSASSA-PSS模式，对应OpenSSL中的RSA_PKCS1_PSS_PADDING。
  
  使用该模式时需要设置两个摘要（md和mgf1_md），且md和mgf1_md长度之和需要小于RSA的密钥长度。例如RSA2048的密钥字节长度为256。

  此模式还可额外设置盐长度saltLen，并用于获取PSS的相关参数。（单位：字节）

  | PSS的相关参数 | 说明 | 
  | -------- | -------- |
  | md | 摘要算法。 | 
  | mgf | 掩码生成算法，目前仅支持MGF1。 | 
  | mgf1_md | MGF1算法中使用的摘要算法。 | 
  | saltLen | 盐长度。（单位：字节） | 
  | trailer_field | 用于编码操作的整数，只支持为1。 | 

> **注意：**
>
> 使用同步接口生成RSA2048、RSA3072、RSA4096、RSA8192非对称密钥或者明文长度超过2048会导致耗时增加。
>
> 由于系统对主线程有时间限制，耗时较长会导致失败，建议开发者在生成位数较大的密钥时，使用对应的异步接口或是[使用多线程并发能力](../../arkts-utils/multi-thread-concurrency-overview.md)进行开发。

### 填充模式为PKCS1

以字符串参数完成RSA签名验签，具体的“字符串参数”由“非对称密钥类型”、“填充模式 PKCS1”和“摘要”使用符号“|”拼接而成，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。举例说明，当需要非对称密钥类型为RSA512、填充模式为PKCS1、摘要算法为MD5的密钥时，其字符串参数为"RSA512|PKCS1|MD5"。

> **说明：**
>
> RSA签名验签时，摘要算法输出的长度，需要小于RSA的密钥长度。如RSA密钥为512位时，不支持SHA512。

| 非对称密钥类型 | 填充模式 | 摘要算法 | API版本 | 
| -------- | -------- | -------- | -------- |
| RSA512 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256] | 9+ | 
| RSA768 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA1024 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA2048 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA3072 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA4096 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA8192 | PKCS1 | [MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 9+ | 
| RSA | PKCS1 | 符合长度要求的摘要算法 | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。

### 填充模式为PSS

以字符串参数完成RSA签名验签，具体的“字符串参数”由“非对称密钥类型”、“填充模式 PSS”、“摘要”和“掩码摘要”使用符号“|”拼接而成，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。举例说明，当需要非对称密钥类型为RSA2048、填充模式为PSS、摘要算法为SHA256、掩码摘要为MGF1_SHA256的密钥时，其字符串参数为"RSA2048|PSS|SHA256|MGF1_SHA256"。

> **说明：**
>
> RSA签名验签时，对于PSS模式，md和mgf1_md长度之和需要小于RSA的密钥长度。如RSA密钥为512位时，无法支持md和mgf1_md同时为SHA256。

| 非对称密钥类型 | 填充模式 | 摘要 | 掩码摘要 | API版本 | 
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
| RSA | PSS | 符合长度要求的摘要算法 | MGF1_符合长度要求的摘要算法 | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。

### 获取/设置PSS填充模式的参数

当前支持RSA使用PSS填充模式时，获取、设置相关参数，“√”表示支持对获取或设置该参数。

| PSS参数 | 枚举值 | 获取 | 设置 | 
| -------- | -------- | -------- | -------- |
| md | PSS_MD_NAME_STR | √ | - | 
| mgf | PSS_MGF_NAME_STR | √ | - | 
| mgf1_md | PSS_MGF1_MD_STR | √ | - | 
| saltLen | PSS_SALT_LEN_NUM | √ | √ | 
| trailer_field | PSS_TRAILER_FIELD_NUM | √ | - | 

### 签名模式为OnlySign

算法库框架目前提供了RSA签名不做摘要仅签名功能。

以字符串参数完成RSA签名，具体的“字符串参数”由“非对称密钥类型”、“填充模式”、“摘要”和“签名模式”使用符号“|”拼接而成，用于在创建非对称签名实例时，指定非对称签名算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。举例说明，当需要非对称密钥类型为RSA2048、填充模式为PKCS1、摘要算法为SHA256、签名模式为OnlySign的密钥时，其字符串参数为"RSA2048|PKCS1|SHA256|OnlySign"。

> **说明：**
>
> RSA仅签名时，对待签名数据有长度要求：
>
> 1. PKCS1填充模式，NoHash不设置摘要算法，数据需要小于RSA密钥字节长度-11（PKCS1填充长度）。
> 2. PKCS1填充模式，设置任意摘要算法，待签名的数据必须是对应的摘要数据。
> 3. NoPadding不设置填充模式，NoHash不设置摘要算法，待签名的数据长度需要等于RSA密钥字节长度，且其数值小于RSA模数。

| 非对称密钥类型 | 填充模式 | 摘要算法 | 签名模式 | API版本 | 
| -------- | -------- | -------- | -------- | -------- | 
| RSA512 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256] | OnlySign | 12+ | 
| RSA768 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA1024 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA2048 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA3072 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA4096 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| RSA8192 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | OnlySign | 12+ | 
| [RSA512\|RSA768\|RSA1024\|RSA2048\|RSA3072\|RSA4096\|RSA8192\|RSA] | NoPadding | NoHash | OnlySign | 12+ | 
| RSA | PKCS1 | 符合长度要求的摘要算法 | OnlySign | 12+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA签名参数输入密钥类型时支持不带长度，签名运算取决于实际输入的密钥长度。

### 验签模式为Recover

算法库框架目前提供了RSA签名恢复原始数据功能。

以字符串参数完成RSA签名恢复，具体的“字符串参数”由“非对称密钥类型”、“填充模式”、“摘要”和“验签模式”使用符号“|”拼接而成，用于在创建非对称验签实例时，指定非对称验签算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。举例说明，当需要非对称密钥类型为RSA2048、填充模式为PKCS1、摘要算法为SHA256、验签模式为Recover的密钥时，其字符串参数为"RSA2048|PKCS1|SHA256|Recover"。

| 非对称密钥类型 | 填充模式 | 摘要算法 | 签名模式 | API版本 | 
| -------- | -------- | -------- | -------- | -------- | 
| RSA512 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256] | Recover | 12+ | 
| RSA768 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA1024 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA2048 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA3072 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA4096 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| RSA8192 | PKCS1 | [NoHash\|MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | Recover | 12+ | 
| [RSA512\|RSA768\|RSA1024\|RSA2048\|RSA3072\|RSA4096\|RSA8192\|RSA] | NoPadding | NoHash | Recover | 12+ | 
| RSA | PKCS1 | 符合长度要求的摘要算法 | Recover | 12+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，RSA签名恢复参数输入密钥类型时支持不带长度，签名恢复运算取决于实际输入的密钥长度。

## ECDSA

ECDSA（Elliptic Curve Digital Signature Algorithm，椭圆曲线数字签名算法）是基于椭圆曲线密码（ECC）的数字签名算法（DSA）。相比DLP（Discrete logarithm Problem，普通的离散对数问题）和IFP（integer factorization problem，大数分解问题），椭圆曲线密码的单位比特强度要高于其他公钥体制。

算法库框架提供了多种椭圆曲线及摘要算法组合的ECDSA签名验签能力。

以字符串参数完成ECDSA签名验签，具体的“字符串参数”由“非对称密钥类型”和“摘要”使用符号“|”拼接而成，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。举例说明，当需要非对称密钥类型为ECC224、摘要算法为SHA256的密钥时，其字符串参数为"ECC224|SHA256"。

| 非对称密钥类型 | 摘要 | API版本 | 
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

如表中最后一行所示，为了兼容由密钥参数生成的密钥，ECDSA签名验签参数输入密钥类型时支持不指定长度和曲线，签名验签运算取决于实际输入的密钥。

## DSA

DSA（Digital Signature Algorithm，数字签名算法）的安全性基于整数有限域离散对数问题的困难性，具有较好的兼容性和适用性。

以字符串参数完成DSA签名验签，具体的“字符串参数”由“非对称密钥类型”和“摘要”使用符号“|”拼接而成，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。

如表所示，各取值范围（即[]中的内容）中，只能选取一项完成字符串拼接。举例说明，当需要非对称密钥类型为DSA1024、摘要算法为SHA256的密钥时，其字符串参数为"DSA1024|SHA256"。

| 非对称密钥类型 | 摘要 | API版本 | 
| -------- | -------- | -------- |
| DSA1024 | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 
| DSA2048 | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 
| DSA3072 | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 
| DSA | [NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512] | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，DSA签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。

> **说明：**
>
> 当使用DSA算法并设置摘要算法为NoHash时，则不支持分段签名或分段验签。

## SM2

SM2数字签名算法，是基于椭圆曲线的签名验签算法。

以字符串参数完成SM2签名验签，具体的“字符串参数”由“非对称密钥类型”和“摘要”使用符号“|”拼接而成，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。

当前SM2签名只支持SM3摘要。

| 非对称密钥类型 | 摘要 | 字符串参数 | API版本 | 
| -------- | -------- | -------- | -------- |
| SM2_256 | SM3 | SM2_256\|SM3 | 10+ | 
| SM2 | SM3 | SM2\|SM3 | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，SM2签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。

## Ed25519

Ed25519是基于椭圆曲线的签名验签算法。

以字符串参数完成Ed25519签名验签，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。

| 非对称密钥类型 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| Ed25519 | Ed25519 | 11+ | 
