# OH_Huks_KeyMaterialEcc


## 概述

定义Ecc密钥的结构体类型。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)

**所在头文件：**[native_huks_type.h](native__huks__type_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg) [keyAlg](#keyalg) | 密钥的算法类型。  | 
| uint32_t [keySize](#keysize) | 密钥的长度。  | 
| uint32_t [xSize](#xsize) | x值的长度。  | 
| uint32_t [ySize](#ysize) | y值的长度。  | 
| uint32_t [zSize](#zsize) | z值的长度。  | 


## 结构体成员变量说明


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialEcc::keyAlg
```
**描述**
密钥的算法类型。


### keySize

```
uint32_t OH_Huks_KeyMaterialEcc::keySize
```
**描述**
密钥的长度。


### xSize

```
uint32_t OH_Huks_KeyMaterialEcc::xSize
```
**描述**
x值的长度。


### ySize

```
uint32_t OH_Huks_KeyMaterialEcc::ySize
```
**描述**
y值的长度。


### zSize

```
uint32_t OH_Huks_KeyMaterialEcc::zSize
```
**描述**
z值的长度。
