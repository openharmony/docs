# CryptoCommonApi


## 概述

为应用提供算法库通用接口功能。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [crypto_common.h](crypto__common_8h.md) | 定义通用API接口。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Crypto_DataBlob](_crypto___data_blob.md) | 加解密数据结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Crypto_DataBlob](_crypto___data_blob.md) [Crypto_DataBlob](#crypto_datablob) | 加解密数据结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](#oh_crypto_errcode) {<br/>CRYPTO_SUCCESS = 0, CRYPTO_INVALID_PARAMS = 401,<br/>CRYPTO_NOT_SUPPORT = 801, CRYPTO_MEMORY_ERROR = 17620001,<br/>CRYPTO_OPERTION_ERROR = 17630001<br/>} | 加解密错误返回码枚举。 | 
| [Crypto_CipherMode](#crypto_ciphermode) {<br/>CRYPTO_ENCRYPT_MODE = 0,<br/>CRYPTO_DECRYPT_MODE = 1<br/>} | 定义加解密操作类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_Crypto_FreeDataBlob](#oh_crypto_freedatablob) ([Crypto_DataBlob](_crypto___data_blob.md) \*dataBlob) | 释放dataBlob数据。 | 


## 类型定义说明


### Crypto_DataBlob

```
typedef struct Crypto_DataBlob Crypto_DataBlob
```

**描述**

加解密数据结构体。

**起始版本：** 12


## 枚举类型说明


### Crypto_CipherMode

```
enum Crypto_CipherMode
```

**描述**

定义加解密操作类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CRYPTO_ENCRYPT_MODE | 加密操作。 | 
| CRYPTO_DECRYPT_MODE | 解密操作。 | 


### OH_Crypto_ErrCode

```
enum OH_Crypto_ErrCode
```

**描述**

加解密错误返回码枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CRYPTO_SUCCESS | 表示操作成功。 | 
| CRYPTO_INVALID_PARAMS | 输入参数不合法。 | 
| CRYPTO_NOT_SUPPORT | 不支持的函数或算法。 | 
| CRYPTO_MEMORY_ERROR | 内存错误。 | 
| CRYPTO_OPERTION_ERROR | 表示加解密操作错误。 | 


## 函数说明


### OH_Crypto_FreeDataBlob()

```
void OH_Crypto_FreeDataBlob (Crypto_DataBlob *dataBlob)
```

**描述**

释放dataBlob数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dataBlob | 需要释放的dataBlob数据。 | 
