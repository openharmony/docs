# CryptoSignatureApi


## 概述

为应用提供验签接口。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [crypto_signature.h](crypto__signature_8h.md) | 定义验签接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoVerify](#oh_cryptoverify) [OH_CryptoVerify](#oh_cryptoverify) | 定义验签结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) {<br/>CRYPTO_PSS_MD_NAME_STR = 100, CRYPTO_PSS_MGF_NAME_STR = 101,<br/>CRYPTO_PSS_MGF1_NAME_STR = 102, CRYPTO_PSS_SALT_LEN_INT = 103,<br/>CRYPTO_PSS_TRAILER_FIELD_INT = 104, CRYPTO_SM2_USER_ID_DATABLOB = 105<br/>} | 定义签名验签参数类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Create](#oh_cryptoverify_create) (const char \*algoName, [OH_CryptoVerify](#oh_cryptoverify) \*\*verify) | 创建验签实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Init](#oh_cryptoverify_init) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*pubKey) | 传入公钥初始化验签实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Update](#oh_cryptoverify_update) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | 追加待验签数据。 | 
| bool [OH_CryptoVerify_Final](#oh_cryptoverify_final) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*signData) | 对数据进行验签。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Recover](#oh_cryptoverify_recover) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*signData, [Crypto_DataBlob](_crypto___data_blob.md) \*rawSignData) | 对签名数据进行恢复操作。 | 
| const char \* [OH_CryptoVerify_GetAlgoName](#oh_cryptoverify_getalgoname) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx) | 获取验签算法名称。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_SetParam](#oh_cryptoverify_setparam) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 设置验签参数。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_GetParam](#oh_cryptoverify_getparam) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 获取验签参数。 | 
| void [OH_CryptoVerify_Destroy](#oh_cryptoverify_destroy) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx) | 销毁验签实例。 | 


## 类型定义说明


### OH_CryptoVerify

```
typedef struct OH_CryptoVerifyOH_CryptoVerify
```

**描述**

定义验签结构体。

**起始版本：** 12


## 枚举类型说明


### CryptoSignature_ParamType

```
enum CryptoSignature_ParamType
```

**描述**

定义签名验签参数类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CRYPTO_PSS_MD_NAME_STR | 表示RSA算法中，使用PSS模式时，消息摘要功能的算法名。 | 
| CRYPTO_PSS_MGF_NAME_STR | 表示RSA算法中，使用PSS模式时，掩码生成算法（目前仅支持MGF1）。 | 
| CRYPTO_PSS_MGF1_NAME_STR | 表示RSA算法中，使用PSS模式时，MGF1掩码生成功能的消息摘要参数。 | 
| CRYPTO_PSS_SALT_LEN_INT | 表示RSA算法中，使用PSS模式时，盐值的长度，长度以字节为单位。 | 
| CRYPTO_PSS_TRAILER_FIELD_INT | 表示RSA算法中，使用PSS模式时，用于编码操作的整数，值为1。 | 
| CRYPTO_SM2_USER_ID_DATABLOB | 表示SM2算法中，用户身份标识字段。 | 


## 函数说明


### OH_CryptoVerify_Create()

```
OH_Crypto_ErrCode OH_CryptoVerify_Create (const char *algoName, OH_CryptoVerify **verify )
```

**描述**

创建验签实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| algoName | 用于生成验签实例的算法名称。例如：RSA1024\|PKCS1\|SHA256 | 
| verify | 指向验签实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoVerify_Destroy()

```
void OH_CryptoVerify_Destroy (OH_CryptoVerify *ctx)
```

**描述**

销毁验签实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 


### OH_CryptoVerify_Final()

```
bool OH_CryptoVerify_Final (OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData )
```

**描述**

对数据进行验签。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 
| in | 传入的数据。 | 
| out | 签名数据。 | 

**返回：**

返回bool类型，代表验签是否通过。

**参见：**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Update](#oh_cryptoverify_update)


### OH_CryptoVerify_GetAlgoName()

```
const char* OH_CryptoVerify_GetAlgoName (OH_CryptoVerify *ctx)
```

**描述**

获取验签算法名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 

**返回：**

返回验签算法名称。


### OH_CryptoVerify_GetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_GetParam (OH_CryptoVerify *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value )
```

**描述**

获取验签参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 
| type | 用于指定需要获取的验签参数。 | 
| value | 获取的验签参数的具体值。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。。


### OH_CryptoVerify_Init()

```
OH_Crypto_ErrCode OH_CryptoVerify_Init (OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey )
```

**描述**

传入公钥初始化验签实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 
| pubKey | 公钥对象。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。

**参见：**

[OH_CryptoVerify_Update](#oh_cryptoverify_update)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)


### OH_CryptoVerify_Recover()

```
OH_Crypto_ErrCode OH_CryptoVerify_Recover (OH_CryptoVerify *ctx, Crypto_DataBlob *signData, Crypto_DataBlob *rawSignData )
```

**描述**

对签名数据进行恢复操作。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 
| signData | 签名数据。 | 
| rawSignData | 验签恢复的数据。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoVerify_SetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_SetParam (OH_CryptoVerify *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value )
```

**描述**

设置验签参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 
| type | 用于指定需要设置的验签参数。 | 
| value | 用于指定验签参数的具体值。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoVerify_Update()

```
OH_Crypto_ErrCode OH_CryptoVerify_Update (OH_CryptoVerify *ctx, Crypto_DataBlob *in )
```

**描述**

追加待验签数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向验签实例。 | 
| in | 传入的消息。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。

**参见：**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)
