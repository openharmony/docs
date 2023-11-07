# @ohos.security.cryptoFramework (加解密算法库框架)

为屏蔽底层硬件和算法库，向上提供统一的密码算法库加解密相关接口。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import cryptoFramework from "@ohos.security.cryptoFramework";
```

## Result

 表示执行结果的枚举。

 **系统能力：** SystemCapability.Security.CryptoFramework

| 名称                                  |    值   |   说明                         |
| ------------------------------------- | -------- | ---------------------------- |
| INVALID_PARAMS                        | 401      | 非法入参。                   |
| NOT_SUPPORT                           | 801      | 操作不支持。                 |
| ERR_OUT_OF_MEMORY                     | 17620001 | 内存错误。                   |
| ERR_RUNTIME_ERROR                     | 17620002 | 运行时外部错误。             |
| ERR_CRYPTO_OPERATION                  | 17630001 | 调用三方算法库API出错。     |

## DataBlob

buffer数组，提供blob数据类型。

 **系统能力：** SystemCapability.Security.CryptoFramework

| 名称 | 类型       | 可读 | 可写 | 说明   |
| ---- | ---------- | ---- | ---- | ------ |
| data | Uint8Array | 是   | 是   | 数据。 |

## ParamsSpec

加解密参数，在进行对称加解密时需要构造其子类对象，并将子类对象传入[init()](#init-2)方法。

适用于需要iv等参数的对称加解密模式（对于无iv等参数的模式如ECB模式，无需构造，在[init()](#init-2)中传入null即可）。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 是   | 指明对称加解密参数的算法模式。可选值如下:<br/> - "IvParamsSpec": 适用于CBC\|CTR\|OFB\|CFB模式<br/> - "GcmParamsSpec": 适用于GCM模式<br/> - "CcmParamsSpec": 适用于CCM模式 |

> **说明：**
>
> 由于[init()](#init-2)的params参数是ParamsSpec类型（父类），而实际需要传入具体的子类对象（如IvParamsSpec），因此在构造子类对象时应设置其父类ParamsSpec的algName参数，使算法库在init()时知道传入的是哪种子类对象。

## IvParamsSpec

加解密参数[ParamsSpec](#paramsspec)的子类，用于在对称加解密时作为[init()](#init-2)方法的参数。

适用于CBC、CTR、OFB、CFB这些仅使用iv作为参数的加解密模式。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称 | 类型                  | 可读 | 可写 | 说明                                                         |
| ---- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv   | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv。常见取值如下：<br/>- AES的CBC\|CTR\|OFB\|CFB模式：iv长度为16字节<br/>- 3DES的CBC\|OFB\|CFB模式：iv长度为8字节<br/>- SM4<sup>10+</sup>的CBC\|CTR\|OFB\|CFB模式：iv长度为16字节。 |

> **说明：**
>
> 传入[init()](#init-2)方法前需要指定其algName属性（来源于父类[ParamsSpec](#paramsspec)）。

## GcmParamsSpec

加解密参数[ParamsSpec](#paramsspec)的子类，用于在对称加解密时作为[init()](#init-2)方法的参数。

适用于GCM模式。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型                  | 可读 | 可写 | 说明                                                         |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv，长度为1~16字节，常用为12字节。                             |
| aad     | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数aad，长度为0~INT_MAX字节，常用为16字节。                             |
| authTag | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数authTag，长度为16字节。<br/>采用GCM模式加密时，需要获取[doFinal()](#dofinal-2)输出的[DataBlob](#datablob)，取出其末尾16字节作为解密时[init()](#init-2)方法的入参[GcmParamsSpec](#gcmparamsspec)中的的authTag。 |

> **说明：**
>
> 1. 传入[init()](#init-2)方法前需要指定其algName属性（来源于父类[ParamsSpec](#paramsspec)）。
> 2. 对于在1~16字节长度范围内的iv，加解密算法库不作额外限制，但其结果取决于底层openssl是否支持。
> 3. 用户不需要使用aad参数或aad长度为0时，可以指定aad的data属性为空的Uint8Array，来构造GcmParamsSpec，写法为aad: { data: new Uint8Array() }。

## CcmParamsSpec

加解密参数[ParamsSpec](#paramsspec)的子类，用于在对称加解密时作为[init()](#init-2)方法的参数。

适用于CCM模式。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型                  | 可读 | 可写 | 说明                                                         |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv，长度为7字节。                              |
| aad     | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数aad，长度为8字节。                             |
| authTag | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数authTag，长度为12字节。<br/>采用CCM模式加密时，需要获取[doFinal()](#dofinal-2)输出的[DataBlob](#datablob)，取出其末尾12字节作为解密时[init()](#init-2)方法的入参[CcmParamsSpec](#ccmparamsspec)中的authTag。 |

> **说明：**
>
> 传入[init()](#init-2)方法前需要指定其algName属性（来源于父类[ParamsSpec](#paramsspec)）。

## CryptoMode

表示加解密操作的枚举。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称         | 值   | 说明               |
| ------------ | ---- | ------------------ |
| ENCRYPT_MODE | 0    | 表示进行加密操作。 |
| DECRYPT_MODE | 1    | 表示进行解密操作。 |

## AsyKeySpecItem<sup>10+</sup>

表示密钥参数的枚举。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称         | 值   | 说明             |
| ------------ | ---- | ---------------- |
| DSA_P_BN | 101 | DSA算法的素模数p。 |
| DSA_Q_BN | 102 | DSA算法中密钥参数q（p-1的素因子）。 |
| DSA_G_BN | 103 | DSA算法的参数g。 |
| DSA_SK_BN | 104 | DSA算法的私钥sk。 |
| DSA_PK_BN | 105 | DSA算法的公钥pk。 |
| ECC_FP_P_BN | 201 | DSA算法中表示椭圆曲线Fp域的素数p。 |
| ECC_A_BN | 202 | DSA算法中椭圆曲线的第一个系数a。 |
| ECC_B_BN | 203 | DSA算法中椭圆曲线的第二个系数b。 |
| ECC_G_X_BN | 204 | ECC算法中基点g的x坐标。 |
| ECC_G_Y_BN | 205 | ECC算法中基点g的y坐标。 |
| ECC_N_BN | 206 | ECC算法中基点g的阶n。 |
| ECC_H_NUM | 207 | ECC算法中的余因子h。 |
| ECC_SK_BN | 208 | ECC算法中的私钥sk。 |
| ECC_PK_X_BN | 209 | ECC算法中，公钥pk（椭圆曲线上的一个点）的x坐标。 |
| ECC_PK_Y_BN | 210 | ECC算法中，公钥pk（椭圆曲线上的一个点）的y坐标。 |
| ECC_FIELD_TYPE_STR | 211 | ECC算法中，椭圆曲线的域类型（当前只支持Fp域）。 |
| ECC_FIELD_SIZE_NUM | 212 | ECC算法中域的大小，单位为bits（注：对于Fp域，域的大小为素数p的bits长度）。 |
| ECC_CURVE_NAME_STR | 213 | ECC算法中的SECG曲线名称。 |
| RSA_N_BN | 301 | RSA算法中的模数n。 |
| RSA_SK_BN | 302 | RSA算法中的私钥sk（即私钥指数d）。 |
| RSA_PK_BN | 303 | RSA算法中的公钥pk（即公钥指数e）。 |

## AsyKeySpecType<sup>10+</sup>

表示密钥参数类型的枚举。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称         | 值   | 说明             |
| ------------ | ---- | ---------------- |
| COMMON_PARAMS_SPEC | 0 | 表示公私钥中包含的公共参数。使用此类型的参数可以调用[generateKeyPair](#generatekeypair-2)随机生成密钥对。 |
| PRIVATE_KEY_SPEC | 1 | 表示私钥中包含的参数。使用此类型的参数可以调用[generatePriKey](#generateprikey)生成指定的私钥。 |
| PUBLIC_KEY_SPEC | 2 | 表示公钥中包含的参数。使用此类型的参数可以调用[generatePubKey](#generatepubkey)生成指定的公钥。 |
| KEY_PAIR_SPEC | 3 | 表示公私钥中包含的全量参数。使用此类型的参数可以调用[generateKeyPair](#generatekeypair-2)生成指定的密钥对。 |

## CipherSpecItem<sup>10+</sup>

表示加解密参数的枚举，这些加解密参数支持通过[setCipherSpec](#setcipherspec10)接口设置/通过[getCipherSpec](#getcipherspec10)接口获取。

当前只支持RSA算法，详细规格请参考框架概述[加解密规格](../../security/cryptoFramework-overview.md#加解密规格)

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称         | 值   | 说明             |
| ------------ | ---- | ---------------- |
| OAEP_MD_NAME_STR | 100 | 表示RSA算法中，使用PKCS1_OAEP模式时，消息摘要功能的算法名。 |
| OAEP_MGF_NAME_STR | 101 | 表示RSA算法中，使用PKCS1_OAEP模式时，掩码生成算法（目前仅支持MGF1）。 |
| OAEP_MGF1_MD_STR | 102 | 表示RSA算法中，使用PKCS1_OAEP模式时，MGF1掩码生成功能的消息摘要算法。 |
| OAEP_MGF1_PSRC_UINT8ARR | 103 | 表示RSA算法中，使用PKCS1_OAEP模式时，pSource的字节流。 |

## SignSpecItem<sup>10+</sup>

表示签名验签参数的枚举，这些签名验签参数支持通过[setSignSpec](#setsignspec10)、[setVerifySpec](#setverifyspec10)接口设置/通过[getSignSpec](#getsignspec10)、[getVerifySpec](#getverifyspec10)接口获取。

当前只支持RSA算法，详细规格请参考框架概述[加解密规格](../../security/cryptoFramework-overview.md#加解密规格)

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称         | 值   | 说明             |
| ------------ | ---- | ---------------- |
| PSS_MD_NAME_STR | 100 | 表示RSA算法中，使用PSS模式时，消息摘要功能的算法名。 |
| PSS_MGF_NAME_STR | 101 | 表示RSA算法中，使用PSS模式时，掩码生成算法（目前仅支持MGF1）。 |
| PSS_MGF1_MD_STR | 102 | 表示RSA算法中，使用PSS模式时，MGF1掩码生成功能的消息摘要参数。 |
| PSS_SALT_LEN_NUM | 103 | 表示RSA算法中，使用PSS模式时，盐值的长度，长度以字节为单位。 |
| PSS_TRAILER_FIELD_NUM | 104 | 表示RSA算法中，使用PSS模式时，用于编码操作的整数，值为1。 |

## AsyKeySpec<sup>10+</sup>

指定非对称密钥参数的基本接口，用于创建密钥生成器。在指定非对称密钥参数时需要构造其子类对象，并将子类对象传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。构造子类对象时，所有bigint类型的密钥参数均采用大端写法，并使用正数。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 是   | 指定非对称密钥的算法名称，比如"RSA"、"DSA"、"ECC"。 |
| specType | [AsyKeySpecType](#asykeyspectype10) | 是   | 是 | 指定密钥参数类型，用于区分公/私钥参数。 |

## DSACommonParamsSpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定DSA算法中公私钥包含的公共参数，随机生成公/私钥。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| p | bigint | 是   | 是   | 指定DSA算法的素模数p。 |
| q | bigint | 是   | 是   | 指定DSA算法中密钥参数q（p-1的素因子）。 |
| g | bigint | 是   | 是   | 指定DSA算法的参数g。 |

## DSAPubKeySpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定DSA算法中公钥包含的参数。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [DSACommonParamsSpec](#dsacommonparamsspec10) | 是   | 是   | 指定DSA算法中公私钥都包含的公共参数。 |
| pk | bigint | 是   | 是   | 指定DSA算法的公钥。 |

## DSAKeyPairSpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定DSA算法中公私钥包含的全量参数。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [DSACommonParamsSpec](#dsacommonparamsspec10) | 是   | 是   | 指定DSA算法中公私钥都包含的公共参数。 |
| sk | bigint | 是   | 是   | 指定DSA算法的私钥sk。 |
| pk | bigint | 是   | 是   | 指定DSA算法的公钥pk。 |

## ECField<sup>10+</sup>

指定椭圆曲线的域。当前只支持Fp域。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| fieldType | string | 是   | 是   | 指定椭圆曲线域的类型，当前只支持"Fp"。 |

## ECFieldFp<sup>10+</sup>

指定椭圆曲线素数域。是[ECField](#ecfield10)的子类。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| p | bigint | 是   | 是   | 指定素数p。 |

## Point<sup>10+</sup>

指定椭圆曲线上的一个点。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x | bigint | 是   | 是   | 指定椭圆曲线上，点的x坐标。 |
| y | bigint | 是   | 是   | 指定椭圆曲线上，点的y坐标。 |

## ECCCommonParamsSpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定ECC算法中公私钥包含的公共参数，随机生成公/私钥。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| field | [ECField](#ecfield10) | 是   | 是   | 指定椭圆曲线的域（当前只支持Fp域）。 |
| a | bigint | 是   | 是   | 指定椭圆曲线的第一个系数a。 |
| b | bigint | 是   | 是   | 指定椭圆曲线的第二个系数b。 |
| g | [Point](#point10) | 是   | 是   | 指定基点g。 |
| n | bigint | 是   | 是   | 指定基点g的阶数n。 |
| h | number | 是   | 是   | 指定余因子h。 |

## ECCPriKeySpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定ECC算法中私钥包含的参数。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | 是   | 是   | 指定ECC算法中公私钥都包含的公共参数。 |
| sk | bigint | 是   | 是   | 指定ECC算法的私钥sk。 |

## ECCPubKeySpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定ECC算法中公钥包含的参数。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | 是   | 是   | 指定ECC算法中公私钥都包含的公共参数。 |
| pk | [Point](#point10) | 是   | 是   | 指定ECC算法的公钥pk。 |

## ECCKeyPairSpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定ECC算法中公私钥包含的全量参数。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | 是   | 是   | 指定ECC算法中公私钥都包含的公共参数。 |
| sk | bigint | 是   | 是   | 指定ECC算法的私钥sk。 |
| pk | [Point](#point10) | 是   | 是   | 指定ECC算法的公钥pk。 |

## RSACommonParamsSpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定RSA算法中公私钥包含的公共参数，随机生成公/私钥。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| n | bigint | 是   | 是   | 指定模数n。 |

## RSAPubKeySpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定RSA算法中公钥包含的参数。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [RSACommonParamsSpec](#rsacommonparamsspec10) | 是   | 是   | 指定RSA算法中公私钥都包含的公共参数。 |
| pk | bigint | 是   | 是   | 指定RSA算法的公钥pk。 |

## RSAKeyPairSpec<sup>10+</sup>

密钥参数[AsyKeySpec](#asykeyspec10)的子类，用于指定RSA算法中公私钥包含的全量参数。

在使用密钥参数生成密钥时，将其传入[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法创建密钥生成器。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [RSACommonParamsSpec](#rsacommonparamsspec10) | 是   | 是   | 指定RSA算法中公私钥都包含的公共参数。 |
| sk | bigint | 是   | 是   | 指定RSA算法的私钥sk。 |
| pk | bigint | 是   | 是   | 指定RSA算法的公钥pk。 |

## KdfSpec<sup>11+</sup>

密钥派生函数参数，使用密钥派生函数进行密钥派生时，需要构建其子类对象并作为输入。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 是   | 指明密钥派生函数的算法名，如"PBKDF2"。 |

## PBKDF2Spec<sup>11+</sup>

密钥派生函数参数[KdfSpec](#kdfspec11)的子类，作为PBKDF2密钥派生函数进行密钥派生时的输入。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| password | string \| Uint8Array | 是   | 是   | 用户输入的原始密码。|
| salt | Uint8Array | 是   | 是   | 盐值。 |
| iterations | number | 是   | 是   | 迭代次数，需要为正整数。 |
| keySize | number | 是   | 是   | 派生得到的密钥字节长度。 |

> **说明：**
>
> password指的是原始密码，如果使用string类型，需要直接传入用于密钥派生的数据，而不是HexString、base64等字符串类型，同时需要确保该字符串为utf-8编码，否则派生结果会有差异。

## Key

密钥（父类），在运行密码算法（如加解密）时需要提前生成其子类对象，并传入[Cipher](#cipher)实例的[init()](#init-2)方法。

密钥可以通过密钥生成器来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | 是   | 否   | 密钥的格式。                 |
| algName | string | 是   | 否   | 密钥对应的算法名（含长度）。 |

### getEncoded

getEncoded(): DataBlob

同步方法，获取密钥数据的字节流。密钥可以为对称密钥，公钥或者私钥。其中，公钥格式满足ASN.1语法、X.509规范、DER编码格式；私钥格式满足ASN.1语法，PKCS#8规范、DER编码方式。

> **说明：**
>
> RSA算法使用密钥参数生成私钥时，私钥对象不支持getEncoded。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 用于查看密钥的具体内容。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 801 | this operation is not supported. |
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**示例：**

```ts
let key: cryptoFramework.SymKey;    // The key is generated by a key generator. The generation process is omitted here.
let encodedKey = key.getEncoded();
console.info("key blob:" + encodedKey.data);
```

## SymKey

对称密钥，是[Key](#key)的子类，在对称加解密时需要将其对象传入[Cipher](#cipher)实例的[init()](#init-2)方法使用。

对称密钥可以通过对称密钥生成器[SymKeyGenerator](#symkeygenerator)来生成。

### clearMem

clearMem(): void

同步方法，将系统底层内存中的的密钥内容清零。建议在不再使用对称密钥实例时，调用本函数，避免内存中密钥数据存留过久。

**系统能力：** SystemCapability.Security.CryptoFramework

**示例：**

```ts
let key: cryptoFramework.SymKey;    // The key is generated by a symKeyGenerator. The generation process is omitted here.
let encodedKey = key.getEncoded();
console.info("key blob: "+ encodedKey.data);    // Display key content.
key.clearMem();
encodedKey = key.getEncoded();
console.info("key blob:" + encodedKey.data);    // Display all 0s.
```

## PubKey

公钥，是[Key](#key)的子类，在非对称加解密、验签、密钥协商时需要将其对象作为输入使用。

公钥可以通过非对称密钥生成器[AsyKeyGenerator](#asykeygenerator)、[AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10)来生成。

### getAsyKeySpec<sup>10+</sup>

getAsyKeySpec(itemType: AsyKeySpecItem): bigint | string | number

同步方法，获取密钥参数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| item  | [AsyKeySpecItem](#asykeyspecitem10) | 是   | 指定的密钥参数。 |

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| bigint\|string\|number | 用于查看密钥参数的具体内容。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters. |
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**示例：**

```ts
let key: cryptoFramework.PubKey; // key is a public key object. The generation process is omitted here.
let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
console.info("ecc item --- p: " + p.toString(16));
```

## PriKey

私钥，是[Key](#key)的子类，在非对称加解密、签名、密钥协商时需要将其作为输入使用。

私钥可以通过非对称密钥生成器[AsyKeyGenerator](#asykeygenerator)、[AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10)来生成。

### clearMem

clearMem(): void

同步方法，将系统底层内存中的的密钥内容清零。

**系统能力：** SystemCapability.Security.CryptoFramework

**示例：**

```ts
let key: cryptoFramework.PriKey; // The key is a private key generated by the asymmetric key generator. The generation process is omitted here.
key.clearMem(); // For the asymmetric private key, clearMem() releases the internal key struct. After clearMem is executed, getEncoded() is not supported.
```

### getAsyKeySpec<sup>10+</sup>

getAsyKeySpec(itemType: AsyKeySpecItem): bigint | string | number

同步方法，获取密钥参数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| item  | [AsyKeySpecItem](#asykeyspecitem10) | 是   | 指定的密钥参数类型。 |

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| bigint\|string\|number | 用于查看密钥参数的具体内容。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters. |
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**示例：**

```ts
let key: cryptoFramework.PriKey; // key is a private key object. The generation process is omitted here.
let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
console.info("ecc item --- p: " + p.toString(16));
```

## KeyPair

非对称密钥对，包含：公钥与私钥。

可以通过非对称密钥生成器[AsyKeyGenerator](#asykeygenerator)、[AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10)来生成。

> **说明：**
>
> KeyPair对象中的pubKey对象和priKey对象，作为KeyPair对象中的一个参数存在，当离开KeyPair对象作用域时，其内部对象可能被析构。
>
> 业务方使用时应持有KeyPair对象的引用，而非内部pubKey或priKey对象的引用。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明           |
| ------- | ------ | ---- | ---- | ------------ |
| priKey  | [PriKey](#prikey) | 是   | 否   | 私钥。      |
| pubKey | [PubKey](#pubkey) | 是   | 否   | 公钥。       |

## cryptoFramework.createSymKeyGenerator

createSymKeyGenerator(algName: string): SymKeyGenerator

通过指定算法名称的字符串，获取相应的对称密钥生成器实例。

支持的规格详见框架概述“[密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 待生成对称密钥生成器的算法名称。<br/>具体取值详见框架概述“[密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)”一节中的“字符串参数”。 |

**返回值：**

| 类型                                | 说明                       |
| ----------------------------------- | -------------------------- |
| [SymKeyGenerator](#symkeygenerator) | 返回对称密钥生成器的对象。 |

以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)
| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters. |
| 801 | this operation is not supported. |

**示例：**

```ts
let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
```

## SymKeyGenerator

对称密钥生成器。

在使用该类的方法前，需要先使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)方法构建一个symKeyGenerator实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                           |
| ------- | ------ | ---- | ---- | ------------------------------ |
| algName | string | 是   | 否   | 对称密钥生成器指定的算法名称。 |

### generateSymKey

generateSymKey(callback: AsyncCallback\<SymKey>): void

异步获取对称密钥生成器随机生成的密钥，通过注册回调函数获取结果。

必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。

目前支持使用OpenSSL的RAND_priv_bytes()作为底层能力生成随机密钥。

> **说明：**
>
> 对于HMAC算法的对称密钥，如果已经在创建对称密钥生成器时指定了具体哈希算法（如指定“HMAC|SHA256”），则会随机生成与哈希长度一致的二进制密钥数据（如指定“HMAC|SHA256”会随机生成256位的密钥数据）。<br/>如果在创建对称密钥生成器时没有指定具体哈希算法，如仅指定“HMAC”，则不支持随机生成对称密钥数据，可通过[convertKey](#convertkey)方式生成对称密钥数据。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SymKey](#symkey)> | 是   | 回调函数。当生成对称密钥成功，err为undefined，data为获取到的SymKey；否则为错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17620001 | memory error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let symAlgName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
symKeyGenerator.generateSymKey((err, symKey) => {
  if (err) {
    console.error(`Generate symKey failed, ${err.code}, ${err.message}`);
  } else {
    console.info(`Generate symKey success, algName: ${symKey.algName}`);
  }
})
```

