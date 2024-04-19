# OH_Huks_KeyMaterialRsa


## Overview

Defines the struct of an RSA key.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg) [keyAlg](#keyalg) | Algorithm of the key. |
| uint32_t [keySize](#keysize) | Length of the key. |
| uint32_t [nSize](#nsize) | Length of **n**. |
| uint32_t [eSize](#esize) | Length of **e**. |
| uint32_t [dSize](#dsize) | Length of **d**. |


## Member Variable Description


### dSize

```
uint32_t OH_Huks_KeyMaterialRsa::dSize
```
**Description**

Length of **d**.


### eSize

```
uint32_t OH_Huks_KeyMaterialRsa::eSize
```
**Description**

Length of **e**.


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialRsa::keyAlg
```
**Description**

Algorithm of the key.


### keySize

```
uint32_t OH_Huks_KeyMaterialRsa::keySize
```
**Description**

Length of the key.


### nSize

```
uint32_t OH_Huks_KeyMaterialRsa::nSize
```
**Description**

Length of **n**.