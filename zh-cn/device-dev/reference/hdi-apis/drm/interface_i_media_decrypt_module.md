# IMediaDecryptModule


## 概述

定义内容解密、解密模块实例释放函数。用于解密加密的内容。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [DecryptMediaData](#decryptmediadata) ([in] boolean secure, [in] struct [CryptoInfo](_crypto_info.md) cryptoInfo, [in] struct [DrmBuffer](_drm_buffer.md) srcBuffer, [in] struct [DrmBuffer](_drm_buffer.md) destBuffer) | 内容解密接口，该接口使用解密描述信息对源缓冲区数据解密 并存放至目标缓冲区，提供安全内存和非安全内存两种类型的目标缓冲区。  | 
| [Release](#release) () | 释放解密模块。  | 


## 成员函数说明


### DecryptMediaData()

```
IMediaDecryptModule::DecryptMediaData ([in] boolean secure, [in] struct CryptoInfo cryptoInfo, [in] struct DrmBuffer srcBuffer, [in] struct DrmBuffer destBuffer )
```
**描述**

内容解密接口，该接口使用解密描述信息对源缓冲区数据解密 并存放至目标缓冲区，提供安全内存和非安全内存两种类型的目标缓冲区。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| secure | 是否在安全内存中解密，true表示使用安全内存，false表示使用非安内存。  | 
| cryptoInfo | 密钥标识及数据加密的相关信息。  | 
| srcBuffer | 待解密数据buffer。  | 
| destBuffer | 解密后数据buffer。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### Release()

```
IMediaDecryptModule::Release ()
```
**描述**

释放解密模块。

**起始版本：** 4.1

**返回：**

0 表示执行成功。

其他值表示执行失败。