### generateSymKey

generateSymKey(): Promise\<SymKey>

异步获取该对称密钥生成器随机生成的密钥，通过Promise获取结果。

必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。

目前支持使用OpenSSL的RAND_priv_bytes()作为底层能力生成随机密钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise对象，返回对称密钥SymKey。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17620001 | memory error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let symAlgName = 'AES128';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
symKeyGenerator.generateSymKey()
  .then(symKey => {
    console.info(`Generate symKey success, algName: ${symKey.algName}`);
  }, (error: BusinessError) => {
    console.error(`Generate symKey failed, ${error.code}, ${error.message}`);
  })
```

### convertKey

convertKey(key: DataBlob, callback: AsyncCallback\<SymKey>): void

异步根据指定数据生成对称密钥，通过注册回调函数获取结果。

必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。

> **说明：**
>
> 对于HMAC算法的对称密钥，如果已经在创建对称密钥生成器时指定了具体哈希算法（如指定“HMAC|SHA256”），则需要传入与哈希长度一致的二进制密钥数据（如传入SHA256对应256位的密钥数据）。<br/>如果在创建对称密钥生成器时没有指定具体哈希算法，如仅指定“HMAC”，则支持传入长度在[1,4096]范围内（单位为byte）的任意二进制密钥数据。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型          | 必填 | 说明                       |
| -------- | ------------------- | ---- | ---------------------|
| key      | [DataBlob](#datablob)             | 是   | 指定的对称密钥材料。                                         |
| callback | AsyncCallback\<[SymKey](#symkey)> | 是   | 回调函数。当生成对称密钥成功，err为undefined，data为获取到的SymKey；否则为错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                                               |
| -------- | --------------------------------------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.                                       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function genKeyMaterialBlob(): cryptoFramework.DataBlob {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return { data: keyMaterial };
}

let symAlgName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
let keyMaterialBlob = genKeyMaterialBlob();
symKeyGenerator.convertKey(keyMaterialBlob, (err, symKey) => {
  if (err) {
    console.error(`Convert symKey failed, ${err.code}, ${err.message}`);
  } else {
    console.info(`Convert symKey success, algName: ${symKey.algName}`);
  }
})
```

