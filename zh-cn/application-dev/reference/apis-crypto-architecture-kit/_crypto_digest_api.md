# CryptoDigestApi


## 概述

为应用提供摘要算法的相关接口。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [crypto_digest.h](crypto__digest_8h.md) | 定义摘要算法API。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoDigest](#oh_cryptodigest) [OH_CryptoDigest](#oh_cryptodigest) | 定义摘要结构体。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Create](#oh_cryptodigest_create) (const char \*algoName, [OH_CryptoDigest](#oh_cryptodigest) \*\*ctx) | 根据给定的算法名称创建一个摘要实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Update](#oh_cryptodigest_update) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | 传入消息进行摘要更新计算。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Final](#oh_cryptodigest_final) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 计算最终摘要。 | 
| uint32_t [OH_CryptoDigest_GetLength](#oh_cryptodigest_getlength) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx) | 获取摘要长度。 | 
| const char \* [OH_CryptoDigest_GetAlgoName](#oh_cryptodigest_getalgoname) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx) | 获取摘要算法。 | 
| void [OH_DigestCrypto_Destroy](#oh_digestcrypto_destroy) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx) | 销毁摘要实例。 | 


## 类型定义说明


### OH_CryptoDigest

```
typedef struct OH_CryptoDigestOH_CryptoDigest
```

**描述**

定义摘要结构体。

**起始版本：** 12


## 函数说明


### OH_CryptoDigest_Create()

```
OH_Crypto_ErrCode OH_CryptoDigest_Create (const char *algoName, OH_CryptoDigest **ctx )
```

**描述**

根据给定的算法名称创建一个摘要实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| algoName | 用于生成摘要实例的算法名称。例如："SHA256" | 
| ctx | 指向摘要实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoDigest_Final()

```
OH_Crypto_ErrCode OH_CryptoDigest_Final (OH_CryptoDigest *ctx, Crypto_DataBlob *out )
```

**描述**

计算最终摘要。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向摘要实例。 | 
| out | 返回的Md的计算结果。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。

**参见：**

[OH_CryptoDigest_Update](#oh_cryptodigest_update)


### OH_CryptoDigest_GetAlgoName()

```
const char* OH_CryptoDigest_GetAlgoName (OH_CryptoDigest *ctx)
```

**描述**

获取摘要算法。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向摘要实例。 | 

**返回：**

摘要算法名。


### OH_CryptoDigest_GetLength()

```
uint32_t OH_CryptoDigest_GetLength (OH_CryptoDigest *ctx)
```

**描述**

获取摘要长度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向摘要实例。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoDigest_Update()

```
OH_Crypto_ErrCode OH_CryptoDigest_Update (OH_CryptoDigest *ctx, Crypto_DataBlob *in )
```

**描述**

传入消息进行摘要更新计算。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向摘要实例。 | 
| in | 传入的消息。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。

**参见：**

[OH_CryptoDigest_Final](#oh_cryptodigest_final)


### OH_DigestCrypto_Destroy()

```
void OH_DigestCrypto_Destroy (OH_CryptoDigest *ctx)
```

**描述**

销毁摘要实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向摘要实例。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。
