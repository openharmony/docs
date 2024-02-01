# OH_Huks_KeyMaterialRsa


## 概述

定义Rsa密钥的结构体类型。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg) [keyAlg](#keyalg) | 密钥的算法类型。  | 
| uint32_t [keySize](#keysize) | 密钥的长度。  | 
| uint32_t [nSize](#nsize) | n值的长度。  | 
| uint32_t [eSize](#esize) | e值的长度。  | 
| uint32_t [dSize](#dsize) | d值的长度。  | 


## 结构体成员变量说明


### dSize

```
uint32_t OH_Huks_KeyMaterialRsa::dSize
```
**描述**
d值的长度。


### eSize

```
uint32_t OH_Huks_KeyMaterialRsa::eSize
```
**描述**
e值的长度。


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialRsa::keyAlg
```
**描述**
密钥的算法类型。


### keySize

```
uint32_t OH_Huks_KeyMaterialRsa::keySize
```
**描述**
密钥的长度。


### nSize

```
uint32_t OH_Huks_KeyMaterialRsa::nSize
```
**描述**
n值的长度。