### convertKey

convertKey(key: DataBlob): Promise\<SymKey>

异步根据指定数据生成对称密钥，通过Promise获取结果。

必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| key  | [DataBlob](#datablob) | 是   | 指定的密钥材料数据。 |

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise对象，返回对称密钥SymKey。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                                          |
| -------- | --------------------------------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.                                |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function genKeyMaterialBlob(): cryptoFramework.DataBlob {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return { data: keyMaterial };
}

let symAlgName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
let keyMaterialBlob = genKeyMaterialBlob();
symKeyGenerator.convertKey(keyMaterialBlob)
  .then(symKey => {
    console.info(`Convert symKey success, algName: ${symKey.algName}`);
  }, (error: BusinessError) => {
    console.error(`Convert symKey failed, ${error.code}, ${error.message}`);
  })
```

## cryptoFramework.createAsyKeyGenerator

createAsyKeyGenerator(algName: string): AsyKeyGenerator

通过指定算法名称的字符串，获取相应的非对称密钥生成器实例。

支持的规格详见框架概述“[密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                             |
| ------- | ------ | ---- | -------------------------------- |
| algName | string | 是   | 待生成对称密钥生成器的算法名称。 |

**返回值：**

| 类型            | 说明                         |
| --------------- | ---------------------------- |
| [AsyKeyGenerator](#asykeygenerator) | 返回非对称密钥生成器的对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters. |
| 801 | this operation is not supported. |
| 17620001 | memory error. |

**示例：**

```ts
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
```

## AsyKeyGenerator

非对称密钥生成器。在使用该类的方法前，需要先使用createAsyKeyGenerator()方法构建一个AsyKeyGenerator实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                             |
| ------- | ------ | ---- | ---- | -------------------------------- |
| algName | string | 是   | 否   | 非对称密钥生成器指定的算法名称。 |

### generateKeyPair

generateKeyPair(callback: AsyncCallback\<KeyPair>): void

异步获取非对称密钥生成器随机生成的密钥，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                    | 必填 | 说明                           |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[KeyPair](#keypair)> | 是   | 回调函数，用于获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
asyKeyGenerator.generateKeyPair((err, keyPair) => {
  if (err) {
    console.error("generateKeyPair: error.");
    return;
  }
  console.info("generateKeyPair: success.");
})
```

### generateKeyPair

generateKeyPair(): Promise\<KeyPair>

异步获取该非对称密钥生成器随机生成的密钥，通过Promise获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | 使用Promise的方式获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
let keyGenPromise = asyKeyGenerator.generateKeyPair();
keyGenPromise.then( keyPair => {
  console.info("generateKeyPair success.");
}).catch((error: BusinessError) => {
  console.error("generateKeyPair error.");
});
```

### convertKey

convertKey(pubKey: DataBlob | null, priKey: DataBlob | null, callback: AsyncCallback\<KeyPair\>): void

异步获取指定数据生成非对称密钥，通过注册回调函数获取结果。详情请看下方**密钥转换说明**。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型       | 必填 | 说明                           |
| -------- | ----------- | ---- | ------------------------------ |
| pubKey   | [DataBlob](#datablob) \| null<sup>10+</sup>    | 是   | 指定的公钥材料。如果公钥不需要转换，可直接传入null。API 10之前只支持DataBlob， API 10之后增加支持null。        |
| priKey   | [DataBlob](#datablob) \| null<sup>10+</sup>   | 是   | 指定的私钥材料。如果私钥不需要转换，可直接传入null。API 10之前只支持DataBlob， API 10之后增加支持null。        |
| callback | AsyncCallback\<[KeyPair](#keypair)> | 是   | 回调函数，用于获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = {data: pubKeyArray}; // Data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = {data: priKeyArray}; // Data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
asyKeyGenerator.convertKey(pubKeyBlob, priKeyBlob, (err, keyPair) => {
  if (err) {
    console.error("convertKey: error.");
    return;
  }
  console.info("convertKey: success.");
})
```

### convertKey

convertKey(pubKey: DataBlob | null, priKey: DataBlob | null): Promise\<KeyPair>

异步获取指定数据生成非对称密钥，通过Promise获取结果。详情请看下方**密钥转换说明**。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型    | 必填 | 说明             |
| ------ | -------- | ---- | ---------------- |
| pubKey | [DataBlob](#datablob) \| null<sup>10+</sup> | 是   | 指定的公钥材料。如果公钥不需要转换，可直接传入null。API 10之前只支持DataBlob， API 10之后增加支持null。 |
| priKey | [DataBlob](#datablob) \| null<sup>10+</sup> | 是   | 指定的私钥材料。如果私钥不需要转换，可直接传入null。API 10之前只支持DataBlob， API 10之后增加支持null。 |

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | 使用Promise的方式获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = {data: pubKeyArray}; // Data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = {data: priKeyArray}; // Data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
let keyGenPromise = asyKeyGenerator.convertKey(pubKeyBlob, priKeyBlob);
keyGenPromise.then( keyPair => {
  console.info("convertKey success.");
}).catch((error: BusinessError) => {
  console.error("convertKey error.");
});
```

**密钥转换说明**

1. 非对称密钥（RSA、ECC、DSA）的公钥和私钥调用getEncoded()方法后，分别返回X.509格式和PKCS#8格式的二进制数据，此数据可用于跨应用传输或持久化存储。
2. 当调用convertKey方法将外来二进制数据转换为算法库非对称密钥对象时，公钥应满足ASN.1语法、X.509规范、DER编码格式，私钥应满足ASN.1语法、PKCS#8规范、DER编码格式。
3. convertKey方法中，公钥和密钥二进制数据非必选项，可单独传入公钥或私钥的数据，生成对应只包含公钥或私钥的KeyPair对象。

## cryptoFramework.createAsyKeyGeneratorBySpec<sup>10+</sup>

createAsyKeyGeneratorBySpec(asyKeySpec: AsyKeySpec): AsyKeyGeneratorBySpec

通过指定密钥参数，获取相应的非对称密钥生成器实例。

支持的规格详见框架概述“[密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                             |
| ------- | ------ | ---- | -------------------------------- |
| asyKeySpec | [AsyKeySpec](#asykeyspec10) | 是   | 密钥参数。非对称密钥生成器根据指定的这些参数生成公/私钥。 |

**返回值：**

| 类型                                            | 说明                       |
| ----------------------------------------------- | -------------------------- |
| [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10) | 返回非对称密钥生成器实例。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters. |
| 801 | this operation is not supported. |
| 17620001 | memory error. |

**示例：**

```ts
// Set the common parameters contained in both the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName : "DSA",
    specType : cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p : BigInt("0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729"),
    q : BigInt("0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b"),
    g : BigInt("0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd"),
  }
  return dsaCommonSpec;
}
// Set full parameters contained in the DSA1024 public and private keys.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName : "DSA",
    specType : cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params : dsaCommonSpec,
    sk : BigInt("0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9"),
    pk : BigInt("0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b"),
  }
  return dsaKeyPairSpec;
}

let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The JS input must be a positive number in big-endian format.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
```

## AsyKeyGeneratorBySpec<sup>10+</sup>

非对称密钥生成器。在使用该类的方法前，需要先使用[createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10)方法构建一个AsyKeyGeneratorBySpec实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                       |
| ------- | ------ | ---- | ---- | -------------------------- |
| algName | string | 是   | 否   | 非对称密钥生成器的算法名。 |

### generateKeyPair

generateKeyPair(callback: AsyncCallback\<KeyPair>): void

异步获取非对称密钥生成器生成的密钥，通过注册回调函数获取结果。

当使用[COMMON_PARAMS_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到随机生成的密钥对；当使用[KEY_PAIR_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到各项数据与密钥参数一致的密钥对。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                    | 必填 | 说明                           |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[KeyPair](#keypair)> | 是   | 回调函数，用于获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // dsa as example, asyKeyPairSpec specifies full parameters contained in the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
asyKeyGeneratorBySpec.generateKeyPair((err, keyPair) => {
  if (err) {
    console.error("generateKeyPair: error.");
    return;
  }
  console.info("generateKeyPair: success.");
})
```

### generateKeyPair

generateKeyPair(): Promise\<KeyPair>

异步获取该非对称密钥生成器生成的密钥，通过Promise获取结果。

