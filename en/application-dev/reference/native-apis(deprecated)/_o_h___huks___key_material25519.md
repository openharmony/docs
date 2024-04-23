# OH_Huks_KeyMaterial25519


## Overview

Defines the structure of a 25519 key.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [keyAlg](#keyalg) | Algorithm of the key.  | 
| [keySize](#keysize) | Length of the 25519 key.  | 
| [pubKeySize](#pubkeysize) | Length of the public key.  | 
| [priKeySize](#prikeysize) | Length of the private key.  | 
| [reserved](#reserved) | Reserved.  | 


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
