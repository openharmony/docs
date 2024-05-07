# OH_Huks_KeyMaterialDsa


## Overview

Defines the struct of a DSA key.

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
| uint32_t [pSize](#psize) | Length of **p**. |
| uint32_t [qSize](#qsize) | Length of **q**. |
| uint32_t [gSize](#gsize) | Length of **g**. |


## Member Variable Description


### gSize

```
uint32_t OH_Huks_KeyMaterialDsa::gSize
```
**Description**

Length of **g**.


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialDsa::keyAlg
```
**Description**

Algorithm of the key.


### keySize

```
uint32_t OH_Huks_KeyMaterialDsa::keySize
```
**Description**
Length of the key.


### pSize

```
uint32_t OH_Huks_KeyMaterialDsa::pSize
```
**Description**
Length of **p**.


### qSize

```
uint32_t OH_Huks_KeyMaterialDsa::qSize
```
**Description**
Length of **q**.


### xSize

```
uint32_t OH_Huks_KeyMaterialDsa::xSize
```
**Description**
Length of **x**.


### ySize

```
uint32_t OH_Huks_KeyMaterialDsa::ySize
```
**Description**
Length of **y**.
