# OH_Huks_KeyMaterialDh


## Overview

Defines the structure of a DH key.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [keyAlg](#keyalg) |Algorithm of the key.  | 
| [keySize](#keysize) | Length of the DH key.  | 
| [pubKeySize](#pubkeysize) | Length of the public key.  | 
| [priKeySize](#prikeysize) | Length of the private key.  | 
| [reserved](#reserved) | Reserved.  | 


## Member Variable Description 


### keyAlg

  
```
enum OH_Huks_KeyAlg OH_Huks_KeyMaterialDh::keyAlg
```
**Description**<br>
Algorithm of the key.


### keySize

  
```
uint32_t OH_Huks_KeyMaterialDh::keySize
```
**Description**<br>
Length of the DH key.


### priKeySize

  
```
uint32_t OH_Huks_KeyMaterialDh::priKeySize
```
**Description**<br>
Length of the private key.


### pubKeySize

  
```
uint32_t OH_Huks_KeyMaterialDh::pubKeySize
```
**Description**<br>
Length of the public key.


### reserved

  
```
uint32_t OH_Huks_KeyMaterialDh::reserved
```
**Description**<br>
Reserved.
