# CryptoSymCipherApi


## 概述

为应用提供对称密钥加解密相关接口功能。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [crypto_sym_cipher.h](crypto__sym__cipher_8h.md) | 定义对称密钥加解密接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoSymCipher](#oh_cryptosymcipher) [OH_CryptoSymCipher](#oh_cryptosymcipher) | 定义对称加解密结构体。 | 
| typedef struct [OH_CryptoSymCipherParams](#oh_cryptosymcipherparams) [OH_CryptoSymCipherParams](#oh_cryptosymcipherparams) | 定义对称加解密参数结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CryptoSymCipher_ParamsType](#cryptosymcipher_paramstype) {<br/>CRYPTO_IV_DATABLOB = 100,<br/>CRYPTO_AAD_DATABLOB = 101,<br/>CRYPTO_TAG_DATABLOB = 102<br/>} | 定义对称加解密参数类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipherParams_Create](#oh_cryptosymcipherparams_create) ([OH_CryptoSymCipherParams](#oh_cryptosymcipherparams) \*\*params) | 创建对称密钥加解密参数实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipherParams_SetParam](#oh_cryptosymcipherparams_setparam) ([OH_CryptoSymCipherParams](#oh_cryptosymcipherparams) \*params, [CryptoSymCipher_ParamsType](#cryptosymcipher_paramstype) paramsType, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 设置对称密钥加解密参数。 | 
| void [OH_CryptoSymCipherParams_Destroy](#oh_cryptosymcipherparams_destroy) ([OH_CryptoSymCipherParams](#oh_cryptosymcipherparams) \*params) | 销毁对称密钥加解密参数实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Create](#oh_cryptosymcipher_create) (const char \*algoName, [OH_CryptoSymCipher](#oh_cryptosymcipher) \*\*ctx) | 根据给定的算法名称创建对称密钥加解密实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Init](#oh_cryptosymcipher_init) ([OH_CryptoSymCipher](#oh_cryptosymcipher) \*ctx, [Crypto_CipherMode](_crypto_common_api.md#crypto_ciphermode) mod, [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*key, [OH_CryptoSymCipherParams](#oh_cryptosymcipherparams) \*params) | 初始化对称密钥加解密实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Update](#oh_cryptosymcipher_update) ([OH_CryptoSymCipher](#oh_cryptosymcipher) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 更新加密或者解密数据操作。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Final](#oh_cryptosymcipher_final) ([OH_CryptoSymCipher](#oh_cryptosymcipher) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 输出加/解密（分组模式产生的）剩余数据，最后结束加密或者解密数据操作。 | 
| const char \* [OH_CryptoSymCipher_GetAlgoName](#oh_cryptosymcipher_getalgoname) ([OH_CryptoSymCipher](#oh_cryptosymcipher) \*ctx) | 获取对称密钥加解密实例的算法名称。 | 
| void [OH_CryptoSymCipher_Destroy](#oh_cryptosymcipher_destroy) ([OH_CryptoSymCipher](#oh_cryptosymcipher) \*ctx) | 销毁对称密钥加解密实例。 | 


## 类型定义说明


### OH_CryptoSymCipher

```
typedef struct OH_CryptoSymCipherOH_CryptoSymCipher
```

**描述**

定义对称加解密结构体。

**起始版本：** 12


### OH_CryptoSymCipherParams

```
typedef struct OH_CryptoSymCipherParamsOH_CryptoSymCipherParams
```

**描述**

定义对称加解密参数结构体。

**起始版本：** 12


## 枚举类型说明


### CryptoSymCipher_ParamsType

```
enum CryptoSymCipher_ParamsType
```

**描述**

定义对称加解密参数类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CRYPTO_IV_DATABLOB | 加解密参数iv。 | 
| CRYPTO_AAD_DATABLOB | 加解密参数aad。 | 
| CRYPTO_TAG_DATABLOB | 加解密参数authTag。 | 


## 函数说明


### OH_CryptoSymCipher_Create()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Create (const char *algoName, OH_CryptoSymCipher **ctx )
```

**描述**

根据给定的算法名称创建对称密钥加解密实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| algoName | 用于生成对称密钥加解密实例的算法名称。例如： AES128\|GCM\|PKCS7. | 
| ctx | 指向对称密钥加解密实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymCipher_Destroy()

```
void OH_CryptoSymCipher_Destroy (OH_CryptoSymCipher *ctx)
```

**描述**

销毁对称密钥加解密实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥加解密实例。 | 


### OH_CryptoSymCipher_Final()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Final (OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out )
```

**描述**

输出 加/解密（分组模式产生的）剩余数据，最后结束加密或者解密数据操作。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥加解密实例。 | 
| in | 要加密或解密的数据。 | 
| out | 返回剩余数据的加/解密结果。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。

**参见：**

[OH_CryptoSymCipher_Init](#oh_cryptosymcipher_init)

[OH_CryptoSymCipher_Update](#oh_cryptosymcipher_update)


### OH_CryptoSymCipher_GetAlgoName()

```
const char* OH_CryptoSymCipher_GetAlgoName (OH_CryptoSymCipher *ctx)
```

**描述**

获取对称密钥加解密实例的算法名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥加解密实例。 | 

**返回：**

返回对称加解密算法名称。


### OH_CryptoSymCipher_Init()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Init (OH_CryptoSymCipher *ctx, Crypto_CipherMode mod, OH_CryptoSymKey *key, OH_CryptoSymCipherParams *params )
```

**描述**

初始化对称密钥加解密实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥加解密实例。 | 
| mod | 加解密模式。 | 
| key | 对称密钥。 | 
| params | 指向对称密钥参数实例。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymCipher_Update()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Update (OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out )
```

**描述**

更新加密或者解密数据操作。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥加解密实例。 | 
| in | 加密或者解密的数据。 | 
| out | 更新的结果。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymCipherParams_Create()

```
OH_Crypto_ErrCode OH_CryptoSymCipherParams_Create (OH_CryptoSymCipherParams **params)
```

**描述**

创建对称密钥加解密参数实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| params | 指向对称加解密参数实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymCipherParams_Destroy()

```
void OH_CryptoSymCipherParams_Destroy (OH_CryptoSymCipherParams *params)
```

**描述**

销毁对称密钥加解密参数实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| params | 指向对称密钥加解密参数实例。 | 


### OH_CryptoSymCipherParams_SetParam()

```
OH_Crypto_ErrCode OH_CryptoSymCipherParams_SetParam (OH_CryptoSymCipherParams *params, CryptoSymCipher_ParamsType paramsType, Crypto_DataBlob *value )
```

**描述**

设置对称密钥加解密参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| params | 指向对称密钥加解密参数实例。 | 
| paramsType | 设置对称密钥加解密参数类型。 | 
| value | 设置的参数值。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。
