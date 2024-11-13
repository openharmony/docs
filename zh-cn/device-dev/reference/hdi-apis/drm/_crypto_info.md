# CryptoInfo


## 概述

定义CryptoInfo，该信息由[IMediaDecryptModule::DecryptMediaData](interface_i_media_decrypt_module.md#decryptmediadata)使用。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [CryptoAlgorithmType](_hdi_drm.md#cryptoalgorithmtype)[type](#type) | 加密算法类型。  | 
| unsigned char[] [keyId](#keyid) | 密钥标识。  | 
| unsigned char[] [iv](#iv) | 秘钥配套的IV。  | 
| struct [Pattern](_pattern.md)[pattern](#pattern) | 加密模式。  | 
| struct [SubSample](_sub_sample.md)[] [subSamples](#subsamples) | 加密subsample。  | 


## 类成员变量说明


### iv

```
unsigned char [] CryptoInfo::iv
```
**描述**

秘钥配套的IV。


### keyId

```
unsigned char [] CryptoInfo::keyId
```
**描述**

密钥标识。


### pattern

```
struct Pattern CryptoInfo::pattern
```
**描述**

加密模式。


### subSamples

```
struct SubSample [] CryptoInfo::subSamples
```
**描述**

加密subsample。


### type

```
enum CryptoAlgorithmType CryptoInfo::type
```
**描述**

加密算法类型。
