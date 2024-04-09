# OH_Huks_PubKeyInfo


## Overview

Defines the struct of a public key.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg) [keyAlg](#keyalg) | Algorithm of the public key. |
| uint32_t [keySize](#keysize) | Length of the public key. |
| uint32_t [nOrXSize](#norxsize) | Length of **n** or **X**. |
| uint32_t [eOrYSize](#eorysize) | Length of **e** or **Y**. |
| uint32_t [placeHolder](#placeholder) | Placeholder size. |


## Member Variable Description


### eOrYSize

```
uint32_t OH_Huks_PubKeyInfo::eOrYSize
```
**Description**

Length of **e** or **Y**.


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_PubKeyInfo::keyAlg
```
**Description**

Algorithm of the public key.


### keySize

```
uint32_t OH_Huks_PubKeyInfo::keySize
```
**Description**

Length of the public key.


### nOrXSize

```
uint32_t OH_Huks_PubKeyInfo::nOrXSize
```
**Description**

Length of **n** or **X**.


### placeHolder

```
uint32_t OH_Huks_PubKeyInfo::placeHolder
```
**Description**

Placeholder size.