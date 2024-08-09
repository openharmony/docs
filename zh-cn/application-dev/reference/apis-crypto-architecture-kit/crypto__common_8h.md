# crypto_common.h


## 概述

定义通用API接口。

**库：** libohcrypto.z.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：**[CryptoCommonApi](_crypto_common_api.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Crypto_DataBlob](_crypto___data_blob.md) | 加解密数据结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Crypto_DataBlob](_crypto___data_blob.md) [Crypto_DataBlob](_crypto_common_api.md#crypto_datablob) | 加解密数据结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) {<br/>CRYPTO_SUCCESS = 0, CRYPTO_INVALID_PARAMS = 401,<br/>CRYPTO_NOT_SUPPORT = 801, CRYPTO_MEMORY_ERROR = 17620001,<br/>CRYPTO_OPERTION_ERROR = 17630001<br/>} | 加解密错误返回码枚举。 | 
| [Crypto_CipherMode](_crypto_common_api.md#crypto_ciphermode) {<br/>CRYPTO_ENCRYPT_MODE = 0,<br/>CRYPTO_DECRYPT_MODE = 1<br/>} | 定义加解密操作类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_Crypto_FreeDataBlob](_crypto_common_api.md#oh_crypto_freedatablob) ([Crypto_DataBlob](_crypto___data_blob.md) \*dataBlob) | 释放dataBlob数据。 | 
