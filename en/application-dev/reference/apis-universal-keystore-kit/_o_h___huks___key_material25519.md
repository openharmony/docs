# OH_Huks_KeyMaterial25519


## Overview

Defines the structure of a 25519 key.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| enum [OH_Huks_KeyAlg](_huks_type_api.md#oh_huks_keyalg) [keyAlg](#keyalg) | Algorithm of the key. | 
| uint32_t [keySize](#keysize) | Length of the 25519 key. | 
| uint32_t [pubKeySize](#pubkeysize) | Length of the public key. | 
| uint32_t [priKeySize](#prikeysize) | Length of the private key. | 
| uint32_t [reserved](#reserved) | Reserved field. You are advised to set the value to **0**. | 


## Member Variable Description


### keyAlg

```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterial25519::keyAlg
```
**Description**<br>
Algorithm of the key.


### keySize

```
uint32_t OH_Huks_KeyMaterial25519::keySize
```
**Description**<br>
Length of the 25519 key.


### priKeySize

```
uint32_t OH_Huks_KeyMaterial25519::priKeySize
```
**Description**<br>
Length of the private key.


### pubKeySize

```
uint32_t OH_Huks_KeyMaterial25519::pubKeySize
```
**Description**<br>
Length of the public key.


### reserved

```
uint32_t OH_Huks_KeyMaterial25519::reserved
```
**Description**<br>
Reserved.
