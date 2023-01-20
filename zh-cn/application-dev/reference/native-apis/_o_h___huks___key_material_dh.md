# OH_Huks_KeyMaterialDh


## 概述

定义Dh密钥的结构体类型。

 **起始版本：**
9

**相关模块:**

[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

  | 名称 | 描述 | 
| -------- | -------- |
| [keyAlg](#keyalg) | enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg)<br/>密钥的算法类型。  | 
| [keySize](#keysize) | uint32_t<br/>Dh密钥的长度。  | 
| [pubKeySize](#pubkeysize) | uint32_t<br/>公钥的长度。  | 
| [priKeySize](#prikeysize) | uint32_t<br/>私钥的长度。  | 
| [reserved](#reserved) | uint32_t<br/>保留。  | 


## 结构体成员变量说明


### keyAlg

  
```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialDh::keyAlg
```
**描述:**
密钥的算法类型。


### keySize

  
```
uint32_t OH_Huks_KeyMaterialDh::keySize
```
**描述:**
Dh密钥的长度。


### priKeySize

  
```
uint32_t OH_Huks_KeyMaterialDh::priKeySize
```
**描述:**
私钥的长度。


### pubKeySize

  
```
uint32_t OH_Huks_KeyMaterialDh::pubKeySize
```
**描述:**
公钥的长度。


### reserved

  
```
uint32_t OH_Huks_KeyMaterialDh::reserved
```
**描述:**
保留。
