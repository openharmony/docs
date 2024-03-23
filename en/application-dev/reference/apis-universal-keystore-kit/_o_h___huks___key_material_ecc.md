# OH_Huks_KeyMaterialEcc


## Overview

Defines the structure of an Elliptic Curve Cryptography (ECC) key.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg) [keyAlg](#keyalg) | Algorithm of the key. |
| uint32_t [keySize](#keysize) | Length of the key. |
| uint32_t [xSize](#xsize) | Length of **x**. |
| uint32_t [ySize](#ysize) | Length of **y**. |
| uint32_t [zSize](#zsize) | Length of **z**. |


## Member Variable Description


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialEcc::keyAlg
```
**Description**

Algorithm of the key.


### keySize

```
uint32_t OH_Huks_KeyMaterialEcc::keySize
```
**Description**

Length of the key.


### xSize

```
uint32_t OH_Huks_KeyMaterialEcc::xSize
```
**Description**
Length of **x**.


### ySize

```
uint32_t OH_Huks_KeyMaterialEcc::ySize
```
**Description**
Length of **y**.


### zSize

```
uint32_t OH_Huks_KeyMaterialEcc::zSize
```
**Description**
Length of **z**.
