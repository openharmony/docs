# OH_Huks_PubKeyInfo


## 概述

定义公钥信息的结构体类型。

 **起始版本：**
9

**相关模块:**

[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

  | 名称 | 描述 | 
| -------- | -------- |
| [keyAlg](#keyalg) | enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg)<br/>公钥的算法类型。  | 
| [keySize](#keysize) | uint32_t<br/>公钥的长度。  | 
| [nOrXSize](#norxsize) | uint32_t<br/>n或X值的长度。  | 
| [eOrYSize](#eorysize) | uint32_t<br/>e或Y值的长度。  | 
| [placeHolder](#placeholder) | uint32_t<br/>占位符大小。  | 


## 结构体成员变量说明


### eOrYSize

  
```
uint32_t OH_Huks_PubKeyInfo::eOrYSize
```
**描述:**
e或Y值的长度。


### keyAlg

  
```
enum OH_Huks_KeyAlg OH_Huks_PubKeyInfo::keyAlg
```
**描述:**
公钥的算法类型。


### keySize

  
```
uint32_t OH_Huks_PubKeyInfo::keySize
```
**描述:**
公钥的长度。


### nOrXSize

  
```
uint32_t OH_Huks_PubKeyInfo::nOrXSize
```
**描述:**
n或X值的长度。


### placeHolder

  
```
uint32_t OH_Huks_PubKeyInfo::placeHolder
```
**描述:**
占位符大小。
