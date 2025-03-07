# CryptoSymKeyApi


## 概述

提供对称密钥相关功能接口。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [crypto_sym_key.h](crypto__sym__key_8h.md) | 定义对称密钥接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoSymKey](#oh_cryptosymkey) [OH_CryptoSymKey](#oh_cryptosymkey) | 定义对称密钥结构体。 | 
| typedef struct [OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) [OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) | 定义对称密钥生成器结构体。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Create](#oh_cryptosymkeygenerator_create) (const char \*algoName, [OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*\*ctx) | 根据给定的算法名称创建对称密钥生成器。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Generate](#oh_cryptosymkeygenerator_generate) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx, [OH_CryptoSymKey](#oh_cryptosymkey) \*\*keyCtx) | 随机生成对称密钥。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Convert](#oh_cryptosymkeygenerator_convert) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx, const [Crypto_DataBlob](_crypto___data_blob.md) \*keyData, [OH_CryptoSymKey](#oh_cryptosymkey) \*\*keyCtx) | 将对称密钥数据转换为对称密钥。 | 
| const char \* [OH_CryptoSymKeyGenerator_GetAlgoName](#oh_cryptosymkeygenerator_getalgoname) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx) | 获取对称密钥生成器的算法名称。 | 
| void [OH_CryptoSymKeyGenerator_Destroy](#oh_cryptosymkeygenerator_destroy) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx) | 销毁对称密钥生成器。 | 
| const char \* [OH_CryptoSymKey_GetAlgoName](#oh_cryptosymkey_getalgoname) ([OH_CryptoSymKey](#oh_cryptosymkey) \*keyCtx) | 从对称密钥获取对称密钥算法名称。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKey_GetKeyData](#oh_cryptosymkey_getkeydata) ([OH_CryptoSymKey](#oh_cryptosymkey) \*keyCtx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 从密钥实例获取对称密钥数据。 | 
| void [OH_CryptoSymKey_Destroy](#oh_cryptosymkey_destroy) ([OH_CryptoSymKey](#oh_cryptosymkey) \*keyCtx) | 销毁对称密钥实例。 | 


## 类型定义说明


### OH_CryptoSymKey

```
typedef struct OH_CryptoSymKeyOH_CryptoSymKey
```

**描述**

定义对称密钥结构体。

**起始版本：** 12


### OH_CryptoSymKeyGenerator

```
typedef struct OH_CryptoSymKeyGeneratorOH_CryptoSymKeyGenerator
```

**描述**

定义对称密钥生成器结构体。

**起始版本：** 12


## 函数说明


### OH_CryptoSymKey_Destroy()

```
void OH_CryptoSymKey_Destroy (OH_CryptoSymKey *keyCtx)
```

**描述**

销毁对称密钥实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyCtx | 指向对称密钥实例。 | 


### OH_CryptoSymKey_GetAlgoName()

```
const char* OH_CryptoSymKey_GetAlgoName (OH_CryptoSymKey *keyCtx)
```

**描述**

从对称密钥获取对称密钥算法名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyCtx | 指向对称密钥实例。 | 

**返回：**

返回对称密钥算法名称。


### OH_CryptoSymKey_GetKeyData()

```
OH_Crypto_ErrCode OH_CryptoSymKey_GetKeyData (OH_CryptoSymKey *keyCtx, Crypto_DataBlob *out )
```

**描述**

从密钥实例获取对称密钥数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyCtx | 指向对称密钥实例。 | 
| out | 获取到的结果。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Convert (OH_CryptoSymKeyGenerator *ctx, const Crypto_DataBlob *keyData, OH_CryptoSymKey **keyCtx )
```

**描述**

将对称密钥数据转换为对称密钥。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥生成器实例。 | 
| keyData | 指向生成对称密钥的数据。 | 
| keyCtx | 指向对称密钥实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Create (const char *algoName, OH_CryptoSymKeyGenerator **ctx )
```

**描述**

根据给定的算法名称创建对称密钥生成器。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| algoName | 用于生成对称密钥的算法名称。例如: "AES256"。 | 
| ctx | 指向对称密钥生成器实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymKeyGenerator_Destroy()

```
void OH_CryptoSymKeyGenerator_Destroy (OH_CryptoSymKeyGenerator *ctx)
```

**描述**

销毁对称密钥生成器。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥生成器实例的指针。 | 


### OH_CryptoSymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Generate (OH_CryptoSymKeyGenerator *ctx, OH_CryptoSymKey **keyCtx )
```

**描述**

随机生成对称密钥。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥生成器实例。 | 
| keyCtx | 指向对称密钥的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoSymKeyGenerator_GetAlgoName()

```
const char* OH_CryptoSymKeyGenerator_GetAlgoName (OH_CryptoSymKeyGenerator *ctx)
```

**描述**

获取对称密钥生成器的算法名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 指向对称密钥生成器实例的指针。 | 

**返回：**

返回对称密钥算法名称。
