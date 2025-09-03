# crypto_signature.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义验签接口。

**引用文件：** <CryptoArchitectureKit/crypto_signature.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoSignatureApi](capi-cryptosignatureapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) | OH_CryptoVerify | 定义验签结构体。 |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) | OH_CryptoSign | 定义签名结构体。 |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) | OH_CryptoEccSignatureSpec | 定义ECC签名规范结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) | CryptoSignature_ParamType | 定义签名验签参数类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoVerify_Create(const char *algoName, OH_CryptoVerify **verify)](#oh_cryptoverify_create) | 创建验签实例。 |
| [OH_Crypto_ErrCode OH_CryptoVerify_Init(OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey)](#oh_cryptoverify_init) | 传入公钥初始化验签实例。 |
| [OH_Crypto_ErrCode OH_CryptoVerify_Update(OH_CryptoVerify *ctx, Crypto_DataBlob *in)](#oh_cryptoverify_update) | 追加待验签数据。 |
| [bool OH_CryptoVerify_Final(OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData)](#oh_cryptoverify_final) | 对数据进行验签。 |
| [OH_Crypto_ErrCode OH_CryptoVerify_Recover(OH_CryptoVerify *ctx, Crypto_DataBlob *signData,Crypto_DataBlob *rawSignData)](#oh_cryptoverify_recover) | 对签名数据进行恢复操作。 |
| [const char *OH_CryptoVerify_GetAlgoName(OH_CryptoVerify *ctx)](#oh_cryptoverify_getalgoname) | 获取验签算法名称。 |
| [OH_Crypto_ErrCode OH_CryptoVerify_SetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)](#oh_cryptoverify_setparam) | 设置验签参数。 |
| [OH_Crypto_ErrCode OH_CryptoVerify_GetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)](#oh_cryptoverify_getparam) | 获取验签参数。 |
| [void OH_CryptoVerify_Destroy(OH_CryptoVerify *ctx)](#oh_cryptoverify_destroy) | 销毁验签实例。 |
| [OH_Crypto_ErrCode OH_CryptoSign_Create(const char *algoName, OH_CryptoSign **sign)](#oh_cryptosign_create) | 根据给定的算法名称创建签名实例。 |
| [OH_Crypto_ErrCode OH_CryptoSign_Init(OH_CryptoSign *ctx, OH_CryptoPrivKey *privKey)](#oh_cryptosign_init) | 初始化签名实例。 |
| [OH_Crypto_ErrCode OH_CryptoSign_Update(OH_CryptoSign *ctx, const Crypto_DataBlob *in)](#oh_cryptosign_update) | 更新需要签名的数据。 |
| [OH_Crypto_ErrCode OH_CryptoSign_Final(OH_CryptoSign *ctx, const Crypto_DataBlob *in, Crypto_DataBlob *out)](#oh_cryptosign_final) | 完成签名操作。 |
| [const char *OH_CryptoSign_GetAlgoName(OH_CryptoSign *ctx)](#oh_cryptosign_getalgoname) | 获取签名实例的算法名称。 |
| [OH_Crypto_ErrCode OH_CryptoSign_SetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type,const Crypto_DataBlob *value)](#oh_cryptosign_setparam) | 设置签名实例的指定参数。 |
| [OH_Crypto_ErrCode OH_CryptoSign_GetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value)](#oh_cryptosign_getparam) | 从签名实例获取指定参数。 |
| [void OH_CryptoSign_Destroy(OH_CryptoSign *ctx)](#oh_cryptosign_destroy) | 销毁签名实例。 |
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Create(Crypto_DataBlob *eccSignature,OH_CryptoEccSignatureSpec **spec)](#oh_cryptoeccsignaturespec_create) | 创建ECC签名规范。 |
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_GetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)](#oh_cryptoeccsignaturespec_getrands) | 获取ECC签名的r和s值。 |
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_SetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)](#oh_cryptoeccsignaturespec_setrands) | 设置ECC签名的r和s值。 |
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Encode(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *out)](#oh_cryptoeccsignaturespec_encode) | 将ECC签名规范编码为DER格式的签名。 |
| [void OH_CryptoEccSignatureSpec_Destroy(OH_CryptoEccSignatureSpec *spec)](#oh_cryptoeccsignaturespec_destroy) | 销毁ECC签名规范。 |

## 枚举类型说明

### CryptoSignature_ParamType

```
enum CryptoSignature_ParamType
```

**描述**

定义签名验签参数类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_PSS_MD_NAME_STR = 100 | 表示RSA算法中，使用PSS模式时，消息摘要功能的算法名。 |
| CRYPTO_PSS_MGF_NAME_STR = 101 | 表示RSA算法中，使用PSS模式时，掩码生成算法（目前仅支持MGF1）。 |
| CRYPTO_PSS_MGF1_NAME_STR = 102 | 表示RSA算法中，使用PSS模式时，MGF1掩码生成功能的消息摘要参数。 |
| CRYPTO_PSS_SALT_LEN_INT = 103 | 表示RSA算法中，使用PSS模式时，盐值的长度，长度以字节为单位。 |
| CRYPTO_PSS_TRAILER_FIELD_INT = 104 | 表示RSA算法中，使用PSS模式时，用于编码操作的整数，值为1。 |
| CRYPTO_SM2_USER_ID_DATABLOB = 105 | 表示SM2算法中，用户身份标识字段。 |


## 函数说明

### OH_CryptoVerify_Create()

```
OH_Crypto_ErrCode OH_CryptoVerify_Create(const char *algoName, OH_CryptoVerify **verify)
```

**描述**

创建验签实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | 用于生成验签实例的算法名称。<br> 例如"RSA1024\|PKCS1\|SHA256" |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) **verify | 指向验签实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoVerify_Init()

```
OH_Crypto_ErrCode OH_CryptoVerify_Init(OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey)
```

**描述**

传入公钥初始化验签实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *pubKey | 公钥对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoVerify_Update](#oh_cryptoverify_update)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)


### OH_CryptoVerify_Update()

```
OH_Crypto_ErrCode OH_CryptoVerify_Update(OH_CryptoVerify *ctx, Crypto_DataBlob *in)
```

**描述**

追加待验签数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 传入的消息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)


### OH_CryptoVerify_Final()

```
bool OH_CryptoVerify_Final(OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData)
```

**描述**

对数据进行验签。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 传入的数据。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *signData | 签名数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 表示验签是否通过。 |

**参考：**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Update](#oh_cryptoverify_update)


### OH_CryptoVerify_Recover()

```
OH_Crypto_ErrCode OH_CryptoVerify_Recover(OH_CryptoVerify *ctx, Crypto_DataBlob *signData,Crypto_DataBlob *rawSignData)
```

**描述**

对签名数据进行恢复操作。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *signData | 签名数据。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *rawSignData | 验签恢复的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoVerify_GetAlgoName()

```
const char *OH_CryptoVerify_GetAlgoName(OH_CryptoVerify *ctx)
```

**描述**

获取验签算法名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回验签算法名称。 |

### OH_CryptoVerify_SetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_SetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)
```

**描述**

设置验签参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | 用于指定需要设置的验签参数。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | 用于指定验签参数的具体值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoVerify_GetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_GetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)
```

**描述**

获取验签参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | 用于指定需要获取的验签参数。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | 获取的验签参数的具体值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoVerify_Destroy()

```
void OH_CryptoVerify_Destroy(OH_CryptoVerify *ctx)
```

**描述**

销毁验签实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | 指向验签实例。 |

### OH_CryptoSign_Create()

```
OH_Crypto_ErrCode OH_CryptoSign_Create(const char *algoName, OH_CryptoSign **sign)
```

**描述**

根据给定的算法名称创建签名实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | 用于生成签名实例的算法名称。<br> 例如"RSA\|PKCS1\|SHA384"、"ECC\|SHA384"。 |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) **sign | 签名实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoSign_Init()

```
OH_Crypto_ErrCode OH_CryptoSign_Init(OH_CryptoSign *ctx, OH_CryptoPrivKey *privKey)
```

**描述**

初始化签名实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | 指向签名实例。 |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *privKey | 私钥。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoSign_Update](#oh_cryptosign_update)

[OH_CryptoSign_Final](#oh_cryptosign_final)


### OH_CryptoSign_Update()

```
OH_Crypto_ErrCode OH_CryptoSign_Update(OH_CryptoSign *ctx, const Crypto_DataBlob *in)
```

**描述**

更新需要签名的数据。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | 指向签名实例。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 需要签名的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoSign_Init](#oh_cryptosign_init)

[OH_CryptoSign_Final](#oh_cryptosign_final)


### OH_CryptoSign_Final()

```
OH_Crypto_ErrCode OH_CryptoSign_Final(OH_CryptoSign *ctx, const Crypto_DataBlob *in, Crypto_DataBlob *out)
```

**描述**

完成签名操作。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | 指向签名实例。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 需要签名的数据。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 签名结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoSign_Init](#oh_cryptosign_init)

[OH_CryptoSign_Update](#oh_cryptosign_update)


### OH_CryptoSign_GetAlgoName()

```
const char *OH_CryptoSign_GetAlgoName(OH_CryptoSign *ctx)
```

**描述**

获取签名实例的算法名称。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | 指向签名实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回签名算法名称。 |

### OH_CryptoSign_SetParam()

```
OH_Crypto_ErrCode OH_CryptoSign_SetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type,const Crypto_DataBlob *value)
```

**描述**

设置签名实例的指定参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | 指向签名实例。 |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | 签名参数类型。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | 输入数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoSign_GetParam()

```
OH_Crypto_ErrCode OH_CryptoSign_GetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value)
```

**描述**

从签名实例获取指定参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | 指向签名实例。 |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | 签名参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | 输出数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoSign_Destroy()

```
void OH_CryptoSign_Destroy(OH_CryptoSign *ctx)
```

**描述**

销毁签名实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | 指向签名实例。 |

### OH_CryptoEccSignatureSpec_Create()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Create(Crypto_DataBlob *eccSignature,OH_CryptoEccSignatureSpec **spec)
```

**描述**

创建ECC签名规范。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *eccSignature | ECC签名（DER格式），如果EccSignature参数为NULL，将创建一个空的ECC签名规范。 |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) **spec | 输出的ECC签名规范。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoEccSignatureSpec_GetRAndS()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_GetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)
```

**描述**

获取ECC签名的r和s值。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | 指向ECC签名规范。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *r | r值。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *s | s值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoEccSignatureSpec_SetRAndS()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_SetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)
```

**描述**

设置ECC签名的r和s值。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | 指向ECC签名规范。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *r | r值。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *s | s值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoEccSignatureSpec_Encode()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Encode(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *out)
```

**描述**

将ECC签名规范编码为DER格式的签名。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | 指向ECC签名规范。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 输出数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoEccSignatureSpec_Destroy()

```
void OH_CryptoEccSignatureSpec_Destroy(OH_CryptoEccSignatureSpec *spec)
```

**描述**

销毁ECC签名规范。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | 指向ECC签名规范。 |