当使用[COMMON_PARAMS_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到随机生成的密钥对；当使用[KEY_PAIR_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到各项数据与密钥参数一致的密钥对。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | 使用Promise的方式获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // dsa as example, asyKeyPairSpec specifies full parameters contained in the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
let keyGenPromise = asyKeyGeneratorBySpec.generateKeyPair();
keyGenPromise.then( keyPair => {
  console.info("generateKeyPair success.");
}).catch((error: BusinessError) => {
  console.error("generateKeyPair error.");
});
```

### generatePriKey

generatePriKey(callback: AsyncCallback\<PriKey>): void

异步获取非对称密钥生成器生成的密钥，通过注册回调函数获取结果。

当使用[PRIVATE_KEY_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到指定的私钥；当使用[KEY_PAIR_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以从生成的密钥对中获取指定的私钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                    | 必填 | 说明                           |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[PriKey](#prikey)> | 是   | 回调函数，用于获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // dsa as example, asyKeyPairSpec specifies full parameters contained in the private and public keys.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
asyKeyGeneratorBySpec.generatePriKey((err, prikey) => {
  if (err) {
    console.error("generatePriKey: error.");
    return;
  }
  console.info("generatePriKey: success.");
})
```

### generatePriKey

generatePriKey(): Promise\<PriKey>

异步获取该非对称密钥生成器生成的密钥，通过Promise获取结果。

当使用[PRIVATE_KEY_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到指定的私钥；当使用[KEY_PAIR_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以从生成的密钥对中获取指定的私钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise\<[PriKey](#prikey)> | 使用Promise的方式获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // dsa as example, asyKeyPairSpec specifies full parameters contained in the private and public keys.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
let keyGenPromise = asyKeyGeneratorBySpec.generatePriKey();
keyGenPromise.then( priKey => {
  console.info("generatePriKey success.");
}).catch((error: BusinessError) => {
  console.error("generatePriKey error.");
});
```

### generatePubKey

generatePubKey(callback: AsyncCallback\<PubKey>): void

异步获取非对称密钥生成器生成的密钥，通过注册回调函数获取结果。

当使用[PUBLIC_KEY_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到指定的公钥；当使用[KEY_PAIR_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以从生成的密钥对中获取指定的公钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                    | 必填 | 说明                           |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[PubKey](#pubkey)> | 是   | 回调函数，用于获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // dsa as example, asyKeyPairSpec specifies full parameters contained in the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
asyKeyGeneratorBySpec.generatePubKey((err, pubKey) => {
  if (err) {
    console.error("generatePubKey: error.");
    return;
  }
  console.info("generatePubKey: success.");
})
```

### generatePubKey

generatePubKey(): Promise\<PubKey>

异步获取该非对称密钥生成器生成的密钥，通过Promise获取结果。

当使用[PUBLIC_KEY_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以得到指定的公钥；当使用[KEY_PAIR_SPEC](#asykeyspectype10)类型的密钥参数来创建密钥生成器时，可以从生成的密钥对中获取指定的公钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise\<[PubKey](#pubkey)> | 使用Promise的方式获取非对称密钥。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // dsa as example, asyKeyPairSpec specifies full parameters contained in the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
let keyGenPromise = asyKeyGeneratorBySpec.generatePubKey();
keyGenPromise.then( pubKey => {
  console.info("generatePubKey success.");
}).catch((error: BusinessError) => {
  console.error("generatePubKey error.");
});
```

## cryptoFramework.createCipher

createCipher(transformation: string): Cipher

通过指定算法名称，获取相应的[Cipher](#cipher)实例。

支持的规格详见框架概述“[加解密规格](../../security/cryptoFramework-overview.md#加解密规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名         | 类型   | 必填 | 说明                                                         |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| transformation | string | 是   | 待生成Cipher的算法名称（含密钥长度）、加密模式以及填充方法的组合。<br/>具体取值详见框架概述“[加解密规格](../../security/cryptoFramework-overview.md#加解密规格)”一节中的“字符串参数”。 |

> **说明：**
>
> 1. 目前对称加解密中，PKCS5和PKCS7的实现相同，其padding长度和分组长度保持一致（即PKCS5和PKCS7在3DES中均按照8字节填充，在AES中均按照16字节填充），另有NoPadding表示不填充。
> <br/>开发者需要自行了解密码学不同分组模式的差异，以便选择合适的参数规格。例如选择ECB和CBC模式时，建议启用填充，否则必须确保明文长度是分组大小的整数倍；选择其他模式时，可以不启用填充，此时密文长度和明文长度一致（即可能不是分组大小的整数倍）。
> 2. 使用RSA、SM2进行非对称加解密时，必须创建两个Cipher对象分别进行加密和解密操作，而不能对同一个Cipher对象进行加解密。对称加解密没有此要求（即只要算法规格一样，可以对同一个Cipher对象进行加解密操作）。

**返回值：**

| 类型              | 说明                     |
| ----------------- | ------------------------ |
| [Cipher](#cipher) | 返回加解密生成器的对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported. |
| 17620001 | memory error.          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let cipherAlgName = '3DES192|ECB|PKCS7';
try {
  let cipher = cryptoFramework.createCipher(cipherAlgName);
  console.info(`cipher algName: ${cipher.algName}`);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Cipher

提供加解密的算法操作功能，按序调用本类中的[init()](#init-1)、[update()](#update)、[doFinal()](#dofinal)方法，可以实现对称加密/对称解密/非对称加密/非对称解密。

完整的加解密流程示例可参考开发指导中的“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”一节。

一次完整的加/解密流程在对称加密和非对称加密中略有不同：

- 对称加解密：init为必选，update为可选（且允许多次update加/解密大数据），doFinal为必选；doFinal结束后可以重新init开始新一轮加/解密流程。
- RSA、SM2非对称加解密：init为必选，不支持update操作，doFinal为必选（允许连续多次doFinal加/解密大数据）；RSA不支持重复init，切换加解密模式或填充方式时，需要重新创建Cipher对象。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | 是   | 否   | 加解密生成器指定的算法名称。 |

### init

init(opMode: CryptoMode, key: Key, params: ParamsSpec | null, callback: AsyncCallback\<void>): void

初始化加解密的[cipher](#cipher)对象，通过注册回调函数获取结果。

必须在使用[createCipher](#cryptoframeworkcreatecipher)创建[Cipher](#cipher)实例后，才能使用本函数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode   | [CryptoMode](#cryptomode) | 是   | 加密或者解密模式。                                           |
| key      | [Key](#key)               | 是   | 指定加密或解密的密钥。                                       |
| params   | [ParamsSpec](#paramsspec) \| null<sup>10+</sup> | 是   | 指定加密或解密的参数，对于ECB等没有参数的算法模式，可以传入null。API 10之前只支持ParamsSpec， API 10之后增加支持null。 |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当加解密初始化成功，err为undefined，否则为错误对象。     |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                                                 |
| -------- | --------------------------------------------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.                                            |
| 17620002 | runtime error.                                           |
| 17630001 | crypto operation error.|

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let symKey: cryptoFramework.SymKey;     // The process of generating the symmetric key is omitted here.
let cipher: cryptoFramework.Cipher;        // The process of creating a Cipher instance is omitted here.

cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null, (err, ) => {
  if (err) {
    console.error(`Failed to init cipher, ${err.code}, ${err.message}`);
  } else {
    console.info(`Init cipher success`);
    // Perform subsequent operations such as update.
  }
})
```

### init

init(opMode: CryptoMode, key: Key, params: ParamsSpec | null): Promise\<void>

初始化加解密的cipher对象，通过Promise获取结果。

必须在使用[createCipher](#cryptoframeworkcreatecipher)创建[Cipher](#cipher)实例后，才能使用本函数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode | [CryptoMode](#cryptomode) | 是   | 加密或者解密模式。                                           |
| key    | [Key](#key)               | 是   | 指定加密或解密的密钥。                                       |
| params | [ParamsSpec](#paramsspec) \| null<sup>10+</sup> | 是   | 指定加密或解密的参数，对于ECB等没有参数的算法模式，可以传入null。API 10之前只支持ParamsSpec， API 10之后增加支持null。 |

**返回值：**

| 类型           | 说明                                   |
| -------------- | -------------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.                                     |
| 17620002 | runtime error.                                    |
| 17630001 | crypto operation error.|

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let symKey: cryptoFramework.SymKey;     // The process of generating the symmetric key is omitted here.
let cipher: cryptoFramework.Cipher;        // The process of creating a Cipher instance is omitted here.
cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null)
  .then(() => {
    console.info(`Init cipher success`);
    // Perform subsequent operations such as update.
  }, (error: BusinessError) => {
    console.error(`Failed to init cipher, ${error.code}, ${error.message}`);
  })
```

### update

update(data: DataBlob, callback: AsyncCallback\<DataBlob>): void

分段更新加密或者解密数据操作，通过注册回调函数获取加/解密数据。

必须在对[Cipher](#cipher)实例使用[init()](init-1)初始化后，才能使用本函数。

> **说明：**
>
> 1. 在进行对称加解密操作的时候，如果开发者对各个分组模式不够熟悉，建议对每次update和doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。这是因为选择的分组模式等各项规格都可能对update和doFinal结果产生影响。<br/>（例如对于ECB和CBC模式，不论update传入的数据是否为分组长度的整数倍，都会以分组作为基本单位进行加/解密，并输出本次update新产生的加/解密分组结果。<br/>可以理解为，update只要凑满一个新的分组就会有输出，如果没有凑满则此次update输出为null，把当前还没被加/解密的数据留着，等下一次update/doFinal传入数据的时候，拼接起来继续凑分组。<br/>最后doFinal的时候，会把剩下的还没加/解密的数据，根据[createCipher](#cryptoframeworkcreatecipher)时设置的padding模式进行填充，补齐到分组的整数倍长度，再输出剩余加解密结果。<br/>而对于可以将分组密码转化为流模式实现的模式，还可能出现密文长度和明文长度相同的情况等。）
> 2. 根据数据量，可以不调用update（即init完成后直接调用doFinal）或多次调用update。<br/>
>    算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的对称加解密，采用多次update的方式传入数据。<br/>
>    AES使用多次update操作的示例代码详见开发指导“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”。
> 3. RSA、SM2非对称加解密不支持update操作。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | 是   | 加密或者解密的数据。data不能为null，也不允许传入{data: Uint8Array(空) }。           |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数。当更新加/解密数据成功，err为undefined，data为此次更新的加/解密结果DataBlob；否则为错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.                               |
| 17620002 | runtime error.                              |
| 17630001 | crypto operation error.                     |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let cipher: cryptoFramework.Cipher;        // The process of creating a Cipher instance is omitted here.
// The init() process is omitted here.
let plainText: cryptoFramework.DataBlob = {data: stringToUint8Array('this is test!')};
cipher.update(plainText, (err, output) => {       // Example of the encryption process.
  if (err) {
    console.error(`Failed to update cipher`);
  } else {
    console.info(`Update cipher success`);
    if (output != null) {
      // Concatenate output.data to the ciphertext.
    }
    // Perform subsequent operations such as doFinal().
  }
})
```

### update

update(data: DataBlob): Promise\<DataBlob>

分段更新加密或者解密数据操作，通过Promise获取加/解密数据。

必须在对[Cipher](#cipher)实例使用[init()](init-2)初始化后，才能使用本函数。

> **说明：**
>
> 1. 在进行对称加解密操作的时候，如果开发者对各个分组模式不够熟悉，建议对每次update和doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。这是因为选择的分组模式等各项规格都可能对update和doFinal结果产生影响。
> <br/>（例如对于ECB和CBC模式，不论update传入的数据是否为分组长度的整数倍，都会以分组作为基本单位进行加/解密，并输出本次update新产生的加/解密分组结果。<br/>可以理解为，update只要凑满一个新的分组就会有输出，如果没有凑满则此次update输出为null，把当前还没被加/解密的数据留着，等下一次update/doFinal传入数据的时候，拼接起来继续凑分组。<br/>最后doFinal的时候，会把剩下的还没加/解密的数据，根据[createCipher](#cryptoframeworkcreatecipher)时设置的padding模式进行填充，补齐到分组的整数倍长度，再输出剩余加解密结果。<br/>而对于可以将分组密码转化为流模式实现的模式，还可能出现密文长度和明文长度相同的情况等。）
> 2. 根据数据量，可以不调用update（即init完成后直接调用doFinal）或多次调用update。<br/>
>    算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的对称加解密，可以采用多次update的方式传入数据。<br/>
>    AES使用多次update操作的示例代码详见开发指导“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”。
> 3. RSA、SM2非对称加解密不支持update操作。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | 是   | 加密或者解密的数据。data不能为null，也不允许传入{data: Uint8Array(空) }。 |

**返回值：**

| 类型                            | 说明                                             |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise对象，返回此次更新的加/解密结果DataBlob。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let cipher: cryptoFramework.Cipher;        // The process of creating a Cipher instance is omitted here.
// The init() process is omitted here.
let plainText: cryptoFramework.DataBlob = {data: stringToUint8Array('this is test!')};
cipher.update(plainText)
  .then((output) => {
    console.info(`Update cipher success.`);
    if (output != null) {
      // Concatenate output.data to the ciphertext.
    }
    // Perform subsequent operations such as doFinal().
  }, (error: BusinessError) => {
    console.info(`Update cipher failed.`);
  })
```

### doFinal

doFinal(data: DataBlob | null, callback: AsyncCallback\<DataBlob>): void

（1）在对称加解密中，doFinal加/解密（分组模式产生的）剩余数据和本次传入的数据，最后结束加密或者解密数据操作，通过注册回调函数获取加密或者解密数据。<br/>如果数据量较小，可以在doFinal中一次性传入数据，而不使用update；如果在本次加解密流程中，已经使用[update](#update-4)传入过数据，可以在doFinal的data参数处传入null。<br/>根据对称加解密的模式不同，doFinal的输出有如下区别：

- 对于GCM和CCM模式的对称加密：一次加密流程中，如果将每一次update和doFinal的结果拼接起来，会得到“密文+authTag”，即末尾的16字节（GCM模式）或12字节（CCM模式）是authTag，而其余部分均为密文。（也就是说，如果doFinal的data参数传入null，则doFinal的结果就是authTag）<br/>authTag需要填入解密时的[GcmParamsSpec](#gcmparamsspec)或[CcmParamsSpec](#ccmparamsspec)；密文则作为解密时的入参data。
- 对于其他模式的对称加解密、GCM和CCM模式的对称解密：一次加/解密流程中，每一次update和doFinal的结果拼接起来，得到完整的明文/密文。

（2）在RSA、SM2非对称加解密中，doFinal加/解密本次传入的数据，通过注册回调函数获取加密或者解密数据。如果数据量较大，可以多次调用doFinal，拼接结果得到完整的明文/密文。

> **说明：**
>
>  1. 对称加解密中，调用doFinal标志着一次加解密流程已经完成，即[Cipher](#cipher)实例的状态被清除，因此当后续开启新一轮加解密流程时，需要重新调用init()并传入完整的参数列表进行初始化<br/>（比如即使是对同一个Cipher实例，采用同样的对称密钥，进行加密然后解密，则解密中调用init的时候仍需填写params参数，而不能直接省略为null）。
>  2. 如果遇到解密失败，需检查加解密数据和init时的参数是否匹配，包括GCM模式下加密得到的authTag是否填入解密时的GcmParamsSpec等。
>  3. doFinal的结果可能为null，因此使用.data字段访问doFinal结果的具体数据前，请记得先判断结果是否为null，避免产生异常。
>  4. RSA、SM2非对称加解密时多次doFinal操作的示例代码详见开发指导“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob) \| null<sup>10+</sup>                 | 是   | 加密或者解密的数据。在对称加解密中允许为null，但不允许传入{data: Uint8Array(空) }。API 10之前只支持DataBlob， API 10之后增加支持null。       |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数。当最终加/解密数据成功，err为undefined，data为剩余数据的加/解密结果DataBlob；否则为错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.           |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let cipher: cryptoFramework.Cipher;        // The process of creating a Cipher instance is omitted here.
let data: cryptoFramework.DataBlob;           // The process of preparing the data to encrypt or decrypt is omitted here.
// The init() and update() processes are omitted here.
cipher.doFinal(data, (err, output) => {
  if (err) {
    console.error(`Failed to finalize cipher, ${err.code}, ${err.message}`);
  } else {
    console.info(`Finalize cipher success`);
    if (output != null) {
      // Concatenate output.data to obtain the complete plaintext/ciphertext (and authTag).
    }
  }
})
```

### doFinal

doFinal(data: DataBlob | null): Promise\<DataBlob>

（1）在对称加解密中，doFinal加/解密（分组模式产生的）剩余数据和本次传入的数据，最后结束加密或者解密数据操作，通过Promise获取加密或者解密数据。<br/>如果数据量较小，可以在doFinal中一次性传入数据，而不使用update；如果在本次加解密流程中，已经使用update传入过数据，可以在doFinal的data参数处传入null。<br/>根据对称加解密的模式不同，doFinal的输出有如下区别：

- 对于GCM和CCM模式的对称加密：一次加密流程中，如果将每一次update和doFinal的结果拼接起来，会得到“密文+authTag”，即末尾的16字节（GCM模式）或12字节（CCM模式）是authTag，而其余部分均为密文。（也就是说，如果doFinal的data参数传入null，则doFinal的结果就是authTag）<br/>authTag需要填入解密时的[GcmParamsSpec](#gcmparamsspec)或[CcmParamsSpec](#ccmparamsspec)；密文则作为解密时的入参data。
- 对于其他模式的对称加解密、GCM和CCM模式的对称解密：一次加/解密流程中，每一次update和doFinal的结果拼接起来，得到完整的明文/密文。

（2）在RSA、SM2非对称加解密中，doFinal加/解密本次传入的数据，通过Promise获取加密或者解密数据。如果数据量较大，可以多次调用doFinal，拼接结果得到完整的明文/密文。

> **说明：**
>
>  1. 对称加解密中，调用doFinal标志着一次加解密流程已经完成，即[Cipher](#cipher)实例的状态被清除，因此当后续开启新一轮加解密流程时，需要重新调用init()并传入完整的参数列表进行初始化<br/>（比如即使是对同一个Cipher实例，采用同样的对称密钥，进行加密然后解密，则解密中调用init的时候仍需填写params参数，而不能直接省略为null）。
>  2. 如果遇到解密失败，需检查加解密数据和init时的参数是否匹配，包括GCM模式下加密得到的authTag是否填入解密时的GcmParamsSpec等。
>  3. doFinal的结果可能为null，因此使用.data字段访问doFinal结果的具体数据前，请记得先判断结果是否为null，避免产生异常。
>  4. RSA、SM2非对称加解密时多次doFinal操作的示例代码详见开发指导“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) \| null<sup>10+</sup> | 是   | 加密或者解密的数据。data参数允许为null，但不允许传入{data: Uint8Array(空) }。API 10之前只支持DataBlob， API 10之后增加支持null。 |

**返回值：**

| 类型                            | 说明                                             |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise对象，返回剩余数据的加/解密结果DataBlob。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let cipher: cryptoFramework.Cipher;        // The process of creating a Cipher instance is omitted here.
let data: cryptoFramework.DataBlob;           // The process of preparing the data to encrypt or decrypt is omitted here.
// The init() and update() processes are omitted here.
cipher.doFinal(data)
  .then(output => {
    console.info(`Finalize cipher success`);
    if (output != null) {
      // Concatenate output.data to obtain the complete plaintext/ciphertext (and authTag).
    }
  }, (error: BusinessError) => {
    console.error(`Failed to finalize cipher, ${error.code}, ${error.message}`);
  })
```

**使用RSA加密的callback完整示例：**

```ts
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
rsaGenerator.generateKeyPair((err, keyPair) => {
  let pubKey = keyPair.pubKey;
  cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, (err, data) => {
    let plainText = "this is cipher text";
    let input: cryptoFramework.DataBlob = {data: stringToUint8Array(plainText) };
    cipher.doFinal(input, (err, data) => {
      AlertDialog.show({ message: "EncryptOutPut is " + data.data} );
    });
  });
});
```

**使用RSA加密的Promise完整示例：**

```ts
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
let keyGenPromise = rsaGenerator.generateKeyPair();
keyGenPromise.then((rsaKeyPair: cryptoFramework.KeyPair): Promise<void> => {
  let pubKey = rsaKeyPair.pubKey;
  return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null); // Pass in the private key and DECRYPT_MODE to initialize the decryption mode.
}).then(() => {
  let plainText = "this is cipher text";
  let input: cryptoFramework.DataBlob = { data: stringToUint8Array(plainText) };
  return cipher.doFinal(input);
}).then(dataBlob => {
  console.info("EncryptOutPut is " + dataBlob.data);
});
```

> **说明：**
>
> 更多加解密流程的完整示例可参考开发指导中的“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”一节。

### setCipherSpec<sup>10+</sup>

setCipherSpec(itemType: CipherSpecItem, itemValue: Uint8Array): void

设置加解密参数。常用的加解密参数可以直接通过[createCipher](#cryptoframeworkcreatecipher) 来指定，剩余参数可以通过本接口指定。当前只支持RSA算法。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [CipherSpecItem](#cipherspecitem10)           | 是   | 用于指定需要设置的加解密参数。 |
| itemValue | Uint8Array | 是   | 用于指定加解密参数的具体值。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
let cipher: cryptoFramework.Cipher; // The process of generating the Cipher instance is omitted here.
let pSource = new Uint8Array([1,2,3,4]);
cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
```

### getCipherSpec<sup>10+</sup>

getCipherSpec(itemType: CipherSpecItem): string | Uint8Array

获取加解密参数。当前只支持RSA算法。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| itemType   | [CipherSpecItem](#cipherspecitem10) | 是   | 用于指定需要获取的加解密参数。 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| string\|Uint8Array | 获取的加解密参数的具体值。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
let cipher: cryptoFramework.Cipher; // The process of generating the Cipher instance is omitted here.
let mdName = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
```

## cryptoFramework.createSign

createSign(algName: string): Sign

Sign实例生成。

支持的规格详见框架概述“[签名验签规格](../../security/cryptoFramework-overview.md#签名验签规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定签名算法：RSA，ECC，DSA或SM2<sup>10+</sup>。使用RSA PKCS1模式时需要设置摘要，使用RSA PSS模式时需要设置摘要和掩码摘要。 |

**返回值**：

| 类型 | 说明                               |
| ---- | ---------------------------------- |
| Sign | 返回由输入算法指定生成的Sign对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

**示例：**

```ts
let signer1 = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");

let signer2 = cryptoFramework.createSign("RSA1024|PSS|SHA256|MGF1_SHA256");

let signer3 = cryptoFramework.createSign("ECC224|SHA256");

let signer4 = cryptoFramework.createSign("DSA2048|SHA256");
```

## Sign

Sign类，使用Sign方法之前需要创建该类的实例进行操作，通过[createSign(algName: string): Sign](#cryptoframeworkcreatesign)方法构造此实例。按序调用本类中的init、update、sign方法完成签名操作。签名操作的示例代码详见开发指导“[使用签名验签操作](../../security/cryptoFramework-guidelines.md#使用签名验签操作)”。

Sign类不支持重复初始化，当业务方需要使用新密钥签名时，需要重新创建新Sign对象并调用init初始化。

业务方使用时，在createSign时确定签名的模式，调用init接口设置密钥。

当待签名数据较短时，可在init初始化后，（无需update）直接调用sign接口传入原文数据进行签名。

当待签名数据较长时，可通过update接口分段传入切分后的原文数据，最后调用sign接口对整体原文数据进行签名。

当使用update分段传入原文时，sign接口API 10之前只支持传入DataBlob， API 10之后增加支持null。业务方可在循环中调用update接口，循环结束后调用sign进行签名。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | 是   | 否   | 签名指定的算法名称。 |

### init

init(priKey: PriKey, callback: AsyncCallback\<void>): void

使用私钥初始化Sign对象，通过注册回调函数获取结果。

Sign类暂不支持重复init。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| priKey   | [PriKey](#prikey)    | 是   | 用于Sign的初始化。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当签名初始化成功，err为undefined，否则为错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### init

init(priKey: PriKey): Promise\<void>

使用私钥初始化Sign对象，通过Promise获取结果。

Sign类暂不支持重复init。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| priKey | [PriKey](#prikey)  | 是   | 用于Sign的初始化。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob, callback: AsyncCallback\<void>): void

追加待签名数据，通过注册回调函数完成更新。

必须在对[Sign](#sign)实例使用[init()](#init-2)初始化后，才能使用本函数。

> **说明：**
>
> 根据数据量，可以不调用update（即[init](#init-2)完成后直接调用[sign](#sign-1)）或多次调用update。<br/>
> 算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的签名操作，采用多次update的方式传入数据，避免一次性申请过大内存。<br/>
> 签名使用多次update操作的示例代码详见开发指导“[使用签名验签操作](../../security/cryptoFramework-guidelines.md#使用签名验签操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明         |
| -------- | --------------------- | ---- | ------------ |
| data     | [DataBlob](#datablob) | 是   | 传入的消息。 |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当签名更新成功，err为undefined，否则为错误对象。|

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob): Promise\<void>

追加待签名数据，通过Promise方式完成更新。

必须在对[Sign](#sign)实例使用[init()](#init-3)初始化后，才能使用本函数。

> **说明：**
>
> 根据数据量，可以不调用update（即[init](#init-3)完成后直接调用[sign](#sign-2)）或多次调用update。<br/>
> 算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的签名操作，采用多次update的方式传入数据，避免一次性申请过大内存。<br/>
> 签名使用多次update操作的示例代码详见开发指导“[使用签名验签操作](../../security/cryptoFramework-guidelines.md#使用签名验签操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | 是   | 传入的消息。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### sign

sign(data: DataBlob | null, callback: AsyncCallback\<DataBlob>): void

对数据进行签名，通过注册回调函数获取签名结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| data     | [DataBlob](#datablob) \| null<sup>10+</sup>              | 是   | 传入的消息。API 10之前只支持DataBlob， API 10之后增加支持null。 |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取DataBlob数据。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### sign

sign(data: DataBlob | null): Promise\<DataBlob>

对数据进行签名，通过Promise方式返回签名结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob) \| null<sup>10+</sup>  | 是   | 传入的消息。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**callback示例：**

```ts
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let globalKeyPair: cryptoFramework.KeyPair;
let signMessageBlob: cryptoFramework.DataBlob;
let plan1 = "This is Sign test plan1"; // The first segment of the data.
let plan2 = "This is Sign test plan2"; // The second segment of the data.
let input1: cryptoFramework.DataBlob = { data: stringToUint8Array(plan1) };
let input2: cryptoFramework.DataBlob = { data: stringToUint8Array(plan2) };

function signMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");
  rsaGenerator.generateKeyPair((err, keyPair) => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, err => {
      signer.update(input1, err => { // add first segment of data
        signer.sign(input2, (err, data) => { // add second segment of data, sign input1 and input2
          signMessageBlob = data;
          AlertDialog.show({message: "res" +  signMessageBlob.data});
        });
      });
    });
  });
}
```

**Promise示例：**

```ts
function stringToUint8Array(str: string) {
  let arr = new Uint8Array(str.length);
  for (let i = 0, j = str.length; i < j; ++i) {
    arr[i] = str.charCodeAt(i);
  }
  return arr;
}

let globalKeyPair: cryptoFramework.KeyPair;
let signMessageBlob: cryptoFramework.DataBlob;
let plan1 = "This is Sign test plan1"; // The first segment of the data.
let plan2 = "This is Sign test plan2"; // The second segment of the data.
let input1: cryptoFramework.DataBlob = { data: stringToUint8Array(plan1) };
let input2: cryptoFramework.DataBlob = { data: stringToUint8Array(plan2) };

function signMessagePromise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256"); // From API version 10, a Sign instance can be created by specifying a string parameter defining the key specifications.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    return signer.init(priKey);
  }).then(() => {
    return signer.update(input1);
  }).then(() => {
    return signer.sign(input2);
  }).then(dataBlob => {
    signMessageBlob = dataBlob;
    console.info("sign output is " + signMessageBlob.data);
  });
}
```

### setSignSpec<sup>10+</sup>

setSignSpec(itemType: SignSpecItem, itemValue: number): void

设置签名参数。常用的签名参数可以直接通过[createSign](#cryptoframeworkcreatesign) 来指定，剩余参数可以通过本接口指定。

当前只支持RSA算法。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | 是   | 用于指定需要设置的签名参数。 |
| itemValue | number | 是   | 用于指定签名参数的具体值。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
let signer: cryptoFramework.Sign; // The process of generating the Sign instance is omitted here.
let setN = 20;
signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
```

### getSignSpec<sup>10+</sup>

getSignSpec(itemType: SignSpecItem): string | number

获取签名参数。当前只支持RSA算法。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| itemType | [SignSpecItem](#signspecitem10)  | 是   | 用于指定需要获取的签名参数。 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| string\|number | 获取的签名参数的具体值。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
let signer: cryptoFramework.Sign; // The process of generating the Sign instance is omitted here.
let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
```

## cryptoFramework.createVerify

createVerify(algName: string): Verify

Verify实例生成。

支持的规格详见框架概述“[签名验签规格](../../security/cryptoFramework-overview.md#签名验签规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定签名算法：RSA，ECC，DSA或SM2<sup>10+</sup>，。使用RSA PKCS1模式时需要设置摘要，使用RSA PSS模式时需要设置摘要和掩码摘要。 |

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| Verify | 返回由输入算法指定生成的Verify对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

**示例：**

```ts
let verifyer1 = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");

let verifyer2 = cryptoFramework.createVerify("RSA1024|PSS|SHA256|MGF1_SHA256")
```

## Verify

Verify类，使用Verify方法之前需要创建该类的实例进行操作，通过[createVerify(algName: string): Verify](#cryptoframeworkcreateverify)方法构造此实例。按序调用本类中的init、update、verify方法完成签名操作。验签操作的示例代码详见开发指导“[使用签名验签操作](../../security/cryptoFramework-guidelines.md#使用签名验签操作)”。

Verify类不支持重复初始化，当业务方需要使用新密钥验签时，需要重新创建新Verify对象并调用init初始化。

业务方使用时，在createVerify时确定验签的模式，调用init接口设置密钥。

当被签名的消息较短时，可在init初始化后，（无需update）直接调用verify接口传入被签名的消息和签名(signatureData)进行验签。

当被签名的消息较长时，可通过update接口分段传入被签名的消息，最后调用verify接口对消息全文进行验签。verify接口的data入参在API 10之前只支持DataBlob， API 10之后增加支持null。业务方可在循环中调用update接口，循环结束后调用verify传入签名(signatureData)进行验签。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | 是   | 否   | 验签指定的算法名称。 |

### init

init(pubKey: PubKey, callback: AsyncCallback\<void>): void

传入公钥初始化Verify对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| pubKey   | [PubKey](#pubkey)    | 是   | 公钥对象，用于Verify的初始化。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当验签初始化成功，err为undefined，否则为错误对象。  |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### init

init(pubKey: PubKey): Promise\<void>

传入公钥初始化Verify对象，通过Promise获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ------ | ---- | ---- | ---------------------------- |
| pubKey | [PubKey](#pubkey)  | 是   | 公钥对象，用于Verify的初始化。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob, callback: AsyncCallback\<void>): void

追加待验签数据，通过注册回调函数完成更新。

必须在对[Verify](#verify)实例使用[init()](#init-4)初始化后，才能使用本函数。

> **说明：**
>
> 根据数据量，可以不调用update（即[init](#init-4)完成后直接调用[verify](#verify-1)）或多次调用update。<br/>
> 算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的验签操作，采用多次update的方式传入数据，避免一次性申请过大内存。<br/>
> 验签使用多次update操作的示例代码详见开发指导“[使用签名验签操作](../../security/cryptoFramework-guidelines.md#使用签名验签操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明         |
| -------- | --------------------- | ---- | ------------ |
| data     | [DataBlob](#datablob) | 是   | 传入的消息。 |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当验签更新成功，err为undefined，否则为错误对象。|

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob): Promise\<void>

追加待验签数据，通过Promise方式完成更新。

必须在对[Verify](#verify)实例使用[init()](#init-5)初始化后，才能使用本函数。

> **说明：**
>
> 根据数据量，可以不调用update（即[init](#init-5)完成后直接调用[verify](#verify-2)）或多次调用update。<br/>
> 算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的验签操作，采用多次update的方式传入数据，避免一次性申请过大内存。<br/>
> 验签使用多次update操作的示例代码详见开发指导“[使用签名验签操作](../../security/cryptoFramework-guidelines.md#使用签名验签操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | 是   | 传入的消息。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### verify

verify(data: DataBlob | null, signatureData: DataBlob, callback: AsyncCallback\<boolean>): void

对数据进行验签，通过注册回调函数返回返回验签结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名        | 类型                 | 必填 | 说明       |
| ------------- | -------------------- | ---- | ---------- |
| data          | [DataBlob](#datablob) \| null<sup>10+</sup>             | 是   | 传入的消息。API 10之前只支持DataBlob， API 10之后增加支持null。 |
| signatureData | [DataBlob](#datablob)              | 是   | 签名数据。  |
| callback      | AsyncCallback\<boolean> | 是   | 回调函数，用于获取以boolean值表示的验签结果。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### verify

verify(data: DataBlob | null, signatureData: DataBlob): Promise\<boolean>

对数据进行验签，通过Promise返回验签结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名        | 类型     | 必填 | 说明       |
| ------------- | -------- | ---- | ---------- |
| data          | [DataBlob](#datablob) \| null<sup>10+</sup>  | 是   | 传入的消息。API 10之前只支持DataBlob， API 10之后增加支持null。 |
| signatureData | [DataBlob](#datablob)  | 是   | 签名数据。  |

**返回值：**

| 类型              | 说明                           |
| ----------------- | ------------------------------ |
| Promise\<boolean> | 异步返回值，代表验签是否通过。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**callback示例：**

```ts
let globalKeyPair: cryptoFramework.KeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let input1: cryptoFramework.DataBlob;
let input2: cryptoFramework.DataBlob;
let signMessageBlob: cryptoFramework.DataBlob;// Signed data, which is omitted here.
let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
verifyer.init(globalKeyPair.pubKey, (err, data) => {
  verifyer.update(input1, (err, data) => {
    verifyer.verify(input2, signMessageBlob, (err, data) => {
      console.info("verify result is " + data);
    })
  });
})
```

**Promise示例：**

```ts
let globalKeyPair: cryptoFramework.KeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
let input1: cryptoFramework.DataBlob;;
let input2: cryptoFramework.DataBlob;;
let signMessageBlob: cryptoFramework.DataBlob;; // Signed data, which is omitted here.
verifyInitPromise.then((): Promise<void> => {
  return verifyer.update(input1);
}).then(() => {
  return verifyer.verify(input2, signMessageBlob);
}).then(res => {
  console.log("Verify result is " + res);
});
```

### setVerifySpec<sup>10+</sup>

setVerifySpec(itemType: SignSpecItem, itemValue: number): void

设置验签参数。常用的签名参数可以直接通过[createVerify](#cryptoframeworkcreateverify) 来指定，剩余参数可以通过本接口指定。当前只支持RSA算法。

验签的参数应当与签名的参数保持一致。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | 是   | 用于指定需要设置的验签参数。 |
| itemValue | number | 是   | 用于指定验签参数的具体值。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
let verifyer: cryptoFramework.Verify; //The process of generating the Verify instance is omitted here.
let setN = 20;
verifyer.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
```

### getVerifySpec<sup>10+</sup>

getVerifySpec(itemType: SignSpecItem): string | number

获取验签参数。当前只支持RSA算法。

验签的参数应当与签名的参数保持一致。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| itemType   | [SignSpecItem](#signspecitem10)  | 是   | 用于指定需要获取的验签参数。 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| string\|number | 获取的验签参数的具体值。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
let verifyer: cryptoFramework.Verify; //The process of generating the Verify instance is omitted here.
let saltLen = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
```

## cryptoFramework.createKeyAgreement

createKeyAgreement(algName: string): KeyAgreement

KeyAgreement实例生成。

支持的规格详见框架概述“[密钥协商规格](../../security/cryptoFramework-overview.md#密钥协商规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                              |
| ------- | ------ | ---- | --------------------------------- |
| algName | string | 是   | 指定密钥协商算法：目前仅支持ECC。 |

**返回值**：

| 类型         | 说明                                       |
| ------------ | ------------------------------------------ |
| KeyAgreement | 返回由输入算法指定生成的KeyAgreement对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

**示例：**

```ts
let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");

```

## KeyAgreement

KeyAgreement类，使用密钥协商方法之前需要创建该类的实例进行操作，通过[createKeyAgreement(algName: string): KeyAgreement](#cryptoframeworkcreatekeyagreement)方法构造此实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | 是   | 否   | 密钥协商指定的算法名称。 |

### generateSecret

generateSecret(priKey: PriKey, pubKey: PubKey, callback: AsyncCallback\<DataBlob>): void

基于传入的私钥与公钥进行密钥协商，通过注册回调函数返回共享秘密。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                   |
| -------- | ------------------------ | ---- | ---------------------- |
| priKey   | [PriKey](#prikey)        | 是   | 设置密钥协商的私钥输入。 |
| pubKey   | [PubKey](#pubkey)        | 是   | 设置密钥协商的公钥输入。 |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 异步接受共享秘密的回调。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### generateSecret

generateSecret(priKey: PriKey, pubKey: PubKey): Promise\<DataBlob>

基于传入的私钥与公钥进行密钥协商，通过Promise返回共享秘密。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| priKey | [PriKey](#prikey) | 是   | 设置密钥协商的私钥输入。 |
| pubKey | [PubKey](#pubkey) | 是   | 设置密钥协商的公钥输入。 |

**返回值：**

| 类型               | 说明     |
| ------------------ | -------- |
| Promise\<[DataBlob](#datablob)> | 共享秘密。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**callback示例：**

```ts
import { BusinessError } from '@ohos.base';

let globalKeyPair: cryptoFramework.KeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");
keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey, (err, secret) => {
  if (err) {
    console.error("keyAgreement error.");
    return;
  }
  console.info("keyAgreement output is " + secret.data);
});
```

**Promise示例：**

```ts
import { BusinessError } from '@ohos.base';

let globalKeyPair: cryptoFramework.KeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");
let keyAgreementPromise = keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey);
keyAgreementPromise.then((secret) => {
  console.info("keyAgreement output is " + secret.data);
}).catch((error: BusinessError) => {
  console.error("keyAgreement error.");
});
```

## cryptoFramework.createMd

createMd(algName: string): Md

生成Md实例，用于进行消息摘要的计算与操作。

支持的规格详见框架概述“[MD消息摘要算法规格](../../security/cryptoFramework-overview.md#md消息摘要算法规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定摘要算法，支持算法请参考“[MD算法支持范围](../../security/cryptoFramework-overview.md#md消息摘要算法规格)”一节。 |

**返回值**：

| 类型 | 说明                                    |
| ---- | --------------------------------------- |
| Md   | 返回由输入算法指定生成的[Md](#md)对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401 | invalid parameters.       |
| 17620001 | memory error.       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  // Set algName based on the algorithm supported.
  let md = cryptoFramework.createMd("SHA256");
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Md

Md类，调用Md方法可以进行MD（Message Digest）摘要计算。调用前，需要通过[createMd](#cryptoframeworkcreatemd)构造Md实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| algName | string | 是   | 否   | 代表指定的摘要算法名。 |

### update

update(input: DataBlob, callback: AsyncCallback\<void>): void

传入消息进行Md更新计算，通过注册回调函数更新。

> **说明：**
>
> Md算法多次调用update更新的代码示例详见开发指导“[使用摘要操作](../../security/cryptoFramework-guidelines.md#使用摘要操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明         |
| -------- | --------------------- | ---- | ------------ |
| input    | [DataBlob](#datablob) | 是   | 传入的消息。 |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当摘要更新成功，err为undefined，否则为错误对象。  |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.       |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let md = cryptoFramework.createMd("SHA256");
console.info("Md algName is: " + md.algName);

let blob: cryptoFramework.DataBlob;
md.update(blob, (err,) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  }
});
```

### update

update(input: DataBlob): Promise\<void>

传入消息进行Md更新计算，通过Promise更新。

> **说明：**
>
> Md算法多次调用update更新的代码示例详见开发指导“[使用摘要操作](../../security/cryptoFramework-guidelines.md#使用摘要操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| input  | DataBlob | 是   | 传入的消息。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.       |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let md = cryptoFramework.createMd("SHA256");
console.info("Md algName is: " + md.algName);

let blob: cryptoFramework.DataBlob;
let promiseMdUpdate = md.update(blob);
promiseMdUpdate.then(() => {
  // do something
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

### digest

digest(callback: AsyncCallback\<DataBlob>): void

通过注册回调函数返回Md的计算结果。

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                     | 必填 | 说明       |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取DataBlob数据。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let md = cryptoFramework.createMd("SHA256");
console.info("Md algName is: " + md.algName);

let blob: cryptoFramework.DataBlob;
md.update(blob, (err,) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  }
  md.digest((err1, mdOutput) => {
    if (err1) {
      console.error("[Callback] err: " + err1.code);
    } else {
      console.error("[Callback]: MD result: " + mdOutput);
    }
  });
});
```

### digest

digest(): Promise\<DataBlob>

通过Promise返回Md的计算结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let md = cryptoFramework.createMd("SHA256");
console.info("Md algName is: " + md.algName);

let blob: cryptoFramework.DataBlob;
let promiseMdUpdate = md.update(blob);
promiseMdUpdate.then(() => {
  let promiseMdDigest = md.digest();
  return promiseMdDigest;
}).then(mdOutput => {
  console.error("[Promise]: MD result: " + mdOutput.data);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

### getMdLength

getMdLength(): number

获取Md消息摘要长度（字节数）。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回md计算结果的字节长度。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let md = cryptoFramework.createMd("SHA256");
console.info("Md algName is: " + md.algName);

let blob: cryptoFramework.DataBlob;
let promiseMdUpdate = md.update(blob);
promiseMdUpdate.then(() => {
  let promiseMdDigest = md.digest();
  return promiseMdDigest;
}).then(mdOutput => {
  console.error("[Promise]: MD result: " + mdOutput.data);
  let mdLen = md.getMdLength();
  console.error("MD len: " + mdLen);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

## cryptoFramework.createMac

createMac(algName: string): Mac

生成Mac实例，用于进行消息认证码的计算与操作。

支持的规格详见框架概述“[HMAC消息认证码算法规格](../../security/cryptoFramework-overview.md#hmac消息认证码算法规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定摘要算法，支持算法请参考“[HMAC算法支持范围](../../security/cryptoFramework-overview.md#hmac消息认证码算法规格)”一节。 |

**返回值**：

| 类型 | 说明                                      |
| ---- | ----------------------------------------- |
| Mac  | 返回由输入算法指定生成的[Mac](#mac)对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 401 | invalid parameters.       |
| 17620001 | memory error.       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  // Set algName based on the algorithm supported.
  let mac = cryptoFramework.createMac("SHA256");
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Mac

Mac类，调用Mac方法可以进行MAC（Message Authentication Code）加密计算。调用前，需要通过[createMac](#cryptoframeworkcreatemac)构造Mac实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| algName | string | 是   | 否   | 代表指定的摘要算法名。 |

### init

init(key: SymKey, callback: AsyncCallback\<void>): void

使用对称密钥初始化Mac计算，通过注册回调函数获取结果。

  > **说明：**
  >
  > 建议通过[HMAC密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)创建对称密钥生成器，调用[generateSymKey](#generatesymkey)随机生成对称密钥或调用[convertKey](#convertkey)传入与密钥规格长度一致的二进制密钥数据生成密钥。<br/>当指定“HMAC”生成对称密钥生成器时，仅支持调用[convertKey](#convertkey)传入长度在[1,4096]范围内（单位为byte）的任意二进制密钥数据生成密钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明           |
| -------- | -------------------- | ---- | -------------- |
| key      | [SymKey](#symkey)    | 是   | 共享对称密钥。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当HMAC初始化成功，err为undefined，否则为错误对象。  |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.       |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let mac = cryptoFramework.createMac("SHA256");
let keyBlob: cryptoFramework.DataBlob;
let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
symKeyGenerator.convertKey(keyBlob, (err, symKey) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  }
  mac.init(symKey, (err1, ) => {
    if (err1) {
      console.error("[Callback] err: " + err1.code);
    }
  });
});
```

### init

init(key: SymKey): Promise\<void>

使用对称密钥初始化Mac计算，通过Promise获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| key    | [SymKey](#symkey) | 是   | 共享对称密钥。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.       |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let mac = cryptoFramework.createMac("SHA256");
console.info("Mac algName is: " + mac.algName);

let keyBlob: cryptoFramework.DataBlob;
let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
let promiseConvertKey = symKeyGenerator.convertKey(keyBlob);
promiseConvertKey.then(symKey => {
  let promiseMacInit = mac.init(symKey);
  return promiseMacInit;
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});

```

### update

update(input: DataBlob, callback: AsyncCallback\<void>): void

传入消息进行Mac更新计算，通过注册回调函数获取结果。

> **说明：**
>
> Hmac算法多次调用update更新的代码示例详见开发指导“[使用消息认证码操作](../../security/cryptoFramework-guidelines.md#使用消息认证码操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明         |
| -------- | --------------------- | ---- | ------------ |
| input    | [DataBlob](#datablob) | 是   | 传入的消息。 |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当HMAC更新成功，err为undefined，否则为错误对象。|

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.       |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let keyBlob: cryptoFramework.DataBlob;
let mac = cryptoFramework.createMac("SHA256");
let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
symKeyGenerator.convertKey(keyBlob, (err, symKey) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  }
  mac.init(symKey, (err1, ) => {
    if (err1) {
      console.error("[Callback] err: " + err1.code);
    }
    let blob: cryptoFramework.DataBlob;
    mac.update(blob, (err2, data) => {
      if (err2) {
        console.error("[Callback] err: " + err2.code);
      }
    });
  });
});
```

### update

update(input: DataBlob): Promise\<void>

传入消息进行Mac更新计算，通过Promise获取结果。

> **说明：**
>
> Hmac算法多次调用update更新的代码示例详见开发指导“[使用消息认证码操作](../../security/cryptoFramework-guidelines.md#使用消息认证码操作)”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| input  | [DataBlob](#datablob) | 是   | 传入的消息。 |

**返回值：**

| 类型           | 说明          |
| -------------- | ------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.       |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let mac = cryptoFramework.createMac("SHA256");
console.info("Mac algName is: " + mac.algName);

let keyBlob: cryptoFramework.DataBlob;
let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
let promiseConvertKey = symKeyGenerator.convertKey(keyBlob);
promiseConvertKey.then(symKey => {
  let promiseMacInit = mac.init(symKey);
  return promiseMacInit;
}).then(() => {
  let blob: cryptoFramework.DataBlob;
  let promiseMacUpdate = mac.update(blob);
  return promiseMacUpdate;
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});

```

### doFinal

doFinal(callback: AsyncCallback\<DataBlob>): void

通过注册回调函数返回Mac的计算结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明     |
| -------- | ------------------------ | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取DataBlob数据。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let keyBlob: cryptoFramework.DataBlob;
let mac = cryptoFramework.createMac("SHA256");
let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
symKeyGenerator.convertKey(keyBlob, (err, symKey) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  }
  mac.init(symKey, (err1, ) => {
    if (err1) {
      console.error("[Callback] err: " + err1.code);
    }
    let blob: cryptoFramework.DataBlob;
    mac.update(blob, (err2, ) => {
      if (err2) {
        console.error("[Callback] err: " + err2.code);
      }
      mac.doFinal((err3, macOutput) => {
        if (err3) {
          console.error("[Callback] err: " + err3.code);
        } else {
          console.error("[Promise]: HMAC result: " + macOutput);
        }
      });
    });
  });
});
```

### doFinal

doFinal(): Promise\<DataBlob>

通过Promise返回Mac的计算结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let mac = cryptoFramework.createMac("SHA256");
console.info("Mac algName is: " + mac.algName);
let keyBlob: cryptoFramework.DataBlob;
let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
let promiseConvertKey = symKeyGenerator.convertKey(keyBlob);
promiseConvertKey.then(symKey => {
  let promiseMacInit = mac.init(symKey);
  return promiseMacInit;
}).then(() => {
  let blob: cryptoFramework.DataBlob;
  let promiseMacUpdate = mac.update(blob);
  return promiseMacUpdate;
}).then(() => {
  let promiseMacDoFinal = mac.doFinal();
  return promiseMacDoFinal;
}).then(macOutput => {
  console.error("[Promise]: HMAC result: " + macOutput.data);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

### getMacLength

getMacLength(): number

获取Mac消息认证码的长度（字节数）。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型   | 说明                        |
| ------ | --------------------------- |
| number | 返回mac计算结果的字节长度。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let mac = cryptoFramework.createMac("SHA256");
console.info("Mac algName is: " + mac.algName);
let keyBlob: cryptoFramework.DataBlob;
let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
let promiseConvertKey = symKeyGenerator.convertKey(keyBlob);
promiseConvertKey.then(symKey => {
  let promiseMacInit = mac.init(symKey);
  return promiseMacInit;
}).then(() => {
  let blob: cryptoFramework.DataBlob;
  let promiseMacUpdate = mac.update(blob);
  return promiseMacUpdate;
}).then(() => {
  let promiseMacDoFinal = mac.doFinal();
  return promiseMacDoFinal;
}).then(macOutput => {
  console.error("[Promise]: HMAC result: " + macOutput.data);
  let macLen = mac.getMacLength();
  console.error("MAC len: " + macLen);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

## cryptoFramework.createRandom

createRandom(): Random

生成Random实例，用于进行随机数的计算与设置种子。

支持的规格详见框架概述“[随机数算法规格](../../security/cryptoFramework-overview.md#随机数)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                                            |
| ------ | ----------------------------------------------- |
| Random | 返回由输入算法指定生成的[Random](#random)对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息     |
| -------- | ------------ |
| 17620001 | memory error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let rand = cryptoFramework.createRandom();
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Random

Random类，调用Random方法可以进行随机数计算。调用前，需要通过[createRandom](#cryptoframeworkcreaterandom)构造Random实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                 |
| ------- | ------ | ---- | ---- | -------------------- |
| algName<sup>10+</sup> | string | 是   | 否   | 代表当前使用的随机数生成算法，目前只支持“CTR_DRBG"。 |

### generateRandom

generateRandom(len: number, callback: AsyncCallback\<DataBlob>): void

异步生成指定长度的随机数，通过注册回调函数返回。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                 |
| -------- | ------------------------ | ---- | -------------------- |
| len      | number                   | 是   | 表示生成随机数的长度，单位为byte，范围在[1, INT_MAX]。 |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取DataBlob数据。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  } else {
    console.error("[Callback]: generate random result: " + randData.data);
  }
});
```

### generateRandom

generateRandom(len: number): Promise\<DataBlob>

异步生成指定长度的随机数，通过Promise返回。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | ------------------------------------------------------ |
| len    | number | 是   | 表示生成随机数的长度，单位为byte，范围在[1, INT_MAX]。 |

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
let promiseGenerateRand = rand.generateRandom(12);
promiseGenerateRand.then(randData => {
  console.error("[Promise]: rand result: " + randData.data);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

### generateRandomSync<sup>10+</sup>

generateRandomSync(len: number): DataBlob

同步生成指定长度的随机数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| len    | number | 是   | 表示生成随机数的长度，单位为byte，范围在[1, INT_MAX]。 |

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
|[DataBlob](#datablob) | 表示生成的随机数。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
try {
  let randData = rand.generateRandomSync(12);
  if (randData != null) {
    console.info("[Sync]: rand result: " + randData.data);
  } else {
    console.error("[Sync]: get rand result fail!");
  }
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

### setSeed

setSeed(seed: DataBlob): void

设置指定的种子。

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| seed   | DataBlob | 是   | 设置的种子。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 17620001 | memory error.      |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  } else {
    console.info("[Callback]: generate random result: " + randData.data);
    try {
      rand.setSeed(randData);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`sync error, ${e.code}, ${e.message}`);
    }
  }
});
```

## cryptoFramework.createKdf<sup>11+</sup>

createKdf(algName: string): Kdf

密钥派生函数（key derivation function）实例生成。<br/>支持的规格详见框架概述“[密钥派生函数规格](../../security/cryptoFramework-overview.md#密钥派生函数规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                              |
| ------- | ------ | ---- | --------------------------------- |
| algName | string | 是   | 指定密钥派生算法（包含HMAC配套的散列函数）：目前仅支持PBKDF2算法，如"PBKDF2|SHA1"。 |

**返回值**：

| 类型         | 说明                                       |
| ------------ | ------------------------------------------ |
| [Kdf](#kdf11) | 返回由输入算法指定生成的Kdf对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

**示例：**

```ts
let kdf = cryptoFramework.createKdf("PBKDF2|SHA1");

```

## Kdf<sup>11+</sup>

密钥派生函数（key derivation function）类，使用密钥派生方法之前需要创建该类的实例进行操作，通过createKdf(algName: string): Kdf方法构造此实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | 是   | 否   | 密钥派生函数的算法名称。 |

### generateSecret

generateSecret(params: KdfSpec, callback: AsyncCallback\<DataBlob>): void

基于传入的密钥派生参数进行密钥派生，通过注册回调函数返回派生得到的密钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                   |
| -------- | ------------------------ | ---- | ---------------------- |
| spec   | [KdfSpec](#kdfspec11)        | 是   | 设置密钥派生函数的参数。 |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取派生得到的密钥DataBlob数据。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let spec: cryptoFramework.PBKDF2Spec = {
  algName: 'PBKDF2',
  password: '123456',
  salt: new Uint8Array(16),
  iterations: 10000,
  keySize: 32
};
let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
kdf.generateSecret(spec, (err, secret) => {
  if (err) {
    console.error("key derivation error.");
    return;
  }
  console.info("key derivation output is " + secret.data);
});
```

### generateSecret

generateSecret(params: KdfSpec): Promise\<DataBlob>

基于传入的密钥派生参数进行密钥派生，通过Promise形式返回派生得到的密钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| spec   | [KdfSpec](#kdfspec11)        | 是   | 设置密钥派生函数的参数。 |

**返回值：**

| 类型               | 说明     |
| ------------------ | -------- |
| Promise\<[DataBlob](#datablob)> | 回调函数，用于获取派生得到的密钥DataBlob数据。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let spec: cryptoFramework.PBKDF2Spec = {
  algName: 'PBKDF2',
  password: '123456',
  salt: new Uint8Array(16),
  iterations: 10000,
  keySize: 32
};
let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
let kdfPromise = kdf.generateSecret(spec);
kdfPromise.then((secret) => {
  console.info("key derivation output is " + secret.data);
}).catch((error: BusinessError) => {
  console.error("key derivation error.");
});
```