# OH_Huks_KeyMaterial25519


## 概述

定义25519类型密钥的结构体类型。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)

**所在头文件：**[native_huks_type.h](native__huks__type_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg) [keyAlg](#keyalg) | 密钥的算法类型。  | 
| uint32_t [keySize](#keysize) | 25519类型密钥的长度。  | 
| uint32_t [pubKeySize](#pubkeysize) | 公钥的长度。  | 
| uint32_t [priKeySize](#prikeysize) | 私钥的长度。  | 
| uint32_t [reserved](#reserved) | 预留字段。建议开发者赋值为0。  | 


## 结构体成员变量说明


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterial25519::keyAlg
```
**描述**
密钥的算法类型。


### keySize

```
uint32_t OH_Huks_KeyMaterial25519::keySize
```
**描述**
25519类型密钥的长度。


### priKeySize

```
uint32_t OH_Huks_KeyMaterial25519::priKeySize
```
**描述**
私钥的长度。


### pubKeySize

```
uint32_t OH_Huks_KeyMaterial25519::pubKeySize
```
**描述**
公钥的长度。


### reserved

```
uint32_t OH_Huks_KeyMaterial25519::reserved
```
**描述**
预留字段，建议开发者赋值为0。
